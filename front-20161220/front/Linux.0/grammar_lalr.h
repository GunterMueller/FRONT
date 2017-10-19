#ifndef _grammar_lalr_h
#define _grammar_lalr_h

#include "grammar.h"

#include <front/parse_support.h>

grammar_Scanner Parse_state_grammar_Scanner (void);	/* state 0 */
grammar_Parser Parse_state_grammar_Parser (void);	/* state 34 */
grammar_grammar Parse_state_grammar_grammar (void);	/* state 42 */
List_grammar_Token Parse_state_grammar_OPTMORE_Token (void);	/* state 45 */
grammar_RegExpr Parse_state_grammar_RegExpr (void);	/* state 46 */
List_String Parse_state_grammar_OPTMORE_ScanAction_semicolonsym (void);	/* state 47 */
grammar_Token Parse_state_grammar_Token (void);	/* state 48 */
grammar_RegExpr Parse_state_grammar_ChoiceRE (void);	/* state 49 */
grammar_RegExpr Parse_state_grammar_SeqRE (void);	/* state 50 */
grammar_RegExpr Parse_state_grammar_PostRE (void);	/* state 51 */
grammar_RegExpr Parse_state_grammar_BasicRE (void);	/* state 52 */
String Parse_state_grammar_ScanAction (void);	/* state 53 */
List_grammar_ProdRule Parse_state_grammar_OPTMORE_ProdRule (void);	/* state 54 */
grammar_ProdRule Parse_state_grammar_ProdRule (void);	/* state 55 */

#endif /* _grammar_lalr_h */
