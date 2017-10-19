#ifndef Lalr_NO_DEFS
#define _Lalr_h

#ifndef NUM_Emptiness
#define NUM_Emptiness NUM_Lalr_Emptiness
#endif
#ifndef Emptiness
#define Emptiness Lalr_Emptiness
#endif
#ifndef Lalr
#define Lalr Lalr_Lalr
#endif
#ifndef Production
#define Production Lalr_Production
#endif
#ifndef LR_Symbol
#define LR_Symbol Lalr_LR_Symbol
#endif
#ifndef LR_Symbols
#define LR_Symbols Lalr_LR_Symbols
#endif
#ifndef LR_state
#define LR_state Lalr_LR_state
#endif
#ifndef Item
#define Item Lalr_Item
#endif
#ifndef Transition
#define Transition Lalr_Transition
#endif
#ifndef Scope
#define Scope Lalr_Scope
#endif
#ifndef List_Production
#define List_Production List_Lalr_Production
#endif
#ifndef List_LR_state
#define List_LR_state List_Lalr_LR_state
#endif
#ifndef Bind_Production
#define Bind_Production Bind_Lalr_Production
#endif
#ifndef List_Ident
#define List_Ident List_Ident
#endif
#ifndef List_Bind_Production
#define List_Bind_Production List_Bind_Lalr_Production
#endif
#ifndef List_Item
#define List_Item List_Lalr_Item
#endif
#ifndef List_Transition
#define List_Transition List_Lalr_Transition
#endif
#ifndef List_LR_Symbol
#define List_LR_Symbol List_Lalr_LR_Symbol
#endif
#ifndef List_LR_Symbols
#define List_LR_Symbols List_Lalr_LR_Symbols
#endif
#ifndef Lalr_src_info
#define Lalr_src_info Lalr_Lalr_src_info
#endif
#ifndef Lalr_srcinfo
#define Lalr_srcinfo Lalr_Lalr_srcinfo
#endif
#ifndef Lalr_loc
#define Lalr_loc Lalr_Lalr_loc
#endif
#ifndef Lalr_grammar
#define Lalr_grammar Lalr_Lalr_grammar
#endif
#ifndef Lalr_states
#define Lalr_states Lalr_Lalr_states
#endif
#ifndef Production_src_info
#define Production_src_info Lalr_Production_src_info
#endif
#ifndef Production_srcinfo
#define Production_srcinfo Lalr_Production_srcinfo
#endif
#ifndef Production_loc
#define Production_loc Lalr_Production_loc
#endif
#ifndef Production__num
#define Production__num Lalr_Production__num
#endif
#ifndef Production_scope
#define Production_scope Lalr_Production_scope
#endif
#ifndef Production_old_scope
#define Production_old_scope Lalr_Production_old_scope
#endif
#ifndef Production_lhs
#define Production_lhs Lalr_Production_lhs
#endif
#ifndef Production_lhs_bind
#define Production_lhs_bind Lalr_Production_lhs_bind
#endif
#ifndef Production_rhs
#define Production_rhs Lalr_Production_rhs
#endif
#ifndef Production_empty
#define Production_empty Lalr_Production_empty
#endif
#ifndef Production_first
#define Production_first Lalr_Production_first
#endif
#ifndef Production_prod_rule
#define Production_prod_rule Lalr_Production_prod_rule
#endif
#ifndef Production_num
#define Production_num Lalr_Production_num
#endif
#ifndef LR_Symbol_src_info
#define LR_Symbol_src_info Lalr_LR_Symbol_src_info
#endif
#ifndef LR_Symbol_srcinfo
#define LR_Symbol_srcinfo Lalr_LR_Symbol_srcinfo
#endif
#ifndef LR_Symbol_loc
#define LR_Symbol_loc Lalr_LR_Symbol_loc
#endif
#ifndef LR_Symbol__num
#define LR_Symbol__num Lalr_LR_Symbol__num
#endif
#ifndef LR_Symbol_scope
#define LR_Symbol_scope Lalr_LR_Symbol_scope
#endif
#ifndef LR_Symbol_old_scope
#define LR_Symbol_old_scope Lalr_LR_Symbol_old_scope
#endif
#ifndef LR_Symbol_memo_link
#define LR_Symbol_memo_link Lalr_LR_Symbol_memo_link
#endif
#ifndef LR_Symbol_id
#define LR_Symbol_id Lalr_LR_Symbol_id
#endif
#ifndef LR_Symbol_prods_bind
#define LR_Symbol_prods_bind Lalr_LR_Symbol_prods_bind
#endif
#ifndef LR_Symbol_prods
#define LR_Symbol_prods Lalr_LR_Symbol_prods
#endif
#ifndef LR_Symbol_make_empty
#define LR_Symbol_make_empty Lalr_LR_Symbol_make_empty
#endif
#ifndef LR_Symbol_fields
#define LR_Symbol_fields Lalr_LR_Symbol_fields
#endif
#ifndef LR_Symbol_first
#define LR_Symbol_first Lalr_LR_Symbol_first
#endif
#ifndef LR_Symbol_empty
#define LR_Symbol_empty Lalr_LR_Symbol_empty
#endif
#ifndef LR_Symbol_first_eval
#define LR_Symbol_first_eval Lalr_LR_Symbol_first_eval
#endif
#ifndef LR_Symbol_empty_eval
#define LR_Symbol_empty_eval Lalr_LR_Symbol_empty_eval
#endif
#ifndef LR_Symbol_start
#define LR_Symbol_start Lalr_LR_Symbol_start
#endif
#ifndef LR_Symbol_hole
#define LR_Symbol_hole Lalr_LR_Symbol_hole
#endif
#ifndef LR_Symbol_start_state
#define LR_Symbol_start_state Lalr_LR_Symbol_start_state
#endif
#ifndef LR_Symbol_num
#define LR_Symbol_num Lalr_LR_Symbol_num
#endif
#ifndef LR_Symbol_hole_num
#define LR_Symbol_hole_num Lalr_LR_Symbol_hole_num
#endif
#ifndef LR_Symbols_src_info
#define LR_Symbols_src_info Lalr_LR_Symbols_src_info
#endif
#ifndef LR_Symbols_srcinfo
#define LR_Symbols_srcinfo Lalr_LR_Symbols_srcinfo
#endif
#ifndef LR_Symbols_loc
#define LR_Symbols_loc Lalr_LR_Symbols_loc
#endif
#ifndef LR_Symbols_memo_link
#define LR_Symbols_memo_link Lalr_LR_Symbols_memo_link
#endif
#ifndef LR_Symbols_data
#define LR_Symbols_data Lalr_LR_Symbols_data
#endif
#ifndef LR_Symbols_next
#define LR_Symbols_next Lalr_LR_Symbols_next
#endif
#ifndef LR_Symbols_num
#define LR_Symbols_num Lalr_LR_Symbols_num
#endif
#ifndef LR_state_src_info
#define LR_state_src_info Lalr_LR_state_src_info
#endif
#ifndef LR_state_srcinfo
#define LR_state_srcinfo Lalr_LR_state_srcinfo
#endif
#ifndef LR_state_loc
#define LR_state_loc Lalr_LR_state_loc
#endif
#ifndef LR_state_num
#define LR_state_num Lalr_LR_state_num
#endif
#ifndef LR_state_items
#define LR_state_items Lalr_LR_state_items
#endif
#ifndef LR_state_transitions
#define LR_state_transitions Lalr_LR_state_transitions
#endif
#ifndef LR_state_start_state
#define LR_state_start_state Lalr_LR_state_start_state
#endif
#ifndef Item_src_info
#define Item_src_info Lalr_Item_src_info
#endif
#ifndef Item_srcinfo
#define Item_srcinfo Lalr_Item_srcinfo
#endif
#ifndef Item_loc
#define Item_loc Lalr_Item_loc
#endif
#ifndef Item_lhs
#define Item_lhs Lalr_Item_lhs
#endif
#ifndef Item_rhs1
#define Item_rhs1 Lalr_Item_rhs1
#endif
#ifndef Item_rhs2
#define Item_rhs2 Lalr_Item_rhs2
#endif
#ifndef Item_followers
#define Item_followers Lalr_Item_followers
#endif
#ifndef Item_production
#define Item_production Lalr_Item_production
#endif
#ifndef Item_predecessors
#define Item_predecessors Lalr_Item_predecessors
#endif
#ifndef Item_start_item
#define Item_start_item Lalr_Item_start_item
#endif
#ifndef Item_conflict
#define Item_conflict Lalr_Item_conflict
#endif
#ifndef Transition_src_info
#define Transition_src_info Lalr_Transition_src_info
#endif
#ifndef Transition_srcinfo
#define Transition_srcinfo Lalr_Transition_srcinfo
#endif
#ifndef Transition_loc
#define Transition_loc Lalr_Transition_loc
#endif
#ifndef Transition_symbol
#define Transition_symbol Lalr_Transition_symbol
#endif
#ifndef Transition_num
#define Transition_num Lalr_Transition_num
#endif
#ifndef Transition_target
#define Transition_target Lalr_Transition_target
#endif
#ifndef Transition_conflict
#define Transition_conflict Lalr_Transition_conflict
#endif
#ifndef Scope_next
#define Scope_next Lalr_Scope_next
#endif
#ifndef Scope__self
#define Scope__self Lalr_Scope__self
#endif
#ifndef Scope__end
#define Scope__end Lalr_Scope__end
#endif
#ifndef List_LR_Symbols_data
#define List_LR_Symbols_data List_Lalr_LR_Symbols_data
#endif
#ifndef List_LR_Symbols_next
#define List_LR_Symbols_next List_Lalr_LR_Symbols_next
#endif
#ifndef List_LR_Symbol_data
#define List_LR_Symbol_data List_Lalr_LR_Symbol_data
#endif
#ifndef List_LR_Symbol_next
#define List_LR_Symbol_next List_Lalr_LR_Symbol_next
#endif
#ifndef List_Transition_data
#define List_Transition_data List_Lalr_Transition_data
#endif
#ifndef List_Transition_next
#define List_Transition_next List_Lalr_Transition_next
#endif
#ifndef List_Item_data
#define List_Item_data List_Lalr_Item_data
#endif
#ifndef List_Item_next
#define List_Item_next List_Lalr_Item_next
#endif
#ifndef List_Bind_Production_data
#define List_Bind_Production_data List_Bind_Lalr_Production_data
#endif
#ifndef List_Bind_Production_next
#define List_Bind_Production_next List_Bind_Lalr_Production_next
#endif
#ifndef List_Ident_data
#define List_Ident_data List_Ident_data
#endif
#ifndef List_Ident_next
#define List_Ident_next List_Ident_next
#endif
#ifndef List_LR_state_data
#define List_LR_state_data List_Lalr_LR_state_data
#endif
#ifndef List_LR_state_next
#define List_LR_state_next List_Lalr_LR_state_next
#endif
#ifndef List_Production_data
#define List_Production_data List_Lalr_Production_data
#endif
#ifndef List_Production_next
#define List_Production_next List_Lalr_Production_next
#endif

