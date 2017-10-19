#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <front/hash.h>

#include "alloc.h"


/* Use dynamic arrays to record allocations, lists take up too much
   space */
struct alloc_list_s {
  size_t    size, max;
  alloc_t **elems;
};

static hash_t allocations;
static alloc_list_t *freed_allocs;
static int count;
static unsigned mem_used_alloc;
static unsigned mem_used_list;

static int
has_key (alloc_t *me, unsigned ptr)
{
  return me->ptr==ptr;
}

static unsigned
make_key (unsigned ptr)
{
  return ptr;
}

alloc_t *
alloc_add (unsigned ptr, unsigned size)
{
  alloc_t *me = malloc (sizeof(*me));
  mem_used_alloc += sizeof(*me);
  
  me->ptr = ptr;
  me->size = size;
  me->freed = 0;
  if (!allocations) {
    allocations = Front_Make_hash_table ((void*)make_key, (void*)has_key);
  }
  Front_Add_in_hash_table (allocations, (void*)ptr, me);
  return me;
}

void
alloc_rm (unsigned ptr)
{
  alloc_t *alloc;
  assert (allocations);

  alloc = Front_Find_in_hash_table (allocations, (void*)ptr);
  Front_Remove_from_hash_table (allocations, (void*)ptr);
  if (!alloc->freed) {
    freed_allocs = alloc_list_prepend (freed_allocs, alloc);
    alloc->freed = 1;
  }
}

alloc_list_t *
alloc_list_prepend (alloc_list_t *l, alloc_t *alloc)
{
  if (!l) {
    l = malloc (sizeof (*l));
    l->size = 0;
    l->max = 16;
    l->elems =  malloc (l->max * sizeof (alloc_t **));
    mem_used_list += sizeof(*l) + l->max * sizeof (alloc_t **);
  }
  if (l->size==l->max) {
    mem_used_list += 16 * sizeof (alloc_t **);
    l->max += 16; 
    l->elems =  realloc (l->elems, l->max * sizeof (alloc_t **));
  }
  l->elems [l->size++] = alloc;
  return l;
}

alloc_t *
alloc_list_last (alloc_list_t *l)
{
  if (!l || l->size==0) return NULL;
  return l->elems[l->size-1];
}

alloc_list_t *
alloc_list_sweep (alloc_list_t *l)
{
  size_t i;
  
  if (!l) return NULL;
  for (i=0; i<l->size; ) {
    if (!l->elems[i]->freed) {
      i++;
    } else {
      l->size --;
      l->elems[i] = l->elems [l->size];
    }
  }
  if (l->size + 16 < l->max) {
    l->max = l->size + 16;
    l->elems =  realloc (l->elems, l->max * sizeof (alloc_t **));
  }
  return l;
}

void
allocations_sweep (void)
{
  size_t i;
  
  for (i=0; i<freed_allocs->size; i++) {
    free (freed_allocs->elems[i]);
  }
  free (freed_allocs->elems);
  free (freed_allocs);
  freed_allocs = NULL;
}

unsigned
alloc_list_lost_mem (alloc_list_t *l)
{
  unsigned bytes = 0;
  
  size_t i;
  if (!l) return 0;
  for (i=0; i<l->size; i++) {
    if (!l->elems[i]->freed) bytes += l->elems[i]->size;
  }
  return bytes;
}

static void
count_allocs (alloc_t *alloc)
{
  alloc = alloc;
  count++;
}

int
num_allocations(void)
{
  count = 0;
  if (allocations) Front_Apply_to_hash_table (allocations, (void*)count_allocs);
  return count;
}

void
alloc_print_mem_used (void)
{
  fprintf (stderr,"allocations: %u bytes ", mem_used_alloc + mem_used_list);
  fprintf (stderr,"(alloc:%u, list:%u)\n", mem_used_alloc, mem_used_list);
}
