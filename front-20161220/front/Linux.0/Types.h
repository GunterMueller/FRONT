#ifndef _Types
#define _Types

#include <stdarg.h>
#include <stddef.h>
#include <front/basic_types.h>

typedef enum {
  Types_plain_macro_kind,
  Types_access_macro_kind
} Types_macro_tag;
extern char *Types_macro_tag_names[];
#define NUM_Types_macro_tag 2

typedef enum {
  Types_struct_typeScope_kind
} Types_Scope_tag;
extern char *Types_Scope_tag_names[];
#define NUM_Types_Scope_tag 1

#ifndef DEF_TYPE_Types_Types
#define DEF_TYPE_Types_Types
typedef struct s_Types_Types    *Types_Types;
#endif

#ifndef DEF_TYPE_Types_includes2
#define DEF_TYPE_Types_includes2
typedef struct s_Types_includes2        *Types_includes2;
#endif

#ifndef DEF_TYPE_Types_EnumType
#define DEF_TYPE_Types_EnumType
typedef struct s_Types_EnumType *Types_EnumType;
#endif

#ifndef DEF_TYPE_Types_BindType
#define DEF_TYPE_Types_BindType
typedef struct s_Types_BindType *Types_BindType;
#endif

#ifndef DEF_TYPE_Types_PointerType
#define DEF_TYPE_Types_PointerType
typedef struct s_Types_PointerType      *Types_PointerType;
#endif

#ifndef DEF_TYPE_Types_subtypedef
#define DEF_TYPE_Types_subtypedef
typedef struct s_Types_subtypedef       *Types_subtypedef;
#endif

#ifndef DEF_TYPE_Types_StructType
#define DEF_TYPE_Types_StructType
typedef struct s_Types_StructType       *Types_StructType;
#endif

#ifndef DEF_TYPE_Types_struct_type
#define DEF_TYPE_Types_struct_type
typedef struct s_Types_struct_type      *Types_struct_type;
#endif

#ifndef DEF_TYPE_Types_macro
#define DEF_TYPE_Types_macro
typedef struct s_Types_macro    *Types_macro;
typedef Types_macro Types_access_macro;
typedef Types_macro Types_plain_macro;
#endif

#ifndef DEF_TYPE_Types_field
#define DEF_TYPE_Types_field
typedef struct s_Types_field    *Types_field;
#endif

#ifndef DEF_TYPE_Types_TypeName
#define DEF_TYPE_Types_TypeName
typedef struct s_Types_TypeName *Types_TypeName;
#endif

#ifndef DEF_TYPE_Types_CreateFunction
#define DEF_TYPE_Types_CreateFunction
typedef struct s_Types_CreateFunction   *Types_CreateFunction;
#endif

#ifndef DEF_TYPE_Types_Scope
#define DEF_TYPE_Types_Scope
typedef struct s_Types_Scope    *Types_Scope;
typedef Types_Scope Types_struct_typeScope;
#endif

#ifndef DEF_TYPE_List_Types_struct_type
#define DEF_TYPE_List_Types_struct_type
typedef struct s_List_Types_struct_type *List_Types_struct_type;
#endif

#ifndef DEF_TYPE_List_Types_field
#define DEF_TYPE_List_Types_field
typedef struct s_List_Types_field       *List_Types_field;
#endif

#ifndef DEF_TYPE_List_Types_CreateFunction
#define DEF_TYPE_List_Types_CreateFunction
typedef struct s_List_Types_CreateFunction      *List_Types_CreateFunction;
#endif

#ifndef DEF_TYPE_List_Types_macro
#define DEF_TYPE_List_Types_macro
typedef struct s_List_Types_macro       *List_Types_macro;
#endif

#ifndef DEF_TYPE_List_Types_TypeName
#define DEF_TYPE_List_Types_TypeName
typedef struct s_List_Types_TypeName    *List_Types_TypeName;
#endif

#ifndef DEF_TYPE_List_Types_StructType
#define DEF_TYPE_List_Types_StructType
typedef struct s_List_Types_StructType  *List_Types_StructType;
#endif

#ifndef DEF_TYPE_List_Types_BindType
#define DEF_TYPE_List_Types_BindType
typedef struct s_List_Types_BindType    *List_Types_BindType;
#endif

#ifndef DEF_TYPE_List_Types_subtypedef
#define DEF_TYPE_List_Types_subtypedef
typedef struct s_List_Types_subtypedef  *List_Types_subtypedef;
#endif

#ifndef DEF_TYPE_List_Types_PointerType
#define DEF_TYPE_List_Types_PointerType
typedef struct s_List_Types_PointerType *List_Types_PointerType;
#endif

#ifndef DEF_TYPE_List_Types_EnumType
#define DEF_TYPE_List_Types_EnumType
typedef struct s_List_Types_EnumType    *List_Types_EnumType;
#endif

#include <front/scan_support.h>
#include <front/print_support.h>
#include <front/SymTab.h>
#include "Types_parse.h"
#include "Types_defs.h"

#include "front.h"
#include "GenTypes.h"
typedef Bind Bind_Types_struct_type;
typedef List_Bind List_Bind_Types_struct_type;
#define List_Bind_Types_struct_type_data(x) (Bind_Types_struct_type)Front_List_data((Front_List)(x))
#define List_Bind_Types_struct_type_next(x) (List_Bind_Types_struct_type)Front_List_next((Front_List)(x))
#define Bind_Types_struct_type_kind 0

extern Types_Types Types_root;

#ifndef DEF_STRUCT_Types_Types
#define DEF_STRUCT_Types_Types

struct s_Types_Types {
  SrcInfo       src_info;  
  List_Types_EnumType   enums;  
  List_Types_PointerType        pointers;  
  List_Types_subtypedef subs;  
  Types_includes2       inc2;  
  List_Types_subtypedef impdefs;  
  List_Types_BindType   binds;  
  Ident r1;  
  Ident r2;  
  List_Types_StructType types;  
} ;

#define Types_Types_src_info(_p)        ((*_p).src_info)
#define Types_Types_srcinfo(_p) ((*_p).src_info)
#define Types_Types_loc(_p)     ((*_p).src_info->loc)
#define Types_Types_enums(_p)   ((*_p).enums)
#define Types_Types_pointers(_p)        ((*_p).pointers)
#define Types_Types_subs(_p)    ((*_p).subs)
#define Types_Types_inc2(_p)    ((*_p).inc2)
#define Types_Types_impdefs(_p) ((*_p).impdefs)
#define Types_Types_binds(_p)   ((*_p).binds)
#define Types_Types_r1(_p)      ((*_p).r1)
#define Types_Types_r2(_p)      ((*_p).r2)
#define Types_Types_types(_p)   ((*_p).types)

