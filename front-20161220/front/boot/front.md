#include "front_defs.h"
front_front (List_Ident, List_front_NameSpace, List_front_Import, List_front_NonTerminal) : front_front		front_front_kind
front_Import (Ident, List_front_ImportedNonTerminal) : front_Import		front_Import_kind
front_ImportedNonTerminal (Ident, Ident) : front_ImportedNonTerminal		front_ImportedNonTerminal_kind
front_NonTerminal (Bool, front_ScanInfo, Ident, front_Super, Bool, Bool, Bool, front_Defines, front_Rhs) : front_NonTerminal		front_NonTerminal_kind
front_NoType (Ident) : front_Super		front_NoType_kind
front_SubType (Ident, Ident) : front_Super		front_SubType_kind
front_Rhs (List_front_Scoping, front_Symbol, Ident, List_front_Alternative, List_front_Or, Ident, front_Symbol, List_front_Check) : front_Rhs		front_Rhs_kind
front_UnLabeledAlt (front_Symbol) : front_Alternative		front_UnLabeledAlt_kind
front_LabeledAlt (Ident, Bool, Bool, Ident, front_Rhs) : front_Alternative		front_LabeledAlt_kind
front_DefiningSym (Bool, front_Define, front_Defining_id, Ident, front_Expr) : front_Symbol		front_DefiningSym_kind
front_IdSym (Ident, front_Type) : front_Symbol		front_IdSym_kind
front_LayoutAction (front_Expr) : front_Symbol		front_LayoutAction_kind
front_LayoutString (String) : front_Symbol		front_LayoutString_kind
front_EmptySym () : front_Symbol		front_EmptySym_kind
front_MoreSymbol (List_front_Symbol, List_front_Or, Ident) : front_Symbol		front_MoreSymbol_kind
front_OptMoreSymbol (List_front_Symbol, List_front_Or) : front_Symbol		front_OptMoreSymbol_kind
front_OptSymbol (List_front_Symbol, List_front_Or, Bool) : front_Symbol		front_OptSymbol_kind
front_OnceSymbol (List_front_Symbol, List_front_Or) : front_Symbol		front_OnceSymbol_kind
front_KeywordSymbol (String, front_Type) : front_Symbol		front_KeywordSymbol_kind
front_CharSymbol (String, front_Type) : front_Symbol		front_CharSymbol_kind
front_StringSymbol (String, Ident, front_Type) : front_Symbol		front_StringSymbol_kind
front_AppliedSym (Ident, front_NameOrField, Ident, front_Expr, Bool) : front_Symbol		front_AppliedSym_kind
front_CompareSym (front_Symbol, Ident) : front_Symbol		front_CompareSym_kind
front_SymbolSeq (List_front_Symbol, List_front_Field, List_front_And) : front_Symbol		front_SymbolSeq_kind
front_AltSymbol (front_Symbol, front_Alternator, List_front_Symbol) : front_Symbol		front_AltSymbol_kind
front_LabeledSym (Ident, front_Symbol) : front_Symbol		front_LabeledSym_kind
front_DefExpr (front_Expr) : front_Defining_id		front_DefExpr_kind
front_DefId (front_Symbol) : front_Defining_id		front_DefId_kind
front_Field (Ident, front_Type, Ident, List_front_FieldInit, Bool, Bool, Bool) : front_Field		front_Field_kind
front_WhenChecks (front_Expr) : front_FieldInit		front_WhenChecks_kind
front_WhenApplied (front_Expr) : front_FieldInit		front_WhenApplied_kind
front_WhenDefining (front_Expr) : front_FieldInit		front_WhenDefining_kind
front_WhenScope (front_Expr) : front_FieldInit		front_WhenScope_kind
front_WhenCreate (Bool, front_Expr) : front_FieldInit		front_WhenCreate_kind
front_Type (Ident, List_front_Type) : front_Type		front_Type_kind
front_CallExpr (front_Expr, List_front_Expr) : front_Expr		front_CallExpr_kind
front_NilExpr () : front_Expr		front_NilExpr_kind
front_StringExpr (String) : front_Expr		front_StringExpr_kind
front_BoolExpr (Bool) : front_Expr		front_BoolExpr_kind
front_IntExpr (Int) : front_Expr		front_IntExpr_kind
front_QualExpr (front_Expr, Ident) : front_Expr		front_QualExpr_kind
front_IdentExpr (Ident) : front_Expr		front_IdentExpr_kind
front_MonExpr (List_Ident, front_Expr) : front_Expr		front_MonExpr_kind
front_BinExpr (List_front_Expr, List_Ident) : front_Expr		front_BinExpr_kind
front_Check (front_Expr, Bool, List_front_Expr) : front_Check		front_Check_kind
front_ScanInfo (front_Type, Bool) : front_ScanInfo		front_ScanInfo_kind
front_MacroDef (Ident) : front_Defines		front_MacroDef_kind
front_PlainDef (Ident) : front_Defines		front_PlainDef_kind
front_NameSpace (Ident) : front_NameSpace		front_NameSpace_kind
front_dummy () : front_dummy		front_dummy_kind
front_NonTerminalScope (front_NonTerminal) : front_Scope		front_NonTerminalScope_kind
List_List_front_Symbol (List_front_Symbol, List_List_front_Symbol) : List_List_front_Symbol		List_List_front_Symbol_kind
List_front_Expr (front_Expr, List_front_Expr) : List_front_Expr		List_front_Expr_kind
List_front_Type (front_Type, List_front_Type) : List_front_Type		List_front_Type_kind
List_front_FieldInit (front_FieldInit, List_front_FieldInit) : List_front_FieldInit		List_front_FieldInit_kind
List_front_And (front_And, List_front_And) : List_front_And		List_front_And_kind
List_front_Field (front_Field, List_front_Field) : List_front_Field		List_front_Field_kind
List_front_Symbol (front_Symbol, List_front_Symbol) : List_front_Symbol		List_front_Symbol_kind
List_front_Check (front_Check, List_front_Check) : List_front_Check		List_front_Check_kind
List_front_Or (front_Or, List_front_Or) : List_front_Or		List_front_Or_kind
List_front_Alternative (front_Alternative, List_front_Alternative) : List_front_Alternative		List_front_Alternative_kind
List_front_Scoping (front_Scoping, List_front_Scoping) : List_front_Scoping		List_front_Scoping_kind
List_front_ImportedNonTerminal (front_ImportedNonTerminal, List_front_ImportedNonTerminal) : List_front_ImportedNonTerminal		List_front_ImportedNonTerminal_kind
List_front_NonTerminal (front_NonTerminal, List_front_NonTerminal) : List_front_NonTerminal		List_front_NonTerminal_kind
List_front_Import (front_Import, List_front_Import) : List_front_Import		List_front_Import_kind
List_front_NameSpace (front_NameSpace, List_front_NameSpace) : List_front_NameSpace		List_front_NameSpace_kind
front_NewScope () : front_Scoping		front_NewScope
front_OpenScope () : front_Scoping		front_OpenScope
front_CloseScope () : front_Scoping		front_CloseScope
front_AndTranspose () : front_And		front_AndTranspose
front_AndLeft () : front_And		front_AndLeft
front_AndRight () : front_And		front_AndRight
front_AndCenter () : front_And		front_AndCenter
front_OrCenter () : front_Or		front_OrCenter
front_OrLeft () : front_Or		front_OrLeft
front_OrRight () : front_Or		front_OrRight
front_OrTranspose () : front_Or		front_OrTranspose
front_Defining () : front_Define		front_Defining
front_Redefining () : front_Define		front_Redefining
front_Overloading () : front_Define		front_Overloading
front_AppliedName () : front_NameOrField		front_AppliedName
front_AppliedField () : front_NameOrField		front_AppliedField
Bind_front_NameSpace () : Bind_front_NameSpace		Bind_front_NameSpace
Bind_front_Alternative () : Bind_front_Alternative		Bind_front_Alternative
Bind_front_NonTerminal () : Bind_front_NonTerminal		Bind_front_NonTerminal
Bind_front_ImportedNonTerminal () : Bind_front_ImportedNonTerminal		Bind_front_ImportedNonTerminal
