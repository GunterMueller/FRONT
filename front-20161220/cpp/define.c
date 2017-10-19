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

#include <assert.h>
#include <front/mem.h>
#include <front/basic_types.h>
#include "define.h"
#include "token.h"
#include "emit.h"
#include "pp.h"
#include "errors.h"

typedef struct s_scope  *scope;

struct s_scope {
  struct scope *parent;
  int obsolete;
  int end;
};

enum define_tag {
  alias_kind,
  macro_kind,
  argument_kind,
  undefine_kind
};

struct s_define {
  struct s_scope  *scope;
  enum define_tag  tag;
  identifier       id;
  tokens           args;
  tokens           repl;
  int              enabled;
  int              variadic;
};

static int define_namespaces[2];
#define alias_namespace define_namespaces[alias_kind]
#define macro_namespace define_namespaces[macro_kind]

static defines define_list;

static tokens comma_tokens (tokens ts);

/* ----------------------------------------------------------------------------
 * Initialize the symbol table for the #defines
 */
void
init_define(void)
{
  Extend_namespaces(2, define_namespaces);
}

void
clear_define(void)
{
  Clean_namespaces(alias_namespace, 2, 0);
}

/* ----------------------------------------------------------------------------
 * Create a new scope
 */
static scope
new_scope(void)
{
  scope me = FE_NEW(scope);
  me->parent = NULL;
  me->obsolete = 0;
  me->end = 0;
  return me;
}


/* ----------------------------------------------------------------------------
 * Retrieve the define ID
 */
static define
retrieve (token id, enum define_tag tag)
{
  Bind bind = Retrieve_Bind(Make_identifier(id->text), NULL,
                            define_namespaces[tag], tag);
  if (bind) return Bind_object(bind);
  return NULL;
}

/* ----------------------------------------------------------------------------
 * TRUE iff a previous definition is the same as A
 */
static Bool
define_exists(define a)
{
  Bind bind = Retrieve_Bind(a->id, NULL, define_namespaces[a->tag], a->tag);
  define b;

  if (!bind) return FALSE;
  b = Bind_object(bind);
  return same_tokens (a->args, b->args) && same_tokens (a->repl, b->repl);
}

/* ----------------------------------------------------------------------------
 * Create and initialize a new define, also adds it to the symbol table
 */
static void
new_define(enum define_tag tag, token id, tokens args, tokens repl)
{
  int i=0;
  tokens ts;
  token arg = NULL;
  define me = FE_NEW(define);

  me->scope = new_scope();
  me->tag = tag;
  me->id = Make_identifier(id->text);
  me->args = args;
  me->repl = repl;
  me->enabled = 1;
  me->variadic = 0;
  if (define_exists (me)) return;
  if (have_macro (id) || have_alias (id)) {
    cpp_redefinition (id, id->text);
    remove_macro (id);
  }
  Store_Bind (me->id, NULL, me->tag, me, define_namespaces[tag], 0, 0);
  for (ts = args; ts; ts = ts->tail) {
    arg = ts->head;
    Store_Bind (Make_identifier (arg->text), me->scope, argument_kind, arg,
                alias_namespace, 0, 0);
    arg->index = i++;
  }
  if (arg && arg->variadic) me->variadic = 1;
  if (!me->repl) me->repl = single(nil_token());

  define_list = add_define (me, define_list);
}

/* ----------------------------------------------------------------------------
 * Return all defines
 */
defines
all_defines()
{
  return define_list;
}

/* ----------------------------------------------------------------------------
 * Return text version of define DEF
 */
