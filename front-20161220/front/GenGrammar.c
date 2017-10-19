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
#include <assert.h>
#include "GenTypes.h"
#include "GenGrammar.h"
#include "GenLex.h"
#include "TypesPrint.h"
#include "frontPrint.h"
#include "flags.h"

static List_Ident    rule_names  = NULL; /* Names of prod_rules  */
static List_Ident    extra_names = NULL; /* Names of extra_rules */
List_ProdRule prod_rules  = NULL; /* Production rules not non-terminals */
List_ProdRule extra_rules = NULL; /* Extra rules for sequences, etc */
List_ProdRule all_rules  = NULL;  /* prod_rule+extra_rules */

#define append_syms(a,b) FRONT_CONCAT (Symbol, a, b)   
#define append_sym(a,b)  FRONT_CONCAT_NODE (Symbol, a, b)

static String symbolsname (List_Symbol l, String sep);
static List_Symbol remove_layout (List_Symbol l);
static void optnull (field f, String a, String b);
static void once    (field f, String a, String b);

/*****************/

/* Nt is a sub-type of a terminal */
static Ident term_sub_type (NonTerminal nt)
{
  Super super;
  if (nt == NULL) return NULL;
  super = NonTerminal_super(nt);
  if (super==NULL) return NULL;
  if (TermType (Super_id(super))) return Super_id(super);
  return NULL;
}

/* No Field's in l test */
static Bool no_fields (List_Field l)
{
  for (; l; l = List_Field_next(l)) {
    if (List_Field_data(l) != NULL) return FALSE;
  }
  return TRUE;
}

static Bool unlabeled (List_Alternative l)
{
  for (; l; l = List_Alternative_next(l)) {
    Alternative a = List_Alternative_data(l);
    if (Alternative_tag(a) != UnLabeledAlt_kind) return FALSE;
  }
  return TRUE;
}

/* A = rhs */
Bool is_macro (NonTerminal nt)
{
  Rhs rhs;
  if (nt == NULL) return FALSE;
  if (Defines_tag(NonTerminal_alias(nt)) != MacroDef_kind) return FALSE;
  rhs = NonTerminal_rhs(nt);
  return unlabeled(Rhs_alts(rhs));
}

/* A : B ::= rhs */
Bool no_nt_type (NonTerminal nt)
{
  Super s;
  if (nt == NULL) return FALSE;
  s = NonTerminal_super(nt);
  if (s == NULL) return FALSE;
  if (Super_tag(s) != NoType_kind) return FALSE;
  return TRUE;
}

/* Check for no alternatives */
Bool no_nt_alts (NonTerminal nt)
{
  Rhs rhs;
  rhs = NonTerminal_rhs(nt);
  return Rhs_alts(rhs) == NULL;
}

/* Check for terminal symbol */
static Bool is_term (Symbol s)
{
  switch (Symbol_tag(s)) {
    case IdSym_kind:
      if (!IdSym_nt(s) && !IdSym_import(s)) return TRUE;
      if (!IdSym_nt(s) || NonTerminal_scan(IdSym_nt(s)) != NULL) return TRUE;
      break;
    case StringSymbol_kind:
    case CharSymbol_kind:
    case KeywordSymbol_kind:
      return TRUE;
    case AppliedSym_kind:
      return TRUE;
    case DefiningSym_kind:
      if (Defining_id_tag(DefiningSym_id(s)) == DefId_kind)
        return is_term (DefId_id (DefiningSym_id(s)));
    default:
      break;
  }
  return FALSE;
}

/* Different definings for the same non-terminal should have the same namespace */
static void check_def_consistency (Symbol s, Symbol t)
{
  if (Symbol_tag(s) != DefiningSym_kind) return;
  if (Symbol_tag(t) != DefiningSym_kind) return;
  if (DefiningSym_ns(s) == NULL) return;
  if (DefiningSym_ns(t) == NULL) return;
  if (DefiningSym_ns_id(s) == DefiningSym_ns_id(t)) return;
  InputError (Symbol_loc(s), TRUE, "Inconsistent namespaces between defining symbols");
  InputError (Symbol_loc(t), TRUE, "Inconsistent namespaces between defining symbols");
}

/* Find a defining symbol by a traversal */
static Symbol _get_defining (Symbol s, Symbol def)
{
  if (def != NULL) {
    check_def_consistency (s, def);
  }
  return s;
}

/* Find a defining symbol by a traversal */
static Symbol get_defining (Alternative alt)
{
  static struct s_front_TraverseTable tab;
  tab.action_DefiningSym[PRE_ACTION] = (void*)_get_defining;
  
  return Traverse_Alternative (alt, &tab, NULL);
}

/* Find a defining symbol by a traversal */
Symbol find_defining (NonTerminal nt, Alternative alt)
{
  if (nt != NULL) alt = NonTerminal_alt(nt);
  if (alt==NULL) return NULL;
  
  return get_defining (alt);
}

/* Find the defining symbol for an applied and check for overload */
Bool applied_overloaded (Symbol app)
{
  Symbol def = NULL;
  def = find_defining (AppliedSym_nt(app), AppliedSym_alt(app));
  return def && DefiningSym_def(def) == Overloading;
}
   
/* Flatten recursively occurring SymbolSeq's into one list of Symbols */
List_Symbol flatten_syms (List_Symbol l)
{
  Symbol s;
  List_Symbol next;
  
  if (l==NULL) return NULL;
  
  s = List_Symbol_data(l);
  next = List_Symbol_next(l);
  if (is_empty_sym (s)) return flatten_syms (next);
  
  switch (Symbol_tag(s)) {
    case LabeledSym_kind:
      return flatten_syms (Create_List_Symbol (LabeledSym_sym(s), next));
    case SymbolSeq_kind:
      return flatten_syms (append_syms(SymbolSeq_symbols(s), next));
    case CompareSym_kind:
      return flatten_syms (Create_List_Symbol (Symbol2_sym(s), next));
    default:
      break;
  }
  return Create_List_Symbol (s, flatten_syms (next));
}

/* Flatten recursively occurring SymbolSeq's into one list of Symbols */
extern List_Symbol flatten_sym (Symbol s)
{
  if (is_empty_sym (s)) return NULL;
  
  switch (Symbol_tag(s)) {
    case LabeledSym_kind:
      return flatten_sym (LabeledSym_sym(s));
    case SymbolSeq_kind:
      return flatten_syms (SymbolSeq_symbols(s));
    case CompareSym_kind:
      return flatten_sym (Symbol2_sym(s));
    default:
      break;
  }
  return Create_List_Symbol (s, NULL);
}

/* Flatten recursively occurring Field's into one list of Fields */
static List_Field _flatten_fields (Symbol s, List_Field l)
{
  return FRONT_CONCAT (Field, SymbolSeq_my_fields(s), l);
}

/* Flatten recursively occurring Field's into one list of Fields */
static List_Field flatten_fields (List_Symbol l)
{
  static struct s_front_TraverseTable tab;
  tab.action_SymbolSeq[POST_ACTION] = (void*)_flatten_fields;
  
  return Traverse_List_Symbol (l, &tab, NULL);
}

