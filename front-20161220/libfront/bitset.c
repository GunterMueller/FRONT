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
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "mem.h"
#include "bitset.h"

#ifndef BITSPERCHAR
#define BITSPERCHAR CHAR_BIT
#endif

#ifndef BITSPERINT
#define BITSPERINT (BITSPERCHAR*sizeof(int))
#endif

#define BITSET_SKIP(a,k,i,j) \
    if (j==0 && !a->bits[i]) { i++; k += BITSPERINT-1; continue; } /* skip empty word */

#define BITSET_PLAIN(a)  { (a)->empty = 0; (a)->single = NULL; } /* normal representation */
#define SAME_SINGLE(a,b) ( (a)->single && (a)->single==(b)->single ) /* normal representation */

#define WORDS(s) ((s+BITSPERINT-1)/BITSPERINT)

fe_bitset
bitset_new (unsigned int size,
            unsigned int (*bit) (void*),
            void* (*elem) (unsigned int))
{
  unsigned w = WORDS(size);
  fe_bitset set = fe_malloc (sizeof(*set) + (w-1)*sizeof(unsigned));
  set->size = size;
  set->bit = bit;
  set->elem = elem;
  set->single = NULL;
  set->empty = 1;
  memset (set->bits, 0, w*sizeof(int));
  return set;
}

fe_bitset 
fe_bitset_dup (fe_bitset set)
{
  fe_bitset new;
  unsigned w, n;
  
  if (!set) return set;
  w = WORDS(set->size);
  new = bitset_new (set->size, NULL, NULL);
  n = sizeof(*set) + (w-1)*sizeof(unsigned);
  memcpy (new, set, n);
  return new;
}

void 
fe_bitset_free (const fe_bitset set)
{
  fe_free (set);
}

void 
fe_bitset_destruct (const fe_bitset set, fe_destructor destructor)
{
  fe_bitset_for_all (set, (void *)destructor);
  fe_bitset_free (set);
}

static void
set_bit (fe_bitset set, unsigned b)
{
  void *x;
  unsigned w;
  
  assert (b < set->size);
  x = set->elem(b);
  w = b / BITSPERINT;
  b = b % BITSPERINT;
  set->bits[w] |= 1<<b;
  if (set->empty || set->single == x) {
    set->single = x;
  } else {
    set->single = NULL;
  }
  set->empty = 0;
}

static void
clear_bit (fe_bitset set, unsigned b)
{
  void *x;
  unsigned w;

  if (set->empty) return;
  assert (b < set->size);
  x = set->elem(b);
  w = b / BITSPERINT;
  b = b % BITSPERINT;
  set->bits[w] &= ~(1<<b);
  if (set->single == x) {
    set->empty = TRUE;
  } else {
    set->single = NULL;
  }
}

fe_bitset 
fe_bitset_add (fe_bitset set, void *elem)
{
  assert (set);
  set_bit (set, set->bit(elem));
  return set;
}

fe_bitset
fe_bitset_remove (fe_bitset set, void *elem)
{
  assert (set);
  clear_bit (set, set->bit(elem));
  return set;
}

fe_bitset   
fe_bitset_union (fe_bitset a, fe_bitset b)
{
  unsigned w, i;
  
  if (!a) return a;
  if (!b || b->empty) return a;
  assert (a->size == b->size);
  
  if (SAME_SINGLE(a,b)) return a; /* Same singletons */
  
  w = WORDS(a->size);
  for (i = 0; i < w; i++) {
    a->bits[i] |= b->bits[i];
  }
  a->empty = 0; /* b not empty => a not empty */
  a->single = NULL;
  return a;
}

fe_bitset 
fe_bitset_intersect (fe_bitset a, fe_bitset b)
{
  if (!b) return a;
  if (a->empty) return a;
  if (b->empty) return b;
  
  int empty = 1;
  assert (a->size == b->size);
  unsigned w = WORDS(a->size);
  unsigned i;
  for (i = 0; i < w; i++) {
    a->bits[i] &= b->bits[i];
    empty &= a->bits[i]==0;
  }
  a->single = NULL;
  a->empty = empty;
  return a;
}

fe_bitset 
fe_bitset_subtract (fe_bitset a, fe_bitset b)
{
  if (!b) return a;
  if (a->empty || b->empty) return a;

  int empty = 1;
  assert (a->size == b->size);
  unsigned w = WORDS(a->size);
  unsigned i;
  for (i = 0; i < w; i++) {
    a->bits[i] &= ~b->bits[i];
    empty &= a->bits[i]==0;
  }
  a->single = NULL;
  a->empty = empty;
  return a;
}

/* b subset of a */
Bool 
fe_bitset_contains (fe_bitset a, fe_bitset b)
{
  if (!b) return TRUE;
  if (!a) return FALSE;
  if (b->empty) return TRUE;
  if (a->empty) return FALSE;

  assert (a->size == b->size);
  unsigned w = WORDS(a->size);
  unsigned i;
  for (i = 0; i < w; i++) {
    if ((a->bits[i] | ~b->bits[i]) == ~0u) continue;
    return 0;
  }
  return TRUE;
}

