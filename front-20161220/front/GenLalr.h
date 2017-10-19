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
#ifndef _gen_lalr_h
#define _gen_lalr_h

#include "grammar.h"
#include "Lalr.h"

typedef List_Ident TermSet; /* Set of terminal symbols */

extern List_LR_Symbol all_symbols; /* All terminal and non-terminal symbols */

/* Element test */
#define term_contains(s,x) FRONT_CONTAINS(s,x)
/* Set union */
TermSet term_union (TermSet a, TermSet b);
/* a := a + b */
TermSet term_unite (TermSet a, TermSet b);

void print_terms (TermSet f);

/* Create a (unique) LR_Symbol with fields f */
LR_Symbol make_lr_symbol (Ident id, List_field f, Bool e);
/* List concatenation */
LR_Symbols append_lr_symbols (LR_Symbols l, LR_Symbols m);

Bool is_terminal (LR_Symbol s);  /* Test for terminal symbol */
Bool can_be_empty (LR_Symbol s); /* Test for emptiness */
Bool emptiness (LR_Symbols l);   /* Test for emptiness */
Bool is_start (Item i);		 /* A -> .a for start symbol A */
Bool is_kernel (Item i);	 /* A -> a.b, a non-empty */
Bool is_completed (Item i);	 /* A -> a. */

/* Followers (l, f) = first(l) + (f if can_be_empty l) */
TermSet followers (LR_Symbols l, TermSet f);

/* Numbering of rhs */
Int New_rhs_num (void);

/* Create Lalr object and generate code for it */
Lalr GenLalr (List_ProdRule l);

#endif /* _gen_lalr_h */
