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
this file implements Dijkstra's shortest path algorithm as described in
Introduction to algorithms
by Thomas H. Cormen, Charles E. Leiserson and Ronald L. Rivest
Ninth printing, 1993
The MIT electrical engineering and comouter science series
*/
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "skiplist.h"

#define NOT_USED(x) ((x) = (x))

/* priority queue containing vertices which shortest distance from the source has not been determined yet; 
   sorted on currently determined shortest distance from source, smallest first
*/
static fe_skiplist q; 

/* copy of distance parameter of shortest_paths */
static int *((*dist)(void *v));

/* copy of map_edges parameter of shortest_paths */
static void (*map)(int (*f)(void *src, void *tgt, int wght), void *src);

static int compare(void *u, void *v)
{
  int diff = (*dist(u)) < (*dist(v));
  if (diff!=0) return diff;
  return (u - v);
}

static void init_vertex(void *u)
{
  (*dist(u)) = INT_MAX; 
}

/* initialize vertex u
   when vertex u is not in the queue:
     add u to the queue
     initialize and add successors of u to the queue
*/
static int init_add_vertex(void *u, void *v, int w)
{
  fe_skiplist_node n;
  
  NOT_USED(v);
  NOT_USED(w);
  init_vertex(u);
  n = fe_skiplist_find(q, u);
  if (n == NULL) {
    /* node not in set, add node and (add and initialize) successor nodes */
    fe_skiplist_insert(q, u);
    map(init_add_vertex, u);
  }
  return 0;
}

/* initialize queue and graph nodes */
static void initialize_shortest_paths(void *source)
{
  q = fe_skiplist_new (compare);
  init_add_vertex(source, NULL, 0);
  fe_skiplist_remove(q, source);
  (*dist(source)) =  0;
  fe_skiplist_insert(q, source);
}


/* try to decrease the upper bound on the shortest path to v */
static int relax(void *u, void *v, int weight)
{
  int res;
  assert((INT_MAX - weight) > (*dist(u)));
  if (((*dist(u)) + weight) < (*dist(v))) {
    fe_skiplist_remove(q, v);
    (*dist(v)) = (*dist(u)) + weight;
    fe_skiplist_insert(q, v);
    res = 1;
  } else {
    res = 0;
  }  
  return res;
}

/* calculate shortest paths from vertex source to every vertex
   this implementation uses Dijkstra's algorithm
   it uses a skiplist to implement the priority queue (avg. log(n) time for searching, insertion and deletion)
   vertices that are not reachable from source are left untouched
   parameters:
     source       - node to calculate the distances to
     distance     - function returning a pointer to the distance field of the vertex v
     map_edges    - function that applies f to all outgoing edges of src where an edge is from src to tgt
                    with weight w
                    for the last invocation of f, for a given tgt and some edge to tgt, that returns true, the edge 
                    is part of the shortest path from source to tgt
                    map_edges function should be re-entrant
   PRE: all edge weights are nonnegative

   Example usage:

   int *distance(void *v) 
   { 
     return &(v->dist); 
   }

   void map(int (*f)(void*, void*, int), void *src)
   {
     int i;
     for (i = 0; i < (src->num_succ); i++) {
       if (f(src, src->succ[i], src->weight[i]) {
         src->succ[i]->pred = src;
       }
     }
   }

  void print_shortest_path(void *tgt)
  {
    print_shortest_path(tgt->pred);
    print_vertex(tgt);
  }

  void main()
  {
    ...
    shortest_paths(source, distance, map);
    print_shortest_path(tgt);
  }
*/
void shortest_paths(void *source, 
		    int *((*distance)(void *v)), 
		    void (*map_edges)(int (*f)(void *src, void *tgt, int w), void *src)
		    )
{
  fe_skiplist_node n;
  void *vertex;
  /* initialize graph functions */
  dist = distance;
  map = map_edges;
  /* initialize queue and graph nodes */
  initialize_shortest_paths(source);
  /* calculate shortest paths */
  for (n = fe_skiplist_begin(q); n != NULL; n = fe_skiplist_begin(q)) {
    vertex = n->element;
    fe_skiplist_remove(q, vertex);
    map(relax, vertex);
  }
  /* finish */
  fe_skiplist_free(q);
}
