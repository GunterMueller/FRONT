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
#ifndef _GENGRAMMAR_H
#define _GENGRAMMAR_H
 
#include "front.h"
#include "grammar.h"

extern List_ProdRule prod_rules;  /* Production rules not non-terminals */
extern List_ProdRule extra_rules; /* Extra rules for sequences, etc */
extern List_ProdRule all_rules;   /* prod_rule+extra_rules */

/* get the initialization for F during WHEN */
FieldInit Field_init_when (Field f, FieldInit_tag when);

/* A = rhs */
extern Bool is_macro (NonTerminal nt);

/* A : B ::= rhs */
extern Bool no_nt_type (NonTerminal nt);

/* Check for no alternatives */
extern Bool no_nt_alts (NonTerminal nt);

/* Rhs r always generates the empty string */
extern Bool is_empty (Rhs r);

/* Symbol s always generates the empty string */
extern Bool is_empty_sym (Symbol s);

/* Check whether the applied symbol app is overloaded */
extern Bool applied_overloaded (Symbol app);

/* s contains just layout */
extern Bool is_layout (Symbol s);

/* s is of the form [ t ]! */
extern Bool is_inlined_opt (Symbol s);

/* Construct the symbol name the Symbol s */
extern String symbolname  (Symbol s);

/* Find a defining symbol within nt or alt */
extern Symbol find_defining (NonTerminal nt, Alternative alt);

/* Flatten recursively occurring SymbolSeq's into one list of Symbols */
extern List_Symbol flatten_syms (List_Symbol l);

/* Flatten recursively occurring SymbolSeq's into one list of Symbols */
extern List_Symbol flatten_sym (Symbol s);

/* Get the fields from s and remove initialized fields */
extern List_field get_fields (Symbol s);
/* Get the fields from l and remove initialized fields */
extern List_field get_syms_fields (List_Symbol l);
/* Remove initialized fields */
extern List_field clean_fields (List_field l);

/* Return the type of a NonTerminal or Alternative, id holds the name of the type */
extern struct_type nonterm_type (NonTerminal nt, Alternative alt, Ident *id);

/* Apply token_op to every terminal Token.
   Apply rule_op  to every non-terminal ProdRule.
*/
extern void 
for_all_rules (void (*token_op) (Token),
	       void (*rule_op)  (ProdRule));

/* Checks whether to generate an extra rule */
Bool valid_extra (ProdRule r);

extern void GenGrammar (front f);
 
#endif /* _GENGRAMMAR_H */
                                                                                
