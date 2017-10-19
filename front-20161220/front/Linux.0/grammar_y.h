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
     hatsym = 259,
     dollarsym = 260,
     openchainsym = 261,
     closechainsym = 262,
     openparsym = 263,
     closeparsym = 264,
     dotsym = 265,
     questionmarksym = 266,
     plussym = 267,
     starsym = 268,
     verticalbarsym = 269,
     semicolonsym = 270,
     nonterminalsym = 271,
     importsym = 272,
     extrasym = 273,
     Stringsym = 274,
     Identsym = 275,
     hole_grammar = 276,
     start_grammar = 277,
     hole_Scanner = 278,
     start_Scanner = 279,
     hole_Token = 280,
     start_Token = 281,
     hole_RegExpr = 282,
     start_RegExpr = 283,
     hole_ChoiceRE = 284,
     start_ChoiceRE = 285,
     hole_SeqRE = 286,
     start_SeqRE = 287,
     hole_PostRE = 288,
     start_PostRE = 289,
     hole_BasicRE = 290,
     start_BasicRE = 291,
     hole_ScanAction = 292,
     start_ScanAction = 293,
     hole_Parser = 294,
     start_Parser = 295,
     hole_ProdRule = 296,
     start_ProdRule = 297,
     hole_OPTMORE_Token = 298,
     start_OPTMORE_Token = 299,
     hole_OPTMORE_ScanAction_semicolonsym = 300,
     start_OPTMORE_ScanAction_semicolonsym = 301,
     hole_OPT_verticalbarsym_RegExpr = 302,
     start_OPT_verticalbarsym_RegExpr = 303,
     hole_OPT_SeqRE = 304,
     start_OPT_SeqRE = 305,
     hole_OPTMORE_ProdRule = 306,
     start_OPTMORE_ProdRule = 307
   };
#endif
#define NONSENSE 258
#define hatsym 259
#define dollarsym 260
#define openchainsym 261
#define closechainsym 262
#define openparsym 263
#define closeparsym 264
#define dotsym 265
#define questionmarksym 266
#define plussym 267
#define starsym 268
#define verticalbarsym 269
#define semicolonsym 270
#define nonterminalsym 271
#define importsym 272
#define extrasym 273
#define Stringsym 274
#define Identsym 275
#define hole_grammar 276
#define start_grammar 277
#define hole_Scanner 278
#define start_Scanner 279
#define hole_Token 280
#define start_Token 281
#define hole_RegExpr 282
#define start_RegExpr 283
#define hole_ChoiceRE 284
#define start_ChoiceRE 285
#define hole_SeqRE 286
#define start_SeqRE 287
#define hole_PostRE 288
#define start_PostRE 289
#define hole_BasicRE 290
#define start_BasicRE 291
#define hole_ScanAction 292
#define start_ScanAction 293
#define hole_Parser 294
#define start_Parser 295
#define hole_ProdRule 296
#define start_ProdRule 297
#define hole_OPTMORE_Token 298
#define start_OPTMORE_Token 299
#define hole_OPTMORE_ScanAction_semicolonsym 300
#define start_OPTMORE_ScanAction_semicolonsym 301
#define hole_OPT_verticalbarsym_RegExpr 302
#define start_OPT_verticalbarsym_RegExpr 303
#define hole_OPT_SeqRE 304
#define start_OPT_SeqRE 305
#define hole_OPTMORE_ProdRule 306
#define start_OPTMORE_ProdRule 307




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)

typedef union YYSTYPE {
String Stringsym_type;
Ident Identsym_type;
grammar_grammar grammar_type;
grammar_Scanner Scanner_type;
grammar_Token Token_type;
grammar_RegExpr RegExpr_type;
grammar_ChoiceRE ChoiceRE_type;
grammar_SeqRE SeqRE_type;
grammar_PostRE PostRE_type;
grammar_BasicRE BasicRE_type;
String ScanAction_type;
grammar_Parser Parser_type;
grammar_ProdRule ProdRule_type;
List_grammar_Token OPTMORE_Token_type;
List_String OPTMORE_ScanAction_semicolonsym_type;
grammar_RegExpr OPT_verticalbarsym_RegExpr_type;
grammar_RegExpr OPT_SeqRE_type;
List_grammar_ProdRule OPTMORE_ProdRule_type;
} YYSTYPE;
/* Line 1268 of yacc.c.  */

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE grammar_lval;

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

extern YYLTYPE grammar_lloc;


