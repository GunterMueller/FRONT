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
#include "front_list.h"
#include "ast_remove.h"
#include "mem.h"

static int mark_offset;
static Bool free_elements = FALSE;

/* ----------------------------------------------------------------------------
 * Check whether a node is marked.
 */
Bool
AST_is_marked (void *node, int offset)
{
  Bool *mark = node+mark_offset;
  mark_offset = offset;
  return *mark;
}

/* ----------------------------------------------------------------------------
 * Remove a node from LIST if it has been marked so.
 */
static Front_List
AST_remove_node(Front_List list)
{
  if(!list) return NULL;
  if(!Front_List_data(list)) return Front_List_next(list);
  
  if (!AST_is_marked(Front_List_data(list), mark_offset)) return list;

  if (free_elements) fe_free (Front_List_data (list));
  return Front_List_next(list);;
}

/* ----------------------------------------------------------------------------
 * Remove a node from OPT if it has been marked so.
 */
static Front_Optional
AST_remove_opt_node(Front_Optional list)
{
  if(!list) return NULL;
  if(!Front_Optional_data(list)) return NULL;
  
  if (!AST_is_marked(Front_Optional_data(list), mark_offset)) return list;

  if (free_elements) fe_free (Front_Optional_data (list));
  return NULL;
}

/* ----------------------------------------------------------------------------
 * Call AST_print_error as a POST_ACTION on "top-level" structs
 */
static void *
fill_remove_list_nodes(Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action)
{
  NOT_USED(e_num);
  NOT_USED(sub);
  NOT_USED(memo);
  if (list && action == 0) return AST_remove_node;
#if 0
  if (opt && action == 0) return AST_remove_opt_node;
#else
  NOT_USED(opt);
#endif
  return NULL;
}

/* ----------------------------------------------------------------------------
 * Initialize remove_list_nodes traverse table
 */
void
init_AST_remove(void *table, void fill_table(void*,void*))
{
  struct s_copy_TraverseTable {
    Front_ClearBackEdges clear_back_edges;
  } *copy_table = table;
  
  copy_table->clear_back_edges = Just_Traverse;
  fill_table (copy_table, fill_remove_list_nodes);
}

/* ----------------------------------------------------------------------------
 * Remove marked list nodes in NODE
 */
void *
_AST_remove_list_nodes(void *node, void *table, void *trav_copy(), int offset)
{
  mark_offset = offset;
  free_elements = FALSE;
  return trav_copy(node, table);
}

/* ----------------------------------------------------------------------------
 * Remove marked list nodes in NODE
 */
void *
_AST_destroy_list_nodes(void *node, void *table, void *trav_copy(), int offset)
{
  mark_offset = offset;
  free_elements = TRUE;
  return trav_copy(node, table);
}
