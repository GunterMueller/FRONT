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
#include <math.h>
#include <stdarg.h>
#include "text.h"
#include "mem.h"
#include "book.h"

static void cvt_signed (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);
static void cvt_unsigned (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);
static void cvt_char (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);
static void cvt_string (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);
static void cvt_pointer (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);
static void cvt_double (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);

static void cvt_section (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);
static void cvt_indentation (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);
static void cvt_alignment (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);
static void cvt_format_string (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);
static void cvt_book (fe_book_t *book, fe_conversion_spec_t *cs, va_list args);

static void string_conversion (fe_book_t *book, fe_conversion_spec_t *cs, const char *s);
static void vprintf_args (fe_book_t *book, char *fmt, va_list args);


/* ----------------------------------------------------------------------------
 * Pre-defined conversions
 */
static fe_conversion_function conversions[256] = {
  ['d'] = cvt_signed,
  ['i'] = cvt_signed,
  ['o'] = cvt_unsigned,
  ['u'] = cvt_unsigned,
  ['x'] = cvt_unsigned,
  ['X'] = cvt_unsigned,
  ['e'] = cvt_double,
  ['E'] = cvt_double,
  ['f'] = cvt_double,
  ['F'] = cvt_double,
  ['g'] = cvt_double,
  ['G'] = cvt_double,
  ['c'] = cvt_char,
  ['s'] = cvt_string,
  ['p'] = cvt_pointer,
  ['&'] = cvt_section,
  ['='] = cvt_indentation,
  ['|'] = cvt_alignment,
  ['n'] = cvt_format_string,
  ['B'] = cvt_book,
};

/* ----------------------------------------------------------------------------
 * Create a section at the conversion spec
 * %&  : create a new section
 * %+& : create an indented new section
 * The argument must be of type fe_book_section_t **
 */
static void
cvt_section (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  fe_book_section_t **section = va_arg (args, fe_book_section_t **);
  *section = fe_book_add_section (book);
  if (cs->flag_plus) {
    fe_book_indent (*section);
  }
}

/* ----------------------------------------------------------------------------
 * Indent BOOK
 * %=  : indent to the current column, argument must be of type int *
 *       will contain the previous indentation
 * %#= : indent to the specified column, argument must be of type int *
 *       will contain the previous indentation
 * %+= : increase indentation, no argument is consumed
 * %-= : decrease indentation, no argument is consumed
 */
static void
cvt_indentation (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  int *ind;
  
  if (cs->flag_plus) {
    fe_book_indent (book);
    return args;
  }
  if (cs->flag_minus) {
    fe_book_undent (book);
    return args;
  }
  ind = va_arg (args, int*);
  if (cs->flag_alternate) {
    *ind = fe_book_set_indent (book, *ind);
  } else {
    *ind = fe_book_indent_here (book);
  }
}

/* ----------------------------------------------------------------------------
 * Add an alignment specification 
 */
static void
cvt_alignment (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  fe_book_align (book, cs->width);
}


/* ----------------------------------------------------------------------------
 * The argument is another formatted string, read its arguments from
 * ARGS.
 * %n  : print a formatted string followed by a new-line
 * %#n : print a formatted string not followed by a new-line
 */
static void
cvt_format_string (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  char *fmt = va_arg (args, char *);
  if (!cs->flag_alternate && cs->width < fe_book_column (book)) {
    fe_book_putc (book, '\n');
  }
  vprintf_args (book, fmt, args);
}

/* ----------------------------------------------------------------------------
 * The argument is another book, recognizes the same flags as %s.
 */
static void
cvt_book (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  fe_book_t *arg = va_arg (args, fe_book_t *);
  char *s = NULL;

  if (arg) s = fe_book_to_string (arg);
  string_conversion (book, cs, s);
}

/* ----------------------------------------------------------------------------
 * Print the number VAL into BOOK using RADIX DIGITS
 */
static int
print_digits (fe_book_t *book, unsigned long long val, int radix, char *digits)
{
  int len = 0;
  
  do {
    fe_book_putc (book, digits[val%radix]);
    len ++; 
    val /= radix;
  } while (val);
  fe_strrev (fe_book_position (book)-len);
  return len;
}

/* ----------------------------------------------------------------------------
 * Character to use for filling the field
 */
static char
filler_char (fe_conversion_spec_t *cs)
{
  if (cs->flag_zero && !cs->flag_minus) return '0';
  return ' ';
}

/* ----------------------------------------------------------------------------
 * Add a decimal signed integer to BOOK
 */
static void
cvt_signed (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  fe_book_t *justify = book;
  long long val;
  int width = cs->width;
  
  switch (cs->modifier) {
  case fe_mod_hh:   val = (char)va_arg (args, int); break;
  case fe_mod_h:    val = (short)va_arg (args, int); break;
  case fe_mod_l:    val = va_arg (args, long); break;
  case fe_mod_ll:   val = va_arg (args, long long); break;
  default:       val = va_arg (args, int); break;
  }

  if (!cs->flag_zero && !cs->flag_minus && width>0) {
    justify = fe_book_add_section (book);
  }
  if (val<0)               { fe_book_putc (book, '-'); width--; val = -val; }
  else if (cs->flag_blank) { fe_book_putc (book, ' '); width--; }
  else if (cs->flag_plus)  { fe_book_putc (book, '+'); width--; }
  
  if (cs->flag_zero && !cs->flag_minus && width>0) {
    justify = fe_book_add_section (book);
  }

  width -= print_digits (book, val, 10, "0123456789");
  if (width>0) fe_book_putnc (justify, width, filler_char (cs));
}

