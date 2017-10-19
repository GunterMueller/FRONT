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
#include <stdio.h>
#include <string.h>
#include <front/mem.h>
#include <front/text.h>
#include <front/support.h>
#include "file.h"
#include "token.h"
#include "emit.h"
#include "errors.h"

static int at_sol = 1;
static int current_line = -1;
static int max_lines = -1;
static int ignore_newlines = 1;

/* ----------------------------------------------------------------------------
 * Merge the tokens A and B
 */
static int
merge_tokens (token a, token b)
{
  if (a->tag <= special_token) a->text = b->text;
  else if (b->tag > special_token) {
    a->text = fe_strappend(a->text, b->text);
  }
  a->tag = merged_kind;
  a->space = b->space;
  return 1;
}

static void
unescape_text(token t)
{
  char *p;
  char *q;

  assert(t != NULL);
  p = t->text;
  q = t->text;
  while (*p) {
    if (strncmp(p,"\\\n",2)!=0) {
      *q++ = *p++;
    } else {
      p+=2;
    }
  }
  *q = 0;
}

/* ----------------------------------------------------------------------------
 * Remove escaped newlines from the token sequence TS
 */
#if 0
static tokens
_remove_escapes(tokens ts)
{
  tokens tail;
  token t, n, nn = NULL;
  
  if (!ts) return NULL;
  tail = ts->tail;
  if (!tail) return ts;
  t = ts->head;
  n = tail->head;
  switch (t->tag) {
  case escape_kind:
    if (n->tag == newline_kind) return _remove_escapes (tail->tail);
    break;
  case string_kind: case char_const_kind:
    unescape_text(t);
  default:
    break;
  }
  tail = tail->tail;
  if (tail) nn = tail->head;
  tail = _remove_escapes (ts->tail);
  if (n->tag == escape_kind && nn && nn->tag == newline_kind) {
    /* N and NN have been removed, try to merge tokens */
    if (!t->space &&  /* space after T */
        !nn->space && /* space after newline */
        merge_tokens(t, tail->head)) tail = tail->tail;
  }
  ts->tail = tail;
  return ts;
}
#endif
static tokens
_remove_escapes(tokens prev)
{
  tokens first = prev;
  tokens ts, escape = NULL, bkslsh = NULL; /* 'escape' is the token preceding 'bkslsh' - so much for terminology */
  token t;
  tokens last_nl;
  int space;

  if (!prev) return NULL;

  t = prev->head;
  switch (t->tag) {
  case escape_kind: escape = prev; break;
  case string_kind:
  case char_const_kind: unescape_text(t);
  default:
    break;
  }
  
  for (ts = prev->tail; ts; prev = ts, ts = ts->tail) {
    token t = ts->head;
    switch (t->tag) {
    case escape_kind:
      escape = prev;
      bkslsh = ts;
      continue;
    case newline_kind:
      if (escape) {
        if (bkslsh->head->space) cpp_space_after_backslash (bkslsh->head); /* In line continuation, newline must follow backslash immediately. */
        space = escape->head->space; /* space after token preceding \ ? */
        last_nl = ts;
        while (ts) {
          t = ts->head;
	  if (t->tag == newline_kind) {
	    space = space || t->space; /* space after newline ? */
	    last_nl = ts;
	    ts = ts->tail;
            if (ts != NULL) {
	      t = ts->head;
	      if (t->tag == escape_kind) { 
		if (t->space) break; /* space after \ */
		ts = ts->tail;
		continue;
              }
	    }
          }
          break;
        }
        escape->tail = last_nl->tail;
        ts = escape;
        if (!space &&       /* no space after first token and no space before second token */
            merge_tokens(ts->head, ts->tail->head)) {
          ts->tail = ts->tail->tail;
        }
        else escape->head->space = space;
        if (first==escape) first = ts->tail;
      }
      break;
    case string_kind:
    case char_const_kind:
      unescape_text(t);
    default:
      break;
    }
    escape = NULL;
    bkslsh = NULL;
  }
  return first;
}

