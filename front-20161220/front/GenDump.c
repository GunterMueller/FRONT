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
#include <assert.h>
#include "flags.h"
#include "GenTypes.h"
#include "GenDump.h"

/* Generate the Root_dump.h file */
static void dump_spec (void)
{
  open_print_file (append_string (Rootstr, "_dump.h"), TRUE);
  set_margin(0); set_position(0);
  
  PF ("#ifndef %s_DUMP_H\n", Rootstr);
  PF ("#define %s_DUMP_H\n\n", Rootstr);

  PF ("#include \"%s.h\"\n\n", Rootstr);
  
  PF ("extern void Dump_%s (%s r, FILE *fs, char *name, char *incpath);\n\n", Rootstr, Rootstr);

  PF ("#endif /* %s_DUMP_H */\n", Rootstr);
  close_print_file();
}

/* Return the printf the format for a std type */
static String print_format (Ident id)
{
  if (id == Create_Ident ("Int")) return "%d";
  if (id == Create_Ident ("Hex")) return "%d";
  if (id == Create_Ident ("Oct")) return "%d";
  if (id == Create_Ident ("Bool")) return "%d";
  if (id == Create_Ident ("String")) return "\\\"%s\\\"";
  if (id == Create_Ident ("Char")) return "\\\'%c\\\'";
  if (id == Create_Ident ("Float")) return "%g";
  if (id == Create_Ident ("Ident")) return "Create_Ident(\\\"%s\\\")";
   return "";
}

/* Generate the formats for arguments of CreateFunction f */
static void print_formats (CreateFunction f, String sep)
{
  List_field l;
  
  for (l = CreateFunction_fields(f); l; l = List_field_next(l)) {
    field g = List_field_data(l);
    TypeName tn = List_TypeName_data(field_type(g));
    Ident tid = TypeName_full(tn);
    EnumType e = find_enumtype(tid);
    
    if (field_id(g) == Create_Ident ("src_info")) continue;
    
    if (e != NULL) {
      if (!enum_is_int(e)) {
        PF ("%s%%s", sep);
      } else {
        PF ("%s%%d", sep);
      }
    } else if (TermType(tid)) {
      PF ("%s%s", sep, print_format (tid));
    } else {
      assert (Allows_nil(tn));
      PF ("%sdump_0x%%0X/*%s*/", sep, Ident_name(tid));
    }
    sep = ", ";
  }
}

/* Generate the arguments of CreateFunction f */
static void print_pre_dumps (CreateFunction f)
{
  struct_type t = CreateFunction_type (f);
  List_field l;
  
  for (l = CreateFunction_fields(f); l; l = List_field_next(l)) {
    field g = List_field_data(l);
    TypeName tn = List_TypeName_data(field_type(g));
    Ident tid = TypeName_full(tn);
    String s = Ident_name(tid);
    EnumType e = find_enumtype(tid);
        
    if (e == NULL && Std_type(tid)) {
      PF ("  dump_%s (", s); field_access (t, g, "me"); PF (");\n");
    }    
  }
}

/* Generate the arguments of CreateFunction f */
static void print_args (CreateFunction f, String sep)
{
  struct_type t = CreateFunction_type (f);
  List_field l;
  
  for (l = CreateFunction_fields(f); l; l = List_field_next(l)) {
    field g = List_field_data(l);
    TypeName tn = List_TypeName_data(field_type(g));
    Ident tid = TypeName_full(tn);
    EnumType e = find_enumtype(tid);
    
    if (field_id(g) == Create_Ident ("src_info")) continue;
    
    if (e != NULL) {
      if (!enum_is_int(e)) {
        PF ("%s%s_names[", sep, Ident_name(tid));  
        field_access (t, g, "me"); 
        PF ("]");
      } else {
        PF ("%s", sep);  
        field_access (t, g, "me"); 
      }
    } else if (TermType(tid)) {
      PF ("%s", sep);
      if (tid == Create_Ident ("Ident")) {
	PF ("Ident_name("); field_access (t, g, "me"); PF (")");
      } else {
	field_access (t, g, "me"); 
      }
    } else {
      assert (Allows_nil(tn)); 
      PF ("%s(int)", sep); field_access (t, g, "me"); 
    }    
    sep = ", ";
  }
}

