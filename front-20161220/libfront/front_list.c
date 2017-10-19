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

#ifndef __MINGW32__

#if !defined(__FreeBSD__)&& !defined(__OpenBSD__)
#include <alloca.h>
#endif
#else
#define alloca __builtin_alloca
#endif
#include <stdlib.h>
#include "front_list.h"
#include "mem.h"
#include "text.h"

Front_List vFront_Enlist (int number, va_list args)
{
  Pointer data;
  Front_List l=NULL, h=NULL;
  
  while(number--) {
    data = va_arg(args,Pointer);
    if (!h) h = l = Create_Front_List (data, NULL);
    else l = Front_List_next(l) = Create_Front_List (data, NULL);
  }
  return h;
}

Front_List Front_Enlist (int number, ...)
{
  Front_List l;
  va_list args;
  
  va_start (args, number);
  l = vFront_Enlist(number, args);
  va_end (args);
  return l;
}

Front_List Create_Front_List (Pointer data, Front_List next)
{
  Front_List l = fe_malloc (sizeof(*l));
  Front_List_data(l) = data;
  Front_List_next(l) = next;
  return l;
}

void Front_List_free (Front_List l)
{
  if (l == NULL) return;
  Front_List_free (Front_List_next(l));
  fe_free (l);
}


Front_List Front_List_dup (Front_List l)
{
  if (l == NULL) return NULL;
  return Create_Front_List (Front_List_data(l), 
                            Front_List_dup (Front_List_next(l)));
}

/* No side effect */
Front_List Front_List_concat_node (Front_List l, Pointer data)
{
  if (l == NULL) return Create_Front_List (data, NULL);
  return Create_Front_List (Front_List_data(l), 
                            Front_List_concat_node (Front_List_next(l), data));
}

/* No side effect */
Front_List Front_List_concat (Front_List l, Front_List m)
{
  if (l == NULL) return m;
  if (m == NULL) return l;
  return Create_Front_List (Front_List_data(l), 
                            Front_List_concat (Front_List_next(l), m));
}

void Front_List_insert (Front_List prev, Front_List cur, Pointer data)
{
  Front_List_next(prev) = Create_Front_List (data, cur);
}

void Front_List_remove_node (Pointer data, Front_List *l)
{
  if (*l == NULL) return;
  if (Front_List_data(*l) == data) {
    *l = Front_List_next(*l);
    return;
  }
  Front_List_remove_node (data, &Front_List_next(*l));
}

void Front_List_insert_node (Pointer data, Front_List *l)
{
  if (*l==NULL) {
    *l = Create_Front_List (data, *l);
    return;
  }
  if (data == Front_List_data(*l)) return;
  Front_List_insert_node (data, &Front_List_next(*l));
}


/* Side effect on l */
void Front_List_append_node (Front_List *l, Pointer data)
{
  if (*l == NULL)  {
    *l = Create_Front_List (data, NULL);
    return;
  }
  Front_List_append_node (&Front_List_next(*l), data);
}

/* Side effect on l */
void Front_List_append (Front_List *l, Front_List m)
{
  if (*l == NULL) { *l = m; return; }
  if (m == NULL) return;
  Front_List_append (&Front_List_next(*l), m);
}

/* Return element of l containing data, NULL if not found */
Front_List Front_List_contains (Front_List l, Pointer data)
{
  LIST_TRAVERSE (l) if (Front_List_data(l) == data) return l;
  return NULL;
}

/* Length of a list */
Int List_size (Front_List l)
{
  Int s = 0;
  LIST_TRAVERSE (l) s++;
  return s;
}

/* Last element of a list, NULL if list is empty */
Pointer List_last (Front_List l)
{
  for (; l; l = Front_List_next(l)) {
    if (Front_List_next(l) != NULL) continue;
    return Front_List_data(l);
  }
  return NULL;
}

