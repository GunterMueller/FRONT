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
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "text.h"
#include "dump_support.h"

FILE *dump_file;

void dump_List_Int (List_Int me)
{ if (me==NULL) return;
  dump_List_Int(List_Int_next(me));
  fprintf (dump_file, "  List_Int dump_0x%x = Create_List_Int(%d, dump_0x%x);\n", 
           (int)me, List_Int_data(me), (int)List_Int_next(me));
}

void dump_List_Oct (List_Oct me)
{ if (me==NULL) return;
  dump_List_Oct(List_Oct_next(me));
  fprintf (dump_file, "  List_Oct dump_0x%x = Create_List_Oct(%d, dump_0x%x);\n", 
           (int)me, List_Oct_data(me), (int)List_Oct_next(me));
}

void dump_List_Hex (List_Hex me)
{ if (me==NULL) return;
  dump_List_Hex(List_Hex_next(me));
  fprintf (dump_file, "  List_Hex dump_0x%x = Create_List_Hex(%d, dump_0x%x);\n", 
           (int)me, List_Hex_data(me), (int)List_Hex_next(me));
}

void dump_List_Bool (List_Bool me)
{ if (me==NULL) return;
  dump_List_Bool(List_Bool_next(me));
  fprintf (dump_file, "  List_Bool dump_0x%x = Create_List_Bool(%d, dump_0x%x);\n", 
           (int)me, List_Bool_data(me), (int)List_Bool_next(me));
}

void dump_List_Char (List_Char me)
{ if (me==NULL) return;
  dump_List_Char(List_Char_next(me));
  fprintf (dump_file, "  List_Char dump_0x%x = Create_List_Char(%d, dump_0x%x);\n", 
           (int)me, List_Char_data(me), (int)List_Char_next(me));
}

void dump_List_String (List_String me)
{ if (me==NULL) return;
  dump_List_String(List_String_next(me));
  fprintf (dump_file, "  List_String dump_0x%x = Create_List_String(\"%s\", dump_0x%x);\n", 
           (int)me, List_String_data(me), (int)List_String_next(me));
}

void dump_List_Ident (List_Ident me)
{ if (me==NULL) return;
  dump_List_Ident(List_Ident_next(me));
  fprintf (dump_file, "  List_Ident dump_0x%x = Create_List_Ident(Create_Ident(\"%s\"), dump_0x%x);\n", 
           (int)me, Ident_name(List_Ident_data(me)), (int)List_Ident_next(me));
}

void dump_Optional_Int (Optional_Int me)
{ if (me==NULL) return;
  fprintf (dump_file, "  Optional_Int dump_0x%x = Create_Optional_Int(%d);\n", 
           (int)me, Optional_Int_data(me));
}

void dump_Optional_Oct (Optional_Oct me)
{ if (me==NULL) return;
  fprintf (dump_file, "  Optional_Oct dump_0x%x = Create_Optional_Oct(%d);\n", 
           (int)me, Optional_Oct_data(me));
}

void dump_Optional_Hex (Optional_Hex me)
{ if (me==NULL) return;
  fprintf (dump_file, "  Optional_Hex dump_0x%x = Create_Optional_Hex(%d);\n", 
           (int)me, Optional_Hex_data(me));
}

void dump_Optional_Bool (Optional_Bool me)
{ if (me==NULL) return;
  fprintf (dump_file, "  Optional_Bool dump_0x%x = Create_Optional_Bool(%d);\n", 
           (int)me, Optional_Bool_data(me));
}

void dump_Optional_Char (Optional_Char me)
{ if (me==NULL) return;
  fprintf (dump_file, "  Optional_Char dump_0x%x = Create_Optional_Char(%d);\n", 
           (int)me, Optional_Char_data(me));
}


/**** Binary dumping *********/

#define BDUMP_SIZE 4096

#define DUMP_MASK 0x12345678

static int bdump_buf[BDUMP_SIZE];
static int dump_ptr = 0;
static int dump_size = 0;

void bdump_SrcInfo (SrcInfo me)
{ bdump_Int (SrcInfo_loc(me));
  bdump_Int (SrcInfo_post_loc(me));
}

void bdump_Int (Int me)
{
#if 0
  printf ("%d\n", me);
#endif
  bdump_buf[dump_ptr++] = me^DUMP_MASK;
  if (dump_ptr >= BDUMP_SIZE) bdump_flush();
}

