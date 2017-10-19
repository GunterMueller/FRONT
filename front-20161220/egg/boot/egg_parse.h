#ifndef _egg_parse_h
#define _egg_parse_h

#include "egg.h"

extern void egg_multi_action (void*);

struct yy_buffer_state;

extern Bool egg_use_lalr;
extern int egg_state_stack_depth;

extern egg_egg Parse_egg_egg (char *s, int n, ...);
extern egg_Uses Parse_egg_Uses (char *s, int n, ...);
extern List_String Parse_egg_Strings (char *s, int n, ...);
extern List_egg_Declaration Parse_egg_Declarations (char *s, int n, ...);
extern egg_Declaration Parse_egg_Declaration (char *s, int n, ...);
extern egg_Expression Parse_egg_Expression (char *s, int n, ...);
extern List_egg_Expression Parse_egg_Params (char *s, int n, ...);
extern List_egg_Statement Parse_egg_Statements (char *s, int n, ...);
extern egg_Statement Parse_egg_Statement (char *s, int n, ...);
extern egg_MessageKind Parse_egg_MessageKind (char *s, int n, ...);
extern egg_Statement Parse_egg_Message (char *s, int n, ...);
extern List_egg_SubMessage Parse_egg_SubMessages (char *s, int n, ...);
extern egg_SubMessage Parse_egg_SubMessage (char *s, int n, ...);
extern egg_Statement Parse_egg_Group (char *s, int n, ...);
extern List_egg_Statement Parse_egg_OPTMORE_Group (char *s, int n, ...);
extern List_String Parse_egg_ALT_Stringsym_SEP_commasym (char *s, int n, ...);
extern List_egg_Declaration Parse_egg_OPTMORE_Declaration (char *s, int n, ...);
extern List_egg_Expression Parse_egg_MORE_Expression (char *s, int n, ...);
extern List_egg_Expression Parse_egg_ALT_Expression_SEP_commasym (char *s, int n, ...);
extern List_egg_Statement Parse_egg_OPTMORE_Statement (char *s, int n, ...);
extern List_egg_SubMessage Parse_egg_ALT_SubMessage_SEP_commasym (char *s, int n, ...);
#endif /* _egg_parse_h*/
