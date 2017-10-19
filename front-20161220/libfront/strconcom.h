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
#ifndef _strconcom_h
#define _strconcom_h

/* calculate the strongly connected components of a directed graph    
   it uses a skiplist to implement the priority queue (avg. log(n) time for searching, insertion and deletion)

   void strongly_connected_components(void** (*scratch)(void), 
                                      void (*map_vertex)(void (*f)(void *v)), 
                                      void (*map_succ)(void (*f)(void *v, void *succ), void *v),
                                      void (*map_pred)(void (*f)(void *v, void *pred), void *v),
		  	              void (*new_tree)(void *v),
                                      void (*new_edge)(void *parent, void *leaf));

   parameters:
     scratch      - function returning a pointer to a void pointer field of the vertex v
                    (This void pointer field is use to store a pointer to some scratch structure
                    where the algorithm stores some computed intermediated results for the vertex.)
     map_vertex   - function that applies f to all vertices.
     map_succ     - function that applies f to all outgoing edges of the given vertex
     map_pred     - function that applies f to all incoming edges of the given vertex

   The following two functions are used to report the constructed components back to the user:

     new_tree     - function that "creates" a new component consisting of the given vertex.
                    The given vertex is the root of the corresponding depth-first search tree
     new_edge     - function that "adds" a vertex to the component. The given edge is an edge
                    of the depth-first search tree. The tree is constructed in a top-down order.


   Example usage:

   void **scratch(void *v) 
   { 
     return &(v->scratch); 
   }

   void map_vertex(int (*f)(void*))
   {
     int i;
     for (i = 0; i < num_vertices; i++) {
       f(vertex[i]);
     }
   }

   void map_succ(int (*f)(void*, void*), void *v)
   {
     int i;
     for (i = 0; i < (v->num_succs); i++) {
       f(v, v->succ[i]);
     }
   }
  
   void map_pred(int (*f)(void*, void*), void *v)
   {
     int i;
     for (i = 0; i < (v->num_preds); i++) {
       f(v, v->pred[i]);
     }
   }
   
   int num_components = 0;

   void new_tree(void* v)
   {
     v->comp_num = num_components;
     num_components++;
   }

   void new_edge(void* parent, void* leaf)
   {
     leaf->comp_num = parent->comp_num;
   }

  void main()
  {
    strongly_connected_components(scraths, 
                                  map_vertex, map_pred, map_succ,
                                  new_tree, new_edge);
    /+ print for each vertex the component number it belongs to +/
    for (i = 0; i != num_vertex; i++) {
       printf("%d\n", vertex[i]->comp_num);
    }       
  }
*/

void strongly_connected_components(void** (*scratch)(void *v), 
                                   void (*map_vertex)(void (*f)(void *v)), 
                                   void (*map_succ)(void (*f)(void *v, void *succ), void *v),
                                   void (*map_pred)(void (*f)(void *v, void *pred), void *v),
				   void (*new_tree)(void *v),
                                   void (*new_edge)(void *parent, void *leaf));
#endif
