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
#include <limits.h>
#include <string.h>
#include "parse_support.h"

//static void print_stack (int n);

static ParseValue AllParseValues = NULL;
static ParseValue FreeParseValues = NULL;
ParseValue temp_parse_value = NULL;

static int first_line = 0;

static ParseValue alloc_ParseValue (void)
{ ParseValue p = FreeParseValues;
  if (p == NULL) {
    p = malloc (sizeof (*p));
    p->next = NULL;
    p->first_line = 0;
  }
  FreeParseValues = p->next;
  return p;
}

ParseValue PushParseValue (String type)
{ ParseValue p = alloc_ParseValue();
  p->first_line = first_line;
  p->type = type;
  p->next = AllParseValues;
  AllParseValues = p;
  return p;
}

static struct ParseValue dummy_parse_value;

ParseValue PopParseValue (String type)
{
  NOT_USED(type);
  ParseValue p = AllParseValues;
  if (AllParseValues==NULL) return &dummy_parse_value;
  first_line = p->first_line;
  AllParseValues = p->next;
  return p;
}

void FreeParseValue (ParseValue p)
{ if (p == &dummy_parse_value) return;
  p->next = FreeParseValues;
  FreeParseValues = p;
}

Int GetFirstLine (void)
{
  NOT_USED(temp_parse_value);
  return first_line;
}

static void _print_stack (int n, ParseValue s)
{
  if (n==0) return;
  if (s == NULL) return;
  _print_stack (n-1, s->next);
  printf ("%s ", s->type); 
}

void
print_stack (int n)
{
  _print_stack (n, AllParseValues);
  printf ("\n");
}

/**************/

void unite_symbol_sets (SymbolSet x, SymbolSet a, SymbolSet b, Int n)
{
  int i;
  for (i = 0; i < n; i++) x[i] = a[i] | b[i];
}

Bool contains_symbol (SymbolSet a, Int sym, Int n)
{
  NOT_USED (n);
  int set = sym / BITSPERWORD;
  int i = sym-set*BITSPERWORD;
  return (a[set] & (1<<i)) != 0;
}

/**************/

Front_List first_sub_tree = NULL;
static Front_List *last_sub_tree = &first_sub_tree;

static void Put_sub_tree (void *t)
{
  *last_sub_tree = Create_Front_List (t, *last_sub_tree);
  last_sub_tree = &Front_List_next(*last_sub_tree);
}

void Put_sub_trees (int n, va_list p)
{ int i;
  for (i = 0; i < n; i++) Put_sub_tree (va_arg (p, void*));
  set_first_line (INT_MIN);
}

void* Get_sub_tree (void)
{ Front_List t = first_sub_tree;
  void *r;
  assert (t != NULL);
  first_sub_tree = Front_List_next(t);
  if (first_sub_tree == NULL) last_sub_tree = &first_sub_tree;
  r = Front_List_data(t);
  free (t);
  return r;
}


