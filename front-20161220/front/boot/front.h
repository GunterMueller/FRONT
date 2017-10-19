#ifndef _front
#define _front

#include <stdarg.h>
#include <stddef.h>
#include <front/basic_types.h>

typedef enum {
  front_SubType_kind,
  front_NoType_kind
} front_Super_tag;
extern char *front_Super_tag_names[];
#define NUM_front_Super_tag 2

typedef enum {
  front_NewScope,
  front_OpenScope,
  front_CloseScope
} front_Scoping;
extern char *front_Scoping_names[];
#define NUM_front_Scoping 3

typedef enum {
  front_LabeledAlt_kind,
  front_UnLabeledAlt_kind
} front_Alternative_tag;
extern char *front_Alternative_tag_names[];
#define NUM_front_Alternative_tag 2

typedef enum {
  front_LabeledSym_kind,
  front_AltSymbol_kind,
  front_SymbolSeq_kind,
  front_CompareSym_kind,
  front_AppliedSym_kind,
  front_StringSymbol_kind,
  front_CharSymbol_kind,
  front_KeywordSymbol_kind,
  front_OnceSymbol_kind,
  front_OptSymbol_kind,
  front_OptMoreSymbol_kind,
  front_MoreSymbol_kind,
  front_EmptySym_kind,
  front_LayoutString_kind,
  front_LayoutAction_kind,
  front_IdSym_kind,
  front_DefiningSym_kind
} front_Symbol_tag;
extern char *front_Symbol_tag_names[];
#define NUM_front_Symbol_tag 17

typedef enum {
  front_AndTranspose,
  front_AndLeft,
  front_AndRight,
  front_AndCenter
} front_And;
extern char *front_And_names[];
#define NUM_front_And 4

typedef enum {
  front_OrCenter,
  front_OrLeft,
  front_OrRight,
  front_OrTranspose
} front_Or;
extern char *front_Or_names[];
#define NUM_front_Or 4

typedef enum {
  front_DefId_kind,
  front_DefExpr_kind
} front_Defining_id_tag;
extern char *front_Defining_id_tag_names[];
#define NUM_front_Defining_id_tag 2

typedef enum {
  front_Defining,
  front_Redefining,
  front_Overloading
} front_Define;
extern char *front_Define_names[];
#define NUM_front_Define 3

typedef enum {
  front_WhenCreate_kind,
  front_WhenScope_kind,
  front_WhenDefining_kind,
  front_WhenApplied_kind,
  front_WhenChecks_kind
} front_FieldInit_tag;
extern char *front_FieldInit_tag_names[];
#define NUM_front_FieldInit_tag 5

typedef enum {
  front_BinExpr_kind,
  front_MonExpr_kind,
  front_IdentExpr_kind,
  front_QualExpr_kind,
  front_IntExpr_kind,
  front_BoolExpr_kind,
  front_StringExpr_kind,
  front_NilExpr_kind,
  front_CallExpr_kind
} front_Expr_tag;
extern char *front_Expr_tag_names[];
#define NUM_front_Expr_tag 9

typedef Bool front_Alternator;

typedef enum {
  front_PlainDef_kind,
  front_MacroDef_kind
} front_Defines_tag;
extern char *front_Defines_tag_names[];
#define NUM_front_Defines_tag 2

typedef enum {
  front_AppliedName,
  front_AppliedField
} front_NameOrField;
extern char *front_NameOrField_names[];
#define NUM_front_NameOrField 2

typedef enum {
  front_NonTerminalScope_kind
} front_Scope_tag;
extern char *front_Scope_tag_names[];
#define NUM_front_Scope_tag 1

#ifndef DEF_TYPE_front_front
#define DEF_TYPE_front_front
typedef struct s_front_front    *front_front;
#endif

#ifndef DEF_TYPE_front_Import
#define DEF_TYPE_front_Import
typedef struct s_front_Import   *front_Import;
#endif

#ifndef DEF_TYPE_front_ImportedNonTerminal
#define DEF_TYPE_front_ImportedNonTerminal
typedef struct s_front_ImportedNonTerminal      *front_ImportedNonTerminal;
#endif

#ifndef DEF_TYPE_front_NonTerminal
#define DEF_TYPE_front_NonTerminal
typedef struct s_front_NonTerminal      *front_NonTerminal;
#endif

#ifndef DEF_TYPE_front_Super
#define DEF_TYPE_front_Super
typedef struct s_front_Super    *front_Super;
typedef front_Super front_NoType;
typedef front_Super front_SubType;
#endif

#ifndef DEF_TYPE_front_Rhs
#define DEF_TYPE_front_Rhs
typedef struct s_front_Rhs      *front_Rhs;
#endif

#ifndef DEF_TYPE_front_Alternative
#define DEF_TYPE_front_Alternative
typedef struct s_front_Alternative      *front_Alternative;
typedef front_Alternative front_UnLabeledAlt;
typedef front_Alternative front_LabeledAlt;
#endif

#ifndef DEF_TYPE_front_Symbol
#define DEF_TYPE_front_Symbol
typedef struct s_front_Symbol   *front_Symbol;
typedef front_Symbol front_DefiningSym;
typedef front_Symbol front_IdSym;
typedef front_Symbol front_LayoutAction;
typedef front_Symbol front_LayoutString;
typedef front_Symbol front_EmptySym;
typedef front_Symbol front_MoreSymbol;
typedef front_Symbol front_OptMoreSymbol;
typedef front_Symbol front_OptSymbol;
typedef front_Symbol front_OnceSymbol;
typedef front_Symbol front_CompoundSym;
typedef front_Symbol front_KeywordSymbol;
typedef front_Symbol front_CharSymbol;
typedef front_Symbol front_StringSymbol;
typedef front_Symbol front_AppliedSym;
typedef front_Symbol front_SimpleSymbol;
typedef front_Symbol front_CompareSym;
typedef front_Symbol front_Symbol2;
typedef front_Symbol front_SymbolSeq;
typedef front_Symbol front_AltSymbol;
typedef front_Symbol front_LabeledSym;
#endif

#ifndef DEF_TYPE_front_Defining_id
#define DEF_TYPE_front_Defining_id
typedef struct s_front_Defining_id      *front_Defining_id;
typedef front_Defining_id front_DefExpr;
typedef front_Defining_id front_DefId;
#endif

#ifndef DEF_TYPE_front_Field
#define DEF_TYPE_front_Field
typedef struct s_front_Field    *front_Field;
#endif

#ifndef DEF_TYPE_front_FieldInit
#define DEF_TYPE_front_FieldInit
typedef struct s_front_FieldInit        *front_FieldInit;
typedef front_FieldInit front_WhenChecks;
typedef front_FieldInit front_WhenApplied;
typedef front_FieldInit front_WhenDefining;
typedef front_FieldInit front_WhenScope;
typedef front_FieldInit front_WhenCreate;
#endif

#ifndef DEF_TYPE_front_Type
#define DEF_TYPE_front_Type
typedef struct s_front_Type     *front_Type;
#endif

#ifndef DEF_TYPE_front_Expr
#define DEF_TYPE_front_Expr
typedef struct s_front_Expr     *front_Expr;
typedef front_Expr front_CallExpr;
typedef front_Expr front_NilExpr;
typedef front_Expr front_StringExpr;
typedef front_Expr front_BoolExpr;
typedef front_Expr front_IntExpr;
typedef front_Expr front_QualExpr;
typedef front_Expr front_IdentExpr;
typedef front_Expr front_SimpleExpr;
typedef front_Expr front_MonExpr;
typedef front_Expr front_MonExpr1;
typedef front_Expr front_BinExpr;
#endif

#ifndef DEF_TYPE_front_Check
#define DEF_TYPE_front_Check
typedef struct s_front_Check    *front_Check;
#endif

#ifndef DEF_TYPE_front_ScanInfo
#define DEF_TYPE_front_ScanInfo
typedef struct s_front_ScanInfo *front_ScanInfo;
#endif

#ifndef DEF_TYPE_front_Defines
#define DEF_TYPE_front_Defines
typedef struct s_front_Defines  *front_Defines;
typedef front_Defines front_MacroDef;
typedef front_Defines front_PlainDef;
#endif

#ifndef DEF_TYPE_front_NameSpace
#define DEF_TYPE_front_NameSpace
typedef struct s_front_NameSpace        *front_NameSpace;
#endif

#ifndef DEF_TYPE_front_dummy
#define DEF_TYPE_front_dummy
typedef struct s_front_dummy    *front_dummy;
#endif

#ifndef DEF_TYPE_front_Scope
#define DEF_TYPE_front_Scope
typedef struct s_front_Scope    *front_Scope;
typedef front_Scope front_NonTerminalScope;
#endif

#ifndef DEF_TYPE_List_List_front_Symbol
#define DEF_TYPE_List_List_front_Symbol
typedef struct s_List_List_front_Symbol *List_List_front_Symbol;
#endif

#ifndef DEF_TYPE_List_front_Expr
#define DEF_TYPE_List_front_Expr
typedef struct s_List_front_Expr        *List_front_Expr;
#endif

#ifndef DEF_TYPE_List_front_Type
#define DEF_TYPE_List_front_Type
typedef struct s_List_front_Type        *List_front_Type;
#endif

#ifndef DEF_TYPE_List_front_FieldInit
#define DEF_TYPE_List_front_FieldInit
typedef struct s_List_front_FieldInit   *List_front_FieldInit;
#endif

#ifndef DEF_TYPE_List_front_And
#define DEF_TYPE_List_front_And
typedef struct s_List_front_And *List_front_And;
#endif

#ifndef DEF_TYPE_List_front_Field
#define DEF_TYPE_List_front_Field
typedef struct s_List_front_Field       *List_front_Field;
#endif

#ifndef DEF_TYPE_List_front_Symbol
#define DEF_TYPE_List_front_Symbol
typedef struct s_List_front_Symbol      *List_front_Symbol;
#endif

#ifndef DEF_TYPE_List_front_Check
#define DEF_TYPE_List_front_Check
typedef struct s_List_front_Check       *List_front_Check;
#endif

#ifndef DEF_TYPE_List_front_Or
#define DEF_TYPE_List_front_Or
typedef struct s_List_front_Or  *List_front_Or;
#endif

#ifndef DEF_TYPE_List_front_Alternative
#define DEF_TYPE_List_front_Alternative
typedef struct s_List_front_Alternative *List_front_Alternative;
#endif

#ifndef DEF_TYPE_List_front_Scoping
#define DEF_TYPE_List_front_Scoping
typedef struct s_List_front_Scoping     *List_front_Scoping;
#endif

#ifndef DEF_TYPE_List_front_ImportedNonTerminal
#define DEF_TYPE_List_front_ImportedNonTerminal
typedef struct s_List_front_ImportedNonTerminal *List_front_ImportedNonTerminal;
#endif

#ifndef DEF_TYPE_List_front_NonTerminal
#define DEF_TYPE_List_front_NonTerminal
typedef struct s_List_front_NonTerminal *List_front_NonTerminal;
#endif

#ifndef DEF_TYPE_List_front_Import
#define DEF_TYPE_List_front_Import
typedef struct s_List_front_Import      *List_front_Import;
#endif

#ifndef DEF_TYPE_List_front_NameSpace
#define DEF_TYPE_List_front_NameSpace
typedef struct s_List_front_NameSpace   *List_front_NameSpace;
#endif

#include <front/scan_support.h>
#include <front/print_support.h>
#include <front/SymTab.h>
#include "front_parse.h"
#include "front_defs.h"

#include "Types.h"
#include "grammar.h"
#include "cpp.h"
typedef Bind Bind_front_NameSpace;
typedef List_Bind List_Bind_front_NameSpace;
#define List_Bind_front_NameSpace_data(x) (Bind_front_NameSpace)Front_List_data((Front_List)(x))
#define List_Bind_front_NameSpace_next(x) (List_Bind_front_NameSpace)Front_List_next((Front_List)(x))
#define Bind_front_NameSpace_kind 3

typedef Bind Bind_front_Alternative;
typedef List_Bind List_Bind_front_Alternative;
#define List_Bind_front_Alternative_data(x) (Bind_front_Alternative)Front_List_data((Front_List)(x))
#define List_Bind_front_Alternative_next(x) (List_Bind_front_Alternative)Front_List_next((Front_List)(x))
#define Bind_front_Alternative_kind 2

typedef Bind Bind_front_NonTerminal;
typedef List_Bind List_Bind_front_NonTerminal;
#define List_Bind_front_NonTerminal_data(x) (Bind_front_NonTerminal)Front_List_data((Front_List)(x))
#define List_Bind_front_NonTerminal_next(x) (List_Bind_front_NonTerminal)Front_List_next((Front_List)(x))
#define Bind_front_NonTerminal_kind 1

typedef Bind Bind_front_ImportedNonTerminal;
typedef List_Bind List_Bind_front_ImportedNonTerminal;
#define List_Bind_front_ImportedNonTerminal_data(x) (Bind_front_ImportedNonTerminal)Front_List_data((Front_List)(x))
#define List_Bind_front_ImportedNonTerminal_next(x) (List_Bind_front_ImportedNonTerminal)Front_List_next((Front_List)(x))
#define Bind_front_ImportedNonTerminal_kind 0

extern front_front front_root;

#ifndef DEF_STRUCT_front_front
#define DEF_STRUCT_front_front

struct s_front_front {
  SrcInfo       src_info;  
  List_Ident    uses;  
  List_front_NameSpace  namespaces;  
  List_front_Import     imports;  
  List_front_NonTerminal        rules;  
} ;

#define front_front_src_info(_p)        ((*_p).src_info)
#define front_front_srcinfo(_p) ((*_p).src_info)
#define front_front_loc(_p)     ((*_p).src_info->loc)
#define front_front_uses(_p)    ((*_p).uses)
#define front_front_namespaces(_p)      ((*_p).namespaces)
#define front_front_imports(_p) ((*_p).imports)
#define front_front_rules(_p)   ((*_p).rules)

extern front_front Create_front_front	(SrcInfo src_info, List_Ident uses, List_front_NameSpace namespaces, List_front_Import imports, List_front_NonTerminal rules);

#endif /* DEF_STRUCT_front_front */

#ifndef DEF_STRUCT_front_Import
#define DEF_STRUCT_front_Import

struct s_front_Import {
  SrcInfo       src_info;  
  Ident grammar;  
  List_front_ImportedNonTerminal        nts;  
} ;

#define front_Import_src_info(_p)       ((*_p).src_info)
#define front_Import_srcinfo(_p)        ((*_p).src_info)
#define front_Import_loc(_p)    ((*_p).src_info->loc)
#define front_Import_grammar(_p)        ((*_p).grammar)
#define front_Import_nts(_p)    ((*_p).nts)

extern front_Import Create_front_Import	(SrcInfo src_info, Ident grammar, List_front_ImportedNonTerminal nts);

#endif /* DEF_STRUCT_front_Import */

#ifndef DEF_STRUCT_front_ImportedNonTerminal
#define DEF_STRUCT_front_ImportedNonTerminal

struct s_front_ImportedNonTerminal {
  SrcInfo       src_info;  
  Int   _num;  
  front_Scope   scope;  
  front_Scope   old_scope;  
  Ident id;  
  Bind_front_ImportedNonTerminal        id_bind;  
  Ident type;  
  Ident grammar;  
} ;