/* Remove initialized fields */
List_field clean_fields (List_field l) 
{
  field f;
  List_field next;
  
  if (l==NULL) return NULL;
  f = List_field_data(l);
  next = clean_fields (List_field_next(l));
  if (field_init(f)) return next;
  return Create_List_field (f, next);
}

/* Get the fields from s and remove initialized fields */
List_field get_fields (Symbol s)
{
  if (s==NULL) return NULL;
  return clean_fields (Symbol_fields(s));
}

/* Get the fields from l and remove initialized fields */
List_field get_syms_fields (List_Symbol l)
{
  List_field f = NULL;
  for (; l; l = List_Symbol_next(l)) {
    f = FRONT_CONCAT (field, f, get_fields(List_Symbol_data(l)));
  }
  return f;
}

/********************************/

/* Add extra rules to the grammar.
   This means rules for 
     Opt     - [a]
     More    - {a}+
     OptMore - {a}
     Alt     - a // b
*/
static void add_extra_rules (List_Symbol l);

/* Add an extra rule for Symbol s, with non-terminal name name.
   If alt is non-null, it represents s//alt.
   fields are the fields of the extra rule.
*/
static void add_extra_rule (Symbol s)
{
  String name = symbolname (s); 
  Ident id = Create_Ident (name);
  List_field f = get_fields(s);
  
#if 0
  printf ("add_extra_rule %s\n", name);
#endif
  if (id == Create_Ident("")) return;
  if (contains_id (rule_names, id)) return;
  if (contains_id (extra_names, id)) return;
  if (is_term(s)) return;
    
  if (Symbol_tag(s) != SymbolSeq_kind) {
    ProdRule rule = Create_Extra_Rule (no_srcinfo, id);
    Extra_Rule_sym(rule) = s;
    ProdRule_fields(rule) = f;

    extra_names = Create_List_Ident (id, extra_names);
    extra_rules = FRONT_CONCAT_NODE(ProdRule, extra_rules, rule);
  }
  switch (Symbol_tag(s)) {
    case OptSymbol_kind:
    case MoreSymbol_kind:
    case OptMoreSymbol_kind:
      add_extra_rules (CompoundSym_sym(s));
      break;
    case SymbolSeq_kind:
      add_extra_rules (SymbolSeq_symbols(s));
      break;
    case AltSymbol_kind:
      add_extra_rule  (AltSymbol_syms1(s));
      add_extra_rules (AltSymbol_syms(s));
      break;
    default:
      break;
  }
}

/* Add extra rules for all symbols in l */
static void add_extra_rules (List_Symbol l)
{
  for (; l; l = List_Symbol_next(l)) {
    add_extra_rule (List_Symbol_data(l));
  }
}

/* Checks whether to generate an extra rule */
Bool valid_extra (ProdRule r)
{
  Symbol sym;
  
  if (ProdRule_tag(r) != Extra_Rule_kind) return TRUE;
  sym = Extra_Rule_sym(r);

  switch (Symbol_tag(sym)) {
    case OnceSymbol_kind:
    case OptSymbol_kind:
    case MoreSymbol_kind:
    case OptMoreSymbol_kind:
    case AltSymbol_kind:
#if 0
      printf ("Valid extra %s\n", Ident_name(ProdRule_lhs(r)));
#endif
      return TRUE;
    default:
      break;
  }
#if 0
  printf ("Invalid extra %s %s\n", Ident_name(ProdRule_lhs(r)), Symbol_tag_names[Symbol_tag(sym)]);
#endif
  return FALSE;
}

/*********************************************/

/* Create the list of symbollist representing the right-hand-sides */
static List_Symbol expand_sym (Symbol s)
{ List_Symbol l;
  Symbol t;
  switch (Symbol_tag(s)) {
    case LabeledSym_kind:
      return expand_sym (LabeledSym_sym(s));
    case OptSymbol_kind:
      if (!OptSymbol_in_line(s)) break;
      l = CompoundSym_sym(s);
      if (List_Symbol_size(l) != 1) break;
      t = COPY_Symbol(s);
      Symbol_empty(t) = TRUE;
      return Create_List_Symbol(t, Create_List_Symbol (s, NULL));
    default: break;
  }
  return Create_List_Symbol(s, NULL);
}

/* Create the list of symbollist representing the right-hand-sides */
static List_List_Symbol expand_rhs (List_Symbol l)
{ Symbol s;
  List_List_Symbol r, t;
  List_Symbol m;
  List_List_Symbol x = NULL;
  
  if (l==NULL) return Create_List_List_Symbol (NULL, NULL);
  s = List_Symbol_data(l);
  r = expand_rhs (List_Symbol_next(l));
  
  for (m = expand_sym(s); m; m = List_Symbol_next(m)) {
    Symbol u = List_Symbol_data(m);
    for (t = r; t; t = List_List_Symbol_next(t)) {
      List_Symbol v = List_List_Symbol_data(t);
      List_Symbol w = Create_List_Symbol (u,v);
      x = Create_List_List_Symbol (w, x);
    }
  }
  return x;
}

/* Create production rules for all non-terminals in the grammar.
   For every alternative, one rule is generated.
*/
static void get_prodrule (Alternative a, NonTerminal nt, List_Symbol pre, List_Symbol post);

/* Generate a production rule nt, with alternative alt.
   pre are the symbols preceeding alt, post are the symbols after alt.
*/
static void make_prodrule (NonTerminal nt, Alternative alt, List_Symbol pre, List_Symbol post)
{
  Ident id = NonTerminal_id(nt);
  List_List_Symbol rhss;
  List_Symbol rhs;
  
  if (!contains_id (rule_names, id)) {
    rule_names = Create_List_Ident (id, rule_names);
  }
  
  rhs = append_syms (pre, post);
  for (rhss = expand_rhs (flatten_syms(rhs)); rhss; rhss = List_List_Symbol_next(rhss)) {
    List_Symbol s1 = List_List_Symbol_data(rhss);
    ProdRule rule = Create_NT_Rule (no_srcinfo, id);
    NT_Rule_nt (rule) = nt;
    NT_Rule_rhs(rule) = s1;
    NT_Rule_fields(rule) = flatten_fields (rhs);
    NT_Rule_alt(rule) = alt;
    ProdRule_fields(rule) = get_syms_fields (rhs);
    prod_rules = FRONT_CONCAT_NODE(ProdRule, prod_rules, rule);
  }
}

static void make_importrule (ImportedNonTerminal nt, Ident grammar)
{
  ProdRule rule;
  rule = Create_Import_Rule (no_srcinfo, ImportedNonTerminal_id(nt));
  ProdRule_fields(rule) = NULL;
  Import_Rule_type (rule) = ImportedNonTerminal_type(nt);
  if (!Import_Rule_type (rule)) {
    Import_Rule_type (rule) = ProdRule_lhs (rule);
  }
  Import_Rule_grammar (rule) = grammar;
  Import_Rule_imp (rule) = nt;
  prod_rules = FRONT_CONCAT_NODE(ProdRule, prod_rules, rule);
}

