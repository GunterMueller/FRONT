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
#include "print_types.h"
#include "frontPrint.h"
#include "TypesPrint.h"
#include "GenTypes.h"
#include "GenGrammar.h"
#include "flags.h"

/* Different kind of traversals */
typedef enum {
  TravPlain,
  TravVoid,
  TravCopy,
  TravCompare
} TravType;

/* Prefixes of traversals */
static String TravName[] = { "", "void_", "copy_", "compare_" };

static List_EnumType All_Enums;	/* All enum types */
static String indent = "";	/* Current indentation */

static void memo_access (struct_type t, Bool impl);

/****************/

static char *
action_skip_children (struct_type t, Bool neg)
{
  char *bang[]={"","!"};
  if (is_skip(t)) {
    return Front_StrAllocf ("%saction->trav_children_%s",
                            bang[!neg], Type_name(t));
  } else {
    return Front_StrAllocf ("%saction->skip_children_%s",
                            bang[neg], Type_name(t));
  }
}

/* Generate the field declaration in a traverse table for type t, sub-type s, kind k */
static void trav_field (String t, String r, TravType k, Bool skip)
{
  if (strlen(t) == 0) return;
  switch (k) {
    case TravPlain:
      PF ("  Pointer (*action_%s[2]) (%s, Pointer);\n", t, r);
      break;
    case TravVoid:
      PF ("  void (*action_%s[2]) (%s);\n", t, r);
      break;
    case TravCopy:
      PF ("  %s (*action_%s[2]) (%s, %s);\n", r, t, r, r);
      break;
    case TravCompare:
      PF ("  int (*action_%s[2]) (%s, %s);\n", t, r, r);
      break;
  }
  if (skip) {
    PF ("  Bool trav_children_%s;\n", t);
  } else {
    PF ("  Bool skip_children_%s;\n", t);
  }
}

/* Generate the field declarations in a traverse table for all (sub-)types for kind k */
static void trav_fields (List_struct_type types, TravType k)
{
  struct_type t;
  if (types==NULL) return;
  t = List_struct_type_data (types);
  if(!Std_type(struct_type_tag(t))) {
    trav_field (Type_name(t), Type_str(t), k, is_skip(t));
  }
  if (struct_type_sub_types(t) != NULL) {
    trav_fields (struct_type_sub_types(t), k);
  }
  trav_fields (List_struct_type_next(types), k);
}

/* Generate the field declarations in a traverse table for all enum-types for kind k */
static void enum_trav_fields (List_EnumType types, TravType k)
{
  EnumType t;
  List_TypeName l;
  String tid, aid;
  
  if (types==NULL) return;
  t = List_EnumType_data (types);
  if (!EnumType_is_tag(t)/* && !enum_is_int(t)*/) {
    aid = Ident_name(EnumType_name(t));
    tid = Ident_name(EnumType_id(t));
    if(!Std_type(EnumType_id(t))) trav_field (aid, tid, k, FALSE);

    for (l = EnumType_enums(t); l; l = List_Ident_next(l)) {
      TypeName tn = List_TypeName_data(l);
      if(!Std_type(TypeName_full(tn))) trav_field (Ident_name(TypeName_id(tn)), tid, k, FALSE);
    }
  }
  enum_trav_fields (List_EnumType_next(types), k);
}

/* Generate the header declarations for the traverse function for all types in
   types, enums and kind k.
*/
static void trav_funcs (List_struct_type types, List_EnumType enums, TravType k)
{
  String id, name;
  Bool skip = FALSE;
  
  if (enums==NULL && types==NULL) return;
  if (types==NULL) return;
  
  if (enums != NULL) {
    EnumType t = List_EnumType_data(enums);
    skip |= EnumType_is_tag(t);
    id = Ident_name (EnumType_id(t));
    name = Ident_name (EnumType_name(t));
  } else {
    struct_type t = List_struct_type_data(types);
    id = Type_str(t);
    name = Type_name(t);
  }
  skip |= Std_type(Create_Ident(id));
  if (!skip) {
    char *table = abbreviatef(TravName[k], "TraverseTable", "");
    char *trav = def_abbrevf("Traverse_%s", name, id, "", TravName[k]);
    switch (k) {
      case TravPlain:
        PF ("extern Pointer %s (%s me, %s table, Pointer val);\n",
            trav, id, table);
        break;
      case TravVoid:
        PF ("extern void %s (%s me, %s table);\n",
            trav, id, table);
        break;
      case TravCopy:
        PF ("extern %s %s (%s me, %s table);\n",
            id, trav, id, table);
        PF ("#ifndef %s\n", abbreviatef ("COPY_", name, ""));
        PF ("#define %s(x) %s(x, &%s)\n",
            abbreviatef ("COPY_", name, ""), trav,
            abbreviate ("copy_actions"));
        PF ("#endif\n");
        break;
      case TravCompare:
        PF ("extern int %s (%s x, %s y, %s table);\n",
           trav, id, id, table);
        break;
    }
  }
  if (enums==NULL) trav_funcs (List_struct_type_next(types), enums, k);
  else trav_funcs (types, List_EnumType_next(enums), k);
}

/* Generate traverse abbreviation macro for type id and traverse kind k */
static void std_trav_macro (String id, TravType k)
{
  String k1 = TravName[k];
  
  if (prefix!=NULL) return;
  
  Abbrev ("#define Traverse_%s%s Traverse_%s%s\n", k1, prefix_string(id), k1, id);
}

/* Generate the traversals for all types+enums, kind k.
   This consists of, for kind k:
    - the traverse table typedef
    - the traverse function headers
    - an abbreviation macro for each traverse function
    - abbreviation macro's for the standard traverse function
*/
static void print_trav (List_struct_type types, List_EnumType enums, TravType k)
{ String kind = TravName[k];
  
  PF ("typedef struct %s {\n", abbreviatef("s_%s", "TraverseTable", "", kind));
  if (k==TravPlain) PF ("  Front_Traversal traversal;\n");
  if (k==TravCopy)  PF ("  Front_ClearBackEdges clear_back_edges;\n");
  trav_fields (types, k);
  enum_trav_fields (enums, k);
  PF ("} *%s;\n\n", abbreviatef("%s", "TraverseTable", "", kind));
  trav_funcs  (types, enums, k); PF ("\n");
  std_trav_macro ("Int", k);
  std_trav_macro ("Oct", k);
  std_trav_macro ("Hex", k);
  std_trav_macro ("Bool", k);
  std_trav_macro ("Char", k);
  std_trav_macro ("String", k);
  std_trav_macro ("Ident", k);
  std_trav_macro ("Float", k);
}

/* Generate a standard traverse table variable with name 'name' and kind k */
static void standard_table (String name, TravType k)
{
  PF ("extern struct %s %s;\n\n", 
      abbreviatef("s_%s","TraverseTable","",TravName[k]),
      abbreviatef("",name,"_actions"));
}

/* Generate the standard traverse tables */
static void standard_tables (void)
{
  standard_table ("scope",    TravPlain);
  standard_table ("defining", TravVoid);
  standard_table ("applied",  TravVoid);
  standard_table ("check",    TravVoid);
  standard_table ("print",    TravVoid);
  standard_table ("copy",     TravCopy);
  standard_table ("compare",  TravCompare);
}

/* Generate a function prototype for a table fill function for type k */
static void fill_table_def (TravType k)
{
  String k1 = TravName[k];
  PF ("extern void %s (%s t,"
      "void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));\n",
      abbreviatef(k1, "fill_table", ""),
      abbreviatef(k1, "TraverseTable", ""));
}

/* Generate all traversal declarations for all types, enums and traversal kinds */
static void print_traversals (List_struct_type types, List_EnumType enums)
{ PF ("#define PRE_ACTION  1\n");
  PF ("#define POST_ACTION 0\n\n");

  print_trav (types, enums, TravPlain);
  print_trav (types, enums, TravVoid);
  print_trav (types, enums, TravCopy);
  print_trav (types, enums, TravCompare);
  PF ("\n");
   
  fill_table_def (TravPlain);
  fill_table_def (TravVoid);
  fill_table_def (TravCopy);
  fill_table_def (TravCompare);
	 
  standard_tables ();
}

/*********/

/* Generate the NameSpace type */
static void print_name_spaces (List_NameSpace l)
{ 
  int n;
  int i;
  String def = "DefaultNameSpace";
  String namespaces, NameSpaces;
  
  l = Create_List_NameSpace (Create_NameSpace(no_srcinfo, Create_Ident(def)), l);
  
  n = List_NameSpace_size(l);
  NameSpaces = abbreviate ("NameSpaces");
  namespaces = abbreviate ("namespaces");
    
  PF ("typedef int %s;\n\n", NameSpaces);
  PF ("extern %s %s[%d];\n\n",
      NameSpaces, namespaces, n);

  for (i=0; l; l = List_NameSpace_next(l), i++) {
    NameSpace ns = List_NameSpace_data(l);
    String id = Ident_name (NameSpace_id(ns));
    PF ("#define %s %s[%d]\n",
        abbreviate(id),
        namespaces, i);
  }
  PF ("\n");
  PF ("#define %s %d\n\n", abbreviate("NUM_NAMESPACES"), n);
}

