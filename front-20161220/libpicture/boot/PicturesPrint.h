#ifndef _PicturesPrint
#define _PicturesPrint

#include "Pictures.h"

#define PRINT_Pictures_Pictures (Pictures_print_actions.action_Pictures[PRE_ACTION]?Pictures_print_actions.action_Pictures[PRE_ACTION]:Print_Pictures_Pictures)
#define PRINT_Pictures_Picture (Pictures_print_actions.action_Picture[PRE_ACTION]?Pictures_print_actions.action_Picture[PRE_ACTION]:Print_Pictures_Picture)
#define PRINT_Pictures_Scope (Pictures_print_actions.action_Scope[PRE_ACTION]?Pictures_print_actions.action_Scope[PRE_ACTION]:Print_Pictures_Scope)
#define PRINT_List_Pictures_Direction (Pictures_print_actions.action_List_Direction[PRE_ACTION]?Pictures_print_actions.action_List_Direction[PRE_ACTION]:Print_List_Pictures_Direction)
#define PRINT_List_Pictures_Picture (Pictures_print_actions.action_List_Picture[PRE_ACTION]?Pictures_print_actions.action_List_Picture[PRE_ACTION]:Print_List_Pictures_Picture)

#define PRINT_Pictures_Direction (Pictures_print_actions.action_Direction[PRE_ACTION]?Pictures_print_actions.action_Direction[PRE_ACTION]:Print_Pictures_Direction)

extern void Print_Pictures_Pictures (Pictures_Pictures me);
extern void Print_Pictures_Picture (Pictures_Picture me);
extern void Print_Pictures_Scope (Pictures_Scope me);
extern void Print_List_Pictures_Direction (List_Pictures_Direction me);
extern void Print_List_Pictures_Picture (List_Pictures_Picture me);

extern char *Text_Pictures_Pictures (Pictures_Pictures me);
extern char *Text_Pictures_Picture (Pictures_Picture me);
extern char *Text_Pictures_Scope (Pictures_Scope me);
extern char *Text_List_Pictures_Direction (List_Pictures_Direction me);
extern char *Text_List_Pictures_Picture (List_Pictures_Picture me);

extern void Print_Pictures_Direction (Pictures_Direction me);

extern char *Text_Pictures_Direction (Pictures_Direction me);

#endif /* _PicturesPrint */
