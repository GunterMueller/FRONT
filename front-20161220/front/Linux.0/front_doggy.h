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
#ifndef front_front_OPERATOR
#define front_front_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_front_kind)
#endif
#ifndef front_front_HAS_OPER
#define front_front_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_front_REPLACE 
#define front_front_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_front
#define COPY_front_front(x) Traverse_copy_front_front(x, &front_copy_actions)
#endif

#ifndef NEW_front_front
#define NEW_front_front(src_info, uses, namespaces, imports, rules, yyy) Create_front_front(NO_SRCINFO, uses, namespaces, imports, rules)
#endif

#define front_front_GET_List_Ident(i,me)	(i == 0 ? front_front_uses(me) : 0)
#define front_front_GET_List_front_NameSpace(i,me)	(i == 1 ? front_front_namespaces(me) : 0)
#define front_front_GET_List_front_Import(i,me)	(i == 2 ? front_front_imports(me) : 0)
#define front_front_GET_List_front_NonTerminal(i,me)	(i == 3 ? front_front_rules(me) : 0)

#ifndef front_Import_OPERATOR
#define front_Import_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Import_kind)
#endif
#ifndef front_Import_HAS_OPER
#define front_Import_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_Import_REPLACE 
#define front_Import_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Import
#define COPY_front_Import(x) Traverse_copy_front_Import(x, &front_copy_actions)
#endif

#ifndef NEW_front_Import
#define NEW_front_Import(src_info, grammar, nts, yyy) Create_front_Import(NO_SRCINFO, grammar, nts)
#endif

#define front_Import_GET_Ident(i,me)	(i == 0 ? front_Import_grammar(me) : 0)
#define front_Import_GET_List_front_ImportedNonTerminal(i,me)	(i == 1 ? front_Import_nts(me) : 0)

#ifndef front_ImportedNonTerminal_OPERATOR
#define front_ImportedNonTerminal_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_ImportedNonTerminal_kind)
#endif
#ifndef front_ImportedNonTerminal_HAS_OPER
#define front_ImportedNonTerminal_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_ImportedNonTerminal_REPLACE 
#define front_ImportedNonTerminal_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_ImportedNonTerminal
#define COPY_front_ImportedNonTerminal(x) Traverse_copy_front_ImportedNonTerminal(x, &front_copy_actions)
#endif

#ifndef NEW_front_ImportedNonTerminal
#define NEW_front_ImportedNonTerminal(src_info, id, type, yyy) Create_front_ImportedNonTerminal(NO_SRCINFO, id, type)
#endif

#define front_ImportedNonTerminal_GET_Ident(i,me)	(i == 0 ? front_ImportedNonTerminal_id(me) : i == 1 ? front_ImportedNonTerminal_type(me) : 0)

#ifndef front_NonTerminal_OPERATOR
#define front_NonTerminal_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_NonTerminal_kind)
#endif
#ifndef front_NonTerminal_HAS_OPER
#define front_NonTerminal_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_NonTerminal_REPLACE 
#define front_NonTerminal_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_NonTerminal
#define COPY_front_NonTerminal(x) Traverse_copy_front_NonTerminal(x, &front_copy_actions)
#endif

#ifndef NEW_front_NonTerminal
#define NEW_front_NonTerminal(src_info, is_root, scan, id, super, meemo, enumerate, skip, alias, rhs, yyy) Create_front_NonTerminal(NO_SRCINFO, is_root, scan, id, super, meemo, enumerate, skip, alias, rhs)
#endif

#define front_NonTerminal_GET_Bool(i,me)	(i == 0 ? front_NonTerminal_is_root(me) : i == 4 ? front_NonTerminal_meemo(me) : i == 5 ? front_NonTerminal_enumerate(me) : i == 6 ? front_NonTerminal_skip(me) : 0)
#define front_NonTerminal_GET_front_ScanInfo(i,me)	(i == 1 ? front_NonTerminal_scan(me) : 0)
#define front_NonTerminal_GET_Ident(i,me)	(i == 2 ? front_NonTerminal_id(me) : 0)
#define front_NonTerminal_GET_front_Super(i,me)	(i == 3 ? front_NonTerminal_super(me) : 0)
#define front_NonTerminal_GET_front_Defines(i,me)	(i == 7 ? front_NonTerminal_alias(me) : 0)
#define front_NonTerminal_GET_front_Rhs(i,me)	(i == 8 ? front_NonTerminal_rhs(me) : 0)

#ifndef front_Super_OPERATOR
#define front_Super_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Super_tag(a))
#endif
#ifndef front_Super_HAS_OPER
#define front_Super_HAS_OPER(a,op) ((a) != NULL && front_Super_tag(a) == op)
#endif
#ifndef front_Super_REPLACE 
#define front_Super_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Super
#define COPY_front_Super(x) Traverse_copy_front_Super(x, &front_copy_actions)
#endif

#ifndef NEW_front_NoType
#define NEW_front_NoType(src_info, id, yyy) Create_front_NoType(NO_SRCINFO, id)
#endif

#define front_NoType_GET_Ident(i,me)	(i == 0 ? front_Super_id(me) : 0)

#ifndef NEW_front_SubType
#define NEW_front_SubType(src_info, x, id, yyy) Create_front_SubType(NO_SRCINFO, x, id)
#endif

#define front_SubType_GET_Ident(i,me)	(i == 0 ? front_SubType_x(me) : i == 1 ? front_Super_id(me) : 0)

#ifndef front_Rhs_OPERATOR
#define front_Rhs_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Rhs_kind)
#endif
#ifndef front_Rhs_HAS_OPER
#define front_Rhs_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_Rhs_REPLACE 
#define front_Rhs_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Rhs
#define COPY_front_Rhs(x) Traverse_copy_front_Rhs(x, &front_copy_actions)
#endif

#ifndef NEW_front_Rhs
#define NEW_front_Rhs(src_info, sc, syms1, x, alts, ops, y, syms2, checklist, yyy) Create_front_Rhs(NO_SRCINFO, sc, syms1, x, alts, ops, y, syms2, checklist)
#endif

#define front_Rhs_GET_List_front_Scoping(i,me)	(i == 0 ? front_Rhs_sc(me) : 0)
#define front_Rhs_GET_front_Symbol(i,me)	(i == 1 ? front_Rhs_syms1(me) : i == 6 ? front_Rhs_syms2(me) : 0)
#define front_Rhs_GET_Ident(i,me)	(i == 2 ? front_Rhs_x(me) : i == 5 ? front_Rhs_y(me) : 0)
#define front_Rhs_GET_List_front_Alternative(i,me)	(i == 3 ? front_Rhs_alts(me) : 0)
#define front_Rhs_GET_List_front_Or(i,me)	(i == 4 ? front_Rhs_ops(me) : 0)
#define front_Rhs_GET_List_front_Check(i,me)	(i == 7 ? front_Rhs_checklist(me) : 0)

