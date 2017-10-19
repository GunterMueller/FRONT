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
#include <front/text.h>
#include <front/mem.h>
#include <front/support.h>
#include "emit.h"
#include "token.h"

typedef struct s_files *files;

struct s_files {
  const char *file;
  files tail;
};


#define FL_START 1
#define FL_CONT  2
#define FL_SYS   4
#define FL_C     8

int    FilePos = 0;
int    emit_to_original_loc = 0;

static token *TokenTable = NULL;
static int    TokenTableSize = 0;
static int    StoreTokens = 1;
static File   CurrentFile = NULL;
static int    Nesting = 0;
static int    CurrentLine = 1;
static int    AddSpace = 0;
static token  CurrentToken = NULL;
static tokens TokenString = NULL;
static token  LastToken = NULL;

static files Files = NULL;
static int Column0 = 1;
static char *Buffer = NULL;
static int   BufMax = -1;
static int   BufSize = 0;
static int   BufEnd  = 0;
static FILE *Out = NULL;
static int no_separating_spaces = 0;

static char *SpillBuf = NULL;
static int SpillSize = 0;
static int SpillMax = 0;

/* ----------------------------------------------------------------------------
 * State saving: allow an emit process to interrupt another one.
 */

typedef struct {
  int    TokenTableSize;
  int    StoreTokens;
  File   CurrentFile;
  int    Nesting;
  int    CurrentLine;
  int    AddSpace;
  token  CurrentToken;
  tokens TokenString;
  token  LastToken;

  files  Files;
  FILE  *Out;
  char  *Buffer;
  int    BufSize;
  int    BufMax;
  int    BufEnd;
  int    FilePos;
  int    Column0;
  int    no_sep_spc;

  char  *SpillBuf;
  int    SpillSize;
  int    SpillMax;

  /* More? */
} emit_state;

static void
save_state (emit_state *e)
{
  e->TokenTableSize = TokenTableSize;
  e->StoreTokens    = StoreTokens;
  e->CurrentFile    = CurrentFile;
  e->Nesting        = Nesting;
  e->CurrentLine    = CurrentLine;
  e->AddSpace       = AddSpace;
  e->CurrentToken   = CurrentToken;
  e->TokenString    = TokenString;
  e->LastToken      = LastToken;

  e->Files   = Files;
  e->Out     = Out;
  e->Buffer  = Buffer;
  e->BufSize = BufSize;
  e->BufMax  = BufMax;
  e->BufEnd  = BufEnd;
  e->FilePos = FilePos;
  e->Column0 = Column0;
  e->no_sep_spc = no_separating_spaces;

  e->SpillBuf  = SpillBuf;
  e->SpillSize = SpillSize;
  e->SpillMax  = SpillMax;
}

static void
restore_state (emit_state *e)
{
  TokenTableSize = e->TokenTableSize;
  StoreTokens    = e->StoreTokens;
  CurrentFile    = e->CurrentFile;
  Nesting        = e->Nesting;
  CurrentLine    = e->CurrentLine;
  AddSpace       = e->AddSpace;
  CurrentToken   = e->CurrentToken;
  TokenString    = e->TokenString;
  LastToken      = e->LastToken;

  Files   = e->Files;
  Out     = e->Out;
  Buffer  = e->Buffer;
  BufSize = e->BufSize;
  BufMax  = e->BufMax;
  BufEnd  = e->BufEnd;
  FilePos = e->FilePos;
  Column0 = e->Column0;
  no_separating_spaces = e->no_sep_spc;

  SpillBuf  = e->SpillBuf;
  SpillSize = e->SpillSize;
  SpillMax  = e->SpillMax;
}

/* ----------------------------------------------------------------------------
 * Initialize emission to FS, or Buffer if FS is NULL
 */
static void
init_emit(FILE *fs, tokens ts)
{
  CurrentFile = NULL;
  Nesting = 0;
  CurrentLine = 1;
  AddSpace = 0;

  no_separating_spaces = 0;
  Out     = fs;
  Buffer  = NULL;
  BufSize = 0;
  BufMax  = -1;
  BufEnd  = 0;
  Column0 = 1;
  Files   = NULL;
  TokenString = ts;
  LastToken = NULL;

  SpillBuf  = NULL;
  SpillSize = 0;
  SpillMax  = 0;
}

static void
init_table(tokens ts)
{
  TokenTable = fe_realloc(TokenTable, sizeof(token)*(TokenTableSize+num_tokens(ts)));
}

#if 0
/* unused: */
static void
store_token(void)
{
  if (TokenTable && StoreTokens) TokenTable[TokenTableSize] = CurrentToken;
}
/* ----------------------------------------------------------------------------
 * non-zero if we've seen this file before
 */
