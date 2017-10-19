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

#ifndef _cpp_define_h
#define _cpp_define_h

typedef struct s_define  *define;
typedef struct s_defines *defines;

#include "token.h"
#include "sequence.h"

void init_define(void);
void clear_define(void);
void new_alias (token id, tokens repl);
void new_macro (token id, tokens args, tokens repl);
void remove_define (token id);
void remove_alias (token id);
void remove_macro (token id);
tokens apply_alias (sequence sq, token id);
tokens apply_macro (sequence sq, token id, tokenss args);
int have_alias (token id);
int have_macro (token id);
int have_macro_args(token id, int args);
defines all_defines ();
char *text_define (define def);
char *get_alias (const char *id);

struct s_defines {
  define   head;
  defines  tail;
};

defines new_defines(define head, defines tail);
defines add_define(define def, defines list);
defines append_defs(defines a, defines b);
void enable_defs (defines defs);

#endif /* _cpp_define_h */
