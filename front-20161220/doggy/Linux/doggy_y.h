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

#ifndef YY_DOGGY_DOGGY_Y_H_INCLUDED
# define YY_DOGGY_DOGGY_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int doggy_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NONSENSE = 258,
    TYPESsym = 259,
    ATTRIBUTESsym = 260,
    openchainsym = 261,
    OPRsym = 262,
    commasym = 263,
    closechainsym = 264,
    MACHINEsym = 265,
    DESCRIPTIONsym = 266,
    openparsym = 267,
    closeparsym = 268,
    starsym = 269,
    openbrksym = 270,
    minussym = 271,
    dotdotsym = 272,
    STEPsym = 273,
    closebrksym = 274,
    verticalbarsym = 275,
    colonsym = 276,
    COMMUTATIVEsym = 277,
    SUPPORTSsym = 278,
    EXTERNALsym = 279,
    externsym = 280,
    semicolonsym = 281,
    FUNCTIONSsym = 282,
    equalssym = 283,
    ANYsym = 284,
    NULLsym = 285,
    _sym = 286,
    candsym = 287,
    corsym = 288,
    hatsym = 289,
    eqsym = 290,
    neqsym = 291,
    lesym = 292,
    gesym = 293,
    lessthansym = 294,
    greaterthansym = 295,
    shlsym = 296,
    shrsym = 297,
    slashsym = 298,
    percentsym = 299,
    ampersandsym = 300,
    plussym = 301,
    openquotesym = 302,
    CONSsym = 303,
    IFsym = 304,
    THENsym = 305,
    ELSIFsym = 306,
    ELSEsym = 307,
    FIsym = 308,
    exclaimsym = 309,
    tildasym = 310,
    arrowsym = 311,
    WHEREsym = 312,
    RULESsym = 313,
    comment1sym = 314,
    comment2sym = 315,
    Boolsym = 316,
    Identsym = 317,
    Intsym = 318,
    Stringsym = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


