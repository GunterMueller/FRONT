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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse grammar_parse
#define yylex   grammar_lex
#define yyerror grammar_error
#define yylval  grammar_lval
#define yychar  grammar_char
#define yydebug grammar_debug
#define yynerrs grammar_nerrs
#define yylloc grammar_lloc

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




/* Copy the first part of user declarations.  */


#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "grammar.h"

extern int input_line_nr;

struct yy_buffer_state *grammar_dummy_state (void);
struct yy_buffer_state *grammar_scanner_state (void);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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
/* Line 191 of yacc.c.  */

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */


#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
             && defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   224

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  17
/* YYNRULES -- Number of rules. */
#define YYNRULES  64
/* YYNRULES -- Number of states. */
#define YYNSTATES  93

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     6,     8,    13,    15,    18,    21,    24,
      27,    30,    32,    34,    36,    38,    42,    46,    48,    50,
      52,    55,    58,    61,    62,    65,    66,    70,    71,    74,
      75,    77,    78,    81,    83,    86,    88,    91,    93,    96,
      98,   101,   103,   106,   108,   111,   113,   116,   118,   121,
     123,   126,   128,   131,   133,   136,   138,   141,   143,   146,
     148,   151,   153,   156,   158
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      54,     0,    -1,    55,    63,    -1,    65,    -1,    57,     6,
      66,     7,    -1,    58,    -1,    59,    67,    -1,    60,    68,
      -1,    61,    11,    -1,    61,    12,    -1,    61,    13,    -1,
      61,    -1,    19,    -1,     4,    -1,     5,    -1,     6,    20,
       7,    -1,     8,    57,     9,    -1,    10,    -1,    19,    -1,
      69,    -1,    20,    16,    -1,    20,    17,    -1,    20,    18,
      -1,    -1,    56,    65,    -1,    -1,    62,    15,    66,    -1,
      -1,    14,    57,    -1,    -1,    59,    -1,    -1,    64,    69,
      -1,    21,    -1,    22,    54,    -1,    23,    -1,    24,    55,
      -1,    25,    -1,    26,    56,    -1,    27,    -1,    28,    57,
      -1,    29,    -1,    30,    58,    -1,    31,    -1,    32,    59,
      -1,    33,    -1,    34,    60,    -1,    35,    -1,    36,    61,
      -1,    37,    -1,    38,    62,    -1,    39,    -1,    40,    63,
      -1,    41,    -1,    42,    64,    -1,    43,    -1,    44,    65,
      -1,    45,    -1,    46,    66,    -1,    47,    -1,    48,    67,
      -1,    49,    -1,    50,    68,    -1,    51,    -1,    52,    69,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   124,   124,   132,   138,   147,   154,   161,   168,   175,
     182,   189,   196,   202,   208,   214,   222,   230,   236,   244,
     250,   257,   264,   273,   279,   287,   293,   302,   308,   316,
     322,   329,   335,   343,   348,   354,   359,   365,   370,   376,
     381,   387,   392,   398,   403,   409,   414,   420,   425,   431,
     436,   442,   447,   453,   458,   464,   469,   475,   480,   486,
     491,   497,   502,   508,   513
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NONSENSE", "hatsym", "dollarsym",
  "openchainsym", "closechainsym", "openparsym", "closeparsym", "dotsym",
  "questionmarksym", "plussym", "starsym", "verticalbarsym",
  "semicolonsym", "nonterminalsym", "importsym", "extrasym", "Stringsym",
  "Identsym", "hole_grammar", "start_grammar", "hole_Scanner",
  "start_Scanner", "hole_Token", "start_Token", "hole_RegExpr",
  "start_RegExpr", "hole_ChoiceRE", "start_ChoiceRE", "hole_SeqRE",
  "start_SeqRE", "hole_PostRE", "start_PostRE", "hole_BasicRE",
  "start_BasicRE", "hole_ScanAction", "start_ScanAction", "hole_Parser",
  "start_Parser", "hole_ProdRule", "start_ProdRule", "hole_OPTMORE_Token",
  "start_OPTMORE_Token", "hole_OPTMORE_ScanAction_semicolonsym",
  "start_OPTMORE_ScanAction_semicolonsym",
  "hole_OPT_verticalbarsym_RegExpr", "start_OPT_verticalbarsym_RegExpr",
  "hole_OPT_SeqRE", "start_OPT_SeqRE", "hole_OPTMORE_ProdRule",
  "start_OPTMORE_ProdRule", "$accept", "grammar", "Scanner", "Token",
  "RegExpr", "ChoiceRE", "SeqRE", "PostRE", "BasicRE", "ScanAction",
  "Parser", "ProdRule", "OPTMORE_Token", "OPTMORE_ScanAction_semicolonsym",
  "OPT_verticalbarsym_RegExpr", "OPT_SeqRE", "OPTMORE_ProdRule", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    53,    54,    55,    56,    57,    58,    59,    60,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    62,    63,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    54,    54,    55,    54,    56,    54,    57,
      54,    58,    54,    59,    54,    60,    54,    61,    54,    62,
      54,    63,    54,    64,    54,    65,    54,    66,    54,    67,
      54,    68,    54,    69,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     1,     4,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     2,     2,     0,     2,     0,     3,     0,     2,     0,
       1,     0,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
      23,    13,    14,     0,     0,    17,    12,    33,    23,    35,
      23,    37,     0,    39,     0,    41,     0,    43,     0,    45,
       0,    47,     0,     0,    31,     0,    55,    23,    25,    27,
      29,    31,     0,    31,    23,     0,     5,    27,    29,    11,
       3,     0,     0,    34,    36,    38,    40,    42,    44,    46,
      48,    18,    49,    50,     0,    51,    53,    63,    52,    31,
      19,    54,    56,    57,     0,    58,     0,    59,    60,    61,
      30,    62,    64,     1,     2,    24,    25,     6,     7,     8,
       9,    10,    15,    16,    20,    21,    22,    32,    25,    28,
       0,    26,     4
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    64,
      58,    59,    40,    65,    68,    71,    60
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -24
static const short yypact[] =
{
      -3,   -24,   -24,   -16,   133,   -24,   -24,   -24,    -3,   -24,
      53,   -24,   100,   -24,   133,   -24,   140,   -24,   172,   -24,
     179,   -24,   189,    50,    51,    26,   -24,    93,    29,    -5,
      46,    -7,     6,    51,    93,     5,   -24,    -5,    46,   102,
     -24,     7,     3,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   137,   -24,   -24,   -24,   -24,    -7,
     -24,   -24,   -24,   -24,     0,   -24,   133,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,    29,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,    29,   -24,
      10,   -24,   -24
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -24,    30,    43,    48,    -4,    39,    55,    44,    61,    47,
      56,    66,    41,    33,    57,    62,   -23
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      42,     1,     2,     3,    41,     4,    73,     5,    72,    66,
      46,    76,    83,    54,    82,    88,     6,    92,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    56,    23,    87,    24,    43,    25,
      26,    27,    67,    28,    57,    29,    54,    30,    51,    31,
       1,     2,     3,    44,     4,    47,     5,     1,     2,     3,
      45,     4,    89,     5,    49,     6,    52,    56,    62,    51,
      53,    54,     6,    48,    63,    75,     9,    17,    11,    19,
      13,    21,    15,    50,    17,    70,    19,    52,    21,    74,
      55,    61,    56,    70,    77,    69,    26,     1,     2,     3,
      78,     4,    57,     5,     1,     2,     3,     0,     4,    90,
       5,     0,     6,    79,    80,    81,     0,     0,    11,     6,
      13,    91,    15,     0,    17,    11,    19,    13,    21,    15,
       0,    17,     0,    19,     0,    21,    26,     1,     2,     3,
       0,     4,     0,     5,     1,     2,     3,     0,     4,     0,
       5,     0,     6,    84,    85,    86,     0,     0,     0,     6,
      13,     0,    15,     0,    17,     0,    19,     0,    21,    15,
       0,    17,     0,    19,     0,    21,     1,     2,     3,     0,
       4,     0,     5,     1,     2,     3,     0,     4,     0,     5,
       0,     6,     0,     1,     2,     3,     0,     4,     6,     5,
       0,     0,     0,    17,     0,    19,     0,    21,     6,     0,
       0,     0,    19,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21
};

