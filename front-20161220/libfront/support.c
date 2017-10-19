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

/* General support functions */
#define SUPPORT
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "support.h"
#include "text.h"

#define STR_BUF_LEN	2000	/* buffer size for func StrAllocf */


Bool NoDecorate = FALSE;

/* ----------------------------------------------------------------------------
 * strdup with formating functionality.
 */
char *Front_StrAllocf(const char *format, ...)
{
  va_list arglist;
  char *result;
  
  va_start(arglist, format);
  result = Front_vStrAllocf(format, arglist);
  va_end(arglist);

  return result;
}

/* ----------------------------------------------------------------------------
 * strdup with formating functionality.
 */
char *Front_vStrAllocf(const char *format, va_list arglist)
{
  char buffer[STR_BUF_LEN]; /* This must be the last declaration, if the buffer */
  /* overflows, it will not scramble other variables. */
  buffer[STR_BUF_LEN-1] = '\0'; 		/* to test buffer overflow */
  vsprintf(buffer, format, arglist);
  assert (!buffer[STR_BUF_LEN-1]);              /* test for overflow, if not too late */	  
  return fe_strdup(buffer);
}


