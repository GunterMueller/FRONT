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
#include "flags.h"
#include "GenTypes.h"
#include "GenBdump.h"

static void dump_fields (CreateFunction f)
{
  struct_type t = CreateFunction_type (f);
  List_field l;
  
  for (l = CreateFunction_fields(f); l; l = List_field_next(l)) {
    field g = List_field_data(l);
    TypeName tn = List_TypeName_data(field_type(g));
    Ident tid = TypeName_full(tn);
    EnumType e = find_enumtype(tid);
    struct_type u = find_type(tid);
    
#if 0
    if (field_id(g) == Create_Ident ("src_info")) continue;
#endif

    if (e != NULL) {
      PF ("    bdump_Int (");  
      field_access (t, g, "me"); 
      PF (");\n");
    } else {
      PF ("    bdump_%s (", Ident_name(tid));  
      field_access (t, g, "me"); 
      PF (");\n");
    }    
  }
}

static void read_fields (CreateFunction f)
{
  struct_type t = CreateFunction_type (f);
  List_field l;
  
  for (l = CreateFunction_fields(f); l; l = List_field_next(l)) {
    field g = List_field_data(l);
    TypeName tn = List_TypeName_data(field_type(g));
    Ident tid = TypeName_full(tn);
    EnumType e = find_enumtype(tid);
    struct_type u = find_type(tid);
    
#if 0
    if (field_id(g) == Create_Ident ("src_info")) continue;
#endif

    PF ("    %s %s = ", Ident_name(tid), Ident_name(field_id(g)));
    
    if (e != NULL) {
      PF ("bread_Int ();\n");  
    } else {
      PF ("bread_%s ();\n", Ident_name(tid));  
    }    
  }
}

static void field_args (CreateFunction f)
{
  struct_type t = CreateFunction_type (f);
  List_field l;
  String sep = "";
  
  for (l = CreateFunction_fields(f); l; l = List_field_next(l)) {
    field g = List_field_data(l);
    TypeName tn = List_TypeName_data(field_type(g));
    Ident tid = TypeName_full(tn);
    EnumType e = find_enumtype(tid);
    struct_type u = find_type(tid);
    String fid = Ident_name(field_id(g));
    
#if 0
    if (field_id(g) == Create_Ident ("src_info")) fid = "no_srcinfo";
#endif
    
    PF ("%s%s", sep, fid);
    sep = ", ";
  }
}

/* Generate a dump function per (sub-)type */
static void dump_functions (Types t, Bool pre)
{
  List_StructType types;
  
  for (types = Types_types(t); types; types = List_StructType_next(types)) {
    StructType type = List_StructType_data(types);
    struct_type s = StructType_type (type);
    List_CreateFunction l;
    
    if (Std_type(struct_type_tag(s))) continue;
    
    PF ("static void bdump_%s (%s me)", Type_str(s), Type_str(s));
    
    if (pre) { PF (";\n"); continue; }
    
    PF ("\n{\n");
    PF ("  if (me==NULL) { bdump_Int(-1); return; }\n");
    if (struct_type_sub_types(s)) {
      PF ("  bdump_Int(%s_tag(me));\n", Type_str(s));
      PF ("  switch (%s_tag(me)) {\n", Type_str(s));
    } else {
      PF ("  bdump_Int(0);\n");
      PF ("  {\n");
    }
    for (l = StructType_creates(type); l; l = List_CreateFunction_next(l)) {
      CreateFunction f = List_CreateFunction_data(l);
      struct_type u = CreateFunction_type(f);
      if (struct_type_sub_types(s)) {
        PF ("  case %s_kind:\n", Type_str(u));
      }
      dump_fields (f);
      if (struct_type_sub_types(s)) PF ("    break;\n");
    }
    PF ("  }\n");
    PF ("}\n\n");
  }
}

/* Generate a read function per (sub-)type */
static void read_functions (Types t, Bool pre)
{
  List_StructType types;
  
  for (types = Types_types(t); types; types = List_StructType_next(types)) {
    StructType type = List_StructType_data(types);
    struct_type s = StructType_type (type);
    List_CreateFunction l;

    if (Std_type(struct_type_tag(s))) continue;
    
    PF ("static %s bread_%s (void)", Type_str(s), Type_str(s));
    
    if (pre) { PF (";\n"); continue; }
    
    PF ("\n{\n");
    PF ("  Int tag = bread_Int();\n");
    PF ("  if (tag == -1) return NULL;\n");
    
    if (struct_type_sub_types(s)) {
      PF ("  switch (tag) {\n", Type_str(s));
    } else {
      PF ("  {\n");
    }
    for (l = StructType_creates(type); l; l = List_CreateFunction_next(l)) {
      CreateFunction f = List_CreateFunction_data(l);
      struct_type u = CreateFunction_type(f);
      if (struct_type_sub_types(s)) {
        PF ("  case %s_kind: {\n", Type_str(u));
      }
      read_fields (f);
      PF ("    return Create_%s(", Type_str(u));
      field_args(f);
      PF (");\n");
      if (struct_type_sub_types(s)) PF ("  }\n");
    }
    PF ("  }\n");
    PF ("  return NULL;\n");
    PF ("}\n\n");
  }
}

static void dump_impl (Types t, List_struct_type types)
{
  open_print_file (append_string (Rootstr, "_bdump.c"), TRUE);
  set_margin(0); set_position(0);
  
  print_std_include ("stdio");

  PF ("#include \"%s_bdump.h\"\n",Rootstr);
  print_include ("dump_support");
  PF ("\n");
    
  PF ("#undef no_srcinfo\n\n");
  
  dump_functions (t, TRUE);
  PF ("\n");
  dump_functions (t, FALSE);

  read_functions (t, TRUE);
  PF ("\n");
  read_functions (t, FALSE);

  PF ("void Write_Bdump_%s (%s r, const char *filename)\n", Rootstr, Rootstr);
  PF ("{\n");
  PF ("  dump_file = fopen (filename, \"wb\");\n\n");
  PF ("  bdump_%s(r);\n", abbreviate(Rootstr));
  PF ("  bdump_flush();\n");
  PF ("  fclose (dump_file);\n");
  PF ("}\n\n");
  
  PF ("%s Read_Bdump_%s (const char *filename)\n", Rootstr, Rootstr);
  PF ("{ %s r;\n", Rootstr);
  PF ("  dump_file = fopen (filename, \"rb\");\n\n");
  PF ("  r = bread_%s();\n", abbreviate(Rootstr));
  PF ("  bdump_close();\n");
  PF ("  fclose (dump_file);\n");
  PF ("  return r;\n");
  PF ("}\n\n");

  close_print_file();
}

static void dump_spec (void)
{
  open_print_file (append_string (Rootstr, "_bdump.h"), TRUE);
  set_margin(0); set_position(0);
  
  PF ("#ifndef %s_BDUMP_H\n", Rootstr);
  PF ("#define %s_BDUMP_H\n\n", Rootstr);

  PF ("#include \"%s.h\"\n\n", Rootstr);
  
  PF ("extern void Write_Bdump_%s (%s_%s r, const char *filename);\n\n", Rootstr, Rootstr,  Rootstr);
  PF ("extern %s_%s Read_Bdump_%s (const char *filename);\n\n", Rootstr, Rootstr, Rootstr);

  PF ("#endif /* %s_BDUMP_H */\n", Rootstr);
  close_print_file();
}

/* Generate the traverse table that writes an ast in binary format.
   Also generate the functions that read it back in. 
*/
void GenBdump (Types t, List_struct_type types)
{
  if (!bdump) return;
  dump_spec ();
  dump_impl (t, types);
}
