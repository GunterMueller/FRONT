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
#include <front/parse_support.h>
#include <front/basic_types.h>
#include "print_lalr.h"

static List_Production productions; 	/* All production rules */
static List_LR_state states;		/* All LALR states */
List_LR_Symbol all_symbols = NULL;	/* All terminal and non-terminal symbols */

#ifndef COPY_List_Ident
#define COPY_List_Ident(x) Traverse_copy_List_Ident(x, &front_copy_actions)
#endif

/*****************/

/* Numbering of rhs */
Int New_rhs_num (void)
{ static Int n = 0;
  return n++;
}

/*****************/

/* Test for terminal symbol */
Bool is_terminal (LR_Symbol s)
{
  return s != NULL && LR_Symbol_prods(s) == NULL;
}

/* Create a (unique) LR_Symbol with fields f */
LR_Symbol make_lr_symbol (Ident id, List_field f, Bool e)
{
  LR_Symbol s = Create_LR_Symbol (no_srcinfo, id, e);
  f = clean_fields(f);
  if (f) {
    if (LR_Symbol_fields(s)) {
      if (List_field_size(f) != List_field_size(LR_Symbol_fields(s))) {
        printf ("f\n"); Print_List_field (f);
        printf ("s\n"); Print_List_field (LR_Symbol_fields(s));
      }
      assert (List_field_size(f) == List_field_size(LR_Symbol_fields(s)));
    }
    LR_Symbol_fields(s) = f;
  }
  return s;
}

/* Insert a terminal/non-terminal (indicated by term) symbol in all_symbols */
static Bool add_symbol (LR_Symbol s, Bool term)
{
  if (!LR_Symbol_make_empty(s) && term == is_terminal(s)) {
    FRONT_INSERT (s, all_symbols);
  }
  return term;
}

void print_terms (TermSet f)
{
  for (; f; f = List_Ident_next(f)) {
    Print_Ident (List_Ident_data(f)); Print_String (" ");
  }
  Print_String ("\n");
}

/* Set union */
TermSet term_union (TermSet a, TermSet b)
{ Ident t;
  TermSet u;
  if (a==NULL) return b;
  if (b==NULL) return a;
  t = List_Ident_data(a);
  u = term_union (List_Ident_next(a), b);
  if (term_contains(b, t)) return u;
  
  return Create_List_Ident (t, u);
}

/* a := a + b */
TermSet term_unite (TermSet a, TermSet b)
{ Ident t;
  if (b==NULL) return a;
  t = List_Ident_data(b);
  FRONT_INSERT (t, a);
  term_unite (a, List_Ident_next(b));
  return a;
}

/* Set intersection */
static TermSet term_intersect (TermSet a, TermSet b)
{ Ident t;
  TermSet u;
  if (a==NULL) return NULL;
  if (b==NULL) return NULL;
  t = List_Ident_data(a);
  u = term_intersect (List_Ident_next(a), b);
  if (!term_contains(b, t)) return u;
  
  return Create_List_Ident (t, u);
}

/* Subset test  */
static Bool term_subset (TermSet a, TermSet b)
{ Ident t;
  if (a==NULL) return TRUE;
  if (b==NULL) return FALSE;
  t = List_Ident_data(a);
  if (!term_contains(b, t)) return FALSE;
  return term_subset (List_Ident_next(a), b);
}

/*****************/

/* List concatenation */
LR_Symbols append_lr_symbols (LR_Symbols l, LR_Symbols m)
{
  if (l==NULL) return m;
  if (m==NULL) return l;
  return Create_LR_Symbols (no_srcinfo, LR_Symbols_data(l),
                            append_lr_symbols (LR_Symbols_next(l), m));
}

/* Element concatenation */
static LR_Symbols append_lr_symbol (LR_Symbols l, LR_Symbol s)
{
  if (l==NULL) return Create_LR_Symbols (no_srcinfo, s, NULL);
  return Create_LR_Symbols (no_srcinfo, LR_Symbols_data(l), 
                            append_lr_symbol (LR_Symbols_next(l), s));
}

