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
/* skip list */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "support.h"
#include "skiplist.h"
#include "mem.h"

/*
 * Author: ir. P.A.C.J. van Loon
 * Date:   03 Sep 1998
 *
 * $Id$
 *
 * Skiplists are a probabilistic way to implement a balanced tree like data structure.
 * They represent a sorted list in which searching, insertion and deletion can be done in avg. log(n) time.
 * See :
 * Pugh, William [1990]. Skip lists: A Probabilistic Alternative To Balanced Trees. 
 * Communications of the ACM, 33(6):668-676, June 1990.
 *
 * Note that Element==(void *)0 can't be added to a SkipList, it will be ignored.
 *
 */

/*
 * SKIPLIST STRUCTURE
 *
 * see comments in code to determine behaviour of skiplist; as SET or BAG representative
 * SET : A skiplist implements a sorted SET of Elements, the comparison functions determine equivalence classes
 * BAG : A skiplist implements a sorted BAG of Elements
 *
 * SkipList *    SkipList    Node          	Node           Node    
 * +----------+  +---------+  +------------+   +------------+   +----
 * | skiplist |->| header  |->| element    | +>| element    | +>| 
 * +----------+  +---------+  +------------+ | +------------+ | 
 *               | level   |  | backward   | | | backward   | | 
 *               +---------+  +------------+ | +------------+ |                                         
 *               | compare |  | forward[0] |-+ | forward[0] |-+   -->  Always there                     
 *               +---------+  +------------+   +------------+     -.                                    
 *               | compEQ  |  | forward*   |   | forward*   |->    |                                    
 *               +---------+  .            .   .            .       >  Optional, grow on demand         
 *                            | forward*   |   | forward*   |->    |                                    
 *                            +------------+   +------------+     -'                                    
 *                            1st node has                                                             
 * 			      special status;                                                          
 *			      it's no data node                                                        
 *
 */

/* levels range from (0 .. MAXLEVEL). default value, use fe_new_skiplist_advanced to supply runtime values */
#define MAXLEVEL 15

/* one in a PART times a new level is introduced. default value, use fe_new_skiplist_advanced to supply runtime values */
#define PART 2

enum add_method {
  bag_add,
  set_add,
};

/* ----------------------------------------------------------------------------
 * Find the node in skiplist ME nearest to ELEM. Returns the node of
 * ELEM if it's in the list, obviously.
 */
fe_skiplist_node
fe_skiplist_find_nearest (fe_skiplist me, void *elem)
{
  int i;
  fe_skiplist_node x;
  
  if (!me || !elem) return NULL;
  
  /* find where element belongs */
  x = fe_skiplist_bottom(me);
  for (i = me->level; i >= 0; i--) {
    while (x->forward[i] != fe_skiplist_bottom(me) 
           && me->compare(x->forward[i]->element, elem) < 0) {
      x = x->forward[i];
    }
  }
  /* move to next position */
  x = x->forward[0];
  
  return x;
}

/* ----------------------------------------------------------------------------
 * Get a random level: 0 <= newLevel <= maxlevel,
 */
static int
random_new_level(fe_skiplist me)
{
  int i, new_level;

  for (new_level = 0;
       rand() <= (RAND_MAX/me->part) && new_level < me->maxlevel;
       new_level++)
    { }
  
  if (me->level < new_level) {
    for (i = me->level + 1; i <= new_level; i++) {
      me->update[i] = fe_skiplist_bottom (me);
    }
    me->level = new_level;
  }

  return new_level; 
}

/* ----------------------------------------------------------------------------
 * Add an element ELEM in skiplist ME.
 * for MODE == bag_add this will add duplicates
 * for MODE == set_add this will not add duplicates
 * returns the created node or the node duplicate present in the skiplist
 */
static fe_skiplist_node
add_node(fe_skiplist me, void *elem, enum add_method mode)
{
  int i, new_level;
  fe_skiplist_node x;

  if(!me || !elem) return NULL;

  x = fe_skiplist_find_nearest (me, elem);
  assert (x);
  
  if (mode==set_add) {
    if (x != fe_skiplist_bottom (me) && me->compare (elem, x->element)==0) {
      return x;
    }
  }

  /* probabilistically determine new level */
  new_level = random_new_level (me);

  /* make new node with (new_level+1) forward pointers  */
  x = fe_malloc (sizeof (struct fe_skiplist_node) + 
                 new_level*sizeof (fe_skiplist_node));
  x->element = elem;

  /* update backward link */
  me->update[0]->forward[0]->backward = x;
  x->backward = me->update[0];

  /* update forward links to and from new node */
  for (i = 0; i <= new_level; i++) {
    x->forward[i] = me->update[i]->forward[i];
    me->update[i]->forward[i] = x;
  }

  return x;
}

/* ----------------------------------------------------------------------------
 * Add ELEMENT to skiplist ME, duplicates are not added
 */
fe_skiplist_node
fe_skiplist_insert(fe_skiplist skiplist, void *element)
{
  return add_node(skiplist, element, set_add);
}