/* Generate a production rule for the Rhs r, current alternative is alt.
   pre preceeds r, post follows r.
*/
static void rhs_prodrule (Rhs r, NonTerminal nt, Alternative alt, List_Symbol pre, List_Symbol post)
{
  List_Alternative l;
  List_Symbol s1 = pre;
  List_Symbol s2 = post;
  
  if (r==NULL) return;

  if (Rhs_syms1(r)) s1 = append_sym (s1, Rhs_syms1(r));
  if (Rhs_syms2(r)) s2 = Create_List_Symbol(Rhs_syms2(r), s2);
  if (Rhs_alts (r) == NULL) {
    make_prodrule (nt, alt, s1, s2);
  }
  for (l = Rhs_alts (r); l; l = List_Alternative_next(l)) {
    Alternative a = List_Alternative_data(l);
    get_prodrule (a, nt, s1, s2);
  }

}

/* Generate a production rule for the alternative a.
   pre preceeds a, post follows a.
*/
static void get_prodrule (Alternative a, NonTerminal nt, List_Symbol pre, List_Symbol post)
{
  if (a==NULL) return;
  switch (Alternative_tag(a)) {
    case LabeledAlt_kind:
      rhs_prodrule (LabeledAlt_rhs(a), nt, a, pre, post);
      break;
    case UnLabeledAlt_kind:
      make_prodrule (nt, a, pre, 
                     Create_List_Symbol (UnLabeledAlt_syms(a), post));
      break;
  }
}

/* Generate production rules for all non-terminals in l */
static void get_prodrules (List_NonTerminal l, List_Import imps)
{
  List_ProdRule p;
  
  for (; l; l = List_NonTerminal_next(l)) {
    NonTerminal nt = List_NonTerminal_data(l);
    Alternative alt = NonTerminal_alt(nt);
    if (NonTerminal_scan(nt) != NULL) continue;
    if (!NonTerminal_reachable(nt)) continue;
    if (is_macro(nt) && is_empty (NonTerminal_rhs(nt))) continue;
    get_prodrule (alt, nt, NULL, NULL);
  }

  for (p = prod_rules; p; p = List_ProdRule_next(p)) {
    add_extra_rules (NT_Rule_rhs(List_ProdRule_data(p)));
  }

  for (; imps; imps = TAIL(imps)) {
    Ident grammar = Import_grammar (HEAD(imps));
    List_ImportedNonTerminal nts;
    
    for (nts = Import_nts (HEAD(imps)); nts; nts = TAIL(nts)) {
      make_importrule (HEAD(nts), grammar);      
    }
  }
}

/**************************/\

/* Symbol s always generates the empty string, used within traversal */
static Bool _empty_sym (Symbol s, Bool e)
{
  if (s==NULL || !e) return e;
  
  switch (Symbol_tag(s)) {
    case SymbolSeq_kind:
      if (!no_fields(SymbolSeq_my_fields(s))) return FALSE;
      break;
    case StringSymbol_kind:
    case CharSymbol_kind:
    case KeywordSymbol_kind:
    case AppliedSym_kind:
      return FALSE;
    case IdSym_kind: {
      NonTerminal nt = IdSym_nt(s);
      if (is_macro(nt)) return is_empty (NonTerminal_rhs(nt));
      return FALSE;
    }
    default:
      break;
  }
  
  return e;
}

/* Rhs r always generates the empty string */
Bool is_empty (Rhs r)
{
  static struct s_front_TraverseTable tab;
  tab.action_Symbol[PRE_ACTION] = (void*)_empty_sym;
  
  return (Bool)Traverse_Rhs (r, &tab, (void*)TRUE);
}

/* Symbol s always generates the empty string */
Bool is_empty_sym (Symbol s)
{
  static struct s_front_TraverseTable tab;
  tab.action_Symbol[PRE_ACTION] = (void*)_empty_sym;
  
  return (Bool)Traverse_Symbol (s, &tab, (void*)TRUE);
}

/* s contains just layout */
Bool is_layout (Symbol s)
{
  if (s==NULL) return TRUE;
  switch (Symbol_tag(s)) {
    case EmptySym_kind:
    case LayoutString_kind:
    case LayoutAction_kind:
      return TRUE;
    case SymbolSeq_kind: {
      List_Symbol l;
      if (!no_fields(SymbolSeq_my_fields(s))) return FALSE;
      for (l = SymbolSeq_symbols(s); l; l = List_Symbol_next(l)) {
        if (!is_layout(List_Symbol_data(l))) return FALSE;
      }
      return TRUE;
    }
    case IdSym_kind: {
      NonTerminal nt = IdSym_nt(s);
      if (nt != NULL && is_macro(nt)) {
        Rhs rhs = NonTerminal_rhs(nt);
	if (Rhs_alts(rhs) != NULL) return FALSE;
	if (Rhs_syms2(rhs) != NULL) return FALSE;
	return is_layout (Rhs_syms1(rhs));
      }
      break;
    }
    default:
      break;
  }
  return FALSE;
}

static List_Symbol remove_layout (List_Symbol l)
{ Symbol s;
  if (l == NULL) return NULL;
  s = List_Symbol_data(l);
  l = remove_layout (List_Symbol_next(l));
  if (is_layout(s)) return l;
  return Create_List_Symbol (s, l);
}

/**************************/

/* Construct the symbol name the list of symbols in l, separated by sep */
static String symbolsname (List_Symbol l, String sep)
{ String t = "";
  String s = "";
  for (; l; l = List_Symbol_next(l)) {
    String u = symbolname(List_Symbol_data(l));
    if (strlen(u) == 0) continue;
    t = append_string (t, s);
    t = append_string (t, u);
    s = sep;
  }
  return t;
}

/* Construct the symbol name the Symbol s */
String symbolname (Symbol s)
{
  if (s==NULL) return "";
  switch (Symbol_tag(s)) {
    case LabeledSym_kind:
      return symbolname (LabeledSym_sym(s));
    case SymbolSeq_kind:
      return symbolsname (flatten_syms(SymbolSeq_symbols(s)), "_");
    case CompareSym_kind:
      return symbolname (Symbol2_sym(s));
    case DefiningSym_kind:
      if (Defining_id_tag(DefiningSym_id(s)) != DefId_kind) break;
      return symbolname (DefId_id(DefiningSym_id(s)));
    case AppliedSym_kind:
      if (AppliedSym_field(s) == AppliedField) break;
      return append_string (Ident_name(AppliedSym_name(s)), "sym");
    case StringSymbol_kind:
    case CharSymbol_kind:
    case KeywordSymbol_kind:
      return term_name (s);
    case OnceSymbol_kind:
      return append_string ("ONCE_", symbolsname (CompoundSym_sym(s), "OR"));
    case OptSymbol_kind:
      return append_string ("OPT_",  symbolsname (CompoundSym_sym(s), "OR"));
    case MoreSymbol_kind:
      return append_string ("MORE_", symbolsname (CompoundSym_sym(s), "OR"));
    case OptMoreSymbol_kind:
      return append_string ("OPTMORE_", symbolsname (CompoundSym_sym(s), "OR"));
    case EmptySym_kind:
    case LayoutString_kind:
    case LayoutAction_kind:
      return "";
    case IdSym_kind: {
      NonTerminal nt = IdSym_nt(s);
      if (nt != NULL) {
#if 0
        if (is_empty (NonTerminal_rhs(nt))) return "";
#endif
        if (NonTerminal_scan(nt) != NULL) {
	  return append_string (Ident_name (IdSym_id(s)), "sym");
	}
	return Ident_name (IdSym_id(s));
      }
      if (IdSym_import (s)) {
	return Ident_name (IdSym_id(s));
      }
      return append_string (Ident_name (IdSym_id(s)), "sym");
    }
    case AltSymbol_kind: {
      Symbol a = AltSymbol_syms1(s);
      List_Symbol b = AltSymbol_syms(s);
      String s1 = symbolname (a);
      String s2 = symbolsname (b, "_");
      return Front_StrAllocf ("ALT_%s_SEP_%s", s1, s2);
    }
  }
  return "";
}

