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
#ifndef _GENLEX_H
#define _GENLEX_H
 
#include "front.h"
#include "grammar.h"

extern List_Token fixed_tokens;	/* Tokens with a fixed representation */
extern List_Token var_tokens;	/* Tokens with a variable representation */

/* Find a token in the list of standard tokens */
extern Token is_std_sym (Ident id);

/* Return the terminal name of symbol, "" for non-terminals */
extern String term_name (Symbol s);

/* Create representation for a literal symbol */
extern String term_repr (Symbol s);

/* Create the data structure for the lexical tokens */
extern void MakeLex (front f);

/* Generate the lex file */
extern void GenLex (front f);
 
#endif /* _GENLEX_H */
                                                                                
