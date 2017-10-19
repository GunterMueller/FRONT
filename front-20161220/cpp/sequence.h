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

#ifndef _cpp_sequence_h
#define _cpp_sequence_h

typedef struct s_sequence *sequence;

#include <stdio.h>
#include "token.h"

struct s_sequence {
  tokens start;
  tokens in;
  tokens out;
  int    eval_defined;
};

sequence new_sequence(tokens start, int eval_defined);
sequence tmp_sequence(tokens start, int eval_defined);
void insert_tokens(sequence sq, tokens begin);
token next_token(sequence sq);
token peek_token(sequence sq);
token peek_text_token(sequence sq);
token this_token(sequence sq);
token out_token(sequence sq);
void pass(sequence sq);
void pass_all(sequence sq);
void print_sequence(sequence sq);

#endif /* _cpp_sequence_h */
