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
#include "GenTypes.h"
#include "GenGrammar.h"
#include "flags.h"
#include "Checks.h"

static NonTerminal cur_nt;

static Bool has_labeled_alts (List_Alternative l)
{
  for (; l; l = List_Alternative_next(l)) {
    Alternative a = List_Alternative_data(l);
    if (Alternative_tag(a) == LabeledAlt_kind) return TRUE;
  }
  return FALSE;
}

/* Check consistency of a macro production rule */
static void check_macro (NonTerminal nt)
{
  Rhs rhs = NonTerminal_rhs(nt);
  Super super = NonTerminal_super(nt);
  String s = Ident_name(NonTerminal_id(nt));
  
  if (super != NULL) {
    InputError (Super_loc(super), TRUE, "Macro '%s' may not have super type", s);
  }
  
  if (has_labeled_alts(Rhs_alts(rhs))) {
    InputError (Rhs_loc(rhs), TRUE, "Macro '%s' may not have sub-types", s);
  }

  if (Rhs_checklist(rhs) != NULL) {
    InputError (Rhs_loc(rhs), TRUE, "Macro '%s' may not have checks", s);
  }

  if (Rhs_sc(rhs) != NULL) {
    InputError (Rhs_loc(rhs), TRUE, "Macro '%s' may not have scoping", s);
  }
}

/* Check consistency of a non-terminal */
static void
check_nonterm (NonTerminal nt)
{ 
  Super super = NonTerminal_super(nt);

  cur_nt = nt;

  if (is_macro(nt)) check_macro(nt);
  
  if (super != NULL) {
    NonTerminal s_nt = Super_super(super);
    String s = Ident_name(Super_id(super));
    if (s_nt != NULL && is_macro(s_nt)) {
      InputError (Super_loc(super), TRUE, "Super type '%s' may not be macro", s);
    }
    if (NonTerminal_scan(nt) != NULL) {
      InputError (Super_loc(super), TRUE, "Super type '%s' not allowed for terminal symbol", s);
    }
  }
}

/* Check cycle in macro usage */
static struct s_front_TraverseTable cycle_tab;

/* Check cycle in macro usage */
static List_Ident sym_cycle (Symbol s, List_Ident under_eval)
{
  NonTerminal nt = IdSym_nt(s);
  if (nt==NULL) return under_eval;
  if (!is_macro(nt)) return under_eval;
  
  if (contains_id (under_eval, NonTerminal_id(nt))) {
    String s = Ident_name(NonTerminal_id(nt));
    InputError (NonTerminal_loc(nt), TRUE, "Macro '%s' is cyclic", s);    
    return under_eval;
  }
  
  under_eval = Create_List_Ident (NonTerminal_id(nt), under_eval);
  
  Traverse_NonTerminal (nt, &cycle_tab, under_eval);  
  
  return List_Ident_next(under_eval);
}

/* Check cycle in super-type usage */
static struct s_front_TraverseTable super_tab;

/* Check cycle in super-type usage */
static List_Ident super_cycle (NonTerminal nt, List_Ident under_eval)
{
  Super super;
  
  if (nt==NULL) return under_eval;
  super = NonTerminal_super(nt);
  if (super==NULL) return under_eval;
  if (Super_super(super)==NULL) return under_eval;
  
  if (contains_id (under_eval, NonTerminal_id(nt))) {
    String s = Ident_name(NonTerminal_id(nt));
    InputError (NonTerminal_loc(nt), TRUE, "Super typing of non-terminal '%s' is cyclic", s);    
    return under_eval;
  }
  
  under_eval = Create_List_Ident (NonTerminal_id(nt), under_eval);
  
  Traverse_NonTerminal (Super_super(super), &super_tab, under_eval);  
  
  return List_Ident_next(under_eval);
}

/* Check consistency of the grammar */
void check_front (front f)
{
  static struct s_void_front_TraverseTable check_tab;
  
  check_tab.action_NonTerminal[PRE_ACTION] = check_nonterm;
  cycle_tab.action_IdSym[PRE_ACTION] = (void*)sym_cycle;
  super_tab.action_NonTerminal[PRE_ACTION] = (void*)super_cycle;
  
  Traverse_void_front (f, &check_tab);
  Traverse_front (f, &cycle_tab, NULL);
  Traverse_front (f, &super_tab, NULL);
}

/**************/

/* Check for fields that have no name */
static void check_types_alt (Alternative a)
{
  String s = Ident_name(LabeledAlt_id(a));
  List_field l;
  struct_type t = Alternative_type(a);
  
  if (nocode) return;
  if (t==NULL) return;
  
  for (l = struct_type_fields1(t); l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (field_id(f) == NULL) {
      InputError (Alternative_loc(a), TRUE, "Alternative '%s' has unlabeled fields", s);
    }
  }
  
  for (l = struct_type_fields2(t); l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (field_id(f) == NULL) {
      InputError (Alternative_loc(a), TRUE, "Alternative '%s' has unlabeled fields", s);
    }
  }
}