/* Generate a dump function per (sub-)type */
static void dump_functions (Types t)
{
  List_StructType types;
  
  for (types = Types_types(t); types; types = List_StructType_next(types)) {
    StructType type = List_StructType_data(types);
    List_CreateFunction l;
    for (l = StructType_creates(type); l; l = List_CreateFunction_next(l)) {
      CreateFunction f = List_CreateFunction_data(l);
      struct_type s = CreateFunction_type (f);
      struct_type r = Root_type (s);
      String si = Front_StrAllocf("make_src_info(%%d)");
      String loc = Front_StrAllocf("%s_loc(me)", Type_str(r));
      String sep = ", ";
      if (struct_type_is_list(r)) {
        si = "";
	loc = "";
	sep = "";
      } else if (!contains_field (r, Create_Ident("src_info"))) {
	  loc = "0";
      }
      
      PF ("static void decl_%s (%s me)\n", Type_name(s), Type_str(s));
      PF ("{\n");
      PF ("  if (me==NULL) return;\n");
      print_pre_dumps (f);
      PF ("  fprintf (dump_file, \"  static %s dump_0x%%0X", Type_str(s));
      PF (";\\n\", (int)me);\n");
      PF ("}\n\n");

      PF ("static void dump_%s (%s me)\n", Type_name(s), Type_str(s));
      PF ("{\n");
      PF ("  if (me==NULL) return;\n");
      print_pre_dumps (f);
      PF ("  fprintf (dump_file, \"  dump_0x%%0X = Create_%s(%s", Type_str(s), si);
      print_formats (f, sep);
      PF (");\\n\", (int)me, %s", loc);
      print_args (f, sep);
      PF (");\n");
      PF ("}\n\n");
    }
  }
}

/* Generate a traverse table containing the dump-functions */
static void init_table (Types t)
{
  List_StructType types;
  
  for (types = Types_types(t); types; types = List_StructType_next(types)) {
    StructType type = List_StructType_data(types);
    Ident tid = struct_type_name(StructType_type(type));
    List_CreateFunction l;
#if 0
    if (Std_type (tid)) {
      String s = Ident_name (tid);
      if (tid==Create_Ident("List_Bind")) continue;
      PF ("  dump_table.action_%s[POST_ACTION] = dump_%s;\n", s, s);
    }
#endif
    for (l = StructType_creates(type); l;l = List_CreateFunction_next(l)) {
      CreateFunction f = List_CreateFunction_data(l);
      String s = Type_name(CreateFunction_type (f));
      PF ("  decl_table.action_%s[POST_ACTION] = decl_%s;\n", s, s);
    }
    for (l = StructType_creates(type); l;l = List_CreateFunction_next(l)) {
      CreateFunction f = List_CreateFunction_data(l);
      String s = Type_name(CreateFunction_type (f));
      PF ("  dump_table.action_%s[POST_ACTION] = dump_%s;\n", s, s);
    }
  }
}

/* Generate the Root_dump.c file */
static void dump_impl (Types t)
{
  open_print_file (append_string (Rootstr, "_dump.c"), TRUE);
  set_margin(0); set_position(0);
  
  print_std_include ("stdio");
  print_include ("dump_support");
  PF ("#include \"%s_dump.h\"\n",Rootstr);
  
  PF ("static struct s_void_%s_TraverseTable decl_table;\n\n", Rootstr);
  PF ("static struct s_void_%s_TraverseTable dump_table;\n\n", Rootstr);
 
  dump_functions (t);
  
  PF ("void Dump_%s (%s r, FILE *fs, char *name, char *incpath)\n", Rootstr, Rootstr);
  PF ("{\n");
  
  init_table (t);
  PF ("\n");
  PF ("  dump_file = fs;\n\n");
  PF ("  if (incpath)\n");
  PF ("    fprintf (dump_file, \"#include \\\"%%s/%s.h\\\"\\n\\n\", incpath);\n", Rootstr);
  PF ("  else\n");
  PF ("    fprintf (dump_file, \"#include \\\"%s.h\\\"\\n\\n\");\n", Rootstr);
  PF ("  fprintf (dump_file, \"%s Recreate_%%s (void)\\n\", name);\n", Rootstr, Rootstr);
  PF ("  fprintf (dump_file, \"{\\n\");\n");
  PF ("  fprintf (dump_file, \"  void *dump_0x%%0X = NULL;\\n\",(int) NULL);\n");
  PF ("  Traverse_void_%s_%s (r, &decl_table);\n", Rootstr, Rootstr);
  PF ("  Traverse_void_%s_%s (r, &dump_table);\n", Rootstr, Rootstr);
  PF ("  fprintf (dump_file, \"  return dump_0x%%0X;\\n\", r);\n");
  PF ("  fprintf (dump_file, \"}\\n\");\n");
  PF ("  fclose (dump_file);\n");
  PF ("}\n");
  close_print_file();
}
  
/* Generate the Root_dump module that dumps an ast 
   in the form of a C function that cab re-create it 
*/
void GenDump (Types t)
{
  if (!gendump) return;
  dump_spec ();
  dump_impl (t);
}
