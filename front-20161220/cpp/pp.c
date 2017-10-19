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
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <front/mem.h>
#include <front/text.h>
#include <front/filename.h>
#include <front/support.h>
#include "token.h"
#include "file.h"
#include "sequence.h"
#include "define.h"
#include "emit.h"
#include "pp.h"
#include "errors.h"

int deep_location = 0;
int visual_studio_compatible = 0;
int cpp_inhibit_expansion = 0;
int cpp_inhibit_linemarkers = 0;
int cpp_gnu = 0;

static void pp_if (sequence sq);

/*-----------------------------------------------------------------------------
 * expand sequence, regardless of cpp_inhibit_expansion
 */
static void
pp_expand_sequence (sequence sq) {
  int old_cpp_inhibit_expansion = cpp_inhibit_expansion;
  cpp_inhibit_expansion = 0;
  {
    pp_sequence (sq);
  }
  cpp_inhibit_expansion = old_cpp_inhibit_expansion;
}

/* ----------------------------------------------------------------------------
 * Read tokens from IN
 */
tokens
read_file(File file, int sysfile)
{
  return remove_escapes (scan_file (file->name, sysfile));
}


/* ----------------------------------------------------------------------------
 * TRUE iff T is interpreted as end of line
 */
static int
is_eol_token (token t)
{
  return ( t->tag==newline_kind ||
           t->tag==eof_kind ||
           t->tag==sof_kind );
}

/* ----------------------------------------------------------------------------
 * Duplicate the next tokens until the next new line
 */
static tokens
dup2nl(sequence sq)
{
  tokens dupe = NULL;
  token next ,t;

/*   t = this_token(sq); */
/*   if (is_eol_token (t)) return single (nil_token ()); */

  do {
    next = peek_token (sq);
    if (!next || is_eol_token (next)) break;
    t = next_token (sq);
    dupe = append_token (dupe, t);
  } while(1);
  if (!dupe) return single (nil_token ());
  return dupe;
}

#ifdef AMBER
/* ----------------------------------------------------------------------------
 * Skip the next tokens until the next new line
 */
static void
skip2nl(sequence sq)
{
  token next ,t;

  do {
    next = peek_token (sq);
    if (!next ||
        next->tag == newline_kind ||
        next->tag == eof_kind ||
        next->tag == sof_kind) break;
    t = next_token (sq);
  } while(1);
}
#endif

/* ----------------------------------------------------------------------------
 * Read a newline, if it's not skip passed the next newline and give an error
 */
static int
skip_nl(sequence sq)
{
  token t;
  int i = 0;
  
  do {
    t = next_token (sq);
    i++;
  } while(t && t->tag!=newline_kind && t->tag!=eof_kind && t->tag!=sof_kind);
  return i==1;
}

/* ----------------------------------------------------------------------------
 * read the file specified in token T
 */
static void
include_file(sequence sq)
{
  int flags = 0;
  File file;
  sequence loc;
  tokens line = NULL;
  tokens ts;
  token p, t;

  p = this_token (sq);
  loc = tmp_sequence (dup2nl (sq), 0);
  pp_expand_sequence (loc);

  line = rescan_as_include (loc->start);
  
  t = line->head;
  if (!t || (t->tag != header_name_kind && t->tag != sys_header_name_kind)) {
    cpp_badly_formed_include (p);
    return;
  }
  if (line->tail) {
    cpp_garbage_after_include (p);
  }

  if (p->tag==include_next_kind) {
    flags |= SEARCH_NEXT;
  } else if (t->tag==header_name_kind) {
    flags |= SEARCH_CURDIR;
  }

  file = new_file (fe_substr(t->text,1,-2), flags);
  if (!file) {
    cpp_could_not_include (p, t->text);
    insert_tokens (sq, NULL);
    return;
  }

  ts = read_file (file, t->tag==sys_header_name_kind);
  if (ts) {
    token sof, eof;
    sof = ts->head;
    eof = last_token(ts);
    sof->outl = p->line;
    sof->outc = p->col;
    eof->file = p->file;
    eof->line = p->line+1;
  }

  if (cpp_inhibit_expansion) {
    pp_expand_sequence (new_sequence (ts,0)); /* do preprocess ... */
    pass_all (sq); /* ... but do not emit resulting tokens */
  } else
    insert_tokens (sq, ts);
}

/* ----------------------------------------------------------------------------
 * Process a #define foo(bar,baz) command
 */
