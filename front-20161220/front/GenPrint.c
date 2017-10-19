/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 */
#include <string.h>
#include <ctype.h>
#include <front/print_support.h>
#include "GenTypes.h"
#include "GenGrammar.h"
#include "frontPrint.h"
#include "TypesPrint.h"
#include "GenPrint.h"

#define DEBUG 0


/* test for s being an identifier */
Bool is_keyword (String s)
{ int i;
  for (i=0; s[i]; i++) {
    if (isalpha((int)s[i])) continue;
    if (i>0 && isdigit((int)s[i])) continue;
    if (s[i] == '_') continue;
    return FALSE;
  }
  return TRUE;
}

/* Generate the PRINT_id macro for type id (abbreviated: ab)*/
static void print_macro (Ident id, Ident ab)
{
  String s = Ident_name (id);
  String t = Ident_name (ab);
  String a;
  if (Std_type(id)) return;
  a = prefix_string ("print_actions");
  PF ("#define %s (%s.action_%s[PRE_ACTION]?"
        "%s.action_%s[PRE_ACTION]:%s)\n", 
	def_abbrevf("PRINT_",t, s,""), a, t, a, t, def_abbrevf("Print_",t, s,""));
  def_abbrevf("Text_",t, s,"");
}

/* Generate the Print_id function header */
static void print_header (Ident id)
{ String s = Ident_name (id);

  if (Std_type(id)) return;
  PF ("extern void Print_%s (%s me);\n", s, s);
}

static void text_header (Ident id)
{ String s = Ident_name (id);

  if (Std_type(id)) return;
  PF ("extern char *Text_%s (%s me);\n", s, s);
}

/* Generate the Print.h file */
static void gen_print_spec (Types t)
{
  List_StructType l;
  List_EnumType e;
  
  open_print_file (append_string (Rootstr, "Print.h"), TRUE);
  set_margin(0); set_position(0);

  PF ("#ifndef _%sPrint\n", Rootstr);
  PF ("#define _%sPrint\n\n", Rootstr);

  PF ("#include \"%s.h\"\n\n", Rootstr);
  
  for (l = Types_types(t); l; l = List_StructType_next(l)) {
    StructType x = List_StructType_data(l);
    print_macro (StructType_id1(x), struct_type_name(StructType_type(x)));
  }
  PF ("\n");

  for (e = Types_enums(t); e; e = List_EnumType_next(e)) {
    EnumType x = List_EnumType_data(e);
    if (EnumType_is_tag(x)) continue;
    print_macro (EnumType_id(x), EnumType_name(x));
  }
  PF ("\n");
  
  for (l = Types_types(t); l; l = List_StructType_next(l)) {
    StructType x = List_StructType_data(l);
    print_header (StructType_id1(x));
  }
  PF ("\n");

  for (l = Types_types(t); l; l = List_StructType_next(l)) {
    StructType x = List_StructType_data(l);
    text_header (StructType_id1(x));
  }
  PF ("\n");

  for (e = Types_enums(t); e; e = List_EnumType_next(e)) {
    EnumType x = List_EnumType_data(e);
    if (EnumType_is_tag(x)) continue;
    print_header (EnumType_id(x));
  }
  PF ("\n");
  
  for (e = Types_enums(t); e; e = List_EnumType_next(e)) {
    EnumType x = List_EnumType_data(e);
    if (EnumType_is_tag(x)) continue;
    text_header (EnumType_id(x));
  }
  PF ("\n");
  
  PF ("#endif /* _%sPrint */\n", Rootstr);
  close_print_file();
}

/*****************/

static String indent = "";    /* Current indentation */
static struct_type cur_type;  /* Current type */

/* Print an access to field f.
   This is normally T_f(me), but can be just an identifier, e.g. with a for-loop.
   in_list indicates this difference.
*/
static void access_field (field f, Bool in_list)
{
  if (in_list) {
    PF ("%s", Ident_name(field_id(f)));
  } else {
    print_field_type (f, cur_type);
    PF ("_%s (me)", Ident_name(field_id(f)));
  }
}

static field the_field;
static Bool _contains_field (Symbol s, Bool b)
{
  if (LabeledSym_id(s) == field_id(the_field)) {
    return TRUE;
  }
  return b;
}

