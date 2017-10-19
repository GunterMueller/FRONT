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
#include <cpp.h>

#include <front/hash.h>
#include "config.h"
#include "front.h"
#include "Types.h"
#include "grammar.h"
#include "pictures/Pictures.h"
#include "Lalr.h"
#include "front_end.h"
#include "frontPrint.h"
#include "front_lalr.h"

#define front_input front_in
extern FILE *front_input;

extern int front_parse (void);
extern int front_restart (FILE *);

static struct s_front_TraverseTable set_grammar;

/* Initialize front library */
static void
initialize (void)
{  
  Extend_namespaces (front_NUM_NAMESPACES, front_namespaces);
  Extend_namespaces (Types_NUM_NAMESPACES, Types_namespaces);
  Extend_namespaces (grammar_NUM_NAMESPACES, grammar_namespaces);
  Extend_namespaces (Pictures_NUM_NAMESPACES, Pictures_namespaces);
  Extend_namespaces (Lalr_NUM_NAMESPACES, Lalr_namespaces);
  Make_identifier_table ();
}

static void
set_grammar_ImportedNonTerminal (ImportedNonTerminal me, Import importer)
{
  ImportedNonTerminal_grammar (me) = Import_grammar (importer);
}

static void
init_traversals (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;

  set_grammar.traversal = Traverse_Down;
  set_grammar.action_ImportedNonTerminal [PRE_ACTION] = set_grammar_ImportedNonTerminal;
  set_grammar.action_Import [PRE_ACTION] = Return_Node;
}

/* parse front file and build front AST */
front_front
parse_front (char *infile)
{
  initialize ();
  
  if (!infile) return NULL;
  CPP_preprocess(infile);
  egg_exit_on_errors ();

  front_input = NULL;
  CPP_set_location (input_size);
  scan_init ((char*)infile);

  front_restart (front_input);

  if (USE_FRONT_LALR_PARSER) {
    Parse_state_front (); /* Own parser */
  } else {
    front_parse (); /* Yacc */
  }
  init_traversals ();
  Traverse_front_front (front_root, &set_grammar, NULL);
  if (NumErrors > 0) exit (1);
  return front_root;  
}