/* ----------------------------------------------------------------------------
 * Add an octal, decimal, or hexadecimal unsigned integer to BOOK
 */
static void
cvt_unsigned (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  unsigned long long val;
  fe_book_t *justify = book;
  int width = cs->width;
  
  switch (cs->modifier) {
  case fe_mod_hh:   val = (unsigned char)va_arg (args, unsigned); break;
  case fe_mod_h:    val = (unsigned short)va_arg (args, unsigned); break;
  case fe_mod_l:    val = va_arg (args, unsigned long); break;
  case fe_mod_ll:   val = va_arg (args, unsigned long long); break;
  default:       val = va_arg (args, unsigned int); break;
  }

  if (!cs->flag_minus && width>0) {
    justify = fe_book_add_section (book);
  }
  
  switch (cs->conversion) {
  case 'o': width -= print_digits (book, val, 8, "01234567"); break;
  case 'u': width -= print_digits (book, val, 10, "0123456789"); break;
  case 'x': width -= print_digits (book, val, 16, "0123456789abcdef"); break;
  case 'X': width -= print_digits (book, val, 16, "0123456789ABCDEF"); break;
  }

  if (width>0) fe_book_putnc (justify, width, filler_char (cs));  
}

/* ----------------------------------------------------------------------------
 * Add a character to BOOK
 */
static void
cvt_char (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  assert (cs->modifier != fe_mod_l);

  if (cs->width>1 && !cs->flag_minus) fe_book_putnc (book, cs->width-1, ' ');
  
  fe_book_putc (book, (char)va_arg (args, int));
  
  if (cs->width>1 && cs->flag_minus)  fe_book_putnc (book, cs->width-1, ' ');
}

/* ----------------------------------------------------------------------------
 * Add a string to BOOK
 */
static void
string_conversion (fe_book_t *book, fe_conversion_spec_t *cs, const char *s)
{
  fe_book_t *justify = book;
  int width = cs->width;
  int len, mlen;
    
  if (!cs->flag_minus) justify = fe_book_add_section (book);
  
  assert (cs->modifier != fe_mod_l);
  
  if (!s) s = "(null)";
  len = fe_strlen (s);
  mlen = len;
  if (cs->precision>=0 && cs->precision < len) {
    mlen = cs->precision;
    if (!cs->flag_minus) s+=len-mlen;
  }
  fe_book_putns (book, mlen, s);
  width -= mlen;
  
  if (width>0) fe_book_putnc (justify, width, ' ');
}

static void
cvt_string (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  string_conversion (book, cs, va_arg (args, char *));
}

/* ----------------------------------------------------------------------------
 * Add a pointer to BOOK
 */
static void
cvt_pointer (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  cs->conversion = 'x';
  cs->flag_alternate = 1;
  cvt_unsigned (book, cs, args);
}

/* ----------------------------------------------------------------------------
 * print the fractional part of VAL to BOOK
 */
static void
print_fraction (fe_book_t *book, double val, int prec, int rm0)
{
  int frac = round ((val - floor(val))*pow (10, prec));
  if (rm0) {
    while (frac%10==0 && prec>0) {
      frac/=10;
      prec--;
    }
  }
  if (prec>0) {
    fe_book_printf (book, ".%0*d",prec,frac);
  }
}

/* ----------------------------------------------------------------------------
 * Add a double to BOOK
 */
static void
cvt_double (fe_book_t *book, fe_conversion_spec_t *cs, va_list args)
{
  fe_book_t *tmp = book;
  char *string;
  int exp, dec;
  int prec = 6;
  int rm0 = 0;
  int diff, width = cs->width;
  double val = va_arg (args, double);

  if (cs->precision>=0) prec = cs->precision;
  
  if (!cs->flag_zero && !cs->flag_minus && width>0) {
    tmp = fe_book_start ();
  }

  if (val<0)               { fe_book_putc (tmp, '-'); width--; val = -val; }
  else if (cs->flag_blank) { fe_book_putc (tmp, ' '); width--; }
  else if (cs->flag_plus)  { fe_book_putc (tmp, '+'); width--; }

  if (tmp == book) {
    tmp = fe_book_start ();
  } else {
    width = cs->width;
  }
  
  exp = floor (log10 (val));
  
  if (cs->conversion=='g' || cs->conversion=='G') {
    if (prec==0) prec=1;
    rm0 = 1;
    /* prec : # significant digits */
    if (exp<=-4 || prec<=exp) {
      cs->conversion -= 2; /* e or E */
      prec --; /* 1 digit before the . */
    } else {
      cs->conversion -= 1; /* f or F */
      prec -= floor (log10 (val+1))+1;
    }
  }
  /* prec : max # digits after the . */
  
  if (cs->conversion=='f' || cs->conversion=='F') {
    dec = floor (val);
    fe_book_printf (tmp, "%d",dec);
    print_fraction (tmp, val, prec, rm0);
  }
  
  if (cs->conversion=='e' || cs->conversion=='E') {
    val = val / pow (10, exp);

    dec = floor (val);
    fe_book_printf (tmp, "%d",dec);
    print_fraction (tmp, val, prec, rm0);
    fe_book_printf (tmp, "e%+03d",exp);
  }
  /* add the value to BOOK */
  string = fe_book_to_string (tmp);
  diff = width - fe_strlen(string);
  if (!cs->flag_minus && diff>0) fe_book_putnc (book, diff, filler_char (cs));
  fe_book_puts (book, string);
  if (cs->flag_minus  && diff>0) fe_book_putnc (book, diff, filler_char (cs));
  fe_free (string);
  fe_book_free (tmp);
}

