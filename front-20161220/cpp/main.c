/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <front/mem.h>
#include <front/flags.h>
#include <front/error.h>
#include "errors.h"
#include "cpp.h"

static int success = 1;
static char *outfile = NULL;
static Bool list_defines = FALSE;
static Bool list_incpaths = FALSE;

#define _STR(x) # x
#define STR(x) _STR(x)

static int set_output  (int argc, char *argv[]);
static int original_loc(int argc, char *argv[]);
static int visual_studio(int argc, char *argv[]);

fe_cli_flag cpp_flags[] = {
  { "-h", NULL,	      fe_help_flag,   DFLT_NAME,   { "display help message" } },
  { "-o", NULL,	      set_output,     "-o <file>", { "write output to <file>" } },
  { "-ol", NULL,      original_loc,   DFLT_NAME,   { "emit tokens to original location"} },
  { "-vs", NULL,      visual_studio,  DFLT_NAME,   { "visual studio message format"} },
  { "-list-defines", &list_defines, NULL, DFLT_NAME, { "list all #defines and #undefs on stderr" } },
  { "-list-incpaths", &list_incpaths, NULL, DFLT_NAME, { "list all (standard, implied, and -I) include paths on stderr" } },
};

const int num_cpp_flags=(sizeof(cpp_flags) / sizeof(*cpp_flags));

/* ------------------------------------------------------------------------- */
static int
original_loc(int argc, char *argv[])
{
  NOT_USED(argc);
  NOT_USED(argv);
  CPP_original_location();
  return 0;
}

/* ------------------------------------------------------------------------- */
static int
visual_studio(int argc, char *argv[])
{
  NOT_USED(argc);
  NOT_USED(argv);
  CPP_visual_studio();
  return 0;
}

/* ------------------------------------------------------------------------- */
static int
set_output(int argc, char *argv[])
{
  if (argc < 2) cpp_missing_argument(NULL, argv[0]);
  else  outfile = argv[1];
  return 1;  
}

/* ----------------------------------------------------------------------------
 * Parse the command line
 */
static void
parse_options (int argc, char *argv[])
{
  int i;
  fe_register_flags (num_libcpp_flags, libcpp_flags);
  fe_register_flags (num_cpp_flags, cpp_flags);
  fe_flags_use_regexp ();
  argc = fe_parse_flags (argc, argv);
  
  for(i=1; i<argc; i++) {
    CPP_cli_include(argv[i]);
  }
}

/* ----------------------------------------------------------------------------
 * C Pre-Processor
 */
int
main(int argc, char *argv[])
{
  FILE *out = stdout;
  
  CPP_initialize();
  CPP_predefines(1);

  parse_options (argc, argv);
  if (!success) return 0;

  CPP_std_include_path ();
  if (list_incpaths)
    CPP_list_incpaths ();

  if (outfile) {
    /* open in bin mode to prevent \n -> \r\n translation; 
       \r is already present from reading in bin mode 
    */
    out = fopen(outfile, "wb");
    if (!out) perror ("cpp");
  }
 
  if (!CPP_preprocess (NULL)) return 1;
  CPP_emit (out);

  if (list_defines)
    CPP_list_defines ();

  return 0;
}
