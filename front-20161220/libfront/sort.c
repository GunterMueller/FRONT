/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include <stdlib.h>
#include <string.h>
#include "mem.h"


#define QS_MAX_THRESH 15

static int (*qs_compare)(const void *, const void *);

/* Once main array is partially sorted by quicksort the remainder is 
   completely sorted using insertion sort, since this is efficient 
   for partitions below QS_MAX_THRESH size. BASE points to the beginning 
   of the array to sort, and END_PTR points at the very last element in
   the array (*not* one beyond it!). */

static void
swap(void *x, void *y, size_t elsize)
{
  void *t = alloca(elsize);
  memcpy(t, x, elsize);
  memcpy(x, y, elsize);
  memcpy(y, t, elsize);
}

static void
move(void *x, void *y, size_t elsize)
{
  memcpy(y, x, elsize);
}

static void
_insert_sort(void *base, void *end_ptr, size_t elsize)
{
  void *run_ptr;
  void *tmp_ptr = end_ptr;
  void *scratch = alloca(elsize);

  /* Find the largest element in the array and put it at the 
     end of the array.  This acts like a sentinel, and it speeds
     up the inner loop of insertion sort. */

  for (run_ptr = end_ptr - elsize; run_ptr >= base; run_ptr-=elsize) {
    if (qs_compare (run_ptr, tmp_ptr) > 0) {
      tmp_ptr = run_ptr;
    }
  }

  if(tmp_ptr != end_ptr) swap (tmp_ptr, end_ptr, elsize); 

  /* Typical insertion sort, but we run from the `right-hand-side'
     downto the `left-hand-side.' */
    
  for (run_ptr = end_ptr - elsize; run_ptr > base; run_ptr-=elsize)  {
    tmp_ptr = run_ptr - elsize;
    move(tmp_ptr, scratch, elsize);

    /* Select the correct location for the new element, 
       by sliding everyone down by 1 to make room! */
      
    for (tmp_ptr+=elsize; qs_compare (scratch, tmp_ptr) > 0; tmp_ptr+=elsize) {
      move (tmp_ptr, (tmp_ptr - elsize), elsize);
    }
      
    move (scratch, tmp_ptr - elsize, elsize);
  }
}

/* Return the median value selected from among the 
   LOW, MIDDLE, and HIGH.  Rearrange LOW and HIGH so
   the three values are sorted amongst themselves. 
   This speeds up later work... */

static void *
find_pivot(void *low, void *high, size_t elsize)
{
  int hi = (high-low)/elsize;
  void *middle = low + (hi/2)*elsize;
    
    if (qs_compare (middle, low) < 0)   swap (middle, low, elsize); 
    if (qs_compare (high, middle) < 0)  swap (middle, high, elsize); 
    else                                return middle;
    
    if (qs_compare (middle, low)  < 0)  swap (middle, low, elsize);
    
    return middle;
}

/* Order elements using quicksort.  This implementation incorporates
   4 optimizations discussed in Sedgewick:
   
   1. Non-recursive, using an explicit stack of log (n) pointers that 
   indicate the next array partition to sort.
   
   2. Choses the pivot element to be the median-of-three, reducing
   the probability of selecting a bad pivot value.
   
   3. Only quicksorts TOTAL_ELEMS / QS_MAX_THRESH partitions, leaving
   insertion sort to sort within the partitions.  This is a
   big win, since insertion sort is faster for small, mostly
   sorted array segements.
   
   4. The larger of the 2 sub-partitions are always pushed onto the
   stack first, with the algorithm then concentrating on the
   smaller partition.  This *guarantees* no more than log (n)
   stack size is needed! */

/* For elements of size pointer */
/* Data structure for stack of unfulfilled obligations. */
typedef struct 
{
    void *lo;
    void *hi;
} StackNode;

#define QS_PUSH(LOW,HIGH)     top->lo = LOW; top->hi = HIGH; top++
#define QS_POP(LOW,HIGH)      --top; LOW = top->lo; HIGH = top->hi
#define QS_STACK_NOT_EMPTY    (stack < top)                