/* Make the rhs of a production rule */
static LR_Symbols make_rhs (List_Symbol l, Bool empty)
{ 
  LR_Symbols m = NULL;
  
  for (; l; l = List_Symbol_next(l)) {
    Symbol x = List_Symbol_data(l);
    String s = symbolname (x);
    LR_Symbol y;
    if (is_layout(x)) continue;
    if (strlen(s) == 0) continue;
    if (is_layout(x)) continue;
    assert (strcmp(s, "sym") != 0);
    if (Symbol_tag(x) == SymbolSeq_kind) {
      m = append_lr_symbols (m, make_rhs (SymbolSeq_symbols(x), empty));
      continue;
    }
    if (is_inlined_opt(x)) {
      List_Symbol l = flatten_syms(CompoundSym_sym(x));
      m = append_lr_symbols (m, make_rhs (l, Symbol_empty(x)));
      continue;
    }
    y = make_lr_symbol (Create_Ident(s), get_fields(x), empty);
    m = append_lr_symbol (m, y);
  }
  return m ;
}

/* Create a production rule */
static Production make_production (Ident lhs, List_Symbol rhs, ProdRule r, Int n)
{
  Production p = Create_Production (no_srcinfo, lhs, make_rhs (rhs, FALSE), TRUE, NULL);
  Production_prod_rule(p) = r;
  Production_num(p) = n;
  return p;
}

/* Create a front Symbol */
static Symbol make_symbol (Ident name)
{ Symbol s = Create_IdSym (no_srcinfo, name, NULL);
  IdSym_nt(s) = Parse_NonTerminal ("%Identsym ::= %Identsym ;", 2, name, name);
  return s;
}

/* Create the production rule ONCE_A -> A */
static List_Production make_once_rules (Ident name, List_Symbol syms, ProdRule r)
{ List_Symbol l;
  List_Production ps = NULL;
  Int i = 0;
  
  /* ONCE_A -> A */
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    Production p = make_production (name, Create_List_Symbol (s, NULL), r, i++);
    FRONT_APPEND_NODE (ps, p);
  }
  return ps;
}

/* Create the production rules OPT_A ->,  OPT_A -> A */
static List_Production make_opt_rules (Ident name, List_Symbol syms, ProdRule r)
{ List_Symbol l;
  List_Production ps = NULL;
  Int i = 0;
  Production p = make_production (name, NULL, r, i++);
  
  FRONT_APPEND_NODE (ps, p);
 
  /* OPT_A -> A */
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    p = make_production (name, Create_List_Symbol (s, NULL), r, i++);
    FRONT_APPEND_NODE (ps, p);
  }
  return ps;
}

/* Create the production rules MORE_A -> A, MORE_A -> A MORE_A */
static List_Production make_more_rules (Ident name, List_Symbol syms, ProdRule r)
{ List_Symbol l;
  List_Production ps = NULL;
  Int i = 0;
  
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    List_Symbol syms = Create_List_Symbol (s, NULL);
    
    /*  MORE_A -> A */
    Production p = make_production (name, syms, r, i++);
    FRONT_APPEND_NODE (ps, p);
    
    /* MORE_A -> A MORE_A */
    s = make_symbol (name);
    FRONT_APPEND_NODE (syms, s);
    p = make_production (name, syms, r, i++);
    FRONT_APPEND_NODE (ps, p);
  }
  return ps;
}

/* Create the production rules OPTMORE_A -> eps, OPTMORE_A -> A OPTMORE_A */
static List_Production make_optmore_rules (Ident name, List_Symbol syms, ProdRule r)
{ List_Symbol l;
  List_Production ps = NULL;
  Production p;
  Int i = 0;
  
  /* OPTMORE_A -> eps */
  p = make_production (name, NULL, r, i++);
  FRONT_APPEND_NODE (ps, p);
    
  /* OPTMORE_A -> A OPTMORE_A */
  for (l = syms; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    List_Symbol syms = Create_List_Symbol (s, NULL);
    s = make_symbol (name);
    FRONT_APPEND_NODE (syms, s);
    p = make_production (name, syms, r, i++);
    FRONT_APPEND_NODE (ps, p);
  }
  return ps;
}

