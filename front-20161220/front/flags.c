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
#include <stdio.h>
#include <string.h>

#include <front/flags.h>
#include <front/filename.h>
#include <front/basic_types.h>
#include <front/error.h>
#include <front/scan_support.h>
#include <pictures/Picture.h>
#include <cpp.h>

#include "flags.h"
#include "GenDiagrams.h"

#define front_input front_in
extern FILE *front_input;

Bool doggy		= FALSE;
Bool be_hook		= FALSE;
Bool scope		= FALSE;
Bool genpretty		= FALSE;
Bool preserve_comment	= FALSE;
Bool no_share_fields	= FALSE;
Bool user_fields	= FALSE;
Bool gendump		= FALSE;
Bool bdump		= FALSE;
Bool nocode		= FALSE;
Bool no_lalr		= FALSE;
Bool LeftRecursive      = FALSE;

String multi_start	= NULL;
String prefix		= NULL;

static int set_multi_start  (int argc, char **argv);
static int set_prefix       (int argc, char **argv);


/* Table of command switches */

static fe_cli_flag cli_flags[] = {
  { "-w",                &NoWarnings, NULL,         DFLT_NAME, { "disable warnings" } },
  { "-doggy",            &doggy     , NULL,         DFLT_NAME, { "Generate doggy interface." } },
  { "-back-end-hooks",   &be_hook   , NULL,         DFLT_NAME, { "Generate back-end hooks in AST." } },
  { "-scope",            &scope     , NULL,         DFLT_NAME, { "Add scope fields." } },
  { "-genpretty",        &genpretty , NULL,         DFLT_NAME, { "Generate pretty printer." } },
  { "-gendump",          &gendump   , NULL,         DFLT_NAME, { "Generate dump traversal." } },
  { "-bdump",            &bdump     , NULL,         DFLT_NAME, { "Generate binary dump traversal." } },
  { "-no-code",          &nocode    , NULL,         DFLT_NAME, { "Suppress code generation." } },
  { "-preserve-comment", &preserve_comment , NULL,  DFLT_NAME, { "Make scanner preserve comments for later use." } },
  { "-no-share-fields",  &no_share_fields  , NULL,  DFLT_NAME, { "Do not share common fields among subtypes." } },
  { "-user-fields",      &user_fields , NULL,       DFLT_NAME, { "Add the macro USER_FIELDS to all types." } },
  { "-no-lalr",          &no_lalr   , NULL,         DFLT_NAME, { "Do not generate lalr parser." } },
  { "-left-recursive",   &LeftRecursive, NULL, "-left-recursive", { "use left-recursive rules"}  },
  { "-prefix",           NULL, set_prefix, "-prefix <string>", { "Use <string> as prefix for all identifiers." } },
  { "-multi-start",      NULL, set_multi_start, "-multi_start <string>", { "Use multiple start symbols." } },
  { "-h",                NULL, fe_help_flag,         DFLT_NAME, { "Show this help message." } },
};

static const int num_cli_flags=(sizeof(cli_flags) / sizeof(*cli_flags));

/* Actions other than boolean setting */

static int set_multi_start (int argc, char **argv)
{ 
  if (argc < 2) {
    FrontError (TRUE, "Missing multi_start argument");
  } else {
    multi_start = argv[1];
  }
  return 1;
}

static int set_prefix (int argc, char **argv)
{ 
  if (argc < 2) {
    FrontError (TRUE, "Missing prefix argument");
  } else {
    prefix = argv[1];
  }
  return 1;
}

static Bool error_given = FALSE;

/* Parse all front flags, returns the input filename */
char *
parse_flags (int argc, char **argv)
{
  fe_package = "Front";
  fe_register_flags (num_cli_flags, cli_flags);
  fe_register_flags (num_cli_diagram_flags, cli_diagram_flags);
  fe_register_flags (num_libcpp_flags, libcpp_flags);
  fe_flags_use_regexp ();
  argc = fe_parse_flags(argc, argv);
  if (argc>2) FrontError (TRUE, "Too many input files");
  return argv[1];
}