extern Types_Types Create_Types_Types	(SrcInfo src_info, List_Types_EnumType enums, List_Types_PointerType pointers, List_Types_subtypedef subs, Types_includes2 inc2, List_Types_subtypedef impdefs, List_Types_BindType binds, Ident r1, Ident r2, List_Types_StructType types);

#endif /* DEF_STRUCT_Types_Types */

#ifndef DEF_STRUCT_Types_includes2
#define DEF_STRUCT_Types_includes2

struct s_Types_includes2 {
  SrcInfo       src_info;  
  Ident id1;  
  Ident id2;  
  List_Ident    uses;  
} ;

#define Types_includes2_src_info(_p)    ((*_p).src_info)
#define Types_includes2_srcinfo(_p)     ((*_p).src_info)
#define Types_includes2_loc(_p) ((*_p).src_info->loc)
#define Types_includes2_id1(_p) ((*_p).id1)
#define Types_includes2_id2(_p) ((*_p).id2)
#define Types_includes2_uses(_p)        ((*_p).uses)

extern Types_includes2 Create_Types_includes2	(SrcInfo src_info, Ident id1, Ident id2, List_Ident uses);

#endif /* DEF_STRUCT_Types_includes2 */

#ifndef DEF_STRUCT_Types_EnumType
#define DEF_STRUCT_Types_EnumType

struct s_Types_EnumType {
  SrcInfo       src_info;  
  List_Types_TypeName   enums;  
  Ident id;  
  Ident str;  
  Ident tag;  
  Int   num;  
  Bool  is_tag;  
  Types_struct_type     str_type;  
  Ident name;  
  
} ;

#define Types_EnumType_src_info(_p)     ((*_p).src_info)
#define Types_EnumType_srcinfo(_p)      ((*_p).src_info)
#define Types_EnumType_loc(_p)  ((*_p).src_info->loc)
#define Types_EnumType_enums(_p)        ((*_p).enums)
#define Types_EnumType_id(_p)   ((*_p).id)
#define Types_EnumType_str(_p)  ((*_p).str)
#define Types_EnumType_tag(_p)  ((*_p).tag)
#define Types_EnumType_num(_p)  ((*_p).num)
#define Types_EnumType_is_tag(_p)       ((*_p).is_tag)
#define Types_EnumType_str_type(_p)     ((*_p).str_type)
#define Types_EnumType_name(_p) ((*_p).name)
#define Types_EnumType_xxx(_p)  ((*_p).xxx)

extern Types_EnumType Create_Types_EnumType	(SrcInfo src_info, List_Types_TypeName enums, Ident id, Ident str, Ident tag, Int num);

#endif /* DEF_STRUCT_Types_EnumType */

#ifndef DEF_STRUCT_Types_BindType
#define DEF_STRUCT_Types_BindType

struct s_Types_BindType {
  SrcInfo       src_info;  
  Ident id1;  
  Ident id2;  
  Ident id3;  
  Ident id4;  
  Ident id5;  
  Ident id6;  
  Ident id7;  
  Int   num;  
  Ident abbrev;  
} ;

#define Types_BindType_src_info(_p)     ((*_p).src_info)
#define Types_BindType_srcinfo(_p)      ((*_p).src_info)
#define Types_BindType_loc(_p)  ((*_p).src_info->loc)
#define Types_BindType_id1(_p)  ((*_p).id1)
#define Types_BindType_id2(_p)  ((*_p).id2)
#define Types_BindType_id3(_p)  ((*_p).id3)
#define Types_BindType_id4(_p)  ((*_p).id4)
#define Types_BindType_id5(_p)  ((*_p).id5)
#define Types_BindType_id6(_p)  ((*_p).id6)
#define Types_BindType_id7(_p)  ((*_p).id7)
#define Types_BindType_num(_p)  ((*_p).num)
#define Types_BindType_abbrev(_p)       ((*_p).abbrev)

extern Types_BindType Create_Types_BindType	(SrcInfo src_info, Ident id1, Ident id2, Ident id3, Ident id4, Ident id5, Ident id6, Ident id7, Int num);

#endif /* DEF_STRUCT_Types_BindType */

#ifndef DEF_STRUCT_Types_PointerType
#define DEF_STRUCT_Types_PointerType

struct s_Types_PointerType {
  SrcInfo       src_info;  
  Ident id1;  
  Ident id2;  
  Ident id3;  
  Ident id;  
  List_Types_subtypedef subs;  
} ;

#define Types_PointerType_src_info(_p)  ((*_p).src_info)
#define Types_PointerType_srcinfo(_p)   ((*_p).src_info)
#define Types_PointerType_loc(_p)       ((*_p).src_info->loc)
#define Types_PointerType_id1(_p)       ((*_p).id1)
#define Types_PointerType_id2(_p)       ((*_p).id2)
#define Types_PointerType_id3(_p)       ((*_p).id3)
#define Types_PointerType_id(_p)        ((*_p).id)
#define Types_PointerType_subs(_p)      ((*_p).subs)

extern Types_PointerType Create_Types_PointerType	(SrcInfo src_info, Ident id1, Ident id2, Ident id3, Ident id, List_Types_subtypedef subs);

#endif /* DEF_STRUCT_Types_PointerType */

#ifndef DEF_STRUCT_Types_subtypedef
#define DEF_STRUCT_Types_subtypedef

struct s_Types_subtypedef {
  SrcInfo       src_info;  
  Ident super;  
  Ident id;  
} ;

#define Types_subtypedef_src_info(_p)   ((*_p).src_info)
#define Types_subtypedef_srcinfo(_p)    ((*_p).src_info)
#define Types_subtypedef_loc(_p)        ((*_p).src_info->loc)
#define Types_subtypedef_super(_p)      ((*_p).super)
#define Types_subtypedef_id(_p) ((*_p).id)

extern Types_subtypedef Create_Types_subtypedef	(SrcInfo src_info, Ident super, Ident id);

#endif /* DEF_STRUCT_Types_subtypedef */

#ifndef DEF_STRUCT_Types_StructType
#define DEF_STRUCT_Types_StructType

struct s_Types_StructType {
  SrcInfo       src_info;  
  Ident id1;  
  Ident id2;  
  Types_struct_type     type;  
  List_Types_macro      macros;  
  List_Types_CreateFunction     creates;  
  Ident id3;  
} ;

#define Types_StructType_src_info(_p)   ((*_p).src_info)
#define Types_StructType_srcinfo(_p)    ((*_p).src_info)
#define Types_StructType_loc(_p)        ((*_p).src_info->loc)
#define Types_StructType_id1(_p)        ((*_p).id1)
#define Types_StructType_id2(_p)        ((*_p).id2)
#define Types_StructType_type(_p)       ((*_p).type)
#define Types_StructType_macros(_p)     ((*_p).macros)
#define Types_StructType_creates(_p)    ((*_p).creates)
#define Types_StructType_id3(_p)        ((*_p).id3)

