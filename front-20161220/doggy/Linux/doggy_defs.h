#ifndef doggy_NO_DEFS
#define _doggy_h

#ifndef machine_descriptionScope
#define machine_descriptionScope doggy_machine_descriptionScope
#endif
#ifndef RuleScope
#define RuleScope doggy_RuleScope
#endif
#ifndef FuncRuleScope
#define FuncRuleScope doggy_FuncRuleScope
#endif
#ifndef RhsGuardScope
#define RhsGuardScope doggy_RhsGuardScope
#endif
#ifndef ExprGuardScope
#define ExprGuardScope doggy_ExprGuardScope
#endif
#ifndef AppliedOpScope
#define AppliedOpScope doggy_AppliedOpScope
#endif
#ifndef OpSetScope
#define OpSetScope doggy_OpSetScope
#endif
#ifndef machine_descriptionScope_kind
#define machine_descriptionScope_kind doggy_machine_descriptionScope_kind
#endif
#ifndef RuleScope_kind
#define RuleScope_kind doggy_RuleScope_kind
#endif
#ifndef FuncRuleScope_kind
#define FuncRuleScope_kind doggy_FuncRuleScope_kind
#endif
#ifndef RhsGuardScope_kind
#define RhsGuardScope_kind doggy_RhsGuardScope_kind
#endif
#ifndef ExprGuardScope_kind
#define ExprGuardScope_kind doggy_ExprGuardScope_kind
#endif
#ifndef AppliedOpScope_kind
#define AppliedOpScope_kind doggy_AppliedOpScope_kind
#endif
#ifndef OpSetScope_kind
#define OpSetScope_kind doggy_OpSetScope_kind
#endif
#ifndef NUM_Scope_tag
#define NUM_Scope_tag NUM_doggy_Scope_tag
#endif
#ifndef Scope_tag
#define Scope_tag doggy_Scope_tag
#endif
#ifndef IsInt_kind
#define IsInt_kind doggy_IsInt_kind
#endif
#ifndef IsId_kind
#define IsId_kind doggy_IsId_kind
#endif
#ifndef NUM_IdInt_tag
#define NUM_IdInt_tag NUM_doggy_IdInt_tag
#endif
#ifndef IdInt_tag
#define IdInt_tag doggy_IdInt_tag
#endif
#ifndef NUM_Property
#define NUM_Property NUM_doggy_Property
#endif
#ifndef Property
#define Property doggy_Property
#endif
#ifndef FRangeType_kind
#define FRangeType_kind doggy_FRangeType_kind
#endif
#ifndef RangeType_kind
#define RangeType_kind doggy_RangeType_kind
#endif
#ifndef PointerType_kind
#define PointerType_kind doggy_PointerType_kind
#endif
#ifndef OprType_kind
#define OprType_kind doggy_OprType_kind
#endif
#ifndef IdentType_kind
#define IdentType_kind doggy_IdentType_kind
#endif
#ifndef TupleType_kind
#define TupleType_kind doggy_TupleType_kind
#endif
#ifndef EdgeType_kind
#define EdgeType_kind doggy_EdgeType_kind
#endif
#ifndef NUM_Type_tag
#define NUM_Type_tag NUM_doggy_Type_tag
#endif
#ifndef Type_tag
#define Type_tag doggy_Type_tag
#endif
#ifndef MinOp
#define MinOp doggy_MinOp
#endif
#ifndef PlusOp
#define PlusOp doggy_PlusOp
#endif
#ifndef DerefOp
#define DerefOp doggy_DerefOp
#endif
#ifndef AddrOp
#define AddrOp doggy_AddrOp
#endif
#ifndef NegOp
#define NegOp doggy_NegOp
#endif
#ifndef NotOp
#define NotOp doggy_NotOp
#endif
#ifndef NUM_MonOp
#define NUM_MonOp NUM_doggy_MonOp
#endif
#ifndef MonOp
#define MonOp doggy_MonOp
#endif
#ifndef SubOp
#define SubOp doggy_SubOp
#endif
#ifndef AddOp
#define AddOp doggy_AddOp
#endif
#ifndef AndOp
#define AndOp doggy_AndOp
#endif
#ifndef MulOp
#define MulOp doggy_MulOp
#endif
#ifndef ModOp
#define ModOp doggy_ModOp
#endif
#ifndef DivOp
#define DivOp doggy_DivOp
#endif
#ifndef SROp
#define SROp doggy_SROp
#endif
#ifndef SLOp
#define SLOp doggy_SLOp
#endif
#ifndef GTOp
#define GTOp doggy_GTOp
#endif
#ifndef LTOp
#define LTOp doggy_LTOp
#endif
#ifndef GEOp
#define GEOp doggy_GEOp
#endif
#ifndef LEOp
#define LEOp doggy_LEOp
#endif
#ifndef NeqOp
#define NeqOp doggy_NeqOp
#endif
#ifndef EqOp
#define EqOp doggy_EqOp
#endif
#ifndef XorOp
#define XorOp doggy_XorOp
#endif
#ifndef CorOp
#define CorOp doggy_CorOp
#endif
#ifndef CandOp
#define CandOp doggy_CandOp
#endif
#ifndef NUM_Operator
#define NUM_Operator NUM_doggy_Operator
#endif
#ifndef Operator
#define Operator doggy_Operator
#endif
#ifndef NullConst_kind
#define NullConst_kind doggy_NullConst_kind
#endif
#ifndef StringConst_kind
#define StringConst_kind doggy_StringConst_kind
#endif
#ifndef BoolConst_kind
#define BoolConst_kind doggy_BoolConst_kind
#endif
#ifndef IntConst_kind
#define IntConst_kind doggy_IntConst_kind
#endif
#ifndef NUM_Constant_tag
#define NUM_Constant_tag NUM_doggy_Constant_tag
#endif
#ifndef Constant_tag
#define Constant_tag doggy_Constant_tag
#endif
#ifndef MonExpr_kind
#define MonExpr_kind doggy_MonExpr_kind
#endif
#ifndef ParExpr_kind
#define ParExpr_kind doggy_ParExpr_kind
#endif
#ifndef Operation_kind
#define Operation_kind doggy_Operation_kind
#endif
#ifndef ConstExpr_kind
#define ConstExpr_kind doggy_ConstExpr_kind
#endif
#ifndef IfExpr_kind
#define IfExpr_kind doggy_IfExpr_kind
#endif
#ifndef IdentExpr_kind
#define IdentExpr_kind doggy_IdentExpr_kind
#endif
#ifndef ConsExpr_kind
#define ConsExpr_kind doggy_ConsExpr_kind
#endif
#ifndef BinExpr_kind
#define BinExpr_kind doggy_BinExpr_kind
#endif
#ifndef NUM_Expr_tag
#define NUM_Expr_tag NUM_doggy_Expr_tag
#endif
#ifndef Expr_tag
#define Expr_tag doggy_Expr_tag
#endif
#ifndef OpSet_kind
#define OpSet_kind doggy_OpSet_kind
#endif
#ifndef AppliedOp_kind
#define AppliedOp_kind doggy_AppliedOp_kind
#endif
#ifndef AnyOp_kind
#define AnyOp_kind doggy_AnyOp_kind
#endif
#ifndef NUM_Applied_operation_tag
#define NUM_Applied_operation_tag NUM_doggy_Applied_operation_tag
#endif
#ifndef Applied_operation_tag
#define Applied_operation_tag doggy_Applied_operation_tag
#endif
#ifndef MoreExprs_kind
#define MoreExprs_kind doggy_MoreExprs_kind
#endif
#ifndef OneExpr_kind
#define OneExpr_kind doggy_OneExpr_kind
#endif
#ifndef NUM_ExprSeq_tag
#define NUM_ExprSeq_tag NUM_doggy_ExprSeq_tag
#endif
#ifndef ExprSeq_tag
#define ExprSeq_tag doggy_ExprSeq_tag
#endif
#ifndef ExprGuard_kind
#define ExprGuard_kind doggy_ExprGuard_kind
#endif
#ifndef RhsGuard_kind
#define RhsGuard_kind doggy_RhsGuard_kind
#endif
#ifndef NUM_Guard_tag
#define NUM_Guard_tag NUM_doggy_Guard_tag
#endif
#ifndef Guard_tag
#define Guard_tag doggy_Guard_tag
#endif
#ifndef BlockRhs_kind
#define BlockRhs_kind doggy_BlockRhs_kind
#endif
#ifndef PlainRhs_kind
#define PlainRhs_kind doggy_PlainRhs_kind
#endif
#ifndef NUM_Rhs_tag
#define NUM_Rhs_tag NUM_doggy_Rhs_tag
#endif
#ifndef Rhs_tag
#define Rhs_tag doggy_Rhs_tag
#endif
#ifndef DontCarePattern_kind
#define DontCarePattern_kind doggy_DontCarePattern_kind
#endif
#ifndef NullPattern_kind
#define NullPattern_kind doggy_NullPattern_kind
#endif
#ifndef ConstPattern_kind
#define ConstPattern_kind doggy_ConstPattern_kind
#endif
#ifndef OpPattern_kind
#define OpPattern_kind doggy_OpPattern_kind
#endif
#ifndef IdentPattern_kind
#define IdentPattern_kind doggy_IdentPattern_kind
#endif
#ifndef DefPattern_kind
#define DefPattern_kind doggy_DefPattern_kind
#endif
#ifndef ConsPattern_kind
#define ConsPattern_kind doggy_ConsPattern_kind
#endif
#ifndef TypedPattern_kind
#define TypedPattern_kind doggy_TypedPattern_kind
#endif
#ifndef NUM_Pattern_tag
#define NUM_Pattern_tag NUM_doggy_Pattern_tag
#endif
#ifndef Pattern_tag
#define Pattern_tag doggy_Pattern_tag
#endif
#ifndef SetArg_kind
#define SetArg_kind doggy_SetArg_kind
#endif
#ifndef PatArg_kind
#define PatArg_kind doggy_PatArg_kind
#endif
#ifndef NUM_ArgPat_tag
#define NUM_ArgPat_tag NUM_doggy_ArgPat_tag
#endif
#ifndef ArgPat_tag
#define ArgPat_tag doggy_ArgPat_tag
#endif
#ifndef UnTypedArg_kind
#define UnTypedArg_kind doggy_UnTypedArg_kind
#endif
#ifndef TypedArg_kind
#define TypedArg_kind doggy_TypedArg_kind
#endif
#ifndef NUM_Argument_tag
#define NUM_Argument_tag NUM_doggy_Argument_tag
#endif
#ifndef Argument_tag
#define Argument_tag doggy_Argument_tag
#endif
#ifndef UnLabeledLhs_kind
#define UnLabeledLhs_kind doggy_UnLabeledLhs_kind
#endif
#ifndef LabeledLhs_kind
#define LabeledLhs_kind doggy_LabeledLhs_kind
#endif
#ifndef NUM_Lhs_tag
#define NUM_Lhs_tag NUM_doggy_Lhs_tag
#endif
#ifndef Lhs_tag
#define Lhs_tag doggy_Lhs_tag
#endif
#ifndef RuleSection_kind
#define RuleSection_kind doggy_RuleSection_kind
#endif
#ifndef FuncSection_kind
#define FuncSection_kind doggy_FuncSection_kind
#endif
#ifndef NUM_Section_tag
#define NUM_Section_tag NUM_doggy_Section_tag
#endif
#ifndef Section_tag
#define Section_tag doggy_Section_tag
#endif
#ifndef IntAttr_kind
#define IntAttr_kind doggy_IntAttr_kind
#endif
#ifndef OpAttr_kind
#define OpAttr_kind doggy_OpAttr_kind
#endif
#ifndef IdAttr_kind
#define IdAttr_kind doggy_IdAttr_kind
#endif
#ifndef NUM_Attribute_tag
#define NUM_Attribute_tag NUM_doggy_Attribute_tag
#endif
#ifndef Attribute_tag
#define Attribute_tag doggy_Attribute_tag
#endif
#ifndef ExtVar_kind
#define ExtVar_kind doggy_ExtVar_kind
#endif
#ifndef ExtFunc_kind
#define ExtFunc_kind doggy_ExtFunc_kind
#endif
#ifndef NUM_FunctionDef_tag
#define NUM_FunctionDef_tag NUM_doggy_FunctionDef_tag
#endif
#ifndef FunctionDef_tag
#define FunctionDef_tag doggy_FunctionDef_tag
#endif
#ifndef doggy
#define doggy doggy_doggy
#endif
#ifndef Typedef
#define Typedef doggy_Typedef
#endif
#ifndef ExtFunc
#define ExtFunc doggy_ExtFunc
#endif
#ifndef ExtVar
#define ExtVar doggy_ExtVar
#endif
#ifndef FunctionDef
#define FunctionDef doggy_FunctionDef
#endif
#ifndef machine_description
#define machine_description doggy_machine_description
#endif
#ifndef Operation_def
#define Operation_def doggy_Operation_def
#endif
#ifndef Attributes
#define Attributes doggy_Attributes
#endif
#ifndef IdAttr
#define IdAttr doggy_IdAttr
#endif
#ifndef OpAttr
#define OpAttr doggy_OpAttr
#endif
#ifndef IntAttr
#define IntAttr doggy_IntAttr
#endif
#ifndef Attribute
#define Attribute doggy_Attribute
#endif
#ifndef FuncSection
#define FuncSection doggy_FuncSection
#endif
#ifndef RuleSection
#define RuleSection doggy_RuleSection
#endif
#ifndef Section
#define Section doggy_Section
#endif
#ifndef Rule
#define Rule doggy_Rule
#endif
#ifndef LabeledLhs
#define LabeledLhs doggy_LabeledLhs
#endif
#ifndef UnLabeledLhs
#define UnLabeledLhs doggy_UnLabeledLhs
#endif
#ifndef Lhs
#define Lhs doggy_Lhs
#endif
#ifndef Func
#define Func doggy_Func
#endif
#ifndef FuncRule
#define FuncRule doggy_FuncRule
#endif
#ifndef TypedArg
#define TypedArg doggy_TypedArg
#endif
#ifndef UnTypedArg
#define UnTypedArg doggy_UnTypedArg
#endif
#ifndef Argument
#define Argument doggy_Argument
#endif
#ifndef PatArg
#define PatArg doggy_PatArg
#endif
#ifndef SetArg
#define SetArg doggy_SetArg
#endif
#ifndef ArgPat
#define ArgPat doggy_ArgPat
#endif
#ifndef TypedPattern
#define TypedPattern doggy_TypedPattern
#endif
#ifndef ConsPattern
#define ConsPattern doggy_ConsPattern
#endif
#ifndef DefPattern
#define DefPattern doggy_DefPattern
#endif
#ifndef IdentPattern
#define IdentPattern doggy_IdentPattern
#endif
#ifndef OpPattern
#define OpPattern doggy_OpPattern
#endif
#ifndef ConstPattern
#define ConstPattern doggy_ConstPattern
#endif
#ifndef NullPattern
#define NullPattern doggy_NullPattern
#endif
#ifndef DontCarePattern
#define DontCarePattern doggy_DontCarePattern
#endif
#ifndef BasicPattern
#define BasicPattern doggy_BasicPattern
#endif
#ifndef Pattern
#define Pattern doggy_Pattern
#endif
#ifndef PlainRhs
#define PlainRhs doggy_PlainRhs
#endif
#ifndef BlockRhs
#define BlockRhs doggy_BlockRhs
#endif
#ifndef Rhs
#define Rhs doggy_Rhs
#endif
#ifndef RhsGuard
#define RhsGuard doggy_RhsGuard
#endif
#ifndef ExprGuard
#define ExprGuard doggy_ExprGuard
#endif
#ifndef Guard
#define Guard doggy_Guard
#endif
#ifndef OneExpr
#define OneExpr doggy_OneExpr
#endif
#ifndef MoreExprs
#define MoreExprs doggy_MoreExprs
#endif
#ifndef ExprSeq
#define ExprSeq doggy_ExprSeq
#endif
#ifndef Wherepart
#define Wherepart doggy_Wherepart
#endif
#ifndef AnyOp
#define AnyOp doggy_AnyOp
#endif
#ifndef AppliedOp
#define AppliedOp doggy_AppliedOp
#endif
#ifndef OpSet
#define OpSet doggy_OpSet
#endif
#ifndef Applied_operation
#define Applied_operation doggy_Applied_operation
#endif
#ifndef Applied_formal
#define Applied_formal doggy_Applied_formal
#endif
#ifndef BinExpr
#define BinExpr doggy_BinExpr
#endif
#ifndef ConsExpr
#define ConsExpr doggy_ConsExpr
#endif
#ifndef IdentExpr
#define IdentExpr doggy_IdentExpr
#endif
#ifndef IfExpr
#define IfExpr doggy_IfExpr
#endif
#ifndef ConstExpr
#define ConstExpr doggy_ConstExpr
#endif
#ifndef Operation
#define Operation doggy_Operation
#endif
#ifndef ParExpr
#define ParExpr doggy_ParExpr
#endif
#ifndef MonExpr
#define MonExpr doggy_MonExpr
#endif
#ifndef SimpleExpr
#define SimpleExpr doggy_SimpleExpr
#endif
#ifndef Expr
#define Expr doggy_Expr
#endif
#ifndef IntConst
#define IntConst doggy_IntConst
#endif
#ifndef BoolConst
#define BoolConst doggy_BoolConst
#endif
#ifndef StringConst
#define StringConst doggy_StringConst
#endif
#ifndef NullConst
#define NullConst doggy_NullConst
#endif
#ifndef Constant
#define Constant doggy_Constant
#endif
#ifndef Definition
#define Definition doggy_Definition
#endif
#ifndef EdgeType
#define EdgeType doggy_EdgeType
#endif
#ifndef TupleType
#define TupleType doggy_TupleType
#endif
#ifndef IdentType
#define IdentType doggy_IdentType
#endif
#ifndef OprType
#define OprType doggy_OprType
#endif
#ifndef PointerType
#define PointerType doggy_PointerType
#endif
#ifndef RangeType
#define RangeType doggy_RangeType
#endif
#ifndef FRangeType
#define FRangeType doggy_FRangeType
#endif
#ifndef BasicType
#define BasicType doggy_BasicType
#endif
#ifndef Type
#define Type doggy_Type
#endif
#ifndef Num
#define Num doggy_Num
#endif
#ifndef IsId
#define IsId doggy_IsId
#endif
#ifndef IsInt
#define IsInt doggy_IsInt
#endif
#ifndef IdInt
#define IdInt doggy_IdInt
#endif
#ifndef Path
#define Path doggy_Path
#endif
#ifndef ActualOp
#define ActualOp doggy_ActualOp
#endif
#ifndef TypePair
#define TypePair doggy_TypePair
#endif
#ifndef Opat
#define Opat doggy_Opat
#endif
#ifndef Format
#define Format doggy_Format
#endif
#ifndef dummy_type
#define dummy_type doggy_dummy_type
#endif
#ifndef Scope
#define Scope doggy_Scope
#endif
#ifndef List_Typedef
#define List_Typedef List_doggy_Typedef
#endif
#ifndef List_FunctionDef
#define List_FunctionDef List_doggy_FunctionDef
#endif
#ifndef List_Section
#define List_Section List_doggy_Section
#endif
#ifndef List_Func
#define List_Func List_doggy_Func
#endif
#ifndef List_Rule
#define List_Rule List_doggy_Rule
#endif
#ifndef Bind_Typedef
#define Bind_Typedef Bind_doggy_Typedef
#endif
#ifndef Bind_FunctionDef
#define Bind_FunctionDef Bind_doggy_FunctionDef
#endif
#ifndef List_Type
#define List_Type List_doggy_Type
#endif
#ifndef Bind_machine_description
#define Bind_machine_description Bind_doggy_machine_description
#endif
#ifndef List_Operation_def
#define List_Operation_def List_doggy_Operation_def
#endif
#ifndef List_Applied_formal
#define List_Applied_formal List_doggy_Applied_formal
#endif
#ifndef Bind_Operation_def
#define Bind_Operation_def Bind_doggy_Operation_def
#endif
#ifndef List_Property
#define List_Property List_doggy_Property
#endif
#ifndef List_Attribute
#define List_Attribute List_doggy_Attribute
#endif
#ifndef Bind_Func
#define Bind_Func Bind_doggy_Func
#endif
#ifndef List_FuncRule
#define List_FuncRule List_doggy_FuncRule
#endif
#ifndef List_Argument
#define List_Argument List_doggy_Argument
#endif
#ifndef Bind_Argument
#define Bind_Argument Bind_doggy_Argument
#endif
#ifndef List_Pattern
#define List_Pattern List_doggy_Pattern
#endif
#ifndef Bind_Pattern
#define Bind_Pattern Bind_doggy_Pattern
#endif
#ifndef List_Guard
#define List_Guard List_doggy_Guard
#endif
#ifndef List_Expr
#define List_Expr List_doggy_Expr
#endif
#ifndef List_Definition
#define List_Definition List_doggy_Definition
#endif
#ifndef List_Operator
#define List_Operator List_doggy_Operator
#endif
#ifndef Bind_Definition
#define Bind_Definition Bind_doggy_Definition
#endif
#ifndef List_Ident
#define List_Ident List_Ident
#endif
#ifndef List_List_Type
#define List_List_Type List_List_doggy_Type
#endif
#ifndef List_ActualOp
#define List_ActualOp List_doggy_ActualOp
#endif
#ifndef List_TypePair
#define List_TypePair List_doggy_TypePair
#endif
#ifndef List_List_TypePair
#define List_List_TypePair List_List_doggy_TypePair
#endif
#ifndef List_Num
#define List_Num List_doggy_Num
#endif
#ifndef doggy_src_info
#define doggy_src_info doggy_doggy_src_info
#endif
#ifndef doggy_srcinfo
#define doggy_srcinfo doggy_doggy_srcinfo
#endif
#ifndef doggy_loc
#define doggy_loc doggy_doggy_loc
#endif
#ifndef doggy_types
#define doggy_types doggy_doggy_types
#endif
#ifndef doggy_source
#define doggy_source doggy_doggy_source
#endif
#ifndef doggy_target
#define doggy_target doggy_doggy_target
#endif
#ifndef doggy_funcs
#define doggy_funcs doggy_doggy_funcs
#endif
#ifndef doggy_sections
#define doggy_sections doggy_doggy_sections
#endif
#ifndef doggy_functions
#define doggy_functions doggy_doggy_functions
#endif
#ifndef doggy_rules
#define doggy_rules doggy_doggy_rules
#endif
#ifndef doggy_xxx
#define doggy_xxx doggy_doggy_xxx
#endif
#ifndef Typedef_src_info
#define Typedef_src_info doggy_Typedef_src_info
#endif
#ifndef Typedef_srcinfo
#define Typedef_srcinfo doggy_Typedef_srcinfo
#endif
#ifndef Typedef_loc
#define Typedef_loc doggy_Typedef_loc
#endif
#ifndef Typedef__num
#define Typedef__num doggy_Typedef__num
#endif
#ifndef Typedef_scope
#define Typedef_scope doggy_Typedef_scope
#endif
#ifndef Typedef_old_scope
#define Typedef_old_scope doggy_Typedef_old_scope
#endif
#ifndef Typedef_id
#define Typedef_id doggy_Typedef_id
#endif
#ifndef Typedef_id_bind
#define Typedef_id_bind doggy_Typedef_id_bind
#endif
#ifndef Typedef_name
#define Typedef_name doggy_Typedef_name
#endif
#ifndef Typedef_short_hand
#define Typedef_short_hand doggy_Typedef_short_hand
#endif
#ifndef Typedef_value
#define Typedef_value doggy_Typedef_value
#endif
#ifndef Typedef_attrs
#define Typedef_attrs doggy_Typedef_attrs
#endif
#ifndef FunctionDef_src_info
#define FunctionDef_src_info doggy_FunctionDef_src_info
#endif
#ifndef FunctionDef_srcinfo
#define FunctionDef_srcinfo doggy_FunctionDef_srcinfo
#endif
#ifndef FunctionDef_loc
#define FunctionDef_loc doggy_FunctionDef_loc
#endif
#ifndef FunctionDef__num
#define FunctionDef__num doggy_FunctionDef__num
#endif
#ifndef FunctionDef_scope
#define FunctionDef_scope doggy_FunctionDef_scope
#endif
#ifndef FunctionDef_old_scope
#define FunctionDef_old_scope doggy_FunctionDef_old_scope
#endif
#ifndef FunctionDef_result
#define FunctionDef_result doggy_FunctionDef_result
#endif
#ifndef FunctionDef_id
#define FunctionDef_id doggy_FunctionDef_id
#endif
#ifndef FunctionDef_id_bind
#define FunctionDef_id_bind doggy_FunctionDef_id_bind
#endif
#ifndef ExtFunc_args
#define ExtFunc_args doggy_ExtFunc_args
#endif
#ifndef machine_description_src_info
#define machine_description_src_info doggy_machine_description_src_info
#endif
#ifndef machine_description_srcinfo
#define machine_description_srcinfo doggy_machine_description_srcinfo
#endif
#ifndef machine_description_loc
#define machine_description_loc doggy_machine_description_loc
#endif
#ifndef machine_description__num
#define machine_description__num doggy_machine_description__num
#endif
#ifndef machine_description_scope
#define machine_description_scope doggy_machine_description_scope
#endif
#ifndef machine_description_old_scope
#define machine_description_old_scope doggy_machine_description_old_scope
#endif
#ifndef machine_description_id
#define machine_description_id doggy_machine_description_id
#endif
#ifndef machine_description_id_bind
#define machine_description_id_bind doggy_machine_description_id_bind
#endif
#ifndef machine_description_defs
#define machine_description_defs doggy_machine_description_defs
#endif
#ifndef machine_description_supports
#define machine_description_supports doggy_machine_description_supports
#endif
#ifndef Operation_def_src_info
#define Operation_def_src_info doggy_Operation_def_src_info
#endif
#ifndef Operation_def_srcinfo
#define Operation_def_srcinfo doggy_Operation_def_srcinfo
#endif
#ifndef Operation_def_loc
#define Operation_def_loc doggy_Operation_def_loc
#endif
#ifndef Operation_def__num
#define Operation_def__num doggy_Operation_def__num
#endif
#ifndef Operation_def_scope
#define Operation_def_scope doggy_Operation_def_scope
#endif
#ifndef Operation_def_old_scope
#define Operation_def_old_scope doggy_Operation_def_old_scope
#endif
#ifndef Operation_def_id
#define Operation_def_id doggy_Operation_def_id
#endif
#ifndef Operation_def_id_bind
#define Operation_def_id_bind doggy_Operation_def_id_bind
#endif
#ifndef Operation_def_types
#define Operation_def_types doggy_Operation_def_types
#endif
#ifndef Operation_def_result
#define Operation_def_result doggy_Operation_def_result
#endif
#ifndef Operation_def_actual_id
#define Operation_def_actual_id doggy_Operation_def_actual_id
#endif
#ifndef Operation_def_descr
#define Operation_def_descr doggy_Operation_def_descr
#endif
#ifndef Operation_def_props
#define Operation_def_props doggy_Operation_def_props
#endif
#ifndef Operation_def_type
#define Operation_def_type doggy_Operation_def_type
#endif
#ifndef Operation_def_src
#define Operation_def_src doggy_Operation_def_src
#endif
#ifndef Operation_def_tgt
#define Operation_def_tgt doggy_Operation_def_tgt
#endif
#ifndef Operation_def_supported
#define Operation_def_supported doggy_Operation_def_supported
#endif
#ifndef Operation_def_mop
#define Operation_def_mop doggy_Operation_def_mop
#endif
#ifndef Operation_def_value
#define Operation_def_value doggy_Operation_def_value
#endif
#ifndef Attributes_src_info
#define Attributes_src_info doggy_Attributes_src_info
#endif
#ifndef Attributes_srcinfo
#define Attributes_srcinfo doggy_Attributes_srcinfo
#endif
#ifndef Attributes_loc
#define Attributes_loc doggy_Attributes_loc
#endif
#ifndef Attributes_ids
#define Attributes_ids doggy_Attributes_ids
#endif
#ifndef Attributes_tail
#define Attributes_tail doggy_Attributes_tail
#endif
#ifndef Attribute_src_info
#define Attribute_src_info doggy_Attribute_src_info
#endif
#ifndef Attribute_srcinfo
#define Attribute_srcinfo doggy_Attribute_srcinfo
#endif
#ifndef Attribute_loc
#define Attribute_loc doggy_Attribute_loc
#endif
#ifndef IdAttr_id
#define IdAttr_id doggy_IdAttr_id
#endif
#ifndef IntAttr_i
#define IntAttr_i doggy_IntAttr_i
#endif
#ifndef Section_src_info
#define Section_src_info doggy_Section_src_info
#endif
#ifndef Section_srcinfo
#define Section_srcinfo doggy_Section_srcinfo
#endif
#ifndef Section_loc
#define Section_loc doggy_Section_loc
#endif
#ifndef FuncSection_funcs
#define FuncSection_funcs doggy_FuncSection_funcs
#endif
#ifndef RuleSection_rules_id
#define RuleSection_rules_id doggy_RuleSection_rules_id
#endif
#ifndef RuleSection_rules
#define RuleSection_rules doggy_RuleSection_rules
#endif
#ifndef Rule_src_info
#define Rule_src_info doggy_Rule_src_info
#endif
#ifndef Rule_srcinfo
#define Rule_srcinfo doggy_Rule_srcinfo
#endif
#ifndef Rule_loc
#define Rule_loc doggy_Rule_loc
#endif
#ifndef Rule__num
#define Rule__num doggy_Rule__num
#endif
#ifndef Rule_scope
#define Rule_scope doggy_Rule_scope
#endif
#ifndef Rule_old_scope
#define Rule_old_scope doggy_Rule_old_scope
#endif
#ifndef Rule_lhs
#define Rule_lhs doggy_Rule_lhs
#endif
#ifndef Rule_rhs
#define Rule_rhs doggy_Rule_rhs
#endif
#ifndef Rule_rules_id
#define Rule_rules_id doggy_Rule_rules_id
#endif
#ifndef Rule_supported
#define Rule_supported doggy_Rule_supported
#endif
#ifndef Rule_rhs_supported
#define Rule_rhs_supported doggy_Rule_rhs_supported
#endif
#ifndef Lhs_src_info
#define Lhs_src_info doggy_Lhs_src_info
#endif
#ifndef Lhs_srcinfo
#define Lhs_srcinfo doggy_Lhs_srcinfo
#endif
#ifndef Lhs_loc
#define Lhs_loc doggy_Lhs_loc
#endif
#ifndef LabeledLhs_id
#define LabeledLhs_id doggy_LabeledLhs_id
#endif
#ifndef Lhs_pat
#define Lhs_pat doggy_Lhs_pat
#endif
#ifndef Func_src_info
#define Func_src_info doggy_Func_src_info
#endif
#ifndef Func_srcinfo
#define Func_srcinfo doggy_Func_srcinfo
#endif
#ifndef Func_loc
#define Func_loc doggy_Func_loc
#endif
#ifndef Func__num
#define Func__num doggy_Func__num
#endif
#ifndef Func_scope
#define Func_scope doggy_Func_scope
#endif
#ifndef Func_old_scope
#define Func_old_scope doggy_Func_old_scope
#endif
#ifndef Func_ext
#define Func_ext doggy_Func_ext
#endif
#ifndef Func_type
#define Func_type doggy_Func_type
#endif
#ifndef Func_id
#define Func_id doggy_Func_id
#endif
#ifndef Func_id_bind
#define Func_id_bind doggy_Func_id_bind
#endif
#ifndef Func_rules
#define Func_rules doggy_Func_rules
#endif
#ifndef Func_args
#define Func_args doggy_Func_args
#endif
#ifndef FuncRule_src_info
#define FuncRule_src_info doggy_FuncRule_src_info
#endif
#ifndef FuncRule_srcinfo
#define FuncRule_srcinfo doggy_FuncRule_srcinfo
#endif
#ifndef FuncRule_loc
#define FuncRule_loc doggy_FuncRule_loc
#endif
#ifndef FuncRule__num
#define FuncRule__num doggy_FuncRule__num
#endif
#ifndef FuncRule_scope
#define FuncRule_scope doggy_FuncRule_scope
#endif
#ifndef FuncRule_old_scope
#define FuncRule_old_scope doggy_FuncRule_old_scope
#endif
#ifndef FuncRule_args
#define FuncRule_args doggy_FuncRule_args
#endif
#ifndef FuncRule_rhs
#define FuncRule_rhs doggy_FuncRule_rhs
#endif
#ifndef FuncRule_supported
#define FuncRule_supported doggy_FuncRule_supported
#endif
#ifndef Argument_src_info
#define Argument_src_info doggy_Argument_src_info
#endif
#ifndef Argument_srcinfo
#define Argument_srcinfo doggy_Argument_srcinfo
#endif
#ifndef Argument_loc
#define Argument_loc doggy_Argument_loc
#endif
#ifndef Argument__num
#define Argument__num doggy_Argument__num
#endif
#ifndef Argument_scope
#define Argument_scope doggy_Argument_scope
#endif
#ifndef Argument_old_scope
#define Argument_old_scope doggy_Argument_old_scope
#endif
#ifndef TypedArg_type
#define TypedArg_type doggy_TypedArg_type
#endif
#ifndef Argument_id
#define Argument_id doggy_Argument_id
#endif
#ifndef Argument_id_bind
#define Argument_id_bind doggy_Argument_id_bind
#endif
#ifndef Argument_pat
#define Argument_pat doggy_Argument_pat
#endif
#ifndef Argument_value
#define Argument_value doggy_Argument_value
#endif
#ifndef ArgPat_src_info
#define ArgPat_src_info doggy_ArgPat_src_info
#endif
#ifndef ArgPat_srcinfo
#define ArgPat_srcinfo doggy_ArgPat_srcinfo
#endif
#ifndef ArgPat_loc
#define ArgPat_loc doggy_ArgPat_loc
#endif
#ifndef PatArg_pat
#define PatArg_pat doggy_PatArg_pat
#endif
#ifndef SetArg_set
#define SetArg_set doggy_SetArg_set
#endif
#ifndef Pattern_src_info
#define Pattern_src_info doggy_Pattern_src_info
#endif
#ifndef Pattern_srcinfo
#define Pattern_srcinfo doggy_Pattern_srcinfo
#endif
#ifndef Pattern_loc
#define Pattern_loc doggy_Pattern_loc
#endif
#ifndef Pattern__num
#define Pattern__num doggy_Pattern__num
#endif
#ifndef Pattern_scope
#define Pattern_scope doggy_Pattern_scope
#endif
#ifndef Pattern_old_scope
#define Pattern_old_scope doggy_Pattern_old_scope
#endif
#ifndef TypedPattern_btype
#define TypedPattern_btype doggy_TypedPattern_btype
#endif
#ifndef TypedPattern_pat
#define TypedPattern_pat doggy_TypedPattern_pat
#endif
#ifndef ConsPattern_lhs
#define ConsPattern_lhs doggy_ConsPattern_lhs
#endif
#ifndef ConsPattern_rhs
#define ConsPattern_rhs doggy_ConsPattern_rhs
#endif
#ifndef DefPattern_ids
#define DefPattern_ids doggy_DefPattern_ids
#endif
#ifndef DefPattern_arg
#define DefPattern_arg doggy_DefPattern_arg
#endif
#ifndef DefPattern_x
#define DefPattern_x doggy_DefPattern_x
#endif
#ifndef DefPattern_use_cnt
#define DefPattern_use_cnt doggy_DefPattern_use_cnt
#endif
#ifndef IdentPattern_id
#define IdentPattern_id doggy_IdentPattern_id
#endif
#ifndef IdentPattern_id_bind
#define IdentPattern_id_bind doggy_IdentPattern_id_bind
#endif
#ifndef IdentPattern_def
#define IdentPattern_def doggy_IdentPattern_def
#endif
#ifndef IdentPattern_use_cnt
#define IdentPattern_use_cnt doggy_IdentPattern_use_cnt
#endif
#ifndef OpPattern_op
#define OpPattern_op doggy_OpPattern_op
#endif
#ifndef OpPattern_args
#define OpPattern_args doggy_OpPattern_args
#endif
#ifndef ConstPattern_cnst
#define ConstPattern_cnst doggy_ConstPattern_cnst
#endif
#ifndef DontCarePattern_expr
#define DontCarePattern_expr doggy_DontCarePattern_expr
#endif
#ifndef Pattern_type
#define Pattern_type doggy_Pattern_type
#endif
#ifndef Pattern__swap
#define Pattern__swap doggy_Pattern__swap
#endif
#ifndef Pattern_swap
#define Pattern_swap doggy_Pattern_swap
#endif
#ifndef Pattern__types
#define Pattern__types doggy_Pattern__types
#endif
#ifndef Pattern_types
#define Pattern_types doggy_Pattern_types
#endif
#ifndef Pattern_value
#define Pattern_value doggy_Pattern_value
#endif
#ifndef Rhs_src_info
#define Rhs_src_info doggy_Rhs_src_info
#endif
#ifndef Rhs_srcinfo
#define Rhs_srcinfo doggy_Rhs_srcinfo
#endif
#ifndef Rhs_loc
#define Rhs_loc doggy_Rhs_loc
#endif
#ifndef PlainRhs_guards
#define PlainRhs_guards doggy_PlainRhs_guards
#endif
#ifndef BlockRhs_rhs
#define BlockRhs_rhs doggy_BlockRhs_rhs
#endif
#ifndef BlockRhs_where
#define BlockRhs_where doggy_BlockRhs_where
#endif
#ifndef Guard_src_info
#define Guard_src_info doggy_Guard_src_info
#endif
#ifndef Guard_srcinfo
#define Guard_srcinfo doggy_Guard_srcinfo
#endif
#ifndef Guard_loc
#define Guard_loc doggy_Guard_loc
#endif
#ifndef Guard__num
#define Guard__num doggy_Guard__num
#endif
#ifndef Guard_scope
#define Guard_scope doggy_Guard_scope
#endif
#ifndef Guard_old_scope
#define Guard_old_scope doggy_Guard_old_scope
#endif
#ifndef Guard_conds
#define Guard_conds doggy_Guard_conds
#endif
#ifndef RhsGuard_rhs
#define RhsGuard_rhs doggy_RhsGuard_rhs
#endif
#ifndef ExprGuard_exprs
#define ExprGuard_exprs doggy_ExprGuard_exprs
#endif
#ifndef Guard_where
#define Guard_where doggy_Guard_where
#endif
#ifndef ExprSeq_src_info
#define ExprSeq_src_info doggy_ExprSeq_src_info
#endif
#ifndef ExprSeq_srcinfo
#define ExprSeq_srcinfo doggy_ExprSeq_srcinfo
#endif
#ifndef ExprSeq_loc
#define ExprSeq_loc doggy_ExprSeq_loc
#endif
#ifndef OneExpr_expr
#define OneExpr_expr doggy_OneExpr_expr
#endif
#ifndef MoreExprs_exprs
#define MoreExprs_exprs doggy_MoreExprs_exprs
#endif
#ifndef Wherepart_src_info
#define Wherepart_src_info doggy_Wherepart_src_info
#endif
#ifndef Wherepart_srcinfo
#define Wherepart_srcinfo doggy_Wherepart_srcinfo
#endif
#ifndef Wherepart_loc
#define Wherepart_loc doggy_Wherepart_loc
#endif
#ifndef Wherepart_defs
#define Wherepart_defs doggy_Wherepart_defs
#endif
#ifndef Applied_operation_src_info
#define Applied_operation_src_info doggy_Applied_operation_src_info
#endif
#ifndef Applied_operation_srcinfo
#define Applied_operation_srcinfo doggy_Applied_operation_srcinfo
#endif
#ifndef Applied_operation_loc
#define Applied_operation_loc doggy_Applied_operation_loc
#endif
#ifndef Applied_operation__num
#define Applied_operation__num doggy_Applied_operation__num
#endif
#ifndef Applied_operation_scope
#define Applied_operation_scope doggy_Applied_operation_scope
#endif
#ifndef Applied_operation_old_scope
#define Applied_operation_old_scope doggy_Applied_operation_old_scope
#endif
#ifndef AppliedOp_op
#define AppliedOp_op doggy_AppliedOp_op
#endif
#ifndef OpSet_ops
#define OpSet_ops doggy_OpSet_ops
#endif
#ifndef Applied_formal_src_info
#define Applied_formal_src_info doggy_Applied_formal_src_info
#endif
#ifndef Applied_formal_srcinfo
#define Applied_formal_srcinfo doggy_Applied_formal_srcinfo
#endif
#ifndef Applied_formal_loc
#define Applied_formal_loc doggy_Applied_formal_loc
#endif
#ifndef Applied_formal__num
#define Applied_formal__num doggy_Applied_formal__num
#endif
#ifndef Applied_formal_scope
#define Applied_formal_scope doggy_Applied_formal_scope
#endif
#ifndef Applied_formal_old_scope
#define Applied_formal_old_scope doggy_Applied_formal_old_scope
#endif
#ifndef Applied_formal_id
#define Applied_formal_id doggy_Applied_formal_id
#endif
#ifndef Applied_formal_ap_bind
#define Applied_formal_ap_bind doggy_Applied_formal_ap_bind
#endif
#ifndef Applied_formal_ap
#define Applied_formal_ap doggy_Applied_formal_ap
#endif
#ifndef Expr_src_info
#define Expr_src_info doggy_Expr_src_info
#endif
#ifndef Expr_srcinfo
#define Expr_srcinfo doggy_Expr_srcinfo
#endif
#ifndef Expr_loc
#define Expr_loc doggy_Expr_loc
#endif
#ifndef Expr__num
#define Expr__num doggy_Expr__num
#endif
#ifndef Expr_scope
#define Expr_scope doggy_Expr_scope
#endif
#ifndef Expr_old_scope
#define Expr_old_scope doggy_Expr_old_scope
#endif
#ifndef Expr_warned
#define Expr_warned doggy_Expr_warned
#endif
#ifndef BinExpr_args
#define BinExpr_args doggy_BinExpr_args
#endif
#ifndef BinExpr_ops
#define BinExpr_ops doggy_BinExpr_ops
#endif
#ifndef ConsExpr_lhs
#define ConsExpr_lhs doggy_ConsExpr_lhs
#endif
#ifndef ConsExpr_rhs
#define ConsExpr_rhs doggy_ConsExpr_rhs
#endif
#ifndef IdentExpr_id
#define IdentExpr_id doggy_IdentExpr_id
#endif
#ifndef IdentExpr_operator_bind
#define IdentExpr_operator_bind doggy_IdentExpr_operator_bind
#endif
#ifndef IdentExpr_operator
#define IdentExpr_operator doggy_IdentExpr_operator
#endif
#ifndef IdentExpr_pattern_bind
#define IdentExpr_pattern_bind doggy_IdentExpr_pattern_bind
#endif
#ifndef IdentExpr_pattern
#define IdentExpr_pattern doggy_IdentExpr_pattern
#endif
#ifndef IdentExpr_ext_bind
#define IdentExpr_ext_bind doggy_IdentExpr_ext_bind
#endif
#ifndef IdentExpr_ext
#define IdentExpr_ext doggy_IdentExpr_ext
#endif
#ifndef IdentExpr_def_bind
#define IdentExpr_def_bind doggy_IdentExpr_def_bind
#endif
#ifndef IdentExpr_def
#define IdentExpr_def doggy_IdentExpr_def
#endif
#ifndef IdentExpr_arg_bind
#define IdentExpr_arg_bind doggy_IdentExpr_arg_bind
#endif
#ifndef IdentExpr_arg
#define IdentExpr_arg doggy_IdentExpr_arg
#endif
#ifndef IdentExpr_use_cnt
#define IdentExpr_use_cnt doggy_IdentExpr_use_cnt
#endif
#ifndef IfExpr_cond
#define IfExpr_cond doggy_IfExpr_cond
#endif
#ifndef IfExpr_thn
#define IfExpr_thn doggy_IfExpr_thn
#endif
#ifndef IfExpr_conds
#define IfExpr_conds doggy_IfExpr_conds
#endif
#ifndef IfExpr_thens
#define IfExpr_thens doggy_IfExpr_thens
#endif
#ifndef IfExpr_els
#define IfExpr_els doggy_IfExpr_els
#endif
#ifndef ConstExpr_cnst
#define ConstExpr_cnst doggy_ConstExpr_cnst
#endif
#ifndef Operation_id
#define Operation_id doggy_Operation_id
#endif
#ifndef Operation_args
#define Operation_args doggy_Operation_args
#endif
#ifndef Operation_operator_bind
#define Operation_operator_bind doggy_Operation_operator_bind
#endif
#ifndef Operation_operator
#define Operation_operator doggy_Operation_operator
#endif
#ifndef Operation_defi_bind
#define Operation_defi_bind doggy_Operation_defi_bind
#endif
#ifndef Operation_defi
#define Operation_defi doggy_Operation_defi
#endif
#ifndef Operation_ext_bind
#define Operation_ext_bind doggy_Operation_ext_bind
#endif
#ifndef Operation_ext
#define Operation_ext doggy_Operation_ext
#endif
#ifndef Operation_func_bind
#define Operation_func_bind doggy_Operation_func_bind
#endif
#ifndef Operation_func
#define Operation_func doggy_Operation_func
#endif
#ifndef ParExpr_expr
#define ParExpr_expr doggy_ParExpr_expr
#endif
#ifndef MonExpr_op
#define MonExpr_op doggy_MonExpr_op
#endif
#ifndef MonExpr_arg
#define MonExpr_arg doggy_MonExpr_arg
#endif
#ifndef Constant_src_info
#define Constant_src_info doggy_Constant_src_info
#endif
#ifndef Constant_srcinfo
#define Constant_srcinfo doggy_Constant_srcinfo
#endif
#ifndef Constant_loc
#define Constant_loc doggy_Constant_loc
#endif
#ifndef IntConst_i
#define IntConst_i doggy_IntConst_i
#endif
#ifndef BoolConst_b
#define BoolConst_b doggy_BoolConst_b
#endif
#ifndef StringConst_s
#define StringConst_s doggy_StringConst_s
#endif
#ifndef Definition_src_info
#define Definition_src_info doggy_Definition_src_info
#endif
#ifndef Definition_srcinfo
#define Definition_srcinfo doggy_Definition_srcinfo
#endif
#ifndef Definition_loc
#define Definition_loc doggy_Definition_loc
#endif
#ifndef Definition__num
#define Definition__num doggy_Definition__num
#endif
#ifndef Definition_scope
#define Definition_scope doggy_Definition_scope
#endif
#ifndef Definition_old_scope
#define Definition_old_scope doggy_Definition_old_scope
#endif
#ifndef Definition_type
#define Definition_type doggy_Definition_type
#endif
#ifndef Definition_id
#define Definition_id doggy_Definition_id
#endif
#ifndef Definition_id_bind
#define Definition_id_bind doggy_Definition_id_bind
#endif
#ifndef Definition_expr
#define Definition_expr doggy_Definition_expr
#endif
#ifndef Definition_value
#define Definition_value doggy_Definition_value
#endif
#ifndef Definition_order
#define Definition_order doggy_Definition_order
#endif
#ifndef Definition_use_cnt
#define Definition_use_cnt doggy_Definition_use_cnt
#endif
#ifndef Type_src_info
#define Type_src_info doggy_Type_src_info
#endif
#ifndef Type_srcinfo
#define Type_srcinfo doggy_Type_srcinfo
#endif
#ifndef Type_loc
#define Type_loc doggy_Type_loc
#endif
#ifndef Type__num
#define Type__num doggy_Type__num
#endif
#ifndef Type_scope
#define Type_scope doggy_Type_scope
#endif
#ifndef Type_old_scope
#define Type_old_scope doggy_Type_old_scope
#endif
#ifndef EdgeType_types
#define EdgeType_types doggy_EdgeType_types
#endif
#ifndef TupleType_types
#define TupleType_types doggy_TupleType_types
#endif
#ifndef IdentType_type_id
#define IdentType_type_id doggy_IdentType_type_id
#endif
#ifndef IdentType_type_bind
#define IdentType_type_bind doggy_IdentType_type_bind
#endif
#ifndef IdentType_type
#define IdentType_type doggy_IdentType_type
#endif
#ifndef OprType_args
#define OprType_args doggy_OprType_args
#endif
#ifndef PointerType_base
#define PointerType_base doggy_PointerType_base
#endif
#ifndef RangeType_lo
#define RangeType_lo doggy_RangeType_lo
#endif
#ifndef RangeType_hi
#define RangeType_hi doggy_RangeType_hi
#endif
#ifndef RangeType_step
#define RangeType_step doggy_RangeType_step
#endif
#ifndef FRangeType_f
#define FRangeType_f doggy_FRangeType_f
#endif
#ifndef Num_src_info
#define Num_src_info doggy_Num_src_info
#endif
#ifndef Num_srcinfo
#define Num_srcinfo doggy_Num_srcinfo
#endif
#ifndef Num_loc
#define Num_loc doggy_Num_loc
#endif
#ifndef Num_neg
#define Num_neg doggy_Num_neg
#endif
#ifndef Num_i
#define Num_i doggy_Num_i
#endif
#ifndef Num_negate
#define Num_negate doggy_Num_negate
#endif
#ifndef IdInt_src_info
#define IdInt_src_info doggy_IdInt_src_info
#endif
#ifndef IdInt_srcinfo
#define IdInt_srcinfo doggy_IdInt_srcinfo
#endif
#ifndef IdInt_loc
#define IdInt_loc doggy_IdInt_loc
#endif
#ifndef IsId_id
#define IsId_id doggy_IsId_id
#endif
#ifndef IsInt_i
#define IsInt_i doggy_IsInt_i
#endif
#ifndef Path_src_info
#define Path_src_info doggy_Path_src_info
#endif
#ifndef Path_srcinfo
#define Path_srcinfo doggy_Path_srcinfo
#endif
#ifndef Path_loc
#define Path_loc doggy_Path_loc
#endif
#ifndef Path_data
#define Path_data doggy_Path_data
#endif
#ifndef Path_type
#define Path_type doggy_Path_type
#endif
#ifndef Path_next
#define Path_next doggy_Path_next
#endif
#ifndef ActualOp_src_info
#define ActualOp_src_info doggy_ActualOp_src_info
#endif
#ifndef ActualOp_srcinfo
#define ActualOp_srcinfo doggy_ActualOp_srcinfo
#endif
#ifndef ActualOp_loc
#define ActualOp_loc doggy_ActualOp_loc
#endif
#ifndef ActualOp_location
#define ActualOp_location doggy_ActualOp_location
#endif
#ifndef ActualOp_id
#define ActualOp_id doggy_ActualOp_id
#endif
#ifndef ActualOp_formals
#define ActualOp_formals doggy_ActualOp_formals
#endif
#ifndef ActualOp_overloaded
#define ActualOp_overloaded doggy_ActualOp_overloaded
#endif
#ifndef ActualOp_src
#define ActualOp_src doggy_ActualOp_src
#endif
#ifndef ActualOp_tgt
#define ActualOp_tgt doggy_ActualOp_tgt
#endif
#ifndef TypePair_src_info
#define TypePair_src_info doggy_TypePair_src_info
#endif
#ifndef TypePair_srcinfo
#define TypePair_srcinfo doggy_TypePair_srcinfo
#endif
#ifndef TypePair_loc
#define TypePair_loc doggy_TypePair_loc
#endif
#ifndef TypePair_t1
#define TypePair_t1 doggy_TypePair_t1
#endif
#ifndef TypePair_t2
#define TypePair_t2 doggy_TypePair_t2
#endif
#ifndef Opat_src_info
#define Opat_src_info doggy_Opat_src_info
#endif
#ifndef Opat_srcinfo
#define Opat_srcinfo doggy_Opat_srcinfo
#endif
#ifndef Opat_loc
#define Opat_loc doggy_Opat_loc
#endif
#ifndef Opat_memo_link
#define Opat_memo_link doggy_Opat_memo_link
#endif
#ifndef Opat_args
#define Opat_args doggy_Opat_args
#endif
#ifndef Opat_result
#define Opat_result doggy_Opat_result
#endif
#ifndef Opat_num
#define Opat_num doggy_Opat_num
#endif
#ifndef Format_src_info
#define Format_src_info doggy_Format_src_info
#endif
#ifndef Format_srcinfo
#define Format_srcinfo doggy_Format_srcinfo
#endif
#ifndef Format_loc
#define Format_loc doggy_Format_loc
#endif
#ifndef Format_memo_link
#define Format_memo_link doggy_Format_memo_link
#endif
#ifndef Format_args
#define Format_args doggy_Format_args
#endif
#ifndef Format_result
#define Format_result doggy_Format_result
#endif
#ifndef Format_swap
#define Format_swap doggy_Format_swap
#endif
#ifndef Format_num
#define Format_num doggy_Format_num
#endif
#ifndef dummy_type_src_info
#define dummy_type_src_info doggy_dummy_type_src_info
#endif
#ifndef dummy_type_srcinfo
#define dummy_type_srcinfo doggy_dummy_type_srcinfo
#endif
#ifndef dummy_type_loc
#define dummy_type_loc doggy_dummy_type_loc
#endif
#ifndef dummy_type_a
#define dummy_type_a doggy_dummy_type_a
#endif
#ifndef dummy_type_x
#define dummy_type_x doggy_dummy_type_x
#endif
#ifndef dummy_type_y
#define dummy_type_y doggy_dummy_type_y
#endif
#ifndef dummy_type_z
#define dummy_type_z doggy_dummy_type_z
#endif
#ifndef dummy_type_b
#define dummy_type_b doggy_dummy_type_b
#endif
#ifndef Scope_next
#define Scope_next doggy_Scope_next
#endif
#ifndef Scope__self
#define Scope__self doggy_Scope__self
#endif
#ifndef Scope__end
#define Scope__end doggy_Scope__end
#endif
#ifndef OpSetScope_data
#define OpSetScope_data doggy_OpSetScope_data
#endif
#ifndef AppliedOpScope_data
#define AppliedOpScope_data doggy_AppliedOpScope_data
#endif
#ifndef ExprGuardScope_data
#define ExprGuardScope_data doggy_ExprGuardScope_data
#endif
#ifndef RhsGuardScope_data
#define RhsGuardScope_data doggy_RhsGuardScope_data
#endif
#ifndef FuncRuleScope_data
#define FuncRuleScope_data doggy_FuncRuleScope_data
#endif
#ifndef RuleScope_data
#define RuleScope_data doggy_RuleScope_data
#endif
#ifndef machine_descriptionScope_data
#define machine_descriptionScope_data doggy_machine_descriptionScope_data
#endif
#ifndef List_Num_data
#define List_Num_data List_doggy_Num_data
#endif
#ifndef List_Num_next
#define List_Num_next List_doggy_Num_next
#endif
#ifndef List_List_TypePair_data
#define List_List_TypePair_data List_List_doggy_TypePair_data
#endif
#ifndef List_List_TypePair_next
#define List_List_TypePair_next List_List_doggy_TypePair_next
#endif
#ifndef List_TypePair_data
#define List_TypePair_data List_doggy_TypePair_data
#endif
#ifndef List_TypePair_next
#define List_TypePair_next List_doggy_TypePair_next
#endif
#ifndef List_ActualOp_data
#define List_ActualOp_data List_doggy_ActualOp_data
#endif
#ifndef List_ActualOp_next
#define List_ActualOp_next List_doggy_ActualOp_next
#endif
#ifndef List_List_Type_data
#define List_List_Type_data List_List_doggy_Type_data
#endif
#ifndef List_List_Type_next
#define List_List_Type_next List_List_doggy_Type_next
#endif
#ifndef List_Ident_data
#define List_Ident_data List_Ident_data
#endif
#ifndef List_Ident_next
#define List_Ident_next List_Ident_next
#endif
#ifndef List_Operator_data
#define List_Operator_data List_doggy_Operator_data
#endif
#ifndef List_Operator_next
#define List_Operator_next List_doggy_Operator_next
#endif
#ifndef List_Definition_data
#define List_Definition_data List_doggy_Definition_data
#endif
#ifndef List_Definition_next
#define List_Definition_next List_doggy_Definition_next
#endif
#ifndef List_Expr_data
#define List_Expr_data List_doggy_Expr_data
#endif
#ifndef List_Expr_next
#define List_Expr_next List_doggy_Expr_next
#endif
#ifndef List_Guard_data
#define List_Guard_data List_doggy_Guard_data
#endif
#ifndef List_Guard_next
#define List_Guard_next List_doggy_Guard_next
#endif
#ifndef List_Pattern_data
#define List_Pattern_data List_doggy_Pattern_data
#endif
#ifndef List_Pattern_next
#define List_Pattern_next List_doggy_Pattern_next
#endif
#ifndef List_Argument_data
#define List_Argument_data List_doggy_Argument_data
#endif
#ifndef List_Argument_next
#define List_Argument_next List_doggy_Argument_next
#endif
#ifndef List_FuncRule_data
#define List_FuncRule_data List_doggy_FuncRule_data
#endif
#ifndef List_FuncRule_next
#define List_FuncRule_next List_doggy_FuncRule_next
#endif
#ifndef List_Attribute_data
#define List_Attribute_data List_doggy_Attribute_data
#endif
#ifndef List_Attribute_next
#define List_Attribute_next List_doggy_Attribute_next
#endif
#ifndef List_Property_data
#define List_Property_data List_doggy_Property_data
#endif
#ifndef List_Property_next
#define List_Property_next List_doggy_Property_next
#endif
#ifndef List_Applied_formal_data
#define List_Applied_formal_data List_doggy_Applied_formal_data
#endif
#ifndef List_Applied_formal_next
#define List_Applied_formal_next List_doggy_Applied_formal_next
#endif
#ifndef List_Operation_def_data
#define List_Operation_def_data List_doggy_Operation_def_data
#endif
#ifndef List_Operation_def_next
#define List_Operation_def_next List_doggy_Operation_def_next
#endif
#ifndef List_Type_data
#define List_Type_data List_doggy_Type_data
#endif
#ifndef List_Type_next
#define List_Type_next List_doggy_Type_next
#endif
#ifndef List_Rule_data
#define List_Rule_data List_doggy_Rule_data
#endif
#ifndef List_Rule_next
#define List_Rule_next List_doggy_Rule_next
#endif
#ifndef List_Func_data
#define List_Func_data List_doggy_Func_data
#endif
#ifndef List_Func_next
#define List_Func_next List_doggy_Func_next
#endif
#ifndef List_Section_data
#define List_Section_data List_doggy_Section_data
#endif
#ifndef List_Section_next
#define List_Section_next List_doggy_Section_next
#endif
#ifndef List_FunctionDef_data
#define List_FunctionDef_data List_doggy_FunctionDef_data
#endif
#ifndef List_FunctionDef_next
#define List_FunctionDef_next List_doggy_FunctionDef_next
#endif
#ifndef List_Typedef_data
#define List_Typedef_data List_doggy_Typedef_data
#endif
#ifndef List_Typedef_next
#define List_Typedef_next List_doggy_Typedef_next
#endif

