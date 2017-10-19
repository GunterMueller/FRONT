#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "front/error.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/mem.h"
#include "egg.h"

#ifndef egg_SKIP_NODE
# define egg_SKIP_NODE(n,t) FALSE
#endif

egg egg_root;

String egg_Expression_tag_names[] = {
  "StringExpr_kind",
  "CallExpr_kind",
  "IdExpr_kind",
};

String egg_Statement_tag_names[] = {
  "Message_kind",
  "Group_kind",
};

String egg_MessageKind_names[] = {
  "ErrorMsg",
  "WarningMsg",
  "DisabledMsg",
  "KeyMsg",
  "PostMsg",
};

String egg_Scope_tag_names[] = {
  "GroupScope_kind",
};

egg_egg Create_egg_egg	(SrcInfo src_info, egg_Uses uses, List_egg_Statement groups)
{ egg_egg me = (egg_egg)fe_malloc(sizeof(*me));
  egg_egg_src_info(me) = src_info;
  egg_egg_uses(me) = uses;
  egg_egg_groups(me) = groups;
  return me;
}

egg_Uses Create_egg_Uses	(SrcInfo src_info, List_String uses)
{ egg_Uses me = (egg_Uses)fe_malloc(sizeof(*me));
  egg_Uses_src_info(me) = src_info;
  egg_Uses_uses(me) = uses;
  return me;
}

egg_Declaration Create_egg_Declaration	(SrcInfo src_info, egg_MessageKind kind, List_egg_Expression exprs)
{ egg_Declaration me = (egg_Declaration)fe_malloc(sizeof(*me));
  egg_Declaration_src_info(me) = src_info;
  egg_Declaration_kind(me) = kind;
  egg_Declaration_exprs(me) = exprs;
  egg_Declaration_group(me) = NULL;
  return me;
}

egg_IdExpr Create_egg_IdExpr	(SrcInfo src_info, Ident id)
{ egg_IdExpr me = (egg_IdExpr)fe_malloc(sizeof(*me));
  egg_Expression_src_info(me) = src_info;
  egg_IdExpr_id(me) = id;
  egg_Expression_tag(me) = egg_IdExpr_kind;
  return me;
}

egg_CallExpr Create_egg_CallExpr	(SrcInfo src_info, Ident id, List_egg_Expression params)
{ egg_CallExpr me = (egg_CallExpr)fe_malloc(sizeof(*me));
  egg_Expression_src_info(me) = src_info;
  egg_CallExpr_id(me) = id;
  egg_CallExpr_params(me) = params;
  egg_Expression_tag(me) = egg_CallExpr_kind;
  return me;
}

egg_StringExpr Create_egg_StringExpr	(SrcInfo src_info, String s)
{ egg_StringExpr me = (egg_StringExpr)fe_malloc(sizeof(*me));
  egg_Expression_src_info(me) = src_info;
  egg_StringExpr_s(me) = s;
  egg_Expression_tag(me) = egg_StringExpr_kind;
  return me;
}

egg_Group Create_egg_Group	(SrcInfo src_info, Bool fatal, Ident id, Ident type, Bool group, List_egg_Declaration decls, List_egg_Statement stats)
{ egg_Group me = (egg_Group)fe_malloc(sizeof(*me));
  egg_Statement_src_info(me) = src_info;
  egg_Statement_fatal(me) = fatal;
  egg_Statement_id(me) = id;
  egg_Group_type(me) = type;
  egg_Group_group(me) = group;
  egg_Group_decls(me) = decls;
  egg_Group_stats(me) = stats;
  egg_Statement__num(me) = - 1;
  egg_Statement_scope(me) = NULL;
  egg_Statement_old_scope(me) = NULL;
  egg_Statement_tag(me) = egg_Group_kind;
  egg_Statement_parent(me) = NULL;
  return me;
}

egg_Message Create_egg_Message	(SrcInfo src_info, Bool fatal, Ident id, List_egg_SubMessage msgs)
{ egg_Message me = (egg_Message)fe_malloc(sizeof(*me));
  egg_Statement_src_info(me) = src_info;
  egg_Statement_fatal(me) = fatal;
  egg_Statement_id(me) = id;
  egg_Message_msgs(me) = msgs;
  egg_Statement__num(me) = - 1;
  egg_Statement_scope(me) = NULL;
  egg_Statement_old_scope(me) = NULL;
  egg_Statement_tag(me) = egg_Message_kind;
  egg_Statement_parent(me) = NULL;
  return me;
}

egg_SubMessage Create_egg_SubMessage	(SrcInfo src_info, egg_MessageKind kind, String msg)
{ egg_SubMessage me = (egg_SubMessage)fe_malloc(sizeof(*me));
  egg_SubMessage_src_info(me) = src_info;
  egg_SubMessage_kind(me) = kind;
  egg_SubMessage_msg(me) = msg;
  return me;
}

egg_GroupScope Create_egg_GroupScope	(egg_Scope next, egg_Statement data)
{ egg_GroupScope me = (egg_GroupScope)fe_malloc(sizeof(*me));
  egg_Scope_next(me) = next;
  egg_GroupScope_data(me) = data;
  egg_Scope__self(me) = 0;
  egg_Scope__end(me) = 0;
  egg_Scope_tag(me) = egg_GroupScope_kind;
  return me;
}

