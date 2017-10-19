#include "LalrPrint.h"
#include <front/text.h>

#include <front/print_support.h>

void Print_Lalr_Lalr (Lalr_Lalr me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Lalr_Lalr_loc(me) >= 0;
    advance_position (Lalr_Lalr_loc(me));
    margin = fix_margin ();
    print_comment(Lalr_Lalr_src_info(me)->pre_comment);
    Print_Keyword ("GRAMMAR");
    Print_Layout ("\n");
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_Lalr_Production xxx_grammar = Lalr_Lalr_grammar (me);
      for (; xxx_grammar != NULL; xxx_grammar = xxx_grammar ? List_Lalr_Production_next(xxx_grammar) : NULL) {
        Lalr_Production yyy_grammar = List_Lalr_Production_data(xxx_grammar);
        PRINT_Lalr_Production(yyy_grammar);
      }
      set_margin (margin);
    }
    Print_Layout ("\n");
    Print_Keyword ("STATES");
    Print_Layout ("\n");
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_Lalr_LR_state xxx_states = Lalr_Lalr_states (me);
      for (; xxx_states != NULL; xxx_states = xxx_states ? List_Lalr_LR_state_next(xxx_states) : NULL) {
        Lalr_LR_state yyy_states = List_Lalr_LR_state_data(xxx_states);
        PRINT_Lalr_LR_state(yyy_states);
      }
      set_margin (margin);
    }
    print_comment(Lalr_Lalr_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Lalr_Lalr (Lalr_Lalr me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Lalr_Lalr(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Lalr_Production (Lalr_Production me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Lalr_Production_loc(me) >= 0;
    advance_position (Lalr_Production_loc(me));
    margin = fix_margin ();
    print_comment(Lalr_Production_src_info(me)->pre_comment);
    start_label (me);
    PRINT_Ident(Lalr_Production_lhs (me));
    end_label ();
    Print_Layout (" ");
    Print_String ("->");
    if (Lalr_Production_rhs (me) != NULL) {
      Lalr_LR_Symbols yyy_rhs = Lalr_Production_rhs (me);
      PRINT_Lalr_LR_Symbols(yyy_rhs);
    }
    Print_Layout (" ");
    Print_String (";");
    Print_Layout ("\n");
    Print_Layout (" ");
    Print_Layout (" ");
    Print_String ("empty:");
    Print_Layout (" ");
    PRINT_Lalr_Emptiness(Lalr_Production_empty (me));
    Print_Layout ("\n");
    Print_Layout (" ");
    Print_Layout (" ");
    Print_String ("first:");
    Print_Layout (" ");
    { Int margin = fix_margin ();
      List_Ident xxx_first = Lalr_Production_first (me);
      for (; xxx_first != NULL; xxx_first = xxx_first ? List_Ident_next(xxx_first) : NULL) {
        Ident yyy_first = List_Ident_data(xxx_first);
        PRINT_Ident(yyy_first);
        Print_String (" ");
      }
      set_margin (margin);
    }
    Print_Layout ("\n");
    print_comment(Lalr_Production_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Lalr_Production (Lalr_Production me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Lalr_Production(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Lalr_LR_Symbol (Lalr_LR_Symbol me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Lalr_LR_Symbol_loc(me) >= 0;
    advance_position (Lalr_LR_Symbol_loc(me));
    margin = fix_margin ();
    print_comment(Lalr_LR_Symbol_src_info(me)->pre_comment);
    PRINT_Ident(Lalr_LR_Symbol_id (me));
    if (Lalr_LR_Symbol_make_empty (me)) {
      Print_String ("?");
    }
    print_comment(Lalr_LR_Symbol_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Lalr_LR_Symbol (Lalr_LR_Symbol me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Lalr_LR_Symbol(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Lalr_LR_Symbols (Lalr_LR_Symbols me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Lalr_LR_Symbols_loc(me) >= 0;
    advance_position (Lalr_LR_Symbols_loc(me));
    margin = fix_margin ();
    print_comment(Lalr_LR_Symbols_src_info(me)->pre_comment);
    Print_Layout (" ");
    PRINT_Lalr_LR_Symbol(Lalr_LR_Symbols_data (me));
    PRINT_Lalr_LR_Symbols(Lalr_LR_Symbols_next (me));
    print_comment(Lalr_LR_Symbols_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Lalr_LR_Symbols (Lalr_LR_Symbols me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Lalr_LR_Symbols(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Lalr_LR_state (Lalr_LR_state me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Lalr_LR_state_loc(me) >= 0;
    advance_position (Lalr_LR_state_loc(me));
    margin = fix_margin ();
    print_comment(Lalr_LR_state_src_info(me)->pre_comment);
    Print_Keyword ("state");
    Print_Layout (" ");
    PRINT_Int(Lalr_LR_state_num (me));
    Print_Layout ("\n");
    Print_Layout (" ");
    Print_Layout (" ");
    { Int margin = fix_margin ();
      List_Lalr_Item xxx_items = Lalr_LR_state_items (me);
      for (; xxx_items != NULL; xxx_items = xxx_items ? List_Lalr_Item_next(xxx_items) : NULL) {
        Lalr_Item yyy_items = List_Lalr_Item_data(xxx_items);
        PRINT_Lalr_Item(yyy_items);
        Print_Layout ("\n");
      }
      set_margin (margin);
    }
    Print_Keyword ("transitions");
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_Lalr_Transition xxx_transitions = Lalr_LR_state_transitions (me);
      for (; xxx_transitions != NULL; xxx_transitions = xxx_transitions ? List_Lalr_Transition_next(xxx_transitions) : NULL) {
        Lalr_Transition yyy_transitions = List_Lalr_Transition_data(xxx_transitions);
        Print_Layout (" ");
        Print_Layout (" ");
        PRINT_Lalr_Transition(yyy_transitions);
        Print_Layout ("\n");
      }
      set_margin (margin);
    }
    Print_Layout ("\n");
    Print_Layout ("\n");
    print_comment(Lalr_LR_state_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Lalr_LR_state (Lalr_LR_state me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Lalr_LR_state(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Lalr_Item (Lalr_Item me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Lalr_Item_loc(me) >= 0;
    advance_position (Lalr_Item_loc(me));
    margin = fix_margin ();
    print_comment(Lalr_Item_src_info(me)->pre_comment);
    PRINT_Ident(Lalr_Item_lhs (me));
    Print_Layout (" ");
    Print_Layout (" ");
    Print_String ("->");
    Print_Layout (" ");
    { Int margin = fix_margin ();
      List_Lalr_LR_Symbol xxx_rhs1 = Lalr_Item_rhs1 (me);
      for (; xxx_rhs1 != NULL; xxx_rhs1 = xxx_rhs1 ? List_Lalr_LR_Symbol_next(xxx_rhs1) : NULL) {
        Lalr_LR_Symbol yyy_rhs1 = List_Lalr_LR_Symbol_data(xxx_rhs1);
        Print_Layout (" ");
        PRINT_Lalr_LR_Symbol(yyy_rhs1);
      }
      set_margin (margin);
    }
    Print_Layout (" ");
    Print_String (".");
    PRINT_Lalr_LR_Symbols(Lalr_Item_rhs2 (me));
    if (Lalr_Item_followers (me) != NULL) {
      List_Ident yyy_followers = Lalr_Item_followers (me);
      Print_Layout ("\t");
      Print_String ("followers:");
      Print_Layout (" ");
      { Int margin = fix_margin ();
        List_Ident xxx_yyy_followers = yyy_followers;
        for (; xxx_yyy_followers != NULL; xxx_yyy_followers = xxx_yyy_followers ? List_Ident_next(xxx_yyy_followers) : NULL) {
          Ident yyy_yyy_followers = List_Ident_data(xxx_yyy_followers);
          PRINT_Ident(yyy_yyy_followers);
          Print_String (" ");
        }
        set_margin (margin);
      }
    }
    print_comment(Lalr_Item_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Lalr_Item (Lalr_Item me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Lalr_Item(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Lalr_Transition (Lalr_Transition me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Lalr_Transition_loc(me) >= 0;
    advance_position (Lalr_Transition_loc(me));
    margin = fix_margin ();
    print_comment(Lalr_Transition_src_info(me)->pre_comment);
    PRINT_Lalr_LR_Symbol(Lalr_Transition_symbol (me));
    Print_Layout (" ");
    Print_String ("=>");
    Print_Layout (" ");
    Print_Keyword ("state");
    Print_Layout (" ");
    PRINT_Int(Lalr_Transition_num (me));
    print_comment(Lalr_Transition_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Lalr_Transition (Lalr_Transition me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Lalr_Transition(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Lalr_Scope (Lalr_Scope me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Lalr_Scope (Lalr_Scope me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Lalr_Scope(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Lalr_LR_Symbols (List_Lalr_LR_Symbols_data(me));
    PRINT_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Lalr_LR_Symbols (List_Lalr_LR_Symbols me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Lalr_LR_Symbols(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Lalr_LR_Symbol (List_Lalr_LR_Symbol_data(me));
    PRINT_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Lalr_LR_Symbol (List_Lalr_LR_Symbol me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Lalr_LR_Symbol(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Lalr_Transition (List_Lalr_Transition me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Lalr_Transition (List_Lalr_Transition_data(me));
    PRINT_List_Lalr_Transition (List_Lalr_Transition_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Lalr_Transition (List_Lalr_Transition me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Lalr_Transition(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Lalr_Item (List_Lalr_Item me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Lalr_Item (List_Lalr_Item_data(me));
    PRINT_List_Lalr_Item (List_Lalr_Item_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Lalr_Item (List_Lalr_Item me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Lalr_Item(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Lalr_LR_state (List_Lalr_LR_state me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Lalr_LR_state (List_Lalr_LR_state_data(me));
    PRINT_List_Lalr_LR_state (List_Lalr_LR_state_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Lalr_LR_state (List_Lalr_LR_state me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Lalr_LR_state(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Lalr_Production (List_Lalr_Production me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Lalr_Production (List_Lalr_Production_data(me));
    PRINT_List_Lalr_Production (List_Lalr_Production_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Lalr_Production (List_Lalr_Production me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Lalr_Production(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Lalr_Emptiness (Lalr_Emptiness me)
{ switch (me) {
    case 0:
      Print_Keyword ("NON_EMPTY");
      break;
    case 1:
      Print_Keyword ("EMPTY");
      break;
  }
}

char *Text_Lalr_Emptiness (Lalr_Emptiness me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Lalr_Emptiness(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

