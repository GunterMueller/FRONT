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

/* Structure of a book:
 *
 *                      +-last----+   
 *                      |         |   
 * +---+     +---+     +---+     +---+     +---+
 * | S |-tl->| C |-tl->| S |-tl->| C |-tl->| C |
 * +---+     +---+     +---+     +---+     +---+
 *  |                                       |
 *  +-last----------------------------------+
 * 
 */
#include <assert.h>
#include "mem.h"
#include "text.h"
#include "book_core.h"

typedef struct fe_book_s fe_book_content_t;
typedef struct fe_book_s fe_book_align_t;
typedef struct fe_align_s fe_align_t;

typedef enum {
  s_section,
  s_align,
  s_content,
} part_kind;

struct fe_align_s {
  int number;
  int column;
  fe_align_t *tail;
};

struct fe_book_s {
  part_kind  kind;
  union {
    struct {
      size_t size;
      size_t max;
      char  *text;
    } content;
    struct {
      fe_book_section_t *section;
      fe_align_t *spec;
    } align;
    struct {
      fe_align_t *alignments;
      int column;
      int indent;
      int indent_size;
      fe_book_t *last;
    } section;
  };
  fe_book_t *tail;
};

/* for all books B:
     B->section.last->kind == s_content 
     no book C: C!=B such that B->section.last == C->section.last
*/

/* ----------------------------------------------------------------------------
 * Create a new content part
 */
static fe_book_content_t *
content_new (void)
{
  fe_book_content_t *me = fe_malloc (sizeof (*me));
  
  me->kind = s_content;
  me->content.size = 0;
  me->content.max = 0;
  me->content.text = NULL;
  me->tail = NULL;
  return me;
}

/* ----------------------------------------------------------------------------
 * Create a new align part
 */
static fe_book_align_t *
align_new (fe_book_section_t *section, int number)
{
  fe_book_content_t *me = fe_malloc (sizeof (*me));
  fe_align_t *spec;
  
  me->kind = s_align;
  me->align.section = section;
  me->tail = content_new ();
  for (spec = section->section.alignments; spec; spec = spec->tail) {
    if (spec->number == number) break;
  }
  if (!spec) {
    spec = fe_malloc (sizeof (*me));
    spec->number = number;
    spec->column = section->section.column;
    spec->tail = section->section.alignments;
    section->section.alignments = spec;
  }
  if (spec->column < section->section.column) {
    spec->column = section->section.column;
  }
  me->align.spec = spec;
  return me;
}

/* ----------------------------------------------------------------------------
 * Create a new section part
 */
static fe_book_section_t *
section_new (void)
{
  fe_book_section_t *me = fe_malloc (sizeof (*me));
  
  me->kind = s_section;
  me->tail = content_new ();
  me->section.column = 0;
  me->section.alignments = NULL;
  me->section.indent = 0;
  me->section.indent_size = 2;
  me->section.last = me->tail;
  return me;
}

/* ----------------------------------------------------------------------------
 * Get the last content in section BOOK
 */
static fe_book_content_t *
fe_book_end (fe_book_section_t *book)
{
  return book->section.last;
}

/* ----------------------------------------------------------------------------
 * Get a pointer to where the next character will be written
 */
char *
fe_book_position (fe_book_section_t *book)
{
  fe_book_content_t *c = fe_book_end (book);
  return c->content.text + c->content.size;
}

/* ----------------------------------------------------------------------------
 * Add DSIZE bytes to CONTENT
 */
static void
content_grow (fe_book_content_t *content, size_t dsize)
{
  size_t nsize;
  
  assert (content->kind == s_content);
  
  nsize = content->content.size + dsize;
  if (content->content.max <= nsize) {
    if (nsize < 2*content->content.max) {
      content->content.max *= 2;
    } else {
      content->content.max = nsize + 1;
    }
    content->content.text = fe_realloc (content->content.text,
                                        content->content.max);
  }
}

/* ----------------------------------------------------------------------------
 * Add character C to the end of CONTENT
 * Pre: there is enough room to add it
 */
static void
content_cadd (fe_book_content_t *content, char c)
{
  assert (content->kind == s_content);
  assert (content->content.size+1 < content->content.max);
  content->content.text [content->content.size] = c;
  content->content.size ++;
  content->content.text [content->content.size] = 0;
}

/* ----------------------------------------------------------------------------
 * Add NUM characters C to the end of CONTENT
 * Pre: there is enough room to add it
 */
static void
content_caddn (fe_book_content_t *content, int num, char c)
{
  int i;
  
  assert (content->kind == s_content);
  assert (content->content.size+num < content->content.max);
  if (num<=0) return;
  
  for (i=0; i<num; i++) {
    content->content.text [content->content.size + i] = c;
  }
  content->content.size += num;
  content->content.text [content->content.size] = 0;
}

/* ----------------------------------------------------------------------------
 * Add B to the end of section A
 */
static fe_book_section_t *
fe_book_append (fe_book_section_t *a, fe_book_t *b)
{
  fe_book_content_t *content = NULL;
  fe_book_t *tail = a->section.last->tail;
  assert (a->kind == s_section);

  a->section.last->tail = b;
  switch (b->kind) {
  case s_section:
    content = content_new ();
    b->section.last->tail = content;
    b = content;
    break;
  case s_align:
    b = b->tail;
    break;
  default:
    break;
  }
  b->tail = tail;
  a->section.last = b;
  return a;
}

