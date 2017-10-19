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
#include <assert.h>
#include "basic_types.h"
#include "SymTab.h"
#include "support.h"

typedef List_Bind *NameSpaces;

int num_name_spaces = 0;
static int delta_name_spaces;
static int current_generation = 0;
static int subject_threshold;
static int subject_namespace;
static int global_scope_end = 0;

typedef struct s_Scope {
  struct s_Scope *next;
  int _num;
  int _end;
} *Scope ;

static List_Bind remove_bind (List_Bind l, Bind b);


/* ----------------------------------------------------------------------------
 *  SCOPE
 * ------------------------------------------------------------------------- */

static Bool
sub_scope (Scope s1, Scope s2)
{
  while (s1 != s2) {
    if (s1 == NULL) return FALSE;
    s1 = s1->next;
  }
  return TRUE;
}

Bool
Sub_scope (void *s1, void *s2)
{
  return s2==NULL || s1==s2 || sub_scope(s1,s2);
}

static int
scope_num(Scope s)
{
  if (s) return s->_num;
  return 0;
}

int
Scope_Num_Stores(void *p)
{
  Scope s = p;
  if (s) return s->_end;
  return global_scope_end;
}

static int
grow_scope(Scope s)
{
  if (s) return s->_end++;
  return global_scope_end++;
}


/* ----------------------------------------------------------------------------
 *  GENERATION
 * ------------------------------------------------------------------------- */

void
SymTab_Bump_Generation(void)
{
  current_generation++;
}

int
SymTab_Generation(void)
{
  return current_generation;
}

/* ----------------------------------------------------------------------------
 *  NAMESPACE
 * ------------------------------------------------------------------------- */

static NameSpaces
alloc_name_spaces (Ident id, int n)
{
  NameSpaces ns = calloc (n, sizeof (Bind));
  _IDENT_INFO(id) = ns;
  return ns;
}

static NameSpaces
get_name_spaces (Ident id)
{
  if (!IDENT_INFO(id)) {
    alloc_name_spaces (id, num_name_spaces);
  }
  return IDENT_INFO(id);
}

static void
grow_name_spaces  (hash_item h)
{
  Ident id = h;
  NameSpaces ns1 = IDENT_INFO(id);
  if (ns1==NULL) return;
  alloc_name_spaces (id, num_name_spaces+delta_name_spaces);
  memcpy (IDENT_INFO(id), ns1, sizeof (Bind) * num_name_spaces);
}

void
Init_symboltable (int num_nspaces)
{
  if(num_nspaces<=num_name_spaces) return;
  num_name_spaces = num_nspaces;
}

void
Extend_namespaces (int num_nspaces, int *name_spaces)
{
  int i;
  delta_name_spaces = num_nspaces;
  for (i=0; i < num_nspaces; i++) name_spaces[i] = num_name_spaces+i;
  if (Front_identifier_table == NULL) Front_Make_identifier_table();
  Front_Apply_to_hash_table (Front_identifier_table, grow_name_spaces);
  num_name_spaces += num_nspaces;
}

static void
clean_namespace (Ident id)
{
  List_Bind bs;
  NameSpaces ns = IDENT_INFO(id);

  if (!ns) return;
  for (bs = ns[subject_namespace]; bs; bs = List_Bind_next (bs)) {
    Bind b = List_Bind_data (bs);
    if (subject_threshold <= Bind_generation (b) &&
        Bind_generation (b) < current_generation) {
      ns[subject_namespace] = remove_bind (ns[subject_namespace], b);
    }
  }
}

void
Clean_namespace (int nspace, int threshold)
{
  subject_namespace = nspace;
  subject_threshold = threshold;
  
  Front_Apply_to_hash_table (Front_identifier_table, (void*)clean_namespace);
  
}

void
Clean_namespaces (int begin, int num, int threshold)
{
  int i;
  
  for (i=0; i<num; i++) {
    Clean_namespace (begin+i, threshold);
  }
}

/* ----------------------------------------------------------------------------
 *  BINDING
 * ------------------------------------------------------------------------- */

static Bind
create_bind (identifier id, void *scope, int loc, int tag, void *object, int forward)
{
  Bind b = malloc (sizeof(*b));
  
  Bind_scope(b)  = scope;
  Bind_generation(b) = current_generation;
  Bind_loc(b)    = loc;
  Bind_id(b)     = id;
  Bind_tag(b)    = tag;
  Bind_object(b) = object;
  Bind_double(b) = FALSE;
  Bind_error(b)  = FALSE;
  Bind_forward(b) = forward;
  Bind_singleton(b) = Create_List_Bind (b, NULL);
  return b;
}

