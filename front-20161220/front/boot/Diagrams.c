#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "error.h"
#include "support.h"
#include "scan_support.h"
#include "Diagrams.h"

Diagrams Diagrams_root;

String Diagrams_Direction_names[] = {
  "Left",
  "Right",
  "Up",
  "Down",
  "Center",
};

String Diagrams_Picture_tag_names[] = {
  "Empty_kind",
  "Box_kind",
  "Curve_kind",
  "Line_kind",
  "Arrow_kind",
  "Text_kind",
  "OrBlock_kind",
  "AndBlock_kind",
  "AltBlock_kind",
  "Compound_kind",
};

Diagrams_Diagrams Create_Diagrams_Diagrams	(SrcInfo src_info, List_Diagrams_Picture pics)
{ Diagrams_Diagrams me = (Diagrams_Diagrams)Front_Alloc(sizeof(*me));
  Diagrams_Diagrams_src_info(me) = src_info;
  Diagrams_Diagrams_pics(me) = pics;
  return me;
}

Diagrams_Compound Create_Diagrams_Compound	(SrcInfo src_info, Int x, Int y, Int w, Int h, List_Diagrams_Picture sub)
{ Diagrams_Compound me = (Diagrams_Compound)Front_Alloc(sizeof(*me));
  Diagrams_Picture_src_info(me) = src_info;
  Diagrams_Picture_x(me) = x;
  Diagrams_Picture_y(me) = y;
  Diagrams_Picture_w(me) = w;
  Diagrams_Picture_h(me) = h;
  Diagrams_Compound_sub(me) = sub;
  Diagrams_Picture_tag(me) = Diagrams_Compound_kind;
  Diagrams_Picture_d(me) = 0;
  return me;
}

Diagrams_AltBlock Create_Diagrams_AltBlock	(SrcInfo src_info, Int x, Int y, Int w, Int h, Diagrams_Picture a, Diagrams_Picture b, Bool turn_left)
{ Diagrams_AltBlock me = (Diagrams_AltBlock)Front_Alloc(sizeof(*me));
  Diagrams_Picture_src_info(me) = src_info;
  Diagrams_Picture_x(me) = x;
  Diagrams_Picture_y(me) = y;
  Diagrams_Picture_w(me) = w;
  Diagrams_Picture_h(me) = h;
  Diagrams_AltBlock_a(me) = a;
  Diagrams_AltBlock_b(me) = b;
  Diagrams_AltBlock_turn_left(me) = turn_left;
  Diagrams_Picture_tag(me) = Diagrams_AltBlock_kind;
  Diagrams_Picture_d(me) = 0;
  return me;
}

Diagrams_AndBlock Create_Diagrams_AndBlock	(SrcInfo src_info, Int x, Int y, Int w, Int h, List_Diagrams_Picture sub, List_Diagrams_Direction dirs)
{ Diagrams_AndBlock me = (Diagrams_AndBlock)Front_Alloc(sizeof(*me));
  Diagrams_Picture_src_info(me) = src_info;
  Diagrams_Picture_x(me) = x;
  Diagrams_Picture_y(me) = y;
  Diagrams_Picture_w(me) = w;
  Diagrams_Picture_h(me) = h;
  Diagrams_AndBlock_sub(me) = sub;
  Diagrams_AndBlock_dirs(me) = dirs;
  Diagrams_Picture_tag(me) = Diagrams_AndBlock_kind;
  Diagrams_Picture_d(me) = 0;
  return me;
}

Diagrams_OrBlock Create_Diagrams_OrBlock	(SrcInfo src_info, Int x, Int y, Int w, Int h, List_Diagrams_Picture sub, List_Diagrams_Direction dirs)
{ Diagrams_OrBlock me = (Diagrams_OrBlock)Front_Alloc(sizeof(*me));
  Diagrams_Picture_src_info(me) = src_info;
  Diagrams_Picture_x(me) = x;
  Diagrams_Picture_y(me) = y;
  Diagrams_Picture_w(me) = w;
  Diagrams_Picture_h(me) = h;
  Diagrams_OrBlock_sub(me) = sub;
  Diagrams_OrBlock_dirs(me) = dirs;
  Diagrams_Picture_tag(me) = Diagrams_OrBlock_kind;
  Diagrams_Picture_d(me) = 0;
  return me;
}

Diagrams_Text Create_Diagrams_Text	(SrcInfo src_info, Int x, Int y, Int w, Int h, String text, Ident font)
{ Diagrams_Text me = (Diagrams_Text)Front_Alloc(sizeof(*me));
  Diagrams_Picture_src_info(me) = src_info;
  Diagrams_Picture_x(me) = x;
  Diagrams_Picture_y(me) = y;
  Diagrams_Picture_w(me) = w;
  Diagrams_Picture_h(me) = h;
  Diagrams_Text_text(me) = text;
  Diagrams_Text_font(me) = font;
  Diagrams_Picture_tag(me) = Diagrams_Text_kind;
  Diagrams_Picture_d(me) = 0;
  return me;
}

Diagrams_Arrow Create_Diagrams_Arrow	(SrcInfo src_info, Int x, Int y, Int w, Int h, Diagrams_Direction dir)
{ Diagrams_Arrow me = (Diagrams_Arrow)Front_Alloc(sizeof(*me));
  Diagrams_Picture_src_info(me) = src_info;
  Diagrams_Picture_x(me) = x;
  Diagrams_Picture_y(me) = y;
  Diagrams_Picture_w(me) = w;
  Diagrams_Picture_h(me) = h;
  Diagrams_Arrow_dir(me) = dir;
  Diagrams_Picture_tag(me) = Diagrams_Arrow_kind;
  Diagrams_Picture_d(me) = 0;
  return me;
}

Diagrams_Line Create_Diagrams_Line	(SrcInfo src_info, Int x, Int y, Int w, Int h)
{ Diagrams_Line me = (Diagrams_Line)Front_Alloc(sizeof(*me));
  Diagrams_Picture_src_info(me) = src_info;
  Diagrams_Picture_x(me) = x;
  Diagrams_Picture_y(me) = y;
  Diagrams_Picture_w(me) = w;
  Diagrams_Picture_h(me) = h;
  Diagrams_Picture_tag(me) = Diagrams_Line_kind;
  Diagrams_Picture_d(me) = 0;
  return me;
}

Diagrams_Curve Create_Diagrams_Curve	(SrcInfo src_info, Int x, Int y, Int w, Int h, Bool d1, Bool d2)
{ Diagrams_Curve me = (Diagrams_Curve)Front_Alloc(sizeof(*me));
  Diagrams_Picture_src_info(me) = src_info;
  Diagrams_Picture_x(me) = x;
  Diagrams_Picture_y(me) = y;
  Diagrams_Picture_w(me) = w;
  Diagrams_Picture_h(me) = h;
  Diagrams_Curve_d1(me) = d1;
  Diagrams_Curve_d2(me) = d2;
  Diagrams_Picture_tag(me) = Diagrams_Curve_kind;
  Diagrams_Picture_d(me) = 0;
  return me;
}

Diagrams_Box Create_Diagrams_Box	(SrcInfo src_info, Int x, Int y, Int w, Int h)
{ Diagrams_Box me = (Diagrams_Box)Front_Alloc(sizeof(*me));
  Diagrams_Picture_src_info(me) = src_info;
  Diagrams_Picture_x(me) = x;
  Diagrams_Picture_y(me) = y;
  Diagrams_Picture_w(me) = w;
  Diagrams_Picture_h(me) = h;
  Diagrams_Picture_tag(me) = Diagrams_Box_kind;
  Diagrams_Picture_d(me) = 0;
  return me;
}

