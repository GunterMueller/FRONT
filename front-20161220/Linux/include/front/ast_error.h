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
#ifndef _ast_error_h
#define _ast_error_h

#define AST_error(n)    ( (n)->fields.error )
#define AST_warning(n)  ( (n)->fields.warning )
#define AST_message(n)  ( (n)->fields.message )
#define AST_loc(n)      ( (n)->src_info->loc )

typedef void (*AST_set_error_type)(void *, char *, ...);

typedef struct s_AST_error_fields {
  Bool error;
  Bool warning;
  char *message;
} *AST_error_fields;

#define ast_error_FIELDS         struct s_AST_error_fields fields;
#define ast_error_INITS(me,t,u)  AST_error(me) = FALSE;  \
                                 AST_warning(me) = FALSE; \
                                 AST_message(me) = NULL;

#define AST_mark_error(n)     do { AST_error(n) = TRUE; } while (0)
#define AST_mark_warning(n)   do { AST_warning(n) = TRUE; } while (0)

/* I don't know a way to do this without this GNU C extension --WY */
#define AST_set_error(n,f,a...)   _AST_set_error(&n->fields, f, ## a)
#define AST_set_warning(n,f,a...) _AST_set_warning(&n->fields, f, ## a)

#define ASTprint_errors(n,t,v) _AST_print_errors(n,t,v,&(n)->fields-&(n), &(n)->src_info-&(n))
#define ASTclear_errors(n,t,v) _AST_clear_errors(n,t,v,&(n)->fields-&(n))

void _AST_set_error(AST_error_fields node, char *fmt, ...);
void _AST_set_warning(AST_error_fields node, char *fmt, ...);
void _vAST_set_error(AST_error_fields node, char *fmt, va_list args);
void _vAST_set_warning(AST_error_fields node, char *fmt, va_list args);

void init_AST_error(void *print, void *clear, void fill_table(void*,void*));

int _AST_print_errors(void *node, void *print_table, void trav_void(), int fields, int srcinfo);
void _AST_clear_errors(void *node, void *clear_table, void trav_void(), int fields);

#endif /*_ast_error_h */
