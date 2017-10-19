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

/* Module for (pretty)printing Front AST's.
   Can print to file/string.
   Can maintain comment or not.
   Can also print in html format.
*/

#ifndef _print_support
#define _print_support

#ifndef _ELEGANT
#include "support.h"
#include "scan_support.h"
#else
#include "StandardTypes.h"
#define Int    StandardTypes_Int
#define Char   StandardTypes_Char
#define String StandardTypes_String
#define Float  StandardTypes_Float
#define Ident  StandardTypes_Ident
#define Bool   StandardTypes_Bool
#include "ScanIO.h"
#define print_support_Front_pretty Front_pretty
#define print_support_Print_html Print_html
#define print_support_eval_comments eval_comments
#endif

extern Bool Front_pretty;	/* Pretty printing or not */
extern FILE *print_file;	/* File for print output */
extern char *print_string;	/* String for print output */
extern Bool Source_node;	/* Current node is a source node; */
extern Bool Print_html;		/* Print in html format */
extern Bool Print_noref;	/* No cross referencing */
extern Bool Print_layout;	/* Layout printing */
extern Bool eval_comments;      /* Comment printing, default FALSE */
extern Bool printing_to_string;	/* Printing to string iso file */
extern Bool fill_src_info;	/* Fill in src_info while printing */
extern Bool suppress_printing;	/* Suppress printing */
extern Bool create_no_scr_info; /* Suppress creating of src_info */

#define pretty Front_pretty

/* Location + comment before/after an AST data element */
typedef struct s_SrcInfo *SrcInfo;
struct s_SrcInfo {
  int 		loc;
  int 		post_loc;
  scan_strings	pre_comment;
  scan_strings	post_comment;
  SrcInfo	next;
};

#define SrcInfo_loc(p)		((p)->loc)
#define SrcInfo_post_loc(p)	((p)->post_loc)
#define SrcInfo_pre_comment(p)	((p)->pre_comment)
#define SrcInfo_post_comment(p)	((p)->post_comment)
#define SrcInfo_next(p)		((p)->next)

#ifdef _ELEGANT
void Debug_SrcInfo (SrcInfo s);
#define TYPE_SIZE_SrcInfo SIZE_pointer
#endif

/* Create a SrcInfo without comment */
SrcInfo make_src_info (int loc);
SrcInfo make_post_src_info (int loc, int post);
SrcInfo no_srcinfo; /* Empty src_info */

/* Setting no_src_info to TRUE disables the creating of SrcInfo within make_{post}_src_info */

#ifndef NO_SRCINFO
#define NO_SRCINFO no_srcinfo
#endif

/* Compute pre and post comments for all AST members */
void EvalComments (void);

/* Advance to input position pos, printing all spaces and comment 
  in between current pos and pos.
*/
void advance_position (int pos);

/* Fill in the src info according to pretty print position */
void set_src_info (SrcInfo *info);

/* Add src_info to the whole tree rooted at root,
   while (pretty-) printing to file fn.
   pr is the print_function for the root.
   When bool is false, printing is suppressed.
   The src_info will point to the corresponding position in file fn.
*/
void add_scan_info (char *fn, void *root, void (*pr) (void*), Bool print);

/* Advance to input position pos, no printing is performed. */
void goto_position (int pos);

/* PRINT macros */

#ifndef PRINT_Int
#define PRINT_Int Print_Int
#endif

#ifndef PRINT_Oct
#define PRINT_Oct Print_Oct
#endif

#ifndef PRINT_Hex
#define PRINT_Hex Print_Hex
#endif

#ifndef PRINT_Float
#define PRINT_Float Print_Float
#endif

#ifndef PRINT_String
#define PRINT_String Print_String
#endif

#ifndef PRINT_Keyword
#define PRINT_Keyword Print_Keyword
#endif

#ifndef PRINT_Ident
#define PRINT_Ident Print_Ident
#endif

#ifndef PRINT_Char
#define PRINT_Char Print_Char
#endif

#ifndef PRINT_Bool
#define PRINT_Bool Print_Bool
#endif

#ifndef PRINT_List_Int
#define PRINT_List_Int Print_List_Int
#endif

#ifndef PRINT_List_Oct
#define PRINT_List_Oct Print_List_Oct
#endif

#ifndef PRINT_List_Hex
#define PRINT_List_Hex Print_List_Hex
#endif

#ifndef PRINT_List_Ident
#define PRINT_List_Ident Print_List_Ident
#endif

#ifndef PRINT_List_String
#define PRINT_List_String Print_List_String
#endif

#ifndef PRINT_List_Bool
#define PRINT_List_Bool Print_List_Bool
#endif

#ifndef PRINT_List_Char
#define PRINT_List_Char Print_List_Char
#endif

/* Basic pritn functions */
void Print_NL(void); 
void Print_Layout(String a); 

void Print_Int(Int a); 
void Print_Oct(Int a);
void Print_Hex(Int a);
void Print_Float(Float a);
void Print_String(String a); 
void Print_Keyword(String a); 
void Print_Ident(Ident a);
void Print_Char(Char a);
void Print_Bool(Bool a);

#ifndef _ELEGANT
void Print_List_Int (List_Int me);
void Print_List_Ident (List_Ident me);
void Print_List_Bool (List_Bool me);
void Print_List_String (List_String me);
void Print_List_Char (List_Char me);
#define Print_List_Oct Print_List_Int
#define Print_List_Hex Print_List_Int
#endif

/* Open file for printing, default is stdout */
Bool open_print_file (char *fn, Bool pretty);
void close_print_file (void);

/* Open string for printing */
Bool open_print_string (char *fn, Bool pretty);
void close_print_string (void);

/* printf version, prints either to print_file or print_string */
int Front_outputf (char *format, ...);

/* Below this line is for internal use only */

#ifdef _ELEGANT
void print_support_InitGlobals (void);
#endif

unsigned int fix_margin (void);
unsigned int get_margin (void);
void set_margin (unsigned int margin);
void set_position (unsigned int p);

Bool suppress_comment;
void print_comment (scan_strings s);

void set_advance (Bool adv);

char *Print_unstring (char*);

char *get_loc_file(int loc);
char *get_loc_line(int loc);
char *get_loc_col(int loc);


/* Html generation */
void start_label (void *def);
void end_label (void);
void start_href (int loc, void *ref);
void end_href (void);
#ifdef _ELEGANT
#define start_label_4(d) start_label((void*)d)
#define start_href_4(l,r) start_href(l, (void*)r)
#endif

#if defined(_ELEGANT) && !defined(_IMPL_)
#undef Int
#undef Char
#undef String
#undef Float
#undef Ident 
#undef Bool 
#endif

#endif /* _print_support */