/* print a function header for a create function */
static void print_create_header (CreateFunction f)
{
  struct_type t = CreateFunction_type (f);
  String s = Type_str(t);
  List_field l;
  String sep = "";
  
  PF ("%s %s\t(", Type_str(t), def_abbrevf ("Create_",Type_name(t),s,""));
  for (l = CreateFunction_fields(f); l; l = List_field_next(l)) {
     field g = List_field_data(l);
     TypeName tn = List_TypeName_data(field_type(g));
     PF ("%s%s %s", sep, 
         Ident_name(TypeName_full(tn)), 
         Ident_name(field_id(g)));
     sep = ", ";
  }
  PF (")");
}

/* Print a declaration for a create function.
   In case of a list types, this becomes a macro.
*/
static void print_createfunction (CreateFunction f)
{ struct_type t = CreateFunction_type (f);
  String s = Type_str(t);
  
  if (struct_type_is_list(t)) {
    PF ("#ifndef Create_%s\n", s);
    PF ("#define %s(x,y)", def_abbrevf ("Create_",Type_name(t),s,""));
    PF (" (%s)Create_Front_List((void*)(x),(Front_List)(y))\n", s);
    PF ("#endif\n\n");
    PF ("#define %s(l) List_size((Front_List)l)\n\n",
        def_abbrevf ("",Type_name(t),s, "_size"));
  } else {
     if (is_memo(t)) memo_access (t, FALSE);
     PF ("extern "); print_create_header(f); PF (";\n");
  }
}

/* Print the declaration of an enum types.
   This can deteriate into a Bool or an Int type.
*/
static void print_enumtype (EnumType t)
{
  if (enum_is_bool(t)) {
    PF ("typedef Bool %s;\n\n", Ident_name(EnumType_id(t)));
  } else if (enum_is_int(t)) {
    PF ("typedef Int %s;\n\n", Ident_name(EnumType_id(t)));
  } else {
    Print_EnumType(t);
  }
}

/* Print a struct type */
static void print_structtype (StructType t)
{
  if (struct_type_in_lib(StructType_type(t))) return;
  Print_StructType (t);
}

/* Print a fields declaration */
static void print_field (field f)
{
  Ident t = TypeName_id (List_TypeName_data(field_type(f)));
  if (t == Create_Ident("VOID")) return;
  Print_field(f);
}

/**************/

/* Generate the Root.h file */
static void print_types_def (front f, Types types_root, List_struct_type types)
{
  Types_print_actions.action_CreateFunction[PRE_ACTION] = print_createfunction;
  Types_print_actions.action_EnumType[PRE_ACTION] = print_enumtype;
  Types_print_actions.action_StructType[PRE_ACTION] = print_structtype;
  Types_print_actions.action_field[PRE_ACTION] = print_field;
  
  open_print_file (append_string (Rootstr, ".h"), TRUE);
  set_margin(0); set_position(0);
  PF ("#ifndef _%s\n", Ident_name (Rootid));
  PF ("#define _%s\n\n", Ident_name (Rootid));
                
  Print_Types (types_root);
  print_traversals (types, Types_enums(types_root));
  print_name_spaces (front_namespaces(f));

  PF ("extern void Decorate_%s (%s r);\n\n", Rootstr, prefix_string(Rootstr));

  PF ("#endif /* _%s */\n", Ident_name (Rootid));
  
  close_print_file();
}

/**************/

/* Map NIL onto NULL for backward compatability */
static String map_expr (String e)
{
  if (strcmp(e, "NIL")==0) return "NULL";
  return e;
}

/* Print the table containing the names for the members of the enum types in l */
static void print_enum_names (List_EnumType l)
{ EnumType t;
  List_TypeName m;
  String id, full;
  
  if (l==NULL) return;
  t = List_EnumType_data(l);
  
  if (!enum_is_int(t)) {
    id = Ident_name (EnumType_name(t));
    full = Ident_name (EnumType_str(t));
    PF ("String %s[] = {\n", def_abbrevf("", id, full, "_names"));
    for (m = EnumType_enums(t); m; m = List_Ident_next(m)) {
      TypeName tn = List_TypeName_data(m);
      PF ("  \"%s\",\n", Ident_name(TypeName_id(tn)));
    }
    PF ("};\n\n");
  }
  print_enum_names (List_EnumType_next(l));
}

/* Generate the field intialization within a create function for type u.
   It generates these intializations for the fields the super types of u, from r up.
   'expr' indicates whether fields with or without an expression must be intialized.
   'pre' indicates whether the super type fields must be before or after the sub-type fields. 
*/
static void print_field_init (field f, struct_type t, struct_type u, Bool expr, FieldInit init)
{
  String e;
  String id = Ident_name(field_id(f));
  Ident t1 = glue_type (field_type(f));
  
  if (expr) {
    if (!init) return;
    e = map_expr (Text_Expr(FieldInit_expr(init)));
  } else {
    if (init) return;
    if (t1 == Create_Ident("VOID")) return;
    e = id;
  }
  if (field_is_tag(f)) e = append_string (Type_str(u), "_kind");
  if (t1 == Create_Ident("VOID")) {
    PF ("  %s;\n", e);
  } else {
    PF ("  %s_%s(me) = %s;\n", Type_str(t), id, e);
  }
}

static void 
gen_field_init (struct_type t, field f, FieldInit_tag when, Bool *done, 
                void (*header)(struct_type, Bool*))
{
  FieldInit i = field_init_when(f, when);
  if (!i) return;
  
  header (t, done);  
  print_field_init (f, t, t, TRUE, i);
}


/* Generate the field intialization within a create function for type u.
   It generates these intializations for the fields the super types of u, from r up.
   'expr' indicates whether fields with or without an expression must be intialized.
   'pre' indicates whether the super type fields must be before or after the sub-type fields. 
*/
static void print_field_inits (struct_type t, struct_type u, Bool expr, Bool pre, FieldInit_tag when)
{
  struct_type r = Super_type(t);
  List_field l;
  
  if (pre && r != t) print_field_inits (r, u, expr, pre, when);
  
  if (pre) l = struct_type_fields1(t);
  else     l = struct_type_fields2(t);
  
  for (; l; l = List_field_next(l)) {
    print_field_init (List_field_data(l), t, u, expr, field_init_when(List_field_data(l), when));
  }

  if (!pre && r != t) print_field_inits (r, u, expr, pre, when);
}

static Int memo_size = 1024;	/* Size of memo table */

/* Generate a test for the existence of an object in the memo table */
static void memo_test (struct_type t, struct_type u, Bool pre, Bool val)
{
  struct_type r = Super_type(t);
  List_field l;
  
  if (pre && r != t) memo_test (r, u, pre, val);
  
  if (pre) l = struct_type_fields1(t);
  else     l = struct_type_fields2(t);
  
  for (; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    String id = Ident_name(field_id(f));
    String e  = id;
    if (field_id(f) == Create_Ident("src_info")) continue;
    if (field_is_tag(f)) e = append_string (Type_str(u), "_kind");
    if (!field_is_tag(f) && field_init(f) != NULL) continue;
    if (val) {
      if (field_is_tag(f)) continue;
      PF ("+(unsigned int)%s", id);
      continue;
    }
    if (field_compare(f) != NULL) {
      PF ("      { int _compare = %s (", Ident_name(field_compare(f))); 
                      field_access (t, f, "*_qqqq"); PF (", %s);\n", e);
      PF ("        if (_compare < 0) continue;\n");
      PF ("        if (_compare > 0) break;\n");
      PF ("      }\n");
    } else {
      PF ("      if ("); field_access (t, f, "*_qqqq"); PF (" > %s) break;\n", e);
      PF ("      if ("); field_access (t, f, "*_qqqq"); PF (" < %s) continue;\n", e);
    }
  }

  if (!pre && r != t) memo_test (r, u, pre, val);
}

/* Find an object in the memo table */
static void memoize (struct_type t)
{
  String r = Type_str(Root_type(t));
  String s = Type_str(t);
  
  PF ("  {\n", r, s);
  PF ("    unsigned int _hash = (0");
    memo_test(t, t, TRUE,  TRUE);
    memo_test(t, t, FALSE, TRUE);
  PF (")/sizeof(int*) %% %d;\n", memo_size);
  PF ("    %s *_qqqq;\n", r);
  PF ("    if (%s_memo_table==NULL)\n", s);
  PF ("    { int i;\n");
  PF ("      %s_memo_table = (%s*)fe_malloc (sizeof(*%s_memo_table)*%d);\n", s, r, s, memo_size);
  PF ("      for (i=0; i < %d; i++){ %s_memo_table[i] = NULL; }\n", memo_size, s);
  PF ("    }\n");
  PF ("    for (_qqqq = &%s_memo_table[_hash]; *_qqqq != NULL; _qqqq = &(*_qqqq)->memo_link) {\n", s);
  memo_test (t, t, TRUE,  FALSE);
  memo_test (t, t, FALSE, FALSE);
  PF ("      return *_qqqq;\n");
  PF ("    }\n");
  PF ("    me = (%s)fe_malloc (sizeof(*me));\n", r);
  PF ("    me->memo_link = *_qqqq;\n");
  PF ("    *_qqqq = me;\n");
  PF ("  }\n");
}

