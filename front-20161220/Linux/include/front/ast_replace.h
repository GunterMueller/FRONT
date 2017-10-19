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
#ifndef _ast_replace_h
#define _ast_replace_h

#include "front_list.h"

#define AST_replace(n)    ( (n)->_replace )

#define ast_replace_FIELDS         Front_List _replace;
#define ast_replace_INITS(me,t,u)  AST_replace(me) = NULL;

#define AST_set_replace(nd,l)   do { AST_replace(nd) = (l); } while(0)
#define AST_set_replace1(nd,n)  do { AST_replace(nd) = Create_Front_List(n,NULL); } while(0)

Front_List AST_replacement (void *node, int offset);
void init_AST_replace(void *table, void fill_table(void*,void*));
void *_AST_replace_list_nodes(void *node, void *table, void *trav_copy(), int offset);

#define ASTreplace_list_nodes(n,t,v) _AST_replace_list_nodes((n),(t),(v),(void*)&AST_replace(n)-(void*)(n))

#endif /*  _ast_replace_h */