extern Types_StructType Create_Types_StructType	(SrcInfo src_info, Ident id1, Ident id2, Types_struct_type type, List_Types_macro macros, List_Types_CreateFunction creates, Ident id3);

#endif /* DEF_STRUCT_Types_StructType */

#ifndef DEF_STRUCT_Types_struct_type
#define DEF_STRUCT_Types_struct_type

struct s_Types_struct_type {
  SrcInfo       src_info;  
  Int   _num;  
  Types_Scope   scope;  
  Types_Scope   old_scope;  
  Ident tag;  
  Bind_Types_struct_type        tag_bind;  
  Ident user;  
  List_Types_field      fields1;  
  List_Types_struct_type        sub_types;  
  List_Types_field      fields2;  
  Ident id;  
  Ident name;  
  List_Check    checks;  
  Bool  is_list;  
  Bool  is_bind;  
  Bool  is_optional;  
  Bool  is_scope;  
  Bool  uses_scope;  
  Bool  opens_scope;  
  Bool  closes_scope;  
  Bool  in_lib;  
  Alternative   alt;  
  Types_CreateFunction  create;  
  Types_EnumType        enumtype;  
  
} ;

#define Types_struct_type_src_info(_p)  ((*_p).src_info)
#define Types_struct_type_srcinfo(_p)   ((*_p).src_info)
#define Types_struct_type_loc(_p)       ((*_p).src_info->loc)
#define Types_struct_type__num(_p)      ((*_p)._num)
#define Types_struct_type_scope(_p)     ((*_p).scope)
#define Types_struct_type_old_scope(_p) ((*_p).old_scope)
#define Types_struct_type_tag(_p)       ((*_p).tag)
#define Types_struct_type_tag_bind(_p)  ((*_p).tag_bind)
#define Types_struct_type_user(_p)      ((*_p).user)
#define Types_struct_type_fields1(_p)   ((*_p).fields1)
#define Types_struct_type_sub_types(_p) ((*_p).sub_types)
#define Types_struct_type_fields2(_p)   ((*_p).fields2)
#define Types_struct_type_id(_p)        ((*_p).id)
#define Types_struct_type_name(_p)      ((*_p).name)
#define Types_struct_type_checks(_p)    ((*_p).checks)
#define Types_struct_type_is_list(_p)   ((*_p).is_list)
#define Types_struct_type_is_bind(_p)   ((*_p).is_bind)
#define Types_struct_type_is_optional(_p)       ((*_p).is_optional)
#define Types_struct_type_is_scope(_p)  ((*_p).is_scope)
#define Types_struct_type_uses_scope(_p)        ((*_p).uses_scope)
#define Types_struct_type_opens_scope(_p)       ((*_p).opens_scope)
#define Types_struct_type_closes_scope(_p)      ((*_p).closes_scope)
#define Types_struct_type_in_lib(_p)    ((*_p).in_lib)
#define Types_struct_type_alt(_p)       ((*_p).alt)
#define Types_struct_type_create(_p)    ((*_p).create)
#define Types_struct_type_enumtype(_p)  ((*_p).enumtype)
#define Types_struct_type_xxx(_p)       ((*_p).xxx)

extern Types_struct_type Create_Types_struct_type	(SrcInfo src_info, Ident tag, Ident user, List_Types_field fields1, List_Types_struct_type sub_types, List_Types_field fields2, Ident id);

#endif /* DEF_STRUCT_Types_struct_type */

#ifndef DEF_STRUCT_Types_macro
#define DEF_STRUCT_Types_macro

struct s_Types_macro {
  SrcInfo       src_info;  
  Types_macro_tag       tag;  
  Ident type;  
  Ident id;  
  union {
  struct s_Types_plain_macro {
  } Types_plain_macro;
  struct s_Types_access_macro {
    Ident       r;  
  } Types_access_macro;
} sub;
  List_Ident    types;  
  Ident f;  
} ;

#define Types_macro_src_info(_p)        ((*_p).src_info)
#define Types_macro_srcinfo(_p) ((*_p).src_info)
#define Types_macro_loc(_p)     ((*_p).src_info->loc)
#define Types_macro_tag(_p)     ((*_p).tag)
#define Types_macro_type(_p)    ((*_p).type)
#define Types_macro_id(_p)      ((*_p).id)
#define Types_access_macro_r(_p)        ((*_p).sub.Types_access_macro.r)
#define Types_macro_types(_p)   ((*_p).types)
#define Types_macro_f(_p)       ((*_p).f)

extern Types_access_macro Create_Types_access_macro	(SrcInfo src_info, Ident type, Ident id, Ident r, List_Ident types, Ident f);
extern Types_plain_macro Create_Types_plain_macro	(SrcInfo src_info, Ident type, Ident id, List_Ident types, Ident f);

#endif /* DEF_STRUCT_Types_macro */

#ifndef DEF_STRUCT_Types_field
#define DEF_STRUCT_Types_field

struct s_Types_field {
  SrcInfo       src_info;  
  List_Types_TypeName   type;  
  Ident id;  
  Ident grammar_id;  
  Bool  uses_scope;  
  Symbol        is_defining;  
  Symbol        is_applied;  
  Ident applied_id;  
  Bool  is_tag;  
  List_FieldInit        init;  
  Bool  trav;  
  Bool  clear;  
  Bool  dont_clear;  
  Ident compare;  
} ;

#define Types_field_src_info(_p)        ((*_p).src_info)
#define Types_field_srcinfo(_p) ((*_p).src_info)
#define Types_field_loc(_p)     ((*_p).src_info->loc)
#define Types_field_type(_p)    ((*_p).type)
#define Types_field_id(_p)      ((*_p).id)
#define Types_field_grammar_id(_p)      ((*_p).grammar_id)
#define Types_field_uses_scope(_p)      ((*_p).uses_scope)
#define Types_field_is_defining(_p)     ((*_p).is_defining)
#define Types_field_is_applied(_p)      ((*_p).is_applied)
#define Types_field_applied_id(_p)      ((*_p).applied_id)
#define Types_field_is_tag(_p)  ((*_p).is_tag)
#define Types_field_init(_p)    ((*_p).init)
#define Types_field_trav(_p)    ((*_p).trav)
#define Types_field_clear(_p)   ((*_p).clear)
#define Types_field_dont_clear(_p)      ((*_p).dont_clear)
#define Types_field_compare(_p) ((*_p).compare)

extern Types_field Create_Types_field	(SrcInfo src_info, List_Types_TypeName type, Ident id);

#endif /* DEF_STRUCT_Types_field */

#ifndef DEF_STRUCT_Types_TypeName
#define DEF_STRUCT_Types_TypeName

struct s_Types_TypeName {
  SrcInfo       src_info;  
  Int   _num;  
  Types_Scope   scope;  
  Types_Scope   old_scope;  
  Ident full;  
  Bind_Types_struct_type        type_bind;  
  Types_struct_type     type;  
  Ident id;  
} ;

