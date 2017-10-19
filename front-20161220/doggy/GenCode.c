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
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <front/error.h>
#include <front/mem.h>
#include <front/scan_support.h>
#include <front/print_support.h>

#include "doggy.h"
#include "Checks.h"
#include "Types.h"
#include "GenCode.h"
#include "doggyPrint.h"

/* Output file for code generation */
FILE *out = NULL;
char *opt_name = "optimize_any";
char *opt_rule_id;

static Ident ident_id, string_id;

static Section Cur_section;

/* Traversals */

static struct s_doggy_TraverseTable Compute_Supported_Mops;
static struct s_doggy_TraverseTable Compute_All_Mops;
static struct s_void_doggy_TraverseTable Reset_Order;
static struct s_void_doggy_TraverseTable Determine_Order;

static int current_order;

/* Indentation level */
static int indent = 0;

Bool search_ops;
static Rule     cur_rule;
static FuncRule cur_func;
static char *arg_name;
static Type cur_type;
List_ActualOp supported_mops;
List_ActualOp all_mops;

/* Macros for indentation */

#define IN { int i; for (i=0; i < indent; i++) fprintf(out, "  "); }
#define BEGIN_SCOPE { fprintf (out, "{\n"); indent++; }
#define END_SCOPE   { indent--; IN; fprintf (out, "}\n"); }
#define SP fprintf (out, " ");
#define OPER	{ if (!*first) fprintf (out, "%s ", oper); \
		  *first = FALSE; \
		}

static void expr (Expr e, Type t);
static int test_pattern (Pattern p, Path path, Type t, Type ut,
                         Bool *first, char *oper, int carry);

/* Element selection */
static Expr
expr_elem (List_Expr l, int i)
{
  if (l==NULL) return NULL;
  if (i==0) return List_Expr_data(l);
  return expr_elem (List_Expr_next(l), i-1);
}

/* Insertion in list */
static List_Ident 
insert_ident (List_Ident l, Ident id)
{
  if (l==NULL) return Create_List_Ident (id, NULL);
  if (List_Ident_data(l) == id) return l;
  List_Ident_next (l) = insert_ident (List_Ident_next(l), id);
  return l;
}

/* List append */
static List_Func 
append_funcs (List_Func l, List_Func m)
{
  if (l==NULL) return m;
  
  return Create_List_Func(List_Func_data(l),
                               append_funcs (List_Func_next(l), m));
}

/* List append */
static List_Rule 
append_rules (List_Rule l, List_Rule m)
{
  if (l==NULL) return m;
  
  return Create_List_Rule(List_Rule_data(l),
                          append_rules (List_Rule_next(l), m));
}

/***********/

static Bool
overload_conflict (ActualOp mop)
{
  List_Operation_def o;
  Operation_def f;
  int n = 0;
  List_Type types = NULL;
  List_Type l;
  
  for (o = ActualOp_formals (mop); o; o = List_Operation_def_next(o)) {
    f = List_Operation_def_data(o);
    l = Operation_def_types(f);
    if (n>0 && !types_conflict (types, l)) {
      return TRUE;
    }
    types = l;
    n++;
  }
  /* TODO: should we check result type aswell ? */
  return FALSE;
}

Bool
is_targ (Operation_def def)
{
  doggy_Scope s;
  machine_description md;
  
  if (!Operation_def_supported(def)) return FALSE;
  
  if (doggy_target(doggy_root) == NULL) return TRUE;
  
  for (s = Operation_def_scope (def); s; s = doggy_Scope_next(s)) {
    if (doggy_Scope_tag(s) != machine_descriptionScope_kind) continue;
    md = machine_descriptionScope_data(s);
    return md == doggy_target(doggy_root);
  }
  return FALSE;
}

/***********/

/* Generate comments */
static void gen_comments (scan_strings s)
{  for (; s; s = s->next) {
    fprintf (out, "%s\n", s->string);
  }
}

/* Generate name of rule r */
static void
rule_id (Rule r)
{
  Lhs l = Rule_lhs(r);
  char *s = "rule";
  
  switch (Lhs_tag (l)) {
    case LabeledLhs_kind:
      fprintf (out, "do_%s", IDENT_STRING(LabeledLhs_id(l)));
      break;
    case UnLabeledLhs_kind:
      if (Rule_rules_id(r) != NULL) {
        s = IDENT_STRING (Rule_rules_id(r));
      } else if(opt_rule_id != NULL) {
        s = opt_rule_id;
      }
      fprintf (out, "optimize_%s_%d", s, find_line_position(Lhs_loc(l)));
      break;
  }
}

static void
print_str (char *s)
{
  if (*s=='"') s++;
  while (*s && *s != '"') fprintf (out, "%c", *s++);
}

/* Default value for a type */
static void
default_val (Type t)
{
  if (t == NULL) t = dep_type;
  
  switch (Type_tag(t)) {
    case EdgeType_kind:
      default_val (List_Type_data(EdgeType_types(t)));
      break;
    case OprType_kind:
      if (search_ops) {
        fprintf (out, "NULL");
      } else {
        fprintf (out, "0");
      }
      break;
    case IdentType_kind:
      if (Typedef_value(IdentType_type(t)) != NULL) {
        print_str (Typedef_value(IdentType_type(t)));
      }
      else fprintf (out, "NULL");
      break;
    default:
      fprintf (out, "NULL");
      break;
  }
}

/* Generate type t */
static void
type (Type t)
{ 
  List_Type l;
  
  if (t==NULL) {
    fprintf (out, "DEP");
    return;
  }
  
  switch (Type_tag(t)) {
    case IdentType_kind:
      if (IdentType_type(t) == NULL) {
        fprintf (out, "%s", IDENT_STRING(IdentType_type_id(t)));
      } else if (Typedef_name(IdentType_type(t)) != NULL) {
        print_str (Typedef_name(IdentType_type(t)));
      } else {
        fprintf (out, "%s", IDENT_STRING(Typedef_id(IdentType_type(t))));
      }
      break;
    case RangeType_kind:
    case FRangeType_kind:
      type (int_type);
      break;
    case PointerType_kind:
      type (PointerType_base(t));
      fprintf (out, "*");      
      break;
    case OprType_kind:
      fprintf (out, "OPR");      
      break;
    case EdgeType_kind:
      for (l = EdgeType_types(t); l; l = List_Type_next(l)) {
        type (List_Type_data(l));
	if (List_Type_next(l) != NULL) fprintf (out, "_or_");
      }
      break;
    case TupleType_kind:
      for (l = TupleType_types(t); l; l = List_Type_next(l)) {
        type (List_Type_data(l));
	if (List_Type_next(l) != NULL) fprintf (out, "_and_");
      }
      break;
  }
}

static void gen_path (Path p, Type t, int i);

/* Generate path access of path p with type t */
static void
get_path (Path p, Type t, char *prefix)
{
  if (p == NULL) {
    fprintf (out, "%s", arg_name);
    return;
  }
  
  if (!isdeptype(Path_type(p))) {
    type (Path_type(p)); fprintf (out, "_");
  }
  fprintf (out, "%s_", prefix);
  type (t);
  fprintf (out, " (");
  fprintf (out, "%d, ", Path_data(p));
  gen_path (Path_next(p), Root(Path_type(p)), 0);
  fprintf (out, ")");
}

/* Generate path access of path p with type t */
static void
gen_path (Path p, Type t, int i)
{
  if (Type_tag(t) == TupleType_kind) {
    fprintf (out, "TUPLE_ARG (");
  }
  get_path (p, t, "GET");
  if (Type_tag(t) == TupleType_kind) {
    fprintf (out, ", %d)",i);
  }
}

/* Test for commutativity of operation */
Bool
commutative (Operation_def f)
{
  List_Property l;
  for (l = Operation_def_props(f); l; l = List_Property_next(l)) {
    if (List_Property_data(l)) return TRUE;
  }
  return FALSE;
}

/************/

/* Declare id with type t and initialize with path access path */
static void
declare (Type t, Path path, Ident id)
{
  IN; type (t);
  fprintf (out, " %s = ", IDENT_STRING(id));
  gen_path (path, t, 0);
  fprintf (out, ";\n");
}

static void
declare_tuple (Type t, Path path, List_Pattern ids)
{
  int i=0;
  List_Pattern ps;
  
  if (!List_Pattern_next (ids)) {
    declare (t, path, IdentPattern_id (List_Pattern_data (ids)));
    return;
  }
  for (ps = ids; ps; ps = List_Pattern_next (ps)) {
    Pattern p = List_Pattern_data (ps);
    
    IN; type (TupleType_index(t,i));
    fprintf (out, " %s = ", IDENT_STRING(IdentPattern_id (p)));
    gen_path (path, t, i);
    fprintf (out, ";\n");
    i++;
  }
}