void
fe_quick_sort(void *base, size_t nmemb, size_t elsize, int compare(const void *, const void *))
{
  void *lo;
  void *hi;
  void *left_ptr;
  void *right_ptr;
  void *middle_ptr;
  void *pivot;
  StackNode  *stack;
  StackNode  *top;  
  size_t max_stack_size = 1;
  int comp;
  size_t i;
    
  if (nmemb < 1) return;
  qs_compare = compare;
  /* Calculate the exact stack space required in the worst case.
     This is approximately equal to the log base 2 of NMEMB. */
      
  for (i = 1; i < nmemb; i += i)  max_stack_size++;
  /* Create the stack, or die trying! */
  stack = (StackNode *) alloca(max_stack_size * sizeof(StackNode));
  if (!stack) return;
  top = stack;
      
  lo = base;
  hi = lo + (nmemb - 1)*elsize;

  do {
    if((size_t)(hi - lo) <= QS_MAX_THRESH*elsize) {
      _insert_sort(lo, hi, elsize);
      if(QS_STACK_NOT_EMPTY) {
        QS_POP(lo, hi);
        continue;
      } else break;
    }
    /* otherwise next iteration of qsort */
    /* Select the median-of-three here. This allows us to
       skip forward for the LEFT_PTR and RIGHT_PTR. */
    pivot = find_pivot (lo, hi, elsize);
    left_ptr  = lo + elsize;
    middle_ptr  = left_ptr;
    right_ptr = hi - elsize; 
        
    do {
      if (middle_ptr > right_ptr) break;
      comp = qs_compare (pivot, right_ptr);
      if (comp < 0) right_ptr-=elsize;
      else if (comp == 0) {
        swap (middle_ptr, right_ptr, elsize);
        middle_ptr+=elsize;
      } else {
        break;
      }
    } while (1);
        
    do {
      if (middle_ptr > right_ptr) break;
      comp = qs_compare (middle_ptr, pivot);
      if (comp == 0) middle_ptr+=elsize;
      else if (comp < 0) {
        swap (left_ptr, middle_ptr, elsize);
        left_ptr+=elsize;
        middle_ptr+=elsize;
      } else {
        swap (middle_ptr, right_ptr, elsize);
        right_ptr-=elsize;
      }
    } while (1);
		
    if ((left_ptr - lo) > (hi - right_ptr)) {
      /* push larger left table */
      QS_PUSH (lo, left_ptr-elsize);
      lo = right_ptr+elsize;
    } else {
      /* push larger right table */
      QS_PUSH (right_ptr+elsize, hi);
      hi = left_ptr-elsize;
    }
  } while(1);	/* when stack is empty it'll break out */
}

void
fe_insert_sort(void *base, size_t nmemb, size_t elsize, int compare(const void *, const void *))
{
  qs_compare = compare;
  _insert_sort (base, base+elsize*nmemb, elsize);
}

/* ----------------------------------------------------------------------------
 * Randomize array BASE consisting of NMEMB elements of size ELSIZE
 */
void
fe_randomize(void *base, size_t nmemb, size_t elsize)
{
  size_t i;
  int r;
  int *set;
  int *remap;
  void *shadow;
  remap = alloca(nmemb*sizeof(int));
  set = alloca(nmemb*sizeof(int));

  /* create set of indices */
  for (i=0; i<nmemb; i++) set[i]=i;
  /* create remap array, selects random elements from SET and removes them */
  for (i=nmemb; i!=0; i--) {
    r = rand()%i;
    remap[i-1] = set[r];
    set[r] = set[i-1];
  }
  /* Remap the array into a shadow array */
  shadow = alloca(nmemb*elsize);
  for(i=0; i<nmemb; i++) {
    memcpy(shadow+remap[i]*elsize,base+i*elsize,elsize);
  }
  /* copy the shadow back into the original */
  memcpy (base, shadow, elsize*nmemb);
}