static const yysigned_char yycheck[] =
{
       4,     4,     5,     6,    20,     8,     0,    10,    31,    14,
      14,     6,     9,    20,     7,    15,    19,     7,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    41,    38,    59,    40,     8,    42,
      43,    44,    47,    46,    51,    48,    20,    50,    19,    52,
       4,     5,     6,    10,     8,    16,    10,     4,     5,     6,
      12,     8,    66,    10,    20,    19,    37,    41,    27,    19,
      23,    20,    19,    18,    45,    34,    23,    31,    25,    33,
      27,    35,    29,    22,    31,    30,    33,    37,    35,    33,
      39,    25,    41,    38,    37,    49,    43,     4,     5,     6,
      38,     8,    51,    10,     4,     5,     6,    -1,     8,    76,
      10,    -1,    19,    11,    12,    13,    -1,    -1,    25,    19,
      27,    88,    29,    -1,    31,    25,    33,    27,    35,    29,
      -1,    31,    -1,    33,    -1,    35,    43,     4,     5,     6,
      -1,     8,    -1,    10,     4,     5,     6,    -1,     8,    -1,
      10,    -1,    19,    16,    17,    18,    -1,    -1,    -1,    19,
      27,    -1,    29,    -1,    31,    -1,    33,    -1,    35,    29,
      -1,    31,    -1,    33,    -1,    35,     4,     5,     6,    -1,
       8,    -1,    10,     4,     5,     6,    -1,     8,    -1,    10,
      -1,    19,    -1,     4,     5,     6,    -1,     8,    19,    10,
      -1,    -1,    -1,    31,    -1,    33,    -1,    35,    19,    -1,
      -1,    -1,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     4,     5,     6,     8,    10,    19,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    38,    40,    42,    43,    44,    46,    48,
      50,    52,    54,    55,    56,    57,    58,    59,    60,    61,
      65,    20,    57,    54,    55,    56,    57,    58,    59,    60,
      61,    19,    37,    62,    20,    39,    41,    51,    63,    64,
      69,    64,    65,    45,    62,    66,    14,    47,    67,    49,
      59,    68,    69,     0,    63,    65,     6,    67,    68,    11,
      12,    13,     7,     9,    16,    17,    18,    69,    15,    57,
      66,    66,     7
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value, Location);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yytype, yyvaluep, yylocationp)
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  YYLTYPE *yylerrsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
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
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
  *++yylsp = yylloc;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    { yyval.grammar_type = Create_grammar_grammar(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].Scanner_type, yyvsp[0].Parser_type);
    Decorate_grammar(yyval.grammar_type);
  ;}
    break;

  case 3:

    { yyval.Scanner_type = Create_grammar_Scanner(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].OPTMORE_Token_type);
  ;}
    break;

  case 4:

    { yyval.Token_type = Create_grammar_Token(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-3].RegExpr_type, yyvsp[-1].OPTMORE_ScanAction_semicolonsym_type);
  ;}
    break;

  case 5:

    {
    yyval.RegExpr_type = yyvsp[0].ChoiceRE_type;
  ;}
    break;

  case 6:

    { yyval.ChoiceRE_type = Create_grammar_ChoiceRE(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].SeqRE_type, yyvsp[0].OPT_verticalbarsym_RegExpr_type);
  ;}
    break;

  case 7:

    { yyval.SeqRE_type = Create_grammar_SeqRE(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].PostRE_type, yyvsp[0].OPT_SeqRE_type);
  ;}
    break;

  case 8:

    { yyval.PostRE_type = Create_grammar_OptRE(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].BasicRE_type);
  ;}
    break;

  case 9:

    { yyval.PostRE_type = Create_grammar_PlusRE(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].BasicRE_type);
  ;}
    break;

  case 10:

    { yyval.PostRE_type = Create_grammar_TimesRE(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].BasicRE_type);
  ;}
    break;

  case 11:

    {
    yyval.PostRE_type = yyvsp[0].BasicRE_type;
  ;}
    break;

  case 12:

    { yyval.BasicRE_type = Create_grammar_StringRE(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].Stringsym_type);
  ;}
    break;

  case 13:

    { yyval.BasicRE_type = Create_grammar_SOLRE(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line));
  ;}
    break;

  case 14:

    { yyval.BasicRE_type = Create_grammar_EOLRE(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line));
  ;}
    break;

  case 15:

    { yyval.BasicRE_type = Create_grammar_IdRE(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-1].Identsym_type);
  ;}
    break;

  case 16:

    { yyval.BasicRE_type = Create_grammar_ParRE(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-1].RegExpr_type);
  ;}
    break;

  case 17:

    { yyval.BasicRE_type = Create_grammar_AnyRE(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line));
  ;}
    break;

  case 18:

    {
    yyval.ScanAction_type = yyvsp[0].Stringsym_type;
  ;}
    break;

  case 19:

    { yyval.Parser_type = Create_grammar_Parser(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].OPTMORE_ProdRule_type);
  ;}
    break;

  case 20:

    { yyval.ProdRule_type = Create_grammar_NT_Rule(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].Identsym_type);
  ;}
    break;

  case 21:

    { yyval.ProdRule_type = Create_grammar_Import_Rule(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].Identsym_type);
  ;}
    break;

  case 22:

    { yyval.ProdRule_type = Create_grammar_Extra_Rule(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].Identsym_type);
  ;}
    break;

  case 23:

    {
    yyval.OPTMORE_Token_type = NULL;
  ;}
    break;

  case 24:

    {
    yyval.OPTMORE_Token_type = Create_List_grammar_Token(yyvsp[-1].Token_type, yyvsp[0].OPTMORE_Token_type);
  ;}
    break;

  case 25:

    {
    yyval.OPTMORE_ScanAction_semicolonsym_type = NULL;
  ;}
    break;

  case 26:

    {
    yyval.OPTMORE_ScanAction_semicolonsym_type = Create_List_String(yyvsp[-2].ScanAction_type, yyvsp[0].OPTMORE_ScanAction_semicolonsym_type);
  ;}
    break;

  case 27:

    {
    yyval.OPT_verticalbarsym_RegExpr_type = NULL;
  ;}
    break;

  case 28:

    {
    yyval.OPT_verticalbarsym_RegExpr_type = yyvsp[0].RegExpr_type;
  ;}
    break;

  case 29:

    {
    yyval.OPT_SeqRE_type = NULL;
  ;}
    break;

  case 30:

    {
    yyval.OPT_SeqRE_type = yyvsp[0].SeqRE_type;
  ;}
    break;

  case 31:

    {
    yyval.OPTMORE_ProdRule_type = NULL;
  ;}
    break;

  case 32:

    {
    yyval.OPTMORE_ProdRule_type = Create_List_grammar_ProdRule(yyvsp[-1].ProdRule_type, yyvsp[0].OPTMORE_ProdRule_type);
  ;}
    break;

  case 33:

    { yyval.grammar_type = (grammar_grammar)Get_sub_tree (); ;}
    break;

  case 34:

    { grammar_multi_action ((void*)yyvsp[0].grammar_type); YYACCEPT; ;}
    break;

  case 35:

    { yyval.Scanner_type = (grammar_Scanner)Get_sub_tree (); ;}
    break;

  case 36:

    { grammar_multi_action ((void*)yyvsp[0].Scanner_type); YYACCEPT; ;}
    break;

  case 37:

    { yyval.Token_type = (grammar_Token)Get_sub_tree (); ;}
    break;

  case 38:

    { grammar_multi_action ((void*)yyvsp[0].Token_type); YYACCEPT; ;}
    break;

  case 39:

    { yyval.RegExpr_type = (grammar_RegExpr)Get_sub_tree (); ;}
    break;

  case 40:

    { grammar_multi_action ((void*)yyvsp[0].RegExpr_type); YYACCEPT; ;}
    break;

  case 41:

    { yyval.ChoiceRE_type = (grammar_RegExpr)Get_sub_tree (); ;}
    break;

  case 42:

    { grammar_multi_action ((void*)yyvsp[0].ChoiceRE_type); YYACCEPT; ;}
    break;

  case 43:

    { yyval.SeqRE_type = (grammar_RegExpr)Get_sub_tree (); ;}
    break;

  case 44:

    { grammar_multi_action ((void*)yyvsp[0].SeqRE_type); YYACCEPT; ;}
    break;

  case 45:

    { yyval.PostRE_type = (grammar_RegExpr)Get_sub_tree (); ;}
    break;

  case 46:

    { grammar_multi_action ((void*)yyvsp[0].PostRE_type); YYACCEPT; ;}
    break;

  case 47:

    { yyval.BasicRE_type = (grammar_RegExpr)Get_sub_tree (); ;}
    break;

  case 48:

    { grammar_multi_action ((void*)yyvsp[0].BasicRE_type); YYACCEPT; ;}
    break;

  case 49:

    { yyval.ScanAction_type = (String)Get_sub_tree (); ;}
    break;

  case 50:

    { grammar_multi_action ((void*)yyvsp[0].ScanAction_type); YYACCEPT; ;}
    break;

  case 51:

    { yyval.Parser_type = (grammar_Parser)Get_sub_tree (); ;}
    break;

  case 52:

    { grammar_multi_action ((void*)yyvsp[0].Parser_type); YYACCEPT; ;}
    break;

  case 53:

    { yyval.ProdRule_type = (grammar_ProdRule)Get_sub_tree (); ;}
    break;

  case 54:

    { grammar_multi_action ((void*)yyvsp[0].ProdRule_type); YYACCEPT; ;}
    break;

  case 55:

    { yyval.OPTMORE_Token_type = (List_grammar_Token)Get_sub_tree (); ;}
    break;

  case 56:

    { grammar_multi_action ((void*)yyvsp[0].OPTMORE_Token_type); YYACCEPT; ;}
    break;

  case 57:

    { yyval.OPTMORE_ScanAction_semicolonsym_type = (List_String)Get_sub_tree (); ;}
    break;

  case 58:

    { grammar_multi_action ((void*)yyvsp[0].OPTMORE_ScanAction_semicolonsym_type); YYACCEPT; ;}
    break;

  case 59:

    { yyval.OPT_verticalbarsym_RegExpr_type = (grammar_RegExpr)Get_sub_tree (); ;}
    break;

  case 60:

    { grammar_multi_action ((void*)yyvsp[0].OPT_verticalbarsym_RegExpr_type); YYACCEPT; ;}
    break;

  case 61:

    { yyval.OPT_SeqRE_type = (grammar_RegExpr)Get_sub_tree (); ;}
    break;

  case 62:

    { grammar_multi_action ((void*)yyvsp[0].OPT_SeqRE_type); YYACCEPT; ;}
    break;

  case 63:

    { yyval.OPTMORE_ProdRule_type = (List_grammar_ProdRule)Get_sub_tree (); ;}
    break;

  case 64:

    { grammar_multi_action ((void*)yyvsp[0].OPTMORE_ProdRule_type); YYACCEPT; ;}
    break;


    }

/* Line 993 of yacc.c.  */


  yyvsp -= yylen;
  yyssp -= yylen;
  yylsp -= yylen;

  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }

  yylerrsp = yylsp;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp, yylsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	  *++yylerrsp = yylloc;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  yylerrsp = yylsp;
  *++yylerrsp = yyloc;
  yylsp -= yylen;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
  YYLLOC_DEFAULT (yyloc, yylsp, yylerrsp - yylsp);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}