/* ----------------------------------------------------------------------------
 * Rescan T
 */
static tokens
rescan_token (token t)
{
  tokens r;
  char *text = fe_strdup(t->text);
  if (t->space) text = fe_charappend(text,' ');
  r = rescan_string(text, t->file, t->line, t->col, t->sol, t->sysfile);
  return copy_props (r, t);
}

/* ----------------------------------------------------------------------------
 * Rescan the tokens TS expecting a header_name
 */
tokens
rescan_as_include (tokens ts)
{
  token h = ts->head;
  char *text = text_tokens(ts);
  return scan_include(text, h->file->name, h->line, h->col, h->sol, h->sysfile);
}

/* ----------------------------------------------------------------------------
 * tokenize the merged tokens
 */
#if 0
static tokens
rescan_merges (tokens ts)
{
  token t;
  
  if (!ts) return NULL;
  t = ts->head;
  ts->tail = rescan_merges(ts->tail);
  if (t->tag != merged_kind) return ts;
  return cat_tokens(rescan_token(t), ts->tail);
}
#endif

static tokens
rescan_merges (tokens ts)
{
  tokens prev = NULL, start = ts;
  token t;
  
  while (ts) {
    t = ts->head;
    if (t->tag == merged_kind) {
      ts = cat_tokens (rescan_token(t), ts->tail);
      if (prev) prev->tail = ts;
      else      start = ts;
    }
    prev = ts;
    ts = ts->tail;
  }
  return start;
}

/* ----------------------------------------------------------------------------
 * Remove escape-newlines from the token sequence TS
 */
tokens
remove_escapes(tokens ts)
{
  tokens res = ts;
  res = _remove_escapes(res);
  res = rescan_merges (res);
  return res;
}

/* ----------------------------------------------------------------------------
 * Remove the glue (##) operator
 */
tokens
remove_glue(tokens ts)
{
  tokens as=NULL, bs=NULL, cs=ts;

  for (cs = ts; cs; as = bs, bs = cs, cs = cs->tail) {
    if (as && bs->head->tag==glue_kind) {
      as->head->space = 0;
      merge_tokens (as->head, cs->head);      
      as->tail = cs->tail;
      cs = as;
      as = bs = NULL;
    }
  }
  return rescan_merges(ts);
}

/* ----------------------------------------------------------------------------
 * Allocate and initialize a new token
 */
token
new_token(enum token_tag tag, const char *text)
{
  token me = FE_NEW(token);
  me->tag = tag;
  me->text = fe_strdup(text);
  me->file = current_file();
  me->line = -1;
  me->col = 0;
  me->index = -1;
  me->outl = -1;
  me->outc = -1;
  me->sol = 0;
  me->space = 0;
  me->defs = NULL;
  me->sysfile = 0;
  me->variadic = 0;
  me->pos = -1;
  return me;
}

void
free_tokens(tokens s)
{
  while (s) {
    tokens n = s->tail;
    free_token (s->head);
    fe_free (s);
    s = n;
  }
}

void
free_token(token t)
{
  char *text = t->text;
  if (text) fe_free (text);
  fe_free (t);
}

void *CPP_dummy_token(char *fname)
{
  token t = new_token (0, "dummy");
  t->file = pseudo_file (fname);
  return t;
}

char *
token_file (void *t)
{
  return ((token) t)->file->name ? (char *)((token) t)->file->name : "stdin";
}

char *
token_line (void *t)
{
  char line[50];

  sprintf(line,"%d",((token) t)->line);
  return fe_strdup (line);
}

char *
token_col (void *t)
{
  char col[50];

  sprintf(col,"%d",((token) t)->col);
  return fe_strdup (col);
}

int
token_loc (void *t)
{
  return ((token) t)->loc;
}

token
dup_token(token t)
{
  token me = FE_NEW(token);
  *me = *t;
  me->text = fe_strdup(me->text);
  return me;
}

token
int_token(int v)
{
  return number_token (Front_StrAllocf("%d",v));
}

