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
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include <front/mem.h>
#include <front/text.h>
#include "frontPrint.h"
#include "Types_parse.h"
#include "GenGrammar.h"
#include "flags.h"

static field add_create (field f, String init);
static field add_expr (field f, List_FieldInit i, Bool trav, Bool clear, Bool dont_clear);
static field rename_field (field f, Ident id);
static field retype_field (field f, List_TypeName type);
static field add_field_defining (field f, Symbol def);
static field add_field_applied  (field f, Symbol app, Ident id);
static struct_type set_scope   (struct_type t, Alternative alt);
static Bool empty_struct (struct_type t);
static struct_type set_checks (struct_type t, List_Check c);
static struct_type set_type_props (struct_type t, struct_type s);
static List_field set_sym_fields (Symbol s, List_field f);
static List_field set_rhs_fields (Rhs r,    List_field f);
static field field_set_grammar (field f, Ident grammar);
static List_field add_compare (List_field l, Ident c);
static void add_extra_type (field f);
static BindType find_bind (Ident id);

NonTerminal Rootsym;	/* Root of the grammar */
Ident Rootid;		/* Name of the root of the grammar */
String Rootstr;		/* Name of the root of the grammar */

#define user()	user_fields ? Rootid : NULL

#include "front_doggy.h"
#include "Types_doggy.h"
#include "Types_doggy.c"

static List_subtypedef subtypes = NULL;		/* all subtype types */
static List_subtypedef imptypes = NULL;		/* all imported types */
static List_EnumType enums = NULL;		/* all enum types */
static List_struct_type all_types = NULL;	/* all pointer types */
static List_struct_type lists = NULL;		/* all list+optional types */
static List_BindType binds = NULL;		/* All Bind types */
static FILE *abbrev_file = NULL;
static hash_t abbreviations = NULL;


/********** Identifier lists ***********/

/* Extend l with id */
void insert_id (List_Ident *l, Ident id)
{
  if (*l == NULL) *l = Create_List_Ident (id, NULL);
  if (List_Ident_data(*l) == id) return;
  insert_id (&List_Ident_next(*l), id);
}

/* Find id in  l */
Bool contains_id (List_Ident l, Ident id)
{
  for (; l; l = List_Ident_next(l)) {
    if (List_Ident_data(l) == id) return TRUE;
  }
  return FALSE;
}

/********** Print support functions ***********/
void PF(char *fmt, ...)
{
  va_list args;
  va_start (args, fmt);
  vfprintf (print_file, fmt, args);
  va_end (args);
}

void open_abbrev(char *file)
{
  abbrev_file = fopen (append_string(file,".h"), "wb");
  if(!abbrev_file) {
    FrontFatalError ("Cannot open file %s\n", file);
  }
  Abbrev ("#ifndef %s_NO_DEFS\n", Rootstr);
  Abbrev ("#define _%s_h\n\n", Rootstr);
}

void close_abbrev(void)
{
  Abbrev ("#endif /* %s_NO_DEFS */\n\n", Rootstr);
  fclose (abbrev_file);
}

void Abbrev(char *fmt, ...)
{
  va_list args;
  va_start (args, fmt);
  if (abbrev_file) vfprintf (abbrev_file, fmt, args);
  va_end (args);
}


void print_std_include (String f)
{ PF ("#include <%s.h>\n", f);
}

void print_include (String f)
{ PF ("#include \"front/%s.h\"\n", f);
}

static void
init_abbreviations(void)
{
  if(abbreviations) return;
  abbreviations = Front_Make_hash_table ((void*)Front_Hash_function,
                                         (void*)Front_cmp_identifier);
}

static identifier
find_abbreviation (const char *s)
{ 
  return Front_Find_in_hash_table(abbreviations, (hash_val)s);
}

String
vdef_abbrevf(String pre, String abbrev, String full, String post, va_list args)
{
  identifier id;
  String result;
  String name;
  
  if(!full || !*full) return full;
  if(!abbrev || !*abbrev) return abbrev;
  result = Front_StrAllocf("%s%s%s", pre, full, post);
  result = Front_vStrAllocf(result, args);
  name = Front_StrAllocf("%s%s%s", pre, abbrev, post);
  name = Front_vStrAllocf(name, args);
  
  init_abbreviations ();
  id = find_abbreviation (name);
  if (id == NULL) {
    id = FE_NEW (identifier);
    _IDENT_STRING(id) = name;
    _IDENT_INFO(id)   = result;
    Front_Add_in_hash_table (abbreviations, (hash_val)name, id);
    Abbrev ("#ifndef %s\n", name);
    Abbrev ("#define %s %s\n", name, result);
    Abbrev ("#endif\n");
  } else {
    assert (strcmp (result, _IDENT_INFO(id))==0);
  }
  return result;
}

String
def_abbrevf(String pre, String abbrev, String full, String post, ...)
{
  char *result;
  va_list args;
  va_start (args, post);
  result = vdef_abbrevf (pre, abbrev, full, post, args);
  va_end (args);
  return result;
}

String
vabbreviatef(String pre, String s, String post, va_list args)
{
  return vdef_abbrevf(pre,s, prefix_string(s),post,args);
}

String
abbreviatef(String pre, String s, String post, ...)
{
  char *result;
  va_list args;
  va_start (args, post);
  result = vabbreviatef (pre, s, post, args);
  va_end (args);
  return result;
}

String
abbreviate(String s)
{
  return abbreviatef ("", s, "");
}

Ident
abbreviate_id(String pre, Ident id, String post)
{
  if (!id) return NULL;
  return Create_Ident (abbreviatef (pre, Ident_name (id), post));
}

/* return prefix_s */
String prefix_string (String s)
{
  assert (prefix);
  return Front_StrAllocf("%s_%s", prefix, s);
}

TypeName make_TypeName(Ident id, Ident full)
{
  TypeName result = Create_TypeName(no_srcinfo, id);
  
  if(full) TypeName_full (result) = full;
  return result;
}

/* Check whether t contains a field with name f */
Bool contains_field (struct_type t, Ident f)
{ List_field l;

  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    field g = List_field_data(l);
    if (field_id(g) == f) return TRUE;
  }
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    field g = List_field_data(l);
    if (field_id(g) == f) return TRUE;
  }
  return FALSE;
}

/* Get the type of a field */
TypeName get_field_type (field f)
{
  List_TypeName l = field_type(f);
  if (l==NULL) return NULL;
  return List_TypeName_data(l);
}

