#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "front/error.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/mem.h"
#include "Types.h"

#ifndef Types_SKIP_NODE
# define Types_SKIP_NODE(n,t) FALSE
#endif

Types Types_root;

String Types_macro_tag_names[] = {
  "plain_macro_kind",
  "access_macro_kind",
};

String Types_Scope_tag_names[] = {
  "struct_typeScope_kind",
};

Types_Types Create_Types_Types	(SrcInfo src_info, List_Types_EnumType enums, List_Types_PointerType pointers, List_Types_subtypedef subs, Types_includes2 inc2, List_Types_subtypedef impdefs, List_Types_BindType binds, Ident r1, Ident r2, List_Types_StructType types)
{ Types_Types me = (Types_Types)fe_malloc(sizeof(*me));
  Types_Types_src_info(me) = src_info;
  Types_Types_enums(me) = enums;
  Types_Types_pointers(me) = pointers;
  Types_Types_subs(me) = subs;
  Types_Types_inc2(me) = inc2;
  Types_Types_impdefs(me) = impdefs;
  Types_Types_binds(me) = binds;
  Types_Types_r1(me) = r1;
  Types_Types_r2(me) = r2;
  Types_Types_types(me) = types;
  return me;
}

Types_includes2 Create_Types_includes2	(SrcInfo src_info, Ident id1, Ident id2, List_Ident uses)
{ Types_includes2 me = (Types_includes2)fe_malloc(sizeof(*me));
  Types_includes2_src_info(me) = src_info;
  Types_includes2_id1(me) = id1;
  Types_includes2_id2(me) = id2;
  Types_includes2_uses(me) = uses;
  return me;
}

Types_EnumType Create_Types_EnumType	(SrcInfo src_info, List_Types_TypeName enums, Ident id, Ident str, Ident tag, Int num)
{ Types_EnumType me = (Types_EnumType)fe_malloc(sizeof(*me));
  Types_EnumType_src_info(me) = src_info;
  Types_EnumType_enums(me) = enums;
  Types_EnumType_id(me) = id;
  Types_EnumType_str(me) = str;
  Types_EnumType_tag(me) = tag;
  Types_EnumType_num(me) = num;
  Types_EnumType_is_tag(me) = FALSE;
  Types_EnumType_str_type(me) = NULL;
  Types_EnumType_name(me) = EnumType_id (me);
  enum_set_name (me);
  return me;
}

Types_BindType Create_Types_BindType	(SrcInfo src_info, Ident id1, Ident id2, Ident id3, Ident id4, Ident id5, Ident id6, Ident id7, Int num)
{ Types_BindType me = (Types_BindType)fe_malloc(sizeof(*me));
  Types_BindType_src_info(me) = src_info;
  Types_BindType_id1(me) = id1;
  Types_BindType_id2(me) = id2;
  Types_BindType_id3(me) = id3;
  Types_BindType_id4(me) = id4;
  Types_BindType_id5(me) = id5;
  Types_BindType_id6(me) = id6;
  Types_BindType_id7(me) = id7;
  Types_BindType_num(me) = num;
  Types_BindType_abbrev(me) = NULL;
  return me;
}

Types_PointerType Create_Types_PointerType	(SrcInfo src_info, Ident id1, Ident id2, Ident id3, Ident id, List_Types_subtypedef subs)
{ Types_PointerType me = (Types_PointerType)fe_malloc(sizeof(*me));
  Types_PointerType_src_info(me) = src_info;
  Types_PointerType_id1(me) = id1;
  Types_PointerType_id2(me) = id2;
  Types_PointerType_id3(me) = id3;
  Types_PointerType_id(me) = id;
  Types_PointerType_subs(me) = subs;
  return me;
}

Types_subtypedef Create_Types_subtypedef	(SrcInfo src_info, Ident super, Ident id)
{ Types_subtypedef me = (Types_subtypedef)fe_malloc(sizeof(*me));
  Types_subtypedef_src_info(me) = src_info;
  Types_subtypedef_super(me) = super;
  Types_subtypedef_id(me) = id;
  return me;
}

Types_StructType Create_Types_StructType	(SrcInfo src_info, Ident id1, Ident id2, Types_struct_type type, List_Types_macro macros, List_Types_CreateFunction creates, Ident id3)
{ Types_StructType me = (Types_StructType)fe_malloc(sizeof(*me));
  Types_StructType_src_info(me) = src_info;
  Types_StructType_id1(me) = id1;
  Types_StructType_id2(me) = id2;
  Types_StructType_type(me) = type;
  Types_StructType_macros(me) = macros;
  Types_StructType_creates(me) = creates;
  Types_StructType_id3(me) = id3;
  return me;
}

Types_struct_type Create_Types_struct_type	(SrcInfo src_info, Ident tag, Ident user, List_Types_field fields1, List_Types_struct_type sub_types, List_Types_field fields2, Ident id)
{ Types_struct_type me = (Types_struct_type)fe_malloc(sizeof(*me));
  Types_struct_type_src_info(me) = src_info;
  Types_struct_type_tag(me) = tag;
  Types_struct_type_user(me) = user;
  Types_struct_type_fields1(me) = fields1;
  Types_struct_type_sub_types(me) = sub_types;
  Types_struct_type_fields2(me) = fields2;
  Types_struct_type_id(me) = id;
  Types_struct_type__num(me) = - 1;
  Types_struct_type_scope(me) = NULL;
  Types_struct_type_old_scope(me) = NULL;
  Types_struct_type_tag_bind(me) = NULL;
  Types_struct_type_name(me) = struct_type_tag (me);
  Types_struct_type_checks(me) = NULL;
  Types_struct_type_is_list(me) = FALSE;
  Types_struct_type_is_bind(me) = FALSE;
  Types_struct_type_is_optional(me) = FALSE;
  Types_struct_type_is_scope(me) = FALSE;
  Types_struct_type_uses_scope(me) = FALSE;
  Types_struct_type_opens_scope(me) = FALSE;
  Types_struct_type_closes_scope(me) = FALSE;
  Types_struct_type_in_lib(me) = FALSE;
  Types_struct_type_alt(me) = NULL;
  Types_struct_type_create(me) = NULL;
  Types_struct_type_enumtype(me) = NULL;
  set_name (me);
  return me;
}

Types_access_macro Create_Types_access_macro	(SrcInfo src_info, Ident type, Ident id, Ident r, List_Ident types, Ident f)
{ Types_access_macro me = (Types_access_macro)fe_malloc(sizeof(*me));
  Types_macro_src_info(me) = src_info;
  Types_macro_type(me) = type;
  Types_macro_id(me) = id;
  Types_access_macro_r(me) = r;
  Types_macro_types(me) = types;
  Types_macro_f(me) = f;
  Types_macro_tag(me) = Types_access_macro_kind;
  return me;
}

Types_plain_macro Create_Types_plain_macro	(SrcInfo src_info, Ident type, Ident id, List_Ident types, Ident f)
{ Types_plain_macro me = (Types_plain_macro)fe_malloc(sizeof(*me));
  Types_macro_src_info(me) = src_info;
  Types_macro_type(me) = type;
  Types_macro_id(me) = id;
  Types_macro_types(me) = types;
  Types_macro_f(me) = f;
  Types_macro_tag(me) = Types_plain_macro_kind;
  return me;
}

Types_field Create_Types_field	(SrcInfo src_info, List_Types_TypeName type, Ident id)
{ Types_field me = (Types_field)fe_malloc(sizeof(*me));
  Types_field_src_info(me) = src_info;
  Types_field_type(me) = type;
  Types_field_id(me) = id;
  Types_field_grammar_id(me) = NULL;
  Types_field_uses_scope(me) = FALSE;
  Types_field_is_defining(me) = NULL;
  Types_field_is_applied(me) = NULL;
  Types_field_applied_id(me) = NULL;
  Types_field_is_tag(me) = FALSE;
  Types_field_init(me) = NULL;
  Types_field_trav(me) = FALSE;
  Types_field_clear(me) = FALSE;
  Types_field_dont_clear(me) = FALSE;
  Types_field_compare(me) = NULL;
  return me;
}

Types_TypeName Create_Types_TypeName	(SrcInfo src_info, Ident full)
{ Types_TypeName me = (Types_TypeName)fe_malloc(sizeof(*me));
  Types_TypeName_src_info(me) = src_info;
  Types_TypeName_full(me) = full;
  Types_TypeName__num(me) = - 1;
  Types_TypeName_scope(me) = NULL;
  Types_TypeName_old_scope(me) = NULL;
  Types_TypeName_type_bind(me) = NULL;
  Types_TypeName_type(me) = NULL;
  Types_TypeName_id(me) = TypeName_full (me);
  return me;
}

Types_CreateFunction Create_Types_CreateFunction	(SrcInfo src_info, List_Types_field fields)
{ Types_CreateFunction me = (Types_CreateFunction)fe_malloc(sizeof(*me));
  Types_CreateFunction_src_info(me) = src_info;
  Types_CreateFunction_fields(me) = fields;
  Types_CreateFunction_type(me) = NULL;
  return me;
}

Types_struct_typeScope Create_Types_struct_typeScope	(Types_Scope next, Types_struct_type data)
{ Types_struct_typeScope me = (Types_struct_typeScope)fe_malloc(sizeof(*me));
  Types_Scope_next(me) = next;
  Types_struct_typeScope_data(me) = data;
  Types_Scope__self(me) = 0;
  Types_Scope__end(me) = 0;
  Types_Scope_tag(me) = Types_struct_typeScope_kind;
  return me;
}