static void
memo_access (struct_type t, Bool impl)
{
  String r = Type_str(Root_type(t));
  String s = Type_str(t);

  if (impl) PF ("static %s *%s_memo_table = NULL;\n\n", r, s);
  
  PF ("%svoid Memo_Traverse_%s (void (*f)(%s))%s", 
      impl ? "" : "extern ", 
      s, r, 
      impl ? "" : ";\n" );
      
  if (impl) {
    PF ("\n");
    PF ("{ int i;\n");
    PF ("  for (i=0; i < %d; i++) {\n", memo_size);
    PF ("    %s _qqqq;\n", s);
    PF ("    for (_qqqq = %s_memo_table[i]; _qqqq != NULL; _qqqq = _qqqq->memo_link) {\n", s);
    PF ("      f(_qqqq);\n");
    PF ("    }\n");
    PF ("  }\n");
    PF ("}\n\n");
  }
  
  PF ("%svoid Memo_Clear_%s (void)%s", 
      impl ? "" : "extern ", 
      s, 
      impl ? "" : ";\n" );
      
  if (impl) {
    PF ("\n");
    PF ("{ int i;\n");
    PF ("  if (!%s_memo_table) return;\n", s);
    PF ("  for (i=0; i < %d; i++) {\n", memo_size);
    PF ("    %s_memo_table[i] = NULL;\n", s);
    PF ("  }\n");
    PF ("}\n\n");
  }
}

/* Generate the create function implementation for f */
static void print_create_function (CreateFunction f)
{
  struct_type t = CreateFunction_type(f);
  
  if (struct_type_is_list(t)) return;
  
  if (is_memo(t)) memo_access (t, TRUE);
  
  print_create_header (f); PF ("\n");
  if (is_memo(t)) {
    PF ("{ %s me;\n", Type_str(t));
    memoize (t);
  } else {
    PF ("{ %s me = (%s)fe_malloc(sizeof(*me));\n", Type_str(t), Type_str(t));
  }
  if (struct_type_user(Root_type(t)) != NULL) {
    PF ("  %s(me, %s, %s);\n", abbreviate("USER_INITS"),
        Type_str(t), Type_str(t));
  }
  print_field_inits (t, t, FALSE, TRUE,  WhenCreate_kind);
  print_field_inits (t, t, FALSE, FALSE, WhenCreate_kind);
  print_field_inits (t, t, TRUE,  TRUE,  WhenCreate_kind);
  print_field_inits (t, t, TRUE,  FALSE, WhenCreate_kind);
  PF ("  return me;\n");
  PF ("}\n\n");
  
}

/* Generate all create function implementations */
static void print_create_functions (Types root)
{
  List_StructType l;
  List_CreateFunction f;
  
  for (l = Types_types (root); l; l = List_StructType_next(l)) {
    for (f = StructType_creates(List_StructType_data(l)); f; f = List_CreateFunction_next(f)) {
      print_create_function (List_CreateFunction_data(f));
    }
  }
}

/* Generate the namespace table and the Decorate function */
static void print_decorate (front f)
{
  List_NameSpace ns = front_namespaces(f);
  int i;
  
  PF ("%s %s[] = { -1",
      abbreviate("NameSpaces"),
      abbreviate("namespaces"));
  for (i=1; ns; ns = List_NameSpace_next(ns), i++) {
    PF (", %d", -1);
  }
  PF (" };\n\n");

  PF ("void Decorate_%s (%s r)\n", Rootstr, prefix_string(Rootstr));
  PF ("{\n"
      "  if (%s[0]<0) Extend_namespaces (%s, %s);\n",
      abbreviate("namespaces"), abbreviate("NUM_NAMESPACES"), abbreviate("namespaces"));
  PF ("  %s_root = r;\n", Rootstr);
  PF ("  if (NoDecorate) return;\n");
  PF ("  %s (r, &%s, NULL);\n", abbreviatef("Traverse_",Rootstr,""), abbreviate("scope_actions"));
  PF ("  %s (r, &%s);\n", abbreviatef("Traverse_void_",Rootstr,""), abbreviate("defining_actions"));
  PF ("  %s (r, &%s);\n", abbreviatef("Traverse_void_",Rootstr,""), abbreviate("applied_actions"));
  PF ("  %s (r, &%s);\n", abbreviatef("Traverse_void_",Rootstr,""), abbreviate("check_actions"));
  PF ("}\n");
}

/**************************** Traversals ******************************************/
static void
traverse_field (TravType k, field f, struct_type t)
{
  String k1 = TravName[k];
  String fid = Ident_name(field_id(f));
  String r = Ident_name(TypeName_full(HEAD (field_type(f))));
  
  PF ("    %s", indent);
  switch (k) {
  case TravPlain:
    PF ("if (action->traversal != Traverse_Down)");
    PF ("  val = Traverse_%s%s (%s_%s(me), action, val);\n", k1, r, Type_str(t), fid);
    PF ("    %selse Traverse_%s%s (%s_%s(me), action, val);\n", indent, k1, r, Type_str(t), fid);
    break;
  case TravVoid:
    PF ("Traverse_%s%s (%s_%s(me), action);\n", k1, r, Type_str(t), fid);
    break;
  case TravCopy:
    PF ("%s_%s(me) = Traverse_%s%s (%s_%s(me), action);\n", Type_str(t), fid, k1, r, Type_str(t), fid);
    break;
  case TravCompare:
    PF ("if ((comp = Traverse_%s%s (%s_%s(x),%s_%s(y), action)) != 0) return comp;\n",
        k1, r, Type_str(t), fid, Type_str(t), fid);
    break;
  }
}

static void
traverse_import_field (TravType k, field f, struct_type t)
{
  String grammar = Ident_name (field_grammar_id (f));
  String k1 = TravName[k];
  String fid = Ident_name(field_id(f));
  String tn = Ident_name(TypeName_id(HEAD (field_type(f))));
  
  PF ("    %s", indent);
  switch (k) {
  case TravPlain:
    PF ("if (action->traversal != Traverse_Down)");
    PF ("  val = Traverse_%s%s_%s (%s_%s(me), action->actions_%s, val);\n",
        k1, grammar, tn, Type_str(t), fid, tn);
    PF ("    %selse Traverse_%s%s_%s (%s_%s(me), action->actions_%s, val);\n",
        indent, k1, grammar, tn, Type_str(t), fid, tn);
    break;
  case TravVoid:
    PF ("Traverse_%s%s_%s (%s_%s(me), action->actions_%s);\n",
        k1, grammar, tn, Type_str(t), fid, tn);
    break;
  case TravCopy:
    PF ("%s_%s(me) = Traverse_%s%s_%s (%s_%s(me), action->actions_%s);\n",
        Type_str(t), fid, k1, grammar, tn, Type_str(t), fid, tn);
    break;
  case TravCompare:
    PF ("if ((comp = Traverse_%s%s_%s (%s_%s(x),%s_%s(y), action->actions_%s)) != 0) return comp;\n",
        k1, grammar, tn, Type_str(t), fid, Type_str(t), fid, tn);
    break;
  }
}

/* Generate recursively call for the traversals of the fields of t, for kind k.
   Pre indicates whether super-type fields should come first.
*/
static void traverse_fields (struct_type t, TravType k, Bool pre)
{
  struct_type s = Super_type(t);
  List_field l, m;
  Bool clear = FALSE, skip = FALSE;
  Bool clear_always;
  
  if (s != t && pre)  traverse_fields (s, k, pre);
  
  if (pre) m = struct_type_fields1(t);
  else     m = struct_type_fields2(t);
  
  for (l = m; l; l = TAIL (l)) {
    field f = HEAD (l);
    TypeName tn = HEAD (field_type(f));
    
    if (field_init(f) && !field_trav(f)) continue;
    if (field_is_tag(f)) continue;
    if (k != TravCompare && TermType (TypeName_id (tn))) continue;
    if (k != TravCompare && k != TravCopy &&
        (ListOfTermType (TypeName_id (tn)) ||
         OptionalTermType (TypeName_id (tn)))) {
      continue;
    }
    if (TypeName_id(tn) == Create_Ident("SrcInfo")) continue;
    if (!skip) {
      PF ("  %sif (%s) {\n", indent, action_skip_children(t, TRUE));
      skip = TRUE;
    }
    if (field_grammar_id (f) && field_grammar_id (f) != Create_Ident (prefix)) {
      traverse_import_field (k,f,t);
    } else {
      traverse_field (k,f,t);
    }
  }
  if (skip) PF ("  %s}\n", indent);
  
  /* Generate clear back-edges */
  for (clear_always = 0; clear_always <= 1; clear_always++) {
    clear = FALSE;
    for (l = m; l; l = List_field_next(l)) {
      field f = List_field_data(l);
      TypeName tn = List_TypeName_data(field_type(f));
      String fid = Ident_name(field_id(f));
      Ident t1 = glue_type (field_type(f));
      if (k != TravCopy) continue;
      if (field_init(f) == NULL) continue;
      if (field_dont_clear(f)) continue;
      if (field_clear(f) != clear_always) continue;
  /*     if (TypeName_id(tn) == Create_Ident("SrcInfo")) continue; */
  /*     if (field_generated(f)) continue; */

      if (!clear_always && !clear) {
	PF ("    %s", indent);
	PF ("if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {\n"); 
      }
      if (field_trav(f))  PF ("      %sif (%s) ", indent, action_skip_children(t, FALSE));
      else                PF ("      %s", indent);
      if (t1 == Create_Ident("VOID")) {
	char *expr = field_expr_when(f, WhenCreate_kind);
	if (!expr) expr = field_expr_when(f, WhenChecks_kind);
	PF ("%s;\n", expr);
      } else {
	PF ("%s_%s(me) = %s;\n", Type_str(t), fid, field_expr_when(f, WhenCreate_kind));
      }
      if (!clear_always) clear = TRUE;
    }
    if (clear) PF ("    %s}\n", indent);
  }
  
  if (s != t && !pre) traverse_fields (s, k, pre);
}