#ifndef front_Alternative_OPERATOR
#define front_Alternative_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Alternative_tag(a))
#endif
#ifndef front_Alternative_HAS_OPER
#define front_Alternative_HAS_OPER(a,op) ((a) != NULL && front_Alternative_tag(a) == op)
#endif
#ifndef front_Alternative_REPLACE 
#define front_Alternative_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Alternative
#define COPY_front_Alternative(x) Traverse_copy_front_Alternative(x, &front_copy_actions)
#endif

#ifndef NEW_front_UnLabeledAlt
#define NEW_front_UnLabeledAlt(src_info, syms, yyy) Create_front_UnLabeledAlt(NO_SRCINFO, syms)
#endif

#define front_UnLabeledAlt_GET_front_Symbol(i,me)	(i == 0 ? front_UnLabeledAlt_syms(me) : 0)

#ifndef NEW_front_LabeledAlt
#define NEW_front_LabeledAlt(src_info, id, meemo, skip, def, rhs, yyy) Create_front_LabeledAlt(NO_SRCINFO, id, meemo, skip, def, rhs)
#endif

#define front_LabeledAlt_GET_Ident(i,me)	(i == 0 ? front_LabeledAlt_id(me) : i == 3 ? front_LabeledAlt_def(me) : 0)
#define front_LabeledAlt_GET_Bool(i,me)	(i == 1 ? front_LabeledAlt_meemo(me) : i == 2 ? front_LabeledAlt_skip(me) : 0)
#define front_LabeledAlt_GET_front_Rhs(i,me)	(i == 4 ? front_LabeledAlt_rhs(me) : 0)

#ifndef front_Symbol_OPERATOR
#define front_Symbol_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Symbol_tag(a))
#endif
#ifndef front_Symbol_HAS_OPER
#define front_Symbol_HAS_OPER(a,op) ((a) != NULL && front_Symbol_tag(a) == op)
#endif
#ifndef front_Symbol_REPLACE 
#define front_Symbol_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Symbol
#define COPY_front_Symbol(x) Traverse_copy_front_Symbol(x, &front_copy_actions)
#endif

#ifndef NEW_front_DefiningSym
#define NEW_front_DefiningSym(src_info, forward, def, id, ns_id, sc, yyy) Create_front_DefiningSym(NO_SRCINFO, forward, def, id, ns_id, sc)
#endif

#define front_DefiningSym_GET_Bool(i,me)	(i == 0 ? front_DefiningSym_forward(me) : 0)
#define front_DefiningSym_GET_front_Define(i,me)	(i == 1 ? front_DefiningSym_def(me) : 0)
#define front_DefiningSym_GET_front_Defining_id(i,me)	(i == 2 ? front_DefiningSym_id(me) : 0)
#define front_DefiningSym_GET_Ident(i,me)	(i == 3 ? front_DefiningSym_ns_id(me) : 0)
#define front_DefiningSym_GET_front_Expr(i,me)	(i == 4 ? front_DefiningSym_sc(me) : 0)

#ifndef NEW_front_IdSym
#define NEW_front_IdSym(src_info, id, type, yyy) Create_front_IdSym(NO_SRCINFO, id, type)
#endif

#define front_IdSym_GET_Ident(i,me)	(i == 0 ? front_IdSym_id(me) : 0)
#define front_IdSym_GET_front_Type(i,me)	(i == 1 ? front_IdSym_type(me) : 0)

#ifndef NEW_front_LayoutAction
#define NEW_front_LayoutAction(src_info, layout, yyy) Create_front_LayoutAction(NO_SRCINFO, layout)
#endif

#define front_LayoutAction_GET_front_Expr(i,me)	(i == 0 ? front_LayoutAction_layout(me) : 0)

#ifndef NEW_front_LayoutString
#define NEW_front_LayoutString(src_info, layout, yyy) Create_front_LayoutString(NO_SRCINFO, layout)
#endif

#define front_LayoutString_GET_String(i,me)	(i == 0 ? front_LayoutString_layout(me) : 0)

#ifndef NEW_front_EmptySym
#define NEW_front_EmptySym(src_info, yyy) Create_front_EmptySym(NO_SRCINFO)
#endif


#ifndef NEW_front_MoreSymbol
#define NEW_front_MoreSymbol(src_info, sym, ops, more, yyy) Create_front_MoreSymbol(NO_SRCINFO, sym, ops, more)
#endif

#define front_MoreSymbol_GET_List_front_Symbol(i,me)	(i == 0 ? front_CompoundSym_sym(me) : 0)
#define front_MoreSymbol_GET_List_front_Or(i,me)	(i == 1 ? front_CompoundSym_ops(me) : 0)
#define front_MoreSymbol_GET_Ident(i,me)	(i == 2 ? front_MoreSymbol_more(me) : 0)

#ifndef NEW_front_OptMoreSymbol
#define NEW_front_OptMoreSymbol(src_info, sym, ops, yyy) Create_front_OptMoreSymbol(NO_SRCINFO, sym, ops)
#endif

#define front_OptMoreSymbol_GET_List_front_Symbol(i,me)	(i == 0 ? front_CompoundSym_sym(me) : 0)
#define front_OptMoreSymbol_GET_List_front_Or(i,me)	(i == 1 ? front_CompoundSym_ops(me) : 0)

#ifndef NEW_front_OptSymbol
#define NEW_front_OptSymbol(src_info, sym, ops, in_line, yyy) Create_front_OptSymbol(NO_SRCINFO, sym, ops, in_line)
#endif

#define front_OptSymbol_GET_List_front_Symbol(i,me)	(i == 0 ? front_CompoundSym_sym(me) : 0)
#define front_OptSymbol_GET_List_front_Or(i,me)	(i == 1 ? front_CompoundSym_ops(me) : 0)
#define front_OptSymbol_GET_Bool(i,me)	(i == 2 ? front_OptSymbol_in_line(me) : 0)

#ifndef NEW_front_OnceSymbol
#define NEW_front_OnceSymbol(src_info, sym, ops, yyy) Create_front_OnceSymbol(NO_SRCINFO, sym, ops)
#endif

#define front_OnceSymbol_GET_List_front_Symbol(i,me)	(i == 0 ? front_CompoundSym_sym(me) : 0)
#define front_OnceSymbol_GET_List_front_Or(i,me)	(i == 1 ? front_CompoundSym_ops(me) : 0)

#ifndef NEW_front_KeywordSymbol
#define NEW_front_KeywordSymbol(src_info, keyword, type, yyy) Create_front_KeywordSymbol(NO_SRCINFO, keyword, type)
#endif

#define front_KeywordSymbol_GET_String(i,me)	(i == 0 ? front_KeywordSymbol_keyword(me) : 0)
#define front_KeywordSymbol_GET_front_Type(i,me)	(i == 1 ? front_KeywordSymbol_type(me) : 0)

#ifndef NEW_front_CharSymbol
#define NEW_front_CharSymbol(src_info, chr, type, yyy) Create_front_CharSymbol(NO_SRCINFO, chr, type)
#endif

#define front_CharSymbol_GET_String(i,me)	(i == 0 ? front_CharSymbol_chr(me) : 0)
#define front_CharSymbol_GET_front_Type(i,me)	(i == 1 ? front_CharSymbol_type(me) : 0)

