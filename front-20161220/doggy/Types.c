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
#include <assert.h>
#include <string.h>

#include "doggy.h"
#include "Types.h"

/* Global variables */

Type list_type;
Type dep_type;
Type int_type;
Type opr_type;
Type bool_type;
Type string_type;
Type null_type;
Type void_type;

Ident operator_id, null_id;

/* Element selection */
Type
type_elem (List_Type l, int i)
{
  if (l==NULL) return NULL;
  if (i==0) return List_Type_data(l);
  return type_elem (List_Type_next(l), i-1);
}

Bool
type_has (List_Type l, Type t)
{
  if (l==NULL) return FALSE;
  if (List_Type_data(l)==t) return TRUE;
  return type_has (List_Type_next(l), t);
}

/* Get the node type for F,
   assumption: if we have untyped edges we also have untyped nodes
*/
Type
Operation_def_node_type(Operation_def f)
{
  Type rt = Operation_def_result(f);
  if(!isdeptype(rt)) rt = Create_IdentType (no_srcinfo, Operation_def_id(f));
  if(!rt) rt = dep_type;
  return rt;
}

int compare_types (List_Type t, List_Type u)
{
  if (t==u) return 0;
  
  if (t==NULL) return -1;
  if (u==NULL) return 1;
  if (!type_conflict(List_Type_data(t), List_Type_data(u))) {
    return compare_types (List_Type_next(t), List_Type_next(u));
  }
  return -1;
}

/* Normalize a type, i.e  remove singelton edge types */
Type 
norm_type (Type t)
{
  if (t==NULL) return NULL;
  if (Type_tag(t) == RangeType_kind) return int_type;
  if (Type_tag(t) == FRangeType_kind) return int_type;
  if (Type_tag(t) == EdgeType_kind && 
      List_Type_next(EdgeType_types(t)) == NULL) {
    return norm_type (List_Type_data(EdgeType_types(t)));
  }
  if (Type_tag(t) == TupleType_kind && 
      List_Type_next(TupleType_types(t)) == NULL) {
    return norm_type (List_Type_data(TupleType_types(t)));
  }
  return t;
}

char* unstring (char *s)
{
  if (s == NULL || s[0] != '"') return s;
  s = Front_StrAllocf(&s[1]);
  s[strlen(s)-1] = 0;
  return s;
}

Bool allows_null (Type t)
{
  Typedef td;
  List_Type l;
  
  t = norm_type(t);
  if (t == NULL) return FALSE;
  switch (Type_tag(t)) {
    case PointerType_kind:
      return TRUE;
    case IdentType_kind:
      td = IdentType_type(t);
      if (td == NULL) return FALSE;
      if (Typedef_value(td) == NULL) return FALSE;
      return Make_identifier(unstring (Typedef_value(td))) == null_id;
    case EdgeType_kind:
      for (l = EdgeType_types(t); l != NULL;  l = List_Type_next(l)) {
	if (allows_null(List_Type_data(l))) return TRUE;
      }
      break;
    default:
      break;
  }
  return FALSE;
}

/* Basic type checking function */
Bool
type_conflict (Type t, Type u)
{
  List_Type l, m;
  
  t = norm_type(t);
  u = norm_type(u);
  if (t==u) return FALSE;
  if (t==NULL || u==NULL) return FALSE;
  if (Type_tag(t) != Type_tag(u)) {
    return TRUE;
  }
  if (t==null_type) return !allows_null(u);
  if (u==null_type) return !allows_null(t);
  
  switch (Type_tag(t)) {
    case FRangeType_kind:
    case RangeType_kind:
      return type_conflict (int_type, u);
    case PointerType_kind:
      return type_conflict (PointerType_base(t), PointerType_base(u));
    case IdentType_kind:
      if (IdentType_type(u) == IdentType_type(int_type) && 
	  IdentType_type_id(t) == Make_identifier ("uint")
	 ) return FALSE;
      if (IdentType_type(t) == IdentType_type(int_type) && 
	  IdentType_type_id(u) == Make_identifier ("uint")
	 ) return FALSE;
      return IdentType_type_id(t) != IdentType_type_id(u);
    case EdgeType_kind:
     for (l = EdgeType_types(t),
          m = EdgeType_types(u); 
	  l != NULL && m != NULL; 
	  l = List_Type_next(l),
	  m = List_Type_next(m)) {
       if (type_conflict(List_Type_data(l), List_Type_data(m))) return TRUE;
     }
     return l != m;
    case OprType_kind:
     if (OprType_args(t) == NULL) return FALSE;
     if (OprType_args(u) == NULL) return FALSE;
     for (l = OprType_args(t),
          m = OprType_args(u); 
	  l != NULL && m != NULL; 
	  l = List_Type_next(l),
	  m = List_Type_next(m)) {
       if (type_conflict(List_Type_data(l), List_Type_data(m))) return TRUE;
     }
     return l != m;    
    default:
      break;
    case TupleType_kind:
     for (l = TupleType_types(t),
          m = TupleType_types(u); 
	  l != NULL && m != NULL; 
	  l = List_Type_next(l),
	  m = List_Type_next(m)) {
       if (type_conflict(List_Type_data(l), List_Type_data(m))) return TRUE;
     }
     return l != m;
  }
  return FALSE;
}