/* ----------------------------------------------------------------------------
 * Add ELEMENT to skiplist ME, duplicates are added too
 */
fe_skiplist_node
fe_skiplist_add(fe_skiplist me, void *element)
{
  return add_node (me, element, bag_add);
}

static void
reverse_skiplist_add (void *elem, fe_skiplist me)
{
  fe_skiplist_add (me, elem);
}



/* fe_skiplist_node findNode(fe_skiplist skiplist, void *element) */
DEF_FIND_NODE(fe_skiplist_find, skiplist->compare)

/* ----------------------------------------------------------------------------
 * BAG : remove first equal address from BAG 
 */
static void
remove_node(fe_skiplist me, fe_skiplist_node x, fe_destructor destructor)
{
  int i;
  /* adjust forward pointers */
  for (i = 0; i <= me->level; i++) {
    if (me->update[i]->forward[i] == x) {
      me->update[i]->forward[i] = x->forward[i];
    }
  }
  /* adjust backward pointer of forward node */
  x->forward[0]->backward = x->backward;

  if (destructor) destructor (x->element);
  fe_free (x);

  /* adjust header level */
  while (me->level > 0 &&
         fe_skiplist_bottom(me)->forward[me->level] == fe_skiplist_bottom(me)) {
    me->level--;
  }
}

void
deleteNode(fe_skiplist me, void *elem)
{
  fe_skiplist_node x;

  x = fe_skiplist_find (me, elem);
  if (!x) return;
            
  remove_node (me, x, fe_free);
}

void
fe_skiplist_remove(fe_skiplist me, void *elem)
{
  fe_skiplist_node x;

  x = fe_skiplist_find (me, elem);
  if (!x) return;
  
  remove_node (me, x, NULL);
}

void
removeNodeFreeElement(fe_skiplist me, void *elem,
                      fe_destructor destructor)
{
  fe_skiplist_node x;

  x = fe_skiplist_find (me, elem);
  if (!x) return;
  
  remove_node (me, x, destructor);
}

static void
reverse_skiplist_remove (void *elem, fe_skiplist me)
{
  fe_skiplist_remove (me, elem);
}

void
fe_skiplist_destruct(fe_skiplist me, fe_destructor destructor)
{ 
  fe_skiplist_node x, next;  

  if (!me) return;

  for (x = fe_skiplist_begin(me); x; x = next) {
    if (x->forward[0] != fe_skiplist_bottom(me)) next = x->forward[0];
    else next = NULL;

    if (destructor) destructor (x->element);

    fe_free(x);
  }

  fe_free (me->header);
  fe_free (me->update);
  fe_free (me);
}

void
deleteSkipList(fe_skiplist skiplist)
{
  fe_skiplist_destruct (skiplist, fe_free);
}

void
fe_skiplist_free(fe_skiplist me)
{
  fe_skiplist_destruct (me, NULL);
}

fe_skiplist
fe_skiplist_new (fe_comparison compare)
{
  return fe_skiplist_new_advanced (compare, MAXLEVEL, PART);
}

fe_skiplist
fe_skiplist_new_advanced (fe_comparison compare,
                          int maxlevel, int part)
{
  fe_skiplist me;
  int i;

  if (!compare) return 0;
  
  me = fe_malloc (sizeof (struct fe_skiplist));
  me->header = fe_malloc (sizeof (struct fe_skiplist_node) +
                               maxlevel*sizeof (fe_skiplist_node));
  me->update = fe_malloc ((maxlevel+1) * sizeof (fe_skiplist_node));

  me->header->element = NULL;

  for (i = 0; i <= maxlevel; i++) {
    me->header->forward[i] = fe_skiplist_bottom(me);
  }

  me->header->backward = fe_skiplist_bottom(me);

  me->level = 0;
  me->maxlevel = maxlevel;
  me->part = part;

  me->compare = compare;

  return me;
}

/* ----------------------------------------------------------------------------
 * Duplicate skiplist ME without the elements
 */
fe_skiplist
fe_skiplist_dup_skeleton (fe_skiplist me)
{
  return fe_skiplist_new_advanced (me->compare, me->maxlevel, me->part);
}

/* ----------------------------------------------------------------------------
 * Duplicate skiplist ME
 */
fe_skiplist
fe_skiplist_dup (fe_skiplist me)
{
  return fe_skiplist_union (fe_skiplist_dup_skeleton (me), me);
}

/* ----------------------------------------------------------------------------
 * Number of elements in skiplist ME
 */
size_t
fe_skiplist_size (fe_skiplist me)
{
  fe_skiplist_node n;
  size_t s=0;
  
  for (n = fe_skiplist_begin (me); n; n = fe_skiplist_node_next (n)) {
    s++;
  }
  return s;
}

Bool
fe_skiplist_is_empty (fe_skiplist me)
{
  return  !me || me->header->forward[0]==fe_skiplist_bottom(me);
}

