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
#include "egg.h"
#include "init.h"

static struct s_egg_TraverseTable set_parent;
static struct s_egg_TraverseTable propagate_fatal;

static Statement
set_parent_Statement (Statement me, Statement parent)
{
  Statement_parent (me) = parent;
  return me;
}

static Statement
set_parent_Declaration(Declaration me, Statement group)
{
  if (me) Declaration_group (me) = group;
  return group;
}

static Bool
propagate_fatal_Pre_Statement (Statement me, Bool fatal)
{
  fatal |= Statement_fatal (me);
  Statement_fatal (me) = fatal;
  if (Statement_tag(me) == Group_kind) {
    Statement_fatal (me) = TRUE;
  } 
  return fatal;
}

static Bool
propagate_fatal_Post_Statement (Statement me, Bool fatal)
{
  if (!Statement_fatal (me) && Statement_parent (me)) {
    Statement_fatal (Statement_parent (me)) = FALSE;
  }
  return fatal;
}

static void
init_traversals (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;

  set_parent.traversal                     = Traverse_Down;
  set_parent.action_Statement [PRE_ACTION] = (void*)set_parent_Statement;
  set_parent.action_Declaration [PRE_ACTION]  = (void*)set_parent_Declaration;

  propagate_fatal.traversal                     = Traverse_Down;
  propagate_fatal.action_Statement [PRE_ACTION] = (void*)propagate_fatal_Pre_Statement;
  propagate_fatal.action_Statement [POST_ACTION] = (void*)propagate_fatal_Post_Statement;
}

static void
egg_decorate (egg root)
{
  init_traversals ();
  Traverse_egg (root, &egg_scope_actions, NULL);
  Traverse_void_egg (root, &egg_defining_actions);
  Traverse_void_egg (root, &egg_applied_actions);

  Traverse_egg (root, &set_parent, NULL);
  Traverse_egg (root, &propagate_fatal, FALSE);
}

void
egg_initialize(void)
{
  Extend_namespaces (egg_NUM_NAMESPACES, egg_namespaces);
  Make_identifier_table ();
}

egg
egg_Parse (const char *filename)
{
  extern int egg_restart (FILE *);
  extern int egg_parse (void);
  extern FILE *egg_in;
  
  if (!filename) {
    egg_in = stdin;
    scan_init ("<stdin>");
  } else {
    egg_in = fopen(filename,"r");
    scan_init ((char*)filename);
  }
  egg_restart (egg_in);
  egg_parse ();
  if(NumErrors>0) return NULL;
  egg_decorate (egg_root);
  return egg_root;
}