#ifndef NEW_front_StringSymbol
#define NEW_front_StringSymbol(src_info, string, n, type, yyy) Create_front_StringSymbol(NO_SRCINFO, string, n, type)
#endif

#define front_StringSymbol_GET_String(i,me)	(i == 0 ? front_StringSymbol_string(me) : 0)
#define front_StringSymbol_GET_Ident(i,me)	(i == 1 ? front_StringSymbol_n(me) : 0)
#define front_StringSymbol_GET_front_Type(i,me)	(i == 2 ? front_StringSymbol_type(me) : 0)

#ifndef NEW_front_AppliedSym
#define NEW_front_AppliedSym(src_info, nt_id, field, name, sc, warn, yyy) Create_front_AppliedSym(NO_SRCINFO, nt_id, field, name, sc, warn)
#endif

#define front_AppliedSym_GET_Ident(i,me)	(i == 0 ? front_AppliedSym_nt_id(me) : i == 2 ? front_AppliedSym_name(me) : 0)
#define front_AppliedSym_GET_front_NameOrField(i,me)	(i == 1 ? front_AppliedSym_field(me) : 0)
#define front_AppliedSym_GET_front_Expr(i,me)	(i == 3 ? front_AppliedSym_sc(me) : 0)
#define front_AppliedSym_GET_Bool(i,me)	(i == 4 ? front_AppliedSym_warn(me) : 0)

#ifndef NEW_front_CompareSym
#define NEW_front_CompareSym(src_info, sym, comp, yyy) Create_front_CompareSym(NO_SRCINFO, sym, comp)
#endif

#define front_CompareSym_GET_front_Symbol(i,me)	(i == 0 ? front_Symbol2_sym(me) : 0)
#define front_CompareSym_GET_Ident(i,me)	(i == 1 ? front_Symbol2_comp(me) : 0)

#ifndef NEW_front_SymbolSeq
#define NEW_front_SymbolSeq(src_info, symbols, my_fields, ands, yyy) Create_front_SymbolSeq(NO_SRCINFO, symbols, my_fields, ands)
#endif

#define front_SymbolSeq_GET_List_front_Symbol(i,me)	(i == 0 ? front_SymbolSeq_symbols(me) : 0)
#define front_SymbolSeq_GET_List_front_Field(i,me)	(i == 1 ? front_SymbolSeq_my_fields(me) : 0)
#define front_SymbolSeq_GET_List_front_And(i,me)	(i == 2 ? front_SymbolSeq_ands(me) : 0)

#ifndef NEW_front_AltSymbol
#define NEW_front_AltSymbol(src_info, syms1, alt, syms, yyy) Create_front_AltSymbol(NO_SRCINFO, syms1, alt, syms)
#endif

#define front_AltSymbol_GET_front_Symbol(i,me)	(i == 0 ? front_AltSymbol_syms1(me) : 0)
#define front_AltSymbol_GET_front_Alternator(i,me)	(i == 1 ? front_AltSymbol_alt(me) : 0)
#define front_AltSymbol_GET_List_front_Symbol(i,me)	(i == 2 ? front_AltSymbol_syms(me) : 0)

#ifndef NEW_front_LabeledSym
#define NEW_front_LabeledSym(src_info, id, sym, yyy) Create_front_LabeledSym(NO_SRCINFO, id, sym)
#endif

#define front_LabeledSym_GET_Ident(i,me)	(i == 0 ? front_LabeledSym_id(me) : 0)
#define front_LabeledSym_GET_front_Symbol(i,me)	(i == 1 ? front_LabeledSym_sym(me) : 0)

#ifndef front_Defining_id_OPERATOR
#define front_Defining_id_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Defining_id_tag(a))
#endif
#ifndef front_Defining_id_HAS_OPER
#define front_Defining_id_HAS_OPER(a,op) ((a) != NULL && front_Defining_id_tag(a) == op)
#endif
#ifndef front_Defining_id_REPLACE 
#define front_Defining_id_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Defining_id
#define COPY_front_Defining_id(x) Traverse_copy_front_Defining_id(x, &front_copy_actions)
#endif

#ifndef NEW_front_DefExpr
#define NEW_front_DefExpr(src_info, e, yyy) Create_front_DefExpr(NO_SRCINFO, e)
#endif

#define front_DefExpr_GET_front_Expr(i,me)	(i == 0 ? front_DefExpr_e(me) : 0)

#ifndef NEW_front_DefId
#define NEW_front_DefId(src_info, id, yyy) Create_front_DefId(NO_SRCINFO, id)
#endif

#define front_DefId_GET_front_Symbol(i,me)	(i == 0 ? front_DefId_id(me) : 0)

#ifndef front_Field_OPERATOR
#define front_Field_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Field_kind)
#endif
#ifndef front_Field_HAS_OPER
#define front_Field_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_Field_REPLACE 
#define front_Field_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Field
#define COPY_front_Field(x) Traverse_copy_front_Field(x, &front_copy_actions)
#endif

#ifndef NEW_front_Field
#define NEW_front_Field(src_info, id, type, assign, when, traverse, clear, dont_clear, yyy) Create_front_Field(NO_SRCINFO, id, type, assign, when, traverse, clear, dont_clear)
#endif

#define front_Field_GET_Ident(i,me)	(i == 0 ? front_Field_id(me) : i == 2 ? front_Field_assign(me) : 0)
#define front_Field_GET_front_Type(i,me)	(i == 1 ? front_Field_type(me) : 0)
#define front_Field_GET_List_front_FieldInit(i,me)	(i == 3 ? front_Field_when(me) : 0)
#define front_Field_GET_Bool(i,me)	(i == 4 ? front_Field_traverse(me) : i == 5 ? front_Field_clear(me) : i == 6 ? front_Field_dont_clear(me) : 0)

#ifndef front_FieldInit_OPERATOR
#define front_FieldInit_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_FieldInit_tag(a))
#endif
#ifndef front_FieldInit_HAS_OPER
#define front_FieldInit_HAS_OPER(a,op) ((a) != NULL && front_FieldInit_tag(a) == op)
#endif
#ifndef front_FieldInit_REPLACE 
#define front_FieldInit_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_FieldInit
#define COPY_front_FieldInit(x) Traverse_copy_front_FieldInit(x, &front_copy_actions)
#endif

#ifndef NEW_front_WhenChecks
#define NEW_front_WhenChecks(src_info, expr, yyy) Create_front_WhenChecks(NO_SRCINFO, expr)
#endif

#define front_WhenChecks_GET_front_Expr(i,me)	(i == 0 ? front_FieldInit_expr(me) : 0)

#ifndef NEW_front_WhenApplied
#define NEW_front_WhenApplied(src_info, expr, yyy) Create_front_WhenApplied(NO_SRCINFO, expr)
#endif

#define front_WhenApplied_GET_front_Expr(i,me)	(i == 0 ? front_FieldInit_expr(me) : 0)

#ifndef NEW_front_WhenDefining
#define NEW_front_WhenDefining(src_info, expr, yyy) Create_front_WhenDefining(NO_SRCINFO, expr)
#endif

#define front_WhenDefining_GET_front_Expr(i,me)	(i == 0 ? front_FieldInit_expr(me) : 0)

