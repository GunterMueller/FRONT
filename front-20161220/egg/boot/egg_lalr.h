#ifndef _egg_lalr_h
#define _egg_lalr_h

#include "egg.h"

#include <front/parse_support.h>

egg_Uses Parse_state_egg_Uses (void);	/* state 0 */
List_egg_Statement Parse_state_egg_OPTMORE_Group (void);	/* state 8 */
egg_egg Parse_state_egg_egg (void);	/* state 62 */
List_String Parse_state_egg_Strings (void);	/* state 65 */
List_String Parse_state_egg_ALT_Stringsym_SEP_commasym (void);	/* state 66 */
List_egg_Declaration Parse_state_egg_OPTMORE_Declaration (void);	/* state 67 */
List_egg_Declaration Parse_state_egg_Declarations (void);	/* state 68 */
egg_MessageKind Parse_state_egg_MessageKind (void);	/* state 69 */
List_egg_Expression Parse_state_egg_MORE_Expression (void);	/* state 70 */
egg_Declaration Parse_state_egg_Declaration (void);	/* state 71 */
egg_Expression Parse_state_egg_Expression (void);	/* state 72 */
List_egg_Expression Parse_state_egg_Params (void);	/* state 73 */
List_egg_Expression Parse_state_egg_ALT_Expression_SEP_commasym (void);	/* state 74 */
List_egg_Statement Parse_state_egg_OPTMORE_Statement (void);	/* state 75 */
List_egg_Statement Parse_state_egg_Statements (void);	/* state 76 */
egg_Statement Parse_state_egg_Message (void);	/* state 77 */
egg_Statement Parse_state_egg_Statement (void);	/* state 80 */
egg_Statement Parse_state_egg_Group (void);	/* state 81 */
List_egg_SubMessage Parse_state_egg_SubMessages (void);	/* state 82 */
List_egg_SubMessage Parse_state_egg_ALT_SubMessage_SEP_commasym (void);	/* state 83 */
egg_SubMessage Parse_state_egg_SubMessage (void);	/* state 84 */

#endif /* _egg_lalr_h */