/* Print the typename of the (sub-)type that contains field f */
void print_field_type (field f, struct_type t)
{
  if (contains_field (t, field_id(f))) {
    PF ("%s", Type_str(t));
    return;
  }
  print_field_type (f, Super_type(t));
}

/* Print an access to field f. */
void field_access (struct_type t, field f, String v)
{
  print_field_type (f, t);
  PF ("_%s(%s)", Ident_name(field_id(f)), v);
}

/* Remove string-quotes front s */
String remove_quotes (String s)
{
  Int l = strlen(s)-1;
  
  s = fe_strdup (s);
  
  /* Remove quotes */
  if (s[0] == s[l] && (s[0] == '"' || s[0] == '\'')) {
    s[l] = 0;
    s++;
  }
  return s;
}

/***********/

/* Test for terminal type */
Bool TermType (Ident id)
{
  return id == Create_Ident ("Int") ||
         id == Create_Ident ("Hex") ||
         id == Create_Ident ("Oct") ||
         id == Create_Ident ("Bool") ||
         id == Create_Ident ("Char") ||
         id == Create_Ident ("String") ||
         id == Create_Ident ("Ident") ||
         id == Create_Ident ("Float");
}

Bool ListOfTermType (Ident id)
{
  return id == Create_Ident ("List_Int") ||
         id == Create_Ident ("List_Hex") ||
         id == Create_Ident ("List_Oct") ||
         id == Create_Ident ("List_Bool") ||
         id == Create_Ident ("List_Char") ||
         id == Create_Ident ("List_String") ||
         id == Create_Ident ("List_Ident") ||
         id == Create_Ident ("List_Float");
}

Bool OptionalTermType (Ident id)
{
  return id == Create_Ident ("Optional_Int") ||
         id == Create_Ident ("Optional_Hex") ||
         id == Create_Ident ("Optional_Oct") ||
         id == Create_Ident ("Optional_Bool") ||
         id == Create_Ident ("Optional_Char") ||
         id == Create_Ident ("Optional_String") ||
         id == Create_Ident ("Optional_Ident") ||
         id == Create_Ident ("Optional_Float");
}

static Bool Is_Bind (Ident id)
{
  struct_type t;
  if (id == Create_Ident ("Bind")) return TRUE;
  if (id == Create_Ident ("List_Bind")) return TRUE;
  t = find_type(id);
  if(t && struct_type_is_bind (t)) return TRUE;
  if(find_bind(id)) return TRUE;
  return FALSE;
}

/* Test for terminal type + Bind derivative */
Bool LibType (Ident id)
{
  return TermType(id) || Is_Bind(id);
}

/* Test for std list + optional types */
Bool Std_type (Ident id)
{
  return ( ListOfTermType(id) || OptionalTermType(id) || Is_Bind(id) );
}

/* Test if NULL is an element of t */
Bool Allows_nil (TypeName t)
{
  Ident id = TypeName_full(t);
  struct_type st = find_type (id);
  EnumType et = find_enumtype (id);
  
  if (et != NULL) return FALSE;
  if (st==NULL) st = TypeName_type(t);
  
  if (id == Create_Ident ("Int")) return FALSE;
  if (id == Create_Ident ("Hex")) return FALSE;
  if (id == Create_Ident ("Oct")) return FALSE;
  if (id == Create_Ident ("Bool")) return FALSE;
  if (id == Create_Ident ("Char")) return FALSE;
  if (id == Create_Ident ("Float")) return FALSE;
  if (id == Create_Ident ("List")) return TRUE;
  if (id == Create_Ident ("Optional")) return TRUE;
  if (st==NULL) return TRUE;
  return !no_fields(st);
}

/* Prefix the name of t */
Ident prefix_type (Ident id)
{
  if (id==NULL) return id;
  assert (prefix);
  if (LibType(id)) return id;
  return Create_Ident (prefix_string (Ident_name(id)));
}

/* Prefix the name of t */
void set_name (struct_type t)
{
  struct_type_tag(t) = prefix_type (struct_type_name (t));
  if (struct_type_id(t) != NULL) {
    struct_type_id(t) = struct_type_tag(t);
  }
}

/* Prefix the name of t */
void abbreviate_struct_type (struct_type t)
{
  def_abbrevf("",Ident_name (struct_type_name(t)),
              Ident_name (struct_type_tag(t)),"");
}

/* Prefix the name of e */
void enum_set_name (EnumType e)
{
  abbreviate_id ("NUM_", EnumType_id(e), "");
  EnumType_id(e) = abbreviate_id ("",EnumType_id(e),"");
  EnumType_tag(e) = EnumType_str(e) = EnumType_id(e);
}

/* Original name */
String Type_name (struct_type t)
{ return Ident_name (struct_type_name(t));
}

/* Prefixed name */
Ident Type_ident (struct_type t)
{ return struct_type_tag(t);
}

/* Prefixed name */
String Type_str (struct_type t)
{ return Ident_name (struct_type_tag(t));
}

/* f uses scoping */
static field add_field_scope (field f)
{ field_uses_scope(f) = TRUE;
  return f;
}

/* f is defining for symbol s */
static field add_field_defining (field f, Symbol s)
{ field_is_defining(f) = s;
  add_field_scope(f);
  return f;
}

/* f is applied for symbol s */
static field add_field_applied (field f, Symbol s, Ident id)
{ field_is_applied(f) = s;
  field_applied_id(f) = id;
  add_field_scope(f);
  return f;
}

/* Print e to a string */
String expr_to_string (Expr e)
{ char s[1024];
  FILE *pf = print_file;
  open_print_string (s, TRUE);
  Print_Expr(e);
  close_print_string();
  print_file = pf;
  return fe_strdup(s);
}

List_FieldInit
default_field_init(void)
{
  return Create_List_FieldInit (Create_WhenCreate(no_srcinfo, TRUE, NULL), NULL);
}

/* Add properties to field f */
static field add_expr (field f, List_FieldInit i, Bool trav, Bool clear, Bool dont_clear)
{ 
  field_init(f) = i;
  field_trav(f) = trav;
  field_clear(f) = clear;
  field_dont_clear(f) = dont_clear;
  return f;
}

static field
add_create (field f, String expr)
{
  if (expr) {
    FieldInit i = Parse_FieldInit (expr,0);
    field_init(f) = Create_List_FieldInit (i, field_init(f));
  }
  return f;
}

FieldInit
field_init_when(field  f, FieldInit_tag when)
{
  List_FieldInit is;
  
  for (is = field_init(f); is; is = List_FieldInit_next (is)) {
    FieldInit i = List_FieldInit_data (is);
    if (FieldInit_tag(i) == when) return i;
  }
  return NULL;
}

