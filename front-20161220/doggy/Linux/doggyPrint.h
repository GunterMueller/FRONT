#ifndef _doggyPrint
#define _doggyPrint

#include "doggy.h"

#define PRINT_doggy_doggy (doggy_print_actions.action_doggy[PRE_ACTION]?doggy_print_actions.action_doggy[PRE_ACTION]:Print_doggy_doggy)
#define PRINT_doggy_Typedef (doggy_print_actions.action_Typedef[PRE_ACTION]?doggy_print_actions.action_Typedef[PRE_ACTION]:Print_doggy_Typedef)
#define PRINT_doggy_FunctionDef (doggy_print_actions.action_FunctionDef[PRE_ACTION]?doggy_print_actions.action_FunctionDef[PRE_ACTION]:Print_doggy_FunctionDef)
#define PRINT_doggy_machine_description (doggy_print_actions.action_machine_description[PRE_ACTION]?doggy_print_actions.action_machine_description[PRE_ACTION]:Print_doggy_machine_description)
#define PRINT_doggy_Operation_def (doggy_print_actions.action_Operation_def[PRE_ACTION]?doggy_print_actions.action_Operation_def[PRE_ACTION]:Print_doggy_Operation_def)
#define PRINT_doggy_Attributes (doggy_print_actions.action_Attributes[PRE_ACTION]?doggy_print_actions.action_Attributes[PRE_ACTION]:Print_doggy_Attributes)
#define PRINT_doggy_Attribute (doggy_print_actions.action_Attribute[PRE_ACTION]?doggy_print_actions.action_Attribute[PRE_ACTION]:Print_doggy_Attribute)
#define PRINT_doggy_Section (doggy_print_actions.action_Section[PRE_ACTION]?doggy_print_actions.action_Section[PRE_ACTION]:Print_doggy_Section)
#define PRINT_doggy_Rule (doggy_print_actions.action_Rule[PRE_ACTION]?doggy_print_actions.action_Rule[PRE_ACTION]:Print_doggy_Rule)
#define PRINT_doggy_Lhs (doggy_print_actions.action_Lhs[PRE_ACTION]?doggy_print_actions.action_Lhs[PRE_ACTION]:Print_doggy_Lhs)
#define PRINT_doggy_Func (doggy_print_actions.action_Func[PRE_ACTION]?doggy_print_actions.action_Func[PRE_ACTION]:Print_doggy_Func)
#define PRINT_doggy_FuncRule (doggy_print_actions.action_FuncRule[PRE_ACTION]?doggy_print_actions.action_FuncRule[PRE_ACTION]:Print_doggy_FuncRule)
#define PRINT_doggy_Argument (doggy_print_actions.action_Argument[PRE_ACTION]?doggy_print_actions.action_Argument[PRE_ACTION]:Print_doggy_Argument)
#define PRINT_doggy_ArgPat (doggy_print_actions.action_ArgPat[PRE_ACTION]?doggy_print_actions.action_ArgPat[PRE_ACTION]:Print_doggy_ArgPat)
#define PRINT_doggy_Pattern (doggy_print_actions.action_Pattern[PRE_ACTION]?doggy_print_actions.action_Pattern[PRE_ACTION]:Print_doggy_Pattern)
#define PRINT_doggy_Rhs (doggy_print_actions.action_Rhs[PRE_ACTION]?doggy_print_actions.action_Rhs[PRE_ACTION]:Print_doggy_Rhs)
#define PRINT_doggy_Guard (doggy_print_actions.action_Guard[PRE_ACTION]?doggy_print_actions.action_Guard[PRE_ACTION]:Print_doggy_Guard)
#define PRINT_doggy_ExprSeq (doggy_print_actions.action_ExprSeq[PRE_ACTION]?doggy_print_actions.action_ExprSeq[PRE_ACTION]:Print_doggy_ExprSeq)
#define PRINT_doggy_Wherepart (doggy_print_actions.action_Wherepart[PRE_ACTION]?doggy_print_actions.action_Wherepart[PRE_ACTION]:Print_doggy_Wherepart)
#define PRINT_doggy_Applied_operation (doggy_print_actions.action_Applied_operation[PRE_ACTION]?doggy_print_actions.action_Applied_operation[PRE_ACTION]:Print_doggy_Applied_operation)
#define PRINT_doggy_Applied_formal (doggy_print_actions.action_Applied_formal[PRE_ACTION]?doggy_print_actions.action_Applied_formal[PRE_ACTION]:Print_doggy_Applied_formal)
#define PRINT_doggy_Expr (doggy_print_actions.action_Expr[PRE_ACTION]?doggy_print_actions.action_Expr[PRE_ACTION]:Print_doggy_Expr)
#define PRINT_doggy_Constant (doggy_print_actions.action_Constant[PRE_ACTION]?doggy_print_actions.action_Constant[PRE_ACTION]:Print_doggy_Constant)
#define PRINT_doggy_Definition (doggy_print_actions.action_Definition[PRE_ACTION]?doggy_print_actions.action_Definition[PRE_ACTION]:Print_doggy_Definition)
#define PRINT_doggy_Type (doggy_print_actions.action_Type[PRE_ACTION]?doggy_print_actions.action_Type[PRE_ACTION]:Print_doggy_Type)
#define PRINT_doggy_Num (doggy_print_actions.action_Num[PRE_ACTION]?doggy_print_actions.action_Num[PRE_ACTION]:Print_doggy_Num)
#define PRINT_doggy_IdInt (doggy_print_actions.action_IdInt[PRE_ACTION]?doggy_print_actions.action_IdInt[PRE_ACTION]:Print_doggy_IdInt)
#define PRINT_doggy_Path (doggy_print_actions.action_Path[PRE_ACTION]?doggy_print_actions.action_Path[PRE_ACTION]:Print_doggy_Path)
#define PRINT_doggy_ActualOp (doggy_print_actions.action_ActualOp[PRE_ACTION]?doggy_print_actions.action_ActualOp[PRE_ACTION]:Print_doggy_ActualOp)
#define PRINT_doggy_TypePair (doggy_print_actions.action_TypePair[PRE_ACTION]?doggy_print_actions.action_TypePair[PRE_ACTION]:Print_doggy_TypePair)
#define PRINT_doggy_Opat (doggy_print_actions.action_Opat[PRE_ACTION]?doggy_print_actions.action_Opat[PRE_ACTION]:Print_doggy_Opat)
#define PRINT_doggy_Format (doggy_print_actions.action_Format[PRE_ACTION]?doggy_print_actions.action_Format[PRE_ACTION]:Print_doggy_Format)
#define PRINT_doggy_dummy_type (doggy_print_actions.action_dummy_type[PRE_ACTION]?doggy_print_actions.action_dummy_type[PRE_ACTION]:Print_doggy_dummy_type)
#define PRINT_doggy_Scope (doggy_print_actions.action_Scope[PRE_ACTION]?doggy_print_actions.action_Scope[PRE_ACTION]:Print_doggy_Scope)
#define PRINT_List_doggy_Num (doggy_print_actions.action_List_Num[PRE_ACTION]?doggy_print_actions.action_List_Num[PRE_ACTION]:Print_List_doggy_Num)
#define PRINT_List_List_doggy_TypePair (doggy_print_actions.action_List_List_TypePair[PRE_ACTION]?doggy_print_actions.action_List_List_TypePair[PRE_ACTION]:Print_List_List_doggy_TypePair)
#define PRINT_List_doggy_TypePair (doggy_print_actions.action_List_TypePair[PRE_ACTION]?doggy_print_actions.action_List_TypePair[PRE_ACTION]:Print_List_doggy_TypePair)
#define PRINT_List_doggy_ActualOp (doggy_print_actions.action_List_ActualOp[PRE_ACTION]?doggy_print_actions.action_List_ActualOp[PRE_ACTION]:Print_List_doggy_ActualOp)
#define PRINT_List_List_doggy_Type (doggy_print_actions.action_List_List_Type[PRE_ACTION]?doggy_print_actions.action_List_List_Type[PRE_ACTION]:Print_List_List_doggy_Type)
#define PRINT_List_doggy_Operator (doggy_print_actions.action_List_Operator[PRE_ACTION]?doggy_print_actions.action_List_Operator[PRE_ACTION]:Print_List_doggy_Operator)
#define PRINT_List_doggy_Definition (doggy_print_actions.action_List_Definition[PRE_ACTION]?doggy_print_actions.action_List_Definition[PRE_ACTION]:Print_List_doggy_Definition)
#define PRINT_List_doggy_Expr (doggy_print_actions.action_List_Expr[PRE_ACTION]?doggy_print_actions.action_List_Expr[PRE_ACTION]:Print_List_doggy_Expr)
#define PRINT_List_doggy_Guard (doggy_print_actions.action_List_Guard[PRE_ACTION]?doggy_print_actions.action_List_Guard[PRE_ACTION]:Print_List_doggy_Guard)
#define PRINT_List_doggy_Pattern (doggy_print_actions.action_List_Pattern[PRE_ACTION]?doggy_print_actions.action_List_Pattern[PRE_ACTION]:Print_List_doggy_Pattern)
#define PRINT_List_doggy_Argument (doggy_print_actions.action_List_Argument[PRE_ACTION]?doggy_print_actions.action_List_Argument[PRE_ACTION]:Print_List_doggy_Argument)
#define PRINT_List_doggy_FuncRule (doggy_print_actions.action_List_FuncRule[PRE_ACTION]?doggy_print_actions.action_List_FuncRule[PRE_ACTION]:Print_List_doggy_FuncRule)
#define PRINT_List_doggy_Attribute (doggy_print_actions.action_List_Attribute[PRE_ACTION]?doggy_print_actions.action_List_Attribute[PRE_ACTION]:Print_List_doggy_Attribute)
#define PRINT_List_doggy_Property (doggy_print_actions.action_List_Property[PRE_ACTION]?doggy_print_actions.action_List_Property[PRE_ACTION]:Print_List_doggy_Property)
#define PRINT_List_doggy_Applied_formal (doggy_print_actions.action_List_Applied_formal[PRE_ACTION]?doggy_print_actions.action_List_Applied_formal[PRE_ACTION]:Print_List_doggy_Applied_formal)
#define PRINT_List_doggy_Operation_def (doggy_print_actions.action_List_Operation_def[PRE_ACTION]?doggy_print_actions.action_List_Operation_def[PRE_ACTION]:Print_List_doggy_Operation_def)
#define PRINT_List_doggy_Type (doggy_print_actions.action_List_Type[PRE_ACTION]?doggy_print_actions.action_List_Type[PRE_ACTION]:Print_List_doggy_Type)
#define PRINT_List_doggy_Rule (doggy_print_actions.action_List_Rule[PRE_ACTION]?doggy_print_actions.action_List_Rule[PRE_ACTION]:Print_List_doggy_Rule)
#define PRINT_List_doggy_Func (doggy_print_actions.action_List_Func[PRE_ACTION]?doggy_print_actions.action_List_Func[PRE_ACTION]:Print_List_doggy_Func)
#define PRINT_List_doggy_Section (doggy_print_actions.action_List_Section[PRE_ACTION]?doggy_print_actions.action_List_Section[PRE_ACTION]:Print_List_doggy_Section)
#define PRINT_List_doggy_FunctionDef (doggy_print_actions.action_List_FunctionDef[PRE_ACTION]?doggy_print_actions.action_List_FunctionDef[PRE_ACTION]:Print_List_doggy_FunctionDef)
#define PRINT_List_doggy_Typedef (doggy_print_actions.action_List_Typedef[PRE_ACTION]?doggy_print_actions.action_List_Typedef[PRE_ACTION]:Print_List_doggy_Typedef)

