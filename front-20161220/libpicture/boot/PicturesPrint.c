#include "PicturesPrint.h"
#include <front/text.h>

#include <front/print_support.h>

void Print_Pictures_Pictures (Pictures_Pictures me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Pictures_Pictures_loc(me) >= 0;
    advance_position (Pictures_Pictures_loc(me));
    margin = fix_margin ();
    print_comment(Pictures_Pictures_src_info(me)->pre_comment);
    { Int margin = fix_margin ();
      List_Pictures_Picture xxx_pics = Pictures_Pictures_pics (me);
      for (; xxx_pics != NULL; xxx_pics = xxx_pics ? List_Pictures_Picture_next(xxx_pics) : NULL) {
        Pictures_Picture yyy_pics = List_Pictures_Picture_data(xxx_pics);
        PRINT_Pictures_Picture(yyy_pics);
      }
      set_margin (margin);
    }
    print_comment(Pictures_Pictures_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Pictures_Pictures (Pictures_Pictures me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Pictures_Pictures(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Pictures_Picture (Pictures_Picture me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Pictures_Picture_loc(me) >= 0;
    advance_position (Pictures_Picture_loc(me));
    margin = fix_margin ();
    print_comment(Pictures_Picture_src_info(me)->pre_comment);
    switch (Pictures_Picture_tag(me)) {
      case Pictures_Empty_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        Print_Layout ("\n");
        break;
      case Pictures_Box_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        Print_Layout (" ");
        Print_Keyword ("rectangle");
        Print_Layout ("\n");
        break;
      case Pictures_Circle_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        Print_Layout (" ");
        Print_Keyword ("circle");
        Print_Layout ("\n");
        break;
      case Pictures_Arc_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        Print_Layout (" ");
        Print_Keyword ("arc");
        PRINT_Float(Pictures_Arc_phi_1 (me));
        PRINT_Float(Pictures_Arc_phi_2 (me));
        Print_Layout ("\n");
        break;
      case Pictures_Curve_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        Print_Layout (" ");
        Print_Keyword ("arctopop");
        PRINT_Bool(Pictures_Curve_d1 (me));
        PRINT_Bool(Pictures_Curve_d2 (me));
        Print_Layout ("\n");
        break;
      case Pictures_Line_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        Print_Layout (" ");
        Print_Keyword ("line");
        Print_Layout ("\n");
        break;
      case Pictures_Arrow_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        Print_Layout (" ");
        Print_Keyword ("triangle");
        Print_Layout (" ");
        Print_Keyword ("eofill");
        PRINT_Pictures_Direction(Pictures_Arrow_dir (me));
        Print_Layout ("\n");
        break;
      case Pictures_Text_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        Print_String ("(");
        PRINT_String(Pictures_Text_text (me));
        Print_String (")");
        PRINT_Ident(Pictures_Text_font (me));
        Print_Layout ("\n");
        break;
      case Pictures_OrBlock_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_Pictures_Picture xxx_sub = Pictures_OrBlock_sub (me);
          List_Pictures_Direction xxx_dirs = Pictures_OrBlock_dirs (me);
          for (; xxx_sub != NULL; xxx_sub = xxx_sub ? List_Pictures_Picture_next(xxx_sub) : NULL) {
            Pictures_Picture yyy_sub = List_Pictures_Picture_data(xxx_sub);
            if (!__first) {
              Pictures_Direction yyy_dirs = List_Pictures_Direction_data(xxx_dirs);
              PRINT_Pictures_Direction(yyy_dirs);
              Print_Keyword ("ENDOR");
              Print_Layout ("\n");
              xxx_dirs = xxx_dirs ? List_Pictures_Direction_next(xxx_dirs) : NULL;
            }
            __first = FALSE;
            Print_String ("OR ");
            PRINT_Pictures_Picture(yyy_sub);
          }
          set_margin (margin);
        }
        Print_Layout ("\n");
        break;
      case Pictures_AndBlock_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_Pictures_Picture xxx_sub = Pictures_AndBlock_sub (me);
          List_Pictures_Direction xxx_dirs = Pictures_AndBlock_dirs (me);
          for (; xxx_sub != NULL; xxx_sub = xxx_sub ? List_Pictures_Picture_next(xxx_sub) : NULL) {
            Pictures_Picture yyy_sub = List_Pictures_Picture_data(xxx_sub);
            if (!__first) {
              Pictures_Direction yyy_dirs = List_Pictures_Direction_data(xxx_dirs);
              PRINT_Pictures_Direction(yyy_dirs);
              Print_Keyword ("ENDAND");
              Print_Layout ("\n");
              xxx_dirs = xxx_dirs ? List_Pictures_Direction_next(xxx_dirs) : NULL;
            }
            __first = FALSE;
            Print_String ("AND ");
            PRINT_Pictures_Picture(yyy_sub);
          }
          set_margin (margin);
        }
        Print_Layout ("\n");
        break;
      case Pictures_AltBlock_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        Print_String ("ALT ");
        PRINT_Pictures_Picture(Pictures_AltBlock_a (me));
        PRINT_Pictures_Picture(Pictures_AltBlock_b (me));
        PRINT_Bool(Pictures_AltBlock_turn_left (me));
        Print_Keyword ("ENDALT");
        Print_Layout ("\n");
        Print_Layout ("\n");
        break;
      case Pictures_Compound_kind:
        PRINT_Float(Pictures_Picture_x (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_y (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_w (me));
        Print_Layout (" ");
        PRINT_Float(Pictures_Picture_h (me));
        Print_Layout (" ");
        { Int margin = fix_margin ();
          List_Pictures_Picture xxx_sub = Pictures_Compound_sub (me);
          for (; xxx_sub != NULL; xxx_sub = xxx_sub ? List_Pictures_Picture_next(xxx_sub) : NULL) {
            Pictures_Picture yyy_sub = List_Pictures_Picture_data(xxx_sub);
            PRINT_Pictures_Picture(yyy_sub);
          }
          set_margin (margin);
        }
        Print_Layout ("\n");
        break;
    }
    print_comment(Pictures_Picture_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Pictures_Picture (Pictures_Picture me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Pictures_Picture(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Pictures_Scope (Pictures_Scope me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Pictures_Scope (Pictures_Scope me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Pictures_Scope(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Pictures_Direction (List_Pictures_Direction me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Pictures_Direction (List_Pictures_Direction_data(me));
    PRINT_List_Pictures_Direction (List_Pictures_Direction_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Pictures_Direction (List_Pictures_Direction me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Pictures_Direction(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Pictures_Picture (List_Pictures_Picture me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Pictures_Picture (List_Pictures_Picture_data(me));
    PRINT_List_Pictures_Picture (List_Pictures_Picture_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Pictures_Picture (List_Pictures_Picture me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Pictures_Picture(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Pictures_Direction (Pictures_Direction me)
{ switch (me) {
    case Pictures_Left:
      Print_Keyword ("L");
      break;
    case Pictures_Right:
      Print_Keyword ("R");
      break;
    case Pictures_Up:
      Print_Keyword ("U");
      break;
    case Pictures_Down:
      Print_Keyword ("D");
      break;
    case Pictures_Center:
      Print_Keyword ("C");
      break;
  }
}

char *Text_Pictures_Direction (Pictures_Direction me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Pictures_Direction(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