/* Coercion of u into t */
Bool 
can_coerce (Type t, Type u)
{
  List_Type l, m;
  
  t = norm_type(t);
  u = norm_type(u);
  if (t==u) return TRUE;
  if (t==NULL || u==NULL) return TRUE;
  if (Type_tag(t) != Type_tag(u)) {
    if (Type_tag(t) == EdgeType_kind) {
     for (l = EdgeType_types(t); l; l = List_Type_next(l)) {
       if (can_coerce(List_Type_data(l), u)) return TRUE;
     }
    }
    if (Type_tag(u) == EdgeType_kind) {
     for (l = EdgeType_types(u); l; l = List_Type_next(l)) {
       if (!can_coerce(t, List_Type_data(l))) return FALSE;
     }
     return TRUE;
    }
    return FALSE;
  }
  
  if (u == null_type && allows_null(t)) return TRUE;
  
  switch (Type_tag(t)) {
    case RangeType_kind:
    case FRangeType_kind:
      return can_coerce (int_type, u);
    case PointerType_kind:
      return can_coerce (PointerType_base(t), PointerType_base(u));
    case IdentType_kind:
      if (IdentType_type(u) == IdentType_type(int_type) && 
	  IdentType_type_id(t) == Make_identifier ("uint")
	 ) return TRUE;
      if (IdentType_type(t) == IdentType_type(int_type) && 
	  IdentType_type_id(u) == Make_identifier ("uint")
	 ) return TRUE;
      if (IdentType_type(u) == IdentType_type(int_type) &&
#if 0
          IdentType_type(t) == IdentType_type(dep_type)
#else
          TRUE /* Assume coercions to and from int */
#endif
	 ) return TRUE;
      if (IdentType_type(t) == IdentType_type(int_type) &&
#if 0
          IdentType_type(u) == IdentType_type(dep_type)
#else
          TRUE /* Assume coercions to and from int */
#endif
         ) return TRUE;
      if (u==string_type && IdentType_type(t)!=NULL) return TRUE;
      return IdentType_type_id(t) == IdentType_type_id(u);
    case EdgeType_kind:
     for (l = EdgeType_types(t),
          m = EdgeType_types(u); 
	  l != NULL && m != NULL; 
	  l = List_Type_next(l),
	  m = List_Type_next(m)) {
       if (can_coerce(List_Type_data(l), List_Type_data(m))) return TRUE;
     }
     return l == m;
    case TupleType_kind:
     for (l = TupleType_types(t),
          m = TupleType_types(u); 
	  l != NULL && m != NULL; 
	  l = List_Type_next(l),
	  m = List_Type_next(m)) {
       if (can_coerce(List_Type_data(l), List_Type_data(m))) return TRUE;
     }
     return l == m;
    case OprType_kind:
     if (OprType_args(t) == NULL) return TRUE;
     if (OprType_args(u) == NULL) return TRUE;
     for (l = OprType_args(t),
          m = OprType_args(u); 
	  l != NULL && m != NULL; 
	  l = List_Type_next(l),
	  m = List_Type_next(m)) {
       if (type_conflict(List_Type_data(l), List_Type_data(m))) return FALSE;
     }
     return l == m;
    default:
      break;
  }
  return TRUE;
}

