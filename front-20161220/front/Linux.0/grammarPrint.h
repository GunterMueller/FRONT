#ifndef _grammarPrint
#define _grammarPrint

#include "grammar.h"

#define PRINT_grammar_grammar (grammar_print_actions.action_grammar[PRE_ACTION]?grammar_print_actions.action_grammar[PRE_ACTION]:Print_grammar_grammar)
#define PRINT_grammar_Scanner (grammar_print_actions.action_Scanner[PRE_ACTION]?grammar_print_actions.action_Scanner[PRE_ACTION]:Print_grammar_Scanner)
#define PRINT_grammar_Token (grammar_print_actions.action_Token[PRE_ACTION]?grammar_print_actions.action_Token[PRE_ACTION]:Print_grammar_Token)
#define PRINT_grammar_RegExpr (grammar_print_actions.action_RegExpr[PRE_ACTION]?grammar_print_actions.action_RegExpr[PRE_ACTION]:Print_grammar_RegExpr)
#define PRINT_grammar_Parser (grammar_print_actions.action_Parser[PRE_ACTION]?grammar_print_actions.action_Parser[PRE_ACTION]:Print_grammar_Parser)
#define PRINT_grammar_ProdRule (grammar_print_actions.action_ProdRule[PRE_ACTION]?grammar_print_actions.action_ProdRule[PRE_ACTION]:Print_grammar_ProdRule)
#define PRINT_grammar_Scope (grammar_print_actions.action_Scope[PRE_ACTION]?grammar_print_actions.action_Scope[PRE_ACTION]:Print_grammar_Scope)
#define PRINT_List_grammar_ProdRule (grammar_print_actions.action_List_ProdRule[PRE_ACTION]?grammar_print_actions.action_List_ProdRule[PRE_ACTION]:Print_List_grammar_ProdRule)
#define PRINT_List_grammar_Token (grammar_print_actions.action_List_Token[PRE_ACTION]?grammar_print_actions.action_List_Token[PRE_ACTION]:Print_List_grammar_Token)


extern void Print_grammar_grammar (grammar_grammar me);
extern void Print_grammar_Scanner (grammar_Scanner me);
extern void Print_grammar_Token (grammar_Token me);
extern void Print_grammar_RegExpr (grammar_RegExpr me);
extern void Print_grammar_Parser (grammar_Parser me);
extern void Print_grammar_ProdRule (grammar_ProdRule me);
extern void Print_grammar_Scope (grammar_Scope me);
extern void Print_List_grammar_ProdRule (List_grammar_ProdRule me);
extern void Print_List_grammar_Token (List_grammar_Token me);

extern char *Text_grammar_grammar (grammar_grammar me);
extern char *Text_grammar_Scanner (grammar_Scanner me);
extern char *Text_grammar_Token (grammar_Token me);
extern char *Text_grammar_RegExpr (grammar_RegExpr me);
extern char *Text_grammar_Parser (grammar_Parser me);
extern char *Text_grammar_ProdRule (grammar_ProdRule me);
extern char *Text_grammar_Scope (grammar_Scope me);
extern char *Text_List_grammar_ProdRule (List_grammar_ProdRule me);
extern char *Text_List_grammar_Token (List_grammar_Token me);



#endif /* _grammarPrint */