char *
field_expr_when(field  f, FieldInit_tag when)
{
  List_FieldInit is;
  
  for (is = field_init(f); is; is = List_FieldInit_next (is)) {
    FieldInit i = List_FieldInit_data (is);
    if (FieldInit_tag(i) == when) return Text_Expr (FieldInit_expr(i));
  }
  return NULL;
}

/* Copy a field to change its properties later */
static field copy_field (field f)
{ 
  field g = Create_field (no_srcinfo, NULL, NULL);
  *g = *f;
  return g;
}

/* Change the name of field f to id */
static field rename_field (field f, Ident id)
{ 
  field g = copy_field (f);
  field_id(g) = id;
  return g;
}

/* Change the type of f to type */
static field retype_field (field f, List_TypeName type)
{ 
  field g = copy_field (f);
  field_type(g) = type;
  return g;
}

/* Add scoping properties in l to type t */
static struct_type scoping (List_Scoping l, struct_type t)
{ Scoping s;
  if (l==NULL) return t;
  s = List_Scoping_data(l);
  struct_type_uses_scope(t) = TRUE;
  if (s == NewScope || s == OpenScope) struct_type_opens_scope(t) = TRUE;
  if (s == NewScope || s == CloseScope) struct_type_closes_scope(t) = TRUE;
  return t;
}

/* Type t uses scoping */
static struct_type scope_sym (Symbol s, struct_type t)
{ NOT_USED(s);
  struct_type_uses_scope(t) = TRUE;
  return t;
}

/* Traverse the alternative alt to set scoping properties in its type t.
   Also, make t and alt point to each other.
*/
static struct_type set_scope (struct_type t, Alternative alt)
{
  static struct s_front_TraverseTable scope_actions;
  scope_actions.action_AppliedSym[PRE_ACTION] = (void*)scope_sym;
  scope_actions.action_DefiningSym[PRE_ACTION] = (void*)scope_sym;
  
  if (t==NULL) return t;

  if (Alternative_tag(alt) != UnLabeledAlt_kind) {
    Rhs rhs = LabeledAlt_rhs(alt);
    scoping (Rhs_sc(rhs), t); 
  }
  Traverse_Alternative (alt, &scope_actions, t);
  struct_type_alt(t) = alt;
  Alternative_type(alt) = t;
  return t;
}

/* Fill in checks in t */
static struct_type set_checks (struct_type t, List_Check c)
{ 
  struct_type_checks(t) = c;
  return t;
}

/* Fill in props of s in t */
static struct_type set_type_props (struct_type t, struct_type s)
{ 
  struct_type_checks(t) = struct_type_checks(s);
  struct_type_is_list(t) |= struct_type_is_list(s);
  struct_type_is_optional(t) |= struct_type_is_optional(s);
  struct_type_is_scope(t) |= struct_type_is_scope(s);
  struct_type_uses_scope(t) |= struct_type_uses_scope(s);
  struct_type_opens_scope(t) |= struct_type_opens_scope(s);
  struct_type_closes_scope(t) |= struct_type_closes_scope(s);
  struct_type_in_lib(t) |= struct_type_in_lib(s);
  if (struct_type_user(t)==NULL) struct_type_user(t) = struct_type_user(s);
  if (struct_type_alt(t)==NULL) {
    struct_type_alt(t) = struct_type_alt(s);
    Alternative_type(struct_type_alt(t)) = t;
  }
  return t;
}

static field field_set_grammar (field f, Ident grammar)
{
  field_grammar_id (f) = grammar;
  return f;
}

/* Fill in fields f in Symbol s */
static List_field set_sym_fields (Symbol s, List_field f) 
{
  if (s) Symbol_fields(s) = f;
  return f;
}

/* Fill in fields f in Rhs r */
static List_field set_rhs_fields (Rhs r, List_field f)
{ 
  if (r != NULL) Rhs_fields(r) = f;
  return f;
}

/* Fill in compare ident c in field in m */
static List_field add_compare (List_field m, Ident c)
{ List_field l;
  for (l = m; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    field_compare(f) = c;
  }
  return m;
}

/* Tests for scope opening within t */
Bool opens_scope (struct_type t)
{
  List_struct_type l;
  if (t==NULL) return FALSE;
  if (struct_type_opens_scope(t)) return TRUE;
  if (struct_type_sub_types(t) == NULL) return FALSE;
  for (l = struct_type_sub_types(t); l; l = List_struct_type_next(l)) {
   if (opens_scope (List_struct_type_data(l))) return TRUE;
  }
  return FALSE;
}

/* Tests for scope closing within t */
Bool closes_scope (struct_type t)
{
  List_struct_type l;
  if (t==NULL) return FALSE;
  if (struct_type_closes_scope(t)) return TRUE;
  if (struct_type_sub_types(t) == NULL) return FALSE;
  for (l = struct_type_sub_types(t); l; l = List_struct_type_next(l)) {
   if (closes_scope (List_struct_type_data(l))) return TRUE;
  }
  return FALSE;
}

/* Tests for scope usage within t */
Bool uses_scope (struct_type t)
{
  List_struct_type l;
  if (t==NULL) return FALSE;
  if (scope) return TRUE;
  if (struct_type_uses_scope(t)) return TRUE;
  if (struct_type_sub_types(t) == NULL) return FALSE;
  for (l = struct_type_sub_types(t); l; l = List_struct_type_next(l)) {
   if (uses_scope (List_struct_type_data(l))) return TRUE;
  }
  return FALSE;
}

/* Test for memo type */
Bool is_memo (struct_type t)
{
  Alternative a = struct_type_alt(t);
  return a!=NULL && Alternative_tag(a) == LabeledAlt_kind && LabeledAlt_meemo(a);
}

/* Test for skip_children default */
Bool is_skip (struct_type t)
{
  Alternative a = struct_type_alt(t);
  return a!=NULL && Alternative_tag(a) == LabeledAlt_kind && LabeledAlt_skip(a);
}

/* A memo type with unnamed members is encoded as an int */
Bool enum_is_int (EnumType t)
{
  List_TypeName l;
  
  if(t==NULL) return FALSE;
  if (EnumType_enums(t) == NULL) return TRUE;

  for (l = EnumType_enums(t); l; l = List_Ident_next(l)) {
    TypeName tn = List_TypeName_data(l);
    if (tn == NULL || TypeName_id(tn) == Create_Ident ("")) return TRUE;
  }
  return FALSE;
}

