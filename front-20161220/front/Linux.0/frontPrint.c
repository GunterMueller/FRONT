#include "frontPrint.h"
#include <front/text.h>

#include <front/print_support.h>

void Print_front_front (front_front me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_front_loc(me) >= 0;
    advance_position (front_front_loc(me));
    margin = fix_margin ();
    print_comment(front_front_src_info(me)->pre_comment);
    if (front_front_uses (me) != NULL) {
      List_Ident yyy_uses = front_front_uses (me);
      Print_Keyword ("USE");
      Print_Layout (" ");
      { Int margin = fix_margin ();
        Bool __first = TRUE;
        List_Ident xxx_yyy_uses = yyy_uses;
        for (; xxx_yyy_uses != NULL; xxx_yyy_uses = xxx_yyy_uses ? List_Ident_next(xxx_yyy_uses) : NULL) {
          Ident yyy_yyy_uses = List_Ident_data(xxx_yyy_uses);
          if (!__first) {
            Print_String (",");
            Print_Layout (" ");
;
          }
          __first = FALSE;
          PRINT_Ident(yyy_yyy_uses);
        }
        set_margin (margin);
      }
      Print_Layout ("\n");
      Print_Layout ("\n");
    }
    if (front_front_namespaces (me) != NULL) {
      List_front_NameSpace yyy_namespaces = front_front_namespaces (me);
      Print_Keyword ("NAMESPACE");
      Print_Layout (" ");
      { Int margin = fix_margin ();
        Bool __first = TRUE;
        List_front_NameSpace xxx_yyy_namespaces = yyy_namespaces;
        for (; xxx_yyy_namespaces != NULL; xxx_yyy_namespaces = xxx_yyy_namespaces ? List_front_NameSpace_next(xxx_yyy_namespaces) : NULL) {
          front_NameSpace yyy_yyy_namespaces = List_front_NameSpace_data(xxx_yyy_namespaces);
          if (!__first) {
            Print_String (",");
            Print_Layout (" ");
;
          }
          __first = FALSE;
          PRINT_front_NameSpace(yyy_yyy_namespaces);
        }
        set_margin (margin);
      }
      Print_Layout ("\n");
      Print_Layout ("\n");
    }
    { Int margin = fix_margin ();
      List_front_Import xxx_imports = front_front_imports (me);
      for (; xxx_imports != NULL; xxx_imports = xxx_imports ? List_front_Import_next(xxx_imports) : NULL) {
        front_Import yyy_imports = List_front_Import_data(xxx_imports);
        PRINT_front_Import(yyy_imports);
      }
      set_margin (margin);
    }
    if (front_front_rules (me) != NULL) {
      List_front_NonTerminal yyy_rules = front_front_rules (me);
      { Int margin = fix_margin ();
        List_front_NonTerminal xxx_yyy_rules = yyy_rules;
        for (; xxx_yyy_rules != NULL; xxx_yyy_rules = xxx_yyy_rules ? List_front_NonTerminal_next(xxx_yyy_rules) : NULL) {
          front_NonTerminal yyy_yyy_rules = List_front_NonTerminal_data(xxx_yyy_rules);
          PRINT_front_NonTerminal(yyy_yyy_rules);
        }
        set_margin (margin);
      }
    }
    print_comment(front_front_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_front (front_front me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_front(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Import (front_Import me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Import_loc(me) >= 0;
    advance_position (front_Import_loc(me));
    margin = fix_margin ();
    print_comment(front_Import_src_info(me)->pre_comment);
    Print_Keyword ("FROM");
    Print_Layout (" ");
    PRINT_Ident(front_Import_grammar (me));
    Print_String (":");
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      Bool __first = TRUE;
      List_front_ImportedNonTerminal xxx_nts = front_Import_nts (me);
      for (; xxx_nts != NULL; xxx_nts = xxx_nts ? List_front_ImportedNonTerminal_next(xxx_nts) : NULL) {
        front_ImportedNonTerminal yyy_nts = List_front_ImportedNonTerminal_data(xxx_nts);
        if (!__first) {
          Print_String (",");
;
        }
        __first = FALSE;
        PRINT_front_ImportedNonTerminal(yyy_nts);
      }
      set_margin (margin);
    }
    Print_Layout ("\n");
    print_comment(front_Import_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Import (front_Import me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Import(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_ImportedNonTerminal (front_ImportedNonTerminal me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_ImportedNonTerminal_loc(me) >= 0;
    advance_position (front_ImportedNonTerminal_loc(me));
    margin = fix_margin ();
    print_comment(front_ImportedNonTerminal_src_info(me)->pre_comment);
    start_label (me);
    PRINT_Ident(front_ImportedNonTerminal_id (me));
    end_label ();
    if (front_ImportedNonTerminal_type (me) != NULL) {
      Ident yyy_type = front_ImportedNonTerminal_type (me);
      Print_String (":");
      PRINT_Ident(yyy_type);
    }
    print_comment(front_ImportedNonTerminal_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_ImportedNonTerminal (front_ImportedNonTerminal me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_ImportedNonTerminal(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_NonTerminal (front_NonTerminal me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_NonTerminal_loc(me) >= 0;
    advance_position (front_NonTerminal_loc(me));
    margin = fix_margin ();
    print_comment(front_NonTerminal_src_info(me)->pre_comment);
    if (front_NonTerminal_is_root (me)) {
      Print_Keyword ("ROOT");
      Print_Layout (" ");
    }
    if (front_NonTerminal_scan (me) != NULL) {
      front_ScanInfo yyy_scan = front_NonTerminal_scan (me);
      PRINT_front_ScanInfo(yyy_scan);
    }
    start_label (me);
    PRINT_Ident(front_NonTerminal_id (me));
    end_label ();
    if (front_NonTerminal_super (me) != NULL) {
      front_Super yyy_super = front_NonTerminal_super (me);
      Print_Layout (" ");
      PRINT_front_Super(yyy_super);
      Print_Layout (" ");
    }
    Print_Layout ("\n");
    if (front_NonTerminal_meemo (me)) {
      Print_Keyword ("MEMO");
    }
    if (front_NonTerminal_enumerate (me)) {
      Print_Keyword ("ENUM");
    }
    if (front_NonTerminal_skip (me)) {
      Print_Keyword ("SKIP");
    }
    Print_Layout (" ");
    Print_Layout (" ");
    PRINT_front_Defines(front_NonTerminal_alias (me));
    Print_Layout ("\t");
    PRINT_front_Rhs(front_NonTerminal_rhs (me));
    Print_Layout (" ");
    Print_String (";");
    Print_Layout ("\n");
    Print_Layout ("\n");
    Print_Layout ("\n");
    print_comment(front_NonTerminal_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_NonTerminal (front_NonTerminal me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_NonTerminal(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Super (front_Super me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Super_loc(me) >= 0;
    advance_position (front_Super_loc(me));
    margin = fix_margin ();
    print_comment(front_Super_src_info(me)->pre_comment);
    switch (front_Super_tag(me)) {
      case front_SubType_kind:
        PRINT_Ident(front_SubType_x (me));
        PRINT_Ident(front_Super_id (me));
        break;
      case front_NoType_kind:
        Print_String (":");
        PRINT_Ident(front_Super_id (me));
        break;
    }
    print_comment(front_Super_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Super (front_Super me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Super(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Rhs (front_Rhs me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Rhs_loc(me) >= 0;
    advance_position (front_Rhs_loc(me));
    margin = fix_margin ();
    print_comment(front_Rhs_src_info(me)->pre_comment);
    { Int margin = fix_margin ();
      List_front_Scoping xxx_sc = front_Rhs_sc (me);
      for (; xxx_sc != NULL; xxx_sc = xxx_sc ? List_front_Scoping_next(xxx_sc) : NULL) {
        front_Scoping yyy_sc = List_front_Scoping_data(xxx_sc);
        PRINT_front_Scoping(yyy_sc);
        Print_Layout ("\n");
        Print_Layout ("\n");
      }
      set_margin (margin);
    }
    Print_Layout ("\n");
    PRINT_front_Symbol(front_Rhs_syms1 (me));
    if (front_Rhs_x (me) != NULL && front_Rhs_alts (me) != NULL && front_Rhs_ops (me) != NULL && front_Rhs_y (me) != NULL && front_Rhs_syms2 (me) != NULL) {
      Ident yyy_x = front_Rhs_x (me);
      List_front_Alternative yyy_alts = front_Rhs_alts (me);
      List_front_Or yyy_ops = front_Rhs_ops (me);
      Ident yyy_y = front_Rhs_y (me);
      front_Symbol yyy_syms2 = front_Rhs_syms2 (me);
      PRINT_Ident(yyy_x);
      { Int margin = fix_margin ();
        Bool __first = TRUE;
        List_front_Alternative xxx_yyy_alts = yyy_alts;
        List_front_Or xxx_yyy_ops = yyy_ops;
        for (; xxx_yyy_alts != NULL; xxx_yyy_alts = xxx_yyy_alts ? List_front_Alternative_next(xxx_yyy_alts) : NULL) {
          front_Alternative yyy_yyy_alts = List_front_Alternative_data(xxx_yyy_alts);
          if (!__first) {
            front_Or yyy_yyy_ops = List_front_Or_data(xxx_yyy_ops);
            PRINT_front_Or(yyy_yyy_ops);
            xxx_yyy_ops = xxx_yyy_ops ? List_front_Or_next(xxx_yyy_ops) : NULL;
          }
          __first = FALSE;
          PRINT_front_Alternative(yyy_yyy_alts);
        }
        set_margin (margin);
      }
      PRINT_Ident(yyy_y);
      Print_Layout ("\n");
      PRINT_front_Symbol(yyy_syms2);
    }
    if (front_Rhs_checklist (me) != NULL) {
      List_front_Check yyy_checklist = front_Rhs_checklist (me);
      Print_Keyword ("CHECKS");
      Print_Layout ("\n");
      { Int margin = fix_margin ();
        List_front_Check xxx_yyy_checklist = yyy_checklist;
        for (; xxx_yyy_checklist != NULL; xxx_yyy_checklist = xxx_yyy_checklist ? List_front_Check_next(xxx_yyy_checklist) : NULL) {
          front_Check yyy_yyy_checklist = List_front_Check_data(xxx_yyy_checklist);
          PRINT_front_Check(yyy_yyy_checklist);
        }
        set_margin (margin);
      }
    }
    print_comment(front_Rhs_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Rhs (front_Rhs me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Rhs(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Alternative (front_Alternative me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Alternative_loc(me) >= 0;
    advance_position (front_Alternative_loc(me));
    margin = fix_margin ();
    print_comment(front_Alternative_src_info(me)->pre_comment);
    switch (front_Alternative_tag(me)) {
      case front_LabeledAlt_kind:
        Print_Layout (" ");
        start_label (me);
        PRINT_Ident(front_LabeledAlt_id (me));
        end_label ();
        if (front_LabeledAlt_meemo (me)) {
          Print_Keyword ("MEMO");
        }
        if (front_LabeledAlt_skip (me)) {
          Print_Keyword ("SKIP");
        }
        Print_Layout (" ");
        PRINT_Ident(front_LabeledAlt_def (me));
        Print_Layout ("\n");
        Print_Layout ("\t");
        PRINT_front_Rhs(front_LabeledAlt_rhs (me));
        break;
      case front_UnLabeledAlt_kind:
        Print_Layout (" ");
        PRINT_front_Symbol(front_UnLabeledAlt_syms (me));
        Print_Layout ("\n");
        break;
    }
    print_comment(front_Alternative_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Alternative (front_Alternative me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Alternative(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Symbol (front_Symbol me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Symbol_loc(me) >= 0;
    advance_position (front_Symbol_loc(me));
    margin = fix_margin ();
    print_comment(front_Symbol_src_info(me)->pre_comment);
    switch (front_Symbol_tag(me)) {
      case front_LabeledSym_kind:
        PRINT_Ident(front_LabeledSym_id (me));
        Print_Layout (" ");
        Print_String (":");
        Print_Layout (" ");
        PRINT_front_Symbol(front_LabeledSym_sym (me));
        Print_Layout ("\n");
        Print_Layout ("\n");
        break;
      case front_AltSymbol_kind:
        PRINT_front_Symbol(front_AltSymbol_syms1 (me));
        Print_Layout (" ");
        PRINT_front_Alternator(front_AltSymbol_alt (me));
        Print_Layout (" ");
        { Int margin = fix_margin ();
          List_front_Symbol xxx_syms = front_AltSymbol_syms (me);
          for (; xxx_syms != NULL; xxx_syms = xxx_syms ? List_front_Symbol_next(xxx_syms) : NULL) {
            front_Symbol yyy_syms = List_front_Symbol_data(xxx_syms);
            PRINT_front_Symbol(yyy_syms);
          }
          set_margin (margin);
        }
        break;
      case front_SymbolSeq_kind:
        if (front_SymbolSeq_symbols (me) != NULL && front_SymbolSeq_my_fields (me) != NULL) {
          List_front_Symbol yyy_symbols = front_SymbolSeq_symbols (me);
          List_front_Field yyy_my_fields = front_SymbolSeq_my_fields (me);
          List_front_And yyy_ands = front_SymbolSeq_ands (me);
          { Int margin = fix_margin ();
            Bool __first = TRUE;
            List_front_Symbol xxx_yyy_symbols = yyy_symbols;
            List_front_Field xxx_yyy_my_fields = yyy_my_fields;
            List_front_And xxx_yyy_ands = yyy_ands;
            for (; xxx_yyy_symbols != NULL && xxx_yyy_my_fields != NULL; xxx_yyy_symbols = xxx_yyy_symbols ? List_front_Symbol_next(xxx_yyy_symbols) : NULL, xxx_yyy_my_fields = xxx_yyy_my_fields ? List_front_Field_next(xxx_yyy_my_fields) : NULL) {
              front_Symbol yyy_yyy_symbols = List_front_Symbol_data(xxx_yyy_symbols);
              front_Field yyy_yyy_my_fields = List_front_Field_data(xxx_yyy_my_fields);
              if (!__first) {
                front_And yyy_yyy_ands = List_front_And_data(xxx_yyy_ands);
                PRINT_front_And(yyy_yyy_ands);
                xxx_yyy_ands = xxx_yyy_ands ? List_front_And_next(xxx_yyy_ands) : NULL;
              }
              __first = FALSE;
              if (yyy_yyy_symbols != NULL) {
                front_Symbol yyy_yyy_yyy_symbols = yyy_yyy_symbols;
                PRINT_front_Symbol(yyy_yyy_yyy_symbols);
              }
              if (yyy_yyy_my_fields != NULL) {
                front_Field yyy_yyy_yyy_my_fields = yyy_yyy_my_fields;
                PRINT_front_Field(yyy_yyy_yyy_my_fields);
              }
            }
            set_margin (margin);
          }
        }
        break;
      case front_CompareSym_kind:
        PRINT_front_Symbol(front_Symbol2_sym (me));
        Print_Layout (" ");
        Print_Keyword ("COMPARE");
        Print_Layout (" ");
        PRINT_Ident(front_Symbol2_comp (me));
        break;
      case front_AppliedSym_kind:
        Print_Keyword ("APPLIED");
        Print_Layout (" ");
        PRINT_Ident(front_AppliedSym_nt_id (me));
        Print_Layout (" ");
        PRINT_front_NameOrField(front_AppliedSym_field (me));
        Print_Layout (" ");
        PRINT_Ident(front_AppliedSym_name (me));
        if (front_AppliedSym_sc (me) != NULL) {
          front_Expr yyy_sc = front_AppliedSym_sc (me);
          Print_Layout (" ");
          Print_Keyword ("SCOPE");
          Print_Layout (" ");
          PRINT_front_Expr(yyy_sc);
        }
        if (front_AppliedSym_warn (me)) {
          Print_Layout (" ");
          Print_Keyword ("WARNING");
        }
        Print_Layout (" ");
        break;
      case front_StringSymbol_kind:
        PRINT_String(front_StringSymbol_string (me));
        Print_Layout (" ");
        if (front_StringSymbol_n (me) != NULL) {
          Ident yyy_n = front_StringSymbol_n (me);
          Print_Keyword ("NAME");
          Print_Layout (" ");
          PRINT_Ident(yyy_n);
        }
        if (front_StringSymbol_type (me) != NULL) {
          front_Type yyy_type = front_StringSymbol_type (me);
          Print_Layout (" ");
          Print_Keyword ("TYPE");
          Print_Layout (" ");
          PRINT_front_Type(yyy_type);
        }
        Print_Layout (" ");
        break;
      case front_CharSymbol_kind:
        PRINT_String(front_CharSymbol_chr (me));
        if (front_CharSymbol_type (me) != NULL) {
          front_Type yyy_type = front_CharSymbol_type (me);
          Print_Layout (" ");
          Print_Keyword ("TYPE");
          Print_Layout (" ");
          PRINT_front_Type(yyy_type);
        }
        Print_Layout (" ");
        break;
      case front_KeywordSymbol_kind:
        PRINT_String(front_KeywordSymbol_keyword (me));
        if (front_KeywordSymbol_type (me) != NULL) {
          front_Type yyy_type = front_KeywordSymbol_type (me);
          Print_Layout (" ");
          Print_Keyword ("TYPE");
          Print_Layout (" ");
          PRINT_front_Type(yyy_type);
        }
        Print_Layout (" ");
        break;
      case front_OnceSymbol_kind:
        Print_String ("((");
        Print_Layout (" ");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_front_Symbol xxx_sym = front_CompoundSym_sym (me);
          List_front_Or xxx_ops = front_CompoundSym_ops (me);
          for (; xxx_sym != NULL; xxx_sym = xxx_sym ? List_front_Symbol_next(xxx_sym) : NULL) {
            front_Symbol yyy_sym = List_front_Symbol_data(xxx_sym);
            if (!__first) {
              front_Or yyy_ops = List_front_Or_data(xxx_ops);
              PRINT_front_Or(yyy_ops);
              Print_Layout (" ");
              xxx_ops = xxx_ops ? List_front_Or_next(xxx_ops) : NULL;
            }
            __first = FALSE;
            PRINT_front_Symbol(yyy_sym);
          }
          set_margin (margin);
        }
        Print_String (")");
        Print_String (")");
        Print_Layout (" ");
        break;
      case front_OptSymbol_kind:
        Print_String ("[");
        Print_Layout (" ");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_front_Symbol xxx_sym = front_CompoundSym_sym (me);
          List_front_Or xxx_ops = front_CompoundSym_ops (me);
          for (; xxx_sym != NULL; xxx_sym = xxx_sym ? List_front_Symbol_next(xxx_sym) : NULL) {
            front_Symbol yyy_sym = List_front_Symbol_data(xxx_sym);
            if (!__first) {
              front_Or yyy_ops = List_front_Or_data(xxx_ops);
              PRINT_front_Or(yyy_ops);
              Print_Layout (" ");
              xxx_ops = xxx_ops ? List_front_Or_next(xxx_ops) : NULL;
            }
            __first = FALSE;
            PRINT_front_Symbol(yyy_sym);
          }
          set_margin (margin);
        }
        Print_String ("]");
        if (front_OptSymbol_in_line (me)) {
          Print_String ("!");
        }
        Print_Layout (" ");
        break;
      case front_OptMoreSymbol_kind:
        Print_String ("{");
        Print_Layout (" ");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_front_Symbol xxx_sym = front_CompoundSym_sym (me);
          List_front_Or xxx_ops = front_CompoundSym_ops (me);
          for (; xxx_sym != NULL; xxx_sym = xxx_sym ? List_front_Symbol_next(xxx_sym) : NULL) {
            front_Symbol yyy_sym = List_front_Symbol_data(xxx_sym);
            if (!__first) {
              front_Or yyy_ops = List_front_Or_data(xxx_ops);
              PRINT_front_Or(yyy_ops);
              Print_Layout (" ");
              xxx_ops = xxx_ops ? List_front_Or_next(xxx_ops) : NULL;
            }
            __first = FALSE;
            PRINT_front_Symbol(yyy_sym);
          }
          set_margin (margin);
        }
        Print_String ("}");
        Print_Layout (" ");
        break;
      case front_MoreSymbol_kind:
        Print_String ("{");
        Print_Layout (" ");
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_front_Symbol xxx_sym = front_CompoundSym_sym (me);
          List_front_Or xxx_ops = front_CompoundSym_ops (me);
          for (; xxx_sym != NULL; xxx_sym = xxx_sym ? List_front_Symbol_next(xxx_sym) : NULL) {
            front_Symbol yyy_sym = List_front_Symbol_data(xxx_sym);
            if (!__first) {
              front_Or yyy_ops = List_front_Or_data(xxx_ops);
              PRINT_front_Or(yyy_ops);
              Print_Layout (" ");
              xxx_ops = xxx_ops ? List_front_Or_next(xxx_ops) : NULL;
            }
            __first = FALSE;
            PRINT_front_Symbol(yyy_sym);
          }
          set_margin (margin);
        }
        Print_String ("}");
        PRINT_Ident(front_MoreSymbol_more (me));
        Print_Layout (" ");
        break;
      case front_EmptySym_kind:
        Print_Keyword ("EMPTY");
        Print_Layout (" ");
        break;
      case front_LayoutString_kind:
        Print_String ("\\");
        PRINT_String(front_LayoutString_layout (me));
        Print_Layout (" ");
        break;
      case front_LayoutAction_kind:
        Print_Keyword ("LAYOUT");
        Print_Layout (" ");
        PRINT_front_Expr(front_LayoutAction_layout (me));
        Print_Layout (" ");
        break;
      case front_IdSym_kind:
        PRINT_Ident(front_IdSym_id (me));
        if (front_IdSym_type (me) != NULL) {
          front_Type yyy_type = front_IdSym_type (me);
          Print_Layout (" ");
          Print_Keyword ("TYPE");
          Print_Layout (" ");
          PRINT_front_Type(yyy_type);
        }
        Print_Layout (" ");
        break;
      case front_DefiningSym_kind:
        if (front_DefiningSym_forward (me)) {
          Print_Keyword ("FORWARD");
        }
        Print_Layout (" ");
        PRINT_front_Define(front_DefiningSym_def (me));
        Print_Layout (" ");
        PRINT_front_Defining_id(front_DefiningSym_id (me));
        if (front_DefiningSym_ns_id (me) != NULL) {
          Ident yyy_ns_id = front_DefiningSym_ns_id (me);
          Print_Keyword ("NAMESPACE");
          Print_Layout (" ");
          if (front_DefiningSym_ns (me) != NULL)
          { start_href (front_NameSpace_loc(front_DefiningSym_ns (me)), front_DefiningSym_ns (me)); }
          PRINT_Ident(yyy_ns_id);
          if (front_DefiningSym_ns (me) != NULL)
          { end_href (); }
        }
        if (front_DefiningSym_sc (me) != NULL) {
          front_Expr yyy_sc = front_DefiningSym_sc (me);
          Print_Keyword ("SCOPE");
          Print_Layout (" ");
          PRINT_front_Expr(yyy_sc);
        }
        break;
    }
    print_comment(front_Symbol_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Symbol (front_Symbol me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Symbol(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Defining_id (front_Defining_id me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Defining_id_loc(me) >= 0;
    advance_position (front_Defining_id_loc(me));
    margin = fix_margin ();
    print_comment(front_Defining_id_src_info(me)->pre_comment);
    switch (front_Defining_id_tag(me)) {
      case front_DefId_kind:
        PRINT_front_Symbol(front_DefId_id (me));
        break;
      case front_DefExpr_kind:
        Print_String ("(");
        PRINT_front_Expr(front_DefExpr_e (me));
        Print_String (")");
        break;
    }
    print_comment(front_Defining_id_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Defining_id (front_Defining_id me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Defining_id(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Field (front_Field me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Field_loc(me) >= 0;
    advance_position (front_Field_loc(me));
    margin = fix_margin ();
    print_comment(front_Field_src_info(me)->pre_comment);
    PRINT_Ident(front_Field_id (me));
    Print_Layout (" ");
    Print_String (":");
    Print_Layout (" ");
    PRINT_front_Type(front_Field_type (me));
    Print_Layout (" ");
    PRINT_Ident(front_Field_assign (me));
    Print_Layout (" ");
    { Int margin = fix_margin ();
      Bool __first = TRUE;
      List_front_FieldInit xxx_when = front_Field_when (me);
      for (; xxx_when != NULL; xxx_when = xxx_when ? List_front_FieldInit_next(xxx_when) : NULL) {
        front_FieldInit yyy_when = List_front_FieldInit_data(xxx_when);
        if (!__first) {
          Print_String (",");
;
        }
        __first = FALSE;
        PRINT_front_FieldInit(yyy_when);
      }
      set_margin (margin);
    }
    if (front_Field_traverse (me)) {
      Print_Layout (" ");
      Print_Keyword ("TRAVERSE");
    }
    if (front_Field_clear (me)) {
      Print_Layout (" ");
      Print_Keyword ("CLEAR");
    }
    if (front_Field_dont_clear (me)) {
      Print_Layout (" ");
      Print_Keyword ("DONT_CLEAR");
    }
    Print_Layout ("\n");
    print_comment(front_Field_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Field (front_Field me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Field(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_FieldInit (front_FieldInit me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_FieldInit_loc(me) >= 0;
    advance_position (front_FieldInit_loc(me));
    margin = fix_margin ();
    print_comment(front_FieldInit_src_info(me)->pre_comment);
    switch (front_FieldInit_tag(me)) {
      case front_WhenCreate_kind:
        if (front_WhenCreate_c (me)) {
          Print_Keyword ("CREATE");
        }
        Print_Layout (" ");
        PRINT_front_Expr(front_FieldInit_expr (me));
        break;
      case front_WhenScope_kind:
        Print_Keyword ("SCOPE");
        Print_Layout (" ");
        PRINT_front_Expr(front_FieldInit_expr (me));
        break;
      case front_WhenDefining_kind:
        Print_Keyword ("DEFINING");
        Print_Layout (" ");
        PRINT_front_Expr(front_FieldInit_expr (me));
        break;
      case front_WhenApplied_kind:
        Print_Keyword ("APPLIED");
        Print_Layout (" ");
        PRINT_front_Expr(front_FieldInit_expr (me));
        break;
      case front_WhenChecks_kind:
        Print_Keyword ("CHECKS");
        Print_Layout (" ");
        PRINT_front_Expr(front_FieldInit_expr (me));
        break;
    }
    print_comment(front_FieldInit_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_FieldInit (front_FieldInit me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_FieldInit(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Type (front_Type me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Type_loc(me) >= 0;
    advance_position (front_Type_loc(me));
    margin = fix_margin ();
    print_comment(front_Type_src_info(me)->pre_comment);
    PRINT_Ident(front_Type_id (me));
    if (front_Type_args (me) != NULL) {
      List_front_Type yyy_args = front_Type_args (me);
      Print_String ("(");
      { Int margin = fix_margin ();
        Bool __first = TRUE;
        List_front_Type xxx_yyy_args = yyy_args;
        for (; xxx_yyy_args != NULL; xxx_yyy_args = xxx_yyy_args ? List_front_Type_next(xxx_yyy_args) : NULL) {
          front_Type yyy_yyy_args = List_front_Type_data(xxx_yyy_args);
          if (!__first) {
            Print_String (",");
            Print_Layout (" ");
;
          }
          __first = FALSE;
          PRINT_front_Type(yyy_yyy_args);
        }
        set_margin (margin);
      }
      Print_String (")");
    }
    print_comment(front_Type_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Type (front_Type me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Type(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Expr (front_Expr me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Expr_loc(me) >= 0;
    advance_position (front_Expr_loc(me));
    margin = fix_margin ();
    print_comment(front_Expr_src_info(me)->pre_comment);
    switch (front_Expr_tag(me)) {
      case front_BinExpr_kind:
        { Int margin = fix_margin ();
          Bool __first = TRUE;
          List_front_Expr xxx_args = front_BinExpr_args (me);
          List_Ident xxx_ops = front_BinExpr_ops (me);
          for (; xxx_args != NULL; xxx_args = xxx_args ? List_front_Expr_next(xxx_args) : NULL) {
            front_Expr yyy_args = List_front_Expr_data(xxx_args);
            if (!__first) {
              Ident yyy_ops = List_Ident_data(xxx_ops);
              Print_Layout (" ");
              PRINT_Ident(yyy_ops);
              Print_Layout (" ");
              xxx_ops = xxx_ops ? List_Ident_next(xxx_ops) : NULL;
            }
            __first = FALSE;
            PRINT_front_Expr(yyy_args);
          }
          set_margin (margin);
        }
        break;
      case front_MonExpr_kind:
        { Int margin = fix_margin ();
          List_Ident xxx_ops = front_MonExpr1_ops (me);
          for (; xxx_ops != NULL; xxx_ops = xxx_ops ? List_Ident_next(xxx_ops) : NULL) {
            Ident yyy_ops = List_Ident_data(xxx_ops);
            PRINT_Ident(yyy_ops);
            Print_Layout (" ");
          }
          set_margin (margin);
        }
        PRINT_front_Expr(front_MonExpr1_arg (me));
        break;
      case front_IdentExpr_kind:
        PRINT_Ident(front_IdentExpr_id (me));
        break;
      case front_QualExpr_kind:
        PRINT_front_Expr(front_QualExpr_prefix (me));
        Print_String (".");
        PRINT_Ident(front_QualExpr_id (me));
        break;
      case front_IntExpr_kind:
        PRINT_Int(front_IntExpr_i (me));
        break;
      case front_BoolExpr_kind:
        PRINT_Bool(front_BoolExpr_b (me));
        break;
      case front_StringExpr_kind:
        PRINT_String(front_StringExpr_string (me));
        break;
      case front_NilExpr_kind:
        Print_Keyword ("NULL");
        break;
      case front_CallExpr_kind:
        PRINT_front_Expr(front_CallExpr_func (me));
        Print_Layout (" ");
        Print_String ("(");
        if (front_CallExpr_args (me) != NULL) {
          List_front_Expr yyy_args = front_CallExpr_args (me);
          { Int margin = fix_margin ();
            Bool __first = TRUE;
            List_front_Expr xxx_yyy_args = yyy_args;
            for (; xxx_yyy_args != NULL; xxx_yyy_args = xxx_yyy_args ? List_front_Expr_next(xxx_yyy_args) : NULL) {
              front_Expr yyy_yyy_args = List_front_Expr_data(xxx_yyy_args);
              if (!__first) {
                Print_String (",");
                Print_Layout (" ");
;
              }
              __first = FALSE;
              PRINT_front_Expr(yyy_yyy_args);
            }
            set_margin (margin);
          }
        }
        Print_String (")");
        break;
    }
    print_comment(front_Expr_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Expr (front_Expr me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Expr(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Check (front_Check me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Check_loc(me) >= 0;
    advance_position (front_Check_loc(me));
    margin = fix_margin ();
    print_comment(front_Check_src_info(me)->pre_comment);
    Print_Layout (" ");
    Print_Layout (" ");
    Print_Keyword ("IF");
    Print_Layout (" ");
    PRINT_front_Expr(front_Check_cond (me));
    Print_Layout (" ");
    Print_Keyword ("THEN");
    if (front_Check_warn (me)) {
      Print_Layout (" ");
      Print_Keyword ("WARNING");
    }
    { Int margin = fix_margin ();
      List_front_Expr xxx_message = front_Check_message (me);
      for (; xxx_message != NULL; xxx_message = xxx_message ? List_front_Expr_next(xxx_message) : NULL) {
        front_Expr yyy_message = List_front_Expr_data(xxx_message);
        Print_Layout (" ");
        PRINT_front_Expr(yyy_message);
      }
      set_margin (margin);
    }
    Print_Layout ("\n");
    print_comment(front_Check_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Check (front_Check me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Check(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_ScanInfo (front_ScanInfo me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_ScanInfo_loc(me) >= 0;
    advance_position (front_ScanInfo_loc(me));
    margin = fix_margin ();
    print_comment(front_ScanInfo_src_info(me)->pre_comment);
    Print_Keyword ("SCAN");
    if (front_ScanInfo_type (me) != NULL) {
      front_Type yyy_type = front_ScanInfo_type (me);
      Print_Layout (" ");
      Print_Keyword ("TYPE");
      Print_Layout (" ");
      PRINT_front_Type(yyy_type);
    }
    if (front_ScanInfo_comment (me)) {
      Print_Layout (" ");
      Print_Keyword ("COMMENT");
    }
    Print_Layout ("\n");
    print_comment(front_ScanInfo_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_ScanInfo (front_ScanInfo me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_ScanInfo(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Defines (front_Defines me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_Defines_loc(me) >= 0;
    advance_position (front_Defines_loc(me));
    margin = fix_margin ();
    print_comment(front_Defines_src_info(me)->pre_comment);
    switch (front_Defines_tag(me)) {
      case front_PlainDef_kind:
        PRINT_Ident(front_Defines_id (me));
        break;
      case front_MacroDef_kind:
        PRINT_Ident(front_Defines_id (me));
        break;
    }
    print_comment(front_Defines_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Defines (front_Defines me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Defines(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_NameSpace (front_NameSpace me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_NameSpace_loc(me) >= 0;
    advance_position (front_NameSpace_loc(me));
    margin = fix_margin ();
    print_comment(front_NameSpace_src_info(me)->pre_comment);
    start_label (me);
    PRINT_Ident(front_NameSpace_id (me));
    end_label ();
    print_comment(front_NameSpace_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_NameSpace (front_NameSpace me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_NameSpace(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_dummy (front_dummy me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = front_dummy_loc(me) >= 0;
    advance_position (front_dummy_loc(me));
    margin = fix_margin ();
    print_comment(front_dummy_src_info(me)->pre_comment);
    print_comment(front_dummy_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_dummy (front_dummy me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_dummy(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Scope (front_Scope me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    switch (front_Scope_tag(me)) {
      case front_NonTerminalScope_kind:
        break;
    }
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_front_Scope (front_Scope me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Scope(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_List_front_Symbol (List_List_front_Symbol me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_List_front_Symbol (List_List_front_Symbol_data(me));
    PRINT_List_List_front_Symbol (List_List_front_Symbol_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_List_front_Symbol (List_List_front_Symbol me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_List_front_Symbol(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_Expr (List_front_Expr me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_Expr (List_front_Expr_data(me));
    PRINT_List_front_Expr (List_front_Expr_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_Expr (List_front_Expr me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_Expr(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_Type (List_front_Type me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_Type (List_front_Type_data(me));
    PRINT_List_front_Type (List_front_Type_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_Type (List_front_Type me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_Type(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_FieldInit (List_front_FieldInit me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_FieldInit (List_front_FieldInit_data(me));
    PRINT_List_front_FieldInit (List_front_FieldInit_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_FieldInit (List_front_FieldInit me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_FieldInit(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_And (List_front_And me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_And (List_front_And_data(me));
    PRINT_List_front_And (List_front_And_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_And (List_front_And me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_And(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_Field (List_front_Field me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_Field (List_front_Field_data(me));
    PRINT_List_front_Field (List_front_Field_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_Field (List_front_Field me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_Field(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_Symbol (List_front_Symbol me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_Symbol (List_front_Symbol_data(me));
    PRINT_List_front_Symbol (List_front_Symbol_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_Symbol (List_front_Symbol me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_Symbol(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_Check (List_front_Check me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_Check (List_front_Check_data(me));
    PRINT_List_front_Check (List_front_Check_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_Check (List_front_Check me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_Check(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_Or (List_front_Or me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_Or (List_front_Or_data(me));
    PRINT_List_front_Or (List_front_Or_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_Or (List_front_Or me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_Or(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_Alternative (List_front_Alternative me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_Alternative (List_front_Alternative_data(me));
    PRINT_List_front_Alternative (List_front_Alternative_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_Alternative (List_front_Alternative me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_Alternative(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_Scoping (List_front_Scoping me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_Scoping (List_front_Scoping_data(me));
    PRINT_List_front_Scoping (List_front_Scoping_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_Scoping (List_front_Scoping me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_Scoping(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_ImportedNonTerminal (List_front_ImportedNonTerminal_data(me));
    PRINT_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_ImportedNonTerminal (List_front_ImportedNonTerminal me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_ImportedNonTerminal(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_NonTerminal (List_front_NonTerminal me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_NonTerminal (List_front_NonTerminal_data(me));
    PRINT_List_front_NonTerminal (List_front_NonTerminal_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_NonTerminal (List_front_NonTerminal me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_NonTerminal(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_Import (List_front_Import me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_Import (List_front_Import_data(me));
    PRINT_List_front_Import (List_front_Import_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_Import (List_front_Import me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_Import(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_front_NameSpace (List_front_NameSpace me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_front_NameSpace (List_front_NameSpace_data(me));
    PRINT_List_front_NameSpace (List_front_NameSpace_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_front_NameSpace (List_front_NameSpace me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_front_NameSpace(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Scoping (front_Scoping me)
{ switch (me) {
    case front_NewScope:
      Print_Keyword ("SCOPE");
      break;
    case front_OpenScope:
      Print_Keyword ("OPENSCOPE");
      break;
    case front_CloseScope:
      Print_Keyword ("CLOSESCOPE");
      break;
  }
}

char *Text_front_Scoping (front_Scoping me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Scoping(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_And (front_And me)
{ switch (me) {
    case front_AndTranspose:
      Print_String ("\\ ");
      break;
    case front_AndLeft:
      Print_String ("\\<");
      break;
    case front_AndRight:
      Print_String ("\\>");
      break;
    case front_AndCenter:
      break;
  }
}

char *Text_front_And (front_And me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_And(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Or (front_Or me)
{ switch (me) {
    case front_OrCenter:
      Print_String ("|");
      break;
    case front_OrLeft:
      Print_String ("|<");
      break;
    case front_OrRight:
      Print_String ("|>");
      break;
    case front_OrTranspose:
      Print_String ("\\|");
      break;
  }
}

char *Text_front_Or (front_Or me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Or(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Define (front_Define me)
{ switch (me) {
    case front_Defining:
      Print_Keyword ("DEFINING");
      Print_Layout ("\n");
      break;
    case front_Redefining:
      Print_Keyword ("REDEFINING");
      Print_Layout ("\n");
      break;
    case front_Overloading:
      Print_Keyword ("OVERLOADING");
      Print_Layout ("\n");
      break;
  }
}

char *Text_front_Define (front_Define me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Define(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_Alternator (front_Alternator me)
{ switch (me) {
    case 0:
      Print_String ("\\\\");
      break;
    case 1:
      Print_String ("//");
      break;
  }
}

char *Text_front_Alternator (front_Alternator me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_Alternator(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_front_NameOrField (front_NameOrField me)
{ switch (me) {
    case front_AppliedName:
      Print_Keyword ("NAME");
      break;
    case front_AppliedField:
      Print_Keyword ("FIELD");
      break;
  }
}

char *Text_front_NameOrField (front_NameOrField me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_front_NameOrField(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