/* Declare and initialize all variables within p under path */
static void
pattern_vars (Pattern p, Path path)
{
  Applied_operation op;
  List_Pattern args;
  List_Applied_formal l;
  int i;
  Operation_def f;
  Bool swap;
  
  if (p==NULL) return;
  
  swap = Pattern_swap(p);
  
  switch (Pattern_tag(p)) {
    case DefPattern_kind:
      declare_tuple (Pattern_type(p), path, DefPattern_ids(p));
      pattern_vars (DefPattern_arg(p), path);
      return;
    case IdentPattern_kind:
      { Bind_Operation_def b = Retrieve_Bind (IdentPattern_id(p), NULL, doggy_DefaultNameSpace, Bind_Operation_def_kind); 
        if (b != NULL && Bind_object(b) != NULL) return; /* Operation */
      }                                                                           
      declare (Pattern_type(p), path, IdentPattern_id(p));
      return;
    case OpPattern_kind:
      op   = OpPattern_op(p);
      args = OpPattern_args(p);
      break;
    case TypedPattern_kind:
      pattern_vars (TypedPattern_pat(p), path);
      return;
    case ConsPattern_kind:
    { Type rt = Pattern_type(p);
      pattern_vars (ConsPattern_lhs(p), Create_Path (no_srcinfo, 0, rt, path));
      pattern_vars (ConsPattern_rhs(p), Create_Path (no_srcinfo, 1, rt, path));
      return;
    }
    case ConstPattern_kind:
    case NullPattern_kind:
    case DontCarePattern_kind:
      return;
  }
  
  switch (Applied_operation_tag(op)) {
    case AnyOp_kind:
      for (i = 0;
           args != NULL;
	   args = List_Pattern_next(args), i++) {
	pattern_vars (List_Pattern_data(args), 
                      Create_Path (no_srcinfo, i, Pattern_type(p), path));
      }
      return;
    case OpSet_kind:
      l = OpSet_ops(op);
      f = Get_operation(List_Applied_formal_data(l));
      break;
    case AppliedOp_kind:
      f = Get_operation(AppliedOp_op(op));
      break;
  }

  if (f==NULL) return;
  
  for (i=0; args != NULL; i++, args = List_Pattern_next(args)) {
    Type rt = Operation_def_node_type(f);
    if (swap) i = 1-i;
    pattern_vars (List_Pattern_data(args), 
                  Create_Path (no_srcinfo, i, rt, path));
  }
}

/* Declare and initialize all variable in the wherepart w */
static void
where_vars (Wherepart w, int lo, int hi)
{
  List_Definition l;
  Definition d;
  int i;
  
  if (w==NULL) return;
  
  for (i = lo; i < hi; i++) {
    for (l = Wherepart_defs(w); l; l = List_Definition_next(l)) {
      d = List_Definition_data(l);
      if (Definition_order(d) != i) continue;
      IN; type (Definition_type(d));
      fprintf (out, " %s = ", IDENT_STRING(Definition_id(d)));
      expr (Definition_expr(d), Definition_type(d)) ;
      fprintf (out, ";\n");
    }
  }
  
}

/* Generate the C operator for op */
static void
operator (Operator op)
{
  switch (op) {
    case CandOp: fprintf (out, "&&"); break;
    case CorOp: fprintf (out, "||"); break;
    case XorOp: fprintf (out, "^"); break;
    case EqOp:  fprintf (out, "=="); break;
    case NeqOp: fprintf (out, "!="); break;
    case LEOp:  fprintf (out, "<="); break;
    case GEOp:  fprintf (out, ">="); break;
    case LTOp:  fprintf (out, "<"); break;
    case GTOp:  fprintf (out, ">"); break;
    case SLOp:  fprintf (out, "<<"); break;
    case SROp:  fprintf (out, ">>"); break;
    case DivOp: fprintf (out, "/"); break;
    case ModOp: fprintf (out, "%s", "%"); break;
    case MulOp: fprintf (out, "*"); break;
    case AndOp: fprintf (out, "&"); break;
    case AddOp: fprintf (out, "+"); break;
    case SubOp: fprintf (out, "-"); break;
  }
}

/* Generate the C operator for op */
static void
monop (MonOp op)
{
  switch (op) {
    case NotOp:   fprintf (out, "!"); break;
    case NegOp:   fprintf (out, "~"); break;
    case AddrOp:  fprintf (out, "&"); break;
    case DerefOp: fprintf (out, "*"); break;
    case PlusOp:  fprintf (out, "+"); break;
    case MinOp:   fprintf (out, "-"); break;
  }
}

/* Generate code for a constant c */
static void
gen_const (Constant c)
{
  switch (Constant_tag(c)) {
    case IntConst_kind:
      fprintf (out, "%d", IntConst_i(c));
      break;
    case BoolConst_kind:
      fprintf (out, "%s", BoolConst_b(c)?"TRUE":"FALSE");
      break;
    case StringConst_kind:
      fprintf (out, "%s", StringConst_s(c));
      break;
    case NullConst_kind:
      fprintf (out, "NULL");
      break;
  }
}

/* Generate a one-letter token for a type */
static void
type_token (Type t)
{
  List_Type l;
  
  if (t==NULL) {
    fprintf (out, "D");
    return;
  }
  
  if (t==null_type) {
    fprintf (out, "NULL");
    return;
  }
  
  switch (Type_tag(t)) {
    case EdgeType_kind:
      l = EdgeType_types(t);
      if (List_Type_next(l) == NULL) {
        type_token (List_Type_data(l)); 
	return;
      }
      fprintf (out, "_");
      for (; l; l = List_Type_next(l)) {
        type_token (List_Type_data(l)); 
      }
      fprintf (out, "_");
      return;
    case TupleType_kind:
      l = TupleType_types(t);
      type_token (List_Type_data(l)); 
      for (l = List_Type_next(l); l; l = List_Type_next(l)) {
        fprintf (out, "n");
        type_token (List_Type_data(l));
      }
      return;
    case OprType_kind:
      fprintf (out, "O");
      return;
    case RangeType_kind:
    case FRangeType_kind:
      type_token(int_type);
      return;
    case PointerType_kind:
      fprintf (out, "P");
      return;
    case IdentType_kind:
      if (IdentType_type(t) == NULL) {
        fprintf (out, "%s", IDENT_STRING(IdentType_type_id(t)));
	return;
      }
      if (Typedef_short_hand(IdentType_type(t)) != NULL) {
        print_str (Typedef_short_hand(IdentType_type(t)));
      } else {
        fprintf (out, "%s", IDENT_STRING(Typedef_id(IdentType_type(t))));
      }
      return;
  }
}

/* Generate code for the creation of a DAG node */
static void
create_op (Operation_def f, List_Expr args, Bool name)
{
  List_Type types = Operation_def_types(f);
  Type t, e;
  Expr ex;
  int i;
  
  if (name && Operation_def_result(f) != NULL
      && !isdeptype(Operation_def_result(f))) {
    /* New style */
    fprintf (out, "%s", IDENT_STRING (Operation_def_id(f)));
    return;
  }
  
/*   for (perm = Actual_operation_perm (Operation_def_actual(f)); */
/*        perm; */
/*        perm = List_Num_next(perm)) { */
/*     j = Num_i(List_Num_data(perm))-1; */
  for (i = 0; i < List_Type_size(types); i++) {
    t = type_elem (types, i);
    ex = expr_elem (args, i);
    t = norm_type(t);
    e = expr_type (ex);
    e = norm_type(e);
    if (name) {
#if 0
      if (e != NULL && Type_tag(t) == EdgeType_kind &&  can_coerce(t, e)) {
	type_token(e);
      } else {
	type_token(t);
      }    
#else
      type_token(t);
#endif
    } else {
      fprintf (out, ", ");
      expr (ex, t);
    }
  }
}

static char *type_tok (Type t)
{  
  t = norm_type(t);
  if (t==NULL) return  "D";
  
  if (t==null_type) return  "NULL";
  if (t==list_type) return  "LIST";
  
  switch (Type_tag(t)) {
    case OprType_kind:
      return  "O";
    case RangeType_kind:
    case FRangeType_kind:
      return type_tok(int_type);
    case PointerType_kind:
      return  "P";
    case IdentType_kind:
      if (Typedef_short_hand(IdentType_type(t)) != NULL) {
        return unstring (Typedef_short_hand(IdentType_type(t)));
      } else {
        return  IDENT_STRING(Typedef_id(IdentType_type(t)));
      }
    default:
      return "";
  }
}

static Type
get_ident_type(Ident id, doggy_Scope s)
{
  Bind bind;
  
  bind = Retrieve_Bind(id,s,doggy_DefaultNameSpace, Bind_Pattern_kind);
  if (bind != NULL) return Pattern_type((Pattern)Bind_object(bind));
  
  bind = Retrieve_Bind(id,s,doggy_DefaultNameSpace, Bind_Definition_kind);
  if (bind != NULL) return Definition_type((Definition)Bind_object(bind));
  
  bind = Retrieve_Bind(id,s,doggy_DefaultNameSpace, Bind_Argument_kind);
  if (bind != NULL) return Argument_type((Argument)Bind_object(bind));
  
  InputError (1, FALSE, "Identifier '%s' not declared\n", IDENT_STRING(id));
  return NULL;
}

static void
print_type(Type t)
{
  Type u=norm_type(t);
  if(Type_tag(u)==IdentType_kind) {
    if (strcmp(IDENT_STRING(IdentType_type_id(u)),"String")==0
        || strcmp(IDENT_STRING(IdentType_type_id(u)),"Ident")==0
        || strcmp(IDENT_STRING(IdentType_type_id(u)),"Bool")==0
        || strcmp(IDENT_STRING(IdentType_type_id(u)),"Float")==0
        || strcmp(IDENT_STRING(IdentType_type_id(u)),"Int")==0
        || strcmp(IDENT_STRING(IdentType_type_id(u)),"Oct")==0
        || strcmp(IDENT_STRING(IdentType_type_id(u)),"Hex")==0) {
      fprintf(out,"%ssym",IDENT_STRING(IdentType_type_id(u)));
    } else if(strcmp(IDENT_STRING(IdentType_type_id(u)),"int")==0) {
      fprintf(out,"Intsym");
    } else if(strcmp(IDENT_STRING(IdentType_type_id(u)),"Bool")==0) {
      fprintf(out,"Boolsym");
    } else type_token(t);
  } else type_token(t);
}