/* Element i of a list, NULL if list is empty */
Pointer List_elem (Front_List l, int i)
{ if (l==NULL) return NULL;
  if (i < 0) return NULL;
  if (i==0) return Front_List_data(l);
  return List_elem (Front_List_next(l), i-1);
}


/* Reverse the elements in a list, makes a copy */
Front_List reverse (Front_List l, Front_List r)
{
  if (l==NULL) return r;
  return reverse (Front_List_next(l), Create_Front_List (Front_List_data(l), r));
}

Front_List List_reverse (Front_List l)
{ return reverse (l, NULL);
}

/**************/

Front_Optional Create_Front_Optional (Pointer data)
{ Front_Optional me;
  me = (Front_Optional)fe_malloc (sizeof(*me));
  (*me).data = data;
  return me;
}

Optional_Int Create_Optional_Int (Int data)
{ Optional_Int me;
  me = (Optional_Int)fe_malloc (sizeof(*me));
  (*me).data = data;
  return me;
}

Optional_Bool Create_Optional_Bool (Bool data)
{ Optional_Bool me;
  me = (Optional_Bool)fe_malloc (sizeof(*me));
  (*me).data = data;
  return me;
}

Optional_Char Create_Optional_Char (Char data)
{ Optional_Char me;
  me = (Optional_Char)fe_malloc (sizeof(*me));
  (*me).data = data;
  return me;
}

Optional_Float Create_Optional_Float (Float data)
{ Optional_Float me;
  me = (Optional_Float)fe_malloc (sizeof(*me));
  (*me).data = data;
  return me;
}

String
ConcatStrings(List_String ss)
{
  String t, s;
  if (!ss) return fe_strdup("");
  t = ConcatStrings (List_String_next(ss));
  s = List_String_data (ss);
  return Front_StrAllocf("%s%s",s,t);
}

/* Sort elements in c */
void Front_sort_list (Front_List c, int(*compare)(const Pointer*, const Pointer *))
{
  Int n = List_size(c);
  Pointer *a;
  Int i;
  Front_List l;
  a = alloca(n*sizeof(Pointer));
  
  for (l = c, i = 0; l; l = Front_List_next(l), i++) {
    a[i] = Front_List_data(l);
  }
  qsort (a, n, sizeof(*a), (void*)compare);
  for (l = c, i = 0; l; l = Front_List_next(l), i++) {
    Front_List_data(l) = a[i];
  }
}

void
Front_List_filter (Front_List *l, Bool filter(Pointer, Front_List))
{
  if (!l || !*l) return;
  Front_List_filter(&TAIL(*l), filter);
  if (!filter(HEAD(*l), TAIL(*l))) {
    *l = TAIL(*l);
  }
}

void
Front_List_filter_simple (Front_List *l, Bool filter(Pointer))
{
  if (!l || !*l) return;
    Front_List_filter_simple (&TAIL(*l), filter);
    if (!filter(HEAD(*l))) {
      *l = TAIL(*l);
  }
}

static Bool
Front_List_filter_is_unique(Pointer p, Front_List l)
{
  return ( Front_List_contains(l, p) == NULL );
}

void
Front_List_filter_dups (Front_List *l)
{
  Front_List_filter(l, Front_List_filter_is_unique);
}

Front_List
Front_List_intersect (Front_List a, Front_List b)
{
  Front_List r = NULL;
  if (!a || !b) return NULL;
  r = Front_List_intersect (TAIL(a), TAIL(b));
  if (Front_List_contains (b, HEAD(a)) &&
      !Front_List_contains (r, HEAD(a))) {
    r = Create_Front_List (HEAD(a), r);
  }
  if (Front_List_contains (a, HEAD(b)) &&
      !Front_List_contains (r, HEAD(b))) {
    r = Create_Front_List (HEAD(b), r);
  }
  return r;
}

Front_List
Front_List_split (Front_List a)
{
  Front_List t = TAIL(a);
  TAIL(a) = NULL;
  return t;
}
