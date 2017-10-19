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
#include <front/basic_types.h>

extern char *outfile;

extern Bool doggy;		/* Generate doggy API */
extern Bool no_share_fields;	/* Don't move common fields to super-type */
extern Bool scope;		/* Add scope field to all types */
extern Bool user_fields;	/* Add USER_FIELDS to all types */
extern Bool be_hook;		/* Add hook field  to all types */
extern Bool gendump;		/* Generate dump generator */
extern Bool bdump;		/* Generate binary dump traversals */
extern Bool nocode;		/* Suppress code generation */
extern Bool diagrams;		/* Generate syntax diagrams */
extern Bool no_lalr;		/* Do not generate lalr parser */
extern Bool LeftRecursive;      /* use left-recursive rules */

extern String multi_start;	/* Used as prefix for multi-start parser */
extern String prefix;		/* Prefix for all generated identifiers */

/* Parse all front flags, returns the input filename */
extern char *parse_flags (int argc, char **argv);

