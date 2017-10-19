/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         doggy_parse
#define yylex           doggy_lex
#define yyerror         doggy_error
#define yydebug         doggy_debug
#define yynerrs         doggy_nerrs

#define yylval          doggy_lval
#define yychar          doggy_char
#define yylloc          doggy_lloc

/* Copy the first part of user declarations.  */


#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "doggy.h"

extern int input_line_nr;

struct yy_buffer_state *doggy_dummy_state (void);
struct yy_buffer_state *doggy_scanner_state (void);



# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "doggy_y.h".  */
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

/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  210
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  321

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   384,   384,   395,   404,   412,   421,   431,   440,   450,
     463,   469,   477,   483,   489,   495,   501,   507,   518,   526,
     534,   540,   549,   559,   567,   576,   584,   592,   605,   612,
     619,   626,   632,   638,   645,   652,   659,   666,   673,   681,
     688,   695,   702,   709,   716,   726,   732,   740,   748,   755,
     762,   771,   777,   783,   790,   799,   805,   814,   825,   834,
     840,   848,   855,   861,   868,   874,   882,   890,   896,   902,
     909,   916,   924,   932,   939,   945,   958,   964,   973,   981,
     988,   996,  1002,  1008,  1014,  1020,  1029,  1035,  1041,  1047,
    1053,  1059,  1065,  1071,  1077,  1083,  1089,  1095,  1101,  1107,
    1113,  1119,  1125,  1131,  1140,  1146,  1152,  1158,  1164,  1170,
    1176,  1182,  1190,  1196,  1203,  1210,  1221,  1231,  1237,  1247,
    1255,  1263,  1271,  1280,  1286,  1293,  1299,  1306,  1312,  1319,
    1325,  1333,  1339,  1347,  1355,  1366,  1372,  1382,  1388,  1396,
    1402,  1410,  1416,  1424,  1430,  1438,  1444,  1451,  1457,  1465,
    1471,  1479,  1486,  1495,  1501,  1509,  1516,  1524,  1530,  1538,
    1544,  1552,  1558,  1566,  1572,  1579,  1586,  1595,  1601,  1608,
    1615,  1624,  1630,  1638,  1645,  1654,  1661,  1670,  1676,  1683,
    1689,  1697,  1704,  1712,  1718,  1725,  1731,  1739,  1745,  1753,
    1760,  1769,  1777,  1787,  1794,  1806,  1812,  1819,  1826,  1835,
    1841,  1848,  1854,  1862,  1869,  1878,  1885,  1894,  1901,  1910,
    1916
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NONSENSE", "TYPESsym", "ATTRIBUTESsym",
  "openchainsym", "OPRsym", "commasym", "closechainsym", "MACHINEsym",
  "DESCRIPTIONsym", "openparsym", "closeparsym", "starsym", "openbrksym",
  "minussym", "dotdotsym", "STEPsym", "closebrksym", "verticalbarsym",
  "colonsym", "COMMUTATIVEsym", "SUPPORTSsym", "EXTERNALsym", "externsym",
  "semicolonsym", "FUNCTIONSsym", "equalssym", "ANYsym", "NULLsym", "_sym",
  "candsym", "corsym", "hatsym", "eqsym", "neqsym", "lesym", "gesym",
  "lessthansym", "greaterthansym", "shlsym", "shrsym", "slashsym",
  "percentsym", "ampersandsym", "plussym", "openquotesym", "CONSsym",
  "IFsym", "THENsym", "ELSIFsym", "ELSEsym", "FIsym", "exclaimsym",
  "tildasym", "arrowsym", "WHEREsym", "RULESsym", "comment1sym",
  "comment2sym", "Boolsym", "Identsym", "Intsym", "Stringsym", "$accept",
  "doggy", "Typedefs", "Typedef", "externals", "FunctionDef",
  "machine_description", "Operation_def", "Attributes", "Attrs",
  "Attribute", "Section", "Rules", "Rule", "Lhs", "Funcs", "Func",
  "FuncRules", "FuncRule", "Arguments", "Argument", "ArgPat2", "PatArg1",
  "ParArg", "SetArg", "Pattern", "UnTypedPattern", "ConsPattern",
  "SimplePattern", "DefPattern", "IdentPattern", "IdentPatterns",
  "SingleDefPattern", "IdParPattern", "BinPattern", "BasicPattern",
  "ParPattern", "Rhs", "Guard", "ExprSeq", "Wherepart",
  "Applied_operation", "OpSet", "Applied_formals", "Applied_formal",
  "Expr", "IdOpExpr", "ConsExpr", "cons", "SimpleExpr", "Condition",
  "Constant", "Definition", "Operator", "IdOp", "MonOp", "Type",
  "BasicType", "Property", "ArgTypes", "Patterns", "Exprs", "Types", "Num",
  "OPT_Typedefs", "OPT_machine_description", "OPT_externals",
  "OPTMORE_Section", "OPTMORE_Typedef",
  "OPT_Stringsym_Stringsym_Stringsym",
  "OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym",
  "OPTMORE_FunctionDef", "OPTMORE_Operation_def",
  "OPT_SUPPORTSsym_OPTMORE_Applied_formal", "OPTMORE_Applied_formal",
  "OPT_Types", "OPT_colonsym_Type", "OPTMORE_Property",
  "OPT_Attrs_OPT_commasym_Attributes", "OPT_commasym_Attributes",
  "MORE_Attribute", "OPT_colonsym_Identsym", "OPTMORE_Rule",
  "OPTMORE_Func", "OPT_externsym", "ALT_FuncRule_SEP_commasym",
  "OPT_Arguments", "ALT_Argument_SEP_commasym",
  "OPT_equalssym_UnTypedPattern", "ALT_IdentPattern_SEP_commasym",
  "OPT_IdOp_SimplePattern", "OPT_Patterns", "OPT_equalssym_SimpleExpr",
  "MORE_Guard", "OPT_Wherepart", "OPT_verticalbarsym_Condition",
  "OPTMORE_Definition", "ALT_Applied_formal_SEP_commasym",
  "ALT_SimpleExpr_SEP_Operator", "OPTMORE_ELSIFsym_Condition_THENsym_Expr",
  "OPT_Exprs", "ALT_BasicType_SEP_verticalbarsym", "OPT_ArgTypes",
  "OPT_STEPsym_Num", "ALT_Pattern_SEP_commasym", "ALT_Expr_SEP_commasym",
  "ALT_Type_SEP_commasym", "OPT_minussym", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF -217

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-217)))