/* A memo type with unnamed members and at most 2 members is encoded as a Bool */
Bool enum_is_bool (EnumType t)
{
  return enum_is_int(t) && List_Ident_size(EnumType_enums(t)) <= 2;
}

/* Find the enum value of a in type r, a is an UnLabeledAlt. */
Bool enum_val (struct_type r, Alternative a, Int *i)
{
  List_struct_type l;
  
  if (struct_type_alt(r)==a) return TRUE;
  
  for (l = struct_type_sub_types(r); l; l = List_struct_type_next(l)) {
    if (enum_val (List_struct_type_data(l), a, i)) return TRUE;
  }
  
  if (struct_type_sub_types(r)==NULL) (*i)++;
  return FALSE;
}

/*******************/

/* Create type Optional_f */
static struct_type CreateOptionalType (TypeName tn)
{ List_struct_type l;
  struct_type t;
  Ident name, id, f, s;
  List_field lf;

  f = TypeName_full(tn);
  s = TypeName_id(tn);
  id = Create_Ident (append_string ("Optional_", Ident_name(f)));
  name = Create_Ident (append_string ("Optional_", Ident_name(s)));
  
  for (l = lists; l; l = List_struct_type_next(l)) {
    t = List_struct_type_data(l);
    if (struct_type_tag(t) == id) return NULL;
  }
  lf = Parse_OPTMORE_field ("%Identsym data;", 1, f); 
  t  = Create_struct_type (no_srcinfo, name, NULL, lf, NULL, NULL, NULL);
  struct_type_is_optional(t) = TRUE;
  struct_type_tag(t) = id;
  lists = Create_List_struct_type (t, lists);
  struct_type_in_lib(t) = LibType (f);
  return t;
}

/* Create type List_f */
static struct_type CreateListType (TypeName tn)
{ List_struct_type l;
  struct_type t;
  Ident name, lst, elt, id;
  List_field lf;

  elt = TypeName_full(tn);
  id = TypeName_id(tn);
  lst = Create_Ident (def_abbrevf("List_",Ident_name(id),Ident_name(elt),""));
  name = Create_Ident (append_string ("List_", Ident_name(id)));
  
  for (l = lists; l; l = List_struct_type_next(l)) {
    t = List_struct_type_data(l);
    if (struct_type_tag(t) == lst) return NULL;
  }
  lf = Parse_OPTMORE_field ("%TypeName data; %TypeName next;", 2,
                           make_TypeName(id,elt),
                           make_TypeName(name,lst)); 
  t  = Create_struct_type (no_srcinfo, name, NULL, lf, NULL, NULL, NULL);
  struct_type_is_list(t) = TRUE;
  struct_type_is_bind(t) = Is_Bind(elt);
  struct_type_tag(t) = lst;
  lists = Create_List_struct_type (t, lists);
  struct_type_in_lib(t) = LibType (elt);
  return t;
}

/* Create type Bind_f */
static BindType CreateBindType (TypeName tn)
{ List_BindType l;
  BindType t;
  Ident f, s;
  static Int num = 0;

  f = TypeName_full(tn);
  s = TypeName_id(tn);
  if (LibType (f)) return NULL;
  
  for (l = binds; l; l = List_struct_type_next(l)) {
    t = List_struct_type_data(l);
    if (BindType_id1(t) == f) return NULL;
  }
  def_abbrevf("Bind_", Ident_name(s), Ident_name(f), "");
  t= Create_BindType (no_srcinfo, f,f,f,f,f,f,f, num++);
  BindType_abbrev(t) = s;
  binds = Create_List_BindType (t, binds);
  return t;
}

/* Concatenate l into one type name */
TypeName glue_type_name (List_TypeName l)
{ 
  Ident id, full;
  TypeName tail;
  
  if (l==NULL) return NULL;
  tail = glue_type_name (List_TypeName_next(l));
  id   = TypeName_id (List_TypeName_data(l));
  full = TypeName_full (List_TypeName_data(l));
  if (tail==NULL) return make_TypeName(id, full);
  assert (id==full);
  return make_TypeName (Create_Ident (Front_StrAllocf ("%s_%s",
                                                       Ident_name(id),
                                                       Ident_name (TypeName_id(tail)))),
                        Create_Ident (Front_StrAllocf ("%s_%s",
                                                       Ident_name(id),
                                                       Ident_name(TypeName_full(tail)))));
}

/* Concatenate l into one identifier */
Ident glue_type (List_TypeName l)
{
  TypeName t = glue_type_name(l);
  if (t==NULL) return NULL;
  return TypeName_id (t);
}

/* Concatenate l into one identifier */
Ident full_glue_type (List_TypeName l)
{
  TypeName t = glue_type_name(l);
  if (t==NULL) return NULL;
  return TypeName_full (t);
}

static Ident the_id; /* Used in traversal */

/* Find the type with name the_id */
static struct_type find_type_action (struct_type t, struct_type u)
{
  if (struct_type_tag(t) == the_id) return t;
  return u;
}

/* Find the type with name id */
struct_type find_type (Ident id)
{
  static struct s_Types_TraverseTable tab;
  tab.action_struct_type[PRE_ACTION] = (void*)find_type_action;
  
  the_id = id;
  return (struct_type)Traverse_List_struct_type (all_types, &tab, NULL);

}
/* Find the bind with name the_id */
static BindType find_bind_action (BindType t, BindType u)
{
  Ident bind_id = Create_Ident (append_string ("Bind_", Ident_name(BindType_id1(t))));
  if (bind_id == the_id) return t;
  return u;
}

/* Name for binding of defining field */
Ident bind_id (field f)
{
  return Create_Ident(Front_StrAllocf("%s_%s", Ident_name(field_id(f)), "bind"));
}

/* Find the bind with name id */
static BindType find_bind (Ident id)
{
  static struct s_Types_TraverseTable tab;
  tab.action_BindType[PRE_ACTION] = (void*)find_bind_action;
  
  the_id = id;
  return (BindType)Traverse_List_BindType (binds, &tab, NULL);

}


/* Find id in  l */
Bool contains_tn (List_TypeName l, Ident id)
{
  for (; l; l = List_Ident_next(l)) {
    if (TypeName_id (List_TypeName_data (l)) == id) return TRUE;
  }
  return FALSE;
}

/* Find the enum type with name id */
EnumType find_enumtype (Ident id)
{
  List_EnumType l;
  
  for (l = enums; l; l = List_EnumType_next(l)) {
    EnumType e = List_EnumType_data(l);
    if (EnumType_id(e) == id) return e;
    if (contains_tn (EnumType_enums(e), id)) return e;
  }
  return NULL;
}