fe_skiplist_node
fe_skiplist_begin (fe_skiplist me)
{
  fe_skiplist_node first;

  if (!me) return NULL;
  first = me->header->forward[0]; 
  if (first==fe_skiplist_bottom(me)) return NULL;
  return first;
}

fe_skiplist_node
fe_skiplist_end (fe_skiplist me)
{
  fe_skiplist_node last;

  if(!me) return NULL;
  last = me->header->backward;
  if(last==fe_skiplist_bottom(me)) return NULL;
  return last;
}

/* ----------------------------------------------------------------------------
 * Add all elements of B to A
 */
fe_skiplist
fe_skiplist_union (fe_skiplist a, fe_skiplist b)
{
  assert (a->compare == b->compare);
  fe_skiplist_for_all (b, (void*)reverse_skiplist_add, a);
  return a;
}

/* ----------------------------------------------------------------------------
 * Remove elements of A that are not in B
 */
fe_skiplist
fe_skiplist_intersect (fe_skiplist a, fe_skiplist b)
{
  fe_skiplist_node an, bn, next;
  
  if (!a || !b) return NULL;
  assert (a->compare == b->compare);

  for (an = fe_skiplist_begin (a), bn = fe_skiplist_begin (b);
       an || bn;
       an = next) {
    int diff;
    next = fe_skiplist_node_next (an);

    if (!an) diff = 1;
    else if (!bn) diff = -1;
    else diff = a->compare (an->element,bn->element);
    
    if (diff==0) { /* same element in a and b */
      bn = fe_skiplist_node_next (bn);
    } else if (diff < 0) { /* a before b */
      remove_node (a, an, NULL);
    } else { /* b before a */
      bn = fe_skiplist_node_next (bn);
    }
  }
  return a;
}

/* ----------------------------------------------------------------------------
 * Remove elements of A that are in B
 */
fe_skiplist
fe_skiplist_subtract (fe_skiplist a, fe_skiplist b)
{
  assert (a->compare == b->compare);
  fe_skiplist_for_all (b, (void*)reverse_skiplist_remove, a);
  return a;
}

/* ----------------------------------------------------------------------------
 * Create a new skiplist from the intersection of A and B
 */
fe_skiplist
fe_skiplist_new_intersect (fe_skiplist a, fe_skiplist b)
{
  fe_skiplist result;
  fe_skiplist_node an, bn;
  
  if (!a || !b) return NULL;
  assert (a->compare == b->compare);

  result = fe_skiplist_dup_skeleton (a);
  for (an = fe_skiplist_begin (a), bn = fe_skiplist_begin (b);
       an || bn;) {
    int diff;

    if (!an) diff = 1;
    else if (!bn) diff = -1;
    else diff = a->compare (an->element,bn->element);
    
    if (diff==0) { /* same element in a and b */
      fe_skiplist_add (result, an->element);
    } else if (diff < 0) { /* a before b */
      an = fe_skiplist_node_next (an);
    } else { /* b before a */
      bn = fe_skiplist_node_next (bn);
    }
  }
  return a;
}

Bool
fe_skiplist_equal (fe_skiplist a, fe_skiplist b)
{
  fe_skiplist_node an, bn;
  
  for (an = fe_skiplist_begin (a), bn = fe_skiplist_begin (b);
       an && bn;
       an = fe_skiplist_node_next (an), bn = fe_skiplist_node_next (bn)) {
    if (a->compare (an->element,bn->element)!=0) {
      return FALSE;
    }
  }
  return an == bn;
}

Bool
fe_skiplist_contains (fe_skiplist a, fe_skiplist b)
{
  fe_skiplist_node an, bn;
  
  for (an = fe_skiplist_begin (a), bn = fe_skiplist_begin (b);
       an && bn;) {
    int diff = a->compare (an->element,bn->element);
    if (diff<0) {
      an = fe_skiplist_node_next (an);
    } else if (diff==0) {
      an = fe_skiplist_node_next (an);
      bn = fe_skiplist_node_next (bn);
    } else return FALSE;
  }
  return !bn;
}

void
fe_skiplist_for_all (fe_skiplist me,
                     void (*f)(void *element, void *user), void *user)
{
  fe_skiplist_node n;
  
  if (!f) return;

  for (n = fe_skiplist_begin (me); n; n = fe_skiplist_node_next (n)) {
    f (n->element, user);
  }
}

void
fe_skiplist_for_all_back (fe_skiplist me,
                          void (*f)(void *element, void *user), void *user)
{
  fe_skiplist_node n;

  if (!f) return;

  for (n = fe_skiplist_end (me); n; n = fe_skiplist_node_prev (n)) {
    f (n->element, user);
  }
}

fe_skiplist_node
fe_skiplist_node_next (fe_skiplist_node me)
{
  fe_skiplist_node next;

  if(!me) return NULL;
  next = me->forward[0];
  if(!next->element) return NULL;
  return next;
}

fe_skiplist_node
fe_skiplist_node_prev (fe_skiplist_node me)
{
  fe_skiplist_node prev;

  if(!me) return NULL;
  prev = me->backward;
  if(!prev->element) return NULL;
  return prev;
}

