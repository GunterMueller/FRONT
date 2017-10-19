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

#include <stdarg.h>
#include <stdio.h>
#include "token.h"
#include "pp.h"

int Success = 1;

/* ----------------------------------------------------------------------------
 * Give a syntax error on token T
 */
void
cpp_vsyntax (token t, char *msg, va_list args)
{
  if (t != NULL) {
    if (visual_studio_compatible) {
      fprintf (stderr, "%s(%d,%d): ", t->file->name, t->line, t->col+1);
    } else {
      fprintf (stderr, "%s:%d:%d: ", t->file->name, t->line, t->col+1);
    }
  }
  vfprintf (stderr, msg, args);
  Success = 0;
}

void
cpp_syntax (token t, char *msg, ...)
{
  va_list args;
  va_start (args, msg);
  cpp_vsyntax (t, msg, args);
  va_end(args);
}

/* ----------------------------------------------------------------------------
 * Give a syntax warning on token T
 */
void
cpp_vwarning (token t, char *msg, va_list args)
{
  if (t != NULL) {
    if (visual_studio_compatible) {
      fprintf (stderr, "%s(%d,%d): warning: ", t->file->name, t->line, t->col+1);
    } else{
      fprintf (stderr, "%s:%d:%d: warning: ", t->file->name, t->line, t->col+1);
    }
  }
  vfprintf (stderr, msg, args);
}

void
cpp_warning (token t, char *msg, ...)
{
  va_list args;
  va_start (args, msg);
  cpp_vwarning (t, msg, args);
  va_end(args);
}
