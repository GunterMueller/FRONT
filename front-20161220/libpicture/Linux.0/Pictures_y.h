/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_PICTURES_PICTURES_Y_H_INCLUDED
# define YY_PICTURES_PICTURES_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int Pictures_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NONSENSE = 258,
    rectanglesym = 259,
    circlesym = 260,
    arcsym = 261,
    arctopopsym = 262,
    linesym = 263,
    trianglesym = 264,
    eofillsym = 265,
    Lsym = 266,
    Rsym = 267,
    Usym = 268,
    Dsym = 269,
    Csym = 270,
    openparsym = 271,
    closeparsym = 272,
    ORspacesym = 273,
    ENDORsym = 274,
    ANDspacesym = 275,
    ENDANDsym = 276,
    ALTspacesym = 277,
    ENDALTsym = 278,
    Boolsym = 279,
    Floatsym = 280,
    Stringsym = 281,
    Identsym = 282,
    hole_Pictures = 283,
    start_Pictures = 284,
    hole_Direction = 285,
    start_Direction = 286,
    hole_Picture = 287,
    start_Picture = 288,
    hole_OPTMORE_Picture = 289,
    start_OPTMORE_Picture = 290,
    hole_MORE_Picture = 291,
    start_MORE_Picture = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


Bool Boolsym_type;
Float Floatsym_type;
String Stringsym_type;
Ident Identsym_type;
Pictures_Pictures Pictures_type;
Pictures_Direction Direction_type;
Pictures_Picture Picture_type;
List_Pictures_Picture OPTMORE_Picture_type;
struct {
  List_Pictures_Picture f1;
  List_Pictures_Direction f2;
} ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL_type;
struct {
  List_Pictures_Picture f1;
  List_Pictures_Direction f2;
} ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL_type;
List_Pictures_Picture MORE_Picture_type;


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE Pictures_lval;
extern YYLTYPE Pictures_lloc;
int Pictures_parse (void);

#endif /* !YY_PICTURES_PICTURES_Y_H_INCLUDED  */
