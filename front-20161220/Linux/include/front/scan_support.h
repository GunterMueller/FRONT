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

#ifndef _scan_support
#define _scan_support

#include "basic_types.h"
#include "error.h"

#if defined(fe_parser_input) && !defined(yyin)
# define yyin fe_parser_input
#endif


/* The required YYLTYPE for flex */
typedef
  struct s_yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#define yyterminate() yy_init=1; return YY_NULL

/* flex init */
#ifdef __cplusplus
#define YY_USER_INIT { yy_input=yyinput; p_yylloc = &yylloc; p_yylloc->first_line=1; }
#else
#define YY_USER_INIT { yy_input=input; p_yylloc = &yylloc; p_yylloc->first_line=1; }
#endif
#define YYLLOC_DEFAULT(Current, Rhs, N)       	                \
  if ((N)==0) {                                                   \
    (Current).last_line   = p_yylloc->first_line;	                \
    (Current).first_line   = p_yylloc->first_line;	        \
  }                                                             \
  (Current).last_line   = (Rhs)[N].last_line;	


/* A list of position/string pairs, used to store skipped 
   text (comment, white space) from the input text.
   This is later on inserted in the AST for printing the original layout.
*/
typedef struct s_scan_strings *scan_strings;
struct s_scan_strings {
  int pos;
  char *string;
  scan_strings next;
};

#define scan_strings_pos(s)	((s)->pos)
#define scan_strings_string(s)	((s)->string)
#define scan_strings_next(s)	((s)->next)

/* Setting no_scan_strings to TRUE disables building the list of position/string pairs */
extern Bool no_scan_strings;

/* Nested include structure of the input text */

typedef struct s_File_includes *File_includes;
struct s_File_includes {
  Ident name;
  File_includes children;
  File_includes next;
  int begin, end; /* Absolute positions [begin..end) */
};

#define File_includes_name(f)	((f)->name)
#define File_includes_children(f)	((f)->children)
#define File_includes_next(f)	((f)->next)
#define File_includes_begin(f)	((f)->begin)
#define File_includes_end(f)	((f)->end)

/* Build an include structure of the parsed input text */
File_includes Build_file_includes (void);

/*********/

/* Current input file */
extern Ident Front_input_file;

/* Open a new input file and reset the scanner */
void scan_init (char *filename);

/* Find relative line nr/file in src */
extern void (*find_location) (int ch, int *line, int *pos, Ident *file);
void _find_location (int ch, int *line, int *pos, Ident *file);

/* Find absolute line nr in src */
void find_position (int ch, int *line, int *pos); 
int find_line_position (int abs);

/* Check whether ch is in the current input file */
Bool Front_local (int ch);

/* Everything below is for internal use */

extern scan_strings first_strings;
extern scan_strings *last_strings;

#define SCAN_POSITION (count_chars ? p_yylloc->first_line : input_line_nr)
#define SCAN_END_POSITION (count_chars ? p_yylloc->last_line : input_line_nr)
extern int input_line_nr, input_size;
void set_first_line (int i);
extern int (*yy_input)(void);
#undef yylloc /* for bison 1.875c-1 */
extern YYLTYPE yylloc, *p_yylloc;
extern Bool count_chars;

void yyerror (char *);
int yylex (void);
int yyparse (void);

void new_input_line (void);
void skip_comment (char *end);
void skip_string (char *end);
void store_line_dir (int rel, Ident f) ;
void update_line_and_fname(char *string);

scan_strings gather_comment (int pos, Bool pre);

void record_symbol (int len, char *text);
void record_length (int len);
Bool Encode_Bool (char *text);
Int Encode_Int (char *text);
Int Encode_Oct (char *text);
Int Encode_Hex (char *text);
Char Encode_Char (char *text);
String Encode_String (char *text);
Ident Encode_Ident (char *text);
Float Encode_Float (char *text);
String Unescape_String(String s, int *length);


#endif /* _scan_support */
