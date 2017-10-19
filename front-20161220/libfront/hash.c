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

/********************************************************************************/
/********* 			hash table				*********/
/********************************************************************************/

#include "hash.h"
#include "mem.h"
#include "text.h"
#include <string.h>

static int w[MAXKEY] =
{
	337, 179, 419 , 31,  1579, 101, 7 ,  89,   271,  607,  683, 47,   8111,
        563, 3,   1979, 83,  7547, 727, 5,   1381, 11,   1031, 17,  1319, 523,
        701, 59,  1097, 13,  2557, 761, 71,  307,  2621, 101,  197, 113,  547,
        2,   1201,19,   1213,23,   1217,29,  1223, 37,   1229, 41,  1231, 43,
        1237,49,  1249, 53,  1259, 57,  1277,59,   1279, 61,  1283,67,   1297,
        71,  73,  79,   89,  97,   103, 107, 109,  127,  131,  137, 139,  149
};

hash_t Front_identifier_table = NULL;

/*
	hash function 
*/
unsigned int Front_Hash_function(const char* s)
{
        int     i;
	int	n;
        
	i=0;
	n=0;
        while (i<MAXKEY  &&  s[i] != '\0')
        {
                n += w[i] * (unsigned char) s[i];
                i++;
        }
        return n;
}




/* 
	make hash table 
*/
hash_t Front_Make_hash_table(unsigned int (make_key)(hash_val), Bool (cmp_key)(hash_item, hash_val))
{
	hash_t	table;
        int     	i;

        table = FE_NEW (hash_t);
	table->make_key = make_key;
	table->cmp_key  = cmp_key;
	table->table = fe_malloc (HASHSIZE * sizeof (hash_elem_p));
	
	/* initialize hash table */
        for (i=0; i!=HASHSIZE; i++)
	{
		table->table[i]=NULL;
	}
	
	return table;
}

/*
	free memory of hash table 
*/
void Front_Free_hash_table(hash_t table)
{
        int     	i;
        hash_elem_t*	p;
	hash_elem_t*	p_next;

        for (i=0; i!=HASHSIZE; i++)
        {
		p = table->table[i];
		
		/* free all bugets in entry i of the table */
                while (p!=NULL)
                {
                        p_next = p->next;
                        fe_free(p);
			p = p_next;
                }
        }
        fe_free(table->table);
        fe_free(table);
}


/*
	add item in hash table 
*/
void Front_Add_in_hash_table(hash_t table, const hash_val name, hash_item item)
{
        hash_elem_t*	elem;
        unsigned int key = (table->make_key)(name) % HASHSIZE;

        elem = FE_NEW(hash_elem_p);

        elem->item = item;
        elem->next = table->table[key];
        table->table[key] = elem;
}

/*
	return item from hash table 
*/
hash_item Front_Find_in_hash_table(hash_t table, const hash_val name)
{
        unsigned int key = (table->make_key)(name) % HASHSIZE;
        hash_elem_t*	elem = table->table[key];

        while ((elem!=NULL) && (!(table->cmp_key)(elem->item, name)))
	{
		elem = elem->next;
	}
	
	return (elem==NULL ? NULL : elem->item);
}

/* apply f to each item in hash table */
void Front_Apply_to_hash_table(hash_t table, void (f)(hash_item))
{
	int i;
	hash_elem_t *l;
	
	for (i= 0; i < HASHSIZE; i++)
	{
		for (l = table->table[i]; l != NULL; l = l->next)
		{
			f (l->item);
		}
	}
}

/* apply f to each item in hash table and remove this if f yields true */
void Front_Apply_to_hash_table_and_remove(hash_t table, Bool (f)(hash_item))
{
	int i;
	hash_elem_t *l;
	hash_elem_t *n;
	hash_elem_t **p;
	
	for (i= 0; i < HASHSIZE; i++)
	{
		p = &table->table[i];
		for (l = *p; l != NULL; l = n)
		{
			/* l == *p */
			n = l->next;
			if (!f (l->item)) 
			{
			  	p = &l->next;
			 	continue;
			}
			fe_free (l);
			*p = n;
		}
	}
}


/* remove the item from the hash table */
void Front_Remove_from_hash_table(hash_t table, const hash_val name)
{
        unsigned int key = (table->make_key)(name) % HASHSIZE;
        hash_elem_t*	elem = table->table[key];
        hash_elem_t*	prev = NULL;

        while ((elem!=NULL) && (!(table->cmp_key)(elem->item, name)))
	{
		prev = elem;
		elem = elem->next;
	}
	
	if (elem==NULL) return;
	if (prev==NULL) {
		table->table[key] = elem->next;
	} else {
		prev->next = elem->next;
	}
	fe_free (elem);
}

Bool Front_cmp_identifier (identifier id, const char *val)
{
  return !strcmp (IDENT_NAME(id), val);
}

hash_t Front_New_identifier_table ()
{
  return Front_Make_hash_table ((void*)Front_Hash_function, (void*)Front_cmp_identifier);
}

void Front_Make_identifier_table ()
{
  if (Front_identifier_table != NULL) return;
  Front_identifier_table = Front_New_identifier_table ();
}

identifier Front_New_identifier (hash_t t, const char *s)
{ identifier id;

  id = Front_Find_in_hash_table(t, (hash_val)s);
  if (id == NULL) {
    id = FE_NEW (identifier);
    _IDENT_STRING(id) = fe_strdup(s);
    _IDENT_INFO(id)   = NULL;
    Front_Add_in_hash_table (t, (hash_val)s, id);
  }
  return id;
}

identifier Front_Make_identifier (const char *s)
{
  return Front_New_identifier (Front_identifier_table, s);
}

identifier Front_Find_identifier (const char *s)
{ 
  return Front_Find_in_hash_table(Front_identifier_table, (hash_val)s);
}

static void free_identifier (identifier id)
{
  fe_free(IDENT_NAME(id));
  fe_free(id);
}

void Front_Free_this_identifier_table (hash_t t)
{
  Front_Apply_to_hash_table (t, (void*)free_identifier);
  Front_Free_hash_table (t);
}

void Front_Free_identifier_table ()
{
  Front_Free_this_identifier_table (Front_identifier_table);
  Front_identifier_table = NULL;
}