#define front_ImportedNonTerminal_src_info(_p)  ((*_p).src_info)
#define front_ImportedNonTerminal_srcinfo(_p)   ((*_p).src_info)
#define front_ImportedNonTerminal_loc(_p)       ((*_p).src_info->loc)
#define front_ImportedNonTerminal__num(_p)      ((*_p)._num)
#define front_ImportedNonTerminal_scope(_p)     ((*_p).scope)
#define front_ImportedNonTerminal_old_scope(_p) ((*_p).old_scope)
#define front_ImportedNonTerminal_id(_p)        ((*_p).id)
#define front_ImportedNonTerminal_id_bind(_p)   ((*_p).id_bind)
#define front_ImportedNonTerminal_type(_p)      ((*_p).type)
#define front_ImportedNonTerminal_grammar(_p)   ((*_p).grammar)

extern front_ImportedNonTerminal Create_front_ImportedNonTerminal	(SrcInfo src_info, Ident id, Ident type);

#endif /* DEF_STRUCT_front_ImportedNonTerminal */

#ifndef DEF_STRUCT_front_NonTerminal
#define DEF_STRUCT_front_NonTerminal

struct s_front_NonTerminal {
  SrcInfo       src_info;  
  Int   _num;  
  front_Scope   scope;  
  front_Scope   old_scope;  
  Bool  is_root;  
  front_ScanInfo        scan;  
  Ident id;  
  Bind_front_NonTerminal        id_bind;  
  front_Super   super;  
  Bool  meemo;  
  Bool  enumerate;  
  Bool  skip;  
  front_Defines alias;  
  front_Rhs     rhs;  
  front_Alternative     alt;  
  Bool  reachable;  
} ;

#define front_NonTerminal_src_info(_p)  ((*_p).src_info)
#define front_NonTerminal_srcinfo(_p)   ((*_p).src_info)
#define front_NonTerminal_loc(_p)       ((*_p).src_info->loc)
#define front_NonTerminal__num(_p)      ((*_p)._num)
#define front_NonTerminal_scope(_p)     ((*_p).scope)
#define front_NonTerminal_old_scope(_p) ((*_p).old_scope)
#define front_NonTerminal_is_root(_p)   ((*_p).is_root)
#define front_NonTerminal_scan(_p)      ((*_p).scan)
#define front_NonTerminal_id(_p)        ((*_p).id)
#define front_NonTerminal_id_bind(_p)   ((*_p).id_bind)
#define front_NonTerminal_super(_p)     ((*_p).super)
#define front_NonTerminal_meemo(_p)     ((*_p).meemo)
#define front_NonTerminal_enumerate(_p) ((*_p).enumerate)
#define front_NonTerminal_skip(_p)      ((*_p).skip)
#define front_NonTerminal_alias(_p)     ((*_p).alias)
#define front_NonTerminal_rhs(_p)       ((*_p).rhs)
#define front_NonTerminal_alt(_p)       ((*_p).alt)
#define front_NonTerminal_reachable(_p) ((*_p).reachable)

extern front_NonTerminal Create_front_NonTerminal	(SrcInfo src_info, Bool is_root, front_ScanInfo scan, Ident id, front_Super super, Bool meemo, Bool enumerate, Bool skip, front_Defines alias, front_Rhs rhs);

#endif /* DEF_STRUCT_front_NonTerminal */

#ifndef DEF_STRUCT_front_Super
#define DEF_STRUCT_front_Super

struct s_front_Super {
  SrcInfo       src_info;  
  Int   _num;  
  front_Scope   scope;  
  front_Scope   old_scope;  
  front_Super_tag       tag;  
  union {
  struct s_front_SubType {
    Ident       x;  
  } front_SubType;
  struct s_front_NoType {
  } front_NoType;
} sub;
  Ident id;  
  Bind_front_NonTerminal        super_bind;  
  front_NonTerminal     super;  
} ;

#define front_Super_src_info(_p)        ((*_p).src_info)
#define front_Super_srcinfo(_p) ((*_p).src_info)
#define front_Super_loc(_p)     ((*_p).src_info->loc)
#define front_Super__num(_p)    ((*_p)._num)
#define front_Super_scope(_p)   ((*_p).scope)
#define front_Super_old_scope(_p)       ((*_p).old_scope)
#define front_Super_tag(_p)     ((*_p).tag)
#define front_SubType_x(_p)     ((*_p).sub.front_SubType.x)
#define front_Super_id(_p)      ((*_p).id)
#define front_Super_super_bind(_p)      ((*_p).super_bind)
#define front_Super_super(_p)   ((*_p).super)

extern front_NoType Create_front_NoType	(SrcInfo src_info, Ident id);
extern front_SubType Create_front_SubType	(SrcInfo src_info, Ident x, Ident id);

#endif /* DEF_STRUCT_front_Super */

#ifndef DEF_STRUCT_front_Rhs
#define DEF_STRUCT_front_Rhs

struct s_front_Rhs {
  SrcInfo       src_info;  
  List_front_Scoping    sc;  
  front_Symbol  syms1;  
  Ident x;  
  List_front_Alternative        alts;  
  List_front_Or ops;  
  Ident y;  
  front_Symbol  syms2;  
  List_front_Check      checklist;  
  List_field    fields;  
} ;

#define front_Rhs_src_info(_p)  ((*_p).src_info)
#define front_Rhs_srcinfo(_p)   ((*_p).src_info)
#define front_Rhs_loc(_p)       ((*_p).src_info->loc)
#define front_Rhs_sc(_p)        ((*_p).sc)
#define front_Rhs_syms1(_p)     ((*_p).syms1)
#define front_Rhs_x(_p) ((*_p).x)
#define front_Rhs_alts(_p)      ((*_p).alts)
#define front_Rhs_ops(_p)       ((*_p).ops)
#define front_Rhs_y(_p) ((*_p).y)
#define front_Rhs_syms2(_p)     ((*_p).syms2)
#define front_Rhs_checklist(_p) ((*_p).checklist)
#define front_Rhs_fields(_p)    ((*_p).fields)

extern front_Rhs Create_front_Rhs	(SrcInfo src_info, List_front_Scoping sc, front_Symbol syms1, Ident x, List_front_Alternative alts, List_front_Or ops, Ident y, front_Symbol syms2, List_front_Check checklist);

#endif /* DEF_STRUCT_front_Rhs */

#ifndef DEF_STRUCT_front_Alternative
#define DEF_STRUCT_front_Alternative

struct s_front_Alternative {
  SrcInfo       src_info;  
  Int   _num;  
  front_Scope   scope;  
  front_Scope   old_scope;  
  front_Alternative_tag tag;  
  union {
  struct s_front_LabeledAlt {
    Ident       id;  
    Bind_front_Alternative      id_bind;  
    Bool        meemo;  
    Bool        skip;  
    Ident       def;  
    front_Rhs   rhs;  
    List_field  fields;  
  } front_LabeledAlt;
  struct s_front_UnLabeledAlt {
    front_Symbol        syms;  
  } front_UnLabeledAlt;
} sub;
  struct_type   type;  
  grammar_RegExpr       re;  
} ;

#define front_Alternative_src_info(_p)  ((*_p).src_info)
#define front_Alternative_srcinfo(_p)   ((*_p).src_info)
#define front_Alternative_loc(_p)       ((*_p).src_info->loc)
#define front_Alternative__num(_p)      ((*_p)._num)
#define front_Alternative_scope(_p)     ((*_p).scope)
#define front_Alternative_old_scope(_p) ((*_p).old_scope)
#define front_Alternative_tag(_p)       ((*_p).tag)
#define front_LabeledAlt_id(_p) ((*_p).sub.front_LabeledAlt.id)
#define front_LabeledAlt_id_bind(_p)    ((*_p).sub.front_LabeledAlt.id_bind)
#define front_LabeledAlt_meemo(_p)      ((*_p).sub.front_LabeledAlt.meemo)
#define front_LabeledAlt_skip(_p)       ((*_p).sub.front_LabeledAlt.skip)
#define front_LabeledAlt_def(_p)        ((*_p).sub.front_LabeledAlt.def)
#define front_LabeledAlt_rhs(_p)        ((*_p).sub.front_LabeledAlt.rhs)
#define front_LabeledAlt_fields(_p)     ((*_p).sub.front_LabeledAlt.fields)
#define front_UnLabeledAlt_syms(_p)     ((*_p).sub.front_UnLabeledAlt.syms)
#define front_Alternative_type(_p)      ((*_p).type)
#define front_Alternative_re(_p)        ((*_p).re)

extern front_UnLabeledAlt Create_front_UnLabeledAlt	(SrcInfo src_info, front_Symbol syms);
extern front_LabeledAlt Create_front_LabeledAlt	(SrcInfo src_info, Ident id, Bool meemo, Bool skip, Ident def, front_Rhs rhs);

#endif /* DEF_STRUCT_front_Alternative */

#ifndef DEF_STRUCT_front_Symbol
#define DEF_STRUCT_front_Symbol

struct s_front_Symbol {
  SrcInfo       src_info;  
  Int   _num;  
  front_Scope   scope;  
  front_Scope   old_scope;  
  front_Symbol_tag      tag;  
  union {
  struct s_front_LabeledSym {
    Ident       id;  
    front_Symbol        sym;  
  } front_LabeledSym;
  struct s_front_AltSymbol {
    front_Symbol        syms1;  
    front_Alternator    alt;  
    List_front_Symbol   syms;  
  } front_AltSymbol;
  struct s_front_SymbolSeq {
    List_front_Symbol   symbols;  
    List_front_Field    my_fields;  
    List_front_And      ands;  
  } front_SymbolSeq;
  struct s_front_Symbol2 {
    front_Symbol        sym;  
    Ident       comp;  
  } front_Symbol2;
  struct s_front_SimpleSymbol {
    union {
    struct s_front_AppliedSym {
      Ident     nt_id;  
      Bind_front_NonTerminal    nt_bind;  
      front_NonTerminal nt;  
      Bind_front_Alternative    alt_bind;  
      front_Alternative alt;  
      front_NameOrField field;  
      Ident     name;  
      front_Expr        sc;  
      Bool      warn;  
    } front_AppliedSym;
    struct s_front_StringSymbol {
      String    string;  
      Ident     n;  
      front_Type        type;  
    } front_StringSymbol;
    struct s_front_CharSymbol {
      String    chr;  
      front_Type        type;  
    } front_CharSymbol;
    struct s_front_KeywordSymbol {
      String    keyword;  
      front_Type        type;  
    } front_KeywordSymbol;
    struct s_front_CompoundSym {
      List_front_Symbol sym;  
      List_front_Or     ops;  
      union {
      struct s_front_OnceSymbol {
      } front_OnceSymbol;
      struct s_front_OptSymbol {
        Bool    in_line;  
      } front_OptSymbol;
      struct s_front_OptMoreSymbol {
      } front_OptMoreSymbol;
      struct s_front_MoreSymbol {
        Ident   more;  
      } front_MoreSymbol;
    } sub;
    } front_CompoundSym;
    struct s_front_EmptySym {
    } front_EmptySym;
    struct s_front_LayoutString {
      String    layout;  
    } front_LayoutString;
    struct s_front_LayoutAction {
      front_Expr        layout;  
    } front_LayoutAction;
  } sub;
  } front_SimpleSymbol;
  struct s_front_IdSym {
    Ident       id;  
    front_Type  type;  
    Bind_front_NonTerminal      nt_bind;  
    front_NonTerminal   nt;  
    Bind_front_ImportedNonTerminal      import_bind;  
    front_ImportedNonTerminal   import;  
  } front_IdSym;
  struct s_front_DefiningSym {
    Bool        forward;  
    front_Define        def;  
    front_Defining_id   id;  
    Ident       ns_id;  
    Bind_front_NameSpace        ns_bind;  
    front_NameSpace     ns;  
    front_Expr  sc;  
  } front_DefiningSym;
} sub;
  List_field    fields;  
  Bool  empty;  
} ;

#define front_Symbol_src_info(_p)       ((*_p).src_info)
#define front_Symbol_srcinfo(_p)        ((*_p).src_info)
#define front_Symbol_loc(_p)    ((*_p).src_info->loc)
#define front_Symbol__num(_p)   ((*_p)._num)
#define front_Symbol_scope(_p)  ((*_p).scope)
#define front_Symbol_old_scope(_p)      ((*_p).old_scope)
#define front_Symbol_tag(_p)    ((*_p).tag)
#define front_LabeledSym_id(_p) ((*_p).sub.front_LabeledSym.id)
#define front_LabeledSym_sym(_p)        ((*_p).sub.front_LabeledSym.sym)
#define front_AltSymbol_syms1(_p)       ((*_p).sub.front_AltSymbol.syms1)
#define front_AltSymbol_alt(_p) ((*_p).sub.front_AltSymbol.alt)
#define front_AltSymbol_syms(_p)        ((*_p).sub.front_AltSymbol.syms)
#define front_SymbolSeq_symbols(_p)     ((*_p).sub.front_SymbolSeq.symbols)
#define front_SymbolSeq_my_fields(_p)   ((*_p).sub.front_SymbolSeq.my_fields)
#define front_SymbolSeq_ands(_p)        ((*_p).sub.front_SymbolSeq.ands)
#define front_Symbol2_sym(_p)   ((*_p).sub.front_Symbol2.sym)
#define front_Symbol2_comp(_p)  ((*_p).sub.front_Symbol2.comp)
#define front_AppliedSym_nt_id(_p)      ((*_p).sub.front_SimpleSymbol.sub.front_AppliedSym.nt_id)
#define front_AppliedSym_nt_bind(_p)    ((*_p).sub.front_SimpleSymbol.sub.front_AppliedSym.nt_bind)
#define front_AppliedSym_nt(_p) ((*_p).sub.front_SimpleSymbol.sub.front_AppliedSym.nt)
#define front_AppliedSym_alt_bind(_p)   ((*_p).sub.front_SimpleSymbol.sub.front_AppliedSym.alt_bind)
#define front_AppliedSym_alt(_p)        ((*_p).sub.front_SimpleSymbol.sub.front_AppliedSym.alt)
#define front_AppliedSym_field(_p)      ((*_p).sub.front_SimpleSymbol.sub.front_AppliedSym.field)
#define front_AppliedSym_name(_p)       ((*_p).sub.front_SimpleSymbol.sub.front_AppliedSym.name)
#define front_AppliedSym_sc(_p) ((*_p).sub.front_SimpleSymbol.sub.front_AppliedSym.sc)
#define front_AppliedSym_warn(_p)       ((*_p).sub.front_SimpleSymbol.sub.front_AppliedSym.warn)
#define front_StringSymbol_string(_p)   ((*_p).sub.front_SimpleSymbol.sub.front_StringSymbol.string)
#define front_StringSymbol_n(_p)        ((*_p).sub.front_SimpleSymbol.sub.front_StringSymbol.n)
#define front_StringSymbol_type(_p)     ((*_p).sub.front_SimpleSymbol.sub.front_StringSymbol.type)
#define front_CharSymbol_chr(_p)        ((*_p).sub.front_SimpleSymbol.sub.front_CharSymbol.chr)
#define front_CharSymbol_type(_p)       ((*_p).sub.front_SimpleSymbol.sub.front_CharSymbol.type)
#define front_KeywordSymbol_keyword(_p) ((*_p).sub.front_SimpleSymbol.sub.front_KeywordSymbol.keyword)
#define front_KeywordSymbol_type(_p)    ((*_p).sub.front_SimpleSymbol.sub.front_KeywordSymbol.type)
#define front_CompoundSym_sym(_p)       ((*_p).sub.front_SimpleSymbol.sub.front_CompoundSym.sym)
#define front_CompoundSym_ops(_p)       ((*_p).sub.front_SimpleSymbol.sub.front_CompoundSym.ops)
#define front_OptSymbol_in_line(_p)     ((*_p).sub.front_SimpleSymbol.sub.front_CompoundSym.sub.front_OptSymbol.in_line)
#define front_MoreSymbol_more(_p)       ((*_p).sub.front_SimpleSymbol.sub.front_CompoundSym.sub.front_MoreSymbol.more)
#define front_LayoutString_layout(_p)   ((*_p).sub.front_SimpleSymbol.sub.front_LayoutString.layout)
#define front_LayoutAction_layout(_p)   ((*_p).sub.front_SimpleSymbol.sub.front_LayoutAction.layout)
#define front_IdSym_id(_p)      ((*_p).sub.front_IdSym.id)
#define front_IdSym_type(_p)    ((*_p).sub.front_IdSym.type)
#define front_IdSym_nt_bind(_p) ((*_p).sub.front_IdSym.nt_bind)
#define front_IdSym_nt(_p)      ((*_p).sub.front_IdSym.nt)
#define front_IdSym_import_bind(_p)     ((*_p).sub.front_IdSym.import_bind)
#define front_IdSym_import(_p)  ((*_p).sub.front_IdSym.import)
#define front_DefiningSym_forward(_p)   ((*_p).sub.front_DefiningSym.forward)
#define front_DefiningSym_def(_p)       ((*_p).sub.front_DefiningSym.def)
#define front_DefiningSym_id(_p)        ((*_p).sub.front_DefiningSym.id)
#define front_DefiningSym_ns_id(_p)     ((*_p).sub.front_DefiningSym.ns_id)
#define front_DefiningSym_ns_bind(_p)   ((*_p).sub.front_DefiningSym.ns_bind)
#define front_DefiningSym_ns(_p)        ((*_p).sub.front_DefiningSym.ns)
#define front_DefiningSym_sc(_p)        ((*_p).sub.front_DefiningSym.sc)
#define front_Symbol_fields(_p) ((*_p).fields)
#define front_Symbol_empty(_p)  ((*_p).empty)