char *
text_define (define def)
{
  char *text_def   = "#define";
  char *text_undef = "#undef";
  char *text_id    = def->id->name;
  char *t_args     = def->args ? text_tokens (comma_tokens (def->args)) : "";
  char *t_repl     = def->repl ? text_tokens (def->repl) : "";
  char *text_args  = t_args ? t_args : "";
  char *text_repl  = t_repl ? t_repl : "";
  char *text;

  if (def->tag == macro_kind) {
    int len = strlen(text_def) + 1 + strlen(text_id) + 2 + strlen(text_args) + 1 + strlen(text_repl) + 1;
    text = fe_malloc (len);

    sprintf (text, "#define %s(%s) %s", text_id, text_args, text_repl);

  } else if (def->tag == alias_kind) {
    int len = strlen(text_def) + 1 + strlen(text_id) + 1 + strlen(text_repl) + 1;
    text = fe_malloc (len);

    sprintf (text, "#define %s %s", text_id, text_repl);

  } else if (def->tag == undefine_kind) {
    int len = strlen(text_undef) + 1 + strlen(text_id);
    text = fe_malloc (len);

    sprintf (text, "#undef %s", text_id);
  }

  return text;
}

/* ----------------------------------------------------------------------------
 * Create a new alias "#define foo bar"
 */
void
new_alias (token id, tokens repl)
{
  new_define(alias_kind, id, NULL, repl);
}

/* ----------------------------------------------------------------------------
 * Create a new macro "#define f(a,b) foo a bar b"
 */
void
new_macro (token id, tokens args, tokens repl)
{
  new_define(macro_kind, id, args, repl);
}

/* ----------------------------------------------------------------------------
 * Retrieve the define ID
 */
static token
retrieve_arg (token id, define macro)
{
  Bind bind;

  bind = Retrieve_Bind (Make_identifier(id->text), macro->scope,
                        alias_namespace, argument_kind);
  if (bind) return Bind_object(bind);
  return NULL;
}

/* ----------------------------------------------------------------------------
 * Remove the #define ID foo bar
 */
void
remove_alias(token id)
{
  Bind bind;

  bind = Retrieve_Bind(Make_identifier(id->text), NULL,
                       alias_namespace, alias_kind);
  if (bind) Remove_Bind(bind, alias_namespace);
}

/* ----------------------------------------------------------------------------
 * Remove the #define ID(foo) bar
 */
void
remove_macro(token id)
{
  Bind bind;

  bind = Retrieve_Bind(Make_identifier(id->text), NULL,
                       macro_namespace, macro_kind);
  if (bind) Remove_Bind(bind, macro_namespace);
}

/* ----------------------------------------------------------------------------
 * Remove the alias and macro ID
 */
void
remove_define(token id)
{
  define me = FE_NEW(define);
  me->tag = undefine_kind;
  me->id = Make_identifier(id->text);
  me->args = 0;
  me->repl = 0;
  define_list = add_define (me, define_list);

  remove_alias (id);
  remove_macro (id);
}

/* ----------------------------------------------------------------------------
 * Disable DEF upto the next token in the sequence SQ
 */
static void
disable_def(sequence sq, define def)
{
  token n = peek_token (sq);

  if (!n) return;
  def->enabled = 0;
  n->defs = new_defines (def, n->defs);
}

/* ----------------------------------------------------------------------------
 * Expand the alias ID
 */
tokens
apply_alias(sequence sq, token id)
{
  define def = retrieve (id, alias_kind);
  
  assert (def);
  disable_def (sq, def);
  return copy_props (dup_tokens(def->repl), id);
}

/* ----------------------------------------------------------------------------
 * Get text representation of the alias named ID.
 */
char *get_alias (const char *id)
{
  token t = id_token (id);
  define def = retrieve (t, alias_kind);
  sequence sq;

  if (!def) return NULL;
  sq = new_sequence (def->repl, 0);
  pp_sequence (sq);
  return text_tokens (sq->start);
}

/* ----------------------------------------------------------------------------
 * Get the value of the argument ID of MACRO
 */
static int
get_argument(token id, define macro)
{
  token tok = retrieve_arg (id, macro);
  
  if (!tok) return -1;
  return tok->index;
/*   return append_ws_if (dup_tokens(tok->repl), id->space); */
}


/* ----------------------------------------------------------------------------
 * Create a comma separated tokens sequence from TSS
 */
