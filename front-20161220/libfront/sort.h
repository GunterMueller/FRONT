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
#ifndef _libfront_sort_h
#define _libfront_sort_h

#include <stdlib.h>

void fe_quick_sort (void *base, size_t nmemb, size_t elsize, int compare(const void *, const void *));
void fe_insert_sort (void *base, size_t nmemb, size_t elsize, int compare(const void *, const void *));
void fe_randomize (void *base, size_t nmemb, size_t elsize);

#endif /* _libfront_sort_h */
