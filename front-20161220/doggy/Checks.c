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
#include "Checks.h"
#include "Types.h"
#include "GenCode.h"

void
init_ident_patterns (List_Pattern pids, Pattern pat)
{
  Pattern pid;
  
  if (!pids) return;
  pid = List_Pattern_data(pids);
  IdentPattern_def (pid) = pat;
  init_ident_patterns (List_Pattern_next(pids), pat);
}


/* Check consistency of argument lists */
static Bool
arg_conflict (List_Argument l, List_Argument m)
{
  Argument a, b;
  
  if (l == NULL || m == NULL) return l != m;
  
  if (arg_conflict (List_Argument_next(l), List_Argument_next(m))) 
    return TRUE;
    
  a = List_Argument_data(l);
  b = List_Argument_data(m);
  
  if (Argument_id(a) != Argument_id(b)) return TRUE;
  
  return type_conflict (Argument_type(a), Argument_type(b));
}

/* Check consistency of function */
Bool Func_conflict (Func f)
{
  List_FuncRule r;
  List_Argument l, m;
  
  Func_args(f) = Arg_types(f);
  
  r = Func_rules(f);
  l = FuncRule_args(List_FuncRule_data(r));
  
  for (r = List_FuncRule_next(r); r; r = List_FuncRule_next(r)) {
    m = FuncRule_args(List_FuncRule_data(r));
    if (arg_conflict(l,m)) return TRUE;
  }
  return FALSE;
}

/* Check consistency of argument */
Bool Arg_conflict (Argument a)
{ NOT_USED(a);
  /* Allow other types too */
  return FALSE;
}

/* Check whether op can be commutative */
Bool Comm_conflict (Operation_def op)
{
  List_Property l;
  List_Type t;
  Type u, v;
  
  for (l = Operation_def_props(op); l; l = List_Property_next(l)) {
    if (!List_Property_data(l)) continue;
    t = Operation_def_types(op);
    if (List_Type_size(t) != 2) return TRUE;
    u = List_Type_data(t);
    v = List_Type_data (List_Type_next(t));
    if (type_conflict (u,v)) return TRUE;
  }
  return FALSE;
}

/* Conversion */
Operation_def Get_operation (Applied_formal a)
{
  if (a == NULL) return NULL;
  
  return Applied_formal_ap(a);
}
  
/* Conversion */
Operation_def Get_applied_op (Applied_operation op)
{
  Applied_formal a;
  
  switch (Applied_operation_tag(op)) {
    case AnyOp_kind:
      return NULL;
    case OpSet_kind:
      if (OpSet_ops(op) == NULL) return NULL;
      a = List_Applied_formal_data (OpSet_ops(op));
      break;
    case AppliedOp_kind:
      a = AppliedOp_op(op);
      break;
  }
  
  return Get_operation (a);
}

#if 0
/* not used at the moment: */
/* Match p against t */
static Bool
type_match (Pattern p, Type t)
{
  switch (Pattern_tag(p)) {
    case IdentPattern_kind:
      return TRUE;
    case DontCarePattern_kind:
      if (DontCarePattern_expr(p)==NULL) return TRUE;
      /* Fall through */
    case ConstPattern_kind:
    case NullPattern_kind:
      return TRUE;
#if 0
      return sub_type (int_type, t) ||
             sub_type (dep_type, t);
#endif
    case DefPattern_kind:
    case OpPattern_kind:
      return isdeptype(t);
    case ConsPattern_kind:
      return is_listtype(t);
    case TypedPattern_kind:
      return sub_type (TypedPattern_btype(p), t);
  }
  return FALSE;
}
#endif
/* Check pattern consistency */
Bool Pattern_conflict (Pattern p)
{
  Applied_operation op;
  List_Pattern args;
  List_Type t = NULL;
  
  switch (Pattern_tag(p)) {
    case ConstPattern_kind:
    case NullPattern_kind:
    case IdentPattern_kind:
    case DontCarePattern_kind:
      return FALSE;
    case DefPattern_kind:
      return Pattern_conflict (DefPattern_arg (p));
    case OpPattern_kind:
      op   = OpPattern_op (p);
      args = OpPattern_args (p);
      break;
    case ConsPattern_kind:
      return FALSE; 
    case TypedPattern_kind:
      return Pattern_conflict (TypedPattern_pat(p));
  }
  
  if (t==NULL) {
    Operation_def f = Get_applied_op(op);
    if (f == NULL) return FALSE;
    if (!Operation_def_src(f)) return TRUE;
    if (!Operation_def_supported(f)) return FALSE;
    t = Operation_def_types(f);
  }
  
  if (List_Type_size (t) != List_Pattern_size (args)) return TRUE;
  
  for (;
       t != NULL && args != NULL;
       t = List_Type_next(t),
       args = List_Pattern_next(args)) {
#if 0
    /* To do: extend check */
    if (!type_match (List_Pattern_data(args), List_Type_data(t))) {
      return TRUE;
    }
#endif
  }
  
  return FALSE;
}

