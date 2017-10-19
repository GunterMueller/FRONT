#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "front/error.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/mem.h"
#include "front.h"

#ifndef front_SKIP_NODE
# define front_SKIP_NODE(n,t) FALSE
#endif

front front_root;

String front_Super_tag_names[] = {
  "SubType_kind",
  "NoType_kind",
};

String front_Scoping_names[] = {
  "NewScope",
  "OpenScope",
  "CloseScope",
};

String front_Alternative_tag_names[] = {
  "LabeledAlt_kind",
  "UnLabeledAlt_kind",
};

String front_Symbol_tag_names[] = {
  "LabeledSym_kind",
  "AltSymbol_kind",
  "SymbolSeq_kind",
  "CompareSym_kind",
  "AppliedSym_kind",
  "StringSymbol_kind",
  "CharSymbol_kind",
  "KeywordSymbol_kind",
  "OnceSymbol_kind",
  "OptSymbol_kind",
  "OptMoreSymbol_kind",
  "MoreSymbol_kind",
  "EmptySym_kind",
  "LayoutString_kind",
  "LayoutAction_kind",
  "IdSym_kind",
  "DefiningSym_kind",
};

String front_And_names[] = {
  "AndTranspose",
  "AndLeft",
  "AndRight",
  "AndCenter",
};

String front_Or_names[] = {
  "OrCenter",
  "OrLeft",
  "OrRight",
  "OrTranspose",
};

String front_Defining_id_tag_names[] = {
  "DefId_kind",
  "DefExpr_kind",
};

String front_Define_names[] = {
  "Defining",
  "Redefining",
  "Overloading",
};

String front_FieldInit_tag_names[] = {
  "WhenCreate_kind",
  "WhenScope_kind",
  "WhenDefining_kind",
  "WhenApplied_kind",
  "WhenChecks_kind",
};

String front_Expr_tag_names[] = {
  "BinExpr_kind",
  "MonExpr_kind",
  "IdentExpr_kind",
  "QualExpr_kind",
  "IntExpr_kind",
  "BoolExpr_kind",
  "StringExpr_kind",
  "NilExpr_kind",
  "CallExpr_kind",
};

String front_Defines_tag_names[] = {
  "PlainDef_kind",
  "MacroDef_kind",
};

String front_NameOrField_names[] = {
  "AppliedName",
  "AppliedField",
};

String front_Scope_tag_names[] = {
  "NonTerminalScope_kind",
};

front_front Create_front_front	(SrcInfo src_info, List_Ident uses, List_front_NameSpace namespaces, List_front_Import imports, List_front_NonTerminal rules)
{ front_front me = (front_front)fe_malloc(sizeof(*me));
  front_front_src_info(me) = src_info;
  front_front_uses(me) = uses;
  front_front_namespaces(me) = namespaces;
  front_front_imports(me) = imports;
  front_front_rules(me) = rules;
  return me;
}

front_Import Create_front_Import	(SrcInfo src_info, Ident grammar, List_front_ImportedNonTerminal nts)
{ front_Import me = (front_Import)fe_malloc(sizeof(*me));
  front_Import_src_info(me) = src_info;
  front_Import_grammar(me) = grammar;
  front_Import_nts(me) = nts;
  return me;
}

front_ImportedNonTerminal Create_front_ImportedNonTerminal	(SrcInfo src_info, Ident id, Ident type)
{ front_ImportedNonTerminal me = (front_ImportedNonTerminal)fe_malloc(sizeof(*me));
  front_ImportedNonTerminal_src_info(me) = src_info;
  front_ImportedNonTerminal_id(me) = id;
  front_ImportedNonTerminal_type(me) = type;
  front_ImportedNonTerminal__num(me) = - 1;
  front_ImportedNonTerminal_scope(me) = NULL;
  front_ImportedNonTerminal_old_scope(me) = NULL;
  front_ImportedNonTerminal_id_bind(me) = NULL;
  front_ImportedNonTerminal_grammar(me) = NULL;
  return me;
}

front_NonTerminal Create_front_NonTerminal	(SrcInfo src_info, Bool is_root, front_ScanInfo scan, Ident id, front_Super super, Bool meemo, Bool enumerate, Bool skip, front_Defines alias, front_Rhs rhs)
{ front_NonTerminal me = (front_NonTerminal)fe_malloc(sizeof(*me));
  front_NonTerminal_src_info(me) = src_info;
  front_NonTerminal_is_root(me) = is_root;
  front_NonTerminal_scan(me) = scan;
  front_NonTerminal_id(me) = id;
  front_NonTerminal_super(me) = super;
  front_NonTerminal_meemo(me) = meemo;
  front_NonTerminal_enumerate(me) = enumerate;
  front_NonTerminal_skip(me) = skip;
  front_NonTerminal_alias(me) = alias;
  front_NonTerminal_rhs(me) = rhs;
  front_NonTerminal__num(me) = - 1;
  front_NonTerminal_scope(me) = NULL;
  front_NonTerminal_old_scope(me) = NULL;
  front_NonTerminal_id_bind(me) = NULL;
  front_NonTerminal_alt(me) = Create_LabeledAlt (NonTerminal_src_info (me), NonTerminal_id (me), NonTerminal_meemo (me), NonTerminal_skip (me), Create_Ident ("="), NonTerminal_rhs (me));
  front_NonTerminal_reachable(me) = FALSE;
  return me;
}

front_NoType Create_front_NoType	(SrcInfo src_info, Ident id)
{ front_NoType me = (front_NoType)fe_malloc(sizeof(*me));
  front_Super_src_info(me) = src_info;
  front_Super_id(me) = id;
  front_Super__num(me) = - 1;
  front_Super_scope(me) = NULL;
  front_Super_old_scope(me) = NULL;
  front_Super_tag(me) = front_NoType_kind;
  front_Super_super_bind(me) = NULL;
  front_Super_super(me) = NULL;
  return me;
}

front_SubType Create_front_SubType	(SrcInfo src_info, Ident x, Ident id)
{ front_SubType me = (front_SubType)fe_malloc(sizeof(*me));
  front_Super_src_info(me) = src_info;
  front_SubType_x(me) = x;
  front_Super_id(me) = id;
  front_Super__num(me) = - 1;
  front_Super_scope(me) = NULL;
  front_Super_old_scope(me) = NULL;
  front_Super_tag(me) = front_SubType_kind;
  front_Super_super_bind(me) = NULL;
  front_Super_super(me) = NULL;
  return me;
}

front_Rhs Create_front_Rhs	(SrcInfo src_info, List_front_Scoping sc, front_Symbol syms1, Ident x, List_front_Alternative alts, List_front_Or ops, Ident y, front_Symbol syms2, List_front_Check checklist)
{ front_Rhs me = (front_Rhs)fe_malloc(sizeof(*me));
  front_Rhs_src_info(me) = src_info;
  front_Rhs_sc(me) = sc;
  front_Rhs_syms1(me) = syms1;
  front_Rhs_x(me) = x;
  front_Rhs_alts(me) = alts;
  front_Rhs_ops(me) = ops;
  front_Rhs_y(me) = y;
  front_Rhs_syms2(me) = syms2;
  front_Rhs_checklist(me) = checklist;
  front_Rhs_fields(me) = NULL;
  return me;
}

front_UnLabeledAlt Create_front_UnLabeledAlt	(SrcInfo src_info, front_Symbol syms)
{ front_UnLabeledAlt me = (front_UnLabeledAlt)fe_malloc(sizeof(*me));
  front_Alternative_src_info(me) = src_info;
  front_UnLabeledAlt_syms(me) = syms;
  front_Alternative__num(me) = - 1;
  front_Alternative_scope(me) = NULL;
  front_Alternative_old_scope(me) = NULL;
  front_Alternative_tag(me) = front_UnLabeledAlt_kind;
  front_Alternative_type(me) = NULL;
  front_Alternative_re(me) = NULL;
  return me;
}

front_LabeledAlt Create_front_LabeledAlt	(SrcInfo src_info, Ident id, Bool meemo, Bool skip, Ident def, front_Rhs rhs)
{ front_LabeledAlt me = (front_LabeledAlt)fe_malloc(sizeof(*me));
  front_Alternative_src_info(me) = src_info;
  front_LabeledAlt_id(me) = id;
  front_LabeledAlt_meemo(me) = meemo;
  front_LabeledAlt_skip(me) = skip;
  front_LabeledAlt_def(me) = def;
  front_LabeledAlt_rhs(me) = rhs;
  front_Alternative__num(me) = - 1;
  front_Alternative_scope(me) = NULL;
  front_Alternative_old_scope(me) = NULL;
  front_Alternative_tag(me) = front_LabeledAlt_kind;
  front_LabeledAlt_id_bind(me) = NULL;
  front_LabeledAlt_fields(me) = NULL;
  front_Alternative_type(me) = NULL;
  front_Alternative_re(me) = NULL;
  return me;
}