static void
define_macro(sequence sq, token id)
{
  token arg, sep;
  tokens args = NULL;
  next_token (sq); /* '(' */
  sep = arg = peek_token (sq);
  if (is_token(sep, ")")) {
    next_token (sq);
  } else {
    do {
      arg = next_token (sq);
      if (is_token(arg, "...")) {
        arg = id_token("__VA_LIST__");
        arg->variadic = 1;
      } else if (!is_ident(arg)) {
        cpp_invalid_argument (arg);
        if (!is_token (arg,"\n")) skip_nl (sq);
        return;
      }
      args = append_token (args, arg);
      sep = next_token (sq);
      if (!arg->variadic && is_token(sep, "...")) {
        arg->variadic = 1;
        sep = next_token (sq);
      }
    } while(is_token(sep,","));
    if (!is_token(sep, ")")) {
      cpp_badly_formed_define (this_token(sq));
      if (!is_token (sep,"\n")) skip_nl (sq);
      return;
    }
  }

  new_macro(id, args, dup2nl (sq));
}

/* ----------------------------------------------------------------------------
 * Process a #define command
 */
static void
pp_define (sequence sq)
{
  token name = next_token(sq);
  token paren = peek_token(sq);

  if (is_token(paren,"(") && !name->space) {
    define_macro (sq, name);
  } else {
    new_alias (name, dup2nl(sq));
  }

  if (cpp_inhibit_expansion)
    pass_all (sq);
}

/* ----------------------------------------------------------------------------
 * skip to the next #else, #elif, or #endif on the current nesting level.
 * skip to #endif only if ENDIF is non-zero
 */
static int
skip_group(sequence sq, int endif)
{
  int ppc=0; /* preprocessing command */
  token t;

  while ((t = peek_token (sq))) {
    switch (t->tag) {
    case hash_kind:
      ppc = t->sol;
      break;
    case if_kind: case ifdef_kind: case ifndef_kind:
      if(ppc) {
        if (!skip_group(sq, 1)) return 0;
      }
      break;
    case else_kind:
    case elif_kind:
      if(endif) break;
    case endif_kind:
      if (ppc) {
	if (cpp_inhibit_expansion)
	  pass_all (sq);
	return 1;
      }
      break;
    default:
      ppc = 0;
      break;
    }
    next_token (sq);
    if (cpp_inhibit_expansion)
      pass_all (sq);
  }
  cpp_unbalanced_if (sq->out->head);
  return 0;
}

/* ----------------------------------------------------------------------------
 * process an else-part or an endif
 */
static void
pp_else(sequence sq)
{
  token t = next_token (sq);
  if (cpp_inhibit_expansion)
    pass_all (sq);
  else
    insert_tokens (sq, NULL);
  switch (t->tag) {
  case else_kind:  pp_sequence (sq); break;
  case elif_kind:  pp_if (sq); break;
  case endif_kind:
    if (cpp_inhibit_expansion)
      pass_all (sq);
    else if (!skip_nl (sq)) cpp_garbage_after_directive (t);
    break;
  default: abort();
  }
}

/* ----------------------------------------------------------------------------
 * Process next section if token T is defined
 */
static void
ifdef (sequence sq)
{
  token t = next_token (sq);
  if (cpp_inhibit_expansion)
    pass_all (sq);
  else
    insert_tokens (sq, NULL);
  if (have_macro (t) || have_alias(t)) {
    pp_sequence (sq);
  } else {
    if (skip_group(sq, 0)) pp_else (sq);
  }
}

/* ----------------------------------------------------------------------------
 * Process next section if token T is not defined
 */
static void
ifndef (sequence sq)
{
  token t = next_token (sq);
  if (cpp_inhibit_expansion)
    pass_all (sq);
  else
    insert_tokens (sq, NULL);

  if (!have_macro (t) && !have_alias(t)) {
    pp_sequence (sq);
  } else {
    if (skip_group (sq, 0)) pp_else (sq);
  }
}

/* ----------------------------------------------------------------------------
 * Process next section if the expression evaluates to 1
 */
static void
pp_if (sequence sq)
{
  int v, ok;
  token c = this_token (sq);
  sequence cond = tmp_sequence (dup2nl (sq), 1);

  pp_expand_sequence (cond);

  v = evaluate (cond->start, &ok);
  if (!ok) {
    cpp_invalid_expression (c);
    v = 0;
  }

  if (cpp_inhibit_expansion)
    pass_all (sq);
  else
    insert_tokens (sq, NULL);

  if (v) {
    pp_sequence (sq);
  } else {
    if (skip_group (sq, 0)) pp_else (sq);
  }
  
}

