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
#include <limits.h>
#include <string.h>
#include "flags.h"
#include "GenGrammar.h"
#include "GenLex.h"
#include "LalrPrint.h"
#include "GenTypes.h"
#include "GenLalr.h"
#include "frontPrint.h"
#include "TypesPrint.h"
#include <front/basic_types.h>
#include <front/parse_support.h>
#include <front/mem.h>
#include "GenLalr.h"
#include "print_lalr.h"

#define SUPPRESSED_CODE 0

static Int num_terminals;	/* Number of terminal symbols */
static Int num_symbols;		/* Number of all symbols */
static int num_set_elements; 	/* Number of element in a SymbolSet */

#ifndef COPY_List_Ident
#define COPY_List_Ident(x) Traverse_copy_List_Ident(x, &front_copy_actions)
#endif

static String Type_kind (field f, struct_type u);
static void optnull (field f, String a, String b);

/****************/

static ProdRule symbol_prod (LR_Symbol x)
{
  List_Production prods = LR_Symbol_prods(x);
  if (prods == NULL) return NULL;
  for (; prods; prods = List_Production_next(prods)) {
    Production p = List_Production_data(prods);
    if (Production_empty(p)) return Production_prod_rule(p);
  }
  prods = LR_Symbol_prods(x);
  return Production_prod_rule (List_Production_data(prods));
}

static NonTerminal symbol_nt (LR_Symbol x)
{
  ProdRule r = symbol_prod (x);
  if (r == NULL) return NULL;
  if (ProdRule_tag(r) != NT_Rule_kind) return NULL;
  return NT_Rule_nt(r);
}

/* Type name of the unique field of a symbol */
static String symbol_type (LR_Symbol x, Bool full)
{
  List_field l = LR_Symbol_fields(x);
  field f;
  
  NonTerminal nt = symbol_nt (x);
  Ident tid;
  if (nt && !is_macro(nt)) {
    nonterm_type (nt, NULL, &tid);
    return Ident_name(tid);
  }
  assert (List_field_size(l) == 1);
  f = List_field_data(l);
    remove_optional (f);
    return Ident_name (full_glue_type(field_type(f)));
}

/* Generate the enum value for symbol s */
static String symbol_name (LR_Symbol s)
{
  String id = Ident_name(LR_Symbol_id(s));
  return Front_StrAllocf("%s_value", id);
}

/* Generate the name for state s */
static String state_name (LR_state s)
{ LR_Symbol x = LR_state_start_state(s);
  if (x) {
    Ident tid = LR_Symbol_id(x);
    return abbreviatef ("Parse_state_", Ident_name(tid), "");
  } else {
    return Front_StrAllocf("Parse_state_%d", LR_state_num(s));
  }
}

/* Set of directors (first symbols) of state s */
static TermSet directors (LR_state s)
{
  TermSet f = NULL;
  List_Item l;
  
  for (l = LR_state_items(s); l; l = List_Item_next(l)) {
    Item i = List_Item_data(l);
    if (!is_kernel(i)) continue;
    f = term_unite (f, followers(Item_rhs2(i), NULL));
  }
  return f;
}

/* Set of followers for a transition under x to to state s 
   Done contains the symbols already handled.
   If level>0,  f is extended with additional symbols.
*/
static TermSet trans_followers (LR_state s, LR_Symbol x, List_Ident *done, TermSet f, Int level)
{
  Ident id = LR_Symbol_id(x);
  List_Item l;
  
  if (term_contains (*done, id)) return f;
  *done = Create_List_Ident (id, *done);
  
  for (l = LR_state_items(s); l; l = List_Item_next(l)) {
    Item i = List_Item_data(l);
    LR_Symbols rhs = Item_rhs2(i);
    if (rhs == NULL) continue;
    if (LR_Symbols_data(rhs) != x) continue;
    if (level != 0) f = term_unite (f, followers (LR_Symbols_next(rhs), NULL));
    if (is_kernel(i)) continue;
    f = trans_followers (s, make_lr_symbol(Item_lhs(i), NULL, FALSE), done, f, level+1);
  }
  return f;
}

/* Insert x into l */
static void insert_symbol_num (SymbolSet l, Int x)
{
  int set = x / BITSPERWORD;
  int i = x-set*BITSPERWORD;
  l[set] |= (1<<i);
}

/* Transform the TermSet l into a SymbolSet */
static SymbolSet make_symbol_set (TermSet l)
{ Int i;
  SymbolSet f = fe_malloc (sizeof(*f)*num_set_elements);
  
  for (i = 0; i < num_set_elements; i++) f[i] = 0;
  
  for (; l; l = List_Ident_next(l)) {
    Ident id = List_Ident_data(l);
    Bool hole = strncmp ("hole_", Ident_name(id), 5) == 0;
    LR_Symbol x;
    Int num;
    if (hole) id = Create_Ident (&Ident_name(id)[5]);
    x = make_lr_symbol(id, NULL, FALSE);
    if (!hole && !is_terminal(x)) continue;
    num = LR_Symbol_num(x);
    if (hole) num = LR_Symbol_hole_num(x);
    insert_symbol_num (f, num);
  }
  return f;
}

/****************/

/* Test whether l has fields */
static Bool rhs_has_fields (LR_Symbols l)
{
  for (; l; l = LR_Symbols_next(l)) {
    LR_Symbol x = LR_Symbols_data(l);
    if (LR_Symbol_fields(x) != NULL) return TRUE;
  }
  return FALSE;
}

/* Number of reductions in l */
static Int num_reductions (List_Item l)
{
  Item i;
  if (l == NULL) return 0;
  i = List_Item_data(l);
  if (!is_completed(i)) return num_reductions (List_Item_next(l));
  return 1 + num_reductions (List_Item_next(l));
}

/* Test whether s contains exactly one reduction */
static Bool one_reduction (LR_state s)
{
  LR_Symbol start = LR_state_start_state(s);
  Bool num_trans = List_Transition_size(LR_state_transitions(s));
  Bool num_items = List_Item_size (LR_state_items(s));

  return !start && num_trans == 0 && num_items == 1;
}

/* Test whether s contains exactly one transition */
static Bool one_transition (LR_state s)
{
  LR_Symbol start = LR_state_start_state(s);
  Bool num_trans = List_Transition_size(LR_state_transitions(s));
  Bool num_reduce = num_reductions (LR_state_items(s));

  return !start && num_trans == 1 && num_reduce == 0;
}

/* Test whether s uses look-ahead */
static Bool uses_look_ahead (LR_state s)
{
  if (one_reduction(s)) return FALSE;
  
  if (one_transition(s)) {
    Transition t = List_Transition_data(LR_state_transitions(s));
    LR_state target = Transition_target(t);
    LR_Symbol x = Transition_symbol(t);
    if (is_terminal(x) && LR_Symbol_fields(x) != NULL) return TRUE;
    if (!uses_look_ahead(target)) return FALSE;
  }
  
  return directors(s) != NULL;
}