/* t is a sub-type of u, i.e. included in a edge type set */
Bool 
sub_type (Type t, Type u)
{
  List_Type l;
  
  if (Type_tag(u) != EdgeType_kind) return !type_conflict(t, u);
  
  for (l = EdgeType_types(u); l; l = List_Type_next(l)) {
    if (!type_conflict (t, List_Type_data(l))) return TRUE;
  }
  return FALSE;
}

/* Type checking of type lists */
Bool 
types_conflict (List_Type t, List_Type u)
{
  for (;
       t != NULL && u != NULL;
       t = List_Type_next(t), u = List_Type_next(u)) {
    if (type_conflict(List_Type_data(t), List_Type_data(u))) {
      return TRUE;
    }
  }
  return t != u;
}

Bool 
typepair_conflict (TypePair t, TypePair u)
{ return type_conflict (TypePair_t1(t), TypePair_t1(u)) || 
         type_conflict (TypePair_t2(t), TypePair_t2(u));
}

Bool 
typepairs_conflict (List_TypePair t, List_TypePair u)
{
  for (;
       t != NULL && u != NULL;
       t = List_TypePair_next(t), u = List_TypePair_next(u)) {
    if (typepair_conflict(List_TypePair_data(t), List_TypePair_data(u))) {
      return TRUE;
    }
  }
  return t != u;
}

Bool 
types_pair_conflict (List_Type t, List_TypePair u)
{
  for (;
       t != NULL && u != NULL;
       t = List_Type_next(t), u = List_TypePair_next(u)) {
    if (type_conflict(List_Type_data(t), TypePair_t1(List_TypePair_data(u)))) {
      return TRUE;
    }
  }
  return t != NULL || u != NULL;
}

/* Test for dep type */
Bool isdeptype (Type t)
{
  List_Type l;
  
  if (t==NULL) return TRUE;
  
  switch (Type_tag(t)) {
    case IdentType_kind:
#if 1
      return IdentType_type(t) == IdentType_type(dep_type);
#else
      /* To do: check for type being result of Operationdef's */
      return TRUE;
#endif
    case EdgeType_kind:
      for (l = EdgeType_types(t); l; l = List_Type_next(l)) {
        if (!isdeptype (List_Type_data(l))) return FALSE;
      }
      return TRUE;
    case TupleType_kind:
      for (l = TupleType_types(t); l; l = List_Type_next(l)) {
        if (!isdeptype (List_Type_data(l))) return FALSE;
      }
      return TRUE;
    default:
      return FALSE;
  }
  return FALSE;
}

Bool is_list_id (Ident id)
{
  return strncmp ("List_", IDENT_STRING(id), 5) == 0;
}

/* Test for dep type */
Bool is_listtype (Type t)
{
  List_Type l;
  
  if (t==NULL) return TRUE;
  
  switch (Type_tag(t)) {
    case IdentType_kind:
      return is_list_id (IdentType_type_id(t));
    case EdgeType_kind:
      for (l = EdgeType_types(t); l; l = List_Type_next(l)) {
        if (!is_listtype (List_Type_data(l))) return FALSE;
      }
      return TRUE;
    default:
      return FALSE;
  }
  return FALSE;
}

/* Test for OPR type */
Bool 
is_opr_type (Type t)
{
  switch (Type_tag(t)) {
    case OprType_kind:
      return TRUE;
    case EdgeType_kind:
      if (List_Type_next(EdgeType_types(t)) == NULL) {
        return is_opr_type (List_Type_data(EdgeType_types(t)));
      }
      break;
    default:
      break;
  }
  return FALSE;
}

/* Type of argument i of binary operator op with result type r */
Type
bin_type (Operator op, Type r, int i)
{
  NOT_USED(i);
  switch (op) {
    case CandOp:
    case CorOp:	
      return bool_type;
    case NeqOp:	
    case EqOp:	
      return r;
    case XorOp:	
    case LEOp:	
    case GEOp:	
    case LTOp:	
    case GTOp:	
    case SLOp:	
    case SROp:	
    case DivOp:	
    case ModOp:	
    case MulOp:	
    case AndOp:	
    case AddOp:	
    case SubOp:
      return int_type;
  }
  return NULL;
}

