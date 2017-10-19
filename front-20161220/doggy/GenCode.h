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
#include <stdio.h>
#include "doggy.h"

/* output file, default is stdout */
extern FILE *out;
extern char *opt_name;
extern char *opt_rule_id;
extern List_ActualOp supported_mops;
extern List_ActualOp all_mops;

extern List_List_TypePair split_formals (List_Applied_formal l);
extern int arg_mask (List_Pattern l, int i);
extern int add_carry (int *a, int c, int n);
extern Bool commutative (Operation_def f);
extern Bool is_targ (Operation_def def);
extern List_Expr ExprGuard_body (Guard g);

extern int doggy_parse (void);
extern void start_doggy (char *fn);

/* Generate code in file out */
extern void Gen_code (Bool search_ops, Bool gen_test, char *id);