/* ----------------------------------------------------------------------------
 * Start a new book
 */
fe_book_t *
fe_book_start (void)
{
  return section_new ();
}

/* ----------------------------------------------------------------------------
 * Free memory used by BOOK
 */
void
fe_book_free (fe_book_t *book)
{
  fe_book_t *b, *next;
  
  for (b = book; b; b = next) {
    next = b->tail;
    if (b->kind == s_content) {
      fe_free (b->content.text);
    }
    fe_free (b);
  }
}

/* ----------------------------------------------------------------------------
 * Create a flattened version of BOOK, all (but the first) section
 * will be removed
 */
fe_book_t *
fe_book_flattened (const fe_book_t *book)
{
  const fe_book_t *b;
  fe_book_t *flat = fe_book_start ();
  
  for (b = book; b; b = b->tail) {
    switch (b->kind) {
    case s_section:
      continue;
    case s_align:
      if (fe_book_column (flat) <= b->align.spec->column) {
        fe_book_putnc (flat, b->align.spec->column - fe_book_column (flat), ' ');
      }
      break;
    case s_content:
      fe_book_puts (flat, b->content.text);
      break;
    }
  }
  return flat;
}

/* ----------------------------------------------------------------------------
 * Convert the BOOK to a string, the BOOK will remain intact
 */
char *
fe_book_to_string (const fe_book_t *book)
{
  fe_book_t *flat = fe_book_flattened (book);
  fe_book_content_t *end = fe_book_end (flat);
  char *result = end->content.text;
  
  end->content.text = NULL;
  fe_book_free (flat);
  return result;
}

/* ----------------------------------------------------------------------------
 * Write BOOK to file FS
 */
void
fe_book_to_file (const fe_book_t *book, FILE *fs)
{
  char *s = fe_book_to_string(book);
  
  fputs (s,fs);
  fe_free (s);
}

/* ----------------------------------------------------------------------------
 * Add a section at the end of stream BOOK
 */
fe_book_t *
fe_book_add_section (fe_book_t *book)
{
  fe_book_t *section = section_new ();
  fe_book_append (book, section);
  
  section->section.column = book->section.column;
  section->section.indent = book->section.indent;
  section->section.indent_size = book->section.indent_size;
  return section;
}

/* ----------------------------------------------------------------------------
 * The column where the next character will be written
 */
int
fe_book_column (const fe_book_t *book)
{
  return book->section.column;
}

/* ----------------------------------------------------------------------------
 * Add an alignment specification to BOOK
 */
void
fe_book_align (fe_book_t *book, int nr)
{
  fe_book_align_t *align = align_new (book, nr);
  fe_book_append (book, align); 
}

/* ----------------------------------------------------------------------------
 * Set the number of spaces used for indentation
 */
void
fe_book_set_indent_size (fe_book_t *book, int size)
{
  book->section.indent_size = size;
}

/* ----------------------------------------------------------------------------
 * Fix the indentation to the column IND
 */
int
fe_book_set_indent (fe_book_t *book, int ind)
{
  int i = book->section.indent;
  book->section.indent = ind;
  return i;
}

/* ----------------------------------------------------------------------------
 * Fix the indentation to the current column
 */
int
fe_book_indent_here (fe_book_t *book)
{
  int i = book->section.indent;
  book->section.indent = book->section.column;
  return i;
}

/* ----------------------------------------------------------------------------
 * Increase indentation
 */
void
fe_book_indent (fe_book_t *book)
{
  book->section.indent += book->section.indent_size;
}

/* ----------------------------------------------------------------------------
 * Decrease indentation
 */
void
fe_book_undent (fe_book_t *book)
{
  assert (book->section.indent!=0);
  book->section.indent -= book->section.indent_size;
}

/* ----------------------------------------------------------------------------
 * Add the character C to the end of stream BOOK
 */
void
fe_book_putc (fe_book_t *book, char c)
{
  fe_book_t *content = fe_book_end (book);

  if (c!='\n' && book->section.column==0) {
    content_grow (content, book->section.indent);
    content_caddn (content, book->section.indent, ' ');
    book->section.column += book->section.indent;
  }
  content_grow (content, 1);
  content_cadd (content, c);
  if (c=='\n') book->section.column = 0;
  else         book->section.column ++;
}

/* ----------------------------------------------------------------------------
 * Add N characters C to the end of stream BOOK
 */
void
fe_book_putnc (fe_book_t *book, int n, char c)
{
  int i;
  
  for (i=0; i<n; i++) {
    fe_book_putc (book, c);
  }
}

/* ----------------------------------------------------------------------------
 * Add the string S to the end of stream BOOK
 */
void
fe_book_puts (fe_book_t *book, const char *s)
{
  int i;

  if (!s) return;
  for (i=0; s[i]; i++) {
    fe_book_putc (book, s[i]);
  }
}

/* ----------------------------------------------------------------------------
 * Add at most LEN bytes of the string S to the end of stream BOOK
 */
void
fe_book_putns (fe_book_t *book, int len, const char *s)
{
  int i;

  if (!s) return;
  for (i=0; s[i] && i<len; i++) {
    fe_book_putc (book, s[i]);
  }
}