/* Create the production rules ALT_A -> a, ALT_A -> a b ALT_A */
static List_Production make_alt_rules (Ident name, Symbol a, List_Symbol b, ProdRule r)
{   
  List_Production ps = NULL;
  Production p;
  List_Symbol syms = Create_List_Symbol (a, NULL);
  Symbol s;
  Int i = 0;
  
  /* ALT_A -> a */
  p = make_production (name, syms, r, i++);
  FRONT_APPEND_NODE (ps, p);
  
  /* ALT_A -> a b ALT_A */
  syms = Create_List_Symbol (a, COPY_List_Symbol(b));
  s = make_symbol (name);
  FRONT_APPEND_NODE (syms, s);
  p = make_production (name, syms, r, i++);
  FRONT_APPEND_NODE (ps, p);
  return ps;
}

/* Create the production rules for the Extra_Rule p */
static List_Production make_extrarule (ProdRule p)
{
  Symbol s = Extra_Rule_sym(p);
  Ident name = ProdRule_lhs(p);
  
  if (!valid_extra(p)) return NULL;
  
  switch (Symbol_tag(s)) {
    case OnceSymbol_kind:
      return make_once_rules (name, CompoundSym_sym(s), p);
    case OptSymbol_kind:
      return make_opt_rules (name, CompoundSym_sym(s), p);
    case MoreSymbol_kind:
      return make_more_rules (name, CompoundSym_sym(s), p);
    case OptMoreSymbol_kind:
      return make_optmore_rules (name, CompoundSym_sym(s), p);
    case AltSymbol_kind:
      return make_alt_rules (name, AltSymbol_syms1(s), AltSymbol_syms(s), p);
    default:
      break;
  }
  return NULL;
}

/* Create the production rules for the ProdRule p */
static List_Production make_production_rule (ProdRule r)
{ Ident id = ProdRule_lhs(r);
  Production p;
  
  switch (ProdRule_tag(r)) {
    case NT_Rule_kind:
      p = make_production (id, NT_Rule_rhs(r), r, 0);
      return Create_List_Production (p, NULL);
    case Extra_Rule_kind:
      return make_extrarule (r);
  }
  return NULL;
}

/* Create the production rules for the ProdRules l */
static List_Production make_productions (List_ProdRule l)
{
  ProdRule r;
  List_ProdRule next;
  List_Production p;
  
  if (l==NULL) return NULL;
  
  r = List_ProdRule_data(l);
  next = List_ProdRule_next(l);
  p = make_production_rule (r);
  if (p == NULL) return make_productions (next);
  FRONT_APPEND (p, make_productions (next));
  return p;
}

/**********/

/* Generate a start/hole rules for non-terminal r */
static List_Production make_multi_start_rule (ProdRule r, List_Production p)
{
  Ident id = ProdRule_lhs(r);
  List_field fields = ProdRule_fields(r);  
  LR_Symbol sym;
#if 0
  printf ("Multi start rule %s\n", Ident_name(ProdRule_lhs(r)));
  Print_ProdRule(r); Print_String ("\n");
#endif
  
  if (ProdRule_tag(r) == NT_Rule_kind) {
    NonTerminal nt = NT_Rule_nt (r);
    
    if (NonTerminal_scan(nt) != NULL) return p;
    
    if (!is_macro(nt)) {
      Ident tn = Create_Ident (Front_StrAllocf("%s_%s", Rootstr, Ident_name(id)));
      field f = Parse_field ("%Identsym me;", 1, tn);
      sym = make_lr_symbol (id, Create_List_field (f, NULL), FALSE);
      LR_Symbol_start(sym) = TRUE;
      LR_Symbol_hole (sym) = id;
      return p;
    }
    sym = make_lr_symbol (id, Rhs_fields(NonTerminal_rhs(nt)), FALSE);
  } else {
    Symbol x = Extra_Rule_sym(r);
    sym = make_lr_symbol (id, fields, FALSE);
    if (!valid_extra(r)) return p;
    switch (Symbol_tag(x)) {
      case OnceSymbol_kind:
      case OptSymbol_kind:
        return p;
      default:
        break;
    }
  }
  
  if (List_field_size(fields)!=1) return p;
  
  LR_Symbol_start(sym) = TRUE;
  LR_Symbol_hole (sym) = glue_type(field_type(List_field_data(fields)));
  return p;
}

