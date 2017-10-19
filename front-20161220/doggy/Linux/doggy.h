#ifndef _doggy
#define _doggy

#include <stdarg.h>
#include <stddef.h>
#include <front/basic_types.h>

typedef enum {
  doggy_ExtFunc_kind,
  doggy_ExtVar_kind
} doggy_FunctionDef_tag;
extern char *doggy_FunctionDef_tag_names[];
#define NUM_doggy_FunctionDef_tag 2

typedef enum {
  doggy_IdAttr_kind,
  doggy_OpAttr_kind,
  doggy_IntAttr_kind
} doggy_Attribute_tag;
extern char *doggy_Attribute_tag_names[];
#define NUM_doggy_Attribute_tag 3

typedef enum {
  doggy_FuncSection_kind,
  doggy_RuleSection_kind
} doggy_Section_tag;
extern char *doggy_Section_tag_names[];
#define NUM_doggy_Section_tag 2

typedef enum {
  doggy_LabeledLhs_kind,
  doggy_UnLabeledLhs_kind
} doggy_Lhs_tag;
extern char *doggy_Lhs_tag_names[];
#define NUM_doggy_Lhs_tag 2

typedef enum {
  doggy_TypedArg_kind,
  doggy_UnTypedArg_kind
} doggy_Argument_tag;
extern char *doggy_Argument_tag_names[];
#define NUM_doggy_Argument_tag 2

typedef enum {
  doggy_PatArg_kind,
  doggy_SetArg_kind
} doggy_ArgPat_tag;
extern char *doggy_ArgPat_tag_names[];
#define NUM_doggy_ArgPat_tag 2

typedef enum {
  doggy_TypedPattern_kind,
  doggy_ConsPattern_kind,
  doggy_DefPattern_kind,
  doggy_IdentPattern_kind,
  doggy_OpPattern_kind,
  doggy_ConstPattern_kind,
  doggy_NullPattern_kind,
  doggy_DontCarePattern_kind
} doggy_Pattern_tag;
extern char *doggy_Pattern_tag_names[];
#define NUM_doggy_Pattern_tag 8

typedef enum {
  doggy_PlainRhs_kind,
  doggy_BlockRhs_kind
} doggy_Rhs_tag;
extern char *doggy_Rhs_tag_names[];
#define NUM_doggy_Rhs_tag 2

typedef enum {
  doggy_RhsGuard_kind,
  doggy_ExprGuard_kind
} doggy_Guard_tag;
extern char *doggy_Guard_tag_names[];
#define NUM_doggy_Guard_tag 2

typedef enum {
  doggy_OneExpr_kind,
  doggy_MoreExprs_kind
} doggy_ExprSeq_tag;
extern char *doggy_ExprSeq_tag_names[];
#define NUM_doggy_ExprSeq_tag 2

typedef enum {
  doggy_AnyOp_kind,
  doggy_AppliedOp_kind,
  doggy_OpSet_kind
} doggy_Applied_operation_tag;
extern char *doggy_Applied_operation_tag_names[];
#define NUM_doggy_Applied_operation_tag 3

typedef enum {
  doggy_BinExpr_kind,
  doggy_ConsExpr_kind,
  doggy_IdentExpr_kind,
  doggy_IfExpr_kind,
  doggy_ConstExpr_kind,
  doggy_Operation_kind,
  doggy_ParExpr_kind,
  doggy_MonExpr_kind
} doggy_Expr_tag;
extern char *doggy_Expr_tag_names[];
#define NUM_doggy_Expr_tag 8

typedef enum {
  doggy_IntConst_kind,
  doggy_BoolConst_kind,
  doggy_StringConst_kind,
  doggy_NullConst_kind
} doggy_Constant_tag;
extern char *doggy_Constant_tag_names[];
#define NUM_doggy_Constant_tag 4

typedef enum {
  doggy_CandOp,
  doggy_CorOp,
  doggy_XorOp,
  doggy_EqOp,
  doggy_NeqOp,
  doggy_LEOp,
  doggy_GEOp,
  doggy_LTOp,
  doggy_GTOp,
  doggy_SLOp,
  doggy_SROp,
  doggy_DivOp,
  doggy_ModOp,
  doggy_MulOp,
  doggy_AndOp,
  doggy_AddOp,
  doggy_SubOp
} doggy_Operator;
extern char *doggy_Operator_names[];
#define NUM_doggy_Operator 17

typedef enum {
  doggy_NotOp,
  doggy_NegOp,
  doggy_AddrOp,
  doggy_DerefOp,
  doggy_PlusOp,
  doggy_MinOp
} doggy_MonOp;
extern char *doggy_MonOp_names[];
#define NUM_doggy_MonOp 6

typedef enum {
  doggy_EdgeType_kind,
  doggy_TupleType_kind,
  doggy_IdentType_kind,
  doggy_OprType_kind,
  doggy_PointerType_kind,
  doggy_RangeType_kind,
  doggy_FRangeType_kind
} doggy_Type_tag;
extern char *doggy_Type_tag_names[];
#define NUM_doggy_Type_tag 7

typedef Bool doggy_Property;

typedef enum {
  doggy_IsId_kind,
  doggy_IsInt_kind
} doggy_IdInt_tag;
extern char *doggy_IdInt_tag_names[];
#define NUM_doggy_IdInt_tag 2

typedef enum {
  doggy_OpSetScope_kind,
  doggy_AppliedOpScope_kind,
  doggy_ExprGuardScope_kind,
  doggy_RhsGuardScope_kind,
  doggy_FuncRuleScope_kind,
  doggy_RuleScope_kind,
  doggy_machine_descriptionScope_kind
} doggy_Scope_tag;
extern char *doggy_Scope_tag_names[];
#define NUM_doggy_Scope_tag 7

#ifndef DEF_TYPE_doggy_doggy
#define DEF_TYPE_doggy_doggy
typedef struct s_doggy_doggy    *doggy_doggy;
#endif

#ifndef DEF_TYPE_doggy_Typedef
#define DEF_TYPE_doggy_Typedef
typedef struct s_doggy_Typedef  *doggy_Typedef;
#endif

#ifndef DEF_TYPE_doggy_FunctionDef
#define DEF_TYPE_doggy_FunctionDef
typedef struct s_doggy_FunctionDef      *doggy_FunctionDef;
typedef doggy_FunctionDef doggy_ExtVar;
typedef doggy_FunctionDef doggy_ExtFunc;
#endif

#ifndef DEF_TYPE_doggy_machine_description
#define DEF_TYPE_doggy_machine_description
typedef struct s_doggy_machine_description      *doggy_machine_description;
#endif

#ifndef DEF_TYPE_doggy_Operation_def
#define DEF_TYPE_doggy_Operation_def
typedef struct s_doggy_Operation_def    *doggy_Operation_def;
#endif

#ifndef DEF_TYPE_doggy_Attributes
#define DEF_TYPE_doggy_Attributes
typedef struct s_doggy_Attributes       *doggy_Attributes;
#endif

#ifndef DEF_TYPE_doggy_Attribute
#define DEF_TYPE_doggy_Attribute
typedef struct s_doggy_Attribute        *doggy_Attribute;
typedef doggy_Attribute doggy_IntAttr;
typedef doggy_Attribute doggy_OpAttr;
typedef doggy_Attribute doggy_IdAttr;
#endif

#ifndef DEF_TYPE_doggy_Section
#define DEF_TYPE_doggy_Section
typedef struct s_doggy_Section  *doggy_Section;
typedef doggy_Section doggy_RuleSection;
typedef doggy_Section doggy_FuncSection;
#endif

#ifndef DEF_TYPE_doggy_Rule
#define DEF_TYPE_doggy_Rule
typedef struct s_doggy_Rule     *doggy_Rule;
#endif

#ifndef DEF_TYPE_doggy_Lhs
#define DEF_TYPE_doggy_Lhs
typedef struct s_doggy_Lhs      *doggy_Lhs;
typedef doggy_Lhs doggy_UnLabeledLhs;
typedef doggy_Lhs doggy_LabeledLhs;
#endif

#ifndef DEF_TYPE_doggy_Func
#define DEF_TYPE_doggy_Func
typedef struct s_doggy_Func     *doggy_Func;
#endif

#ifndef DEF_TYPE_doggy_FuncRule
#define DEF_TYPE_doggy_FuncRule
typedef struct s_doggy_FuncRule *doggy_FuncRule;
#endif

#ifndef DEF_TYPE_doggy_Argument
#define DEF_TYPE_doggy_Argument
typedef struct s_doggy_Argument *doggy_Argument;
typedef doggy_Argument doggy_UnTypedArg;
typedef doggy_Argument doggy_TypedArg;
#endif

#ifndef DEF_TYPE_doggy_ArgPat
#define DEF_TYPE_doggy_ArgPat
typedef struct s_doggy_ArgPat   *doggy_ArgPat;
typedef doggy_ArgPat doggy_SetArg;
typedef doggy_ArgPat doggy_PatArg;
#endif

#ifndef DEF_TYPE_doggy_Pattern
#define DEF_TYPE_doggy_Pattern
typedef struct s_doggy_Pattern  *doggy_Pattern;
typedef doggy_Pattern doggy_DontCarePattern;
typedef doggy_Pattern doggy_NullPattern;
typedef doggy_Pattern doggy_ConstPattern;
typedef doggy_Pattern doggy_OpPattern;
typedef doggy_Pattern doggy_BasicPattern;
typedef doggy_Pattern doggy_IdentPattern;
typedef doggy_Pattern doggy_DefPattern;
typedef doggy_Pattern doggy_ConsPattern;
typedef doggy_Pattern doggy_TypedPattern;
#endif

#ifndef DEF_TYPE_doggy_Rhs
#define DEF_TYPE_doggy_Rhs
typedef struct s_doggy_Rhs      *doggy_Rhs;
typedef doggy_Rhs doggy_BlockRhs;
typedef doggy_Rhs doggy_PlainRhs;
#endif

#ifndef DEF_TYPE_doggy_Guard
#define DEF_TYPE_doggy_Guard
typedef struct s_doggy_Guard    *doggy_Guard;
typedef doggy_Guard doggy_ExprGuard;
typedef doggy_Guard doggy_RhsGuard;
#endif

#ifndef DEF_TYPE_doggy_ExprSeq
#define DEF_TYPE_doggy_ExprSeq
typedef struct s_doggy_ExprSeq  *doggy_ExprSeq;
typedef doggy_ExprSeq doggy_MoreExprs;
typedef doggy_ExprSeq doggy_OneExpr;
#endif

#ifndef DEF_TYPE_doggy_Wherepart
#define DEF_TYPE_doggy_Wherepart
typedef struct s_doggy_Wherepart        *doggy_Wherepart;
#endif

#ifndef DEF_TYPE_doggy_Applied_operation
#define DEF_TYPE_doggy_Applied_operation
typedef struct s_doggy_Applied_operation        *doggy_Applied_operation;
typedef doggy_Applied_operation doggy_OpSet;
typedef doggy_Applied_operation doggy_AppliedOp;
typedef doggy_Applied_operation doggy_AnyOp;
#endif

#ifndef DEF_TYPE_doggy_Applied_formal
#define DEF_TYPE_doggy_Applied_formal
typedef struct s_doggy_Applied_formal   *doggy_Applied_formal;
#endif

#ifndef DEF_TYPE_doggy_Expr
#define DEF_TYPE_doggy_Expr
typedef struct s_doggy_Expr     *doggy_Expr;
typedef doggy_Expr doggy_MonExpr;
typedef doggy_Expr doggy_ParExpr;
typedef doggy_Expr doggy_Operation;
typedef doggy_Expr doggy_ConstExpr;
typedef doggy_Expr doggy_IfExpr;
typedef doggy_Expr doggy_IdentExpr;
typedef doggy_Expr doggy_SimpleExpr;
typedef doggy_Expr doggy_ConsExpr;
typedef doggy_Expr doggy_BinExpr;
#endif

#ifndef DEF_TYPE_doggy_Constant
#define DEF_TYPE_doggy_Constant
typedef struct s_doggy_Constant *doggy_Constant;
typedef doggy_Constant doggy_NullConst;
typedef doggy_Constant doggy_StringConst;
typedef doggy_Constant doggy_BoolConst;
typedef doggy_Constant doggy_IntConst;
#endif

#ifndef DEF_TYPE_doggy_Definition
#define DEF_TYPE_doggy_Definition
typedef struct s_doggy_Definition       *doggy_Definition;
#endif

#ifndef DEF_TYPE_doggy_Type
#define DEF_TYPE_doggy_Type
typedef struct s_doggy_Type     *doggy_Type;
typedef doggy_Type doggy_FRangeType;
typedef doggy_Type doggy_RangeType;
typedef doggy_Type doggy_PointerType;
typedef doggy_Type doggy_OprType;
typedef doggy_Type doggy_IdentType;
typedef doggy_Type doggy_BasicType;
typedef doggy_Type doggy_TupleType;
typedef doggy_Type doggy_EdgeType;
#endif

#ifndef DEF_TYPE_doggy_Num
#define DEF_TYPE_doggy_Num
typedef struct s_doggy_Num      *doggy_Num;
#endif

#ifndef DEF_TYPE_doggy_IdInt
#define DEF_TYPE_doggy_IdInt
typedef struct s_doggy_IdInt    *doggy_IdInt;
typedef doggy_IdInt doggy_IsInt;
typedef doggy_IdInt doggy_IsId;
#endif

#ifndef DEF_TYPE_doggy_Path
#define DEF_TYPE_doggy_Path
typedef struct s_doggy_Path     *doggy_Path;
#endif

#ifndef DEF_TYPE_doggy_ActualOp
#define DEF_TYPE_doggy_ActualOp
typedef struct s_doggy_ActualOp *doggy_ActualOp;
#endif

#ifndef DEF_TYPE_doggy_TypePair
#define DEF_TYPE_doggy_TypePair
typedef struct s_doggy_TypePair *doggy_TypePair;
#endif

#ifndef DEF_TYPE_doggy_Opat
#define DEF_TYPE_doggy_Opat
typedef struct s_doggy_Opat     *doggy_Opat;
#endif

#ifndef DEF_TYPE_doggy_Format
#define DEF_TYPE_doggy_Format
typedef struct s_doggy_Format   *doggy_Format;
#endif

#ifndef DEF_TYPE_doggy_dummy_type
#define DEF_TYPE_doggy_dummy_type
typedef struct s_doggy_dummy_type       *doggy_dummy_type;
#endif

#ifndef DEF_TYPE_doggy_Scope
#define DEF_TYPE_doggy_Scope
typedef struct s_doggy_Scope    *doggy_Scope;
typedef doggy_Scope doggy_machine_descriptionScope;
typedef doggy_Scope doggy_RuleScope;
typedef doggy_Scope doggy_FuncRuleScope;
typedef doggy_Scope doggy_RhsGuardScope;
typedef doggy_Scope doggy_ExprGuardScope;
typedef doggy_Scope doggy_AppliedOpScope;
typedef doggy_Scope doggy_OpSetScope;
#endif

#ifndef DEF_TYPE_List_doggy_Num
#define DEF_TYPE_List_doggy_Num
typedef struct s_List_doggy_Num *List_doggy_Num;
#endif

#ifndef DEF_TYPE_List_List_doggy_TypePair
#define DEF_TYPE_List_List_doggy_TypePair
typedef struct s_List_List_doggy_TypePair       *List_List_doggy_TypePair;
#endif

#ifndef DEF_TYPE_List_doggy_TypePair
#define DEF_TYPE_List_doggy_TypePair
typedef struct s_List_doggy_TypePair    *List_doggy_TypePair;
#endif

#ifndef DEF_TYPE_List_doggy_ActualOp
#define DEF_TYPE_List_doggy_ActualOp
typedef struct s_List_doggy_ActualOp    *List_doggy_ActualOp;
#endif

#ifndef DEF_TYPE_List_List_doggy_Type
#define DEF_TYPE_List_List_doggy_Type
typedef struct s_List_List_doggy_Type   *List_List_doggy_Type;
#endif

#ifndef DEF_TYPE_List_doggy_Operator
#define DEF_TYPE_List_doggy_Operator
typedef struct s_List_doggy_Operator    *List_doggy_Operator;
#endif

#ifndef DEF_TYPE_List_doggy_Definition
#define DEF_TYPE_List_doggy_Definition
typedef struct s_List_doggy_Definition  *List_doggy_Definition;
#endif

#ifndef DEF_TYPE_List_doggy_Expr
#define DEF_TYPE_List_doggy_Expr
typedef struct s_List_doggy_Expr        *List_doggy_Expr;
#endif

#ifndef DEF_TYPE_List_doggy_Guard
#define DEF_TYPE_List_doggy_Guard
typedef struct s_List_doggy_Guard       *List_doggy_Guard;
#endif

#ifndef DEF_TYPE_List_doggy_Pattern
#define DEF_TYPE_List_doggy_Pattern
typedef struct s_List_doggy_Pattern     *List_doggy_Pattern;
#endif

#ifndef DEF_TYPE_List_doggy_Argument
#define DEF_TYPE_List_doggy_Argument
typedef struct s_List_doggy_Argument    *List_doggy_Argument;
#endif

#ifndef DEF_TYPE_List_doggy_FuncRule
#define DEF_TYPE_List_doggy_FuncRule
typedef struct s_List_doggy_FuncRule    *List_doggy_FuncRule;
#endif

#ifndef DEF_TYPE_List_doggy_Attribute
#define DEF_TYPE_List_doggy_Attribute
typedef struct s_List_doggy_Attribute   *List_doggy_Attribute;
#endif

#ifndef DEF_TYPE_List_doggy_Property
#define DEF_TYPE_List_doggy_Property
typedef struct s_List_doggy_Property    *List_doggy_Property;
#endif

#ifndef DEF_TYPE_List_doggy_Applied_formal
#define DEF_TYPE_List_doggy_Applied_formal
typedef struct s_List_doggy_Applied_formal      *List_doggy_Applied_formal;
#endif

#ifndef DEF_TYPE_List_doggy_Operation_def
#define DEF_TYPE_List_doggy_Operation_def
typedef struct s_List_doggy_Operation_def       *List_doggy_Operation_def;
#endif

#ifndef DEF_TYPE_List_doggy_Type
#define DEF_TYPE_List_doggy_Type
typedef struct s_List_doggy_Type        *List_doggy_Type;
#endif

#ifndef DEF_TYPE_List_doggy_Rule
#define DEF_TYPE_List_doggy_Rule
typedef struct s_List_doggy_Rule        *List_doggy_Rule;
#endif

#ifndef DEF_TYPE_List_doggy_Func
#define DEF_TYPE_List_doggy_Func
typedef struct s_List_doggy_Func        *List_doggy_Func;
#endif

#ifndef DEF_TYPE_List_doggy_Section
#define DEF_TYPE_List_doggy_Section
typedef struct s_List_doggy_Section     *List_doggy_Section;
#endif

#ifndef DEF_TYPE_List_doggy_FunctionDef
#define DEF_TYPE_List_doggy_FunctionDef
typedef struct s_List_doggy_FunctionDef *List_doggy_FunctionDef;
#endif

#ifndef DEF_TYPE_List_doggy_Typedef
#define DEF_TYPE_List_doggy_Typedef
typedef struct s_List_doggy_Typedef     *List_doggy_Typedef;
#endif

#include <front/scan_support.h>
#include <front/print_support.h>
#include <front/SymTab.h>
#include "doggy_defs.h"

#include "Checks.h"
#include "Types.h"
#include "GenCode.h"
#include "flags.h"
typedef Bind Bind_doggy_Definition;
typedef List_Bind List_Bind_doggy_Definition;
#define List_Bind_doggy_Definition_data(x) (Bind_doggy_Definition)Front_List_data((Front_List)(x))
#define List_Bind_doggy_Definition_next(x) (List_Bind_doggy_Definition)Front_List_next((Front_List)(x))
#define Bind_doggy_Definition_kind 7

typedef Bind Bind_doggy_Pattern;
typedef List_Bind List_Bind_doggy_Pattern;
#define List_Bind_doggy_Pattern_data(x) (Bind_doggy_Pattern)Front_List_data((Front_List)(x))
#define List_Bind_doggy_Pattern_next(x) (List_Bind_doggy_Pattern)Front_List_next((Front_List)(x))
#define Bind_doggy_Pattern_kind 6

typedef Bind Bind_doggy_Argument;
typedef List_Bind List_Bind_doggy_Argument;
#define List_Bind_doggy_Argument_data(x) (Bind_doggy_Argument)Front_List_data((Front_List)(x))
#define List_Bind_doggy_Argument_next(x) (List_Bind_doggy_Argument)Front_List_next((Front_List)(x))
#define Bind_doggy_Argument_kind 5

typedef Bind Bind_doggy_Func;
typedef List_Bind List_Bind_doggy_Func;
#define List_Bind_doggy_Func_data(x) (Bind_doggy_Func)Front_List_data((Front_List)(x))
#define List_Bind_doggy_Func_next(x) (List_Bind_doggy_Func)Front_List_next((Front_List)(x))
#define Bind_doggy_Func_kind 4

typedef Bind Bind_doggy_Operation_def;
typedef List_Bind List_Bind_doggy_Operation_def;
#define List_Bind_doggy_Operation_def_data(x) (Bind_doggy_Operation_def)Front_List_data((Front_List)(x))
#define List_Bind_doggy_Operation_def_next(x) (List_Bind_doggy_Operation_def)Front_List_next((Front_List)(x))
#define Bind_doggy_Operation_def_kind 3

typedef Bind Bind_doggy_machine_description;
typedef List_Bind List_Bind_doggy_machine_description;
#define List_Bind_doggy_machine_description_data(x) (Bind_doggy_machine_description)Front_List_data((Front_List)(x))
#define List_Bind_doggy_machine_description_next(x) (List_Bind_doggy_machine_description)Front_List_next((Front_List)(x))
#define Bind_doggy_machine_description_kind 2

typedef Bind Bind_doggy_FunctionDef;
typedef List_Bind List_Bind_doggy_FunctionDef;
#define List_Bind_doggy_FunctionDef_data(x) (Bind_doggy_FunctionDef)Front_List_data((Front_List)(x))
#define List_Bind_doggy_FunctionDef_next(x) (List_Bind_doggy_FunctionDef)Front_List_next((Front_List)(x))
#define Bind_doggy_FunctionDef_kind 1

typedef Bind Bind_doggy_Typedef;
typedef List_Bind List_Bind_doggy_Typedef;
#define List_Bind_doggy_Typedef_data(x) (Bind_doggy_Typedef)Front_List_data((Front_List)(x))
#define List_Bind_doggy_Typedef_next(x) (List_Bind_doggy_Typedef)Front_List_next((Front_List)(x))
#define Bind_doggy_Typedef_kind 0

extern doggy_doggy doggy_root;

#ifndef DEF_STRUCT_doggy_doggy
#define DEF_STRUCT_doggy_doggy

struct s_doggy_doggy {
  SrcInfo       src_info;  
  List_doggy_Typedef    types;  
  doggy_machine_description     source;  
  doggy_machine_description     target;  
  List_doggy_FunctionDef        funcs;  
  List_doggy_Section    sections;  
  List_doggy_Func       functions;  
  List_doggy_Rule       rules;  
  
} ;

