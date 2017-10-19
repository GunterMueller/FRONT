#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "front/error.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/mem.h"
#include "Pictures.h"

#ifndef Pictures_SKIP_NODE
# define Pictures_SKIP_NODE(n,t) FALSE
#endif

Pictures Pictures_root;

String Pictures_Direction_names[] = {
  "Left",
  "Right",
  "Up",
  "Down",
  "Center",
};

String Pictures_Picture_tag_names[] = {
  "Empty_kind",
  "Box_kind",
  "Circle_kind",
  "Arc_kind",
  "Curve_kind",
  "Line_kind",
  "Arrow_kind",
  "Text_kind",
  "OrBlock_kind",
  "AndBlock_kind",
  "AltBlock_kind",
  "Compound_kind",
};

Pictures_Pictures Create_Pictures_Pictures	(SrcInfo src_info, List_Pictures_Picture pics)
{ Pictures_Pictures me = (Pictures_Pictures)fe_malloc(sizeof(*me));
  Pictures_Pictures_src_info(me) = src_info;
  Pictures_Pictures_pics(me) = pics;
  Pictures_Pictures_hook(me) = NULL;
  return me;
}

Pictures_Compound Create_Pictures_Compound	(SrcInfo src_info, Float x, Float y, Float w, Float h, List_Pictures_Picture sub)
{ Pictures_Compound me = (Pictures_Compound)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_Compound_sub(me) = sub;
  Pictures_Picture_tag(me) = Pictures_Compound_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_AltBlock Create_Pictures_AltBlock	(SrcInfo src_info, Float x, Float y, Float w, Float h, Pictures_Picture a, Pictures_Picture b, Bool turn_left)
{ Pictures_AltBlock me = (Pictures_AltBlock)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_AltBlock_a(me) = a;
  Pictures_AltBlock_b(me) = b;
  Pictures_AltBlock_turn_left(me) = turn_left;
  Pictures_Picture_tag(me) = Pictures_AltBlock_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_AndBlock Create_Pictures_AndBlock	(SrcInfo src_info, Float x, Float y, Float w, Float h, List_Pictures_Picture sub, List_Pictures_Direction dirs)
{ Pictures_AndBlock me = (Pictures_AndBlock)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_AndBlock_sub(me) = sub;
  Pictures_AndBlock_dirs(me) = dirs;
  Pictures_Picture_tag(me) = Pictures_AndBlock_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_OrBlock Create_Pictures_OrBlock	(SrcInfo src_info, Float x, Float y, Float w, Float h, List_Pictures_Picture sub, List_Pictures_Direction dirs)
{ Pictures_OrBlock me = (Pictures_OrBlock)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_OrBlock_sub(me) = sub;
  Pictures_OrBlock_dirs(me) = dirs;
  Pictures_Picture_tag(me) = Pictures_OrBlock_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_Text Create_Pictures_Text	(SrcInfo src_info, Float x, Float y, Float w, Float h, String text, Ident font)
{ Pictures_Text me = (Pictures_Text)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_Text_text(me) = text;
  Pictures_Text_font(me) = font;
  Pictures_Picture_tag(me) = Pictures_Text_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_Arrow Create_Pictures_Arrow	(SrcInfo src_info, Float x, Float y, Float w, Float h, Pictures_Direction dir)
{ Pictures_Arrow me = (Pictures_Arrow)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_Arrow_dir(me) = dir;
  Pictures_Picture_tag(me) = Pictures_Arrow_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_Line Create_Pictures_Line	(SrcInfo src_info, Float x, Float y, Float w, Float h)
{ Pictures_Line me = (Pictures_Line)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_Picture_tag(me) = Pictures_Line_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_Curve Create_Pictures_Curve	(SrcInfo src_info, Float x, Float y, Float w, Float h, Bool d1, Bool d2)
{ Pictures_Curve me = (Pictures_Curve)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_Curve_d1(me) = d1;
  Pictures_Curve_d2(me) = d2;
  Pictures_Picture_tag(me) = Pictures_Curve_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_Arc Create_Pictures_Arc	(SrcInfo src_info, Float x, Float y, Float w, Float h, Float phi_1, Float phi_2)
{ Pictures_Arc me = (Pictures_Arc)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_Arc_phi_1(me) = phi_1;
  Pictures_Arc_phi_2(me) = phi_2;
  Pictures_Picture_tag(me) = Pictures_Arc_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_Circle Create_Pictures_Circle	(SrcInfo src_info, Float x, Float y, Float w, Float h)
{ Pictures_Circle me = (Pictures_Circle)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_Picture_tag(me) = Pictures_Circle_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_Box Create_Pictures_Box	(SrcInfo src_info, Float x, Float y, Float w, Float h)
{ Pictures_Box me = (Pictures_Box)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_Picture_tag(me) = Pictures_Box_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_Empty Create_Pictures_Empty	(SrcInfo src_info, Float x, Float y, Float w, Float h)
{ Pictures_Empty me = (Pictures_Empty)fe_malloc(sizeof(*me));
  Pictures_Picture_src_info(me) = src_info;
  Pictures_Picture_x(me) = x;
  Pictures_Picture_y(me) = y;
  Pictures_Picture_w(me) = w;
  Pictures_Picture_h(me) = h;
  Pictures_Picture_tag(me) = Pictures_Empty_kind;
  Pictures_Picture_hook(me) = NULL;
  Pictures_Picture_d(me) = 0;
  Pictures_Picture_scale(me) = 1;
  Pictures_Picture_phi(me) = 0;
  Pictures_Picture_fill(me) = FALSE;
  Pictures_Picture_dash(me) = 0;
  Pictures_Picture_with_color(me) = FALSE;
  return me;
}

Pictures_Scope Create_Pictures_Scope	(Pictures_Scope next)
{ Pictures_Scope me = (Pictures_Scope)fe_malloc(sizeof(*me));
  Pictures_Scope_next(me) = next;
  Pictures_Scope__self(me) = 0;
  Pictures_Scope__end(me) = 0;
  return me;
}

Pointer Traverse_Pictures_Pictures (Pictures_Pictures me, TraverseTable action, Pointer val)
{ 
  if (Pictures_SKIP_NODE(Pictures, me)) return val;
  if (action->action_Pictures[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Pictures[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Pictures)
  { 
  if (!action->skip_children_Pictures) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_Pictures_Picture (Pictures_Pictures_pics(me), action, val);
    else Traverse_List_Pictures_Picture (Pictures_Pictures_pics(me), action, val);
  }
  }
  if (action->action_Pictures[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Pictures[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Pictures_Picture (Pictures_Picture me, TraverseTable action, Pointer val)
{ 
  if (Pictures_SKIP_NODE(Picture, me)) return val;
  if (action->action_Picture[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Picture[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Picture)
  { switch (Pictures_Picture_tag(me)) {
      case Pictures_Empty_kind:
        if (action->action_Empty[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Empty[PRE_ACTION](me, val);
        }
        if (action->action_Empty[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Empty[POST_ACTION](me, val);
        }
        break;
      case Pictures_Box_kind:
        if (action->action_Box[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Box[PRE_ACTION](me, val);
        }
        if (action->action_Box[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Box[POST_ACTION](me, val);
        }
        break;
      case Pictures_Circle_kind:
        if (action->action_Circle[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Circle[PRE_ACTION](me, val);
        }
        if (action->action_Circle[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Circle[POST_ACTION](me, val);
        }
        break;
      case Pictures_Arc_kind:
        if (action->action_Arc[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Arc[PRE_ACTION](me, val);
        }
        if (action->action_Arc[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Arc[POST_ACTION](me, val);
        }
        break;
      case Pictures_Curve_kind:
        if (action->action_Curve[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Curve[PRE_ACTION](me, val);
        }
        if (action->action_Curve[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Curve[POST_ACTION](me, val);
        }
        break;
      case Pictures_Line_kind:
        if (action->action_Line[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Line[PRE_ACTION](me, val);
        }
        if (action->action_Line[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Line[POST_ACTION](me, val);
        }
        break;
      case Pictures_Arrow_kind:
        if (action->action_Arrow[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Arrow[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Arrow) {
          if (action->traversal != Traverse_Down)  val = Traverse_Pictures_Direction (Pictures_Arrow_dir(me), action, val);
          else Traverse_Pictures_Direction (Pictures_Arrow_dir(me), action, val);
        }
        if (action->action_Arrow[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Arrow[POST_ACTION](me, val);
        }
        break;
      case Pictures_Text_kind:
        if (action->action_Text[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Text[PRE_ACTION](me, val);
        }
        if (action->action_Text[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Text[POST_ACTION](me, val);
        }
        break;
      case Pictures_OrBlock_kind:
        if (action->action_OrBlock[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OrBlock[PRE_ACTION](me, val);
        }
        if (!action->skip_children_OrBlock) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_Pictures_Picture (Pictures_OrBlock_sub(me), action, val);
          else Traverse_List_Pictures_Picture (Pictures_OrBlock_sub(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_Pictures_Direction (Pictures_OrBlock_dirs(me), action, val);
          else Traverse_List_Pictures_Direction (Pictures_OrBlock_dirs(me), action, val);
        }
        if (action->action_OrBlock[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OrBlock[POST_ACTION](me, val);
        }
        break;
      case Pictures_AndBlock_kind:
        if (action->action_AndBlock[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndBlock[PRE_ACTION](me, val);
        }
        if (!action->skip_children_AndBlock) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_Pictures_Picture (Pictures_AndBlock_sub(me), action, val);
          else Traverse_List_Pictures_Picture (Pictures_AndBlock_sub(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_Pictures_Direction (Pictures_AndBlock_dirs(me), action, val);
          else Traverse_List_Pictures_Direction (Pictures_AndBlock_dirs(me), action, val);
        }
        if (action->action_AndBlock[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AndBlock[POST_ACTION](me, val);
        }
        break;
      case Pictures_AltBlock_kind:
        if (action->action_AltBlock[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AltBlock[PRE_ACTION](me, val);
        }
        if (!action->skip_children_AltBlock) {
          if (action->traversal != Traverse_Down)  val = Traverse_Pictures_Picture (Pictures_AltBlock_a(me), action, val);
          else Traverse_Pictures_Picture (Pictures_AltBlock_a(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_Pictures_Picture (Pictures_AltBlock_b(me), action, val);
          else Traverse_Pictures_Picture (Pictures_AltBlock_b(me), action, val);
        }
        if (action->action_AltBlock[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AltBlock[POST_ACTION](me, val);
        }
        break;
      case Pictures_Compound_kind:
        if (action->action_Compound[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Compound[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Compound) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_Pictures_Picture (Pictures_Compound_sub(me), action, val);
          else Traverse_List_Pictures_Picture (Pictures_Compound_sub(me), action, val);
        }
        if (action->action_Compound[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Compound[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Picture[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Picture[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Pictures_Scope (Pictures_Scope me, TraverseTable action, Pointer val)
{ 
  if (Pictures_SKIP_NODE(Scope, me)) return val;
  if (action->action_Scope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Scope)
  { 
  if (!action->skip_children_Scope) {
    if (action->traversal != Traverse_Down)  val = Traverse_Pictures_Scope (Pictures_Scope_next(me), action, val);
    else Traverse_Pictures_Scope (Pictures_Scope_next(me), action, val);
  }
  }
  if (action->action_Scope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Pictures_Direction (List_Pictures_Direction me, TraverseTable action, Pointer val)
{ 
  if (Pictures_SKIP_NODE(List_Direction, me)) return val;
  if (action->action_List_Direction[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Direction[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Direction)
  { 
  if (!action->skip_children_List_Direction) {
    if (action->traversal != Traverse_Down)  val = Traverse_Pictures_Direction (List_Pictures_Direction_data(me), action, val);
    else Traverse_Pictures_Direction (List_Pictures_Direction_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Pictures_Direction (List_Pictures_Direction_next(me), action, val);
    else Traverse_List_Pictures_Direction (List_Pictures_Direction_next(me), action, val);
  }
  }
  if (action->action_List_Direction[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Direction[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Pictures_Picture (List_Pictures_Picture me, TraverseTable action, Pointer val)
{ 
  if (Pictures_SKIP_NODE(List_Picture, me)) return val;
  if (action->action_List_Picture[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Picture[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Picture)
  { 
  if (!action->skip_children_List_Picture) {
    if (action->traversal != Traverse_Down)  val = Traverse_Pictures_Picture (List_Pictures_Picture_data(me), action, val);
    else Traverse_Pictures_Picture (List_Pictures_Picture_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Pictures_Picture (List_Pictures_Picture_next(me), action, val);
    else Traverse_List_Pictures_Picture (List_Pictures_Picture_next(me), action, val);
  }
  }
  if (action->action_List_Picture[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Picture[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Pictures_Direction (Pictures_Direction me, TraverseTable action, Pointer val)
{ 
  if (Pictures_SKIP_NODE(Direction, me)) return val;
  if (action->action_Direction[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Direction[PRE_ACTION](me, val);
  }
  { switch (me) {
      case Pictures_Left:
        if (action->action_Left[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Left[PRE_ACTION](me, val);
        }
        if (action->action_Left[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Left[POST_ACTION](me, val);
        }
        break;
      case Pictures_Right:
        if (action->action_Right[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Right[PRE_ACTION](me, val);
        }
        if (action->action_Right[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Right[POST_ACTION](me, val);
        }
        break;
      case Pictures_Up:
        if (action->action_Up[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Up[PRE_ACTION](me, val);
        }
        if (action->action_Up[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Up[POST_ACTION](me, val);
        }
        break;
      case Pictures_Down:
        if (action->action_Down[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Down[PRE_ACTION](me, val);
        }
        if (action->action_Down[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Down[POST_ACTION](me, val);
        }
        break;
      case Pictures_Center:
        if (action->action_Center[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Center[PRE_ACTION](me, val);
        }
        if (action->action_Center[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Center[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Direction[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Direction[POST_ACTION](me, val);
  }
  return val;
}

void Traverse_void_Pictures_Pictures (Pictures_Pictures me, void_Pictures_TraverseTable action)
{ 
  if (Pictures_SKIP_NODE(Pictures, me)) return;
  if (action->action_Pictures[PRE_ACTION] != NULL) {
    action->action_Pictures[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Pictures)
  { 
  if (!action->skip_children_Pictures) {
    Traverse_void_List_Pictures_Picture (Pictures_Pictures_pics(me), action);
  }
  }
  if (action->action_Pictures[POST_ACTION] != NULL) {
    action->action_Pictures[POST_ACTION](me);
  }
}

void Traverse_void_Pictures_Picture (Pictures_Picture me, void_Pictures_TraverseTable action)
{ 
  if (Pictures_SKIP_NODE(Picture, me)) return;
  if (action->action_Picture[PRE_ACTION] != NULL) {
    action->action_Picture[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Picture)
  { switch (Pictures_Picture_tag(me)) {
      case Pictures_Empty_kind:
        if (action->action_Empty[PRE_ACTION] != NULL) {
          action->action_Empty[PRE_ACTION](me);
        }
        if (action->action_Empty[POST_ACTION] != NULL) {
          action->action_Empty[POST_ACTION](me);
        }
        break;
      case Pictures_Box_kind:
        if (action->action_Box[PRE_ACTION] != NULL) {
          action->action_Box[PRE_ACTION](me);
        }
        if (action->action_Box[POST_ACTION] != NULL) {
          action->action_Box[POST_ACTION](me);
        }
        break;
      case Pictures_Circle_kind:
        if (action->action_Circle[PRE_ACTION] != NULL) {
          action->action_Circle[PRE_ACTION](me);
        }
        if (action->action_Circle[POST_ACTION] != NULL) {
          action->action_Circle[POST_ACTION](me);
        }
        break;
      case Pictures_Arc_kind:
        if (action->action_Arc[PRE_ACTION] != NULL) {
          action->action_Arc[PRE_ACTION](me);
        }
        if (action->action_Arc[POST_ACTION] != NULL) {
          action->action_Arc[POST_ACTION](me);
        }
        break;
      case Pictures_Curve_kind:
        if (action->action_Curve[PRE_ACTION] != NULL) {
          action->action_Curve[PRE_ACTION](me);
        }
        if (action->action_Curve[POST_ACTION] != NULL) {
          action->action_Curve[POST_ACTION](me);
        }
        break;
      case Pictures_Line_kind:
        if (action->action_Line[PRE_ACTION] != NULL) {
          action->action_Line[PRE_ACTION](me);
        }
        if (action->action_Line[POST_ACTION] != NULL) {
          action->action_Line[POST_ACTION](me);
        }
        break;
      case Pictures_Arrow_kind:
        if (action->action_Arrow[PRE_ACTION] != NULL) {
          action->action_Arrow[PRE_ACTION](me);
        }
        if (!action->skip_children_Arrow) {
          Traverse_void_Pictures_Direction (Pictures_Arrow_dir(me), action);
        }
        if (action->action_Arrow[POST_ACTION] != NULL) {
          action->action_Arrow[POST_ACTION](me);
        }
        break;
      case Pictures_Text_kind:
        if (action->action_Text[PRE_ACTION] != NULL) {
          action->action_Text[PRE_ACTION](me);
        }
        if (action->action_Text[POST_ACTION] != NULL) {
          action->action_Text[POST_ACTION](me);
        }
        break;
      case Pictures_OrBlock_kind:
        if (action->action_OrBlock[PRE_ACTION] != NULL) {
          action->action_OrBlock[PRE_ACTION](me);
        }
        if (!action->skip_children_OrBlock) {
          Traverse_void_List_Pictures_Picture (Pictures_OrBlock_sub(me), action);
          Traverse_void_List_Pictures_Direction (Pictures_OrBlock_dirs(me), action);
        }
        if (action->action_OrBlock[POST_ACTION] != NULL) {
          action->action_OrBlock[POST_ACTION](me);
        }
        break;
      case Pictures_AndBlock_kind:
        if (action->action_AndBlock[PRE_ACTION] != NULL) {
          action->action_AndBlock[PRE_ACTION](me);
        }
        if (!action->skip_children_AndBlock) {
          Traverse_void_List_Pictures_Picture (Pictures_AndBlock_sub(me), action);
          Traverse_void_List_Pictures_Direction (Pictures_AndBlock_dirs(me), action);
        }
        if (action->action_AndBlock[POST_ACTION] != NULL) {
          action->action_AndBlock[POST_ACTION](me);
        }
        break;
      case Pictures_AltBlock_kind:
        if (action->action_AltBlock[PRE_ACTION] != NULL) {
          action->action_AltBlock[PRE_ACTION](me);
        }
        if (!action->skip_children_AltBlock) {
          Traverse_void_Pictures_Picture (Pictures_AltBlock_a(me), action);
          Traverse_void_Pictures_Picture (Pictures_AltBlock_b(me), action);
        }
        if (action->action_AltBlock[POST_ACTION] != NULL) {
          action->action_AltBlock[POST_ACTION](me);
        }
        break;
      case Pictures_Compound_kind:
        if (action->action_Compound[PRE_ACTION] != NULL) {
          action->action_Compound[PRE_ACTION](me);
        }
        if (!action->skip_children_Compound) {
          Traverse_void_List_Pictures_Picture (Pictures_Compound_sub(me), action);
        }
        if (action->action_Compound[POST_ACTION] != NULL) {
          action->action_Compound[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Picture[POST_ACTION] != NULL) {
    action->action_Picture[POST_ACTION](me);
  }
}

void Traverse_void_Pictures_Scope (Pictures_Scope me, void_Pictures_TraverseTable action)
{ 
  if (Pictures_SKIP_NODE(Scope, me)) return;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    action->action_Scope[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Scope)
  { 
  if (!action->skip_children_Scope) {
    Traverse_void_Pictures_Scope (Pictures_Scope_next(me), action);
  }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    action->action_Scope[POST_ACTION](me);
  }
}

void Traverse_void_List_Pictures_Direction (List_Pictures_Direction me, void_Pictures_TraverseTable action)
{ 
  if (Pictures_SKIP_NODE(List_Direction, me)) return;
  if (action->action_List_Direction[PRE_ACTION] != NULL) {
    action->action_List_Direction[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Direction)
  { 
  if (!action->skip_children_List_Direction) {
    Traverse_void_Pictures_Direction (List_Pictures_Direction_data(me), action);
    Traverse_void_List_Pictures_Direction (List_Pictures_Direction_next(me), action);
  }
  }
  if (action->action_List_Direction[POST_ACTION] != NULL) {
    action->action_List_Direction[POST_ACTION](me);
  }
}

void Traverse_void_List_Pictures_Picture (List_Pictures_Picture me, void_Pictures_TraverseTable action)
{ 
  if (Pictures_SKIP_NODE(List_Picture, me)) return;
  if (action->action_List_Picture[PRE_ACTION] != NULL) {
    action->action_List_Picture[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Picture)
  { 
  if (!action->skip_children_List_Picture) {
    Traverse_void_Pictures_Picture (List_Pictures_Picture_data(me), action);
    Traverse_void_List_Pictures_Picture (List_Pictures_Picture_next(me), action);
  }
  }
  if (action->action_List_Picture[POST_ACTION] != NULL) {
    action->action_List_Picture[POST_ACTION](me);
  }
}

void Traverse_void_Pictures_Direction (Pictures_Direction me, void_Pictures_TraverseTable action)
{ 
  if (Pictures_SKIP_NODE(Direction, me)) return;
  if (action->action_Direction[PRE_ACTION] != NULL) {
    action->action_Direction[PRE_ACTION](me);
  }
  { switch (me) {
      case Pictures_Left:
        if (action->action_Left[PRE_ACTION] != NULL) {
          action->action_Left[PRE_ACTION](me);
        }
        if (action->action_Left[POST_ACTION] != NULL) {
          action->action_Left[POST_ACTION](me);
        }
        break;
      case Pictures_Right:
        if (action->action_Right[PRE_ACTION] != NULL) {
          action->action_Right[PRE_ACTION](me);
        }
        if (action->action_Right[POST_ACTION] != NULL) {
          action->action_Right[POST_ACTION](me);
        }
        break;
      case Pictures_Up:
        if (action->action_Up[PRE_ACTION] != NULL) {
          action->action_Up[PRE_ACTION](me);
        }
        if (action->action_Up[POST_ACTION] != NULL) {
          action->action_Up[POST_ACTION](me);
        }
        break;
      case Pictures_Down:
        if (action->action_Down[PRE_ACTION] != NULL) {
          action->action_Down[PRE_ACTION](me);
        }
        if (action->action_Down[POST_ACTION] != NULL) {
          action->action_Down[POST_ACTION](me);
        }
        break;
      case Pictures_Center:
        if (action->action_Center[PRE_ACTION] != NULL) {
          action->action_Center[PRE_ACTION](me);
        }
        if (action->action_Center[POST_ACTION] != NULL) {
          action->action_Center[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_Direction[POST_ACTION] != NULL) {
    action->action_Direction[POST_ACTION](me);
  }
}

Pictures_Pictures Traverse_copy_Pictures_Pictures (Pictures_Pictures me, copy_Pictures_TraverseTable action)
{ Pictures_Pictures _new = me, _old = me;
  if (action->action_Pictures[PRE_ACTION] != NULL) {
    _new = action->action_Pictures[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Pictures_Pictures)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Pictures) {
    Pictures_Pictures_pics(me) = Traverse_copy_List_Pictures_Picture (Pictures_Pictures_pics(me), action);
  }
  }
  if (action->action_Pictures[POST_ACTION] != NULL) {
    me = action->action_Pictures[POST_ACTION](me, _old);
  }
  return me;
}

Pictures_Picture Traverse_copy_Pictures_Picture (Pictures_Picture me, copy_Pictures_TraverseTable action)
{ Pictures_Picture _new = me, _old = me;
  if (action->action_Picture[PRE_ACTION] != NULL) {
    _new = action->action_Picture[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Pictures_Picture)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (Pictures_Picture_tag(me)) {
      case Pictures_Empty_kind:
        if (action->action_Empty[PRE_ACTION] != NULL) {
          _new = action->action_Empty[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (action->action_Empty[POST_ACTION] != NULL) {
          _new = action->action_Empty[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_Box_kind:
        if (action->action_Box[PRE_ACTION] != NULL) {
          _new = action->action_Box[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (action->action_Box[POST_ACTION] != NULL) {
          _new = action->action_Box[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_Circle_kind:
        if (action->action_Circle[PRE_ACTION] != NULL) {
          _new = action->action_Circle[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (action->action_Circle[POST_ACTION] != NULL) {
          _new = action->action_Circle[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_Arc_kind:
        if (action->action_Arc[PRE_ACTION] != NULL) {
          _new = action->action_Arc[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (action->action_Arc[POST_ACTION] != NULL) {
          _new = action->action_Arc[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_Curve_kind:
        if (action->action_Curve[PRE_ACTION] != NULL) {
          _new = action->action_Curve[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (action->action_Curve[POST_ACTION] != NULL) {
          _new = action->action_Curve[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_Line_kind:
        if (action->action_Line[PRE_ACTION] != NULL) {
          _new = action->action_Line[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (action->action_Line[POST_ACTION] != NULL) {
          _new = action->action_Line[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_Arrow_kind:
        if (action->action_Arrow[PRE_ACTION] != NULL) {
          _new = action->action_Arrow[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (!action->skip_children_Arrow) {
          Pictures_Arrow_dir(me) = Traverse_copy_Pictures_Direction (Pictures_Arrow_dir(me), action);
        }
        if (action->action_Arrow[POST_ACTION] != NULL) {
          _new = action->action_Arrow[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_Text_kind:
        if (action->action_Text[PRE_ACTION] != NULL) {
          _new = action->action_Text[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (action->action_Text[POST_ACTION] != NULL) {
          _new = action->action_Text[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_OrBlock_kind:
        if (action->action_OrBlock[PRE_ACTION] != NULL) {
          _new = action->action_OrBlock[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (!action->skip_children_OrBlock) {
          Pictures_OrBlock_sub(me) = Traverse_copy_List_Pictures_Picture (Pictures_OrBlock_sub(me), action);
          Pictures_OrBlock_dirs(me) = Traverse_copy_List_Pictures_Direction (Pictures_OrBlock_dirs(me), action);
        }
        if (action->action_OrBlock[POST_ACTION] != NULL) {
          _new = action->action_OrBlock[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_AndBlock_kind:
        if (action->action_AndBlock[PRE_ACTION] != NULL) {
          _new = action->action_AndBlock[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (!action->skip_children_AndBlock) {
          Pictures_AndBlock_sub(me) = Traverse_copy_List_Pictures_Picture (Pictures_AndBlock_sub(me), action);
          Pictures_AndBlock_dirs(me) = Traverse_copy_List_Pictures_Direction (Pictures_AndBlock_dirs(me), action);
        }
        if (action->action_AndBlock[POST_ACTION] != NULL) {
          _new = action->action_AndBlock[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_AltBlock_kind:
        if (action->action_AltBlock[PRE_ACTION] != NULL) {
          _new = action->action_AltBlock[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (!action->skip_children_AltBlock) {
          Pictures_AltBlock_a(me) = Traverse_copy_Pictures_Picture (Pictures_AltBlock_a(me), action);
          Pictures_AltBlock_b(me) = Traverse_copy_Pictures_Picture (Pictures_AltBlock_b(me), action);
        }
        if (action->action_AltBlock[POST_ACTION] != NULL) {
          _new = action->action_AltBlock[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Pictures_Compound_kind:
        if (action->action_Compound[PRE_ACTION] != NULL) {
          _new = action->action_Compound[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Pictures_Picture_d(me) = 0;
            Pictures_Picture_scale(me) = 1;
            Pictures_Picture_phi(me) = 0;
            Pictures_Picture_fill(me) = FALSE;
            Pictures_Picture_dash(me) = 0;
            Pictures_Picture_with_color(me) = FALSE;
          }
        if (!action->skip_children_Compound) {
          Pictures_Compound_sub(me) = Traverse_copy_List_Pictures_Picture (Pictures_Compound_sub(me), action);
        }
        if (action->action_Compound[POST_ACTION] != NULL) {
          _new = action->action_Compound[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_Picture[POST_ACTION] != NULL) {
    me = action->action_Picture[POST_ACTION](me, _old);
  }
  return me;
}

Pictures_Scope Traverse_copy_Pictures_Scope (Pictures_Scope me, copy_Pictures_TraverseTable action)
{ Pictures_Scope _new = me, _old = me;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    _new = action->action_Scope[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Pictures_Scope)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Scope) {
    Pictures_Scope_next(me) = Traverse_copy_Pictures_Scope (Pictures_Scope_next(me), action);
  }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    me = action->action_Scope[POST_ACTION](me, _old);
  }
  return me;
}

List_Pictures_Direction Traverse_copy_List_Pictures_Direction (List_Pictures_Direction me, copy_Pictures_TraverseTable action)
{ List_Pictures_Direction _new = me, _old = me;
  if (action->action_List_Direction[PRE_ACTION] != NULL) {
    _new = action->action_List_Direction[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Pictures_Direction)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Direction) {
    List_Pictures_Direction_data(me) = Traverse_copy_Pictures_Direction (List_Pictures_Direction_data(me), action);
    List_Pictures_Direction_next(me) = Traverse_copy_List_Pictures_Direction (List_Pictures_Direction_next(me), action);
  }
  }
  if (action->action_List_Direction[POST_ACTION] != NULL) {
    me = action->action_List_Direction[POST_ACTION](me, _old);
  }
  return me;
}

List_Pictures_Picture Traverse_copy_List_Pictures_Picture (List_Pictures_Picture me, copy_Pictures_TraverseTable action)
{ List_Pictures_Picture _new = me, _old = me;
  if (action->action_List_Picture[PRE_ACTION] != NULL) {
    _new = action->action_List_Picture[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Pictures_Picture)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Picture) {
    List_Pictures_Picture_data(me) = Traverse_copy_Pictures_Picture (List_Pictures_Picture_data(me), action);
    List_Pictures_Picture_next(me) = Traverse_copy_List_Pictures_Picture (List_Pictures_Picture_next(me), action);
  }
  }
  if (action->action_List_Picture[POST_ACTION] != NULL) {
    me = action->action_List_Picture[POST_ACTION](me, _old);
  }
  return me;
}

Pictures_Direction Traverse_copy_Pictures_Direction (Pictures_Direction me, copy_Pictures_TraverseTable action)
{ Pictures_Direction _new = me, _old = me;
  if (action->action_Direction[PRE_ACTION] != NULL) {
    return action->action_Direction[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_Direction[POST_ACTION] != NULL) {
    me = action->action_Direction[POST_ACTION](me, _old);
  }
  return me;
}

int Traverse_compare_Pictures_Pictures (Pictures_Pictures x, Pictures_Pictures y, compare_Pictures_TraverseTable action)
{ int comp = 0;
  if (action->action_Pictures[PRE_ACTION] != NULL) {
    return action->action_Pictures[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Pictures) {
    if ((comp = Traverse_compare_List_Pictures_Picture (Pictures_Pictures_pics(x),Pictures_Pictures_pics(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Pictures_Picture (Pictures_Picture x, Pictures_Picture y, compare_Pictures_TraverseTable action)
{ int comp = 0;
  if (action->action_Picture[PRE_ACTION] != NULL) {
    return action->action_Picture[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (Pictures_Picture_tag(x) < Pictures_Picture_tag(y)) return -1;
  if (Pictures_Picture_tag(x) > Pictures_Picture_tag(y)) return 1;;
  switch (Pictures_Picture_tag(x)) {
      case Pictures_Empty_kind:
        if (action->action_Empty[PRE_ACTION] != NULL) {
          return action->action_Empty[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (action->action_Empty[POST_ACTION] != NULL) {
          return action->action_Empty[POST_ACTION](x, y);
        }
        break;
      case Pictures_Box_kind:
        if (action->action_Box[PRE_ACTION] != NULL) {
          return action->action_Box[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (action->action_Box[POST_ACTION] != NULL) {
          return action->action_Box[POST_ACTION](x, y);
        }
        break;
      case Pictures_Circle_kind:
        if (action->action_Circle[PRE_ACTION] != NULL) {
          return action->action_Circle[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (action->action_Circle[POST_ACTION] != NULL) {
          return action->action_Circle[POST_ACTION](x, y);
        }
        break;
      case Pictures_Arc_kind:
        if (action->action_Arc[PRE_ACTION] != NULL) {
          return action->action_Arc[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Arc) {
          if ((comp = Traverse_compare_Float (Pictures_Arc_phi_1(x),Pictures_Arc_phi_1(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Arc_phi_2(x),Pictures_Arc_phi_2(y), action)) != 0) return comp;
        }
        if (action->action_Arc[POST_ACTION] != NULL) {
          return action->action_Arc[POST_ACTION](x, y);
        }
        break;
      case Pictures_Curve_kind:
        if (action->action_Curve[PRE_ACTION] != NULL) {
          return action->action_Curve[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Curve) {
          if ((comp = Traverse_compare_Bool (Pictures_Curve_d1(x),Pictures_Curve_d1(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Bool (Pictures_Curve_d2(x),Pictures_Curve_d2(y), action)) != 0) return comp;
        }
        if (action->action_Curve[POST_ACTION] != NULL) {
          return action->action_Curve[POST_ACTION](x, y);
        }
        break;
      case Pictures_Line_kind:
        if (action->action_Line[PRE_ACTION] != NULL) {
          return action->action_Line[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (action->action_Line[POST_ACTION] != NULL) {
          return action->action_Line[POST_ACTION](x, y);
        }
        break;
      case Pictures_Arrow_kind:
        if (action->action_Arrow[PRE_ACTION] != NULL) {
          return action->action_Arrow[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Arrow) {
          if ((comp = Traverse_compare_Pictures_Direction (Pictures_Arrow_dir(x),Pictures_Arrow_dir(y), action)) != 0) return comp;
        }
        if (action->action_Arrow[POST_ACTION] != NULL) {
          return action->action_Arrow[POST_ACTION](x, y);
        }
        break;
      case Pictures_Text_kind:
        if (action->action_Text[PRE_ACTION] != NULL) {
          return action->action_Text[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Text) {
          if ((comp = Traverse_compare_String (Pictures_Text_text(x),Pictures_Text_text(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (Pictures_Text_font(x),Pictures_Text_font(y), action)) != 0) return comp;
        }
        if (action->action_Text[POST_ACTION] != NULL) {
          return action->action_Text[POST_ACTION](x, y);
        }
        break;
      case Pictures_OrBlock_kind:
        if (action->action_OrBlock[PRE_ACTION] != NULL) {
          return action->action_OrBlock[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (!action->skip_children_OrBlock) {
          if ((comp = Traverse_compare_List_Pictures_Picture (Pictures_OrBlock_sub(x),Pictures_OrBlock_sub(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_Pictures_Direction (Pictures_OrBlock_dirs(x),Pictures_OrBlock_dirs(y), action)) != 0) return comp;
        }
        if (action->action_OrBlock[POST_ACTION] != NULL) {
          return action->action_OrBlock[POST_ACTION](x, y);
        }
        break;
      case Pictures_AndBlock_kind:
        if (action->action_AndBlock[PRE_ACTION] != NULL) {
          return action->action_AndBlock[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (!action->skip_children_AndBlock) {
          if ((comp = Traverse_compare_List_Pictures_Picture (Pictures_AndBlock_sub(x),Pictures_AndBlock_sub(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_Pictures_Direction (Pictures_AndBlock_dirs(x),Pictures_AndBlock_dirs(y), action)) != 0) return comp;
        }
        if (action->action_AndBlock[POST_ACTION] != NULL) {
          return action->action_AndBlock[POST_ACTION](x, y);
        }
        break;
      case Pictures_AltBlock_kind:
        if (action->action_AltBlock[PRE_ACTION] != NULL) {
          return action->action_AltBlock[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (!action->skip_children_AltBlock) {
          if ((comp = Traverse_compare_Pictures_Picture (Pictures_AltBlock_a(x),Pictures_AltBlock_a(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Pictures_Picture (Pictures_AltBlock_b(x),Pictures_AltBlock_b(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Bool (Pictures_AltBlock_turn_left(x),Pictures_AltBlock_turn_left(y), action)) != 0) return comp;
        }
        if (action->action_AltBlock[POST_ACTION] != NULL) {
          return action->action_AltBlock[POST_ACTION](x, y);
        }
        break;
      case Pictures_Compound_kind:
        if (action->action_Compound[PRE_ACTION] != NULL) {
          return action->action_Compound[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Picture) {
          if ((comp = Traverse_compare_Float (Pictures_Picture_x(x),Pictures_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_y(x),Pictures_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_w(x),Pictures_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Float (Pictures_Picture_h(x),Pictures_Picture_h(y), action)) != 0) return comp;
        }
        if (!action->skip_children_Compound) {
          if ((comp = Traverse_compare_List_Pictures_Picture (Pictures_Compound_sub(x),Pictures_Compound_sub(y), action)) != 0) return comp;
        }
        if (action->action_Compound[POST_ACTION] != NULL) {
          return action->action_Compound[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_Pictures_Scope (Pictures_Scope x, Pictures_Scope y, compare_Pictures_TraverseTable action)
{ int comp = 0;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    return action->action_Scope[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Scope) {
    if ((comp = Traverse_compare_Pictures_Scope (Pictures_Scope_next(x),Pictures_Scope_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Pictures_Direction (List_Pictures_Direction x, List_Pictures_Direction y, compare_Pictures_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Direction[PRE_ACTION] != NULL) {
    return action->action_List_Direction[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Direction) {
    if ((comp = Traverse_compare_Pictures_Direction (List_Pictures_Direction_data(x),List_Pictures_Direction_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Pictures_Direction (List_Pictures_Direction_next(x),List_Pictures_Direction_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_Pictures_Picture (List_Pictures_Picture x, List_Pictures_Picture y, compare_Pictures_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Picture[PRE_ACTION] != NULL) {
    return action->action_List_Picture[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Picture) {
    if ((comp = Traverse_compare_Pictures_Picture (List_Pictures_Picture_data(x),List_Pictures_Picture_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Pictures_Picture (List_Pictures_Picture_next(x),List_Pictures_Picture_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_Pictures_Direction (Pictures_Direction x, Pictures_Direction y, compare_Pictures_TraverseTable action)
{ if (action->action_Direction[PRE_ACTION] != NULL) {
    return action->action_Direction[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

struct s_Pictures_TraverseTable Pictures_scope_actions = {

  Traverse_Accumulate,
  { NULL,	NULL }, FALSE,	/* Pictures_Pictures */
  { NULL,	NULL }, FALSE,	/* Pictures_Picture */
  { NULL,	NULL }, FALSE,	/* Pictures_Empty */
  { NULL,	NULL }, FALSE,	/* Pictures_Box */
  { NULL,	NULL }, FALSE,	/* Pictures_Circle */
  { NULL,	NULL }, FALSE,	/* Pictures_Arc */
  { NULL,	NULL }, FALSE,	/* Pictures_Curve */
  { NULL,	NULL }, FALSE,	/* Pictures_Line */
  { NULL,	NULL }, FALSE,	/* Pictures_Arrow */
  { NULL,	NULL }, FALSE,	/* Pictures_Text */
  { NULL,	NULL }, FALSE,	/* Pictures_OrBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_AndBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_AltBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_Compound */
  { NULL,	NULL }, FALSE,	/* Pictures_Scope */
  { NULL,	NULL }, FALSE,	/* List_Pictures_Direction */
  { NULL,	NULL }, FALSE,	/* List_Pictures_Picture */
  { NULL,	 NULL }, FALSE,	/* Pictures_Direction */
  { NULL,	 NULL }, FALSE,	/* Pictures_Left */
  { NULL,	 NULL }, FALSE,	/* Pictures_Right */
  { NULL,	 NULL }, FALSE,	/* Pictures_Up */
  { NULL,	 NULL }, FALSE,	/* Pictures_Down */
  { NULL,	 NULL }, FALSE,	/* Pictures_Center */
};

static void Defining_Pictures_Pictures (Pictures_Pictures me)
{
  if (me==NULL) return;
}

static void Defining_Pictures_Picture (Pictures_Picture me)
{
  if (me==NULL) return;
}

struct s_void_Pictures_TraverseTable Pictures_defining_actions = {

  { NULL,	(void*)Defining_Pictures_Pictures }, FALSE,	/* Pictures_Pictures */
  { NULL,	(void*)Defining_Pictures_Picture }, FALSE,	/* Pictures_Picture */
  { NULL,	NULL }, FALSE,	/* Pictures_Empty */
  { NULL,	NULL }, FALSE,	/* Pictures_Box */
  { NULL,	NULL }, FALSE,	/* Pictures_Circle */
  { NULL,	NULL }, FALSE,	/* Pictures_Arc */
  { NULL,	NULL }, FALSE,	/* Pictures_Curve */
  { NULL,	NULL }, FALSE,	/* Pictures_Line */
  { NULL,	NULL }, FALSE,	/* Pictures_Arrow */
  { NULL,	NULL }, FALSE,	/* Pictures_Text */
  { NULL,	NULL }, FALSE,	/* Pictures_OrBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_AndBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_AltBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_Compound */
  { NULL,	NULL }, FALSE,	/* Pictures_Scope */
  { NULL,	NULL }, FALSE,	/* List_Pictures_Direction */
  { NULL,	NULL }, FALSE,	/* List_Pictures_Picture */
  { NULL,	 NULL }, FALSE,	/* Pictures_Direction */
  { NULL,	 NULL }, FALSE,	/* Pictures_Left */
  { NULL,	 NULL }, FALSE,	/* Pictures_Right */
  { NULL,	 NULL }, FALSE,	/* Pictures_Up */
  { NULL,	 NULL }, FALSE,	/* Pictures_Down */
  { NULL,	 NULL }, FALSE,	/* Pictures_Center */
};

struct s_void_Pictures_TraverseTable Pictures_applied_actions = {

  { NULL,	NULL }, FALSE,	/* Pictures_Pictures */
  { NULL,	NULL }, FALSE,	/* Pictures_Picture */
  { NULL,	NULL }, FALSE,	/* Pictures_Empty */
  { NULL,	NULL }, FALSE,	/* Pictures_Box */
  { NULL,	NULL }, FALSE,	/* Pictures_Circle */
  { NULL,	NULL }, FALSE,	/* Pictures_Arc */
  { NULL,	NULL }, FALSE,	/* Pictures_Curve */
  { NULL,	NULL }, FALSE,	/* Pictures_Line */
  { NULL,	NULL }, FALSE,	/* Pictures_Arrow */
  { NULL,	NULL }, FALSE,	/* Pictures_Text */
  { NULL,	NULL }, FALSE,	/* Pictures_OrBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_AndBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_AltBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_Compound */
  { NULL,	NULL }, FALSE,	/* Pictures_Scope */
  { NULL,	NULL }, FALSE,	/* List_Pictures_Direction */
  { NULL,	NULL }, FALSE,	/* List_Pictures_Picture */
  { NULL,	 NULL }, FALSE,	/* Pictures_Direction */
  { NULL,	 NULL }, FALSE,	/* Pictures_Left */
  { NULL,	 NULL }, FALSE,	/* Pictures_Right */
  { NULL,	 NULL }, FALSE,	/* Pictures_Up */
  { NULL,	 NULL }, FALSE,	/* Pictures_Down */
  { NULL,	 NULL }, FALSE,	/* Pictures_Center */
};

struct s_void_Pictures_TraverseTable Pictures_check_actions = {

  { NULL,	NULL }, FALSE,	/* Pictures_Pictures */
  { NULL,	NULL }, FALSE,	/* Pictures_Picture */
  { NULL,	NULL }, FALSE,	/* Pictures_Empty */
  { NULL,	NULL }, FALSE,	/* Pictures_Box */
  { NULL,	NULL }, FALSE,	/* Pictures_Circle */
  { NULL,	NULL }, FALSE,	/* Pictures_Arc */
  { NULL,	NULL }, FALSE,	/* Pictures_Curve */
  { NULL,	NULL }, FALSE,	/* Pictures_Line */
  { NULL,	NULL }, FALSE,	/* Pictures_Arrow */
  { NULL,	NULL }, FALSE,	/* Pictures_Text */
  { NULL,	NULL }, FALSE,	/* Pictures_OrBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_AndBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_AltBlock */
  { NULL,	NULL }, FALSE,	/* Pictures_Compound */
  { NULL,	NULL }, FALSE,	/* Pictures_Scope */
  { NULL,	NULL }, FALSE,	/* List_Pictures_Direction */
  { NULL,	NULL }, FALSE,	/* List_Pictures_Picture */
  { NULL,	 NULL }, FALSE,	/* Pictures_Direction */
  { NULL,	 NULL }, FALSE,	/* Pictures_Left */
  { NULL,	 NULL }, FALSE,	/* Pictures_Right */
  { NULL,	 NULL }, FALSE,	/* Pictures_Up */
  { NULL,	 NULL }, FALSE,	/* Pictures_Down */
  { NULL,	 NULL }, FALSE,	/* Pictures_Center */
};

struct s_void_Pictures_TraverseTable Pictures_print_actions;

struct s_copy_Pictures_TraverseTable Pictures_copy_actions;

struct s_compare_Pictures_TraverseTable Pictures_compare_actions;

void Pictures_fill_table (Pictures_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Pictures[PRE_ACTION] = (void* (*) (Pictures_Pictures, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Pictures[POST_ACTION] = (void* (*) (Pictures_Pictures, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Picture[PRE_ACTION] = (void* (*) (Pictures_Picture, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Picture[POST_ACTION] = (void* (*) (Pictures_Picture, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Empty[PRE_ACTION] = (void* (*) (Pictures_Empty, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Empty[POST_ACTION] = (void* (*) (Pictures_Empty, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Box[PRE_ACTION] = (void* (*) (Pictures_Box, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Box[POST_ACTION] = (void* (*) (Pictures_Box, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Circle[PRE_ACTION] = (void* (*) (Pictures_Circle, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Circle[POST_ACTION] = (void* (*) (Pictures_Circle, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arc[PRE_ACTION] = (void* (*) (Pictures_Arc, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arc[POST_ACTION] = (void* (*) (Pictures_Arc, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Curve[PRE_ACTION] = (void* (*) (Pictures_Curve, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Curve[POST_ACTION] = (void* (*) (Pictures_Curve, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Line[PRE_ACTION] = (void* (*) (Pictures_Line, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Line[POST_ACTION] = (void* (*) (Pictures_Line, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arrow[PRE_ACTION] = (void* (*) (Pictures_Arrow, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arrow[POST_ACTION] = (void* (*) (Pictures_Arrow, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Text[PRE_ACTION] = (void* (*) (Pictures_Text, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Text[POST_ACTION] = (void* (*) (Pictures_Text, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrBlock[PRE_ACTION] = (void* (*) (Pictures_OrBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrBlock[POST_ACTION] = (void* (*) (Pictures_OrBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndBlock[PRE_ACTION] = (void* (*) (Pictures_AndBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndBlock[POST_ACTION] = (void* (*) (Pictures_AndBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltBlock[PRE_ACTION] = (void* (*) (Pictures_AltBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltBlock[POST_ACTION] = (void* (*) (Pictures_AltBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Compound[PRE_ACTION] = (void* (*) (Pictures_Compound, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Compound[POST_ACTION] = (void* (*) (Pictures_Compound, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void* (*) (Pictures_Scope, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void* (*) (Pictures_Scope, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Direction[PRE_ACTION] = (void* (*) (List_Pictures_Direction, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Direction[POST_ACTION] = (void* (*) (List_Pictures_Direction, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Picture[PRE_ACTION] = (void* (*) (List_Pictures_Picture, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Picture[POST_ACTION] = (void* (*) (List_Pictures_Picture, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Direction[PRE_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Direction[POST_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Left[PRE_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Left[POST_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Right[PRE_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Right[POST_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Up[PRE_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Up[POST_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Down[PRE_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Down[POST_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Center[PRE_ACTION] = (void* (*) (Pictures_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Center[POST_ACTION] = (void* (*) (Pictures_Direction, void*))x;
}

void void_Pictures_fill_table (void_Pictures_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Pictures[PRE_ACTION] = (void (*) (Pictures_Pictures))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Pictures[POST_ACTION] = (void (*) (Pictures_Pictures))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Picture[PRE_ACTION] = (void (*) (Pictures_Picture))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Picture[POST_ACTION] = (void (*) (Pictures_Picture))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Empty[PRE_ACTION] = (void (*) (Pictures_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Empty[POST_ACTION] = (void (*) (Pictures_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Box[PRE_ACTION] = (void (*) (Pictures_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Box[POST_ACTION] = (void (*) (Pictures_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Circle[PRE_ACTION] = (void (*) (Pictures_Circle))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Circle[POST_ACTION] = (void (*) (Pictures_Circle))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arc[PRE_ACTION] = (void (*) (Pictures_Arc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arc[POST_ACTION] = (void (*) (Pictures_Arc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Curve[PRE_ACTION] = (void (*) (Pictures_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Curve[POST_ACTION] = (void (*) (Pictures_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Line[PRE_ACTION] = (void (*) (Pictures_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Line[POST_ACTION] = (void (*) (Pictures_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arrow[PRE_ACTION] = (void (*) (Pictures_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arrow[POST_ACTION] = (void (*) (Pictures_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Text[PRE_ACTION] = (void (*) (Pictures_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Text[POST_ACTION] = (void (*) (Pictures_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrBlock[PRE_ACTION] = (void (*) (Pictures_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrBlock[POST_ACTION] = (void (*) (Pictures_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndBlock[PRE_ACTION] = (void (*) (Pictures_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndBlock[POST_ACTION] = (void (*) (Pictures_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltBlock[PRE_ACTION] = (void (*) (Pictures_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltBlock[POST_ACTION] = (void (*) (Pictures_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Compound[PRE_ACTION] = (void (*) (Pictures_Compound))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Compound[POST_ACTION] = (void (*) (Pictures_Compound))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void (*) (Pictures_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void (*) (Pictures_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Direction[PRE_ACTION] = (void (*) (List_Pictures_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Direction[POST_ACTION] = (void (*) (List_Pictures_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Picture[PRE_ACTION] = (void (*) (List_Pictures_Picture))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Picture[POST_ACTION] = (void (*) (List_Pictures_Picture))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Direction[PRE_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Direction[POST_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Left[PRE_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Left[POST_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Right[PRE_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Right[POST_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Up[PRE_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Up[POST_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Down[PRE_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Down[POST_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Center[PRE_ACTION] = (void (*) (Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Center[POST_ACTION] = (void (*) (Pictures_Direction))x;
}

void copy_Pictures_fill_table (copy_Pictures_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Pictures[PRE_ACTION] = (Pictures_Pictures (*) (Pictures_Pictures, Pictures_Pictures))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Pictures[POST_ACTION] = (Pictures_Pictures (*) (Pictures_Pictures, Pictures_Pictures))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Picture[PRE_ACTION] = (Pictures_Picture (*) (Pictures_Picture, Pictures_Picture))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Picture[POST_ACTION] = (Pictures_Picture (*) (Pictures_Picture, Pictures_Picture))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Empty[PRE_ACTION] = (Pictures_Empty (*) (Pictures_Empty, Pictures_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Empty[POST_ACTION] = (Pictures_Empty (*) (Pictures_Empty, Pictures_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Box[PRE_ACTION] = (Pictures_Box (*) (Pictures_Box, Pictures_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Box[POST_ACTION] = (Pictures_Box (*) (Pictures_Box, Pictures_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Circle[PRE_ACTION] = (Pictures_Circle (*) (Pictures_Circle, Pictures_Circle))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Circle[POST_ACTION] = (Pictures_Circle (*) (Pictures_Circle, Pictures_Circle))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arc[PRE_ACTION] = (Pictures_Arc (*) (Pictures_Arc, Pictures_Arc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arc[POST_ACTION] = (Pictures_Arc (*) (Pictures_Arc, Pictures_Arc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Curve[PRE_ACTION] = (Pictures_Curve (*) (Pictures_Curve, Pictures_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Curve[POST_ACTION] = (Pictures_Curve (*) (Pictures_Curve, Pictures_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Line[PRE_ACTION] = (Pictures_Line (*) (Pictures_Line, Pictures_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Line[POST_ACTION] = (Pictures_Line (*) (Pictures_Line, Pictures_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arrow[PRE_ACTION] = (Pictures_Arrow (*) (Pictures_Arrow, Pictures_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arrow[POST_ACTION] = (Pictures_Arrow (*) (Pictures_Arrow, Pictures_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Text[PRE_ACTION] = (Pictures_Text (*) (Pictures_Text, Pictures_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Text[POST_ACTION] = (Pictures_Text (*) (Pictures_Text, Pictures_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrBlock[PRE_ACTION] = (Pictures_OrBlock (*) (Pictures_OrBlock, Pictures_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrBlock[POST_ACTION] = (Pictures_OrBlock (*) (Pictures_OrBlock, Pictures_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndBlock[PRE_ACTION] = (Pictures_AndBlock (*) (Pictures_AndBlock, Pictures_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndBlock[POST_ACTION] = (Pictures_AndBlock (*) (Pictures_AndBlock, Pictures_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltBlock[PRE_ACTION] = (Pictures_AltBlock (*) (Pictures_AltBlock, Pictures_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltBlock[POST_ACTION] = (Pictures_AltBlock (*) (Pictures_AltBlock, Pictures_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Compound[PRE_ACTION] = (Pictures_Compound (*) (Pictures_Compound, Pictures_Compound))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Compound[POST_ACTION] = (Pictures_Compound (*) (Pictures_Compound, Pictures_Compound))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (Pictures_Scope (*) (Pictures_Scope, Pictures_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (Pictures_Scope (*) (Pictures_Scope, Pictures_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Direction[PRE_ACTION] = (List_Pictures_Direction (*) (List_Pictures_Direction, List_Pictures_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Direction[POST_ACTION] = (List_Pictures_Direction (*) (List_Pictures_Direction, List_Pictures_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Picture[PRE_ACTION] = (List_Pictures_Picture (*) (List_Pictures_Picture, List_Pictures_Picture))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Picture[POST_ACTION] = (List_Pictures_Picture (*) (List_Pictures_Picture, List_Pictures_Picture))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Direction[PRE_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Direction[POST_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Left[PRE_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Left[POST_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Right[PRE_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Right[POST_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Up[PRE_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Up[POST_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Down[PRE_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Down[POST_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Center[PRE_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Center[POST_ACTION] = (Pictures_Direction (*) (Pictures_Direction, Pictures_Direction))x;
}

void compare_Pictures_fill_table (compare_Pictures_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Pictures[PRE_ACTION] = (int (*) (Pictures_Pictures, Pictures_Pictures))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Pictures[POST_ACTION] = (int (*) (Pictures_Pictures, Pictures_Pictures))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Picture[PRE_ACTION] = (int (*) (Pictures_Picture, Pictures_Picture))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Picture[POST_ACTION] = (int (*) (Pictures_Picture, Pictures_Picture))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Empty[PRE_ACTION] = (int (*) (Pictures_Empty, Pictures_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Empty[POST_ACTION] = (int (*) (Pictures_Empty, Pictures_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Box[PRE_ACTION] = (int (*) (Pictures_Box, Pictures_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Box[POST_ACTION] = (int (*) (Pictures_Box, Pictures_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Circle[PRE_ACTION] = (int (*) (Pictures_Circle, Pictures_Circle))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Circle[POST_ACTION] = (int (*) (Pictures_Circle, Pictures_Circle))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arc[PRE_ACTION] = (int (*) (Pictures_Arc, Pictures_Arc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arc[POST_ACTION] = (int (*) (Pictures_Arc, Pictures_Arc))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Curve[PRE_ACTION] = (int (*) (Pictures_Curve, Pictures_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Curve[POST_ACTION] = (int (*) (Pictures_Curve, Pictures_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Line[PRE_ACTION] = (int (*) (Pictures_Line, Pictures_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Line[POST_ACTION] = (int (*) (Pictures_Line, Pictures_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arrow[PRE_ACTION] = (int (*) (Pictures_Arrow, Pictures_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arrow[POST_ACTION] = (int (*) (Pictures_Arrow, Pictures_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Text[PRE_ACTION] = (int (*) (Pictures_Text, Pictures_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Text[POST_ACTION] = (int (*) (Pictures_Text, Pictures_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrBlock[PRE_ACTION] = (int (*) (Pictures_OrBlock, Pictures_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrBlock[POST_ACTION] = (int (*) (Pictures_OrBlock, Pictures_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndBlock[PRE_ACTION] = (int (*) (Pictures_AndBlock, Pictures_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndBlock[POST_ACTION] = (int (*) (Pictures_AndBlock, Pictures_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltBlock[PRE_ACTION] = (int (*) (Pictures_AltBlock, Pictures_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltBlock[POST_ACTION] = (int (*) (Pictures_AltBlock, Pictures_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Compound[PRE_ACTION] = (int (*) (Pictures_Compound, Pictures_Compound))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Compound[POST_ACTION] = (int (*) (Pictures_Compound, Pictures_Compound))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (int (*) (Pictures_Scope, Pictures_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (int (*) (Pictures_Scope, Pictures_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Direction[PRE_ACTION] = (int (*) (List_Pictures_Direction, List_Pictures_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Direction[POST_ACTION] = (int (*) (List_Pictures_Direction, List_Pictures_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Picture[PRE_ACTION] = (int (*) (List_Pictures_Picture, List_Pictures_Picture))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Picture[POST_ACTION] = (int (*) (List_Pictures_Picture, List_Pictures_Picture))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Direction[PRE_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Direction[POST_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Left[PRE_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Left[POST_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Right[PRE_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Right[POST_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Up[PRE_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Up[POST_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Down[PRE_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Down[POST_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Center[PRE_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Center[POST_ACTION] = (int (*) (Pictures_Direction, Pictures_Direction))x;
}

Pictures_NameSpaces Pictures_namespaces[] = { -1 };

void Decorate_Pictures (Pictures_Pictures r)
{
  if (Pictures_namespaces[0]<0) Extend_namespaces (Pictures_NUM_NAMESPACES, Pictures_namespaces);
  Pictures_root = r;
  if (NoDecorate) return;
  Traverse_Pictures_Pictures (r, &Pictures_scope_actions, NULL);
  Traverse_void_Pictures_Pictures (r, &Pictures_defining_actions);
  Traverse_void_Pictures_Pictures (r, &Pictures_applied_actions);
  Traverse_void_Pictures_Pictures (r, &Pictures_check_actions);
}
