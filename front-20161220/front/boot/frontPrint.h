#ifndef _frontPrint
#define _frontPrint

#include "front.h"

#define PRINT_front_front (front_print_actions.action_front[PRE_ACTION]?front_print_actions.action_front[PRE_ACTION]:Print_front_front)
#define PRINT_front_Import (front_print_actions.action_Import[PRE_ACTION]?front_print_actions.action_Import[PRE_ACTION]:Print_front_Import)
#define PRINT_front_ImportedNonTerminal (front_print_actions.action_ImportedNonTerminal[PRE_ACTION]?front_print_actions.action_ImportedNonTerminal[PRE_ACTION]:Print_front_ImportedNonTerminal)
#define PRINT_front_NonTerminal (front_print_actions.action_NonTerminal[PRE_ACTION]?front_print_actions.action_NonTerminal[PRE_ACTION]:Print_front_NonTerminal)
#define PRINT_front_Super (front_print_actions.action_Super[PRE_ACTION]?front_print_actions.action_Super[PRE_ACTION]:Print_front_Super)
#define PRINT_front_Rhs (front_print_actions.action_Rhs[PRE_ACTION]?front_print_actions.action_Rhs[PRE_ACTION]:Print_front_Rhs)
#define PRINT_front_Alternative (front_print_actions.action_Alternative[PRE_ACTION]?front_print_actions.action_Alternative[PRE_ACTION]:Print_front_Alternative)
#define PRINT_front_Symbol (front_print_actions.action_Symbol[PRE_ACTION]?front_print_actions.action_Symbol[PRE_ACTION]:Print_front_Symbol)
#define PRINT_front_Defining_id (front_print_actions.action_Defining_id[PRE_ACTION]?front_print_actions.action_Defining_id[PRE_ACTION]:Print_front_Defining_id)
#define PRINT_front_Field (front_print_actions.action_Field[PRE_ACTION]?front_print_actions.action_Field[PRE_ACTION]:Print_front_Field)
#define PRINT_front_FieldInit (front_print_actions.action_FieldInit[PRE_ACTION]?front_print_actions.action_FieldInit[PRE_ACTION]:Print_front_FieldInit)
#define PRINT_front_Type (front_print_actions.action_Type[PRE_ACTION]?front_print_actions.action_Type[PRE_ACTION]:Print_front_Type)
#define PRINT_front_Expr (front_print_actions.action_Expr[PRE_ACTION]?front_print_actions.action_Expr[PRE_ACTION]:Print_front_Expr)
#define PRINT_front_Check (front_print_actions.action_Check[PRE_ACTION]?front_print_actions.action_Check[PRE_ACTION]:Print_front_Check)
#define PRINT_front_ScanInfo (front_print_actions.action_ScanInfo[PRE_ACTION]?front_print_actions.action_ScanInfo[PRE_ACTION]:Print_front_ScanInfo)
#define PRINT_front_Defines (front_print_actions.action_Defines[PRE_ACTION]?front_print_actions.action_Defines[PRE_ACTION]:Print_front_Defines)
#define PRINT_front_NameSpace (front_print_actions.action_NameSpace[PRE_ACTION]?front_print_actions.action_NameSpace[PRE_ACTION]:Print_front_NameSpace)
#define PRINT_front_dummy (front_print_actions.action_dummy[PRE_ACTION]?front_print_actions.action_dummy[PRE_ACTION]:Print_front_dummy)
#define PRINT_front_Scope (front_print_actions.action_Scope[PRE_ACTION]?front_print_actions.action_Scope[PRE_ACTION]:Print_front_Scope)
#define PRINT_List_List_front_Symbol (front_print_actions.action_List_List_Symbol[PRE_ACTION]?front_print_actions.action_List_List_Symbol[PRE_ACTION]:Print_List_List_front_Symbol)
#define PRINT_List_front_Expr (front_print_actions.action_List_Expr[PRE_ACTION]?front_print_actions.action_List_Expr[PRE_ACTION]:Print_List_front_Expr)
#define PRINT_List_front_Type (front_print_actions.action_List_Type[PRE_ACTION]?front_print_actions.action_List_Type[PRE_ACTION]:Print_List_front_Type)
#define PRINT_List_front_FieldInit (front_print_actions.action_List_FieldInit[PRE_ACTION]?front_print_actions.action_List_FieldInit[PRE_ACTION]:Print_List_front_FieldInit)
#define PRINT_List_front_And (front_print_actions.action_List_And[PRE_ACTION]?front_print_actions.action_List_And[PRE_ACTION]:Print_List_front_And)
#define PRINT_List_front_Field (front_print_actions.action_List_Field[PRE_ACTION]?front_print_actions.action_List_Field[PRE_ACTION]:Print_List_front_Field)
#define PRINT_List_front_Symbol (front_print_actions.action_List_Symbol[PRE_ACTION]?front_print_actions.action_List_Symbol[PRE_ACTION]:Print_List_front_Symbol)
#define PRINT_List_front_Check (front_print_actions.action_List_Check[PRE_ACTION]?front_print_actions.action_List_Check[PRE_ACTION]:Print_List_front_Check)
#define PRINT_List_front_Or (front_print_actions.action_List_Or[PRE_ACTION]?front_print_actions.action_List_Or[PRE_ACTION]:Print_List_front_Or)
#define PRINT_List_front_Alternative (front_print_actions.action_List_Alternative[PRE_ACTION]?front_print_actions.action_List_Alternative[PRE_ACTION]:Print_List_front_Alternative)
#define PRINT_List_front_Scoping (front_print_actions.action_List_Scoping[PRE_ACTION]?front_print_actions.action_List_Scoping[PRE_ACTION]:Print_List_front_Scoping)
#define PRINT_List_front_ImportedNonTerminal (front_print_actions.action_List_ImportedNonTerminal[PRE_ACTION]?front_print_actions.action_List_ImportedNonTerminal[PRE_ACTION]:Print_List_front_ImportedNonTerminal)
#define PRINT_List_front_NonTerminal (front_print_actions.action_List_NonTerminal[PRE_ACTION]?front_print_actions.action_List_NonTerminal[PRE_ACTION]:Print_List_front_NonTerminal)
#define PRINT_List_front_Import (front_print_actions.action_List_Import[PRE_ACTION]?front_print_actions.action_List_Import[PRE_ACTION]:Print_List_front_Import)
#define PRINT_List_front_NameSpace (front_print_actions.action_List_NameSpace[PRE_ACTION]?front_print_actions.action_List_NameSpace[PRE_ACTION]:Print_List_front_NameSpace)