int
same_token(token a, token b)
{
  return a->tag == b->tag && strcmp (a->text,b->text)==0;
}

/* ----------------------------------------------------------------------------
 * Evaluate a constant token
 */
int
eval_constant(token t, int *ok, int *is_unsigned)
{
  char *end;
  int v;
  if(is_unsigned) *is_unsigned = 0;
  if (!t) {
    *ok = 0;
  } else if (t->tag == pp_number_kind) {
    int l = strlen(t->text)-1;

    if (t->text[l]=='l' || t->text[l]=='L') l--;
    if (t->text[0]=='0' || t->text[l]=='u' || t->text[l]=='U') {
      v = strtoul(t->text, &end, 0);
      if(is_unsigned && t->text[0]!='0') *is_unsigned = 1;
      *ok = (*end==0 || *end=='u' || *end=='U' || *end=='l' || *end=='L');
    } else {
      v = strtol(t->text, &end, 0);
      *ok = (*end==0 || *end=='l' || *end=='L');
    }
    
  } else if(t->tag == char_const_kind) {
    if (strlen(t->text)!=3 ||
        t->text[0]!='\'' ||
        t->text[2]!='\'' ||
        t->text[0]!=0) {
      *ok = 0;
    } else {
      *ok = 1;
      v = t->text[1];
    }
  } else {
    *ok = 0;
  }
  return v;
}

static int
isprint (char c)
{
  return c >= ' ' && c != 127;
}

/* ----------------------------------------------------------------------------
 * print text, non graphical chars are printed in the octal representation
 */
static void
text(char *t)
{
  if(!t) return;
  while(*t) {
    if (*t == '\\')      printf("\\\\");
    else if (*t == '\n') printf("\\n");
    else if(isprint(*t)) printf("%c",*t);
    else                 printf("\\%03o",*t);
    t++;
  }
}

/* ----------------------------------------------------------------------------
 * Print token for debugging
 */
void
print_token(token t)
{
  char *br[]={"{}","<>"};

  if (t->tag == newline_kind && ignore_newlines) return;
  if (t->sol) printf("^");
  printf("%d", t->line);
  if (t->outl>0 && t->outl!=t->line) printf("(%d)", t->outl);
  printf("+");
  printf("%d",t->col);
  if (t->outc>0 && t->outc!=t->col) printf("(%d)", t->outc);
  printf(":%c",br[t->sysfile][0]);
  text(t->text);
  if (t->tag == sof_kind || t->tag == eof_kind) printf(":%s",t->file->name);
  printf("%c ",br[t->sysfile][1]); 
  if (t->space) printf("_ ");
}

/* ----------------------------------------------------------------------------
 * Allocate and initialize a new token list
 */
tokens
new_tokens(token head, tokens tail)
{
  tokens me = FE_NEW(tokens);
  me->head = head;
  me->tail = tail;
  return me;
}

int
num_tokens(tokens ts)
{
  int i = 0;
  
  while (ts) {
    i++;
    ts = ts->tail;
  }
  return i;
}

token
last_token(tokens ts)
{
  if (!ts) return NULL;
  while (ts->tail) ts = ts->tail;
  return ts->head;
}

tokens
append_token(tokens begin, token end)
{
  if (!begin) return new_tokens(end, NULL);
  begin->tail = append_token(begin->tail, end);
  return begin;
}

tokens
append_ws_if(tokens toks, int c)
{
  token last = last_token(toks);

  if(last) last->space = c;
  return toks;
}

tokens
dup_tokens(tokens ts)
{
  if (!ts) return NULL;
  return new_tokens (dup_token(ts->head),
                     dup_tokens(ts->tail));
}

tokens
cat_tokens(tokens a, tokens b)
{
  if (!a) return b;
  if (!b) return a;
  a->tail = cat_tokens(a->tail, b);
  return a;
}

token
second_token (tokens ts)
{
  if (!ts || !ts->tail) return NULL;
  return ts->tail->head;
}

