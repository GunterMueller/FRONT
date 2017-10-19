#include "grammarPrint.h"
#include <front/text.h>

#include <front/print_support.h>

void Print_grammar_grammar (grammar_grammar me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = grammar_grammar_loc(me) >= 0;
    advance_position (grammar_grammar_loc(me));
    margin = fix_margin ();
    print_comment(grammar_grammar_src_info(me)->pre_comment);
    PRINT_grammar_Scanner(grammar_grammar_scanner (me));
    PRINT_grammar_Parser(grammar_grammar_parser (me));
    print_comment(grammar_grammar_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_grammar_grammar (grammar_grammar me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_grammar_grammar(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_grammar_Scanner (grammar_Scanner me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = grammar_Scanner_loc(me) >= 0;
    advance_position (grammar_Scanner_loc(me));
    margin = fix_margin ();
    print_comment(grammar_Scanner_src_info(me)->pre_comment);
    { Int margin = fix_margin ();
      List_grammar_Token xxx_tokens = grammar_Scanner_tokens (me);
      for (; xxx_tokens != NULL; xxx_tokens = xxx_tokens ? List_grammar_Token_next(xxx_tokens) : NULL) {
        grammar_Token yyy_tokens = List_grammar_Token_data(xxx_tokens);
        PRINT_grammar_Token(yyy_tokens);
      }
      set_margin (margin);
    }
    print_comment(grammar_Scanner_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_grammar_Scanner (grammar_Scanner me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_grammar_Scanner(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_grammar_Token (grammar_Token me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = grammar_Token_loc(me) >= 0;
    advance_position (grammar_Token_loc(me));
    margin = fix_margin ();
    print_comment(grammar_Token_src_info(me)->pre_comment);
    PRINT_grammar_RegExpr(grammar_Token_re (me));
    Print_Layout (" ");
    Print_String ("{");
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_String xxx_actions = grammar_Token_actions (me);
      for (; xxx_actions != NULL; xxx_actions = xxx_actions ? List_String_next(xxx_actions) : NULL) {
        String yyy_actions = List_String_data(xxx_actions);
        Print_Layout (" ");
        Print_Layout (" ");
        PRINT_String(yyy_actions);
        Print_String (";");
        Print_Layout ("\n");
      }
      set_margin (margin);
    }
    Print_String ("}");
    Print_Layout ("\n");
    Print_Layout ("\n");
    print_comment(grammar_Token_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_grammar_Token (grammar_Token me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_grammar_Token(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_grammar_RegExpr (grammar_RegExpr me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = grammar_RegExpr_loc(me) >= 0;
    advance_position (grammar_RegExpr_loc(me));
    margin = fix_margin ();
    print_comment(grammar_RegExpr_src_info(me)->pre_comment);
    switch (grammar_RegExpr_tag(me)) {
      case grammar_ChoiceRE_kind:
        PRINT_grammar_RegExpr(grammar_ChoiceRE_head (me));
        if (grammar_ChoiceRE_tail (me) != NULL) {
          grammar_RegExpr yyy_tail = grammar_ChoiceRE_tail (me);
          Print_String ("|");
          PRINT_grammar_RegExpr(yyy_tail);
        }
        break;
      case grammar_SeqRE_kind:
        PRINT_grammar_RegExpr(grammar_SeqRE_head (me));
        if (grammar_SeqRE_tail (me) != NULL) {
          grammar_RegExpr yyy_tail = grammar_SeqRE_tail (me);
          PRINT_grammar_RegExpr(yyy_tail);
        }
        break;
      case grammar_OptRE_kind:
        PRINT_grammar_RegExpr(grammar_PostRE_re (me));
        Print_String ("?");
        break;
      case grammar_PlusRE_kind:
        PRINT_grammar_RegExpr(grammar_PostRE_re (me));
        Print_String ("+");
        break;
      case grammar_TimesRE_kind:
        PRINT_grammar_RegExpr(grammar_PostRE_re (me));
        Print_String ("*");
        break;
      case grammar_StringRE_kind:
        PRINT_String(grammar_StringRE_s (me));
        break;
      case grammar_SOLRE_kind:
        Print_String ("^");
        break;
      case grammar_EOLRE_kind:
        Print_String ("$");
        break;
      case grammar_IdRE_kind:
        Print_String ("{");
        PRINT_Ident(grammar_IdRE_id (me));
        Print_String ("}");
        break;
      case grammar_ParRE_kind:
        Print_String ("(");
        PRINT_grammar_RegExpr(grammar_ParRE_re (me));
        Print_String (")");
        break;
      case grammar_AnyRE_kind:
        Print_String (".");
        break;
    }
    print_comment(grammar_RegExpr_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_grammar_RegExpr (grammar_RegExpr me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_grammar_RegExpr(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_grammar_Parser (grammar_Parser me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = grammar_Parser_loc(me) >= 0;
    advance_position (grammar_Parser_loc(me));
    margin = fix_margin ();
    print_comment(grammar_Parser_src_info(me)->pre_comment);
    { Int margin = fix_margin ();
      List_grammar_ProdRule xxx_rules = grammar_Parser_rules (me);
      for (; xxx_rules != NULL; xxx_rules = xxx_rules ? List_grammar_ProdRule_next(xxx_rules) : NULL) {
        grammar_ProdRule yyy_rules = List_grammar_ProdRule_data(xxx_rules);
        PRINT_grammar_ProdRule(yyy_rules);
      }
      set_margin (margin);
    }
    print_comment(grammar_Parser_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_grammar_Parser (grammar_Parser me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_grammar_Parser(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_grammar_ProdRule (grammar_ProdRule me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = grammar_ProdRule_loc(me) >= 0;
    advance_position (grammar_ProdRule_loc(me));
    margin = fix_margin ();
    print_comment(grammar_ProdRule_src_info(me)->pre_comment);
    switch (grammar_ProdRule_tag(me)) {
      case grammar_NT_Rule_kind:
        PRINT_Ident(grammar_ProdRule_lhs (me));
        Print_Layout (" ");
        Print_Keyword ("nonterminal");
        Print_Layout ("\n");
        break;
      case grammar_Import_Rule_kind:
        PRINT_Ident(grammar_ProdRule_lhs (me));
        Print_Layout (" ");
        Print_Keyword ("import");
        Print_Layout ("\n");
        break;
      case grammar_Extra_Rule_kind:
        PRINT_Ident(grammar_ProdRule_lhs (me));
        Print_Layout (" ");
        Print_Keyword ("extra");
        Print_Layout ("\n");
        break;
    }
    print_comment(grammar_ProdRule_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_grammar_ProdRule (grammar_ProdRule me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_grammar_ProdRule(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_grammar_Scope (grammar_Scope me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_grammar_Scope (grammar_Scope me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_grammar_Scope(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_grammar_ProdRule (List_grammar_ProdRule me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_grammar_ProdRule (List_grammar_ProdRule_data(me));
    PRINT_List_grammar_ProdRule (List_grammar_ProdRule_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_grammar_ProdRule (List_grammar_ProdRule me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_grammar_ProdRule(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_grammar_Token (List_grammar_Token me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_grammar_Token (List_grammar_Token_data(me));
    PRINT_List_grammar_Token (List_grammar_Token_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_grammar_Token (List_grammar_Token me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_grammar_Token(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