/**************/

/* Print the symbol-set l */
static void gen_symbol_set (TermSet l)
{ Int i;
  SymbolSet f = make_symbol_set (l);
  
  NOT_USED(temp_parse_value);
  
  PF ("{ ");
  for (i = 0; i < num_set_elements; i++) {
    PF ("0x%x", f[i]);
    if (i < num_set_elements-1) PF (", ");
  }
  PF (" }");
}

/****************/

/* Push a value of type tn with generaric type 'type' */
static void push_action (String type, String value, String pre, String tn)
{
  PF ("%s      PUSH_PARSEVALUE(%s,%s,%s);\n", pre, type, value, tn);
}

/* Push non-values for all fields in l */
static void insert_fields (List_field l, String pre)
{
  for (; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    TypeName tn = glue_type_name(field_type(f));
    push_action (Type_kind(f, NULL), "0", pre, Ident_name(TypeName_full(tn)));
  }
}

/* Generate parse-time code for the void fields in l */
static void do_void_fields (List_Field l, String pre)
{
  for (; l; l = List_Field_next(l)) {
    Field f = List_Field_data(l);
    Ident t;
    if (f == NULL) continue;
    if (Field_when(f) == NULL) continue;
    t = Type_id(Field_type(f));
    if (t != Create_Ident("VOID")) continue;
    PF ("    %s", pre);
    Print_Expr(FieldInit_expr(Field_init_when(f,WhenCreate_kind)));
    PF (";\n");    
  }
}

/* Generate an insertion for an expected symbol x */
static void insert_symbol (LR_Symbol x)
{ List_Production ps;
  Production p = NULL;
  ProdRule r = NULL;
  List_Field fields = NULL;
  Bool macro = FALSE;
  
  ps = LR_Symbol_prods(x);
  if (ps != NULL && List_Production_next(ps) == NULL) p = List_Production_data(ps);
  if (p) r = Production_prod_rule(p);
  
  if (r && ProdRule_tag(r) == NT_Rule_kind) {
    /* Void fields may depend on normal fields */
    if (LR_Symbol_fields(x) == NULL) fields = NT_Rule_fields(r);
    macro = is_macro (NT_Rule_nt(r));
  }
  
  if (!can_be_empty(x)) {
    PF ("      InputError (SCAN_POSITION, TRUE, \"%s expected\");\n", Ident_name(LR_Symbol_id(x)));
  }
  insert_fields (LR_Symbol_fields(x), "");
  PF ("      ");
  if (is_terminal(x)) PF ("dont_shift = TRUE; ");
  PF ("_%s_symbol = %s_value; n = 0;\n", Rootstr, Ident_name(LR_Symbol_id(x)));

  if (macro) do_void_fields (fields, "  ");
}

/****************/

/* Abbreviation for type of field f that is a member of u */
static String Type_kind (field f, struct_type u)
{ struct_type t = NULL;
  TypeName tn = List_TypeName_data(field_type(f));
  Ident tid = TypeName_full(tn);
  EnumType e;
  subtypedef sub = find_subtype(tid);

  if (u) t = find_field_type (u, field_id(f));
  e = find_enumtype (tid);
  if (!t) t = find_type (tid);
  if (sub) {
    return Ident_name(subtypedef_super(sub));
  } else if (TermType(tid)) {
    return Ident_name(tid);
  } else if (e != NULL) {
    return "Int";
  } else if (t != NULL) {
    return Front_StrAllocf ("Pointer");
  } else {
    return "Pointer";
  }
}

static Int arg_num = 0;

/* Declare and pop the arguments of a Create function */
static void count_pop_arg (field f)
{
  Ident id = field_id(f);

  if (field_init(f) != NULL) return;
  if (id == NULL || id == Create_Ident("")) arg_num++;
}

/* Declare and pop the arguments of a Create function */
static void count_pop_arg2 (Symbol s)
{
  List_field l;
  
  for (l = get_fields(s); l; l = List_field_next(l)) {
    count_pop_arg (List_field_data(l));
  }
}

/* Declare and pop the arguments of a Create function */
static void pop_create_arg (field f, struct_type u, String n, Bool empty)
{
  TypeName tn = glue_type_name(field_type(f));
  Ident id = field_id(f);
  
  if (field_init(f) != NULL) return;
  
  PF ("        "); 
  Print_TypeName (glue_type_name(field_type(f))); 
  PF ("  "); 
  
  if (id == NULL || id == Create_Ident("")) PF ("_id_%d", --arg_num);
  else Print_Ident (id); 
  if (TypeName_id(tn) == Create_Ident("SrcInfo")) {
    PF (";\n");
    return;
  }
  if (empty) {
    PF ("%s = ", n); 
    if (f==0) PF ("FALSE");
    else PF ("NULL");
    PF (";\n"); 
  } else {
    PF ("%s = POP_PARSEVALUE (%s, %s);\n", n, Type_kind (f, u), Ident_name(TypeName_full(tn))); 
  }
}

/* Declare and pop the arguments of a Create function */
static void pop_create_arg2 (Symbol s, struct_type u, String n)
{
  List_field l;
  Bool empty = is_inlined_opt(s) && Symbol_empty(s);
#if 0
  PF ("/* %s %d */ ", symbolname(s), empty);
#endif
  for (l = (List_field)List_reverse((Front_List)get_fields(s)); l; l = List_field_next(l)) {
    pop_create_arg (List_field_data(l), u, n, empty);
  }
}

/* Declare and pop the arguments of a Create function */
static void _pop_create_args2 (List_Symbol l, struct_type u, String n)
{ if (l==NULL) return;
  
  count_pop_arg2    (List_Symbol_data(l));
  _pop_create_args2 (List_Symbol_next(l), u, n);
  pop_create_arg2   (List_Symbol_data(l), u, n);
}

/* Declare and pop the arguments of a Create function */
static void _pop_create_args (List_field l, List_Symbol syms, struct_type u, String n)
{ if (l==NULL) return;
  
  if (syms == NULL) {
    count_pop_arg    (List_field_data(l));
    _pop_create_args (List_field_next(l), NULL, u, n);
    pop_create_arg   (List_field_data(l), u, n, FALSE);
  } else {
    _pop_create_args2 (syms, u, n);
  }
}

/* Declare and pop the arguments of a Create function */
static void pop_create_args (List_field l, List_Symbol syms, struct_type u, String n)
{
  arg_num = 0;
  _pop_create_args (l, syms, u, n);
  assert (arg_num == 0);
}

