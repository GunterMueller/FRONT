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
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <front/text.h>
#include <front/mem.h>
#include <front/error.h>
#include <front/filename.h>
#include "egg.h"
#include "eggPrint.h"
#include "messenger.h"

#define EGG_MAX_PREFIX_LENGTH 255
static char   prefix[EGG_MAX_PREFIX_LENGTH];

static struct s_void_egg_TraverseTable declare_mode_funcs;
static struct s_void_egg_TraverseTable declare_fixes;
static struct s_void_egg_TraverseTable declare_funcs;

static struct s_void_egg_TraverseTable define_modes;
static struct s_void_egg_TraverseTable impl_mode_funcs;
static struct s_void_egg_TraverseTable impl_msg_funcs;
static struct s_void_egg_TraverseTable implement_funcs;
static struct s_void_egg_TraverseTable parse_options;
static struct s_egg_TraverseTable      list_options;

static FILE *outfs;
static int indent=0;

/* ----------------------------------------------------------------------------
 * Print a formatted string to the output file
 */
static void
PF(char *fmt, ...)
{
  va_list args;

  va_start (args, fmt);
  fprintf (outfs, "%*s", indent, "");
  vfprintf (outfs, fmt, args);
  va_end (args);
}

/* ----------------------------------------------------------------------------
 * Get the group containing the declarations for S
 */
static Group
get_decls (Statement s)
{
  do {
    if (Statement_tag(s) == Group_kind && Group_decls (s)) {
      return s;
    }
    s = Statement_parent (s);
  } while (s);
  return NULL;
}

static char *
root_group_name (Statement s)
{
  Group group = get_decls (s);
  if (!group) return NULL;
  return Ident_name (Statement_id (group));
}

static char *
get_group_type(Statement s)
{
  Group g = get_decls (s);
  if (!Group_type (g)) return "void *";
  return Ident_name (Group_type (g));
}

static Declaration
get_decl (Statement s, MessageKind m)
{
  Statement g = get_decls (s);
  List_Declaration ds;
  
  for (ds = Group_decls (g); ds; ds = List_Declaration_next (ds)) {
    Declaration d = List_Declaration_data (ds);
    if (Declaration_kind(d) == m) return d;
  }
  return NULL;
}

/* ----------------------------------------------------------------------------
 * Generate the declaration of message mode modifier function
 */
static void
declare_mode_funcs_Statement (Statement me)
{
  char *s;

  if (Statement_fatal (me)) return;
  s = Ident_name (Statement_id (me));
  PF ("void %sset_%s_mode (egg_msg_kind mode);\n", prefix, s);
}

/* ----------------------------------------------------------------------------
 * Generate the declaration of the fix function pointer
 */
static void
declare_fixes_Message (Message me)
{
  char *s = Ident_name (Statement_id (me));
  char *type = get_group_type (me);
  PF ("int (*%s%s_fix) (%s object);\n", prefix, s, type);
}

/* ----------------------------------------------------------------------------
 * Generate the declaration of error function
 */
static void
declare_funcs_Message (Message me)
{
  char *s = Ident_name (Statement_id (me));
  char *type = get_group_type (me);
  PF ("int %s%s (%s loc, ...);\n", prefix, s, type);
}

/* ----------------------------------------------------------------------------
 * Add #includes for USES
 */
static void
include_uses (Uses uses)
{
  List_String us;
  
  for (us = Uses_uses (uses); us; us = List_String_next (us)) {
    PF ("#include %s\n", List_String_data (us));
  }
  PF ("\n");
}

/* ----------------------------------------------------------------------------
 * Generate the definition of error modes
 */
static void
define_modes_Message (Message me)
{
  SubMessage first;
  char *s, *t;

  s = Ident_name (Statement_id (me));
  t = root_group_name (me);
  assert (t);
  first = List_SubMessage_data (Message_msgs (me));
  PF ("egg_msg_kind %s%s_mode = egg_%s_kind;\n", prefix, s,
      Text_MessageKind (SubMessage_kind (first)));
}

/* ----------------------------------------------------------------------------
 * Generate the message mode modifier functions
 */
static void
impl_mode_funcs_Group (Group me)
{
  char *s;
  List_Statement stats;

  if (Statement_fatal (me)) return;
  s = Ident_name (Statement_id (me));
  PF ("void\n"
      "%sset_%s_mode (egg_msg_kind mode)\n"
      "{\n",
      prefix,
      s);
  for (stats = Group_stats (me); stats; stats = List_Statement_next (stats)) {
    Statement s = List_Statement_data (stats);
    if (Statement_fatal (s)) continue;
    PF ("  %sset_%s_mode (mode);\n", prefix, Ident_name (Statement_id (s)));
  }
  PF ("}\n\n");
}

