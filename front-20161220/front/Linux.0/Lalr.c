#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "front/error.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/mem.h"
#include "Lalr.h"

#ifndef Lalr_SKIP_NODE
# define Lalr_SKIP_NODE(n,t) FALSE
#endif

Lalr Lalr_root;

Lalr_Lalr Create_Lalr_Lalr	(SrcInfo src_info, List_Lalr_Production grammar, List_Lalr_LR_state states)
{ Lalr_Lalr me = (Lalr_Lalr)fe_malloc(sizeof(*me));
  Lalr_Lalr_src_info(me) = src_info;
  Lalr_Lalr_grammar(me) = grammar;
  Lalr_Lalr_states(me) = states;
  return me;
}

Lalr_Production Create_Lalr_Production	(SrcInfo src_info, Ident lhs, Lalr_LR_Symbols rhs, Lalr_Emptiness empty, List_Ident first)
{ Lalr_Production me = (Lalr_Production)fe_malloc(sizeof(*me));
  Lalr_Production_src_info(me) = src_info;
  Lalr_Production_lhs(me) = lhs;
  Lalr_Production_rhs(me) = rhs;
  Lalr_Production_empty(me) = empty;
  Lalr_Production_first(me) = first;
  Lalr_Production__num(me) = - 1;
  Lalr_Production_scope(me) = NULL;
  Lalr_Production_old_scope(me) = NULL;
  Lalr_Production_lhs_bind(me) = NULL;
  Lalr_Production_prod_rule(me) = NULL;
  Lalr_Production_num(me) = 0;
  return me;
}

static Lalr_LR_Symbol *Lalr_LR_Symbol_memo_table = NULL;

void Memo_Traverse_Lalr_LR_Symbol (void (*f)(Lalr_LR_Symbol))
{ int i;
  for (i=0; i < 1024; i++) {
    Lalr_LR_Symbol _qqqq;
    for (_qqqq = Lalr_LR_Symbol_memo_table[i]; _qqqq != NULL; _qqqq = _qqqq->memo_link) {
      f(_qqqq);
    }
  }
}

void Memo_Clear_Lalr_LR_Symbol (void)
{ int i;
  if (!Lalr_LR_Symbol_memo_table) return;
  for (i=0; i < 1024; i++) {
    Lalr_LR_Symbol_memo_table[i] = NULL;
  }
}

Lalr_LR_Symbol Create_Lalr_LR_Symbol	(SrcInfo src_info, Ident id, Bool make_empty)
{ Lalr_LR_Symbol me;
  {
    unsigned int _hash = (0+(unsigned int)id+(unsigned int)make_empty)/sizeof(int*) % 1024;
    Lalr_LR_Symbol *_qqqq;
    if (Lalr_LR_Symbol_memo_table==NULL)
    { int i;
      Lalr_LR_Symbol_memo_table = (Lalr_LR_Symbol*)fe_malloc (sizeof(*Lalr_LR_Symbol_memo_table)*1024);
      for (i=0; i < 1024; i++){ Lalr_LR_Symbol_memo_table[i] = NULL; }
    }
    for (_qqqq = &Lalr_LR_Symbol_memo_table[_hash]; *_qqqq != NULL; _qqqq = &(*_qqqq)->memo_link) {
      if (Lalr_LR_Symbol_id(*_qqqq) > id) break;
      if (Lalr_LR_Symbol_id(*_qqqq) < id) continue;
      if (Lalr_LR_Symbol_make_empty(*_qqqq) > make_empty) break;
      if (Lalr_LR_Symbol_make_empty(*_qqqq) < make_empty) continue;
      return *_qqqq;
    }
    me = (Lalr_LR_Symbol)fe_malloc (sizeof(*me));
    me->memo_link = *_qqqq;
    *_qqqq = me;
  }
  Lalr_LR_Symbol_src_info(me) = src_info;
  Lalr_LR_Symbol_id(me) = id;
  Lalr_LR_Symbol_make_empty(me) = make_empty;
  Lalr_LR_Symbol__num(me) = - 1;
  Lalr_LR_Symbol_scope(me) = NULL;
  Lalr_LR_Symbol_old_scope(me) = NULL;
  Lalr_LR_Symbol_memo_link(me) = Lalr_LR_Symbol_memo_link (me);
  Lalr_LR_Symbol_prods_bind(me) = NULL;
  Lalr_LR_Symbol_prods(me) = NULL;
  Lalr_LR_Symbol_fields(me) = NULL;
  Lalr_LR_Symbol_first(me) = NULL;
  Lalr_LR_Symbol_empty(me) = TRUE;
  Lalr_LR_Symbol_first_eval(me) = UnEval;
  Lalr_LR_Symbol_empty_eval(me) = UnEval;
  Lalr_LR_Symbol_start(me) = FALSE;
  Lalr_LR_Symbol_hole(me) = NULL;
  Lalr_LR_Symbol_start_state(me) = NULL;
  Lalr_LR_Symbol_num(me) = 0;
  Lalr_LR_Symbol_hole_num(me) = 0;
  return me;
}

static Lalr_LR_Symbols *Lalr_LR_Symbols_memo_table = NULL;

void Memo_Traverse_Lalr_LR_Symbols (void (*f)(Lalr_LR_Symbols))
{ int i;
  for (i=0; i < 1024; i++) {
    Lalr_LR_Symbols _qqqq;
    for (_qqqq = Lalr_LR_Symbols_memo_table[i]; _qqqq != NULL; _qqqq = _qqqq->memo_link) {
      f(_qqqq);
    }
  }
}

void Memo_Clear_Lalr_LR_Symbols (void)
{ int i;
  if (!Lalr_LR_Symbols_memo_table) return;
  for (i=0; i < 1024; i++) {
    Lalr_LR_Symbols_memo_table[i] = NULL;
  }
}

Lalr_LR_Symbols Create_Lalr_LR_Symbols	(SrcInfo src_info, Lalr_LR_Symbol data, Lalr_LR_Symbols next)
{ Lalr_LR_Symbols me;
  {
    unsigned int _hash = (0+(unsigned int)data+(unsigned int)next)/sizeof(int*) % 1024;
    Lalr_LR_Symbols *_qqqq;
    if (Lalr_LR_Symbols_memo_table==NULL)
    { int i;
      Lalr_LR_Symbols_memo_table = (Lalr_LR_Symbols*)fe_malloc (sizeof(*Lalr_LR_Symbols_memo_table)*1024);
      for (i=0; i < 1024; i++){ Lalr_LR_Symbols_memo_table[i] = NULL; }
    }
    for (_qqqq = &Lalr_LR_Symbols_memo_table[_hash]; *_qqqq != NULL; _qqqq = &(*_qqqq)->memo_link) {
      if (Lalr_LR_Symbols_data(*_qqqq) > data) break;
      if (Lalr_LR_Symbols_data(*_qqqq) < data) continue;
      if (Lalr_LR_Symbols_next(*_qqqq) > next) break;
      if (Lalr_LR_Symbols_next(*_qqqq) < next) continue;
      return *_qqqq;
    }
    me = (Lalr_LR_Symbols)fe_malloc (sizeof(*me));
    me->memo_link = *_qqqq;
    *_qqqq = me;
  }
  Lalr_LR_Symbols_src_info(me) = src_info;
  Lalr_LR_Symbols_data(me) = data;
  Lalr_LR_Symbols_next(me) = next;
  Lalr_LR_Symbols_memo_link(me) = Lalr_LR_Symbols_memo_link (me);
  Lalr_LR_Symbols_num(me) = New_rhs_num ();
  return me;
}

Lalr_LR_state Create_Lalr_LR_state	(SrcInfo src_info, Int num, List_Lalr_Item items, List_Lalr_Transition transitions)
{ Lalr_LR_state me = (Lalr_LR_state)fe_malloc(sizeof(*me));
  Lalr_LR_state_src_info(me) = src_info;
  Lalr_LR_state_num(me) = num;
  Lalr_LR_state_items(me) = items;
  Lalr_LR_state_transitions(me) = transitions;
  Lalr_LR_state_start_state(me) = NULL;
  return me;
}

