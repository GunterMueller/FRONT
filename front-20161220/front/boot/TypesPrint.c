#include "TypesPrint.h"
#include <front/text.h>

#include <front/print_support.h>

void Print_Types_Types (Types_Types me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_Types_loc(me) >= 0;
    advance_position (Types_Types_loc(me));
    margin = fix_margin ();
    print_comment(Types_Types_src_info(me)->pre_comment);
    Print_String ("#include <stdarg.h>");
    Print_Layout ("\n");
    Print_String ("#include <stddef.h>");
    Print_Layout ("\n");
    Print_String ("#include <front/basic_types.h>");
    Print_Layout ("\n");
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_Types_EnumType xxx_enums = Types_Types_enums (me);
      for (; xxx_enums != NULL; xxx_enums = xxx_enums ? List_Types_EnumType_next(xxx_enums) : NULL) {
        Types_EnumType yyy_enums = List_Types_EnumType_data(xxx_enums);
        PRINT_Types_EnumType(yyy_enums);
      }
      set_margin (margin);
    }
    { Int margin = fix_margin ();
      List_Types_PointerType xxx_pointers = Types_Types_pointers (me);
      for (; xxx_pointers != NULL; xxx_pointers = xxx_pointers ? List_Types_PointerType_next(xxx_pointers) : NULL) {
        Types_PointerType yyy_pointers = List_Types_PointerType_data(xxx_pointers);
        PRINT_Types_PointerType(yyy_pointers);
      }
      set_margin (margin);
    }
    { Int margin = fix_margin ();
      List_Types_subtypedef xxx_subs = Types_Types_subs (me);
      for (; xxx_subs != NULL; xxx_subs = xxx_subs ? List_Types_subtypedef_next(xxx_subs) : NULL) {
        Types_subtypedef yyy_subs = List_Types_subtypedef_data(xxx_subs);
        PRINT_Types_subtypedef(yyy_subs);
      }
      set_margin (margin);
    }
    PRINT_Types_includes2(Types_Types_inc2 (me));
    { Int margin = fix_margin ();
      List_Types_subtypedef xxx_impdefs = Types_Types_impdefs (me);
      for (; xxx_impdefs != NULL; xxx_impdefs = xxx_impdefs ? List_Types_subtypedef_next(xxx_impdefs) : NULL) {
        Types_subtypedef yyy_impdefs = List_Types_subtypedef_data(xxx_impdefs);
        PRINT_Types_subtypedef(yyy_impdefs);
      }
      set_margin (margin);
    }
    { Int margin = fix_margin ();
      List_Types_BindType xxx_binds = Types_Types_binds (me);
      for (; xxx_binds != NULL; xxx_binds = xxx_binds ? List_Types_BindType_next(xxx_binds) : NULL) {
        Types_BindType yyy_binds = List_Types_BindType_data(xxx_binds);
        PRINT_Types_BindType(yyy_binds);
      }
      set_margin (margin);
    }
    Print_Keyword ("extern");
    Print_Layout (" ");
    PRINT_Ident(Types_Types_r1 (me));
    Print_Layout (" ");
    PRINT_Ident(Types_Types_r2 (me));
    Print_String ("_root;");
    Print_Layout ("\n");
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_Types_StructType xxx_types = Types_Types_types (me);
      for (; xxx_types != NULL; xxx_types = xxx_types ? List_Types_StructType_next(xxx_types) : NULL) {
        Types_StructType yyy_types = List_Types_StructType_data(xxx_types);
        PRINT_Types_StructType(yyy_types);
      }
      set_margin (margin);
    }
    print_comment(Types_Types_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_Types (Types_Types me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_Types(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_includes2 (Types_includes2 me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_includes2_loc(me) >= 0;
    advance_position (Types_includes2_loc(me));
    margin = fix_margin ();
    print_comment(Types_includes2_src_info(me)->pre_comment);
    Print_String ("#include <front/scan_support.h>");
    Print_Layout ("\n");
    Print_String ("#include <front/print_support.h>");
    Print_Layout ("\n");
    Print_String ("#include <front/SymTab.h>");
    Print_Layout ("\n");
    if (Types_includes2_id1 (me) != NULL) {
      Ident yyy_id1 = Types_includes2_id1 (me);
      Print_String ("#include \"");
      PRINT_Ident(yyy_id1);
      Print_String ("_parse.h\"");
      Print_Layout ("\n");
    }
    Print_String ("#include \"");
    PRINT_Ident(Types_includes2_id2 (me));
    Print_String ("_defs.h\"");
    Print_Layout ("\n");
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_Ident xxx_uses = Types_includes2_uses (me);
      for (; xxx_uses != NULL; xxx_uses = xxx_uses ? List_Ident_next(xxx_uses) : NULL) {
        Ident yyy_uses = List_Ident_data(xxx_uses);
        Print_String ("#include \"");
        PRINT_Ident(yyy_uses);
        Print_String (".h\"");
        Print_Layout ("\n");
      }
      set_margin (margin);
    }
    print_comment(Types_includes2_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_includes2 (Types_includes2 me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_includes2(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_EnumType (Types_EnumType me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_EnumType_loc(me) >= 0;
    advance_position (Types_EnumType_loc(me));
    margin = fix_margin ();
    print_comment(Types_EnumType_src_info(me)->pre_comment);
    Print_Keyword ("typedef");
    Print_Layout (" ");
    Print_Keyword ("enum");
    Print_Layout (" ");
    Print_String ("{");
    Print_Layout ("\n");
    Print_Layout (" ");
    Print_Layout (" ");
    { Int margin = fix_margin ();
      Bool __first = TRUE;
      List_Types_TypeName xxx_enums = Types_EnumType_enums (me);
      for (; xxx_enums != NULL; xxx_enums = xxx_enums ? List_Types_TypeName_next(xxx_enums) : NULL) {
        Types_TypeName yyy_enums = List_Types_TypeName_data(xxx_enums);
        if (!__first) {
          Print_String (",");
          Print_Layout ("\n");
;
        }
        __first = FALSE;
        PRINT_Types_TypeName(yyy_enums);
      }
      set_margin (margin);
    }
    Print_Layout ("\n");
    Print_String ("}");
    Print_Layout (" ");
    PRINT_Ident(Types_EnumType_id (me));
    Print_String (";");
    Print_Layout ("\n");
    Print_String ("extern char *");
    PRINT_Ident(Types_EnumType_str (me));
    Print_String ("_names[];");
    Print_Layout ("\n");
    Print_String ("#define NUM_");
    PRINT_Ident(Types_EnumType_tag (me));
    Print_Layout (" ");
    PRINT_Int(Types_EnumType_num (me));
    Print_Layout ("\n");
    Print_Layout ("\n");
    print_comment(Types_EnumType_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_EnumType (Types_EnumType me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_EnumType(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_BindType (Types_BindType me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_BindType_loc(me) >= 0;
    advance_position (Types_BindType_loc(me));
    margin = fix_margin ();
    print_comment(Types_BindType_src_info(me)->pre_comment);
    Print_String ("typedef Bind Bind_");
    PRINT_Ident(Types_BindType_id1 (me));
    Print_String (";");
    Print_Layout ("\n");
    Print_String ("typedef List_Bind List_Bind_");
    PRINT_Ident(Types_BindType_id2 (me));
    Print_String (";");
    Print_Layout ("\n");
    Print_String ("#define List_Bind_");
    PRINT_Ident(Types_BindType_id3 (me));
    Print_String ("_data(x)");
    Print_Layout (" ");
    Print_String ("(Bind_");
    PRINT_Ident(Types_BindType_id4 (me));
    Print_String (")Front_List_data((Front_List)(x))");
    Print_Layout ("\n");
    Print_String ("#define List_Bind_");
    PRINT_Ident(Types_BindType_id5 (me));
    Print_String ("_next(x)");
    Print_Layout (" ");
    Print_String ("(List_Bind_");
    PRINT_Ident(Types_BindType_id6 (me));
    Print_String (")Front_List_next((Front_List)(x))");
    Print_Layout ("\n");
    Print_String ("#define Bind_");
    PRINT_Ident(Types_BindType_id7 (me));
    Print_Keyword ("_kind");
    Print_Layout (" ");
    PRINT_Int(Types_BindType_num (me));
    Print_Layout ("\n");
    Print_Layout ("\n");
    print_comment(Types_BindType_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_BindType (Types_BindType me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_BindType(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_PointerType (Types_PointerType me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_PointerType_loc(me) >= 0;
    advance_position (Types_PointerType_loc(me));
    margin = fix_margin ();
    print_comment(Types_PointerType_src_info(me)->pre_comment);
    Print_String ("#ifndef DEF_TYPE_");
    PRINT_Ident(Types_PointerType_id1 (me));
    Print_Layout ("\n");
    Print_String ("#define DEF_TYPE_");
    PRINT_Ident(Types_PointerType_id2 (me));
    Print_Layout ("\n");
    Print_String ("typedef struct s_");
    PRINT_Ident(Types_PointerType_id3 (me));
    Print_Layout ("\t");
    Print_String ("*");
    PRINT_Ident(Types_PointerType_id (me));
    Print_String (";");
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_Types_subtypedef xxx_subs = Types_PointerType_subs (me);
      for (; xxx_subs != NULL; xxx_subs = xxx_subs ? List_Types_subtypedef_next(xxx_subs) : NULL) {
        Types_subtypedef yyy_subs = List_Types_subtypedef_data(xxx_subs);
        PRINT_Types_subtypedef(yyy_subs);
      }
      set_margin (margin);
    }
    Print_String ("#endif");
    Print_Layout ("\n");
    Print_Layout ("\n");
    print_comment(Types_PointerType_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_PointerType (Types_PointerType me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_PointerType(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_subtypedef (Types_subtypedef me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_subtypedef_loc(me) >= 0;
    advance_position (Types_subtypedef_loc(me));
    margin = fix_margin ();
    print_comment(Types_subtypedef_src_info(me)->pre_comment);
    Print_String ("typedef ");
    PRINT_Ident(Types_subtypedef_super (me));
    Print_Layout (" ");
    PRINT_Ident(Types_subtypedef_id (me));
    Print_String (";");
    Print_Layout ("\n");
    print_comment(Types_subtypedef_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_subtypedef (Types_subtypedef me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_subtypedef(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_StructType (Types_StructType me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_StructType_loc(me) >= 0;
    advance_position (Types_StructType_loc(me));
    margin = fix_margin ();
    print_comment(Types_StructType_src_info(me)->pre_comment);
    Print_String ("#ifndef DEF_STRUCT_");
    PRINT_Ident(Types_StructType_id1 (me));
    Print_Layout ("\n");
    Print_String ("#define DEF_STRUCT_");
    PRINT_Ident(Types_StructType_id2 (me));
    Print_Layout ("\n");
    Print_Layout ("\n");
    PRINT_Types_struct_type(Types_StructType_type (me));
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_Types_macro xxx_macros = Types_StructType_macros (me);
      for (; xxx_macros != NULL; xxx_macros = xxx_macros ? List_Types_macro_next(xxx_macros) : NULL) {
        Types_macro yyy_macros = List_Types_macro_data(xxx_macros);
        PRINT_Types_macro(yyy_macros);
      }
      set_margin (margin);
    }
    Print_Layout ("\n");
    { Int margin = fix_margin ();
      List_Types_CreateFunction xxx_creates = Types_StructType_creates (me);
      for (; xxx_creates != NULL; xxx_creates = xxx_creates ? List_Types_CreateFunction_next(xxx_creates) : NULL) {
        Types_CreateFunction yyy_creates = List_Types_CreateFunction_data(xxx_creates);
        PRINT_Types_CreateFunction(yyy_creates);
      }
      set_margin (margin);
    }
    Print_Layout ("\n");
    Print_String ("#endif /* DEF_STRUCT_");
    PRINT_Ident(Types_StructType_id3 (me));
    Print_String (" */");
    Print_Layout ("\n");
    Print_Layout ("\n");
    print_comment(Types_StructType_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_StructType (Types_StructType me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_StructType(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_struct_type (Types_struct_type me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_struct_type_loc(me) >= 0;
    advance_position (Types_struct_type_loc(me));
    margin = fix_margin ();
    print_comment(Types_struct_type_src_info(me)->pre_comment);
    Print_Keyword ("struct");
    Print_Layout (" ");
    Print_Keyword ("s_");
    start_label (me);
    PRINT_Ident(Types_struct_type_tag (me));
    end_label ();
    Print_Layout (" ");
    Print_String ("{");
    Print_Layout ("\n");
    if (Types_struct_type_user (me) != NULL) {
      Ident yyy_user = Types_struct_type_user (me);
      Print_Layout (" ");
      Print_Layout (" ");
      PRINT_Ident(yyy_user);
      Print_Keyword ("_USER_FIELDS");
      Print_Layout ("\n");
    }
    { Int margin = fix_margin ();
      List_Types_field xxx_fields1 = Types_struct_type_fields1 (me);
      for (; xxx_fields1 != NULL; xxx_fields1 = xxx_fields1 ? List_Types_field_next(xxx_fields1) : NULL) {
        Types_field yyy_fields1 = List_Types_field_data(xxx_fields1);
        Print_Layout (" ");
        Print_Layout (" ");
        PRINT_Types_field(yyy_fields1);
        Print_Layout ("\n");
      }
      set_margin (margin);
    }
    if (Types_struct_type_sub_types (me) != NULL) {
      List_Types_struct_type yyy_sub_types = Types_struct_type_sub_types (me);
      Print_Layout (" ");
      Print_Layout (" ");
      Print_String ("union {");
      Print_Layout ("\n");
      Print_Layout (" ");
      Print_Layout (" ");
      { Int margin = fix_margin ();
        List_Types_struct_type xxx_yyy_sub_types = yyy_sub_types;
        for (; xxx_yyy_sub_types != NULL; xxx_yyy_sub_types = xxx_yyy_sub_types ? List_Types_struct_type_next(xxx_yyy_sub_types) : NULL) {
          Types_struct_type yyy_yyy_sub_types = List_Types_struct_type_data(xxx_yyy_sub_types);
          PRINT_Types_struct_type(yyy_yyy_sub_types);
        }
        set_margin (margin);
      }
      Print_String ("} sub;");
      Print_Layout ("\n");
    }
    { Int margin = fix_margin ();
      List_Types_field xxx_fields2 = Types_struct_type_fields2 (me);
      for (; xxx_fields2 != NULL; xxx_fields2 = xxx_fields2 ? List_Types_field_next(xxx_fields2) : NULL) {
        Types_field yyy_fields2 = List_Types_field_data(xxx_fields2);
        Print_Layout (" ");
        Print_Layout (" ");
        PRINT_Types_field(yyy_fields2);
        Print_Layout ("\n");
      }
      set_margin (margin);
    }
    Print_String ("}");
    Print_Layout (" ");
    if (Types_struct_type_id (me) != NULL) {
      Ident yyy_id = Types_struct_type_id (me);
      PRINT_Ident(yyy_id);
    }
    Print_String (";");
    Print_Layout ("\n");
    print_comment(Types_struct_type_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_struct_type (Types_struct_type me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_struct_type(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_macro (Types_macro me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_macro_loc(me) >= 0;
    advance_position (Types_macro_loc(me));
    margin = fix_margin ();
    print_comment(Types_macro_src_info(me)->pre_comment);
    switch (Types_macro_tag(me)) {
      case Types_plain_macro_kind:
        Print_String ("#define");
        Print_Layout (" ");
        PRINT_Ident(Types_macro_type (me));
        Print_Keyword ("_");
        PRINT_Ident(Types_macro_id (me));
        Print_String ("(_p)");
        Print_Layout ("\t");
        Print_String ("(");
        Print_String ("(*_p)");
        { Int margin = fix_margin ();
          List_Ident xxx_types = Types_macro_types (me);
          for (; xxx_types != NULL; xxx_types = xxx_types ? List_Ident_next(xxx_types) : NULL) {
            Ident yyy_types = List_Ident_data(xxx_types);
            Print_String (".sub.");
            PRINT_Ident(yyy_types);
          }
          set_margin (margin);
        }
        Print_String (".");
        PRINT_Ident(Types_macro_f (me));
        Print_String (")");
        Print_Layout ("\n");
        break;
      case Types_access_macro_kind:
        Print_String ("#define");
        Print_Layout (" ");
        PRINT_Ident(Types_macro_type (me));
        Print_Keyword ("_");
        PRINT_Ident(Types_macro_id (me));
        Print_String ("(_p)");
        Print_Layout ("\t");
        Print_String ("(");
        PRINT_Ident(Types_access_macro_r (me));
        Print_String ("_USER_ACCESS(_p)");
        { Int margin = fix_margin ();
          List_Ident xxx_types = Types_macro_types (me);
          for (; xxx_types != NULL; xxx_types = xxx_types ? List_Ident_next(xxx_types) : NULL) {
            Ident yyy_types = List_Ident_data(xxx_types);
            Print_String (".sub.");
            PRINT_Ident(yyy_types);
          }
          set_margin (margin);
        }
        Print_String (".");
        PRINT_Ident(Types_macro_f (me));
        Print_String (")");
        Print_Layout ("\n");
        break;
    }
    print_comment(Types_macro_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_macro (Types_macro me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_macro(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_field (Types_field me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_field_loc(me) >= 0;
    advance_position (Types_field_loc(me));
    margin = fix_margin ();
    print_comment(Types_field_src_info(me)->pre_comment);
    { Int margin = fix_margin ();
      Bool __first = TRUE;
      List_Types_TypeName xxx_type = Types_field_type (me);
      for (; xxx_type != NULL; xxx_type = xxx_type ? List_Types_TypeName_next(xxx_type) : NULL) {
        Types_TypeName yyy_type = List_Types_TypeName_data(xxx_type);
        if (!__first) {
          Print_Keyword ("_");
;
        }
        __first = FALSE;
        PRINT_Types_TypeName(yyy_type);
      }
      set_margin (margin);
    }
    Print_Layout ("\t");
    PRINT_Ident(Types_field_id (me));
    Print_String (";");
    Print_Layout (" ");
    Print_Layout (" ");
    print_comment(Types_field_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_field (Types_field me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_field(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_TypeName (Types_TypeName me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_TypeName_loc(me) >= 0;
    advance_position (Types_TypeName_loc(me));
    margin = fix_margin ();
    print_comment(Types_TypeName_src_info(me)->pre_comment);
    PRINT_Ident(Types_TypeName_full (me));
    print_comment(Types_TypeName_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_TypeName (Types_TypeName me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_TypeName(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_CreateFunction (Types_CreateFunction me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    Source_node = Types_CreateFunction_loc(me) >= 0;
    advance_position (Types_CreateFunction_loc(me));
    margin = fix_margin ();
    print_comment(Types_CreateFunction_src_info(me)->pre_comment);
    Print_Keyword ("CREATE");
    { Int margin = fix_margin ();
      List_Types_field xxx_fields = Types_CreateFunction_fields (me);
      for (; xxx_fields != NULL; xxx_fields = xxx_fields ? List_Types_field_next(xxx_fields) : NULL) {
        Types_field yyy_fields = List_Types_field_data(xxx_fields);
        PRINT_Types_field(yyy_fields);
      }
      set_margin (margin);
    }
    print_comment(Types_CreateFunction_src_info(me)->post_comment);
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_CreateFunction (Types_CreateFunction me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_CreateFunction(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_Types_Scope (Types_Scope me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    switch (Types_Scope_tag(me)) {
      case Types_struct_typeScope_kind:
        break;
    }
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_Types_Scope (Types_Scope me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_Types_Scope(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Types_struct_type (List_Types_struct_type me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Types_struct_type (List_Types_struct_type_data(me));
    PRINT_List_Types_struct_type (List_Types_struct_type_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Types_struct_type (List_Types_struct_type me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Types_struct_type(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Types_field (List_Types_field me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Types_field (List_Types_field_data(me));
    PRINT_List_Types_field (List_Types_field_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Types_field (List_Types_field me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Types_field(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Types_CreateFunction (List_Types_CreateFunction me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Types_CreateFunction (List_Types_CreateFunction_data(me));
    PRINT_List_Types_CreateFunction (List_Types_CreateFunction_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Types_CreateFunction (List_Types_CreateFunction me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Types_CreateFunction(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Types_macro (List_Types_macro me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Types_macro (List_Types_macro_data(me));
    PRINT_List_Types_macro (List_Types_macro_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Types_macro (List_Types_macro me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Types_macro(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Types_TypeName (List_Types_TypeName me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Types_TypeName (List_Types_TypeName_data(me));
    PRINT_List_Types_TypeName (List_Types_TypeName_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Types_TypeName (List_Types_TypeName me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Types_TypeName(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Types_StructType (List_Types_StructType me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Types_StructType (List_Types_StructType_data(me));
    PRINT_List_Types_StructType (List_Types_StructType_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Types_StructType (List_Types_StructType me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Types_StructType(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Types_BindType (List_Types_BindType me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Types_BindType (List_Types_BindType_data(me));
    PRINT_List_Types_BindType (List_Types_BindType_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Types_BindType (List_Types_BindType me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Types_BindType(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Types_subtypedef (List_Types_subtypedef me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Types_subtypedef (List_Types_subtypedef_data(me));
    PRINT_List_Types_subtypedef (List_Types_subtypedef_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Types_subtypedef (List_Types_subtypedef me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Types_subtypedef(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Types_PointerType (List_Types_PointerType me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Types_PointerType (List_Types_PointerType_data(me));
    PRINT_List_Types_PointerType (List_Types_PointerType_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Types_PointerType (List_Types_PointerType me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Types_PointerType(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

void Print_List_Types_EnumType (List_Types_EnumType me)
{ EvalComments ();
  { unsigned int margin;
    Bool source_node = Source_node;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Types_EnumType (List_Types_EnumType_data(me));
    PRINT_List_Types_EnumType (List_Types_EnumType_next(me));
    Source_node = source_node;    set_margin (margin);
  }
}

char *Text_List_Types_EnumType (List_Types_EnumType me)
{
  char *old_ps = print_string;
  FILE *old_pf = print_file;
  static char str[4096];
  set_advance(FALSE);
  open_print_string (str, Front_pretty);
  Print_List_Types_EnumType(me);
  close_print_string ();
  set_advance(TRUE);
  print_string = old_ps;
  print_file = old_pf;
  return fe_strdup(str);
}

