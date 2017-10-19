/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 */
#ifndef _GENTYPES_H
#define _GENTYPES_H

#include "front.h"
#include "Types.h"
#include <stdarg.h>

extern NonTerminal Rootsym;	/* Root of the grammar */
extern Ident Rootid;		/* Name of the root of the grammar */
extern String Rootstr;		/* Name of the root of the grammar */

/* prints to print_file */
extern void PF(char *, ...);

/* open file as the abbreviation file */
void open_abbrev(char *file);

/* close the abbreviation file */
void close_abbrev(void);

/* prints to the abbreviation file */
extern void Abbrev(char *, ...);

/* return pre_prefix_s_post, and generate an abbreviation in the abbreviation file */
extern String vabbreviatef(String pre, String s, String post, va_list args);

/* return pre_prefix_s_post, and generate an abbreviation in the abbreviation file */
extern String abbreviatef(String pre, String s, String post, ...);

/* return pre_full_post, and generate an abbreviation pre_abbrev_post = pre_full_post */
extern String def_abbrevf(String pre, String abbrev, String full, String post, ...);

/* return pre_full_post, and generate an abbreviation pre_abbrev_post = pre_full_post */
extern String vdef_abbrevf(String pre, String abbrev, String full, String post, va_list args);

/* return prefix_s, and generate an abbreviation in the abbreviation file */
extern String abbreviate(String s);

/* return pre_prefix_id_post, and generate an abbreviation in the abbreviation file */
Ident abbreviate_id(String pre, Ident id, String post);

/* return prefix_s */
extern String prefix_string (String s);

/* prints #include <f.h> */
extern void print_std_include (String f);

/* prints #include "f.h" */
extern void print_include (String f);

/* get the initialization in F for WHEN */
FieldInit field_init_when(field  f, FieldInit_tag when);

/* get the initialization string in F for WHEN */
char *field_expr_when(field  f, FieldInit_tag when);

/* Get the type of a field */
TypeName get_field_type (field f);

/* Print the typename of the (sub-)type that contains field f */
extern void print_field_type (field f, struct_type t);

/* Create a TypeName with specified non-prefixed and prefixed name */
extern TypeName make_TypeName(Ident id, Ident full);

/* Check whether t contains a field with name f */
extern Bool contains_field (struct_type t, Ident f);

/* Print an access to field , i.e. t_f(v) */
extern void field_access (struct_type t, field f, String v);

/* Remove string-quotes front s */
extern String remove_quotes (String s);

/* Insert / find an identifier in a list */
extern void insert_id (List_Ident *l, Ident id);
extern Bool contains_id (List_Ident l, Ident id);

/* Prefix the name of t */
extern void set_name     (struct_type t);

/* Prefix the name of e */
extern void enum_set_name (EnumType e);

/* Prefix the name of of a type with name id */
extern Ident prefix_type (Ident id);

/* Tests for scope actions within t */
extern Bool opens_scope  (struct_type t);
extern Bool closes_scope (struct_type t);
extern Bool uses_scope   (struct_type t);

/* Test for t being a memo type */

/* Concatenate l into one type name */
extern TypeName glue_type_name (List_TypeName l);

/* Concatenate l into one identifier */
extern Ident glue_type (List_TypeName l);

/* Concatenate l into one prefixed identifier */
extern Ident full_glue_type (List_TypeName l);

/* remove redundant optional types */
extern void remove_optional (field f);

/* Change the name of f into its root-type */
extern void set_root_type (TypeName f);

/* Fill in the TypeName_type for the head of l */
extern void set_type_struct (List_TypeName l);

/* Find types for identifiers */
extern struct_type find_type (Ident id);
extern EnumType find_enumtype (Ident id);
extern subtypedef find_subtype (Ident id);

/* Find a (sub-type) with field of name id */
extern struct_type find_field_type (struct_type t, Ident id);

/* Tests on types */
extern Bool TermType (Ident id);
extern Bool ListOfTermType (Ident id);
extern Bool OptionalTermType (Ident id);
extern Bool Std_type (Ident id);
extern Bool Allows_nil (TypeName t);
extern Bool is_memo (struct_type t);
extern Bool is_skip (struct_type t);
extern Bool enum_is_bool (EnumType t);
extern Bool enum_is_int (EnumType t);

/* Find the enum value of a in type r, a is an UnLabeledAlt. */
extern Bool enum_val (struct_type r, Alternative a, Int *i);

/* String concatenation */
extern String append_string (String a, String b);

/* Print e to a string */
extern String expr_to_string (Expr e);

/* Names of types */
extern String Type_name  (struct_type t);  /* Original name */
extern String Type_str   (struct_type t);  /* Prefixed name */
extern Ident  Type_ident (struct_type t);  /* Prefixed name */

/* Name for binding of defining field */
extern Ident bind_id (field f);

/* The root type of type */
extern struct_type Root_type (struct_type t);

/* The super type of type */
extern struct_type Super_type (struct_type t);

/* Check for list type */
extern Bool is_list (TypeName t);

extern Bool is_list_field (field f);

/* Check for non-terminal type */
extern Bool IsNonTerm(struct_type t);

/* Compute the Types data structure for grammar f */
extern Types GenTypes (front f, List_struct_type *all_str_types);

#endif /* _GENTYPES_H */