static Bool contains_field_id (Symbol s, field f)
{
  static struct s_front_TraverseTable tab;
  tab.action_LabeledSym[PRE_ACTION] = (void*)_contains_field;
  
  if (f==NULL) return TRUE;
  the_field = f;
  return (Bool)Traverse_Symbol (s, &tab, FALSE);
}

typedef enum { field_optional, field_non_optional, field_not_found }
optional_type;

static optional_type can_be_empty (Symbol s, field f);

/* Test for possible emptiness */
static optional_type list_can_be_empty (List_Symbol l, field f)
{
  for (; l; l = List_Symbol_next(l)) {
    Symbol t = List_Symbol_data(l);
    if (!contains_field_id(t, f)) continue;
    return can_be_empty (t, f);
  }
  return field_not_found;
}

/* Test for possible emptiness */
static optional_type can_be_empty (Symbol s, field f)
{
  if (!contains_field_id(s, f)) return field_not_found;
  
  switch (Symbol_tag(s)) {
    case OptSymbol_kind:
    case OptMoreSymbol_kind:
      return field_optional;
    case SymbolSeq_kind:
      return list_can_be_empty (SymbolSeq_symbols(s), f);
    case CompareSym_kind:
      return can_be_empty (Symbol2_sym(s), f);
    case LabeledSym_kind:
      if (LabeledSym_id(s) == field_id(f)) {
        return can_be_empty (LabeledSym_sym(s), NULL);
      }
      return can_be_empty (LabeledSym_sym(s), f);
    case AltSymbol_kind: {
      List_Symbol l;
      for (l = AltSymbol_syms(s); l; l = List_Symbol_next(l)) {
        Symbol t = List_Symbol_data(l);
	if (!contains_field_id(t, f)) continue;
        return field_optional;
      }
      return can_be_empty (AltSymbol_syms1(s), f);
    }
    default:
      break;
  }
  return field_non_optional;
}

/* Generate a test for all the fields in l being NULL */
static void null_test (List_Symbol s, List_field l, Bool in_list, Bool null)
{
  String sep = "";
  for (; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    if (list_can_be_empty(s, f) == field_optional) continue;
    PF ("%s", sep);
    access_field (f, in_list);
    if (!null) PF (" != NULL");
    sep = " && ";
  }
}

static void print_expr (Expr e)
{ Print_Expr(e);
}

/* Generate a call to the print function for field f */
static void print_field (field f, Bool in_list)
{
  if (field_init(f) != NULL) return;
  PF ("%sPRINT_%s(", indent, Ident_name (full_glue_type(field_type(f))));
  access_field (f, in_list);
  PF (");\n");
}

/* Generate calls to the print function for fields in l */
static void print_fields (List_field l, Bool in_list)
{
  for (; l; l = List_field_next(l)) {
    print_field(List_field_data(l), in_list);
  }
}

/* Return the first n fields in l */
static List_field take_fields (List_field l, int n)
{
  if (l==NULL || n==0) return NULL;
  return Create_List_field (List_field_data(l), 
                            take_fields (List_field_next(l), n-1));
}

/* Remove the first n fields from l */
static List_field drop_fields (List_field l, int n)
{
  if (l==NULL || n==0) return l;
  return drop_fields (List_field_next(l), n-1);
}

static void print_sym (Symbol s, List_field f, Bool in_list);
static void print_alt (Alternative a, Bool pre, List_field f, Bool in_list, Bool macro);

/* Generate printing for the symbols in l */
static void print_syms (List_Symbol l, List_field f, Bool in_list)
{
  if (DEBUG) PF ("%s/* #syms = %d */\n", indent, List_Symbol_size(l));
  for (; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    List_field f1 = get_fields(s);
    Int n = List_field_size(f1);
    print_sym (s, take_fields(f, n), in_list);
    f = drop_fields (f, n);
  }
}