/* Abbreviations for doggy.h */

#ifndef Create_doggy
#define Create_doggy Create_doggy_doggy
#endif
#ifndef Create_Typedef
#define Create_Typedef Create_doggy_Typedef
#endif
#ifndef Create_ExtVar
#define Create_ExtVar Create_doggy_ExtVar
#endif
#ifndef Create_ExtFunc
#define Create_ExtFunc Create_doggy_ExtFunc
#endif
#ifndef Create_machine_description
#define Create_machine_description Create_doggy_machine_description
#endif
#ifndef Create_Operation_def
#define Create_Operation_def Create_doggy_Operation_def
#endif
#ifndef Create_Attributes
#define Create_Attributes Create_doggy_Attributes
#endif
#ifndef Create_IntAttr
#define Create_IntAttr Create_doggy_IntAttr
#endif
#ifndef Create_OpAttr
#define Create_OpAttr Create_doggy_OpAttr
#endif
#ifndef Create_IdAttr
#define Create_IdAttr Create_doggy_IdAttr
#endif
#ifndef Create_RuleSection
#define Create_RuleSection Create_doggy_RuleSection
#endif
#ifndef Create_FuncSection
#define Create_FuncSection Create_doggy_FuncSection
#endif
#ifndef Create_Rule
#define Create_Rule Create_doggy_Rule
#endif
#ifndef Create_UnLabeledLhs
#define Create_UnLabeledLhs Create_doggy_UnLabeledLhs
#endif
#ifndef Create_LabeledLhs
#define Create_LabeledLhs Create_doggy_LabeledLhs
#endif
#ifndef Create_Func
#define Create_Func Create_doggy_Func
#endif
#ifndef Create_FuncRule
#define Create_FuncRule Create_doggy_FuncRule
#endif
#ifndef Create_UnTypedArg
#define Create_UnTypedArg Create_doggy_UnTypedArg
#endif
#ifndef Create_TypedArg
#define Create_TypedArg Create_doggy_TypedArg
#endif
#ifndef Create_SetArg
#define Create_SetArg Create_doggy_SetArg
#endif
#ifndef Create_PatArg
#define Create_PatArg Create_doggy_PatArg
#endif
#ifndef Create_DontCarePattern
#define Create_DontCarePattern Create_doggy_DontCarePattern
#endif
#ifndef Create_NullPattern
#define Create_NullPattern Create_doggy_NullPattern
#endif
#ifndef Create_ConstPattern
#define Create_ConstPattern Create_doggy_ConstPattern
#endif
#ifndef Create_OpPattern
#define Create_OpPattern Create_doggy_OpPattern
#endif
#ifndef Create_IdentPattern
#define Create_IdentPattern Create_doggy_IdentPattern
#endif
#ifndef Create_DefPattern
#define Create_DefPattern Create_doggy_DefPattern
#endif
#ifndef Create_ConsPattern
#define Create_ConsPattern Create_doggy_ConsPattern
#endif
#ifndef Create_TypedPattern
#define Create_TypedPattern Create_doggy_TypedPattern
#endif
#ifndef Create_BlockRhs
#define Create_BlockRhs Create_doggy_BlockRhs
#endif
#ifndef Create_PlainRhs
#define Create_PlainRhs Create_doggy_PlainRhs
#endif
#ifndef Create_ExprGuard
#define Create_ExprGuard Create_doggy_ExprGuard
#endif
#ifndef Create_RhsGuard
#define Create_RhsGuard Create_doggy_RhsGuard
#endif
#ifndef Create_MoreExprs
#define Create_MoreExprs Create_doggy_MoreExprs
#endif
#ifndef Create_OneExpr
#define Create_OneExpr Create_doggy_OneExpr
#endif
#ifndef Create_Wherepart
#define Create_Wherepart Create_doggy_Wherepart
#endif
#ifndef Create_OpSet
#define Create_OpSet Create_doggy_OpSet
#endif
#ifndef Create_AppliedOp
#define Create_AppliedOp Create_doggy_AppliedOp
#endif
#ifndef Create_AnyOp
#define Create_AnyOp Create_doggy_AnyOp
#endif
#ifndef Create_Applied_formal
#define Create_Applied_formal Create_doggy_Applied_formal
#endif
#ifndef Create_MonExpr
#define Create_MonExpr Create_doggy_MonExpr
#endif
#ifndef Create_ParExpr
#define Create_ParExpr Create_doggy_ParExpr
#endif
#ifndef Create_Operation
#define Create_Operation Create_doggy_Operation
#endif
#ifndef Create_ConstExpr
#define Create_ConstExpr Create_doggy_ConstExpr
#endif
#ifndef Create_IfExpr
#define Create_IfExpr Create_doggy_IfExpr
#endif
#ifndef Create_IdentExpr
#define Create_IdentExpr Create_doggy_IdentExpr
#endif
#ifndef Create_ConsExpr
#define Create_ConsExpr Create_doggy_ConsExpr
#endif
#ifndef Create_BinExpr
#define Create_BinExpr Create_doggy_BinExpr
#endif
#ifndef Create_NullConst
#define Create_NullConst Create_doggy_NullConst
#endif
#ifndef Create_StringConst
#define Create_StringConst Create_doggy_StringConst
#endif
#ifndef Create_BoolConst
#define Create_BoolConst Create_doggy_BoolConst
#endif
#ifndef Create_IntConst
#define Create_IntConst Create_doggy_IntConst
#endif
#ifndef Create_Definition
#define Create_Definition Create_doggy_Definition
#endif
#ifndef Create_FRangeType
#define Create_FRangeType Create_doggy_FRangeType
#endif
#ifndef Create_RangeType
#define Create_RangeType Create_doggy_RangeType
#endif
#ifndef Create_PointerType
#define Create_PointerType Create_doggy_PointerType
#endif
#ifndef Create_OprType
#define Create_OprType Create_doggy_OprType
#endif
#ifndef Create_IdentType
#define Create_IdentType Create_doggy_IdentType
#endif
#ifndef Create_TupleType
#define Create_TupleType Create_doggy_TupleType
#endif
#ifndef Create_EdgeType
#define Create_EdgeType Create_doggy_EdgeType
#endif
#ifndef Create_Num
#define Create_Num Create_doggy_Num
#endif
#ifndef Create_IsInt
#define Create_IsInt Create_doggy_IsInt
#endif
#ifndef Create_IsId
#define Create_IsId Create_doggy_IsId
#endif
#ifndef Create_Path
#define Create_Path Create_doggy_Path
#endif
#ifndef Create_ActualOp
#define Create_ActualOp Create_doggy_ActualOp
#endif
#ifndef Create_TypePair
#define Create_TypePair Create_doggy_TypePair
#endif
#ifndef Create_Opat
#define Create_Opat Create_doggy_Opat
#endif
#ifndef Create_Format
#define Create_Format Create_doggy_Format
#endif
#ifndef Create_dummy_type
#define Create_dummy_type Create_doggy_dummy_type
#endif
#ifndef Create_machine_descriptionScope
#define Create_machine_descriptionScope Create_doggy_machine_descriptionScope
#endif
#ifndef Create_RuleScope
#define Create_RuleScope Create_doggy_RuleScope
#endif
#ifndef Create_FuncRuleScope
#define Create_FuncRuleScope Create_doggy_FuncRuleScope
#endif
#ifndef Create_RhsGuardScope
#define Create_RhsGuardScope Create_doggy_RhsGuardScope
#endif
#ifndef Create_ExprGuardScope
#define Create_ExprGuardScope Create_doggy_ExprGuardScope
#endif
#ifndef Create_AppliedOpScope
#define Create_AppliedOpScope Create_doggy_AppliedOpScope
#endif
#ifndef Create_OpSetScope
#define Create_OpSetScope Create_doggy_OpSetScope
#endif
#ifndef Create_List_Num
#define Create_List_Num Create_List_doggy_Num
#endif
#ifndef List_Num_size
#define List_Num_size List_doggy_Num_size
#endif
#ifndef Create_List_List_TypePair
#define Create_List_List_TypePair Create_List_List_doggy_TypePair
#endif
#ifndef List_List_TypePair_size
#define List_List_TypePair_size List_List_doggy_TypePair_size
#endif
#ifndef Create_List_TypePair
#define Create_List_TypePair Create_List_doggy_TypePair
#endif
#ifndef List_TypePair_size
#define List_TypePair_size List_doggy_TypePair_size
#endif
#ifndef Create_List_ActualOp
#define Create_List_ActualOp Create_List_doggy_ActualOp
#endif
#ifndef List_ActualOp_size
#define List_ActualOp_size List_doggy_ActualOp_size
#endif
#ifndef Create_List_List_Type
#define Create_List_List_Type Create_List_List_doggy_Type
#endif
#ifndef List_List_Type_size
#define List_List_Type_size List_List_doggy_Type_size
#endif
#ifndef Create_List_Operator
#define Create_List_Operator Create_List_doggy_Operator
#endif
#ifndef List_Operator_size
#define List_Operator_size List_doggy_Operator_size
#endif
#ifndef Create_List_Definition
#define Create_List_Definition Create_List_doggy_Definition
#endif
#ifndef List_Definition_size
#define List_Definition_size List_doggy_Definition_size
#endif
#ifndef Create_List_Expr
#define Create_List_Expr Create_List_doggy_Expr
#endif
#ifndef List_Expr_size
#define List_Expr_size List_doggy_Expr_size
#endif
#ifndef Create_List_Guard
#define Create_List_Guard Create_List_doggy_Guard
#endif
#ifndef List_Guard_size
#define List_Guard_size List_doggy_Guard_size
#endif
#ifndef Create_List_Pattern
#define Create_List_Pattern Create_List_doggy_Pattern
#endif
#ifndef List_Pattern_size
#define List_Pattern_size List_doggy_Pattern_size
#endif
#ifndef Create_List_Argument
#define Create_List_Argument Create_List_doggy_Argument
#endif
#ifndef List_Argument_size
#define List_Argument_size List_doggy_Argument_size
#endif
#ifndef Create_List_FuncRule
#define Create_List_FuncRule Create_List_doggy_FuncRule
#endif
#ifndef List_FuncRule_size
#define List_FuncRule_size List_doggy_FuncRule_size
#endif
#ifndef Create_List_Attribute
#define Create_List_Attribute Create_List_doggy_Attribute
#endif
#ifndef List_Attribute_size
#define List_Attribute_size List_doggy_Attribute_size
#endif
#ifndef Create_List_Property
#define Create_List_Property Create_List_doggy_Property
#endif
#ifndef List_Property_size
#define List_Property_size List_doggy_Property_size
#endif
#ifndef Create_List_Applied_formal
#define Create_List_Applied_formal Create_List_doggy_Applied_formal
#endif
#ifndef List_Applied_formal_size
#define List_Applied_formal_size List_doggy_Applied_formal_size
#endif
#ifndef Create_List_Operation_def
#define Create_List_Operation_def Create_List_doggy_Operation_def
#endif
#ifndef List_Operation_def_size
#define List_Operation_def_size List_doggy_Operation_def_size
#endif
#ifndef Create_List_Type
#define Create_List_Type Create_List_doggy_Type
#endif
#ifndef List_Type_size
#define List_Type_size List_doggy_Type_size
#endif
#ifndef Create_List_Rule
#define Create_List_Rule Create_List_doggy_Rule
#endif
#ifndef List_Rule_size
#define List_Rule_size List_doggy_Rule_size
#endif
#ifndef Create_List_Func
#define Create_List_Func Create_List_doggy_Func
#endif
#ifndef List_Func_size
#define List_Func_size List_doggy_Func_size
#endif
#ifndef Create_List_Section
#define Create_List_Section Create_List_doggy_Section
#endif
#ifndef List_Section_size
#define List_Section_size List_doggy_Section_size
#endif
#ifndef Create_List_FunctionDef
#define Create_List_FunctionDef Create_List_doggy_FunctionDef
#endif
#ifndef List_FunctionDef_size
#define List_FunctionDef_size List_doggy_FunctionDef_size
#endif
#ifndef Create_List_Typedef
#define Create_List_Typedef Create_List_doggy_Typedef
#endif
#ifndef List_Typedef_size
#define List_Typedef_size List_doggy_Typedef_size
#endif
#ifndef s_TraverseTable
#define s_TraverseTable s_doggy_TraverseTable
#endif
#ifndef TraverseTable
#define TraverseTable doggy_TraverseTable
#endif
#ifndef Traverse_Operator
#define Traverse_Operator Traverse_doggy_Operator
#endif
#ifndef Traverse_MonOp
#define Traverse_MonOp Traverse_doggy_MonOp
#endif
#ifndef Traverse_Property
#define Traverse_Property Traverse_doggy_Property
#endif
#ifndef Traverse_doggy
#define Traverse_doggy Traverse_doggy_doggy
#endif
#ifndef Traverse_Typedef
#define Traverse_Typedef Traverse_doggy_Typedef
#endif
#ifndef Traverse_FunctionDef
#define Traverse_FunctionDef Traverse_doggy_FunctionDef
#endif
#ifndef Traverse_machine_description
#define Traverse_machine_description Traverse_doggy_machine_description
#endif
#ifndef Traverse_Operation_def
#define Traverse_Operation_def Traverse_doggy_Operation_def
#endif
#ifndef Traverse_Attributes
#define Traverse_Attributes Traverse_doggy_Attributes
#endif
#ifndef Traverse_Attribute
#define Traverse_Attribute Traverse_doggy_Attribute
#endif
#ifndef Traverse_Section
#define Traverse_Section Traverse_doggy_Section
#endif
#ifndef Traverse_Rule
#define Traverse_Rule Traverse_doggy_Rule
#endif
#ifndef Traverse_Lhs
#define Traverse_Lhs Traverse_doggy_Lhs
#endif
#ifndef Traverse_Func
#define Traverse_Func Traverse_doggy_Func
#endif
#ifndef Traverse_FuncRule
#define Traverse_FuncRule Traverse_doggy_FuncRule
#endif
#ifndef Traverse_Argument
#define Traverse_Argument Traverse_doggy_Argument
#endif
#ifndef Traverse_ArgPat
#define Traverse_ArgPat Traverse_doggy_ArgPat
#endif
#ifndef Traverse_Pattern
#define Traverse_Pattern Traverse_doggy_Pattern
#endif
#ifndef Traverse_Rhs
#define Traverse_Rhs Traverse_doggy_Rhs
#endif
#ifndef Traverse_Guard
#define Traverse_Guard Traverse_doggy_Guard
#endif
#ifndef Traverse_ExprSeq
#define Traverse_ExprSeq Traverse_doggy_ExprSeq
#endif
#ifndef Traverse_Wherepart
#define Traverse_Wherepart Traverse_doggy_Wherepart
#endif
#ifndef Traverse_Applied_operation
#define Traverse_Applied_operation Traverse_doggy_Applied_operation
#endif
#ifndef Traverse_Applied_formal
#define Traverse_Applied_formal Traverse_doggy_Applied_formal
#endif
#ifndef Traverse_Expr
#define Traverse_Expr Traverse_doggy_Expr
#endif
#ifndef Traverse_Constant
#define Traverse_Constant Traverse_doggy_Constant
#endif
#ifndef Traverse_Definition
#define Traverse_Definition Traverse_doggy_Definition
#endif
#ifndef Traverse_Type
#define Traverse_Type Traverse_doggy_Type
#endif
#ifndef Traverse_Num
#define Traverse_Num Traverse_doggy_Num
#endif
#ifndef Traverse_IdInt
#define Traverse_IdInt Traverse_doggy_IdInt
#endif
#ifndef Traverse_Path
#define Traverse_Path Traverse_doggy_Path
#endif
#ifndef Traverse_ActualOp
#define Traverse_ActualOp Traverse_doggy_ActualOp
#endif
#ifndef Traverse_TypePair
#define Traverse_TypePair Traverse_doggy_TypePair
#endif
#ifndef Traverse_Opat
#define Traverse_Opat Traverse_doggy_Opat
#endif
#ifndef Traverse_Format
#define Traverse_Format Traverse_doggy_Format
#endif
#ifndef Traverse_dummy_type
#define Traverse_dummy_type Traverse_doggy_dummy_type
#endif
#ifndef Traverse_Scope
#define Traverse_Scope Traverse_doggy_Scope
#endif
#ifndef Traverse_List_Num
#define Traverse_List_Num Traverse_List_doggy_Num
#endif
#ifndef Traverse_List_List_TypePair
#define Traverse_List_List_TypePair Traverse_List_List_doggy_TypePair
#endif
#ifndef Traverse_List_TypePair
#define Traverse_List_TypePair Traverse_List_doggy_TypePair
#endif
#ifndef Traverse_List_ActualOp
#define Traverse_List_ActualOp Traverse_List_doggy_ActualOp
#endif
#ifndef Traverse_List_List_Type
#define Traverse_List_List_Type Traverse_List_List_doggy_Type
#endif
#ifndef Traverse_List_Operator
#define Traverse_List_Operator Traverse_List_doggy_Operator
#endif
#ifndef Traverse_List_Definition
#define Traverse_List_Definition Traverse_List_doggy_Definition
#endif
#ifndef Traverse_List_Expr
#define Traverse_List_Expr Traverse_List_doggy_Expr
#endif
#ifndef Traverse_List_Guard
#define Traverse_List_Guard Traverse_List_doggy_Guard
#endif
#ifndef Traverse_List_Pattern
#define Traverse_List_Pattern Traverse_List_doggy_Pattern
#endif
#ifndef Traverse_List_Argument
#define Traverse_List_Argument Traverse_List_doggy_Argument
#endif
#ifndef Traverse_List_FuncRule
#define Traverse_List_FuncRule Traverse_List_doggy_FuncRule
#endif
#ifndef Traverse_List_Attribute
#define Traverse_List_Attribute Traverse_List_doggy_Attribute
#endif
#ifndef Traverse_List_Property
#define Traverse_List_Property Traverse_List_doggy_Property
#endif
#ifndef Traverse_List_Applied_formal
#define Traverse_List_Applied_formal Traverse_List_doggy_Applied_formal
#endif
#ifndef Traverse_List_Operation_def
#define Traverse_List_Operation_def Traverse_List_doggy_Operation_def
#endif
#ifndef Traverse_List_Type
#define Traverse_List_Type Traverse_List_doggy_Type
#endif
#ifndef Traverse_List_Rule
#define Traverse_List_Rule Traverse_List_doggy_Rule
#endif
#ifndef Traverse_List_Func
#define Traverse_List_Func Traverse_List_doggy_Func
#endif
#ifndef Traverse_List_Section
#define Traverse_List_Section Traverse_List_doggy_Section
#endif
#ifndef Traverse_List_FunctionDef
#define Traverse_List_FunctionDef Traverse_List_doggy_FunctionDef
#endif
#ifndef Traverse_List_Typedef
#define Traverse_List_Typedef Traverse_List_doggy_Typedef
#endif
#ifndef s_void_TraverseTable
#define s_void_TraverseTable s_void_doggy_TraverseTable
#endif
#ifndef void_TraverseTable
#define void_TraverseTable void_doggy_TraverseTable
#endif
#ifndef Traverse_void_Operator
#define Traverse_void_Operator Traverse_void_doggy_Operator
#endif
#ifndef Traverse_void_MonOp
#define Traverse_void_MonOp Traverse_void_doggy_MonOp
#endif
#ifndef Traverse_void_Property
#define Traverse_void_Property Traverse_void_doggy_Property
#endif
#ifndef Traverse_void_doggy
#define Traverse_void_doggy Traverse_void_doggy_doggy
#endif
#ifndef Traverse_void_Typedef
#define Traverse_void_Typedef Traverse_void_doggy_Typedef
#endif
#ifndef Traverse_void_FunctionDef
#define Traverse_void_FunctionDef Traverse_void_doggy_FunctionDef
#endif
#ifndef Traverse_void_machine_description
#define Traverse_void_machine_description Traverse_void_doggy_machine_description
#endif
#ifndef Traverse_void_Operation_def
#define Traverse_void_Operation_def Traverse_void_doggy_Operation_def
#endif
#ifndef Traverse_void_Attributes
#define Traverse_void_Attributes Traverse_void_doggy_Attributes
#endif
#ifndef Traverse_void_Attribute
#define Traverse_void_Attribute Traverse_void_doggy_Attribute
#endif
#ifndef Traverse_void_Section
#define Traverse_void_Section Traverse_void_doggy_Section
#endif
#ifndef Traverse_void_Rule
#define Traverse_void_Rule Traverse_void_doggy_Rule
#endif
#ifndef Traverse_void_Lhs
#define Traverse_void_Lhs Traverse_void_doggy_Lhs
#endif
#ifndef Traverse_void_Func
#define Traverse_void_Func Traverse_void_doggy_Func
#endif
#ifndef Traverse_void_FuncRule
#define Traverse_void_FuncRule Traverse_void_doggy_FuncRule
#endif
#ifndef Traverse_void_Argument
#define Traverse_void_Argument Traverse_void_doggy_Argument
#endif
#ifndef Traverse_void_ArgPat
#define Traverse_void_ArgPat Traverse_void_doggy_ArgPat
#endif
#ifndef Traverse_void_Pattern
#define Traverse_void_Pattern Traverse_void_doggy_Pattern
#endif
#ifndef Traverse_void_Rhs
#define Traverse_void_Rhs Traverse_void_doggy_Rhs
#endif
#ifndef Traverse_void_Guard
#define Traverse_void_Guard Traverse_void_doggy_Guard
#endif
#ifndef Traverse_void_ExprSeq
#define Traverse_void_ExprSeq Traverse_void_doggy_ExprSeq
#endif
#ifndef Traverse_void_Wherepart
#define Traverse_void_Wherepart Traverse_void_doggy_Wherepart
#endif
#ifndef Traverse_void_Applied_operation
#define Traverse_void_Applied_operation Traverse_void_doggy_Applied_operation
#endif
#ifndef Traverse_void_Applied_formal
#define Traverse_void_Applied_formal Traverse_void_doggy_Applied_formal
#endif
#ifndef Traverse_void_Expr
#define Traverse_void_Expr Traverse_void_doggy_Expr
#endif
#ifndef Traverse_void_Constant
#define Traverse_void_Constant Traverse_void_doggy_Constant
#endif
#ifndef Traverse_void_Definition
#define Traverse_void_Definition Traverse_void_doggy_Definition
#endif
#ifndef Traverse_void_Type
#define Traverse_void_Type Traverse_void_doggy_Type
#endif
#ifndef Traverse_void_Num
#define Traverse_void_Num Traverse_void_doggy_Num
#endif
#ifndef Traverse_void_IdInt
#define Traverse_void_IdInt Traverse_void_doggy_IdInt
#endif
#ifndef Traverse_void_Path
#define Traverse_void_Path Traverse_void_doggy_Path
#endif
#ifndef Traverse_void_ActualOp
#define Traverse_void_ActualOp Traverse_void_doggy_ActualOp
#endif
#ifndef Traverse_void_TypePair
#define Traverse_void_TypePair Traverse_void_doggy_TypePair
#endif
#ifndef Traverse_void_Opat
#define Traverse_void_Opat Traverse_void_doggy_Opat
#endif
#ifndef Traverse_void_Format
#define Traverse_void_Format Traverse_void_doggy_Format
#endif
#ifndef Traverse_void_dummy_type
#define Traverse_void_dummy_type Traverse_void_doggy_dummy_type
#endif
#ifndef Traverse_void_Scope
#define Traverse_void_Scope Traverse_void_doggy_Scope
#endif
#ifndef Traverse_void_List_Num
#define Traverse_void_List_Num Traverse_void_List_doggy_Num
#endif
#ifndef Traverse_void_List_List_TypePair
#define Traverse_void_List_List_TypePair Traverse_void_List_List_doggy_TypePair
#endif
#ifndef Traverse_void_List_TypePair
#define Traverse_void_List_TypePair Traverse_void_List_doggy_TypePair
#endif
#ifndef Traverse_void_List_ActualOp
#define Traverse_void_List_ActualOp Traverse_void_List_doggy_ActualOp
#endif
#ifndef Traverse_void_List_List_Type
#define Traverse_void_List_List_Type Traverse_void_List_List_doggy_Type
#endif
#ifndef Traverse_void_List_Operator
#define Traverse_void_List_Operator Traverse_void_List_doggy_Operator
#endif
#ifndef Traverse_void_List_Definition
#define Traverse_void_List_Definition Traverse_void_List_doggy_Definition
#endif
#ifndef Traverse_void_List_Expr
#define Traverse_void_List_Expr Traverse_void_List_doggy_Expr
#endif
#ifndef Traverse_void_List_Guard
#define Traverse_void_List_Guard Traverse_void_List_doggy_Guard
#endif
#ifndef Traverse_void_List_Pattern
#define Traverse_void_List_Pattern Traverse_void_List_doggy_Pattern
#endif
#ifndef Traverse_void_List_Argument
#define Traverse_void_List_Argument Traverse_void_List_doggy_Argument
#endif
#ifndef Traverse_void_List_FuncRule
#define Traverse_void_List_FuncRule Traverse_void_List_doggy_FuncRule
#endif
#ifndef Traverse_void_List_Attribute
#define Traverse_void_List_Attribute Traverse_void_List_doggy_Attribute
#endif
#ifndef Traverse_void_List_Property
#define Traverse_void_List_Property Traverse_void_List_doggy_Property
#endif
#ifndef Traverse_void_List_Applied_formal
#define Traverse_void_List_Applied_formal Traverse_void_List_doggy_Applied_formal
#endif
#ifndef Traverse_void_List_Operation_def
#define Traverse_void_List_Operation_def Traverse_void_List_doggy_Operation_def
#endif
#ifndef Traverse_void_List_Type
#define Traverse_void_List_Type Traverse_void_List_doggy_Type
#endif
#ifndef Traverse_void_List_Rule
#define Traverse_void_List_Rule Traverse_void_List_doggy_Rule
#endif
#ifndef Traverse_void_List_Func
#define Traverse_void_List_Func Traverse_void_List_doggy_Func
#endif
#ifndef Traverse_void_List_Section
#define Traverse_void_List_Section Traverse_void_List_doggy_Section
#endif
#ifndef Traverse_void_List_FunctionDef
#define Traverse_void_List_FunctionDef Traverse_void_List_doggy_FunctionDef
#endif
#ifndef Traverse_void_List_Typedef
#define Traverse_void_List_Typedef Traverse_void_List_doggy_Typedef
#endif
#ifndef s_copy_TraverseTable
#define s_copy_TraverseTable s_copy_doggy_TraverseTable
#endif
#ifndef copy_TraverseTable
#define copy_TraverseTable copy_doggy_TraverseTable
#endif
#ifndef Traverse_copy_Operator
#define Traverse_copy_Operator Traverse_copy_doggy_Operator
#endif
#ifndef COPY_Operator
#define COPY_Operator COPY_doggy_Operator
#endif
#ifndef copy_actions
#define copy_actions doggy_copy_actions
#endif
#ifndef Traverse_copy_MonOp
#define Traverse_copy_MonOp Traverse_copy_doggy_MonOp
#endif
#ifndef COPY_MonOp
#define COPY_MonOp COPY_doggy_MonOp
#endif
#ifndef Traverse_copy_Property
#define Traverse_copy_Property Traverse_copy_doggy_Property
#endif
#ifndef COPY_Property
#define COPY_Property COPY_doggy_Property
#endif
#ifndef Traverse_copy_doggy
#define Traverse_copy_doggy Traverse_copy_doggy_doggy
#endif
#ifndef COPY_doggy
#define COPY_doggy COPY_doggy_doggy
#endif
#ifndef Traverse_copy_Typedef
#define Traverse_copy_Typedef Traverse_copy_doggy_Typedef
#endif
#ifndef COPY_Typedef
#define COPY_Typedef COPY_doggy_Typedef
#endif
#ifndef Traverse_copy_FunctionDef
#define Traverse_copy_FunctionDef Traverse_copy_doggy_FunctionDef
#endif
#ifndef COPY_FunctionDef
#define COPY_FunctionDef COPY_doggy_FunctionDef
#endif
#ifndef Traverse_copy_machine_description
#define Traverse_copy_machine_description Traverse_copy_doggy_machine_description
#endif
#ifndef COPY_machine_description
#define COPY_machine_description COPY_doggy_machine_description
#endif
#ifndef Traverse_copy_Operation_def
#define Traverse_copy_Operation_def Traverse_copy_doggy_Operation_def
#endif
#ifndef COPY_Operation_def
#define COPY_Operation_def COPY_doggy_Operation_def
#endif
#ifndef Traverse_copy_Attributes
#define Traverse_copy_Attributes Traverse_copy_doggy_Attributes
#endif
#ifndef COPY_Attributes
#define COPY_Attributes COPY_doggy_Attributes
#endif
#ifndef Traverse_copy_Attribute
#define Traverse_copy_Attribute Traverse_copy_doggy_Attribute
#endif
#ifndef COPY_Attribute
#define COPY_Attribute COPY_doggy_Attribute
#endif
#ifndef Traverse_copy_Section
#define Traverse_copy_Section Traverse_copy_doggy_Section
#endif
#ifndef COPY_Section
#define COPY_Section COPY_doggy_Section
#endif
#ifndef Traverse_copy_Rule
#define Traverse_copy_Rule Traverse_copy_doggy_Rule
#endif
#ifndef COPY_Rule
#define COPY_Rule COPY_doggy_Rule
#endif
#ifndef Traverse_copy_Lhs
#define Traverse_copy_Lhs Traverse_copy_doggy_Lhs
#endif
#ifndef COPY_Lhs
#define COPY_Lhs COPY_doggy_Lhs
#endif
#ifndef Traverse_copy_Func
#define Traverse_copy_Func Traverse_copy_doggy_Func
#endif
#ifndef COPY_Func
#define COPY_Func COPY_doggy_Func
#endif
#ifndef Traverse_copy_FuncRule
#define Traverse_copy_FuncRule Traverse_copy_doggy_FuncRule
#endif
#ifndef COPY_FuncRule
#define COPY_FuncRule COPY_doggy_FuncRule
#endif
#ifndef Traverse_copy_Argument
#define Traverse_copy_Argument Traverse_copy_doggy_Argument
#endif
#ifndef COPY_Argument
#define COPY_Argument COPY_doggy_Argument
#endif
#ifndef Traverse_copy_ArgPat
#define Traverse_copy_ArgPat Traverse_copy_doggy_ArgPat
#endif
#ifndef COPY_ArgPat
#define COPY_ArgPat COPY_doggy_ArgPat
#endif
#ifndef Traverse_copy_Pattern
#define Traverse_copy_Pattern Traverse_copy_doggy_Pattern
#endif
#ifndef COPY_Pattern
#define COPY_Pattern COPY_doggy_Pattern
#endif
#ifndef Traverse_copy_Rhs
#define Traverse_copy_Rhs Traverse_copy_doggy_Rhs
#endif
#ifndef COPY_Rhs
#define COPY_Rhs COPY_doggy_Rhs
#endif
#ifndef Traverse_copy_Guard
#define Traverse_copy_Guard Traverse_copy_doggy_Guard
#endif
#ifndef COPY_Guard
#define COPY_Guard COPY_doggy_Guard
#endif
#ifndef Traverse_copy_ExprSeq
#define Traverse_copy_ExprSeq Traverse_copy_doggy_ExprSeq
#endif
#ifndef COPY_ExprSeq
#define COPY_ExprSeq COPY_doggy_ExprSeq
#endif
#ifndef Traverse_copy_Wherepart
#define Traverse_copy_Wherepart Traverse_copy_doggy_Wherepart
#endif
#ifndef COPY_Wherepart
#define COPY_Wherepart COPY_doggy_Wherepart
#endif
#ifndef Traverse_copy_Applied_operation
#define Traverse_copy_Applied_operation Traverse_copy_doggy_Applied_operation
#endif
#ifndef COPY_Applied_operation
#define COPY_Applied_operation COPY_doggy_Applied_operation
#endif
#ifndef Traverse_copy_Applied_formal
#define Traverse_copy_Applied_formal Traverse_copy_doggy_Applied_formal
#endif
#ifndef COPY_Applied_formal
#define COPY_Applied_formal COPY_doggy_Applied_formal
#endif
#ifndef Traverse_copy_Expr
#define Traverse_copy_Expr Traverse_copy_doggy_Expr
#endif
#ifndef COPY_Expr
#define COPY_Expr COPY_doggy_Expr
#endif
#ifndef Traverse_copy_Constant
#define Traverse_copy_Constant Traverse_copy_doggy_Constant
#endif
#ifndef COPY_Constant
#define COPY_Constant COPY_doggy_Constant
#endif
#ifndef Traverse_copy_Definition
#define Traverse_copy_Definition Traverse_copy_doggy_Definition
#endif
#ifndef COPY_Definition
#define COPY_Definition COPY_doggy_Definition
#endif
#ifndef Traverse_copy_Type
#define Traverse_copy_Type Traverse_copy_doggy_Type
#endif
#ifndef COPY_Type
#define COPY_Type COPY_doggy_Type
#endif
#ifndef Traverse_copy_Num
#define Traverse_copy_Num Traverse_copy_doggy_Num
#endif
#ifndef COPY_Num
#define COPY_Num COPY_doggy_Num
#endif
#ifndef Traverse_copy_IdInt
#define Traverse_copy_IdInt Traverse_copy_doggy_IdInt
#endif
#ifndef COPY_IdInt
#define COPY_IdInt COPY_doggy_IdInt
#endif
#ifndef Traverse_copy_Path
#define Traverse_copy_Path Traverse_copy_doggy_Path
#endif
#ifndef COPY_Path
#define COPY_Path COPY_doggy_Path
#endif
#ifndef Traverse_copy_ActualOp
#define Traverse_copy_ActualOp Traverse_copy_doggy_ActualOp
#endif
#ifndef COPY_ActualOp
#define COPY_ActualOp COPY_doggy_ActualOp
#endif
#ifndef Traverse_copy_TypePair
#define Traverse_copy_TypePair Traverse_copy_doggy_TypePair
#endif
#ifndef COPY_TypePair
#define COPY_TypePair COPY_doggy_TypePair
#endif
#ifndef Traverse_copy_Opat
#define Traverse_copy_Opat Traverse_copy_doggy_Opat
#endif
#ifndef COPY_Opat
#define COPY_Opat COPY_doggy_Opat
#endif
#ifndef Traverse_copy_Format
#define Traverse_copy_Format Traverse_copy_doggy_Format
#endif
#ifndef COPY_Format
#define COPY_Format COPY_doggy_Format
#endif
#ifndef Traverse_copy_dummy_type
#define Traverse_copy_dummy_type Traverse_copy_doggy_dummy_type
#endif
#ifndef COPY_dummy_type
#define COPY_dummy_type COPY_doggy_dummy_type
#endif
#ifndef Traverse_copy_Scope
#define Traverse_copy_Scope Traverse_copy_doggy_Scope
#endif
#ifndef COPY_Scope
#define COPY_Scope COPY_doggy_Scope
#endif
#ifndef Traverse_copy_List_Num
#define Traverse_copy_List_Num Traverse_copy_List_doggy_Num
#endif
#ifndef COPY_List_Num
#define COPY_List_Num COPY_doggy_List_Num
#endif
#ifndef Traverse_copy_List_List_TypePair
#define Traverse_copy_List_List_TypePair Traverse_copy_List_List_doggy_TypePair
#endif
#ifndef COPY_List_List_TypePair
#define COPY_List_List_TypePair COPY_doggy_List_List_TypePair
#endif
#ifndef Traverse_copy_List_TypePair
#define Traverse_copy_List_TypePair Traverse_copy_List_doggy_TypePair
#endif
#ifndef COPY_List_TypePair
#define COPY_List_TypePair COPY_doggy_List_TypePair
#endif
#ifndef Traverse_copy_List_ActualOp
#define Traverse_copy_List_ActualOp Traverse_copy_List_doggy_ActualOp
#endif
#ifndef COPY_List_ActualOp
#define COPY_List_ActualOp COPY_doggy_List_ActualOp
#endif
#ifndef Traverse_copy_List_List_Type
#define Traverse_copy_List_List_Type Traverse_copy_List_List_doggy_Type
#endif
#ifndef COPY_List_List_Type
#define COPY_List_List_Type COPY_doggy_List_List_Type
#endif
#ifndef Traverse_copy_List_Operator
#define Traverse_copy_List_Operator Traverse_copy_List_doggy_Operator
#endif
#ifndef COPY_List_Operator
#define COPY_List_Operator COPY_doggy_List_Operator
#endif
#ifndef Traverse_copy_List_Definition
#define Traverse_copy_List_Definition Traverse_copy_List_doggy_Definition
#endif
#ifndef COPY_List_Definition
#define COPY_List_Definition COPY_doggy_List_Definition
#endif
#ifndef Traverse_copy_List_Expr
#define Traverse_copy_List_Expr Traverse_copy_List_doggy_Expr
#endif
#ifndef COPY_List_Expr
#define COPY_List_Expr COPY_doggy_List_Expr
#endif
#ifndef Traverse_copy_List_Guard
#define Traverse_copy_List_Guard Traverse_copy_List_doggy_Guard
#endif
#ifndef COPY_List_Guard
#define COPY_List_Guard COPY_doggy_List_Guard
#endif
#ifndef Traverse_copy_List_Pattern
#define Traverse_copy_List_Pattern Traverse_copy_List_doggy_Pattern
#endif
#ifndef COPY_List_Pattern
#define COPY_List_Pattern COPY_doggy_List_Pattern
#endif
#ifndef Traverse_copy_List_Argument
#define Traverse_copy_List_Argument Traverse_copy_List_doggy_Argument
#endif
#ifndef COPY_List_Argument
#define COPY_List_Argument COPY_doggy_List_Argument
#endif
#ifndef Traverse_copy_List_FuncRule
#define Traverse_copy_List_FuncRule Traverse_copy_List_doggy_FuncRule
#endif
#ifndef COPY_List_FuncRule
#define COPY_List_FuncRule COPY_doggy_List_FuncRule
#endif
#ifndef Traverse_copy_List_Attribute
#define Traverse_copy_List_Attribute Traverse_copy_List_doggy_Attribute
#endif
#ifndef COPY_List_Attribute
#define COPY_List_Attribute COPY_doggy_List_Attribute
#endif
#ifndef Traverse_copy_List_Property
#define Traverse_copy_List_Property Traverse_copy_List_doggy_Property
#endif
#ifndef COPY_List_Property
#define COPY_List_Property COPY_doggy_List_Property
#endif
#ifndef Traverse_copy_List_Applied_formal
#define Traverse_copy_List_Applied_formal Traverse_copy_List_doggy_Applied_formal
#endif
#ifndef COPY_List_Applied_formal
#define COPY_List_Applied_formal COPY_doggy_List_Applied_formal
#endif
#ifndef Traverse_copy_List_Operation_def
#define Traverse_copy_List_Operation_def Traverse_copy_List_doggy_Operation_def
#endif
#ifndef COPY_List_Operation_def
#define COPY_List_Operation_def COPY_doggy_List_Operation_def
#endif
#ifndef Traverse_copy_List_Type
#define Traverse_copy_List_Type Traverse_copy_List_doggy_Type
#endif
#ifndef COPY_List_Type
#define COPY_List_Type COPY_doggy_List_Type
#endif
#ifndef Traverse_copy_List_Rule
#define Traverse_copy_List_Rule Traverse_copy_List_doggy_Rule
#endif
#ifndef COPY_List_Rule
#define COPY_List_Rule COPY_doggy_List_Rule
#endif
#ifndef Traverse_copy_List_Func
#define Traverse_copy_List_Func Traverse_copy_List_doggy_Func
#endif
#ifndef COPY_List_Func
#define COPY_List_Func COPY_doggy_List_Func
#endif
#ifndef Traverse_copy_List_Section
#define Traverse_copy_List_Section Traverse_copy_List_doggy_Section
#endif
#ifndef COPY_List_Section
#define COPY_List_Section COPY_doggy_List_Section
#endif
#ifndef Traverse_copy_List_FunctionDef
#define Traverse_copy_List_FunctionDef Traverse_copy_List_doggy_FunctionDef
#endif
#ifndef COPY_List_FunctionDef
#define COPY_List_FunctionDef COPY_doggy_List_FunctionDef
#endif
#ifndef Traverse_copy_List_Typedef
#define Traverse_copy_List_Typedef Traverse_copy_List_doggy_Typedef
#endif
#ifndef COPY_List_Typedef
#define COPY_List_Typedef COPY_doggy_List_Typedef
#endif
#ifndef s_compare_TraverseTable
#define s_compare_TraverseTable s_compare_doggy_TraverseTable
#endif
#ifndef compare_TraverseTable
#define compare_TraverseTable compare_doggy_TraverseTable
#endif
#ifndef Traverse_compare_Operator
#define Traverse_compare_Operator Traverse_compare_doggy_Operator
#endif
#ifndef Traverse_compare_MonOp
#define Traverse_compare_MonOp Traverse_compare_doggy_MonOp
#endif
#ifndef Traverse_compare_Property
#define Traverse_compare_Property Traverse_compare_doggy_Property
#endif
#ifndef Traverse_compare_doggy
#define Traverse_compare_doggy Traverse_compare_doggy_doggy
#endif
#ifndef Traverse_compare_Typedef
#define Traverse_compare_Typedef Traverse_compare_doggy_Typedef
#endif
#ifndef Traverse_compare_FunctionDef
#define Traverse_compare_FunctionDef Traverse_compare_doggy_FunctionDef
#endif
#ifndef Traverse_compare_machine_description
#define Traverse_compare_machine_description Traverse_compare_doggy_machine_description
#endif
#ifndef Traverse_compare_Operation_def
#define Traverse_compare_Operation_def Traverse_compare_doggy_Operation_def
#endif
#ifndef Traverse_compare_Attributes
#define Traverse_compare_Attributes Traverse_compare_doggy_Attributes
#endif
#ifndef Traverse_compare_Attribute
#define Traverse_compare_Attribute Traverse_compare_doggy_Attribute
#endif
#ifndef Traverse_compare_Section
#define Traverse_compare_Section Traverse_compare_doggy_Section
#endif
#ifndef Traverse_compare_Rule
#define Traverse_compare_Rule Traverse_compare_doggy_Rule
#endif
#ifndef Traverse_compare_Lhs
#define Traverse_compare_Lhs Traverse_compare_doggy_Lhs
#endif
#ifndef Traverse_compare_Func
#define Traverse_compare_Func Traverse_compare_doggy_Func
#endif
#ifndef Traverse_compare_FuncRule
#define Traverse_compare_FuncRule Traverse_compare_doggy_FuncRule
#endif
#ifndef Traverse_compare_Argument
#define Traverse_compare_Argument Traverse_compare_doggy_Argument
#endif
#ifndef Traverse_compare_ArgPat
#define Traverse_compare_ArgPat Traverse_compare_doggy_ArgPat
#endif
#ifndef Traverse_compare_Pattern
#define Traverse_compare_Pattern Traverse_compare_doggy_Pattern
#endif
#ifndef Traverse_compare_Rhs
#define Traverse_compare_Rhs Traverse_compare_doggy_Rhs
#endif
#ifndef Traverse_compare_Guard
#define Traverse_compare_Guard Traverse_compare_doggy_Guard
#endif
#ifndef Traverse_compare_ExprSeq
#define Traverse_compare_ExprSeq Traverse_compare_doggy_ExprSeq
#endif
#ifndef Traverse_compare_Wherepart
#define Traverse_compare_Wherepart Traverse_compare_doggy_Wherepart
#endif
#ifndef Traverse_compare_Applied_operation
#define Traverse_compare_Applied_operation Traverse_compare_doggy_Applied_operation
#endif
#ifndef Traverse_compare_Applied_formal
#define Traverse_compare_Applied_formal Traverse_compare_doggy_Applied_formal
#endif
#ifndef Traverse_compare_Expr
#define Traverse_compare_Expr Traverse_compare_doggy_Expr
#endif
#ifndef Traverse_compare_Constant
#define Traverse_compare_Constant Traverse_compare_doggy_Constant
#endif
#ifndef Traverse_compare_Definition
#define Traverse_compare_Definition Traverse_compare_doggy_Definition
#endif
#ifndef Traverse_compare_Type
#define Traverse_compare_Type Traverse_compare_doggy_Type
#endif
#ifndef Traverse_compare_Num
#define Traverse_compare_Num Traverse_compare_doggy_Num
#endif
#ifndef Traverse_compare_IdInt
#define Traverse_compare_IdInt Traverse_compare_doggy_IdInt
#endif
#ifndef Traverse_compare_Path
#define Traverse_compare_Path Traverse_compare_doggy_Path
#endif
#ifndef Traverse_compare_ActualOp
#define Traverse_compare_ActualOp Traverse_compare_doggy_ActualOp
#endif
#ifndef Traverse_compare_TypePair
#define Traverse_compare_TypePair Traverse_compare_doggy_TypePair
#endif
#ifndef Traverse_compare_Opat
#define Traverse_compare_Opat Traverse_compare_doggy_Opat
#endif
#ifndef Traverse_compare_Format
#define Traverse_compare_Format Traverse_compare_doggy_Format
#endif
#ifndef Traverse_compare_dummy_type
#define Traverse_compare_dummy_type Traverse_compare_doggy_dummy_type
#endif
#ifndef Traverse_compare_Scope
#define Traverse_compare_Scope Traverse_compare_doggy_Scope
#endif
#ifndef Traverse_compare_List_Num
#define Traverse_compare_List_Num Traverse_compare_List_doggy_Num
#endif
#ifndef Traverse_compare_List_List_TypePair
#define Traverse_compare_List_List_TypePair Traverse_compare_List_List_doggy_TypePair
#endif
#ifndef Traverse_compare_List_TypePair
#define Traverse_compare_List_TypePair Traverse_compare_List_doggy_TypePair
#endif
#ifndef Traverse_compare_List_ActualOp
#define Traverse_compare_List_ActualOp Traverse_compare_List_doggy_ActualOp
#endif
#ifndef Traverse_compare_List_List_Type
#define Traverse_compare_List_List_Type Traverse_compare_List_List_doggy_Type
#endif
#ifndef Traverse_compare_List_Operator
#define Traverse_compare_List_Operator Traverse_compare_List_doggy_Operator
#endif
#ifndef Traverse_compare_List_Definition
#define Traverse_compare_List_Definition Traverse_compare_List_doggy_Definition
#endif
#ifndef Traverse_compare_List_Expr
#define Traverse_compare_List_Expr Traverse_compare_List_doggy_Expr
#endif
#ifndef Traverse_compare_List_Guard
#define Traverse_compare_List_Guard Traverse_compare_List_doggy_Guard
#endif
#ifndef Traverse_compare_List_Pattern
#define Traverse_compare_List_Pattern Traverse_compare_List_doggy_Pattern
#endif
#ifndef Traverse_compare_List_Argument
#define Traverse_compare_List_Argument Traverse_compare_List_doggy_Argument
#endif
#ifndef Traverse_compare_List_FuncRule
#define Traverse_compare_List_FuncRule Traverse_compare_List_doggy_FuncRule
#endif
#ifndef Traverse_compare_List_Attribute
#define Traverse_compare_List_Attribute Traverse_compare_List_doggy_Attribute
#endif
#ifndef Traverse_compare_List_Property
#define Traverse_compare_List_Property Traverse_compare_List_doggy_Property
#endif
#ifndef Traverse_compare_List_Applied_formal
#define Traverse_compare_List_Applied_formal Traverse_compare_List_doggy_Applied_formal
#endif
#ifndef Traverse_compare_List_Operation_def
#define Traverse_compare_List_Operation_def Traverse_compare_List_doggy_Operation_def
#endif
#ifndef Traverse_compare_List_Type
#define Traverse_compare_List_Type Traverse_compare_List_doggy_Type
#endif
#ifndef Traverse_compare_List_Rule
#define Traverse_compare_List_Rule Traverse_compare_List_doggy_Rule
#endif
#ifndef Traverse_compare_List_Func
#define Traverse_compare_List_Func Traverse_compare_List_doggy_Func
#endif
#ifndef Traverse_compare_List_Section
#define Traverse_compare_List_Section Traverse_compare_List_doggy_Section
#endif
#ifndef Traverse_compare_List_FunctionDef
#define Traverse_compare_List_FunctionDef Traverse_compare_List_doggy_FunctionDef
#endif
#ifndef Traverse_compare_List_Typedef
#define Traverse_compare_List_Typedef Traverse_compare_List_doggy_Typedef
#endif
#ifndef fill_table
#define fill_table doggy_fill_table
#endif
#ifndef void_fill_table
#define void_fill_table void_doggy_fill_table
#endif
#ifndef copy_fill_table
#define copy_fill_table copy_doggy_fill_table
#endif
#ifndef compare_fill_table
#define compare_fill_table compare_doggy_fill_table
#endif
#ifndef scope_actions
#define scope_actions doggy_scope_actions
#endif
#ifndef defining_actions
#define defining_actions doggy_defining_actions
#endif
#ifndef applied_actions
#define applied_actions doggy_applied_actions
#endif
#ifndef check_actions
#define check_actions doggy_check_actions
#endif
#ifndef print_actions
#define print_actions doggy_print_actions
#endif
#ifndef compare_actions
#define compare_actions doggy_compare_actions
#endif
#ifndef NameSpaces
#define NameSpaces doggy_NameSpaces
#endif
#ifndef namespaces
#define namespaces doggy_namespaces
#endif
#ifndef DefaultNameSpace
#define DefaultNameSpace doggy_DefaultNameSpace
#endif
#ifndef TypeNameSpace
#define TypeNameSpace doggy_TypeNameSpace
#endif
#ifndef NUM_NAMESPACES
#define NUM_NAMESPACES doggy_NUM_NAMESPACES
#endif
#ifndef FunctionDef_tag_names
#define FunctionDef_tag_names doggy_FunctionDef_tag_names
#endif
#ifndef Attribute_tag_names
#define Attribute_tag_names doggy_Attribute_tag_names
#endif
#ifndef Section_tag_names
#define Section_tag_names doggy_Section_tag_names
#endif
#ifndef Lhs_tag_names
#define Lhs_tag_names doggy_Lhs_tag_names
#endif
#ifndef Argument_tag_names
#define Argument_tag_names doggy_Argument_tag_names
#endif
#ifndef ArgPat_tag_names
#define ArgPat_tag_names doggy_ArgPat_tag_names
#endif
#ifndef Pattern_tag_names
#define Pattern_tag_names doggy_Pattern_tag_names
#endif
#ifndef Rhs_tag_names
#define Rhs_tag_names doggy_Rhs_tag_names
#endif
#ifndef Guard_tag_names
#define Guard_tag_names doggy_Guard_tag_names
#endif
#ifndef ExprSeq_tag_names
#define ExprSeq_tag_names doggy_ExprSeq_tag_names
#endif
#ifndef Applied_operation_tag_names
#define Applied_operation_tag_names doggy_Applied_operation_tag_names
#endif
#ifndef Expr_tag_names
#define Expr_tag_names doggy_Expr_tag_names
#endif
#ifndef Constant_tag_names
#define Constant_tag_names doggy_Constant_tag_names
#endif
#ifndef Operator_names
#define Operator_names doggy_Operator_names
#endif
#ifndef MonOp_names
#define MonOp_names doggy_MonOp_names
#endif
#ifndef Type_tag_names
#define Type_tag_names doggy_Type_tag_names
#endif
#ifndef IdInt_tag_names
#define IdInt_tag_names doggy_IdInt_tag_names
#endif
#ifndef Scope_tag_names
#define Scope_tag_names doggy_Scope_tag_names
#endif
#ifndef Bind_Typedef_kind
#define Bind_Typedef_kind Bind_doggy_Typedef_kind
#endif
#ifndef Bind_FunctionDef_kind
#define Bind_FunctionDef_kind Bind_doggy_FunctionDef_kind
#endif
#ifndef Bind_machine_description_kind
#define Bind_machine_description_kind Bind_doggy_machine_description_kind
#endif
#ifndef Bind_Operation_def_kind
#define Bind_Operation_def_kind Bind_doggy_Operation_def_kind
#endif
#ifndef Bind_Func_kind
#define Bind_Func_kind Bind_doggy_Func_kind
#endif
#ifndef Bind_Argument_kind
#define Bind_Argument_kind Bind_doggy_Argument_kind
#endif
#ifndef Bind_Pattern_kind
#define Bind_Pattern_kind Bind_doggy_Pattern_kind
#endif
#ifndef Bind_Definition_kind
#define Bind_Definition_kind Bind_doggy_Definition_kind
#endif
#ifndef Print_doggy
#define Print_doggy Print_doggy_doggy
#endif
#ifndef PRINT_doggy
#define PRINT_doggy PRINT_doggy_doggy
#endif
#ifndef Text_doggy
#define Text_doggy Text_doggy_doggy
#endif
#ifndef Print_Typedef
#define Print_Typedef Print_doggy_Typedef
#endif
#ifndef PRINT_Typedef
#define PRINT_Typedef PRINT_doggy_Typedef
#endif
#ifndef Text_Typedef
#define Text_Typedef Text_doggy_Typedef
#endif
#ifndef Print_FunctionDef
#define Print_FunctionDef Print_doggy_FunctionDef
#endif
#ifndef PRINT_FunctionDef
#define PRINT_FunctionDef PRINT_doggy_FunctionDef
#endif
#ifndef Text_FunctionDef
#define Text_FunctionDef Text_doggy_FunctionDef
#endif
#ifndef Print_machine_description
#define Print_machine_description Print_doggy_machine_description
#endif
#ifndef PRINT_machine_description
#define PRINT_machine_description PRINT_doggy_machine_description
#endif
#ifndef Text_machine_description
#define Text_machine_description Text_doggy_machine_description
#endif
#ifndef Print_Operation_def
#define Print_Operation_def Print_doggy_Operation_def
#endif
#ifndef PRINT_Operation_def
#define PRINT_Operation_def PRINT_doggy_Operation_def
#endif
#ifndef Text_Operation_def
#define Text_Operation_def Text_doggy_Operation_def
#endif
#ifndef Print_Attributes
#define Print_Attributes Print_doggy_Attributes
#endif
#ifndef PRINT_Attributes
#define PRINT_Attributes PRINT_doggy_Attributes
#endif
#ifndef Text_Attributes
#define Text_Attributes Text_doggy_Attributes
#endif
#ifndef Print_Attribute
#define Print_Attribute Print_doggy_Attribute
#endif
#ifndef PRINT_Attribute
#define PRINT_Attribute PRINT_doggy_Attribute
#endif
#ifndef Text_Attribute
#define Text_Attribute Text_doggy_Attribute
#endif
#ifndef Print_Section
#define Print_Section Print_doggy_Section
#endif
#ifndef PRINT_Section
#define PRINT_Section PRINT_doggy_Section
#endif
#ifndef Text_Section
#define Text_Section Text_doggy_Section
#endif
#ifndef Print_Rule
#define Print_Rule Print_doggy_Rule
#endif
#ifndef PRINT_Rule
#define PRINT_Rule PRINT_doggy_Rule
#endif
#ifndef Text_Rule
#define Text_Rule Text_doggy_Rule
#endif
#ifndef Print_Lhs
#define Print_Lhs Print_doggy_Lhs
#endif
#ifndef PRINT_Lhs
#define PRINT_Lhs PRINT_doggy_Lhs
#endif
#ifndef Text_Lhs
#define Text_Lhs Text_doggy_Lhs
#endif
#ifndef Print_Func
#define Print_Func Print_doggy_Func
#endif
#ifndef PRINT_Func
#define PRINT_Func PRINT_doggy_Func
#endif
#ifndef Text_Func
#define Text_Func Text_doggy_Func
#endif
#ifndef Print_FuncRule
#define Print_FuncRule Print_doggy_FuncRule
#endif
#ifndef PRINT_FuncRule
#define PRINT_FuncRule PRINT_doggy_FuncRule
#endif
#ifndef Text_FuncRule
#define Text_FuncRule Text_doggy_FuncRule
#endif
#ifndef Print_Argument
#define Print_Argument Print_doggy_Argument
#endif
#ifndef PRINT_Argument
#define PRINT_Argument PRINT_doggy_Argument
#endif
#ifndef Text_Argument
#define Text_Argument Text_doggy_Argument
#endif
#ifndef Print_ArgPat
#define Print_ArgPat Print_doggy_ArgPat
#endif
#ifndef PRINT_ArgPat
#define PRINT_ArgPat PRINT_doggy_ArgPat
#endif
#ifndef Text_ArgPat
#define Text_ArgPat Text_doggy_ArgPat
#endif
#ifndef Print_Pattern
#define Print_Pattern Print_doggy_Pattern
#endif
#ifndef PRINT_Pattern
#define PRINT_Pattern PRINT_doggy_Pattern
#endif
#ifndef Text_Pattern
#define Text_Pattern Text_doggy_Pattern
#endif
#ifndef Print_Rhs
#define Print_Rhs Print_doggy_Rhs
#endif
#ifndef PRINT_Rhs
#define PRINT_Rhs PRINT_doggy_Rhs
#endif
#ifndef Text_Rhs
#define Text_Rhs Text_doggy_Rhs
#endif
#ifndef Print_Guard
#define Print_Guard Print_doggy_Guard
#endif
#ifndef PRINT_Guard
#define PRINT_Guard PRINT_doggy_Guard
#endif
#ifndef Text_Guard
#define Text_Guard Text_doggy_Guard
#endif
#ifndef Print_ExprSeq
#define Print_ExprSeq Print_doggy_ExprSeq
#endif
#ifndef PRINT_ExprSeq
#define PRINT_ExprSeq PRINT_doggy_ExprSeq
#endif
#ifndef Text_ExprSeq
#define Text_ExprSeq Text_doggy_ExprSeq
#endif
#ifndef Print_Wherepart
#define Print_Wherepart Print_doggy_Wherepart
#endif
#ifndef PRINT_Wherepart
#define PRINT_Wherepart PRINT_doggy_Wherepart
#endif
#ifndef Text_Wherepart
#define Text_Wherepart Text_doggy_Wherepart
#endif
#ifndef Print_Applied_operation
#define Print_Applied_operation Print_doggy_Applied_operation
#endif
#ifndef PRINT_Applied_operation
#define PRINT_Applied_operation PRINT_doggy_Applied_operation
#endif
#ifndef Text_Applied_operation
#define Text_Applied_operation Text_doggy_Applied_operation
#endif
#ifndef Print_Applied_formal
#define Print_Applied_formal Print_doggy_Applied_formal
#endif
#ifndef PRINT_Applied_formal
#define PRINT_Applied_formal PRINT_doggy_Applied_formal
#endif
#ifndef Text_Applied_formal
#define Text_Applied_formal Text_doggy_Applied_formal
#endif
#ifndef Print_Expr
#define Print_Expr Print_doggy_Expr
#endif
#ifndef PRINT_Expr
#define PRINT_Expr PRINT_doggy_Expr
#endif
#ifndef Text_Expr
#define Text_Expr Text_doggy_Expr
#endif
#ifndef Print_Constant
#define Print_Constant Print_doggy_Constant
#endif
#ifndef PRINT_Constant
#define PRINT_Constant PRINT_doggy_Constant
#endif
#ifndef Text_Constant
#define Text_Constant Text_doggy_Constant
#endif
#ifndef Print_Definition
#define Print_Definition Print_doggy_Definition
#endif
#ifndef PRINT_Definition
#define PRINT_Definition PRINT_doggy_Definition
#endif
#ifndef Text_Definition
#define Text_Definition Text_doggy_Definition
#endif
#ifndef Print_Type
#define Print_Type Print_doggy_Type
#endif
#ifndef PRINT_Type
#define PRINT_Type PRINT_doggy_Type
#endif
#ifndef Text_Type
#define Text_Type Text_doggy_Type
#endif
#ifndef Print_Num
#define Print_Num Print_doggy_Num
#endif
#ifndef PRINT_Num
#define PRINT_Num PRINT_doggy_Num
#endif
#ifndef Text_Num
#define Text_Num Text_doggy_Num
#endif
#ifndef Print_IdInt
#define Print_IdInt Print_doggy_IdInt
#endif
#ifndef PRINT_IdInt
#define PRINT_IdInt PRINT_doggy_IdInt
#endif
#ifndef Text_IdInt
#define Text_IdInt Text_doggy_IdInt
#endif
#ifndef Print_Path
#define Print_Path Print_doggy_Path
#endif
#ifndef PRINT_Path
#define PRINT_Path PRINT_doggy_Path
#endif
#ifndef Text_Path
#define Text_Path Text_doggy_Path
#endif
#ifndef Print_ActualOp
#define Print_ActualOp Print_doggy_ActualOp
#endif
#ifndef PRINT_ActualOp
#define PRINT_ActualOp PRINT_doggy_ActualOp
#endif
#ifndef Text_ActualOp
#define Text_ActualOp Text_doggy_ActualOp
#endif
#ifndef Print_TypePair
#define Print_TypePair Print_doggy_TypePair
#endif
#ifndef PRINT_TypePair
#define PRINT_TypePair PRINT_doggy_TypePair
#endif
#ifndef Text_TypePair
#define Text_TypePair Text_doggy_TypePair
#endif
#ifndef Print_Opat
#define Print_Opat Print_doggy_Opat
#endif
#ifndef PRINT_Opat
#define PRINT_Opat PRINT_doggy_Opat
#endif
#ifndef Text_Opat
#define Text_Opat Text_doggy_Opat
#endif
#ifndef Print_Format
#define Print_Format Print_doggy_Format
#endif
#ifndef PRINT_Format
#define PRINT_Format PRINT_doggy_Format
#endif
#ifndef Text_Format
#define Text_Format Text_doggy_Format
#endif
#ifndef Print_dummy_type
#define Print_dummy_type Print_doggy_dummy_type
#endif
#ifndef PRINT_dummy_type
#define PRINT_dummy_type PRINT_doggy_dummy_type
#endif
#ifndef Text_dummy_type
#define Text_dummy_type Text_doggy_dummy_type
#endif
#ifndef Print_Scope
#define Print_Scope Print_doggy_Scope
#endif
#ifndef PRINT_Scope
#define PRINT_Scope PRINT_doggy_Scope
#endif
#ifndef Text_Scope
#define Text_Scope Text_doggy_Scope
#endif
#ifndef Print_List_Num
#define Print_List_Num Print_List_doggy_Num
#endif
#ifndef PRINT_List_Num
#define PRINT_List_Num PRINT_List_doggy_Num
#endif
#ifndef Text_List_Num
#define Text_List_Num Text_List_doggy_Num
#endif
#ifndef Print_List_List_TypePair
#define Print_List_List_TypePair Print_List_List_doggy_TypePair
#endif
#ifndef PRINT_List_List_TypePair
#define PRINT_List_List_TypePair PRINT_List_List_doggy_TypePair
#endif
#ifndef Text_List_List_TypePair
#define Text_List_List_TypePair Text_List_List_doggy_TypePair
#endif
#ifndef Print_List_TypePair
#define Print_List_TypePair Print_List_doggy_TypePair
#endif
#ifndef PRINT_List_TypePair
#define PRINT_List_TypePair PRINT_List_doggy_TypePair
#endif
#ifndef Text_List_TypePair
#define Text_List_TypePair Text_List_doggy_TypePair
#endif
#ifndef Print_List_ActualOp
#define Print_List_ActualOp Print_List_doggy_ActualOp
#endif
#ifndef PRINT_List_ActualOp
#define PRINT_List_ActualOp PRINT_List_doggy_ActualOp
#endif
#ifndef Text_List_ActualOp
#define Text_List_ActualOp Text_List_doggy_ActualOp
#endif
#ifndef Print_List_List_Type
#define Print_List_List_Type Print_List_List_doggy_Type
#endif
#ifndef PRINT_List_List_Type
#define PRINT_List_List_Type PRINT_List_List_doggy_Type
#endif
#ifndef Text_List_List_Type
#define Text_List_List_Type Text_List_List_doggy_Type
#endif
#ifndef Print_List_Operator
#define Print_List_Operator Print_List_doggy_Operator
#endif
#ifndef PRINT_List_Operator
#define PRINT_List_Operator PRINT_List_doggy_Operator
#endif
#ifndef Text_List_Operator
#define Text_List_Operator Text_List_doggy_Operator
#endif
#ifndef Print_List_Definition
#define Print_List_Definition Print_List_doggy_Definition
#endif
#ifndef PRINT_List_Definition
#define PRINT_List_Definition PRINT_List_doggy_Definition
#endif
#ifndef Text_List_Definition
#define Text_List_Definition Text_List_doggy_Definition
#endif
#ifndef Print_List_Expr
#define Print_List_Expr Print_List_doggy_Expr
#endif
#ifndef PRINT_List_Expr
#define PRINT_List_Expr PRINT_List_doggy_Expr
#endif
#ifndef Text_List_Expr
#define Text_List_Expr Text_List_doggy_Expr
#endif
#ifndef Print_List_Guard
#define Print_List_Guard Print_List_doggy_Guard
#endif
#ifndef PRINT_List_Guard
#define PRINT_List_Guard PRINT_List_doggy_Guard
#endif
#ifndef Text_List_Guard
#define Text_List_Guard Text_List_doggy_Guard
#endif
#ifndef Print_List_Pattern
#define Print_List_Pattern Print_List_doggy_Pattern
#endif
#ifndef PRINT_List_Pattern
#define PRINT_List_Pattern PRINT_List_doggy_Pattern
#endif
#ifndef Text_List_Pattern
#define Text_List_Pattern Text_List_doggy_Pattern
#endif
#ifndef Print_List_Argument
#define Print_List_Argument Print_List_doggy_Argument
#endif
#ifndef PRINT_List_Argument
#define PRINT_List_Argument PRINT_List_doggy_Argument
#endif
#ifndef Text_List_Argument
#define Text_List_Argument Text_List_doggy_Argument
#endif
#ifndef Print_List_FuncRule
#define Print_List_FuncRule Print_List_doggy_FuncRule
#endif
#ifndef PRINT_List_FuncRule
#define PRINT_List_FuncRule PRINT_List_doggy_FuncRule
#endif
#ifndef Text_List_FuncRule
#define Text_List_FuncRule Text_List_doggy_FuncRule
#endif
#ifndef Print_List_Attribute
#define Print_List_Attribute Print_List_doggy_Attribute
#endif
#ifndef PRINT_List_Attribute
#define PRINT_List_Attribute PRINT_List_doggy_Attribute
#endif
#ifndef Text_List_Attribute
#define Text_List_Attribute Text_List_doggy_Attribute
#endif
#ifndef Print_List_Property
#define Print_List_Property Print_List_doggy_Property
#endif
#ifndef PRINT_List_Property
#define PRINT_List_Property PRINT_List_doggy_Property
#endif
#ifndef Text_List_Property
#define Text_List_Property Text_List_doggy_Property
#endif
#ifndef Print_List_Applied_formal
#define Print_List_Applied_formal Print_List_doggy_Applied_formal
#endif
#ifndef PRINT_List_Applied_formal
#define PRINT_List_Applied_formal PRINT_List_doggy_Applied_formal
#endif
#ifndef Text_List_Applied_formal
#define Text_List_Applied_formal Text_List_doggy_Applied_formal
#endif
#ifndef Print_List_Operation_def
#define Print_List_Operation_def Print_List_doggy_Operation_def
#endif
#ifndef PRINT_List_Operation_def
#define PRINT_List_Operation_def PRINT_List_doggy_Operation_def
#endif
#ifndef Text_List_Operation_def
#define Text_List_Operation_def Text_List_doggy_Operation_def
#endif
#ifndef Print_List_Type
#define Print_List_Type Print_List_doggy_Type
#endif
#ifndef PRINT_List_Type
#define PRINT_List_Type PRINT_List_doggy_Type
#endif
#ifndef Text_List_Type
#define Text_List_Type Text_List_doggy_Type
#endif
#ifndef Print_List_Rule
#define Print_List_Rule Print_List_doggy_Rule
#endif
#ifndef PRINT_List_Rule
#define PRINT_List_Rule PRINT_List_doggy_Rule
#endif
#ifndef Text_List_Rule
#define Text_List_Rule Text_List_doggy_Rule
#endif
#ifndef Print_List_Func
#define Print_List_Func Print_List_doggy_Func
#endif
#ifndef PRINT_List_Func
#define PRINT_List_Func PRINT_List_doggy_Func
#endif
#ifndef Text_List_Func
#define Text_List_Func Text_List_doggy_Func
#endif
#ifndef Print_List_Section
#define Print_List_Section Print_List_doggy_Section
#endif
#ifndef PRINT_List_Section
#define PRINT_List_Section PRINT_List_doggy_Section
#endif
#ifndef Text_List_Section
#define Text_List_Section Text_List_doggy_Section
#endif
#ifndef Print_List_FunctionDef
#define Print_List_FunctionDef Print_List_doggy_FunctionDef
#endif
#ifndef PRINT_List_FunctionDef
#define PRINT_List_FunctionDef PRINT_List_doggy_FunctionDef
#endif
#ifndef Text_List_FunctionDef
#define Text_List_FunctionDef Text_List_doggy_FunctionDef
#endif
#ifndef Print_List_Typedef
#define Print_List_Typedef Print_List_doggy_Typedef
#endif
#ifndef PRINT_List_Typedef
#define PRINT_List_Typedef PRINT_List_doggy_Typedef
#endif
#ifndef Text_List_Typedef
#define Text_List_Typedef Text_List_doggy_Typedef
#endif
#ifndef Print_Operator
#define Print_Operator Print_doggy_Operator
#endif
#ifndef PRINT_Operator
#define PRINT_Operator PRINT_doggy_Operator
#endif
#ifndef Text_Operator
#define Text_Operator Text_doggy_Operator
#endif
#ifndef Print_MonOp
#define Print_MonOp Print_doggy_MonOp
#endif
#ifndef PRINT_MonOp
#define PRINT_MonOp PRINT_doggy_MonOp
#endif
#ifndef Text_MonOp
#define Text_MonOp Text_doggy_MonOp
#endif
#ifndef Print_Property
#define Print_Property Print_doggy_Property
#endif
#ifndef PRINT_Property
#define PRINT_Property PRINT_doggy_Property
#endif
#ifndef Text_Property
#define Text_Property Text_doggy_Property
#endif
#ifndef Parse_state_doggy
#define Parse_state_doggy Parse_state_doggy_doggy
#endif
#endif /* doggy_NO_DEFS */