/* Abbreviations for Lalr.h */

#ifndef Create_Lalr
#define Create_Lalr Create_Lalr_Lalr
#endif
#ifndef Create_Production
#define Create_Production Create_Lalr_Production
#endif
#ifndef Create_LR_Symbol
#define Create_LR_Symbol Create_Lalr_LR_Symbol
#endif
#ifndef Create_LR_Symbols
#define Create_LR_Symbols Create_Lalr_LR_Symbols
#endif
#ifndef Create_LR_state
#define Create_LR_state Create_Lalr_LR_state
#endif
#ifndef Create_Item
#define Create_Item Create_Lalr_Item
#endif
#ifndef Create_Transition
#define Create_Transition Create_Lalr_Transition
#endif
#ifndef Create_Scope
#define Create_Scope Create_Lalr_Scope
#endif
#ifndef Create_List_LR_Symbols
#define Create_List_LR_Symbols Create_List_Lalr_LR_Symbols
#endif
#ifndef List_LR_Symbols_size
#define List_LR_Symbols_size List_Lalr_LR_Symbols_size
#endif
#ifndef Create_List_LR_Symbol
#define Create_List_LR_Symbol Create_List_Lalr_LR_Symbol
#endif
#ifndef List_LR_Symbol_size
#define List_LR_Symbol_size List_Lalr_LR_Symbol_size
#endif
#ifndef Create_List_Transition
#define Create_List_Transition Create_List_Lalr_Transition
#endif
#ifndef List_Transition_size
#define List_Transition_size List_Lalr_Transition_size
#endif
#ifndef Create_List_Item
#define Create_List_Item Create_List_Lalr_Item
#endif
#ifndef List_Item_size
#define List_Item_size List_Lalr_Item_size
#endif
#ifndef Create_List_LR_state
#define Create_List_LR_state Create_List_Lalr_LR_state
#endif
#ifndef List_LR_state_size
#define List_LR_state_size List_Lalr_LR_state_size
#endif
#ifndef Create_List_Production
#define Create_List_Production Create_List_Lalr_Production
#endif
#ifndef List_Production_size
#define List_Production_size List_Lalr_Production_size
#endif
#ifndef s_TraverseTable
#define s_TraverseTable s_Lalr_TraverseTable
#endif
#ifndef TraverseTable
#define TraverseTable Lalr_TraverseTable
#endif
#ifndef Traverse_Emptiness
#define Traverse_Emptiness Traverse_Lalr_Emptiness
#endif
#ifndef Traverse_Lalr
#define Traverse_Lalr Traverse_Lalr_Lalr
#endif
#ifndef Traverse_Production
#define Traverse_Production Traverse_Lalr_Production
#endif
#ifndef Traverse_LR_Symbol
#define Traverse_LR_Symbol Traverse_Lalr_LR_Symbol
#endif
#ifndef Traverse_LR_Symbols
#define Traverse_LR_Symbols Traverse_Lalr_LR_Symbols
#endif
#ifndef Traverse_LR_state
#define Traverse_LR_state Traverse_Lalr_LR_state
#endif
#ifndef Traverse_Item
#define Traverse_Item Traverse_Lalr_Item
#endif
#ifndef Traverse_Transition
#define Traverse_Transition Traverse_Lalr_Transition
#endif
#ifndef Traverse_Scope
#define Traverse_Scope Traverse_Lalr_Scope
#endif
#ifndef Traverse_List_LR_Symbols
#define Traverse_List_LR_Symbols Traverse_List_Lalr_LR_Symbols
#endif
#ifndef Traverse_List_LR_Symbol
#define Traverse_List_LR_Symbol Traverse_List_Lalr_LR_Symbol
#endif
#ifndef Traverse_List_Transition
#define Traverse_List_Transition Traverse_List_Lalr_Transition
#endif
#ifndef Traverse_List_Item
#define Traverse_List_Item Traverse_List_Lalr_Item
#endif
#ifndef Traverse_List_LR_state
#define Traverse_List_LR_state Traverse_List_Lalr_LR_state
#endif
#ifndef Traverse_List_Production
#define Traverse_List_Production Traverse_List_Lalr_Production
#endif
#ifndef s_void_TraverseTable
#define s_void_TraverseTable s_void_Lalr_TraverseTable
#endif
#ifndef void_TraverseTable
#define void_TraverseTable void_Lalr_TraverseTable
#endif
#ifndef Traverse_void_Emptiness
#define Traverse_void_Emptiness Traverse_void_Lalr_Emptiness
#endif
#ifndef Traverse_void_Lalr
#define Traverse_void_Lalr Traverse_void_Lalr_Lalr
#endif
#ifndef Traverse_void_Production
#define Traverse_void_Production Traverse_void_Lalr_Production
#endif
#ifndef Traverse_void_LR_Symbol
#define Traverse_void_LR_Symbol Traverse_void_Lalr_LR_Symbol
#endif
#ifndef Traverse_void_LR_Symbols
#define Traverse_void_LR_Symbols Traverse_void_Lalr_LR_Symbols
#endif
#ifndef Traverse_void_LR_state
#define Traverse_void_LR_state Traverse_void_Lalr_LR_state
#endif
#ifndef Traverse_void_Item
#define Traverse_void_Item Traverse_void_Lalr_Item
#endif
#ifndef Traverse_void_Transition
#define Traverse_void_Transition Traverse_void_Lalr_Transition
#endif
#ifndef Traverse_void_Scope
#define Traverse_void_Scope Traverse_void_Lalr_Scope
#endif
#ifndef Traverse_void_List_LR_Symbols
#define Traverse_void_List_LR_Symbols Traverse_void_List_Lalr_LR_Symbols
#endif
#ifndef Traverse_void_List_LR_Symbol
#define Traverse_void_List_LR_Symbol Traverse_void_List_Lalr_LR_Symbol
#endif
#ifndef Traverse_void_List_Transition
#define Traverse_void_List_Transition Traverse_void_List_Lalr_Transition
#endif
#ifndef Traverse_void_List_Item
#define Traverse_void_List_Item Traverse_void_List_Lalr_Item
#endif
#ifndef Traverse_void_List_LR_state
#define Traverse_void_List_LR_state Traverse_void_List_Lalr_LR_state
#endif
#ifndef Traverse_void_List_Production
#define Traverse_void_List_Production Traverse_void_List_Lalr_Production
#endif
#ifndef s_copy_TraverseTable
#define s_copy_TraverseTable s_copy_Lalr_TraverseTable
#endif
#ifndef copy_TraverseTable
#define copy_TraverseTable copy_Lalr_TraverseTable
#endif
#ifndef Traverse_copy_Emptiness
#define Traverse_copy_Emptiness Traverse_copy_Lalr_Emptiness
#endif
#ifndef COPY_Emptiness
#define COPY_Emptiness COPY_Lalr_Emptiness
#endif
#ifndef copy_actions
#define copy_actions Lalr_copy_actions
#endif
#ifndef Traverse_copy_Lalr
#define Traverse_copy_Lalr Traverse_copy_Lalr_Lalr
#endif
#ifndef COPY_Lalr
#define COPY_Lalr COPY_Lalr_Lalr
#endif
#ifndef Traverse_copy_Production
#define Traverse_copy_Production Traverse_copy_Lalr_Production
#endif
#ifndef COPY_Production
#define COPY_Production COPY_Lalr_Production
#endif
#ifndef Traverse_copy_LR_Symbol
#define Traverse_copy_LR_Symbol Traverse_copy_Lalr_LR_Symbol
#endif
#ifndef COPY_LR_Symbol
#define COPY_LR_Symbol COPY_Lalr_LR_Symbol
#endif
#ifndef Traverse_copy_LR_Symbols
#define Traverse_copy_LR_Symbols Traverse_copy_Lalr_LR_Symbols
#endif
#ifndef COPY_LR_Symbols
#define COPY_LR_Symbols COPY_Lalr_LR_Symbols
#endif
#ifndef Traverse_copy_LR_state
#define Traverse_copy_LR_state Traverse_copy_Lalr_LR_state
#endif
#ifndef COPY_LR_state
#define COPY_LR_state COPY_Lalr_LR_state
#endif
#ifndef Traverse_copy_Item
#define Traverse_copy_Item Traverse_copy_Lalr_Item
#endif
#ifndef COPY_Item
#define COPY_Item COPY_Lalr_Item
#endif
#ifndef Traverse_copy_Transition
#define Traverse_copy_Transition Traverse_copy_Lalr_Transition
#endif
#ifndef COPY_Transition
#define COPY_Transition COPY_Lalr_Transition
#endif
#ifndef Traverse_copy_Scope
#define Traverse_copy_Scope Traverse_copy_Lalr_Scope
#endif
#ifndef COPY_Scope
#define COPY_Scope COPY_Lalr_Scope
#endif
#ifndef Traverse_copy_List_LR_Symbols
#define Traverse_copy_List_LR_Symbols Traverse_copy_List_Lalr_LR_Symbols
#endif
#ifndef COPY_List_LR_Symbols
#define COPY_List_LR_Symbols COPY_Lalr_List_LR_Symbols
#endif
#ifndef Traverse_copy_List_LR_Symbol
#define Traverse_copy_List_LR_Symbol Traverse_copy_List_Lalr_LR_Symbol
#endif
#ifndef COPY_List_LR_Symbol
#define COPY_List_LR_Symbol COPY_Lalr_List_LR_Symbol
#endif
#ifndef Traverse_copy_List_Transition
#define Traverse_copy_List_Transition Traverse_copy_List_Lalr_Transition
#endif
#ifndef COPY_List_Transition
#define COPY_List_Transition COPY_Lalr_List_Transition
#endif
#ifndef Traverse_copy_List_Item
#define Traverse_copy_List_Item Traverse_copy_List_Lalr_Item
#endif
#ifndef COPY_List_Item
#define COPY_List_Item COPY_Lalr_List_Item
#endif
#ifndef Traverse_copy_List_LR_state
#define Traverse_copy_List_LR_state Traverse_copy_List_Lalr_LR_state
#endif
#ifndef COPY_List_LR_state
#define COPY_List_LR_state COPY_Lalr_List_LR_state
#endif
#ifndef Traverse_copy_List_Production
#define Traverse_copy_List_Production Traverse_copy_List_Lalr_Production
#endif
#ifndef COPY_List_Production
#define COPY_List_Production COPY_Lalr_List_Production
#endif
#ifndef s_compare_TraverseTable
#define s_compare_TraverseTable s_compare_Lalr_TraverseTable
#endif
#ifndef compare_TraverseTable
#define compare_TraverseTable compare_Lalr_TraverseTable
#endif
#ifndef Traverse_compare_Emptiness
#define Traverse_compare_Emptiness Traverse_compare_Lalr_Emptiness
#endif
#ifndef Traverse_compare_Lalr
#define Traverse_compare_Lalr Traverse_compare_Lalr_Lalr
#endif
#ifndef Traverse_compare_Production
#define Traverse_compare_Production Traverse_compare_Lalr_Production
#endif
#ifndef Traverse_compare_LR_Symbol
#define Traverse_compare_LR_Symbol Traverse_compare_Lalr_LR_Symbol
#endif
#ifndef Traverse_compare_LR_Symbols
#define Traverse_compare_LR_Symbols Traverse_compare_Lalr_LR_Symbols
#endif
#ifndef Traverse_compare_LR_state
#define Traverse_compare_LR_state Traverse_compare_Lalr_LR_state
#endif
#ifndef Traverse_compare_Item
#define Traverse_compare_Item Traverse_compare_Lalr_Item
#endif
#ifndef Traverse_compare_Transition
#define Traverse_compare_Transition Traverse_compare_Lalr_Transition
#endif
#ifndef Traverse_compare_Scope
#define Traverse_compare_Scope Traverse_compare_Lalr_Scope
#endif
#ifndef Traverse_compare_List_LR_Symbols
#define Traverse_compare_List_LR_Symbols Traverse_compare_List_Lalr_LR_Symbols
#endif
#ifndef Traverse_compare_List_LR_Symbol
#define Traverse_compare_List_LR_Symbol Traverse_compare_List_Lalr_LR_Symbol
#endif
#ifndef Traverse_compare_List_Transition
#define Traverse_compare_List_Transition Traverse_compare_List_Lalr_Transition
#endif
#ifndef Traverse_compare_List_Item
#define Traverse_compare_List_Item Traverse_compare_List_Lalr_Item
#endif
#ifndef Traverse_compare_List_LR_state
#define Traverse_compare_List_LR_state Traverse_compare_List_Lalr_LR_state
#endif
#ifndef Traverse_compare_List_Production
#define Traverse_compare_List_Production Traverse_compare_List_Lalr_Production
#endif
#ifndef fill_table
#define fill_table Lalr_fill_table
#endif
#ifndef void_fill_table
#define void_fill_table void_Lalr_fill_table
#endif
#ifndef copy_fill_table
#define copy_fill_table copy_Lalr_fill_table
#endif
#ifndef compare_fill_table
#define compare_fill_table compare_Lalr_fill_table
#endif
#ifndef scope_actions
#define scope_actions Lalr_scope_actions
#endif
#ifndef defining_actions
#define defining_actions Lalr_defining_actions
#endif
#ifndef applied_actions
#define applied_actions Lalr_applied_actions
#endif
#ifndef check_actions
#define check_actions Lalr_check_actions
#endif
#ifndef print_actions
#define print_actions Lalr_print_actions
#endif
#ifndef compare_actions
#define compare_actions Lalr_compare_actions
#endif
#ifndef NameSpaces
#define NameSpaces Lalr_NameSpaces
#endif
#ifndef namespaces
#define namespaces Lalr_namespaces
#endif
#ifndef DefaultNameSpace
#define DefaultNameSpace Lalr_DefaultNameSpace
#endif
#ifndef NUM_NAMESPACES
#define NUM_NAMESPACES Lalr_NUM_NAMESPACES
#endif
#ifndef Bind_Production_kind
#define Bind_Production_kind Bind_Lalr_Production_kind
#endif

