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

/*
 * Author: ir. P.A.C.J. van Loon Date: 03 Sep 1998
 *
 * Skiplists are a probabilistic way to implement a balanced tree like
 * data structure.  They represent a sorted list in which searching,
 * insertion and deletion can be done in avg. log(n) time.  See :
 * Pugh, William [1990]. Skip lists: A Probabilistic Alternative To
 * Balanced Trees.  Communications of the ACM, 33(6):668-676, June
 * 1990.
 *
 * Note that Element==(void *)0 can't be added to a fe_skiplist, it will
 * be ignored.
 *
 */

#ifndef _libfront_skiplist_h
#define _libfront_skiplist_h

#include "basic_types.h"

typedef struct fe_skiplist_node *fe_skiplist_node;

struct fe_skiplist_node {
    void *element;      /* user's element */
    fe_skiplist_node   backward;     /* skip list backward pointer */
    fe_skiplist_node   forward[1];   /* skip list forward pointer(s) */
};

typedef struct fe_skiplist {
  fe_skiplist_node    header;     /* list Header */
  int      level;      /* current level of list */
  int      maxlevel;   /* maximum level of list */
  int      part;       /* once in a 'part' times, a new level is added */
  fe_skiplist_node   *update;     /* scratch pad memory; an array of Node* of maxlevel elements */
  fe_comparison  compare;    /* compare two elements in a node : a - b */
} *fe_skiplist;

/* the bottom and top point to the beginning of the list, making it
 * effectively circular, avoids extensive NULL pointer testing
 */
#define fe_skiplist_bottom(s) (s)->header
#define fe_skiplist_top(s)    (s)->header


fe_skiplist fe_skiplist_new (fe_comparison compare); 
fe_skiplist fe_skiplist_new_advanced (fe_comparison compare, int maxlevel, int part);
fe_skiplist fe_skiplist_dup (fe_skiplist me);

void fe_skiplist_free (fe_skiplist me);
void fe_skiplist_destruct (fe_skiplist me, fe_destructor destructor);

fe_skiplist_node fe_skiplist_add (fe_skiplist me, void *elem);
fe_skiplist_node fe_skiplist_insert (fe_skiplist me, void *elem);
void fe_skiplist_remove (fe_skiplist me, void *elem);

/* these functions modify and return A */
fe_skiplist fe_skiplist_union (fe_skiplist a, fe_skiplist b);
fe_skiplist fe_skiplist_intersect (fe_skiplist a, fe_skiplist b);
fe_skiplist fe_skiplist_subtract (fe_skiplist a, fe_skiplist b);

#define fe_skiplist_new_union(a,b)    fe_skiplist_union (fe_skiplist_dup (a), b);
#define fe_skiplist_new_subtract(a,b) fe_skiplist_subtract (fe_skiplist_dup (a), b);
fe_skiplist fe_skiplist_new_intersect (fe_skiplist a, fe_skiplist b); 

Bool fe_skiplist_contains (fe_skiplist a, fe_skiplist b);
Bool fe_skiplist_equal (fe_skiplist a, fe_skiplist b);


#define fe_skiplist_has_element(sl,el)      (fe_skiplist_find(sl,el)!=NULL)
Bool    fe_skiplist_is_empty(fe_skiplist me);
size_t  fe_skiplist_size(fe_skiplist me);

void fe_skiplist_for_all (fe_skiplist me, void (*f)(void *elem, void *user), void *user);

void fe_skiplist_for_all_back (fe_skiplist me, void (*f)(void *elem, void *user), void *user);

fe_skiplist_node fe_skiplist_find (fe_skiplist me, void *elem);
fe_skiplist_node fe_skiplist_find_nearest (fe_skiplist skiplist, void *elem); 

fe_skiplist_node fe_skiplist_begin (fe_skiplist me);
fe_skiplist_node fe_skiplist_end (fe_skiplist me);

fe_skiplist_node fe_skiplist_node_next (fe_skiplist_node me);
fe_skiplist_node fe_skiplist_node_prev (fe_skiplist_node me);





/* extern void deleteSkipList(fe_skiplist skiplist) ; */
/* extern void deleteNode (fe_skiplist skiplist, void *element) ;  /\* deletes element too *\/ */
/* extern void removeNodeFreeElement (fe_skiplist skiplist, void *element, void (*freeElement)(void *)); /\* removes node frees element *\/ */

/* For performance reasons a macro is made out of a function definition,
   thereby unfortunately exposing internals of skiplist.
   Please don't rely on these internals as they may change without notice.
   Only the function interfaces and function semanctics will be stable or at least
   backward compatible.
*/

#define DEF_FIND_NODE(NAME,COMP)                                        \
fe_skiplist_node NAME(fe_skiplist skiplist, void *element) {            \
    int i;                                                              \
    fe_skiplist_node x;                                                 \
    int level;                                                          \
                                                                        \
    if(!skiplist || !element) return 0;                                 \
                                                                        \
    level = skiplist->level;                                            \
                                                                        \
    x = skiplist->header;                                               \
    for (i = level; i >= 0; i--) {                                      \
      while(x->forward[i] != fe_skiplist_bottom (skiplist)) {           \
	if(COMP(x->forward[i]->element, element)<0){                    \
	  x = x->forward[i];                                            \
	}else{                                                          \
	  break;                                                        \
	}                                                               \
      }                                                                 \
    }                                                                   \
    x = x->forward[0];                                                  \
                                                                        \
    if (x != fe_skiplist_bottom (skiplist)) {                           \
      if (COMP(element, x->element)==0) return (x);                     \
    }                                                                   \
    return(0);                                                          \
}

#endif /* _libfront_skiplist_h */
