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
#define yyparse         egg_parse
#define yylex           egg_lex
#define yyerror         egg_error
#define yydebug         egg_debug
#define yynerrs         egg_nerrs

#define yylval          egg_lval
#define yychar          egg_char
#define yylloc          egg_lloc

/* Copy the first part of user declarations.  */


#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "egg.h"

extern int input_line_nr;

struct yy_buffer_state *egg_dummy_state (void);
struct yy_buffer_state *egg_scanner_state (void);



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
   by #include "egg_y.h".  */
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
#define YYFINAL  106
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   158,   158,   166,   174,   182,   190,   199,   205,   214,
     220,   228,   236,   243,   250,   256,   262,   268,   274,   280,
     289,   297,   304,   319,   325,   333,   340,   349,   355,   363,
     370,   378,   385,   394,   400,   408,   414,   421,   428,   437,
     443,   452,   458,   465,   470,   476,   481,   487,   492,   498,
     503,   509,   514,   520,   525,   531,   536,   542,   547,   553,
     558,   564,   569,   575,   580,   586,   591,   597,   602,   608,
     613,   619,   624,   630,   635,   641,   646,   652,   657,   663,
     668,   674,   679,   685,   690,   696,   701,   707,   712,   718,
     723
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NONSENSE", "usessym", "commasym",
  "semicolonsym", "fatalsym", "errorsym", "warningsym", "disabledsym",
  "keysym", "postsym", "openparsym", "closeparsym", "groupsym",
  "openchainsym", "equalssym", "closechainsym", "commentsym", "Stringsym",
  "Identsym", "hole_egg", "start_egg", "hole_Uses", "start_Uses",
  "hole_Strings", "start_Strings", "hole_Declarations",
  "start_Declarations", "hole_Declaration", "start_Declaration",
  "hole_Expression", "start_Expression", "hole_Params", "start_Params",
  "hole_Statements", "start_Statements", "hole_Statement",
  "start_Statement", "hole_MessageKind", "start_MessageKind",
  "hole_Message", "start_Message", "hole_SubMessages", "start_SubMessages",
  "hole_SubMessage", "start_SubMessage", "hole_Group", "start_Group",
  "hole_OPTMORE_Group", "start_OPTMORE_Group",
  "hole_ALT_Stringsym_SEP_commasym", "start_ALT_Stringsym_SEP_commasym",
  "hole_OPTMORE_Declaration", "start_OPTMORE_Declaration",
  "hole_MORE_Expression", "start_MORE_Expression",
  "hole_ALT_Expression_SEP_commasym", "start_ALT_Expression_SEP_commasym",
  "hole_OPTMORE_Statement", "start_OPTMORE_Statement", "hole_OPT_fatalsym",
  "start_OPT_fatalsym", "hole_ALT_SubMessage_SEP_commasym",
  "start_ALT_SubMessage_SEP_commasym",
  "hole_OPT_openparsym_Identsym_closeparsym",
  "start_OPT_openparsym_Identsym_closeparsym", "hole_OPT_groupsym",
  "start_OPT_groupsym", "$accept", "egg", "Uses", "Strings",
  "Declarations", "Declaration", "Expression", "Params", "Statements",
  "Statement", "MessageKind", "Message", "SubMessages", "SubMessage",
  "Group", "OPTMORE_Group", "ALT_Stringsym_SEP_commasym",
  "OPTMORE_Declaration", "MORE_Expression", "ALT_Expression_SEP_commasym",
  "OPTMORE_Statement", "OPT_fatalsym", "ALT_SubMessage_SEP_commasym",
  "OPT_openparsym_Identsym_closeparsym", "OPT_groupsym", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

#define YYPACT_NINF -25

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-25)))