/* Return type of binary operator */
static Type
bin_rtype (Operator op, Type t)
{
  NOT_USED(t);
  switch (op) {
    case CandOp:
    case CorOp:	
    case NeqOp:	
    case EqOp:	
    case LEOp:	
    case GEOp:	
    case LTOp:	
    case GTOp:
      return bool_type;    
    case SLOp:	
    case SROp:	
    case XorOp:	
    case DivOp:	
    case ModOp:	
    case MulOp:	
    case AndOp:	
    case AddOp:	
    case SubOp:
      return int_type;
  }
  return NULL;
}

/* Type of argument of monadic operator op with result type t */
Type
mon_type (MonOp op, Type t)
{
  t = norm_type (t);
  switch (op) {
    case NotOp:	return bool_type;
    case NegOp:	return int_type;
    case AddrOp:  	
       if (t != NULL && Type_tag(t) == PointerType_kind) return (PointerType_base(t));
       return NULL;
    case DerefOp:
       return Create_PointerType (make_src_info(-1),t);
    case PlusOp: return int_type;
    case MinOp:	 return int_type;
  }
  return NULL;
}

/* Return type of unary operator */
static Type
mon_rtype (MonOp op, Type t)
{
  switch (op) {
    case NotOp:	return bool_type;
    case NegOp:	return int_type;
    case AddrOp: 	
       return Create_PointerType (make_src_info(-1),t);
    case DerefOp:
       if (t != NULL && Type_tag(t) == PointerType_kind) return (PointerType_base(t));
       return NULL;
    case PlusOp: return int_type;
    case MinOp:	 return int_type;
  }
  return NULL;
}

Type Pat_type (Pattern p)
{
  Applied_operation op;
  List_Applied_formal l = NULL;
  Type t = dep_type;
  
  if (p == NULL) return t;
  
  switch (Pattern_tag(p)) {
    case ConsPattern_kind:
      return list_type;
    case TypedPattern_kind:
      return TypedPattern_btype(p);
    case DefPattern_kind:
      return Pat_type (DefPattern_arg(p));
    case OpPattern_kind:
      op = OpPattern_op(p);
      switch (Applied_operation_tag(op)) {
        case OpSet_kind:
	  l = OpSet_ops(op);
	  break;
	case AppliedOp_kind:
	  l = Create_List_Applied_formal (AppliedOp_op(op), NULL);
	  break;
        default:
          break;
      }
      break; 
    case IdentPattern_kind:
      { Bind_Operation_def b = Retrieve_Bind (IdentPattern_id(p), NULL, doggy_DefaultNameSpace, Bind_Operation_def_kind); 
        if (b != NULL) { 
	  Operation_def f = (Operation_def)Bind_object(b);                                                                         
	  if (f != NULL) return opr_type;
	}
      }                                                                           
      break;
    default:
      break;
  }
  
  if (l == NULL) return t;
  
  t = NULL;
  
  for (; l; l = List_Applied_formal_next(l)) {
    Operation_def f = Applied_formal_ap(List_Applied_formal_data(l));
    Type u = (f != NULL)?Operation_def_result(f):dep_type;
    
    if (t==NULL) { t = u; continue; }
    if (type_conflict (t,u)) return dep_type;
  }
  
  if (t == NULL) return dep_type;
  
  return t;
}

Type
Argument_type (Argument a)
{ Type t = NULL;
  ArgPat a1;
  if (Argument_tag(a) == TypedArg_kind) return TypedArg_type(a);
  
  a1 = Argument_pat(a);
  switch (ArgPat_tag(a1)) {
    case PatArg_kind:
      if (PatArg_pat(a1) != NULL) t = Pat_type (PatArg_pat(a1));
      break;
    case SetArg_kind:
      return opr_type;
  }
  if (t != NULL) return t;
  return dep_type;
}

/* Argument types of a function */
List_Type 
arg_types (List_Argument l)
{
  Type t;
  
  if (l==NULL) return NULL;
  t = Argument_type (List_Argument_data(l));
  if (t==NULL) t = dep_type;
  return Create_List_Type (t, arg_types (List_Argument_next(l)));
}

/* Argument types of a function */
List_Type 
Arg_types (Func f)
{  
  return arg_types (FuncRule_args(List_FuncRule_data(Func_rules(f))));
}


/* Precedence table of binary operators */
static Operator precedences[]
= { MulOp, DivOp, ModOp, 
    AddOp, SubOp, 
    SLOp,  SROp,
    LEOp,  GEOp, LTOp, GTOp,
    EqOp,  NeqOp,
    AndOp, 
    CandOp,
    CorOp,
    -1
};

