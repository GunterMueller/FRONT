/* A Bison parser, made by GNU Bison 1.875c.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NONSENSE = 258,
     GRAMMARsym = 259,
     minusgreaterthansym = 260,
     questionmarksym = 261,
     semicolonsym = 262,
     emptycolonsym = 263,
     NON_EMPTYsym = 264,
     EMPTYsym = 265,
     firstcolonsym = 266,
     spacesym = 267,
     STATESsym = 268,
     statesym = 269,
     dotsym = 270,
     followerscolonsym = 271,
     transitionssym = 272,
     equalsgreaterthansym = 273,
     Intsym = 274,
     Identsym = 275,
     hole_Lalr = 276,
     start_Lalr = 277,
     hole_Production = 278,
     start_Production = 279,
     hole_ProdRhs = 280,
     start_ProdRhs = 281,
     hole_LR_Symbol = 282,
     start_LR_Symbol = 283,
     hole_LR_Symbols = 284,
     start_LR_Symbols = 285,
     hole_Emptiness = 286,
     start_Emptiness = 287,
     hole_LR_state = 288,
     start_LR_state = 289,
     hole_Item = 290,
     start_Item = 291,
     hole_TermSet = 292,
     start_TermSet = 293,
     hole_Transition = 294,
     start_Transition = 295,
     hole_OPTMORE_Production = 296,
     start_OPTMORE_Production = 297,
     hole_OPTMORE_LR_state = 298,
     start_OPTMORE_LR_state = 299,
     hole_OPT_LR_Symbols = 300,
     start_OPT_LR_Symbols = 301,
     hole_OPT_questionmarksym = 302,
     start_OPT_questionmarksym = 303,
     hole_MORE_Item = 304,
     start_MORE_Item = 305,
     hole_OPTMORE_Transition = 306,
     start_OPTMORE_Transition = 307,
     hole_OPTMORE_LR_Symbol = 308,
     start_OPTMORE_LR_Symbol = 309,
     hole_OPT_followerscolonsym_TermSet = 310,
     start_OPT_followerscolonsym_TermSet = 311,
     hole_MORE_Identsym_spacesym = 312,
     start_MORE_Identsym_spacesym = 313
   };
#endif
#define NONSENSE 258
#define GRAMMARsym 259
#define minusgreaterthansym 260
#define questionmarksym 261
#define semicolonsym 262
#define emptycolonsym 263
#define NON_EMPTYsym 264
#define EMPTYsym 265
#define firstcolonsym 266
#define spacesym 267
#define STATESsym 268
#define statesym 269
#define dotsym 270
#define followerscolonsym 271
#define transitionssym 272
#define equalsgreaterthansym 273
#define Intsym 274
#define Identsym 275
#define hole_Lalr 276
#define start_Lalr 277
#define hole_Production 278
#define start_Production 279
#define hole_ProdRhs 280
#define start_ProdRhs 281
#define hole_LR_Symbol 282
#define start_LR_Symbol 283
#define hole_LR_Symbols 284
#define start_LR_Symbols 285
#define hole_Emptiness 286
#define start_Emptiness 287
#define hole_LR_state 288
#define start_LR_state 289
#define hole_Item 290
#define start_Item 291
#define hole_TermSet 292
#define start_TermSet 293
#define hole_Transition 294
#define start_Transition 295
#define hole_OPTMORE_Production 296
#define start_OPTMORE_Production 297
#define hole_OPTMORE_LR_state 298
#define start_OPTMORE_LR_state 299
#define hole_OPT_LR_Symbols 300
#define start_OPT_LR_Symbols 301
#define hole_OPT_questionmarksym 302
#define start_OPT_questionmarksym 303
#define hole_MORE_Item 304
#define start_MORE_Item 305
#define hole_OPTMORE_Transition 306
#define start_OPTMORE_Transition 307
#define hole_OPTMORE_LR_Symbol 308
#define start_OPTMORE_LR_Symbol 309
#define hole_OPT_followerscolonsym_TermSet 310
#define start_OPT_followerscolonsym_TermSet 311
#define hole_MORE_Identsym_spacesym 312
#define start_MORE_Identsym_spacesym 313




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)

typedef union YYSTYPE {
Int Intsym_type;
Ident Identsym_type;
Lalr_Lalr Lalr_type;
Lalr_Production Production_type;
Lalr_LR_Symbols ProdRhs_type;
Lalr_LR_Symbol LR_Symbol_type;
Lalr_LR_Symbols LR_Symbols_type;
Lalr_Emptiness Emptiness_type;
Lalr_LR_state LR_state_type;
Lalr_Item Item_type;
List_Ident TermSet_type;
Lalr_Transition Transition_type;
List_Lalr_Production OPTMORE_Production_type;
List_Lalr_LR_state OPTMORE_LR_state_type;
Lalr_LR_Symbols OPT_LR_Symbols_type;
Bool OPT_questionmarksym_type;
List_Lalr_Item MORE_Item_type;
List_Lalr_Transition OPTMORE_Transition_type;
List_Lalr_LR_Symbol OPTMORE_LR_Symbol_type;
List_Ident OPT_followerscolonsym_TermSet_type;
List_Ident MORE_Identsym_spacesym_type;
} YYSTYPE;
/* Line 1268 of yacc.c.  */

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE Lalr_lval;

#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE Lalr_lloc;


