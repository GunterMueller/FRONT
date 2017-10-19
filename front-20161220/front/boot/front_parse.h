#ifndef _front_parse_h
#define _front_parse_h

#include "front.h"

extern void front_multi_action (void*);

struct yy_buffer_state;

extern Bool front_use_lalr;
extern int front_state_stack_depth;

extern front_front Parse_front_front (char *s, int n, ...);
extern front_Import Parse_front_Import (char *s, int n, ...);
extern List_front_ImportedNonTerminal Parse_front_ImportedNonTerminals (char *s, int n, ...);
extern front_ImportedNonTerminal Parse_front_ImportedNonTerminal (char *s, int n, ...);
extern List_front_NonTerminal Parse_front_NonTerminals (char *s, int n, ...);
extern front_NonTerminal Parse_front_NonTerminal (char *s, int n, ...);
extern front_Super Parse_front_Super (char *s, int n, ...);
extern front_Rhs Parse_front_Rhs (char *s, int n, ...);
extern front_Scoping Parse_front_Scoping (char *s, int n, ...);
extern front_Alternative Parse_front_Alternative (char *s, int n, ...);
extern front_Symbol Parse_front_Symbol (char *s, int n, ...);
extern front_Symbol Parse_front_Symbol1 (char *s, int n, ...);
extern front_Symbol Parse_front_AltSymbol (char *s, int n, ...);
extern front_Symbol Parse_front_SymbolSeq (char *s, int n, ...);
extern front_And Parse_front_And (char *s, int n, ...);
extern front_Or Parse_front_Or (char *s, int n, ...);
extern front_Symbol Parse_front_Symbol2 (char *s, int n, ...);
extern front_Symbol Parse_front_SimpleSymbol (char *s, int n, ...);
extern front_Symbol Parse_front_IdSym (char *s, int n, ...);
extern front_Type Parse_front_OptType (char *s, int n, ...);
extern front_Symbol Parse_front_DefiningSym (char *s, int n, ...);
extern front_Expr Parse_front_ScopeExpr (char *s, int n, ...);
extern front_Defining_id Parse_front_Defining_id (char *s, int n, ...);
extern front_Define Parse_front_Define (char *s, int n, ...);
extern front_Field Parse_front_Field (char *s, int n, ...);
extern List_front_FieldInit Parse_front_FieldInits (char *s, int n, ...);
extern front_FieldInit Parse_front_FieldInit (char *s, int n, ...);
extern front_Type Parse_front_Type (char *s, int n, ...);
extern front_Expr Parse_front_Expr (char *s, int n, ...);
extern front_Expr Parse_front_MonExpr1 (char *s, int n, ...);
extern front_Expr Parse_front_SimpleExpr (char *s, int n, ...);
extern String Parse_front_StringOrKeyword (char *s, int n, ...);
extern front_Check Parse_front_Check (char *s, int n, ...);
extern List_front_NameSpace Parse_front_NameSpaceList (char *s, int n, ...);
extern List_front_Expr Parse_front_ExprList (char *s, int n, ...);
extern List_Ident Parse_front_IdentList (char *s, int n, ...);
extern List_front_Type Parse_front_TypeList (char *s, int n, ...);
extern front_Alternator Parse_front_Alternator (char *s, int n, ...);
extern front_ScanInfo Parse_front_ScanInfo (char *s, int n, ...);
extern front_Defines Parse_front_Defines (char *s, int n, ...);
extern front_NameSpace Parse_front_NameSpace (char *s, int n, ...);
extern Ident Parse_front_Oper (char *s, int n, ...);
extern front_NameOrField Parse_front_NameOrField (char *s, int n, ...);
extern List_front_Import Parse_front_OPTMORE_Import (char *s, int n, ...);
extern List_front_ImportedNonTerminal Parse_front_ALT_ImportedNonTerminal_SEP_commasym (char *s, int n, ...);
extern List_front_NonTerminal Parse_front_MORE_NonTerminal (char *s, int n, ...);
extern List_front_Scoping Parse_front_OPTMORE_Scoping (char *s, int n, ...);
extern List_front_Check Parse_front_OPTMORE_Check (char *s, int n, ...);
extern List_front_Symbol Parse_front_MORE_Symbol (char *s, int n, ...);
extern List_front_FieldInit Parse_front_ALT_FieldInit_SEP_commasym (char *s, int n, ...);
extern List_Ident Parse_front_OPTMORE_Oper (char *s, int n, ...);
extern List_front_Expr Parse_front_MORE_MonExpr1 (char *s, int n, ...);
extern List_front_NameSpace Parse_front_ALT_NameSpace_SEP_commasym_SP (char *s, int n, ...);
extern List_front_Expr Parse_front_ALT_Expr_SEP_commasym_SP (char *s, int n, ...);
extern List_Ident Parse_front_ALT_Identsym_SEP_commasym_SP (char *s, int n, ...);
extern List_front_Type Parse_front_ALT_Type_SEP_commasym_SP (char *s, int n, ...);
#endif /* _front_parse_h*/