#ifndef NEW_front_WhenScope
#define NEW_front_WhenScope(src_info, expr, yyy) Create_front_WhenScope(NO_SRCINFO, expr)
#endif

#define front_WhenScope_GET_front_Expr(i,me)	(i == 0 ? front_FieldInit_expr(me) : 0)

#ifndef NEW_front_WhenCreate
#define NEW_front_WhenCreate(src_info, c, expr, yyy) Create_front_WhenCreate(NO_SRCINFO, c, expr)
#endif

#define front_WhenCreate_GET_Bool(i,me)	(i == 0 ? front_WhenCreate_c(me) : 0)
#define front_WhenCreate_GET_front_Expr(i,me)	(i == 1 ? front_FieldInit_expr(me) : 0)

#ifndef front_Type_OPERATOR
#define front_Type_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Type_kind)
#endif
#ifndef front_Type_HAS_OPER
#define front_Type_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_Type_REPLACE 
#define front_Type_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Type
#define COPY_front_Type(x) Traverse_copy_front_Type(x, &front_copy_actions)
#endif

#ifndef NEW_front_Type
#define NEW_front_Type(src_info, id, args, yyy) Create_front_Type(NO_SRCINFO, id, args)
#endif

#define front_Type_GET_Ident(i,me)	(i == 0 ? front_Type_id(me) : 0)
#define front_Type_GET_List_front_Type(i,me)	(i == 1 ? front_Type_args(me) : 0)

#ifndef front_Expr_OPERATOR
#define front_Expr_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Expr_tag(a))
#endif
#ifndef front_Expr_HAS_OPER
#define front_Expr_HAS_OPER(a,op) ((a) != NULL && front_Expr_tag(a) == op)
#endif
#ifndef front_Expr_REPLACE 
#define front_Expr_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Expr
#define COPY_front_Expr(x) Traverse_copy_front_Expr(x, &front_copy_actions)
#endif

#ifndef NEW_front_CallExpr
#define NEW_front_CallExpr(src_info, func, args, yyy) Create_front_CallExpr(NO_SRCINFO, func, args)
#endif

#define front_CallExpr_GET_front_Expr(i,me)	(i == 0 ? front_CallExpr_func(me) : 0)
#define front_CallExpr_GET_List_front_Expr(i,me)	(i == 1 ? front_CallExpr_args(me) : 0)

#ifndef NEW_front_NilExpr
#define NEW_front_NilExpr(src_info, yyy) Create_front_NilExpr(NO_SRCINFO)
#endif


#ifndef NEW_front_StringExpr
#define NEW_front_StringExpr(src_info, string, yyy) Create_front_StringExpr(NO_SRCINFO, string)
#endif

#define front_StringExpr_GET_String(i,me)	(i == 0 ? front_StringExpr_string(me) : 0)

#ifndef NEW_front_BoolExpr
#define NEW_front_BoolExpr(src_info, b, yyy) Create_front_BoolExpr(NO_SRCINFO, b)
#endif

#define front_BoolExpr_GET_Bool(i,me)	(i == 0 ? front_BoolExpr_b(me) : 0)

#ifndef NEW_front_IntExpr
#define NEW_front_IntExpr(src_info, i, yyy) Create_front_IntExpr(NO_SRCINFO, i)
#endif

#define front_IntExpr_GET_Int(i,me)	(i == 0 ? front_IntExpr_i(me) : 0)

#ifndef NEW_front_QualExpr
#define NEW_front_QualExpr(src_info, prefix, id, yyy) Create_front_QualExpr(NO_SRCINFO, prefix, id)
#endif

#define front_QualExpr_GET_front_Expr(i,me)	(i == 0 ? front_QualExpr_prefix(me) : 0)
#define front_QualExpr_GET_Ident(i,me)	(i == 1 ? front_QualExpr_id(me) : 0)

#ifndef NEW_front_IdentExpr
#define NEW_front_IdentExpr(src_info, id, yyy) Create_front_IdentExpr(NO_SRCINFO, id)
#endif

#define front_IdentExpr_GET_Ident(i,me)	(i == 0 ? front_IdentExpr_id(me) : 0)

#ifndef NEW_front_MonExpr
#define NEW_front_MonExpr(src_info, ops, arg, yyy) Create_front_MonExpr(NO_SRCINFO, ops, arg)
#endif

#define front_MonExpr_GET_List_Ident(i,me)	(i == 0 ? front_MonExpr1_ops(me) : 0)
#define front_MonExpr_GET_front_Expr(i,me)	(i == 1 ? front_MonExpr1_arg(me) : 0)

#ifndef NEW_front_BinExpr
#define NEW_front_BinExpr(src_info, args, ops, yyy) Create_front_BinExpr(NO_SRCINFO, args, ops)
#endif

#define front_BinExpr_GET_List_front_Expr(i,me)	(i == 0 ? front_BinExpr_args(me) : 0)
#define front_BinExpr_GET_List_Ident(i,me)	(i == 1 ? front_BinExpr_ops(me) : 0)

#ifndef front_Check_OPERATOR
#define front_Check_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Check_kind)
#endif
#ifndef front_Check_HAS_OPER
#define front_Check_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_Check_REPLACE 
#define front_Check_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Check
#define COPY_front_Check(x) Traverse_copy_front_Check(x, &front_copy_actions)
#endif

#ifndef NEW_front_Check
#define NEW_front_Check(src_info, cond, warn, message, yyy) Create_front_Check(NO_SRCINFO, cond, warn, message)
#endif

#define front_Check_GET_front_Expr(i,me)	(i == 0 ? front_Check_cond(me) : 0)
#define front_Check_GET_Bool(i,me)	(i == 1 ? front_Check_warn(me) : 0)
#define front_Check_GET_List_front_Expr(i,me)	(i == 2 ? front_Check_message(me) : 0)

#ifndef front_ScanInfo_OPERATOR
#define front_ScanInfo_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_ScanInfo_kind)
#endif
#ifndef front_ScanInfo_HAS_OPER
#define front_ScanInfo_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_ScanInfo_REPLACE 
#define front_ScanInfo_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_ScanInfo
#define COPY_front_ScanInfo(x) Traverse_copy_front_ScanInfo(x, &front_copy_actions)
#endif

#ifndef NEW_front_ScanInfo
#define NEW_front_ScanInfo(src_info, type, comment, yyy) Create_front_ScanInfo(NO_SRCINFO, type, comment)
#endif

#define front_ScanInfo_GET_front_Type(i,me)	(i == 0 ? front_ScanInfo_type(me) : 0)
#define front_ScanInfo_GET_Bool(i,me)	(i == 1 ? front_ScanInfo_comment(me) : 0)

#ifndef front_Defines_OPERATOR
#define front_Defines_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Defines_tag(a))
#endif
#ifndef front_Defines_HAS_OPER
#define front_Defines_HAS_OPER(a,op) ((a) != NULL && front_Defines_tag(a) == op)
#endif
#ifndef front_Defines_REPLACE 
#define front_Defines_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Defines
#define COPY_front_Defines(x) Traverse_copy_front_Defines(x, &front_copy_actions)
#endif