/* Generate call to an action function (pre or post) */
static void action (String id, String assign, String args, String pre, String rest, String cond)
{
  PF ("%sif (action->action_%s[%s_ACTION] != NULL%s) {\n", indent, id, pre, cond);
  PF ("    %s%saction->action_%s[%s_ACTION](%s);\n", indent, assign, id, pre, args);
  if (strlen(rest) > 0) PF ("%s%s", indent, rest);
  PF ("%s  }\n", indent);
}

/* Generate calls to all action functions, pre or post*/
static void actions (struct_type t, String assign, String args, Bool pre, String rest, String cond)
{
  struct_type s = Super_type(t);
  
  if (s==t) return;
  if (pre) {
    actions (s, assign, args, pre, rest, cond);
    PF ("  "); action (Type_name(t), assign, args, "PRE", rest, cond);
  } else {
    PF ("  "); action (Type_name(t), assign, args, "POST", rest, cond);
    actions (s, assign, args, pre, rest, cond);
  }
}

/* Generate traversal for a sub-type */
static void trav_sub (struct_type t, Bool root, TravType k, String assign, String args, String rest, String cond)
{
  String id = Type_str(t);
  String ind = indent;
  List_struct_type sub = struct_type_sub_types(t);
  
  if (sub != NULL) {
    for (; sub; sub = List_struct_type_next(sub)) {
      trav_sub (List_struct_type_data(sub), FALSE, k, assign, args, rest, cond);
    }
  } else if (!root) {
    indent = "      ";
    PF ("      case %s_kind:\n", id);
    actions (t, assign, args, TRUE, "", cond);
    traverse_fields (t, k, TRUE);
    traverse_fields (t, k, FALSE);
    actions (t, assign, args, FALSE, rest, cond);
    PF ("        break;\n");
    indent = ind;
  } else {
    traverse_fields (t, k, TRUE);
    traverse_fields (t, k, FALSE);
  }
}

/* Generate traversal actions for enum members */
static void trav_enums (List_TypeName l, TravType k, String assign, String args, String rest, String cond)
{
  NOT_USED(k);
  indent = "      ";
  for (; l; l = List_TypeName_next(l)) {
    String tid = Ident_name (TypeName_full (List_TypeName_data(l)));
    String aid = Ident_name (TypeName_id (List_TypeName_data(l)));
    PF ("      case %s:\n", tid);
    PF ("  "); action (aid, assign, args, "PRE", "", cond);
    PF ("  "); action (aid, assign, args, "POST", rest, cond);
    PF ("        break;\n");
  }
  indent = "";
}

/* Generate the function for the plain traversal of type t or e.
   'id' is the name of the type.
*/
static void plain_trav_func (struct_type t, EnumType e, String ab, String id)
{
  String cond = " && !(action->traversal == Traverse_Stop && val==NULL)";
  List_struct_type sub = NULL;
  
  if (t) sub = struct_type_sub_types(t);
  PF ("Pointer Traverse_%s (%s me, TraverseTable action, Pointer val)\n",
       id, id, abbreviate("TraverseTable"));
  PF ("{ \n");
  PF ("  if (%s_SKIP_NODE(%s, me)) return val;\n  ", Rootstr, ab);
  action (ab, "val = ", "me, val", "PRE", "", cond);
  if (!e) PF ("  if (me != NULL && %s)\n", action_skip_children(t, TRUE));
/*   PF ("  if (action->traversal != Traverse_Stop || val!=NULL)\n"); */
  PF ("  { ");
  if (sub != NULL) {
    PF ("switch (%s_tag(me)) {\n", id);
    for (; sub; sub = List_struct_type_next(sub)) {
      trav_sub (List_struct_type_data(sub), FALSE, TravPlain, "val = ", "me, val", "", cond);
    }
    PF ("    }\n");
  } else if (t) {
    PF ("\n");
    trav_sub (t, TRUE, TravPlain, "val = ", "me, val", "", cond);
  } else if (!enum_is_int(e)) {
    PF ("switch (me) {\n");
    trav_enums (EnumType_enums(e), TravPlain, "val = ", "me, val", "", cond);
    PF ("    }\n");
  }
  PF ("  }\n");
  PF ("  "); action (ab, "val = ", "me, val", "POST", "", cond);
  PF ("  return val;\n");
  PF ("}\n\n");
}

/* Generate the function for the void traversal of type t or e.
   'id' is the name of the type.
*/
static void void_trav_func (struct_type t, EnumType e, String ab, String id)
{
  List_struct_type sub = NULL;
  
  if (t) sub = struct_type_sub_types(t);
  PF ("void Traverse_void_%s (%s me, %s action)\n",
       id, id, abbreviatef("void_","TraverseTable",""));
  PF ("{ \n");
  PF ("  if (%s_SKIP_NODE(%s, me)) return;\n  ", Rootstr, ab);
  action (ab, "", "me", "PRE", "", "");
  if (!e) PF ("  if (me != NULL && %s)\n", action_skip_children(t, TRUE));
  PF ("  { ");
  if (sub != NULL) {
    PF ("switch (%s_tag(me)) {\n", id);
    for (; sub; sub = List_struct_type_next(sub)) {
      trav_sub (List_struct_type_data(sub), FALSE, TravVoid, "", "me", "", "");
    }
    PF ("    }\n");
  } else if (t)  {
    PF ("\n");
    trav_sub (t, TRUE, TravVoid, "", "me", "", "");
  } else if (!enum_is_int(e)) {
    PF ("switch (me) {\n");
    trav_enums (EnumType_enums(e), TravVoid, "", "me", "", "");
    PF ("    }\n");
  }
  PF ("  }\n");
  PF ("  "); action (ab, "", "me", "POST", "", "");
  PF ("}\n\n");
}

/* Generate the function for the copy traversal of type t or e.
   'id' is the name of the type.
*/
static void copy_trav_func (struct_type t, EnumType e, String ab, String id)
{
  List_struct_type sub = NULL;
  
  if (t) sub = struct_type_sub_types(t);
  PF ("%s Traverse_copy_%s (%s me, %s action)\n",
       id, id, id, abbreviatef("copy_","TraverseTable",""));
  PF ("{ %s _new = me, _old = me;\n", id);
  if (e) {
    PF ("  "); action (ab, "return ", "me, me", "PRE", "", "");
    PF ("  _new = me;\n");
  } else {
    PF ("  "); action (ab, "_new = ", "me, me", "PRE", "    if (_new != NULL) return _new;\n", "");
    PF ("  if (me == NULL) return me;\n");
    PF ("  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)\n");
    PF ("  { _new = (%s)fe_malloc (sizeof(*_new));\n", id);
    PF ("    *_new = *me;\n");
    PF ("  }\n");
    PF ("  me = _new;\n");
    PF ("  if (me != NULL)\n");
    PF ("  { ");
    if (sub != NULL) {
      PF ("switch (%s_tag(me)) {\n", id);
      for (; sub; sub = List_struct_type_next(sub)) {
	trav_sub (List_struct_type_data(sub), FALSE, TravCopy, "_new = ", "me, me", "    if (_new != NULL) return _new;\n", "");
      }
      PF ("    }\n");
    } else {
      PF ("\n");
      trav_sub (t, TRUE, TravCopy, "_new = ", "me, me", "    if (_new != NULL) return _new;\n", "");
    }
    PF ("  }\n");
  }
  PF ("  "); action (ab, "me = ", "me, _old", "POST", "", "");
  PF ("  return me;\n");
  PF ("}\n\n");
}