static Bind
find_object (void *object, List_Bind l)
{
  for (; l; l = List_Bind_next(l)) {
    Bind b1 = List_Bind_data(l);
    if (Bind_object(b1) == object) return b1;
  }
  return NULL;
}

static List_Bind
insert_bind (Bind *b, List_Bind l, Bool redef, Bool overload)
{
  Bind b1;
  
  if (l == NULL || overload) return Create_List_Bind (*b, l);
  b1 = List_Bind_data(l);
  if (Bind_scope(*b) == Bind_scope(b1)) {
    if (redef) { 
      *b = b1; /* Allow redefinition */
    } else {
      Bind_double(*b) = TRUE; /* Already declared */
    }
  } else {
    List_Bind_next(l) = insert_bind (b, List_Bind_next(l), redef, FALSE);
  }
  return l;
}

static List_Bind
remove_bind (List_Bind l, Bind b)
{
  if (l==NULL) return NULL;
  if (List_Bind_data(l) == b) return List_Bind_next(l);
  List_Bind_next(l) = remove_bind (List_Bind_next(l), b);
  return l;
}

static Bind
update_bind(Bind b, void *scope, int loc, void *object)
{
  Bind_generation (b) = current_generation;
  Bind_object (b) = object;
  Bind_scope(b) = scope;
  Bind_loc(b) = loc;
  return b;
}

static Bool
is_better_bind (Bind def, Bind old, Scope s, int num)
{
  /* old => old.scope >= def.scope */
  assert (s == Bind_scope(def));
  
  if (!Bind_forward(def)) return TRUE;
  if (num <= Bind_loc(def)) return FALSE;
  if (!old) return TRUE;
  if (Bind_scope(def) != Bind_scope(old)) return TRUE;
  return Bind_loc(old) < Bind_loc(def);
}

static Bool
is_better_def(Bind def, Bind old, Scope scope, int loc)
{
  int num = loc;
  Scope s = scope;
  
  if (s == Bind_scope(def)) {
    return is_better_bind (def, old, s, num);
  }
  while(s && (!old || Bind_scope(old)!=s)) {
    num = scope_num(s);
    s = s->next;
    if (s == Bind_scope(def)) {
      return is_better_bind (def, old, s, num);
    }
  }
  return FALSE;
}

static Bool
is_possible_def(Bind def, Scope scope, int loc)
{
  return is_better_def (def, NULL, scope, loc);
}


Bind
StoreBind (identifier id, void *scope, int tag, void *object, int nspace,
           Bool overload, Bool redef, Bool forward)
{
  int loc;
  NameSpaces ns;
  Bind b;

  assert (nspace < num_name_spaces);
  loc = grow_scope(scope);
  if (!id) return create_bind (id, scope, loc, tag, NULL, forward);
  
  ns = get_name_spaces (id);

  /* find (ID,OBJECT) in any scope */
  b = find_object (object, ns[nspace]);
  if (b) return update_bind (b, scope, loc, object);
  b = create_bind (id, scope, loc, tag, object, forward);
  ns[nspace] = insert_bind (&b, ns[nspace], redef, overload);
  return b;
}

Bind
ReplaceBind (Bind b, identifier id, void *scope, int tag, void *object,
             int nspace, Bool overload, Bool redef, Bool forward)
{
  if (b) Remove_Bind (b, nspace);
  return StoreBind (id, scope, tag, object, nspace, overload, redef, forward);
}

List_Bind
StoreBindList (List_Ident l, void *scope, int tag, void *object, int nspace,
               Bool overload, Bool redef, Bool forward)
{
  List_Ident m;
  List_Bind b = NULL;
  
  for (m = l; m; m = List_Ident_next(m)) {
    Bind b1 = StoreBind (List_Ident_data(m), scope, tag, object, nspace,
                         overload, redef, forward);
    FRONT_APPEND_NODE (b, b1);
  }
  return b;
}

