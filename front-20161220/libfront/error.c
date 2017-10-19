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

#include "error.h"

char *fe_package="<oops! fe_package not assigned>";

/* ----------------------------------------------------------------------------
 * Print an error message to stderr
 */
void
fe_error(char *msg, ...)
{
  va_list args;
  
  va_start(args,msg);
  fprintf(stderr,"%s: ",fe_package);
  vfprintf(stderr,msg,args);
  fprintf(stderr,"\n ");
  va_end(args);
}

/* -----------------------------------------------------------------------------
 * Print a message to stderr and abort
 */
void
_fe_abort (char *file, int line, char *string)
{
  fprintf(stderr,"%s:%s:%d: ABORT! %s", fe_package, file, line, string);
  abort();
}