/* Create the production rules for the ProdRule p */
static List_Production multi_start_productions (List_ProdRule l, List_Production p)
{
  ProdRule r;
  List_ProdRule next;
  
  if (multi_start == NULL) return p;
  
  if (l==NULL) return p;
  
  r = List_ProdRule_data(l);
  next = List_ProdRule_next(l);
  p = make_multi_start_rule (r, p);
  return multi_start_productions (next, p);
}

/********* Comparisons on items *****/

/* A -> .a for start symbol A */
Bool is_start (Item i)
{
  return Item_start_item(i);
}

/* A -> a.b, a non-empty */
Bool is_kernel (Item i)
{
  return Item_rhs1(i) != NULL || is_start(i);
}

/* A -> a. */
Bool is_completed (Item i)
{
  return Item_rhs2(i) == NULL;
}

/* Number of kernel items in l */
static Int num_kernel_items (List_Item l)
{
  Int n = 0;
  for (; l; l = List_Item_next(l)) {
    if (is_kernel (List_Item_data(l))) n++;
  }
  return n;
}

/* Comparison on symbol list */
static Bool same_symbols (List_LR_Symbol l, List_LR_Symbol m)
{
  for (; l && m; l = List_LR_Symbol_next(l), m = List_LR_Symbol_next(m)) {
    if (LR_Symbol_id(List_LR_Symbol_data(l)) != 
        LR_Symbol_id(List_LR_Symbol_data(m))) return FALSE;
  }
  return l==m;
}

/* Comparison on items */
static Bool same_item (Item i, Item j)
{
  if (Item_lhs(i) != Item_lhs(j)) return FALSE;
  if (Item_rhs2(i) != Item_rhs2(j)) return FALSE;
  if (!same_symbols (Item_rhs1(i), Item_rhs1(j))) return FALSE;
  return TRUE;
}

/* Membership test on items */
static Item contains_item (List_Item l, Item i)
{
  for (; l; l = List_Item_next(l)) {
    Item j = List_Item_data(l);
    if (same_item (j, i)) return j;
  }
  return NULL;
}

/* Comparison on states */
static Bool same_state (List_Item l, List_Item m)
{
  Int x = num_kernel_items (l);
  Int y = num_kernel_items (m);
  if (x != y) return FALSE;
  
  for (; l; l = List_Item_next(l)) {
    Item i = List_Item_data(l);
    Item j = contains_item (m, i);
    if (j == NULL) return FALSE;
    if (!is_kernel(j)) return FALSE;
  }
  return TRUE;
}

/* Check whether a state with items equal to 'items' is in states */
static LR_state state_exists (List_Item items, List_LR_state states)
{
  LR_state state;
  
  if (states==NULL) return NULL;
  state = List_LR_state_data(states);
  if (same_state   (items, LR_state_items (state))) return state;
  return state_exists (items, List_LR_state_next(states));
}

/* Combine the properties of i and j into i */
static void unite_item (Item i, Item j)
{
  Item_followers (i) = term_union (Item_followers (i), Item_followers (j));
  Item_predecessors(i) = FRONT_CONCAT (Item, Item_predecessors(i), Item_predecessors(j));
}

/* Combine the properties of common items of a and b into b */
static void unite_items (List_Item a, List_Item b)
{
  for (; b; b = List_Item_next(b)) {
    Item i = List_Item_data(b);
    Item j = contains_item (a, i);
    unite_item (j, i);
  }
}