/* ----------------------------------------------------------------------------
 * convert a width or precision parameter to an int. -1 means take
 * width from an argument.
 */
static int
fmt_to_i (char **fmtp)
{
  int v = 0;
  
  if (**fmtp=='*') {
    v = -1;
    (*fmtp)++;
  } else {
    for (; **fmtp; (*fmtp)++) {
      int d = **fmtp-'0';
      if (d<0 || d>9) break;
      v = v * 10 + d;
    }
  }
  return v;
}

/* ----------------------------------------------------------------------------
 * Print a printf-like format to BOOK
 * fmt = "%{flags}{width}.{precision}{mod}{spec}"
 *   flags: # alternate form;
 *          0 zero padded;
 *          - left justified;
 *         ' ' 1 blank before signed positive number
 *          + always add sign
 *   width: the minimum width
 *          * read from args
 *   precision: precision or max width
 *              * read from args
 *   mod: hh signed char
 *        h  signed short
 *        l  signed long
 *        ll signed long long
 *        L  long double
 *   spec: d,i,o,u,x,X,e,E,f,F,g,G,c,s,p,%
 */
static fe_conversion_spec_t
print_arg (fe_book_t *book, char **fmtp, va_list args)
{
  char *fmt = *fmtp;
  fe_conversion_spec_t cs = { 0, 0, 0, 0, 0, 0, -2, fe_mod_none, 0 };

  if (*fmt == '%') {
    fe_book_putc (book, '%');
    return cs;
  }
  /* flags */
  for (;*fmt;fmt++) {
    switch (*fmt) {
    case '#': cs.flag_alternate = 1; continue;
    case '0': cs.flag_zero = 1; continue;
    case '-': cs.flag_minus = 1; continue;
    case ' ': cs.flag_blank = 1; continue;
    case '+': cs.flag_plus = 1; continue;
    }
    break;
  }
  /* width and precision */
  cs.width = fmt_to_i (&fmt);
  if (*fmt=='.') {
    fmt++;
    cs.precision = fmt_to_i (&fmt);
  }
  /* mod */
  switch (*fmt) {
  case 'h':
    while (*fmt=='h' && cs.modifier!=fe_mod_hh) {
      cs.modifier--;
      fmt++;
    }
    break;
  case 'l':
    while (*fmt=='l' && cs.modifier!=fe_mod_ll) {
      cs.modifier++;
      fmt++;
    }
    break;
  case 'L':
    cs.modifier = fe_mod_L;
    break;
  }
  /* perform conversion */
  cs.conversion = *fmt;
  if (cs.width < 0) cs.width = va_arg (args, int);
  if (cs.width < 0) {
    cs.flag_minus = 1;
    cs.width = -cs.width;
  }
  if (cs.precision==-1)  cs.precision = va_arg (args, int);
  *fmtp = fmt+1;
  conversions[(int)*fmt] (book, &cs, args);

  return cs;
}

/* ----------------------------------------------------------------------------
 * "vprintf" to BOOK
 */
static void
vprintf_args (fe_book_t *book, char *fmt, va_list args)
{
  char *s;

  for (s=fmt; *s; ) {
    if (*s=='%') {
      s++;
      print_arg (book, &s, args);
    } else {
      fe_book_putc (book, *s);
      s++;
    }
  }
}

/* ----------------------------------------------------------------------------
 * "vprintf" to BOOK
 */
void
fe_book_vprintf (fe_book_t *book, char *fmt, va_list args)
{
  return vprintf_args (book, fmt, args);
}

/* ----------------------------------------------------------------------------
 * "printf" to BOOK
 */
void
fe_book_printf (fe_book_t *book, char *s, ...)
{
  va_list args;
  va_start (args, s);
  fe_book_vprintf (book, s, args);
  va_end (args);
}

/* ----------------------------------------------------------------------------
 * Add the conversion F for character CHR.
 */
void
fe_book_register_conversion (char chr, fe_conversion_function f)
{
  conversions[(int)chr] = f;
}