static Ident
print_ident_type(char **string, doggy_Scope scope)
{
  Ident result;
  int size = 0;
  char *s, *p=*string;
  int typed = (p[0]=='{');

  if(typed) p++;
  sscanf(p,"%*[a-zA-Z0-9_]%n",&size);
  if (size == 0) {	/* still zero ==> conversion was unsuccessful */
      InputError (1, FALSE, "Character '%c' not allowed in identifier names.\n",
		  *string[0]) ;
      InputError (1, FALSE, "Offending text: '%s ...'\n", *string) ;
      return NULL ;
  }
  s = fe_malloc (size+1);
  strncpy (s, p, size);
  s[size]=0;
  p+=size;
  result = Find_identifier(s);
  if(!result) {
    InputError (1, FALSE, "Identifier '%s' not declared\n", s);
  }
  
  if(typed) {
    if(*p==':') {
      p++;
      size=strcspn(p,"}");
      fprintf(out,"%.*s",size,p);
      p+=size;
    }
    if(*p!='}') {
      InputError(1,FALSE, "Unterminated parse string argument `%s'\n",s);
    } else p++;
  } else if(result) {
    Type t=get_ident_type(result,scope);
    if(t) print_type(t);
  }
  *string=p;
  return result;
}

#define MAX_ARGS_SIZE 1024

static void
gen_parse_string(Expr e, Type t)
{
  char *string, *p;
  static char _args[MAX_ARGS_SIZE];
  char *args = _args;
  int num=0;
  Ident id;
  
  args[0] = 0;
  
  fprintf(out,"Parse_");
  type (t);
  fprintf(out,"(");
  assert (Expr_tag(e)==ConstExpr_kind &&
          Constant_tag(ConstExpr_cnst(e)) == StringConst_kind);
  string = StringConst_s(ConstExpr_cnst(e));

  p=string;
  while(*p) {
    switch(*p) {
    case '$':
      fputc('%',out);
      p++;
      id = print_ident_type(&p,Expr_scope(e));
      args += sprintf (args, ", %s", IDENT_STRING(id));
      num++;
      continue;
    case '\\':
      fputc(*p++,out);
    }
    fputc(*p++,out);
  }
  fprintf(out, ", %d%s)",num, _args);
}
 
/* Generate code for expression e with type t */
static void
expr (Expr e, Type t)
{
  List_Expr l, m;
  List_Operator ops;
  List_Type types, tl;
  Bool convert;
  Bool copy;
  Type s, u;
  char *sep = "";

  if(Expr_tag(e)==BinExpr_kind && BinExpr_ops(e)==NULL) {
    /* Binary expression with one argument */
    expr (List_Expr_data(BinExpr_args (e)), t);
    return;
  }
  
  if (t == NULL && !Expr_warned(e)) {
    InputWarning (Expr_loc(e), TRUE, 5, "Unknown type");
    Expr_warned(e) = TRUE;
  }
  
  s = expr_type(e);
  convert = s != NULL && t != NULL && 
            !is_opr_type(s) && !is_opr_type(t) &&
            type_conflict(s, t) && !sub_type (s, t);

  copy = tree && !convert && Expr_tag(e) == IdentExpr_kind && IdentExpr_use_cnt(e) > 1;
  
  if (strlen (type_tok(s))!=0 && strcmp(type_tok(s), type_tok(t))==0) convert = FALSE;

  if (s==string_type && type_conflict(s,t)) {
    assert ( Expr_tag(e)==ConstExpr_kind );
    gen_parse_string(e,t);
    return;
  }

  if (convert) {
    fprintf (out, "CONVERT_");
    type (s);
    fprintf (out, "_TO_");
    type (t);
    fprintf (out, " (");
  }
  
  if (copy) {
    fprintf (out, "COPY_");
    type (s);
    fprintf (out, " (");
  }
  
  switch (Expr_tag(e)) {
    case BinExpr_kind:
      l = BinExpr_args (e);
      u = t;
      if (BinExpr_ops(e) != NULL) {
        u = expr_type (List_Expr_data(l));
        u = bin_type (List_Operator_data(BinExpr_ops(e)), u, 0);
#if 0
      } else if (u != NULL) {
        u = s;
#endif
      }
      expr (List_Expr_data(l), u);
      for (l = List_Expr_next(l),
           ops = BinExpr_ops(e);
	   l != NULL && ops != NULL;
	   l = List_Expr_next(l),
	   ops = List_Operator_next(ops)) {
        SP; operator (List_Operator_data(ops)); SP;
        u = expr_type (List_Expr_data(l));
	expr (List_Expr_data(l), bin_type (List_Operator_data(ops), u, 0));
      }
      break;
      
    case IdentExpr_kind: {
      Ident id = IdentExpr_id(e);
      Operation_def f = IdentExpr_operator(e);
      
      if (f == NULL) {
	fprintf (out, "%s", IDENT_STRING(id));
      } else {
	fprintf (out, "%s", IDENT_STRING(Operation_def_actual_id (f)));
      }
      break;
    }
    
    case IfExpr_kind:
      fprintf (out, "(");
      expr (IfExpr_cond(e), bool_type);
      fprintf (out, " ? ");
      expr (IfExpr_thn(e), t);
      for (l = IfExpr_conds(e),
           m = IfExpr_thens(e);
	   l != NULL && m != NULL;
	   l = List_Expr_next(l),
	   m = List_Expr_next(m)) {
        fprintf (out, " : ");
        expr (List_Expr_data(l), bool_type);
        fprintf (out, " ? ");
        expr (List_Expr_data(m), s);
      }
      fprintf (out, " : ");
      expr (IfExpr_els(e), s);
      fprintf (out, ")");
      break;
      
    case ConsExpr_kind:
      fprintf (out, "CREATE_LIST(");
      type(t);
      fprintf (out, ", ");
      expr (ConsExpr_lhs(e), arg_type(t));
      fprintf (out, ", ");
      expr (ConsExpr_rhs(e), t);
      fprintf (out, ")");
      break;

    case ConstExpr_kind:
      gen_const (ConstExpr_cnst(e));
      break;
      
    case Operation_kind: {
      Ident id = Operation_id(e);
      Operation_def f = Operation_operator(e);
      Definition d = Operation_defi (e);
      FunctionDef ext = Operation_ext (e);
      Func func = Operation_func (e);
            
      if (d != NULL) {
        types = get_def_types (d);
	fprintf (out, "NEW_");
	for (l = Operation_args(e), tl = types;
	     l != NULL;
	     l = List_Expr_next(l), tl = tl?List_Type_next(tl):NULL) {
	  if (tl == NULL && !Expr_warned(e)) {
            InputError (Expr_loc(e), TRUE, "Incorrect number of arguments");
            Expr_warned(e) = TRUE;
	  }
	  type_token(tl?List_Type_data(tl):expr_type(List_Expr_data(l)));
	}
	if (tl != NULL && !Expr_warned(e)) {
          InputError (Expr_loc(e), TRUE, "Incorrect number of arguments");
          Expr_warned(e) = TRUE;
	}
	fprintf (out, " (");
	fprintf (out, "%s", IDENT_STRING(id));
	for (l = Operation_args(e), tl = types;
	     l != NULL;
	     l = List_Expr_next(l), tl = tl?List_Type_next(tl):NULL) {
          fprintf (out, ", ");
	  expr (List_Expr_data(l), tl?List_Type_data(tl):NULL);
	}
        fprintf (out, ", ins)");
	break;
      }
      
      if (f != NULL) {
	fprintf (out, "NEW_");
	create_op (f, Operation_args(e), TRUE);
	  fprintf (out, " (");
	  fprintf (out, "%s", IDENT_STRING(Operation_def_actual_id (f)));
	  create_op (f, Operation_args(e), FALSE);
          fprintf (out, ", ins)");
	break;
      }
      
      if (func != NULL) {
	fprintf (out, "%s (", IDENT_STRING(Func_id(func)));
	for (l = Operation_args(e), types = Func_args(func);
	     l != NULL && types != NULL;
	     l = List_Expr_next(l), types = List_Type_next(types)) {
	  u = List_Type_data(types);
          fprintf (out, "%s", sep);
	  sep = ", ";
	  expr (List_Expr_data(l), u);
	}
        fprintf (out, ")");
	break;
      }
      
      assert (ext != NULL && FunctionDef_tag(ext) == ExtFunc_kind);
      
      if (id == Make_identifier ("IS_CONSTANT") && 
	  !type_conflict(expr_type(List_Expr_data(Operation_args(e))), int_type)) {
	fprintf (out, "TRUE");
	break;
      }
      
      if ((id == Make_identifier ("GET_CONSTANT") ||
	   id == Make_identifier ("GET_UCONSTANT")) && 
	  !type_conflict(expr_type(List_Expr_data(Operation_args(e))), int_type)) {
	expr (List_Expr_data(Operation_args(e)), int_type);
	break;
      }
      
      fprintf (out, "%s (", IDENT_STRING(id));
      for (l = Operation_args(e), types = ExtFunc_args(ext);
	   l != NULL && types != NULL;
	   l = List_Expr_next(l), types = List_Type_next(types)) {
	u = List_Type_data(types);
        fprintf (out, "%s", sep);
	sep = ", ";
	expr (List_Expr_data(l), u);
      }
      fprintf (out, ")");
      break;
    }

    case MonExpr_kind:
      monop (MonExpr_op(e));
      fprintf (out, " ");
      expr (MonExpr_arg(e), mon_type (MonExpr_op(e), t));
      break;

    case ParExpr_kind:
      fprintf (out, "(");
      expr (ParExpr_expr(e), s);
      fprintf (out, ")");
      break;
  }
  
  if (copy) fprintf (out, ")");
  if (convert) fprintf (out, ")");
}