/* Abbreviations for Lalr_parse.h */

#ifndef Parse_Lalr
#define Parse_Lalr Parse_Lalr_Lalr
#endif
#ifndef Parse_Production
#define Parse_Production Parse_Lalr_Production
#endif
#ifndef Parse_ProdRhs
#define Parse_ProdRhs Parse_Lalr_ProdRhs
#endif
#ifndef Parse_LR_Symbol
#define Parse_LR_Symbol Parse_Lalr_LR_Symbol
#endif
#ifndef Parse_LR_Symbols
#define Parse_LR_Symbols Parse_Lalr_LR_Symbols
#endif
#ifndef Parse_Emptiness
#define Parse_Emptiness Parse_Lalr_Emptiness
#endif
#ifndef Parse_LR_state
#define Parse_LR_state Parse_Lalr_LR_state
#endif
#ifndef Parse_Item
#define Parse_Item Parse_Lalr_Item
#endif
#ifndef Parse_TermSet
#define Parse_TermSet Parse_Lalr_TermSet
#endif
#ifndef Parse_Transition
#define Parse_Transition Parse_Lalr_Transition
#endif
#ifndef Parse_OPTMORE_Production
#define Parse_OPTMORE_Production Parse_Lalr_OPTMORE_Production
#endif
#ifndef Parse_OPTMORE_LR_state
#define Parse_OPTMORE_LR_state Parse_Lalr_OPTMORE_LR_state
#endif
#ifndef Parse_MORE_Item
#define Parse_MORE_Item Parse_Lalr_MORE_Item
#endif
#ifndef Parse_OPTMORE_Transition
#define Parse_OPTMORE_Transition Parse_Lalr_OPTMORE_Transition
#endif
#ifndef Parse_OPTMORE_LR_Symbol
#define Parse_OPTMORE_LR_Symbol Parse_Lalr_OPTMORE_LR_Symbol
#endif
#ifndef Parse_MORE_Identsym_spacesym
#define Parse_MORE_Identsym_spacesym Parse_Lalr_MORE_Identsym_spacesym
#endif
#ifndef Parse_state_Lalr
#define Parse_state_Lalr Parse_state_Lalr_Lalr
#endif
#ifndef parse_string
#define parse_string Lalr_parse_string
#endif
#ifndef Parse_state_Production
#define Parse_state_Production Parse_state_Lalr_Production
#endif
#ifndef Parse_state_ProdRhs
#define Parse_state_ProdRhs Parse_state_Lalr_ProdRhs
#endif
#ifndef Parse_state_LR_Symbol
#define Parse_state_LR_Symbol Parse_state_Lalr_LR_Symbol
#endif
#ifndef Parse_state_LR_Symbols
#define Parse_state_LR_Symbols Parse_state_Lalr_LR_Symbols
#endif
#ifndef Parse_state_Emptiness
#define Parse_state_Emptiness Parse_state_Lalr_Emptiness
#endif
#ifndef Parse_state_LR_state
#define Parse_state_LR_state Parse_state_Lalr_LR_state
#endif
#ifndef Parse_state_Item
#define Parse_state_Item Parse_state_Lalr_Item
#endif
#ifndef Parse_state_TermSet
#define Parse_state_TermSet Parse_state_Lalr_TermSet
#endif
#ifndef Parse_state_Transition
#define Parse_state_Transition Parse_state_Lalr_Transition
#endif
#ifndef Parse_state_OPTMORE_Production
#define Parse_state_OPTMORE_Production Parse_state_Lalr_OPTMORE_Production
#endif
#ifndef Parse_state_OPTMORE_LR_state
#define Parse_state_OPTMORE_LR_state Parse_state_Lalr_OPTMORE_LR_state
#endif
#ifndef Parse_state_MORE_Item
#define Parse_state_MORE_Item Parse_state_Lalr_MORE_Item
#endif
#ifndef Parse_state_OPTMORE_Transition
#define Parse_state_OPTMORE_Transition Parse_state_Lalr_OPTMORE_Transition
#endif
#ifndef Parse_state_OPTMORE_LR_Symbol
#define Parse_state_OPTMORE_LR_Symbol Parse_state_Lalr_OPTMORE_LR_Symbol
#endif
#ifndef Parse_state_MORE_Identsym_spacesym
#define Parse_state_MORE_Identsym_spacesym Parse_state_Lalr_MORE_Identsym_spacesym
#endif
#ifndef Print_Lalr
#define Print_Lalr Print_Lalr_Lalr
#endif
#ifndef PRINT_Lalr
#define PRINT_Lalr PRINT_Lalr_Lalr
#endif
#ifndef Text_Lalr
#define Text_Lalr Text_Lalr_Lalr
#endif
#ifndef Print_Production
#define Print_Production Print_Lalr_Production
#endif
#ifndef PRINT_Production
#define PRINT_Production PRINT_Lalr_Production
#endif
#ifndef Text_Production
#define Text_Production Text_Lalr_Production
#endif
#ifndef Print_LR_Symbol
#define Print_LR_Symbol Print_Lalr_LR_Symbol
#endif
#ifndef PRINT_LR_Symbol
#define PRINT_LR_Symbol PRINT_Lalr_LR_Symbol
#endif
#ifndef Text_LR_Symbol
#define Text_LR_Symbol Text_Lalr_LR_Symbol
#endif
#ifndef Print_LR_Symbols
#define Print_LR_Symbols Print_Lalr_LR_Symbols
#endif
#ifndef PRINT_LR_Symbols
#define PRINT_LR_Symbols PRINT_Lalr_LR_Symbols
#endif
#ifndef Text_LR_Symbols
#define Text_LR_Symbols Text_Lalr_LR_Symbols
#endif
#ifndef Print_LR_state
#define Print_LR_state Print_Lalr_LR_state
#endif
#ifndef PRINT_LR_state
#define PRINT_LR_state PRINT_Lalr_LR_state
#endif
#ifndef Text_LR_state
#define Text_LR_state Text_Lalr_LR_state
#endif
#ifndef Print_Item
#define Print_Item Print_Lalr_Item
#endif
#ifndef PRINT_Item
#define PRINT_Item PRINT_Lalr_Item
#endif
#ifndef Text_Item
#define Text_Item Text_Lalr_Item
#endif
#ifndef Print_Transition
#define Print_Transition Print_Lalr_Transition
#endif
#ifndef PRINT_Transition
#define PRINT_Transition PRINT_Lalr_Transition
#endif
#ifndef Text_Transition
#define Text_Transition Text_Lalr_Transition
#endif
#ifndef Print_Scope
#define Print_Scope Print_Lalr_Scope
#endif
#ifndef PRINT_Scope
#define PRINT_Scope PRINT_Lalr_Scope
#endif
#ifndef Text_Scope
#define Text_Scope Text_Lalr_Scope
#endif
#ifndef Print_List_LR_Symbols
#define Print_List_LR_Symbols Print_List_Lalr_LR_Symbols
#endif
#ifndef PRINT_List_LR_Symbols
#define PRINT_List_LR_Symbols PRINT_List_Lalr_LR_Symbols
#endif
#ifndef Text_List_LR_Symbols
#define Text_List_LR_Symbols Text_List_Lalr_LR_Symbols
#endif
#ifndef Print_List_LR_Symbol
#define Print_List_LR_Symbol Print_List_Lalr_LR_Symbol
#endif
#ifndef PRINT_List_LR_Symbol
#define PRINT_List_LR_Symbol PRINT_List_Lalr_LR_Symbol
#endif
#ifndef Text_List_LR_Symbol
#define Text_List_LR_Symbol Text_List_Lalr_LR_Symbol
#endif
#ifndef Print_List_Transition
#define Print_List_Transition Print_List_Lalr_Transition
#endif
#ifndef PRINT_List_Transition
#define PRINT_List_Transition PRINT_List_Lalr_Transition
#endif
#ifndef Text_List_Transition
#define Text_List_Transition Text_List_Lalr_Transition
#endif
#ifndef Print_List_Item
#define Print_List_Item Print_List_Lalr_Item
#endif
#ifndef PRINT_List_Item
#define PRINT_List_Item PRINT_List_Lalr_Item
#endif
#ifndef Text_List_Item
#define Text_List_Item Text_List_Lalr_Item
#endif
#ifndef Print_List_LR_state
#define Print_List_LR_state Print_List_Lalr_LR_state
#endif
#ifndef PRINT_List_LR_state
#define PRINT_List_LR_state PRINT_List_Lalr_LR_state
#endif
#ifndef Text_List_LR_state
#define Text_List_LR_state Text_List_Lalr_LR_state
#endif
#ifndef Print_List_Production
#define Print_List_Production Print_List_Lalr_Production
#endif
#ifndef PRINT_List_Production
#define PRINT_List_Production PRINT_List_Lalr_Production
#endif
#ifndef Text_List_Production
#define Text_List_Production Text_List_Lalr_Production
#endif
#ifndef Print_Emptiness
#define Print_Emptiness Print_Lalr_Emptiness
#endif
#ifndef PRINT_Emptiness
#define PRINT_Emptiness PRINT_Lalr_Emptiness
#endif
#ifndef Text_Emptiness
#define Text_Emptiness Text_Lalr_Emptiness
#endif
#endif /* Lalr_NO_DEFS */

