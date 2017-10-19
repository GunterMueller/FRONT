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
#include <string.h>
#include "GenTypes.h"
#include "GenDoggy.h"
#include "flags.h"

/********** Types *********/

/* Print the Root.types file, containing the doggy Typedefs */
static void print_types (Types types)
{
  List_StructType l;
  List_EnumType m;
  List_BindType b;
  
  open_print_file (append_string (Rootstr, ".types"), TRUE);
  set_margin(0); set_position(0);
  
  PF ("#include \"front/Basic.types\"\n\n");
  
  for (l = Types_types(types); l; l = List_StructType_next(l)) {
    struct_type t = StructType_type(List_StructType_data(l));
    String s = Type_str(t); 
    String n = Type_name(t);
    if (Std_type(struct_type_tag(t))) continue;
    PF ("%s\t\"%s\"\t\"%s\"\t\"NULL\"\n", s, s, n);
  }
  
  for (m = Types_enums(types); m; m = List_EnumType_next(m)) {
    EnumType t = List_EnumType_data(m);
    String s = Ident_name (EnumType_id(t));
    String n = Ident_name (EnumType_name(t));
    List_TypeName tns;
    String e = s;
    if (EnumType_is_tag(t)) continue;
    for (tns = EnumType_enums(t); tns; tns = List_Ident_next(tns)) {
      TypeName tn = List_Ident_data(tns);
      if (tn == NULL || TypeName_id(tn) == Create_Ident("")) continue;
      break;
    }
    if (tns!=NULL) e = Ident_name(TypeName_full (List_Ident_data(tns)));
    PF ("%s\t\"%s\"\t\"%s\"\t\"%s\"\n", s, s, n, e);
  }

  for (b = Types_binds(types); b; b = List_BindType_next(b)) {
    BindType t = List_BindType_data(b);
    String s = append_string ("Bind_", Ident_name (BindType_id1(t)));
    String n = append_string ("Bind_", Ident_name (BindType_abbrev(t)));
    PF ("%s\t\"%s\"\t\"%s\"\t\"%s\"\n", s, s, n, s);
  }

  close_print_file();
}

/********** MD *********/

/* Print md definitions for all types and sub-types types */
static void print_md_types (CreateFunction f)
{
  struct_type t = CreateFunction_type(f);
  struct_type r = Root_type (t);
  List_field l;
  String sep = "";
  List_field fs = CreateFunction_fields(f);
  
  if (!struct_type_is_list(t)) fs = List_field_next(fs);

  PF ("%s (", Type_str(t));
  for (l = fs; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    TypeName tn = List_TypeName_data(field_type(f));
    PF ("%s%s", sep, Ident_name(TypeName_full(tn)));
    sep = ", ";
  }
  PF (") : %s\t\t", Type_str(r));
  PF ("%s_kind\n", Type_str(t));
}

/* Print md definitions for enum types */
static void print_enum_types (EnumType t)
{
  String s = Ident_name (EnumType_str(t));
  List_TypeName tns;
  if (EnumType_is_tag(t)) return;
  for (tns = EnumType_enums(t); tns; tns = List_Ident_next(tns)) {
    TypeName tn = List_TypeName_data(tns);
    String e;
    if (tn == NULL || TypeName_id (tn) == Create_Ident("")) continue;
    e = Ident_name(TypeName_full (tn));
    PF ("%s () : %s\t\t%s\n", e, s, e);
  }
}

/* Print the Root.md file, containing the doggy machine_description */
static void print_md (Types types)
{
  List_StructType l;
  List_EnumType m;
  List_BindType b;

  open_print_file (append_string (Rootstr, ".md"), TRUE);
  set_margin(0); set_position(0);

  PF ("#include \"%s_defs.h\"\n", Rootstr);
  for (l = Types_types(types); l; l = List_StructType_next(l)) {
    StructType t1 = List_StructType_data(l);
    struct_type t = StructType_type(t1);
    List_CreateFunction f;
    if (Std_type(struct_type_tag(t))) continue;
    for (f = StructType_creates(t1); f; f = List_CreateFunction_next(f)) {
      print_md_types (List_CreateFunction_data(f));
    }
  }
  
  for (m = Types_enums(types); m; m = List_EnumType_next(m)) {
    print_enum_types (List_EnumType_data(m));
  }

  for (b = Types_binds(types); b; b = List_BindType_next(b)) {
    BindType t = List_BindType_data(b);
    String s = append_string ("Bind_", Ident_name (BindType_id1(t)));
    PF ("%s () : %s\t\t%s\n", s, s, s);
  }

  close_print_file();
}

