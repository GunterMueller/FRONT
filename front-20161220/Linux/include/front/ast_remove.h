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
#ifndef _ast_remove_h
#define _ast_remove_h

#define AST_remove(n)    ( (n)->_remove )

#define ast_remove_FIELDS         Bool _remove;
#define ast_remove_INITS(me,t,u)  AST_remove(me) = FALSE;

#define AST_mark_remove(nd) do { AST_remove(nd) = TRUE; } while(0)

Bool AST_is_marked (void *node, int offset);
void init_AST_remove(void *table, void fill_table(void*,void*));
void *_AST_remove_list_nodes(void *node, void *table, void *trav_copy(), int offset);
void *_AST_destroy_list_nodes(void *node, void *table, void *trav_copy(), int offset);


#define ASTremove_list_nodes(n,t,v) _AST_remove_list_nodes((n),(t),(v),(void*)&AST_remove(n)-(void*)(n))
#define ASTdestroy_list_nodes(n,t,v) _AST_destroy_list_nodes((n),(t),(v),(void*)&AST_remove(n)-(void*)(n))

#endif /*  _ast_remove_h */