void bdump_Oct (Oct me)
{ bdump_Int (me);
}

void bdump_Hex (Hex me)
{ bdump_Int (me);
}

void bdump_Bool (Bool me)
{ bdump_Int (me);
}

void bdump_Char (Char me)
{ bdump_Int (me);
}

#define MAX_STRING_SIZE 1024*16

void bdump_String (String me)
{
  int l;
  int i;
  static Int s[MAX_STRING_SIZE];

  if (me==NULL) { bdump_Int(-1); return; }
  bdump_Int(0);
  
  l = strlen(me)+1;
  l += sizeof(Int)-1;
  l /= sizeof(Int); 
  strcpy ((char*)s, me);
  
  for (i = 0; i < l; i++) bdump_Int(s[i]);
}

void bdump_Float (Float me)
{ union {
    Float f;
    Int a[sizeof(Float)/sizeof(Int)];
  } u;
  unsigned i;
  u.f = me;
  for (i = 0; i < sizeof (u.a) / sizeof(Int); i++) bdump_Int (u.a[i]);
}

void bdump_Ident (Ident me)
{ 
  if (me==NULL) { bdump_Int(-1); return; }
  bdump_Int(0);
  
  bdump_String (Ident_name(me));
}

void bdump_List (void *me, void *f)
{
  Front_List l = me;
  void (*g) (Pointer) = f;

  if (l==NULL) { bdump_Int(-1); return; }
  bdump_Int(0);
  g (Front_List_data(l));
  bdump_List (Front_List_next(l), f);
}

void bdump_Optional (void *me, void *f)
{
  Front_Optional l = me;
  void (*g) (Pointer) = f;
  if (l==NULL) { bdump_Int(-1); return; }
  bdump_Int(0);
  g (Front_Optional_data(l));
}

void bdump_flush (void)
{
  write (fileno(dump_file), bdump_buf, dump_ptr*sizeof(*bdump_buf));
  dump_ptr = 0;
}

/****************************************************/

SrcInfo bread_SrcInfo (void)
{ Int loc  = bread_Int ();
  Int post = bread_Int ();
  return make_post_src_info(loc, post);
}

Int bread_Int (void)
{
  int r;
  if (dump_ptr >= BDUMP_SIZE) dump_size = 0;
  if (dump_size==0) {
    dump_size = read (fileno(dump_file), bdump_buf,  sizeof(bdump_buf));
    dump_ptr = 0;
  }
  if (dump_size==0) return 0;
  r = bdump_buf[dump_ptr++]^DUMP_MASK;
#if 0
  printf ("%d\n", r);
#endif
  return r;
}

Oct bread_Oct (void)
{ return bread_Int();
}

Hex bread_Hex (void)
{ return bread_Int();
}

Bool bread_Bool (void)
{ return bread_Int();
}

Char bread_Char (void)
{ return bread_Int();
}

String bread_String (void)
{ 
  int i = bread_Int();
  static Int s[MAX_STRING_SIZE];
  static char t[sizeof(Int)+1];

  if (i==-1) return NULL;

  i = 0;
  
  do {
    s[i] = bread_Int();
    strncpy (t, (char*)&s[i], sizeof(Int));
    if (strlen(t) < sizeof(Int)) break;
    i++;
  } while (TRUE);
  return fe_strdup ((char*)s);
}

Float bread_Float (void)
{ union {
    Float f;
    Int a[sizeof(Float)/sizeof(Int)];
  } u;
  unsigned i;
  for (i = 0; i < sizeof (u.a) / sizeof(Int); i++) u.a[i] = bread_Int ();
  return u.f;
}

Ident bread_Ident (void)
{ 
  int i = bread_Int();
  if (i==-1) return NULL;

  return Create_Ident (bread_String());
}

void *bread_List (void *(*f)(void))
{
  int i = bread_Int();
  Pointer data = f ();
  Front_List next = bread_List (f);
  if (i==-1) return NULL;
  return Create_Front_List(data, next);
}

void  *bread_Optional (void *(*f)(void))
{
  int i = bread_Int();
  Pointer data = f ();
  if (i==-1) return NULL;
  return Create_Front_Optional(data);
}

void bdump_close (void)
{ dump_size = 0;
  dump_ptr = 0;
}