#define doggy_doggy_src_info(_p)        ((*_p).src_info)
#define doggy_doggy_srcinfo(_p) ((*_p).src_info)
#define doggy_doggy_loc(_p)     ((*_p).src_info->loc)
#define doggy_doggy_types(_p)   ((*_p).types)
#define doggy_doggy_source(_p)  ((*_p).source)
#define doggy_doggy_target(_p)  ((*_p).target)
#define doggy_doggy_funcs(_p)   ((*_p).funcs)
#define doggy_doggy_sections(_p)        ((*_p).sections)
#define doggy_doggy_functions(_p)       ((*_p).functions)
#define doggy_doggy_rules(_p)   ((*_p).rules)
#define doggy_doggy_xxx(_p)     ((*_p).xxx)

extern doggy_doggy Create_doggy_doggy	(SrcInfo src_info, List_doggy_Typedef types, doggy_machine_description source, doggy_machine_description target, List_doggy_FunctionDef funcs, List_doggy_Section sections);

#endif /* DEF_STRUCT_doggy_doggy */

#ifndef DEF_STRUCT_doggy_Typedef
#define DEF_STRUCT_doggy_Typedef

struct s_doggy_Typedef {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  Ident id;  
  Bind_doggy_Typedef    id_bind;  
  String        name;  
  String        short_hand;  
  String        value;  
  doggy_Attributes      attrs;  
} ;

#define doggy_Typedef_src_info(_p)      ((*_p).src_info)
#define doggy_Typedef_srcinfo(_p)       ((*_p).src_info)
#define doggy_Typedef_loc(_p)   ((*_p).src_info->loc)
#define doggy_Typedef__num(_p)  ((*_p)._num)
#define doggy_Typedef_scope(_p) ((*_p).scope)
#define doggy_Typedef_old_scope(_p)     ((*_p).old_scope)
#define doggy_Typedef_id(_p)    ((*_p).id)
#define doggy_Typedef_id_bind(_p)       ((*_p).id_bind)
#define doggy_Typedef_name(_p)  ((*_p).name)
#define doggy_Typedef_short_hand(_p)    ((*_p).short_hand)
#define doggy_Typedef_value(_p) ((*_p).value)
#define doggy_Typedef_attrs(_p) ((*_p).attrs)

extern doggy_Typedef Create_doggy_Typedef	(SrcInfo src_info, Ident id, String name, String short_hand, String value, doggy_Attributes attrs);

#endif /* DEF_STRUCT_doggy_Typedef */

#ifndef DEF_STRUCT_doggy_FunctionDef
#define DEF_STRUCT_doggy_FunctionDef

struct s_doggy_FunctionDef {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  doggy_FunctionDef_tag tag;  
  doggy_Type    result;  
  Ident id;  
  Bind_doggy_FunctionDef        id_bind;  
  union {
  struct s_doggy_ExtFunc {
    List_doggy_Type     args;  
  } doggy_ExtFunc;
  struct s_doggy_ExtVar {
  } doggy_ExtVar;
} sub;
} ;

#define doggy_FunctionDef_src_info(_p)  ((*_p).src_info)
#define doggy_FunctionDef_srcinfo(_p)   ((*_p).src_info)
#define doggy_FunctionDef_loc(_p)       ((*_p).src_info->loc)
#define doggy_FunctionDef__num(_p)      ((*_p)._num)
#define doggy_FunctionDef_scope(_p)     ((*_p).scope)
#define doggy_FunctionDef_old_scope(_p) ((*_p).old_scope)
#define doggy_FunctionDef_tag(_p)       ((*_p).tag)
#define doggy_FunctionDef_result(_p)    ((*_p).result)
#define doggy_FunctionDef_id(_p)        ((*_p).id)
#define doggy_FunctionDef_id_bind(_p)   ((*_p).id_bind)
#define doggy_ExtFunc_args(_p)  ((*_p).sub.doggy_ExtFunc.args)

extern doggy_ExtVar Create_doggy_ExtVar	(SrcInfo src_info, doggy_Type result, Ident id);
extern doggy_ExtFunc Create_doggy_ExtFunc	(SrcInfo src_info, doggy_Type result, Ident id, List_doggy_Type args);

#endif /* DEF_STRUCT_doggy_FunctionDef */

#ifndef DEF_STRUCT_doggy_machine_description
#define DEF_STRUCT_doggy_machine_description

struct s_doggy_machine_description {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  Ident id;  
  Bind_doggy_machine_description        id_bind;  
  List_doggy_Operation_def      defs;  
  List_doggy_Applied_formal     supports;  
} ;

#define doggy_machine_description_src_info(_p)  ((*_p).src_info)
#define doggy_machine_description_srcinfo(_p)   ((*_p).src_info)
#define doggy_machine_description_loc(_p)       ((*_p).src_info->loc)
#define doggy_machine_description__num(_p)      ((*_p)._num)
#define doggy_machine_description_scope(_p)     ((*_p).scope)
#define doggy_machine_description_old_scope(_p) ((*_p).old_scope)
#define doggy_machine_description_id(_p)        ((*_p).id)
#define doggy_machine_description_id_bind(_p)   ((*_p).id_bind)
#define doggy_machine_description_defs(_p)      ((*_p).defs)
#define doggy_machine_description_supports(_p)  ((*_p).supports)

extern doggy_machine_description Create_doggy_machine_description	(SrcInfo src_info, Ident id, List_doggy_Operation_def defs, List_doggy_Applied_formal supports);

#endif /* DEF_STRUCT_doggy_machine_description */

#ifndef DEF_STRUCT_doggy_Operation_def
#define DEF_STRUCT_doggy_Operation_def

struct s_doggy_Operation_def {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  Ident id;  
  Bind_doggy_Operation_def      id_bind;  
  List_doggy_Type       types;  
  doggy_Type    result;  
  Ident actual_id;  
  doggy_Attributes      descr;  
  List_doggy_Property   props;  
  doggy_Type    type;  
  Bool  src;  
  Bool  tgt;  
  Bool  supported;  
  doggy_ActualOp        mop;  
  VALUE value;  
} ;

#define doggy_Operation_def_src_info(_p)        ((*_p).src_info)
#define doggy_Operation_def_srcinfo(_p) ((*_p).src_info)
#define doggy_Operation_def_loc(_p)     ((*_p).src_info->loc)
#define doggy_Operation_def__num(_p)    ((*_p)._num)
#define doggy_Operation_def_scope(_p)   ((*_p).scope)
#define doggy_Operation_def_old_scope(_p)       ((*_p).old_scope)
#define doggy_Operation_def_id(_p)      ((*_p).id)
#define doggy_Operation_def_id_bind(_p) ((*_p).id_bind)
#define doggy_Operation_def_types(_p)   ((*_p).types)
#define doggy_Operation_def_result(_p)  ((*_p).result)
#define doggy_Operation_def_actual_id(_p)       ((*_p).actual_id)
#define doggy_Operation_def_descr(_p)   ((*_p).descr)
#define doggy_Operation_def_props(_p)   ((*_p).props)
#define doggy_Operation_def_type(_p)    ((*_p).type)
#define doggy_Operation_def_src(_p)     ((*_p).src)
#define doggy_Operation_def_tgt(_p)     ((*_p).tgt)
#define doggy_Operation_def_supported(_p)       ((*_p).supported)
#define doggy_Operation_def_mop(_p)     ((*_p).mop)
#define doggy_Operation_def_value(_p)   ((*_p).value)

extern doggy_Operation_def Create_doggy_Operation_def	(SrcInfo src_info, Ident id, List_doggy_Type types, doggy_Type result, Ident actual_id, doggy_Attributes descr, List_doggy_Property props);

#endif /* DEF_STRUCT_doggy_Operation_def */

#ifndef DEF_STRUCT_doggy_Attributes
#define DEF_STRUCT_doggy_Attributes

struct s_doggy_Attributes {
  SrcInfo       src_info;  
  List_doggy_Attribute  ids;  
  doggy_Attributes      tail;  
} ;

#define doggy_Attributes_src_info(_p)   ((*_p).src_info)
#define doggy_Attributes_srcinfo(_p)    ((*_p).src_info)
#define doggy_Attributes_loc(_p)        ((*_p).src_info->loc)
#define doggy_Attributes_ids(_p)        ((*_p).ids)
#define doggy_Attributes_tail(_p)       ((*_p).tail)

extern doggy_Attributes Create_doggy_Attributes	(SrcInfo src_info, List_doggy_Attribute ids, doggy_Attributes tail);

#endif /* DEF_STRUCT_doggy_Attributes */

#ifndef DEF_STRUCT_doggy_Attribute
#define DEF_STRUCT_doggy_Attribute

struct s_doggy_Attribute {
  SrcInfo       src_info;  
  doggy_Attribute_tag   tag;  
  union {
  struct s_doggy_IdAttr {
    Ident       id;  
  } doggy_IdAttr;
  struct s_doggy_OpAttr {
  } doggy_OpAttr;
  struct s_doggy_IntAttr {
    Int i;  
  } doggy_IntAttr;
} sub;
} ;

#define doggy_Attribute_src_info(_p)    ((*_p).src_info)
#define doggy_Attribute_srcinfo(_p)     ((*_p).src_info)
#define doggy_Attribute_loc(_p) ((*_p).src_info->loc)
#define doggy_Attribute_tag(_p) ((*_p).tag)
#define doggy_IdAttr_id(_p)     ((*_p).sub.doggy_IdAttr.id)
#define doggy_IntAttr_i(_p)     ((*_p).sub.doggy_IntAttr.i)

extern doggy_IntAttr Create_doggy_IntAttr	(SrcInfo src_info, Int i);
extern doggy_OpAttr Create_doggy_OpAttr	(SrcInfo src_info);
extern doggy_IdAttr Create_doggy_IdAttr	(SrcInfo src_info, Ident id);

#endif /* DEF_STRUCT_doggy_Attribute */

#ifndef DEF_STRUCT_doggy_Section
#define DEF_STRUCT_doggy_Section

struct s_doggy_Section {
  SrcInfo       src_info;  
  doggy_Section_tag     tag;  
  union {
  struct s_doggy_FuncSection {
    List_doggy_Func     funcs;  
  } doggy_FuncSection;
  struct s_doggy_RuleSection {
    Ident       rules_id;  
    List_doggy_Rule     rules;  
  } doggy_RuleSection;
} sub;
} ;

#define doggy_Section_src_info(_p)      ((*_p).src_info)
#define doggy_Section_srcinfo(_p)       ((*_p).src_info)
#define doggy_Section_loc(_p)   ((*_p).src_info->loc)
#define doggy_Section_tag(_p)   ((*_p).tag)
#define doggy_FuncSection_funcs(_p)     ((*_p).sub.doggy_FuncSection.funcs)
#define doggy_RuleSection_rules_id(_p)  ((*_p).sub.doggy_RuleSection.rules_id)
#define doggy_RuleSection_rules(_p)     ((*_p).sub.doggy_RuleSection.rules)

extern doggy_RuleSection Create_doggy_RuleSection	(SrcInfo src_info, Ident rules_id, List_doggy_Rule rules);
extern doggy_FuncSection Create_doggy_FuncSection	(SrcInfo src_info, List_doggy_Func funcs);

#endif /* DEF_STRUCT_doggy_Section */

#ifndef DEF_STRUCT_doggy_Rule
#define DEF_STRUCT_doggy_Rule

struct s_doggy_Rule {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  doggy_Lhs     lhs;  
  doggy_Rhs     rhs;  
  Ident rules_id;  
  Bool  supported;  
  Bool  rhs_supported;  
} ;

#define doggy_Rule_src_info(_p) ((*_p).src_info)
#define doggy_Rule_srcinfo(_p)  ((*_p).src_info)
#define doggy_Rule_loc(_p)      ((*_p).src_info->loc)
#define doggy_Rule__num(_p)     ((*_p)._num)
#define doggy_Rule_scope(_p)    ((*_p).scope)
#define doggy_Rule_old_scope(_p)        ((*_p).old_scope)
#define doggy_Rule_lhs(_p)      ((*_p).lhs)
#define doggy_Rule_rhs(_p)      ((*_p).rhs)
#define doggy_Rule_rules_id(_p) ((*_p).rules_id)
#define doggy_Rule_supported(_p)        ((*_p).supported)
#define doggy_Rule_rhs_supported(_p)    ((*_p).rhs_supported)

extern doggy_Rule Create_doggy_Rule	(SrcInfo src_info, doggy_Lhs lhs, doggy_Rhs rhs);

#endif /* DEF_STRUCT_doggy_Rule */

#ifndef DEF_STRUCT_doggy_Lhs
#define DEF_STRUCT_doggy_Lhs

struct s_doggy_Lhs {
  SrcInfo       src_info;  
  doggy_Lhs_tag tag;  
  union {
  struct s_doggy_LabeledLhs {
    Ident       id;  
  } doggy_LabeledLhs;
  struct s_doggy_UnLabeledLhs {
  } doggy_UnLabeledLhs;
} sub;
  doggy_Pattern pat;  
} ;

#define doggy_Lhs_src_info(_p)  ((*_p).src_info)
#define doggy_Lhs_srcinfo(_p)   ((*_p).src_info)
#define doggy_Lhs_loc(_p)       ((*_p).src_info->loc)
#define doggy_Lhs_tag(_p)       ((*_p).tag)
#define doggy_LabeledLhs_id(_p) ((*_p).sub.doggy_LabeledLhs.id)
#define doggy_Lhs_pat(_p)       ((*_p).pat)

extern doggy_UnLabeledLhs Create_doggy_UnLabeledLhs	(SrcInfo src_info, doggy_Pattern pat);
extern doggy_LabeledLhs Create_doggy_LabeledLhs	(SrcInfo src_info, Ident id, doggy_Pattern pat);

#endif /* DEF_STRUCT_doggy_Lhs */

#ifndef DEF_STRUCT_doggy_Func
#define DEF_STRUCT_doggy_Func

struct s_doggy_Func {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  Bool  ext;  
  doggy_Type    type;  
  Ident id;  
  Bind_doggy_Func       id_bind;  
  List_doggy_FuncRule   rules;  
  List_doggy_Type       args;  
} ;

#define doggy_Func_src_info(_p) ((*_p).src_info)
#define doggy_Func_srcinfo(_p)  ((*_p).src_info)
#define doggy_Func_loc(_p)      ((*_p).src_info->loc)
#define doggy_Func__num(_p)     ((*_p)._num)
#define doggy_Func_scope(_p)    ((*_p).scope)
#define doggy_Func_old_scope(_p)        ((*_p).old_scope)
#define doggy_Func_ext(_p)      ((*_p).ext)
#define doggy_Func_type(_p)     ((*_p).type)
#define doggy_Func_id(_p)       ((*_p).id)
#define doggy_Func_id_bind(_p)  ((*_p).id_bind)
#define doggy_Func_rules(_p)    ((*_p).rules)
#define doggy_Func_args(_p)     ((*_p).args)

extern doggy_Func Create_doggy_Func	(SrcInfo src_info, Bool ext, doggy_Type type, Ident id, List_doggy_FuncRule rules);

#endif /* DEF_STRUCT_doggy_Func */

#ifndef DEF_STRUCT_doggy_FuncRule
#define DEF_STRUCT_doggy_FuncRule

struct s_doggy_FuncRule {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  List_doggy_Argument   args;  
  doggy_Rhs     rhs;  
  Bool  supported;  
} ;

#define doggy_FuncRule_src_info(_p)     ((*_p).src_info)
#define doggy_FuncRule_srcinfo(_p)      ((*_p).src_info)
#define doggy_FuncRule_loc(_p)  ((*_p).src_info->loc)
#define doggy_FuncRule__num(_p) ((*_p)._num)
#define doggy_FuncRule_scope(_p)        ((*_p).scope)
#define doggy_FuncRule_old_scope(_p)    ((*_p).old_scope)
#define doggy_FuncRule_args(_p) ((*_p).args)
#define doggy_FuncRule_rhs(_p)  ((*_p).rhs)
#define doggy_FuncRule_supported(_p)    ((*_p).supported)

extern doggy_FuncRule Create_doggy_FuncRule	(SrcInfo src_info, List_doggy_Argument args, doggy_Rhs rhs);

#endif /* DEF_STRUCT_doggy_FuncRule */

#ifndef DEF_STRUCT_doggy_Argument
#define DEF_STRUCT_doggy_Argument

struct s_doggy_Argument {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  doggy_Argument_tag    tag;  
  union {
  struct s_doggy_TypedArg {
    doggy_Type  type;  
  } doggy_TypedArg;
  struct s_doggy_UnTypedArg {
  } doggy_UnTypedArg;
} sub;
  Ident id;  
  Bind_doggy_Argument   id_bind;  
  doggy_ArgPat  pat;  
  VALUE value;  
} ;

#define doggy_Argument_src_info(_p)     ((*_p).src_info)
#define doggy_Argument_srcinfo(_p)      ((*_p).src_info)
#define doggy_Argument_loc(_p)  ((*_p).src_info->loc)
#define doggy_Argument__num(_p) ((*_p)._num)
#define doggy_Argument_scope(_p)        ((*_p).scope)
#define doggy_Argument_old_scope(_p)    ((*_p).old_scope)
#define doggy_Argument_tag(_p)  ((*_p).tag)
#define doggy_TypedArg_type(_p) ((*_p).sub.doggy_TypedArg.type)
#define doggy_Argument_id(_p)   ((*_p).id)
#define doggy_Argument_id_bind(_p)      ((*_p).id_bind)
#define doggy_Argument_pat(_p)  ((*_p).pat)
#define doggy_Argument_value(_p)        ((*_p).value)

extern doggy_UnTypedArg Create_doggy_UnTypedArg	(SrcInfo src_info, Ident id, doggy_ArgPat pat);
extern doggy_TypedArg Create_doggy_TypedArg	(SrcInfo src_info, doggy_Type type, Ident id, doggy_ArgPat pat);

#endif /* DEF_STRUCT_doggy_Argument */

#ifndef DEF_STRUCT_doggy_ArgPat
#define DEF_STRUCT_doggy_ArgPat

struct s_doggy_ArgPat {
  SrcInfo       src_info;  
  doggy_ArgPat_tag      tag;  
  union {
  struct s_doggy_PatArg {
    doggy_Pattern       pat;  
  } doggy_PatArg;
  struct s_doggy_SetArg {
    doggy_Applied_operation     set;  
  } doggy_SetArg;
} sub;
} ;

#define doggy_ArgPat_src_info(_p)       ((*_p).src_info)
#define doggy_ArgPat_srcinfo(_p)        ((*_p).src_info)
#define doggy_ArgPat_loc(_p)    ((*_p).src_info->loc)
#define doggy_ArgPat_tag(_p)    ((*_p).tag)
#define doggy_PatArg_pat(_p)    ((*_p).sub.doggy_PatArg.pat)
#define doggy_SetArg_set(_p)    ((*_p).sub.doggy_SetArg.set)

extern doggy_SetArg Create_doggy_SetArg	(SrcInfo src_info, doggy_Applied_operation set);
extern doggy_PatArg Create_doggy_PatArg	(SrcInfo src_info, doggy_Pattern pat);

#endif /* DEF_STRUCT_doggy_ArgPat */

#ifndef DEF_STRUCT_doggy_Pattern
#define DEF_STRUCT_doggy_Pattern

struct s_doggy_Pattern {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  doggy_Pattern_tag     tag;  
  union {
  struct s_doggy_TypedPattern {
    doggy_Type  btype;  
    doggy_Pattern       pat;  
  } doggy_TypedPattern;
  struct s_doggy_ConsPattern {
    doggy_Pattern       lhs;  
    doggy_Pattern       rhs;  
  } doggy_ConsPattern;
  struct s_doggy_DefPattern {
    List_doggy_Pattern  ids;  
    doggy_Pattern       arg;  
    
    Int use_cnt;  
  } doggy_DefPattern;
  struct s_doggy_IdentPattern {
    Ident       id;  
    Bind_doggy_Pattern  id_bind;  
    doggy_Pattern       def;  
    Int use_cnt;  
  } doggy_IdentPattern;
  struct s_doggy_BasicPattern {
    union {
    struct s_doggy_OpPattern {
      doggy_Applied_operation   op;  
      List_doggy_Pattern        args;  
    } doggy_OpPattern;
    struct s_doggy_ConstPattern {
      Int       cnst;  
    } doggy_ConstPattern;
    struct s_doggy_NullPattern {
    } doggy_NullPattern;
    struct s_doggy_DontCarePattern {
      doggy_Expr        expr;  
    } doggy_DontCarePattern;
  } sub;
  } doggy_BasicPattern;
} sub;
  doggy_Type    type;  
  Int   _swap;  
  Int   swap;  
  Int   _types;  
  Int   types;  
  VALUE value;  
} ;

#define doggy_Pattern_src_info(_p)      ((*_p).src_info)
#define doggy_Pattern_srcinfo(_p)       ((*_p).src_info)
#define doggy_Pattern_loc(_p)   ((*_p).src_info->loc)
#define doggy_Pattern__num(_p)  ((*_p)._num)
#define doggy_Pattern_scope(_p) ((*_p).scope)
#define doggy_Pattern_old_scope(_p)     ((*_p).old_scope)
#define doggy_Pattern_tag(_p)   ((*_p).tag)
#define doggy_TypedPattern_btype(_p)    ((*_p).sub.doggy_TypedPattern.btype)
#define doggy_TypedPattern_pat(_p)      ((*_p).sub.doggy_TypedPattern.pat)
#define doggy_ConsPattern_lhs(_p)       ((*_p).sub.doggy_ConsPattern.lhs)
#define doggy_ConsPattern_rhs(_p)       ((*_p).sub.doggy_ConsPattern.rhs)
#define doggy_DefPattern_ids(_p)        ((*_p).sub.doggy_DefPattern.ids)
#define doggy_DefPattern_arg(_p)        ((*_p).sub.doggy_DefPattern.arg)
#define doggy_DefPattern_x(_p)  ((*_p).sub.doggy_DefPattern.x)
#define doggy_DefPattern_use_cnt(_p)    ((*_p).sub.doggy_DefPattern.use_cnt)
#define doggy_IdentPattern_id(_p)       ((*_p).sub.doggy_IdentPattern.id)
#define doggy_IdentPattern_id_bind(_p)  ((*_p).sub.doggy_IdentPattern.id_bind)
#define doggy_IdentPattern_def(_p)      ((*_p).sub.doggy_IdentPattern.def)
#define doggy_IdentPattern_use_cnt(_p)  ((*_p).sub.doggy_IdentPattern.use_cnt)
#define doggy_OpPattern_op(_p)  ((*_p).sub.doggy_BasicPattern.sub.doggy_OpPattern.op)
#define doggy_OpPattern_args(_p)        ((*_p).sub.doggy_BasicPattern.sub.doggy_OpPattern.args)
#define doggy_ConstPattern_cnst(_p)     ((*_p).sub.doggy_BasicPattern.sub.doggy_ConstPattern.cnst)
#define doggy_DontCarePattern_expr(_p)  ((*_p).sub.doggy_BasicPattern.sub.doggy_DontCarePattern.expr)
#define doggy_Pattern_type(_p)  ((*_p).type)
#define doggy_Pattern__swap(_p) ((*_p)._swap)
#define doggy_Pattern_swap(_p)  ((*_p).swap)
#define doggy_Pattern__types(_p)        ((*_p)._types)
#define doggy_Pattern_types(_p) ((*_p).types)
#define doggy_Pattern_value(_p) ((*_p).value)