extern front_DefiningSym Create_front_DefiningSym	(SrcInfo src_info, Bool forward, front_Define def, front_Defining_id id, Ident ns_id, front_Expr sc);
extern front_IdSym Create_front_IdSym	(SrcInfo src_info, Ident id, front_Type type);
extern front_LayoutAction Create_front_LayoutAction	(SrcInfo src_info, front_Expr layout);
extern front_LayoutString Create_front_LayoutString	(SrcInfo src_info, String layout);
extern front_EmptySym Create_front_EmptySym	(SrcInfo src_info);
extern front_MoreSymbol Create_front_MoreSymbol	(SrcInfo src_info, List_front_Symbol sym, List_front_Or ops, Ident more);
extern front_OptMoreSymbol Create_front_OptMoreSymbol	(SrcInfo src_info, List_front_Symbol sym, List_front_Or ops);
extern front_OptSymbol Create_front_OptSymbol	(SrcInfo src_info, List_front_Symbol sym, List_front_Or ops, Bool in_line);
extern front_OnceSymbol Create_front_OnceSymbol	(SrcInfo src_info, List_front_Symbol sym, List_front_Or ops);
extern front_KeywordSymbol Create_front_KeywordSymbol	(SrcInfo src_info, String keyword, front_Type type);
extern front_CharSymbol Create_front_CharSymbol	(SrcInfo src_info, String chr, front_Type type);
extern front_StringSymbol Create_front_StringSymbol	(SrcInfo src_info, String string, Ident n, front_Type type);
extern front_AppliedSym Create_front_AppliedSym	(SrcInfo src_info, Ident nt_id, front_NameOrField field, Ident name, front_Expr sc, Bool warn);
extern front_CompareSym Create_front_CompareSym	(SrcInfo src_info, front_Symbol sym, Ident comp);
extern front_SymbolSeq Create_front_SymbolSeq	(SrcInfo src_info, List_front_Symbol symbols, List_front_Field my_fields, List_front_And ands);
extern front_AltSymbol Create_front_AltSymbol	(SrcInfo src_info, front_Symbol syms1, front_Alternator alt, List_front_Symbol syms);
extern front_LabeledSym Create_front_LabeledSym	(SrcInfo src_info, Ident id, front_Symbol sym);

#endif /* DEF_STRUCT_front_Symbol */

#ifndef DEF_STRUCT_front_Defining_id
#define DEF_STRUCT_front_Defining_id

struct s_front_Defining_id {
  SrcInfo       src_info;  
  front_Defining_id_tag tag;  
  union {
  struct s_front_DefId {
    front_Symbol        id;  
  } front_DefId;
  struct s_front_DefExpr {
    front_Expr  e;  
  } front_DefExpr;
} sub;
} ;

#define front_Defining_id_src_info(_p)  ((*_p).src_info)
#define front_Defining_id_srcinfo(_p)   ((*_p).src_info)
#define front_Defining_id_loc(_p)       ((*_p).src_info->loc)
#define front_Defining_id_tag(_p)       ((*_p).tag)
#define front_DefId_id(_p)      ((*_p).sub.front_DefId.id)
#define front_DefExpr_e(_p)     ((*_p).sub.front_DefExpr.e)

extern front_DefExpr Create_front_DefExpr	(SrcInfo src_info, front_Expr e);
extern front_DefId Create_front_DefId	(SrcInfo src_info, front_Symbol id);

#endif /* DEF_STRUCT_front_Defining_id */

#ifndef DEF_STRUCT_front_Field
#define DEF_STRUCT_front_Field

struct s_front_Field {
  SrcInfo       src_info;  
  Ident id;  
  front_Type    type;  
  Ident assign;  
  List_front_FieldInit  when;  
  Bool  traverse;  
  Bool  clear;  
  Bool  dont_clear;  
} ;

#define front_Field_src_info(_p)        ((*_p).src_info)
#define front_Field_srcinfo(_p) ((*_p).src_info)
#define front_Field_loc(_p)     ((*_p).src_info->loc)
#define front_Field_id(_p)      ((*_p).id)
#define front_Field_type(_p)    ((*_p).type)
#define front_Field_assign(_p)  ((*_p).assign)
#define front_Field_when(_p)    ((*_p).when)
#define front_Field_traverse(_p)        ((*_p).traverse)
#define front_Field_clear(_p)   ((*_p).clear)
#define front_Field_dont_clear(_p)      ((*_p).dont_clear)

extern front_Field Create_front_Field	(SrcInfo src_info, Ident id, front_Type type, Ident assign, List_front_FieldInit when, Bool traverse, Bool clear, Bool dont_clear);

#endif /* DEF_STRUCT_front_Field */

#ifndef DEF_STRUCT_front_FieldInit
#define DEF_STRUCT_front_FieldInit

struct s_front_FieldInit {
  SrcInfo       src_info;  
  front_FieldInit_tag   tag;  
  union {
  struct s_front_WhenCreate {
    Bool        c;  
  } front_WhenCreate;
  struct s_front_WhenScope {
  } front_WhenScope;
  struct s_front_WhenDefining {
  } front_WhenDefining;
  struct s_front_WhenApplied {
  } front_WhenApplied;
  struct s_front_WhenChecks {
  } front_WhenChecks;
} sub;
  front_Expr    expr;  
} ;

#define front_FieldInit_src_info(_p)    ((*_p).src_info)
#define front_FieldInit_srcinfo(_p)     ((*_p).src_info)
#define front_FieldInit_loc(_p) ((*_p).src_info->loc)
#define front_FieldInit_tag(_p) ((*_p).tag)
#define front_WhenCreate_c(_p)  ((*_p).sub.front_WhenCreate.c)
#define front_FieldInit_expr(_p)        ((*_p).expr)

extern front_WhenChecks Create_front_WhenChecks	(SrcInfo src_info, front_Expr expr);
extern front_WhenApplied Create_front_WhenApplied	(SrcInfo src_info, front_Expr expr);
extern front_WhenDefining Create_front_WhenDefining	(SrcInfo src_info, front_Expr expr);
extern front_WhenScope Create_front_WhenScope	(SrcInfo src_info, front_Expr expr);
extern front_WhenCreate Create_front_WhenCreate	(SrcInfo src_info, Bool c, front_Expr expr);

#endif /* DEF_STRUCT_front_FieldInit */

#ifndef DEF_STRUCT_front_Type
#define DEF_STRUCT_front_Type

struct s_front_Type {
  SrcInfo       src_info;  
  Int   _num;  
  front_Scope   scope;  
  front_Scope   old_scope;  
  Ident id;  
  List_front_Type       args;  
  Bind_front_NonTerminal        nt_bind;  
  front_NonTerminal     nt;  
  Bind_front_ImportedNonTerminal        import_bind;  
  front_ImportedNonTerminal     import;  
  Bind_front_Alternative        alt_bind;  
  front_Alternative     alt;  
} ;

#define front_Type_src_info(_p) ((*_p).src_info)
#define front_Type_srcinfo(_p)  ((*_p).src_info)
#define front_Type_loc(_p)      ((*_p).src_info->loc)
#define front_Type__num(_p)     ((*_p)._num)
#define front_Type_scope(_p)    ((*_p).scope)
#define front_Type_old_scope(_p)        ((*_p).old_scope)
#define front_Type_id(_p)       ((*_p).id)
#define front_Type_args(_p)     ((*_p).args)
#define front_Type_nt_bind(_p)  ((*_p).nt_bind)
#define front_Type_nt(_p)       ((*_p).nt)
#define front_Type_import_bind(_p)      ((*_p).import_bind)
#define front_Type_import(_p)   ((*_p).import)
#define front_Type_alt_bind(_p) ((*_p).alt_bind)
#define front_Type_alt(_p)      ((*_p).alt)

extern front_Type Create_front_Type	(SrcInfo src_info, Ident id, List_front_Type args);

#endif /* DEF_STRUCT_front_Type */

#ifndef DEF_STRUCT_front_Expr
#define DEF_STRUCT_front_Expr

struct s_front_Expr {
  SrcInfo       src_info;  
  front_Expr_tag        tag;  
  union {
  struct s_front_BinExpr {
    List_front_Expr     args;  
    List_Ident  ops;  
  } front_BinExpr;
  struct s_front_MonExpr1 {
    List_Ident  ops;  
    front_Expr  arg;  
  } front_MonExpr1;
  struct s_front_SimpleExpr {
    union {
    struct s_front_IdentExpr {
      Ident     id;  
    } front_IdentExpr;
    struct s_front_QualExpr {
      front_Expr        prefix;  
      Ident     id;  
    } front_QualExpr;
    struct s_front_IntExpr {
      Int       i;  
    } front_IntExpr;
    struct s_front_BoolExpr {
      Bool      b;  
    } front_BoolExpr;
    struct s_front_StringExpr {
      String    string;  
    } front_StringExpr;
    struct s_front_NilExpr {
    } front_NilExpr;
    struct s_front_CallExpr {
      front_Expr        func;  
      List_front_Expr   args;  
    } front_CallExpr;
  } sub;
  } front_SimpleExpr;
} sub;
} ;

#define front_Expr_src_info(_p) ((*_p).src_info)
#define front_Expr_srcinfo(_p)  ((*_p).src_info)
#define front_Expr_loc(_p)      ((*_p).src_info->loc)
#define front_Expr_tag(_p)      ((*_p).tag)
#define front_BinExpr_args(_p)  ((*_p).sub.front_BinExpr.args)
#define front_BinExpr_ops(_p)   ((*_p).sub.front_BinExpr.ops)
#define front_MonExpr1_ops(_p)  ((*_p).sub.front_MonExpr1.ops)
#define front_MonExpr1_arg(_p)  ((*_p).sub.front_MonExpr1.arg)
#define front_IdentExpr_id(_p)  ((*_p).sub.front_SimpleExpr.sub.front_IdentExpr.id)
#define front_QualExpr_prefix(_p)       ((*_p).sub.front_SimpleExpr.sub.front_QualExpr.prefix)
#define front_QualExpr_id(_p)   ((*_p).sub.front_SimpleExpr.sub.front_QualExpr.id)
#define front_IntExpr_i(_p)     ((*_p).sub.front_SimpleExpr.sub.front_IntExpr.i)
#define front_BoolExpr_b(_p)    ((*_p).sub.front_SimpleExpr.sub.front_BoolExpr.b)
#define front_StringExpr_string(_p)     ((*_p).sub.front_SimpleExpr.sub.front_StringExpr.string)
#define front_CallExpr_func(_p) ((*_p).sub.front_SimpleExpr.sub.front_CallExpr.func)
#define front_CallExpr_args(_p) ((*_p).sub.front_SimpleExpr.sub.front_CallExpr.args)

extern front_CallExpr Create_front_CallExpr	(SrcInfo src_info, front_Expr func, List_front_Expr args);
extern front_NilExpr Create_front_NilExpr	(SrcInfo src_info);
extern front_StringExpr Create_front_StringExpr	(SrcInfo src_info, String string);
extern front_BoolExpr Create_front_BoolExpr	(SrcInfo src_info, Bool b);
extern front_IntExpr Create_front_IntExpr	(SrcInfo src_info, Int i);
extern front_QualExpr Create_front_QualExpr	(SrcInfo src_info, front_Expr prefix, Ident id);
extern front_IdentExpr Create_front_IdentExpr	(SrcInfo src_info, Ident id);
extern front_MonExpr Create_front_MonExpr	(SrcInfo src_info, List_Ident ops, front_Expr arg);
extern front_BinExpr Create_front_BinExpr	(SrcInfo src_info, List_front_Expr args, List_Ident ops);

#endif /* DEF_STRUCT_front_Expr */

#ifndef DEF_STRUCT_front_Check
#define DEF_STRUCT_front_Check

struct s_front_Check {
  SrcInfo       src_info;  
  front_Expr    cond;  
  Bool  warn;  
  List_front_Expr       message;  
} ;

#define front_Check_src_info(_p)        ((*_p).src_info)
#define front_Check_srcinfo(_p) ((*_p).src_info)
#define front_Check_loc(_p)     ((*_p).src_info->loc)
#define front_Check_cond(_p)    ((*_p).cond)
#define front_Check_warn(_p)    ((*_p).warn)
#define front_Check_message(_p) ((*_p).message)

extern front_Check Create_front_Check	(SrcInfo src_info, front_Expr cond, Bool warn, List_front_Expr message);

#endif /* DEF_STRUCT_front_Check */

#ifndef DEF_STRUCT_front_ScanInfo
#define DEF_STRUCT_front_ScanInfo

struct s_front_ScanInfo {
  SrcInfo       src_info;  
  front_Type    type;  
  Bool  comment;  
} ;

#define front_ScanInfo_src_info(_p)     ((*_p).src_info)
#define front_ScanInfo_srcinfo(_p)      ((*_p).src_info)
#define front_ScanInfo_loc(_p)  ((*_p).src_info->loc)
#define front_ScanInfo_type(_p) ((*_p).type)
#define front_ScanInfo_comment(_p)      ((*_p).comment)

extern front_ScanInfo Create_front_ScanInfo	(SrcInfo src_info, front_Type type, Bool comment);

#endif /* DEF_STRUCT_front_ScanInfo */

#ifndef DEF_STRUCT_front_Defines
#define DEF_STRUCT_front_Defines

struct s_front_Defines {
  SrcInfo       src_info;  
  front_Defines_tag     tag;  
  Ident id;  
} ;

#define front_Defines_src_info(_p)      ((*_p).src_info)
#define front_Defines_srcinfo(_p)       ((*_p).src_info)
#define front_Defines_loc(_p)   ((*_p).src_info->loc)
#define front_Defines_tag(_p)   ((*_p).tag)
#define front_Defines_id(_p)    ((*_p).id)

