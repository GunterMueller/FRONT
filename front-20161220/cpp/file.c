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
#include <stdio.h>
#include <string.h>
#include <front/mem.h>
#include <front/text.h>
#include <front/filename.h>
#include "file.h"

struct s_path {
  char *dir;
  path  next;
};

static path include_path;
static File Files = NULL;
static File TemporaryFile = NULL;

/* ----------------------------------------------------------------------------
 * Create a new path
 */
static path
new_path(const char *dir, path next)
{
  char *pdir = fe_slashpath(dir);
  path me = FE_NEW(path);
  if (pdir && pdir[strlen(dir)-1]!='/') pdir = fe_strappend(pdir,"/");
  me->dir = pdir;
  me->next = next;
  return me;
}

/* ----------------------------------------------------------------------------
 * Open the first FILE  found in PATH
 */
static int
get_path(File me, const char *file, int flags)
{
  path p, last = NULL;
  FILE *fs = NULL;
  char *curdir = NULL;
  char *fullname = NULL;
  char *slashfile;
  
  if (!strcmp (file, "stdin")) {
    me->name = NULL;
    me->path = NULL; 
    return 1;
  }

  slashfile = fe_slashpath(file);
  if (fe_absolutepath (slashfile)) {
    fullname = fe_strdup (slashfile);
    fs = fopen (fullname, "r");
  } else if (flags & SEARCH_CURDIR) {
    if (me->parent && me->parent->name) curdir = fe_getdirname(me->parent->name);
  /*fullname = fe_dropdotdirs (fe_strcat(curdir, slashfile));*/
    fullname = fe_strcat(curdir, slashfile);
    fs = fopen (fullname, "r");
  }
  if (flags & SEARCH_NEXT && me->parent->path) {
    p = me->parent->path->next;
  } else {
    p = include_path;
  }
  
  for (; !fs && p; p = p->next) {
    fe_free (fullname);
  /*fullname = fe_dropdotdirs (fe_strcat(p->dir, slashfile));*/
    fullname = fe_strcat(p->dir, slashfile);
    fs = fopen (fullname, "r");
    last = p;
  }
  fe_free(slashfile);
  if (!fs) return 0;
  fclose(fs);
  me->name = fullname;
  me->path = last;
  return 1;
}

/* ----------------------------------------------------------------------------
 * Enter FILE, searches the path
 */
File
new_file(const char *name, int flags)
{
  File me = FE_NEW(File);
  
  me->parent = Files;
  if (!get_path(me, name, flags)) return NULL;
  Files = me;
  return me;
}

/* ----------------------------------------------------------------------------
 * Enter pseudo file FILE
 */
File
pseudo_file(const char *name)
{
  File me = FE_NEW(File);
  
  me->name = name;
  me->parent = Files;
  me->path = NULL;
  Files = me;
  return me;
}

/* ----------------------------------------------------------------------------
 * Temporarily enter FILE
 */
File
temporary_file(File file)
{
  TemporaryFile = file;
  return file;
}

/* ----------------------------------------------------------------------------
 * Get the current file
 */
File
current_file(void)
{
  if (TemporaryFile) return TemporaryFile;
  return Files;
}

/* ----------------------------------------------------------------------------
 * Leave current file
 */
void
leave_file(void)
{
  if (TemporaryFile) {
    TemporaryFile = NULL;
  } else {
    assert (Files);
    Files = Files->parent;
  }
}

/* ----------------------------------------------------------------------------
 * append DIR to the include path
 */
void
append_include(const char *dir)
{
  path p = include_path;
  
  if (!p) include_path = new_path(dir, NULL);
  else {
    while(p->next) p = p->next;
    p->next = new_path(dir, NULL);
  }
}

/* ----------------------------------------------------------------------------
 * list all include paths on stderr
 */
void
list_includes(void)
{
  path p;
  for (p = include_path; p; p = p->next) {
    fprintf (stderr, "%s\n", p->dir);
  }
}

/* ----------------------------------------------------------------------------
 * clear include paths
 */
void
clear_include(void)
{
  include_path = NULL;
  assert(!Files);
  assert(!TemporaryFile);
}

void
print_includes(path p)
{
  printf("includes:\n");
  for(; p; p = p->next) {
    printf("  %s\n", p->dir);
  }
}
