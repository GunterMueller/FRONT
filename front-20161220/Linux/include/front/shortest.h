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
#ifndef _shortest_h
#define _shortest_h

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
                    map_edges should be re-entrant
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
		    void (*map_edges)(int (*f)(void *src, void *tgt, int weight), void *src)
		    );

#endif
