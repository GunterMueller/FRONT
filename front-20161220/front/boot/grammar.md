#include "grammar_defs.h"
grammar_grammar (grammar_Scanner, grammar_Parser) : grammar_grammar		grammar_grammar_kind
grammar_Scanner (List_grammar_Token) : grammar_Scanner		grammar_Scanner_kind
grammar_Token (grammar_RegExpr, List_String) : grammar_Token		grammar_Token_kind
grammar_AnyRE () : grammar_RegExpr		grammar_AnyRE_kind
grammar_ParRE (grammar_RegExpr) : grammar_RegExpr		grammar_ParRE_kind
grammar_IdRE (Ident) : grammar_RegExpr		grammar_IdRE_kind
grammar_EOLRE () : grammar_RegExpr		grammar_EOLRE_kind
grammar_SOLRE () : grammar_RegExpr		grammar_SOLRE_kind
grammar_StringRE (String) : grammar_RegExpr		grammar_StringRE_kind
grammar_TimesRE (grammar_RegExpr) : grammar_RegExpr		grammar_TimesRE_kind
grammar_PlusRE (grammar_RegExpr) : grammar_RegExpr		grammar_PlusRE_kind
grammar_OptRE (grammar_RegExpr) : grammar_RegExpr		grammar_OptRE_kind
grammar_SeqRE (grammar_RegExpr, grammar_RegExpr) : grammar_RegExpr		grammar_SeqRE_kind
grammar_ChoiceRE (grammar_RegExpr, grammar_RegExpr) : grammar_RegExpr		grammar_ChoiceRE_kind
grammar_Parser (List_grammar_ProdRule) : grammar_Parser		grammar_Parser_kind
grammar_Extra_Rule (Ident) : grammar_ProdRule		grammar_Extra_Rule_kind
grammar_Import_Rule (Ident) : grammar_ProdRule		grammar_Import_Rule_kind
grammar_NT_Rule (Ident) : grammar_ProdRule		grammar_NT_Rule_kind
grammar_Scope () : grammar_Scope		grammar_Scope_kind
List_grammar_ProdRule (grammar_ProdRule, List_grammar_ProdRule) : List_grammar_ProdRule		List_grammar_ProdRule_kind
List_grammar_Token (grammar_Token, List_grammar_Token) : List_grammar_Token		List_grammar_Token_kind
