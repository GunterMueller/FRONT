#ifndef _eggPrint
#define _eggPrint

#include "egg.h"

#define PRINT_egg_egg (egg_print_actions.action_egg[PRE_ACTION]?egg_print_actions.action_egg[PRE_ACTION]:Print_egg_egg)
#define PRINT_egg_Uses (egg_print_actions.action_Uses[PRE_ACTION]?egg_print_actions.action_Uses[PRE_ACTION]:Print_egg_Uses)
#define PRINT_egg_Declaration (egg_print_actions.action_Declaration[PRE_ACTION]?egg_print_actions.action_Declaration[PRE_ACTION]:Print_egg_Declaration)
#define PRINT_egg_Expression (egg_print_actions.action_Expression[PRE_ACTION]?egg_print_actions.action_Expression[PRE_ACTION]:Print_egg_Expression)
#define PRINT_egg_Statement (egg_print_actions.action_Statement[PRE_ACTION]?egg_print_actions.action_Statement[PRE_ACTION]:Print_egg_Statement)
#define PRINT_egg_SubMessage (egg_print_actions.action_SubMessage[PRE_ACTION]?egg_print_actions.action_SubMessage[PRE_ACTION]:Print_egg_SubMessage)
#define PRINT_egg_Scope (egg_print_actions.action_Scope[PRE_ACTION]?egg_print_actions.action_Scope[PRE_ACTION]:Print_egg_Scope)
#define PRINT_List_egg_Declaration (egg_print_actions.action_List_Declaration[PRE_ACTION]?egg_print_actions.action_List_Declaration[PRE_ACTION]:Print_List_egg_Declaration)
#define PRINT_List_egg_SubMessage (egg_print_actions.action_List_SubMessage[PRE_ACTION]?egg_print_actions.action_List_SubMessage[PRE_ACTION]:Print_List_egg_SubMessage)
#define PRINT_List_egg_Expression (egg_print_actions.action_List_Expression[PRE_ACTION]?egg_print_actions.action_List_Expression[PRE_ACTION]:Print_List_egg_Expression)
#define PRINT_List_egg_Statement (egg_print_actions.action_List_Statement[PRE_ACTION]?egg_print_actions.action_List_Statement[PRE_ACTION]:Print_List_egg_Statement)

#define PRINT_egg_MessageKind (egg_print_actions.action_MessageKind[PRE_ACTION]?egg_print_actions.action_MessageKind[PRE_ACTION]:Print_egg_MessageKind)

extern void Print_egg_egg (egg_egg me);
extern void Print_egg_Uses (egg_Uses me);
extern void Print_egg_Declaration (egg_Declaration me);
extern void Print_egg_Expression (egg_Expression me);
extern void Print_egg_Statement (egg_Statement me);
extern void Print_egg_SubMessage (egg_SubMessage me);
extern void Print_egg_Scope (egg_Scope me);
extern void Print_List_egg_Declaration (List_egg_Declaration me);
extern void Print_List_egg_SubMessage (List_egg_SubMessage me);
extern void Print_List_egg_Expression (List_egg_Expression me);
extern void Print_List_egg_Statement (List_egg_Statement me);

extern char *Text_egg_egg (egg_egg me);
extern char *Text_egg_Uses (egg_Uses me);
extern char *Text_egg_Declaration (egg_Declaration me);
extern char *Text_egg_Expression (egg_Expression me);
extern char *Text_egg_Statement (egg_Statement me);
extern char *Text_egg_SubMessage (egg_SubMessage me);
extern char *Text_egg_Scope (egg_Scope me);
extern char *Text_List_egg_Declaration (List_egg_Declaration me);
extern char *Text_List_egg_SubMessage (List_egg_SubMessage me);
extern char *Text_List_egg_Expression (List_egg_Expression me);
extern char *Text_List_egg_Statement (List_egg_Statement me);

extern void Print_egg_MessageKind (egg_MessageKind me);

extern char *Text_egg_MessageKind (egg_MessageKind me);

#endif /* _eggPrint */