static void
pp_defined (sequence sq)
{
  int error=0;
  token v;
  token id;

  id = next_token(sq);
  if (is_token(id, "(")) {
    id = next_token (sq);
    if (!is_token (next_token (sq), ")")) {
      cpp_badly_formed_defined (this_token(sq));
      error = 1;
    }
  }
  v = int_token (!error && (have_alias(id) || have_macro(id)));
  
  insert_tokens (sq, copy_props (single (v), id));
}

/* ----------------------------------------------------------------------------
 * Give a #error message and quit
 */
static void
pp_error (sequence sq)
{
  token t = this_token (sq);
  if (cpp_inhibit_expansion)
    pass_all (sq);
  else if (t->tag == warning_kind) cpp_hash_warning (t, text_tokens (dup2nl (sq)));
  else                        cpp_hash_error   (t, text_tokens (dup2nl (sq)));

/*     cpp_warning (t, ""); */
/*   else                        cpp_syntax (t, ""); */
/*   emit_tokens (stderr, dup2nl (sq)); */
}

/* ----------------------------------------------------------------------------
 * Set line and possibly file for next tokens
 */
static void
pp_line (sequence sq)
{
  int ok;
  int delta;
  char *file = NULL;
  token self, t;
  tokens ts;
  sequence loc;

  self = this_token(sq);
  loc = tmp_sequence (dup2nl (sq), 0);
  pp_expand_sequence (loc);

  t = next_token(loc);
  delta = self->line+1 - eval_constant (t, &ok, NULL);
  if (!ok || t->tag!=pp_number_kind) {
    cpp_badly_formed_line_number (t);
    return;
  }
  
  t = next_token(loc);
  if (t) {
    if (t->tag!=string_kind) {
      cpp_badly_formed_file_name (t);
    } else {
      file = fe_substr (t->text,1,-2);
    }
    if (peek_token(loc)) {
      if (!cpp_inhibit_expansion)
	cpp_garbage_after_line (t);
    }
  }
  if (!delta && !file) return;

  t = loc_token ();
  t->file = self->file;
  t->line = self->line+1;
  t->col = 0;

  if (cpp_inhibit_expansion) {
    pass_all (sq);
  } else {
    insert_tokens (sq, single (t));

    for (ts = sq->in; ts; ts = ts->tail) {
      token t = ts->head;
      t->line -= delta;
      if (file && t->file) t->file->name = file;
    }
  }
}

/* ----------------------------------------------------------------------------
 * Set line and file for next tokens
 */
static void
pp_line_marker(sequence sq)
{
  token t, self = this_token(sq);
  tokens ts;
  int ok;
  int delta;
  char *file = NULL;

  delta = self->line+1 - eval_constant (self, &ok, NULL);
  if (!ok) {
    cpp_badly_formed_line_number (t);
    return;
  }
  t = next_token (sq);
  if (!t || t->tag != string_kind) {
    cpp_badly_formed_file_name (t);
    return;
  }
  file = fe_substr (t->text,1,-2);
  /* skip flags */
  t = peek_token (sq);
  while (t && t->tag != newline_kind) {
    t = next_token (sq);
  }
  
  t = loc_token ();
  t->file = self->file;
  t->line = self->line+1;
  t->col = 0;

  if (cpp_inhibit_expansion) {
    insert_tokens (sq, 0);
    for (ts = sq->in; ts; ts = ts->tail) {
      token t = ts->head;
      t->line -= delta;
      if (file && t->file) t->file->name = file;
    }
  } else {
    insert_tokens (sq, single (t));
    for (ts = sq->in; ts; ts = ts->tail) {
      token t = ts->head;
      t->line -= delta;
      if (file && t->file) t->file->name = file;
    }
  }
}

/* ----------------------------------------------------------------------------
 * Process a preprocessing command.
 * Returns 1 if the current nesting level is finished, 0 otherwise
 */
static int
pp_command(sequence sq)
{
  static int nesting=0;
  token t = next_token(sq);
  
  if(!t) { pass(sq); return 0; }
  nesting++;
  switch (t->tag) {
  case include_next_kind: 
  case include_kind:
    include_file (sq);
    nesting--;
    return 0;
  case define_kind:  pp_define (sq); break;
  case undef_kind:
    remove_define (next_token (sq));
    if (cpp_inhibit_expansion)
      pass_all (sq);
    break;
  case if_kind:      pp_if (sq); break;
  case ifdef_kind:   ifdef (sq); break;
  case ifndef_kind:  ifndef (sq); break;
  case elif_kind: case else_kind:
    if (skip_group (sq, 1)) next_token (sq); /* endif */
    /* fall-through */
  case endif_kind:
    if (cpp_inhibit_expansion)
      pass_all (sq);
    else if (!skip_nl (sq)) cpp_garbage_after_directive (t);
    if (nesting!=1) return 1;
    cpp_unexpected_endif (t);
    break;
  case error_kind:   /* fall through */  
  case warning_kind: pp_error (sq); break;    
  case line_kind:    pp_line (sq); break;
  case pp_number_kind: pp_line_marker (sq); break;
  case newline_kind: 
    if (cpp_inhibit_expansion)
      pass_all (sq);
    break;
  case ident_kind:   /* fall through */  
  case pragma_kind:
    pass_all (sq);
    break;
  default:
    cpp_invalid_directive (t, t->text);
    break;
  }

  insert_tokens (sq, NULL);
  nesting--;
  return 0;
}