/* Assign the src_info value */
static void set_srcinfo (List_field l, Bool type)
{
  field first;
  String t = "";
  
  if (l==NULL) return;
  if (type) t = "SrcInfo ";

  first = List_field_data(l);
  if (field_id(first) != Create_Ident("src_info")) return;
  l = List_field_next(l);
  if (l==NULL) {
    PF ("        %ssrc_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);\n", t);
  } else {
    PF ("        %ssrc_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);\n", t);
  }
}

/* Print the argument of a create function */
static String print_create_args (List_field l, String sep, Int *num)
{ 
  for (; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    Ident id = field_id(f);
    if (field_init(f) != NULL) continue;
    PF ("%s", sep);
    if (id == NULL || id == Create_Ident("")) PF ("_id_%d", (*num)++);
    else PF ("%s", Ident_name (field_id(f))); 
    sep = ", ";
  }
  return sep;
}

/* Print the argument of a create function */
static void print_create_args2 (List_Symbol l, String sep)
{ Int num = 0;

  if (strlen(sep)==0) PF ("src_info");
  sep = ", ";
  for (; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    sep = print_create_args (Symbol_fields(s), sep, &num);
  }
}

/* Push an enum value */
static void enum_action (EnumType e, Alternative a, struct_type t)
{
  Int i = 0;
  struct_type u = EnumType_str_type(e);
  String value;
  
  if (enum_is_bool(e)) {
    Bool ok = enum_val (u, a, &i);
    assert (ok);
    value = i==0 ? "FALSE" : "TRUE";
  } else if (enum_is_int(e)) {
    Bool ok = enum_val (u, a, &i);
    assert (ok);
    value = Front_StrAllocf ("%d", i);
  } else {
    value = Type_str(t);
  }
  push_action ("Int", value, "", Ident_name(EnumType_id(e)));
}

/* Push an subtype value */
static void subtype_action (subtypedef e, Alternative a, struct_type t)
{
  String value = Type_str(t);

  push_action (Ident_name(subtypedef_super(e)), value, "", 
               Ident_name(subtypedef_id(e)));
}

/* Create e new object and push it on the stack */
static void create_action (List_field fields, List_Symbol syms, NonTerminal nt, struct_type t, String tid, String cid, Bool si)
{ String sep = "";
  String type = "Pointer";
  subtypedef sub = find_subtype (Create_Ident(tid));
  Int num = 0;
  
  if (sub != NULL) {
    type = Ident_name (subtypedef_super(sub));
  }

  PF ("      { ParseValue me;\n");
  pop_create_args (fields, syms, t, "");
  set_srcinfo (fields, syms != NULL);
  PF ("        me = PushParseValue(\"%s\");\n", tid);
  PF ("        me->sub.%sValue = %s(", type, cid);
    if (si) {
      PF ("make_post_src_info(SCAN_POSITION, SCAN_END_POSITION)");
      sep = ", ";
    }
    if (syms) print_create_args2 (syms, sep);
    else print_create_args (fields, sep, &num);
    PF (");\n");
  if (NonTerminal_id(nt) == Rootid) {
    PF ("        Decorate_%s(me->sub.PointerValue);\n", Rootstr);
  }
  PF ("      }\n");
}

/* Semantic action for a non-terminal nt */
static void nt_action (NonTerminal nt, Alternative a, ProdRule p)
{
  struct_type t = NULL;
  struct_type r;
  EnumType e = NULL;
  CreateFunction f = NULL;
  List_field fields = NULL;
  String t_str;
  String cid;
  
  if (a != NULL) t = Alternative_type(a);
  if (t != NULL) {
    Ident tid;
    r = nonterm_type (nt, NULL, &tid);
    e = find_enumtype (tid);
    f = struct_type_create(t);
  }
    
  if (e != NULL) {
    /* Enum type, don't call Create function */
    enum_action (e, a, t);
    return;
  }
  
  if (t == NULL || f == NULL) {
    if (!no_nt_type(nt) || !no_nt_alts(nt)) {
      if (is_macro(nt)) do_void_fields (NT_Rule_fields(p), "");
      return;
    }
    fields = Rhs_fields(NonTerminal_rhs(nt));
    t_str = Ident_name(NonTerminal_id(nt));
    if (no_nt_type(nt)) {
      Super s = NonTerminal_super(nt);
      t_str = Ident_name(Super_id(s));
      if (!Std_type (Super_id(s)) && !TermType(Super_id(s))) {
        t_str = abbreviate (t_str);
      }
    }
    cid = Ident_name(NonTerminal_id(nt));
    create_action (fields, flatten_syms(NT_Rule_rhs(p)), nt, t, t_str, cid, TRUE);
    return;
  } else {
    t_str = Type_str(Root_type(t));
    cid = Front_StrAllocf ("Create_%s", Type_str(t));
  }
  
  if (f != NULL) {
    /* Alternative has a type with a create function f */
    fields = CreateFunction_fields(f);
  }
  
  create_action (fields, flatten_syms(NT_Rule_rhs(p)), nt, t, t_str, cid, FALSE);
}

/* Generate the null-value for an [A], FALSE or NULL */
static void optnull (field f, String a, String b)
{ NOT_USED(a); NOT_USED(b);
  if (f==NULL) push_action ("Bool", "FALSE", "  ", "Bool");
  else {
    List_TypeName tn = field_type(f);
    push_action ("Pointer", "NULL", "  ", Ident_name(full_glue_type(tn)));
  }
}

static String list_type (TypeName tn)
{
  return Front_StrAllocf ("List_%s", Ident_name(TypeName_full(tn)));
}

/* Generate the null-value for an {A}, 0 or NULL */
static void listnull (field f, String a, String b)
{ NOT_USED(a); NOT_USED(b);
  if (f==NULL) push_action ("Int", "0", "  ", "Int");
  else {
    TypeName tn = get_field_type(f);
    push_action ("Pointer", "NULL", "  ", list_type(tn));
  }
}

/* Generate the non-recursive-value for an {A}+ -> A */
static void rec (field f, String a, String b)
{ NOT_USED(a); 
  if (f==NULL) {
    push_action ("Int", b, "  ", "Int");
  } else {
    TypeName tn = get_field_type(f);
    push_action ("Pointer", b, "  ", list_type(tn));
  }
}

/* Generate the non-recursive-value for an ((A)) */
static void once (field f, String a, String b)
{ 
  List_TypeName tn = field_type(f);
  NOT_USED(b);
  push_action (Type_kind(f, NULL), a, "  ", Ident_name(full_glue_type(tn)));
}