#define PRINT_doggy_Operator (doggy_print_actions.action_Operator[PRE_ACTION]?doggy_print_actions.action_Operator[PRE_ACTION]:Print_doggy_Operator)
#define PRINT_doggy_MonOp (doggy_print_actions.action_MonOp[PRE_ACTION]?doggy_print_actions.action_MonOp[PRE_ACTION]:Print_doggy_MonOp)
#define PRINT_doggy_Property (doggy_print_actions.action_Property[PRE_ACTION]?doggy_print_actions.action_Property[PRE_ACTION]:Print_doggy_Property)

extern void Print_doggy_doggy (doggy_doggy me);
extern void Print_doggy_Typedef (doggy_Typedef me);
extern void Print_doggy_FunctionDef (doggy_FunctionDef me);
extern void Print_doggy_machine_description (doggy_machine_description me);
extern void Print_doggy_Operation_def (doggy_Operation_def me);
extern void Print_doggy_Attributes (doggy_Attributes me);
extern void Print_doggy_Attribute (doggy_Attribute me);
extern void Print_doggy_Section (doggy_Section me);
extern void Print_doggy_Rule (doggy_Rule me);
extern void Print_doggy_Lhs (doggy_Lhs me);
extern void Print_doggy_Func (doggy_Func me);
extern void Print_doggy_FuncRule (doggy_FuncRule me);
extern void Print_doggy_Argument (doggy_Argument me);
extern void Print_doggy_ArgPat (doggy_ArgPat me);
extern void Print_doggy_Pattern (doggy_Pattern me);
extern void Print_doggy_Rhs (doggy_Rhs me);
extern void Print_doggy_Guard (doggy_Guard me);
extern void Print_doggy_ExprSeq (doggy_ExprSeq me);
extern void Print_doggy_Wherepart (doggy_Wherepart me);
extern void Print_doggy_Applied_operation (doggy_Applied_operation me);
extern void Print_doggy_Applied_formal (doggy_Applied_formal me);
extern void Print_doggy_Expr (doggy_Expr me);
extern void Print_doggy_Constant (doggy_Constant me);
extern void Print_doggy_Definition (doggy_Definition me);
extern void Print_doggy_Type (doggy_Type me);
extern void Print_doggy_Num (doggy_Num me);
extern void Print_doggy_IdInt (doggy_IdInt me);
extern void Print_doggy_Path (doggy_Path me);
extern void Print_doggy_ActualOp (doggy_ActualOp me);
extern void Print_doggy_TypePair (doggy_TypePair me);
extern void Print_doggy_Opat (doggy_Opat me);
extern void Print_doggy_Format (doggy_Format me);
extern void Print_doggy_dummy_type (doggy_dummy_type me);
extern void Print_doggy_Scope (doggy_Scope me);
extern void Print_List_doggy_Num (List_doggy_Num me);
extern void Print_List_List_doggy_TypePair (List_List_doggy_TypePair me);
extern void Print_List_doggy_TypePair (List_doggy_TypePair me);
extern void Print_List_doggy_ActualOp (List_doggy_ActualOp me);
extern void Print_List_List_doggy_Type (List_List_doggy_Type me);
extern void Print_List_doggy_Operator (List_doggy_Operator me);
extern void Print_List_doggy_Definition (List_doggy_Definition me);
extern void Print_List_doggy_Expr (List_doggy_Expr me);
extern void Print_List_doggy_Guard (List_doggy_Guard me);
extern void Print_List_doggy_Pattern (List_doggy_Pattern me);
extern void Print_List_doggy_Argument (List_doggy_Argument me);
extern void Print_List_doggy_FuncRule (List_doggy_FuncRule me);
extern void Print_List_doggy_Attribute (List_doggy_Attribute me);
extern void Print_List_doggy_Property (List_doggy_Property me);
extern void Print_List_doggy_Applied_formal (List_doggy_Applied_formal me);
extern void Print_List_doggy_Operation_def (List_doggy_Operation_def me);
extern void Print_List_doggy_Type (List_doggy_Type me);
extern void Print_List_doggy_Rule (List_doggy_Rule me);
extern void Print_List_doggy_Func (List_doggy_Func me);
extern void Print_List_doggy_Section (List_doggy_Section me);
extern void Print_List_doggy_FunctionDef (List_doggy_FunctionDef me);
extern void Print_List_doggy_Typedef (List_doggy_Typedef me);

