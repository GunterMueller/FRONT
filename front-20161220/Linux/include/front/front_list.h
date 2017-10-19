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

/* Module defining generic lists for Front */

#ifndef _front_list
#define _front_list

typedef struct s_Front_List  *Front_List; 
typedef struct s_List_Ident  *List_Ident;
typedef struct s_List_Int    *List_Int;
typedef struct s_List_Bool   *List_Bool;
typedef struct s_List_String *List_String;
typedef struct s_List_Char   *List_Char;
typedef struct s_List_Bind   *List_Bind;

typedef struct s_Front_Optional  *Front_Optional;
typedef struct s_Optional_Int    *Optional_Int;
typedef struct s_Optional_Bool   *Optional_Bool;
typedef struct s_Optional_Char   *Optional_Char;
typedef struct s_Optional_Float  *Optional_Float;

#include "basic_types.h"
#include "hash.h"
#include "SymTab.h"

/* Generic list type.
   This type is specialized by instances created by Front.
*/

struct s_Front_List {
  Pointer data;
  struct s_Front_List* next;
};

#define Front_List_data(node) ((node)->data)
#define Front_List_next(node) ((node)->next)

/* Creation function */
Front_List Create_Front_List (Pointer data, Front_List next);

/* Put the NULL terminated argument list in a Front_List */
Front_List vFront_Enlist (int number, va_list args);

/* Put the NULL terminated argument list in a Front_List */
Front_List Front_Enlist (int number, ...);

/* Free list L, not its elements */
void Front_List_free (Front_List l);

/* Duplicate the list, no side effects */
Front_List Front_List_dup (Front_List l);

/* Append the two lists, no side effects */
Front_List Front_List_concat (Front_List l, Front_List m); 

/* Append data at the end of l, no side effects */
Front_List Front_List_concat_node (Front_List l, Pointer data);

/* Insert between prev and cur */
void Front_List_insert (Front_List prev, Front_List cur, Pointer data);

/* Remove data from l */
void Front_List_remove_node (Pointer data, Front_List *l);

/* Insert in *l if not already present, side effect on l */
void Front_List_insert_node (Pointer data, Front_List *l);

/* Append the two lists, side effect on l */
void Front_List_append (Front_List *l, Front_List m); 

/* Append data at the end of l, side effect on l */
void Front_List_append_node (Front_List *l, Pointer data);

/* Return element of l containing data, NULL if not found */
Front_List Front_List_contains (Front_List l, Pointer data);

/* Split after A, removes the tail from A and returns it */
Front_List Front_List_split (Front_List a);

/* Length of a list */
Int List_size (Front_List l);

/* Last element of a list, NULL if list is empty */
Pointer List_last (Front_List l);

/* Element i of a list, NULL if list is empty */
Pointer List_elem (Front_List l, int i);

/* Reverse the elements in a list, makes a copy */
Front_List List_reverse (Front_List l);

/* Sort elements in c */
void Front_sort_list (Front_List c, int(*compare)(const Pointer*, const Pointer*));

/* Filter element in l */
void Front_List_filter (Front_List *l, Bool filter(Pointer, Front_List)) ;

/* Filter element in l, but filter function only takes the element as argument, not rest of list */
void Front_List_filter_simple (Front_List *l, Bool filter(Pointer)) ;

/* Filter duplicate elements out of l*/
void Front_List_filter_dups (Front_List *l);

/* intersection of A and B */
Front_List Front_List_intersect (Front_List a, Front_List b);


#define HEAD(l) Front_List_data(l)
#define TAIL(l) Front_List_next(l)

#define LIST_FORALL(var,list) \
  for (var = (Front_List)list; var != NULL; var = Front_List_next (var))

#define LIST_TRAVERSE(var) \
  for (; var != NULL; var = Front_List_next (var))

#define FRONT_DUP(T,a)           (List_##T)Front_List_dup ((Front_List)a)

#define FRONT_CONCAT(T,a,b)      (List_##T)Front_List_concat ((Front_List)a, (Front_List)b)
#define FRONT_CONCAT_NODE(T,a,b) (List_##T)Front_List_concat_node ((Front_List)a, (Pointer)b)

#define FRONT_APPEND(a,b)        Front_List_append ((Front_List*)&a, (Front_List)b)
#define FRONT_APPEND_NODE(a,b)   Front_List_append_node ((Front_List*)&a, (Pointer)b)
#define FRONT_PREPEND_NODE(a,b)  (*(Front_List*)&(b) = Create_Front_List ((Pointer)a, (Front_List)(b)))