/* Generate test for an id = Applied_formal */
static void
test_op (Operation_def f, Ident id, Bool *first, char *oper)
{  
  OPER;
#if 0
  fprintf (out, "%s == %s", IDENT_STRING(id), 
             IDENT_STRING (Operation_def_actual_id(f)));
#else
  fprintf (out, "OPR_HAS_OPER (%s, %s)", IDENT_STRING(id), 
             IDENT_STRING (Operation_def_actual_id(f)));
#endif
}

static void
test_set (Ident id, List_Applied_formal l, Bool *first, char *oper)
{
  Applied_formal a;

  OPER;
  fprintf (out, " (");
  *first = TRUE;
  for (; l; l = List_Applied_formal_next(l)) {
    a = List_Applied_formal_data(l);
    test_op (Get_operation(a), id, first, " ||");
  }
  fprintf (out, ")");
  *first = FALSE;
}

/* Generate test for an id = Applied_operation */
static void
test_opr (Ident id, Applied_operation op, Bool *first, char *oper)
{  
  switch (Applied_operation_tag(op)) {
    case AnyOp_kind:
      return;
    case AppliedOp_kind:
      test_op (Get_operation(AppliedOp_op(op)), id, first, oper);
      break;
    case OpSet_kind:
      test_set (id, OpSet_ops(op), first, oper);
      break;
  }
}

static void
test_edge_cnt (Operation_def f, Path p, Bool *first, char *oper)
{
  OPER;
  fprintf (out, "(NUM_EDGES(");
  gen_path (p, dep_type, 0);
  fprintf (out, ") == %d)", List_Type_size(Operation_def_types(f)));
}

static void
test_overload (Operation_def f, Type t, Path p, Bool *first, char *oper)
{
  OPER;
  NOT_USED(f);
  get_path (p, t, "HAS");
}

/* Generate code for the testing of the TAG (OPR) of a DAG node for
   value op.
   The node is accessed by p,t.
   If !first, the test is combined with a previous test with
   binary operator oper (&& or ||).
   For empty p and !subset, the test is quaranteed to succeed
   and suppressed by comment.
*/
static void
_test_vars (Operation_def f, Type t, Path p, Bool *first, char *oper, Bool subset)
{ Bool suppress;

  if (f==NULL) return;

  suppress = p == NULL && 
             !subset && 
	     cur_rule != NULL;
    
  if (suppress) fprintf (out, "/* ");
  if (!*first) { 
    fprintf (out, "%s ", oper); 
  } else {
    fprintf (out, " ");
  }

#if 0
  if (t == opr_type) {
    gen_path (p, t, 0);
    fprintf (out, " == %s", IDENT_STRING(Operation_def_actual_id(f)));
  } else 
#endif
  {
    if (!isdeptype(t)) {
      type (t);
      fprintf (out, "_");
    }
    fprintf (out, "HAS_OPER (");
    gen_path (p, t, 0);
    fprintf (out, ", %s)", IDENT_STRING(Operation_def_actual_id(f)));
  }
  
  if (suppress) {
    fprintf (out, " */");
  } else {
    *first = FALSE;
  }
  
  fprintf (out, "\n");
  IN;
}

static void
test_vars (Applied_formal op, Type t, Path p, Bool *first, char *oper, Bool subset)
{
  _test_vars (Get_operation(op), t, p, first, oper, subset);
}

/* Add c to *a modulo n, return carry */
int
add_carry (int *a, int c, int n)
{
  *a += c;
  c = *a / n;
  *a = *a % n;
  return c;
}

/* Insert t in l. 
   If l contains a list compatible with t, l is returned.
*/
static List_List_Type
insert_types (List_Type t, List_List_Type l)
{
  if (l == NULL) return Create_List_List_Type (t, NULL);
  
  if (!types_conflict (t, List_List_Type_data(l))) return l;
  
  List_List_Type_next (l) = insert_types (t, List_List_Type_next(l));
  return l;
}

/* Insert t in l. 
   If l contains a list compatible with t, l is returned.
*/
static List_List_TypePair
insert_typepairs (List_TypePair t, List_List_TypePair l)
{
  if (l == NULL) return Create_List_List_TypePair (t, NULL);
  
  if (!typepairs_conflict (t, List_List_TypePair_data(l))) return l;
  
  List_List_TypePair_next (l) = insert_typepairs (t, List_List_TypePair_next(l));
  return l;
}

static List_TypePair
split_type (Type s, Type t, List_TypePair r) 
{
  List_Type l;
  
  switch (Type_tag(t)) {
    case EdgeType_kind:
      for (l = EdgeType_types(t); l; l = List_Type_next(l)) {
        r = split_type (s, List_Type_data(l), r);
      }
      return r;
    default:
      return Create_List_TypePair(Create_TypePair(no_srcinfo, s,t), r); 
  }
  return r;
}

/* Cartesion product of types in l */
static List_List_TypePair
split_types (List_Type l)
{
  List_List_TypePair r;
  List_TypePair tl;
  List_TypePair rl;
  Type t;
  TypePair tp;
  List_List_TypePair s;
  
  if (l==NULL) return Create_List_List_TypePair (NULL, NULL);
  t = List_Type_data(l);
  
  s = NULL;
  for (r = split_types (List_Type_next(l)); r; r = List_List_Type_next(r)) {
    rl = List_List_Type_data (r);
    for (tl = split_type(t, t, NULL); tl; tl = List_TypePair_next(tl)) {
      tp = List_Type_data(tl);
      s = Create_List_List_TypePair (Create_List_TypePair(tp, rl), s);
    }
  }
  return s;
}

/* Return the argument types for the set of operators in l */ 
List_List_TypePair
split_formals (List_Applied_formal l)
{
  Operation_def f;
  List_Type t;
  List_List_TypePair tl;
  List_List_TypePair r;
  
  if (l == NULL) return NULL;
  
  f = Get_operation (List_Applied_formal_data(l));
  r = split_formals (List_Applied_formal_next(l));
  if (f == NULL) return r;
  t = Operation_def_types(f);
  for (tl = split_types (t); tl; tl = List_List_TypePair_next(tl)) {
    r = insert_typepairs (List_List_TypePair_data(tl), r);
  }
  
  return r;
}

/* Test for ANY pattern */
static Bool
is_any (Pattern p)
{
  switch (Pattern_tag(p)) {
    case DontCarePattern_kind:
      return DontCarePattern_expr(p)==NULL;
    case TypedPattern_kind:
      return is_any (TypedPattern_pat(p));
    case IdentPattern_kind:
    case DefPattern_kind:
    case OpPattern_kind:
    case ConsPattern_kind:
    case NullPattern_kind:
    case ConstPattern_kind:
      return FALSE;
  }
  return FALSE;
}

/* Compute a mask for l. Bit i is 1 iff argument pattern i is not
   any pattern.
   The mask is used to test the non-any patterns for a dep type. 
*/
int
arg_mask (List_Pattern l, int i)
{
  int m = 0;
  
  if (l == NULL) return m;
  m = arg_mask (List_Pattern_next(l), i+1);
  if (!is_any(List_Pattern_data(l))) m |= (1<<i);
  return m;
}