extern front_MacroDef Create_front_MacroDef	(SrcInfo src_info, Ident id);
extern front_PlainDef Create_front_PlainDef	(SrcInfo src_info, Ident id);

#endif /* DEF_STRUCT_front_Defines */

#ifndef DEF_STRUCT_front_NameSpace
#define DEF_STRUCT_front_NameSpace

struct s_front_NameSpace {
  SrcInfo       src_info;  
  Int   _num;  
  front_Scope   scope;  
  front_Scope   old_scope;  
  Ident id;  
  Bind_front_NameSpace  id_bind;  
} ;

#define front_NameSpace_src_info(_p)    ((*_p).src_info)
#define front_NameSpace_srcinfo(_p)     ((*_p).src_info)
#define front_NameSpace_loc(_p) ((*_p).src_info->loc)
#define front_NameSpace__num(_p)        ((*_p)._num)
#define front_NameSpace_scope(_p)       ((*_p).scope)
#define front_NameSpace_old_scope(_p)   ((*_p).old_scope)
#define front_NameSpace_id(_p)  ((*_p).id)
#define front_NameSpace_id_bind(_p)     ((*_p).id_bind)

extern front_NameSpace Create_front_NameSpace	(SrcInfo src_info, Ident id);

#endif /* DEF_STRUCT_front_NameSpace */

#ifndef DEF_STRUCT_front_dummy
#define DEF_STRUCT_front_dummy

struct s_front_dummy {
  SrcInfo       src_info;  
  List_List_front_Symbol        x;  
} ;

#define front_dummy_src_info(_p)        ((*_p).src_info)
#define front_dummy_srcinfo(_p) ((*_p).src_info)
#define front_dummy_loc(_p)     ((*_p).src_info->loc)
#define front_dummy_x(_p)       ((*_p).x)

extern front_dummy Create_front_dummy	(SrcInfo src_info);

#endif /* DEF_STRUCT_front_dummy */

#ifndef DEF_STRUCT_front_Scope
#define DEF_STRUCT_front_Scope

struct s_front_Scope {
  front_Scope   next;  
  Int   _self;  
  Int   _end;  
  front_Scope_tag       tag;  
  union {
  struct s_front_NonTerminalScope {
    front_NonTerminal   data;  
  } front_NonTerminalScope;
} sub;
} ;

#define front_Scope_next(_p)    ((*_p).next)
#define front_Scope__self(_p)   ((*_p)._self)
#define front_Scope__end(_p)    ((*_p)._end)
#define front_Scope_tag(_p)     ((*_p).tag)
#define front_NonTerminalScope_data(_p) ((*_p).sub.front_NonTerminalScope.data)

extern front_NonTerminalScope Create_front_NonTerminalScope	(front_Scope next, front_NonTerminal data);

#endif /* DEF_STRUCT_front_Scope */

#ifndef DEF_STRUCT_List_List_front_Symbol
#define DEF_STRUCT_List_List_front_Symbol

struct s_List_List_front_Symbol {
  List_front_Symbol     data;  
  List_List_front_Symbol        next;  
} ;

#define List_List_front_Symbol_data(_p) ((*_p).data)
#define List_List_front_Symbol_next(_p) ((*_p).next)

#ifndef Create_List_List_front_Symbol
#define Create_List_List_front_Symbol(x,y) (List_List_front_Symbol)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_List_front_Symbol_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_List_front_Symbol */

#ifndef DEF_STRUCT_List_front_Expr
#define DEF_STRUCT_List_front_Expr

struct s_List_front_Expr {
  front_Expr    data;  
  List_front_Expr       next;  
} ;

#define List_front_Expr_data(_p)        ((*_p).data)
#define List_front_Expr_next(_p)        ((*_p).next)

#ifndef Create_List_front_Expr
#define Create_List_front_Expr(x,y) (List_front_Expr)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_Expr_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_Expr */

#ifndef DEF_STRUCT_List_front_Type
#define DEF_STRUCT_List_front_Type

struct s_List_front_Type {
  front_Type    data;  
  List_front_Type       next;  
} ;

#define List_front_Type_data(_p)        ((*_p).data)
#define List_front_Type_next(_p)        ((*_p).next)

#ifndef Create_List_front_Type
#define Create_List_front_Type(x,y) (List_front_Type)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_Type_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_Type */

#ifndef DEF_STRUCT_List_front_FieldInit
#define DEF_STRUCT_List_front_FieldInit

struct s_List_front_FieldInit {
  front_FieldInit       data;  
  List_front_FieldInit  next;  
} ;

#define List_front_FieldInit_data(_p)   ((*_p).data)
#define List_front_FieldInit_next(_p)   ((*_p).next)

#ifndef Create_List_front_FieldInit
#define Create_List_front_FieldInit(x,y) (List_front_FieldInit)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_FieldInit_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_FieldInit */

#ifndef DEF_STRUCT_List_front_And
#define DEF_STRUCT_List_front_And

struct s_List_front_And {
  front_And     data;  
  List_front_And        next;  
} ;

#define List_front_And_data(_p) ((*_p).data)
#define List_front_And_next(_p) ((*_p).next)

#ifndef Create_List_front_And
#define Create_List_front_And(x,y) (List_front_And)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_And_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_And */

#ifndef DEF_STRUCT_List_front_Field
#define DEF_STRUCT_List_front_Field

struct s_List_front_Field {
  front_Field   data;  
  List_front_Field      next;  
} ;

#define List_front_Field_data(_p)       ((*_p).data)
#define List_front_Field_next(_p)       ((*_p).next)

#ifndef Create_List_front_Field
#define Create_List_front_Field(x,y) (List_front_Field)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_Field_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_Field */

#ifndef DEF_STRUCT_List_front_Symbol
#define DEF_STRUCT_List_front_Symbol

struct s_List_front_Symbol {
  front_Symbol  data;  
  List_front_Symbol     next;  
} ;

#define List_front_Symbol_data(_p)      ((*_p).data)
#define List_front_Symbol_next(_p)      ((*_p).next)

#ifndef Create_List_front_Symbol
#define Create_List_front_Symbol(x,y) (List_front_Symbol)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_Symbol_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_Symbol */

#ifndef DEF_STRUCT_List_front_Check
#define DEF_STRUCT_List_front_Check

struct s_List_front_Check {
  front_Check   data;  
  List_front_Check      next;  
} ;

#define List_front_Check_data(_p)       ((*_p).data)
#define List_front_Check_next(_p)       ((*_p).next)

#ifndef Create_List_front_Check
#define Create_List_front_Check(x,y) (List_front_Check)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_Check_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_Check */

#ifndef DEF_STRUCT_List_front_Or
#define DEF_STRUCT_List_front_Or

struct s_List_front_Or {
  front_Or      data;  
  List_front_Or next;  
} ;

#define List_front_Or_data(_p)  ((*_p).data)
#define List_front_Or_next(_p)  ((*_p).next)

#ifndef Create_List_front_Or
#define Create_List_front_Or(x,y) (List_front_Or)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_Or_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_Or */

#ifndef DEF_STRUCT_List_front_Alternative
#define DEF_STRUCT_List_front_Alternative

struct s_List_front_Alternative {
  front_Alternative     data;  
  List_front_Alternative        next;  
} ;

#define List_front_Alternative_data(_p) ((*_p).data)
#define List_front_Alternative_next(_p) ((*_p).next)

#ifndef Create_List_front_Alternative
#define Create_List_front_Alternative(x,y) (List_front_Alternative)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_Alternative_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_Alternative */

#ifndef DEF_STRUCT_List_front_Scoping
#define DEF_STRUCT_List_front_Scoping

struct s_List_front_Scoping {
  front_Scoping data;  
  List_front_Scoping    next;  
} ;

#define List_front_Scoping_data(_p)     ((*_p).data)
#define List_front_Scoping_next(_p)     ((*_p).next)

#ifndef Create_List_front_Scoping
#define Create_List_front_Scoping(x,y) (List_front_Scoping)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_Scoping_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_Scoping */

#ifndef DEF_STRUCT_List_front_ImportedNonTerminal
#define DEF_STRUCT_List_front_ImportedNonTerminal

struct s_List_front_ImportedNonTerminal {
  front_ImportedNonTerminal     data;  
  List_front_ImportedNonTerminal        next;  
} ;

#define List_front_ImportedNonTerminal_data(_p) ((*_p).data)
#define List_front_ImportedNonTerminal_next(_p) ((*_p).next)

#ifndef Create_List_front_ImportedNonTerminal
#define Create_List_front_ImportedNonTerminal(x,y) (List_front_ImportedNonTerminal)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_ImportedNonTerminal_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_ImportedNonTerminal */

#ifndef DEF_STRUCT_List_front_NonTerminal
#define DEF_STRUCT_List_front_NonTerminal

struct s_List_front_NonTerminal {
  front_NonTerminal     data;  
  List_front_NonTerminal        next;  
} ;

#define List_front_NonTerminal_data(_p) ((*_p).data)
#define List_front_NonTerminal_next(_p) ((*_p).next)

#ifndef Create_List_front_NonTerminal
#define Create_List_front_NonTerminal(x,y) (List_front_NonTerminal)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_NonTerminal_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_NonTerminal */

#ifndef DEF_STRUCT_List_front_Import
#define DEF_STRUCT_List_front_Import

struct s_List_front_Import {
  front_Import  data;  
  List_front_Import     next;  
} ;

#define List_front_Import_data(_p)      ((*_p).data)
#define List_front_Import_next(_p)      ((*_p).next)

#ifndef Create_List_front_Import
#define Create_List_front_Import(x,y) (List_front_Import)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_Import_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_Import */

#ifndef DEF_STRUCT_List_front_NameSpace
#define DEF_STRUCT_List_front_NameSpace

struct s_List_front_NameSpace {
  front_NameSpace       data;  
  List_front_NameSpace  next;  
} ;

#define List_front_NameSpace_data(_p)   ((*_p).data)
#define List_front_NameSpace_next(_p)   ((*_p).next)

#ifndef Create_List_front_NameSpace
#define Create_List_front_NameSpace(x,y) (List_front_NameSpace)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_front_NameSpace_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_front_NameSpace */

#define PRE_ACTION  1
#define POST_ACTION 0

