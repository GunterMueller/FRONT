#ifndef _grammar_parse_h
#define _grammar_parse_h

#include "grammar.h"

extern void grammar_multi_action (void*);

struct yy_buffer_state;

extern Bool grammar_use_lalr;
extern int grammar_state_stack_depth;

extern grammar_grammar Parse_grammar_grammar (char *s, int n, ...);
extern grammar_Scanner Parse_grammar_Scanner (char *s, int n, ...);
extern grammar_Token Parse_grammar_Token (char *s, int n, ...);
extern grammar_RegExpr Parse_grammar_RegExpr (char *s, int n, ...);
extern grammar_RegExpr Parse_grammar_ChoiceRE (char *s, int n, ...);
extern grammar_RegExpr Parse_grammar_SeqRE (char *s, int n, ...);
extern grammar_RegExpr Parse_grammar_PostRE (char *s, int n, ...);
extern grammar_RegExpr Parse_grammar_BasicRE (char *s, int n, ...);
extern String Parse_grammar_ScanAction (char *s, int n, ...);
extern grammar_Parser Parse_grammar_Parser (char *s, int n, ...);
extern grammar_ProdRule Parse_grammar_ProdRule (char *s, int n, ...);
extern List_grammar_Token Parse_grammar_OPTMORE_Token (char *s, int n, ...);
extern List_String Parse_grammar_OPTMORE_ScanAction_semicolonsym (char *s, int n, ...);
extern List_grammar_ProdRule Parse_grammar_OPTMORE_ProdRule (char *s, int n, ...);
#endif /* _grammar_parse_h*/