/* Generate recursive value for [A] -> A */
static void opt (field f, String a, String b)
{ 
  NOT_USED(b);
  if (f==NULL) {
    push_action ("Bool", "TRUE", "  ", "Bool");
  } else if (Allows_nil (get_field_type(f))) {
    String t = Ident_name(full_glue_type(field_type(f)));
    push_action ("Pointer", a, "  ", t);
  } else {
    String t = Ident_name(full_glue_type(field_type(f)));
    String val = Front_StrAllocf("Create_Optional_%s(%s)", t, a);
    push_action ("Pointer", val, "  ", t);
  }
}

/* Generate recursive value for {A}+ -> A {A}+ */
static void more (field f, String a, String b)
{ 
  if (f==NULL) {
    String val = Front_StrAllocf("%s+1", b);
    push_action ("Int", val, "  ", "Int");
  } else {
    TypeName tn = get_field_type(f);
    String t = Ident_name(full_glue_type(field_type(f)));
    String val = Front_StrAllocf("Create_List_%s(%s,%s)", t, a, b);
    push_action ("Pointer", val, "  ", list_type(tn));
  }
}

/* Generate value for {A}+ -> A */
static void more_once (field f, String a, String b)
{ 
  NOT_USED(b);

  if (f==NULL) {
    push_action ("Int", "0", "  ", "Int");
  } else {
    TypeName tn = get_field_type(f);
    String t = Ident_name(full_glue_type(field_type(f)));
    String val = Front_StrAllocf("Create_List_%s(%s,NULL)", t, a);
    push_action ("Pointer", val, "  ", list_type(tn));
  }
}

/* Append s to the field names in f */
static List_field append_field_tag (List_field l, String s, String t, int n)
{
  
  if (l == NULL) return l;
  {
    field f = List_field_data(l);
    String id = Ident_name (field_id(f));
    TypeName tn = get_field_type(f);
    List_field next;
    if (strlen(id) == 0) id = Front_StrAllocf("_id_%d", n++);
    next = append_field_tag (List_field_next(l), s, t, n);
    
    s = Front_StrAllocf("%s%s", id, s);
    t = Front_StrAllocf("%s%s", t, Ident_name(full_glue_type(field_type(f))));
    f = Parse_field ("%Identsym %Identsym;", 2, Create_Ident(t), Create_Ident(s));
    return Create_List_field (f, next);
  }
}

/* Construct s.fi */
static String append_field (String s, String i)
{
  return Front_StrAllocf ("%s%s", s, i);
}

/* Print the attribute construction Symbol s, element of syms.
   syms occurs in an extra rule, e.g.
     A -> [ B | C ], then syms = A, B and s is either NULL, A or B.
   null is used to print if s==NULL, i.e for an epsilon rule.
   create is used for s!=NULL.
*/
static void print_extra_fields (Symbol s, List_Symbol syms, 
				void (*null) (field, String left, String right), 
				void (*create) (field, String left, String right))
{
  Int n = 0;
  List_Symbol l;
  List_field f;
    
  for (l = syms; l; l = List_Symbol_next(l)) {
    n += List_field_size (get_fields(List_Symbol_data(l)));
  }
  
  if (n==0) {
   if (create == once) return;
   if (s==NULL) null   (NULL, "", ""); 
   else         create (NULL, "", "");
   return;
  }
  
  n = 0;
  /* Traverse syms and pick out s, the active rhs.
     Call create for s and null for other elements of syms. 
  */
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol t = List_Symbol_data(l);
    List_Symbol m;
    for (m = flatten_sym (t); m; m = List_Symbol_next(m)) {
      Symbol u = List_Symbol_data(m);
      List_field fields = get_fields(u);
      for (f = fields; f; f = List_field_next(f)) {
	String left, right;
	Ident id = field_id(List_field_data(f));
	
	left = Ident_name(id);
	if (strlen(left)==0) left = Front_StrAllocf("_id_%d", n++);
	right = append_field (left, "_l");
	if (s != t) null   (List_field_data(f), left, right);
	else        create (List_field_data(f), left, right);
      }
    }
  }
}

/* Semantic action for ((s1|s2|...)) 
   Action for sj is generated, as determined by the production rule for item i
*/
static void once_action (List_Symbol syms, Item i)
{
  List_Symbol l;
  Production p = Item_production(i);
  Int n;
  
  PF ("      { /* once action */\n");
  for (l = syms, n=0; l; l = List_Symbol_next(l), n++) {
    Symbol s = List_Symbol_data(l);
    if (n != Production_num(p)) continue;
    pop_create_args (get_syms_fields(flatten_sym (s)), NULL, NULL, "");
  }
  for (l = syms, n=0; l; l = List_Symbol_next(l), n++) {
    Symbol s = List_Symbol_data(l);
    if (n != Production_num(p)) continue;
    if (List_Symbol_size(syms) == 1) {
      print_extra_fields (s, syms, optnull, once);
    } else {
      print_extra_fields (s, syms, optnull, opt);
    }
  }
  PF ("      }\n");
}

/* Semantic action for [s1|s2|...] 
   Action for sj is generated, as determined by the production rule for item i
*/
static void opt_action (List_Symbol syms, Item i)
{
  Bool empty = Item_rhs1(i) == NULL;
  List_Symbol l;
  Production p = Item_production(i);
  Int n;

  PF ("      { /* opt action */\n");
  if (empty) {
    print_extra_fields (NULL, syms, optnull, opt);
  } else {
    for (l = syms, n=1; l; l = List_Symbol_next(l), n++) {
      Symbol s = List_Symbol_data(l);
      if (n != Production_num(p)) continue;
      pop_create_args (get_syms_fields(flatten_sym (s)), NULL, NULL, "");
    }
    for (l = syms, n=1; l; l = List_Symbol_next(l), n++) {
      Symbol s = List_Symbol_data(l);
      if (n != Production_num(p)) continue;
      print_extra_fields (s, syms, optnull, opt);
    }
  }
  PF ("      }\n");
}

/* Semantic action for {s1|s2|...}+ 
   Action for sj is generated, as determined by the production rule for item i
*/
static void more_action (List_Symbol syms, Item i)
{
  List_Symbol l;
  Production p = Item_production(i);
  Int n;

  PF ("      { /* more action */\n");
  for (l = syms, n=0; l; l = List_Symbol_next(l), n++) {
    Symbol s = List_Symbol_data(l);
    
    if (n == Production_num(p)) {
      /*  MORE_A -> A */
      pop_create_args (get_syms_fields(flatten_sym (s)), NULL, NULL, "");
      break;
    }
    n++;
    if (n == Production_num(p)) {   
      /* MORE_A -> A MORE_A */
      List_field f = get_syms_fields(flatten_sym (s));
      f = FRONT_CONCAT(field, f, append_field_tag (f, "_l", "List_", 0));
      pop_create_args (f, NULL, NULL, "");
    }
  }
  for (l = syms, n=0; l; l = List_Symbol_next(l), n++) {
    Symbol s = List_Symbol_data(l);
    
    if (n == Production_num(p)) {
      /*  MORE_A -> A */
      print_extra_fields (s, syms, listnull, more_once);
      break;
    }
    n++;
    if (n == Production_num(p)) {   
      /* MORE_A -> A MORE_A */
      print_extra_fields (s, syms, rec, more);
    }
  }
  PF ("      }\n");
}

