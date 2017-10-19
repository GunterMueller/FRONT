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

#ifndef __HASH_H__
#define __HASH_H__

#include <stdlib.h>

typedef void *hash_val;
typedef void *hash_item;
typedef struct hash_s hash_s;
typedef struct hash_elem_s  hash_elem_t;
typedef struct hash_elem_s *hash_elem_p;
typedef hash_s *hash_t;
typedef struct identifier_s identifier_t;
typedef identifier_t *identifier;
typedef identifier Ident;

#include "support.h"

/********************************************************************************/
/********* 			hash table				*********/
/********************************************************************************/

#define HASHSIZE        10003		/* size of hash table			*/
#define MAXKEY	        78		/* max size hash key			*/

/********************************************************************************/
/********* 			data structures				*********/
/********************************************************************************/

/* hash table, comtains a function to construct a key and one to compare keys */
struct hash_s
{	unsigned int (*make_key)(hash_val);
	Bool (*cmp_key)(hash_item, hash_val);
	hash_elem_p* 	table;
};

/* List of hashed items in a bucket */
struct hash_elem_s
{
        hash_item	item;		/* item in table			*/
        hash_elem_p	next;		/* next hash table element		*/
};

/* Identifiers are hashed strings */
struct identifier_s
{
	char		*name;
	void		*info;
};

extern hash_t Front_identifier_table;

#define _IDENT_STRING(id)	((id)->name)
#define _IDENT_INFO(id)		((id)->info)
#define IDENT_STRING(id)	((id) ? (id)->name : "")
#define IDENT_INFO(id)		((id) ? (id)->info : NULL)
#define IDENT_NAME(id)		(0+IDENT_STRING(id))

/********************************************************************************/
/********* 			functions				*********/
/********************************************************************************/

/* Make hash table */
hash_t Front_Make_hash_table(unsigned int (make_key)(hash_val), 
                             Bool (cmp_key)(hash_item, hash_val));

/* Default key construction for the string type */
unsigned int Front_Hash_function(const char* s);

/* free memory of hash table */
void Front_Free_hash_table(hash_t table);

/* add item in hash table */
void Front_Add_in_hash_table(hash_t table, hash_val name, hash_item item);

/* return item from hash table */
hash_item Front_Find_in_hash_table(hash_t table, const hash_val name);

/* apply f to each item in hash table */
void Front_Apply_to_hash_table(hash_t table, void (f)(hash_item));

/* apply f to each item in hash table and remove this if f yields true */
void Front_Apply_to_hash_table_and_remove(hash_t table, Bool (f)(hash_item));

/* remove the item from the hash table */
void Front_Remove_from_hash_table(hash_t table, const hash_val name);

/* Make/free a identifier table */
hash_t Front_New_identifier_table (void);
void Front_Free_this_identifier_table (hash_t t);

/* Make/free the identifier table */
void Front_Make_identifier_table (void);
void Front_Free_identifier_table (void);

/* Identifier comparison */
Bool Front_cmp_identifier (identifier id, const char *val);

/* Make an identifier (hashed string) for string s */
identifier Front_New_identifier (hash_t t, const char *s);
identifier Front_Make_identifier (const char *s);

/* Find an idenfier in the table */
identifier Front_Find_identifier (const char *s);

#define Make_identifier_table Front_Make_identifier_table
#define Make_identifier Front_Make_identifier
#define Find_identifier Front_Find_identifier
#define Free_identifier_table Front_Free_identifier_table

#endif
