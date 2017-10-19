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
#ifndef _parse_support_h
#define _parse_support_h

#include "basic_types.h"
#include "front_list.h"

#ifndef BITSPERBYTE 
#define BITSPERBYTE 8
#endif

#ifndef BITSPERWORD 
#define BITSPERWORD (BITSPERBYTE*sizeof(Int))
#endif

/* The union of all types that can be constructed by the parser */
typedef struct ParseValue {
  union {
    Int		IntValue;
    Hex		HexValue;
    Oct		OctValue;
    Char	CharValue;
    Bool	BoolValue;
    Ident	IdentValue;
    String	StringValue;
    Float	FloatValue;
    Pointer	PointerValue;
  } sub;
  Int first_line;
  String type;
  struct ParseValue *next;
} *ParseValue;

ParseValue PushParseValue (String type);
ParseValue PopParseValue  (String type);
void FreeParseValue (ParseValue p);
Int GetFirstLine (void);

extern ParseValue temp_parse_value;

#define PUSH_PARSEVALUE(T,v,N) \
{ ParseValue me = PushParseValue(#N); \
  me->sub.T##Value = v; \
}

#define POP_PARSEVALUE(T,N) \
  (temp_parse_value = PopParseValue(#N), \
   FreeParseValue (temp_parse_value), \
   temp_parse_value->sub.T##Value)

typedef Int *SymbolSet;

/* a := a | b */
void unite_symbol_sets (SymbolSet x, SymbolSet a, SymbolSet b, Int n);
Bool contains_symbol (SymbolSet a, Int sym, Int n);

#define DELETE_UNTIL(s,T) \
{ while (!contains_symbol(s,_##T##_token,WORDS_IN_SET)) { \
    InputError (SCAN_POSITION, TRUE, "Unexpected symbol"); \
    SHIFT(); \
  } \
}

/* multi-start support */

extern Front_List first_sub_tree;

void Put_sub_trees (int n, va_list p);

void* Get_sub_tree (void);

#endif /* _parse_support_h */
