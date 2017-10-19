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

#ifndef _basic_types
#define _basic_types

#include <stddef.h>
#include <stdlib.h>
#ifdef __MINGW32__
#include <libiberty.h>
#endif

/* The Front basic types */

typedef char Char;
typedef Char *String;
typedef int Int;
typedef int Oct;
typedef int Hex;
typedef double Float;
typedef void *Pointer;
typedef int (*fe_comparison)(void *a, void *b);
typedef void (*fe_destructor)(void *p);

typedef enum { UnEval, UnderEval, Evaluated, EvalCyclic } EvalState;

#include "support.h"
#include "hash.h"
#include "front_list.h"
#include "scan_support.h"

#define Create_Ident(s) Make_identifier(s)
#define Ident_name(id)	IDENT_NAME(id)

/* Basic comparison functions for traversals */
Bool Traverse_compare_List_Int (List_Int x, List_Int y, void *z);
Bool Traverse_compare_List_Char (List_Char x, List_Char y, void *z);
Bool Traverse_compare_List_Bool (List_Bool x, List_Bool y, void *z);
Bool Traverse_compare_List_Ident (List_Ident x, List_Ident y, void *z);
Bool Traverse_compare_List_String (List_String x, List_String y, void *z);
Bool Traverse_compare_Ident  (Ident,  Ident, void*);
Bool Traverse_compare_Char   (Char,   Char, void*);
Bool Traverse_compare_String (String, String, void*);
Bool Traverse_compare_Int    (Int,    Int, void*);
Bool Traverse_compare_Bool   (Bool,   Bool, void*);
Bool Traverse_compare_Float  (Float,  Float, void*);

#define Traverse_compare_Optional_Int(x,y,z) ( x && y && Optional_Int_data (x)==Optional_Int_data (y) )

#define Traverse_compare_Hex(x,y,z) Traverse_compare_Int(x,y,z)
#define Traverse_compare_Oct(x,y,z) Traverse_compare_Int(x,y,z)

/* Basic copy functions for traversals */

List_Int _Traverse_copy_List_Int (List_Int me, void *y);
List_Char _Traverse_copy_List_Char (List_Char me, void *y);
List_Bool _Traverse_copy_List_Bool (List_Bool me, void *y);
List_Ident _Traverse_copy_List_Ident (List_Ident me, void *y);
List_String _Traverse_copy_List_String (List_String me, void *y);

#define Traverse_copy_List_Int(me,y)    ( __must_copy(y) ? _Traverse_copy_List_Int(me,y) : (me) )
#define Traverse_copy_List_Char(me,y)   ( __must_copy(y) ? _Traverse_copy_List_Char(me,y) : (me) )
#define Traverse_copy_List_Bool(me,y)   ( __must_copy(y) ? _Traverse_copy_List_Bool(me,y) : (me) )
#define Traverse_copy_List_Ident(me,y)  ( __must_copy(y) ? _Traverse_copy_List_Ident(me,y) : (me) )
#define Traverse_copy_List_String(me,y) ( __must_copy(y) ? _Traverse_copy_List_String(me,y) : (me) )

#define __must_copy(t) ((t)->clear_back_edges==Just_Copy || (t)->clear_back_edges==Copy_and_Clear)

#define Traverse_copy_Ident(x,y) (x)
#define Traverse_copy_Char(x,y) (x)
#define Traverse_copy_String(x,y)  ( __must_copy(y) ? Front_StrAlloc(x) : (x) )
#define Traverse_copy_Int(x,y) (x)
#define Traverse_copy_Optional_Int(x,y) ( x && __must_copy(y) ? Create_Optional_Int (Optional_Int_data (x)) : x )
#define Traverse_copy_Bool(x,y) (x)
#define Traverse_copy_Float(x,y) (x)
#define Traverse_copy_Oct(x,y) Traverse_copy_Int(x,y)
#define Traverse_copy_Hex(x,y) Traverse_copy_Int(x,y)

/* Basic parse functions */

#define Parse_Ident(x,y)  Encode_Ident(x)
#define Parse_Char(x,y)   Encode_Char(x)
#define Parse_String(x,y) Encode_String(x)
#define Parse_Int(x,y)    Encode_Int(x)
#define Parse_Bool(x,y)   Encode_Bool(x)
#define Parse_Float(x,y)  Encode_Float(x)
#define Parse_Oct(x,y)    Encode_Oct(x)
#define Parse_Hex(x,y)    Encode_Hex(x)

/* Utility function: adds string-quotes */
String Ident_qstring (Ident id);

/* return ME, handy in traversals */
void *Return_Node (void *me);
/* return NULL */
void *Return_NULL (void *me);

#endif /* _basic_types */