/* The functions returns a copy of the fields in h, but with names YYY_f, where
   f is the corresponding field in l.
   l contains List_T fields, where h contains the corresponding T fields.
*/
static List_field sub_fields (List_field l, List_field h)
{ List_field g = NULL;
  for (; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    String s = append_string ("yyy_", Ident_name(field_id(f)));
    field f1;
    if (h == NULL) break;
    f1 = Create_field (no_srcinfo, NULL, NULL);
    *f1 = *List_field_data(h);
    field_id(f1) = Create_Ident(s);
    FRONT_APPEND_NODE (g, f1);
    h = List_field_next(h);
  }
  return g;
}

/* In case of optional fields, this generates the access to the heads:
   T yyy_f = List_T_data(xxx_f);
*/
static void null_decl (List_field l, List_field h, Bool in_list)
{ 
  if (h==NULL) return;
  
  for (; l; l = List_field_next(l), h = List_field_next(h)) {
    field f = List_field_data(l);
    field g = List_field_data(h);
    remove_optional (f);
    remove_optional (g);
    PF ("%s  %s", indent, Ident_name(full_glue_type(field_type(g))));
    PF (" yyy_%s = ", Ident_name(field_id(f)));
    if (Allows_nil(List_TypeName_data(field_type(g)))) {
      access_field (f, in_list); PF (";\n");
    } else {
      PF ("%s_data(", Ident_name(full_glue_type(field_type(f)))); 
      access_field (f, in_list); PF (");\n");
    }
  }
}

/* In case of iteration over list-fields, this generates the access to the heads:
   T yyy_f = List_T_data(xxx_f);
*/
static void head_decl (List_field l, List_field h)
{ 
  if (h==NULL) return;
  
  for (; l; l = List_field_next(l), h = List_field_next(h)) {
    field f = List_field_data(l);
    field g = List_field_data(h);
    remove_optional (f);
    remove_optional (g);
    PF ("%s%s", indent, Ident_name(full_glue_type(field_type(g))));
    PF (" yyy_%s = ", Ident_name(field_id(f)));
    PF ("%s_data(xxx_%s);\n", Ident_name(full_glue_type(field_type(f))), Ident_name(field_id(f)));
  }
}

/* Generate printing for an optional symbol [A|B]
   this has the form 
     if (f_A != NULL) <printing for A>
     if (f_B != NULL) <printing for B>
*/
static void print_opt (List_Symbol l, List_field f, Bool in_list)
{
  String ind = indent;
  String new_ind = append_string (indent, "  ");
  for (; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    List_field g = get_fields(s);
    Int n = List_field_size(g);
    List_field f1;
    List_field f2;
    if (g==NULL) n = 1;
    f1 = take_fields(f, n);
    f2 = sub_fields (f1, g);;

    PF ("%sif (", indent);
    null_test (l, f1, in_list, g==NULL);
    PF (") {\n");
    null_decl (f1, g, in_list);
    indent = new_ind;
    print_sym (s, f2, TRUE);
    indent = ind;
    PF ("%s}\n", indent);
    
    f = drop_fields (f, n);
  }
}

/* Generate declarations for the fields in l 
   These have the form 
     T_f xxx_f = access(f);
*/
static void decl_fields (List_field l, Bool in_list)
{ 
  for (; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    PF ("%s  %s", indent, Ident_name(full_glue_type(field_type(f))));
    PF (" xxx_%s = ", Ident_name(field_id(f)));
    access_field (f, in_list);
    PF (";\n");
  }
}

/* Generate xxx_f = List_T_next(xxx_f), or
   xxxx_f--, in case of empty 
*/
static void next_fields (List_field l, Bool empty, String s, String i)
{
  String sep = "";

  for (; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    String fid = Ident_name(field_id(f));
    PF ("%s", i);
    PF ("%sxxx_%s", sep, fid);
    if (empty) {
      PF ("--"); 
    } else {
      PF (" = xxx_%s ? %s", fid, Ident_name(full_glue_type(field_type(f))));
      PF ("_next(xxx_%s) : NULL", fid);
    }
    sep = s;
  }
}

/* Generate the condition and step part of a for-loop over list-fields */
static void iter_fields (List_field fl1, List_field fl2, Bool empty)
{ String sep = "";
  List_field l;

  for (l = fl1; l; l = List_field_next(l)) {
    field f = List_field_data(l);
    PF ("%sxxx_%s", sep, Ident_name(field_id(f)));
    if (empty) PF (" > 0"); else PF (" != NULL");
    sep = " && ";
  }
  PF ("; ");
  next_fields (fl2, empty, ", ", "");
}