static void
impl_mode_funcs_Message (Message me)
{
  char *s;

  if (Statement_fatal (me)) return;
  s = Ident_name (Statement_id (me));
  PF ("void\n"
      "%sset_%s_mode (egg_msg_kind mode)\n"
      "{\n",
      prefix, s);
  PF ("  %s%s_mode = mode;\n"
      "}\n\n", prefix, s);
  
}

static void
print_expr (Expression e, Bool deref)
{
  char *sep;
  List_Expression es;
  
  switch (Expression_tag (e)) {
  case StringExpr_kind:
    PF (StringExpr_s(e));
    break;
  case IdExpr_kind:
    if (IdExpr_id (e) == Create_Ident ("locater"))       PF ("loc");
    else if (IdExpr_id (e) == Create_Ident ("message")) {
      if (deref) PF("*");
      PF ("msg");
    }
    else PF (Ident_name (IdExpr_id (e)));
    break;
  case CallExpr_kind:
    PF (Ident_name (CallExpr_id (e))); 
    sep = "(";
    for (es = CallExpr_params (e); es; es = List_Expression_next (es)) {
      PF (sep);
      print_expr (List_Expression_data (es), deref);
      sep = ",";
    }
    PF (")");
  }
}

static void
make_set_key (Declaration me)
{
  Expression e;
  List_Expression es;
  
  es = Declaration_exprs (me);
  if (List_Expression_next (es)) {
    fe_abort ("unexpected list element");
  }
  e = List_Expression_data (es);
  PF ("  if(!secondary) egg_sort_key (msg, ");
  print_expr (e, TRUE);
  PF (");\n");
}

static void
make_post_call (Declaration me)
{
  Expression e;
  List_Expression es;

  if (!me) return;
  es = Declaration_exprs (me);
  if (List_Expression_next (es)) {
    fe_abort ("unexpected list element");
  }
  e = List_Expression_data (es);
  PF ("    ");
  print_expr (e, FALSE);
  PF (";\n");
}


static void
make_make_error (Declaration me)
{
  char *group = Ident_name (Statement_id (Declaration_group (me)));
  List_Expression es;
  
  PF ("static void\n"
      "make_%s_%s(egg_msg *msg, void *loc, char *fmt, va_list args, int secondary)\n"
      "{\n",
      group,
      Text_MessageKind (Declaration_kind (me)));
  make_set_key (get_decl (Declaration_group (me), KeyMsg));
  for (es = Declaration_exprs (me); es; es = List_Expression_next (es)) {
    Expression e = List_Expression_data (es);
    PF ("  egg_add_string (msg, ");
    print_expr (e, TRUE);
    PF (");\n");
  }
  PF ("  egg_vadd_format (msg, fmt, args);\n");
  PF ("  egg_add_string (msg, \"\\n\");\n");
  switch (Declaration_kind (me)) {
  case ErrorMsg:   PF ("  egg_set_kind (msg, egg_error_kind);\n"); break;
  case WarningMsg: PF ("  egg_set_kind (msg, egg_warning_kind);\n"); break;
  default:
    break;
  }
/*   PF ("  *msg = egg_submit (*msg);\n"); */
/*   make_post_call (get_decl (Declaration_group (me), PostMsg)); */
  PF ("}\n\n");
}

static void
impl_msg_funcs_Declaration (Declaration me)
{
  switch (Declaration_kind (me)) {
  case ErrorMsg: case WarningMsg:
    make_make_error (me); break;
  default:
    break;
  }
}

/* ----------------------------------------------------------------------------
 * Print calls to the message function depending on the message mode
 */
static void
print_trailing_messages (Message me, char *kind)
{
  char *root = root_group_name (me);
  List_SubMessage msgs = Message_msgs (me);

  for (msgs = List_SubMessage_next (msgs);
       msgs;
       msgs = List_SubMessage_next (msgs)) {
      SubMessage msg = List_SubMessage_data (msgs);
      PF ("    loc = va_arg (args, void*);\n");
      PF ("    make_%s_%s(&msg, loc, %s,args, 1);\n",
          root, kind, SubMessage_msg (msg));
  }
}

