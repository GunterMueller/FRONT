#ifndef CREATE_LIST          
#define CREATE_LIST(t,a,b)   (Create_##t((a),(b)))
#endif                       
#ifndef LIST_HAS_LIST        
#define LIST_HAS_LIST(i,l)   ((l) != NULL)
#endif                       
#ifndef LIST_GET_LIST        
#define LIST_GET_LIST(i,l)   ((i)==0?Front_data((Front_List)(l)) : (i)==1 ? Front_next((Front_List)(l)) : NULL)
#endif                       
#ifndef LIST                 
#define LIST                 Front_List
#endif                       
#ifndef LIST_REPLACE         
#define LIST_REPLACE(a,b,i)  (*(a) = *(b))
#endif                       
#ifndef CONVERT_I_TO_Int     
#define CONVERT_I_TO_Int(i)  (i)
#endif                       
#ifndef CONVERT_Int_TO_I     
#define CONVERT_Int_TO_I(i)  (i)
#endif                       
#ifndef CONVERT_Bool_TO_B    
#define CONVERT_Bool_TO_B(i) (i)
#endif                       
#ifndef CONVERT_B_TO_Bool    
#define CONVERT_B_TO_Bool(i) (i)
#endif                       
#ifndef IS_NULL              
#define IS_NULL(i)           ((i) == NULL)
#endif                       
#ifndef COPY_Ident           
#define COPY_Ident(x)        (x)
#endif                       
#ifndef COPY_Int             
#define COPY_Int(x)          (x)
#endif                       
#ifndef COPY_Bool            
#define COPY_Bool(x)         (x)
#endif                       
#ifndef COPY_Char            
#define COPY_Char(x)         (x)
#endif                       
#ifndef COPY_String          
#define COPY_String(x)       (x)
#endif                       
#ifndef COPY_Float           
#define COPY_Float(x)        (x)
#endif                       
#ifndef COPY_I               
#define COPY_I(x)            (x)
#endif                       
#ifndef COPY_B               
#define COPY_B(x)            (x)
#endif                       
#ifndef Lalr_Lalr_OPERATOR
#define Lalr_Lalr_OPERATOR(a) ((a)==NULL?(unsigned)~0:Lalr_Lalr_kind)
#endif
#ifndef Lalr_Lalr_HAS_OPER
#define Lalr_Lalr_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Lalr_Lalr_REPLACE 
#define Lalr_Lalr_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Lalr_Lalr
#define COPY_Lalr_Lalr(x) Traverse_copy_Lalr_Lalr(x, &Lalr_copy_actions)
#endif

#ifndef NEW_Lalr_Lalr
#define NEW_Lalr_Lalr(src_info, grammar, states, yyy) Create_Lalr_Lalr(NO_SRCINFO, grammar, states)
#endif

#define Lalr_Lalr_GET_List_Lalr_Production(i,me)	(i == 0 ? Lalr_Lalr_grammar(me) : 0)
#define Lalr_Lalr_GET_List_Lalr_LR_state(i,me)	(i == 1 ? Lalr_Lalr_states(me) : 0)

#ifndef Lalr_Production_OPERATOR
#define Lalr_Production_OPERATOR(a) ((a)==NULL?(unsigned)~0:Lalr_Production_kind)
#endif
#ifndef Lalr_Production_HAS_OPER
#define Lalr_Production_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Lalr_Production_REPLACE 
#define Lalr_Production_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Lalr_Production
#define COPY_Lalr_Production(x) Traverse_copy_Lalr_Production(x, &Lalr_copy_actions)
#endif

#ifndef NEW_Lalr_Production
#define NEW_Lalr_Production(src_info, lhs, rhs, empty, first, yyy) Create_Lalr_Production(NO_SRCINFO, lhs, rhs, empty, first)
#endif

#define Lalr_Production_GET_Ident(i,me)	(i == 0 ? Lalr_Production_lhs(me) : 0)
#define Lalr_Production_GET_Lalr_LR_Symbols(i,me)	(i == 1 ? Lalr_Production_rhs(me) : 0)
#define Lalr_Production_GET_Lalr_Emptiness(i,me)	(i == 2 ? Lalr_Production_empty(me) : 0)
#define Lalr_Production_GET_List_Ident(i,me)	(i == 3 ? Lalr_Production_first(me) : 0)

#ifndef Lalr_LR_Symbol_OPERATOR
#define Lalr_LR_Symbol_OPERATOR(a) ((a)==NULL?(unsigned)~0:Lalr_LR_Symbol_kind)
#endif
#ifndef Lalr_LR_Symbol_HAS_OPER
#define Lalr_LR_Symbol_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Lalr_LR_Symbol_REPLACE 
#define Lalr_LR_Symbol_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Lalr_LR_Symbol
#define COPY_Lalr_LR_Symbol(x) Traverse_copy_Lalr_LR_Symbol(x, &Lalr_copy_actions)
#endif

