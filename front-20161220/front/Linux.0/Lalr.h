#ifndef _Lalr
#define _Lalr

#include <stdarg.h>
#include <stddef.h>
#include <front/basic_types.h>

typedef Bool Lalr_Emptiness;

#ifndef DEF_TYPE_Lalr_Lalr
#define DEF_TYPE_Lalr_Lalr
typedef struct s_Lalr_Lalr      *Lalr_Lalr;
#endif

#ifndef DEF_TYPE_Lalr_Production
#define DEF_TYPE_Lalr_Production
typedef struct s_Lalr_Production        *Lalr_Production;
#endif

#ifndef DEF_TYPE_Lalr_LR_Symbol
#define DEF_TYPE_Lalr_LR_Symbol
typedef struct s_Lalr_LR_Symbol *Lalr_LR_Symbol;
#endif

#ifndef DEF_TYPE_Lalr_LR_Symbols
#define DEF_TYPE_Lalr_LR_Symbols
typedef struct s_Lalr_LR_Symbols        *Lalr_LR_Symbols;
#endif

#ifndef DEF_TYPE_Lalr_LR_state
#define DEF_TYPE_Lalr_LR_state
typedef struct s_Lalr_LR_state  *Lalr_LR_state;
#endif

#ifndef DEF_TYPE_Lalr_Item
#define DEF_TYPE_Lalr_Item
typedef struct s_Lalr_Item      *Lalr_Item;
#endif

#ifndef DEF_TYPE_Lalr_Transition
#define DEF_TYPE_Lalr_Transition
typedef struct s_Lalr_Transition        *Lalr_Transition;
#endif

#ifndef DEF_TYPE_Lalr_Scope
#define DEF_TYPE_Lalr_Scope
typedef struct s_Lalr_Scope     *Lalr_Scope;
#endif

#ifndef DEF_TYPE_List_Lalr_LR_Symbols
#define DEF_TYPE_List_Lalr_LR_Symbols
typedef struct s_List_Lalr_LR_Symbols   *List_Lalr_LR_Symbols;
#endif

#ifndef DEF_TYPE_List_Lalr_LR_Symbol
#define DEF_TYPE_List_Lalr_LR_Symbol
typedef struct s_List_Lalr_LR_Symbol    *List_Lalr_LR_Symbol;
#endif

#ifndef DEF_TYPE_List_Lalr_Transition
#define DEF_TYPE_List_Lalr_Transition
typedef struct s_List_Lalr_Transition   *List_Lalr_Transition;
#endif

#ifndef DEF_TYPE_List_Lalr_Item
#define DEF_TYPE_List_Lalr_Item
typedef struct s_List_Lalr_Item *List_Lalr_Item;
#endif

#ifndef DEF_TYPE_List_Lalr_LR_state
#define DEF_TYPE_List_Lalr_LR_state
typedef struct s_List_Lalr_LR_state     *List_Lalr_LR_state;
#endif

#ifndef DEF_TYPE_List_Lalr_Production
#define DEF_TYPE_List_Lalr_Production
typedef struct s_List_Lalr_Production   *List_Lalr_Production;
#endif

#include <front/scan_support.h>
#include <front/print_support.h>
#include <front/SymTab.h>
#include "Lalr_parse.h"
#include "Lalr_defs.h"

#include "grammar.h"
#include "GenLalr.h"
typedef Bind Bind_Lalr_Production;
typedef List_Bind List_Bind_Lalr_Production;
#define List_Bind_Lalr_Production_data(x) (Bind_Lalr_Production)Front_List_data((Front_List)(x))
#define List_Bind_Lalr_Production_next(x) (List_Bind_Lalr_Production)Front_List_next((Front_List)(x))
#define Bind_Lalr_Production_kind 0

extern Lalr_Lalr Lalr_root;

#ifndef DEF_STRUCT_Lalr_Lalr
#define DEF_STRUCT_Lalr_Lalr

struct s_Lalr_Lalr {
  SrcInfo       src_info;  
  List_Lalr_Production  grammar;  
  List_Lalr_LR_state    states;  
} ;

#define Lalr_Lalr_src_info(_p)  ((*_p).src_info)
#define Lalr_Lalr_srcinfo(_p)   ((*_p).src_info)
#define Lalr_Lalr_loc(_p)       ((*_p).src_info->loc)
#define Lalr_Lalr_grammar(_p)   ((*_p).grammar)
#define Lalr_Lalr_states(_p)    ((*_p).states)

