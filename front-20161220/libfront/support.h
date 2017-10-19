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

#ifndef _support_h_
#define _support_h_

#include <stdlib.h>
#include <stdarg.h>

typedef unsigned int Bool;

extern Bool NoDecorate;

#ifndef FALSE
#define FALSE (0)
#endif
#ifndef TRUE
#define TRUE  (1)
#endif

#ifndef NOT_USED
# define NOT_USED(x) ((x) = (x))
#endif

#if (__GNUC__ < 3)
#error front requires GCC version 3.0
#if defined(__OpenBSD__)
#error please install /usr/ports/lang/egcs/stable
#endif
#endif


/* strdup with formating functionality */
char *Front_StrAllocf(const char *format, ...);

/* strdup with formating functionality */
char *Front_vStrAllocf(const char *format, va_list arglist);

/* Traversal types for Front */
typedef enum { 
  Traverse_Accumulate = 0, /* Accumulate a value during traversal */
  Traverse_Down,	   /* Propagate a value down */
  Traverse_Stop		   /* Stop when a traverse function returns NULL */
} Front_Traversal ;

/* Traversal types for Front */
typedef enum { 
  Just_Copy = 0, 	   /* Do not clear back-edges */
  Copy_and_Clear,	   /* Copy and clear the back-edges in the copy */
  Just_Clear,		   /* Not not copy and just clear the back-edges in the original */
  Just_Traverse		   /* Not not copy nor clear the back-edges in the original.
  			      This will just change the fields in the original */
} Front_ClearBackEdges ;

#endif /* _support_h_ */