typedef struct s_front_TraverseTable {
  Front_Traversal traversal;
  Pointer (*action_front[2]) (front_front, Pointer);
  Bool skip_children_front;
  Pointer (*action_Import[2]) (front_Import, Pointer);
  Bool skip_children_Import;
  Pointer (*action_ImportedNonTerminal[2]) (front_ImportedNonTerminal, Pointer);
  Bool skip_children_ImportedNonTerminal;
  Pointer (*action_NonTerminal[2]) (front_NonTerminal, Pointer);
  Bool skip_children_NonTerminal;
  Pointer (*action_Super[2]) (front_Super, Pointer);
  Bool skip_children_Super;
  Pointer (*action_SubType[2]) (front_SubType, Pointer);
  Bool skip_children_SubType;
  Pointer (*action_NoType[2]) (front_NoType, Pointer);
  Bool skip_children_NoType;
  Pointer (*action_Rhs[2]) (front_Rhs, Pointer);
  Bool skip_children_Rhs;
  Pointer (*action_Alternative[2]) (front_Alternative, Pointer);
  Bool skip_children_Alternative;
  Pointer (*action_LabeledAlt[2]) (front_LabeledAlt, Pointer);
  Bool skip_children_LabeledAlt;
  Pointer (*action_UnLabeledAlt[2]) (front_UnLabeledAlt, Pointer);
  Bool skip_children_UnLabeledAlt;
  Pointer (*action_Symbol[2]) (front_Symbol, Pointer);
  Bool skip_children_Symbol;
  Pointer (*action_LabeledSym[2]) (front_LabeledSym, Pointer);
  Bool skip_children_LabeledSym;
  Pointer (*action_AltSymbol[2]) (front_AltSymbol, Pointer);
  Bool skip_children_AltSymbol;
  Pointer (*action_SymbolSeq[2]) (front_SymbolSeq, Pointer);
  Bool skip_children_SymbolSeq;
  Pointer (*action_Symbol2[2]) (front_Symbol2, Pointer);
  Bool skip_children_Symbol2;
  Pointer (*action_CompareSym[2]) (front_CompareSym, Pointer);
  Bool skip_children_CompareSym;
  Pointer (*action_SimpleSymbol[2]) (front_SimpleSymbol, Pointer);
  Bool skip_children_SimpleSymbol;
  Pointer (*action_AppliedSym[2]) (front_AppliedSym, Pointer);
  Bool skip_children_AppliedSym;
  Pointer (*action_StringSymbol[2]) (front_StringSymbol, Pointer);
  Bool skip_children_StringSymbol;
  Pointer (*action_CharSymbol[2]) (front_CharSymbol, Pointer);
  Bool skip_children_CharSymbol;
  Pointer (*action_KeywordSymbol[2]) (front_KeywordSymbol, Pointer);
  Bool skip_children_KeywordSymbol;
  Pointer (*action_CompoundSym[2]) (front_CompoundSym, Pointer);
  Bool skip_children_CompoundSym;
  Pointer (*action_OnceSymbol[2]) (front_OnceSymbol, Pointer);
  Bool skip_children_OnceSymbol;
  Pointer (*action_OptSymbol[2]) (front_OptSymbol, Pointer);
  Bool skip_children_OptSymbol;
  Pointer (*action_OptMoreSymbol[2]) (front_OptMoreSymbol, Pointer);
  Bool skip_children_OptMoreSymbol;
  Pointer (*action_MoreSymbol[2]) (front_MoreSymbol, Pointer);
  Bool skip_children_MoreSymbol;
  Pointer (*action_EmptySym[2]) (front_EmptySym, Pointer);
  Bool skip_children_EmptySym;
  Pointer (*action_LayoutString[2]) (front_LayoutString, Pointer);
  Bool skip_children_LayoutString;
  Pointer (*action_LayoutAction[2]) (front_LayoutAction, Pointer);
  Bool skip_children_LayoutAction;
  Pointer (*action_IdSym[2]) (front_IdSym, Pointer);
  Bool skip_children_IdSym;
  Pointer (*action_DefiningSym[2]) (front_DefiningSym, Pointer);
  Bool skip_children_DefiningSym;
  Pointer (*action_Defining_id[2]) (front_Defining_id, Pointer);
  Bool skip_children_Defining_id;
  Pointer (*action_DefId[2]) (front_DefId, Pointer);
  Bool skip_children_DefId;
  Pointer (*action_DefExpr[2]) (front_DefExpr, Pointer);
  Bool skip_children_DefExpr;
  Pointer (*action_Field[2]) (front_Field, Pointer);
  Bool skip_children_Field;
  Pointer (*action_FieldInit[2]) (front_FieldInit, Pointer);
  Bool skip_children_FieldInit;
  Pointer (*action_WhenCreate[2]) (front_WhenCreate, Pointer);
  Bool skip_children_WhenCreate;
  Pointer (*action_WhenScope[2]) (front_WhenScope, Pointer);
  Bool skip_children_WhenScope;
  Pointer (*action_WhenDefining[2]) (front_WhenDefining, Pointer);
  Bool skip_children_WhenDefining;
  Pointer (*action_WhenApplied[2]) (front_WhenApplied, Pointer);
  Bool skip_children_WhenApplied;
  Pointer (*action_WhenChecks[2]) (front_WhenChecks, Pointer);
  Bool skip_children_WhenChecks;
  Pointer (*action_Type[2]) (front_Type, Pointer);
  Bool skip_children_Type;
  Pointer (*action_Expr[2]) (front_Expr, Pointer);
  Bool skip_children_Expr;
  Pointer (*action_BinExpr[2]) (front_BinExpr, Pointer);
  Bool skip_children_BinExpr;
  Pointer (*action_MonExpr1[2]) (front_MonExpr1, Pointer);
  Bool skip_children_MonExpr1;
  Pointer (*action_MonExpr[2]) (front_MonExpr, Pointer);
  Bool skip_children_MonExpr;
  Pointer (*action_SimpleExpr[2]) (front_SimpleExpr, Pointer);
  Bool skip_children_SimpleExpr;
  Pointer (*action_IdentExpr[2]) (front_IdentExpr, Pointer);
  Bool skip_children_IdentExpr;
  Pointer (*action_QualExpr[2]) (front_QualExpr, Pointer);
  Bool skip_children_QualExpr;
  Pointer (*action_IntExpr[2]) (front_IntExpr, Pointer);
  Bool skip_children_IntExpr;
  Pointer (*action_BoolExpr[2]) (front_BoolExpr, Pointer);
  Bool skip_children_BoolExpr;
  Pointer (*action_StringExpr[2]) (front_StringExpr, Pointer);
  Bool skip_children_StringExpr;
  Pointer (*action_NilExpr[2]) (front_NilExpr, Pointer);
  Bool skip_children_NilExpr;
  Pointer (*action_CallExpr[2]) (front_CallExpr, Pointer);
  Bool skip_children_CallExpr;
  Pointer (*action_Check[2]) (front_Check, Pointer);
  Bool skip_children_Check;
  Pointer (*action_ScanInfo[2]) (front_ScanInfo, Pointer);
  Bool skip_children_ScanInfo;
  Pointer (*action_Defines[2]) (front_Defines, Pointer);
  Bool skip_children_Defines;
  Pointer (*action_PlainDef[2]) (front_PlainDef, Pointer);
  Bool skip_children_PlainDef;
  Pointer (*action_MacroDef[2]) (front_MacroDef, Pointer);
  Bool skip_children_MacroDef;
  Pointer (*action_NameSpace[2]) (front_NameSpace, Pointer);
  Bool skip_children_NameSpace;
  Pointer (*action_dummy[2]) (front_dummy, Pointer);
  Bool skip_children_dummy;
  Pointer (*action_Scope[2]) (front_Scope, Pointer);
  Bool skip_children_Scope;
  Pointer (*action_NonTerminalScope[2]) (front_NonTerminalScope, Pointer);
  Bool skip_children_NonTerminalScope;
  Pointer (*action_List_List_Symbol[2]) (List_List_front_Symbol, Pointer);
  Bool skip_children_List_List_Symbol;
  Pointer (*action_List_Expr[2]) (List_front_Expr, Pointer);
  Bool skip_children_List_Expr;
  Pointer (*action_List_Type[2]) (List_front_Type, Pointer);
  Bool skip_children_List_Type;
  Pointer (*action_List_FieldInit[2]) (List_front_FieldInit, Pointer);
  Bool skip_children_List_FieldInit;
  Pointer (*action_List_And[2]) (List_front_And, Pointer);
  Bool skip_children_List_And;
  Pointer (*action_List_Field[2]) (List_front_Field, Pointer);
  Bool skip_children_List_Field;
  Pointer (*action_List_Symbol[2]) (List_front_Symbol, Pointer);
  Bool skip_children_List_Symbol;
  Pointer (*action_List_Check[2]) (List_front_Check, Pointer);
  Bool skip_children_List_Check;
  Pointer (*action_List_Or[2]) (List_front_Or, Pointer);
  Bool skip_children_List_Or;
  Pointer (*action_List_Alternative[2]) (List_front_Alternative, Pointer);
  Bool skip_children_List_Alternative;
  Pointer (*action_List_Scoping[2]) (List_front_Scoping, Pointer);
  Bool skip_children_List_Scoping;
  Pointer (*action_List_ImportedNonTerminal[2]) (List_front_ImportedNonTerminal, Pointer);
  Bool skip_children_List_ImportedNonTerminal;
  Pointer (*action_List_NonTerminal[2]) (List_front_NonTerminal, Pointer);
  Bool skip_children_List_NonTerminal;
  Pointer (*action_List_Import[2]) (List_front_Import, Pointer);
  Bool skip_children_List_Import;
  Pointer (*action_List_NameSpace[2]) (List_front_NameSpace, Pointer);
  Bool skip_children_List_NameSpace;
  Pointer (*action_Scoping[2]) (front_Scoping, Pointer);
  Bool skip_children_Scoping;
  Pointer (*action_NewScope[2]) (front_Scoping, Pointer);
  Bool skip_children_NewScope;
  Pointer (*action_OpenScope[2]) (front_Scoping, Pointer);
  Bool skip_children_OpenScope;
  Pointer (*action_CloseScope[2]) (front_Scoping, Pointer);
  Bool skip_children_CloseScope;
  Pointer (*action_And[2]) (front_And, Pointer);
  Bool skip_children_And;
  Pointer (*action_AndTranspose[2]) (front_And, Pointer);
  Bool skip_children_AndTranspose;
  Pointer (*action_AndLeft[2]) (front_And, Pointer);
  Bool skip_children_AndLeft;
  Pointer (*action_AndRight[2]) (front_And, Pointer);
  Bool skip_children_AndRight;
  Pointer (*action_AndCenter[2]) (front_And, Pointer);
  Bool skip_children_AndCenter;
  Pointer (*action_Or[2]) (front_Or, Pointer);
  Bool skip_children_Or;
  Pointer (*action_OrCenter[2]) (front_Or, Pointer);
  Bool skip_children_OrCenter;
  Pointer (*action_OrLeft[2]) (front_Or, Pointer);
  Bool skip_children_OrLeft;
  Pointer (*action_OrRight[2]) (front_Or, Pointer);
  Bool skip_children_OrRight;
  Pointer (*action_OrTranspose[2]) (front_Or, Pointer);
  Bool skip_children_OrTranspose;
  Pointer (*action_Define[2]) (front_Define, Pointer);
  Bool skip_children_Define;
  Pointer (*action_Defining[2]) (front_Define, Pointer);
  Bool skip_children_Defining;
  Pointer (*action_Redefining[2]) (front_Define, Pointer);
  Bool skip_children_Redefining;
  Pointer (*action_Overloading[2]) (front_Define, Pointer);
  Bool skip_children_Overloading;
  Pointer (*action_Alternator[2]) (front_Alternator, Pointer);
  Bool skip_children_Alternator;
  Pointer (*action_NameOrField[2]) (front_NameOrField, Pointer);
  Bool skip_children_NameOrField;
  Pointer (*action_AppliedName[2]) (front_NameOrField, Pointer);
  Bool skip_children_AppliedName;
  Pointer (*action_AppliedField[2]) (front_NameOrField, Pointer);
  Bool skip_children_AppliedField;
} *front_TraverseTable;