#define Types_TypeName_src_info(_p)     ((*_p).src_info)
#define Types_TypeName_srcinfo(_p)      ((*_p).src_info)
#define Types_TypeName_loc(_p)  ((*_p).src_info->loc)
#define Types_TypeName__num(_p) ((*_p)._num)
#define Types_TypeName_scope(_p)        ((*_p).scope)
#define Types_TypeName_old_scope(_p)    ((*_p).old_scope)
#define Types_TypeName_full(_p) ((*_p).full)
#define Types_TypeName_type_bind(_p)    ((*_p).type_bind)
#define Types_TypeName_type(_p) ((*_p).type)
#define Types_TypeName_id(_p)   ((*_p).id)

extern Types_TypeName Create_Types_TypeName	(SrcInfo src_info, Ident full);

#endif /* DEF_STRUCT_Types_TypeName */

#ifndef DEF_STRUCT_Types_CreateFunction
#define DEF_STRUCT_Types_CreateFunction

struct s_Types_CreateFunction {
  SrcInfo       src_info;  
  List_Types_field      fields;  
  Types_struct_type     type;  
} ;

#define Types_CreateFunction_src_info(_p)       ((*_p).src_info)
#define Types_CreateFunction_srcinfo(_p)        ((*_p).src_info)
#define Types_CreateFunction_loc(_p)    ((*_p).src_info->loc)
#define Types_CreateFunction_fields(_p) ((*_p).fields)
#define Types_CreateFunction_type(_p)   ((*_p).type)

extern Types_CreateFunction Create_Types_CreateFunction	(SrcInfo src_info, List_Types_field fields);

#endif /* DEF_STRUCT_Types_CreateFunction */

#ifndef DEF_STRUCT_Types_Scope
#define DEF_STRUCT_Types_Scope

struct s_Types_Scope {
  Types_Scope   next;  
  Int   _self;  
  Int   _end;  
  Types_Scope_tag       tag;  
  union {
  struct s_Types_struct_typeScope {
    Types_struct_type   data;  
  } Types_struct_typeScope;
} sub;
} ;

#define Types_Scope_next(_p)    ((*_p).next)
#define Types_Scope__self(_p)   ((*_p)._self)
#define Types_Scope__end(_p)    ((*_p)._end)
#define Types_Scope_tag(_p)     ((*_p).tag)
#define Types_struct_typeScope_data(_p) ((*_p).sub.Types_struct_typeScope.data)

extern Types_struct_typeScope Create_Types_struct_typeScope	(Types_Scope next, Types_struct_type data);

#endif /* DEF_STRUCT_Types_Scope */

#ifndef DEF_STRUCT_List_Types_struct_type
#define DEF_STRUCT_List_Types_struct_type

struct s_List_Types_struct_type {
  Types_struct_type     data;  
  List_Types_struct_type        next;  
} ;

#define List_Types_struct_type_data(_p) ((*_p).data)
#define List_Types_struct_type_next(_p) ((*_p).next)

#ifndef Create_List_Types_struct_type
#define Create_List_Types_struct_type(x,y) (List_Types_struct_type)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Types_struct_type_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Types_struct_type */

#ifndef DEF_STRUCT_List_Types_field
#define DEF_STRUCT_List_Types_field

struct s_List_Types_field {
  Types_field   data;  
  List_Types_field      next;  
} ;

#define List_Types_field_data(_p)       ((*_p).data)
#define List_Types_field_next(_p)       ((*_p).next)

#ifndef Create_List_Types_field
#define Create_List_Types_field(x,y) (List_Types_field)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Types_field_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Types_field */

#ifndef DEF_STRUCT_List_Types_CreateFunction
#define DEF_STRUCT_List_Types_CreateFunction

struct s_List_Types_CreateFunction {
  Types_CreateFunction  data;  
  List_Types_CreateFunction     next;  
} ;

#define List_Types_CreateFunction_data(_p)      ((*_p).data)
#define List_Types_CreateFunction_next(_p)      ((*_p).next)

#ifndef Create_List_Types_CreateFunction
#define Create_List_Types_CreateFunction(x,y) (List_Types_CreateFunction)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Types_CreateFunction_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Types_CreateFunction */

#ifndef DEF_STRUCT_List_Types_macro
#define DEF_STRUCT_List_Types_macro

struct s_List_Types_macro {
  Types_macro   data;  
  List_Types_macro      next;  
} ;

#define List_Types_macro_data(_p)       ((*_p).data)
#define List_Types_macro_next(_p)       ((*_p).next)

#ifndef Create_List_Types_macro
#define Create_List_Types_macro(x,y) (List_Types_macro)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Types_macro_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Types_macro */

#ifndef DEF_STRUCT_List_Types_TypeName
#define DEF_STRUCT_List_Types_TypeName

struct s_List_Types_TypeName {
  Types_TypeName        data;  
  List_Types_TypeName   next;  
} ;

#define List_Types_TypeName_data(_p)    ((*_p).data)
#define List_Types_TypeName_next(_p)    ((*_p).next)

#ifndef Create_List_Types_TypeName
#define Create_List_Types_TypeName(x,y) (List_Types_TypeName)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Types_TypeName_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Types_TypeName */

#ifndef DEF_STRUCT_List_Types_StructType
#define DEF_STRUCT_List_Types_StructType

struct s_List_Types_StructType {
  Types_StructType      data;  
  List_Types_StructType next;  
} ;

#define List_Types_StructType_data(_p)  ((*_p).data)
#define List_Types_StructType_next(_p)  ((*_p).next)

#ifndef Create_List_Types_StructType
#define Create_List_Types_StructType(x,y) (List_Types_StructType)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Types_StructType_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Types_StructType */

#ifndef DEF_STRUCT_List_Types_BindType
#define DEF_STRUCT_List_Types_BindType

struct s_List_Types_BindType {
  Types_BindType        data;  
  List_Types_BindType   next;  
} ;

#define List_Types_BindType_data(_p)    ((*_p).data)
#define List_Types_BindType_next(_p)    ((*_p).next)

#ifndef Create_List_Types_BindType
#define Create_List_Types_BindType(x,y) (List_Types_BindType)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Types_BindType_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Types_BindType */

#ifndef DEF_STRUCT_List_Types_subtypedef
#define DEF_STRUCT_List_Types_subtypedef

struct s_List_Types_subtypedef {
  Types_subtypedef      data;  
  List_Types_subtypedef next;  
} ;

#define List_Types_subtypedef_data(_p)  ((*_p).data)
#define List_Types_subtypedef_next(_p)  ((*_p).next)

#ifndef Create_List_Types_subtypedef
#define Create_List_Types_subtypedef(x,y) (List_Types_subtypedef)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Types_subtypedef_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Types_subtypedef */

