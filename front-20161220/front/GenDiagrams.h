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
#ifndef _GENDIAGRAMS_H
#define _GENDIAGRAMS_H

#include <front/flags.h>
#include "front.h"

extern fe_cli_flag cli_diagram_flags[];
const int num_cli_diagram_flags;

/* Generate the Root.ps file for syntax diagrams */
extern void GenDiagrams (front f);
 
#endif /* _GENDIAGRAMS_H */                                                        
