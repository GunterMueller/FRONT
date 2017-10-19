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
#include <front/print_support.h>
#include "GenTypes.h"
#include "GenGrammar.h"
#include "flags.h"
#include "GenSubParse.h"

static Bool def = TRUE;

/* Generate the preamble, containing the
   Root_multi_action function pointer
   Root_parse_nt function
   sub_trees type
   first_sub_tree, last_sub_tree variables
   Root_Put_sub_tree, Root_Get_sub_tree functions
   get_node functions
   vRoot_parse_string and Root_parse_string functions
*/
void preamble (void)
{
  PF ("extern struct yy_buffer_state *%s__scan_string (char *);\n", prefix);
  PF ("extern struct yy_buffer_state *%s__scan_buffer (char *, size_t);\n", prefix);
  PF ("extern struct yy_buffer_state *%s__create_buffer (FILE *, int);\n", prefix);
  PF ("extern void %s__switch_to_buffer (struct yy_buffer_state *);\n", prefix);
  PF ("extern void %s_push_buffer_state (struct yy_buffer_state *);\n", prefix);
  PF ("extern void %s__delete_buffer (struct yy_buffer_state *);\n", prefix);
  PF ("extern int %s_parse (void);\n\n", prefix);

  PF ("Bool %s_use_lalr = FALSE;\n", prefix);
  PF ("extern int %s_state_stack_depth;\n", prefix);

  PF ("static void %s_parse_nt (char *nt, char *s)\n", prefix);
  PF ("{ char *t = (char*)fe_malloc(%d+strlen(nt)+strlen(s)+3);\n", strlen(multi_start) );
  PF ("  struct yy_buffer_state *buf;");
  PF ("  sprintf(t, \"%%s_%%s %%s\", \"%s\", nt, s);\n", multi_start );
  PF ("  buf = %s__scan_string (t);", prefix);
  PF ("  %s__switch_to_buffer (buf);\n", prefix);
  PF ("  %s_parse();\n", prefix);
  PF ("  %s__delete_buffer(buf);\n", prefix);
  PF ("}\n");
  PF ("\n");
  PF ("static void *the_node;\n");

  PF ("void %s_multi_action (void* n)\n", prefix);
  PF ("{ the_node = n; }\n");
  PF ("\n");
  PF ("static void *%s_parse_string (char *nt, char *s)\n", prefix);
  PF ("{\n");
  PF ("  the_node = NULL;\n", prefix);
  PF ("  %s_parse_nt (nt, s);\n", prefix);
  PF ("  assert (first_sub_tree==NULL);\n");
  PF ("  return the_node;\n");
  PF ("}\n\n");

  PF ("static struct yy_buffer_state *dummy_state (void)\n");
  PF ("{\n");
  PF ("  static struct yy_buffer_state *state = NULL;\n");
  PF ("  if (!state) state = %s__create_buffer (NULL,0);\n",prefix);
  PF ("  return state;\n");
  PF ("}\n\n");
}

/* Generate a sub-parse rule for symbol s with type t */
static void print_rule (String t, String s, Ident id)
{
  if (def) {
    PF ("extern %s %s (char *s, int n, ...);\n", t, abbreviatef ("Parse_",s,""));
  } else {
    PF ("%s %s (char *s, int n, ...)\n", t, abbreviatef ("Parse_",s,""));
    PF ("{ va_list p;\n");
    PF ("  va_start(p, n); Put_sub_trees (n, p); va_end(p);\n");
    PF ("  set_first_line (INT_MIN);\n");
    if (no_lalr) {
      PF ("    return (%s)%s (\"%s\", s);\n", t, abbreviatef ("","parse_string",""),s);
    } else {
      PF ("  if (%s_use_lalr) {\n", Rootstr);
      PF ("    %s__switch_to_buffer (%s__scan_string (s));\n", prefix, prefix);
      PF ("    return %s ();\n", abbreviatef ("Parse_state_",s,""));
      PF ("  } else {\n");
      PF ("    return (%s)%s (\"%s\", s);\n", t, abbreviatef ("","parse_string",""),s);
      PF ("  }\n");
    }
    PF ("}\n\n");
  }
}

