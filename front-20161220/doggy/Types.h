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
#ifndef _Types
#define _Types

typedef void *DEP;
typedef void *REG;
typedef void *OPR;
typedef void *EDGE;

typedef struct {
  struct Type *type;
  union {
    DEP dep;
    int i;
    float f;
    double d;
    char *l;
    Bool b;
    REG r;
    OPR o;
    void *other;
  } u;
} VALUE;

#define dep_val(v) ((v).u.dep)
#define int_val(v) ((v).u.i)
#define bool_val(v) ((v).u.b)
#define opr_val(v) ((v).u.o)
#define float_val(v) ((v).u.f)
#define double_val(v) ((v).u.d)
#define reg_val(v) ((v).u.r)
#define lab_val(v) ((v).u.l)
#define other_val(v) ((v).u.other)

#include "doggy.h"

/* Constant types */
extern Type dep_type, int_type, opr_type, bool_type, list_type, string_type, null_type, void_type;
extern Bool type_conflict  (Type t, Type u);
extern Bool types_conflict (List_Type t, List_Type u);

/* Can coerce u into t */
extern Bool can_coerce  (Type t, Type u);

/* return i-th elem of l */
extern Type type_elem (List_Type l, int i);

/* L contains T */
extern Bool type_has (List_Type l, Type t);

/* t is a sub type of u */
extern Bool sub_type (Type t, Type u);

/* Normalize t */
extern Type norm_type (Type t);

extern VALUE NoValue (void);

/* Test for dep type */
extern Bool isdeptype (Type t);

/* Test for list type */
extern Bool is_list_id (Ident id);
extern Bool is_listtype (Type t);

/* Test for OPR type */
extern Bool is_opr_type (Type t);

extern int compare_types (List_Type t, List_Type u);

/* Module initialization */
extern Bool init_types (void);

#ifdef DOGGY
extern Bool typepair_conflict (TypePair t, TypePair u);
extern Bool typepairs_conflict (List_TypePair t, List_TypePair u);
extern Bool types_pair_conflict (List_Type t, List_TypePair u);

/* return type of e */
extern Type expr_type (Expr e);

/* Type of argument i of binary operator op with result type r */
extern Type bin_type (Operator op, Type r, int i);

/* Type of argument of monadic operator op with result type t */
extern Type mon_type (MonOp op, Type t);

/* Get the node type of operation definition F */
extern Type Operation_def_node_type(Operation_def f);

/* Argument types of a function */
extern List_Type Arg_types (Func f);

/* Type of argument, defaults to dep */
extern Type Argument_type (Argument a);

/* Type of tuple element at index I */
extern Type TupleType_index(Type t, int i);

/* Argument type of a list type */
extern Type arg_type(Type t);

/* Type of pattern, defaults to dep */
extern Type Pat_type (Pattern p);

/* Fill in the types for the pattern of scope s*/
extern void Set_pattern_types (doggy_Scope s);

/* Return the root of a (constructor) type t */
extern Type Root (Type t);

/* If e or d has an OPR type, return the arg types */
extern List_Type _get_def_types (Expr e);
extern List_Type  get_def_types (Definition d);

extern Bool allows_null (Type t); 

extern char* unstring (char *name); /* Remove string quotes */
extern char* find_type_name (Type t, char *name);

#endif /* DOGGY */

#endif /* _Types */