extern Lalr_Lalr Create_Lalr_Lalr	(SrcInfo src_info, List_Lalr_Production grammar, List_Lalr_LR_state states);

#endif /* DEF_STRUCT_Lalr_Lalr */

#ifndef DEF_STRUCT_Lalr_Production
#define DEF_STRUCT_Lalr_Production

struct s_Lalr_Production {
  SrcInfo       src_info;  
  Int   _num;  
  Lalr_Scope    scope;  
  Lalr_Scope    old_scope;  
  Ident lhs;  
  Bind_Lalr_Production  lhs_bind;  
  Lalr_LR_Symbols       rhs;  
  Lalr_Emptiness        empty;  
  List_Ident    first;  
  ProdRule      prod_rule;  
  Int   num;  
} ;

#define Lalr_Production_src_info(_p)    ((*_p).src_info)
#define Lalr_Production_srcinfo(_p)     ((*_p).src_info)
#define Lalr_Production_loc(_p) ((*_p).src_info->loc)
#define Lalr_Production__num(_p)        ((*_p)._num)
#define Lalr_Production_scope(_p)       ((*_p).scope)
#define Lalr_Production_old_scope(_p)   ((*_p).old_scope)
#define Lalr_Production_lhs(_p) ((*_p).lhs)
#define Lalr_Production_lhs_bind(_p)    ((*_p).lhs_bind)
#define Lalr_Production_rhs(_p) ((*_p).rhs)
#define Lalr_Production_empty(_p)       ((*_p).empty)
#define Lalr_Production_first(_p)       ((*_p).first)
#define Lalr_Production_prod_rule(_p)   ((*_p).prod_rule)
#define Lalr_Production_num(_p) ((*_p).num)

extern Lalr_Production Create_Lalr_Production	(SrcInfo src_info, Ident lhs, Lalr_LR_Symbols rhs, Lalr_Emptiness empty, List_Ident first);

#endif /* DEF_STRUCT_Lalr_Production */

#ifndef DEF_STRUCT_Lalr_LR_Symbol
#define DEF_STRUCT_Lalr_LR_Symbol

struct s_Lalr_LR_Symbol {
  SrcInfo       src_info;  
  Int   _num;  
  Lalr_Scope    scope;  
  Lalr_Scope    old_scope;  
  Lalr_LR_Symbol        memo_link;  
  Ident id;  
  List_Bind_Lalr_Production     prods_bind;  
  List_Lalr_Production  prods;  
  Bool  make_empty;  
  List_field    fields;  
  List_Ident    first;  
  Bool  empty;  
  EvalState     first_eval;  
  EvalState     empty_eval;  
  Bool  start;  
  Ident hole;  
  Lalr_LR_state start_state;  
  Int   num;  
  Int   hole_num;  
} ;

#define Lalr_LR_Symbol_src_info(_p)     ((*_p).src_info)
#define Lalr_LR_Symbol_srcinfo(_p)      ((*_p).src_info)
#define Lalr_LR_Symbol_loc(_p)  ((*_p).src_info->loc)
#define Lalr_LR_Symbol__num(_p) ((*_p)._num)
#define Lalr_LR_Symbol_scope(_p)        ((*_p).scope)
#define Lalr_LR_Symbol_old_scope(_p)    ((*_p).old_scope)
#define Lalr_LR_Symbol_memo_link(_p)    ((*_p).memo_link)
#define Lalr_LR_Symbol_id(_p)   ((*_p).id)
#define Lalr_LR_Symbol_prods_bind(_p)   ((*_p).prods_bind)
#define Lalr_LR_Symbol_prods(_p)        ((*_p).prods)
#define Lalr_LR_Symbol_make_empty(_p)   ((*_p).make_empty)
#define Lalr_LR_Symbol_fields(_p)       ((*_p).fields)
#define Lalr_LR_Symbol_first(_p)        ((*_p).first)
#define Lalr_LR_Symbol_empty(_p)        ((*_p).empty)
#define Lalr_LR_Symbol_first_eval(_p)   ((*_p).first_eval)
#define Lalr_LR_Symbol_empty_eval(_p)   ((*_p).empty_eval)
#define Lalr_LR_Symbol_start(_p)        ((*_p).start)
#define Lalr_LR_Symbol_hole(_p) ((*_p).hole)
#define Lalr_LR_Symbol_start_state(_p)  ((*_p).start_state)
#define Lalr_LR_Symbol_num(_p)  ((*_p).num)
#define Lalr_LR_Symbol_hole_num(_p)     ((*_p).hole_num)