static tokens
comma_tokenss (tokenss tss)
{
  if (!tss) return NULL;
  if (!tss->tail) return tss->head;
  return cat_tokens (tss->head,
                     new_tokens (punctuator_token (","),
                                 comma_tokenss (tss->tail)));
}

static tokens
singleton (token t)
{
  tokens ts = FE_NEW(tokens);
  ts->head = t;
  ts->tail = NULL;
  return ts;
}

static tokens
comma_tokens (tokens ts)
{
  if (!ts) return NULL;
  if (!ts->tail) return singleton (ts->head);
  return cat_tokens (singleton (ts->head),
                     new_tokens (punctuator_token (","),
                                 comma_tokens (ts->tail)));
}

/* ----------------------------------------------------------------------------
 * Apply macro ID with arguments ARGS
 */
tokens
apply_macro(sequence sq, token id, tokenss args)
{
  int stringize=0, glue=0;
  tokens ts, res = NULL;
  define def = retrieve (id, macro_kind);
  tokens *pars;
  
  assert (def);
  pars = alloca(num_tokens(def->args)*sizeof(tokens));
  
  /* set the argument replacements */
  if (!args && def->args && !def->args->tail) {
    /* single empty argument */
    args = new_tokenss(NULL, NULL);
  }
  for (ts = def->args; ts; ts=ts->tail) {
    token arg = ts->head;
    if (arg->variadic) {
      pars[arg->index] = comma_tokenss(args);
      args = NULL;
    } else {
      assert (args);
      pars[arg->index] = args->head;
      args = args->tail;
    }
  }
  /* make the macro replacement */
  for (ts = def->repl; ts; ts = ts->tail) {
    token t = ts->head;
    if (t->tag == hash_kind) {
      stringize = 1;
    } else if (t->tag == glue_kind) {
      glue = 1;
      res = append_token(res, dup_token(t));
    } else {
      int index = get_argument(t, def);
      if (index<0) {
        res = append_token(res, dup_token(t));
      } else if(stringize) {
        res = cat_tokens(res, single (string_tokens(pars[index])));
      } else {
        tokens arg = append_ws_if (dup_tokens(pars[index]), t->space);
        token n = second_token(ts);
        if (!glue && (!n || n->tag!=glue_kind)) {
          sequence s = tmp_sequence (arg, 0);
          pp_sequence(s);
          arg = s->start;
        }
        res = cat_tokens(res, arg);
      }
      glue = 0;
      stringize = 0;
    }
  }
  disable_def (sq, def);
  return copy_props(res, id);
}

/* ----------------------------------------------------------------------------
 * non-zero if ID is a macro
 */
int
have_macro(token id)
{
  define def = retrieve (id, macro_kind);
  return def && def->enabled;
}

/* ----------------------------------------------------------------------------
 * non-zero if ID is a macro with ARGS arguments
 */
int
have_macro_args(token id, int args)
{
  define def = retrieve (id, macro_kind);
  int d;
  if (!def || !def->enabled) return FALSE;
  d = num_tokens(def->args)-args;
  if (!def->variadic) return d;
  d--; /* don't count the ... argument */
  if (d<=0) return 0;
  return d;
}

/* ----------------------------------------------------------------------------
 * non-zero if ID is an alias
 */
int
have_alias(token id)
{
  define def = retrieve (id, alias_kind);
  return def && def->enabled;
}

/* ----------------------------------------------------------------------------
 * Create and initialize a define list
 */
defines
new_defines(define head, defines tail)
{
  defines me = FE_NEW(defines);
  me->head = head;
  me->tail = tail;
  return me;
}

/* ----------------------------------------------------------------------------
 * Add a define to the end of a define list
 */
defines
add_define(define def, defines list)
{
  defines l;
  defines me = FE_NEW(defines);
  for (l = list; l && l->tail; l = l->tail);
  if (l) l->tail = me; else list = me;
  me->head = def;
  me->tail = NULL;
  return list;
}

/* ----------------------------------------------------------------------------
 * Enable all DEFS
 */
void
enable_defs (defines defs)
{
  for(; defs; defs = defs->tail) {
    defs->head->enabled = 1;
  }
}