static int
sof_file(const char *file)
{
  files f;
  
  for (f = Files; f; f=f->tail) {
    if (strcmp(f->file, file)==0) return 1;
  }
  f = FE_NEW(files);
  f->file = file;
  f->tail = Files;
  Files = f;
  return 0;
}
#endif
/* ----------------------------------------------------------------------------
 * Number of characters V takes in decimal representation
 */
static int
size(int v)
{
  int p=10;
  int d=1;
  if (v<0) {
    d++;
    v = -v;
  }
  while(p<=v) { d++; p*=10; }
  return d;
}

/* ----------------------------------------------------------------------------
 * Increase buffer capacity up to BufMax
 */
#if 0
/* Now integrated in spill_printf; can be cleaned up in due time. */
static char *
grow_buffer(int d)
{
  if (BufEnd) return NULL;
  if (BufMax>0) {
    if (BufMax<BufSize+d) {
      BufEnd = 1;
      return NULL;
    } 
  } else {
    Buffer = fe_realloc(Buffer, BufSize+d+1);
  }
  BufSize+=d;
  return Buffer+BufSize-d;
}
#endif

/* ----------------------------------------------------------------------------
 * Output SIZE characters: up to BufMax into Buffer, the rest into SpillBuf.
 */
static int
spill_printf(int size, const char *fmt, ...)
{
  int n;
  va_list a;
  if (BufMax <= 0 || BufSize + size < BufMax)
  {
    if (BufMax <= 0) Buffer = fe_realloc (Buffer, BufSize + size + 1);

    va_start (a, fmt);
    n = vsprintf (Buffer + BufSize, fmt, a);
    va_end (a);

    BufSize += size;
  }
  else
  {
    static char temp[8192];
    int buf = BufMax - BufSize - 1;
    int spill = size - buf;
    if (SpillSize + spill > SpillMax) {
      SpillMax = SpillSize + spill;
      SpillBuf = fe_realloc (SpillBuf, SpillMax + 1);
    }
    va_start (a, fmt);
    assert (size < sizeof (temp));
    n = vsprintf (temp, fmt, a);
    va_end (a);

    /* Split temp over Buffer and SpillBuf. */
    sprintf (Buffer + BufSize, "%*.*s", buf, buf, temp);
    sprintf (SpillBuf + SpillSize, "%s", temp + buf);

    SpillSize += spill;
    BufSize += buf;
    BufEnd = 1;
  }
  return n;
}

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

/* ----------------------------------------------------------------------------
 * Output data from SpillBuf: up to BufMax into Buffer, keep the rest.
 */
static void
emit_spill(void)
{
  if (BufMax <= 0) {
    assert (!SpillBuf); /* No spilling should occur when Buffer grows dynamically. */
  } else if (SpillSize > 0) {
    int m = min (SpillSize, BufMax - BufSize - 1); /* Prevent spilling spills, hence force the then branch to be taken in spill_printf()! */
    spill_printf (m, "%s", SpillBuf);
    memmove (SpillBuf, SpillBuf + SpillSize, m);
    SpillSize -= m;
  }
}

/* ----------------------------------------------------------------------------
 * Print an integer
 */
static void
emit_int(int v)
{
  CurrentToken->pos = FilePos;
  if (!Out) {
    FilePos += spill_printf (size(v),"%d", v);
  } else {
    FilePos += fprintf (Out, "%d", v);
  }
  Column0=0;
}

/* ----------------------------------------------------------------------------
 * Print a string
 */
static void
emit_string(const char *s)
{
  CurrentToken->pos = FilePos;
  if (!Out) {
    FilePos += spill_printf (fe_strlen (s),"%s", s);
  } else {
    FilePos += fprintf (Out, "%s", s);
  }
  Column0=0;
}

/* ----------------------------------------------------------------------------
 * Print N spaces
 */
static void
emit_spaces(int n)
{
  if (!Out) {
    FilePos += spill_printf (n,"%*s", n, "");
  } else {
    FilePos += fprintf (Out, "%*s", n, "");
  }
  Column0=0;
}

/* ----------------------------------------------------------------------------
 * print a new line
 */
static void
nl(void)
{
  emit_string("\n");
  Column0 = 1;
}

/* ----------------------------------------------------------------------------
 * go to column 0
 */
static void
column0(void)
{
  if (!Column0) nl();
}

/* ----------------------------------------------------------------------------
 * Print a line pragma
 */