/* Generate the function for the compare traversal of type t or e.
   'id' is the name of the type.
*/
static void compare_trav_func (struct_type t, EnumType e, String ab, String id)
{
  List_struct_type sub = NULL;
  
  if (t) sub = struct_type_sub_types(t);
  PF ("int Traverse_compare_%s (%s x, %s y, %s action)\n",
       id, id, id, abbreviatef("compare_","TraverseTable",""));
  if (e) {
    PF ("{ "); action (ab, "return ", "x, y", "PRE", "", "");
    PF ("  if (x < y) return -1;\n");
    PF ("  if (x > y) return 1;\n");
    PF ("  return 0;");
    PF ("}\n\n");
    return;
  }
  PF ("{ int comp = 0;\n");
  PF ("  "); action (ab, "return ", "x, y", "PRE", "", "");
  PF ("  if (x == y) return 0;\n");
  if (!e) PF ("  if (x == NULL && y != NULL) return -1;\n");
  if (!e) PF ("  if (x != NULL && y == NULL) return 1;\n");
  if (sub != NULL) {
    PF ("  if (%s_tag(x) < %s_tag(y)) return -1;\n", id, id);
    PF ("  if (%s_tag(x) > %s_tag(y)) return 1;;\n", id, id);
    PF ("  switch (%s_tag(x)) {\n", id);
    for (; sub; sub = List_struct_type_next(sub)) {
      trav_sub (List_struct_type_data(sub), FALSE, TravCompare, "return ", "x, y", "", "");
    }
    PF ("  }\n");
  } else if (t)  {
    PF ("\n");
    trav_sub (t, TRUE, TravCompare, "return ", "x, y", "", "");
  } else {
    trav_enums (EnumType_enums(e), TravCompare, "return ", "x, y", "", "");
  }
  PF ("  return comp;\n");
  PF ("}\n\n");
}

/* Generate the traversal functions for all types. 
   The argument trav_func is called for each type and is one of the
   four functions above, depending on the traversal kind.
*/
static void
print_traverse_funcs (List_struct_type types, List_EnumType enums,
                      void (*trav_func) (struct_type t, EnumType e,
                                         String ab, String id))
{
  List_struct_type l;
  List_EnumType m;

  for (l = types; l; l = List_struct_type_next(l)) {
    struct_type t = List_struct_type_data(l);
    if (Std_type(struct_type_tag(t))) continue;
    trav_func (t, NULL, Type_name(t), Type_str(t));
  }
  
  for (m = enums; m; m = List_EnumType_next(m)) {
    EnumType t = List_EnumType_data(m);
    if (EnumType_is_tag(t)) continue;
    trav_func (NULL, t, Ident_name(EnumType_name(t)), Ident_name(EnumType_id(t)));
  }
}

/* Check whether t contains a defining field */
static Bool struct_type_is_defining (struct_type t)
{ 
  List_field l;
  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (field_is_defining(f) != NULL) return TRUE;
  }
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (field_is_defining(f) != NULL) return TRUE;
  }
  return FALSE;
}

/* Check whether t contains an applied field */
static Bool struct_type_is_applied (struct_type t)
{ 
  List_field l;
  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (field_is_applied(f) != NULL) return TRUE;
  }
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (field_is_applied(f) != NULL) return TRUE;
  }
  return FALSE;
}

/* Check whether t has a field with FieldInit i */
static Bool has_field_init (struct_type t, FieldInit_tag i)
{
  List_field l;
  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (field_init_when(f, i)) return TRUE;
  }
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (field_init_when(f, i)) return TRUE;
  }
  return FALSE;
}

/************ Scope functions ************/

static void scope_header (struct_type t, Bool *done)
{
  if (!*done) {
    PF ("static void* PushScope_%s (%s me, void *val)\n", Type_str(t), Type_str(t));                                                                                                  
    PF ("{ if (me == NULL) return val;\n");                                                                                                                                            
  }
  *done = TRUE;
}

static void scope_function (struct_type t, String scope, Bool *done)
{
  struct_type r = Root_type(t);
/*   if (!struct_type_opens_scope(t) && !struct_type_uses_scope(t) && */
/*       (t!=r || !uses_scope(t))) return; */
  if ( (struct_type_sub_types(t) || !uses_scope(r)) &&
       !struct_type_opens_scope(t)) {
    return;
  }

  scope_header (t, done);

  if (struct_type_opens_scope(t) || uses_scope(r)) {
    PF ("  me->old_scope = (%s) val;\n", scope);
  }
  if (struct_type_opens_scope(t)) {
    PF ("  if (%s_scope(me) != NULL &&\n", Type_str(r));
    PF ("      %s_next(%s_scope(me))==(%s)val &&\n", scope, Type_str(r), scope);
    PF ("      %sScope_data(%s_scope(me)) == me)\n", Type_name(t), Type_str(r));
    PF ("       val = %s_scope(me);\n", Type_str(r)); 
    PF ("  else {\n");
    PF ("    val = (void*)Create_%sScope ((%s)val, me);\n", Type_name(t), scope);
    PF ("  }\n");
  }
  PF ("  %s_scope(me) = (%s) val;\n", Type_str(r), scope);                                                                                                               
}

/* Generate the Push_Scope_t and Pop_Scope_t function for all t in types */
static void scope_functions (List_struct_type types)
{
  struct_type t;
  struct_type r;
  String scope;
  Bool done = FALSE;
  List_field l;
  
  scope = prefix_string("Scope");
  
  if (types==NULL) return;
  t = List_struct_type_data (types);
  r = Root_type (t);
  
  scope_function (t, scope, &done);
  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    gen_field_init (t, List_field_data(l), WhenScope_kind, &done, scope_header);
  }
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    gen_field_init (t, List_field_data(l), WhenScope_kind, &done, scope_header);
  }
  if (done) {
    PF ("  return val;\n");                                                                                                                                                
    PF ("}\n\n");                                                                                                                                                            
  }

  if (struct_type_closes_scope(t)) {
    PF ("static void* PopScope_%s (%s me, void *val)\n", Type_str(t), Type_str(t));                                                                                                
    PF ("{ if (me == NULL) return val;\n");
    PF ("  val = (void*)me->old_scope;\n");                                                                                                                
    PF ("  return val;\n");                                                                                                                                                
    PF ("}\n\n");                                                                                                                                                            
  }

  if (struct_type_sub_types(t) != NULL) {
    scope_functions (struct_type_sub_types(t));
  }
  scope_functions (List_struct_type_next(types));
}

/* Generate the contents of the scope_table */
static void trav_scope (List_struct_type types)
{
  struct_type t;
  struct_type r;
  if (types==NULL) return;
  t = List_struct_type_data (types);
  if (Std_type(struct_type_tag(t))) {
    trav_scope (List_struct_type_next(types));
    return;
  }
  r = Root_type (t);
  if (struct_type_closes_scope(t)) {
    PF ("  { PopScope_%s,\t", Type_str(t));
  } else {
    PF ("  { NULL,\t");
  }
  if ( !(struct_type_sub_types(t) || !uses_scope(r)) ||
       struct_type_opens_scope(t) ||
       has_field_init (t, WhenScope_kind)) {
    PF ("PushScope_%s", Type_str(t));
  } else {
    PF ("NULL");
  }
  PF (" }, FALSE,\t/* %s */\n", Type_str(t));
  if (struct_type_sub_types(t) != NULL) {
    trav_scope (struct_type_sub_types(t));
  }
  trav_scope (List_struct_type_next(types));
}

/************ Defining functions ************/

/* Generate an access for field f of type t */
static void access_ident (struct_type t, field f)
{
  String type = Ident_name (TypeName_id(List_TypeName_data(field_type(f))));
  String fid = Ident_name(field_id(f));
  String l = "";
  Bool list = is_list (List_TypeName_data(field_type(f)));
  
  if (list) l = "List_";

  if (strcmp(type, "Ident") == 0 || 
      (list && strcmp(type, "List_Ident") == 0)) {
    PF ("%s_%s(me)", Type_str(t), fid);
  } else {
    PF ("%s_to_%sIdent(%s_%s(me))", type, l, Type_str(t), fid);
  }
}

static Bool
is_root_nt(struct_type t)
{
  return IsNonTerm(t) && t==Root_type(t);
}

static void
def_header (struct_type t, Bool *done)
{ 
  struct_type r = Root_type(t);
  if (*done) return;
  PF ("static void Defining_%s (%s me)\n", Type_str(t), Type_str(t));                                                                                                              
  PF ("{\n");
  if (uses_scope(t) || opens_scope(t)) {
    PF ("  Scope scope;\n");
  }
  PF ("  if (me==NULL) return;\n");
  *done = TRUE;
}

static void
def_header_common(struct_type t, Symbol def, Int *done)
{
  struct_type r = Root_type(t);
  if (*done == 2) return;
  if (struct_type_opens_scope(t)) {
    def_header (t, done);
    PF ("  Scope__self (%s_scope(me)) = Scope_Num_Stores (%s_old_scope(me));\n"
        , Type_str(r), Type_str(r));
    *done = 2;
  }
  if (uses_scope(t) || opens_scope(t)) {
    def_header (t, done);
    PF ("  scope = ");;
    if (def && DefiningSym_sc(def)) {
      PF ("%s;\n", expr_to_string(DefiningSym_sc(def)));
    } else if (struct_type_opens_scope(t)) {
      PF ("%s(%s_scope(me));\n", abbreviate("Scope_next"), Type_str(r));
    } else {
      PF ("%s_scope(me);\n", Type_str(r));
    }
    PF ("  %s__num(me) = Scope_Num_Stores (scope);\n", Type_str(r), Type_str(r));
    *done = 2;
  }
}
  
