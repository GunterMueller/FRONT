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
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "mem.h"
#include "skiplist.h"
#include "mempool.h"

typedef struct s_fe_mempools *fe_mempools;

struct s_fe_mempools {
  fe_mempools  tail;
  fe_mempool   pool;
};

static fe_mempool current_pool;
static fe_mempools pool_stack;

static int
mp_compare(void * a, void * b)
{ 
  return a-b;
}	

DEF_FIND_NODE (mp_find, mp_compare)

/* ----------------------------------------------------------------------------
 * Error handling stuff
 */
static void
vbail (const char *m, va_list args)
{
  fprintf (stderr, "allocation error: ");
  vfprintf (stderr, m, args);
  abort();
}

static void
bail (const char *m, ...)
{
  va_list args;
  va_start (args, m);
  vbail (m, args);
  va_end (args);
}

/* ----------------------------------------------------------------------------
 * Memory pool stack management
 */
void
fe_push_mempool (fe_mempool pool)
{
  fe_mempools mps = fe_mpalloc (sizeof (*mps));
  mps->pool = pool;
  mps->tail = pool_stack;
  pool_stack = mps;
  current_pool = pool;
}

void
fe_pop_mempool (fe_mempool pool)
{
  fe_mempools old;
  if (current_pool != pool) {
    fe_abort ("memory pool to be popped is not the current pool.");
  }
  old = pool_stack;
  pool_stack = pool_stack->tail;
  current_pool = pool_stack->pool;
  fe_mpfree (old);
}

/* ----------------------------------------------------------------------------
 * Memory pool construction/destruction
 */
fe_mempool
fe_new_mempool (void)
{
  fe_mempool mp = fe_skiplist_new (mp_compare);
  fe_push_mempool (mp);
  return mp;
}

void
fe_free_mempool (fe_mempool pool)
{
  fe_mempool mp = current_pool;
  fe_mempools s;
  
  fe_pop_mempool (pool);
  for (s = pool_stack; s; s = s->tail) {
    if (s->pool == mp) {
      fe_abort ("attempting to free a pool that is still on the pool stack.");
    }
  }
  fe_skiplist_destruct (mp, fe_mpfree);
  fe_mpfree (mp);
}

/* ----------------------------------------------------------------------------
 * Add chunk P to the current pool
 */
static void
add_chunk (const void *p)
{
  fe_skiplist_insert (current_pool, p);
}

static void
remove_chunk (const void *p)
{
  if (!fe_has_chunk (current_pool, p)) {
    bail ("attepting to free chunk %p which is not in the current pool.", p);
  }
  fe_skiplist_remove (current_pool, p);
}

int
fe_has_chunk (fe_mempool pool, const void *p)
{
  return mp_find (pool, p)!=NULL;
}

void 
fe_move_chunk (fe_mempool dst, const void *p)
{
  remove_chunk (p);
  fe_skiplist_insert (dst, p);
}

/* ----------------------------------------------------------------------------
 * malloc, free, and realloc replacements
 */
void *
fe_mpalloc (size_t s)
{
  void *p = fe_malloc (s);
  add_chunk (p);
  return p;
}

void
fe_mpfree (void *p)
{
  remove_chunk (p);
  fe_free (p);
}

void *
fe_mprealloc (void *p, size_t s)
{
  void *r;
  remove_chunk (p);
  r = fe_realloc (p, s);
  add_chunk (r);
  return r;
}