#ifndef NEW_front_MacroDef
#define NEW_front_MacroDef(src_info, id, yyy) Create_front_MacroDef(NO_SRCINFO, id)
#endif

#define front_MacroDef_GET_Ident(i,me)	(i == 0 ? front_Defines_id(me) : 0)

#ifndef NEW_front_PlainDef
#define NEW_front_PlainDef(src_info, id, yyy) Create_front_PlainDef(NO_SRCINFO, id)
#endif

#define front_PlainDef_GET_Ident(i,me)	(i == 0 ? front_Defines_id(me) : 0)

#ifndef front_NameSpace_OPERATOR
#define front_NameSpace_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_NameSpace_kind)
#endif
#ifndef front_NameSpace_HAS_OPER
#define front_NameSpace_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_NameSpace_REPLACE 
#define front_NameSpace_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_NameSpace
#define COPY_front_NameSpace(x) Traverse_copy_front_NameSpace(x, &front_copy_actions)
#endif

#ifndef NEW_front_NameSpace
#define NEW_front_NameSpace(src_info, id, yyy) Create_front_NameSpace(NO_SRCINFO, id)
#endif

#define front_NameSpace_GET_Ident(i,me)	(i == 0 ? front_NameSpace_id(me) : 0)

#ifndef front_dummy_OPERATOR
#define front_dummy_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_dummy_kind)
#endif
#ifndef front_dummy_HAS_OPER
#define front_dummy_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef front_dummy_REPLACE 
#define front_dummy_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_dummy
#define COPY_front_dummy(x) Traverse_copy_front_dummy(x, &front_copy_actions)
#endif

#ifndef NEW_front_dummy
#define NEW_front_dummy(src_info, yyy) Create_front_dummy(NO_SRCINFO)
#endif


#ifndef front_Scope_OPERATOR
#define front_Scope_OPERATOR(a) ((a)==NULL?(unsigned)~0:front_Scope_tag(a))
#endif
#ifndef front_Scope_HAS_OPER
#define front_Scope_HAS_OPER(a,op) ((a) != NULL && front_Scope_tag(a) == op)
#endif
#ifndef front_Scope_REPLACE 
#define front_Scope_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_front_Scope
#define COPY_front_Scope(x) Traverse_copy_front_Scope(x, &front_copy_actions)
#endif

#ifndef NEW_front_NonTerminalScope
#define NEW_front_NonTerminalScope(next, data, yyy) Create_front_NonTerminalScope(NO_SRCINFO, data)
#endif

#define front_NonTerminalScope_GET_front_NonTerminal(i,me)	(i == 0 ? front_NonTerminalScope_data(me) : 0)

#ifndef List_List_front_Symbol_OPERATOR
#define List_List_front_Symbol_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_List_front_Symbol_kind)
#endif
#ifndef List_List_front_Symbol_HAS_OPER
#define List_List_front_Symbol_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_List_front_Symbol_REPLACE 
#define List_List_front_Symbol_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_List_front_Symbol
#define COPY_List_List_front_Symbol(x) Traverse_copy_List_List_front_Symbol(x, &front_copy_actions)
#endif

#ifndef NEW_List_List_front_Symbol
#define NEW_List_List_front_Symbol(xxx, data, next, yyy) Create_List_List_front_Symbol(data, next)
#endif

#define List_List_front_Symbol_GET_List_front_Symbol(i,me)	(i == 0 ? List_List_front_Symbol_data(me) : 0)
#define List_List_front_Symbol_GET_List_List_front_Symbol(i,me)	(i == 1 ? List_List_front_Symbol_next(me) : 0)

#ifndef List_front_Expr_OPERATOR
#define List_front_Expr_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_Expr_kind)
#endif
#ifndef List_front_Expr_HAS_OPER
#define List_front_Expr_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_Expr_REPLACE 
#define List_front_Expr_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_Expr
#define COPY_List_front_Expr(x) Traverse_copy_List_front_Expr(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_Expr
#define NEW_List_front_Expr(xxx, data, next, yyy) Create_List_front_Expr(data, next)
#endif

#define List_front_Expr_GET_front_Expr(i,me)	(i == 0 ? List_front_Expr_data(me) : 0)
#define List_front_Expr_GET_List_front_Expr(i,me)	(i == 1 ? List_front_Expr_next(me) : 0)

#ifndef List_front_Type_OPERATOR
#define List_front_Type_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_Type_kind)
#endif
#ifndef List_front_Type_HAS_OPER
#define List_front_Type_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_Type_REPLACE 
#define List_front_Type_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_Type
#define COPY_List_front_Type(x) Traverse_copy_List_front_Type(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_Type
#define NEW_List_front_Type(xxx, data, next, yyy) Create_List_front_Type(data, next)
#endif

#define List_front_Type_GET_front_Type(i,me)	(i == 0 ? List_front_Type_data(me) : 0)
#define List_front_Type_GET_List_front_Type(i,me)	(i == 1 ? List_front_Type_next(me) : 0)

#ifndef List_front_FieldInit_OPERATOR
#define List_front_FieldInit_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_FieldInit_kind)
#endif
#ifndef List_front_FieldInit_HAS_OPER
#define List_front_FieldInit_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_FieldInit_REPLACE 
#define List_front_FieldInit_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_FieldInit
#define COPY_List_front_FieldInit(x) Traverse_copy_List_front_FieldInit(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_FieldInit
#define NEW_List_front_FieldInit(xxx, data, next, yyy) Create_List_front_FieldInit(data, next)
#endif

#define List_front_FieldInit_GET_front_FieldInit(i,me)	(i == 0 ? List_front_FieldInit_data(me) : 0)
#define List_front_FieldInit_GET_List_front_FieldInit(i,me)	(i == 1 ? List_front_FieldInit_next(me) : 0)

#ifndef List_front_And_OPERATOR
#define List_front_And_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_And_kind)
#endif
#ifndef List_front_And_HAS_OPER
#define List_front_And_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_And_REPLACE 
#define List_front_And_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_And
#define COPY_List_front_And(x) Traverse_copy_List_front_And(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_And
#define NEW_List_front_And(xxx, data, next, yyy) Create_List_front_And(data, next)
#endif

#define List_front_And_GET_front_And(i,me)	(i == 0 ? List_front_And_data(me) : 0)
#define List_front_And_GET_List_front_And(i,me)	(i == 1 ? List_front_And_next(me) : 0)

#ifndef List_front_Field_OPERATOR
#define List_front_Field_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_Field_kind)
#endif
#ifndef List_front_Field_HAS_OPER
#define List_front_Field_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_Field_REPLACE 
#define List_front_Field_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_Field
#define COPY_List_front_Field(x) Traverse_copy_List_front_Field(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_Field
#define NEW_List_front_Field(xxx, data, next, yyy) Create_List_front_Field(data, next)
#endif

#define List_front_Field_GET_front_Field(i,me)	(i == 0 ? List_front_Field_data(me) : 0)
#define List_front_Field_GET_List_front_Field(i,me)	(i == 1 ? List_front_Field_next(me) : 0)