/*****************/

/* Test for emptiness */
static Bool prod_empty (Production p);

/* Test for emptiness */
static Bool _can_be_empty (LR_Symbol s)
{
  List_Production ps;
  
  if (LR_Symbol_make_empty(s)) return TRUE;

  for (ps = LR_Symbol_prods(s); ps; ps = List_Production_next(ps)) {
    if (prod_empty (List_Production_data(ps))) return TRUE;
  }
  return FALSE;
}

/* Test for emptiness */
Bool can_be_empty (LR_Symbol s)
{
  switch (LR_Symbol_empty_eval(s)) {
    case UnEval:
      LR_Symbol_empty_eval(s) = UnderEval;
      LR_Symbol_empty(s) = _can_be_empty (s);
      LR_Symbol_empty_eval(s) = Evaluated;
      break;
    case UnderEval:
    case Evaluated:
    case EvalCyclic:
      break;
  }
  return LR_Symbol_empty(s);
}

/* Test for emptiness */
Bool emptiness (LR_Symbols l)
{  
  if (l==NULL) return TRUE;
  return can_be_empty (LR_Symbols_data(l)) && emptiness (LR_Symbols_next(l));
}

/* Test for emptiness */
static Bool prod_empty (Production p)
{
  Production_empty(p) = emptiness (Production_rhs(p));
  return Production_empty(p);
}

/* Compute emptiness for all production rules */
static void compute_empty (List_Production l)
{
  for (; l; l = List_Production_next(l)) {
    Production p = List_Production_data(l);
    Production_empty(p) = emptiness (Production_rhs(p));
  }
}

/*****************/

/* Set of first symbols of p */
static TermSet prod_first (Production p);

/* first A:b = first a + (first b if can_be_empty A), 
   where A->a is a rule for A
*/
static TermSet _first (LR_Symbol s)
{
  List_Production ps;
  TermSet g = NULL;
  Ident id;
  
  if (LR_Symbol_hole(s)) {
    id = Create_Ident (Front_StrAllocf("hole_%s", Ident_name(LR_Symbol_id(s))));
    g = Create_List_Ident (id, g);
  }
  if (is_terminal(s)) {
    id = LR_Symbol_id(s);
    g = Create_List_Ident (id, g);
    return g;
  }
  
  for (ps = LR_Symbol_prods(s); ps; ps = List_Production_next(ps)) {
    Production p = List_Production_data(ps);
    g = term_unite (g, prod_first(p));
  }
  return g;
}

/* Set of first symbols of s */
static TermSet first (LR_Symbol s)
{
  switch (LR_Symbol_first_eval(s)) {
    case UnEval:
      LR_Symbol_first_eval(s) = UnderEval;
      LR_Symbol_first(s) = _first (s);
      LR_Symbol_first_eval(s) = Evaluated;
      break;
    case UnderEval:
    case Evaluated:
    case EvalCyclic:
      break;
  }
  return LR_Symbol_first(s);
}

/* Followers (l, f) = first(l) + (f if can_be_empty l) */
TermSet followers (LR_Symbols l, TermSet f)
{
  LR_Symbol s;
  
  if (l==NULL) return f;
  s = LR_Symbols_data(l);
  l = LR_Symbols_next(l);
  if (!can_be_empty(s)) return first(s);
  return term_union (first(s), followers (l, f));
}

/* Set of first symbols of p */
static TermSet prod_first (Production p)
{
  Production_first(p) = followers (Production_rhs(p), NULL);
  return Production_first(p);
}

/* Computeb the first symbol sets for all productions */
static void compute_first (List_Production l)
{
  for (; l; l = List_Production_next(l)) {
    Production p = List_Production_data(l);
    Production_first(p) = prod_first (p);
  }
}

/*****************/

