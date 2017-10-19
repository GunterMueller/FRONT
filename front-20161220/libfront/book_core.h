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

#ifndef _book_core_h
#define  _book_core_h

typedef struct fe_book_s fe_book_t;
typedef struct fe_book_s fe_book_section_t;

#include <stdarg.h>
#include <stdio.h>

/* Start a new book */
fe_book_t *fe_book_start (void);

/* Free memory used by BOOK */
void fe_book_free (fe_book_t *book);

/* Create a flattened version of BOOK, all (but the initial) section
 * will be removed
 */
fe_book_t *fe_book_flattened (const fe_book_t *book);

/* Convert the BOOK to a string, the BOOK will remain intact.
   It is up to the user to free the string. */
char *fe_book_to_string (const fe_book_t *book);

/* Write BOOK to the file FS, inspect errno to check on errors */
void fe_book_to_file (const fe_book_t *book, FILE *fs);

/* Add a section at the end of stream BOOK */
fe_book_t *fe_book_add_section (fe_book_t *book);

/* The column where the next character will be written */
int fe_book_column (const fe_book_t *book);

/* Add an alignment specification to BOOK, reusable through NR */
void fe_book_align (fe_book_t *book, int nr);

/* Set the number of spaces used for indentation */
void fe_book_set_indent_size (fe_book_t *book, int size);

/* Increase indentation */
void fe_book_indent (fe_book_t *book);

/* Decrease indentation */
void fe_book_undent (fe_book_t *book);

/* Fix the indentation to the column IND */
int fe_book_set_indent (fe_book_t *book, int ind);

/* Fix the indentation to the current column */
int fe_book_indent_here (fe_book_t *book);

/* Add the string s at the end of section BOOK */
void fe_book_puts  (fe_book_t *book, const char *s);

/* Add atmost n bytes of the string s at the end of section BOOK */
void fe_book_putns (fe_book_t *book, int len, const char *s);

/* Add character C at the end of section BOOK */
void fe_book_putc  (fe_book_t *book, char c);

/* Add N characters C at the end of section BOOK */
void fe_book_putnc (fe_book_t *book, int n, char c);

/* The pointer to where the next character will be written.  This may
 * be invalid after the next time something is written in the book
 */
char *fe_book_position (fe_book_section_t *book);

#endif /* _book_core_h */
