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

#ifndef _cpp_pp_h
#define _cpp_pp_h

#include "file.h"
#include "token.h"
#include "sequence.h"

extern int deep_location;
extern int visual_studio_compatible;
extern int cpp_inhibit_expansion;
extern int cpp_inhibit_linemarkers;
extern int cpp_gnu;

tokens read_file(File file, int sysfile);
void pp_sequence(sequence sq);

#ifdef AMBER
void pp_pragmas(tokens *ts);
#endif

#endif /* _cpp_pp_h */
