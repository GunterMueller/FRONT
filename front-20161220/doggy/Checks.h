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
#ifndef _Checks
#define _Checks

#include "doggy.h"

#ifdef DOGGY
#define ROOT_TYPE doggy
#else
#define ROOT_TYPE mdt
#endif /* DOGGY */

#define num_negate(x) if (Num_neg(x)) { Num_i(x) = -Num_i(x); }

#define BinPattern(l,a,id,b) \
  ((id)==NULL ? (a) : \
    Create_OpPattern (l, \
      Create_AppliedOp (l, Create_Applied_formal (l, id)), \
      Create_List_Pattern(a, Create_List_Pattern (b, NULL))))

#define IdOpExpr(l,a,op,b) \
  Create_Operation (l, op, \
     Create_List_Expr (a, Create_List_Expr (b, NULL)))

#define ParArg(l,p)  Create_PatArg(l,p)
#define PatArg1(l,p) Create_PatArg(l,p)
#define ParPattern(l,p) (p)
#define IdParPattern(l,id,p) SingleDefPattern (l,id,p)
#define SingleDefPattern(s, id, arg) Create_DefPattern (s, Create_List_Pattern (Create_IdentPattern (s,id), NULL), arg)
  
extern Bool ExtraWarnings;
extern Bool Allow_undeclared_ops;

extern void init_ident_patterns (List_Pattern pids, Pattern pat);

/* Check whether op can be commutative */
extern Bool Comm_conflict (Operation_def op);

/* Fix up of ADT */
extern void Store_md (ROOT_TYPE d);

#ifdef DOGGY
/* Check consistency of function */
extern Bool Func_conflict (Func f);

/* Check consistency of argument */
extern Bool Arg_conflict (Argument a);

/* Check pattern consistency */
extern Bool Pattern_conflict (Pattern p);

/* Check set consistency in set pattern */
extern Bool Pattern_set_conflict (List_Applied_formal l);

/* Type checking of definition */
extern Bool Def_conflict (Definition d);

/* Type checking of call */
extern Bool Call_conflict (Expr e);

/* Type checking of conditions and branches */
extern Bool If_conflict (Expr e);

/* Binary/unary operator type checking */
extern Bool Oper_conflict (Expr e);

/* Check for dep type of guard */
extern Bool NonDepType (Guard g);

/* If a is unsupported, flag this in the rule. */
extern Bool SetSupported (Operation_def f, doggy_Scope s, Bool nil);

/* test if current rule is supported */
extern Bool Supported (doggy_Scope s);

/* Conversions*/
extern Operation_def Get_operation (Applied_formal a);
extern Operation_def Get_applied_op (Applied_operation op);

#endif /* DOGGY */

#endif /* _Checks */