/* Generate code testing patterb p under (path,t).
   The test is combined with a possible preceeding test 
   (indicated by first) using operator oper (&& or ||).
   A pattern may require several tests, due to
   commutativity and/or distinctly typed operators in a set.
   This function generates one of them, indicated by a state
   Pattern_swap, Pattern_types. 
   The first indicates swapping due to commutativity, 
   the second which of the distinctly typed operators is used.
   The state is is incremented by adding carry to it.
   This new state is kept in Pattern__swap, Pattern__types.
   The function returns a new carry.
   If the carry comes out at the end (top level call of test_pattern),
   all possible tests have been generated.
*/
static int
test_pattern (Pattern p, Path path, Type t, Type ut, 
              Bool *first, char *oper, int carry)
{
  Applied_operation op;
  List_Pattern args, args1;
  List_Applied_formal l, l1;
  Operation_def f;
  List_TypePair lt;
  Path p1;
  TypePair t1;
  int i;
  Expr exp = NULL;

  Bool cur_swap;
  
  List_TypePair the_types = NULL;
  List_List_TypePair types;
  int num_types;
  Bool overloaded;
  
  if (p==NULL) return carry;
  
  Pattern_type(p) = t;
  
  if (type_conflict (ut, t)) {
    OPER;
    get_path (path, t, "HAS");
  }

  switch (Pattern_tag(p)) {
    case IdentPattern_kind: 
      { Bind_Operation_def b = Retrieve_Bind (IdentPattern_id(p), NULL, doggy_DefaultNameSpace, Bind_Operation_def_kind); 
        if (b != NULL) { 
	  Operation_def f = (Operation_def)Bind_object(b);                                                                         
	  if (f != NULL) {
            Applied_formal a = Create_Applied_formal(make_src_info(-1), IdentPattern_id(p));
	    Applied_formal_ap(a) = f;
	    op = Create_AppliedOp(make_src_info(-1),a);
	    args = NULL;
            break;
	  }
	}
      }                                                                           
      return carry;
    case DontCarePattern_kind:
      exp = DontCarePattern_expr(p);
      if (exp==NULL) return carry;
      /* Fall through */
    case ConstPattern_kind:
      OPER;
      if (isdeptype(t) || type_conflict (t,int_type)) {
        if (!isdeptype(t)) { type (t); fprintf (out, "_"); }
	fprintf (out, "HAS_IMM_VAL(");
        gen_path (path, t, 0);
        fprintf (out, ", ");
      } else {
        fprintf (out, "(");
        gen_path (path, t, 0);
        fprintf (out, " == ");
      }
      if (Pattern_tag(p) == ConstPattern_kind) {
        fprintf (out, "%d", ConstPattern_cnst(p));
      } else {
        expr (exp, int_type);
      }
      fprintf (out, ")");
      return carry;
    case NullPattern_kind:
      OPER;
      fprintf (out, "(");
      gen_path (path, t, 0);
      fprintf (out, " == ");
      fprintf (out, "NULL)");
      return carry;
    case DefPattern_kind:
      return test_pattern (DefPattern_arg(p), path, t, ut,
                           first, oper, carry);
    case OpPattern_kind:
      op   = OpPattern_op(p);
      args = OpPattern_args(p);
      break;
    case ConsPattern_kind: {
      Type rt = t;
      OPER;
      fprintf(out,"!IS_NULL(");
      gen_path(path, t, 0);
      fprintf(out,")");
      carry = test_pattern (ConsPattern_lhs(p), Create_Path (no_srcinfo, 0, rt, path), 
      			    arg_type(t), arg_type(ut),
                            first, oper, carry);
      carry = test_pattern (ConsPattern_rhs(p), Create_Path (no_srcinfo, 1, rt, path), 
      			    t, ut,
                            first, oper, carry);
      return carry;
    }
    case TypedPattern_kind:
      if (type_conflict (ut, TypedPattern_btype(p))) {
        if (type_conflict (t, TypedPattern_btype(p))) {
	  OPER;
          fprintf (out, "FALSE");
	} else if (!type_conflict (ut, t)) {
	  OPER;
	  get_path (path, TypedPattern_btype(p), "HAS");
	}
      }
      return test_pattern (TypedPattern_pat(p), path, TypedPattern_btype(p), TypedPattern_btype(p),
                           first, oper, carry);
  }
  
  /* Pattern_tag(p) == OpPattern_kind */
  switch (Applied_operation_tag(op)) {
    case AnyOp_kind:
      OPER;
      fprintf (out, "test_any(");
      gen_path (path, t, 0);
      fprintf (out, ", %d, %u)\n", List_Pattern_size (args), arg_mask (args, 0));
      for (args1 = args, i = 0;
	   args1 != NULL;
	   args1 = List_Pattern_next(args1), i++) {
	p1 = Create_Path (no_srcinfo, i, dep_type, path);
	carry = test_pattern (List_Pattern_data(args1),  
                              p1, Pat_type(List_Pattern_data(args1)), dep_type, 
			      first, oper, carry);
      }
      return carry;
    case OpSet_kind:
      l = OpSet_ops(op);
      break;
    case AppliedOp_kind:
      l = Create_List_Applied_formal (AppliedOp_op(op), NULL);
      break;
  }
  
  types = split_formals (l);
  num_types = List_List_TypePair_size (types);

  /* Remember current types and increment _types */
  Pattern_types(p) = Pattern__types(p);
  carry = add_carry (&Pattern__types(p), carry, num_types);
  
  /* Select current type */
  for (i = 0; types; types = List_List_Type_next(types), i++) {
    if (i==Pattern_types(p)) {
      the_types = List_List_Type_data(types);
      break;
    }
  }
#if 0
  /* Allow nullary operators */
  assert (the_types != NULL);
#endif

  /* Remember current swap and increment _swap */
  Pattern_swap(p) = Pattern__swap(p);
  
  for (l1 = l; l1; l1 = List_Applied_formal_next(l1)) {
    /* If any op is commutative, increment swap by carry */
    if (commutative(Get_operation(List_Applied_formal_data(l1)))) {
      carry = add_carry (&Pattern__swap(p), carry, 2);
      break;
    }
  }
  cur_swap = Pattern_swap(p);
  
  /* Get any op */
  f = Get_applied_op (op);
  if (f==NULL) return carry;
  
  /* Generate test for current types and swap */
  
  if (List_Applied_formal_next(l) == NULL) {
    test_vars (List_Applied_formal_data(l), t, path, first, oper, cur_swap);
  } else {
    Bool any = FALSE;
    
    if (!*first) fprintf (out, "%s ", oper); 
    fprintf (out, "(");
    *first = TRUE;
    oper = "||";
    indent++;
    for (l1 = l; l1; l1 = List_Applied_formal_next(l1)) {
      f = Get_operation(List_Applied_formal_data(l1));
      if (types_pair_conflict (Operation_def_types(f), the_types)) continue;
      if (cur_swap && !commutative(f)) continue;
      any = TRUE;
      test_vars (List_Applied_formal_data(l1), t, path, first, oper, cur_swap || num_types>1);
    }
    if (*first) { 
      if (any) {
        fprintf (out, "TRUE\n"); IN; 
      } else {
        fprintf (out, "FALSE\n"); IN; 
      }
    }
    indent--;
    fprintf (out, ") ");
    *first = FALSE;
    oper = "&&";
  }

  /* Generate overload resolution test */
  
  overloaded = Operation_def_mop(f) != NULL &&
               ActualOp_overloaded(Operation_def_mop(f));
  if (overloaded) {
    test_edge_cnt (f, path, first, oper);
  }
  
  /* Recurse on the argument for current swap value */
     
  for (lt = the_types,
       args1 = args, i=0;
       lt != NULL && args1 != NULL;
       lt = List_Type_next(lt),
       args1 = List_Pattern_next(args1), i++) {
    Type rt = Operation_def_node_type(f);
    if (cur_swap) i = 1-i;
    p1 = Create_Path (no_srcinfo, i, rt, path);
    t1 = List_Type_data(lt);
    if (overloaded) {
      test_overload (f, TypePair_t2(t1), p1, first, oper);
    }
    carry = test_pattern (List_Pattern_data(args1),  
                          p1, TypePair_t2(t1), TypePair_t1(t1), 
			  first, oper, carry);
  }
  return carry;
}

static void
actions (List_Expr l, Type t, int i)
{
  if (l==NULL) return;
  
  IN;
    if (!isdeptype(t)) { type (t); fprintf (out, "_"); }
    fprintf (out, "REPLACE (ins, ");  
    expr (List_Expr_data(l), t); 
  fprintf (out, ", %d);\n", i); 
  actions (List_Expr_next(l), t, i-1);
}

/* Generate code for the replacement of a DAG node by e new one */
static void
action (List_Expr l, Rule r, Type t)
{  
  if (r == NULL) {
    /* generate code for a function */
    IN; 
    if(!List_Expr_next(l)) {
      fprintf (out, "return ");
      expr (List_Expr_data(l), t);
    } else {
      expr (List_Expr_data(l), void_type);
    }
    fprintf (out, ";\n");
    if(List_Expr_next(l)) action(List_Expr_next(l), r, t);
    return;
  }
  fprintf (out, "\n");
  IN; fprintf (out, "REASON("); rule_id(r);
  fprintf (out, ");\n");
  
  actions (l, t, List_Expr_size(l)-1);
  
  IN; fprintf (out, "return TRUE;\n");
}

List_Expr
ExprGuard_body (Guard g)
{
  if (g==NULL) return NULL;
  if (Guard_tag(g) != ExprGuard_kind) return NULL;
  if (ExprGuard_exprs(g) == NULL) return NULL;
  
  switch (ExprSeq_tag(ExprGuard_exprs(g))) {
    case OneExpr_kind:
      return Create_List_Expr (OneExpr_expr(ExprGuard_exprs(g)), NULL);
    case MoreExprs_kind:
      return MoreExprs_exprs(ExprGuard_exprs(g));
  }
  return NULL;
}

/* Determine initialization order for definitions */

static int determine_order (Expr cond, Wherepart w)
{
  int cond_order;

  current_order = 0;
  Traverse_void_Wherepart (w, &Reset_Order);
  Traverse_void_Expr (cond, &Determine_Order);
  cond_order = current_order;
  Traverse_void_Wherepart (w, &Determine_Order);
  return cond_order;
}

/* Gen code for the Rhs r for rule, 
   i.e. where parts and replacement action.
*/
static void
gen_rhs (Rhs r)
{
  List_Guard l;
  Guard g;
  Wherepart w;
  Bool has_where;
  int cond_order;
  
  switch (Rhs_tag(r)) {
    case PlainRhs_kind:
      for (l = PlainRhs_guards(r); l; l = List_Guard_next(l)) {
        g = List_Guard_data(l);
	w = Guard_where(g);
	has_where = w != NULL && Wherepart_defs(w) != NULL;
	switch (Guard_tag(g)) {
	  case RhsGuard_kind:
	    cond_order = determine_order (Guard_conds(g), w);
            if (has_where) { IN; BEGIN_SCOPE; where_vars (w, 0, cond_order); }   
	    IN; fprintf (out, "if ("); expr (Guard_conds(g), bool_type);
	    fprintf (out, ") ");
	    BEGIN_SCOPE;
	      where_vars (w, cond_order, current_order);
	      gen_rhs  (RhsGuard_rhs(g));
	    END_SCOPE;
	    break;
	  case ExprGuard_kind:
	    cond_order = determine_order (Guard_conds(g), w);
            if (has_where) { IN; BEGIN_SCOPE; where_vars (w, 0, cond_order); }   
	    if (Guard_conds(g) != NULL) {
	      IN; fprintf (out, "if ("); 
		  expr (Guard_conds(g), bool_type);
	          fprintf (out, ") ");
	      BEGIN_SCOPE;
	        where_vars (w, cond_order, current_order);
	        action (ExprGuard_body(g), cur_rule, cur_type);
	      END_SCOPE;      
	    } else {
	      where_vars (w, 0, current_order);
	      action (ExprGuard_body(g), cur_rule, cur_type);      
	    }
	    break;
	}
	if (has_where) END_SCOPE;
      }
      break;
    case BlockRhs_kind:
      w = BlockRhs_where(r);
      if (w != NULL && Wherepart_defs(w) != NULL) { 
        IN; BEGIN_SCOPE; 
	  cond_order = determine_order (NULL, w);
	  where_vars (w, 0, current_order);
          gen_rhs (BlockRhs_rhs(r)); 
	END_SCOPE;    
      } else {
        gen_rhs (BlockRhs_rhs(r));      
      } 
      break;
  }
}

