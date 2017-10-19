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

/* NOTE: MEMPOOLS ARE UNTESTED */

#ifndef _libfront_mempool_h
#define _libfront_mempool_h

#include "skiplist.h"

typedef fe_skiplist fe_mempool;

/* create and push a new memory pool */
fe_mempool fe_new_mempool (void);

/* push an existing memory pool */
void fe_push_mempool (fe_mempool pool);

/* pop POOL from the memory pool stack, if POOL is not on the top of
   stack an abort is done */
void fe_pop_mempool (fe_mempool pool);

/* Free the memory pool and everything allocated in the pool */
void fe_free_mempool (fe_mempool pool);

/* Allocate S bytes in the current memory pool */
void *fe_mpalloc (size_t s);

/* Free P from the current memory pool */
void fe_mpfree (void *p);

/* Resize an allocated block of memory in the current memory pool */
void *fe_mprealloc (void *p, size_t s);

/* TRUE iff P is in memory pool POOL */
int fe_has_chunk (fe_mempool pool, const void *p);

/* Move P from the current memory pool to DST */
void  fe_move_chunk (fe_mempool dst, const void *p);

#endif /* _libfront_mempool_h */