/* Check set consistency in set pattern */
Bool Pattern_set_conflict (List_Applied_formal l)
{
  Operation_def f;
  List_Type t, u;
  
  if (l==NULL) return FALSE;
  f = Get_operation (List_Applied_formal_data(l));
  if (f==NULL) return FALSE;
  t = Operation_def_types(f);
  
  for (l = List_Applied_formal_next(l); l; l = List_Applied_formal_next(l)) {
    f = Get_operation (List_Applied_formal_data(l));
    if (f==NULL) return FALSE;
    u = Operation_def_types(f);
    if (types_conflict(t,u)) return TRUE;
  }
  
  return FALSE;
}

/* Type checking of definition */
Bool Def_conflict (Definition d)
{
  Expr e = Definition_expr(d);
  
  Set_pattern_types (Expr_scope(e));
  
  return !can_coerce (Definition_type(d), expr_type(e));
}

/* Type checking of call */
Bool Call_conflict (Expr e)
{
  Operation_def f;
  FunctionDef ext;
  Func func;
  List_Type t;
  List_Expr l;
  
  if (Expr_tag(e) != Operation_kind) return FALSE;
  
  Set_pattern_types (Expr_scope(e));

  f = Operation_operator(e);
  ext = Operation_ext (e);
  func = Operation_func (e);
  
  if (f != NULL) {
    if (!Operation_def_supported(f)) return FALSE;
    t = Operation_def_types(f);
  } else if (ext != NULL && FunctionDef_tag(ext) == ExtFunc_kind) {
    t = ExtFunc_args(ext);
  } else if (func != NULL) {
    if (Func_args(func) == NULL) Func_args(func) = Arg_types(func);
    t = Func_args(func);
  } else {
    return FALSE;
  }
  l = Operation_args(e);
  if (List_Type_size(t) != List_Expr_size(l)) {
    return TRUE;
  }
  for (; t != NULL && l != NULL;
       t = List_Type_next(t), l = List_Expr_next(l)) {
#if 0
/* Disabled: allow coercion of call args */
    if (!type_conflict (List_Type_data(t), 
                       expr_type(List_Expr_data(l)))) continue;
    if (can_coerce (List_Type_data(t), 
                       expr_type(List_Expr_data(l)))) continue;
    return TRUE;
#endif
  }
  return !(t==NULL && l==NULL);
}

/* Type checking of conditions and branches */
Bool If_conflict (Expr e)
{
  Type t;
  List_Expr l;
  
  if (Expr_tag(e) != IfExpr_kind) return FALSE;
  
  Set_pattern_types (Expr_scope(e));

  t = expr_type (IfExpr_thn (e));
  if (type_conflict (t, expr_type (IfExpr_els(e)))) return TRUE;
  for (l = IfExpr_thens(e); l; l = List_Expr_next(l)) {
    if (type_conflict (t, expr_type (List_Expr_data(l)))) return TRUE;
  }
  
  return FALSE;
}

/* Type checking of binary operator */
static Bool
bin_conflict (Operator op, Type l, Type r)
{
  Type t;
  
  if (l == NULL) return TRUE;
  if (r == NULL) return TRUE;

  l = norm_type (l);
  r = norm_type (r);
  switch (op) {
    case CandOp:
    case CorOp:
      t = bool_type;
      break;	
    case NeqOp:	
    case EqOp:
      if (Type_tag(l) == EdgeType_kind) return TRUE;
      if (Type_tag(r) == EdgeType_kind) return TRUE;
      if (Type_tag(l) == OprType_kind && Type_tag(r) == OprType_kind) return FALSE;
      return type_conflict (l, r);	
    case SLOp:	
    case SROp:	
    case XorOp:	
    case DivOp:	
    case ModOp:	
    case MulOp:	
    case AndOp:	
    case AddOp:	
    case SubOp:
    case LEOp:	
    case GEOp:	
    case LTOp:	
    case GTOp:
      t = int_type;
      break;	
  }
  if (!can_coerce (t,l)) return TRUE;
  if (!can_coerce (t,r)) return TRUE;
  return FALSE;
}

/* Type checking of monadic operator */
static Bool
mon_conflict (MonOp op, Type l)
{
  Type t;
  
  if (l == NULL) return TRUE;
  
  switch (op) {
    case NotOp:	
      t = bool_type;
      break;
    case NegOp:
    case PlusOp:
    case MinOp:	
      t = int_type;
      break;
    case AddrOp: 
       return FALSE;
    case DerefOp:
       return l == NULL || Type_tag(l) == PointerType_kind;
  }
  if (!can_coerce (t,l)) return TRUE;
  return FALSE;
}

