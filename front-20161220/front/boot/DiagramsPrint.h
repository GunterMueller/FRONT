#ifndef _DiagramsPrint
#define _DiagramsPrint

#include "Diagrams.h"

#define PRINT_Diagrams_Diagrams (Diagrams_print_actions.action_Diagrams[PRE_ACTION]?Diagrams_print_actions.action_Diagrams[PRE_ACTION]:Print_Diagrams_Diagrams)
#define PRINT_Diagrams_Picture (Diagrams_print_actions.action_Picture[PRE_ACTION]?Diagrams_print_actions.action_Picture[PRE_ACTION]:Print_Diagrams_Picture)
#define PRINT_Diagrams_Scope (Diagrams_print_actions.action_Scope[PRE_ACTION]?Diagrams_print_actions.action_Scope[PRE_ACTION]:Print_Diagrams_Scope)
#define PRINT_List_Diagrams_Direction (Diagrams_print_actions.action_List_Direction[PRE_ACTION]?Diagrams_print_actions.action_List_Direction[PRE_ACTION]:Print_List_Diagrams_Direction)
#define PRINT_List_Diagrams_Picture (Diagrams_print_actions.action_List_Picture[PRE_ACTION]?Diagrams_print_actions.action_List_Picture[PRE_ACTION]:Print_List_Diagrams_Picture)

#define PRINT_Diagrams_Direction (Diagrams_print_actions.action_Direction[PRE_ACTION]?Diagrams_print_actions.action_Direction[PRE_ACTION]:Print_Diagrams_Direction)

extern void Print_Diagrams_Diagrams (Diagrams_Diagrams me);
extern void Print_Diagrams_Picture (Diagrams_Picture me);
extern void Print_Diagrams_Scope (Diagrams_Scope me);
extern void Print_List_Diagrams_Direction (List_Diagrams_Direction me);
extern void Print_List_Diagrams_Picture (List_Diagrams_Picture me);

extern void Print_Diagrams_Direction (Diagrams_Direction me);

#endif /* _DiagramsPrint */