extern doggy_DontCarePattern Create_doggy_DontCarePattern	(SrcInfo src_info, doggy_Expr expr);
extern doggy_NullPattern Create_doggy_NullPattern	(SrcInfo src_info);
extern doggy_ConstPattern Create_doggy_ConstPattern	(SrcInfo src_info, Int cnst);
extern doggy_OpPattern Create_doggy_OpPattern	(SrcInfo src_info, doggy_Applied_operation op, List_doggy_Pattern args);
extern doggy_IdentPattern Create_doggy_IdentPattern	(SrcInfo src_info, Ident id);
extern doggy_DefPattern Create_doggy_DefPattern	(SrcInfo src_info, List_doggy_Pattern ids, doggy_Pattern arg);
extern doggy_ConsPattern Create_doggy_ConsPattern	(SrcInfo src_info, doggy_Pattern lhs, doggy_Pattern rhs);
extern doggy_TypedPattern Create_doggy_TypedPattern	(SrcInfo src_info, doggy_Type btype, doggy_Pattern pat);

#endif /* DEF_STRUCT_doggy_Pattern */

#ifndef DEF_STRUCT_doggy_Rhs
#define DEF_STRUCT_doggy_Rhs

struct s_doggy_Rhs {
  SrcInfo       src_info;  
  doggy_Rhs_tag tag;  
  union {
  struct s_doggy_PlainRhs {
    List_doggy_Guard    guards;  
  } doggy_PlainRhs;
  struct s_doggy_BlockRhs {
    doggy_Rhs   rhs;  
    doggy_Wherepart     where;  
  } doggy_BlockRhs;
} sub;
} ;

#define doggy_Rhs_src_info(_p)  ((*_p).src_info)
#define doggy_Rhs_srcinfo(_p)   ((*_p).src_info)
#define doggy_Rhs_loc(_p)       ((*_p).src_info->loc)
#define doggy_Rhs_tag(_p)       ((*_p).tag)
#define doggy_PlainRhs_guards(_p)       ((*_p).sub.doggy_PlainRhs.guards)
#define doggy_BlockRhs_rhs(_p)  ((*_p).sub.doggy_BlockRhs.rhs)
#define doggy_BlockRhs_where(_p)        ((*_p).sub.doggy_BlockRhs.where)

extern doggy_BlockRhs Create_doggy_BlockRhs	(SrcInfo src_info, doggy_Rhs rhs, doggy_Wherepart where);
extern doggy_PlainRhs Create_doggy_PlainRhs	(SrcInfo src_info, List_doggy_Guard guards);

#endif /* DEF_STRUCT_doggy_Rhs */

#ifndef DEF_STRUCT_doggy_Guard
#define DEF_STRUCT_doggy_Guard

struct s_doggy_Guard {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  doggy_Guard_tag       tag;  
  doggy_Expr    conds;  
  union {
  struct s_doggy_RhsGuard {
    doggy_Rhs   rhs;  
  } doggy_RhsGuard;
  struct s_doggy_ExprGuard {
    doggy_ExprSeq       exprs;  
  } doggy_ExprGuard;
} sub;
  doggy_Wherepart       where;  
} ;

#define doggy_Guard_src_info(_p)        ((*_p).src_info)
#define doggy_Guard_srcinfo(_p) ((*_p).src_info)
#define doggy_Guard_loc(_p)     ((*_p).src_info->loc)
#define doggy_Guard__num(_p)    ((*_p)._num)
#define doggy_Guard_scope(_p)   ((*_p).scope)
#define doggy_Guard_old_scope(_p)       ((*_p).old_scope)
#define doggy_Guard_tag(_p)     ((*_p).tag)
#define doggy_Guard_conds(_p)   ((*_p).conds)
#define doggy_RhsGuard_rhs(_p)  ((*_p).sub.doggy_RhsGuard.rhs)
#define doggy_ExprGuard_exprs(_p)       ((*_p).sub.doggy_ExprGuard.exprs)
#define doggy_Guard_where(_p)   ((*_p).where)

extern doggy_ExprGuard Create_doggy_ExprGuard	(SrcInfo src_info, doggy_Expr conds, doggy_ExprSeq exprs, doggy_Wherepart where);
extern doggy_RhsGuard Create_doggy_RhsGuard	(SrcInfo src_info, doggy_Expr conds, doggy_Rhs rhs, doggy_Wherepart where);

#endif /* DEF_STRUCT_doggy_Guard */

#ifndef DEF_STRUCT_doggy_ExprSeq
#define DEF_STRUCT_doggy_ExprSeq

struct s_doggy_ExprSeq {
  SrcInfo       src_info;  
  doggy_ExprSeq_tag     tag;  
  union {
  struct s_doggy_OneExpr {
    doggy_Expr  expr;  
  } doggy_OneExpr;
  struct s_doggy_MoreExprs {
    List_doggy_Expr     exprs;  
  } doggy_MoreExprs;
} sub;
} ;

#define doggy_ExprSeq_src_info(_p)      ((*_p).src_info)
#define doggy_ExprSeq_srcinfo(_p)       ((*_p).src_info)
#define doggy_ExprSeq_loc(_p)   ((*_p).src_info->loc)
#define doggy_ExprSeq_tag(_p)   ((*_p).tag)
#define doggy_OneExpr_expr(_p)  ((*_p).sub.doggy_OneExpr.expr)
#define doggy_MoreExprs_exprs(_p)       ((*_p).sub.doggy_MoreExprs.exprs)

extern doggy_MoreExprs Create_doggy_MoreExprs	(SrcInfo src_info, List_doggy_Expr exprs);
extern doggy_OneExpr Create_doggy_OneExpr	(SrcInfo src_info, doggy_Expr expr);

#endif /* DEF_STRUCT_doggy_ExprSeq */

#ifndef DEF_STRUCT_doggy_Wherepart
#define DEF_STRUCT_doggy_Wherepart

struct s_doggy_Wherepart {
  SrcInfo       src_info;  
  List_doggy_Definition defs;  
} ;

#define doggy_Wherepart_src_info(_p)    ((*_p).src_info)
#define doggy_Wherepart_srcinfo(_p)     ((*_p).src_info)
#define doggy_Wherepart_loc(_p) ((*_p).src_info->loc)
#define doggy_Wherepart_defs(_p)        ((*_p).defs)

extern doggy_Wherepart Create_doggy_Wherepart	(SrcInfo src_info, List_doggy_Definition defs);

#endif /* DEF_STRUCT_doggy_Wherepart */

#ifndef DEF_STRUCT_doggy_Applied_operation
#define DEF_STRUCT_doggy_Applied_operation

struct s_doggy_Applied_operation {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  doggy_Applied_operation_tag   tag;  
  union {
  struct s_doggy_AnyOp {
  } doggy_AnyOp;
  struct s_doggy_AppliedOp {
    doggy_Applied_formal        op;  
  } doggy_AppliedOp;
  struct s_doggy_OpSet {
    List_doggy_Applied_formal   ops;  
  } doggy_OpSet;
} sub;
} ;

#define doggy_Applied_operation_src_info(_p)    ((*_p).src_info)
#define doggy_Applied_operation_srcinfo(_p)     ((*_p).src_info)
#define doggy_Applied_operation_loc(_p) ((*_p).src_info->loc)
#define doggy_Applied_operation__num(_p)        ((*_p)._num)
#define doggy_Applied_operation_scope(_p)       ((*_p).scope)
#define doggy_Applied_operation_old_scope(_p)   ((*_p).old_scope)
#define doggy_Applied_operation_tag(_p) ((*_p).tag)
#define doggy_AppliedOp_op(_p)  ((*_p).sub.doggy_AppliedOp.op)
#define doggy_OpSet_ops(_p)     ((*_p).sub.doggy_OpSet.ops)

extern doggy_OpSet Create_doggy_OpSet	(SrcInfo src_info, List_doggy_Applied_formal ops);
extern doggy_AppliedOp Create_doggy_AppliedOp	(SrcInfo src_info, doggy_Applied_formal op);
extern doggy_AnyOp Create_doggy_AnyOp	(SrcInfo src_info);

#endif /* DEF_STRUCT_doggy_Applied_operation */

#ifndef DEF_STRUCT_doggy_Applied_formal
#define DEF_STRUCT_doggy_Applied_formal

struct s_doggy_Applied_formal {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  Ident id;  
  Bind_doggy_Operation_def      ap_bind;  
  doggy_Operation_def   ap;  
} ;

#define doggy_Applied_formal_src_info(_p)       ((*_p).src_info)
#define doggy_Applied_formal_srcinfo(_p)        ((*_p).src_info)
#define doggy_Applied_formal_loc(_p)    ((*_p).src_info->loc)
#define doggy_Applied_formal__num(_p)   ((*_p)._num)
#define doggy_Applied_formal_scope(_p)  ((*_p).scope)
#define doggy_Applied_formal_old_scope(_p)      ((*_p).old_scope)
#define doggy_Applied_formal_id(_p)     ((*_p).id)
#define doggy_Applied_formal_ap_bind(_p)        ((*_p).ap_bind)
#define doggy_Applied_formal_ap(_p)     ((*_p).ap)

extern doggy_Applied_formal Create_doggy_Applied_formal	(SrcInfo src_info, Ident id);

#endif /* DEF_STRUCT_doggy_Applied_formal */

#ifndef DEF_STRUCT_doggy_Expr
#define DEF_STRUCT_doggy_Expr

struct s_doggy_Expr {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  doggy_Expr_tag        tag;  
  Bool  warned;  
  union {
  struct s_doggy_BinExpr {
    List_doggy_Expr     args;  
    List_doggy_Operator ops;  
  } doggy_BinExpr;
  struct s_doggy_ConsExpr {
    doggy_Expr  lhs;  
    doggy_Expr  rhs;  
  } doggy_ConsExpr;
  struct s_doggy_SimpleExpr {
    union {
    struct s_doggy_IdentExpr {
      Ident     id;  
      Bind_doggy_Operation_def  operator_bind;  
      doggy_Operation_def       operator;  
      Bind_doggy_Pattern        pattern_bind;  
      doggy_Pattern     pattern;  
      Bind_doggy_FunctionDef    ext_bind;  
      doggy_FunctionDef ext;  
      Bind_doggy_Definition     def_bind;  
      doggy_Definition  def;  
      Bind_doggy_Argument       arg_bind;  
      doggy_Argument    arg;  
      Int       use_cnt;  
    } doggy_IdentExpr;
    struct s_doggy_IfExpr {
      doggy_Expr        cond;  
      doggy_Expr        thn;  
      List_doggy_Expr   conds;  
      List_doggy_Expr   thens;  
      doggy_Expr        els;  
    } doggy_IfExpr;
    struct s_doggy_ConstExpr {
      doggy_Constant    cnst;  
    } doggy_ConstExpr;
    struct s_doggy_Operation {
      Ident     id;  
      List_doggy_Expr   args;  
      Bind_doggy_Operation_def  operator_bind;  
      doggy_Operation_def       operator;  
      Bind_doggy_Definition     defi_bind;  
      doggy_Definition  defi;  
      Bind_doggy_FunctionDef    ext_bind;  
      doggy_FunctionDef ext;  
      Bind_doggy_Func   func_bind;  
      doggy_Func        func;  
    } doggy_Operation;
    struct s_doggy_ParExpr {
      doggy_Expr        expr;  
    } doggy_ParExpr;
    struct s_doggy_MonExpr {
      doggy_MonOp       op;  
      doggy_Expr        arg;  
    } doggy_MonExpr;
  } sub;
  } doggy_SimpleExpr;
} sub;
} ;

#define doggy_Expr_src_info(_p) ((*_p).src_info)
#define doggy_Expr_srcinfo(_p)  ((*_p).src_info)
#define doggy_Expr_loc(_p)      ((*_p).src_info->loc)
#define doggy_Expr__num(_p)     ((*_p)._num)
#define doggy_Expr_scope(_p)    ((*_p).scope)
#define doggy_Expr_old_scope(_p)        ((*_p).old_scope)
#define doggy_Expr_tag(_p)      ((*_p).tag)
#define doggy_Expr_warned(_p)   ((*_p).warned)
#define doggy_BinExpr_args(_p)  ((*_p).sub.doggy_BinExpr.args)
#define doggy_BinExpr_ops(_p)   ((*_p).sub.doggy_BinExpr.ops)
#define doggy_ConsExpr_lhs(_p)  ((*_p).sub.doggy_ConsExpr.lhs)
#define doggy_ConsExpr_rhs(_p)  ((*_p).sub.doggy_ConsExpr.rhs)
#define doggy_IdentExpr_id(_p)  ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.id)
#define doggy_IdentExpr_operator_bind(_p)       ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.operator_bind)
#define doggy_IdentExpr_operator(_p)    ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.operator)
#define doggy_IdentExpr_pattern_bind(_p)        ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.pattern_bind)
#define doggy_IdentExpr_pattern(_p)     ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.pattern)
#define doggy_IdentExpr_ext_bind(_p)    ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.ext_bind)
#define doggy_IdentExpr_ext(_p) ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.ext)
#define doggy_IdentExpr_def_bind(_p)    ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.def_bind)
#define doggy_IdentExpr_def(_p) ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.def)
#define doggy_IdentExpr_arg_bind(_p)    ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.arg_bind)
#define doggy_IdentExpr_arg(_p) ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.arg)
#define doggy_IdentExpr_use_cnt(_p)     ((*_p).sub.doggy_SimpleExpr.sub.doggy_IdentExpr.use_cnt)
#define doggy_IfExpr_cond(_p)   ((*_p).sub.doggy_SimpleExpr.sub.doggy_IfExpr.cond)
#define doggy_IfExpr_thn(_p)    ((*_p).sub.doggy_SimpleExpr.sub.doggy_IfExpr.thn)
#define doggy_IfExpr_conds(_p)  ((*_p).sub.doggy_SimpleExpr.sub.doggy_IfExpr.conds)
#define doggy_IfExpr_thens(_p)  ((*_p).sub.doggy_SimpleExpr.sub.doggy_IfExpr.thens)
#define doggy_IfExpr_els(_p)    ((*_p).sub.doggy_SimpleExpr.sub.doggy_IfExpr.els)
#define doggy_ConstExpr_cnst(_p)        ((*_p).sub.doggy_SimpleExpr.sub.doggy_ConstExpr.cnst)
#define doggy_Operation_id(_p)  ((*_p).sub.doggy_SimpleExpr.sub.doggy_Operation.id)
#define doggy_Operation_args(_p)        ((*_p).sub.doggy_SimpleExpr.sub.doggy_Operation.args)
#define doggy_Operation_operator_bind(_p)       ((*_p).sub.doggy_SimpleExpr.sub.doggy_Operation.operator_bind)
#define doggy_Operation_operator(_p)    ((*_p).sub.doggy_SimpleExpr.sub.doggy_Operation.operator)
#define doggy_Operation_defi_bind(_p)   ((*_p).sub.doggy_SimpleExpr.sub.doggy_Operation.defi_bind)
#define doggy_Operation_defi(_p)        ((*_p).sub.doggy_SimpleExpr.sub.doggy_Operation.defi)
#define doggy_Operation_ext_bind(_p)    ((*_p).sub.doggy_SimpleExpr.sub.doggy_Operation.ext_bind)
#define doggy_Operation_ext(_p) ((*_p).sub.doggy_SimpleExpr.sub.doggy_Operation.ext)
#define doggy_Operation_func_bind(_p)   ((*_p).sub.doggy_SimpleExpr.sub.doggy_Operation.func_bind)
#define doggy_Operation_func(_p)        ((*_p).sub.doggy_SimpleExpr.sub.doggy_Operation.func)
#define doggy_ParExpr_expr(_p)  ((*_p).sub.doggy_SimpleExpr.sub.doggy_ParExpr.expr)
#define doggy_MonExpr_op(_p)    ((*_p).sub.doggy_SimpleExpr.sub.doggy_MonExpr.op)
#define doggy_MonExpr_arg(_p)   ((*_p).sub.doggy_SimpleExpr.sub.doggy_MonExpr.arg)

extern doggy_MonExpr Create_doggy_MonExpr	(SrcInfo src_info, doggy_MonOp op, doggy_Expr arg);
extern doggy_ParExpr Create_doggy_ParExpr	(SrcInfo src_info, doggy_Expr expr);
extern doggy_Operation Create_doggy_Operation	(SrcInfo src_info, Ident id, List_doggy_Expr args);
extern doggy_ConstExpr Create_doggy_ConstExpr	(SrcInfo src_info, doggy_Constant cnst);
extern doggy_IfExpr Create_doggy_IfExpr	(SrcInfo src_info, doggy_Expr cond, doggy_Expr thn, List_doggy_Expr conds, List_doggy_Expr thens, doggy_Expr els);
extern doggy_IdentExpr Create_doggy_IdentExpr	(SrcInfo src_info, Ident id);
extern doggy_ConsExpr Create_doggy_ConsExpr	(SrcInfo src_info, doggy_Expr lhs, doggy_Expr rhs);
extern doggy_BinExpr Create_doggy_BinExpr	(SrcInfo src_info, List_doggy_Expr args, List_doggy_Operator ops);

#endif /* DEF_STRUCT_doggy_Expr */

#ifndef DEF_STRUCT_doggy_Constant
#define DEF_STRUCT_doggy_Constant

struct s_doggy_Constant {
  SrcInfo       src_info;  
  doggy_Constant_tag    tag;  
  union {
  struct s_doggy_IntConst {
    Int i;  
  } doggy_IntConst;
  struct s_doggy_BoolConst {
    Bool        b;  
  } doggy_BoolConst;
  struct s_doggy_StringConst {
    String      s;  
  } doggy_StringConst;
  struct s_doggy_NullConst {
  } doggy_NullConst;
} sub;
} ;

#define doggy_Constant_src_info(_p)     ((*_p).src_info)
#define doggy_Constant_srcinfo(_p)      ((*_p).src_info)
#define doggy_Constant_loc(_p)  ((*_p).src_info->loc)
#define doggy_Constant_tag(_p)  ((*_p).tag)
#define doggy_IntConst_i(_p)    ((*_p).sub.doggy_IntConst.i)
#define doggy_BoolConst_b(_p)   ((*_p).sub.doggy_BoolConst.b)
#define doggy_StringConst_s(_p) ((*_p).sub.doggy_StringConst.s)

extern doggy_NullConst Create_doggy_NullConst	(SrcInfo src_info);
extern doggy_StringConst Create_doggy_StringConst	(SrcInfo src_info, String s);
extern doggy_BoolConst Create_doggy_BoolConst	(SrcInfo src_info, Bool b);
extern doggy_IntConst Create_doggy_IntConst	(SrcInfo src_info, Int i);

#endif /* DEF_STRUCT_doggy_Constant */

#ifndef DEF_STRUCT_doggy_Definition
#define DEF_STRUCT_doggy_Definition

struct s_doggy_Definition {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  doggy_Type    type;  
  Ident id;  
  Bind_doggy_Definition id_bind;  
  doggy_Expr    expr;  
  VALUE value;  
  Int   order;  
  Int   use_cnt;  
} ;

#define doggy_Definition_src_info(_p)   ((*_p).src_info)
#define doggy_Definition_srcinfo(_p)    ((*_p).src_info)
#define doggy_Definition_loc(_p)        ((*_p).src_info->loc)
#define doggy_Definition__num(_p)       ((*_p)._num)
#define doggy_Definition_scope(_p)      ((*_p).scope)
#define doggy_Definition_old_scope(_p)  ((*_p).old_scope)
#define doggy_Definition_type(_p)       ((*_p).type)
#define doggy_Definition_id(_p) ((*_p).id)
#define doggy_Definition_id_bind(_p)    ((*_p).id_bind)
#define doggy_Definition_expr(_p)       ((*_p).expr)
#define doggy_Definition_value(_p)      ((*_p).value)
#define doggy_Definition_order(_p)      ((*_p).order)
#define doggy_Definition_use_cnt(_p)    ((*_p).use_cnt)

extern doggy_Definition Create_doggy_Definition	(SrcInfo src_info, doggy_Type type, Ident id, doggy_Expr expr);

#endif /* DEF_STRUCT_doggy_Definition */

#ifndef DEF_STRUCT_doggy_Type
#define DEF_STRUCT_doggy_Type

struct s_doggy_Type {
  SrcInfo       src_info;  
  Int   _num;  
  doggy_Scope   scope;  
  doggy_Scope   old_scope;  
  doggy_Type_tag        tag;  
  union {
  struct s_doggy_EdgeType {
    List_doggy_Type     types;  
  } doggy_EdgeType;
  struct s_doggy_TupleType {
    List_doggy_Type     types;  
  } doggy_TupleType;
  struct s_doggy_BasicType {
    union {
    struct s_doggy_IdentType {
      Ident     type_id;  
      Bind_doggy_Typedef        type_bind;  
      doggy_Typedef     type;  
    } doggy_IdentType;
    struct s_doggy_OprType {
      List_doggy_Type   args;  
    } doggy_OprType;
    struct s_doggy_PointerType {
      doggy_Type        base;  
    } doggy_PointerType;
    struct s_doggy_RangeType {
      doggy_Num lo;  
      doggy_Num hi;  
      doggy_Num step;  
    } doggy_RangeType;
    struct s_doggy_FRangeType {
      Ident     f;  
    } doggy_FRangeType;
  } sub;
  } doggy_BasicType;
} sub;
} ;

#define doggy_Type_src_info(_p) ((*_p).src_info)
#define doggy_Type_srcinfo(_p)  ((*_p).src_info)
#define doggy_Type_loc(_p)      ((*_p).src_info->loc)
#define doggy_Type__num(_p)     ((*_p)._num)
#define doggy_Type_scope(_p)    ((*_p).scope)
#define doggy_Type_old_scope(_p)        ((*_p).old_scope)
#define doggy_Type_tag(_p)      ((*_p).tag)
#define doggy_EdgeType_types(_p)        ((*_p).sub.doggy_EdgeType.types)
#define doggy_TupleType_types(_p)       ((*_p).sub.doggy_TupleType.types)
#define doggy_IdentType_type_id(_p)     ((*_p).sub.doggy_BasicType.sub.doggy_IdentType.type_id)
#define doggy_IdentType_type_bind(_p)   ((*_p).sub.doggy_BasicType.sub.doggy_IdentType.type_bind)
#define doggy_IdentType_type(_p)        ((*_p).sub.doggy_BasicType.sub.doggy_IdentType.type)
#define doggy_OprType_args(_p)  ((*_p).sub.doggy_BasicType.sub.doggy_OprType.args)
#define doggy_PointerType_base(_p)      ((*_p).sub.doggy_BasicType.sub.doggy_PointerType.base)
#define doggy_RangeType_lo(_p)  ((*_p).sub.doggy_BasicType.sub.doggy_RangeType.lo)
#define doggy_RangeType_hi(_p)  ((*_p).sub.doggy_BasicType.sub.doggy_RangeType.hi)
#define doggy_RangeType_step(_p)        ((*_p).sub.doggy_BasicType.sub.doggy_RangeType.step)
#define doggy_FRangeType_f(_p)  ((*_p).sub.doggy_BasicType.sub.doggy_FRangeType.f)