/* Semantic action for {s1|s2|...}
   Action for sj is generated, as determined by the production rule for item i
*/
static void optmore_action (List_Symbol syms, Item i)
{
  Bool empty = Item_rhs1(i) == NULL;
  List_Symbol l;
  Int n;
  
  PF ("      { /* optmore action */\n");
  if (empty) {
    /* OPTMORE_A -> eps */
    print_extra_fields (NULL, syms, listnull, more);
  } else {
    /* OPTMORE_A -> A OPTMORE_A */
    for (l = syms, n=1; l; l = List_Symbol_next(l), n++) {
      Symbol s = List_Symbol_data(l);
      List_field f = get_syms_fields(flatten_sym (s));
      f = FRONT_CONCAT(field, f, append_field_tag (f, "_l", "List_", 0));
      pop_create_args (f, NULL, NULL, "");
    }
    for (l = syms, n=1; l; l = List_Symbol_next(l), n++) {
      Symbol s = List_Symbol_data(l);
      print_extra_fields (s, syms, rec, more);
    }
  }
  PF ("      }\n");
}

/* Semantic action for a // b
   Action for first or second rule is generated, as determined by the production rule for item i
*/
static void alt_action (Symbol a, List_Symbol b, Item i)
{
  Symbol seq = Create_SymbolSeq (no_srcinfo, b, NULL, NULL);
  List_Symbol syms = Create_List_Symbol (a, Create_List_Symbol(seq, NULL));
  List_field f = NULL;
  Production p = Item_production(i);
  
  f = get_syms_fields(flatten_sym (seq));
  Symbol_fields(seq) = f;
  
  PF ("      { /* alt action */\n");
  if (Production_num(p) == 0) {
    /* ALT_A -> a */
    pop_create_args (get_syms_fields(flatten_sym (a)), NULL, NULL, "");
    print_extra_fields (a, syms, listnull, more_once);
  } else {
    /* ALT_A -> a b ALT_A */
    syms = Create_List_Symbol (a, b);
    seq = Create_SymbolSeq (no_srcinfo, syms, NULL, NULL);
    f = get_syms_fields(flatten_sym (seq));
    syms = Create_List_Symbol(seq, NULL);
    Symbol_fields(seq) = f;
    
    f = FRONT_CONCAT(field, f, append_field_tag (f, "_l", "List_", 0));
    pop_create_args (f, NULL, NULL, "");
    print_extra_fields (seq, syms, rec, more);
  }
  PF ("      }\n");
}

/* Semantic action extra rule p
   Action for sj is generated, as determined by the production rule for item i
*/
static void extra_action (ProdRule p, Item i)
{
  Symbol s = Extra_Rule_sym(p);
  
  if (!valid_extra(p)) return;
  
  switch (Symbol_tag(s)) {
  case OnceSymbol_kind: once_action (CompoundSym_sym(s), i); return;
  case OptSymbol_kind:  opt_action (CompoundSym_sym(s), i);  return;
  case MoreSymbol_kind: more_action (CompoundSym_sym(s), i); return;
  case OptMoreSymbol_kind: optmore_action (CompoundSym_sym(s), i); return;
  case AltSymbol_kind: alt_action (AltSymbol_syms1(s), AltSymbol_syms(s), i); return;
  default:
    break;
  }
}

/* Semantic action for completed item i */
static void semantic_action (Item i)
{
  Production p = Item_production(i);
  ProdRule r = Production_prod_rule(p);
  NonTerminal nt;
  
  if (r==NULL) return;
  
  switch (ProdRule_tag(r)) {
    case NT_Rule_kind:
      nt = NT_Rule_nt(r);
      nt_action (nt, NT_Rule_alt(r), r);
      break;
    case Extra_Rule_kind:
      extra_action (r, i);
  }
}

/**************/

/* Generate case entry for symbol x, possibly with hole.
   Suppress if x already in f.
*/
static Bool gen_case (LR_Symbol x, TermSet f, Bool hole)
{ Ident id = LR_Symbol_id(x);
  Bool ok = !term_contains (f, id);
#if !SUPPRESSED_CODE
  if (!ok) return ok;
#endif
  if (ok) PF ("   "); else PF (" /*");

  if (hole && LR_Symbol_hole(x)) {
    PF (" case hole_%s:", symbol_name(x));
    PF (" HOLE_ACTION (%d, \"%s\");\n", is_terminal(x), Ident_name(LR_Symbol_hole(x)));
    PF ("   ");
  }
  
  PF (" case %s:", symbol_name(x));

  if (ok) PF ("\n"); else PF (" */\n");
  return ok;
}

/* Generate case entries for symbos in l, possibly with hole.
   Suppress for those already in f.
*/
static Bool gen_cases (TermSet l, TermSet f)
{ Bool ok = FALSE;
  for (; l; l = List_Ident_next(l)) {
    Ident term = List_Ident_data(l);
    LR_Symbol x = make_lr_symbol (term, NULL, FALSE);
    ok |= gen_case (x, f, FALSE);
  }
  return TRUE;
}

/* Generate a reduce action for completed item i 
   done is the set of follower symbols already handled.
   do_case indicates the generation of case labels.
   In some cases, i can be handled by the default_item.
*/
static TermSet reduce_action (Item i, TermSet done, Bool do_case, Item default_item)
{ Int n = List_LR_state_size(Item_rhs1(i));
  Ident id = Item_lhs(i);
  TermSet f = Item_followers(i);
  Bool ok = TRUE;
  Bool move_to_default;
  
  if (!is_completed(i)) return done;
  if (Item_conflict(i)) return done;
  
#if 0
  PF ("  /* "); Print_Item (i); PF (" */\n");
  PF ("  /* "); Print_Item (default_item); PF (" */\n");
#endif
  /* See whether this case can be moved to the default action */
  move_to_default = i == default_item;
  if (default_item && !is_completed(default_item)) {
    LR_Symbol x = LR_Symbols_data(Item_rhs2(default_item));
    if (!rhs_has_fields (Item_rhs2(i))) {
      move_to_default |= id == LR_Symbol_id(x);
    }
  }
  if (move_to_default) {
    ok = FALSE;
    do_case = FALSE;
  }
  
  if (do_case) ok = gen_cases (f, done);

  { Item_followers(i) = NULL;
#if 0
    PF ("      /* reduce "); Print_Item (i); PF (" */\n");
#endif
    Item_followers(i) = f;
  }
  
  if (ok) {
    PF ("      n = %d; _%s_symbol = %s_value;\n", n, Rootstr, Ident_name(id));
    semantic_action (i);
    if (do_case) PF ("      break;\n");
  } else {
#if SUPPRESSED_CODE
    PF ("#if 0\n");
    PF ("      n = %d; _%s_symbol = %s_value;\n", n, Rootstr, Ident_name(id));
    semantic_action (i);
    if (do_case) PF ("      break;\n");
    PF ("#endif\n");
#endif
  }
  done = term_union (done, COPY_List_Ident(f));
  return done;
}

