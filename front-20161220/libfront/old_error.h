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

/* general headerfile for errors */
#include <stdio.h>
#include "support.h"

#ifndef _error_h_
#define _error_h_

extern Bool  NoWarnings;  /* Suppress warnings */
extern int  WarningLevel;  /* Minimum of warnings to be given */
extern int  NumErrors;  /* Number of errors produced so far */
extern int  NumWarnings;  /* Number of warnings produced so far */

/* change to Visual Studio output format */
void VisualStudioOutput(void);

/* Report an error/warning on stdout, optionally with a newline */
void _FrontError(Bool nl, char *text, ...);
extern void (*FrontError)(Bool nl, char *text, ...);
void _FrontWarning(Bool nl, long level, char *text, ...);
extern void (*FrontWarning)(Bool nl, long level, char *text, ...);
void _FrontMessage(char *text, ...);
extern void (*FrontMessage)(char *text, ...);


/* Report an error/warning on stdout for location loc in the input text */
void _InputError(int loc, Bool nl, char *text, ...);
extern void (*InputError)(int loc, Bool nl, char *text, ...);
void _InputWarning(int loc, Bool nl, long level, char *text, ...);
extern void (*InputWarning)(int loc, Bool nl, long level, char *text, ...);

void _Front_Parse_Error(char *msg, char *token);
extern void (*Front_Parse_Error)(char *msg, char *token);

void _FrontFatalError(char *text, ...);
extern void (*FrontFatalError)(char *text, ...);

/* Print a location in the form of <file>: line <linenr>,<column> on stdout */
void Print_loc(int loc);

#endif
