#ifndef _TypesPrint
#define _TypesPrint

#include "Types.h"

#define PRINT_Types_Types (Types_print_actions.action_Types[PRE_ACTION]?Types_print_actions.action_Types[PRE_ACTION]:Print_Types_Types)
#define PRINT_Types_includes2 (Types_print_actions.action_includes2[PRE_ACTION]?Types_print_actions.action_includes2[PRE_ACTION]:Print_Types_includes2)
#define PRINT_Types_EnumType (Types_print_actions.action_EnumType[PRE_ACTION]?Types_print_actions.action_EnumType[PRE_ACTION]:Print_Types_EnumType)
#define PRINT_Types_BindType (Types_print_actions.action_BindType[PRE_ACTION]?Types_print_actions.action_BindType[PRE_ACTION]:Print_Types_BindType)
#define PRINT_Types_PointerType (Types_print_actions.action_PointerType[PRE_ACTION]?Types_print_actions.action_PointerType[PRE_ACTION]:Print_Types_PointerType)
#define PRINT_Types_subtypedef (Types_print_actions.action_subtypedef[PRE_ACTION]?Types_print_actions.action_subtypedef[PRE_ACTION]:Print_Types_subtypedef)
#define PRINT_Types_StructType (Types_print_actions.action_StructType[PRE_ACTION]?Types_print_actions.action_StructType[PRE_ACTION]:Print_Types_StructType)
#define PRINT_Types_struct_type (Types_print_actions.action_struct_type[PRE_ACTION]?Types_print_actions.action_struct_type[PRE_ACTION]:Print_Types_struct_type)
#define PRINT_Types_macro (Types_print_actions.action_macro[PRE_ACTION]?Types_print_actions.action_macro[PRE_ACTION]:Print_Types_macro)
#define PRINT_Types_field (Types_print_actions.action_field[PRE_ACTION]?Types_print_actions.action_field[PRE_ACTION]:Print_Types_field)
#define PRINT_Types_TypeName (Types_print_actions.action_TypeName[PRE_ACTION]?Types_print_actions.action_TypeName[PRE_ACTION]:Print_Types_TypeName)
#define PRINT_Types_CreateFunction (Types_print_actions.action_CreateFunction[PRE_ACTION]?Types_print_actions.action_CreateFunction[PRE_ACTION]:Print_Types_CreateFunction)
#define PRINT_Types_Scope (Types_print_actions.action_Scope[PRE_ACTION]?Types_print_actions.action_Scope[PRE_ACTION]:Print_Types_Scope)
#define PRINT_List_Types_struct_type (Types_print_actions.action_List_struct_type[PRE_ACTION]?Types_print_actions.action_List_struct_type[PRE_ACTION]:Print_List_Types_struct_type)
#define PRINT_List_Types_field (Types_print_actions.action_List_field[PRE_ACTION]?Types_print_actions.action_List_field[PRE_ACTION]:Print_List_Types_field)
#define PRINT_List_Types_CreateFunction (Types_print_actions.action_List_CreateFunction[PRE_ACTION]?Types_print_actions.action_List_CreateFunction[PRE_ACTION]:Print_List_Types_CreateFunction)
#define PRINT_List_Types_macro (Types_print_actions.action_List_macro[PRE_ACTION]?Types_print_actions.action_List_macro[PRE_ACTION]:Print_List_Types_macro)
#define PRINT_List_Types_TypeName (Types_print_actions.action_List_TypeName[PRE_ACTION]?Types_print_actions.action_List_TypeName[PRE_ACTION]:Print_List_Types_TypeName)
#define PRINT_List_Types_StructType (Types_print_actions.action_List_StructType[PRE_ACTION]?Types_print_actions.action_List_StructType[PRE_ACTION]:Print_List_Types_StructType)
#define PRINT_List_Types_BindType (Types_print_actions.action_List_BindType[PRE_ACTION]?Types_print_actions.action_List_BindType[PRE_ACTION]:Print_List_Types_BindType)
#define PRINT_List_Types_subtypedef (Types_print_actions.action_List_subtypedef[PRE_ACTION]?Types_print_actions.action_List_subtypedef[PRE_ACTION]:Print_List_Types_subtypedef)
#define PRINT_List_Types_PointerType (Types_print_actions.action_List_PointerType[PRE_ACTION]?Types_print_actions.action_List_PointerType[PRE_ACTION]:Print_List_Types_PointerType)
#define PRINT_List_Types_EnumType (Types_print_actions.action_List_EnumType[PRE_ACTION]?Types_print_actions.action_List_EnumType[PRE_ACTION]:Print_List_Types_EnumType)


extern void Print_Types_Types (Types_Types me);
extern void Print_Types_includes2 (Types_includes2 me);
extern void Print_Types_EnumType (Types_EnumType me);
extern void Print_Types_BindType (Types_BindType me);
extern void Print_Types_PointerType (Types_PointerType me);
extern void Print_Types_subtypedef (Types_subtypedef me);
extern void Print_Types_StructType (Types_StructType me);
extern void Print_Types_struct_type (Types_struct_type me);
extern void Print_Types_macro (Types_macro me);
extern void Print_Types_field (Types_field me);
extern void Print_Types_TypeName (Types_TypeName me);
extern void Print_Types_CreateFunction (Types_CreateFunction me);
extern void Print_Types_Scope (Types_Scope me);
extern void Print_List_Types_struct_type (List_Types_struct_type me);
extern void Print_List_Types_field (List_Types_field me);
extern void Print_List_Types_CreateFunction (List_Types_CreateFunction me);
extern void Print_List_Types_macro (List_Types_macro me);
extern void Print_List_Types_TypeName (List_Types_TypeName me);
extern void Print_List_Types_StructType (List_Types_StructType me);
extern void Print_List_Types_BindType (List_Types_BindType me);
extern void Print_List_Types_subtypedef (List_Types_subtypedef me);
extern void Print_List_Types_PointerType (List_Types_PointerType me);
extern void Print_List_Types_EnumType (List_Types_EnumType me);

extern char *Text_Types_Types (Types_Types me);
extern char *Text_Types_includes2 (Types_includes2 me);
extern char *Text_Types_EnumType (Types_EnumType me);
extern char *Text_Types_BindType (Types_BindType me);
extern char *Text_Types_PointerType (Types_PointerType me);
extern char *Text_Types_subtypedef (Types_subtypedef me);
extern char *Text_Types_StructType (Types_StructType me);
extern char *Text_Types_struct_type (Types_struct_type me);
extern char *Text_Types_macro (Types_macro me);
extern char *Text_Types_field (Types_field me);
extern char *Text_Types_TypeName (Types_TypeName me);
extern char *Text_Types_CreateFunction (Types_CreateFunction me);
extern char *Text_Types_Scope (Types_Scope me);
extern char *Text_List_Types_struct_type (List_Types_struct_type me);
extern char *Text_List_Types_field (List_Types_field me);
extern char *Text_List_Types_CreateFunction (List_Types_CreateFunction me);
extern char *Text_List_Types_macro (List_Types_macro me);
extern char *Text_List_Types_TypeName (List_Types_TypeName me);
extern char *Text_List_Types_StructType (List_Types_StructType me);
extern char *Text_List_Types_BindType (List_Types_BindType me);
extern char *Text_List_Types_subtypedef (List_Types_subtypedef me);
extern char *Text_List_Types_PointerType (List_Types_PointerType me);
extern char *Text_List_Types_EnumType (List_Types_EnumType me);



#endif /* _TypesPrint */