/* Generate a shift action for terminal x */
static void shift_action (LR_Symbol x)
{
  Ident id = LR_Symbol_id(x);
  if (LR_Symbol_fields(x) != NULL) {
    String type = symbol_type(x, FALSE);
    String value = Front_StrAllocf("%s_lval.%s_type", Rootstr, Ident_name(id));
    PF ("        if (!dont_shift)"); 
    push_action (type, value, "", type);
  }
  PF ("        if (!dont_shift) SHIFT(); dont_shift = FALSE;\n");
}

/* Recursive call to function for next state t */
static void goto_next_state (LR_state t, Bool followers)
{
  if (uses_look_ahead(t)) {
    PF ("        n = %s(%sfollowers);\n", state_name(t), followers?"_":"");
  } else {
    PF ("        n = %s();\n", state_name(t));
  }
}

/* Generate code for transition t from state 'state'
   done is the set of symbols already handled.
   do_case indicates the generation of case labels.
*/
static TermSet gen_transition (Transition t, TermSet done, LR_state state, Bool do_case)
{ LR_Symbol x = Transition_symbol(t);
  Ident id = LR_Symbol_id(x);
  Bool ok = TRUE;
  TermSet done2 = NULL;
  TermSet followers = trans_followers(state, Transition_symbol(t), &done2, NULL, 0);
  LR_state target = Transition_target(t);
  Bool shift_first;
  
  if (Transition_conflict(t)) return done;
  
  if (do_case) ok = gen_case (x, done, TRUE);

  if (!ok) PF ("    /*\n");
  
  PF ("      {\n");
  if (followers) {
    PF ("        static Int my_followers[] = "); 
    gen_symbol_set (followers);
    PF (";\n");
    PF ("        unite_symbol_sets (_followers, my_followers, followers, %d);\n", num_set_elements);
  }
  
  shift_first = is_terminal(x) && LR_Symbol_fields(x) != NULL;
  if (shift_first || uses_look_ahead(target)) {
    if (is_terminal(x)) shift_action (x);
    goto_next_state (target, followers!= NULL);
  } else {
    goto_next_state (target, followers!= NULL);
    if (is_terminal(x)) shift_action (x);
  }
  
  if (do_case) PF ("        break;\n");
  PF ("      }\n");
  
  if (!ok) PF ("    */\n");
  if (!term_contains (done, id)) done = Create_List_Ident (id, done);
  return done;
}

/* Generate an accept action for completed item i in a start state 
   done is the set of follower symbols already handled.
*/
static TermSet accept_action (Item i, TermSet done)
{
  Ident id = Item_lhs(i);
  Bool ok;
  
  if (!is_start(i)) return done;
  
  ok = gen_case (make_lr_symbol (id, NULL, FALSE), done, FALSE);
  if (ok) {
    PF ("      n = 1; break;");
    PF (" /* accept "); Print_Item (i); PF (" */\n");
  } else {
#if SUPPRESSED_CODE
    PF ("      /* n = 1; break; */");
    PF (" /* accept "); Print_Item (i); PF (" */\n");
#endif
  }
  FRONT_INSERT (id, done);
  return done;
}

/* Generate an insertion/reduction for the default item i */
static void insert_item (Item i)
{  
#if 1
  PF ("    /* default item:"); Print_Item(i); PF (" */\n");
#endif
    
  if (!is_completed(i)) {
    LR_Symbol x = LR_Symbols_data(Item_rhs2(i));
    ProdRule r = symbol_prod (x);
    NonTerminal nt = symbol_nt (x);
    List_field fields;
    PF ("/* nt = %p */\n", nt);
    if (nt == NULL) {
      insert_symbol(x);
    } else {
      fields = clean_fields (Rhs_fields (NonTerminal_rhs(nt)));
      if (fields != NULL) insert_symbol(x);
      else {
        PF ("      n = %d; _%s_symbol = %s;\n", 0, Rootstr, symbol_name(x));
        nt_action (nt, NT_Rule_alt(r), r);
      }
    }
  } else {
    reduce_action (i, NULL, FALSE, NULL);
  }
  PF ("      break;\n");
}

/**************/

/* Number of non-empty symbols in b for A -> a.b */
static Int item_size (Item i)
{ LR_Symbols l;
  Int size = 0;
  for (l = Item_rhs2(i); l; l = LR_Symbols_next(l)) {
    LR_Symbol x = LR_Symbols_data(l);
    if (!can_be_empty(x)) size++;
  }
  return size;
}

/* State has just one kernel item */
static Item single_item (LR_state state)
{ List_Item l;
  Item item = NULL;
  for (l = LR_state_items(state); l; l = List_Item_next(l)) {
    Item i = List_Item_data(l);
    if (!is_kernel(i)) continue;
    if (item != NULL) return NULL;
    item = i;
  }
  return item;
}

/* State has some completed kernel item */
static Item completed_kernel_item (LR_state state)
{ List_Item l;
  for (l = LR_state_items(state); l; l = List_Item_next(l)) {
    Item i = List_Item_data(l);
    if (!is_kernel(i)) continue;
    if (is_completed(i)) return i;
  }
  return NULL;
}

/* State has some empty kernel item */
static Item empty_kernel_item (LR_state state)
{ List_Item l;
  for (l = LR_state_items(state); l; l = List_Item_next(l)) {
    Item i = List_Item_data(l);
    if (!is_kernel(i)) continue;
    if (emptiness (Item_rhs2(i))) return i;
  }
  return NULL;
}

/* Return the kernel item with the shortest rhs */
static Item shortest_kernel_item (LR_state state)
{ List_Item l;
  Item item = NULL;
  Int size = INT_MAX;
  for (l = LR_state_items(state); l; l = List_Item_next(l)) {
    Item i = List_Item_data(l);
    if (!is_kernel(i)) continue;
    if (item_size(i) < size) {
      item = i;
      size = item_size(i);
    }
  }
  return item;
}

/* Return the default item for 'state' */
static Item default_item (LR_state state)
{ Item i;

  i = single_item(state);
  if (i != NULL) return i;
  i = completed_kernel_item(state);
  if (i != NULL) return i;
  i = empty_kernel_item(state);
  if (i != NULL) return i;
  return NULL;
}