/* Generate a Defining_t function for defining field f in type t */
static void
defining_function (struct_type t, field f, Int *done)
{ 
  struct_type r = Root_type(t);
  String ns = "DefaultNameSpace";
  Symbol def = field_is_defining(f);
  struct_type bind;
  String overload = "FALSE";
  String redef = "FALSE";
  String forward = "FALSE";
  String type = Ident_name (TypeName_id(List_TypeName_data(field_type(f))));
  String store = "ReplaceBind";
  String cast = "";

  if (!def && !is_root_nt(t) && !struct_type_opens_scope(t)) return;
  def_header (t, done);
  if (!def) return;
  def_header_common (t, def, done);
  
  if (DefiningSym_ns_id(def) != NULL) {
    ns = Ident_name(DefiningSym_ns_id(def));
  }
  bind = find_field_type (t, bind_id(f));
  
  if (DefiningSym_forward(def)) forward = "TRUE";
  switch (DefiningSym_def(def)) {
  case Redefining: redef = "TRUE"; break;
  case Overloading: overload = "TRUE"; break;
  default: break;
  }
  
  if (is_list(List_TypeName_data(field_type(f)))) {
    store = "ReplaceBindList";
    cast = Front_StrAllocf ("(List_Bind_%s)", Type_str(r));
  }
  
  PF ("  %s_%s(me) = %s%s (%s_%s(me), ",
      Type_str(bind), Ident_name(bind_id(f)),
      cast, store,
      Type_str(bind), Ident_name(bind_id(f)));
  access_ident (t, f);
  PF (", scope, %s, me, %s, %s, %s, %s);\n",                 
      def_abbrevf("Bind_",Type_name(r),Type_str(r),"_kind"),
      abbreviate(ns), overload, redef, forward);
}

/* Generate defining functions for all types t in types */
static void defining_functions (List_struct_type types)
{
  struct_type t;
  struct_type r;
  List_field l;
  Int done = 0;

  if (types==NULL) return;
  t = List_struct_type_data (types);
  r = Root_type (t);
  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    gen_field_init (t, List_field_data(l), WhenDefining_kind, &done, def_header);
    defining_function (t, List_field_data(l), &done);
  }
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    gen_field_init (t, List_field_data(l), WhenDefining_kind, &done, def_header);
    defining_function (t, List_field_data(l), &done);
  }
  def_header_common (t, NULL, &done);
  if (done) {
    PF ("}\n\n");                                                                                                                                                         
  } 

  if (struct_type_sub_types(t) != NULL) {
    defining_functions (struct_type_sub_types(t));
  }
  defining_functions (List_struct_type_next(types));
}

/* Generate the contents of the defining_table */
static void trav_defining (List_struct_type types)
{
  struct_type t;
  struct_type r;
  if (types==NULL) return;
  t = List_struct_type_data (types);
  if (Std_type(struct_type_tag(t))) {
    trav_defining (List_struct_type_next(types));
    return;
  }
  r = Root_type (t);
  PF ("  { NULL,\t");
  if (struct_type_is_defining(t) ||
      is_root_nt(t) ||
      has_field_init (t, WhenDefining_kind) ||
      struct_type_opens_scope(t)) {
    PF ("(void*)Defining_%s", Type_str(t));
  } else {
    PF ("NULL");
  }
  PF (" }, FALSE,\t/* %s */\n", Type_str(t));
  if (struct_type_sub_types(t) != NULL) {
    trav_defining (struct_type_sub_types(t));
  }
  trav_defining (List_struct_type_next(types));
}

/************ Applied functions ************/

static struct_type find_typeof_field (struct_type t, Ident f)
{ if (t==NULL) return NULL;
  if (contains_field (t, f)) {
    return t;
  }
  if (Super_type(t)==t) return NULL;
  return find_typeof_field (Super_type(t), f);
}

static void applied_header (struct_type t, Bool *done)
{ 
  if (!*done) {
    PF ("static void Retrieve_%s (%s me)\n", Type_str(t), Type_str(t));                                                                                                              
    PF ("{ if (me==NULL) return;\n");                                                                                                                                      
  }
  *done = TRUE;
}
/* Generate a Retrieve_t function for applied field f in type t */
static void applied_function (struct_type t, field f, Bool *done)
{ 
  struct_type r = Root_type(t);
  String ns = "DefaultNameSpace";
  Symbol app = field_is_applied(f);
  Symbol def = NULL;
  Bool overload = FALSE;
  String type;
  String fid = Ident_name(field_applied_id(f));
  String scope = append_string (Type_str(r), "_scope(me)");
  struct_type tf = find_typeof_field (t, field_applied_id(f));
  String idname;
  String locname = append_string (Type_str(r), "__num(me)");
  NonTerminal nt;
  struct_type def_type;
  Alternative alt;
  Ident tid;
  
  if (app == NULL) return;
  
  nt = AppliedSym_nt(app);
  alt = AppliedSym_alt(app);
  def = find_defining (nt, alt);
  if (def==NULL) {
    String nt_name = Ident_name (AppliedSym_nt_id(app));
    InputError (Symbol_loc(app), TRUE, "No defining symbol found for applied symbol %s", nt_name);
    return;
  }

  def_type = nonterm_type (nt, alt, &tid);
  type = Type_str(Root_type(def_type));
  
  if (DefiningSym_ns_id(def) != NULL) {
    ns = Ident_name(DefiningSym_ns_id(def));
  }
  overload = def && DefiningSym_def(def) == Overloading;
    
  if (AppliedSym_sc(app) != NULL) scope = expr_to_string(AppliedSym_sc(app));
  
  idname = Front_StrAllocf ("%s_%s_id(me)", Type_str(tf), fid);
  if (AppliedSym_field(app) == AppliedField) {
    tf = find_typeof_field (t, AppliedSym_name(app));
    if ( tf == NULL ) {
      InputError(Symbol_loc(app), TRUE, "No defining symbol found for applied field `%s'", Ident_name(AppliedSym_name(app)));
      return;
    }
    idname = Front_StrAllocf ("%s_%s(me)", Type_str(tf), Ident_name(AppliedSym_name(app)));
  } else if (AppliedSym_name(app) != Create_Ident("Ident")) {
    idname = Front_StrAllocf ("%s_to_Ident(%s)", Ident_name(AppliedSym_name(app)), idname);
  }
  
  applied_header (t, done);
  PF ("  if (%s != NULL) {\n", idname);
  
  if (!overload) {                                                                                                           
    PF ("    %s_%s_bind(me) = RetrieveBind (%s, %s, %s, %s, Bind_%s_kind);\n",
              Type_str(t), fid, idname, scope, locname, abbreviate(ns), type);      
    PF ("    %s_%s(me) = NULL;\n", Type_str(t), fid);                                                                                                                  
    PF ("    if (%s_%s_bind(me) != NULL)\n", Type_str(t), fid);                                                                                                        
    PF ("      %s_%s(me) = (%s)Bind_object(%s_%s_bind(me));\n",
              Type_str(t), fid, Type_str(def_type), Type_str(t), fid);                                                                        
  } else {
    PF ("    { List_Bind l;\n");
    PF ("      %s_%s_bind(me) = RetrieveListBind (%s, %s, %s, %s, Bind_%s_kind);\n",
              Type_str(t), fid, idname, scope, locname, abbreviate(ns), type);      
    PF ("      %s_%s(me) = NULL;\n", Type_str(t), fid);                                                                                                                  
    PF ("      for (l = %s_%s_bind(me); l != NULL; l = List_Bind_next(l)) {\n", Type_str(t), fid);                                                                                                        
    PF ("        FRONT_APPEND_NODE (%s_%s(me), Bind_object(List_Bind_data(l)));\n",
                Type_str(t), fid);                                                                        
    PF ("      }\n");                                                                                                                                                                                                                                                                                   
    PF ("    }\n");                                                                                                                                                                                                                                                                                   
  }
  PF ("  }\n");                                                                                                                                                                                                                                                                                   
}

/* Generate applied functions for all types t in types */
static void applied_functions (List_struct_type types)
{
  struct_type t;
  struct_type r;
  List_field l;
  Bool done = FALSE;
  
  if (types==NULL) return;
  
  t = List_struct_type_data (types);
  r = Root_type (t);
  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    gen_field_init (t, List_field_data(l), WhenApplied_kind, &done, applied_header);
    applied_function (t, List_field_data(l), &done);
  }
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    gen_field_init (t, List_field_data(l), WhenApplied_kind, &done, applied_header);
    applied_function (t, List_field_data(l), &done);
  }
  if (done) {
    PF ("}\n\n");                                                                                                                                                         
  }

  if (struct_type_sub_types(t) != NULL) {
    applied_functions (struct_type_sub_types(t));
  }
  applied_functions (List_struct_type_next(types));
}

