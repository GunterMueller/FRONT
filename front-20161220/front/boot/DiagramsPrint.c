#include "DiagramsPrint.h"
#include "print_support.h"

void Print_Diagrams_Diagrams (Diagrams_Diagrams me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Diagrams_Diagrams_loc(me) >= 0;
    advance_position (Diagrams_Diagrams_loc(me));
    margin = fix_margin ();
    print_comment(Diagrams_Diagrams_src_info(me)->pre_comment);
    { Int margin = fix_margin ();
      List_Diagrams_Picture xxx_pics = Diagrams_Diagrams_pics (me);
      for (; xxx_pics != NULL; xxx_pics = List_Diagrams_Picture_next(xxx_pics)) {
        Diagrams_Picture yyy_pics = List_Diagrams_Picture_data(xxx_pics);
        PRINT_Diagrams_Picture(yyy_pics);
      }
      set_margin (margin);
    }
    print_comment(Diagrams_Diagrams_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

void Print_Diagrams_Picture (Diagrams_Picture me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Diagrams_Picture_loc(me) >= 0;
    advance_position (Diagrams_Picture_loc(me));
    margin = fix_margin ();
    print_comment(Diagrams_Picture_src_info(me)->pre_comment);
    switch (Diagrams_Picture_tag(me)) {
      case Diagrams_Empty_kind:
        PRINT_Int(Diagrams_Picture_x (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_y (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_w (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_h (me));
        Print_Layout (" ");
        Print_Layout ("\n");
        break;
      case Diagrams_Box_kind:
        PRINT_Int(Diagrams_Picture_x (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_y (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_w (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_h (me));
        Print_Layout (" ");
        Print_Layout (" ");
        Print_Keyword ("rectangle");
        Print_Layout ("\n");
        break;
      case Diagrams_Curve_kind:
        PRINT_Int(Diagrams_Picture_x (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_y (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_w (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_h (me));
        Print_Layout (" ");
        Print_Layout (" ");
        Print_Keyword ("arctopop");
        PRINT_Bool(Diagrams_Curve_d1 (me));
        PRINT_Bool(Diagrams_Curve_d2 (me));
        Print_Layout ("\n");
        break;
      case Diagrams_Line_kind:
        PRINT_Int(Diagrams_Picture_x (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_y (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_w (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_h (me));
        Print_Layout (" ");
        Print_Layout (" ");
        Print_Keyword ("line");
        Print_Layout ("\n");
        break;
      case Diagrams_Arrow_kind:
        PRINT_Int(Diagrams_Picture_x (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_y (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_w (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_h (me));
        Print_Layout (" ");
        Print_Layout (" ");
        Print_Keyword ("triangle");
        Print_Layout (" ");
        Print_Keyword ("eofill");
        PRINT_Diagrams_Direction(Diagrams_Arrow_dir (me));
        Print_Layout ("\n");
        break;
      case Diagrams_Text_kind:
        PRINT_Int(Diagrams_Picture_x (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_y (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_w (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_h (me));
        Print_Layout (" ");
        Print_String ("(");
        PRINT_String(Diagrams_Text_text (me));
        Print_String (")");
        PRINT_Ident(Diagrams_Text_font (me));
        Print_Layout ("\n");
        break;
      case Diagrams_OrBlock_kind:
        PRINT_Int(Diagrams_Picture_x (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_y (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_w (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_h (me));
        Print_Layout (" ");
        { Int margin = fix_margin ();
          List_Diagrams_Picture xxx_sub = Diagrams_OrBlock_sub (me);
          List_Diagrams_Direction xxx_dirs = Diagrams_OrBlock_dirs (me);
          Diagrams_Picture yyy_sub = List_Diagrams_Picture_data(xxx_sub);
          Print_String ("OR ");
          PRINT_Diagrams_Picture(yyy_sub);
          xxx_sub = List_Diagrams_Picture_next(xxx_sub);
          for (; xxx_sub != NULL && xxx_dirs != NULL; xxx_sub = List_Diagrams_Picture_next(xxx_sub), xxx_dirs = List_Diagrams_Direction_next(xxx_dirs)) {
            Diagrams_Picture yyy_sub = List_Diagrams_Picture_data(xxx_sub);
            Diagrams_Direction yyy_dirs = List_Diagrams_Direction_data(xxx_dirs);
            PRINT_Diagrams_Direction(yyy_dirs);
            Print_Keyword ("ENDOR");
            Print_Layout ("\n");
            Print_String ("OR ");
            PRINT_Diagrams_Picture(yyy_sub);
          }
          set_margin (margin);
        }
        Print_Layout ("\n");
        break;
      case Diagrams_AndBlock_kind:
        PRINT_Int(Diagrams_Picture_x (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_y (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_w (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_h (me));
        Print_Layout (" ");
        { Int margin = fix_margin ();
          List_Diagrams_Picture xxx_sub = Diagrams_AndBlock_sub (me);
          List_Diagrams_Direction xxx_dirs = Diagrams_AndBlock_dirs (me);
          Diagrams_Picture yyy_sub = List_Diagrams_Picture_data(xxx_sub);
          Print_String ("AND ");
          PRINT_Diagrams_Picture(yyy_sub);
          xxx_sub = List_Diagrams_Picture_next(xxx_sub);
          for (; xxx_sub != NULL && xxx_dirs != NULL; xxx_sub = List_Diagrams_Picture_next(xxx_sub), xxx_dirs = List_Diagrams_Direction_next(xxx_dirs)) {
            Diagrams_Picture yyy_sub = List_Diagrams_Picture_data(xxx_sub);
            Diagrams_Direction yyy_dirs = List_Diagrams_Direction_data(xxx_dirs);
            PRINT_Diagrams_Direction(yyy_dirs);
            Print_Keyword ("ENDAND");
            Print_Layout ("\n");
            Print_String ("AND ");
            PRINT_Diagrams_Picture(yyy_sub);
          }
          set_margin (margin);
        }
        Print_Layout ("\n");
        break;
      case Diagrams_AltBlock_kind:
        PRINT_Int(Diagrams_Picture_x (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_y (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_w (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_h (me));
        Print_Layout (" ");
        Print_String ("ALT ");
        PRINT_Diagrams_Picture(Diagrams_AltBlock_a (me));
        PRINT_Diagrams_Picture(Diagrams_AltBlock_b (me));
        PRINT_Bool(Diagrams_AltBlock_turn_left (me));
        Print_Keyword ("ENDALT");
        Print_Layout ("\n");
        Print_Layout ("\n");
        break;
      case Diagrams_Compound_kind:
        PRINT_Int(Diagrams_Picture_x (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_y (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_w (me));
        Print_Layout (" ");
        PRINT_Int(Diagrams_Picture_h (me));
        Print_Layout (" ");
        { Int margin = fix_margin ();
          List_Diagrams_Picture xxx_sub = Diagrams_Compound_sub (me);
          for (; xxx_sub != NULL; xxx_sub = List_Diagrams_Picture_next(xxx_sub)) {
            Diagrams_Picture yyy_sub = List_Diagrams_Picture_data(xxx_sub);
            PRINT_Diagrams_Picture(yyy_sub);
          }
          set_margin (margin);
        }
        Print_Layout ("\n");
        break;
    }
    print_comment(Diagrams_Picture_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

void Print_Diagrams_Scope (Diagrams_Scope me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    Source_node = source_node;    set_margin (margin);
  }
}

void Print_List_Diagrams_Direction (List_Diagrams_Direction me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Diagrams_Direction (List_Diagrams_Direction_data(me));
    PRINT_List_Diagrams_Direction (List_Diagrams_Direction_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

void Print_List_Diagrams_Picture (List_Diagrams_Picture me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Diagrams_Picture (List_Diagrams_Picture_data(me));
    PRINT_List_Diagrams_Picture (List_Diagrams_Picture_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

void Print_Diagrams_Direction (Diagrams_Direction me)
{ switch (me) {
    case Diagrams_Left:
      Print_Keyword ("L");
      break;
    case Diagrams_Right:
      Print_Keyword ("R");
      break;
    case Diagrams_Up:
      Print_Keyword ("U");
      break;
    case Diagrams_Down:
      Print_Keyword ("D");
      break;
    case Diagrams_Center:
      Print_Keyword ("C");
      break;
  }
}