extern char *Text_doggy_doggy (doggy_doggy me);
extern char *Text_doggy_Typedef (doggy_Typedef me);
extern char *Text_doggy_FunctionDef (doggy_FunctionDef me);
extern char *Text_doggy_machine_description (doggy_machine_description me);
extern char *Text_doggy_Operation_def (doggy_Operation_def me);
extern char *Text_doggy_Attributes (doggy_Attributes me);
extern char *Text_doggy_Attribute (doggy_Attribute me);
extern char *Text_doggy_Section (doggy_Section me);
extern char *Text_doggy_Rule (doggy_Rule me);
extern char *Text_doggy_Lhs (doggy_Lhs me);
extern char *Text_doggy_Func (doggy_Func me);
extern char *Text_doggy_FuncRule (doggy_FuncRule me);
extern char *Text_doggy_Argument (doggy_Argument me);
extern char *Text_doggy_ArgPat (doggy_ArgPat me);
extern char *Text_doggy_Pattern (doggy_Pattern me);
extern char *Text_doggy_Rhs (doggy_Rhs me);
extern char *Text_doggy_Guard (doggy_Guard me);
extern char *Text_doggy_ExprSeq (doggy_ExprSeq me);
extern char *Text_doggy_Wherepart (doggy_Wherepart me);
extern char *Text_doggy_Applied_operation (doggy_Applied_operation me);
extern char *Text_doggy_Applied_formal (doggy_Applied_formal me);
extern char *Text_doggy_Expr (doggy_Expr me);
extern char *Text_doggy_Constant (doggy_Constant me);
extern char *Text_doggy_Definition (doggy_Definition me);
extern char *Text_doggy_Type (doggy_Type me);
extern char *Text_doggy_Num (doggy_Num me);
extern char *Text_doggy_IdInt (doggy_IdInt me);
extern char *Text_doggy_Path (doggy_Path me);
extern char *Text_doggy_ActualOp (doggy_ActualOp me);
extern char *Text_doggy_TypePair (doggy_TypePair me);
extern char *Text_doggy_Opat (doggy_Opat me);
extern char *Text_doggy_Format (doggy_Format me);
extern char *Text_doggy_dummy_type (doggy_dummy_type me);
extern char *Text_doggy_Scope (doggy_Scope me);
extern char *Text_List_doggy_Num (List_doggy_Num me);
extern char *Text_List_List_doggy_TypePair (List_List_doggy_TypePair me);
extern char *Text_List_doggy_TypePair (List_doggy_TypePair me);
extern char *Text_List_doggy_ActualOp (List_doggy_ActualOp me);
extern char *Text_List_List_doggy_Type (List_List_doggy_Type me);
extern char *Text_List_doggy_Operator (List_doggy_Operator me);
extern char *Text_List_doggy_Definition (List_doggy_Definition me);
extern char *Text_List_doggy_Expr (List_doggy_Expr me);
extern char *Text_List_doggy_Guard (List_doggy_Guard me);
extern char *Text_List_doggy_Pattern (List_doggy_Pattern me);
extern char *Text_List_doggy_Argument (List_doggy_Argument me);
extern char *Text_List_doggy_FuncRule (List_doggy_FuncRule me);
extern char *Text_List_doggy_Attribute (List_doggy_Attribute me);
extern char *Text_List_doggy_Property (List_doggy_Property me);
extern char *Text_List_doggy_Applied_formal (List_doggy_Applied_formal me);
extern char *Text_List_doggy_Operation_def (List_doggy_Operation_def me);
extern char *Text_List_doggy_Type (List_doggy_Type me);
extern char *Text_List_doggy_Rule (List_doggy_Rule me);
extern char *Text_List_doggy_Func (List_doggy_Func me);
extern char *Text_List_doggy_Section (List_doggy_Section me);
extern char *Text_List_doggy_FunctionDef (List_doggy_FunctionDef me);
extern char *Text_List_doggy_Typedef (List_doggy_Typedef me);

extern void Print_doggy_Operator (doggy_Operator me);
extern void Print_doggy_MonOp (doggy_MonOp me);
extern void Print_doggy_Property (doggy_Property me);

extern char *Text_doggy_Operator (doggy_Operator me);
extern char *Text_doggy_MonOp (doggy_MonOp me);
extern char *Text_doggy_Property (doggy_Property me);

#endif /* _doggyPrint */