/* Convert a sequence of exprs and binary operators into an 
   expression tree.
   The int i is a the precedence level under consideration.
*/
static void
_convert_bin (List_Expr *e, List_Operator *ops, int i)
{
  Operator op = precedences[i];
  Expr b;
  
  if (*ops == NULL) return;
  
  if (List_Operator_data (*ops) != op) {
    _convert_bin (&List_Expr_next(*e), &List_Operator_next(*ops), i);
  } else { 
    b = Create_BinExpr (Expr_src_info(List_Expr_data(*e)), 
	  Create_List_Expr (List_Expr_data(*e), 
	    Create_List_Expr (List_Expr_data (List_Expr_next (*e)), NULL)),
	  Create_List_Operator (op, NULL));
    Expr_scope(b) = Expr_scope(List_Expr_data(*e));
    *e = List_Expr_next(*e);
    List_Expr_data(*e) = b;
    *ops = List_Operator_next(*ops);
    _convert_bin (e, ops, i);
  }
}


/* Convert a sequence of exprs and binary operators into an 
   expression tree, from precedence level i onwards.
*/
static void
convert_bin (List_Expr *e, List_Operator *ops, int i)
{
  if (*ops == NULL || List_Operator_next(*ops) == NULL) return;
  
  _convert_bin (e, ops, i);
  convert_bin (e, ops, i+1);
}

/* Return the type of the operator of e.
   Returns NULL if e has no operator type.
*/
static Type
operator_type (Expr e)
{
  List_Type l;
  
  if (Expr_tag(e) == BinExpr_kind) {
    convert_bin (&BinExpr_args(e), &BinExpr_ops (e), 0);
    e = List_Expr_data(BinExpr_args(e));
  }
  
  l = _get_def_types (e);
  if (l != NULL) return Create_OprType (make_src_info(-1), l);
  
  return NULL;
}

/* Argument type of a list type */
Type arg_type (Type t)
{
  char *s;
  Type u;
  Ident id;
  
  if (t==NULL) return t;
  
  t = norm_type(t);
  if (Type_tag(t) != IdentType_kind) return t;
  if (!is_list_id(IdentType_type_id(t))) return t;
  s = IDENT_STRING(IdentType_type_id(t));
  id = Make_identifier (&s[5]);
  u = Create_IdentType (Type_src_info(t), id);
  *u = *t;
  IdentType_type_id(u) = id;
  /* We should look for the Typedef */
#if 0
  d = doggy_Traverse_copy_Typedef (IdentType_type(t), &doggy_copy_actions);
  Typedef_id(d) = id;
  IdentType_type(u) = d;
#else
  Traverse_void_Type (u, &doggy_applied_actions);
#endif
  return u;
}

/* Type of an expression.
   During code generation, this a a single type.
   Before code generation, it can be/contain a set type,
   due to operator sets.
*/
Type
expr_type (Expr e)
{
  Type t;
  
  switch (Expr_tag(e)) {
    case BinExpr_kind:
      convert_bin (&BinExpr_args(e), &BinExpr_ops (e), 0);
      t = expr_type (List_Expr_data(BinExpr_args(e)));
      if (BinExpr_ops(e) != NULL) {
        t = bin_rtype (List_Operator_data(BinExpr_ops(e)), t);
      }
      break;
    case MonExpr_kind:
      t = mon_rtype (MonExpr_op(e), expr_type (MonExpr_arg(e)));
      break;
    case IdentExpr_kind: {
      Pattern p = IdentExpr_pattern (e);
      Definition d = IdentExpr_def (e);
      Argument a = IdentExpr_arg (e);
      Operation_def f = IdentExpr_operator(e);
      FunctionDef ext = IdentExpr_ext(e);
      
      if (p)   return Pattern_type(p);
      if (d)   return Definition_type(d);
      if (a)   return Argument_type (a);
      if (f)   return Operation_def_type(f);
      if (ext && FunctionDef_tag(ext) == ExtVar_kind) return FunctionDef_result(ext);
      t = NULL;
      break;
    }
    case IfExpr_kind:
      t = expr_type (IfExpr_thn(e));
      break;
    case ConstExpr_kind:
      switch (Constant_tag(ConstExpr_cnst(e))) {
        case IntConst_kind:    t = int_type;  break;
        case BoolConst_kind:   t = bool_type; break;
        case StringConst_kind: t = string_type; break;
        case NullConst_kind:   t = null_type; break;
      }
      break;
    case Operation_kind: {
      Operation_def f = Operation_operator(e);
      Definition d = Operation_defi (e);
      Func func = Operation_func (e);
      FunctionDef ext = Operation_ext (e);
      
      if (f != NULL && Operation_def_result(f) != NULL) return Operation_def_result(f);
      if (f != NULL) return dep_type;
      if (ext != NULL) {
        if (FunctionDef_id(ext) == operator_id && 
	    Operation_args(e) != NULL) {
	  t = operator_type (List_Expr_data (Operation_args(e)));
	  if (t != NULL) return t;
	}
        return FunctionDef_result (ext);
      }
      if (func != NULL) {
        return Func_type (func);
      }
      if (d != NULL) {
        t = Definition_type(d);
	if (t != NULL && is_opr_type(t)) {
	  return dep_type;
	}
      }
      t = NULL;
      break;
    }
    case ParExpr_kind:
      t = expr_type (ParExpr_expr(e));
      break;
    case ConsExpr_kind:
      t = expr_type (ConsExpr_rhs(e));
      break;
    default:
      t = dep_type;
      break;
  }
  return t;
}