/* Find the enum type with name id */
subtypedef find_subtype (Ident id)
{
  List_subtypedef l;
  
  for (l = subtypes; l; l = List_subtypedef_next(l)) {
    subtypedef e = List_subtypedef_data(l);
    if (subtypedef_id(e) == id) return e;
  }
  return NULL;
}

/* Find a (sub-type) with field of name id */
struct_type find_field_type (struct_type t, Ident id)
{
  List_field l;
  List_struct_type m;
  
  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (field_id(f) == id) return t;
  }
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (field_id(f) == id) return t;
  }
  
  for (m = struct_type_sub_types(t); m; m = List_struct_type_next(m)) {
    struct_type s = find_field_type (List_struct_type_data(m), id);
    if (s != NULL) return s;
  }
  return NULL;
}

/* Fill in the TypeName_type for the head of l */
void set_type_struct (List_TypeName l)
{ 
  TypeName t;
  if (l==NULL) return;
  set_type_struct (List_TypeName_next(l));
  t = List_TypeName_data(l);
  if (TypeName_type(t) != NULL) return;
  TypeName_type(t) = find_type (TypeName_full(t));
}

/* Create an optional, list or bind type */
static void add_extra (Ident id, List_TypeName args)
{
  TypeName arg = glue_type_name(args);

  if(!args) return;
  add_extra (TypeName_full(List_TypeName_data(args)), List_TypeName_next(args));
  
  if (id == Create_Ident("List")) {
    CreateListType (arg);
    return;
  }
  if (id == Create_Ident("Bind")) {
    CreateBindType (arg);
    return;
  }
  if (id == Create_Ident("Optional")) {
    CreateOptionalType (arg);
    return;
  }
  assert (FALSE);
}

/* remove redundant optional types */
static List_TypeName _remove_optional (List_TypeName l)
{ TypeName t;
  if (l==NULL) return NULL;
  t = List_TypeName_data(l);
  l = _remove_optional(List_TypeName_next(l));
  if (TypeName_id(t) == Create_Ident("Optional") && 
      Allows_nil(List_TypeName_data(l))) return l;
  return Create_List_TypeName (t, l);
}

/* remove redundant optional types */
void remove_optional (field f)
{
  field_type(f) = _remove_optional(field_type(f));
}

/* Add extra type used by f */
static void add_extra_type (field f)
{
  List_TypeName types;
  
  remove_optional(f);
  
  types = field_type(f);
  if (List_TypeName_next(types) == NULL) return;
  add_extra (TypeName_full(List_TypeName_data(types)), List_TypeName_next(types));
}

/* Check for list type */
Bool is_list (TypeName t)
{
  String s = Ident_name (TypeName_id(t));
  return TypeName_id(t) == Create_Ident("List") ||
         strncmp (s, "List_", 5) == 0;
}

/* field f has list type */
Bool is_list_field (field f)
{
  return is_list (List_TypeName_data(field_type(f)));
}

/* Add extra types for f and then glue f's type into one identifier */
static void glue_field_type (field f)
{
  List_TypeName types;
  TypeName type;
    
  add_extra_type (f);
  types = field_type(f);
  if (List_TypeName_next(types) == NULL) return;
  type = glue_type_name (types);
  field_type(f) = Create_List_TypeName (type, NULL);
}

/* Add extra types for fields of s */
static void add_symbol_types (Symbol s)
{
  List_field l;
  if (s == NULL) return;
  
  for (l = Symbol_fields(s); l; l = List_field_next(l)) {
    add_extra_type (List_field_data(l));
  }
}

/* Make StructType for each element of l */
static List_StructType make_structs (List_struct_type l)
{
  struct_type t;
  Ident id;
  StructType s;
  
  if (l==NULL) return NULL;
  t = List_struct_type_data(l);
  id = struct_type_tag(t);
  s = Create_StructType (no_srcinfo, id, id, t, NULL, NULL, id);
  return Create_List_StructType (s, make_structs (List_struct_type_next(l)));
}

static NonTerminal retrieve_nt (Ident id)
{ Bind_front_NonTerminal b = Retrieve_Bind (id, NULL, front_DefaultNameSpace, Bind_front_NonTerminal_kind);
  if (b==NULL) return NULL;
  return Bind_object(b);
}

Bool
IsNonTerm(struct_type t)
{
  return retrieve_nt (struct_type_name (t))!=NULL;
}

static subtypedef Make_subtype (struct_type t)
{
  NonTerminal nt = retrieve_nt (struct_type_name(t));
  if (nt == NULL || NonTerminal_super(nt) == NULL) return NULL;
  if (!TermType(Super_id(NonTerminal_super(nt)))) return NULL;
  return Create_subtypedef (no_srcinfo, Super_id(NonTerminal_super(nt)), struct_type_tag(t));
}

/* Remove enum types from l and add them to enums */
List_struct_type Make_Enums (List_struct_type l)
{
  struct_type t;
  EnumType t1;
  List_struct_type tl;
  Ident id;
  subtypedef sub;
  
  if (l==NULL) return NULL;
  t = List_struct_type_data(l);
  id = struct_type_tag(t);
  tl = Make_Enums (List_struct_type_next(l));
  t1 = Make_Enum(t);
  sub = Make_subtype(t);
  if (t1) {
    enums = Create_List_EnumType(t1, enums);
    struct_type_enumtype(t) = t1;
    EnumType_str_type(t1) = t;
    return tl;
  } else if (sub) {
    subtypes = Create_List_subtypedef (sub, subtypes);
    return tl;
  } else {
    t1 = Make_Tag(t);
    if (t1) {
      EnumType_is_tag(t1) = TRUE;
      enums = Create_List_EnumType(t1, enums);
    }
  }
  return Create_List_struct_type (t, tl);
}

static Ident
import_typedef_Import (Import imp, Ident grammar)
{
  NOT_USED (grammar);
  return Import_grammar (imp);
}

static Ident
import_typedef (ImportedNonTerminal imp, Ident grammar)
{
  List_subtypedef sts;
  subtypedef sub;
  Ident iname, id = ImportedNonTerminal_type (imp);
  
  if (!id) id = ImportedNonTerminal_id (imp);
  iname = Create_Ident (Front_StrAllocf ("%s_%s",
                                       Ident_name (grammar),
                                       Ident_name (id)));
  id = Create_Ident (Front_StrAllocf ("%s_%s", prefix, Ident_name (id)));
  for (sts = imptypes; sts; sts = TAIL(sts)) {
    if (subtypedef_id (HEAD(sts))==id) return grammar;
  }
  sub = Create_subtypedef (no_srcinfo, iname, id);
  imptypes = Create_List_subtypedef (sub, imptypes);
  return grammar;
}

