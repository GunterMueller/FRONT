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

#ifndef _book_print_h
#define _book_print_h

#include <stdarg.h>
#include "book_core.h"

/* conversion specification */
typedef struct {
  int flag_alternate : 1;
  int flag_zero : 1;
  int flag_minus : 1;
  int flag_blank : 1;
  int flag_plus : 1;
  int width;
  int precision;
  enum {
    fe_mod_hh,
    fe_mod_h,
    fe_mod_none,
    fe_mod_l,
    fe_mod_ll,
    fe_mod_L
  } modifier;
  char conversion;
} fe_conversion_spec_t;

/* the type of conversion functions */
typedef void (*fe_conversion_function)(fe_book_t *, fe_conversion_spec_t *, va_list *args);

/* printf to BOOK */
void fe_book_printf (fe_book_t *book, char *s, ...);

/* vprintf to BOOK, returns the remaining argument list */
void fe_book_vprintf (fe_book_t *book, char *fmt, va_list args);

/* add a conversion %CHR, calls F when it occurs */
void fe_book_register_conversion (char chr, fe_conversion_function f);

#endif /* _book_print_h */