#ifndef NEW_Lalr_LR_Symbol
#define NEW_Lalr_LR_Symbol(src_info, id, make_empty, yyy) Create_Lalr_LR_Symbol(NO_SRCINFO, id, make_empty)
#endif

#define Lalr_LR_Symbol_GET_Ident(i,me)	(i == 0 ? Lalr_LR_Symbol_id(me) : 0)
#define Lalr_LR_Symbol_GET_Bool(i,me)	(i == 1 ? Lalr_LR_Symbol_make_empty(me) : 0)

#ifndef Lalr_LR_Symbols_OPERATOR
#define Lalr_LR_Symbols_OPERATOR(a) ((a)==NULL?(unsigned)~0:Lalr_LR_Symbols_kind)
#endif
#ifndef Lalr_LR_Symbols_HAS_OPER
#define Lalr_LR_Symbols_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Lalr_LR_Symbols_REPLACE 
#define Lalr_LR_Symbols_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Lalr_LR_Symbols
#define COPY_Lalr_LR_Symbols(x) Traverse_copy_Lalr_LR_Symbols(x, &Lalr_copy_actions)
#endif

#ifndef NEW_Lalr_LR_Symbols
#define NEW_Lalr_LR_Symbols(src_info, data, next, yyy) Create_Lalr_LR_Symbols(NO_SRCINFO, data, next)
#endif

#define Lalr_LR_Symbols_GET_Lalr_LR_Symbol(i,me)	(i == 0 ? Lalr_LR_Symbols_data(me) : 0)
#define Lalr_LR_Symbols_GET_Lalr_LR_Symbols(i,me)	(i == 1 ? Lalr_LR_Symbols_next(me) : 0)

#ifndef Lalr_LR_state_OPERATOR
#define Lalr_LR_state_OPERATOR(a) ((a)==NULL?(unsigned)~0:Lalr_LR_state_kind)
#endif
#ifndef Lalr_LR_state_HAS_OPER
#define Lalr_LR_state_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Lalr_LR_state_REPLACE 
#define Lalr_LR_state_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Lalr_LR_state
#define COPY_Lalr_LR_state(x) Traverse_copy_Lalr_LR_state(x, &Lalr_copy_actions)
#endif

#ifndef NEW_Lalr_LR_state
#define NEW_Lalr_LR_state(src_info, num, items, transitions, yyy) Create_Lalr_LR_state(NO_SRCINFO, num, items, transitions)
#endif

#define Lalr_LR_state_GET_Int(i,me)	(i == 0 ? Lalr_LR_state_num(me) : 0)
#define Lalr_LR_state_GET_List_Lalr_Item(i,me)	(i == 1 ? Lalr_LR_state_items(me) : 0)
#define Lalr_LR_state_GET_List_Lalr_Transition(i,me)	(i == 2 ? Lalr_LR_state_transitions(me) : 0)

#ifndef Lalr_Item_OPERATOR
#define Lalr_Item_OPERATOR(a) ((a)==NULL?(unsigned)~0:Lalr_Item_kind)
#endif
#ifndef Lalr_Item_HAS_OPER
#define Lalr_Item_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Lalr_Item_REPLACE 
#define Lalr_Item_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Lalr_Item
#define COPY_Lalr_Item(x) Traverse_copy_Lalr_Item(x, &Lalr_copy_actions)
#endif

#ifndef NEW_Lalr_Item
#define NEW_Lalr_Item(src_info, lhs, rhs1, rhs2, followers, yyy) Create_Lalr_Item(NO_SRCINFO, lhs, rhs1, rhs2, followers)
#endif

#define Lalr_Item_GET_Ident(i,me)	(i == 0 ? Lalr_Item_lhs(me) : 0)
#define Lalr_Item_GET_List_Lalr_LR_Symbol(i,me)	(i == 1 ? Lalr_Item_rhs1(me) : 0)
#define Lalr_Item_GET_Lalr_LR_Symbols(i,me)	(i == 2 ? Lalr_Item_rhs2(me) : 0)
#define Lalr_Item_GET_List_Ident(i,me)	(i == 3 ? Lalr_Item_followers(me) : 0)