/****************** Printing ******************/

/* Print the arguments of a Create function 
   s is symbol in the rhs of a production rule, with attribute $$i
*/
static void print_create_fields (Symbol s, Int *i)
{
  List_field l = get_fields(s);
  Int n = List_field_size(l);
  Int j;
  
  
  if (is_inlined_opt(s)) {
    List_Symbol m;
    Bool empty = TRUE;
    for (m = flatten_syms(CompoundSym_sym(s)); m; m = List_Symbol_next(m)) {
      Symbol x = List_Symbol_data(m);
      l = get_fields(x);
      n = List_field_size (l);
      for (j=1; l; l = List_field_next(l), j++) {
        empty = FALSE;
	PF (", ");
	if (Symbol_empty(s)) {
	  optnull (List_field_data(l), "", "");
	} else {
          String str;
          if (is_list_field(List_field_data(l)) && LeftRecursive) {
            PF ("(");
            Print_Ident(full_glue_type(field_type(List_field_data(l))));
            PF (") List_reverse ((Front_List)");
          }
	  if (n == 1) str = Front_StrAllocf ("$%d", *i);
          else str = Front_StrAllocf ("$%d.f%d", *i, j);
	  once (List_field_data(l), str, "");
          if (is_list_field(List_field_data(l)) && LeftRecursive) {
            PF (")");
          }
	}
      }
      if (!Symbol_empty(s)) (*i)++;
    }
    if (empty) { 
#if 0
    PF ("/* %s %d %s %d */ ", symbolname(s), *i, symbolname(x), n);
#endif
      PF (", ");
      if (Symbol_empty(s)) optnull (NULL, "", "");
      else once (NULL, "TRUE", "");
    }
    return;
  }
  
  for (j=1; l; l = List_field_next(l), j++) {
    PF (", ");
    if (is_list_field(List_field_data(l)) && LeftRecursive) {
      PF ("(");
      Print_Ident(full_glue_type(field_type(List_field_data(l))));
      PF (") List_reverse ((Front_List)");
    }
    PF ("$%d", *i);
    if (n > 1) PF (".f%d", j);
    if (is_list_field(List_field_data(l)) && LeftRecursive) {
      PF (")");
    }
  }
  (*i)++;  
}

/* Print the arguments of a Create function.
   rhs is the rhs of a production rule.
*/
static void print_create_args (List_Symbol rhs)
{
  List_Symbol l;
  Int i = 1;
  
  for (l = rhs; l; l = List_Symbol_next(l)) {
    Symbol x = List_Symbol_data(l);
    String s = symbolname (x);
    if (strlen(s) == 0) continue;
    print_create_fields (x, &i);
  }
}

/* Print the assignement to the fields of a macro non-terminal.
   n is the number of fields: if n==1 the lhs is $$, otherwise it is $$(*k)
   Symbol s is the i-th element of the rhs of the production rule.
*/
static void print_macro_fields (Symbol s, Int *i, Int n, Int *k)
{
  List_field l = get_fields(s);
  Int j;
  Int nf = List_field_size(l);
     
  for (j=1; l; l = List_field_next(l), j++, (*k)++) {
    if (n==1) {
      PF ("    $$ = ");
    } else if (nf==1) {
       PF ("    $$.f%d = ", *k);
    } else {
       PF ("    $$.f%d = $%d.f%d;\n", *k, *i, j);
       continue;
    }
    if (is_inlined_opt(s)) {
      if (Symbol_empty(s)) {
        optnull (List_field_data(l), "", "");
	*i--;
      } else {
        String str = Front_StrAllocf ("$%d", *i);
        once (List_field_data(l), str, "");
      }
    } else {
      PF ("$%d", *i);
    }
    PF (";\n");
  }
  (*i)++;
}

FieldInit
Field_init_when (Field f, FieldInit_tag when)
{
  List_FieldInit is;
  
  for (is = Field_when(f); is; is = List_FieldInit_next (is)) {
    FieldInit i = List_FieldInit_data (is);
    if (FieldInit_tag(i) == when) return i;
  }
  return NULL;
}

/* Print the assignement to the fields of a macro non-terminal.
   rhs is the rhs of a production rule.
*/
static void print_create_macro (List_Symbol rhs, List_Field fields, Bool macro)
{
  List_Symbol l;
  Int i = 1;
  Int n = 0;
  Int k = 1;

  for (l = rhs; l; l = List_Symbol_next(l)) {
    n += List_field_size (get_fields(List_Symbol_data(l)));
  }
  PF ("  {\n");
  for (l = rhs; l; l = List_Symbol_next(l)) {
    print_macro_fields (List_Symbol_data(l), &i, n, &k);
  }
  for (; fields; fields = List_Field_next(fields)) {
    Field f = List_Field_data(fields);
    Ident t;
    if (f==NULL) continue;
    t = Type_id(Field_type(f));
    if (!macro) continue;
    if (t != Create_Ident("VOID")) continue;
    /* VOID field, evaluate during parse */
    PF ("    /* field %s */\n", Ident_name(Field_id(f)));
    PF ("    ");
    Print_Expr(FieldInit_expr(Field_init_when(f,WhenCreate_kind)));
    PF (";\n");
  }
  PF ("  }\n");
 }

/* Print the SrcInfo argument to a Create function */
static void print_src_info (Int n)
{ if (n==0) {
    PF ("make_post_src_info(p_yylloc->first_line, p_yylloc->last_line)");
  } else {
    PF ("make_post_src_info(@%d.first_line, @%d.last_line)", 1, n);
  }
}