extern doggy_FRangeType Create_doggy_FRangeType	(SrcInfo src_info, Ident f);
extern doggy_RangeType Create_doggy_RangeType	(SrcInfo src_info, doggy_Num lo, doggy_Num hi, doggy_Num step);
extern doggy_PointerType Create_doggy_PointerType	(SrcInfo src_info, doggy_Type base);
extern doggy_OprType Create_doggy_OprType	(SrcInfo src_info, List_doggy_Type args);
extern doggy_IdentType Create_doggy_IdentType	(SrcInfo src_info, Ident type_id);
extern doggy_TupleType Create_doggy_TupleType	(SrcInfo src_info, List_doggy_Type types);
extern doggy_EdgeType Create_doggy_EdgeType	(SrcInfo src_info, List_doggy_Type types);

#endif /* DEF_STRUCT_doggy_Type */

#ifndef DEF_STRUCT_doggy_Num
#define DEF_STRUCT_doggy_Num

struct s_doggy_Num {
  SrcInfo       src_info;  
  Bool  neg;  
  Int   i;  
  
} ;

#define doggy_Num_src_info(_p)  ((*_p).src_info)
#define doggy_Num_srcinfo(_p)   ((*_p).src_info)
#define doggy_Num_loc(_p)       ((*_p).src_info->loc)
#define doggy_Num_neg(_p)       ((*_p).neg)
#define doggy_Num_i(_p) ((*_p).i)
#define doggy_Num_negate(_p)    ((*_p).negate)

extern doggy_Num Create_doggy_Num	(SrcInfo src_info, Bool neg, Int i);

#endif /* DEF_STRUCT_doggy_Num */

#ifndef DEF_STRUCT_doggy_IdInt
#define DEF_STRUCT_doggy_IdInt

struct s_doggy_IdInt {
  SrcInfo       src_info;  
  doggy_IdInt_tag       tag;  
  union {
  struct s_doggy_IsId {
    Ident       id;  
  } doggy_IsId;
  struct s_doggy_IsInt {
    Int i;  
  } doggy_IsInt;
} sub;
} ;

#define doggy_IdInt_src_info(_p)        ((*_p).src_info)
#define doggy_IdInt_srcinfo(_p) ((*_p).src_info)
#define doggy_IdInt_loc(_p)     ((*_p).src_info->loc)
#define doggy_IdInt_tag(_p)     ((*_p).tag)
#define doggy_IsId_id(_p)       ((*_p).sub.doggy_IsId.id)
#define doggy_IsInt_i(_p)       ((*_p).sub.doggy_IsInt.i)

extern doggy_IsInt Create_doggy_IsInt	(SrcInfo src_info, Int i);
extern doggy_IsId Create_doggy_IsId	(SrcInfo src_info, Ident id);

#endif /* DEF_STRUCT_doggy_IdInt */

#ifndef DEF_STRUCT_doggy_Path
#define DEF_STRUCT_doggy_Path

struct s_doggy_Path {
  SrcInfo       src_info;  
  Int   data;  
  doggy_Type    type;  
  doggy_Path    next;  
} ;

#define doggy_Path_src_info(_p) ((*_p).src_info)
#define doggy_Path_srcinfo(_p)  ((*_p).src_info)
#define doggy_Path_loc(_p)      ((*_p).src_info->loc)
#define doggy_Path_data(_p)     ((*_p).data)
#define doggy_Path_type(_p)     ((*_p).type)
#define doggy_Path_next(_p)     ((*_p).next)

extern doggy_Path Create_doggy_Path	(SrcInfo src_info, Int data, doggy_Type type, doggy_Path next);

#endif /* DEF_STRUCT_doggy_Path */

#ifndef DEF_STRUCT_doggy_ActualOp
#define DEF_STRUCT_doggy_ActualOp

struct s_doggy_ActualOp {
  SrcInfo       src_info;  
  Int   location;  
  Ident id;  
  List_doggy_Operation_def      formals;  
  Bool  overloaded;  
  Bool  src;  
  Bool  tgt;  
} ;

#define doggy_ActualOp_src_info(_p)     ((*_p).src_info)
#define doggy_ActualOp_srcinfo(_p)      ((*_p).src_info)
#define doggy_ActualOp_loc(_p)  ((*_p).src_info->loc)
#define doggy_ActualOp_location(_p)     ((*_p).location)
#define doggy_ActualOp_id(_p)   ((*_p).id)
#define doggy_ActualOp_formals(_p)      ((*_p).formals)
#define doggy_ActualOp_overloaded(_p)   ((*_p).overloaded)
#define doggy_ActualOp_src(_p)  ((*_p).src)
#define doggy_ActualOp_tgt(_p)  ((*_p).tgt)

extern doggy_ActualOp Create_doggy_ActualOp	(SrcInfo src_info, Int location, Ident id, List_doggy_Operation_def formals);

#endif /* DEF_STRUCT_doggy_ActualOp */

#ifndef DEF_STRUCT_doggy_TypePair
#define DEF_STRUCT_doggy_TypePair

struct s_doggy_TypePair {
  SrcInfo       src_info;  
  doggy_Type    t1;  
  doggy_Type    t2;  
} ;

#define doggy_TypePair_src_info(_p)     ((*_p).src_info)
#define doggy_TypePair_srcinfo(_p)      ((*_p).src_info)
#define doggy_TypePair_loc(_p)  ((*_p).src_info->loc)
#define doggy_TypePair_t1(_p)   ((*_p).t1)
#define doggy_TypePair_t2(_p)   ((*_p).t2)

extern doggy_TypePair Create_doggy_TypePair	(SrcInfo src_info, doggy_Type t1, doggy_Type t2);

#endif /* DEF_STRUCT_doggy_TypePair */

#ifndef DEF_STRUCT_doggy_Opat
#define DEF_STRUCT_doggy_Opat

struct s_doggy_Opat {
  SrcInfo       src_info;  
  doggy_Opat    memo_link;  
  List_doggy_Type       args;  
  doggy_Type    result;  
  Int   num;  
} ;

#define doggy_Opat_src_info(_p) ((*_p).src_info)
#define doggy_Opat_srcinfo(_p)  ((*_p).src_info)
#define doggy_Opat_loc(_p)      ((*_p).src_info->loc)
#define doggy_Opat_memo_link(_p)        ((*_p).memo_link)
#define doggy_Opat_args(_p)     ((*_p).args)
#define doggy_Opat_result(_p)   ((*_p).result)
#define doggy_Opat_num(_p)      ((*_p).num)

extern void Memo_Traverse_doggy_Opat (void (*f)(doggy_Opat));
extern void Memo_Clear_doggy_Opat (void);
extern doggy_Opat Create_doggy_Opat	(SrcInfo src_info, List_doggy_Type args, doggy_Type result);

#endif /* DEF_STRUCT_doggy_Opat */

#ifndef DEF_STRUCT_doggy_Format
#define DEF_STRUCT_doggy_Format

struct s_doggy_Format {
  SrcInfo       src_info;  
  doggy_Format  memo_link;  
  List_doggy_Type       args;  
  doggy_Type    result;  
  Bool  swap;  
  Int   num;  
} ;

#define doggy_Format_src_info(_p)       ((*_p).src_info)
#define doggy_Format_srcinfo(_p)        ((*_p).src_info)
#define doggy_Format_loc(_p)    ((*_p).src_info->loc)
#define doggy_Format_memo_link(_p)      ((*_p).memo_link)
#define doggy_Format_args(_p)   ((*_p).args)
#define doggy_Format_result(_p) ((*_p).result)
#define doggy_Format_swap(_p)   ((*_p).swap)
#define doggy_Format_num(_p)    ((*_p).num)

extern void Memo_Traverse_doggy_Format (void (*f)(doggy_Format));
extern void Memo_Clear_doggy_Format (void);
extern doggy_Format Create_doggy_Format	(SrcInfo src_info, List_doggy_Type args, doggy_Type result, Bool swap);

#endif /* DEF_STRUCT_doggy_Format */

#ifndef DEF_STRUCT_doggy_dummy_type
#define DEF_STRUCT_doggy_dummy_type

struct s_doggy_dummy_type {
  SrcInfo       src_info;  
  List_Ident    a;  
  List_List_doggy_Type  x;  
  List_doggy_ActualOp   y;  
  List_doggy_TypePair   z;  
  List_List_doggy_TypePair      b;  
} ;

#define doggy_dummy_type_src_info(_p)   ((*_p).src_info)
#define doggy_dummy_type_srcinfo(_p)    ((*_p).src_info)
#define doggy_dummy_type_loc(_p)        ((*_p).src_info->loc)
#define doggy_dummy_type_a(_p)  ((*_p).a)
#define doggy_dummy_type_x(_p)  ((*_p).x)
#define doggy_dummy_type_y(_p)  ((*_p).y)
#define doggy_dummy_type_z(_p)  ((*_p).z)
#define doggy_dummy_type_b(_p)  ((*_p).b)

extern doggy_dummy_type Create_doggy_dummy_type	(SrcInfo src_info, List_Ident a, List_doggy_ActualOp y, List_doggy_TypePair z);

#endif /* DEF_STRUCT_doggy_dummy_type */

#ifndef DEF_STRUCT_doggy_Scope
#define DEF_STRUCT_doggy_Scope

struct s_doggy_Scope {
  doggy_Scope   next;  
  Int   _self;  
  Int   _end;  
  doggy_Scope_tag       tag;  
  union {
  struct s_doggy_OpSetScope {
    doggy_Applied_operation     data;  
  } doggy_OpSetScope;
  struct s_doggy_AppliedOpScope {
    doggy_Applied_operation     data;  
  } doggy_AppliedOpScope;
  struct s_doggy_ExprGuardScope {
    doggy_Guard data;  
  } doggy_ExprGuardScope;
  struct s_doggy_RhsGuardScope {
    doggy_Guard data;  
  } doggy_RhsGuardScope;
  struct s_doggy_FuncRuleScope {
    doggy_FuncRule      data;  
  } doggy_FuncRuleScope;
  struct s_doggy_RuleScope {
    doggy_Rule  data;  
  } doggy_RuleScope;
  struct s_doggy_machine_descriptionScope {
    doggy_machine_description   data;  
  } doggy_machine_descriptionScope;
} sub;
} ;

#define doggy_Scope_next(_p)    ((*_p).next)
#define doggy_Scope__self(_p)   ((*_p)._self)
#define doggy_Scope__end(_p)    ((*_p)._end)
#define doggy_Scope_tag(_p)     ((*_p).tag)
#define doggy_OpSetScope_data(_p)       ((*_p).sub.doggy_OpSetScope.data)
#define doggy_AppliedOpScope_data(_p)   ((*_p).sub.doggy_AppliedOpScope.data)
#define doggy_ExprGuardScope_data(_p)   ((*_p).sub.doggy_ExprGuardScope.data)
#define doggy_RhsGuardScope_data(_p)    ((*_p).sub.doggy_RhsGuardScope.data)
#define doggy_FuncRuleScope_data(_p)    ((*_p).sub.doggy_FuncRuleScope.data)
#define doggy_RuleScope_data(_p)        ((*_p).sub.doggy_RuleScope.data)
#define doggy_machine_descriptionScope_data(_p) ((*_p).sub.doggy_machine_descriptionScope.data)

extern doggy_machine_descriptionScope Create_doggy_machine_descriptionScope	(doggy_Scope next, doggy_machine_description data);
extern doggy_RuleScope Create_doggy_RuleScope	(doggy_Scope next, doggy_Rule data);
extern doggy_FuncRuleScope Create_doggy_FuncRuleScope	(doggy_Scope next, doggy_FuncRule data);
extern doggy_RhsGuardScope Create_doggy_RhsGuardScope	(doggy_Scope next, doggy_Guard data);
extern doggy_ExprGuardScope Create_doggy_ExprGuardScope	(doggy_Scope next, doggy_Guard data);
extern doggy_AppliedOpScope Create_doggy_AppliedOpScope	(doggy_Scope next, doggy_Applied_operation data);
extern doggy_OpSetScope Create_doggy_OpSetScope	(doggy_Scope next, doggy_Applied_operation data);

#endif /* DEF_STRUCT_doggy_Scope */

#ifndef DEF_STRUCT_List_doggy_Num
#define DEF_STRUCT_List_doggy_Num

struct s_List_doggy_Num {
  doggy_Num     data;  
  List_doggy_Num        next;  
} ;

#define List_doggy_Num_data(_p) ((*_p).data)
#define List_doggy_Num_next(_p) ((*_p).next)

#ifndef Create_List_doggy_Num
#define Create_List_doggy_Num(x,y) (List_doggy_Num)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Num_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Num */

#ifndef DEF_STRUCT_List_List_doggy_TypePair
#define DEF_STRUCT_List_List_doggy_TypePair

struct s_List_List_doggy_TypePair {
  List_doggy_TypePair   data;  
  List_List_doggy_TypePair      next;  
} ;

#define List_List_doggy_TypePair_data(_p)       ((*_p).data)
#define List_List_doggy_TypePair_next(_p)       ((*_p).next)

#ifndef Create_List_List_doggy_TypePair
#define Create_List_List_doggy_TypePair(x,y) (List_List_doggy_TypePair)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_List_doggy_TypePair_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_List_doggy_TypePair */

#ifndef DEF_STRUCT_List_doggy_TypePair
#define DEF_STRUCT_List_doggy_TypePair

struct s_List_doggy_TypePair {
  doggy_TypePair        data;  
  List_doggy_TypePair   next;  
} ;

#define List_doggy_TypePair_data(_p)    ((*_p).data)
#define List_doggy_TypePair_next(_p)    ((*_p).next)

#ifndef Create_List_doggy_TypePair
#define Create_List_doggy_TypePair(x,y) (List_doggy_TypePair)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_TypePair_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_TypePair */

#ifndef DEF_STRUCT_List_doggy_ActualOp
#define DEF_STRUCT_List_doggy_ActualOp

struct s_List_doggy_ActualOp {
  doggy_ActualOp        data;  
  List_doggy_ActualOp   next;  
} ;

#define List_doggy_ActualOp_data(_p)    ((*_p).data)
#define List_doggy_ActualOp_next(_p)    ((*_p).next)

#ifndef Create_List_doggy_ActualOp
#define Create_List_doggy_ActualOp(x,y) (List_doggy_ActualOp)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_ActualOp_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_ActualOp */

#ifndef DEF_STRUCT_List_List_doggy_Type
#define DEF_STRUCT_List_List_doggy_Type

struct s_List_List_doggy_Type {
  List_doggy_Type       data;  
  List_List_doggy_Type  next;  
} ;

#define List_List_doggy_Type_data(_p)   ((*_p).data)
#define List_List_doggy_Type_next(_p)   ((*_p).next)

#ifndef Create_List_List_doggy_Type
#define Create_List_List_doggy_Type(x,y) (List_List_doggy_Type)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_List_doggy_Type_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_List_doggy_Type */

#ifndef DEF_STRUCT_List_doggy_Operator
#define DEF_STRUCT_List_doggy_Operator

struct s_List_doggy_Operator {
  doggy_Operator        data;  
  List_doggy_Operator   next;  
} ;

#define List_doggy_Operator_data(_p)    ((*_p).data)
#define List_doggy_Operator_next(_p)    ((*_p).next)

#ifndef Create_List_doggy_Operator
#define Create_List_doggy_Operator(x,y) (List_doggy_Operator)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Operator_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Operator */

#ifndef DEF_STRUCT_List_doggy_Definition
#define DEF_STRUCT_List_doggy_Definition

struct s_List_doggy_Definition {
  doggy_Definition      data;  
  List_doggy_Definition next;  
} ;

#define List_doggy_Definition_data(_p)  ((*_p).data)
#define List_doggy_Definition_next(_p)  ((*_p).next)

#ifndef Create_List_doggy_Definition
#define Create_List_doggy_Definition(x,y) (List_doggy_Definition)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Definition_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Definition */

#ifndef DEF_STRUCT_List_doggy_Expr
#define DEF_STRUCT_List_doggy_Expr

struct s_List_doggy_Expr {
  doggy_Expr    data;  
  List_doggy_Expr       next;  
} ;

#define List_doggy_Expr_data(_p)        ((*_p).data)
#define List_doggy_Expr_next(_p)        ((*_p).next)

#ifndef Create_List_doggy_Expr
#define Create_List_doggy_Expr(x,y) (List_doggy_Expr)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Expr_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Expr */

#ifndef DEF_STRUCT_List_doggy_Guard
#define DEF_STRUCT_List_doggy_Guard

struct s_List_doggy_Guard {
  doggy_Guard   data;  
  List_doggy_Guard      next;  
} ;

#define List_doggy_Guard_data(_p)       ((*_p).data)
#define List_doggy_Guard_next(_p)       ((*_p).next)

#ifndef Create_List_doggy_Guard
#define Create_List_doggy_Guard(x,y) (List_doggy_Guard)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Guard_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Guard */

#ifndef DEF_STRUCT_List_doggy_Pattern
#define DEF_STRUCT_List_doggy_Pattern

struct s_List_doggy_Pattern {
  doggy_Pattern data;  
  List_doggy_Pattern    next;  
} ;

#define List_doggy_Pattern_data(_p)     ((*_p).data)
#define List_doggy_Pattern_next(_p)     ((*_p).next)

#ifndef Create_List_doggy_Pattern
#define Create_List_doggy_Pattern(x,y) (List_doggy_Pattern)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Pattern_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Pattern */

#ifndef DEF_STRUCT_List_doggy_Argument
#define DEF_STRUCT_List_doggy_Argument

struct s_List_doggy_Argument {
  doggy_Argument        data;  
  List_doggy_Argument   next;  
} ;

#define List_doggy_Argument_data(_p)    ((*_p).data)
#define List_doggy_Argument_next(_p)    ((*_p).next)

#ifndef Create_List_doggy_Argument
#define Create_List_doggy_Argument(x,y) (List_doggy_Argument)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Argument_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Argument */

#ifndef DEF_STRUCT_List_doggy_FuncRule
#define DEF_STRUCT_List_doggy_FuncRule

struct s_List_doggy_FuncRule {
  doggy_FuncRule        data;  
  List_doggy_FuncRule   next;  
} ;

#define List_doggy_FuncRule_data(_p)    ((*_p).data)
#define List_doggy_FuncRule_next(_p)    ((*_p).next)

#ifndef Create_List_doggy_FuncRule
#define Create_List_doggy_FuncRule(x,y) (List_doggy_FuncRule)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_FuncRule_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_FuncRule */

#ifndef DEF_STRUCT_List_doggy_Attribute
#define DEF_STRUCT_List_doggy_Attribute

struct s_List_doggy_Attribute {
  doggy_Attribute       data;  
  List_doggy_Attribute  next;  
} ;

#define List_doggy_Attribute_data(_p)   ((*_p).data)
#define List_doggy_Attribute_next(_p)   ((*_p).next)

#ifndef Create_List_doggy_Attribute
#define Create_List_doggy_Attribute(x,y) (List_doggy_Attribute)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Attribute_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Attribute */

#ifndef DEF_STRUCT_List_doggy_Property
#define DEF_STRUCT_List_doggy_Property

struct s_List_doggy_Property {
  doggy_Property        data;  
  List_doggy_Property   next;  
} ;

#define List_doggy_Property_data(_p)    ((*_p).data)
#define List_doggy_Property_next(_p)    ((*_p).next)

#ifndef Create_List_doggy_Property
#define Create_List_doggy_Property(x,y) (List_doggy_Property)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Property_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Property */

#ifndef DEF_STRUCT_List_doggy_Applied_formal
#define DEF_STRUCT_List_doggy_Applied_formal

struct s_List_doggy_Applied_formal {
  doggy_Applied_formal  data;  
  List_doggy_Applied_formal     next;  
} ;

#define List_doggy_Applied_formal_data(_p)      ((*_p).data)
#define List_doggy_Applied_formal_next(_p)      ((*_p).next)

#ifndef Create_List_doggy_Applied_formal
#define Create_List_doggy_Applied_formal(x,y) (List_doggy_Applied_formal)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Applied_formal_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Applied_formal */

#ifndef DEF_STRUCT_List_doggy_Operation_def
#define DEF_STRUCT_List_doggy_Operation_def

struct s_List_doggy_Operation_def {
  doggy_Operation_def   data;  
  List_doggy_Operation_def      next;  
} ;

#define List_doggy_Operation_def_data(_p)       ((*_p).data)
#define List_doggy_Operation_def_next(_p)       ((*_p).next)

#ifndef Create_List_doggy_Operation_def
#define Create_List_doggy_Operation_def(x,y) (List_doggy_Operation_def)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Operation_def_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Operation_def */

#ifndef DEF_STRUCT_List_doggy_Type
#define DEF_STRUCT_List_doggy_Type

struct s_List_doggy_Type {
  doggy_Type    data;  
  List_doggy_Type       next;  
} ;

#define List_doggy_Type_data(_p)        ((*_p).data)
#define List_doggy_Type_next(_p)        ((*_p).next)

#ifndef Create_List_doggy_Type
#define Create_List_doggy_Type(x,y) (List_doggy_Type)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Type_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Type */

#ifndef DEF_STRUCT_List_doggy_Rule
#define DEF_STRUCT_List_doggy_Rule

struct s_List_doggy_Rule {
  doggy_Rule    data;  
  List_doggy_Rule       next;  
} ;

#define List_doggy_Rule_data(_p)        ((*_p).data)
#define List_doggy_Rule_next(_p)        ((*_p).next)

#ifndef Create_List_doggy_Rule
#define Create_List_doggy_Rule(x,y) (List_doggy_Rule)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Rule_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Rule */

#ifndef DEF_STRUCT_List_doggy_Func
#define DEF_STRUCT_List_doggy_Func

struct s_List_doggy_Func {
  doggy_Func    data;  
  List_doggy_Func       next;  
} ;

#define List_doggy_Func_data(_p)        ((*_p).data)
#define List_doggy_Func_next(_p)        ((*_p).next)

#ifndef Create_List_doggy_Func
#define Create_List_doggy_Func(x,y) (List_doggy_Func)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Func_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Func */

#ifndef DEF_STRUCT_List_doggy_Section
#define DEF_STRUCT_List_doggy_Section

struct s_List_doggy_Section {
  doggy_Section data;  
  List_doggy_Section    next;  
} ;

#define List_doggy_Section_data(_p)     ((*_p).data)
#define List_doggy_Section_next(_p)     ((*_p).next)

#ifndef Create_List_doggy_Section
#define Create_List_doggy_Section(x,y) (List_doggy_Section)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Section_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Section */