extern void Memo_Traverse_Lalr_LR_Symbol (void (*f)(Lalr_LR_Symbol));
extern void Memo_Clear_Lalr_LR_Symbol (void);
extern Lalr_LR_Symbol Create_Lalr_LR_Symbol	(SrcInfo src_info, Ident id, Bool make_empty);

#endif /* DEF_STRUCT_Lalr_LR_Symbol */

#ifndef DEF_STRUCT_Lalr_LR_Symbols
#define DEF_STRUCT_Lalr_LR_Symbols

struct s_Lalr_LR_Symbols {
  SrcInfo       src_info;  
  Lalr_LR_Symbols       memo_link;  
  Lalr_LR_Symbol        data;  
  Lalr_LR_Symbols       next;  
  Int   num;  
} ;

#define Lalr_LR_Symbols_src_info(_p)    ((*_p).src_info)
#define Lalr_LR_Symbols_srcinfo(_p)     ((*_p).src_info)
#define Lalr_LR_Symbols_loc(_p) ((*_p).src_info->loc)
#define Lalr_LR_Symbols_memo_link(_p)   ((*_p).memo_link)
#define Lalr_LR_Symbols_data(_p)        ((*_p).data)
#define Lalr_LR_Symbols_next(_p)        ((*_p).next)
#define Lalr_LR_Symbols_num(_p) ((*_p).num)

extern void Memo_Traverse_Lalr_LR_Symbols (void (*f)(Lalr_LR_Symbols));
extern void Memo_Clear_Lalr_LR_Symbols (void);
extern Lalr_LR_Symbols Create_Lalr_LR_Symbols	(SrcInfo src_info, Lalr_LR_Symbol data, Lalr_LR_Symbols next);

#endif /* DEF_STRUCT_Lalr_LR_Symbols */

#ifndef DEF_STRUCT_Lalr_LR_state
#define DEF_STRUCT_Lalr_LR_state

struct s_Lalr_LR_state {
  SrcInfo       src_info;  
  Int   num;  
  List_Lalr_Item        items;  
  List_Lalr_Transition  transitions;  
  Lalr_LR_Symbol        start_state;  
} ;

#define Lalr_LR_state_src_info(_p)      ((*_p).src_info)
#define Lalr_LR_state_srcinfo(_p)       ((*_p).src_info)
#define Lalr_LR_state_loc(_p)   ((*_p).src_info->loc)
#define Lalr_LR_state_num(_p)   ((*_p).num)
#define Lalr_LR_state_items(_p) ((*_p).items)
#define Lalr_LR_state_transitions(_p)   ((*_p).transitions)
#define Lalr_LR_state_start_state(_p)   ((*_p).start_state)

extern Lalr_LR_state Create_Lalr_LR_state	(SrcInfo src_info, Int num, List_Lalr_Item items, List_Lalr_Transition transitions);

#endif /* DEF_STRUCT_Lalr_LR_state */

#ifndef DEF_STRUCT_Lalr_Item
#define DEF_STRUCT_Lalr_Item

struct s_Lalr_Item {
  SrcInfo       src_info;  
  Ident lhs;  
  List_Lalr_LR_Symbol   rhs1;  
  Lalr_LR_Symbols       rhs2;  
  List_Ident    followers;  
  Lalr_Production       production;  
  List_Item     predecessors;  
  Bool  start_item;  
  Bool  conflict;  
} ;

#define Lalr_Item_src_info(_p)  ((*_p).src_info)
#define Lalr_Item_srcinfo(_p)   ((*_p).src_info)
#define Lalr_Item_loc(_p)       ((*_p).src_info->loc)
#define Lalr_Item_lhs(_p)       ((*_p).lhs)
#define Lalr_Item_rhs1(_p)      ((*_p).rhs1)
#define Lalr_Item_rhs2(_p)      ((*_p).rhs2)
#define Lalr_Item_followers(_p) ((*_p).followers)
#define Lalr_Item_production(_p)        ((*_p).production)
#define Lalr_Item_predecessors(_p)      ((*_p).predecessors)
#define Lalr_Item_start_item(_p)        ((*_p).start_item)
#define Lalr_Item_conflict(_p)  ((*_p).conflict)

extern Lalr_Item Create_Lalr_Item	(SrcInfo src_info, Ident lhs, List_Lalr_LR_Symbol rhs1, Lalr_LR_Symbols rhs2, List_Ident followers);

#endif /* DEF_STRUCT_Lalr_Item */

#ifndef DEF_STRUCT_Lalr_Transition
#define DEF_STRUCT_Lalr_Transition