/* print the body (statement part) of a production rule 
   nt -> rhs, for alternative a.
*/
static void print_body (NonTerminal nt, Alternative a, List_Symbol rhs, 
                        List_Field fields, Int n)
{
  struct_type t = NULL;
  struct_type r;
  EnumType e;
  CreateFunction f = NULL;
  Ident tid;
  String ts;
  
  if (a != NULL) t = Alternative_type(a);
  if (t != NULL) f = struct_type_create(t);

  if (t == NULL) {
    PF ("  /* No type */\n");
    if (no_nt_type(nt) && no_nt_alts(nt)) {
      PF ("  { $$ = %s(", Ident_name(NonTerminal_id(nt)));
      print_src_info (n);
      print_create_args (rhs);
      PF ("); }\n");
    } else {
      print_create_macro (rhs, fields, TRUE);
    }
    return;
  }
  
  ts = Type_str(t);
  
  r = nonterm_type (nt, NULL, &tid);
  e = find_enumtype (tid);
  
  if (e != NULL) {
    /* Enum type, don't call Create function */
    Int i = 0;
    struct_type u = EnumType_str_type(e);
    PF ("  /* Enum type */\n");
    if (enum_is_bool(e)) {
      Bool ok = enum_val (u, a, &i);
      assert (ok);
      PF ("  { $$ = %s; }\n", i==0 ? "FALSE" : "TRUE");
    } else if (enum_is_int(e)) {
      Bool ok = enum_val (u, a, &i);
      assert (ok);
      PF ("  { $$ = %d; }\n", i);
    } else {
      PF ("  { $$ = %s; }\n", ts);
    }
    return;
  }
  
  /* Alternative has a type with a create function f */
  if (f != NULL) {
    PF ("  { $$ = Create_%s(", Type_str(t));
    print_src_info (n);
    print_create_args (rhs);
    PF (");\n");
    if (NonTerminal_id(nt) == Rootid) {
      PF ("    Decorate_%s($$);\n", Rootstr);
    }
    PF ("  }\n");
  } else {
    print_create_macro (rhs, fields, FALSE);
  }
}

Bool is_inlined_opt (Symbol s)
{ return Symbol_tag(s) == OptSymbol_kind && OptSymbol_in_line(s);
}

/* Print the rhs of a production rule */
static Int print_rhs (List_Symbol l)
{ Int n = 0;

  for (; l; l = List_Symbol_next(l)) {
    Symbol x = List_Symbol_data(l);
    String s = symbolname (x);
    if (strlen(s) == 0) continue;
    if (is_layout(x)) continue;
    switch (Symbol_tag(x)) {
      case SymbolSeq_kind:
        n += print_rhs (SymbolSeq_symbols(x));
        continue;
      case OptSymbol_kind:
        if (!OptSymbol_in_line(x)) break;
	if (!Symbol_empty(x)) print_rhs (CompoundSym_sym(x));
	continue;
      default:
        break;
    }
    PF ("  %s\n", s);
    if (!is_empty_sym(x)) n++;
  }
  return n;
}

static void
print_import_rule (Import_Rule p)
{
#ifdef IMPORT_ENABLED
  Ident grammar = Import_Rule_grammar (p);
  Ident nt = ProdRule_lhs (p);
  
  PF ("%s : {\n", Ident_name (nt));
  PF ("  if (yychar != YYEMPTY) {\n");
  PF ("    %s_error(\"import parse impossible, look-ahead token not empty\\n\")\n",
      Rootstr);
  PF ("  }\n");
  PF ("  %s__switch_to_buffer (%s_dummy_state());\n", Rootstr, Rootstr);
  PF ("  $$ = %s_export_parse_%s (%s_scanner_state());\n", Ident_name (grammar), Ident_name (nt), Rootstr);
  PF ("  if (!$$) YYABORT;\n");
  PF ("  %s__switch_to_buffer (%s_scanner_state());\n", Rootstr, Rootstr);
  PF ("}\n\n");
#endif
}

static void
print_nt_rule (NT_Rule p)
{
  NonTerminal nt = NT_Rule_nt(p); 
  Int n;
  
  PF ("%s :\n", Ident_name (ProdRule_lhs(p)));
  n = print_rhs (NT_Rule_rhs(p));
  print_body (nt, NT_Rule_alt(p), NT_Rule_rhs(p), NT_Rule_fields(p), n);
  PF (";\n\n");
}

static void print_prodrule (ProdRule p)
{
  switch (ProdRule_tag (p)) {
  case NT_Rule_kind: print_nt_rule (p); break;
  case Import_Rule_kind: print_import_rule (p); break;
  default:
    break;
  }
}

/******************** Printing of extra rules *********************/

/* The following functions are arguments to print_extra_fields
   f is the field to initialize. 
   If f is NULL, there is no field in the rhs but there is oe in the lhs,
     e.g. for [ "aap" ].
   a is the attribute for the non-recursive part
   b is the attribute for the recursive part
   e.g. OPTMORE_A :
          A
	  OPTMORE_A 
	{ $$ = Create_List_A ($1, $2); } ;
   Then a equals $1 and b $2.
*/

/* Generate the null-value for an [A], FALSE or NULL */
static void optnull (field f, String a, String b)
{ NOT_USED(a); NOT_USED(b);
  if (f==NULL) PF ("FALSE");
  else PF ("NULL");
}

/* Generate the null-value for an {A}, 0 or NULL */
static void listnull (field f, String a, String b)
{ NOT_USED(a); NOT_USED(b);
  if (f==NULL) PF ("0");
  else PF ("NULL");
}

/* Generate the non-recursive-value for an {A}+ -> A */
static void rec (field f, String a, String b)
{ NOT_USED(f); NOT_USED(a);
  PF ("%s", b);
}

/* Generate the non-recursive-value for an ((A)) */
static void once (field f, String a, String b)
{ 
  NOT_USED(f); NOT_USED(b);
  PF ("%s", a);
}

/* Generate recursive value for [A] -> A */
static void opt (field f, String a, String b)
{ 
  NOT_USED(b);
  if (f==NULL) {
    PF ("TRUE");
  } else if (Allows_nil (get_field_type(f))) {
    PF ("%s", a);
  } else {
    PF ("Create_Optional_");
    Print_Ident(full_glue_type(field_type(f)));
    PF ("(%s)", a);
  }
}

/* Generate recursive value for {A}+ -> A {A}+ */
static void more (field f, String a, String b)
{ 
  if (f==NULL) {
    PF ("%s+1", b);
  } else {
    PF ("Create_List_");
    Print_Ident(full_glue_type(field_type(f)));
    PF ("(%s, %s)", a, b);
  }
}

#if 0
/* Generate recursive value for {A}+ -> A {A}+ */
static void rev_more (field f, String a, String b)
{ 
  if (f==NULL) {
    PF ("%s+1", b);
  } else {
    PF ("Create_Rev_List_");
    Print_Ident(full_glue_type(field_type(f)));
    PF ("(%s, %s)", b, a);
  }
}
#endif

/* Generate value for {A}+ -> A */
static void more_once (field f, String a, String b)
{ 
  NOT_USED(b);

  if (f==NULL) {
    PF ("1");
  } else {
    PF ("Create_List_");
    Print_Ident(full_glue_type(field_type(f)));
    PF ("(%s, NULL)", a);
  }
}

#if 0
/* Generate value for {A}+ -> A */
static void rev_more_once (field f, String a, String b)
{ 
  NOT_USED(b);

  if (f==NULL) {
    PF ("1");
  } else {
    PF ("Create_Rev_List_");
    Print_Ident(full_glue_type(field_type(f)));
    PF ("(NULL, %s)", a);
  }
}
#endif

/* Construct s.fi */
static String append_field (String s, Int n, Int i)
{
  if (n<=1) return s;
  return Front_StrAllocf ("%s.f%d", s, i);
}