/********** API *********/

/* Print the fixed part of the doggy API */
static void api_preamble (void)
{
  PF ("#ifndef CREATE_LIST          \n");
  PF ("#define CREATE_LIST(t,a,b)   (Create_##t((a),(b)))\n");
  PF ("#endif                       \n");
  PF ("#ifndef LIST_HAS_LIST        \n");
  PF ("#define LIST_HAS_LIST(i,l)   ((l) != NULL)\n");
  PF ("#endif                       \n");
  PF ("#ifndef LIST_GET_LIST        \n");
  PF ("#define LIST_GET_LIST(i,l)   ((i)==0?Front_data((Front_List)(l)) : (i)==1 ? Front_next((Front_List)(l)) : NULL)\n");
  PF ("#endif                       \n");
  PF ("#ifndef LIST                 \n");
  PF ("#define LIST                 Front_List\n");
  PF ("#endif                       \n");
  PF ("#ifndef LIST_REPLACE         \n");
  PF ("#define LIST_REPLACE(a,b,i)  (*(a) = *(b))\n");
  PF ("#endif                       \n");
  PF ("#ifndef CONVERT_I_TO_Int     \n");
  PF ("#define CONVERT_I_TO_Int(i)  (i)\n");
  PF ("#endif                       \n");
  PF ("#ifndef CONVERT_Int_TO_I     \n");
  PF ("#define CONVERT_Int_TO_I(i)  (i)\n");
  PF ("#endif                       \n");
  PF ("#ifndef CONVERT_Bool_TO_B    \n");
  PF ("#define CONVERT_Bool_TO_B(i) (i)\n");
  PF ("#endif                       \n");
  PF ("#ifndef CONVERT_B_TO_Bool    \n");
  PF ("#define CONVERT_B_TO_Bool(i) (i)\n");
  PF ("#endif                       \n");
  PF ("#ifndef IS_NULL              \n");
  PF ("#define IS_NULL(i)           ((i) == NULL)\n");
  PF ("#endif                       \n");
  PF ("#ifndef COPY_Ident           \n");
  PF ("#define COPY_Ident(x)        (x)\n");
  PF ("#endif                       \n");
  PF ("#ifndef COPY_Int             \n");
  PF ("#define COPY_Int(x)          (x)\n");
  PF ("#endif                       \n");
  PF ("#ifndef COPY_Bool            \n");
  PF ("#define COPY_Bool(x)         (x)\n");
  PF ("#endif                       \n");
  PF ("#ifndef COPY_Char            \n");
  PF ("#define COPY_Char(x)         (x)\n");
  PF ("#endif                       \n");
  PF ("#ifndef COPY_String          \n");
  PF ("#define COPY_String(x)       (x)\n");
  PF ("#endif                       \n");
  PF ("#ifndef COPY_Float           \n");
  PF ("#define COPY_Float(x)        (x)\n");
  PF ("#endif                       \n");
  PF ("#ifndef COPY_I               \n");
  PF ("#define COPY_I(x)            (x)\n");
  PF ("#endif                       \n");
  PF ("#ifndef COPY_B               \n");
  PF ("#define COPY_B(x)            (x)\n");
  PF ("#endif                       \n");
}

/* Print a type_field ident */
static void print_field (struct_type t, field f)
{
  List_field l;
  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    field g = List_field_data(l);
    if (field_id(g) != field_id(f)) continue;
    PF ("%s_%s", Type_str(t), Ident_name (field_id(f)));
    return;
  }
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    field g = List_field_data(l);
    if (field_id(g) != field_id(f)) continue;
    PF ("%s_%s", Type_str(t), Ident_name (field_id(f)));
    return;
  }
  print_field (Super_type (t), f);
}

