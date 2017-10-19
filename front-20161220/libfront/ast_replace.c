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
#include "ast_replace.h"

static int mark_offset;

/* ----------------------------------------------------------------------------
 * Get the replacement of NODE
 */
Front_List
AST_replacement (void *node, int offset)
{
  Front_List *mark = node+offset;
  return *mark;
}

/* ----------------------------------------------------------------------------
 * Replace a node from LIST by its replacement.
 */
static Front_List
AST_replace_node(Front_List list)
{
  Front_List repl;
  
  if(!list) return NULL;
  if(!Front_List_data(list)) return Front_List_next(list);

  repl = AST_replacement (Front_List_data(list), mark_offset);
  if (!repl) return list;

  FRONT_APPEND(repl, Front_List_next (list));
  return repl;
}

/* ----------------------------------------------------------------------------
 * Call AST_replace_node as a POST_ACTION on "top-level" structs
 */
static void *
fill_replace_list_nodes(Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action)
{
  NOT_USED(e_num);
  NOT_USED(sub);
  NOT_USED(memo);
  NOT_USED(opt);
  if (list && action == 0) return AST_replace_node;
  return NULL;
}

/* ----------------------------------------------------------------------------
 * Initialize replace_list_nodes traverse table
 */
void
init_AST_replace(void *table, void fill_table(void*,void*))
{
  struct s_copy_TraverseTable {
    Front_ClearBackEdges clear_back_edges;
  } *copy_table = table;
  
  copy_table->clear_back_edges = Just_Traverse;
  fill_table (copy_table, fill_replace_list_nodes);
}

/* ----------------------------------------------------------------------------
 * Replace list nodes in NODE
 */
void *
_AST_replace_list_nodes(void *node, void *table, void *trav_copy(), int offset)
{
  mark_offset = offset;
  return trav_copy(node, table);
}