#define PRINT_front_Scoping (front_print_actions.action_Scoping[PRE_ACTION]?front_print_actions.action_Scoping[PRE_ACTION]:Print_front_Scoping)
#define PRINT_front_And (front_print_actions.action_And[PRE_ACTION]?front_print_actions.action_And[PRE_ACTION]:Print_front_And)
#define PRINT_front_Or (front_print_actions.action_Or[PRE_ACTION]?front_print_actions.action_Or[PRE_ACTION]:Print_front_Or)
#define PRINT_front_Define (front_print_actions.action_Define[PRE_ACTION]?front_print_actions.action_Define[PRE_ACTION]:Print_front_Define)
#define PRINT_front_Alternator (front_print_actions.action_Alternator[PRE_ACTION]?front_print_actions.action_Alternator[PRE_ACTION]:Print_front_Alternator)
#define PRINT_front_NameOrField (front_print_actions.action_NameOrField[PRE_ACTION]?front_print_actions.action_NameOrField[PRE_ACTION]:Print_front_NameOrField)

extern void Print_front_front (front_front me);
extern void Print_front_Import (front_Import me);
extern void Print_front_ImportedNonTerminal (front_ImportedNonTerminal me);
extern void Print_front_NonTerminal (front_NonTerminal me);
extern void Print_front_Super (front_Super me);
extern void Print_front_Rhs (front_Rhs me);
extern void Print_front_Alternative (front_Alternative me);
extern void Print_front_Symbol (front_Symbol me);
extern void Print_front_Defining_id (front_Defining_id me);
extern void Print_front_Field (front_Field me);
extern void Print_front_FieldInit (front_FieldInit me);
extern void Print_front_Type (front_Type me);
extern void Print_front_Expr (front_Expr me);
extern void Print_front_Check (front_Check me);
extern void Print_front_ScanInfo (front_ScanInfo me);
extern void Print_front_Defines (front_Defines me);
extern void Print_front_NameSpace (front_NameSpace me);
extern void Print_front_dummy (front_dummy me);
extern void Print_front_Scope (front_Scope me);
extern void Print_List_List_front_Symbol (List_List_front_Symbol me);
extern void Print_List_front_Expr (List_front_Expr me);
extern void Print_List_front_Type (List_front_Type me);
extern void Print_List_front_FieldInit (List_front_FieldInit me);
extern void Print_List_front_And (List_front_And me);
extern void Print_List_front_Field (List_front_Field me);
extern void Print_List_front_Symbol (List_front_Symbol me);
extern void Print_List_front_Check (List_front_Check me);
extern void Print_List_front_Or (List_front_Or me);
extern void Print_List_front_Alternative (List_front_Alternative me);
extern void Print_List_front_Scoping (List_front_Scoping me);
extern void Print_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal me);
extern void Print_List_front_NonTerminal (List_front_NonTerminal me);
extern void Print_List_front_Import (List_front_Import me);
extern void Print_List_front_NameSpace (List_front_NameSpace me);

