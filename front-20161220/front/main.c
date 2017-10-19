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

#include "Checks.h"
#include "flags.h"
#include "front_end.h"
#include "GenCode.h"
#include "Types.h"

int
main (int argc, char **argv)
{
  front_front root;
  char *infile;

  infile = parse_flags (argc, argv);
  if (!infile) {
    FrontError (TRUE,"No input file specified");
  }
  root = parse_front (infile);
  check_front (root);
  if (NumErrors > 0) exit (1);
  
  
  Gen_code (root);
  
  return 0;
}
