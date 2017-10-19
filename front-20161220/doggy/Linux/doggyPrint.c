#include "doggyPrint.h"
#include <front/text.h>

#include <front/print_support.h>

void Print_doggy_doggy (doggy_doggy me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_doggy_loc(me) >= 0;
    advance_position (doggy_doggy_loc(me));
    margin = fix_margin ();
    print_comment(doggy_doggy_src_info(me)->pre_comment);
    if (doggy_doggy_types (me) != NULL) {
      List_doggy_Typedef yyy_types = doggy_doggy_types (me);
      Print_Keyword ("TYPES");
      Print_Layout ("\n");
      Print_Layout ("\n");
      { Int margin = fix_margin ();
        List_doggy_Typedef xxx_yyy_types = yyy_types;
        for (; xxx_yyy_types != NULL; xxx_yyy_types = xxx_yyy_types ? List_doggy_Typedef_next(xxx_yyy_types) : NULL) {
          doggy_Typedef yyy_yyy_types = List_doggy_Typedef_data(xxx_yyy_types);
          PRINT_doggy_Typedef(yyy_yyy_types);
        }
        set_margin (margin);
      }
      Print_Layout ("\n");
      Print_Layout ("\n");
    }
    PRINT_doggy_machine_description(doggy_doggy_source (me));
    Print_Layout ("\n");
    if (doggy_doggy_target (me) != NULL) {
      doggy_machine_description yyy_target = doggy_doggy_target (me);
      PRINT_doggy_machine_description(yyy_target);
      Print_Layout ("\n");
    }
    if (doggy_doggy_funcs (me) != NULL) {
      List_doggy_FunctionDef yyy_funcs = doggy_doggy_funcs (me);
      Print_Keyword ("EXTERNAL");
      Print_Layout ("\n");
      Print_Layout ("\n");
      { Int margin = fix_margin ();
        List_doggy_FunctionDef xxx_yyy_funcs = yyy_funcs;
        for (; xxx_yyy_funcs != NULL; xxx_yyy_funcs = xxx_yyy_funcs ? List_doggy_FunctionDef_next(xxx_yyy_funcs) : NULL) {
          doggy_FunctionDef yyy_yyy_funcs = List_doggy_FunctionDef_data(xxx_yyy_funcs);
          PRINT_doggy_FunctionDef(yyy_yyy_funcs);
        }
        set_margin (margin);
      }
      Print_Layout ("\n");
    }
    { Int margin = fix_margin ();
      List_doggy_Section xxx_sections = doggy_doggy_sections (me);
      for (; xxx_sections != NULL; xxx_sections = xxx_sections ? List_doggy_Section_next(xxx_sections) : NULL) {
        doggy_Section yyy_sections = List_doggy_Section_data(xxx_sections);
        PRINT_doggy_Section(yyy_sections);
      }
      set_margin (margin);
    }
    print_comment(doggy_doggy_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_doggy (doggy_doggy me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_doggy(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Typedef (doggy_Typedef me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Typedef_loc(me) >= 0;
    advance_position (doggy_Typedef_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Typedef_src_info(me)->pre_comment);
    start_label (me);
    PRINT_Ident(doggy_Typedef_id (me));
    end_label ();
    if (doggy_Typedef_name (me) != NULL && doggy_Typedef_short_hand (me) != NULL && doggy_Typedef_value (me) != NULL) {
      String yyy_name = doggy_Typedef_name (me);
      String yyy_short_hand = doggy_Typedef_short_hand (me);
      String yyy_value = doggy_Typedef_value (me);
      Print_Layout (" ");
      PRINT_String(yyy_name);
      Print_Layout (" ");
      PRINT_String(yyy_short_hand);
      Print_Layout (" ");
      PRINT_String(yyy_value);
      Print_Layout (" ");
    }
    Print_Layout ("\t");
    if (doggy_Typedef_attrs (me) != NULL) {
      doggy_Attributes yyy_attrs = doggy_Typedef_attrs (me);
      Print_Layout (" ");
      Print_Keyword ("ATTRIBUTES");
      Print_Layout (" ");
      Print_String ("{");
      PRINT_doggy_Attributes(yyy_attrs);
      Print_String ("}");
    }
    Print_Layout ("\n");
    print_comment(doggy_Typedef_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Typedef (doggy_Typedef me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Typedef(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_FunctionDef (doggy_FunctionDef me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_FunctionDef_loc(me) >= 0;
    advance_position (doggy_FunctionDef_loc(me));
    margin = fix_margin ();
    print_comment(doggy_FunctionDef_src_info(me)->pre_comment);
    switch (doggy_FunctionDef_tag(me)) {
      case doggy_ExtFunc_kind:
        Print_Keyword ("extern");
        Print_Layout (" ");
        PRINT_doggy_Type(doggy_FunctionDef_result (me));
        Print_Layout ("\t");
        start_label (me);
        PRINT_Ident(doggy_FunctionDef_id (me));
        end_label ();
        Print_Layout (" ");
        Print_String ("(");
        if (doggy_ExtFunc_args (me) != NULL) {
          List_doggy_Type yyy_args = doggy_ExtFunc_args (me);
          { Int margin = fix_margin ();
            Bool __first = TRUE;
            List_doggy_Type xxx_yyy_args = yyy_args;
            for (; xxx_yyy_args != NULL; xxx_yyy_args = xxx_yyy_args ? List_doggy_Type_next(xxx_yyy_args) : NULL) {
              doggy_Type yyy_yyy_args = List_doggy_Type_data(xxx_yyy_args);
              if (!__first) {
                Print_String (",");
;
              }
              __first = FALSE;
              PRINT_doggy_Type(yyy_yyy_args);
            }
            set_margin (margin);
          }
        }
        Print_String (")");
        Print_String (";");
        Print_Layout ("\n");
        break;
      case doggy_ExtVar_kind:
        Print_Keyword ("extern");
        Print_Layout (" ");
        PRINT_doggy_Type(doggy_FunctionDef_result (me));
        Print_Layout ("\t");
        start_label (me);
        PRINT_Ident(doggy_FunctionDef_id (me));
        end_label ();
        Print_Layout (" ");
        Print_String (";");
        Print_Layout ("\n");
        break;
    }
    print_comment(doggy_FunctionDef_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_FunctionDef (doggy_FunctionDef me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_FunctionDef(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_machine_description (doggy_machine_description me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_machine_description_loc(me) >= 0;
    advance_position (doggy_machine_description_loc(me));
    margin = fix_margin ();
    print_comment(doggy_machine_description_src_info(me)->pre_comment);
    Print_Keyword ("MACHINE");
    Print_Layout (" ");
    Print_Keyword ("DESCRIPTION");
    Print_Layout (" ");
    start_label (me);
    PRINT_Ident(doggy_machine_description_id (me));
    end_label ();
    Print_Layout ("\n");
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_doggy_Operation_def xxx_defs = doggy_machine_description_defs (me);
      for (; xxx_defs != NULL; xxx_defs = xxx_defs ? List_doggy_Operation_def_next(xxx_defs) : NULL) {
        doggy_Operation_def yyy_defs = List_doggy_Operation_def_data(xxx_defs);
        PRINT_doggy_Operation_def(yyy_defs);
      }
      set_margin (margin);
    }
    if (doggy_machine_description_supports (me) != NULL) {
      List_doggy_Applied_formal yyy_supports = doggy_machine_description_supports (me);
      Print_Keyword ("SUPPORTS");
      { Int margin = fix_margin ();
        List_doggy_Applied_formal xxx_yyy_supports = yyy_supports;
        for (; xxx_yyy_supports != NULL; xxx_yyy_supports = xxx_yyy_supports ? List_doggy_Applied_formal_next(xxx_yyy_supports) : NULL) {
          doggy_Applied_formal yyy_yyy_supports = List_doggy_Applied_formal_data(xxx_yyy_supports);
          PRINT_doggy_Applied_formal(yyy_yyy_supports);
        }
        set_margin (margin);
      }
    }
    print_comment(doggy_machine_description_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_machine_description (doggy_machine_description me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_machine_description(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Operation_def (doggy_Operation_def me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Operation_def_loc(me) >= 0;
    advance_position (doggy_Operation_def_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Operation_def_src_info(me)->pre_comment);
    start_label (me);
    PRINT_Ident(doggy_Operation_def_id (me));
    end_label ();
    Print_Layout (" ");
    Print_String ("(");
    if (doggy_Operation_def_types (me) != NULL) {
      List_doggy_Type yyy_types = doggy_Operation_def_types (me);
      { Int margin = fix_margin ();
        Bool __first = TRUE;
        List_doggy_Type xxx_yyy_types = yyy_types;
        for (; xxx_yyy_types != NULL; xxx_yyy_types = xxx_yyy_types ? List_doggy_Type_next(xxx_yyy_types) : NULL) {
          doggy_Type yyy_yyy_types = List_doggy_Type_data(xxx_yyy_types);
          if (!__first) {
            Print_String (",");
;
          }
          __first = FALSE;
          PRINT_doggy_Type(yyy_yyy_types);
        }
        set_margin (margin);
      }
    }
    Print_String (")");
    if (doggy_Operation_def_result (me) != NULL) {
      doggy_Type yyy_result = doggy_Operation_def_result (me);
      Print_Layout (" ");
      Print_String (":");
      Print_Layout (" ");
      PRINT_doggy_Type(yyy_result);
    }
    Print_Layout ("\t");
    PRINT_Ident(doggy_Operation_def_actual_id (me));
    Print_Layout ("\t");
    if (doggy_Operation_def_descr (me) != NULL) {
      doggy_Attributes yyy_descr = doggy_Operation_def_descr (me);
      Print_Layout (" ");
      Print_Keyword ("ATTRIBUTES");
      Print_Layout (" ");
      Print_String ("{");
      PRINT_doggy_Attributes(yyy_descr);
      Print_String ("}");
    }
    Print_Layout ("\t");
    { Int margin = fix_margin ();
      List_doggy_Property xxx_props = doggy_Operation_def_props (me);
      for (; xxx_props != NULL; xxx_props = xxx_props ? List_doggy_Property_next(xxx_props) : NULL) {
        doggy_Property yyy_props = List_doggy_Property_data(xxx_props);
        PRINT_doggy_Property(yyy_props);
        Print_Layout (" ");
      }
      set_margin (margin);
    }
    Print_Layout ("\n");
    print_comment(doggy_Operation_def_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Operation_def (doggy_Operation_def me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Operation_def(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Attributes (doggy_Attributes me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Attributes_loc(me) >= 0;
    advance_position (doggy_Attributes_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Attributes_src_info(me)->pre_comment);
    if (doggy_Attributes_ids (me) != NULL) {
      List_doggy_Attribute yyy_ids = doggy_Attributes_ids (me);
      doggy_Attributes yyy_tail = doggy_Attributes_tail (me);
      { Int margin = fix_margin ();
        List_doggy_Attribute xxx_yyy_ids = yyy_ids;
        for (; xxx_yyy_ids != NULL; xxx_yyy_ids = xxx_yyy_ids ? List_doggy_Attribute_next(xxx_yyy_ids) : NULL) {
          doggy_Attribute yyy_yyy_ids = List_doggy_Attribute_data(xxx_yyy_ids);
          PRINT_doggy_Attribute(yyy_yyy_ids);
          Print_Layout (" ");
        }
        set_margin (margin);
      }
      if (yyy_tail != NULL) {
        doggy_Attributes yyy_yyy_tail = yyy_tail;
        Print_String (",");
        PRINT_doggy_Attributes(yyy_yyy_tail);
      }
    }
    print_comment(doggy_Attributes_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Attributes (doggy_Attributes me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Attributes(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Attribute (doggy_Attribute me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Attribute_loc(me) >= 0;
    advance_position (doggy_Attribute_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Attribute_src_info(me)->pre_comment);
    switch (doggy_Attribute_tag(me)) {
      case doggy_IdAttr_kind:
        PRINT_Ident(doggy_IdAttr_id (me));
        break;
      case doggy_OpAttr_kind:
        Print_Keyword ("OPR");
        break;
      case doggy_IntAttr_kind:
        PRINT_Int(doggy_IntAttr_i (me));
        break;
    }
    print_comment(doggy_Attribute_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Attribute (doggy_Attribute me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Attribute(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Section (doggy_Section me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Section_loc(me) >= 0;
    advance_position (doggy_Section_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Section_src_info(me)->pre_comment);
    switch (doggy_Section_tag(me)) {
      case doggy_FuncSection_kind:
        Print_Keyword ("FUNCTIONS");
        Print_Layout ("\n");
        Print_Layout ("\n");
        { Int margin = fix_margin ();
          List_doggy_Func xxx_funcs = doggy_FuncSection_funcs (me);
          for (; xxx_funcs != NULL; xxx_funcs = xxx_funcs ? List_doggy_Func_next(xxx_funcs) : NULL) {
            doggy_Func yyy_funcs = List_doggy_Func_data(xxx_funcs);
            PRINT_doggy_Func(yyy_funcs);
            Print_Layout ("\n");
          }
          set_margin (margin);
        }
        break;
      case doggy_RuleSection_kind:
        Print_Keyword ("RULES");
        if (doggy_RuleSection_rules_id (me) != NULL) {
          Ident yyy_rules_id = doggy_RuleSection_rules_id (me);
          Print_Layout (" ");
          Print_String (":");
          Print_Layout (" ");
          PRINT_Ident(yyy_rules_id);
        }
        Print_Layout ("\n");
        Print_Layout ("\n");
        { Int margin = fix_margin ();
          List_doggy_Rule xxx_rules = doggy_RuleSection_rules (me);
          for (; xxx_rules != NULL; xxx_rules = xxx_rules ? List_doggy_Rule_next(xxx_rules) : NULL) {
            doggy_Rule yyy_rules = List_doggy_Rule_data(xxx_rules);
            PRINT_doggy_Rule(yyy_rules);
            Print_Layout ("\n");
          }
          set_margin (margin);
        }
        Print_Layout ("\n");
        break;
    }
    print_comment(doggy_Section_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Section (doggy_Section me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Section(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Rule (doggy_Rule me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Rule_loc(me) >= 0;
    advance_position (doggy_Rule_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Rule_src_info(me)->pre_comment);
    PRINT_doggy_Lhs(doggy_Rule_lhs (me));
    Print_Layout ("\n");
    Print_Layout (" ");
    Print_Layout (" ");
    PRINT_doggy_Rhs(doggy_Rule_rhs (me));
    Print_String (";");
    Print_Layout ("\n");
    print_comment(doggy_Rule_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Rule (doggy_Rule me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Rule(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Lhs (doggy_Lhs me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Lhs_loc(me) >= 0;
    advance_position (doggy_Lhs_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Lhs_src_info(me)->pre_comment);
    switch (doggy_Lhs_tag(me)) {
      case doggy_LabeledLhs_kind:
        PRINT_Ident(doggy_LabeledLhs_id (me));
        Print_String (":");
        Print_Layout ("\n");
        PRINT_doggy_Pattern(doggy_Lhs_pat (me));
        break;
      case doggy_UnLabeledLhs_kind:
        PRINT_doggy_Pattern(doggy_Lhs_pat (me));
        break;
    }
    print_comment(doggy_Lhs_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Lhs (doggy_Lhs me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Lhs(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Func (doggy_Func me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Func_loc(me) >= 0;
    advance_position (doggy_Func_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Func_src_info(me)->pre_comment);
    if (doggy_Func_ext (me)) {
      Print_Keyword ("extern");
      Print_Layout (" ");
    }
    PRINT_doggy_Type(doggy_Func_type (me));
    Print_Layout (" ");
    start_label (me);
    PRINT_Ident(doggy_Func_id (me));
    end_label ();
    Print_Layout ("\n");
    Print_Layout (" ");
    Print_Layout (" ");
    { Int margin = fix_margin ();
      Bool __first = TRUE;
      List_doggy_FuncRule xxx_rules = doggy_Func_rules (me);
      for (; xxx_rules != NULL; xxx_rules = xxx_rules ? List_doggy_FuncRule_next(xxx_rules) : NULL) {
        doggy_FuncRule yyy_rules = List_doggy_FuncRule_data(xxx_rules);
        if (!__first) {
          Print_String (",");
;
        }
        __first = FALSE;
        PRINT_doggy_FuncRule(yyy_rules);
        Print_Layout ("\n");
      }
      set_margin (margin);
    }
    Print_String (";");
    Print_Layout ("\n");
    print_comment(doggy_Func_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Func (doggy_Func me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Func(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_FuncRule (doggy_FuncRule me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_FuncRule_loc(me) >= 0;
    advance_position (doggy_FuncRule_loc(me));
    margin = fix_margin ();
    print_comment(doggy_FuncRule_src_info(me)->pre_comment);
    Print_String ("(");
    if (doggy_FuncRule_args (me) != NULL) {
      List_doggy_Argument yyy_args = doggy_FuncRule_args (me);
      { Int margin = fix_margin ();
        Bool __first = TRUE;
        List_doggy_Argument xxx_yyy_args = yyy_args;
        for (; xxx_yyy_args != NULL; xxx_yyy_args = xxx_yyy_args ? List_doggy_Argument_next(xxx_yyy_args) : NULL) {
          doggy_Argument yyy_yyy_args = List_doggy_Argument_data(xxx_yyy_args);
          if (!__first) {
            Print_String (",");
;
          }
          __first = FALSE;
          PRINT_doggy_Argument(yyy_yyy_args);
        }
        set_margin (margin);
      }
    }
    Print_String (")");
    Print_Layout ("\n");
    PRINT_doggy_Rhs(doggy_FuncRule_rhs (me));
    print_comment(doggy_FuncRule_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_FuncRule (doggy_FuncRule me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_FuncRule(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Argument (doggy_Argument me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Argument_loc(me) >= 0;
    advance_position (doggy_Argument_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Argument_src_info(me)->pre_comment);
    switch (doggy_Argument_tag(me)) {
      case doggy_TypedArg_kind:
        PRINT_doggy_Type(doggy_TypedArg_type (me));
        Print_Layout (" ");
        start_label (me);
        PRINT_Ident(doggy_Argument_id (me));
        end_label ();
        PRINT_doggy_ArgPat(doggy_Argument_pat (me));
        break;
      case doggy_UnTypedArg_kind:
        start_label (me);
        PRINT_Ident(doggy_Argument_id (me));
        end_label ();
        PRINT_doggy_ArgPat(doggy_Argument_pat (me));
        break;
    }
    print_comment(doggy_Argument_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Argument (doggy_Argument me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Argument(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_ArgPat (doggy_ArgPat me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_ArgPat_loc(me) >= 0;
    advance_position (doggy_ArgPat_loc(me));
    margin = fix_margin ();
    print_comment(doggy_ArgPat_src_info(me)->pre_comment);
    switch (doggy_ArgPat_tag(me)) {
      case doggy_PatArg_kind:
        PRINT_doggy_Pattern(doggy_PatArg_pat (me));
        break;
      case doggy_SetArg_kind:
        Print_String ("=");
        PRINT_doggy_Applied_operation(doggy_SetArg_set (me));
        break;
    }
    print_comment(doggy_ArgPat_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_ArgPat (doggy_ArgPat me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_ArgPat(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Pattern (doggy_Pattern me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Pattern_loc(me) >= 0;
    advance_position (doggy_Pattern_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Pattern_src_info(me)->pre_comment);
    switch (doggy_Pattern_tag(me)) {
      case doggy_TypedPattern_kind:
        PRINT_doggy_Type(doggy_TypedPattern_btype (me));
        Print_Layout (" ");
        PRINT_doggy_Pattern(doggy_TypedPattern_pat (me));
        break;
      case doggy_ConsPattern_kind:
        PRINT_doggy_Pattern(doggy_ConsPattern_lhs (me));
        Print_String ("::");
        PRINT_doggy_Pattern(doggy_ConsPattern_rhs (me));
        break;
      case doggy_DefPattern_kind:
        Print_String ("{");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_doggy_Pattern xxx_ids = doggy_DefPattern_ids (me);
          for (; xxx_ids != NULL; xxx_ids = xxx_ids ? List_doggy_Pattern_next(xxx_ids) : NULL) {
            doggy_Pattern yyy_ids = List_doggy_Pattern_data(xxx_ids);
            if (!__first) {
              Print_String (",");
;
            }
            __first = FALSE;
            PRINT_doggy_Pattern(yyy_ids);
          }
          set_margin (margin);
        }
        Print_String ("}");
        Print_String ("=");
        PRINT_doggy_Pattern(doggy_DefPattern_arg (me));
        break;
      case doggy_IdentPattern_kind:
        start_label (me);
        PRINT_Ident(doggy_IdentPattern_id (me));
        end_label ();
        break;
      case doggy_OpPattern_kind:
        PRINT_doggy_Applied_operation(doggy_OpPattern_op (me));
        Print_String ("(");
        if (doggy_OpPattern_args (me) != NULL) {
          List_doggy_Pattern yyy_args = doggy_OpPattern_args (me);
          { Int margin = fix_margin ();
            Bool __first = TRUE;
            List_doggy_Pattern xxx_yyy_args = yyy_args;
            for (; xxx_yyy_args != NULL; xxx_yyy_args = xxx_yyy_args ? List_doggy_Pattern_next(xxx_yyy_args) : NULL) {
              doggy_Pattern yyy_yyy_args = List_doggy_Pattern_data(xxx_yyy_args);
              if (!__first) {
                Print_String (",");
;
              }
              __first = FALSE;
              PRINT_doggy_Pattern(yyy_yyy_args);
            }
            set_margin (margin);
          }
        }
        Print_String (")");
        break;
      case doggy_ConstPattern_kind:
        PRINT_Int(doggy_ConstPattern_cnst (me));
        break;
      case doggy_NullPattern_kind:
        Print_Keyword ("NULL");
        break;
      case doggy_DontCarePattern_kind:
        Print_Keyword ("_");
        if (doggy_DontCarePattern_expr (me) != NULL) {
          doggy_Expr yyy_expr = doggy_DontCarePattern_expr (me);
          Print_String ("=");
          PRINT_doggy_Expr(yyy_expr);
        }
        break;
    }
    print_comment(doggy_Pattern_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Pattern (doggy_Pattern me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Pattern(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Rhs (doggy_Rhs me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Rhs_loc(me) >= 0;
    advance_position (doggy_Rhs_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Rhs_src_info(me)->pre_comment);
    switch (doggy_Rhs_tag(me)) {
      case doggy_PlainRhs_kind:
        { Int margin = fix_margin ();
          List_doggy_Guard xxx_guards = doggy_PlainRhs_guards (me);
          for (; xxx_guards != NULL; xxx_guards = xxx_guards ? List_doggy_Guard_next(xxx_guards) : NULL) {
            doggy_Guard yyy_guards = List_doggy_Guard_data(xxx_guards);
            PRINT_doggy_Guard(yyy_guards);
            Print_Layout ("\n");
          }
          set_margin (margin);
        }
        break;
      case doggy_BlockRhs_kind:
        Print_String ("{");
        Print_Layout (" ");
        PRINT_doggy_Rhs(doggy_BlockRhs_rhs (me));
        Print_String ("}");
        if (doggy_BlockRhs_where (me) != NULL) {
          doggy_Wherepart yyy_where = doggy_BlockRhs_where (me);
          Print_Layout ("\n");
          Print_Layout (" ");
          Print_Layout (" ");
          PRINT_doggy_Wherepart(yyy_where);
        }
        Print_Layout ("\n");
        break;
    }
    print_comment(doggy_Rhs_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Rhs (doggy_Rhs me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Rhs(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Guard (doggy_Guard me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Guard_loc(me) >= 0;
    advance_position (doggy_Guard_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Guard_src_info(me)->pre_comment);
    switch (doggy_Guard_tag(me)) {
      case doggy_RhsGuard_kind:
        Print_String ("|");
        Print_Layout (" ");
        PRINT_doggy_Expr(doggy_Guard_conds (me));
        Print_Layout ("\n");
        Print_String ("{");
        Print_Layout (" ");
        PRINT_doggy_Rhs(doggy_RhsGuard_rhs (me));
        Print_String ("}");
        if (doggy_Guard_where (me) != NULL) {
          doggy_Wherepart yyy_where = doggy_Guard_where (me);
          Print_Layout ("\n");
          Print_Layout (" ");
          Print_Layout (" ");
          PRINT_doggy_Wherepart(yyy_where);
        }
        break;
      case doggy_ExprGuard_kind:
        if (doggy_Guard_conds (me) != NULL) {
          doggy_Expr yyy_conds = doggy_Guard_conds (me);
          Print_String ("|");
          Print_Layout (" ");
          PRINT_doggy_Expr(yyy_conds);
          Print_Layout ("\n");
        }
        Print_String ("->");
        Print_Layout (" ");
        PRINT_doggy_ExprSeq(doggy_ExprGuard_exprs (me));
        if (doggy_Guard_where (me) != NULL) {
          doggy_Wherepart yyy_where = doggy_Guard_where (me);
          Print_Layout ("\n");
          Print_Layout (" ");
          Print_Layout (" ");
          PRINT_doggy_Wherepart(yyy_where);
        }
        break;
    }
    print_comment(doggy_Guard_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Guard (doggy_Guard me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Guard(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_ExprSeq (doggy_ExprSeq me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_ExprSeq_loc(me) >= 0;
    advance_position (doggy_ExprSeq_loc(me));
    margin = fix_margin ();
    print_comment(doggy_ExprSeq_src_info(me)->pre_comment);
    switch (doggy_ExprSeq_tag(me)) {
      case doggy_OneExpr_kind:
        PRINT_doggy_Expr(doggy_OneExpr_expr (me));
        break;
      case doggy_MoreExprs_kind:
        Print_String ("{");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_doggy_Expr xxx_exprs = doggy_MoreExprs_exprs (me);
          for (; xxx_exprs != NULL; xxx_exprs = xxx_exprs ? List_doggy_Expr_next(xxx_exprs) : NULL) {
            doggy_Expr yyy_exprs = List_doggy_Expr_data(xxx_exprs);
            if (!__first) {
              Print_String (",");
;
            }
            __first = FALSE;
            PRINT_doggy_Expr(yyy_exprs);
          }
          set_margin (margin);
        }
        Print_String ("}");
        break;
    }
    print_comment(doggy_ExprSeq_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_ExprSeq (doggy_ExprSeq me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_ExprSeq(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Wherepart (doggy_Wherepart me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Wherepart_loc(me) >= 0;
    advance_position (doggy_Wherepart_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Wherepart_src_info(me)->pre_comment);
    Print_Keyword ("WHERE");
    Print_Layout (" ");
    Print_Layout (" ");
    { Int margin = fix_margin ();
      List_doggy_Definition xxx_defs = doggy_Wherepart_defs (me);
      for (; xxx_defs != NULL; xxx_defs = xxx_defs ? List_doggy_Definition_next(xxx_defs) : NULL) {
        doggy_Definition yyy_defs = List_doggy_Definition_data(xxx_defs);
        Print_Layout ("\n");
        Print_Layout (" ");
        Print_Layout (" ");
        PRINT_doggy_Definition(yyy_defs);
      }
      set_margin (margin);
    }
    print_comment(doggy_Wherepart_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Wherepart (doggy_Wherepart me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Wherepart(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Applied_operation (doggy_Applied_operation me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Applied_operation_loc(me) >= 0;
    advance_position (doggy_Applied_operation_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Applied_operation_src_info(me)->pre_comment);
    switch (doggy_Applied_operation_tag(me)) {
      case doggy_AnyOp_kind:
        Print_Keyword ("ANY");
        break;
      case doggy_AppliedOp_kind:
        PRINT_doggy_Applied_formal(doggy_AppliedOp_op (me));
        break;
      case doggy_OpSet_kind:
        Print_String ("[");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_doggy_Applied_formal xxx_ops = doggy_OpSet_ops (me);
          for (; xxx_ops != NULL; xxx_ops = xxx_ops ? List_doggy_Applied_formal_next(xxx_ops) : NULL) {
            doggy_Applied_formal yyy_ops = List_doggy_Applied_formal_data(xxx_ops);
            if (!__first) {
              Print_String (",");
;
            }
            __first = FALSE;
            PRINT_doggy_Applied_formal(yyy_ops);
          }
          set_margin (margin);
        }
        Print_String ("]");
        break;
    }
    print_comment(doggy_Applied_operation_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Applied_operation (doggy_Applied_operation me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Applied_operation(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Applied_formal (doggy_Applied_formal me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Applied_formal_loc(me) >= 0;
    advance_position (doggy_Applied_formal_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Applied_formal_src_info(me)->pre_comment);
    PRINT_Ident(doggy_Applied_formal_id (me));
    print_comment(doggy_Applied_formal_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Applied_formal (doggy_Applied_formal me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Applied_formal(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Expr (doggy_Expr me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Expr_loc(me) >= 0;
    advance_position (doggy_Expr_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Expr_src_info(me)->pre_comment);
    switch (doggy_Expr_tag(me)) {
      case doggy_BinExpr_kind:
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_doggy_Expr xxx_args = doggy_BinExpr_args (me);
          List_doggy_Operator xxx_ops = doggy_BinExpr_ops (me);
          for (; xxx_args != NULL; xxx_args = xxx_args ? List_doggy_Expr_next(xxx_args) : NULL) {
            doggy_Expr yyy_args = List_doggy_Expr_data(xxx_args);
            if (!__first) {
              doggy_Operator yyy_ops = List_doggy_Operator_data(xxx_ops);
              PRINT_doggy_Operator(yyy_ops);
              xxx_ops = xxx_ops ? List_doggy_Operator_next(xxx_ops) : NULL;
            }
            __first = FALSE;
            PRINT_doggy_Expr(yyy_args);
          }
          set_margin (margin);
        }
        break;
      case doggy_ConsExpr_kind:
        PRINT_doggy_Expr(doggy_ConsExpr_lhs (me));
        Print_String ("::");
        PRINT_doggy_Expr(doggy_ConsExpr_rhs (me));
        break;
      case doggy_IdentExpr_kind:
        PRINT_Ident(doggy_IdentExpr_id (me));
        break;
      case doggy_IfExpr_kind:
        Print_Keyword ("IF");
        Print_Layout (" ");
        PRINT_doggy_Expr(doggy_IfExpr_cond (me));
        Print_Layout (" ");
        Print_Keyword ("THEN");
        Print_Layout (" ");
        PRINT_doggy_Expr(doggy_IfExpr_thn (me));
        Print_Layout (" ");
        { Int margin = fix_margin ();
          List_doggy_Expr xxx_conds = doggy_IfExpr_conds (me);
          List_doggy_Expr xxx_thens = doggy_IfExpr_thens (me);
          for (; xxx_conds != NULL && xxx_thens != NULL; xxx_conds = xxx_conds ? List_doggy_Expr_next(xxx_conds) : NULL, xxx_thens = xxx_thens ? List_doggy_Expr_next(xxx_thens) : NULL) {
            doggy_Expr yyy_conds = List_doggy_Expr_data(xxx_conds);
            doggy_Expr yyy_thens = List_doggy_Expr_data(xxx_thens);
            Print_Keyword ("ELSIF");
            Print_Layout (" ");
            PRINT_doggy_Expr(yyy_conds);
            Print_Layout (" ");
            Print_Keyword ("THEN");
            Print_Layout (" ");
            PRINT_doggy_Expr(yyy_thens);
            Print_Layout (" ");
          }
          set_margin (margin);
        }
        Print_Keyword ("ELSE");
        Print_Layout (" ");
        PRINT_doggy_Expr(doggy_IfExpr_els (me));
        Print_Layout (" ");
        Print_Keyword ("FI");
        break;
      case doggy_ConstExpr_kind:
        PRINT_doggy_Constant(doggy_ConstExpr_cnst (me));
        break;
      case doggy_Operation_kind:
        PRINT_Ident(doggy_Operation_id (me));
        Print_Layout (" ");
        Print_String ("(");
        if (doggy_Operation_args (me) != NULL) {
          List_doggy_Expr yyy_args = doggy_Operation_args (me);
          { Int margin = fix_margin ();
            Bool __first = TRUE;
            List_doggy_Expr xxx_yyy_args = yyy_args;
            for (; xxx_yyy_args != NULL; xxx_yyy_args = xxx_yyy_args ? List_doggy_Expr_next(xxx_yyy_args) : NULL) {
              doggy_Expr yyy_yyy_args = List_doggy_Expr_data(xxx_yyy_args);
              if (!__first) {
                Print_String (",");
;
              }
              __first = FALSE;
              PRINT_doggy_Expr(yyy_yyy_args);
            }
            set_margin (margin);
          }
        }
        Print_String (")");
        break;
      case doggy_ParExpr_kind:
        Print_String ("(");
        PRINT_doggy_Expr(doggy_ParExpr_expr (me));
        Print_String (")");
        break;
      case doggy_MonExpr_kind:
        PRINT_doggy_MonOp(doggy_MonExpr_op (me));
        PRINT_doggy_Expr(doggy_MonExpr_arg (me));
        break;
    }
    print_comment(doggy_Expr_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Expr (doggy_Expr me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Expr(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Constant (doggy_Constant me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Constant_loc(me) >= 0;
    advance_position (doggy_Constant_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Constant_src_info(me)->pre_comment);
    switch (doggy_Constant_tag(me)) {
      case doggy_IntConst_kind:
        PRINT_Int(doggy_IntConst_i (me));
        break;
      case doggy_BoolConst_kind:
        PRINT_Bool(doggy_BoolConst_b (me));
        break;
      case doggy_StringConst_kind:
        PRINT_String(doggy_StringConst_s (me));
        break;
      case doggy_NullConst_kind:
        Print_Keyword ("NULL");
        break;
    }
    print_comment(doggy_Constant_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Constant (doggy_Constant me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Constant(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Definition (doggy_Definition me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Definition_loc(me) >= 0;
    advance_position (doggy_Definition_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Definition_src_info(me)->pre_comment);
    PRINT_doggy_Type(doggy_Definition_type (me));
    Print_Layout (" ");
    start_label (me);
    PRINT_Ident(doggy_Definition_id (me));
    end_label ();
    Print_Layout (" ");
    Print_String ("=");
    Print_Layout (" ");
    PRINT_doggy_Expr(doggy_Definition_expr (me));
    print_comment(doggy_Definition_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Definition (doggy_Definition me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Definition(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Type (doggy_Type me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Type_loc(me) >= 0;
    advance_position (doggy_Type_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Type_src_info(me)->pre_comment);
    switch (doggy_Type_tag(me)) {
      case doggy_EdgeType_kind:
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_doggy_Type xxx_types = doggy_EdgeType_types (me);
          for (; xxx_types != NULL; xxx_types = xxx_types ? List_doggy_Type_next(xxx_types) : NULL) {
            doggy_Type yyy_types = List_doggy_Type_data(xxx_types);
            if (!__first) {
              Print_String ("|");
;
            }
            __first = FALSE;
            PRINT_doggy_Type(yyy_types);
          }
          set_margin (margin);
        }
        break;
      case doggy_TupleType_kind:
        Print_String ("{");
        if (doggy_TupleType_types (me) != NULL) {
          List_doggy_Type yyy_types = doggy_TupleType_types (me);
          { Int margin = fix_margin ();
            Bool __first = TRUE;
            List_doggy_Type xxx_yyy_types = yyy_types;
            for (; xxx_yyy_types != NULL; xxx_yyy_types = xxx_yyy_types ? List_doggy_Type_next(xxx_yyy_types) : NULL) {
              doggy_Type yyy_yyy_types = List_doggy_Type_data(xxx_yyy_types);
              if (!__first) {
                Print_String (",");
;
              }
              __first = FALSE;
              PRINT_doggy_Type(yyy_yyy_types);
            }
            set_margin (margin);
          }
        }
        Print_String ("}");
        break;
      case doggy_IdentType_kind:
        if (doggy_IdentType_type (me) != NULL)
        { start_href (doggy_Typedef_loc(doggy_IdentType_type (me)), doggy_IdentType_type (me)); }
        PRINT_Ident(doggy_IdentType_type_id (me));
        if (doggy_IdentType_type (me) != NULL)
        { end_href (); }
        break;
      case doggy_OprType_kind:
        Print_Keyword ("OPR");
        if (doggy_OprType_args (me) != NULL) {
          List_doggy_Type yyy_args = doggy_OprType_args (me);
          Print_String ("(");
          if (yyy_args != NULL) {
            List_doggy_Type yyy_yyy_args = yyy_args;
            { Int margin = fix_margin ();
              Bool __first = TRUE;
              List_doggy_Type xxx_yyy_yyy_args = yyy_yyy_args;
              for (; xxx_yyy_yyy_args != NULL; xxx_yyy_yyy_args = xxx_yyy_yyy_args ? List_doggy_Type_next(xxx_yyy_yyy_args) : NULL) {
                doggy_Type yyy_yyy_yyy_args = List_doggy_Type_data(xxx_yyy_yyy_args);
                if (!__first) {
                  Print_String (",");
;
                }
                __first = FALSE;
                PRINT_doggy_Type(yyy_yyy_yyy_args);
              }
              set_margin (margin);
            }
          }
          Print_String (")");
        }
        break;
      case doggy_PointerType_kind:
        PRINT_doggy_Type(doggy_PointerType_base (me));
        Print_String ("*");
        break;
      case doggy_RangeType_kind:
        Print_String ("[");
        PRINT_doggy_Num(doggy_RangeType_lo (me));
        Print_String ("..");
        PRINT_doggy_Num(doggy_RangeType_hi (me));
        if (doggy_RangeType_step (me) != NULL) {
          doggy_Num yyy_step = doggy_RangeType_step (me);
          Print_Keyword ("STEP");
          PRINT_doggy_Num(yyy_step);
        }
        Print_String ("]");
        break;
      case doggy_FRangeType_kind:
        Print_String ("[");
        PRINT_Ident(doggy_FRangeType_f (me));
        Print_String ("(");
        Print_String (")");
        Print_String ("]");
        break;
    }
    print_comment(doggy_Type_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Type (doggy_Type me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Type(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Num (doggy_Num me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Num_loc(me) >= 0;
    advance_position (doggy_Num_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Num_src_info(me)->pre_comment);
    if (doggy_Num_neg (me)) {
      Print_String ("-");
    }
    PRINT_Int(doggy_Num_i (me));
    print_comment(doggy_Num_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Num (doggy_Num me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Num(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_IdInt (doggy_IdInt me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_IdInt_loc(me) >= 0;
    advance_position (doggy_IdInt_loc(me));
    margin = fix_margin ();
    print_comment(doggy_IdInt_src_info(me)->pre_comment);
    switch (doggy_IdInt_tag(me)) {
      case doggy_IsId_kind:
        PRINT_Ident(doggy_IsId_id (me));
        break;
      case doggy_IsInt_kind:
        PRINT_Int(doggy_IsInt_i (me));
        break;
    }
    print_comment(doggy_IdInt_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_IdInt (doggy_IdInt me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_IdInt(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Path (doggy_Path me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Path_loc(me) >= 0;
    advance_position (doggy_Path_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Path_src_info(me)->pre_comment);
    PRINT_Int(doggy_Path_data (me));
    PRINT_doggy_Type(doggy_Path_type (me));
    PRINT_doggy_Path(doggy_Path_next (me));
    print_comment(doggy_Path_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Path (doggy_Path me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Path(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_ActualOp (doggy_ActualOp me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_ActualOp_loc(me) >= 0;
    advance_position (doggy_ActualOp_loc(me));
    margin = fix_margin ();
    print_comment(doggy_ActualOp_src_info(me)->pre_comment);
    PRINT_Int(doggy_ActualOp_location (me));
    PRINT_Ident(doggy_ActualOp_id (me));
    { Int margin = fix_margin ();
      List_doggy_Operation_def xxx_formals = doggy_ActualOp_formals (me);
      for (; xxx_formals != NULL; xxx_formals = xxx_formals ? List_doggy_Operation_def_next(xxx_formals) : NULL) {
        doggy_Operation_def yyy_formals = List_doggy_Operation_def_data(xxx_formals);
        PRINT_doggy_Operation_def(yyy_formals);
      }
      set_margin (margin);
    }
    print_comment(doggy_ActualOp_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_ActualOp (doggy_ActualOp me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_ActualOp(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_TypePair (doggy_TypePair me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_TypePair_loc(me) >= 0;
    advance_position (doggy_TypePair_loc(me));
    margin = fix_margin ();
    print_comment(doggy_TypePair_src_info(me)->pre_comment);
    PRINT_doggy_Type(doggy_TypePair_t1 (me));
    PRINT_doggy_Type(doggy_TypePair_t2 (me));
    print_comment(doggy_TypePair_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_TypePair (doggy_TypePair me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_TypePair(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Opat (doggy_Opat me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Opat_loc(me) >= 0;
    advance_position (doggy_Opat_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Opat_src_info(me)->pre_comment);
    { Int margin = fix_margin ();
      List_doggy_Type xxx_args = doggy_Opat_args (me);
      for (; xxx_args != NULL; xxx_args = xxx_args ? List_doggy_Type_next(xxx_args) : NULL) {
        doggy_Type yyy_args = List_doggy_Type_data(xxx_args);
        PRINT_doggy_Type(yyy_args);
      }
      set_margin (margin);
    }
    PRINT_doggy_Type(doggy_Opat_result (me));
    print_comment(doggy_Opat_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Opat (doggy_Opat me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Opat(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Format (doggy_Format me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_Format_loc(me) >= 0;
    advance_position (doggy_Format_loc(me));
    margin = fix_margin ();
    print_comment(doggy_Format_src_info(me)->pre_comment);
    { Int margin = fix_margin ();
      List_doggy_Type xxx_args = doggy_Format_args (me);
      for (; xxx_args != NULL; xxx_args = xxx_args ? List_doggy_Type_next(xxx_args) : NULL) {
        doggy_Type yyy_args = List_doggy_Type_data(xxx_args);
        PRINT_doggy_Type(yyy_args);
      }
      set_margin (margin);
    }
    PRINT_doggy_Type(doggy_Format_result (me));
    PRINT_Bool(doggy_Format_swap (me));
    print_comment(doggy_Format_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Format (doggy_Format me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Format(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_dummy_type (doggy_dummy_type me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = doggy_dummy_type_loc(me) >= 0;
    advance_position (doggy_dummy_type_loc(me));
    margin = fix_margin ();
    print_comment(doggy_dummy_type_src_info(me)->pre_comment);
    { Int margin = fix_margin ();
      List_Ident xxx_a = doggy_dummy_type_a (me);
      for (; xxx_a != NULL; xxx_a = xxx_a ? List_Ident_next(xxx_a) : NULL) {
        Ident yyy_a = List_Ident_data(xxx_a);
        PRINT_Ident(yyy_a);
      }
      set_margin (margin);
    }
    { Int margin = fix_margin ();
      for (; ; ) {
      }
      set_margin (margin);
    }
    { Int margin = fix_margin ();
      List_doggy_ActualOp xxx_y = doggy_dummy_type_y (me);
      for (; xxx_y != NULL; xxx_y = xxx_y ? List_doggy_ActualOp_next(xxx_y) : NULL) {
        doggy_ActualOp yyy_y = List_doggy_ActualOp_data(xxx_y);
        PRINT_doggy_ActualOp(yyy_y);
      }
      set_margin (margin);
    }
    { Int margin = fix_margin ();
      List_doggy_TypePair xxx_z = doggy_dummy_type_z (me);
      for (; xxx_z != NULL; xxx_z = xxx_z ? List_doggy_TypePair_next(xxx_z) : NULL) {
        doggy_TypePair yyy_z = List_doggy_TypePair_data(xxx_z);
        PRINT_doggy_TypePair(yyy_z);
      }
      set_margin (margin);
    }
    { Int margin = fix_margin ();
      for (; ; ) {
      }
      set_margin (margin);
    }
    print_comment(doggy_dummy_type_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_dummy_type (doggy_dummy_type me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_dummy_type(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Scope (doggy_Scope me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    switch (doggy_Scope_tag(me)) {
      case doggy_OpSetScope_kind:
        break;
      case doggy_AppliedOpScope_kind:
        break;
      case doggy_ExprGuardScope_kind:
        break;
      case doggy_RhsGuardScope_kind:
        break;
      case doggy_FuncRuleScope_kind:
        break;
      case doggy_RuleScope_kind:
        break;
      case doggy_machine_descriptionScope_kind:
        break;
    }
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_doggy_Scope (doggy_Scope me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Scope(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Num (List_doggy_Num me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Num (List_doggy_Num_data(me));
    PRINT_List_doggy_Num (List_doggy_Num_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Num (List_doggy_Num me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Num(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_List_doggy_TypePair (List_List_doggy_TypePair me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_List_doggy_TypePair (List_List_doggy_TypePair_data(me));
    PRINT_List_List_doggy_TypePair (List_List_doggy_TypePair_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_List_doggy_TypePair (List_List_doggy_TypePair me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_List_doggy_TypePair(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_TypePair (List_doggy_TypePair me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_TypePair (List_doggy_TypePair_data(me));
    PRINT_List_doggy_TypePair (List_doggy_TypePair_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_TypePair (List_doggy_TypePair me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_TypePair(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_ActualOp (List_doggy_ActualOp me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_ActualOp (List_doggy_ActualOp_data(me));
    PRINT_List_doggy_ActualOp (List_doggy_ActualOp_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_ActualOp (List_doggy_ActualOp me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_ActualOp(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_List_doggy_Type (List_List_doggy_Type me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_List_doggy_Type (List_List_doggy_Type_data(me));
    PRINT_List_List_doggy_Type (List_List_doggy_Type_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_List_doggy_Type (List_List_doggy_Type me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_List_doggy_Type(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Operator (List_doggy_Operator me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Operator (List_doggy_Operator_data(me));
    PRINT_List_doggy_Operator (List_doggy_Operator_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Operator (List_doggy_Operator me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Operator(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Definition (List_doggy_Definition me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Definition (List_doggy_Definition_data(me));
    PRINT_List_doggy_Definition (List_doggy_Definition_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Definition (List_doggy_Definition me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Definition(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Expr (List_doggy_Expr me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Expr (List_doggy_Expr_data(me));
    PRINT_List_doggy_Expr (List_doggy_Expr_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Expr (List_doggy_Expr me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Expr(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Guard (List_doggy_Guard me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Guard (List_doggy_Guard_data(me));
    PRINT_List_doggy_Guard (List_doggy_Guard_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Guard (List_doggy_Guard me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Guard(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Pattern (List_doggy_Pattern me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Pattern (List_doggy_Pattern_data(me));
    PRINT_List_doggy_Pattern (List_doggy_Pattern_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Pattern (List_doggy_Pattern me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Pattern(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Argument (List_doggy_Argument me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Argument (List_doggy_Argument_data(me));
    PRINT_List_doggy_Argument (List_doggy_Argument_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Argument (List_doggy_Argument me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Argument(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_FuncRule (List_doggy_FuncRule me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_FuncRule (List_doggy_FuncRule_data(me));
    PRINT_List_doggy_FuncRule (List_doggy_FuncRule_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_FuncRule (List_doggy_FuncRule me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_FuncRule(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Attribute (List_doggy_Attribute me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Attribute (List_doggy_Attribute_data(me));
    PRINT_List_doggy_Attribute (List_doggy_Attribute_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Attribute (List_doggy_Attribute me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Attribute(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Property (List_doggy_Property me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Property (List_doggy_Property_data(me));
    PRINT_List_doggy_Property (List_doggy_Property_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Property (List_doggy_Property me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Property(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Applied_formal (List_doggy_Applied_formal me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Applied_formal (List_doggy_Applied_formal_data(me));
    PRINT_List_doggy_Applied_formal (List_doggy_Applied_formal_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Applied_formal (List_doggy_Applied_formal me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Applied_formal(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Operation_def (List_doggy_Operation_def me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Operation_def (List_doggy_Operation_def_data(me));
    PRINT_List_doggy_Operation_def (List_doggy_Operation_def_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Operation_def (List_doggy_Operation_def me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Operation_def(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Type (List_doggy_Type me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Type (List_doggy_Type_data(me));
    PRINT_List_doggy_Type (List_doggy_Type_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Type (List_doggy_Type me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Type(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Rule (List_doggy_Rule me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Rule (List_doggy_Rule_data(me));
    PRINT_List_doggy_Rule (List_doggy_Rule_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Rule (List_doggy_Rule me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Rule(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Func (List_doggy_Func me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Func (List_doggy_Func_data(me));
    PRINT_List_doggy_Func (List_doggy_Func_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Func (List_doggy_Func me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Func(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Section (List_doggy_Section me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Section (List_doggy_Section_data(me));
    PRINT_List_doggy_Section (List_doggy_Section_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Section (List_doggy_Section me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Section(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_FunctionDef (List_doggy_FunctionDef me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_FunctionDef (List_doggy_FunctionDef_data(me));
    PRINT_List_doggy_FunctionDef (List_doggy_FunctionDef_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_FunctionDef (List_doggy_FunctionDef me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_FunctionDef(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_doggy_Typedef (List_doggy_Typedef me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_doggy_Typedef (List_doggy_Typedef_data(me));
    PRINT_List_doggy_Typedef (List_doggy_Typedef_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_doggy_Typedef (List_doggy_Typedef me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_doggy_Typedef(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Operator (doggy_Operator me)
{ switch (me) {
    case doggy_CandOp:
      Print_String ("&&");
      break;
    case doggy_CorOp:
      Print_String ("||");
      break;
    case doggy_XorOp:
      Print_String ("^");
      break;
    case doggy_EqOp:
      Print_String ("==");
      break;
    case doggy_NeqOp:
      Print_String ("!=");
      break;
    case doggy_LEOp:
      Print_String ("<=");
      break;
    case doggy_GEOp:
      Print_String (">=");
      break;
    case doggy_LTOp:
      Print_String ("<");
      break;
    case doggy_GTOp:
      Print_String (">");
      break;
    case doggy_SLOp:
      Print_String ("<<");
      break;
    case doggy_SROp:
      Print_String (">>");
      break;
    case doggy_DivOp:
      Print_String ("/");
      break;
    case doggy_ModOp:
      Print_String ("%");
      break;
    case doggy_MulOp:
      Print_String ("*");
      break;
    case doggy_AndOp:
      Print_String ("&");
      break;
    case doggy_AddOp:
      Print_String ("+");
      break;
    case doggy_SubOp:
      Print_String ("-");
      break;
  }
}

char *Text_doggy_Operator (doggy_Operator me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Operator(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_MonOp (doggy_MonOp me)
{ switch (me) {
    case doggy_NotOp:
      Print_String ("!");
      break;
    case doggy_NegOp:
      Print_String ("~");
      break;
    case doggy_AddrOp:
      Print_String ("&");
      break;
    case doggy_DerefOp:
      Print_String ("*");
      break;
    case doggy_PlusOp:
      Print_String ("+");
      break;
    case doggy_MinOp:
      Print_String ("-");
      break;
  }
}

char *Text_doggy_MonOp (doggy_MonOp me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_MonOp(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_doggy_Property (doggy_Property me)
{    Print_Keyword ("COMMUTATIVE");
}

char *Text_doggy_Property (doggy_Property me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_doggy_Property(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