front_DefiningSym Create_front_DefiningSym	(SrcInfo src_info, Bool forward, front_Define def, front_Defining_id id, Ident ns_id, front_Expr sc)
{ front_DefiningSym me = (front_DefiningSym)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_DefiningSym_forward(me) = forward;
  front_DefiningSym_def(me) = def;
  front_DefiningSym_id(me) = id;
  front_DefiningSym_ns_id(me) = ns_id;
  front_DefiningSym_sc(me) = sc;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_DefiningSym_kind;
  front_DefiningSym_ns_bind(me) = NULL;
  front_DefiningSym_ns(me) = NULL;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_IdSym Create_front_IdSym	(SrcInfo src_info, Ident id, front_Type type)
{ front_IdSym me = (front_IdSym)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_IdSym_id(me) = id;
  front_IdSym_type(me) = type;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_IdSym_kind;
  front_IdSym_nt_bind(me) = NULL;
  front_IdSym_nt(me) = NULL;
  front_IdSym_import_bind(me) = NULL;
  front_IdSym_import(me) = NULL;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_LayoutAction Create_front_LayoutAction	(SrcInfo src_info, front_Expr layout)
{ front_LayoutAction me = (front_LayoutAction)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_LayoutAction_layout(me) = layout;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_LayoutAction_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_LayoutString Create_front_LayoutString	(SrcInfo src_info, String layout)
{ front_LayoutString me = (front_LayoutString)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_LayoutString_layout(me) = layout;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_LayoutString_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_EmptySym Create_front_EmptySym	(SrcInfo src_info)
{ front_EmptySym me = (front_EmptySym)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_EmptySym_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_MoreSymbol Create_front_MoreSymbol	(SrcInfo src_info, List_front_Symbol sym, List_front_Or ops, Ident more)
{ front_MoreSymbol me = (front_MoreSymbol)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_CompoundSym_sym(me) = sym;
  front_CompoundSym_ops(me) = ops;
  front_MoreSymbol_more(me) = more;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_MoreSymbol_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_OptMoreSymbol Create_front_OptMoreSymbol	(SrcInfo src_info, List_front_Symbol sym, List_front_Or ops)
{ front_OptMoreSymbol me = (front_OptMoreSymbol)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_CompoundSym_sym(me) = sym;
  front_CompoundSym_ops(me) = ops;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_OptMoreSymbol_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_OptSymbol Create_front_OptSymbol	(SrcInfo src_info, List_front_Symbol sym, List_front_Or ops, Bool in_line)
{ front_OptSymbol me = (front_OptSymbol)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_CompoundSym_sym(me) = sym;
  front_CompoundSym_ops(me) = ops;
  front_OptSymbol_in_line(me) = in_line;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_OptSymbol_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_OnceSymbol Create_front_OnceSymbol	(SrcInfo src_info, List_front_Symbol sym, List_front_Or ops)
{ front_OnceSymbol me = (front_OnceSymbol)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_CompoundSym_sym(me) = sym;
  front_CompoundSym_ops(me) = ops;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_OnceSymbol_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_KeywordSymbol Create_front_KeywordSymbol	(SrcInfo src_info, String keyword, front_Type type)
{ front_KeywordSymbol me = (front_KeywordSymbol)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_KeywordSymbol_keyword(me) = keyword;
  front_KeywordSymbol_type(me) = type;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_KeywordSymbol_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_CharSymbol Create_front_CharSymbol	(SrcInfo src_info, String chr, front_Type type)
{ front_CharSymbol me = (front_CharSymbol)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_CharSymbol_chr(me) = chr;
  front_CharSymbol_type(me) = type;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_CharSymbol_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_StringSymbol Create_front_StringSymbol	(SrcInfo src_info, String string, Ident n, front_Type type)
{ front_StringSymbol me = (front_StringSymbol)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_StringSymbol_string(me) = string;
  front_StringSymbol_n(me) = n;
  front_StringSymbol_type(me) = type;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_StringSymbol_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_AppliedSym Create_front_AppliedSym	(SrcInfo src_info, Ident nt_id, front_NameOrField field, Ident name, front_Expr sc, Bool warn)
{ front_AppliedSym me = (front_AppliedSym)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_AppliedSym_nt_id(me) = nt_id;
  front_AppliedSym_field(me) = field;
  front_AppliedSym_name(me) = name;
  front_AppliedSym_sc(me) = sc;
  front_AppliedSym_warn(me) = warn;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_AppliedSym_kind;
  front_AppliedSym_nt_bind(me) = NULL;
  front_AppliedSym_nt(me) = NULL;
  front_AppliedSym_alt_bind(me) = NULL;
  front_AppliedSym_alt(me) = NULL;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_CompareSym Create_front_CompareSym	(SrcInfo src_info, front_Symbol sym, Ident comp)
{ front_CompareSym me = (front_CompareSym)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_Symbol2_sym(me) = sym;
  front_Symbol2_comp(me) = comp;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_CompareSym_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_SymbolSeq Create_front_SymbolSeq	(SrcInfo src_info, List_front_Symbol symbols, List_front_Field my_fields, List_front_And ands)
{ front_SymbolSeq me = (front_SymbolSeq)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_SymbolSeq_symbols(me) = symbols;
  front_SymbolSeq_my_fields(me) = my_fields;
  front_SymbolSeq_ands(me) = ands;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_SymbolSeq_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_AltSymbol Create_front_AltSymbol	(SrcInfo src_info, front_Symbol syms1, front_Alternator alt, List_front_Symbol syms)
{ front_AltSymbol me = (front_AltSymbol)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_AltSymbol_syms1(me) = syms1;
  front_AltSymbol_alt(me) = alt;
  front_AltSymbol_syms(me) = syms;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_AltSymbol_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_LabeledSym Create_front_LabeledSym	(SrcInfo src_info, Ident id, front_Symbol sym)
{ front_LabeledSym me = (front_LabeledSym)fe_malloc(sizeof(*me));
  front_Symbol_src_info(me) = src_info;
  front_LabeledSym_id(me) = id;
  front_LabeledSym_sym(me) = sym;
  front_Symbol__num(me) = - 1;
  front_Symbol_scope(me) = NULL;
  front_Symbol_old_scope(me) = NULL;
  front_Symbol_tag(me) = front_LabeledSym_kind;
  front_Symbol_fields(me) = NULL;
  front_Symbol_empty(me) = FALSE;
  return me;
}

front_DefExpr Create_front_DefExpr	(SrcInfo src_info, front_Expr e)
{ front_DefExpr me = (front_DefExpr)fe_malloc(sizeof(*me));
  front_Defining_id_src_info(me) = src_info;
  front_DefExpr_e(me) = e;
  front_Defining_id_tag(me) = front_DefExpr_kind;
  return me;
}

front_DefId Create_front_DefId	(SrcInfo src_info, front_Symbol id)
{ front_DefId me = (front_DefId)fe_malloc(sizeof(*me));
  front_Defining_id_src_info(me) = src_info;
  front_DefId_id(me) = id;
  front_Defining_id_tag(me) = front_DefId_kind;
  return me;
}

front_Field Create_front_Field	(SrcInfo src_info, Ident id, front_Type type, Ident assign, List_front_FieldInit when, Bool traverse, Bool clear, Bool dont_clear)
{ front_Field me = (front_Field)fe_malloc(sizeof(*me));
  front_Field_src_info(me) = src_info;
  front_Field_id(me) = id;
  front_Field_type(me) = type;
  front_Field_assign(me) = assign;
  front_Field_when(me) = when;
  front_Field_traverse(me) = traverse;
  front_Field_clear(me) = clear;
  front_Field_dont_clear(me) = dont_clear;
  return me;
}

front_WhenChecks Create_front_WhenChecks	(SrcInfo src_info, front_Expr expr)
{ front_WhenChecks me = (front_WhenChecks)fe_malloc(sizeof(*me));
  front_FieldInit_src_info(me) = src_info;
  front_FieldInit_expr(me) = expr;
  front_FieldInit_tag(me) = front_WhenChecks_kind;
  return me;
}

front_WhenApplied Create_front_WhenApplied	(SrcInfo src_info, front_Expr expr)
{ front_WhenApplied me = (front_WhenApplied)fe_malloc(sizeof(*me));
  front_FieldInit_src_info(me) = src_info;
  front_FieldInit_expr(me) = expr;
  front_FieldInit_tag(me) = front_WhenApplied_kind;
  return me;
}

front_WhenDefining Create_front_WhenDefining	(SrcInfo src_info, front_Expr expr)
{ front_WhenDefining me = (front_WhenDefining)fe_malloc(sizeof(*me));
  front_FieldInit_src_info(me) = src_info;
  front_FieldInit_expr(me) = expr;
  front_FieldInit_tag(me) = front_WhenDefining_kind;
  return me;
}

front_WhenScope Create_front_WhenScope	(SrcInfo src_info, front_Expr expr)
{ front_WhenScope me = (front_WhenScope)fe_malloc(sizeof(*me));
  front_FieldInit_src_info(me) = src_info;
  front_FieldInit_expr(me) = expr;
  front_FieldInit_tag(me) = front_WhenScope_kind;
  return me;
}

front_WhenCreate Create_front_WhenCreate	(SrcInfo src_info, Bool c, front_Expr expr)
{ front_WhenCreate me = (front_WhenCreate)fe_malloc(sizeof(*me));
  front_FieldInit_src_info(me) = src_info;
  front_WhenCreate_c(me) = c;
  front_FieldInit_expr(me) = expr;
  front_FieldInit_tag(me) = front_WhenCreate_kind;
  return me;
}

front_Type Create_front_Type	(SrcInfo src_info, Ident id, List_front_Type args)
{ front_Type me = (front_Type)fe_malloc(sizeof(*me));
  front_Type_src_info(me) = src_info;
  front_Type_id(me) = id;
  front_Type_args(me) = args;
  front_Type__num(me) = - 1;
  front_Type_scope(me) = NULL;
  front_Type_old_scope(me) = NULL;
  front_Type_nt_bind(me) = NULL;
  front_Type_nt(me) = NULL;
  front_Type_import_bind(me) = NULL;
  front_Type_import(me) = NULL;
  front_Type_alt_bind(me) = NULL;
  front_Type_alt(me) = NULL;
  return me;
}

front_CallExpr Create_front_CallExpr	(SrcInfo src_info, front_Expr func, List_front_Expr args)
{ front_CallExpr me = (front_CallExpr)fe_malloc(sizeof(*me));
  front_Expr_src_info(me) = src_info;
  front_CallExpr_func(me) = func;
  front_CallExpr_args(me) = args;
  front_Expr_tag(me) = front_CallExpr_kind;
  return me;
}

front_NilExpr Create_front_NilExpr	(SrcInfo src_info)
{ front_NilExpr me = (front_NilExpr)fe_malloc(sizeof(*me));
  front_Expr_src_info(me) = src_info;
  front_Expr_tag(me) = front_NilExpr_kind;
  return me;
}

front_StringExpr Create_front_StringExpr	(SrcInfo src_info, String string)
{ front_StringExpr me = (front_StringExpr)fe_malloc(sizeof(*me));
  front_Expr_src_info(me) = src_info;
  front_StringExpr_string(me) = string;
  front_Expr_tag(me) = front_StringExpr_kind;
  return me;
}

front_BoolExpr Create_front_BoolExpr	(SrcInfo src_info, Bool b)
{ front_BoolExpr me = (front_BoolExpr)fe_malloc(sizeof(*me));
  front_Expr_src_info(me) = src_info;
  front_BoolExpr_b(me) = b;
  front_Expr_tag(me) = front_BoolExpr_kind;
  return me;
}

front_IntExpr Create_front_IntExpr	(SrcInfo src_info, Int i)
{ front_IntExpr me = (front_IntExpr)fe_malloc(sizeof(*me));
  front_Expr_src_info(me) = src_info;
  front_IntExpr_i(me) = i;
  front_Expr_tag(me) = front_IntExpr_kind;
  return me;
}

front_QualExpr Create_front_QualExpr	(SrcInfo src_info, front_Expr prefix, Ident id)
{ front_QualExpr me = (front_QualExpr)fe_malloc(sizeof(*me));
  front_Expr_src_info(me) = src_info;
  front_QualExpr_prefix(me) = prefix;
  front_QualExpr_id(me) = id;
  front_Expr_tag(me) = front_QualExpr_kind;
  return me;
}

front_IdentExpr Create_front_IdentExpr	(SrcInfo src_info, Ident id)
{ front_IdentExpr me = (front_IdentExpr)fe_malloc(sizeof(*me));
  front_Expr_src_info(me) = src_info;
  front_IdentExpr_id(me) = id;
  front_Expr_tag(me) = front_IdentExpr_kind;
  return me;
}

front_MonExpr Create_front_MonExpr	(SrcInfo src_info, List_Ident ops, front_Expr arg)
{ front_MonExpr me = (front_MonExpr)fe_malloc(sizeof(*me));
  front_Expr_src_info(me) = src_info;
  front_MonExpr1_ops(me) = ops;
  front_MonExpr1_arg(me) = arg;
  front_Expr_tag(me) = front_MonExpr_kind;
  return me;
}

front_BinExpr Create_front_BinExpr	(SrcInfo src_info, List_front_Expr args, List_Ident ops)
{ front_BinExpr me = (front_BinExpr)fe_malloc(sizeof(*me));
  front_Expr_src_info(me) = src_info;
  front_BinExpr_args(me) = args;
  front_BinExpr_ops(me) = ops;
  front_Expr_tag(me) = front_BinExpr_kind;
  return me;
}

front_Check Create_front_Check	(SrcInfo src_info, front_Expr cond, Bool warn, List_front_Expr message)
{ front_Check me = (front_Check)fe_malloc(sizeof(*me));
  front_Check_src_info(me) = src_info;
  front_Check_cond(me) = cond;
  front_Check_warn(me) = warn;
  front_Check_message(me) = message;
  return me;
}

front_ScanInfo Create_front_ScanInfo	(SrcInfo src_info, front_Type type, Bool comment)
{ front_ScanInfo me = (front_ScanInfo)fe_malloc(sizeof(*me));
  front_ScanInfo_src_info(me) = src_info;
  front_ScanInfo_type(me) = type;
  front_ScanInfo_comment(me) = comment;
  return me;
}

front_MacroDef Create_front_MacroDef	(SrcInfo src_info, Ident id)
{ front_MacroDef me = (front_MacroDef)fe_malloc(sizeof(*me));
  front_Defines_src_info(me) = src_info;
  front_Defines_id(me) = id;
  front_Defines_tag(me) = front_MacroDef_kind;
  return me;
}

front_PlainDef Create_front_PlainDef	(SrcInfo src_info, Ident id)
{ front_PlainDef me = (front_PlainDef)fe_malloc(sizeof(*me));
  front_Defines_src_info(me) = src_info;
  front_Defines_id(me) = id;
  front_Defines_tag(me) = front_PlainDef_kind;
  return me;
}

front_NameSpace Create_front_NameSpace	(SrcInfo src_info, Ident id)
{ front_NameSpace me = (front_NameSpace)fe_malloc(sizeof(*me));
  front_NameSpace_src_info(me) = src_info;
  front_NameSpace_id(me) = id;
  front_NameSpace__num(me) = - 1;
  front_NameSpace_scope(me) = NULL;
  front_NameSpace_old_scope(me) = NULL;
  front_NameSpace_id_bind(me) = NULL;
  return me;
}

front_dummy Create_front_dummy	(SrcInfo src_info)
{ front_dummy me = (front_dummy)fe_malloc(sizeof(*me));
  front_dummy_src_info(me) = src_info;
  front_dummy_x(me) = NULL;
  return me;
}

front_NonTerminalScope Create_front_NonTerminalScope	(front_Scope next, front_NonTerminal data)
{ front_NonTerminalScope me = (front_NonTerminalScope)fe_malloc(sizeof(*me));
  front_Scope_next(me) = next;
  front_NonTerminalScope_data(me) = data;
  front_Scope__self(me) = 0;
  front_Scope__end(me) = 0;
  front_Scope_tag(me) = front_NonTerminalScope_kind;
  return me;
}

Pointer Traverse_front_front (front_front me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(front, me)) return val;
  if (action->action_front[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_front[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_front)
  { 
  if (!action->skip_children_front) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_NameSpace (front_front_namespaces(me), action, val);
    else Traverse_List_front_NameSpace (front_front_namespaces(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Import (front_front_imports(me), action, val);
    else Traverse_List_front_Import (front_front_imports(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_NonTerminal (front_front_rules(me), action, val);
    else Traverse_List_front_NonTerminal (front_front_rules(me), action, val);
  }
  }
  if (action->action_front[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_front[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Import (front_Import me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Import, me)) return val;
  if (action->action_Import[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Import[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Import)
  { 
  if (!action->skip_children_Import) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_ImportedNonTerminal (front_Import_nts(me), action, val);
    else Traverse_List_front_ImportedNonTerminal (front_Import_nts(me), action, val);
  }
  }
  if (action->action_Import[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Import[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_ImportedNonTerminal (front_ImportedNonTerminal me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(ImportedNonTerminal, me)) return val;
  if (action->action_ImportedNonTerminal[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ImportedNonTerminal[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_ImportedNonTerminal)
  { 
  }
  if (action->action_ImportedNonTerminal[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ImportedNonTerminal[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_NonTerminal (front_NonTerminal me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(NonTerminal, me)) return val;
  if (action->action_NonTerminal[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_NonTerminal[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_NonTerminal)
  { 
  if (!action->skip_children_NonTerminal) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_ScanInfo (front_NonTerminal_scan(me), action, val);
    else Traverse_front_ScanInfo (front_NonTerminal_scan(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_front_Super (front_NonTerminal_super(me), action, val);
    else Traverse_front_Super (front_NonTerminal_super(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_front_Defines (front_NonTerminal_alias(me), action, val);
    else Traverse_front_Defines (front_NonTerminal_alias(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_front_Rhs (front_NonTerminal_rhs(me), action, val);
    else Traverse_front_Rhs (front_NonTerminal_rhs(me), action, val);
  }
  }
  if (action->action_NonTerminal[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_NonTerminal[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Super (front_Super me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Super, me)) return val;
  if (action->action_Super[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Super[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Super)
  { switch (front_Super_tag(me)) {
      case front_SubType_kind:
        if (action->action_SubType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SubType[PRE_ACTION](me, val);
        }
        if (action->action_SubType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SubType[POST_ACTION](me, val);
        }
        break;
      case front_NoType_kind:
        if (action->action_NoType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NoType[PRE_ACTION](me, val);
        }
        if (action->action_NoType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NoType[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Super[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Super[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Rhs (front_Rhs me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Rhs, me)) return val;
  if (action->action_Rhs[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Rhs[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Rhs)
  { 
  if (!action->skip_children_Rhs) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Scoping (front_Rhs_sc(me), action, val);
    else Traverse_List_front_Scoping (front_Rhs_sc(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_front_Symbol (front_Rhs_syms1(me), action, val);
    else Traverse_front_Symbol (front_Rhs_syms1(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Alternative (front_Rhs_alts(me), action, val);
    else Traverse_List_front_Alternative (front_Rhs_alts(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Or (front_Rhs_ops(me), action, val);
    else Traverse_List_front_Or (front_Rhs_ops(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_front_Symbol (front_Rhs_syms2(me), action, val);
    else Traverse_front_Symbol (front_Rhs_syms2(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Check (front_Rhs_checklist(me), action, val);
    else Traverse_List_front_Check (front_Rhs_checklist(me), action, val);
  }
  }
  if (action->action_Rhs[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Rhs[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Alternative (front_Alternative me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Alternative, me)) return val;
  if (action->action_Alternative[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Alternative[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Alternative)
  { switch (front_Alternative_tag(me)) {
      case front_LabeledAlt_kind:
        if (action->action_LabeledAlt[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LabeledAlt[PRE_ACTION](me, val);
        }
        if (!action->skip_children_LabeledAlt) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Rhs (front_LabeledAlt_rhs(me), action, val);
          else Traverse_front_Rhs (front_LabeledAlt_rhs(me), action, val);
        }
        if (action->action_LabeledAlt[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LabeledAlt[POST_ACTION](me, val);
        }
        break;
      case front_UnLabeledAlt_kind:
        if (action->action_UnLabeledAlt[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_UnLabeledAlt[PRE_ACTION](me, val);
        }
        if (!action->skip_children_UnLabeledAlt) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Symbol (front_UnLabeledAlt_syms(me), action, val);
          else Traverse_front_Symbol (front_UnLabeledAlt_syms(me), action, val);
        }
        if (action->action_UnLabeledAlt[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_UnLabeledAlt[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Alternative[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Alternative[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Symbol (front_Symbol me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Symbol, me)) return val;
  if (action->action_Symbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Symbol[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Symbol)
  { switch (front_Symbol_tag(me)) {
      case front_LabeledSym_kind:
        if (action->action_LabeledSym[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LabeledSym[PRE_ACTION](me, val);
        }
        if (!action->skip_children_LabeledSym) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Symbol (front_LabeledSym_sym(me), action, val);
          else Traverse_front_Symbol (front_LabeledSym_sym(me), action, val);
        }
        if (action->action_LabeledSym[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LabeledSym[POST_ACTION](me, val);
        }
        break;
      case front_AltSymbol_kind:
        if (action->action_AltSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AltSymbol[PRE_ACTION](me, val);
        }
        if (!action->skip_children_AltSymbol) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Symbol (front_AltSymbol_syms1(me), action, val);
          else Traverse_front_Symbol (front_AltSymbol_syms1(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_front_Alternator (front_AltSymbol_alt(me), action, val);
          else Traverse_front_Alternator (front_AltSymbol_alt(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Symbol (front_AltSymbol_syms(me), action, val);
          else Traverse_List_front_Symbol (front_AltSymbol_syms(me), action, val);
        }
        if (action->action_AltSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AltSymbol[POST_ACTION](me, val);
        }
        break;
      case front_SymbolSeq_kind:
        if (action->action_SymbolSeq[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SymbolSeq[PRE_ACTION](me, val);
        }
        if (!action->skip_children_SymbolSeq) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Symbol (front_SymbolSeq_symbols(me), action, val);
          else Traverse_List_front_Symbol (front_SymbolSeq_symbols(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Field (front_SymbolSeq_my_fields(me), action, val);
          else Traverse_List_front_Field (front_SymbolSeq_my_fields(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_And (front_SymbolSeq_ands(me), action, val);
          else Traverse_List_front_And (front_SymbolSeq_ands(me), action, val);
        }
        if (action->action_SymbolSeq[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SymbolSeq[POST_ACTION](me, val);
        }
        break;
      case front_CompareSym_kind:
        if (action->action_Symbol2[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Symbol2[PRE_ACTION](me, val);
        }
        if (action->action_CompareSym[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CompareSym[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Symbol2) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Symbol (front_Symbol2_sym(me), action, val);
          else Traverse_front_Symbol (front_Symbol2_sym(me), action, val);
        }
        if (action->action_CompareSym[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CompareSym[POST_ACTION](me, val);
        }
        if (action->action_Symbol2[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Symbol2[POST_ACTION](me, val);
        }
        break;
      case front_AppliedSym_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_AppliedSym[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AppliedSym[PRE_ACTION](me, val);
        }
        if (!action->skip_children_AppliedSym) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_NameOrField (front_AppliedSym_field(me), action, val);
          else Traverse_front_NameOrField (front_AppliedSym_field(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_AppliedSym_sc(me), action, val);
          else Traverse_front_Expr (front_AppliedSym_sc(me), action, val);
        }
        if (action->action_AppliedSym[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AppliedSym[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_StringSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_StringSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_StringSymbol[PRE_ACTION](me, val);
        }
        if (!action->skip_children_StringSymbol) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Type (front_StringSymbol_type(me), action, val);
          else Traverse_front_Type (front_StringSymbol_type(me), action, val);
        }
        if (action->action_StringSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_StringSymbol[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_CharSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_CharSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CharSymbol[PRE_ACTION](me, val);
        }
        if (!action->skip_children_CharSymbol) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Type (front_CharSymbol_type(me), action, val);
          else Traverse_front_Type (front_CharSymbol_type(me), action, val);
        }
        if (action->action_CharSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CharSymbol[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_KeywordSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_KeywordSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_KeywordSymbol[PRE_ACTION](me, val);
        }
        if (!action->skip_children_KeywordSymbol) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Type (front_KeywordSymbol_type(me), action, val);
          else Traverse_front_Type (front_KeywordSymbol_type(me), action, val);
        }
        if (action->action_KeywordSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_KeywordSymbol[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_OnceSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CompoundSym[PRE_ACTION](me, val);
        }
        if (action->action_OnceSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OnceSymbol[PRE_ACTION](me, val);
        }
        if (!action->skip_children_CompoundSym) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Symbol (front_CompoundSym_sym(me), action, val);
          else Traverse_List_front_Symbol (front_CompoundSym_sym(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Or (front_CompoundSym_ops(me), action, val);
          else Traverse_List_front_Or (front_CompoundSym_ops(me), action, val);
        }
        if (action->action_OnceSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OnceSymbol[POST_ACTION](me, val);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CompoundSym[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_OptSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CompoundSym[PRE_ACTION](me, val);
        }
        if (action->action_OptSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OptSymbol[PRE_ACTION](me, val);
        }
        if (!action->skip_children_CompoundSym) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Symbol (front_CompoundSym_sym(me), action, val);
          else Traverse_List_front_Symbol (front_CompoundSym_sym(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Or (front_CompoundSym_ops(me), action, val);
          else Traverse_List_front_Or (front_CompoundSym_ops(me), action, val);
        }
        if (action->action_OptSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OptSymbol[POST_ACTION](me, val);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CompoundSym[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_OptMoreSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CompoundSym[PRE_ACTION](me, val);
        }
        if (action->action_OptMoreSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OptMoreSymbol[PRE_ACTION](me, val);
        }
        if (!action->skip_children_CompoundSym) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Symbol (front_CompoundSym_sym(me), action, val);
          else Traverse_List_front_Symbol (front_CompoundSym_sym(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Or (front_CompoundSym_ops(me), action, val);
          else Traverse_List_front_Or (front_CompoundSym_ops(me), action, val);
        }
        if (action->action_OptMoreSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OptMoreSymbol[POST_ACTION](me, val);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CompoundSym[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_MoreSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CompoundSym[PRE_ACTION](me, val);
        }
        if (action->action_MoreSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MoreSymbol[PRE_ACTION](me, val);
        }
        if (!action->skip_children_CompoundSym) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Symbol (front_CompoundSym_sym(me), action, val);
          else Traverse_List_front_Symbol (front_CompoundSym_sym(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Or (front_CompoundSym_ops(me), action, val);
          else Traverse_List_front_Or (front_CompoundSym_ops(me), action, val);
        }
        if (action->action_MoreSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MoreSymbol[POST_ACTION](me, val);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CompoundSym[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_EmptySym_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_EmptySym[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_EmptySym[PRE_ACTION](me, val);
        }
        if (action->action_EmptySym[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_EmptySym[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_LayoutString_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_LayoutString[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LayoutString[PRE_ACTION](me, val);
        }
        if (action->action_LayoutString[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LayoutString[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_LayoutAction_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[PRE_ACTION](me, val);
        }
        if (action->action_LayoutAction[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LayoutAction[PRE_ACTION](me, val);
        }
        if (!action->skip_children_LayoutAction) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_LayoutAction_layout(me), action, val);
          else Traverse_front_Expr (front_LayoutAction_layout(me), action, val);
        }
        if (action->action_LayoutAction[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_LayoutAction[POST_ACTION](me, val);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleSymbol[POST_ACTION](me, val);
        }
        break;
      case front_IdSym_kind:
        if (action->action_IdSym[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdSym[PRE_ACTION](me, val);
        }
        if (!action->skip_children_IdSym) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Type (front_IdSym_type(me), action, val);
          else Traverse_front_Type (front_IdSym_type(me), action, val);
        }
        if (action->action_IdSym[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdSym[POST_ACTION](me, val);
        }
        break;
      case front_DefiningSym_kind:
        if (action->action_DefiningSym[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DefiningSym[PRE_ACTION](me, val);
        }
        if (!action->skip_children_DefiningSym) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Define (front_DefiningSym_def(me), action, val);
          else Traverse_front_Define (front_DefiningSym_def(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_front_Defining_id (front_DefiningSym_id(me), action, val);
          else Traverse_front_Defining_id (front_DefiningSym_id(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_DefiningSym_sc(me), action, val);
          else Traverse_front_Expr (front_DefiningSym_sc(me), action, val);
        }
        if (action->action_DefiningSym[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DefiningSym[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Symbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Symbol[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Defining_id (front_Defining_id me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Defining_id, me)) return val;
  if (action->action_Defining_id[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Defining_id[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Defining_id)
  { switch (front_Defining_id_tag(me)) {
      case front_DefId_kind:
        if (action->action_DefId[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DefId[PRE_ACTION](me, val);
        }
        if (!action->skip_children_DefId) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Symbol (front_DefId_id(me), action, val);
          else Traverse_front_Symbol (front_DefId_id(me), action, val);
        }
        if (action->action_DefId[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DefId[POST_ACTION](me, val);
        }
        break;
      case front_DefExpr_kind:
        if (action->action_DefExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DefExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_DefExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_DefExpr_e(me), action, val);
          else Traverse_front_Expr (front_DefExpr_e(me), action, val);
        }
        if (action->action_DefExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DefExpr[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Defining_id[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Defining_id[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Field (front_Field me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Field, me)) return val;
  if (action->action_Field[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Field[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Field)
  { 
  if (!action->skip_children_Field) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Type (front_Field_type(me), action, val);
    else Traverse_front_Type (front_Field_type(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_FieldInit (front_Field_when(me), action, val);
    else Traverse_List_front_FieldInit (front_Field_when(me), action, val);
  }
  }
  if (action->action_Field[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Field[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_FieldInit (front_FieldInit me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(FieldInit, me)) return val;
  if (action->action_FieldInit[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_FieldInit[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_FieldInit)
  { switch (front_FieldInit_tag(me)) {
      case front_WhenCreate_kind:
        if (action->action_WhenCreate[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WhenCreate[PRE_ACTION](me, val);
        }
        if (!action->skip_children_FieldInit) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_FieldInit_expr(me), action, val);
          else Traverse_front_Expr (front_FieldInit_expr(me), action, val);
        }
        if (action->action_WhenCreate[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WhenCreate[POST_ACTION](me, val);
        }
        break;
      case front_WhenScope_kind:
        if (action->action_WhenScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WhenScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_FieldInit) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_FieldInit_expr(me), action, val);
          else Traverse_front_Expr (front_FieldInit_expr(me), action, val);
        }
        if (action->action_WhenScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WhenScope[POST_ACTION](me, val);
        }
        break;
      case front_WhenDefining_kind:
        if (action->action_WhenDefining[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WhenDefining[PRE_ACTION](me, val);
        }
        if (!action->skip_children_FieldInit) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_FieldInit_expr(me), action, val);
          else Traverse_front_Expr (front_FieldInit_expr(me), action, val);
        }
        if (action->action_WhenDefining[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WhenDefining[POST_ACTION](me, val);
        }
        break;
      case front_WhenApplied_kind:
        if (action->action_WhenApplied[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WhenApplied[PRE_ACTION](me, val);
        }
        if (!action->skip_children_FieldInit) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_FieldInit_expr(me), action, val);
          else Traverse_front_Expr (front_FieldInit_expr(me), action, val);
        }
        if (action->action_WhenApplied[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WhenApplied[POST_ACTION](me, val);
        }
        break;
      case front_WhenChecks_kind:
        if (action->action_WhenChecks[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WhenChecks[PRE_ACTION](me, val);
        }
        if (!action->skip_children_FieldInit) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_FieldInit_expr(me), action, val);
          else Traverse_front_Expr (front_FieldInit_expr(me), action, val);
        }
        if (action->action_WhenChecks[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WhenChecks[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_FieldInit[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_FieldInit[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Type (front_Type me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Type, me)) return val;
  if (action->action_Type[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Type[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Type)
  { 
  if (!action->skip_children_Type) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Type (front_Type_args(me), action, val);
    else Traverse_List_front_Type (front_Type_args(me), action, val);
  }
  }
  if (action->action_Type[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Type[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Expr (front_Expr me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Expr, me)) return val;
  if (action->action_Expr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Expr[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Expr)
  { switch (front_Expr_tag(me)) {
      case front_BinExpr_kind:
        if (action->action_BinExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BinExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_BinExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Expr (front_BinExpr_args(me), action, val);
          else Traverse_List_front_Expr (front_BinExpr_args(me), action, val);
        }
        if (action->action_BinExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BinExpr[POST_ACTION](me, val);
        }
        break;
      case front_MonExpr_kind:
        if (action->action_MonExpr1[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MonExpr1[PRE_ACTION](me, val);
        }
        if (action->action_MonExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MonExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_MonExpr1) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_MonExpr1_arg(me), action, val);
          else Traverse_front_Expr (front_MonExpr1_arg(me), action, val);
        }
        if (action->action_MonExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MonExpr[POST_ACTION](me, val);
        }
        if (action->action_MonExpr1[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MonExpr1[POST_ACTION](me, val);
        }
        break;
      case front_IdentExpr_kind:
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
      case front_QualExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_QualExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_QualExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_QualExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_QualExpr_prefix(me), action, val);
          else Traverse_front_Expr (front_QualExpr_prefix(me), action, val);
        }
        if (action->action_QualExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_QualExpr[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
      case front_IntExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_IntExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IntExpr[PRE_ACTION](me, val);
        }
        if (action->action_IntExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IntExpr[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
      case front_BoolExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_BoolExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BoolExpr[PRE_ACTION](me, val);
        }
        if (action->action_BoolExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BoolExpr[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
      case front_StringExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_StringExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_StringExpr[PRE_ACTION](me, val);
        }
        if (action->action_StringExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_StringExpr[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
      case front_NilExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_NilExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NilExpr[PRE_ACTION](me, val);
        }
        if (action->action_NilExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NilExpr[POST_ACTION](me, val);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[POST_ACTION](me, val);
        }
        break;
      case front_CallExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SimpleExpr[PRE_ACTION](me, val);
        }
        if (action->action_CallExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CallExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_CallExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_CallExpr_func(me), action, val);
          else Traverse_front_Expr (front_CallExpr_func(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_front_Expr (front_CallExpr_args(me), action, val);
          else Traverse_List_front_Expr (front_CallExpr_args(me), action, val);
        }
        if (action->action_CallExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CallExpr[POST_ACTION](me, val);
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

Pointer Traverse_front_Check (front_Check me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Check, me)) return val;
  if (action->action_Check[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Check[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Check)
  { 
  if (!action->skip_children_Check) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (front_Check_cond(me), action, val);
    else Traverse_front_Expr (front_Check_cond(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Expr (front_Check_message(me), action, val);
    else Traverse_List_front_Expr (front_Check_message(me), action, val);
  }
  }
  if (action->action_Check[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Check[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_ScanInfo (front_ScanInfo me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(ScanInfo, me)) return val;
  if (action->action_ScanInfo[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ScanInfo[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_ScanInfo)
  { 
  if (!action->skip_children_ScanInfo) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Type (front_ScanInfo_type(me), action, val);
    else Traverse_front_Type (front_ScanInfo_type(me), action, val);
  }
  }
  if (action->action_ScanInfo[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ScanInfo[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Defines (front_Defines me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Defines, me)) return val;
  if (action->action_Defines[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Defines[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Defines)
  { switch (front_Defines_tag(me)) {
      case front_PlainDef_kind:
        if (action->action_PlainDef[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PlainDef[PRE_ACTION](me, val);
        }
        if (action->action_PlainDef[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PlainDef[POST_ACTION](me, val);
        }
        break;
      case front_MacroDef_kind:
        if (action->action_MacroDef[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MacroDef[PRE_ACTION](me, val);
        }
        if (action->action_MacroDef[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_MacroDef[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Defines[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Defines[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_NameSpace (front_NameSpace me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(NameSpace, me)) return val;
  if (action->action_NameSpace[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_NameSpace[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_NameSpace)
  { 
  }
  if (action->action_NameSpace[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_NameSpace[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_dummy (front_dummy me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(dummy, me)) return val;
  if (action->action_dummy[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_dummy[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_dummy)
  { 
  }
  if (action->action_dummy[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_dummy[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Scope (front_Scope me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Scope, me)) return val;
  if (action->action_Scope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Scope)
  { switch (front_Scope_tag(me)) {
      case front_NonTerminalScope_kind:
        if (action->action_NonTerminalScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NonTerminalScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Scope) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_Scope (front_Scope_next(me), action, val);
          else Traverse_front_Scope (front_Scope_next(me), action, val);
        }
        if (!action->skip_children_NonTerminalScope) {
          if (action->traversal != Traverse_Down)  val = Traverse_front_NonTerminal (front_NonTerminalScope_data(me), action, val);
          else Traverse_front_NonTerminal (front_NonTerminalScope_data(me), action, val);
        }
        if (action->action_NonTerminalScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NonTerminalScope[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Scope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_List_front_Symbol (List_List_front_Symbol me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_List_Symbol, me)) return val;
  if (action->action_List_List_Symbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_List_Symbol[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_List_Symbol)
  { 
  if (!action->skip_children_List_List_Symbol) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Symbol (List_List_front_Symbol_data(me), action, val);
    else Traverse_List_front_Symbol (List_List_front_Symbol_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_List_front_Symbol (List_List_front_Symbol_next(me), action, val);
    else Traverse_List_List_front_Symbol (List_List_front_Symbol_next(me), action, val);
  }
  }
  if (action->action_List_List_Symbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_List_Symbol[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_Expr (List_front_Expr me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_Expr, me)) return val;
  if (action->action_List_Expr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Expr[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Expr)
  { 
  if (!action->skip_children_List_Expr) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Expr (List_front_Expr_data(me), action, val);
    else Traverse_front_Expr (List_front_Expr_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Expr (List_front_Expr_next(me), action, val);
    else Traverse_List_front_Expr (List_front_Expr_next(me), action, val);
  }
  }
  if (action->action_List_Expr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Expr[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_Type (List_front_Type me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_Type, me)) return val;
  if (action->action_List_Type[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Type[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Type)
  { 
  if (!action->skip_children_List_Type) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Type (List_front_Type_data(me), action, val);
    else Traverse_front_Type (List_front_Type_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Type (List_front_Type_next(me), action, val);
    else Traverse_List_front_Type (List_front_Type_next(me), action, val);
  }
  }
  if (action->action_List_Type[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Type[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_FieldInit (List_front_FieldInit me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_FieldInit, me)) return val;
  if (action->action_List_FieldInit[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_FieldInit[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_FieldInit)
  { 
  if (!action->skip_children_List_FieldInit) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_FieldInit (List_front_FieldInit_data(me), action, val);
    else Traverse_front_FieldInit (List_front_FieldInit_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_FieldInit (List_front_FieldInit_next(me), action, val);
    else Traverse_List_front_FieldInit (List_front_FieldInit_next(me), action, val);
  }
  }
  if (action->action_List_FieldInit[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_FieldInit[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_And (List_front_And me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_And, me)) return val;
  if (action->action_List_And[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_And[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_And)
  { 
  if (!action->skip_children_List_And) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_And (List_front_And_data(me), action, val);
    else Traverse_front_And (List_front_And_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_And (List_front_And_next(me), action, val);
    else Traverse_List_front_And (List_front_And_next(me), action, val);
  }
  }
  if (action->action_List_And[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_And[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_Field (List_front_Field me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_Field, me)) return val;
  if (action->action_List_Field[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Field[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Field)
  { 
  if (!action->skip_children_List_Field) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Field (List_front_Field_data(me), action, val);
    else Traverse_front_Field (List_front_Field_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Field (List_front_Field_next(me), action, val);
    else Traverse_List_front_Field (List_front_Field_next(me), action, val);
  }
  }
  if (action->action_List_Field[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Field[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_Symbol (List_front_Symbol me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_Symbol, me)) return val;
  if (action->action_List_Symbol[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Symbol[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Symbol)
  { 
  if (!action->skip_children_List_Symbol) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Symbol (List_front_Symbol_data(me), action, val);
    else Traverse_front_Symbol (List_front_Symbol_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Symbol (List_front_Symbol_next(me), action, val);
    else Traverse_List_front_Symbol (List_front_Symbol_next(me), action, val);
  }
  }
  if (action->action_List_Symbol[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Symbol[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_Check (List_front_Check me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_Check, me)) return val;
  if (action->action_List_Check[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Check[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Check)
  { 
  if (!action->skip_children_List_Check) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Check (List_front_Check_data(me), action, val);
    else Traverse_front_Check (List_front_Check_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Check (List_front_Check_next(me), action, val);
    else Traverse_List_front_Check (List_front_Check_next(me), action, val);
  }
  }
  if (action->action_List_Check[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Check[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_Or (List_front_Or me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_Or, me)) return val;
  if (action->action_List_Or[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Or[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Or)
  { 
  if (!action->skip_children_List_Or) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Or (List_front_Or_data(me), action, val);
    else Traverse_front_Or (List_front_Or_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Or (List_front_Or_next(me), action, val);
    else Traverse_List_front_Or (List_front_Or_next(me), action, val);
  }
  }
  if (action->action_List_Or[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Or[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_Alternative (List_front_Alternative me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_Alternative, me)) return val;
  if (action->action_List_Alternative[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Alternative[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Alternative)
  { 
  if (!action->skip_children_List_Alternative) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Alternative (List_front_Alternative_data(me), action, val);
    else Traverse_front_Alternative (List_front_Alternative_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Alternative (List_front_Alternative_next(me), action, val);
    else Traverse_List_front_Alternative (List_front_Alternative_next(me), action, val);
  }
  }
  if (action->action_List_Alternative[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Alternative[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_Scoping (List_front_Scoping me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_Scoping, me)) return val;
  if (action->action_List_Scoping[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Scoping[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Scoping)
  { 
  if (!action->skip_children_List_Scoping) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Scoping (List_front_Scoping_data(me), action, val);
    else Traverse_front_Scoping (List_front_Scoping_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Scoping (List_front_Scoping_next(me), action, val);
    else Traverse_List_front_Scoping (List_front_Scoping_next(me), action, val);
  }
  }
  if (action->action_List_Scoping[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Scoping[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_ImportedNonTerminal, me)) return val;
  if (action->action_List_ImportedNonTerminal[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_ImportedNonTerminal[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_ImportedNonTerminal)
  { 
  if (!action->skip_children_List_ImportedNonTerminal) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_ImportedNonTerminal (List_front_ImportedNonTerminal_data(me), action, val);
    else Traverse_front_ImportedNonTerminal (List_front_ImportedNonTerminal_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal_next(me), action, val);
    else Traverse_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal_next(me), action, val);
  }
  }
  if (action->action_List_ImportedNonTerminal[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_ImportedNonTerminal[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_NonTerminal (List_front_NonTerminal me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_NonTerminal, me)) return val;
  if (action->action_List_NonTerminal[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_NonTerminal[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_NonTerminal)
  { 
  if (!action->skip_children_List_NonTerminal) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_NonTerminal (List_front_NonTerminal_data(me), action, val);
    else Traverse_front_NonTerminal (List_front_NonTerminal_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_NonTerminal (List_front_NonTerminal_next(me), action, val);
    else Traverse_List_front_NonTerminal (List_front_NonTerminal_next(me), action, val);
  }
  }
  if (action->action_List_NonTerminal[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_NonTerminal[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_Import (List_front_Import me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_Import, me)) return val;
  if (action->action_List_Import[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Import[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Import)
  { 
  if (!action->skip_children_List_Import) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_Import (List_front_Import_data(me), action, val);
    else Traverse_front_Import (List_front_Import_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_Import (List_front_Import_next(me), action, val);
    else Traverse_List_front_Import (List_front_Import_next(me), action, val);
  }
  }
  if (action->action_List_Import[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Import[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_front_NameSpace (List_front_NameSpace me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(List_NameSpace, me)) return val;
  if (action->action_List_NameSpace[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_NameSpace[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_NameSpace)
  { 
  if (!action->skip_children_List_NameSpace) {
    if (action->traversal != Traverse_Down)  val = Traverse_front_NameSpace (List_front_NameSpace_data(me), action, val);
    else Traverse_front_NameSpace (List_front_NameSpace_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_front_NameSpace (List_front_NameSpace_next(me), action, val);
    else Traverse_List_front_NameSpace (List_front_NameSpace_next(me), action, val);
  }
  }
  if (action->action_List_NameSpace[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_NameSpace[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Scoping (front_Scoping me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Scoping, me)) return val;
  if (action->action_Scoping[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scoping[PRE_ACTION](me, val);
  }
  { switch (me) {
      case front_NewScope:
        if (action->action_NewScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NewScope[PRE_ACTION](me, val);
        }
        if (action->action_NewScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NewScope[POST_ACTION](me, val);
        }
        break;
      case front_OpenScope:
        if (action->action_OpenScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OpenScope[PRE_ACTION](me, val);
        }
        if (action->action_OpenScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OpenScope[POST_ACTION](me, val);
        }
        break;
      case front_CloseScope:
        if (action->action_CloseScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CloseScope[PRE_ACTION](me, val);
        }
        if (action->action_CloseScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CloseScope[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Scoping[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scoping[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_And (front_And me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(And, me)) return val;
  if (action->action_And[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_And[PRE_ACTION](me, val);
  }
  { switch (me) {
      case front_AndTranspose:
        if (action->action_AndTranspose[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndTranspose[PRE_ACTION](me, val);
        }
        if (action->action_AndTranspose[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndTranspose[POST_ACTION](me, val);
        }
        break;
      case front_AndLeft:
        if (action->action_AndLeft[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndLeft[PRE_ACTION](me, val);
        }
        if (action->action_AndLeft[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndLeft[POST_ACTION](me, val);
        }
        break;
      case front_AndRight:
        if (action->action_AndRight[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndRight[PRE_ACTION](me, val);
        }
        if (action->action_AndRight[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndRight[POST_ACTION](me, val);
        }
        break;
      case front_AndCenter:
        if (action->action_AndCenter[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndCenter[PRE_ACTION](me, val);
        }
        if (action->action_AndCenter[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndCenter[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_And[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_And[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Or (front_Or me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Or, me)) return val;
  if (action->action_Or[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Or[PRE_ACTION](me, val);
  }
  { switch (me) {
      case front_OrCenter:
        if (action->action_OrCenter[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OrCenter[PRE_ACTION](me, val);
        }
        if (action->action_OrCenter[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OrCenter[POST_ACTION](me, val);
        }
        break;
      case front_OrLeft:
        if (action->action_OrLeft[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OrLeft[PRE_ACTION](me, val);
        }
        if (action->action_OrLeft[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OrLeft[POST_ACTION](me, val);
        }
        break;
      case front_OrRight:
        if (action->action_OrRight[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OrRight[PRE_ACTION](me, val);
        }
        if (action->action_OrRight[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OrRight[POST_ACTION](me, val);
        }
        break;
      case front_OrTranspose:
        if (action->action_OrTranspose[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OrTranspose[PRE_ACTION](me, val);
        }
        if (action->action_OrTranspose[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OrTranspose[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Or[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Or[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Define (front_Define me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Define, me)) return val;
  if (action->action_Define[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Define[PRE_ACTION](me, val);
  }
  { switch (me) {
      case front_Defining:
        if (action->action_Defining[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Defining[PRE_ACTION](me, val);
        }
        if (action->action_Defining[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Defining[POST_ACTION](me, val);
        }
        break;
      case front_Redefining:
        if (action->action_Redefining[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Redefining[PRE_ACTION](me, val);
        }
        if (action->action_Redefining[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Redefining[POST_ACTION](me, val);
        }
        break;
      case front_Overloading:
        if (action->action_Overloading[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Overloading[PRE_ACTION](me, val);
        }
        if (action->action_Overloading[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Overloading[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Define[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Define[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_Alternator (front_Alternator me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(Alternator, me)) return val;
  if (action->action_Alternator[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Alternator[PRE_ACTION](me, val);
  }
  {   }
  if (action->action_Alternator[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Alternator[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_front_NameOrField (front_NameOrField me, TraverseTable action, Pointer val)
{ 
  if (front_SKIP_NODE(NameOrField, me)) return val;
  if (action->action_NameOrField[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_NameOrField[PRE_ACTION](me, val);
  }
  { switch (me) {
      case front_AppliedName:
        if (action->action_AppliedName[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AppliedName[PRE_ACTION](me, val);
        }
        if (action->action_AppliedName[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AppliedName[POST_ACTION](me, val);
        }
        break;
      case front_AppliedField:
        if (action->action_AppliedField[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AppliedField[PRE_ACTION](me, val);
        }
        if (action->action_AppliedField[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AppliedField[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_NameOrField[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_NameOrField[POST_ACTION](me, val);
  }
  return val;
}

void Traverse_void_front_front (front_front me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(front, me)) return;
  if (action->action_front[PRE_ACTION] != NULL) {
    action->action_front[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_front)
  { 
  if (!action->skip_children_front) {
    Traverse_void_List_front_NameSpace (front_front_namespaces(me), action);
    Traverse_void_List_front_Import (front_front_imports(me), action);
    Traverse_void_List_front_NonTerminal (front_front_rules(me), action);
  }
  }
  if (action->action_front[POST_ACTION] != NULL) {
    action->action_front[POST_ACTION](me);
  }
}

void Traverse_void_front_Import (front_Import me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Import, me)) return;
  if (action->action_Import[PRE_ACTION] != NULL) {
    action->action_Import[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Import)
  { 
  if (!action->skip_children_Import) {
    Traverse_void_List_front_ImportedNonTerminal (front_Import_nts(me), action);
  }
  }
  if (action->action_Import[POST_ACTION] != NULL) {
    action->action_Import[POST_ACTION](me);
  }
}

void Traverse_void_front_ImportedNonTerminal (front_ImportedNonTerminal me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(ImportedNonTerminal, me)) return;
  if (action->action_ImportedNonTerminal[PRE_ACTION] != NULL) {
    action->action_ImportedNonTerminal[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_ImportedNonTerminal)
  { 
  }
  if (action->action_ImportedNonTerminal[POST_ACTION] != NULL) {
    action->action_ImportedNonTerminal[POST_ACTION](me);
  }
}

void Traverse_void_front_NonTerminal (front_NonTerminal me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(NonTerminal, me)) return;
  if (action->action_NonTerminal[PRE_ACTION] != NULL) {
    action->action_NonTerminal[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_NonTerminal)
  { 
  if (!action->skip_children_NonTerminal) {
    Traverse_void_front_ScanInfo (front_NonTerminal_scan(me), action);
    Traverse_void_front_Super (front_NonTerminal_super(me), action);
    Traverse_void_front_Defines (front_NonTerminal_alias(me), action);
    Traverse_void_front_Rhs (front_NonTerminal_rhs(me), action);
  }
  }
  if (action->action_NonTerminal[POST_ACTION] != NULL) {
    action->action_NonTerminal[POST_ACTION](me);
  }
}

void Traverse_void_front_Super (front_Super me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Super, me)) return;
  if (action->action_Super[PRE_ACTION] != NULL) {
    action->action_Super[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Super)
  { switch (front_Super_tag(me)) {
      case front_SubType_kind:
        if (action->action_SubType[PRE_ACTION] != NULL) {
          action->action_SubType[PRE_ACTION](me);
        }
        if (action->action_SubType[POST_ACTION] != NULL) {
          action->action_SubType[POST_ACTION](me);
        }
        break;
      case front_NoType_kind:
        if (action->action_NoType[PRE_ACTION] != NULL) {
          action->action_NoType[PRE_ACTION](me);
        }
        if (action->action_NoType[POST_ACTION] != NULL) {
          action->action_NoType[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Super[POST_ACTION] != NULL) {
    action->action_Super[POST_ACTION](me);
  }
}

void Traverse_void_front_Rhs (front_Rhs me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Rhs, me)) return;
  if (action->action_Rhs[PRE_ACTION] != NULL) {
    action->action_Rhs[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Rhs)
  { 
  if (!action->skip_children_Rhs) {
    Traverse_void_List_front_Scoping (front_Rhs_sc(me), action);
    Traverse_void_front_Symbol (front_Rhs_syms1(me), action);
    Traverse_void_List_front_Alternative (front_Rhs_alts(me), action);
    Traverse_void_List_front_Or (front_Rhs_ops(me), action);
    Traverse_void_front_Symbol (front_Rhs_syms2(me), action);
    Traverse_void_List_front_Check (front_Rhs_checklist(me), action);
  }
  }
  if (action->action_Rhs[POST_ACTION] != NULL) {
    action->action_Rhs[POST_ACTION](me);
  }
}

void Traverse_void_front_Alternative (front_Alternative me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Alternative, me)) return;
  if (action->action_Alternative[PRE_ACTION] != NULL) {
    action->action_Alternative[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Alternative)
  { switch (front_Alternative_tag(me)) {
      case front_LabeledAlt_kind:
        if (action->action_LabeledAlt[PRE_ACTION] != NULL) {
          action->action_LabeledAlt[PRE_ACTION](me);
        }
        if (!action->skip_children_LabeledAlt) {
          Traverse_void_front_Rhs (front_LabeledAlt_rhs(me), action);
        }
        if (action->action_LabeledAlt[POST_ACTION] != NULL) {
          action->action_LabeledAlt[POST_ACTION](me);
        }
        break;
      case front_UnLabeledAlt_kind:
        if (action->action_UnLabeledAlt[PRE_ACTION] != NULL) {
          action->action_UnLabeledAlt[PRE_ACTION](me);
        }
        if (!action->skip_children_UnLabeledAlt) {
          Traverse_void_front_Symbol (front_UnLabeledAlt_syms(me), action);
        }
        if (action->action_UnLabeledAlt[POST_ACTION] != NULL) {
          action->action_UnLabeledAlt[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Alternative[POST_ACTION] != NULL) {
    action->action_Alternative[POST_ACTION](me);
  }
}

void Traverse_void_front_Symbol (front_Symbol me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Symbol, me)) return;
  if (action->action_Symbol[PRE_ACTION] != NULL) {
    action->action_Symbol[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Symbol)
  { switch (front_Symbol_tag(me)) {
      case front_LabeledSym_kind:
        if (action->action_LabeledSym[PRE_ACTION] != NULL) {
          action->action_LabeledSym[PRE_ACTION](me);
        }
        if (!action->skip_children_LabeledSym) {
          Traverse_void_front_Symbol (front_LabeledSym_sym(me), action);
        }
        if (action->action_LabeledSym[POST_ACTION] != NULL) {
          action->action_LabeledSym[POST_ACTION](me);
        }
        break;
      case front_AltSymbol_kind:
        if (action->action_AltSymbol[PRE_ACTION] != NULL) {
          action->action_AltSymbol[PRE_ACTION](me);
        }
        if (!action->skip_children_AltSymbol) {
          Traverse_void_front_Symbol (front_AltSymbol_syms1(me), action);
          Traverse_void_front_Alternator (front_AltSymbol_alt(me), action);
          Traverse_void_List_front_Symbol (front_AltSymbol_syms(me), action);
        }
        if (action->action_AltSymbol[POST_ACTION] != NULL) {
          action->action_AltSymbol[POST_ACTION](me);
        }
        break;
      case front_SymbolSeq_kind:
        if (action->action_SymbolSeq[PRE_ACTION] != NULL) {
          action->action_SymbolSeq[PRE_ACTION](me);
        }
        if (!action->skip_children_SymbolSeq) {
          Traverse_void_List_front_Symbol (front_SymbolSeq_symbols(me), action);
          Traverse_void_List_front_Field (front_SymbolSeq_my_fields(me), action);
          Traverse_void_List_front_And (front_SymbolSeq_ands(me), action);
        }
        if (action->action_SymbolSeq[POST_ACTION] != NULL) {
          action->action_SymbolSeq[POST_ACTION](me);
        }
        break;
      case front_CompareSym_kind:
        if (action->action_Symbol2[PRE_ACTION] != NULL) {
          action->action_Symbol2[PRE_ACTION](me);
        }
        if (action->action_CompareSym[PRE_ACTION] != NULL) {
          action->action_CompareSym[PRE_ACTION](me);
        }
        if (!action->skip_children_Symbol2) {
          Traverse_void_front_Symbol (front_Symbol2_sym(me), action);
        }
        if (action->action_CompareSym[POST_ACTION] != NULL) {
          action->action_CompareSym[POST_ACTION](me);
        }
        if (action->action_Symbol2[POST_ACTION] != NULL) {
          action->action_Symbol2[POST_ACTION](me);
        }
        break;
      case front_AppliedSym_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_AppliedSym[PRE_ACTION] != NULL) {
          action->action_AppliedSym[PRE_ACTION](me);
        }
        if (!action->skip_children_AppliedSym) {
          Traverse_void_front_NameOrField (front_AppliedSym_field(me), action);
          Traverse_void_front_Expr (front_AppliedSym_sc(me), action);
        }
        if (action->action_AppliedSym[POST_ACTION] != NULL) {
          action->action_AppliedSym[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_StringSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_StringSymbol[PRE_ACTION] != NULL) {
          action->action_StringSymbol[PRE_ACTION](me);
        }
        if (!action->skip_children_StringSymbol) {
          Traverse_void_front_Type (front_StringSymbol_type(me), action);
        }
        if (action->action_StringSymbol[POST_ACTION] != NULL) {
          action->action_StringSymbol[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_CharSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_CharSymbol[PRE_ACTION] != NULL) {
          action->action_CharSymbol[PRE_ACTION](me);
        }
        if (!action->skip_children_CharSymbol) {
          Traverse_void_front_Type (front_CharSymbol_type(me), action);
        }
        if (action->action_CharSymbol[POST_ACTION] != NULL) {
          action->action_CharSymbol[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_KeywordSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_KeywordSymbol[PRE_ACTION] != NULL) {
          action->action_KeywordSymbol[PRE_ACTION](me);
        }
        if (!action->skip_children_KeywordSymbol) {
          Traverse_void_front_Type (front_KeywordSymbol_type(me), action);
        }
        if (action->action_KeywordSymbol[POST_ACTION] != NULL) {
          action->action_KeywordSymbol[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_OnceSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          action->action_CompoundSym[PRE_ACTION](me);
        }
        if (action->action_OnceSymbol[PRE_ACTION] != NULL) {
          action->action_OnceSymbol[PRE_ACTION](me);
        }
        if (!action->skip_children_CompoundSym) {
          Traverse_void_List_front_Symbol (front_CompoundSym_sym(me), action);
          Traverse_void_List_front_Or (front_CompoundSym_ops(me), action);
        }
        if (action->action_OnceSymbol[POST_ACTION] != NULL) {
          action->action_OnceSymbol[POST_ACTION](me);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          action->action_CompoundSym[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_OptSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          action->action_CompoundSym[PRE_ACTION](me);
        }
        if (action->action_OptSymbol[PRE_ACTION] != NULL) {
          action->action_OptSymbol[PRE_ACTION](me);
        }
        if (!action->skip_children_CompoundSym) {
          Traverse_void_List_front_Symbol (front_CompoundSym_sym(me), action);
          Traverse_void_List_front_Or (front_CompoundSym_ops(me), action);
        }
        if (action->action_OptSymbol[POST_ACTION] != NULL) {
          action->action_OptSymbol[POST_ACTION](me);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          action->action_CompoundSym[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_OptMoreSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          action->action_CompoundSym[PRE_ACTION](me);
        }
        if (action->action_OptMoreSymbol[PRE_ACTION] != NULL) {
          action->action_OptMoreSymbol[PRE_ACTION](me);
        }
        if (!action->skip_children_CompoundSym) {
          Traverse_void_List_front_Symbol (front_CompoundSym_sym(me), action);
          Traverse_void_List_front_Or (front_CompoundSym_ops(me), action);
        }
        if (action->action_OptMoreSymbol[POST_ACTION] != NULL) {
          action->action_OptMoreSymbol[POST_ACTION](me);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          action->action_CompoundSym[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_MoreSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          action->action_CompoundSym[PRE_ACTION](me);
        }
        if (action->action_MoreSymbol[PRE_ACTION] != NULL) {
          action->action_MoreSymbol[PRE_ACTION](me);
        }
        if (!action->skip_children_CompoundSym) {
          Traverse_void_List_front_Symbol (front_CompoundSym_sym(me), action);
          Traverse_void_List_front_Or (front_CompoundSym_ops(me), action);
        }
        if (action->action_MoreSymbol[POST_ACTION] != NULL) {
          action->action_MoreSymbol[POST_ACTION](me);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          action->action_CompoundSym[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_EmptySym_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_EmptySym[PRE_ACTION] != NULL) {
          action->action_EmptySym[PRE_ACTION](me);
        }
        if (action->action_EmptySym[POST_ACTION] != NULL) {
          action->action_EmptySym[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_LayoutString_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_LayoutString[PRE_ACTION] != NULL) {
          action->action_LayoutString[PRE_ACTION](me);
        }
        if (action->action_LayoutString[POST_ACTION] != NULL) {
          action->action_LayoutString[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_LayoutAction_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          action->action_SimpleSymbol[PRE_ACTION](me);
        }
        if (action->action_LayoutAction[PRE_ACTION] != NULL) {
          action->action_LayoutAction[PRE_ACTION](me);
        }
        if (!action->skip_children_LayoutAction) {
          Traverse_void_front_Expr (front_LayoutAction_layout(me), action);
        }
        if (action->action_LayoutAction[POST_ACTION] != NULL) {
          action->action_LayoutAction[POST_ACTION](me);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          action->action_SimpleSymbol[POST_ACTION](me);
        }
        break;
      case front_IdSym_kind:
        if (action->action_IdSym[PRE_ACTION] != NULL) {
          action->action_IdSym[PRE_ACTION](me);
        }
        if (!action->skip_children_IdSym) {
          Traverse_void_front_Type (front_IdSym_type(me), action);
        }
        if (action->action_IdSym[POST_ACTION] != NULL) {
          action->action_IdSym[POST_ACTION](me);
        }
        break;
      case front_DefiningSym_kind:
        if (action->action_DefiningSym[PRE_ACTION] != NULL) {
          action->action_DefiningSym[PRE_ACTION](me);
        }
        if (!action->skip_children_DefiningSym) {
          Traverse_void_front_Define (front_DefiningSym_def(me), action);
          Traverse_void_front_Defining_id (front_DefiningSym_id(me), action);
          Traverse_void_front_Expr (front_DefiningSym_sc(me), action);
        }
        if (action->action_DefiningSym[POST_ACTION] != NULL) {
          action->action_DefiningSym[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Symbol[POST_ACTION] != NULL) {
    action->action_Symbol[POST_ACTION](me);
  }
}

void Traverse_void_front_Defining_id (front_Defining_id me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Defining_id, me)) return;
  if (action->action_Defining_id[PRE_ACTION] != NULL) {
    action->action_Defining_id[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Defining_id)
  { switch (front_Defining_id_tag(me)) {
      case front_DefId_kind:
        if (action->action_DefId[PRE_ACTION] != NULL) {
          action->action_DefId[PRE_ACTION](me);
        }
        if (!action->skip_children_DefId) {
          Traverse_void_front_Symbol (front_DefId_id(me), action);
        }
        if (action->action_DefId[POST_ACTION] != NULL) {
          action->action_DefId[POST_ACTION](me);
        }
        break;
      case front_DefExpr_kind:
        if (action->action_DefExpr[PRE_ACTION] != NULL) {
          action->action_DefExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_DefExpr) {
          Traverse_void_front_Expr (front_DefExpr_e(me), action);
        }
        if (action->action_DefExpr[POST_ACTION] != NULL) {
          action->action_DefExpr[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Defining_id[POST_ACTION] != NULL) {
    action->action_Defining_id[POST_ACTION](me);
  }
}

void Traverse_void_front_Field (front_Field me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Field, me)) return;
  if (action->action_Field[PRE_ACTION] != NULL) {
    action->action_Field[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Field)
  { 
  if (!action->skip_children_Field) {
    Traverse_void_front_Type (front_Field_type(me), action);
    Traverse_void_List_front_FieldInit (front_Field_when(me), action);
  }
  }
  if (action->action_Field[POST_ACTION] != NULL) {
    action->action_Field[POST_ACTION](me);
  }
}

void Traverse_void_front_FieldInit (front_FieldInit me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(FieldInit, me)) return;
  if (action->action_FieldInit[PRE_ACTION] != NULL) {
    action->action_FieldInit[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_FieldInit)
  { switch (front_FieldInit_tag(me)) {
      case front_WhenCreate_kind:
        if (action->action_WhenCreate[PRE_ACTION] != NULL) {
          action->action_WhenCreate[PRE_ACTION](me);
        }
        if (!action->skip_children_FieldInit) {
          Traverse_void_front_Expr (front_FieldInit_expr(me), action);
        }
        if (action->action_WhenCreate[POST_ACTION] != NULL) {
          action->action_WhenCreate[POST_ACTION](me);
        }
        break;
      case front_WhenScope_kind:
        if (action->action_WhenScope[PRE_ACTION] != NULL) {
          action->action_WhenScope[PRE_ACTION](me);
        }
        if (!action->skip_children_FieldInit) {
          Traverse_void_front_Expr (front_FieldInit_expr(me), action);
        }
        if (action->action_WhenScope[POST_ACTION] != NULL) {
          action->action_WhenScope[POST_ACTION](me);
        }
        break;
      case front_WhenDefining_kind:
        if (action->action_WhenDefining[PRE_ACTION] != NULL) {
          action->action_WhenDefining[PRE_ACTION](me);
        }
        if (!action->skip_children_FieldInit) {
          Traverse_void_front_Expr (front_FieldInit_expr(me), action);
        }
        if (action->action_WhenDefining[POST_ACTION] != NULL) {
          action->action_WhenDefining[POST_ACTION](me);
        }
        break;
      case front_WhenApplied_kind:
        if (action->action_WhenApplied[PRE_ACTION] != NULL) {
          action->action_WhenApplied[PRE_ACTION](me);
        }
        if (!action->skip_children_FieldInit) {
          Traverse_void_front_Expr (front_FieldInit_expr(me), action);
        }
        if (action->action_WhenApplied[POST_ACTION] != NULL) {
          action->action_WhenApplied[POST_ACTION](me);
        }
        break;
      case front_WhenChecks_kind:
        if (action->action_WhenChecks[PRE_ACTION] != NULL) {
          action->action_WhenChecks[PRE_ACTION](me);
        }
        if (!action->skip_children_FieldInit) {
          Traverse_void_front_Expr (front_FieldInit_expr(me), action);
        }
        if (action->action_WhenChecks[POST_ACTION] != NULL) {
          action->action_WhenChecks[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_FieldInit[POST_ACTION] != NULL) {
    action->action_FieldInit[POST_ACTION](me);
  }
}

void Traverse_void_front_Type (front_Type me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Type, me)) return;
  if (action->action_Type[PRE_ACTION] != NULL) {
    action->action_Type[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Type)
  { 
  if (!action->skip_children_Type) {
    Traverse_void_List_front_Type (front_Type_args(me), action);
  }
  }
  if (action->action_Type[POST_ACTION] != NULL) {
    action->action_Type[POST_ACTION](me);
  }
}

void Traverse_void_front_Expr (front_Expr me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Expr, me)) return;
  if (action->action_Expr[PRE_ACTION] != NULL) {
    action->action_Expr[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Expr)
  { switch (front_Expr_tag(me)) {
      case front_BinExpr_kind:
        if (action->action_BinExpr[PRE_ACTION] != NULL) {
          action->action_BinExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_BinExpr) {
          Traverse_void_List_front_Expr (front_BinExpr_args(me), action);
        }
        if (action->action_BinExpr[POST_ACTION] != NULL) {
          action->action_BinExpr[POST_ACTION](me);
        }
        break;
      case front_MonExpr_kind:
        if (action->action_MonExpr1[PRE_ACTION] != NULL) {
          action->action_MonExpr1[PRE_ACTION](me);
        }
        if (action->action_MonExpr[PRE_ACTION] != NULL) {
          action->action_MonExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_MonExpr1) {
          Traverse_void_front_Expr (front_MonExpr1_arg(me), action);
        }
        if (action->action_MonExpr[POST_ACTION] != NULL) {
          action->action_MonExpr[POST_ACTION](me);
        }
        if (action->action_MonExpr1[POST_ACTION] != NULL) {
          action->action_MonExpr1[POST_ACTION](me);
        }
        break;
      case front_IdentExpr_kind:
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
      case front_QualExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_QualExpr[PRE_ACTION] != NULL) {
          action->action_QualExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_QualExpr) {
          Traverse_void_front_Expr (front_QualExpr_prefix(me), action);
        }
        if (action->action_QualExpr[POST_ACTION] != NULL) {
          action->action_QualExpr[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
      case front_IntExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_IntExpr[PRE_ACTION] != NULL) {
          action->action_IntExpr[PRE_ACTION](me);
        }
        if (action->action_IntExpr[POST_ACTION] != NULL) {
          action->action_IntExpr[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
      case front_BoolExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_BoolExpr[PRE_ACTION] != NULL) {
          action->action_BoolExpr[PRE_ACTION](me);
        }
        if (action->action_BoolExpr[POST_ACTION] != NULL) {
          action->action_BoolExpr[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
      case front_StringExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_StringExpr[PRE_ACTION] != NULL) {
          action->action_StringExpr[PRE_ACTION](me);
        }
        if (action->action_StringExpr[POST_ACTION] != NULL) {
          action->action_StringExpr[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
      case front_NilExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_NilExpr[PRE_ACTION] != NULL) {
          action->action_NilExpr[PRE_ACTION](me);
        }
        if (action->action_NilExpr[POST_ACTION] != NULL) {
          action->action_NilExpr[POST_ACTION](me);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          action->action_SimpleExpr[POST_ACTION](me);
        }
        break;
      case front_CallExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          action->action_SimpleExpr[PRE_ACTION](me);
        }
        if (action->action_CallExpr[PRE_ACTION] != NULL) {
          action->action_CallExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_CallExpr) {
          Traverse_void_front_Expr (front_CallExpr_func(me), action);
          Traverse_void_List_front_Expr (front_CallExpr_args(me), action);
        }
        if (action->action_CallExpr[POST_ACTION] != NULL) {
          action->action_CallExpr[POST_ACTION](me);
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

void Traverse_void_front_Check (front_Check me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Check, me)) return;
  if (action->action_Check[PRE_ACTION] != NULL) {
    action->action_Check[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Check)
  { 
  if (!action->skip_children_Check) {
    Traverse_void_front_Expr (front_Check_cond(me), action);
    Traverse_void_List_front_Expr (front_Check_message(me), action);
  }
  }
  if (action->action_Check[POST_ACTION] != NULL) {
    action->action_Check[POST_ACTION](me);
  }
}

void Traverse_void_front_ScanInfo (front_ScanInfo me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(ScanInfo, me)) return;
  if (action->action_ScanInfo[PRE_ACTION] != NULL) {
    action->action_ScanInfo[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_ScanInfo)
  { 
  if (!action->skip_children_ScanInfo) {
    Traverse_void_front_Type (front_ScanInfo_type(me), action);
  }
  }
  if (action->action_ScanInfo[POST_ACTION] != NULL) {
    action->action_ScanInfo[POST_ACTION](me);
  }
}

void Traverse_void_front_Defines (front_Defines me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Defines, me)) return;
  if (action->action_Defines[PRE_ACTION] != NULL) {
    action->action_Defines[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Defines)
  { switch (front_Defines_tag(me)) {
      case front_PlainDef_kind:
        if (action->action_PlainDef[PRE_ACTION] != NULL) {
          action->action_PlainDef[PRE_ACTION](me);
        }
        if (action->action_PlainDef[POST_ACTION] != NULL) {
          action->action_PlainDef[POST_ACTION](me);
        }
        break;
      case front_MacroDef_kind:
        if (action->action_MacroDef[PRE_ACTION] != NULL) {
          action->action_MacroDef[PRE_ACTION](me);
        }
        if (action->action_MacroDef[POST_ACTION] != NULL) {
          action->action_MacroDef[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Defines[POST_ACTION] != NULL) {
    action->action_Defines[POST_ACTION](me);
  }
}

void Traverse_void_front_NameSpace (front_NameSpace me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(NameSpace, me)) return;
  if (action->action_NameSpace[PRE_ACTION] != NULL) {
    action->action_NameSpace[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_NameSpace)
  { 
  }
  if (action->action_NameSpace[POST_ACTION] != NULL) {
    action->action_NameSpace[POST_ACTION](me);
  }
}

void Traverse_void_front_dummy (front_dummy me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(dummy, me)) return;
  if (action->action_dummy[PRE_ACTION] != NULL) {
    action->action_dummy[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_dummy)
  { 
  }
  if (action->action_dummy[POST_ACTION] != NULL) {
    action->action_dummy[POST_ACTION](me);
  }
}

void Traverse_void_front_Scope (front_Scope me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Scope, me)) return;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    action->action_Scope[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Scope)
  { switch (front_Scope_tag(me)) {
      case front_NonTerminalScope_kind:
        if (action->action_NonTerminalScope[PRE_ACTION] != NULL) {
          action->action_NonTerminalScope[PRE_ACTION](me);
        }
        if (!action->skip_children_Scope) {
          Traverse_void_front_Scope (front_Scope_next(me), action);
        }
        if (!action->skip_children_NonTerminalScope) {
          Traverse_void_front_NonTerminal (front_NonTerminalScope_data(me), action);
        }
        if (action->action_NonTerminalScope[POST_ACTION] != NULL) {
          action->action_NonTerminalScope[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    action->action_Scope[POST_ACTION](me);
  }
}

void Traverse_void_List_List_front_Symbol (List_List_front_Symbol me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_List_Symbol, me)) return;
  if (action->action_List_List_Symbol[PRE_ACTION] != NULL) {
    action->action_List_List_Symbol[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_List_Symbol)
  { 
  if (!action->skip_children_List_List_Symbol) {
    Traverse_void_List_front_Symbol (List_List_front_Symbol_data(me), action);
    Traverse_void_List_List_front_Symbol (List_List_front_Symbol_next(me), action);
  }
  }
  if (action->action_List_List_Symbol[POST_ACTION] != NULL) {
    action->action_List_List_Symbol[POST_ACTION](me);
  }
}

void Traverse_void_List_front_Expr (List_front_Expr me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_Expr, me)) return;
  if (action->action_List_Expr[PRE_ACTION] != NULL) {
    action->action_List_Expr[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Expr)
  { 
  if (!action->skip_children_List_Expr) {
    Traverse_void_front_Expr (List_front_Expr_data(me), action);
    Traverse_void_List_front_Expr (List_front_Expr_next(me), action);
  }
  }
  if (action->action_List_Expr[POST_ACTION] != NULL) {
    action->action_List_Expr[POST_ACTION](me);
  }
}

void Traverse_void_List_front_Type (List_front_Type me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_Type, me)) return;
  if (action->action_List_Type[PRE_ACTION] != NULL) {
    action->action_List_Type[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Type)
  { 
  if (!action->skip_children_List_Type) {
    Traverse_void_front_Type (List_front_Type_data(me), action);
    Traverse_void_List_front_Type (List_front_Type_next(me), action);
  }
  }
  if (action->action_List_Type[POST_ACTION] != NULL) {
    action->action_List_Type[POST_ACTION](me);
  }
}

void Traverse_void_List_front_FieldInit (List_front_FieldInit me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_FieldInit, me)) return;
  if (action->action_List_FieldInit[PRE_ACTION] != NULL) {
    action->action_List_FieldInit[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_FieldInit)
  { 
  if (!action->skip_children_List_FieldInit) {
    Traverse_void_front_FieldInit (List_front_FieldInit_data(me), action);
    Traverse_void_List_front_FieldInit (List_front_FieldInit_next(me), action);
  }
  }
  if (action->action_List_FieldInit[POST_ACTION] != NULL) {
    action->action_List_FieldInit[POST_ACTION](me);
  }
}

void Traverse_void_List_front_And (List_front_And me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_And, me)) return;
  if (action->action_List_And[PRE_ACTION] != NULL) {
    action->action_List_And[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_And)
  { 
  if (!action->skip_children_List_And) {
    Traverse_void_front_And (List_front_And_data(me), action);
    Traverse_void_List_front_And (List_front_And_next(me), action);
  }
  }
  if (action->action_List_And[POST_ACTION] != NULL) {
    action->action_List_And[POST_ACTION](me);
  }
}

void Traverse_void_List_front_Field (List_front_Field me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_Field, me)) return;
  if (action->action_List_Field[PRE_ACTION] != NULL) {
    action->action_List_Field[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Field)
  { 
  if (!action->skip_children_List_Field) {
    Traverse_void_front_Field (List_front_Field_data(me), action);
    Traverse_void_List_front_Field (List_front_Field_next(me), action);
  }
  }
  if (action->action_List_Field[POST_ACTION] != NULL) {
    action->action_List_Field[POST_ACTION](me);
  }
}

void Traverse_void_List_front_Symbol (List_front_Symbol me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_Symbol, me)) return;
  if (action->action_List_Symbol[PRE_ACTION] != NULL) {
    action->action_List_Symbol[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Symbol)
  { 
  if (!action->skip_children_List_Symbol) {
    Traverse_void_front_Symbol (List_front_Symbol_data(me), action);
    Traverse_void_List_front_Symbol (List_front_Symbol_next(me), action);
  }
  }
  if (action->action_List_Symbol[POST_ACTION] != NULL) {
    action->action_List_Symbol[POST_ACTION](me);
  }
}

void Traverse_void_List_front_Check (List_front_Check me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_Check, me)) return;
  if (action->action_List_Check[PRE_ACTION] != NULL) {
    action->action_List_Check[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Check)
  { 
  if (!action->skip_children_List_Check) {
    Traverse_void_front_Check (List_front_Check_data(me), action);
    Traverse_void_List_front_Check (List_front_Check_next(me), action);
  }
  }
  if (action->action_List_Check[POST_ACTION] != NULL) {
    action->action_List_Check[POST_ACTION](me);
  }
}

void Traverse_void_List_front_Or (List_front_Or me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_Or, me)) return;
  if (action->action_List_Or[PRE_ACTION] != NULL) {
    action->action_List_Or[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Or)
  { 
  if (!action->skip_children_List_Or) {
    Traverse_void_front_Or (List_front_Or_data(me), action);
    Traverse_void_List_front_Or (List_front_Or_next(me), action);
  }
  }
  if (action->action_List_Or[POST_ACTION] != NULL) {
    action->action_List_Or[POST_ACTION](me);
  }
}

void Traverse_void_List_front_Alternative (List_front_Alternative me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_Alternative, me)) return;
  if (action->action_List_Alternative[PRE_ACTION] != NULL) {
    action->action_List_Alternative[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Alternative)
  { 
  if (!action->skip_children_List_Alternative) {
    Traverse_void_front_Alternative (List_front_Alternative_data(me), action);
    Traverse_void_List_front_Alternative (List_front_Alternative_next(me), action);
  }
  }
  if (action->action_List_Alternative[POST_ACTION] != NULL) {
    action->action_List_Alternative[POST_ACTION](me);
  }
}

void Traverse_void_List_front_Scoping (List_front_Scoping me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_Scoping, me)) return;
  if (action->action_List_Scoping[PRE_ACTION] != NULL) {
    action->action_List_Scoping[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Scoping)
  { 
  if (!action->skip_children_List_Scoping) {
    Traverse_void_front_Scoping (List_front_Scoping_data(me), action);
    Traverse_void_List_front_Scoping (List_front_Scoping_next(me), action);
  }
  }
  if (action->action_List_Scoping[POST_ACTION] != NULL) {
    action->action_List_Scoping[POST_ACTION](me);
  }
}

void Traverse_void_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_ImportedNonTerminal, me)) return;
  if (action->action_List_ImportedNonTerminal[PRE_ACTION] != NULL) {
    action->action_List_ImportedNonTerminal[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_ImportedNonTerminal)
  { 
  if (!action->skip_children_List_ImportedNonTerminal) {
    Traverse_void_front_ImportedNonTerminal (List_front_ImportedNonTerminal_data(me), action);
    Traverse_void_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal_next(me), action);
  }
  }
  if (action->action_List_ImportedNonTerminal[POST_ACTION] != NULL) {
    action->action_List_ImportedNonTerminal[POST_ACTION](me);
  }
}

void Traverse_void_List_front_NonTerminal (List_front_NonTerminal me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_NonTerminal, me)) return;
  if (action->action_List_NonTerminal[PRE_ACTION] != NULL) {
    action->action_List_NonTerminal[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_NonTerminal)
  { 
  if (!action->skip_children_List_NonTerminal) {
    Traverse_void_front_NonTerminal (List_front_NonTerminal_data(me), action);
    Traverse_void_List_front_NonTerminal (List_front_NonTerminal_next(me), action);
  }
  }
  if (action->action_List_NonTerminal[POST_ACTION] != NULL) {
    action->action_List_NonTerminal[POST_ACTION](me);
  }
}

void Traverse_void_List_front_Import (List_front_Import me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_Import, me)) return;
  if (action->action_List_Import[PRE_ACTION] != NULL) {
    action->action_List_Import[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Import)
  { 
  if (!action->skip_children_List_Import) {
    Traverse_void_front_Import (List_front_Import_data(me), action);
    Traverse_void_List_front_Import (List_front_Import_next(me), action);
  }
  }
  if (action->action_List_Import[POST_ACTION] != NULL) {
    action->action_List_Import[POST_ACTION](me);
  }
}

void Traverse_void_List_front_NameSpace (List_front_NameSpace me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(List_NameSpace, me)) return;
  if (action->action_List_NameSpace[PRE_ACTION] != NULL) {
    action->action_List_NameSpace[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_NameSpace)
  { 
  if (!action->skip_children_List_NameSpace) {
    Traverse_void_front_NameSpace (List_front_NameSpace_data(me), action);
    Traverse_void_List_front_NameSpace (List_front_NameSpace_next(me), action);
  }
  }
  if (action->action_List_NameSpace[POST_ACTION] != NULL) {
    action->action_List_NameSpace[POST_ACTION](me);
  }
}

void Traverse_void_front_Scoping (front_Scoping me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Scoping, me)) return;
  if (action->action_Scoping[PRE_ACTION] != NULL) {
    action->action_Scoping[PRE_ACTION](me);
  }
  { switch (me) {
      case front_NewScope:
        if (action->action_NewScope[PRE_ACTION] != NULL) {
          action->action_NewScope[PRE_ACTION](me);
        }
        if (action->action_NewScope[POST_ACTION] != NULL) {
          action->action_NewScope[POST_ACTION](me);
        }
        break;
      case front_OpenScope:
        if (action->action_OpenScope[PRE_ACTION] != NULL) {
          action->action_OpenScope[PRE_ACTION](me);
        }
        if (action->action_OpenScope[POST_ACTION] != NULL) {
          action->action_OpenScope[POST_ACTION](me);
        }
        break;
      case front_CloseScope:
        if (action->action_CloseScope[PRE_ACTION] != NULL) {
          action->action_CloseScope[PRE_ACTION](me);
        }
        if (action->action_CloseScope[POST_ACTION] != NULL) {
          action->action_CloseScope[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Scoping[POST_ACTION] != NULL) {
    action->action_Scoping[POST_ACTION](me);
  }
}

void Traverse_void_front_And (front_And me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(And, me)) return;
  if (action->action_And[PRE_ACTION] != NULL) {
    action->action_And[PRE_ACTION](me);
  }
  { switch (me) {
      case front_AndTranspose:
        if (action->action_AndTranspose[PRE_ACTION] != NULL) {
          action->action_AndTranspose[PRE_ACTION](me);
        }
        if (action->action_AndTranspose[POST_ACTION] != NULL) {
          action->action_AndTranspose[POST_ACTION](me);
        }
        break;
      case front_AndLeft:
        if (action->action_AndLeft[PRE_ACTION] != NULL) {
          action->action_AndLeft[PRE_ACTION](me);
        }
        if (action->action_AndLeft[POST_ACTION] != NULL) {
          action->action_AndLeft[POST_ACTION](me);
        }
        break;
      case front_AndRight:
        if (action->action_AndRight[PRE_ACTION] != NULL) {
          action->action_AndRight[PRE_ACTION](me);
        }
        if (action->action_AndRight[POST_ACTION] != NULL) {
          action->action_AndRight[POST_ACTION](me);
        }
        break;
      case front_AndCenter:
        if (action->action_AndCenter[PRE_ACTION] != NULL) {
          action->action_AndCenter[PRE_ACTION](me);
        }
        if (action->action_AndCenter[POST_ACTION] != NULL) {
          action->action_AndCenter[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_And[POST_ACTION] != NULL) {
    action->action_And[POST_ACTION](me);
  }
}

void Traverse_void_front_Or (front_Or me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Or, me)) return;
  if (action->action_Or[PRE_ACTION] != NULL) {
    action->action_Or[PRE_ACTION](me);
  }
  { switch (me) {
      case front_OrCenter:
        if (action->action_OrCenter[PRE_ACTION] != NULL) {
          action->action_OrCenter[PRE_ACTION](me);
        }
        if (action->action_OrCenter[POST_ACTION] != NULL) {
          action->action_OrCenter[POST_ACTION](me);
        }
        break;
      case front_OrLeft:
        if (action->action_OrLeft[PRE_ACTION] != NULL) {
          action->action_OrLeft[PRE_ACTION](me);
        }
        if (action->action_OrLeft[POST_ACTION] != NULL) {
          action->action_OrLeft[POST_ACTION](me);
        }
        break;
      case front_OrRight:
        if (action->action_OrRight[PRE_ACTION] != NULL) {
          action->action_OrRight[PRE_ACTION](me);
        }
        if (action->action_OrRight[POST_ACTION] != NULL) {
          action->action_OrRight[POST_ACTION](me);
        }
        break;
      case front_OrTranspose:
        if (action->action_OrTranspose[PRE_ACTION] != NULL) {
          action->action_OrTranspose[PRE_ACTION](me);
        }
        if (action->action_OrTranspose[POST_ACTION] != NULL) {
          action->action_OrTranspose[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Or[POST_ACTION] != NULL) {
    action->action_Or[POST_ACTION](me);
  }
}

void Traverse_void_front_Define (front_Define me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Define, me)) return;
  if (action->action_Define[PRE_ACTION] != NULL) {
    action->action_Define[PRE_ACTION](me);
  }
  { switch (me) {
      case front_Defining:
        if (action->action_Defining[PRE_ACTION] != NULL) {
          action->action_Defining[PRE_ACTION](me);
        }
        if (action->action_Defining[POST_ACTION] != NULL) {
          action->action_Defining[POST_ACTION](me);
        }
        break;
      case front_Redefining:
        if (action->action_Redefining[PRE_ACTION] != NULL) {
          action->action_Redefining[PRE_ACTION](me);
        }
        if (action->action_Redefining[POST_ACTION] != NULL) {
          action->action_Redefining[POST_ACTION](me);
        }
        break;
      case front_Overloading:
        if (action->action_Overloading[PRE_ACTION] != NULL) {
          action->action_Overloading[PRE_ACTION](me);
        }
        if (action->action_Overloading[POST_ACTION] != NULL) {
          action->action_Overloading[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Define[POST_ACTION] != NULL) {
    action->action_Define[POST_ACTION](me);
  }
}

void Traverse_void_front_Alternator (front_Alternator me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(Alternator, me)) return;
  if (action->action_Alternator[PRE_ACTION] != NULL) {
    action->action_Alternator[PRE_ACTION](me);
  }
  {   }
  if (action->action_Alternator[POST_ACTION] != NULL) {
    action->action_Alternator[POST_ACTION](me);
  }
}

void Traverse_void_front_NameOrField (front_NameOrField me, void_front_TraverseTable action)
{ 
  if (front_SKIP_NODE(NameOrField, me)) return;
  if (action->action_NameOrField[PRE_ACTION] != NULL) {
    action->action_NameOrField[PRE_ACTION](me);
  }
  { switch (me) {
      case front_AppliedName:
        if (action->action_AppliedName[PRE_ACTION] != NULL) {
          action->action_AppliedName[PRE_ACTION](me);
        }
        if (action->action_AppliedName[POST_ACTION] != NULL) {
          action->action_AppliedName[POST_ACTION](me);
        }
        break;
      case front_AppliedField:
        if (action->action_AppliedField[PRE_ACTION] != NULL) {
          action->action_AppliedField[PRE_ACTION](me);
        }
        if (action->action_AppliedField[POST_ACTION] != NULL) {
          action->action_AppliedField[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_NameOrField[POST_ACTION] != NULL) {
    action->action_NameOrField[POST_ACTION](me);
  }
}

front_front Traverse_copy_front_front (front_front me, copy_front_TraverseTable action)
{ front_front _new = me, _old = me;
  if (action->action_front[PRE_ACTION] != NULL) {
    _new = action->action_front[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_front)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_front) {
    front_front_uses(me) = Traverse_copy_List_Ident (front_front_uses(me), action);
    front_front_namespaces(me) = Traverse_copy_List_front_NameSpace (front_front_namespaces(me), action);
    front_front_imports(me) = Traverse_copy_List_front_Import (front_front_imports(me), action);
    front_front_rules(me) = Traverse_copy_List_front_NonTerminal (front_front_rules(me), action);
  }
  }
  if (action->action_front[POST_ACTION] != NULL) {
    me = action->action_front[POST_ACTION](me, _old);
  }
  return me;
}

front_Import Traverse_copy_front_Import (front_Import me, copy_front_TraverseTable action)
{ front_Import _new = me, _old = me;
  if (action->action_Import[PRE_ACTION] != NULL) {
    _new = action->action_Import[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Import)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Import) {
    front_Import_nts(me) = Traverse_copy_List_front_ImportedNonTerminal (front_Import_nts(me), action);
  }
  }
  if (action->action_Import[POST_ACTION] != NULL) {
    me = action->action_Import[POST_ACTION](me, _old);
  }
  return me;
}

front_ImportedNonTerminal Traverse_copy_front_ImportedNonTerminal (front_ImportedNonTerminal me, copy_front_TraverseTable action)
{ front_ImportedNonTerminal _new = me, _old = me;
  if (action->action_ImportedNonTerminal[PRE_ACTION] != NULL) {
    _new = action->action_ImportedNonTerminal[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_ImportedNonTerminal)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      front_ImportedNonTerminal_scope(me) = NULL;
      front_ImportedNonTerminal_old_scope(me) = NULL;
      front_ImportedNonTerminal_grammar(me) = NULL;
    }
  }
  if (action->action_ImportedNonTerminal[POST_ACTION] != NULL) {
    me = action->action_ImportedNonTerminal[POST_ACTION](me, _old);
  }
  return me;
}

front_NonTerminal Traverse_copy_front_NonTerminal (front_NonTerminal me, copy_front_TraverseTable action)
{ front_NonTerminal _new = me, _old = me;
  if (action->action_NonTerminal[PRE_ACTION] != NULL) {
    _new = action->action_NonTerminal[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_NonTerminal)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_NonTerminal) {
    front_NonTerminal_scan(me) = Traverse_copy_front_ScanInfo (front_NonTerminal_scan(me), action);
    front_NonTerminal_super(me) = Traverse_copy_front_Super (front_NonTerminal_super(me), action);
    front_NonTerminal_alias(me) = Traverse_copy_front_Defines (front_NonTerminal_alias(me), action);
    front_NonTerminal_rhs(me) = Traverse_copy_front_Rhs (front_NonTerminal_rhs(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      front_NonTerminal_scope(me) = NULL;
      front_NonTerminal_old_scope(me) = NULL;
      front_NonTerminal_alt(me) = Create_LabeledAlt (NonTerminal_src_info (me), NonTerminal_id (me), NonTerminal_meemo (me), NonTerminal_skip (me), Create_Ident ("="), NonTerminal_rhs (me));
      front_NonTerminal_reachable(me) = FALSE;
    }
  }
  if (action->action_NonTerminal[POST_ACTION] != NULL) {
    me = action->action_NonTerminal[POST_ACTION](me, _old);
  }
  return me;
}

front_Super Traverse_copy_front_Super (front_Super me, copy_front_TraverseTable action)
{ front_Super _new = me, _old = me;
  if (action->action_Super[PRE_ACTION] != NULL) {
    _new = action->action_Super[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Super)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (front_Super_tag(me)) {
      case front_SubType_kind:
        if (action->action_SubType[PRE_ACTION] != NULL) {
          _new = action->action_SubType[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Super_scope(me) = NULL;
            front_Super_old_scope(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Super_super_bind(me) = NULL;
            front_Super_super(me) = NULL;
          }
        if (action->action_SubType[POST_ACTION] != NULL) {
          _new = action->action_SubType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_NoType_kind:
        if (action->action_NoType[PRE_ACTION] != NULL) {
          _new = action->action_NoType[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Super_scope(me) = NULL;
            front_Super_old_scope(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Super_super_bind(me) = NULL;
            front_Super_super(me) = NULL;
          }
        if (action->action_NoType[POST_ACTION] != NULL) {
          _new = action->action_NoType[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Super[POST_ACTION] != NULL) {
    me = action->action_Super[POST_ACTION](me, _old);
  }
  return me;
}

front_Rhs Traverse_copy_front_Rhs (front_Rhs me, copy_front_TraverseTable action)
{ front_Rhs _new = me, _old = me;
  if (action->action_Rhs[PRE_ACTION] != NULL) {
    _new = action->action_Rhs[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Rhs)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Rhs) {
    front_Rhs_sc(me) = Traverse_copy_List_front_Scoping (front_Rhs_sc(me), action);
    front_Rhs_syms1(me) = Traverse_copy_front_Symbol (front_Rhs_syms1(me), action);
    front_Rhs_alts(me) = Traverse_copy_List_front_Alternative (front_Rhs_alts(me), action);
    front_Rhs_ops(me) = Traverse_copy_List_front_Or (front_Rhs_ops(me), action);
    front_Rhs_syms2(me) = Traverse_copy_front_Symbol (front_Rhs_syms2(me), action);
    front_Rhs_checklist(me) = Traverse_copy_List_front_Check (front_Rhs_checklist(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      front_Rhs_fields(me) = NULL;
    }
  }
  if (action->action_Rhs[POST_ACTION] != NULL) {
    me = action->action_Rhs[POST_ACTION](me, _old);
  }
  return me;
}

front_Alternative Traverse_copy_front_Alternative (front_Alternative me, copy_front_TraverseTable action)
{ front_Alternative _new = me, _old = me;
  if (action->action_Alternative[PRE_ACTION] != NULL) {
    _new = action->action_Alternative[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Alternative)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (front_Alternative_tag(me)) {
      case front_LabeledAlt_kind:
        if (action->action_LabeledAlt[PRE_ACTION] != NULL) {
          _new = action->action_LabeledAlt[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Alternative_scope(me) = NULL;
            front_Alternative_old_scope(me) = NULL;
          }
        if (!action->skip_children_LabeledAlt) {
          front_LabeledAlt_rhs(me) = Traverse_copy_front_Rhs (front_LabeledAlt_rhs(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_LabeledAlt_fields(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Alternative_type(me) = NULL;
            front_Alternative_re(me) = NULL;
          }
        if (action->action_LabeledAlt[POST_ACTION] != NULL) {
          _new = action->action_LabeledAlt[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_UnLabeledAlt_kind:
        if (action->action_UnLabeledAlt[PRE_ACTION] != NULL) {
          _new = action->action_UnLabeledAlt[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Alternative_scope(me) = NULL;
            front_Alternative_old_scope(me) = NULL;
          }
        if (!action->skip_children_UnLabeledAlt) {
          front_UnLabeledAlt_syms(me) = Traverse_copy_front_Symbol (front_UnLabeledAlt_syms(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Alternative_type(me) = NULL;
            front_Alternative_re(me) = NULL;
          }
        if (action->action_UnLabeledAlt[POST_ACTION] != NULL) {
          _new = action->action_UnLabeledAlt[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Alternative[POST_ACTION] != NULL) {
    me = action->action_Alternative[POST_ACTION](me, _old);
  }
  return me;
}

front_Symbol Traverse_copy_front_Symbol (front_Symbol me, copy_front_TraverseTable action)
{ front_Symbol _new = me, _old = me;
  if (action->action_Symbol[PRE_ACTION] != NULL) {
    _new = action->action_Symbol[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Symbol)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (front_Symbol_tag(me)) {
      case front_LabeledSym_kind:
        if (action->action_LabeledSym[PRE_ACTION] != NULL) {
          _new = action->action_LabeledSym[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_LabeledSym) {
          front_LabeledSym_sym(me) = Traverse_copy_front_Symbol (front_LabeledSym_sym(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_LabeledSym[POST_ACTION] != NULL) {
          _new = action->action_LabeledSym[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_AltSymbol_kind:
        if (action->action_AltSymbol[PRE_ACTION] != NULL) {
          _new = action->action_AltSymbol[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_AltSymbol) {
          front_AltSymbol_syms1(me) = Traverse_copy_front_Symbol (front_AltSymbol_syms1(me), action);
          front_AltSymbol_alt(me) = Traverse_copy_front_Alternator (front_AltSymbol_alt(me), action);
          front_AltSymbol_syms(me) = Traverse_copy_List_front_Symbol (front_AltSymbol_syms(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_AltSymbol[POST_ACTION] != NULL) {
          _new = action->action_AltSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_SymbolSeq_kind:
        if (action->action_SymbolSeq[PRE_ACTION] != NULL) {
          _new = action->action_SymbolSeq[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_SymbolSeq) {
          front_SymbolSeq_symbols(me) = Traverse_copy_List_front_Symbol (front_SymbolSeq_symbols(me), action);
          front_SymbolSeq_my_fields(me) = Traverse_copy_List_front_Field (front_SymbolSeq_my_fields(me), action);
          front_SymbolSeq_ands(me) = Traverse_copy_List_front_And (front_SymbolSeq_ands(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_SymbolSeq[POST_ACTION] != NULL) {
          _new = action->action_SymbolSeq[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_CompareSym_kind:
        if (action->action_Symbol2[PRE_ACTION] != NULL) {
          _new = action->action_Symbol2[PRE_ACTION](me, me);
        }
        if (action->action_CompareSym[PRE_ACTION] != NULL) {
          _new = action->action_CompareSym[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_Symbol2) {
          front_Symbol2_sym(me) = Traverse_copy_front_Symbol (front_Symbol2_sym(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_CompareSym[POST_ACTION] != NULL) {
          _new = action->action_CompareSym[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_Symbol2[POST_ACTION] != NULL) {
          _new = action->action_Symbol2[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_AppliedSym_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_AppliedSym[PRE_ACTION] != NULL) {
          _new = action->action_AppliedSym[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_AppliedSym) {
          front_AppliedSym_field(me) = Traverse_copy_front_NameOrField (front_AppliedSym_field(me), action);
          front_AppliedSym_sc(me) = Traverse_copy_front_Expr (front_AppliedSym_sc(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_AppliedSym_nt_bind(me) = NULL;
            front_AppliedSym_nt(me) = NULL;
            front_AppliedSym_alt_bind(me) = NULL;
            front_AppliedSym_alt(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_AppliedSym[POST_ACTION] != NULL) {
          _new = action->action_AppliedSym[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_StringSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_StringSymbol[PRE_ACTION] != NULL) {
          _new = action->action_StringSymbol[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_StringSymbol) {
          front_StringSymbol_type(me) = Traverse_copy_front_Type (front_StringSymbol_type(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_StringSymbol[POST_ACTION] != NULL) {
          _new = action->action_StringSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_CharSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_CharSymbol[PRE_ACTION] != NULL) {
          _new = action->action_CharSymbol[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_CharSymbol) {
          front_CharSymbol_type(me) = Traverse_copy_front_Type (front_CharSymbol_type(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_CharSymbol[POST_ACTION] != NULL) {
          _new = action->action_CharSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_KeywordSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_KeywordSymbol[PRE_ACTION] != NULL) {
          _new = action->action_KeywordSymbol[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_KeywordSymbol) {
          front_KeywordSymbol_type(me) = Traverse_copy_front_Type (front_KeywordSymbol_type(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_KeywordSymbol[POST_ACTION] != NULL) {
          _new = action->action_KeywordSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_OnceSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          _new = action->action_CompoundSym[PRE_ACTION](me, me);
        }
        if (action->action_OnceSymbol[PRE_ACTION] != NULL) {
          _new = action->action_OnceSymbol[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_CompoundSym) {
          front_CompoundSym_sym(me) = Traverse_copy_List_front_Symbol (front_CompoundSym_sym(me), action);
          front_CompoundSym_ops(me) = Traverse_copy_List_front_Or (front_CompoundSym_ops(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_OnceSymbol[POST_ACTION] != NULL) {
          _new = action->action_OnceSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          _new = action->action_CompoundSym[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_OptSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          _new = action->action_CompoundSym[PRE_ACTION](me, me);
        }
        if (action->action_OptSymbol[PRE_ACTION] != NULL) {
          _new = action->action_OptSymbol[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_CompoundSym) {
          front_CompoundSym_sym(me) = Traverse_copy_List_front_Symbol (front_CompoundSym_sym(me), action);
          front_CompoundSym_ops(me) = Traverse_copy_List_front_Or (front_CompoundSym_ops(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_OptSymbol[POST_ACTION] != NULL) {
          _new = action->action_OptSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          _new = action->action_CompoundSym[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_OptMoreSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          _new = action->action_CompoundSym[PRE_ACTION](me, me);
        }
        if (action->action_OptMoreSymbol[PRE_ACTION] != NULL) {
          _new = action->action_OptMoreSymbol[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_CompoundSym) {
          front_CompoundSym_sym(me) = Traverse_copy_List_front_Symbol (front_CompoundSym_sym(me), action);
          front_CompoundSym_ops(me) = Traverse_copy_List_front_Or (front_CompoundSym_ops(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_OptMoreSymbol[POST_ACTION] != NULL) {
          _new = action->action_OptMoreSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          _new = action->action_CompoundSym[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_MoreSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          _new = action->action_CompoundSym[PRE_ACTION](me, me);
        }
        if (action->action_MoreSymbol[PRE_ACTION] != NULL) {
          _new = action->action_MoreSymbol[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_CompoundSym) {
          front_CompoundSym_sym(me) = Traverse_copy_List_front_Symbol (front_CompoundSym_sym(me), action);
          front_CompoundSym_ops(me) = Traverse_copy_List_front_Or (front_CompoundSym_ops(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_MoreSymbol[POST_ACTION] != NULL) {
          _new = action->action_MoreSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          _new = action->action_CompoundSym[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_EmptySym_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_EmptySym[PRE_ACTION] != NULL) {
          _new = action->action_EmptySym[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_EmptySym[POST_ACTION] != NULL) {
          _new = action->action_EmptySym[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_LayoutString_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_LayoutString[PRE_ACTION] != NULL) {
          _new = action->action_LayoutString[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_LayoutString[POST_ACTION] != NULL) {
          _new = action->action_LayoutString[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_LayoutAction_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[PRE_ACTION](me, me);
        }
        if (action->action_LayoutAction[PRE_ACTION] != NULL) {
          _new = action->action_LayoutAction[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_LayoutAction) {
          front_LayoutAction_layout(me) = Traverse_copy_front_Expr (front_LayoutAction_layout(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_LayoutAction[POST_ACTION] != NULL) {
          _new = action->action_LayoutAction[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          _new = action->action_SimpleSymbol[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_IdSym_kind:
        if (action->action_IdSym[PRE_ACTION] != NULL) {
          _new = action->action_IdSym[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_IdSym) {
          front_IdSym_type(me) = Traverse_copy_front_Type (front_IdSym_type(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_IdSym_nt_bind(me) = NULL;
            front_IdSym_nt(me) = NULL;
            front_IdSym_import_bind(me) = NULL;
            front_IdSym_import(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_IdSym[POST_ACTION] != NULL) {
          _new = action->action_IdSym[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_DefiningSym_kind:
        if (action->action_DefiningSym[PRE_ACTION] != NULL) {
          _new = action->action_DefiningSym[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_scope(me) = NULL;
            front_Symbol_old_scope(me) = NULL;
          }
        if (!action->skip_children_DefiningSym) {
          front_DefiningSym_def(me) = Traverse_copy_front_Define (front_DefiningSym_def(me), action);
          front_DefiningSym_id(me) = Traverse_copy_front_Defining_id (front_DefiningSym_id(me), action);
          front_DefiningSym_sc(me) = Traverse_copy_front_Expr (front_DefiningSym_sc(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_DefiningSym_ns_bind(me) = NULL;
            front_DefiningSym_ns(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            front_Symbol_fields(me) = NULL;
            front_Symbol_empty(me) = FALSE;
          }
        if (action->action_DefiningSym[POST_ACTION] != NULL) {
          _new = action->action_DefiningSym[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Symbol[POST_ACTION] != NULL) {
    me = action->action_Symbol[POST_ACTION](me, _old);
  }
  return me;
}

front_Defining_id Traverse_copy_front_Defining_id (front_Defining_id me, copy_front_TraverseTable action)
{ front_Defining_id _new = me, _old = me;
  if (action->action_Defining_id[PRE_ACTION] != NULL) {
    _new = action->action_Defining_id[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Defining_id)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (front_Defining_id_tag(me)) {
      case front_DefId_kind:
        if (action->action_DefId[PRE_ACTION] != NULL) {
          _new = action->action_DefId[PRE_ACTION](me, me);
        }
        if (!action->skip_children_DefId) {
          front_DefId_id(me) = Traverse_copy_front_Symbol (front_DefId_id(me), action);
        }
        if (action->action_DefId[POST_ACTION] != NULL) {
          _new = action->action_DefId[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_DefExpr_kind:
        if (action->action_DefExpr[PRE_ACTION] != NULL) {
          _new = action->action_DefExpr[PRE_ACTION](me, me);
        }
        if (!action->skip_children_DefExpr) {
          front_DefExpr_e(me) = Traverse_copy_front_Expr (front_DefExpr_e(me), action);
        }
        if (action->action_DefExpr[POST_ACTION] != NULL) {
          _new = action->action_DefExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Defining_id[POST_ACTION] != NULL) {
    me = action->action_Defining_id[POST_ACTION](me, _old);
  }
  return me;
}

front_Field Traverse_copy_front_Field (front_Field me, copy_front_TraverseTable action)
{ front_Field _new = me, _old = me;
  if (action->action_Field[PRE_ACTION] != NULL) {
    _new = action->action_Field[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Field)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Field) {
    front_Field_type(me) = Traverse_copy_front_Type (front_Field_type(me), action);
    front_Field_when(me) = Traverse_copy_List_front_FieldInit (front_Field_when(me), action);
  }
  }
  if (action->action_Field[POST_ACTION] != NULL) {
    me = action->action_Field[POST_ACTION](me, _old);
  }
  return me;
}

front_FieldInit Traverse_copy_front_FieldInit (front_FieldInit me, copy_front_TraverseTable action)
{ front_FieldInit _new = me, _old = me;
  if (action->action_FieldInit[PRE_ACTION] != NULL) {
    _new = action->action_FieldInit[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_FieldInit)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (front_FieldInit_tag(me)) {
      case front_WhenCreate_kind:
        if (action->action_WhenCreate[PRE_ACTION] != NULL) {
          _new = action->action_WhenCreate[PRE_ACTION](me, me);
        }
        if (!action->skip_children_FieldInit) {
          front_FieldInit_expr(me) = Traverse_copy_front_Expr (front_FieldInit_expr(me), action);
        }
        if (action->action_WhenCreate[POST_ACTION] != NULL) {
          _new = action->action_WhenCreate[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_WhenScope_kind:
        if (action->action_WhenScope[PRE_ACTION] != NULL) {
          _new = action->action_WhenScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_FieldInit) {
          front_FieldInit_expr(me) = Traverse_copy_front_Expr (front_FieldInit_expr(me), action);
        }
        if (action->action_WhenScope[POST_ACTION] != NULL) {
          _new = action->action_WhenScope[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_WhenDefining_kind:
        if (action->action_WhenDefining[PRE_ACTION] != NULL) {
          _new = action->action_WhenDefining[PRE_ACTION](me, me);
        }
        if (!action->skip_children_FieldInit) {
          front_FieldInit_expr(me) = Traverse_copy_front_Expr (front_FieldInit_expr(me), action);
        }
        if (action->action_WhenDefining[POST_ACTION] != NULL) {
          _new = action->action_WhenDefining[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_WhenApplied_kind:
        if (action->action_WhenApplied[PRE_ACTION] != NULL) {
          _new = action->action_WhenApplied[PRE_ACTION](me, me);
        }
        if (!action->skip_children_FieldInit) {
          front_FieldInit_expr(me) = Traverse_copy_front_Expr (front_FieldInit_expr(me), action);
        }
        if (action->action_WhenApplied[POST_ACTION] != NULL) {
          _new = action->action_WhenApplied[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_WhenChecks_kind:
        if (action->action_WhenChecks[PRE_ACTION] != NULL) {
          _new = action->action_WhenChecks[PRE_ACTION](me, me);
        }
        if (!action->skip_children_FieldInit) {
          front_FieldInit_expr(me) = Traverse_copy_front_Expr (front_FieldInit_expr(me), action);
        }
        if (action->action_WhenChecks[POST_ACTION] != NULL) {
          _new = action->action_WhenChecks[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_FieldInit[POST_ACTION] != NULL) {
    me = action->action_FieldInit[POST_ACTION](me, _old);
  }
  return me;
}

front_Type Traverse_copy_front_Type (front_Type me, copy_front_TraverseTable action)
{ front_Type _new = me, _old = me;
  if (action->action_Type[PRE_ACTION] != NULL) {
    _new = action->action_Type[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Type)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Type) {
    front_Type_args(me) = Traverse_copy_List_front_Type (front_Type_args(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      front_Type_scope(me) = NULL;
      front_Type_old_scope(me) = NULL;
      front_Type_nt_bind(me) = NULL;
      front_Type_nt(me) = NULL;
      front_Type_import_bind(me) = NULL;
      front_Type_import(me) = NULL;
      front_Type_alt_bind(me) = NULL;
      front_Type_alt(me) = NULL;
    }
  }
  if (action->action_Type[POST_ACTION] != NULL) {
    me = action->action_Type[POST_ACTION](me, _old);
  }
  return me;
}

front_Expr Traverse_copy_front_Expr (front_Expr me, copy_front_TraverseTable action)
{ front_Expr _new = me, _old = me;
  if (action->action_Expr[PRE_ACTION] != NULL) {
    _new = action->action_Expr[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Expr)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (front_Expr_tag(me)) {
      case front_BinExpr_kind:
        if (action->action_BinExpr[PRE_ACTION] != NULL) {
          _new = action->action_BinExpr[PRE_ACTION](me, me);
        }
        if (!action->skip_children_BinExpr) {
          front_BinExpr_args(me) = Traverse_copy_List_front_Expr (front_BinExpr_args(me), action);
          front_BinExpr_ops(me) = Traverse_copy_List_Ident (front_BinExpr_ops(me), action);
        }
        if (action->action_BinExpr[POST_ACTION] != NULL) {
          _new = action->action_BinExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_MonExpr_kind:
        if (action->action_MonExpr1[PRE_ACTION] != NULL) {
          _new = action->action_MonExpr1[PRE_ACTION](me, me);
        }
        if (action->action_MonExpr[PRE_ACTION] != NULL) {
          _new = action->action_MonExpr[PRE_ACTION](me, me);
        }
        if (!action->skip_children_MonExpr1) {
          front_MonExpr1_ops(me) = Traverse_copy_List_Ident (front_MonExpr1_ops(me), action);
          front_MonExpr1_arg(me) = Traverse_copy_front_Expr (front_MonExpr1_arg(me), action);
        }
        if (action->action_MonExpr[POST_ACTION] != NULL) {
          _new = action->action_MonExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_MonExpr1[POST_ACTION] != NULL) {
          _new = action->action_MonExpr1[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_IdentExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_IdentExpr[PRE_ACTION] != NULL) {
          _new = action->action_IdentExpr[PRE_ACTION](me, me);
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
      case front_QualExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_QualExpr[PRE_ACTION] != NULL) {
          _new = action->action_QualExpr[PRE_ACTION](me, me);
        }
        if (!action->skip_children_QualExpr) {
          front_QualExpr_prefix(me) = Traverse_copy_front_Expr (front_QualExpr_prefix(me), action);
        }
        if (action->action_QualExpr[POST_ACTION] != NULL) {
          _new = action->action_QualExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_IntExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_IntExpr[PRE_ACTION] != NULL) {
          _new = action->action_IntExpr[PRE_ACTION](me, me);
        }
        if (action->action_IntExpr[POST_ACTION] != NULL) {
          _new = action->action_IntExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_BoolExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_BoolExpr[PRE_ACTION] != NULL) {
          _new = action->action_BoolExpr[PRE_ACTION](me, me);
        }
        if (action->action_BoolExpr[POST_ACTION] != NULL) {
          _new = action->action_BoolExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_StringExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_StringExpr[PRE_ACTION] != NULL) {
          _new = action->action_StringExpr[PRE_ACTION](me, me);
        }
        if (action->action_StringExpr[POST_ACTION] != NULL) {
          _new = action->action_StringExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_NilExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_NilExpr[PRE_ACTION] != NULL) {
          _new = action->action_NilExpr[PRE_ACTION](me, me);
        }
        if (action->action_NilExpr[POST_ACTION] != NULL) {
          _new = action->action_NilExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          _new = action->action_SimpleExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_CallExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          _new = action->action_SimpleExpr[PRE_ACTION](me, me);
        }
        if (action->action_CallExpr[PRE_ACTION] != NULL) {
          _new = action->action_CallExpr[PRE_ACTION](me, me);
        }
        if (!action->skip_children_CallExpr) {
          front_CallExpr_func(me) = Traverse_copy_front_Expr (front_CallExpr_func(me), action);
          front_CallExpr_args(me) = Traverse_copy_List_front_Expr (front_CallExpr_args(me), action);
        }
        if (action->action_CallExpr[POST_ACTION] != NULL) {
          _new = action->action_CallExpr[POST_ACTION](me, me);
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

front_Check Traverse_copy_front_Check (front_Check me, copy_front_TraverseTable action)
{ front_Check _new = me, _old = me;
  if (action->action_Check[PRE_ACTION] != NULL) {
    _new = action->action_Check[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Check)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Check) {
    front_Check_cond(me) = Traverse_copy_front_Expr (front_Check_cond(me), action);
    front_Check_message(me) = Traverse_copy_List_front_Expr (front_Check_message(me), action);
  }
  }
  if (action->action_Check[POST_ACTION] != NULL) {
    me = action->action_Check[POST_ACTION](me, _old);
  }
  return me;
}

front_ScanInfo Traverse_copy_front_ScanInfo (front_ScanInfo me, copy_front_TraverseTable action)
{ front_ScanInfo _new = me, _old = me;
  if (action->action_ScanInfo[PRE_ACTION] != NULL) {
    _new = action->action_ScanInfo[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_ScanInfo)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_ScanInfo) {
    front_ScanInfo_type(me) = Traverse_copy_front_Type (front_ScanInfo_type(me), action);
  }
  }
  if (action->action_ScanInfo[POST_ACTION] != NULL) {
    me = action->action_ScanInfo[POST_ACTION](me, _old);
  }
  return me;
}

front_Defines Traverse_copy_front_Defines (front_Defines me, copy_front_TraverseTable action)
{ front_Defines _new = me, _old = me;
  if (action->action_Defines[PRE_ACTION] != NULL) {
    _new = action->action_Defines[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Defines)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (front_Defines_tag(me)) {
      case front_PlainDef_kind:
        if (action->action_PlainDef[PRE_ACTION] != NULL) {
          _new = action->action_PlainDef[PRE_ACTION](me, me);
        }
        if (action->action_PlainDef[POST_ACTION] != NULL) {
          _new = action->action_PlainDef[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case front_MacroDef_kind:
        if (action->action_MacroDef[PRE_ACTION] != NULL) {
          _new = action->action_MacroDef[PRE_ACTION](me, me);
        }
        if (action->action_MacroDef[POST_ACTION] != NULL) {
          _new = action->action_MacroDef[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Defines[POST_ACTION] != NULL) {
    me = action->action_Defines[POST_ACTION](me, _old);
  }
  return me;
}

front_NameSpace Traverse_copy_front_NameSpace (front_NameSpace me, copy_front_TraverseTable action)
{ front_NameSpace _new = me, _old = me;
  if (action->action_NameSpace[PRE_ACTION] != NULL) {
    _new = action->action_NameSpace[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_NameSpace)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      front_NameSpace_scope(me) = NULL;
      front_NameSpace_old_scope(me) = NULL;
    }
  }
  if (action->action_NameSpace[POST_ACTION] != NULL) {
    me = action->action_NameSpace[POST_ACTION](me, _old);
  }
  return me;
}

front_dummy Traverse_copy_front_dummy (front_dummy me, copy_front_TraverseTable action)
{ front_dummy _new = me, _old = me;
  if (action->action_dummy[PRE_ACTION] != NULL) {
    _new = action->action_dummy[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_dummy)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      front_dummy_x(me) = NULL;
    }
  }
  if (action->action_dummy[POST_ACTION] != NULL) {
    me = action->action_dummy[POST_ACTION](me, _old);
  }
  return me;
}

front_Scope Traverse_copy_front_Scope (front_Scope me, copy_front_TraverseTable action)
{ front_Scope _new = me, _old = me;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    _new = action->action_Scope[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (front_Scope)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (front_Scope_tag(me)) {
      case front_NonTerminalScope_kind:
        if (action->action_NonTerminalScope[PRE_ACTION] != NULL) {
          _new = action->action_NonTerminalScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Scope) {
          front_Scope_next(me) = Traverse_copy_front_Scope (front_Scope_next(me), action);
        }
        if (!action->skip_children_NonTerminalScope) {
          front_NonTerminalScope_data(me) = Traverse_copy_front_NonTerminal (front_NonTerminalScope_data(me), action);
        }
        if (action->action_NonTerminalScope[POST_ACTION] != NULL) {
          _new = action->action_NonTerminalScope[POST_ACTION](me, me);
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

List_List_front_Symbol Traverse_copy_List_List_front_Symbol (List_List_front_Symbol me, copy_front_TraverseTable action)
{ List_List_front_Symbol _new = me, _old = me;
  if (action->action_List_List_Symbol[PRE_ACTION] != NULL) {
    _new = action->action_List_List_Symbol[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_List_front_Symbol)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_List_Symbol) {
    List_List_front_Symbol_data(me) = Traverse_copy_List_front_Symbol (List_List_front_Symbol_data(me), action);
    List_List_front_Symbol_next(me) = Traverse_copy_List_List_front_Symbol (List_List_front_Symbol_next(me), action);
  }
  }
  if (action->action_List_List_Symbol[POST_ACTION] != NULL) {
    me = action->action_List_List_Symbol[POST_ACTION](me, _old);
  }
  return me;
}

List_front_Expr Traverse_copy_List_front_Expr (List_front_Expr me, copy_front_TraverseTable action)
{ List_front_Expr _new = me, _old = me;
  if (action->action_List_Expr[PRE_ACTION] != NULL) {
    _new = action->action_List_Expr[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_Expr)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Expr) {
    List_front_Expr_data(me) = Traverse_copy_front_Expr (List_front_Expr_data(me), action);
    List_front_Expr_next(me) = Traverse_copy_List_front_Expr (List_front_Expr_next(me), action);
  }
  }
  if (action->action_List_Expr[POST_ACTION] != NULL) {
    me = action->action_List_Expr[POST_ACTION](me, _old);
  }
  return me;
}

List_front_Type Traverse_copy_List_front_Type (List_front_Type me, copy_front_TraverseTable action)
{ List_front_Type _new = me, _old = me;
  if (action->action_List_Type[PRE_ACTION] != NULL) {
    _new = action->action_List_Type[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_Type)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Type) {
    List_front_Type_data(me) = Traverse_copy_front_Type (List_front_Type_data(me), action);
    List_front_Type_next(me) = Traverse_copy_List_front_Type (List_front_Type_next(me), action);
  }
  }
  if (action->action_List_Type[POST_ACTION] != NULL) {
    me = action->action_List_Type[POST_ACTION](me, _old);
  }
  return me;
}

List_front_FieldInit Traverse_copy_List_front_FieldInit (List_front_FieldInit me, copy_front_TraverseTable action)
{ List_front_FieldInit _new = me, _old = me;
  if (action->action_List_FieldInit[PRE_ACTION] != NULL) {
    _new = action->action_List_FieldInit[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_FieldInit)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_FieldInit) {
    List_front_FieldInit_data(me) = Traverse_copy_front_FieldInit (List_front_FieldInit_data(me), action);
    List_front_FieldInit_next(me) = Traverse_copy_List_front_FieldInit (List_front_FieldInit_next(me), action);
  }
  }
  if (action->action_List_FieldInit[POST_ACTION] != NULL) {
    me = action->action_List_FieldInit[POST_ACTION](me, _old);
  }
  return me;
}

List_front_And Traverse_copy_List_front_And (List_front_And me, copy_front_TraverseTable action)
{ List_front_And _new = me, _old = me;
  if (action->action_List_And[PRE_ACTION] != NULL) {
    _new = action->action_List_And[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_And)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_And) {
    List_front_And_data(me) = Traverse_copy_front_And (List_front_And_data(me), action);
    List_front_And_next(me) = Traverse_copy_List_front_And (List_front_And_next(me), action);
  }
  }
  if (action->action_List_And[POST_ACTION] != NULL) {
    me = action->action_List_And[POST_ACTION](me, _old);
  }
  return me;
}

List_front_Field Traverse_copy_List_front_Field (List_front_Field me, copy_front_TraverseTable action)
{ List_front_Field _new = me, _old = me;
  if (action->action_List_Field[PRE_ACTION] != NULL) {
    _new = action->action_List_Field[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_Field)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Field) {
    List_front_Field_data(me) = Traverse_copy_front_Field (List_front_Field_data(me), action);
    List_front_Field_next(me) = Traverse_copy_List_front_Field (List_front_Field_next(me), action);
  }
  }
  if (action->action_List_Field[POST_ACTION] != NULL) {
    me = action->action_List_Field[POST_ACTION](me, _old);
  }
  return me;
}

List_front_Symbol Traverse_copy_List_front_Symbol (List_front_Symbol me, copy_front_TraverseTable action)
{ List_front_Symbol _new = me, _old = me;
  if (action->action_List_Symbol[PRE_ACTION] != NULL) {
    _new = action->action_List_Symbol[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_Symbol)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Symbol) {
    List_front_Symbol_data(me) = Traverse_copy_front_Symbol (List_front_Symbol_data(me), action);
    List_front_Symbol_next(me) = Traverse_copy_List_front_Symbol (List_front_Symbol_next(me), action);
  }
  }
  if (action->action_List_Symbol[POST_ACTION] != NULL) {
    me = action->action_List_Symbol[POST_ACTION](me, _old);
  }
  return me;
}

List_front_Check Traverse_copy_List_front_Check (List_front_Check me, copy_front_TraverseTable action)
{ List_front_Check _new = me, _old = me;
  if (action->action_List_Check[PRE_ACTION] != NULL) {
    _new = action->action_List_Check[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_Check)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Check) {
    List_front_Check_data(me) = Traverse_copy_front_Check (List_front_Check_data(me), action);
    List_front_Check_next(me) = Traverse_copy_List_front_Check (List_front_Check_next(me), action);
  }
  }
  if (action->action_List_Check[POST_ACTION] != NULL) {
    me = action->action_List_Check[POST_ACTION](me, _old);
  }
  return me;
}

List_front_Or Traverse_copy_List_front_Or (List_front_Or me, copy_front_TraverseTable action)
{ List_front_Or _new = me, _old = me;
  if (action->action_List_Or[PRE_ACTION] != NULL) {
    _new = action->action_List_Or[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_Or)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Or) {
    List_front_Or_data(me) = Traverse_copy_front_Or (List_front_Or_data(me), action);
    List_front_Or_next(me) = Traverse_copy_List_front_Or (List_front_Or_next(me), action);
  }
  }
  if (action->action_List_Or[POST_ACTION] != NULL) {
    me = action->action_List_Or[POST_ACTION](me, _old);
  }
  return me;
}

List_front_Alternative Traverse_copy_List_front_Alternative (List_front_Alternative me, copy_front_TraverseTable action)
{ List_front_Alternative _new = me, _old = me;
  if (action->action_List_Alternative[PRE_ACTION] != NULL) {
    _new = action->action_List_Alternative[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_Alternative)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Alternative) {
    List_front_Alternative_data(me) = Traverse_copy_front_Alternative (List_front_Alternative_data(me), action);
    List_front_Alternative_next(me) = Traverse_copy_List_front_Alternative (List_front_Alternative_next(me), action);
  }
  }
  if (action->action_List_Alternative[POST_ACTION] != NULL) {
    me = action->action_List_Alternative[POST_ACTION](me, _old);
  }
  return me;
}

List_front_Scoping Traverse_copy_List_front_Scoping (List_front_Scoping me, copy_front_TraverseTable action)
{ List_front_Scoping _new = me, _old = me;
  if (action->action_List_Scoping[PRE_ACTION] != NULL) {
    _new = action->action_List_Scoping[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_Scoping)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Scoping) {
    List_front_Scoping_data(me) = Traverse_copy_front_Scoping (List_front_Scoping_data(me), action);
    List_front_Scoping_next(me) = Traverse_copy_List_front_Scoping (List_front_Scoping_next(me), action);
  }
  }
  if (action->action_List_Scoping[POST_ACTION] != NULL) {
    me = action->action_List_Scoping[POST_ACTION](me, _old);
  }
  return me;
}

List_front_ImportedNonTerminal Traverse_copy_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal me, copy_front_TraverseTable action)
{ List_front_ImportedNonTerminal _new = me, _old = me;
  if (action->action_List_ImportedNonTerminal[PRE_ACTION] != NULL) {
    _new = action->action_List_ImportedNonTerminal[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_ImportedNonTerminal)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_ImportedNonTerminal) {
    List_front_ImportedNonTerminal_data(me) = Traverse_copy_front_ImportedNonTerminal (List_front_ImportedNonTerminal_data(me), action);
    List_front_ImportedNonTerminal_next(me) = Traverse_copy_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal_next(me), action);
  }
  }
  if (action->action_List_ImportedNonTerminal[POST_ACTION] != NULL) {
    me = action->action_List_ImportedNonTerminal[POST_ACTION](me, _old);
  }
  return me;
}

List_front_NonTerminal Traverse_copy_List_front_NonTerminal (List_front_NonTerminal me, copy_front_TraverseTable action)
{ List_front_NonTerminal _new = me, _old = me;
  if (action->action_List_NonTerminal[PRE_ACTION] != NULL) {
    _new = action->action_List_NonTerminal[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_NonTerminal)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_NonTerminal) {
    List_front_NonTerminal_data(me) = Traverse_copy_front_NonTerminal (List_front_NonTerminal_data(me), action);
    List_front_NonTerminal_next(me) = Traverse_copy_List_front_NonTerminal (List_front_NonTerminal_next(me), action);
  }
  }
  if (action->action_List_NonTerminal[POST_ACTION] != NULL) {
    me = action->action_List_NonTerminal[POST_ACTION](me, _old);
  }
  return me;
}

List_front_Import Traverse_copy_List_front_Import (List_front_Import me, copy_front_TraverseTable action)
{ List_front_Import _new = me, _old = me;
  if (action->action_List_Import[PRE_ACTION] != NULL) {
    _new = action->action_List_Import[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_Import)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Import) {
    List_front_Import_data(me) = Traverse_copy_front_Import (List_front_Import_data(me), action);
    List_front_Import_next(me) = Traverse_copy_List_front_Import (List_front_Import_next(me), action);
  }
  }
  if (action->action_List_Import[POST_ACTION] != NULL) {
    me = action->action_List_Import[POST_ACTION](me, _old);
  }
  return me;
}

List_front_NameSpace Traverse_copy_List_front_NameSpace (List_front_NameSpace me, copy_front_TraverseTable action)
{ List_front_NameSpace _new = me, _old = me;
  if (action->action_List_NameSpace[PRE_ACTION] != NULL) {
    _new = action->action_List_NameSpace[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_front_NameSpace)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_NameSpace) {
    List_front_NameSpace_data(me) = Traverse_copy_front_NameSpace (List_front_NameSpace_data(me), action);
    List_front_NameSpace_next(me) = Traverse_copy_List_front_NameSpace (List_front_NameSpace_next(me), action);
  }
  }
  if (action->action_List_NameSpace[POST_ACTION] != NULL) {
    me = action->action_List_NameSpace[POST_ACTION](me, _old);
  }
  return me;
}

front_Scoping Traverse_copy_front_Scoping (front_Scoping me, copy_front_TraverseTable action)
{ front_Scoping _new = me, _old = me;
  if (action->action_Scoping[PRE_ACTION] != NULL) {
    return action->action_Scoping[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_Scoping[POST_ACTION] != NULL) {
    me = action->action_Scoping[POST_ACTION](me, _old);
  }
  return me;
}

front_And Traverse_copy_front_And (front_And me, copy_front_TraverseTable action)
{ front_And _new = me, _old = me;
  if (action->action_And[PRE_ACTION] != NULL) {
    return action->action_And[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_And[POST_ACTION] != NULL) {
    me = action->action_And[POST_ACTION](me, _old);
  }
  return me;
}

front_Or Traverse_copy_front_Or (front_Or me, copy_front_TraverseTable action)
{ front_Or _new = me, _old = me;
  if (action->action_Or[PRE_ACTION] != NULL) {
    return action->action_Or[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_Or[POST_ACTION] != NULL) {
    me = action->action_Or[POST_ACTION](me, _old);
  }
  return me;
}

front_Define Traverse_copy_front_Define (front_Define me, copy_front_TraverseTable action)
{ front_Define _new = me, _old = me;
  if (action->action_Define[PRE_ACTION] != NULL) {
    return action->action_Define[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_Define[POST_ACTION] != NULL) {
    me = action->action_Define[POST_ACTION](me, _old);
  }
  return me;
}

front_Alternator Traverse_copy_front_Alternator (front_Alternator me, copy_front_TraverseTable action)
{ front_Alternator _new = me, _old = me;
  if (action->action_Alternator[PRE_ACTION] != NULL) {
    return action->action_Alternator[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_Alternator[POST_ACTION] != NULL) {
    me = action->action_Alternator[POST_ACTION](me, _old);
  }
  return me;
}

front_NameOrField Traverse_copy_front_NameOrField (front_NameOrField me, copy_front_TraverseTable action)
{ front_NameOrField _new = me, _old = me;
  if (action->action_NameOrField[PRE_ACTION] != NULL) {
    return action->action_NameOrField[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_NameOrField[POST_ACTION] != NULL) {
    me = action->action_NameOrField[POST_ACTION](me, _old);
  }
  return me;
}

int Traverse_compare_front_front (front_front x, front_front y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_front[PRE_ACTION] != NULL) {
    return action->action_front[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_front) {
    if ((comp = Traverse_compare_List_Ident (front_front_uses(x),front_front_uses(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_NameSpace (front_front_namespaces(x),front_front_namespaces(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Import (front_front_imports(x),front_front_imports(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_NonTerminal (front_front_rules(x),front_front_rules(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_Import (front_Import x, front_Import y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Import[PRE_ACTION] != NULL) {
    return action->action_Import[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Import) {
    if ((comp = Traverse_compare_Ident (front_Import_grammar(x),front_Import_grammar(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_ImportedNonTerminal (front_Import_nts(x),front_Import_nts(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_ImportedNonTerminal (front_ImportedNonTerminal x, front_ImportedNonTerminal y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_ImportedNonTerminal[PRE_ACTION] != NULL) {
    return action->action_ImportedNonTerminal[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_ImportedNonTerminal) {
    if ((comp = Traverse_compare_Ident (front_ImportedNonTerminal_id(x),front_ImportedNonTerminal_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (front_ImportedNonTerminal_type(x),front_ImportedNonTerminal_type(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_NonTerminal (front_NonTerminal x, front_NonTerminal y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_NonTerminal[PRE_ACTION] != NULL) {
    return action->action_NonTerminal[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_NonTerminal) {
    if ((comp = Traverse_compare_Bool (front_NonTerminal_is_root(x),front_NonTerminal_is_root(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_front_ScanInfo (front_NonTerminal_scan(x),front_NonTerminal_scan(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (front_NonTerminal_id(x),front_NonTerminal_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_front_Super (front_NonTerminal_super(x),front_NonTerminal_super(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Bool (front_NonTerminal_meemo(x),front_NonTerminal_meemo(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Bool (front_NonTerminal_enumerate(x),front_NonTerminal_enumerate(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Bool (front_NonTerminal_skip(x),front_NonTerminal_skip(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_front_Defines (front_NonTerminal_alias(x),front_NonTerminal_alias(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_front_Rhs (front_NonTerminal_rhs(x),front_NonTerminal_rhs(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_Super (front_Super x, front_Super y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Super[PRE_ACTION] != NULL) {
    return action->action_Super[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (front_Super_tag(x) < front_Super_tag(y)) return -1;
  if (front_Super_tag(x) > front_Super_tag(y)) return 1;;
  switch (front_Super_tag(x)) {
      case front_SubType_kind:
        if (action->action_SubType[PRE_ACTION] != NULL) {
          return action->action_SubType[PRE_ACTION](x, y);
        }
        if (!action->skip_children_SubType) {
          if ((comp = Traverse_compare_Ident (front_SubType_x(x),front_SubType_x(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Super) {
          if ((comp = Traverse_compare_Ident (front_Super_id(x),front_Super_id(y), action)) != 0) return comp;
        }
        if (action->action_SubType[POST_ACTION] != NULL) {
          return action->action_SubType[POST_ACTION](x, y);
        }
        break;
      case front_NoType_kind:
        if (action->action_NoType[PRE_ACTION] != NULL) {
          return action->action_NoType[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Super) {
          if ((comp = Traverse_compare_Ident (front_Super_id(x),front_Super_id(y), action)) != 0) return comp;
        }
        if (action->action_NoType[POST_ACTION] != NULL) {
          return action->action_NoType[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_front_Rhs (front_Rhs x, front_Rhs y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Rhs[PRE_ACTION] != NULL) {
    return action->action_Rhs[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Rhs) {
    if ((comp = Traverse_compare_List_front_Scoping (front_Rhs_sc(x),front_Rhs_sc(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_front_Symbol (front_Rhs_syms1(x),front_Rhs_syms1(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (front_Rhs_x(x),front_Rhs_x(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Alternative (front_Rhs_alts(x),front_Rhs_alts(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Or (front_Rhs_ops(x),front_Rhs_ops(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (front_Rhs_y(x),front_Rhs_y(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_front_Symbol (front_Rhs_syms2(x),front_Rhs_syms2(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Check (front_Rhs_checklist(x),front_Rhs_checklist(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_Alternative (front_Alternative x, front_Alternative y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Alternative[PRE_ACTION] != NULL) {
    return action->action_Alternative[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (front_Alternative_tag(x) < front_Alternative_tag(y)) return -1;
  if (front_Alternative_tag(x) > front_Alternative_tag(y)) return 1;;
  switch (front_Alternative_tag(x)) {
      case front_LabeledAlt_kind:
        if (action->action_LabeledAlt[PRE_ACTION] != NULL) {
          return action->action_LabeledAlt[PRE_ACTION](x, y);
        }
        if (!action->skip_children_LabeledAlt) {
          if ((comp = Traverse_compare_Ident (front_LabeledAlt_id(x),front_LabeledAlt_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Bool (front_LabeledAlt_meemo(x),front_LabeledAlt_meemo(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Bool (front_LabeledAlt_skip(x),front_LabeledAlt_skip(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (front_LabeledAlt_def(x),front_LabeledAlt_def(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Rhs (front_LabeledAlt_rhs(x),front_LabeledAlt_rhs(y), action)) != 0) return comp;
        }
        if (action->action_LabeledAlt[POST_ACTION] != NULL) {
          return action->action_LabeledAlt[POST_ACTION](x, y);
        }
        break;
      case front_UnLabeledAlt_kind:
        if (action->action_UnLabeledAlt[PRE_ACTION] != NULL) {
          return action->action_UnLabeledAlt[PRE_ACTION](x, y);
        }
        if (!action->skip_children_UnLabeledAlt) {
          if ((comp = Traverse_compare_front_Symbol (front_UnLabeledAlt_syms(x),front_UnLabeledAlt_syms(y), action)) != 0) return comp;
        }
        if (action->action_UnLabeledAlt[POST_ACTION] != NULL) {
          return action->action_UnLabeledAlt[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_front_Symbol (front_Symbol x, front_Symbol y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Symbol[PRE_ACTION] != NULL) {
    return action->action_Symbol[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (front_Symbol_tag(x) < front_Symbol_tag(y)) return -1;
  if (front_Symbol_tag(x) > front_Symbol_tag(y)) return 1;;
  switch (front_Symbol_tag(x)) {
      case front_LabeledSym_kind:
        if (action->action_LabeledSym[PRE_ACTION] != NULL) {
          return action->action_LabeledSym[PRE_ACTION](x, y);
        }
        if (!action->skip_children_LabeledSym) {
          if ((comp = Traverse_compare_Ident (front_LabeledSym_id(x),front_LabeledSym_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Symbol (front_LabeledSym_sym(x),front_LabeledSym_sym(y), action)) != 0) return comp;
        }
        if (action->action_LabeledSym[POST_ACTION] != NULL) {
          return action->action_LabeledSym[POST_ACTION](x, y);
        }
        break;
      case front_AltSymbol_kind:
        if (action->action_AltSymbol[PRE_ACTION] != NULL) {
          return action->action_AltSymbol[PRE_ACTION](x, y);
        }
        if (!action->skip_children_AltSymbol) {
          if ((comp = Traverse_compare_front_Symbol (front_AltSymbol_syms1(x),front_AltSymbol_syms1(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Alternator (front_AltSymbol_alt(x),front_AltSymbol_alt(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_front_Symbol (front_AltSymbol_syms(x),front_AltSymbol_syms(y), action)) != 0) return comp;
        }
        if (action->action_AltSymbol[POST_ACTION] != NULL) {
          return action->action_AltSymbol[POST_ACTION](x, y);
        }
        break;
      case front_SymbolSeq_kind:
        if (action->action_SymbolSeq[PRE_ACTION] != NULL) {
          return action->action_SymbolSeq[PRE_ACTION](x, y);
        }
        if (!action->skip_children_SymbolSeq) {
          if ((comp = Traverse_compare_List_front_Symbol (front_SymbolSeq_symbols(x),front_SymbolSeq_symbols(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_front_Field (front_SymbolSeq_my_fields(x),front_SymbolSeq_my_fields(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_front_And (front_SymbolSeq_ands(x),front_SymbolSeq_ands(y), action)) != 0) return comp;
        }
        if (action->action_SymbolSeq[POST_ACTION] != NULL) {
          return action->action_SymbolSeq[POST_ACTION](x, y);
        }
        break;
      case front_CompareSym_kind:
        if (action->action_Symbol2[PRE_ACTION] != NULL) {
          return action->action_Symbol2[PRE_ACTION](x, y);
        }
        if (action->action_CompareSym[PRE_ACTION] != NULL) {
          return action->action_CompareSym[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Symbol2) {
          if ((comp = Traverse_compare_front_Symbol (front_Symbol2_sym(x),front_Symbol2_sym(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (front_Symbol2_comp(x),front_Symbol2_comp(y), action)) != 0) return comp;
        }
        if (action->action_CompareSym[POST_ACTION] != NULL) {
          return action->action_CompareSym[POST_ACTION](x, y);
        }
        if (action->action_Symbol2[POST_ACTION] != NULL) {
          return action->action_Symbol2[POST_ACTION](x, y);
        }
        break;
      case front_AppliedSym_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_AppliedSym[PRE_ACTION] != NULL) {
          return action->action_AppliedSym[PRE_ACTION](x, y);
        }
        if (!action->skip_children_AppliedSym) {
          if ((comp = Traverse_compare_Ident (front_AppliedSym_nt_id(x),front_AppliedSym_nt_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_NameOrField (front_AppliedSym_field(x),front_AppliedSym_field(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (front_AppliedSym_name(x),front_AppliedSym_name(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Expr (front_AppliedSym_sc(x),front_AppliedSym_sc(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Bool (front_AppliedSym_warn(x),front_AppliedSym_warn(y), action)) != 0) return comp;
        }
        if (action->action_AppliedSym[POST_ACTION] != NULL) {
          return action->action_AppliedSym[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_StringSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_StringSymbol[PRE_ACTION] != NULL) {
          return action->action_StringSymbol[PRE_ACTION](x, y);
        }
        if (!action->skip_children_StringSymbol) {
          if ((comp = Traverse_compare_String (front_StringSymbol_string(x),front_StringSymbol_string(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (front_StringSymbol_n(x),front_StringSymbol_n(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Type (front_StringSymbol_type(x),front_StringSymbol_type(y), action)) != 0) return comp;
        }
        if (action->action_StringSymbol[POST_ACTION] != NULL) {
          return action->action_StringSymbol[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_CharSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_CharSymbol[PRE_ACTION] != NULL) {
          return action->action_CharSymbol[PRE_ACTION](x, y);
        }
        if (!action->skip_children_CharSymbol) {
          if ((comp = Traverse_compare_String (front_CharSymbol_chr(x),front_CharSymbol_chr(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Type (front_CharSymbol_type(x),front_CharSymbol_type(y), action)) != 0) return comp;
        }
        if (action->action_CharSymbol[POST_ACTION] != NULL) {
          return action->action_CharSymbol[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_KeywordSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_KeywordSymbol[PRE_ACTION] != NULL) {
          return action->action_KeywordSymbol[PRE_ACTION](x, y);
        }
        if (!action->skip_children_KeywordSymbol) {
          if ((comp = Traverse_compare_String (front_KeywordSymbol_keyword(x),front_KeywordSymbol_keyword(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Type (front_KeywordSymbol_type(x),front_KeywordSymbol_type(y), action)) != 0) return comp;
        }
        if (action->action_KeywordSymbol[POST_ACTION] != NULL) {
          return action->action_KeywordSymbol[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_OnceSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          return action->action_CompoundSym[PRE_ACTION](x, y);
        }
        if (action->action_OnceSymbol[PRE_ACTION] != NULL) {
          return action->action_OnceSymbol[PRE_ACTION](x, y);
        }
        if (!action->skip_children_CompoundSym) {
          if ((comp = Traverse_compare_List_front_Symbol (front_CompoundSym_sym(x),front_CompoundSym_sym(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_front_Or (front_CompoundSym_ops(x),front_CompoundSym_ops(y), action)) != 0) return comp;
        }
        if (action->action_OnceSymbol[POST_ACTION] != NULL) {
          return action->action_OnceSymbol[POST_ACTION](x, y);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          return action->action_CompoundSym[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_OptSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          return action->action_CompoundSym[PRE_ACTION](x, y);
        }
        if (action->action_OptSymbol[PRE_ACTION] != NULL) {
          return action->action_OptSymbol[PRE_ACTION](x, y);
        }
        if (!action->skip_children_CompoundSym) {
          if ((comp = Traverse_compare_List_front_Symbol (front_CompoundSym_sym(x),front_CompoundSym_sym(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_front_Or (front_CompoundSym_ops(x),front_CompoundSym_ops(y), action)) != 0) return comp;
        }
        if (!action->skip_children_OptSymbol) {
          if ((comp = Traverse_compare_Bool (front_OptSymbol_in_line(x),front_OptSymbol_in_line(y), action)) != 0) return comp;
        }
        if (action->action_OptSymbol[POST_ACTION] != NULL) {
          return action->action_OptSymbol[POST_ACTION](x, y);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          return action->action_CompoundSym[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_OptMoreSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          return action->action_CompoundSym[PRE_ACTION](x, y);
        }
        if (action->action_OptMoreSymbol[PRE_ACTION] != NULL) {
          return action->action_OptMoreSymbol[PRE_ACTION](x, y);
        }
        if (!action->skip_children_CompoundSym) {
          if ((comp = Traverse_compare_List_front_Symbol (front_CompoundSym_sym(x),front_CompoundSym_sym(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_front_Or (front_CompoundSym_ops(x),front_CompoundSym_ops(y), action)) != 0) return comp;
        }
        if (action->action_OptMoreSymbol[POST_ACTION] != NULL) {
          return action->action_OptMoreSymbol[POST_ACTION](x, y);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          return action->action_CompoundSym[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_MoreSymbol_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_CompoundSym[PRE_ACTION] != NULL) {
          return action->action_CompoundSym[PRE_ACTION](x, y);
        }
        if (action->action_MoreSymbol[PRE_ACTION] != NULL) {
          return action->action_MoreSymbol[PRE_ACTION](x, y);
        }
        if (!action->skip_children_CompoundSym) {
          if ((comp = Traverse_compare_List_front_Symbol (front_CompoundSym_sym(x),front_CompoundSym_sym(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_front_Or (front_CompoundSym_ops(x),front_CompoundSym_ops(y), action)) != 0) return comp;
        }
        if (!action->skip_children_MoreSymbol) {
          if ((comp = Traverse_compare_Ident (front_MoreSymbol_more(x),front_MoreSymbol_more(y), action)) != 0) return comp;
        }
        if (action->action_MoreSymbol[POST_ACTION] != NULL) {
          return action->action_MoreSymbol[POST_ACTION](x, y);
        }
        if (action->action_CompoundSym[POST_ACTION] != NULL) {
          return action->action_CompoundSym[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_EmptySym_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_EmptySym[PRE_ACTION] != NULL) {
          return action->action_EmptySym[PRE_ACTION](x, y);
        }
        if (action->action_EmptySym[POST_ACTION] != NULL) {
          return action->action_EmptySym[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_LayoutString_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_LayoutString[PRE_ACTION] != NULL) {
          return action->action_LayoutString[PRE_ACTION](x, y);
        }
        if (!action->skip_children_LayoutString) {
          if ((comp = Traverse_compare_String (front_LayoutString_layout(x),front_LayoutString_layout(y), action)) != 0) return comp;
        }
        if (action->action_LayoutString[POST_ACTION] != NULL) {
          return action->action_LayoutString[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_LayoutAction_kind:
        if (action->action_SimpleSymbol[PRE_ACTION] != NULL) {
          return action->action_SimpleSymbol[PRE_ACTION](x, y);
        }
        if (action->action_LayoutAction[PRE_ACTION] != NULL) {
          return action->action_LayoutAction[PRE_ACTION](x, y);
        }
        if (!action->skip_children_LayoutAction) {
          if ((comp = Traverse_compare_front_Expr (front_LayoutAction_layout(x),front_LayoutAction_layout(y), action)) != 0) return comp;
        }
        if (action->action_LayoutAction[POST_ACTION] != NULL) {
          return action->action_LayoutAction[POST_ACTION](x, y);
        }
        if (action->action_SimpleSymbol[POST_ACTION] != NULL) {
          return action->action_SimpleSymbol[POST_ACTION](x, y);
        }
        break;
      case front_IdSym_kind:
        if (action->action_IdSym[PRE_ACTION] != NULL) {
          return action->action_IdSym[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IdSym) {
          if ((comp = Traverse_compare_Ident (front_IdSym_id(x),front_IdSym_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Type (front_IdSym_type(x),front_IdSym_type(y), action)) != 0) return comp;
        }
        if (action->action_IdSym[POST_ACTION] != NULL) {
          return action->action_IdSym[POST_ACTION](x, y);
        }
        break;
      case front_DefiningSym_kind:
        if (action->action_DefiningSym[PRE_ACTION] != NULL) {
          return action->action_DefiningSym[PRE_ACTION](x, y);
        }
        if (!action->skip_children_DefiningSym) {
          if ((comp = Traverse_compare_Bool (front_DefiningSym_forward(x),front_DefiningSym_forward(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Define (front_DefiningSym_def(x),front_DefiningSym_def(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Defining_id (front_DefiningSym_id(x),front_DefiningSym_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (front_DefiningSym_ns_id(x),front_DefiningSym_ns_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Expr (front_DefiningSym_sc(x),front_DefiningSym_sc(y), action)) != 0) return comp;
        }
        if (action->action_DefiningSym[POST_ACTION] != NULL) {
          return action->action_DefiningSym[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_front_Defining_id (front_Defining_id x, front_Defining_id y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Defining_id[PRE_ACTION] != NULL) {
    return action->action_Defining_id[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (front_Defining_id_tag(x) < front_Defining_id_tag(y)) return -1;
  if (front_Defining_id_tag(x) > front_Defining_id_tag(y)) return 1;;
  switch (front_Defining_id_tag(x)) {
      case front_DefId_kind:
        if (action->action_DefId[PRE_ACTION] != NULL) {
          return action->action_DefId[PRE_ACTION](x, y);
        }
        if (!action->skip_children_DefId) {
          if ((comp = Traverse_compare_front_Symbol (front_DefId_id(x),front_DefId_id(y), action)) != 0) return comp;
        }
        if (action->action_DefId[POST_ACTION] != NULL) {
          return action->action_DefId[POST_ACTION](x, y);
        }
        break;
      case front_DefExpr_kind:
        if (action->action_DefExpr[PRE_ACTION] != NULL) {
          return action->action_DefExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_DefExpr) {
          if ((comp = Traverse_compare_front_Expr (front_DefExpr_e(x),front_DefExpr_e(y), action)) != 0) return comp;
        }
        if (action->action_DefExpr[POST_ACTION] != NULL) {
          return action->action_DefExpr[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_front_Field (front_Field x, front_Field y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Field[PRE_ACTION] != NULL) {
    return action->action_Field[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Field) {
    if ((comp = Traverse_compare_Ident (front_Field_id(x),front_Field_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_front_Type (front_Field_type(x),front_Field_type(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (front_Field_assign(x),front_Field_assign(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_FieldInit (front_Field_when(x),front_Field_when(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Bool (front_Field_traverse(x),front_Field_traverse(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Bool (front_Field_clear(x),front_Field_clear(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Bool (front_Field_dont_clear(x),front_Field_dont_clear(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_FieldInit (front_FieldInit x, front_FieldInit y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_FieldInit[PRE_ACTION] != NULL) {
    return action->action_FieldInit[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (front_FieldInit_tag(x) < front_FieldInit_tag(y)) return -1;
  if (front_FieldInit_tag(x) > front_FieldInit_tag(y)) return 1;;
  switch (front_FieldInit_tag(x)) {
      case front_WhenCreate_kind:
        if (action->action_WhenCreate[PRE_ACTION] != NULL) {
          return action->action_WhenCreate[PRE_ACTION](x, y);
        }
        if (!action->skip_children_WhenCreate) {
          if ((comp = Traverse_compare_Bool (front_WhenCreate_c(x),front_WhenCreate_c(y), action)) != 0) return comp;
        }
        if (!action->skip_children_FieldInit) {
          if ((comp = Traverse_compare_front_Expr (front_FieldInit_expr(x),front_FieldInit_expr(y), action)) != 0) return comp;
        }
        if (action->action_WhenCreate[POST_ACTION] != NULL) {
          return action->action_WhenCreate[POST_ACTION](x, y);
        }
        break;
      case front_WhenScope_kind:
        if (action->action_WhenScope[PRE_ACTION] != NULL) {
          return action->action_WhenScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_FieldInit) {
          if ((comp = Traverse_compare_front_Expr (front_FieldInit_expr(x),front_FieldInit_expr(y), action)) != 0) return comp;
        }
        if (action->action_WhenScope[POST_ACTION] != NULL) {
          return action->action_WhenScope[POST_ACTION](x, y);
        }
        break;
      case front_WhenDefining_kind:
        if (action->action_WhenDefining[PRE_ACTION] != NULL) {
          return action->action_WhenDefining[PRE_ACTION](x, y);
        }
        if (!action->skip_children_FieldInit) {
          if ((comp = Traverse_compare_front_Expr (front_FieldInit_expr(x),front_FieldInit_expr(y), action)) != 0) return comp;
        }
        if (action->action_WhenDefining[POST_ACTION] != NULL) {
          return action->action_WhenDefining[POST_ACTION](x, y);
        }
        break;
      case front_WhenApplied_kind:
        if (action->action_WhenApplied[PRE_ACTION] != NULL) {
          return action->action_WhenApplied[PRE_ACTION](x, y);
        }
        if (!action->skip_children_FieldInit) {
          if ((comp = Traverse_compare_front_Expr (front_FieldInit_expr(x),front_FieldInit_expr(y), action)) != 0) return comp;
        }
        if (action->action_WhenApplied[POST_ACTION] != NULL) {
          return action->action_WhenApplied[POST_ACTION](x, y);
        }
        break;
      case front_WhenChecks_kind:
        if (action->action_WhenChecks[PRE_ACTION] != NULL) {
          return action->action_WhenChecks[PRE_ACTION](x, y);
        }
        if (!action->skip_children_FieldInit) {
          if ((comp = Traverse_compare_front_Expr (front_FieldInit_expr(x),front_FieldInit_expr(y), action)) != 0) return comp;
        }
        if (action->action_WhenChecks[POST_ACTION] != NULL) {
          return action->action_WhenChecks[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_front_Type (front_Type x, front_Type y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Type[PRE_ACTION] != NULL) {
    return action->action_Type[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Type) {
    if ((comp = Traverse_compare_Ident (front_Type_id(x),front_Type_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Type (front_Type_args(x),front_Type_args(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_Expr (front_Expr x, front_Expr y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Expr[PRE_ACTION] != NULL) {
    return action->action_Expr[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (front_Expr_tag(x) < front_Expr_tag(y)) return -1;
  if (front_Expr_tag(x) > front_Expr_tag(y)) return 1;;
  switch (front_Expr_tag(x)) {
      case front_BinExpr_kind:
        if (action->action_BinExpr[PRE_ACTION] != NULL) {
          return action->action_BinExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_BinExpr) {
          if ((comp = Traverse_compare_List_front_Expr (front_BinExpr_args(x),front_BinExpr_args(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_Ident (front_BinExpr_ops(x),front_BinExpr_ops(y), action)) != 0) return comp;
        }
        if (action->action_BinExpr[POST_ACTION] != NULL) {
          return action->action_BinExpr[POST_ACTION](x, y);
        }
        break;
      case front_MonExpr_kind:
        if (action->action_MonExpr1[PRE_ACTION] != NULL) {
          return action->action_MonExpr1[PRE_ACTION](x, y);
        }
        if (action->action_MonExpr[PRE_ACTION] != NULL) {
          return action->action_MonExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_MonExpr1) {
          if ((comp = Traverse_compare_List_Ident (front_MonExpr1_ops(x),front_MonExpr1_ops(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_front_Expr (front_MonExpr1_arg(x),front_MonExpr1_arg(y), action)) != 0) return comp;
        }
        if (action->action_MonExpr[POST_ACTION] != NULL) {
          return action->action_MonExpr[POST_ACTION](x, y);
        }
        if (action->action_MonExpr1[POST_ACTION] != NULL) {
          return action->action_MonExpr1[POST_ACTION](x, y);
        }
        break;
      case front_IdentExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_IdentExpr[PRE_ACTION] != NULL) {
          return action->action_IdentExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IdentExpr) {
          if ((comp = Traverse_compare_Ident (front_IdentExpr_id(x),front_IdentExpr_id(y), action)) != 0) return comp;
        }
        if (action->action_IdentExpr[POST_ACTION] != NULL) {
          return action->action_IdentExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case front_QualExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_QualExpr[PRE_ACTION] != NULL) {
          return action->action_QualExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_QualExpr) {
          if ((comp = Traverse_compare_front_Expr (front_QualExpr_prefix(x),front_QualExpr_prefix(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (front_QualExpr_id(x),front_QualExpr_id(y), action)) != 0) return comp;
        }
        if (action->action_QualExpr[POST_ACTION] != NULL) {
          return action->action_QualExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case front_IntExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_IntExpr[PRE_ACTION] != NULL) {
          return action->action_IntExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IntExpr) {
          if ((comp = Traverse_compare_Int (front_IntExpr_i(x),front_IntExpr_i(y), action)) != 0) return comp;
        }
        if (action->action_IntExpr[POST_ACTION] != NULL) {
          return action->action_IntExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case front_BoolExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_BoolExpr[PRE_ACTION] != NULL) {
          return action->action_BoolExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_BoolExpr) {
          if ((comp = Traverse_compare_Bool (front_BoolExpr_b(x),front_BoolExpr_b(y), action)) != 0) return comp;
        }
        if (action->action_BoolExpr[POST_ACTION] != NULL) {
          return action->action_BoolExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case front_StringExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_StringExpr[PRE_ACTION] != NULL) {
          return action->action_StringExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_StringExpr) {
          if ((comp = Traverse_compare_String (front_StringExpr_string(x),front_StringExpr_string(y), action)) != 0) return comp;
        }
        if (action->action_StringExpr[POST_ACTION] != NULL) {
          return action->action_StringExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case front_NilExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_NilExpr[PRE_ACTION] != NULL) {
          return action->action_NilExpr[PRE_ACTION](x, y);
        }
        if (action->action_NilExpr[POST_ACTION] != NULL) {
          return action->action_NilExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
      case front_CallExpr_kind:
        if (action->action_SimpleExpr[PRE_ACTION] != NULL) {
          return action->action_SimpleExpr[PRE_ACTION](x, y);
        }
        if (action->action_CallExpr[PRE_ACTION] != NULL) {
          return action->action_CallExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_CallExpr) {
          if ((comp = Traverse_compare_front_Expr (front_CallExpr_func(x),front_CallExpr_func(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_front_Expr (front_CallExpr_args(x),front_CallExpr_args(y), action)) != 0) return comp;
        }
        if (action->action_CallExpr[POST_ACTION] != NULL) {
          return action->action_CallExpr[POST_ACTION](x, y);
        }
        if (action->action_SimpleExpr[POST_ACTION] != NULL) {
          return action->action_SimpleExpr[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_front_Check (front_Check x, front_Check y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Check[PRE_ACTION] != NULL) {
    return action->action_Check[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Check) {
    if ((comp = Traverse_compare_front_Expr (front_Check_cond(x),front_Check_cond(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Bool (front_Check_warn(x),front_Check_warn(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Expr (front_Check_message(x),front_Check_message(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_ScanInfo (front_ScanInfo x, front_ScanInfo y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_ScanInfo[PRE_ACTION] != NULL) {
    return action->action_ScanInfo[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_ScanInfo) {
    if ((comp = Traverse_compare_front_Type (front_ScanInfo_type(x),front_ScanInfo_type(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Bool (front_ScanInfo_comment(x),front_ScanInfo_comment(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_Defines (front_Defines x, front_Defines y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Defines[PRE_ACTION] != NULL) {
    return action->action_Defines[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (front_Defines_tag(x) < front_Defines_tag(y)) return -1;
  if (front_Defines_tag(x) > front_Defines_tag(y)) return 1;;
  switch (front_Defines_tag(x)) {
      case front_PlainDef_kind:
        if (action->action_PlainDef[PRE_ACTION] != NULL) {
          return action->action_PlainDef[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Defines) {
          if ((comp = Traverse_compare_Ident (front_Defines_id(x),front_Defines_id(y), action)) != 0) return comp;
        }
        if (action->action_PlainDef[POST_ACTION] != NULL) {
          return action->action_PlainDef[POST_ACTION](x, y);
        }
        break;
      case front_MacroDef_kind:
        if (action->action_MacroDef[PRE_ACTION] != NULL) {
          return action->action_MacroDef[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Defines) {
          if ((comp = Traverse_compare_Ident (front_Defines_id(x),front_Defines_id(y), action)) != 0) return comp;
        }
        if (action->action_MacroDef[POST_ACTION] != NULL) {
          return action->action_MacroDef[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_front_NameSpace (front_NameSpace x, front_NameSpace y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_NameSpace[PRE_ACTION] != NULL) {
    return action->action_NameSpace[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_NameSpace) {
    if ((comp = Traverse_compare_Ident (front_NameSpace_id(x),front_NameSpace_id(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_dummy (front_dummy x, front_dummy y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_dummy[PRE_ACTION] != NULL) {
    return action->action_dummy[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  return comp;
}

int Traverse_compare_front_Scope (front_Scope x, front_Scope y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    return action->action_Scope[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (front_Scope_tag(x) < front_Scope_tag(y)) return -1;
  if (front_Scope_tag(x) > front_Scope_tag(y)) return 1;;
  switch (front_Scope_tag(x)) {
      case front_NonTerminalScope_kind:
        if (action->action_NonTerminalScope[PRE_ACTION] != NULL) {
          return action->action_NonTerminalScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Scope) {
          if ((comp = Traverse_compare_front_Scope (front_Scope_next(x),front_Scope_next(y), action)) != 0) return comp;
        }
        if (!action->skip_children_NonTerminalScope) {
          if ((comp = Traverse_compare_front_NonTerminal (front_NonTerminalScope_data(x),front_NonTerminalScope_data(y), action)) != 0) return comp;
        }
        if (action->action_NonTerminalScope[POST_ACTION] != NULL) {
          return action->action_NonTerminalScope[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_List_List_front_Symbol (List_List_front_Symbol x, List_List_front_Symbol y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_List_Symbol[PRE_ACTION] != NULL) {
    return action->action_List_List_Symbol[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_List_Symbol) {
    if ((comp = Traverse_compare_List_front_Symbol (List_List_front_Symbol_data(x),List_List_front_Symbol_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_List_front_Symbol (List_List_front_Symbol_next(x),List_List_front_Symbol_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_Expr (List_front_Expr x, List_front_Expr y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Expr[PRE_ACTION] != NULL) {
    return action->action_List_Expr[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Expr) {
    if ((comp = Traverse_compare_front_Expr (List_front_Expr_data(x),List_front_Expr_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Expr (List_front_Expr_next(x),List_front_Expr_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_Type (List_front_Type x, List_front_Type y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Type[PRE_ACTION] != NULL) {
    return action->action_List_Type[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Type) {
    if ((comp = Traverse_compare_front_Type (List_front_Type_data(x),List_front_Type_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Type (List_front_Type_next(x),List_front_Type_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_FieldInit (List_front_FieldInit x, List_front_FieldInit y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_FieldInit[PRE_ACTION] != NULL) {
    return action->action_List_FieldInit[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_FieldInit) {
    if ((comp = Traverse_compare_front_FieldInit (List_front_FieldInit_data(x),List_front_FieldInit_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_FieldInit (List_front_FieldInit_next(x),List_front_FieldInit_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_And (List_front_And x, List_front_And y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_And[PRE_ACTION] != NULL) {
    return action->action_List_And[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_And) {
    if ((comp = Traverse_compare_front_And (List_front_And_data(x),List_front_And_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_And (List_front_And_next(x),List_front_And_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_Field (List_front_Field x, List_front_Field y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Field[PRE_ACTION] != NULL) {
    return action->action_List_Field[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Field) {
    if ((comp = Traverse_compare_front_Field (List_front_Field_data(x),List_front_Field_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Field (List_front_Field_next(x),List_front_Field_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_Symbol (List_front_Symbol x, List_front_Symbol y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Symbol[PRE_ACTION] != NULL) {
    return action->action_List_Symbol[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Symbol) {
    if ((comp = Traverse_compare_front_Symbol (List_front_Symbol_data(x),List_front_Symbol_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Symbol (List_front_Symbol_next(x),List_front_Symbol_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_Check (List_front_Check x, List_front_Check y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Check[PRE_ACTION] != NULL) {
    return action->action_List_Check[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Check) {
    if ((comp = Traverse_compare_front_Check (List_front_Check_data(x),List_front_Check_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Check (List_front_Check_next(x),List_front_Check_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_Or (List_front_Or x, List_front_Or y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Or[PRE_ACTION] != NULL) {
    return action->action_List_Or[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Or) {
    if ((comp = Traverse_compare_front_Or (List_front_Or_data(x),List_front_Or_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Or (List_front_Or_next(x),List_front_Or_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_Alternative (List_front_Alternative x, List_front_Alternative y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Alternative[PRE_ACTION] != NULL) {
    return action->action_List_Alternative[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Alternative) {
    if ((comp = Traverse_compare_front_Alternative (List_front_Alternative_data(x),List_front_Alternative_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Alternative (List_front_Alternative_next(x),List_front_Alternative_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_Scoping (List_front_Scoping x, List_front_Scoping y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Scoping[PRE_ACTION] != NULL) {
    return action->action_List_Scoping[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Scoping) {
    if ((comp = Traverse_compare_front_Scoping (List_front_Scoping_data(x),List_front_Scoping_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Scoping (List_front_Scoping_next(x),List_front_Scoping_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal x, List_front_ImportedNonTerminal y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_ImportedNonTerminal[PRE_ACTION] != NULL) {
    return action->action_List_ImportedNonTerminal[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_ImportedNonTerminal) {
    if ((comp = Traverse_compare_front_ImportedNonTerminal (List_front_ImportedNonTerminal_data(x),List_front_ImportedNonTerminal_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal_next(x),List_front_ImportedNonTerminal_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_NonTerminal (List_front_NonTerminal x, List_front_NonTerminal y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_NonTerminal[PRE_ACTION] != NULL) {
    return action->action_List_NonTerminal[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_NonTerminal) {
    if ((comp = Traverse_compare_front_NonTerminal (List_front_NonTerminal_data(x),List_front_NonTerminal_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_NonTerminal (List_front_NonTerminal_next(x),List_front_NonTerminal_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_Import (List_front_Import x, List_front_Import y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Import[PRE_ACTION] != NULL) {
    return action->action_List_Import[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Import) {
    if ((comp = Traverse_compare_front_Import (List_front_Import_data(x),List_front_Import_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_Import (List_front_Import_next(x),List_front_Import_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_front_NameSpace (List_front_NameSpace x, List_front_NameSpace y, compare_front_TraverseTable action)
{ int comp = 0;
  if (action->action_List_NameSpace[PRE_ACTION] != NULL) {
    return action->action_List_NameSpace[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_NameSpace) {
    if ((comp = Traverse_compare_front_NameSpace (List_front_NameSpace_data(x),List_front_NameSpace_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_front_NameSpace (List_front_NameSpace_next(x),List_front_NameSpace_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_front_Scoping (front_Scoping x, front_Scoping y, compare_front_TraverseTable action)
{ if (action->action_Scoping[PRE_ACTION] != NULL) {
    return action->action_Scoping[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

int Traverse_compare_front_And (front_And x, front_And y, compare_front_TraverseTable action)
{ if (action->action_And[PRE_ACTION] != NULL) {
    return action->action_And[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

int Traverse_compare_front_Or (front_Or x, front_Or y, compare_front_TraverseTable action)
{ if (action->action_Or[PRE_ACTION] != NULL) {
    return action->action_Or[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

int Traverse_compare_front_Define (front_Define x, front_Define y, compare_front_TraverseTable action)
{ if (action->action_Define[PRE_ACTION] != NULL) {
    return action->action_Define[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

int Traverse_compare_front_Alternator (front_Alternator x, front_Alternator y, compare_front_TraverseTable action)
{ if (action->action_Alternator[PRE_ACTION] != NULL) {
    return action->action_Alternator[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

int Traverse_compare_front_NameOrField (front_NameOrField x, front_NameOrField y, compare_front_TraverseTable action)
{ if (action->action_NameOrField[PRE_ACTION] != NULL) {
    return action->action_NameOrField[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

static void* PushScope_front_ImportedNonTerminal (front_ImportedNonTerminal me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_ImportedNonTerminal_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_NonTerminal (front_NonTerminal me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  if (front_NonTerminal_scope(me) != NULL &&
      front_Scope_next(front_NonTerminal_scope(me))==(front_Scope)val &&
      NonTerminalScope_data(front_NonTerminal_scope(me)) == me)
       val = front_NonTerminal_scope(me);
  else {
    val = (void*)Create_NonTerminalScope ((front_Scope)val, me);
  }
  front_NonTerminal_scope(me) = (front_Scope) val;
  return val;
}

static void* PopScope_front_NonTerminal (front_NonTerminal me, void *val)
{ if (me == NULL) return val;
  val = (void*)me->old_scope;
  return val;
}

static void* PushScope_front_SubType (front_SubType me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Super_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_NoType (front_NoType me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Super_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_LabeledAlt (front_LabeledAlt me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Alternative_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_UnLabeledAlt (front_UnLabeledAlt me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Alternative_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_LabeledSym (front_LabeledSym me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_AltSymbol (front_AltSymbol me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_SymbolSeq (front_SymbolSeq me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_CompareSym (front_CompareSym me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_AppliedSym (front_AppliedSym me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_StringSymbol (front_StringSymbol me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_CharSymbol (front_CharSymbol me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_KeywordSymbol (front_KeywordSymbol me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_OnceSymbol (front_OnceSymbol me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_OptSymbol (front_OptSymbol me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_OptMoreSymbol (front_OptMoreSymbol me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_MoreSymbol (front_MoreSymbol me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_EmptySym (front_EmptySym me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_LayoutString (front_LayoutString me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_LayoutAction (front_LayoutAction me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_IdSym (front_IdSym me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_DefiningSym (front_DefiningSym me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Symbol_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_Type (front_Type me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_Type_scope(me) = (front_Scope) val;
  return val;
}

static void* PushScope_front_NameSpace (front_NameSpace me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (front_Scope) val;
  front_NameSpace_scope(me) = (front_Scope) val;
  return val;
}

struct s_front_TraverseTable front_scope_actions = {

  Traverse_Accumulate,
  { NULL,	NULL }, FALSE,	/* front_front */
  { NULL,	NULL }, FALSE,	/* front_Import */
  { NULL,	PushScope_front_ImportedNonTerminal }, FALSE,	/* front_ImportedNonTerminal */
  { PopScope_front_NonTerminal,	PushScope_front_NonTerminal }, FALSE,	/* front_NonTerminal */
  { NULL,	NULL }, FALSE,	/* front_Super */
  { NULL,	PushScope_front_SubType }, FALSE,	/* front_SubType */
  { NULL,	PushScope_front_NoType }, FALSE,	/* front_NoType */
  { NULL,	NULL }, FALSE,	/* front_Rhs */
  { NULL,	NULL }, FALSE,	/* front_Alternative */
  { NULL,	PushScope_front_LabeledAlt }, FALSE,	/* front_LabeledAlt */
  { NULL,	PushScope_front_UnLabeledAlt }, FALSE,	/* front_UnLabeledAlt */
  { NULL,	NULL }, FALSE,	/* front_Symbol */
  { NULL,	PushScope_front_LabeledSym }, FALSE,	/* front_LabeledSym */
  { NULL,	PushScope_front_AltSymbol }, FALSE,	/* front_AltSymbol */
  { NULL,	PushScope_front_SymbolSeq }, FALSE,	/* front_SymbolSeq */
  { NULL,	NULL }, FALSE,	/* front_Symbol2 */
  { NULL,	PushScope_front_CompareSym }, FALSE,	/* front_CompareSym */
  { NULL,	NULL }, FALSE,	/* front_SimpleSymbol */
  { NULL,	PushScope_front_AppliedSym }, FALSE,	/* front_AppliedSym */
  { NULL,	PushScope_front_StringSymbol }, FALSE,	/* front_StringSymbol */
  { NULL,	PushScope_front_CharSymbol }, FALSE,	/* front_CharSymbol */
  { NULL,	PushScope_front_KeywordSymbol }, FALSE,	/* front_KeywordSymbol */
  { NULL,	NULL }, FALSE,	/* front_CompoundSym */
  { NULL,	PushScope_front_OnceSymbol }, FALSE,	/* front_OnceSymbol */
  { NULL,	PushScope_front_OptSymbol }, FALSE,	/* front_OptSymbol */
  { NULL,	PushScope_front_OptMoreSymbol }, FALSE,	/* front_OptMoreSymbol */
  { NULL,	PushScope_front_MoreSymbol }, FALSE,	/* front_MoreSymbol */
  { NULL,	PushScope_front_EmptySym }, FALSE,	/* front_EmptySym */
  { NULL,	PushScope_front_LayoutString }, FALSE,	/* front_LayoutString */
  { NULL,	PushScope_front_LayoutAction }, FALSE,	/* front_LayoutAction */
  { NULL,	PushScope_front_IdSym }, FALSE,	/* front_IdSym */
  { NULL,	PushScope_front_DefiningSym }, FALSE,	/* front_DefiningSym */
  { NULL,	NULL }, FALSE,	/* front_Defining_id */
  { NULL,	NULL }, FALSE,	/* front_DefId */
  { NULL,	NULL }, FALSE,	/* front_DefExpr */
  { NULL,	NULL }, FALSE,	/* front_Field */
  { NULL,	NULL }, FALSE,	/* front_FieldInit */
  { NULL,	NULL }, FALSE,	/* front_WhenCreate */
  { NULL,	NULL }, FALSE,	/* front_WhenScope */
  { NULL,	NULL }, FALSE,	/* front_WhenDefining */
  { NULL,	NULL }, FALSE,	/* front_WhenApplied */
  { NULL,	NULL }, FALSE,	/* front_WhenChecks */
  { NULL,	PushScope_front_Type }, FALSE,	/* front_Type */
  { NULL,	NULL }, FALSE,	/* front_Expr */
  { NULL,	NULL }, FALSE,	/* front_BinExpr */
  { NULL,	NULL }, FALSE,	/* front_MonExpr1 */
  { NULL,	NULL }, FALSE,	/* front_MonExpr */
  { NULL,	NULL }, FALSE,	/* front_SimpleExpr */
  { NULL,	NULL }, FALSE,	/* front_IdentExpr */
  { NULL,	NULL }, FALSE,	/* front_QualExpr */
  { NULL,	NULL }, FALSE,	/* front_IntExpr */
  { NULL,	NULL }, FALSE,	/* front_BoolExpr */
  { NULL,	NULL }, FALSE,	/* front_StringExpr */
  { NULL,	NULL }, FALSE,	/* front_NilExpr */
  { NULL,	NULL }, FALSE,	/* front_CallExpr */
  { NULL,	NULL }, FALSE,	/* front_Check */
  { NULL,	NULL }, FALSE,	/* front_ScanInfo */
  { NULL,	NULL }, FALSE,	/* front_Defines */
  { NULL,	NULL }, FALSE,	/* front_PlainDef */
  { NULL,	NULL }, FALSE,	/* front_MacroDef */
  { NULL,	PushScope_front_NameSpace }, FALSE,	/* front_NameSpace */
  { NULL,	NULL }, FALSE,	/* front_dummy */
  { NULL,	NULL }, FALSE,	/* front_Scope */
  { NULL,	NULL }, FALSE,	/* front_NonTerminalScope */
  { NULL,	NULL }, FALSE,	/* List_List_front_Symbol */
  { NULL,	NULL }, FALSE,	/* List_front_Expr */
  { NULL,	NULL }, FALSE,	/* List_front_Type */
  { NULL,	NULL }, FALSE,	/* List_front_FieldInit */
  { NULL,	NULL }, FALSE,	/* List_front_And */
  { NULL,	NULL }, FALSE,	/* List_front_Field */
  { NULL,	NULL }, FALSE,	/* List_front_Symbol */
  { NULL,	NULL }, FALSE,	/* List_front_Check */
  { NULL,	NULL }, FALSE,	/* List_front_Or */
  { NULL,	NULL }, FALSE,	/* List_front_Alternative */
  { NULL,	NULL }, FALSE,	/* List_front_Scoping */
  { NULL,	NULL }, FALSE,	/* List_front_ImportedNonTerminal */
  { NULL,	NULL }, FALSE,	/* List_front_NonTerminal */
  { NULL,	NULL }, FALSE,	/* List_front_Import */
  { NULL,	NULL }, FALSE,	/* List_front_NameSpace */
  { NULL,	 NULL }, FALSE,	/* front_Scoping */
  { NULL,	 NULL }, FALSE,	/* front_NewScope */
  { NULL,	 NULL }, FALSE,	/* front_OpenScope */
  { NULL,	 NULL }, FALSE,	/* front_CloseScope */
  { NULL,	 NULL }, FALSE,	/* front_And */
  { NULL,	 NULL }, FALSE,	/* front_AndTranspose */
  { NULL,	 NULL }, FALSE,	/* front_AndLeft */
  { NULL,	 NULL }, FALSE,	/* front_AndRight */
  { NULL,	 NULL }, FALSE,	/* front_AndCenter */
  { NULL,	 NULL }, FALSE,	/* front_Or */
  { NULL,	 NULL }, FALSE,	/* front_OrCenter */
  { NULL,	 NULL }, FALSE,	/* front_OrLeft */
  { NULL,	 NULL }, FALSE,	/* front_OrRight */
  { NULL,	 NULL }, FALSE,	/* front_OrTranspose */
  { NULL,	 NULL }, FALSE,	/* front_Define */
  { NULL,	 NULL }, FALSE,	/* front_Defining */
  { NULL,	 NULL }, FALSE,	/* front_Redefining */
  { NULL,	 NULL }, FALSE,	/* front_Overloading */
  { NULL,	 NULL }, FALSE,	/* front_Alternator */
  { NULL,	 NULL }, FALSE,	/* front_NameOrField */
  { NULL,	 NULL }, FALSE,	/* front_AppliedName */
  { NULL,	 NULL }, FALSE,	/* front_AppliedField */
};

static void Defining_front_front (front_front me)
{
  if (me==NULL) return;
}

static void Defining_front_Import (front_Import me)
{
  if (me==NULL) return;
}

static void Defining_front_ImportedNonTerminal (front_ImportedNonTerminal me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_ImportedNonTerminal_scope(me);
  front_ImportedNonTerminal__num(me) = Scope_Num_Stores (scope);
  front_ImportedNonTerminal_id_bind(me) = ReplaceBind (front_ImportedNonTerminal_id_bind(me), front_ImportedNonTerminal_id(me), scope, Bind_front_ImportedNonTerminal_kind, me, front_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_front_NonTerminal (front_NonTerminal me)
{
  Scope scope;
  if (me==NULL) return;
  Scope__self (front_NonTerminal_scope(me)) = Scope_Num_Stores (front_NonTerminal_old_scope(me));
  scope = front_Scope_next(front_NonTerminal_scope(me));
  front_NonTerminal__num(me) = Scope_Num_Stores (scope);
  front_NonTerminal_id_bind(me) = ReplaceBind (front_NonTerminal_id_bind(me), front_NonTerminal_id(me), scope, Bind_front_NonTerminal_kind, me, front_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_front_Super (front_Super me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_Super_scope(me);
  front_Super__num(me) = Scope_Num_Stores (scope);
}

static void Defining_front_Rhs (front_Rhs me)
{
  if (me==NULL) return;
}

static void Defining_front_Alternative (front_Alternative me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_Alternative_scope(me);
  front_Alternative__num(me) = Scope_Num_Stores (scope);
}

static void Defining_front_LabeledAlt (front_LabeledAlt me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_Scope_next (Alternative_scope (me));
  front_Alternative__num(me) = Scope_Num_Stores (scope);
  front_LabeledAlt_id_bind(me) = ReplaceBind (front_LabeledAlt_id_bind(me), front_LabeledAlt_id(me), scope, Bind_front_Alternative_kind, me, front_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_front_Symbol (front_Symbol me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_Symbol_scope(me);
  front_Symbol__num(me) = Scope_Num_Stores (scope);
}

static void Defining_front_SimpleSymbol (front_SimpleSymbol me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_Symbol_scope(me);
  front_Symbol__num(me) = Scope_Num_Stores (scope);
}

static void Defining_front_AppliedSym (front_AppliedSym me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_Symbol_scope(me);
  front_Symbol__num(me) = Scope_Num_Stores (scope);
}

static void Defining_front_IdSym (front_IdSym me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_Symbol_scope(me);
  front_Symbol__num(me) = Scope_Num_Stores (scope);
}

static void Defining_front_DefiningSym (front_DefiningSym me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_Symbol_scope(me);
  front_Symbol__num(me) = Scope_Num_Stores (scope);
}

static void Defining_front_Defining_id (front_Defining_id me)
{
  if (me==NULL) return;
}

static void Defining_front_Field (front_Field me)
{
  if (me==NULL) return;
}

static void Defining_front_FieldInit (front_FieldInit me)
{
  if (me==NULL) return;
}

static void Defining_front_Type (front_Type me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_Type_scope(me);
  front_Type__num(me) = Scope_Num_Stores (scope);
}

static void Defining_front_Expr (front_Expr me)
{
  if (me==NULL) return;
}

static void Defining_front_Check (front_Check me)
{
  if (me==NULL) return;
}

static void Defining_front_ScanInfo (front_ScanInfo me)
{
  if (me==NULL) return;
}

static void Defining_front_Defines (front_Defines me)
{
  if (me==NULL) return;
}

static void Defining_front_NameSpace (front_NameSpace me)
{
  Scope scope;
  if (me==NULL) return;
  scope = front_NameSpace_scope(me);
  front_NameSpace__num(me) = Scope_Num_Stores (scope);
  front_NameSpace_id_bind(me) = ReplaceBind (front_NameSpace_id_bind(me), front_NameSpace_id(me), scope, Bind_front_NameSpace_kind, me, front_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_front_dummy (front_dummy me)
{
  if (me==NULL) return;
}

struct s_void_front_TraverseTable front_defining_actions = {

  { NULL,	(void*)Defining_front_front }, FALSE,	/* front_front */
  { NULL,	(void*)Defining_front_Import }, FALSE,	/* front_Import */
  { NULL,	(void*)Defining_front_ImportedNonTerminal }, FALSE,	/* front_ImportedNonTerminal */
  { NULL,	(void*)Defining_front_NonTerminal }, FALSE,	/* front_NonTerminal */
  { NULL,	(void*)Defining_front_Super }, FALSE,	/* front_Super */
  { NULL,	NULL }, FALSE,	/* front_SubType */
  { NULL,	NULL }, FALSE,	/* front_NoType */
  { NULL,	(void*)Defining_front_Rhs }, FALSE,	/* front_Rhs */
  { NULL,	(void*)Defining_front_Alternative }, FALSE,	/* front_Alternative */
  { NULL,	(void*)Defining_front_LabeledAlt }, FALSE,	/* front_LabeledAlt */
  { NULL,	NULL }, FALSE,	/* front_UnLabeledAlt */
  { NULL,	(void*)Defining_front_Symbol }, FALSE,	/* front_Symbol */
  { NULL,	NULL }, FALSE,	/* front_LabeledSym */
  { NULL,	NULL }, FALSE,	/* front_AltSymbol */
  { NULL,	NULL }, FALSE,	/* front_SymbolSeq */
  { NULL,	NULL }, FALSE,	/* front_Symbol2 */
  { NULL,	NULL }, FALSE,	/* front_CompareSym */
  { NULL,	NULL }, FALSE,	/* front_SimpleSymbol */
  { NULL,	NULL }, FALSE,	/* front_AppliedSym */
  { NULL,	NULL }, FALSE,	/* front_StringSymbol */
  { NULL,	NULL }, FALSE,	/* front_CharSymbol */
  { NULL,	NULL }, FALSE,	/* front_KeywordSymbol */
  { NULL,	NULL }, FALSE,	/* front_CompoundSym */
  { NULL,	NULL }, FALSE,	/* front_OnceSymbol */
  { NULL,	NULL }, FALSE,	/* front_OptSymbol */
  { NULL,	NULL }, FALSE,	/* front_OptMoreSymbol */
  { NULL,	NULL }, FALSE,	/* front_MoreSymbol */
  { NULL,	NULL }, FALSE,	/* front_EmptySym */
  { NULL,	NULL }, FALSE,	/* front_LayoutString */
  { NULL,	NULL }, FALSE,	/* front_LayoutAction */
  { NULL,	NULL }, FALSE,	/* front_IdSym */
  { NULL,	NULL }, FALSE,	/* front_DefiningSym */
  { NULL,	(void*)Defining_front_Defining_id }, FALSE,	/* front_Defining_id */
  { NULL,	NULL }, FALSE,	/* front_DefId */
  { NULL,	NULL }, FALSE,	/* front_DefExpr */
  { NULL,	(void*)Defining_front_Field }, FALSE,	/* front_Field */
  { NULL,	(void*)Defining_front_FieldInit }, FALSE,	/* front_FieldInit */
  { NULL,	NULL }, FALSE,	/* front_WhenCreate */
  { NULL,	NULL }, FALSE,	/* front_WhenScope */
  { NULL,	NULL }, FALSE,	/* front_WhenDefining */
  { NULL,	NULL }, FALSE,	/* front_WhenApplied */
  { NULL,	NULL }, FALSE,	/* front_WhenChecks */
  { NULL,	(void*)Defining_front_Type }, FALSE,	/* front_Type */
  { NULL,	(void*)Defining_front_Expr }, FALSE,	/* front_Expr */
  { NULL,	NULL }, FALSE,	/* front_BinExpr */
  { NULL,	NULL }, FALSE,	/* front_MonExpr1 */
  { NULL,	NULL }, FALSE,	/* front_MonExpr */
  { NULL,	NULL }, FALSE,	/* front_SimpleExpr */
  { NULL,	NULL }, FALSE,	/* front_IdentExpr */
  { NULL,	NULL }, FALSE,	/* front_QualExpr */
  { NULL,	NULL }, FALSE,	/* front_IntExpr */
  { NULL,	NULL }, FALSE,	/* front_BoolExpr */
  { NULL,	NULL }, FALSE,	/* front_StringExpr */
  { NULL,	NULL }, FALSE,	/* front_NilExpr */
  { NULL,	NULL }, FALSE,	/* front_CallExpr */
  { NULL,	(void*)Defining_front_Check }, FALSE,	/* front_Check */
  { NULL,	(void*)Defining_front_ScanInfo }, FALSE,	/* front_ScanInfo */
  { NULL,	(void*)Defining_front_Defines }, FALSE,	/* front_Defines */
  { NULL,	NULL }, FALSE,	/* front_PlainDef */
  { NULL,	NULL }, FALSE,	/* front_MacroDef */
  { NULL,	(void*)Defining_front_NameSpace }, FALSE,	/* front_NameSpace */
  { NULL,	(void*)Defining_front_dummy }, FALSE,	/* front_dummy */
  { NULL,	NULL }, FALSE,	/* front_Scope */
  { NULL,	NULL }, FALSE,	/* front_NonTerminalScope */
  { NULL,	NULL }, FALSE,	/* List_List_front_Symbol */
  { NULL,	NULL }, FALSE,	/* List_front_Expr */
  { NULL,	NULL }, FALSE,	/* List_front_Type */
  { NULL,	NULL }, FALSE,	/* List_front_FieldInit */
  { NULL,	NULL }, FALSE,	/* List_front_And */
  { NULL,	NULL }, FALSE,	/* List_front_Field */
  { NULL,	NULL }, FALSE,	/* List_front_Symbol */
  { NULL,	NULL }, FALSE,	/* List_front_Check */
  { NULL,	NULL }, FALSE,	/* List_front_Or */
  { NULL,	NULL }, FALSE,	/* List_front_Alternative */
  { NULL,	NULL }, FALSE,	/* List_front_Scoping */
  { NULL,	NULL }, FALSE,	/* List_front_ImportedNonTerminal */
  { NULL,	NULL }, FALSE,	/* List_front_NonTerminal */
  { NULL,	NULL }, FALSE,	/* List_front_Import */
  { NULL,	NULL }, FALSE,	/* List_front_NameSpace */
  { NULL,	 NULL }, FALSE,	/* front_Scoping */
  { NULL,	 NULL }, FALSE,	/* front_NewScope */
  { NULL,	 NULL }, FALSE,	/* front_OpenScope */
  { NULL,	 NULL }, FALSE,	/* front_CloseScope */
  { NULL,	 NULL }, FALSE,	/* front_And */
  { NULL,	 NULL }, FALSE,	/* front_AndTranspose */
  { NULL,	 NULL }, FALSE,	/* front_AndLeft */
  { NULL,	 NULL }, FALSE,	/* front_AndRight */
  { NULL,	 NULL }, FALSE,	/* front_AndCenter */
  { NULL,	 NULL }, FALSE,	/* front_Or */
  { NULL,	 NULL }, FALSE,	/* front_OrCenter */
  { NULL,	 NULL }, FALSE,	/* front_OrLeft */
  { NULL,	 NULL }, FALSE,	/* front_OrRight */
  { NULL,	 NULL }, FALSE,	/* front_OrTranspose */
  { NULL,	 NULL }, FALSE,	/* front_Define */
  { NULL,	 NULL }, FALSE,	/* front_Defining */
  { NULL,	 NULL }, FALSE,	/* front_Redefining */
  { NULL,	 NULL }, FALSE,	/* front_Overloading */
  { NULL,	 NULL }, FALSE,	/* front_Alternator */
  { NULL,	 NULL }, FALSE,	/* front_NameOrField */
  { NULL,	 NULL }, FALSE,	/* front_AppliedName */
  { NULL,	 NULL }, FALSE,	/* front_AppliedField */
};

static void Retrieve_front_Super (front_Super me)
{ if (me==NULL) return;
  if (front_Super_id(me) != NULL) {
    front_Super_super_bind(me) = RetrieveBind (front_Super_id(me), front_Super_scope(me), front_Super__num(me), front_DefaultNameSpace, Bind_front_NonTerminal_kind);
    front_Super_super(me) = NULL;
    if (front_Super_super_bind(me) != NULL)
      front_Super_super(me) = (front_NonTerminal)Bind_object(front_Super_super_bind(me));
  }
}

static void Retrieve_front_AppliedSym (front_AppliedSym me)
{ if (me==NULL) return;
  if (front_AppliedSym_nt_id(me) != NULL) {
    front_AppliedSym_nt_bind(me) = RetrieveBind (front_AppliedSym_nt_id(me), front_Symbol_scope(me), front_Symbol__num(me), front_DefaultNameSpace, Bind_front_NonTerminal_kind);
    front_AppliedSym_nt(me) = NULL;
    if (front_AppliedSym_nt_bind(me) != NULL)
      front_AppliedSym_nt(me) = (front_NonTerminal)Bind_object(front_AppliedSym_nt_bind(me));
  }
  if (front_AppliedSym_nt_id(me) != NULL) {
    front_AppliedSym_alt_bind(me) = RetrieveBind (front_AppliedSym_nt_id(me), front_Symbol_scope(me), front_Symbol__num(me), front_DefaultNameSpace, Bind_front_Alternative_kind);
    front_AppliedSym_alt(me) = NULL;
    if (front_AppliedSym_alt_bind(me) != NULL)
      front_AppliedSym_alt(me) = (front_Alternative)Bind_object(front_AppliedSym_alt_bind(me));
  }
}

static void Retrieve_front_IdSym (front_IdSym me)
{ if (me==NULL) return;
  if (front_IdSym_id(me) != NULL) {
    front_IdSym_nt_bind(me) = RetrieveBind (front_IdSym_id(me), front_Symbol_scope(me), front_Symbol__num(me), front_DefaultNameSpace, Bind_front_NonTerminal_kind);
    front_IdSym_nt(me) = NULL;
    if (front_IdSym_nt_bind(me) != NULL)
      front_IdSym_nt(me) = (front_NonTerminal)Bind_object(front_IdSym_nt_bind(me));
  }
  if (front_IdSym_id(me) != NULL) {
    front_IdSym_import_bind(me) = RetrieveBind (front_IdSym_id(me), front_Symbol_scope(me), front_Symbol__num(me), front_DefaultNameSpace, Bind_front_ImportedNonTerminal_kind);
    front_IdSym_import(me) = NULL;
    if (front_IdSym_import_bind(me) != NULL)
      front_IdSym_import(me) = (front_ImportedNonTerminal)Bind_object(front_IdSym_import_bind(me));
  }
}

static void Retrieve_front_DefiningSym (front_DefiningSym me)
{ if (me==NULL) return;
  if (front_DefiningSym_ns_id(me) != NULL) {
    front_DefiningSym_ns_bind(me) = RetrieveBind (front_DefiningSym_ns_id(me), front_Symbol_scope(me), front_Symbol__num(me), front_DefaultNameSpace, Bind_front_NameSpace_kind);
    front_DefiningSym_ns(me) = NULL;
    if (front_DefiningSym_ns_bind(me) != NULL)
      front_DefiningSym_ns(me) = (front_NameSpace)Bind_object(front_DefiningSym_ns_bind(me));
  }
}

static void Retrieve_front_Type (front_Type me)
{ if (me==NULL) return;
  if (front_Type_id(me) != NULL) {
    front_Type_nt_bind(me) = RetrieveBind (front_Type_id(me), front_Type_scope(me), front_Type__num(me), front_DefaultNameSpace, Bind_front_NonTerminal_kind);
    front_Type_nt(me) = NULL;
    if (front_Type_nt_bind(me) != NULL)
      front_Type_nt(me) = (front_NonTerminal)Bind_object(front_Type_nt_bind(me));
  }
  if (front_Type_id(me) != NULL) {
    front_Type_import_bind(me) = RetrieveBind (front_Type_id(me), front_Type_scope(me), front_Type__num(me), front_DefaultNameSpace, Bind_front_ImportedNonTerminal_kind);
    front_Type_import(me) = NULL;
    if (front_Type_import_bind(me) != NULL)
      front_Type_import(me) = (front_ImportedNonTerminal)Bind_object(front_Type_import_bind(me));
  }
  if (front_Type_id(me) != NULL) {
    front_Type_alt_bind(me) = RetrieveBind (front_Type_id(me), front_Type_scope(me), front_Type__num(me), front_DefaultNameSpace, Bind_front_Alternative_kind);
    front_Type_alt(me) = NULL;
    if (front_Type_alt_bind(me) != NULL)
      front_Type_alt(me) = (front_Alternative)Bind_object(front_Type_alt_bind(me));
  }
}

struct s_void_front_TraverseTable front_applied_actions = {

  { NULL,	NULL }, FALSE,	/* front_front */
  { NULL,	NULL }, FALSE,	/* front_Import */
  { NULL,	NULL }, FALSE,	/* front_ImportedNonTerminal */
  { NULL,	NULL }, FALSE,	/* front_NonTerminal */
  { NULL,	Retrieve_front_Super }, FALSE,	/* front_Super */
  { NULL,	NULL }, FALSE,	/* front_SubType */
  { NULL,	NULL }, FALSE,	/* front_NoType */
  { NULL,	NULL }, FALSE,	/* front_Rhs */
  { NULL,	NULL }, FALSE,	/* front_Alternative */
  { NULL,	NULL }, FALSE,	/* front_LabeledAlt */
  { NULL,	NULL }, FALSE,	/* front_UnLabeledAlt */
  { NULL,	NULL }, FALSE,	/* front_Symbol */
  { NULL,	NULL }, FALSE,	/* front_LabeledSym */
  { NULL,	NULL }, FALSE,	/* front_AltSymbol */
  { NULL,	NULL }, FALSE,	/* front_SymbolSeq */
  { NULL,	NULL }, FALSE,	/* front_Symbol2 */
  { NULL,	NULL }, FALSE,	/* front_CompareSym */
  { NULL,	NULL }, FALSE,	/* front_SimpleSymbol */
  { NULL,	Retrieve_front_AppliedSym }, FALSE,	/* front_AppliedSym */
  { NULL,	NULL }, FALSE,	/* front_StringSymbol */
  { NULL,	NULL }, FALSE,	/* front_CharSymbol */
  { NULL,	NULL }, FALSE,	/* front_KeywordSymbol */
  { NULL,	NULL }, FALSE,	/* front_CompoundSym */
  { NULL,	NULL }, FALSE,	/* front_OnceSymbol */
  { NULL,	NULL }, FALSE,	/* front_OptSymbol */
  { NULL,	NULL }, FALSE,	/* front_OptMoreSymbol */
  { NULL,	NULL }, FALSE,	/* front_MoreSymbol */
  { NULL,	NULL }, FALSE,	/* front_EmptySym */
  { NULL,	NULL }, FALSE,	/* front_LayoutString */
  { NULL,	NULL }, FALSE,	/* front_LayoutAction */
  { NULL,	Retrieve_front_IdSym }, FALSE,	/* front_IdSym */
  { NULL,	Retrieve_front_DefiningSym }, FALSE,	/* front_DefiningSym */
  { NULL,	NULL }, FALSE,	/* front_Defining_id */
  { NULL,	NULL }, FALSE,	/* front_DefId */
  { NULL,	NULL }, FALSE,	/* front_DefExpr */
  { NULL,	NULL }, FALSE,	/* front_Field */
  { NULL,	NULL }, FALSE,	/* front_FieldInit */
  { NULL,	NULL }, FALSE,	/* front_WhenCreate */
  { NULL,	NULL }, FALSE,	/* front_WhenScope */
  { NULL,	NULL }, FALSE,	/* front_WhenDefining */
  { NULL,	NULL }, FALSE,	/* front_WhenApplied */
  { NULL,	NULL }, FALSE,	/* front_WhenChecks */
  { NULL,	Retrieve_front_Type }, FALSE,	/* front_Type */
  { NULL,	NULL }, FALSE,	/* front_Expr */
  { NULL,	NULL }, FALSE,	/* front_BinExpr */
  { NULL,	NULL }, FALSE,	/* front_MonExpr1 */
  { NULL,	NULL }, FALSE,	/* front_MonExpr */
  { NULL,	NULL }, FALSE,	/* front_SimpleExpr */
  { NULL,	NULL }, FALSE,	/* front_IdentExpr */
  { NULL,	NULL }, FALSE,	/* front_QualExpr */
  { NULL,	NULL }, FALSE,	/* front_IntExpr */
  { NULL,	NULL }, FALSE,	/* front_BoolExpr */
  { NULL,	NULL }, FALSE,	/* front_StringExpr */
  { NULL,	NULL }, FALSE,	/* front_NilExpr */
  { NULL,	NULL }, FALSE,	/* front_CallExpr */
  { NULL,	NULL }, FALSE,	/* front_Check */
  { NULL,	NULL }, FALSE,	/* front_ScanInfo */
  { NULL,	NULL }, FALSE,	/* front_Defines */
  { NULL,	NULL }, FALSE,	/* front_PlainDef */
  { NULL,	NULL }, FALSE,	/* front_MacroDef */
  { NULL,	NULL }, FALSE,	/* front_NameSpace */
  { NULL,	NULL }, FALSE,	/* front_dummy */
  { NULL,	NULL }, FALSE,	/* front_Scope */
  { NULL,	NULL }, FALSE,	/* front_NonTerminalScope */
  { NULL,	NULL }, FALSE,	/* List_List_front_Symbol */
  { NULL,	NULL }, FALSE,	/* List_front_Expr */
  { NULL,	NULL }, FALSE,	/* List_front_Type */
  { NULL,	NULL }, FALSE,	/* List_front_FieldInit */
  { NULL,	NULL }, FALSE,	/* List_front_And */
  { NULL,	NULL }, FALSE,	/* List_front_Field */
  { NULL,	NULL }, FALSE,	/* List_front_Symbol */
  { NULL,	NULL }, FALSE,	/* List_front_Check */
  { NULL,	NULL }, FALSE,	/* List_front_Or */
  { NULL,	NULL }, FALSE,	/* List_front_Alternative */
  { NULL,	NULL }, FALSE,	/* List_front_Scoping */
  { NULL,	NULL }, FALSE,	/* List_front_ImportedNonTerminal */
  { NULL,	NULL }, FALSE,	/* List_front_NonTerminal */
  { NULL,	NULL }, FALSE,	/* List_front_Import */
  { NULL,	NULL }, FALSE,	/* List_front_NameSpace */
  { NULL,	 NULL }, FALSE,	/* front_Scoping */
  { NULL,	 NULL }, FALSE,	/* front_NewScope */
  { NULL,	 NULL }, FALSE,	/* front_OpenScope */
  { NULL,	 NULL }, FALSE,	/* front_CloseScope */
  { NULL,	 NULL }, FALSE,	/* front_And */
  { NULL,	 NULL }, FALSE,	/* front_AndTranspose */
  { NULL,	 NULL }, FALSE,	/* front_AndLeft */
  { NULL,	 NULL }, FALSE,	/* front_AndRight */
  { NULL,	 NULL }, FALSE,	/* front_AndCenter */
  { NULL,	 NULL }, FALSE,	/* front_Or */
  { NULL,	 NULL }, FALSE,	/* front_OrCenter */
  { NULL,	 NULL }, FALSE,	/* front_OrLeft */
  { NULL,	 NULL }, FALSE,	/* front_OrRight */
  { NULL,	 NULL }, FALSE,	/* front_OrTranspose */
  { NULL,	 NULL }, FALSE,	/* front_Define */
  { NULL,	 NULL }, FALSE,	/* front_Defining */
  { NULL,	 NULL }, FALSE,	/* front_Redefining */
  { NULL,	 NULL }, FALSE,	/* front_Overloading */
  { NULL,	 NULL }, FALSE,	/* front_Alternator */
  { NULL,	 NULL }, FALSE,	/* front_NameOrField */
  { NULL,	 NULL }, FALSE,	/* front_AppliedName */
  { NULL,	 NULL }, FALSE,	/* front_AppliedField */
};

static void Check_front_front (front_front me)
{ if (me==NULL) return;
  { if (front_rules (me) == NULL)
    { InputError (front_front_loc(me), FALSE, "");
      FrontMessage ("%s", "Rule(s) expected");
      FrontMessage ("\n");
    }
  }
}

static void Check_front_ImportedNonTerminal (front_ImportedNonTerminal me)
{ if (me==NULL) return;
  if (Bind_double (front_ImportedNonTerminal_id_bind(me))) {
    InputError (front_ImportedNonTerminal_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(front_ImportedNonTerminal_id(me)));
  }
}

static void Check_front_NonTerminal (front_NonTerminal me)
{ if (me==NULL) return;
  if (Bind_double (front_NonTerminal_id_bind(me))) {
    InputError (front_NonTerminal_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(front_NonTerminal_id(me)));
  }
}

static void Check_front_Super (front_Super me)
{ if (me==NULL) return;
  { if (Super_super (me) == NULL && ! TermType (Super_id (me)))
    { InputError (front_Super_loc(me), FALSE, "");
      FrontMessage ("%s", "Super-type not declared");
      FrontMessage ("\n");
    }
  }
}

static void Check_front_LabeledAlt (front_LabeledAlt me)
{ if (me==NULL) return;
  if (Bind_double (front_LabeledAlt_id_bind(me))) {
    InputError (front_Alternative_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(front_LabeledAlt_id(me)));
  }
}

static void Check_front_AppliedSym (front_AppliedSym me)
{ if (me==NULL) return;
}

static void Check_front_IdSym (front_IdSym me)
{ if (me==NULL) return;
}

static void Check_front_DefiningSym (front_DefiningSym me)
{ if (me==NULL) return;
  if (front_DefiningSym_ns_bind(me) == NULL && front_DefiningSym_ns_id(me) != NULL) {
    InputError (front_Symbol_loc(me), TRUE, "Identifier '%s' not declared", Ident_name(front_DefiningSym_ns_id(me)));
  }
}

static void Check_front_Type (front_Type me)
{ if (me==NULL) return;
}

static void Check_front_NameSpace (front_NameSpace me)
{ if (me==NULL) return;
  if (Bind_double (front_NameSpace_id_bind(me))) {
    InputError (front_NameSpace_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(front_NameSpace_id(me)));
  }
}

struct s_void_front_TraverseTable front_check_actions = {

  { NULL,	Check_front_front }, FALSE,	/* front_front */
  { NULL,	NULL }, FALSE,	/* front_Import */
  { NULL,	Check_front_ImportedNonTerminal }, FALSE,	/* front_ImportedNonTerminal */
  { NULL,	Check_front_NonTerminal }, FALSE,	/* front_NonTerminal */
  { NULL,	Check_front_Super }, FALSE,	/* front_Super */
  { NULL,	NULL }, FALSE,	/* front_SubType */
  { NULL,	NULL }, FALSE,	/* front_NoType */
  { NULL,	NULL }, FALSE,	/* front_Rhs */
  { NULL,	NULL }, FALSE,	/* front_Alternative */
  { NULL,	Check_front_LabeledAlt }, FALSE,	/* front_LabeledAlt */
  { NULL,	NULL }, FALSE,	/* front_UnLabeledAlt */
  { NULL,	NULL }, FALSE,	/* front_Symbol */
  { NULL,	NULL }, FALSE,	/* front_LabeledSym */
  { NULL,	NULL }, FALSE,	/* front_AltSymbol */
  { NULL,	NULL }, FALSE,	/* front_SymbolSeq */
  { NULL,	NULL }, FALSE,	/* front_Symbol2 */
  { NULL,	NULL }, FALSE,	/* front_CompareSym */
  { NULL,	NULL }, FALSE,	/* front_SimpleSymbol */
  { NULL,	Check_front_AppliedSym }, FALSE,	/* front_AppliedSym */
  { NULL,	NULL }, FALSE,	/* front_StringSymbol */
  { NULL,	NULL }, FALSE,	/* front_CharSymbol */
  { NULL,	NULL }, FALSE,	/* front_KeywordSymbol */
  { NULL,	NULL }, FALSE,	/* front_CompoundSym */
  { NULL,	NULL }, FALSE,	/* front_OnceSymbol */
  { NULL,	NULL }, FALSE,	/* front_OptSymbol */
  { NULL,	NULL }, FALSE,	/* front_OptMoreSymbol */
  { NULL,	NULL }, FALSE,	/* front_MoreSymbol */
  { NULL,	NULL }, FALSE,	/* front_EmptySym */
  { NULL,	NULL }, FALSE,	/* front_LayoutString */
  { NULL,	NULL }, FALSE,	/* front_LayoutAction */
  { NULL,	Check_front_IdSym }, FALSE,	/* front_IdSym */
  { NULL,	Check_front_DefiningSym }, FALSE,	/* front_DefiningSym */
  { NULL,	NULL }, FALSE,	/* front_Defining_id */
  { NULL,	NULL }, FALSE,	/* front_DefId */
  { NULL,	NULL }, FALSE,	/* front_DefExpr */
  { NULL,	NULL }, FALSE,	/* front_Field */
  { NULL,	NULL }, FALSE,	/* front_FieldInit */
  { NULL,	NULL }, FALSE,	/* front_WhenCreate */
  { NULL,	NULL }, FALSE,	/* front_WhenScope */
  { NULL,	NULL }, FALSE,	/* front_WhenDefining */
  { NULL,	NULL }, FALSE,	/* front_WhenApplied */
  { NULL,	NULL }, FALSE,	/* front_WhenChecks */
  { NULL,	Check_front_Type }, FALSE,	/* front_Type */
  { NULL,	NULL }, FALSE,	/* front_Expr */
  { NULL,	NULL }, FALSE,	/* front_BinExpr */
  { NULL,	NULL }, FALSE,	/* front_MonExpr1 */
  { NULL,	NULL }, FALSE,	/* front_MonExpr */
  { NULL,	NULL }, FALSE,	/* front_SimpleExpr */
  { NULL,	NULL }, FALSE,	/* front_IdentExpr */
  { NULL,	NULL }, FALSE,	/* front_QualExpr */
  { NULL,	NULL }, FALSE,	/* front_IntExpr */
  { NULL,	NULL }, FALSE,	/* front_BoolExpr */
  { NULL,	NULL }, FALSE,	/* front_StringExpr */
  { NULL,	NULL }, FALSE,	/* front_NilExpr */
  { NULL,	NULL }, FALSE,	/* front_CallExpr */
  { NULL,	NULL }, FALSE,	/* front_Check */
  { NULL,	NULL }, FALSE,	/* front_ScanInfo */
  { NULL,	NULL }, FALSE,	/* front_Defines */
  { NULL,	NULL }, FALSE,	/* front_PlainDef */
  { NULL,	NULL }, FALSE,	/* front_MacroDef */
  { NULL,	Check_front_NameSpace }, FALSE,	/* front_NameSpace */
  { NULL,	NULL }, FALSE,	/* front_dummy */
  { NULL,	NULL }, FALSE,	/* front_Scope */
  { NULL,	NULL }, FALSE,	/* front_NonTerminalScope */
  { NULL,	NULL }, FALSE,	/* List_List_front_Symbol */
  { NULL,	NULL }, FALSE,	/* List_front_Expr */
  { NULL,	NULL }, FALSE,	/* List_front_Type */
  { NULL,	NULL }, FALSE,	/* List_front_FieldInit */
  { NULL,	NULL }, FALSE,	/* List_front_And */
  { NULL,	NULL }, FALSE,	/* List_front_Field */
  { NULL,	NULL }, FALSE,	/* List_front_Symbol */
  { NULL,	NULL }, FALSE,	/* List_front_Check */
  { NULL,	NULL }, FALSE,	/* List_front_Or */
  { NULL,	NULL }, FALSE,	/* List_front_Alternative */
  { NULL,	NULL }, FALSE,	/* List_front_Scoping */
  { NULL,	NULL }, FALSE,	/* List_front_ImportedNonTerminal */
  { NULL,	NULL }, FALSE,	/* List_front_NonTerminal */
  { NULL,	NULL }, FALSE,	/* List_front_Import */
  { NULL,	NULL }, FALSE,	/* List_front_NameSpace */
  { NULL,	 NULL }, FALSE,	/* front_Scoping */
  { NULL,	 NULL }, FALSE,	/* front_NewScope */
  { NULL,	 NULL }, FALSE,	/* front_OpenScope */
  { NULL,	 NULL }, FALSE,	/* front_CloseScope */
  { NULL,	 NULL }, FALSE,	/* front_And */
  { NULL,	 NULL }, FALSE,	/* front_AndTranspose */
  { NULL,	 NULL }, FALSE,	/* front_AndLeft */
  { NULL,	 NULL }, FALSE,	/* front_AndRight */
  { NULL,	 NULL }, FALSE,	/* front_AndCenter */
  { NULL,	 NULL }, FALSE,	/* front_Or */
  { NULL,	 NULL }, FALSE,	/* front_OrCenter */
  { NULL,	 NULL }, FALSE,	/* front_OrLeft */
  { NULL,	 NULL }, FALSE,	/* front_OrRight */
  { NULL,	 NULL }, FALSE,	/* front_OrTranspose */
  { NULL,	 NULL }, FALSE,	/* front_Define */
  { NULL,	 NULL }, FALSE,	/* front_Defining */
  { NULL,	 NULL }, FALSE,	/* front_Redefining */
  { NULL,	 NULL }, FALSE,	/* front_Overloading */
  { NULL,	 NULL }, FALSE,	/* front_Alternator */
  { NULL,	 NULL }, FALSE,	/* front_NameOrField */
  { NULL,	 NULL }, FALSE,	/* front_AppliedName */
  { NULL,	 NULL }, FALSE,	/* front_AppliedField */
};

struct s_void_front_TraverseTable front_print_actions;

struct s_copy_front_TraverseTable front_copy_actions;

struct s_compare_front_TraverseTable front_compare_actions;

void front_fill_table (front_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_front[PRE_ACTION] = (void* (*) (front_front, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_front[POST_ACTION] = (void* (*) (front_front, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Import[PRE_ACTION] = (void* (*) (front_Import, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Import[POST_ACTION] = (void* (*) (front_Import, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ImportedNonTerminal[PRE_ACTION] = (void* (*) (front_ImportedNonTerminal, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ImportedNonTerminal[POST_ACTION] = (void* (*) (front_ImportedNonTerminal, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NonTerminal[PRE_ACTION] = (void* (*) (front_NonTerminal, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NonTerminal[POST_ACTION] = (void* (*) (front_NonTerminal, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Super[PRE_ACTION] = (void* (*) (front_Super, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Super[POST_ACTION] = (void* (*) (front_Super, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubType[PRE_ACTION] = (void* (*) (front_SubType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubType[POST_ACTION] = (void* (*) (front_SubType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NoType[PRE_ACTION] = (void* (*) (front_NoType, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NoType[POST_ACTION] = (void* (*) (front_NoType, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rhs[PRE_ACTION] = (void* (*) (front_Rhs, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rhs[POST_ACTION] = (void* (*) (front_Rhs, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Alternative[PRE_ACTION] = (void* (*) (front_Alternative, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Alternative[POST_ACTION] = (void* (*) (front_Alternative, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledAlt[PRE_ACTION] = (void* (*) (front_LabeledAlt, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledAlt[POST_ACTION] = (void* (*) (front_LabeledAlt, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnLabeledAlt[PRE_ACTION] = (void* (*) (front_UnLabeledAlt, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnLabeledAlt[POST_ACTION] = (void* (*) (front_UnLabeledAlt, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Symbol[PRE_ACTION] = (void* (*) (front_Symbol, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Symbol[POST_ACTION] = (void* (*) (front_Symbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledSym[PRE_ACTION] = (void* (*) (front_LabeledSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledSym[POST_ACTION] = (void* (*) (front_LabeledSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltSymbol[PRE_ACTION] = (void* (*) (front_AltSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltSymbol[POST_ACTION] = (void* (*) (front_AltSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SymbolSeq[PRE_ACTION] = (void* (*) (front_SymbolSeq, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SymbolSeq[POST_ACTION] = (void* (*) (front_SymbolSeq, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Symbol2[PRE_ACTION] = (void* (*) (front_Symbol2, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Symbol2[POST_ACTION] = (void* (*) (front_Symbol2, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CompareSym[PRE_ACTION] = (void* (*) (front_CompareSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CompareSym[POST_ACTION] = (void* (*) (front_CompareSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleSymbol[PRE_ACTION] = (void* (*) (front_SimpleSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleSymbol[POST_ACTION] = (void* (*) (front_SimpleSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedSym[PRE_ACTION] = (void* (*) (front_AppliedSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedSym[POST_ACTION] = (void* (*) (front_AppliedSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringSymbol[PRE_ACTION] = (void* (*) (front_StringSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringSymbol[POST_ACTION] = (void* (*) (front_StringSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CharSymbol[PRE_ACTION] = (void* (*) (front_CharSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CharSymbol[POST_ACTION] = (void* (*) (front_CharSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_KeywordSymbol[PRE_ACTION] = (void* (*) (front_KeywordSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_KeywordSymbol[POST_ACTION] = (void* (*) (front_KeywordSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CompoundSym[PRE_ACTION] = (void* (*) (front_CompoundSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CompoundSym[POST_ACTION] = (void* (*) (front_CompoundSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OnceSymbol[PRE_ACTION] = (void* (*) (front_OnceSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OnceSymbol[POST_ACTION] = (void* (*) (front_OnceSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptSymbol[PRE_ACTION] = (void* (*) (front_OptSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptSymbol[POST_ACTION] = (void* (*) (front_OptSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptMoreSymbol[PRE_ACTION] = (void* (*) (front_OptMoreSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptMoreSymbol[POST_ACTION] = (void* (*) (front_OptMoreSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MoreSymbol[PRE_ACTION] = (void* (*) (front_MoreSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MoreSymbol[POST_ACTION] = (void* (*) (front_MoreSymbol, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EmptySym[PRE_ACTION] = (void* (*) (front_EmptySym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EmptySym[POST_ACTION] = (void* (*) (front_EmptySym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LayoutString[PRE_ACTION] = (void* (*) (front_LayoutString, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LayoutString[POST_ACTION] = (void* (*) (front_LayoutString, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LayoutAction[PRE_ACTION] = (void* (*) (front_LayoutAction, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LayoutAction[POST_ACTION] = (void* (*) (front_LayoutAction, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdSym[PRE_ACTION] = (void* (*) (front_IdSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdSym[POST_ACTION] = (void* (*) (front_IdSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefiningSym[PRE_ACTION] = (void* (*) (front_DefiningSym, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefiningSym[POST_ACTION] = (void* (*) (front_DefiningSym, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defining_id[PRE_ACTION] = (void* (*) (front_Defining_id, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defining_id[POST_ACTION] = (void* (*) (front_Defining_id, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefId[PRE_ACTION] = (void* (*) (front_DefId, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefId[POST_ACTION] = (void* (*) (front_DefId, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefExpr[PRE_ACTION] = (void* (*) (front_DefExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefExpr[POST_ACTION] = (void* (*) (front_DefExpr, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Field[PRE_ACTION] = (void* (*) (front_Field, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Field[POST_ACTION] = (void* (*) (front_Field, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FieldInit[PRE_ACTION] = (void* (*) (front_FieldInit, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FieldInit[POST_ACTION] = (void* (*) (front_FieldInit, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenCreate[PRE_ACTION] = (void* (*) (front_WhenCreate, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenCreate[POST_ACTION] = (void* (*) (front_WhenCreate, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenScope[PRE_ACTION] = (void* (*) (front_WhenScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenScope[POST_ACTION] = (void* (*) (front_WhenScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenDefining[PRE_ACTION] = (void* (*) (front_WhenDefining, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenDefining[POST_ACTION] = (void* (*) (front_WhenDefining, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenApplied[PRE_ACTION] = (void* (*) (front_WhenApplied, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenApplied[POST_ACTION] = (void* (*) (front_WhenApplied, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenChecks[PRE_ACTION] = (void* (*) (front_WhenChecks, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenChecks[POST_ACTION] = (void* (*) (front_WhenChecks, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Type[PRE_ACTION] = (void* (*) (front_Type, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Type[POST_ACTION] = (void* (*) (front_Type, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expr[PRE_ACTION] = (void* (*) (front_Expr, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expr[POST_ACTION] = (void* (*) (front_Expr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BinExpr[PRE_ACTION] = (void* (*) (front_BinExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BinExpr[POST_ACTION] = (void* (*) (front_BinExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr1[PRE_ACTION] = (void* (*) (front_MonExpr1, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr1[POST_ACTION] = (void* (*) (front_MonExpr1, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr[PRE_ACTION] = (void* (*) (front_MonExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr[POST_ACTION] = (void* (*) (front_MonExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleExpr[PRE_ACTION] = (void* (*) (front_SimpleExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleExpr[POST_ACTION] = (void* (*) (front_SimpleExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentExpr[PRE_ACTION] = (void* (*) (front_IdentExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentExpr[POST_ACTION] = (void* (*) (front_IdentExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_QualExpr[PRE_ACTION] = (void* (*) (front_QualExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_QualExpr[POST_ACTION] = (void* (*) (front_QualExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntExpr[PRE_ACTION] = (void* (*) (front_IntExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntExpr[POST_ACTION] = (void* (*) (front_IntExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BoolExpr[PRE_ACTION] = (void* (*) (front_BoolExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BoolExpr[POST_ACTION] = (void* (*) (front_BoolExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringExpr[PRE_ACTION] = (void* (*) (front_StringExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringExpr[POST_ACTION] = (void* (*) (front_StringExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NilExpr[PRE_ACTION] = (void* (*) (front_NilExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NilExpr[POST_ACTION] = (void* (*) (front_NilExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CallExpr[PRE_ACTION] = (void* (*) (front_CallExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CallExpr[POST_ACTION] = (void* (*) (front_CallExpr, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Check[PRE_ACTION] = (void* (*) (front_Check, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Check[POST_ACTION] = (void* (*) (front_Check, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ScanInfo[PRE_ACTION] = (void* (*) (front_ScanInfo, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ScanInfo[POST_ACTION] = (void* (*) (front_ScanInfo, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defines[PRE_ACTION] = (void* (*) (front_Defines, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defines[POST_ACTION] = (void* (*) (front_Defines, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlainDef[PRE_ACTION] = (void* (*) (front_PlainDef, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlainDef[POST_ACTION] = (void* (*) (front_PlainDef, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MacroDef[PRE_ACTION] = (void* (*) (front_MacroDef, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MacroDef[POST_ACTION] = (void* (*) (front_MacroDef, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NameSpace[PRE_ACTION] = (void* (*) (front_NameSpace, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NameSpace[POST_ACTION] = (void* (*) (front_NameSpace, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_dummy[PRE_ACTION] = (void* (*) (front_dummy, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_dummy[POST_ACTION] = (void* (*) (front_dummy, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void* (*) (front_Scope, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void* (*) (front_Scope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NonTerminalScope[PRE_ACTION] = (void* (*) (front_NonTerminalScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NonTerminalScope[POST_ACTION] = (void* (*) (front_NonTerminalScope, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_Symbol[PRE_ACTION] = (void* (*) (List_List_front_Symbol, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_Symbol[POST_ACTION] = (void* (*) (List_List_front_Symbol, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expr[PRE_ACTION] = (void* (*) (List_front_Expr, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expr[POST_ACTION] = (void* (*) (List_front_Expr, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Type[PRE_ACTION] = (void* (*) (List_front_Type, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Type[POST_ACTION] = (void* (*) (List_front_Type, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FieldInit[PRE_ACTION] = (void* (*) (List_front_FieldInit, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FieldInit[POST_ACTION] = (void* (*) (List_front_FieldInit, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_And[PRE_ACTION] = (void* (*) (List_front_And, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_And[POST_ACTION] = (void* (*) (List_front_And, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Field[PRE_ACTION] = (void* (*) (List_front_Field, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Field[POST_ACTION] = (void* (*) (List_front_Field, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Symbol[PRE_ACTION] = (void* (*) (List_front_Symbol, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Symbol[POST_ACTION] = (void* (*) (List_front_Symbol, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Check[PRE_ACTION] = (void* (*) (List_front_Check, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Check[POST_ACTION] = (void* (*) (List_front_Check, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Or[PRE_ACTION] = (void* (*) (List_front_Or, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Or[POST_ACTION] = (void* (*) (List_front_Or, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Alternative[PRE_ACTION] = (void* (*) (List_front_Alternative, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Alternative[POST_ACTION] = (void* (*) (List_front_Alternative, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Scoping[PRE_ACTION] = (void* (*) (List_front_Scoping, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Scoping[POST_ACTION] = (void* (*) (List_front_Scoping, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ImportedNonTerminal[PRE_ACTION] = (void* (*) (List_front_ImportedNonTerminal, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ImportedNonTerminal[POST_ACTION] = (void* (*) (List_front_ImportedNonTerminal, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_NonTerminal[PRE_ACTION] = (void* (*) (List_front_NonTerminal, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_NonTerminal[POST_ACTION] = (void* (*) (List_front_NonTerminal, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Import[PRE_ACTION] = (void* (*) (List_front_Import, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Import[POST_ACTION] = (void* (*) (List_front_Import, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_NameSpace[PRE_ACTION] = (void* (*) (List_front_NameSpace, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_NameSpace[POST_ACTION] = (void* (*) (List_front_NameSpace, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scoping[PRE_ACTION] = (void* (*) (front_Scoping, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scoping[POST_ACTION] = (void* (*) (front_Scoping, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NewScope[PRE_ACTION] = (void* (*) (front_Scoping, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NewScope[POST_ACTION] = (void* (*) (front_Scoping, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpenScope[PRE_ACTION] = (void* (*) (front_Scoping, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpenScope[POST_ACTION] = (void* (*) (front_Scoping, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CloseScope[PRE_ACTION] = (void* (*) (front_Scoping, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CloseScope[POST_ACTION] = (void* (*) (front_Scoping, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_And[PRE_ACTION] = (void* (*) (front_And, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_And[POST_ACTION] = (void* (*) (front_And, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndTranspose[PRE_ACTION] = (void* (*) (front_And, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndTranspose[POST_ACTION] = (void* (*) (front_And, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndLeft[PRE_ACTION] = (void* (*) (front_And, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndLeft[POST_ACTION] = (void* (*) (front_And, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndRight[PRE_ACTION] = (void* (*) (front_And, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndRight[POST_ACTION] = (void* (*) (front_And, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndCenter[PRE_ACTION] = (void* (*) (front_And, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndCenter[POST_ACTION] = (void* (*) (front_And, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Or[PRE_ACTION] = (void* (*) (front_Or, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Or[POST_ACTION] = (void* (*) (front_Or, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrCenter[PRE_ACTION] = (void* (*) (front_Or, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrCenter[POST_ACTION] = (void* (*) (front_Or, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrLeft[PRE_ACTION] = (void* (*) (front_Or, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrLeft[POST_ACTION] = (void* (*) (front_Or, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrRight[PRE_ACTION] = (void* (*) (front_Or, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrRight[POST_ACTION] = (void* (*) (front_Or, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrTranspose[PRE_ACTION] = (void* (*) (front_Or, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrTranspose[POST_ACTION] = (void* (*) (front_Or, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Define[PRE_ACTION] = (void* (*) (front_Define, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Define[POST_ACTION] = (void* (*) (front_Define, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defining[PRE_ACTION] = (void* (*) (front_Define, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defining[POST_ACTION] = (void* (*) (front_Define, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Redefining[PRE_ACTION] = (void* (*) (front_Define, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Redefining[POST_ACTION] = (void* (*) (front_Define, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Overloading[PRE_ACTION] = (void* (*) (front_Define, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Overloading[POST_ACTION] = (void* (*) (front_Define, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Alternator[PRE_ACTION] = (void* (*) (front_Alternator, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Alternator[POST_ACTION] = (void* (*) (front_Alternator, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NameOrField[PRE_ACTION] = (void* (*) (front_NameOrField, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NameOrField[POST_ACTION] = (void* (*) (front_NameOrField, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedName[PRE_ACTION] = (void* (*) (front_NameOrField, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedName[POST_ACTION] = (void* (*) (front_NameOrField, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedField[PRE_ACTION] = (void* (*) (front_NameOrField, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedField[POST_ACTION] = (void* (*) (front_NameOrField, void*))x;
}

void void_front_fill_table (void_front_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_front[PRE_ACTION] = (void (*) (front_front))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_front[POST_ACTION] = (void (*) (front_front))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Import[PRE_ACTION] = (void (*) (front_Import))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Import[POST_ACTION] = (void (*) (front_Import))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ImportedNonTerminal[PRE_ACTION] = (void (*) (front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ImportedNonTerminal[POST_ACTION] = (void (*) (front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NonTerminal[PRE_ACTION] = (void (*) (front_NonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NonTerminal[POST_ACTION] = (void (*) (front_NonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Super[PRE_ACTION] = (void (*) (front_Super))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Super[POST_ACTION] = (void (*) (front_Super))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubType[PRE_ACTION] = (void (*) (front_SubType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubType[POST_ACTION] = (void (*) (front_SubType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NoType[PRE_ACTION] = (void (*) (front_NoType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NoType[POST_ACTION] = (void (*) (front_NoType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rhs[PRE_ACTION] = (void (*) (front_Rhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rhs[POST_ACTION] = (void (*) (front_Rhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Alternative[PRE_ACTION] = (void (*) (front_Alternative))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Alternative[POST_ACTION] = (void (*) (front_Alternative))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledAlt[PRE_ACTION] = (void (*) (front_LabeledAlt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledAlt[POST_ACTION] = (void (*) (front_LabeledAlt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnLabeledAlt[PRE_ACTION] = (void (*) (front_UnLabeledAlt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnLabeledAlt[POST_ACTION] = (void (*) (front_UnLabeledAlt))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Symbol[PRE_ACTION] = (void (*) (front_Symbol))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Symbol[POST_ACTION] = (void (*) (front_Symbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledSym[PRE_ACTION] = (void (*) (front_LabeledSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledSym[POST_ACTION] = (void (*) (front_LabeledSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltSymbol[PRE_ACTION] = (void (*) (front_AltSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltSymbol[POST_ACTION] = (void (*) (front_AltSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SymbolSeq[PRE_ACTION] = (void (*) (front_SymbolSeq))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SymbolSeq[POST_ACTION] = (void (*) (front_SymbolSeq))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Symbol2[PRE_ACTION] = (void (*) (front_Symbol2))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Symbol2[POST_ACTION] = (void (*) (front_Symbol2))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CompareSym[PRE_ACTION] = (void (*) (front_CompareSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CompareSym[POST_ACTION] = (void (*) (front_CompareSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleSymbol[PRE_ACTION] = (void (*) (front_SimpleSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleSymbol[POST_ACTION] = (void (*) (front_SimpleSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedSym[PRE_ACTION] = (void (*) (front_AppliedSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedSym[POST_ACTION] = (void (*) (front_AppliedSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringSymbol[PRE_ACTION] = (void (*) (front_StringSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringSymbol[POST_ACTION] = (void (*) (front_StringSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CharSymbol[PRE_ACTION] = (void (*) (front_CharSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CharSymbol[POST_ACTION] = (void (*) (front_CharSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_KeywordSymbol[PRE_ACTION] = (void (*) (front_KeywordSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_KeywordSymbol[POST_ACTION] = (void (*) (front_KeywordSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CompoundSym[PRE_ACTION] = (void (*) (front_CompoundSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CompoundSym[POST_ACTION] = (void (*) (front_CompoundSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OnceSymbol[PRE_ACTION] = (void (*) (front_OnceSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OnceSymbol[POST_ACTION] = (void (*) (front_OnceSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptSymbol[PRE_ACTION] = (void (*) (front_OptSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptSymbol[POST_ACTION] = (void (*) (front_OptSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptMoreSymbol[PRE_ACTION] = (void (*) (front_OptMoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptMoreSymbol[POST_ACTION] = (void (*) (front_OptMoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MoreSymbol[PRE_ACTION] = (void (*) (front_MoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MoreSymbol[POST_ACTION] = (void (*) (front_MoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EmptySym[PRE_ACTION] = (void (*) (front_EmptySym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EmptySym[POST_ACTION] = (void (*) (front_EmptySym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LayoutString[PRE_ACTION] = (void (*) (front_LayoutString))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LayoutString[POST_ACTION] = (void (*) (front_LayoutString))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LayoutAction[PRE_ACTION] = (void (*) (front_LayoutAction))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LayoutAction[POST_ACTION] = (void (*) (front_LayoutAction))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdSym[PRE_ACTION] = (void (*) (front_IdSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdSym[POST_ACTION] = (void (*) (front_IdSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefiningSym[PRE_ACTION] = (void (*) (front_DefiningSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefiningSym[POST_ACTION] = (void (*) (front_DefiningSym))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defining_id[PRE_ACTION] = (void (*) (front_Defining_id))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defining_id[POST_ACTION] = (void (*) (front_Defining_id))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefId[PRE_ACTION] = (void (*) (front_DefId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefId[POST_ACTION] = (void (*) (front_DefId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefExpr[PRE_ACTION] = (void (*) (front_DefExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefExpr[POST_ACTION] = (void (*) (front_DefExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Field[PRE_ACTION] = (void (*) (front_Field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Field[POST_ACTION] = (void (*) (front_Field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FieldInit[PRE_ACTION] = (void (*) (front_FieldInit))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FieldInit[POST_ACTION] = (void (*) (front_FieldInit))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenCreate[PRE_ACTION] = (void (*) (front_WhenCreate))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenCreate[POST_ACTION] = (void (*) (front_WhenCreate))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenScope[PRE_ACTION] = (void (*) (front_WhenScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenScope[POST_ACTION] = (void (*) (front_WhenScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenDefining[PRE_ACTION] = (void (*) (front_WhenDefining))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenDefining[POST_ACTION] = (void (*) (front_WhenDefining))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenApplied[PRE_ACTION] = (void (*) (front_WhenApplied))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenApplied[POST_ACTION] = (void (*) (front_WhenApplied))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenChecks[PRE_ACTION] = (void (*) (front_WhenChecks))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenChecks[POST_ACTION] = (void (*) (front_WhenChecks))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Type[PRE_ACTION] = (void (*) (front_Type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Type[POST_ACTION] = (void (*) (front_Type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expr[PRE_ACTION] = (void (*) (front_Expr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expr[POST_ACTION] = (void (*) (front_Expr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BinExpr[PRE_ACTION] = (void (*) (front_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BinExpr[POST_ACTION] = (void (*) (front_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr1[PRE_ACTION] = (void (*) (front_MonExpr1))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr1[POST_ACTION] = (void (*) (front_MonExpr1))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr[PRE_ACTION] = (void (*) (front_MonExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr[POST_ACTION] = (void (*) (front_MonExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleExpr[PRE_ACTION] = (void (*) (front_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleExpr[POST_ACTION] = (void (*) (front_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentExpr[PRE_ACTION] = (void (*) (front_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentExpr[POST_ACTION] = (void (*) (front_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_QualExpr[PRE_ACTION] = (void (*) (front_QualExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_QualExpr[POST_ACTION] = (void (*) (front_QualExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntExpr[PRE_ACTION] = (void (*) (front_IntExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntExpr[POST_ACTION] = (void (*) (front_IntExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BoolExpr[PRE_ACTION] = (void (*) (front_BoolExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BoolExpr[POST_ACTION] = (void (*) (front_BoolExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringExpr[PRE_ACTION] = (void (*) (front_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringExpr[POST_ACTION] = (void (*) (front_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NilExpr[PRE_ACTION] = (void (*) (front_NilExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NilExpr[POST_ACTION] = (void (*) (front_NilExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CallExpr[PRE_ACTION] = (void (*) (front_CallExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CallExpr[POST_ACTION] = (void (*) (front_CallExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Check[PRE_ACTION] = (void (*) (front_Check))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Check[POST_ACTION] = (void (*) (front_Check))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ScanInfo[PRE_ACTION] = (void (*) (front_ScanInfo))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ScanInfo[POST_ACTION] = (void (*) (front_ScanInfo))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defines[PRE_ACTION] = (void (*) (front_Defines))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defines[POST_ACTION] = (void (*) (front_Defines))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlainDef[PRE_ACTION] = (void (*) (front_PlainDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlainDef[POST_ACTION] = (void (*) (front_PlainDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MacroDef[PRE_ACTION] = (void (*) (front_MacroDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MacroDef[POST_ACTION] = (void (*) (front_MacroDef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NameSpace[PRE_ACTION] = (void (*) (front_NameSpace))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NameSpace[POST_ACTION] = (void (*) (front_NameSpace))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_dummy[PRE_ACTION] = (void (*) (front_dummy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_dummy[POST_ACTION] = (void (*) (front_dummy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void (*) (front_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void (*) (front_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NonTerminalScope[PRE_ACTION] = (void (*) (front_NonTerminalScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NonTerminalScope[POST_ACTION] = (void (*) (front_NonTerminalScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_Symbol[PRE_ACTION] = (void (*) (List_List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_Symbol[POST_ACTION] = (void (*) (List_List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expr[PRE_ACTION] = (void (*) (List_front_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expr[POST_ACTION] = (void (*) (List_front_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Type[PRE_ACTION] = (void (*) (List_front_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Type[POST_ACTION] = (void (*) (List_front_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FieldInit[PRE_ACTION] = (void (*) (List_front_FieldInit))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FieldInit[POST_ACTION] = (void (*) (List_front_FieldInit))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_And[PRE_ACTION] = (void (*) (List_front_And))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_And[POST_ACTION] = (void (*) (List_front_And))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Field[PRE_ACTION] = (void (*) (List_front_Field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Field[POST_ACTION] = (void (*) (List_front_Field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Symbol[PRE_ACTION] = (void (*) (List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Symbol[POST_ACTION] = (void (*) (List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Check[PRE_ACTION] = (void (*) (List_front_Check))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Check[POST_ACTION] = (void (*) (List_front_Check))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Or[PRE_ACTION] = (void (*) (List_front_Or))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Or[POST_ACTION] = (void (*) (List_front_Or))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Alternative[PRE_ACTION] = (void (*) (List_front_Alternative))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Alternative[POST_ACTION] = (void (*) (List_front_Alternative))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Scoping[PRE_ACTION] = (void (*) (List_front_Scoping))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Scoping[POST_ACTION] = (void (*) (List_front_Scoping))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ImportedNonTerminal[PRE_ACTION] = (void (*) (List_front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ImportedNonTerminal[POST_ACTION] = (void (*) (List_front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_NonTerminal[PRE_ACTION] = (void (*) (List_front_NonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_NonTerminal[POST_ACTION] = (void (*) (List_front_NonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Import[PRE_ACTION] = (void (*) (List_front_Import))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Import[POST_ACTION] = (void (*) (List_front_Import))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_NameSpace[PRE_ACTION] = (void (*) (List_front_NameSpace))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_NameSpace[POST_ACTION] = (void (*) (List_front_NameSpace))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scoping[PRE_ACTION] = (void (*) (front_Scoping))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scoping[POST_ACTION] = (void (*) (front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NewScope[PRE_ACTION] = (void (*) (front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NewScope[POST_ACTION] = (void (*) (front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpenScope[PRE_ACTION] = (void (*) (front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpenScope[POST_ACTION] = (void (*) (front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CloseScope[PRE_ACTION] = (void (*) (front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CloseScope[POST_ACTION] = (void (*) (front_Scoping))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_And[PRE_ACTION] = (void (*) (front_And))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_And[POST_ACTION] = (void (*) (front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndTranspose[PRE_ACTION] = (void (*) (front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndTranspose[POST_ACTION] = (void (*) (front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndLeft[PRE_ACTION] = (void (*) (front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndLeft[POST_ACTION] = (void (*) (front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndRight[PRE_ACTION] = (void (*) (front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndRight[POST_ACTION] = (void (*) (front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndCenter[PRE_ACTION] = (void (*) (front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndCenter[POST_ACTION] = (void (*) (front_And))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Or[PRE_ACTION] = (void (*) (front_Or))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Or[POST_ACTION] = (void (*) (front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrCenter[PRE_ACTION] = (void (*) (front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrCenter[POST_ACTION] = (void (*) (front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrLeft[PRE_ACTION] = (void (*) (front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrLeft[POST_ACTION] = (void (*) (front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrRight[PRE_ACTION] = (void (*) (front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrRight[POST_ACTION] = (void (*) (front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrTranspose[PRE_ACTION] = (void (*) (front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrTranspose[POST_ACTION] = (void (*) (front_Or))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Define[PRE_ACTION] = (void (*) (front_Define))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Define[POST_ACTION] = (void (*) (front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defining[PRE_ACTION] = (void (*) (front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defining[POST_ACTION] = (void (*) (front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Redefining[PRE_ACTION] = (void (*) (front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Redefining[POST_ACTION] = (void (*) (front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Overloading[PRE_ACTION] = (void (*) (front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Overloading[POST_ACTION] = (void (*) (front_Define))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Alternator[PRE_ACTION] = (void (*) (front_Alternator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Alternator[POST_ACTION] = (void (*) (front_Alternator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NameOrField[PRE_ACTION] = (void (*) (front_NameOrField))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NameOrField[POST_ACTION] = (void (*) (front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedName[PRE_ACTION] = (void (*) (front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedName[POST_ACTION] = (void (*) (front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedField[PRE_ACTION] = (void (*) (front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedField[POST_ACTION] = (void (*) (front_NameOrField))x;
}

void copy_front_fill_table (copy_front_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_front[PRE_ACTION] = (front_front (*) (front_front, front_front))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_front[POST_ACTION] = (front_front (*) (front_front, front_front))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Import[PRE_ACTION] = (front_Import (*) (front_Import, front_Import))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Import[POST_ACTION] = (front_Import (*) (front_Import, front_Import))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ImportedNonTerminal[PRE_ACTION] = (front_ImportedNonTerminal (*) (front_ImportedNonTerminal, front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ImportedNonTerminal[POST_ACTION] = (front_ImportedNonTerminal (*) (front_ImportedNonTerminal, front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NonTerminal[PRE_ACTION] = (front_NonTerminal (*) (front_NonTerminal, front_NonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NonTerminal[POST_ACTION] = (front_NonTerminal (*) (front_NonTerminal, front_NonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Super[PRE_ACTION] = (front_Super (*) (front_Super, front_Super))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Super[POST_ACTION] = (front_Super (*) (front_Super, front_Super))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubType[PRE_ACTION] = (front_SubType (*) (front_SubType, front_SubType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubType[POST_ACTION] = (front_SubType (*) (front_SubType, front_SubType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NoType[PRE_ACTION] = (front_NoType (*) (front_NoType, front_NoType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NoType[POST_ACTION] = (front_NoType (*) (front_NoType, front_NoType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rhs[PRE_ACTION] = (front_Rhs (*) (front_Rhs, front_Rhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rhs[POST_ACTION] = (front_Rhs (*) (front_Rhs, front_Rhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Alternative[PRE_ACTION] = (front_Alternative (*) (front_Alternative, front_Alternative))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Alternative[POST_ACTION] = (front_Alternative (*) (front_Alternative, front_Alternative))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledAlt[PRE_ACTION] = (front_LabeledAlt (*) (front_LabeledAlt, front_LabeledAlt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledAlt[POST_ACTION] = (front_LabeledAlt (*) (front_LabeledAlt, front_LabeledAlt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnLabeledAlt[PRE_ACTION] = (front_UnLabeledAlt (*) (front_UnLabeledAlt, front_UnLabeledAlt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnLabeledAlt[POST_ACTION] = (front_UnLabeledAlt (*) (front_UnLabeledAlt, front_UnLabeledAlt))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Symbol[PRE_ACTION] = (front_Symbol (*) (front_Symbol, front_Symbol))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Symbol[POST_ACTION] = (front_Symbol (*) (front_Symbol, front_Symbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledSym[PRE_ACTION] = (front_LabeledSym (*) (front_LabeledSym, front_LabeledSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledSym[POST_ACTION] = (front_LabeledSym (*) (front_LabeledSym, front_LabeledSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltSymbol[PRE_ACTION] = (front_AltSymbol (*) (front_AltSymbol, front_AltSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltSymbol[POST_ACTION] = (front_AltSymbol (*) (front_AltSymbol, front_AltSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SymbolSeq[PRE_ACTION] = (front_SymbolSeq (*) (front_SymbolSeq, front_SymbolSeq))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SymbolSeq[POST_ACTION] = (front_SymbolSeq (*) (front_SymbolSeq, front_SymbolSeq))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Symbol2[PRE_ACTION] = (front_Symbol2 (*) (front_Symbol2, front_Symbol2))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Symbol2[POST_ACTION] = (front_Symbol2 (*) (front_Symbol2, front_Symbol2))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CompareSym[PRE_ACTION] = (front_CompareSym (*) (front_CompareSym, front_CompareSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CompareSym[POST_ACTION] = (front_CompareSym (*) (front_CompareSym, front_CompareSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleSymbol[PRE_ACTION] = (front_SimpleSymbol (*) (front_SimpleSymbol, front_SimpleSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleSymbol[POST_ACTION] = (front_SimpleSymbol (*) (front_SimpleSymbol, front_SimpleSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedSym[PRE_ACTION] = (front_AppliedSym (*) (front_AppliedSym, front_AppliedSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedSym[POST_ACTION] = (front_AppliedSym (*) (front_AppliedSym, front_AppliedSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringSymbol[PRE_ACTION] = (front_StringSymbol (*) (front_StringSymbol, front_StringSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringSymbol[POST_ACTION] = (front_StringSymbol (*) (front_StringSymbol, front_StringSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CharSymbol[PRE_ACTION] = (front_CharSymbol (*) (front_CharSymbol, front_CharSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CharSymbol[POST_ACTION] = (front_CharSymbol (*) (front_CharSymbol, front_CharSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_KeywordSymbol[PRE_ACTION] = (front_KeywordSymbol (*) (front_KeywordSymbol, front_KeywordSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_KeywordSymbol[POST_ACTION] = (front_KeywordSymbol (*) (front_KeywordSymbol, front_KeywordSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CompoundSym[PRE_ACTION] = (front_CompoundSym (*) (front_CompoundSym, front_CompoundSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CompoundSym[POST_ACTION] = (front_CompoundSym (*) (front_CompoundSym, front_CompoundSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OnceSymbol[PRE_ACTION] = (front_OnceSymbol (*) (front_OnceSymbol, front_OnceSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OnceSymbol[POST_ACTION] = (front_OnceSymbol (*) (front_OnceSymbol, front_OnceSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptSymbol[PRE_ACTION] = (front_OptSymbol (*) (front_OptSymbol, front_OptSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptSymbol[POST_ACTION] = (front_OptSymbol (*) (front_OptSymbol, front_OptSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptMoreSymbol[PRE_ACTION] = (front_OptMoreSymbol (*) (front_OptMoreSymbol, front_OptMoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptMoreSymbol[POST_ACTION] = (front_OptMoreSymbol (*) (front_OptMoreSymbol, front_OptMoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MoreSymbol[PRE_ACTION] = (front_MoreSymbol (*) (front_MoreSymbol, front_MoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MoreSymbol[POST_ACTION] = (front_MoreSymbol (*) (front_MoreSymbol, front_MoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EmptySym[PRE_ACTION] = (front_EmptySym (*) (front_EmptySym, front_EmptySym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EmptySym[POST_ACTION] = (front_EmptySym (*) (front_EmptySym, front_EmptySym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LayoutString[PRE_ACTION] = (front_LayoutString (*) (front_LayoutString, front_LayoutString))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LayoutString[POST_ACTION] = (front_LayoutString (*) (front_LayoutString, front_LayoutString))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LayoutAction[PRE_ACTION] = (front_LayoutAction (*) (front_LayoutAction, front_LayoutAction))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LayoutAction[POST_ACTION] = (front_LayoutAction (*) (front_LayoutAction, front_LayoutAction))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdSym[PRE_ACTION] = (front_IdSym (*) (front_IdSym, front_IdSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdSym[POST_ACTION] = (front_IdSym (*) (front_IdSym, front_IdSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefiningSym[PRE_ACTION] = (front_DefiningSym (*) (front_DefiningSym, front_DefiningSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefiningSym[POST_ACTION] = (front_DefiningSym (*) (front_DefiningSym, front_DefiningSym))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defining_id[PRE_ACTION] = (front_Defining_id (*) (front_Defining_id, front_Defining_id))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defining_id[POST_ACTION] = (front_Defining_id (*) (front_Defining_id, front_Defining_id))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefId[PRE_ACTION] = (front_DefId (*) (front_DefId, front_DefId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefId[POST_ACTION] = (front_DefId (*) (front_DefId, front_DefId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefExpr[PRE_ACTION] = (front_DefExpr (*) (front_DefExpr, front_DefExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefExpr[POST_ACTION] = (front_DefExpr (*) (front_DefExpr, front_DefExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Field[PRE_ACTION] = (front_Field (*) (front_Field, front_Field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Field[POST_ACTION] = (front_Field (*) (front_Field, front_Field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FieldInit[PRE_ACTION] = (front_FieldInit (*) (front_FieldInit, front_FieldInit))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FieldInit[POST_ACTION] = (front_FieldInit (*) (front_FieldInit, front_FieldInit))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenCreate[PRE_ACTION] = (front_WhenCreate (*) (front_WhenCreate, front_WhenCreate))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenCreate[POST_ACTION] = (front_WhenCreate (*) (front_WhenCreate, front_WhenCreate))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenScope[PRE_ACTION] = (front_WhenScope (*) (front_WhenScope, front_WhenScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenScope[POST_ACTION] = (front_WhenScope (*) (front_WhenScope, front_WhenScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenDefining[PRE_ACTION] = (front_WhenDefining (*) (front_WhenDefining, front_WhenDefining))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenDefining[POST_ACTION] = (front_WhenDefining (*) (front_WhenDefining, front_WhenDefining))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenApplied[PRE_ACTION] = (front_WhenApplied (*) (front_WhenApplied, front_WhenApplied))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenApplied[POST_ACTION] = (front_WhenApplied (*) (front_WhenApplied, front_WhenApplied))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenChecks[PRE_ACTION] = (front_WhenChecks (*) (front_WhenChecks, front_WhenChecks))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenChecks[POST_ACTION] = (front_WhenChecks (*) (front_WhenChecks, front_WhenChecks))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Type[PRE_ACTION] = (front_Type (*) (front_Type, front_Type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Type[POST_ACTION] = (front_Type (*) (front_Type, front_Type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expr[PRE_ACTION] = (front_Expr (*) (front_Expr, front_Expr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expr[POST_ACTION] = (front_Expr (*) (front_Expr, front_Expr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BinExpr[PRE_ACTION] = (front_BinExpr (*) (front_BinExpr, front_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BinExpr[POST_ACTION] = (front_BinExpr (*) (front_BinExpr, front_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr1[PRE_ACTION] = (front_MonExpr1 (*) (front_MonExpr1, front_MonExpr1))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr1[POST_ACTION] = (front_MonExpr1 (*) (front_MonExpr1, front_MonExpr1))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr[PRE_ACTION] = (front_MonExpr (*) (front_MonExpr, front_MonExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr[POST_ACTION] = (front_MonExpr (*) (front_MonExpr, front_MonExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleExpr[PRE_ACTION] = (front_SimpleExpr (*) (front_SimpleExpr, front_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleExpr[POST_ACTION] = (front_SimpleExpr (*) (front_SimpleExpr, front_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentExpr[PRE_ACTION] = (front_IdentExpr (*) (front_IdentExpr, front_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentExpr[POST_ACTION] = (front_IdentExpr (*) (front_IdentExpr, front_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_QualExpr[PRE_ACTION] = (front_QualExpr (*) (front_QualExpr, front_QualExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_QualExpr[POST_ACTION] = (front_QualExpr (*) (front_QualExpr, front_QualExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntExpr[PRE_ACTION] = (front_IntExpr (*) (front_IntExpr, front_IntExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntExpr[POST_ACTION] = (front_IntExpr (*) (front_IntExpr, front_IntExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BoolExpr[PRE_ACTION] = (front_BoolExpr (*) (front_BoolExpr, front_BoolExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BoolExpr[POST_ACTION] = (front_BoolExpr (*) (front_BoolExpr, front_BoolExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringExpr[PRE_ACTION] = (front_StringExpr (*) (front_StringExpr, front_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringExpr[POST_ACTION] = (front_StringExpr (*) (front_StringExpr, front_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NilExpr[PRE_ACTION] = (front_NilExpr (*) (front_NilExpr, front_NilExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NilExpr[POST_ACTION] = (front_NilExpr (*) (front_NilExpr, front_NilExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CallExpr[PRE_ACTION] = (front_CallExpr (*) (front_CallExpr, front_CallExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CallExpr[POST_ACTION] = (front_CallExpr (*) (front_CallExpr, front_CallExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Check[PRE_ACTION] = (front_Check (*) (front_Check, front_Check))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Check[POST_ACTION] = (front_Check (*) (front_Check, front_Check))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ScanInfo[PRE_ACTION] = (front_ScanInfo (*) (front_ScanInfo, front_ScanInfo))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ScanInfo[POST_ACTION] = (front_ScanInfo (*) (front_ScanInfo, front_ScanInfo))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defines[PRE_ACTION] = (front_Defines (*) (front_Defines, front_Defines))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defines[POST_ACTION] = (front_Defines (*) (front_Defines, front_Defines))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlainDef[PRE_ACTION] = (front_PlainDef (*) (front_PlainDef, front_PlainDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlainDef[POST_ACTION] = (front_PlainDef (*) (front_PlainDef, front_PlainDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MacroDef[PRE_ACTION] = (front_MacroDef (*) (front_MacroDef, front_MacroDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MacroDef[POST_ACTION] = (front_MacroDef (*) (front_MacroDef, front_MacroDef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NameSpace[PRE_ACTION] = (front_NameSpace (*) (front_NameSpace, front_NameSpace))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NameSpace[POST_ACTION] = (front_NameSpace (*) (front_NameSpace, front_NameSpace))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_dummy[PRE_ACTION] = (front_dummy (*) (front_dummy, front_dummy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_dummy[POST_ACTION] = (front_dummy (*) (front_dummy, front_dummy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (front_Scope (*) (front_Scope, front_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (front_Scope (*) (front_Scope, front_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NonTerminalScope[PRE_ACTION] = (front_NonTerminalScope (*) (front_NonTerminalScope, front_NonTerminalScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NonTerminalScope[POST_ACTION] = (front_NonTerminalScope (*) (front_NonTerminalScope, front_NonTerminalScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_Symbol[PRE_ACTION] = (List_List_front_Symbol (*) (List_List_front_Symbol, List_List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_Symbol[POST_ACTION] = (List_List_front_Symbol (*) (List_List_front_Symbol, List_List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expr[PRE_ACTION] = (List_front_Expr (*) (List_front_Expr, List_front_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expr[POST_ACTION] = (List_front_Expr (*) (List_front_Expr, List_front_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Type[PRE_ACTION] = (List_front_Type (*) (List_front_Type, List_front_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Type[POST_ACTION] = (List_front_Type (*) (List_front_Type, List_front_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FieldInit[PRE_ACTION] = (List_front_FieldInit (*) (List_front_FieldInit, List_front_FieldInit))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FieldInit[POST_ACTION] = (List_front_FieldInit (*) (List_front_FieldInit, List_front_FieldInit))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_And[PRE_ACTION] = (List_front_And (*) (List_front_And, List_front_And))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_And[POST_ACTION] = (List_front_And (*) (List_front_And, List_front_And))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Field[PRE_ACTION] = (List_front_Field (*) (List_front_Field, List_front_Field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Field[POST_ACTION] = (List_front_Field (*) (List_front_Field, List_front_Field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Symbol[PRE_ACTION] = (List_front_Symbol (*) (List_front_Symbol, List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Symbol[POST_ACTION] = (List_front_Symbol (*) (List_front_Symbol, List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Check[PRE_ACTION] = (List_front_Check (*) (List_front_Check, List_front_Check))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Check[POST_ACTION] = (List_front_Check (*) (List_front_Check, List_front_Check))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Or[PRE_ACTION] = (List_front_Or (*) (List_front_Or, List_front_Or))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Or[POST_ACTION] = (List_front_Or (*) (List_front_Or, List_front_Or))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Alternative[PRE_ACTION] = (List_front_Alternative (*) (List_front_Alternative, List_front_Alternative))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Alternative[POST_ACTION] = (List_front_Alternative (*) (List_front_Alternative, List_front_Alternative))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Scoping[PRE_ACTION] = (List_front_Scoping (*) (List_front_Scoping, List_front_Scoping))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Scoping[POST_ACTION] = (List_front_Scoping (*) (List_front_Scoping, List_front_Scoping))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ImportedNonTerminal[PRE_ACTION] = (List_front_ImportedNonTerminal (*) (List_front_ImportedNonTerminal, List_front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ImportedNonTerminal[POST_ACTION] = (List_front_ImportedNonTerminal (*) (List_front_ImportedNonTerminal, List_front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_NonTerminal[PRE_ACTION] = (List_front_NonTerminal (*) (List_front_NonTerminal, List_front_NonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_NonTerminal[POST_ACTION] = (List_front_NonTerminal (*) (List_front_NonTerminal, List_front_NonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Import[PRE_ACTION] = (List_front_Import (*) (List_front_Import, List_front_Import))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Import[POST_ACTION] = (List_front_Import (*) (List_front_Import, List_front_Import))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_NameSpace[PRE_ACTION] = (List_front_NameSpace (*) (List_front_NameSpace, List_front_NameSpace))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_NameSpace[POST_ACTION] = (List_front_NameSpace (*) (List_front_NameSpace, List_front_NameSpace))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scoping[PRE_ACTION] = (front_Scoping (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scoping[POST_ACTION] = (front_Scoping (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NewScope[PRE_ACTION] = (front_Scoping (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NewScope[POST_ACTION] = (front_Scoping (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpenScope[PRE_ACTION] = (front_Scoping (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpenScope[POST_ACTION] = (front_Scoping (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CloseScope[PRE_ACTION] = (front_Scoping (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CloseScope[POST_ACTION] = (front_Scoping (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_And[PRE_ACTION] = (front_And (*) (front_And, front_And))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_And[POST_ACTION] = (front_And (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndTranspose[PRE_ACTION] = (front_And (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndTranspose[POST_ACTION] = (front_And (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndLeft[PRE_ACTION] = (front_And (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndLeft[POST_ACTION] = (front_And (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndRight[PRE_ACTION] = (front_And (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndRight[POST_ACTION] = (front_And (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndCenter[PRE_ACTION] = (front_And (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndCenter[POST_ACTION] = (front_And (*) (front_And, front_And))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Or[PRE_ACTION] = (front_Or (*) (front_Or, front_Or))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Or[POST_ACTION] = (front_Or (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrCenter[PRE_ACTION] = (front_Or (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrCenter[POST_ACTION] = (front_Or (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrLeft[PRE_ACTION] = (front_Or (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrLeft[POST_ACTION] = (front_Or (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrRight[PRE_ACTION] = (front_Or (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrRight[POST_ACTION] = (front_Or (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrTranspose[PRE_ACTION] = (front_Or (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrTranspose[POST_ACTION] = (front_Or (*) (front_Or, front_Or))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Define[PRE_ACTION] = (front_Define (*) (front_Define, front_Define))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Define[POST_ACTION] = (front_Define (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defining[PRE_ACTION] = (front_Define (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defining[POST_ACTION] = (front_Define (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Redefining[PRE_ACTION] = (front_Define (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Redefining[POST_ACTION] = (front_Define (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Overloading[PRE_ACTION] = (front_Define (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Overloading[POST_ACTION] = (front_Define (*) (front_Define, front_Define))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Alternator[PRE_ACTION] = (front_Alternator (*) (front_Alternator, front_Alternator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Alternator[POST_ACTION] = (front_Alternator (*) (front_Alternator, front_Alternator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NameOrField[PRE_ACTION] = (front_NameOrField (*) (front_NameOrField, front_NameOrField))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NameOrField[POST_ACTION] = (front_NameOrField (*) (front_NameOrField, front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedName[PRE_ACTION] = (front_NameOrField (*) (front_NameOrField, front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedName[POST_ACTION] = (front_NameOrField (*) (front_NameOrField, front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedField[PRE_ACTION] = (front_NameOrField (*) (front_NameOrField, front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedField[POST_ACTION] = (front_NameOrField (*) (front_NameOrField, front_NameOrField))x;
}

void compare_front_fill_table (compare_front_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_front[PRE_ACTION] = (int (*) (front_front, front_front))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_front[POST_ACTION] = (int (*) (front_front, front_front))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Import[PRE_ACTION] = (int (*) (front_Import, front_Import))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Import[POST_ACTION] = (int (*) (front_Import, front_Import))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ImportedNonTerminal[PRE_ACTION] = (int (*) (front_ImportedNonTerminal, front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ImportedNonTerminal[POST_ACTION] = (int (*) (front_ImportedNonTerminal, front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NonTerminal[PRE_ACTION] = (int (*) (front_NonTerminal, front_NonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NonTerminal[POST_ACTION] = (int (*) (front_NonTerminal, front_NonTerminal))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Super[PRE_ACTION] = (int (*) (front_Super, front_Super))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Super[POST_ACTION] = (int (*) (front_Super, front_Super))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubType[PRE_ACTION] = (int (*) (front_SubType, front_SubType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubType[POST_ACTION] = (int (*) (front_SubType, front_SubType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NoType[PRE_ACTION] = (int (*) (front_NoType, front_NoType))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NoType[POST_ACTION] = (int (*) (front_NoType, front_NoType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Rhs[PRE_ACTION] = (int (*) (front_Rhs, front_Rhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Rhs[POST_ACTION] = (int (*) (front_Rhs, front_Rhs))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Alternative[PRE_ACTION] = (int (*) (front_Alternative, front_Alternative))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Alternative[POST_ACTION] = (int (*) (front_Alternative, front_Alternative))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledAlt[PRE_ACTION] = (int (*) (front_LabeledAlt, front_LabeledAlt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledAlt[POST_ACTION] = (int (*) (front_LabeledAlt, front_LabeledAlt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_UnLabeledAlt[PRE_ACTION] = (int (*) (front_UnLabeledAlt, front_UnLabeledAlt))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_UnLabeledAlt[POST_ACTION] = (int (*) (front_UnLabeledAlt, front_UnLabeledAlt))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Symbol[PRE_ACTION] = (int (*) (front_Symbol, front_Symbol))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Symbol[POST_ACTION] = (int (*) (front_Symbol, front_Symbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LabeledSym[PRE_ACTION] = (int (*) (front_LabeledSym, front_LabeledSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LabeledSym[POST_ACTION] = (int (*) (front_LabeledSym, front_LabeledSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltSymbol[PRE_ACTION] = (int (*) (front_AltSymbol, front_AltSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltSymbol[POST_ACTION] = (int (*) (front_AltSymbol, front_AltSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SymbolSeq[PRE_ACTION] = (int (*) (front_SymbolSeq, front_SymbolSeq))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SymbolSeq[POST_ACTION] = (int (*) (front_SymbolSeq, front_SymbolSeq))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Symbol2[PRE_ACTION] = (int (*) (front_Symbol2, front_Symbol2))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Symbol2[POST_ACTION] = (int (*) (front_Symbol2, front_Symbol2))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CompareSym[PRE_ACTION] = (int (*) (front_CompareSym, front_CompareSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CompareSym[POST_ACTION] = (int (*) (front_CompareSym, front_CompareSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleSymbol[PRE_ACTION] = (int (*) (front_SimpleSymbol, front_SimpleSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleSymbol[POST_ACTION] = (int (*) (front_SimpleSymbol, front_SimpleSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedSym[PRE_ACTION] = (int (*) (front_AppliedSym, front_AppliedSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedSym[POST_ACTION] = (int (*) (front_AppliedSym, front_AppliedSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringSymbol[PRE_ACTION] = (int (*) (front_StringSymbol, front_StringSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringSymbol[POST_ACTION] = (int (*) (front_StringSymbol, front_StringSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CharSymbol[PRE_ACTION] = (int (*) (front_CharSymbol, front_CharSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CharSymbol[POST_ACTION] = (int (*) (front_CharSymbol, front_CharSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_KeywordSymbol[PRE_ACTION] = (int (*) (front_KeywordSymbol, front_KeywordSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_KeywordSymbol[POST_ACTION] = (int (*) (front_KeywordSymbol, front_KeywordSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CompoundSym[PRE_ACTION] = (int (*) (front_CompoundSym, front_CompoundSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CompoundSym[POST_ACTION] = (int (*) (front_CompoundSym, front_CompoundSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OnceSymbol[PRE_ACTION] = (int (*) (front_OnceSymbol, front_OnceSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OnceSymbol[POST_ACTION] = (int (*) (front_OnceSymbol, front_OnceSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptSymbol[PRE_ACTION] = (int (*) (front_OptSymbol, front_OptSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptSymbol[POST_ACTION] = (int (*) (front_OptSymbol, front_OptSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptMoreSymbol[PRE_ACTION] = (int (*) (front_OptMoreSymbol, front_OptMoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptMoreSymbol[POST_ACTION] = (int (*) (front_OptMoreSymbol, front_OptMoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MoreSymbol[PRE_ACTION] = (int (*) (front_MoreSymbol, front_MoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MoreSymbol[POST_ACTION] = (int (*) (front_MoreSymbol, front_MoreSymbol))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EmptySym[PRE_ACTION] = (int (*) (front_EmptySym, front_EmptySym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EmptySym[POST_ACTION] = (int (*) (front_EmptySym, front_EmptySym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LayoutString[PRE_ACTION] = (int (*) (front_LayoutString, front_LayoutString))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LayoutString[POST_ACTION] = (int (*) (front_LayoutString, front_LayoutString))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_LayoutAction[PRE_ACTION] = (int (*) (front_LayoutAction, front_LayoutAction))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_LayoutAction[POST_ACTION] = (int (*) (front_LayoutAction, front_LayoutAction))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdSym[PRE_ACTION] = (int (*) (front_IdSym, front_IdSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdSym[POST_ACTION] = (int (*) (front_IdSym, front_IdSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefiningSym[PRE_ACTION] = (int (*) (front_DefiningSym, front_DefiningSym))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefiningSym[POST_ACTION] = (int (*) (front_DefiningSym, front_DefiningSym))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defining_id[PRE_ACTION] = (int (*) (front_Defining_id, front_Defining_id))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defining_id[POST_ACTION] = (int (*) (front_Defining_id, front_Defining_id))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefId[PRE_ACTION] = (int (*) (front_DefId, front_DefId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefId[POST_ACTION] = (int (*) (front_DefId, front_DefId))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DefExpr[PRE_ACTION] = (int (*) (front_DefExpr, front_DefExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DefExpr[POST_ACTION] = (int (*) (front_DefExpr, front_DefExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Field[PRE_ACTION] = (int (*) (front_Field, front_Field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Field[POST_ACTION] = (int (*) (front_Field, front_Field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_FieldInit[PRE_ACTION] = (int (*) (front_FieldInit, front_FieldInit))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_FieldInit[POST_ACTION] = (int (*) (front_FieldInit, front_FieldInit))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenCreate[PRE_ACTION] = (int (*) (front_WhenCreate, front_WhenCreate))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenCreate[POST_ACTION] = (int (*) (front_WhenCreate, front_WhenCreate))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenScope[PRE_ACTION] = (int (*) (front_WhenScope, front_WhenScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenScope[POST_ACTION] = (int (*) (front_WhenScope, front_WhenScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenDefining[PRE_ACTION] = (int (*) (front_WhenDefining, front_WhenDefining))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenDefining[POST_ACTION] = (int (*) (front_WhenDefining, front_WhenDefining))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenApplied[PRE_ACTION] = (int (*) (front_WhenApplied, front_WhenApplied))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenApplied[POST_ACTION] = (int (*) (front_WhenApplied, front_WhenApplied))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WhenChecks[PRE_ACTION] = (int (*) (front_WhenChecks, front_WhenChecks))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WhenChecks[POST_ACTION] = (int (*) (front_WhenChecks, front_WhenChecks))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Type[PRE_ACTION] = (int (*) (front_Type, front_Type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Type[POST_ACTION] = (int (*) (front_Type, front_Type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expr[PRE_ACTION] = (int (*) (front_Expr, front_Expr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expr[POST_ACTION] = (int (*) (front_Expr, front_Expr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BinExpr[PRE_ACTION] = (int (*) (front_BinExpr, front_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BinExpr[POST_ACTION] = (int (*) (front_BinExpr, front_BinExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr1[PRE_ACTION] = (int (*) (front_MonExpr1, front_MonExpr1))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr1[POST_ACTION] = (int (*) (front_MonExpr1, front_MonExpr1))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MonExpr[PRE_ACTION] = (int (*) (front_MonExpr, front_MonExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MonExpr[POST_ACTION] = (int (*) (front_MonExpr, front_MonExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SimpleExpr[PRE_ACTION] = (int (*) (front_SimpleExpr, front_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SimpleExpr[POST_ACTION] = (int (*) (front_SimpleExpr, front_SimpleExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdentExpr[PRE_ACTION] = (int (*) (front_IdentExpr, front_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdentExpr[POST_ACTION] = (int (*) (front_IdentExpr, front_IdentExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_QualExpr[PRE_ACTION] = (int (*) (front_QualExpr, front_QualExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_QualExpr[POST_ACTION] = (int (*) (front_QualExpr, front_QualExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IntExpr[PRE_ACTION] = (int (*) (front_IntExpr, front_IntExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IntExpr[POST_ACTION] = (int (*) (front_IntExpr, front_IntExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BoolExpr[PRE_ACTION] = (int (*) (front_BoolExpr, front_BoolExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BoolExpr[POST_ACTION] = (int (*) (front_BoolExpr, front_BoolExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringExpr[PRE_ACTION] = (int (*) (front_StringExpr, front_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringExpr[POST_ACTION] = (int (*) (front_StringExpr, front_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NilExpr[PRE_ACTION] = (int (*) (front_NilExpr, front_NilExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NilExpr[POST_ACTION] = (int (*) (front_NilExpr, front_NilExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CallExpr[PRE_ACTION] = (int (*) (front_CallExpr, front_CallExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CallExpr[POST_ACTION] = (int (*) (front_CallExpr, front_CallExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Check[PRE_ACTION] = (int (*) (front_Check, front_Check))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Check[POST_ACTION] = (int (*) (front_Check, front_Check))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ScanInfo[PRE_ACTION] = (int (*) (front_ScanInfo, front_ScanInfo))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ScanInfo[POST_ACTION] = (int (*) (front_ScanInfo, front_ScanInfo))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defines[PRE_ACTION] = (int (*) (front_Defines, front_Defines))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defines[POST_ACTION] = (int (*) (front_Defines, front_Defines))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlainDef[PRE_ACTION] = (int (*) (front_PlainDef, front_PlainDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlainDef[POST_ACTION] = (int (*) (front_PlainDef, front_PlainDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MacroDef[PRE_ACTION] = (int (*) (front_MacroDef, front_MacroDef))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MacroDef[POST_ACTION] = (int (*) (front_MacroDef, front_MacroDef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NameSpace[PRE_ACTION] = (int (*) (front_NameSpace, front_NameSpace))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NameSpace[POST_ACTION] = (int (*) (front_NameSpace, front_NameSpace))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_dummy[PRE_ACTION] = (int (*) (front_dummy, front_dummy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_dummy[POST_ACTION] = (int (*) (front_dummy, front_dummy))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (int (*) (front_Scope, front_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (int (*) (front_Scope, front_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NonTerminalScope[PRE_ACTION] = (int (*) (front_NonTerminalScope, front_NonTerminalScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NonTerminalScope[POST_ACTION] = (int (*) (front_NonTerminalScope, front_NonTerminalScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_List_Symbol[PRE_ACTION] = (int (*) (List_List_front_Symbol, List_List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_List_Symbol[POST_ACTION] = (int (*) (List_List_front_Symbol, List_List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expr[PRE_ACTION] = (int (*) (List_front_Expr, List_front_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expr[POST_ACTION] = (int (*) (List_front_Expr, List_front_Expr))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Type[PRE_ACTION] = (int (*) (List_front_Type, List_front_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Type[POST_ACTION] = (int (*) (List_front_Type, List_front_Type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_FieldInit[PRE_ACTION] = (int (*) (List_front_FieldInit, List_front_FieldInit))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_FieldInit[POST_ACTION] = (int (*) (List_front_FieldInit, List_front_FieldInit))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_And[PRE_ACTION] = (int (*) (List_front_And, List_front_And))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_And[POST_ACTION] = (int (*) (List_front_And, List_front_And))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Field[PRE_ACTION] = (int (*) (List_front_Field, List_front_Field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Field[POST_ACTION] = (int (*) (List_front_Field, List_front_Field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Symbol[PRE_ACTION] = (int (*) (List_front_Symbol, List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Symbol[POST_ACTION] = (int (*) (List_front_Symbol, List_front_Symbol))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Check[PRE_ACTION] = (int (*) (List_front_Check, List_front_Check))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Check[POST_ACTION] = (int (*) (List_front_Check, List_front_Check))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Or[PRE_ACTION] = (int (*) (List_front_Or, List_front_Or))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Or[POST_ACTION] = (int (*) (List_front_Or, List_front_Or))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Alternative[PRE_ACTION] = (int (*) (List_front_Alternative, List_front_Alternative))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Alternative[POST_ACTION] = (int (*) (List_front_Alternative, List_front_Alternative))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Scoping[PRE_ACTION] = (int (*) (List_front_Scoping, List_front_Scoping))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Scoping[POST_ACTION] = (int (*) (List_front_Scoping, List_front_Scoping))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ImportedNonTerminal[PRE_ACTION] = (int (*) (List_front_ImportedNonTerminal, List_front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ImportedNonTerminal[POST_ACTION] = (int (*) (List_front_ImportedNonTerminal, List_front_ImportedNonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_NonTerminal[PRE_ACTION] = (int (*) (List_front_NonTerminal, List_front_NonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_NonTerminal[POST_ACTION] = (int (*) (List_front_NonTerminal, List_front_NonTerminal))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Import[PRE_ACTION] = (int (*) (List_front_Import, List_front_Import))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Import[POST_ACTION] = (int (*) (List_front_Import, List_front_Import))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_NameSpace[PRE_ACTION] = (int (*) (List_front_NameSpace, List_front_NameSpace))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_NameSpace[POST_ACTION] = (int (*) (List_front_NameSpace, List_front_NameSpace))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scoping[PRE_ACTION] = (int (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scoping[POST_ACTION] = (int (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NewScope[PRE_ACTION] = (int (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NewScope[POST_ACTION] = (int (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OpenScope[PRE_ACTION] = (int (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OpenScope[POST_ACTION] = (int (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CloseScope[PRE_ACTION] = (int (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CloseScope[POST_ACTION] = (int (*) (front_Scoping, front_Scoping))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_And[PRE_ACTION] = (int (*) (front_And, front_And))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_And[POST_ACTION] = (int (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndTranspose[PRE_ACTION] = (int (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndTranspose[POST_ACTION] = (int (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndLeft[PRE_ACTION] = (int (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndLeft[POST_ACTION] = (int (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndRight[PRE_ACTION] = (int (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndRight[POST_ACTION] = (int (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndCenter[PRE_ACTION] = (int (*) (front_And, front_And))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndCenter[POST_ACTION] = (int (*) (front_And, front_And))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Or[PRE_ACTION] = (int (*) (front_Or, front_Or))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Or[POST_ACTION] = (int (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrCenter[PRE_ACTION] = (int (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrCenter[POST_ACTION] = (int (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrLeft[PRE_ACTION] = (int (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrLeft[POST_ACTION] = (int (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrRight[PRE_ACTION] = (int (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrRight[POST_ACTION] = (int (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrTranspose[PRE_ACTION] = (int (*) (front_Or, front_Or))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrTranspose[POST_ACTION] = (int (*) (front_Or, front_Or))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Define[PRE_ACTION] = (int (*) (front_Define, front_Define))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Define[POST_ACTION] = (int (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Defining[PRE_ACTION] = (int (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Defining[POST_ACTION] = (int (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Redefining[PRE_ACTION] = (int (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Redefining[POST_ACTION] = (int (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Overloading[PRE_ACTION] = (int (*) (front_Define, front_Define))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Overloading[POST_ACTION] = (int (*) (front_Define, front_Define))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Alternator[PRE_ACTION] = (int (*) (front_Alternator, front_Alternator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Alternator[POST_ACTION] = (int (*) (front_Alternator, front_Alternator))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NameOrField[PRE_ACTION] = (int (*) (front_NameOrField, front_NameOrField))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NameOrField[POST_ACTION] = (int (*) (front_NameOrField, front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedName[PRE_ACTION] = (int (*) (front_NameOrField, front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedName[POST_ACTION] = (int (*) (front_NameOrField, front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AppliedField[PRE_ACTION] = (int (*) (front_NameOrField, front_NameOrField))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AppliedField[POST_ACTION] = (int (*) (front_NameOrField, front_NameOrField))x;
}

front_NameSpaces front_namespaces[] = { -1 };

void Decorate_front (front_front r)
{
  if (front_namespaces[0]<0) Extend_namespaces (front_NUM_NAMESPACES, front_namespaces);
  front_root = r;
  if (NoDecorate) return;
  Traverse_front_front (r, &front_scope_actions, NULL);
  Traverse_void_front_front (r, &front_defining_actions);
  Traverse_void_front_front (r, &front_applied_actions);
  Traverse_void_front_front (r, &front_check_actions);
}