int
same_tokens (tokens as, tokens bs)
{
  while (as && bs) {
    if (!same_token (as->head, bs->head)) {
      return FALSE;
    }
    as = as->tail;
    bs = bs->tail;
  }
  return as==bs;
}


/* ----------------------------------------------------------------------------
 * Copy properties from the token FROM to the tokens in TO
 * props: outl, sysfile, outc (first element only)
 */
tokens
copy_props(tokens to, token from)
{
  int outl;
  tokens ts;
  token last = NULL;
  
  assert (from);
  outl = from->outl;
  if (outl<0) outl = from->line;
  for (ts = to; ts; ts = ts->tail) {
    last = ts->head;
    last->outl = outl;
    last->sysfile = from->sysfile;
  }
  if (to) to->head->outc = from->col;
  return to;
}

/* ----------------------------------------------------------------------------
 * Override the location of all tokens in TO to the location in FROM
 */
void
override_location(tokens to, token from)
{
  tokens ts;
  
  for (ts = to; ts; ts = ts->tail) {
    token t = ts->head;
    t->file = from->file;
    t->line = from->line;
    t->col = from->col;
    t->sysfile = from->sysfile;
  }
}

/* ----------------------------------------------------------------------------
 * Transform S into a proper C string
 */
static char *
quote_string (const char *s)
{
  const char *t;
  char *e;
  char *r = fe_strdup("\"");
  int l=0;
  int escape = 0;
  int str = 0;
  int quote = 0;

  t = s;
  for (; *s; s++) {
    switch (*s) {
    case '\"': escape = 0; e = "\\\""; if(!escape && !quote) str=!str; break;
    case '\'': escape = 0; l++;        if(!str && !escape) quote=!quote; continue;
    case '\\':
      escape = 1;
      if(str || quote) { e = "\\\\"; break; }
      else { l++; continue; }
    default:   escape = 0; l++; continue;
    }
    r = fe_strnappend(r, t, l);
    r = fe_strappend (r, e);
    t = s+1;
    l = 0;
  }
  r = fe_strnappend(r, t, l);
  return fe_strappend (r, "\"");
}

/* ----------------------------------------------------------------------------
 * Return the string of the tokens TS
 */
token
string_tokens (tokens ts)
{
  token last = last_token (ts);
  token t;
  int space = 0;

  if (last) space = last->space;
  t = string_token (quote_string (text_tokens (ts)));
  t->space = space;
  return t;
}

/* ----------------------------------------------------------------------------
 * Print tokens for debugging
 */
static void
_print_tokens(tokens ts, tokens end)
{
  if (!ts || ts==end) return;
  if (max_lines>0 && max_lines<current_line) return;
  print_token(ts->head);
  if (ts->head->tag == newline_kind) {
    if (!at_sol || !ignore_newlines) printf("\n%d: ", ++current_line);
    at_sol = 1;
  } else {
    at_sol = 0;
  }
  if (max_lines>0 && max_lines<current_line) printf("\netc. etc. etc\n");
  _print_tokens(ts->tail, end);
}

void
print_tokens_to(tokens ts, tokens end)
{
  current_line = 1;
  printf ("0: ");
  _print_tokens(ts, end);
  printf("\n");
}

void
print_tokens(tokens ts)
{
  print_tokens_to (ts, NULL);
}

/* ----------------------------------------------------------------------------
 * Allocate and initialize a new token list list
 */
tokenss
new_tokenss(tokens head, tokenss tail)
{
  tokenss me = FE_NEW(tokenss);
  me->head = head;
  me->tail = tail;
  return me;
}

tokenss
append_tokens(tokenss begin, tokens end)
{
  if (!begin) return new_tokenss(end, NULL);
  begin->tail = append_tokens(begin->tail, end);
  return begin;
}

tokens
concat_tokenss(tokenss tss)
{
  if (!tss) return NULL;
  return cat_tokens(tss->head, concat_tokenss(tss->tail));
}

int
num_tokenss(tokenss tss)
{
  int i = 0;
  
  while (tss) {
    i++;
    tss = tss->tail;
  }
  return i;
}