List_Bind
ReplaceBindList (List_Bind bs, List_Ident l, void *scope, int tag, void *object,
                 int nspace, Bool overload, Bool redef, Bool forward)
{
  List_Ident m;

  while(bs) {
    Remove_Bind(HEAD(bs), nspace);
    bs = TAIL(bs);
  }
  for (m = l; m; m = List_Ident_next(m)) {
    Bind b = StoreBind (List_Ident_data(m), scope, tag,
                        object, nspace, overload, redef, forward);
    if (!bs) {
      FRONT_APPEND_NODE (bs, b);
    } else {
      HEAD (bs) = b;
      bs = TAIL (bs);
    }
  }
  return bs;
}


Bind
RetrieveBind (identifier id, void *scope, int loc, int nspace, int tag)
{
  NameSpaces ns = IDENT_INFO(id);
  List_Bind l;
  Bind b = NULL;

  if (!ns) return NULL;
  
  for (l = ns[nspace]; l != NULL; l = List_Bind_next(l)) {
    Bind b1 = List_Bind_data(l);
    if (Bind_tag (b1) != tag) continue;
    if (!is_better_def (b1, b, scope, loc)) continue;
    b = b1;
  }
  return b;
}

List_Bind
RetrieveListBind (identifier id, void *scope, int loc, int nspace, int tag)
{
  NameSpaces ns = IDENT_INFO(id);
  List_Bind l = NULL;
  List_Bind b = NULL;
  List_Bind m = NULL;
  Bind bind = NULL;
  Int in_scope = 0;
  Bool all_in_scope = TRUE;
  
  if (ns != NULL) m = ns[nspace];
  
  bind = NULL;
  for (l = m; l != NULL; l = List_Bind_next(l)) {
    if (Bind_tag (List_Bind_data(l)) == tag &&
        is_possible_def(List_Bind_data(l), scope, loc)) {
      in_scope++;
      bind = List_Bind_data(l);
    } else {
      all_in_scope = FALSE;
    }
  }
  
  if (all_in_scope) return m; /* All in scope */
  if (in_scope==1) return Bind_singleton(bind); /* Just one in scope */
  
  for (l = m; l != NULL; l = List_Bind_next(l)) {
    if (Bind_tag (List_Bind_data(l)) != tag) continue;
    if (!is_possible_def (List_Bind_data(l), scope, loc)) continue;

    b = Create_List_Bind (List_Bind_data(l), b);
  }
  return b;
}


Bool
List_Bind_double (List_Bind l)
{
  for (; l; l = List_Bind_next(l)) {
    if (Bind_double (List_Bind_data(l))) return TRUE;
  }
  return FALSE;
}

void
Remove_Bind (Bind b, int nspace)
{
  NameSpaces ns;
  
  if (b==NULL) return;
  
  ns = IDENT_INFO(Bind_id(b));
  
  if (ns == NULL) return;
  
  ns[nspace] = remove_bind (ns[nspace], b);
}

/* ----------------------------------------------------------------------------
 *  CONVERSIONS
 * ------------------------------------------------------------------------- */
Ident
Int_to_Ident (Int x)
{
  char s[128];
  sprintf (s, "%d", x);
  return Make_identifier (s);
}

Ident
Bool_to_Ident (Bool x)
{
  if (x) return Make_identifier ("TRUE");
  else return Make_identifier ("FALSE");
}

Ident
String_to_Ident (String x)
{
  return Make_identifier (x);
}

Ident
Char_to_Ident (char x)
{
  char s[2];
  s[0] = x; s[1] = 0;
  return Make_identifier (s);
}

List_Ident
List_Int_to_List_Ident (List_Int x)
{
  if (x == NULL) return NULL;
  return Create_List_Ident (Int_to_Ident(List_Int_data(x)),
                            List_Int_to_List_Ident (List_Int_next(x)));
}

List_Ident
List_Bool_to_List_Ident (List_Bool x)
{
  if (x == NULL) return NULL;
  return Create_List_Ident (Bool_to_Ident(List_Bool_data(x)),
                            List_Bool_to_List_Ident (List_Bool_next(x)));
}

List_Ident
List_String_to_List_Ident (List_String x)
{
  if (x == NULL) return NULL;
  return Create_List_Ident (String_to_Ident(List_String_data(x)),
                            List_String_to_List_Ident (List_String_next(x)));
}

List_Ident
List_Char_to_List_Ident (List_Char x)
{
  if (x == NULL) return NULL;
  return Create_List_Ident (Char_to_Ident(List_Char_data(x)),
                            List_Char_to_List_Ident (List_Char_next(x)));
}


