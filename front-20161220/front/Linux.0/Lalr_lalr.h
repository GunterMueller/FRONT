#ifndef _Lalr_lalr_h
#define _Lalr_lalr_h

#include "Lalr.h"

#include <front/parse_support.h>

List_Lalr_Production Parse_state_Lalr_OPTMORE_Production (void);	/* state 0 */
List_Lalr_LR_state Parse_state_Lalr_OPTMORE_LR_state (void);	/* state 24 */
Lalr_Lalr Parse_state_Lalr_Lalr (void);	/* state 50 */
Lalr_LR_Symbols Parse_state_Lalr_ProdRhs (void);	/* state 55 */
Lalr_Emptiness Parse_state_Lalr_Emptiness (void);	/* state 56 */
List_Ident Parse_state_Lalr_TermSet (void);	/* state 57 */
Lalr_Production Parse_state_Lalr_Production (void);	/* state 58 */
Lalr_LR_Symbol Parse_state_Lalr_LR_Symbol (void);	/* state 59 */
Lalr_LR_Symbols Parse_state_Lalr_LR_Symbols (void);	/* state 60 */
List_Lalr_Item Parse_state_Lalr_MORE_Item (void);	/* state 61 */
List_Lalr_Transition Parse_state_Lalr_OPTMORE_Transition (void);	/* state 62 */
Lalr_LR_state Parse_state_Lalr_LR_state (void);	/* state 63 */
List_Lalr_LR_Symbol Parse_state_Lalr_OPTMORE_LR_Symbol (void);	/* state 64 */
Lalr_Item Parse_state_Lalr_Item (void);	/* state 65 */
List_Ident Parse_state_Lalr_MORE_Identsym_spacesym (void);	/* state 66 */
Lalr_Transition Parse_state_Lalr_Transition (void);	/* state 67 */

#endif /* _Lalr_lalr_h */