static List_subtypedef make_sub_types (List_struct_type l, Ident root, List_subtypedef s)
{
  for (; l; l = List_struct_type_next(l)) {
    struct_type t = List_struct_type_data(l);
    s = Create_List_subtypedef (Create_subtypedef(no_srcinfo, root, struct_type_tag(t)), s);
    s = make_sub_types (struct_type_sub_types(t), root, s);
  }
  return s;
}

/* Make PointerType for each element of l */
List_PointerType Make_Pointers (List_struct_type l)
{
  struct_type t;
  List_PointerType tl;
  PointerType t2;
  Ident id;
  
  if (l==NULL) return NULL;
  t = List_struct_type_data(l);
  id = struct_type_tag(t);
  tl = Make_Pointers (List_struct_type_next(l));
  if (struct_type_in_lib(t)) return tl;
  t2 = Create_PointerType (no_srcinfo, id, id, id, id, 
                           make_sub_types (struct_type_sub_types(t), id, NULL));
  struct_type_id(t) = NULL;
  return Create_List_PointerType (t2, tl);
}

/* The super type of type */
struct_type Super_type (struct_type t)
{
  if (t==NULL || struct_type_old_scope(t) == NULL) return t;
#ifdef Types_Scope_struct_type
  return Types_Scope_struct_type(struct_type_old_scope(t));
#else
  return struct_typeScope_data(struct_type_old_scope(t));
#endif
}

/* The root type of type */
struct_type Root_type (struct_type t)
{
  struct_type s = Super_type (t);
  if (s==t) return t;
  return Root_type (s);
}

/* Replace the type of f by its root type */
void set_root_type (TypeName f)
{
  struct_type t = TypeName_type(f);
  if (t==NULL) return;
  t = Root_type (t);
  TypeName_id(f) = struct_type_name(t);
  TypeName_full(f) = struct_type_tag(t);
}

/* Add a standard field with name id and type type and initial expression expr to t */
static field add_standard_field (struct_type t, String type, String id, String expr, Bool dont_clear)
{
  field f = Parse_field ("%Identsym %Identsym;", 2, Create_Ident(type), Create_Ident(id));
  add_create (f, expr);
  field_dont_clear(f) = dont_clear;
/*   field_generated(f) = TRUE; */
  if (struct_type_is_scope(t)) {
    FRONT_APPEND_NODE (struct_type_fields1(t), f);
  } else {
    struct_type_fields1(t) = Create_List_field (f, struct_type_fields1(t));
  }
  return f;
}

/* Check for emptiness (unnamed) of t */
static Bool empty_struct (struct_type t)
{
  Ident id = struct_type_id(t);
  return id == NULL || id == Create_Ident("");
}

/* Remove all unnamed structs from l */
static List_struct_type remove_empty_types (List_struct_type l, struct_type s)
{
  List_struct_type next;
  struct_type t;
  
  if (l == NULL) return l;
  t    = List_struct_type_data(l);
  next = List_struct_type_next(l);
  next = remove_empty_types (next, s);
  if (empty_struct(t)) return next;
  List_struct_type_next(l) = next;
  return l;
}

/* Remove unnamed subtypes */
static void clean_type (struct_type t)
{
  struct_type_sub_types(t) = remove_empty_types (struct_type_sub_types(t), t);
}

/* Add standard field to t, if appropriate.
   These are: src_info, memo_link, hook, old_scope, scope, tag
*/
static struct_type add_standard_fields (struct_type t, struct_type s)
{ 
  if (s != NULL) {
    /* sub-type */
    struct_type_user(t) = NULL;
    return t;
  }
  if (be_hook && !struct_type_is_scope(t) && 
      !struct_type_is_list(t) && 
      !struct_type_is_optional(t)) {
    String h = Front_StrAllocf("struct %s_hook*", Type_str(t));
    add_standard_field (t, h, "hook", "NULL", TRUE);
  }
  if (is_memo(t)) {
    String expr = Front_StrAllocf("%s_memo_link(me)", Type_str(t));
    add_standard_field (t, Type_str(t), "memo_link", expr, TRUE);
  }
  if (struct_type_sub_types(t)) {
    field f = add_standard_field (t, append_string (Type_str(t), "_tag"), "tag", "0", TRUE);
    field_is_tag(f) = TRUE;
  }
  if (uses_scope(t) || opens_scope(t)) {
    add_standard_field (t, abbreviate ("Scope"), "old_scope", "NULL", FALSE);
  }
  if (uses_scope(t) || opens_scope(t)) {
    add_standard_field (t, abbreviate ("Scope"), "scope", "NULL", FALSE);
  }
  if (!struct_type_is_scope(t) && 
      !struct_type_is_list(t) && 
      !struct_type_is_optional(t)) {
    if (uses_scope(t) || opens_scope(t)) {
      add_standard_field (t, "Int", "_num", "-1", TRUE);
    }
    add_standard_field (t, "SrcInfo", "src_info", NULL, TRUE);
  } else {
    struct_type_user(t) = NULL;
  }
  return t;
}

/* List of all field-access macros for the current type */
static List_macro macros; 

/* All tags for sub-types in s */
static List_Ident selectors (struct_type s)
{
  struct_type r = Super_type(s);
  if (r==s) return NULL;
  return FRONT_CONCAT_NODE (Ident, selectors (r), struct_type_tag(s));
}

/* For traversal */
static struct_type set_struct_type (struct_type t, struct_type s)
{ NOT_USED(s);
  return t;
}

/* Add a field-access macro for f within s.
   If f is src_info, also add loc and srcinfo macros.
*/
static struct_type add_field_macro (field f, struct_type s)
{ 
  macro m;
  
  if (s==NULL) return s;
  
  if (user_fields && !struct_type_is_list(s) && !struct_type_is_optional(s) && 
      !struct_type_is_scope(Root_type(s))) {
    m = Create_access_macro (no_srcinfo, struct_type_tag(s), field_id(f), Rootid, selectors(s), field_id(f));
  } else {
    m = Create_plain_macro (no_srcinfo, struct_type_tag(s), field_id(f), selectors(s), field_id(f));
  }
  def_abbrevf("", Type_name(s), Type_str(s), "_%s", Ident_name(field_id(f)));
  FRONT_APPEND_NODE (macros, m);
  if (field_id(f) == Create_Ident ("src_info")) {
    Ident id = Create_Ident ("srcinfo");
    List_Ident sel = selectors(s);
    Ident name = field_id(f);
    m = Create_plain_macro (no_srcinfo, struct_type_tag(s), id, sel, name);
    FRONT_APPEND_NODE (macros, m);
    def_abbrevf("", Type_name(s), Type_str(s), "_%s", Ident_name(id));
    
    id = Create_Ident ("loc");
    name = Create_Ident ("src_info->loc");
    m = Create_plain_macro (no_srcinfo, struct_type_tag(s), id, sel, name);
    FRONT_APPEND_NODE (macros, m);
    def_abbrevf("", Type_name(s), Type_str(s), "_%s", Ident_name(id));
  }
  return s;
}