/* Generate code for all tests for p,
   followed by the corresponding replacement action.
   This is done by adding 1 to the state in p for each test
   being generated, until a carry comes out, see test_pattern
   above.
*/
static void
test_lhs (Pattern p)
{
   Bool first = TRUE;
   int carry = 0;
   
   while (carry == 0) {
     IN; fprintf (out,"if (");
       indent += 2;
       first = TRUE;
       carry = test_pattern (p, NULL, Pat_type(p), dep_type, &first, "&&", 1);
       if (first) {
         fprintf (out, "TRUE) ");
       } else {
         IN; fprintf (out, ") ");
       }
       indent -= 2;
     BEGIN_SCOPE;
       pattern_vars (p, NULL);
       gen_rhs (Rule_rhs(cur_rule));
     END_SCOPE; 
   }
}

/* Generate code for all tests for p,
   followed by the corresponding return.
   This is done by adding 1 to the state in p for each test
   being generated, until a carry comes out, see test_pattern
   above.
*/
static void
test_func (FuncRule p)
{
   Bool first = TRUE;
   int carry = 0;
   List_Argument l;
   Argument a;
   ArgPat a1;
   
   while (carry == 0) {
     IN; fprintf (out,"if (");
       indent += 2;
       first = TRUE;
       carry = 1;
       for (l = FuncRule_args(p); l; l = List_Argument_next(l)) {
         a = List_Argument_data(l);
	 a1 = Argument_pat(a);
	 arg_name = IDENT_STRING(Argument_id(a));
	 switch (ArgPat_tag(a1)) {
	   case PatArg_kind:
	     if (PatArg_pat(a1) != NULL) carry = test_pattern (PatArg_pat(a1), NULL, Argument_type(a), Argument_type(a), &first, "&&", carry);
	     break;
	   case SetArg_kind:
	     test_opr (Argument_id(a), SetArg_set(a1), &first, "&&");
             break;
	 }
       }
       if (first) {
         fprintf (out, "TRUE) ");
       } else {
         IN; fprintf (out, ") ");
       }
       indent -= 2;
     BEGIN_SCOPE;
       for (l = FuncRule_args(p); l; l = List_Argument_next(l)) {
	 a = List_Argument_data(l);
	 a1 = Argument_pat(a);
	 arg_name = IDENT_STRING(Argument_id(a));
	 if (ArgPat_tag(a1) == PatArg_kind) {
	   if (PatArg_pat(a1) != NULL) pattern_vars (PatArg_pat(a1), NULL);
	 }
       }
       gen_rhs (FuncRule_rhs(p));      
     END_SCOPE; 
   }
}


/* Generate code for rule r.
   This is a c-function, testing the pattern for r and
   then applying r in case of a match.
   It returns a boolean indicating a successful match.
*/
static void
gen_rule (Rule r)
{         
  char *boolt = find_type_name (bool_type, "Bool");
   
   if (!Rule_rhs_supported(r)) {
     InputWarning (Rule_loc(r), TRUE, 2, 
                   "Rhs of rule is not supported: rule disabled\n"); 
   }
   
   if (!Rule_supported(r)) return;
   
   cur_rule = r;
   cur_func = NULL;
   cur_type = Pat_type (Lhs_pat(Rule_lhs(r)));
   arg_name = "ins";
   
   gen_comments (Rule_src_info(r)->pre_comment);
   { Bool s = suppress_comment;
     suppress_comment = TRUE;
     print_file = out;
     print_str ("/* ");
     Print_Rule(r);
     print_str ("*/"); Print_NL ();
     suppress_comment = s;
   }
   fprintf (out, "static %s\n", boolt);
   rule_id (r);
   fprintf (out, " (");
   type (cur_type);
   fprintf (out, " ins)\n");
   BEGIN_SCOPE;  
     test_lhs (Lhs_pat(Rule_lhs(r))); 
     IN; fprintf (out, "return FALSE;\n");
   END_SCOPE;
   fprintf (out, "\n");
}

static void
gen_func_header (Func p, Bool forward)
{      
   List_FuncRule l;
   List_Argument a;
   char *sep = "";
   
   cur_type = Func_type(p);
   
   if (!Func_ext(p)) {
     fprintf (out, "static "); 
   } else if (forward) {
     fprintf (out, "extern "); 
   }
   type (cur_type);
   fprintf (out, "%s", forward?" ":"\n");
   fprintf (out, "%s (", IDENT_STRING (Func_id(p)));
   
   l = Func_rules(p);
   for (a = FuncRule_args(List_FuncRule_data(l)); a; a = List_Argument_next(a)) {
     fprintf (out, "%s", sep);
     type (Argument_type(List_Argument_data(a)));
     fprintf (out, " %s", IDENT_STRING(Argument_id(List_Argument_data(a))));
     sep = ", ";
   }
   
   fprintf (out, ")%s\n", forward?";":"");
}

/* Generate code for function p.
   This is a c-function, testing the pattern for p.
   It returns a boolean indicating a successful match.
*/
static void
gen_func (Func p)
{      
   List_FuncRule l;
   
   cur_rule = NULL;
   cur_type = Func_type(p);
   
   gen_comments (Func_src_info(p)->pre_comment);
   { Bool s = suppress_comment;
     suppress_comment = TRUE;
     print_file = out;
     print_str ("/* ");
     Print_Func(p);
     print_str ("*/"); Print_NL ();
     suppress_comment = s;
   }
   
   gen_func_header (p, FALSE);

   BEGIN_SCOPE;
   
     for (l = Func_rules(p); l; l = List_FuncRule_next(l)) {
       cur_func = List_FuncRule_data(l);
       if (!FuncRule_supported(cur_func)) continue;
       test_func (cur_func);
     }

     IN; fprintf (out, "return ");
     default_val(cur_type);
     fprintf (out, ";\n");
   END_SCOPE;
   fprintf (out, "\n");
}

static Bool
/* The operation of op = f1 */
_has_operation (Applied_formal op, Operation_def f1)
{
  return Get_operation(op)==f1;
}

/* Pattern p contains operation f at top level */
static Bool
has_operation (Pattern p, Operation_def f)
{
  Applied_operation op;
  List_Applied_formal l;
  
  switch (Pattern_tag(p)) {
    case DefPattern_kind:
      return has_operation (DefPattern_arg(p), f);
    case ConstPattern_kind:
    case NullPattern_kind:
    case IdentPattern_kind:
    case DontCarePattern_kind:
      return !type_conflict(Operation_def_result(f),Pattern_type(p));
    case OpPattern_kind:
      op = OpPattern_op (p);
      break;
    case ConsPattern_kind:
      return is_list_id (Operation_def_id(f));
    case TypedPattern_kind:
      return has_operation (TypedPattern_pat(p), f);
  }
  
  switch (Applied_operation_tag(op)) {
    case AnyOp_kind:
      return TRUE;
    case OpSet_kind:
      for (l = OpSet_ops(op); l; l = List_Applied_formal_next(l)) {
        if (_has_operation (List_Applied_formal_data(l), f)) return TRUE;
      }
      return FALSE;
    case AppliedOp_kind:
      return _has_operation (AppliedOp_op(op), f);
  }
  return FALSE;
}

/***********/
/* Mop list computation */

static List_ActualOp
insert_mop (List_ActualOp l, Ident id, Operation_def f)
{
  ActualOp mop;
    
  if (l == NULL) {
    mop = Create_ActualOp (no_srcinfo, Operation_def_loc(f), id, Create_List_Operation_def (f, NULL));
    Operation_def_mop(f) = mop;
    if (Operation_def_src(f)) ActualOp_src(mop) = TRUE;
    if (Operation_def_tgt(f)) ActualOp_tgt(mop) = TRUE;
    return Create_List_ActualOp (mop, NULL);
  }
  
  mop = List_ActualOp_data (l);
  if (ActualOp_id (mop) != id) {
    List_ActualOp_next(l) = insert_mop (List_ActualOp_next(l), id, f);
    return l;
  }
  if (ActualOp_formals(mop) != NULL) {
    ActualOp_overloaded(mop) = TRUE;
  }
  ActualOp_formals(mop) = Create_List_Operation_def (f, ActualOp_formals(mop));
  Operation_def_mop(f) = mop;
  return l;
}


List_ActualOp 
Action_Compute_Supported_Mops_Operation_def (Operation_def f, List_ActualOp mops)
{ if (!Operation_def_supported (f)) return mops;
  return insert_mop (mops, Operation_def_actual_id(f), f);
}

/* Definition order computation */
	 
List_ActualOp 
Action_Compute_All_Mops_Operation_def (Operation_def f, List_ActualOp mops)
{
  return insert_mop (mops, Operation_def_actual_id(f), f);
}

/* Reset order functions */
void Action_Reset_Order_Definition (Definition e)
{ if (e==NULL) return;
  Definition_order (e) = -1;
}

/* Determine order functions */

void Action_Determine_Order_Expr (Expr e)
{ Definition d = NULL;
  
  if (e == NULL) return;
  switch (Expr_tag(e)) {
    case IdentExpr_kind:
      d = IdentExpr_def (e);
      break;
    case Operation_kind:
      d = Operation_defi (e);
      break;
    default:
      return;
  }
  Traverse_void_Definition (d, &Determine_Order);
}

void Action_Determine_Order_Definition (Definition e)
{ if (e==NULL || Definition_order (e) >= 0) return;
  Definition_order (e) = current_order++;
}

/***********/