/* Print the attribute construction Symbol s, element of syms.
   syms occurs in an extra rule, e.g.
     A -> [ B | C ], then syms = A, B and s is either NULL, A or B.
   null is used to print if s==NULL, i.e for an epsilon rule.
   create is used for s!=NULL.
*/
static void print_extra_fields (Symbol s, List_Symbol syms,
                                Bool rev, Bool revfields, int start, 
				void (*null) (field, String left, String right), 
				void (*create) (field, String left, String right))
{
  Int fdir = 1;
  Int fstart = 1;
  Int n = 0; /* Number of rhs fields */
  List_Symbol l;
  Int lnum = 1;
  Int recnum = 1; /* rhs number of the recursive call */
  String right;
  List_Symbol s1 = flatten_sym(s);
  
  if (s && !rev) recnum = List_Symbol_size(s1)+1;
  right = Front_StrAllocf ("$%d", recnum);
  
  for (l = syms; l; l = List_Symbol_next(l)) {
    n += List_field_size (get_fields(List_Symbol_data(l)));
  }
  if (revfields) {
    lnum = fstart = n;
    fdir = -1;
  }
  
  if (n==0) {
   if (create == once) return;
   PF ("    $$ = "); 
   if (s==NULL) null   (NULL, "", right); 
   else         create (NULL, "", right);
   PF (";\n");
   return;
  }
  
  /* Traverse syms and pick out s, the active rhs.
     Call create for s and null for other elements of syms. 
  */
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol t = List_Symbol_data(l);
    List_Symbol m;
    Int snum; /* Number of rhs symbol u */
    for (m = flatten_sym (t), snum=start; m; m = List_Symbol_next(m), snum++) {
      Symbol u = List_Symbol_data(m);
      List_field fs = get_fields(u);
      Int k =  List_field_size(fs);
      List_field f;
      Int fnum;
      for (f = fs, fnum = fstart; f; f = List_field_next(f), fnum+=fdir) {
	String left = Front_StrAllocf ("$%d", snum);
	String right1 = right;
	left   = append_field (left,   k, fnum);
	right1 = append_field (right1, n, lnum);
	if (n<=1) {
	  PF ("    $$ = ");
	} else {
	  PF ("    $$.f%d = ", lnum);
          lnum+=fdir;
	}
	if (s != t) null   (List_field_data(f), left, right1);
	else        create (List_field_data(f), left, right1);
	PF (";\n");
      }
    }
  }
}

/* Print the rules for name -> ((A | B)) */
static void print_once_rules (String name, List_Symbol syms)
{ List_Symbol l;
  
  /* ONCE_A -> A */
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    PF ("%s :\n", name);
    print_rhs (Create_List_Symbol (s, NULL));
    PF ("  {\n");
    if (List_Symbol_size(syms) == 1) {
      print_extra_fields (s, syms, FALSE, FALSE, 1, optnull, once);
    } else {
      print_extra_fields (s, syms, FALSE, FALSE, 1, optnull, opt);
    }
    PF ("  }\n");
    PF (";\n\n");
  }
}

/* Print the rules for name -> [A | B] */
static void print_opt_rules (String name, List_Symbol syms)
{ List_Symbol l;
  
  /* OPT_A -> eps */
  PF ("%s :\n", name);
  PF ("  {\n");
    print_extra_fields (NULL, syms, FALSE, FALSE, 1, optnull, opt);
  PF ("  }\n");
  PF (";\n\n");
    
  /* OPT_A -> A */
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    PF ("%s :\n", name);
    print_rhs (Create_List_Symbol (s, NULL));
    PF ("  {\n");
    print_extra_fields (s, syms, FALSE, FALSE, 1, optnull, opt);
    PF ("  }\n");
    PF (";\n\n");
  }
}

/* Print the rules for name -> {A | B}+ */
static void print_more_rules (String name, List_Symbol syms)
{ List_Symbol l;
    
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    
    /*  MORE_A -> A */
    PF ("%s :\n", name);
    print_rhs (Create_List_Symbol (s, NULL));
    PF ("  {\n");
    print_extra_fields (s, syms, FALSE, FALSE, 1, listnull, more_once);
    PF ("  }\n");
    PF (";\n\n");
    
    /* MORE_A -> A MORE_A */
    PF ("%s :\n", name);
    print_rhs (Create_List_Symbol (s, NULL));
    PF ("  %s\n", name);
    PF ("  {\n");
    print_extra_fields (s, syms, FALSE, FALSE, 1, rec, more);
    PF ("  }\n");
    PF (";\n\n");
  }
}

/* Print the rules for name -> {A | B}+ */
static void print_rev_more_rules (String name, List_Symbol syms)
{
  List_Symbol l;
    
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    
    /*  MORE_A -> A */
    PF ("%s :\n", name);
    print_rhs (Create_List_Symbol (s, NULL));
    PF ("  {\n");
    print_extra_fields (s, syms, TRUE, FALSE, 1, listnull, more_once);
    PF ("  }\n");
    PF (";\n\n");
    
    /* MORE_A -> A MORE_A */
    PF ("%s :\n", name);
    PF ("  %s\n", name);
    print_rhs (Create_List_Symbol (s, NULL));
    PF ("  {\n");
    print_extra_fields (s, syms, TRUE, FALSE, 2, rec, more);
    PF ("  }\n");
    PF (";\n\n");
  }
}

/* Print the rules for name -> {A | B} */
static void print_optmore_rules (String name, List_Symbol syms)
{ List_Symbol l;

  /* OPTMORE_A -> eps */
  PF ("%s :\n", name);
  PF ("  {\n");
    print_extra_fields (NULL, syms, FALSE, FALSE, 1, listnull, more);
  PF ("  }\n");
  PF (";\n\n");
    
  /* OPTMORE_A -> A OPTMORE_A */
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    PF ("%s :\n", name);
    print_rhs (Create_List_Symbol (s, NULL));
    PF ("  %s\n", name);
    PF ("  {\n");
    print_extra_fields (s, syms, FALSE, FALSE, 1, rec, more);
    PF ("  }\n");
    PF (";\n\n");
  }
}

/* Print the rules for name -> {A | B} */
static void print_rev_optmore_rules (String name, List_Symbol syms)
{
  List_Symbol l;

  /* OPTMORE_A -> eps */
  PF ("%s :\n", name);
  PF ("  {\n");
  print_extra_fields (NULL, syms, TRUE, FALSE, 1, listnull, more);
  PF ("  }\n");
  PF (";\n\n");
    
  /* OPTMORE_A -> A OPTMORE_A */
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    PF ("%s :\n", name);
    PF ("  %s\n", name);
    print_rhs (Create_List_Symbol (s, NULL));
    PF ("  {\n");
    print_extra_fields (s, syms, TRUE, FALSE, 2, rec, more);
    PF ("  }\n");
    PF (";\n\n");
  }
}

/* TODO: remove this */
#ifdef FRONT2
#define ANDS , NULL
#else
#define ANDS
#endif