struct s_Lalr_Transition {
  SrcInfo       src_info;  
  Lalr_LR_Symbol        symbol;  
  Int   num;  
  Lalr_LR_state target;  
  Bool  conflict;  
} ;

#define Lalr_Transition_src_info(_p)    ((*_p).src_info)
#define Lalr_Transition_srcinfo(_p)     ((*_p).src_info)
#define Lalr_Transition_loc(_p) ((*_p).src_info->loc)
#define Lalr_Transition_symbol(_p)      ((*_p).symbol)
#define Lalr_Transition_num(_p) ((*_p).num)
#define Lalr_Transition_target(_p)      ((*_p).target)
#define Lalr_Transition_conflict(_p)    ((*_p).conflict)

extern Lalr_Transition Create_Lalr_Transition	(SrcInfo src_info, Lalr_LR_Symbol symbol, Int num);

#endif /* DEF_STRUCT_Lalr_Transition */

#ifndef DEF_STRUCT_Lalr_Scope
#define DEF_STRUCT_Lalr_Scope

struct s_Lalr_Scope {
  Lalr_Scope    next;  
  Int   _self;  
  Int   _end;  
} ;

#define Lalr_Scope_next(_p)     ((*_p).next)
#define Lalr_Scope__self(_p)    ((*_p)._self)
#define Lalr_Scope__end(_p)     ((*_p)._end)

extern Lalr_Scope Create_Lalr_Scope	(Lalr_Scope next);

#endif /* DEF_STRUCT_Lalr_Scope */

#ifndef DEF_STRUCT_List_Lalr_LR_Symbols
#define DEF_STRUCT_List_Lalr_LR_Symbols

struct s_List_Lalr_LR_Symbols {
  Lalr_LR_Symbols       data;  
  List_Lalr_LR_Symbols  next;  
} ;

#define List_Lalr_LR_Symbols_data(_p)   ((*_p).data)
#define List_Lalr_LR_Symbols_next(_p)   ((*_p).next)

#ifndef Create_List_Lalr_LR_Symbols
#define Create_List_Lalr_LR_Symbols(x,y) (List_Lalr_LR_Symbols)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Lalr_LR_Symbols_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Lalr_LR_Symbols */

#ifndef DEF_STRUCT_List_Lalr_LR_Symbol
#define DEF_STRUCT_List_Lalr_LR_Symbol

struct s_List_Lalr_LR_Symbol {
  Lalr_LR_Symbol        data;  
  List_Lalr_LR_Symbol   next;  
} ;

#define List_Lalr_LR_Symbol_data(_p)    ((*_p).data)
#define List_Lalr_LR_Symbol_next(_p)    ((*_p).next)

#ifndef Create_List_Lalr_LR_Symbol
#define Create_List_Lalr_LR_Symbol(x,y) (List_Lalr_LR_Symbol)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Lalr_LR_Symbol_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Lalr_LR_Symbol */

#ifndef DEF_STRUCT_List_Lalr_Transition
#define DEF_STRUCT_List_Lalr_Transition

struct s_List_Lalr_Transition {
  Lalr_Transition       data;  
  List_Lalr_Transition  next;  
} ;

#define List_Lalr_Transition_data(_p)   ((*_p).data)
#define List_Lalr_Transition_next(_p)   ((*_p).next)

#ifndef Create_List_Lalr_Transition
#define Create_List_Lalr_Transition(x,y) (List_Lalr_Transition)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Lalr_Transition_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Lalr_Transition */

#ifndef DEF_STRUCT_List_Lalr_Item
#define DEF_STRUCT_List_Lalr_Item

struct s_List_Lalr_Item {
  Lalr_Item     data;  
  List_Lalr_Item        next;  
} ;

#define List_Lalr_Item_data(_p) ((*_p).data)
#define List_Lalr_Item_next(_p) ((*_p).next)

#ifndef Create_List_Lalr_Item
#define Create_List_Lalr_Item(x,y) (List_Lalr_Item)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Lalr_Item_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Lalr_Item */

#ifndef DEF_STRUCT_List_Lalr_LR_state
#define DEF_STRUCT_List_Lalr_LR_state

struct s_List_Lalr_LR_state {
  Lalr_LR_state data;  
  List_Lalr_LR_state    next;  
} ;

#define List_Lalr_LR_state_data(_p)     ((*_p).data)
#define List_Lalr_LR_state_next(_p)     ((*_p).next)

#ifndef Create_List_Lalr_LR_state
#define Create_List_Lalr_LR_state(x,y) (List_Lalr_LR_state)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Lalr_LR_state_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Lalr_LR_state */

