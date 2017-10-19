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
#ifndef _error_h
#define _error_h

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "old_error.h"

/* Name of the program */
extern char *fe_package;

/* if there has been a system error, print a message and exit */
#define SYS_ERROR()  if(errno!=0) { perror(fe_package); exit(1); }

/* Print a message to stderr */
void fe_error(char *msg, ...);

/* Print a message to stderr and abort */
void _fe_abort(char *file, int line, char *string);

#define fe_abort(m)  _fe_abort (__FILE__,__LINE__,m)

#endif /* _error_h */