#define YYTABLE_NINF -186

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,   -39,    36,  -217,    42,    -7,   -39,  -217,  -217,    40,
      42,    -6,    57,  -217,    23,  -217,    68,    32,    98,  -217,
      43,    81,  -217,   -13,  -217,    11,    99,    43,    97,     9,
      81,  -217,    12,   109,   -13,  -217,  -217,  -217,  -217,  -217,
    -217,   114,   129,    11,  -217,  -217,     9,  -217,    76,  -217,
       9,   132,    27,  -217,    83,     7,  -217,  -217,  -217,    12,
    -217,     9,    86,   102,  -217,  -217,    11,  -217,  -217,   146,
    -217,   142,  -217,  -217,    76,  -217,   151,     9,  -217,  -217,
    -217,   150,   159,   104,    67,  -217,    18,  -217,   106,  -217,
     116,    76,  -217,  -217,   152,   161,  -217,   102,    82,  -217,
    -217,   131,  -217,  -217,  -217,  -217,  -217,   134,   175,  -217,
    -217,  -217,  -217,     9,   167,  -217,  -217,   181,   182,   183,
    -217,  -217,   172,  -217,   188,  -217,   197,   198,  -217,   193,
     205,  -217,   147,  -217,   112,   154,  -217,  -217,    82,   147,
     189,    -3,  -217,   158,  -217,   112,   156,   112,  -217,    84,
    -217,     9,   157,  -217,   201,   203,  -217,    41,   196,   215,
    -217,   116,   199,  -217,    76,   147,  -217,  -217,  -217,  -217,
    -217,   147,  -217,  -217,  -217,   212,  -217,  -217,  -217,  -217,
     147,    10,  -217,    84,  -217,   216,  -217,  -217,  -217,   218,
     222,  -217,  -217,  -217,    14,  -217,  -217,  -217,    38,   178,
     221,  -217,    35,  -217,   217,  -217,  -217,    57,  -217,   183,
     214,   121,  -217,   223,   173,   225,  -217,  -217,   188,  -217,
     141,  -217,   226,   186,   147,  -217,   227,   184,  -217,  -217,
    -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,
    -217,  -217,  -217,  -217,  -217,   147,   147,   147,    82,   147,
     184,  -217,   150,    84,  -217,  -217,   220,  -217,  -217,    95,
    -217,  -217,  -217,  -217,  -217,  -217,    41,   219,    82,  -217,
    -217,  -217,   147,   235,  -217,   231,  -217,  -217,     9,  -217,
    -217,  -217,   253,  -217,  -217,   236,   237,  -217,  -217,  -217,
     220,  -217,  -217,   256,  -217,  -217,  -217,   224,   147,  -217,
       9,   208,  -217,   184,  -217,  -217,   147,   228,  -217,  -217,
     244,  -217,   229,   147,   147,   147,   195,  -217,   224,  -217,
    -217
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     123,   131,     0,   124,     0,   133,   131,     3,     1,     0,
     125,     0,   135,   132,     0,   126,   127,     0,     0,     4,
     139,   137,   128,   129,   134,   151,     0,   139,   141,     0,
     137,     5,   163,   157,   129,    16,    15,     2,    13,    12,
      14,     0,   153,   155,    10,    11,   145,   140,   143,     8,
     145,   199,   209,   112,     0,   197,   110,   138,   164,   163,
      21,     0,     0,   159,   130,   136,   151,   152,   156,   207,
     146,     0,   121,    67,   143,   142,     0,   145,   200,   113,
     210,     0,     0,     0,     0,   114,     0,   162,     0,   158,
       0,     0,    62,    52,   179,    45,    51,   159,   185,    20,
      37,    36,    41,    39,    40,    42,    43,   175,     0,    63,
      64,    17,   154,     0,   147,   144,   111,     0,     0,   209,
     122,     7,     0,   198,     0,    45,   173,     0,    46,     0,
     189,    66,     0,    53,     0,     0,    48,   160,   185,     0,
       0,   181,    55,     0,    73,     0,     0,     0,    49,   177,
     208,     0,     0,   118,     0,   201,     6,   167,     0,   165,
      23,     0,     0,    65,     0,     0,   107,   109,    84,   106,
     108,     0,   104,   105,    82,    74,    81,    83,   180,    76,
       0,    45,    19,     0,    47,     0,    80,    69,    70,   191,
     186,    68,    18,   182,     0,    38,   103,   176,   209,   112,
     203,    34,     0,   178,     0,   119,   148,   135,   116,   209,
       0,   112,   168,   169,     0,     0,    25,    22,     0,   174,
       0,   190,     0,     0,   195,    79,     0,   183,    99,   102,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   100,   101,     0,     0,     0,   185,     0,
     183,    59,    67,     0,    35,    50,   149,   202,   115,     0,
      27,    28,    29,    30,    32,    31,     0,   171,   185,   166,
      44,    78,     0,   205,   196,     0,   120,    54,   187,   184,
      56,    72,   191,   192,    71,     0,     0,    58,   204,   117,
     149,     9,   172,    33,   170,    26,    24,   193,     0,    77,
     187,     0,    61,   183,    60,   150,     0,     0,   206,   188,
       0,    57,     0,     0,     0,     0,     0,    85,   193,    75,
     194
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -217,  -217,  -217,  -217,  -217,  -217,   263,  -217,   210,  -217,
    -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,
    -217,    16,  -217,  -217,  -217,    91,   -62,  -217,   130,  -217,
     -80,  -217,  -217,  -217,  -126,  -217,  -200,  -132,  -217,  -217,
    -217,  -217,    19,  -217,   -45,  -163,  -217,  -217,    92,  -125,
    -167,  -217,  -217,  -217,    93,  -217,   -29,  -141,  -217,   200,
    -217,    51,  -217,  -114,  -217,  -217,  -217,   267,   296,  -217,
      96,   274,   278,  -217,   232,   -37,  -217,    17,  -217,  -217,
     265,  -217,   213,   250,  -217,    94,  -217,    45,  -217,   153,
    -217,  -217,  -217,   174,  -216,  -217,    13,   155,    70,    -1,
    -217,   234,  -217,  -217,    65,    24,   211,  -217
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,    22,    30,    10,    27,    41,    42,
      43,    34,    35,    97,    98,    36,    59,   158,   159,   212,
     213,   260,   261,   262,   263,   200,   201,   100,   101,   102,
     103,   127,   104,   105,   106,   107,   136,   140,   141,   250,
     279,   108,   109,   129,   110,   186,   187,   188,   145,   189,
     190,   179,   300,   246,   147,   180,    69,    55,   290,    78,
     203,   274,    70,    82,     4,    16,    23,    37,     7,    12,
      19,    31,    28,    49,    75,    71,   152,   291,    44,    67,
      45,    63,   111,    60,    61,   160,   215,   216,   265,   128,
     148,   204,   133,   142,   280,   143,   302,   131,   191,   307,
     275,    56,    79,   210,   205,   276,    72,    83
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    99,   222,    74,   223,   155,   185,   178,   202,   184,
     126,   264,  -161,    76,    32,    50,    51,   139,    38,     1,
     249,    85,   -67,     5,    52,    51,   165,    86,   166,    74,
     167,   251,    88,    52,   287,    99,     8,    58,   135,  -161,
     117,    90,   202,    80,   168,    33,   130,    50,    51,    85,
      91,    14,     9,  -185,    80,   225,    52,    11,    17,   169,
     170,   273,    18,   171,    92,    93,    94,   264,   172,   173,
    -161,    53,   182,    39,    40,   174,   175,   176,   177,    77,
      53,   126,   281,   195,   284,    20,   273,   311,   138,    81,
      90,    51,    21,   121,   270,   257,    24,   181,    96,   198,
     252,    90,   139,   211,    25,    26,    29,   183,    90,   297,
      91,    46,   202,    92,    93,    94,   285,    91,    90,   130,
      48,   282,   206,    65,    92,    93,    94,    91,   214,  -171,
      62,    92,    93,    94,  -171,   273,   296,    66,    73,   312,
     254,    92,    93,    94,    77,    84,   199,    96,    89,   259,
     316,   317,   318,   130,   113,   114,    91,   181,    96,   165,
     116,   166,   118,   167,    95,    96,   183,   120,   124,    91,
      92,    93,    94,   -67,   181,    96,   119,   168,   125,   144,
     132,   146,   134,    92,    93,    94,   -45,   149,   151,   135,
     -67,   -45,   169,   170,   153,   154,   171,   292,   156,    80,
     157,   172,   173,    73,    96,   161,   135,   162,   174,   175,
     176,   177,   163,   164,   194,   192,    73,    96,   196,   207,
     208,   209,   217,   218,   224,   227,   -45,   220,   248,   253,
     255,   266,   228,   258,   229,   267,   272,   214,   268,   271,
     277,   278,   289,   298,   299,   303,   304,   259,   319,   301,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   146,   144,   228,   -63,   229,
     310,   301,   314,    15,   226,   306,   112,   197,   293,   315,
     313,   245,   247,   295,   122,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     286,    64,    13,   256,    57,    47,   115,   305,    68,    87,
     137,   294,   269,   309,   219,   193,   283,   320,   288,   221,
     123,     0,   308,     0,   150
};