static void init_traversals (void)
{
  static Bool done = FALSE;
  
  if (done) return;
  done = TRUE;

  Compute_Supported_Mops.action_Operation_def[PRE_ACTION] = (void*)Action_Compute_Supported_Mops_Operation_def;
  Compute_All_Mops.action_Operation_def[PRE_ACTION] = (void*)Action_Compute_All_Mops_Operation_def;
  Reset_Order.action_Definition[POST_ACTION] = (void*)Action_Reset_Order_Definition;
  Determine_Order.action_Expr[POST_ACTION] = Action_Determine_Order_Expr;
  Determine_Order.action_Definition[POST_ACTION] = Action_Determine_Order_Definition;
}

/* Return the list of supported concrete operations */
static List_ActualOp
find_ops (Bool supported_only)
{
  List_ActualOp mops = NULL;
  Ident id;

  if(supported_only) {
    mops = Traverse_machine_description (doggy_source(doggy_root), &Compute_Supported_Mops, mops);
    mops = Traverse_machine_description (doggy_target(doggy_root), &Compute_Supported_Mops, mops);
  } else {
    mops = Traverse_machine_description (doggy_source(doggy_root), &Compute_All_Mops, mops);
    mops = Traverse_machine_description (doggy_target(doggy_root), &Compute_All_Mops, mops);
  }
  
  { List_ActualOp l;
    int n = 0;
    for (l = mops, n = 0; l; l = List_ActualOp_next(l), n++) {
      id = ActualOp_id (List_ActualOp_data(l));
      if (overload_conflict (List_ActualOp_data(l))) {
	InputError (ActualOp_location (List_ActualOp_data(l)),
	            TRUE, "Overload conflict for operator %s", IDENT_STRING(id));
      }
    }
  }
  return mops;
}


static void arg_cast (Pattern p)
{
  switch (Pattern_tag(p)) {
    case ConsPattern_kind:
      fprintf (out, "(LIST)");
      break;
    default:
      break;
  }
}

/***********/

static int
gen_op_test (ActualOp mop, Bool gen)
{
  List_Operation_def o;
  Operation_def f;
  char *oper = "";
  List_Type t;
  int i;
  
  if (gen) {
    return ActualOp_formals(mop) != NULL;
  }
  
  IN; fprintf (out, "if (");
  
  for (o = ActualOp_formals(mop); o; o = List_Operation_def_next(o)) {
    f = List_Operation_def_data(o);
    fprintf (out, "%s", oper);
    fprintf (out, "(NUM_EDGES(ins) != %d ", 
                  List_Type_size(Operation_def_types(f))); 
    oper = " || ";
    for (t = Operation_def_types(f), i = 0; t; t = List_Type_next(t), i++) {
      fprintf (out, "%s!HAS_", oper);
      type (List_Type_data(t));
      fprintf (out, "(%d,ins)", i);
    }
    fprintf (out, ")");
    oper = " && ";
  }
  fprintf (out, ") ");
  
  BEGIN_SCOPE;
    IN; fprintf (out, "OPER_ERROR (NUM_EDGES(ins), \"%s\");\n",
                 IDENT_STRING(Operation_def_actual_id(f)));       
  END_SCOPE;
  return 1;
}

/***********/

/* Each case in the switch tests for those rules that
   contain the operation at the top-level pattern.
   The function returns a boolean indicating a successful match.
*/
static int
gen_tests (ActualOp mop, Bool gen)
{
  List_Rule l;
  Rule r;
  List_Operation_def o;
  Operation_def f;
  Operation_def def = NULL;
  int num_rules = 0;
  
  for (l = RuleSection_rules (Cur_section); l; l = List_Rule_next(l)) {
    r = List_Rule_data(l);
    for (o = ActualOp_formals(mop); o; o = List_Operation_def_next(o)) {
      f = List_Operation_def_data(o);
      if (!has_operation (Lhs_pat(Rule_lhs(r)),f)) continue;
      if (!Rule_supported(r)) continue;
      def = f;
      num_rules++;
      if (gen) continue;
      IN; fprintf (out, "if (");
	rule_id(r); fprintf (out, " (");
	arg_cast (Lhs_pat(Rule_lhs(r)));
	fprintf (out, "ins)) return TRUE;\n");
      break;
    }
  }
  if (gen) return num_rules;
  
  if (num_rules==0 && RuleSection_rules (Cur_section) != NULL &&
      (ExtraWarnings || (def != NULL && is_targ(def)))
     ) {
    InputWarning (ActualOp_location(mop), TRUE, 1, "Operation %s has no applicable rules",
              IDENT_STRING(ActualOp_id(mop)));
  }
  return num_rules;
}

/* Generate a function with a switch statement on the concrete 
   operations in mops.
   The boolean search_ops indicates that concrete operators
   are not modelled by integrals. In that case, the macro
   OPER_NUM is used to extract an integral value usable in a
   switch statement.
*/
static void
gen_switch (Type t, char *fname, int (gen)(ActualOp, Bool), Bool src, Bool tgt)
{
  int n;
  List_ActualOp mops;
  ActualOp mop, the_mop = NULL;
  List_Operation_def l;
  Type u = dep_type;
  Int do_something = 0;
  Bool mop_cnt = 0;
  char *boolt = find_type_name (bool_type, "Bool");
  
  for (mops = supported_mops, n = 0; mops; mops = List_ActualOp_next(mops), n++) {
    int tests;
    mop = List_ActualOp_data (mops);
    if (src && ActualOp_src(mop)) {}
    else if (tgt && ActualOp_tgt(mop)) {}
    else continue;
    if (ActualOp_formals(mop) == NULL) continue;
    for (l = ActualOp_formals(mop); l; l = List_Operation_def_next(l)) {
      Operation_def f = List_Operation_def_data(l);
      if (Operation_def_result (f) != NULL) u = Operation_def_result (f);
    }
    if (type_conflict(t, u)) continue; /* Not for this type */
    mop_cnt++;
    tests = gen(mop, TRUE);
    if (tests == 0) continue;
    do_something += tests;
    if (do_something == 1) the_mop = mop;
  }
  
  if (!do_something) return;
  
  fprintf (out, "%s %s", boolt, fname);
  if (!isdeptype(t)) { fprintf (out, "_"); type (t); }
  fprintf (out, " ("); type (t);
  fprintf (out, " ins)\n");
  BEGIN_SCOPE;
  
  if (do_something == 1 && mop_cnt == 1) {
    gen (the_mop, FALSE);
    IN; fprintf (out, "return FALSE;\n");
    END_SCOPE;
    fprintf (out, "\n");
    return;
  }
  
  if (search_ops) {
    IN; 
    fprintf (out, "switch (OPER_NUM(");
    if (!isdeptype(t)) { type (t); fprintf (out, "_"); }
    fprintf (out, "OPERATOR(ins))) ");
  } else {
    IN; 
    fprintf (out, "switch (");
    if (!isdeptype(t)) { type (t); fprintf (out, "_"); }
    fprintf (out, "OPERATOR(ins)) ");
  }
  BEGIN_SCOPE;
  for (mops = supported_mops, n = 0; mops; mops = List_ActualOp_next(mops), n++) {
    mop = List_ActualOp_data (mops);
    if (src && ActualOp_src(mop)) {}
    else if (tgt && ActualOp_tgt(mop)) {}
    else continue;
    for (l = ActualOp_formals(mop); l; l = List_Operation_def_next(l)) {
      Operation_def f = List_Operation_def_data(l);
      if (Operation_def_result (f) != NULL) u = Operation_def_result (f);
    }
    if (type_conflict(t, u)) continue; /* Not for this type */
    
    if (search_ops) {
      IN; fprintf (out, "case %d: /* %s */\n", n,
                      IDENT_STRING(ActualOp_id(mop)));
    } else {
      IN; fprintf (out, "case %s:\n",
                      IDENT_STRING(ActualOp_id(mop)));
    }
    indent++;
    gen (mop, FALSE);
    IN; fprintf (out, "break;\n");
    indent--;
  }
    IN; fprintf (out, "default:\n");
    indent++;
    IN; fprintf (out, "break;\n");
    indent--;
    
  END_SCOPE;
  IN; fprintf (out, "return FALSE;\n");
  END_SCOPE;
  fprintf (out, "\n");
}

/* Generate code for the initialization of an operator table,
   mapping operator numbers onto concrete operators. 
*/
static void
gen_init (void)
{
  List_ActualOp l;
  int n = 0;
  Ident id;
  
  for (l = supported_mops, n = 0; l; l = List_ActualOp_next(l), n++) {
    id = ActualOp_id (List_ActualOp_data(l));
    fprintf (out, "#define %s\tall_ops[%d]\n", IDENT_STRING(id), n);
  }
  
  fprintf (out, "\nstatic OPR all_ops[%d];\n\n", n);
  
  fprintf (out, "static void init (void)\n");
  BEGIN_SCOPE;
  for (l = supported_mops, n = 0; l; l = List_ActualOp_next(l), n++) {
    id = ActualOp_id (List_ActualOp_data(l));
    IN;
    fprintf (out, "all_ops[%d] = FIND_OP(%s, %d);\n", 
                  n, IDENT_STRING(id), n);
  }
  END_SCOPE;
  fprintf (out, "\n\n");
}

