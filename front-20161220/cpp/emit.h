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

#ifndef _cpp_emit_h
#define _cpp_emit_h

#include <stdio.h>
#include "token.h"
#include "sequence.h"
#include "pp.h"

extern int FilePos;
extern int emit_to_original_loc;

char *text_tokens (tokens ts);

void emit_tokens(FILE *fs, tokens ts);
void emit_tokens_optimized (FILE *fs, tokens ts);
int  emit_fill(char *buf, int max);
void start_fill(tokens ts);
#if 0
void continue_fill(sequence sq);
#endif
token find_token(int loc);

#endif /* _cpp_emit_h */
