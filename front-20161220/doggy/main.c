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
#include <unistd.h>
#include <string.h>
#include <front/hash.h>
#include <front/error.h>
#include <front/scan_support.h>
#include "Types.h"
#include "GenCode.h"
#include "flags.h"

#define USAGE "doggy [-w] [-allow_undeclared_ops] [-f filename] [-i id] [-search_ops] [-o file_name] [-gen_test]"


int main (int argc, char **argv)
{
  parse_flags (argc, argv);
  
  count_chars = TRUE;
  start_doggy (input_file);
  
  if (NumErrors > 0) {
    if (outfile != NULL) unlink (outfile);
    exit (1);
  }
  
  out = stdout;
  if (outfile != NULL) {
    out = fopen (outfile, "w");
  }
  if (out == NULL) {
    FrontError (TRUE, "Cannot open output file");
    exit (1);
  }
  Gen_code (search_ops, gen_test, id_string);
  fclose (out);
  
  if (NumErrors > 0) {
    if (outfile != NULL) unlink (outfile);
    exit (1);
  }
  return 0;
}

