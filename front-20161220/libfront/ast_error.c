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
#include <stdarg.h>
#include "print_support.h"
#include "support.h"
#include "error.h"
#include "ast_error.h"

static int fields_offset;
static int srcinfo_offset;

/* ----------------------------------------------------------------------------
 * Set the error message of NODE
 */
void
_AST_set_error(AST_error_fields fields, char *fmt, ...)
{
  
  va_list args;
  va_start(args,fmt);

  _vAST_set_error (fields, fmt, args);
  va_end(args);
}

void
_AST_set_warning(AST_error_fields fields, char *fmt, ...)
{
  va_list args;
  va_start(args,fmt);
  
  _vAST_set_warning (fields, fmt, args);
  va_end(args);
}

void
_vAST_set_error(AST_error_fields fields, char *fmt, va_list args)
{
  fields->message = Front_vStrAllocf(fmt, args);
  fields->error = TRUE;
}

void
_vAST_set_warning(AST_error_fields fields, char *fmt, va_list args)
{
  fields->message = Front_vStrAllocf(fmt, args);
  fields->warning = TRUE;
}

/* ----------------------------------------------------------------------------
 * Print the error message of NODE if it has one
 */
static void
AST_print_error(void *node)
{
  AST_error_fields fields = node+fields_offset;
  SrcInfo *srcinfo = node+srcinfo_offset;
  
  if(node && fields->error && fields->message) {
    InputError(SrcInfo_loc(*srcinfo), TRUE, fields->message);
    fields->message = NULL;
  }
  if(node && fields->warning && fields->message) {
    InputWarning(SrcInfo_loc(*srcinfo), 5, TRUE, fields->message);
    fields->message = NULL;
  }
}

/* ----------------------------------------------------------------------------
 * Print the error message of NODE if it has one
 */
static void
AST_clear_error(void *node)
{
  AST_error_fields fields = node+fields_offset;
  
  if(!node) return;
  fields->error = FALSE;
  fields->warning = FALSE;
  fields->message = NULL;
}

/* ----------------------------------------------------------------------------
 * Call AST_print_error as a PRE_ACTION on "top-level" structs
 */
static void *
fill_print_errors(Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action)
{
  if (e_num || sub || list || opt || memo) return NULL;
  if (action == 1) return AST_print_error;
  else return NULL;
}

/* ----------------------------------------------------------------------------
 * Call AST_print_error as a PRE_ACTION on "top-level" structs
 */
static void *
fill_clear_errors(Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action)
{
  if (e_num || sub || list || opt || memo) return NULL;
  if (action == 1) return AST_clear_error;
  else return NULL;
}

/* ----------------------------------------------------------------------------
 * Initialize traverse tables
 */
void
init_AST_error(void *print, void *clear, void fill_table(void*,void*))
{
  fill_table(print, fill_print_errors);
  fill_table(clear, fill_clear_errors);
}

/* ----------------------------------------------------------------------------
 * Print the error messages in NODE
 */
int
_AST_print_errors(void *node, void *print_table, void trav_void(),
                  int fields, int srcinfo)
{
  int d, e = NumErrors;
  
  fields_offset = (int)fields;
  srcinfo_offset = (int)srcinfo;
  
  NumErrors = 0;
  trav_void(node, print_table);
  d = NumErrors;
  if(d==0) NumErrors = e;
  return d;
}

/* ----------------------------------------------------------------------------
 * Clear the error messages in NODE
 */
void
_AST_clear_errors(void *node, void *clear_table, void trav_void(), int fields)
{
  fields_offset = (int)fields;
  trav_void(node, clear_table);
}