/* Construct the list of arguments for a create function */
static List_field make_arg_fields (List_field m, List_field l)
{
  for (; m ; m = List_field_next(m)) {
    field f = List_field_data(m);
    
    if (field_init(f)) continue;
    FRONT_APPEND_NODE (l, f);
  }
  
  return l;
}

/* Construct the list of arguments for a create function */
static List_field arg_fields (struct_type t, List_field l, Bool pre)
{
  struct_type s = Super_type(t);

  if (pre) {
    if (s != t) l = arg_fields (s, l, pre);
    l = make_arg_fields (struct_type_fields1(t), l);
  } else {
    l = make_arg_fields (struct_type_fields2(t), l);
    if (s != t) l = arg_fields (s, l, pre);
  }
  
  return l;

}

static Bool
same_field_init (FieldInit i, FieldInit j)
{
  if (FieldInit_tag(i)!=FieldInit_tag(j)) return FALSE;
  return Traverse_compare_front_Expr (FieldInit_expr(i),
                                      FieldInit_expr(j),
                                      &front_compare_actions);
}

static Bool
same_field_inits (List_FieldInit is, List_FieldInit js)
{
  FieldInit i, j;
  
  if (!is || !js) return is==js;
  i = List_FieldInit_data(is);
  j = List_FieldInit_data(js);
  
  return ( same_field_init(i,j) &&
           same_field_inits (List_FieldInit_next(is),
                             List_FieldInit_next(js)) );
}

/* Compare f and g */
static Bool same_field (field f, field g)
{
  List_TypeName t1, t2;
  if (field_id(f) != field_id(g)) return FALSE;
  if (!same_field_inits (field_init(f), field_init(g))) return FALSE;
  for (t1 = field_type(f), t2 = field_type(g);
       t1 && t2;
       t1 = List_TypeName_next(t1), t2 = List_TypeName_next(t2)) {
    if (TypeName_id(List_TypeName_data(t1)) != TypeName_id(List_TypeName_data(t2))) return FALSE;
  }
  if (t1 != t2) return FALSE;
  return TRUE;
}

/* Check for f occurring in l */
static Bool has_field (List_field l, field f)
{
  if (l==NULL) return FALSE;
  return same_field (List_field_data(l), f) ||
         has_field  (List_field_next(l), f);
}

/* Compute common fields of l and m */
static List_field insersect_fields (List_field l, List_field m)
{
  List_field i;
  field f;
  if (l==NULL || m==NULL) return NULL;
  i = insersect_fields(List_field_next(l), m);
  f = List_field_data(l);
  if (has_field(m, f)) return Create_List_field (f, i);
  return i;
}

/* Compute common fields of f and fields of types in l */
static List_field common_fields (List_field f, List_struct_type l)
{ 
  struct_type t1;
  List_field f1;
  if (l==NULL || f == NULL) return f;
  t1 = List_struct_type_data(l);
  f1 = FRONT_CONCAT (field, struct_type_fields1(t1), struct_type_fields2(t1));
  f = insersect_fields (f, f1);
  return common_fields (f, List_struct_type_next(l));
}

/* Remove fields in f from l */
static List_field remove_common_fields (List_field f, List_field l)
{
  List_field next;
  if (l == NULL) return NULL;
  next = remove_common_fields (f, List_field_next(l));
  if (has_field (f, List_field_data(l))) return next;
  return Create_List_field (List_field_data(l), next);
}

/* Remove fields in f from all types in l */
static void remove_common (List_field f, List_struct_type l)
{
  struct_type t;
  if (l == NULL) return;
  t = List_struct_type_data (l);
  struct_type_fields1(t) = remove_common_fields (f, struct_type_fields1(t));
  struct_type_fields2(t) = remove_common_fields (f, struct_type_fields2(t));
  remove_common(f, List_struct_type_next(l));
}

/* Remove some special fields for defining and applied symbosl from l.
   These fields are not common fields and thus not moved to a super type.
*/
static List_field remove_special_fields (List_field l)
{
  field f;
  field g = NULL;
  List_field next;
  
  if (l==NULL) return NULL;
  f = List_field_data(l);
  next = List_field_next(l);
  if (next != NULL) g = List_field_data(next);
  
  if (field_is_defining(f)) {
    next = List_field_next(next);
    return remove_special_fields (next);
  }
  
  if (g != NULL && field_is_applied(g)) {
    if (AppliedSym_field(field_is_applied(g))== AppliedName) {
      /* id, bind, value */
      next = List_field_next(next);
      next = List_field_next(next);
      return remove_special_fields (next);
    } else {
      /* bind, value */
      next = List_field_next(next);
      next = List_field_next(next);
    }   
  }

  next = remove_special_fields(next);
  return Create_List_field (f, next);
}

/* Move common fields of sub-types to their super-type */
static void set_common_fields (struct_type t)
{
  List_struct_type l;
  List_field all, common;
  struct_type t1;
  
  if (struct_type_is_scope(t)) return;
  l = struct_type_sub_types(t);
  if (l==NULL) return;
  t1 = List_struct_type_data(l);
  all = FRONT_CONCAT (field, struct_type_fields1(t1), struct_type_fields2(t1));
  all = remove_special_fields (all);
  common = common_fields (all, List_struct_type_next(l));
  if (common == NULL) return;
  struct_type_fields1(t) = FRONT_CONCAT (field, struct_type_fields1(t), common);
  remove_common (common, l);
}

/* Construct the create function for a type */
static List_CreateFunction create_type (struct_type t, List_CreateFunction l)
{ 
  CreateFunction f;
  
  if (struct_type_sub_types(t) != NULL) return l;
  if (Std_type(struct_type_tag(t))) return l;
  f = Create_CreateFunction (no_srcinfo, 
                     arg_fields (t, arg_fields (t, NULL, TRUE), FALSE));
  CreateFunction_type(f) = t;
  struct_type_create(t) = f;
  return Create_List_CreateFunction (f, l);
}