/* ----------------------------------------------------------------------------
 * String for __TIME__
 */
static char *
Time(void)
{
  static char *compile_time = NULL;
  struct tm *local;
  time_t now;
  time (&now);
  local = localtime(&now);
  if (!compile_time) {
    compile_time = Front_StrAllocf("\"%.2d:%.2d:%.2d\"",
                                   local->tm_hour,
                                   local->tm_min,
                                   local->tm_sec);
  }
  return compile_time;
}

/* ----------------------------------------------------------------------------
 * String for __DATE__
 */
static char *
Date(void)
{
  static char *compile_date = NULL;
  char *months[]={ "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
  struct tm *local;
  time_t now;
  time (&now);
  local = localtime(&now);

  if (!compile_date) {
    compile_date = Front_StrAllocf("\"%.3s%3d %4d\"",
                                   months[local->tm_mon],
                                   local->tm_mday,
                                   1900+local->tm_year);
  }
  return compile_date;
}

/* ----------------------------------------------------------------------------
 * String for __FILE__
 */
static token
Filename(token t)
{
  File f = t->file;
  while(f->parent) f = f->parent;
  return string_token (Front_StrAllocf("\"%s\"", f->name));
}

/* ----------------------------------------------------------------------------
 * Alias expand the identifier token T, note __LINE__ done during emit
 */
static tokens
expand_alias(sequence sq, token t)
{
  token r;
  
  if (have_alias(t)) return apply_alias (sq, t);
  else if (!strcmp ("__FILE__",t->text)) r = Filename (t);
  else if (!strcmp ("__DATE__",t->text)) r = string_token (Date());
  else if (!strcmp ("__TIME__",t->text)) r = string_token (Time());
  else {
    pass (sq);
    return NULL;
  }
  r->file = t->file;
  r->line = t->line;
  r->outl = t->outl;
  r->col  = t->col;
  r->outc = t->outc;
  return single (r);
}

/* ----------------------------------------------------------------------------
 * get the list of tokens that make up a macro argument.
 */
static tokens
next_argument(sequence sq)
{
  token t;
  tokens res = NULL;
  int nest = 0;

  for(t = peek_token(sq); t; t = peek_token(sq)) {
    if (t->tag == newline_kind) {
      next_token (sq);
      continue;
    } else if (is_token(t, ",") && nest==0) break;
    else if (is_token(t, ")")) {
      if(nest==0) break;
      nest--;
    } else if (is_token(t, "(")) {
      nest++;
    }
    res = append_token (res, next_token(sq));
  }
  if (!t) {
    cpp_unterminated_arglist (out_token (sq));
    return NULL;
  }
  this_token (sq)->space = 0;
  if (!res) return single (nil_token());
  return res;
}

/* ----------------------------------------------------------------------------
 * Get macro arguments
 */
static Bool
get_macro_args (sequence sq, tokenss *args)
{
  token sep;
  tokens arg;

  *args = NULL;
  for (sep = next_token (sq); sep->tag==newline_kind; sep = next_token (sq));
  /* sep == "(" */
  sep = peek_token (sq);
  if (is_token(sep, ")")) {
    next_token (sq);
  } else {
    do {
      arg = next_argument (sq);
      if (!arg) return FALSE;
      *args = append_tokens (*args, arg);
      sep = next_token (sq);
    } while (sep && is_token (sep, ","));
  }
  return TRUE;
}

/* ----------------------------------------------------------------------------
 * Macro expand the identifier token ID, and all its arguments
 */
static tokens
expand_macro(sequence sq, token id)
{
  int diff;
  tokens save = sq->in;
  tokens repl = NULL;
  tokenss args = NULL;

  assert (have_macro (id));

  if (!get_macro_args (sq, &args)) return NULL;
  diff = have_macro_args (id, num_tokenss (args));
  if (diff==0) {
    repl = apply_macro (sq, id, args);
  } else if (have_alias (id)){
    sq->in = save;
    repl = expand_alias (sq, id);
  } else if (diff>0) {
    cpp_too_few_arguments (id, id->text);
  } else if (diff<0) {
    cpp_too_many_arguments (id, id->text);
    if (visual_studio_compatible) {
      repl = apply_macro (sq, id, args);
    }
  }
  return repl;
}

/* ----------------------------------------------------------------------------
 * Define expansion
 */
static void
expand_define(sequence sq)
{
  token t = this_token (sq);
  token n = peek_text_token (sq);
  tokens repl;
  
  if (!n || !is_token (n, "(") || !have_macro (t)) {
    repl = expand_alias (sq, t);
  } else {
    repl = expand_macro (sq, t);
  }
  if (!repl) return;
  repl = remove_glue (repl);
#warning To do: set properties of expansion to that of the macro (Why? isnt this done now )
  if(!deep_location) override_location (repl, t);
  repl = append_ws_if (repl, this_token(sq)->space);
  if (t->sol) repl->head->sol = TRUE;
  insert_tokens (sq, repl);
}

/* ----------------------------------------------------------------------------
 * Process all tokens
 */
void
pp_sequence(sequence sq)
{
  int have_nil = 0;
  token t;
  
  while ((t = next_token (sq))) {
    switch (t->tag) {
    case hash_kind:
      if (t->sol) {
        t->space = 0;
        if (pp_command(sq)) return;
      } else {
        pass (sq);
      }
      break;
    case defined_kind:
      if (sq->eval_defined) pp_defined (sq);
      pass_all(sq);
      break;
    case nil_kind:
      if (have_nil) insert_tokens (sq, NULL);
      else pass (sq);
      break;
    case eos_kind:
      insert_tokens (sq, NULL);
      break;
    case eof_kind:
      leave_file();
      /* fall through */
    default:
      if (is_ident(t) && !cpp_inhibit_expansion) expand_define(sq);
      else             pass (sq);
    }
    have_nil = (t->tag == nil_kind);
  }
}

#ifdef AMBER
/* ----------------------------------------------------------------------------
 * Check for asm
 */
static int is_asm(token t)
{
  assert(t != NULL);
  return is_token(t, "asm") || is_token(t, "ASM");
}

/* ----------------------------------------------------------------------------
 * Check for endasm 
 */
static int is_endasm(token t)
{
  assert(t != NULL);
  return is_token(t, "endasm") || is_token(t, "ENDASM");
}

/* ----------------------------------------------------------------------------
 * Check for endasm pragma
 * note that next_token might be called; in that case the sequence is on a 
 * pragma token when it returns
 */
static int
pragma_endasm(sequence sq)
{
  token t;
  t = this_token(sq);
  if (t == NULL) return 0;
  if (t->tag != hash_kind) return 0;
  t = peek_token(sq);
  if (t == NULL) return 0;
  if (t->tag != pragma_kind) return 0;
  t = next_token(sq);
  t = peek_token(sq);
  if (t == NULL) return 0;
  return is_endasm(t);
}

/* ----------------------------------------------------------------------------
 * Skip upto and including first pragma endasm
 */
static void
skip_past_endasm(sequence sq)
{
  token t;
  t = this_token(sq);
  /* note: pragma_endasm might have side effect on current token */
  while (t && !pragma_endasm(sq)) {
    t = next_token(sq);
  }
  if (t != NULL) {
    skip2nl(sq);
  } else {
    fprintf(stderr, "Unterminated #pragma asm\n");
  }
}

/* ----------------------------------------------------------------------------
 * Process pragma in sq
 */
static void
pp_pragmas_pragma(sequence sq) /* keep pp_pragma for use in pp_command */
{
  token t, next;
  t = next_token(sq);
  if(!t) { pass(sq); return; }

  if (t->tag ==  pragma_kind) {
    next = peek_token(sq);
    if (is_asm(next)) {
      /* skip to first pragma endasm */
      skip_past_endasm(sq);
    } else {
      /* omit pragma line in output (AMBER SPECIFIC) */
      skip2nl(sq);
    }
    insert_tokens(sq, NULL);
  } else {
    /* not a pragma */
    pass_all(sq);
  } 
}

/* ----------------------------------------------------------------------------
 * Process pragmas in *ts
 */

void
pp_pragmas(tokens *ts)
{
  sequence sq;
  token t;
  assert(ts != NULL);
  if (*ts == NULL) return;

  sq = new_sequence(*ts, 0);
  while ((t = next_token (sq))) {
    if (t->tag == hash_kind) {
      pp_pragmas_pragma(sq);
    } else {
      pass(sq);
    }
  }
  *ts = sq->start;
  /* free_sequence(sq); */
}
#endif