/* Types of a pattern list */
static List_Type
pats_to_types (List_Pattern l)
{
  if (l==NULL) return NULL;
  return Create_List_Type (Pattern_type (List_Pattern_data(l)), 
                           pats_to_types(List_Pattern_next(l)));
}


/* Argument types of a pattern */
static List_Type
get_pattern_def_types (Pattern p)
{
  List_Pattern args = NULL;
  
  switch (Pattern_tag(p)) {
    case DefPattern_kind:
      return get_pattern_def_types (DefPattern_arg(p));
      break;
    case OpPattern_kind:
      args = OpPattern_args(p);
      break;
    case TypedPattern_kind:
      return get_pattern_def_types (TypedPattern_pat(p));
    case ConsPattern_kind:
      args = Create_List_Pattern (ConsPattern_lhs(p), Create_List_Pattern (ConsPattern_rhs(p), NULL) );
      break;
    case IdentPattern_kind:
      if (IdentPattern_def(p)) return get_pattern_def_types (IdentPattern_def(p));
    case ConstPattern_kind:
    case NullPattern_kind:
    case DontCarePattern_kind:
      break;
  }
  return pats_to_types (args);
}

/* If t has an OPR type, return the arg types */
extern List_Type
get_tdef_types (Type t)
{
  if (!is_opr_type(t)) return NULL;
  return OprType_args(t);
}

/* If e has an OPR type, return the arg types */
List_Type
_get_def_types (Expr e)
{
  List_Type t;
  List_Expr m;
  
  switch (Expr_tag(e)) {
    case IdentExpr_kind: {
      Pattern p = IdentExpr_pattern(e);
      Operation_def f = IdentExpr_operator(e);
      Definition d = IdentExpr_def (e);
      Argument a = IdentExpr_arg (e);
      ArgPat a1;
      
      if (d != NULL) return get_def_types (d);
      if (f != NULL) return Operation_def_types (f);
      if (p != NULL) return get_pattern_def_types (p);
      if (a != NULL) {
        a1 = Argument_pat(a);
	switch (ArgPat_tag(a1)) {
	  case PatArg_kind:
	    if (PatArg_pat(a1) == NULL) return NULL;
	    return get_pattern_def_types (PatArg_pat(a1));
	  case SetArg_kind:
	  { Applied_operation op = SetArg_set(a1);
	    Applied_formal l;
	    Operation_def f;
	    assert (Applied_operation_tag(op) == OpSet_kind);
	    l = List_Applied_formal_data (OpSet_ops(op));
	    f = Applied_formal_ap (l);
	    if (f != NULL) return Operation_def_types(f);
	  }
	}
      }
      break;
    }
    case IfExpr_kind:
      t = _get_def_types (IfExpr_thn(e));
        if (t != NULL) return t;
      t = _get_def_types (IfExpr_els(e));
        if (t != NULL) return t;
      for (m = IfExpr_thens(e); m; m = List_Expr_next(m)) {
        t = _get_def_types (List_Expr_data(m));
        if (t != NULL) return t;
      }
      break;
    case Operation_kind: {
      Ident id = Operation_id(e);
      Operation_def f = Operation_operator(e);
      Definition d = Operation_defi (e);
      Func func = Operation_func (e);
      FunctionDef ext = Operation_ext (e);
            
      if (d != NULL) return get_def_types (d);
      if (f != NULL) return Operation_def_types (f);
      if (func != NULL) return Func_args (func);
      if (ext != NULL && id == Make_identifier ("OPERATOR")) {
        m = Operation_args(e);
	if (m != NULL) return _get_def_types(List_Expr_data(m));
      }
      break;
    }
      break;
    case ParExpr_kind:
      return _get_def_types (ParExpr_expr(e));
    case BinExpr_kind:
      if (BinExpr_ops(e) == NULL) {
        return _get_def_types (List_Expr_data(BinExpr_args(e)));
      }
      break;
    default:
      break;
  }
  return NULL;
}