#ifndef DEF_STRUCT_List_Types_PointerType
#define DEF_STRUCT_List_Types_PointerType

struct s_List_Types_PointerType {
  Types_PointerType     data;  
  List_Types_PointerType        next;  
} ;

#define List_Types_PointerType_data(_p) ((*_p).data)
#define List_Types_PointerType_next(_p) ((*_p).next)

#ifndef Create_List_Types_PointerType
#define Create_List_Types_PointerType(x,y) (List_Types_PointerType)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Types_PointerType_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Types_PointerType */

#ifndef DEF_STRUCT_List_Types_EnumType
#define DEF_STRUCT_List_Types_EnumType

struct s_List_Types_EnumType {
  Types_EnumType        data;  
  List_Types_EnumType   next;  
} ;

#define List_Types_EnumType_data(_p)    ((*_p).data)
#define List_Types_EnumType_next(_p)    ((*_p).next)

#ifndef Create_List_Types_EnumType
#define Create_List_Types_EnumType(x,y) (List_Types_EnumType)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Types_EnumType_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Types_EnumType */

#define PRE_ACTION  1
#define POST_ACTION 0

typedef struct s_Types_TraverseTable {
  Front_Traversal traversal;
  Pointer (*action_Types[2]) (Types_Types, Pointer);
  Bool skip_children_Types;
  Pointer (*action_includes2[2]) (Types_includes2, Pointer);
  Bool skip_children_includes2;
  Pointer (*action_EnumType[2]) (Types_EnumType, Pointer);
  Bool skip_children_EnumType;
  Pointer (*action_BindType[2]) (Types_BindType, Pointer);
  Bool skip_children_BindType;
  Pointer (*action_PointerType[2]) (Types_PointerType, Pointer);
  Bool skip_children_PointerType;
  Pointer (*action_subtypedef[2]) (Types_subtypedef, Pointer);
  Bool skip_children_subtypedef;
  Pointer (*action_StructType[2]) (Types_StructType, Pointer);
  Bool skip_children_StructType;
  Pointer (*action_struct_type[2]) (Types_struct_type, Pointer);
  Bool skip_children_struct_type;
  Pointer (*action_macro[2]) (Types_macro, Pointer);
  Bool skip_children_macro;
  Pointer (*action_plain_macro[2]) (Types_plain_macro, Pointer);
  Bool skip_children_plain_macro;
  Pointer (*action_access_macro[2]) (Types_access_macro, Pointer);
  Bool skip_children_access_macro;
  Pointer (*action_field[2]) (Types_field, Pointer);
  Bool skip_children_field;
  Pointer (*action_TypeName[2]) (Types_TypeName, Pointer);
  Bool skip_children_TypeName;
  Pointer (*action_CreateFunction[2]) (Types_CreateFunction, Pointer);
  Bool skip_children_CreateFunction;
  Pointer (*action_Scope[2]) (Types_Scope, Pointer);
  Bool skip_children_Scope;
  Pointer (*action_struct_typeScope[2]) (Types_struct_typeScope, Pointer);
  Bool skip_children_struct_typeScope;
  Pointer (*action_List_struct_type[2]) (List_Types_struct_type, Pointer);
  Bool skip_children_List_struct_type;
  Pointer (*action_List_field[2]) (List_Types_field, Pointer);
  Bool skip_children_List_field;
  Pointer (*action_List_CreateFunction[2]) (List_Types_CreateFunction, Pointer);
  Bool skip_children_List_CreateFunction;
  Pointer (*action_List_macro[2]) (List_Types_macro, Pointer);
  Bool skip_children_List_macro;
  Pointer (*action_List_TypeName[2]) (List_Types_TypeName, Pointer);
  Bool skip_children_List_TypeName;
  Pointer (*action_List_StructType[2]) (List_Types_StructType, Pointer);
  Bool skip_children_List_StructType;
  Pointer (*action_List_BindType[2]) (List_Types_BindType, Pointer);
  Bool skip_children_List_BindType;
  Pointer (*action_List_subtypedef[2]) (List_Types_subtypedef, Pointer);
  Bool skip_children_List_subtypedef;
  Pointer (*action_List_PointerType[2]) (List_Types_PointerType, Pointer);
  Bool skip_children_List_PointerType;
  Pointer (*action_List_EnumType[2]) (List_Types_EnumType, Pointer);
  Bool skip_children_List_EnumType;
} *Types_TraverseTable;

