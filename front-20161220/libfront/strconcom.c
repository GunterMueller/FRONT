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
this file implements the strongly connected components algorithm as described in
Introduction to algorithms
by Thomas H. Cormen, Charles E. Leiserson and Ronald L. Rivest
Ninth printing, 1993
The MIT electrical engineering and comouter science series
*/
#include <stdlib.h>
#include "mem.h"
#include "strconcom.h"

#define FALSE 0
#define TRUE 1

typedef enum {WHITE, GRAY, BLACK} color_t;

typedef struct scratch_s {
  color_t color;
  char make_root;
} scratch_t;

#define SCRATCH_COLOR(s)   (s)->color
#define SCRATCH_MAKE_ROOT(s) (s)->make_root

static void** (*top_scratch)(void* v);
static void (*top_new_tree)(void *v);
static void (*top_new_edge)(void *p, void *l);

static int num_vertices;
static void **sorted_vertices;
static int num_sorted_vertices;

static scratch_t* get_scratch(void *v)
{
  return (scratch_t*)(*(top_scratch(v)));
}

static void init_vertex(void* v)
{
  *(top_scratch(v)) = fe_malloc(sizeof(scratch_t));
  num_vertices++;
}

static void clear_vertex(void* v)
{
  scratch_t *v_s;
  v_s = get_scratch(v);
  SCRATCH_COLOR(v_s) = WHITE;
  SCRATCH_MAKE_ROOT(v_s) = TRUE;
}

static void finish_vertex(void* v)
{
  scratch_t **s;
  s = (scratch_t**)top_scratch(v);
  if (*s != NULL) {
    fe_free(*s);
    *s = NULL;
  }
}

static void init_scc(void (*map_vertex)(void (*f)(void *v)))
{
  num_vertices = 0;
  map_vertex(init_vertex);
  sorted_vertices = (void**)fe_malloc(sizeof(void*)*num_vertices);
  num_sorted_vertices = 0;
}

static void clear_vertices(void (*map_vertex)(void (*f)(void *v)))
{
  map_vertex(clear_vertex);
}

static void finish_scc(void (*map_vertex)(void (*f)(void *v)))
{
  map_vertex(finish_vertex);
  if (sorted_vertices != NULL) {
    fe_free(sorted_vertices);
    sorted_vertices = NULL;
  }
}

void sorted_map_vertex(void (*f)(void *v))
{
  int i;
  for (i = num_sorted_vertices-1; i >= 0; i--) {
    f(sorted_vertices[i]);
  }
}

/* implementation of Depth-First-Search */

static void (*DFS_map_succ)(void (*f)(void *src, void *tgt), void *src);
static int DFS_mode; 

static void DFS_visit(void *u);

static void DFS_visit_main(void *u, void *v)
{
  scratch_t *u_s;
  scratch_t *v_s;
  u_s = get_scratch(u);
  v_s = get_scratch(v);
  
  if (DFS_mode == 1) {
    if (SCRATCH_MAKE_ROOT(u_s) == TRUE) {
      /* u is root of a tree in the depth-first forest */
      top_new_tree(u);
      SCRATCH_MAKE_ROOT(u_s) = FALSE;
    }
  }
  if (SCRATCH_COLOR(v_s) == WHITE) {
    if (DFS_mode == 1) {
      /* edge from u to v is an edge of the depth-first tree */
      SCRATCH_MAKE_ROOT(v_s) = FALSE;
      top_new_edge(u, v);
    }
    DFS_visit(v);
  }
}

static void DFS_visit(void *u)
{
  scratch_t *u_s;
  u_s = get_scratch(u);

  SCRATCH_COLOR(u_s) = GRAY;
  DFS_map_succ(DFS_visit_main, u);
  SCRATCH_COLOR(u_s) = BLACK;
  if (DFS_mode == 0) {
    sorted_vertices[num_sorted_vertices] = u;
    num_sorted_vertices++;
  }
}
  

static void DFS_main(void* u)
{
  scratch_t *u_s;
  u_s = get_scratch(u);
  if (SCRATCH_COLOR(u_s) == WHITE) {
    DFS_visit(u);
  }
}
    

static void DFS(void (*map_vertex)(void (*f)(void *v)), 
                void (*map_succ)(void (*f)(void *src, void *tgt), void *src),
		int mode /* mode 0: store in array sorted_vertices the vertices sorted by finishing time; 
			    mode 1: perform calls new_tree and new_edge */)
  
{
  DFS_map_succ = map_succ;
  DFS_mode     = mode;

  clear_vertices(map_vertex);
  map_vertex(DFS_main);
}

/**********************************************************************/

void strongly_connected_components(void** (*scratch)(void* v), 
                                   void (*map_vertex)(void (*f)(void *v)), 
                                   void (*map_succ)(void (*f)(void *v, void *succ), void *v),
                                   void (*map_pred)(void (*f)(void *v, void *pred), void *v),
				   void (*new_tree)(void *v),
                                   void (*new_edge)(void *parent, void *leave))
{
  top_scratch = scratch;
  top_new_tree = new_tree;
  top_new_edge = new_edge;

  init_scc(map_vertex);
  DFS(map_vertex, map_succ, 0);
  DFS(sorted_map_vertex, map_pred, 1);
  finish_scc(map_vertex);
}