#define FRONT_INSERT_HERE(p,c,d) Front_List_insert((Front_List)p, (Front_List)c, (Pointer)d);
#define FRONT_INSERT(a,b)        Front_List_insert_node ((Pointer)a, (Front_List*)&b)
#define FRONT_CONTAINS(a,b)      Front_List_contains ((Front_List)a, (Pointer)b)
#define FRONT_REMOVE_NODE(a,b)   Front_List_remove_node ((Pointer)a, (Front_List*)&b)
#define FRONT_SPLIT(T,a)         ((List_##T)Front_List_split ((Front_List)a))

#define FRONT_REVERSE(T,a)       (List_##T)List_reverse((Front_List)a)
#define FRONT_FILTER(l,f)        Front_List_filter((Front_List*)&l,(void*)f)
#define FRONT_FILTER_SIMPLE(l,f) Front_List_filter_simple((Front_List*)&l,(void*)f)
#define FRONT_FILTER_DUPS(l)     Front_List_filter_dups((Front_List*)&l)
#define FRONT_INTERSECT(T,a,b)   (List_##T)Front_List_intersect((Front_List)a,(Front_List)b)

#define FRONT_INDEX(l,i)         List_elem ((Front_List)l,i)
#define FRONT_LAST(l)            List_last ((Front_List)l)

  
/***** Int lists ********/

struct s_List_Int
{ 
  Int      data;
  List_Int next;
};

#define List_Int_data(_p) ((*_p).data)
#define List_Int_next(_p) ((*_p).next)

#define Create_List_Int(x,l) (List_Int)Create_Front_List((Pointer)(x),(Front_List)(l))
#define List_Int_size(l) List_size((Front_List)(l))

#define List_Int_GET_Int(i,me)  	(i == 0 ? List_Int_data(me) : 0)  
#define List_Int_GET_List_Int(i,me)  	(i == 1 ? List_Int_next(me) : NULL)  

/***** Oct lists ********/

#define List_Oct List_Int
       
#define List_Oct_data(_p) ((*_p).data)
#define List_Oct_next(_p) ((*_p).next)

#define Create_List_Oct(x,l) (List_Oct)Create_Front_List((PoOcter)(x),(Front_List)(l))
#define List_Oct_size(l) List_size((Front_List)(l))

#define List_Oct_GET_Oct(i,me)  	(i == 0 ? List_Oct_data(me) : 0)  
#define List_Oct_GET_List_Oct(i,me)  	(i == 1 ? List_Oct_next(me) : NULL)  

/***** Hex lists ********/

#define List_Hex List_Int
       
#define List_Hex_data(_p) ((*_p).data)
#define List_Hex_next(_p) ((*_p).next)

#define Create_List_Hex(x,l) (List_Hex)Create_Front_List((PoHexer)(x),(Front_List)(l))
#define List_Hex_size(l) List_size((Front_List)(l))

#define List_Hex_GET_Hex(i,me)  	(i == 0 ? List_Hex_data(me) : 0)  
#define List_Hex_GET_List_Hex(i,me)  	(i == 1 ? List_Hex_next(me) : NULL)  

/***** Ident lists ********/

struct s_List_Ident
{ 
  Ident      data;
  List_Ident next;
};

#define List_Ident_data(_p) ((*_p).data)
#define List_Ident_next(_p) ((*_p).next)

#define Create_List_Ident(x,l) (List_Ident)Create_Front_List((Pointer)(x),(Front_List)(l))
#define List_Ident_size(l) List_size((Front_List)(l))

#define List_Ident_GET_Ident(i,me)  	(i == 0 ? List_Ident_data(me) : 0)  
#define List_Ident_GET_List_Ident(i,me)  	(i == 1 ? List_Ident_next(me) : NULL)  

/***** Bool lists ********/

struct s_List_Bool
{ 
  unsigned int data;
  List_Bool next;
};

#define List_Bool_data(_p) ((Bool)(*_p).data)
#define List_Bool_next(_p) ((*_p).next)

#define Create_List_Bool(x,l) (List_Bool)Create_Front_List((Pointer)(x),(Front_List)(l))
#define List_Bool_size(l) List_size((Front_List)(l))