/* Generate the contents of the applied_table */
static void trav_applied (List_struct_type types)
{
  struct_type t;
  struct_type r;
  if (types==NULL) return;
  t = List_struct_type_data (types);
  if (Std_type(struct_type_tag(t))) {
    trav_applied (List_struct_type_next(types));
    return;
  }
  r = Root_type (t);
  PF ("  { NULL,\t");
  if (struct_type_is_applied(t) || 
      has_field_init (t, WhenApplied_kind)) {
    PF ("Retrieve_%s", Type_str(t));
  } else {
    PF ("NULL");
  }
  PF (" }, FALSE,\t/* %s */\n", Type_str(t));
  if (struct_type_sub_types(t) != NULL) {
    trav_applied (struct_type_sub_types(t));
  }
  trav_applied (List_struct_type_next(types));
}

/************ Check functions ************/

static void check_header (struct_type t, Bool *done)
{ 
  if (!*done) {
    PF ("static void Check_%s (%s me)\n", Type_str(t), Type_str(t));                                                                                                           
    PF ("{ if (me==NULL) return;\n");
  }
  *done = TRUE;
}

/* Generate a Check_t function for the checks of type t */
static void check_function (struct_type t, Bool *done)
{ struct_type r = Root_type(t);
  List_Check l;
  List_Expr m;
  
  if (struct_type_checks(t) == NULL) return;

  check_header (t, done);
    
  for (l = struct_type_checks(t); l; l = List_Check_next(l)) {
    Check c = List_Check_data(l);
    PF ("  { if ("); Print_Expr(Check_cond(c)); PF (")\n");                                                                                                            
    PF ("    { Input%s (%s_loc(me), FALSE, %s\"\");\n", 
       Check_warn(c) ? "Warning" : "Error", Type_str(r),
       Check_warn(c) ? "5, " : "");                                                                                                 
    for (m = Check_message(c); m; m = List_Expr_next(m)) {
      PF ("      FrontMessage (\"%%s\", %s);\n", expr_to_string(List_Expr_data(m)));                                                                                               
    }
    PF ("      FrontMessage (\"\\n\");\n");                                                                                                                   
    PF ("    }\n");                                                                                                                                        
    PF ("  }\n");                                                                                                                                            
  }                                                                                                                      
}

/* Generate a Check_t function for the definings of type t */
static void check_def (struct_type t, field f, Bool *done)
{ 
  struct_type r = Root_type(t);
  Symbol def = field_is_defining(f);
  struct_type bind;
  Bool overload = FALSE;
  Bool redef = FALSE;
  String type = Ident_name (TypeName_id(List_TypeName_data(field_type(f))));
  String bid;
  
  if (def == NULL) return;
  
  check_header (t, done);

  bind = find_field_type (t, bind_id(f));
  bid = Ident_name(bind_id(f));
  switch (DefiningSym_def(def)) {
    case Redefining: redef = TRUE; break;
    case Overloading: overload = TRUE; break;
    default: break;
  }

#if 1
  overload = FALSE;
#endif
    
  if (strncmp (type, "List_", 5)==0) {
    PF ("  { List_Bind_%s _lll;\n", Type_str(r));
    PF ("    for (_lll = %s_%s(me); _lll; _lll = List_Bind_%s_next(_lll)) {\n", Type_str(bind), bid, Type_str(r));
    PF ("      Bind _bind = List_Bind_%s_data(_lll);\n", Type_str(r));
    PF ("      if (%sBind_double (_bind)) {\n", overload?"List_":"");                                                                                                                            
    PF ("        InputError (%s_loc(me), TRUE, "
                "\"Identifier '%%s' already declared\", Ident_name(Bind_id(_bind)));\n", Type_str(r));
    PF ("      }\n");
    PF ("    }\n");
    PF ("  }\n");
  } else { 
    PF ("  if (%sBind_double (%s_%s(me))) {\n", overload?"List_":"", Type_str(bind), bid);                                                                                                                            
    PF ("    InputError (%s_loc(me), TRUE, "
            "\"Identifier '%%s' already declared\", Ident_name(", Type_str(r));
	    access_ident (t, f);
            PF ("));\n");
    PF ("  }\n");
  }
}

/* Check whether id contains NULL */
static Bool no_nil (Ident id)
{
  return id == Create_Ident ("Int") ||
         id == Create_Ident ("Hex") ||
         id == Create_Ident ("Oct") ||
         id == Create_Ident ("Bool") ||
         id == Create_Ident ("Char") ||
         id == Create_Ident ("Float");
}

/* Generate a Check_t function for the applieds of type t */
static void check_applied (struct_type t, field f, Bool *done)
{ 
  struct_type r = Root_type(t);
  String ns = "DefaultNameSpace";
  Symbol app = field_is_applied(f);
  Symbol def = NULL;
  Bool overload = FALSE;
  String type;
  String fid = Ident_name(field_applied_id(f));
  String scope = append_string (Type_str(r), "_scope(me)");
  String idname = Front_StrAllocf ("%s_%s_id(me)", Type_str(t), fid);
  String locname = append_string (Type_str(r), "_loc(me)");
  struct_type def_type;
  Ident tid;
  
  if (app == NULL) return;
  
  overload = applied_overloaded(app);

  def = find_defining (AppliedSym_nt(app), AppliedSym_alt(app));
  if (def == NULL) return;
  
  def_type = nonterm_type (AppliedSym_nt(app), AppliedSym_alt(app), &tid);
  type = Type_str(Root_type(def_type));

  if (DefiningSym_ns_id(def) != NULL) {
    ns = Ident_name(DefiningSym_ns_id(def));
  }
    
  if (AppliedSym_name(app) != Create_Ident("Ident")) {
    idname = Front_StrAllocf ("%s_to_Ident(%s)", Ident_name(AppliedSym_name(app)), idname);
  }  
  
  check_header (t, done);
  
  if (AppliedSym_field(app) == AppliedField) return;

  if (!overload) {                                                                                                           
    PF ("  if (%s_%s_bind(me) == NULL", Type_str(t), fid);
    if (!no_nil(AppliedSym_name(app))) {
      PF (" && %s != NULL", idname);                                                                                           
    }
    PF (") {\n");
    PF ("    InputError (%s_loc(me), TRUE, ", Type_str(r));
          PF ("\"Identifier '%%s' not declared\", Ident_name(%s));\n", idname);
    PF ("  }\n");                                                    
  } else {
    PF ("  { List_Bind l;\n");
    PF ("    %s_%s_bind(me) = RetrieveListBind (%s, %s, %s, %s, Bind_%s_kind);\n",
              Type_str(t), fid, idname, scope, locname, abbreviate(ns), type);      
    PF ("    if (%s != NULL && %s_%s_bind(me) == NULL) {\n", idname, Type_str(t), fid);
    PF ("      InputError (%s_loc(me), TRUE, ", Type_str(r));
              PF ("\"Identifier '%%s' not declared\", Ident_name(%s));\n", idname);
    PF ("    }\n");
    PF ("    for (l = %s_%s_bind(me); l != NULL; l = List_Bind_next(l)) {\n", Type_str(t), fid);                                                                                                        
    PF ("      if (List_Bind_data(l) == NULL &&");
              PF ("%s != NULL) {\n", idname);                                                                                           
    PF ("        InputError (%s_loc(me), TRUE, ", Type_str(r));
              PF ("\"Identifier '%%s' not declared\", Ident_name(%s));\n", idname);
    PF ("      }\n");                                                    
    PF ("    }\n");
    PF ("  }\n");                                                                                                                                                                                                                                                                                
  }
}

/* Generate check functions for all types t in types */
static void check_functions (List_struct_type types)
{
  struct_type t;
  List_field l;
  Bool done = FALSE;
  
  if (types==NULL) return;
  
  t = List_struct_type_data (types);
  check_function (t, &done);
  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    gen_field_init (t, List_field_data(l), WhenChecks_kind, &done, check_header);
    check_def (t, List_field_data(l), &done);
    check_applied (t, List_field_data(l), &done);
  }
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    gen_field_init (t, List_field_data(l), WhenChecks_kind, &done, check_header);
    check_def (t, List_field_data(l), &done);
    check_applied (t, List_field_data(l), &done);
  }
  if (done) {
    PF ("}\n\n");                                                                                                                                                         
  }

  if (struct_type_sub_types(t) != NULL) {
    check_functions (struct_type_sub_types(t));
  }
  check_functions (List_struct_type_next(types));
}

/* Generate the contents of the check_table */
static void trav_check (List_struct_type types)
{
  struct_type t;
  if (types==NULL) return;
  t = List_struct_type_data (types);
  if (!Std_type(struct_type_tag(t))) {
    PF ("  { NULL,\t");
    if (struct_type_checks(t) != NULL || 
        struct_type_is_defining(t) || 
        struct_type_is_applied(t) || 
        has_field_init (t, WhenChecks_kind)) {
      PF ("Check_%s", Type_str(t));
    } else {
      PF ("NULL");
    }
    PF (" }, FALSE,\t/* %s */\n", Type_str(t));
    if (struct_type_sub_types(t) != NULL) {
      trav_check (struct_type_sub_types(t));
    }
  }
  trav_check (List_struct_type_next(types));
}

