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

#include <stdio.h>
#include <string.h>

#include "basic_types.h"
#include "text.h"

List_Int
_Traverse_copy_List_Int (List_Int me, void *y)
{
  if (!me) return NULL;
  return Create_List_Int (List_Int_data(me),
                          _Traverse_copy_List_Int (List_Int_next(me),y));
}

List_Char
_Traverse_copy_List_Char (List_Char me, void *y)
{
  if (!me) return NULL;
  return Create_List_Char ((int)List_Char_data(me),
                           _Traverse_copy_List_Char (List_Char_next(me),y));
}

List_Bool
_Traverse_copy_List_Bool (List_Bool me, void *y)
{
  if (!me) return NULL;
  return Create_List_Bool (List_Bool_data(me),
                           _Traverse_copy_List_Bool (List_Bool_next(me),y));
}

List_Ident
_Traverse_copy_List_Ident (List_Ident me, void *y)
{
  if (!me) return NULL;
  return Create_List_Ident (List_Ident_data(me),
                            _Traverse_copy_List_Ident (List_Ident_next(me),y));
}

List_String
_Traverse_copy_List_String (List_String me, void *y)
{
  if (!me) return NULL;
  return Create_List_String (fe_strdup (List_String_data(me)),
                             _Traverse_copy_List_String (List_String_next(me),y));
}

Bool
Traverse_compare_List_Int (List_Int x, List_Int y, void *z)
{
  int comp;
  Int i;
  Int j;

  if ( x == NULL || y == NULL )
    return x == y;

  i = List_Int_data(x);
  j = List_Int_data(y);

  if (0!=(comp =Traverse_compare_Int(i,j,z))) return comp;
  return Traverse_compare_List_Int(List_Int_next(x),List_Int_next(y),z);
}

Bool
Traverse_compare_List_Char (List_Char x, List_Char y, void *z)
{
  int comp;
  Char i;
  Char j;

  if ( x == NULL || y == NULL )
    return x == y;

  i = List_Char_data(x);
  j = List_Char_data(y);

  if (0!=(comp =Traverse_compare_Char(i,j,z))) return comp;
  return Traverse_compare_List_Char(List_Char_next(x),List_Char_next(y),z);
}

Bool
Traverse_compare_List_Bool (List_Bool x, List_Bool y, void *z)
{
  int comp;
  Bool i;
  Bool j;

  if ( x == NULL || y == NULL )
    return x == y;

  i = List_Bool_data(x);
  j = List_Bool_data(y);

  if (0!=(comp =Traverse_compare_Bool(i,j,z))) return comp;
  return Traverse_compare_List_Bool(List_Bool_next(x),List_Bool_next(y),z);
}

Bool
Traverse_compare_List_Ident (List_Ident x, List_Ident y, void *z)
{
  int comp;
  Ident i;
  Ident j;

  if ( x == NULL || y == NULL )
    return x == y;

  i = List_Ident_data(x);
  j = List_Ident_data(y);

  if (0!=(comp =Traverse_compare_Ident(i,j,z))) return comp;
  return Traverse_compare_List_Ident(List_Ident_next(x),List_Ident_next(y),z);
}

Bool
Traverse_compare_List_String (List_String x, List_String y, void *z)
{
  int comp;
  String i;
  String j;

  if ( x == NULL || y == NULL )
    return x == y;

  i = List_String_data(x);
  j = List_String_data(y);

  if (0!=(comp =Traverse_compare_String(i,j,z))) return comp;
  return Traverse_compare_List_String(List_String_next(x),List_String_next(y),z);
}

Bool
Traverse_compare_Ident (Ident x, Ident y, void *z)
{
  NOT_USED(z);
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;
}

Bool
Traverse_compare_Char (Char x, Char y, void *z)
{
  NOT_USED(z);
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;
}

Bool
Traverse_compare_String (String x, String y, void *z)
{
  NOT_USED(z);
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;
}

Bool
Traverse_compare_Int (Int x, Int y, void *z)
{
  NOT_USED(z);
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;
}

Bool
Traverse_compare_Bool (Bool x, Bool y, void *z)
{
  NOT_USED(z);
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;
}

Bool
Traverse_compare_Float (Float x, Float y, void *z)
{
  NOT_USED(z);
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;
}

String
Ident_qstring (Ident id)
{
  String s = Ident_name (id);
  Int l = strlen(s)+3;

  s = malloc (l);
  sprintf (s, "\"%s\"", Ident_name (id));
  s[l-1] = 0;
  return s;
}

void *
Return_Node (void *me)
{
  return me;
}

void *
Return_NULL (void *me)
{
  NOT_USED (me);
  return NULL;
}
