#ifndef _LalrPrint
#define _LalrPrint

#include "Lalr.h"

#define PRINT_Lalr_Lalr (Lalr_print_actions.action_Lalr[PRE_ACTION]?Lalr_print_actions.action_Lalr[PRE_ACTION]:Print_Lalr_Lalr)
#define PRINT_Lalr_Production (Lalr_print_actions.action_Production[PRE_ACTION]?Lalr_print_actions.action_Production[PRE_ACTION]:Print_Lalr_Production)
#define PRINT_Lalr_LR_Symbol (Lalr_print_actions.action_LR_Symbol[PRE_ACTION]?Lalr_print_actions.action_LR_Symbol[PRE_ACTION]:Print_Lalr_LR_Symbol)
#define PRINT_Lalr_LR_Symbols (Lalr_print_actions.action_LR_Symbols[PRE_ACTION]?Lalr_print_actions.action_LR_Symbols[PRE_ACTION]:Print_Lalr_LR_Symbols)
#define PRINT_Lalr_LR_state (Lalr_print_actions.action_LR_state[PRE_ACTION]?Lalr_print_actions.action_LR_state[PRE_ACTION]:Print_Lalr_LR_state)
#define PRINT_Lalr_Item (Lalr_print_actions.action_Item[PRE_ACTION]?Lalr_print_actions.action_Item[PRE_ACTION]:Print_Lalr_Item)
#define PRINT_Lalr_Transition (Lalr_print_actions.action_Transition[PRE_ACTION]?Lalr_print_actions.action_Transition[PRE_ACTION]:Print_Lalr_Transition)
#define PRINT_Lalr_Scope (Lalr_print_actions.action_Scope[PRE_ACTION]?Lalr_print_actions.action_Scope[PRE_ACTION]:Print_Lalr_Scope)
#define PRINT_List_Lalr_LR_Symbols (Lalr_print_actions.action_List_LR_Symbols[PRE_ACTION]?Lalr_print_actions.action_List_LR_Symbols[PRE_ACTION]:Print_List_Lalr_LR_Symbols)
#define PRINT_List_Lalr_LR_Symbol (Lalr_print_actions.action_List_LR_Symbol[PRE_ACTION]?Lalr_print_actions.action_List_LR_Symbol[PRE_ACTION]:Print_List_Lalr_LR_Symbol)
#define PRINT_List_Lalr_Transition (Lalr_print_actions.action_List_Transition[PRE_ACTION]?Lalr_print_actions.action_List_Transition[PRE_ACTION]:Print_List_Lalr_Transition)
#define PRINT_List_Lalr_Item (Lalr_print_actions.action_List_Item[PRE_ACTION]?Lalr_print_actions.action_List_Item[PRE_ACTION]:Print_List_Lalr_Item)
#define PRINT_List_Lalr_LR_state (Lalr_print_actions.action_List_LR_state[PRE_ACTION]?Lalr_print_actions.action_List_LR_state[PRE_ACTION]:Print_List_Lalr_LR_state)
#define PRINT_List_Lalr_Production (Lalr_print_actions.action_List_Production[PRE_ACTION]?Lalr_print_actions.action_List_Production[PRE_ACTION]:Print_List_Lalr_Production)

#define PRINT_Lalr_Emptiness (Lalr_print_actions.action_Emptiness[PRE_ACTION]?Lalr_print_actions.action_Emptiness[PRE_ACTION]:Print_Lalr_Emptiness)

extern void Print_Lalr_Lalr (Lalr_Lalr me);
extern void Print_Lalr_Production (Lalr_Production me);
extern void Print_Lalr_LR_Symbol (Lalr_LR_Symbol me);
extern void Print_Lalr_LR_Symbols (Lalr_LR_Symbols me);
extern void Print_Lalr_LR_state (Lalr_LR_state me);
extern void Print_Lalr_Item (Lalr_Item me);
extern void Print_Lalr_Transition (Lalr_Transition me);
extern void Print_Lalr_Scope (Lalr_Scope me);
extern void Print_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols me);
extern void Print_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol me);
extern void Print_List_Lalr_Transition (List_Lalr_Transition me);
extern void Print_List_Lalr_Item (List_Lalr_Item me);
extern void Print_List_Lalr_LR_state (List_Lalr_LR_state me);
extern void Print_List_Lalr_Production (List_Lalr_Production me);

extern char *Text_Lalr_Lalr (Lalr_Lalr me);
extern char *Text_Lalr_Production (Lalr_Production me);
extern char *Text_Lalr_LR_Symbol (Lalr_LR_Symbol me);
extern char *Text_Lalr_LR_Symbols (Lalr_LR_Symbols me);
extern char *Text_Lalr_LR_state (Lalr_LR_state me);
extern char *Text_Lalr_Item (Lalr_Item me);
extern char *Text_Lalr_Transition (Lalr_Transition me);
extern char *Text_Lalr_Scope (Lalr_Scope me);
extern char *Text_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols me);
extern char *Text_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol me);
extern char *Text_List_Lalr_Transition (List_Lalr_Transition me);
extern char *Text_List_Lalr_Item (List_Lalr_Item me);
extern char *Text_List_Lalr_LR_state (List_Lalr_LR_state me);
extern char *Text_List_Lalr_Production (List_Lalr_Production me);

extern void Print_Lalr_Emptiness (Lalr_Emptiness me);

extern char *Text_Lalr_Emptiness (Lalr_Emptiness me);

#endif /* _LalrPrint */
