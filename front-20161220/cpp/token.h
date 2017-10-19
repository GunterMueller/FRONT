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

#ifndef _cpp_token_h
#define _cpp_token_h

typedef struct s_token   *token;
typedef struct s_tokens  *tokens;
typedef struct s_tokenss *tokenss;

#include <stdio.h>
#include <string.h>
#include "file.h"
#include "define.h"

enum token_tag {
  eos_kind, /* end of sequence */
  sof_kind, /* start of file */
  eof_kind, /* end of file */
  loc_kind, /* location marker */
  nil_kind, /* empty token */
  special_token = nil_kind,
  
  hash_kind,
  glue_kind,

  identifier_start,
  include_kind = identifier_start, 
  include_next_kind, 
  define_kind, 
  undef_kind, 
  line_kind, 
  if_kind, 
  ifdef_kind, 
  ifndef_kind, 
  else_kind, 
  elif_kind, 
  endif_kind,
  error_kind,
  warning_kind,
  pragma_kind,
  defined_kind,
  ident_kind,
  line_alias_kind,
  identifier_kind,
  identifier_end = identifier_kind,
  
  header_name_kind,
  sys_header_name_kind,
  pp_number_kind,
  char_const_kind,
  string_kind,
  operator_kind,
  punctuator_kind,
  escape_kind,
  newline_kind,
  other_kind,
  merged_kind,
  num_token_kind
};

struct s_token {
  enum token_tag   tag;
  int              loc;
  File             file;
  int              line, col;
  char            *text;
  int              index; /* used during macro expansion */
  int              outl, outc;
  int              sol;  /* start of line */
  int              sysfile;  /* in a system file */
  int              space;
  int              variadic; /* non-zero for variadic macro args */
  defines          defs;
  int              pos;   /* character position in output */
};

token new_token(enum token_tag tag, const char *text);
void free_tokens(tokens s);
void free_token(token t);
token dup_token(token t);
token int_token(int v);
int same_token (token a, token b);
int eval_constant(token t, int *ok, int *is_unsigned);
void print_token(token t);

char *token_file (void *t);
char *token_line (void *t);
char *token_col (void *t);
int token_loc (void *);

#define is_token(t,s)          ( strcmp((t)->text,s)==0 )
#define is_ident(t)            ( identifier_start <= (t)->tag && (t)->tag <= identifier_end )
#define is_special(t)          ( t->tag < special_token )

#define sof_token()            new_token (sof_kind, "$SOF")
#define eof_token()            new_token (eof_kind, "$EOF")
#define loc_token()            new_token (loc_kind, "$LOC")
#define nil_token()            new_token (nil_kind, "$NIL")
#define eos_token()            new_token (eos_kind, "$EOS")

#define hash_token(text)       new_token (hash_kind, text)
#define glue_token(text)       new_token (glue_kind, text)
#define include_token(text)    new_token (include_kind, text)
#define include_next_token(text) new_token (include_next_kind, text)
#define define_token(text)     new_token (define_kind, text)
#define undef_token(text)      new_token (undef_kind, text)
#define line_token(text)       new_token (line_kind, text)
#define if_token(text)         new_token (if_kind, text)
#define ifdef_token(text)      new_token (ifdef_kind, text)
#define ifndef_token(text)     new_token (ifndef_kind, text)
#define else_token(text)       new_token (else_kind, text)
#define elif_token(text)       new_token (elif_kind, text)
#define endif_token(text)      new_token (endif_kind, text)
#define error_token(text)      new_token (error_kind, text)
#define warning_token(text)    new_token (warning_kind, text)
#define pragma_token(text)     new_token (pragma_kind, text)
#define defined_token(text)    new_token (defined_kind, text)
#define header_token(text)     new_token (header_name_kind, text)
#define sys_header_token(text) new_token (sys_header_name_kind, text)
#define ident_token(text)      new_token (ident_kind, text)
#define line_alias_token(text) new_token (line_alias_kind, text)

#define id_token(text)         new_token (identifier_kind, text)
#define number_token(text)     new_token (pp_number_kind, text)
#define char_token(text)       new_token (char_const_kind, text)
#define string_token(text)     new_token (string_kind, text)
#define operator_token(text)   new_token (operator_kind, text)
#define punctuator_token(text) new_token (punctuator_kind, text)
#define escape_token(text)     new_token (escape_kind, text)
#define newline_token(text)    new_token (newline_kind, text)
#define other_token(text)      new_token (other_kind, text)

struct s_tokens {
  token  head;
  tokens tail;
};

#define single(t) new_tokens(t, NULL)

tokens new_tokens(token head, tokens tail);
tokens append_token(tokens begin, token end);
tokens dup_tokens(tokens ts);
tokens cat_tokens(tokens a, tokens b);
tokens append_ws_if(tokens toks, int c);
tokens copy_props(tokens to, token from);
void override_location(tokens to, token from);
int num_tokens(tokens ts);
token last_token(tokens ts);
token string_tokens (tokens ts);
token second_token (tokens ts);
int same_tokens (tokens as, tokens bs);

tokens rescan_as_include (tokens ts);

void print_tokens(tokens ts);
void print_tokens_to(tokens ts, tokens end);

struct s_tokenss {
  tokens  head;
  tokenss tail;
};

tokenss new_tokenss (tokens head, tokenss tail);
tokenss append_tokens (tokenss begin, tokens end);
tokens  concat_tokenss (tokenss tss);
int num_tokenss(tokenss tss);


#define head(t) t->head;
#define tail(t) t->tail;

tokens remove_escapes (tokens ts);
tokens remove_glue (tokens ts);

/* in cpp.l */
extern int enable_c99;
extern int enable_trigraph;

tokens rescan_string(char *string, File file, int l, int c, int s, int sf);
tokens scan_string(char *string, const char *file, int l, int c, int s, int sf);
tokens scan_include(char *string, const char *file, int l, int c, int s, int sf);
tokens scan_file(const char *filename, int sysfile);

/* in expression.y */
int evaluate(tokens ts, int *is_ok);

#endif /* _cpp_token_h */