/* Generate a for-loop for a MoreSymbol */
static void print_more (List_Symbol l, List_field f, Bool in_list)
{
  String ind = indent;
  String new_ind = append_string (indent, "    ");
  for (; l; l = List_Symbol_next(l)) {
    Symbol s = List_Symbol_data(l);
    List_field g = get_fields(s);
    Int n = List_field_size(g);
    List_field f1;
    List_field f2;
    if (g==NULL) n = 1;
    f1 = take_fields(f, n);
    f2 = sub_fields (f1, g);;
    
    PF ("%s{ Int margin = fix_margin ();\n", indent);
    decl_fields (f1, in_list);
    PF ("%s  for (; ", indent);
    iter_fields (f1, f1, g==NULL);
    PF (") {\n");
    indent = new_ind;
    head_decl(f1, g);
    print_sym (s, f2, TRUE);
    indent = ind;
    PF ("%s  }\n", indent);
    PF ("%s  set_margin (margin);\n", indent);
    PF ("%s}\n", indent);
    
    f = drop_fields (f, n);
  }
}

/* Generate a for-loop for an alternation a // b */
static void print_alternate (Symbol a, List_Symbol b, List_field f, Bool in_list)
{ 
  String ind = indent;
  String new_ind1 = append_string (indent, "  ");
  String new_ind2 = append_string (new_ind1, "  ");
  String new_ind3 = append_string (new_ind2, "  ");

  List_field g1 = get_fields(a);
  List_field g2 = get_syms_fields(b);
  List_field g = FRONT_CONCAT(field, g1, g2);
  Int n = List_field_size(g1);
  List_field f1 = take_fields (f, n);
  List_field f3 = sub_fields (f, g);
  List_field f2 = drop_fields (f3, n);
  List_field f4 = drop_fields (f, n);
  
  PF ("%s{ Int margin = fix_margin ();\n", indent);
  PF ("%s  Bool __first = TRUE;\n", indent);
  decl_fields (f, in_list);
  indent = new_ind1;
#if 0
  head_decl(f1, g);
  print_sym (a, f3, TRUE);
  next_fields (f1, FALSE, ";\n", indent); PF (";\n");
#endif
  PF ("%sfor (; ", indent);
  indent = new_ind2;
  iter_fields (f1, f1, FALSE);
  PF (") {\n");
  head_decl(f1, g);
  if (DEBUG) PF ("%s/* b */\n", indent);
  PF ("%sif (!__first) {\n", indent);
    indent = new_ind3;
    head_decl(f4, g2);
    print_syms (b, f2, TRUE);
    next_fields (f4, FALSE, ";\n", indent); PF (";\n");
    indent = new_ind2;
  PF ("%s}\n", indent);
  PF ("%s__first = FALSE;\n", indent);
  if (DEBUG) PF ("%s/* a */\n", indent);
  print_sym (a, f3, TRUE);
  indent = ind;
  PF ("%s  }\n", indent);
  PF ("%s  set_margin (margin);\n", indent);
  PF ("%s}\n", indent);

}