/* Add the closure of l to state */
static List_Item closure (List_Item l, List_Item state)
{ Item i, j;
  if (l == NULL) return state;
  i = List_Item_data(l);
  l = List_Item_next(l);
  j = contains_item (state, i);
  if (j == NULL) {
    FRONT_APPEND_NODE (state, i);
    if (Item_rhs2(i) != NULL) {
      LR_Symbol s = List_LR_Symbol_data(Item_rhs2(i));
      List_Production ps;
      for (ps = LR_Symbol_prods(s); ps; ps = List_Production_next(ps)) {
        Production p = List_Production_data(ps);
	TermSet folls = followers (List_LR_Symbol_next(Item_rhs2(i)), Item_followers(i));
	j = Create_Item (no_srcinfo, Production_lhs(p), NULL, Production_rhs(p), folls);
	Item_production(j) = p;
        FRONT_APPEND_NODE (l, j);
	FRONT_APPEND_NODE (Item_predecessors(j), i);
      }
    }
  } else {
    unite_item (j, i);
  }
  return closure (l, state);
}

static Bool changed; /* Fix-point reached yet? */

static LR_state cur_state; /* Current state */

/* Set current state to s */
static void close_state (LR_state s)
{  cur_state = s;
}

/* Closure of the followers set of an item */
static void close_follow (Item item)
{
  List_Item l;
  TermSet f = Item_followers(item);
  for (l = Item_predecessors(item); l; l = List_Item_next(l)) {
    Item j = List_Item_data(l);
    TermSet g = COPY_List_Ident (Item_followers(j));
    if (!is_kernel (item)) {
      g = followers (List_Item_next(Item_rhs2(j)), g);
    }
    if (term_subset (g, f)) continue;
    f = term_union (f, g);
    changed = TRUE;
  }
  Item_followers(item) = f;
}

/* Compute the closure of the follower sets of all items in all states */
static void close_followers (List_LR_state states)
{ 
  static struct s_void_Lalr_TraverseTable tab;
  tab.action_LR_state[PRE_ACTION] = close_state;
  tab.action_Item[POST_ACTION] = close_follow;
  
  do {
    changed = FALSE;
    Traverse_void_List_LR_state (states, &tab);
  } while (changed);
}

/*****************/

static List_LR_state make_states (List_Item items, List_LR_state states, LR_state state, LR_Symbol sym);

/* Compute next state from state l under transition s */
static List_Item goto_state (List_Item l, Ident s)
{ List_Item g = NULL;

  for (; l; l = List_Item_next(l)) {
    Item item = List_Item_data(l);
    LR_Symbols rhs = Item_rhs2(item);
    LR_Symbol t = NULL;
    Item j;
    
    for (rhs = Item_rhs2(item); rhs; rhs = LR_Symbols_next(rhs)) {
      t = List_LR_Symbol_data(rhs);
      if (!LR_Symbol_make_empty(t)) break;
    }
    if (t == NULL || LR_Symbol_id(t) != s) continue;
    /* Shift the dot in item */
    j = Create_Item (no_srcinfo, Item_lhs(item), 
                     FRONT_CONCAT_NODE(LR_Symbol, Item_rhs1(item), t), 
		     LR_Symbols_next(rhs), NULL);
    Item_production(j) = Item_production(item);
    FRONT_APPEND_NODE (g, j);
    FRONT_APPEND_NODE (Item_predecessors(j), item);
  }
  return g;
}

/* Extend the set of states 'states' with new states 
   under transition of all 'items' in 'state' 
*/
static List_LR_state gotos (List_Item items, LR_state state, List_LR_state states)
{ Item item;
  LR_Symbols rhs;
  
  if (items == NULL) return states;
  item  = List_Item_data(items);
  items = List_Item_next(items);
  states = gotos (items, state, states);
  for (rhs = Item_rhs2(item); rhs; rhs = LR_Symbols_next(rhs)) {
    LR_Symbol s = LR_Symbols_data(rhs);
    List_Item next;
    if (LR_Symbol_make_empty(s)) continue;
    next = goto_state (LR_state_items(state), LR_Symbol_id(s));
    states = make_states (next, states, state, s);
    break;
  }
  return states;
}

