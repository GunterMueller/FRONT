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
#ifndef _filename_h
#define _filename_h

#include "support.h"

/* Does FILENAME have extension EXT? */
int
fe_hasext(const char *filename, char *ext);
     
/* Drop .. and . dirs */
char *
fe_dropdotdirs(char *filename);

/* Get the full path name of FILENAME */
char *
fe_fullname(const char *filename);

/* Create a string containing the basename of FILENAME */
char *
fe_basename(const char *filename);

/* Drop N directories from FILENAME, creates a new string */
char *
fe_dropdirn(const char *filename, int n);

/* Drop 1 directory from FILENAME, creates a new string */
char *
fe_dropdir(const char *filename);

/* Drop N extensions from FILENAME, creates a new string */
char *
fe_dropextn(const char *filename, int n);

/* Drop 1 extension from FILENAME, creates a new string */
char *
fe_dropext(const char *filename);

/* Drop all extensions from FILENAME, creates a new string */
char *
fe_dropextall(const char *filename);

/* Replace the extension of FILENAME by EXTENSION. */
char *
fe_replext(const char *filename, const char *extenstion);

/* Create a string containing the path to the file FILENAME */
char *
fe_getdirname(const char *filename);

/* TRUE if FILENAME is an absolute path */
int
fe_absolutepath(const char *filename);

/* Create a string containing path in which backslashes are replaced 
   by slashes 
*/
char *
fe_slashpath(const char *path);

#endif /* _filename_h */
