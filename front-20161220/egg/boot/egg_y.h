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

#ifndef YY_EGG_EGG_Y_H_INCLUDED
# define YY_EGG_EGG_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int egg_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NONSENSE = 258,
    usessym = 259,
    commasym = 260,
    semicolonsym = 261,
    fatalsym = 262,
    errorsym = 263,
    warningsym = 264,
    disabledsym = 265,
    keysym = 266,
    postsym = 267,
    openparsym = 268,
    closeparsym = 269,
    groupsym = 270,
    openchainsym = 271,
    equalssym = 272,
    closechainsym = 273,
    commentsym = 274,
    Stringsym = 275,
    Identsym = 276,
    hole_egg = 277,
    start_egg = 278,
    hole_Uses = 279,
    start_Uses = 280,
    hole_Strings = 281,
    start_Strings = 282,
    hole_Declarations = 283,
    start_Declarations = 284,
    hole_Declaration = 285,
    start_Declaration = 286,
    hole_Expression = 287,
    start_Expression = 288,
    hole_Params = 289,
    start_Params = 290,
    hole_Statements = 291,
    start_Statements = 292,
    hole_Statement = 293,
    start_Statement = 294,
    hole_MessageKind = 295,
    start_MessageKind = 296,
    hole_Message = 297,
    start_Message = 298,
    hole_SubMessages = 299,
    start_SubMessages = 300,
    hole_SubMessage = 301,
    start_SubMessage = 302,
    hole_Group = 303,
    start_Group = 304,
    hole_OPTMORE_Group = 305,
    start_OPTMORE_Group = 306,
    hole_ALT_Stringsym_SEP_commasym = 307,
    start_ALT_Stringsym_SEP_commasym = 308,
    hole_OPTMORE_Declaration = 309,
    start_OPTMORE_Declaration = 310,
    hole_MORE_Expression = 311,
    start_MORE_Expression = 312,
    hole_ALT_Expression_SEP_commasym = 313,
    start_ALT_Expression_SEP_commasym = 314,
    hole_OPTMORE_Statement = 315,
    start_OPTMORE_Statement = 316,
    hole_OPT_fatalsym = 317,
    start_OPT_fatalsym = 318,
    hole_ALT_SubMessage_SEP_commasym = 319,
    start_ALT_SubMessage_SEP_commasym = 320,
    hole_OPT_openparsym_Identsym_closeparsym = 321,
    start_OPT_openparsym_Identsym_closeparsym = 322,
    hole_OPT_groupsym = 323,
    start_OPT_groupsym = 324
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


String Stringsym_type;
Ident Identsym_type;
egg_egg egg_type;
egg_Uses Uses_type;
List_String Strings_type;
List_egg_Declaration Declarations_type;
egg_Declaration Declaration_type;
egg_Expression Expression_type;
List_egg_Expression Params_type;
List_egg_Statement Statements_type;
egg_Statement Statement_type;
egg_MessageKind MessageKind_type;
egg_Message Message_type;
List_egg_SubMessage SubMessages_type;
egg_SubMessage SubMessage_type;
egg_Group Group_type;
List_egg_Statement OPTMORE_Group_type;
List_String ALT_Stringsym_SEP_commasym_type;
List_egg_Declaration OPTMORE_Declaration_type;
List_egg_Expression MORE_Expression_type;
List_egg_Expression ALT_Expression_SEP_commasym_type;
List_egg_Statement OPTMORE_Statement_type;
Bool OPT_fatalsym_type;
List_egg_SubMessage ALT_SubMessage_SEP_commasym_type;
Ident OPT_openparsym_Identsym_closeparsym_type;
Bool OPT_groupsym_type;


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


extern YYSTYPE egg_lval;
extern YYLTYPE egg_lloc;
int egg_parse (void);

#endif /* !YY_EGG_EGG_Y_H_INCLUDED  */