#define YYTABLE_NINF -36

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      86,     2,   -25,    86,   -25,    36,     2,   154,   202,   138,
     171,    76,    13,   228,    14,    22,   178,     9,   123,     7,
     166,   148,   177,   119,     3,    27,    -2,    33,    23,   123,
      21,   -25,   -25,    43,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   166,    35,
     -25,   -25,   -25,    37,   -25,   -25,   -25,   -25,    58,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   119,
     -25,   -25,   -25,    51,   -25,   -25,   -25,    56,   -25,   -25,
     -25,    61,   -25,    77,   -25,   -25,   -25,    63,   -25,   123,
     -25,   -25,   -25,   -25,   148,   -25,   -25,   -25,   -25,   -25,
      64,   -25,   -25,   -25,   -25,   -25,   -25,   -25,     7,   -25,
     -25,   148,   171,   177,   -25,    34,    22,   -25,    27,    -2,
     -25,   -25,    78,   -25,    88,    85,   -25,    96,    33,   -25,
     -25,   -25,   -25,   -25,    87,   154,    76,    89,   -25
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    43,     0,    45,     0,     0,    27,     0,     0,
       0,    33,    35,     0,    35,     0,     0,    35,    23,     0,
      27,     0,     0,    33,    35,     0,    39,    41,     0,    23,
      25,    47,    73,     0,     4,    44,    46,    48,    14,    15,
      16,    17,    18,    49,    51,    61,    75,    50,    27,     0,
       5,    52,     7,     9,    53,    54,    55,    79,    31,    56,
      10,    36,    57,    59,    63,    69,    81,    83,    58,    33,
      12,    13,    11,     0,    60,    62,    64,     0,    65,    67,
      85,     0,    66,    37,    20,    68,    70,     0,    71,    23,
      72,    74,    76,    77,    29,    78,    80,    82,    84,    86,
       0,    87,    88,    42,    89,    90,     1,     2,     0,     3,
      28,     0,     0,     0,    34,    39,     0,    21,     0,    39,
      24,    30,     0,    26,     0,     0,    32,     0,    41,    38,
      40,     6,     8,    19,     0,    27,    33,     0,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -25,   101,   111,   100,   -13,   112,    -6,    20,     6,   122,
      -7,   132,   133,   134,   -10,   -20,   -15,     5,   -24,   -17,
     -11,     0,   -23,   126,    26
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    33,    47,    48,    58,    59,    68,    69,
      81,    70,   127,    83,    71,    90,    34,    50,    95,    60,
      72,    73,    84,   128,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    49,    99,    55,    91,    96,    75,    86,    89,   107,
      61,   100,    97,    49,    77,    94,    61,    87,    87,    89,
      61,    61,    30,   106,    98,    92,   108,    30,    31,    87,
      38,    39,    40,    41,    42,    38,    39,    40,    41,    42,
       1,    49,    38,    39,    40,    41,    42,   100,   103,   109,
     112,    63,   111,   110,    32,    64,    64,    65,   114,    32,
       4,    65,    45,   113,   101,    67,    78,    45,    79,   120,
     121,    67,   115,    79,    45,    67,    67,   116,    78,    89,
      79,   117,   118,    61,   119,   122,    80,   124,    94,    87,
       1,    80,   130,   123,   131,   129,   126,   -35,    80,   132,
     101,   104,   133,   135,    35,    94,    37,   138,     2,     3,
       4,     5,    62,     6,    63,     7,    36,     8,    64,     9,
      51,    10,   136,    11,    65,    12,    61,    13,    49,    14,
      61,    15,   125,    16,    74,    17,    66,    18,    67,    19,
     -35,    20,   137,    21,   -35,    22,    76,    23,    82,    24,
      85,    25,   102,    26,   134,    27,     0,    63,    52,    53,
       0,    64,    38,    39,    40,    41,    42,    65,    52,    53,
      54,    65,     0,    88,    38,    39,    40,    41,    42,    66,
      54,    67,    43,     0,    44,    67,    38,    39,    40,    41,
      42,    52,    53,     0,    45,     0,    44,    52,    53,     0,
       0,     0,     0,    54,    93,    56,    45,     0,    46,    54,
      38,    39,    40,    41,    42,     0,     0,     0,    45,     0,
      46,     0,     0,     0,    79,     0,     0,     0,     0,    57,
       0,     0,    44,     0,     0,    57,    38,    39,    40,    41,
      42,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45
};