/* Generate the default action for 'state' */
static void default_action (LR_state state)
{ Item i;

  i = default_item(state);
  if (i == NULL) {
    PF ("      InputError (SCAN_POSITION, TRUE, \"Syntax error\");\n");
    i = shortest_kernel_item(state);
  }
  insert_item (i);
}

/**************/

/* Generate the reduce actions and the transitions for 'state' */
static void gen_actions (LR_state state)
{
  List_Transition ts;
  List_Item is;
  TermSet terms = NULL;
  Item def_item = default_item (state);
  for (is = LR_state_items(state); is; is = List_Item_next(is)) {
    Item i = List_Item_data(is);
    terms = accept_action (i, terms);
    terms = reduce_action (i, terms, TRUE, def_item);
  }

  for (ts = LR_state_transitions(state); ts; ts = List_Transition_next(ts)) {
    Transition t = List_Transition_data(ts);
    terms = gen_transition (t, terms, state, TRUE);
  }
  
  for (is = LR_state_items(state); is; is = List_Item_next(is)) {
    break;
  }
}

/* Test whether s has transitions under a terminal symbol */
static Bool terminal_trans (LR_state s)
{ List_Transition l;
  for (l = LR_state_transitions(s); l; l = List_Transition_next(l)) {
    Transition t = List_Transition_data(l);
    LR_Symbol x = Transition_symbol(t);
    if (is_terminal(x)) return TRUE;
  }
  return FALSE;
}

/* Generate the header for the parse function for state s */
static void gen_header (LR_state s, Bool forward, Bool h_file);

/* Generate the parse function for state s, possible as inline function */
static void gen_function (LR_state s, Bool inl)
{ 
  LR_Symbol start = LR_state_start_state(s);
  Bool num_trans = List_Transition_size(LR_state_transitions(s));
  TermSet dirs = NULL;
  Bool look_ahead = uses_look_ahead (s);
  
  
  if (look_ahead) dirs = directors(s);
  if (look_ahead) { PF ("/* directors of state %d\n   ", LR_state_num(s)); print_terms (dirs); PF (" */\n"); }
  if (inl != (num_trans==0)) return;
  gen_header (s, FALSE, FALSE);
  PF ("{ int n;\n");
  if (terminal_trans(s)) PF ("  Bool dont_shift = FALSE;\n");
  
  if (one_reduction(s)) {
    /* Just one reduction */
    Item i = List_Item_data (LR_state_items(s));
    reduce_action (i, NULL, FALSE, NULL);
    PF ("  return n-1;\n");
    PF ("}\n\n");
    return;
  } 
  
  if (one_transition(s)) {
    /* Just one transition */
    Transition t = List_Transition_data (LR_state_transitions(s));
    if (look_ahead) PF ("  NOT_USED(followers);\n");
    gen_transition (t, NULL, s, FALSE);
    PF ("  return n-1;\n");
    PF ("}\n\n");
    return;
  } 

  if (dirs) {
    PF ("  static Int directors[%d] = ", num_set_elements); gen_symbol_set(dirs); PF (";\n");
    PF ("  Int _followers[%d];\n", num_set_elements);
  }
  if (start) {
    String eof = Front_StrAllocf("%s_EOF", Rootstr);
    List_Ident f = Create_List_Ident (Create_Ident(eof), NULL);
    LR_Symbol x = make_lr_symbol (Create_Ident(eof), NULL, FALSE);
    PF ("  Int followers[%d] = ", num_set_elements); gen_symbol_set(f); PF (";\n");
    PF ("  fill_terminal_map();\n");
    PF ("  SHIFT();\n");
  }
  if (dirs)  PF ("  unite_symbol_sets (_followers, followers, directors, %d);\n", num_set_elements);
  
  if (look_ahead) PF ("  DELETE_UNTIL (%sfollowers, %s);\n", dirs?"_":"", Rootstr);
  PF ("  _%s_symbol = _%s_token;\n", Rootstr, Rootstr);
  PF ("  do {\n");
  PF ("    REPORT(%d);\n", LR_state_num(s));
  PF ("    switch (_%s_symbol) {\n", Rootstr);
  gen_actions (s);
  PF ("    default:\n");
  default_action (s);
  PF ("    }\n");
  PF ("  } while (n==0);\n");
  if (start) {
    String type = "Pointer";
    String st = symbol_type (start, TRUE);
    subtypedef sub = find_subtype(Create_Ident(st));
    if (sub) type = Ident_name(subtypedef_super(sub));
    else if (find_enumtype(Create_Ident(st))) type = "Int";
    PF ("  return PopParseValue(\"%s\")->sub.%sValue;\n", st, type);
  } else {
    PF ("  return n-1;\n");
  }
  PF ("}\n\n");
}

/* Generate the header for the parse function for state s */
static void gen_header (LR_state s, Bool forward, Bool h_file)
{ 
  if (forward && LR_state_transitions(s) == NULL && !h_file) {
    PF ("\n");
    gen_function (s, TRUE);
  } else {
    LR_Symbol start = LR_state_start_state(s);
    if (start) {
      String type = symbol_type (start, FALSE);
      PF ("%s %s (void)", type, state_name(s));
    } else {
      String inl = "";
      if (h_file) return;
      if (LR_state_transitions(s) == NULL) inl = "__inline__ ";
      if (uses_look_ahead(s)) {
        PF ("static %sint %s (SymbolSet followers)", inl, state_name(s));
      } else {
        PF ("static %sint %s (void)", inl, state_name(s));
      }
    }
    if (forward) PF (";");
    PF ("\t/* state %d */\n", LR_state_num(s));
  }
}

/* Generate an enumeration type containing members for all symbols */
static void generate_symbol_enum (void)
{
  List_LR_Symbol syms;  
  Int num = 0;
  LR_Symbol s;
  
  PF ("typedef enum {\n");
  PF ("  %s_NONSENSE,\n", Rootstr); num++;
  
  for (syms = all_symbols; syms; syms = List_LR_Symbol_next(syms)) {
    s = List_LR_Symbol_data(syms);
    if (is_terminal(s)) {
      LR_Symbol_num(s) = num++;
      PF ("  %s,\n", symbol_name(s));
    }
    if (LR_Symbol_hole (s)) {
      LR_Symbol_hole_num(s) = num++;
      PF ("  hole_%s,\n",  symbol_name(s));
    }
  }
  s = make_lr_symbol (Create_Ident(Front_StrAllocf("%s_EOF", Rootstr)), NULL, FALSE);
  LR_Symbol_num(s) = num++;
  PF ("  %s,\n", symbol_name(s));
  
  num_terminals = num;
  num_set_elements = (num_terminals+BITSPERWORD-1)/BITSPERWORD;
  
  for (syms = all_symbols; syms; syms = List_LR_Symbol_next(syms)) {
    s = List_LR_Symbol_data(syms);
    if (!is_terminal(s)) {
      LR_Symbol_num(s) = num++;
      PF ("  %s,\n", symbol_name(s));
    }
  }

  num_symbols = num;
  
  PF ("  %s_ERROR\n",      Rootstr); num++;
  PF ("} %sSymbol;\n\n",   Rootstr);
  
  PF ("static %sSymbol _%s_token;\n\n", Rootstr, Rootstr);
  PF ("static %sSymbol _%s_symbol;\n\n", Rootstr, Rootstr);
  
  PF ("#define NUM_TERMINALS %d\n\n", num_terminals);
  PF ("#define WORDS_IN_SET ((NUM_TERMINALS+BITSPERWORD-1)/BITSPERWORD)\n\n", num_terminals);
}

