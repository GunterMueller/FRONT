/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

%{
#include <stdlib.h>
#include "token.h"
#include "define.h"

  static tokens token_string = NULL;
  static int result, ok;

  static void expression_error(char *s);
  static int expression_lex(void);

%}

%union {
  token tok;
  struct {
    int ok, val, is_unsigned;
  }     v;
}

%type<v>   expression logical_or_expr logical_and_expr inclusive_or_expr
%type<v>   exclusive_or_expr and_expr equality_expr relational_expr shift_expr
%type<v>   additive_expr multiplicative_expr unary_expr
%type<tok> constant
%type<tok> ident

%token ident
%token constant
%token logical_or
%token logical_and
%token equality
%token inequality
%token atmost
%token atleast
%token shift_right
%token shift_left

%%

expression:
logical_or_expr
{ result = $1.val; ok = $1.ok; }
|
logical_or_expr '?' expression ':' expression
{
  if ($1.ok && $1.val) {
    result = $3.val; ok = $3.ok;
  } else {
    result = $5.val; ok = $5.ok;
  }
}
;

logical_or_expr:
logical_and_expr
|
logical_or_expr logical_or logical_and_expr
{
  $$ = $1;
  if ($1.ok) {
    if ($1.val) $$.val = 1;
    else if ($3.ok && $3.val) $$.val = 1;
    else $$.ok = $3.ok;
  } 
}
;

logical_and_expr:
inclusive_or_expr
|
logical_and_expr logical_and inclusive_or_expr
{
  $$ = $1;
  if ($1.ok) {
    if (!$1.val) $$.val = 0;
    else if ($3.ok && !$3.val) $$.val = 0;
    else {
      $$.ok = $3.ok;
      $$.val = 1;
    }
  }
}
;

inclusive_or_expr:
exclusive_or_expr
|
inclusive_or_expr '|' exclusive_or_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  if ($$.ok) $$.val |= $3.val;
}
;

exclusive_or_expr:
and_expr
|
exclusive_or_expr '^' and_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  if ($$.ok) $$.val ^= $3.val;
}
;

and_expr:
equality_expr
|
and_expr '&' equality_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  if ($$.ok) $$.val &= $3.val;
}
;

equality_expr:
relational_expr
|
equality_expr equality relational_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  if ($$.ok) $$.val = ($$.val == $3.val);
}
|
equality_expr inequality relational_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  if ($$.ok) $$.val = ($$.val != $3.val);
}
;

relational_expr:
shift_expr
|
relational_expr '<' shift_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  $$.is_unsigned = $1.is_unsigned || $3.is_unsigned;
  if ($$.ok) {
    if ($$.is_unsigned) $$.val = ((unsigned) $$.val < (unsigned)$3.val);
    else                $$.val = ($$.val < $3.val);
  }
}
|
relational_expr '>' shift_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  $$.is_unsigned = $1.is_unsigned || $3.is_unsigned;
  if ($$.ok) {
    if ($$.is_unsigned) $$.val = ((unsigned) $$.val > (unsigned)$3.val);
    else                $$.val = ($$.val > $3.val);
  }
}
|
relational_expr atmost shift_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  $$.is_unsigned = $1.is_unsigned || $3.is_unsigned;
  if ($$.ok) {
    if ($$.is_unsigned) $$.val = ((unsigned) $$.val <= (unsigned)$3.val);
    else                $$.val = ($$.val <= $3.val);
  }
}
|
relational_expr atleast shift_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  $$.is_unsigned = $1.is_unsigned || $3.is_unsigned;
  if ($$.ok) {
    if ($$.is_unsigned) $$.val = ((unsigned) $$.val >= (unsigned)$3.val);
    else                $$.val = ($$.val >= $3.val);
  }
}
;

shift_expr:
additive_expr
|
shift_expr shift_left additive_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  if ($$.ok) {
    if ($$.is_unsigned) $$.val = ((unsigned)$$.val << $3.val);
    else                $$.val = ($$.val << $3.val);
  }
}
|
shift_expr shift_right additive_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  if ($$.ok) $$.val = ($$.val >> $3.val);
  if ($$.ok) {
    if ($$.is_unsigned) $$.val = ((unsigned)$$.val >> $3.val);
    else                $$.val = ($$.val >> $3.val);
  }
}
;

additive_expr:
multiplicative_expr
|
additive_expr '+' multiplicative_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  if ($$.ok) $$.val = ($$.val + $3.val);
}
|
additive_expr '-' multiplicative_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  if ($$.ok) $$.val = ($$.val - $3.val);
}
;

multiplicative_expr:
unary_expr
|
multiplicative_expr '*' unary_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok;
  $$.is_unsigned = $1.is_unsigned && $3.is_unsigned;
  if ($$.ok) {
    if ($$.is_unsigned) $$.val = ((unsigned)$$.val * $3.val);
    else                $$.val = ($$.val * $3.val);
  }
}
|
multiplicative_expr '/' unary_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok && ($3.val!=0);
  $$.is_unsigned = $1.is_unsigned && $3.is_unsigned;
  if ($$.ok) {
    if ($$.is_unsigned) $$.val = ((unsigned)$$.val / $3.val);
    else                $$.val = ($$.val / $3.val);
  }
}
|
multiplicative_expr '%' unary_expr
{
  $$ = $1;
  $$.ok = $$.ok && $3.ok && ($3.val!=0);
  if ($$.ok) {
    if ($$.is_unsigned) $$.val = ((unsigned)$$.val % $3.val);
    else                $$.val = ($$.val % $3.val);
  }
}
;

unary_expr:
'(' expression ')'
{ $$ = $2; }
|
'+' unary_expr
{ $$ = $2; }
|
'-' unary_expr
{
  $$.ok = $2.ok;
  $$.val = -$2.val;
}
|
'~' unary_expr
{
  $$.ok = $2.ok;
  $$.val = ~$2.val;
}
|
'!' unary_expr
{
  $$.ok = $2.ok;
  $$.val = !$2.val;
}
|
constant
{
  $$.val = eval_constant($1, &$$.ok, &$$.is_unsigned);
}
|
ident
{ $$.val = 0; $$.ok = 1; }
;

%%

static void
expression_error(char *s)
{ s=s; }

static int
expression_lex(void)
{
  token t;
  if (!token_string) return 0;
  t = token_string->head;
  token_string = token_string->tail;
  switch (t->tag) {
  case operator_kind:
  case punctuator_kind:
    if (!t->text[1]) return t->text[0];
    if (!strcmp(t->text,"||")) return logical_or;
    if (!strcmp(t->text,"&&")) return logical_and;
    if (!strcmp(t->text,"==")) return equality;
    if (!strcmp(t->text,"!=")) return inequality;
    if (!strcmp(t->text,"<=")) return atmost;
    if (!strcmp(t->text,">=")) return atleast;
    if (!strcmp(t->text,"<<")) return shift_left;
    if (!strcmp(t->text,">>")) return shift_right;
    break;
  case pp_number_kind:
  case char_const_kind:
    yylval.tok = t;
    return constant;
  default:
    if (is_ident(t)) {
      yylval.tok = t;
      return ident;
    }
    break;
  }
  return -1;
}

int
evaluate(tokens ts, int *is_ok)
{
  token_string = ts;
  *is_ok = !expression_parse();
  *is_ok |= ok;
  return result;
}