/* Generate run-time support functions */
static void
gen_test_any (void)
{
  char *dep = find_type_name (dep_type, "DEP");
  char *boolt = find_type_name (bool_type, "Bool");
  
  fprintf (out, "#ifndef TEST_ANY\n");
  fprintf (out, "#define TEST_ANY\n");
  fprintf (out, "static %s\n", boolt);
  fprintf (out, "test_any (%s d, int n, unsigned int mask)\n", dep);
  fprintf (out, "{\n");
  fprintf (out, "  int i;\n");
  fprintf (out, "  \n");
  fprintf (out, "  if (NUM_EDGES(d) != n) return FALSE;\n");
  fprintf (out, "  \n");
  fprintf (out, "  for (i = 0; i < n; i++) {\n");
  fprintf (out, "    if ((mask & (1<<i)) != 0 && IS_NULL(GET_%s(i, d))) return FALSE;\n", dep);
  fprintf (out, "  }\n");
  fprintf (out, "  return TRUE;\n");
  fprintf (out, "}\n");
  fprintf (out, "#endif\n\n");
}

static void
gen_funcs (void)
{
  gen_test_any ();
}
/* Initialize doggy_root */
void
init_doggy_root ()
{
  List_Section s;
  List_Rule l;
  Section sect;

  for (s = doggy_sections(doggy_root); s; s = List_Section_next(s)) {
    sect = List_Section_data(s);
    switch (Section_tag(sect)) {
      case FuncSection_kind:
         doggy_functions(doggy_root) 
	   = append_funcs (doggy_functions(doggy_root), 
	                   FuncSection_funcs (sect));
        break;
      case RuleSection_kind:
         for (l = RuleSection_rules (sect); l; l = List_Rule_next(l)) {
	   Rule_rules_id (List_Rule_data(l)) = RuleSection_rules_id (sect);
	 }
         doggy_rules(doggy_root) 
	   = append_rules (doggy_rules(doggy_root), 
	                   RuleSection_rules (sect));
        break;
    }
  }
}

void start_doggy (char *fn)
{  
  extern FILE *doggy_in;
  
  Make_identifier_table ();
  doggy_in = NULL;
  if (fn != NULL) {
    doggy_in = fopen (fn, "rb");
  } else {
    doggy_in = stdin;
    fn = "stdin";
  }
  if (doggy_in == NULL) {
    FrontError (TRUE, "Cannot open file %s", fn);
    exit (1);
  }
  scan_init (fn);
#if 0
  init_types ();
#endif
  doggy_parse();
  if (NumErrors > 0) exit (1);

  init_traversals ();

  init_doggy_root ();
  EvalComments ();
  supported_mops = find_ops (TRUE);
  all_mops = find_ops (FALSE);
}


static List_Type insert_type (Type t, List_Type l)
{
  if (l == NULL) {
    return Create_List_Type (t, l);
  }
  
  if (!type_conflict(t, List_Type_data(l))) return l;
  List_Type_next(l) = insert_type (t, List_Type_next(l));
  return l;
}

static List_Type node_types (void)
{
  List_Type l = Create_List_Type (dep_type, NULL);
  List_Operation_def m;
  machine_description md;
  
  md = doggy_source(doggy_root);  
  if (md != NULL) {
    for (m = machine_description_defs(md); m; m = List_Operation_def_next(m)) {
      Operation_def f =  List_Operation_def_data (m);
      if (Operation_def_result(f) != NULL) insert_type (Operation_def_result(f), l);
    }
  }
  md = doggy_target(doggy_root);  
  if (md != NULL) {
    for (m = machine_description_defs(md); m; m = List_Operation_def_next(m)) {
      Operation_def f =  List_Operation_def_data (m);
      if (Operation_def_result(f) != NULL) insert_type (Operation_def_result(f), l);
    }
  }
  return l;
}

static void pattern_use (Pattern p, Expr e)
{
  int c;
  if (p == NULL) return;

  switch (Pattern_tag(p)) {
  case IdentPattern_kind: c=++IdentPattern_use_cnt(p); break; 
  case DefPattern_kind:   c=++DefPattern_use_cnt(p); break;
  default: abort();
 }
  IdentExpr_use_cnt(e) = c;
#if 0
  if (tree && IdentExpr_use_cnt(e) > 1) 
     InputWarning (Expr_loc(e), 5, TRUE, "Double use %s", IDENT_STRING(IdentExpr_id(e)));
#endif
}

static void def_use (Definition p, Expr e)
{
  if (p == NULL) return;
  
  Definition_use_cnt(p)++;
  IdentExpr_use_cnt(e) = Definition_use_cnt(p);
#if 0
  if (tree && IdentExpr_use_cnt(e) > 1) 
     InputWarning (Expr_loc(e), 5, TRUE, "Double use %s", IDENT_STRING(IdentExpr_id(e)));
#endif
}

static void arg_use_cnt (Expr e)
{
  List_Expr l;

  if (e==NULL) return;
  switch (Expr_tag(e)) {
    case ParExpr_kind:
      arg_use_cnt (ParExpr_expr(e));
      return;
    case BinExpr_kind:
      if (BinExpr_ops(e) == NULL) {
        arg_use_cnt (List_Expr_data(BinExpr_args(e)));
        return;
      }
      break;
    case Operation_kind:
#if 0
      if (Operation_operator(e) != NULL) break;
#endif
      l = Operation_args(e);
      if (Operation_ext(e) != NULL && 
          l != NULL && List_Expr_next(l)==NULL) {
        FunctionDef f = Operation_ext(e);
	Type t = NULL;
	if (FunctionDef_tag(f) == ExtFunc_kind) t = List_Type_data(ExtFunc_args(f));
	t = norm_type(t);
	if (t != NULL && Type_tag(t) == IdentType_kind) {
	  char *s = IDENT_STRING(IdentType_type_id(t));
	  if (strncmp (s,IDENT_STRING(Operation_id(e)), strlen(s))==0) {
            /* Probably access function */
            break;
	  }
	}
      }
      for (; l; l = List_Expr_next(l)) {
	arg_use_cnt (List_Expr_data(l));
      }
      break;
    case ConsExpr_kind:
      arg_use_cnt (ConsExpr_lhs(e));
      arg_use_cnt (ConsExpr_rhs(e));
      break;
    case IfExpr_kind:
      arg_use_cnt (IfExpr_thn(e));
      arg_use_cnt (IfExpr_els(e));
      for (l = IfExpr_thens(e); l; l = List_Expr_next(l)) {
	arg_use_cnt (List_Expr_data(l));
      }
      break;
    case IdentExpr_kind:
      pattern_use (IdentExpr_pattern(e), e);
      def_use (IdentExpr_def(e), e);
    default:
      break;
  }
}

static Bool is_simple_type (Type t)
{
  Typedef d;
  Ident id;
  
  t = norm_type(t);
  
  switch (Type_tag(t)) {
    case IdentType_kind:
      d = IdentType_type(t);
      id = IdentType_type_id(t);
      if (d==NULL) return TRUE;
      if (id == ident_id) return TRUE;
      if (id == string_id) return TRUE;
      return !allows_null(t);
    default:
      break;
  }
  return TRUE;
}

static void definition_use_cnt (Definition d)
{
  Type t = Definition_type(d);
  
  if (is_simple_type(t)) return;
  
  arg_use_cnt (Definition_expr(d));
}

static void rhs_use_cnt (Guard d)
{
  List_Expr l;
  ExprSeq s = ExprGuard_exprs(d);
  
  switch (ExprSeq_tag(s)) {
    case OneExpr_kind: 
      arg_use_cnt (OneExpr_expr(s));
      break;
    case MoreExprs_kind:
      for (l = MoreExprs_exprs(s); l; l = List_Expr_next(l)) {
	arg_use_cnt (List_Expr_data(l));
      }
      break;
  }
  
}

static void rule_use_cnt (Rule r)
{
  static struct s_void_doggy_TraverseTable use_cnt_actions;
  
  use_cnt_actions.action_Definition[PRE_ACTION] = definition_use_cnt;
  use_cnt_actions.action_ExprGuard[PRE_ACTION] = rhs_use_cnt;
    
  Traverse_void_Rule (r, &use_cnt_actions);
}

static void compute_use_cnt (void)
{
  static struct s_void_doggy_TraverseTable use_cnt_actions;
  
  use_cnt_actions.action_Rule[PRE_ACTION] = rule_use_cnt;
  
  ident_id = Make_identifier("Ident");
  string_id = Make_identifier("String");
  
  Traverse_void_doggy (doggy_root, &use_cnt_actions);
}

/* Generate all code */
void
Gen_code (Bool search, Bool gen_test, char *id)
{
  List_Func p;
  List_Rule l;
  List_Section s;
  
  List_Type types;

  opt_rule_id=id;
  
  search_ops = search;
  
  compute_use_cnt ();
    
  if (search_ops) {
    gen_init ();
  }
  
  if (gen_test) {
    for (types = node_types (); types; types = List_Type_next(types)) {
      gen_switch (List_Type_data(types), "test_ops", gen_op_test, TRUE, TRUE);
    }
  }
  gen_funcs ();
      
  for (p = doggy_functions(doggy_root); p; p = List_Func_next(p)) {
    gen_func_header (List_Func_data(p), TRUE);
  }
    
  for (p = doggy_functions(doggy_root); p; p = List_Func_next(p)) {
    gen_func (List_Func_data(p));
  }
    
  for (l = doggy_rules(doggy_root); l; l = List_Rule_next(l)) {
    gen_rule (List_Rule_data(l));
  }
  
  for (s = doggy_sections(doggy_root); s; s = List_Section_next(s)) {
    Section s1 = List_Section_data(s);
    if (Section_tag(s1) != RuleSection_kind) continue;
    if (RuleSection_rules(s1) == NULL) continue;
    for (types = node_types (); types; types = List_Type_next(types)) {
      char *name = opt_name;
      if (RuleSection_rules_id(s1) != NULL)  name = IDENT_STRING(RuleSection_rules_id(s1));
      Cur_section = s1;
      gen_switch (List_Type_data(types), name, gen_tests, TRUE, FALSE);
    }
  }
}