#ifndef List_front_Symbol_OPERATOR
#define List_front_Symbol_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_Symbol_kind)
#endif
#ifndef List_front_Symbol_HAS_OPER
#define List_front_Symbol_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_Symbol_REPLACE 
#define List_front_Symbol_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_Symbol
#define COPY_List_front_Symbol(x) Traverse_copy_List_front_Symbol(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_Symbol
#define NEW_List_front_Symbol(xxx, data, next, yyy) Create_List_front_Symbol(data, next)
#endif

#define List_front_Symbol_GET_front_Symbol(i,me)	(i == 0 ? List_front_Symbol_data(me) : 0)
#define List_front_Symbol_GET_List_front_Symbol(i,me)	(i == 1 ? List_front_Symbol_next(me) : 0)

#ifndef List_front_Check_OPERATOR
#define List_front_Check_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_Check_kind)
#endif
#ifndef List_front_Check_HAS_OPER
#define List_front_Check_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_Check_REPLACE 
#define List_front_Check_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_Check
#define COPY_List_front_Check(x) Traverse_copy_List_front_Check(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_Check
#define NEW_List_front_Check(xxx, data, next, yyy) Create_List_front_Check(data, next)
#endif

#define List_front_Check_GET_front_Check(i,me)	(i == 0 ? List_front_Check_data(me) : 0)
#define List_front_Check_GET_List_front_Check(i,me)	(i == 1 ? List_front_Check_next(me) : 0)

#ifndef List_front_Or_OPERATOR
#define List_front_Or_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_Or_kind)
#endif
#ifndef List_front_Or_HAS_OPER
#define List_front_Or_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_Or_REPLACE 
#define List_front_Or_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_Or
#define COPY_List_front_Or(x) Traverse_copy_List_front_Or(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_Or
#define NEW_List_front_Or(xxx, data, next, yyy) Create_List_front_Or(data, next)
#endif

#define List_front_Or_GET_front_Or(i,me)	(i == 0 ? List_front_Or_data(me) : 0)
#define List_front_Or_GET_List_front_Or(i,me)	(i == 1 ? List_front_Or_next(me) : 0)

#ifndef List_front_Alternative_OPERATOR
#define List_front_Alternative_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_Alternative_kind)
#endif
#ifndef List_front_Alternative_HAS_OPER
#define List_front_Alternative_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_Alternative_REPLACE 
#define List_front_Alternative_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_Alternative
#define COPY_List_front_Alternative(x) Traverse_copy_List_front_Alternative(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_Alternative
#define NEW_List_front_Alternative(xxx, data, next, yyy) Create_List_front_Alternative(data, next)
#endif

#define List_front_Alternative_GET_front_Alternative(i,me)	(i == 0 ? List_front_Alternative_data(me) : 0)
#define List_front_Alternative_GET_List_front_Alternative(i,me)	(i == 1 ? List_front_Alternative_next(me) : 0)

#ifndef List_front_Scoping_OPERATOR
#define List_front_Scoping_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_Scoping_kind)
#endif
#ifndef List_front_Scoping_HAS_OPER
#define List_front_Scoping_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_Scoping_REPLACE 
#define List_front_Scoping_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_Scoping
#define COPY_List_front_Scoping(x) Traverse_copy_List_front_Scoping(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_Scoping
#define NEW_List_front_Scoping(xxx, data, next, yyy) Create_List_front_Scoping(data, next)
#endif

#define List_front_Scoping_GET_front_Scoping(i,me)	(i == 0 ? List_front_Scoping_data(me) : 0)
#define List_front_Scoping_GET_List_front_Scoping(i,me)	(i == 1 ? List_front_Scoping_next(me) : 0)

#ifndef List_front_ImportedNonTerminal_OPERATOR
#define List_front_ImportedNonTerminal_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_ImportedNonTerminal_kind)
#endif
#ifndef List_front_ImportedNonTerminal_HAS_OPER
#define List_front_ImportedNonTerminal_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_ImportedNonTerminal_REPLACE 
#define List_front_ImportedNonTerminal_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_ImportedNonTerminal
#define COPY_List_front_ImportedNonTerminal(x) Traverse_copy_List_front_ImportedNonTerminal(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_ImportedNonTerminal
#define NEW_List_front_ImportedNonTerminal(xxx, data, next, yyy) Create_List_front_ImportedNonTerminal(data, next)
#endif

#define List_front_ImportedNonTerminal_GET_front_ImportedNonTerminal(i,me)	(i == 0 ? List_front_ImportedNonTerminal_data(me) : 0)
#define List_front_ImportedNonTerminal_GET_List_front_ImportedNonTerminal(i,me)	(i == 1 ? List_front_ImportedNonTerminal_next(me) : 0)

#ifndef List_front_NonTerminal_OPERATOR
#define List_front_NonTerminal_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_NonTerminal_kind)
#endif
#ifndef List_front_NonTerminal_HAS_OPER
#define List_front_NonTerminal_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_NonTerminal_REPLACE 
#define List_front_NonTerminal_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_NonTerminal
#define COPY_List_front_NonTerminal(x) Traverse_copy_List_front_NonTerminal(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_NonTerminal
#define NEW_List_front_NonTerminal(xxx, data, next, yyy) Create_List_front_NonTerminal(data, next)
#endif

#define List_front_NonTerminal_GET_front_NonTerminal(i,me)	(i == 0 ? List_front_NonTerminal_data(me) : 0)
#define List_front_NonTerminal_GET_List_front_NonTerminal(i,me)	(i == 1 ? List_front_NonTerminal_next(me) : 0)

#ifndef List_front_Import_OPERATOR
#define List_front_Import_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_Import_kind)
#endif
#ifndef List_front_Import_HAS_OPER
#define List_front_Import_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_Import_REPLACE 
#define List_front_Import_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_Import
#define COPY_List_front_Import(x) Traverse_copy_List_front_Import(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_Import
#define NEW_List_front_Import(xxx, data, next, yyy) Create_List_front_Import(data, next)
#endif

#define List_front_Import_GET_front_Import(i,me)	(i == 0 ? List_front_Import_data(me) : 0)
#define List_front_Import_GET_List_front_Import(i,me)	(i == 1 ? List_front_Import_next(me) : 0)

#ifndef List_front_NameSpace_OPERATOR
#define List_front_NameSpace_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_front_NameSpace_kind)
#endif
#ifndef List_front_NameSpace_HAS_OPER
#define List_front_NameSpace_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_front_NameSpace_REPLACE 
#define List_front_NameSpace_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_front_NameSpace
#define COPY_List_front_NameSpace(x) Traverse_copy_List_front_NameSpace(x, &front_copy_actions)
#endif

#ifndef NEW_List_front_NameSpace
#define NEW_List_front_NameSpace(xxx, data, next, yyy) Create_List_front_NameSpace(data, next)
#endif

#define List_front_NameSpace_GET_front_NameSpace(i,me)	(i == 0 ? List_front_NameSpace_data(me) : 0)
#define List_front_NameSpace_GET_List_front_NameSpace(i,me)	(i == 1 ? List_front_NameSpace_next(me) : 0)

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
#define COPY_List_Ident(x) Traverse_copy_List_Ident(x, &front_copy_actions)
#endif

