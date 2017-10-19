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
#include <stdio.h>
#include <front/error.h>
#include <front/flags.h>
#include <front/filename.h>
#include "init.h"
#include "messenger.h"

static char *prefix = "";
static char *infile = NULL;
static char *outfile = NULL;
static Bool use_stdin = FALSE;

static int set_prefix(int argc, char *argv[]);
static int set_output(int argc, char *argv[]);

fe_cli_flag egg_flags[] = {
  { "-h",      NULL,        fe_help_flag, DFLT_NAME,     { "display help message" } },
  { "-P",      NULL,        set_prefix,   "-P <PREFIX>", { "at prefix to global identifiers" } },
  { "-o",      NULL,        set_output,   "-o <file>",   { "write output to <name>.c and <name>.h" } },
  { "-",   &use_stdin,      NULL,         DFLT_NAME,     { "use stdin as input (this requires -o)" } },
};
int num_egg_flags = sizeof(egg_flags)/sizeof(egg_flags[0]);

static int
set_output(int argc, char *argv[])
{
  if (argc < 2) {
    FrontError (TRUE, "Missing output file name");
  } else {
    outfile = argv[1];
  }
  return 1;  
}

static int
set_prefix(int argc, char *argv[])
{
  if (argc < 2) {
    FrontError (TRUE, "Missing prefix name");
  } else {
    prefix = argv[1];
  }
  return 1;  
}


static void
parse_flags (int argc, char **argv)
{
  fe_package="egg";
  fe_register_flags (num_egg_flags, egg_flags);
  argc=fe_parse_flags(argc,argv);
  if(argc>1) {
    infile = argv[1];
    if (!outfile) outfile = fe_dropext (fe_basename (infile));
  }
}

/* Error message Generator Generator */
int
main (int argc, char **argv)
{
  egg_initialize ();
  parse_flags      (argc, argv);

  if (!infile && !(use_stdin && outfile)) fe_usage ();
  assert (outfile);
  if (egg_Parse (infile)) {
    gen_messenger (outfile, prefix, egg_root);
  }
  return NumErrors!=0;
}