#ifndef Lalr_Transition_OPERATOR
#define Lalr_Transition_OPERATOR(a) ((a)==NULL?(unsigned)~0:Lalr_Transition_kind)
#endif
#ifndef Lalr_Transition_HAS_OPER
#define Lalr_Transition_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Lalr_Transition_REPLACE 
#define Lalr_Transition_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Lalr_Transition
#define COPY_Lalr_Transition(x) Traverse_copy_Lalr_Transition(x, &Lalr_copy_actions)
#endif

#ifndef NEW_Lalr_Transition
#define NEW_Lalr_Transition(src_info, symbol, num, yyy) Create_Lalr_Transition(NO_SRCINFO, symbol, num)
#endif

#define Lalr_Transition_GET_Lalr_LR_Symbol(i,me)	(i == 0 ? Lalr_Transition_symbol(me) : 0)
#define Lalr_Transition_GET_Int(i,me)	(i == 1 ? Lalr_Transition_num(me) : 0)

#ifndef Lalr_Scope_OPERATOR
#define Lalr_Scope_OPERATOR(a) ((a)==NULL?(unsigned)~0:Lalr_Scope_kind)
#endif
#ifndef Lalr_Scope_HAS_OPER
#define Lalr_Scope_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Lalr_Scope_REPLACE 
#define Lalr_Scope_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Lalr_Scope
#define COPY_Lalr_Scope(x) Traverse_copy_Lalr_Scope(x, &Lalr_copy_actions)
#endif

#ifndef NEW_Lalr_Scope
#define NEW_Lalr_Scope(next, yyy) Create_Lalr_Scope(NO_SRCINFO)
#endif


#ifndef List_Lalr_LR_Symbols_OPERATOR
#define List_Lalr_LR_Symbols_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Lalr_LR_Symbols_kind)
#endif
#ifndef List_Lalr_LR_Symbols_HAS_OPER
#define List_Lalr_LR_Symbols_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Lalr_LR_Symbols_REPLACE 
#define List_Lalr_LR_Symbols_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Lalr_LR_Symbols
#define COPY_List_Lalr_LR_Symbols(x) Traverse_copy_List_Lalr_LR_Symbols(x, &Lalr_copy_actions)
#endif

#ifndef NEW_List_Lalr_LR_Symbols
#define NEW_List_Lalr_LR_Symbols(xxx, data, next, yyy) Create_List_Lalr_LR_Symbols(data, next)
#endif

#define List_Lalr_LR_Symbols_GET_Lalr_LR_Symbols(i,me)	(i == 0 ? List_Lalr_LR_Symbols_data(me) : 0)
#define List_Lalr_LR_Symbols_GET_List_Lalr_LR_Symbols(i,me)	(i == 1 ? List_Lalr_LR_Symbols_next(me) : 0)

#ifndef List_Lalr_LR_Symbol_OPERATOR
#define List_Lalr_LR_Symbol_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Lalr_LR_Symbol_kind)
#endif
#ifndef List_Lalr_LR_Symbol_HAS_OPER
#define List_Lalr_LR_Symbol_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Lalr_LR_Symbol_REPLACE 
#define List_Lalr_LR_Symbol_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Lalr_LR_Symbol
#define COPY_List_Lalr_LR_Symbol(x) Traverse_copy_List_Lalr_LR_Symbol(x, &Lalr_copy_actions)
#endif

#ifndef NEW_List_Lalr_LR_Symbol
#define NEW_List_Lalr_LR_Symbol(xxx, data, next, yyy) Create_List_Lalr_LR_Symbol(data, next)
#endif

#define List_Lalr_LR_Symbol_GET_Lalr_LR_Symbol(i,me)	(i == 0 ? List_Lalr_LR_Symbol_data(me) : 0)
#define List_Lalr_LR_Symbol_GET_List_Lalr_LR_Symbol(i,me)	(i == 1 ? List_Lalr_LR_Symbol_next(me) : 0)

#ifndef List_Lalr_Transition_OPERATOR
#define List_Lalr_Transition_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Lalr_Transition_kind)
#endif
#ifndef List_Lalr_Transition_HAS_OPER
#define List_Lalr_Transition_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Lalr_Transition_REPLACE 
#define List_Lalr_Transition_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Lalr_Transition
#define COPY_List_Lalr_Transition(x) Traverse_copy_List_Lalr_Transition(x, &Lalr_copy_actions)
#endif

#ifndef NEW_List_Lalr_Transition
#define NEW_List_Lalr_Transition(xxx, data, next, yyy) Create_List_Lalr_Transition(data, next)
#endif

#define List_Lalr_Transition_GET_Lalr_Transition(i,me)	(i == 0 ? List_Lalr_Transition_data(me) : 0)
#define List_Lalr_Transition_GET_List_Lalr_Transition(i,me)	(i == 1 ? List_Lalr_Transition_next(me) : 0)