/* Test whether l contains a transitions under s */
static Bool contains_transition (List_Transition l, LR_Symbol s)
{
  for (; l; l = List_Transition_next(l)) {
    if (Transition_symbol(List_Transition_data(l)) == s) return TRUE;
  }
  return FALSE;
}

/* Add a transition from 'from' under sym to 'to' 
   to the transitions in from
*/
static void add_transition (LR_state from, LR_Symbol sym, LR_state to)
{
  Transition trans;
  
  if (from==NULL) return;
  if (contains_transition(LR_state_transitions(from), sym)) return;
  
  trans = Create_Transition (no_srcinfo, sym, LR_state_num(to));
  Transition_target(trans) = to;
  FRONT_APPEND_NODE (LR_state_transitions(from), trans);
}

/* Compute the start state for start symbol sym */
static List_Item start_state (LR_Symbol sym)
{
  String eof = Front_StrAllocf("%s_EOF", Rootstr);
  TermSet folls = Create_List_Ident (Create_Ident(eof), NULL);
  List_Item items = NULL;
  List_Production l;
  
  if (!LR_Symbol_start(sym)) return NULL;
  
  Traverse_void_Lalr_LR_Symbol (sym, &Lalr_applied_actions);
  
  for (l = LR_Symbol_prods(sym); l; l = List_Production_next(l)) {
    Production start = List_Production_data(l);
    Item item = Create_Item (no_srcinfo, Production_lhs(start), NULL, Production_rhs(start), folls);
    Item_start_item (item) = TRUE;
    Item_production (item) = start;
    FRONT_APPEND_NODE (items, item);
  }
  return items;
}

/* Add a new state 'items' to states.
   The new state originated from a transition from prev under sym.
   prev and sym are NULL for start states.
   Also add transitively all states reachable from transitions from the new state.
*/
static List_LR_state make_states (List_Item items, List_LR_state states, LR_state prev, LR_Symbol sym)
{
  LR_state state;
  static Int num = 0;
  
  if (items==NULL) return states;
  
  state = state_exists (items, states);
  if (state) {
    unite_items (LR_state_items(state), items);
    add_transition (prev, sym, state);
    return states;
  }
  items = closure (items, NULL);
  state = Create_LR_state (no_srcinfo, num++, items, NULL);
  add_transition (prev, sym, state);
  FRONT_APPEND_NODE (states, state);
  
  if (prev==NULL) {
    /* Start state */
    Item item = List_Item_data(items);
    LR_Symbol sym = make_lr_symbol (Item_lhs(item), NULL, FALSE);
    LR_Symbol_start_state(sym) = state;
    LR_state_start_state(state) = sym;
  }
  
  fflush (stdout);
  return gotos (items, state, states);
}

/* Create the states for all production rules */
static List_LR_state create_states (void)
{
  LR_Symbol root = make_lr_symbol (Rootid, Parse_OPTMORE_field("%Identsym me;", 1, Rootid), FALSE);
  List_LR_Symbol l;
  List_LR_state states = NULL;

  LR_Symbol_start(root) = TRUE;
  add_symbol (root, FALSE);
  Traverse_void_Lalr_LR_Symbol (root, &Lalr_applied_actions);
  
  for (l = all_symbols; l; l = List_LR_Symbol_next(l)) {
    LR_Symbol sym = List_LR_Symbol_data(l);
    Traverse_void_Lalr_LR_Symbol (sym, &Lalr_applied_actions);
    if (is_terminal(sym)) continue;
    states = make_states (start_state(sym), states, NULL, NULL);
  }
  return states;
}

/**************/

