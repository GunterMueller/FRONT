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
#include <stdlib.h>
#include "front.h"
#include "GenCode.h"
#include "frontPrint.h"
#include "GenTypes.h"
#include "GenSubParse.h"
#include "GenDoggy.h"
#include "GenLex.h"
#include "GenGrammar.h"
#include "GenPrint.h"
#include "GenDump.h"
#include "GenBdump.h"
#include "GenDiagrams.h"
#include "GenLalr.h"
#include "flags.h"
#include "print_types.h"

/* Generate all output files */
void Gen_code (front_front root)
{
  Types types;
  List_struct_type str_types;
  
  types = GenTypes (root, &str_types);
  
  check_types (root);
  if (NumErrors > 0) exit (1);

  MakeLex     (root);

  if (!nocode) {
    PrintTypes   (root, types, str_types);  
    GenGrammar   (root);
    GenLex       (root);
    GenSubParse  (root);
    GenDoggy     (types);
    GenPrint     (types);
    GenDump      (types);
    GenBdump     (types, str_types);
    GenLalr      (all_rules);
    close_abbrev (); /* opened in GenTypes */
  }
  if (diagrams)    GenDiagrams (root);
  if (NumErrors > 0) exit (1);
}
