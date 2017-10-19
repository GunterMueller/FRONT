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
#include "sequence.h"
#include "token.h"

static int TRACE=0;

/* ----------------------------------------------------------------------------
 * Allocate and initialize a new token sequence
 */
sequence
new_sequence(tokens start, int eval_defined)
{
  sequence me = FE_NEW(sequence);

  me->start = start;
  me->in = me->out = NULL;
  me->eval_defined = eval_defined;
  return me;
}


/* ----------------------------------------------------------------------------
 * Create a NIL terminated sequence
 */
sequence
tmp_sequence(tokens s, int eval_def)
{
  return new_sequence (append_token (s, eos_token ()), eval_def);
}

/* ----------------------------------------------------------------------------
 * Insert the tokens in BEGIN after the current token
 * Discards tokens in between out and in.
 */
void
insert_tokens(sequence sq, tokens begin)
{
  tokens end = NULL;
  if (begin) for(end = begin; end->tail; end = end->tail);

  if (!sq->in) { sq->start = begin; return; }
  if (!begin) {
    assert (!end);
    begin = sq->in->tail;
  }
  if (end) end->tail = sq->in->tail;
  if (sq->out) sq->out->tail = begin;
  else         sq->start = begin;
  sq->in = sq->out;
}

/* ----------------------------------------------------------------------------
 * Shift to the next token
 */
token
next_token(sequence sq)
{
  if (!sq->in) sq->in = sq->start;
  else         sq->in = sq->in->tail;
  if (!sq->in) return NULL;
  enable_defs (sq->in->head->defs);
  return sq->in->head;
}

/* ----------------------------------------------------------------------------
 * Get the next token
 */
token
peek_token(sequence sq)
{
  if (sq->in) {
    if (sq->in->tail) return sq->in->tail->head;
  } else {
    if (sq->start) return sq->start->head;
  }
  return NULL;
}

/* ----------------------------------------------------------------------------
 * Get the next non-newline token
 */
token
peek_text_token(sequence sq)
{
  tokens first = NULL;
  
  if (sq->in) {
    if (sq->in->tail) first = sq->in->tail;
  } else {
    if (sq->start) first = sq->start;
  }
  while (first && first->head->tag == newline_kind) first = first->tail;
  if (!first) return NULL;
  return first->head;
}

/* ----------------------------------------------------------------------------
 * Get the current token
 */
token
this_token(sequence sq)
{
  if (sq->in)     return sq->in->head;
  return NULL;
}

/* ----------------------------------------------------------------------------
 * Get the current output token
 */
token
out_token(sequence sq)
{
  if (sq->out)     return sq->out->head;
  return sq->start->head;
}

/* ----------------------------------------------------------------------------
 * Accept the current output token, but no newlines
 */
void
pass(sequence sq)
{
  token t;

  if (sq->out) {
    t = sq->out->head;
    if (TRACE) { printf ("PASS: "); print_token(t); printf("\n"); }
    if (t->outl<0) t->outl = t->line;
    if (t->outc<0) t->outc = t->col;
    sq->out = sq->out->tail;
  } else {
    sq->out = sq->start;
  }
}

/* ----------------------------------------------------------------------------
 * Accept all tokens upto the current input token
 */
void
pass_all(sequence sq)
{
  while (sq->out!=sq->in) pass (sq);
}

/* ----------------------------------------------------------------------------
 * Print the sequence SQ
 */
void
print_sequence(sequence sq)
{
  tokens a, b;
  a = sq->out;
  b = sq->in;
  if (a) a = a->tail;
  else   a = sq->start;
  printf ("<<<OUT>>> ");
  if (b) {
    if (a!=b->tail) print_tokens_to(a, b->tail);
    b = b->tail;
  } else if (!sq->out) {
    b = sq->start;
  } else {
    b = a;
  }
  printf ("<<<IN>>> ");
  if (b) print_tokens (b);
  printf ("\n");
}