static void
print_cases (Message me)
{
  char *s = Ident_name (Statement_id (me));
  char *root = root_group_name (me);
  List_SubMessage msgs = Message_msgs (me);
  SubMessage first = List_SubMessage_data (msgs);

  PF ("  case egg_error_kind:\n");
  PF ("    egg_set_fix (&msg, (int(*)(void*))%s%s_fix, loc);\n", prefix, s);
  PF ("    make_%s_error(&msg, loc, %s, args, 0);\n",
      root, SubMessage_msg (first));
  make_post_call (get_decl (me, PostMsg));
  print_trailing_messages (me, "error");
  PF ("    msg = egg_submit (msg);\n");
  PF ("    break;\n");
  
  PF ("  case egg_warning_kind:\n");
  PF ("    egg_set_fix (&msg, (int(*)(void*))%s%s_fix, loc);\n", prefix, s);
  PF ("    make_%s_warning(&msg, loc, %s, args, 0);\n",
      root, SubMessage_msg (first));
  print_trailing_messages (me, "warning");
  PF ("    msg = egg_submit (msg);\n");
  PF ("    break;\n");
  
  PF ("  case egg_disabled_kind:\n");
  PF ("    if (%s%s_fix) {\n", prefix, s);
  PF ("      egg_set_fix (&msg, (int(*)(void*))%s%s_fix, loc);\n", prefix, s);
  PF ("      msg = egg_submit (msg);\n"
      "    }\n"
      "    break;\n");
}

static void
implement_funcs_Message (Message me)
{
  char *s, *type;

  s = Ident_name (Statement_id (me));
  type = get_group_type (me);
  PF ("int\n"
      "%s%s (%s loc, ...)\n"
      "{\n",
      prefix, s, type);
  PF ("  va_list args;\n"
      "  egg_msg msg = NULL;\n\n"
      "  va_start (args, loc);\n"
      "  switch (%s%s_mode) {\n", prefix, s, s);
  print_cases (me);
  PF ("  default: \n"
      "    fe_abort (\"unexpected egg error mode\");\n"
      "  }\n"
      "  va_end (args);\n"
      "  return %s%s_mode==egg_error_kind;\n"
      "}\n\n", prefix, s);    
}

/* ----------------------------------------------------------------------------
 * Generate the message mode setting option parser
 */
static void
parse_options_Pre_Group (Group me)
{
  if (Statement_fatal (me)) return;
  if (!Group_group (me)) return;
  PF ("{\n");
  indent += 2;
}

static void
parse_options_Post_Group (Group me)
{
  if (Statement_fatal (me)) return;
  if (!Group_group (me)) return;
  PF ("if (strcmp (name, \"%s\")==0) {\n", Ident_name (Statement_id (me)));
  PF ("  %sset_%s_mode (m);\n", prefix, Ident_name (Statement_id (me)));
  PF ("  return 1;\n");
  PF ("}\n");
  indent -= 2;
  PF ("}\n");
}

static void
parse_options_Message (Message me)
{
  if (Statement_fatal (me)) return;
  PF ("if (strcmp (name, \"%s\")==0) {\n", Ident_name (Statement_id (me)));
  PF ("  %sset_%s_mode (m);\n", prefix, Ident_name (Statement_id (me)));
  PF ("  return 1;\n");
  PF ("}\n");
}

static void
parse_cli_options(egg root)
{
  List_Statement gs;
  
  for (gs = egg_groups (root); gs; gs = List_Statement_next (gs)) {
    Group g = List_Statement_data (gs);
    char *name = Ident_name (Statement_id (g));
    PF ("int\n"
        "%s%s_parse_option (char *name, char *mode)\n"
        "{\n",
        prefix,
        name);
    indent+=2;

    PF ("egg_msg_kind m;\n");
    PF ("if (strcmp (mode, \"error\")==0) m = egg_error_kind;\n");
    PF ("else if (strcmp (mode, \"warning\")==0) m = egg_warning_kind;\n");
    PF ("else if (strcmp (mode, \"disabled\")==0) m = egg_disabled_kind;\n");
    PF ("\n");
    Traverse_void_Statement (g, &parse_options);
    PF ("  return 0;\n");
    indent-=2;
    PF ("}\n\n");
  }
}

static void
declare_parse_option(egg root)
{
  List_Statement gs;
  
  for (gs = egg_groups (root); gs; gs = List_Statement_next (gs)) {
    Group g = List_Statement_data (gs);
    PF ("int %s%s_parse_option (char *name, char *mode);\n",
        prefix, Ident_name (Statement_id (g)));
  }
}

/* ----------------------------------------------------------------------------
 * Generate the message mode setting lister
 */
static int
list_options_Statement (Statement me, int ind)
{
  if (Statement_fatal (me)) return ind;
  if (Statement_tag (me) == Group_kind) {
    if (!Group_group (me)) return ind;
    PF ("  printf (\"%*s%-40s\\n\");\n",
        ind,"",
        Ident_name (Statement_id (me)));
    ind+=2;
  } else {  
    PF ("  printf (\"%*s%-*s  %%s\\n\", egg_msg_name(%s%s_mode));\n",
        ind," ",
        40-ind, Ident_name (Statement_id (me)),
        prefix, Ident_name (Statement_id (me)));
  }
  return ind;
}