/* If d has an OPR type, return the arg types */
List_Type
get_def_types (Definition d)
{
  Type t = Definition_type (d);
  if (!is_opr_type(t)) return NULL;
  t = norm_type(t);
  if (OprType_args(t) != NULL) return OprType_args(t);
  return _get_def_types (Definition_expr(d));
}

Type
TupleType_index(Type t, int i)
{
  List_Type ts;
  
  if (Type_tag(t)!=TupleType_kind) {
    assert (i==0);
    return t;
  }
  for (ts = TupleType_types(t); ts && i; ts = List_Type_next(ts)) i--;
  assert (ts);
  return List_Type_data(ts);
}

/* Fill in type t for pattern p and recursively for sub-patterns */
static void
set_type (Pattern p, Type t)
{
  Applied_operation op;
  List_Pattern args, args1;
  List_Applied_formal l, l1;
  Operation_def f;
  int i;
  Type u;
  
  if (p == NULL) return;

  Pattern_type(p) = t;
  
  switch (Pattern_tag(p)) {
    case IdentPattern_kind:
    case DontCarePattern_kind:
    case ConstPattern_kind:
    case NullPattern_kind:
      return;
    case DefPattern_kind:
      u = Pat_type(DefPattern_arg(p));
      if (t == dep_type && u != NULL) t = Pattern_type(p) = u;
      set_type (DefPattern_arg(p),t);
      i=0;
      for (args = DefPattern_ids(p); args; args = List_Pattern_next (args)) {
        Pattern pid = List_Pattern_data (args);
        set_type (pid, TupleType_index(t,i++));
      }
      return;
    case OpPattern_kind:
      op   = OpPattern_op(p);
      args = OpPattern_args(p);
      break;
    case TypedPattern_kind:
      set_type (TypedPattern_pat(p), TypedPattern_btype(p));
      return;
    case ConsPattern_kind:
      set_type (ConsPattern_lhs(p), arg_type(t));
      set_type (ConsPattern_rhs(p), t);
      return;
  }
  
  switch (Applied_operation_tag(op)) {
    case AnyOp_kind:
      for (args1 = args; args1 != NULL; args1 = List_Pattern_next(args1)) {
	set_type (List_Pattern_data(args1), dep_type);
      }
      return;
    case OpSet_kind:
      l = OpSet_ops(op);
      break;
    case AppliedOp_kind:
      l = Create_List_Applied_formal (AppliedOp_op(op), NULL);
      break;
  }
  
  /* Get any op */
  f = Get_applied_op (op);
  if (f==NULL) return;
  
  if (t == dep_type && Operation_def_result(f) != NULL) {
    t = Pattern_type(p) = Operation_def_result(f);
  }
    
  for (args1 = args, i = 0; args1 != NULL; args1 = List_Pattern_next(args1), i++) {
    t = NULL;
    for (l1 = l; l1; l1 = List_Applied_formal_next(l1)) {
      f = Get_operation (List_Applied_formal_data(l1));
      u = type_elem (Operation_def_types(f), i);
      if (t != NULL && type_conflict(t,u)) {
        t = Create_EdgeType (make_src_info(-1), Create_List_Type (t, Create_List_Type (u, NULL)));
      } else {
        t = u;
      }
    }
    set_type (List_Pattern_data(args1), t);
  }
}

