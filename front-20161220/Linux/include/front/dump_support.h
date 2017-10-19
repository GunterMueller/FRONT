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
#ifndef _dump_support
#define _dump_support

#include <stdio.h>
#include "front_list.h"
#include "print_support.h"

FILE *dump_file;

/******************** Dump functions ************/

void dump_List_Int    (List_Int me);
void dump_List_Oct    (List_Oct me);
void dump_List_Hex    (List_Hex me);
void dump_List_Bool   (List_Bool me);
void dump_List_Char   (List_Char me);
void dump_List_String (List_String me);
void dump_List_Ident  (List_Ident me);

void dump_Optional_Int  (Optional_Int me);
void dump_Optional_Oct  (Optional_Oct me);
void dump_Optional_Hex  (Optional_Hex me);
void dump_Optional_Bool (Optional_Bool me);
void dump_Optional_Char (Optional_Char me);

/******************** Binary dump functions ************/

void bdump_SrcInfo  (SrcInfo me);
void bdump_Int      (Int me);
void bdump_Oct      (Oct me);
void bdump_Hex      (Hex me);
void bdump_Bool     (Bool me);
void bdump_Char     (Char me);
void bdump_String   (String me);
void bdump_Float    (Float me);
void bdump_Ident    (Ident me);
void bdump_List     (void *l, void *f);
void bdump_Optional (void *l, void *f);

#define bdump_List_Int(me)    bdump_List(me, bdump_Int)
#define bdump_List_Oct(me)    bdump_List(me, bdump_Oct)
#define bdump_List_Hex(me)    bdump_List(me, bdump_Hex)
#define bdump_List_Bool(me)   bdump_List(me, bdump_Bool)
#define bdump_List_Char(me)   bdump_List(me, bdump_Char)
#define bdump_List_String(me) bdump_List(me, bdump_String)
#define bdump_List_Ident(me)  bdump_List(me, bdump_Ident)

#define bdump_Optional_Int(me)  bdump_Optional(me, bdump_Int)
#define bdump_Optional_Oct(me)  bdump_Optional(me, bdump_Oct)
#define bdump_Optional_Hex(me)  bdump_Optional(me, bdump_Hex)
#define bdump_Optional_Bool(me) bdump_Optional(me, bdump_Bool)
#define bdump_Optional_Char(me) bdump_Optional(me, bdump_Char)

void bdump_flush    (void);

/**********/

SrcInfo bread_SrcInfo  (void);
Int     bread_Int      (void);
Oct     bread_Oct      (void);
Hex     bread_Hex      (void);
Bool    bread_Bool     (void);
Char    bread_Char     (void);
String  bread_String   (void);
Float   bread_Float    (void);
Ident   bread_Ident    (void);
void   *bread_List     (void *(*f)(void));
void   *bread_Optional (void *(*f)(void));

#define bread_List_Int()    bread_List((void*(*)(void))bread_Int)
#define bread_List_Oct()    bread_List((void*(*)(void))bread_Oct)
#define bread_List_Hex()    bread_List((void*(*)(void))bread_Hex)
#define bread_List_Bool()   bread_List((void*(*)(void))bread_Bool)
#define bread_List_Char()   bread_List((void*(*)(void))bread_Char)
#define bread_List_String() bread_List((void*(*)(void))bread_String)
#define bread_List_Ident()  bread_List((void*(*)(void))bread_Ident)

#define bread_Optional_Int()  bread_Optional((void*(*)(void))bread_Int)
#define bread_Optional_Oct()  bread_Optional((void*(*)(void))bread_Oct)
#define bread_Optional_Hex()  bread_Optional((void*(*)(void))bread_Hex)
#define bread_Optional_Bool() bread_Optional((void*(*)(void))bread_Bool)
#define bread_Optional_Char() bread_Optional((void*(*)(void))bread_Char)

void   bdump_close    (void);

#endif /* _dump_support */