#ifndef DEF_STRUCT_List_Lalr_Production
#define DEF_STRUCT_List_Lalr_Production

struct s_List_Lalr_Production {
  Lalr_Production       data;  
  List_Lalr_Production  next;  
} ;

#define List_Lalr_Production_data(_p)   ((*_p).data)
#define List_Lalr_Production_next(_p)   ((*_p).next)

#ifndef Create_List_Lalr_Production
#define Create_List_Lalr_Production(x,y) (List_Lalr_Production)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Lalr_Production_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Lalr_Production */

#define PRE_ACTION  1
#define POST_ACTION 0

typedef struct s_Lalr_TraverseTable {
  Front_Traversal traversal;
  Pointer (*action_Lalr[2]) (Lalr_Lalr, Pointer);
  Bool skip_children_Lalr;
  Pointer (*action_Production[2]) (Lalr_Production, Pointer);
  Bool skip_children_Production;
  Pointer (*action_LR_Symbol[2]) (Lalr_LR_Symbol, Pointer);
  Bool skip_children_LR_Symbol;
  Pointer (*action_LR_Symbols[2]) (Lalr_LR_Symbols, Pointer);
  Bool skip_children_LR_Symbols;
  Pointer (*action_LR_state[2]) (Lalr_LR_state, Pointer);
  Bool skip_children_LR_state;
  Pointer (*action_Item[2]) (Lalr_Item, Pointer);
  Bool skip_children_Item;
  Pointer (*action_Transition[2]) (Lalr_Transition, Pointer);
  Bool skip_children_Transition;
  Pointer (*action_Scope[2]) (Lalr_Scope, Pointer);
  Bool skip_children_Scope;
  Pointer (*action_List_LR_Symbols[2]) (List_Lalr_LR_Symbols, Pointer);
  Bool skip_children_List_LR_Symbols;
  Pointer (*action_List_LR_Symbol[2]) (List_Lalr_LR_Symbol, Pointer);
  Bool skip_children_List_LR_Symbol;
  Pointer (*action_List_Transition[2]) (List_Lalr_Transition, Pointer);
  Bool skip_children_List_Transition;
  Pointer (*action_List_Item[2]) (List_Lalr_Item, Pointer);
  Bool skip_children_List_Item;
  Pointer (*action_List_LR_state[2]) (List_Lalr_LR_state, Pointer);
  Bool skip_children_List_LR_state;
  Pointer (*action_List_Production[2]) (List_Lalr_Production, Pointer);
  Bool skip_children_List_Production;
  Pointer (*action_Emptiness[2]) (Lalr_Emptiness, Pointer);
  Bool skip_children_Emptiness;
} *Lalr_TraverseTable;