extern char *Text_front_front (front_front me);
extern char *Text_front_Import (front_Import me);
extern char *Text_front_ImportedNonTerminal (front_ImportedNonTerminal me);
extern char *Text_front_NonTerminal (front_NonTerminal me);
extern char *Text_front_Super (front_Super me);
extern char *Text_front_Rhs (front_Rhs me);
extern char *Text_front_Alternative (front_Alternative me);
extern char *Text_front_Symbol (front_Symbol me);
extern char *Text_front_Defining_id (front_Defining_id me);
extern char *Text_front_Field (front_Field me);
extern char *Text_front_FieldInit (front_FieldInit me);
extern char *Text_front_Type (front_Type me);
extern char *Text_front_Expr (front_Expr me);
extern char *Text_front_Check (front_Check me);
extern char *Text_front_ScanInfo (front_ScanInfo me);
extern char *Text_front_Defines (front_Defines me);
extern char *Text_front_NameSpace (front_NameSpace me);
extern char *Text_front_dummy (front_dummy me);
extern char *Text_front_Scope (front_Scope me);
extern char *Text_List_List_front_Symbol (List_List_front_Symbol me);
extern char *Text_List_front_Expr (List_front_Expr me);
extern char *Text_List_front_Type (List_front_Type me);
extern char *Text_List_front_FieldInit (List_front_FieldInit me);
extern char *Text_List_front_And (List_front_And me);
extern char *Text_List_front_Field (List_front_Field me);
extern char *Text_List_front_Symbol (List_front_Symbol me);
extern char *Text_List_front_Check (List_front_Check me);
extern char *Text_List_front_Or (List_front_Or me);
extern char *Text_List_front_Alternative (List_front_Alternative me);
extern char *Text_List_front_Scoping (List_front_Scoping me);
extern char *Text_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal me);
extern char *Text_List_front_NonTerminal (List_front_NonTerminal me);
extern char *Text_List_front_Import (List_front_Import me);
extern char *Text_List_front_NameSpace (List_front_NameSpace me);

extern void Print_front_Scoping (front_Scoping me);
extern void Print_front_And (front_And me);
extern void Print_front_Or (front_Or me);
extern void Print_front_Define (front_Define me);
extern void Print_front_Alternator (front_Alternator me);
extern void Print_front_NameOrField (front_NameOrField me);

extern char *Text_front_Scoping (front_Scoping me);
extern char *Text_front_And (front_And me);
extern char *Text_front_Or (front_Or me);
extern char *Text_front_Define (front_Define me);
extern char *Text_front_Alternator (front_Alternator me);
extern char *Text_front_NameOrField (front_NameOrField me);

#endif /* _frontPrint */