/* Print the doggy api for a (sub-)type */
static void print_api_types (CreateFunction f)
{
  struct_type t = CreateFunction_type(f);
  List_field l;
  List_field fs = CreateFunction_fields(f);
  int i;
  String sep = "";
  List_Ident tns = NULL;
  
 /* NEW macro for Create function */
  PF ("#ifndef NEW_%s\n", Type_str(t));
  PF ("#define NEW_%s(", Type_str(t));
  if (struct_type_is_list(t) || struct_type_is_optional(t)) {
    PF ("xxx, ");
  }
  for (l = fs; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    PF ("%s, ", Ident_name(field_id(f)));
  }
  PF ("yyy) ");
  PF ("Create_%s(", Type_str(t));
  if (!struct_type_is_list(t)) {
    fs = List_field_next(fs);
    PF ("NO_SRCINFO");
    sep = ", ";
  }
  for (l = fs; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    PF ("%s%s", sep, Ident_name(field_id(f)));
    sep = ", ";
  }
  PF (")\n");
  PF ("#endif\n\n");
  
  /* Collect types of fields */
  for (l = fs, i=0; l; l = List_field_next(l), i++) {
    field f = List_field_data(l);
    TypeName tn = List_TypeName_data(field_type(f));
    Ident id = TypeName_full(tn);
    insert_id (&tns, id);
  }
  
  /* generate macro for each field type */
  for (; tns; tns = List_Ident_next(tns)) {
    Ident id = List_Ident_data(tns);
    PF ("#define %s_GET_%s(i,me)\t(", Type_str(t), Ident_name(id));
    for (l = fs, i=0; l; l = List_field_next(l), i++) {
      field f = List_field_data(l);
      TypeName tn = List_TypeName_data(field_type(f));
      if (TypeName_full(tn) != id) continue;
      PF ("i == %d ? ", i);
      print_field (t, f);
      PF ("(me) : ");
    }
    PF ("0)\n");
  }
  
  PF ("\n");
}

/* Print access macros for a type s */
static void print_api_type (String s, Bool has_sub, Bool is_enum)
{
  String tag = "tag(a)";
  
  if (!has_sub) tag = "kind";
  
  PF ("#ifndef %s_OPERATOR\n", s);
  PF ("#define %s_OPERATOR(a) ", s);
  if (is_enum) {
    PF ("(a)\n");
  } else {
    PF ("((a)==NULL?(unsigned)~0:%s_%s)\n", s, tag);
  }
  PF ("#endif\n");
  PF ("#ifndef %s_HAS_OPER\n", s);
  PF ("#define %s_HAS_OPER(a,op) ", s);
  if (is_enum) {
    PF ("((a) == op");
  } else {
    PF ("((a) != NULL");
    if (has_sub) PF (" && %s_tag(a) == op", s);
  }
  PF (")\n");
  PF ("#endif\n");
  PF ("#ifndef %s_REPLACE \n", s);
  PF ("#define %s_REPLACE(x,y,i) ", s);
  if (is_enum) {
    PF ("((x) = (y))\n");
  } else {
    PF ("(*(x) = *(y))\n");
  }
  PF ("#endif \n");
  PF ("#ifndef COPY_%s\n", s);
  PF ("#define COPY_%s(x) ", s);
  if (is_enum) {
    PF ("(x)\n");
  } else {
    PF ("Traverse_copy_%s(x, &%s_copy_actions)\n", s, Rootstr);
  }
  PF ("#endif\n\n");
}

/* NEW macro for enum type */
static void print_enum_type (Ident id)
{
  String s;
  if (id==NULL) return;
  s = Ident_name(id);
  if (strlen(s) == 0) return;
  PF ("#ifndef NEW_%s\n", s);                                                                  
  PF ("#define NEW_%s(x,y)\t%s\n", s, s);
  PF ("#endif\n");                                                                                        
}

/* Print the doggy api, Root_doggy.h */
static void print_api (Types types)
{
  List_StructType l;
  List_EnumType m;
  List_BindType b;
  List_TypeName tns;

  open_print_file (append_string (Rootstr, "_doggy.h"), TRUE);
  set_margin(0); set_position(0);

  api_preamble ();
  
  for (l = Types_types(types); l; l = List_StructType_next(l)) {
    StructType t = List_StructType_data(l);
    List_CreateFunction f;
    struct_type type = StructType_type(t);
    print_api_type (Type_str(type), struct_type_sub_types(type) != NULL, FALSE);
    for (f = StructType_creates(t); f; f = List_CreateFunction_next(f)) {
      print_api_types (List_CreateFunction_data(f));
    }
  }
  
  for (m = Types_enums(types); m; m = List_EnumType_next(m)) {
    EnumType t = List_EnumType_data(m);
    print_api_type (Ident_name(EnumType_id(t)), EnumType_enums(t)!=NULL, TRUE);
    for (tns = EnumType_enums(t); tns; tns = List_Ident_next(tns)) {
      Ident id = TypeName_full (List_Ident_data(tns));
      print_enum_type (id);
    }
  }

  for (b = Types_binds(types); b; b = List_BindType_next(b)) {
    BindType t = List_BindType_data(b);
    String s = append_string ("Bind_", Ident_name (BindType_id1(t)));
    print_api_type (s, FALSE, TRUE);
  }

  close_print_file();
}

/*******************/

/* Generate the doggy api */
void GenDoggy (Types types)
{
  if (!doggy) return;
  print_types (types);
  print_md (types);
  print_api (types);
}