extern Pointer Traverse_front_Scoping (front_Scoping me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_And (front_And me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Or (front_Or me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Define (front_Define me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Alternator (front_Alternator me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_NameOrField (front_NameOrField me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_front (front_front me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Import (front_Import me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_ImportedNonTerminal (front_ImportedNonTerminal me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_NonTerminal (front_NonTerminal me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Super (front_Super me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Rhs (front_Rhs me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Alternative (front_Alternative me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Symbol (front_Symbol me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Defining_id (front_Defining_id me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Field (front_Field me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_FieldInit (front_FieldInit me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Type (front_Type me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Expr (front_Expr me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Check (front_Check me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_ScanInfo (front_ScanInfo me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Defines (front_Defines me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_NameSpace (front_NameSpace me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_dummy (front_dummy me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_front_Scope (front_Scope me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_List_front_Symbol (List_List_front_Symbol me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_Expr (List_front_Expr me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_Type (List_front_Type me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_FieldInit (List_front_FieldInit me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_And (List_front_And me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_Field (List_front_Field me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_Symbol (List_front_Symbol me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_Check (List_front_Check me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_Or (List_front_Or me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_Alternative (List_front_Alternative me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_Scoping (List_front_Scoping me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_NonTerminal (List_front_NonTerminal me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_Import (List_front_Import me, front_TraverseTable table, Pointer val);
extern Pointer Traverse_List_front_NameSpace (List_front_NameSpace me, front_TraverseTable table, Pointer val);

typedef struct s_void_front_TraverseTable {
  void (*action_front[2]) (front_front);
  Bool skip_children_front;
  void (*action_Import[2]) (front_Import);
  Bool skip_children_Import;
  void (*action_ImportedNonTerminal[2]) (front_ImportedNonTerminal);
  Bool skip_children_ImportedNonTerminal;
  void (*action_NonTerminal[2]) (front_NonTerminal);
  Bool skip_children_NonTerminal;
  void (*action_Super[2]) (front_Super);
  Bool skip_children_Super;
  void (*action_SubType[2]) (front_SubType);
  Bool skip_children_SubType;
  void (*action_NoType[2]) (front_NoType);
  Bool skip_children_NoType;
  void (*action_Rhs[2]) (front_Rhs);
  Bool skip_children_Rhs;
  void (*action_Alternative[2]) (front_Alternative);
  Bool skip_children_Alternative;
  void (*action_LabeledAlt[2]) (front_LabeledAlt);
  Bool skip_children_LabeledAlt;
  void (*action_UnLabeledAlt[2]) (front_UnLabeledAlt);
  Bool skip_children_UnLabeledAlt;
  void (*action_Symbol[2]) (front_Symbol);
  Bool skip_children_Symbol;
  void (*action_LabeledSym[2]) (front_LabeledSym);
  Bool skip_children_LabeledSym;
  void (*action_AltSymbol[2]) (front_AltSymbol);
  Bool skip_children_AltSymbol;
  void (*action_SymbolSeq[2]) (front_SymbolSeq);
  Bool skip_children_SymbolSeq;
  void (*action_Symbol2[2]) (front_Symbol2);
  Bool skip_children_Symbol2;
  void (*action_CompareSym[2]) (front_CompareSym);
  Bool skip_children_CompareSym;
  void (*action_SimpleSymbol[2]) (front_SimpleSymbol);
  Bool skip_children_SimpleSymbol;
  void (*action_AppliedSym[2]) (front_AppliedSym);
  Bool skip_children_AppliedSym;
  void (*action_StringSymbol[2]) (front_StringSymbol);
  Bool skip_children_StringSymbol;
  void (*action_CharSymbol[2]) (front_CharSymbol);
  Bool skip_children_CharSymbol;
  void (*action_KeywordSymbol[2]) (front_KeywordSymbol);
  Bool skip_children_KeywordSymbol;
  void (*action_CompoundSym[2]) (front_CompoundSym);
  Bool skip_children_CompoundSym;
  void (*action_OnceSymbol[2]) (front_OnceSymbol);
  Bool skip_children_OnceSymbol;
  void (*action_OptSymbol[2]) (front_OptSymbol);
  Bool skip_children_OptSymbol;
  void (*action_OptMoreSymbol[2]) (front_OptMoreSymbol);
  Bool skip_children_OptMoreSymbol;
  void (*action_MoreSymbol[2]) (front_MoreSymbol);
  Bool skip_children_MoreSymbol;
  void (*action_EmptySym[2]) (front_EmptySym);
  Bool skip_children_EmptySym;
  void (*action_LayoutString[2]) (front_LayoutString);
  Bool skip_children_LayoutString;
  void (*action_LayoutAction[2]) (front_LayoutAction);
  Bool skip_children_LayoutAction;
  void (*action_IdSym[2]) (front_IdSym);
  Bool skip_children_IdSym;
  void (*action_DefiningSym[2]) (front_DefiningSym);
  Bool skip_children_DefiningSym;
  void (*action_Defining_id[2]) (front_Defining_id);
  Bool skip_children_Defining_id;
  void (*action_DefId[2]) (front_DefId);
  Bool skip_children_DefId;
  void (*action_DefExpr[2]) (front_DefExpr);
  Bool skip_children_DefExpr;
  void (*action_Field[2]) (front_Field);
  Bool skip_children_Field;
  void (*action_FieldInit[2]) (front_FieldInit);
  Bool skip_children_FieldInit;
  void (*action_WhenCreate[2]) (front_WhenCreate);
  Bool skip_children_WhenCreate;
  void (*action_WhenScope[2]) (front_WhenScope);
  Bool skip_children_WhenScope;
  void (*action_WhenDefining[2]) (front_WhenDefining);
  Bool skip_children_WhenDefining;
  void (*action_WhenApplied[2]) (front_WhenApplied);
  Bool skip_children_WhenApplied;
  void (*action_WhenChecks[2]) (front_WhenChecks);
  Bool skip_children_WhenChecks;
  void (*action_Type[2]) (front_Type);
  Bool skip_children_Type;
  void (*action_Expr[2]) (front_Expr);
  Bool skip_children_Expr;
  void (*action_BinExpr[2]) (front_BinExpr);
  Bool skip_children_BinExpr;
  void (*action_MonExpr1[2]) (front_MonExpr1);
  Bool skip_children_MonExpr1;
  void (*action_MonExpr[2]) (front_MonExpr);
  Bool skip_children_MonExpr;
  void (*action_SimpleExpr[2]) (front_SimpleExpr);
  Bool skip_children_SimpleExpr;
  void (*action_IdentExpr[2]) (front_IdentExpr);
  Bool skip_children_IdentExpr;
  void (*action_QualExpr[2]) (front_QualExpr);
  Bool skip_children_QualExpr;
  void (*action_IntExpr[2]) (front_IntExpr);
  Bool skip_children_IntExpr;
  void (*action_BoolExpr[2]) (front_BoolExpr);
  Bool skip_children_BoolExpr;
  void (*action_StringExpr[2]) (front_StringExpr);
  Bool skip_children_StringExpr;
  void (*action_NilExpr[2]) (front_NilExpr);
  Bool skip_children_NilExpr;
  void (*action_CallExpr[2]) (front_CallExpr);
  Bool skip_children_CallExpr;
  void (*action_Check[2]) (front_Check);
  Bool skip_children_Check;
  void (*action_ScanInfo[2]) (front_ScanInfo);
  Bool skip_children_ScanInfo;
  void (*action_Defines[2]) (front_Defines);
  Bool skip_children_Defines;
  void (*action_PlainDef[2]) (front_PlainDef);
  Bool skip_children_PlainDef;
  void (*action_MacroDef[2]) (front_MacroDef);
  Bool skip_children_MacroDef;
  void (*action_NameSpace[2]) (front_NameSpace);
  Bool skip_children_NameSpace;
  void (*action_dummy[2]) (front_dummy);
  Bool skip_children_dummy;
  void (*action_Scope[2]) (front_Scope);
  Bool skip_children_Scope;
  void (*action_NonTerminalScope[2]) (front_NonTerminalScope);
  Bool skip_children_NonTerminalScope;
  void (*action_List_List_Symbol[2]) (List_List_front_Symbol);
  Bool skip_children_List_List_Symbol;
  void (*action_List_Expr[2]) (List_front_Expr);
  Bool skip_children_List_Expr;
  void (*action_List_Type[2]) (List_front_Type);
  Bool skip_children_List_Type;
  void (*action_List_FieldInit[2]) (List_front_FieldInit);
  Bool skip_children_List_FieldInit;
  void (*action_List_And[2]) (List_front_And);
  Bool skip_children_List_And;
  void (*action_List_Field[2]) (List_front_Field);
  Bool skip_children_List_Field;
  void (*action_List_Symbol[2]) (List_front_Symbol);
  Bool skip_children_List_Symbol;
  void (*action_List_Check[2]) (List_front_Check);
  Bool skip_children_List_Check;
  void (*action_List_Or[2]) (List_front_Or);
  Bool skip_children_List_Or;
  void (*action_List_Alternative[2]) (List_front_Alternative);
  Bool skip_children_List_Alternative;
  void (*action_List_Scoping[2]) (List_front_Scoping);
  Bool skip_children_List_Scoping;
  void (*action_List_ImportedNonTerminal[2]) (List_front_ImportedNonTerminal);
  Bool skip_children_List_ImportedNonTerminal;
  void (*action_List_NonTerminal[2]) (List_front_NonTerminal);
  Bool skip_children_List_NonTerminal;
  void (*action_List_Import[2]) (List_front_Import);
  Bool skip_children_List_Import;
  void (*action_List_NameSpace[2]) (List_front_NameSpace);
  Bool skip_children_List_NameSpace;
  void (*action_Scoping[2]) (front_Scoping);
  Bool skip_children_Scoping;
  void (*action_NewScope[2]) (front_Scoping);
  Bool skip_children_NewScope;
  void (*action_OpenScope[2]) (front_Scoping);
  Bool skip_children_OpenScope;
  void (*action_CloseScope[2]) (front_Scoping);
  Bool skip_children_CloseScope;
  void (*action_And[2]) (front_And);
  Bool skip_children_And;
  void (*action_AndTranspose[2]) (front_And);
  Bool skip_children_AndTranspose;
  void (*action_AndLeft[2]) (front_And);
  Bool skip_children_AndLeft;
  void (*action_AndRight[2]) (front_And);
  Bool skip_children_AndRight;
  void (*action_AndCenter[2]) (front_And);
  Bool skip_children_AndCenter;
  void (*action_Or[2]) (front_Or);
  Bool skip_children_Or;
  void (*action_OrCenter[2]) (front_Or);
  Bool skip_children_OrCenter;
  void (*action_OrLeft[2]) (front_Or);
  Bool skip_children_OrLeft;
  void (*action_OrRight[2]) (front_Or);
  Bool skip_children_OrRight;
  void (*action_OrTranspose[2]) (front_Or);
  Bool skip_children_OrTranspose;
  void (*action_Define[2]) (front_Define);
  Bool skip_children_Define;
  void (*action_Defining[2]) (front_Define);
  Bool skip_children_Defining;
  void (*action_Redefining[2]) (front_Define);
  Bool skip_children_Redefining;
  void (*action_Overloading[2]) (front_Define);
  Bool skip_children_Overloading;
  void (*action_Alternator[2]) (front_Alternator);
  Bool skip_children_Alternator;
  void (*action_NameOrField[2]) (front_NameOrField);
  Bool skip_children_NameOrField;
  void (*action_AppliedName[2]) (front_NameOrField);
  Bool skip_children_AppliedName;
  void (*action_AppliedField[2]) (front_NameOrField);
  Bool skip_children_AppliedField;
} *void_front_TraverseTable;

extern void Traverse_void_front_Scoping (front_Scoping me, void_front_TraverseTable table);
extern void Traverse_void_front_And (front_And me, void_front_TraverseTable table);
extern void Traverse_void_front_Or (front_Or me, void_front_TraverseTable table);
extern void Traverse_void_front_Define (front_Define me, void_front_TraverseTable table);
extern void Traverse_void_front_Alternator (front_Alternator me, void_front_TraverseTable table);
extern void Traverse_void_front_NameOrField (front_NameOrField me, void_front_TraverseTable table);
extern void Traverse_void_front_front (front_front me, void_front_TraverseTable table);
extern void Traverse_void_front_Import (front_Import me, void_front_TraverseTable table);
extern void Traverse_void_front_ImportedNonTerminal (front_ImportedNonTerminal me, void_front_TraverseTable table);
extern void Traverse_void_front_NonTerminal (front_NonTerminal me, void_front_TraverseTable table);
extern void Traverse_void_front_Super (front_Super me, void_front_TraverseTable table);
extern void Traverse_void_front_Rhs (front_Rhs me, void_front_TraverseTable table);
extern void Traverse_void_front_Alternative (front_Alternative me, void_front_TraverseTable table);
extern void Traverse_void_front_Symbol (front_Symbol me, void_front_TraverseTable table);
extern void Traverse_void_front_Defining_id (front_Defining_id me, void_front_TraverseTable table);
extern void Traverse_void_front_Field (front_Field me, void_front_TraverseTable table);
extern void Traverse_void_front_FieldInit (front_FieldInit me, void_front_TraverseTable table);
extern void Traverse_void_front_Type (front_Type me, void_front_TraverseTable table);
extern void Traverse_void_front_Expr (front_Expr me, void_front_TraverseTable table);
extern void Traverse_void_front_Check (front_Check me, void_front_TraverseTable table);
extern void Traverse_void_front_ScanInfo (front_ScanInfo me, void_front_TraverseTable table);
extern void Traverse_void_front_Defines (front_Defines me, void_front_TraverseTable table);
extern void Traverse_void_front_NameSpace (front_NameSpace me, void_front_TraverseTable table);
extern void Traverse_void_front_dummy (front_dummy me, void_front_TraverseTable table);
extern void Traverse_void_front_Scope (front_Scope me, void_front_TraverseTable table);
extern void Traverse_void_List_List_front_Symbol (List_List_front_Symbol me, void_front_TraverseTable table);
extern void Traverse_void_List_front_Expr (List_front_Expr me, void_front_TraverseTable table);
extern void Traverse_void_List_front_Type (List_front_Type me, void_front_TraverseTable table);
extern void Traverse_void_List_front_FieldInit (List_front_FieldInit me, void_front_TraverseTable table);
extern void Traverse_void_List_front_And (List_front_And me, void_front_TraverseTable table);
extern void Traverse_void_List_front_Field (List_front_Field me, void_front_TraverseTable table);
extern void Traverse_void_List_front_Symbol (List_front_Symbol me, void_front_TraverseTable table);
extern void Traverse_void_List_front_Check (List_front_Check me, void_front_TraverseTable table);
extern void Traverse_void_List_front_Or (List_front_Or me, void_front_TraverseTable table);
extern void Traverse_void_List_front_Alternative (List_front_Alternative me, void_front_TraverseTable table);
extern void Traverse_void_List_front_Scoping (List_front_Scoping me, void_front_TraverseTable table);
extern void Traverse_void_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal me, void_front_TraverseTable table);
extern void Traverse_void_List_front_NonTerminal (List_front_NonTerminal me, void_front_TraverseTable table);
extern void Traverse_void_List_front_Import (List_front_Import me, void_front_TraverseTable table);
extern void Traverse_void_List_front_NameSpace (List_front_NameSpace me, void_front_TraverseTable table);

typedef struct s_copy_front_TraverseTable {
  Front_ClearBackEdges clear_back_edges;
  front_front (*action_front[2]) (front_front, front_front);
  Bool skip_children_front;
  front_Import (*action_Import[2]) (front_Import, front_Import);
  Bool skip_children_Import;
  front_ImportedNonTerminal (*action_ImportedNonTerminal[2]) (front_ImportedNonTerminal, front_ImportedNonTerminal);
  Bool skip_children_ImportedNonTerminal;
  front_NonTerminal (*action_NonTerminal[2]) (front_NonTerminal, front_NonTerminal);
  Bool skip_children_NonTerminal;
  front_Super (*action_Super[2]) (front_Super, front_Super);
  Bool skip_children_Super;
  front_SubType (*action_SubType[2]) (front_SubType, front_SubType);
  Bool skip_children_SubType;
  front_NoType (*action_NoType[2]) (front_NoType, front_NoType);
  Bool skip_children_NoType;
  front_Rhs (*action_Rhs[2]) (front_Rhs, front_Rhs);
  Bool skip_children_Rhs;
  front_Alternative (*action_Alternative[2]) (front_Alternative, front_Alternative);
  Bool skip_children_Alternative;
  front_LabeledAlt (*action_LabeledAlt[2]) (front_LabeledAlt, front_LabeledAlt);
  Bool skip_children_LabeledAlt;
  front_UnLabeledAlt (*action_UnLabeledAlt[2]) (front_UnLabeledAlt, front_UnLabeledAlt);
  Bool skip_children_UnLabeledAlt;
  front_Symbol (*action_Symbol[2]) (front_Symbol, front_Symbol);
  Bool skip_children_Symbol;
  front_LabeledSym (*action_LabeledSym[2]) (front_LabeledSym, front_LabeledSym);
  Bool skip_children_LabeledSym;
  front_AltSymbol (*action_AltSymbol[2]) (front_AltSymbol, front_AltSymbol);
  Bool skip_children_AltSymbol;
  front_SymbolSeq (*action_SymbolSeq[2]) (front_SymbolSeq, front_SymbolSeq);
  Bool skip_children_SymbolSeq;
  front_Symbol2 (*action_Symbol2[2]) (front_Symbol2, front_Symbol2);
  Bool skip_children_Symbol2;
  front_CompareSym (*action_CompareSym[2]) (front_CompareSym, front_CompareSym);
  Bool skip_children_CompareSym;
  front_SimpleSymbol (*action_SimpleSymbol[2]) (front_SimpleSymbol, front_SimpleSymbol);
  Bool skip_children_SimpleSymbol;
  front_AppliedSym (*action_AppliedSym[2]) (front_AppliedSym, front_AppliedSym);
  Bool skip_children_AppliedSym;
  front_StringSymbol (*action_StringSymbol[2]) (front_StringSymbol, front_StringSymbol);
  Bool skip_children_StringSymbol;
  front_CharSymbol (*action_CharSymbol[2]) (front_CharSymbol, front_CharSymbol);
  Bool skip_children_CharSymbol;
  front_KeywordSymbol (*action_KeywordSymbol[2]) (front_KeywordSymbol, front_KeywordSymbol);
  Bool skip_children_KeywordSymbol;
  front_CompoundSym (*action_CompoundSym[2]) (front_CompoundSym, front_CompoundSym);
  Bool skip_children_CompoundSym;
  front_OnceSymbol (*action_OnceSymbol[2]) (front_OnceSymbol, front_OnceSymbol);
  Bool skip_children_OnceSymbol;
  front_OptSymbol (*action_OptSymbol[2]) (front_OptSymbol, front_OptSymbol);
  Bool skip_children_OptSymbol;
  front_OptMoreSymbol (*action_OptMoreSymbol[2]) (front_OptMoreSymbol, front_OptMoreSymbol);
  Bool skip_children_OptMoreSymbol;
  front_MoreSymbol (*action_MoreSymbol[2]) (front_MoreSymbol, front_MoreSymbol);
  Bool skip_children_MoreSymbol;
  front_EmptySym (*action_EmptySym[2]) (front_EmptySym, front_EmptySym);
  Bool skip_children_EmptySym;
  front_LayoutString (*action_LayoutString[2]) (front_LayoutString, front_LayoutString);
  Bool skip_children_LayoutString;
  front_LayoutAction (*action_LayoutAction[2]) (front_LayoutAction, front_LayoutAction);
  Bool skip_children_LayoutAction;
  front_IdSym (*action_IdSym[2]) (front_IdSym, front_IdSym);
  Bool skip_children_IdSym;
  front_DefiningSym (*action_DefiningSym[2]) (front_DefiningSym, front_DefiningSym);
  Bool skip_children_DefiningSym;
  front_Defining_id (*action_Defining_id[2]) (front_Defining_id, front_Defining_id);
  Bool skip_children_Defining_id;
  front_DefId (*action_DefId[2]) (front_DefId, front_DefId);
  Bool skip_children_DefId;
  front_DefExpr (*action_DefExpr[2]) (front_DefExpr, front_DefExpr);
  Bool skip_children_DefExpr;
  front_Field (*action_Field[2]) (front_Field, front_Field);
  Bool skip_children_Field;
  front_FieldInit (*action_FieldInit[2]) (front_FieldInit, front_FieldInit);
  Bool skip_children_FieldInit;
  front_WhenCreate (*action_WhenCreate[2]) (front_WhenCreate, front_WhenCreate);
  Bool skip_children_WhenCreate;
  front_WhenScope (*action_WhenScope[2]) (front_WhenScope, front_WhenScope);
  Bool skip_children_WhenScope;
  front_WhenDefining (*action_WhenDefining[2]) (front_WhenDefining, front_WhenDefining);
  Bool skip_children_WhenDefining;
  front_WhenApplied (*action_WhenApplied[2]) (front_WhenApplied, front_WhenApplied);
  Bool skip_children_WhenApplied;
  front_WhenChecks (*action_WhenChecks[2]) (front_WhenChecks, front_WhenChecks);
  Bool skip_children_WhenChecks;
  front_Type (*action_Type[2]) (front_Type, front_Type);
  Bool skip_children_Type;
  front_Expr (*action_Expr[2]) (front_Expr, front_Expr);
  Bool skip_children_Expr;
  front_BinExpr (*action_BinExpr[2]) (front_BinExpr, front_BinExpr);
  Bool skip_children_BinExpr;
  front_MonExpr1 (*action_MonExpr1[2]) (front_MonExpr1, front_MonExpr1);
  Bool skip_children_MonExpr1;
  front_MonExpr (*action_MonExpr[2]) (front_MonExpr, front_MonExpr);
  Bool skip_children_MonExpr;
  front_SimpleExpr (*action_SimpleExpr[2]) (front_SimpleExpr, front_SimpleExpr);
  Bool skip_children_SimpleExpr;
  front_IdentExpr (*action_IdentExpr[2]) (front_IdentExpr, front_IdentExpr);
  Bool skip_children_IdentExpr;
  front_QualExpr (*action_QualExpr[2]) (front_QualExpr, front_QualExpr);
  Bool skip_children_QualExpr;
  front_IntExpr (*action_IntExpr[2]) (front_IntExpr, front_IntExpr);
  Bool skip_children_IntExpr;
  front_BoolExpr (*action_BoolExpr[2]) (front_BoolExpr, front_BoolExpr);
  Bool skip_children_BoolExpr;
  front_StringExpr (*action_StringExpr[2]) (front_StringExpr, front_StringExpr);
  Bool skip_children_StringExpr;
  front_NilExpr (*action_NilExpr[2]) (front_NilExpr, front_NilExpr);
  Bool skip_children_NilExpr;
  front_CallExpr (*action_CallExpr[2]) (front_CallExpr, front_CallExpr);
  Bool skip_children_CallExpr;
  front_Check (*action_Check[2]) (front_Check, front_Check);
  Bool skip_children_Check;
  front_ScanInfo (*action_ScanInfo[2]) (front_ScanInfo, front_ScanInfo);
  Bool skip_children_ScanInfo;
  front_Defines (*action_Defines[2]) (front_Defines, front_Defines);
  Bool skip_children_Defines;
  front_PlainDef (*action_PlainDef[2]) (front_PlainDef, front_PlainDef);
  Bool skip_children_PlainDef;
  front_MacroDef (*action_MacroDef[2]) (front_MacroDef, front_MacroDef);
  Bool skip_children_MacroDef;
  front_NameSpace (*action_NameSpace[2]) (front_NameSpace, front_NameSpace);
  Bool skip_children_NameSpace;
  front_dummy (*action_dummy[2]) (front_dummy, front_dummy);
  Bool skip_children_dummy;
  front_Scope (*action_Scope[2]) (front_Scope, front_Scope);
  Bool skip_children_Scope;
  front_NonTerminalScope (*action_NonTerminalScope[2]) (front_NonTerminalScope, front_NonTerminalScope);
  Bool skip_children_NonTerminalScope;
  List_List_front_Symbol (*action_List_List_Symbol[2]) (List_List_front_Symbol, List_List_front_Symbol);
  Bool skip_children_List_List_Symbol;
  List_front_Expr (*action_List_Expr[2]) (List_front_Expr, List_front_Expr);
  Bool skip_children_List_Expr;
  List_front_Type (*action_List_Type[2]) (List_front_Type, List_front_Type);
  Bool skip_children_List_Type;
  List_front_FieldInit (*action_List_FieldInit[2]) (List_front_FieldInit, List_front_FieldInit);
  Bool skip_children_List_FieldInit;
  List_front_And (*action_List_And[2]) (List_front_And, List_front_And);
  Bool skip_children_List_And;
  List_front_Field (*action_List_Field[2]) (List_front_Field, List_front_Field);
  Bool skip_children_List_Field;
  List_front_Symbol (*action_List_Symbol[2]) (List_front_Symbol, List_front_Symbol);
  Bool skip_children_List_Symbol;
  List_front_Check (*action_List_Check[2]) (List_front_Check, List_front_Check);
  Bool skip_children_List_Check;
  List_front_Or (*action_List_Or[2]) (List_front_Or, List_front_Or);
  Bool skip_children_List_Or;
  List_front_Alternative (*action_List_Alternative[2]) (List_front_Alternative, List_front_Alternative);
  Bool skip_children_List_Alternative;
  List_front_Scoping (*action_List_Scoping[2]) (List_front_Scoping, List_front_Scoping);
  Bool skip_children_List_Scoping;
  List_front_ImportedNonTerminal (*action_List_ImportedNonTerminal[2]) (List_front_ImportedNonTerminal, List_front_ImportedNonTerminal);
  Bool skip_children_List_ImportedNonTerminal;
  List_front_NonTerminal (*action_List_NonTerminal[2]) (List_front_NonTerminal, List_front_NonTerminal);
  Bool skip_children_List_NonTerminal;
  List_front_Import (*action_List_Import[2]) (List_front_Import, List_front_Import);
  Bool skip_children_List_Import;
  List_front_NameSpace (*action_List_NameSpace[2]) (List_front_NameSpace, List_front_NameSpace);
  Bool skip_children_List_NameSpace;
  front_Scoping (*action_Scoping[2]) (front_Scoping, front_Scoping);
  Bool skip_children_Scoping;
  front_Scoping (*action_NewScope[2]) (front_Scoping, front_Scoping);
  Bool skip_children_NewScope;
  front_Scoping (*action_OpenScope[2]) (front_Scoping, front_Scoping);
  Bool skip_children_OpenScope;
  front_Scoping (*action_CloseScope[2]) (front_Scoping, front_Scoping);
  Bool skip_children_CloseScope;
  front_And (*action_And[2]) (front_And, front_And);
  Bool skip_children_And;
  front_And (*action_AndTranspose[2]) (front_And, front_And);
  Bool skip_children_AndTranspose;
  front_And (*action_AndLeft[2]) (front_And, front_And);
  Bool skip_children_AndLeft;
  front_And (*action_AndRight[2]) (front_And, front_And);
  Bool skip_children_AndRight;
  front_And (*action_AndCenter[2]) (front_And, front_And);
  Bool skip_children_AndCenter;
  front_Or (*action_Or[2]) (front_Or, front_Or);
  Bool skip_children_Or;
  front_Or (*action_OrCenter[2]) (front_Or, front_Or);
  Bool skip_children_OrCenter;
  front_Or (*action_OrLeft[2]) (front_Or, front_Or);
  Bool skip_children_OrLeft;
  front_Or (*action_OrRight[2]) (front_Or, front_Or);
  Bool skip_children_OrRight;
  front_Or (*action_OrTranspose[2]) (front_Or, front_Or);
  Bool skip_children_OrTranspose;
  front_Define (*action_Define[2]) (front_Define, front_Define);
  Bool skip_children_Define;
  front_Define (*action_Defining[2]) (front_Define, front_Define);
  Bool skip_children_Defining;
  front_Define (*action_Redefining[2]) (front_Define, front_Define);
  Bool skip_children_Redefining;
  front_Define (*action_Overloading[2]) (front_Define, front_Define);
  Bool skip_children_Overloading;
  front_Alternator (*action_Alternator[2]) (front_Alternator, front_Alternator);
  Bool skip_children_Alternator;
  front_NameOrField (*action_NameOrField[2]) (front_NameOrField, front_NameOrField);
  Bool skip_children_NameOrField;
  front_NameOrField (*action_AppliedName[2]) (front_NameOrField, front_NameOrField);
  Bool skip_children_AppliedName;
  front_NameOrField (*action_AppliedField[2]) (front_NameOrField, front_NameOrField);
  Bool skip_children_AppliedField;
} *copy_front_TraverseTable;

extern front_Scoping Traverse_copy_front_Scoping (front_Scoping me, copy_front_TraverseTable table);
#ifndef COPY_front_Scoping
#define COPY_front_Scoping(x) Traverse_copy_front_Scoping(x, &front_copy_actions)
#endif
extern front_And Traverse_copy_front_And (front_And me, copy_front_TraverseTable table);
#ifndef COPY_front_And
#define COPY_front_And(x) Traverse_copy_front_And(x, &front_copy_actions)
#endif
extern front_Or Traverse_copy_front_Or (front_Or me, copy_front_TraverseTable table);
#ifndef COPY_front_Or
#define COPY_front_Or(x) Traverse_copy_front_Or(x, &front_copy_actions)
#endif
extern front_Define Traverse_copy_front_Define (front_Define me, copy_front_TraverseTable table);
#ifndef COPY_front_Define
#define COPY_front_Define(x) Traverse_copy_front_Define(x, &front_copy_actions)
#endif
extern front_Alternator Traverse_copy_front_Alternator (front_Alternator me, copy_front_TraverseTable table);
#ifndef COPY_front_Alternator
#define COPY_front_Alternator(x) Traverse_copy_front_Alternator(x, &front_copy_actions)
#endif
extern front_NameOrField Traverse_copy_front_NameOrField (front_NameOrField me, copy_front_TraverseTable table);
#ifndef COPY_front_NameOrField
#define COPY_front_NameOrField(x) Traverse_copy_front_NameOrField(x, &front_copy_actions)
#endif
extern front_front Traverse_copy_front_front (front_front me, copy_front_TraverseTable table);
#ifndef COPY_front_front
#define COPY_front_front(x) Traverse_copy_front_front(x, &front_copy_actions)
#endif
extern front_Import Traverse_copy_front_Import (front_Import me, copy_front_TraverseTable table);
#ifndef COPY_front_Import
#define COPY_front_Import(x) Traverse_copy_front_Import(x, &front_copy_actions)
#endif
extern front_ImportedNonTerminal Traverse_copy_front_ImportedNonTerminal (front_ImportedNonTerminal me, copy_front_TraverseTable table);
#ifndef COPY_front_ImportedNonTerminal
#define COPY_front_ImportedNonTerminal(x) Traverse_copy_front_ImportedNonTerminal(x, &front_copy_actions)
#endif
extern front_NonTerminal Traverse_copy_front_NonTerminal (front_NonTerminal me, copy_front_TraverseTable table);
#ifndef COPY_front_NonTerminal
#define COPY_front_NonTerminal(x) Traverse_copy_front_NonTerminal(x, &front_copy_actions)
#endif
extern front_Super Traverse_copy_front_Super (front_Super me, copy_front_TraverseTable table);
#ifndef COPY_front_Super
#define COPY_front_Super(x) Traverse_copy_front_Super(x, &front_copy_actions)
#endif
extern front_Rhs Traverse_copy_front_Rhs (front_Rhs me, copy_front_TraverseTable table);
#ifndef COPY_front_Rhs
#define COPY_front_Rhs(x) Traverse_copy_front_Rhs(x, &front_copy_actions)
#endif
extern front_Alternative Traverse_copy_front_Alternative (front_Alternative me, copy_front_TraverseTable table);
#ifndef COPY_front_Alternative
#define COPY_front_Alternative(x) Traverse_copy_front_Alternative(x, &front_copy_actions)
#endif
extern front_Symbol Traverse_copy_front_Symbol (front_Symbol me, copy_front_TraverseTable table);
#ifndef COPY_front_Symbol
#define COPY_front_Symbol(x) Traverse_copy_front_Symbol(x, &front_copy_actions)
#endif
extern front_Defining_id Traverse_copy_front_Defining_id (front_Defining_id me, copy_front_TraverseTable table);
#ifndef COPY_front_Defining_id
#define COPY_front_Defining_id(x) Traverse_copy_front_Defining_id(x, &front_copy_actions)
#endif
extern front_Field Traverse_copy_front_Field (front_Field me, copy_front_TraverseTable table);
#ifndef COPY_front_Field
#define COPY_front_Field(x) Traverse_copy_front_Field(x, &front_copy_actions)
#endif
extern front_FieldInit Traverse_copy_front_FieldInit (front_FieldInit me, copy_front_TraverseTable table);
#ifndef COPY_front_FieldInit
#define COPY_front_FieldInit(x) Traverse_copy_front_FieldInit(x, &front_copy_actions)
#endif
extern front_Type Traverse_copy_front_Type (front_Type me, copy_front_TraverseTable table);
#ifndef COPY_front_Type
#define COPY_front_Type(x) Traverse_copy_front_Type(x, &front_copy_actions)
#endif
extern front_Expr Traverse_copy_front_Expr (front_Expr me, copy_front_TraverseTable table);
#ifndef COPY_front_Expr
#define COPY_front_Expr(x) Traverse_copy_front_Expr(x, &front_copy_actions)
#endif
extern front_Check Traverse_copy_front_Check (front_Check me, copy_front_TraverseTable table);
#ifndef COPY_front_Check
#define COPY_front_Check(x) Traverse_copy_front_Check(x, &front_copy_actions)
#endif
extern front_ScanInfo Traverse_copy_front_ScanInfo (front_ScanInfo me, copy_front_TraverseTable table);
#ifndef COPY_front_ScanInfo
#define COPY_front_ScanInfo(x) Traverse_copy_front_ScanInfo(x, &front_copy_actions)
#endif
extern front_Defines Traverse_copy_front_Defines (front_Defines me, copy_front_TraverseTable table);
#ifndef COPY_front_Defines
#define COPY_front_Defines(x) Traverse_copy_front_Defines(x, &front_copy_actions)
#endif
extern front_NameSpace Traverse_copy_front_NameSpace (front_NameSpace me, copy_front_TraverseTable table);
#ifndef COPY_front_NameSpace
#define COPY_front_NameSpace(x) Traverse_copy_front_NameSpace(x, &front_copy_actions)
#endif
extern front_dummy Traverse_copy_front_dummy (front_dummy me, copy_front_TraverseTable table);
#ifndef COPY_front_dummy
#define COPY_front_dummy(x) Traverse_copy_front_dummy(x, &front_copy_actions)
#endif
extern front_Scope Traverse_copy_front_Scope (front_Scope me, copy_front_TraverseTable table);
#ifndef COPY_front_Scope
#define COPY_front_Scope(x) Traverse_copy_front_Scope(x, &front_copy_actions)
#endif
extern List_List_front_Symbol Traverse_copy_List_List_front_Symbol (List_List_front_Symbol me, copy_front_TraverseTable table);
#ifndef COPY_front_List_List_Symbol
#define COPY_front_List_List_Symbol(x) Traverse_copy_List_List_front_Symbol(x, &front_copy_actions)
#endif
extern List_front_Expr Traverse_copy_List_front_Expr (List_front_Expr me, copy_front_TraverseTable table);
#ifndef COPY_front_List_Expr
#define COPY_front_List_Expr(x) Traverse_copy_List_front_Expr(x, &front_copy_actions)
#endif
extern List_front_Type Traverse_copy_List_front_Type (List_front_Type me, copy_front_TraverseTable table);
#ifndef COPY_front_List_Type
#define COPY_front_List_Type(x) Traverse_copy_List_front_Type(x, &front_copy_actions)
#endif
extern List_front_FieldInit Traverse_copy_List_front_FieldInit (List_front_FieldInit me, copy_front_TraverseTable table);
#ifndef COPY_front_List_FieldInit
#define COPY_front_List_FieldInit(x) Traverse_copy_List_front_FieldInit(x, &front_copy_actions)
#endif
extern List_front_And Traverse_copy_List_front_And (List_front_And me, copy_front_TraverseTable table);
#ifndef COPY_front_List_And
#define COPY_front_List_And(x) Traverse_copy_List_front_And(x, &front_copy_actions)
#endif
extern List_front_Field Traverse_copy_List_front_Field (List_front_Field me, copy_front_TraverseTable table);
#ifndef COPY_front_List_Field
#define COPY_front_List_Field(x) Traverse_copy_List_front_Field(x, &front_copy_actions)
#endif
extern List_front_Symbol Traverse_copy_List_front_Symbol (List_front_Symbol me, copy_front_TraverseTable table);
#ifndef COPY_front_List_Symbol
#define COPY_front_List_Symbol(x) Traverse_copy_List_front_Symbol(x, &front_copy_actions)
#endif
extern List_front_Check Traverse_copy_List_front_Check (List_front_Check me, copy_front_TraverseTable table);
#ifndef COPY_front_List_Check
#define COPY_front_List_Check(x) Traverse_copy_List_front_Check(x, &front_copy_actions)
#endif
extern List_front_Or Traverse_copy_List_front_Or (List_front_Or me, copy_front_TraverseTable table);
#ifndef COPY_front_List_Or
#define COPY_front_List_Or(x) Traverse_copy_List_front_Or(x, &front_copy_actions)
#endif
extern List_front_Alternative Traverse_copy_List_front_Alternative (List_front_Alternative me, copy_front_TraverseTable table);
#ifndef COPY_front_List_Alternative
#define COPY_front_List_Alternative(x) Traverse_copy_List_front_Alternative(x, &front_copy_actions)
#endif
extern List_front_Scoping Traverse_copy_List_front_Scoping (List_front_Scoping me, copy_front_TraverseTable table);
#ifndef COPY_front_List_Scoping
#define COPY_front_List_Scoping(x) Traverse_copy_List_front_Scoping(x, &front_copy_actions)
#endif
extern List_front_ImportedNonTerminal Traverse_copy_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal me, copy_front_TraverseTable table);
#ifndef COPY_front_List_ImportedNonTerminal
#define COPY_front_List_ImportedNonTerminal(x) Traverse_copy_List_front_ImportedNonTerminal(x, &front_copy_actions)
#endif
extern List_front_NonTerminal Traverse_copy_List_front_NonTerminal (List_front_NonTerminal me, copy_front_TraverseTable table);
#ifndef COPY_front_List_NonTerminal
#define COPY_front_List_NonTerminal(x) Traverse_copy_List_front_NonTerminal(x, &front_copy_actions)
#endif
extern List_front_Import Traverse_copy_List_front_Import (List_front_Import me, copy_front_TraverseTable table);
#ifndef COPY_front_List_Import
#define COPY_front_List_Import(x) Traverse_copy_List_front_Import(x, &front_copy_actions)
#endif
extern List_front_NameSpace Traverse_copy_List_front_NameSpace (List_front_NameSpace me, copy_front_TraverseTable table);
#ifndef COPY_front_List_NameSpace
#define COPY_front_List_NameSpace(x) Traverse_copy_List_front_NameSpace(x, &front_copy_actions)
#endif

typedef struct s_compare_front_TraverseTable {
  int (*action_front[2]) (front_front, front_front);
  Bool skip_children_front;
  int (*action_Import[2]) (front_Import, front_Import);
  Bool skip_children_Import;
  int (*action_ImportedNonTerminal[2]) (front_ImportedNonTerminal, front_ImportedNonTerminal);
  Bool skip_children_ImportedNonTerminal;
  int (*action_NonTerminal[2]) (front_NonTerminal, front_NonTerminal);
  Bool skip_children_NonTerminal;
  int (*action_Super[2]) (front_Super, front_Super);
  Bool skip_children_Super;
  int (*action_SubType[2]) (front_SubType, front_SubType);
  Bool skip_children_SubType;
  int (*action_NoType[2]) (front_NoType, front_NoType);
  Bool skip_children_NoType;
  int (*action_Rhs[2]) (front_Rhs, front_Rhs);
  Bool skip_children_Rhs;
  int (*action_Alternative[2]) (front_Alternative, front_Alternative);
  Bool skip_children_Alternative;
  int (*action_LabeledAlt[2]) (front_LabeledAlt, front_LabeledAlt);
  Bool skip_children_LabeledAlt;
  int (*action_UnLabeledAlt[2]) (front_UnLabeledAlt, front_UnLabeledAlt);
  Bool skip_children_UnLabeledAlt;
  int (*action_Symbol[2]) (front_Symbol, front_Symbol);
  Bool skip_children_Symbol;
  int (*action_LabeledSym[2]) (front_LabeledSym, front_LabeledSym);
  Bool skip_children_LabeledSym;
  int (*action_AltSymbol[2]) (front_AltSymbol, front_AltSymbol);
  Bool skip_children_AltSymbol;
  int (*action_SymbolSeq[2]) (front_SymbolSeq, front_SymbolSeq);
  Bool skip_children_SymbolSeq;
  int (*action_Symbol2[2]) (front_Symbol2, front_Symbol2);
  Bool skip_children_Symbol2;
  int (*action_CompareSym[2]) (front_CompareSym, front_CompareSym);
  Bool skip_children_CompareSym;
  int (*action_SimpleSymbol[2]) (front_SimpleSymbol, front_SimpleSymbol);
  Bool skip_children_SimpleSymbol;
  int (*action_AppliedSym[2]) (front_AppliedSym, front_AppliedSym);
  Bool skip_children_AppliedSym;
  int (*action_StringSymbol[2]) (front_StringSymbol, front_StringSymbol);
  Bool skip_children_StringSymbol;
  int (*action_CharSymbol[2]) (front_CharSymbol, front_CharSymbol);
  Bool skip_children_CharSymbol;
  int (*action_KeywordSymbol[2]) (front_KeywordSymbol, front_KeywordSymbol);
  Bool skip_children_KeywordSymbol;
  int (*action_CompoundSym[2]) (front_CompoundSym, front_CompoundSym);
  Bool skip_children_CompoundSym;
  int (*action_OnceSymbol[2]) (front_OnceSymbol, front_OnceSymbol);
  Bool skip_children_OnceSymbol;
  int (*action_OptSymbol[2]) (front_OptSymbol, front_OptSymbol);
  Bool skip_children_OptSymbol;
  int (*action_OptMoreSymbol[2]) (front_OptMoreSymbol, front_OptMoreSymbol);
  Bool skip_children_OptMoreSymbol;
  int (*action_MoreSymbol[2]) (front_MoreSymbol, front_MoreSymbol);
  Bool skip_children_MoreSymbol;
  int (*action_EmptySym[2]) (front_EmptySym, front_EmptySym);
  Bool skip_children_EmptySym;
  int (*action_LayoutString[2]) (front_LayoutString, front_LayoutString);
  Bool skip_children_LayoutString;
  int (*action_LayoutAction[2]) (front_LayoutAction, front_LayoutAction);
  Bool skip_children_LayoutAction;
  int (*action_IdSym[2]) (front_IdSym, front_IdSym);
  Bool skip_children_IdSym;
  int (*action_DefiningSym[2]) (front_DefiningSym, front_DefiningSym);
  Bool skip_children_DefiningSym;
  int (*action_Defining_id[2]) (front_Defining_id, front_Defining_id);
  Bool skip_children_Defining_id;
  int (*action_DefId[2]) (front_DefId, front_DefId);
  Bool skip_children_DefId;
  int (*action_DefExpr[2]) (front_DefExpr, front_DefExpr);
  Bool skip_children_DefExpr;
  int (*action_Field[2]) (front_Field, front_Field);
  Bool skip_children_Field;
  int (*action_FieldInit[2]) (front_FieldInit, front_FieldInit);
  Bool skip_children_FieldInit;
  int (*action_WhenCreate[2]) (front_WhenCreate, front_WhenCreate);
  Bool skip_children_WhenCreate;
  int (*action_WhenScope[2]) (front_WhenScope, front_WhenScope);
  Bool skip_children_WhenScope;
  int (*action_WhenDefining[2]) (front_WhenDefining, front_WhenDefining);
  Bool skip_children_WhenDefining;
  int (*action_WhenApplied[2]) (front_WhenApplied, front_WhenApplied);
  Bool skip_children_WhenApplied;
  int (*action_WhenChecks[2]) (front_WhenChecks, front_WhenChecks);
  Bool skip_children_WhenChecks;
  int (*action_Type[2]) (front_Type, front_Type);
  Bool skip_children_Type;
  int (*action_Expr[2]) (front_Expr, front_Expr);
  Bool skip_children_Expr;
  int (*action_BinExpr[2]) (front_BinExpr, front_BinExpr);
  Bool skip_children_BinExpr;
  int (*action_MonExpr1[2]) (front_MonExpr1, front_MonExpr1);
  Bool skip_children_MonExpr1;
  int (*action_MonExpr[2]) (front_MonExpr, front_MonExpr);
  Bool skip_children_MonExpr;
  int (*action_SimpleExpr[2]) (front_SimpleExpr, front_SimpleExpr);
  Bool skip_children_SimpleExpr;
  int (*action_IdentExpr[2]) (front_IdentExpr, front_IdentExpr);
  Bool skip_children_IdentExpr;
  int (*action_QualExpr[2]) (front_QualExpr, front_QualExpr);
  Bool skip_children_QualExpr;
  int (*action_IntExpr[2]) (front_IntExpr, front_IntExpr);
  Bool skip_children_IntExpr;
  int (*action_BoolExpr[2]) (front_BoolExpr, front_BoolExpr);
  Bool skip_children_BoolExpr;
  int (*action_StringExpr[2]) (front_StringExpr, front_StringExpr);
  Bool skip_children_StringExpr;
  int (*action_NilExpr[2]) (front_NilExpr, front_NilExpr);
  Bool skip_children_NilExpr;
  int (*action_CallExpr[2]) (front_CallExpr, front_CallExpr);
  Bool skip_children_CallExpr;
  int (*action_Check[2]) (front_Check, front_Check);
  Bool skip_children_Check;
  int (*action_ScanInfo[2]) (front_ScanInfo, front_ScanInfo);
  Bool skip_children_ScanInfo;
  int (*action_Defines[2]) (front_Defines, front_Defines);
  Bool skip_children_Defines;
  int (*action_PlainDef[2]) (front_PlainDef, front_PlainDef);
  Bool skip_children_PlainDef;
  int (*action_MacroDef[2]) (front_MacroDef, front_MacroDef);
  Bool skip_children_MacroDef;
  int (*action_NameSpace[2]) (front_NameSpace, front_NameSpace);
  Bool skip_children_NameSpace;
  int (*action_dummy[2]) (front_dummy, front_dummy);
  Bool skip_children_dummy;
  int (*action_Scope[2]) (front_Scope, front_Scope);
  Bool skip_children_Scope;
  int (*action_NonTerminalScope[2]) (front_NonTerminalScope, front_NonTerminalScope);
  Bool skip_children_NonTerminalScope;
  int (*action_List_List_Symbol[2]) (List_List_front_Symbol, List_List_front_Symbol);
  Bool skip_children_List_List_Symbol;
  int (*action_List_Expr[2]) (List_front_Expr, List_front_Expr);
  Bool skip_children_List_Expr;
  int (*action_List_Type[2]) (List_front_Type, List_front_Type);
  Bool skip_children_List_Type;
  int (*action_List_FieldInit[2]) (List_front_FieldInit, List_front_FieldInit);
  Bool skip_children_List_FieldInit;
  int (*action_List_And[2]) (List_front_And, List_front_And);
  Bool skip_children_List_And;
  int (*action_List_Field[2]) (List_front_Field, List_front_Field);
  Bool skip_children_List_Field;
  int (*action_List_Symbol[2]) (List_front_Symbol, List_front_Symbol);
  Bool skip_children_List_Symbol;
  int (*action_List_Check[2]) (List_front_Check, List_front_Check);
  Bool skip_children_List_Check;
  int (*action_List_Or[2]) (List_front_Or, List_front_Or);
  Bool skip_children_List_Or;
  int (*action_List_Alternative[2]) (List_front_Alternative, List_front_Alternative);
  Bool skip_children_List_Alternative;
  int (*action_List_Scoping[2]) (List_front_Scoping, List_front_Scoping);
  Bool skip_children_List_Scoping;
  int (*action_List_ImportedNonTerminal[2]) (List_front_ImportedNonTerminal, List_front_ImportedNonTerminal);
  Bool skip_children_List_ImportedNonTerminal;
  int (*action_List_NonTerminal[2]) (List_front_NonTerminal, List_front_NonTerminal);
  Bool skip_children_List_NonTerminal;
  int (*action_List_Import[2]) (List_front_Import, List_front_Import);
  Bool skip_children_List_Import;
  int (*action_List_NameSpace[2]) (List_front_NameSpace, List_front_NameSpace);
  Bool skip_children_List_NameSpace;
  int (*action_Scoping[2]) (front_Scoping, front_Scoping);
  Bool skip_children_Scoping;
  int (*action_NewScope[2]) (front_Scoping, front_Scoping);
  Bool skip_children_NewScope;
  int (*action_OpenScope[2]) (front_Scoping, front_Scoping);
  Bool skip_children_OpenScope;
  int (*action_CloseScope[2]) (front_Scoping, front_Scoping);
  Bool skip_children_CloseScope;
  int (*action_And[2]) (front_And, front_And);
  Bool skip_children_And;
  int (*action_AndTranspose[2]) (front_And, front_And);
  Bool skip_children_AndTranspose;
  int (*action_AndLeft[2]) (front_And, front_And);
  Bool skip_children_AndLeft;
  int (*action_AndRight[2]) (front_And, front_And);
  Bool skip_children_AndRight;
  int (*action_AndCenter[2]) (front_And, front_And);
  Bool skip_children_AndCenter;
  int (*action_Or[2]) (front_Or, front_Or);
  Bool skip_children_Or;
  int (*action_OrCenter[2]) (front_Or, front_Or);
  Bool skip_children_OrCenter;
  int (*action_OrLeft[2]) (front_Or, front_Or);
  Bool skip_children_OrLeft;
  int (*action_OrRight[2]) (front_Or, front_Or);
  Bool skip_children_OrRight;
  int (*action_OrTranspose[2]) (front_Or, front_Or);
  Bool skip_children_OrTranspose;
  int (*action_Define[2]) (front_Define, front_Define);
  Bool skip_children_Define;
  int (*action_Defining[2]) (front_Define, front_Define);
  Bool skip_children_Defining;
  int (*action_Redefining[2]) (front_Define, front_Define);
  Bool skip_children_Redefining;
  int (*action_Overloading[2]) (front_Define, front_Define);
  Bool skip_children_Overloading;
  int (*action_Alternator[2]) (front_Alternator, front_Alternator);
  Bool skip_children_Alternator;
  int (*action_NameOrField[2]) (front_NameOrField, front_NameOrField);
  Bool skip_children_NameOrField;
  int (*action_AppliedName[2]) (front_NameOrField, front_NameOrField);
  Bool skip_children_AppliedName;
  int (*action_AppliedField[2]) (front_NameOrField, front_NameOrField);
  Bool skip_children_AppliedField;
} *compare_front_TraverseTable;

extern int Traverse_compare_front_Scoping (front_Scoping x, front_Scoping y, compare_front_TraverseTable table);
extern int Traverse_compare_front_And (front_And x, front_And y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Or (front_Or x, front_Or y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Define (front_Define x, front_Define y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Alternator (front_Alternator x, front_Alternator y, compare_front_TraverseTable table);
extern int Traverse_compare_front_NameOrField (front_NameOrField x, front_NameOrField y, compare_front_TraverseTable table);
extern int Traverse_compare_front_front (front_front x, front_front y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Import (front_Import x, front_Import y, compare_front_TraverseTable table);
extern int Traverse_compare_front_ImportedNonTerminal (front_ImportedNonTerminal x, front_ImportedNonTerminal y, compare_front_TraverseTable table);
extern int Traverse_compare_front_NonTerminal (front_NonTerminal x, front_NonTerminal y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Super (front_Super x, front_Super y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Rhs (front_Rhs x, front_Rhs y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Alternative (front_Alternative x, front_Alternative y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Symbol (front_Symbol x, front_Symbol y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Defining_id (front_Defining_id x, front_Defining_id y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Field (front_Field x, front_Field y, compare_front_TraverseTable table);
extern int Traverse_compare_front_FieldInit (front_FieldInit x, front_FieldInit y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Type (front_Type x, front_Type y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Expr (front_Expr x, front_Expr y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Check (front_Check x, front_Check y, compare_front_TraverseTable table);
extern int Traverse_compare_front_ScanInfo (front_ScanInfo x, front_ScanInfo y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Defines (front_Defines x, front_Defines y, compare_front_TraverseTable table);
extern int Traverse_compare_front_NameSpace (front_NameSpace x, front_NameSpace y, compare_front_TraverseTable table);
extern int Traverse_compare_front_dummy (front_dummy x, front_dummy y, compare_front_TraverseTable table);
extern int Traverse_compare_front_Scope (front_Scope x, front_Scope y, compare_front_TraverseTable table);
extern int Traverse_compare_List_List_front_Symbol (List_List_front_Symbol x, List_List_front_Symbol y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_Expr (List_front_Expr x, List_front_Expr y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_Type (List_front_Type x, List_front_Type y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_FieldInit (List_front_FieldInit x, List_front_FieldInit y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_And (List_front_And x, List_front_And y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_Field (List_front_Field x, List_front_Field y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_Symbol (List_front_Symbol x, List_front_Symbol y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_Check (List_front_Check x, List_front_Check y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_Or (List_front_Or x, List_front_Or y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_Alternative (List_front_Alternative x, List_front_Alternative y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_Scoping (List_front_Scoping x, List_front_Scoping y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal x, List_front_ImportedNonTerminal y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_NonTerminal (List_front_NonTerminal x, List_front_NonTerminal y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_Import (List_front_Import x, List_front_Import y, compare_front_TraverseTable table);
extern int Traverse_compare_List_front_NameSpace (List_front_NameSpace x, List_front_NameSpace y, compare_front_TraverseTable table);


extern void front_fill_table (front_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void void_front_fill_table (void_front_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void copy_front_fill_table (copy_front_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void compare_front_fill_table (compare_front_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern struct s_front_TraverseTable front_scope_actions;

extern struct s_void_front_TraverseTable front_defining_actions;

extern struct s_void_front_TraverseTable front_applied_actions;

extern struct s_void_front_TraverseTable front_check_actions;

extern struct s_void_front_TraverseTable front_print_actions;

extern struct s_copy_front_TraverseTable front_copy_actions;

extern struct s_compare_front_TraverseTable front_compare_actions;

typedef int front_NameSpaces;

extern front_NameSpaces front_namespaces[1];

#define front_DefaultNameSpace front_namespaces[0]

#define front_NUM_NAMESPACES 1

extern void Decorate_front (front_front r);

#endif /* _front */
