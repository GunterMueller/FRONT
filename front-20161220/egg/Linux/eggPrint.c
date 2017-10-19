#include "eggPrint.h"
#include <front/text.h>

#include <front/print_support.h>

void Print_egg_egg (egg_egg me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = egg_egg_loc(me) >= 0;
    advance_position (egg_egg_loc(me));
    margin = fix_margin ();
    print_comment(egg_egg_src_info(me)->pre_comment);
    PRINT_egg_Uses(egg_egg_uses (me));
    { Int margin = fix_margin ();
      List_egg_Statement xxx_groups = egg_egg_groups (me);
      for (; xxx_groups != NULL; xxx_groups = xxx_groups ? List_egg_Statement_next(xxx_groups) : NULL) {
        egg_Statement yyy_groups = List_egg_Statement_data(xxx_groups);
        PRINT_egg_Statement(yyy_groups);
      }
      set_margin (margin);
    }
    print_comment(egg_egg_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_egg_egg (egg_egg me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_egg_egg(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_egg_Uses (egg_Uses me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = egg_Uses_loc(me) >= 0;
    advance_position (egg_Uses_loc(me));
    margin = fix_margin ();
    print_comment(egg_Uses_src_info(me)->pre_comment);
    Print_Keyword ("uses");
    { Int margin = fix_margin ();
      Bool __first = TRUE;
      List_String xxx_uses = egg_Uses_uses (me);
      for (; xxx_uses != NULL; xxx_uses = xxx_uses ? List_String_next(xxx_uses) : NULL) {
        String yyy_uses = List_String_data(xxx_uses);
        if (!__first) {
          Print_String (",");
;
        }
        __first = FALSE;
        PRINT_String(yyy_uses);
      }
      set_margin (margin);
    }
    Print_String (";");
    Print_Layout ("\n");
    print_comment(egg_Uses_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_egg_Uses (egg_Uses me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_egg_Uses(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_egg_Declaration (egg_Declaration me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = egg_Declaration_loc(me) >= 0;
    advance_position (egg_Declaration_loc(me));
    margin = fix_margin ();
    print_comment(egg_Declaration_src_info(me)->pre_comment);
    PRINT_egg_MessageKind(egg_Declaration_kind (me));
    Print_Layout (" ");
    Print_String ("=");
    Print_Layout (" ");
    { Int margin = fix_margin ();
      List_egg_Expression xxx_exprs = egg_Declaration_exprs (me);
      for (; xxx_exprs != NULL; xxx_exprs = xxx_exprs ? List_egg_Expression_next(xxx_exprs) : NULL) {
        egg_Expression yyy_exprs = List_egg_Expression_data(xxx_exprs);
        PRINT_egg_Expression(yyy_exprs);
      }
      set_margin (margin);
    }
    Print_String (";");
    Print_Layout ("\n");
    print_comment(egg_Declaration_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_egg_Declaration (egg_Declaration me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_egg_Declaration(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_egg_Expression (egg_Expression me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = egg_Expression_loc(me) >= 0;
    advance_position (egg_Expression_loc(me));
    margin = fix_margin ();
    print_comment(egg_Expression_src_info(me)->pre_comment);
    switch (egg_Expression_tag(me)) {
      case egg_StringExpr_kind:
        PRINT_String(egg_StringExpr_s (me));
        break;
      case egg_CallExpr_kind:
        PRINT_Ident(egg_CallExpr_id (me));
        Print_String ("(");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_egg_Expression xxx_params = egg_CallExpr_params (me);
          for (; xxx_params != NULL; xxx_params = xxx_params ? List_egg_Expression_next(xxx_params) : NULL) {
            egg_Expression yyy_params = List_egg_Expression_data(xxx_params);
            if (!__first) {
              Print_String (",");
;
            }
            __first = FALSE;
            PRINT_egg_Expression(yyy_params);
          }
          set_margin (margin);
        }
        Print_String (")");
        break;
      case egg_IdExpr_kind:
        PRINT_Ident(egg_IdExpr_id (me));
        break;
    }
    print_comment(egg_Expression_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_egg_Expression (egg_Expression me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_egg_Expression(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_egg_Statement (egg_Statement me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = egg_Statement_loc(me) >= 0;
    advance_position (egg_Statement_loc(me));
    margin = fix_margin ();
    print_comment(egg_Statement_src_info(me)->pre_comment);
    switch (egg_Statement_tag(me)) {
      case egg_Message_kind:
        if (egg_Statement_fatal (me)) {
          Print_Keyword ("fatal");
          Print_Layout (" ");
        }
        PRINT_Ident(egg_Statement_id (me));
        Print_Layout (" ");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_egg_SubMessage xxx_msgs = egg_Message_msgs (me);
          for (; xxx_msgs != NULL; xxx_msgs = xxx_msgs ? List_egg_SubMessage_next(xxx_msgs) : NULL) {
            egg_SubMessage yyy_msgs = List_egg_SubMessage_data(xxx_msgs);
            if (!__first) {
              Print_String (",");
;
            }
            __first = FALSE;
            PRINT_egg_SubMessage(yyy_msgs);
          }
          set_margin (margin);
        }
        Print_String (";");
        Print_Layout ("\n");
        break;
      case egg_Group_kind:
        Print_Layout ("\n");
        if (egg_Statement_fatal (me)) {
          Print_Keyword ("fatal");
          Print_Layout (" ");
        }
        PRINT_Ident(egg_Statement_id (me));
        Print_Layout (" ");
        if (egg_Group_type (me) != NULL) {
          Ident yyy_type = egg_Group_type (me);
          Print_String ("(");
          PRINT_Ident(yyy_type);
          Print_String (")");
          Print_Layout (" ");
        }
        if (egg_Group_group (me)) {
          Print_Keyword ("group");
          Print_Layout (" ");
        }
        Print_String ("{");
        Print_Layout ("\n");
        Print_Layout (" ");
        Print_Layout (" ");
        { Int margin = fix_margin ();
          List_egg_Declaration xxx_decls = egg_Group_decls (me);
          for (; xxx_decls != NULL; xxx_decls = xxx_decls ? List_egg_Declaration_next(xxx_decls) : NULL) {
            egg_Declaration yyy_decls = List_egg_Declaration_data(xxx_decls);
            PRINT_egg_Declaration(yyy_decls);
          }
          set_margin (margin);
        }
        { Int margin = fix_margin ();
          List_egg_Statement xxx_stats = egg_Group_stats (me);
          for (; xxx_stats != NULL; xxx_stats = xxx_stats ? List_egg_Statement_next(xxx_stats) : NULL) {
            egg_Statement yyy_stats = List_egg_Statement_data(xxx_stats);
            PRINT_egg_Statement(yyy_stats);
          }
          set_margin (margin);
        }
        Print_String ("}");
        Print_Layout ("\n");
        break;
    }
    print_comment(egg_Statement_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_egg_Statement (egg_Statement me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_egg_Statement(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_egg_SubMessage (egg_SubMessage me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = egg_SubMessage_loc(me) >= 0;
    advance_position (egg_SubMessage_loc(me));
    margin = fix_margin ();
    print_comment(egg_SubMessage_src_info(me)->pre_comment);
    PRINT_egg_MessageKind(egg_SubMessage_kind (me));
    Print_Layout (" ");
    PRINT_String(egg_SubMessage_msg (me));
    print_comment(egg_SubMessage_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_egg_SubMessage (egg_SubMessage me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_egg_SubMessage(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_egg_Scope (egg_Scope me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    switch (egg_Scope_tag(me)) {
      case egg_GroupScope_kind:
        break;
    }
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_egg_Scope (egg_Scope me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_egg_Scope(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_egg_Declaration (List_egg_Declaration me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_egg_Declaration (List_egg_Declaration_data(me));
    PRINT_List_egg_Declaration (List_egg_Declaration_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_egg_Declaration (List_egg_Declaration me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_egg_Declaration(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_egg_SubMessage (List_egg_SubMessage me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_egg_SubMessage (List_egg_SubMessage_data(me));
    PRINT_List_egg_SubMessage (List_egg_SubMessage_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_egg_SubMessage (List_egg_SubMessage me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_egg_SubMessage(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_egg_Expression (List_egg_Expression me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_egg_Expression (List_egg_Expression_data(me));
    PRINT_List_egg_Expression (List_egg_Expression_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_egg_Expression (List_egg_Expression me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_egg_Expression(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_egg_Statement (List_egg_Statement me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_egg_Statement (List_egg_Statement_data(me));
    PRINT_List_egg_Statement (List_egg_Statement_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_egg_Statement (List_egg_Statement me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_egg_Statement(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_egg_MessageKind (egg_MessageKind me)
{ switch (me) {
    case egg_ErrorMsg:
      Print_Keyword ("error");
      break;
    case egg_WarningMsg:
      Print_Keyword ("warning");
      break;
    case egg_DisabledMsg:
      Print_Keyword ("disabled");
      break;
    case egg_KeyMsg:
      Print_Keyword ("key");
      break;
    case egg_PostMsg:
      Print_Keyword ("post");
      break;
  }
}

char *Text_egg_MessageKind (egg_MessageKind me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_egg_MessageKind(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