/* Generate the printing for Symbol s with fields f */
static void print_sym (Symbol s, List_field f, Bool in_list)
{
  if (s==NULL) return;
  
  if (DEBUG) PF ("%s/* Symbol %s */\n", indent, Symbol_tag_names[Symbol_tag(s)]);
  switch (Symbol_tag(s)) {
    case LabeledSym_kind:
      print_sym (LabeledSym_sym(s), f, in_list);
      break;
    case CompareSym_kind:
      print_sym (Symbol2_sym(s), f, in_list);
      break;
    case AppliedSym_kind: {
      field g;
      struct_type t;
      Ident tid = NULL;
      if (AppliedSym_field(s) == AppliedField) break;
      g = List_field_data(List_field_next(List_field_next(Symbol_fields(s))));
      t = nonterm_type (AppliedSym_nt(s), AppliedSym_alt(s), &tid);
      if (tid==NULL) {
        tid = AppliedSym_nt_id(s);
	tid = Create_Ident(Ident_name(tid));
      }
      PF ("%sif (", indent); access_field (g, FALSE); PF (" != NULL)\n");
        PF ("%s{ start_href (%s_loc(", indent, Ident_name(tid));
	  if (applied_overloaded(s)) {
	    PF ("List_%s_data(", Ident_name(tid));
	    access_field (g, FALSE); PF (")), ");
	  } else {
            access_field (g, FALSE); PF ("), ");
          }
	  access_field (g, FALSE); PF ("); }\n");
      print_fields (f, in_list);
      PF ("%sif (", indent);  access_field (g, FALSE); PF (" != NULL)\n");
        PF ("%s{ end_href (); }\n", indent);
      break;
    }
    case StringSymbol_kind:
      if (StringSymbol_type(s) == NULL) {
        if (is_keyword(remove_quotes(StringSymbol_string(s)))) {
	  PF ("%sPrint_Keyword (%s);\n", indent, StringSymbol_string(s));
	} else {
	  PF ("%sPrint_String (%s);\n", indent, StringSymbol_string(s));
	}
      } else {
       print_fields (f, in_list);
      }
      break;
    case CharSymbol_kind:
      if (CharSymbol_type(s) == NULL) {
        PF ("%sPrint_String (\"%s\");\n", indent, remove_quotes(CharSymbol_chr(s)));
      } else {
        print_fields (f, in_list);
      }
      break;
    case KeywordSymbol_kind:
      if (KeywordSymbol_type(s) == NULL) {
        PF ("%sPrint_Keyword (\"%s\");\n", indent, remove_quotes(KeywordSymbol_keyword(s)));
      } else {
        print_fields (f, in_list);
      }
      break;
    case OnceSymbol_kind:
      if (List_Symbol_size(CompoundSym_sym(s)) == 1) {
        print_sym (List_Symbol_data(CompoundSym_sym(s)), f, in_list);
        break;
      }
      /* Fall throught */
    case OptSymbol_kind:
      print_opt (CompoundSym_sym(s), f, in_list);
      break;
    case OptMoreSymbol_kind:
    case MoreSymbol_kind:
      print_more (CompoundSym_sym(s), f, in_list);
      break;
    case AltSymbol_kind:
      print_alternate (AltSymbol_syms1(s), AltSymbol_syms(s), f, in_list);
      break;
    case EmptySym_kind:
      break;
    case LayoutString_kind:
      PF ("%sPrint_Layout (\"%s\");\n", indent, remove_quotes(LayoutString_layout(s)));
      break;
#if 0
/* TODO: find out what this means */
    case ForceLayout_kind:
      PF ("%sPrint_Layout (\"%s\");\n", indent, remove_quotes(ForceLayout_layout(s)));
      break;
#endif
    case LayoutAction_kind:
      print_expr (LayoutAction_layout(s));
      break;
    case SymbolSeq_kind:
      print_syms (SymbolSeq_symbols(s), f, in_list);
      break;
    case DefiningSym_kind:
      if (Defining_id_tag(DefiningSym_id(s)) == DefId_kind) {
        PF ("%sstart_label (me);\n", indent);
        print_sym (DefId_id(DefiningSym_id(s)), f, in_list);
        PF ("%send_label ();\n", indent);
      }
      break;
    case IdSym_kind: {
      NonTerminal nt = IdSym_nt(s);
      if (nt != NULL && is_macro(nt)) {
	if (DEBUG) PF ("%s /*macro pre %s */\n", indent, Ident_name(IdSym_id(s)));
	print_alt (NonTerminal_alt(nt), TRUE, f, in_list, TRUE);
	if (DEBUG) PF ("%s /*macro post %s */\n", indent, Ident_name(IdSym_id(s)));
        print_alt (NonTerminal_alt(nt), FALSE, f, in_list, TRUE);
	if (DEBUG) PF ("%s /*macro end %s */\n", indent, Ident_name(IdSym_id(s)));
        break;
      }
      print_fields (f, in_list);
      break;
    }
  }
}