Pointer Traverse_egg_egg (egg_egg me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(egg, me)) return val;
  if (action->action_egg[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_egg[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_egg)
  { 
  if (!action->skip_children_egg) {
    if (action->traversal != Traverse_Down)  val = Traverse_egg_Uses (egg_egg_uses(me), action, val);
    else Traverse_egg_Uses (egg_egg_uses(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_egg_Statement (egg_egg_groups(me), action, val);
    else Traverse_List_egg_Statement (egg_egg_groups(me), action, val);
  }
  }
  if (action->action_egg[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_egg[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_egg_Uses (egg_Uses me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(Uses, me)) return val;
  if (action->action_Uses[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Uses[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Uses)
  { 
  }
  if (action->action_Uses[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Uses[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_egg_Declaration (egg_Declaration me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(Declaration, me)) return val;
  if (action->action_Declaration[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Declaration[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Declaration)
  { 
  if (!action->skip_children_Declaration) {
    if (action->traversal != Traverse_Down)  val = Traverse_egg_MessageKind (egg_Declaration_kind(me), action, val);
    else Traverse_egg_MessageKind (egg_Declaration_kind(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_egg_Expression (egg_Declaration_exprs(me), action, val);
    else Traverse_List_egg_Expression (egg_Declaration_exprs(me), action, val);
  }
  }
  if (action->action_Declaration[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Declaration[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_egg_Expression (egg_Expression me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(Expression, me)) return val;
  if (action->action_Expression[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Expression[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Expression)
  { switch (egg_Expression_tag(me)) {
      case egg_StringExpr_kind:
        if (action->action_StringExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_StringExpr[PRE_ACTION](me, val);
        }
        if (action->action_StringExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_StringExpr[POST_ACTION](me, val);
        }
        break;
      case egg_CallExpr_kind:
        if (action->action_CallExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CallExpr[PRE_ACTION](me, val);
        }
        if (!action->skip_children_CallExpr) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_egg_Expression (egg_CallExpr_params(me), action, val);
          else Traverse_List_egg_Expression (egg_CallExpr_params(me), action, val);
        }
        if (action->action_CallExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_CallExpr[POST_ACTION](me, val);
        }
        break;
      case egg_IdExpr_kind:
        if (action->action_IdExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdExpr[PRE_ACTION](me, val);
        }
        if (action->action_IdExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdExpr[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Expression[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Expression[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_egg_Statement (egg_Statement me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(Statement, me)) return val;
  if (action->action_Statement[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Statement[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Statement)
  { switch (egg_Statement_tag(me)) {
      case egg_Message_kind:
        if (action->action_Message[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Message[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Message) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_egg_SubMessage (egg_Message_msgs(me), action, val);
          else Traverse_List_egg_SubMessage (egg_Message_msgs(me), action, val);
        }
        if (action->action_Message[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Message[POST_ACTION](me, val);
        }
        break;
      case egg_Group_kind:
        if (action->action_Group[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Group[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Group) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_egg_Declaration (egg_Group_decls(me), action, val);
          else Traverse_List_egg_Declaration (egg_Group_decls(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_egg_Statement (egg_Group_stats(me), action, val);
          else Traverse_List_egg_Statement (egg_Group_stats(me), action, val);
        }
        if (action->action_Group[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Group[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Statement[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Statement[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_egg_SubMessage (egg_SubMessage me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(SubMessage, me)) return val;
  if (action->action_SubMessage[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_SubMessage[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_SubMessage)
  { 
  if (!action->skip_children_SubMessage) {
    if (action->traversal != Traverse_Down)  val = Traverse_egg_MessageKind (egg_SubMessage_kind(me), action, val);
    else Traverse_egg_MessageKind (egg_SubMessage_kind(me), action, val);
  }
  }
  if (action->action_SubMessage[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_SubMessage[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_egg_Scope (egg_Scope me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(Scope, me)) return val;
  if (action->action_Scope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Scope)
  { switch (egg_Scope_tag(me)) {
      case egg_GroupScope_kind:
        if (action->action_GroupScope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_GroupScope[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Scope) {
          if (action->traversal != Traverse_Down)  val = Traverse_egg_Scope (egg_Scope_next(me), action, val);
          else Traverse_egg_Scope (egg_Scope_next(me), action, val);
        }
        if (!action->skip_children_GroupScope) {
          if (action->traversal != Traverse_Down)  val = Traverse_egg_Statement (egg_GroupScope_data(me), action, val);
          else Traverse_egg_Statement (egg_GroupScope_data(me), action, val);
        }
        if (action->action_GroupScope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_GroupScope[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Scope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_egg_Declaration (List_egg_Declaration me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(List_Declaration, me)) return val;
  if (action->action_List_Declaration[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Declaration[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Declaration)
  { 
  if (!action->skip_children_List_Declaration) {
    if (action->traversal != Traverse_Down)  val = Traverse_egg_Declaration (List_egg_Declaration_data(me), action, val);
    else Traverse_egg_Declaration (List_egg_Declaration_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_egg_Declaration (List_egg_Declaration_next(me), action, val);
    else Traverse_List_egg_Declaration (List_egg_Declaration_next(me), action, val);
  }
  }
  if (action->action_List_Declaration[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Declaration[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_egg_SubMessage (List_egg_SubMessage me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(List_SubMessage, me)) return val;
  if (action->action_List_SubMessage[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_SubMessage[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_SubMessage)
  { 
  if (!action->skip_children_List_SubMessage) {
    if (action->traversal != Traverse_Down)  val = Traverse_egg_SubMessage (List_egg_SubMessage_data(me), action, val);
    else Traverse_egg_SubMessage (List_egg_SubMessage_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_egg_SubMessage (List_egg_SubMessage_next(me), action, val);
    else Traverse_List_egg_SubMessage (List_egg_SubMessage_next(me), action, val);
  }
  }
  if (action->action_List_SubMessage[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_SubMessage[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_egg_Expression (List_egg_Expression me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(List_Expression, me)) return val;
  if (action->action_List_Expression[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Expression[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Expression)
  { 
  if (!action->skip_children_List_Expression) {
    if (action->traversal != Traverse_Down)  val = Traverse_egg_Expression (List_egg_Expression_data(me), action, val);
    else Traverse_egg_Expression (List_egg_Expression_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_egg_Expression (List_egg_Expression_next(me), action, val);
    else Traverse_List_egg_Expression (List_egg_Expression_next(me), action, val);
  }
  }
  if (action->action_List_Expression[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Expression[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_egg_Statement (List_egg_Statement me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(List_Statement, me)) return val;
  if (action->action_List_Statement[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Statement[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Statement)
  { 
  if (!action->skip_children_List_Statement) {
    if (action->traversal != Traverse_Down)  val = Traverse_egg_Statement (List_egg_Statement_data(me), action, val);
    else Traverse_egg_Statement (List_egg_Statement_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_egg_Statement (List_egg_Statement_next(me), action, val);
    else Traverse_List_egg_Statement (List_egg_Statement_next(me), action, val);
  }
  }
  if (action->action_List_Statement[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Statement[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_egg_MessageKind (egg_MessageKind me, TraverseTable action, Pointer val)
{ 
  if (egg_SKIP_NODE(MessageKind, me)) return val;
  if (action->action_MessageKind[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_MessageKind[PRE_ACTION](me, val);
  }
  { switch (me) {
      case egg_ErrorMsg:
        if (action->action_ErrorMsg[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ErrorMsg[PRE_ACTION](me, val);
        }
        if (action->action_ErrorMsg[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ErrorMsg[POST_ACTION](me, val);
        }
        break;
      case egg_WarningMsg:
        if (action->action_WarningMsg[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WarningMsg[PRE_ACTION](me, val);
        }
        if (action->action_WarningMsg[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_WarningMsg[POST_ACTION](me, val);
        }
        break;
      case egg_DisabledMsg:
        if (action->action_DisabledMsg[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DisabledMsg[PRE_ACTION](me, val);
        }
        if (action->action_DisabledMsg[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_DisabledMsg[POST_ACTION](me, val);
        }
        break;
      case egg_KeyMsg:
        if (action->action_KeyMsg[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_KeyMsg[PRE_ACTION](me, val);
        }
        if (action->action_KeyMsg[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_KeyMsg[POST_ACTION](me, val);
        }
        break;
      case egg_PostMsg:
        if (action->action_PostMsg[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PostMsg[PRE_ACTION](me, val);
        }
        if (action->action_PostMsg[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PostMsg[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_MessageKind[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_MessageKind[POST_ACTION](me, val);
  }
  return val;
}

void Traverse_void_egg_egg (egg_egg me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(egg, me)) return;
  if (action->action_egg[PRE_ACTION] != NULL) {
    action->action_egg[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_egg)
  { 
  if (!action->skip_children_egg) {
    Traverse_void_egg_Uses (egg_egg_uses(me), action);
    Traverse_void_List_egg_Statement (egg_egg_groups(me), action);
  }
  }
  if (action->action_egg[POST_ACTION] != NULL) {
    action->action_egg[POST_ACTION](me);
  }
}

void Traverse_void_egg_Uses (egg_Uses me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(Uses, me)) return;
  if (action->action_Uses[PRE_ACTION] != NULL) {
    action->action_Uses[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Uses)
  { 
  }
  if (action->action_Uses[POST_ACTION] != NULL) {
    action->action_Uses[POST_ACTION](me);
  }
}

void Traverse_void_egg_Declaration (egg_Declaration me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(Declaration, me)) return;
  if (action->action_Declaration[PRE_ACTION] != NULL) {
    action->action_Declaration[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Declaration)
  { 
  if (!action->skip_children_Declaration) {
    Traverse_void_egg_MessageKind (egg_Declaration_kind(me), action);
    Traverse_void_List_egg_Expression (egg_Declaration_exprs(me), action);
  }
  }
  if (action->action_Declaration[POST_ACTION] != NULL) {
    action->action_Declaration[POST_ACTION](me);
  }
}

void Traverse_void_egg_Expression (egg_Expression me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(Expression, me)) return;
  if (action->action_Expression[PRE_ACTION] != NULL) {
    action->action_Expression[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Expression)
  { switch (egg_Expression_tag(me)) {
      case egg_StringExpr_kind:
        if (action->action_StringExpr[PRE_ACTION] != NULL) {
          action->action_StringExpr[PRE_ACTION](me);
        }
        if (action->action_StringExpr[POST_ACTION] != NULL) {
          action->action_StringExpr[POST_ACTION](me);
        }
        break;
      case egg_CallExpr_kind:
        if (action->action_CallExpr[PRE_ACTION] != NULL) {
          action->action_CallExpr[PRE_ACTION](me);
        }
        if (!action->skip_children_CallExpr) {
          Traverse_void_List_egg_Expression (egg_CallExpr_params(me), action);
        }
        if (action->action_CallExpr[POST_ACTION] != NULL) {
          action->action_CallExpr[POST_ACTION](me);
        }
        break;
      case egg_IdExpr_kind:
        if (action->action_IdExpr[PRE_ACTION] != NULL) {
          action->action_IdExpr[PRE_ACTION](me);
        }
        if (action->action_IdExpr[POST_ACTION] != NULL) {
          action->action_IdExpr[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Expression[POST_ACTION] != NULL) {
    action->action_Expression[POST_ACTION](me);
  }
}

void Traverse_void_egg_Statement (egg_Statement me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(Statement, me)) return;
  if (action->action_Statement[PRE_ACTION] != NULL) {
    action->action_Statement[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Statement)
  { switch (egg_Statement_tag(me)) {
      case egg_Message_kind:
        if (action->action_Message[PRE_ACTION] != NULL) {
          action->action_Message[PRE_ACTION](me);
        }
        if (!action->skip_children_Message) {
          Traverse_void_List_egg_SubMessage (egg_Message_msgs(me), action);
        }
        if (action->action_Message[POST_ACTION] != NULL) {
          action->action_Message[POST_ACTION](me);
        }
        break;
      case egg_Group_kind:
        if (action->action_Group[PRE_ACTION] != NULL) {
          action->action_Group[PRE_ACTION](me);
        }
        if (!action->skip_children_Group) {
          Traverse_void_List_egg_Declaration (egg_Group_decls(me), action);
          Traverse_void_List_egg_Statement (egg_Group_stats(me), action);
        }
        if (action->action_Group[POST_ACTION] != NULL) {
          action->action_Group[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Statement[POST_ACTION] != NULL) {
    action->action_Statement[POST_ACTION](me);
  }
}

void Traverse_void_egg_SubMessage (egg_SubMessage me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(SubMessage, me)) return;
  if (action->action_SubMessage[PRE_ACTION] != NULL) {
    action->action_SubMessage[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_SubMessage)
  { 
  if (!action->skip_children_SubMessage) {
    Traverse_void_egg_MessageKind (egg_SubMessage_kind(me), action);
  }
  }
  if (action->action_SubMessage[POST_ACTION] != NULL) {
    action->action_SubMessage[POST_ACTION](me);
  }
}

void Traverse_void_egg_Scope (egg_Scope me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(Scope, me)) return;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    action->action_Scope[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Scope)
  { switch (egg_Scope_tag(me)) {
      case egg_GroupScope_kind:
        if (action->action_GroupScope[PRE_ACTION] != NULL) {
          action->action_GroupScope[PRE_ACTION](me);
        }
        if (!action->skip_children_Scope) {
          Traverse_void_egg_Scope (egg_Scope_next(me), action);
        }
        if (!action->skip_children_GroupScope) {
          Traverse_void_egg_Statement (egg_GroupScope_data(me), action);
        }
        if (action->action_GroupScope[POST_ACTION] != NULL) {
          action->action_GroupScope[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    action->action_Scope[POST_ACTION](me);
  }
}

void Traverse_void_List_egg_Declaration (List_egg_Declaration me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(List_Declaration, me)) return;
  if (action->action_List_Declaration[PRE_ACTION] != NULL) {
    action->action_List_Declaration[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Declaration)
  { 
  if (!action->skip_children_List_Declaration) {
    Traverse_void_egg_Declaration (List_egg_Declaration_data(me), action);
    Traverse_void_List_egg_Declaration (List_egg_Declaration_next(me), action);
  }
  }
  if (action->action_List_Declaration[POST_ACTION] != NULL) {
    action->action_List_Declaration[POST_ACTION](me);
  }
}

void Traverse_void_List_egg_SubMessage (List_egg_SubMessage me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(List_SubMessage, me)) return;
  if (action->action_List_SubMessage[PRE_ACTION] != NULL) {
    action->action_List_SubMessage[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_SubMessage)
  { 
  if (!action->skip_children_List_SubMessage) {
    Traverse_void_egg_SubMessage (List_egg_SubMessage_data(me), action);
    Traverse_void_List_egg_SubMessage (List_egg_SubMessage_next(me), action);
  }
  }
  if (action->action_List_SubMessage[POST_ACTION] != NULL) {
    action->action_List_SubMessage[POST_ACTION](me);
  }
}

void Traverse_void_List_egg_Expression (List_egg_Expression me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(List_Expression, me)) return;
  if (action->action_List_Expression[PRE_ACTION] != NULL) {
    action->action_List_Expression[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Expression)
  { 
  if (!action->skip_children_List_Expression) {
    Traverse_void_egg_Expression (List_egg_Expression_data(me), action);
    Traverse_void_List_egg_Expression (List_egg_Expression_next(me), action);
  }
  }
  if (action->action_List_Expression[POST_ACTION] != NULL) {
    action->action_List_Expression[POST_ACTION](me);
  }
}

void Traverse_void_List_egg_Statement (List_egg_Statement me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(List_Statement, me)) return;
  if (action->action_List_Statement[PRE_ACTION] != NULL) {
    action->action_List_Statement[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Statement)
  { 
  if (!action->skip_children_List_Statement) {
    Traverse_void_egg_Statement (List_egg_Statement_data(me), action);
    Traverse_void_List_egg_Statement (List_egg_Statement_next(me), action);
  }
  }
  if (action->action_List_Statement[POST_ACTION] != NULL) {
    action->action_List_Statement[POST_ACTION](me);
  }
}

void Traverse_void_egg_MessageKind (egg_MessageKind me, void_egg_TraverseTable action)
{ 
  if (egg_SKIP_NODE(MessageKind, me)) return;
  if (action->action_MessageKind[PRE_ACTION] != NULL) {
    action->action_MessageKind[PRE_ACTION](me);
  }
  { switch (me) {
      case egg_ErrorMsg:
        if (action->action_ErrorMsg[PRE_ACTION] != NULL) {
          action->action_ErrorMsg[PRE_ACTION](me);
        }
        if (action->action_ErrorMsg[POST_ACTION] != NULL) {
          action->action_ErrorMsg[POST_ACTION](me);
        }
        break;
      case egg_WarningMsg:
        if (action->action_WarningMsg[PRE_ACTION] != NULL) {
          action->action_WarningMsg[PRE_ACTION](me);
        }
        if (action->action_WarningMsg[POST_ACTION] != NULL) {
          action->action_WarningMsg[POST_ACTION](me);
        }
        break;
      case egg_DisabledMsg:
        if (action->action_DisabledMsg[PRE_ACTION] != NULL) {
          action->action_DisabledMsg[PRE_ACTION](me);
        }
        if (action->action_DisabledMsg[POST_ACTION] != NULL) {
          action->action_DisabledMsg[POST_ACTION](me);
        }
        break;
      case egg_KeyMsg:
        if (action->action_KeyMsg[PRE_ACTION] != NULL) {
          action->action_KeyMsg[PRE_ACTION](me);
        }
        if (action->action_KeyMsg[POST_ACTION] != NULL) {
          action->action_KeyMsg[POST_ACTION](me);
        }
        break;
      case egg_PostMsg:
        if (action->action_PostMsg[PRE_ACTION] != NULL) {
          action->action_PostMsg[PRE_ACTION](me);
        }
        if (action->action_PostMsg[POST_ACTION] != NULL) {
          action->action_PostMsg[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_MessageKind[POST_ACTION] != NULL) {
    action->action_MessageKind[POST_ACTION](me);
  }
}

egg_egg Traverse_copy_egg_egg (egg_egg me, copy_egg_TraverseTable action)
{ egg_egg _new = me, _old = me;
  if (action->action_egg[PRE_ACTION] != NULL) {
    _new = action->action_egg[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (egg_egg)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_egg) {
    egg_egg_uses(me) = Traverse_copy_egg_Uses (egg_egg_uses(me), action);
    egg_egg_groups(me) = Traverse_copy_List_egg_Statement (egg_egg_groups(me), action);
  }
  }
  if (action->action_egg[POST_ACTION] != NULL) {
    me = action->action_egg[POST_ACTION](me, _old);
  }
  return me;
}

egg_Uses Traverse_copy_egg_Uses (egg_Uses me, copy_egg_TraverseTable action)
{ egg_Uses _new = me, _old = me;
  if (action->action_Uses[PRE_ACTION] != NULL) {
    _new = action->action_Uses[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (egg_Uses)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Uses) {
    egg_Uses_uses(me) = Traverse_copy_List_String (egg_Uses_uses(me), action);
  }
  }
  if (action->action_Uses[POST_ACTION] != NULL) {
    me = action->action_Uses[POST_ACTION](me, _old);
  }
  return me;
}

egg_Declaration Traverse_copy_egg_Declaration (egg_Declaration me, copy_egg_TraverseTable action)
{ egg_Declaration _new = me, _old = me;
  if (action->action_Declaration[PRE_ACTION] != NULL) {
    _new = action->action_Declaration[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (egg_Declaration)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Declaration) {
    egg_Declaration_kind(me) = Traverse_copy_egg_MessageKind (egg_Declaration_kind(me), action);
    egg_Declaration_exprs(me) = Traverse_copy_List_egg_Expression (egg_Declaration_exprs(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      egg_Declaration_group(me) = NULL;
    }
  }
  if (action->action_Declaration[POST_ACTION] != NULL) {
    me = action->action_Declaration[POST_ACTION](me, _old);
  }
  return me;
}

egg_Expression Traverse_copy_egg_Expression (egg_Expression me, copy_egg_TraverseTable action)
{ egg_Expression _new = me, _old = me;
  if (action->action_Expression[PRE_ACTION] != NULL) {
    _new = action->action_Expression[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (egg_Expression)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (egg_Expression_tag(me)) {
      case egg_StringExpr_kind:
        if (action->action_StringExpr[PRE_ACTION] != NULL) {
          _new = action->action_StringExpr[PRE_ACTION](me, me);
        }
        if (action->action_StringExpr[POST_ACTION] != NULL) {
          _new = action->action_StringExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case egg_CallExpr_kind:
        if (action->action_CallExpr[PRE_ACTION] != NULL) {
          _new = action->action_CallExpr[PRE_ACTION](me, me);
        }
        if (!action->skip_children_CallExpr) {
          egg_CallExpr_params(me) = Traverse_copy_List_egg_Expression (egg_CallExpr_params(me), action);
        }
        if (action->action_CallExpr[POST_ACTION] != NULL) {
          _new = action->action_CallExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case egg_IdExpr_kind:
        if (action->action_IdExpr[PRE_ACTION] != NULL) {
          _new = action->action_IdExpr[PRE_ACTION](me, me);
        }
        if (action->action_IdExpr[POST_ACTION] != NULL) {
          _new = action->action_IdExpr[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Expression[POST_ACTION] != NULL) {
    me = action->action_Expression[POST_ACTION](me, _old);
  }
  return me;
}

egg_Statement Traverse_copy_egg_Statement (egg_Statement me, copy_egg_TraverseTable action)
{ egg_Statement _new = me, _old = me;
  if (action->action_Statement[PRE_ACTION] != NULL) {
    _new = action->action_Statement[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (egg_Statement)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (egg_Statement_tag(me)) {
      case egg_Message_kind:
        if (action->action_Message[PRE_ACTION] != NULL) {
          _new = action->action_Message[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            egg_Statement_scope(me) = NULL;
            egg_Statement_old_scope(me) = NULL;
          }
        if (!action->skip_children_Message) {
          egg_Message_msgs(me) = Traverse_copy_List_egg_SubMessage (egg_Message_msgs(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            egg_Statement_parent(me) = NULL;
          }
        if (action->action_Message[POST_ACTION] != NULL) {
          _new = action->action_Message[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case egg_Group_kind:
        if (action->action_Group[PRE_ACTION] != NULL) {
          _new = action->action_Group[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            egg_Statement_scope(me) = NULL;
            egg_Statement_old_scope(me) = NULL;
          }
        if (!action->skip_children_Group) {
          egg_Group_decls(me) = Traverse_copy_List_egg_Declaration (egg_Group_decls(me), action);
          egg_Group_stats(me) = Traverse_copy_List_egg_Statement (egg_Group_stats(me), action);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            egg_Statement_parent(me) = NULL;
          }
        if (action->action_Group[POST_ACTION] != NULL) {
          _new = action->action_Group[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Statement[POST_ACTION] != NULL) {
    me = action->action_Statement[POST_ACTION](me, _old);
  }
  return me;
}

egg_SubMessage Traverse_copy_egg_SubMessage (egg_SubMessage me, copy_egg_TraverseTable action)
{ egg_SubMessage _new = me, _old = me;
  if (action->action_SubMessage[PRE_ACTION] != NULL) {
    _new = action->action_SubMessage[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (egg_SubMessage)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_SubMessage) {
    egg_SubMessage_kind(me) = Traverse_copy_egg_MessageKind (egg_SubMessage_kind(me), action);
  }
  }
  if (action->action_SubMessage[POST_ACTION] != NULL) {
    me = action->action_SubMessage[POST_ACTION](me, _old);
  }
  return me;
}

egg_Scope Traverse_copy_egg_Scope (egg_Scope me, copy_egg_TraverseTable action)
{ egg_Scope _new = me, _old = me;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    _new = action->action_Scope[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (egg_Scope)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (egg_Scope_tag(me)) {
      case egg_GroupScope_kind:
        if (action->action_GroupScope[PRE_ACTION] != NULL) {
          _new = action->action_GroupScope[PRE_ACTION](me, me);
        }
        if (!action->skip_children_Scope) {
          egg_Scope_next(me) = Traverse_copy_egg_Scope (egg_Scope_next(me), action);
        }
        if (!action->skip_children_GroupScope) {
          egg_GroupScope_data(me) = Traverse_copy_egg_Statement (egg_GroupScope_data(me), action);
        }
        if (action->action_GroupScope[POST_ACTION] != NULL) {
          _new = action->action_GroupScope[POST_ACTION](me, me);
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

List_egg_Declaration Traverse_copy_List_egg_Declaration (List_egg_Declaration me, copy_egg_TraverseTable action)
{ List_egg_Declaration _new = me, _old = me;
  if (action->action_List_Declaration[PRE_ACTION] != NULL) {
    _new = action->action_List_Declaration[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_egg_Declaration)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Declaration) {
    List_egg_Declaration_data(me) = Traverse_copy_egg_Declaration (List_egg_Declaration_data(me), action);
    List_egg_Declaration_next(me) = Traverse_copy_List_egg_Declaration (List_egg_Declaration_next(me), action);
  }
  }
  if (action->action_List_Declaration[POST_ACTION] != NULL) {
    me = action->action_List_Declaration[POST_ACTION](me, _old);
  }
  return me;
}

List_egg_SubMessage Traverse_copy_List_egg_SubMessage (List_egg_SubMessage me, copy_egg_TraverseTable action)
{ List_egg_SubMessage _new = me, _old = me;
  if (action->action_List_SubMessage[PRE_ACTION] != NULL) {
    _new = action->action_List_SubMessage[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_egg_SubMessage)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_SubMessage) {
    List_egg_SubMessage_data(me) = Traverse_copy_egg_SubMessage (List_egg_SubMessage_data(me), action);
    List_egg_SubMessage_next(me) = Traverse_copy_List_egg_SubMessage (List_egg_SubMessage_next(me), action);
  }
  }
  if (action->action_List_SubMessage[POST_ACTION] != NULL) {
    me = action->action_List_SubMessage[POST_ACTION](me, _old);
  }
  return me;
}

List_egg_Expression Traverse_copy_List_egg_Expression (List_egg_Expression me, copy_egg_TraverseTable action)
{ List_egg_Expression _new = me, _old = me;
  if (action->action_List_Expression[PRE_ACTION] != NULL) {
    _new = action->action_List_Expression[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_egg_Expression)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Expression) {
    List_egg_Expression_data(me) = Traverse_copy_egg_Expression (List_egg_Expression_data(me), action);
    List_egg_Expression_next(me) = Traverse_copy_List_egg_Expression (List_egg_Expression_next(me), action);
  }
  }
  if (action->action_List_Expression[POST_ACTION] != NULL) {
    me = action->action_List_Expression[POST_ACTION](me, _old);
  }
  return me;
}

List_egg_Statement Traverse_copy_List_egg_Statement (List_egg_Statement me, copy_egg_TraverseTable action)
{ List_egg_Statement _new = me, _old = me;
  if (action->action_List_Statement[PRE_ACTION] != NULL) {
    _new = action->action_List_Statement[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_egg_Statement)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Statement) {
    List_egg_Statement_data(me) = Traverse_copy_egg_Statement (List_egg_Statement_data(me), action);
    List_egg_Statement_next(me) = Traverse_copy_List_egg_Statement (List_egg_Statement_next(me), action);
  }
  }
  if (action->action_List_Statement[POST_ACTION] != NULL) {
    me = action->action_List_Statement[POST_ACTION](me, _old);
  }
  return me;
}

egg_MessageKind Traverse_copy_egg_MessageKind (egg_MessageKind me, copy_egg_TraverseTable action)
{ egg_MessageKind _new = me, _old = me;
  if (action->action_MessageKind[PRE_ACTION] != NULL) {
    return action->action_MessageKind[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_MessageKind[POST_ACTION] != NULL) {
    me = action->action_MessageKind[POST_ACTION](me, _old);
  }
  return me;
}

int Traverse_compare_egg_egg (egg_egg x, egg_egg y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_egg[PRE_ACTION] != NULL) {
    return action->action_egg[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_egg) {
    if ((comp = Traverse_compare_egg_Uses (egg_egg_uses(x),egg_egg_uses(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_egg_Statement (egg_egg_groups(x),egg_egg_groups(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_egg_Uses (egg_Uses x, egg_Uses y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_Uses[PRE_ACTION] != NULL) {
    return action->action_Uses[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Uses) {
    if ((comp = Traverse_compare_List_String (egg_Uses_uses(x),egg_Uses_uses(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_egg_Declaration (egg_Declaration x, egg_Declaration y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_Declaration[PRE_ACTION] != NULL) {
    return action->action_Declaration[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Declaration) {
    if ((comp = Traverse_compare_egg_MessageKind (egg_Declaration_kind(x),egg_Declaration_kind(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_egg_Expression (egg_Declaration_exprs(x),egg_Declaration_exprs(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_egg_Expression (egg_Expression x, egg_Expression y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_Expression[PRE_ACTION] != NULL) {
    return action->action_Expression[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (egg_Expression_tag(x) < egg_Expression_tag(y)) return -1;
  if (egg_Expression_tag(x) > egg_Expression_tag(y)) return 1;;
  switch (egg_Expression_tag(x)) {
      case egg_StringExpr_kind:
        if (action->action_StringExpr[PRE_ACTION] != NULL) {
          return action->action_StringExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_StringExpr) {
          if ((comp = Traverse_compare_String (egg_StringExpr_s(x),egg_StringExpr_s(y), action)) != 0) return comp;
        }
        if (action->action_StringExpr[POST_ACTION] != NULL) {
          return action->action_StringExpr[POST_ACTION](x, y);
        }
        break;
      case egg_CallExpr_kind:
        if (action->action_CallExpr[PRE_ACTION] != NULL) {
          return action->action_CallExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_CallExpr) {
          if ((comp = Traverse_compare_Ident (egg_CallExpr_id(x),egg_CallExpr_id(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_egg_Expression (egg_CallExpr_params(x),egg_CallExpr_params(y), action)) != 0) return comp;
        }
        if (action->action_CallExpr[POST_ACTION] != NULL) {
          return action->action_CallExpr[POST_ACTION](x, y);
        }
        break;
      case egg_IdExpr_kind:
        if (action->action_IdExpr[PRE_ACTION] != NULL) {
          return action->action_IdExpr[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IdExpr) {
          if ((comp = Traverse_compare_Ident (egg_IdExpr_id(x),egg_IdExpr_id(y), action)) != 0) return comp;
        }
        if (action->action_IdExpr[POST_ACTION] != NULL) {
          return action->action_IdExpr[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_egg_Statement (egg_Statement x, egg_Statement y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_Statement[PRE_ACTION] != NULL) {
    return action->action_Statement[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (egg_Statement_tag(x) < egg_Statement_tag(y)) return -1;
  if (egg_Statement_tag(x) > egg_Statement_tag(y)) return 1;;
  switch (egg_Statement_tag(x)) {
      case egg_Message_kind:
        if (action->action_Message[PRE_ACTION] != NULL) {
          return action->action_Message[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Statement) {
          if ((comp = Traverse_compare_Bool (egg_Statement_fatal(x),egg_Statement_fatal(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (egg_Statement_id(x),egg_Statement_id(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Message) {
          if ((comp = Traverse_compare_List_egg_SubMessage (egg_Message_msgs(x),egg_Message_msgs(y), action)) != 0) return comp;
        }
        if (action->action_Message[POST_ACTION] != NULL) {
          return action->action_Message[POST_ACTION](x, y);
        }
        break;
      case egg_Group_kind:
        if (action->action_Group[PRE_ACTION] != NULL) {
          return action->action_Group[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Statement) {
          if ((comp = Traverse_compare_Bool (egg_Statement_fatal(x),egg_Statement_fatal(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (egg_Statement_id(x),egg_Statement_id(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Group) {
          if ((comp = Traverse_compare_Ident (egg_Group_type(x),egg_Group_type(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Bool (egg_Group_group(x),egg_Group_group(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_egg_Declaration (egg_Group_decls(x),egg_Group_decls(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_egg_Statement (egg_Group_stats(x),egg_Group_stats(y), action)) != 0) return comp;
        }
        if (action->action_Group[POST_ACTION] != NULL) {
          return action->action_Group[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_egg_SubMessage (egg_SubMessage x, egg_SubMessage y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_SubMessage[PRE_ACTION] != NULL) {
    return action->action_SubMessage[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_SubMessage) {
    if ((comp = Traverse_compare_egg_MessageKind (egg_SubMessage_kind(x),egg_SubMessage_kind(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_String (egg_SubMessage_msg(x),egg_SubMessage_msg(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_egg_Scope (egg_Scope x, egg_Scope y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    return action->action_Scope[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (egg_Scope_tag(x) < egg_Scope_tag(y)) return -1;
  if (egg_Scope_tag(x) > egg_Scope_tag(y)) return 1;;
  switch (egg_Scope_tag(x)) {
      case egg_GroupScope_kind:
        if (action->action_GroupScope[PRE_ACTION] != NULL) {
          return action->action_GroupScope[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Scope) {
          if ((comp = Traverse_compare_egg_Scope (egg_Scope_next(x),egg_Scope_next(y), action)) != 0) return comp;
        }
        if (!action->skip_children_GroupScope) {
          if ((comp = Traverse_compare_egg_Statement (egg_GroupScope_data(x),egg_GroupScope_data(y), action)) != 0) return comp;
        }
        if (action->action_GroupScope[POST_ACTION] != NULL) {
          return action->action_GroupScope[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_List_egg_Declaration (List_egg_Declaration x, List_egg_Declaration y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Declaration[PRE_ACTION] != NULL) {
    return action->action_List_Declaration[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Declaration) {
    if ((comp = Traverse_compare_egg_Declaration (List_egg_Declaration_data(x),List_egg_Declaration_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_egg_Declaration (List_egg_Declaration_next(x),List_egg_Declaration_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_egg_SubMessage (List_egg_SubMessage x, List_egg_SubMessage y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_List_SubMessage[PRE_ACTION] != NULL) {
    return action->action_List_SubMessage[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_SubMessage) {
    if ((comp = Traverse_compare_egg_SubMessage (List_egg_SubMessage_data(x),List_egg_SubMessage_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_egg_SubMessage (List_egg_SubMessage_next(x),List_egg_SubMessage_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_egg_Expression (List_egg_Expression x, List_egg_Expression y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Expression[PRE_ACTION] != NULL) {
    return action->action_List_Expression[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Expression) {
    if ((comp = Traverse_compare_egg_Expression (List_egg_Expression_data(x),List_egg_Expression_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_egg_Expression (List_egg_Expression_next(x),List_egg_Expression_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_egg_Statement (List_egg_Statement x, List_egg_Statement y, compare_egg_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Statement[PRE_ACTION] != NULL) {
    return action->action_List_Statement[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Statement) {
    if ((comp = Traverse_compare_egg_Statement (List_egg_Statement_data(x),List_egg_Statement_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_egg_Statement (List_egg_Statement_next(x),List_egg_Statement_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_egg_MessageKind (egg_MessageKind x, egg_MessageKind y, compare_egg_TraverseTable action)
{ if (action->action_MessageKind[PRE_ACTION] != NULL) {
    return action->action_MessageKind[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

static void* PushScope_egg_Message (egg_Message me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (egg_Scope) val;
  egg_Statement_scope(me) = (egg_Scope) val;
  return val;
}

static void* PushScope_egg_Group (egg_Group me, void *val)
{ if (me == NULL) return val;
  me->old_scope = (egg_Scope) val;
  if (egg_Statement_scope(me) != NULL &&
      egg_Scope_next(egg_Statement_scope(me))==(egg_Scope)val &&
      GroupScope_data(egg_Statement_scope(me)) == me)
       val = egg_Statement_scope(me);
  else {
    val = (void*)Create_GroupScope ((egg_Scope)val, me);
  }
  egg_Statement_scope(me) = (egg_Scope) val;
  return val;
}

static void* PopScope_egg_Group (egg_Group me, void *val)
{ if (me == NULL) return val;
  val = (void*)me->old_scope;
  return val;
}

struct s_egg_TraverseTable egg_scope_actions = {

  Traverse_Accumulate,
  { NULL,	NULL }, FALSE,	/* egg_egg */
  { NULL,	NULL }, FALSE,	/* egg_Uses */
  { NULL,	NULL }, FALSE,	/* egg_Declaration */
  { NULL,	NULL }, FALSE,	/* egg_Expression */
  { NULL,	NULL }, FALSE,	/* egg_StringExpr */
  { NULL,	NULL }, FALSE,	/* egg_CallExpr */
  { NULL,	NULL }, FALSE,	/* egg_IdExpr */
  { NULL,	NULL }, FALSE,	/* egg_Statement */
  { NULL,	PushScope_egg_Message }, FALSE,	/* egg_Message */
  { PopScope_egg_Group,	PushScope_egg_Group }, FALSE,	/* egg_Group */
  { NULL,	NULL }, FALSE,	/* egg_SubMessage */
  { NULL,	NULL }, FALSE,	/* egg_Scope */
  { NULL,	NULL }, FALSE,	/* egg_GroupScope */
  { NULL,	NULL }, FALSE,	/* List_egg_Declaration */
  { NULL,	NULL }, FALSE,	/* List_egg_SubMessage */
  { NULL,	NULL }, FALSE,	/* List_egg_Expression */
  { NULL,	NULL }, FALSE,	/* List_egg_Statement */
  { NULL,	 NULL }, FALSE,	/* egg_MessageKind */
  { NULL,	 NULL }, FALSE,	/* egg_ErrorMsg */
  { NULL,	 NULL }, FALSE,	/* egg_WarningMsg */
  { NULL,	 NULL }, FALSE,	/* egg_DisabledMsg */
  { NULL,	 NULL }, FALSE,	/* egg_KeyMsg */
  { NULL,	 NULL }, FALSE,	/* egg_PostMsg */
};

static void Defining_egg_egg (egg_egg me)
{
  if (me==NULL) return;
}

static void Defining_egg_Uses (egg_Uses me)
{
  if (me==NULL) return;
}

static void Defining_egg_Declaration (egg_Declaration me)
{
  if (me==NULL) return;
}

static void Defining_egg_Expression (egg_Expression me)
{
  if (me==NULL) return;
}

static void Defining_egg_Statement (egg_Statement me)
{
  Scope scope;
  if (me==NULL) return;
  scope = egg_Statement_scope(me);
  egg_Statement__num(me) = Scope_Num_Stores (scope);
}

static void Defining_egg_Group (egg_Group me)
{
  Scope scope;
  if (me==NULL) return;
  Scope__self (egg_Statement_scope(me)) = Scope_Num_Stores (egg_Statement_old_scope(me));
  scope = egg_Scope_next(egg_Statement_scope(me));
  egg_Statement__num(me) = Scope_Num_Stores (scope);
}

static void Defining_egg_SubMessage (egg_SubMessage me)
{
  if (me==NULL) return;
}

struct s_void_egg_TraverseTable egg_defining_actions = {

  { NULL,	(void*)Defining_egg_egg }, FALSE,	/* egg_egg */
  { NULL,	(void*)Defining_egg_Uses }, FALSE,	/* egg_Uses */
  { NULL,	(void*)Defining_egg_Declaration }, FALSE,	/* egg_Declaration */
  { NULL,	(void*)Defining_egg_Expression }, FALSE,	/* egg_Expression */
  { NULL,	NULL }, FALSE,	/* egg_StringExpr */
  { NULL,	NULL }, FALSE,	/* egg_CallExpr */
  { NULL,	NULL }, FALSE,	/* egg_IdExpr */
  { NULL,	(void*)Defining_egg_Statement }, FALSE,	/* egg_Statement */
  { NULL,	NULL }, FALSE,	/* egg_Message */
  { NULL,	(void*)Defining_egg_Group }, FALSE,	/* egg_Group */
  { NULL,	(void*)Defining_egg_SubMessage }, FALSE,	/* egg_SubMessage */
  { NULL,	NULL }, FALSE,	/* egg_Scope */
  { NULL,	NULL }, FALSE,	/* egg_GroupScope */
  { NULL,	NULL }, FALSE,	/* List_egg_Declaration */
  { NULL,	NULL }, FALSE,	/* List_egg_SubMessage */
  { NULL,	NULL }, FALSE,	/* List_egg_Expression */
  { NULL,	NULL }, FALSE,	/* List_egg_Statement */
  { NULL,	 NULL }, FALSE,	/* egg_MessageKind */
  { NULL,	 NULL }, FALSE,	/* egg_ErrorMsg */
  { NULL,	 NULL }, FALSE,	/* egg_WarningMsg */
  { NULL,	 NULL }, FALSE,	/* egg_DisabledMsg */
  { NULL,	 NULL }, FALSE,	/* egg_KeyMsg */
  { NULL,	 NULL }, FALSE,	/* egg_PostMsg */
};

struct s_void_egg_TraverseTable egg_applied_actions = {

  { NULL,	NULL }, FALSE,	/* egg_egg */
  { NULL,	NULL }, FALSE,	/* egg_Uses */
  { NULL,	NULL }, FALSE,	/* egg_Declaration */
  { NULL,	NULL }, FALSE,	/* egg_Expression */
  { NULL,	NULL }, FALSE,	/* egg_StringExpr */
  { NULL,	NULL }, FALSE,	/* egg_CallExpr */
  { NULL,	NULL }, FALSE,	/* egg_IdExpr */
  { NULL,	NULL }, FALSE,	/* egg_Statement */
  { NULL,	NULL }, FALSE,	/* egg_Message */
  { NULL,	NULL }, FALSE,	/* egg_Group */
  { NULL,	NULL }, FALSE,	/* egg_SubMessage */
  { NULL,	NULL }, FALSE,	/* egg_Scope */
  { NULL,	NULL }, FALSE,	/* egg_GroupScope */
  { NULL,	NULL }, FALSE,	/* List_egg_Declaration */
  { NULL,	NULL }, FALSE,	/* List_egg_SubMessage */
  { NULL,	NULL }, FALSE,	/* List_egg_Expression */
  { NULL,	NULL }, FALSE,	/* List_egg_Statement */
  { NULL,	 NULL }, FALSE,	/* egg_MessageKind */
  { NULL,	 NULL }, FALSE,	/* egg_ErrorMsg */
  { NULL,	 NULL }, FALSE,	/* egg_WarningMsg */
  { NULL,	 NULL }, FALSE,	/* egg_DisabledMsg */
  { NULL,	 NULL }, FALSE,	/* egg_KeyMsg */
  { NULL,	 NULL }, FALSE,	/* egg_PostMsg */
};

struct s_void_egg_TraverseTable egg_check_actions = {

  { NULL,	NULL }, FALSE,	/* egg_egg */
  { NULL,	NULL }, FALSE,	/* egg_Uses */
  { NULL,	NULL }, FALSE,	/* egg_Declaration */
  { NULL,	NULL }, FALSE,	/* egg_Expression */
  { NULL,	NULL }, FALSE,	/* egg_StringExpr */
  { NULL,	NULL }, FALSE,	/* egg_CallExpr */
  { NULL,	NULL }, FALSE,	/* egg_IdExpr */
  { NULL,	NULL }, FALSE,	/* egg_Statement */
  { NULL,	NULL }, FALSE,	/* egg_Message */
  { NULL,	NULL }, FALSE,	/* egg_Group */
  { NULL,	NULL }, FALSE,	/* egg_SubMessage */
  { NULL,	NULL }, FALSE,	/* egg_Scope */
  { NULL,	NULL }, FALSE,	/* egg_GroupScope */
  { NULL,	NULL }, FALSE,	/* List_egg_Declaration */
  { NULL,	NULL }, FALSE,	/* List_egg_SubMessage */
  { NULL,	NULL }, FALSE,	/* List_egg_Expression */
  { NULL,	NULL }, FALSE,	/* List_egg_Statement */
  { NULL,	 NULL }, FALSE,	/* egg_MessageKind */
  { NULL,	 NULL }, FALSE,	/* egg_ErrorMsg */
  { NULL,	 NULL }, FALSE,	/* egg_WarningMsg */
  { NULL,	 NULL }, FALSE,	/* egg_DisabledMsg */
  { NULL,	 NULL }, FALSE,	/* egg_KeyMsg */
  { NULL,	 NULL }, FALSE,	/* egg_PostMsg */
};

struct s_void_egg_TraverseTable egg_print_actions;

struct s_copy_egg_TraverseTable egg_copy_actions;

struct s_compare_egg_TraverseTable egg_compare_actions;

void egg_fill_table (egg_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_egg[PRE_ACTION] = (void* (*) (egg_egg, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_egg[POST_ACTION] = (void* (*) (egg_egg, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Uses[PRE_ACTION] = (void* (*) (egg_Uses, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Uses[POST_ACTION] = (void* (*) (egg_Uses, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Declaration[PRE_ACTION] = (void* (*) (egg_Declaration, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Declaration[POST_ACTION] = (void* (*) (egg_Declaration, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expression[PRE_ACTION] = (void* (*) (egg_Expression, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expression[POST_ACTION] = (void* (*) (egg_Expression, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringExpr[PRE_ACTION] = (void* (*) (egg_StringExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringExpr[POST_ACTION] = (void* (*) (egg_StringExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CallExpr[PRE_ACTION] = (void* (*) (egg_CallExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CallExpr[POST_ACTION] = (void* (*) (egg_CallExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdExpr[PRE_ACTION] = (void* (*) (egg_IdExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdExpr[POST_ACTION] = (void* (*) (egg_IdExpr, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Statement[PRE_ACTION] = (void* (*) (egg_Statement, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Statement[POST_ACTION] = (void* (*) (egg_Statement, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Message[PRE_ACTION] = (void* (*) (egg_Message, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Message[POST_ACTION] = (void* (*) (egg_Message, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Group[PRE_ACTION] = (void* (*) (egg_Group, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Group[POST_ACTION] = (void* (*) (egg_Group, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubMessage[PRE_ACTION] = (void* (*) (egg_SubMessage, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubMessage[POST_ACTION] = (void* (*) (egg_SubMessage, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void* (*) (egg_Scope, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void* (*) (egg_Scope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GroupScope[PRE_ACTION] = (void* (*) (egg_GroupScope, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GroupScope[POST_ACTION] = (void* (*) (egg_GroupScope, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Declaration[PRE_ACTION] = (void* (*) (List_egg_Declaration, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Declaration[POST_ACTION] = (void* (*) (List_egg_Declaration, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_SubMessage[PRE_ACTION] = (void* (*) (List_egg_SubMessage, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_SubMessage[POST_ACTION] = (void* (*) (List_egg_SubMessage, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expression[PRE_ACTION] = (void* (*) (List_egg_Expression, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expression[POST_ACTION] = (void* (*) (List_egg_Expression, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Statement[PRE_ACTION] = (void* (*) (List_egg_Statement, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Statement[POST_ACTION] = (void* (*) (List_egg_Statement, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MessageKind[PRE_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MessageKind[POST_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ErrorMsg[PRE_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ErrorMsg[POST_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WarningMsg[PRE_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WarningMsg[POST_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DisabledMsg[PRE_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DisabledMsg[POST_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_KeyMsg[PRE_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_KeyMsg[POST_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PostMsg[PRE_ACTION] = (void* (*) (egg_MessageKind, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PostMsg[POST_ACTION] = (void* (*) (egg_MessageKind, void*))x;
}

void void_egg_fill_table (void_egg_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_egg[PRE_ACTION] = (void (*) (egg_egg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_egg[POST_ACTION] = (void (*) (egg_egg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Uses[PRE_ACTION] = (void (*) (egg_Uses))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Uses[POST_ACTION] = (void (*) (egg_Uses))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Declaration[PRE_ACTION] = (void (*) (egg_Declaration))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Declaration[POST_ACTION] = (void (*) (egg_Declaration))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expression[PRE_ACTION] = (void (*) (egg_Expression))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expression[POST_ACTION] = (void (*) (egg_Expression))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringExpr[PRE_ACTION] = (void (*) (egg_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringExpr[POST_ACTION] = (void (*) (egg_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CallExpr[PRE_ACTION] = (void (*) (egg_CallExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CallExpr[POST_ACTION] = (void (*) (egg_CallExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdExpr[PRE_ACTION] = (void (*) (egg_IdExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdExpr[POST_ACTION] = (void (*) (egg_IdExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Statement[PRE_ACTION] = (void (*) (egg_Statement))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Statement[POST_ACTION] = (void (*) (egg_Statement))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Message[PRE_ACTION] = (void (*) (egg_Message))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Message[POST_ACTION] = (void (*) (egg_Message))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Group[PRE_ACTION] = (void (*) (egg_Group))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Group[POST_ACTION] = (void (*) (egg_Group))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubMessage[PRE_ACTION] = (void (*) (egg_SubMessage))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubMessage[POST_ACTION] = (void (*) (egg_SubMessage))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void (*) (egg_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void (*) (egg_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GroupScope[PRE_ACTION] = (void (*) (egg_GroupScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GroupScope[POST_ACTION] = (void (*) (egg_GroupScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Declaration[PRE_ACTION] = (void (*) (List_egg_Declaration))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Declaration[POST_ACTION] = (void (*) (List_egg_Declaration))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_SubMessage[PRE_ACTION] = (void (*) (List_egg_SubMessage))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_SubMessage[POST_ACTION] = (void (*) (List_egg_SubMessage))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expression[PRE_ACTION] = (void (*) (List_egg_Expression))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expression[POST_ACTION] = (void (*) (List_egg_Expression))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Statement[PRE_ACTION] = (void (*) (List_egg_Statement))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Statement[POST_ACTION] = (void (*) (List_egg_Statement))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MessageKind[PRE_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MessageKind[POST_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ErrorMsg[PRE_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ErrorMsg[POST_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WarningMsg[PRE_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WarningMsg[POST_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DisabledMsg[PRE_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DisabledMsg[POST_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_KeyMsg[PRE_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_KeyMsg[POST_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PostMsg[PRE_ACTION] = (void (*) (egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PostMsg[POST_ACTION] = (void (*) (egg_MessageKind))x;
}

void copy_egg_fill_table (copy_egg_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_egg[PRE_ACTION] = (egg_egg (*) (egg_egg, egg_egg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_egg[POST_ACTION] = (egg_egg (*) (egg_egg, egg_egg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Uses[PRE_ACTION] = (egg_Uses (*) (egg_Uses, egg_Uses))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Uses[POST_ACTION] = (egg_Uses (*) (egg_Uses, egg_Uses))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Declaration[PRE_ACTION] = (egg_Declaration (*) (egg_Declaration, egg_Declaration))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Declaration[POST_ACTION] = (egg_Declaration (*) (egg_Declaration, egg_Declaration))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expression[PRE_ACTION] = (egg_Expression (*) (egg_Expression, egg_Expression))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expression[POST_ACTION] = (egg_Expression (*) (egg_Expression, egg_Expression))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringExpr[PRE_ACTION] = (egg_StringExpr (*) (egg_StringExpr, egg_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringExpr[POST_ACTION] = (egg_StringExpr (*) (egg_StringExpr, egg_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CallExpr[PRE_ACTION] = (egg_CallExpr (*) (egg_CallExpr, egg_CallExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CallExpr[POST_ACTION] = (egg_CallExpr (*) (egg_CallExpr, egg_CallExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdExpr[PRE_ACTION] = (egg_IdExpr (*) (egg_IdExpr, egg_IdExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdExpr[POST_ACTION] = (egg_IdExpr (*) (egg_IdExpr, egg_IdExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Statement[PRE_ACTION] = (egg_Statement (*) (egg_Statement, egg_Statement))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Statement[POST_ACTION] = (egg_Statement (*) (egg_Statement, egg_Statement))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Message[PRE_ACTION] = (egg_Message (*) (egg_Message, egg_Message))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Message[POST_ACTION] = (egg_Message (*) (egg_Message, egg_Message))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Group[PRE_ACTION] = (egg_Group (*) (egg_Group, egg_Group))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Group[POST_ACTION] = (egg_Group (*) (egg_Group, egg_Group))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubMessage[PRE_ACTION] = (egg_SubMessage (*) (egg_SubMessage, egg_SubMessage))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubMessage[POST_ACTION] = (egg_SubMessage (*) (egg_SubMessage, egg_SubMessage))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (egg_Scope (*) (egg_Scope, egg_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (egg_Scope (*) (egg_Scope, egg_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GroupScope[PRE_ACTION] = (egg_GroupScope (*) (egg_GroupScope, egg_GroupScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GroupScope[POST_ACTION] = (egg_GroupScope (*) (egg_GroupScope, egg_GroupScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Declaration[PRE_ACTION] = (List_egg_Declaration (*) (List_egg_Declaration, List_egg_Declaration))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Declaration[POST_ACTION] = (List_egg_Declaration (*) (List_egg_Declaration, List_egg_Declaration))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_SubMessage[PRE_ACTION] = (List_egg_SubMessage (*) (List_egg_SubMessage, List_egg_SubMessage))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_SubMessage[POST_ACTION] = (List_egg_SubMessage (*) (List_egg_SubMessage, List_egg_SubMessage))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expression[PRE_ACTION] = (List_egg_Expression (*) (List_egg_Expression, List_egg_Expression))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expression[POST_ACTION] = (List_egg_Expression (*) (List_egg_Expression, List_egg_Expression))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Statement[PRE_ACTION] = (List_egg_Statement (*) (List_egg_Statement, List_egg_Statement))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Statement[POST_ACTION] = (List_egg_Statement (*) (List_egg_Statement, List_egg_Statement))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MessageKind[PRE_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MessageKind[POST_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ErrorMsg[PRE_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ErrorMsg[POST_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WarningMsg[PRE_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WarningMsg[POST_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DisabledMsg[PRE_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DisabledMsg[POST_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_KeyMsg[PRE_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_KeyMsg[POST_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PostMsg[PRE_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PostMsg[POST_ACTION] = (egg_MessageKind (*) (egg_MessageKind, egg_MessageKind))x;
}

void compare_egg_fill_table (compare_egg_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_egg[PRE_ACTION] = (int (*) (egg_egg, egg_egg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_egg[POST_ACTION] = (int (*) (egg_egg, egg_egg))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Uses[PRE_ACTION] = (int (*) (egg_Uses, egg_Uses))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Uses[POST_ACTION] = (int (*) (egg_Uses, egg_Uses))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Declaration[PRE_ACTION] = (int (*) (egg_Declaration, egg_Declaration))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Declaration[POST_ACTION] = (int (*) (egg_Declaration, egg_Declaration))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Expression[PRE_ACTION] = (int (*) (egg_Expression, egg_Expression))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Expression[POST_ACTION] = (int (*) (egg_Expression, egg_Expression))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringExpr[PRE_ACTION] = (int (*) (egg_StringExpr, egg_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringExpr[POST_ACTION] = (int (*) (egg_StringExpr, egg_StringExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_CallExpr[PRE_ACTION] = (int (*) (egg_CallExpr, egg_CallExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_CallExpr[POST_ACTION] = (int (*) (egg_CallExpr, egg_CallExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdExpr[PRE_ACTION] = (int (*) (egg_IdExpr, egg_IdExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdExpr[POST_ACTION] = (int (*) (egg_IdExpr, egg_IdExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Statement[PRE_ACTION] = (int (*) (egg_Statement, egg_Statement))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Statement[POST_ACTION] = (int (*) (egg_Statement, egg_Statement))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Message[PRE_ACTION] = (int (*) (egg_Message, egg_Message))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Message[POST_ACTION] = (int (*) (egg_Message, egg_Message))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Group[PRE_ACTION] = (int (*) (egg_Group, egg_Group))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Group[POST_ACTION] = (int (*) (egg_Group, egg_Group))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SubMessage[PRE_ACTION] = (int (*) (egg_SubMessage, egg_SubMessage))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SubMessage[POST_ACTION] = (int (*) (egg_SubMessage, egg_SubMessage))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (int (*) (egg_Scope, egg_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (int (*) (egg_Scope, egg_Scope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_GroupScope[PRE_ACTION] = (int (*) (egg_GroupScope, egg_GroupScope))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_GroupScope[POST_ACTION] = (int (*) (egg_GroupScope, egg_GroupScope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Declaration[PRE_ACTION] = (int (*) (List_egg_Declaration, List_egg_Declaration))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Declaration[POST_ACTION] = (int (*) (List_egg_Declaration, List_egg_Declaration))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_SubMessage[PRE_ACTION] = (int (*) (List_egg_SubMessage, List_egg_SubMessage))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_SubMessage[POST_ACTION] = (int (*) (List_egg_SubMessage, List_egg_SubMessage))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Expression[PRE_ACTION] = (int (*) (List_egg_Expression, List_egg_Expression))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Expression[POST_ACTION] = (int (*) (List_egg_Expression, List_egg_Expression))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Statement[PRE_ACTION] = (int (*) (List_egg_Statement, List_egg_Statement))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Statement[POST_ACTION] = (int (*) (List_egg_Statement, List_egg_Statement))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_MessageKind[PRE_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_MessageKind[POST_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ErrorMsg[PRE_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ErrorMsg[POST_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_WarningMsg[PRE_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_WarningMsg[POST_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_DisabledMsg[PRE_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_DisabledMsg[POST_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_KeyMsg[PRE_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_KeyMsg[POST_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PostMsg[PRE_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PostMsg[POST_ACTION] = (int (*) (egg_MessageKind, egg_MessageKind))x;
}

egg_NameSpaces egg_namespaces[] = { -1 };

void Decorate_egg (egg_egg r)
{
  if (egg_namespaces[0]<0) Extend_namespaces (egg_NUM_NAMESPACES, egg_namespaces);
  egg_root = r;
  if (NoDecorate) return;
  Traverse_egg_egg (r, &egg_scope_actions, NULL);
  Traverse_void_egg_egg (r, &egg_defining_actions);
  Traverse_void_egg_egg (r, &egg_applied_actions);
  Traverse_void_egg_egg (r, &egg_check_actions);
}