/* Generate an export parse rule for symbol s with type t */
static void print_export_rule (String t, String s)
{
#ifdef IMPORT_ENABLED
  if (def) {
    PF ("%s %s (struct yy_buffer_state *current_state);\n", t, abbreviatef ("export_parse_",s,""));
  } else {
    PF ("%s %s (struct yy_buffer_state *current_state)\n", t, abbreviatef ("export_parse_",s,""));
    PF ("{\n");
    PF ("  char start[]=\"%s_%s \\0\";\n",multi_start,s);
    PF ("  struct yy_buffer_state *start_state = %s__create_buffer (NULL,0);\n\n",prefix);
    PF ("  /* Pickup the lexer state from the importer. */\n");
    PF ("  %s__switch_to_buffer (current_state);\n", prefix);
    PF ("  /* .._scan_buffer overwrites the current state */\n");
    PF ("  %s_push_buffer_state (start_state);\n", prefix);
    PF ("  %s_state_stack_depth ++;\n", prefix);
    PF ("  /* Get the parser in the right state with the start symbol. */\n");
    PF ("  %s__scan_buffer (start, sizeof(start));\n", prefix);
    PF ("  /* Prepare the result, and parse */\n");
    PF ("  the_node = NULL;\n");
    PF ("  %s_parse ();\n", prefix);
    PF ("  /* Switch to a new state to force the lexer info back into current_state. */\n");
    PF ("  %s__switch_to_buffer (dummy_state ());\n",prefix);
    PF ("  return (%s) the_node;\n",t);
    PF ("}\n\n");
  }
#endif
}

/* Generate a sub-parse rule for production rule r */
static void print_prod_rule (ProdRule r)
{
  String s = Ident_name (ProdRule_lhs(r));
  List_field fields = ProdRule_fields(r);
  field f;
  Ident id;

  if (ProdRule_tag(r) == NT_Rule_kind) {
    NonTerminal nt = NT_Rule_nt (r);
    Ident tid;

    if (NonTerminal_scan(nt) != NULL) return;
    if (!is_macro(nt)) {
      nonterm_type (nt, NULL, &tid);
      print_rule (Ident_name(tid), s, NonTerminal_id(nt));
      print_export_rule (Ident_name(tid), s);
      return;
    }
  } else {
    Symbol x = Extra_Rule_sym(r);
    switch (Symbol_tag(x)) {
      case OnceSymbol_kind:
      case OptSymbol_kind:
  return;
      default:
  break;
    }
  }
  if (List_field_size(fields) != 1) return;
  f = List_field_data(fields);
  remove_optional (f);
  id = full_glue_type(field_type(f));
  print_rule (Ident_name(id), s, id);
  print_export_rule (Ident_name(id), s);
}

/* Generate the sub-parse modeule Root_parse.c */
static void print_impl (front f)
{
  NOT_USED(f);
  open_print_file (append_string (Rootstr, "_parse.c"), TRUE);
  set_margin(0); set_position(0);

  print_std_include("stdlib");
  print_std_include("string");
  print_std_include("assert");
  print_std_include("limits");
  print_include("parse_support");
  print_include("mem");
  PF ("#include \"%s_parse.h\"\n", Rootstr);
  if (!no_lalr) PF ("#include \"%s_lalr.h\"\n", Rootstr);
  PF ("\n");
  preamble();

  def = FALSE;
  for_all_rules (NULL, print_prod_rule);

  close_print_file();
}

/***********************/

/* Generate the fixed part in the .h file */
static void def_preamble (void)
{
  PF ("extern void %s_multi_action (void*);\n\n", prefix);
  PF ("struct yy_buffer_state;\n\n");
  PF ("extern Bool %s_use_lalr;\n", prefix);
  PF ("extern int %s_state_stack_depth;\n\n", prefix);
}

/* Generate the sub-parse modeule Root_parse.h */
static void print_def (front f)
{
  NOT_USED(f);
  open_print_file (append_string (Rootstr, "_parse.h"), TRUE);
  set_margin(0); set_position(0);
  PF ("#ifndef _%s_parse_h\n", Rootstr);
  PF ("#define _%s_parse_h\n\n", Rootstr);

  PF ("#include \"%s.h\"\n", Rootstr);
  PF ("\n");
  def_preamble();

  def = TRUE;
  for_all_rules (NULL, print_prod_rule);

#if 0
  PF ("\n#ifndef %s_NO_DEFS\n", Rootstr);
  print_include (append_string (Rootstr, "_defs"));
  PF ("#endif /* %s_NO_DEFS */\n\n", Rootstr);
#endif
  PF ("#endif /* _%s_parse_h*/\n", Rootstr);

  close_print_file();
}

/* Generate the Root_parse module */
void GenSubParse (front f)
{
  if (multi_start == NULL) return;
  Abbrev ("\n/* Abbreviations for %s */\n\n", append_string (Rootstr, "_parse.h"));
  print_def (f);
  print_impl (f);
}