Lalr_Item Create_Lalr_Item	(SrcInfo src_info, Ident lhs, List_Lalr_LR_Symbol rhs1, Lalr_LR_Symbols rhs2, List_Ident followers)
{ Lalr_Item me = (Lalr_Item)fe_malloc(sizeof(*me));
  Lalr_Item_src_info(me) = src_info;
  Lalr_Item_lhs(me) = lhs;
  Lalr_Item_rhs1(me) = rhs1;
  Lalr_Item_rhs2(me) = rhs2;
  Lalr_Item_followers(me) = followers;
  Lalr_Item_production(me) = NULL;
  Lalr_Item_predecessors(me) = NULL;
  Lalr_Item_start_item(me) = FALSE;
  Lalr_Item_conflict(me) = FALSE;
  return me;
}

Lalr_Transition Create_Lalr_Transition	(SrcInfo src_info, Lalr_LR_Symbol symbol, Int num)
{ Lalr_Transition me = (Lalr_Transition)fe_malloc(sizeof(*me));
  Lalr_Transition_src_info(me) = src_info;
  Lalr_Transition_symbol(me) = symbol;
  Lalr_Transition_num(me) = num;
  Lalr_Transition_target(me) = NULL;
  Lalr_Transition_conflict(me) = FALSE;
  return me;
}

Lalr_Scope Create_Lalr_Scope	(Lalr_Scope next)
{ Lalr_Scope me = (Lalr_Scope)fe_malloc(sizeof(*me));
  Lalr_Scope_next(me) = next;
  Lalr_Scope__self(me) = 0;
  Lalr_Scope__end(me) = 0;
  return me;
}