/* Generate the printing for Rhs r with fields f */
static void print_rhs (Rhs r, Bool pre, List_field f, Bool in_list, Bool macro)
{ 
  List_field f1 = get_fields(Rhs_syms1(r));
  Int n = List_field_size(f1);
  if ( pre) {
    print_sym (Rhs_syms1(r), take_fields(f, n), in_list);
    if (macro && Rhs_alts(r) != NULL) {
      print_alt (List_Alternative_data(Rhs_alts(r)), pre, f, in_list, macro);
    }
  }
  if (!pre) print_sym (Rhs_syms2(r), drop_fields(f, n), in_list);
}

/* Generate the printing for Alternative a with fields f */
static void print_alt (Alternative a, Bool pre, List_field f, Bool in_list, Bool macro)
{
  if (a == NULL) return;
  switch (Alternative_tag(a)) {
    case LabeledAlt_kind:
      if (DEBUG) PF ("%s/* rhs %s */\n", indent, Ident_name (LabeledAlt_id(a)));
      print_rhs (LabeledAlt_rhs(a), pre, f, in_list, macro);
      break;
    case UnLabeledAlt_kind:
      if (DEBUG) PF ("%s/* unlabeled alt */\n", indent);
      if (pre) print_sym (UnLabeledAlt_syms(a), f, in_list);
      break;
  }
}

static List_field rhs_fields (Rhs r)
{ List_field f = NULL;
  if (r==NULL) return f;
  
  f = get_fields(Rhs_syms1(r));
  f = FRONT_CONCAT(field, f, get_fields(Rhs_syms2(r)));
  return f;
}

/* Generate the body of a list printing function */
static void print_list (struct_type t)
{ String s = Type_str(t);
  String u = &s[5];
  PF ("    PRINT_%s (%s_data(me));\n", u, s);
  PF ("    PRINT_%s (%s_next(me));\n", s, s);
}

/* Generate the printing statements for t 
   This generates the printing of the super-type symbols, 
   either preceeding or following t, as indicated by pre.
   It prints the symbols for t itself in between.
*/
static void print_sub (struct_type t, Bool pre)
{ Alternative a = struct_type_alt(t);
  struct_type u = cur_type;
  List_field f;

  cur_type = t;
  
  if (DEBUG) PF ("%s/* alt %s pre %d*/\n", indent, Type_str(t), pre);
  if (pre && Root_type(t) != t) {
    print_sub (Super_type(t), pre);
  }
  
  if (a != NULL) {
    if (Alternative_tag(a) == UnLabeledAlt_kind) {
      f = get_fields (UnLabeledAlt_syms(a));
    } else {
      f = rhs_fields (LabeledAlt_rhs(a));
    }
    print_alt (a, pre, f, FALSE, FALSE);
  } else if (pre && struct_type_is_list(t)) {
    print_list (t);
  }
  
  if (!pre && Root_type(t) != t) {
    print_sub (Super_type(t), pre);
  }
  cur_type = u;
}

typedef enum { no_enum, string_enum, int_enum }
enum_kind;

/* Generate the printing for all lef-sub-types of t.
   If needed, a case label is generated.
   e_num indicates whether it is an enum type, *n contains the current enum value.
*/
static void print_type (struct_type t, Bool sub, enum_kind e_num, Int *n)
{
  List_struct_type l = struct_type_sub_types(t);
  String s = Type_str(t);
  
  indent = "    ";
  
  if (l != NULL) {
    for (; l; l = List_struct_type_next(l)) {
      print_type (List_struct_type_data(l), sub, e_num, n);
    }
    return;
  }
  
  if (sub) {
    if (e_num != no_enum) {
      if ((strlen(s) == 0) || (e_num == int_enum)) {
        PF ("    case %d:\n", *n);
      } else {
        PF ("    case %s:\n", s);
      }
      indent = "      ";
      (*n)++;
    } else {
      PF ("      case %s_kind:\n", s);
      indent = "        ";
    }
  }
  
  print_sub (t, TRUE);
  print_sub (t, FALSE);
  
  if (sub) {
    if (e_num != no_enum) {
      PF ("      break;\n");
    } else {
      PF ("        break;\n");
    }
  }
}