/* Print the rules for name -> a // b */
static void print_alt_rules (String name, Symbol a, List_Symbol b)
{   
  Symbol seq = Create_SymbolSeq (no_srcinfo, b, NULL ANDS);
  List_Symbol syms = Create_List_Symbol (a, Create_List_Symbol(seq, NULL));
  List_field f = NULL;
  
  f = get_syms_fields (b);
  Symbol_fields(seq) = f;
  
  /* ALT_A -> a */
  PF ("%s :\n", name);
  print_rhs (Create_List_Symbol (a, NULL));
  PF ("  {\n");
  print_extra_fields (a, syms, FALSE, FALSE, 1, listnull, more_once);
  PF ("  }\n");
  PF (";\n\n");
  
  syms = Create_List_Symbol (a, b);
  seq = Create_SymbolSeq (no_srcinfo, syms, NULL ANDS);
  syms = Create_List_Symbol(seq, NULL);
  f = FRONT_CONCAT (field, Symbol_fields(a), f);
  Symbol_fields(seq) = f;
  
  /* ALT_A -> a b ALT_A */
  PF ("%s :\n", name);
  print_rhs (Create_List_Symbol (a, NULL));
  print_rhs (b);
  PF ("  %s\n", name);
  PF ("  {\n");
  print_extra_fields (seq, syms, FALSE, FALSE, 1, rec, more);
  PF ("  }\n");
  PF (";\n\n");
}

/* Print the rules for name -> a // b */
static void print_rev_alt_rules (String name, Symbol a, List_Symbol b)
{   
  Symbol seq = Create_SymbolSeq (no_srcinfo, b, NULL ANDS);
  List_Symbol syms = Create_List_Symbol (a, Create_List_Symbol(seq, NULL));
  List_field f = NULL;
  
  f = get_syms_fields (b);
  Symbol_fields(seq) = f;
  
  /* ALT_A -> a */
  PF ("%s :\n", name);
  print_rhs (Create_List_Symbol (a, NULL));
  PF ("  {\n");
  print_extra_fields (a, syms, TRUE, FALSE, 1, listnull, more_once);
  PF ("  }\n");
  PF (";\n\n");

  syms = FRONT_CONCAT_NODE (Symbol, b, a);
  seq = Create_SymbolSeq (no_srcinfo, syms, NULL ANDS);
  syms = Create_List_Symbol(seq, NULL);
  f = FRONT_CONCAT (field, Symbol_fields(a), f);
  Symbol_fields(seq) = f;
  
  /* ALT_A -> ALT_A b a */
  PF ("%s :\n", name);
  PF ("  %s\n", name);
  print_rhs (b);
  print_rhs (Create_List_Symbol (a, NULL));
  PF ("  {\n");
  print_extra_fields (seq, syms, TRUE, TRUE, 2, rec, more);
  PF ("  }\n");
  PF (";\n\n");
}

/* Print an extra rule */
static void print_extrarule (ProdRule p)
{
  Symbol s = Extra_Rule_sym(p);
  String name = Ident_name (ProdRule_lhs(p));
  
/*
  if (Extra_Rule_alt(p) != NULL) {
    print_alt_rules (name, s, Extra_Rule_alt(p));
    return;
  }
*/   
  switch (Symbol_tag(s)) {
    case OnceSymbol_kind:
      print_once_rules (name, CompoundSym_sym(s));
      break;
    case OptSymbol_kind:
      print_opt_rules (name, CompoundSym_sym(s));
      break;
    case MoreSymbol_kind:
      if (!LeftRecursive) print_more_rules (name, CompoundSym_sym(s));
      else                print_rev_more_rules (name, CompoundSym_sym(s));
      break;
    case OptMoreSymbol_kind:
      if (!LeftRecursive) print_optmore_rules (name, CompoundSym_sym(s));
      else                print_rev_optmore_rules (name, CompoundSym_sym(s));
      break;
    case AltSymbol_kind:
      if (!LeftRecursive) print_alt_rules (name, AltSymbol_syms1(s), AltSymbol_syms(s));
      else                print_rev_alt_rules (name, AltSymbol_syms1(s), AltSymbol_syms(s));
    default:
      break;
  }
}

/* Print all production rules */
static void print_prodrules (void)
{
  List_ProdRule l;
  
  PF ("%%start %s\n\n",Rootstr);
  PF ("%%%%\n\n");
  
  for (l = prod_rules; l; l = List_ProdRule_next(l)) {
    print_prodrule (List_ProdRule_data(l));
  }
  
  PF ("/**** Extra rules ****/\n\n");
  
  for (l = extra_rules; l; l = List_Symbol_next(l)) {
    print_extrarule (List_Symbol_data(l));
  }
}

/************* Additional stuff like token and type declarations ***********/


/* Apply token_op to every terminal Token.
   Apply rule_op  to every non-terminal ProdRule.
*/
void 
for_all_rules (void (*token_op) (Token),
	       void (*rule_op)  (ProdRule))
{
  List_Token l;
  List_ProdRule p;
  List_Ident types = NULL;
  
  for (l = fixed_tokens; l; l = List_Token_next(l)) {
    if (token_op) token_op (List_Token_data(l));
  }
  for (l = var_tokens; l; l = List_Token_next(l)) {
    if (token_op) token_op (List_Token_data(l));
  }
  
  if (rule_op == NULL) return;
  
  for (p = prod_rules; p; p = List_ProdRule_next(p)) {
    ProdRule r = List_ProdRule_data(p);
    Ident id = ProdRule_lhs(r);
    if (contains_id (types, id)) continue;
    types = Create_List_Ident (id, types);
    
    rule_op (r);
  }
  
  for (p = extra_rules; p; p = List_ProdRule_next(p)) {
    ProdRule r = List_ProdRule_data(p);
    Ident id = ProdRule_lhs(r);
    if (!valid_extra(r)) continue;
    if (contains_id (types, id)) continue;
    types = Create_List_Ident (id, types);
    
    rule_op (r);
  }
}

/***************************/

/* Print a token declaration for a terminal symbol t */
static void print_token (Token t)
{ PF ("%%token %s\n", Ident_name(Token_id(t)));
}

/* Print a hole+start token declaration for a non-terminal r */
static void print_hole_start (ProdRule r)
{
  Ident id = ProdRule_lhs(r);
  NonTerminal nt = NULL;
  List_field fields = ProdRule_fields(r);
  
  if (multi_start==NULL) return;
  if (ProdRule_tag(r) == NT_Rule_kind) {
    nt = NT_Rule_nt(r);
    if (is_macro(nt) && List_field_size(fields)!=1) return;
  } else {
    if (List_field_size(fields)!=1) return;
  }
  
  PF ("%%token hole_%s\n", Ident_name(id));
  
#if 0
  if (nt && NonTerminal_super(nt) != NULL) return;
  if (nt && no_nt_type(nt)) return;
#endif
  PF ("%%token start_%s\n", Ident_name(id));
}

/* Print all token declarations */
static void print_tokens (void)
{
  PF ("%%token NONSENSE\n");;
  for_all_rules (print_token, print_hole_start);
  PF ("\n");
}

/**************** Union generation **********/

/* Print a type declaration for a terminal symbol id with type t */
static void term_type (Ident id, Ident t)
{ if (t==NULL) return;
  PF ("%s %s_type;\n", Ident_name(t), Ident_name(id));
}