Diagrams_Empty Create_Diagrams_Empty	(SrcInfo src_info, Int x, Int y, Int w, Int h)
{ Diagrams_Empty me = (Diagrams_Empty)Front_Alloc(sizeof(*me));
  Diagrams_Picture_src_info(me) = src_info;
  Diagrams_Picture_x(me) = x;
  Diagrams_Picture_y(me) = y;
  Diagrams_Picture_w(me) = w;
  Diagrams_Picture_h(me) = h;
  Diagrams_Picture_tag(me) = Diagrams_Empty_kind;
  Diagrams_Picture_d(me) = 0;
  return me;
}

Diagrams_Scope Create_Diagrams_Scope	(Diagrams_Scope next)
{ Diagrams_Scope me = (Diagrams_Scope)Front_Alloc(sizeof(*me));
  Diagrams_Scope_next(me) = next;
  return me;
}

Pointer Traverse_Diagrams_Diagrams (Diagrams_Diagrams me, TraverseTable action, Pointer val)
{ if (action->action_Diagrams[PRE_ACTION] != NULL) {
    val = action->action_Diagrams[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Diagrams)
  if (action->traversal != Traverse_Stop || val!=NULL)
  { 
    if (action->traversal != Traverse_Down)  val = Traverse_List_Diagrams_Picture (Diagrams_Diagrams_pics(me), action, val);
    else Traverse_List_Diagrams_Picture (Diagrams_Diagrams_pics(me), action, val);
  }
  if (action->action_Diagrams[POST_ACTION] != NULL) {
    val = action->action_Diagrams[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Diagrams_Picture (Diagrams_Picture me, TraverseTable action, Pointer val)
{ if (action->action_Picture[PRE_ACTION] != NULL) {
    val = action->action_Picture[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Picture)
  if (action->traversal != Traverse_Stop || val!=NULL)
  { switch (Diagrams_Picture_tag(me)) {
      case Diagrams_Empty_kind:
        if (action->action_Empty[PRE_ACTION] != NULL) {
          val = action->action_Empty[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Empty) {
        }
        if (action->action_Empty[POST_ACTION] != NULL) {
          val = action->action_Empty[POST_ACTION](me, val);
        }
        break;
      case Diagrams_Box_kind:
        if (action->action_Box[PRE_ACTION] != NULL) {
          val = action->action_Box[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Box) {
        }
        if (action->action_Box[POST_ACTION] != NULL) {
          val = action->action_Box[POST_ACTION](me, val);
        }
        break;
      case Diagrams_Curve_kind:
        if (action->action_Curve[PRE_ACTION] != NULL) {
          val = action->action_Curve[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Curve) {
        }
        if (action->action_Curve[POST_ACTION] != NULL) {
          val = action->action_Curve[POST_ACTION](me, val);
        }
        break;
      case Diagrams_Line_kind:
        if (action->action_Line[PRE_ACTION] != NULL) {
          val = action->action_Line[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Line) {
        }
        if (action->action_Line[POST_ACTION] != NULL) {
          val = action->action_Line[POST_ACTION](me, val);
        }
        break;
      case Diagrams_Arrow_kind:
        if (action->action_Arrow[PRE_ACTION] != NULL) {
          val = action->action_Arrow[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Arrow) {
          if (action->traversal != Traverse_Down)  val = Traverse_Diagrams_Direction (Diagrams_Arrow_dir(me), action, val);
          else Traverse_Diagrams_Direction (Diagrams_Arrow_dir(me), action, val);
        }
        if (action->action_Arrow[POST_ACTION] != NULL) {
          val = action->action_Arrow[POST_ACTION](me, val);
        }
        break;
      case Diagrams_Text_kind:
        if (action->action_Text[PRE_ACTION] != NULL) {
          val = action->action_Text[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Text) {
        }
        if (action->action_Text[POST_ACTION] != NULL) {
          val = action->action_Text[POST_ACTION](me, val);
        }
        break;
      case Diagrams_OrBlock_kind:
        if (action->action_OrBlock[PRE_ACTION] != NULL) {
          val = action->action_OrBlock[PRE_ACTION](me, val);
        }
        if (!action->skip_children_OrBlock) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_Diagrams_Picture (Diagrams_OrBlock_sub(me), action, val);
          else Traverse_List_Diagrams_Picture (Diagrams_OrBlock_sub(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_Diagrams_Direction (Diagrams_OrBlock_dirs(me), action, val);
          else Traverse_List_Diagrams_Direction (Diagrams_OrBlock_dirs(me), action, val);
        }
        if (action->action_OrBlock[POST_ACTION] != NULL) {
          val = action->action_OrBlock[POST_ACTION](me, val);
        }
        break;
      case Diagrams_AndBlock_kind:
        if (action->action_AndBlock[PRE_ACTION] != NULL) {
          val = action->action_AndBlock[PRE_ACTION](me, val);
        }
        if (!action->skip_children_AndBlock) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_Diagrams_Picture (Diagrams_AndBlock_sub(me), action, val);
          else Traverse_List_Diagrams_Picture (Diagrams_AndBlock_sub(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_List_Diagrams_Direction (Diagrams_AndBlock_dirs(me), action, val);
          else Traverse_List_Diagrams_Direction (Diagrams_AndBlock_dirs(me), action, val);
        }
        if (action->action_AndBlock[POST_ACTION] != NULL) {
          val = action->action_AndBlock[POST_ACTION](me, val);
        }
        break;
      case Diagrams_AltBlock_kind:
        if (action->action_AltBlock[PRE_ACTION] != NULL) {
          val = action->action_AltBlock[PRE_ACTION](me, val);
        }
        if (!action->skip_children_AltBlock) {
          if (action->traversal != Traverse_Down)  val = Traverse_Diagrams_Picture (Diagrams_AltBlock_a(me), action, val);
          else Traverse_Diagrams_Picture (Diagrams_AltBlock_a(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_Diagrams_Picture (Diagrams_AltBlock_b(me), action, val);
          else Traverse_Diagrams_Picture (Diagrams_AltBlock_b(me), action, val);
        }
        if (action->action_AltBlock[POST_ACTION] != NULL) {
          val = action->action_AltBlock[POST_ACTION](me, val);
        }
        break;
      case Diagrams_Compound_kind:
        if (action->action_Compound[PRE_ACTION] != NULL) {
          val = action->action_Compound[PRE_ACTION](me, val);
        }
        if (!action->skip_children_Compound) {
          if (action->traversal != Traverse_Down)  val = Traverse_List_Diagrams_Picture (Diagrams_Compound_sub(me), action, val);
          else Traverse_List_Diagrams_Picture (Diagrams_Compound_sub(me), action, val);
        }
        if (action->action_Compound[POST_ACTION] != NULL) {
          val = action->action_Compound[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Picture[POST_ACTION] != NULL) {
    val = action->action_Picture[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Diagrams_Scope (Diagrams_Scope me, TraverseTable action, Pointer val)
{ if (action->action_Scope[PRE_ACTION] != NULL) {
    val = action->action_Scope[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Scope)
  if (action->traversal != Traverse_Stop || val!=NULL)
  { 
    if (action->traversal != Traverse_Down)  val = Traverse_Diagrams_Scope (Diagrams_Scope_next(me), action, val);
    else Traverse_Diagrams_Scope (Diagrams_Scope_next(me), action, val);
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    val = action->action_Scope[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Diagrams_Direction (List_Diagrams_Direction me, TraverseTable action, Pointer val)
{ if (action->action_List_Direction[PRE_ACTION] != NULL) {
    val = action->action_List_Direction[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Direction)
  if (action->traversal != Traverse_Stop || val!=NULL)
  { 
    if (action->traversal != Traverse_Down)  val = Traverse_Diagrams_Direction (List_Diagrams_Direction_data(me), action, val);
    else Traverse_Diagrams_Direction (List_Diagrams_Direction_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Diagrams_Direction (List_Diagrams_Direction_next(me), action, val);
    else Traverse_List_Diagrams_Direction (List_Diagrams_Direction_next(me), action, val);
  }
  if (action->action_List_Direction[POST_ACTION] != NULL) {
    val = action->action_List_Direction[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_Diagrams_Picture (List_Diagrams_Picture me, TraverseTable action, Pointer val)
{ if (action->action_List_Picture[PRE_ACTION] != NULL) {
    val = action->action_List_Picture[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Picture)
  if (action->traversal != Traverse_Stop || val!=NULL)
  { 
    if (action->traversal != Traverse_Down)  val = Traverse_Diagrams_Picture (List_Diagrams_Picture_data(me), action, val);
    else Traverse_Diagrams_Picture (List_Diagrams_Picture_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_Diagrams_Picture (List_Diagrams_Picture_next(me), action, val);
    else Traverse_List_Diagrams_Picture (List_Diagrams_Picture_next(me), action, val);
  }
  if (action->action_List_Picture[POST_ACTION] != NULL) {
    val = action->action_List_Picture[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_Diagrams_Direction (Diagrams_Direction me, TraverseTable action, Pointer val)
{ if (action->action_Direction[PRE_ACTION] != NULL) {
    val = action->action_Direction[PRE_ACTION](me, val);
  }
  if (action->traversal != Traverse_Stop || val!=NULL)
  { switch (me) {
      case Diagrams_Left:
        if (action->action_Left[PRE_ACTION] != NULL) {
          val = action->action_Left[PRE_ACTION](me, val);
        }
        if (action->action_Left[POST_ACTION] != NULL) {
          val = action->action_Left[POST_ACTION](me, val);
        }
        break;
      case Diagrams_Right:
        if (action->action_Right[PRE_ACTION] != NULL) {
          val = action->action_Right[PRE_ACTION](me, val);
        }
        if (action->action_Right[POST_ACTION] != NULL) {
          val = action->action_Right[POST_ACTION](me, val);
        }
        break;
      case Diagrams_Up:
        if (action->action_Up[PRE_ACTION] != NULL) {
          val = action->action_Up[PRE_ACTION](me, val);
        }
        if (action->action_Up[POST_ACTION] != NULL) {
          val = action->action_Up[POST_ACTION](me, val);
        }
        break;
      case Diagrams_Down:
        if (action->action_Down[PRE_ACTION] != NULL) {
          val = action->action_Down[PRE_ACTION](me, val);
        }
        if (action->action_Down[POST_ACTION] != NULL) {
          val = action->action_Down[POST_ACTION](me, val);
        }
        break;
      case Diagrams_Center:
        if (action->action_Center[PRE_ACTION] != NULL) {
          val = action->action_Center[PRE_ACTION](me, val);
        }
        if (action->action_Center[POST_ACTION] != NULL) {
          val = action->action_Center[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_Direction[POST_ACTION] != NULL) {
    val = action->action_Direction[POST_ACTION](me, val);
  }
  return val;
}

void Traverse_void_Diagrams_Diagrams (Diagrams_Diagrams me, void_Diagrams_TraverseTable action)
{ if (action->action_Diagrams[PRE_ACTION] != NULL) {
    action->action_Diagrams[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Diagrams)
  { 
    Traverse_void_List_Diagrams_Picture (Diagrams_Diagrams_pics(me), action);
  }
  if (action->action_Diagrams[POST_ACTION] != NULL) {
    action->action_Diagrams[POST_ACTION](me);
  }
}

void Traverse_void_Diagrams_Picture (Diagrams_Picture me, void_Diagrams_TraverseTable action)
{ if (action->action_Picture[PRE_ACTION] != NULL) {
    action->action_Picture[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Picture)
  { switch (Diagrams_Picture_tag(me)) {
      case Diagrams_Empty_kind:
        if (action->action_Empty[PRE_ACTION] != NULL) {
          action->action_Empty[PRE_ACTION](me);
        }
        if (!action->skip_children_Empty) {
        }
        if (action->action_Empty[POST_ACTION] != NULL) {
          action->action_Empty[POST_ACTION](me);
        }
        break;
      case Diagrams_Box_kind:
        if (action->action_Box[PRE_ACTION] != NULL) {
          action->action_Box[PRE_ACTION](me);
        }
        if (!action->skip_children_Box) {
        }
        if (action->action_Box[POST_ACTION] != NULL) {
          action->action_Box[POST_ACTION](me);
        }
        break;
      case Diagrams_Curve_kind:
        if (action->action_Curve[PRE_ACTION] != NULL) {
          action->action_Curve[PRE_ACTION](me);
        }
        if (!action->skip_children_Curve) {
        }
        if (action->action_Curve[POST_ACTION] != NULL) {
          action->action_Curve[POST_ACTION](me);
        }
        break;
      case Diagrams_Line_kind:
        if (action->action_Line[PRE_ACTION] != NULL) {
          action->action_Line[PRE_ACTION](me);
        }
        if (!action->skip_children_Line) {
        }
        if (action->action_Line[POST_ACTION] != NULL) {
          action->action_Line[POST_ACTION](me);
        }
        break;
      case Diagrams_Arrow_kind:
        if (action->action_Arrow[PRE_ACTION] != NULL) {
          action->action_Arrow[PRE_ACTION](me);
        }
        if (!action->skip_children_Arrow) {
          Traverse_void_Diagrams_Direction (Diagrams_Arrow_dir(me), action);
        }
        if (action->action_Arrow[POST_ACTION] != NULL) {
          action->action_Arrow[POST_ACTION](me);
        }
        break;
      case Diagrams_Text_kind:
        if (action->action_Text[PRE_ACTION] != NULL) {
          action->action_Text[PRE_ACTION](me);
        }
        if (!action->skip_children_Text) {
        }
        if (action->action_Text[POST_ACTION] != NULL) {
          action->action_Text[POST_ACTION](me);
        }
        break;
      case Diagrams_OrBlock_kind:
        if (action->action_OrBlock[PRE_ACTION] != NULL) {
          action->action_OrBlock[PRE_ACTION](me);
        }
        if (!action->skip_children_OrBlock) {
          Traverse_void_List_Diagrams_Picture (Diagrams_OrBlock_sub(me), action);
          Traverse_void_List_Diagrams_Direction (Diagrams_OrBlock_dirs(me), action);
        }
        if (action->action_OrBlock[POST_ACTION] != NULL) {
          action->action_OrBlock[POST_ACTION](me);
        }
        break;
      case Diagrams_AndBlock_kind:
        if (action->action_AndBlock[PRE_ACTION] != NULL) {
          action->action_AndBlock[PRE_ACTION](me);
        }
        if (!action->skip_children_AndBlock) {
          Traverse_void_List_Diagrams_Picture (Diagrams_AndBlock_sub(me), action);
          Traverse_void_List_Diagrams_Direction (Diagrams_AndBlock_dirs(me), action);
        }
        if (action->action_AndBlock[POST_ACTION] != NULL) {
          action->action_AndBlock[POST_ACTION](me);
        }
        break;
      case Diagrams_AltBlock_kind:
        if (action->action_AltBlock[PRE_ACTION] != NULL) {
          action->action_AltBlock[PRE_ACTION](me);
        }
        if (!action->skip_children_AltBlock) {
          Traverse_void_Diagrams_Picture (Diagrams_AltBlock_a(me), action);
          Traverse_void_Diagrams_Picture (Diagrams_AltBlock_b(me), action);
        }
        if (action->action_AltBlock[POST_ACTION] != NULL) {
          action->action_AltBlock[POST_ACTION](me);
        }
        break;
      case Diagrams_Compound_kind:
        if (action->action_Compound[PRE_ACTION] != NULL) {
          action->action_Compound[PRE_ACTION](me);
        }
        if (!action->skip_children_Compound) {
          Traverse_void_List_Diagrams_Picture (Diagrams_Compound_sub(me), action);
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

void Traverse_void_Diagrams_Scope (Diagrams_Scope me, void_Diagrams_TraverseTable action)
{ if (action->action_Scope[PRE_ACTION] != NULL) {
    action->action_Scope[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Scope)
  { 
    Traverse_void_Diagrams_Scope (Diagrams_Scope_next(me), action);
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    action->action_Scope[POST_ACTION](me);
  }
}

void Traverse_void_List_Diagrams_Direction (List_Diagrams_Direction me, void_Diagrams_TraverseTable action)
{ if (action->action_List_Direction[PRE_ACTION] != NULL) {
    action->action_List_Direction[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Direction)
  { 
    Traverse_void_Diagrams_Direction (List_Diagrams_Direction_data(me), action);
    Traverse_void_List_Diagrams_Direction (List_Diagrams_Direction_next(me), action);
  }
  if (action->action_List_Direction[POST_ACTION] != NULL) {
    action->action_List_Direction[POST_ACTION](me);
  }
}

void Traverse_void_List_Diagrams_Picture (List_Diagrams_Picture me, void_Diagrams_TraverseTable action)
{ if (action->action_List_Picture[PRE_ACTION] != NULL) {
    action->action_List_Picture[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Picture)
  { 
    Traverse_void_Diagrams_Picture (List_Diagrams_Picture_data(me), action);
    Traverse_void_List_Diagrams_Picture (List_Diagrams_Picture_next(me), action);
  }
  if (action->action_List_Picture[POST_ACTION] != NULL) {
    action->action_List_Picture[POST_ACTION](me);
  }
}

void Traverse_void_Diagrams_Direction (Diagrams_Direction me, void_Diagrams_TraverseTable action)
{ if (action->action_Direction[PRE_ACTION] != NULL) {
    action->action_Direction[PRE_ACTION](me);
  }
  { switch (me) {
      case Diagrams_Left:
        if (action->action_Left[PRE_ACTION] != NULL) {
          action->action_Left[PRE_ACTION](me);
        }
        if (action->action_Left[POST_ACTION] != NULL) {
          action->action_Left[POST_ACTION](me);
        }
        break;
      case Diagrams_Right:
        if (action->action_Right[PRE_ACTION] != NULL) {
          action->action_Right[PRE_ACTION](me);
        }
        if (action->action_Right[POST_ACTION] != NULL) {
          action->action_Right[POST_ACTION](me);
        }
        break;
      case Diagrams_Up:
        if (action->action_Up[PRE_ACTION] != NULL) {
          action->action_Up[PRE_ACTION](me);
        }
        if (action->action_Up[POST_ACTION] != NULL) {
          action->action_Up[POST_ACTION](me);
        }
        break;
      case Diagrams_Down:
        if (action->action_Down[PRE_ACTION] != NULL) {
          action->action_Down[PRE_ACTION](me);
        }
        if (action->action_Down[POST_ACTION] != NULL) {
          action->action_Down[POST_ACTION](me);
        }
        break;
      case Diagrams_Center:
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

Diagrams_Diagrams Traverse_copy_Diagrams_Diagrams (Diagrams_Diagrams me, copy_Diagrams_TraverseTable action)
{ Diagrams_Diagrams _new = me, _old = me;
  if (action->action_Diagrams[PRE_ACTION] != NULL) {
    _new = action->action_Diagrams[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Diagrams_Diagrams)Front_Alloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    Diagrams_Diagrams_pics(me) = Traverse_copy_List_Diagrams_Picture (Diagrams_Diagrams_pics(me), action);
  }
  if (action->action_Diagrams[POST_ACTION] != NULL) {
    me = action->action_Diagrams[POST_ACTION](me, _old);
  }
  return me;
}

Diagrams_Picture Traverse_copy_Diagrams_Picture (Diagrams_Picture me, copy_Diagrams_TraverseTable action)
{ Diagrams_Picture _new = me, _old = me;
  if (action->action_Picture[PRE_ACTION] != NULL) {
    _new = action->action_Picture[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Diagrams_Picture)Front_Alloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (Diagrams_Picture_tag(me)) {
      case Diagrams_Empty_kind:
        if (action->action_Empty[PRE_ACTION] != NULL) {
          _new = action->action_Empty[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Diagrams_Picture_d(me) = 0;
          }
        if (action->action_Empty[POST_ACTION] != NULL) {
          _new = action->action_Empty[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Diagrams_Box_kind:
        if (action->action_Box[PRE_ACTION] != NULL) {
          _new = action->action_Box[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Diagrams_Picture_d(me) = 0;
          }
        if (action->action_Box[POST_ACTION] != NULL) {
          _new = action->action_Box[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Diagrams_Curve_kind:
        if (action->action_Curve[PRE_ACTION] != NULL) {
          _new = action->action_Curve[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Diagrams_Picture_d(me) = 0;
          }
        if (action->action_Curve[POST_ACTION] != NULL) {
          _new = action->action_Curve[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Diagrams_Line_kind:
        if (action->action_Line[PRE_ACTION] != NULL) {
          _new = action->action_Line[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Diagrams_Picture_d(me) = 0;
          }
        if (action->action_Line[POST_ACTION] != NULL) {
          _new = action->action_Line[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Diagrams_Arrow_kind:
        if (action->action_Arrow[PRE_ACTION] != NULL) {
          _new = action->action_Arrow[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Diagrams_Picture_d(me) = 0;
          }
          Diagrams_Arrow_dir(me) = Traverse_copy_Diagrams_Direction (Diagrams_Arrow_dir(me), action);
        if (action->action_Arrow[POST_ACTION] != NULL) {
          _new = action->action_Arrow[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Diagrams_Text_kind:
        if (action->action_Text[PRE_ACTION] != NULL) {
          _new = action->action_Text[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Diagrams_Picture_d(me) = 0;
          }
        if (action->action_Text[POST_ACTION] != NULL) {
          _new = action->action_Text[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Diagrams_OrBlock_kind:
        if (action->action_OrBlock[PRE_ACTION] != NULL) {
          _new = action->action_OrBlock[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Diagrams_Picture_d(me) = 0;
          }
          Diagrams_OrBlock_sub(me) = Traverse_copy_List_Diagrams_Picture (Diagrams_OrBlock_sub(me), action);
          Diagrams_OrBlock_dirs(me) = Traverse_copy_List_Diagrams_Direction (Diagrams_OrBlock_dirs(me), action);
        if (action->action_OrBlock[POST_ACTION] != NULL) {
          _new = action->action_OrBlock[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Diagrams_AndBlock_kind:
        if (action->action_AndBlock[PRE_ACTION] != NULL) {
          _new = action->action_AndBlock[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Diagrams_Picture_d(me) = 0;
          }
          Diagrams_AndBlock_sub(me) = Traverse_copy_List_Diagrams_Picture (Diagrams_AndBlock_sub(me), action);
          Diagrams_AndBlock_dirs(me) = Traverse_copy_List_Diagrams_Direction (Diagrams_AndBlock_dirs(me), action);
        if (action->action_AndBlock[POST_ACTION] != NULL) {
          _new = action->action_AndBlock[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Diagrams_AltBlock_kind:
        if (action->action_AltBlock[PRE_ACTION] != NULL) {
          _new = action->action_AltBlock[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Diagrams_Picture_d(me) = 0;
          }
          Diagrams_AltBlock_a(me) = Traverse_copy_Diagrams_Picture (Diagrams_AltBlock_a(me), action);
          Diagrams_AltBlock_b(me) = Traverse_copy_Diagrams_Picture (Diagrams_AltBlock_b(me), action);
        if (action->action_AltBlock[POST_ACTION] != NULL) {
          _new = action->action_AltBlock[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case Diagrams_Compound_kind:
        if (action->action_Compound[PRE_ACTION] != NULL) {
          _new = action->action_Compound[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            Diagrams_Picture_d(me) = 0;
          }
          Diagrams_Compound_sub(me) = Traverse_copy_List_Diagrams_Picture (Diagrams_Compound_sub(me), action);
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

Diagrams_Scope Traverse_copy_Diagrams_Scope (Diagrams_Scope me, copy_Diagrams_TraverseTable action)
{ Diagrams_Scope _new = me, _old = me;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    _new = action->action_Scope[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (Diagrams_Scope)Front_Alloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    Diagrams_Scope_next(me) = Traverse_copy_Diagrams_Scope (Diagrams_Scope_next(me), action);
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    me = action->action_Scope[POST_ACTION](me, _old);
  }
  return me;
}

List_Diagrams_Direction Traverse_copy_List_Diagrams_Direction (List_Diagrams_Direction me, copy_Diagrams_TraverseTable action)
{ List_Diagrams_Direction _new = me, _old = me;
  if (action->action_List_Direction[PRE_ACTION] != NULL) {
    _new = action->action_List_Direction[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Diagrams_Direction)Front_Alloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    List_Diagrams_Direction_data(me) = Traverse_copy_Diagrams_Direction (List_Diagrams_Direction_data(me), action);
    List_Diagrams_Direction_next(me) = Traverse_copy_List_Diagrams_Direction (List_Diagrams_Direction_next(me), action);
  }
  if (action->action_List_Direction[POST_ACTION] != NULL) {
    me = action->action_List_Direction[POST_ACTION](me, _old);
  }
  return me;
}

List_Diagrams_Picture Traverse_copy_List_Diagrams_Picture (List_Diagrams_Picture me, copy_Diagrams_TraverseTable action)
{ List_Diagrams_Picture _new = me, _old = me;
  if (action->action_List_Picture[PRE_ACTION] != NULL) {
    _new = action->action_List_Picture[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_Diagrams_Picture)Front_Alloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
    List_Diagrams_Picture_data(me) = Traverse_copy_Diagrams_Picture (List_Diagrams_Picture_data(me), action);
    List_Diagrams_Picture_next(me) = Traverse_copy_List_Diagrams_Picture (List_Diagrams_Picture_next(me), action);
  }
  if (action->action_List_Picture[POST_ACTION] != NULL) {
    me = action->action_List_Picture[POST_ACTION](me, _old);
  }
  return me;
}

Diagrams_Direction Traverse_copy_Diagrams_Direction (Diagrams_Direction me, copy_Diagrams_TraverseTable action)
{ Diagrams_Direction _new = me, _old = me;
  if (action->action_Direction[PRE_ACTION] != NULL) {
    return action->action_Direction[PRE_ACTION](me, me);
  }
  _new = me;
  if (action->action_Direction[POST_ACTION] != NULL) {
    me = action->action_Direction[POST_ACTION](me, _old);
  }
  return me;
}

int Traverse_compare_Diagrams_Diagrams (Diagrams_Diagrams x, Diagrams_Diagrams y, compare_Diagrams_TraverseTable action)
{ int comp = 0;
  if (action->action_Diagrams[PRE_ACTION] != NULL) {
    return action->action_Diagrams[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

    if ((comp = Traverse_compare_List_Diagrams_Picture (Diagrams_Diagrams_pics(x),Diagrams_Diagrams_pics(y), action)) != 0) return comp;
  return comp;
}

int Traverse_compare_Diagrams_Picture (Diagrams_Picture x, Diagrams_Picture y, compare_Diagrams_TraverseTable action)
{ int comp = 0;
  if (action->action_Picture[PRE_ACTION] != NULL) {
    return action->action_Picture[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (Diagrams_Picture_tag(x) < Diagrams_Picture_tag(y)) return -1;
  if (Diagrams_Picture_tag(x) > Diagrams_Picture_tag(y)) return 1;;
  switch (Diagrams_Picture_tag(x)) {
      case Diagrams_Empty_kind:
        if (action->action_Empty[PRE_ACTION] != NULL) {
          return action->action_Empty[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Empty) {
          if ((comp = Traverse_compare_Int (Diagrams_Picture_x(x),Diagrams_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_y(x),Diagrams_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_w(x),Diagrams_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_h(x),Diagrams_Picture_h(y), action)) != 0) return comp;
        }
        if (action->action_Empty[POST_ACTION] != NULL) {
          return action->action_Empty[POST_ACTION](x, y);
        }
        break;
      case Diagrams_Box_kind:
        if (action->action_Box[PRE_ACTION] != NULL) {
          return action->action_Box[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Box) {
          if ((comp = Traverse_compare_Int (Diagrams_Picture_x(x),Diagrams_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_y(x),Diagrams_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_w(x),Diagrams_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_h(x),Diagrams_Picture_h(y), action)) != 0) return comp;
        }
        if (action->action_Box[POST_ACTION] != NULL) {
          return action->action_Box[POST_ACTION](x, y);
        }
        break;
      case Diagrams_Curve_kind:
        if (action->action_Curve[PRE_ACTION] != NULL) {
          return action->action_Curve[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Curve) {
          if ((comp = Traverse_compare_Int (Diagrams_Picture_x(x),Diagrams_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_y(x),Diagrams_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_w(x),Diagrams_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_h(x),Diagrams_Picture_h(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Bool (Diagrams_Curve_d1(x),Diagrams_Curve_d1(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Bool (Diagrams_Curve_d2(x),Diagrams_Curve_d2(y), action)) != 0) return comp;
        }
        if (action->action_Curve[POST_ACTION] != NULL) {
          return action->action_Curve[POST_ACTION](x, y);
        }
        break;
      case Diagrams_Line_kind:
        if (action->action_Line[PRE_ACTION] != NULL) {
          return action->action_Line[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Line) {
          if ((comp = Traverse_compare_Int (Diagrams_Picture_x(x),Diagrams_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_y(x),Diagrams_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_w(x),Diagrams_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_h(x),Diagrams_Picture_h(y), action)) != 0) return comp;
        }
        if (action->action_Line[POST_ACTION] != NULL) {
          return action->action_Line[POST_ACTION](x, y);
        }
        break;
      case Diagrams_Arrow_kind:
        if (action->action_Arrow[PRE_ACTION] != NULL) {
          return action->action_Arrow[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Arrow) {
          if ((comp = Traverse_compare_Int (Diagrams_Picture_x(x),Diagrams_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_y(x),Diagrams_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_w(x),Diagrams_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_h(x),Diagrams_Picture_h(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Diagrams_Direction (Diagrams_Arrow_dir(x),Diagrams_Arrow_dir(y), action)) != 0) return comp;
        }
        if (action->action_Arrow[POST_ACTION] != NULL) {
          return action->action_Arrow[POST_ACTION](x, y);
        }
        break;
      case Diagrams_Text_kind:
        if (action->action_Text[PRE_ACTION] != NULL) {
          return action->action_Text[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Text) {
          if ((comp = Traverse_compare_Int (Diagrams_Picture_x(x),Diagrams_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_y(x),Diagrams_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_w(x),Diagrams_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_h(x),Diagrams_Picture_h(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_String (Diagrams_Text_text(x),Diagrams_Text_text(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Ident (Diagrams_Text_font(x),Diagrams_Text_font(y), action)) != 0) return comp;
        }
        if (action->action_Text[POST_ACTION] != NULL) {
          return action->action_Text[POST_ACTION](x, y);
        }
        break;
      case Diagrams_OrBlock_kind:
        if (action->action_OrBlock[PRE_ACTION] != NULL) {
          return action->action_OrBlock[PRE_ACTION](x, y);
        }
        if (!action->skip_children_OrBlock) {
          if ((comp = Traverse_compare_Int (Diagrams_Picture_x(x),Diagrams_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_y(x),Diagrams_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_w(x),Diagrams_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_h(x),Diagrams_Picture_h(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_Diagrams_Picture (Diagrams_OrBlock_sub(x),Diagrams_OrBlock_sub(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_Diagrams_Direction (Diagrams_OrBlock_dirs(x),Diagrams_OrBlock_dirs(y), action)) != 0) return comp;
        }
        if (action->action_OrBlock[POST_ACTION] != NULL) {
          return action->action_OrBlock[POST_ACTION](x, y);
        }
        break;
      case Diagrams_AndBlock_kind:
        if (action->action_AndBlock[PRE_ACTION] != NULL) {
          return action->action_AndBlock[PRE_ACTION](x, y);
        }
        if (!action->skip_children_AndBlock) {
          if ((comp = Traverse_compare_Int (Diagrams_Picture_x(x),Diagrams_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_y(x),Diagrams_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_w(x),Diagrams_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_h(x),Diagrams_Picture_h(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_Diagrams_Picture (Diagrams_AndBlock_sub(x),Diagrams_AndBlock_sub(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_Diagrams_Direction (Diagrams_AndBlock_dirs(x),Diagrams_AndBlock_dirs(y), action)) != 0) return comp;
        }
        if (action->action_AndBlock[POST_ACTION] != NULL) {
          return action->action_AndBlock[POST_ACTION](x, y);
        }
        break;
      case Diagrams_AltBlock_kind:
        if (action->action_AltBlock[PRE_ACTION] != NULL) {
          return action->action_AltBlock[PRE_ACTION](x, y);
        }
        if (!action->skip_children_AltBlock) {
          if ((comp = Traverse_compare_Int (Diagrams_Picture_x(x),Diagrams_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_y(x),Diagrams_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_w(x),Diagrams_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_h(x),Diagrams_Picture_h(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Diagrams_Picture (Diagrams_AltBlock_a(x),Diagrams_AltBlock_a(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Diagrams_Picture (Diagrams_AltBlock_b(x),Diagrams_AltBlock_b(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Bool (Diagrams_AltBlock_turn_left(x),Diagrams_AltBlock_turn_left(y), action)) != 0) return comp;
        }
        if (action->action_AltBlock[POST_ACTION] != NULL) {
          return action->action_AltBlock[POST_ACTION](x, y);
        }
        break;
      case Diagrams_Compound_kind:
        if (action->action_Compound[PRE_ACTION] != NULL) {
          return action->action_Compound[PRE_ACTION](x, y);
        }
        if (!action->skip_children_Compound) {
          if ((comp = Traverse_compare_Int (Diagrams_Picture_x(x),Diagrams_Picture_x(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_y(x),Diagrams_Picture_y(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_w(x),Diagrams_Picture_w(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_Int (Diagrams_Picture_h(x),Diagrams_Picture_h(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_List_Diagrams_Picture (Diagrams_Compound_sub(x),Diagrams_Compound_sub(y), action)) != 0) return comp;
        }
        if (action->action_Compound[POST_ACTION] != NULL) {
          return action->action_Compound[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_Diagrams_Scope (Diagrams_Scope x, Diagrams_Scope y, compare_Diagrams_TraverseTable action)
{ int comp = 0;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    return action->action_Scope[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

    if ((comp = Traverse_compare_Diagrams_Scope (Diagrams_Scope_next(x),Diagrams_Scope_next(y), action)) != 0) return comp;
  return comp;
}

int Traverse_compare_List_Diagrams_Direction (List_Diagrams_Direction x, List_Diagrams_Direction y, compare_Diagrams_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Direction[PRE_ACTION] != NULL) {
    return action->action_List_Direction[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

    if ((comp = Traverse_compare_Diagrams_Direction (List_Diagrams_Direction_data(x),List_Diagrams_Direction_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Diagrams_Direction (List_Diagrams_Direction_next(x),List_Diagrams_Direction_next(y), action)) != 0) return comp;
  return comp;
}

int Traverse_compare_List_Diagrams_Picture (List_Diagrams_Picture x, List_Diagrams_Picture y, compare_Diagrams_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Picture[PRE_ACTION] != NULL) {
    return action->action_List_Picture[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

    if ((comp = Traverse_compare_Diagrams_Picture (List_Diagrams_Picture_data(x),List_Diagrams_Picture_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_Diagrams_Picture (List_Diagrams_Picture_next(x),List_Diagrams_Picture_next(y), action)) != 0) return comp;
  return comp;
}

int Traverse_compare_Diagrams_Direction (Diagrams_Direction x, Diagrams_Direction y, compare_Diagrams_TraverseTable action)
{ if (action->action_Direction[PRE_ACTION] != NULL) {
    return action->action_Direction[PRE_ACTION](x, y);
  }
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;}

struct s_Diagrams_TraverseTable Diagrams_scope_actions = {

  Traverse_Accumulate,
  { NULL,	NULL }, FALSE,	/* Diagrams_Diagrams */
  { NULL,	NULL }, FALSE,	/* Diagrams_Picture */
  { NULL,	NULL }, FALSE,	/* Diagrams_Empty */
  { NULL,	NULL }, FALSE,	/* Diagrams_Box */
  { NULL,	NULL }, FALSE,	/* Diagrams_Curve */
  { NULL,	NULL }, FALSE,	/* Diagrams_Line */
  { NULL,	NULL }, FALSE,	/* Diagrams_Arrow */
  { NULL,	NULL }, FALSE,	/* Diagrams_Text */
  { NULL,	NULL }, FALSE,	/* Diagrams_OrBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_AndBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_AltBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_Compound */
  { NULL,	NULL }, FALSE,	/* Diagrams_Scope */
  { NULL,	NULL }, FALSE,	/* List_Diagrams_Direction */
  { NULL,	NULL }, FALSE,	/* List_Diagrams_Picture */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Direction */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Left */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Right */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Up */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Down */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Center */
};

struct s_void_Diagrams_TraverseTable Diagrams_defining_actions = {

  { NULL,	NULL }, FALSE,	/* Diagrams_Diagrams */
  { NULL,	NULL }, FALSE,	/* Diagrams_Picture */
  { NULL,	NULL }, FALSE,	/* Diagrams_Empty */
  { NULL,	NULL }, FALSE,	/* Diagrams_Box */
  { NULL,	NULL }, FALSE,	/* Diagrams_Curve */
  { NULL,	NULL }, FALSE,	/* Diagrams_Line */
  { NULL,	NULL }, FALSE,	/* Diagrams_Arrow */
  { NULL,	NULL }, FALSE,	/* Diagrams_Text */
  { NULL,	NULL }, FALSE,	/* Diagrams_OrBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_AndBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_AltBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_Compound */
  { NULL,	NULL }, FALSE,	/* Diagrams_Scope */
  { NULL,	NULL }, FALSE,	/* List_Diagrams_Direction */
  { NULL,	NULL }, FALSE,	/* List_Diagrams_Picture */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Direction */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Left */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Right */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Up */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Down */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Center */
};

struct s_void_Diagrams_TraverseTable Diagrams_applied_actions = {

  { NULL,	NULL }, FALSE,	/* Diagrams_Diagrams */
  { NULL,	NULL }, FALSE,	/* Diagrams_Picture */
  { NULL,	NULL }, FALSE,	/* Diagrams_Empty */
  { NULL,	NULL }, FALSE,	/* Diagrams_Box */
  { NULL,	NULL }, FALSE,	/* Diagrams_Curve */
  { NULL,	NULL }, FALSE,	/* Diagrams_Line */
  { NULL,	NULL }, FALSE,	/* Diagrams_Arrow */
  { NULL,	NULL }, FALSE,	/* Diagrams_Text */
  { NULL,	NULL }, FALSE,	/* Diagrams_OrBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_AndBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_AltBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_Compound */
  { NULL,	NULL }, FALSE,	/* Diagrams_Scope */
  { NULL,	NULL }, FALSE,	/* List_Diagrams_Direction */
  { NULL,	NULL }, FALSE,	/* List_Diagrams_Picture */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Direction */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Left */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Right */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Up */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Down */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Center */
};

struct s_void_Diagrams_TraverseTable Diagrams_check_actions = {

  { NULL,	NULL }, FALSE,	/* Diagrams_Diagrams */
  { NULL,	NULL }, FALSE,	/* Diagrams_Picture */
  { NULL,	NULL }, FALSE,	/* Diagrams_Empty */
  { NULL,	NULL }, FALSE,	/* Diagrams_Box */
  { NULL,	NULL }, FALSE,	/* Diagrams_Curve */
  { NULL,	NULL }, FALSE,	/* Diagrams_Line */
  { NULL,	NULL }, FALSE,	/* Diagrams_Arrow */
  { NULL,	NULL }, FALSE,	/* Diagrams_Text */
  { NULL,	NULL }, FALSE,	/* Diagrams_OrBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_AndBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_AltBlock */
  { NULL,	NULL }, FALSE,	/* Diagrams_Compound */
  { NULL,	NULL }, FALSE,	/* Diagrams_Scope */
  { NULL,	NULL }, FALSE,	/* List_Diagrams_Direction */
  { NULL,	NULL }, FALSE,	/* List_Diagrams_Picture */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Direction */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Left */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Right */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Up */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Down */
  { NULL,	 NULL }, FALSE,	/* Diagrams_Center */
};

struct s_void_Diagrams_TraverseTable Diagrams_print_actions;

struct s_copy_Diagrams_TraverseTable Diagrams_copy_actions;

struct s_compare_Diagrams_TraverseTable Diagrams_compare_actions;

void Diagrams_fill_table (Diagrams_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Diagrams[PRE_ACTION] = (void* (*) (Diagrams_Diagrams, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Diagrams[POST_ACTION] = (void* (*) (Diagrams_Diagrams, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Picture[PRE_ACTION] = (void* (*) (Diagrams_Picture, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Picture[POST_ACTION] = (void* (*) (Diagrams_Picture, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Empty[PRE_ACTION] = (void* (*) (Diagrams_Empty, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Empty[POST_ACTION] = (void* (*) (Diagrams_Empty, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Box[PRE_ACTION] = (void* (*) (Diagrams_Box, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Box[POST_ACTION] = (void* (*) (Diagrams_Box, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Curve[PRE_ACTION] = (void* (*) (Diagrams_Curve, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Curve[POST_ACTION] = (void* (*) (Diagrams_Curve, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Line[PRE_ACTION] = (void* (*) (Diagrams_Line, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Line[POST_ACTION] = (void* (*) (Diagrams_Line, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arrow[PRE_ACTION] = (void* (*) (Diagrams_Arrow, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arrow[POST_ACTION] = (void* (*) (Diagrams_Arrow, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Text[PRE_ACTION] = (void* (*) (Diagrams_Text, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Text[POST_ACTION] = (void* (*) (Diagrams_Text, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrBlock[PRE_ACTION] = (void* (*) (Diagrams_OrBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrBlock[POST_ACTION] = (void* (*) (Diagrams_OrBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndBlock[PRE_ACTION] = (void* (*) (Diagrams_AndBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndBlock[POST_ACTION] = (void* (*) (Diagrams_AndBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltBlock[PRE_ACTION] = (void* (*) (Diagrams_AltBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltBlock[POST_ACTION] = (void* (*) (Diagrams_AltBlock, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Compound[PRE_ACTION] = (void* (*) (Diagrams_Compound, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Compound[POST_ACTION] = (void* (*) (Diagrams_Compound, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void* (*) (Diagrams_Scope, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void* (*) (Diagrams_Scope, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Direction[PRE_ACTION] = (void* (*) (List_Diagrams_Direction, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Direction[POST_ACTION] = (void* (*) (List_Diagrams_Direction, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Picture[PRE_ACTION] = (void* (*) (List_Diagrams_Picture, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Picture[POST_ACTION] = (void* (*) (List_Diagrams_Picture, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Direction[PRE_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Direction[POST_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Left[PRE_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Left[POST_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Right[PRE_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Right[POST_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Up[PRE_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Up[POST_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Down[PRE_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Down[POST_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Center[PRE_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Center[POST_ACTION] = (void* (*) (Diagrams_Direction, void*))x;
}

void void_Diagrams_fill_table (void_Diagrams_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Diagrams[PRE_ACTION] = (void (*) (Diagrams_Diagrams))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Diagrams[POST_ACTION] = (void (*) (Diagrams_Diagrams))x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Picture[PRE_ACTION] = (void (*) (Diagrams_Picture))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Picture[POST_ACTION] = (void (*) (Diagrams_Picture))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Empty[PRE_ACTION] = (void (*) (Diagrams_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Empty[POST_ACTION] = (void (*) (Diagrams_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Box[PRE_ACTION] = (void (*) (Diagrams_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Box[POST_ACTION] = (void (*) (Diagrams_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Curve[PRE_ACTION] = (void (*) (Diagrams_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Curve[POST_ACTION] = (void (*) (Diagrams_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Line[PRE_ACTION] = (void (*) (Diagrams_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Line[POST_ACTION] = (void (*) (Diagrams_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arrow[PRE_ACTION] = (void (*) (Diagrams_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arrow[POST_ACTION] = (void (*) (Diagrams_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Text[PRE_ACTION] = (void (*) (Diagrams_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Text[POST_ACTION] = (void (*) (Diagrams_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrBlock[PRE_ACTION] = (void (*) (Diagrams_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrBlock[POST_ACTION] = (void (*) (Diagrams_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndBlock[PRE_ACTION] = (void (*) (Diagrams_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndBlock[POST_ACTION] = (void (*) (Diagrams_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltBlock[PRE_ACTION] = (void (*) (Diagrams_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltBlock[POST_ACTION] = (void (*) (Diagrams_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Compound[PRE_ACTION] = (void (*) (Diagrams_Compound))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Compound[POST_ACTION] = (void (*) (Diagrams_Compound))x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void (*) (Diagrams_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void (*) (Diagrams_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Direction[PRE_ACTION] = (void (*) (List_Diagrams_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Direction[POST_ACTION] = (void (*) (List_Diagrams_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Picture[PRE_ACTION] = (void (*) (List_Diagrams_Picture))x;
  x = f (FALSE,FALSE,TRUE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Picture[POST_ACTION] = (void (*) (List_Diagrams_Picture))x;
  x = f (TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Direction[PRE_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Direction[POST_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Left[PRE_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Left[POST_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Right[PRE_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Right[POST_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Up[PRE_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Up[POST_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Down[PRE_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Down[POST_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Center[PRE_ACTION] = (void (*) (Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Center[POST_ACTION] = (void (*) (Diagrams_Direction))x;
}

void copy_Diagrams_fill_table (copy_Diagrams_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Diagrams[PRE_ACTION] = (Diagrams_Diagrams (*) (Diagrams_Diagrams, Diagrams_Diagrams))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Diagrams[POST_ACTION] = (Diagrams_Diagrams (*) (Diagrams_Diagrams, Diagrams_Diagrams))x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Picture[PRE_ACTION] = (Diagrams_Picture (*) (Diagrams_Picture, Diagrams_Picture))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Picture[POST_ACTION] = (Diagrams_Picture (*) (Diagrams_Picture, Diagrams_Picture))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Empty[PRE_ACTION] = (Diagrams_Empty (*) (Diagrams_Empty, Diagrams_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Empty[POST_ACTION] = (Diagrams_Empty (*) (Diagrams_Empty, Diagrams_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Box[PRE_ACTION] = (Diagrams_Box (*) (Diagrams_Box, Diagrams_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Box[POST_ACTION] = (Diagrams_Box (*) (Diagrams_Box, Diagrams_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Curve[PRE_ACTION] = (Diagrams_Curve (*) (Diagrams_Curve, Diagrams_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Curve[POST_ACTION] = (Diagrams_Curve (*) (Diagrams_Curve, Diagrams_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Line[PRE_ACTION] = (Diagrams_Line (*) (Diagrams_Line, Diagrams_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Line[POST_ACTION] = (Diagrams_Line (*) (Diagrams_Line, Diagrams_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arrow[PRE_ACTION] = (Diagrams_Arrow (*) (Diagrams_Arrow, Diagrams_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arrow[POST_ACTION] = (Diagrams_Arrow (*) (Diagrams_Arrow, Diagrams_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Text[PRE_ACTION] = (Diagrams_Text (*) (Diagrams_Text, Diagrams_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Text[POST_ACTION] = (Diagrams_Text (*) (Diagrams_Text, Diagrams_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrBlock[PRE_ACTION] = (Diagrams_OrBlock (*) (Diagrams_OrBlock, Diagrams_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrBlock[POST_ACTION] = (Diagrams_OrBlock (*) (Diagrams_OrBlock, Diagrams_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndBlock[PRE_ACTION] = (Diagrams_AndBlock (*) (Diagrams_AndBlock, Diagrams_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndBlock[POST_ACTION] = (Diagrams_AndBlock (*) (Diagrams_AndBlock, Diagrams_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltBlock[PRE_ACTION] = (Diagrams_AltBlock (*) (Diagrams_AltBlock, Diagrams_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltBlock[POST_ACTION] = (Diagrams_AltBlock (*) (Diagrams_AltBlock, Diagrams_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Compound[PRE_ACTION] = (Diagrams_Compound (*) (Diagrams_Compound, Diagrams_Compound))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Compound[POST_ACTION] = (Diagrams_Compound (*) (Diagrams_Compound, Diagrams_Compound))x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (Diagrams_Scope (*) (Diagrams_Scope, Diagrams_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (Diagrams_Scope (*) (Diagrams_Scope, Diagrams_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Direction[PRE_ACTION] = (List_Diagrams_Direction (*) (List_Diagrams_Direction, List_Diagrams_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Direction[POST_ACTION] = (List_Diagrams_Direction (*) (List_Diagrams_Direction, List_Diagrams_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Picture[PRE_ACTION] = (List_Diagrams_Picture (*) (List_Diagrams_Picture, List_Diagrams_Picture))x;
  x = f (FALSE,FALSE,TRUE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Picture[POST_ACTION] = (List_Diagrams_Picture (*) (List_Diagrams_Picture, List_Diagrams_Picture))x;
  x = f (TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Direction[PRE_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Direction[POST_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Left[PRE_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Left[POST_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Right[PRE_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Right[POST_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Up[PRE_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Up[POST_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Down[PRE_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Down[POST_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Center[PRE_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Center[POST_ACTION] = (Diagrams_Direction (*) (Diagrams_Direction, Diagrams_Direction))x;
}

void compare_Diagrams_fill_table (compare_Diagrams_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Diagrams[PRE_ACTION] = (int (*) (Diagrams_Diagrams, Diagrams_Diagrams))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Diagrams[POST_ACTION] = (int (*) (Diagrams_Diagrams, Diagrams_Diagrams))x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Picture[PRE_ACTION] = (int (*) (Diagrams_Picture, Diagrams_Picture))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Picture[POST_ACTION] = (int (*) (Diagrams_Picture, Diagrams_Picture))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Empty[PRE_ACTION] = (int (*) (Diagrams_Empty, Diagrams_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Empty[POST_ACTION] = (int (*) (Diagrams_Empty, Diagrams_Empty))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Box[PRE_ACTION] = (int (*) (Diagrams_Box, Diagrams_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Box[POST_ACTION] = (int (*) (Diagrams_Box, Diagrams_Box))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Curve[PRE_ACTION] = (int (*) (Diagrams_Curve, Diagrams_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Curve[POST_ACTION] = (int (*) (Diagrams_Curve, Diagrams_Curve))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Line[PRE_ACTION] = (int (*) (Diagrams_Line, Diagrams_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Line[POST_ACTION] = (int (*) (Diagrams_Line, Diagrams_Line))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Arrow[PRE_ACTION] = (int (*) (Diagrams_Arrow, Diagrams_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Arrow[POST_ACTION] = (int (*) (Diagrams_Arrow, Diagrams_Arrow))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Text[PRE_ACTION] = (int (*) (Diagrams_Text, Diagrams_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Text[POST_ACTION] = (int (*) (Diagrams_Text, Diagrams_Text))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OrBlock[PRE_ACTION] = (int (*) (Diagrams_OrBlock, Diagrams_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OrBlock[POST_ACTION] = (int (*) (Diagrams_OrBlock, Diagrams_OrBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AndBlock[PRE_ACTION] = (int (*) (Diagrams_AndBlock, Diagrams_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AndBlock[POST_ACTION] = (int (*) (Diagrams_AndBlock, Diagrams_AndBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AltBlock[PRE_ACTION] = (int (*) (Diagrams_AltBlock, Diagrams_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AltBlock[POST_ACTION] = (int (*) (Diagrams_AltBlock, Diagrams_AltBlock))x;
  x = f (FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Compound[PRE_ACTION] = (int (*) (Diagrams_Compound, Diagrams_Compound))x;
  x = f (FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Compound[POST_ACTION] = (int (*) (Diagrams_Compound, Diagrams_Compound))x;
  x = f (FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (int (*) (Diagrams_Scope, Diagrams_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (int (*) (Diagrams_Scope, Diagrams_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Direction[PRE_ACTION] = (int (*) (List_Diagrams_Direction, List_Diagrams_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Direction[POST_ACTION] = (int (*) (List_Diagrams_Direction, List_Diagrams_Direction))x;
  x = f (FALSE,FALSE,TRUE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Picture[PRE_ACTION] = (int (*) (List_Diagrams_Picture, List_Diagrams_Picture))x;
  x = f (FALSE,FALSE,TRUE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Picture[POST_ACTION] = (int (*) (List_Diagrams_Picture, List_Diagrams_Picture))x;
  x = f (TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Direction[PRE_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Direction[POST_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Left[PRE_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Left[POST_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Right[PRE_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Right[POST_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Up[PRE_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Up[POST_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Down[PRE_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Down[POST_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Center[PRE_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
  x = f (TRUE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Center[POST_ACTION] = (int (*) (Diagrams_Direction, Diagrams_Direction))x;
}

Diagrams_NameSpaces Diagrams_namespaces[] = { 0 };

void Decorate_Diagrams (Diagrams_Diagrams r)
{ Init_symboltable (Diagrams_NUM_NAMESPACES);  Diagrams_root = r;
  if (NoDecorate) return;
  Traverse_Diagrams_Diagrams (r, &Diagrams_scope_actions, NULL);
  Traverse_void_Diagrams_Diagrams (r, &Diagrams_defining_actions);
  Traverse_void_Diagrams_Diagrams (r, &Diagrams_applied_actions);
  Traverse_void_Diagrams_Diagrams (r, &Diagrams_check_actions);
}