/* Check typeing consistency of a non-terminal */
static void check_types_nonterm (NonTerminal nt)
{ 
  Rhs rhs = NonTerminal_rhs(nt);
  Super super = NonTerminal_super(nt);
  String s = Ident_name(NonTerminal_id(nt));

  cur_nt = nt;

  if (is_macro(nt)) return;
  
  check_types_alt (NonTerminal_alt(nt));
  
  /* A : B = f1 < .. > f2 must have empty f1, f2 */
  if (super != NULL && Super_tag(super) == NoType_kind && 
      Rhs_alts(rhs) != NULL && NonTerminal_scan(nt) == NULL) {
    if (get_fields(Rhs_syms1(rhs)) != NULL || 
        get_fields(Rhs_syms2(rhs)) != NULL) {
      InputError (Rhs_loc(rhs), TRUE, "Non-terminal '%s' may not have symbols", s);
    }
  }
}

/* Check consistency of an unlabeled alternative */
static void check_types_unlab_alt (Alternative a)
{ List_field l = get_fields(UnLabeledAlt_syms(a));
  NonTerminal nt = NonTerminalScope_data(Alternative_scope(a));
  Ident tid;
  struct_type t = nonterm_type (nt, NULL, &tid);
  
  if (nocode) return;
  if (is_macro(nt)) return;
  
  /* Enum type may not have fields */
  if (find_enumtype(tid) != NULL) {
    if (l!=NULL) {
      InputError (Alternative_loc(a), TRUE, "Enum type may not have fields");
    }
    return;
  }
  
  if (t==NULL) return;
  
  if (is_empty_sym(UnLabeledAlt_syms(a))) return;
  
  /* An unlabeled alt should have exactly one field of the appropriate type */
  if (l==NULL) {
    InputError (Alternative_loc(a), TRUE, "Alternative has no fields");
  } else if (List_field_next(l)!=NULL) {
    InputError (Alternative_loc(a), TRUE, "Alternative has more than one field");
  } else {
    field f = List_field_data(l);
    TypeName tn = List_TypeName_data(field_type(f));
    Ident id = TypeName_full(tn);
    if (id != tid) {
      InputError (Alternative_loc(a), TRUE, "Alternative should have type '%s'", Type_str(t));
    }
  }
}

/* A defining symbol should have exactly one field of a standard type */
static void check_defining (Defining_id def)
{
  List_field l = get_fields (DefId_id(def));
  if (l==NULL) {
    InputError (Defining_id_loc(def), TRUE, "Defining symbol has no fields");
  } else if (List_field_next(l)!=NULL) {
    InputError (Defining_id_loc(def), TRUE, "Defining symbol has more than one field");
  } else {
    field f = List_field_data(l);
    TypeName tn = List_TypeName_data(field_type(f));
    Ident id = TypeName_full(tn);
    if (!TermType(id) && !Std_type(id)) {
      InputError (Defining_id_loc(def), TRUE, "Defining symbol has incorrect type");
    }
  }
}

/* An applied symbol should have a corrsponding defining */
/* An applied symbol should have a name of terminal type */
static void check_applied (Symbol s)
{
  NonTerminal nt = AppliedSym_nt(s);
  Alternative alt = AppliedSym_alt(s);
  Symbol def = find_defining (nt, alt);
  
  if (def == NULL) {
    String name = Ident_name (AppliedSym_nt_id(s));
    InputError (Symbol_loc(s), TRUE, "Symbol '%s' is not defining", name);
  }
  
  if (AppliedSym_field(s) == AppliedName) {
    Ident id = AppliedSym_name(s);
    if (!TermType(id)) {
      InputError (Symbol_loc(s), TRUE, "Applied symbol must have type 'Ident'");
    }
  }
}

/* An undefined symbol should have a terminal type */
static void check_idsym (Symbol s)
{ NonTerminal nt = IdSym_nt(s);
  Type t = IdSym_type(s);
  if (nt == NULL && t != NULL) {
    if (Type_args(t) != NULL || !TermType(Type_id(t))) {
      String name = Ident_name (IdSym_id(s));
      InputError (Symbol_loc(s), TRUE, "Symbol '%s' should have terminal type", name);
    }
  }
}

/* Check consistency of the types */
void check_types (front f)
{
  static struct s_void_front_TraverseTable check_tab;
  check_tab.action_NonTerminal[PRE_ACTION] = check_types_nonterm;
  check_tab.action_LabeledAlt[PRE_ACTION] = check_types_alt;
  check_tab.action_UnLabeledAlt[PRE_ACTION] = check_types_unlab_alt;
  check_tab.action_DefId[PRE_ACTION] = check_defining;
  check_tab.action_AppliedSym[PRE_ACTION] = check_applied;
  check_tab.action_IdSym[PRE_ACTION] = check_idsym;

  Traverse_void_front (f, &check_tab);
}

