/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 */
#include "Types_parse.h"

/* TODO:
   Macros to serve as interface between front 1.1 and front 2.0.
   Most of these will disappear when 2.0 is up and running
*/
#if 0
#undef Traverse_List_Ident
#undef Traverse_void_List_Ident
#undef Traverse_copy_List_Ident
#undef Traverse_compare_List_Ident

#ifndef Parse_OPTMOREfield
#define Parse_OPTMOREfield Parse_OPTMORE_field
#endif

#ifndef PlainAlt_def
#define PlainAlt_def(p) LabeledAlt_def(p)
#endif

#ifndef MacroAlt_def
#define MacroAlt_def(p) LabeledAlt_def(p)
#endif

#define front_Traverse_copy_Int(x,y) (x)
#define front_Traverse_copy_Bool(x,y) (x)
#define front_Traverse_copy_Char(x,y) (x)
#define front_Traverse_copy_Float(x,y) (x)
#define front_Traverse_copy_Ident(x,y) (x)
#define front_Traverse_copy_String(x,y) (x)

#define Types_Traverse_copy_Int(x,y) (x)
#define Types_Traverse_copy_Bool(x,y) (x)
#define Types_Traverse_copy_Char(x,y) (x)
#define Types_Traverse_copy_Float(x,y) (x)
#define Types_Traverse_copy_Ident(x,y) (x)
#define Types_Traverse_copy_String(x,y) (x)

#define grammar_Traverse_copy_Int(x,y) (x)
#define grammar_Traverse_copy_Bool(x,y) (x)
#define grammar_Traverse_copy_Char(x,y) (x)
#define grammar_Traverse_copy_Float(x,y) (x)
#define grammar_Traverse_copy_Ident(x,y) (x)
#define grammar_Traverse_copy_String(x,y) (x)

#define front_Traverse_compare_Int(x,y,a) Traverse_compare_Int(x,y,a)
#define front_Traverse_compare_Bool(x,y,a) Traverse_compare_Bool(x,y,a)
#define front_Traverse_compare_Char(x,y,a) Traverse_compare_Char(x,y,a)
#define front_Traverse_compare_Float(x,y,a) Traverse_compare_Float(x,y,a)
#define front_Traverse_compare_Ident(x,y,a) Traverse_compare_Ident(x,y,a)
#define front_Traverse_compare_String(x,y,a) Traverse_compare_String(x,y,a)

#define Types_Traverse_compare_Int(x,y,a) Traverse_compare_Int(x,y,a)
#define Types_Traverse_compare_Bool(x,y,a) Traverse_compare_Bool(x,y,a)
#define Types_Traverse_compare_Char(x,y,a) Traverse_compare_Char(x,y,a)
#define Types_Traverse_compare_Float(x,y,a) Traverse_compare_Float(x,y,a)
#define Types_Traverse_compare_Ident(x,y,a) Traverse_compare_Ident(x,y,a)
#define Types_Traverse_compare_String(x,y,a) Traverse_compare_String(x,y,a)

#define grammar_Traverse_compare_Int(x,y,a) Traverse_compare_Int(x,y,a)
#define grammar_Traverse_compare_Bool(x,y,a) Traverse_compare_Bool(x,y,a)
#define grammar_Traverse_compare_Char(x,y,a) Traverse_compare_Char(x,y,a)
#define grammar_Traverse_compare_Float(x,y,a) Traverse_compare_Float(x,y,a)
#define grammar_Traverse_compare_Ident(x,y,a) Traverse_compare_Ident(x,y,a)
#define grammar_Traverse_compare_String(x,y,a) Traverse_compare_String(x,y,a)
#endif