#ifndef front_Super_tag_OPERATOR
#define front_Super_tag_OPERATOR(a) (a)
#endif
#ifndef front_Super_tag_HAS_OPER
#define front_Super_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Super_tag_REPLACE 
#define front_Super_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Super_tag
#define COPY_front_Super_tag(x) (x)
#endif

#ifndef NEW_front_SubType_kind
#define NEW_front_SubType_kind(x,y)	front_SubType_kind
#endif
#ifndef NEW_front_NoType_kind
#define NEW_front_NoType_kind(x,y)	front_NoType_kind
#endif
#ifndef front_Scoping_OPERATOR
#define front_Scoping_OPERATOR(a) (a)
#endif
#ifndef front_Scoping_HAS_OPER
#define front_Scoping_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Scoping_REPLACE 
#define front_Scoping_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Scoping
#define COPY_front_Scoping(x) (x)
#endif

#ifndef NEW_front_NewScope
#define NEW_front_NewScope(x,y)	front_NewScope
#endif
#ifndef NEW_front_OpenScope
#define NEW_front_OpenScope(x,y)	front_OpenScope
#endif
#ifndef NEW_front_CloseScope
#define NEW_front_CloseScope(x,y)	front_CloseScope
#endif
#ifndef front_Alternative_tag_OPERATOR
#define front_Alternative_tag_OPERATOR(a) (a)
#endif
#ifndef front_Alternative_tag_HAS_OPER
#define front_Alternative_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Alternative_tag_REPLACE 
#define front_Alternative_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Alternative_tag
#define COPY_front_Alternative_tag(x) (x)
#endif

#ifndef NEW_front_LabeledAlt_kind
#define NEW_front_LabeledAlt_kind(x,y)	front_LabeledAlt_kind
#endif
#ifndef NEW_front_UnLabeledAlt_kind
#define NEW_front_UnLabeledAlt_kind(x,y)	front_UnLabeledAlt_kind
#endif
#ifndef front_Symbol_tag_OPERATOR
#define front_Symbol_tag_OPERATOR(a) (a)
#endif
#ifndef front_Symbol_tag_HAS_OPER
#define front_Symbol_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Symbol_tag_REPLACE 
#define front_Symbol_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Symbol_tag
#define COPY_front_Symbol_tag(x) (x)
#endif

#ifndef NEW_front_LabeledSym_kind
#define NEW_front_LabeledSym_kind(x,y)	front_LabeledSym_kind
#endif
#ifndef NEW_front_AltSymbol_kind
#define NEW_front_AltSymbol_kind(x,y)	front_AltSymbol_kind
#endif
#ifndef NEW_front_SymbolSeq_kind
#define NEW_front_SymbolSeq_kind(x,y)	front_SymbolSeq_kind
#endif
#ifndef NEW_front_CompareSym_kind
#define NEW_front_CompareSym_kind(x,y)	front_CompareSym_kind
#endif
#ifndef NEW_front_AppliedSym_kind
#define NEW_front_AppliedSym_kind(x,y)	front_AppliedSym_kind
#endif
#ifndef NEW_front_StringSymbol_kind
#define NEW_front_StringSymbol_kind(x,y)	front_StringSymbol_kind
#endif
#ifndef NEW_front_CharSymbol_kind
#define NEW_front_CharSymbol_kind(x,y)	front_CharSymbol_kind
#endif
#ifndef NEW_front_KeywordSymbol_kind
#define NEW_front_KeywordSymbol_kind(x,y)	front_KeywordSymbol_kind
#endif
#ifndef NEW_front_OnceSymbol_kind
#define NEW_front_OnceSymbol_kind(x,y)	front_OnceSymbol_kind
#endif
#ifndef NEW_front_OptSymbol_kind
#define NEW_front_OptSymbol_kind(x,y)	front_OptSymbol_kind
#endif
#ifndef NEW_front_OptMoreSymbol_kind
#define NEW_front_OptMoreSymbol_kind(x,y)	front_OptMoreSymbol_kind
#endif
#ifndef NEW_front_MoreSymbol_kind
#define NEW_front_MoreSymbol_kind(x,y)	front_MoreSymbol_kind
#endif
#ifndef NEW_front_EmptySym_kind
#define NEW_front_EmptySym_kind(x,y)	front_EmptySym_kind
#endif
#ifndef NEW_front_LayoutString_kind
#define NEW_front_LayoutString_kind(x,y)	front_LayoutString_kind
#endif
#ifndef NEW_front_LayoutAction_kind
#define NEW_front_LayoutAction_kind(x,y)	front_LayoutAction_kind
#endif
#ifndef NEW_front_IdSym_kind
#define NEW_front_IdSym_kind(x,y)	front_IdSym_kind
#endif
#ifndef NEW_front_DefiningSym_kind
#define NEW_front_DefiningSym_kind(x,y)	front_DefiningSym_kind
#endif
#ifndef front_And_OPERATOR
#define front_And_OPERATOR(a) (a)
#endif
#ifndef front_And_HAS_OPER
#define front_And_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_And_REPLACE 
#define front_And_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_And
#define COPY_front_And(x) (x)
#endif

#ifndef NEW_front_AndTranspose
#define NEW_front_AndTranspose(x,y)	front_AndTranspose
#endif
#ifndef NEW_front_AndLeft
#define NEW_front_AndLeft(x,y)	front_AndLeft
#endif
#ifndef NEW_front_AndRight
#define NEW_front_AndRight(x,y)	front_AndRight
#endif
#ifndef NEW_front_AndCenter
#define NEW_front_AndCenter(x,y)	front_AndCenter
#endif
#ifndef front_Or_OPERATOR
#define front_Or_OPERATOR(a) (a)
#endif
#ifndef front_Or_HAS_OPER
#define front_Or_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Or_REPLACE 
#define front_Or_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Or
#define COPY_front_Or(x) (x)
#endif

#ifndef NEW_front_OrCenter
#define NEW_front_OrCenter(x,y)	front_OrCenter
#endif
#ifndef NEW_front_OrLeft
#define NEW_front_OrLeft(x,y)	front_OrLeft
#endif
#ifndef NEW_front_OrRight
#define NEW_front_OrRight(x,y)	front_OrRight
#endif
#ifndef NEW_front_OrTranspose
#define NEW_front_OrTranspose(x,y)	front_OrTranspose
#endif
#ifndef front_Defining_id_tag_OPERATOR
#define front_Defining_id_tag_OPERATOR(a) (a)
#endif
#ifndef front_Defining_id_tag_HAS_OPER
#define front_Defining_id_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Defining_id_tag_REPLACE 
#define front_Defining_id_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Defining_id_tag
#define COPY_front_Defining_id_tag(x) (x)
#endif

#ifndef NEW_front_DefId_kind
#define NEW_front_DefId_kind(x,y)	front_DefId_kind
#endif
#ifndef NEW_front_DefExpr_kind
#define NEW_front_DefExpr_kind(x,y)	front_DefExpr_kind
#endif
#ifndef front_Define_OPERATOR
#define front_Define_OPERATOR(a) (a)
#endif
#ifndef front_Define_HAS_OPER
#define front_Define_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Define_REPLACE 
#define front_Define_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Define
#define COPY_front_Define(x) (x)
#endif