/* add standard fields
   make create function
   move common fields
   make macros
*/
static void add_macros (List_StructType m)
{
  List_StructType l;
  
  static struct s_Types_TraverseTable std_field_actions;
  static struct s_Types_TraverseTable macro_actions;
  static struct s_Types_TraverseTable create_actions;
  static struct s_void_Types_TraverseTable common_fields_actions;

  std_field_actions.traversal = Traverse_Down;
  std_field_actions.action_struct_type[PRE_ACTION] = (void*)add_standard_fields;
  
  macro_actions.traversal = Traverse_Down;
  macro_actions.action_struct_type[PRE_ACTION] = (void*)set_struct_type;
  macro_actions.action_field[PRE_ACTION] = (void*)add_field_macro;

  create_actions.action_struct_type[POST_ACTION] = (void*)create_type;

  common_fields_actions.action_struct_type[POST_ACTION] = set_common_fields;

  for (l = m; l; l = List_StructType_next(l)) {
    StructType t = List_StructType_data(l);
    
    Traverse_StructType (t, &std_field_actions, NULL);
    StructType_creates(t) = Traverse_StructType (t, &create_actions, NULL);
    
    if (!no_share_fields) Traverse_void_StructType (t, &common_fields_actions);
    
    macros = NULL;
    Traverse_StructType (t, &macro_actions, NULL);
    StructType_macros(t) = macros;
  }

}

/* Add the scope sub-type for type t that opens a scope */
static List_struct_type make_sub_scope (struct_type t, List_struct_type scopes)
{
  struct_type s;
  field f;
  Ident id, tid, name;
  
  if (t==NULL) return scopes;
  if (!struct_type_opens_scope(t)) return scopes;
  tid = struct_type_name(t);
  id = Create_Ident ("data");
  f = make_field (tid, id, Rootid);
  name = Create_Ident (append_string (Type_name(t), "Scope"));
  id = abbreviate_id ("",name,"");
  s = Create_struct_type (no_srcinfo, name, NULL, Create_List_field(f,NULL), NULL, NULL, id);
  struct_type_tag(s) = id;
  struct_type_id(s) = id;
  return Create_List_struct_type (s, scopes);
}

/* Construct the Root_Scope type */
static List_struct_type make_scope (List_struct_type l)
{ 
  static struct s_Types_TraverseTable sub_scope_action;
  List_field fields = NULL;
  field f;
  struct_type scope;
  Ident id;
  List_struct_type sub_types;
  
  if (prefix == NULL) {
    id = Create_Ident (abbreviate ("Scope")); 
  } else {
    id = Create_Ident ("Scope"); 
  }
  f = make_field (id, Create_Ident ("next"), Rootid);
  FRONT_APPEND_NODE (fields, f);

  
  sub_scope_action.action_struct_type[POST_ACTION] = (void*)make_sub_scope;
  sub_types = Traverse_List_struct_type (l, &sub_scope_action, NULL);
  
  scope = Create_struct_type (no_srcinfo, id, user(), fields, sub_types, NULL, id);
  struct_type_is_scope (scope) = TRUE;
  add_standard_field (scope, "Int", "_self", "0", TRUE);
  add_standard_field (scope, "Int", "_end", "0", TRUE);
  FRONT_APPEND_NODE (l, scope);
  return l;
}

/* Find the start symbol */
static NonTerminal root_sym (List_NonTerminal l)
{
  NonTerminal r = NULL;
  for (; l; l = List_NonTerminal_next(l)) {
    NonTerminal n = List_NonTerminal_data(l);
    if (r==NULL || NonTerminal_is_root(n)) r = n;
  }
  return r;
}

/**************/

/* Compute the Types data structure for grammar f */
Types GenTypes (front f, List_struct_type *all_str_types)
{
  includes2 include_list = NULL;
  List_struct_type types = NULL;
  Types types_root;

  static struct s_front_TraverseTable nt_actions;
  static struct s_front_TraverseTable import_typedefs;
  static struct s_void_front_TraverseTable nt_actions2;
  static struct s_void_Types_TraverseTable root_type_actions;
  static struct s_void_Types_TraverseTable clean_type_actions;
  static struct s_void_Types_TraverseTable prefix_type_actions;
  
  nt_actions.action_NonTerminal[PRE_ACTION] = (void*)map_nonterm;

  import_typedefs.action_ImportedNonTerminal [PRE_ACTION] = (void*)import_typedef;
  import_typedefs.action_Import [PRE_ACTION] = (void*)import_typedef_Import;
  
  root_type_actions.action_TypeName[PRE_ACTION] = set_root_type;
  root_type_actions.action_field[POST_ACTION] = glue_field_type;
  clean_type_actions.action_struct_type[POST_ACTION] = clean_type;
  
  prefix_type_actions.action_struct_type[POST_ACTION] = abbreviate_struct_type;
  
  nt_actions2.action_Symbol[PRE_ACTION] = (void*)add_symbol_types;
  
  Rootsym = root_sym(front_rules(f));
  Rootid = NonTerminal_id(Rootsym);
  Rootstr = Ident_name (Rootid);
  if(!nocode) open_abbrev  (append_string (Rootstr, "_defs"));
  if(!prefix) prefix = Rootstr;
  
  if (multi_start) {
    include_list = Create_includes2 (no_srcinfo, Rootid, Rootid, front_uses(front_root));
  } else {
    include_list = Create_includes2 (no_srcinfo, NULL, Rootid, front_uses(front_root));
  }
  
  types = Traverse_front (f, &nt_actions, types);
  Traverse_front (f, &import_typedefs, NULL);
  types = make_scope (types);

  types = Make_Enums (types);
  
  /* Remove unnamed subtypes */
  Traverse_void_List_struct_type (types, &clean_type_actions);
  
  /* Prefix types */
  Traverse_void_List_struct_type (types, &prefix_type_actions);
  
  all_types = types;
  *all_str_types = types;

  types_root = Create_Types (no_srcinfo, enums, NULL, subtypes, include_list, imptypes,
                             NULL, prefix_type(Rootid), Rootid, make_structs(types));
  Decorate_Types (types_root);
  
  /* replace subtypes by their roots.
     add param types, like List and Bind 
  */
  Traverse_void_Types (types_root, &root_type_actions);
  Traverse_void_front (f, &nt_actions2);
  FRONT_APPEND(types, lists);
  Types_binds(types_root) = binds;
  
  Types_pointers(types_root) = Make_Pointers (types);
  Types_types(types_root) = make_structs(types);
  add_macros (Types_types(types_root));

  return types_root;
}