static const yytype_int16 yycheck[] =
{
       7,     8,    25,     9,    19,    22,    13,    17,    18,    29,
       7,    13,    23,    20,    14,    21,     7,    17,    18,    29,
       7,     7,    20,     0,    24,    20,     5,    20,    26,    29,
       8,     9,    10,    11,    12,     8,     9,    10,    11,    12,
       4,    48,     8,     9,    10,    11,    12,    13,    15,     6,
      13,    38,    17,    48,    52,    42,    42,    48,    69,    52,
      24,    48,    40,     5,    66,    62,    44,    40,    46,    89,
      94,    62,    21,    46,    40,    62,    62,    21,    44,    89,
      46,    20,     5,     7,    21,    21,    64,   111,    94,    89,
       4,    64,    14,   108,     6,   118,   113,    21,    64,    14,
      66,    68,     6,    16,     3,   111,     6,    18,    22,    23,
      24,    25,    36,    27,    38,    29,     5,    31,    42,    33,
       8,    35,   135,    37,    48,    39,     7,    41,   135,    43,
       7,    45,   112,    47,    12,    49,    60,    51,    62,    53,
      21,    55,   136,    57,    21,    59,    14,    61,    15,    63,
      16,    65,    26,    67,   128,    69,    -1,    38,    20,    21,
      -1,    42,     8,     9,    10,    11,    12,    48,    20,    21,
      32,    48,    -1,    50,     8,     9,    10,    11,    12,    60,
      32,    62,    28,    -1,    30,    62,     8,     9,    10,    11,
      12,    20,    21,    -1,    40,    -1,    30,    20,    21,    -1,
      -1,    -1,    -1,    32,    56,    34,    40,    -1,    54,    32,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    40,    -1,
      54,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    30,    -1,    -1,    58,     8,     9,    10,    11,
      12,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    22,    23,    24,    25,    27,    29,    31,    33,
      35,    37,    39,    41,    43,    45,    47,    49,    51,    53,
      55,    57,    59,    61,    63,    65,    67,    69,    71,    72,
      20,    26,    52,    73,    86,    71,    72,    73,     8,     9,
      10,    11,    12,    28,    30,    40,    54,    74,    75,    80,
      87,    75,    20,    21,    32,    76,    34,    58,    76,    77,
      89,     7,    36,    38,    42,    48,    60,    62,    78,    79,
      81,    84,    90,    91,    79,    80,    81,    91,    44,    46,
      64,    80,    82,    83,    92,    83,    84,    91,    50,    84,
      85,    86,    87,    56,    76,    88,    89,    90,    91,    92,
      13,    66,    93,    15,    68,    94,     0,    85,     5,     6,
      87,    17,    13,     5,    90,    21,    21,    20,     5,    21,
      85,    88,    21,    86,    88,    77,    89,    82,    93,    92,
      14,     6,    14,     6,    94,    16,    74,    78,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    73,    74,    75,    76,    76,    76,
      77,    78,    79,    79,    80,    80,    80,    80,    80,    81,
      82,    83,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    71,    71,    72,    71,    73,    71,    74,
      71,    75,    71,    76,    71,    77,    71,    78,    71,    79,
      71,    80,    71,    81,    71,    82,    71,    83,    71,    84,
      71,    85,    71,    86,    71,    87,    71,    88,    71,    89,
      71,    90,    71,    91,    71,    92,    71,    93,    71,    94,
      71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     1,     4,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     2,     8,     0,     2,     1,     3,     0,     2,     1,
       2,     1,     3,     0,     2,     0,     1,     1,     3,     0,
       3,     0,     1,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2
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

    { (yyval.egg_type) = Create_egg_egg(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[-1].Uses_type), (yyvsp[0].OPTMORE_Group_type));
    Decorate_egg((yyval.egg_type));
  }

    break;

  case 3:

    { (yyval.Uses_type) = Create_egg_Uses(make_post_src_info((yylsp[-2]).first_line, (yylsp[0]).last_line), (yyvsp[-1].Strings_type));
  }

    break;

  case 4:

    {
    (yyval.Strings_type) = (yyvsp[0].ALT_Stringsym_SEP_commasym_type);
  }

    break;

  case 5:

    {
    (yyval.Declarations_type) = (yyvsp[0].OPTMORE_Declaration_type);
  }

    break;

  case 6:

    { (yyval.Declaration_type) = Create_egg_Declaration(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-3].MessageKind_type), (yyvsp[-1].MORE_Expression_type));
  }

    break;

  case 7:

    { (yyval.Expression_type) = Create_egg_StringExpr(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Stringsym_type));
  }

    break;

  case 8:

    { (yyval.Expression_type) = Create_egg_CallExpr(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-3].Identsym_type), (yyvsp[-1].Params_type));
  }

    break;

  case 9:

    { (yyval.Expression_type) = Create_egg_IdExpr(make_post_src_info((yylsp[0]).first_line, (yylsp[0]).last_line), (yyvsp[0].Identsym_type));
  }

    break;

  case 10:

    {
    (yyval.Params_type) = (yyvsp[0].ALT_Expression_SEP_commasym_type);
  }

    break;

  case 11:

    {
    (yyval.Statements_type) = (yyvsp[0].OPTMORE_Statement_type);
  }

    break;

  case 12:

    {
    (yyval.Statement_type) = (yyvsp[0].Message_type);
  }

    break;

  case 13:

    {
    (yyval.Statement_type) = (yyvsp[0].Group_type);
  }

    break;

  case 14:

    { (yyval.MessageKind_type) = egg_ErrorMsg; }

    break;

  case 15:

    { (yyval.MessageKind_type) = egg_WarningMsg; }

    break;

  case 16:

    { (yyval.MessageKind_type) = egg_DisabledMsg; }

    break;

  case 17:

    { (yyval.MessageKind_type) = egg_KeyMsg; }

    break;

  case 18:

    { (yyval.MessageKind_type) = egg_PostMsg; }

    break;

  case 19:

    { (yyval.Message_type) = Create_egg_Message(make_post_src_info((yylsp[-3]).first_line, (yylsp[0]).last_line), (yyvsp[-3].OPT_fatalsym_type), (yyvsp[-2].Identsym_type), (yyvsp[-1].SubMessages_type));
  }

    break;

  case 20:

    {
    (yyval.SubMessages_type) = (yyvsp[0].ALT_SubMessage_SEP_commasym_type);
  }

    break;

  case 21:

    { (yyval.SubMessage_type) = Create_egg_SubMessage(make_post_src_info((yylsp[-1]).first_line, (yylsp[0]).last_line), (yyvsp[-1].MessageKind_type), (yyvsp[0].Stringsym_type));
  }

    break;

  case 22:

    { (yyval.Group_type) = Create_egg_Group(make_post_src_info((yylsp[-7]).first_line, (yylsp[0]).last_line), (yyvsp[-7].OPT_fatalsym_type), (yyvsp[-6].Identsym_type), (yyvsp[-5].OPT_openparsym_Identsym_closeparsym_type), (yyvsp[-4].OPT_groupsym_type), (yyvsp[-2].Declarations_type), (yyvsp[-1].Statements_type));
  }

    break;

  case 23:

    {
    (yyval.OPTMORE_Group_type) = NULL;
  }

    break;

  case 24:

    {
    (yyval.OPTMORE_Group_type) = Create_List_egg_Statement((yyvsp[-1].Group_type), (yyvsp[0].OPTMORE_Group_type));
  }

    break;

  case 25:

    {
    (yyval.ALT_Stringsym_SEP_commasym_type) = Create_List_String((yyvsp[0].Stringsym_type), NULL);
  }

    break;

  case 26:

    {
    (yyval.ALT_Stringsym_SEP_commasym_type) = Create_List_String((yyvsp[-2].Stringsym_type), (yyvsp[0].ALT_Stringsym_SEP_commasym_type));
  }

    break;

  case 27:

    {
    (yyval.OPTMORE_Declaration_type) = NULL;
  }

    break;

  case 28:

    {
    (yyval.OPTMORE_Declaration_type) = Create_List_egg_Declaration((yyvsp[-1].Declaration_type), (yyvsp[0].OPTMORE_Declaration_type));
  }

    break;

  case 29:

    {
    (yyval.MORE_Expression_type) = Create_List_egg_Expression((yyvsp[0].Expression_type), NULL);
  }

    break;

  case 30:

    {
    (yyval.MORE_Expression_type) = Create_List_egg_Expression((yyvsp[-1].Expression_type), (yyvsp[0].MORE_Expression_type));
  }

    break;

  case 31:

    {
    (yyval.ALT_Expression_SEP_commasym_type) = Create_List_egg_Expression((yyvsp[0].Expression_type), NULL);
  }

    break;

  case 32:

    {
    (yyval.ALT_Expression_SEP_commasym_type) = Create_List_egg_Expression((yyvsp[-2].Expression_type), (yyvsp[0].ALT_Expression_SEP_commasym_type));
  }

    break;

  case 33:

    {
    (yyval.OPTMORE_Statement_type) = NULL;
  }

    break;

  case 34:

    {
    (yyval.OPTMORE_Statement_type) = Create_List_egg_Statement((yyvsp[-1].Statement_type), (yyvsp[0].OPTMORE_Statement_type));
  }

    break;

  case 35:

    {
    (yyval.OPT_fatalsym_type) = FALSE;
  }

    break;

  case 36:

    {
    (yyval.OPT_fatalsym_type) = TRUE;
  }

    break;

  case 37:

    {
    (yyval.ALT_SubMessage_SEP_commasym_type) = Create_List_egg_SubMessage((yyvsp[0].SubMessage_type), NULL);
  }

    break;

  case 38:

    {
    (yyval.ALT_SubMessage_SEP_commasym_type) = Create_List_egg_SubMessage((yyvsp[-2].SubMessage_type), (yyvsp[0].ALT_SubMessage_SEP_commasym_type));
  }

    break;

  case 39:

    {
    (yyval.OPT_openparsym_Identsym_closeparsym_type) = NULL;
  }

    break;

  case 40:

    {
    (yyval.OPT_openparsym_Identsym_closeparsym_type) = (yyvsp[-1].Identsym_type);
  }

    break;

  case 41:

    {
    (yyval.OPT_groupsym_type) = FALSE;
  }

    break;

  case 42:

    {
    (yyval.OPT_groupsym_type) = TRUE;
  }

    break;

  case 43:

    { (yyval.egg_type) = (egg_egg)Get_sub_tree (); }

    break;

  case 44:

    { egg_multi_action ((void*)(yyvsp[0].egg_type)); YYACCEPT; }

    break;

  case 45:

    { (yyval.Uses_type) = (egg_Uses)Get_sub_tree (); }

    break;

  case 46:

    { egg_multi_action ((void*)(yyvsp[0].Uses_type)); YYACCEPT; }

    break;

  case 47:

    { (yyval.Strings_type) = (List_String)Get_sub_tree (); }

    break;

  case 48:

    { egg_multi_action ((void*)(yyvsp[0].Strings_type)); YYACCEPT; }

    break;

  case 49:

    { (yyval.Declarations_type) = (List_egg_Declaration)Get_sub_tree (); }

    break;

  case 50:

    { egg_multi_action ((void*)(yyvsp[0].Declarations_type)); YYACCEPT; }

    break;

  case 51:

    { (yyval.Declaration_type) = (egg_Declaration)Get_sub_tree (); }

    break;

  case 52:

    { egg_multi_action ((void*)(yyvsp[0].Declaration_type)); YYACCEPT; }

    break;

  case 53:

    { (yyval.Expression_type) = (egg_Expression)Get_sub_tree (); }

    break;

  case 54:

    { egg_multi_action ((void*)(yyvsp[0].Expression_type)); YYACCEPT; }

    break;

  case 55:

    { (yyval.Params_type) = (List_egg_Expression)Get_sub_tree (); }

    break;

  case 56:

    { egg_multi_action ((void*)(yyvsp[0].Params_type)); YYACCEPT; }

    break;

  case 57:

    { (yyval.Statements_type) = (List_egg_Statement)Get_sub_tree (); }

    break;

  case 58:

    { egg_multi_action ((void*)(yyvsp[0].Statements_type)); YYACCEPT; }

    break;

  case 59:

    { (yyval.Statement_type) = (egg_Statement)Get_sub_tree (); }

    break;

  case 60:

    { egg_multi_action ((void*)(yyvsp[0].Statement_type)); YYACCEPT; }

    break;

  case 61:

    { (yyval.MessageKind_type) = (egg_MessageKind)Get_sub_tree (); }

    break;

  case 62:

    { egg_multi_action ((void*)(yyvsp[0].MessageKind_type)); YYACCEPT; }

    break;

  case 63:

    { (yyval.Message_type) = (egg_Statement)Get_sub_tree (); }

    break;

  case 64:

    { egg_multi_action ((void*)(yyvsp[0].Message_type)); YYACCEPT; }

    break;

  case 65:

    { (yyval.SubMessages_type) = (List_egg_SubMessage)Get_sub_tree (); }

    break;

  case 66:

    { egg_multi_action ((void*)(yyvsp[0].SubMessages_type)); YYACCEPT; }

    break;

  case 67:

    { (yyval.SubMessage_type) = (egg_SubMessage)Get_sub_tree (); }

    break;

  case 68:

    { egg_multi_action ((void*)(yyvsp[0].SubMessage_type)); YYACCEPT; }

    break;

  case 69:

    { (yyval.Group_type) = (egg_Statement)Get_sub_tree (); }

    break;

  case 70:

    { egg_multi_action ((void*)(yyvsp[0].Group_type)); YYACCEPT; }

    break;

  case 71:

    { (yyval.OPTMORE_Group_type) = (List_egg_Statement)Get_sub_tree (); }

    break;

  case 72:

    { egg_multi_action ((void*)(yyvsp[0].OPTMORE_Group_type)); YYACCEPT; }

    break;

  case 73:

    { (yyval.ALT_Stringsym_SEP_commasym_type) = (List_String)Get_sub_tree (); }

    break;

  case 74:

    { egg_multi_action ((void*)(yyvsp[0].ALT_Stringsym_SEP_commasym_type)); YYACCEPT; }

    break;

  case 75:

    { (yyval.OPTMORE_Declaration_type) = (List_egg_Declaration)Get_sub_tree (); }

    break;

  case 76:

    { egg_multi_action ((void*)(yyvsp[0].OPTMORE_Declaration_type)); YYACCEPT; }

    break;

  case 77:

    { (yyval.MORE_Expression_type) = (List_egg_Expression)Get_sub_tree (); }

    break;

  case 78:

    { egg_multi_action ((void*)(yyvsp[0].MORE_Expression_type)); YYACCEPT; }

    break;

  case 79:

    { (yyval.ALT_Expression_SEP_commasym_type) = (List_egg_Expression)Get_sub_tree (); }

    break;

  case 80:

    { egg_multi_action ((void*)(yyvsp[0].ALT_Expression_SEP_commasym_type)); YYACCEPT; }

    break;

  case 81:

    { (yyval.OPTMORE_Statement_type) = (List_egg_Statement)Get_sub_tree (); }

    break;

  case 82:

    { egg_multi_action ((void*)(yyvsp[0].OPTMORE_Statement_type)); YYACCEPT; }

    break;

  case 83:

    { (yyval.OPT_fatalsym_type) = (Bool)Get_sub_tree (); }

    break;

  case 84:

    { egg_multi_action ((void*)(yyvsp[0].OPT_fatalsym_type)); YYACCEPT; }

    break;

  case 85:

    { (yyval.ALT_SubMessage_SEP_commasym_type) = (List_egg_SubMessage)Get_sub_tree (); }

    break;

  case 86:

    { egg_multi_action ((void*)(yyvsp[0].ALT_SubMessage_SEP_commasym_type)); YYACCEPT; }

    break;

  case 87:

    { (yyval.OPT_openparsym_Identsym_closeparsym_type) = (Ident)Get_sub_tree (); }

    break;

  case 88:

    { egg_multi_action ((void*)(yyvsp[0].OPT_openparsym_Identsym_closeparsym_type)); YYACCEPT; }

    break;

  case 89:

    { (yyval.OPT_groupsym_type) = (Bool)Get_sub_tree (); }

    break;

  case 90:

    { egg_multi_action ((void*)(yyvsp[0].OPT_groupsym_type)); YYACCEPT; }

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