#ifndef DEF_STRUCT_List_doggy_FunctionDef
#define DEF_STRUCT_List_doggy_FunctionDef

struct s_List_doggy_FunctionDef {
  doggy_FunctionDef     data;  
  List_doggy_FunctionDef        next;  
} ;

#define List_doggy_FunctionDef_data(_p) ((*_p).data)
#define List_doggy_FunctionDef_next(_p) ((*_p).next)

#ifndef Create_List_doggy_FunctionDef
#define Create_List_doggy_FunctionDef(x,y) (List_doggy_FunctionDef)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_FunctionDef_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_FunctionDef */

#ifndef DEF_STRUCT_List_doggy_Typedef
#define DEF_STRUCT_List_doggy_Typedef

struct s_List_doggy_Typedef {
  doggy_Typedef data;  
  List_doggy_Typedef    next;  
} ;

#define List_doggy_Typedef_data(_p)     ((*_p).data)
#define List_doggy_Typedef_next(_p)     ((*_p).next)

#ifndef Create_List_doggy_Typedef
#define Create_List_doggy_Typedef(x,y) (List_doggy_Typedef)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_doggy_Typedef_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_doggy_Typedef */

#define PRE_ACTION  1
#define POST_ACTION 0

typedef struct s_doggy_TraverseTable {
  Front_Traversal traversal;
  Pointer (*action_doggy[2]) (doggy_doggy, Pointer);
  Bool skip_children_doggy;
  Pointer (*action_Typedef[2]) (doggy_Typedef, Pointer);
  Bool skip_children_Typedef;
  Pointer (*action_FunctionDef[2]) (doggy_FunctionDef, Pointer);
  Bool skip_children_FunctionDef;
  Pointer (*action_ExtFunc[2]) (doggy_ExtFunc, Pointer);
  Bool skip_children_ExtFunc;
  Pointer (*action_ExtVar[2]) (doggy_ExtVar, Pointer);
  Bool skip_children_ExtVar;
  Pointer (*action_machine_description[2]) (doggy_machine_description, Pointer);
  Bool skip_children_machine_description;
  Pointer (*action_Operation_def[2]) (doggy_Operation_def, Pointer);
  Bool skip_children_Operation_def;
  Pointer (*action_Attributes[2]) (doggy_Attributes, Pointer);
  Bool skip_children_Attributes;
  Pointer (*action_Attribute[2]) (doggy_Attribute, Pointer);
  Bool skip_children_Attribute;
  Pointer (*action_IdAttr[2]) (doggy_IdAttr, Pointer);
  Bool skip_children_IdAttr;
  Pointer (*action_OpAttr[2]) (doggy_OpAttr, Pointer);
  Bool skip_children_OpAttr;
  Pointer (*action_IntAttr[2]) (doggy_IntAttr, Pointer);
  Bool skip_children_IntAttr;
  Pointer (*action_Section[2]) (doggy_Section, Pointer);
  Bool skip_children_Section;
  Pointer (*action_FuncSection[2]) (doggy_FuncSection, Pointer);
  Bool skip_children_FuncSection;
  Pointer (*action_RuleSection[2]) (doggy_RuleSection, Pointer);
  Bool skip_children_RuleSection;
  Pointer (*action_Rule[2]) (doggy_Rule, Pointer);
  Bool skip_children_Rule;
  Pointer (*action_Lhs[2]) (doggy_Lhs, Pointer);
  Bool skip_children_Lhs;
  Pointer (*action_LabeledLhs[2]) (doggy_LabeledLhs, Pointer);
  Bool skip_children_LabeledLhs;
  Pointer (*action_UnLabeledLhs[2]) (doggy_UnLabeledLhs, Pointer);
  Bool skip_children_UnLabeledLhs;
  Pointer (*action_Func[2]) (doggy_Func, Pointer);
  Bool skip_children_Func;
  Pointer (*action_FuncRule[2]) (doggy_FuncRule, Pointer);
  Bool skip_children_FuncRule;
  Pointer (*action_Argument[2]) (doggy_Argument, Pointer);
  Bool skip_children_Argument;
  Pointer (*action_TypedArg[2]) (doggy_TypedArg, Pointer);
  Bool skip_children_TypedArg;
  Pointer (*action_UnTypedArg[2]) (doggy_UnTypedArg, Pointer);
  Bool skip_children_UnTypedArg;
  Pointer (*action_ArgPat[2]) (doggy_ArgPat, Pointer);
  Bool skip_children_ArgPat;
  Pointer (*action_PatArg[2]) (doggy_PatArg, Pointer);
  Bool skip_children_PatArg;
  Pointer (*action_SetArg[2]) (doggy_SetArg, Pointer);
  Bool skip_children_SetArg;
  Pointer (*action_Pattern[2]) (doggy_Pattern, Pointer);
  Bool skip_children_Pattern;
  Pointer (*action_TypedPattern[2]) (doggy_TypedPattern, Pointer);
  Bool skip_children_TypedPattern;
  Pointer (*action_ConsPattern[2]) (doggy_ConsPattern, Pointer);
  Bool skip_children_ConsPattern;
  Pointer (*action_DefPattern[2]) (doggy_DefPattern, Pointer);
  Bool skip_children_DefPattern;
  Pointer (*action_IdentPattern[2]) (doggy_IdentPattern, Pointer);
  Bool skip_children_IdentPattern;
  Pointer (*action_BasicPattern[2]) (doggy_BasicPattern, Pointer);
  Bool skip_children_BasicPattern;
  Pointer (*action_OpPattern[2]) (doggy_OpPattern, Pointer);
  Bool skip_children_OpPattern;
  Pointer (*action_ConstPattern[2]) (doggy_ConstPattern, Pointer);
  Bool skip_children_ConstPattern;
  Pointer (*action_NullPattern[2]) (doggy_NullPattern, Pointer);
  Bool skip_children_NullPattern;
  Pointer (*action_DontCarePattern[2]) (doggy_DontCarePattern, Pointer);
  Bool skip_children_DontCarePattern;
  Pointer (*action_Rhs[2]) (doggy_Rhs, Pointer);
  Bool skip_children_Rhs;
  Pointer (*action_PlainRhs[2]) (doggy_PlainRhs, Pointer);
  Bool skip_children_PlainRhs;
  Pointer (*action_BlockRhs[2]) (doggy_BlockRhs, Pointer);
  Bool skip_children_BlockRhs;
  Pointer (*action_Guard[2]) (doggy_Guard, Pointer);
  Bool skip_children_Guard;
  Pointer (*action_RhsGuard[2]) (doggy_RhsGuard, Pointer);
  Bool skip_children_RhsGuard;
  Pointer (*action_ExprGuard[2]) (doggy_ExprGuard, Pointer);
  Bool skip_children_ExprGuard;
  Pointer (*action_ExprSeq[2]) (doggy_ExprSeq, Pointer);
  Bool skip_children_ExprSeq;
  Pointer (*action_OneExpr[2]) (doggy_OneExpr, Pointer);
  Bool skip_children_OneExpr;
  Pointer (*action_MoreExprs[2]) (doggy_MoreExprs, Pointer);
  Bool skip_children_MoreExprs;
  Pointer (*action_Wherepart[2]) (doggy_Wherepart, Pointer);
  Bool skip_children_Wherepart;
  Pointer (*action_Applied_operation[2]) (doggy_Applied_operation, Pointer);
  Bool skip_children_Applied_operation;
  Pointer (*action_AnyOp[2]) (doggy_AnyOp, Pointer);
  Bool skip_children_AnyOp;
  Pointer (*action_AppliedOp[2]) (doggy_AppliedOp, Pointer);
  Bool skip_children_AppliedOp;
  Pointer (*action_OpSet[2]) (doggy_OpSet, Pointer);
  Bool skip_children_OpSet;
  Pointer (*action_Applied_formal[2]) (doggy_Applied_formal, Pointer);
  Bool skip_children_Applied_formal;
  Pointer (*action_Expr[2]) (doggy_Expr, Pointer);
  Bool skip_children_Expr;
  Pointer (*action_BinExpr[2]) (doggy_BinExpr, Pointer);
  Bool skip_children_BinExpr;
  Pointer (*action_ConsExpr[2]) (doggy_ConsExpr, Pointer);
  Bool skip_children_ConsExpr;
  Pointer (*action_SimpleExpr[2]) (doggy_SimpleExpr, Pointer);
  Bool skip_children_SimpleExpr;
  Pointer (*action_IdentExpr[2]) (doggy_IdentExpr, Pointer);
  Bool skip_children_IdentExpr;
  Pointer (*action_IfExpr[2]) (doggy_IfExpr, Pointer);
  Bool skip_children_IfExpr;
  Pointer (*action_ConstExpr[2]) (doggy_ConstExpr, Pointer);
  Bool skip_children_ConstExpr;
  Pointer (*action_Operation[2]) (doggy_Operation, Pointer);
  Bool skip_children_Operation;
  Pointer (*action_ParExpr[2]) (doggy_ParExpr, Pointer);
  Bool skip_children_ParExpr;
  Pointer (*action_MonExpr[2]) (doggy_MonExpr, Pointer);
  Bool skip_children_MonExpr;
  Pointer (*action_Constant[2]) (doggy_Constant, Pointer);
  Bool skip_children_Constant;
  Pointer (*action_IntConst[2]) (doggy_IntConst, Pointer);
  Bool skip_children_IntConst;
  Pointer (*action_BoolConst[2]) (doggy_BoolConst, Pointer);
  Bool skip_children_BoolConst;
  Pointer (*action_StringConst[2]) (doggy_StringConst, Pointer);
  Bool skip_children_StringConst;
  Pointer (*action_NullConst[2]) (doggy_NullConst, Pointer);
  Bool skip_children_NullConst;
  Pointer (*action_Definition[2]) (doggy_Definition, Pointer);
  Bool skip_children_Definition;
  Pointer (*action_Type[2]) (doggy_Type, Pointer);
  Bool skip_children_Type;
  Pointer (*action_EdgeType[2]) (doggy_EdgeType, Pointer);
  Bool skip_children_EdgeType;
  Pointer (*action_TupleType[2]) (doggy_TupleType, Pointer);
  Bool skip_children_TupleType;
  Pointer (*action_BasicType[2]) (doggy_BasicType, Pointer);
  Bool skip_children_BasicType;
  Pointer (*action_IdentType[2]) (doggy_IdentType, Pointer);
  Bool skip_children_IdentType;
  Pointer (*action_OprType[2]) (doggy_OprType, Pointer);
  Bool skip_children_OprType;
  Pointer (*action_PointerType[2]) (doggy_PointerType, Pointer);
  Bool skip_children_PointerType;
  Pointer (*action_RangeType[2]) (doggy_RangeType, Pointer);
  Bool skip_children_RangeType;
  Pointer (*action_FRangeType[2]) (doggy_FRangeType, Pointer);
  Bool skip_children_FRangeType;
  Pointer (*action_Num[2]) (doggy_Num, Pointer);
  Bool skip_children_Num;
  Pointer (*action_IdInt[2]) (doggy_IdInt, Pointer);
  Bool skip_children_IdInt;
  Pointer (*action_IsId[2]) (doggy_IsId, Pointer);
  Bool skip_children_IsId;
  Pointer (*action_IsInt[2]) (doggy_IsInt, Pointer);
  Bool skip_children_IsInt;
  Pointer (*action_Path[2]) (doggy_Path, Pointer);
  Bool skip_children_Path;
  Pointer (*action_ActualOp[2]) (doggy_ActualOp, Pointer);
  Bool skip_children_ActualOp;
  Pointer (*action_TypePair[2]) (doggy_TypePair, Pointer);
  Bool skip_children_TypePair;
  Pointer (*action_Opat[2]) (doggy_Opat, Pointer);
  Bool skip_children_Opat;
  Pointer (*action_Format[2]) (doggy_Format, Pointer);
  Bool skip_children_Format;
  Pointer (*action_dummy_type[2]) (doggy_dummy_type, Pointer);
  Bool skip_children_dummy_type;
  Pointer (*action_Scope[2]) (doggy_Scope, Pointer);
  Bool skip_children_Scope;
  Pointer (*action_OpSetScope[2]) (doggy_OpSetScope, Pointer);
  Bool skip_children_OpSetScope;
  Pointer (*action_AppliedOpScope[2]) (doggy_AppliedOpScope, Pointer);
  Bool skip_children_AppliedOpScope;
  Pointer (*action_ExprGuardScope[2]) (doggy_ExprGuardScope, Pointer);
  Bool skip_children_ExprGuardScope;
  Pointer (*action_RhsGuardScope[2]) (doggy_RhsGuardScope, Pointer);
  Bool skip_children_RhsGuardScope;
  Pointer (*action_FuncRuleScope[2]) (doggy_FuncRuleScope, Pointer);
  Bool skip_children_FuncRuleScope;
  Pointer (*action_RuleScope[2]) (doggy_RuleScope, Pointer);
  Bool skip_children_RuleScope;
  Pointer (*action_machine_descriptionScope[2]) (doggy_machine_descriptionScope, Pointer);
  Bool skip_children_machine_descriptionScope;
  Pointer (*action_List_Num[2]) (List_doggy_Num, Pointer);
  Bool skip_children_List_Num;
  Pointer (*action_List_List_TypePair[2]) (List_List_doggy_TypePair, Pointer);
  Bool skip_children_List_List_TypePair;
  Pointer (*action_List_TypePair[2]) (List_doggy_TypePair, Pointer);
  Bool skip_children_List_TypePair;
  Pointer (*action_List_ActualOp[2]) (List_doggy_ActualOp, Pointer);
  Bool skip_children_List_ActualOp;
  Pointer (*action_List_List_Type[2]) (List_List_doggy_Type, Pointer);
  Bool skip_children_List_List_Type;
  Pointer (*action_List_Operator[2]) (List_doggy_Operator, Pointer);
  Bool skip_children_List_Operator;
  Pointer (*action_List_Definition[2]) (List_doggy_Definition, Pointer);
  Bool skip_children_List_Definition;
  Pointer (*action_List_Expr[2]) (List_doggy_Expr, Pointer);
  Bool skip_children_List_Expr;
  Pointer (*action_List_Guard[2]) (List_doggy_Guard, Pointer);
  Bool skip_children_List_Guard;
  Pointer (*action_List_Pattern[2]) (List_doggy_Pattern, Pointer);
  Bool skip_children_List_Pattern;
  Pointer (*action_List_Argument[2]) (List_doggy_Argument, Pointer);
  Bool skip_children_List_Argument;
  Pointer (*action_List_FuncRule[2]) (List_doggy_FuncRule, Pointer);
  Bool skip_children_List_FuncRule;
  Pointer (*action_List_Attribute[2]) (List_doggy_Attribute, Pointer);
  Bool skip_children_List_Attribute;
  Pointer (*action_List_Property[2]) (List_doggy_Property, Pointer);
  Bool skip_children_List_Property;
  Pointer (*action_List_Applied_formal[2]) (List_doggy_Applied_formal, Pointer);
  Bool skip_children_List_Applied_formal;
  Pointer (*action_List_Operation_def[2]) (List_doggy_Operation_def, Pointer);
  Bool skip_children_List_Operation_def;
  Pointer (*action_List_Type[2]) (List_doggy_Type, Pointer);
  Bool skip_children_List_Type;
  Pointer (*action_List_Rule[2]) (List_doggy_Rule, Pointer);
  Bool skip_children_List_Rule;
  Pointer (*action_List_Func[2]) (List_doggy_Func, Pointer);
  Bool skip_children_List_Func;
  Pointer (*action_List_Section[2]) (List_doggy_Section, Pointer);
  Bool skip_children_List_Section;
  Pointer (*action_List_FunctionDef[2]) (List_doggy_FunctionDef, Pointer);
  Bool skip_children_List_FunctionDef;
  Pointer (*action_List_Typedef[2]) (List_doggy_Typedef, Pointer);
  Bool skip_children_List_Typedef;
  Pointer (*action_Operator[2]) (doggy_Operator, Pointer);
  Bool skip_children_Operator;
  Pointer (*action_CandOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_CandOp;
  Pointer (*action_CorOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_CorOp;
  Pointer (*action_XorOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_XorOp;
  Pointer (*action_EqOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_EqOp;
  Pointer (*action_NeqOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_NeqOp;
  Pointer (*action_LEOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_LEOp;
  Pointer (*action_GEOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_GEOp;
  Pointer (*action_LTOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_LTOp;
  Pointer (*action_GTOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_GTOp;
  Pointer (*action_SLOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_SLOp;
  Pointer (*action_SROp[2]) (doggy_Operator, Pointer);
  Bool skip_children_SROp;
  Pointer (*action_DivOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_DivOp;
  Pointer (*action_ModOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_ModOp;
  Pointer (*action_MulOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_MulOp;
  Pointer (*action_AndOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_AndOp;
  Pointer (*action_AddOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_AddOp;
  Pointer (*action_SubOp[2]) (doggy_Operator, Pointer);
  Bool skip_children_SubOp;
  Pointer (*action_MonOp[2]) (doggy_MonOp, Pointer);
  Bool skip_children_MonOp;
  Pointer (*action_NotOp[2]) (doggy_MonOp, Pointer);
  Bool skip_children_NotOp;
  Pointer (*action_NegOp[2]) (doggy_MonOp, Pointer);
  Bool skip_children_NegOp;
  Pointer (*action_AddrOp[2]) (doggy_MonOp, Pointer);
  Bool skip_children_AddrOp;
  Pointer (*action_DerefOp[2]) (doggy_MonOp, Pointer);
  Bool skip_children_DerefOp;
  Pointer (*action_PlusOp[2]) (doggy_MonOp, Pointer);
  Bool skip_children_PlusOp;
  Pointer (*action_MinOp[2]) (doggy_MonOp, Pointer);
  Bool skip_children_MinOp;
  Pointer (*action_Property[2]) (doggy_Property, Pointer);
  Bool skip_children_Property;
} *doggy_TraverseTable;

extern Pointer Traverse_doggy_Operator (doggy_Operator me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_MonOp (doggy_MonOp me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Property (doggy_Property me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_doggy (doggy_doggy me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Typedef (doggy_Typedef me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_FunctionDef (doggy_FunctionDef me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_machine_description (doggy_machine_description me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Operation_def (doggy_Operation_def me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Attributes (doggy_Attributes me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Attribute (doggy_Attribute me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Section (doggy_Section me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Rule (doggy_Rule me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Lhs (doggy_Lhs me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Func (doggy_Func me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_FuncRule (doggy_FuncRule me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Argument (doggy_Argument me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_ArgPat (doggy_ArgPat me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Pattern (doggy_Pattern me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Rhs (doggy_Rhs me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Guard (doggy_Guard me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_ExprSeq (doggy_ExprSeq me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Wherepart (doggy_Wherepart me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Applied_operation (doggy_Applied_operation me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Applied_formal (doggy_Applied_formal me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Expr (doggy_Expr me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Constant (doggy_Constant me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Definition (doggy_Definition me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Type (doggy_Type me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Num (doggy_Num me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_IdInt (doggy_IdInt me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Path (doggy_Path me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_ActualOp (doggy_ActualOp me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_TypePair (doggy_TypePair me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Opat (doggy_Opat me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Format (doggy_Format me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_dummy_type (doggy_dummy_type me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_doggy_Scope (doggy_Scope me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Num (List_doggy_Num me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_List_doggy_TypePair (List_List_doggy_TypePair me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_TypePair (List_doggy_TypePair me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_ActualOp (List_doggy_ActualOp me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_List_doggy_Type (List_List_doggy_Type me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Operator (List_doggy_Operator me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Definition (List_doggy_Definition me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Expr (List_doggy_Expr me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Guard (List_doggy_Guard me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Pattern (List_doggy_Pattern me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Argument (List_doggy_Argument me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_FuncRule (List_doggy_FuncRule me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Attribute (List_doggy_Attribute me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Property (List_doggy_Property me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Applied_formal (List_doggy_Applied_formal me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Operation_def (List_doggy_Operation_def me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Type (List_doggy_Type me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Rule (List_doggy_Rule me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Func (List_doggy_Func me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Section (List_doggy_Section me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_FunctionDef (List_doggy_FunctionDef me, doggy_TraverseTable table, Pointer val);
extern Pointer Traverse_List_doggy_Typedef (List_doggy_Typedef me, doggy_TraverseTable table, Pointer val);

typedef struct s_void_doggy_TraverseTable {
  void (*action_doggy[2]) (doggy_doggy);
  Bool skip_children_doggy;
  void (*action_Typedef[2]) (doggy_Typedef);
  Bool skip_children_Typedef;
  void (*action_FunctionDef[2]) (doggy_FunctionDef);
  Bool skip_children_FunctionDef;
  void (*action_ExtFunc[2]) (doggy_ExtFunc);
  Bool skip_children_ExtFunc;
  void (*action_ExtVar[2]) (doggy_ExtVar);
  Bool skip_children_ExtVar;
  void (*action_machine_description[2]) (doggy_machine_description);
  Bool skip_children_machine_description;
  void (*action_Operation_def[2]) (doggy_Operation_def);
  Bool skip_children_Operation_def;
  void (*action_Attributes[2]) (doggy_Attributes);
  Bool skip_children_Attributes;
  void (*action_Attribute[2]) (doggy_Attribute);
  Bool skip_children_Attribute;
  void (*action_IdAttr[2]) (doggy_IdAttr);
  Bool skip_children_IdAttr;
  void (*action_OpAttr[2]) (doggy_OpAttr);
  Bool skip_children_OpAttr;
  void (*action_IntAttr[2]) (doggy_IntAttr);
  Bool skip_children_IntAttr;
  void (*action_Section[2]) (doggy_Section);
  Bool skip_children_Section;
  void (*action_FuncSection[2]) (doggy_FuncSection);
  Bool skip_children_FuncSection;
  void (*action_RuleSection[2]) (doggy_RuleSection);
  Bool skip_children_RuleSection;
  void (*action_Rule[2]) (doggy_Rule);
  Bool skip_children_Rule;
  void (*action_Lhs[2]) (doggy_Lhs);
  Bool skip_children_Lhs;
  void (*action_LabeledLhs[2]) (doggy_LabeledLhs);
  Bool skip_children_LabeledLhs;
  void (*action_UnLabeledLhs[2]) (doggy_UnLabeledLhs);
  Bool skip_children_UnLabeledLhs;
  void (*action_Func[2]) (doggy_Func);
  Bool skip_children_Func;
  void (*action_FuncRule[2]) (doggy_FuncRule);
  Bool skip_children_FuncRule;
  void (*action_Argument[2]) (doggy_Argument);
  Bool skip_children_Argument;
  void (*action_TypedArg[2]) (doggy_TypedArg);
  Bool skip_children_TypedArg;
  void (*action_UnTypedArg[2]) (doggy_UnTypedArg);
  Bool skip_children_UnTypedArg;
  void (*action_ArgPat[2]) (doggy_ArgPat);
  Bool skip_children_ArgPat;
  void (*action_PatArg[2]) (doggy_PatArg);
  Bool skip_children_PatArg;
  void (*action_SetArg[2]) (doggy_SetArg);
  Bool skip_children_SetArg;
  void (*action_Pattern[2]) (doggy_Pattern);
  Bool skip_children_Pattern;
  void (*action_TypedPattern[2]) (doggy_TypedPattern);
  Bool skip_children_TypedPattern;
  void (*action_ConsPattern[2]) (doggy_ConsPattern);
  Bool skip_children_ConsPattern;
  void (*action_DefPattern[2]) (doggy_DefPattern);
  Bool skip_children_DefPattern;
  void (*action_IdentPattern[2]) (doggy_IdentPattern);
  Bool skip_children_IdentPattern;
  void (*action_BasicPattern[2]) (doggy_BasicPattern);
  Bool skip_children_BasicPattern;
  void (*action_OpPattern[2]) (doggy_OpPattern);
  Bool skip_children_OpPattern;
  void (*action_ConstPattern[2]) (doggy_ConstPattern);
  Bool skip_children_ConstPattern;
  void (*action_NullPattern[2]) (doggy_NullPattern);
  Bool skip_children_NullPattern;
  void (*action_DontCarePattern[2]) (doggy_DontCarePattern);
  Bool skip_children_DontCarePattern;
  void (*action_Rhs[2]) (doggy_Rhs);
  Bool skip_children_Rhs;
  void (*action_PlainRhs[2]) (doggy_PlainRhs);
  Bool skip_children_PlainRhs;
  void (*action_BlockRhs[2]) (doggy_BlockRhs);
  Bool skip_children_BlockRhs;
  void (*action_Guard[2]) (doggy_Guard);
  Bool skip_children_Guard;
  void (*action_RhsGuard[2]) (doggy_RhsGuard);
  Bool skip_children_RhsGuard;
  void (*action_ExprGuard[2]) (doggy_ExprGuard);
  Bool skip_children_ExprGuard;
  void (*action_ExprSeq[2]) (doggy_ExprSeq);
  Bool skip_children_ExprSeq;
  void (*action_OneExpr[2]) (doggy_OneExpr);
  Bool skip_children_OneExpr;
  void (*action_MoreExprs[2]) (doggy_MoreExprs);
  Bool skip_children_MoreExprs;
  void (*action_Wherepart[2]) (doggy_Wherepart);
  Bool skip_children_Wherepart;
  void (*action_Applied_operation[2]) (doggy_Applied_operation);
  Bool skip_children_Applied_operation;
  void (*action_AnyOp[2]) (doggy_AnyOp);
  Bool skip_children_AnyOp;
  void (*action_AppliedOp[2]) (doggy_AppliedOp);
  Bool skip_children_AppliedOp;
  void (*action_OpSet[2]) (doggy_OpSet);
  Bool skip_children_OpSet;
  void (*action_Applied_formal[2]) (doggy_Applied_formal);
  Bool skip_children_Applied_formal;
  void (*action_Expr[2]) (doggy_Expr);
  Bool skip_children_Expr;
  void (*action_BinExpr[2]) (doggy_BinExpr);
  Bool skip_children_BinExpr;
  void (*action_ConsExpr[2]) (doggy_ConsExpr);
  Bool skip_children_ConsExpr;
  void (*action_SimpleExpr[2]) (doggy_SimpleExpr);
  Bool skip_children_SimpleExpr;
  void (*action_IdentExpr[2]) (doggy_IdentExpr);
  Bool skip_children_IdentExpr;
  void (*action_IfExpr[2]) (doggy_IfExpr);
  Bool skip_children_IfExpr;
  void (*action_ConstExpr[2]) (doggy_ConstExpr);
  Bool skip_children_ConstExpr;
  void (*action_Operation[2]) (doggy_Operation);
  Bool skip_children_Operation;
  void (*action_ParExpr[2]) (doggy_ParExpr);
  Bool skip_children_ParExpr;
  void (*action_MonExpr[2]) (doggy_MonExpr);
  Bool skip_children_MonExpr;
  void (*action_Constant[2]) (doggy_Constant);
  Bool skip_children_Constant;
  void (*action_IntConst[2]) (doggy_IntConst);
  Bool skip_children_IntConst;
  void (*action_BoolConst[2]) (doggy_BoolConst);
  Bool skip_children_BoolConst;
  void (*action_StringConst[2]) (doggy_StringConst);
  Bool skip_children_StringConst;
  void (*action_NullConst[2]) (doggy_NullConst);
  Bool skip_children_NullConst;
  void (*action_Definition[2]) (doggy_Definition);
  Bool skip_children_Definition;
  void (*action_Type[2]) (doggy_Type);
  Bool skip_children_Type;
  void (*action_EdgeType[2]) (doggy_EdgeType);
  Bool skip_children_EdgeType;
  void (*action_TupleType[2]) (doggy_TupleType);
  Bool skip_children_TupleType;
  void (*action_BasicType[2]) (doggy_BasicType);
  Bool skip_children_BasicType;
  void (*action_IdentType[2]) (doggy_IdentType);
  Bool skip_children_IdentType;
  void (*action_OprType[2]) (doggy_OprType);
  Bool skip_children_OprType;
  void (*action_PointerType[2]) (doggy_PointerType);
  Bool skip_children_PointerType;
  void (*action_RangeType[2]) (doggy_RangeType);
  Bool skip_children_RangeType;
  void (*action_FRangeType[2]) (doggy_FRangeType);
  Bool skip_children_FRangeType;
  void (*action_Num[2]) (doggy_Num);
  Bool skip_children_Num;
  void (*action_IdInt[2]) (doggy_IdInt);
  Bool skip_children_IdInt;
  void (*action_IsId[2]) (doggy_IsId);
  Bool skip_children_IsId;
  void (*action_IsInt[2]) (doggy_IsInt);
  Bool skip_children_IsInt;
  void (*action_Path[2]) (doggy_Path);
  Bool skip_children_Path;
  void (*action_ActualOp[2]) (doggy_ActualOp);
  Bool skip_children_ActualOp;
  void (*action_TypePair[2]) (doggy_TypePair);
  Bool skip_children_TypePair;
  void (*action_Opat[2]) (doggy_Opat);
  Bool skip_children_Opat;
  void (*action_Format[2]) (doggy_Format);
  Bool skip_children_Format;
  void (*action_dummy_type[2]) (doggy_dummy_type);
  Bool skip_children_dummy_type;
  void (*action_Scope[2]) (doggy_Scope);
  Bool skip_children_Scope;
  void (*action_OpSetScope[2]) (doggy_OpSetScope);
  Bool skip_children_OpSetScope;
  void (*action_AppliedOpScope[2]) (doggy_AppliedOpScope);
  Bool skip_children_AppliedOpScope;
  void (*action_ExprGuardScope[2]) (doggy_ExprGuardScope);
  Bool skip_children_ExprGuardScope;
  void (*action_RhsGuardScope[2]) (doggy_RhsGuardScope);
  Bool skip_children_RhsGuardScope;
  void (*action_FuncRuleScope[2]) (doggy_FuncRuleScope);
  Bool skip_children_FuncRuleScope;
  void (*action_RuleScope[2]) (doggy_RuleScope);
  Bool skip_children_RuleScope;
  void (*action_machine_descriptionScope[2]) (doggy_machine_descriptionScope);
  Bool skip_children_machine_descriptionScope;
  void (*action_List_Num[2]) (List_doggy_Num);
  Bool skip_children_List_Num;
  void (*action_List_List_TypePair[2]) (List_List_doggy_TypePair);
  Bool skip_children_List_List_TypePair;
  void (*action_List_TypePair[2]) (List_doggy_TypePair);
  Bool skip_children_List_TypePair;
  void (*action_List_ActualOp[2]) (List_doggy_ActualOp);
  Bool skip_children_List_ActualOp;
  void (*action_List_List_Type[2]) (List_List_doggy_Type);
  Bool skip_children_List_List_Type;
  void (*action_List_Operator[2]) (List_doggy_Operator);
  Bool skip_children_List_Operator;
  void (*action_List_Definition[2]) (List_doggy_Definition);
  Bool skip_children_List_Definition;
  void (*action_List_Expr[2]) (List_doggy_Expr);
  Bool skip_children_List_Expr;
  void (*action_List_Guard[2]) (List_doggy_Guard);
  Bool skip_children_List_Guard;
  void (*action_List_Pattern[2]) (List_doggy_Pattern);
  Bool skip_children_List_Pattern;
  void (*action_List_Argument[2]) (List_doggy_Argument);
  Bool skip_children_List_Argument;
  void (*action_List_FuncRule[2]) (List_doggy_FuncRule);
  Bool skip_children_List_FuncRule;
  void (*action_List_Attribute[2]) (List_doggy_Attribute);
  Bool skip_children_List_Attribute;
  void (*action_List_Property[2]) (List_doggy_Property);
  Bool skip_children_List_Property;
  void (*action_List_Applied_formal[2]) (List_doggy_Applied_formal);
  Bool skip_children_List_Applied_formal;
  void (*action_List_Operation_def[2]) (List_doggy_Operation_def);
  Bool skip_children_List_Operation_def;
  void (*action_List_Type[2]) (List_doggy_Type);
  Bool skip_children_List_Type;
  void (*action_List_Rule[2]) (List_doggy_Rule);
  Bool skip_children_List_Rule;
  void (*action_List_Func[2]) (List_doggy_Func);
  Bool skip_children_List_Func;
  void (*action_List_Section[2]) (List_doggy_Section);
  Bool skip_children_List_Section;
  void (*action_List_FunctionDef[2]) (List_doggy_FunctionDef);
  Bool skip_children_List_FunctionDef;
  void (*action_List_Typedef[2]) (List_doggy_Typedef);
  Bool skip_children_List_Typedef;
  void (*action_Operator[2]) (doggy_Operator);
  Bool skip_children_Operator;
  void (*action_CandOp[2]) (doggy_Operator);
  Bool skip_children_CandOp;
  void (*action_CorOp[2]) (doggy_Operator);
  Bool skip_children_CorOp;
  void (*action_XorOp[2]) (doggy_Operator);
  Bool skip_children_XorOp;
  void (*action_EqOp[2]) (doggy_Operator);
  Bool skip_children_EqOp;
  void (*action_NeqOp[2]) (doggy_Operator);
  Bool skip_children_NeqOp;
  void (*action_LEOp[2]) (doggy_Operator);
  Bool skip_children_LEOp;
  void (*action_GEOp[2]) (doggy_Operator);
  Bool skip_children_GEOp;
  void (*action_LTOp[2]) (doggy_Operator);
  Bool skip_children_LTOp;
  void (*action_GTOp[2]) (doggy_Operator);
  Bool skip_children_GTOp;
  void (*action_SLOp[2]) (doggy_Operator);
  Bool skip_children_SLOp;
  void (*action_SROp[2]) (doggy_Operator);
  Bool skip_children_SROp;
  void (*action_DivOp[2]) (doggy_Operator);
  Bool skip_children_DivOp;
  void (*action_ModOp[2]) (doggy_Operator);
  Bool skip_children_ModOp;
  void (*action_MulOp[2]) (doggy_Operator);
  Bool skip_children_MulOp;
  void (*action_AndOp[2]) (doggy_Operator);
  Bool skip_children_AndOp;
  void (*action_AddOp[2]) (doggy_Operator);
  Bool skip_children_AddOp;
  void (*action_SubOp[2]) (doggy_Operator);
  Bool skip_children_SubOp;
  void (*action_MonOp[2]) (doggy_MonOp);
  Bool skip_children_MonOp;
  void (*action_NotOp[2]) (doggy_MonOp);
  Bool skip_children_NotOp;
  void (*action_NegOp[2]) (doggy_MonOp);
  Bool skip_children_NegOp;
  void (*action_AddrOp[2]) (doggy_MonOp);
  Bool skip_children_AddrOp;
  void (*action_DerefOp[2]) (doggy_MonOp);
  Bool skip_children_DerefOp;
  void (*action_PlusOp[2]) (doggy_MonOp);
  Bool skip_children_PlusOp;
  void (*action_MinOp[2]) (doggy_MonOp);
  Bool skip_children_MinOp;
  void (*action_Property[2]) (doggy_Property);
  Bool skip_children_Property;
} *void_doggy_TraverseTable;

extern void Traverse_void_doggy_Operator (doggy_Operator me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_MonOp (doggy_MonOp me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Property (doggy_Property me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_doggy (doggy_doggy me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Typedef (doggy_Typedef me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_FunctionDef (doggy_FunctionDef me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_machine_description (doggy_machine_description me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Operation_def (doggy_Operation_def me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Attributes (doggy_Attributes me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Attribute (doggy_Attribute me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Section (doggy_Section me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Rule (doggy_Rule me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Lhs (doggy_Lhs me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Func (doggy_Func me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_FuncRule (doggy_FuncRule me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Argument (doggy_Argument me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_ArgPat (doggy_ArgPat me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Pattern (doggy_Pattern me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Rhs (doggy_Rhs me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Guard (doggy_Guard me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_ExprSeq (doggy_ExprSeq me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Wherepart (doggy_Wherepart me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Applied_operation (doggy_Applied_operation me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Applied_formal (doggy_Applied_formal me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Expr (doggy_Expr me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Constant (doggy_Constant me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Definition (doggy_Definition me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Type (doggy_Type me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Num (doggy_Num me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_IdInt (doggy_IdInt me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Path (doggy_Path me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_ActualOp (doggy_ActualOp me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_TypePair (doggy_TypePair me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Opat (doggy_Opat me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Format (doggy_Format me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_dummy_type (doggy_dummy_type me, void_doggy_TraverseTable table);
extern void Traverse_void_doggy_Scope (doggy_Scope me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Num (List_doggy_Num me, void_doggy_TraverseTable table);
extern void Traverse_void_List_List_doggy_TypePair (List_List_doggy_TypePair me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_TypePair (List_doggy_TypePair me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_ActualOp (List_doggy_ActualOp me, void_doggy_TraverseTable table);
extern void Traverse_void_List_List_doggy_Type (List_List_doggy_Type me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Operator (List_doggy_Operator me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Definition (List_doggy_Definition me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Expr (List_doggy_Expr me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Guard (List_doggy_Guard me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Pattern (List_doggy_Pattern me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Argument (List_doggy_Argument me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_FuncRule (List_doggy_FuncRule me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Attribute (List_doggy_Attribute me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Property (List_doggy_Property me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Applied_formal (List_doggy_Applied_formal me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Operation_def (List_doggy_Operation_def me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Type (List_doggy_Type me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Rule (List_doggy_Rule me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Func (List_doggy_Func me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Section (List_doggy_Section me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_FunctionDef (List_doggy_FunctionDef me, void_doggy_TraverseTable table);
extern void Traverse_void_List_doggy_Typedef (List_doggy_Typedef me, void_doggy_TraverseTable table);

typedef struct s_copy_doggy_TraverseTable {
  Front_ClearBackEdges clear_back_edges;
  doggy_doggy (*action_doggy[2]) (doggy_doggy, doggy_doggy);
  Bool skip_children_doggy;
  doggy_Typedef (*action_Typedef[2]) (doggy_Typedef, doggy_Typedef);
  Bool skip_children_Typedef;
  doggy_FunctionDef (*action_FunctionDef[2]) (doggy_FunctionDef, doggy_FunctionDef);
  Bool skip_children_FunctionDef;
  doggy_ExtFunc (*action_ExtFunc[2]) (doggy_ExtFunc, doggy_ExtFunc);
  Bool skip_children_ExtFunc;
  doggy_ExtVar (*action_ExtVar[2]) (doggy_ExtVar, doggy_ExtVar);
  Bool skip_children_ExtVar;
  doggy_machine_description (*action_machine_description[2]) (doggy_machine_description, doggy_machine_description);
  Bool skip_children_machine_description;
  doggy_Operation_def (*action_Operation_def[2]) (doggy_Operation_def, doggy_Operation_def);
  Bool skip_children_Operation_def;
  doggy_Attributes (*action_Attributes[2]) (doggy_Attributes, doggy_Attributes);
  Bool skip_children_Attributes;
  doggy_Attribute (*action_Attribute[2]) (doggy_Attribute, doggy_Attribute);
  Bool skip_children_Attribute;
  doggy_IdAttr (*action_IdAttr[2]) (doggy_IdAttr, doggy_IdAttr);
  Bool skip_children_IdAttr;
  doggy_OpAttr (*action_OpAttr[2]) (doggy_OpAttr, doggy_OpAttr);
  Bool skip_children_OpAttr;
  doggy_IntAttr (*action_IntAttr[2]) (doggy_IntAttr, doggy_IntAttr);
  Bool skip_children_IntAttr;
  doggy_Section (*action_Section[2]) (doggy_Section, doggy_Section);
  Bool skip_children_Section;
  doggy_FuncSection (*action_FuncSection[2]) (doggy_FuncSection, doggy_FuncSection);
  Bool skip_children_FuncSection;
  doggy_RuleSection (*action_RuleSection[2]) (doggy_RuleSection, doggy_RuleSection);
  Bool skip_children_RuleSection;
  doggy_Rule (*action_Rule[2]) (doggy_Rule, doggy_Rule);
  Bool skip_children_Rule;
  doggy_Lhs (*action_Lhs[2]) (doggy_Lhs, doggy_Lhs);
  Bool skip_children_Lhs;
  doggy_LabeledLhs (*action_LabeledLhs[2]) (doggy_LabeledLhs, doggy_LabeledLhs);
  Bool skip_children_LabeledLhs;
  doggy_UnLabeledLhs (*action_UnLabeledLhs[2]) (doggy_UnLabeledLhs, doggy_UnLabeledLhs);
  Bool skip_children_UnLabeledLhs;
  doggy_Func (*action_Func[2]) (doggy_Func, doggy_Func);
  Bool skip_children_Func;
  doggy_FuncRule (*action_FuncRule[2]) (doggy_FuncRule, doggy_FuncRule);
  Bool skip_children_FuncRule;
  doggy_Argument (*action_Argument[2]) (doggy_Argument, doggy_Argument);
  Bool skip_children_Argument;
  doggy_TypedArg (*action_TypedArg[2]) (doggy_TypedArg, doggy_TypedArg);
  Bool skip_children_TypedArg;
  doggy_UnTypedArg (*action_UnTypedArg[2]) (doggy_UnTypedArg, doggy_UnTypedArg);
  Bool skip_children_UnTypedArg;
  doggy_ArgPat (*action_ArgPat[2]) (doggy_ArgPat, doggy_ArgPat);
  Bool skip_children_ArgPat;
  doggy_PatArg (*action_PatArg[2]) (doggy_PatArg, doggy_PatArg);
  Bool skip_children_PatArg;
  doggy_SetArg (*action_SetArg[2]) (doggy_SetArg, doggy_SetArg);
  Bool skip_children_SetArg;
  doggy_Pattern (*action_Pattern[2]) (doggy_Pattern, doggy_Pattern);
  Bool skip_children_Pattern;
  doggy_TypedPattern (*action_TypedPattern[2]) (doggy_TypedPattern, doggy_TypedPattern);
  Bool skip_children_TypedPattern;
  doggy_ConsPattern (*action_ConsPattern[2]) (doggy_ConsPattern, doggy_ConsPattern);
  Bool skip_children_ConsPattern;
  doggy_DefPattern (*action_DefPattern[2]) (doggy_DefPattern, doggy_DefPattern);
  Bool skip_children_DefPattern;
  doggy_IdentPattern (*action_IdentPattern[2]) (doggy_IdentPattern, doggy_IdentPattern);
  Bool skip_children_IdentPattern;
  doggy_BasicPattern (*action_BasicPattern[2]) (doggy_BasicPattern, doggy_BasicPattern);
  Bool skip_children_BasicPattern;
  doggy_OpPattern (*action_OpPattern[2]) (doggy_OpPattern, doggy_OpPattern);
  Bool skip_children_OpPattern;
  doggy_ConstPattern (*action_ConstPattern[2]) (doggy_ConstPattern, doggy_ConstPattern);
  Bool skip_children_ConstPattern;
  doggy_NullPattern (*action_NullPattern[2]) (doggy_NullPattern, doggy_NullPattern);
  Bool skip_children_NullPattern;
  doggy_DontCarePattern (*action_DontCarePattern[2]) (doggy_DontCarePattern, doggy_DontCarePattern);
  Bool skip_children_DontCarePattern;
  doggy_Rhs (*action_Rhs[2]) (doggy_Rhs, doggy_Rhs);
  Bool skip_children_Rhs;
  doggy_PlainRhs (*action_PlainRhs[2]) (doggy_PlainRhs, doggy_PlainRhs);
  Bool skip_children_PlainRhs;
  doggy_BlockRhs (*action_BlockRhs[2]) (doggy_BlockRhs, doggy_BlockRhs);
  Bool skip_children_BlockRhs;
  doggy_Guard (*action_Guard[2]) (doggy_Guard, doggy_Guard);
  Bool skip_children_Guard;
  doggy_RhsGuard (*action_RhsGuard[2]) (doggy_RhsGuard, doggy_RhsGuard);
  Bool skip_children_RhsGuard;
  doggy_ExprGuard (*action_ExprGuard[2]) (doggy_ExprGuard, doggy_ExprGuard);
  Bool skip_children_ExprGuard;
  doggy_ExprSeq (*action_ExprSeq[2]) (doggy_ExprSeq, doggy_ExprSeq);
  Bool skip_children_ExprSeq;
  doggy_OneExpr (*action_OneExpr[2]) (doggy_OneExpr, doggy_OneExpr);
  Bool skip_children_OneExpr;
  doggy_MoreExprs (*action_MoreExprs[2]) (doggy_MoreExprs, doggy_MoreExprs);
  Bool skip_children_MoreExprs;
  doggy_Wherepart (*action_Wherepart[2]) (doggy_Wherepart, doggy_Wherepart);
  Bool skip_children_Wherepart;
  doggy_Applied_operation (*action_Applied_operation[2]) (doggy_Applied_operation, doggy_Applied_operation);
  Bool skip_children_Applied_operation;
  doggy_AnyOp (*action_AnyOp[2]) (doggy_AnyOp, doggy_AnyOp);
  Bool skip_children_AnyOp;
  doggy_AppliedOp (*action_AppliedOp[2]) (doggy_AppliedOp, doggy_AppliedOp);
  Bool skip_children_AppliedOp;
  doggy_OpSet (*action_OpSet[2]) (doggy_OpSet, doggy_OpSet);
  Bool skip_children_OpSet;
  doggy_Applied_formal (*action_Applied_formal[2]) (doggy_Applied_formal, doggy_Applied_formal);
  Bool skip_children_Applied_formal;
  doggy_Expr (*action_Expr[2]) (doggy_Expr, doggy_Expr);
  Bool skip_children_Expr;
  doggy_BinExpr (*action_BinExpr[2]) (doggy_BinExpr, doggy_BinExpr);
  Bool skip_children_BinExpr;
  doggy_ConsExpr (*action_ConsExpr[2]) (doggy_ConsExpr, doggy_ConsExpr);
  Bool skip_children_ConsExpr;
  doggy_SimpleExpr (*action_SimpleExpr[2]) (doggy_SimpleExpr, doggy_SimpleExpr);
  Bool skip_children_SimpleExpr;
  doggy_IdentExpr (*action_IdentExpr[2]) (doggy_IdentExpr, doggy_IdentExpr);
  Bool skip_children_IdentExpr;
  doggy_IfExpr (*action_IfExpr[2]) (doggy_IfExpr, doggy_IfExpr);
  Bool skip_children_IfExpr;
  doggy_ConstExpr (*action_ConstExpr[2]) (doggy_ConstExpr, doggy_ConstExpr);
  Bool skip_children_ConstExpr;
  doggy_Operation (*action_Operation[2]) (doggy_Operation, doggy_Operation);
  Bool skip_children_Operation;
  doggy_ParExpr (*action_ParExpr[2]) (doggy_ParExpr, doggy_ParExpr);
  Bool skip_children_ParExpr;
  doggy_MonExpr (*action_MonExpr[2]) (doggy_MonExpr, doggy_MonExpr);
  Bool skip_children_MonExpr;
  doggy_Constant (*action_Constant[2]) (doggy_Constant, doggy_Constant);
  Bool skip_children_Constant;
  doggy_IntConst (*action_IntConst[2]) (doggy_IntConst, doggy_IntConst);
  Bool skip_children_IntConst;
  doggy_BoolConst (*action_BoolConst[2]) (doggy_BoolConst, doggy_BoolConst);
  Bool skip_children_BoolConst;
  doggy_StringConst (*action_StringConst[2]) (doggy_StringConst, doggy_StringConst);
  Bool skip_children_StringConst;
  doggy_NullConst (*action_NullConst[2]) (doggy_NullConst, doggy_NullConst);
  Bool skip_children_NullConst;
  doggy_Definition (*action_Definition[2]) (doggy_Definition, doggy_Definition);
  Bool skip_children_Definition;
  doggy_Type (*action_Type[2]) (doggy_Type, doggy_Type);
  Bool skip_children_Type;
  doggy_EdgeType (*action_EdgeType[2]) (doggy_EdgeType, doggy_EdgeType);
  Bool skip_children_EdgeType;
  doggy_TupleType (*action_TupleType[2]) (doggy_TupleType, doggy_TupleType);
  Bool skip_children_TupleType;
  doggy_BasicType (*action_BasicType[2]) (doggy_BasicType, doggy_BasicType);
  Bool skip_children_BasicType;
  doggy_IdentType (*action_IdentType[2]) (doggy_IdentType, doggy_IdentType);
  Bool skip_children_IdentType;
  doggy_OprType (*action_OprType[2]) (doggy_OprType, doggy_OprType);
  Bool skip_children_OprType;
  doggy_PointerType (*action_PointerType[2]) (doggy_PointerType, doggy_PointerType);
  Bool skip_children_PointerType;
  doggy_RangeType (*action_RangeType[2]) (doggy_RangeType, doggy_RangeType);
  Bool skip_children_RangeType;
  doggy_FRangeType (*action_FRangeType[2]) (doggy_FRangeType, doggy_FRangeType);
  Bool skip_children_FRangeType;
  doggy_Num (*action_Num[2]) (doggy_Num, doggy_Num);
  Bool skip_children_Num;
  doggy_IdInt (*action_IdInt[2]) (doggy_IdInt, doggy_IdInt);
  Bool skip_children_IdInt;
  doggy_IsId (*action_IsId[2]) (doggy_IsId, doggy_IsId);
  Bool skip_children_IsId;
  doggy_IsInt (*action_IsInt[2]) (doggy_IsInt, doggy_IsInt);
  Bool skip_children_IsInt;
  doggy_Path (*action_Path[2]) (doggy_Path, doggy_Path);
  Bool skip_children_Path;
  doggy_ActualOp (*action_ActualOp[2]) (doggy_ActualOp, doggy_ActualOp);
  Bool skip_children_ActualOp;
  doggy_TypePair (*action_TypePair[2]) (doggy_TypePair, doggy_TypePair);
  Bool skip_children_TypePair;
  doggy_Opat (*action_Opat[2]) (doggy_Opat, doggy_Opat);
  Bool skip_children_Opat;
  doggy_Format (*action_Format[2]) (doggy_Format, doggy_Format);
  Bool skip_children_Format;
  doggy_dummy_type (*action_dummy_type[2]) (doggy_dummy_type, doggy_dummy_type);
  Bool skip_children_dummy_type;
  doggy_Scope (*action_Scope[2]) (doggy_Scope, doggy_Scope);
  Bool skip_children_Scope;
  doggy_OpSetScope (*action_OpSetScope[2]) (doggy_OpSetScope, doggy_OpSetScope);
  Bool skip_children_OpSetScope;
  doggy_AppliedOpScope (*action_AppliedOpScope[2]) (doggy_AppliedOpScope, doggy_AppliedOpScope);
  Bool skip_children_AppliedOpScope;
  doggy_ExprGuardScope (*action_ExprGuardScope[2]) (doggy_ExprGuardScope, doggy_ExprGuardScope);
  Bool skip_children_ExprGuardScope;
  doggy_RhsGuardScope (*action_RhsGuardScope[2]) (doggy_RhsGuardScope, doggy_RhsGuardScope);
  Bool skip_children_RhsGuardScope;
  doggy_FuncRuleScope (*action_FuncRuleScope[2]) (doggy_FuncRuleScope, doggy_FuncRuleScope);
  Bool skip_children_FuncRuleScope;
  doggy_RuleScope (*action_RuleScope[2]) (doggy_RuleScope, doggy_RuleScope);
  Bool skip_children_RuleScope;
  doggy_machine_descriptionScope (*action_machine_descriptionScope[2]) (doggy_machine_descriptionScope, doggy_machine_descriptionScope);
  Bool skip_children_machine_descriptionScope;
  List_doggy_Num (*action_List_Num[2]) (List_doggy_Num, List_doggy_Num);
  Bool skip_children_List_Num;
  List_List_doggy_TypePair (*action_List_List_TypePair[2]) (List_List_doggy_TypePair, List_List_doggy_TypePair);
  Bool skip_children_List_List_TypePair;
  List_doggy_TypePair (*action_List_TypePair[2]) (List_doggy_TypePair, List_doggy_TypePair);
  Bool skip_children_List_TypePair;
  List_doggy_ActualOp (*action_List_ActualOp[2]) (List_doggy_ActualOp, List_doggy_ActualOp);
  Bool skip_children_List_ActualOp;
  List_List_doggy_Type (*action_List_List_Type[2]) (List_List_doggy_Type, List_List_doggy_Type);
  Bool skip_children_List_List_Type;
  List_doggy_Operator (*action_List_Operator[2]) (List_doggy_Operator, List_doggy_Operator);
  Bool skip_children_List_Operator;
  List_doggy_Definition (*action_List_Definition[2]) (List_doggy_Definition, List_doggy_Definition);
  Bool skip_children_List_Definition;
  List_doggy_Expr (*action_List_Expr[2]) (List_doggy_Expr, List_doggy_Expr);
  Bool skip_children_List_Expr;
  List_doggy_Guard (*action_List_Guard[2]) (List_doggy_Guard, List_doggy_Guard);
  Bool skip_children_List_Guard;
  List_doggy_Pattern (*action_List_Pattern[2]) (List_doggy_Pattern, List_doggy_Pattern);
  Bool skip_children_List_Pattern;
  List_doggy_Argument (*action_List_Argument[2]) (List_doggy_Argument, List_doggy_Argument);
  Bool skip_children_List_Argument;
  List_doggy_FuncRule (*action_List_FuncRule[2]) (List_doggy_FuncRule, List_doggy_FuncRule);
  Bool skip_children_List_FuncRule;
  List_doggy_Attribute (*action_List_Attribute[2]) (List_doggy_Attribute, List_doggy_Attribute);
  Bool skip_children_List_Attribute;
  List_doggy_Property (*action_List_Property[2]) (List_doggy_Property, List_doggy_Property);
  Bool skip_children_List_Property;
  List_doggy_Applied_formal (*action_List_Applied_formal[2]) (List_doggy_Applied_formal, List_doggy_Applied_formal);
  Bool skip_children_List_Applied_formal;
  List_doggy_Operation_def (*action_List_Operation_def[2]) (List_doggy_Operation_def, List_doggy_Operation_def);
  Bool skip_children_List_Operation_def;
  List_doggy_Type (*action_List_Type[2]) (List_doggy_Type, List_doggy_Type);
  Bool skip_children_List_Type;
  List_doggy_Rule (*action_List_Rule[2]) (List_doggy_Rule, List_doggy_Rule);
  Bool skip_children_List_Rule;
  List_doggy_Func (*action_List_Func[2]) (List_doggy_Func, List_doggy_Func);
  Bool skip_children_List_Func;
  List_doggy_Section (*action_List_Section[2]) (List_doggy_Section, List_doggy_Section);
  Bool skip_children_List_Section;
  List_doggy_FunctionDef (*action_List_FunctionDef[2]) (List_doggy_FunctionDef, List_doggy_FunctionDef);
  Bool skip_children_List_FunctionDef;
  List_doggy_Typedef (*action_List_Typedef[2]) (List_doggy_Typedef, List_doggy_Typedef);
  Bool skip_children_List_Typedef;
  doggy_Operator (*action_Operator[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_Operator;
  doggy_Operator (*action_CandOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_CandOp;
  doggy_Operator (*action_CorOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_CorOp;
  doggy_Operator (*action_XorOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_XorOp;
  doggy_Operator (*action_EqOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_EqOp;
  doggy_Operator (*action_NeqOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_NeqOp;
  doggy_Operator (*action_LEOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_LEOp;
  doggy_Operator (*action_GEOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_GEOp;
  doggy_Operator (*action_LTOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_LTOp;
  doggy_Operator (*action_GTOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_GTOp;
  doggy_Operator (*action_SLOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_SLOp;
  doggy_Operator (*action_SROp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_SROp;
  doggy_Operator (*action_DivOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_DivOp;
  doggy_Operator (*action_ModOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_ModOp;
  doggy_Operator (*action_MulOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_MulOp;
  doggy_Operator (*action_AndOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_AndOp;
  doggy_Operator (*action_AddOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_AddOp;
  doggy_Operator (*action_SubOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_SubOp;
  doggy_MonOp (*action_MonOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_MonOp;
  doggy_MonOp (*action_NotOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_NotOp;
  doggy_MonOp (*action_NegOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_NegOp;
  doggy_MonOp (*action_AddrOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_AddrOp;
  doggy_MonOp (*action_DerefOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_DerefOp;
  doggy_MonOp (*action_PlusOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_PlusOp;
  doggy_MonOp (*action_MinOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_MinOp;
  doggy_Property (*action_Property[2]) (doggy_Property, doggy_Property);
  Bool skip_children_Property;
} *copy_doggy_TraverseTable;

extern doggy_Operator Traverse_copy_doggy_Operator (doggy_Operator me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Operator
#define COPY_doggy_Operator(x) Traverse_copy_doggy_Operator(x, &doggy_copy_actions)
#endif
extern doggy_MonOp Traverse_copy_doggy_MonOp (doggy_MonOp me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_MonOp
#define COPY_doggy_MonOp(x) Traverse_copy_doggy_MonOp(x, &doggy_copy_actions)
#endif
extern doggy_Property Traverse_copy_doggy_Property (doggy_Property me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Property
#define COPY_doggy_Property(x) Traverse_copy_doggy_Property(x, &doggy_copy_actions)
#endif
extern doggy_doggy Traverse_copy_doggy_doggy (doggy_doggy me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_doggy
#define COPY_doggy_doggy(x) Traverse_copy_doggy_doggy(x, &doggy_copy_actions)
#endif
extern doggy_Typedef Traverse_copy_doggy_Typedef (doggy_Typedef me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Typedef
#define COPY_doggy_Typedef(x) Traverse_copy_doggy_Typedef(x, &doggy_copy_actions)
#endif
extern doggy_FunctionDef Traverse_copy_doggy_FunctionDef (doggy_FunctionDef me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_FunctionDef
#define COPY_doggy_FunctionDef(x) Traverse_copy_doggy_FunctionDef(x, &doggy_copy_actions)
#endif
extern doggy_machine_description Traverse_copy_doggy_machine_description (doggy_machine_description me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_machine_description
#define COPY_doggy_machine_description(x) Traverse_copy_doggy_machine_description(x, &doggy_copy_actions)
#endif
extern doggy_Operation_def Traverse_copy_doggy_Operation_def (doggy_Operation_def me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Operation_def
#define COPY_doggy_Operation_def(x) Traverse_copy_doggy_Operation_def(x, &doggy_copy_actions)
#endif
extern doggy_Attributes Traverse_copy_doggy_Attributes (doggy_Attributes me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Attributes
#define COPY_doggy_Attributes(x) Traverse_copy_doggy_Attributes(x, &doggy_copy_actions)
#endif
extern doggy_Attribute Traverse_copy_doggy_Attribute (doggy_Attribute me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Attribute
#define COPY_doggy_Attribute(x) Traverse_copy_doggy_Attribute(x, &doggy_copy_actions)
#endif
extern doggy_Section Traverse_copy_doggy_Section (doggy_Section me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Section
#define COPY_doggy_Section(x) Traverse_copy_doggy_Section(x, &doggy_copy_actions)
#endif
extern doggy_Rule Traverse_copy_doggy_Rule (doggy_Rule me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Rule
#define COPY_doggy_Rule(x) Traverse_copy_doggy_Rule(x, &doggy_copy_actions)
#endif
extern doggy_Lhs Traverse_copy_doggy_Lhs (doggy_Lhs me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Lhs
#define COPY_doggy_Lhs(x) Traverse_copy_doggy_Lhs(x, &doggy_copy_actions)
#endif
extern doggy_Func Traverse_copy_doggy_Func (doggy_Func me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Func
#define COPY_doggy_Func(x) Traverse_copy_doggy_Func(x, &doggy_copy_actions)
#endif
extern doggy_FuncRule Traverse_copy_doggy_FuncRule (doggy_FuncRule me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_FuncRule
#define COPY_doggy_FuncRule(x) Traverse_copy_doggy_FuncRule(x, &doggy_copy_actions)
#endif
extern doggy_Argument Traverse_copy_doggy_Argument (doggy_Argument me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Argument
#define COPY_doggy_Argument(x) Traverse_copy_doggy_Argument(x, &doggy_copy_actions)
#endif
extern doggy_ArgPat Traverse_copy_doggy_ArgPat (doggy_ArgPat me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_ArgPat
#define COPY_doggy_ArgPat(x) Traverse_copy_doggy_ArgPat(x, &doggy_copy_actions)
#endif
extern doggy_Pattern Traverse_copy_doggy_Pattern (doggy_Pattern me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Pattern
#define COPY_doggy_Pattern(x) Traverse_copy_doggy_Pattern(x, &doggy_copy_actions)
#endif
extern doggy_Rhs Traverse_copy_doggy_Rhs (doggy_Rhs me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Rhs
#define COPY_doggy_Rhs(x) Traverse_copy_doggy_Rhs(x, &doggy_copy_actions)
#endif
extern doggy_Guard Traverse_copy_doggy_Guard (doggy_Guard me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Guard
#define COPY_doggy_Guard(x) Traverse_copy_doggy_Guard(x, &doggy_copy_actions)
#endif
extern doggy_ExprSeq Traverse_copy_doggy_ExprSeq (doggy_ExprSeq me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_ExprSeq
#define COPY_doggy_ExprSeq(x) Traverse_copy_doggy_ExprSeq(x, &doggy_copy_actions)
#endif
extern doggy_Wherepart Traverse_copy_doggy_Wherepart (doggy_Wherepart me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Wherepart
#define COPY_doggy_Wherepart(x) Traverse_copy_doggy_Wherepart(x, &doggy_copy_actions)
#endif
extern doggy_Applied_operation Traverse_copy_doggy_Applied_operation (doggy_Applied_operation me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Applied_operation
#define COPY_doggy_Applied_operation(x) Traverse_copy_doggy_Applied_operation(x, &doggy_copy_actions)
#endif
extern doggy_Applied_formal Traverse_copy_doggy_Applied_formal (doggy_Applied_formal me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Applied_formal
#define COPY_doggy_Applied_formal(x) Traverse_copy_doggy_Applied_formal(x, &doggy_copy_actions)
#endif
extern doggy_Expr Traverse_copy_doggy_Expr (doggy_Expr me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Expr
#define COPY_doggy_Expr(x) Traverse_copy_doggy_Expr(x, &doggy_copy_actions)
#endif
extern doggy_Constant Traverse_copy_doggy_Constant (doggy_Constant me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Constant
#define COPY_doggy_Constant(x) Traverse_copy_doggy_Constant(x, &doggy_copy_actions)
#endif
extern doggy_Definition Traverse_copy_doggy_Definition (doggy_Definition me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Definition
#define COPY_doggy_Definition(x) Traverse_copy_doggy_Definition(x, &doggy_copy_actions)
#endif
extern doggy_Type Traverse_copy_doggy_Type (doggy_Type me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Type
#define COPY_doggy_Type(x) Traverse_copy_doggy_Type(x, &doggy_copy_actions)
#endif
extern doggy_Num Traverse_copy_doggy_Num (doggy_Num me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Num
#define COPY_doggy_Num(x) Traverse_copy_doggy_Num(x, &doggy_copy_actions)
#endif
extern doggy_IdInt Traverse_copy_doggy_IdInt (doggy_IdInt me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_IdInt
#define COPY_doggy_IdInt(x) Traverse_copy_doggy_IdInt(x, &doggy_copy_actions)
#endif
extern doggy_Path Traverse_copy_doggy_Path (doggy_Path me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Path
#define COPY_doggy_Path(x) Traverse_copy_doggy_Path(x, &doggy_copy_actions)
#endif
extern doggy_ActualOp Traverse_copy_doggy_ActualOp (doggy_ActualOp me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_ActualOp
#define COPY_doggy_ActualOp(x) Traverse_copy_doggy_ActualOp(x, &doggy_copy_actions)
#endif
extern doggy_TypePair Traverse_copy_doggy_TypePair (doggy_TypePair me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_TypePair
#define COPY_doggy_TypePair(x) Traverse_copy_doggy_TypePair(x, &doggy_copy_actions)
#endif
extern doggy_Opat Traverse_copy_doggy_Opat (doggy_Opat me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Opat
#define COPY_doggy_Opat(x) Traverse_copy_doggy_Opat(x, &doggy_copy_actions)
#endif
extern doggy_Format Traverse_copy_doggy_Format (doggy_Format me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Format
#define COPY_doggy_Format(x) Traverse_copy_doggy_Format(x, &doggy_copy_actions)
#endif
extern doggy_dummy_type Traverse_copy_doggy_dummy_type (doggy_dummy_type me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_dummy_type
#define COPY_doggy_dummy_type(x) Traverse_copy_doggy_dummy_type(x, &doggy_copy_actions)
#endif
extern doggy_Scope Traverse_copy_doggy_Scope (doggy_Scope me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_Scope
#define COPY_doggy_Scope(x) Traverse_copy_doggy_Scope(x, &doggy_copy_actions)
#endif
extern List_doggy_Num Traverse_copy_List_doggy_Num (List_doggy_Num me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Num
#define COPY_doggy_List_Num(x) Traverse_copy_List_doggy_Num(x, &doggy_copy_actions)
#endif
extern List_List_doggy_TypePair Traverse_copy_List_List_doggy_TypePair (List_List_doggy_TypePair me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_List_TypePair
#define COPY_doggy_List_List_TypePair(x) Traverse_copy_List_List_doggy_TypePair(x, &doggy_copy_actions)
#endif
extern List_doggy_TypePair Traverse_copy_List_doggy_TypePair (List_doggy_TypePair me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_TypePair
#define COPY_doggy_List_TypePair(x) Traverse_copy_List_doggy_TypePair(x, &doggy_copy_actions)
#endif
extern List_doggy_ActualOp Traverse_copy_List_doggy_ActualOp (List_doggy_ActualOp me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_ActualOp
#define COPY_doggy_List_ActualOp(x) Traverse_copy_List_doggy_ActualOp(x, &doggy_copy_actions)
#endif
extern List_List_doggy_Type Traverse_copy_List_List_doggy_Type (List_List_doggy_Type me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_List_Type
#define COPY_doggy_List_List_Type(x) Traverse_copy_List_List_doggy_Type(x, &doggy_copy_actions)
#endif
extern List_doggy_Operator Traverse_copy_List_doggy_Operator (List_doggy_Operator me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Operator
#define COPY_doggy_List_Operator(x) Traverse_copy_List_doggy_Operator(x, &doggy_copy_actions)
#endif
extern List_doggy_Definition Traverse_copy_List_doggy_Definition (List_doggy_Definition me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Definition
#define COPY_doggy_List_Definition(x) Traverse_copy_List_doggy_Definition(x, &doggy_copy_actions)
#endif
extern List_doggy_Expr Traverse_copy_List_doggy_Expr (List_doggy_Expr me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Expr
#define COPY_doggy_List_Expr(x) Traverse_copy_List_doggy_Expr(x, &doggy_copy_actions)
#endif
extern List_doggy_Guard Traverse_copy_List_doggy_Guard (List_doggy_Guard me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Guard
#define COPY_doggy_List_Guard(x) Traverse_copy_List_doggy_Guard(x, &doggy_copy_actions)
#endif
extern List_doggy_Pattern Traverse_copy_List_doggy_Pattern (List_doggy_Pattern me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Pattern
#define COPY_doggy_List_Pattern(x) Traverse_copy_List_doggy_Pattern(x, &doggy_copy_actions)
#endif
extern List_doggy_Argument Traverse_copy_List_doggy_Argument (List_doggy_Argument me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Argument
#define COPY_doggy_List_Argument(x) Traverse_copy_List_doggy_Argument(x, &doggy_copy_actions)
#endif
extern List_doggy_FuncRule Traverse_copy_List_doggy_FuncRule (List_doggy_FuncRule me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_FuncRule
#define COPY_doggy_List_FuncRule(x) Traverse_copy_List_doggy_FuncRule(x, &doggy_copy_actions)
#endif
extern List_doggy_Attribute Traverse_copy_List_doggy_Attribute (List_doggy_Attribute me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Attribute
#define COPY_doggy_List_Attribute(x) Traverse_copy_List_doggy_Attribute(x, &doggy_copy_actions)
#endif
extern List_doggy_Property Traverse_copy_List_doggy_Property (List_doggy_Property me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Property
#define COPY_doggy_List_Property(x) Traverse_copy_List_doggy_Property(x, &doggy_copy_actions)
#endif
extern List_doggy_Applied_formal Traverse_copy_List_doggy_Applied_formal (List_doggy_Applied_formal me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Applied_formal
#define COPY_doggy_List_Applied_formal(x) Traverse_copy_List_doggy_Applied_formal(x, &doggy_copy_actions)
#endif
extern List_doggy_Operation_def Traverse_copy_List_doggy_Operation_def (List_doggy_Operation_def me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Operation_def
#define COPY_doggy_List_Operation_def(x) Traverse_copy_List_doggy_Operation_def(x, &doggy_copy_actions)
#endif
extern List_doggy_Type Traverse_copy_List_doggy_Type (List_doggy_Type me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Type
#define COPY_doggy_List_Type(x) Traverse_copy_List_doggy_Type(x, &doggy_copy_actions)
#endif
extern List_doggy_Rule Traverse_copy_List_doggy_Rule (List_doggy_Rule me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Rule
#define COPY_doggy_List_Rule(x) Traverse_copy_List_doggy_Rule(x, &doggy_copy_actions)
#endif
extern List_doggy_Func Traverse_copy_List_doggy_Func (List_doggy_Func me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Func
#define COPY_doggy_List_Func(x) Traverse_copy_List_doggy_Func(x, &doggy_copy_actions)
#endif
extern List_doggy_Section Traverse_copy_List_doggy_Section (List_doggy_Section me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Section
#define COPY_doggy_List_Section(x) Traverse_copy_List_doggy_Section(x, &doggy_copy_actions)
#endif
extern List_doggy_FunctionDef Traverse_copy_List_doggy_FunctionDef (List_doggy_FunctionDef me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_FunctionDef
#define COPY_doggy_List_FunctionDef(x) Traverse_copy_List_doggy_FunctionDef(x, &doggy_copy_actions)
#endif
extern List_doggy_Typedef Traverse_copy_List_doggy_Typedef (List_doggy_Typedef me, copy_doggy_TraverseTable table);
#ifndef COPY_doggy_List_Typedef
#define COPY_doggy_List_Typedef(x) Traverse_copy_List_doggy_Typedef(x, &doggy_copy_actions)
#endif

typedef struct s_compare_doggy_TraverseTable {
  int (*action_doggy[2]) (doggy_doggy, doggy_doggy);
  Bool skip_children_doggy;
  int (*action_Typedef[2]) (doggy_Typedef, doggy_Typedef);
  Bool skip_children_Typedef;
  int (*action_FunctionDef[2]) (doggy_FunctionDef, doggy_FunctionDef);
  Bool skip_children_FunctionDef;
  int (*action_ExtFunc[2]) (doggy_ExtFunc, doggy_ExtFunc);
  Bool skip_children_ExtFunc;
  int (*action_ExtVar[2]) (doggy_ExtVar, doggy_ExtVar);
  Bool skip_children_ExtVar;
  int (*action_machine_description[2]) (doggy_machine_description, doggy_machine_description);
  Bool skip_children_machine_description;
  int (*action_Operation_def[2]) (doggy_Operation_def, doggy_Operation_def);
  Bool skip_children_Operation_def;
  int (*action_Attributes[2]) (doggy_Attributes, doggy_Attributes);
  Bool skip_children_Attributes;
  int (*action_Attribute[2]) (doggy_Attribute, doggy_Attribute);
  Bool skip_children_Attribute;
  int (*action_IdAttr[2]) (doggy_IdAttr, doggy_IdAttr);
  Bool skip_children_IdAttr;
  int (*action_OpAttr[2]) (doggy_OpAttr, doggy_OpAttr);
  Bool skip_children_OpAttr;
  int (*action_IntAttr[2]) (doggy_IntAttr, doggy_IntAttr);
  Bool skip_children_IntAttr;
  int (*action_Section[2]) (doggy_Section, doggy_Section);
  Bool skip_children_Section;
  int (*action_FuncSection[2]) (doggy_FuncSection, doggy_FuncSection);
  Bool skip_children_FuncSection;
  int (*action_RuleSection[2]) (doggy_RuleSection, doggy_RuleSection);
  Bool skip_children_RuleSection;
  int (*action_Rule[2]) (doggy_Rule, doggy_Rule);
  Bool skip_children_Rule;
  int (*action_Lhs[2]) (doggy_Lhs, doggy_Lhs);
  Bool skip_children_Lhs;
  int (*action_LabeledLhs[2]) (doggy_LabeledLhs, doggy_LabeledLhs);
  Bool skip_children_LabeledLhs;
  int (*action_UnLabeledLhs[2]) (doggy_UnLabeledLhs, doggy_UnLabeledLhs);
  Bool skip_children_UnLabeledLhs;
  int (*action_Func[2]) (doggy_Func, doggy_Func);
  Bool skip_children_Func;
  int (*action_FuncRule[2]) (doggy_FuncRule, doggy_FuncRule);
  Bool skip_children_FuncRule;
  int (*action_Argument[2]) (doggy_Argument, doggy_Argument);
  Bool skip_children_Argument;
  int (*action_TypedArg[2]) (doggy_TypedArg, doggy_TypedArg);
  Bool skip_children_TypedArg;
  int (*action_UnTypedArg[2]) (doggy_UnTypedArg, doggy_UnTypedArg);
  Bool skip_children_UnTypedArg;
  int (*action_ArgPat[2]) (doggy_ArgPat, doggy_ArgPat);
  Bool skip_children_ArgPat;
  int (*action_PatArg[2]) (doggy_PatArg, doggy_PatArg);
  Bool skip_children_PatArg;
  int (*action_SetArg[2]) (doggy_SetArg, doggy_SetArg);
  Bool skip_children_SetArg;
  int (*action_Pattern[2]) (doggy_Pattern, doggy_Pattern);
  Bool skip_children_Pattern;
  int (*action_TypedPattern[2]) (doggy_TypedPattern, doggy_TypedPattern);
  Bool skip_children_TypedPattern;
  int (*action_ConsPattern[2]) (doggy_ConsPattern, doggy_ConsPattern);
  Bool skip_children_ConsPattern;
  int (*action_DefPattern[2]) (doggy_DefPattern, doggy_DefPattern);
  Bool skip_children_DefPattern;
  int (*action_IdentPattern[2]) (doggy_IdentPattern, doggy_IdentPattern);
  Bool skip_children_IdentPattern;
  int (*action_BasicPattern[2]) (doggy_BasicPattern, doggy_BasicPattern);
  Bool skip_children_BasicPattern;
  int (*action_OpPattern[2]) (doggy_OpPattern, doggy_OpPattern);
  Bool skip_children_OpPattern;
  int (*action_ConstPattern[2]) (doggy_ConstPattern, doggy_ConstPattern);
  Bool skip_children_ConstPattern;
  int (*action_NullPattern[2]) (doggy_NullPattern, doggy_NullPattern);
  Bool skip_children_NullPattern;
  int (*action_DontCarePattern[2]) (doggy_DontCarePattern, doggy_DontCarePattern);
  Bool skip_children_DontCarePattern;
  int (*action_Rhs[2]) (doggy_Rhs, doggy_Rhs);
  Bool skip_children_Rhs;
  int (*action_PlainRhs[2]) (doggy_PlainRhs, doggy_PlainRhs);
  Bool skip_children_PlainRhs;
  int (*action_BlockRhs[2]) (doggy_BlockRhs, doggy_BlockRhs);
  Bool skip_children_BlockRhs;
  int (*action_Guard[2]) (doggy_Guard, doggy_Guard);
  Bool skip_children_Guard;
  int (*action_RhsGuard[2]) (doggy_RhsGuard, doggy_RhsGuard);
  Bool skip_children_RhsGuard;
  int (*action_ExprGuard[2]) (doggy_ExprGuard, doggy_ExprGuard);
  Bool skip_children_ExprGuard;
  int (*action_ExprSeq[2]) (doggy_ExprSeq, doggy_ExprSeq);
  Bool skip_children_ExprSeq;
  int (*action_OneExpr[2]) (doggy_OneExpr, doggy_OneExpr);
  Bool skip_children_OneExpr;
  int (*action_MoreExprs[2]) (doggy_MoreExprs, doggy_MoreExprs);
  Bool skip_children_MoreExprs;
  int (*action_Wherepart[2]) (doggy_Wherepart, doggy_Wherepart);
  Bool skip_children_Wherepart;
  int (*action_Applied_operation[2]) (doggy_Applied_operation, doggy_Applied_operation);
  Bool skip_children_Applied_operation;
  int (*action_AnyOp[2]) (doggy_AnyOp, doggy_AnyOp);
  Bool skip_children_AnyOp;
  int (*action_AppliedOp[2]) (doggy_AppliedOp, doggy_AppliedOp);
  Bool skip_children_AppliedOp;
  int (*action_OpSet[2]) (doggy_OpSet, doggy_OpSet);
  Bool skip_children_OpSet;
  int (*action_Applied_formal[2]) (doggy_Applied_formal, doggy_Applied_formal);
  Bool skip_children_Applied_formal;
  int (*action_Expr[2]) (doggy_Expr, doggy_Expr);
  Bool skip_children_Expr;
  int (*action_BinExpr[2]) (doggy_BinExpr, doggy_BinExpr);
  Bool skip_children_BinExpr;
  int (*action_ConsExpr[2]) (doggy_ConsExpr, doggy_ConsExpr);
  Bool skip_children_ConsExpr;
  int (*action_SimpleExpr[2]) (doggy_SimpleExpr, doggy_SimpleExpr);
  Bool skip_children_SimpleExpr;
  int (*action_IdentExpr[2]) (doggy_IdentExpr, doggy_IdentExpr);
  Bool skip_children_IdentExpr;
  int (*action_IfExpr[2]) (doggy_IfExpr, doggy_IfExpr);
  Bool skip_children_IfExpr;
  int (*action_ConstExpr[2]) (doggy_ConstExpr, doggy_ConstExpr);
  Bool skip_children_ConstExpr;
  int (*action_Operation[2]) (doggy_Operation, doggy_Operation);
  Bool skip_children_Operation;
  int (*action_ParExpr[2]) (doggy_ParExpr, doggy_ParExpr);
  Bool skip_children_ParExpr;
  int (*action_MonExpr[2]) (doggy_MonExpr, doggy_MonExpr);
  Bool skip_children_MonExpr;
  int (*action_Constant[2]) (doggy_Constant, doggy_Constant);
  Bool skip_children_Constant;
  int (*action_IntConst[2]) (doggy_IntConst, doggy_IntConst);
  Bool skip_children_IntConst;
  int (*action_BoolConst[2]) (doggy_BoolConst, doggy_BoolConst);
  Bool skip_children_BoolConst;
  int (*action_StringConst[2]) (doggy_StringConst, doggy_StringConst);
  Bool skip_children_StringConst;
  int (*action_NullConst[2]) (doggy_NullConst, doggy_NullConst);
  Bool skip_children_NullConst;
  int (*action_Definition[2]) (doggy_Definition, doggy_Definition);
  Bool skip_children_Definition;
  int (*action_Type[2]) (doggy_Type, doggy_Type);
  Bool skip_children_Type;
  int (*action_EdgeType[2]) (doggy_EdgeType, doggy_EdgeType);
  Bool skip_children_EdgeType;
  int (*action_TupleType[2]) (doggy_TupleType, doggy_TupleType);
  Bool skip_children_TupleType;
  int (*action_BasicType[2]) (doggy_BasicType, doggy_BasicType);
  Bool skip_children_BasicType;
  int (*action_IdentType[2]) (doggy_IdentType, doggy_IdentType);
  Bool skip_children_IdentType;
  int (*action_OprType[2]) (doggy_OprType, doggy_OprType);
  Bool skip_children_OprType;
  int (*action_PointerType[2]) (doggy_PointerType, doggy_PointerType);
  Bool skip_children_PointerType;
  int (*action_RangeType[2]) (doggy_RangeType, doggy_RangeType);
  Bool skip_children_RangeType;
  int (*action_FRangeType[2]) (doggy_FRangeType, doggy_FRangeType);
  Bool skip_children_FRangeType;
  int (*action_Num[2]) (doggy_Num, doggy_Num);
  Bool skip_children_Num;
  int (*action_IdInt[2]) (doggy_IdInt, doggy_IdInt);
  Bool skip_children_IdInt;
  int (*action_IsId[2]) (doggy_IsId, doggy_IsId);
  Bool skip_children_IsId;
  int (*action_IsInt[2]) (doggy_IsInt, doggy_IsInt);
  Bool skip_children_IsInt;
  int (*action_Path[2]) (doggy_Path, doggy_Path);
  Bool skip_children_Path;
  int (*action_ActualOp[2]) (doggy_ActualOp, doggy_ActualOp);
  Bool skip_children_ActualOp;
  int (*action_TypePair[2]) (doggy_TypePair, doggy_TypePair);
  Bool skip_children_TypePair;
  int (*action_Opat[2]) (doggy_Opat, doggy_Opat);
  Bool skip_children_Opat;
  int (*action_Format[2]) (doggy_Format, doggy_Format);
  Bool skip_children_Format;
  int (*action_dummy_type[2]) (doggy_dummy_type, doggy_dummy_type);
  Bool skip_children_dummy_type;
  int (*action_Scope[2]) (doggy_Scope, doggy_Scope);
  Bool skip_children_Scope;
  int (*action_OpSetScope[2]) (doggy_OpSetScope, doggy_OpSetScope);
  Bool skip_children_OpSetScope;
  int (*action_AppliedOpScope[2]) (doggy_AppliedOpScope, doggy_AppliedOpScope);
  Bool skip_children_AppliedOpScope;
  int (*action_ExprGuardScope[2]) (doggy_ExprGuardScope, doggy_ExprGuardScope);
  Bool skip_children_ExprGuardScope;
  int (*action_RhsGuardScope[2]) (doggy_RhsGuardScope, doggy_RhsGuardScope);
  Bool skip_children_RhsGuardScope;
  int (*action_FuncRuleScope[2]) (doggy_FuncRuleScope, doggy_FuncRuleScope);
  Bool skip_children_FuncRuleScope;
  int (*action_RuleScope[2]) (doggy_RuleScope, doggy_RuleScope);
  Bool skip_children_RuleScope;
  int (*action_machine_descriptionScope[2]) (doggy_machine_descriptionScope, doggy_machine_descriptionScope);
  Bool skip_children_machine_descriptionScope;
  int (*action_List_Num[2]) (List_doggy_Num, List_doggy_Num);
  Bool skip_children_List_Num;
  int (*action_List_List_TypePair[2]) (List_List_doggy_TypePair, List_List_doggy_TypePair);
  Bool skip_children_List_List_TypePair;
  int (*action_List_TypePair[2]) (List_doggy_TypePair, List_doggy_TypePair);
  Bool skip_children_List_TypePair;
  int (*action_List_ActualOp[2]) (List_doggy_ActualOp, List_doggy_ActualOp);
  Bool skip_children_List_ActualOp;
  int (*action_List_List_Type[2]) (List_List_doggy_Type, List_List_doggy_Type);
  Bool skip_children_List_List_Type;
  int (*action_List_Operator[2]) (List_doggy_Operator, List_doggy_Operator);
  Bool skip_children_List_Operator;
  int (*action_List_Definition[2]) (List_doggy_Definition, List_doggy_Definition);
  Bool skip_children_List_Definition;
  int (*action_List_Expr[2]) (List_doggy_Expr, List_doggy_Expr);
  Bool skip_children_List_Expr;
  int (*action_List_Guard[2]) (List_doggy_Guard, List_doggy_Guard);
  Bool skip_children_List_Guard;
  int (*action_List_Pattern[2]) (List_doggy_Pattern, List_doggy_Pattern);
  Bool skip_children_List_Pattern;
  int (*action_List_Argument[2]) (List_doggy_Argument, List_doggy_Argument);
  Bool skip_children_List_Argument;
  int (*action_List_FuncRule[2]) (List_doggy_FuncRule, List_doggy_FuncRule);
  Bool skip_children_List_FuncRule;
  int (*action_List_Attribute[2]) (List_doggy_Attribute, List_doggy_Attribute);
  Bool skip_children_List_Attribute;
  int (*action_List_Property[2]) (List_doggy_Property, List_doggy_Property);
  Bool skip_children_List_Property;
  int (*action_List_Applied_formal[2]) (List_doggy_Applied_formal, List_doggy_Applied_formal);
  Bool skip_children_List_Applied_formal;
  int (*action_List_Operation_def[2]) (List_doggy_Operation_def, List_doggy_Operation_def);
  Bool skip_children_List_Operation_def;
  int (*action_List_Type[2]) (List_doggy_Type, List_doggy_Type);
  Bool skip_children_List_Type;
  int (*action_List_Rule[2]) (List_doggy_Rule, List_doggy_Rule);
  Bool skip_children_List_Rule;
  int (*action_List_Func[2]) (List_doggy_Func, List_doggy_Func);
  Bool skip_children_List_Func;
  int (*action_List_Section[2]) (List_doggy_Section, List_doggy_Section);
  Bool skip_children_List_Section;
  int (*action_List_FunctionDef[2]) (List_doggy_FunctionDef, List_doggy_FunctionDef);
  Bool skip_children_List_FunctionDef;
  int (*action_List_Typedef[2]) (List_doggy_Typedef, List_doggy_Typedef);
  Bool skip_children_List_Typedef;
  int (*action_Operator[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_Operator;
  int (*action_CandOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_CandOp;
  int (*action_CorOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_CorOp;
  int (*action_XorOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_XorOp;
  int (*action_EqOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_EqOp;
  int (*action_NeqOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_NeqOp;
  int (*action_LEOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_LEOp;
  int (*action_GEOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_GEOp;
  int (*action_LTOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_LTOp;
  int (*action_GTOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_GTOp;
  int (*action_SLOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_SLOp;
  int (*action_SROp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_SROp;
  int (*action_DivOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_DivOp;
  int (*action_ModOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_ModOp;
  int (*action_MulOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_MulOp;
  int (*action_AndOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_AndOp;
  int (*action_AddOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_AddOp;
  int (*action_SubOp[2]) (doggy_Operator, doggy_Operator);
  Bool skip_children_SubOp;
  int (*action_MonOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_MonOp;
  int (*action_NotOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_NotOp;
  int (*action_NegOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_NegOp;
  int (*action_AddrOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_AddrOp;
  int (*action_DerefOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_DerefOp;
  int (*action_PlusOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_PlusOp;
  int (*action_MinOp[2]) (doggy_MonOp, doggy_MonOp);
  Bool skip_children_MinOp;
  int (*action_Property[2]) (doggy_Property, doggy_Property);
  Bool skip_children_Property;
} *compare_doggy_TraverseTable;

extern int Traverse_compare_doggy_Operator (doggy_Operator x, doggy_Operator y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_MonOp (doggy_MonOp x, doggy_MonOp y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Property (doggy_Property x, doggy_Property y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_doggy (doggy_doggy x, doggy_doggy y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Typedef (doggy_Typedef x, doggy_Typedef y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_FunctionDef (doggy_FunctionDef x, doggy_FunctionDef y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_machine_description (doggy_machine_description x, doggy_machine_description y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Operation_def (doggy_Operation_def x, doggy_Operation_def y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Attributes (doggy_Attributes x, doggy_Attributes y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Attribute (doggy_Attribute x, doggy_Attribute y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Section (doggy_Section x, doggy_Section y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Rule (doggy_Rule x, doggy_Rule y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Lhs (doggy_Lhs x, doggy_Lhs y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Func (doggy_Func x, doggy_Func y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_FuncRule (doggy_FuncRule x, doggy_FuncRule y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Argument (doggy_Argument x, doggy_Argument y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_ArgPat (doggy_ArgPat x, doggy_ArgPat y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Pattern (doggy_Pattern x, doggy_Pattern y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Rhs (doggy_Rhs x, doggy_Rhs y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Guard (doggy_Guard x, doggy_Guard y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_ExprSeq (doggy_ExprSeq x, doggy_ExprSeq y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Wherepart (doggy_Wherepart x, doggy_Wherepart y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Applied_operation (doggy_Applied_operation x, doggy_Applied_operation y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Applied_formal (doggy_Applied_formal x, doggy_Applied_formal y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Expr (doggy_Expr x, doggy_Expr y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Constant (doggy_Constant x, doggy_Constant y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Definition (doggy_Definition x, doggy_Definition y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Type (doggy_Type x, doggy_Type y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Num (doggy_Num x, doggy_Num y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_IdInt (doggy_IdInt x, doggy_IdInt y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Path (doggy_Path x, doggy_Path y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_ActualOp (doggy_ActualOp x, doggy_ActualOp y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_TypePair (doggy_TypePair x, doggy_TypePair y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Opat (doggy_Opat x, doggy_Opat y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Format (doggy_Format x, doggy_Format y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_dummy_type (doggy_dummy_type x, doggy_dummy_type y, compare_doggy_TraverseTable table);
extern int Traverse_compare_doggy_Scope (doggy_Scope x, doggy_Scope y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Num (List_doggy_Num x, List_doggy_Num y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_List_doggy_TypePair (List_List_doggy_TypePair x, List_List_doggy_TypePair y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_TypePair (List_doggy_TypePair x, List_doggy_TypePair y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_ActualOp (List_doggy_ActualOp x, List_doggy_ActualOp y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_List_doggy_Type (List_List_doggy_Type x, List_List_doggy_Type y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Operator (List_doggy_Operator x, List_doggy_Operator y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Definition (List_doggy_Definition x, List_doggy_Definition y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Expr (List_doggy_Expr x, List_doggy_Expr y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Guard (List_doggy_Guard x, List_doggy_Guard y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Pattern (List_doggy_Pattern x, List_doggy_Pattern y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Argument (List_doggy_Argument x, List_doggy_Argument y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_FuncRule (List_doggy_FuncRule x, List_doggy_FuncRule y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Attribute (List_doggy_Attribute x, List_doggy_Attribute y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Property (List_doggy_Property x, List_doggy_Property y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Applied_formal (List_doggy_Applied_formal x, List_doggy_Applied_formal y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Operation_def (List_doggy_Operation_def x, List_doggy_Operation_def y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Type (List_doggy_Type x, List_doggy_Type y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Rule (List_doggy_Rule x, List_doggy_Rule y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Func (List_doggy_Func x, List_doggy_Func y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Section (List_doggy_Section x, List_doggy_Section y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_FunctionDef (List_doggy_FunctionDef x, List_doggy_FunctionDef y, compare_doggy_TraverseTable table);
extern int Traverse_compare_List_doggy_Typedef (List_doggy_Typedef x, List_doggy_Typedef y, compare_doggy_TraverseTable table);


extern void doggy_fill_table (doggy_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void void_doggy_fill_table (void_doggy_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void copy_doggy_fill_table (copy_doggy_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void compare_doggy_fill_table (compare_doggy_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern struct s_doggy_TraverseTable doggy_scope_actions;

extern struct s_void_doggy_TraverseTable doggy_defining_actions;

extern struct s_void_doggy_TraverseTable doggy_applied_actions;

extern struct s_void_doggy_TraverseTable doggy_check_actions;

extern struct s_void_doggy_TraverseTable doggy_print_actions;

extern struct s_copy_doggy_TraverseTable doggy_copy_actions;

extern struct s_compare_doggy_TraverseTable doggy_compare_actions;

typedef int doggy_NameSpaces;

extern doggy_NameSpaces doggy_namespaces[2];

#define doggy_DefaultNameSpace doggy_namespaces[0]
#define doggy_TypeNameSpace doggy_namespaces[1]

#define doggy_NUM_NAMESPACES 2

extern void Decorate_doggy (doggy_doggy r);

#endif /* _doggy */