/* Fill in the types for the pattern of scope s*/
void
Set_pattern_types (doggy_Scope s)
{
  List_Argument l;
  Argument a;
  ArgPat a1;
  Type t;
  
  if (s==NULL) return;
  
  switch (doggy_Scope_tag(s)) {
    case machine_descriptionScope_kind:
    case ExprGuardScope_kind:
    case RhsGuardScope_kind:
    case OpSetScope_kind:
    case AppliedOpScope_kind:
      Set_pattern_types (doggy_Scope_next(s));
      break;
    case RuleScope_kind:
      set_type (Lhs_pat (Rule_lhs (RuleScope_data(s))), dep_type);
      break;
    case FuncRuleScope_kind:
      for (l = FuncRule_args (FuncRuleScope_data(s)); l; l = List_Argument_next(l)) {
        a = List_Argument_data(l);
	a1 = Argument_pat(a);
	t = Argument_type(a);
	if (ArgPat_tag(a1) == PatArg_kind && PatArg_pat(a1) != NULL) set_type (PatArg_pat(a1), t);
      }
      break;
  }
}

static Type retrieve_type (char *s, Bool required)
{ Ident id = Make_identifier (s);
  Bind_Typedef b = Retrieve_Bind (id, NULL, doggy_TypeNameSpace, Bind_Typedef_kind);
  Typedef d = NULL;
  Type t;
  
  if (b !=NULL) {
    d = Bind_object(b);
  } else if (required) {
    InputError (1, FALSE, "Identifier '%s' not declared\n", s);
  }
  t = Create_IdentType (make_src_info(-1), id);
  IdentType_type_bind(t) = b;
  IdentType_type(t) = d;
  return t;
}

/* Mark the supported operations */
static void mark_supported(void) 
{
  List_Applied_formal a;
  List_Operation_def o;
  machine_description md=doggy_source(doggy_root);

  if(doggy_target(doggy_root) != NULL) {
    /* Support all source ops */
    for (o = machine_description_defs (md); o; o = List_Operation_def_next(o)) {
      Operation_def_supported(List_Operation_def_data(o)) = TRUE;
    }
    md=doggy_target(doggy_root);
  }
  if (machine_description_supports(md) == NULL) {
    /* Support all ops */
    for (o = machine_description_defs (md); o; o = List_Operation_def_next(o)) {
      Operation_def_supported(List_Operation_def_data(o)) = TRUE;
    }    
  } else {
    for (a = machine_description_supports(md); a; a = List_Applied_formal_next(a)) {
      Applied_formal op = List_Applied_formal_data(a);
      if (Get_operation(op)) Operation_def_supported(Get_operation(op)) = TRUE;
    }
  }
}

Type Root (Type t)
{ 
  if (t==NULL) return t;
  
  t = norm_type (t);
  
  switch (Type_tag(t)) {
    case IdentType_kind:
      { Bind_Operation_def b = Retrieve_Bind (IdentType_type_id(t), NULL, doggy_DefaultNameSpace, Bind_Operation_def_kind);
        Operation_def f;
	if (b==NULL) break;
	f = Bind_object(b);
	if (f == NULL) break;
	if (Operation_def_result(f) == NULL) break;
	return Operation_def_result(f);
      }
    default:;
      break;
  }
  return t;
}

char* find_type_name (Type t, char *name)
{
  if (t != NULL && Type_tag(t) == IdentType_kind &&
      IdentType_type(t) != NULL) {
    Typedef d = IdentType_type(t);
    name = Typedef_name(d);
    name = unstring (name);
    Typedef_name(d) = name;
  }
  return name;
}

/* Module initialization */
Bool init_types (void)
{ 
  opr_type = Create_OprType (make_src_info(-1), NULL);

  dep_type    = retrieve_type ("dep", TRUE);
  int_type    = retrieve_type ("Int", TRUE);
  bool_type   = retrieve_type ("Bool", TRUE);
  string_type = retrieve_type ("String", TRUE);
  list_type   = retrieve_type ("LIST", FALSE);
  void_type   = retrieve_type ("void", FALSE);
  null_type   = retrieve_type ("NULL", FALSE);
  
  operator_id = Make_identifier ("OPERATOR");
  null_id     = Make_identifier ("NULL");
  mark_supported();
  return FALSE;
}

VALUE NoValue (void)
{ VALUE v;
  return v;
}
