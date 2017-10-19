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

/* Error functions */
#define ERROR_HANDLER
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "scan_support.h"

Bool	NoWarnings = FALSE;
int     WarningLevel = 0;
int	NumErrors = 0;
int	NumWarnings = 0;

static Bool VSOut = FALSE; /* visual studio output format */
void (*Front_Parse_Error)(char *msg, char *token) = _Front_Parse_Error;
void (*FrontFatalError)(char *text, ...) = _FrontFatalError;
void (*FrontError)(Bool nl, char *text, ...) = _FrontError;
void (*FrontWarning)(Bool nl, long level, char *text, ...) = _FrontWarning;
void (*FrontMessage)(char *text, ...) = _FrontMessage;
void (*InputError)(int loc, Bool nl, char *text, ...) = _InputError;
void (*InputWarning)(int loc, Bool nl, long level, char *text, ...) = _InputWarning;

/* ----------------------------------------------------------------------------
 * Set output format to visual studio format: <file>(<pos>):<msg>
 */
void VisualStudioOutput(void)
{
  VSOut = TRUE;
}

/* ----------------------------------------------------------------------------
 * Print a message to standard-error in the form of 
 * Error:  <text>\n
 */
void _FrontError(Bool nl, char *text, ...)
{
  va_list arg_list;

  va_start(arg_list, text);
  fprintf(stderr,"Error: ");
  vfprintf(stderr, text, arg_list);
  if (nl) fputc('\n',stderr);
  va_end(arg_list);
  NumErrors++;
}

/* ----------------------------------------------------------------------------
 * Print a message to standard-error in the form of 
 * Warning:  <text>\n
 */
void _FrontWarning(Bool nl, long level, char *text, ...)
{
  va_list arg_list;
  
  if (NoWarnings || level < WarningLevel) return;

  va_start(arg_list, text);
  fprintf(stderr,"Warning: ");
  vfprintf(stderr, text, arg_list);
  if (nl) fputc('\n',stderr);
  va_end(arg_list);
  NumWarnings++;
}

/* ----------------------------------------------------------------------------
 * Print a message to standard-error in the form of 
 * <Programme-name>: Fatal Error:  <text>\n
 * And stop programme.
 */
void _FrontFatalError(char *text, ...)
{
  va_list arg_list;

  va_start(arg_list, text);
  fprintf(stderr,"Fatal Error: ");
  vfprintf(stderr, text, arg_list);
  fputc('\n',stderr);
  va_end(arg_list);
  exit(3);
}

/* ----------------------------------------------------------------------------
 * Print a message to standard-error in the form of 
 * <Programme-name>:  <text>
 * And stop programme.
 */
void _FrontMessage(char *text, ...)
{
  va_list arg_list;

  va_start(arg_list, text);
  vfprintf(stderr, text, arg_list);
  va_end(arg_list);
}

/* ----------------------------------------------------------------------------
 * produce a file-name and line-number
 * visual studio format: <file>(<loc>): Error:
 * front format:         Error: <file>: line <loc>:
 */
static void ErrorLoc(Ident file, int line, int pos)
{
  if (count_chars) {
    if (VSOut) {
      fprintf(stderr, "%s(%d,%d): Error: ", IDENT_STRING(file), line, pos);
    } else {
      fprintf(stderr, "Error: %s: line %d,%d: ", IDENT_STRING(file), line, pos);
    }
  } else {
    if (VSOut) {
      fprintf(stderr, "%s(%d): Error: ", IDENT_STRING(file), line);
    } else {
      fprintf(stderr, "Error: %s: line %d: ", IDENT_STRING(file), line);
    }
  }
}

/* ----------------------------------------------------------------------------
 * produce a file-name and line-number
 * visual studio format: <file>(<loc>): Warning:
 * front format:         Warning: <file>: line <loc>:
 */
static void WarningLoc(long level, Ident file, int line, int pos)
{
  if (NoWarnings || level < WarningLevel) return;

  if (count_chars) {
    if (VSOut) {
      fprintf(stderr, "%s(%d,%d): Warning: ", IDENT_STRING(file), line, pos);
    } else {
      fprintf(stderr, "Warning: %s: line %d,%d: ", IDENT_STRING(file), line, pos);
    }
  } else {
    if (VSOut) {
      fprintf(stderr, "%s(%d): Warning: ", IDENT_STRING(file), line);
    } else {
      fprintf(stderr, "Warning: %s: line %d: ", IDENT_STRING(file), line);
    }
  }
}

/* ----------------------------------------------------------------------------
 * produce a file-name line-number and then the error
 * visual studio format: <file>(<loc>): Error: <text> 
 * front format:         Error: <file>: line <loc>: <text>
 */
void _InputError(int loc, Bool nl, char *text, ...)
{
  va_list arg_list;
  int line, pos;
  Ident file;

  va_start(arg_list, text);
  find_location (loc, &line, &pos, &file);
  ErrorLoc(file, line, pos);
  vfprintf (stderr, text, arg_list);
  if (nl) fputc('\n',stderr);
  va_end(arg_list);
  NumErrors++;
}

/* ----------------------------------------------------------------------------
 * produce a file-name line-number and than the warning
 * visual studio format: <file>(<loc>): Warning: <text> 
 * front format:         Warning: <file>: line <loc>: <text>
 */
void _InputWarning(int loc, Bool nl, long level, char *text, ...)
{
  va_list arg_list;
  int line, pos;
  Ident file;

  if (NoWarnings || level < WarningLevel) return;

  va_start(arg_list, text);
  find_location (loc, &line, &pos, &file);
  WarningLoc(level, file, line, pos);
  vfprintf (stderr, text, arg_list);
  if (nl) fputc('\n',stderr);
  va_end(arg_list);
  NumWarnings++;
}

void
_Front_Parse_Error(char *msg, char *token)
{
  InputError (SCAN_POSITION, TRUE, "%s at token \"%s\"", msg, token);
  exit(1);
}

/* ----------------------------------------------------------------------------
 * Print location LOC
 * visual studio format: <file>(<line>,<pos>)
 * front format:         <file>: line <line>,<pos>:
 */
void
Print_loc(int loc)
{
  int line, pos;
  Ident file;
  
  find_location (loc, &line, &pos, &file);
  if (VSOut) {
    printf("%s(%d,%d)\n", IDENT_STRING(file), line, pos);
  } else {
    printf("%s: line %d,%d\n", IDENT_STRING(file), line, pos);
  }
}