/************ Tables ************/

/* Generate empty field inits for enum elements of a traverse table */
static void trav_enum_init (List_EnumType types)
{
  EnumType t;
  List_TypeName l;
   
  if (types==NULL) return;
  t = List_EnumType_data (types);
  if (!EnumType_is_tag(t)/* && !enum_is_int(t)*/) {
    Ident id = EnumType_id(t);
    PF ("  { NULL,\t NULL }, FALSE,\t/* %s */\n", Ident_name(id));

    for (l = EnumType_enums(t); l; l = List_Ident_next(l)) {
      Ident id = TypeName_full (List_TypeName_data(l));
      if (id == NULL || id == Create_Ident("")) continue;
      PF ("  { NULL,\t NULL }, FALSE,\t/* %s */\n", Ident_name(id));
    }
  }
  trav_enum_init (List_EnumType_next(types));
}

#define b2s(b) ((b)?"TRUE":"FALSE")

/*************** Fill_tabels *************/

/* Fill the table for type t, root type r, kind k and pre or post with function x */
static void fill_tab (String t, String r, TravType k, String pre)
{ 
  switch (k) {
    case TravPlain:
      PF ("  if (x!=NULL) t->action_%s[%s_ACTION] = (void* (*) (%s, void*))x;\n", t, pre, r);
      break;
    case TravVoid:
      PF ("  if (x!=NULL) t->action_%s[%s_ACTION] = (void (*) (%s))x;\n", t, pre, r);
      break;
    case TravCopy:
      PF ("  if (x!=NULL) t->action_%s[%s_ACTION] = (%s (*) (%s, %s))x;\n", t, pre, r, r, r);
      break;
    case TravCompare:
      PF ("  if (x!=NULL) t->action_%s[%s_ACTION] = (int (*) (%s, %s))x;\n", t, pre, r, r);
      break;
  }
}

/* Fill the table for type t, root type r, kind k and pre or post 
   First compute the function x that will be stored.
   This function gets properties of the type at hand as arguments, namely
   enum-type, sub-type, list-type, memo-type.
*/
static void fill_table_call (String t, String r, Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, TravType k)
{
  PF ("  x = f (%s,%s,%s,%s,%s,PRE_ACTION);\n", b2s(e_num), b2s(sub), b2s(list), b2s(opt), b2s(memo));
  fill_tab (t, r, k, "PRE");
  PF ("  x = f (%s,%s,%s,%s,%s,POST_ACTION);\n", b2s(e_num), b2s(sub), b2s(list), b2s(opt), b2s(memo));
  fill_tab (t, r, k, "POST");
}

/* Fill the table for all types t in types and traverse kind k */
static void fill_type_tables (List_struct_type types, Bool sub, TravType k)
{ List_struct_type l;
  for (l = types; l; l = List_struct_type_next(l)) {
    struct_type t = List_struct_type_data(l);
    Bool memo = FALSE;
    if(Std_type (struct_type_tag(t))) continue;
    fill_table_call (Type_name(t), Type_str(t), FALSE, sub, struct_type_is_list(t), struct_type_is_optional(t), memo, k);
    if (struct_type_sub_types(t) != NULL) {
      fill_type_tables (struct_type_sub_types(t), TRUE, k);
    }
  }
}

/* Fill the table for all enum-types t in types and traverse kind k */
static void fill_enum_tables (List_EnumType enums, TravType k)
{ List_EnumType l;
  for (l = enums; l; l = List_EnumType_next(l)) {
    EnumType t = List_EnumType_data(l);
    List_TypeName sub;
    if (EnumType_is_tag(t)) continue;
    fill_table_call (Ident_name (EnumType_name(t)), Ident_name (EnumType_id(t)), TRUE, FALSE, FALSE, FALSE, FALSE, k);
    for (sub = EnumType_enums(t); sub; sub = List_Ident_next(sub)) {
      Ident id = TypeName_id (List_Ident_data(sub));
      if (id==NULL || id == Create_Ident("")) continue;
      fill_table_call (Ident_name(id), Ident_name (EnumType_id(t)), TRUE, TRUE, FALSE, FALSE, FALSE, k);
    }
  }
}

/* Generate the fill_tabel functions for traverse kind k*/
static void fill_tables (List_struct_type types, List_EnumType enums, TravType k)
{
  String k1 = TravName[k];
  PF ("void %s (%s t,"
         "void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))\n",
      abbreviatef (k1,"fill_table",""),
      abbreviatef (k1,"TraverseTable",""));
  PF ("{ void *x;\n");
  fill_type_tables (types, FALSE, k);
  fill_enum_tables (enums, k);
  PF ("}\n\n");
}

/* Generate the standard traverse tables and the fill functions */
static void print_tables (List_struct_type types, List_EnumType enums)
{
  scope_functions (types);
  PF ("struct %s %s = {\n\n",
      abbreviatef ("s_","TraverseTable",""), abbreviate ("scope_actions"));
  PF ("  Traverse_Accumulate,\n");
    trav_scope (types);
    trav_enum_init (enums);
  PF ("};\n\n");
  
  defining_functions (types);
  PF ("struct %s %s = {\n\n",
      abbreviatef ("s_void_","TraverseTable",""), abbreviate ("defining_actions"));
    trav_defining (types);
    trav_enum_init (enums);
  PF ("};\n\n");
  
  applied_functions (types);
  PF ("struct %s %s = {\n\n",
      abbreviatef ("s_void_","TraverseTable",""), abbreviate ("applied_actions"));
    trav_applied (types);
    trav_enum_init (enums);
  PF ("};\n\n");
  
  check_functions (types);
  PF ("struct %s %s = {\n\n",
      abbreviatef ("s_void_","TraverseTable",""), abbreviate ("check_actions"));
    trav_check (types);
    trav_enum_init (enums);
  PF ("};\n\n");
  
  PF ("struct %s %s;\n\n",
      abbreviatef ("s_void_","TraverseTable",""), abbreviate ("print_actions"));
  PF ("struct %s %s;\n\n",
      abbreviatef ("s_copy_","TraverseTable",""), abbreviate ("copy_actions"));
  PF ("struct %s %s;\n\n",
      abbreviatef ("s_compare_","TraverseTable",""), abbreviate ("compare_actions"));

  fill_tables (types, enums, TravPlain);
  fill_tables (types, enums, TravVoid);
  fill_tables (types, enums, TravCopy);
  fill_tables (types, enums, TravCompare);
}

/* Generate the Root.c module */
static void print_types_impl (front f, Types types_root, List_struct_type types)
{
  open_print_file (append_string (Rootstr, ".c"), TRUE);
  set_margin(0); set_position(0);

  print_std_include ("stdio");
  print_std_include ("assert");
  print_std_include ("string");
  print_include ("error");
  print_include ("support");
  print_include ("scan_support");
  print_include ("mem");
  PF ("#include \"%s.h\"\n", Rootstr);
  PF ("\n");

  PF ("#ifndef %s_SKIP_NODE\n", Rootstr);
  PF ("# define %s_SKIP_NODE(n,t) FALSE\n", Rootstr);
  PF ("#endif\n\n");
  PF ("%s %s_root;\n\n", Rootstr, Rootstr);
  
  print_enum_names (Types_enums(types_root));
  print_create_functions (types_root);
  print_traverse_funcs (types, Types_enums(types_root), plain_trav_func);
  print_traverse_funcs (types, Types_enums(types_root), void_trav_func);
  print_traverse_funcs (types, Types_enums(types_root), copy_trav_func);
  print_traverse_funcs (types, Types_enums(types_root), compare_trav_func);
  
  print_tables (types, Types_enums(types_root));
  print_decorate (f);

  close_print_file();
}

/**************/

static Bool has_empty_sub_types (List_struct_type l)
{
  for (; l; l = List_struct_type_next(l)) {
    struct_type t = List_struct_type_data(l);
    List_struct_type sub = struct_type_sub_types(t);
    if (struct_type_fields1(t) != NULL) return FALSE;
    if (struct_type_fields2(t) != NULL) return FALSE;
    if (!has_empty_sub_types(sub)) return FALSE;
  }
  return TRUE;
}

static void print_struct_type (struct_type me)
{
  List_struct_type sub = struct_type_sub_types(me);
  if (has_empty_sub_types(sub)) {
    struct_type_sub_types(me) = NULL;
    Print_Types_struct_type (me);
    struct_type_sub_types(me) = sub;
  } else {
    Print_Types_struct_type (me);
  }
}

/**************/

/* Generate the Root.h and Root.c modules */
void PrintTypes (front f, Types types_root, List_struct_type types)
{
  Abbrev ("\n/* Abbreviations for %s */\n\n", append_string (Rootstr, ".h"));
  All_Enums = Types_enums(types_root);
  
  Types_print_actions.action_struct_type[PRE_ACTION] = print_struct_type;
  
  print_types_def  (f, types_root, types);
  print_types_impl (f, types_root, types);
  
}