Bool Boolsym_type;
Ident Identsym_type;
Int Intsym_type;
String Stringsym_type;
doggy_doggy doggy_type;
List_doggy_Typedef Typedefs_type;
doggy_Typedef Typedef_type;
List_doggy_FunctionDef externals_type;
doggy_FunctionDef FunctionDef_type;
doggy_machine_description machine_description_type;
doggy_Operation_def Operation_def_type;
doggy_Attributes Attributes_type;
List_doggy_Attribute Attrs_type;
doggy_Attribute Attribute_type;
doggy_Section Section_type;
struct {
  Ident f1;
  List_doggy_Rule f2;
} Rules_type;
doggy_Rule Rule_type;
doggy_Lhs Lhs_type;
List_doggy_Func Funcs_type;
doggy_Func Func_type;
List_doggy_FuncRule FuncRules_type;
doggy_FuncRule FuncRule_type;
List_doggy_Argument Arguments_type;
doggy_Argument Argument_type;
doggy_ArgPat ArgPat_type;
ArgPat ArgPat2_type;
ArgPat PatArg1_type;
ArgPat ParArg_type;
doggy_SetArg SetArg_type;
doggy_Pattern Pattern_type;
Pattern UnTypedPattern_type;
doggy_ConsPattern ConsPattern_type;
Pattern SimplePattern_type;
doggy_DefPattern DefPattern_type;
doggy_IdentPattern IdentPattern_type;
List_doggy_Pattern IdentPatterns_type;
Pattern SingleDefPattern_type;
Pattern IdParPattern_type;
Pattern BinPattern_type;
doggy_BasicPattern BasicPattern_type;
Pattern ParPattern_type;
doggy_Rhs Rhs_type;
doggy_Guard Guard_type;
doggy_ExprSeq ExprSeq_type;
doggy_Wherepart Wherepart_type;
doggy_Applied_operation Applied_operation_type;
doggy_OpSet OpSet_type;
List_doggy_Applied_formal Applied_formals_type;
doggy_Applied_formal Applied_formal_type;
doggy_Expr Expr_type;
Expr IdOpExpr_type;
doggy_ConsExpr ConsExpr_type;
doggy_SimpleExpr SimpleExpr_type;
doggy_Expr Condition_type;
doggy_Constant Constant_type;
doggy_Definition Definition_type;
doggy_Operator Operator_type;
Ident IdOp_type;
doggy_MonOp MonOp_type;
doggy_Type Type_type;
doggy_BasicType BasicType_type;
doggy_Property Property_type;
List_doggy_Type ArgTypes_type;
List_doggy_Pattern Patterns_type;
List_doggy_Expr Exprs_type;
List_doggy_Type Types_type;
doggy_Num Num_type;
List_doggy_Typedef OPT_Typedefs_type;
doggy_machine_description OPT_machine_description_type;
List_doggy_FunctionDef OPT_externals_type;
List_doggy_Section OPTMORE_Section_type;
List_doggy_Typedef OPTMORE_Typedef_type;
struct {
  String f1;
  String f2;
  String f3;
} OPT_Stringsym_Stringsym_Stringsym_type;
doggy_Attributes OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_type;
List_doggy_FunctionDef OPTMORE_FunctionDef_type;
List_doggy_Operation_def OPTMORE_Operation_def_type;
List_doggy_Applied_formal OPT_SUPPORTSsym_OPTMORE_Applied_formal_type;
List_doggy_Applied_formal OPTMORE_Applied_formal_type;
List_doggy_Type OPT_Types_type;
doggy_Type OPT_colonsym_Type_type;
List_doggy_Property OPTMORE_Property_type;
struct {
  List_doggy_Attribute f1;
  doggy_Attributes f2;
} OPT_Attrs_OPT_commasym_Attributes_type;
doggy_Attributes OPT_commasym_Attributes_type;
List_doggy_Attribute MORE_Attribute_type;
Ident OPT_colonsym_Identsym_type;
List_doggy_Rule OPTMORE_Rule_type;
List_doggy_Func OPTMORE_Func_type;
Bool OPT_externsym_type;
List_doggy_FuncRule ALT_FuncRule_SEP_commasym_type;
List_doggy_Argument OPT_Arguments_type;
List_doggy_Argument ALT_Argument_SEP_commasym_type;
doggy_Pattern OPT_equalssym_UnTypedPattern_type;
List_doggy_Pattern ALT_IdentPattern_SEP_commasym_type;
struct {
  Ident f1;
  doggy_Pattern f2;
} OPT_IdOp_SimplePattern_type;
List_doggy_Pattern OPT_Patterns_type;
doggy_Expr OPT_equalssym_SimpleExpr_type;
List_doggy_Guard MORE_Guard_type;
doggy_Wherepart OPT_Wherepart_type;
doggy_Expr OPT_verticalbarsym_Condition_type;
List_doggy_Definition OPTMORE_Definition_type;
List_doggy_Applied_formal ALT_Applied_formal_SEP_commasym_type;
struct {
  List_doggy_Expr f1;
  List_doggy_Operator f2;
} ALT_SimpleExpr_SEP_Operator_type;
struct {
  List_doggy_Expr f1;
  List_doggy_Expr f2;
} OPTMORE_ELSIFsym_Condition_THENsym_Expr_type;
List_doggy_Expr OPT_Exprs_type;
List_doggy_Type ALT_BasicType_SEP_verticalbarsym_type;
List_doggy_Type OPT_ArgTypes_type;
doggy_Num OPT_STEPsym_Num_type;
List_doggy_Pattern ALT_Pattern_SEP_commasym_type;
List_doggy_Expr ALT_Expr_SEP_commasym_type;
List_doggy_Type ALT_Type_SEP_commasym_type;
Bool OPT_minussym_type;


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


extern YYSTYPE doggy_lval;
extern YYLTYPE doggy_lloc;
int doggy_parse (void);

#endif /* !YY_DOGGY_DOGGY_Y_H_INCLUDED  */