Pointer Traverse_Lalr_Lalr (Lalr_Lalr me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(Lalr, me)) return val;
  if (action->action_Lalr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Lalr[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Lalr)
  { 
  if (!action->skip_children_Lalr) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_Production (Lalr_Lalr_grammar(me), action, val);
    else Traverse_List_Lalr_Production (Lalr_Lalr_grammar(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_LR_state (Lalr_Lalr_states(me), action, val);
    else Traverse_List_Lalr_LR_state (Lalr_Lalr_states(me), action, val);
  }
  }
  if (action->action_Lalr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Lalr[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Lalr_Production (Lalr_Production me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(Production, me)) return val;
  if (action->action_Production[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Production[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Production)
  { 
  if (!action->skip_children_Production) {
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_LR_Symbols (Lalr_Production_rhs(me), action, val);
    else Traverse_Lalr_LR_Symbols (Lalr_Production_rhs(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_Emptiness (Lalr_Production_empty(me), action, val);
    else Traverse_Lalr_Emptiness (Lalr_Production_empty(me), action, val);
  }
  }
  if (action->action_Production[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Production[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Lalr_LR_Symbol (Lalr_LR_Symbol me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(LR_Symbol, me)) return val;
  if (action->action_LR_Symbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_LR_Symbol[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_LR_Symbol)
  { 
  }
  if (action->action_LR_Symbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_LR_Symbol[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Lalr_LR_Symbols (Lalr_LR_Symbols me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(LR_Symbols, me)) return val;
  if (action->action_LR_Symbols[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_LR_Symbols[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_LR_Symbols)
  { 
  if (!action->skip_children_LR_Symbols) {
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_LR_Symbol (Lalr_LR_Symbols_data(me), action, val);
    else Traverse_Lalr_LR_Symbol (Lalr_LR_Symbols_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_LR_Symbols (Lalr_LR_Symbols_next(me), action, val);
    else Traverse_Lalr_LR_Symbols (Lalr_LR_Symbols_next(me), action, val);
  }
  }
  if (action->action_LR_Symbols[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_LR_Symbols[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Lalr_LR_state (Lalr_LR_state me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(LR_state, me)) return val;
  if (action->action_LR_state[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_LR_state[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_LR_state)
  { 
  if (!action->skip_children_LR_state) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_Item (Lalr_LR_state_items(me), action, val);
    else Traverse_List_Lalr_Item (Lalr_LR_state_items(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_Transition (Lalr_LR_state_transitions(me), action, val);
    else Traverse_List_Lalr_Transition (Lalr_LR_state_transitions(me), action, val);
  }
  }
  if (action->action_LR_state[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_LR_state[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Lalr_Item (Lalr_Item me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(Item, me)) return val;
  if (action->action_Item[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Item[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Item)
  { 
  if (!action->skip_children_Item) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_LR_Symbol (Lalr_Item_rhs1(me), action, val);
    else Traverse_List_Lalr_LR_Symbol (Lalr_Item_rhs1(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_LR_Symbols (Lalr_Item_rhs2(me), action, val);
    else Traverse_Lalr_LR_Symbols (Lalr_Item_rhs2(me), action, val);
  }
  }
  if (action->action_Item[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Item[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Lalr_Transition (Lalr_Transition me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(Transition, me)) return val;
  if (action->action_Transition[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Transition[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Transition)
  { 
  if (!action->skip_children_Transition) {
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_LR_Symbol (Lalr_Transition_symbol(me), action, val);
    else Traverse_Lalr_LR_Symbol (Lalr_Transition_symbol(me), action, val);
  }
  }
  if (action->action_Transition[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Transition[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Lalr_Scope (Lalr_Scope me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(Scope, me)) return val;
  if (action->action_Scope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Scope)
  { 
  if (!action->skip_children_Scope) {
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_Scope (Lalr_Scope_next(me), action, val);
    else Traverse_Lalr_Scope (Lalr_Scope_next(me), action, val);
  }
  }
  if (action->action_Scope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(List_LR_Symbols, me)) return val;
  if (action->action_List_LR_Symbols[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_LR_Symbols[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_LR_Symbols)
  { 
  if (!action->skip_children_List_LR_Symbols) {
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_LR_Symbols (List_Lalr_LR_Symbols_data(me), action, val);
    else Traverse_Lalr_LR_Symbols (List_Lalr_LR_Symbols_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols_next(me), action, val);
    else Traverse_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols_next(me), action, val);
  }
  }
  if (action->action_List_LR_Symbols[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_LR_Symbols[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(List_LR_Symbol, me)) return val;
  if (action->action_List_LR_Symbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_LR_Symbol[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_LR_Symbol)
  { 
  if (!action->skip_children_List_LR_Symbol) {
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_LR_Symbol (List_Lalr_LR_Symbol_data(me), action, val);
    else Traverse_Lalr_LR_Symbol (List_Lalr_LR_Symbol_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol_next(me), action, val);
    else Traverse_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol_next(me), action, val);
  }
  }
  if (action->action_List_LR_Symbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_LR_Symbol[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Lalr_Transition (List_Lalr_Transition me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(List_Transition, me)) return val;
  if (action->action_List_Transition[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Transition[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Transition)
  { 
  if (!action->skip_children_List_Transition) {
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_Transition (List_Lalr_Transition_data(me), action, val);
    else Traverse_Lalr_Transition (List_Lalr_Transition_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_Transition (List_Lalr_Transition_next(me), action, val);
    else Traverse_List_Lalr_Transition (List_Lalr_Transition_next(me), action, val);
  }
  }
  if (action->action_List_Transition[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Transition[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Lalr_Item (List_Lalr_Item me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(List_Item, me)) return val;
  if (action->action_List_Item[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Item[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Item)
  { 
  if (!action->skip_children_List_Item) {
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_Item (List_Lalr_Item_data(me), action, val);
    else Traverse_Lalr_Item (List_Lalr_Item_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_Item (List_Lalr_Item_next(me), action, val);
    else Traverse_List_Lalr_Item (List_Lalr_Item_next(me), action, val);
  }
  }
  if (action->action_List_Item[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Item[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Lalr_LR_state (List_Lalr_LR_state me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(List_LR_state, me)) return val;
  if (action->action_List_LR_state[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_LR_state[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_LR_state)
  { 
  if (!action->skip_children_List_LR_state) {
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_LR_state (List_Lalr_LR_state_data(me), action, val);
    else Traverse_Lalr_LR_state (List_Lalr_LR_state_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_LR_state (List_Lalr_LR_state_next(me), action, val);
    else Traverse_List_Lalr_LR_state (List_Lalr_LR_state_next(me), action, val);
  }
  }
  if (action->action_List_LR_state[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_LR_state[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Lalr_Production (List_Lalr_Production me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(List_Production, me)) return val;
  if (action->action_List_Production[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Production[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Production)
  { 
  if (!action->skip_children_List_Production) {
    if (action->traversal != Traverse_Down)  val = Traverse_Lalr_Production (List_Lalr_Production_data(me), action, val);
    else Traverse_Lalr_Production (List_Lalr_Production_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Lalr_Production (List_Lalr_Production_next(me), action, val);
    else Traverse_List_Lalr_Production (List_Lalr_Production_next(me), action, val);
  }
  }
  if (action->action_List_Production[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Production[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Lalr_Emptiness (Lalr_Emptiness me, TraverseTable action, Pointer val)
{ 
  if (Lalr_SKIP_NODE(Emptiness, me)) return val;
  if (action->action_Emptiness[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Emptiness[PRE_ACTION](me, val);
  }
  {   }
  if (action->action_Emptiness[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Emptiness[POST_ACTION](me, val);
  }
  return val;
}

void Traverse_void_Lalr_Lalr (Lalr_Lalr me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(Lalr, me)) return;
  if (action->action_Lalr[PRE_ACTION] != NULL) {
    action->action_Lalr[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Lalr)
  { 
  if (!action->skip_children_Lalr) {
    Traverse_void_List_Lalr_Production (Lalr_Lalr_grammar(me), action);
    Traverse_void_List_Lalr_LR_state (Lalr_Lalr_states(me), action);
  }
  }
  if (action->action_Lalr[POST_ACTION] != NULL) {
    action->action_Lalr[POST_ACTION](me);
  }
}

void Traverse_void_Lalr_Production (Lalr_Production me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(Production, me)) return;
  if (action->action_Production[PRE_ACTION] != NULL) {
    action->action_Production[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Production)
  { 
  if (!action->skip_children_Production) {
    Traverse_void_Lalr_LR_Symbols (Lalr_Production_rhs(me), action);
    Traverse_void_Lalr_Emptiness (Lalr_Production_empty(me), action);
  }
  }
  if (action->action_Production[POST_ACTION] != NULL) {
    action->action_Production[POST_ACTION](me);
  }
}

void Traverse_void_Lalr_LR_Symbol (Lalr_LR_Symbol me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(LR_Symbol, me)) return;
  if (action->action_LR_Symbol[PRE_ACTION] != NULL) {
    action->action_LR_Symbol[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_LR_Symbol)
  { 
  }
  if (action->action_LR_Symbol[POST_ACTION] != NULL) {
    action->action_LR_Symbol[POST_ACTION](me);
  }
}

void Traverse_void_Lalr_LR_Symbols (Lalr_LR_Symbols me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(LR_Symbols, me)) return;
  if (action->action_LR_Symbols[PRE_ACTION] != NULL) {
    action->action_LR_Symbols[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_LR_Symbols)
  { 
  if (!action->skip_children_LR_Symbols) {
    Traverse_void_Lalr_LR_Symbol (Lalr_LR_Symbols_data(me), action);
    Traverse_void_Lalr_LR_Symbols (Lalr_LR_Symbols_next(me), action);
  }
  }
  if (action->action_LR_Symbols[POST_ACTION] != NULL) {
    action->action_LR_Symbols[POST_ACTION](me);
  }
}

void Traverse_void_Lalr_LR_state (Lalr_LR_state me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(LR_state, me)) return;
  if (action->action_LR_state[PRE_ACTION] != NULL) {
    action->action_LR_state[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_LR_state)
  { 
  if (!action->skip_children_LR_state) {
    Traverse_void_List_Lalr_Item (Lalr_LR_state_items(me), action);
    Traverse_void_List_Lalr_Transition (Lalr_LR_state_transitions(me), action);
  }
  }
  if (action->action_LR_state[POST_ACTION] != NULL) {
    action->action_LR_state[POST_ACTION](me);
  }
}

void Traverse_void_Lalr_Item (Lalr_Item me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(Item, me)) return;
  if (action->action_Item[PRE_ACTION] != NULL) {
    action->action_Item[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Item)
  { 
  if (!action->skip_children_Item) {
    Traverse_void_List_Lalr_LR_Symbol (Lalr_Item_rhs1(me), action);
    Traverse_void_Lalr_LR_Symbols (Lalr_Item_rhs2(me), action);
  }
  }
  if (action->action_Item[POST_ACTION] != NULL) {
    action->action_Item[POST_ACTION](me);
  }
}

void Traverse_void_Lalr_Transition (Lalr_Transition me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(Transition, me)) return;
  if (action->action_Transition[PRE_ACTION] != NULL) {
    action->action_Transition[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Transition)
  { 
  if (!action->skip_children_Transition) {
    Traverse_void_Lalr_LR_Symbol (Lalr_Transition_symbol(me), action);
  }
  }
  if (action->action_Transition[POST_ACTION] != NULL) {
    action->action_Transition[POST_ACTION](me);
  }
}

void Traverse_void_Lalr_Scope (Lalr_Scope me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(Scope, me)) return;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    action->action_Scope[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Scope)
  { 
  if (!action->skip_children_Scope) {
    Traverse_void_Lalr_Scope (Lalr_Scope_next(me), action);
  }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    action->action_Scope[POST_ACTION](me);
  }
}

void Traverse_void_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(List_LR_Symbols, me)) return;
  if (action->action_List_LR_Symbols[PRE_ACTION] != NULL) {
    action->action_List_LR_Symbols[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_LR_Symbols)
  { 
  if (!action->skip_children_List_LR_Symbols) {
    Traverse_void_Lalr_LR_Symbols (List_Lalr_LR_Symbols_data(me), action);
    Traverse_void_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols_next(me), action);
  }
  }
  if (action->action_List_LR_Symbols[POST_ACTION] != NULL) {
    action->action_List_LR_Symbols[POST_ACTION](me);
  }
}

void Traverse_void_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(List_LR_Symbol, me)) return;
  if (action->action_List_LR_Symbol[PRE_ACTION] != NULL) {
    action->action_List_LR_Symbol[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_LR_Symbol)
  { 
  if (!action->skip_children_List_LR_Symbol) {
    Traverse_void_Lalr_LR_Symbol (List_Lalr_LR_Symbol_data(me), action);
    Traverse_void_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol_next(me), action);
  }
  }
  if (action->action_List_LR_Symbol[POST_ACTION] != NULL) {
    action->action_List_LR_Symbol[POST_ACTION](me);
  }
}

void Traverse_void_List_Lalr_Transition (List_Lalr_Transition me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(List_Transition, me)) return;
  if (action->action_List_Transition[PRE_ACTION] != NULL) {
    action->action_List_Transition[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Transition)
  { 
  if (!action->skip_children_List_Transition) {
    Traverse_void_Lalr_Transition (List_Lalr_Transition_data(me), action);
    Traverse_void_List_Lalr_Transition (List_Lalr_Transition_next(me), action);
  }
  }
  if (action->action_List_Transition[POST_ACTION] != NULL) {
    action->action_List_Transition[POST_ACTION](me);
  }
}

void Traverse_void_List_Lalr_Item (List_Lalr_Item me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(List_Item, me)) return;
  if (action->action_List_Item[PRE_ACTION] != NULL) {
    action->action_List_Item[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Item)
  { 
  if (!action->skip_children_List_Item) {
    Traverse_void_Lalr_Item (List_Lalr_Item_data(me), action);
    Traverse_void_List_Lalr_Item (List_Lalr_Item_next(me), action);
  }
  }
  if (action->action_List_Item[POST_ACTION] != NULL) {
    action->action_List_Item[POST_ACTION](me);
  }
}

void Traverse_void_List_Lalr_LR_state (List_Lalr_LR_state me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(List_LR_state, me)) return;
  if (action->action_List_LR_state[PRE_ACTION] != NULL) {
    action->action_List_LR_state[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_LR_state)
  { 
  if (!action->skip_children_List_LR_state) {
    Traverse_void_Lalr_LR_state (List_Lalr_LR_state_data(me), action);
    Traverse_void_List_Lalr_LR_state (List_Lalr_LR_state_next(me), action);
  }
  }
  if (action->action_List_LR_state[POST_ACTION] != NULL) {
    action->action_List_LR_state[POST_ACTION](me);
  }
}

void Traverse_void_List_Lalr_Production (List_Lalr_Production me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(List_Production, me)) return;
  if (action->action_List_Production[PRE_ACTION] != NULL) {
    action->action_List_Production[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Production)
  { 
  if (!action->skip_children_List_Production) {
    Traverse_void_Lalr_Production (List_Lalr_Production_data(me), action);
    Traverse_void_List_Lalr_Production (List_Lalr_Production_next(me), action);
  }
  }
  if (action->action_List_Production[POST_ACTION] != NULL) {
    action->action_List_Production[POST_ACTION](me);
  }
}

void Traverse_void_Lalr_Emptiness (Lalr_Emptiness me, void_Lalr_TraverseTable action)
{ 
  if (Lalr_SKIP_NODE(Emptiness, me)) return;
  if (action->action_Emptiness[PRE_ACTION] != NULL) {
    action->action_Emptiness[PRE_ACTION](me);
  }
  {   }
  if (action->action_Emptiness[POST_ACTION] != NULL) {
    action->action_Emptiness[POST_ACTION](me);
  }
}

Lalr_Lalr Traverse_copy_Lalr_Lalr (Lalr_Lalr me, copy_Lalr_TraverseTable action)
{ Lalr_Lalr _new = me, _old = me;
  if (action->action_Lalr[PRE_ACTION] != NULL) {
    _new = action->action_Lalr[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Lalr_Lalr)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Lalr) {
    Lalr_Lalr_grammar(me) = Traverse_copy_List_Lalr_Production (Lalr_Lalr_grammar(me), action);
    Lalr_Lalr_states(me) = Traverse_copy_List_Lalr_LR_state (Lalr_Lalr_states(me), action);
  }
  }
  if (action->action_Lalr[POST_ACTION] != NULL) {
    me = action->action_Lalr[POST_ACTION](me, _old);
  }
  return me;
}

Lalr_Production Traverse_copy_Lalr_Production (Lalr_Production me, copy_Lalr_TraverseTable action)
{ Lalr_Production _new = me, _old = me;
  if (action->action_Production[PRE_ACTION] != NULL) {
    _new = action->action_Production[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Lalr_Production)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Production) {
    Lalr_Production_rhs(me) = Traverse_copy_Lalr_LR_Symbols (Lalr_Production_rhs(me), action);
    Lalr_Production_empty(me) = Traverse_copy_Lalr_Emptiness (Lalr_Production_empty(me), action);
    Lalr_Production_first(me) = Traverse_copy_List_Ident (Lalr_Production_first(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Lalr_Production_scope(me) = NULL;
      Lalr_Production_old_scope(me) = NULL;
      Lalr_Production_prod_rule(me) = NULL;
      Lalr_Production_num(me) = 0;
    }
  }
  if (action->action_Production[POST_ACTION] != NULL) {
    me = action->action_Production[POST_ACTION](me, _old);
  }
  return me;
}

Lalr_LR_Symbol Traverse_copy_Lalr_LR_Symbol (Lalr_LR_Symbol me, copy_Lalr_TraverseTable action)
{ Lalr_LR_Symbol _new = me, _old = me;
  if (action->action_LR_Symbol[PRE_ACTION] != NULL) {
    _new = action->action_LR_Symbol[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Lalr_LR_Symbol)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Lalr_LR_Symbol_scope(me) = NULL;
      Lalr_LR_Symbol_old_scope(me) = NULL;
      Lalr_LR_Symbol_prods_bind(me) = NULL;
      Lalr_LR_Symbol_prods(me) = NULL;
      Lalr_LR_Symbol_fields(me) = NULL;
      Lalr_LR_Symbol_first(me) = NULL;
      Lalr_LR_Symbol_empty(me) = TRUE;
      Lalr_LR_Symbol_first_eval(me) = UnEval;
      Lalr_LR_Symbol_empty_eval(me) = UnEval;
      Lalr_LR_Symbol_start(me) = FALSE;
      Lalr_LR_Symbol_hole(me) = NULL;
      Lalr_LR_Symbol_start_state(me) = NULL;
      Lalr_LR_Symbol_num(me) = 0;
      Lalr_LR_Symbol_hole_num(me) = 0;
    }
  }
  if (action->action_LR_Symbol[POST_ACTION] != NULL) {
    me = action->action_LR_Symbol[POST_ACTION](me, _old);
  }
  return me;
}

Lalr_LR_Symbols Traverse_copy_Lalr_LR_Symbols (Lalr_LR_Symbols me, copy_Lalr_TraverseTable action)
{ Lalr_LR_Symbols _new = me, _old = me;
  if (action->action_LR_Symbols[PRE_ACTION] != NULL) {
    _new = action->action_LR_Symbols[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Lalr_LR_Symbols)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_LR_Symbols) {
    Lalr_LR_Symbols_data(me) = Traverse_copy_Lalr_LR_Symbol (Lalr_LR_Symbols_data(me), action);
    Lalr_LR_Symbols_next(me) = Traverse_copy_Lalr_LR_Symbols (Lalr_LR_Symbols_next(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Lalr_LR_Symbols_num(me) = New_rhs_num ();
    }
  }
  if (action->action_LR_Symbols[POST_ACTION] != NULL) {
    me = action->action_LR_Symbols[POST_ACTION](me, _old);
  }
  return me;
}

Lalr_LR_state Traverse_copy_Lalr_LR_state (Lalr_LR_state me, copy_Lalr_TraverseTable action)
{ Lalr_LR_state _new = me, _old = me;
  if (action->action_LR_state[PRE_ACTION] != NULL) {
    _new = action->action_LR_state[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Lalr_LR_state)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_LR_state) {
    Lalr_LR_state_items(me) = Traverse_copy_List_Lalr_Item (Lalr_LR_state_items(me), action);
    Lalr_LR_state_transitions(me) = Traverse_copy_List_Lalr_Transition (Lalr_LR_state_transitions(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Lalr_LR_state_start_state(me) = NULL;
    }
  }
  if (action->action_LR_state[POST_ACTION] != NULL) {
    me = action->action_LR_state[POST_ACTION](me, _old);
  }
  return me;
}

Lalr_Item Traverse_copy_Lalr_Item (Lalr_Item me, copy_Lalr_TraverseTable action)
{ Lalr_Item _new = me, _old = me;
  if (action->action_Item[PRE_ACTION] != NULL) {
    _new = action->action_Item[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Lalr_Item)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Item) {
    Lalr_Item_rhs1(me) = Traverse_copy_List_Lalr_LR_Symbol (Lalr_Item_rhs1(me), action);
    Lalr_Item_rhs2(me) = Traverse_copy_Lalr_LR_Symbols (Lalr_Item_rhs2(me), action);
    Lalr_Item_followers(me) = Traverse_copy_List_Ident (Lalr_Item_followers(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Lalr_Item_production(me) = NULL;
      Lalr_Item_predecessors(me) = NULL;
      Lalr_Item_start_item(me) = FALSE;
      Lalr_Item_conflict(me) = FALSE;
    }
  }
  if (action->action_Item[POST_ACTION] != NULL) {
    me = action->action_Item[POST_ACTION](me, _old);
  }
  return me;
}

Lalr_Transition Traverse_copy_Lalr_Transition (Lalr_Transition me, copy_Lalr_TraverseTable action)
{ Lalr_Transition _new = me, _old = me;
  if (action->action_Transition[PRE_ACTION] != NULL) {
    _new = action->action_Transition[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Lalr_Transition)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Transition) {
    Lalr_Transition_symbol(me) = Traverse_copy_Lalr_LR_Symbol (Lalr_Transition_symbol(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Lalr_Transition_target(me) = NULL;
      Lalr_Transition_conflict(me) = FALSE;
    }
  }
  if (action->action_Transition[POST_ACTION] != NULL) {
    me = action->action_Transition[POST_ACTION](me, _old);
  }
  return me;
}

Lalr_Scope Traverse_copy_Lalr_Scope (Lalr_Scope me, copy_Lalr_TraverseTable action)
{ Lalr_Scope _new = me, _old = me;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    _new = action->action_Scope[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Lalr_Scope)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Scope) {
    Lalr_Scope_next(me) = Traverse_copy_Lalr_Scope (Lalr_Scope_next(me), action);
  }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    me = action->action_Scope[POST_ACTION](me, _old);
  }
  return me;
}

List_Lalr_LR_Symbols Traverse_copy_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols me, copy_Lalr_TraverseTable action)
{ List_Lalr_LR_Symbols _new = me, _old = me;
  if (action->action_List_LR_Symbols[PRE_ACTION] != NULL) {
    _new = action->action_List_LR_Symbols[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Lalr_LR_Symbols)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_LR_Symbols) {
    List_Lalr_LR_Symbols_data(me) = Traverse_copy_Lalr_LR_Symbols (List_Lalr_LR_Symbols_data(me), action);
    List_Lalr_LR_Symbols_next(me) = Traverse_copy_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols_next(me), action);
  }
  }
  if (action->action_List_LR_Symbols[POST_ACTION] != NULL) {
    me = action->action_List_LR_Symbols[POST_ACTION](me, _old);
  }
  return me;
}

List_Lalr_LR_Symbol Traverse_copy_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol me, copy_Lalr_TraverseTable action)
{ List_Lalr_LR_Symbol _new = me, _old = me;
  if (action->action_List_LR_Symbol[PRE_ACTION] != NULL) {
    _new = action->action_List_LR_Symbol[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Lalr_LR_Symbol)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_LR_Symbol) {
    List_Lalr_LR_Symbol_data(me) = Traverse_copy_Lalr_LR_Symbol (List_Lalr_LR_Symbol_data(me), action);
    List_Lalr_LR_Symbol_next(me) = Traverse_copy_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol_next(me), action);
  }
  }
  if (action->action_List_LR_Symbol[POST_ACTION] != NULL) {
    me = action->action_List_LR_Symbol[POST_ACTION](me, _old);
  }
  return me;
}

List_Lalr_Transition Traverse_copy_List_Lalr_Transition (List_Lalr_Transition me, copy_Lalr_TraverseTable action)
{ List_Lalr_Transition _new = me, _old = me;
  if (action->action_List_Transition[PRE_ACTION] != NULL) {
    _new = action->action_List_Transition[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Lalr_Transition)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Transition) {
    List_Lalr_Transition_data(me) = Traverse_copy_Lalr_Transition (List_Lalr_Transition_data(me), action);
    List_Lalr_Transition_next(me) = Traverse_copy_List_Lalr_Transition (List_Lalr_Transition_next(me), action);
  }
  }
  if (action->action_List_Transition[POST_ACTION] != NULL) {
    me = action->action_List_Transition[POST_ACTION](me, _old);
  }
  return me;
}

List_Lalr_Item Traverse_copy_List_Lalr_Item (List_Lalr_Item me, copy_Lalr_TraverseTable action)
{ List_Lalr_Item _new = me, _old = me;
  if (action->action_List_Item[PRE_ACTION] != NULL) {
    _new = action->action_List_Item[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Lalr_Item)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Item) {
    List_Lalr_Item_data(me) = Traverse_copy_Lalr_Item (List_Lalr_Item_data(me), action);
    List_Lalr_Item_next(me) = Traverse_copy_List_Lalr_Item (List_Lalr_Item_next(me), action);
  }
  }
  if (action->action_List_Item[POST_ACTION] != NULL) {
    me = action->action_List_Item[POST_ACTION](me, _old);
  }
  return me;
}

List_Lalr_LR_state Traverse_copy_List_Lalr_LR_state (List_Lalr_LR_state me, copy_Lalr_TraverseTable action)
{ List_Lalr_LR_state _new = me, _old = me;
  if (action->action_List_LR_state[PRE_ACTION] != NULL) {
    _new = action->action_List_LR_state[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Lalr_LR_state)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_LR_state) {
    List_Lalr_LR_state_data(me) = Traverse_copy_Lalr_LR_state (List_Lalr_LR_state_data(me), action);
    List_Lalr_LR_state_next(me) = Traverse_copy_List_Lalr_LR_state (List_Lalr_LR_state_next(me), action);
  }
  }
  if (action->action_List_LR_state[POST_ACTION] != NULL) {
    me = action->action_List_LR_state[POST_ACTION](me, _old);
  }
  return me;
}

List_Lalr_Production Traverse_copy_List_Lalr_Production (List_Lalr_Production me, copy_Lalr_TraverseTable action)
{ List_Lalr_Production _new = me, _old = me;
  if (action->action_List_Production[PRE_ACTION] != NULL) {
    _new = action->action_List_Production[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Lalr_Production)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Production) {
    List_Lalr_Production_data(me) = Traverse_copy_Lalr_Production (List_Lalr_Production_data(me), action);
    List_Lalr_Production_next(me) = Traverse_copy_List_Lalr_Production (List_Lalr_Production_next(me), action);
  }
  }
  if (action->action_List_Production[POST_ACTION] != NULL) {
    me = action->action_List_Production[POST_ACTION](me, _old);
  }
  return me;
}

Lalr_Emptiness Traverse_copy_Lalr_Emptiness (Lalr_Emptiness me, copy_Lalr_TraverseTable action)
{ Lalr_Emptiness _new = me, _old = me;
  if (action->action_Emptiness[PRE_ACTION] != NULL) {
    return action->action_Emptiness[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_Emptiness[POST_ACTION] != NULL) {
    me = action->action_Emptiness[POST_ACTION](me, _old);
  }
  return me;
}

int Traverse_compare_Lalr_Lalr (Lalr_Lalr x, Lalr_Lalr y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_Lalr[PRE_ACTION] != NULL) {
    return action->action_Lalr[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Lalr) {
    if ((comp = Traverse_compare_List_Lalr_Production (Lalr_Lalr_grammar(x),Lalr_Lalr_grammar(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Lalr_LR_state (Lalr_Lalr_states(x),Lalr_Lalr_states(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Lalr_Production (Lalr_Production x, Lalr_Production y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_Production[PRE_ACTION] != NULL) {
    return action->action_Production[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Production) {
    if ((comp = Traverse_compare_Ident (Lalr_Production_lhs(x),Lalr_Production_lhs(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Lalr_LR_Symbols (Lalr_Production_rhs(x),Lalr_Production_rhs(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Lalr_Emptiness (Lalr_Production_empty(x),Lalr_Production_empty(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Ident (Lalr_Production_first(x),Lalr_Production_first(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Lalr_LR_Symbol (Lalr_LR_Symbol x, Lalr_LR_Symbol y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_LR_Symbol[PRE_ACTION] != NULL) {
    return action->action_LR_Symbol[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_LR_Symbol) {
    if ((comp = Traverse_compare_Ident (Lalr_LR_Symbol_id(x),Lalr_LR_Symbol_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Bool (Lalr_LR_Symbol_make_empty(x),Lalr_LR_Symbol_make_empty(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Lalr_LR_Symbols (Lalr_LR_Symbols x, Lalr_LR_Symbols y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_LR_Symbols[PRE_ACTION] != NULL) {
    return action->action_LR_Symbols[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_LR_Symbols) {
    if ((comp = Traverse_compare_Lalr_LR_Symbol (Lalr_LR_Symbols_data(x),Lalr_LR_Symbols_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Lalr_LR_Symbols (Lalr_LR_Symbols_next(x),Lalr_LR_Symbols_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Lalr_LR_state (Lalr_LR_state x, Lalr_LR_state y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_LR_state[PRE_ACTION] != NULL) {
    return action->action_LR_state[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_LR_state) {
    if ((comp = Traverse_compare_Int (Lalr_LR_state_num(x),Lalr_LR_state_num(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Lalr_Item (Lalr_LR_state_items(x),Lalr_LR_state_items(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Lalr_Transition (Lalr_LR_state_transitions(x),Lalr_LR_state_transitions(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Lalr_Item (Lalr_Item x, Lalr_Item y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_Item[PRE_ACTION] != NULL) {
    return action->action_Item[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Item) {
    if ((comp = Traverse_compare_Ident (Lalr_Item_lhs(x),Lalr_Item_lhs(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Lalr_LR_Symbol (Lalr_Item_rhs1(x),Lalr_Item_rhs1(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Lalr_LR_Symbols (Lalr_Item_rhs2(x),Lalr_Item_rhs2(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Ident (Lalr_Item_followers(x),Lalr_Item_followers(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Lalr_Transition (Lalr_Transition x, Lalr_Transition y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_Transition[PRE_ACTION] != NULL) {
    return action->action_Transition[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Transition) {
    if ((comp = Traverse_compare_Lalr_LR_Symbol (Lalr_Transition_symbol(x),Lalr_Transition_symbol(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Int (Lalr_Transition_num(x),Lalr_Transition_num(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Lalr_Scope (Lalr_Scope x, Lalr_Scope y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    return action->action_Scope[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Scope) {
    if ((comp = Traverse_compare_Lalr_Scope (Lalr_Scope_next(x),Lalr_Scope_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols x, List_Lalr_LR_Symbols y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_List_LR_Symbols[PRE_ACTION] != NULL) {
    return action->action_List_LR_Symbols[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_LR_Symbols) {
    if ((comp = Traverse_compare_Lalr_LR_Symbols (List_Lalr_LR_Symbols_data(x),List_Lalr_LR_Symbols_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols_next(x),List_Lalr_LR_Symbols_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol x, List_Lalr_LR_Symbol y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_List_LR_Symbol[PRE_ACTION] != NULL) {
    return action->action_List_LR_Symbol[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_LR_Symbol) {
    if ((comp = Traverse_compare_Lalr_LR_Symbol (List_Lalr_LR_Symbol_data(x),List_Lalr_LR_Symbol_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol_next(x),List_Lalr_LR_Symbol_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Lalr_Transition (List_Lalr_Transition x, List_Lalr_Transition y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Transition[PRE_ACTION] != NULL) {
    return action->action_List_Transition[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Transition) {
    if ((comp = Traverse_compare_Lalr_Transition (List_Lalr_Transition_data(x),List_Lalr_Transition_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Lalr_Transition (List_Lalr_Transition_next(x),List_Lalr_Transition_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Lalr_Item (List_Lalr_Item x, List_Lalr_Item y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Item[PRE_ACTION] != NULL) {
    return action->action_List_Item[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Item) {
    if ((comp = Traverse_compare_Lalr_Item (List_Lalr_Item_data(x),List_Lalr_Item_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Lalr_Item (List_Lalr_Item_next(x),List_Lalr_Item_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Lalr_LR_state (List_Lalr_LR_state x, List_Lalr_LR_state y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_List_LR_state[PRE_ACTION] != NULL) {
    return action->action_List_LR_state[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_LR_state) {
    if ((comp = Traverse_compare_Lalr_LR_state (List_Lalr_LR_state_data(x),List_Lalr_LR_state_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Lalr_LR_state (List_Lalr_LR_state_next(x),List_Lalr_LR_state_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Lalr_Production (List_Lalr_Production x, List_Lalr_Production y, compare_Lalr_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Production[PRE_ACTION] != NULL) {
    return action->action_List_Production[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Production) {
    if ((comp = Traverse_compare_Lalr_Production (List_Lalr_Production_data(x),List_Lalr_Production_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Lalr_Production (List_Lalr_Production_next(x),List_Lalr_Production_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Lalr_Emptiness (Lalr_Emptiness x, Lalr_Emptiness y, compare_Lalr_TraverseTable action)
{ if (action->action_Emptiness[PRE_ACTION] != NULL) {
    return action->action_Emptiness[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

static void* PushScope_Lalr_Production (Lalr_Production me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (Lalr_Scope) val;
  Lalr_Production_scope(me) = (Lalr_Scope) val;
  return val;
}

static void* PushScope_Lalr_LR_Symbol (Lalr_LR_Symbol me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (Lalr_Scope) val;
  Lalr_LR_Symbol_scope(me) = (Lalr_Scope) val;
  return val;
}

struct s_Lalr_TraverseTable Lalr_scope_actions = {

  Traverse_Accumulate,
  { NULL,	NULL }, FALSE,	/* Lalr_Lalr */
  { NULL,	PushScope_Lalr_Production }, FALSE,	/* Lalr_Production */
  { NULL,	PushScope_Lalr_LR_Symbol }, FALSE,	/* Lalr_LR_Symbol */
  { NULL,	NULL }, FALSE,	/* Lalr_LR_Symbols */
  { NULL,	NULL }, FALSE,	/* Lalr_LR_state */
  { NULL,	NULL }, FALSE,	/* Lalr_Item */
  { NULL,	NULL }, FALSE,	/* Lalr_Transition */
  { NULL,	NULL }, FALSE,	/* Lalr_Scope */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_Symbols */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_Symbol */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Transition */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Item */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_state */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Production */
  { NULL,	 NULL }, FALSE,	/* Lalr_Emptiness */
};

static void Defining_Lalr_Lalr (Lalr_Lalr me)
{
  if (me==NULL) return;
}

static void Defining_Lalr_Production (Lalr_Production me)
{
  Scope scope;
  if (me==NULL) return;
  scope = Lalr_Production_scope(me);
  Lalr_Production__num(me) = Scope_Num_Stores (scope);
  Lalr_Production_lhs_bind(me) = ReplaceBind (Lalr_Production_lhs_bind(me), Lalr_Production_lhs(me), scope, Bind_Lalr_Production_kind, me, Lalr_DefaultNameSpace, TRUE, FALSE, FALSE);
}

static void Defining_Lalr_LR_Symbol (Lalr_LR_Symbol me)
{
  Scope scope;
  if (me==NULL) return;
  scope = Lalr_LR_Symbol_scope(me);
  Lalr_LR_Symbol__num(me) = Scope_Num_Stores (scope);
}

static void Defining_Lalr_LR_Symbols (Lalr_LR_Symbols me)
{
  if (me==NULL) return;
}

static void Defining_Lalr_LR_state (Lalr_LR_state me)
{
  if (me==NULL) return;
}

static void Defining_Lalr_Item (Lalr_Item me)
{
  if (me==NULL) return;
}

static void Defining_Lalr_Transition (Lalr_Transition me)
{
  if (me==NULL) return;
}

struct s_void_Lalr_TraverseTable Lalr_defining_actions = {

  { NULL,	(void*)Defining_Lalr_Lalr }, FALSE,	/* Lalr_Lalr */
  { NULL,	(void*)Defining_Lalr_Production }, FALSE,	/* Lalr_Production */
  { NULL,	(void*)Defining_Lalr_LR_Symbol }, FALSE,	/* Lalr_LR_Symbol */
  { NULL,	(void*)Defining_Lalr_LR_Symbols }, FALSE,	/* Lalr_LR_Symbols */
  { NULL,	(void*)Defining_Lalr_LR_state }, FALSE,	/* Lalr_LR_state */
  { NULL,	(void*)Defining_Lalr_Item }, FALSE,	/* Lalr_Item */
  { NULL,	(void*)Defining_Lalr_Transition }, FALSE,	/* Lalr_Transition */
  { NULL,	NULL }, FALSE,	/* Lalr_Scope */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_Symbols */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_Symbol */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Transition */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Item */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_state */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Production */
  { NULL,	 NULL }, FALSE,	/* Lalr_Emptiness */
};

static void Retrieve_Lalr_LR_Symbol (Lalr_LR_Symbol me)
{ if (me==NULL) return;
  if (Lalr_LR_Symbol_id(me) != NULL) {
    { List_Bind l;
      Lalr_LR_Symbol_prods_bind(me) = RetrieveListBind (Lalr_LR_Symbol_id(me), Lalr_LR_Symbol_scope(me), Lalr_LR_Symbol__num(me), Lalr_DefaultNameSpace, Bind_Lalr_Production_kind);
      Lalr_LR_Symbol_prods(me) = NULL;
      for (l = Lalr_LR_Symbol_prods_bind(me); l != NULL; l = List_Bind_next(l)) {
        FRONT_APPEND_NODE (Lalr_LR_Symbol_prods(me), Bind_object(List_Bind_data(l)));
      }
    }
  }
}

struct s_void_Lalr_TraverseTable Lalr_applied_actions = {

  { NULL,	NULL }, FALSE,	/* Lalr_Lalr */
  { NULL,	NULL }, FALSE,	/* Lalr_Production */
  { NULL,	Retrieve_Lalr_LR_Symbol }, FALSE,	/* Lalr_LR_Symbol */
  { NULL,	NULL }, FALSE,	/* Lalr_LR_Symbols */
  { NULL,	NULL }, FALSE,	/* Lalr_LR_state */
  { NULL,	NULL }, FALSE,	/* Lalr_Item */
  { NULL,	NULL }, FALSE,	/* Lalr_Transition */
  { NULL,	NULL }, FALSE,	/* Lalr_Scope */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_Symbols */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_Symbol */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Transition */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Item */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_state */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Production */
  { NULL,	 NULL }, FALSE,	/* Lalr_Emptiness */
};

static void Check_Lalr_Production (Lalr_Production me)
{ if (me==NULL) return;
  if (Bind_double (Lalr_Production_lhs_bind(me))) {
    InputError (Lalr_Production_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(Lalr_Production_lhs(me)));
  }
}

static void Check_Lalr_LR_Symbol (Lalr_LR_Symbol me)
{ if (me==NULL) return;
}

struct s_void_Lalr_TraverseTable Lalr_check_actions = {

  { NULL,	NULL }, FALSE,	/* Lalr_Lalr */
  { NULL,	Check_Lalr_Production }, FALSE,	/* Lalr_Production */
  { NULL,	Check_Lalr_LR_Symbol }, FALSE,	/* Lalr_LR_Symbol */
  { NULL,	NULL }, FALSE,	/* Lalr_LR_Symbols */
  { NULL,	NULL }, FALSE,	/* Lalr_LR_state */
  { NULL,	NULL }, FALSE,	/* Lalr_Item */
  { NULL,	NULL }, FALSE,	/* Lalr_Transition */
  { NULL,	NULL }, FALSE,	/* Lalr_Scope */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_Symbols */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_Symbol */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Transition */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Item */
  { NULL,	NULL }, FALSE,	/* List_Lalr_LR_state */
  { NULL,	NULL }, FALSE,	/* List_Lalr_Production */
  { NULL,	 NULL }, FALSE,	/* Lalr_Emptiness */
};

struct s_void_Lalr_TraverseTable Lalr_print_actions;

struct s_copy_Lalr_TraverseTable Lalr_copy_actions;

struct s_compare_Lalr_TraverseTable Lalr_compare_actions;

void Lalr_fill_table (Lalr_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Lalr[PRE_ACTION] = (void* (*) (Lalr_Lalr, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Lalr[POST_ACTION] = (void* (*) (Lalr_Lalr, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Production[PRE_ACTION] = (void* (*) (Lalr_Production, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Production[POST_ACTION] = (void* (*) (Lalr_Production, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_Symbol[PRE_ACTION] = (void* (*) (Lalr_LR_Symbol, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_Symbol[POST_ACTION] = (void* (*) (Lalr_LR_Symbol, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_Symbols[PRE_ACTION] = (void* (*) (Lalr_LR_Symbols, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_Symbols[POST_ACTION] = (void* (*) (Lalr_LR_Symbols, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_state[PRE_ACTION] = (void* (*) (Lalr_LR_state, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_state[POST_ACTION] = (void* (*) (Lalr_LR_state, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Item[PRE_ACTION] = (void* (*) (Lalr_Item, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Item[POST_ACTION] = (void* (*) (Lalr_Item, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Transition[PRE_ACTION] = (void* (*) (Lalr_Transition, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Transition[POST_ACTION] = (void* (*) (Lalr_Transition, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void* (*) (Lalr_Scope, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void* (*) (Lalr_Scope, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_Symbols[PRE_ACTION] = (void* (*) (List_Lalr_LR_Symbols, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_Symbols[POST_ACTION] = (void* (*) (List_Lalr_LR_Symbols, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_Symbol[PRE_ACTION] = (void* (*) (List_Lalr_LR_Symbol, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_Symbol[POST_ACTION] = (void* (*) (List_Lalr_LR_Symbol, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Transition[PRE_ACTION] = (void* (*) (List_Lalr_Transition, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Transition[POST_ACTION] = (void* (*) (List_Lalr_Transition, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Item[PRE_ACTION] = (void* (*) (List_Lalr_Item, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Item[POST_ACTION] = (void* (*) (List_Lalr_Item, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_state[PRE_ACTION] = (void* (*) (List_Lalr_LR_state, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_state[POST_ACTION] = (void* (*) (List_Lalr_LR_state, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Production[PRE_ACTION] = (void* (*) (List_Lalr_Production, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Production[POST_ACTION] = (void* (*) (List_Lalr_Production, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Emptiness[PRE_ACTION] = (void* (*) (Lalr_Emptiness, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Emptiness[POST_ACTION] = (void* (*) (Lalr_Emptiness, void*))x;
}

void void_Lalr_fill_table (void_Lalr_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Lalr[PRE_ACTION] = (void (*) (Lalr_Lalr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Lalr[POST_ACTION] = (void (*) (Lalr_Lalr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Production[PRE_ACTION] = (void (*) (Lalr_Production))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Production[POST_ACTION] = (void (*) (Lalr_Production))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_Symbol[PRE_ACTION] = (void (*) (Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_Symbol[POST_ACTION] = (void (*) (Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_Symbols[PRE_ACTION] = (void (*) (Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_Symbols[POST_ACTION] = (void (*) (Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_state[PRE_ACTION] = (void (*) (Lalr_LR_state))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_state[POST_ACTION] = (void (*) (Lalr_LR_state))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Item[PRE_ACTION] = (void (*) (Lalr_Item))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Item[POST_ACTION] = (void (*) (Lalr_Item))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Transition[PRE_ACTION] = (void (*) (Lalr_Transition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Transition[POST_ACTION] = (void (*) (Lalr_Transition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void (*) (Lalr_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void (*) (Lalr_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_Symbols[PRE_ACTION] = (void (*) (List_Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_Symbols[POST_ACTION] = (void (*) (List_Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_Symbol[PRE_ACTION] = (void (*) (List_Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_Symbol[POST_ACTION] = (void (*) (List_Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Transition[PRE_ACTION] = (void (*) (List_Lalr_Transition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Transition[POST_ACTION] = (void (*) (List_Lalr_Transition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Item[PRE_ACTION] = (void (*) (List_Lalr_Item))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Item[POST_ACTION] = (void (*) (List_Lalr_Item))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_state[PRE_ACTION] = (void (*) (List_Lalr_LR_state))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_state[POST_ACTION] = (void (*) (List_Lalr_LR_state))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Production[PRE_ACTION] = (void (*) (List_Lalr_Production))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Production[POST_ACTION] = (void (*) (List_Lalr_Production))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Emptiness[PRE_ACTION] = (void (*) (Lalr_Emptiness))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Emptiness[POST_ACTION] = (void (*) (Lalr_Emptiness))x;
}

void copy_Lalr_fill_table (copy_Lalr_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Lalr[PRE_ACTION] = (Lalr_Lalr (*) (Lalr_Lalr, Lalr_Lalr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Lalr[POST_ACTION] = (Lalr_Lalr (*) (Lalr_Lalr, Lalr_Lalr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Production[PRE_ACTION] = (Lalr_Production (*) (Lalr_Production, Lalr_Production))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Production[POST_ACTION] = (Lalr_Production (*) (Lalr_Production, Lalr_Production))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_Symbol[PRE_ACTION] = (Lalr_LR_Symbol (*) (Lalr_LR_Symbol, Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_Symbol[POST_ACTION] = (Lalr_LR_Symbol (*) (Lalr_LR_Symbol, Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_Symbols[PRE_ACTION] = (Lalr_LR_Symbols (*) (Lalr_LR_Symbols, Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_Symbols[POST_ACTION] = (Lalr_LR_Symbols (*) (Lalr_LR_Symbols, Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_state[PRE_ACTION] = (Lalr_LR_state (*) (Lalr_LR_state, Lalr_LR_state))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_state[POST_ACTION] = (Lalr_LR_state (*) (Lalr_LR_state, Lalr_LR_state))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Item[PRE_ACTION] = (Lalr_Item (*) (Lalr_Item, Lalr_Item))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Item[POST_ACTION] = (Lalr_Item (*) (Lalr_Item, Lalr_Item))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Transition[PRE_ACTION] = (Lalr_Transition (*) (Lalr_Transition, Lalr_Transition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Transition[POST_ACTION] = (Lalr_Transition (*) (Lalr_Transition, Lalr_Transition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (Lalr_Scope (*) (Lalr_Scope, Lalr_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (Lalr_Scope (*) (Lalr_Scope, Lalr_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_Symbols[PRE_ACTION] = (List_Lalr_LR_Symbols (*) (List_Lalr_LR_Symbols, List_Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_Symbols[POST_ACTION] = (List_Lalr_LR_Symbols (*) (List_Lalr_LR_Symbols, List_Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_Symbol[PRE_ACTION] = (List_Lalr_LR_Symbol (*) (List_Lalr_LR_Symbol, List_Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_Symbol[POST_ACTION] = (List_Lalr_LR_Symbol (*) (List_Lalr_LR_Symbol, List_Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Transition[PRE_ACTION] = (List_Lalr_Transition (*) (List_Lalr_Transition, List_Lalr_Transition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Transition[POST_ACTION] = (List_Lalr_Transition (*) (List_Lalr_Transition, List_Lalr_Transition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Item[PRE_ACTION] = (List_Lalr_Item (*) (List_Lalr_Item, List_Lalr_Item))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Item[POST_ACTION] = (List_Lalr_Item (*) (List_Lalr_Item, List_Lalr_Item))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_state[PRE_ACTION] = (List_Lalr_LR_state (*) (List_Lalr_LR_state, List_Lalr_LR_state))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_state[POST_ACTION] = (List_Lalr_LR_state (*) (List_Lalr_LR_state, List_Lalr_LR_state))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Production[PRE_ACTION] = (List_Lalr_Production (*) (List_Lalr_Production, List_Lalr_Production))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Production[POST_ACTION] = (List_Lalr_Production (*) (List_Lalr_Production, List_Lalr_Production))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Emptiness[PRE_ACTION] = (Lalr_Emptiness (*) (Lalr_Emptiness, Lalr_Emptiness))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Emptiness[POST_ACTION] = (Lalr_Emptiness (*) (Lalr_Emptiness, Lalr_Emptiness))x;
}

void compare_Lalr_fill_table (compare_Lalr_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Lalr[PRE_ACTION] = (int (*) (Lalr_Lalr, Lalr_Lalr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Lalr[POST_ACTION] = (int (*) (Lalr_Lalr, Lalr_Lalr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Production[PRE_ACTION] = (int (*) (Lalr_Production, Lalr_Production))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Production[POST_ACTION] = (int (*) (Lalr_Production, Lalr_Production))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_Symbol[PRE_ACTION] = (int (*) (Lalr_LR_Symbol, Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_Symbol[POST_ACTION] = (int (*) (Lalr_LR_Symbol, Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_Symbols[PRE_ACTION] = (int (*) (Lalr_LR_Symbols, Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_Symbols[POST_ACTION] = (int (*) (Lalr_LR_Symbols, Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LR_state[PRE_ACTION] = (int (*) (Lalr_LR_state, Lalr_LR_state))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LR_state[POST_ACTION] = (int (*) (Lalr_LR_state, Lalr_LR_state))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Item[PRE_ACTION] = (int (*) (Lalr_Item, Lalr_Item))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Item[POST_ACTION] = (int (*) (Lalr_Item, Lalr_Item))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Transition[PRE_ACTION] = (int (*) (Lalr_Transition, Lalr_Transition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Transition[POST_ACTION] = (int (*) (Lalr_Transition, Lalr_Transition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (int (*) (Lalr_Scope, Lalr_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (int (*) (Lalr_Scope, Lalr_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_Symbols[PRE_ACTION] = (int (*) (List_Lalr_LR_Symbols, List_Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_Symbols[POST_ACTION] = (int (*) (List_Lalr_LR_Symbols, List_Lalr_LR_Symbols))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_Symbol[PRE_ACTION] = (int (*) (List_Lalr_LR_Symbol, List_Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_Symbol[POST_ACTION] = (int (*) (List_Lalr_LR_Symbol, List_Lalr_LR_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Transition[PRE_ACTION] = (int (*) (List_Lalr_Transition, List_Lalr_Transition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Transition[POST_ACTION] = (int (*) (List_Lalr_Transition, List_Lalr_Transition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Item[PRE_ACTION] = (int (*) (List_Lalr_Item, List_Lalr_Item))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Item[POST_ACTION] = (int (*) (List_Lalr_Item, List_Lalr_Item))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_LR_state[PRE_ACTION] = (int (*) (List_Lalr_LR_state, List_Lalr_LR_state))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_LR_state[POST_ACTION] = (int (*) (List_Lalr_LR_state, List_Lalr_LR_state))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Production[PRE_ACTION] = (int (*) (List_Lalr_Production, List_Lalr_Production))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Production[POST_ACTION] = (int (*) (List_Lalr_Production, List_Lalr_Production))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Emptiness[PRE_ACTION] = (int (*) (Lalr_Emptiness, Lalr_Emptiness))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Emptiness[POST_ACTION] = (int (*) (Lalr_Emptiness, Lalr_Emptiness))x;
}

Lalr_NameSpaces Lalr_namespaces[] = { -1 };

void Decorate_Lalr (Lalr_Lalr r)
{
  if (Lalr_namespaces[0]<0) Extend_namespaces (Lalr_NUM_NAMESPACES, Lalr_namespaces);
  Lalr_root = r;
  if (NoDecorate) return;
  Traverse_Lalr_Lalr (r, &Lalr_scope_actions, NULL);
  Traverse_void_Lalr_Lalr (r, &Lalr_defining_actions);
  Traverse_void_Lalr_Lalr (r, &Lalr_applied_actions);
  Traverse_void_Lalr_Lalr (r, &Lalr_check_actions);
}