static const yytype_int16 yycheck[] =
{
      29,    63,   165,    48,   171,   119,   138,   132,   149,   135,
      90,   211,     0,    50,    27,     6,     7,    20,     7,     4,
       6,    14,    12,    62,    15,     7,    12,    20,    14,    74,
      16,   194,    61,    15,   250,    97,     0,    25,    28,    27,
      77,     6,   183,    16,    30,    58,    91,     6,     7,    14,
      15,    11,    10,    56,    16,   180,    15,    64,    64,    45,
      46,   224,     5,    49,    29,    30,    31,   267,    54,    55,
      58,    62,   134,    62,    63,    61,    62,    63,    64,    12,
      62,   161,   245,   145,   247,    62,   249,   303,     6,    62,
       6,     7,    24,    26,   220,   209,    64,    62,    63,    15,
      62,     6,    20,    62,     6,    62,    25,    12,     6,   272,
      15,    12,   253,    29,    30,    31,   248,    15,     6,   164,
      23,   246,   151,     9,    29,    30,    31,    15,   157,     8,
      21,    29,    30,    31,    13,   298,   268,     8,    62,   306,
     202,    29,    30,    31,    12,    62,    62,    63,    62,    28,
     313,   314,   315,   198,     8,    13,    15,    62,    63,    12,
       9,    14,    12,    16,    62,    63,    12,    63,    62,    15,
      29,    30,    31,    12,    62,    63,    17,    30,    62,    48,
      28,    47,    21,    29,    30,    31,     8,    12,    21,    28,
      12,    13,    45,    46,    13,    13,    49,   259,    26,    16,
      12,    54,    55,    62,    63,     8,    28,     9,    61,    62,
      63,    64,    19,     8,    56,    26,    62,    63,    62,    62,
      19,    18,    26,     8,    12,     9,    48,    28,     6,     8,
      13,     8,    14,    19,    16,    62,    50,   266,    13,    13,
      13,    57,    22,     8,    13,     9,     9,    28,    53,   278,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    14,    12,    16,
      62,   300,    28,    10,   183,    51,    66,   147,   259,    50,
      52,   189,   189,   267,    84,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
     249,    34,     6,   207,    30,    27,    74,   290,    43,    59,
      97,   266,   218,   300,   161,   141,   246,   318,   253,   164,
      86,    -1,   298,    -1,   113
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    66,    67,   129,    62,    68,   133,     0,    10,
      71,    64,   134,   133,    11,    71,   130,    64,     5,   135,
      62,    24,    69,   131,    64,     6,    62,    72,   137,    25,
      70,   136,    27,    58,    76,    77,    80,   132,     7,    62,
      63,    73,    74,    75,   143,   145,    12,   137,    23,   138,
       6,     7,    15,    62,   121,   122,   166,   136,    25,    81,
     148,   149,    21,   146,   132,     9,     8,   144,   145,   121,
     127,   140,   171,    62,   109,   139,   140,    12,   124,   167,
      16,    62,   128,   172,    62,    14,    20,   148,   121,    62,
       6,    15,    29,    30,    31,    62,    63,    78,    79,    91,
      92,    93,    94,    95,    97,    98,    99,   100,   106,   107,
     109,   147,    73,     8,    13,   139,     9,   140,    12,    17,
      63,    26,   124,   166,    62,    62,    95,    96,   154,   108,
     109,   162,    28,   157,    21,    28,   101,   147,     6,    20,
     102,   103,   158,   160,    48,   113,    47,   119,   155,    12,
     171,    21,   141,    13,    13,   128,    26,    12,    82,    83,
     150,     8,     9,    19,     8,    12,    14,    16,    30,    45,
      46,    49,    54,    55,    61,    62,    63,    64,   114,   116,
     120,    62,    91,    12,    99,   102,   110,   111,   112,   114,
     115,   163,    26,   158,    56,    91,    62,    93,    15,    62,
      90,    91,   122,   125,   156,   169,   121,    62,    19,    18,
     168,    62,    84,    85,   121,   151,   152,    26,     8,   154,
      28,   162,   110,   115,    12,   114,    90,     9,    14,    16,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   113,   118,   119,     6,     6,
     104,   110,    62,     8,    91,    13,   135,   128,    19,    28,
      86,    87,    88,    89,   101,   153,     8,    62,    13,   150,
      99,    13,    50,   110,   126,   165,   170,    13,    57,   105,
     159,   110,   114,   163,   110,   102,   126,   159,   169,    22,
     123,   142,    91,   107,   152,    86,   102,   110,     8,    13,
     117,   121,   161,     9,     9,   142,    51,   164,   170,   161,
      62,   159,   115,    52,    28,    50,   110,   110,   110,    53,
     164
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    68,    69,    70,    70,    71,    72,
      73,    74,    75,    75,    75,    76,    76,    77,    78,    79,
      79,    80,    81,    82,    83,    84,    85,    85,    86,    86,
      86,    87,    88,    89,    90,    90,    91,    91,    92,    93,
      93,    93,    93,    93,    94,    95,    96,    97,    98,    99,
     100,   100,   100,   100,   101,   102,   102,   103,   103,   104,
     104,   105,   106,   106,   106,   107,   108,   109,   110,   110,
     110,   111,   112,   113,   114,   114,   114,   114,   114,   114,
     115,   116,   116,   116,   116,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   120,   120,   120,   120,   120,   120,
     121,   121,   122,   122,   122,   122,   122,   123,   124,   125,
     126,   127,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     147,   148,   148,   149,   149,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   154,   155,   155,   156,   156,   157,
     157,   158,   158,   159,   159,   160,   160,   161,   161,   162,
     162,   163,   163,   164,   164,   165,   165,   166,   166,   167,
     167,   168,   168,   169,   169,   170,   170,   171,   171,   172,
     172
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     3,     2,     5,     4,     5,     8,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     2,     5,     1,     4,     1,     3,     2,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     5,     1,     1,     3,     2,     2,
       4,     1,     1,     2,     4,     1,     4,     6,     4,     1,
       3,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     8,     1,     4,     3,     2,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     2,     6,     5,     1,     3,     1,
       1,     1,     2,     0,     1,     0,     1,     0,     1,     0,
       2,     0,     2,     0,     3,     0,     4,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     1,     0,     2,     0,
       2,     0,     2,     0,     2,     1,     2,     0,     2,     0,
       2,     0,     2,     0,     1,     1,     3,     0,     1,     1,
       3,     0,     2,     1,     3,     0,     2,     0,     1,     0,
       2,     1,     2,     0,     1,     0,     2,     0,     2,     1,
       3,     1,     3,     0,     5,     0,     1,     1,     3,     0,
       1,     0,     2,     1,     3,     1,     3,     1,     3,     0,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    { (yyval.doggy_type) = Create_doggy_doggy(make_post_src_info((yylsp[-4]).first_line, (yylsp[0]).last_line), (yyvsp[-4].OPT_Typedefs_type), (yyvsp[-3].machine_description_type), (yyvsp[-2].OPT_machine_description_type), (yyvsp[-1].OPT_externals_type), (yyvsp[0].OPTMORE_Section_type));
    Decorate_doggy((yyval.doggy_type));
  }

    break;

  case 3:

    {
    (yyval.Typedefs_type) = (yyvsp[0].OPTMORE_Typedef_type);
  }

    break;

  case 4:

    { (yyval.Typedef_type) = Create_doggy_Typedef(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-2].Identsym_type), (yyvsp[-1].OPT_Stringsym_Stringsym_Stringsym_type).f1, (yyvsp[-1].OPT_Stringsym_Stringsym_Stringsym_type).f2, (yyvsp[-1].OPT_Stringsym_Stringsym_Stringsym_type).f3, (yyvsp[0].OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_type));
  }

    break;

  case 5:

    {
    (yyval.externals_type) = (yyvsp[0].OPTMORE_FunctionDef_type);
  }

    break;

  case 6:

    { (yyval.FunctionDef_type) = Create_doggy_ExtFunc(make_post_src_info((yylsp[-4]).first_line, (yylsp[0]).last_line), (yyvsp[-3].Type_type), (yyvsp[-2].Identsym_type), (yyvsp[-1].ArgTypes_type));
  }

    break;

  case 7:

    { (yyval.FunctionDef_type) = Create_doggy_ExtVar(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-2].Type_type), (yyvsp[-1].Identsym_type));
  }

    break;

  case 8:

    { (yyval.machine_description_type) = Create_doggy_machine_description(make_post_src_info((yylsp[-4]).first_line, (yylsp[0]).last_line), (yyvsp[-2].Identsym_type), (yyvsp[-1].OPTMORE_Operation_def_type), (yyvsp[0].OPT_SUPPORTSsym_OPTMORE_Applied_formal_type));
  }

    break;

  case 9:

    { (yyval.Operation_def_type) = Create_doggy_Operation_def(make_post_src_info((yylsp[-7]).first_line, (yylsp[0]).last_line), (yyvsp[-7].Identsym_type), (yyvsp[-5].OPT_Types_type), (yyvsp[-3].OPT_colonsym_Type_type), (yyvsp[-2].Identsym_type), (yyvsp[-1].OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_type), (yyvsp[0].OPTMORE_Property_type));
  }

    break;

  case 10:

    { (yyval.Attributes_type) = Create_doggy_Attributes(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].OPT_Attrs_OPT_commasym_Attributes_type).f1, (yyvsp[0].OPT_Attrs_OPT_commasym_Attributes_type).f2);
  }

    break;

  case 11:

    {
    (yyval.Attrs_type) = (yyvsp[0].MORE_Attribute_type);
  }

    break;

  case 12:

    { (yyval.Attribute_type) = Create_doggy_IdAttr(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Identsym_type));
  }

    break;

  case 13:

    { (yyval.Attribute_type) = Create_doggy_OpAttr(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line));
  }

    break;

  case 14:

    { (yyval.Attribute_type) = Create_doggy_IntAttr(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Intsym_type));
  }

    break;

  case 15:

    { (yyval.Section_type) = Create_doggy_FuncSection(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Funcs_type));
  }

    break;

  case 16:

    { (yyval.Section_type) = Create_doggy_RuleSection(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Rules_type).f1, (yyvsp[0].Rules_type).f2);
  }

    break;

  case 17:

    {
    (yyval.Rules_type).f1 = (yyvsp[-1].OPT_colonsym_Identsym_type);
    (yyval.Rules_type).f2 = (yyvsp[0].OPTMORE_Rule_type);
  }

    break;

  case 18:

    { (yyval.Rule_type) = Create_doggy_Rule(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-2].Lhs_type), (yyvsp[-1].Rhs_type));
  }

    break;

  case 19:

    { (yyval.Lhs_type) = Create_doggy_LabeledLhs(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-2].Identsym_type), (yyvsp[0].UnTypedPattern_type));
  }

    break;

  case 20:

    { (yyval.Lhs_type) = Create_doggy_UnLabeledLhs(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].UnTypedPattern_type));
  }

    break;

  case 21:

    {
    (yyval.Funcs_type) = (yyvsp[0].OPTMORE_Func_type);
  }

    break;

  case 22:

    { (yyval.Func_type) = Create_doggy_Func(make_post_src_info((yylsp[-4]).first_line, (yylsp[0]).last_line), (yyvsp[-4].OPT_externsym_type), (yyvsp[-3].Type_type), (yyvsp[-2].Identsym_type), (yyvsp[-1].FuncRules_type));
  }

    break;

  case 23:

    {
    (yyval.FuncRules_type) = (yyvsp[0].ALT_FuncRule_SEP_commasym_type);
  }

    break;

  case 24:

    { (yyval.FuncRule_type) = Create_doggy_FuncRule(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-2].OPT_Arguments_type), (yyvsp[0].Rhs_type));
  }

    break;

  case 25:

    {
    (yyval.Arguments_type) = (yyvsp[0].ALT_Argument_SEP_commasym_type);
  }

    break;

  case 26:

    { (yyval.Argument_type) = Create_doggy_TypedArg(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-2].Type_type), (yyvsp[-1].Identsym_type), (yyvsp[0].ArgPat2_type));
  }

    break;

  case 27:

    { (yyval.Argument_type) = Create_doggy_UnTypedArg(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[-1].Identsym_type), (yyvsp[0].ArgPat2_type));
  }

    break;

  case 28:

    {
    (yyval.ArgPat2_type) = (yyvsp[0].PatArg1_type);
  }

    break;

  case 29:

    {
    (yyval.ArgPat2_type) = (yyvsp[0].ParArg_type);
  }

    break;

  case 30:

    {
    (yyval.ArgPat2_type) = (yyvsp[0].SetArg_type);
  }

    break;

  case 31:

    { (yyval.PatArg1_type) = PatArg1(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].OPT_equalssym_UnTypedPattern_type)); }

    break;

  case 32:

    { (yyval.ParArg_type) = ParArg(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].ParPattern_type)); }

    break;

  case 33:

    { (yyval.SetArg_type) = Create_doggy_SetArg(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[0].OpSet_type));
  }

    break;

  case 34:

    {
    (yyval.Pattern_type) = (yyvsp[0].UnTypedPattern_type);
  }

    break;

  case 35:

    { (yyval.Pattern_type) = Create_doggy_TypedPattern(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[-1].BasicType_type), (yyvsp[0].UnTypedPattern_type));
  }

    break;

  case 36:

    {
    (yyval.UnTypedPattern_type) = (yyvsp[0].SimplePattern_type);
  }

    break;

  case 37:

    {
    (yyval.UnTypedPattern_type) = (yyvsp[0].ConsPattern_type);
  }

    break;

  case 38:

    { (yyval.ConsPattern_type) = Create_doggy_ConsPattern(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-2].SimplePattern_type), (yyvsp[0].UnTypedPattern_type));
  }

    break;

  case 39:

    {
    (yyval.SimplePattern_type) = (yyvsp[0].IdentPattern_type);
  }

    break;

  case 40:

    {
    (yyval.SimplePattern_type) = (yyvsp[0].SingleDefPattern_type);
  }

    break;

  case 41:

    {
    (yyval.SimplePattern_type) = (yyvsp[0].DefPattern_type);
  }

    break;

  case 42:

    {
    (yyval.SimplePattern_type) = (yyvsp[0].IdParPattern_type);
  }

    break;

  case 43:

    {
    (yyval.SimplePattern_type) = (yyvsp[0].BinPattern_type);
  }

    break;

  case 44:

    { (yyval.DefPattern_type) = Create_doggy_DefPattern(make_post_src_info((yylsp[-4]).first_line, (yylsp[0]).last_line), (yyvsp[-3].IdentPatterns_type), (yyvsp[0].BinPattern_type));
  }

    break;

  case 45:

    { (yyval.IdentPattern_type) = Create_doggy_IdentPattern(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Identsym_type));
  }

    break;

  case 46:

    {
    (yyval.IdentPatterns_type) = (yyvsp[0].ALT_IdentPattern_SEP_commasym_type);
  }

    break;

  case 47:

    { (yyval.SingleDefPattern_type) = SingleDefPattern(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-2].Identsym_type), (yyvsp[0].BinPattern_type)); }

    break;

  case 48:

    { (yyval.IdParPattern_type) = IdParPattern(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[-1].Identsym_type), (yyvsp[0].ParPattern_type)); }

    break;

  case 49:

    { (yyval.BinPattern_type) = BinPattern(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[-1].BasicPattern_type), (yyvsp[0].OPT_IdOp_SimplePattern_type).f1, (yyvsp[0].OPT_IdOp_SimplePattern_type).f2); }

    break;

  case 50:

    { (yyval.BasicPattern_type) = Create_doggy_OpPattern(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-3].Applied_operation_type), (yyvsp[-1].OPT_Patterns_type));
  }

    break;

  case 51:

    { (yyval.BasicPattern_type) = Create_doggy_ConstPattern(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Intsym_type));
  }

    break;

  case 52:

    { (yyval.BasicPattern_type) = Create_doggy_NullPattern(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line));
  }

    break;

  case 53:

    { (yyval.BasicPattern_type) = Create_doggy_DontCarePattern(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[0].OPT_equalssym_SimpleExpr_type));
  }

    break;

  case 54:

    { (yyval.ParPattern_type) = ParPattern(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-1].Pattern_type)); }

    break;

  case 55:

    { (yyval.Rhs_type) = Create_doggy_PlainRhs(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].MORE_Guard_type));
  }

    break;

  case 56:

    { (yyval.Rhs_type) = Create_doggy_BlockRhs(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-2].Rhs_type), (yyvsp[0].OPT_Wherepart_type));
  }

    break;

  case 57:

    { (yyval.Guard_type) = Create_doggy_RhsGuard(make_post_src_info((yylsp[-5]).first_line, (yylsp[0]).last_line), (yyvsp[-4].Condition_type), (yyvsp[-2].Rhs_type), (yyvsp[0].OPT_Wherepart_type));
  }

    break;

  case 58:

    { (yyval.Guard_type) = Create_doggy_ExprGuard(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-3].OPT_verticalbarsym_Condition_type), (yyvsp[-1].ExprSeq_type), (yyvsp[0].OPT_Wherepart_type));
  }

    break;

  case 59:

    { (yyval.ExprSeq_type) = Create_doggy_OneExpr(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Expr_type));
  }

    break;

  case 60:

    { (yyval.ExprSeq_type) = Create_doggy_MoreExprs(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-1].Exprs_type));
  }

    break;

  case 61:

    { (yyval.Wherepart_type) = Create_doggy_Wherepart(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[0].OPTMORE_Definition_type));
  }

    break;

  case 62:

    { (yyval.Applied_operation_type) = Create_doggy_AnyOp(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line));
  }

    break;

  case 63:

    {
    (yyval.Applied_operation_type) = (yyvsp[0].OpSet_type);
  }

    break;

  case 64:

    { (yyval.Applied_operation_type) = Create_doggy_AppliedOp(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Applied_formal_type));
  }

    break;

  case 65:

    { (yyval.OpSet_type) = Create_doggy_OpSet(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-1].Applied_formals_type));
  }

    break;

  case 66:

    {
    (yyval.Applied_formals_type) = (yyvsp[0].ALT_Applied_formal_SEP_commasym_type);
  }

    break;

  case 67:

    { (yyval.Applied_formal_type) = Create_doggy_Applied_formal(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Identsym_type));
  }

    break;

  case 68:

    { (yyval.Expr_type) = Create_doggy_BinExpr(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].ALT_SimpleExpr_SEP_Operator_type).f1, (yyvsp[0].ALT_SimpleExpr_SEP_Operator_type).f2);
  }

    break;

  case 69:

    {
    (yyval.Expr_type) = (yyvsp[0].IdOpExpr_type);
  }

    break;

  case 70:

    {
    (yyval.Expr_type) = (yyvsp[0].ConsExpr_type);
  }

    break;

  case 71:

    { (yyval.IdOpExpr_type) = IdOpExpr(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-2].SimpleExpr_type), (yyvsp[-1].IdOp_type), (yyvsp[0].Expr_type)); }

    break;

  case 72:

    { (yyval.ConsExpr_type) = Create_doggy_ConsExpr(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-2].SimpleExpr_type), (yyvsp[0].Expr_type));
  }

    break;

  case 73:

    {
  }

    break;

  case 74:

    { (yyval.SimpleExpr_type) = Create_doggy_IdentExpr(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Identsym_type));
  }

    break;

  case 75:

    { (yyval.SimpleExpr_type) = Create_doggy_IfExpr(make_post_src_info((yylsp[-7]).first_line, (yylsp[0]).last_line), (yyvsp[-6].Condition_type), (yyvsp[-4].Expr_type), (yyvsp[-3].OPTMORE_ELSIFsym_Condition_THENsym_Expr_type).f1, (yyvsp[-3].OPTMORE_ELSIFsym_Condition_THENsym_Expr_type).f2, (yyvsp[-1].Expr_type));
  }

    break;

  case 76:

    { (yyval.SimpleExpr_type) = Create_doggy_ConstExpr(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Constant_type));
  }

    break;

  case 77:

    { (yyval.SimpleExpr_type) = Create_doggy_Operation(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-3].Identsym_type), (yyvsp[-1].OPT_Exprs_type));
  }

    break;

  case 78:

    { (yyval.SimpleExpr_type) = Create_doggy_ParExpr(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-1].Expr_type));
  }

    break;

  case 79:

    { (yyval.SimpleExpr_type) = Create_doggy_MonExpr(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[-1].MonOp_type), (yyvsp[0].SimpleExpr_type));
  }

    break;

  case 80:

    {
    (yyval.Condition_type) = (yyvsp[0].Expr_type);
  }

    break;

  case 81:

    { (yyval.Constant_type) = Create_doggy_IntConst(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Intsym_type));
  }

    break;

  case 82:

    { (yyval.Constant_type) = Create_doggy_BoolConst(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Boolsym_type));
  }

    break;

  case 83:

    { (yyval.Constant_type) = Create_doggy_StringConst(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Stringsym_type));
  }

    break;

  case 84:

    { (yyval.Constant_type) = Create_doggy_NullConst(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line));
  }

    break;

  case 85:

    { (yyval.Definition_type) = Create_doggy_Definition(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-3].Type_type), (yyvsp[-2].Identsym_type), (yyvsp[0].Expr_type));
  }

    break;

  case 86:

    { (yyval.Operator_type) = doggy_CandOp; }

    break;

  case 87:

    { (yyval.Operator_type) = doggy_CorOp; }

    break;

  case 88:

    { (yyval.Operator_type) = doggy_XorOp; }

    break;

  case 89:

    { (yyval.Operator_type) = doggy_EqOp; }

    break;

  case 90:

    { (yyval.Operator_type) = doggy_NeqOp; }

    break;

  case 91:

    { (yyval.Operator_type) = doggy_LEOp; }

    break;

  case 92:

    { (yyval.Operator_type) = doggy_GEOp; }

    break;

  case 93:

    { (yyval.Operator_type) = doggy_LTOp; }

    break;

  case 94:

    { (yyval.Operator_type) = doggy_GTOp; }

    break;

  case 95:

    { (yyval.Operator_type) = doggy_SLOp; }

    break;

  case 96:

    { (yyval.Operator_type) = doggy_SROp; }

    break;

  case 97:

    { (yyval.Operator_type) = doggy_DivOp; }

    break;

  case 98:

    { (yyval.Operator_type) = doggy_ModOp; }

    break;

  case 99:

    { (yyval.Operator_type) = doggy_MulOp; }

    break;

  case 100:

    { (yyval.Operator_type) = doggy_AndOp; }

    break;

  case 101:

    { (yyval.Operator_type) = doggy_AddOp; }

    break;

  case 102:

    { (yyval.Operator_type) = doggy_SubOp; }

    break;

  case 103:

    {
    (yyval.IdOp_type) = (yyvsp[0].Identsym_type);
  }

    break;

  case 104:

    { (yyval.MonOp_type) = doggy_NotOp; }

    break;

  case 105:

    { (yyval.MonOp_type) = doggy_NegOp; }

    break;

  case 106:

    { (yyval.MonOp_type) = doggy_AddrOp; }

    break;

  case 107:

    { (yyval.MonOp_type) = doggy_DerefOp; }

    break;

  case 108:

    { (yyval.MonOp_type) = doggy_PlusOp; }

    break;

  case 109:

    { (yyval.MonOp_type) = doggy_MinOp; }

    break;

  case 110:

    { (yyval.Type_type) = Create_doggy_EdgeType(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].ALT_BasicType_SEP_verticalbarsym_type));
  }

    break;

  case 111:

    { (yyval.Type_type) = Create_doggy_TupleType(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-1].OPT_Types_type));
  }

    break;

  case 112:

    { (yyval.BasicType_type) = Create_doggy_IdentType(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Identsym_type));
  }

    break;

  case 113:

    { (yyval.BasicType_type) = Create_doggy_OprType(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[0].OPT_ArgTypes_type));
  }

    break;

  case 114:

    { (yyval.BasicType_type) = Create_doggy_PointerType(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[-1].BasicType_type));
  }

    break;

  case 115:

    { (yyval.BasicType_type) = Create_doggy_RangeType(make_post_src_info((yylsp[-5]).first_line, (yylsp[0]).last_line), (yyvsp[-4].Num_type), (yyvsp[-2].Num_type), (yyvsp[-1].OPT_STEPsym_Num_type));
  }

    break;

  case 116:

    { (yyval.BasicType_type) = Create_doggy_FRangeType(make_post_src_info((yylsp[-4]).first_line, (yylsp[0]).last_line), (yyvsp[-3].Identsym_type));
  }

    break;

  case 117:

    { (yyval.Property_type) = FALSE; }

    break;

  case 118:

    {
    (yyval.ArgTypes_type) = (yyvsp[-1].OPT_Types_type);
  }

    break;

  case 119:

    {
    (yyval.Patterns_type) = (yyvsp[0].ALT_Pattern_SEP_commasym_type);
  }

    break;

  case 120:

    {
    (yyval.Exprs_type) = (yyvsp[0].ALT_Expr_SEP_commasym_type);
  }

    break;

  case 121:

    {
    (yyval.Types_type) = (yyvsp[0].ALT_Type_SEP_commasym_type);
  }

    break;

  case 122:

    { (yyval.Num_type) = Create_doggy_Num(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[-1].OPT_minussym_type), (yyvsp[0].Intsym_type));
  }

    break;

  case 123:

    {
    (yyval.OPT_Typedefs_type) = NULL;
  }

    break;

  case 124:

    {
    (yyval.OPT_Typedefs_type) = (yyvsp[0].Typedefs_type);
  }

    break;

  case 125:

    {
    (yyval.OPT_machine_description_type) = NULL;
  }

    break;

  case 126:

    {
    (yyval.OPT_machine_description_type) = (yyvsp[0].machine_description_type);
  }

    break;

  case 127:

    {
    (yyval.OPT_externals_type) = NULL;
  }

    break;

  case 128:

    {
    (yyval.OPT_externals_type) = (yyvsp[0].externals_type);
  }

    break;

  case 129:

    {
    (yyval.OPTMORE_Section_type) = NULL;
  }

    break;

  case 130:

    {
    (yyval.OPTMORE_Section_type) = Create_List_doggy_Section((yyvsp[-1].Section_type), (yyvsp[0].OPTMORE_Section_type));
  }

    break;

  case 131:

    {
    (yyval.OPTMORE_Typedef_type) = NULL;
  }

    break;

  case 132:

    {
    (yyval.OPTMORE_Typedef_type) = Create_List_doggy_Typedef((yyvsp[-1].Typedef_type), (yyvsp[0].OPTMORE_Typedef_type));
  }

    break;

  case 133:

    {
    (yyval.OPT_Stringsym_Stringsym_Stringsym_type).f1 = NULL;
    (yyval.OPT_Stringsym_Stringsym_Stringsym_type).f2 = NULL;
    (yyval.OPT_Stringsym_Stringsym_Stringsym_type).f3 = NULL;
  }

    break;

  case 134:

    {
    (yyval.OPT_Stringsym_Stringsym_Stringsym_type).f1 = (yyvsp[-2].Stringsym_type);
    (yyval.OPT_Stringsym_Stringsym_Stringsym_type).f2 = (yyvsp[-1].Stringsym_type);
    (yyval.OPT_Stringsym_Stringsym_Stringsym_type).f3 = (yyvsp[0].Stringsym_type);
  }

    break;

  case 135:

    {
    (yyval.OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_type) = NULL;
  }

    break;

  case 136:

    {
    (yyval.OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_type) = (yyvsp[-1].Attributes_type);
  }

    break;

  case 137:

    {
    (yyval.OPTMORE_FunctionDef_type) = NULL;
  }

    break;

  case 138:

    {
    (yyval.OPTMORE_FunctionDef_type) = Create_List_doggy_FunctionDef((yyvsp[-1].FunctionDef_type), (yyvsp[0].OPTMORE_FunctionDef_type));
  }

    break;

  case 139:

    {
    (yyval.OPTMORE_Operation_def_type) = NULL;
  }

    break;

  case 140:

    {
    (yyval.OPTMORE_Operation_def_type) = Create_List_doggy_Operation_def((yyvsp[-1].Operation_def_type), (yyvsp[0].OPTMORE_Operation_def_type));
  }

    break;

  case 141:

    {
    (yyval.OPT_SUPPORTSsym_OPTMORE_Applied_formal_type) = NULL;
  }

    break;

  case 142:

    {
    (yyval.OPT_SUPPORTSsym_OPTMORE_Applied_formal_type) = (yyvsp[0].OPTMORE_Applied_formal_type);
  }

    break;

  case 143:

    {
    (yyval.OPTMORE_Applied_formal_type) = NULL;
  }

    break;

  case 144:

    {
    (yyval.OPTMORE_Applied_formal_type) = Create_List_doggy_Applied_formal((yyvsp[-1].Applied_formal_type), (yyvsp[0].OPTMORE_Applied_formal_type));
  }

    break;

  case 145:

    {
    (yyval.OPT_Types_type) = NULL;
  }

    break;

  case 146:

    {
    (yyval.OPT_Types_type) = (yyvsp[0].Types_type);
  }

    break;

  case 147:

    {
    (yyval.OPT_colonsym_Type_type) = NULL;
  }

    break;

  case 148:

    {
    (yyval.OPT_colonsym_Type_type) = (yyvsp[0].Type_type);
  }

    break;

  case 149:

    {
    (yyval.OPTMORE_Property_type) = NULL;
  }

    break;

  case 150:

    {
    (yyval.OPTMORE_Property_type) = Create_List_doggy_Property((yyvsp[-1].Property_type), (yyvsp[0].OPTMORE_Property_type));
  }

    break;

  case 151:

    {
    (yyval.OPT_Attrs_OPT_commasym_Attributes_type).f1 = NULL;
    (yyval.OPT_Attrs_OPT_commasym_Attributes_type).f2 = NULL;
  }

    break;

  case 152:

    {
    (yyval.OPT_Attrs_OPT_commasym_Attributes_type).f1 = (yyvsp[-1].Attrs_type);
    (yyval.OPT_Attrs_OPT_commasym_Attributes_type).f2 = (yyvsp[0].OPT_commasym_Attributes_type);
  }

    break;

  case 153:

    {
    (yyval.OPT_commasym_Attributes_type) = NULL;
  }

    break;

  case 154:

    {
    (yyval.OPT_commasym_Attributes_type) = (yyvsp[0].Attributes_type);
  }

    break;

  case 155:

    {
    (yyval.MORE_Attribute_type) = Create_List_doggy_Attribute((yyvsp[0].Attribute_type), NULL);
  }

    break;

  case 156:

    {
    (yyval.MORE_Attribute_type) = Create_List_doggy_Attribute((yyvsp[-1].Attribute_type), (yyvsp[0].MORE_Attribute_type));
  }

    break;

  case 157:

    {
    (yyval.OPT_colonsym_Identsym_type) = NULL;
  }

    break;

  case 158:

    {
    (yyval.OPT_colonsym_Identsym_type) = (yyvsp[0].Identsym_type);
  }

    break;

  case 159:

    {
    (yyval.OPTMORE_Rule_type) = NULL;
  }

    break;

  case 160:

    {
    (yyval.OPTMORE_Rule_type) = Create_List_doggy_Rule((yyvsp[-1].Rule_type), (yyvsp[0].OPTMORE_Rule_type));
  }

    break;

  case 161:

    {
    (yyval.OPTMORE_Func_type) = NULL;
  }

    break;

  case 162:

    {
    (yyval.OPTMORE_Func_type) = Create_List_doggy_Func((yyvsp[-1].Func_type), (yyvsp[0].OPTMORE_Func_type));
  }

    break;

  case 163:

    {
    (yyval.OPT_externsym_type) = FALSE;
  }

    break;

  case 164:

    {
    (yyval.OPT_externsym_type) = TRUE;
  }

    break;

  case 165:

    {
    (yyval.ALT_FuncRule_SEP_commasym_type) = Create_List_doggy_FuncRule((yyvsp[0].FuncRule_type), NULL);
  }

    break;

  case 166:

    {
    (yyval.ALT_FuncRule_SEP_commasym_type) = Create_List_doggy_FuncRule((yyvsp[-2].FuncRule_type), (yyvsp[0].ALT_FuncRule_SEP_commasym_type));
  }

    break;

  case 167:

    {
    (yyval.OPT_Arguments_type) = NULL;
  }

    break;

  case 168:

    {
    (yyval.OPT_Arguments_type) = (yyvsp[0].Arguments_type);
  }

    break;

  case 169:

    {
    (yyval.ALT_Argument_SEP_commasym_type) = Create_List_doggy_Argument((yyvsp[0].Argument_type), NULL);
  }

    break;

  case 170:

    {
    (yyval.ALT_Argument_SEP_commasym_type) = Create_List_doggy_Argument((yyvsp[-2].Argument_type), (yyvsp[0].ALT_Argument_SEP_commasym_type));
  }

    break;

  case 171:

    {
    (yyval.OPT_equalssym_UnTypedPattern_type) = NULL;
  }

    break;

  case 172:

    {
    (yyval.OPT_equalssym_UnTypedPattern_type) = (yyvsp[0].UnTypedPattern_type);
  }

    break;

  case 173:

    {
    (yyval.ALT_IdentPattern_SEP_commasym_type) = Create_List_doggy_Pattern((yyvsp[0].IdentPattern_type), NULL);
  }

    break;

  case 174:

    {
    (yyval.ALT_IdentPattern_SEP_commasym_type) = Create_List_doggy_Pattern((yyvsp[-2].IdentPattern_type), (yyvsp[0].ALT_IdentPattern_SEP_commasym_type));
  }

    break;

  case 175:

    {
    (yyval.OPT_IdOp_SimplePattern_type).f1 = NULL;
    (yyval.OPT_IdOp_SimplePattern_type).f2 = NULL;
  }

    break;

  case 176:

    {
    (yyval.OPT_IdOp_SimplePattern_type).f1 = (yyvsp[-1].IdOp_type);
    (yyval.OPT_IdOp_SimplePattern_type).f2 = (yyvsp[0].SimplePattern_type);
  }

    break;

  case 177:

    {
    (yyval.OPT_Patterns_type) = NULL;
  }

    break;

  case 178:

    {
    (yyval.OPT_Patterns_type) = (yyvsp[0].Patterns_type);
  }

    break;

  case 179:

    {
    (yyval.OPT_equalssym_SimpleExpr_type) = NULL;
  }

    break;

  case 180:

    {
    (yyval.OPT_equalssym_SimpleExpr_type) = (yyvsp[0].SimpleExpr_type);
  }

    break;

  case 181:

    {
    (yyval.MORE_Guard_type) = Create_List_doggy_Guard((yyvsp[0].Guard_type), NULL);
  }

    break;

  case 182:

    {
    (yyval.MORE_Guard_type) = Create_List_doggy_Guard((yyvsp[-1].Guard_type), (yyvsp[0].MORE_Guard_type));
  }

    break;

  case 183:

    {
    (yyval.OPT_Wherepart_type) = NULL;
  }

    break;

  case 184:

    {
    (yyval.OPT_Wherepart_type) = (yyvsp[0].Wherepart_type);
  }

    break;

  case 185:

    {
    (yyval.OPT_verticalbarsym_Condition_type) = NULL;
  }

    break;

  case 186:

    {
    (yyval.OPT_verticalbarsym_Condition_type) = (yyvsp[0].Condition_type);
  }

    break;

  case 187:

    {
    (yyval.OPTMORE_Definition_type) = NULL;
  }

    break;

  case 188:

    {
    (yyval.OPTMORE_Definition_type) = Create_List_doggy_Definition((yyvsp[-1].Definition_type), (yyvsp[0].OPTMORE_Definition_type));
  }

    break;

  case 189:

    {
    (yyval.ALT_Applied_formal_SEP_commasym_type) = Create_List_doggy_Applied_formal((yyvsp[0].Applied_formal_type), NULL);
  }

    break;

  case 190:

    {
    (yyval.ALT_Applied_formal_SEP_commasym_type) = Create_List_doggy_Applied_formal((yyvsp[-2].Applied_formal_type), (yyvsp[0].ALT_Applied_formal_SEP_commasym_type));
  }

    break;

  case 191:

    {
    (yyval.ALT_SimpleExpr_SEP_Operator_type).f1 = Create_List_doggy_Expr((yyvsp[0].SimpleExpr_type), NULL);
    (yyval.ALT_SimpleExpr_SEP_Operator_type).f2 = NULL;
  }

    break;

  case 192:

    {
    (yyval.ALT_SimpleExpr_SEP_Operator_type).f1 = Create_List_doggy_Expr((yyvsp[-2].SimpleExpr_type), (yyvsp[0].ALT_SimpleExpr_SEP_Operator_type).f1);
    (yyval.ALT_SimpleExpr_SEP_Operator_type).f2 = Create_List_doggy_Operator((yyvsp[-1].Operator_type), (yyvsp[0].ALT_SimpleExpr_SEP_Operator_type).f2);
  }

    break;

  case 193:

    {
    (yyval.OPTMORE_ELSIFsym_Condition_THENsym_Expr_type).f1 = NULL;
    (yyval.OPTMORE_ELSIFsym_Condition_THENsym_Expr_type).f2 = NULL;
  }

    break;

  case 194:

    {
    (yyval.OPTMORE_ELSIFsym_Condition_THENsym_Expr_type).f1 = Create_List_doggy_Expr((yyvsp[-3].Condition_type), (yyvsp[0].OPTMORE_ELSIFsym_Condition_THENsym_Expr_type).f1);
    (yyval.OPTMORE_ELSIFsym_Condition_THENsym_Expr_type).f2 = Create_List_doggy_Expr((yyvsp[-1].Expr_type), (yyvsp[0].OPTMORE_ELSIFsym_Condition_THENsym_Expr_type).f2);
  }

    break;

  case 195:

    {
    (yyval.OPT_Exprs_type) = NULL;
  }

    break;

  case 196:

    {
    (yyval.OPT_Exprs_type) = (yyvsp[0].Exprs_type);
  }

    break;

  case 197:

    {
    (yyval.ALT_BasicType_SEP_verticalbarsym_type) = Create_List_doggy_Type((yyvsp[0].BasicType_type), NULL);
  }

    break;

  case 198:

    {
    (yyval.ALT_BasicType_SEP_verticalbarsym_type) = Create_List_doggy_Type((yyvsp[-2].BasicType_type), (yyvsp[0].ALT_BasicType_SEP_verticalbarsym_type));
  }

    break;

  case 199:

    {
    (yyval.OPT_ArgTypes_type) = NULL;
  }

    break;

  case 200:

    {
    (yyval.OPT_ArgTypes_type) = (yyvsp[0].ArgTypes_type);
  }

    break;

  case 201:

    {
    (yyval.OPT_STEPsym_Num_type) = NULL;
  }

    break;

  case 202:

    {
    (yyval.OPT_STEPsym_Num_type) = (yyvsp[0].Num_type);
  }

    break;

  case 203:

    {
    (yyval.ALT_Pattern_SEP_commasym_type) = Create_List_doggy_Pattern((yyvsp[0].Pattern_type), NULL);
  }

    break;

  case 204:

    {
    (yyval.ALT_Pattern_SEP_commasym_type) = Create_List_doggy_Pattern((yyvsp[-2].Pattern_type), (yyvsp[0].ALT_Pattern_SEP_commasym_type));
  }

    break;

  case 205:

    {
    (yyval.ALT_Expr_SEP_commasym_type) = Create_List_doggy_Expr((yyvsp[0].Expr_type), NULL);
  }

    break;

  case 206:

    {
    (yyval.ALT_Expr_SEP_commasym_type) = Create_List_doggy_Expr((yyvsp[-2].Expr_type), (yyvsp[0].ALT_Expr_SEP_commasym_type));
  }

    break;

  case 207:

    {
    (yyval.ALT_Type_SEP_commasym_type) = Create_List_doggy_Type((yyvsp[0].Type_type), NULL);
  }

    break;

  case 208:

    {
    (yyval.ALT_Type_SEP_commasym_type) = Create_List_doggy_Type((yyvsp[-2].Type_type), (yyvsp[0].ALT_Type_SEP_commasym_type));
  }

    break;

  case 209:

    {
    (yyval.OPT_minussym_type) = FALSE;
  }

    break;

  case 210:

    {
    (yyval.OPT_minussym_type) = TRUE;
  }

    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
