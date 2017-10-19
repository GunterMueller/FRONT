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

#ifndef _cpp_cpp_h
#define _cpp_cpp_h

#include <stdio.h>
#include <front/flags.h>
#include <front/hash.h>

extern fe_cli_flag libcpp_flags[];
extern const int   num_libcpp_flags;

void CPP_initialize(void);                   /* initialize cpp */
void CPP_finish(void);                       /* clear internal state */
void CPP_predefines(int gnu);                /* set standard predefines*/
void CPP_c99(void);                          /* enable c99 compatibility */
void CPP_gnu(void);                          /* enable Gnu compatibility */
void CPP_trigraphs(void);                    /* enable trigraph translation */
void CPP_inhibit_expansion(void);            /* inhibit macro expansion*/
void CPP_inhibit_linemarkers(void);          /* inhibit generation of linemarkers */

void CPP_original_location(void);            /* emit tokens to original location */
void CPP_deep_location(void);                /* keep track of original token locations */
void CPP_visual_studio(void);                /* be a bit visual studio compatible */

void CPP_include_path(const char *dir);      /* add DIR to the include path */
void CPP_std_include_path(void);             /* add the standard include dirs */
void CPP_predefine(char *alias, char *repl); /* #define alias repl */
int  CPP_cli_define(char *def);              /* store a cli define (-D) */
void CPP_cli_include (const char *file);     /* add a cli include (-include) */

int  CPP_preprocess(const char *filename);   /* read and preprocess FILENAME */
int  CPP_preprocess_string(const char *filename, char *string);
void CPP_set_location(int loc);              /* set the current location */
void CPP_emit(FILE *out);                    /* write preprocess file to OUT */
int  CPP_output(char *buf, int max);         /* write upto MAX chars into BUF */

void CPP_find_location(int loc, int *line, int *pos, identifier *file);

char *CPP_alias(const char *symbol);         /* retrieve expanded text of alias #define SYMBOL */
void CPP_list_defines();                     /* list all (unexpanded) #defines and #undefs */
void CPP_list_incpaths();                    /* list all (standard, implied, and -I) include paths */

#define YY_INPUT(buf,result,max)                                                        \
 if(!yyin) result=CPP_output(buf,max);                                                  \
 else {                                                                                 \
  result = fread(buf, 1, max, yyin);                                                    \
  if (result==0 && ferror(yyin)) YY_FATAL_ERROR( "input in flex scanner failed" );      \
 }

/* Error support */

char *token_file (void *t);
char *token_line (void *t);
char *token_col (void *t);
int token_loc (void *t);

void *CPP_dummy_token(char *fname);

#endif /* _cpp_cpp_h */