static void
line_pragma(File file, int line, int flags)
{
  assert (file);
  if (!cpp_inhibit_linemarkers) {
    column0 ();
    emit_string ("#line ");
    emit_int    (line);
    emit_string (" \"");
    emit_string (file->name);
    emit_string ("\"");
  } 
  if (!cpp_inhibit_expansion) {
    if (flags & FL_START) emit_string (" 1");
    if (flags & FL_CONT)  emit_string (" 2");
    if (flags & FL_SYS)   emit_string (" 3");
    if (flags & FL_C)     emit_string (" 4");
  }
  if (!cpp_inhibit_linemarkers) nl ();
}

/* ----------------------------------------------------------------------------
 * Fill to the current token position
 */
static int
fill(void)
{
  token t = CurrentToken;
  int lines, d = t->outl - CurrentLine;
  int flags = 0;
  
  assert(TokenString != NULL);
  if (t->tag==newline_kind) {
    if (TokenString->tail != NULL) {
      lines = d = TokenString->tail->head->outl - CurrentLine;
    } else {
      lines = d = 1;
    }
  }

  if (AddSpace) emit_string(" ");
  if (d<=0) return 0;

  if (!emit_to_original_loc && t->tag!=newline_kind) return 0;
  if (d<=8) {
    while (d--) nl();
  } else {
    if (t->sysfile) flags = FL_SYS;
    line_pragma (CurrentFile, CurrentLine+d, flags);
  }
  if (emit_to_original_loc) emit_spaces (t->outc);
  else {
    if (TokenString->tail) emit_spaces (TokenString->tail->head->outc);
    CurrentLine+=lines;
  }
  return 1;
}

/* ----------------------------------------------------------------------------
 * Non-zero if we need to add a space between A and B
 */
static void
separating_space(void)
{
  token a = LastToken;
  token b = CurrentToken;
  token x = NULL, y = NULL, z = NULL;
  tokens l, l0;
  char *merged;

  if (!a || !b) return;
  if (no_separating_spaces) return;
  if (a->space || a->outl<b->outl) return;
  if (is_special(a) || is_special(b)) return;
  merged =  fe_strcat(a->text, b->text);
  l0 = l = scan_string (merged, NULL, 0, 0, 0, 0);
  if (l) { x = l->head; l = l->tail; }
  if (l) { y = l->head; l = l->tail; }
  if (l) { z = l->head; l = l->tail; }
  if (z || !y || strcmp(a->text, x->text)!=0) {
    emit_spaces(1);
  }
  free_tokens(l0);
}

/* ----------------------------------------------------------------------------
 * Save the token T in the token table
 */
static void
save_token(token t)
{
  NOT_USED(t);
  if (TokenTable && StoreTokens) TokenTable[TokenTableSize++] = t;
/*   if(!BufEnd) printf ("%p %6d %s\n",t,t->pos, t->text); */
}

static void
adjust_current_line(void)
{
  if (emit_to_original_loc && CurrentLine < CurrentToken->outl) {
    CurrentLine = CurrentToken->outl;
  }
}

/* ----------------------------------------------------------------------------
 * Print the token string TS to OUT
 */
static void
_emit_tokens(void)
{
  emit_spill();

  for (;TokenString && !BufEnd; TokenString = TokenString->tail) {
    int flags = 0;
    token n = NULL;
    
    CurrentToken = TokenString->head;
    separating_space();
    if (TokenString->tail) n = TokenString->tail->head;
    if (CurrentToken->sysfile) flags = FL_SYS;
    
    switch (CurrentToken->tag) {
    case sof_kind:
      AddSpace = 0;
      fill ();
      if (!cpp_inhibit_expansion) {
        if (!Nesting) line_pragma (CurrentToken->file, 1, flags);
        else          line_pragma (CurrentToken->file, 1, flags | FL_START);
      }
      CurrentFile = CurrentToken->file;
      CurrentLine = 1;
      Nesting++;
      break;
    case loc_kind:
      line_pragma (CurrentToken->file, CurrentToken->outl, flags);
      CurrentLine = CurrentToken->outl;
      AddSpace = 0;
      break;
    case eof_kind: /* note eof is the first token _outside_ the file */
      Nesting--;
      if (n && n->sysfile) flags = FL_SYS;
      else                 flags = 0;
      if (!cpp_inhibit_expansion)
        if (Nesting) line_pragma (CurrentToken->file, CurrentToken->outl, flags | FL_CONT);
      CurrentFile = CurrentToken->file;
      CurrentLine = CurrentToken->outl;
      AddSpace = 0;
      break;
    case newline_kind:
      if (!emit_to_original_loc) fill();
      AddSpace = 0;
      break;
    case nil_kind:
      if (fill ()) AddSpace = 0;
      else         AddSpace = CurrentToken->space;
      adjust_current_line ();
      Column0=0; /* forces extra newline if nil on empty line at end of file */
      break;
    case line_alias_kind:
      fill ();
      adjust_current_line ();
      emit_int (CurrentLine);
      save_token (CurrentToken);
      AddSpace = CurrentToken->space;
      break;
    default:
      fill ();
      adjust_current_line ();
      emit_string (CurrentToken->text);
      save_token (CurrentToken);
      AddSpace = CurrentToken->space;
    }
    LastToken = CurrentToken;
  }
}