/* Binary/unary operator type checking */
Bool Oper_conflict (Expr e)
{
  Type l, r;
  
  expr_type (e); /* Force normalization of e */
  
  if (!Supported(Expr_scope(e))) return FALSE;
  
  Set_pattern_types (Expr_scope(e));
  
  switch (Expr_tag(e)) {
    case BinExpr_kind:
      if (BinExpr_ops(e) == NULL) return FALSE;
      if (List_Operator_next(BinExpr_ops(e)) != NULL) return TRUE;
      l = expr_type (List_Expr_data(BinExpr_args(e)));
      r = expr_type (List_Expr_data(List_Expr_next(BinExpr_args(e))));
      return bin_conflict (List_Operator_data(BinExpr_ops(e)), l, r);
    case MonExpr_kind:
      l = expr_type (MonExpr_arg(e));
      return mon_conflict (MonExpr_op(e), l);
    default:
      return FALSE;
  }
}

/* Check for dep type of guard */
Bool NonDepType (Guard g)
{  
  List_Expr l;
  
  if (Guard_tag(g) != ExprGuard_kind) return FALSE;
  
  Set_pattern_types (Guard_scope(g));

  for (l = ExprGuard_body(g); l; l = List_Expr_next(l)) {
    if (!isdeptype (expr_type (List_Expr_data(l)))) return TRUE;
  }
  return FALSE;
}

/* Remove f from l */
static List_Applied_formal 
remove_op (List_Applied_formal l, Operation_def f)
{
  if (l==NULL) return NULL;
  
  if (Get_operation(List_Applied_formal_data(l)) == f) {
    return remove_op (List_Applied_formal_next(l), f);
  }
  List_Applied_formal_next(l) = remove_op (List_Applied_formal_next(l), f);
  return l;
}

/* If a is unsupported, flag this in the rule, or remove it from the set. */
Bool SetSupported (Operation_def f, doggy_Scope s, Bool nil)
{  
  Applied_operation a;
  Bool in_rhs = TRUE;
  
  if (!nil && f==NULL) return FALSE;
  if (f != NULL && Operation_def_supported(f)) return FALSE;

  /* f is not supported. */
  for (; s != NULL; s = doggy_Scope_next(s)) {
    switch (doggy_Scope_tag(s)) {
      case RuleScope_kind: {
        Rule rule = RuleScope_data(s);
        if (!Rule_supported(rule)) break;
        Rule_supported(rule) = FALSE;
	if (in_rhs) {
          Rule_rhs_supported(rule) = FALSE;
        }
	break;
      }
      case FuncRuleScope_kind:
        FuncRule_supported(FuncRuleScope_data(s)) = FALSE;
        break;
      case machine_descriptionScope_kind:
      case ExprGuardScope_kind:
      case RhsGuardScope_kind:
	break;
      case OpSetScope_kind:
	a = AppliedOpScope_data(s);
        in_rhs = FALSE;
	OpSet_ops(a) = remove_op (OpSet_ops(a), f);
	if (OpSet_ops(a) != NULL) return FALSE;
        break;
      case AppliedOpScope_kind:
	a = AppliedOpScope_data(s);
        in_rhs = FALSE;
        break;
    }
  }
  return FALSE;
}

/* test if current rule is supported */
Bool Supported (doggy_Scope s)
{  
  for (; s != NULL; s = doggy_Scope_next(s)) {
    if (doggy_Scope_tag(s) == RuleScope_kind) {
      return Rule_supported(RuleScope_data(s));
    } else if (doggy_Scope_tag(s) == FuncRuleScope_kind) {
      return FuncRule_supported(FuncRuleScope_data(s));
    } else {
      return Supported (doggy_Scope_next(s));
    }
  }
  return TRUE;
}

/* Fix up of ADT */
void store_md (machine_description md, Bool src) 
{
  List_Operation_def o;
  Operation_def f;

  for (o = machine_description_defs (md); o; o = List_Operation_def_next(o)) {
    f = List_Operation_def_data(o);
    if (src) {
      Operation_def_src(f) = TRUE;
    } else {
      Operation_def_tgt(f) = TRUE;
    }
  }
  return;
  if(!src) {
    List_Applied_formal a;
    Applied_formal op;
    
    for (a = machine_description_supports (md); a; a = List_Applied_formal_next(a)) {
      op = List_Applied_formal_data(a);
      Operation_def_supported(Get_operation(op)) = TRUE;
    }
  }
}

void Store_md (doggy d)
{
  store_md (doggy_source(d), TRUE);
  if (doggy_target(d) != NULL) {
    store_md (doggy_target(d), FALSE);
  } else {
    store_md (doggy_source(d), FALSE);
  }
}