#ifndef NEW_front_Defining
#define NEW_front_Defining(x,y)	front_Defining
#endif
#ifndef NEW_front_Redefining
#define NEW_front_Redefining(x,y)	front_Redefining
#endif
#ifndef NEW_front_Overloading
#define NEW_front_Overloading(x,y)	front_Overloading
#endif
#ifndef front_FieldInit_tag_OPERATOR
#define front_FieldInit_tag_OPERATOR(a) (a)
#endif
#ifndef front_FieldInit_tag_HAS_OPER
#define front_FieldInit_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_FieldInit_tag_REPLACE 
#define front_FieldInit_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_FieldInit_tag
#define COPY_front_FieldInit_tag(x) (x)
#endif

#ifndef NEW_front_WhenCreate_kind
#define NEW_front_WhenCreate_kind(x,y)	front_WhenCreate_kind
#endif
#ifndef NEW_front_WhenScope_kind
#define NEW_front_WhenScope_kind(x,y)	front_WhenScope_kind
#endif
#ifndef NEW_front_WhenDefining_kind
#define NEW_front_WhenDefining_kind(x,y)	front_WhenDefining_kind
#endif
#ifndef NEW_front_WhenApplied_kind
#define NEW_front_WhenApplied_kind(x,y)	front_WhenApplied_kind
#endif
#ifndef NEW_front_WhenChecks_kind
#define NEW_front_WhenChecks_kind(x,y)	front_WhenChecks_kind
#endif
#ifndef front_Expr_tag_OPERATOR
#define front_Expr_tag_OPERATOR(a) (a)
#endif
#ifndef front_Expr_tag_HAS_OPER
#define front_Expr_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Expr_tag_REPLACE 
#define front_Expr_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Expr_tag
#define COPY_front_Expr_tag(x) (x)
#endif

#ifndef NEW_front_BinExpr_kind
#define NEW_front_BinExpr_kind(x,y)	front_BinExpr_kind
#endif
#ifndef NEW_front_MonExpr_kind
#define NEW_front_MonExpr_kind(x,y)	front_MonExpr_kind
#endif
#ifndef NEW_front_IdentExpr_kind
#define NEW_front_IdentExpr_kind(x,y)	front_IdentExpr_kind
#endif
#ifndef NEW_front_QualExpr_kind
#define NEW_front_QualExpr_kind(x,y)	front_QualExpr_kind
#endif
#ifndef NEW_front_IntExpr_kind
#define NEW_front_IntExpr_kind(x,y)	front_IntExpr_kind
#endif
#ifndef NEW_front_BoolExpr_kind
#define NEW_front_BoolExpr_kind(x,y)	front_BoolExpr_kind
#endif
#ifndef NEW_front_StringExpr_kind
#define NEW_front_StringExpr_kind(x,y)	front_StringExpr_kind
#endif
#ifndef NEW_front_NilExpr_kind
#define NEW_front_NilExpr_kind(x,y)	front_NilExpr_kind
#endif
#ifndef NEW_front_CallExpr_kind
#define NEW_front_CallExpr_kind(x,y)	front_CallExpr_kind
#endif
#ifndef front_Alternator_OPERATOR
#define front_Alternator_OPERATOR(a) (a)
#endif
#ifndef front_Alternator_HAS_OPER
#define front_Alternator_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Alternator_REPLACE 
#define front_Alternator_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Alternator
#define COPY_front_Alternator(x) (x)
#endif

#ifndef front_Defines_tag_OPERATOR
#define front_Defines_tag_OPERATOR(a) (a)
#endif
#ifndef front_Defines_tag_HAS_OPER
#define front_Defines_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Defines_tag_REPLACE 
#define front_Defines_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Defines_tag
#define COPY_front_Defines_tag(x) (x)
#endif

#ifndef NEW_front_PlainDef_kind
#define NEW_front_PlainDef_kind(x,y)	front_PlainDef_kind
#endif
#ifndef NEW_front_MacroDef_kind
#define NEW_front_MacroDef_kind(x,y)	front_MacroDef_kind
#endif
#ifndef front_NameOrField_OPERATOR
#define front_NameOrField_OPERATOR(a) (a)
#endif
#ifndef front_NameOrField_HAS_OPER
#define front_NameOrField_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_NameOrField_REPLACE 
#define front_NameOrField_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_NameOrField
#define COPY_front_NameOrField(x) (x)
#endif

#ifndef NEW_front_AppliedName
#define NEW_front_AppliedName(x,y)	front_AppliedName
#endif
#ifndef NEW_front_AppliedField
#define NEW_front_AppliedField(x,y)	front_AppliedField
#endif
#ifndef front_Scope_tag_OPERATOR
#define front_Scope_tag_OPERATOR(a) (a)
#endif
#ifndef front_Scope_tag_HAS_OPER
#define front_Scope_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef front_Scope_tag_REPLACE 
#define front_Scope_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_front_Scope_tag
#define COPY_front_Scope_tag(x) (x)
#endif

#ifndef NEW_front_NonTerminalScope_kind
#define NEW_front_NonTerminalScope_kind(x,y)	front_NonTerminalScope_kind
#endif
#ifndef Bind_front_NameSpace_OPERATOR
#define Bind_front_NameSpace_OPERATOR(a) (a)
#endif
#ifndef Bind_front_NameSpace_HAS_OPER
#define Bind_front_NameSpace_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Bind_front_NameSpace_REPLACE 
#define Bind_front_NameSpace_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Bind_front_NameSpace
#define COPY_Bind_front_NameSpace(x) (x)
#endif

#ifndef Bind_front_Alternative_OPERATOR
#define Bind_front_Alternative_OPERATOR(a) (a)
#endif
#ifndef Bind_front_Alternative_HAS_OPER
#define Bind_front_Alternative_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Bind_front_Alternative_REPLACE 
#define Bind_front_Alternative_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Bind_front_Alternative
#define COPY_Bind_front_Alternative(x) (x)
#endif

#ifndef Bind_front_NonTerminal_OPERATOR
#define Bind_front_NonTerminal_OPERATOR(a) (a)
#endif
#ifndef Bind_front_NonTerminal_HAS_OPER
#define Bind_front_NonTerminal_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Bind_front_NonTerminal_REPLACE 
#define Bind_front_NonTerminal_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Bind_front_NonTerminal
#define COPY_Bind_front_NonTerminal(x) (x)
#endif

#ifndef Bind_front_ImportedNonTerminal_OPERATOR
#define Bind_front_ImportedNonTerminal_OPERATOR(a) (a)
#endif
#ifndef Bind_front_ImportedNonTerminal_HAS_OPER
#define Bind_front_ImportedNonTerminal_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Bind_front_ImportedNonTerminal_REPLACE 
#define Bind_front_ImportedNonTerminal_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Bind_front_ImportedNonTerminal
#define COPY_Bind_front_ImportedNonTerminal(x) (x)
#endif