/* ----------------------------------------------------------------------------
 * Get the text corresponding to the token string TS 
 */
char *
text_tokens (tokens ts)
{
  token last;
  char *b;
  emit_state e;
  save_state (&e);

  init_emit (NULL, ts);
  StoreTokens = 0;
  no_separating_spaces = 1;
  last = last_token (ts);
  if (last) last->space = 0;
  if (ts->head) CurrentLine = ts->head->outl;
  _emit_tokens ();

  b = Buffer;
  restore_state (&e);
  return b;
}

/* ----------------------------------------------------------------------------
 * Print the token string TS to OUT
 */
void
emit_tokens(FILE *fs, tokens ts)
{
  token last;
  emit_state e;
  save_state (&e);

  init_emit (fs, ts);
  last = last_token (ts);
  if (last) last->space = 0;
  if (ts->head) CurrentLine = ts->head->outl;
  _emit_tokens ();
  column0();

  restore_state (&e);
}

/* ----------------------------------------------------------------------------
 * Remove some superfluous tokens
 */
static tokens
remove_nl (tokens ts)
{
  tokens start = ts;
  tokens prev = NULL;

  while (ts) {
    token t = ts->head;
    if (t->tag==newline_kind) {
      if (emit_to_original_loc ||
          (ts->tail && ts->tail->head->tag==newline_kind)) {
        if (prev) prev->tail = ts->tail;
        else      start = ts->tail;
      }
    } else prev = ts;
    ts = ts->tail;
  }
  return start;
}

static tokens
optimize_tokens (tokens ts)
{
  tokens start;
  tokens ns;
  token t, n = NULL;

  ts = remove_nl (ts);
  if (!ts) return ts;
  start = ts;

  for (ns = ts->tail;
       ns;
       ts = ns, ns = ts->tail) {
    t = ts->head;
    n = ns->head;
    
    switch (t->tag) {
    case loc_kind: break;
    case nil_kind: n->outc = t->outc; break;
    default:
      if (n->tag==nil_kind) {
        t->space |= n->space;
        ts->tail = ns->tail;
      }
      break;
    }
  }
  return start;
}

/* ----------------------------------------------------------------------------
 * Optimize tokens ts and then emit
 */
void
emit_tokens_optimized (FILE *fs, tokens ts)
{
  tokens optts;

  /* assert(ts != NULL); */ /* assert unwanted if you do a dynamic check in the next line */
  if (!ts) return;
  optts = optimize_tokens (ts);
  if (!optts) return;
  emit_tokens(fs, optts);
}
/* ----------------------------------------------------------------------------
 * Write as many tokens from the current TokenString as possible into BUF of
 * size MAX
 */
int
emit_fill(char *buf, int max)
{
  Buffer  = buf;
  BufMax  = max;
  BufSize = 0;
  BufEnd  = 0;
  _emit_tokens ();
  return BufSize;
}

/* ----------------------------------------------------------------------------
 * Start filling from tokens ts
 */
void
start_fill(tokens ts)
{
  init_emit(NULL, ts);
  init_table(ts);
}

#if 0
void
continue_fill(sequence sq)
{
  TokenString = cat_tokens (TokenString, sq->start);
  TokenTable = fe_realloc(TokenTable, sizeof(token)*(TokenTableSize +
                                                     num_tokens(TokenString)));
}
#endif

/* ----------------------------------------------------------------------------
 * get the token at position loc
 */
token
find_token(int loc)
{
  int l, h, m;

  if (loc<0) return NULL;
  if (!TokenTable) return NULL;
  if (TokenTable[TokenTableSize-1]->pos<loc) return NULL;
  
  l = 0;
  h = TokenTableSize;
  while (l < h-1) {
    /* TokenTable[l]->pos < loc <= TokenTable[h]->pos */
    m = (l+h) / 2; /* l < m < h */
    if (TokenTable[m]->pos >= loc) { h = m; }
    else                           { l = m; }
  }
  if (l==h-1 && TokenTable[h]->pos==loc) l++;
  /* TokenTable[h-1]->pos < loc <= TokenTable[h]->pos && l == h-1 */
  return TokenTable[l];
}