extern Pointer Traverse_Lalr_Emptiness (Lalr_Emptiness me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_Lalr_Lalr (Lalr_Lalr me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_Lalr_Production (Lalr_Production me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_Lalr_LR_Symbol (Lalr_LR_Symbol me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_Lalr_LR_Symbols (Lalr_LR_Symbols me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_Lalr_LR_state (Lalr_LR_state me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_Lalr_Item (Lalr_Item me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_Lalr_Transition (Lalr_Transition me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_Lalr_Scope (Lalr_Scope me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Lalr_Transition (List_Lalr_Transition me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Lalr_Item (List_Lalr_Item me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Lalr_LR_state (List_Lalr_LR_state me, Lalr_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Lalr_Production (List_Lalr_Production me, Lalr_TraverseTable table, Pointer val);

typedef struct s_void_Lalr_TraverseTable {
  void (*action_Lalr[2]) (Lalr_Lalr);
  Bool skip_children_Lalr;
  void (*action_Production[2]) (Lalr_Production);
  Bool skip_children_Production;
  void (*action_LR_Symbol[2]) (Lalr_LR_Symbol);
  Bool skip_children_LR_Symbol;
  void (*action_LR_Symbols[2]) (Lalr_LR_Symbols);
  Bool skip_children_LR_Symbols;
  void (*action_LR_state[2]) (Lalr_LR_state);
  Bool skip_children_LR_state;
  void (*action_Item[2]) (Lalr_Item);
  Bool skip_children_Item;
  void (*action_Transition[2]) (Lalr_Transition);
  Bool skip_children_Transition;
  void (*action_Scope[2]) (Lalr_Scope);
  Bool skip_children_Scope;
  void (*action_List_LR_Symbols[2]) (List_Lalr_LR_Symbols);
  Bool skip_children_List_LR_Symbols;
  void (*action_List_LR_Symbol[2]) (List_Lalr_LR_Symbol);
  Bool skip_children_List_LR_Symbol;
  void (*action_List_Transition[2]) (List_Lalr_Transition);
  Bool skip_children_List_Transition;
  void (*action_List_Item[2]) (List_Lalr_Item);
  Bool skip_children_List_Item;
  void (*action_List_LR_state[2]) (List_Lalr_LR_state);
  Bool skip_children_List_LR_state;
  void (*action_List_Production[2]) (List_Lalr_Production);
  Bool skip_children_List_Production;
  void (*action_Emptiness[2]) (Lalr_Emptiness);
  Bool skip_children_Emptiness;
} *void_Lalr_TraverseTable;

extern void Traverse_void_Lalr_Emptiness (Lalr_Emptiness me, void_Lalr_TraverseTable table);
extern void Traverse_void_Lalr_Lalr (Lalr_Lalr me, void_Lalr_TraverseTable table);
extern void Traverse_void_Lalr_Production (Lalr_Production me, void_Lalr_TraverseTable table);
extern void Traverse_void_Lalr_LR_Symbol (Lalr_LR_Symbol me, void_Lalr_TraverseTable table);
extern void Traverse_void_Lalr_LR_Symbols (Lalr_LR_Symbols me, void_Lalr_TraverseTable table);
extern void Traverse_void_Lalr_LR_state (Lalr_LR_state me, void_Lalr_TraverseTable table);
extern void Traverse_void_Lalr_Item (Lalr_Item me, void_Lalr_TraverseTable table);
extern void Traverse_void_Lalr_Transition (Lalr_Transition me, void_Lalr_TraverseTable table);
extern void Traverse_void_Lalr_Scope (Lalr_Scope me, void_Lalr_TraverseTable table);
extern void Traverse_void_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols me, void_Lalr_TraverseTable table);
extern void Traverse_void_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol me, void_Lalr_TraverseTable table);
extern void Traverse_void_List_Lalr_Transition (List_Lalr_Transition me, void_Lalr_TraverseTable table);
extern void Traverse_void_List_Lalr_Item (List_Lalr_Item me, void_Lalr_TraverseTable table);
extern void Traverse_void_List_Lalr_LR_state (List_Lalr_LR_state me, void_Lalr_TraverseTable table);
extern void Traverse_void_List_Lalr_Production (List_Lalr_Production me, void_Lalr_TraverseTable table);

typedef struct s_copy_Lalr_TraverseTable {
  Front_ClearBackEdges clear_back_edges;
  Lalr_Lalr (*action_Lalr[2]) (Lalr_Lalr, Lalr_Lalr);
  Bool skip_children_Lalr;
  Lalr_Production (*action_Production[2]) (Lalr_Production, Lalr_Production);
  Bool skip_children_Production;
  Lalr_LR_Symbol (*action_LR_Symbol[2]) (Lalr_LR_Symbol, Lalr_LR_Symbol);
  Bool skip_children_LR_Symbol;
  Lalr_LR_Symbols (*action_LR_Symbols[2]) (Lalr_LR_Symbols, Lalr_LR_Symbols);
  Bool skip_children_LR_Symbols;
  Lalr_LR_state (*action_LR_state[2]) (Lalr_LR_state, Lalr_LR_state);
  Bool skip_children_LR_state;
  Lalr_Item (*action_Item[2]) (Lalr_Item, Lalr_Item);
  Bool skip_children_Item;
  Lalr_Transition (*action_Transition[2]) (Lalr_Transition, Lalr_Transition);
  Bool skip_children_Transition;
  Lalr_Scope (*action_Scope[2]) (Lalr_Scope, Lalr_Scope);
  Bool skip_children_Scope;
  List_Lalr_LR_Symbols (*action_List_LR_Symbols[2]) (List_Lalr_LR_Symbols, List_Lalr_LR_Symbols);
  Bool skip_children_List_LR_Symbols;
  List_Lalr_LR_Symbol (*action_List_LR_Symbol[2]) (List_Lalr_LR_Symbol, List_Lalr_LR_Symbol);
  Bool skip_children_List_LR_Symbol;
  List_Lalr_Transition (*action_List_Transition[2]) (List_Lalr_Transition, List_Lalr_Transition);
  Bool skip_children_List_Transition;
  List_Lalr_Item (*action_List_Item[2]) (List_Lalr_Item, List_Lalr_Item);
  Bool skip_children_List_Item;
  List_Lalr_LR_state (*action_List_LR_state[2]) (List_Lalr_LR_state, List_Lalr_LR_state);
  Bool skip_children_List_LR_state;
  List_Lalr_Production (*action_List_Production[2]) (List_Lalr_Production, List_Lalr_Production);
  Bool skip_children_List_Production;
  Lalr_Emptiness (*action_Emptiness[2]) (Lalr_Emptiness, Lalr_Emptiness);
  Bool skip_children_Emptiness;
} *copy_Lalr_TraverseTable;

extern Lalr_Emptiness Traverse_copy_Lalr_Emptiness (Lalr_Emptiness me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_Emptiness
#define COPY_Lalr_Emptiness(x) Traverse_copy_Lalr_Emptiness(x, &Lalr_copy_actions)
#endif
extern Lalr_Lalr Traverse_copy_Lalr_Lalr (Lalr_Lalr me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_Lalr
#define COPY_Lalr_Lalr(x) Traverse_copy_Lalr_Lalr(x, &Lalr_copy_actions)
#endif
extern Lalr_Production Traverse_copy_Lalr_Production (Lalr_Production me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_Production
#define COPY_Lalr_Production(x) Traverse_copy_Lalr_Production(x, &Lalr_copy_actions)
#endif
extern Lalr_LR_Symbol Traverse_copy_Lalr_LR_Symbol (Lalr_LR_Symbol me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_LR_Symbol
#define COPY_Lalr_LR_Symbol(x) Traverse_copy_Lalr_LR_Symbol(x, &Lalr_copy_actions)
#endif
extern Lalr_LR_Symbols Traverse_copy_Lalr_LR_Symbols (Lalr_LR_Symbols me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_LR_Symbols
#define COPY_Lalr_LR_Symbols(x) Traverse_copy_Lalr_LR_Symbols(x, &Lalr_copy_actions)
#endif
extern Lalr_LR_state Traverse_copy_Lalr_LR_state (Lalr_LR_state me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_LR_state
#define COPY_Lalr_LR_state(x) Traverse_copy_Lalr_LR_state(x, &Lalr_copy_actions)
#endif
extern Lalr_Item Traverse_copy_Lalr_Item (Lalr_Item me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_Item
#define COPY_Lalr_Item(x) Traverse_copy_Lalr_Item(x, &Lalr_copy_actions)
#endif
extern Lalr_Transition Traverse_copy_Lalr_Transition (Lalr_Transition me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_Transition
#define COPY_Lalr_Transition(x) Traverse_copy_Lalr_Transition(x, &Lalr_copy_actions)
#endif
extern Lalr_Scope Traverse_copy_Lalr_Scope (Lalr_Scope me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_Scope
#define COPY_Lalr_Scope(x) Traverse_copy_Lalr_Scope(x, &Lalr_copy_actions)
#endif
extern List_Lalr_LR_Symbols Traverse_copy_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_List_LR_Symbols
#define COPY_Lalr_List_LR_Symbols(x) Traverse_copy_List_Lalr_LR_Symbols(x, &Lalr_copy_actions)
#endif
extern List_Lalr_LR_Symbol Traverse_copy_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_List_LR_Symbol
#define COPY_Lalr_List_LR_Symbol(x) Traverse_copy_List_Lalr_LR_Symbol(x, &Lalr_copy_actions)
#endif
extern List_Lalr_Transition Traverse_copy_List_Lalr_Transition (List_Lalr_Transition me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_List_Transition
#define COPY_Lalr_List_Transition(x) Traverse_copy_List_Lalr_Transition(x, &Lalr_copy_actions)
#endif
extern List_Lalr_Item Traverse_copy_List_Lalr_Item (List_Lalr_Item me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_List_Item
#define COPY_Lalr_List_Item(x) Traverse_copy_List_Lalr_Item(x, &Lalr_copy_actions)
#endif
extern List_Lalr_LR_state Traverse_copy_List_Lalr_LR_state (List_Lalr_LR_state me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_List_LR_state
#define COPY_Lalr_List_LR_state(x) Traverse_copy_List_Lalr_LR_state(x, &Lalr_copy_actions)
#endif
extern List_Lalr_Production Traverse_copy_List_Lalr_Production (List_Lalr_Production me, copy_Lalr_TraverseTable table);
#ifndef COPY_Lalr_List_Production
#define COPY_Lalr_List_Production(x) Traverse_copy_List_Lalr_Production(x, &Lalr_copy_actions)
#endif

typedef struct s_compare_Lalr_TraverseTable {
  int (*action_Lalr[2]) (Lalr_Lalr, Lalr_Lalr);
  Bool skip_children_Lalr;
  int (*action_Production[2]) (Lalr_Production, Lalr_Production);
  Bool skip_children_Production;
  int (*action_LR_Symbol[2]) (Lalr_LR_Symbol, Lalr_LR_Symbol);
  Bool skip_children_LR_Symbol;
  int (*action_LR_Symbols[2]) (Lalr_LR_Symbols, Lalr_LR_Symbols);
  Bool skip_children_LR_Symbols;
  int (*action_LR_state[2]) (Lalr_LR_state, Lalr_LR_state);
  Bool skip_children_LR_state;
  int (*action_Item[2]) (Lalr_Item, Lalr_Item);
  Bool skip_children_Item;
  int (*action_Transition[2]) (Lalr_Transition, Lalr_Transition);
  Bool skip_children_Transition;
  int (*action_Scope[2]) (Lalr_Scope, Lalr_Scope);
  Bool skip_children_Scope;
  int (*action_List_LR_Symbols[2]) (List_Lalr_LR_Symbols, List_Lalr_LR_Symbols);
  Bool skip_children_List_LR_Symbols;
  int (*action_List_LR_Symbol[2]) (List_Lalr_LR_Symbol, List_Lalr_LR_Symbol);
  Bool skip_children_List_LR_Symbol;
  int (*action_List_Transition[2]) (List_Lalr_Transition, List_Lalr_Transition);
  Bool skip_children_List_Transition;
  int (*action_List_Item[2]) (List_Lalr_Item, List_Lalr_Item);
  Bool skip_children_List_Item;
  int (*action_List_LR_state[2]) (List_Lalr_LR_state, List_Lalr_LR_state);
  Bool skip_children_List_LR_state;
  int (*action_List_Production[2]) (List_Lalr_Production, List_Lalr_Production);
  Bool skip_children_List_Production;
  int (*action_Emptiness[2]) (Lalr_Emptiness, Lalr_Emptiness);
  Bool skip_children_Emptiness;
} *compare_Lalr_TraverseTable;

extern int Traverse_compare_Lalr_Emptiness (Lalr_Emptiness x, Lalr_Emptiness y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_Lalr_Lalr (Lalr_Lalr x, Lalr_Lalr y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_Lalr_Production (Lalr_Production x, Lalr_Production y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_Lalr_LR_Symbol (Lalr_LR_Symbol x, Lalr_LR_Symbol y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_Lalr_LR_Symbols (Lalr_LR_Symbols x, Lalr_LR_Symbols y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_Lalr_LR_state (Lalr_LR_state x, Lalr_LR_state y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_Lalr_Item (Lalr_Item x, Lalr_Item y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_Lalr_Transition (Lalr_Transition x, Lalr_Transition y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_Lalr_Scope (Lalr_Scope x, Lalr_Scope y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols x, List_Lalr_LR_Symbols y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol x, List_Lalr_LR_Symbol y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_List_Lalr_Transition (List_Lalr_Transition x, List_Lalr_Transition y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_List_Lalr_Item (List_Lalr_Item x, List_Lalr_Item y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_List_Lalr_LR_state (List_Lalr_LR_state x, List_Lalr_LR_state y, compare_Lalr_TraverseTable table);
extern int Traverse_compare_List_Lalr_Production (List_Lalr_Production x, List_Lalr_Production y, compare_Lalr_TraverseTable table);


extern void Lalr_fill_table (Lalr_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void void_Lalr_fill_table (void_Lalr_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void copy_Lalr_fill_table (copy_Lalr_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void compare_Lalr_fill_table (compare_Lalr_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern struct s_Lalr_TraverseTable Lalr_scope_actions;

extern struct s_void_Lalr_TraverseTable Lalr_defining_actions;

extern struct s_void_Lalr_TraverseTable Lalr_applied_actions;

extern struct s_void_Lalr_TraverseTable Lalr_check_actions;

extern struct s_void_Lalr_TraverseTable Lalr_print_actions;

extern struct s_copy_Lalr_TraverseTable Lalr_copy_actions;

extern struct s_compare_Lalr_TraverseTable Lalr_compare_actions;

typedef int Lalr_NameSpaces;

extern Lalr_NameSpaces Lalr_namespaces[1];

#define Lalr_DefaultNameSpace Lalr_namespaces[0]

#define Lalr_NUM_NAMESPACES 1

extern void Decorate_Lalr (Lalr_Lalr r);

#endif /* _Lalr */