Bool    
fe_bitset_equal (fe_bitset a, fe_bitset b)
{
  if (!b) return !a;
  if (!a) return !b;
  if (a->empty && b->empty) return TRUE;
  if (SAME_SINGLE (a,b)) return TRUE;
 
  assert (a->size == b->size);
  unsigned w = WORDS(a->size);
  unsigned i;
  for (i = 0; i < w; i++) {
    if (a->bits[i] != b->bits[i]) return FALSE;
  }
  return TRUE;
}

Bool
fe_bitset_has_element (fe_bitset a, void *elem)
{
  if (a->empty) return FALSE;
  if (a->single) return a->single == elem;
  
  unsigned b = a->bit(elem);
  unsigned w = b / BITSPERINT;
  b = b % BITSPERINT;
  assert (b < a->size);
  return (a->bits[w] & 1<<b) != 0;
}

Bool
fe_bitset_is_empty (fe_bitset a)
{
  if (!a) return TRUE;
  if (a->empty) return TRUE;
  if (a->single) return FALSE;
  
  unsigned w = WORDS(a->size);
  unsigned i;
  for (i = 0; i < w; i++) {
    if (a->bits[i]) return FALSE;
  }
  return TRUE;
}


unsigned
fe_bitset_size (fe_bitset a)
{
  if (!a || a->empty) return 0;
  if (a->single) return 1;
  
  unsigned k;
  unsigned i = 0, j = 0;
  unsigned size = 0;
  for (k = 0; k < a->size; k++) {
    BITSET_SKIP(a,k,i,j); /* skip empty word */
    if (a->bits[i] & (1<<j)) size++;
    if (++j==BITSPERINT) { j = 0; i++; }
  }
  return size;
}

void   
fe_bitset_for_all (fe_bitset a, void (*f) (void*))
{
  if (!a || a->empty) return;
  if (a->single) { f (a->single); return; }
  
  unsigned k;
  unsigned i = 0, j = 0;
  for (k = 0; k < a->size; k++) {
    BITSET_SKIP(a,k,i,j); /* skip empty word */
    if (a->bits[i] & (1<<j)) f (a->elem(k));
    if (++j==BITSPERINT) { j = 0; i++; }
  }
}

fe_bitset 
fe_bitset_filter (fe_bitset a, Bool f (void*))
{
  if (!a || a->empty) return a;
  if (a->single && f(a->single)) return a;

  int empty = 1;
  
  unsigned k;
  unsigned i = 0, j = 0;
  for (k = 0; k < a->size; k++) {
    BITSET_SKIP(a,k,i,j); /* skip empty word */
    if (a->bits[i] & (1<<j)) {
      int b = f (a->elem(k));
      if (!b) a->bits[i] &= ~(1<<j);
    }
    if (++j==BITSPERINT) { empty &= !a->bits[i]; j = 0; i++; }
  }
  a->empty = empty;
  a->single = NULL;
  return a;
}

Bool
fe_bitset_property (fe_bitset a, Bool f(void *a, void *b), void *b)
{
  if (!a || a->empty) return FALSE;
  if (a->single) return f (a->single, b);
  
  unsigned k;
  unsigned i = 0, j = 0;
  
  for (k = 0; k < a->size; k++) {
    BITSET_SKIP(a,k,i,j); /* skip empty word */
    if (a->bits[i] & (1<<j)) {
      if (f (a->elem(k), b)) return TRUE;
    }
    if (++j==BITSPERINT) { j = 0; i++; }
  }
  return FALSE;
}

void *
fe_bitset_for_all_acc (fe_bitset a, void *(*f) (void *, void*, void*),
                       void *b, void *r)
{
  if (!a || a->empty) return r;
  if (a->single) return f (a->single, b, r);
  
  unsigned k;
  unsigned i = 0, j = 0;
  for (k = 0; k < a->size; k++) {
    BITSET_SKIP(a,k,i,j); /* skip empty word */
    if (a->bits[i] & (1<<j)) r = f (a->elem(k), b, r);
    if (++j==BITSPERINT) { j = 0; i++; }
  }
  return r;
}

void   
fe_bitset_for_pairs (fe_bitset a, void (*f) (void*, void*))
{
  if (!a || a->empty) return;
  unsigned k;
  unsigned i = 0, j = 0;
  for (k = 0; k < a->size; k++) {
    unsigned l;
    unsigned i1 = 0, j1 = 0;
    BITSET_SKIP(a,k,i,j); /* skip empty word */
    if (a->bits[i] & (1<<j)) {
      for (l = 0; l < a->size; l++) {
        BITSET_SKIP(a,l,i1,j1); /* skip empty word */
	if (l > k && (a->bits[i1] & (1<<j1))) {
	  f (a->elem(k), a->elem(l));
	}
	if (++j1==BITSPERINT) { j1 = 0; i1++; }
      }
    }
    if (++j==BITSPERINT) { j = 0; i++; }
  }
}
