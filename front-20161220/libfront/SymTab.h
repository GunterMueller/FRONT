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

#ifndef _SymTab
#define _SymTab

typedef struct s_Bind *Bind;

#include "support.h"
#include "hash.h"
#include "basic_types.h"
#include "front_list.h"

/* Bindings, i.e. the things that are stored in the symbol table.
   A binding combines an Ident, a scope, an AST object and a tag.
   A symbol table contains a set of bindings per name-space.
*/

struct s_Bind {
  void 		*scope;
  int           generation;
  int           loc;
  Ident		id;
  void 		*object;
  int		tag : 16;
  int 		duble : 8;
  int 		error : 7;
  int           forward : 1;
  List_Bind     singleton;
};

#define Bind_scope(b)	   ((b)->scope)
#define Bind_generation(b) ((b)->generation)
#define Bind_loc(b)	   ((b)->loc)
#define Bind_id(b)	   ((b)->id)
#define Bind_tag(b)	   ((b)->tag)
#define Bind_object(b)	   ((b)->object)
#define Bind_double(b)	   ((b)->duble)
#define Bind_error(b)	   ((b)->error)
#define Bind_forward(b)	   ((b)->forward)
#define Bind_singleton(b)  ((b)->singleton)

/***********/

/* Initialize the symbol table with num_nspaces name-spaces */
void Init_symboltable (int num_nspaces)
#ifdef __GNUC__
     __attribute__ ((deprecated))
     /* Please use Extend_namespaces instead, eg:
          Init_symboltable (cfront_NUM_NAMESPACES);
        becomes:
          Extend_namespaces (cfront_NUM_NAMESPACES,
                             cfront_namespaces);
     */     
#endif
     ;

/* Extend the symbol table with num_nspaces name-spaces */
void Extend_namespaces (int num_nspaces, int *name_spaces);

/* Start a new generation */
void SymTab_Bump_Generation(void);

/* Get the current generation */
int SymTab_Generation(void);

/* Remove bindings from older generations, binding older than MINIMUM are kept */
void Clean_namespace (int nspace, int minimum);
void Clean_namespaces (int begin, int num, int minimum);

/* Check whether s1 is a sub-scope of s2 */
Bool Sub_scope (void *s1, void *s2);

int Scope_Num_Stores(void *s);

/* Create a new binding and store it in the symbol-tabel for namespace ns. 
   overload indicates that overloading is allowed, i.e. the symbol-table
     will hold more than one entry for the same identifier/namespace/scope 
    combination.
   redef indicates whether an existing binding for the same identifier/namespace/scope 
     can be replaced by the new one.
*/
Bind StoreBind (Ident id, void *scope, int tag, void *object, int ns,
                       Bool overload, Bool redef, Bool forward);

/* Does a Store_Bind for each identifier in the list */
List_Bind StoreBindList (List_Ident id, void *scope, int tag, void *object, int ns,
                                Bool overload, Bool redef, Bool forward);

/* Replace bind B */
Bind ReplaceBind (Bind b, identifier id, void *scope, int tag, void *object, int nspace,
                  Bool overload, Bool redef, Bool forward);

List_Bind ReplaceBindList (List_Bind bs, List_Ident l, void *scope, int tag,
                           void *object, int nspace, Bool overload, Bool redef, Bool forward);

/* Retrieve a binding for a Ident/scope/namespace/tag combination.
   This will return the binding for the deepest scope.
*/
Bind RetrieveBind (Ident id, void *scope, int loc, int ns, int tag);

/* Retrieve all bindings for a Ident/scope/namespace/tag combination.
   Used in combination with overloading.
*/
List_Bind RetrieveListBind (Ident id, void *scope, int loc, int ns, int tag);

/* Remove a binding from the symboltable */
void Remove_Bind (Bind b, int nspace);

/* Check for doubcle declarations in l */
Bool List_Bind_double (List_Bind l);

/* Some conversions to use integers, etc. rather than Ident's as a symboltable key */ 
Ident Int_to_Ident (Int x);
Ident Bool_to_Ident (Bool x);
Ident String_to_Ident (String x);
Ident Char_to_Ident (char x);
#define Hex_to_Ident(x) Int_to_Ident(x)
#define Oct_to_Ident(x) Int_to_Ident(x)

List_Ident List_Int_to_List_Ident (List_Int x);
List_Ident List_Bool_to_List_Ident (List_Bool x);
List_Ident List_String_to_List_Ident (List_String x);
List_Ident List_Char_to_List_Ident (List_Char x);
#define List_Hex_to_Ident(x) List_Int_to_List_Ident(x)
#define List_Oct_to_Ident(x) List_Int_to_List_Ident(x)

/* Ye Olde functions (before 26-11-2003) */
#define Create_Bind(scope,id,tag,object)  \
                    CreateBind ((scope),0,(tag),(object))
#define Store_Bind(id,scope,tag,object,ns,overload,redef) \
                    StoreBind((id),(scope),(tag),(object),(ns),(overload),(redef),FALSE)
#define Store_Bind_List(id,scope,tag,object,ns,overload,redef) \
                    StoreBindList ((id), (scope), (tag), (object), (ns), (overload), (redef), FALSE)
#define Retrieve_Bind(id,scope,ns,tag) \
                    RetrieveBind((id),(scope),0,(ns),(tag))
#define Retrieve_List_Bind(id,scope,ns,tag) \
                    RetrieveListBind((id),(scope),0,(ns),(tag))

#endif /* _SymTab */
