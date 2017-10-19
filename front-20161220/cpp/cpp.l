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

%option noyywrap nounput
%pointer

%{
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#ifdef _POSIX_MAPPED_FILES
# include <sys/mman.h>
#endif

#include <front/mem.h>
#include "token.h"

static tokens begin = NULL;
static tokens end = NULL;

int enable_c99 = 0;
int enable_trigraph = 0;
static int initial = 0;
static int line = 1;
static int col = 0;
static int space = 0;
static int sol = 0;
static int sysfile = 0;

static char *inbuffer;
static char *bufpos;
static int   buflen; 
 
static int strcount(char *s, char c);
static void append(token t);
static void skip_to(const char *end);
static int read_input(char *buf, int max);

#define YY_INPUT(buf,result,max)      result=read_input(buf,max)
%}

Non_digit    [a-zA-Z_]
Alphanum     [a-zA-Z_0-9]
NOT_Q_BS_CR  [\000-\011\013-&(-\[\]-\177]
NOT_DQ_BS_CR [\000-\011\013-!#-\[\]-\177]
Bs           [\\]
Digit        [0-9]
OctDigit     [0-7]
OctNumber    {OctDigit}{OctDigit}?{OctDigit}?
HexDigit     [0-9a-fA-F]
HexNumber    {HexDigit}+
Esc          ([abfnrtv\"\'?\\\n]|{OctNumber}|[xX]{HexNumber})
Quote        [\']
Double_quote [\"]
NOT_GR_CR    [^>\n]
NOT_DQ_CR    [^"\n]
Space        [\000-\007\013- ]

%x INC C99
%%
<*>"\t"                            { int d=8-(col%8); col+=d; space = 1;}
<*>{Space}+                        { col+=yyleng; space = 1;}
<*>[\015]?"\n"                     { append (newline_token (yytext)); line++; col=0; sol=1; space=0; BEGIN(initial); }
<*>"/*"                            { skip_to("*/"); space=1; }
<INC,C99>"//"                      { skip_to("\n"); sol=1; col=0; space=0; }

        /* preprocessing tokens */
<*>#                               { append (hash_token (yytext)); }
<*>##                              { append (glue_token (yytext)); }
<*>include                         { append (include_token (yytext)); BEGIN(INC); }
<*>include_next                    { append (include_next_token (yytext)); BEGIN(INC); }
<*>define                          { append (define_token (yytext)); }
<*>undef                           { append (undef_token (yytext)); }
<*>line                            { append (line_token (yytext)); }
<*>if                              { append (if_token (yytext)); }
<*>ifdef                           { append (ifdef_token (yytext)); }
<*>ifndef                          { append (ifndef_token (yytext)); }
<*>else                            { append (else_token (yytext)); }
<*>elif                            { append (elif_token (yytext)); }
<*>endif                           { append (endif_token (yytext)); }
<*>error                           { append (error_token (yytext)); }
<*>warning                         { append (warning_token (yytext)); }
<*>pragma                          { append (pragma_token (yytext)); }
<*>defined                         { append (defined_token (yytext)); }
<*>ident                           { append (ident_token (yytext)); }
<*>"\\"                            { if (sol && space) { space=0; append (other_token (" ")); }
                                     append (escape_token (yytext));
                                   }
<*>__LINE__                        { append (line_alias_token (yytext)); }

        /* header-name */
<INC>\<{NOT_GR_CR}+\>  {
        append (sys_header_token(yytext));
        BEGIN(initial);
}
<INC>\"{NOT_DQ_CR}+\"  {
        append (header_token(yytext));
        BEGIN(initial);
}

        /* pp-number */
<*>(".")?{Digit}({Alphanum}|[eE][+-]|\.)*    {
        append (number_token(yytext));
}

        /* character-constant */
<*>("L")?{Quote}({NOT_Q_BS_CR}|{Bs}{Esc})+{Quote}  {
        append (char_token(yytext));
        line+=strcount (yytext,'\n');
}

        /* string-literal */
<*>("L")?{Double_quote}({NOT_DQ_BS_CR}|{Bs}{Esc})*{Double_quote}   {
        append (string_token(yytext));
        line+=strcount (yytext,'\n');
}

        /* punctuator (except *) */
<*>[\[\](){},:=;#]        {
        append (punctuator_token (yytext));
}
<*>"..."   {
        append (punctuator_token (yytext));
}

        /* operator */
<*>"->"            { append (operator_token (yytext)); }
<*>"++"            { append (operator_token (yytext)); }
<*>"--"            { append (operator_token (yytext)); }
<*>"sizeof"        { append (operator_token (yytext)); }
<*>"<<"            { append (operator_token (yytext)); }
<*>">>"            { append (operator_token (yytext)); }
<*>"<="            { append (operator_token (yytext)); }
<*>">="            { append (operator_token (yytext)); }
<*>"=="            { append (operator_token (yytext)); }
<*>"!="            { append (operator_token (yytext)); }
<*>"&&"            { append (operator_token (yytext)); }
<*>"||"            { append (operator_token (yytext)); }
<*>"*="            { append (operator_token (yytext)); }
<*>"/="            { append (operator_token (yytext)); }
<*>"%="            { append (operator_token (yytext)); }
<*>"+="            { append (operator_token (yytext)); }
<*>"-="            { append (operator_token (yytext)); }
<*>"<<="           { append (operator_token (yytext)); }
<*>">>="           { append (operator_token (yytext)); }
<*>"&="            { append (operator_token (yytext)); }
<*>"^="            { append (operator_token (yytext)); }
<*>"|="            { append (operator_token (yytext)); }
<*>[\[\]().&*+\-~!/%<>^|?:=,#]      {
        append (operator_token (yytext));
}

        /* idenfitier */
<*>{Non_digit}{Alphanum}*  {
        append (id_token(yytext));
}

        /* other non-white space character */
<*>.       { append (other_token (yytext)); }

%%

static int
strcount(char *s, char c)
{
  int i=0;
  while(*s) {
    if(*s==c) i++;
    s++;
  }
  return i;
}

static void
append(token t)
{
  static int loc=0;
  tokens ts = new_tokens(t, NULL);
  t->loc = loc++;
  t->line = line;
  t->col = col;
  t->sol = sol;
  t->sysfile = sysfile;
  col += yyleng;
  if (!end) begin = end = ts;
  else {
    end->head->space = space;
    end = end->tail = ts;
  }
  space = 0;
  sol = 0;
}

static void
skip_to(const char *end)
{
  int escape = 0;
  int nl = 0;
  int c;

  c = input();
  do {
    do {
      if (c==EOF) {
        fprintf(stderr, "%s: Unterminated comment\n", begin->head->file->name);
        return;
      }
      if (c==end[0]) break;
      if (c=='\\') escape=1;
      else {
        if (c=='\n') { nl = !escape; line++; col=0; }
        else col++;
        escape = 0;
      }
      c = input();
    } while(1);
    escape=0;
    if (!end[1]) break;
    c = input();
  } while(c!=end[1]);
  if (c=='\n') { nl = 1; line++; col=0; }
  else col++;
  
  if (nl) append (newline_token ("\n")); 
}
/*
static void
skip_to(const char *end)
{
  int len = strlen(end);
  FE_ARRAY(char,match,len+1);
  int p = 0;
  int nl = 0;
  while(p<len) {
    match[p] = input();
    if (match[p]==EOF) break;
    if (match[p]=='\n') { nl = 1; line++; col=0; }
    else col++;
    while (strncmp(match, end, p+1)!=0) {
      memmove(match,match+1,p);
      p--;
    }
    p++;
  }
  if (nl) append (newline_token ("\n")); 
}
*/
static int
filesize(FILE *fs)
{
  long pos = ftell(fs);
  long res;
  fseek(fs,0, SEEK_END);
  res = ftell(fs);
  fseek(fs,pos,SEEK_SET);
  assert(res <= INT_MAX);
  return res;
}

static int
read_input(char *buf, int max)
{
  int len = buflen;
  if (max<len) len=max;
  if (!enable_trigraph) {
    strncpy(buf,bufpos,len);
    bufpos+=len;
  } else {
    int i, q = 0;

    for(i=0; i<max && *bufpos; ) {
      if(q==2) {
        switch(bufpos[q]) {
        case '=':  buf[i++] = '#';  bufpos+=q+1; continue;
        case '(':  buf[i++] = '[';  bufpos+=q+1; continue;
        case '/':  buf[i++] = '\\'; bufpos+=q+1; continue;
        case ')':  buf[i++] = ']';  bufpos+=q+1; continue;
        case '\'': buf[i++] = '^';  bufpos+=q+1; continue;
        case '<':  buf[i++] = '{';  bufpos+=q+1; continue;
        case '!':  buf[i++] = '|';  bufpos+=q+1; continue;
        case '>':  buf[i++] = '}';  bufpos+=q+1; continue;
        case '-':  buf[i++] = '~';  bufpos+=q+1; continue;
        }
      } else if(bufpos[q]=='?') {
        q++;
        continue;
      }
      q=0;
      buf[i++] = *bufpos++;
    }
    len = i;
  }
  buflen-=len;
  return len;
}

static char *
buffer_stdin (int *len)
{
  /* We cannot fseek/ftell on stdin, hence use repeat-until-done scheme. */

  int size = 8192;
  int max  = size, n;
  char *buf = fe_malloc (size+1), *pos = buf;
  *len = 0;
  while ((n = fread (pos, 1, max, stdin)) == max)
  {
    buf = fe_realloc (buf, size+size+1);
    *len += n;
    pos   = buf + *len;
    max   = size;
    size += size;
  }
  *len += n;
  if (ferror (stdin)) fprintf (stderr, "An error occurred while reading from stdin.\n");
  return buf;
}

#ifndef _POSIX_MAPPED_FILES

static void
buffer_file(const char *filename)
{
  FILE *in;
  if (filename) {
    in = fopen (filename, "rb"); /* open in bin mode for ftell on windows */
    assert (in);
    buflen = filesize(in);
    bufpos = inbuffer = fe_malloc(buflen+1);
    fread(bufpos, 1,buflen,in);
    fclose(in);
  }
  else {
    bufpos = inbuffer = buffer_stdin (&buflen);
  }
  inbuffer[buflen]=0;
}

static void
unbuffer(void)
{
  fe_free(inbuffer);
}

#else

static void
buffer_file(const char *filename)
{
  FILE *in;
  if (filename) {
    in = fopen (filename, "rb"); /* open in bin mode for ftell on windows */
    assert (in);
    buflen = filesize(in);
    bufpos = inbuffer = mmap (NULL, buflen, PROT_READ, MAP_SHARED, fileno(in), 0);
    fclose(in);
  }
  else {
    bufpos = inbuffer = buffer_stdin (&buflen);
    inbuffer[buflen]=0;
  }
}

static void
unbuffer(void)
{
}

#endif

tokens
scan_file(const char *filename, int sf)
{
  buffer_file(filename);
  begin = NULL;
  end = NULL;
  line = 1;
  col = 0;
  sysfile = sf;
  append (sof_token());
  sol = 1;
  line = 1;
  col = 0;
  if(enable_c99) initial = C99;
  else           initial = 0;
  BEGIN(initial);
  yylex();
  append (eof_token());
  unbuffer();
  return begin;
}

tokens
scan_string(char *string, const char *file, int l, int c, int s, int sf)
{
  if(enable_c99) initial = C99;
  else           initial = 0;
  BEGIN(initial);
  buflen = strlen(string);
  inbuffer = bufpos = string;
  begin = NULL;
  end = NULL;
  sol = s;
  sysfile = sf;
  line = l;
  col = c;
  pseudo_file(file);
  yylex();
  leave_file();
  
  if (end) end->head->space = space;
  return begin;
}

tokens
rescan_string(char *string, File file, int l, int c, int s, int sf)
{
  if(enable_c99) initial = C99;
  else           initial = 0;
  BEGIN(initial);
  buflen = strlen(string);
  inbuffer = bufpos = string;
  begin = NULL;
  end = NULL;
  sol = s;
  sysfile = sf;
  line = l;
  col = c;
  temporary_file(file);
  yylex();
  leave_file();
  
  if (end) end->head->space = space;
  return begin;
}

tokens
scan_include(char *string, const char *file, int l, int c, int s, int sf)
{
  if(enable_c99) initial = C99;
  else           initial = 0;
  BEGIN(INC);
  buflen = strlen(string);
  inbuffer = bufpos = string;
  begin = NULL;
  end = NULL;
  sol = s;
  sysfile = sf;
  line = l;
  col = c;
  pseudo_file(file);
  yylex();
  leave_file();
  if (end) end->head->space = space;
  return begin;
}
