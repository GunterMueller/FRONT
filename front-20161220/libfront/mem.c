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
#include <stdlib.h>
#include "error.h"

/* ----------------------------------------------------------------------------
 * Allocate SIZE bytes on heap, exit if unsuccessful
 */
void *
fe_malloc(size_t size)
{
  void *result;
  errno=0;
  
  result=malloc(size);
  SYS_ERROR();
  return result;
}

/* ----------------------------------------------------------------------------
 * Allocate SIZE bytes on heap and clear, exit if unsuccessful
 */
void *
fe_calloc(size_t num, size_t size)
{
  void *result;
  errno=0;

  result=calloc(num, size);
  SYS_ERROR();
  return result;
}

/* ----------------------------------------------------------------------------
 * Reallocate PTR to SIZE bytes on heap, exit if unsuccessful
 */
void *
fe_realloc(void *ptr, size_t size)
{
  void *result;
  errno=0;

  result=realloc(ptr,size);
  SYS_ERROR();
  return result;
}


void 
fe_free(void *ptr)
{
  free (ptr);
}
