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

#ifndef _cpp_file_h
#define _cpp_file_h

typedef struct s_File *File;
typedef struct s_path *path;

#define SEARCH_CURDIR 1
#define SEARCH_NEXT   2

struct s_File {
  const char *name;
  File  parent;
  path  path;
};

File new_file(const char *name, int flags);
File pseudo_file(const char *name);
File temporary_file(File file);
File current_file(void);
void leave_file(void);

void append_include(const char *dir);
void list_includes(void);
void clear_include(void);
#endif /* _cpp_file_h */