#define List_Bool_GET_Bool(i,me)  	(i == 0 ? List_Bool_data(me) : 0)  
#define List_Bool_GET_List_Bool(i,me)  	(i == 1 ? List_Bool_next(me) : NULL)  

/***** String lists ********/

struct s_List_String
{ 
  String      data;
  List_String next;
};

#define List_String_data(_p) ((*_p).data)
#define List_String_next(_p) ((*_p).next)

#define Create_List_String(x,l) (List_String)Create_Front_List((Pointer)(x),(Front_List)(l))
#define List_String_size(l) List_size((Front_List)(l))

#define List_String_GET_String(i,me)  	(i == 0 ? List_String_data(me) : 0)  
#define List_String_GET_List_String(i,me)  	(i == 1 ? List_String_next(me) : NULL)  

String ConcatStrings(List_String s);

/***** Char lists ********/

struct s_List_Char
{ 
  int       data;
  List_Char next;
};

#define List_Char_data(_p) ((Char)(*_p).data)
#define List_Char_next(_p) ((*_p).next)

#define Create_List_Char(x,l) (List_Char)Create_Front_List((Pointer)(x),(Front_List)(l))
#define List_Char_size(l) List_size((Front_List)(l))

#define List_Char_GET_Char(i,me)  	(i == 0 ? List_Char_data(me) : 0)  
#define List_Char_GET_List_Char(i,me)  	(i == 1 ? List_Char_next(me) : NULL)  

/***** Bind lists ********/

struct s_List_Bind
{ 
  Bind      data;
  List_Bind next;
};

#define List_Bind_data(_p) ((*_p).data)
#define List_Bind_next(_p) ((*_p).next)

#define Create_List_Bind(x,l) (List_Bind)Create_Front_List((Pointer)(x),(Front_List)(l))
#define List_Bind_size(l) List_size((Front_List)(l))

#define List_Bind_GET_Bind(i,me)  	(i == 0 ? List_Bind_data(me) : 0)  
#define List_Bind_GET_List_Bind(i,me)  	(i == 1 ? List_Bind_next(me) : NULL)  

/***** Generic Optional ********/

struct s_Front_Optional
{ 
  Pointer data;
};

#define Front_Optional_data(_p) ((*_p).data)

Front_Optional Create_Front_Optional (Pointer data);

#define Front_Optional_GET(i,me)  	(i == 0 ? Front_Optional_data(me) : NULL)  

/***** Optional Int ********/

struct s_Optional_Int
{ 
  Int data;
};

#define Optional_Int_data(_p) ((*_p).data)

Optional_Int Create_Optional_Int (Int data);

#define Optional_Int_GET_Int(i,me)  	(i == 0 ? Optional_Int_data(me) : 0)  

/***** Optional Oct ********/

#define Optional_Oct Optional_Int

#define Optional_Oct_data(_p) ((*_p).data)

#define Create_Optional_Oct Create_Optional_Int

#define Optional_Oct_GET_Oct(i,me)  	(i == 0 ? Optional_Oct_data(me) : 0)  

/***** Optional Hex ********/

#define Optional_Hex Optional_Int

#define Optional_Hex_data(_p) ((*_p).data)

#define Create_Optional_Hex Create_Optional_Int

#define Optional_Hex_GET_Hex(i,me)  	(i == 0 ? Optional_Hex_data(me) : 0)  

/***** Optional Bool ********/

struct s_Optional_Bool
{ 
  Bool data;
};

#define Optional_Bool_data(_p) ((*_p).data)

Optional_Bool Create_Optional_Bool (Bool data);

#define Optional_Bool_GET_Bool(i,me)  	(i == 0 ? Optional_Bool_data(me) : 0)  

/***** Optional Char ********/

struct s_Optional_Char
{ 
  Char data;
};

#define Optional_Char_data(_p) ((*_p).data)

Optional_Char Create_Optional_Char (Char data);

#define Optional_Char_GET_Char(i,me)  	(i == 0 ? Optional_Char_data(me) : 0)  

/***** Optional Float ********/

struct s_Optional_Float
{ 
  Float data;
};

#define Optional_Float_data(_p) ((*_p).data)

Optional_Float Create_Optional_Float (Float data);

#define Optional_Float_GET_Float(i,me)  	(i == 0 ? Optional_Float_data(me) : 0)  

#endif /* _front_list */