/* Generate a table with names for all symbols */
static void generate_symbol_names (void)
{
  List_LR_Symbol syms;  
  LR_Symbol s;
  
  PF ("static String %s_symbol_names[] = {\n", Rootstr);
  PF ("  \"%s_NONSENSE\",\n", Rootstr);
  
  for (syms = all_symbols; syms; syms = List_LR_Symbol_next(syms)) {
    s = List_LR_Symbol_data(syms);
    
    if (is_terminal(s)) {
      PF ("  \"%s\",\n", Ident_name(LR_Symbol_id(s)));
    }
    if (LR_Symbol_hole (s)) {
      PF ("  \"hole_%s\",\n", Ident_name(LR_Symbol_id(s)));
    }
  }
  PF ("  \"%s_EOF\",\n", Rootstr);
  
  for (syms = all_symbols; syms; syms = List_LR_Symbol_next(syms)) {
    s = List_LR_Symbol_data(syms);
    if (!is_terminal(s)) {
      PF ("  \"%s\",\n", Ident_name(LR_Symbol_id(s)));
    }
  }
  
  PF ("  \"%s_ERROR\"\n",      Rootstr);
  PF ("};\n\n",   Rootstr);
}

/* Generate a table that translates Yacc symbol numbers into our enumeration values */
static void generate_terminal_map (void)
{
  List_LR_Symbol syms;  

  PF ("static %sSymbol %s_terminal_map[2*%s_ERROR];\n\n", Rootstr, Rootstr, Rootstr);
  
  PF ("static void fill_terminal_map (void)\n");
  PF ("{\n");
  PF ("  static Bool done = FALSE;\n");
  PF ("  if (done) return;\n");
  PF ("  done = TRUE;\n");
  
  PF ("  %s_terminal_map[0] = %s_NONSENSE;\n", Rootstr, Rootstr);
  for (syms = all_symbols; syms; syms = List_LR_Symbol_next(syms)) {
    LR_Symbol s = List_LR_Symbol_data(syms);
    Ident id = LR_Symbol_id(s);
    if (is_terminal(s)) {
      PF ("  %s_terminal_map[%s-NONSENSE] = %s;\n", Rootstr, Ident_name(id), symbol_name(s));
    }
    if (LR_Symbol_hole (s)) {
      PF ("  %s_terminal_map[hole_%s-NONSENSE] = hole_%s;\n", Rootstr, Ident_name(id),  symbol_name(s));
    }
  }
  PF ("}\n\n");
}

/**************/

/* Generate the parser header file */
static void generate_parser_def (Lalr lalr)
{
  List_LR_state l;
  
  PF ("#ifndef _%s_lalr_h\n", Rootstr);
  PF ("#define _%s_lalr_h\n\n", Rootstr);

  PF ("#include \"%s.h\"\n\n", Rootstr);
  PF ("#include <front/parse_support.h>\n\n", Rootstr);

  if (lalr) {
    for (l = Lalr_states(lalr); l; l = List_LR_state_next(l)) {
      gen_header (List_LR_state_data(l), TRUE, TRUE);
    }
  }
  
  PF ("\n");
  PF ("#endif /* _%s_lalr_h */\n", Rootstr);
}

/* Generate the recursive ascent parser */
static void generate_parser (Lalr lalr)
{
  List_LR_state l;
  
  PF ("#include \"%s_lalr.h\"\n\n", Rootstr);
  PF ("#include \"%s_y.h\"\n\n", Rootstr);

  if (lalr == NULL) return;
  
  generate_symbol_enum ();
  generate_symbol_names ();
  generate_terminal_map ();

  PF ("extern int %s_lex(void);\n", Rootstr, Rootstr);
  PF ("#define SHIFT() { _%s_token = %s_lex();", Rootstr, Rootstr);
  PF (" if (_%s_token==0) _%s_token = %s_EOF_value;", Rootstr, Rootstr, Rootstr);
  PF (" else _%s_token = %s_terminal_map[_%s_token-NONSENSE]; }\n", Rootstr, Rootstr, Rootstr);
  PF ("#define HOLE_ACTION(term,s) PUSH_PARSEVALUE(Pointer,Get_sub_tree(),hole); SHIFT()\n");
  PF ("#ifdef TRACE_%s_PARSE\n", Rootstr);
  PF ("#define REPORT(n) \\\n");
  PF ("    printf (\"State %%d,\tsymbol %%s,\ttoken %%s\\n\", n, ");
    PF ("%s_symbol_names[_%s_symbol], ", Rootstr, Rootstr);
    PF ("%s_symbol_names[_%s_token]);\n", Rootstr, Rootstr);
  PF ("#else\n");
  PF ("#define REPORT(n)\n");
  PF ("#endif\n");

  PF ("#if !defined(__GNUC__)\n");
  PF ("# define __inline__\n");
  PF ("#endif\n");
  
  for (l = Lalr_states(lalr); l; l = List_LR_state_next(l)) {
    gen_header (List_LR_state_data(l), TRUE, FALSE);
  }
  PF ("\n");

  for (l = Lalr_states(lalr); l; l = List_LR_state_next(l)) {
    gen_function (List_LR_state_data(l), FALSE);
  }
}

/**************/

/* Generate the recursive ascent parser */
void Print_lalr (Lalr lalr)
{
  if (no_lalr) return;

  open_print_file (append_string (Rootstr, "_lalr.h"), TRUE);
  set_margin(0); set_position(0);
  generate_parser_def(lalr);
  close_print_file();
  
  open_print_file (append_string (Rootstr, "_lalr.c"), TRUE);
  set_margin(0); set_position(0);
  generate_parser(lalr);
  close_print_file();
  
  open_print_file (append_string (Rootstr, ".states"), TRUE);
  set_margin(0); set_position(0);
  Print_Lalr (lalr);
  close_print_file();
}
