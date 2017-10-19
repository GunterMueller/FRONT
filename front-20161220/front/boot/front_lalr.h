#ifndef _front_lalr_h
#define _front_lalr_h

#include "front.h"

#include <front/parse_support.h>

List_front_Import Parse_state_front_OPTMORE_Import (void);	/* state 0 */
front_front Parse_state_front_front (void);	/* state 15 */
List_front_ImportedNonTerminal Parse_state_front_ImportedNonTerminals (void);	/* state 271 */
front_Import Parse_state_front_Import (void);	/* state 272 */
List_front_ImportedNonTerminal Parse_state_front_ALT_ImportedNonTerminal_SEP_commasym (void);	/* state 273 */
front_ImportedNonTerminal Parse_state_front_ImportedNonTerminal (void);	/* state 274 */
List_front_NonTerminal Parse_state_front_MORE_NonTerminal (void);	/* state 275 */
List_front_NonTerminal Parse_state_front_NonTerminals (void);	/* state 276 */
front_Defines Parse_state_front_Defines (void);	/* state 277 */
front_Rhs Parse_state_front_Rhs (void);	/* state 278 */
front_NonTerminal Parse_state_front_NonTerminal (void);	/* state 279 */
front_Super Parse_state_front_Super (void);	/* state 280 */
List_front_Scoping Parse_state_front_OPTMORE_Scoping (void);	/* state 281 */
front_Symbol Parse_state_front_Symbol1 (void);	/* state 282 */
front_Scoping Parse_state_front_Scoping (void);	/* state 283 */
front_Alternative Parse_state_front_Alternative (void);	/* state 284 */
front_Symbol Parse_state_front_Symbol2 (void);	/* state 285 */
front_Symbol Parse_state_front_Symbol (void);	/* state 286 */
front_Symbol Parse_state_front_AltSymbol (void);	/* state 287 */
front_Symbol Parse_state_front_SymbolSeq (void);	/* state 289 */
front_Alternator Parse_state_front_Alternator (void);	/* state 290 */
List_front_Symbol Parse_state_front_MORE_Symbol (void);	/* state 291 */
front_And Parse_state_front_And (void);	/* state 292 */
front_Or Parse_state_front_Or (void);	/* state 293 */
front_Symbol Parse_state_front_SimpleSymbol (void);	/* state 294 */
front_Symbol Parse_state_front_DefiningSym (void);	/* state 295 */
front_Symbol Parse_state_front_IdSym (void);	/* state 296 */
front_NameOrField Parse_state_front_NameOrField (void);	/* state 297 */
front_Type Parse_state_front_OptType (void);	/* state 298 */
String Parse_state_front_StringOrKeyword (void);	/* state 299 */
front_Expr Parse_state_front_Expr (void);	/* state 300 */
front_Define Parse_state_front_Define (void);	/* state 301 */
front_Defining_id Parse_state_front_Defining_id (void);	/* state 302 */
front_Expr Parse_state_front_ScopeExpr (void);	/* state 303 */
front_Type Parse_state_front_Type (void);	/* state 304 */
List_front_FieldInit Parse_state_front_FieldInits (void);	/* state 305 */
front_Field Parse_state_front_Field (void);	/* state 306 */
List_front_FieldInit Parse_state_front_ALT_FieldInit_SEP_commasym (void);	/* state 309 */
front_FieldInit Parse_state_front_FieldInit (void);	/* state 310 */
List_Ident Parse_state_front_OPTMORE_Oper (void);	/* state 311 */
front_Expr Parse_state_front_SimpleExpr (void);	/* state 312 */
front_Expr Parse_state_front_MonExpr1 (void);	/* state 314 */
List_front_Expr Parse_state_front_MORE_MonExpr1 (void);	/* state 315 */
front_Check Parse_state_front_Check (void);	/* state 316 */
List_front_NameSpace Parse_state_front_ALT_NameSpace_SEP_commasym_SP (void);	/* state 317 */
List_front_NameSpace Parse_state_front_NameSpaceList (void);	/* state 318 */
List_front_Expr Parse_state_front_ALT_Expr_SEP_commasym_SP (void);	/* state 319 */
List_front_Expr Parse_state_front_ExprList (void);	/* state 320 */
List_Ident Parse_state_front_ALT_Identsym_SEP_commasym_SP (void);	/* state 321 */
List_Ident Parse_state_front_IdentList (void);	/* state 322 */
List_front_Type Parse_state_front_ALT_Type_SEP_commasym_SP (void);	/* state 323 */
List_front_Type Parse_state_front_TypeList (void);	/* state 324 */
front_ScanInfo Parse_state_front_ScanInfo (void);	/* state 325 */
front_NameSpace Parse_state_front_NameSpace (void);	/* state 326 */
Ident Parse_state_front_Oper (void);	/* state 327 */
List_front_Check Parse_state_front_OPTMORE_Check (void);	/* state 328 */

#endif /* _front_lalr_h */
