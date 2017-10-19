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
#include <unistd.h>
#include <string.h>
#include "filename.h"
#include "text.h"
#include "mem.h"

#ifndef SLASH
#define SLASH '/'
#endif


static const char *
get_cwd(void)
{
  static char *current_dir = NULL;
  int len = 0;
  char *buffer=NULL;

  if (current_dir) return current_dir;
  do {
    len+=80;
    buffer = fe_realloc(buffer,len); 
  } while(!getcwd(buffer,len));
  current_dir = buffer;
  return current_dir;
}

/* ----------------------------------------------------------------------------
 * Drop .. and . dirs
 */
char *
fe_dropdotdirs(char *filename)
{
  int done = 0;
  char *f = filename;
  if (!filename) return filename;
  do {
    if (fe_isprefix ("./", f)) {
      f += 2;
    } else if (fe_isprefix ("../", f)) {
      f += 3;
    } else if (fe_isprefix ("//", f)) {
      f += 1;
    } else {
      done = 1;
    }
  } while (!done);
  return memmove (filename, f, fe_strlen (f) + 1);
}

/* ----------------------------------------------------------------------------
 * Create a new string that contains the full path name of FILENAME
 */
char *
fe_fullname(const char *filename)
{
  char *cwd;
  
  if (fe_absolutepath(filename)) return fe_strdup(filename);
  cwd = fe_strdup(get_cwd());
  if (filename) {
    cwd = fe_strappend(cwd, "/");
    cwd = fe_strappend(cwd, filename);
  }
  return cwd;
}

/* ----------------------------------------------------------------------------
 * Does FILENAME have extension EXT?
 */
int
fe_hasext(const char *filename, char *ext)
{
  return strcmp(filename+fe_strlen(filename)-fe_strlen(ext),ext)==0;  
}

/* ----------------------------------------------------------------------------
 * Create a string containing the basename of FILENAME
 */
char *
fe_basename(const char *filename)
{
  const char *slash=filename;

  while(filename[1]) {
    if(filename[0]==SLASH) slash=filename+1;
    filename++;
  }
  return fe_strdup(slash);
}

/* ----------------------------------------------------------------------------
 * Drop N directories from FILENAME
 */
char *
fe_dropdirn(const char *filename, int n)
{
  int i, start = 0;
  int end=strlen(filename);
  
  for(i=0; i!=end && n!=0; i++) {
    if(filename[i]==SLASH) {
      start=i+1;
      n--;
    }
  }
  return fe_strdup(filename+start);
}

/* ----------------------------------------------------------------------------
 * Drop 1 directory from FILENAME
 */
char *
fe_dropdir(const char *filename)
{
  return fe_dropdirn(filename,1);
}

/* ----------------------------------------------------------------------------
 * Drop N extensions from FILENAME
 */
char *
fe_dropextn(const char *filename, int n)
{
  int i;
  int dot=strlen(filename);
  
  for(i=dot; i!=0 && n!=0; i--) {
    if(filename[i]=='.') {
      dot=i;
      n--;
    }
  }
  return fe_strndup(filename,dot);
}

/* ----------------------------------------------------------------------------
 * Drop 1 extension from FILENAME
 */
char *
fe_dropext(const char *filename)
{
  return fe_dropextn(filename,1);
}

/* ----------------------------------------------------------------------------
 * Drop all extensions from FILENAME
 */
char *
fe_dropextall(const char *filename)
{
  return fe_dropextn(filename, -1);  
}

/* ----------------------------------------------------------------------------
 * Replace the extenstion of FILENAME by EXTENSION
 */
char *
fe_replext(const char *filename, const char *extenstion)
{
  return fe_strappend(fe_dropext(filename),extenstion);
}

/* ----------------------------------------------------------------------------
 * Create a string containing the path to the file FILENAME
 */
char *
fe_getdirname(const char *filename)
{ int index;
  for (index=fe_strlen(filename); index>=0 ;index--) {
    if (filename[index]=='/') return fe_strndup(filename, index+1);
  }
  return fe_strdup("./");
}

/* ----------------------------------------------------------------------------
 * TRUE if FILENAME is an absolute path
 */
int
fe_absolutepath(const char *filename)
{
  if (!filename) return FALSE;
#ifdef __MINGW32__
  return filename[0]=='/' || filename[1]==':';
#else
  return filename[0]=='/';
#endif
}

/* ----------------------------------------------------------------------------
 *  Create a string containing path in which backslashes are replaced 
 *  by slashes 
 */
char *
fe_slashpath(const char *path)
{
  char *res;
  int i;
  int len;
  res = fe_strdup(path);
  len = fe_strlen(res);
  for (i = 0; i < len; i++) {
    if (res[i] == '\\') {
      res[i] = '/';
    }
  }
  return res;
}
