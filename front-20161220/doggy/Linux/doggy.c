#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "front/error.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/mem.h"
#include "doggy.h"

#ifndef doggy_SKIP_NODE
# define doggy_SKIP_NODE(n,t) FALSE
#endif

doggy doggy_root;

String doggy_FunctionDef_tag_names[] = {
  "ExtFunc_kind",
  "ExtVar_kind",
};

String doggy_Attribute_tag_names[] = {
  "IdAttr_kind",
  "OpAttr_kind",
  "IntAttr_kind",
};

String doggy_Section_tag_names[] = {
  "FuncSection_kind",
  "RuleSection_kind",
};

String doggy_Lhs_tag_names[] = {
  "LabeledLhs_kind",
  "UnLabeledLhs_kind",
};

String doggy_Argument_tag_names[] = {
  "TypedArg_kind",
  "UnTypedArg_kind",
};

String doggy_ArgPat_tag_names[] = {
  "PatArg_kind",
  "SetArg_kind",
};

String doggy_Pattern_tag_names[] = {
  "TypedPattern_kind",
  "ConsPattern_kind",
  "DefPattern_kind",
  "IdentPattern_kind",
  "OpPattern_kind",
  "ConstPattern_kind",
  "NullPattern_kind",
  "DontCarePattern_kind",
};

String doggy_Rhs_tag_names[] = {
  "PlainRhs_kind",
  "BlockRhs_kind",
};

String doggy_Guard_tag_names[] = {
  "RhsGuard_kind",
  "ExprGuard_kind",
};

String doggy_ExprSeq_tag_names[] = {
  "OneExpr_kind",
  "MoreExprs_kind",
};

String doggy_Applied_operation_tag_names[] = {
  "AnyOp_kind",
  "AppliedOp_kind",
  "OpSet_kind",
};

String doggy_Expr_tag_names[] = {
  "BinExpr_kind",
  "ConsExpr_kind",
  "IdentExpr_kind",
  "IfExpr_kind",
  "ConstExpr_kind",
  "Operation_kind",
  "ParExpr_kind",
  "MonExpr_kind",
};

String doggy_Constant_tag_names[] = {
  "IntConst_kind",
  "BoolConst_kind",
  "StringConst_kind",
  "NullConst_kind",
};

String doggy_Operator_names[] = {
  "CandOp",
  "CorOp",
  "XorOp",
  "EqOp",
  "NeqOp",
  "LEOp",
  "GEOp",
  "LTOp",
  "GTOp",
  "SLOp",
  "SROp",
  "DivOp",
  "ModOp",
  "MulOp",
  "AndOp",
  "AddOp",
  "SubOp",
};

String doggy_MonOp_names[] = {
  "NotOp",
  "NegOp",
  "AddrOp",
  "DerefOp",
  "PlusOp",
  "MinOp",
};

String doggy_Type_tag_names[] = {
  "EdgeType_kind",
  "TupleType_kind",
  "IdentType_kind",
  "OprType_kind",
  "PointerType_kind",
  "RangeType_kind",
  "FRangeType_kind",
};

String doggy_IdInt_tag_names[] = {
  "IsId_kind",
  "IsInt_kind",
};

String doggy_Scope_tag_names[] = {
  "OpSetScope_kind",
  "AppliedOpScope_kind",
  "ExprGuardScope_kind",
  "RhsGuardScope_kind",
  "FuncRuleScope_kind",
  "RuleScope_kind",
  "machine_descriptionScope_kind",
};

doggy_doggy Create_doggy_doggy	(SrcInfo src_info, List_doggy_Typedef types, doggy_machine_description source, doggy_machine_description target, List_doggy_FunctionDef funcs, List_doggy_Section sections)
{ doggy_doggy me = (doggy_doggy)fe_malloc(sizeof(*me));
  doggy_doggy_src_info(me) = src_info;
  doggy_doggy_types(me) = types;
  doggy_doggy_source(me) = source;
  doggy_doggy_target(me) = target;
  doggy_doggy_funcs(me) = funcs;
  doggy_doggy_sections(me) = sections;
  doggy_doggy_functions(me) = NULL;
  doggy_doggy_rules(me) = NULL;
  Store_md (me);
  return me;
}

doggy_Typedef Create_doggy_Typedef	(SrcInfo src_info, Ident id, String name, String short_hand, String value, doggy_Attributes attrs)
{ doggy_Typedef me = (doggy_Typedef)fe_malloc(sizeof(*me));
  doggy_Typedef_src_info(me) = src_info;
  doggy_Typedef_id(me) = id;
  doggy_Typedef_name(me) = name;
  doggy_Typedef_short_hand(me) = short_hand;
  doggy_Typedef_value(me) = value;
  doggy_Typedef_attrs(me) = attrs;
  doggy_Typedef__num(me) = - 1;
  doggy_Typedef_scope(me) = NULL;
  doggy_Typedef_old_scope(me) = NULL;
  doggy_Typedef_id_bind(me) = NULL;
  return me;
}

doggy_ExtVar Create_doggy_ExtVar	(SrcInfo src_info, doggy_Type result, Ident id)
{ doggy_ExtVar me = (doggy_ExtVar)fe_malloc(sizeof(*me));
  doggy_FunctionDef_src_info(me) = src_info;
  doggy_FunctionDef_result(me) = result;
  doggy_FunctionDef_id(me) = id;
  doggy_FunctionDef__num(me) = - 1;
  doggy_FunctionDef_scope(me) = NULL;
  doggy_FunctionDef_old_scope(me) = NULL;
  doggy_FunctionDef_tag(me) = doggy_ExtVar_kind;
  doggy_FunctionDef_id_bind(me) = NULL;
  return me;
}

doggy_ExtFunc Create_doggy_ExtFunc	(SrcInfo src_info, doggy_Type result, Ident id, List_doggy_Type args)
{ doggy_ExtFunc me = (doggy_ExtFunc)fe_malloc(sizeof(*me));
  doggy_FunctionDef_src_info(me) = src_info;
  doggy_FunctionDef_result(me) = result;
  doggy_FunctionDef_id(me) = id;
  doggy_ExtFunc_args(me) = args;
  doggy_FunctionDef__num(me) = - 1;
  doggy_FunctionDef_scope(me) = NULL;
  doggy_FunctionDef_old_scope(me) = NULL;
  doggy_FunctionDef_tag(me) = doggy_ExtFunc_kind;
  doggy_FunctionDef_id_bind(me) = NULL;
  return me;
}

doggy_machine_description Create_doggy_machine_description	(SrcInfo src_info, Ident id, List_doggy_Operation_def defs, List_doggy_Applied_formal supports)
{ doggy_machine_description me = (doggy_machine_description)fe_malloc(sizeof(*me));
  doggy_machine_description_src_info(me) = src_info;
  doggy_machine_description_id(me) = id;
  doggy_machine_description_defs(me) = defs;
  doggy_machine_description_supports(me) = supports;
  doggy_machine_description__num(me) = - 1;
  doggy_machine_description_scope(me) = NULL;
  doggy_machine_description_old_scope(me) = NULL;
  doggy_machine_description_id_bind(me) = NULL;
  return me;
}

doggy_Operation_def Create_doggy_Operation_def	(SrcInfo src_info, Ident id, List_doggy_Type types, doggy_Type result, Ident actual_id, doggy_Attributes descr, List_doggy_Property props)
{ doggy_Operation_def me = (doggy_Operation_def)fe_malloc(sizeof(*me));
  doggy_Operation_def_src_info(me) = src_info;
  doggy_Operation_def_id(me) = id;
  doggy_Operation_def_types(me) = types;
  doggy_Operation_def_result(me) = result;
  doggy_Operation_def_actual_id(me) = actual_id;
  doggy_Operation_def_descr(me) = descr;
  doggy_Operation_def_props(me) = props;
  doggy_Operation_def__num(me) = - 1;
  doggy_Operation_def_scope(me) = NULL;
  doggy_Operation_def_old_scope(me) = NULL;
  doggy_Operation_def_id_bind(me) = NULL;
  doggy_Operation_def_type(me) = Create_OprType (make_src_info (- 1), Operation_def_types (me));
  doggy_Operation_def_src(me) = FALSE;
  doggy_Operation_def_tgt(me) = FALSE;
  doggy_Operation_def_supported(me) = FALSE;
  doggy_Operation_def_mop(me) = NULL;
  doggy_Operation_def_value(me) = NoValue ();
  return me;
}

doggy_Attributes Create_doggy_Attributes	(SrcInfo src_info, List_doggy_Attribute ids, doggy_Attributes tail)
{ doggy_Attributes me = (doggy_Attributes)fe_malloc(sizeof(*me));
  doggy_Attributes_src_info(me) = src_info;
  doggy_Attributes_ids(me) = ids;
  doggy_Attributes_tail(me) = tail;
  return me;
}

doggy_IntAttr Create_doggy_IntAttr	(SrcInfo src_info, Int i)
{ doggy_IntAttr me = (doggy_IntAttr)fe_malloc(sizeof(*me));
  doggy_Attribute_src_info(me) = src_info;
  doggy_IntAttr_i(me) = i;
  doggy_Attribute_tag(me) = doggy_IntAttr_kind;
  return me;
}

doggy_OpAttr Create_doggy_OpAttr	(SrcInfo src_info)
{ doggy_OpAttr me = (doggy_OpAttr)fe_malloc(sizeof(*me));
  doggy_Attribute_src_info(me) = src_info;
  doggy_Attribute_tag(me) = doggy_OpAttr_kind;
  return me;
}

doggy_IdAttr Create_doggy_IdAttr	(SrcInfo src_info, Ident id)
{ doggy_IdAttr me = (doggy_IdAttr)fe_malloc(sizeof(*me));
  doggy_Attribute_src_info(me) = src_info;
  doggy_IdAttr_id(me) = id;
  doggy_Attribute_tag(me) = doggy_IdAttr_kind;
  return me;
}

doggy_RuleSection Create_doggy_RuleSection	(SrcInfo src_info, Ident rules_id, List_doggy_Rule rules)
{ doggy_RuleSection me = (doggy_RuleSection)fe_malloc(sizeof(*me));
  doggy_Section_src_info(me) = src_info;
  doggy_RuleSection_rules_id(me) = rules_id;
  doggy_RuleSection_rules(me) = rules;
  doggy_Section_tag(me) = doggy_RuleSection_kind;
  return me;
}

doggy_FuncSection Create_doggy_FuncSection	(SrcInfo src_info, List_doggy_Func funcs)
{ doggy_FuncSection me = (doggy_FuncSection)fe_malloc(sizeof(*me));
  doggy_Section_src_info(me) = src_info;
  doggy_FuncSection_funcs(me) = funcs;
  doggy_Section_tag(me) = doggy_FuncSection_kind;
  return me;
}

doggy_Rule Create_doggy_Rule	(SrcInfo src_info, doggy_Lhs lhs, doggy_Rhs rhs)
{ doggy_Rule me = (doggy_Rule)fe_malloc(sizeof(*me));
  doggy_Rule_src_info(me) = src_info;
  doggy_Rule_lhs(me) = lhs;
  doggy_Rule_rhs(me) = rhs;
  doggy_Rule__num(me) = - 1;
  doggy_Rule_scope(me) = NULL;
  doggy_Rule_old_scope(me) = NULL;
  doggy_Rule_rules_id(me) = NULL;
  doggy_Rule_supported(me) = TRUE;
  doggy_Rule_rhs_supported(me) = TRUE;
  return me;
}

doggy_UnLabeledLhs Create_doggy_UnLabeledLhs	(SrcInfo src_info, doggy_Pattern pat)
{ doggy_UnLabeledLhs me = (doggy_UnLabeledLhs)fe_malloc(sizeof(*me));
  doggy_Lhs_src_info(me) = src_info;
  doggy_Lhs_pat(me) = pat;
  doggy_Lhs_tag(me) = doggy_UnLabeledLhs_kind;
  return me;
}

doggy_LabeledLhs Create_doggy_LabeledLhs	(SrcInfo src_info, Ident id, doggy_Pattern pat)
{ doggy_LabeledLhs me = (doggy_LabeledLhs)fe_malloc(sizeof(*me));
  doggy_Lhs_src_info(me) = src_info;
  doggy_LabeledLhs_id(me) = id;
  doggy_Lhs_pat(me) = pat;
  doggy_Lhs_tag(me) = doggy_LabeledLhs_kind;
  return me;
}

doggy_Func Create_doggy_Func	(SrcInfo src_info, Bool ext, doggy_Type type, Ident id, List_doggy_FuncRule rules)
{ doggy_Func me = (doggy_Func)fe_malloc(sizeof(*me));
  doggy_Func_src_info(me) = src_info;
  doggy_Func_ext(me) = ext;
  doggy_Func_type(me) = type;
  doggy_Func_id(me) = id;
  doggy_Func_rules(me) = rules;
  doggy_Func__num(me) = - 1;
  doggy_Func_scope(me) = NULL;
  doggy_Func_old_scope(me) = NULL;
  doggy_Func_id_bind(me) = NULL;
  doggy_Func_args(me) = NULL;
  return me;
}

doggy_FuncRule Create_doggy_FuncRule	(SrcInfo src_info, List_doggy_Argument args, doggy_Rhs rhs)
{ doggy_FuncRule me = (doggy_FuncRule)fe_malloc(sizeof(*me));
  doggy_FuncRule_src_info(me) = src_info;
  doggy_FuncRule_args(me) = args;
  doggy_FuncRule_rhs(me) = rhs;
  doggy_FuncRule__num(me) = - 1;
  doggy_FuncRule_scope(me) = NULL;
  doggy_FuncRule_old_scope(me) = NULL;
  doggy_FuncRule_supported(me) = TRUE;
  return me;
}

doggy_UnTypedArg Create_doggy_UnTypedArg	(SrcInfo src_info, Ident id, doggy_ArgPat pat)
{ doggy_UnTypedArg me = (doggy_UnTypedArg)fe_malloc(sizeof(*me));
  doggy_Argument_src_info(me) = src_info;
  doggy_Argument_id(me) = id;
  doggy_Argument_pat(me) = pat;
  doggy_Argument__num(me) = - 1;
  doggy_Argument_scope(me) = NULL;
  doggy_Argument_old_scope(me) = NULL;
  doggy_Argument_tag(me) = doggy_UnTypedArg_kind;
  doggy_Argument_id_bind(me) = NULL;
  doggy_Argument_value(me) = NoValue ();
  return me;
}

doggy_TypedArg Create_doggy_TypedArg	(SrcInfo src_info, doggy_Type type, Ident id, doggy_ArgPat pat)
{ doggy_TypedArg me = (doggy_TypedArg)fe_malloc(sizeof(*me));
  doggy_Argument_src_info(me) = src_info;
  doggy_TypedArg_type(me) = type;
  doggy_Argument_id(me) = id;
  doggy_Argument_pat(me) = pat;
  doggy_Argument__num(me) = - 1;
  doggy_Argument_scope(me) = NULL;
  doggy_Argument_old_scope(me) = NULL;
  doggy_Argument_tag(me) = doggy_TypedArg_kind;
  doggy_Argument_id_bind(me) = NULL;
  doggy_Argument_value(me) = NoValue ();
  return me;
}

doggy_SetArg Create_doggy_SetArg	(SrcInfo src_info, doggy_Applied_operation set)
{ doggy_SetArg me = (doggy_SetArg)fe_malloc(sizeof(*me));
  doggy_ArgPat_src_info(me) = src_info;
  doggy_SetArg_set(me) = set;
  doggy_ArgPat_tag(me) = doggy_SetArg_kind;
  return me;
}

doggy_PatArg Create_doggy_PatArg	(SrcInfo src_info, doggy_Pattern pat)
{ doggy_PatArg me = (doggy_PatArg)fe_malloc(sizeof(*me));
  doggy_ArgPat_src_info(me) = src_info;
  doggy_PatArg_pat(me) = pat;
  doggy_ArgPat_tag(me) = doggy_PatArg_kind;
  return me;
}

doggy_DontCarePattern Create_doggy_DontCarePattern	(SrcInfo src_info, doggy_Expr expr)
{ doggy_DontCarePattern me = (doggy_DontCarePattern)fe_malloc(sizeof(*me));
  doggy_Pattern_src_info(me) = src_info;
  doggy_DontCarePattern_expr(me) = expr;
  doggy_Pattern__num(me) = - 1;
  doggy_Pattern_scope(me) = NULL;
  doggy_Pattern_old_scope(me) = NULL;
  doggy_Pattern_tag(me) = doggy_DontCarePattern_kind;
  doggy_Pattern_type(me) = NULL;
  doggy_Pattern__swap(me) = 0;
  doggy_Pattern_swap(me) = 0;
  doggy_Pattern__types(me) = 0;
  doggy_Pattern_types(me) = 0;
  doggy_Pattern_value(me) = NoValue ();
  return me;
}

doggy_NullPattern Create_doggy_NullPattern	(SrcInfo src_info)
{ doggy_NullPattern me = (doggy_NullPattern)fe_malloc(sizeof(*me));
  doggy_Pattern_src_info(me) = src_info;
  doggy_Pattern__num(me) = - 1;
  doggy_Pattern_scope(me) = NULL;
  doggy_Pattern_old_scope(me) = NULL;
  doggy_Pattern_tag(me) = doggy_NullPattern_kind;
  doggy_Pattern_type(me) = NULL;
  doggy_Pattern__swap(me) = 0;
  doggy_Pattern_swap(me) = 0;
  doggy_Pattern__types(me) = 0;
  doggy_Pattern_types(me) = 0;
  doggy_Pattern_value(me) = NoValue ();
  return me;
}

doggy_ConstPattern Create_doggy_ConstPattern	(SrcInfo src_info, Int cnst)
{ doggy_ConstPattern me = (doggy_ConstPattern)fe_malloc(sizeof(*me));
  doggy_Pattern_src_info(me) = src_info;
  doggy_ConstPattern_cnst(me) = cnst;
  doggy_Pattern__num(me) = - 1;
  doggy_Pattern_scope(me) = NULL;
  doggy_Pattern_old_scope(me) = NULL;
  doggy_Pattern_tag(me) = doggy_ConstPattern_kind;
  doggy_Pattern_type(me) = NULL;
  doggy_Pattern__swap(me) = 0;
  doggy_Pattern_swap(me) = 0;
  doggy_Pattern__types(me) = 0;
  doggy_Pattern_types(me) = 0;
  doggy_Pattern_value(me) = NoValue ();
  return me;
}

doggy_OpPattern Create_doggy_OpPattern	(SrcInfo src_info, doggy_Applied_operation op, List_doggy_Pattern args)
{ doggy_OpPattern me = (doggy_OpPattern)fe_malloc(sizeof(*me));
  doggy_Pattern_src_info(me) = src_info;
  doggy_OpPattern_op(me) = op;
  doggy_OpPattern_args(me) = args;
  doggy_Pattern__num(me) = - 1;
  doggy_Pattern_scope(me) = NULL;
  doggy_Pattern_old_scope(me) = NULL;
  doggy_Pattern_tag(me) = doggy_OpPattern_kind;
  doggy_Pattern_type(me) = NULL;
  doggy_Pattern__swap(me) = 0;
  doggy_Pattern_swap(me) = 0;
  doggy_Pattern__types(me) = 0;
  doggy_Pattern_types(me) = 0;
  doggy_Pattern_value(me) = NoValue ();
  return me;
}

doggy_IdentPattern Create_doggy_IdentPattern	(SrcInfo src_info, Ident id)
{ doggy_IdentPattern me = (doggy_IdentPattern)fe_malloc(sizeof(*me));
  doggy_Pattern_src_info(me) = src_info;
  doggy_IdentPattern_id(me) = id;
  doggy_Pattern__num(me) = - 1;
  doggy_Pattern_scope(me) = NULL;
  doggy_Pattern_old_scope(me) = NULL;
  doggy_Pattern_tag(me) = doggy_IdentPattern_kind;
  doggy_IdentPattern_id_bind(me) = NULL;
  doggy_IdentPattern_def(me) = NULL;
  doggy_IdentPattern_use_cnt(me) = 0;
  doggy_Pattern_type(me) = NULL;
  doggy_Pattern__swap(me) = 0;
  doggy_Pattern_swap(me) = 0;
  doggy_Pattern__types(me) = 0;
  doggy_Pattern_types(me) = 0;
  doggy_Pattern_value(me) = NoValue ();
  return me;
}

doggy_DefPattern Create_doggy_DefPattern	(SrcInfo src_info, List_doggy_Pattern ids, doggy_Pattern arg)
{ doggy_DefPattern me = (doggy_DefPattern)fe_malloc(sizeof(*me));
  doggy_Pattern_src_info(me) = src_info;
  doggy_DefPattern_ids(me) = ids;
  doggy_DefPattern_arg(me) = arg;
  doggy_Pattern__num(me) = - 1;
  doggy_Pattern_scope(me) = NULL;
  doggy_Pattern_old_scope(me) = NULL;
  doggy_Pattern_tag(me) = doggy_DefPattern_kind;
  init_ident_patterns (DefPattern_ids (me), me);
  doggy_DefPattern_use_cnt(me) = 0;
  doggy_Pattern_type(me) = NULL;
  doggy_Pattern__swap(me) = 0;
  doggy_Pattern_swap(me) = 0;
  doggy_Pattern__types(me) = 0;
  doggy_Pattern_types(me) = 0;
  doggy_Pattern_value(me) = NoValue ();
  return me;
}

doggy_ConsPattern Create_doggy_ConsPattern	(SrcInfo src_info, doggy_Pattern lhs, doggy_Pattern rhs)
{ doggy_ConsPattern me = (doggy_ConsPattern)fe_malloc(sizeof(*me));
  doggy_Pattern_src_info(me) = src_info;
  doggy_ConsPattern_lhs(me) = lhs;
  doggy_ConsPattern_rhs(me) = rhs;
  doggy_Pattern__num(me) = - 1;
  doggy_Pattern_scope(me) = NULL;
  doggy_Pattern_old_scope(me) = NULL;
  doggy_Pattern_tag(me) = doggy_ConsPattern_kind;
  doggy_Pattern_type(me) = NULL;
  doggy_Pattern__swap(me) = 0;
  doggy_Pattern_swap(me) = 0;
  doggy_Pattern__types(me) = 0;
  doggy_Pattern_types(me) = 0;
  doggy_Pattern_value(me) = NoValue ();
  return me;
}

doggy_TypedPattern Create_doggy_TypedPattern	(SrcInfo src_info, doggy_Type btype, doggy_Pattern pat)
{ doggy_TypedPattern me = (doggy_TypedPattern)fe_malloc(sizeof(*me));
  doggy_Pattern_src_info(me) = src_info;
  doggy_TypedPattern_btype(me) = btype;
  doggy_TypedPattern_pat(me) = pat;
  doggy_Pattern__num(me) = - 1;
  doggy_Pattern_scope(me) = NULL;
  doggy_Pattern_old_scope(me) = NULL;
  doggy_Pattern_tag(me) = doggy_TypedPattern_kind;
  doggy_Pattern_type(me) = NULL;
  doggy_Pattern__swap(me) = 0;
  doggy_Pattern_swap(me) = 0;
  doggy_Pattern__types(me) = 0;
  doggy_Pattern_types(me) = 0;
  doggy_Pattern_value(me) = NoValue ();
  return me;
}

doggy_BlockRhs Create_doggy_BlockRhs	(SrcInfo src_info, doggy_Rhs rhs, doggy_Wherepart where)
{ doggy_BlockRhs me = (doggy_BlockRhs)fe_malloc(sizeof(*me));
  doggy_Rhs_src_info(me) = src_info;
  doggy_BlockRhs_rhs(me) = rhs;
  doggy_BlockRhs_where(me) = where;
  doggy_Rhs_tag(me) = doggy_BlockRhs_kind;
  return me;
}

doggy_PlainRhs Create_doggy_PlainRhs	(SrcInfo src_info, List_doggy_Guard guards)
{ doggy_PlainRhs me = (doggy_PlainRhs)fe_malloc(sizeof(*me));
  doggy_Rhs_src_info(me) = src_info;
  doggy_PlainRhs_guards(me) = guards;
  doggy_Rhs_tag(me) = doggy_PlainRhs_kind;
  return me;
}

doggy_ExprGuard Create_doggy_ExprGuard	(SrcInfo src_info, doggy_Expr conds, doggy_ExprSeq exprs, doggy_Wherepart where)
{ doggy_ExprGuard me = (doggy_ExprGuard)fe_malloc(sizeof(*me));
  doggy_Guard_src_info(me) = src_info;
  doggy_Guard_conds(me) = conds;
  doggy_ExprGuard_exprs(me) = exprs;
  doggy_Guard_where(me) = where;
  doggy_Guard__num(me) = - 1;
  doggy_Guard_scope(me) = NULL;
  doggy_Guard_old_scope(me) = NULL;
  doggy_Guard_tag(me) = doggy_ExprGuard_kind;
  return me;
}

doggy_RhsGuard Create_doggy_RhsGuard	(SrcInfo src_info, doggy_Expr conds, doggy_Rhs rhs, doggy_Wherepart where)
{ doggy_RhsGuard me = (doggy_RhsGuard)fe_malloc(sizeof(*me));
  doggy_Guard_src_info(me) = src_info;
  doggy_Guard_conds(me) = conds;
  doggy_RhsGuard_rhs(me) = rhs;
  doggy_Guard_where(me) = where;
  doggy_Guard__num(me) = - 1;
  doggy_Guard_scope(me) = NULL;
  doggy_Guard_old_scope(me) = NULL;
  doggy_Guard_tag(me) = doggy_RhsGuard_kind;
  return me;
}

doggy_MoreExprs Create_doggy_MoreExprs	(SrcInfo src_info, List_doggy_Expr exprs)
{ doggy_MoreExprs me = (doggy_MoreExprs)fe_malloc(sizeof(*me));
  doggy_ExprSeq_src_info(me) = src_info;
  doggy_MoreExprs_exprs(me) = exprs;
  doggy_ExprSeq_tag(me) = doggy_MoreExprs_kind;
  return me;
}

doggy_OneExpr Create_doggy_OneExpr	(SrcInfo src_info, doggy_Expr expr)
{ doggy_OneExpr me = (doggy_OneExpr)fe_malloc(sizeof(*me));
  doggy_ExprSeq_src_info(me) = src_info;
  doggy_OneExpr_expr(me) = expr;
  doggy_ExprSeq_tag(me) = doggy_OneExpr_kind;
  return me;
}

doggy_Wherepart Create_doggy_Wherepart	(SrcInfo src_info, List_doggy_Definition defs)
{ doggy_Wherepart me = (doggy_Wherepart)fe_malloc(sizeof(*me));
  doggy_Wherepart_src_info(me) = src_info;
  doggy_Wherepart_defs(me) = defs;
  return me;
}

doggy_OpSet Create_doggy_OpSet	(SrcInfo src_info, List_doggy_Applied_formal ops)
{ doggy_OpSet me = (doggy_OpSet)fe_malloc(sizeof(*me));
  doggy_Applied_operation_src_info(me) = src_info;
  doggy_OpSet_ops(me) = ops;
  doggy_Applied_operation__num(me) = - 1;
  doggy_Applied_operation_scope(me) = NULL;
  doggy_Applied_operation_old_scope(me) = NULL;
  doggy_Applied_operation_tag(me) = doggy_OpSet_kind;
  return me;
}

doggy_AppliedOp Create_doggy_AppliedOp	(SrcInfo src_info, doggy_Applied_formal op)
{ doggy_AppliedOp me = (doggy_AppliedOp)fe_malloc(sizeof(*me));
  doggy_Applied_operation_src_info(me) = src_info;
  doggy_AppliedOp_op(me) = op;
  doggy_Applied_operation__num(me) = - 1;
  doggy_Applied_operation_scope(me) = NULL;
  doggy_Applied_operation_old_scope(me) = NULL;
  doggy_Applied_operation_tag(me) = doggy_AppliedOp_kind;
  return me;
}

doggy_AnyOp Create_doggy_AnyOp	(SrcInfo src_info)
{ doggy_AnyOp me = (doggy_AnyOp)fe_malloc(sizeof(*me));
  doggy_Applied_operation_src_info(me) = src_info;
  doggy_Applied_operation__num(me) = - 1;
  doggy_Applied_operation_scope(me) = NULL;
  doggy_Applied_operation_old_scope(me) = NULL;
  doggy_Applied_operation_tag(me) = doggy_AnyOp_kind;
  return me;
}

doggy_Applied_formal Create_doggy_Applied_formal	(SrcInfo src_info, Ident id)
{ doggy_Applied_formal me = (doggy_Applied_formal)fe_malloc(sizeof(*me));
  doggy_Applied_formal_src_info(me) = src_info;
  doggy_Applied_formal_id(me) = id;
  doggy_Applied_formal__num(me) = - 1;
  doggy_Applied_formal_scope(me) = NULL;
  doggy_Applied_formal_old_scope(me) = NULL;
  doggy_Applied_formal_ap_bind(me) = NULL;
  doggy_Applied_formal_ap(me) = NULL;
  return me;
}

doggy_MonExpr Create_doggy_MonExpr	(SrcInfo src_info, doggy_MonOp op, doggy_Expr arg)
{ doggy_MonExpr me = (doggy_MonExpr)fe_malloc(sizeof(*me));
  doggy_Expr_src_info(me) = src_info;
  doggy_MonExpr_op(me) = op;
  doggy_MonExpr_arg(me) = arg;
  doggy_Expr__num(me) = - 1;
  doggy_Expr_scope(me) = NULL;
  doggy_Expr_old_scope(me) = NULL;
  doggy_Expr_tag(me) = doggy_MonExpr_kind;
  doggy_Expr_warned(me) = FALSE;
  return me;
}

doggy_ParExpr Create_doggy_ParExpr	(SrcInfo src_info, doggy_Expr expr)
{ doggy_ParExpr me = (doggy_ParExpr)fe_malloc(sizeof(*me));
  doggy_Expr_src_info(me) = src_info;
  doggy_ParExpr_expr(me) = expr;
  doggy_Expr__num(me) = - 1;
  doggy_Expr_scope(me) = NULL;
  doggy_Expr_old_scope(me) = NULL;
  doggy_Expr_tag(me) = doggy_ParExpr_kind;
  doggy_Expr_warned(me) = FALSE;
  return me;
}

doggy_Operation Create_doggy_Operation	(SrcInfo src_info, Ident id, List_doggy_Expr args)
{ doggy_Operation me = (doggy_Operation)fe_malloc(sizeof(*me));
  doggy_Expr_src_info(me) = src_info;
  doggy_Operation_id(me) = id;
  doggy_Operation_args(me) = args;
  doggy_Expr__num(me) = - 1;
  doggy_Expr_scope(me) = NULL;
  doggy_Expr_old_scope(me) = NULL;
  doggy_Expr_tag(me) = doggy_Operation_kind;
  doggy_Expr_warned(me) = FALSE;
  doggy_Operation_operator_bind(me) = NULL;
  doggy_Operation_operator(me) = NULL;
  doggy_Operation_defi_bind(me) = NULL;
  doggy_Operation_defi(me) = NULL;
  doggy_Operation_ext_bind(me) = NULL;
  doggy_Operation_ext(me) = NULL;
  doggy_Operation_func_bind(me) = NULL;
  doggy_Operation_func(me) = NULL;
  return me;
}

doggy_ConstExpr Create_doggy_ConstExpr	(SrcInfo src_info, doggy_Constant cnst)
{ doggy_ConstExpr me = (doggy_ConstExpr)fe_malloc(sizeof(*me));
  doggy_Expr_src_info(me) = src_info;
  doggy_ConstExpr_cnst(me) = cnst;
  doggy_Expr__num(me) = - 1;
  doggy_Expr_scope(me) = NULL;
  doggy_Expr_old_scope(me) = NULL;
  doggy_Expr_tag(me) = doggy_ConstExpr_kind;
  doggy_Expr_warned(me) = FALSE;
  return me;
}

doggy_IfExpr Create_doggy_IfExpr	(SrcInfo src_info, doggy_Expr cond, doggy_Expr thn, List_doggy_Expr conds, List_doggy_Expr thens, doggy_Expr els)
{ doggy_IfExpr me = (doggy_IfExpr)fe_malloc(sizeof(*me));
  doggy_Expr_src_info(me) = src_info;
  doggy_IfExpr_cond(me) = cond;
  doggy_IfExpr_thn(me) = thn;
  doggy_IfExpr_conds(me) = conds;
  doggy_IfExpr_thens(me) = thens;
  doggy_IfExpr_els(me) = els;
  doggy_Expr__num(me) = - 1;
  doggy_Expr_scope(me) = NULL;
  doggy_Expr_old_scope(me) = NULL;
  doggy_Expr_tag(me) = doggy_IfExpr_kind;
  doggy_Expr_warned(me) = FALSE;
  return me;
}

doggy_IdentExpr Create_doggy_IdentExpr	(SrcInfo src_info, Ident id)
{ doggy_IdentExpr me = (doggy_IdentExpr)fe_malloc(sizeof(*me));
  doggy_Expr_src_info(me) = src_info;
  doggy_IdentExpr_id(me) = id;
  doggy_Expr__num(me) = - 1;
  doggy_Expr_scope(me) = NULL;
  doggy_Expr_old_scope(me) = NULL;
  doggy_Expr_tag(me) = doggy_IdentExpr_kind;
  doggy_Expr_warned(me) = FALSE;
  doggy_IdentExpr_operator_bind(me) = NULL;
  doggy_IdentExpr_operator(me) = NULL;
  doggy_IdentExpr_pattern_bind(me) = NULL;
  doggy_IdentExpr_pattern(me) = NULL;
  doggy_IdentExpr_ext_bind(me) = NULL;
  doggy_IdentExpr_ext(me) = NULL;
  doggy_IdentExpr_def_bind(me) = NULL;
  doggy_IdentExpr_def(me) = NULL;
  doggy_IdentExpr_arg_bind(me) = NULL;
  doggy_IdentExpr_arg(me) = NULL;
  doggy_IdentExpr_use_cnt(me) = 0;
  return me;
}

doggy_ConsExpr Create_doggy_ConsExpr	(SrcInfo src_info, doggy_Expr lhs, doggy_Expr rhs)
{ doggy_ConsExpr me = (doggy_ConsExpr)fe_malloc(sizeof(*me));
  doggy_Expr_src_info(me) = src_info;
  doggy_ConsExpr_lhs(me) = lhs;
  doggy_ConsExpr_rhs(me) = rhs;
  doggy_Expr__num(me) = - 1;
  doggy_Expr_scope(me) = NULL;
  doggy_Expr_old_scope(me) = NULL;
  doggy_Expr_tag(me) = doggy_ConsExpr_kind;
  doggy_Expr_warned(me) = FALSE;
  return me;
}

doggy_BinExpr Create_doggy_BinExpr	(SrcInfo src_info, List_doggy_Expr args, List_doggy_Operator ops)
{ doggy_BinExpr me = (doggy_BinExpr)fe_malloc(sizeof(*me));
  doggy_Expr_src_info(me) = src_info;
  doggy_BinExpr_args(me) = args;
  doggy_BinExpr_ops(me) = ops;
  doggy_Expr__num(me) = - 1;
  doggy_Expr_scope(me) = NULL;
  doggy_Expr_old_scope(me) = NULL;
  doggy_Expr_tag(me) = doggy_BinExpr_kind;
  doggy_Expr_warned(me) = FALSE;
  return me;
}

doggy_NullConst Create_doggy_NullConst	(SrcInfo src_info)
{ doggy_NullConst me = (doggy_NullConst)fe_malloc(sizeof(*me));
  doggy_Constant_src_info(me) = src_info;
  doggy_Constant_tag(me) = doggy_NullConst_kind;
  return me;
}

doggy_StringConst Create_doggy_StringConst	(SrcInfo src_info, String s)
{ doggy_StringConst me = (doggy_StringConst)fe_malloc(sizeof(*me));
  doggy_Constant_src_info(me) = src_info;
  doggy_StringConst_s(me) = s;
  doggy_Constant_tag(me) = doggy_StringConst_kind;
  return me;
}

doggy_BoolConst Create_doggy_BoolConst	(SrcInfo src_info, Bool b)
{ doggy_BoolConst me = (doggy_BoolConst)fe_malloc(sizeof(*me));
  doggy_Constant_src_info(me) = src_info;
  doggy_BoolConst_b(me) = b;
  doggy_Constant_tag(me) = doggy_BoolConst_kind;
  return me;
}

doggy_IntConst Create_doggy_IntConst	(SrcInfo src_info, Int i)
{ doggy_IntConst me = (doggy_IntConst)fe_malloc(sizeof(*me));
  doggy_Constant_src_info(me) = src_info;
  doggy_IntConst_i(me) = i;
  doggy_Constant_tag(me) = doggy_IntConst_kind;
  return me;
}

doggy_Definition Create_doggy_Definition	(SrcInfo src_info, doggy_Type type, Ident id, doggy_Expr expr)
{ doggy_Definition me = (doggy_Definition)fe_malloc(sizeof(*me));
  doggy_Definition_src_info(me) = src_info;
  doggy_Definition_type(me) = type;
  doggy_Definition_id(me) = id;
  doggy_Definition_expr(me) = expr;
  doggy_Definition__num(me) = - 1;
  doggy_Definition_scope(me) = NULL;
  doggy_Definition_old_scope(me) = NULL;
  doggy_Definition_id_bind(me) = NULL;
  doggy_Definition_value(me) = NoValue ();
  doggy_Definition_order(me) = - 1;
  doggy_Definition_use_cnt(me) = 0;
  return me;
}

doggy_FRangeType Create_doggy_FRangeType	(SrcInfo src_info, Ident f)
{ doggy_FRangeType me = (doggy_FRangeType)fe_malloc(sizeof(*me));
  doggy_Type_src_info(me) = src_info;
  doggy_FRangeType_f(me) = f;
  doggy_Type__num(me) = - 1;
  doggy_Type_scope(me) = NULL;
  doggy_Type_old_scope(me) = NULL;
  doggy_Type_tag(me) = doggy_FRangeType_kind;
  return me;
}

doggy_RangeType Create_doggy_RangeType	(SrcInfo src_info, doggy_Num lo, doggy_Num hi, doggy_Num step)
{ doggy_RangeType me = (doggy_RangeType)fe_malloc(sizeof(*me));
  doggy_Type_src_info(me) = src_info;
  doggy_RangeType_lo(me) = lo;
  doggy_RangeType_hi(me) = hi;
  doggy_RangeType_step(me) = step;
  doggy_Type__num(me) = - 1;
  doggy_Type_scope(me) = NULL;
  doggy_Type_old_scope(me) = NULL;
  doggy_Type_tag(me) = doggy_RangeType_kind;
  return me;
}

doggy_PointerType Create_doggy_PointerType	(SrcInfo src_info, doggy_Type base)
{ doggy_PointerType me = (doggy_PointerType)fe_malloc(sizeof(*me));
  doggy_Type_src_info(me) = src_info;
  doggy_PointerType_base(me) = base;
  doggy_Type__num(me) = - 1;
  doggy_Type_scope(me) = NULL;
  doggy_Type_old_scope(me) = NULL;
  doggy_Type_tag(me) = doggy_PointerType_kind;
  return me;
}

doggy_OprType Create_doggy_OprType	(SrcInfo src_info, List_doggy_Type args)
{ doggy_OprType me = (doggy_OprType)fe_malloc(sizeof(*me));
  doggy_Type_src_info(me) = src_info;
  doggy_OprType_args(me) = args;
  doggy_Type__num(me) = - 1;
  doggy_Type_scope(me) = NULL;
  doggy_Type_old_scope(me) = NULL;
  doggy_Type_tag(me) = doggy_OprType_kind;
  return me;
}

doggy_IdentType Create_doggy_IdentType	(SrcInfo src_info, Ident type_id)
{ doggy_IdentType me = (doggy_IdentType)fe_malloc(sizeof(*me));
  doggy_Type_src_info(me) = src_info;
  doggy_IdentType_type_id(me) = type_id;
  doggy_Type__num(me) = - 1;
  doggy_Type_scope(me) = NULL;
  doggy_Type_old_scope(me) = NULL;
  doggy_Type_tag(me) = doggy_IdentType_kind;
  doggy_IdentType_type_bind(me) = NULL;
  doggy_IdentType_type(me) = NULL;
  return me;
}

doggy_TupleType Create_doggy_TupleType	(SrcInfo src_info, List_doggy_Type types)
{ doggy_TupleType me = (doggy_TupleType)fe_malloc(sizeof(*me));
  doggy_Type_src_info(me) = src_info;
  doggy_TupleType_types(me) = types;
  doggy_Type__num(me) = - 1;
  doggy_Type_scope(me) = NULL;
  doggy_Type_old_scope(me) = NULL;
  doggy_Type_tag(me) = doggy_TupleType_kind;
  return me;
}

doggy_EdgeType Create_doggy_EdgeType	(SrcInfo src_info, List_doggy_Type types)
{ doggy_EdgeType me = (doggy_EdgeType)fe_malloc(sizeof(*me));
  doggy_Type_src_info(me) = src_info;
  doggy_EdgeType_types(me) = types;
  doggy_Type__num(me) = - 1;
  doggy_Type_scope(me) = NULL;
  doggy_Type_old_scope(me) = NULL;
  doggy_Type_tag(me) = doggy_EdgeType_kind;
  return me;
}

doggy_Num Create_doggy_Num	(SrcInfo src_info, Bool neg, Int i)
{ doggy_Num me = (doggy_Num)fe_malloc(sizeof(*me));
  doggy_Num_src_info(me) = src_info;
  doggy_Num_neg(me) = neg;
  doggy_Num_i(me) = i;
  num_negate (me);
  return me;
}

doggy_IsInt Create_doggy_IsInt	(SrcInfo src_info, Int i)
{ doggy_IsInt me = (doggy_IsInt)fe_malloc(sizeof(*me));
  doggy_IdInt_src_info(me) = src_info;
  doggy_IsInt_i(me) = i;
  doggy_IdInt_tag(me) = doggy_IsInt_kind;
  return me;
}

doggy_IsId Create_doggy_IsId	(SrcInfo src_info, Ident id)
{ doggy_IsId me = (doggy_IsId)fe_malloc(sizeof(*me));
  doggy_IdInt_src_info(me) = src_info;
  doggy_IsId_id(me) = id;
  doggy_IdInt_tag(me) = doggy_IsId_kind;
  return me;
}

doggy_Path Create_doggy_Path	(SrcInfo src_info, Int data, doggy_Type type, doggy_Path next)
{ doggy_Path me = (doggy_Path)fe_malloc(sizeof(*me));
  doggy_Path_src_info(me) = src_info;
  doggy_Path_data(me) = data;
  doggy_Path_type(me) = type;
  doggy_Path_next(me) = next;
  return me;
}

doggy_ActualOp Create_doggy_ActualOp	(SrcInfo src_info, Int location, Ident id, List_doggy_Operation_def formals)
{ doggy_ActualOp me = (doggy_ActualOp)fe_malloc(sizeof(*me));
  doggy_ActualOp_src_info(me) = src_info;
  doggy_ActualOp_location(me) = location;
  doggy_ActualOp_id(me) = id;
  doggy_ActualOp_formals(me) = formals;
  doggy_ActualOp_overloaded(me) = FALSE;
  doggy_ActualOp_src(me) = FALSE;
  doggy_ActualOp_tgt(me) = FALSE;
  return me;
}

doggy_TypePair Create_doggy_TypePair	(SrcInfo src_info, doggy_Type t1, doggy_Type t2)
{ doggy_TypePair me = (doggy_TypePair)fe_malloc(sizeof(*me));
  doggy_TypePair_src_info(me) = src_info;
  doggy_TypePair_t1(me) = t1;
  doggy_TypePair_t2(me) = t2;
  return me;
}

static doggy_Opat *doggy_Opat_memo_table = NULL;

void Memo_Traverse_doggy_Opat (void (*f)(doggy_Opat))
{ int i;
  for (i=0; i < 1024; i++) {
    doggy_Opat _qqqq;
    for (_qqqq = doggy_Opat_memo_table[i]; _qqqq != NULL; _qqqq = _qqqq->memo_link) {
      f(_qqqq);
    }
  }
}

void Memo_Clear_doggy_Opat (void)
{ int i;
  if (!doggy_Opat_memo_table) return;
  for (i=0; i < 1024; i++) {
    doggy_Opat_memo_table[i] = NULL;
  }
}

doggy_Opat Create_doggy_Opat	(SrcInfo src_info, List_doggy_Type args, doggy_Type result)
{ doggy_Opat me;
  {
    unsigned int _hash = (0+(unsigned int)args+(unsigned int)result)/sizeof(int*) % 1024;
    doggy_Opat *_qqqq;
    if (doggy_Opat_memo_table==NULL)
    { int i;
      doggy_Opat_memo_table = (doggy_Opat*)fe_malloc (sizeof(*doggy_Opat_memo_table)*1024);
      for (i=0; i < 1024; i++){ doggy_Opat_memo_table[i] = NULL; }
    }
    for (_qqqq = &doggy_Opat_memo_table[_hash]; *_qqqq != NULL; _qqqq = &(*_qqqq)->memo_link) {
      { int _compare = compare_types (doggy_Opat_args(*_qqqq), args);
        if (_compare < 0) continue;
        if (_compare > 0) break;
      }
      if (doggy_Opat_result(*_qqqq) > result) break;
      if (doggy_Opat_result(*_qqqq) < result) continue;
      return *_qqqq;
    }
    me = (doggy_Opat)fe_malloc (sizeof(*me));
    me->memo_link = *_qqqq;
    *_qqqq = me;
  }
  doggy_Opat_src_info(me) = src_info;
  doggy_Opat_args(me) = args;
  doggy_Opat_result(me) = result;
  doggy_Opat_memo_link(me) = doggy_Opat_memo_link (me);
  doggy_Opat_num(me) = 0;
  return me;
}

static doggy_Format *doggy_Format_memo_table = NULL;

void Memo_Traverse_doggy_Format (void (*f)(doggy_Format))
{ int i;
  for (i=0; i < 1024; i++) {
    doggy_Format _qqqq;
    for (_qqqq = doggy_Format_memo_table[i]; _qqqq != NULL; _qqqq = _qqqq->memo_link) {
      f(_qqqq);
    }
  }
}

void Memo_Clear_doggy_Format (void)
{ int i;
  if (!doggy_Format_memo_table) return;
  for (i=0; i < 1024; i++) {
    doggy_Format_memo_table[i] = NULL;
  }
}

doggy_Format Create_doggy_Format	(SrcInfo src_info, List_doggy_Type args, doggy_Type result, Bool swap)
{ doggy_Format me;
  {
    unsigned int _hash = (0+(unsigned int)args+(unsigned int)result+(unsigned int)swap)/sizeof(int*) % 1024;
    doggy_Format *_qqqq;
    if (doggy_Format_memo_table==NULL)
    { int i;
      doggy_Format_memo_table = (doggy_Format*)fe_malloc (sizeof(*doggy_Format_memo_table)*1024);
      for (i=0; i < 1024; i++){ doggy_Format_memo_table[i] = NULL; }
    }
    for (_qqqq = &doggy_Format_memo_table[_hash]; *_qqqq != NULL; _qqqq = &(*_qqqq)->memo_link) {
      { int _compare = compare_types (doggy_Format_args(*_qqqq), args);
        if (_compare < 0) continue;
        if (_compare > 0) break;
      }
      if (doggy_Format_result(*_qqqq) > result) break;
      if (doggy_Format_result(*_qqqq) < result) continue;
      if (doggy_Format_swap(*_qqqq) > swap) break;
      if (doggy_Format_swap(*_qqqq) < swap) continue;
      return *_qqqq;
    }
    me = (doggy_Format)fe_malloc (sizeof(*me));
    me->memo_link = *_qqqq;
    *_qqqq = me;
  }
  doggy_Format_src_info(me) = src_info;
  doggy_Format_args(me) = args;
  doggy_Format_result(me) = result;
  doggy_Format_swap(me) = swap;
  doggy_Format_memo_link(me) = doggy_Format_memo_link (me);
  doggy_Format_num(me) = 0;
  return me;
}

doggy_dummy_type Create_doggy_dummy_type	(SrcInfo src_info, List_Ident a, List_doggy_ActualOp y, List_doggy_TypePair z)
{ doggy_dummy_type me = (doggy_dummy_type)fe_malloc(sizeof(*me));
  doggy_dummy_type_src_info(me) = src_info;
  doggy_dummy_type_a(me) = a;
  doggy_dummy_type_y(me) = y;
  doggy_dummy_type_z(me) = z;
  doggy_dummy_type_x(me) = NULL;
  doggy_dummy_type_b(me) = NULL;
  return me;
}

doggy_machine_descriptionScope Create_doggy_machine_descriptionScope	(doggy_Scope next, doggy_machine_description data)
{ doggy_machine_descriptionScope me = (doggy_machine_descriptionScope)fe_malloc(sizeof(*me));
  doggy_Scope_next(me) = next;
  doggy_machine_descriptionScope_data(me) = data;
  doggy_Scope__self(me) = 0;
  doggy_Scope__end(me) = 0;
  doggy_Scope_tag(me) = doggy_machine_descriptionScope_kind;
  return me;
}

doggy_RuleScope Create_doggy_RuleScope	(doggy_Scope next, doggy_Rule data)
{ doggy_RuleScope me = (doggy_RuleScope)fe_malloc(sizeof(*me));
  doggy_Scope_next(me) = next;
  doggy_RuleScope_data(me) = data;
  doggy_Scope__self(me) = 0;
  doggy_Scope__end(me) = 0;
  doggy_Scope_tag(me) = doggy_RuleScope_kind;
  return me;
}

doggy_FuncRuleScope Create_doggy_FuncRuleScope	(doggy_Scope next, doggy_FuncRule data)
{ doggy_FuncRuleScope me = (doggy_FuncRuleScope)fe_malloc(sizeof(*me));
  doggy_Scope_next(me) = next;
  doggy_FuncRuleScope_data(me) = data;
  doggy_Scope__self(me) = 0;
  doggy_Scope__end(me) = 0;
  doggy_Scope_tag(me) = doggy_FuncRuleScope_kind;
  return me;
}

doggy_RhsGuardScope Create_doggy_RhsGuardScope	(doggy_Scope next, doggy_Guard data)
{ doggy_RhsGuardScope me = (doggy_RhsGuardScope)fe_malloc(sizeof(*me));
  doggy_Scope_next(me) = next;
  doggy_RhsGuardScope_data(me) = data;
  doggy_Scope__self(me) = 0;
  doggy_Scope__end(me) = 0;
  doggy_Scope_tag(me) = doggy_RhsGuardScope_kind;
  return me;
}

doggy_ExprGuardScope Create_doggy_ExprGuardScope	(doggy_Scope next, doggy_Guard data)
{ doggy_ExprGuardScope me = (doggy_ExprGuardScope)fe_malloc(sizeof(*me));
  doggy_Scope_next(me) = next;
  doggy_ExprGuardScope_data(me) = data;
  doggy_Scope__self(me) = 0;
  doggy_Scope__end(me) = 0;
  doggy_Scope_tag(me) = doggy_ExprGuardScope_kind;
  return me;
}

doggy_AppliedOpScope Create_doggy_AppliedOpScope	(doggy_Scope next, doggy_Applied_operation data)
{ doggy_AppliedOpScope me = (doggy_AppliedOpScope)fe_malloc(sizeof(*me));
  doggy_Scope_next(me) = next;
  doggy_AppliedOpScope_data(me) = data;
  doggy_Scope__self(me) = 0;
  doggy_Scope__end(me) = 0;
  doggy_Scope_tag(me) = doggy_AppliedOpScope_kind;
  return me;
}

doggy_OpSetScope Create_doggy_OpSetScope	(doggy_Scope next, doggy_Applied_operation data)
{ doggy_OpSetScope me = (doggy_OpSetScope)fe_malloc(sizeof(*me));
  doggy_Scope_next(me) = next;
  doggy_OpSetScope_data(me) = data;
  doggy_Scope__self(me) = 0;
  doggy_Scope__end(me) = 0;
  doggy_Scope_tag(me) = doggy_OpSetScope_kind;
  return me;
}

Pointer Traverse_doggy_doggy (doggy_doggy me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(doggy, me)) return val;
  if (action->action_doggy[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_doggy[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_doggy)
  { 
  if (!action->skip_children_doggy) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Typedef (doggy_doggy_types(me), action, val);
    else Traverse_List_doggy_Typedef (doggy_doggy_types(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_machine_description (doggy_doggy_source(me), action, val);
    else Traverse_doggy_machine_description (doggy_doggy_source(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_machine_description (doggy_doggy_target(me), action, val);
    else Traverse_doggy_machine_description (doggy_doggy_target(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_FunctionDef (doggy_doggy_funcs(me), action, val);
    else Traverse_List_doggy_FunctionDef (doggy_doggy_funcs(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Section (doggy_doggy_sections(me), action, val);
    else Traverse_List_doggy_Section (doggy_doggy_sections(me), action, val);
  }
  }
  if (action->action_doggy[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_doggy[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Typedef (doggy_Typedef me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Typedef, me)) return val;
  if (action->action_Typedef[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Typedef[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Typedef)
  { 
  if (!action->skip_children_Typedef) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Attributes (doggy_Typedef_attrs(me), action, val);
    else Traverse_doggy_Attributes (doggy_Typedef_attrs(me), action, val);
  }
  }
  if (action->action_Typedef[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Typedef[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_FunctionDef (doggy_FunctionDef me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(FunctionDef, me)) return val;
  if (action->action_FunctionDef[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_FunctionDef[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_FunctionDef)
  { switch (doggy_FunctionDef_tag(me)) {
      case doggy_ExtFunc_kind:
        if (action->action_ExtFunc[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ExtFunc[PRE_ACTION](me, val);
        }
        if (!action->skip_children_FunctionDef) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_FunctionDef_result(me), action, val);
          else Traverse_doggy_Type (doggy_FunctionDef_result(me), action, val);
        }
        if (!action->skip_children_ExtFunc) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Type (doggy_ExtFunc_args(me), action, val);
          else Traverse_List_doggy_Type (doggy_ExtFunc_args(me), action, val);
        }
        if (action->action_ExtFunc[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ExtFunc[POST_ACTION](me, val);
        }
        break;
      case doggy_ExtVar_kind:
        if (action->action_ExtVar[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ExtVar[PRE_ACTION](me, val);
        }
        if (!action->skip_children_FunctionDef) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_FunctionDef_result(me), action, val);
          else Traverse_doggy_Type (doggy_FunctionDef_result(me), action, val);
        }
        if (action->action_ExtVar[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ExtVar[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_FunctionDef[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_FunctionDef[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_machine_description (doggy_machine_description me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(machine_description, me)) return val;
  if (action->action_machine_description[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_machine_description[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_machine_description)
  { 
  if (!action->skip_children_machine_description) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Operation_def (doggy_machine_description_defs(me), action, val);
    else Traverse_List_doggy_Operation_def (doggy_machine_description_defs(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Applied_formal (doggy_machine_description_supports(me), action, val);
    else Traverse_List_doggy_Applied_formal (doggy_machine_description_supports(me), action, val);
  }
  }
  if (action->action_machine_description[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_machine_description[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Operation_def (doggy_Operation_def me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Operation_def, me)) return val;
  if (action->action_Operation_def[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Operation_def[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Operation_def)
  { 
  if (!action->skip_children_Operation_def) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Type (doggy_Operation_def_types(me), action, val);
    else Traverse_List_doggy_Type (doggy_Operation_def_types(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_Operation_def_result(me), action, val);
    else Traverse_doggy_Type (doggy_Operation_def_result(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Attributes (doggy_Operation_def_descr(me), action, val);
    else Traverse_doggy_Attributes (doggy_Operation_def_descr(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Property (doggy_Operation_def_props(me), action, val);
    else Traverse_List_doggy_Property (doggy_Operation_def_props(me), action, val);
  }
  }
  if (action->action_Operation_def[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Operation_def[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Attributes (doggy_Attributes me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Attributes, me)) return val;
  if (action->action_Attributes[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Attributes[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Attributes)
  { 
  if (!action->skip_children_Attributes) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Attribute (doggy_Attributes_ids(me), action, val);
    else Traverse_List_doggy_Attribute (doggy_Attributes_ids(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Attributes (doggy_Attributes_tail(me), action, val);
    else Traverse_doggy_Attributes (doggy_Attributes_tail(me), action, val);
  }
  }
  if (action->action_Attributes[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Attributes[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Attribute (doggy_Attribute me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Attribute, me)) return val;
  if (action->action_Attribute[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Attribute[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Attribute)
  { switch (doggy_Attribute_tag(me)) {
      case doggy_IdAttr_kind:
        if (action->action_IdAttr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdAttr[PRE_ACTION](me, val);
        }
        if (action->action_IdAttr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdAttr[POST_ACTION](me, val);
        }
        break;
      case doggy_OpAttr_kind:
        if (action->action_OpAttr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OpAttr[PRE_ACTION](me, val);
        }
        if (action->action_OpAttr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OpAttr[POST_ACTION](me, val);
        }
        break;
      case doggy_IntAttr_kind:
        if (action->action_IntAttr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IntAttr[PRE_ACTION](me, val);
        }
        if (action->action_IntAttr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IntAttr[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Attribute[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Attribute[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Section (doggy_Section me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Section, me)) return val;
  if (action->action_Section[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Section[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Section)
  { switch (doggy_Section_tag(me)) {
      case doggy_FuncSection_kind:
        if (action->action_FuncSection[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_FuncSection[PRE_ACTION](me, val);
        }
        if (!action->skip_children_FuncSection) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Func (doggy_FuncSection_funcs(me), action, val);
          else Traverse_List_doggy_Func (doggy_FuncSection_funcs(me), action, val);
        }
        if (action->action_FuncSection[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_FuncSection[POST_ACTION](me, val);
        }
        break;
      case doggy_RuleSection_kind:
        if (action->action_RuleSection[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_RuleSection[PRE_ACTION](me, val);
        }
        if (!action->skip_children_RuleSection) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Rule (doggy_RuleSection_rules(me), action, val);
          else Traverse_List_doggy_Rule (doggy_RuleSection_rules(me), action, val);
        }
        if (action->action_RuleSection[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_RuleSection[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Section[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Section[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Rule (doggy_Rule me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Rule, me)) return val;
  if (action->action_Rule[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Rule[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Rule)
  { 
  if (!action->skip_children_Rule) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Lhs (doggy_Rule_lhs(me), action, val);
    else Traverse_doggy_Lhs (doggy_Rule_lhs(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Rhs (doggy_Rule_rhs(me), action, val);
    else Traverse_doggy_Rhs (doggy_Rule_rhs(me), action, val);
  }
  }
  if (action->action_Rule[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Rule[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Lhs (doggy_Lhs me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Lhs, me)) return val;
  if (action->action_Lhs[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Lhs[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Lhs)
  { switch (doggy_Lhs_tag(me)) {
      case doggy_LabeledLhs_kind:
        if (action->action_LabeledLhs[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LabeledLhs[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Lhs) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Pattern (doggy_Lhs_pat(me), action, val);
          else Traverse_doggy_Pattern (doggy_Lhs_pat(me), action, val);
        }
        if (action->action_LabeledLhs[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LabeledLhs[POST_ACTION](me, val);
        }
        break;
      case doggy_UnLabeledLhs_kind:
        if (action->action_UnLabeledLhs[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_UnLabeledLhs[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Lhs) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Pattern (doggy_Lhs_pat(me), action, val);
          else Traverse_doggy_Pattern (doggy_Lhs_pat(me), action, val);
        }
        if (action->action_UnLabeledLhs[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_UnLabeledLhs[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Lhs[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Lhs[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Func (doggy_Func me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Func, me)) return val;
  if (action->action_Func[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Func[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Func)
  { 
  if (!action->skip_children_Func) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_Func_type(me), action, val);
    else Traverse_doggy_Type (doggy_Func_type(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_FuncRule (doggy_Func_rules(me), action, val);
    else Traverse_List_doggy_FuncRule (doggy_Func_rules(me), action, val);
  }
  }
  if (action->action_Func[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Func[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_FuncRule (doggy_FuncRule me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(FuncRule, me)) return val;
  if (action->action_FuncRule[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_FuncRule[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_FuncRule)
  { 
  if (!action->skip_children_FuncRule) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Argument (doggy_FuncRule_args(me), action, val);
    else Traverse_List_doggy_Argument (doggy_FuncRule_args(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Rhs (doggy_FuncRule_rhs(me), action, val);
    else Traverse_doggy_Rhs (doggy_FuncRule_rhs(me), action, val);
  }
  }
  if (action->action_FuncRule[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_FuncRule[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Argument (doggy_Argument me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Argument, me)) return val;
  if (action->action_Argument[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Argument[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Argument)
  { switch (doggy_Argument_tag(me)) {
      case doggy_TypedArg_kind:
        if (action->action_TypedArg[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_TypedArg[PRE_ACTION](me, val);
        }
        if (!action->skip_children_TypedArg) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_TypedArg_type(me), action, val);
          else Traverse_doggy_Type (doggy_TypedArg_type(me), action, val);
        }
        if (!action->skip_children_Argument) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_ArgPat (doggy_Argument_pat(me), action, val);
          else Traverse_doggy_ArgPat (doggy_Argument_pat(me), action, val);
        }
        if (action->action_TypedArg[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_TypedArg[POST_ACTION](me, val);
        }
        break;
      case doggy_UnTypedArg_kind:
        if (action->action_UnTypedArg[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_UnTypedArg[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Argument) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_ArgPat (doggy_Argument_pat(me), action, val);
          else Traverse_doggy_ArgPat (doggy_Argument_pat(me), action, val);
        }
        if (action->action_UnTypedArg[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_UnTypedArg[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Argument[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Argument[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_ArgPat (doggy_ArgPat me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(ArgPat, me)) return val;
  if (action->action_ArgPat[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ArgPat[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_ArgPat)
  { switch (doggy_ArgPat_tag(me)) {
      case doggy_PatArg_kind:
        if (action->action_PatArg[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PatArg[PRE_ACTION](me, val);
        }
        if (!action->skip_children_PatArg) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Pattern (doggy_PatArg_pat(me), action, val);
          else Traverse_doggy_Pattern (doggy_PatArg_pat(me), action, val);
        }
        if (action->action_PatArg[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PatArg[POST_ACTION](me, val);
        }
        break;
      case doggy_SetArg_kind:
        if (action->action_SetArg[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SetArg[PRE_ACTION](me, val);
        }
        if (!action->skip_children_SetArg) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Applied_operation (doggy_SetArg_set(me), action, val);
          else Traverse_doggy_Applied_operation (doggy_SetArg_set(me), action, val);
        }
        if (action->action_SetArg[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SetArg[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_ArgPat[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ArgPat[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Pattern (doggy_Pattern me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Pattern, me)) return val;
  if (action->action_Pattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Pattern[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Pattern)
  { switch (doggy_Pattern_tag(me)) {
      case doggy_TypedPattern_kind:
        if (action->action_TypedPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_TypedPattern[PRE_ACTION](me, val);
        }
        if (!action->skip_children_TypedPattern) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_TypedPattern_btype(me), action, val);
          else Traverse_doggy_Type (doggy_TypedPattern_btype(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Pattern (doggy_TypedPattern_pat(me), action, val);
          else Traverse_doggy_Pattern (doggy_TypedPattern_pat(me), action, val);
        }
        if (action->action_TypedPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_TypedPattern[POST_ACTION](me, val);
        }
        break;
      case doggy_ConsPattern_kind:
        if (action->action_ConsPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ConsPattern[PRE_ACTION](me, val);
        }
        if (!action->skip_children_ConsPattern) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Pattern (doggy_ConsPattern_lhs(me), action, val);
          else Traverse_doggy_Pattern (doggy_ConsPattern_lhs(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Pattern (doggy_ConsPattern_rhs(me), action, val);
          else Traverse_doggy_Pattern (doggy_ConsPattern_rhs(me), action, val);
        }
        if (action->action_ConsPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ConsPattern[POST_ACTION](me, val);
        }
        break;
      case doggy_DefPattern_kind:
        if (action->action_DefPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DefPattern[PRE_ACTION](me, val);
        }
        if (!action->skip_children_DefPattern) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Pattern (doggy_DefPattern_ids(me), action, val);
          else Traverse_List_doggy_Pattern (doggy_DefPattern_ids(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Pattern (doggy_DefPattern_arg(me), action, val);
          else Traverse_doggy_Pattern (doggy_DefPattern_arg(me), action, val);
        }
        if (action->action_DefPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DefPattern[POST_ACTION](me, val);
        }
        break;
      case doggy_IdentPattern_kind:
        if (action->action_IdentPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdentPattern[PRE_ACTION](me, val);
        }
        if (action->action_IdentPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdentPattern[POST_ACTION](me, val);
        }
        break;
      case doggy_OpPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicPattern[PRE_ACTION](me, val);
        }
        if (action->action_OpPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OpPattern[PRE_ACTION](me, val);
        }
        if (!action->skip_children_OpPattern) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Applied_operation (doggy_OpPattern_op(me), action, val);
          else Traverse_doggy_Applied_operation (doggy_OpPattern_op(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Pattern (doggy_OpPattern_args(me), action, val);
          else Traverse_List_doggy_Pattern (doggy_OpPattern_args(me), action, val);
        }
        if (action->action_OpPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OpPattern[POST_ACTION](me, val);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicPattern[POST_ACTION](me, val);
        }
        break;
      case doggy_ConstPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicPattern[PRE_ACTION](me, val);
        }
        if (action->action_ConstPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ConstPattern[PRE_ACTION](me, val);
        }
        if (action->action_ConstPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ConstPattern[POST_ACTION](me, val);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicPattern[POST_ACTION](me, val);
        }
        break;
      case doggy_NullPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicPattern[PRE_ACTION](me, val);
        }
        if (action->action_NullPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NullPattern[PRE_ACTION](me, val);
        }
        if (action->action_NullPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NullPattern[POST_ACTION](me, val);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicPattern[POST_ACTION](me, val);
        }
        break;
      case doggy_DontCarePattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicPattern[PRE_ACTION](me, val);
        }
        if (action->action_DontCarePattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DontCarePattern[PRE_ACTION](me, val);
        }
        if (!action->skip_children_DontCarePattern) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_DontCarePattern_expr(me), action, val);
          else Traverse_doggy_Expr (doggy_DontCarePattern_expr(me), action, val);
        }
        if (action->action_DontCarePattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DontCarePattern[POST_ACTION](me, val);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicPattern[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Pattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Pattern[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Rhs (doggy_Rhs me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Rhs, me)) return val;
  if (action->action_Rhs[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Rhs[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Rhs)
  { switch (doggy_Rhs_tag(me)) {
      case doggy_PlainRhs_kind:
        if (action->action_PlainRhs[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PlainRhs[PRE_ACTION](me, val);
        }
        if (!action->skip_children_PlainRhs) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Guard (doggy_PlainRhs_guards(me), action, val);
          else Traverse_List_doggy_Guard (doggy_PlainRhs_guards(me), action, val);
        }
        if (action->action_PlainRhs[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PlainRhs[POST_ACTION](me, val);
        }
        break;
      case doggy_BlockRhs_kind:
        if (action->action_BlockRhs[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BlockRhs[PRE_ACTION](me, val);
        }
        if (!action->skip_children_BlockRhs) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Rhs (doggy_BlockRhs_rhs(me), action, val);
          else Traverse_doggy_Rhs (doggy_BlockRhs_rhs(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Wherepart (doggy_BlockRhs_where(me), action, val);
          else Traverse_doggy_Wherepart (doggy_BlockRhs_where(me), action, val);
        }
        if (action->action_BlockRhs[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BlockRhs[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Rhs[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Rhs[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Guard (doggy_Guard me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Guard, me)) return val;
  if (action->action_Guard[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Guard[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Guard)
  { switch (doggy_Guard_tag(me)) {
      case doggy_RhsGuard_kind:
        if (action->action_RhsGuard[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_RhsGuard[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Guard) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_Guard_conds(me), action, val);
          else Traverse_doggy_Expr (doggy_Guard_conds(me), action, val);
        }
        if (!action->skip_children_RhsGuard) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Rhs (doggy_RhsGuard_rhs(me), action, val);
          else Traverse_doggy_Rhs (doggy_RhsGuard_rhs(me), action, val);
        }
        if (!action->skip_children_Guard) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Wherepart (doggy_Guard_where(me), action, val);
          else Traverse_doggy_Wherepart (doggy_Guard_where(me), action, val);
        }
        if (action->action_RhsGuard[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_RhsGuard[POST_ACTION](me, val);
        }
        break;
      case doggy_ExprGuard_kind:
        if (action->action_ExprGuard[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ExprGuard[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Guard) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_Guard_conds(me), action, val);
          else Traverse_doggy_Expr (doggy_Guard_conds(me), action, val);
        }
        if (!action->skip_children_ExprGuard) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_ExprSeq (doggy_ExprGuard_exprs(me), action, val);
          else Traverse_doggy_ExprSeq (doggy_ExprGuard_exprs(me), action, val);
        }
        if (!action->skip_children_Guard) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Wherepart (doggy_Guard_where(me), action, val);
          else Traverse_doggy_Wherepart (doggy_Guard_where(me), action, val);
        }
        if (action->action_ExprGuard[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ExprGuard[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Guard[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Guard[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_ExprSeq (doggy_ExprSeq me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(ExprSeq, me)) return val;
  if (action->action_ExprSeq[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ExprSeq[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_ExprSeq)
  { switch (doggy_ExprSeq_tag(me)) {
      case doggy_OneExpr_kind:
        if (action->action_OneExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OneExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_OneExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_OneExpr_expr(me), action, val);
          else Traverse_doggy_Expr (doggy_OneExpr_expr(me), action, val);
        }
        if (action->action_OneExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OneExpr[POST_ACTION](me, val);
        }
        break;
      case doggy_MoreExprs_kind:
        if (action->action_MoreExprs[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MoreExprs[PRE_ACTION](me, val);
        }
        if (!action->skip_children_MoreExprs) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Expr (doggy_MoreExprs_exprs(me), action, val);
          else Traverse_List_doggy_Expr (doggy_MoreExprs_exprs(me), action, val);
        }
        if (action->action_MoreExprs[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MoreExprs[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_ExprSeq[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ExprSeq[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Wherepart (doggy_Wherepart me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Wherepart, me)) return val;
  if (action->action_Wherepart[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Wherepart[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Wherepart)
  { 
  if (!action->skip_children_Wherepart) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Definition (doggy_Wherepart_defs(me), action, val);
    else Traverse_List_doggy_Definition (doggy_Wherepart_defs(me), action, val);
  }
  }
  if (action->action_Wherepart[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Wherepart[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Applied_operation (doggy_Applied_operation me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Applied_operation, me)) return val;
  if (action->action_Applied_operation[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Applied_operation[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Applied_operation)
  { switch (doggy_Applied_operation_tag(me)) {
      case doggy_AnyOp_kind:
        if (action->action_AnyOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AnyOp[PRE_ACTION](me, val);
        }
        if (action->action_AnyOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AnyOp[POST_ACTION](me, val);
        }
        break;
      case doggy_AppliedOp_kind:
        if (action->action_AppliedOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AppliedOp[PRE_ACTION](me, val);
        }
        if (!action->skip_children_AppliedOp) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Applied_formal (doggy_AppliedOp_op(me), action, val);
          else Traverse_doggy_Applied_formal (doggy_AppliedOp_op(me), action, val);
        }
        if (action->action_AppliedOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AppliedOp[POST_ACTION](me, val);
        }
        break;
      case doggy_OpSet_kind:
        if (action->action_OpSet[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OpSet[PRE_ACTION](me, val);
        }
        if (!action->skip_children_OpSet) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Applied_formal (doggy_OpSet_ops(me), action, val);
          else Traverse_List_doggy_Applied_formal (doggy_OpSet_ops(me), action, val);
        }
        if (action->action_OpSet[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OpSet[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Applied_operation[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Applied_operation[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Applied_formal (doggy_Applied_formal me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Applied_formal, me)) return val;
  if (action->action_Applied_formal[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Applied_formal[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Applied_formal)
  { 
  }
  if (action->action_Applied_formal[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Applied_formal[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Expr (doggy_Expr me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Expr, me)) return val;
  if (action->action_Expr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Expr[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Expr)
  { switch (doggy_Expr_tag(me)) {
      case doggy_BinExpr_kind:
        if (action->action_BinExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BinExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_BinExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Expr (doggy_BinExpr_args(me), action, val);
          else Traverse_List_doggy_Expr (doggy_BinExpr_args(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Operator (doggy_BinExpr_ops(me), action, val);
          else Traverse_List_doggy_Operator (doggy_BinExpr_ops(me), action, val);
        }
        if (action->action_BinExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BinExpr[POST_ACTION](me, val);
        }
        break;
      case doggy_ConsExpr_kind:
        if (action->action_ConsExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ConsExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_ConsExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_ConsExpr_lhs(me), action, val);
          else Traverse_doggy_Expr (doggy_ConsExpr_lhs(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_ConsExpr_rhs(me), action, val);
          else Traverse_doggy_Expr (doggy_ConsExpr_rhs(me), action, val);
        }
        if (action->action_ConsExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ConsExpr[POST_ACTION](me, val);
        }
        break;
      case doggy_IdentExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_IdentExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdentExpr[PRE_ACTION](me, val);
        }
        if (action->action_IdentExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdentExpr[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
      case doggy_IfExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_IfExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IfExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_IfExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_IfExpr_cond(me), action, val);
          else Traverse_doggy_Expr (doggy_IfExpr_cond(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_IfExpr_thn(me), action, val);
          else Traverse_doggy_Expr (doggy_IfExpr_thn(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Expr (doggy_IfExpr_conds(me), action, val);
          else Traverse_List_doggy_Expr (doggy_IfExpr_conds(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Expr (doggy_IfExpr_thens(me), action, val);
          else Traverse_List_doggy_Expr (doggy_IfExpr_thens(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_IfExpr_els(me), action, val);
          else Traverse_doggy_Expr (doggy_IfExpr_els(me), action, val);
        }
        if (action->action_IfExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IfExpr[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
      case doggy_ConstExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_ConstExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ConstExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_ConstExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Constant (doggy_ConstExpr_cnst(me), action, val);
          else Traverse_doggy_Constant (doggy_ConstExpr_cnst(me), action, val);
        }
        if (action->action_ConstExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ConstExpr[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
      case doggy_Operation_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_Operation[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Operation[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Operation) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Expr (doggy_Operation_args(me), action, val);
          else Traverse_List_doggy_Expr (doggy_Operation_args(me), action, val);
        }
        if (action->action_Operation[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Operation[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
      case doggy_ParExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_ParExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ParExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_ParExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_ParExpr_expr(me), action, val);
          else Traverse_doggy_Expr (doggy_ParExpr_expr(me), action, val);
        }
        if (action->action_ParExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ParExpr[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
      case doggy_MonExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_MonExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MonExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_MonExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_MonOp (doggy_MonExpr_op(me), action, val);
          else Traverse_doggy_MonOp (doggy_MonExpr_op(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_MonExpr_arg(me), action, val);
          else Traverse_doggy_Expr (doggy_MonExpr_arg(me), action, val);
        }
        if (action->action_MonExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MonExpr[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Expr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Expr[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Constant (doggy_Constant me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Constant, me)) return val;
  if (action->action_Constant[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Constant[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Constant)
  { switch (doggy_Constant_tag(me)) {
      case doggy_IntConst_kind:
        if (action->action_IntConst[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IntConst[PRE_ACTION](me, val);
        }
        if (action->action_IntConst[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IntConst[POST_ACTION](me, val);
        }
        break;
      case doggy_BoolConst_kind:
        if (action->action_BoolConst[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BoolConst[PRE_ACTION](me, val);
        }
        if (action->action_BoolConst[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BoolConst[POST_ACTION](me, val);
        }
        break;
      case doggy_StringConst_kind:
        if (action->action_StringConst[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_StringConst[PRE_ACTION](me, val);
        }
        if (action->action_StringConst[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_StringConst[POST_ACTION](me, val);
        }
        break;
      case doggy_NullConst_kind:
        if (action->action_NullConst[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NullConst[PRE_ACTION](me, val);
        }
        if (action->action_NullConst[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NullConst[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Constant[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Constant[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Definition (doggy_Definition me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Definition, me)) return val;
  if (action->action_Definition[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Definition[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Definition)
  { 
  if (!action->skip_children_Definition) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_Definition_type(me), action, val);
    else Traverse_doggy_Type (doggy_Definition_type(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (doggy_Definition_expr(me), action, val);
    else Traverse_doggy_Expr (doggy_Definition_expr(me), action, val);
  }
  }
  if (action->action_Definition[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Definition[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Type (doggy_Type me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Type, me)) return val;
  if (action->action_Type[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Type[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Type)
  { switch (doggy_Type_tag(me)) {
      case doggy_EdgeType_kind:
        if (action->action_EdgeType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_EdgeType[PRE_ACTION](me, val);
        }
        if (!action->skip_children_EdgeType) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Type (doggy_EdgeType_types(me), action, val);
          else Traverse_List_doggy_Type (doggy_EdgeType_types(me), action, val);
        }
        if (action->action_EdgeType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_EdgeType[POST_ACTION](me, val);
        }
        break;
      case doggy_TupleType_kind:
        if (action->action_TupleType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_TupleType[PRE_ACTION](me, val);
        }
        if (!action->skip_children_TupleType) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Type (doggy_TupleType_types(me), action, val);
          else Traverse_List_doggy_Type (doggy_TupleType_types(me), action, val);
        }
        if (action->action_TupleType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_TupleType[POST_ACTION](me, val);
        }
        break;
      case doggy_IdentType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicType[PRE_ACTION](me, val);
        }
        if (action->action_IdentType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdentType[PRE_ACTION](me, val);
        }
        if (action->action_IdentType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdentType[POST_ACTION](me, val);
        }
        if (action->action_BasicType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicType[POST_ACTION](me, val);
        }
        break;
      case doggy_OprType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicType[PRE_ACTION](me, val);
        }
        if (action->action_OprType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OprType[PRE_ACTION](me, val);
        }
        if (!action->skip_children_OprType) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Type (doggy_OprType_args(me), action, val);
          else Traverse_List_doggy_Type (doggy_OprType_args(me), action, val);
        }
        if (action->action_OprType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OprType[POST_ACTION](me, val);
        }
        if (action->action_BasicType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicType[POST_ACTION](me, val);
        }
        break;
      case doggy_PointerType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicType[PRE_ACTION](me, val);
        }
        if (action->action_PointerType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PointerType[PRE_ACTION](me, val);
        }
        if (!action->skip_children_PointerType) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_PointerType_base(me), action, val);
          else Traverse_doggy_Type (doggy_PointerType_base(me), action, val);
        }
        if (action->action_PointerType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PointerType[POST_ACTION](me, val);
        }
        if (action->action_BasicType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicType[POST_ACTION](me, val);
        }
        break;
      case doggy_RangeType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicType[PRE_ACTION](me, val);
        }
        if (action->action_RangeType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_RangeType[PRE_ACTION](me, val);
        }
        if (!action->skip_children_RangeType) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Num (doggy_RangeType_lo(me), action, val);
          else Traverse_doggy_Num (doggy_RangeType_lo(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Num (doggy_RangeType_hi(me), action, val);
          else Traverse_doggy_Num (doggy_RangeType_hi(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Num (doggy_RangeType_step(me), action, val);
          else Traverse_doggy_Num (doggy_RangeType_step(me), action, val);
        }
        if (action->action_RangeType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_RangeType[POST_ACTION](me, val);
        }
        if (action->action_BasicType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicType[POST_ACTION](me, val);
        }
        break;
      case doggy_FRangeType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicType[PRE_ACTION](me, val);
        }
        if (action->action_FRangeType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_FRangeType[PRE_ACTION](me, val);
        }
        if (action->action_FRangeType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_FRangeType[POST_ACTION](me, val);
        }
        if (action->action_BasicType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicType[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Type[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Type[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Num (doggy_Num me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Num, me)) return val;
  if (action->action_Num[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Num[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Num)
  { 
  }
  if (action->action_Num[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Num[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_IdInt (doggy_IdInt me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(IdInt, me)) return val;
  if (action->action_IdInt[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_IdInt[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_IdInt)
  { switch (doggy_IdInt_tag(me)) {
      case doggy_IsId_kind:
        if (action->action_IsId[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IsId[PRE_ACTION](me, val);
        }
        if (action->action_IsId[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IsId[POST_ACTION](me, val);
        }
        break;
      case doggy_IsInt_kind:
        if (action->action_IsInt[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IsInt[PRE_ACTION](me, val);
        }
        if (action->action_IsInt[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IsInt[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_IdInt[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_IdInt[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Path (doggy_Path me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Path, me)) return val;
  if (action->action_Path[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Path[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Path)
  { 
  if (!action->skip_children_Path) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_Path_type(me), action, val);
    else Traverse_doggy_Type (doggy_Path_type(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Path (doggy_Path_next(me), action, val);
    else Traverse_doggy_Path (doggy_Path_next(me), action, val);
  }
  }
  if (action->action_Path[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Path[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_ActualOp (doggy_ActualOp me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(ActualOp, me)) return val;
  if (action->action_ActualOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ActualOp[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_ActualOp)
  { 
  if (!action->skip_children_ActualOp) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Operation_def (doggy_ActualOp_formals(me), action, val);
    else Traverse_List_doggy_Operation_def (doggy_ActualOp_formals(me), action, val);
  }
  }
  if (action->action_ActualOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ActualOp[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_TypePair (doggy_TypePair me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(TypePair, me)) return val;
  if (action->action_TypePair[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_TypePair[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_TypePair)
  { 
  if (!action->skip_children_TypePair) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_TypePair_t1(me), action, val);
    else Traverse_doggy_Type (doggy_TypePair_t1(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_TypePair_t2(me), action, val);
    else Traverse_doggy_Type (doggy_TypePair_t2(me), action, val);
  }
  }
  if (action->action_TypePair[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_TypePair[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Opat (doggy_Opat me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Opat, me)) return val;
  if (action->action_Opat[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Opat[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Opat)
  { 
  if (!action->skip_children_Opat) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Type (doggy_Opat_args(me), action, val);
    else Traverse_List_doggy_Type (doggy_Opat_args(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_Opat_result(me), action, val);
    else Traverse_doggy_Type (doggy_Opat_result(me), action, val);
  }
  }
  if (action->action_Opat[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Opat[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Format (doggy_Format me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Format, me)) return val;
  if (action->action_Format[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Format[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Format)
  { 
  if (!action->skip_children_Format) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Type (doggy_Format_args(me), action, val);
    else Traverse_List_doggy_Type (doggy_Format_args(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (doggy_Format_result(me), action, val);
    else Traverse_doggy_Type (doggy_Format_result(me), action, val);
  }
  }
  if (action->action_Format[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Format[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_dummy_type (doggy_dummy_type me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(dummy_type, me)) return val;
  if (action->action_dummy_type[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_dummy_type[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_dummy_type)
  { 
  if (!action->skip_children_dummy_type) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_ActualOp (doggy_dummy_type_y(me), action, val);
    else Traverse_List_doggy_ActualOp (doggy_dummy_type_y(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_TypePair (doggy_dummy_type_z(me), action, val);
    else Traverse_List_doggy_TypePair (doggy_dummy_type_z(me), action, val);
  }
  }
  if (action->action_dummy_type[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_dummy_type[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Scope (doggy_Scope me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Scope, me)) return val;
  if (action->action_Scope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Scope)
  { switch (doggy_Scope_tag(me)) {
      case doggy_OpSetScope_kind:
        if (action->action_OpSetScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OpSetScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Scope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
          else Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
        }
        if (!action->skip_children_OpSetScope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Applied_operation (doggy_OpSetScope_data(me), action, val);
          else Traverse_doggy_Applied_operation (doggy_OpSetScope_data(me), action, val);
        }
        if (action->action_OpSetScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OpSetScope[POST_ACTION](me, val);
        }
        break;
      case doggy_AppliedOpScope_kind:
        if (action->action_AppliedOpScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AppliedOpScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Scope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
          else Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
        }
        if (!action->skip_children_AppliedOpScope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Applied_operation (doggy_AppliedOpScope_data(me), action, val);
          else Traverse_doggy_Applied_operation (doggy_AppliedOpScope_data(me), action, val);
        }
        if (action->action_AppliedOpScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AppliedOpScope[POST_ACTION](me, val);
        }
        break;
      case doggy_ExprGuardScope_kind:
        if (action->action_ExprGuardScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ExprGuardScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Scope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
          else Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
        }
        if (!action->skip_children_ExprGuardScope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Guard (doggy_ExprGuardScope_data(me), action, val);
          else Traverse_doggy_Guard (doggy_ExprGuardScope_data(me), action, val);
        }
        if (action->action_ExprGuardScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ExprGuardScope[POST_ACTION](me, val);
        }
        break;
      case doggy_RhsGuardScope_kind:
        if (action->action_RhsGuardScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_RhsGuardScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Scope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
          else Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
        }
        if (!action->skip_children_RhsGuardScope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Guard (doggy_RhsGuardScope_data(me), action, val);
          else Traverse_doggy_Guard (doggy_RhsGuardScope_data(me), action, val);
        }
        if (action->action_RhsGuardScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_RhsGuardScope[POST_ACTION](me, val);
        }
        break;
      case doggy_FuncRuleScope_kind:
        if (action->action_FuncRuleScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_FuncRuleScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Scope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
          else Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
        }
        if (!action->skip_children_FuncRuleScope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_FuncRule (doggy_FuncRuleScope_data(me), action, val);
          else Traverse_doggy_FuncRule (doggy_FuncRuleScope_data(me), action, val);
        }
        if (action->action_FuncRuleScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_FuncRuleScope[POST_ACTION](me, val);
        }
        break;
      case doggy_RuleScope_kind:
        if (action->action_RuleScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_RuleScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Scope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
          else Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
        }
        if (!action->skip_children_RuleScope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Rule (doggy_RuleScope_data(me), action, val);
          else Traverse_doggy_Rule (doggy_RuleScope_data(me), action, val);
        }
        if (action->action_RuleScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_RuleScope[POST_ACTION](me, val);
        }
        break;
      case doggy_machine_descriptionScope_kind:
        if (action->action_machine_descriptionScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_machine_descriptionScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Scope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
          else Traverse_doggy_Scope (doggy_Scope_next(me), action, val);
        }
        if (!action->skip_children_machine_descriptionScope) {
          if (action->traversal != Traverse_Down)  val = Traverse_doggy_machine_description (doggy_machine_descriptionScope_data(me), action, val);
          else Traverse_doggy_machine_description (doggy_machine_descriptionScope_data(me), action, val);
        }
        if (action->action_machine_descriptionScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_machine_descriptionScope[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Scope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Num (List_doggy_Num me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Num, me)) return val;
  if (action->action_List_Num[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Num[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Num)
  { 
  if (!action->skip_children_List_Num) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Num (List_doggy_Num_data(me), action, val);
    else Traverse_doggy_Num (List_doggy_Num_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Num (List_doggy_Num_next(me), action, val);
    else Traverse_List_doggy_Num (List_doggy_Num_next(me), action, val);
  }
  }
  if (action->action_List_Num[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Num[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_List_doggy_TypePair (List_List_doggy_TypePair me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_List_TypePair, me)) return val;
  if (action->action_List_List_TypePair[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_List_TypePair[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_List_TypePair)
  { 
  if (!action->skip_children_List_List_TypePair) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_TypePair (List_List_doggy_TypePair_data(me), action, val);
    else Traverse_List_doggy_TypePair (List_List_doggy_TypePair_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_List_doggy_TypePair (List_List_doggy_TypePair_next(me), action, val);
    else Traverse_List_List_doggy_TypePair (List_List_doggy_TypePair_next(me), action, val);
  }
  }
  if (action->action_List_List_TypePair[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_List_TypePair[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_TypePair (List_doggy_TypePair me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_TypePair, me)) return val;
  if (action->action_List_TypePair[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_TypePair[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_TypePair)
  { 
  if (!action->skip_children_List_TypePair) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_TypePair (List_doggy_TypePair_data(me), action, val);
    else Traverse_doggy_TypePair (List_doggy_TypePair_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_TypePair (List_doggy_TypePair_next(me), action, val);
    else Traverse_List_doggy_TypePair (List_doggy_TypePair_next(me), action, val);
  }
  }
  if (action->action_List_TypePair[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_TypePair[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_ActualOp (List_doggy_ActualOp me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_ActualOp, me)) return val;
  if (action->action_List_ActualOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_ActualOp[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_ActualOp)
  { 
  if (!action->skip_children_List_ActualOp) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_ActualOp (List_doggy_ActualOp_data(me), action, val);
    else Traverse_doggy_ActualOp (List_doggy_ActualOp_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_ActualOp (List_doggy_ActualOp_next(me), action, val);
    else Traverse_List_doggy_ActualOp (List_doggy_ActualOp_next(me), action, val);
  }
  }
  if (action->action_List_ActualOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_ActualOp[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_List_doggy_Type (List_List_doggy_Type me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_List_Type, me)) return val;
  if (action->action_List_List_Type[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_List_Type[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_List_Type)
  { 
  if (!action->skip_children_List_List_Type) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Type (List_List_doggy_Type_data(me), action, val);
    else Traverse_List_doggy_Type (List_List_doggy_Type_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_List_doggy_Type (List_List_doggy_Type_next(me), action, val);
    else Traverse_List_List_doggy_Type (List_List_doggy_Type_next(me), action, val);
  }
  }
  if (action->action_List_List_Type[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_List_Type[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Operator (List_doggy_Operator me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Operator, me)) return val;
  if (action->action_List_Operator[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Operator[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Operator)
  { 
  if (!action->skip_children_List_Operator) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Operator (List_doggy_Operator_data(me), action, val);
    else Traverse_doggy_Operator (List_doggy_Operator_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Operator (List_doggy_Operator_next(me), action, val);
    else Traverse_List_doggy_Operator (List_doggy_Operator_next(me), action, val);
  }
  }
  if (action->action_List_Operator[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Operator[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Definition (List_doggy_Definition me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Definition, me)) return val;
  if (action->action_List_Definition[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Definition[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Definition)
  { 
  if (!action->skip_children_List_Definition) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Definition (List_doggy_Definition_data(me), action, val);
    else Traverse_doggy_Definition (List_doggy_Definition_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Definition (List_doggy_Definition_next(me), action, val);
    else Traverse_List_doggy_Definition (List_doggy_Definition_next(me), action, val);
  }
  }
  if (action->action_List_Definition[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Definition[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Expr (List_doggy_Expr me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Expr, me)) return val;
  if (action->action_List_Expr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Expr[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Expr)
  { 
  if (!action->skip_children_List_Expr) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Expr (List_doggy_Expr_data(me), action, val);
    else Traverse_doggy_Expr (List_doggy_Expr_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Expr (List_doggy_Expr_next(me), action, val);
    else Traverse_List_doggy_Expr (List_doggy_Expr_next(me), action, val);
  }
  }
  if (action->action_List_Expr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Expr[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Guard (List_doggy_Guard me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Guard, me)) return val;
  if (action->action_List_Guard[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Guard[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Guard)
  { 
  if (!action->skip_children_List_Guard) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Guard (List_doggy_Guard_data(me), action, val);
    else Traverse_doggy_Guard (List_doggy_Guard_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Guard (List_doggy_Guard_next(me), action, val);
    else Traverse_List_doggy_Guard (List_doggy_Guard_next(me), action, val);
  }
  }
  if (action->action_List_Guard[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Guard[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Pattern (List_doggy_Pattern me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Pattern, me)) return val;
  if (action->action_List_Pattern[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Pattern[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Pattern)
  { 
  if (!action->skip_children_List_Pattern) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Pattern (List_doggy_Pattern_data(me), action, val);
    else Traverse_doggy_Pattern (List_doggy_Pattern_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Pattern (List_doggy_Pattern_next(me), action, val);
    else Traverse_List_doggy_Pattern (List_doggy_Pattern_next(me), action, val);
  }
  }
  if (action->action_List_Pattern[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Pattern[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Argument (List_doggy_Argument me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Argument, me)) return val;
  if (action->action_List_Argument[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Argument[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Argument)
  { 
  if (!action->skip_children_List_Argument) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Argument (List_doggy_Argument_data(me), action, val);
    else Traverse_doggy_Argument (List_doggy_Argument_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Argument (List_doggy_Argument_next(me), action, val);
    else Traverse_List_doggy_Argument (List_doggy_Argument_next(me), action, val);
  }
  }
  if (action->action_List_Argument[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Argument[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_FuncRule (List_doggy_FuncRule me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_FuncRule, me)) return val;
  if (action->action_List_FuncRule[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_FuncRule[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_FuncRule)
  { 
  if (!action->skip_children_List_FuncRule) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_FuncRule (List_doggy_FuncRule_data(me), action, val);
    else Traverse_doggy_FuncRule (List_doggy_FuncRule_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_FuncRule (List_doggy_FuncRule_next(me), action, val);
    else Traverse_List_doggy_FuncRule (List_doggy_FuncRule_next(me), action, val);
  }
  }
  if (action->action_List_FuncRule[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_FuncRule[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Attribute (List_doggy_Attribute me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Attribute, me)) return val;
  if (action->action_List_Attribute[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Attribute[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Attribute)
  { 
  if (!action->skip_children_List_Attribute) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Attribute (List_doggy_Attribute_data(me), action, val);
    else Traverse_doggy_Attribute (List_doggy_Attribute_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Attribute (List_doggy_Attribute_next(me), action, val);
    else Traverse_List_doggy_Attribute (List_doggy_Attribute_next(me), action, val);
  }
  }
  if (action->action_List_Attribute[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Attribute[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Property (List_doggy_Property me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Property, me)) return val;
  if (action->action_List_Property[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Property[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Property)
  { 
  if (!action->skip_children_List_Property) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Property (List_doggy_Property_data(me), action, val);
    else Traverse_doggy_Property (List_doggy_Property_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Property (List_doggy_Property_next(me), action, val);
    else Traverse_List_doggy_Property (List_doggy_Property_next(me), action, val);
  }
  }
  if (action->action_List_Property[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Property[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Applied_formal (List_doggy_Applied_formal me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Applied_formal, me)) return val;
  if (action->action_List_Applied_formal[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Applied_formal[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Applied_formal)
  { 
  if (!action->skip_children_List_Applied_formal) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Applied_formal (List_doggy_Applied_formal_data(me), action, val);
    else Traverse_doggy_Applied_formal (List_doggy_Applied_formal_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Applied_formal (List_doggy_Applied_formal_next(me), action, val);
    else Traverse_List_doggy_Applied_formal (List_doggy_Applied_formal_next(me), action, val);
  }
  }
  if (action->action_List_Applied_formal[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Applied_formal[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Operation_def (List_doggy_Operation_def me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Operation_def, me)) return val;
  if (action->action_List_Operation_def[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Operation_def[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Operation_def)
  { 
  if (!action->skip_children_List_Operation_def) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Operation_def (List_doggy_Operation_def_data(me), action, val);
    else Traverse_doggy_Operation_def (List_doggy_Operation_def_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Operation_def (List_doggy_Operation_def_next(me), action, val);
    else Traverse_List_doggy_Operation_def (List_doggy_Operation_def_next(me), action, val);
  }
  }
  if (action->action_List_Operation_def[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Operation_def[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Type (List_doggy_Type me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Type, me)) return val;
  if (action->action_List_Type[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Type[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Type)
  { 
  if (!action->skip_children_List_Type) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Type (List_doggy_Type_data(me), action, val);
    else Traverse_doggy_Type (List_doggy_Type_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Type (List_doggy_Type_next(me), action, val);
    else Traverse_List_doggy_Type (List_doggy_Type_next(me), action, val);
  }
  }
  if (action->action_List_Type[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Type[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Rule (List_doggy_Rule me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Rule, me)) return val;
  if (action->action_List_Rule[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Rule[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Rule)
  { 
  if (!action->skip_children_List_Rule) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Rule (List_doggy_Rule_data(me), action, val);
    else Traverse_doggy_Rule (List_doggy_Rule_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Rule (List_doggy_Rule_next(me), action, val);
    else Traverse_List_doggy_Rule (List_doggy_Rule_next(me), action, val);
  }
  }
  if (action->action_List_Rule[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Rule[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Func (List_doggy_Func me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Func, me)) return val;
  if (action->action_List_Func[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Func[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Func)
  { 
  if (!action->skip_children_List_Func) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Func (List_doggy_Func_data(me), action, val);
    else Traverse_doggy_Func (List_doggy_Func_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Func (List_doggy_Func_next(me), action, val);
    else Traverse_List_doggy_Func (List_doggy_Func_next(me), action, val);
  }
  }
  if (action->action_List_Func[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Func[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Section (List_doggy_Section me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Section, me)) return val;
  if (action->action_List_Section[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Section[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Section)
  { 
  if (!action->skip_children_List_Section) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Section (List_doggy_Section_data(me), action, val);
    else Traverse_doggy_Section (List_doggy_Section_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Section (List_doggy_Section_next(me), action, val);
    else Traverse_List_doggy_Section (List_doggy_Section_next(me), action, val);
  }
  }
  if (action->action_List_Section[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Section[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_FunctionDef (List_doggy_FunctionDef me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_FunctionDef, me)) return val;
  if (action->action_List_FunctionDef[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_FunctionDef[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_FunctionDef)
  { 
  if (!action->skip_children_List_FunctionDef) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_FunctionDef (List_doggy_FunctionDef_data(me), action, val);
    else Traverse_doggy_FunctionDef (List_doggy_FunctionDef_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_FunctionDef (List_doggy_FunctionDef_next(me), action, val);
    else Traverse_List_doggy_FunctionDef (List_doggy_FunctionDef_next(me), action, val);
  }
  }
  if (action->action_List_FunctionDef[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_FunctionDef[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_doggy_Typedef (List_doggy_Typedef me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(List_Typedef, me)) return val;
  if (action->action_List_Typedef[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Typedef[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Typedef)
  { 
  if (!action->skip_children_List_Typedef) {
    if (action->traversal != Traverse_Down)  val = Traverse_doggy_Typedef (List_doggy_Typedef_data(me), action, val);
    else Traverse_doggy_Typedef (List_doggy_Typedef_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_doggy_Typedef (List_doggy_Typedef_next(me), action, val);
    else Traverse_List_doggy_Typedef (List_doggy_Typedef_next(me), action, val);
  }
  }
  if (action->action_List_Typedef[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Typedef[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Operator (doggy_Operator me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Operator, me)) return val;
  if (action->action_Operator[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Operator[PRE_ACTION](me, val);
  }
  { switch (me) {
      case doggy_CandOp:
        if (action->action_CandOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CandOp[PRE_ACTION](me, val);
        }
        if (action->action_CandOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CandOp[POST_ACTION](me, val);
        }
        break;
      case doggy_CorOp:
        if (action->action_CorOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CorOp[PRE_ACTION](me, val);
        }
        if (action->action_CorOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CorOp[POST_ACTION](me, val);
        }
        break;
      case doggy_XorOp:
        if (action->action_XorOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_XorOp[PRE_ACTION](me, val);
        }
        if (action->action_XorOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_XorOp[POST_ACTION](me, val);
        }
        break;
      case doggy_EqOp:
        if (action->action_EqOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_EqOp[PRE_ACTION](me, val);
        }
        if (action->action_EqOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_EqOp[POST_ACTION](me, val);
        }
        break;
      case doggy_NeqOp:
        if (action->action_NeqOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NeqOp[PRE_ACTION](me, val);
        }
        if (action->action_NeqOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NeqOp[POST_ACTION](me, val);
        }
        break;
      case doggy_LEOp:
        if (action->action_LEOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LEOp[PRE_ACTION](me, val);
        }
        if (action->action_LEOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LEOp[POST_ACTION](me, val);
        }
        break;
      case doggy_GEOp:
        if (action->action_GEOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_GEOp[PRE_ACTION](me, val);
        }
        if (action->action_GEOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_GEOp[POST_ACTION](me, val);
        }
        break;
      case doggy_LTOp:
        if (action->action_LTOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LTOp[PRE_ACTION](me, val);
        }
        if (action->action_LTOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LTOp[POST_ACTION](me, val);
        }
        break;
      case doggy_GTOp:
        if (action->action_GTOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_GTOp[PRE_ACTION](me, val);
        }
        if (action->action_GTOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_GTOp[POST_ACTION](me, val);
        }
        break;
      case doggy_SLOp:
        if (action->action_SLOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SLOp[PRE_ACTION](me, val);
        }
        if (action->action_SLOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SLOp[POST_ACTION](me, val);
        }
        break;
      case doggy_SROp:
        if (action->action_SROp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SROp[PRE_ACTION](me, val);
        }
        if (action->action_SROp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SROp[POST_ACTION](me, val);
        }
        break;
      case doggy_DivOp:
        if (action->action_DivOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DivOp[PRE_ACTION](me, val);
        }
        if (action->action_DivOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DivOp[POST_ACTION](me, val);
        }
        break;
      case doggy_ModOp:
        if (action->action_ModOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ModOp[PRE_ACTION](me, val);
        }
        if (action->action_ModOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ModOp[POST_ACTION](me, val);
        }
        break;
      case doggy_MulOp:
        if (action->action_MulOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MulOp[PRE_ACTION](me, val);
        }
        if (action->action_MulOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MulOp[POST_ACTION](me, val);
        }
        break;
      case doggy_AndOp:
        if (action->action_AndOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndOp[PRE_ACTION](me, val);
        }
        if (action->action_AndOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndOp[POST_ACTION](me, val);
        }
        break;
      case doggy_AddOp:
        if (action->action_AddOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AddOp[PRE_ACTION](me, val);
        }
        if (action->action_AddOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AddOp[POST_ACTION](me, val);
        }
        break;
      case doggy_SubOp:
        if (action->action_SubOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SubOp[PRE_ACTION](me, val);
        }
        if (action->action_SubOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SubOp[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Operator[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Operator[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_MonOp (doggy_MonOp me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(MonOp, me)) return val;
  if (action->action_MonOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_MonOp[PRE_ACTION](me, val);
  }
  { switch (me) {
      case doggy_NotOp:
        if (action->action_NotOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NotOp[PRE_ACTION](me, val);
        }
        if (action->action_NotOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NotOp[POST_ACTION](me, val);
        }
        break;
      case doggy_NegOp:
        if (action->action_NegOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NegOp[PRE_ACTION](me, val);
        }
        if (action->action_NegOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NegOp[POST_ACTION](me, val);
        }
        break;
      case doggy_AddrOp:
        if (action->action_AddrOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AddrOp[PRE_ACTION](me, val);
        }
        if (action->action_AddrOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AddrOp[POST_ACTION](me, val);
        }
        break;
      case doggy_DerefOp:
        if (action->action_DerefOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DerefOp[PRE_ACTION](me, val);
        }
        if (action->action_DerefOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DerefOp[POST_ACTION](me, val);
        }
        break;
      case doggy_PlusOp:
        if (action->action_PlusOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PlusOp[PRE_ACTION](me, val);
        }
        if (action->action_PlusOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PlusOp[POST_ACTION](me, val);
        }
        break;
      case doggy_MinOp:
        if (action->action_MinOp[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MinOp[PRE_ACTION](me, val);
        }
        if (action->action_MinOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MinOp[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_MonOp[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_MonOp[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_doggy_Property (doggy_Property me, TraverseTable action, Pointer val)
{ 
  if (doggy_SKIP_NODE(Property, me)) return val;
  if (action->action_Property[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Property[PRE_ACTION](me, val);
  }
  {   }
  if (action->action_Property[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Property[POST_ACTION](me, val);
  }
  return val;
}

void Traverse_void_doggy_doggy (doggy_doggy me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(doggy, me)) return;
  if (action->action_doggy[PRE_ACTION] != NULL) {
    action->action_doggy[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_doggy)
  { 
  if (!action->skip_children_doggy) {
    Traverse_void_List_doggy_Typedef (doggy_doggy_types(me), action);
    Traverse_void_doggy_machine_description (doggy_doggy_source(me), action);
    Traverse_void_doggy_machine_description (doggy_doggy_target(me), action);
    Traverse_void_List_doggy_FunctionDef (doggy_doggy_funcs(me), action);
    Traverse_void_List_doggy_Section (doggy_doggy_sections(me), action);
  }
  }
  if (action->action_doggy[POST_ACTION] != NULL) {
    action->action_doggy[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Typedef (doggy_Typedef me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Typedef, me)) return;
  if (action->action_Typedef[PRE_ACTION] != NULL) {
    action->action_Typedef[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Typedef)
  { 
  if (!action->skip_children_Typedef) {
    Traverse_void_doggy_Attributes (doggy_Typedef_attrs(me), action);
  }
  }
  if (action->action_Typedef[POST_ACTION] != NULL) {
    action->action_Typedef[POST_ACTION](me);
  }
}

void Traverse_void_doggy_FunctionDef (doggy_FunctionDef me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(FunctionDef, me)) return;
  if (action->action_FunctionDef[PRE_ACTION] != NULL) {
    action->action_FunctionDef[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_FunctionDef)
  { switch (doggy_FunctionDef_tag(me)) {
      case doggy_ExtFunc_kind:
        if (action->action_ExtFunc[PRE_ACTION] != NULL) {
          action->action_ExtFunc[PRE_ACTION](me);
        }
        if (!action->skip_children_FunctionDef) {
          Traverse_void_doggy_Type (doggy_FunctionDef_result(me), action);
        }
        if (!action->skip_children_ExtFunc) {
          Traverse_void_List_doggy_Type (doggy_ExtFunc_args(me), action);
        }
        if (action->action_ExtFunc[POST_ACTION] != NULL) {
          action->action_ExtFunc[POST_ACTION](me);
        }
        break;
      case doggy_ExtVar_kind:
        if (action->action_ExtVar[PRE_ACTION] != NULL) {
          action->action_ExtVar[PRE_ACTION](me);
        }
        if (!action->skip_children_FunctionDef) {
          Traverse_void_doggy_Type (doggy_FunctionDef_result(me), action);
        }
        if (action->action_ExtVar[POST_ACTION] != NULL) {
          action->action_ExtVar[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_FunctionDef[POST_ACTION] != NULL) {
    action->action_FunctionDef[POST_ACTION](me);
  }
}

void Traverse_void_doggy_machine_description (doggy_machine_description me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(machine_description, me)) return;
  if (action->action_machine_description[PRE_ACTION] != NULL) {
    action->action_machine_description[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_machine_description)
  { 
  if (!action->skip_children_machine_description) {
    Traverse_void_List_doggy_Operation_def (doggy_machine_description_defs(me), action);
    Traverse_void_List_doggy_Applied_formal (doggy_machine_description_supports(me), action);
  }
  }
  if (action->action_machine_description[POST_ACTION] != NULL) {
    action->action_machine_description[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Operation_def (doggy_Operation_def me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Operation_def, me)) return;
  if (action->action_Operation_def[PRE_ACTION] != NULL) {
    action->action_Operation_def[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Operation_def)
  { 
  if (!action->skip_children_Operation_def) {
    Traverse_void_List_doggy_Type (doggy_Operation_def_types(me), action);
    Traverse_void_doggy_Type (doggy_Operation_def_result(me), action);
    Traverse_void_doggy_Attributes (doggy_Operation_def_descr(me), action);
    Traverse_void_List_doggy_Property (doggy_Operation_def_props(me), action);
  }
  }
  if (action->action_Operation_def[POST_ACTION] != NULL) {
    action->action_Operation_def[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Attributes (doggy_Attributes me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Attributes, me)) return;
  if (action->action_Attributes[PRE_ACTION] != NULL) {
    action->action_Attributes[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Attributes)
  { 
  if (!action->skip_children_Attributes) {
    Traverse_void_List_doggy_Attribute (doggy_Attributes_ids(me), action);
    Traverse_void_doggy_Attributes (doggy_Attributes_tail(me), action);
  }
  }
  if (action->action_Attributes[POST_ACTION] != NULL) {
    action->action_Attributes[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Attribute (doggy_Attribute me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Attribute, me)) return;
  if (action->action_Attribute[PRE_ACTION] != NULL) {
    action->action_Attribute[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Attribute)
  { switch (doggy_Attribute_tag(me)) {
      case doggy_IdAttr_kind:
        if (action->action_IdAttr[PRE_ACTION] != NULL) {
          action->action_IdAttr[PRE_ACTION](me);
        }
        if (action->action_IdAttr[POST_ACTION] != NULL) {
          action->action_IdAttr[POST_ACTION](me);
        }
        break;
      case doggy_OpAttr_kind:
        if (action->action_OpAttr[PRE_ACTION] != NULL) {
          action->action_OpAttr[PRE_ACTION](me);
        }
        if (action->action_OpAttr[POST_ACTION] != NULL) {
          action->action_OpAttr[POST_ACTION](me);
        }
        break;
      case doggy_IntAttr_kind:
        if (action->action_IntAttr[PRE_ACTION] != NULL) {
          action->action_IntAttr[PRE_ACTION](me);
        }
        if (action->action_IntAttr[POST_ACTION] != NULL) {
          action->action_IntAttr[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Attribute[POST_ACTION] != NULL) {
    action->action_Attribute[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Section (doggy_Section me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Section, me)) return;
  if (action->action_Section[PRE_ACTION] != NULL) {
    action->action_Section[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Section)
  { switch (doggy_Section_tag(me)) {
      case doggy_FuncSection_kind:
        if (action->action_FuncSection[PRE_ACTION] != NULL) {
          action->action_FuncSection[PRE_ACTION](me);
        }
        if (!action->skip_children_FuncSection) {
          Traverse_void_List_doggy_Func (doggy_FuncSection_funcs(me), action);
        }
        if (action->action_FuncSection[POST_ACTION] != NULL) {
          action->action_FuncSection[POST_ACTION](me);
        }
        break;
      case doggy_RuleSection_kind:
        if (action->action_RuleSection[PRE_ACTION] != NULL) {
          action->action_RuleSection[PRE_ACTION](me);
        }
        if (!action->skip_children_RuleSection) {
          Traverse_void_List_doggy_Rule (doggy_RuleSection_rules(me), action);
        }
        if (action->action_RuleSection[POST_ACTION] != NULL) {
          action->action_RuleSection[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Section[POST_ACTION] != NULL) {
    action->action_Section[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Rule (doggy_Rule me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Rule, me)) return;
  if (action->action_Rule[PRE_ACTION] != NULL) {
    action->action_Rule[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Rule)
  { 
  if (!action->skip_children_Rule) {
    Traverse_void_doggy_Lhs (doggy_Rule_lhs(me), action);
    Traverse_void_doggy_Rhs (doggy_Rule_rhs(me), action);
  }
  }
  if (action->action_Rule[POST_ACTION] != NULL) {
    action->action_Rule[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Lhs (doggy_Lhs me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Lhs, me)) return;
  if (action->action_Lhs[PRE_ACTION] != NULL) {
    action->action_Lhs[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Lhs)
  { switch (doggy_Lhs_tag(me)) {
      case doggy_LabeledLhs_kind:
        if (action->action_LabeledLhs[PRE_ACTION] != NULL) {
          action->action_LabeledLhs[PRE_ACTION](me);
        }
        if (!action->skip_children_Lhs) {
          Traverse_void_doggy_Pattern (doggy_Lhs_pat(me), action);
        }
        if (action->action_LabeledLhs[POST_ACTION] != NULL) {
          action->action_LabeledLhs[POST_ACTION](me);
        }
        break;
      case doggy_UnLabeledLhs_kind:
        if (action->action_UnLabeledLhs[PRE_ACTION] != NULL) {
          action->action_UnLabeledLhs[PRE_ACTION](me);
        }
        if (!action->skip_children_Lhs) {
          Traverse_void_doggy_Pattern (doggy_Lhs_pat(me), action);
        }
        if (action->action_UnLabeledLhs[POST_ACTION] != NULL) {
          action->action_UnLabeledLhs[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Lhs[POST_ACTION] != NULL) {
    action->action_Lhs[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Func (doggy_Func me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Func, me)) return;
  if (action->action_Func[PRE_ACTION] != NULL) {
    action->action_Func[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Func)
  { 
  if (!action->skip_children_Func) {
    Traverse_void_doggy_Type (doggy_Func_type(me), action);
    Traverse_void_List_doggy_FuncRule (doggy_Func_rules(me), action);
  }
  }
  if (action->action_Func[POST_ACTION] != NULL) {
    action->action_Func[POST_ACTION](me);
  }
}

void Traverse_void_doggy_FuncRule (doggy_FuncRule me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(FuncRule, me)) return;
  if (action->action_FuncRule[PRE_ACTION] != NULL) {
    action->action_FuncRule[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_FuncRule)
  { 
  if (!action->skip_children_FuncRule) {
    Traverse_void_List_doggy_Argument (doggy_FuncRule_args(me), action);
    Traverse_void_doggy_Rhs (doggy_FuncRule_rhs(me), action);
  }
  }
  if (action->action_FuncRule[POST_ACTION] != NULL) {
    action->action_FuncRule[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Argument (doggy_Argument me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Argument, me)) return;
  if (action->action_Argument[PRE_ACTION] != NULL) {
    action->action_Argument[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Argument)
  { switch (doggy_Argument_tag(me)) {
      case doggy_TypedArg_kind:
        if (action->action_TypedArg[PRE_ACTION] != NULL) {
          action->action_TypedArg[PRE_ACTION](me);
        }
        if (!action->skip_children_TypedArg) {
          Traverse_void_doggy_Type (doggy_TypedArg_type(me), action);
        }
        if (!action->skip_children_Argument) {
          Traverse_void_doggy_ArgPat (doggy_Argument_pat(me), action);
        }
        if (action->action_TypedArg[POST_ACTION] != NULL) {
          action->action_TypedArg[POST_ACTION](me);
        }
        break;
      case doggy_UnTypedArg_kind:
        if (action->action_UnTypedArg[PRE_ACTION] != NULL) {
          action->action_UnTypedArg[PRE_ACTION](me);
        }
        if (!action->skip_children_Argument) {
          Traverse_void_doggy_ArgPat (doggy_Argument_pat(me), action);
        }
        if (action->action_UnTypedArg[POST_ACTION] != NULL) {
          action->action_UnTypedArg[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Argument[POST_ACTION] != NULL) {
    action->action_Argument[POST_ACTION](me);
  }
}

void Traverse_void_doggy_ArgPat (doggy_ArgPat me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(ArgPat, me)) return;
  if (action->action_ArgPat[PRE_ACTION] != NULL) {
    action->action_ArgPat[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_ArgPat)
  { switch (doggy_ArgPat_tag(me)) {
      case doggy_PatArg_kind:
        if (action->action_PatArg[PRE_ACTION] != NULL) {
          action->action_PatArg[PRE_ACTION](me);
        }
        if (!action->skip_children_PatArg) {
          Traverse_void_doggy_Pattern (doggy_PatArg_pat(me), action);
        }
        if (action->action_PatArg[POST_ACTION] != NULL) {
          action->action_PatArg[POST_ACTION](me);
        }
        break;
      case doggy_SetArg_kind:
        if (action->action_SetArg[PRE_ACTION] != NULL) {
          action->action_SetArg[PRE_ACTION](me);
        }
        if (!action->skip_children_SetArg) {
          Traverse_void_doggy_Applied_operation (doggy_SetArg_set(me), action);
        }
        if (action->action_SetArg[POST_ACTION] != NULL) {
          action->action_SetArg[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_ArgPat[POST_ACTION] != NULL) {
    action->action_ArgPat[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Pattern (doggy_Pattern me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Pattern, me)) return;
  if (action->action_Pattern[PRE_ACTION] != NULL) {
    action->action_Pattern[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Pattern)
  { switch (doggy_Pattern_tag(me)) {
      case doggy_TypedPattern_kind:
        if (action->action_TypedPattern[PRE_ACTION] != NULL) {
          action->action_TypedPattern[PRE_ACTION](me);
        }
        if (!action->skip_children_TypedPattern) {
          Traverse_void_doggy_Type (doggy_TypedPattern_btype(me), action);
          Traverse_void_doggy_Pattern (doggy_TypedPattern_pat(me), action);
        }
        if (action->action_TypedPattern[POST_ACTION] != NULL) {
          action->action_TypedPattern[POST_ACTION](me);
        }
        break;
      case doggy_ConsPattern_kind:
        if (action->action_ConsPattern[PRE_ACTION] != NULL) {
          action->action_ConsPattern[PRE_ACTION](me);
        }
        if (!action->skip_children_ConsPattern) {
          Traverse_void_doggy_Pattern (doggy_ConsPattern_lhs(me), action);
          Traverse_void_doggy_Pattern (doggy_ConsPattern_rhs(me), action);
        }
        if (action->action_ConsPattern[POST_ACTION] != NULL) {
          action->action_ConsPattern[POST_ACTION](me);
        }
        break;
      case doggy_DefPattern_kind:
        if (action->action_DefPattern[PRE_ACTION] != NULL) {
          action->action_DefPattern[PRE_ACTION](me);
        }
        if (!action->skip_children_DefPattern) {
          Traverse_void_List_doggy_Pattern (doggy_DefPattern_ids(me), action);
          Traverse_void_doggy_Pattern (doggy_DefPattern_arg(me), action);
        }
        if (action->action_DefPattern[POST_ACTION] != NULL) {
          action->action_DefPattern[POST_ACTION](me);
        }
        break;
      case doggy_IdentPattern_kind:
        if (action->action_IdentPattern[PRE_ACTION] != NULL) {
          action->action_IdentPattern[PRE_ACTION](me);
        }
        if (action->action_IdentPattern[POST_ACTION] != NULL) {
          action->action_IdentPattern[POST_ACTION](me);
        }
        break;
      case doggy_OpPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          action->action_BasicPattern[PRE_ACTION](me);
        }
        if (action->action_OpPattern[PRE_ACTION] != NULL) {
          action->action_OpPattern[PRE_ACTION](me);
        }
        if (!action->skip_children_OpPattern) {
          Traverse_void_doggy_Applied_operation (doggy_OpPattern_op(me), action);
          Traverse_void_List_doggy_Pattern (doggy_OpPattern_args(me), action);
        }
        if (action->action_OpPattern[POST_ACTION] != NULL) {
          action->action_OpPattern[POST_ACTION](me);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          action->action_BasicPattern[POST_ACTION](me);
        }
        break;
      case doggy_ConstPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          action->action_BasicPattern[PRE_ACTION](me);
        }
        if (action->action_ConstPattern[PRE_ACTION] != NULL) {
          action->action_ConstPattern[PRE_ACTION](me);
        }
        if (action->action_ConstPattern[POST_ACTION] != NULL) {
          action->action_ConstPattern[POST_ACTION](me);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          action->action_BasicPattern[POST_ACTION](me);
        }
        break;
      case doggy_NullPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          action->action_BasicPattern[PRE_ACTION](me);
        }
        if (action->action_NullPattern[PRE_ACTION] != NULL) {
          action->action_NullPattern[PRE_ACTION](me);
        }
        if (action->action_NullPattern[POST_ACTION] != NULL) {
          action->action_NullPattern[POST_ACTION](me);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          action->action_BasicPattern[POST_ACTION](me);
        }
        break;
      case doggy_DontCarePattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          action->action_BasicPattern[PRE_ACTION](me);
        }
        if (action->action_DontCarePattern[PRE_ACTION] != NULL) {
          action->action_DontCarePattern[PRE_ACTION](me);
        }
        if (!action->skip_children_DontCarePattern) {
          Traverse_void_doggy_Expr (doggy_DontCarePattern_expr(me), action);
        }
        if (action->action_DontCarePattern[POST_ACTION] != NULL) {
          action->action_DontCarePattern[POST_ACTION](me);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          action->action_BasicPattern[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Pattern[POST_ACTION] != NULL) {
    action->action_Pattern[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Rhs (doggy_Rhs me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Rhs, me)) return;
  if (action->action_Rhs[PRE_ACTION] != NULL) {
    action->action_Rhs[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Rhs)
  { switch (doggy_Rhs_tag(me)) {
      case doggy_PlainRhs_kind:
        if (action->action_PlainRhs[PRE_ACTION] != NULL) {
          action->action_PlainRhs[PRE_ACTION](me);
        }
        if (!action->skip_children_PlainRhs) {
          Traverse_void_List_doggy_Guard (doggy_PlainRhs_guards(me), action);
        }
        if (action->action_PlainRhs[POST_ACTION] != NULL) {
          action->action_PlainRhs[POST_ACTION](me);
        }
        break;
      case doggy_BlockRhs_kind:
        if (action->action_BlockRhs[PRE_ACTION] != NULL) {
          action->action_BlockRhs[PRE_ACTION](me);
        }
        if (!action->skip_children_BlockRhs) {
          Traverse_void_doggy_Rhs (doggy_BlockRhs_rhs(me), action);
          Traverse_void_doggy_Wherepart (doggy_BlockRhs_where(me), action);
        }
        if (action->action_BlockRhs[POST_ACTION] != NULL) {
          action->action_BlockRhs[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Rhs[POST_ACTION] != NULL) {
    action->action_Rhs[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Guard (doggy_Guard me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Guard, me)) return;
  if (action->action_Guard[PRE_ACTION] != NULL) {
    action->action_Guard[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Guard)
  { switch (doggy_Guard_tag(me)) {
      case doggy_RhsGuard_kind:
        if (action->action_RhsGuard[PRE_ACTION] != NULL) {
          action->action_RhsGuard[PRE_ACTION](me);
        }
        if (!action->skip_children_Guard) {
          Traverse_void_doggy_Expr (doggy_Guard_conds(me), action);
        }
        if (!action->skip_children_RhsGuard) {
          Traverse_void_doggy_Rhs (doggy_RhsGuard_rhs(me), action);
        }
        if (!action->skip_children_Guard) {
          Traverse_void_doggy_Wherepart (doggy_Guard_where(me), action);
        }
        if (action->action_RhsGuard[POST_ACTION] != NULL) {
          action->action_RhsGuard[POST_ACTION](me);
        }
        break;
      case doggy_ExprGuard_kind:
        if (action->action_ExprGuard[PRE_ACTION] != NULL) {
          action->action_ExprGuard[PRE_ACTION](me);
        }
        if (!action->skip_children_Guard) {
          Traverse_void_doggy_Expr (doggy_Guard_conds(me), action);
        }
        if (!action->skip_children_ExprGuard) {
          Traverse_void_doggy_ExprSeq (doggy_ExprGuard_exprs(me), action);
        }
        if (!action->skip_children_Guard) {
          Traverse_void_doggy_Wherepart (doggy_Guard_where(me), action);
        }
        if (action->action_ExprGuard[POST_ACTION] != NULL) {
          action->action_ExprGuard[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Guard[POST_ACTION] != NULL) {
    action->action_Guard[POST_ACTION](me);
  }
}

void Traverse_void_doggy_ExprSeq (doggy_ExprSeq me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(ExprSeq, me)) return;
  if (action->action_ExprSeq[PRE_ACTION] != NULL) {
    action->action_ExprSeq[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_ExprSeq)
  { switch (doggy_ExprSeq_tag(me)) {
      case doggy_OneExpr_kind:
        if (action->action_OneExpr[PRE_ACTION] != NULL) {
          action->action_OneExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_OneExpr) {
          Traverse_void_doggy_Expr (doggy_OneExpr_expr(me), action);
        }
        if (action->action_OneExpr[POST_ACTION] != NULL) {
          action->action_OneExpr[POST_ACTION](me);
        }
        break;
      case doggy_MoreExprs_kind:
        if (action->action_MoreExprs[PRE_ACTION] != NULL) {
          action->action_MoreExprs[PRE_ACTION](me);
        }
        if (!action->skip_children_MoreExprs) {
          Traverse_void_List_doggy_Expr (doggy_MoreExprs_exprs(me), action);
        }
        if (action->action_MoreExprs[POST_ACTION] != NULL) {
          action->action_MoreExprs[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_ExprSeq[POST_ACTION] != NULL) {
    action->action_ExprSeq[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Wherepart (doggy_Wherepart me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Wherepart, me)) return;
  if (action->action_Wherepart[PRE_ACTION] != NULL) {
    action->action_Wherepart[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Wherepart)
  { 
  if (!action->skip_children_Wherepart) {
    Traverse_void_List_doggy_Definition (doggy_Wherepart_defs(me), action);
  }
  }
  if (action->action_Wherepart[POST_ACTION] != NULL) {
    action->action_Wherepart[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Applied_operation (doggy_Applied_operation me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Applied_operation, me)) return;
  if (action->action_Applied_operation[PRE_ACTION] != NULL) {
    action->action_Applied_operation[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Applied_operation)
  { switch (doggy_Applied_operation_tag(me)) {
      case doggy_AnyOp_kind:
        if (action->action_AnyOp[PRE_ACTION] != NULL) {
          action->action_AnyOp[PRE_ACTION](me);
        }
        if (action->action_AnyOp[POST_ACTION] != NULL) {
          action->action_AnyOp[POST_ACTION](me);
        }
        break;
      case doggy_AppliedOp_kind:
        if (action->action_AppliedOp[PRE_ACTION] != NULL) {
          action->action_AppliedOp[PRE_ACTION](me);
        }
        if (!action->skip_children_AppliedOp) {
          Traverse_void_doggy_Applied_formal (doggy_AppliedOp_op(me), action);
        }
        if (action->action_AppliedOp[POST_ACTION] != NULL) {
          action->action_AppliedOp[POST_ACTION](me);
        }
        break;
      case doggy_OpSet_kind:
        if (action->action_OpSet[PRE_ACTION] != NULL) {
          action->action_OpSet[PRE_ACTION](me);
        }
        if (!action->skip_children_OpSet) {
          Traverse_void_List_doggy_Applied_formal (doggy_OpSet_ops(me), action);
        }
        if (action->action_OpSet[POST_ACTION] != NULL) {
          action->action_OpSet[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Applied_operation[POST_ACTION] != NULL) {
    action->action_Applied_operation[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Applied_formal (doggy_Applied_formal me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Applied_formal, me)) return;
  if (action->action_Applied_formal[PRE_ACTION] != NULL) {
    action->action_Applied_formal[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Applied_formal)
  { 
  }
  if (action->action_Applied_formal[POST_ACTION] != NULL) {
    action->action_Applied_formal[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Expr (doggy_Expr me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Expr, me)) return;
  if (action->action_Expr[PRE_ACTION] != NULL) {
    action->action_Expr[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Expr)
  { switch (doggy_Expr_tag(me)) {
      case doggy_BinExpr_kind:
        if (action->action_BinExpr[PRE_ACTION] != NULL) {
          action->action_BinExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_BinExpr) {
          Traverse_void_List_doggy_Expr (doggy_BinExpr_args(me), action);
          Traverse_void_List_doggy_Operator (doggy_BinExpr_ops(me), action);
        }
        if (action->action_BinExpr[POST_ACTION] != NULL) {
          action->action_BinExpr[POST_ACTION](me);
        }
        break;
      case doggy_ConsExpr_kind:
        if (action->action_ConsExpr[PRE_ACTION] != NULL) {
          action->action_ConsExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_ConsExpr) {
          Traverse_void_doggy_Expr (doggy_ConsExpr_lhs(me), action);
          Traverse_void_doggy_Expr (doggy_ConsExpr_rhs(me), action);
        }
        if (action->action_ConsExpr[POST_ACTION] != NULL) {
          action->action_ConsExpr[POST_ACTION](me);
        }
        break;
      case doggy_IdentExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_IdentExpr[PRE_ACTION] != NULL) {
          action->action_IdentExpr[PRE_ACTION](me);
        }
        if (action->action_IdentExpr[POST_ACTION] != NULL) {
          action->action_IdentExpr[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
      case doggy_IfExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_IfExpr[PRE_ACTION] != NULL) {
          action->action_IfExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_IfExpr) {
          Traverse_void_doggy_Expr (doggy_IfExpr_cond(me), action);
          Traverse_void_doggy_Expr (doggy_IfExpr_thn(me), action);
          Traverse_void_List_doggy_Expr (doggy_IfExpr_conds(me), action);
          Traverse_void_List_doggy_Expr (doggy_IfExpr_thens(me), action);
          Traverse_void_doggy_Expr (doggy_IfExpr_els(me), action);
        }
        if (action->action_IfExpr[POST_ACTION] != NULL) {
          action->action_IfExpr[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
      case doggy_ConstExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_ConstExpr[PRE_ACTION] != NULL) {
          action->action_ConstExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_ConstExpr) {
          Traverse_void_doggy_Constant (doggy_ConstExpr_cnst(me), action);
        }
        if (action->action_ConstExpr[POST_ACTION] != NULL) {
          action->action_ConstExpr[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
      case doggy_Operation_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_Operation[PRE_ACTION] != NULL) {
          action->action_Operation[PRE_ACTION](me);
        }
        if (!action->skip_children_Operation) {
          Traverse_void_List_doggy_Expr (doggy_Operation_args(me), action);
        }
        if (action->action_Operation[POST_ACTION] != NULL) {
          action->action_Operation[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
      case doggy_ParExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_ParExpr[PRE_ACTION] != NULL) {
          action->action_ParExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_ParExpr) {
          Traverse_void_doggy_Expr (doggy_ParExpr_expr(me), action);
        }
        if (action->action_ParExpr[POST_ACTION] != NULL) {
          action->action_ParExpr[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
      case doggy_MonExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_MonExpr[PRE_ACTION] != NULL) {
          action->action_MonExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_MonExpr) {
          Traverse_void_doggy_MonOp (doggy_MonExpr_op(me), action);
          Traverse_void_doggy_Expr (doggy_MonExpr_arg(me), action);
        }
        if (action->action_MonExpr[POST_ACTION] != NULL) {
          action->action_MonExpr[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Expr[POST_ACTION] != NULL) {
    action->action_Expr[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Constant (doggy_Constant me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Constant, me)) return;
  if (action->action_Constant[PRE_ACTION] != NULL) {
    action->action_Constant[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Constant)
  { switch (doggy_Constant_tag(me)) {
      case doggy_IntConst_kind:
        if (action->action_IntConst[PRE_ACTION] != NULL) {
          action->action_IntConst[PRE_ACTION](me);
        }
        if (action->action_IntConst[POST_ACTION] != NULL) {
          action->action_IntConst[POST_ACTION](me);
        }
        break;
      case doggy_BoolConst_kind:
        if (action->action_BoolConst[PRE_ACTION] != NULL) {
          action->action_BoolConst[PRE_ACTION](me);
        }
        if (action->action_BoolConst[POST_ACTION] != NULL) {
          action->action_BoolConst[POST_ACTION](me);
        }
        break;
      case doggy_StringConst_kind:
        if (action->action_StringConst[PRE_ACTION] != NULL) {
          action->action_StringConst[PRE_ACTION](me);
        }
        if (action->action_StringConst[POST_ACTION] != NULL) {
          action->action_StringConst[POST_ACTION](me);
        }
        break;
      case doggy_NullConst_kind:
        if (action->action_NullConst[PRE_ACTION] != NULL) {
          action->action_NullConst[PRE_ACTION](me);
        }
        if (action->action_NullConst[POST_ACTION] != NULL) {
          action->action_NullConst[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Constant[POST_ACTION] != NULL) {
    action->action_Constant[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Definition (doggy_Definition me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Definition, me)) return;
  if (action->action_Definition[PRE_ACTION] != NULL) {
    action->action_Definition[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Definition)
  { 
  if (!action->skip_children_Definition) {
    Traverse_void_doggy_Type (doggy_Definition_type(me), action);
    Traverse_void_doggy_Expr (doggy_Definition_expr(me), action);
  }
  }
  if (action->action_Definition[POST_ACTION] != NULL) {
    action->action_Definition[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Type (doggy_Type me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Type, me)) return;
  if (action->action_Type[PRE_ACTION] != NULL) {
    action->action_Type[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Type)
  { switch (doggy_Type_tag(me)) {
      case doggy_EdgeType_kind:
        if (action->action_EdgeType[PRE_ACTION] != NULL) {
          action->action_EdgeType[PRE_ACTION](me);
        }
        if (!action->skip_children_EdgeType) {
          Traverse_void_List_doggy_Type (doggy_EdgeType_types(me), action);
        }
        if (action->action_EdgeType[POST_ACTION] != NULL) {
          action->action_EdgeType[POST_ACTION](me);
        }
        break;
      case doggy_TupleType_kind:
        if (action->action_TupleType[PRE_ACTION] != NULL) {
          action->action_TupleType[PRE_ACTION](me);
        }
        if (!action->skip_children_TupleType) {
          Traverse_void_List_doggy_Type (doggy_TupleType_types(me), action);
        }
        if (action->action_TupleType[POST_ACTION] != NULL) {
          action->action_TupleType[POST_ACTION](me);
        }
        break;
      case doggy_IdentType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          action->action_BasicType[PRE_ACTION](me);
        }
        if (action->action_IdentType[PRE_ACTION] != NULL) {
          action->action_IdentType[PRE_ACTION](me);
        }
        if (action->action_IdentType[POST_ACTION] != NULL) {
          action->action_IdentType[POST_ACTION](me);
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          action->action_BasicType[POST_ACTION](me);
        }
        break;
      case doggy_OprType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          action->action_BasicType[PRE_ACTION](me);
        }
        if (action->action_OprType[PRE_ACTION] != NULL) {
          action->action_OprType[PRE_ACTION](me);
        }
        if (!action->skip_children_OprType) {
          Traverse_void_List_doggy_Type (doggy_OprType_args(me), action);
        }
        if (action->action_OprType[POST_ACTION] != NULL) {
          action->action_OprType[POST_ACTION](me);
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          action->action_BasicType[POST_ACTION](me);
        }
        break;
      case doggy_PointerType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          action->action_BasicType[PRE_ACTION](me);
        }
        if (action->action_PointerType[PRE_ACTION] != NULL) {
          action->action_PointerType[PRE_ACTION](me);
        }
        if (!action->skip_children_PointerType) {
          Traverse_void_doggy_Type (doggy_PointerType_base(me), action);
        }
        if (action->action_PointerType[POST_ACTION] != NULL) {
          action->action_PointerType[POST_ACTION](me);
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          action->action_BasicType[POST_ACTION](me);
        }
        break;
      case doggy_RangeType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          action->action_BasicType[PRE_ACTION](me);
        }
        if (action->action_RangeType[PRE_ACTION] != NULL) {
          action->action_RangeType[PRE_ACTION](me);
        }
        if (!action->skip_children_RangeType) {
          Traverse_void_doggy_Num (doggy_RangeType_lo(me), action);
          Traverse_void_doggy_Num (doggy_RangeType_hi(me), action);
          Traverse_void_doggy_Num (doggy_RangeType_step(me), action);
        }
        if (action->action_RangeType[POST_ACTION] != NULL) {
          action->action_RangeType[POST_ACTION](me);
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          action->action_BasicType[POST_ACTION](me);
        }
        break;
      case doggy_FRangeType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          action->action_BasicType[PRE_ACTION](me);
        }
        if (action->action_FRangeType[PRE_ACTION] != NULL) {
          action->action_FRangeType[PRE_ACTION](me);
        }
        if (action->action_FRangeType[POST_ACTION] != NULL) {
          action->action_FRangeType[POST_ACTION](me);
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          action->action_BasicType[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Type[POST_ACTION] != NULL) {
    action->action_Type[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Num (doggy_Num me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Num, me)) return;
  if (action->action_Num[PRE_ACTION] != NULL) {
    action->action_Num[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Num)
  { 
  }
  if (action->action_Num[POST_ACTION] != NULL) {
    action->action_Num[POST_ACTION](me);
  }
}

void Traverse_void_doggy_IdInt (doggy_IdInt me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(IdInt, me)) return;
  if (action->action_IdInt[PRE_ACTION] != NULL) {
    action->action_IdInt[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_IdInt)
  { switch (doggy_IdInt_tag(me)) {
      case doggy_IsId_kind:
        if (action->action_IsId[PRE_ACTION] != NULL) {
          action->action_IsId[PRE_ACTION](me);
        }
        if (action->action_IsId[POST_ACTION] != NULL) {
          action->action_IsId[POST_ACTION](me);
        }
        break;
      case doggy_IsInt_kind:
        if (action->action_IsInt[PRE_ACTION] != NULL) {
          action->action_IsInt[PRE_ACTION](me);
        }
        if (action->action_IsInt[POST_ACTION] != NULL) {
          action->action_IsInt[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_IdInt[POST_ACTION] != NULL) {
    action->action_IdInt[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Path (doggy_Path me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Path, me)) return;
  if (action->action_Path[PRE_ACTION] != NULL) {
    action->action_Path[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Path)
  { 
  if (!action->skip_children_Path) {
    Traverse_void_doggy_Type (doggy_Path_type(me), action);
    Traverse_void_doggy_Path (doggy_Path_next(me), action);
  }
  }
  if (action->action_Path[POST_ACTION] != NULL) {
    action->action_Path[POST_ACTION](me);
  }
}

void Traverse_void_doggy_ActualOp (doggy_ActualOp me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(ActualOp, me)) return;
  if (action->action_ActualOp[PRE_ACTION] != NULL) {
    action->action_ActualOp[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_ActualOp)
  { 
  if (!action->skip_children_ActualOp) {
    Traverse_void_List_doggy_Operation_def (doggy_ActualOp_formals(me), action);
  }
  }
  if (action->action_ActualOp[POST_ACTION] != NULL) {
    action->action_ActualOp[POST_ACTION](me);
  }
}

void Traverse_void_doggy_TypePair (doggy_TypePair me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(TypePair, me)) return;
  if (action->action_TypePair[PRE_ACTION] != NULL) {
    action->action_TypePair[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_TypePair)
  { 
  if (!action->skip_children_TypePair) {
    Traverse_void_doggy_Type (doggy_TypePair_t1(me), action);
    Traverse_void_doggy_Type (doggy_TypePair_t2(me), action);
  }
  }
  if (action->action_TypePair[POST_ACTION] != NULL) {
    action->action_TypePair[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Opat (doggy_Opat me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Opat, me)) return;
  if (action->action_Opat[PRE_ACTION] != NULL) {
    action->action_Opat[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Opat)
  { 
  if (!action->skip_children_Opat) {
    Traverse_void_List_doggy_Type (doggy_Opat_args(me), action);
    Traverse_void_doggy_Type (doggy_Opat_result(me), action);
  }
  }
  if (action->action_Opat[POST_ACTION] != NULL) {
    action->action_Opat[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Format (doggy_Format me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Format, me)) return;
  if (action->action_Format[PRE_ACTION] != NULL) {
    action->action_Format[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Format)
  { 
  if (!action->skip_children_Format) {
    Traverse_void_List_doggy_Type (doggy_Format_args(me), action);
    Traverse_void_doggy_Type (doggy_Format_result(me), action);
  }
  }
  if (action->action_Format[POST_ACTION] != NULL) {
    action->action_Format[POST_ACTION](me);
  }
}

void Traverse_void_doggy_dummy_type (doggy_dummy_type me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(dummy_type, me)) return;
  if (action->action_dummy_type[PRE_ACTION] != NULL) {
    action->action_dummy_type[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_dummy_type)
  { 
  if (!action->skip_children_dummy_type) {
    Traverse_void_List_doggy_ActualOp (doggy_dummy_type_y(me), action);
    Traverse_void_List_doggy_TypePair (doggy_dummy_type_z(me), action);
  }
  }
  if (action->action_dummy_type[POST_ACTION] != NULL) {
    action->action_dummy_type[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Scope (doggy_Scope me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Scope, me)) return;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    action->action_Scope[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Scope)
  { switch (doggy_Scope_tag(me)) {
      case doggy_OpSetScope_kind:
        if (action->action_OpSetScope[PRE_ACTION] != NULL) {
          action->action_OpSetScope[PRE_ACTION](me);
        }
        if (!action->skip_children_Scope) {
          Traverse_void_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_OpSetScope) {
          Traverse_void_doggy_Applied_operation (doggy_OpSetScope_data(me), action);
        }
        if (action->action_OpSetScope[POST_ACTION] != NULL) {
          action->action_OpSetScope[POST_ACTION](me);
        }
        break;
      case doggy_AppliedOpScope_kind:
        if (action->action_AppliedOpScope[PRE_ACTION] != NULL) {
          action->action_AppliedOpScope[PRE_ACTION](me);
        }
        if (!action->skip_children_Scope) {
          Traverse_void_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_AppliedOpScope) {
          Traverse_void_doggy_Applied_operation (doggy_AppliedOpScope_data(me), action);
        }
        if (action->action_AppliedOpScope[POST_ACTION] != NULL) {
          action->action_AppliedOpScope[POST_ACTION](me);
        }
        break;
      case doggy_ExprGuardScope_kind:
        if (action->action_ExprGuardScope[PRE_ACTION] != NULL) {
          action->action_ExprGuardScope[PRE_ACTION](me);
        }
        if (!action->skip_children_Scope) {
          Traverse_void_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_ExprGuardScope) {
          Traverse_void_doggy_Guard (doggy_ExprGuardScope_data(me), action);
        }
        if (action->action_ExprGuardScope[POST_ACTION] != NULL) {
          action->action_ExprGuardScope[POST_ACTION](me);
        }
        break;
      case doggy_RhsGuardScope_kind:
        if (action->action_RhsGuardScope[PRE_ACTION] != NULL) {
          action->action_RhsGuardScope[PRE_ACTION](me);
        }
        if (!action->skip_children_Scope) {
          Traverse_void_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_RhsGuardScope) {
          Traverse_void_doggy_Guard (doggy_RhsGuardScope_data(me), action);
        }
        if (action->action_RhsGuardScope[POST_ACTION] != NULL) {
          action->action_RhsGuardScope[POST_ACTION](me);
        }
        break;
      case doggy_FuncRuleScope_kind:
        if (action->action_FuncRuleScope[PRE_ACTION] != NULL) {
          action->action_FuncRuleScope[PRE_ACTION](me);
        }
        if (!action->skip_children_Scope) {
          Traverse_void_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_FuncRuleScope) {
          Traverse_void_doggy_FuncRule (doggy_FuncRuleScope_data(me), action);
        }
        if (action->action_FuncRuleScope[POST_ACTION] != NULL) {
          action->action_FuncRuleScope[POST_ACTION](me);
        }
        break;
      case doggy_RuleScope_kind:
        if (action->action_RuleScope[PRE_ACTION] != NULL) {
          action->action_RuleScope[PRE_ACTION](me);
        }
        if (!action->skip_children_Scope) {
          Traverse_void_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_RuleScope) {
          Traverse_void_doggy_Rule (doggy_RuleScope_data(me), action);
        }
        if (action->action_RuleScope[POST_ACTION] != NULL) {
          action->action_RuleScope[POST_ACTION](me);
        }
        break;
      case doggy_machine_descriptionScope_kind:
        if (action->action_machine_descriptionScope[PRE_ACTION] != NULL) {
          action->action_machine_descriptionScope[PRE_ACTION](me);
        }
        if (!action->skip_children_Scope) {
          Traverse_void_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_machine_descriptionScope) {
          Traverse_void_doggy_machine_description (doggy_machine_descriptionScope_data(me), action);
        }
        if (action->action_machine_descriptionScope[POST_ACTION] != NULL) {
          action->action_machine_descriptionScope[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    action->action_Scope[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Num (List_doggy_Num me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Num, me)) return;
  if (action->action_List_Num[PRE_ACTION] != NULL) {
    action->action_List_Num[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Num)
  { 
  if (!action->skip_children_List_Num) {
    Traverse_void_doggy_Num (List_doggy_Num_data(me), action);
    Traverse_void_List_doggy_Num (List_doggy_Num_next(me), action);
  }
  }
  if (action->action_List_Num[POST_ACTION] != NULL) {
    action->action_List_Num[POST_ACTION](me);
  }
}

void Traverse_void_List_List_doggy_TypePair (List_List_doggy_TypePair me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_List_TypePair, me)) return;
  if (action->action_List_List_TypePair[PRE_ACTION] != NULL) {
    action->action_List_List_TypePair[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_List_TypePair)
  { 
  if (!action->skip_children_List_List_TypePair) {
    Traverse_void_List_doggy_TypePair (List_List_doggy_TypePair_data(me), action);
    Traverse_void_List_List_doggy_TypePair (List_List_doggy_TypePair_next(me), action);
  }
  }
  if (action->action_List_List_TypePair[POST_ACTION] != NULL) {
    action->action_List_List_TypePair[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_TypePair (List_doggy_TypePair me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_TypePair, me)) return;
  if (action->action_List_TypePair[PRE_ACTION] != NULL) {
    action->action_List_TypePair[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_TypePair)
  { 
  if (!action->skip_children_List_TypePair) {
    Traverse_void_doggy_TypePair (List_doggy_TypePair_data(me), action);
    Traverse_void_List_doggy_TypePair (List_doggy_TypePair_next(me), action);
  }
  }
  if (action->action_List_TypePair[POST_ACTION] != NULL) {
    action->action_List_TypePair[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_ActualOp (List_doggy_ActualOp me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_ActualOp, me)) return;
  if (action->action_List_ActualOp[PRE_ACTION] != NULL) {
    action->action_List_ActualOp[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_ActualOp)
  { 
  if (!action->skip_children_List_ActualOp) {
    Traverse_void_doggy_ActualOp (List_doggy_ActualOp_data(me), action);
    Traverse_void_List_doggy_ActualOp (List_doggy_ActualOp_next(me), action);
  }
  }
  if (action->action_List_ActualOp[POST_ACTION] != NULL) {
    action->action_List_ActualOp[POST_ACTION](me);
  }
}

void Traverse_void_List_List_doggy_Type (List_List_doggy_Type me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_List_Type, me)) return;
  if (action->action_List_List_Type[PRE_ACTION] != NULL) {
    action->action_List_List_Type[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_List_Type)
  { 
  if (!action->skip_children_List_List_Type) {
    Traverse_void_List_doggy_Type (List_List_doggy_Type_data(me), action);
    Traverse_void_List_List_doggy_Type (List_List_doggy_Type_next(me), action);
  }
  }
  if (action->action_List_List_Type[POST_ACTION] != NULL) {
    action->action_List_List_Type[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Operator (List_doggy_Operator me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Operator, me)) return;
  if (action->action_List_Operator[PRE_ACTION] != NULL) {
    action->action_List_Operator[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Operator)
  { 
  if (!action->skip_children_List_Operator) {
    Traverse_void_doggy_Operator (List_doggy_Operator_data(me), action);
    Traverse_void_List_doggy_Operator (List_doggy_Operator_next(me), action);
  }
  }
  if (action->action_List_Operator[POST_ACTION] != NULL) {
    action->action_List_Operator[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Definition (List_doggy_Definition me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Definition, me)) return;
  if (action->action_List_Definition[PRE_ACTION] != NULL) {
    action->action_List_Definition[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Definition)
  { 
  if (!action->skip_children_List_Definition) {
    Traverse_void_doggy_Definition (List_doggy_Definition_data(me), action);
    Traverse_void_List_doggy_Definition (List_doggy_Definition_next(me), action);
  }
  }
  if (action->action_List_Definition[POST_ACTION] != NULL) {
    action->action_List_Definition[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Expr (List_doggy_Expr me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Expr, me)) return;
  if (action->action_List_Expr[PRE_ACTION] != NULL) {
    action->action_List_Expr[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Expr)
  { 
  if (!action->skip_children_List_Expr) {
    Traverse_void_doggy_Expr (List_doggy_Expr_data(me), action);
    Traverse_void_List_doggy_Expr (List_doggy_Expr_next(me), action);
  }
  }
  if (action->action_List_Expr[POST_ACTION] != NULL) {
    action->action_List_Expr[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Guard (List_doggy_Guard me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Guard, me)) return;
  if (action->action_List_Guard[PRE_ACTION] != NULL) {
    action->action_List_Guard[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Guard)
  { 
  if (!action->skip_children_List_Guard) {
    Traverse_void_doggy_Guard (List_doggy_Guard_data(me), action);
    Traverse_void_List_doggy_Guard (List_doggy_Guard_next(me), action);
  }
  }
  if (action->action_List_Guard[POST_ACTION] != NULL) {
    action->action_List_Guard[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Pattern (List_doggy_Pattern me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Pattern, me)) return;
  if (action->action_List_Pattern[PRE_ACTION] != NULL) {
    action->action_List_Pattern[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Pattern)
  { 
  if (!action->skip_children_List_Pattern) {
    Traverse_void_doggy_Pattern (List_doggy_Pattern_data(me), action);
    Traverse_void_List_doggy_Pattern (List_doggy_Pattern_next(me), action);
  }
  }
  if (action->action_List_Pattern[POST_ACTION] != NULL) {
    action->action_List_Pattern[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Argument (List_doggy_Argument me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Argument, me)) return;
  if (action->action_List_Argument[PRE_ACTION] != NULL) {
    action->action_List_Argument[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Argument)
  { 
  if (!action->skip_children_List_Argument) {
    Traverse_void_doggy_Argument (List_doggy_Argument_data(me), action);
    Traverse_void_List_doggy_Argument (List_doggy_Argument_next(me), action);
  }
  }
  if (action->action_List_Argument[POST_ACTION] != NULL) {
    action->action_List_Argument[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_FuncRule (List_doggy_FuncRule me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_FuncRule, me)) return;
  if (action->action_List_FuncRule[PRE_ACTION] != NULL) {
    action->action_List_FuncRule[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_FuncRule)
  { 
  if (!action->skip_children_List_FuncRule) {
    Traverse_void_doggy_FuncRule (List_doggy_FuncRule_data(me), action);
    Traverse_void_List_doggy_FuncRule (List_doggy_FuncRule_next(me), action);
  }
  }
  if (action->action_List_FuncRule[POST_ACTION] != NULL) {
    action->action_List_FuncRule[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Attribute (List_doggy_Attribute me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Attribute, me)) return;
  if (action->action_List_Attribute[PRE_ACTION] != NULL) {
    action->action_List_Attribute[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Attribute)
  { 
  if (!action->skip_children_List_Attribute) {
    Traverse_void_doggy_Attribute (List_doggy_Attribute_data(me), action);
    Traverse_void_List_doggy_Attribute (List_doggy_Attribute_next(me), action);
  }
  }
  if (action->action_List_Attribute[POST_ACTION] != NULL) {
    action->action_List_Attribute[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Property (List_doggy_Property me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Property, me)) return;
  if (action->action_List_Property[PRE_ACTION] != NULL) {
    action->action_List_Property[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Property)
  { 
  if (!action->skip_children_List_Property) {
    Traverse_void_doggy_Property (List_doggy_Property_data(me), action);
    Traverse_void_List_doggy_Property (List_doggy_Property_next(me), action);
  }
  }
  if (action->action_List_Property[POST_ACTION] != NULL) {
    action->action_List_Property[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Applied_formal (List_doggy_Applied_formal me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Applied_formal, me)) return;
  if (action->action_List_Applied_formal[PRE_ACTION] != NULL) {
    action->action_List_Applied_formal[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Applied_formal)
  { 
  if (!action->skip_children_List_Applied_formal) {
    Traverse_void_doggy_Applied_formal (List_doggy_Applied_formal_data(me), action);
    Traverse_void_List_doggy_Applied_formal (List_doggy_Applied_formal_next(me), action);
  }
  }
  if (action->action_List_Applied_formal[POST_ACTION] != NULL) {
    action->action_List_Applied_formal[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Operation_def (List_doggy_Operation_def me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Operation_def, me)) return;
  if (action->action_List_Operation_def[PRE_ACTION] != NULL) {
    action->action_List_Operation_def[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Operation_def)
  { 
  if (!action->skip_children_List_Operation_def) {
    Traverse_void_doggy_Operation_def (List_doggy_Operation_def_data(me), action);
    Traverse_void_List_doggy_Operation_def (List_doggy_Operation_def_next(me), action);
  }
  }
  if (action->action_List_Operation_def[POST_ACTION] != NULL) {
    action->action_List_Operation_def[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Type (List_doggy_Type me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Type, me)) return;
  if (action->action_List_Type[PRE_ACTION] != NULL) {
    action->action_List_Type[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Type)
  { 
  if (!action->skip_children_List_Type) {
    Traverse_void_doggy_Type (List_doggy_Type_data(me), action);
    Traverse_void_List_doggy_Type (List_doggy_Type_next(me), action);
  }
  }
  if (action->action_List_Type[POST_ACTION] != NULL) {
    action->action_List_Type[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Rule (List_doggy_Rule me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Rule, me)) return;
  if (action->action_List_Rule[PRE_ACTION] != NULL) {
    action->action_List_Rule[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Rule)
  { 
  if (!action->skip_children_List_Rule) {
    Traverse_void_doggy_Rule (List_doggy_Rule_data(me), action);
    Traverse_void_List_doggy_Rule (List_doggy_Rule_next(me), action);
  }
  }
  if (action->action_List_Rule[POST_ACTION] != NULL) {
    action->action_List_Rule[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Func (List_doggy_Func me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Func, me)) return;
  if (action->action_List_Func[PRE_ACTION] != NULL) {
    action->action_List_Func[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Func)
  { 
  if (!action->skip_children_List_Func) {
    Traverse_void_doggy_Func (List_doggy_Func_data(me), action);
    Traverse_void_List_doggy_Func (List_doggy_Func_next(me), action);
  }
  }
  if (action->action_List_Func[POST_ACTION] != NULL) {
    action->action_List_Func[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Section (List_doggy_Section me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Section, me)) return;
  if (action->action_List_Section[PRE_ACTION] != NULL) {
    action->action_List_Section[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Section)
  { 
  if (!action->skip_children_List_Section) {
    Traverse_void_doggy_Section (List_doggy_Section_data(me), action);
    Traverse_void_List_doggy_Section (List_doggy_Section_next(me), action);
  }
  }
  if (action->action_List_Section[POST_ACTION] != NULL) {
    action->action_List_Section[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_FunctionDef (List_doggy_FunctionDef me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_FunctionDef, me)) return;
  if (action->action_List_FunctionDef[PRE_ACTION] != NULL) {
    action->action_List_FunctionDef[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_FunctionDef)
  { 
  if (!action->skip_children_List_FunctionDef) {
    Traverse_void_doggy_FunctionDef (List_doggy_FunctionDef_data(me), action);
    Traverse_void_List_doggy_FunctionDef (List_doggy_FunctionDef_next(me), action);
  }
  }
  if (action->action_List_FunctionDef[POST_ACTION] != NULL) {
    action->action_List_FunctionDef[POST_ACTION](me);
  }
}

void Traverse_void_List_doggy_Typedef (List_doggy_Typedef me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(List_Typedef, me)) return;
  if (action->action_List_Typedef[PRE_ACTION] != NULL) {
    action->action_List_Typedef[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Typedef)
  { 
  if (!action->skip_children_List_Typedef) {
    Traverse_void_doggy_Typedef (List_doggy_Typedef_data(me), action);
    Traverse_void_List_doggy_Typedef (List_doggy_Typedef_next(me), action);
  }
  }
  if (action->action_List_Typedef[POST_ACTION] != NULL) {
    action->action_List_Typedef[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Operator (doggy_Operator me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Operator, me)) return;
  if (action->action_Operator[PRE_ACTION] != NULL) {
    action->action_Operator[PRE_ACTION](me);
  }
  { switch (me) {
      case doggy_CandOp:
        if (action->action_CandOp[PRE_ACTION] != NULL) {
          action->action_CandOp[PRE_ACTION](me);
        }
        if (action->action_CandOp[POST_ACTION] != NULL) {
          action->action_CandOp[POST_ACTION](me);
        }
        break;
      case doggy_CorOp:
        if (action->action_CorOp[PRE_ACTION] != NULL) {
          action->action_CorOp[PRE_ACTION](me);
        }
        if (action->action_CorOp[POST_ACTION] != NULL) {
          action->action_CorOp[POST_ACTION](me);
        }
        break;
      case doggy_XorOp:
        if (action->action_XorOp[PRE_ACTION] != NULL) {
          action->action_XorOp[PRE_ACTION](me);
        }
        if (action->action_XorOp[POST_ACTION] != NULL) {
          action->action_XorOp[POST_ACTION](me);
        }
        break;
      case doggy_EqOp:
        if (action->action_EqOp[PRE_ACTION] != NULL) {
          action->action_EqOp[PRE_ACTION](me);
        }
        if (action->action_EqOp[POST_ACTION] != NULL) {
          action->action_EqOp[POST_ACTION](me);
        }
        break;
      case doggy_NeqOp:
        if (action->action_NeqOp[PRE_ACTION] != NULL) {
          action->action_NeqOp[PRE_ACTION](me);
        }
        if (action->action_NeqOp[POST_ACTION] != NULL) {
          action->action_NeqOp[POST_ACTION](me);
        }
        break;
      case doggy_LEOp:
        if (action->action_LEOp[PRE_ACTION] != NULL) {
          action->action_LEOp[PRE_ACTION](me);
        }
        if (action->action_LEOp[POST_ACTION] != NULL) {
          action->action_LEOp[POST_ACTION](me);
        }
        break;
      case doggy_GEOp:
        if (action->action_GEOp[PRE_ACTION] != NULL) {
          action->action_GEOp[PRE_ACTION](me);
        }
        if (action->action_GEOp[POST_ACTION] != NULL) {
          action->action_GEOp[POST_ACTION](me);
        }
        break;
      case doggy_LTOp:
        if (action->action_LTOp[PRE_ACTION] != NULL) {
          action->action_LTOp[PRE_ACTION](me);
        }
        if (action->action_LTOp[POST_ACTION] != NULL) {
          action->action_LTOp[POST_ACTION](me);
        }
        break;
      case doggy_GTOp:
        if (action->action_GTOp[PRE_ACTION] != NULL) {
          action->action_GTOp[PRE_ACTION](me);
        }
        if (action->action_GTOp[POST_ACTION] != NULL) {
          action->action_GTOp[POST_ACTION](me);
        }
        break;
      case doggy_SLOp:
        if (action->action_SLOp[PRE_ACTION] != NULL) {
          action->action_SLOp[PRE_ACTION](me);
        }
        if (action->action_SLOp[POST_ACTION] != NULL) {
          action->action_SLOp[POST_ACTION](me);
        }
        break;
      case doggy_SROp:
        if (action->action_SROp[PRE_ACTION] != NULL) {
          action->action_SROp[PRE_ACTION](me);
        }
        if (action->action_SROp[POST_ACTION] != NULL) {
          action->action_SROp[POST_ACTION](me);
        }
        break;
      case doggy_DivOp:
        if (action->action_DivOp[PRE_ACTION] != NULL) {
          action->action_DivOp[PRE_ACTION](me);
        }
        if (action->action_DivOp[POST_ACTION] != NULL) {
          action->action_DivOp[POST_ACTION](me);
        }
        break;
      case doggy_ModOp:
        if (action->action_ModOp[PRE_ACTION] != NULL) {
          action->action_ModOp[PRE_ACTION](me);
        }
        if (action->action_ModOp[POST_ACTION] != NULL) {
          action->action_ModOp[POST_ACTION](me);
        }
        break;
      case doggy_MulOp:
        if (action->action_MulOp[PRE_ACTION] != NULL) {
          action->action_MulOp[PRE_ACTION](me);
        }
        if (action->action_MulOp[POST_ACTION] != NULL) {
          action->action_MulOp[POST_ACTION](me);
        }
        break;
      case doggy_AndOp:
        if (action->action_AndOp[PRE_ACTION] != NULL) {
          action->action_AndOp[PRE_ACTION](me);
        }
        if (action->action_AndOp[POST_ACTION] != NULL) {
          action->action_AndOp[POST_ACTION](me);
        }
        break;
      case doggy_AddOp:
        if (action->action_AddOp[PRE_ACTION] != NULL) {
          action->action_AddOp[PRE_ACTION](me);
        }
        if (action->action_AddOp[POST_ACTION] != NULL) {
          action->action_AddOp[POST_ACTION](me);
        }
        break;
      case doggy_SubOp:
        if (action->action_SubOp[PRE_ACTION] != NULL) {
          action->action_SubOp[PRE_ACTION](me);
        }
        if (action->action_SubOp[POST_ACTION] != NULL) {
          action->action_SubOp[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Operator[POST_ACTION] != NULL) {
    action->action_Operator[POST_ACTION](me);
  }
}

void Traverse_void_doggy_MonOp (doggy_MonOp me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(MonOp, me)) return;
  if (action->action_MonOp[PRE_ACTION] != NULL) {
    action->action_MonOp[PRE_ACTION](me);
  }
  { switch (me) {
      case doggy_NotOp:
        if (action->action_NotOp[PRE_ACTION] != NULL) {
          action->action_NotOp[PRE_ACTION](me);
        }
        if (action->action_NotOp[POST_ACTION] != NULL) {
          action->action_NotOp[POST_ACTION](me);
        }
        break;
      case doggy_NegOp:
        if (action->action_NegOp[PRE_ACTION] != NULL) {
          action->action_NegOp[PRE_ACTION](me);
        }
        if (action->action_NegOp[POST_ACTION] != NULL) {
          action->action_NegOp[POST_ACTION](me);
        }
        break;
      case doggy_AddrOp:
        if (action->action_AddrOp[PRE_ACTION] != NULL) {
          action->action_AddrOp[PRE_ACTION](me);
        }
        if (action->action_AddrOp[POST_ACTION] != NULL) {
          action->action_AddrOp[POST_ACTION](me);
        }
        break;
      case doggy_DerefOp:
        if (action->action_DerefOp[PRE_ACTION] != NULL) {
          action->action_DerefOp[PRE_ACTION](me);
        }
        if (action->action_DerefOp[POST_ACTION] != NULL) {
          action->action_DerefOp[POST_ACTION](me);
        }
        break;
      case doggy_PlusOp:
        if (action->action_PlusOp[PRE_ACTION] != NULL) {
          action->action_PlusOp[PRE_ACTION](me);
        }
        if (action->action_PlusOp[POST_ACTION] != NULL) {
          action->action_PlusOp[POST_ACTION](me);
        }
        break;
      case doggy_MinOp:
        if (action->action_MinOp[PRE_ACTION] != NULL) {
          action->action_MinOp[PRE_ACTION](me);
        }
        if (action->action_MinOp[POST_ACTION] != NULL) {
          action->action_MinOp[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_MonOp[POST_ACTION] != NULL) {
    action->action_MonOp[POST_ACTION](me);
  }
}

void Traverse_void_doggy_Property (doggy_Property me, void_doggy_TraverseTable action)
{ 
  if (doggy_SKIP_NODE(Property, me)) return;
  if (action->action_Property[PRE_ACTION] != NULL) {
    action->action_Property[PRE_ACTION](me);
  }
  {   }
  if (action->action_Property[POST_ACTION] != NULL) {
    action->action_Property[POST_ACTION](me);
  }
}

doggy_doggy Traverse_copy_doggy_doggy (doggy_doggy me, copy_doggy_TraverseTable action)
{ doggy_doggy _new = me, _old = me;
  if (action->action_doggy[PRE_ACTION] != NULL) {
    _new = action->action_doggy[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_doggy)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_doggy) {
    doggy_doggy_types(me) = Traverse_copy_List_doggy_Typedef (doggy_doggy_types(me), action);
    doggy_doggy_source(me) = Traverse_copy_doggy_machine_description (doggy_doggy_source(me), action);
    doggy_doggy_target(me) = Traverse_copy_doggy_machine_description (doggy_doggy_target(me), action);
    doggy_doggy_funcs(me) = Traverse_copy_List_doggy_FunctionDef (doggy_doggy_funcs(me), action);
    doggy_doggy_sections(me) = Traverse_copy_List_doggy_Section (doggy_doggy_sections(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_doggy_functions(me) = NULL;
      doggy_doggy_rules(me) = NULL;
      Store_md (me);
    }
  }
  if (action->action_doggy[POST_ACTION] != NULL) {
    me = action->action_doggy[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Typedef Traverse_copy_doggy_Typedef (doggy_Typedef me, copy_doggy_TraverseTable action)
{ doggy_Typedef _new = me, _old = me;
  if (action->action_Typedef[PRE_ACTION] != NULL) {
    _new = action->action_Typedef[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Typedef)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Typedef) {
    doggy_Typedef_attrs(me) = Traverse_copy_doggy_Attributes (doggy_Typedef_attrs(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_Typedef_scope(me) = NULL;
      doggy_Typedef_old_scope(me) = NULL;
    }
  }
  if (action->action_Typedef[POST_ACTION] != NULL) {
    me = action->action_Typedef[POST_ACTION](me, _old);
  }
  return me;
}

doggy_FunctionDef Traverse_copy_doggy_FunctionDef (doggy_FunctionDef me, copy_doggy_TraverseTable action)
{ doggy_FunctionDef _new = me, _old = me;
  if (action->action_FunctionDef[PRE_ACTION] != NULL) {
    _new = action->action_FunctionDef[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_FunctionDef)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_FunctionDef_tag(me)) {
      case doggy_ExtFunc_kind:
        if (action->action_ExtFunc[PRE_ACTION] != NULL) {
          _new = action->action_ExtFunc[PRE_ACTION](me, me);
        }
        if (!action->skip_children_FunctionDef) {
          doggy_FunctionDef_result(me) = Traverse_copy_doggy_Type (doggy_FunctionDef_result(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_FunctionDef_scope(me) = NULL;
            doggy_FunctionDef_old_scope(me) = NULL;
          }
        if (!action->skip_children_ExtFunc) {
          doggy_ExtFunc_args(me) = Traverse_copy_List_doggy_Type (doggy_ExtFunc_args(me), action);
        }
        if (action->action_ExtFunc[POST_ACTION] != NULL) {
          _new = action->action_ExtFunc[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_ExtVar_kind:
        if (action->action_ExtVar[PRE_ACTION] != NULL) {
          _new = action->action_ExtVar[PRE_ACTION](me, me);
        }
        if (!action->skip_children_FunctionDef) {
          doggy_FunctionDef_result(me) = Traverse_copy_doggy_Type (doggy_FunctionDef_result(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_FunctionDef_scope(me) = NULL;
            doggy_FunctionDef_old_scope(me) = NULL;
          }
        if (action->action_ExtVar[POST_ACTION] != NULL) {
          _new = action->action_ExtVar[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_FunctionDef[POST_ACTION] != NULL) {
    me = action->action_FunctionDef[POST_ACTION](me, _old);
  }
  return me;
}

doggy_machine_description Traverse_copy_doggy_machine_description (doggy_machine_description me, copy_doggy_TraverseTable action)
{ doggy_machine_description _new = me, _old = me;
  if (action->action_machine_description[PRE_ACTION] != NULL) {
    _new = action->action_machine_description[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_machine_description)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_machine_description) {
    doggy_machine_description_defs(me) = Traverse_copy_List_doggy_Operation_def (doggy_machine_description_defs(me), action);
    doggy_machine_description_supports(me) = Traverse_copy_List_doggy_Applied_formal (doggy_machine_description_supports(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_machine_description_scope(me) = NULL;
      doggy_machine_description_old_scope(me) = NULL;
    }
  }
  if (action->action_machine_description[POST_ACTION] != NULL) {
    me = action->action_machine_description[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Operation_def Traverse_copy_doggy_Operation_def (doggy_Operation_def me, copy_doggy_TraverseTable action)
{ doggy_Operation_def _new = me, _old = me;
  if (action->action_Operation_def[PRE_ACTION] != NULL) {
    _new = action->action_Operation_def[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Operation_def)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Operation_def) {
    doggy_Operation_def_types(me) = Traverse_copy_List_doggy_Type (doggy_Operation_def_types(me), action);
    doggy_Operation_def_result(me) = Traverse_copy_doggy_Type (doggy_Operation_def_result(me), action);
    doggy_Operation_def_descr(me) = Traverse_copy_doggy_Attributes (doggy_Operation_def_descr(me), action);
    doggy_Operation_def_props(me) = Traverse_copy_List_doggy_Property (doggy_Operation_def_props(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_Operation_def_scope(me) = NULL;
      doggy_Operation_def_old_scope(me) = NULL;
      doggy_Operation_def_type(me) = Create_OprType (make_src_info (- 1), Operation_def_types (me));
      doggy_Operation_def_src(me) = FALSE;
      doggy_Operation_def_tgt(me) = FALSE;
      doggy_Operation_def_supported(me) = FALSE;
      doggy_Operation_def_mop(me) = NULL;
      doggy_Operation_def_value(me) = NoValue ();
    }
  }
  if (action->action_Operation_def[POST_ACTION] != NULL) {
    me = action->action_Operation_def[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Attributes Traverse_copy_doggy_Attributes (doggy_Attributes me, copy_doggy_TraverseTable action)
{ doggy_Attributes _new = me, _old = me;
  if (action->action_Attributes[PRE_ACTION] != NULL) {
    _new = action->action_Attributes[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Attributes)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Attributes) {
    doggy_Attributes_ids(me) = Traverse_copy_List_doggy_Attribute (doggy_Attributes_ids(me), action);
    doggy_Attributes_tail(me) = Traverse_copy_doggy_Attributes (doggy_Attributes_tail(me), action);
  }
  }
  if (action->action_Attributes[POST_ACTION] != NULL) {
    me = action->action_Attributes[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Attribute Traverse_copy_doggy_Attribute (doggy_Attribute me, copy_doggy_TraverseTable action)
{ doggy_Attribute _new = me, _old = me;
  if (action->action_Attribute[PRE_ACTION] != NULL) {
    _new = action->action_Attribute[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Attribute)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Attribute_tag(me)) {
      case doggy_IdAttr_kind:
        if (action->action_IdAttr[PRE_ACTION] != NULL) {
          _new = action->action_IdAttr[PRE_ACTION](me, me);
        }
        if (action->action_IdAttr[POST_ACTION] != NULL) {
          _new = action->action_IdAttr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_OpAttr_kind:
        if (action->action_OpAttr[PRE_ACTION] != NULL) {
          _new = action->action_OpAttr[PRE_ACTION](me, me);
        }
        if (action->action_OpAttr[POST_ACTION] != NULL) {
          _new = action->action_OpAttr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_IntAttr_kind:
        if (action->action_IntAttr[PRE_ACTION] != NULL) {
          _new = action->action_IntAttr[PRE_ACTION](me, me);
        }
        if (action->action_IntAttr[POST_ACTION] != NULL) {
          _new = action->action_IntAttr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Attribute[POST_ACTION] != NULL) {
    me = action->action_Attribute[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Section Traverse_copy_doggy_Section (doggy_Section me, copy_doggy_TraverseTable action)
{ doggy_Section _new = me, _old = me;
  if (action->action_Section[PRE_ACTION] != NULL) {
    _new = action->action_Section[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Section)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Section_tag(me)) {
      case doggy_FuncSection_kind:
        if (action->action_FuncSection[PRE_ACTION] != NULL) {
          _new = action->action_FuncSection[PRE_ACTION](me, me);
        }
        if (!action->skip_children_FuncSection) {
          doggy_FuncSection_funcs(me) = Traverse_copy_List_doggy_Func (doggy_FuncSection_funcs(me), action);
        }
        if (action->action_FuncSection[POST_ACTION] != NULL) {
          _new = action->action_FuncSection[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_RuleSection_kind:
        if (action->action_RuleSection[PRE_ACTION] != NULL) {
          _new = action->action_RuleSection[PRE_ACTION](me, me);
        }
        if (!action->skip_children_RuleSection) {
          doggy_RuleSection_rules(me) = Traverse_copy_List_doggy_Rule (doggy_RuleSection_rules(me), action);
        }
        if (action->action_RuleSection[POST_ACTION] != NULL) {
          _new = action->action_RuleSection[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Section[POST_ACTION] != NULL) {
    me = action->action_Section[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Rule Traverse_copy_doggy_Rule (doggy_Rule me, copy_doggy_TraverseTable action)
{ doggy_Rule _new = me, _old = me;
  if (action->action_Rule[PRE_ACTION] != NULL) {
    _new = action->action_Rule[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Rule)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Rule) {
    doggy_Rule_lhs(me) = Traverse_copy_doggy_Lhs (doggy_Rule_lhs(me), action);
    doggy_Rule_rhs(me) = Traverse_copy_doggy_Rhs (doggy_Rule_rhs(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_Rule_scope(me) = NULL;
      doggy_Rule_old_scope(me) = NULL;
      doggy_Rule_rules_id(me) = NULL;
      doggy_Rule_supported(me) = TRUE;
      doggy_Rule_rhs_supported(me) = TRUE;
    }
  }
  if (action->action_Rule[POST_ACTION] != NULL) {
    me = action->action_Rule[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Lhs Traverse_copy_doggy_Lhs (doggy_Lhs me, copy_doggy_TraverseTable action)
{ doggy_Lhs _new = me, _old = me;
  if (action->action_Lhs[PRE_ACTION] != NULL) {
    _new = action->action_Lhs[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Lhs)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Lhs_tag(me)) {
      case doggy_LabeledLhs_kind:
        if (action->action_LabeledLhs[PRE_ACTION] != NULL) {
          _new = action->action_LabeledLhs[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Lhs) {
          doggy_Lhs_pat(me) = Traverse_copy_doggy_Pattern (doggy_Lhs_pat(me), action);
        }
        if (action->action_LabeledLhs[POST_ACTION] != NULL) {
          _new = action->action_LabeledLhs[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_UnLabeledLhs_kind:
        if (action->action_UnLabeledLhs[PRE_ACTION] != NULL) {
          _new = action->action_UnLabeledLhs[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Lhs) {
          doggy_Lhs_pat(me) = Traverse_copy_doggy_Pattern (doggy_Lhs_pat(me), action);
        }
        if (action->action_UnLabeledLhs[POST_ACTION] != NULL) {
          _new = action->action_UnLabeledLhs[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Lhs[POST_ACTION] != NULL) {
    me = action->action_Lhs[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Func Traverse_copy_doggy_Func (doggy_Func me, copy_doggy_TraverseTable action)
{ doggy_Func _new = me, _old = me;
  if (action->action_Func[PRE_ACTION] != NULL) {
    _new = action->action_Func[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Func)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Func) {
    doggy_Func_type(me) = Traverse_copy_doggy_Type (doggy_Func_type(me), action);
    doggy_Func_rules(me) = Traverse_copy_List_doggy_FuncRule (doggy_Func_rules(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_Func_scope(me) = NULL;
      doggy_Func_old_scope(me) = NULL;
      doggy_Func_args(me) = NULL;
    }
  }
  if (action->action_Func[POST_ACTION] != NULL) {
    me = action->action_Func[POST_ACTION](me, _old);
  }
  return me;
}

doggy_FuncRule Traverse_copy_doggy_FuncRule (doggy_FuncRule me, copy_doggy_TraverseTable action)
{ doggy_FuncRule _new = me, _old = me;
  if (action->action_FuncRule[PRE_ACTION] != NULL) {
    _new = action->action_FuncRule[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_FuncRule)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_FuncRule) {
    doggy_FuncRule_args(me) = Traverse_copy_List_doggy_Argument (doggy_FuncRule_args(me), action);
    doggy_FuncRule_rhs(me) = Traverse_copy_doggy_Rhs (doggy_FuncRule_rhs(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_FuncRule_scope(me) = NULL;
      doggy_FuncRule_old_scope(me) = NULL;
      doggy_FuncRule_supported(me) = TRUE;
    }
  }
  if (action->action_FuncRule[POST_ACTION] != NULL) {
    me = action->action_FuncRule[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Argument Traverse_copy_doggy_Argument (doggy_Argument me, copy_doggy_TraverseTable action)
{ doggy_Argument _new = me, _old = me;
  if (action->action_Argument[PRE_ACTION] != NULL) {
    _new = action->action_Argument[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Argument)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Argument_tag(me)) {
      case doggy_TypedArg_kind:
        if (action->action_TypedArg[PRE_ACTION] != NULL) {
          _new = action->action_TypedArg[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Argument_scope(me) = NULL;
            doggy_Argument_old_scope(me) = NULL;
          }
        if (!action->skip_children_TypedArg) {
          doggy_TypedArg_type(me) = Traverse_copy_doggy_Type (doggy_TypedArg_type(me), action);
        }
        if (!action->skip_children_Argument) {
          doggy_Argument_pat(me) = Traverse_copy_doggy_ArgPat (doggy_Argument_pat(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Argument_value(me) = NoValue ();
          }
        if (action->action_TypedArg[POST_ACTION] != NULL) {
          _new = action->action_TypedArg[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_UnTypedArg_kind:
        if (action->action_UnTypedArg[PRE_ACTION] != NULL) {
          _new = action->action_UnTypedArg[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Argument_scope(me) = NULL;
            doggy_Argument_old_scope(me) = NULL;
          }
        if (!action->skip_children_Argument) {
          doggy_Argument_pat(me) = Traverse_copy_doggy_ArgPat (doggy_Argument_pat(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Argument_value(me) = NoValue ();
          }
        if (action->action_UnTypedArg[POST_ACTION] != NULL) {
          _new = action->action_UnTypedArg[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Argument[POST_ACTION] != NULL) {
    me = action->action_Argument[POST_ACTION](me, _old);
  }
  return me;
}

doggy_ArgPat Traverse_copy_doggy_ArgPat (doggy_ArgPat me, copy_doggy_TraverseTable action)
{ doggy_ArgPat _new = me, _old = me;
  if (action->action_ArgPat[PRE_ACTION] != NULL) {
    _new = action->action_ArgPat[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_ArgPat)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_ArgPat_tag(me)) {
      case doggy_PatArg_kind:
        if (action->action_PatArg[PRE_ACTION] != NULL) {
          _new = action->action_PatArg[PRE_ACTION](me, me);
        }
        if (!action->skip_children_PatArg) {
          doggy_PatArg_pat(me) = Traverse_copy_doggy_Pattern (doggy_PatArg_pat(me), action);
        }
        if (action->action_PatArg[POST_ACTION] != NULL) {
          _new = action->action_PatArg[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_SetArg_kind:
        if (action->action_SetArg[PRE_ACTION] != NULL) {
          _new = action->action_SetArg[PRE_ACTION](me, me);
        }
        if (!action->skip_children_SetArg) {
          doggy_SetArg_set(me) = Traverse_copy_doggy_Applied_operation (doggy_SetArg_set(me), action);
        }
        if (action->action_SetArg[POST_ACTION] != NULL) {
          _new = action->action_SetArg[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_ArgPat[POST_ACTION] != NULL) {
    me = action->action_ArgPat[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Pattern Traverse_copy_doggy_Pattern (doggy_Pattern me, copy_doggy_TraverseTable action)
{ doggy_Pattern _new = me, _old = me;
  if (action->action_Pattern[PRE_ACTION] != NULL) {
    _new = action->action_Pattern[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Pattern)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Pattern_tag(me)) {
      case doggy_TypedPattern_kind:
        if (action->action_TypedPattern[PRE_ACTION] != NULL) {
          _new = action->action_TypedPattern[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_scope(me) = NULL;
            doggy_Pattern_old_scope(me) = NULL;
          }
        if (!action->skip_children_TypedPattern) {
          doggy_TypedPattern_btype(me) = Traverse_copy_doggy_Type (doggy_TypedPattern_btype(me), action);
          doggy_TypedPattern_pat(me) = Traverse_copy_doggy_Pattern (doggy_TypedPattern_pat(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_type(me) = NULL;
            doggy_Pattern__swap(me) = 0;
            doggy_Pattern_swap(me) = 0;
            doggy_Pattern__types(me) = 0;
            doggy_Pattern_types(me) = 0;
            doggy_Pattern_value(me) = NoValue ();
          }
        if (action->action_TypedPattern[POST_ACTION] != NULL) {
          _new = action->action_TypedPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_ConsPattern_kind:
        if (action->action_ConsPattern[PRE_ACTION] != NULL) {
          _new = action->action_ConsPattern[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_scope(me) = NULL;
            doggy_Pattern_old_scope(me) = NULL;
          }
        if (!action->skip_children_ConsPattern) {
          doggy_ConsPattern_lhs(me) = Traverse_copy_doggy_Pattern (doggy_ConsPattern_lhs(me), action);
          doggy_ConsPattern_rhs(me) = Traverse_copy_doggy_Pattern (doggy_ConsPattern_rhs(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_type(me) = NULL;
            doggy_Pattern__swap(me) = 0;
            doggy_Pattern_swap(me) = 0;
            doggy_Pattern__types(me) = 0;
            doggy_Pattern_types(me) = 0;
            doggy_Pattern_value(me) = NoValue ();
          }
        if (action->action_ConsPattern[POST_ACTION] != NULL) {
          _new = action->action_ConsPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_DefPattern_kind:
        if (action->action_DefPattern[PRE_ACTION] != NULL) {
          _new = action->action_DefPattern[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_scope(me) = NULL;
            doggy_Pattern_old_scope(me) = NULL;
          }
        if (!action->skip_children_DefPattern) {
          doggy_DefPattern_ids(me) = Traverse_copy_List_doggy_Pattern (doggy_DefPattern_ids(me), action);
          doggy_DefPattern_arg(me) = Traverse_copy_doggy_Pattern (doggy_DefPattern_arg(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            init_ident_patterns (DefPattern_ids (me), me);
            doggy_DefPattern_use_cnt(me) = 0;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_type(me) = NULL;
            doggy_Pattern__swap(me) = 0;
            doggy_Pattern_swap(me) = 0;
            doggy_Pattern__types(me) = 0;
            doggy_Pattern_types(me) = 0;
            doggy_Pattern_value(me) = NoValue ();
          }
        if (action->action_DefPattern[POST_ACTION] != NULL) {
          _new = action->action_DefPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_IdentPattern_kind:
        if (action->action_IdentPattern[PRE_ACTION] != NULL) {
          _new = action->action_IdentPattern[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_scope(me) = NULL;
            doggy_Pattern_old_scope(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_IdentPattern_def(me) = NULL;
            doggy_IdentPattern_use_cnt(me) = 0;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_type(me) = NULL;
            doggy_Pattern__swap(me) = 0;
            doggy_Pattern_swap(me) = 0;
            doggy_Pattern__types(me) = 0;
            doggy_Pattern_types(me) = 0;
            doggy_Pattern_value(me) = NoValue ();
          }
        if (action->action_IdentPattern[POST_ACTION] != NULL) {
          _new = action->action_IdentPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_OpPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          _new = action->action_BasicPattern[PRE_ACTION](me, me);
        }
        if (action->action_OpPattern[PRE_ACTION] != NULL) {
          _new = action->action_OpPattern[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_scope(me) = NULL;
            doggy_Pattern_old_scope(me) = NULL;
          }
        if (!action->skip_children_OpPattern) {
          doggy_OpPattern_op(me) = Traverse_copy_doggy_Applied_operation (doggy_OpPattern_op(me), action);
          doggy_OpPattern_args(me) = Traverse_copy_List_doggy_Pattern (doggy_OpPattern_args(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_type(me) = NULL;
            doggy_Pattern__swap(me) = 0;
            doggy_Pattern_swap(me) = 0;
            doggy_Pattern__types(me) = 0;
            doggy_Pattern_types(me) = 0;
            doggy_Pattern_value(me) = NoValue ();
          }
        if (action->action_OpPattern[POST_ACTION] != NULL) {
          _new = action->action_OpPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          _new = action->action_BasicPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_ConstPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          _new = action->action_BasicPattern[PRE_ACTION](me, me);
        }
        if (action->action_ConstPattern[PRE_ACTION] != NULL) {
          _new = action->action_ConstPattern[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_scope(me) = NULL;
            doggy_Pattern_old_scope(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_type(me) = NULL;
            doggy_Pattern__swap(me) = 0;
            doggy_Pattern_swap(me) = 0;
            doggy_Pattern__types(me) = 0;
            doggy_Pattern_types(me) = 0;
            doggy_Pattern_value(me) = NoValue ();
          }
        if (action->action_ConstPattern[POST_ACTION] != NULL) {
          _new = action->action_ConstPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          _new = action->action_BasicPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_NullPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          _new = action->action_BasicPattern[PRE_ACTION](me, me);
        }
        if (action->action_NullPattern[PRE_ACTION] != NULL) {
          _new = action->action_NullPattern[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_scope(me) = NULL;
            doggy_Pattern_old_scope(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_type(me) = NULL;
            doggy_Pattern__swap(me) = 0;
            doggy_Pattern_swap(me) = 0;
            doggy_Pattern__types(me) = 0;
            doggy_Pattern_types(me) = 0;
            doggy_Pattern_value(me) = NoValue ();
          }
        if (action->action_NullPattern[POST_ACTION] != NULL) {
          _new = action->action_NullPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          _new = action->action_BasicPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_DontCarePattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          _new = action->action_BasicPattern[PRE_ACTION](me, me);
        }
        if (action->action_DontCarePattern[PRE_ACTION] != NULL) {
          _new = action->action_DontCarePattern[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_scope(me) = NULL;
            doggy_Pattern_old_scope(me) = NULL;
          }
        if (!action->skip_children_DontCarePattern) {
          doggy_DontCarePattern_expr(me) = Traverse_copy_doggy_Expr (doggy_DontCarePattern_expr(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Pattern_type(me) = NULL;
            doggy_Pattern__swap(me) = 0;
            doggy_Pattern_swap(me) = 0;
            doggy_Pattern__types(me) = 0;
            doggy_Pattern_types(me) = 0;
            doggy_Pattern_value(me) = NoValue ();
          }
        if (action->action_DontCarePattern[POST_ACTION] != NULL) {
          _new = action->action_DontCarePattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          _new = action->action_BasicPattern[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Pattern[POST_ACTION] != NULL) {
    me = action->action_Pattern[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Rhs Traverse_copy_doggy_Rhs (doggy_Rhs me, copy_doggy_TraverseTable action)
{ doggy_Rhs _new = me, _old = me;
  if (action->action_Rhs[PRE_ACTION] != NULL) {
    _new = action->action_Rhs[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Rhs)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Rhs_tag(me)) {
      case doggy_PlainRhs_kind:
        if (action->action_PlainRhs[PRE_ACTION] != NULL) {
          _new = action->action_PlainRhs[PRE_ACTION](me, me);
        }
        if (!action->skip_children_PlainRhs) {
          doggy_PlainRhs_guards(me) = Traverse_copy_List_doggy_Guard (doggy_PlainRhs_guards(me), action);
        }
        if (action->action_PlainRhs[POST_ACTION] != NULL) {
          _new = action->action_PlainRhs[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_BlockRhs_kind:
        if (action->action_BlockRhs[PRE_ACTION] != NULL) {
          _new = action->action_BlockRhs[PRE_ACTION](me, me);
        }
        if (!action->skip_children_BlockRhs) {
          doggy_BlockRhs_rhs(me) = Traverse_copy_doggy_Rhs (doggy_BlockRhs_rhs(me), action);
          doggy_BlockRhs_where(me) = Traverse_copy_doggy_Wherepart (doggy_BlockRhs_where(me), action);
        }
        if (action->action_BlockRhs[POST_ACTION] != NULL) {
          _new = action->action_BlockRhs[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Rhs[POST_ACTION] != NULL) {
    me = action->action_Rhs[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Guard Traverse_copy_doggy_Guard (doggy_Guard me, copy_doggy_TraverseTable action)
{ doggy_Guard _new = me, _old = me;
  if (action->action_Guard[PRE_ACTION] != NULL) {
    _new = action->action_Guard[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Guard)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Guard_tag(me)) {
      case doggy_RhsGuard_kind:
        if (action->action_RhsGuard[PRE_ACTION] != NULL) {
          _new = action->action_RhsGuard[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Guard) {
          doggy_Guard_conds(me) = Traverse_copy_doggy_Expr (doggy_Guard_conds(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Guard_scope(me) = NULL;
            doggy_Guard_old_scope(me) = NULL;
          }
        if (!action->skip_children_RhsGuard) {
          doggy_RhsGuard_rhs(me) = Traverse_copy_doggy_Rhs (doggy_RhsGuard_rhs(me), action);
        }
        if (!action->skip_children_Guard) {
          doggy_Guard_where(me) = Traverse_copy_doggy_Wherepart (doggy_Guard_where(me), action);
        }
        if (action->action_RhsGuard[POST_ACTION] != NULL) {
          _new = action->action_RhsGuard[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_ExprGuard_kind:
        if (action->action_ExprGuard[PRE_ACTION] != NULL) {
          _new = action->action_ExprGuard[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Guard) {
          doggy_Guard_conds(me) = Traverse_copy_doggy_Expr (doggy_Guard_conds(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Guard_scope(me) = NULL;
            doggy_Guard_old_scope(me) = NULL;
          }
        if (!action->skip_children_ExprGuard) {
          doggy_ExprGuard_exprs(me) = Traverse_copy_doggy_ExprSeq (doggy_ExprGuard_exprs(me), action);
        }
        if (!action->skip_children_Guard) {
          doggy_Guard_where(me) = Traverse_copy_doggy_Wherepart (doggy_Guard_where(me), action);
        }
        if (action->action_ExprGuard[POST_ACTION] != NULL) {
          _new = action->action_ExprGuard[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Guard[POST_ACTION] != NULL) {
    me = action->action_Guard[POST_ACTION](me, _old);
  }
  return me;
}

doggy_ExprSeq Traverse_copy_doggy_ExprSeq (doggy_ExprSeq me, copy_doggy_TraverseTable action)
{ doggy_ExprSeq _new = me, _old = me;
  if (action->action_ExprSeq[PRE_ACTION] != NULL) {
    _new = action->action_ExprSeq[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_ExprSeq)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_ExprSeq_tag(me)) {
      case doggy_OneExpr_kind:
        if (action->action_OneExpr[PRE_ACTION] != NULL) {
          _new = action->action_OneExpr[PRE_ACTION](me, me);
        }
        if (!action->skip_children_OneExpr) {
          doggy_OneExpr_expr(me) = Traverse_copy_doggy_Expr (doggy_OneExpr_expr(me), action);
        }
        if (action->action_OneExpr[POST_ACTION] != NULL) {
          _new = action->action_OneExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_MoreExprs_kind:
        if (action->action_MoreExprs[PRE_ACTION] != NULL) {
          _new = action->action_MoreExprs[PRE_ACTION](me, me);
        }
        if (!action->skip_children_MoreExprs) {
          doggy_MoreExprs_exprs(me) = Traverse_copy_List_doggy_Expr (doggy_MoreExprs_exprs(me), action);
        }
        if (action->action_MoreExprs[POST_ACTION] != NULL) {
          _new = action->action_MoreExprs[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_ExprSeq[POST_ACTION] != NULL) {
    me = action->action_ExprSeq[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Wherepart Traverse_copy_doggy_Wherepart (doggy_Wherepart me, copy_doggy_TraverseTable action)
{ doggy_Wherepart _new = me, _old = me;
  if (action->action_Wherepart[PRE_ACTION] != NULL) {
    _new = action->action_Wherepart[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Wherepart)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Wherepart) {
    doggy_Wherepart_defs(me) = Traverse_copy_List_doggy_Definition (doggy_Wherepart_defs(me), action);
  }
  }
  if (action->action_Wherepart[POST_ACTION] != NULL) {
    me = action->action_Wherepart[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Applied_operation Traverse_copy_doggy_Applied_operation (doggy_Applied_operation me, copy_doggy_TraverseTable action)
{ doggy_Applied_operation _new = me, _old = me;
  if (action->action_Applied_operation[PRE_ACTION] != NULL) {
    _new = action->action_Applied_operation[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Applied_operation)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Applied_operation_tag(me)) {
      case doggy_AnyOp_kind:
        if (action->action_AnyOp[PRE_ACTION] != NULL) {
          _new = action->action_AnyOp[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Applied_operation_scope(me) = NULL;
            doggy_Applied_operation_old_scope(me) = NULL;
          }
        if (action->action_AnyOp[POST_ACTION] != NULL) {
          _new = action->action_AnyOp[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_AppliedOp_kind:
        if (action->action_AppliedOp[PRE_ACTION] != NULL) {
          _new = action->action_AppliedOp[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Applied_operation_scope(me) = NULL;
            doggy_Applied_operation_old_scope(me) = NULL;
          }
        if (!action->skip_children_AppliedOp) {
          doggy_AppliedOp_op(me) = Traverse_copy_doggy_Applied_formal (doggy_AppliedOp_op(me), action);
        }
        if (action->action_AppliedOp[POST_ACTION] != NULL) {
          _new = action->action_AppliedOp[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_OpSet_kind:
        if (action->action_OpSet[PRE_ACTION] != NULL) {
          _new = action->action_OpSet[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Applied_operation_scope(me) = NULL;
            doggy_Applied_operation_old_scope(me) = NULL;
          }
        if (!action->skip_children_OpSet) {
          doggy_OpSet_ops(me) = Traverse_copy_List_doggy_Applied_formal (doggy_OpSet_ops(me), action);
        }
        if (action->action_OpSet[POST_ACTION] != NULL) {
          _new = action->action_OpSet[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Applied_operation[POST_ACTION] != NULL) {
    me = action->action_Applied_operation[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Applied_formal Traverse_copy_doggy_Applied_formal (doggy_Applied_formal me, copy_doggy_TraverseTable action)
{ doggy_Applied_formal _new = me, _old = me;
  if (action->action_Applied_formal[PRE_ACTION] != NULL) {
    _new = action->action_Applied_formal[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Applied_formal)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_Applied_formal_scope(me) = NULL;
      doggy_Applied_formal_old_scope(me) = NULL;
      doggy_Applied_formal_ap_bind(me) = NULL;
      doggy_Applied_formal_ap(me) = NULL;
    }
  }
  if (action->action_Applied_formal[POST_ACTION] != NULL) {
    me = action->action_Applied_formal[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Expr Traverse_copy_doggy_Expr (doggy_Expr me, copy_doggy_TraverseTable action)
{ doggy_Expr _new = me, _old = me;
  if (action->action_Expr[PRE_ACTION] != NULL) {
    _new = action->action_Expr[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Expr)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Expr_tag(me)) {
      case doggy_BinExpr_kind:
        if (action->action_BinExpr[PRE_ACTION] != NULL) {
          _new = action->action_BinExpr[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Expr_scope(me) = NULL;
            doggy_Expr_old_scope(me) = NULL;
            doggy_Expr_warned(me) = FALSE;
          }
        if (!action->skip_children_BinExpr) {
          doggy_BinExpr_args(me) = Traverse_copy_List_doggy_Expr (doggy_BinExpr_args(me), action);
          doggy_BinExpr_ops(me) = Traverse_copy_List_doggy_Operator (doggy_BinExpr_ops(me), action);
        }
        if (action->action_BinExpr[POST_ACTION] != NULL) {
          _new = action->action_BinExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_ConsExpr_kind:
        if (action->action_ConsExpr[PRE_ACTION] != NULL) {
          _new = action->action_ConsExpr[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Expr_scope(me) = NULL;
            doggy_Expr_old_scope(me) = NULL;
            doggy_Expr_warned(me) = FALSE;
          }
        if (!action->skip_children_ConsExpr) {
          doggy_ConsExpr_lhs(me) = Traverse_copy_doggy_Expr (doggy_ConsExpr_lhs(me), action);
          doggy_ConsExpr_rhs(me) = Traverse_copy_doggy_Expr (doggy_ConsExpr_rhs(me), action);
        }
        if (action->action_ConsExpr[POST_ACTION] != NULL) {
          _new = action->action_ConsExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_IdentExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_IdentExpr[PRE_ACTION] != NULL) {
          _new = action->action_IdentExpr[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Expr_scope(me) = NULL;
            doggy_Expr_old_scope(me) = NULL;
            doggy_Expr_warned(me) = FALSE;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_IdentExpr_operator_bind(me) = NULL;
            doggy_IdentExpr_operator(me) = NULL;
            doggy_IdentExpr_pattern_bind(me) = NULL;
            doggy_IdentExpr_pattern(me) = NULL;
            doggy_IdentExpr_ext_bind(me) = NULL;
            doggy_IdentExpr_ext(me) = NULL;
            doggy_IdentExpr_def_bind(me) = NULL;
            doggy_IdentExpr_def(me) = NULL;
            doggy_IdentExpr_arg_bind(me) = NULL;
            doggy_IdentExpr_arg(me) = NULL;
            doggy_IdentExpr_use_cnt(me) = 0;
          }
        if (action->action_IdentExpr[POST_ACTION] != NULL) {
          _new = action->action_IdentExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_IfExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_IfExpr[PRE_ACTION] != NULL) {
          _new = action->action_IfExpr[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Expr_scope(me) = NULL;
            doggy_Expr_old_scope(me) = NULL;
            doggy_Expr_warned(me) = FALSE;
          }
        if (!action->skip_children_IfExpr) {
          doggy_IfExpr_cond(me) = Traverse_copy_doggy_Expr (doggy_IfExpr_cond(me), action);
          doggy_IfExpr_thn(me) = Traverse_copy_doggy_Expr (doggy_IfExpr_thn(me), action);
          doggy_IfExpr_conds(me) = Traverse_copy_List_doggy_Expr (doggy_IfExpr_conds(me), action);
          doggy_IfExpr_thens(me) = Traverse_copy_List_doggy_Expr (doggy_IfExpr_thens(me), action);
          doggy_IfExpr_els(me) = Traverse_copy_doggy_Expr (doggy_IfExpr_els(me), action);
        }
        if (action->action_IfExpr[POST_ACTION] != NULL) {
          _new = action->action_IfExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_ConstExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_ConstExpr[PRE_ACTION] != NULL) {
          _new = action->action_ConstExpr[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Expr_scope(me) = NULL;
            doggy_Expr_old_scope(me) = NULL;
            doggy_Expr_warned(me) = FALSE;
          }
        if (!action->skip_children_ConstExpr) {
          doggy_ConstExpr_cnst(me) = Traverse_copy_doggy_Constant (doggy_ConstExpr_cnst(me), action);
        }
        if (action->action_ConstExpr[POST_ACTION] != NULL) {
          _new = action->action_ConstExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_Operation_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_Operation[PRE_ACTION] != NULL) {
          _new = action->action_Operation[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Expr_scope(me) = NULL;
            doggy_Expr_old_scope(me) = NULL;
            doggy_Expr_warned(me) = FALSE;
          }
        if (!action->skip_children_Operation) {
          doggy_Operation_args(me) = Traverse_copy_List_doggy_Expr (doggy_Operation_args(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Operation_operator_bind(me) = NULL;
            doggy_Operation_operator(me) = NULL;
            doggy_Operation_defi_bind(me) = NULL;
            doggy_Operation_defi(me) = NULL;
            doggy_Operation_ext_bind(me) = NULL;
            doggy_Operation_ext(me) = NULL;
            doggy_Operation_func_bind(me) = NULL;
            doggy_Operation_func(me) = NULL;
          }
        if (action->action_Operation[POST_ACTION] != NULL) {
          _new = action->action_Operation[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_ParExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_ParExpr[PRE_ACTION] != NULL) {
          _new = action->action_ParExpr[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Expr_scope(me) = NULL;
            doggy_Expr_old_scope(me) = NULL;
            doggy_Expr_warned(me) = FALSE;
          }
        if (!action->skip_children_ParExpr) {
          doggy_ParExpr_expr(me) = Traverse_copy_doggy_Expr (doggy_ParExpr_expr(me), action);
        }
        if (action->action_ParExpr[POST_ACTION] != NULL) {
          _new = action->action_ParExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_MonExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_MonExpr[PRE_ACTION] != NULL) {
          _new = action->action_MonExpr[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Expr_scope(me) = NULL;
            doggy_Expr_old_scope(me) = NULL;
            doggy_Expr_warned(me) = FALSE;
          }
        if (!action->skip_children_MonExpr) {
          doggy_MonExpr_op(me) = Traverse_copy_doggy_MonOp (doggy_MonExpr_op(me), action);
          doggy_MonExpr_arg(me) = Traverse_copy_doggy_Expr (doggy_MonExpr_arg(me), action);
        }
        if (action->action_MonExpr[POST_ACTION] != NULL) {
          _new = action->action_MonExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Expr[POST_ACTION] != NULL) {
    me = action->action_Expr[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Constant Traverse_copy_doggy_Constant (doggy_Constant me, copy_doggy_TraverseTable action)
{ doggy_Constant _new = me, _old = me;
  if (action->action_Constant[PRE_ACTION] != NULL) {
    _new = action->action_Constant[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Constant)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Constant_tag(me)) {
      case doggy_IntConst_kind:
        if (action->action_IntConst[PRE_ACTION] != NULL) {
          _new = action->action_IntConst[PRE_ACTION](me, me);
        }
        if (action->action_IntConst[POST_ACTION] != NULL) {
          _new = action->action_IntConst[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_BoolConst_kind:
        if (action->action_BoolConst[PRE_ACTION] != NULL) {
          _new = action->action_BoolConst[PRE_ACTION](me, me);
        }
        if (action->action_BoolConst[POST_ACTION] != NULL) {
          _new = action->action_BoolConst[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_StringConst_kind:
        if (action->action_StringConst[PRE_ACTION] != NULL) {
          _new = action->action_StringConst[PRE_ACTION](me, me);
        }
        if (action->action_StringConst[POST_ACTION] != NULL) {
          _new = action->action_StringConst[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_NullConst_kind:
        if (action->action_NullConst[PRE_ACTION] != NULL) {
          _new = action->action_NullConst[PRE_ACTION](me, me);
        }
        if (action->action_NullConst[POST_ACTION] != NULL) {
          _new = action->action_NullConst[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Constant[POST_ACTION] != NULL) {
    me = action->action_Constant[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Definition Traverse_copy_doggy_Definition (doggy_Definition me, copy_doggy_TraverseTable action)
{ doggy_Definition _new = me, _old = me;
  if (action->action_Definition[PRE_ACTION] != NULL) {
    _new = action->action_Definition[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Definition)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Definition) {
    doggy_Definition_type(me) = Traverse_copy_doggy_Type (doggy_Definition_type(me), action);
    doggy_Definition_expr(me) = Traverse_copy_doggy_Expr (doggy_Definition_expr(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_Definition_scope(me) = NULL;
      doggy_Definition_old_scope(me) = NULL;
      doggy_Definition_value(me) = NoValue ();
      doggy_Definition_order(me) = - 1;
      doggy_Definition_use_cnt(me) = 0;
    }
  }
  if (action->action_Definition[POST_ACTION] != NULL) {
    me = action->action_Definition[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Type Traverse_copy_doggy_Type (doggy_Type me, copy_doggy_TraverseTable action)
{ doggy_Type _new = me, _old = me;
  if (action->action_Type[PRE_ACTION] != NULL) {
    _new = action->action_Type[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Type)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Type_tag(me)) {
      case doggy_EdgeType_kind:
        if (action->action_EdgeType[PRE_ACTION] != NULL) {
          _new = action->action_EdgeType[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Type_scope(me) = NULL;
            doggy_Type_old_scope(me) = NULL;
          }
        if (!action->skip_children_EdgeType) {
          doggy_EdgeType_types(me) = Traverse_copy_List_doggy_Type (doggy_EdgeType_types(me), action);
        }
        if (action->action_EdgeType[POST_ACTION] != NULL) {
          _new = action->action_EdgeType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_TupleType_kind:
        if (action->action_TupleType[PRE_ACTION] != NULL) {
          _new = action->action_TupleType[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Type_scope(me) = NULL;
            doggy_Type_old_scope(me) = NULL;
          }
        if (!action->skip_children_TupleType) {
          doggy_TupleType_types(me) = Traverse_copy_List_doggy_Type (doggy_TupleType_types(me), action);
        }
        if (action->action_TupleType[POST_ACTION] != NULL) {
          _new = action->action_TupleType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_IdentType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          _new = action->action_BasicType[PRE_ACTION](me, me);
        }
        if (action->action_IdentType[PRE_ACTION] != NULL) {
          _new = action->action_IdentType[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Type_scope(me) = NULL;
            doggy_Type_old_scope(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_IdentType_type_bind(me) = NULL;
            doggy_IdentType_type(me) = NULL;
          }
        if (action->action_IdentType[POST_ACTION] != NULL) {
          _new = action->action_IdentType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          _new = action->action_BasicType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_OprType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          _new = action->action_BasicType[PRE_ACTION](me, me);
        }
        if (action->action_OprType[PRE_ACTION] != NULL) {
          _new = action->action_OprType[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Type_scope(me) = NULL;
            doggy_Type_old_scope(me) = NULL;
          }
        if (!action->skip_children_OprType) {
          doggy_OprType_args(me) = Traverse_copy_List_doggy_Type (doggy_OprType_args(me), action);
        }
        if (action->action_OprType[POST_ACTION] != NULL) {
          _new = action->action_OprType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          _new = action->action_BasicType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_PointerType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          _new = action->action_BasicType[PRE_ACTION](me, me);
        }
        if (action->action_PointerType[PRE_ACTION] != NULL) {
          _new = action->action_PointerType[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Type_scope(me) = NULL;
            doggy_Type_old_scope(me) = NULL;
          }
        if (!action->skip_children_PointerType) {
          doggy_PointerType_base(me) = Traverse_copy_doggy_Type (doggy_PointerType_base(me), action);
        }
        if (action->action_PointerType[POST_ACTION] != NULL) {
          _new = action->action_PointerType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          _new = action->action_BasicType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_RangeType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          _new = action->action_BasicType[PRE_ACTION](me, me);
        }
        if (action->action_RangeType[PRE_ACTION] != NULL) {
          _new = action->action_RangeType[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Type_scope(me) = NULL;
            doggy_Type_old_scope(me) = NULL;
          }
        if (!action->skip_children_RangeType) {
          doggy_RangeType_lo(me) = Traverse_copy_doggy_Num (doggy_RangeType_lo(me), action);
          doggy_RangeType_hi(me) = Traverse_copy_doggy_Num (doggy_RangeType_hi(me), action);
          doggy_RangeType_step(me) = Traverse_copy_doggy_Num (doggy_RangeType_step(me), action);
        }
        if (action->action_RangeType[POST_ACTION] != NULL) {
          _new = action->action_RangeType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          _new = action->action_BasicType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_FRangeType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          _new = action->action_BasicType[PRE_ACTION](me, me);
        }
        if (action->action_FRangeType[PRE_ACTION] != NULL) {
          _new = action->action_FRangeType[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            doggy_Type_scope(me) = NULL;
            doggy_Type_old_scope(me) = NULL;
          }
        if (action->action_FRangeType[POST_ACTION] != NULL) {
          _new = action->action_FRangeType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          _new = action->action_BasicType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Type[POST_ACTION] != NULL) {
    me = action->action_Type[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Num Traverse_copy_doggy_Num (doggy_Num me, copy_doggy_TraverseTable action)
{ doggy_Num _new = me, _old = me;
  if (action->action_Num[PRE_ACTION] != NULL) {
    _new = action->action_Num[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Num)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      num_negate (me);
    }
  }
  if (action->action_Num[POST_ACTION] != NULL) {
    me = action->action_Num[POST_ACTION](me, _old);
  }
  return me;
}

doggy_IdInt Traverse_copy_doggy_IdInt (doggy_IdInt me, copy_doggy_TraverseTable action)
{ doggy_IdInt _new = me, _old = me;
  if (action->action_IdInt[PRE_ACTION] != NULL) {
    _new = action->action_IdInt[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_IdInt)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_IdInt_tag(me)) {
      case doggy_IsId_kind:
        if (action->action_IsId[PRE_ACTION] != NULL) {
          _new = action->action_IsId[PRE_ACTION](me, me);
        }
        if (action->action_IsId[POST_ACTION] != NULL) {
          _new = action->action_IsId[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_IsInt_kind:
        if (action->action_IsInt[PRE_ACTION] != NULL) {
          _new = action->action_IsInt[PRE_ACTION](me, me);
        }
        if (action->action_IsInt[POST_ACTION] != NULL) {
          _new = action->action_IsInt[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_IdInt[POST_ACTION] != NULL) {
    me = action->action_IdInt[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Path Traverse_copy_doggy_Path (doggy_Path me, copy_doggy_TraverseTable action)
{ doggy_Path _new = me, _old = me;
  if (action->action_Path[PRE_ACTION] != NULL) {
    _new = action->action_Path[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Path)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Path) {
    doggy_Path_type(me) = Traverse_copy_doggy_Type (doggy_Path_type(me), action);
    doggy_Path_next(me) = Traverse_copy_doggy_Path (doggy_Path_next(me), action);
  }
  }
  if (action->action_Path[POST_ACTION] != NULL) {
    me = action->action_Path[POST_ACTION](me, _old);
  }
  return me;
}

doggy_ActualOp Traverse_copy_doggy_ActualOp (doggy_ActualOp me, copy_doggy_TraverseTable action)
{ doggy_ActualOp _new = me, _old = me;
  if (action->action_ActualOp[PRE_ACTION] != NULL) {
    _new = action->action_ActualOp[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_ActualOp)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_ActualOp) {
    doggy_ActualOp_formals(me) = Traverse_copy_List_doggy_Operation_def (doggy_ActualOp_formals(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_ActualOp_overloaded(me) = FALSE;
      doggy_ActualOp_src(me) = FALSE;
      doggy_ActualOp_tgt(me) = FALSE;
    }
  }
  if (action->action_ActualOp[POST_ACTION] != NULL) {
    me = action->action_ActualOp[POST_ACTION](me, _old);
  }
  return me;
}

doggy_TypePair Traverse_copy_doggy_TypePair (doggy_TypePair me, copy_doggy_TraverseTable action)
{ doggy_TypePair _new = me, _old = me;
  if (action->action_TypePair[PRE_ACTION] != NULL) {
    _new = action->action_TypePair[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_TypePair)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_TypePair) {
    doggy_TypePair_t1(me) = Traverse_copy_doggy_Type (doggy_TypePair_t1(me), action);
    doggy_TypePair_t2(me) = Traverse_copy_doggy_Type (doggy_TypePair_t2(me), action);
  }
  }
  if (action->action_TypePair[POST_ACTION] != NULL) {
    me = action->action_TypePair[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Opat Traverse_copy_doggy_Opat (doggy_Opat me, copy_doggy_TraverseTable action)
{ doggy_Opat _new = me, _old = me;
  if (action->action_Opat[PRE_ACTION] != NULL) {
    _new = action->action_Opat[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Opat)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Opat) {
    doggy_Opat_args(me) = Traverse_copy_List_doggy_Type (doggy_Opat_args(me), action);
    doggy_Opat_result(me) = Traverse_copy_doggy_Type (doggy_Opat_result(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_Opat_num(me) = 0;
    }
  }
  if (action->action_Opat[POST_ACTION] != NULL) {
    me = action->action_Opat[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Format Traverse_copy_doggy_Format (doggy_Format me, copy_doggy_TraverseTable action)
{ doggy_Format _new = me, _old = me;
  if (action->action_Format[PRE_ACTION] != NULL) {
    _new = action->action_Format[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Format)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Format) {
    doggy_Format_args(me) = Traverse_copy_List_doggy_Type (doggy_Format_args(me), action);
    doggy_Format_result(me) = Traverse_copy_doggy_Type (doggy_Format_result(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_Format_num(me) = 0;
    }
  }
  if (action->action_Format[POST_ACTION] != NULL) {
    me = action->action_Format[POST_ACTION](me, _old);
  }
  return me;
}

doggy_dummy_type Traverse_copy_doggy_dummy_type (doggy_dummy_type me, copy_doggy_TraverseTable action)
{ doggy_dummy_type _new = me, _old = me;
  if (action->action_dummy_type[PRE_ACTION] != NULL) {
    _new = action->action_dummy_type[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_dummy_type)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_dummy_type) {
    doggy_dummy_type_a(me) = Traverse_copy_List_Ident (doggy_dummy_type_a(me), action);
    doggy_dummy_type_y(me) = Traverse_copy_List_doggy_ActualOp (doggy_dummy_type_y(me), action);
    doggy_dummy_type_z(me) = Traverse_copy_List_doggy_TypePair (doggy_dummy_type_z(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      doggy_dummy_type_x(me) = NULL;
      doggy_dummy_type_b(me) = NULL;
    }
  }
  if (action->action_dummy_type[POST_ACTION] != NULL) {
    me = action->action_dummy_type[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Scope Traverse_copy_doggy_Scope (doggy_Scope me, copy_doggy_TraverseTable action)
{ doggy_Scope _new = me, _old = me;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    _new = action->action_Scope[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (doggy_Scope)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (doggy_Scope_tag(me)) {
      case doggy_OpSetScope_kind:
        if (action->action_OpSetScope[PRE_ACTION] != NULL) {
          _new = action->action_OpSetScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Scope) {
          doggy_Scope_next(me) = Traverse_copy_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_OpSetScope) {
          doggy_OpSetScope_data(me) = Traverse_copy_doggy_Applied_operation (doggy_OpSetScope_data(me), action);
        }
        if (action->action_OpSetScope[POST_ACTION] != NULL) {
          _new = action->action_OpSetScope[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_AppliedOpScope_kind:
        if (action->action_AppliedOpScope[PRE_ACTION] != NULL) {
          _new = action->action_AppliedOpScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Scope) {
          doggy_Scope_next(me) = Traverse_copy_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_AppliedOpScope) {
          doggy_AppliedOpScope_data(me) = Traverse_copy_doggy_Applied_operation (doggy_AppliedOpScope_data(me), action);
        }
        if (action->action_AppliedOpScope[POST_ACTION] != NULL) {
          _new = action->action_AppliedOpScope[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_ExprGuardScope_kind:
        if (action->action_ExprGuardScope[PRE_ACTION] != NULL) {
          _new = action->action_ExprGuardScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Scope) {
          doggy_Scope_next(me) = Traverse_copy_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_ExprGuardScope) {
          doggy_ExprGuardScope_data(me) = Traverse_copy_doggy_Guard (doggy_ExprGuardScope_data(me), action);
        }
        if (action->action_ExprGuardScope[POST_ACTION] != NULL) {
          _new = action->action_ExprGuardScope[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_RhsGuardScope_kind:
        if (action->action_RhsGuardScope[PRE_ACTION] != NULL) {
          _new = action->action_RhsGuardScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Scope) {
          doggy_Scope_next(me) = Traverse_copy_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_RhsGuardScope) {
          doggy_RhsGuardScope_data(me) = Traverse_copy_doggy_Guard (doggy_RhsGuardScope_data(me), action);
        }
        if (action->action_RhsGuardScope[POST_ACTION] != NULL) {
          _new = action->action_RhsGuardScope[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_FuncRuleScope_kind:
        if (action->action_FuncRuleScope[PRE_ACTION] != NULL) {
          _new = action->action_FuncRuleScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Scope) {
          doggy_Scope_next(me) = Traverse_copy_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_FuncRuleScope) {
          doggy_FuncRuleScope_data(me) = Traverse_copy_doggy_FuncRule (doggy_FuncRuleScope_data(me), action);
        }
        if (action->action_FuncRuleScope[POST_ACTION] != NULL) {
          _new = action->action_FuncRuleScope[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_RuleScope_kind:
        if (action->action_RuleScope[PRE_ACTION] != NULL) {
          _new = action->action_RuleScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Scope) {
          doggy_Scope_next(me) = Traverse_copy_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_RuleScope) {
          doggy_RuleScope_data(me) = Traverse_copy_doggy_Rule (doggy_RuleScope_data(me), action);
        }
        if (action->action_RuleScope[POST_ACTION] != NULL) {
          _new = action->action_RuleScope[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case doggy_machine_descriptionScope_kind:
        if (action->action_machine_descriptionScope[PRE_ACTION] != NULL) {
          _new = action->action_machine_descriptionScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Scope) {
          doggy_Scope_next(me) = Traverse_copy_doggy_Scope (doggy_Scope_next(me), action);
        }
        if (!action->skip_children_machine_descriptionScope) {
          doggy_machine_descriptionScope_data(me) = Traverse_copy_doggy_machine_description (doggy_machine_descriptionScope_data(me), action);
        }
        if (action->action_machine_descriptionScope[POST_ACTION] != NULL) {
          _new = action->action_machine_descriptionScope[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    me = action->action_Scope[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Num Traverse_copy_List_doggy_Num (List_doggy_Num me, copy_doggy_TraverseTable action)
{ List_doggy_Num _new = me, _old = me;
  if (action->action_List_Num[PRE_ACTION] != NULL) {
    _new = action->action_List_Num[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Num)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Num) {
    List_doggy_Num_data(me) = Traverse_copy_doggy_Num (List_doggy_Num_data(me), action);
    List_doggy_Num_next(me) = Traverse_copy_List_doggy_Num (List_doggy_Num_next(me), action);
  }
  }
  if (action->action_List_Num[POST_ACTION] != NULL) {
    me = action->action_List_Num[POST_ACTION](me, _old);
  }
  return me;
}

List_List_doggy_TypePair Traverse_copy_List_List_doggy_TypePair (List_List_doggy_TypePair me, copy_doggy_TraverseTable action)
{ List_List_doggy_TypePair _new = me, _old = me;
  if (action->action_List_List_TypePair[PRE_ACTION] != NULL) {
    _new = action->action_List_List_TypePair[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_List_doggy_TypePair)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_List_TypePair) {
    List_List_doggy_TypePair_data(me) = Traverse_copy_List_doggy_TypePair (List_List_doggy_TypePair_data(me), action);
    List_List_doggy_TypePair_next(me) = Traverse_copy_List_List_doggy_TypePair (List_List_doggy_TypePair_next(me), action);
  }
  }
  if (action->action_List_List_TypePair[POST_ACTION] != NULL) {
    me = action->action_List_List_TypePair[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_TypePair Traverse_copy_List_doggy_TypePair (List_doggy_TypePair me, copy_doggy_TraverseTable action)
{ List_doggy_TypePair _new = me, _old = me;
  if (action->action_List_TypePair[PRE_ACTION] != NULL) {
    _new = action->action_List_TypePair[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_TypePair)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_TypePair) {
    List_doggy_TypePair_data(me) = Traverse_copy_doggy_TypePair (List_doggy_TypePair_data(me), action);
    List_doggy_TypePair_next(me) = Traverse_copy_List_doggy_TypePair (List_doggy_TypePair_next(me), action);
  }
  }
  if (action->action_List_TypePair[POST_ACTION] != NULL) {
    me = action->action_List_TypePair[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_ActualOp Traverse_copy_List_doggy_ActualOp (List_doggy_ActualOp me, copy_doggy_TraverseTable action)
{ List_doggy_ActualOp _new = me, _old = me;
  if (action->action_List_ActualOp[PRE_ACTION] != NULL) {
    _new = action->action_List_ActualOp[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_ActualOp)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_ActualOp) {
    List_doggy_ActualOp_data(me) = Traverse_copy_doggy_ActualOp (List_doggy_ActualOp_data(me), action);
    List_doggy_ActualOp_next(me) = Traverse_copy_List_doggy_ActualOp (List_doggy_ActualOp_next(me), action);
  }
  }
  if (action->action_List_ActualOp[POST_ACTION] != NULL) {
    me = action->action_List_ActualOp[POST_ACTION](me, _old);
  }
  return me;
}

List_List_doggy_Type Traverse_copy_List_List_doggy_Type (List_List_doggy_Type me, copy_doggy_TraverseTable action)
{ List_List_doggy_Type _new = me, _old = me;
  if (action->action_List_List_Type[PRE_ACTION] != NULL) {
    _new = action->action_List_List_Type[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_List_doggy_Type)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_List_Type) {
    List_List_doggy_Type_data(me) = Traverse_copy_List_doggy_Type (List_List_doggy_Type_data(me), action);
    List_List_doggy_Type_next(me) = Traverse_copy_List_List_doggy_Type (List_List_doggy_Type_next(me), action);
  }
  }
  if (action->action_List_List_Type[POST_ACTION] != NULL) {
    me = action->action_List_List_Type[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Operator Traverse_copy_List_doggy_Operator (List_doggy_Operator me, copy_doggy_TraverseTable action)
{ List_doggy_Operator _new = me, _old = me;
  if (action->action_List_Operator[PRE_ACTION] != NULL) {
    _new = action->action_List_Operator[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Operator)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Operator) {
    List_doggy_Operator_data(me) = Traverse_copy_doggy_Operator (List_doggy_Operator_data(me), action);
    List_doggy_Operator_next(me) = Traverse_copy_List_doggy_Operator (List_doggy_Operator_next(me), action);
  }
  }
  if (action->action_List_Operator[POST_ACTION] != NULL) {
    me = action->action_List_Operator[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Definition Traverse_copy_List_doggy_Definition (List_doggy_Definition me, copy_doggy_TraverseTable action)
{ List_doggy_Definition _new = me, _old = me;
  if (action->action_List_Definition[PRE_ACTION] != NULL) {
    _new = action->action_List_Definition[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Definition)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Definition) {
    List_doggy_Definition_data(me) = Traverse_copy_doggy_Definition (List_doggy_Definition_data(me), action);
    List_doggy_Definition_next(me) = Traverse_copy_List_doggy_Definition (List_doggy_Definition_next(me), action);
  }
  }
  if (action->action_List_Definition[POST_ACTION] != NULL) {
    me = action->action_List_Definition[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Expr Traverse_copy_List_doggy_Expr (List_doggy_Expr me, copy_doggy_TraverseTable action)
{ List_doggy_Expr _new = me, _old = me;
  if (action->action_List_Expr[PRE_ACTION] != NULL) {
    _new = action->action_List_Expr[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Expr)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Expr) {
    List_doggy_Expr_data(me) = Traverse_copy_doggy_Expr (List_doggy_Expr_data(me), action);
    List_doggy_Expr_next(me) = Traverse_copy_List_doggy_Expr (List_doggy_Expr_next(me), action);
  }
  }
  if (action->action_List_Expr[POST_ACTION] != NULL) {
    me = action->action_List_Expr[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Guard Traverse_copy_List_doggy_Guard (List_doggy_Guard me, copy_doggy_TraverseTable action)
{ List_doggy_Guard _new = me, _old = me;
  if (action->action_List_Guard[PRE_ACTION] != NULL) {
    _new = action->action_List_Guard[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Guard)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Guard) {
    List_doggy_Guard_data(me) = Traverse_copy_doggy_Guard (List_doggy_Guard_data(me), action);
    List_doggy_Guard_next(me) = Traverse_copy_List_doggy_Guard (List_doggy_Guard_next(me), action);
  }
  }
  if (action->action_List_Guard[POST_ACTION] != NULL) {
    me = action->action_List_Guard[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Pattern Traverse_copy_List_doggy_Pattern (List_doggy_Pattern me, copy_doggy_TraverseTable action)
{ List_doggy_Pattern _new = me, _old = me;
  if (action->action_List_Pattern[PRE_ACTION] != NULL) {
    _new = action->action_List_Pattern[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Pattern)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Pattern) {
    List_doggy_Pattern_data(me) = Traverse_copy_doggy_Pattern (List_doggy_Pattern_data(me), action);
    List_doggy_Pattern_next(me) = Traverse_copy_List_doggy_Pattern (List_doggy_Pattern_next(me), action);
  }
  }
  if (action->action_List_Pattern[POST_ACTION] != NULL) {
    me = action->action_List_Pattern[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Argument Traverse_copy_List_doggy_Argument (List_doggy_Argument me, copy_doggy_TraverseTable action)
{ List_doggy_Argument _new = me, _old = me;
  if (action->action_List_Argument[PRE_ACTION] != NULL) {
    _new = action->action_List_Argument[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Argument)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Argument) {
    List_doggy_Argument_data(me) = Traverse_copy_doggy_Argument (List_doggy_Argument_data(me), action);
    List_doggy_Argument_next(me) = Traverse_copy_List_doggy_Argument (List_doggy_Argument_next(me), action);
  }
  }
  if (action->action_List_Argument[POST_ACTION] != NULL) {
    me = action->action_List_Argument[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_FuncRule Traverse_copy_List_doggy_FuncRule (List_doggy_FuncRule me, copy_doggy_TraverseTable action)
{ List_doggy_FuncRule _new = me, _old = me;
  if (action->action_List_FuncRule[PRE_ACTION] != NULL) {
    _new = action->action_List_FuncRule[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_FuncRule)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_FuncRule) {
    List_doggy_FuncRule_data(me) = Traverse_copy_doggy_FuncRule (List_doggy_FuncRule_data(me), action);
    List_doggy_FuncRule_next(me) = Traverse_copy_List_doggy_FuncRule (List_doggy_FuncRule_next(me), action);
  }
  }
  if (action->action_List_FuncRule[POST_ACTION] != NULL) {
    me = action->action_List_FuncRule[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Attribute Traverse_copy_List_doggy_Attribute (List_doggy_Attribute me, copy_doggy_TraverseTable action)
{ List_doggy_Attribute _new = me, _old = me;
  if (action->action_List_Attribute[PRE_ACTION] != NULL) {
    _new = action->action_List_Attribute[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Attribute)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Attribute) {
    List_doggy_Attribute_data(me) = Traverse_copy_doggy_Attribute (List_doggy_Attribute_data(me), action);
    List_doggy_Attribute_next(me) = Traverse_copy_List_doggy_Attribute (List_doggy_Attribute_next(me), action);
  }
  }
  if (action->action_List_Attribute[POST_ACTION] != NULL) {
    me = action->action_List_Attribute[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Property Traverse_copy_List_doggy_Property (List_doggy_Property me, copy_doggy_TraverseTable action)
{ List_doggy_Property _new = me, _old = me;
  if (action->action_List_Property[PRE_ACTION] != NULL) {
    _new = action->action_List_Property[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Property)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Property) {
    List_doggy_Property_data(me) = Traverse_copy_doggy_Property (List_doggy_Property_data(me), action);
    List_doggy_Property_next(me) = Traverse_copy_List_doggy_Property (List_doggy_Property_next(me), action);
  }
  }
  if (action->action_List_Property[POST_ACTION] != NULL) {
    me = action->action_List_Property[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Applied_formal Traverse_copy_List_doggy_Applied_formal (List_doggy_Applied_formal me, copy_doggy_TraverseTable action)
{ List_doggy_Applied_formal _new = me, _old = me;
  if (action->action_List_Applied_formal[PRE_ACTION] != NULL) {
    _new = action->action_List_Applied_formal[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Applied_formal)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Applied_formal) {
    List_doggy_Applied_formal_data(me) = Traverse_copy_doggy_Applied_formal (List_doggy_Applied_formal_data(me), action);
    List_doggy_Applied_formal_next(me) = Traverse_copy_List_doggy_Applied_formal (List_doggy_Applied_formal_next(me), action);
  }
  }
  if (action->action_List_Applied_formal[POST_ACTION] != NULL) {
    me = action->action_List_Applied_formal[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Operation_def Traverse_copy_List_doggy_Operation_def (List_doggy_Operation_def me, copy_doggy_TraverseTable action)
{ List_doggy_Operation_def _new = me, _old = me;
  if (action->action_List_Operation_def[PRE_ACTION] != NULL) {
    _new = action->action_List_Operation_def[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Operation_def)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Operation_def) {
    List_doggy_Operation_def_data(me) = Traverse_copy_doggy_Operation_def (List_doggy_Operation_def_data(me), action);
    List_doggy_Operation_def_next(me) = Traverse_copy_List_doggy_Operation_def (List_doggy_Operation_def_next(me), action);
  }
  }
  if (action->action_List_Operation_def[POST_ACTION] != NULL) {
    me = action->action_List_Operation_def[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Type Traverse_copy_List_doggy_Type (List_doggy_Type me, copy_doggy_TraverseTable action)
{ List_doggy_Type _new = me, _old = me;
  if (action->action_List_Type[PRE_ACTION] != NULL) {
    _new = action->action_List_Type[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Type)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Type) {
    List_doggy_Type_data(me) = Traverse_copy_doggy_Type (List_doggy_Type_data(me), action);
    List_doggy_Type_next(me) = Traverse_copy_List_doggy_Type (List_doggy_Type_next(me), action);
  }
  }
  if (action->action_List_Type[POST_ACTION] != NULL) {
    me = action->action_List_Type[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Rule Traverse_copy_List_doggy_Rule (List_doggy_Rule me, copy_doggy_TraverseTable action)
{ List_doggy_Rule _new = me, _old = me;
  if (action->action_List_Rule[PRE_ACTION] != NULL) {
    _new = action->action_List_Rule[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Rule)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Rule) {
    List_doggy_Rule_data(me) = Traverse_copy_doggy_Rule (List_doggy_Rule_data(me), action);
    List_doggy_Rule_next(me) = Traverse_copy_List_doggy_Rule (List_doggy_Rule_next(me), action);
  }
  }
  if (action->action_List_Rule[POST_ACTION] != NULL) {
    me = action->action_List_Rule[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Func Traverse_copy_List_doggy_Func (List_doggy_Func me, copy_doggy_TraverseTable action)
{ List_doggy_Func _new = me, _old = me;
  if (action->action_List_Func[PRE_ACTION] != NULL) {
    _new = action->action_List_Func[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Func)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Func) {
    List_doggy_Func_data(me) = Traverse_copy_doggy_Func (List_doggy_Func_data(me), action);
    List_doggy_Func_next(me) = Traverse_copy_List_doggy_Func (List_doggy_Func_next(me), action);
  }
  }
  if (action->action_List_Func[POST_ACTION] != NULL) {
    me = action->action_List_Func[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Section Traverse_copy_List_doggy_Section (List_doggy_Section me, copy_doggy_TraverseTable action)
{ List_doggy_Section _new = me, _old = me;
  if (action->action_List_Section[PRE_ACTION] != NULL) {
    _new = action->action_List_Section[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Section)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Section) {
    List_doggy_Section_data(me) = Traverse_copy_doggy_Section (List_doggy_Section_data(me), action);
    List_doggy_Section_next(me) = Traverse_copy_List_doggy_Section (List_doggy_Section_next(me), action);
  }
  }
  if (action->action_List_Section[POST_ACTION] != NULL) {
    me = action->action_List_Section[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_FunctionDef Traverse_copy_List_doggy_FunctionDef (List_doggy_FunctionDef me, copy_doggy_TraverseTable action)
{ List_doggy_FunctionDef _new = me, _old = me;
  if (action->action_List_FunctionDef[PRE_ACTION] != NULL) {
    _new = action->action_List_FunctionDef[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_FunctionDef)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_FunctionDef) {
    List_doggy_FunctionDef_data(me) = Traverse_copy_doggy_FunctionDef (List_doggy_FunctionDef_data(me), action);
    List_doggy_FunctionDef_next(me) = Traverse_copy_List_doggy_FunctionDef (List_doggy_FunctionDef_next(me), action);
  }
  }
  if (action->action_List_FunctionDef[POST_ACTION] != NULL) {
    me = action->action_List_FunctionDef[POST_ACTION](me, _old);
  }
  return me;
}

List_doggy_Typedef Traverse_copy_List_doggy_Typedef (List_doggy_Typedef me, copy_doggy_TraverseTable action)
{ List_doggy_Typedef _new = me, _old = me;
  if (action->action_List_Typedef[PRE_ACTION] != NULL) {
    _new = action->action_List_Typedef[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_doggy_Typedef)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Typedef) {
    List_doggy_Typedef_data(me) = Traverse_copy_doggy_Typedef (List_doggy_Typedef_data(me), action);
    List_doggy_Typedef_next(me) = Traverse_copy_List_doggy_Typedef (List_doggy_Typedef_next(me), action);
  }
  }
  if (action->action_List_Typedef[POST_ACTION] != NULL) {
    me = action->action_List_Typedef[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Operator Traverse_copy_doggy_Operator (doggy_Operator me, copy_doggy_TraverseTable action)
{ doggy_Operator _new = me, _old = me;
  if (action->action_Operator[PRE_ACTION] != NULL) {
    return action->action_Operator[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_Operator[POST_ACTION] != NULL) {
    me = action->action_Operator[POST_ACTION](me, _old);
  }
  return me;
}

doggy_MonOp Traverse_copy_doggy_MonOp (doggy_MonOp me, copy_doggy_TraverseTable action)
{ doggy_MonOp _new = me, _old = me;
  if (action->action_MonOp[PRE_ACTION] != NULL) {
    return action->action_MonOp[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_MonOp[POST_ACTION] != NULL) {
    me = action->action_MonOp[POST_ACTION](me, _old);
  }
  return me;
}

doggy_Property Traverse_copy_doggy_Property (doggy_Property me, copy_doggy_TraverseTable action)
{ doggy_Property _new = me, _old = me;
  if (action->action_Property[PRE_ACTION] != NULL) {
    return action->action_Property[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_Property[POST_ACTION] != NULL) {
    me = action->action_Property[POST_ACTION](me, _old);
  }
  return me;
}

int Traverse_compare_doggy_doggy (doggy_doggy x, doggy_doggy y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_doggy[PRE_ACTION] != NULL) {
    return action->action_doggy[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_doggy) {
    if ((comp = Traverse_compare_List_doggy_Typedef (doggy_doggy_types(x),doggy_doggy_types(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_machine_description (doggy_doggy_source(x),doggy_doggy_source(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_machine_description (doggy_doggy_target(x),doggy_doggy_target(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_FunctionDef (doggy_doggy_funcs(x),doggy_doggy_funcs(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Section (doggy_doggy_sections(x),doggy_doggy_sections(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Typedef (doggy_Typedef x, doggy_Typedef y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Typedef[PRE_ACTION] != NULL) {
    return action->action_Typedef[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Typedef) {
    if ((comp = Traverse_compare_Ident (doggy_Typedef_id(x),doggy_Typedef_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_String (doggy_Typedef_name(x),doggy_Typedef_name(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_String (doggy_Typedef_short_hand(x),doggy_Typedef_short_hand(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_String (doggy_Typedef_value(x),doggy_Typedef_value(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Attributes (doggy_Typedef_attrs(x),doggy_Typedef_attrs(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_FunctionDef (doggy_FunctionDef x, doggy_FunctionDef y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_FunctionDef[PRE_ACTION] != NULL) {
    return action->action_FunctionDef[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_FunctionDef_tag(x) < doggy_FunctionDef_tag(y)) return -1;
  if (doggy_FunctionDef_tag(x) > doggy_FunctionDef_tag(y)) return 1;;
  switch (doggy_FunctionDef_tag(x)) {
      case doggy_ExtFunc_kind:
        if (action->action_ExtFunc[PRE_ACTION] != NULL) {
          return action->action_ExtFunc[PRE_ACTION](x, y);
        }
        if (!action->skip_children_FunctionDef) {
          if ((comp = Traverse_compare_doggy_Type (doggy_FunctionDef_result(x),doggy_FunctionDef_result(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (doggy_FunctionDef_id(x),doggy_FunctionDef_id(y), action)) != 0) return comp;
        }
        if (!action->skip_children_ExtFunc) {
          if ((comp = Traverse_compare_List_doggy_Type (doggy_ExtFunc_args(x),doggy_ExtFunc_args(y), action)) != 0) return comp;
        }
        if (action->action_ExtFunc[POST_ACTION] != NULL) {
          return action->action_ExtFunc[POST_ACTION](x, y);
        }
        break;
      case doggy_ExtVar_kind:
        if (action->action_ExtVar[PRE_ACTION] != NULL) {
          return action->action_ExtVar[PRE_ACTION](x, y);
        }
        if (!action->skip_children_FunctionDef) {
          if ((comp = Traverse_compare_doggy_Type (doggy_FunctionDef_result(x),doggy_FunctionDef_result(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (doggy_FunctionDef_id(x),doggy_FunctionDef_id(y), action)) != 0) return comp;
        }
        if (action->action_ExtVar[POST_ACTION] != NULL) {
          return action->action_ExtVar[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_machine_description (doggy_machine_description x, doggy_machine_description y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_machine_description[PRE_ACTION] != NULL) {
    return action->action_machine_description[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_machine_description) {
    if ((comp = Traverse_compare_Ident (doggy_machine_description_id(x),doggy_machine_description_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Operation_def (doggy_machine_description_defs(x),doggy_machine_description_defs(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Applied_formal (doggy_machine_description_supports(x),doggy_machine_description_supports(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Operation_def (doggy_Operation_def x, doggy_Operation_def y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Operation_def[PRE_ACTION] != NULL) {
    return action->action_Operation_def[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Operation_def) {
    if ((comp = Traverse_compare_Ident (doggy_Operation_def_id(x),doggy_Operation_def_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Type (doggy_Operation_def_types(x),doggy_Operation_def_types(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Type (doggy_Operation_def_result(x),doggy_Operation_def_result(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (doggy_Operation_def_actual_id(x),doggy_Operation_def_actual_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Attributes (doggy_Operation_def_descr(x),doggy_Operation_def_descr(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Property (doggy_Operation_def_props(x),doggy_Operation_def_props(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Attributes (doggy_Attributes x, doggy_Attributes y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Attributes[PRE_ACTION] != NULL) {
    return action->action_Attributes[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Attributes) {
    if ((comp = Traverse_compare_List_doggy_Attribute (doggy_Attributes_ids(x),doggy_Attributes_ids(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Attributes (doggy_Attributes_tail(x),doggy_Attributes_tail(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Attribute (doggy_Attribute x, doggy_Attribute y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Attribute[PRE_ACTION] != NULL) {
    return action->action_Attribute[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Attribute_tag(x) < doggy_Attribute_tag(y)) return -1;
  if (doggy_Attribute_tag(x) > doggy_Attribute_tag(y)) return 1;;
  switch (doggy_Attribute_tag(x)) {
      case doggy_IdAttr_kind:
        if (action->action_IdAttr[PRE_ACTION] != NULL) {
          return action->action_IdAttr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IdAttr) {
          if ((comp = Traverse_compare_Ident (doggy_IdAttr_id(x),doggy_IdAttr_id(y), action)) != 0) return comp;
        }
        if (action->action_IdAttr[POST_ACTION] != NULL) {
          return action->action_IdAttr[POST_ACTION](x, y);
        }
        break;
      case doggy_OpAttr_kind:
        if (action->action_OpAttr[PRE_ACTION] != NULL) {
          return action->action_OpAttr[PRE_ACTION](x, y);
        }
        if (action->action_OpAttr[POST_ACTION] != NULL) {
          return action->action_OpAttr[POST_ACTION](x, y);
        }
        break;
      case doggy_IntAttr_kind:
        if (action->action_IntAttr[PRE_ACTION] != NULL) {
          return action->action_IntAttr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IntAttr) {
          if ((comp = Traverse_compare_Int (doggy_IntAttr_i(x),doggy_IntAttr_i(y), action)) != 0) return comp;
        }
        if (action->action_IntAttr[POST_ACTION] != NULL) {
          return action->action_IntAttr[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Section (doggy_Section x, doggy_Section y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Section[PRE_ACTION] != NULL) {
    return action->action_Section[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Section_tag(x) < doggy_Section_tag(y)) return -1;
  if (doggy_Section_tag(x) > doggy_Section_tag(y)) return 1;;
  switch (doggy_Section_tag(x)) {
      case doggy_FuncSection_kind:
        if (action->action_FuncSection[PRE_ACTION] != NULL) {
          return action->action_FuncSection[PRE_ACTION](x, y);
        }
        if (!action->skip_children_FuncSection) {
          if ((comp = Traverse_compare_List_doggy_Func (doggy_FuncSection_funcs(x),doggy_FuncSection_funcs(y), action)) != 0) return comp;
        }
        if (action->action_FuncSection[POST_ACTION] != NULL) {
          return action->action_FuncSection[POST_ACTION](x, y);
        }
        break;
      case doggy_RuleSection_kind:
        if (action->action_RuleSection[PRE_ACTION] != NULL) {
          return action->action_RuleSection[PRE_ACTION](x, y);
        }
        if (!action->skip_children_RuleSection) {
          if ((comp = Traverse_compare_Ident (doggy_RuleSection_rules_id(x),doggy_RuleSection_rules_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_doggy_Rule (doggy_RuleSection_rules(x),doggy_RuleSection_rules(y), action)) != 0) return comp;
        }
        if (action->action_RuleSection[POST_ACTION] != NULL) {
          return action->action_RuleSection[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Rule (doggy_Rule x, doggy_Rule y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Rule[PRE_ACTION] != NULL) {
    return action->action_Rule[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Rule) {
    if ((comp = Traverse_compare_doggy_Lhs (doggy_Rule_lhs(x),doggy_Rule_lhs(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Rhs (doggy_Rule_rhs(x),doggy_Rule_rhs(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Lhs (doggy_Lhs x, doggy_Lhs y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Lhs[PRE_ACTION] != NULL) {
    return action->action_Lhs[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Lhs_tag(x) < doggy_Lhs_tag(y)) return -1;
  if (doggy_Lhs_tag(x) > doggy_Lhs_tag(y)) return 1;;
  switch (doggy_Lhs_tag(x)) {
      case doggy_LabeledLhs_kind:
        if (action->action_LabeledLhs[PRE_ACTION] != NULL) {
          return action->action_LabeledLhs[PRE_ACTION](x, y);
        }
        if (!action->skip_children_LabeledLhs) {
          if ((comp = Traverse_compare_Ident (doggy_LabeledLhs_id(x),doggy_LabeledLhs_id(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Lhs) {
          if ((comp = Traverse_compare_doggy_Pattern (doggy_Lhs_pat(x),doggy_Lhs_pat(y), action)) != 0) return comp;
        }
        if (action->action_LabeledLhs[POST_ACTION] != NULL) {
          return action->action_LabeledLhs[POST_ACTION](x, y);
        }
        break;
      case doggy_UnLabeledLhs_kind:
        if (action->action_UnLabeledLhs[PRE_ACTION] != NULL) {
          return action->action_UnLabeledLhs[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Lhs) {
          if ((comp = Traverse_compare_doggy_Pattern (doggy_Lhs_pat(x),doggy_Lhs_pat(y), action)) != 0) return comp;
        }
        if (action->action_UnLabeledLhs[POST_ACTION] != NULL) {
          return action->action_UnLabeledLhs[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Func (doggy_Func x, doggy_Func y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Func[PRE_ACTION] != NULL) {
    return action->action_Func[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Func) {
    if ((comp = Traverse_compare_Bool (doggy_Func_ext(x),doggy_Func_ext(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Type (doggy_Func_type(x),doggy_Func_type(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (doggy_Func_id(x),doggy_Func_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_FuncRule (doggy_Func_rules(x),doggy_Func_rules(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_FuncRule (doggy_FuncRule x, doggy_FuncRule y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_FuncRule[PRE_ACTION] != NULL) {
    return action->action_FuncRule[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_FuncRule) {
    if ((comp = Traverse_compare_List_doggy_Argument (doggy_FuncRule_args(x),doggy_FuncRule_args(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Rhs (doggy_FuncRule_rhs(x),doggy_FuncRule_rhs(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Argument (doggy_Argument x, doggy_Argument y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Argument[PRE_ACTION] != NULL) {
    return action->action_Argument[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Argument_tag(x) < doggy_Argument_tag(y)) return -1;
  if (doggy_Argument_tag(x) > doggy_Argument_tag(y)) return 1;;
  switch (doggy_Argument_tag(x)) {
      case doggy_TypedArg_kind:
        if (action->action_TypedArg[PRE_ACTION] != NULL) {
          return action->action_TypedArg[PRE_ACTION](x, y);
        }
        if (!action->skip_children_TypedArg) {
          if ((comp = Traverse_compare_doggy_Type (doggy_TypedArg_type(x),doggy_TypedArg_type(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Argument) {
          if ((comp = Traverse_compare_Ident (doggy_Argument_id(x),doggy_Argument_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_ArgPat (doggy_Argument_pat(x),doggy_Argument_pat(y), action)) != 0) return comp;
        }
        if (action->action_TypedArg[POST_ACTION] != NULL) {
          return action->action_TypedArg[POST_ACTION](x, y);
        }
        break;
      case doggy_UnTypedArg_kind:
        if (action->action_UnTypedArg[PRE_ACTION] != NULL) {
          return action->action_UnTypedArg[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Argument) {
          if ((comp = Traverse_compare_Ident (doggy_Argument_id(x),doggy_Argument_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_ArgPat (doggy_Argument_pat(x),doggy_Argument_pat(y), action)) != 0) return comp;
        }
        if (action->action_UnTypedArg[POST_ACTION] != NULL) {
          return action->action_UnTypedArg[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_ArgPat (doggy_ArgPat x, doggy_ArgPat y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_ArgPat[PRE_ACTION] != NULL) {
    return action->action_ArgPat[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_ArgPat_tag(x) < doggy_ArgPat_tag(y)) return -1;
  if (doggy_ArgPat_tag(x) > doggy_ArgPat_tag(y)) return 1;;
  switch (doggy_ArgPat_tag(x)) {
      case doggy_PatArg_kind:
        if (action->action_PatArg[PRE_ACTION] != NULL) {
          return action->action_PatArg[PRE_ACTION](x, y);
        }
        if (!action->skip_children_PatArg) {
          if ((comp = Traverse_compare_doggy_Pattern (doggy_PatArg_pat(x),doggy_PatArg_pat(y), action)) != 0) return comp;
        }
        if (action->action_PatArg[POST_ACTION] != NULL) {
          return action->action_PatArg[POST_ACTION](x, y);
        }
        break;
      case doggy_SetArg_kind:
        if (action->action_SetArg[PRE_ACTION] != NULL) {
          return action->action_SetArg[PRE_ACTION](x, y);
        }
        if (!action->skip_children_SetArg) {
          if ((comp = Traverse_compare_doggy_Applied_operation (doggy_SetArg_set(x),doggy_SetArg_set(y), action)) != 0) return comp;
        }
        if (action->action_SetArg[POST_ACTION] != NULL) {
          return action->action_SetArg[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Pattern (doggy_Pattern x, doggy_Pattern y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Pattern[PRE_ACTION] != NULL) {
    return action->action_Pattern[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Pattern_tag(x) < doggy_Pattern_tag(y)) return -1;
  if (doggy_Pattern_tag(x) > doggy_Pattern_tag(y)) return 1;;
  switch (doggy_Pattern_tag(x)) {
      case doggy_TypedPattern_kind:
        if (action->action_TypedPattern[PRE_ACTION] != NULL) {
          return action->action_TypedPattern[PRE_ACTION](x, y);
        }
        if (!action->skip_children_TypedPattern) {
          if ((comp = Traverse_compare_doggy_Type (doggy_TypedPattern_btype(x),doggy_TypedPattern_btype(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_Pattern (doggy_TypedPattern_pat(x),doggy_TypedPattern_pat(y), action)) != 0) return comp;
        }
        if (action->action_TypedPattern[POST_ACTION] != NULL) {
          return action->action_TypedPattern[POST_ACTION](x, y);
        }
        break;
      case doggy_ConsPattern_kind:
        if (action->action_ConsPattern[PRE_ACTION] != NULL) {
          return action->action_ConsPattern[PRE_ACTION](x, y);
        }
        if (!action->skip_children_ConsPattern) {
          if ((comp = Traverse_compare_doggy_Pattern (doggy_ConsPattern_lhs(x),doggy_ConsPattern_lhs(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_Pattern (doggy_ConsPattern_rhs(x),doggy_ConsPattern_rhs(y), action)) != 0) return comp;
        }
        if (action->action_ConsPattern[POST_ACTION] != NULL) {
          return action->action_ConsPattern[POST_ACTION](x, y);
        }
        break;
      case doggy_DefPattern_kind:
        if (action->action_DefPattern[PRE_ACTION] != NULL) {
          return action->action_DefPattern[PRE_ACTION](x, y);
        }
        if (!action->skip_children_DefPattern) {
          if ((comp = Traverse_compare_List_doggy_Pattern (doggy_DefPattern_ids(x),doggy_DefPattern_ids(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_Pattern (doggy_DefPattern_arg(x),doggy_DefPattern_arg(y), action)) != 0) return comp;
        }
        if (action->action_DefPattern[POST_ACTION] != NULL) {
          return action->action_DefPattern[POST_ACTION](x, y);
        }
        break;
      case doggy_IdentPattern_kind:
        if (action->action_IdentPattern[PRE_ACTION] != NULL) {
          return action->action_IdentPattern[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IdentPattern) {
          if ((comp = Traverse_compare_Ident (doggy_IdentPattern_id(x),doggy_IdentPattern_id(y), action)) != 0) return comp;
        }
        if (action->action_IdentPattern[POST_ACTION] != NULL) {
          return action->action_IdentPattern[POST_ACTION](x, y);
        }
        break;
      case doggy_OpPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          return action->action_BasicPattern[PRE_ACTION](x, y);
        }
        if (action->action_OpPattern[PRE_ACTION] != NULL) {
          return action->action_OpPattern[PRE_ACTION](x, y);
        }
        if (!action->skip_children_OpPattern) {
          if ((comp = Traverse_compare_doggy_Applied_operation (doggy_OpPattern_op(x),doggy_OpPattern_op(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_doggy_Pattern (doggy_OpPattern_args(x),doggy_OpPattern_args(y), action)) != 0) return comp;
        }
        if (action->action_OpPattern[POST_ACTION] != NULL) {
          return action->action_OpPattern[POST_ACTION](x, y);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          return action->action_BasicPattern[POST_ACTION](x, y);
        }
        break;
      case doggy_ConstPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          return action->action_BasicPattern[PRE_ACTION](x, y);
        }
        if (action->action_ConstPattern[PRE_ACTION] != NULL) {
          return action->action_ConstPattern[PRE_ACTION](x, y);
        }
        if (!action->skip_children_ConstPattern) {
          if ((comp = Traverse_compare_Int (doggy_ConstPattern_cnst(x),doggy_ConstPattern_cnst(y), action)) != 0) return comp;
        }
        if (action->action_ConstPattern[POST_ACTION] != NULL) {
          return action->action_ConstPattern[POST_ACTION](x, y);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          return action->action_BasicPattern[POST_ACTION](x, y);
        }
        break;
      case doggy_NullPattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          return action->action_BasicPattern[PRE_ACTION](x, y);
        }
        if (action->action_NullPattern[PRE_ACTION] != NULL) {
          return action->action_NullPattern[PRE_ACTION](x, y);
        }
        if (action->action_NullPattern[POST_ACTION] != NULL) {
          return action->action_NullPattern[POST_ACTION](x, y);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          return action->action_BasicPattern[POST_ACTION](x, y);
        }
        break;
      case doggy_DontCarePattern_kind:
        if (action->action_BasicPattern[PRE_ACTION] != NULL) {
          return action->action_BasicPattern[PRE_ACTION](x, y);
        }
        if (action->action_DontCarePattern[PRE_ACTION] != NULL) {
          return action->action_DontCarePattern[PRE_ACTION](x, y);
        }
        if (!action->skip_children_DontCarePattern) {
          if ((comp = Traverse_compare_doggy_Expr (doggy_DontCarePattern_expr(x),doggy_DontCarePattern_expr(y), action)) != 0) return comp;
        }
        if (action->action_DontCarePattern[POST_ACTION] != NULL) {
          return action->action_DontCarePattern[POST_ACTION](x, y);
        }
        if (action->action_BasicPattern[POST_ACTION] != NULL) {
          return action->action_BasicPattern[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Rhs (doggy_Rhs x, doggy_Rhs y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Rhs[PRE_ACTION] != NULL) {
    return action->action_Rhs[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Rhs_tag(x) < doggy_Rhs_tag(y)) return -1;
  if (doggy_Rhs_tag(x) > doggy_Rhs_tag(y)) return 1;;
  switch (doggy_Rhs_tag(x)) {
      case doggy_PlainRhs_kind:
        if (action->action_PlainRhs[PRE_ACTION] != NULL) {
          return action->action_PlainRhs[PRE_ACTION](x, y);
        }
        if (!action->skip_children_PlainRhs) {
          if ((comp = Traverse_compare_List_doggy_Guard (doggy_PlainRhs_guards(x),doggy_PlainRhs_guards(y), action)) != 0) return comp;
        }
        if (action->action_PlainRhs[POST_ACTION] != NULL) {
          return action->action_PlainRhs[POST_ACTION](x, y);
        }
        break;
      case doggy_BlockRhs_kind:
        if (action->action_BlockRhs[PRE_ACTION] != NULL) {
          return action->action_BlockRhs[PRE_ACTION](x, y);
        }
        if (!action->skip_children_BlockRhs) {
          if ((comp = Traverse_compare_doggy_Rhs (doggy_BlockRhs_rhs(x),doggy_BlockRhs_rhs(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_Wherepart (doggy_BlockRhs_where(x),doggy_BlockRhs_where(y), action)) != 0) return comp;
        }
        if (action->action_BlockRhs[POST_ACTION] != NULL) {
          return action->action_BlockRhs[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Guard (doggy_Guard x, doggy_Guard y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Guard[PRE_ACTION] != NULL) {
    return action->action_Guard[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Guard_tag(x) < doggy_Guard_tag(y)) return -1;
  if (doggy_Guard_tag(x) > doggy_Guard_tag(y)) return 1;;
  switch (doggy_Guard_tag(x)) {
      case doggy_RhsGuard_kind:
        if (action->action_RhsGuard[PRE_ACTION] != NULL) {
          return action->action_RhsGuard[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Guard) {
          if ((comp = Traverse_compare_doggy_Expr (doggy_Guard_conds(x),doggy_Guard_conds(y), action)) != 0) return comp;
        }
        if (!action->skip_children_RhsGuard) {
          if ((comp = Traverse_compare_doggy_Rhs (doggy_RhsGuard_rhs(x),doggy_RhsGuard_rhs(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Guard) {
          if ((comp = Traverse_compare_doggy_Wherepart (doggy_Guard_where(x),doggy_Guard_where(y), action)) != 0) return comp;
        }
        if (action->action_RhsGuard[POST_ACTION] != NULL) {
          return action->action_RhsGuard[POST_ACTION](x, y);
        }
        break;
      case doggy_ExprGuard_kind:
        if (action->action_ExprGuard[PRE_ACTION] != NULL) {
          return action->action_ExprGuard[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Guard) {
          if ((comp = Traverse_compare_doggy_Expr (doggy_Guard_conds(x),doggy_Guard_conds(y), action)) != 0) return comp;
        }
        if (!action->skip_children_ExprGuard) {
          if ((comp = Traverse_compare_doggy_ExprSeq (doggy_ExprGuard_exprs(x),doggy_ExprGuard_exprs(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Guard) {
          if ((comp = Traverse_compare_doggy_Wherepart (doggy_Guard_where(x),doggy_Guard_where(y), action)) != 0) return comp;
        }
        if (action->action_ExprGuard[POST_ACTION] != NULL) {
          return action->action_ExprGuard[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_ExprSeq (doggy_ExprSeq x, doggy_ExprSeq y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_ExprSeq[PRE_ACTION] != NULL) {
    return action->action_ExprSeq[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_ExprSeq_tag(x) < doggy_ExprSeq_tag(y)) return -1;
  if (doggy_ExprSeq_tag(x) > doggy_ExprSeq_tag(y)) return 1;;
  switch (doggy_ExprSeq_tag(x)) {
      case doggy_OneExpr_kind:
        if (action->action_OneExpr[PRE_ACTION] != NULL) {
          return action->action_OneExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_OneExpr) {
          if ((comp = Traverse_compare_doggy_Expr (doggy_OneExpr_expr(x),doggy_OneExpr_expr(y), action)) != 0) return comp;
        }
        if (action->action_OneExpr[POST_ACTION] != NULL) {
          return action->action_OneExpr[POST_ACTION](x, y);
        }
        break;
      case doggy_MoreExprs_kind:
        if (action->action_MoreExprs[PRE_ACTION] != NULL) {
          return action->action_MoreExprs[PRE_ACTION](x, y);
        }
        if (!action->skip_children_MoreExprs) {
          if ((comp = Traverse_compare_List_doggy_Expr (doggy_MoreExprs_exprs(x),doggy_MoreExprs_exprs(y), action)) != 0) return comp;
        }
        if (action->action_MoreExprs[POST_ACTION] != NULL) {
          return action->action_MoreExprs[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Wherepart (doggy_Wherepart x, doggy_Wherepart y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Wherepart[PRE_ACTION] != NULL) {
    return action->action_Wherepart[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Wherepart) {
    if ((comp = Traverse_compare_List_doggy_Definition (doggy_Wherepart_defs(x),doggy_Wherepart_defs(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Applied_operation (doggy_Applied_operation x, doggy_Applied_operation y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Applied_operation[PRE_ACTION] != NULL) {
    return action->action_Applied_operation[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Applied_operation_tag(x) < doggy_Applied_operation_tag(y)) return -1;
  if (doggy_Applied_operation_tag(x) > doggy_Applied_operation_tag(y)) return 1;;
  switch (doggy_Applied_operation_tag(x)) {
      case doggy_AnyOp_kind:
        if (action->action_AnyOp[PRE_ACTION] != NULL) {
          return action->action_AnyOp[PRE_ACTION](x, y);
        }
        if (action->action_AnyOp[POST_ACTION] != NULL) {
          return action->action_AnyOp[POST_ACTION](x, y);
        }
        break;
      case doggy_AppliedOp_kind:
        if (action->action_AppliedOp[PRE_ACTION] != NULL) {
          return action->action_AppliedOp[PRE_ACTION](x, y);
        }
        if (!action->skip_children_AppliedOp) {
          if ((comp = Traverse_compare_doggy_Applied_formal (doggy_AppliedOp_op(x),doggy_AppliedOp_op(y), action)) != 0) return comp;
        }
        if (action->action_AppliedOp[POST_ACTION] != NULL) {
          return action->action_AppliedOp[POST_ACTION](x, y);
        }
        break;
      case doggy_OpSet_kind:
        if (action->action_OpSet[PRE_ACTION] != NULL) {
          return action->action_OpSet[PRE_ACTION](x, y);
        }
        if (!action->skip_children_OpSet) {
          if ((comp = Traverse_compare_List_doggy_Applied_formal (doggy_OpSet_ops(x),doggy_OpSet_ops(y), action)) != 0) return comp;
        }
        if (action->action_OpSet[POST_ACTION] != NULL) {
          return action->action_OpSet[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Applied_formal (doggy_Applied_formal x, doggy_Applied_formal y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Applied_formal[PRE_ACTION] != NULL) {
    return action->action_Applied_formal[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Applied_formal) {
    if ((comp = Traverse_compare_Ident (doggy_Applied_formal_id(x),doggy_Applied_formal_id(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Expr (doggy_Expr x, doggy_Expr y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Expr[PRE_ACTION] != NULL) {
    return action->action_Expr[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Expr_tag(x) < doggy_Expr_tag(y)) return -1;
  if (doggy_Expr_tag(x) > doggy_Expr_tag(y)) return 1;;
  switch (doggy_Expr_tag(x)) {
      case doggy_BinExpr_kind:
        if (action->action_BinExpr[PRE_ACTION] != NULL) {
          return action->action_BinExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_BinExpr) {
          if ((comp = Traverse_compare_List_doggy_Expr (doggy_BinExpr_args(x),doggy_BinExpr_args(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_doggy_Operator (doggy_BinExpr_ops(x),doggy_BinExpr_ops(y), action)) != 0) return comp;
        }
        if (action->action_BinExpr[POST_ACTION] != NULL) {
          return action->action_BinExpr[POST_ACTION](x, y);
        }
        break;
      case doggy_ConsExpr_kind:
        if (action->action_ConsExpr[PRE_ACTION] != NULL) {
          return action->action_ConsExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_ConsExpr) {
          if ((comp = Traverse_compare_doggy_Expr (doggy_ConsExpr_lhs(x),doggy_ConsExpr_lhs(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_Expr (doggy_ConsExpr_rhs(x),doggy_ConsExpr_rhs(y), action)) != 0) return comp;
        }
        if (action->action_ConsExpr[POST_ACTION] != NULL) {
          return action->action_ConsExpr[POST_ACTION](x, y);
        }
        break;
      case doggy_IdentExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_IdentExpr[PRE_ACTION] != NULL) {
          return action->action_IdentExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IdentExpr) {
          if ((comp = Traverse_compare_Ident (doggy_IdentExpr_id(x),doggy_IdentExpr_id(y), action)) != 0) return comp;
        }
        if (action->action_IdentExpr[POST_ACTION] != NULL) {
          return action->action_IdentExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case doggy_IfExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_IfExpr[PRE_ACTION] != NULL) {
          return action->action_IfExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IfExpr) {
          if ((comp = Traverse_compare_doggy_Expr (doggy_IfExpr_cond(x),doggy_IfExpr_cond(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_Expr (doggy_IfExpr_thn(x),doggy_IfExpr_thn(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_doggy_Expr (doggy_IfExpr_conds(x),doggy_IfExpr_conds(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_doggy_Expr (doggy_IfExpr_thens(x),doggy_IfExpr_thens(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_Expr (doggy_IfExpr_els(x),doggy_IfExpr_els(y), action)) != 0) return comp;
        }
        if (action->action_IfExpr[POST_ACTION] != NULL) {
          return action->action_IfExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case doggy_ConstExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_ConstExpr[PRE_ACTION] != NULL) {
          return action->action_ConstExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_ConstExpr) {
          if ((comp = Traverse_compare_doggy_Constant (doggy_ConstExpr_cnst(x),doggy_ConstExpr_cnst(y), action)) != 0) return comp;
        }
        if (action->action_ConstExpr[POST_ACTION] != NULL) {
          return action->action_ConstExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case doggy_Operation_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_Operation[PRE_ACTION] != NULL) {
          return action->action_Operation[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Operation) {
          if ((comp = Traverse_compare_Ident (doggy_Operation_id(x),doggy_Operation_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_doggy_Expr (doggy_Operation_args(x),doggy_Operation_args(y), action)) != 0) return comp;
        }
        if (action->action_Operation[POST_ACTION] != NULL) {
          return action->action_Operation[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case doggy_ParExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_ParExpr[PRE_ACTION] != NULL) {
          return action->action_ParExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_ParExpr) {
          if ((comp = Traverse_compare_doggy_Expr (doggy_ParExpr_expr(x),doggy_ParExpr_expr(y), action)) != 0) return comp;
        }
        if (action->action_ParExpr[POST_ACTION] != NULL) {
          return action->action_ParExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case doggy_MonExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_MonExpr[PRE_ACTION] != NULL) {
          return action->action_MonExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_MonExpr) {
          if ((comp = Traverse_compare_doggy_MonOp (doggy_MonExpr_op(x),doggy_MonExpr_op(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_Expr (doggy_MonExpr_arg(x),doggy_MonExpr_arg(y), action)) != 0) return comp;
        }
        if (action->action_MonExpr[POST_ACTION] != NULL) {
          return action->action_MonExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Constant (doggy_Constant x, doggy_Constant y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Constant[PRE_ACTION] != NULL) {
    return action->action_Constant[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Constant_tag(x) < doggy_Constant_tag(y)) return -1;
  if (doggy_Constant_tag(x) > doggy_Constant_tag(y)) return 1;;
  switch (doggy_Constant_tag(x)) {
      case doggy_IntConst_kind:
        if (action->action_IntConst[PRE_ACTION] != NULL) {
          return action->action_IntConst[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IntConst) {
          if ((comp = Traverse_compare_Int (doggy_IntConst_i(x),doggy_IntConst_i(y), action)) != 0) return comp;
        }
        if (action->action_IntConst[POST_ACTION] != NULL) {
          return action->action_IntConst[POST_ACTION](x, y);
        }
        break;
      case doggy_BoolConst_kind:
        if (action->action_BoolConst[PRE_ACTION] != NULL) {
          return action->action_BoolConst[PRE_ACTION](x, y);
        }
        if (!action->skip_children_BoolConst) {
          if ((comp = Traverse_compare_Bool (doggy_BoolConst_b(x),doggy_BoolConst_b(y), action)) != 0) return comp;
        }
        if (action->action_BoolConst[POST_ACTION] != NULL) {
          return action->action_BoolConst[POST_ACTION](x, y);
        }
        break;
      case doggy_StringConst_kind:
        if (action->action_StringConst[PRE_ACTION] != NULL) {
          return action->action_StringConst[PRE_ACTION](x, y);
        }
        if (!action->skip_children_StringConst) {
          if ((comp = Traverse_compare_String (doggy_StringConst_s(x),doggy_StringConst_s(y), action)) != 0) return comp;
        }
        if (action->action_StringConst[POST_ACTION] != NULL) {
          return action->action_StringConst[POST_ACTION](x, y);
        }
        break;
      case doggy_NullConst_kind:
        if (action->action_NullConst[PRE_ACTION] != NULL) {
          return action->action_NullConst[PRE_ACTION](x, y);
        }
        if (action->action_NullConst[POST_ACTION] != NULL) {
          return action->action_NullConst[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Definition (doggy_Definition x, doggy_Definition y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Definition[PRE_ACTION] != NULL) {
    return action->action_Definition[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Definition) {
    if ((comp = Traverse_compare_doggy_Type (doggy_Definition_type(x),doggy_Definition_type(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (doggy_Definition_id(x),doggy_Definition_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Expr (doggy_Definition_expr(x),doggy_Definition_expr(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Type (doggy_Type x, doggy_Type y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Type[PRE_ACTION] != NULL) {
    return action->action_Type[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Type_tag(x) < doggy_Type_tag(y)) return -1;
  if (doggy_Type_tag(x) > doggy_Type_tag(y)) return 1;;
  switch (doggy_Type_tag(x)) {
      case doggy_EdgeType_kind:
        if (action->action_EdgeType[PRE_ACTION] != NULL) {
          return action->action_EdgeType[PRE_ACTION](x, y);
        }
        if (!action->skip_children_EdgeType) {
          if ((comp = Traverse_compare_List_doggy_Type (doggy_EdgeType_types(x),doggy_EdgeType_types(y), action)) != 0) return comp;
        }
        if (action->action_EdgeType[POST_ACTION] != NULL) {
          return action->action_EdgeType[POST_ACTION](x, y);
        }
        break;
      case doggy_TupleType_kind:
        if (action->action_TupleType[PRE_ACTION] != NULL) {
          return action->action_TupleType[PRE_ACTION](x, y);
        }
        if (!action->skip_children_TupleType) {
          if ((comp = Traverse_compare_List_doggy_Type (doggy_TupleType_types(x),doggy_TupleType_types(y), action)) != 0) return comp;
        }
        if (action->action_TupleType[POST_ACTION] != NULL) {
          return action->action_TupleType[POST_ACTION](x, y);
        }
        break;
      case doggy_IdentType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          return action->action_BasicType[PRE_ACTION](x, y);
        }
        if (action->action_IdentType[PRE_ACTION] != NULL) {
          return action->action_IdentType[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IdentType) {
          if ((comp = Traverse_compare_Ident (doggy_IdentType_type_id(x),doggy_IdentType_type_id(y), action)) != 0) return comp;
        }
        if (action->action_IdentType[POST_ACTION] != NULL) {
          return action->action_IdentType[POST_ACTION](x, y);
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          return action->action_BasicType[POST_ACTION](x, y);
        }
        break;
      case doggy_OprType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          return action->action_BasicType[PRE_ACTION](x, y);
        }
        if (action->action_OprType[PRE_ACTION] != NULL) {
          return action->action_OprType[PRE_ACTION](x, y);
        }
        if (!action->skip_children_OprType) {
          if ((comp = Traverse_compare_List_doggy_Type (doggy_OprType_args(x),doggy_OprType_args(y), action)) != 0) return comp;
        }
        if (action->action_OprType[POST_ACTION] != NULL) {
          return action->action_OprType[POST_ACTION](x, y);
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          return action->action_BasicType[POST_ACTION](x, y);
        }
        break;
      case doggy_PointerType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          return action->action_BasicType[PRE_ACTION](x, y);
        }
        if (action->action_PointerType[PRE_ACTION] != NULL) {
          return action->action_PointerType[PRE_ACTION](x, y);
        }
        if (!action->skip_children_PointerType) {
          if ((comp = Traverse_compare_doggy_Type (doggy_PointerType_base(x),doggy_PointerType_base(y), action)) != 0) return comp;
        }
        if (action->action_PointerType[POST_ACTION] != NULL) {
          return action->action_PointerType[POST_ACTION](x, y);
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          return action->action_BasicType[POST_ACTION](x, y);
        }
        break;
      case doggy_RangeType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          return action->action_BasicType[PRE_ACTION](x, y);
        }
        if (action->action_RangeType[PRE_ACTION] != NULL) {
          return action->action_RangeType[PRE_ACTION](x, y);
        }
        if (!action->skip_children_RangeType) {
          if ((comp = Traverse_compare_doggy_Num (doggy_RangeType_lo(x),doggy_RangeType_lo(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_Num (doggy_RangeType_hi(x),doggy_RangeType_hi(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_doggy_Num (doggy_RangeType_step(x),doggy_RangeType_step(y), action)) != 0) return comp;
        }
        if (action->action_RangeType[POST_ACTION] != NULL) {
          return action->action_RangeType[POST_ACTION](x, y);
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          return action->action_BasicType[POST_ACTION](x, y);
        }
        break;
      case doggy_FRangeType_kind:
        if (action->action_BasicType[PRE_ACTION] != NULL) {
          return action->action_BasicType[PRE_ACTION](x, y);
        }
        if (action->action_FRangeType[PRE_ACTION] != NULL) {
          return action->action_FRangeType[PRE_ACTION](x, y);
        }
        if (!action->skip_children_FRangeType) {
          if ((comp = Traverse_compare_Ident (doggy_FRangeType_f(x),doggy_FRangeType_f(y), action)) != 0) return comp;
        }
        if (action->action_FRangeType[POST_ACTION] != NULL) {
          return action->action_FRangeType[POST_ACTION](x, y);
        }
        if (action->action_BasicType[POST_ACTION] != NULL) {
          return action->action_BasicType[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Num (doggy_Num x, doggy_Num y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Num[PRE_ACTION] != NULL) {
    return action->action_Num[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Num) {
    if ((comp = Traverse_compare_Bool (doggy_Num_neg(x),doggy_Num_neg(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Int (doggy_Num_i(x),doggy_Num_i(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_IdInt (doggy_IdInt x, doggy_IdInt y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_IdInt[PRE_ACTION] != NULL) {
    return action->action_IdInt[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_IdInt_tag(x) < doggy_IdInt_tag(y)) return -1;
  if (doggy_IdInt_tag(x) > doggy_IdInt_tag(y)) return 1;;
  switch (doggy_IdInt_tag(x)) {
      case doggy_IsId_kind:
        if (action->action_IsId[PRE_ACTION] != NULL) {
          return action->action_IsId[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IsId) {
          if ((comp = Traverse_compare_Ident (doggy_IsId_id(x),doggy_IsId_id(y), action)) != 0) return comp;
        }
        if (action->action_IsId[POST_ACTION] != NULL) {
          return action->action_IsId[POST_ACTION](x, y);
        }
        break;
      case doggy_IsInt_kind:
        if (action->action_IsInt[PRE_ACTION] != NULL) {
          return action->action_IsInt[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IsInt) {
          if ((comp = Traverse_compare_Int (doggy_IsInt_i(x),doggy_IsInt_i(y), action)) != 0) return comp;
        }
        if (action->action_IsInt[POST_ACTION] != NULL) {
          return action->action_IsInt[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_doggy_Path (doggy_Path x, doggy_Path y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Path[PRE_ACTION] != NULL) {
    return action->action_Path[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Path) {
    if ((comp = Traverse_compare_Int (doggy_Path_data(x),doggy_Path_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Type (doggy_Path_type(x),doggy_Path_type(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Path (doggy_Path_next(x),doggy_Path_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_ActualOp (doggy_ActualOp x, doggy_ActualOp y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_ActualOp[PRE_ACTION] != NULL) {
    return action->action_ActualOp[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_ActualOp) {
    if ((comp = Traverse_compare_Int (doggy_ActualOp_location(x),doggy_ActualOp_location(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (doggy_ActualOp_id(x),doggy_ActualOp_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Operation_def (doggy_ActualOp_formals(x),doggy_ActualOp_formals(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_TypePair (doggy_TypePair x, doggy_TypePair y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_TypePair[PRE_ACTION] != NULL) {
    return action->action_TypePair[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_TypePair) {
    if ((comp = Traverse_compare_doggy_Type (doggy_TypePair_t1(x),doggy_TypePair_t1(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Type (doggy_TypePair_t2(x),doggy_TypePair_t2(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Opat (doggy_Opat x, doggy_Opat y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Opat[PRE_ACTION] != NULL) {
    return action->action_Opat[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Opat) {
    if ((comp = Traverse_compare_List_doggy_Type (doggy_Opat_args(x),doggy_Opat_args(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Type (doggy_Opat_result(x),doggy_Opat_result(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Format (doggy_Format x, doggy_Format y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Format[PRE_ACTION] != NULL) {
    return action->action_Format[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Format) {
    if ((comp = Traverse_compare_List_doggy_Type (doggy_Format_args(x),doggy_Format_args(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_doggy_Type (doggy_Format_result(x),doggy_Format_result(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Bool (doggy_Format_swap(x),doggy_Format_swap(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_dummy_type (doggy_dummy_type x, doggy_dummy_type y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_dummy_type[PRE_ACTION] != NULL) {
    return action->action_dummy_type[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_dummy_type) {
    if ((comp = Traverse_compare_List_Ident (doggy_dummy_type_a(x),doggy_dummy_type_a(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_ActualOp (doggy_dummy_type_y(x),doggy_dummy_type_y(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_TypePair (doggy_dummy_type_z(x),doggy_dummy_type_z(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Scope (doggy_Scope x, doggy_Scope y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    return action->action_Scope[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (doggy_Scope_tag(x) < doggy_Scope_tag(y)) return -1;
  if (doggy_Scope_tag(x) > doggy_Scope_tag(y)) return 1;;
  switch (doggy_Scope_tag(x)) {
      case doggy_OpSetScope_kind:
        if (action->action_OpSetScope[PRE_ACTION] != NULL) {
          return action->action_OpSetScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Scope) {
          if ((comp = Traverse_compare_doggy_Scope (doggy_Scope_next(x),doggy_Scope_next(y), action)) != 0) return comp;
        }
        if (!action->skip_children_OpSetScope) {
          if ((comp = Traverse_compare_doggy_Applied_operation (doggy_OpSetScope_data(x),doggy_OpSetScope_data(y), action)) != 0) return comp;
        }
        if (action->action_OpSetScope[POST_ACTION] != NULL) {
          return action->action_OpSetScope[POST_ACTION](x, y);
        }
        break;
      case doggy_AppliedOpScope_kind:
        if (action->action_AppliedOpScope[PRE_ACTION] != NULL) {
          return action->action_AppliedOpScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Scope) {
          if ((comp = Traverse_compare_doggy_Scope (doggy_Scope_next(x),doggy_Scope_next(y), action)) != 0) return comp;
        }
        if (!action->skip_children_AppliedOpScope) {
          if ((comp = Traverse_compare_doggy_Applied_operation (doggy_AppliedOpScope_data(x),doggy_AppliedOpScope_data(y), action)) != 0) return comp;
        }
        if (action->action_AppliedOpScope[POST_ACTION] != NULL) {
          return action->action_AppliedOpScope[POST_ACTION](x, y);
        }
        break;
      case doggy_ExprGuardScope_kind:
        if (action->action_ExprGuardScope[PRE_ACTION] != NULL) {
          return action->action_ExprGuardScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Scope) {
          if ((comp = Traverse_compare_doggy_Scope (doggy_Scope_next(x),doggy_Scope_next(y), action)) != 0) return comp;
        }
        if (!action->skip_children_ExprGuardScope) {
          if ((comp = Traverse_compare_doggy_Guard (doggy_ExprGuardScope_data(x),doggy_ExprGuardScope_data(y), action)) != 0) return comp;
        }
        if (action->action_ExprGuardScope[POST_ACTION] != NULL) {
          return action->action_ExprGuardScope[POST_ACTION](x, y);
        }
        break;
      case doggy_RhsGuardScope_kind:
        if (action->action_RhsGuardScope[PRE_ACTION] != NULL) {
          return action->action_RhsGuardScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Scope) {
          if ((comp = Traverse_compare_doggy_Scope (doggy_Scope_next(x),doggy_Scope_next(y), action)) != 0) return comp;
        }
        if (!action->skip_children_RhsGuardScope) {
          if ((comp = Traverse_compare_doggy_Guard (doggy_RhsGuardScope_data(x),doggy_RhsGuardScope_data(y), action)) != 0) return comp;
        }
        if (action->action_RhsGuardScope[POST_ACTION] != NULL) {
          return action->action_RhsGuardScope[POST_ACTION](x, y);
        }
        break;
      case doggy_FuncRuleScope_kind:
        if (action->action_FuncRuleScope[PRE_ACTION] != NULL) {
          return action->action_FuncRuleScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Scope) {
          if ((comp = Traverse_compare_doggy_Scope (doggy_Scope_next(x),doggy_Scope_next(y), action)) != 0) return comp;
        }
        if (!action->skip_children_FuncRuleScope) {
          if ((comp = Traverse_compare_doggy_FuncRule (doggy_FuncRuleScope_data(x),doggy_FuncRuleScope_data(y), action)) != 0) return comp;
        }
        if (action->action_FuncRuleScope[POST_ACTION] != NULL) {
          return action->action_FuncRuleScope[POST_ACTION](x, y);
        }
        break;
      case doggy_RuleScope_kind:
        if (action->action_RuleScope[PRE_ACTION] != NULL) {
          return action->action_RuleScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Scope) {
          if ((comp = Traverse_compare_doggy_Scope (doggy_Scope_next(x),doggy_Scope_next(y), action)) != 0) return comp;
        }
        if (!action->skip_children_RuleScope) {
          if ((comp = Traverse_compare_doggy_Rule (doggy_RuleScope_data(x),doggy_RuleScope_data(y), action)) != 0) return comp;
        }
        if (action->action_RuleScope[POST_ACTION] != NULL) {
          return action->action_RuleScope[POST_ACTION](x, y);
        }
        break;
      case doggy_machine_descriptionScope_kind:
        if (action->action_machine_descriptionScope[PRE_ACTION] != NULL) {
          return action->action_machine_descriptionScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Scope) {
          if ((comp = Traverse_compare_doggy_Scope (doggy_Scope_next(x),doggy_Scope_next(y), action)) != 0) return comp;
        }
        if (!action->skip_children_machine_descriptionScope) {
          if ((comp = Traverse_compare_doggy_machine_description (doggy_machine_descriptionScope_data(x),doggy_machine_descriptionScope_data(y), action)) != 0) return comp;
        }
        if (action->action_machine_descriptionScope[POST_ACTION] != NULL) {
          return action->action_machine_descriptionScope[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_List_doggy_Num (List_doggy_Num x, List_doggy_Num y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Num[PRE_ACTION] != NULL) {
    return action->action_List_Num[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Num) {
    if ((comp = Traverse_compare_doggy_Num (List_doggy_Num_data(x),List_doggy_Num_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Num (List_doggy_Num_next(x),List_doggy_Num_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_List_doggy_TypePair (List_List_doggy_TypePair x, List_List_doggy_TypePair y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_List_TypePair[PRE_ACTION] != NULL) {
    return action->action_List_List_TypePair[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_List_TypePair) {
    if ((comp = Traverse_compare_List_doggy_TypePair (List_List_doggy_TypePair_data(x),List_List_doggy_TypePair_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_List_doggy_TypePair (List_List_doggy_TypePair_next(x),List_List_doggy_TypePair_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_TypePair (List_doggy_TypePair x, List_doggy_TypePair y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_TypePair[PRE_ACTION] != NULL) {
    return action->action_List_TypePair[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_TypePair) {
    if ((comp = Traverse_compare_doggy_TypePair (List_doggy_TypePair_data(x),List_doggy_TypePair_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_TypePair (List_doggy_TypePair_next(x),List_doggy_TypePair_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_ActualOp (List_doggy_ActualOp x, List_doggy_ActualOp y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_ActualOp[PRE_ACTION] != NULL) {
    return action->action_List_ActualOp[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_ActualOp) {
    if ((comp = Traverse_compare_doggy_ActualOp (List_doggy_ActualOp_data(x),List_doggy_ActualOp_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_ActualOp (List_doggy_ActualOp_next(x),List_doggy_ActualOp_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_List_doggy_Type (List_List_doggy_Type x, List_List_doggy_Type y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_List_Type[PRE_ACTION] != NULL) {
    return action->action_List_List_Type[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_List_Type) {
    if ((comp = Traverse_compare_List_doggy_Type (List_List_doggy_Type_data(x),List_List_doggy_Type_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_List_doggy_Type (List_List_doggy_Type_next(x),List_List_doggy_Type_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Operator (List_doggy_Operator x, List_doggy_Operator y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Operator[PRE_ACTION] != NULL) {
    return action->action_List_Operator[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Operator) {
    if ((comp = Traverse_compare_doggy_Operator (List_doggy_Operator_data(x),List_doggy_Operator_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Operator (List_doggy_Operator_next(x),List_doggy_Operator_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Definition (List_doggy_Definition x, List_doggy_Definition y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Definition[PRE_ACTION] != NULL) {
    return action->action_List_Definition[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Definition) {
    if ((comp = Traverse_compare_doggy_Definition (List_doggy_Definition_data(x),List_doggy_Definition_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Definition (List_doggy_Definition_next(x),List_doggy_Definition_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Expr (List_doggy_Expr x, List_doggy_Expr y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Expr[PRE_ACTION] != NULL) {
    return action->action_List_Expr[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Expr) {
    if ((comp = Traverse_compare_doggy_Expr (List_doggy_Expr_data(x),List_doggy_Expr_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Expr (List_doggy_Expr_next(x),List_doggy_Expr_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Guard (List_doggy_Guard x, List_doggy_Guard y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Guard[PRE_ACTION] != NULL) {
    return action->action_List_Guard[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Guard) {
    if ((comp = Traverse_compare_doggy_Guard (List_doggy_Guard_data(x),List_doggy_Guard_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Guard (List_doggy_Guard_next(x),List_doggy_Guard_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Pattern (List_doggy_Pattern x, List_doggy_Pattern y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Pattern[PRE_ACTION] != NULL) {
    return action->action_List_Pattern[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Pattern) {
    if ((comp = Traverse_compare_doggy_Pattern (List_doggy_Pattern_data(x),List_doggy_Pattern_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Pattern (List_doggy_Pattern_next(x),List_doggy_Pattern_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Argument (List_doggy_Argument x, List_doggy_Argument y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Argument[PRE_ACTION] != NULL) {
    return action->action_List_Argument[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Argument) {
    if ((comp = Traverse_compare_doggy_Argument (List_doggy_Argument_data(x),List_doggy_Argument_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Argument (List_doggy_Argument_next(x),List_doggy_Argument_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_FuncRule (List_doggy_FuncRule x, List_doggy_FuncRule y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_FuncRule[PRE_ACTION] != NULL) {
    return action->action_List_FuncRule[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_FuncRule) {
    if ((comp = Traverse_compare_doggy_FuncRule (List_doggy_FuncRule_data(x),List_doggy_FuncRule_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_FuncRule (List_doggy_FuncRule_next(x),List_doggy_FuncRule_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Attribute (List_doggy_Attribute x, List_doggy_Attribute y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Attribute[PRE_ACTION] != NULL) {
    return action->action_List_Attribute[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Attribute) {
    if ((comp = Traverse_compare_doggy_Attribute (List_doggy_Attribute_data(x),List_doggy_Attribute_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Attribute (List_doggy_Attribute_next(x),List_doggy_Attribute_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Property (List_doggy_Property x, List_doggy_Property y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Property[PRE_ACTION] != NULL) {
    return action->action_List_Property[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Property) {
    if ((comp = Traverse_compare_doggy_Property (List_doggy_Property_data(x),List_doggy_Property_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Property (List_doggy_Property_next(x),List_doggy_Property_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Applied_formal (List_doggy_Applied_formal x, List_doggy_Applied_formal y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Applied_formal[PRE_ACTION] != NULL) {
    return action->action_List_Applied_formal[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Applied_formal) {
    if ((comp = Traverse_compare_doggy_Applied_formal (List_doggy_Applied_formal_data(x),List_doggy_Applied_formal_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Applied_formal (List_doggy_Applied_formal_next(x),List_doggy_Applied_formal_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Operation_def (List_doggy_Operation_def x, List_doggy_Operation_def y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Operation_def[PRE_ACTION] != NULL) {
    return action->action_List_Operation_def[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Operation_def) {
    if ((comp = Traverse_compare_doggy_Operation_def (List_doggy_Operation_def_data(x),List_doggy_Operation_def_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Operation_def (List_doggy_Operation_def_next(x),List_doggy_Operation_def_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Type (List_doggy_Type x, List_doggy_Type y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Type[PRE_ACTION] != NULL) {
    return action->action_List_Type[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Type) {
    if ((comp = Traverse_compare_doggy_Type (List_doggy_Type_data(x),List_doggy_Type_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Type (List_doggy_Type_next(x),List_doggy_Type_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Rule (List_doggy_Rule x, List_doggy_Rule y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Rule[PRE_ACTION] != NULL) {
    return action->action_List_Rule[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Rule) {
    if ((comp = Traverse_compare_doggy_Rule (List_doggy_Rule_data(x),List_doggy_Rule_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Rule (List_doggy_Rule_next(x),List_doggy_Rule_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Func (List_doggy_Func x, List_doggy_Func y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Func[PRE_ACTION] != NULL) {
    return action->action_List_Func[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Func) {
    if ((comp = Traverse_compare_doggy_Func (List_doggy_Func_data(x),List_doggy_Func_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Func (List_doggy_Func_next(x),List_doggy_Func_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Section (List_doggy_Section x, List_doggy_Section y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Section[PRE_ACTION] != NULL) {
    return action->action_List_Section[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Section) {
    if ((comp = Traverse_compare_doggy_Section (List_doggy_Section_data(x),List_doggy_Section_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Section (List_doggy_Section_next(x),List_doggy_Section_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_FunctionDef (List_doggy_FunctionDef x, List_doggy_FunctionDef y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_FunctionDef[PRE_ACTION] != NULL) {
    return action->action_List_FunctionDef[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_FunctionDef) {
    if ((comp = Traverse_compare_doggy_FunctionDef (List_doggy_FunctionDef_data(x),List_doggy_FunctionDef_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_FunctionDef (List_doggy_FunctionDef_next(x),List_doggy_FunctionDef_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_doggy_Typedef (List_doggy_Typedef x, List_doggy_Typedef y, compare_doggy_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Typedef[PRE_ACTION] != NULL) {
    return action->action_List_Typedef[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Typedef) {
    if ((comp = Traverse_compare_doggy_Typedef (List_doggy_Typedef_data(x),List_doggy_Typedef_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_doggy_Typedef (List_doggy_Typedef_next(x),List_doggy_Typedef_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_doggy_Operator (doggy_Operator x, doggy_Operator y, compare_doggy_TraverseTable action)
{ if (action->action_Operator[PRE_ACTION] != NULL) {
    return action->action_Operator[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

int Traverse_compare_doggy_MonOp (doggy_MonOp x, doggy_MonOp y, compare_doggy_TraverseTable action)
{ if (action->action_MonOp[PRE_ACTION] != NULL) {
    return action->action_MonOp[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

int Traverse_compare_doggy_Property (doggy_Property x, doggy_Property y, compare_doggy_TraverseTable action)
{ if (action->action_Property[PRE_ACTION] != NULL) {
    return action->action_Property[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

static void* PushScope_doggy_Typedef (doggy_Typedef me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Typedef_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_ExtFunc (doggy_ExtFunc me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_FunctionDef_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_ExtVar (doggy_ExtVar me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_FunctionDef_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_machine_description (doggy_machine_description me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  if (doggy_machine_description_scope(me) != NULL &&
      doggy_Scope_next(doggy_machine_description_scope(me))==(doggy_Scope)val &&
      machine_descriptionScope_data(doggy_machine_description_scope(me)) == me)
       val = doggy_machine_description_scope(me);
  else {
    val = (void*)Create_machine_descriptionScope ((doggy_Scope)val, me);
  }
  doggy_machine_description_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PopScope_doggy_machine_description (doggy_machine_description me, void *val)
{ if (me == NULL) return val;
  val = (void*)me->old_scope;
  return val;
}

static void* PushScope_doggy_Operation_def (doggy_Operation_def me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Operation_def_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_Rule (doggy_Rule me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  if (doggy_Rule_scope(me) != NULL &&
      doggy_Scope_next(doggy_Rule_scope(me))==(doggy_Scope)val &&
      RuleScope_data(doggy_Rule_scope(me)) == me)
       val = doggy_Rule_scope(me);
  else {
    val = (void*)Create_RuleScope ((doggy_Scope)val, me);
  }
  doggy_Rule_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PopScope_doggy_Rule (doggy_Rule me, void *val)
{ if (me == NULL) return val;
  val = (void*)me->old_scope;
  return val;
}

static void* PushScope_doggy_Func (doggy_Func me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Func_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_FuncRule (doggy_FuncRule me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  if (doggy_FuncRule_scope(me) != NULL &&
      doggy_Scope_next(doggy_FuncRule_scope(me))==(doggy_Scope)val &&
      FuncRuleScope_data(doggy_FuncRule_scope(me)) == me)
       val = doggy_FuncRule_scope(me);
  else {
    val = (void*)Create_FuncRuleScope ((doggy_Scope)val, me);
  }
  doggy_FuncRule_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PopScope_doggy_FuncRule (doggy_FuncRule me, void *val)
{ if (me == NULL) return val;
  val = (void*)me->old_scope;
  return val;
}

static void* PushScope_doggy_TypedArg (doggy_TypedArg me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Argument_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_UnTypedArg (doggy_UnTypedArg me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Argument_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_TypedPattern (doggy_TypedPattern me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Pattern_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_ConsPattern (doggy_ConsPattern me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Pattern_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_DefPattern (doggy_DefPattern me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Pattern_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_IdentPattern (doggy_IdentPattern me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Pattern_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_OpPattern (doggy_OpPattern me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Pattern_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_ConstPattern (doggy_ConstPattern me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Pattern_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_NullPattern (doggy_NullPattern me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Pattern_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_DontCarePattern (doggy_DontCarePattern me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Pattern_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_RhsGuard (doggy_RhsGuard me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  if (doggy_Guard_scope(me) != NULL &&
      doggy_Scope_next(doggy_Guard_scope(me))==(doggy_Scope)val &&
      RhsGuardScope_data(doggy_Guard_scope(me)) == me)
       val = doggy_Guard_scope(me);
  else {
    val = (void*)Create_RhsGuardScope ((doggy_Scope)val, me);
  }
  doggy_Guard_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PopScope_doggy_RhsGuard (doggy_RhsGuard me, void *val)
{ if (me == NULL) return val;
  val = (void*)me->old_scope;
  return val;
}

static void* PushScope_doggy_ExprGuard (doggy_ExprGuard me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  if (doggy_Guard_scope(me) != NULL &&
      doggy_Scope_next(doggy_Guard_scope(me))==(doggy_Scope)val &&
      ExprGuardScope_data(doggy_Guard_scope(me)) == me)
       val = doggy_Guard_scope(me);
  else {
    val = (void*)Create_ExprGuardScope ((doggy_Scope)val, me);
  }
  doggy_Guard_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PopScope_doggy_ExprGuard (doggy_ExprGuard me, void *val)
{ if (me == NULL) return val;
  val = (void*)me->old_scope;
  return val;
}

static void* PushScope_doggy_AnyOp (doggy_AnyOp me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Applied_operation_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_AppliedOp (doggy_AppliedOp me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  if (doggy_Applied_operation_scope(me) != NULL &&
      doggy_Scope_next(doggy_Applied_operation_scope(me))==(doggy_Scope)val &&
      AppliedOpScope_data(doggy_Applied_operation_scope(me)) == me)
       val = doggy_Applied_operation_scope(me);
  else {
    val = (void*)Create_AppliedOpScope ((doggy_Scope)val, me);
  }
  doggy_Applied_operation_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PopScope_doggy_AppliedOp (doggy_AppliedOp me, void *val)
{ if (me == NULL) return val;
  val = (void*)me->old_scope;
  return val;
}

static void* PushScope_doggy_OpSet (doggy_OpSet me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  if (doggy_Applied_operation_scope(me) != NULL &&
      doggy_Scope_next(doggy_Applied_operation_scope(me))==(doggy_Scope)val &&
      OpSetScope_data(doggy_Applied_operation_scope(me)) == me)
       val = doggy_Applied_operation_scope(me);
  else {
    val = (void*)Create_OpSetScope ((doggy_Scope)val, me);
  }
  doggy_Applied_operation_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PopScope_doggy_OpSet (doggy_OpSet me, void *val)
{ if (me == NULL) return val;
  val = (void*)me->old_scope;
  return val;
}

static void* PushScope_doggy_Applied_formal (doggy_Applied_formal me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Applied_formal_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_BinExpr (doggy_BinExpr me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Expr_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_ConsExpr (doggy_ConsExpr me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Expr_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_IdentExpr (doggy_IdentExpr me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Expr_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_IfExpr (doggy_IfExpr me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Expr_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_ConstExpr (doggy_ConstExpr me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Expr_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_Operation (doggy_Operation me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Expr_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_ParExpr (doggy_ParExpr me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Expr_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_MonExpr (doggy_MonExpr me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Expr_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_Definition (doggy_Definition me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Definition_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_EdgeType (doggy_EdgeType me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Type_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_TupleType (doggy_TupleType me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Type_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_IdentType (doggy_IdentType me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Type_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_OprType (doggy_OprType me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Type_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_PointerType (doggy_PointerType me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Type_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_RangeType (doggy_RangeType me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Type_scope(me) = (doggy_Scope) val;
  return val;
}

static void* PushScope_doggy_FRangeType (doggy_FRangeType me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (doggy_Scope) val;
  doggy_Type_scope(me) = (doggy_Scope) val;
  return val;
}

struct s_doggy_TraverseTable doggy_scope_actions = {

  Traverse_Accumulate,
  { NULL,	NULL }, FALSE,	/* doggy_doggy */
  { NULL,	PushScope_doggy_Typedef }, FALSE,	/* doggy_Typedef */
  { NULL,	NULL }, FALSE,	/* doggy_FunctionDef */
  { NULL,	PushScope_doggy_ExtFunc }, FALSE,	/* doggy_ExtFunc */
  { NULL,	PushScope_doggy_ExtVar }, FALSE,	/* doggy_ExtVar */
  { PopScope_doggy_machine_description,	PushScope_doggy_machine_description }, FALSE,	/* doggy_machine_description */
  { NULL,	PushScope_doggy_Operation_def }, FALSE,	/* doggy_Operation_def */
  { NULL,	NULL }, FALSE,	/* doggy_Attributes */
  { NULL,	NULL }, FALSE,	/* doggy_Attribute */
  { NULL,	NULL }, FALSE,	/* doggy_IdAttr */
  { NULL,	NULL }, FALSE,	/* doggy_OpAttr */
  { NULL,	NULL }, FALSE,	/* doggy_IntAttr */
  { NULL,	NULL }, FALSE,	/* doggy_Section */
  { NULL,	NULL }, FALSE,	/* doggy_FuncSection */
  { NULL,	NULL }, FALSE,	/* doggy_RuleSection */
  { PopScope_doggy_Rule,	PushScope_doggy_Rule }, FALSE,	/* doggy_Rule */
  { NULL,	NULL }, FALSE,	/* doggy_Lhs */
  { NULL,	NULL }, FALSE,	/* doggy_LabeledLhs */
  { NULL,	NULL }, FALSE,	/* doggy_UnLabeledLhs */
  { NULL,	PushScope_doggy_Func }, FALSE,	/* doggy_Func */
  { PopScope_doggy_FuncRule,	PushScope_doggy_FuncRule }, FALSE,	/* doggy_FuncRule */
  { NULL,	NULL }, FALSE,	/* doggy_Argument */
  { NULL,	PushScope_doggy_TypedArg }, FALSE,	/* doggy_TypedArg */
  { NULL,	PushScope_doggy_UnTypedArg }, FALSE,	/* doggy_UnTypedArg */
  { NULL,	NULL }, FALSE,	/* doggy_ArgPat */
  { NULL,	NULL }, FALSE,	/* doggy_PatArg */
  { NULL,	NULL }, FALSE,	/* doggy_SetArg */
  { NULL,	NULL }, FALSE,	/* doggy_Pattern */
  { NULL,	PushScope_doggy_TypedPattern }, FALSE,	/* doggy_TypedPattern */
  { NULL,	PushScope_doggy_ConsPattern }, FALSE,	/* doggy_ConsPattern */
  { NULL,	PushScope_doggy_DefPattern }, FALSE,	/* doggy_DefPattern */
  { NULL,	PushScope_doggy_IdentPattern }, FALSE,	/* doggy_IdentPattern */
  { NULL,	NULL }, FALSE,	/* doggy_BasicPattern */
  { NULL,	PushScope_doggy_OpPattern }, FALSE,	/* doggy_OpPattern */
  { NULL,	PushScope_doggy_ConstPattern }, FALSE,	/* doggy_ConstPattern */
  { NULL,	PushScope_doggy_NullPattern }, FALSE,	/* doggy_NullPattern */
  { NULL,	PushScope_doggy_DontCarePattern }, FALSE,	/* doggy_DontCarePattern */
  { NULL,	NULL }, FALSE,	/* doggy_Rhs */
  { NULL,	NULL }, FALSE,	/* doggy_PlainRhs */
  { NULL,	NULL }, FALSE,	/* doggy_BlockRhs */
  { NULL,	NULL }, FALSE,	/* doggy_Guard */
  { PopScope_doggy_RhsGuard,	PushScope_doggy_RhsGuard }, FALSE,	/* doggy_RhsGuard */
  { PopScope_doggy_ExprGuard,	PushScope_doggy_ExprGuard }, FALSE,	/* doggy_ExprGuard */
  { NULL,	NULL }, FALSE,	/* doggy_ExprSeq */
  { NULL,	NULL }, FALSE,	/* doggy_OneExpr */
  { NULL,	NULL }, FALSE,	/* doggy_MoreExprs */
  { NULL,	NULL }, FALSE,	/* doggy_Wherepart */
  { NULL,	NULL }, FALSE,	/* doggy_Applied_operation */
  { NULL,	PushScope_doggy_AnyOp }, FALSE,	/* doggy_AnyOp */
  { PopScope_doggy_AppliedOp,	PushScope_doggy_AppliedOp }, FALSE,	/* doggy_AppliedOp */
  { PopScope_doggy_OpSet,	PushScope_doggy_OpSet }, FALSE,	/* doggy_OpSet */
  { NULL,	PushScope_doggy_Applied_formal }, FALSE,	/* doggy_Applied_formal */
  { NULL,	NULL }, FALSE,	/* doggy_Expr */
  { NULL,	PushScope_doggy_BinExpr }, FALSE,	/* doggy_BinExpr */
  { NULL,	PushScope_doggy_ConsExpr }, FALSE,	/* doggy_ConsExpr */
  { NULL,	NULL }, FALSE,	/* doggy_SimpleExpr */
  { NULL,	PushScope_doggy_IdentExpr }, FALSE,	/* doggy_IdentExpr */
  { NULL,	PushScope_doggy_IfExpr }, FALSE,	/* doggy_IfExpr */
  { NULL,	PushScope_doggy_ConstExpr }, FALSE,	/* doggy_ConstExpr */
  { NULL,	PushScope_doggy_Operation }, FALSE,	/* doggy_Operation */
  { NULL,	PushScope_doggy_ParExpr }, FALSE,	/* doggy_ParExpr */
  { NULL,	PushScope_doggy_MonExpr }, FALSE,	/* doggy_MonExpr */
  { NULL,	NULL }, FALSE,	/* doggy_Constant */
  { NULL,	NULL }, FALSE,	/* doggy_IntConst */
  { NULL,	NULL }, FALSE,	/* doggy_BoolConst */
  { NULL,	NULL }, FALSE,	/* doggy_StringConst */
  { NULL,	NULL }, FALSE,	/* doggy_NullConst */
  { NULL,	PushScope_doggy_Definition }, FALSE,	/* doggy_Definition */
  { NULL,	NULL }, FALSE,	/* doggy_Type */
  { NULL,	PushScope_doggy_EdgeType }, FALSE,	/* doggy_EdgeType */
  { NULL,	PushScope_doggy_TupleType }, FALSE,	/* doggy_TupleType */
  { NULL,	NULL }, FALSE,	/* doggy_BasicType */
  { NULL,	PushScope_doggy_IdentType }, FALSE,	/* doggy_IdentType */
  { NULL,	PushScope_doggy_OprType }, FALSE,	/* doggy_OprType */
  { NULL,	PushScope_doggy_PointerType }, FALSE,	/* doggy_PointerType */
  { NULL,	PushScope_doggy_RangeType }, FALSE,	/* doggy_RangeType */
  { NULL,	PushScope_doggy_FRangeType }, FALSE,	/* doggy_FRangeType */
  { NULL,	NULL }, FALSE,	/* doggy_Num */
  { NULL,	NULL }, FALSE,	/* doggy_IdInt */
  { NULL,	NULL }, FALSE,	/* doggy_IsId */
  { NULL,	NULL }, FALSE,	/* doggy_IsInt */
  { NULL,	NULL }, FALSE,	/* doggy_Path */
  { NULL,	NULL }, FALSE,	/* doggy_ActualOp */
  { NULL,	NULL }, FALSE,	/* doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* doggy_Opat */
  { NULL,	NULL }, FALSE,	/* doggy_Format */
  { NULL,	NULL }, FALSE,	/* doggy_dummy_type */
  { NULL,	NULL }, FALSE,	/* doggy_Scope */
  { NULL,	NULL }, FALSE,	/* doggy_OpSetScope */
  { NULL,	NULL }, FALSE,	/* doggy_AppliedOpScope */
  { NULL,	NULL }, FALSE,	/* doggy_ExprGuardScope */
  { NULL,	NULL }, FALSE,	/* doggy_RhsGuardScope */
  { NULL,	NULL }, FALSE,	/* doggy_FuncRuleScope */
  { NULL,	NULL }, FALSE,	/* doggy_RuleScope */
  { NULL,	NULL }, FALSE,	/* doggy_machine_descriptionScope */
  { NULL,	NULL }, FALSE,	/* List_doggy_Num */
  { NULL,	NULL }, FALSE,	/* List_List_doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* List_doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* List_doggy_ActualOp */
  { NULL,	NULL }, FALSE,	/* List_List_doggy_Type */
  { NULL,	NULL }, FALSE,	/* List_doggy_Operator */
  { NULL,	NULL }, FALSE,	/* List_doggy_Definition */
  { NULL,	NULL }, FALSE,	/* List_doggy_Expr */
  { NULL,	NULL }, FALSE,	/* List_doggy_Guard */
  { NULL,	NULL }, FALSE,	/* List_doggy_Pattern */
  { NULL,	NULL }, FALSE,	/* List_doggy_Argument */
  { NULL,	NULL }, FALSE,	/* List_doggy_FuncRule */
  { NULL,	NULL }, FALSE,	/* List_doggy_Attribute */
  { NULL,	NULL }, FALSE,	/* List_doggy_Property */
  { NULL,	NULL }, FALSE,	/* List_doggy_Applied_formal */
  { NULL,	NULL }, FALSE,	/* List_doggy_Operation_def */
  { NULL,	NULL }, FALSE,	/* List_doggy_Type */
  { NULL,	NULL }, FALSE,	/* List_doggy_Rule */
  { NULL,	NULL }, FALSE,	/* List_doggy_Func */
  { NULL,	NULL }, FALSE,	/* List_doggy_Section */
  { NULL,	NULL }, FALSE,	/* List_doggy_FunctionDef */
  { NULL,	NULL }, FALSE,	/* List_doggy_Typedef */
  { NULL,	 NULL }, FALSE,	/* doggy_Operator */
  { NULL,	 NULL }, FALSE,	/* doggy_CandOp */
  { NULL,	 NULL }, FALSE,	/* doggy_CorOp */
  { NULL,	 NULL }, FALSE,	/* doggy_XorOp */
  { NULL,	 NULL }, FALSE,	/* doggy_EqOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NeqOp */
  { NULL,	 NULL }, FALSE,	/* doggy_LEOp */
  { NULL,	 NULL }, FALSE,	/* doggy_GEOp */
  { NULL,	 NULL }, FALSE,	/* doggy_LTOp */
  { NULL,	 NULL }, FALSE,	/* doggy_GTOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SLOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SROp */
  { NULL,	 NULL }, FALSE,	/* doggy_DivOp */
  { NULL,	 NULL }, FALSE,	/* doggy_ModOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MulOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AndOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AddOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SubOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MonOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NotOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NegOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AddrOp */
  { NULL,	 NULL }, FALSE,	/* doggy_DerefOp */
  { NULL,	 NULL }, FALSE,	/* doggy_PlusOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MinOp */
  { NULL,	 NULL }, FALSE,	/* doggy_Property */
};

static void Defining_doggy_doggy (doggy_doggy me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Typedef (doggy_Typedef me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Typedef_scope(me);
  doggy_Typedef__num(me) = Scope_Num_Stores (scope);
  doggy_Typedef_id_bind(me) = ReplaceBind (doggy_Typedef_id_bind(me), doggy_Typedef_id(me), scope, Bind_doggy_Typedef_kind, me, doggy_TypeNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_doggy_FunctionDef (doggy_FunctionDef me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_FunctionDef_scope(me);
  doggy_FunctionDef__num(me) = Scope_Num_Stores (scope);
  doggy_FunctionDef_id_bind(me) = ReplaceBind (doggy_FunctionDef_id_bind(me), doggy_FunctionDef_id(me), scope, Bind_doggy_FunctionDef_kind, me, doggy_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_doggy_machine_description (doggy_machine_description me)
{
  Scope scope;
  if (me==NULL) return;
  Scope__self (doggy_machine_description_scope(me)) = Scope_Num_Stores (doggy_machine_description_old_scope(me));
  scope = doggy_Scope_next(doggy_machine_description_scope(me));
  doggy_machine_description__num(me) = Scope_Num_Stores (scope);
  doggy_machine_description_id_bind(me) = ReplaceBind (doggy_machine_description_id_bind(me), doggy_machine_description_id(me), scope, Bind_doggy_machine_description_kind, me, doggy_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_doggy_Operation_def (doggy_Operation_def me)
{
  Scope scope;
  if (me==NULL) return;
  scope = NULL;
  doggy_Operation_def__num(me) = Scope_Num_Stores (scope);
  doggy_Operation_def_id_bind(me) = ReplaceBind (doggy_Operation_def_id_bind(me), doggy_Operation_def_id(me), scope, Bind_doggy_Operation_def_kind, me, doggy_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_doggy_Attributes (doggy_Attributes me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Attribute (doggy_Attribute me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Section (doggy_Section me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Rule (doggy_Rule me)
{
  Scope scope;
  if (me==NULL) return;
  Scope__self (doggy_Rule_scope(me)) = Scope_Num_Stores (doggy_Rule_old_scope(me));
  scope = doggy_Scope_next(doggy_Rule_scope(me));
  doggy_Rule__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_Lhs (doggy_Lhs me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Func (doggy_Func me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Func_scope(me);
  doggy_Func__num(me) = Scope_Num_Stores (scope);
  doggy_Func_id_bind(me) = ReplaceBind (doggy_Func_id_bind(me), doggy_Func_id(me), scope, Bind_doggy_Func_kind, me, doggy_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_doggy_FuncRule (doggy_FuncRule me)
{
  Scope scope;
  if (me==NULL) return;
  Scope__self (doggy_FuncRule_scope(me)) = Scope_Num_Stores (doggy_FuncRule_old_scope(me));
  scope = doggy_Scope_next(doggy_FuncRule_scope(me));
  doggy_FuncRule__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_Argument (doggy_Argument me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Argument_scope(me);
  doggy_Argument__num(me) = Scope_Num_Stores (scope);
  doggy_Argument_id_bind(me) = ReplaceBind (doggy_Argument_id_bind(me), doggy_Argument_id(me), scope, Bind_doggy_Argument_kind, me, doggy_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_doggy_ArgPat (doggy_ArgPat me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Pattern (doggy_Pattern me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Pattern_scope(me);
  doggy_Pattern__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_IdentPattern (doggy_IdentPattern me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Pattern_scope(me);
  doggy_Pattern__num(me) = Scope_Num_Stores (scope);
  doggy_IdentPattern_id_bind(me) = ReplaceBind (doggy_IdentPattern_id_bind(me), doggy_IdentPattern_id(me), scope, Bind_doggy_Pattern_kind, me, doggy_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_doggy_Rhs (doggy_Rhs me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Guard (doggy_Guard me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Guard_scope(me);
  doggy_Guard__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_RhsGuard (doggy_RhsGuard me)
{
  Scope scope;
  if (me==NULL) return;
  Scope__self (doggy_Guard_scope(me)) = Scope_Num_Stores (doggy_Guard_old_scope(me));
  scope = doggy_Scope_next(doggy_Guard_scope(me));
  doggy_Guard__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_ExprGuard (doggy_ExprGuard me)
{
  Scope scope;
  if (me==NULL) return;
  Scope__self (doggy_Guard_scope(me)) = Scope_Num_Stores (doggy_Guard_old_scope(me));
  scope = doggy_Scope_next(doggy_Guard_scope(me));
  doggy_Guard__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_ExprSeq (doggy_ExprSeq me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Wherepart (doggy_Wherepart me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Applied_operation (doggy_Applied_operation me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Applied_operation_scope(me);
  doggy_Applied_operation__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_AppliedOp (doggy_AppliedOp me)
{
  Scope scope;
  if (me==NULL) return;
  Scope__self (doggy_Applied_operation_scope(me)) = Scope_Num_Stores (doggy_Applied_operation_old_scope(me));
  scope = doggy_Scope_next(doggy_Applied_operation_scope(me));
  doggy_Applied_operation__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_OpSet (doggy_OpSet me)
{
  Scope scope;
  if (me==NULL) return;
  Scope__self (doggy_Applied_operation_scope(me)) = Scope_Num_Stores (doggy_Applied_operation_old_scope(me));
  scope = doggy_Scope_next(doggy_Applied_operation_scope(me));
  doggy_Applied_operation__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_Applied_formal (doggy_Applied_formal me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Applied_formal_scope(me);
  doggy_Applied_formal__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_Expr (doggy_Expr me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Expr_scope(me);
  doggy_Expr__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_SimpleExpr (doggy_SimpleExpr me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Expr_scope(me);
  doggy_Expr__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_IdentExpr (doggy_IdentExpr me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Expr_scope(me);
  doggy_Expr__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_Operation (doggy_Operation me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Expr_scope(me);
  doggy_Expr__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_Constant (doggy_Constant me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Definition (doggy_Definition me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Definition_scope(me);
  doggy_Definition__num(me) = Scope_Num_Stores (scope);
  doggy_Definition_id_bind(me) = ReplaceBind (doggy_Definition_id_bind(me), doggy_Definition_id(me), scope, Bind_doggy_Definition_kind, me, doggy_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_doggy_Type (doggy_Type me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Type_scope(me);
  doggy_Type__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_BasicType (doggy_BasicType me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Type_scope(me);
  doggy_Type__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_IdentType (doggy_IdentType me)
{
  Scope scope;
  if (me==NULL) return;
  scope = doggy_Type_scope(me);
  doggy_Type__num(me) = Scope_Num_Stores (scope);
}

static void Defining_doggy_Num (doggy_Num me)
{
  if (me==NULL) return;
}

static void Defining_doggy_IdInt (doggy_IdInt me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Path (doggy_Path me)
{
  if (me==NULL) return;
}

static void Defining_doggy_ActualOp (doggy_ActualOp me)
{
  if (me==NULL) return;
}

static void Defining_doggy_TypePair (doggy_TypePair me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Opat (doggy_Opat me)
{
  if (me==NULL) return;
}

static void Defining_doggy_Format (doggy_Format me)
{
  if (me==NULL) return;
}

static void Defining_doggy_dummy_type (doggy_dummy_type me)
{
  if (me==NULL) return;
}

struct s_void_doggy_TraverseTable doggy_defining_actions = {

  { NULL,	(void*)Defining_doggy_doggy }, FALSE,	/* doggy_doggy */
  { NULL,	(void*)Defining_doggy_Typedef }, FALSE,	/* doggy_Typedef */
  { NULL,	(void*)Defining_doggy_FunctionDef }, FALSE,	/* doggy_FunctionDef */
  { NULL,	NULL }, FALSE,	/* doggy_ExtFunc */
  { NULL,	NULL }, FALSE,	/* doggy_ExtVar */
  { NULL,	(void*)Defining_doggy_machine_description }, FALSE,	/* doggy_machine_description */
  { NULL,	(void*)Defining_doggy_Operation_def }, FALSE,	/* doggy_Operation_def */
  { NULL,	(void*)Defining_doggy_Attributes }, FALSE,	/* doggy_Attributes */
  { NULL,	(void*)Defining_doggy_Attribute }, FALSE,	/* doggy_Attribute */
  { NULL,	NULL }, FALSE,	/* doggy_IdAttr */
  { NULL,	NULL }, FALSE,	/* doggy_OpAttr */
  { NULL,	NULL }, FALSE,	/* doggy_IntAttr */
  { NULL,	(void*)Defining_doggy_Section }, FALSE,	/* doggy_Section */
  { NULL,	NULL }, FALSE,	/* doggy_FuncSection */
  { NULL,	NULL }, FALSE,	/* doggy_RuleSection */
  { NULL,	(void*)Defining_doggy_Rule }, FALSE,	/* doggy_Rule */
  { NULL,	(void*)Defining_doggy_Lhs }, FALSE,	/* doggy_Lhs */
  { NULL,	NULL }, FALSE,	/* doggy_LabeledLhs */
  { NULL,	NULL }, FALSE,	/* doggy_UnLabeledLhs */
  { NULL,	(void*)Defining_doggy_Func }, FALSE,	/* doggy_Func */
  { NULL,	(void*)Defining_doggy_FuncRule }, FALSE,	/* doggy_FuncRule */
  { NULL,	(void*)Defining_doggy_Argument }, FALSE,	/* doggy_Argument */
  { NULL,	NULL }, FALSE,	/* doggy_TypedArg */
  { NULL,	NULL }, FALSE,	/* doggy_UnTypedArg */
  { NULL,	(void*)Defining_doggy_ArgPat }, FALSE,	/* doggy_ArgPat */
  { NULL,	NULL }, FALSE,	/* doggy_PatArg */
  { NULL,	NULL }, FALSE,	/* doggy_SetArg */
  { NULL,	(void*)Defining_doggy_Pattern }, FALSE,	/* doggy_Pattern */
  { NULL,	NULL }, FALSE,	/* doggy_TypedPattern */
  { NULL,	NULL }, FALSE,	/* doggy_ConsPattern */
  { NULL,	NULL }, FALSE,	/* doggy_DefPattern */
  { NULL,	(void*)Defining_doggy_IdentPattern }, FALSE,	/* doggy_IdentPattern */
  { NULL,	NULL }, FALSE,	/* doggy_BasicPattern */
  { NULL,	NULL }, FALSE,	/* doggy_OpPattern */
  { NULL,	NULL }, FALSE,	/* doggy_ConstPattern */
  { NULL,	NULL }, FALSE,	/* doggy_NullPattern */
  { NULL,	NULL }, FALSE,	/* doggy_DontCarePattern */
  { NULL,	(void*)Defining_doggy_Rhs }, FALSE,	/* doggy_Rhs */
  { NULL,	NULL }, FALSE,	/* doggy_PlainRhs */
  { NULL,	NULL }, FALSE,	/* doggy_BlockRhs */
  { NULL,	(void*)Defining_doggy_Guard }, FALSE,	/* doggy_Guard */
  { NULL,	(void*)Defining_doggy_RhsGuard }, FALSE,	/* doggy_RhsGuard */
  { NULL,	(void*)Defining_doggy_ExprGuard }, FALSE,	/* doggy_ExprGuard */
  { NULL,	(void*)Defining_doggy_ExprSeq }, FALSE,	/* doggy_ExprSeq */
  { NULL,	NULL }, FALSE,	/* doggy_OneExpr */
  { NULL,	NULL }, FALSE,	/* doggy_MoreExprs */
  { NULL,	(void*)Defining_doggy_Wherepart }, FALSE,	/* doggy_Wherepart */
  { NULL,	(void*)Defining_doggy_Applied_operation }, FALSE,	/* doggy_Applied_operation */
  { NULL,	NULL }, FALSE,	/* doggy_AnyOp */
  { NULL,	(void*)Defining_doggy_AppliedOp }, FALSE,	/* doggy_AppliedOp */
  { NULL,	(void*)Defining_doggy_OpSet }, FALSE,	/* doggy_OpSet */
  { NULL,	(void*)Defining_doggy_Applied_formal }, FALSE,	/* doggy_Applied_formal */
  { NULL,	(void*)Defining_doggy_Expr }, FALSE,	/* doggy_Expr */
  { NULL,	NULL }, FALSE,	/* doggy_BinExpr */
  { NULL,	NULL }, FALSE,	/* doggy_ConsExpr */
  { NULL,	NULL }, FALSE,	/* doggy_SimpleExpr */
  { NULL,	NULL }, FALSE,	/* doggy_IdentExpr */
  { NULL,	NULL }, FALSE,	/* doggy_IfExpr */
  { NULL,	NULL }, FALSE,	/* doggy_ConstExpr */
  { NULL,	NULL }, FALSE,	/* doggy_Operation */
  { NULL,	NULL }, FALSE,	/* doggy_ParExpr */
  { NULL,	NULL }, FALSE,	/* doggy_MonExpr */
  { NULL,	(void*)Defining_doggy_Constant }, FALSE,	/* doggy_Constant */
  { NULL,	NULL }, FALSE,	/* doggy_IntConst */
  { NULL,	NULL }, FALSE,	/* doggy_BoolConst */
  { NULL,	NULL }, FALSE,	/* doggy_StringConst */
  { NULL,	NULL }, FALSE,	/* doggy_NullConst */
  { NULL,	(void*)Defining_doggy_Definition }, FALSE,	/* doggy_Definition */
  { NULL,	(void*)Defining_doggy_Type }, FALSE,	/* doggy_Type */
  { NULL,	NULL }, FALSE,	/* doggy_EdgeType */
  { NULL,	NULL }, FALSE,	/* doggy_TupleType */
  { NULL,	NULL }, FALSE,	/* doggy_BasicType */
  { NULL,	NULL }, FALSE,	/* doggy_IdentType */
  { NULL,	NULL }, FALSE,	/* doggy_OprType */
  { NULL,	NULL }, FALSE,	/* doggy_PointerType */
  { NULL,	NULL }, FALSE,	/* doggy_RangeType */
  { NULL,	NULL }, FALSE,	/* doggy_FRangeType */
  { NULL,	(void*)Defining_doggy_Num }, FALSE,	/* doggy_Num */
  { NULL,	(void*)Defining_doggy_IdInt }, FALSE,	/* doggy_IdInt */
  { NULL,	NULL }, FALSE,	/* doggy_IsId */
  { NULL,	NULL }, FALSE,	/* doggy_IsInt */
  { NULL,	(void*)Defining_doggy_Path }, FALSE,	/* doggy_Path */
  { NULL,	(void*)Defining_doggy_ActualOp }, FALSE,	/* doggy_ActualOp */
  { NULL,	(void*)Defining_doggy_TypePair }, FALSE,	/* doggy_TypePair */
  { NULL,	(void*)Defining_doggy_Opat }, FALSE,	/* doggy_Opat */
  { NULL,	(void*)Defining_doggy_Format }, FALSE,	/* doggy_Format */
  { NULL,	(void*)Defining_doggy_dummy_type }, FALSE,	/* doggy_dummy_type */
  { NULL,	NULL }, FALSE,	/* doggy_Scope */
  { NULL,	NULL }, FALSE,	/* doggy_OpSetScope */
  { NULL,	NULL }, FALSE,	/* doggy_AppliedOpScope */
  { NULL,	NULL }, FALSE,	/* doggy_ExprGuardScope */
  { NULL,	NULL }, FALSE,	/* doggy_RhsGuardScope */
  { NULL,	NULL }, FALSE,	/* doggy_FuncRuleScope */
  { NULL,	NULL }, FALSE,	/* doggy_RuleScope */
  { NULL,	NULL }, FALSE,	/* doggy_machine_descriptionScope */
  { NULL,	NULL }, FALSE,	/* List_doggy_Num */
  { NULL,	NULL }, FALSE,	/* List_List_doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* List_doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* List_doggy_ActualOp */
  { NULL,	NULL }, FALSE,	/* List_List_doggy_Type */
  { NULL,	NULL }, FALSE,	/* List_doggy_Operator */
  { NULL,	NULL }, FALSE,	/* List_doggy_Definition */
  { NULL,	NULL }, FALSE,	/* List_doggy_Expr */
  { NULL,	NULL }, FALSE,	/* List_doggy_Guard */
  { NULL,	NULL }, FALSE,	/* List_doggy_Pattern */
  { NULL,	NULL }, FALSE,	/* List_doggy_Argument */
  { NULL,	NULL }, FALSE,	/* List_doggy_FuncRule */
  { NULL,	NULL }, FALSE,	/* List_doggy_Attribute */
  { NULL,	NULL }, FALSE,	/* List_doggy_Property */
  { NULL,	NULL }, FALSE,	/* List_doggy_Applied_formal */
  { NULL,	NULL }, FALSE,	/* List_doggy_Operation_def */
  { NULL,	NULL }, FALSE,	/* List_doggy_Type */
  { NULL,	NULL }, FALSE,	/* List_doggy_Rule */
  { NULL,	NULL }, FALSE,	/* List_doggy_Func */
  { NULL,	NULL }, FALSE,	/* List_doggy_Section */
  { NULL,	NULL }, FALSE,	/* List_doggy_FunctionDef */
  { NULL,	NULL }, FALSE,	/* List_doggy_Typedef */
  { NULL,	 NULL }, FALSE,	/* doggy_Operator */
  { NULL,	 NULL }, FALSE,	/* doggy_CandOp */
  { NULL,	 NULL }, FALSE,	/* doggy_CorOp */
  { NULL,	 NULL }, FALSE,	/* doggy_XorOp */
  { NULL,	 NULL }, FALSE,	/* doggy_EqOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NeqOp */
  { NULL,	 NULL }, FALSE,	/* doggy_LEOp */
  { NULL,	 NULL }, FALSE,	/* doggy_GEOp */
  { NULL,	 NULL }, FALSE,	/* doggy_LTOp */
  { NULL,	 NULL }, FALSE,	/* doggy_GTOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SLOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SROp */
  { NULL,	 NULL }, FALSE,	/* doggy_DivOp */
  { NULL,	 NULL }, FALSE,	/* doggy_ModOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MulOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AndOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AddOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SubOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MonOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NotOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NegOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AddrOp */
  { NULL,	 NULL }, FALSE,	/* doggy_DerefOp */
  { NULL,	 NULL }, FALSE,	/* doggy_PlusOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MinOp */
  { NULL,	 NULL }, FALSE,	/* doggy_Property */
};

static void Retrieve_doggy_Applied_formal (doggy_Applied_formal me)
{ if (me==NULL) return;
  if (doggy_Applied_formal_id(me) != NULL) {
    doggy_Applied_formal_ap_bind(me) = RetrieveBind (doggy_Applied_formal_id(me), doggy_Applied_formal_scope(me), doggy_Applied_formal__num(me), doggy_DefaultNameSpace, Bind_doggy_Operation_def_kind);
    doggy_Applied_formal_ap(me) = NULL;
    if (doggy_Applied_formal_ap_bind(me) != NULL)
      doggy_Applied_formal_ap(me) = (doggy_Operation_def)Bind_object(doggy_Applied_formal_ap_bind(me));
  }
}

static void Retrieve_doggy_IdentExpr (doggy_IdentExpr me)
{ if (me==NULL) return;
  if (doggy_IdentExpr_id(me) != NULL) {
    doggy_IdentExpr_operator_bind(me) = RetrieveBind (doggy_IdentExpr_id(me), doggy_Expr_scope(me), doggy_Expr__num(me), doggy_DefaultNameSpace, Bind_doggy_Operation_def_kind);
    doggy_IdentExpr_operator(me) = NULL;
    if (doggy_IdentExpr_operator_bind(me) != NULL)
      doggy_IdentExpr_operator(me) = (doggy_Operation_def)Bind_object(doggy_IdentExpr_operator_bind(me));
  }
  if (doggy_IdentExpr_id(me) != NULL) {
    doggy_IdentExpr_pattern_bind(me) = RetrieveBind (doggy_IdentExpr_id(me), doggy_Expr_scope(me), doggy_Expr__num(me), doggy_DefaultNameSpace, Bind_doggy_Pattern_kind);
    doggy_IdentExpr_pattern(me) = NULL;
    if (doggy_IdentExpr_pattern_bind(me) != NULL)
      doggy_IdentExpr_pattern(me) = (doggy_Pattern)Bind_object(doggy_IdentExpr_pattern_bind(me));
  }
  if (doggy_IdentExpr_id(me) != NULL) {
    doggy_IdentExpr_ext_bind(me) = RetrieveBind (doggy_IdentExpr_id(me), doggy_Expr_scope(me), doggy_Expr__num(me), doggy_DefaultNameSpace, Bind_doggy_FunctionDef_kind);
    doggy_IdentExpr_ext(me) = NULL;
    if (doggy_IdentExpr_ext_bind(me) != NULL)
      doggy_IdentExpr_ext(me) = (doggy_FunctionDef)Bind_object(doggy_IdentExpr_ext_bind(me));
  }
  if (doggy_IdentExpr_id(me) != NULL) {
    doggy_IdentExpr_def_bind(me) = RetrieveBind (doggy_IdentExpr_id(me), doggy_Expr_scope(me), doggy_Expr__num(me), doggy_DefaultNameSpace, Bind_doggy_Definition_kind);
    doggy_IdentExpr_def(me) = NULL;
    if (doggy_IdentExpr_def_bind(me) != NULL)
      doggy_IdentExpr_def(me) = (doggy_Definition)Bind_object(doggy_IdentExpr_def_bind(me));
  }
  if (doggy_IdentExpr_id(me) != NULL) {
    doggy_IdentExpr_arg_bind(me) = RetrieveBind (doggy_IdentExpr_id(me), doggy_Expr_scope(me), doggy_Expr__num(me), doggy_DefaultNameSpace, Bind_doggy_Argument_kind);
    doggy_IdentExpr_arg(me) = NULL;
    if (doggy_IdentExpr_arg_bind(me) != NULL)
      doggy_IdentExpr_arg(me) = (doggy_Argument)Bind_object(doggy_IdentExpr_arg_bind(me));
  }
}

static void Retrieve_doggy_Operation (doggy_Operation me)
{ if (me==NULL) return;
  if (doggy_Operation_id(me) != NULL) {
    doggy_Operation_operator_bind(me) = RetrieveBind (doggy_Operation_id(me), doggy_Expr_scope(me), doggy_Expr__num(me), doggy_DefaultNameSpace, Bind_doggy_Operation_def_kind);
    doggy_Operation_operator(me) = NULL;
    if (doggy_Operation_operator_bind(me) != NULL)
      doggy_Operation_operator(me) = (doggy_Operation_def)Bind_object(doggy_Operation_operator_bind(me));
  }
  if (doggy_Operation_id(me) != NULL) {
    doggy_Operation_defi_bind(me) = RetrieveBind (doggy_Operation_id(me), doggy_Expr_scope(me), doggy_Expr__num(me), doggy_DefaultNameSpace, Bind_doggy_Definition_kind);
    doggy_Operation_defi(me) = NULL;
    if (doggy_Operation_defi_bind(me) != NULL)
      doggy_Operation_defi(me) = (doggy_Definition)Bind_object(doggy_Operation_defi_bind(me));
  }
  if (doggy_Operation_id(me) != NULL) {
    doggy_Operation_ext_bind(me) = RetrieveBind (doggy_Operation_id(me), doggy_Expr_scope(me), doggy_Expr__num(me), doggy_DefaultNameSpace, Bind_doggy_FunctionDef_kind);
    doggy_Operation_ext(me) = NULL;
    if (doggy_Operation_ext_bind(me) != NULL)
      doggy_Operation_ext(me) = (doggy_FunctionDef)Bind_object(doggy_Operation_ext_bind(me));
  }
  if (doggy_Operation_id(me) != NULL) {
    doggy_Operation_func_bind(me) = RetrieveBind (doggy_Operation_id(me), doggy_Expr_scope(me), doggy_Expr__num(me), doggy_DefaultNameSpace, Bind_doggy_Func_kind);
    doggy_Operation_func(me) = NULL;
    if (doggy_Operation_func_bind(me) != NULL)
      doggy_Operation_func(me) = (doggy_Func)Bind_object(doggy_Operation_func_bind(me));
  }
}

static void Retrieve_doggy_IdentType (doggy_IdentType me)
{ if (me==NULL) return;
  if (doggy_IdentType_type_id(me) != NULL) {
    doggy_IdentType_type_bind(me) = RetrieveBind (doggy_IdentType_type_id(me), doggy_Type_scope(me), doggy_Type__num(me), doggy_TypeNameSpace, Bind_doggy_Typedef_kind);
    doggy_IdentType_type(me) = NULL;
    if (doggy_IdentType_type_bind(me) != NULL)
      doggy_IdentType_type(me) = (doggy_Typedef)Bind_object(doggy_IdentType_type_bind(me));
  }
}

struct s_void_doggy_TraverseTable doggy_applied_actions = {

  { NULL,	NULL }, FALSE,	/* doggy_doggy */
  { NULL,	NULL }, FALSE,	/* doggy_Typedef */
  { NULL,	NULL }, FALSE,	/* doggy_FunctionDef */
  { NULL,	NULL }, FALSE,	/* doggy_ExtFunc */
  { NULL,	NULL }, FALSE,	/* doggy_ExtVar */
  { NULL,	NULL }, FALSE,	/* doggy_machine_description */
  { NULL,	NULL }, FALSE,	/* doggy_Operation_def */
  { NULL,	NULL }, FALSE,	/* doggy_Attributes */
  { NULL,	NULL }, FALSE,	/* doggy_Attribute */
  { NULL,	NULL }, FALSE,	/* doggy_IdAttr */
  { NULL,	NULL }, FALSE,	/* doggy_OpAttr */
  { NULL,	NULL }, FALSE,	/* doggy_IntAttr */
  { NULL,	NULL }, FALSE,	/* doggy_Section */
  { NULL,	NULL }, FALSE,	/* doggy_FuncSection */
  { NULL,	NULL }, FALSE,	/* doggy_RuleSection */
  { NULL,	NULL }, FALSE,	/* doggy_Rule */
  { NULL,	NULL }, FALSE,	/* doggy_Lhs */
  { NULL,	NULL }, FALSE,	/* doggy_LabeledLhs */
  { NULL,	NULL }, FALSE,	/* doggy_UnLabeledLhs */
  { NULL,	NULL }, FALSE,	/* doggy_Func */
  { NULL,	NULL }, FALSE,	/* doggy_FuncRule */
  { NULL,	NULL }, FALSE,	/* doggy_Argument */
  { NULL,	NULL }, FALSE,	/* doggy_TypedArg */
  { NULL,	NULL }, FALSE,	/* doggy_UnTypedArg */
  { NULL,	NULL }, FALSE,	/* doggy_ArgPat */
  { NULL,	NULL }, FALSE,	/* doggy_PatArg */
  { NULL,	NULL }, FALSE,	/* doggy_SetArg */
  { NULL,	NULL }, FALSE,	/* doggy_Pattern */
  { NULL,	NULL }, FALSE,	/* doggy_TypedPattern */
  { NULL,	NULL }, FALSE,	/* doggy_ConsPattern */
  { NULL,	NULL }, FALSE,	/* doggy_DefPattern */
  { NULL,	NULL }, FALSE,	/* doggy_IdentPattern */
  { NULL,	NULL }, FALSE,	/* doggy_BasicPattern */
  { NULL,	NULL }, FALSE,	/* doggy_OpPattern */
  { NULL,	NULL }, FALSE,	/* doggy_ConstPattern */
  { NULL,	NULL }, FALSE,	/* doggy_NullPattern */
  { NULL,	NULL }, FALSE,	/* doggy_DontCarePattern */
  { NULL,	NULL }, FALSE,	/* doggy_Rhs */
  { NULL,	NULL }, FALSE,	/* doggy_PlainRhs */
  { NULL,	NULL }, FALSE,	/* doggy_BlockRhs */
  { NULL,	NULL }, FALSE,	/* doggy_Guard */
  { NULL,	NULL }, FALSE,	/* doggy_RhsGuard */
  { NULL,	NULL }, FALSE,	/* doggy_ExprGuard */
  { NULL,	NULL }, FALSE,	/* doggy_ExprSeq */
  { NULL,	NULL }, FALSE,	/* doggy_OneExpr */
  { NULL,	NULL }, FALSE,	/* doggy_MoreExprs */
  { NULL,	NULL }, FALSE,	/* doggy_Wherepart */
  { NULL,	NULL }, FALSE,	/* doggy_Applied_operation */
  { NULL,	NULL }, FALSE,	/* doggy_AnyOp */
  { NULL,	NULL }, FALSE,	/* doggy_AppliedOp */
  { NULL,	NULL }, FALSE,	/* doggy_OpSet */
  { NULL,	Retrieve_doggy_Applied_formal }, FALSE,	/* doggy_Applied_formal */
  { NULL,	NULL }, FALSE,	/* doggy_Expr */
  { NULL,	NULL }, FALSE,	/* doggy_BinExpr */
  { NULL,	NULL }, FALSE,	/* doggy_ConsExpr */
  { NULL,	NULL }, FALSE,	/* doggy_SimpleExpr */
  { NULL,	Retrieve_doggy_IdentExpr }, FALSE,	/* doggy_IdentExpr */
  { NULL,	NULL }, FALSE,	/* doggy_IfExpr */
  { NULL,	NULL }, FALSE,	/* doggy_ConstExpr */
  { NULL,	Retrieve_doggy_Operation }, FALSE,	/* doggy_Operation */
  { NULL,	NULL }, FALSE,	/* doggy_ParExpr */
  { NULL,	NULL }, FALSE,	/* doggy_MonExpr */
  { NULL,	NULL }, FALSE,	/* doggy_Constant */
  { NULL,	NULL }, FALSE,	/* doggy_IntConst */
  { NULL,	NULL }, FALSE,	/* doggy_BoolConst */
  { NULL,	NULL }, FALSE,	/* doggy_StringConst */
  { NULL,	NULL }, FALSE,	/* doggy_NullConst */
  { NULL,	NULL }, FALSE,	/* doggy_Definition */
  { NULL,	NULL }, FALSE,	/* doggy_Type */
  { NULL,	NULL }, FALSE,	/* doggy_EdgeType */
  { NULL,	NULL }, FALSE,	/* doggy_TupleType */
  { NULL,	NULL }, FALSE,	/* doggy_BasicType */
  { NULL,	Retrieve_doggy_IdentType }, FALSE,	/* doggy_IdentType */
  { NULL,	NULL }, FALSE,	/* doggy_OprType */
  { NULL,	NULL }, FALSE,	/* doggy_PointerType */
  { NULL,	NULL }, FALSE,	/* doggy_RangeType */
  { NULL,	NULL }, FALSE,	/* doggy_FRangeType */
  { NULL,	NULL }, FALSE,	/* doggy_Num */
  { NULL,	NULL }, FALSE,	/* doggy_IdInt */
  { NULL,	NULL }, FALSE,	/* doggy_IsId */
  { NULL,	NULL }, FALSE,	/* doggy_IsInt */
  { NULL,	NULL }, FALSE,	/* doggy_Path */
  { NULL,	NULL }, FALSE,	/* doggy_ActualOp */
  { NULL,	NULL }, FALSE,	/* doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* doggy_Opat */
  { NULL,	NULL }, FALSE,	/* doggy_Format */
  { NULL,	NULL }, FALSE,	/* doggy_dummy_type */
  { NULL,	NULL }, FALSE,	/* doggy_Scope */
  { NULL,	NULL }, FALSE,	/* doggy_OpSetScope */
  { NULL,	NULL }, FALSE,	/* doggy_AppliedOpScope */
  { NULL,	NULL }, FALSE,	/* doggy_ExprGuardScope */
  { NULL,	NULL }, FALSE,	/* doggy_RhsGuardScope */
  { NULL,	NULL }, FALSE,	/* doggy_FuncRuleScope */
  { NULL,	NULL }, FALSE,	/* doggy_RuleScope */
  { NULL,	NULL }, FALSE,	/* doggy_machine_descriptionScope */
  { NULL,	NULL }, FALSE,	/* List_doggy_Num */
  { NULL,	NULL }, FALSE,	/* List_List_doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* List_doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* List_doggy_ActualOp */
  { NULL,	NULL }, FALSE,	/* List_List_doggy_Type */
  { NULL,	NULL }, FALSE,	/* List_doggy_Operator */
  { NULL,	NULL }, FALSE,	/* List_doggy_Definition */
  { NULL,	NULL }, FALSE,	/* List_doggy_Expr */
  { NULL,	NULL }, FALSE,	/* List_doggy_Guard */
  { NULL,	NULL }, FALSE,	/* List_doggy_Pattern */
  { NULL,	NULL }, FALSE,	/* List_doggy_Argument */
  { NULL,	NULL }, FALSE,	/* List_doggy_FuncRule */
  { NULL,	NULL }, FALSE,	/* List_doggy_Attribute */
  { NULL,	NULL }, FALSE,	/* List_doggy_Property */
  { NULL,	NULL }, FALSE,	/* List_doggy_Applied_formal */
  { NULL,	NULL }, FALSE,	/* List_doggy_Operation_def */
  { NULL,	NULL }, FALSE,	/* List_doggy_Type */
  { NULL,	NULL }, FALSE,	/* List_doggy_Rule */
  { NULL,	NULL }, FALSE,	/* List_doggy_Func */
  { NULL,	NULL }, FALSE,	/* List_doggy_Section */
  { NULL,	NULL }, FALSE,	/* List_doggy_FunctionDef */
  { NULL,	NULL }, FALSE,	/* List_doggy_Typedef */
  { NULL,	 NULL }, FALSE,	/* doggy_Operator */
  { NULL,	 NULL }, FALSE,	/* doggy_CandOp */
  { NULL,	 NULL }, FALSE,	/* doggy_CorOp */
  { NULL,	 NULL }, FALSE,	/* doggy_XorOp */
  { NULL,	 NULL }, FALSE,	/* doggy_EqOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NeqOp */
  { NULL,	 NULL }, FALSE,	/* doggy_LEOp */
  { NULL,	 NULL }, FALSE,	/* doggy_GEOp */
  { NULL,	 NULL }, FALSE,	/* doggy_LTOp */
  { NULL,	 NULL }, FALSE,	/* doggy_GTOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SLOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SROp */
  { NULL,	 NULL }, FALSE,	/* doggy_DivOp */
  { NULL,	 NULL }, FALSE,	/* doggy_ModOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MulOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AndOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AddOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SubOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MonOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NotOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NegOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AddrOp */
  { NULL,	 NULL }, FALSE,	/* doggy_DerefOp */
  { NULL,	 NULL }, FALSE,	/* doggy_PlusOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MinOp */
  { NULL,	 NULL }, FALSE,	/* doggy_Property */
};

static void Check_doggy_doggy (doggy_doggy me)
{ if (me==NULL) return;
  { if (init_types ())
    { InputError (doggy_doggy_loc(me), FALSE, "");
      FrontMessage ("%s", "");
      FrontMessage ("\n");
    }
  }
}

static void Check_doggy_Typedef (doggy_Typedef me)
{ if (me==NULL) return;
  if (Bind_double (doggy_Typedef_id_bind(me))) {
    InputError (doggy_Typedef_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(doggy_Typedef_id(me)));
  }
}

static void Check_doggy_FunctionDef (doggy_FunctionDef me)
{ if (me==NULL) return;
  if (Bind_double (doggy_FunctionDef_id_bind(me))) {
    InputError (doggy_FunctionDef_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(doggy_FunctionDef_id(me)));
  }
}

static void Check_doggy_machine_description (doggy_machine_description me)
{ if (me==NULL) return;
  if (Bind_double (doggy_machine_description_id_bind(me))) {
    InputError (doggy_machine_description_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(doggy_machine_description_id(me)));
  }
}

static void Check_doggy_Operation_def (doggy_Operation_def me)
{ if (me==NULL) return;
  { if (Comm_conflict (me))
    { InputError (doggy_Operation_def_loc(me), FALSE, "");
      FrontMessage ("%s", "Operator ");
      FrontMessage ("%s", IDENT_STRING (Operation_def_id (me)));
      FrontMessage ("%s", " can not be commutative");
      FrontMessage ("\n");
    }
  }
  if (Bind_double (doggy_Operation_def_id_bind(me))) {
    InputError (doggy_Operation_def_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(doggy_Operation_def_id(me)));
  }
}

static void Check_doggy_Func (doggy_Func me)
{ if (me==NULL) return;
  { if (Func_conflict (me))
    { InputError (doggy_Func_loc(me), FALSE, "");
      FrontMessage ("%s", "Inconsistent rules for function ");
      FrontMessage ("%s", IDENT_STRING (Func_id (me)));
      FrontMessage ("\n");
    }
  }
  if (Bind_double (doggy_Func_id_bind(me))) {
    InputError (doggy_Func_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(doggy_Func_id(me)));
  }
}

static void Check_doggy_Argument (doggy_Argument me)
{ if (me==NULL) return;
  { if (Arg_conflict (me))
    { InputError (doggy_Argument_loc(me), FALSE, "");
      FrontMessage ("%s", "Incorrect argument ");
      FrontMessage ("%s", IDENT_STRING (Argument_id (me)));
      FrontMessage ("\n");
    }
  }
  if (Bind_double (doggy_Argument_id_bind(me))) {
    InputError (doggy_Argument_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(doggy_Argument_id(me)));
  }
}

static void Check_doggy_Pattern (doggy_Pattern me)
{ if (me==NULL) return;
  { if (Pattern_conflict (me))
    { InputError (doggy_Pattern_loc(me), FALSE, "");
      FrontMessage ("%s", "Incorrect pattern");
      FrontMessage ("\n");
    }
  }
}

static void Check_doggy_IdentPattern (doggy_IdentPattern me)
{ if (me==NULL) return;
  if (Bind_double (doggy_IdentPattern_id_bind(me))) {
    InputError (doggy_Pattern_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(doggy_IdentPattern_id(me)));
  }
}

static void Check_doggy_Applied_formal (doggy_Applied_formal me)
{ if (me==NULL) return;
  { if (SetSupported (Applied_formal_ap (me), Applied_formal_scope (me), TRUE))
    { InputError (doggy_Applied_formal_loc(me), FALSE, "");
      FrontMessage ("%s", "");
      FrontMessage ("\n");
    }
  }
  { if (allow_undeclared_ops == FALSE && Applied_formal_ap (me) == NULL)
    { InputError (doggy_Applied_formal_loc(me), FALSE, "");
      FrontMessage ("%s", "Identifier '");
      FrontMessage ("%s", IDENT_NAME (Applied_formal_id (me)));
      FrontMessage ("%s", "' not declared");
      FrontMessage ("\n");
    }
  }
}

static void Check_doggy_Expr (doggy_Expr me)
{ if (me==NULL) return;
  { if (Oper_conflict (me))
    { InputError (doggy_Expr_loc(me), FALSE, "");
      FrontMessage ("%s", "Incorrect typing of operator arguments");
      FrontMessage ("\n");
    }
  }
}

static void Check_doggy_IdentExpr (doggy_IdentExpr me)
{ if (me==NULL) return;
  { if (IdentExpr_operator (me) == NULL && IdentExpr_pattern (me) == NULL && IdentExpr_ext (me) == NULL && IdentExpr_def (me) == NULL && IdentExpr_arg (me) == NULL)
    { InputError (doggy_Expr_loc(me), FALSE, "");
      FrontMessage ("%s", "Identifier '");
      FrontMessage ("%s", IDENT_NAME (IdentExpr_id (me)));
      FrontMessage ("%s", "' not declared");
      FrontMessage ("\n");
    }
  }
  { if (SetSupported (IdentExpr_operator (me), Expr_scope (me), FALSE))
    { InputError (doggy_Expr_loc(me), FALSE, "");
      FrontMessage ("%s", "");
      FrontMessage ("\n");
    }
  }
}

static void Check_doggy_IfExpr (doggy_IfExpr me)
{ if (me==NULL) return;
  { if (If_conflict (me))
    { InputError (doggy_Expr_loc(me), FALSE, "");
      FrontMessage ("%s", "Incorrect types for if-branches");
      FrontMessage ("\n");
    }
  }
}

static void Check_doggy_Operation (doggy_Operation me)
{ if (me==NULL) return;
  { if (Operation_operator (me) == NULL && Operation_ext (me) == NULL && Operation_func (me) == NULL && Operation_defi (me) == NULL)
    { InputError (doggy_Expr_loc(me), FALSE, "");
      FrontMessage ("%s", "Operation '");
      FrontMessage ("%s", IDENT_NAME (IdentExpr_id (me)));
      FrontMessage ("%s", "' not declared");
      FrontMessage ("\n");
    }
  }
  { if (Call_conflict (me))
    { InputError (doggy_Expr_loc(me), FALSE, "");
      FrontMessage ("%s", "Incorrect arguments for operator ");
      FrontMessage ("%s", IDENT_STRING (Operation_id (me)));
      FrontMessage ("\n");
    }
  }
  { if (SetSupported (Operation_operator (me), Expr_scope (me), FALSE))
    { InputError (doggy_Expr_loc(me), FALSE, "");
      FrontMessage ("%s", "");
      FrontMessage ("\n");
    }
  }
}

static void Check_doggy_Definition (doggy_Definition me)
{ if (me==NULL) return;
  { if (Def_conflict (me))
    { InputError (doggy_Definition_loc(me), FALSE, "");
      FrontMessage ("%s", "Type conflict for definition of ");
      FrontMessage ("%s", IDENT_STRING (Definition_id (me)));
      FrontMessage ("\n");
    }
  }
  if (Bind_double (doggy_Definition_id_bind(me))) {
    InputError (doggy_Definition_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(doggy_Definition_id(me)));
  }
}

static void Check_doggy_IdentType (doggy_IdentType me)
{ if (me==NULL) return;
  if (doggy_IdentType_type_bind(me) == NULL && doggy_IdentType_type_id(me) != NULL) {
    InputError (doggy_Type_loc(me), TRUE, "Identifier '%s' not declared", Ident_name(doggy_IdentType_type_id(me)));
  }
}

struct s_void_doggy_TraverseTable doggy_check_actions = {

  { NULL,	Check_doggy_doggy }, FALSE,	/* doggy_doggy */
  { NULL,	Check_doggy_Typedef }, FALSE,	/* doggy_Typedef */
  { NULL,	Check_doggy_FunctionDef }, FALSE,	/* doggy_FunctionDef */
  { NULL,	NULL }, FALSE,	/* doggy_ExtFunc */
  { NULL,	NULL }, FALSE,	/* doggy_ExtVar */
  { NULL,	Check_doggy_machine_description }, FALSE,	/* doggy_machine_description */
  { NULL,	Check_doggy_Operation_def }, FALSE,	/* doggy_Operation_def */
  { NULL,	NULL }, FALSE,	/* doggy_Attributes */
  { NULL,	NULL }, FALSE,	/* doggy_Attribute */
  { NULL,	NULL }, FALSE,	/* doggy_IdAttr */
  { NULL,	NULL }, FALSE,	/* doggy_OpAttr */
  { NULL,	NULL }, FALSE,	/* doggy_IntAttr */
  { NULL,	NULL }, FALSE,	/* doggy_Section */
  { NULL,	NULL }, FALSE,	/* doggy_FuncSection */
  { NULL,	NULL }, FALSE,	/* doggy_RuleSection */
  { NULL,	NULL }, FALSE,	/* doggy_Rule */
  { NULL,	NULL }, FALSE,	/* doggy_Lhs */
  { NULL,	NULL }, FALSE,	/* doggy_LabeledLhs */
  { NULL,	NULL }, FALSE,	/* doggy_UnLabeledLhs */
  { NULL,	Check_doggy_Func }, FALSE,	/* doggy_Func */
  { NULL,	NULL }, FALSE,	/* doggy_FuncRule */
  { NULL,	Check_doggy_Argument }, FALSE,	/* doggy_Argument */
  { NULL,	NULL }, FALSE,	/* doggy_TypedArg */
  { NULL,	NULL }, FALSE,	/* doggy_UnTypedArg */
  { NULL,	NULL }, FALSE,	/* doggy_ArgPat */
  { NULL,	NULL }, FALSE,	/* doggy_PatArg */
  { NULL,	NULL }, FALSE,	/* doggy_SetArg */
  { NULL,	Check_doggy_Pattern }, FALSE,	/* doggy_Pattern */
  { NULL,	NULL }, FALSE,	/* doggy_TypedPattern */
  { NULL,	NULL }, FALSE,	/* doggy_ConsPattern */
  { NULL,	NULL }, FALSE,	/* doggy_DefPattern */
  { NULL,	Check_doggy_IdentPattern }, FALSE,	/* doggy_IdentPattern */
  { NULL,	NULL }, FALSE,	/* doggy_BasicPattern */
  { NULL,	NULL }, FALSE,	/* doggy_OpPattern */
  { NULL,	NULL }, FALSE,	/* doggy_ConstPattern */
  { NULL,	NULL }, FALSE,	/* doggy_NullPattern */
  { NULL,	NULL }, FALSE,	/* doggy_DontCarePattern */
  { NULL,	NULL }, FALSE,	/* doggy_Rhs */
  { NULL,	NULL }, FALSE,	/* doggy_PlainRhs */
  { NULL,	NULL }, FALSE,	/* doggy_BlockRhs */
  { NULL,	NULL }, FALSE,	/* doggy_Guard */
  { NULL,	NULL }, FALSE,	/* doggy_RhsGuard */
  { NULL,	NULL }, FALSE,	/* doggy_ExprGuard */
  { NULL,	NULL }, FALSE,	/* doggy_ExprSeq */
  { NULL,	NULL }, FALSE,	/* doggy_OneExpr */
  { NULL,	NULL }, FALSE,	/* doggy_MoreExprs */
  { NULL,	NULL }, FALSE,	/* doggy_Wherepart */
  { NULL,	NULL }, FALSE,	/* doggy_Applied_operation */
  { NULL,	NULL }, FALSE,	/* doggy_AnyOp */
  { NULL,	NULL }, FALSE,	/* doggy_AppliedOp */
  { NULL,	NULL }, FALSE,	/* doggy_OpSet */
  { NULL,	Check_doggy_Applied_formal }, FALSE,	/* doggy_Applied_formal */
  { NULL,	Check_doggy_Expr }, FALSE,	/* doggy_Expr */
  { NULL,	NULL }, FALSE,	/* doggy_BinExpr */
  { NULL,	NULL }, FALSE,	/* doggy_ConsExpr */
  { NULL,	NULL }, FALSE,	/* doggy_SimpleExpr */
  { NULL,	Check_doggy_IdentExpr }, FALSE,	/* doggy_IdentExpr */
  { NULL,	Check_doggy_IfExpr }, FALSE,	/* doggy_IfExpr */
  { NULL,	NULL }, FALSE,	/* doggy_ConstExpr */
  { NULL,	Check_doggy_Operation }, FALSE,	/* doggy_Operation */
  { NULL,	NULL }, FALSE,	/* doggy_ParExpr */
  { NULL,	NULL }, FALSE,	/* doggy_MonExpr */
  { NULL,	NULL }, FALSE,	/* doggy_Constant */
  { NULL,	NULL }, FALSE,	/* doggy_IntConst */
  { NULL,	NULL }, FALSE,	/* doggy_BoolConst */
  { NULL,	NULL }, FALSE,	/* doggy_StringConst */
  { NULL,	NULL }, FALSE,	/* doggy_NullConst */
  { NULL,	Check_doggy_Definition }, FALSE,	/* doggy_Definition */
  { NULL,	NULL }, FALSE,	/* doggy_Type */
  { NULL,	NULL }, FALSE,	/* doggy_EdgeType */
  { NULL,	NULL }, FALSE,	/* doggy_TupleType */
  { NULL,	NULL }, FALSE,	/* doggy_BasicType */
  { NULL,	Check_doggy_IdentType }, FALSE,	/* doggy_IdentType */
  { NULL,	NULL }, FALSE,	/* doggy_OprType */
  { NULL,	NULL }, FALSE,	/* doggy_PointerType */
  { NULL,	NULL }, FALSE,	/* doggy_RangeType */
  { NULL,	NULL }, FALSE,	/* doggy_FRangeType */
  { NULL,	NULL }, FALSE,	/* doggy_Num */
  { NULL,	NULL }, FALSE,	/* doggy_IdInt */
  { NULL,	NULL }, FALSE,	/* doggy_IsId */
  { NULL,	NULL }, FALSE,	/* doggy_IsInt */
  { NULL,	NULL }, FALSE,	/* doggy_Path */
  { NULL,	NULL }, FALSE,	/* doggy_ActualOp */
  { NULL,	NULL }, FALSE,	/* doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* doggy_Opat */
  { NULL,	NULL }, FALSE,	/* doggy_Format */
  { NULL,	NULL }, FALSE,	/* doggy_dummy_type */
  { NULL,	NULL }, FALSE,	/* doggy_Scope */
  { NULL,	NULL }, FALSE,	/* doggy_OpSetScope */
  { NULL,	NULL }, FALSE,	/* doggy_AppliedOpScope */
  { NULL,	NULL }, FALSE,	/* doggy_ExprGuardScope */
  { NULL,	NULL }, FALSE,	/* doggy_RhsGuardScope */
  { NULL,	NULL }, FALSE,	/* doggy_FuncRuleScope */
  { NULL,	NULL }, FALSE,	/* doggy_RuleScope */
  { NULL,	NULL }, FALSE,	/* doggy_machine_descriptionScope */
  { NULL,	NULL }, FALSE,	/* List_doggy_Num */
  { NULL,	NULL }, FALSE,	/* List_List_doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* List_doggy_TypePair */
  { NULL,	NULL }, FALSE,	/* List_doggy_ActualOp */
  { NULL,	NULL }, FALSE,	/* List_List_doggy_Type */
  { NULL,	NULL }, FALSE,	/* List_doggy_Operator */
  { NULL,	NULL }, FALSE,	/* List_doggy_Definition */
  { NULL,	NULL }, FALSE,	/* List_doggy_Expr */
  { NULL,	NULL }, FALSE,	/* List_doggy_Guard */
  { NULL,	NULL }, FALSE,	/* List_doggy_Pattern */
  { NULL,	NULL }, FALSE,	/* List_doggy_Argument */
  { NULL,	NULL }, FALSE,	/* List_doggy_FuncRule */
  { NULL,	NULL }, FALSE,	/* List_doggy_Attribute */
  { NULL,	NULL }, FALSE,	/* List_doggy_Property */
  { NULL,	NULL }, FALSE,	/* List_doggy_Applied_formal */
  { NULL,	NULL }, FALSE,	/* List_doggy_Operation_def */
  { NULL,	NULL }, FALSE,	/* List_doggy_Type */
  { NULL,	NULL }, FALSE,	/* List_doggy_Rule */
  { NULL,	NULL }, FALSE,	/* List_doggy_Func */
  { NULL,	NULL }, FALSE,	/* List_doggy_Section */
  { NULL,	NULL }, FALSE,	/* List_doggy_FunctionDef */
  { NULL,	NULL }, FALSE,	/* List_doggy_Typedef */
  { NULL,	 NULL }, FALSE,	/* doggy_Operator */
  { NULL,	 NULL }, FALSE,	/* doggy_CandOp */
  { NULL,	 NULL }, FALSE,	/* doggy_CorOp */
  { NULL,	 NULL }, FALSE,	/* doggy_XorOp */
  { NULL,	 NULL }, FALSE,	/* doggy_EqOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NeqOp */
  { NULL,	 NULL }, FALSE,	/* doggy_LEOp */
  { NULL,	 NULL }, FALSE,	/* doggy_GEOp */
  { NULL,	 NULL }, FALSE,	/* doggy_LTOp */
  { NULL,	 NULL }, FALSE,	/* doggy_GTOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SLOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SROp */
  { NULL,	 NULL }, FALSE,	/* doggy_DivOp */
  { NULL,	 NULL }, FALSE,	/* doggy_ModOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MulOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AndOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AddOp */
  { NULL,	 NULL }, FALSE,	/* doggy_SubOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MonOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NotOp */
  { NULL,	 NULL }, FALSE,	/* doggy_NegOp */
  { NULL,	 NULL }, FALSE,	/* doggy_AddrOp */
  { NULL,	 NULL }, FALSE,	/* doggy_DerefOp */
  { NULL,	 NULL }, FALSE,	/* doggy_PlusOp */
  { NULL,	 NULL }, FALSE,	/* doggy_MinOp */
  { NULL,	 NULL }, FALSE,	/* doggy_Property */
};

struct s_void_doggy_TraverseTable doggy_print_actions;

struct s_copy_doggy_TraverseTable doggy_copy_actions;

struct s_compare_doggy_TraverseTable doggy_compare_actions;

void doggy_fill_table (doggy_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_doggy[PRE_ACTION] = (void* (*) (doggy_doggy, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_doggy[POST_ACTION] = (void* (*) (doggy_doggy, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Typedef[PRE_ACTION] = (void* (*) (doggy_Typedef, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Typedef[POST_ACTION] = (void* (*) (doggy_Typedef, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FunctionDef[PRE_ACTION] = (void* (*) (doggy_FunctionDef, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FunctionDef[POST_ACTION] = (void* (*) (doggy_FunctionDef, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExtFunc[PRE_ACTION] = (void* (*) (doggy_ExtFunc, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExtFunc[POST_ACTION] = (void* (*) (doggy_ExtFunc, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExtVar[PRE_ACTION] = (void* (*) (doggy_ExtVar, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExtVar[POST_ACTION] = (void* (*) (doggy_ExtVar, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_machine_description[PRE_ACTION] = (void* (*) (doggy_machine_description, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_machine_description[POST_ACTION] = (void* (*) (doggy_machine_description, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operation_def[PRE_ACTION] = (void* (*) (doggy_Operation_def, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operation_def[POST_ACTION] = (void* (*) (doggy_Operation_def, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Attributes[PRE_ACTION] = (void* (*) (doggy_Attributes, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Attributes[POST_ACTION] = (void* (*) (doggy_Attributes, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Attribute[PRE_ACTION] = (void* (*) (doggy_Attribute, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Attribute[POST_ACTION] = (void* (*) (doggy_Attribute, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdAttr[PRE_ACTION] = (void* (*) (doggy_IdAttr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdAttr[POST_ACTION] = (void* (*) (doggy_IdAttr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpAttr[PRE_ACTION] = (void* (*) (doggy_OpAttr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpAttr[POST_ACTION] = (void* (*) (doggy_OpAttr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntAttr[PRE_ACTION] = (void* (*) (doggy_IntAttr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntAttr[POST_ACTION] = (void* (*) (doggy_IntAttr, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Section[PRE_ACTION] = (void* (*) (doggy_Section, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Section[POST_ACTION] = (void* (*) (doggy_Section, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncSection[PRE_ACTION] = (void* (*) (doggy_FuncSection, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncSection[POST_ACTION] = (void* (*) (doggy_FuncSection, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RuleSection[PRE_ACTION] = (void* (*) (doggy_RuleSection, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RuleSection[POST_ACTION] = (void* (*) (doggy_RuleSection, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rule[PRE_ACTION] = (void* (*) (doggy_Rule, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rule[POST_ACTION] = (void* (*) (doggy_Rule, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Lhs[PRE_ACTION] = (void* (*) (doggy_Lhs, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Lhs[POST_ACTION] = (void* (*) (doggy_Lhs, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledLhs[PRE_ACTION] = (void* (*) (doggy_LabeledLhs, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledLhs[POST_ACTION] = (void* (*) (doggy_LabeledLhs, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnLabeledLhs[PRE_ACTION] = (void* (*) (doggy_UnLabeledLhs, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnLabeledLhs[POST_ACTION] = (void* (*) (doggy_UnLabeledLhs, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Func[PRE_ACTION] = (void* (*) (doggy_Func, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Func[POST_ACTION] = (void* (*) (doggy_Func, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncRule[PRE_ACTION] = (void* (*) (doggy_FuncRule, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncRule[POST_ACTION] = (void* (*) (doggy_FuncRule, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Argument[PRE_ACTION] = (void* (*) (doggy_Argument, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Argument[POST_ACTION] = (void* (*) (doggy_Argument, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypedArg[PRE_ACTION] = (void* (*) (doggy_TypedArg, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypedArg[POST_ACTION] = (void* (*) (doggy_TypedArg, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnTypedArg[PRE_ACTION] = (void* (*) (doggy_UnTypedArg, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnTypedArg[POST_ACTION] = (void* (*) (doggy_UnTypedArg, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ArgPat[PRE_ACTION] = (void* (*) (doggy_ArgPat, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ArgPat[POST_ACTION] = (void* (*) (doggy_ArgPat, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PatArg[PRE_ACTION] = (void* (*) (doggy_PatArg, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PatArg[POST_ACTION] = (void* (*) (doggy_PatArg, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SetArg[PRE_ACTION] = (void* (*) (doggy_SetArg, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SetArg[POST_ACTION] = (void* (*) (doggy_SetArg, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Pattern[PRE_ACTION] = (void* (*) (doggy_Pattern, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Pattern[POST_ACTION] = (void* (*) (doggy_Pattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypedPattern[PRE_ACTION] = (void* (*) (doggy_TypedPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypedPattern[POST_ACTION] = (void* (*) (doggy_TypedPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConsPattern[PRE_ACTION] = (void* (*) (doggy_ConsPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConsPattern[POST_ACTION] = (void* (*) (doggy_ConsPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefPattern[PRE_ACTION] = (void* (*) (doggy_DefPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefPattern[POST_ACTION] = (void* (*) (doggy_DefPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentPattern[PRE_ACTION] = (void* (*) (doggy_IdentPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentPattern[POST_ACTION] = (void* (*) (doggy_IdentPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicPattern[PRE_ACTION] = (void* (*) (doggy_BasicPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicPattern[POST_ACTION] = (void* (*) (doggy_BasicPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpPattern[PRE_ACTION] = (void* (*) (doggy_OpPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpPattern[POST_ACTION] = (void* (*) (doggy_OpPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConstPattern[PRE_ACTION] = (void* (*) (doggy_ConstPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConstPattern[POST_ACTION] = (void* (*) (doggy_ConstPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NullPattern[PRE_ACTION] = (void* (*) (doggy_NullPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NullPattern[POST_ACTION] = (void* (*) (doggy_NullPattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DontCarePattern[PRE_ACTION] = (void* (*) (doggy_DontCarePattern, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DontCarePattern[POST_ACTION] = (void* (*) (doggy_DontCarePattern, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rhs[PRE_ACTION] = (void* (*) (doggy_Rhs, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rhs[POST_ACTION] = (void* (*) (doggy_Rhs, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlainRhs[PRE_ACTION] = (void* (*) (doggy_PlainRhs, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlainRhs[POST_ACTION] = (void* (*) (doggy_PlainRhs, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BlockRhs[PRE_ACTION] = (void* (*) (doggy_BlockRhs, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BlockRhs[POST_ACTION] = (void* (*) (doggy_BlockRhs, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Guard[PRE_ACTION] = (void* (*) (doggy_Guard, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Guard[POST_ACTION] = (void* (*) (doggy_Guard, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RhsGuard[PRE_ACTION] = (void* (*) (doggy_RhsGuard, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RhsGuard[POST_ACTION] = (void* (*) (doggy_RhsGuard, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprGuard[PRE_ACTION] = (void* (*) (doggy_ExprGuard, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprGuard[POST_ACTION] = (void* (*) (doggy_ExprGuard, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprSeq[PRE_ACTION] = (void* (*) (doggy_ExprSeq, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprSeq[POST_ACTION] = (void* (*) (doggy_ExprSeq, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OneExpr[PRE_ACTION] = (void* (*) (doggy_OneExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OneExpr[POST_ACTION] = (void* (*) (doggy_OneExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MoreExprs[PRE_ACTION] = (void* (*) (doggy_MoreExprs, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MoreExprs[POST_ACTION] = (void* (*) (doggy_MoreExprs, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Wherepart[PRE_ACTION] = (void* (*) (doggy_Wherepart, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Wherepart[POST_ACTION] = (void* (*) (doggy_Wherepart, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Applied_operation[PRE_ACTION] = (void* (*) (doggy_Applied_operation, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Applied_operation[POST_ACTION] = (void* (*) (doggy_Applied_operation, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AnyOp[PRE_ACTION] = (void* (*) (doggy_AnyOp, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AnyOp[POST_ACTION] = (void* (*) (doggy_AnyOp, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedOp[PRE_ACTION] = (void* (*) (doggy_AppliedOp, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedOp[POST_ACTION] = (void* (*) (doggy_AppliedOp, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpSet[PRE_ACTION] = (void* (*) (doggy_OpSet, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpSet[POST_ACTION] = (void* (*) (doggy_OpSet, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Applied_formal[PRE_ACTION] = (void* (*) (doggy_Applied_formal, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Applied_formal[POST_ACTION] = (void* (*) (doggy_Applied_formal, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expr[PRE_ACTION] = (void* (*) (doggy_Expr, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expr[POST_ACTION] = (void* (*) (doggy_Expr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BinExpr[PRE_ACTION] = (void* (*) (doggy_BinExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BinExpr[POST_ACTION] = (void* (*) (doggy_BinExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConsExpr[PRE_ACTION] = (void* (*) (doggy_ConsExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConsExpr[POST_ACTION] = (void* (*) (doggy_ConsExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleExpr[PRE_ACTION] = (void* (*) (doggy_SimpleExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleExpr[POST_ACTION] = (void* (*) (doggy_SimpleExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentExpr[PRE_ACTION] = (void* (*) (doggy_IdentExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentExpr[POST_ACTION] = (void* (*) (doggy_IdentExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IfExpr[PRE_ACTION] = (void* (*) (doggy_IfExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IfExpr[POST_ACTION] = (void* (*) (doggy_IfExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConstExpr[PRE_ACTION] = (void* (*) (doggy_ConstExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConstExpr[POST_ACTION] = (void* (*) (doggy_ConstExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operation[PRE_ACTION] = (void* (*) (doggy_Operation, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operation[POST_ACTION] = (void* (*) (doggy_Operation, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ParExpr[PRE_ACTION] = (void* (*) (doggy_ParExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ParExpr[POST_ACTION] = (void* (*) (doggy_ParExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr[PRE_ACTION] = (void* (*) (doggy_MonExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr[POST_ACTION] = (void* (*) (doggy_MonExpr, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Constant[PRE_ACTION] = (void* (*) (doggy_Constant, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Constant[POST_ACTION] = (void* (*) (doggy_Constant, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntConst[PRE_ACTION] = (void* (*) (doggy_IntConst, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntConst[POST_ACTION] = (void* (*) (doggy_IntConst, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BoolConst[PRE_ACTION] = (void* (*) (doggy_BoolConst, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BoolConst[POST_ACTION] = (void* (*) (doggy_BoolConst, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringConst[PRE_ACTION] = (void* (*) (doggy_StringConst, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringConst[POST_ACTION] = (void* (*) (doggy_StringConst, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NullConst[PRE_ACTION] = (void* (*) (doggy_NullConst, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NullConst[POST_ACTION] = (void* (*) (doggy_NullConst, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Definition[PRE_ACTION] = (void* (*) (doggy_Definition, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Definition[POST_ACTION] = (void* (*) (doggy_Definition, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Type[PRE_ACTION] = (void* (*) (doggy_Type, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Type[POST_ACTION] = (void* (*) (doggy_Type, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EdgeType[PRE_ACTION] = (void* (*) (doggy_EdgeType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EdgeType[POST_ACTION] = (void* (*) (doggy_EdgeType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TupleType[PRE_ACTION] = (void* (*) (doggy_TupleType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TupleType[POST_ACTION] = (void* (*) (doggy_TupleType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicType[PRE_ACTION] = (void* (*) (doggy_BasicType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicType[POST_ACTION] = (void* (*) (doggy_BasicType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentType[PRE_ACTION] = (void* (*) (doggy_IdentType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentType[POST_ACTION] = (void* (*) (doggy_IdentType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OprType[PRE_ACTION] = (void* (*) (doggy_OprType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OprType[POST_ACTION] = (void* (*) (doggy_OprType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PointerType[PRE_ACTION] = (void* (*) (doggy_PointerType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PointerType[POST_ACTION] = (void* (*) (doggy_PointerType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RangeType[PRE_ACTION] = (void* (*) (doggy_RangeType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RangeType[POST_ACTION] = (void* (*) (doggy_RangeType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FRangeType[PRE_ACTION] = (void* (*) (doggy_FRangeType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FRangeType[POST_ACTION] = (void* (*) (doggy_FRangeType, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Num[PRE_ACTION] = (void* (*) (doggy_Num, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Num[POST_ACTION] = (void* (*) (doggy_Num, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdInt[PRE_ACTION] = (void* (*) (doggy_IdInt, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdInt[POST_ACTION] = (void* (*) (doggy_IdInt, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IsId[PRE_ACTION] = (void* (*) (doggy_IsId, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IsId[POST_ACTION] = (void* (*) (doggy_IsId, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IsInt[PRE_ACTION] = (void* (*) (doggy_IsInt, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IsInt[POST_ACTION] = (void* (*) (doggy_IsInt, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Path[PRE_ACTION] = (void* (*) (doggy_Path, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Path[POST_ACTION] = (void* (*) (doggy_Path, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ActualOp[PRE_ACTION] = (void* (*) (doggy_ActualOp, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ActualOp[POST_ACTION] = (void* (*) (doggy_ActualOp, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypePair[PRE_ACTION] = (void* (*) (doggy_TypePair, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypePair[POST_ACTION] = (void* (*) (doggy_TypePair, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Opat[PRE_ACTION] = (void* (*) (doggy_Opat, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Opat[POST_ACTION] = (void* (*) (doggy_Opat, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Format[PRE_ACTION] = (void* (*) (doggy_Format, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Format[POST_ACTION] = (void* (*) (doggy_Format, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_dummy_type[PRE_ACTION] = (void* (*) (doggy_dummy_type, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_dummy_type[POST_ACTION] = (void* (*) (doggy_dummy_type, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void* (*) (doggy_Scope, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void* (*) (doggy_Scope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpSetScope[PRE_ACTION] = (void* (*) (doggy_OpSetScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpSetScope[POST_ACTION] = (void* (*) (doggy_OpSetScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedOpScope[PRE_ACTION] = (void* (*) (doggy_AppliedOpScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedOpScope[POST_ACTION] = (void* (*) (doggy_AppliedOpScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprGuardScope[PRE_ACTION] = (void* (*) (doggy_ExprGuardScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprGuardScope[POST_ACTION] = (void* (*) (doggy_ExprGuardScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RhsGuardScope[PRE_ACTION] = (void* (*) (doggy_RhsGuardScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RhsGuardScope[POST_ACTION] = (void* (*) (doggy_RhsGuardScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncRuleScope[PRE_ACTION] = (void* (*) (doggy_FuncRuleScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncRuleScope[POST_ACTION] = (void* (*) (doggy_FuncRuleScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RuleScope[PRE_ACTION] = (void* (*) (doggy_RuleScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RuleScope[POST_ACTION] = (void* (*) (doggy_RuleScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_machine_descriptionScope[PRE_ACTION] = (void* (*) (doggy_machine_descriptionScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_machine_descriptionScope[POST_ACTION] = (void* (*) (doggy_machine_descriptionScope, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Num[PRE_ACTION] = (void* (*) (List_doggy_Num, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Num[POST_ACTION] = (void* (*) (List_doggy_Num, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_TypePair[PRE_ACTION] = (void* (*) (List_List_doggy_TypePair, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_TypePair[POST_ACTION] = (void* (*) (List_List_doggy_TypePair, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_TypePair[PRE_ACTION] = (void* (*) (List_doggy_TypePair, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_TypePair[POST_ACTION] = (void* (*) (List_doggy_TypePair, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ActualOp[PRE_ACTION] = (void* (*) (List_doggy_ActualOp, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ActualOp[POST_ACTION] = (void* (*) (List_doggy_ActualOp, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_Type[PRE_ACTION] = (void* (*) (List_List_doggy_Type, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_Type[POST_ACTION] = (void* (*) (List_List_doggy_Type, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Operator[PRE_ACTION] = (void* (*) (List_doggy_Operator, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Operator[POST_ACTION] = (void* (*) (List_doggy_Operator, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Definition[PRE_ACTION] = (void* (*) (List_doggy_Definition, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Definition[POST_ACTION] = (void* (*) (List_doggy_Definition, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expr[PRE_ACTION] = (void* (*) (List_doggy_Expr, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expr[POST_ACTION] = (void* (*) (List_doggy_Expr, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Guard[PRE_ACTION] = (void* (*) (List_doggy_Guard, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Guard[POST_ACTION] = (void* (*) (List_doggy_Guard, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Pattern[PRE_ACTION] = (void* (*) (List_doggy_Pattern, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Pattern[POST_ACTION] = (void* (*) (List_doggy_Pattern, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Argument[PRE_ACTION] = (void* (*) (List_doggy_Argument, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Argument[POST_ACTION] = (void* (*) (List_doggy_Argument, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FuncRule[PRE_ACTION] = (void* (*) (List_doggy_FuncRule, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FuncRule[POST_ACTION] = (void* (*) (List_doggy_FuncRule, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Attribute[PRE_ACTION] = (void* (*) (List_doggy_Attribute, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Attribute[POST_ACTION] = (void* (*) (List_doggy_Attribute, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Property[PRE_ACTION] = (void* (*) (List_doggy_Property, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Property[POST_ACTION] = (void* (*) (List_doggy_Property, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Applied_formal[PRE_ACTION] = (void* (*) (List_doggy_Applied_formal, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Applied_formal[POST_ACTION] = (void* (*) (List_doggy_Applied_formal, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Operation_def[PRE_ACTION] = (void* (*) (List_doggy_Operation_def, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Operation_def[POST_ACTION] = (void* (*) (List_doggy_Operation_def, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Type[PRE_ACTION] = (void* (*) (List_doggy_Type, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Type[POST_ACTION] = (void* (*) (List_doggy_Type, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Rule[PRE_ACTION] = (void* (*) (List_doggy_Rule, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Rule[POST_ACTION] = (void* (*) (List_doggy_Rule, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Func[PRE_ACTION] = (void* (*) (List_doggy_Func, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Func[POST_ACTION] = (void* (*) (List_doggy_Func, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Section[PRE_ACTION] = (void* (*) (List_doggy_Section, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Section[POST_ACTION] = (void* (*) (List_doggy_Section, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FunctionDef[PRE_ACTION] = (void* (*) (List_doggy_FunctionDef, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FunctionDef[POST_ACTION] = (void* (*) (List_doggy_FunctionDef, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Typedef[PRE_ACTION] = (void* (*) (List_doggy_Typedef, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Typedef[POST_ACTION] = (void* (*) (List_doggy_Typedef, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operator[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operator[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CandOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CandOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CorOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CorOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_XorOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_XorOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EqOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EqOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NeqOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NeqOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LEOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LEOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GEOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GEOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LTOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LTOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GTOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GTOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SLOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SLOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SROp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SROp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DivOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DivOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ModOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ModOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MulOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MulOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AddOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AddOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubOp[PRE_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubOp[POST_ACTION] = (void* (*) (doggy_Operator, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonOp[PRE_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonOp[POST_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NotOp[PRE_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NotOp[POST_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NegOp[PRE_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NegOp[POST_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AddrOp[PRE_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AddrOp[POST_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DerefOp[PRE_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DerefOp[POST_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlusOp[PRE_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlusOp[POST_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MinOp[PRE_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MinOp[POST_ACTION] = (void* (*) (doggy_MonOp, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Property[PRE_ACTION] = (void* (*) (doggy_Property, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Property[POST_ACTION] = (void* (*) (doggy_Property, void*))x;
}

void void_doggy_fill_table (void_doggy_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_doggy[PRE_ACTION] = (void (*) (doggy_doggy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_doggy[POST_ACTION] = (void (*) (doggy_doggy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Typedef[PRE_ACTION] = (void (*) (doggy_Typedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Typedef[POST_ACTION] = (void (*) (doggy_Typedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FunctionDef[PRE_ACTION] = (void (*) (doggy_FunctionDef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FunctionDef[POST_ACTION] = (void (*) (doggy_FunctionDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExtFunc[PRE_ACTION] = (void (*) (doggy_ExtFunc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExtFunc[POST_ACTION] = (void (*) (doggy_ExtFunc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExtVar[PRE_ACTION] = (void (*) (doggy_ExtVar))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExtVar[POST_ACTION] = (void (*) (doggy_ExtVar))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_machine_description[PRE_ACTION] = (void (*) (doggy_machine_description))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_machine_description[POST_ACTION] = (void (*) (doggy_machine_description))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operation_def[PRE_ACTION] = (void (*) (doggy_Operation_def))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operation_def[POST_ACTION] = (void (*) (doggy_Operation_def))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Attributes[PRE_ACTION] = (void (*) (doggy_Attributes))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Attributes[POST_ACTION] = (void (*) (doggy_Attributes))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Attribute[PRE_ACTION] = (void (*) (doggy_Attribute))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Attribute[POST_ACTION] = (void (*) (doggy_Attribute))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdAttr[PRE_ACTION] = (void (*) (doggy_IdAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdAttr[POST_ACTION] = (void (*) (doggy_IdAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpAttr[PRE_ACTION] = (void (*) (doggy_OpAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpAttr[POST_ACTION] = (void (*) (doggy_OpAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntAttr[PRE_ACTION] = (void (*) (doggy_IntAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntAttr[POST_ACTION] = (void (*) (doggy_IntAttr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Section[PRE_ACTION] = (void (*) (doggy_Section))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Section[POST_ACTION] = (void (*) (doggy_Section))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncSection[PRE_ACTION] = (void (*) (doggy_FuncSection))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncSection[POST_ACTION] = (void (*) (doggy_FuncSection))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RuleSection[PRE_ACTION] = (void (*) (doggy_RuleSection))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RuleSection[POST_ACTION] = (void (*) (doggy_RuleSection))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rule[PRE_ACTION] = (void (*) (doggy_Rule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rule[POST_ACTION] = (void (*) (doggy_Rule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Lhs[PRE_ACTION] = (void (*) (doggy_Lhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Lhs[POST_ACTION] = (void (*) (doggy_Lhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledLhs[PRE_ACTION] = (void (*) (doggy_LabeledLhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledLhs[POST_ACTION] = (void (*) (doggy_LabeledLhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnLabeledLhs[PRE_ACTION] = (void (*) (doggy_UnLabeledLhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnLabeledLhs[POST_ACTION] = (void (*) (doggy_UnLabeledLhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Func[PRE_ACTION] = (void (*) (doggy_Func))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Func[POST_ACTION] = (void (*) (doggy_Func))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncRule[PRE_ACTION] = (void (*) (doggy_FuncRule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncRule[POST_ACTION] = (void (*) (doggy_FuncRule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Argument[PRE_ACTION] = (void (*) (doggy_Argument))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Argument[POST_ACTION] = (void (*) (doggy_Argument))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypedArg[PRE_ACTION] = (void (*) (doggy_TypedArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypedArg[POST_ACTION] = (void (*) (doggy_TypedArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnTypedArg[PRE_ACTION] = (void (*) (doggy_UnTypedArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnTypedArg[POST_ACTION] = (void (*) (doggy_UnTypedArg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ArgPat[PRE_ACTION] = (void (*) (doggy_ArgPat))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ArgPat[POST_ACTION] = (void (*) (doggy_ArgPat))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PatArg[PRE_ACTION] = (void (*) (doggy_PatArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PatArg[POST_ACTION] = (void (*) (doggy_PatArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SetArg[PRE_ACTION] = (void (*) (doggy_SetArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SetArg[POST_ACTION] = (void (*) (doggy_SetArg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Pattern[PRE_ACTION] = (void (*) (doggy_Pattern))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Pattern[POST_ACTION] = (void (*) (doggy_Pattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypedPattern[PRE_ACTION] = (void (*) (doggy_TypedPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypedPattern[POST_ACTION] = (void (*) (doggy_TypedPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConsPattern[PRE_ACTION] = (void (*) (doggy_ConsPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConsPattern[POST_ACTION] = (void (*) (doggy_ConsPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefPattern[PRE_ACTION] = (void (*) (doggy_DefPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefPattern[POST_ACTION] = (void (*) (doggy_DefPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentPattern[PRE_ACTION] = (void (*) (doggy_IdentPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentPattern[POST_ACTION] = (void (*) (doggy_IdentPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicPattern[PRE_ACTION] = (void (*) (doggy_BasicPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicPattern[POST_ACTION] = (void (*) (doggy_BasicPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpPattern[PRE_ACTION] = (void (*) (doggy_OpPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpPattern[POST_ACTION] = (void (*) (doggy_OpPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConstPattern[PRE_ACTION] = (void (*) (doggy_ConstPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConstPattern[POST_ACTION] = (void (*) (doggy_ConstPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NullPattern[PRE_ACTION] = (void (*) (doggy_NullPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NullPattern[POST_ACTION] = (void (*) (doggy_NullPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DontCarePattern[PRE_ACTION] = (void (*) (doggy_DontCarePattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DontCarePattern[POST_ACTION] = (void (*) (doggy_DontCarePattern))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rhs[PRE_ACTION] = (void (*) (doggy_Rhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rhs[POST_ACTION] = (void (*) (doggy_Rhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlainRhs[PRE_ACTION] = (void (*) (doggy_PlainRhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlainRhs[POST_ACTION] = (void (*) (doggy_PlainRhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BlockRhs[PRE_ACTION] = (void (*) (doggy_BlockRhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BlockRhs[POST_ACTION] = (void (*) (doggy_BlockRhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Guard[PRE_ACTION] = (void (*) (doggy_Guard))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Guard[POST_ACTION] = (void (*) (doggy_Guard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RhsGuard[PRE_ACTION] = (void (*) (doggy_RhsGuard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RhsGuard[POST_ACTION] = (void (*) (doggy_RhsGuard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprGuard[PRE_ACTION] = (void (*) (doggy_ExprGuard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprGuard[POST_ACTION] = (void (*) (doggy_ExprGuard))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprSeq[PRE_ACTION] = (void (*) (doggy_ExprSeq))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprSeq[POST_ACTION] = (void (*) (doggy_ExprSeq))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OneExpr[PRE_ACTION] = (void (*) (doggy_OneExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OneExpr[POST_ACTION] = (void (*) (doggy_OneExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MoreExprs[PRE_ACTION] = (void (*) (doggy_MoreExprs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MoreExprs[POST_ACTION] = (void (*) (doggy_MoreExprs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Wherepart[PRE_ACTION] = (void (*) (doggy_Wherepart))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Wherepart[POST_ACTION] = (void (*) (doggy_Wherepart))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Applied_operation[PRE_ACTION] = (void (*) (doggy_Applied_operation))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Applied_operation[POST_ACTION] = (void (*) (doggy_Applied_operation))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AnyOp[PRE_ACTION] = (void (*) (doggy_AnyOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AnyOp[POST_ACTION] = (void (*) (doggy_AnyOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedOp[PRE_ACTION] = (void (*) (doggy_AppliedOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedOp[POST_ACTION] = (void (*) (doggy_AppliedOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpSet[PRE_ACTION] = (void (*) (doggy_OpSet))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpSet[POST_ACTION] = (void (*) (doggy_OpSet))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Applied_formal[PRE_ACTION] = (void (*) (doggy_Applied_formal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Applied_formal[POST_ACTION] = (void (*) (doggy_Applied_formal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expr[PRE_ACTION] = (void (*) (doggy_Expr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expr[POST_ACTION] = (void (*) (doggy_Expr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BinExpr[PRE_ACTION] = (void (*) (doggy_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BinExpr[POST_ACTION] = (void (*) (doggy_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConsExpr[PRE_ACTION] = (void (*) (doggy_ConsExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConsExpr[POST_ACTION] = (void (*) (doggy_ConsExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleExpr[PRE_ACTION] = (void (*) (doggy_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleExpr[POST_ACTION] = (void (*) (doggy_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentExpr[PRE_ACTION] = (void (*) (doggy_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentExpr[POST_ACTION] = (void (*) (doggy_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IfExpr[PRE_ACTION] = (void (*) (doggy_IfExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IfExpr[POST_ACTION] = (void (*) (doggy_IfExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConstExpr[PRE_ACTION] = (void (*) (doggy_ConstExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConstExpr[POST_ACTION] = (void (*) (doggy_ConstExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operation[PRE_ACTION] = (void (*) (doggy_Operation))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operation[POST_ACTION] = (void (*) (doggy_Operation))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ParExpr[PRE_ACTION] = (void (*) (doggy_ParExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ParExpr[POST_ACTION] = (void (*) (doggy_ParExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr[PRE_ACTION] = (void (*) (doggy_MonExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr[POST_ACTION] = (void (*) (doggy_MonExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Constant[PRE_ACTION] = (void (*) (doggy_Constant))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Constant[POST_ACTION] = (void (*) (doggy_Constant))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntConst[PRE_ACTION] = (void (*) (doggy_IntConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntConst[POST_ACTION] = (void (*) (doggy_IntConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BoolConst[PRE_ACTION] = (void (*) (doggy_BoolConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BoolConst[POST_ACTION] = (void (*) (doggy_BoolConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringConst[PRE_ACTION] = (void (*) (doggy_StringConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringConst[POST_ACTION] = (void (*) (doggy_StringConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NullConst[PRE_ACTION] = (void (*) (doggy_NullConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NullConst[POST_ACTION] = (void (*) (doggy_NullConst))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Definition[PRE_ACTION] = (void (*) (doggy_Definition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Definition[POST_ACTION] = (void (*) (doggy_Definition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Type[PRE_ACTION] = (void (*) (doggy_Type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Type[POST_ACTION] = (void (*) (doggy_Type))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EdgeType[PRE_ACTION] = (void (*) (doggy_EdgeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EdgeType[POST_ACTION] = (void (*) (doggy_EdgeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TupleType[PRE_ACTION] = (void (*) (doggy_TupleType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TupleType[POST_ACTION] = (void (*) (doggy_TupleType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicType[PRE_ACTION] = (void (*) (doggy_BasicType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicType[POST_ACTION] = (void (*) (doggy_BasicType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentType[PRE_ACTION] = (void (*) (doggy_IdentType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentType[POST_ACTION] = (void (*) (doggy_IdentType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OprType[PRE_ACTION] = (void (*) (doggy_OprType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OprType[POST_ACTION] = (void (*) (doggy_OprType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PointerType[PRE_ACTION] = (void (*) (doggy_PointerType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PointerType[POST_ACTION] = (void (*) (doggy_PointerType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RangeType[PRE_ACTION] = (void (*) (doggy_RangeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RangeType[POST_ACTION] = (void (*) (doggy_RangeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FRangeType[PRE_ACTION] = (void (*) (doggy_FRangeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FRangeType[POST_ACTION] = (void (*) (doggy_FRangeType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Num[PRE_ACTION] = (void (*) (doggy_Num))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Num[POST_ACTION] = (void (*) (doggy_Num))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdInt[PRE_ACTION] = (void (*) (doggy_IdInt))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdInt[POST_ACTION] = (void (*) (doggy_IdInt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IsId[PRE_ACTION] = (void (*) (doggy_IsId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IsId[POST_ACTION] = (void (*) (doggy_IsId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IsInt[PRE_ACTION] = (void (*) (doggy_IsInt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IsInt[POST_ACTION] = (void (*) (doggy_IsInt))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Path[PRE_ACTION] = (void (*) (doggy_Path))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Path[POST_ACTION] = (void (*) (doggy_Path))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ActualOp[PRE_ACTION] = (void (*) (doggy_ActualOp))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ActualOp[POST_ACTION] = (void (*) (doggy_ActualOp))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypePair[PRE_ACTION] = (void (*) (doggy_TypePair))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypePair[POST_ACTION] = (void (*) (doggy_TypePair))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Opat[PRE_ACTION] = (void (*) (doggy_Opat))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Opat[POST_ACTION] = (void (*) (doggy_Opat))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Format[PRE_ACTION] = (void (*) (doggy_Format))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Format[POST_ACTION] = (void (*) (doggy_Format))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_dummy_type[PRE_ACTION] = (void (*) (doggy_dummy_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_dummy_type[POST_ACTION] = (void (*) (doggy_dummy_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void (*) (doggy_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void (*) (doggy_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpSetScope[PRE_ACTION] = (void (*) (doggy_OpSetScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpSetScope[POST_ACTION] = (void (*) (doggy_OpSetScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedOpScope[PRE_ACTION] = (void (*) (doggy_AppliedOpScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedOpScope[POST_ACTION] = (void (*) (doggy_AppliedOpScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprGuardScope[PRE_ACTION] = (void (*) (doggy_ExprGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprGuardScope[POST_ACTION] = (void (*) (doggy_ExprGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RhsGuardScope[PRE_ACTION] = (void (*) (doggy_RhsGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RhsGuardScope[POST_ACTION] = (void (*) (doggy_RhsGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncRuleScope[PRE_ACTION] = (void (*) (doggy_FuncRuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncRuleScope[POST_ACTION] = (void (*) (doggy_FuncRuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RuleScope[PRE_ACTION] = (void (*) (doggy_RuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RuleScope[POST_ACTION] = (void (*) (doggy_RuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_machine_descriptionScope[PRE_ACTION] = (void (*) (doggy_machine_descriptionScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_machine_descriptionScope[POST_ACTION] = (void (*) (doggy_machine_descriptionScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Num[PRE_ACTION] = (void (*) (List_doggy_Num))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Num[POST_ACTION] = (void (*) (List_doggy_Num))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_TypePair[PRE_ACTION] = (void (*) (List_List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_TypePair[POST_ACTION] = (void (*) (List_List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_TypePair[PRE_ACTION] = (void (*) (List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_TypePair[POST_ACTION] = (void (*) (List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ActualOp[PRE_ACTION] = (void (*) (List_doggy_ActualOp))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ActualOp[POST_ACTION] = (void (*) (List_doggy_ActualOp))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_Type[PRE_ACTION] = (void (*) (List_List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_Type[POST_ACTION] = (void (*) (List_List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Operator[PRE_ACTION] = (void (*) (List_doggy_Operator))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Operator[POST_ACTION] = (void (*) (List_doggy_Operator))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Definition[PRE_ACTION] = (void (*) (List_doggy_Definition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Definition[POST_ACTION] = (void (*) (List_doggy_Definition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expr[PRE_ACTION] = (void (*) (List_doggy_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expr[POST_ACTION] = (void (*) (List_doggy_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Guard[PRE_ACTION] = (void (*) (List_doggy_Guard))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Guard[POST_ACTION] = (void (*) (List_doggy_Guard))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Pattern[PRE_ACTION] = (void (*) (List_doggy_Pattern))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Pattern[POST_ACTION] = (void (*) (List_doggy_Pattern))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Argument[PRE_ACTION] = (void (*) (List_doggy_Argument))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Argument[POST_ACTION] = (void (*) (List_doggy_Argument))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FuncRule[PRE_ACTION] = (void (*) (List_doggy_FuncRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FuncRule[POST_ACTION] = (void (*) (List_doggy_FuncRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Attribute[PRE_ACTION] = (void (*) (List_doggy_Attribute))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Attribute[POST_ACTION] = (void (*) (List_doggy_Attribute))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Property[PRE_ACTION] = (void (*) (List_doggy_Property))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Property[POST_ACTION] = (void (*) (List_doggy_Property))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Applied_formal[PRE_ACTION] = (void (*) (List_doggy_Applied_formal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Applied_formal[POST_ACTION] = (void (*) (List_doggy_Applied_formal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Operation_def[PRE_ACTION] = (void (*) (List_doggy_Operation_def))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Operation_def[POST_ACTION] = (void (*) (List_doggy_Operation_def))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Type[PRE_ACTION] = (void (*) (List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Type[POST_ACTION] = (void (*) (List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Rule[PRE_ACTION] = (void (*) (List_doggy_Rule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Rule[POST_ACTION] = (void (*) (List_doggy_Rule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Func[PRE_ACTION] = (void (*) (List_doggy_Func))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Func[POST_ACTION] = (void (*) (List_doggy_Func))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Section[PRE_ACTION] = (void (*) (List_doggy_Section))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Section[POST_ACTION] = (void (*) (List_doggy_Section))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FunctionDef[PRE_ACTION] = (void (*) (List_doggy_FunctionDef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FunctionDef[POST_ACTION] = (void (*) (List_doggy_FunctionDef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Typedef[PRE_ACTION] = (void (*) (List_doggy_Typedef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Typedef[POST_ACTION] = (void (*) (List_doggy_Typedef))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operator[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operator[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CandOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CandOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CorOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CorOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_XorOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_XorOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EqOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EqOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NeqOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NeqOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LEOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LEOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GEOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GEOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LTOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LTOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GTOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GTOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SLOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SLOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SROp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SROp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DivOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DivOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ModOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ModOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MulOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MulOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AddOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AddOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubOp[PRE_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubOp[POST_ACTION] = (void (*) (doggy_Operator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonOp[PRE_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonOp[POST_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NotOp[PRE_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NotOp[POST_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NegOp[PRE_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NegOp[POST_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AddrOp[PRE_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AddrOp[POST_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DerefOp[PRE_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DerefOp[POST_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlusOp[PRE_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlusOp[POST_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MinOp[PRE_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MinOp[POST_ACTION] = (void (*) (doggy_MonOp))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Property[PRE_ACTION] = (void (*) (doggy_Property))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Property[POST_ACTION] = (void (*) (doggy_Property))x;
}

void copy_doggy_fill_table (copy_doggy_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_doggy[PRE_ACTION] = (doggy_doggy (*) (doggy_doggy, doggy_doggy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_doggy[POST_ACTION] = (doggy_doggy (*) (doggy_doggy, doggy_doggy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Typedef[PRE_ACTION] = (doggy_Typedef (*) (doggy_Typedef, doggy_Typedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Typedef[POST_ACTION] = (doggy_Typedef (*) (doggy_Typedef, doggy_Typedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FunctionDef[PRE_ACTION] = (doggy_FunctionDef (*) (doggy_FunctionDef, doggy_FunctionDef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FunctionDef[POST_ACTION] = (doggy_FunctionDef (*) (doggy_FunctionDef, doggy_FunctionDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExtFunc[PRE_ACTION] = (doggy_ExtFunc (*) (doggy_ExtFunc, doggy_ExtFunc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExtFunc[POST_ACTION] = (doggy_ExtFunc (*) (doggy_ExtFunc, doggy_ExtFunc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExtVar[PRE_ACTION] = (doggy_ExtVar (*) (doggy_ExtVar, doggy_ExtVar))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExtVar[POST_ACTION] = (doggy_ExtVar (*) (doggy_ExtVar, doggy_ExtVar))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_machine_description[PRE_ACTION] = (doggy_machine_description (*) (doggy_machine_description, doggy_machine_description))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_machine_description[POST_ACTION] = (doggy_machine_description (*) (doggy_machine_description, doggy_machine_description))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operation_def[PRE_ACTION] = (doggy_Operation_def (*) (doggy_Operation_def, doggy_Operation_def))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operation_def[POST_ACTION] = (doggy_Operation_def (*) (doggy_Operation_def, doggy_Operation_def))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Attributes[PRE_ACTION] = (doggy_Attributes (*) (doggy_Attributes, doggy_Attributes))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Attributes[POST_ACTION] = (doggy_Attributes (*) (doggy_Attributes, doggy_Attributes))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Attribute[PRE_ACTION] = (doggy_Attribute (*) (doggy_Attribute, doggy_Attribute))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Attribute[POST_ACTION] = (doggy_Attribute (*) (doggy_Attribute, doggy_Attribute))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdAttr[PRE_ACTION] = (doggy_IdAttr (*) (doggy_IdAttr, doggy_IdAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdAttr[POST_ACTION] = (doggy_IdAttr (*) (doggy_IdAttr, doggy_IdAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpAttr[PRE_ACTION] = (doggy_OpAttr (*) (doggy_OpAttr, doggy_OpAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpAttr[POST_ACTION] = (doggy_OpAttr (*) (doggy_OpAttr, doggy_OpAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntAttr[PRE_ACTION] = (doggy_IntAttr (*) (doggy_IntAttr, doggy_IntAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntAttr[POST_ACTION] = (doggy_IntAttr (*) (doggy_IntAttr, doggy_IntAttr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Section[PRE_ACTION] = (doggy_Section (*) (doggy_Section, doggy_Section))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Section[POST_ACTION] = (doggy_Section (*) (doggy_Section, doggy_Section))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncSection[PRE_ACTION] = (doggy_FuncSection (*) (doggy_FuncSection, doggy_FuncSection))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncSection[POST_ACTION] = (doggy_FuncSection (*) (doggy_FuncSection, doggy_FuncSection))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RuleSection[PRE_ACTION] = (doggy_RuleSection (*) (doggy_RuleSection, doggy_RuleSection))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RuleSection[POST_ACTION] = (doggy_RuleSection (*) (doggy_RuleSection, doggy_RuleSection))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rule[PRE_ACTION] = (doggy_Rule (*) (doggy_Rule, doggy_Rule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rule[POST_ACTION] = (doggy_Rule (*) (doggy_Rule, doggy_Rule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Lhs[PRE_ACTION] = (doggy_Lhs (*) (doggy_Lhs, doggy_Lhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Lhs[POST_ACTION] = (doggy_Lhs (*) (doggy_Lhs, doggy_Lhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledLhs[PRE_ACTION] = (doggy_LabeledLhs (*) (doggy_LabeledLhs, doggy_LabeledLhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledLhs[POST_ACTION] = (doggy_LabeledLhs (*) (doggy_LabeledLhs, doggy_LabeledLhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnLabeledLhs[PRE_ACTION] = (doggy_UnLabeledLhs (*) (doggy_UnLabeledLhs, doggy_UnLabeledLhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnLabeledLhs[POST_ACTION] = (doggy_UnLabeledLhs (*) (doggy_UnLabeledLhs, doggy_UnLabeledLhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Func[PRE_ACTION] = (doggy_Func (*) (doggy_Func, doggy_Func))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Func[POST_ACTION] = (doggy_Func (*) (doggy_Func, doggy_Func))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncRule[PRE_ACTION] = (doggy_FuncRule (*) (doggy_FuncRule, doggy_FuncRule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncRule[POST_ACTION] = (doggy_FuncRule (*) (doggy_FuncRule, doggy_FuncRule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Argument[PRE_ACTION] = (doggy_Argument (*) (doggy_Argument, doggy_Argument))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Argument[POST_ACTION] = (doggy_Argument (*) (doggy_Argument, doggy_Argument))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypedArg[PRE_ACTION] = (doggy_TypedArg (*) (doggy_TypedArg, doggy_TypedArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypedArg[POST_ACTION] = (doggy_TypedArg (*) (doggy_TypedArg, doggy_TypedArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnTypedArg[PRE_ACTION] = (doggy_UnTypedArg (*) (doggy_UnTypedArg, doggy_UnTypedArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnTypedArg[POST_ACTION] = (doggy_UnTypedArg (*) (doggy_UnTypedArg, doggy_UnTypedArg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ArgPat[PRE_ACTION] = (doggy_ArgPat (*) (doggy_ArgPat, doggy_ArgPat))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ArgPat[POST_ACTION] = (doggy_ArgPat (*) (doggy_ArgPat, doggy_ArgPat))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PatArg[PRE_ACTION] = (doggy_PatArg (*) (doggy_PatArg, doggy_PatArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PatArg[POST_ACTION] = (doggy_PatArg (*) (doggy_PatArg, doggy_PatArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SetArg[PRE_ACTION] = (doggy_SetArg (*) (doggy_SetArg, doggy_SetArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SetArg[POST_ACTION] = (doggy_SetArg (*) (doggy_SetArg, doggy_SetArg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Pattern[PRE_ACTION] = (doggy_Pattern (*) (doggy_Pattern, doggy_Pattern))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Pattern[POST_ACTION] = (doggy_Pattern (*) (doggy_Pattern, doggy_Pattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypedPattern[PRE_ACTION] = (doggy_TypedPattern (*) (doggy_TypedPattern, doggy_TypedPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypedPattern[POST_ACTION] = (doggy_TypedPattern (*) (doggy_TypedPattern, doggy_TypedPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConsPattern[PRE_ACTION] = (doggy_ConsPattern (*) (doggy_ConsPattern, doggy_ConsPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConsPattern[POST_ACTION] = (doggy_ConsPattern (*) (doggy_ConsPattern, doggy_ConsPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefPattern[PRE_ACTION] = (doggy_DefPattern (*) (doggy_DefPattern, doggy_DefPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefPattern[POST_ACTION] = (doggy_DefPattern (*) (doggy_DefPattern, doggy_DefPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentPattern[PRE_ACTION] = (doggy_IdentPattern (*) (doggy_IdentPattern, doggy_IdentPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentPattern[POST_ACTION] = (doggy_IdentPattern (*) (doggy_IdentPattern, doggy_IdentPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicPattern[PRE_ACTION] = (doggy_BasicPattern (*) (doggy_BasicPattern, doggy_BasicPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicPattern[POST_ACTION] = (doggy_BasicPattern (*) (doggy_BasicPattern, doggy_BasicPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpPattern[PRE_ACTION] = (doggy_OpPattern (*) (doggy_OpPattern, doggy_OpPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpPattern[POST_ACTION] = (doggy_OpPattern (*) (doggy_OpPattern, doggy_OpPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConstPattern[PRE_ACTION] = (doggy_ConstPattern (*) (doggy_ConstPattern, doggy_ConstPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConstPattern[POST_ACTION] = (doggy_ConstPattern (*) (doggy_ConstPattern, doggy_ConstPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NullPattern[PRE_ACTION] = (doggy_NullPattern (*) (doggy_NullPattern, doggy_NullPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NullPattern[POST_ACTION] = (doggy_NullPattern (*) (doggy_NullPattern, doggy_NullPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DontCarePattern[PRE_ACTION] = (doggy_DontCarePattern (*) (doggy_DontCarePattern, doggy_DontCarePattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DontCarePattern[POST_ACTION] = (doggy_DontCarePattern (*) (doggy_DontCarePattern, doggy_DontCarePattern))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rhs[PRE_ACTION] = (doggy_Rhs (*) (doggy_Rhs, doggy_Rhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rhs[POST_ACTION] = (doggy_Rhs (*) (doggy_Rhs, doggy_Rhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlainRhs[PRE_ACTION] = (doggy_PlainRhs (*) (doggy_PlainRhs, doggy_PlainRhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlainRhs[POST_ACTION] = (doggy_PlainRhs (*) (doggy_PlainRhs, doggy_PlainRhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BlockRhs[PRE_ACTION] = (doggy_BlockRhs (*) (doggy_BlockRhs, doggy_BlockRhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BlockRhs[POST_ACTION] = (doggy_BlockRhs (*) (doggy_BlockRhs, doggy_BlockRhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Guard[PRE_ACTION] = (doggy_Guard (*) (doggy_Guard, doggy_Guard))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Guard[POST_ACTION] = (doggy_Guard (*) (doggy_Guard, doggy_Guard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RhsGuard[PRE_ACTION] = (doggy_RhsGuard (*) (doggy_RhsGuard, doggy_RhsGuard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RhsGuard[POST_ACTION] = (doggy_RhsGuard (*) (doggy_RhsGuard, doggy_RhsGuard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprGuard[PRE_ACTION] = (doggy_ExprGuard (*) (doggy_ExprGuard, doggy_ExprGuard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprGuard[POST_ACTION] = (doggy_ExprGuard (*) (doggy_ExprGuard, doggy_ExprGuard))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprSeq[PRE_ACTION] = (doggy_ExprSeq (*) (doggy_ExprSeq, doggy_ExprSeq))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprSeq[POST_ACTION] = (doggy_ExprSeq (*) (doggy_ExprSeq, doggy_ExprSeq))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OneExpr[PRE_ACTION] = (doggy_OneExpr (*) (doggy_OneExpr, doggy_OneExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OneExpr[POST_ACTION] = (doggy_OneExpr (*) (doggy_OneExpr, doggy_OneExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MoreExprs[PRE_ACTION] = (doggy_MoreExprs (*) (doggy_MoreExprs, doggy_MoreExprs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MoreExprs[POST_ACTION] = (doggy_MoreExprs (*) (doggy_MoreExprs, doggy_MoreExprs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Wherepart[PRE_ACTION] = (doggy_Wherepart (*) (doggy_Wherepart, doggy_Wherepart))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Wherepart[POST_ACTION] = (doggy_Wherepart (*) (doggy_Wherepart, doggy_Wherepart))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Applied_operation[PRE_ACTION] = (doggy_Applied_operation (*) (doggy_Applied_operation, doggy_Applied_operation))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Applied_operation[POST_ACTION] = (doggy_Applied_operation (*) (doggy_Applied_operation, doggy_Applied_operation))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AnyOp[PRE_ACTION] = (doggy_AnyOp (*) (doggy_AnyOp, doggy_AnyOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AnyOp[POST_ACTION] = (doggy_AnyOp (*) (doggy_AnyOp, doggy_AnyOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedOp[PRE_ACTION] = (doggy_AppliedOp (*) (doggy_AppliedOp, doggy_AppliedOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedOp[POST_ACTION] = (doggy_AppliedOp (*) (doggy_AppliedOp, doggy_AppliedOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpSet[PRE_ACTION] = (doggy_OpSet (*) (doggy_OpSet, doggy_OpSet))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpSet[POST_ACTION] = (doggy_OpSet (*) (doggy_OpSet, doggy_OpSet))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Applied_formal[PRE_ACTION] = (doggy_Applied_formal (*) (doggy_Applied_formal, doggy_Applied_formal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Applied_formal[POST_ACTION] = (doggy_Applied_formal (*) (doggy_Applied_formal, doggy_Applied_formal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expr[PRE_ACTION] = (doggy_Expr (*) (doggy_Expr, doggy_Expr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expr[POST_ACTION] = (doggy_Expr (*) (doggy_Expr, doggy_Expr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BinExpr[PRE_ACTION] = (doggy_BinExpr (*) (doggy_BinExpr, doggy_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BinExpr[POST_ACTION] = (doggy_BinExpr (*) (doggy_BinExpr, doggy_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConsExpr[PRE_ACTION] = (doggy_ConsExpr (*) (doggy_ConsExpr, doggy_ConsExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConsExpr[POST_ACTION] = (doggy_ConsExpr (*) (doggy_ConsExpr, doggy_ConsExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleExpr[PRE_ACTION] = (doggy_SimpleExpr (*) (doggy_SimpleExpr, doggy_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleExpr[POST_ACTION] = (doggy_SimpleExpr (*) (doggy_SimpleExpr, doggy_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentExpr[PRE_ACTION] = (doggy_IdentExpr (*) (doggy_IdentExpr, doggy_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentExpr[POST_ACTION] = (doggy_IdentExpr (*) (doggy_IdentExpr, doggy_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IfExpr[PRE_ACTION] = (doggy_IfExpr (*) (doggy_IfExpr, doggy_IfExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IfExpr[POST_ACTION] = (doggy_IfExpr (*) (doggy_IfExpr, doggy_IfExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConstExpr[PRE_ACTION] = (doggy_ConstExpr (*) (doggy_ConstExpr, doggy_ConstExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConstExpr[POST_ACTION] = (doggy_ConstExpr (*) (doggy_ConstExpr, doggy_ConstExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operation[PRE_ACTION] = (doggy_Operation (*) (doggy_Operation, doggy_Operation))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operation[POST_ACTION] = (doggy_Operation (*) (doggy_Operation, doggy_Operation))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ParExpr[PRE_ACTION] = (doggy_ParExpr (*) (doggy_ParExpr, doggy_ParExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ParExpr[POST_ACTION] = (doggy_ParExpr (*) (doggy_ParExpr, doggy_ParExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr[PRE_ACTION] = (doggy_MonExpr (*) (doggy_MonExpr, doggy_MonExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr[POST_ACTION] = (doggy_MonExpr (*) (doggy_MonExpr, doggy_MonExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Constant[PRE_ACTION] = (doggy_Constant (*) (doggy_Constant, doggy_Constant))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Constant[POST_ACTION] = (doggy_Constant (*) (doggy_Constant, doggy_Constant))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntConst[PRE_ACTION] = (doggy_IntConst (*) (doggy_IntConst, doggy_IntConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntConst[POST_ACTION] = (doggy_IntConst (*) (doggy_IntConst, doggy_IntConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BoolConst[PRE_ACTION] = (doggy_BoolConst (*) (doggy_BoolConst, doggy_BoolConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BoolConst[POST_ACTION] = (doggy_BoolConst (*) (doggy_BoolConst, doggy_BoolConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringConst[PRE_ACTION] = (doggy_StringConst (*) (doggy_StringConst, doggy_StringConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringConst[POST_ACTION] = (doggy_StringConst (*) (doggy_StringConst, doggy_StringConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NullConst[PRE_ACTION] = (doggy_NullConst (*) (doggy_NullConst, doggy_NullConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NullConst[POST_ACTION] = (doggy_NullConst (*) (doggy_NullConst, doggy_NullConst))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Definition[PRE_ACTION] = (doggy_Definition (*) (doggy_Definition, doggy_Definition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Definition[POST_ACTION] = (doggy_Definition (*) (doggy_Definition, doggy_Definition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Type[PRE_ACTION] = (doggy_Type (*) (doggy_Type, doggy_Type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Type[POST_ACTION] = (doggy_Type (*) (doggy_Type, doggy_Type))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EdgeType[PRE_ACTION] = (doggy_EdgeType (*) (doggy_EdgeType, doggy_EdgeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EdgeType[POST_ACTION] = (doggy_EdgeType (*) (doggy_EdgeType, doggy_EdgeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TupleType[PRE_ACTION] = (doggy_TupleType (*) (doggy_TupleType, doggy_TupleType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TupleType[POST_ACTION] = (doggy_TupleType (*) (doggy_TupleType, doggy_TupleType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicType[PRE_ACTION] = (doggy_BasicType (*) (doggy_BasicType, doggy_BasicType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicType[POST_ACTION] = (doggy_BasicType (*) (doggy_BasicType, doggy_BasicType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentType[PRE_ACTION] = (doggy_IdentType (*) (doggy_IdentType, doggy_IdentType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentType[POST_ACTION] = (doggy_IdentType (*) (doggy_IdentType, doggy_IdentType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OprType[PRE_ACTION] = (doggy_OprType (*) (doggy_OprType, doggy_OprType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OprType[POST_ACTION] = (doggy_OprType (*) (doggy_OprType, doggy_OprType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PointerType[PRE_ACTION] = (doggy_PointerType (*) (doggy_PointerType, doggy_PointerType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PointerType[POST_ACTION] = (doggy_PointerType (*) (doggy_PointerType, doggy_PointerType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RangeType[PRE_ACTION] = (doggy_RangeType (*) (doggy_RangeType, doggy_RangeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RangeType[POST_ACTION] = (doggy_RangeType (*) (doggy_RangeType, doggy_RangeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FRangeType[PRE_ACTION] = (doggy_FRangeType (*) (doggy_FRangeType, doggy_FRangeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FRangeType[POST_ACTION] = (doggy_FRangeType (*) (doggy_FRangeType, doggy_FRangeType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Num[PRE_ACTION] = (doggy_Num (*) (doggy_Num, doggy_Num))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Num[POST_ACTION] = (doggy_Num (*) (doggy_Num, doggy_Num))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdInt[PRE_ACTION] = (doggy_IdInt (*) (doggy_IdInt, doggy_IdInt))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdInt[POST_ACTION] = (doggy_IdInt (*) (doggy_IdInt, doggy_IdInt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IsId[PRE_ACTION] = (doggy_IsId (*) (doggy_IsId, doggy_IsId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IsId[POST_ACTION] = (doggy_IsId (*) (doggy_IsId, doggy_IsId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IsInt[PRE_ACTION] = (doggy_IsInt (*) (doggy_IsInt, doggy_IsInt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IsInt[POST_ACTION] = (doggy_IsInt (*) (doggy_IsInt, doggy_IsInt))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Path[PRE_ACTION] = (doggy_Path (*) (doggy_Path, doggy_Path))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Path[POST_ACTION] = (doggy_Path (*) (doggy_Path, doggy_Path))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ActualOp[PRE_ACTION] = (doggy_ActualOp (*) (doggy_ActualOp, doggy_ActualOp))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ActualOp[POST_ACTION] = (doggy_ActualOp (*) (doggy_ActualOp, doggy_ActualOp))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypePair[PRE_ACTION] = (doggy_TypePair (*) (doggy_TypePair, doggy_TypePair))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypePair[POST_ACTION] = (doggy_TypePair (*) (doggy_TypePair, doggy_TypePair))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Opat[PRE_ACTION] = (doggy_Opat (*) (doggy_Opat, doggy_Opat))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Opat[POST_ACTION] = (doggy_Opat (*) (doggy_Opat, doggy_Opat))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Format[PRE_ACTION] = (doggy_Format (*) (doggy_Format, doggy_Format))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Format[POST_ACTION] = (doggy_Format (*) (doggy_Format, doggy_Format))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_dummy_type[PRE_ACTION] = (doggy_dummy_type (*) (doggy_dummy_type, doggy_dummy_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_dummy_type[POST_ACTION] = (doggy_dummy_type (*) (doggy_dummy_type, doggy_dummy_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (doggy_Scope (*) (doggy_Scope, doggy_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (doggy_Scope (*) (doggy_Scope, doggy_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpSetScope[PRE_ACTION] = (doggy_OpSetScope (*) (doggy_OpSetScope, doggy_OpSetScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpSetScope[POST_ACTION] = (doggy_OpSetScope (*) (doggy_OpSetScope, doggy_OpSetScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedOpScope[PRE_ACTION] = (doggy_AppliedOpScope (*) (doggy_AppliedOpScope, doggy_AppliedOpScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedOpScope[POST_ACTION] = (doggy_AppliedOpScope (*) (doggy_AppliedOpScope, doggy_AppliedOpScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprGuardScope[PRE_ACTION] = (doggy_ExprGuardScope (*) (doggy_ExprGuardScope, doggy_ExprGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprGuardScope[POST_ACTION] = (doggy_ExprGuardScope (*) (doggy_ExprGuardScope, doggy_ExprGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RhsGuardScope[PRE_ACTION] = (doggy_RhsGuardScope (*) (doggy_RhsGuardScope, doggy_RhsGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RhsGuardScope[POST_ACTION] = (doggy_RhsGuardScope (*) (doggy_RhsGuardScope, doggy_RhsGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncRuleScope[PRE_ACTION] = (doggy_FuncRuleScope (*) (doggy_FuncRuleScope, doggy_FuncRuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncRuleScope[POST_ACTION] = (doggy_FuncRuleScope (*) (doggy_FuncRuleScope, doggy_FuncRuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RuleScope[PRE_ACTION] = (doggy_RuleScope (*) (doggy_RuleScope, doggy_RuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RuleScope[POST_ACTION] = (doggy_RuleScope (*) (doggy_RuleScope, doggy_RuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_machine_descriptionScope[PRE_ACTION] = (doggy_machine_descriptionScope (*) (doggy_machine_descriptionScope, doggy_machine_descriptionScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_machine_descriptionScope[POST_ACTION] = (doggy_machine_descriptionScope (*) (doggy_machine_descriptionScope, doggy_machine_descriptionScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Num[PRE_ACTION] = (List_doggy_Num (*) (List_doggy_Num, List_doggy_Num))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Num[POST_ACTION] = (List_doggy_Num (*) (List_doggy_Num, List_doggy_Num))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_TypePair[PRE_ACTION] = (List_List_doggy_TypePair (*) (List_List_doggy_TypePair, List_List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_TypePair[POST_ACTION] = (List_List_doggy_TypePair (*) (List_List_doggy_TypePair, List_List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_TypePair[PRE_ACTION] = (List_doggy_TypePair (*) (List_doggy_TypePair, List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_TypePair[POST_ACTION] = (List_doggy_TypePair (*) (List_doggy_TypePair, List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ActualOp[PRE_ACTION] = (List_doggy_ActualOp (*) (List_doggy_ActualOp, List_doggy_ActualOp))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ActualOp[POST_ACTION] = (List_doggy_ActualOp (*) (List_doggy_ActualOp, List_doggy_ActualOp))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_Type[PRE_ACTION] = (List_List_doggy_Type (*) (List_List_doggy_Type, List_List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_Type[POST_ACTION] = (List_List_doggy_Type (*) (List_List_doggy_Type, List_List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Operator[PRE_ACTION] = (List_doggy_Operator (*) (List_doggy_Operator, List_doggy_Operator))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Operator[POST_ACTION] = (List_doggy_Operator (*) (List_doggy_Operator, List_doggy_Operator))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Definition[PRE_ACTION] = (List_doggy_Definition (*) (List_doggy_Definition, List_doggy_Definition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Definition[POST_ACTION] = (List_doggy_Definition (*) (List_doggy_Definition, List_doggy_Definition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expr[PRE_ACTION] = (List_doggy_Expr (*) (List_doggy_Expr, List_doggy_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expr[POST_ACTION] = (List_doggy_Expr (*) (List_doggy_Expr, List_doggy_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Guard[PRE_ACTION] = (List_doggy_Guard (*) (List_doggy_Guard, List_doggy_Guard))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Guard[POST_ACTION] = (List_doggy_Guard (*) (List_doggy_Guard, List_doggy_Guard))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Pattern[PRE_ACTION] = (List_doggy_Pattern (*) (List_doggy_Pattern, List_doggy_Pattern))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Pattern[POST_ACTION] = (List_doggy_Pattern (*) (List_doggy_Pattern, List_doggy_Pattern))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Argument[PRE_ACTION] = (List_doggy_Argument (*) (List_doggy_Argument, List_doggy_Argument))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Argument[POST_ACTION] = (List_doggy_Argument (*) (List_doggy_Argument, List_doggy_Argument))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FuncRule[PRE_ACTION] = (List_doggy_FuncRule (*) (List_doggy_FuncRule, List_doggy_FuncRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FuncRule[POST_ACTION] = (List_doggy_FuncRule (*) (List_doggy_FuncRule, List_doggy_FuncRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Attribute[PRE_ACTION] = (List_doggy_Attribute (*) (List_doggy_Attribute, List_doggy_Attribute))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Attribute[POST_ACTION] = (List_doggy_Attribute (*) (List_doggy_Attribute, List_doggy_Attribute))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Property[PRE_ACTION] = (List_doggy_Property (*) (List_doggy_Property, List_doggy_Property))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Property[POST_ACTION] = (List_doggy_Property (*) (List_doggy_Property, List_doggy_Property))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Applied_formal[PRE_ACTION] = (List_doggy_Applied_formal (*) (List_doggy_Applied_formal, List_doggy_Applied_formal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Applied_formal[POST_ACTION] = (List_doggy_Applied_formal (*) (List_doggy_Applied_formal, List_doggy_Applied_formal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Operation_def[PRE_ACTION] = (List_doggy_Operation_def (*) (List_doggy_Operation_def, List_doggy_Operation_def))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Operation_def[POST_ACTION] = (List_doggy_Operation_def (*) (List_doggy_Operation_def, List_doggy_Operation_def))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Type[PRE_ACTION] = (List_doggy_Type (*) (List_doggy_Type, List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Type[POST_ACTION] = (List_doggy_Type (*) (List_doggy_Type, List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Rule[PRE_ACTION] = (List_doggy_Rule (*) (List_doggy_Rule, List_doggy_Rule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Rule[POST_ACTION] = (List_doggy_Rule (*) (List_doggy_Rule, List_doggy_Rule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Func[PRE_ACTION] = (List_doggy_Func (*) (List_doggy_Func, List_doggy_Func))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Func[POST_ACTION] = (List_doggy_Func (*) (List_doggy_Func, List_doggy_Func))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Section[PRE_ACTION] = (List_doggy_Section (*) (List_doggy_Section, List_doggy_Section))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Section[POST_ACTION] = (List_doggy_Section (*) (List_doggy_Section, List_doggy_Section))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FunctionDef[PRE_ACTION] = (List_doggy_FunctionDef (*) (List_doggy_FunctionDef, List_doggy_FunctionDef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FunctionDef[POST_ACTION] = (List_doggy_FunctionDef (*) (List_doggy_FunctionDef, List_doggy_FunctionDef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Typedef[PRE_ACTION] = (List_doggy_Typedef (*) (List_doggy_Typedef, List_doggy_Typedef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Typedef[POST_ACTION] = (List_doggy_Typedef (*) (List_doggy_Typedef, List_doggy_Typedef))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operator[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operator[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CandOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CandOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CorOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CorOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_XorOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_XorOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EqOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EqOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NeqOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NeqOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LEOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LEOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GEOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GEOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LTOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LTOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GTOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GTOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SLOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SLOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SROp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SROp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DivOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DivOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ModOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ModOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MulOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MulOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AddOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AddOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubOp[PRE_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubOp[POST_ACTION] = (doggy_Operator (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonOp[PRE_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonOp[POST_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NotOp[PRE_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NotOp[POST_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NegOp[PRE_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NegOp[POST_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AddrOp[PRE_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AddrOp[POST_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DerefOp[PRE_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DerefOp[POST_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlusOp[PRE_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlusOp[POST_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MinOp[PRE_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MinOp[POST_ACTION] = (doggy_MonOp (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Property[PRE_ACTION] = (doggy_Property (*) (doggy_Property, doggy_Property))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Property[POST_ACTION] = (doggy_Property (*) (doggy_Property, doggy_Property))x;
}

void compare_doggy_fill_table (compare_doggy_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_doggy[PRE_ACTION] = (int (*) (doggy_doggy, doggy_doggy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_doggy[POST_ACTION] = (int (*) (doggy_doggy, doggy_doggy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Typedef[PRE_ACTION] = (int (*) (doggy_Typedef, doggy_Typedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Typedef[POST_ACTION] = (int (*) (doggy_Typedef, doggy_Typedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FunctionDef[PRE_ACTION] = (int (*) (doggy_FunctionDef, doggy_FunctionDef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FunctionDef[POST_ACTION] = (int (*) (doggy_FunctionDef, doggy_FunctionDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExtFunc[PRE_ACTION] = (int (*) (doggy_ExtFunc, doggy_ExtFunc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExtFunc[POST_ACTION] = (int (*) (doggy_ExtFunc, doggy_ExtFunc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExtVar[PRE_ACTION] = (int (*) (doggy_ExtVar, doggy_ExtVar))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExtVar[POST_ACTION] = (int (*) (doggy_ExtVar, doggy_ExtVar))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_machine_description[PRE_ACTION] = (int (*) (doggy_machine_description, doggy_machine_description))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_machine_description[POST_ACTION] = (int (*) (doggy_machine_description, doggy_machine_description))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operation_def[PRE_ACTION] = (int (*) (doggy_Operation_def, doggy_Operation_def))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operation_def[POST_ACTION] = (int (*) (doggy_Operation_def, doggy_Operation_def))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Attributes[PRE_ACTION] = (int (*) (doggy_Attributes, doggy_Attributes))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Attributes[POST_ACTION] = (int (*) (doggy_Attributes, doggy_Attributes))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Attribute[PRE_ACTION] = (int (*) (doggy_Attribute, doggy_Attribute))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Attribute[POST_ACTION] = (int (*) (doggy_Attribute, doggy_Attribute))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdAttr[PRE_ACTION] = (int (*) (doggy_IdAttr, doggy_IdAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdAttr[POST_ACTION] = (int (*) (doggy_IdAttr, doggy_IdAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpAttr[PRE_ACTION] = (int (*) (doggy_OpAttr, doggy_OpAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpAttr[POST_ACTION] = (int (*) (doggy_OpAttr, doggy_OpAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntAttr[PRE_ACTION] = (int (*) (doggy_IntAttr, doggy_IntAttr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntAttr[POST_ACTION] = (int (*) (doggy_IntAttr, doggy_IntAttr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Section[PRE_ACTION] = (int (*) (doggy_Section, doggy_Section))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Section[POST_ACTION] = (int (*) (doggy_Section, doggy_Section))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncSection[PRE_ACTION] = (int (*) (doggy_FuncSection, doggy_FuncSection))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncSection[POST_ACTION] = (int (*) (doggy_FuncSection, doggy_FuncSection))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RuleSection[PRE_ACTION] = (int (*) (doggy_RuleSection, doggy_RuleSection))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RuleSection[POST_ACTION] = (int (*) (doggy_RuleSection, doggy_RuleSection))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rule[PRE_ACTION] = (int (*) (doggy_Rule, doggy_Rule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rule[POST_ACTION] = (int (*) (doggy_Rule, doggy_Rule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Lhs[PRE_ACTION] = (int (*) (doggy_Lhs, doggy_Lhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Lhs[POST_ACTION] = (int (*) (doggy_Lhs, doggy_Lhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledLhs[PRE_ACTION] = (int (*) (doggy_LabeledLhs, doggy_LabeledLhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledLhs[POST_ACTION] = (int (*) (doggy_LabeledLhs, doggy_LabeledLhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnLabeledLhs[PRE_ACTION] = (int (*) (doggy_UnLabeledLhs, doggy_UnLabeledLhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnLabeledLhs[POST_ACTION] = (int (*) (doggy_UnLabeledLhs, doggy_UnLabeledLhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Func[PRE_ACTION] = (int (*) (doggy_Func, doggy_Func))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Func[POST_ACTION] = (int (*) (doggy_Func, doggy_Func))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncRule[PRE_ACTION] = (int (*) (doggy_FuncRule, doggy_FuncRule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncRule[POST_ACTION] = (int (*) (doggy_FuncRule, doggy_FuncRule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Argument[PRE_ACTION] = (int (*) (doggy_Argument, doggy_Argument))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Argument[POST_ACTION] = (int (*) (doggy_Argument, doggy_Argument))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypedArg[PRE_ACTION] = (int (*) (doggy_TypedArg, doggy_TypedArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypedArg[POST_ACTION] = (int (*) (doggy_TypedArg, doggy_TypedArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnTypedArg[PRE_ACTION] = (int (*) (doggy_UnTypedArg, doggy_UnTypedArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnTypedArg[POST_ACTION] = (int (*) (doggy_UnTypedArg, doggy_UnTypedArg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ArgPat[PRE_ACTION] = (int (*) (doggy_ArgPat, doggy_ArgPat))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ArgPat[POST_ACTION] = (int (*) (doggy_ArgPat, doggy_ArgPat))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PatArg[PRE_ACTION] = (int (*) (doggy_PatArg, doggy_PatArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PatArg[POST_ACTION] = (int (*) (doggy_PatArg, doggy_PatArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SetArg[PRE_ACTION] = (int (*) (doggy_SetArg, doggy_SetArg))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SetArg[POST_ACTION] = (int (*) (doggy_SetArg, doggy_SetArg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Pattern[PRE_ACTION] = (int (*) (doggy_Pattern, doggy_Pattern))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Pattern[POST_ACTION] = (int (*) (doggy_Pattern, doggy_Pattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypedPattern[PRE_ACTION] = (int (*) (doggy_TypedPattern, doggy_TypedPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypedPattern[POST_ACTION] = (int (*) (doggy_TypedPattern, doggy_TypedPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConsPattern[PRE_ACTION] = (int (*) (doggy_ConsPattern, doggy_ConsPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConsPattern[POST_ACTION] = (int (*) (doggy_ConsPattern, doggy_ConsPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefPattern[PRE_ACTION] = (int (*) (doggy_DefPattern, doggy_DefPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefPattern[POST_ACTION] = (int (*) (doggy_DefPattern, doggy_DefPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentPattern[PRE_ACTION] = (int (*) (doggy_IdentPattern, doggy_IdentPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentPattern[POST_ACTION] = (int (*) (doggy_IdentPattern, doggy_IdentPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicPattern[PRE_ACTION] = (int (*) (doggy_BasicPattern, doggy_BasicPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicPattern[POST_ACTION] = (int (*) (doggy_BasicPattern, doggy_BasicPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpPattern[PRE_ACTION] = (int (*) (doggy_OpPattern, doggy_OpPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpPattern[POST_ACTION] = (int (*) (doggy_OpPattern, doggy_OpPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConstPattern[PRE_ACTION] = (int (*) (doggy_ConstPattern, doggy_ConstPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConstPattern[POST_ACTION] = (int (*) (doggy_ConstPattern, doggy_ConstPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NullPattern[PRE_ACTION] = (int (*) (doggy_NullPattern, doggy_NullPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NullPattern[POST_ACTION] = (int (*) (doggy_NullPattern, doggy_NullPattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DontCarePattern[PRE_ACTION] = (int (*) (doggy_DontCarePattern, doggy_DontCarePattern))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DontCarePattern[POST_ACTION] = (int (*) (doggy_DontCarePattern, doggy_DontCarePattern))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rhs[PRE_ACTION] = (int (*) (doggy_Rhs, doggy_Rhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rhs[POST_ACTION] = (int (*) (doggy_Rhs, doggy_Rhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlainRhs[PRE_ACTION] = (int (*) (doggy_PlainRhs, doggy_PlainRhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlainRhs[POST_ACTION] = (int (*) (doggy_PlainRhs, doggy_PlainRhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BlockRhs[PRE_ACTION] = (int (*) (doggy_BlockRhs, doggy_BlockRhs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BlockRhs[POST_ACTION] = (int (*) (doggy_BlockRhs, doggy_BlockRhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Guard[PRE_ACTION] = (int (*) (doggy_Guard, doggy_Guard))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Guard[POST_ACTION] = (int (*) (doggy_Guard, doggy_Guard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RhsGuard[PRE_ACTION] = (int (*) (doggy_RhsGuard, doggy_RhsGuard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RhsGuard[POST_ACTION] = (int (*) (doggy_RhsGuard, doggy_RhsGuard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprGuard[PRE_ACTION] = (int (*) (doggy_ExprGuard, doggy_ExprGuard))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprGuard[POST_ACTION] = (int (*) (doggy_ExprGuard, doggy_ExprGuard))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprSeq[PRE_ACTION] = (int (*) (doggy_ExprSeq, doggy_ExprSeq))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprSeq[POST_ACTION] = (int (*) (doggy_ExprSeq, doggy_ExprSeq))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OneExpr[PRE_ACTION] = (int (*) (doggy_OneExpr, doggy_OneExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OneExpr[POST_ACTION] = (int (*) (doggy_OneExpr, doggy_OneExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MoreExprs[PRE_ACTION] = (int (*) (doggy_MoreExprs, doggy_MoreExprs))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MoreExprs[POST_ACTION] = (int (*) (doggy_MoreExprs, doggy_MoreExprs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Wherepart[PRE_ACTION] = (int (*) (doggy_Wherepart, doggy_Wherepart))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Wherepart[POST_ACTION] = (int (*) (doggy_Wherepart, doggy_Wherepart))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Applied_operation[PRE_ACTION] = (int (*) (doggy_Applied_operation, doggy_Applied_operation))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Applied_operation[POST_ACTION] = (int (*) (doggy_Applied_operation, doggy_Applied_operation))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AnyOp[PRE_ACTION] = (int (*) (doggy_AnyOp, doggy_AnyOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AnyOp[POST_ACTION] = (int (*) (doggy_AnyOp, doggy_AnyOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedOp[PRE_ACTION] = (int (*) (doggy_AppliedOp, doggy_AppliedOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedOp[POST_ACTION] = (int (*) (doggy_AppliedOp, doggy_AppliedOp))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpSet[PRE_ACTION] = (int (*) (doggy_OpSet, doggy_OpSet))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpSet[POST_ACTION] = (int (*) (doggy_OpSet, doggy_OpSet))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Applied_formal[PRE_ACTION] = (int (*) (doggy_Applied_formal, doggy_Applied_formal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Applied_formal[POST_ACTION] = (int (*) (doggy_Applied_formal, doggy_Applied_formal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expr[PRE_ACTION] = (int (*) (doggy_Expr, doggy_Expr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expr[POST_ACTION] = (int (*) (doggy_Expr, doggy_Expr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BinExpr[PRE_ACTION] = (int (*) (doggy_BinExpr, doggy_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BinExpr[POST_ACTION] = (int (*) (doggy_BinExpr, doggy_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConsExpr[PRE_ACTION] = (int (*) (doggy_ConsExpr, doggy_ConsExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConsExpr[POST_ACTION] = (int (*) (doggy_ConsExpr, doggy_ConsExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleExpr[PRE_ACTION] = (int (*) (doggy_SimpleExpr, doggy_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleExpr[POST_ACTION] = (int (*) (doggy_SimpleExpr, doggy_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentExpr[PRE_ACTION] = (int (*) (doggy_IdentExpr, doggy_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentExpr[POST_ACTION] = (int (*) (doggy_IdentExpr, doggy_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IfExpr[PRE_ACTION] = (int (*) (doggy_IfExpr, doggy_IfExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IfExpr[POST_ACTION] = (int (*) (doggy_IfExpr, doggy_IfExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ConstExpr[PRE_ACTION] = (int (*) (doggy_ConstExpr, doggy_ConstExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ConstExpr[POST_ACTION] = (int (*) (doggy_ConstExpr, doggy_ConstExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operation[PRE_ACTION] = (int (*) (doggy_Operation, doggy_Operation))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operation[POST_ACTION] = (int (*) (doggy_Operation, doggy_Operation))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ParExpr[PRE_ACTION] = (int (*) (doggy_ParExpr, doggy_ParExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ParExpr[POST_ACTION] = (int (*) (doggy_ParExpr, doggy_ParExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr[PRE_ACTION] = (int (*) (doggy_MonExpr, doggy_MonExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr[POST_ACTION] = (int (*) (doggy_MonExpr, doggy_MonExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Constant[PRE_ACTION] = (int (*) (doggy_Constant, doggy_Constant))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Constant[POST_ACTION] = (int (*) (doggy_Constant, doggy_Constant))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntConst[PRE_ACTION] = (int (*) (doggy_IntConst, doggy_IntConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntConst[POST_ACTION] = (int (*) (doggy_IntConst, doggy_IntConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BoolConst[PRE_ACTION] = (int (*) (doggy_BoolConst, doggy_BoolConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BoolConst[POST_ACTION] = (int (*) (doggy_BoolConst, doggy_BoolConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringConst[PRE_ACTION] = (int (*) (doggy_StringConst, doggy_StringConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringConst[POST_ACTION] = (int (*) (doggy_StringConst, doggy_StringConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NullConst[PRE_ACTION] = (int (*) (doggy_NullConst, doggy_NullConst))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NullConst[POST_ACTION] = (int (*) (doggy_NullConst, doggy_NullConst))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Definition[PRE_ACTION] = (int (*) (doggy_Definition, doggy_Definition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Definition[POST_ACTION] = (int (*) (doggy_Definition, doggy_Definition))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Type[PRE_ACTION] = (int (*) (doggy_Type, doggy_Type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Type[POST_ACTION] = (int (*) (doggy_Type, doggy_Type))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EdgeType[PRE_ACTION] = (int (*) (doggy_EdgeType, doggy_EdgeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EdgeType[POST_ACTION] = (int (*) (doggy_EdgeType, doggy_EdgeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TupleType[PRE_ACTION] = (int (*) (doggy_TupleType, doggy_TupleType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TupleType[POST_ACTION] = (int (*) (doggy_TupleType, doggy_TupleType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicType[PRE_ACTION] = (int (*) (doggy_BasicType, doggy_BasicType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicType[POST_ACTION] = (int (*) (doggy_BasicType, doggy_BasicType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentType[PRE_ACTION] = (int (*) (doggy_IdentType, doggy_IdentType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentType[POST_ACTION] = (int (*) (doggy_IdentType, doggy_IdentType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OprType[PRE_ACTION] = (int (*) (doggy_OprType, doggy_OprType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OprType[POST_ACTION] = (int (*) (doggy_OprType, doggy_OprType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PointerType[PRE_ACTION] = (int (*) (doggy_PointerType, doggy_PointerType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PointerType[POST_ACTION] = (int (*) (doggy_PointerType, doggy_PointerType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RangeType[PRE_ACTION] = (int (*) (doggy_RangeType, doggy_RangeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RangeType[POST_ACTION] = (int (*) (doggy_RangeType, doggy_RangeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FRangeType[PRE_ACTION] = (int (*) (doggy_FRangeType, doggy_FRangeType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FRangeType[POST_ACTION] = (int (*) (doggy_FRangeType, doggy_FRangeType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Num[PRE_ACTION] = (int (*) (doggy_Num, doggy_Num))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Num[POST_ACTION] = (int (*) (doggy_Num, doggy_Num))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdInt[PRE_ACTION] = (int (*) (doggy_IdInt, doggy_IdInt))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdInt[POST_ACTION] = (int (*) (doggy_IdInt, doggy_IdInt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IsId[PRE_ACTION] = (int (*) (doggy_IsId, doggy_IsId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IsId[POST_ACTION] = (int (*) (doggy_IsId, doggy_IsId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IsInt[PRE_ACTION] = (int (*) (doggy_IsInt, doggy_IsInt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IsInt[POST_ACTION] = (int (*) (doggy_IsInt, doggy_IsInt))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Path[PRE_ACTION] = (int (*) (doggy_Path, doggy_Path))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Path[POST_ACTION] = (int (*) (doggy_Path, doggy_Path))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ActualOp[PRE_ACTION] = (int (*) (doggy_ActualOp, doggy_ActualOp))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ActualOp[POST_ACTION] = (int (*) (doggy_ActualOp, doggy_ActualOp))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypePair[PRE_ACTION] = (int (*) (doggy_TypePair, doggy_TypePair))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypePair[POST_ACTION] = (int (*) (doggy_TypePair, doggy_TypePair))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Opat[PRE_ACTION] = (int (*) (doggy_Opat, doggy_Opat))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Opat[POST_ACTION] = (int (*) (doggy_Opat, doggy_Opat))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Format[PRE_ACTION] = (int (*) (doggy_Format, doggy_Format))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Format[POST_ACTION] = (int (*) (doggy_Format, doggy_Format))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_dummy_type[PRE_ACTION] = (int (*) (doggy_dummy_type, doggy_dummy_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_dummy_type[POST_ACTION] = (int (*) (doggy_dummy_type, doggy_dummy_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (int (*) (doggy_Scope, doggy_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (int (*) (doggy_Scope, doggy_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpSetScope[PRE_ACTION] = (int (*) (doggy_OpSetScope, doggy_OpSetScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpSetScope[POST_ACTION] = (int (*) (doggy_OpSetScope, doggy_OpSetScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedOpScope[PRE_ACTION] = (int (*) (doggy_AppliedOpScope, doggy_AppliedOpScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedOpScope[POST_ACTION] = (int (*) (doggy_AppliedOpScope, doggy_AppliedOpScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ExprGuardScope[PRE_ACTION] = (int (*) (doggy_ExprGuardScope, doggy_ExprGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ExprGuardScope[POST_ACTION] = (int (*) (doggy_ExprGuardScope, doggy_ExprGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RhsGuardScope[PRE_ACTION] = (int (*) (doggy_RhsGuardScope, doggy_RhsGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RhsGuardScope[POST_ACTION] = (int (*) (doggy_RhsGuardScope, doggy_RhsGuardScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FuncRuleScope[PRE_ACTION] = (int (*) (doggy_FuncRuleScope, doggy_FuncRuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FuncRuleScope[POST_ACTION] = (int (*) (doggy_FuncRuleScope, doggy_FuncRuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RuleScope[PRE_ACTION] = (int (*) (doggy_RuleScope, doggy_RuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RuleScope[POST_ACTION] = (int (*) (doggy_RuleScope, doggy_RuleScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_machine_descriptionScope[PRE_ACTION] = (int (*) (doggy_machine_descriptionScope, doggy_machine_descriptionScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_machine_descriptionScope[POST_ACTION] = (int (*) (doggy_machine_descriptionScope, doggy_machine_descriptionScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Num[PRE_ACTION] = (int (*) (List_doggy_Num, List_doggy_Num))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Num[POST_ACTION] = (int (*) (List_doggy_Num, List_doggy_Num))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_TypePair[PRE_ACTION] = (int (*) (List_List_doggy_TypePair, List_List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_TypePair[POST_ACTION] = (int (*) (List_List_doggy_TypePair, List_List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_TypePair[PRE_ACTION] = (int (*) (List_doggy_TypePair, List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_TypePair[POST_ACTION] = (int (*) (List_doggy_TypePair, List_doggy_TypePair))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ActualOp[PRE_ACTION] = (int (*) (List_doggy_ActualOp, List_doggy_ActualOp))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ActualOp[POST_ACTION] = (int (*) (List_doggy_ActualOp, List_doggy_ActualOp))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_Type[PRE_ACTION] = (int (*) (List_List_doggy_Type, List_List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_Type[POST_ACTION] = (int (*) (List_List_doggy_Type, List_List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Operator[PRE_ACTION] = (int (*) (List_doggy_Operator, List_doggy_Operator))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Operator[POST_ACTION] = (int (*) (List_doggy_Operator, List_doggy_Operator))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Definition[PRE_ACTION] = (int (*) (List_doggy_Definition, List_doggy_Definition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Definition[POST_ACTION] = (int (*) (List_doggy_Definition, List_doggy_Definition))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expr[PRE_ACTION] = (int (*) (List_doggy_Expr, List_doggy_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expr[POST_ACTION] = (int (*) (List_doggy_Expr, List_doggy_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Guard[PRE_ACTION] = (int (*) (List_doggy_Guard, List_doggy_Guard))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Guard[POST_ACTION] = (int (*) (List_doggy_Guard, List_doggy_Guard))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Pattern[PRE_ACTION] = (int (*) (List_doggy_Pattern, List_doggy_Pattern))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Pattern[POST_ACTION] = (int (*) (List_doggy_Pattern, List_doggy_Pattern))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Argument[PRE_ACTION] = (int (*) (List_doggy_Argument, List_doggy_Argument))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Argument[POST_ACTION] = (int (*) (List_doggy_Argument, List_doggy_Argument))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FuncRule[PRE_ACTION] = (int (*) (List_doggy_FuncRule, List_doggy_FuncRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FuncRule[POST_ACTION] = (int (*) (List_doggy_FuncRule, List_doggy_FuncRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Attribute[PRE_ACTION] = (int (*) (List_doggy_Attribute, List_doggy_Attribute))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Attribute[POST_ACTION] = (int (*) (List_doggy_Attribute, List_doggy_Attribute))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Property[PRE_ACTION] = (int (*) (List_doggy_Property, List_doggy_Property))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Property[POST_ACTION] = (int (*) (List_doggy_Property, List_doggy_Property))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Applied_formal[PRE_ACTION] = (int (*) (List_doggy_Applied_formal, List_doggy_Applied_formal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Applied_formal[POST_ACTION] = (int (*) (List_doggy_Applied_formal, List_doggy_Applied_formal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Operation_def[PRE_ACTION] = (int (*) (List_doggy_Operation_def, List_doggy_Operation_def))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Operation_def[POST_ACTION] = (int (*) (List_doggy_Operation_def, List_doggy_Operation_def))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Type[PRE_ACTION] = (int (*) (List_doggy_Type, List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Type[POST_ACTION] = (int (*) (List_doggy_Type, List_doggy_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Rule[PRE_ACTION] = (int (*) (List_doggy_Rule, List_doggy_Rule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Rule[POST_ACTION] = (int (*) (List_doggy_Rule, List_doggy_Rule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Func[PRE_ACTION] = (int (*) (List_doggy_Func, List_doggy_Func))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Func[POST_ACTION] = (int (*) (List_doggy_Func, List_doggy_Func))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Section[PRE_ACTION] = (int (*) (List_doggy_Section, List_doggy_Section))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Section[POST_ACTION] = (int (*) (List_doggy_Section, List_doggy_Section))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FunctionDef[PRE_ACTION] = (int (*) (List_doggy_FunctionDef, List_doggy_FunctionDef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FunctionDef[POST_ACTION] = (int (*) (List_doggy_FunctionDef, List_doggy_FunctionDef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Typedef[PRE_ACTION] = (int (*) (List_doggy_Typedef, List_doggy_Typedef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Typedef[POST_ACTION] = (int (*) (List_doggy_Typedef, List_doggy_Typedef))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Operator[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Operator[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CandOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CandOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CorOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CorOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_XorOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_XorOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EqOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EqOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NeqOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NeqOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LEOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LEOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GEOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GEOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LTOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LTOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GTOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GTOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SLOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SLOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SROp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SROp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DivOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DivOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ModOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ModOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MulOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MulOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AddOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AddOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubOp[PRE_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubOp[POST_ACTION] = (int (*) (doggy_Operator, doggy_Operator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonOp[PRE_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonOp[POST_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NotOp[PRE_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NotOp[POST_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NegOp[PRE_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NegOp[POST_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AddrOp[PRE_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AddrOp[POST_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DerefOp[PRE_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DerefOp[POST_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlusOp[PRE_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlusOp[POST_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MinOp[PRE_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MinOp[POST_ACTION] = (int (*) (doggy_MonOp, doggy_MonOp))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Property[PRE_ACTION] = (int (*) (doggy_Property, doggy_Property))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Property[POST_ACTION] = (int (*) (doggy_Property, doggy_Property))x;
}

doggy_NameSpaces doggy_namespaces[] = { -1, -1 };

void Decorate_doggy (doggy_doggy r)
{
  if (doggy_namespaces[0]<0) Extend_namespaces (doggy_NUM_NAMESPACES, doggy_namespaces);
  doggy_root = r;
  if (NoDecorate) return;
  Traverse_doggy_doggy (r, &doggy_scope_actions, NULL);
  Traverse_void_doggy_doggy (r, &doggy_defining_actions);
  Traverse_void_doggy_doggy (r, &doggy_applied_actions);
  Traverse_void_doggy_doggy (r, &doggy_check_actions);
}