static void
gen_list_options(egg root)
{
  List_Statement gs;
  
  for (gs = egg_groups (root); gs; gs = List_Statement_next (gs)) {
    Group g = List_Statement_data (gs);
    PF ("void\n"
        "%s%s_list_options (void)\n"
        "{\n",
        prefix, Ident_name (Statement_id (g)));
    Traverse_Statement (g, &list_options, 0);
    PF ("}\n\n");
  }
}

static void
declare_list_options(egg root)
{
  List_Statement gs;
  
  for (gs = egg_groups (root); gs; gs = List_Statement_next (gs)) {
    Group g = List_Statement_data (gs);
    PF ("void %s%s_list_options (void);\n",
        prefix, Ident_name (Statement_id (g)));
  }
}

static void
init_traversals (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;

  /* .h */
  declare_mode_funcs.action_Statement [PRE_ACTION] = declare_mode_funcs_Statement;
  declare_fixes.action_Message [PRE_ACTION]        = declare_fixes_Message;
  declare_funcs.action_Message [PRE_ACTION]        = declare_funcs_Message;
  
  /* .c */
  define_modes.action_Message [PRE_ACTION]         = define_modes_Message;
  impl_mode_funcs.action_Message [PRE_ACTION]      = impl_mode_funcs_Message;
  impl_mode_funcs.action_Group [PRE_ACTION]        = impl_mode_funcs_Group;
  impl_msg_funcs.action_Declaration [PRE_ACTION]   = impl_msg_funcs_Declaration;
  implement_funcs.action_Message [PRE_ACTION]      = implement_funcs_Message;

  parse_options.action_Group [PRE_ACTION]          = parse_options_Pre_Group;
  parse_options.action_Group [POST_ACTION]         = parse_options_Post_Group;
  parse_options.action_Message [PRE_ACTION]        = parse_options_Message;

  list_options.traversal                           = Traverse_Down;
  list_options.action_Statement [PRE_ACTION]       = (void*)list_options_Statement;
}

static void
start_c(char *name)
{
  char *s = fe_strcat (name, ".c");
  outfs = fopen (s, "w");
  fe_free (s);
  PF ("#include <stdlib.h>\n", name);
  PF ("#include <stdarg.h>\n", name);
  PF ("#include <string.h>\n", name);
  PF ("#include <stdio.h>\n", name);
  PF ("#include \"%s.h\"\n", name);
  PF ("#include \"front/error.h\"\n");
  PF ("#include \"front/egg_msg.h\"\n");
}

static void
end_c (char *name)
{
  NOT_USED(name);
  fclose (outfs);
}

static void
start_h(char *name, egg root)
{
  char *s = fe_strcat (name, ".h");
  char *uid = fe_basename(name);
  unsigned int i;
  for (i=0; i<strlen(uid); i++) {
    if (uid[i] == '.') {
      uid[i] = '\0';
      break;
    }
  }
  outfs = fopen (s, "w");
  fe_free (s);
  /* add pointer to ifdef to make it slightly unique */
  PF ("#ifndef _egg_%s_%p_h\n", uid, name);
  PF ("#define _egg_%s_%p_h\n\n", uid, name);
  PF ("#include \"front/egg_msg.h\"\n\n");
  include_uses (egg_uses (root));
}

static void
end_h (char *name)
{
  char *uid = fe_basename(name);
  unsigned int i;
  for (i=0; i<strlen(uid); i++) {
    if (uid[i] == '.') {
      uid[i] = '\0';
      break;
    }
  }
  PF ("\n#endif /* _egg_%s_%p_h */\n", uid, name);
  fclose (outfs);
}

void
gen_messenger(char *name, char *p, egg root)
{
  init_traversals ();
  
  if (p != NULL) {
    strncpy ( prefix, p, EGG_MAX_PREFIX_LENGTH);
    prefix[EGG_MAX_PREFIX_LENGTH-1] = '\0';
  }

  start_h (name, root);
  PF ("\n");
  Traverse_void_egg (root, &declare_mode_funcs);
  PF ("\n");
  Traverse_void_egg (root, &declare_fixes);
  PF ("\n");
  Traverse_void_egg (root, &declare_funcs);
  PF ("\n");
  declare_parse_option (root);
  declare_list_options (root);
  end_h (name);
  
  start_c (name);
  Traverse_void_egg (root, &define_modes);
  PF ("\n");
  Traverse_void_egg (root, &impl_msg_funcs);
  Traverse_void_egg (root, &impl_mode_funcs);
  Traverse_void_egg (root, &implement_funcs);
  parse_cli_options (root);
  gen_list_options (root);
  end_c (name);
}