/* Print a type declaration for a non-terminal symbol id with fields l */
static void fields_type (Ident id, List_field l)
{
  Int i;
  if (l == NULL) return;
  
  if (List_field_size(l)==1) {
    field f = List_field_data(l);
    remove_optional (f);
    Print_Ident (full_glue_type(field_type(f)));
    PF (" %s_type;\n", Ident_name(id));
    return;
  }
  
  /* More than one field, we need a struct */
  PF ("struct {\n");
  for (i=1; l; l = List_field_next(l), i++) {
    field f = List_field_data(l);
    List_TypeName t;
    remove_optional (f);
    set_type_struct (field_type(f));
    for (t = field_type(f); t; t = List_TypeName_next(t)) {
      set_root_type (List_TypeName_data(t));
    }
    t = field_type(f);
    PF ("  ");
    Print_Ident (full_glue_type(t));
    PF (" f%d;\n", i);
  }
  PF ("} %s_type;\n", Ident_name(id));
}

/* Generate a union element for terminal symbol t */
static void token_union (Token t)
{ term_type (Token_id(t), Token_type(t));
}

/* Generate a union element for non-terminal symbol r */
static void rule_union (ProdRule r)
{
  Ident id = ProdRule_lhs(r);
  List_field fields = ProdRule_fields(r);
  NonTerminal nt;
  
  switch (ProdRule_tag(r)) {
  case NT_Rule_kind: 
    nt = NT_Rule_nt (r);
    
    if (term_sub_type(nt)) {
      term_type (id, term_sub_type(nt));
      return;
    } else if (!is_macro(nt)) {
      struct_type type = Alternative_type (NonTerminal_alt(nt));
      if (no_nt_type(nt)) {
        Super s = NonTerminal_super(nt);
        String u = Ident_name(Super_id(s));
        term_type (id, Create_Ident(u));
      } else if (type!=NULL) {
        term_type (id, Type_ident(type));
      }
      return;
    }
    break;
  case Import_Rule_kind:
    term_type (ProdRule_lhs (r), Import_Rule_type (r));
    break;
  default:
    break;
  }
  fields_type (id, fields);
}

/* Generate the union for all symbol types */
static void print_union (void)
{  
  PF ("%%union {\n");
  for_all_rules (token_union, rule_union);  
  PF ("}\n\n");
}

/**************** Type-name generation **********/

/* Print a type-name declaration for symbol id */
static void print_type (Ident id)
{
  String s = Ident_name (id);
  PF ("%%type <%s_type>	%s\n", s, s);
}

/* Print a type-name declaration for terminal t */
static void token_type (Token t)
{
  print_type (Token_id(t));
}

/* Print a type-name declaration for non-terminal r */
static void rule_type (ProdRule r)
{ /* NonTerminal nt = NULL; */
/*   if (ProdRule_tag(r) == NT_Rule_kind) nt = NT_Rule_nt (r);  */
  
  print_type (ProdRule_lhs(r));
}

/* Print all type-name declarations */
static void print_types (void)
{
  for_all_rules (token_type, rule_type);
  PF ("\n");
}

/*************** Extra production rules for holes and starts ***********/

/* id : hole_id { $$ = (t)Get_sub_tree (); } */
static void hole_rule (Ident id, Ident t, Bool list)
{ String s = Ident_name(id);

  PF ("%s :\n", s);
  PF ("  hole_%s\n", s);
  if (list && LeftRecursive) {
    PF ("  { $$ = (%s)List_reverse((Front_List)Get_sub_tree ()); }\n", Ident_name(t));
  } else {
    PF ("  { $$ = (%s)Get_sub_tree (); }\n", Ident_name(t));
  }
  PF (";\n\n");
}

/* Root : { start_id id { Root_multi_action ((void*)$2); } */
static void start_rule (Ident id)
{ String s = Ident_name(id);

  PF ("%s :\n", Rootstr);
  PF ("  start_%s\n", s);
  PF ("  %s\n", s);
  PF ("  { %s_multi_action ((void*)$2); YYACCEPT; }\n", Rootstr);
  PF (";\n\n");
}

/* Generate a hole rule for nonterminal id with fields l */
static void print_hole_rule (Ident id, List_field l)
{
  field f;
  
  if (List_field_size(l)!=1) return;
  
  f = List_field_data(l);
  remove_optional (f);
  
  hole_rule (id, full_glue_type(field_type(f)), is_list_field(f));
}

/* Generate a start rule for nonterminal id with fields l */
static void print_start_rule (Ident id, List_field l)
{
  if (List_field_size(l)!=1) return;
  start_rule (id);
}

/* Generate a start/hole rules for terminal t */
static void multi_token (Token t)
{ NOT_USED(t);
}

/* Find the type and its name for a non-terminal or alternative */
struct_type nonterm_type (NonTerminal nt, Alternative alt, Ident *id)
{
  Super super = NULL;
  struct_type type = NULL;
  String x;
  
  if (alt == NULL && nt!=NULL) alt = NonTerminal_alt(nt); 
  
  if (alt==NULL) return NULL;
  
  if (nt) super = NonTerminal_super(nt);
  type = Alternative_type (alt);
#ifdef LabeledAlt_id
  x = Ident_name(LabeledAlt_id(alt));
#else
  x = Ident_name(PlainAlt_id(alt));
#endif
  
  if (type != NULL) {
    type = Root_type(type);
    *id = struct_type_tag(type);
    return type;
  }
  *id = prefix_type (Create_Ident(x));
  if (super == NULL) return NULL;
  x = Ident_name (Super_id(super));
  *id = prefix_type (Create_Ident(x));
  return find_type (Super_id(super));
}

/* Generate a start/hole rules for non-terminal r */
static void multi_rule (ProdRule r)
{ 
  Ident id = ProdRule_lhs(r);
  List_field fields = ProdRule_fields(r);
  
  if (ProdRule_tag(r) == NT_Rule_kind) {
    NonTerminal nt = NT_Rule_nt (r);
    Ident tid; 
    
    nonterm_type (nt, NULL, &tid);

    if (NonTerminal_scan(nt) != NULL) return;
    if (!is_macro(nt)) {
      hole_rule (id, tid, FALSE);
#if 0
      if (NonTerminal_super(nt) != NULL) return;
#endif
      start_rule (id);
      return;
    }
  }
  print_hole_rule (id, fields);
  print_start_rule (id, fields);
}

/* Generate hole/start rules */
static void print_multistart_rules (void)
{
  if (multi_start == NULL) return;
  for_all_rules (multi_token, multi_rule);
}

/**************************/

/* Print yacc preamble */
static void print_preamble (void)
{
  PF ("%%{\n");
  PF ("#include <string.h>\n");
  PF ("#include \"front/scan_support.h\"\n");
  PF ("#include \"front/parse_support.h\"\n");
  PF ("#include \"%s.h\"\n\n", Rootstr);
  PF ("extern int input_line_nr;\n\n");
  PF ("struct yy_buffer_state *%s_dummy_state (void);\n",Rootstr);
  PF ("struct yy_buffer_state *%s_scanner_state (void);\n",Rootstr);
  PF ("%%}\n\n");
}

/**************************/

/* Generate yacc file */
void GenGrammar (front f)
{
  get_prodrules (front_rules (f), front_imports (f));
  
  all_rules = FRONT_CONCAT (ProdRule, prod_rules, extra_rules);

  open_print_file (append_string (Rootstr, ".y"), TRUE);
  set_margin(0); set_position(0);
  
  print_preamble ();
  print_tokens   ();
  print_union    ();
  print_types    ();
  print_prodrules ();
  print_multistart_rules ();
  close_print_file();
}