/* Preamble for pretty printing */
static void pretty1 (struct_type t)
{ 
  String s = Type_str(t);
  Bool has_loc = contains_field (t, Create_Ident("src_info"));
  PF ("  { unsigned int margin;\n");
  PF ("    Bool source_node = Source_node;\n");
  PF ("    if (me == NULL) return;\n");
  if (has_loc) PF ("    Source_node = %s_loc(me) >= 0;\n", s);
  if (has_loc) PF ("    advance_position (%s_loc(me));\n", s);
  PF ("    margin = fix_margin ();\n");
  if (has_loc) PF ("    print_comment(%s_src_info(me)->pre_comment);\n", s);
}

/* Postamble for pretty printing */
static void pretty2 (struct_type t)
{ 
  String s = Type_str(t);
  Bool has_loc = contains_field (t, Create_Ident("src_info"));
  if (has_loc) PF ("    print_comment(%s_src_info(me)->post_comment);\n", s);
  PF ("    Source_node = source_node;");
  PF ("    set_margin (margin);\n");
  PF ("  }\n");
}

static void
gen_text_function (String s)
{
  PF ("char *Text_%s (%s me)\n", s, s);
  PF ("{\n");
  PF ("  char *old_ps = print_string;\n");
  PF ("  FILE *old_pf = print_file;\n");
  PF ("  static char str[4096];\n");
  PF ("  set_advance(FALSE);\n");
  PF ("  open_print_string (str, Front_pretty);\n");
  PF ("  Print_%s(me);\n", s);
  PF ("  close_print_string ();\n");
  PF ("  set_advance(TRUE);\n");
  PF ("  print_string = old_ps;\n");
  PF ("  print_file = old_pf;\n");
  PF ("  return fe_strdup(str);\n");
  PF ("}\n\n");
}

static void text_function (StructType t1)
{
  gen_text_function (Type_str (StructType_type (t1)));
}

/* Generate the print function for type t */
static void print_function (StructType t1)
{
  struct_type t = StructType_type(t1);
  String s = Type_str(t);
  List_struct_type l = struct_type_sub_types(t);
  
  PF ("void Print_%s (%s me)\n", s, s);
  PF ("{ EvalComments ();\n");
  pretty1 (t);
  if (l == NULL) {
    print_type (t, FALSE, no_enum, NULL);
  } else {
   PF ("    switch (%s_tag(me)) {\n", s);
    print_type (t, TRUE, no_enum, NULL);
   PF ("    }\n");
  }
  pretty2 (t);
  PF ("}\n\n");
}

/* Generate the print function for enum type e */
static void print_enum_function (EnumType e)
{
  struct_type t = EnumType_str_type(e);
  String s = Ident_name (EnumType_id(e));
  Int n = 0;
  enum_kind e_num = enum_is_int(e)?int_enum:string_enum;

  PF ("void Print_%s (%s me)\n", s, s);
  if (List_Ident_size(EnumType_enums(e)) < 2) {
    PF ("{");
    print_type (t, FALSE, e_num, &n);
  } else {
    PF ("{ switch (me) {\n");
      print_type (t, TRUE, e_num, &n);
    PF ("  }\n");
  }
  PF ("}\n\n");
}

static void text_enum_function (EnumType e)
{
  gen_text_function (Ident_name (EnumType_id(e)));
}

/* Generate the Print.c file */
static void gen_print_impl (Types t)
{
  List_StructType l;
  List_EnumType e;

  open_print_file (append_string (Rootstr, "Print.c"), TRUE);
  set_margin(0); set_position(0);

  PF ("#include \"%sPrint.h\"\n", Rootstr);
  PF ("#include <front/text.h>\n\n");
  PF ("#include <front/print_support.h>\n\n");
  
  for (l = Types_types(t); l; l = List_StructType_next(l)) {
    StructType x = List_StructType_data(l);
    if (Std_type(StructType_id1(x))) continue;
    print_function (x);
    text_function (x);
  }

  for (e = Types_enums(t); e; e = List_EnumType_next(e)) {
    EnumType x = List_EnumType_data(e);
    if (EnumType_is_tag(x)) continue;
    print_enum_function (x);
    text_enum_function (x);
  }

  close_print_file();
}

/* Generate the RootPrint.h and RootPrint.c files */
void GenPrint (Types t)
{
  gen_print_spec (t);
  gen_print_impl (t);
}
