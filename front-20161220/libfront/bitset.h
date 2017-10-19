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
#ifndef _bitset_h
#define _bitset_h

#include "basic_types.h"

typedef struct {
  unsigned int size; 		/* in bits */
  unsigned int (*bit) (void*); 	/* get bit number */
  void* (*elem) (unsigned int);	/* get element from bit number */
  void *single;			/* if non-NULL, the singleton element of this set */
  int empty;			/* boolean, denotes emptiness */
  unsigned int bits[1]; 	/* Bit vector, ceil(size/sizeof(int)) elements */
} *fe_bitset;

fe_bitset
fe_bitset_new (unsigned int size,            /* # elements in set */
               unsigned int (*bit) (void*),  /* index of the element */
               void* (*elem) (unsigned int));/* get element at index */
fe_bitset fe_bitset_dup (fe_bitset set);

void      fe_bitset_free (const fe_bitset set);
void      fe_bitset_destruct (const fe_bitset set, fe_destructor destructor);

fe_bitset fe_bitset_add (fe_bitset set, void *elem);
fe_bitset fe_bitset_remove (fe_bitset set, void *elem);

/* these functions modify and return A */
fe_bitset fe_bitset_union (fe_bitset a, fe_bitset b); 
fe_bitset fe_bitset_intersect (fe_bitset a, fe_bitset b);
fe_bitset fe_bitset_subtract (fe_bitset a, fe_bitset b);

Bool      fe_bitset_contains (fe_bitset a, fe_bitset b);
Bool      fe_bitset_equal (fe_bitset a, fe_bitset b);

Bool      fe_bitset_has_element (fe_bitset a, void *elem);
Bool      fe_bitset_is_empty (fe_bitset a);
unsigned  fe_bitset_size (fe_bitset a);

void      fe_bitset_for_all (fe_bitset a, void (*f) (void*));
fe_bitset fe_bitset_filter (fe_bitset a, Bool f (void*));

Bool      fe_bitset_property (fe_bitset a, Bool f (void *a, void *b), void *b);
void     *fe_bitset_for_all_acc (fe_bitset a, void *(*f) (void*, void*, void*), void *b, void *r);
void      fe_bitset_for_pairs (fe_bitset a, void (*f) (void*, void*));


#define fe_bitset_new_union(a,b)      fe_bitset_union (fe_bitset_dup(a), b)
#define fe_bitset_new_intersect(a,b)  fe_bitset_intersect (fe_bitset_dup(a), b)
#define fe_bitset_new_subtract(a,b)   fe_bitset_subtract (fe_bitset_dup(a), b)


#endif /* _bitset_h */