extern Pointer Traverse_Types_Types (Types_Types me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_includes2 (Types_includes2 me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_EnumType (Types_EnumType me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_BindType (Types_BindType me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_PointerType (Types_PointerType me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_subtypedef (Types_subtypedef me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_StructType (Types_StructType me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_struct_type (Types_struct_type me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_macro (Types_macro me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_field (Types_field me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_TypeName (Types_TypeName me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_CreateFunction (Types_CreateFunction me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_Types_Scope (Types_Scope me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Types_struct_type (List_Types_struct_type me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Types_field (List_Types_field me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Types_CreateFunction (List_Types_CreateFunction me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Types_macro (List_Types_macro me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Types_TypeName (List_Types_TypeName me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Types_StructType (List_Types_StructType me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Types_BindType (List_Types_BindType me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Types_subtypedef (List_Types_subtypedef me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Types_PointerType (List_Types_PointerType me, Types_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Types_EnumType (List_Types_EnumType me, Types_TraverseTable table, Pointer val);

typedef struct s_void_Types_TraverseTable {
  void (*action_Types[2]) (Types_Types);
  Bool skip_children_Types;
  void (*action_includes2[2]) (Types_includes2);
  Bool skip_children_includes2;
  void (*action_EnumType[2]) (Types_EnumType);
  Bool skip_children_EnumType;
  void (*action_BindType[2]) (Types_BindType);
  Bool skip_children_BindType;
  void (*action_PointerType[2]) (Types_PointerType);
  Bool skip_children_PointerType;
  void (*action_subtypedef[2]) (Types_subtypedef);
  Bool skip_children_subtypedef;
  void (*action_StructType[2]) (Types_StructType);
  Bool skip_children_StructType;
  void (*action_struct_type[2]) (Types_struct_type);
  Bool skip_children_struct_type;
  void (*action_macro[2]) (Types_macro);
  Bool skip_children_macro;
  void (*action_plain_macro[2]) (Types_plain_macro);
  Bool skip_children_plain_macro;
  void (*action_access_macro[2]) (Types_access_macro);
  Bool skip_children_access_macro;
  void (*action_field[2]) (Types_field);
  Bool skip_children_field;
  void (*action_TypeName[2]) (Types_TypeName);
  Bool skip_children_TypeName;
  void (*action_CreateFunction[2]) (Types_CreateFunction);
  Bool skip_children_CreateFunction;
  void (*action_Scope[2]) (Types_Scope);
  Bool skip_children_Scope;
  void (*action_struct_typeScope[2]) (Types_struct_typeScope);
  Bool skip_children_struct_typeScope;
  void (*action_List_struct_type[2]) (List_Types_struct_type);
  Bool skip_children_List_struct_type;
  void (*action_List_field[2]) (List_Types_field);
  Bool skip_children_List_field;
  void (*action_List_CreateFunction[2]) (List_Types_CreateFunction);
  Bool skip_children_List_CreateFunction;
  void (*action_List_macro[2]) (List_Types_macro);
  Bool skip_children_List_macro;
  void (*action_List_TypeName[2]) (List_Types_TypeName);
  Bool skip_children_List_TypeName;
  void (*action_List_StructType[2]) (List_Types_StructType);
  Bool skip_children_List_StructType;
  void (*action_List_BindType[2]) (List_Types_BindType);
  Bool skip_children_List_BindType;
  void (*action_List_subtypedef[2]) (List_Types_subtypedef);
  Bool skip_children_List_subtypedef;
  void (*action_List_PointerType[2]) (List_Types_PointerType);
  Bool skip_children_List_PointerType;
  void (*action_List_EnumType[2]) (List_Types_EnumType);
  Bool skip_children_List_EnumType;
} *void_Types_TraverseTable;

extern void Traverse_void_Types_Types (Types_Types me, void_Types_TraverseTable table);
extern void Traverse_void_Types_includes2 (Types_includes2 me, void_Types_TraverseTable table);
extern void Traverse_void_Types_EnumType (Types_EnumType me, void_Types_TraverseTable table);
extern void Traverse_void_Types_BindType (Types_BindType me, void_Types_TraverseTable table);
extern void Traverse_void_Types_PointerType (Types_PointerType me, void_Types_TraverseTable table);
extern void Traverse_void_Types_subtypedef (Types_subtypedef me, void_Types_TraverseTable table);
extern void Traverse_void_Types_StructType (Types_StructType me, void_Types_TraverseTable table);
extern void Traverse_void_Types_struct_type (Types_struct_type me, void_Types_TraverseTable table);
extern void Traverse_void_Types_macro (Types_macro me, void_Types_TraverseTable table);
extern void Traverse_void_Types_field (Types_field me, void_Types_TraverseTable table);
extern void Traverse_void_Types_TypeName (Types_TypeName me, void_Types_TraverseTable table);
extern void Traverse_void_Types_CreateFunction (Types_CreateFunction me, void_Types_TraverseTable table);
extern void Traverse_void_Types_Scope (Types_Scope me, void_Types_TraverseTable table);
extern void Traverse_void_List_Types_struct_type (List_Types_struct_type me, void_Types_TraverseTable table);
extern void Traverse_void_List_Types_field (List_Types_field me, void_Types_TraverseTable table);
extern void Traverse_void_List_Types_CreateFunction (List_Types_CreateFunction me, void_Types_TraverseTable table);
extern void Traverse_void_List_Types_macro (List_Types_macro me, void_Types_TraverseTable table);
extern void Traverse_void_List_Types_TypeName (List_Types_TypeName me, void_Types_TraverseTable table);
extern void Traverse_void_List_Types_StructType (List_Types_StructType me, void_Types_TraverseTable table);
extern void Traverse_void_List_Types_BindType (List_Types_BindType me, void_Types_TraverseTable table);
extern void Traverse_void_List_Types_subtypedef (List_Types_subtypedef me, void_Types_TraverseTable table);
extern void Traverse_void_List_Types_PointerType (List_Types_PointerType me, void_Types_TraverseTable table);
extern void Traverse_void_List_Types_EnumType (List_Types_EnumType me, void_Types_TraverseTable table);

typedef struct s_copy_Types_TraverseTable {
  Front_ClearBackEdges clear_back_edges;
  Types_Types (*action_Types[2]) (Types_Types, Types_Types);
  Bool skip_children_Types;
  Types_includes2 (*action_includes2[2]) (Types_includes2, Types_includes2);
  Bool skip_children_includes2;
  Types_EnumType (*action_EnumType[2]) (Types_EnumType, Types_EnumType);
  Bool skip_children_EnumType;
  Types_BindType (*action_BindType[2]) (Types_BindType, Types_BindType);
  Bool skip_children_BindType;
  Types_PointerType (*action_PointerType[2]) (Types_PointerType, Types_PointerType);
  Bool skip_children_PointerType;
  Types_subtypedef (*action_subtypedef[2]) (Types_subtypedef, Types_subtypedef);
  Bool skip_children_subtypedef;
  Types_StructType (*action_StructType[2]) (Types_StructType, Types_StructType);
  Bool skip_children_StructType;
  Types_struct_type (*action_struct_type[2]) (Types_struct_type, Types_struct_type);
  Bool skip_children_struct_type;
  Types_macro (*action_macro[2]) (Types_macro, Types_macro);
  Bool skip_children_macro;
  Types_plain_macro (*action_plain_macro[2]) (Types_plain_macro, Types_plain_macro);
  Bool skip_children_plain_macro;
  Types_access_macro (*action_access_macro[2]) (Types_access_macro, Types_access_macro);
  Bool skip_children_access_macro;
  Types_field (*action_field[2]) (Types_field, Types_field);
  Bool skip_children_field;
  Types_TypeName (*action_TypeName[2]) (Types_TypeName, Types_TypeName);
  Bool skip_children_TypeName;
  Types_CreateFunction (*action_CreateFunction[2]) (Types_CreateFunction, Types_CreateFunction);
  Bool skip_children_CreateFunction;
  Types_Scope (*action_Scope[2]) (Types_Scope, Types_Scope);
  Bool skip_children_Scope;
  Types_struct_typeScope (*action_struct_typeScope[2]) (Types_struct_typeScope, Types_struct_typeScope);
  Bool skip_children_struct_typeScope;
  List_Types_struct_type (*action_List_struct_type[2]) (List_Types_struct_type, List_Types_struct_type);
  Bool skip_children_List_struct_type;
  List_Types_field (*action_List_field[2]) (List_Types_field, List_Types_field);
  Bool skip_children_List_field;
  List_Types_CreateFunction (*action_List_CreateFunction[2]) (List_Types_CreateFunction, List_Types_CreateFunction);
  Bool skip_children_List_CreateFunction;
  List_Types_macro (*action_List_macro[2]) (List_Types_macro, List_Types_macro);
  Bool skip_children_List_macro;
  List_Types_TypeName (*action_List_TypeName[2]) (List_Types_TypeName, List_Types_TypeName);
  Bool skip_children_List_TypeName;
  List_Types_StructType (*action_List_StructType[2]) (List_Types_StructType, List_Types_StructType);
  Bool skip_children_List_StructType;
  List_Types_BindType (*action_List_BindType[2]) (List_Types_BindType, List_Types_BindType);
  Bool skip_children_List_BindType;
  List_Types_subtypedef (*action_List_subtypedef[2]) (List_Types_subtypedef, List_Types_subtypedef);
  Bool skip_children_List_subtypedef;
  List_Types_PointerType (*action_List_PointerType[2]) (List_Types_PointerType, List_Types_PointerType);
  Bool skip_children_List_PointerType;
  List_Types_EnumType (*action_List_EnumType[2]) (List_Types_EnumType, List_Types_EnumType);
  Bool skip_children_List_EnumType;
} *copy_Types_TraverseTable;

extern Types_Types Traverse_copy_Types_Types (Types_Types me, copy_Types_TraverseTable table);
#ifndef COPY_Types_Types
#define COPY_Types_Types(x) Traverse_copy_Types_Types(x, &Types_copy_actions)
#endif
extern Types_includes2 Traverse_copy_Types_includes2 (Types_includes2 me, copy_Types_TraverseTable table);
#ifndef COPY_Types_includes2
#define COPY_Types_includes2(x) Traverse_copy_Types_includes2(x, &Types_copy_actions)
#endif
extern Types_EnumType Traverse_copy_Types_EnumType (Types_EnumType me, copy_Types_TraverseTable table);
#ifndef COPY_Types_EnumType
#define COPY_Types_EnumType(x) Traverse_copy_Types_EnumType(x, &Types_copy_actions)
#endif
extern Types_BindType Traverse_copy_Types_BindType (Types_BindType me, copy_Types_TraverseTable table);
#ifndef COPY_Types_BindType
#define COPY_Types_BindType(x) Traverse_copy_Types_BindType(x, &Types_copy_actions)
#endif
extern Types_PointerType Traverse_copy_Types_PointerType (Types_PointerType me, copy_Types_TraverseTable table);
#ifndef COPY_Types_PointerType
#define COPY_Types_PointerType(x) Traverse_copy_Types_PointerType(x, &Types_copy_actions)
#endif
extern Types_subtypedef Traverse_copy_Types_subtypedef (Types_subtypedef me, copy_Types_TraverseTable table);
#ifndef COPY_Types_subtypedef
#define COPY_Types_subtypedef(x) Traverse_copy_Types_subtypedef(x, &Types_copy_actions)
#endif
extern Types_StructType Traverse_copy_Types_StructType (Types_StructType me, copy_Types_TraverseTable table);
#ifndef COPY_Types_StructType
#define COPY_Types_StructType(x) Traverse_copy_Types_StructType(x, &Types_copy_actions)
#endif
extern Types_struct_type Traverse_copy_Types_struct_type (Types_struct_type me, copy_Types_TraverseTable table);
#ifndef COPY_Types_struct_type
#define COPY_Types_struct_type(x) Traverse_copy_Types_struct_type(x, &Types_copy_actions)
#endif
extern Types_macro Traverse_copy_Types_macro (Types_macro me, copy_Types_TraverseTable table);
#ifndef COPY_Types_macro
#define COPY_Types_macro(x) Traverse_copy_Types_macro(x, &Types_copy_actions)
#endif
extern Types_field Traverse_copy_Types_field (Types_field me, copy_Types_TraverseTable table);
#ifndef COPY_Types_field
#define COPY_Types_field(x) Traverse_copy_Types_field(x, &Types_copy_actions)
#endif
extern Types_TypeName Traverse_copy_Types_TypeName (Types_TypeName me, copy_Types_TraverseTable table);
#ifndef COPY_Types_TypeName
#define COPY_Types_TypeName(x) Traverse_copy_Types_TypeName(x, &Types_copy_actions)
#endif
extern Types_CreateFunction Traverse_copy_Types_CreateFunction (Types_CreateFunction me, copy_Types_TraverseTable table);
#ifndef COPY_Types_CreateFunction
#define COPY_Types_CreateFunction(x) Traverse_copy_Types_CreateFunction(x, &Types_copy_actions)
#endif
extern Types_Scope Traverse_copy_Types_Scope (Types_Scope me, copy_Types_TraverseTable table);
#ifndef COPY_Types_Scope
#define COPY_Types_Scope(x) Traverse_copy_Types_Scope(x, &Types_copy_actions)
#endif
extern List_Types_struct_type Traverse_copy_List_Types_struct_type (List_Types_struct_type me, copy_Types_TraverseTable table);
#ifndef COPY_Types_List_struct_type
#define COPY_Types_List_struct_type(x) Traverse_copy_List_Types_struct_type(x, &Types_copy_actions)
#endif
extern List_Types_field Traverse_copy_List_Types_field (List_Types_field me, copy_Types_TraverseTable table);
#ifndef COPY_Types_List_field
#define COPY_Types_List_field(x) Traverse_copy_List_Types_field(x, &Types_copy_actions)
#endif
extern List_Types_CreateFunction Traverse_copy_List_Types_CreateFunction (List_Types_CreateFunction me, copy_Types_TraverseTable table);
#ifndef COPY_Types_List_CreateFunction
#define COPY_Types_List_CreateFunction(x) Traverse_copy_List_Types_CreateFunction(x, &Types_copy_actions)
#endif
extern List_Types_macro Traverse_copy_List_Types_macro (List_Types_macro me, copy_Types_TraverseTable table);
#ifndef COPY_Types_List_macro
#define COPY_Types_List_macro(x) Traverse_copy_List_Types_macro(x, &Types_copy_actions)
#endif
extern List_Types_TypeName Traverse_copy_List_Types_TypeName (List_Types_TypeName me, copy_Types_TraverseTable table);
#ifndef COPY_Types_List_TypeName
#define COPY_Types_List_TypeName(x) Traverse_copy_List_Types_TypeName(x, &Types_copy_actions)
#endif
extern List_Types_StructType Traverse_copy_List_Types_StructType (List_Types_StructType me, copy_Types_TraverseTable table);
#ifndef COPY_Types_List_StructType
#define COPY_Types_List_StructType(x) Traverse_copy_List_Types_StructType(x, &Types_copy_actions)
#endif
extern List_Types_BindType Traverse_copy_List_Types_BindType (List_Types_BindType me, copy_Types_TraverseTable table);
#ifndef COPY_Types_List_BindType
#define COPY_Types_List_BindType(x) Traverse_copy_List_Types_BindType(x, &Types_copy_actions)
#endif
extern List_Types_subtypedef Traverse_copy_List_Types_subtypedef (List_Types_subtypedef me, copy_Types_TraverseTable table);
#ifndef COPY_Types_List_subtypedef
#define COPY_Types_List_subtypedef(x) Traverse_copy_List_Types_subtypedef(x, &Types_copy_actions)
#endif
extern List_Types_PointerType Traverse_copy_List_Types_PointerType (List_Types_PointerType me, copy_Types_TraverseTable table);
#ifndef COPY_Types_List_PointerType
#define COPY_Types_List_PointerType(x) Traverse_copy_List_Types_PointerType(x, &Types_copy_actions)
#endif
extern List_Types_EnumType Traverse_copy_List_Types_EnumType (List_Types_EnumType me, copy_Types_TraverseTable table);
#ifndef COPY_Types_List_EnumType
#define COPY_Types_List_EnumType(x) Traverse_copy_List_Types_EnumType(x, &Types_copy_actions)
#endif

typedef struct s_compare_Types_TraverseTable {
  int (*action_Types[2]) (Types_Types, Types_Types);
  Bool skip_children_Types;
  int (*action_includes2[2]) (Types_includes2, Types_includes2);
  Bool skip_children_includes2;
  int (*action_EnumType[2]) (Types_EnumType, Types_EnumType);
  Bool skip_children_EnumType;
  int (*action_BindType[2]) (Types_BindType, Types_BindType);
  Bool skip_children_BindType;
  int (*action_PointerType[2]) (Types_PointerType, Types_PointerType);
  Bool skip_children_PointerType;
  int (*action_subtypedef[2]) (Types_subtypedef, Types_subtypedef);
  Bool skip_children_subtypedef;
  int (*action_StructType[2]) (Types_StructType, Types_StructType);
  Bool skip_children_StructType;
  int (*action_struct_type[2]) (Types_struct_type, Types_struct_type);
  Bool skip_children_struct_type;
  int (*action_macro[2]) (Types_macro, Types_macro);
  Bool skip_children_macro;
  int (*action_plain_macro[2]) (Types_plain_macro, Types_plain_macro);
  Bool skip_children_plain_macro;
  int (*action_access_macro[2]) (Types_access_macro, Types_access_macro);
  Bool skip_children_access_macro;
  int (*action_field[2]) (Types_field, Types_field);
  Bool skip_children_field;
  int (*action_TypeName[2]) (Types_TypeName, Types_TypeName);
  Bool skip_children_TypeName;
  int (*action_CreateFunction[2]) (Types_CreateFunction, Types_CreateFunction);
  Bool skip_children_CreateFunction;
  int (*action_Scope[2]) (Types_Scope, Types_Scope);
  Bool skip_children_Scope;
  int (*action_struct_typeScope[2]) (Types_struct_typeScope, Types_struct_typeScope);
  Bool skip_children_struct_typeScope;
  int (*action_List_struct_type[2]) (List_Types_struct_type, List_Types_struct_type);
  Bool skip_children_List_struct_type;
  int (*action_List_field[2]) (List_Types_field, List_Types_field);
  Bool skip_children_List_field;
  int (*action_List_CreateFunction[2]) (List_Types_CreateFunction, List_Types_CreateFunction);
  Bool skip_children_List_CreateFunction;
  int (*action_List_macro[2]) (List_Types_macro, List_Types_macro);
  Bool skip_children_List_macro;
  int (*action_List_TypeName[2]) (List_Types_TypeName, List_Types_TypeName);
  Bool skip_children_List_TypeName;
  int (*action_List_StructType[2]) (List_Types_StructType, List_Types_StructType);
  Bool skip_children_List_StructType;
  int (*action_List_BindType[2]) (List_Types_BindType, List_Types_BindType);
  Bool skip_children_List_BindType;
  int (*action_List_subtypedef[2]) (List_Types_subtypedef, List_Types_subtypedef);
  Bool skip_children_List_subtypedef;
  int (*action_List_PointerType[2]) (List_Types_PointerType, List_Types_PointerType);
  Bool skip_children_List_PointerType;
  int (*action_List_EnumType[2]) (List_Types_EnumType, List_Types_EnumType);
  Bool skip_children_List_EnumType;
} *compare_Types_TraverseTable;

extern int Traverse_compare_Types_Types (Types_Types x, Types_Types y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_includes2 (Types_includes2 x, Types_includes2 y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_EnumType (Types_EnumType x, Types_EnumType y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_BindType (Types_BindType x, Types_BindType y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_PointerType (Types_PointerType x, Types_PointerType y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_subtypedef (Types_subtypedef x, Types_subtypedef y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_StructType (Types_StructType x, Types_StructType y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_struct_type (Types_struct_type x, Types_struct_type y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_macro (Types_macro x, Types_macro y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_field (Types_field x, Types_field y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_TypeName (Types_TypeName x, Types_TypeName y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_CreateFunction (Types_CreateFunction x, Types_CreateFunction y, compare_Types_TraverseTable table);
extern int Traverse_compare_Types_Scope (Types_Scope x, Types_Scope y, compare_Types_TraverseTable table);
extern int Traverse_compare_List_Types_struct_type (List_Types_struct_type x, List_Types_struct_type y, compare_Types_TraverseTable table);
extern int Traverse_compare_List_Types_field (List_Types_field x, List_Types_field y, compare_Types_TraverseTable table);
extern int Traverse_compare_List_Types_CreateFunction (List_Types_CreateFunction x, List_Types_CreateFunction y, compare_Types_TraverseTable table);
extern int Traverse_compare_List_Types_macro (List_Types_macro x, List_Types_macro y, compare_Types_TraverseTable table);
extern int Traverse_compare_List_Types_TypeName (List_Types_TypeName x, List_Types_TypeName y, compare_Types_TraverseTable table);
extern int Traverse_compare_List_Types_StructType (List_Types_StructType x, List_Types_StructType y, compare_Types_TraverseTable table);
extern int Traverse_compare_List_Types_BindType (List_Types_BindType x, List_Types_BindType y, compare_Types_TraverseTable table);
extern int Traverse_compare_List_Types_subtypedef (List_Types_subtypedef x, List_Types_subtypedef y, compare_Types_TraverseTable table);
extern int Traverse_compare_List_Types_PointerType (List_Types_PointerType x, List_Types_PointerType y, compare_Types_TraverseTable table);
extern int Traverse_compare_List_Types_EnumType (List_Types_EnumType x, List_Types_EnumType y, compare_Types_TraverseTable table);


extern void Types_fill_table (Types_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void void_Types_fill_table (void_Types_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void copy_Types_fill_table (copy_Types_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void compare_Types_fill_table (compare_Types_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern struct s_Types_TraverseTable Types_scope_actions;

extern struct s_void_Types_TraverseTable Types_defining_actions;

extern struct s_void_Types_TraverseTable Types_applied_actions;

extern struct s_void_Types_TraverseTable Types_check_actions;

extern struct s_void_Types_TraverseTable Types_print_actions;

extern struct s_copy_Types_TraverseTable Types_copy_actions;

extern struct s_compare_Types_TraverseTable Types_compare_actions;

typedef int Types_NameSpaces;

extern Types_NameSpaces Types_namespaces[1];

#define Types_DefaultNameSpace Types_namespaces[0]

#define Types_NUM_NAMESPACES 1

extern void Decorate_Types (Types_Types r);

#endif /* _Types */