/* Sort productions, non-empty ones first */
static void sort_productions (void)
{
  List_LR_Symbol l;
  for (l = all_symbols; l; l = List_LR_Symbol_next(l)) {
    LR_Symbol x = List_LR_Symbol_data(l);
    List_Production ps;
    List_Production empty = NULL;
    List_Production non_empty = NULL;

    for (ps = LR_Symbol_prods(x); ps; ps = List_Production_next(ps)) {
      Production p = List_Production_data(ps);
      if (Production_empty(p)) FRONT_APPEND_NODE (empty, p);
      else FRONT_APPEND_NODE (non_empty, p);
    }
    FRONT_APPEND (non_empty, empty);
    LR_Symbol_prods(x) = non_empty;
  }
}

/****************/

/* Insert a terminal/non-terminal (indicated by term) symbol in all_symbols */
static Bool add_nt_symbol (Production p, Bool term)
{ LR_Symbol s;
  ProdRule r;
  
  if (term) return term;
  
  r = Production_prod_rule(p);
  s = make_lr_symbol (Production_lhs(p), NULL, FALSE);
  FRONT_INSERT (s, all_symbols);
  return term;
}

/* Compute all terminal and non-terminal symbols in all_symbols */
static void compute_symbols (Lalr lalr)
{
  static struct s_Lalr_TraverseTable tab;
  tab.action_Production[POST_ACTION] = (void*)add_nt_symbol;
  tab.action_LR_Symbol[POST_ACTION] = (void*)add_symbol;
  
  Traverse_Lalr (lalr, &tab, (void*)TRUE);
  Traverse_Lalr (lalr, &tab, (void*)FALSE);
}

/**************/

/* Report the shift-reduce conflicts in state */
static void find_shift_reduce_conflicts (LR_state state)
{
  List_Transition t;
  List_Item l;
  
  for (t = LR_state_transitions(state); t; t = List_Transition_next(t)) {
    Transition trans = List_Transition_data(t);
    LR_Symbol s = Transition_symbol(trans);
    Ident id = LR_Symbol_id(s);
    
    for (l = LR_state_items(state); l; l = List_Item_next(l)) {
      Item item = List_Item_data(l);
      if (!is_completed(item)) continue;
      if (!term_contains(Item_followers(item), id)) continue;
      FrontWarning (TRUE, 5, "Shift-reduce conflict for symbol %s in state %d", Ident_name(id), LR_state_num(state));
      Item_conflict(item) = TRUE;
    }
  }
}

/* Report the reduce-reduce conflicts in state */
static void find_reduce_reduce_conflicts (LR_state state)
{
  List_Item l, m;
  for (l = LR_state_items(state); l; l = List_Item_next(l)) {
    Item i = List_Item_data(l);
    if (!is_completed(i)) continue;
    for (m = List_Item_next(l); m; m = List_Item_next(m)) {
      Item j = List_Item_data(m);
      TermSet conflicts;
      if (!is_completed(j)) continue;
      conflicts = term_intersect (Item_followers(i), Item_followers(j));
      for (; conflicts; conflicts = List_Ident_next(conflicts)) {
        Ident id = List_Ident_data(conflicts);
	FrontWarning (TRUE, 5, "Reduce-reduce conflict for symbols %s in state %d", Ident_name(id), LR_state_num(state));
        Item_conflict(j) = TRUE;
      }
    }
  }
}

/* Report the conflicts in state */
static void find_conflicts (List_LR_state l)
{
  for (; l; l = List_LR_state_next(l)) {
    LR_state s = List_LR_state_data(l);
    find_shift_reduce_conflicts (s);
    find_reduce_reduce_conflicts (s);
  }
}

/**************/

/* Create Lalr object and generate code for it */
Lalr GenLalr (List_ProdRule l)
{ 

  Lalr lalr = NULL;
  
  productions = make_productions (l);
  productions = multi_start_productions (l, productions);
    
  lalr = Create_Lalr (no_srcinfo, productions, states);
  Decorate_Lalr (lalr);
  compute_symbols (lalr);
  compute_empty (productions);
  compute_first (productions);
  sort_productions ();
  
  states = create_states ();
  Lalr_states(lalr) = states;
  close_followers (states);
  find_conflicts (states);

  Print_lalr (lalr);
  
  return lalr;
}