Pointer Traverse_Types_Types (Types_Types me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(Types, me)) return val;
  if (action->action_Types[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Types[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Types)
  { 
  if (!action->skip_children_Types) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_EnumType (Types_Types_enums(me), action, val);
    else Traverse_List_Types_EnumType (Types_Types_enums(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_PointerType (Types_Types_pointers(me), action, val);
    else Traverse_List_Types_PointerType (Types_Types_pointers(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_subtypedef (Types_Types_subs(me), action, val);
    else Traverse_List_Types_subtypedef (Types_Types_subs(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_Types_includes2 (Types_Types_inc2(me), action, val);
    else Traverse_Types_includes2 (Types_Types_inc2(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_subtypedef (Types_Types_impdefs(me), action, val);
    else Traverse_List_Types_subtypedef (Types_Types_impdefs(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_BindType (Types_Types_binds(me), action, val);
    else Traverse_List_Types_BindType (Types_Types_binds(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_StructType (Types_Types_types(me), action, val);
    else Traverse_List_Types_StructType (Types_Types_types(me), action, val);
  }
  }
  if (action->action_Types[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Types[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_includes2 (Types_includes2 me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(includes2, me)) return val;
  if (action->action_includes2[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_includes2[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_includes2)
  { 
  }
  if (action->action_includes2[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_includes2[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_EnumType (Types_EnumType me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(EnumType, me)) return val;
  if (action->action_EnumType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_EnumType[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_EnumType)
  { 
  if (!action->skip_children_EnumType) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_TypeName (Types_EnumType_enums(me), action, val);
    else Traverse_List_Types_TypeName (Types_EnumType_enums(me), action, val);
  }
  }
  if (action->action_EnumType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_EnumType[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_BindType (Types_BindType me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(BindType, me)) return val;
  if (action->action_BindType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_BindType[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_BindType)
  { 
  }
  if (action->action_BindType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_BindType[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_PointerType (Types_PointerType me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(PointerType, me)) return val;
  if (action->action_PointerType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_PointerType[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_PointerType)
  { 
  if (!action->skip_children_PointerType) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_subtypedef (Types_PointerType_subs(me), action, val);
    else Traverse_List_Types_subtypedef (Types_PointerType_subs(me), action, val);
  }
  }
  if (action->action_PointerType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_PointerType[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_subtypedef (Types_subtypedef me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(subtypedef, me)) return val;
  if (action->action_subtypedef[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_subtypedef[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_subtypedef)
  { 
  }
  if (action->action_subtypedef[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_subtypedef[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_StructType (Types_StructType me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(StructType, me)) return val;
  if (action->action_StructType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_StructType[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_StructType)
  { 
  if (!action->skip_children_StructType) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_struct_type (Types_StructType_type(me), action, val);
    else Traverse_Types_struct_type (Types_StructType_type(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_macro (Types_StructType_macros(me), action, val);
    else Traverse_List_Types_macro (Types_StructType_macros(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_CreateFunction (Types_StructType_creates(me), action, val);
    else Traverse_List_Types_CreateFunction (Types_StructType_creates(me), action, val);
  }
  }
  if (action->action_StructType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_StructType[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_struct_type (Types_struct_type me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(struct_type, me)) return val;
  if (action->action_struct_type[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_struct_type[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_struct_type)
  { 
  if (!action->skip_children_struct_type) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_field (Types_struct_type_fields1(me), action, val);
    else Traverse_List_Types_field (Types_struct_type_fields1(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_struct_type (Types_struct_type_sub_types(me), action, val);
    else Traverse_List_Types_struct_type (Types_struct_type_sub_types(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_field (Types_struct_type_fields2(me), action, val);
    else Traverse_List_Types_field (Types_struct_type_fields2(me), action, val);
  }
  }
  if (action->action_struct_type[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_struct_type[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_macro (Types_macro me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(macro, me)) return val;
  if (action->action_macro[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_macro[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_macro)
  { switch (Types_macro_tag(me)) {
      case Types_plain_macro_kind:
        if (action->action_plain_macro[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_plain_macro[PRE_ACTION](me, val);
        }
        if (action->action_plain_macro[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_plain_macro[POST_ACTION](me, val);
        }
        break;
      case Types_access_macro_kind:
        if (action->action_access_macro[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_access_macro[PRE_ACTION](me, val);
        }
        if (action->action_access_macro[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_access_macro[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_macro[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_macro[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_field (Types_field me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(field, me)) return val;
  if (action->action_field[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_field[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_field)
  { 
  if (!action->skip_children_field) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_TypeName (Types_field_type(me), action, val);
    else Traverse_List_Types_TypeName (Types_field_type(me), action, val);
  }
  }
  if (action->action_field[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_field[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_TypeName (Types_TypeName me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(TypeName, me)) return val;
  if (action->action_TypeName[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_TypeName[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_TypeName)
  { 
  }
  if (action->action_TypeName[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_TypeName[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_CreateFunction (Types_CreateFunction me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(CreateFunction, me)) return val;
  if (action->action_CreateFunction[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_CreateFunction[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_CreateFunction)
  { 
  if (!action->skip_children_CreateFunction) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_field (Types_CreateFunction_fields(me), action, val);
    else Traverse_List_Types_field (Types_CreateFunction_fields(me), action, val);
  }
  }
  if (action->action_CreateFunction[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_CreateFunction[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Types_Scope (Types_Scope me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(Scope, me)) return val;
  if (action->action_Scope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Scope)
  { switch (Types_Scope_tag(me)) {
      case Types_struct_typeScope_kind:
        if (action->action_struct_typeScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_struct_typeScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Scope) {
          if (action->traversal != Traverse_Down)  val = Traverse_Types_Scope (Types_Scope_next(me), action, val);
          else Traverse_Types_Scope (Types_Scope_next(me), action, val);
        }
        if (!action->skip_children_struct_typeScope) {
          if (action->traversal != Traverse_Down)  val = Traverse_Types_struct_type (Types_struct_typeScope_data(me), action, val);
          else Traverse_Types_struct_type (Types_struct_typeScope_data(me), action, val);
        }
        if (action->action_struct_typeScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_struct_typeScope[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Scope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Types_struct_type (List_Types_struct_type me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(List_struct_type, me)) return val;
  if (action->action_List_struct_type[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_struct_type[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_struct_type)
  { 
  if (!action->skip_children_List_struct_type) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_struct_type (List_Types_struct_type_data(me), action, val);
    else Traverse_Types_struct_type (List_Types_struct_type_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_struct_type (List_Types_struct_type_next(me), action, val);
    else Traverse_List_Types_struct_type (List_Types_struct_type_next(me), action, val);
  }
  }
  if (action->action_List_struct_type[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_struct_type[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Types_field (List_Types_field me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(List_field, me)) return val;
  if (action->action_List_field[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_field[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_field)
  { 
  if (!action->skip_children_List_field) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_field (List_Types_field_data(me), action, val);
    else Traverse_Types_field (List_Types_field_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_field (List_Types_field_next(me), action, val);
    else Traverse_List_Types_field (List_Types_field_next(me), action, val);
  }
  }
  if (action->action_List_field[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_field[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Types_CreateFunction (List_Types_CreateFunction me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(List_CreateFunction, me)) return val;
  if (action->action_List_CreateFunction[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_CreateFunction[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_CreateFunction)
  { 
  if (!action->skip_children_List_CreateFunction) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_CreateFunction (List_Types_CreateFunction_data(me), action, val);
    else Traverse_Types_CreateFunction (List_Types_CreateFunction_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_CreateFunction (List_Types_CreateFunction_next(me), action, val);
    else Traverse_List_Types_CreateFunction (List_Types_CreateFunction_next(me), action, val);
  }
  }
  if (action->action_List_CreateFunction[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_CreateFunction[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Types_macro (List_Types_macro me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(List_macro, me)) return val;
  if (action->action_List_macro[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_macro[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_macro)
  { 
  if (!action->skip_children_List_macro) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_macro (List_Types_macro_data(me), action, val);
    else Traverse_Types_macro (List_Types_macro_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_macro (List_Types_macro_next(me), action, val);
    else Traverse_List_Types_macro (List_Types_macro_next(me), action, val);
  }
  }
  if (action->action_List_macro[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_macro[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Types_TypeName (List_Types_TypeName me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(List_TypeName, me)) return val;
  if (action->action_List_TypeName[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_TypeName[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_TypeName)
  { 
  if (!action->skip_children_List_TypeName) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_TypeName (List_Types_TypeName_data(me), action, val);
    else Traverse_Types_TypeName (List_Types_TypeName_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_TypeName (List_Types_TypeName_next(me), action, val);
    else Traverse_List_Types_TypeName (List_Types_TypeName_next(me), action, val);
  }
  }
  if (action->action_List_TypeName[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_TypeName[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Types_StructType (List_Types_StructType me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(List_StructType, me)) return val;
  if (action->action_List_StructType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_StructType[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_StructType)
  { 
  if (!action->skip_children_List_StructType) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_StructType (List_Types_StructType_data(me), action, val);
    else Traverse_Types_StructType (List_Types_StructType_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_StructType (List_Types_StructType_next(me), action, val);
    else Traverse_List_Types_StructType (List_Types_StructType_next(me), action, val);
  }
  }
  if (action->action_List_StructType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_StructType[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Types_BindType (List_Types_BindType me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(List_BindType, me)) return val;
  if (action->action_List_BindType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_BindType[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_BindType)
  { 
  if (!action->skip_children_List_BindType) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_BindType (List_Types_BindType_data(me), action, val);
    else Traverse_Types_BindType (List_Types_BindType_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_BindType (List_Types_BindType_next(me), action, val);
    else Traverse_List_Types_BindType (List_Types_BindType_next(me), action, val);
  }
  }
  if (action->action_List_BindType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_BindType[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Types_subtypedef (List_Types_subtypedef me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(List_subtypedef, me)) return val;
  if (action->action_List_subtypedef[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_subtypedef[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_subtypedef)
  { 
  if (!action->skip_children_List_subtypedef) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_subtypedef (List_Types_subtypedef_data(me), action, val);
    else Traverse_Types_subtypedef (List_Types_subtypedef_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_subtypedef (List_Types_subtypedef_next(me), action, val);
    else Traverse_List_Types_subtypedef (List_Types_subtypedef_next(me), action, val);
  }
  }
  if (action->action_List_subtypedef[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_subtypedef[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Types_PointerType (List_Types_PointerType me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(List_PointerType, me)) return val;
  if (action->action_List_PointerType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_PointerType[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_PointerType)
  { 
  if (!action->skip_children_List_PointerType) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_PointerType (List_Types_PointerType_data(me), action, val);
    else Traverse_Types_PointerType (List_Types_PointerType_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_PointerType (List_Types_PointerType_next(me), action, val);
    else Traverse_List_Types_PointerType (List_Types_PointerType_next(me), action, val);
  }
  }
  if (action->action_List_PointerType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_PointerType[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Types_EnumType (List_Types_EnumType me, TraverseTable action, Pointer val)
{ 
  if (Types_SKIP_NODE(List_EnumType, me)) return val;
  if (action->action_List_EnumType[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_EnumType[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_EnumType)
  { 
  if (!action->skip_children_List_EnumType) {
    if (action->traversal != Traverse_Down)  val = Traverse_Types_EnumType (List_Types_EnumType_data(me), action, val);
    else Traverse_Types_EnumType (List_Types_EnumType_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Types_EnumType (List_Types_EnumType_next(me), action, val);
    else Traverse_List_Types_EnumType (List_Types_EnumType_next(me), action, val);
  }
  }
  if (action->action_List_EnumType[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_EnumType[POST_ACTION](me, val);
  }
  return val;
}

void Traverse_void_Types_Types (Types_Types me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(Types, me)) return;
  if (action->action_Types[PRE_ACTION] != NULL) {
    action->action_Types[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Types)
  { 
  if (!action->skip_children_Types) {
    Traverse_void_List_Types_EnumType (Types_Types_enums(me), action);
    Traverse_void_List_Types_PointerType (Types_Types_pointers(me), action);
    Traverse_void_List_Types_subtypedef (Types_Types_subs(me), action);
    Traverse_void_Types_includes2 (Types_Types_inc2(me), action);
    Traverse_void_List_Types_subtypedef (Types_Types_impdefs(me), action);
    Traverse_void_List_Types_BindType (Types_Types_binds(me), action);
    Traverse_void_List_Types_StructType (Types_Types_types(me), action);
  }
  }
  if (action->action_Types[POST_ACTION] != NULL) {
    action->action_Types[POST_ACTION](me);
  }
}

void Traverse_void_Types_includes2 (Types_includes2 me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(includes2, me)) return;
  if (action->action_includes2[PRE_ACTION] != NULL) {
    action->action_includes2[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_includes2)
  { 
  }
  if (action->action_includes2[POST_ACTION] != NULL) {
    action->action_includes2[POST_ACTION](me);
  }
}

void Traverse_void_Types_EnumType (Types_EnumType me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(EnumType, me)) return;
  if (action->action_EnumType[PRE_ACTION] != NULL) {
    action->action_EnumType[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_EnumType)
  { 
  if (!action->skip_children_EnumType) {
    Traverse_void_List_Types_TypeName (Types_EnumType_enums(me), action);
  }
  }
  if (action->action_EnumType[POST_ACTION] != NULL) {
    action->action_EnumType[POST_ACTION](me);
  }
}

void Traverse_void_Types_BindType (Types_BindType me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(BindType, me)) return;
  if (action->action_BindType[PRE_ACTION] != NULL) {
    action->action_BindType[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_BindType)
  { 
  }
  if (action->action_BindType[POST_ACTION] != NULL) {
    action->action_BindType[POST_ACTION](me);
  }
}

void Traverse_void_Types_PointerType (Types_PointerType me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(PointerType, me)) return;
  if (action->action_PointerType[PRE_ACTION] != NULL) {
    action->action_PointerType[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_PointerType)
  { 
  if (!action->skip_children_PointerType) {
    Traverse_void_List_Types_subtypedef (Types_PointerType_subs(me), action);
  }
  }
  if (action->action_PointerType[POST_ACTION] != NULL) {
    action->action_PointerType[POST_ACTION](me);
  }
}

void Traverse_void_Types_subtypedef (Types_subtypedef me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(subtypedef, me)) return;
  if (action->action_subtypedef[PRE_ACTION] != NULL) {
    action->action_subtypedef[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_subtypedef)
  { 
  }
  if (action->action_subtypedef[POST_ACTION] != NULL) {
    action->action_subtypedef[POST_ACTION](me);
  }
}

void Traverse_void_Types_StructType (Types_StructType me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(StructType, me)) return;
  if (action->action_StructType[PRE_ACTION] != NULL) {
    action->action_StructType[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_StructType)
  { 
  if (!action->skip_children_StructType) {
    Traverse_void_Types_struct_type (Types_StructType_type(me), action);
    Traverse_void_List_Types_macro (Types_StructType_macros(me), action);
    Traverse_void_List_Types_CreateFunction (Types_StructType_creates(me), action);
  }
  }
  if (action->action_StructType[POST_ACTION] != NULL) {
    action->action_StructType[POST_ACTION](me);
  }
}

void Traverse_void_Types_struct_type (Types_struct_type me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(struct_type, me)) return;
  if (action->action_struct_type[PRE_ACTION] != NULL) {
    action->action_struct_type[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_struct_type)
  { 
  if (!action->skip_children_struct_type) {
    Traverse_void_List_Types_field (Types_struct_type_fields1(me), action);
    Traverse_void_List_Types_struct_type (Types_struct_type_sub_types(me), action);
    Traverse_void_List_Types_field (Types_struct_type_fields2(me), action);
  }
  }
  if (action->action_struct_type[POST_ACTION] != NULL) {
    action->action_struct_type[POST_ACTION](me);
  }
}

void Traverse_void_Types_macro (Types_macro me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(macro, me)) return;
  if (action->action_macro[PRE_ACTION] != NULL) {
    action->action_macro[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_macro)
  { switch (Types_macro_tag(me)) {
      case Types_plain_macro_kind:
        if (action->action_plain_macro[PRE_ACTION] != NULL) {
          action->action_plain_macro[PRE_ACTION](me);
        }
        if (action->action_plain_macro[POST_ACTION] != NULL) {
          action->action_plain_macro[POST_ACTION](me);
        }
        break;
      case Types_access_macro_kind:
        if (action->action_access_macro[PRE_ACTION] != NULL) {
          action->action_access_macro[PRE_ACTION](me);
        }
        if (action->action_access_macro[POST_ACTION] != NULL) {
          action->action_access_macro[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_macro[POST_ACTION] != NULL) {
    action->action_macro[POST_ACTION](me);
  }
}

void Traverse_void_Types_field (Types_field me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(field, me)) return;
  if (action->action_field[PRE_ACTION] != NULL) {
    action->action_field[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_field)
  { 
  if (!action->skip_children_field) {
    Traverse_void_List_Types_TypeName (Types_field_type(me), action);
  }
  }
  if (action->action_field[POST_ACTION] != NULL) {
    action->action_field[POST_ACTION](me);
  }
}

void Traverse_void_Types_TypeName (Types_TypeName me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(TypeName, me)) return;
  if (action->action_TypeName[PRE_ACTION] != NULL) {
    action->action_TypeName[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_TypeName)
  { 
  }
  if (action->action_TypeName[POST_ACTION] != NULL) {
    action->action_TypeName[POST_ACTION](me);
  }
}

void Traverse_void_Types_CreateFunction (Types_CreateFunction me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(CreateFunction, me)) return;
  if (action->action_CreateFunction[PRE_ACTION] != NULL) {
    action->action_CreateFunction[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_CreateFunction)
  { 
  if (!action->skip_children_CreateFunction) {
    Traverse_void_List_Types_field (Types_CreateFunction_fields(me), action);
  }
  }
  if (action->action_CreateFunction[POST_ACTION] != NULL) {
    action->action_CreateFunction[POST_ACTION](me);
  }
}

void Traverse_void_Types_Scope (Types_Scope me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(Scope, me)) return;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    action->action_Scope[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Scope)
  { switch (Types_Scope_tag(me)) {
      case Types_struct_typeScope_kind:
        if (action->action_struct_typeScope[PRE_ACTION] != NULL) {
          action->action_struct_typeScope[PRE_ACTION](me);
        }
        if (!action->skip_children_Scope) {
          Traverse_void_Types_Scope (Types_Scope_next(me), action);
        }
        if (!action->skip_children_struct_typeScope) {
          Traverse_void_Types_struct_type (Types_struct_typeScope_data(me), action);
        }
        if (action->action_struct_typeScope[POST_ACTION] != NULL) {
          action->action_struct_typeScope[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    action->action_Scope[POST_ACTION](me);
  }
}

void Traverse_void_List_Types_struct_type (List_Types_struct_type me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(List_struct_type, me)) return;
  if (action->action_List_struct_type[PRE_ACTION] != NULL) {
    action->action_List_struct_type[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_struct_type)
  { 
  if (!action->skip_children_List_struct_type) {
    Traverse_void_Types_struct_type (List_Types_struct_type_data(me), action);
    Traverse_void_List_Types_struct_type (List_Types_struct_type_next(me), action);
  }
  }
  if (action->action_List_struct_type[POST_ACTION] != NULL) {
    action->action_List_struct_type[POST_ACTION](me);
  }
}

void Traverse_void_List_Types_field (List_Types_field me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(List_field, me)) return;
  if (action->action_List_field[PRE_ACTION] != NULL) {
    action->action_List_field[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_field)
  { 
  if (!action->skip_children_List_field) {
    Traverse_void_Types_field (List_Types_field_data(me), action);
    Traverse_void_List_Types_field (List_Types_field_next(me), action);
  }
  }
  if (action->action_List_field[POST_ACTION] != NULL) {
    action->action_List_field[POST_ACTION](me);
  }
}

void Traverse_void_List_Types_CreateFunction (List_Types_CreateFunction me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(List_CreateFunction, me)) return;
  if (action->action_List_CreateFunction[PRE_ACTION] != NULL) {
    action->action_List_CreateFunction[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_CreateFunction)
  { 
  if (!action->skip_children_List_CreateFunction) {
    Traverse_void_Types_CreateFunction (List_Types_CreateFunction_data(me), action);
    Traverse_void_List_Types_CreateFunction (List_Types_CreateFunction_next(me), action);
  }
  }
  if (action->action_List_CreateFunction[POST_ACTION] != NULL) {
    action->action_List_CreateFunction[POST_ACTION](me);
  }
}

void Traverse_void_List_Types_macro (List_Types_macro me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(List_macro, me)) return;
  if (action->action_List_macro[PRE_ACTION] != NULL) {
    action->action_List_macro[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_macro)
  { 
  if (!action->skip_children_List_macro) {
    Traverse_void_Types_macro (List_Types_macro_data(me), action);
    Traverse_void_List_Types_macro (List_Types_macro_next(me), action);
  }
  }
  if (action->action_List_macro[POST_ACTION] != NULL) {
    action->action_List_macro[POST_ACTION](me);
  }
}

void Traverse_void_List_Types_TypeName (List_Types_TypeName me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(List_TypeName, me)) return;
  if (action->action_List_TypeName[PRE_ACTION] != NULL) {
    action->action_List_TypeName[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_TypeName)
  { 
  if (!action->skip_children_List_TypeName) {
    Traverse_void_Types_TypeName (List_Types_TypeName_data(me), action);
    Traverse_void_List_Types_TypeName (List_Types_TypeName_next(me), action);
  }
  }
  if (action->action_List_TypeName[POST_ACTION] != NULL) {
    action->action_List_TypeName[POST_ACTION](me);
  }
}

void Traverse_void_List_Types_StructType (List_Types_StructType me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(List_StructType, me)) return;
  if (action->action_List_StructType[PRE_ACTION] != NULL) {
    action->action_List_StructType[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_StructType)
  { 
  if (!action->skip_children_List_StructType) {
    Traverse_void_Types_StructType (List_Types_StructType_data(me), action);
    Traverse_void_List_Types_StructType (List_Types_StructType_next(me), action);
  }
  }
  if (action->action_List_StructType[POST_ACTION] != NULL) {
    action->action_List_StructType[POST_ACTION](me);
  }
}

void Traverse_void_List_Types_BindType (List_Types_BindType me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(List_BindType, me)) return;
  if (action->action_List_BindType[PRE_ACTION] != NULL) {
    action->action_List_BindType[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_BindType)
  { 
  if (!action->skip_children_List_BindType) {
    Traverse_void_Types_BindType (List_Types_BindType_data(me), action);
    Traverse_void_List_Types_BindType (List_Types_BindType_next(me), action);
  }
  }
  if (action->action_List_BindType[POST_ACTION] != NULL) {
    action->action_List_BindType[POST_ACTION](me);
  }
}

void Traverse_void_List_Types_subtypedef (List_Types_subtypedef me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(List_subtypedef, me)) return;
  if (action->action_List_subtypedef[PRE_ACTION] != NULL) {
    action->action_List_subtypedef[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_subtypedef)
  { 
  if (!action->skip_children_List_subtypedef) {
    Traverse_void_Types_subtypedef (List_Types_subtypedef_data(me), action);
    Traverse_void_List_Types_subtypedef (List_Types_subtypedef_next(me), action);
  }
  }
  if (action->action_List_subtypedef[POST_ACTION] != NULL) {
    action->action_List_subtypedef[POST_ACTION](me);
  }
}

void Traverse_void_List_Types_PointerType (List_Types_PointerType me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(List_PointerType, me)) return;
  if (action->action_List_PointerType[PRE_ACTION] != NULL) {
    action->action_List_PointerType[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_PointerType)
  { 
  if (!action->skip_children_List_PointerType) {
    Traverse_void_Types_PointerType (List_Types_PointerType_data(me), action);
    Traverse_void_List_Types_PointerType (List_Types_PointerType_next(me), action);
  }
  }
  if (action->action_List_PointerType[POST_ACTION] != NULL) {
    action->action_List_PointerType[POST_ACTION](me);
  }
}

void Traverse_void_List_Types_EnumType (List_Types_EnumType me, void_Types_TraverseTable action)
{ 
  if (Types_SKIP_NODE(List_EnumType, me)) return;
  if (action->action_List_EnumType[PRE_ACTION] != NULL) {
    action->action_List_EnumType[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_EnumType)
  { 
  if (!action->skip_children_List_EnumType) {
    Traverse_void_Types_EnumType (List_Types_EnumType_data(me), action);
    Traverse_void_List_Types_EnumType (List_Types_EnumType_next(me), action);
  }
  }
  if (action->action_List_EnumType[POST_ACTION] != NULL) {
    action->action_List_EnumType[POST_ACTION](me);
  }
}

Types_Types Traverse_copy_Types_Types (Types_Types me, copy_Types_TraverseTable action)
{ Types_Types _new = me, _old = me;
  if (action->action_Types[PRE_ACTION] != NULL) {
    _new = action->action_Types[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_Types)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Types) {
    Types_Types_enums(me) = Traverse_copy_List_Types_EnumType (Types_Types_enums(me), action);
    Types_Types_pointers(me) = Traverse_copy_List_Types_PointerType (Types_Types_pointers(me), action);
    Types_Types_subs(me) = Traverse_copy_List_Types_subtypedef (Types_Types_subs(me), action);
    Types_Types_inc2(me) = Traverse_copy_Types_includes2 (Types_Types_inc2(me), action);
    Types_Types_impdefs(me) = Traverse_copy_List_Types_subtypedef (Types_Types_impdefs(me), action);
    Types_Types_binds(me) = Traverse_copy_List_Types_BindType (Types_Types_binds(me), action);
    Types_Types_types(me) = Traverse_copy_List_Types_StructType (Types_Types_types(me), action);
  }
  }
  if (action->action_Types[POST_ACTION] != NULL) {
    me = action->action_Types[POST_ACTION](me, _old);
  }
  return me;
}

Types_includes2 Traverse_copy_Types_includes2 (Types_includes2 me, copy_Types_TraverseTable action)
{ Types_includes2 _new = me, _old = me;
  if (action->action_includes2[PRE_ACTION] != NULL) {
    _new = action->action_includes2[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_includes2)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_includes2) {
    Types_includes2_uses(me) = Traverse_copy_List_Ident (Types_includes2_uses(me), action);
  }
  }
  if (action->action_includes2[POST_ACTION] != NULL) {
    me = action->action_includes2[POST_ACTION](me, _old);
  }
  return me;
}

Types_EnumType Traverse_copy_Types_EnumType (Types_EnumType me, copy_Types_TraverseTable action)
{ Types_EnumType _new = me, _old = me;
  if (action->action_EnumType[PRE_ACTION] != NULL) {
    _new = action->action_EnumType[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_EnumType)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_EnumType) {
    Types_EnumType_enums(me) = Traverse_copy_List_Types_TypeName (Types_EnumType_enums(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Types_EnumType_is_tag(me) = FALSE;
      Types_EnumType_str_type(me) = NULL;
      Types_EnumType_name(me) = EnumType_id (me);
      enum_set_name (me);
    }
  }
  if (action->action_EnumType[POST_ACTION] != NULL) {
    me = action->action_EnumType[POST_ACTION](me, _old);
  }
  return me;
}

Types_BindType Traverse_copy_Types_BindType (Types_BindType me, copy_Types_TraverseTable action)
{ Types_BindType _new = me, _old = me;
  if (action->action_BindType[PRE_ACTION] != NULL) {
    _new = action->action_BindType[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_BindType)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Types_BindType_abbrev(me) = NULL;
    }
  }
  if (action->action_BindType[POST_ACTION] != NULL) {
    me = action->action_BindType[POST_ACTION](me, _old);
  }
  return me;
}

Types_PointerType Traverse_copy_Types_PointerType (Types_PointerType me, copy_Types_TraverseTable action)
{ Types_PointerType _new = me, _old = me;
  if (action->action_PointerType[PRE_ACTION] != NULL) {
    _new = action->action_PointerType[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_PointerType)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_PointerType) {
    Types_PointerType_subs(me) = Traverse_copy_List_Types_subtypedef (Types_PointerType_subs(me), action);
  }
  }
  if (action->action_PointerType[POST_ACTION] != NULL) {
    me = action->action_PointerType[POST_ACTION](me, _old);
  }
  return me;
}

Types_subtypedef Traverse_copy_Types_subtypedef (Types_subtypedef me, copy_Types_TraverseTable action)
{ Types_subtypedef _new = me, _old = me;
  if (action->action_subtypedef[PRE_ACTION] != NULL) {
    _new = action->action_subtypedef[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_subtypedef)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  }
  if (action->action_subtypedef[POST_ACTION] != NULL) {
    me = action->action_subtypedef[POST_ACTION](me, _old);
  }
  return me;
}

Types_StructType Traverse_copy_Types_StructType (Types_StructType me, copy_Types_TraverseTable action)
{ Types_StructType _new = me, _old = me;
  if (action->action_StructType[PRE_ACTION] != NULL) {
    _new = action->action_StructType[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_StructType)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_StructType) {
    Types_StructType_type(me) = Traverse_copy_Types_struct_type (Types_StructType_type(me), action);
    Types_StructType_macros(me) = Traverse_copy_List_Types_macro (Types_StructType_macros(me), action);
    Types_StructType_creates(me) = Traverse_copy_List_Types_CreateFunction (Types_StructType_creates(me), action);
  }
  }
  if (action->action_StructType[POST_ACTION] != NULL) {
    me = action->action_StructType[POST_ACTION](me, _old);
  }
  return me;
}

Types_struct_type Traverse_copy_Types_struct_type (Types_struct_type me, copy_Types_TraverseTable action)
{ Types_struct_type _new = me, _old = me;
  if (action->action_struct_type[PRE_ACTION] != NULL) {
    _new = action->action_struct_type[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_struct_type)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_struct_type) {
    Types_struct_type_fields1(me) = Traverse_copy_List_Types_field (Types_struct_type_fields1(me), action);
    Types_struct_type_sub_types(me) = Traverse_copy_List_Types_struct_type (Types_struct_type_sub_types(me), action);
    Types_struct_type_fields2(me) = Traverse_copy_List_Types_field (Types_struct_type_fields2(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Types_struct_type_scope(me) = NULL;
      Types_struct_type_old_scope(me) = NULL;
      Types_struct_type_name(me) = struct_type_tag (me);
      Types_struct_type_checks(me) = NULL;
      Types_struct_type_is_list(me) = FALSE;
      Types_struct_type_is_bind(me) = FALSE;
      Types_struct_type_is_optional(me) = FALSE;
      Types_struct_type_is_scope(me) = FALSE;
      Types_struct_type_uses_scope(me) = FALSE;
      Types_struct_type_opens_scope(me) = FALSE;
      Types_struct_type_closes_scope(me) = FALSE;
      Types_struct_type_in_lib(me) = FALSE;
      Types_struct_type_alt(me) = NULL;
      Types_struct_type_create(me) = NULL;
      Types_struct_type_enumtype(me) = NULL;
      set_name (me);
    }
  }
  if (action->action_struct_type[POST_ACTION] != NULL) {
    me = action->action_struct_type[POST_ACTION](me, _old);
  }
  return me;
}

Types_macro Traverse_copy_Types_macro (Types_macro me, copy_Types_TraverseTable action)
{ Types_macro _new = me, _old = me;
  if (action->action_macro[PRE_ACTION] != NULL) {
    _new = action->action_macro[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_macro)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (Types_macro_tag(me)) {
      case Types_plain_macro_kind:
        if (action->action_plain_macro[PRE_ACTION] != NULL) {
          _new = action->action_plain_macro[PRE_ACTION](me, me);
        }
        if (!action->skip_children_macro) {
          Types_macro_types(me) = Traverse_copy_List_Ident (Types_macro_types(me), action);
        }
        if (action->action_plain_macro[POST_ACTION] != NULL) {
          _new = action->action_plain_macro[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Types_access_macro_kind:
        if (action->action_access_macro[PRE_ACTION] != NULL) {
          _new = action->action_access_macro[PRE_ACTION](me, me);
        }
        if (!action->skip_children_macro) {
          Types_macro_types(me) = Traverse_copy_List_Ident (Types_macro_types(me), action);
        }
        if (action->action_access_macro[POST_ACTION] != NULL) {
          _new = action->action_access_macro[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_macro[POST_ACTION] != NULL) {
    me = action->action_macro[POST_ACTION](me, _old);
  }
  return me;
}

Types_field Traverse_copy_Types_field (Types_field me, copy_Types_TraverseTable action)
{ Types_field _new = me, _old = me;
  if (action->action_field[PRE_ACTION] != NULL) {
    _new = action->action_field[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_field)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_field) {
    Types_field_type(me) = Traverse_copy_List_Types_TypeName (Types_field_type(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Types_field_grammar_id(me) = NULL;
      Types_field_uses_scope(me) = FALSE;
      Types_field_is_defining(me) = NULL;
      Types_field_is_applied(me) = NULL;
      Types_field_applied_id(me) = NULL;
      Types_field_is_tag(me) = FALSE;
      Types_field_init(me) = NULL;
      Types_field_trav(me) = FALSE;
      Types_field_clear(me) = FALSE;
      Types_field_dont_clear(me) = FALSE;
      Types_field_compare(me) = NULL;
    }
  }
  if (action->action_field[POST_ACTION] != NULL) {
    me = action->action_field[POST_ACTION](me, _old);
  }
  return me;
}

Types_TypeName Traverse_copy_Types_TypeName (Types_TypeName me, copy_Types_TraverseTable action)
{ Types_TypeName _new = me, _old = me;
  if (action->action_TypeName[PRE_ACTION] != NULL) {
    _new = action->action_TypeName[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_TypeName)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Types_TypeName_scope(me) = NULL;
      Types_TypeName_old_scope(me) = NULL;
      Types_TypeName_type_bind(me) = NULL;
      Types_TypeName_type(me) = NULL;
      Types_TypeName_id(me) = TypeName_full (me);
    }
  }
  if (action->action_TypeName[POST_ACTION] != NULL) {
    me = action->action_TypeName[POST_ACTION](me, _old);
  }
  return me;
}

Types_CreateFunction Traverse_copy_Types_CreateFunction (Types_CreateFunction me, copy_Types_TraverseTable action)
{ Types_CreateFunction _new = me, _old = me;
  if (action->action_CreateFunction[PRE_ACTION] != NULL) {
    _new = action->action_CreateFunction[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_CreateFunction)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_CreateFunction) {
    Types_CreateFunction_fields(me) = Traverse_copy_List_Types_field (Types_CreateFunction_fields(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      Types_CreateFunction_type(me) = NULL;
    }
  }
  if (action->action_CreateFunction[POST_ACTION] != NULL) {
    me = action->action_CreateFunction[POST_ACTION](me, _old);
  }
  return me;
}

Types_Scope Traverse_copy_Types_Scope (Types_Scope me, copy_Types_TraverseTable action)
{ Types_Scope _new = me, _old = me;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    _new = action->action_Scope[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Types_Scope)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (Types_Scope_tag(me)) {
      case Types_struct_typeScope_kind:
        if (action->action_struct_typeScope[PRE_ACTION] != NULL) {
          _new = action->action_struct_typeScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Scope) {
          Types_Scope_next(me) = Traverse_copy_Types_Scope (Types_Scope_next(me), action);
        }
        if (!action->skip_children_struct_typeScope) {
          Types_struct_typeScope_data(me) = Traverse_copy_Types_struct_type (Types_struct_typeScope_data(me), action);
        }
        if (action->action_struct_typeScope[POST_ACTION] != NULL) {
          _new = action->action_struct_typeScope[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    me = action->action_Scope[POST_ACTION](me, _old);
  }
  return me;
}

List_Types_struct_type Traverse_copy_List_Types_struct_type (List_Types_struct_type me, copy_Types_TraverseTable action)
{ List_Types_struct_type _new = me, _old = me;
  if (action->action_List_struct_type[PRE_ACTION] != NULL) {
    _new = action->action_List_struct_type[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Types_struct_type)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_struct_type) {
    List_Types_struct_type_data(me) = Traverse_copy_Types_struct_type (List_Types_struct_type_data(me), action);
    List_Types_struct_type_next(me) = Traverse_copy_List_Types_struct_type (List_Types_struct_type_next(me), action);
  }
  }
  if (action->action_List_struct_type[POST_ACTION] != NULL) {
    me = action->action_List_struct_type[POST_ACTION](me, _old);
  }
  return me;
}

List_Types_field Traverse_copy_List_Types_field (List_Types_field me, copy_Types_TraverseTable action)
{ List_Types_field _new = me, _old = me;
  if (action->action_List_field[PRE_ACTION] != NULL) {
    _new = action->action_List_field[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Types_field)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_field) {
    List_Types_field_data(me) = Traverse_copy_Types_field (List_Types_field_data(me), action);
    List_Types_field_next(me) = Traverse_copy_List_Types_field (List_Types_field_next(me), action);
  }
  }
  if (action->action_List_field[POST_ACTION] != NULL) {
    me = action->action_List_field[POST_ACTION](me, _old);
  }
  return me;
}

List_Types_CreateFunction Traverse_copy_List_Types_CreateFunction (List_Types_CreateFunction me, copy_Types_TraverseTable action)
{ List_Types_CreateFunction _new = me, _old = me;
  if (action->action_List_CreateFunction[PRE_ACTION] != NULL) {
    _new = action->action_List_CreateFunction[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Types_CreateFunction)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_CreateFunction) {
    List_Types_CreateFunction_data(me) = Traverse_copy_Types_CreateFunction (List_Types_CreateFunction_data(me), action);
    List_Types_CreateFunction_next(me) = Traverse_copy_List_Types_CreateFunction (List_Types_CreateFunction_next(me), action);
  }
  }
  if (action->action_List_CreateFunction[POST_ACTION] != NULL) {
    me = action->action_List_CreateFunction[POST_ACTION](me, _old);
  }
  return me;
}

List_Types_macro Traverse_copy_List_Types_macro (List_Types_macro me, copy_Types_TraverseTable action)
{ List_Types_macro _new = me, _old = me;
  if (action->action_List_macro[PRE_ACTION] != NULL) {
    _new = action->action_List_macro[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Types_macro)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_macro) {
    List_Types_macro_data(me) = Traverse_copy_Types_macro (List_Types_macro_data(me), action);
    List_Types_macro_next(me) = Traverse_copy_List_Types_macro (List_Types_macro_next(me), action);
  }
  }
  if (action->action_List_macro[POST_ACTION] != NULL) {
    me = action->action_List_macro[POST_ACTION](me, _old);
  }
  return me;
}

List_Types_TypeName Traverse_copy_List_Types_TypeName (List_Types_TypeName me, copy_Types_TraverseTable action)
{ List_Types_TypeName _new = me, _old = me;
  if (action->action_List_TypeName[PRE_ACTION] != NULL) {
    _new = action->action_List_TypeName[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Types_TypeName)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_TypeName) {
    List_Types_TypeName_data(me) = Traverse_copy_Types_TypeName (List_Types_TypeName_data(me), action);
    List_Types_TypeName_next(me) = Traverse_copy_List_Types_TypeName (List_Types_TypeName_next(me), action);
  }
  }
  if (action->action_List_TypeName[POST_ACTION] != NULL) {
    me = action->action_List_TypeName[POST_ACTION](me, _old);
  }
  return me;
}

List_Types_StructType Traverse_copy_List_Types_StructType (List_Types_StructType me, copy_Types_TraverseTable action)
{ List_Types_StructType _new = me, _old = me;
  if (action->action_List_StructType[PRE_ACTION] != NULL) {
    _new = action->action_List_StructType[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Types_StructType)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_StructType) {
    List_Types_StructType_data(me) = Traverse_copy_Types_StructType (List_Types_StructType_data(me), action);
    List_Types_StructType_next(me) = Traverse_copy_List_Types_StructType (List_Types_StructType_next(me), action);
  }
  }
  if (action->action_List_StructType[POST_ACTION] != NULL) {
    me = action->action_List_StructType[POST_ACTION](me, _old);
  }
  return me;
}

List_Types_BindType Traverse_copy_List_Types_BindType (List_Types_BindType me, copy_Types_TraverseTable action)
{ List_Types_BindType _new = me, _old = me;
  if (action->action_List_BindType[PRE_ACTION] != NULL) {
    _new = action->action_List_BindType[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Types_BindType)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_BindType) {
    List_Types_BindType_data(me) = Traverse_copy_Types_BindType (List_Types_BindType_data(me), action);
    List_Types_BindType_next(me) = Traverse_copy_List_Types_BindType (List_Types_BindType_next(me), action);
  }
  }
  if (action->action_List_BindType[POST_ACTION] != NULL) {
    me = action->action_List_BindType[POST_ACTION](me, _old);
  }
  return me;
}

List_Types_subtypedef Traverse_copy_List_Types_subtypedef (List_Types_subtypedef me, copy_Types_TraverseTable action)
{ List_Types_subtypedef _new = me, _old = me;
  if (action->action_List_subtypedef[PRE_ACTION] != NULL) {
    _new = action->action_List_subtypedef[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Types_subtypedef)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_subtypedef) {
    List_Types_subtypedef_data(me) = Traverse_copy_Types_subtypedef (List_Types_subtypedef_data(me), action);
    List_Types_subtypedef_next(me) = Traverse_copy_List_Types_subtypedef (List_Types_subtypedef_next(me), action);
  }
  }
  if (action->action_List_subtypedef[POST_ACTION] != NULL) {
    me = action->action_List_subtypedef[POST_ACTION](me, _old);
  }
  return me;
}

List_Types_PointerType Traverse_copy_List_Types_PointerType (List_Types_PointerType me, copy_Types_TraverseTable action)
{ List_Types_PointerType _new = me, _old = me;
  if (action->action_List_PointerType[PRE_ACTION] != NULL) {
    _new = action->action_List_PointerType[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Types_PointerType)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_PointerType) {
    List_Types_PointerType_data(me) = Traverse_copy_Types_PointerType (List_Types_PointerType_data(me), action);
    List_Types_PointerType_next(me) = Traverse_copy_List_Types_PointerType (List_Types_PointerType_next(me), action);
  }
  }
  if (action->action_List_PointerType[POST_ACTION] != NULL) {
    me = action->action_List_PointerType[POST_ACTION](me, _old);
  }
  return me;
}

List_Types_EnumType Traverse_copy_List_Types_EnumType (List_Types_EnumType me, copy_Types_TraverseTable action)
{ List_Types_EnumType _new = me, _old = me;
  if (action->action_List_EnumType[PRE_ACTION] != NULL) {
    _new = action->action_List_EnumType[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Types_EnumType)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_EnumType) {
    List_Types_EnumType_data(me) = Traverse_copy_Types_EnumType (List_Types_EnumType_data(me), action);
    List_Types_EnumType_next(me) = Traverse_copy_List_Types_EnumType (List_Types_EnumType_next(me), action);
  }
  }
  if (action->action_List_EnumType[POST_ACTION] != NULL) {
    me = action->action_List_EnumType[POST_ACTION](me, _old);
  }
  return me;
}

int Traverse_compare_Types_Types (Types_Types x, Types_Types y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_Types[PRE_ACTION] != NULL) {
    return action->action_Types[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Types) {
    if ((comp = Traverse_compare_List_Types_EnumType (Types_Types_enums(x),Types_Types_enums(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_PointerType (Types_Types_pointers(x),Types_Types_pointers(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_subtypedef (Types_Types_subs(x),Types_Types_subs(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Types_includes2 (Types_Types_inc2(x),Types_Types_inc2(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_subtypedef (Types_Types_impdefs(x),Types_Types_impdefs(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_BindType (Types_Types_binds(x),Types_Types_binds(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_Types_r1(x),Types_Types_r1(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_Types_r2(x),Types_Types_r2(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_StructType (Types_Types_types(x),Types_Types_types(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_includes2 (Types_includes2 x, Types_includes2 y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_includes2[PRE_ACTION] != NULL) {
    return action->action_includes2[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_includes2) {
    if ((comp = Traverse_compare_Ident (Types_includes2_id1(x),Types_includes2_id1(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_includes2_id2(x),Types_includes2_id2(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Ident (Types_includes2_uses(x),Types_includes2_uses(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_EnumType (Types_EnumType x, Types_EnumType y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_EnumType[PRE_ACTION] != NULL) {
    return action->action_EnumType[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_EnumType) {
    if ((comp = Traverse_compare_List_Types_TypeName (Types_EnumType_enums(x),Types_EnumType_enums(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_EnumType_id(x),Types_EnumType_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_EnumType_str(x),Types_EnumType_str(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_EnumType_tag(x),Types_EnumType_tag(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Int (Types_EnumType_num(x),Types_EnumType_num(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_BindType (Types_BindType x, Types_BindType y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_BindType[PRE_ACTION] != NULL) {
    return action->action_BindType[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_BindType) {
    if ((comp = Traverse_compare_Ident (Types_BindType_id1(x),Types_BindType_id1(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_BindType_id2(x),Types_BindType_id2(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_BindType_id3(x),Types_BindType_id3(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_BindType_id4(x),Types_BindType_id4(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_BindType_id5(x),Types_BindType_id5(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_BindType_id6(x),Types_BindType_id6(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_BindType_id7(x),Types_BindType_id7(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Int (Types_BindType_num(x),Types_BindType_num(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_PointerType (Types_PointerType x, Types_PointerType y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_PointerType[PRE_ACTION] != NULL) {
    return action->action_PointerType[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_PointerType) {
    if ((comp = Traverse_compare_Ident (Types_PointerType_id1(x),Types_PointerType_id1(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_PointerType_id2(x),Types_PointerType_id2(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_PointerType_id3(x),Types_PointerType_id3(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_PointerType_id(x),Types_PointerType_id(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_subtypedef (Types_PointerType_subs(x),Types_PointerType_subs(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_subtypedef (Types_subtypedef x, Types_subtypedef y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_subtypedef[PRE_ACTION] != NULL) {
    return action->action_subtypedef[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_subtypedef) {
    if ((comp = Traverse_compare_Ident (Types_subtypedef_super(x),Types_subtypedef_super(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_subtypedef_id(x),Types_subtypedef_id(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_StructType (Types_StructType x, Types_StructType y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_StructType[PRE_ACTION] != NULL) {
    return action->action_StructType[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_StructType) {
    if ((comp = Traverse_compare_Ident (Types_StructType_id1(x),Types_StructType_id1(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_StructType_id2(x),Types_StructType_id2(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Types_struct_type (Types_StructType_type(x),Types_StructType_type(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_macro (Types_StructType_macros(x),Types_StructType_macros(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_CreateFunction (Types_StructType_creates(x),Types_StructType_creates(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_StructType_id3(x),Types_StructType_id3(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_struct_type (Types_struct_type x, Types_struct_type y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_struct_type[PRE_ACTION] != NULL) {
    return action->action_struct_type[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_struct_type) {
    if ((comp = Traverse_compare_Ident (Types_struct_type_tag(x),Types_struct_type_tag(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_struct_type_user(x),Types_struct_type_user(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_field (Types_struct_type_fields1(x),Types_struct_type_fields1(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_struct_type (Types_struct_type_sub_types(x),Types_struct_type_sub_types(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_field (Types_struct_type_fields2(x),Types_struct_type_fields2(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_struct_type_id(x),Types_struct_type_id(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_macro (Types_macro x, Types_macro y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_macro[PRE_ACTION] != NULL) {
    return action->action_macro[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (Types_macro_tag(x) < Types_macro_tag(y)) return -1;
  if (Types_macro_tag(x) > Types_macro_tag(y)) return 1;;
  switch (Types_macro_tag(x)) {
      case Types_plain_macro_kind:
        if (action->action_plain_macro[PRE_ACTION] != NULL) {
          return action->action_plain_macro[PRE_ACTION](x, y);
        }
        if (!action->skip_children_macro) {
          if ((comp = Traverse_compare_Ident (Types_macro_type(x),Types_macro_type(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (Types_macro_id(x),Types_macro_id(y), action)) != 0) return comp;
        }
        if (!action->skip_children_macro) {
          if ((comp = Traverse_compare_List_Ident (Types_macro_types(x),Types_macro_types(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (Types_macro_f(x),Types_macro_f(y), action)) != 0) return comp;
        }
        if (action->action_plain_macro[POST_ACTION] != NULL) {
          return action->action_plain_macro[POST_ACTION](x, y);
        }
        break;
      case Types_access_macro_kind:
        if (action->action_access_macro[PRE_ACTION] != NULL) {
          return action->action_access_macro[PRE_ACTION](x, y);
        }
        if (!action->skip_children_macro) {
          if ((comp = Traverse_compare_Ident (Types_macro_type(x),Types_macro_type(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (Types_macro_id(x),Types_macro_id(y), action)) != 0) return comp;
        }
        if (!action->skip_children_access_macro) {
          if ((comp = Traverse_compare_Ident (Types_access_macro_r(x),Types_access_macro_r(y), action)) != 0) return comp;
        }
        if (!action->skip_children_macro) {
          if ((comp = Traverse_compare_List_Ident (Types_macro_types(x),Types_macro_types(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (Types_macro_f(x),Types_macro_f(y), action)) != 0) return comp;
        }
        if (action->action_access_macro[POST_ACTION] != NULL) {
          return action->action_access_macro[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_Types_field (Types_field x, Types_field y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_field[PRE_ACTION] != NULL) {
    return action->action_field[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_field) {
    if ((comp = Traverse_compare_List_Types_TypeName (Types_field_type(x),Types_field_type(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_Ident (Types_field_id(x),Types_field_id(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_TypeName (Types_TypeName x, Types_TypeName y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_TypeName[PRE_ACTION] != NULL) {
    return action->action_TypeName[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_TypeName) {
    if ((comp = Traverse_compare_Ident (Types_TypeName_full(x),Types_TypeName_full(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_CreateFunction (Types_CreateFunction x, Types_CreateFunction y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_CreateFunction[PRE_ACTION] != NULL) {
    return action->action_CreateFunction[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_CreateFunction) {
    if ((comp = Traverse_compare_List_Types_field (Types_CreateFunction_fields(x),Types_CreateFunction_fields(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Types_Scope (Types_Scope x, Types_Scope y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    return action->action_Scope[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (Types_Scope_tag(x) < Types_Scope_tag(y)) return -1;
  if (Types_Scope_tag(x) > Types_Scope_tag(y)) return 1;;
  switch (Types_Scope_tag(x)) {
      case Types_struct_typeScope_kind:
        if (action->action_struct_typeScope[PRE_ACTION] != NULL) {
          return action->action_struct_typeScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Scope) {
          if ((comp = Traverse_compare_Types_Scope (Types_Scope_next(x),Types_Scope_next(y), action)) != 0) return comp;
        }
        if (!action->skip_children_struct_typeScope) {
          if ((comp = Traverse_compare_Types_struct_type (Types_struct_typeScope_data(x),Types_struct_typeScope_data(y), action)) != 0) return comp;
        }
        if (action->action_struct_typeScope[POST_ACTION] != NULL) {
          return action->action_struct_typeScope[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_List_Types_struct_type (List_Types_struct_type x, List_Types_struct_type y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_List_struct_type[PRE_ACTION] != NULL) {
    return action->action_List_struct_type[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_struct_type) {
    if ((comp = Traverse_compare_Types_struct_type (List_Types_struct_type_data(x),List_Types_struct_type_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_struct_type (List_Types_struct_type_next(x),List_Types_struct_type_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Types_field (List_Types_field x, List_Types_field y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_List_field[PRE_ACTION] != NULL) {
    return action->action_List_field[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_field) {
    if ((comp = Traverse_compare_Types_field (List_Types_field_data(x),List_Types_field_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_field (List_Types_field_next(x),List_Types_field_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Types_CreateFunction (List_Types_CreateFunction x, List_Types_CreateFunction y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_List_CreateFunction[PRE_ACTION] != NULL) {
    return action->action_List_CreateFunction[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_CreateFunction) {
    if ((comp = Traverse_compare_Types_CreateFunction (List_Types_CreateFunction_data(x),List_Types_CreateFunction_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_CreateFunction (List_Types_CreateFunction_next(x),List_Types_CreateFunction_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Types_macro (List_Types_macro x, List_Types_macro y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_List_macro[PRE_ACTION] != NULL) {
    return action->action_List_macro[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_macro) {
    if ((comp = Traverse_compare_Types_macro (List_Types_macro_data(x),List_Types_macro_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_macro (List_Types_macro_next(x),List_Types_macro_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Types_TypeName (List_Types_TypeName x, List_Types_TypeName y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_List_TypeName[PRE_ACTION] != NULL) {
    return action->action_List_TypeName[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_TypeName) {
    if ((comp = Traverse_compare_Types_TypeName (List_Types_TypeName_data(x),List_Types_TypeName_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_TypeName (List_Types_TypeName_next(x),List_Types_TypeName_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Types_StructType (List_Types_StructType x, List_Types_StructType y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_List_StructType[PRE_ACTION] != NULL) {
    return action->action_List_StructType[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_StructType) {
    if ((comp = Traverse_compare_Types_StructType (List_Types_StructType_data(x),List_Types_StructType_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_StructType (List_Types_StructType_next(x),List_Types_StructType_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Types_BindType (List_Types_BindType x, List_Types_BindType y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_List_BindType[PRE_ACTION] != NULL) {
    return action->action_List_BindType[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_BindType) {
    if ((comp = Traverse_compare_Types_BindType (List_Types_BindType_data(x),List_Types_BindType_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_BindType (List_Types_BindType_next(x),List_Types_BindType_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Types_subtypedef (List_Types_subtypedef x, List_Types_subtypedef y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_List_subtypedef[PRE_ACTION] != NULL) {
    return action->action_List_subtypedef[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_subtypedef) {
    if ((comp = Traverse_compare_Types_subtypedef (List_Types_subtypedef_data(x),List_Types_subtypedef_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_subtypedef (List_Types_subtypedef_next(x),List_Types_subtypedef_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Types_PointerType (List_Types_PointerType x, List_Types_PointerType y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_List_PointerType[PRE_ACTION] != NULL) {
    return action->action_List_PointerType[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_PointerType) {
    if ((comp = Traverse_compare_Types_PointerType (List_Types_PointerType_data(x),List_Types_PointerType_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_PointerType (List_Types_PointerType_next(x),List_Types_PointerType_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Types_EnumType (List_Types_EnumType x, List_Types_EnumType y, compare_Types_TraverseTable action)
{ int comp = 0;
  if (action->action_List_EnumType[PRE_ACTION] != NULL) {
    return action->action_List_EnumType[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_EnumType) {
    if ((comp = Traverse_compare_Types_EnumType (List_Types_EnumType_data(x),List_Types_EnumType_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Types_EnumType (List_Types_EnumType_next(x),List_Types_EnumType_next(y), action)) != 0) return comp;
  }
  return comp;
}

static void* PushScope_Types_struct_type (Types_struct_type me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (Types_Scope) val;
  if (Types_struct_type_scope(me) != NULL &&
      Types_Scope_next(Types_struct_type_scope(me))==(Types_Scope)val &&
      struct_typeScope_data(Types_struct_type_scope(me)) == me)
       val = Types_struct_type_scope(me);
  else {
    val = (void*)Create_struct_typeScope ((Types_Scope)val, me);
  }
  Types_struct_type_scope(me) = (Types_Scope) val;
  return val;
}

static void* PopScope_Types_struct_type (Types_struct_type me, void *val)
{ if (me == NULL) return val;
  val = (void*)me->old_scope;
  return val;
}

static void* PushScope_Types_TypeName (Types_TypeName me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (Types_Scope) val;
  Types_TypeName_scope(me) = (Types_Scope) val;
  return val;
}

struct s_Types_TraverseTable Types_scope_actions = {

  Traverse_Accumulate,
  { NULL,	NULL }, FALSE,	/* Types_Types */
  { NULL,	NULL }, FALSE,	/* Types_includes2 */
  { NULL,	NULL }, FALSE,	/* Types_EnumType */
  { NULL,	NULL }, FALSE,	/* Types_BindType */
  { NULL,	NULL }, FALSE,	/* Types_PointerType */
  { NULL,	NULL }, FALSE,	/* Types_subtypedef */
  { NULL,	NULL }, FALSE,	/* Types_StructType */
  { PopScope_Types_struct_type,	PushScope_Types_struct_type }, FALSE,	/* Types_struct_type */
  { NULL,	NULL }, FALSE,	/* Types_macro */
  { NULL,	NULL }, FALSE,	/* Types_plain_macro */
  { NULL,	NULL }, FALSE,	/* Types_access_macro */
  { NULL,	NULL }, FALSE,	/* Types_field */
  { NULL,	PushScope_Types_TypeName }, FALSE,	/* Types_TypeName */
  { NULL,	NULL }, FALSE,	/* Types_CreateFunction */
  { NULL,	NULL }, FALSE,	/* Types_Scope */
  { NULL,	NULL }, FALSE,	/* Types_struct_typeScope */
  { NULL,	NULL }, FALSE,	/* List_Types_struct_type */
  { NULL,	NULL }, FALSE,	/* List_Types_field */
  { NULL,	NULL }, FALSE,	/* List_Types_CreateFunction */
  { NULL,	NULL }, FALSE,	/* List_Types_macro */
  { NULL,	NULL }, FALSE,	/* List_Types_TypeName */
  { NULL,	NULL }, FALSE,	/* List_Types_StructType */
  { NULL,	NULL }, FALSE,	/* List_Types_BindType */
  { NULL,	NULL }, FALSE,	/* List_Types_subtypedef */
  { NULL,	NULL }, FALSE,	/* List_Types_PointerType */
  { NULL,	NULL }, FALSE,	/* List_Types_EnumType */
};

static void Defining_Types_Types (Types_Types me)
{
  if (me==NULL) return;
}

static void Defining_Types_includes2 (Types_includes2 me)
{
  if (me==NULL) return;
}

static void Defining_Types_EnumType (Types_EnumType me)
{
  if (me==NULL) return;
}

static void Defining_Types_BindType (Types_BindType me)
{
  if (me==NULL) return;
}

static void Defining_Types_PointerType (Types_PointerType me)
{
  if (me==NULL) return;
}

static void Defining_Types_subtypedef (Types_subtypedef me)
{
  if (me==NULL) return;
}

static void Defining_Types_StructType (Types_StructType me)
{
  if (me==NULL) return;
}

static void Defining_Types_struct_type (Types_struct_type me)
{
  Scope scope;
  if (me==NULL) return;
  Scope__self (Types_struct_type_scope(me)) = Scope_Num_Stores (Types_struct_type_old_scope(me));
  scope = NULL;
  Types_struct_type__num(me) = Scope_Num_Stores (scope);
  Types_struct_type_tag_bind(me) = ReplaceBind (Types_struct_type_tag_bind(me), Types_struct_type_tag(me), scope, Bind_Types_struct_type_kind, me, Types_DefaultNameSpace, FALSE, FALSE, FALSE);
}

static void Defining_Types_macro (Types_macro me)
{
  if (me==NULL) return;
}

static void Defining_Types_field (Types_field me)
{
  if (me==NULL) return;
}

static void Defining_Types_TypeName (Types_TypeName me)
{
  Scope scope;
  if (me==NULL) return;
  scope = Types_TypeName_scope(me);
  Types_TypeName__num(me) = Scope_Num_Stores (scope);
}

static void Defining_Types_CreateFunction (Types_CreateFunction me)
{
  if (me==NULL) return;
}

struct s_void_Types_TraverseTable Types_defining_actions = {

  { NULL,	(void*)Defining_Types_Types }, FALSE,	/* Types_Types */
  { NULL,	(void*)Defining_Types_includes2 }, FALSE,	/* Types_includes2 */
  { NULL,	(void*)Defining_Types_EnumType }, FALSE,	/* Types_EnumType */
  { NULL,	(void*)Defining_Types_BindType }, FALSE,	/* Types_BindType */
  { NULL,	(void*)Defining_Types_PointerType }, FALSE,	/* Types_PointerType */
  { NULL,	(void*)Defining_Types_subtypedef }, FALSE,	/* Types_subtypedef */
  { NULL,	(void*)Defining_Types_StructType }, FALSE,	/* Types_StructType */
  { NULL,	(void*)Defining_Types_struct_type }, FALSE,	/* Types_struct_type */
  { NULL,	(void*)Defining_Types_macro }, FALSE,	/* Types_macro */
  { NULL,	NULL }, FALSE,	/* Types_plain_macro */
  { NULL,	NULL }, FALSE,	/* Types_access_macro */
  { NULL,	(void*)Defining_Types_field }, FALSE,	/* Types_field */
  { NULL,	(void*)Defining_Types_TypeName }, FALSE,	/* Types_TypeName */
  { NULL,	(void*)Defining_Types_CreateFunction }, FALSE,	/* Types_CreateFunction */
  { NULL,	NULL }, FALSE,	/* Types_Scope */
  { NULL,	NULL }, FALSE,	/* Types_struct_typeScope */
  { NULL,	NULL }, FALSE,	/* List_Types_struct_type */
  { NULL,	NULL }, FALSE,	/* List_Types_field */
  { NULL,	NULL }, FALSE,	/* List_Types_CreateFunction */
  { NULL,	NULL }, FALSE,	/* List_Types_macro */
  { NULL,	NULL }, FALSE,	/* List_Types_TypeName */
  { NULL,	NULL }, FALSE,	/* List_Types_StructType */
  { NULL,	NULL }, FALSE,	/* List_Types_BindType */
  { NULL,	NULL }, FALSE,	/* List_Types_subtypedef */
  { NULL,	NULL }, FALSE,	/* List_Types_PointerType */
  { NULL,	NULL }, FALSE,	/* List_Types_EnumType */
};

static void Retrieve_Types_TypeName (Types_TypeName me)
{ if (me==NULL) return;
  if (Types_TypeName_full(me) != NULL) {
    Types_TypeName_type_bind(me) = RetrieveBind (Types_TypeName_full(me), Types_TypeName_scope(me), Types_TypeName__num(me), Types_DefaultNameSpace, Bind_Types_struct_type_kind);
    Types_TypeName_type(me) = NULL;
    if (Types_TypeName_type_bind(me) != NULL)
      Types_TypeName_type(me) = (Types_struct_type)Bind_object(Types_TypeName_type_bind(me));
  }
}

struct s_void_Types_TraverseTable Types_applied_actions = {

  { NULL,	NULL }, FALSE,	/* Types_Types */
  { NULL,	NULL }, FALSE,	/* Types_includes2 */
  { NULL,	NULL }, FALSE,	/* Types_EnumType */
  { NULL,	NULL }, FALSE,	/* Types_BindType */
  { NULL,	NULL }, FALSE,	/* Types_PointerType */
  { NULL,	NULL }, FALSE,	/* Types_subtypedef */
  { NULL,	NULL }, FALSE,	/* Types_StructType */
  { NULL,	NULL }, FALSE,	/* Types_struct_type */
  { NULL,	NULL }, FALSE,	/* Types_macro */
  { NULL,	NULL }, FALSE,	/* Types_plain_macro */
  { NULL,	NULL }, FALSE,	/* Types_access_macro */
  { NULL,	NULL }, FALSE,	/* Types_field */
  { NULL,	Retrieve_Types_TypeName }, FALSE,	/* Types_TypeName */
  { NULL,	NULL }, FALSE,	/* Types_CreateFunction */
  { NULL,	NULL }, FALSE,	/* Types_Scope */
  { NULL,	NULL }, FALSE,	/* Types_struct_typeScope */
  { NULL,	NULL }, FALSE,	/* List_Types_struct_type */
  { NULL,	NULL }, FALSE,	/* List_Types_field */
  { NULL,	NULL }, FALSE,	/* List_Types_CreateFunction */
  { NULL,	NULL }, FALSE,	/* List_Types_macro */
  { NULL,	NULL }, FALSE,	/* List_Types_TypeName */
  { NULL,	NULL }, FALSE,	/* List_Types_StructType */
  { NULL,	NULL }, FALSE,	/* List_Types_BindType */
  { NULL,	NULL }, FALSE,	/* List_Types_subtypedef */
  { NULL,	NULL }, FALSE,	/* List_Types_PointerType */
  { NULL,	NULL }, FALSE,	/* List_Types_EnumType */
};

static void Check_Types_struct_type (Types_struct_type me)
{ if (me==NULL) return;
  if (Bind_double (Types_struct_type_tag_bind(me))) {
    InputError (Types_struct_type_loc(me), TRUE, "Identifier '%s' already declared", Ident_name(Types_struct_type_tag(me)));
  }
}

static void Check_Types_TypeName (Types_TypeName me)
{ if (me==NULL) return;
}

struct s_void_Types_TraverseTable Types_check_actions = {

  { NULL,	NULL }, FALSE,	/* Types_Types */
  { NULL,	NULL }, FALSE,	/* Types_includes2 */
  { NULL,	NULL }, FALSE,	/* Types_EnumType */
  { NULL,	NULL }, FALSE,	/* Types_BindType */
  { NULL,	NULL }, FALSE,	/* Types_PointerType */
  { NULL,	NULL }, FALSE,	/* Types_subtypedef */
  { NULL,	NULL }, FALSE,	/* Types_StructType */
  { NULL,	Check_Types_struct_type }, FALSE,	/* Types_struct_type */
  { NULL,	NULL }, FALSE,	/* Types_macro */
  { NULL,	NULL }, FALSE,	/* Types_plain_macro */
  { NULL,	NULL }, FALSE,	/* Types_access_macro */
  { NULL,	NULL }, FALSE,	/* Types_field */
  { NULL,	Check_Types_TypeName }, FALSE,	/* Types_TypeName */
  { NULL,	NULL }, FALSE,	/* Types_CreateFunction */
  { NULL,	NULL }, FALSE,	/* Types_Scope */
  { NULL,	NULL }, FALSE,	/* Types_struct_typeScope */
  { NULL,	NULL }, FALSE,	/* List_Types_struct_type */
  { NULL,	NULL }, FALSE,	/* List_Types_field */
  { NULL,	NULL }, FALSE,	/* List_Types_CreateFunction */
  { NULL,	NULL }, FALSE,	/* List_Types_macro */
  { NULL,	NULL }, FALSE,	/* List_Types_TypeName */
  { NULL,	NULL }, FALSE,	/* List_Types_StructType */
  { NULL,	NULL }, FALSE,	/* List_Types_BindType */
  { NULL,	NULL }, FALSE,	/* List_Types_subtypedef */
  { NULL,	NULL }, FALSE,	/* List_Types_PointerType */
  { NULL,	NULL }, FALSE,	/* List_Types_EnumType */
};

struct s_void_Types_TraverseTable Types_print_actions;

struct s_copy_Types_TraverseTable Types_copy_actions;

struct s_compare_Types_TraverseTable Types_compare_actions;

void Types_fill_table (Types_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Types[PRE_ACTION] = (void* (*) (Types_Types, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Types[POST_ACTION] = (void* (*) (Types_Types, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_includes2[PRE_ACTION] = (void* (*) (Types_includes2, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_includes2[POST_ACTION] = (void* (*) (Types_includes2, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EnumType[PRE_ACTION] = (void* (*) (Types_EnumType, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EnumType[POST_ACTION] = (void* (*) (Types_EnumType, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BindType[PRE_ACTION] = (void* (*) (Types_BindType, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BindType[POST_ACTION] = (void* (*) (Types_BindType, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PointerType[PRE_ACTION] = (void* (*) (Types_PointerType, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PointerType[POST_ACTION] = (void* (*) (Types_PointerType, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_subtypedef[PRE_ACTION] = (void* (*) (Types_subtypedef, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_subtypedef[POST_ACTION] = (void* (*) (Types_subtypedef, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StructType[PRE_ACTION] = (void* (*) (Types_StructType, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StructType[POST_ACTION] = (void* (*) (Types_StructType, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_struct_type[PRE_ACTION] = (void* (*) (Types_struct_type, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_struct_type[POST_ACTION] = (void* (*) (Types_struct_type, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_macro[PRE_ACTION] = (void* (*) (Types_macro, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_macro[POST_ACTION] = (void* (*) (Types_macro, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_plain_macro[PRE_ACTION] = (void* (*) (Types_plain_macro, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_plain_macro[POST_ACTION] = (void* (*) (Types_plain_macro, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_access_macro[PRE_ACTION] = (void* (*) (Types_access_macro, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_access_macro[POST_ACTION] = (void* (*) (Types_access_macro, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_field[PRE_ACTION] = (void* (*) (Types_field, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_field[POST_ACTION] = (void* (*) (Types_field, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypeName[PRE_ACTION] = (void* (*) (Types_TypeName, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypeName[POST_ACTION] = (void* (*) (Types_TypeName, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CreateFunction[PRE_ACTION] = (void* (*) (Types_CreateFunction, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CreateFunction[POST_ACTION] = (void* (*) (Types_CreateFunction, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void* (*) (Types_Scope, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void* (*) (Types_Scope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_struct_typeScope[PRE_ACTION] = (void* (*) (Types_struct_typeScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_struct_typeScope[POST_ACTION] = (void* (*) (Types_struct_typeScope, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_struct_type[PRE_ACTION] = (void* (*) (List_Types_struct_type, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_struct_type[POST_ACTION] = (void* (*) (List_Types_struct_type, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_field[PRE_ACTION] = (void* (*) (List_Types_field, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_field[POST_ACTION] = (void* (*) (List_Types_field, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_CreateFunction[PRE_ACTION] = (void* (*) (List_Types_CreateFunction, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_CreateFunction[POST_ACTION] = (void* (*) (List_Types_CreateFunction, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_macro[PRE_ACTION] = (void* (*) (List_Types_macro, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_macro[POST_ACTION] = (void* (*) (List_Types_macro, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_TypeName[PRE_ACTION] = (void* (*) (List_Types_TypeName, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_TypeName[POST_ACTION] = (void* (*) (List_Types_TypeName, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_StructType[PRE_ACTION] = (void* (*) (List_Types_StructType, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_StructType[POST_ACTION] = (void* (*) (List_Types_StructType, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_BindType[PRE_ACTION] = (void* (*) (List_Types_BindType, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_BindType[POST_ACTION] = (void* (*) (List_Types_BindType, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_subtypedef[PRE_ACTION] = (void* (*) (List_Types_subtypedef, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_subtypedef[POST_ACTION] = (void* (*) (List_Types_subtypedef, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_PointerType[PRE_ACTION] = (void* (*) (List_Types_PointerType, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_PointerType[POST_ACTION] = (void* (*) (List_Types_PointerType, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_EnumType[PRE_ACTION] = (void* (*) (List_Types_EnumType, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_EnumType[POST_ACTION] = (void* (*) (List_Types_EnumType, void*))x;
}

void void_Types_fill_table (void_Types_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Types[PRE_ACTION] = (void (*) (Types_Types))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Types[POST_ACTION] = (void (*) (Types_Types))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_includes2[PRE_ACTION] = (void (*) (Types_includes2))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_includes2[POST_ACTION] = (void (*) (Types_includes2))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EnumType[PRE_ACTION] = (void (*) (Types_EnumType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EnumType[POST_ACTION] = (void (*) (Types_EnumType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BindType[PRE_ACTION] = (void (*) (Types_BindType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BindType[POST_ACTION] = (void (*) (Types_BindType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PointerType[PRE_ACTION] = (void (*) (Types_PointerType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PointerType[POST_ACTION] = (void (*) (Types_PointerType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_subtypedef[PRE_ACTION] = (void (*) (Types_subtypedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_subtypedef[POST_ACTION] = (void (*) (Types_subtypedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StructType[PRE_ACTION] = (void (*) (Types_StructType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StructType[POST_ACTION] = (void (*) (Types_StructType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_struct_type[PRE_ACTION] = (void (*) (Types_struct_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_struct_type[POST_ACTION] = (void (*) (Types_struct_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_macro[PRE_ACTION] = (void (*) (Types_macro))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_macro[POST_ACTION] = (void (*) (Types_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_plain_macro[PRE_ACTION] = (void (*) (Types_plain_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_plain_macro[POST_ACTION] = (void (*) (Types_plain_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_access_macro[PRE_ACTION] = (void (*) (Types_access_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_access_macro[POST_ACTION] = (void (*) (Types_access_macro))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_field[PRE_ACTION] = (void (*) (Types_field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_field[POST_ACTION] = (void (*) (Types_field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypeName[PRE_ACTION] = (void (*) (Types_TypeName))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypeName[POST_ACTION] = (void (*) (Types_TypeName))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CreateFunction[PRE_ACTION] = (void (*) (Types_CreateFunction))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CreateFunction[POST_ACTION] = (void (*) (Types_CreateFunction))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void (*) (Types_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void (*) (Types_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_struct_typeScope[PRE_ACTION] = (void (*) (Types_struct_typeScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_struct_typeScope[POST_ACTION] = (void (*) (Types_struct_typeScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_struct_type[PRE_ACTION] = (void (*) (List_Types_struct_type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_struct_type[POST_ACTION] = (void (*) (List_Types_struct_type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_field[PRE_ACTION] = (void (*) (List_Types_field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_field[POST_ACTION] = (void (*) (List_Types_field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_CreateFunction[PRE_ACTION] = (void (*) (List_Types_CreateFunction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_CreateFunction[POST_ACTION] = (void (*) (List_Types_CreateFunction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_macro[PRE_ACTION] = (void (*) (List_Types_macro))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_macro[POST_ACTION] = (void (*) (List_Types_macro))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_TypeName[PRE_ACTION] = (void (*) (List_Types_TypeName))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_TypeName[POST_ACTION] = (void (*) (List_Types_TypeName))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_StructType[PRE_ACTION] = (void (*) (List_Types_StructType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_StructType[POST_ACTION] = (void (*) (List_Types_StructType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_BindType[PRE_ACTION] = (void (*) (List_Types_BindType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_BindType[POST_ACTION] = (void (*) (List_Types_BindType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_subtypedef[PRE_ACTION] = (void (*) (List_Types_subtypedef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_subtypedef[POST_ACTION] = (void (*) (List_Types_subtypedef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_PointerType[PRE_ACTION] = (void (*) (List_Types_PointerType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_PointerType[POST_ACTION] = (void (*) (List_Types_PointerType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_EnumType[PRE_ACTION] = (void (*) (List_Types_EnumType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_EnumType[POST_ACTION] = (void (*) (List_Types_EnumType))x;
}

void copy_Types_fill_table (copy_Types_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Types[PRE_ACTION] = (Types_Types (*) (Types_Types, Types_Types))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Types[POST_ACTION] = (Types_Types (*) (Types_Types, Types_Types))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_includes2[PRE_ACTION] = (Types_includes2 (*) (Types_includes2, Types_includes2))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_includes2[POST_ACTION] = (Types_includes2 (*) (Types_includes2, Types_includes2))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EnumType[PRE_ACTION] = (Types_EnumType (*) (Types_EnumType, Types_EnumType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EnumType[POST_ACTION] = (Types_EnumType (*) (Types_EnumType, Types_EnumType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BindType[PRE_ACTION] = (Types_BindType (*) (Types_BindType, Types_BindType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BindType[POST_ACTION] = (Types_BindType (*) (Types_BindType, Types_BindType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PointerType[PRE_ACTION] = (Types_PointerType (*) (Types_PointerType, Types_PointerType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PointerType[POST_ACTION] = (Types_PointerType (*) (Types_PointerType, Types_PointerType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_subtypedef[PRE_ACTION] = (Types_subtypedef (*) (Types_subtypedef, Types_subtypedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_subtypedef[POST_ACTION] = (Types_subtypedef (*) (Types_subtypedef, Types_subtypedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StructType[PRE_ACTION] = (Types_StructType (*) (Types_StructType, Types_StructType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StructType[POST_ACTION] = (Types_StructType (*) (Types_StructType, Types_StructType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_struct_type[PRE_ACTION] = (Types_struct_type (*) (Types_struct_type, Types_struct_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_struct_type[POST_ACTION] = (Types_struct_type (*) (Types_struct_type, Types_struct_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_macro[PRE_ACTION] = (Types_macro (*) (Types_macro, Types_macro))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_macro[POST_ACTION] = (Types_macro (*) (Types_macro, Types_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_plain_macro[PRE_ACTION] = (Types_plain_macro (*) (Types_plain_macro, Types_plain_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_plain_macro[POST_ACTION] = (Types_plain_macro (*) (Types_plain_macro, Types_plain_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_access_macro[PRE_ACTION] = (Types_access_macro (*) (Types_access_macro, Types_access_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_access_macro[POST_ACTION] = (Types_access_macro (*) (Types_access_macro, Types_access_macro))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_field[PRE_ACTION] = (Types_field (*) (Types_field, Types_field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_field[POST_ACTION] = (Types_field (*) (Types_field, Types_field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypeName[PRE_ACTION] = (Types_TypeName (*) (Types_TypeName, Types_TypeName))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypeName[POST_ACTION] = (Types_TypeName (*) (Types_TypeName, Types_TypeName))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CreateFunction[PRE_ACTION] = (Types_CreateFunction (*) (Types_CreateFunction, Types_CreateFunction))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CreateFunction[POST_ACTION] = (Types_CreateFunction (*) (Types_CreateFunction, Types_CreateFunction))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (Types_Scope (*) (Types_Scope, Types_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (Types_Scope (*) (Types_Scope, Types_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_struct_typeScope[PRE_ACTION] = (Types_struct_typeScope (*) (Types_struct_typeScope, Types_struct_typeScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_struct_typeScope[POST_ACTION] = (Types_struct_typeScope (*) (Types_struct_typeScope, Types_struct_typeScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_struct_type[PRE_ACTION] = (List_Types_struct_type (*) (List_Types_struct_type, List_Types_struct_type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_struct_type[POST_ACTION] = (List_Types_struct_type (*) (List_Types_struct_type, List_Types_struct_type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_field[PRE_ACTION] = (List_Types_field (*) (List_Types_field, List_Types_field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_field[POST_ACTION] = (List_Types_field (*) (List_Types_field, List_Types_field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_CreateFunction[PRE_ACTION] = (List_Types_CreateFunction (*) (List_Types_CreateFunction, List_Types_CreateFunction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_CreateFunction[POST_ACTION] = (List_Types_CreateFunction (*) (List_Types_CreateFunction, List_Types_CreateFunction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_macro[PRE_ACTION] = (List_Types_macro (*) (List_Types_macro, List_Types_macro))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_macro[POST_ACTION] = (List_Types_macro (*) (List_Types_macro, List_Types_macro))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_TypeName[PRE_ACTION] = (List_Types_TypeName (*) (List_Types_TypeName, List_Types_TypeName))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_TypeName[POST_ACTION] = (List_Types_TypeName (*) (List_Types_TypeName, List_Types_TypeName))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_StructType[PRE_ACTION] = (List_Types_StructType (*) (List_Types_StructType, List_Types_StructType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_StructType[POST_ACTION] = (List_Types_StructType (*) (List_Types_StructType, List_Types_StructType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_BindType[PRE_ACTION] = (List_Types_BindType (*) (List_Types_BindType, List_Types_BindType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_BindType[POST_ACTION] = (List_Types_BindType (*) (List_Types_BindType, List_Types_BindType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_subtypedef[PRE_ACTION] = (List_Types_subtypedef (*) (List_Types_subtypedef, List_Types_subtypedef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_subtypedef[POST_ACTION] = (List_Types_subtypedef (*) (List_Types_subtypedef, List_Types_subtypedef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_PointerType[PRE_ACTION] = (List_Types_PointerType (*) (List_Types_PointerType, List_Types_PointerType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_PointerType[POST_ACTION] = (List_Types_PointerType (*) (List_Types_PointerType, List_Types_PointerType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_EnumType[PRE_ACTION] = (List_Types_EnumType (*) (List_Types_EnumType, List_Types_EnumType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_EnumType[POST_ACTION] = (List_Types_EnumType (*) (List_Types_EnumType, List_Types_EnumType))x;
}

void compare_Types_fill_table (compare_Types_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Types[PRE_ACTION] = (int (*) (Types_Types, Types_Types))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Types[POST_ACTION] = (int (*) (Types_Types, Types_Types))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_includes2[PRE_ACTION] = (int (*) (Types_includes2, Types_includes2))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_includes2[POST_ACTION] = (int (*) (Types_includes2, Types_includes2))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EnumType[PRE_ACTION] = (int (*) (Types_EnumType, Types_EnumType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EnumType[POST_ACTION] = (int (*) (Types_EnumType, Types_EnumType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BindType[PRE_ACTION] = (int (*) (Types_BindType, Types_BindType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BindType[POST_ACTION] = (int (*) (Types_BindType, Types_BindType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PointerType[PRE_ACTION] = (int (*) (Types_PointerType, Types_PointerType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PointerType[POST_ACTION] = (int (*) (Types_PointerType, Types_PointerType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_subtypedef[PRE_ACTION] = (int (*) (Types_subtypedef, Types_subtypedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_subtypedef[POST_ACTION] = (int (*) (Types_subtypedef, Types_subtypedef))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StructType[PRE_ACTION] = (int (*) (Types_StructType, Types_StructType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StructType[POST_ACTION] = (int (*) (Types_StructType, Types_StructType))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_struct_type[PRE_ACTION] = (int (*) (Types_struct_type, Types_struct_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_struct_type[POST_ACTION] = (int (*) (Types_struct_type, Types_struct_type))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_macro[PRE_ACTION] = (int (*) (Types_macro, Types_macro))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_macro[POST_ACTION] = (int (*) (Types_macro, Types_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_plain_macro[PRE_ACTION] = (int (*) (Types_plain_macro, Types_plain_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_plain_macro[POST_ACTION] = (int (*) (Types_plain_macro, Types_plain_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_access_macro[PRE_ACTION] = (int (*) (Types_access_macro, Types_access_macro))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_access_macro[POST_ACTION] = (int (*) (Types_access_macro, Types_access_macro))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_field[PRE_ACTION] = (int (*) (Types_field, Types_field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_field[POST_ACTION] = (int (*) (Types_field, Types_field))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TypeName[PRE_ACTION] = (int (*) (Types_TypeName, Types_TypeName))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TypeName[POST_ACTION] = (int (*) (Types_TypeName, Types_TypeName))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CreateFunction[PRE_ACTION] = (int (*) (Types_CreateFunction, Types_CreateFunction))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CreateFunction[POST_ACTION] = (int (*) (Types_CreateFunction, Types_CreateFunction))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (int (*) (Types_Scope, Types_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (int (*) (Types_Scope, Types_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_struct_typeScope[PRE_ACTION] = (int (*) (Types_struct_typeScope, Types_struct_typeScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_struct_typeScope[POST_ACTION] = (int (*) (Types_struct_typeScope, Types_struct_typeScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_struct_type[PRE_ACTION] = (int (*) (List_Types_struct_type, List_Types_struct_type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_struct_type[POST_ACTION] = (int (*) (List_Types_struct_type, List_Types_struct_type))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_field[PRE_ACTION] = (int (*) (List_Types_field, List_Types_field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_field[POST_ACTION] = (int (*) (List_Types_field, List_Types_field))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_CreateFunction[PRE_ACTION] = (int (*) (List_Types_CreateFunction, List_Types_CreateFunction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_CreateFunction[POST_ACTION] = (int (*) (List_Types_CreateFunction, List_Types_CreateFunction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_macro[PRE_ACTION] = (int (*) (List_Types_macro, List_Types_macro))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_macro[POST_ACTION] = (int (*) (List_Types_macro, List_Types_macro))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_TypeName[PRE_ACTION] = (int (*) (List_Types_TypeName, List_Types_TypeName))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_TypeName[POST_ACTION] = (int (*) (List_Types_TypeName, List_Types_TypeName))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_StructType[PRE_ACTION] = (int (*) (List_Types_StructType, List_Types_StructType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_StructType[POST_ACTION] = (int (*) (List_Types_StructType, List_Types_StructType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_BindType[PRE_ACTION] = (int (*) (List_Types_BindType, List_Types_BindType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_BindType[POST_ACTION] = (int (*) (List_Types_BindType, List_Types_BindType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_subtypedef[PRE_ACTION] = (int (*) (List_Types_subtypedef, List_Types_subtypedef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_subtypedef[POST_ACTION] = (int (*) (List_Types_subtypedef, List_Types_subtypedef))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_PointerType[PRE_ACTION] = (int (*) (List_Types_PointerType, List_Types_PointerType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_PointerType[POST_ACTION] = (int (*) (List_Types_PointerType, List_Types_PointerType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_EnumType[PRE_ACTION] = (int (*) (List_Types_EnumType, List_Types_EnumType))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_EnumType[POST_ACTION] = (int (*) (List_Types_EnumType, List_Types_EnumType))x;
}

Types_NameSpaces Types_namespaces[] = { -1 };

void Decorate_Types (Types_Types r)
{
  if (Types_namespaces[0]<0) Extend_namespaces (Types_NUM_NAMESPACES, Types_namespaces);
  Types_root = r;
  if (NoDecorate) return;
  Traverse_Types_Types (r, &Types_scope_actions, NULL);
  Traverse_void_Types_Types (r, &Types_defining_actions);
  Traverse_void_Types_Types (r, &Types_applied_actions);
  Traverse_void_Types_Types (r, &Types_check_actions);
}