#ifndef List_Lalr_Item_OPERATOR
#define List_Lalr_Item_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Lalr_Item_kind)
#endif
#ifndef List_Lalr_Item_HAS_OPER
#define List_Lalr_Item_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Lalr_Item_REPLACE 
#define List_Lalr_Item_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Lalr_Item
#define COPY_List_Lalr_Item(x) Traverse_copy_List_Lalr_Item(x, &Lalr_copy_actions)
#endif

#ifndef NEW_List_Lalr_Item
#define NEW_List_Lalr_Item(xxx, data, next, yyy) Create_List_Lalr_Item(data, next)
#endif

#define List_Lalr_Item_GET_Lalr_Item(i,me)	(i == 0 ? List_Lalr_Item_data(me) : 0)
#define List_Lalr_Item_GET_List_Lalr_Item(i,me)	(i == 1 ? List_Lalr_Item_next(me) : 0)

#ifndef List_Bind_Lalr_Production_OPERATOR
#define List_Bind_Lalr_Production_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Bind_Lalr_Production_kind)
#endif
#ifndef List_Bind_Lalr_Production_HAS_OPER
#define List_Bind_Lalr_Production_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Bind_Lalr_Production_REPLACE 
#define List_Bind_Lalr_Production_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Bind_Lalr_Production
#define COPY_List_Bind_Lalr_Production(x) Traverse_copy_List_Bind_Lalr_Production(x, &Lalr_copy_actions)
#endif

#ifndef List_Ident_OPERATOR
#define List_Ident_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Ident_kind)
#endif
#ifndef List_Ident_HAS_OPER
#define List_Ident_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Ident_REPLACE 
#define List_Ident_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Ident
#define COPY_List_Ident(x) Traverse_copy_List_Ident(x, &Lalr_copy_actions)
#endif

#ifndef List_Lalr_LR_state_OPERATOR
#define List_Lalr_LR_state_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Lalr_LR_state_kind)
#endif
#ifndef List_Lalr_LR_state_HAS_OPER
#define List_Lalr_LR_state_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Lalr_LR_state_REPLACE 
#define List_Lalr_LR_state_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Lalr_LR_state
#define COPY_List_Lalr_LR_state(x) Traverse_copy_List_Lalr_LR_state(x, &Lalr_copy_actions)
#endif

#ifndef NEW_List_Lalr_LR_state
#define NEW_List_Lalr_LR_state(xxx, data, next, yyy) Create_List_Lalr_LR_state(data, next)
#endif

#define List_Lalr_LR_state_GET_Lalr_LR_state(i,me)	(i == 0 ? List_Lalr_LR_state_data(me) : 0)
#define List_Lalr_LR_state_GET_List_Lalr_LR_state(i,me)	(i == 1 ? List_Lalr_LR_state_next(me) : 0)

#ifndef List_Lalr_Production_OPERATOR
#define List_Lalr_Production_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Lalr_Production_kind)
#endif
#ifndef List_Lalr_Production_HAS_OPER
#define List_Lalr_Production_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Lalr_Production_REPLACE 
#define List_Lalr_Production_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Lalr_Production
#define COPY_List_Lalr_Production(x) Traverse_copy_List_Lalr_Production(x, &Lalr_copy_actions)
#endif

#ifndef NEW_List_Lalr_Production
#define NEW_List_Lalr_Production(xxx, data, next, yyy) Create_List_Lalr_Production(data, next)
#endif

#define List_Lalr_Production_GET_Lalr_Production(i,me)	(i == 0 ? List_Lalr_Production_data(me) : 0)
#define List_Lalr_Production_GET_List_Lalr_Production(i,me)	(i == 1 ? List_Lalr_Production_next(me) : 0)

#ifndef Lalr_Emptiness_OPERATOR
#define Lalr_Emptiness_OPERATOR(a) (a)
#endif
#ifndef Lalr_Emptiness_HAS_OPER
#define Lalr_Emptiness_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Lalr_Emptiness_REPLACE 
#define Lalr_Emptiness_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Lalr_Emptiness
#define COPY_Lalr_Emptiness(x) (x)
#endif

#ifndef Bind_Lalr_Production_OPERATOR
#define Bind_Lalr_Production_OPERATOR(a) (a)
#endif
#ifndef Bind_Lalr_Production_HAS_OPER
#define Bind_Lalr_Production_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Bind_Lalr_Production_REPLACE 
#define Bind_Lalr_Production_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Bind_Lalr_Production
#define COPY_Bind_Lalr_Production(x) (x)
#endif

