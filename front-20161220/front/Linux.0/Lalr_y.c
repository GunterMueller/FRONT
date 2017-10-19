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
#define yyparse Lalr_parse
#define yylex   Lalr_lex
#define yyerror Lalr_error
#define yylval  Lalr_lval
#define yychar  Lalr_char
#define yydebug Lalr_debug
#define yynerrs Lalr_nerrs
#define yylloc Lalr_lloc

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




/* Copy the first part of user declarations.  */


#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "Lalr.h"

extern int input_line_nr;

struct yy_buffer_state *Lalr_dummy_state (void);
struct yy_buffer_state *Lalr_scanner_state (void);


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
#define YYFINAL  80
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   121

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  20
/* YYNRULES -- Number of rules. */
#define YYNRULES  68
/* YYNRULES -- Number of states. */
#define YYNSTATES  112

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     8,    17,    19,    22,    25,    27,    29,
      35,    42,    44,    49,    50,    53,    54,    57,    58,    60,
      61,    63,    65,    68,    69,    72,    73,    76,    77,    80,
      83,    87,    89,    92,    94,    97,    99,   102,   104,   107,
     109,   112,   114,   117,   119,   122,   124,   127,   129,   132,
     134,   137,   139,   142,   144,   147,   149,   152,   154,   157,
     159,   162,   164,   167,   169,   172,   174,   177,   179
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      60,     0,    -1,     4,    70,    13,    71,    -1,    20,     5,
      62,     7,     8,    65,    11,    68,    -1,    72,    -1,    20,
      73,    -1,    63,    64,    -1,     9,    -1,    10,    -1,    14,
      19,    74,    17,    75,    -1,    20,     5,    76,    15,    64,
      77,    -1,    78,    -1,    63,    18,    14,    19,    -1,    -1,
      61,    70,    -1,    -1,    66,    71,    -1,    -1,    64,    -1,
      -1,     6,    -1,    67,    -1,    67,    74,    -1,    -1,    69,
      75,    -1,    -1,    63,    76,    -1,    -1,    16,    68,    -1,
      20,    12,    -1,    20,    12,    78,    -1,    21,    -1,    22,
      60,    -1,    23,    -1,    24,    61,    -1,    25,    -1,    26,
      62,    -1,    27,    -1,    28,    63,    -1,    29,    -1,    30,
      64,    -1,    31,    -1,    32,    65,    -1,    33,    -1,    34,
      66,    -1,    35,    -1,    36,    67,    -1,    37,    -1,    38,
      68,    -1,    39,    -1,    40,    69,    -1,    41,    -1,    42,
      70,    -1,    43,    -1,    44,    71,    -1,    45,    -1,    46,
      72,    -1,    47,    -1,    48,    73,    -1,    49,    -1,    50,
      74,    -1,    51,    -1,    52,    75,    -1,    53,    -1,    54,
      76,    -1,    55,    -1,    56,    77,    -1,    57,    -1,    58,
      78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   136,   136,   146,   159,   167,   174,   181,   187,   193,
     203,   214,   222,   233,   239,   247,   253,   261,   267,   274,
     280,   287,   294,   302,   308,   316,   322,   330,   336,   344,
     352,   361,   366,   372,   377,   383,   388,   394,   399,   405,
     410,   416,   421,   427,   432,   438,   443,   449,   454,   460,
     465,   471,   476,   482,   487,   493,   498,   504,   509,   515,
     520,   526,   531,   537,   542,   548,   553,   559,   564
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NONSENSE", "GRAMMARsym",
  "minusgreaterthansym", "questionmarksym", "semicolonsym",
  "emptycolonsym", "NON_EMPTYsym", "EMPTYsym", "firstcolonsym", "spacesym",
  "STATESsym", "statesym", "dotsym", "followerscolonsym", "transitionssym",
  "equalsgreaterthansym", "Intsym", "Identsym", "hole_Lalr", "start_Lalr",
  "hole_Production", "start_Production", "hole_ProdRhs", "start_ProdRhs",
  "hole_LR_Symbol", "start_LR_Symbol", "hole_LR_Symbols",
  "start_LR_Symbols", "hole_Emptiness", "start_Emptiness", "hole_LR_state",
  "start_LR_state", "hole_Item", "start_Item", "hole_TermSet",
  "start_TermSet", "hole_Transition", "start_Transition",
  "hole_OPTMORE_Production", "start_OPTMORE_Production",
  "hole_OPTMORE_LR_state", "start_OPTMORE_LR_state", "hole_OPT_LR_Symbols",
  "start_OPT_LR_Symbols", "hole_OPT_questionmarksym",
  "start_OPT_questionmarksym", "hole_MORE_Item", "start_MORE_Item",
  "hole_OPTMORE_Transition", "start_OPTMORE_Transition",
  "hole_OPTMORE_LR_Symbol", "start_OPTMORE_LR_Symbol",
  "hole_OPT_followerscolonsym_TermSet",
  "start_OPT_followerscolonsym_TermSet", "hole_MORE_Identsym_spacesym",
  "start_MORE_Identsym_spacesym", "$accept", "Lalr", "Production",
  "ProdRhs", "LR_Symbol", "LR_Symbols", "Emptiness", "LR_state", "Item",
  "TermSet", "Transition", "OPTMORE_Production", "OPTMORE_LR_state",
  "OPT_LR_Symbols", "OPT_questionmarksym", "MORE_Item",
  "OPTMORE_Transition", "OPTMORE_LR_Symbol",
  "OPT_followerscolonsym_TermSet", "MORE_Identsym_spacesym", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    59,    60,    61,    62,    63,    64,    65,    65,    66,
      67,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    60,    60,    61,    60,    62,    60,    63,    60,    64,
      60,    65,    60,    66,    60,    67,    60,    68,    60,    69,
      60,    70,    60,    71,    60,    72,    60,    73,    60,    74,
      60,    75,    60,    76,    60,    77,    60,    78,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     4,     8,     1,     2,     2,     1,     1,     5,
       6,     1,     4,     0,     2,     0,     2,     0,     1,     0,
       1,     1,     2,     0,     2,     0,     2,     0,     2,     2,
       3,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,    13,    31,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,    13,    15,    17,    19,     0,    23,    25,
      27,     0,     0,     0,    33,    51,    13,     0,    32,    34,
      19,    35,    37,    39,    55,    36,     0,    18,     4,    38,
      40,     7,     8,    41,    42,     0,    43,    44,     0,    45,
      46,     0,    47,    67,    48,    11,    49,     0,    50,    52,
      53,    15,    54,    56,    20,    57,    58,    59,    21,    60,
      61,    23,    62,    63,    25,    64,     0,    65,    66,    68,
       1,    17,    14,    15,     5,     6,     0,    25,    29,     0,
      16,    22,    24,    26,    28,     0,     2,     0,     0,    30,
       0,     0,    23,     0,    12,     0,     9,    27,     0,    10,
       0,     3
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,    22,    26,    35,    36,    37,    44,    61,    68,    54,
      71,    27,    62,    38,    66,    69,    72,    75,    78,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yysigned_char yypact[] =
{
       0,    69,   -76,     0,    98,    55,    88,    87,     6,    79,
      82,   -10,    67,    69,    31,    56,     2,    37,    39,    35,
      -2,     3,     9,    12,   -76,   -76,    69,    20,   -76,   -76,
       2,   -76,   -76,   -76,   -76,   -76,    87,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,    22,   -76,   -76,    14,   -76,
     -76,    -1,   -76,   -76,   -76,   -76,   -76,    21,   -76,   -76,
     -76,    31,   -76,   -76,   -76,   -76,   -76,   -76,    37,   -76,
     -76,    39,   -76,   -76,    35,   -76,   -10,   -76,   -76,   -76,
     -76,    55,   -76,    31,   -76,   -76,    37,    35,     3,    47,
     -76,   -76,   -76,   -76,   -76,    60,   -76,    46,    54,   -76,
      52,    65,    39,    87,   -76,     6,   -76,    -2,    66,   -76,
     -10,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -76,    76,    91,    16,    -6,    -5,     4,    90,    93,   -75,
      99,    -8,   -54,   104,    75,   -43,   -51,    17,    13,   -18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      39,    94,    40,    79,     1,    59,    57,    90,    64,    80,
      51,    88,    57,    74,    76,    41,    42,    81,    82,    87,
      92,     2,     3,    51,     4,    91,     5,    52,     6,    96,
       7,    85,     8,    83,     9,   111,    10,    43,    11,    89,
      12,    86,    13,    97,    14,    45,    15,    53,    16,    65,
      17,   106,    18,    77,    19,    30,    20,    48,    21,    30,
      53,   100,    32,   102,    46,    57,    32,   101,    74,   103,
      99,   104,    49,   105,    60,    30,    30,   110,    56,    28,
      31,    74,    32,    32,    33,    33,    67,    30,    73,    23,
      70,    93,    24,    45,    32,    29,    57,    95,   107,    47,
      34,    34,    48,    50,    98,    84,    56,    30,    30,   108,
      25,    58,    46,     0,    32,    32,    33,    49,    23,    63,
     109,    24
};

static const yysigned_char yycheck[] =
{
       6,    76,     7,    21,     4,    13,    12,    61,     6,     0,
      20,    12,    18,    19,    16,     9,    10,     5,    26,     5,
      71,    21,    22,    20,    24,    68,    26,    37,    28,    83,
      30,    36,    32,    13,    34,   110,    36,    31,    38,    18,
      40,    19,    42,    86,    44,    14,    46,    57,    48,    47,
      50,   102,    52,    55,    54,    20,    56,    20,    58,    20,
      57,    14,    27,    17,    33,    71,    27,     7,    74,    15,
      88,    19,    35,     8,    43,    20,    20,    11,    39,     3,
      25,    87,    27,    27,    29,    29,    49,    20,    53,    20,
      51,    74,    23,    14,    27,     4,   102,    81,   103,     9,
      45,    45,    20,    10,    87,    30,    39,    20,    20,   105,
      41,    12,    33,    -1,    27,    27,    29,    35,    20,    15,
     107,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     4,    21,    22,    24,    26,    28,    30,    32,    34,
      36,    38,    40,    42,    44,    46,    48,    50,    52,    54,
      56,    58,    60,    20,    23,    41,    61,    70,    60,    61,
      20,    25,    27,    29,    45,    62,    63,    64,    72,    63,
      64,     9,    10,    31,    65,    14,    33,    66,    20,    35,
      67,    20,    37,    57,    68,    78,    39,    63,    69,    70,
      43,    66,    71,    72,     6,    47,    73,    49,    67,    74,
      51,    69,    75,    53,    63,    76,    16,    55,    77,    78,
       0,     5,    70,    13,    73,    64,    19,     5,    12,    18,
      71,    74,    75,    76,    68,    62,    71,    74,    76,    78,
      14,     7,    17,    15,    19,     8,    75,    64,    65,    77,
      11,    68
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

    { yyval.Lalr_type = Create_Lalr_Lalr(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-2].OPTMORE_Production_type, yyvsp[0].OPTMORE_LR_state_type);
    Decorate_Lalr(yyval.Lalr_type);
  ;}
    break;

  case 3:

    { yyval.Production_type = Create_Lalr_Production(make_post_src_info(yylsp[-7].first_line, yylsp[0].last_line), yyvsp[-7].Identsym_type, yyvsp[-5].ProdRhs_type, yyvsp[-2].Emptiness_type, yyvsp[0].TermSet_type);
  ;}
    break;

  case 4:

    {
    yyval.ProdRhs_type = yyvsp[0].OPT_LR_Symbols_type;
  ;}
    break;

  case 5:

    { yyval.LR_Symbol_type = Create_Lalr_LR_Symbol(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].Identsym_type, yyvsp[0].OPT_questionmarksym_type);
  ;}
    break;

  case 6:

    { yyval.LR_Symbols_type = Create_Lalr_LR_Symbols(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].LR_Symbol_type, yyvsp[0].LR_Symbols_type);
  ;}
    break;

  case 7:

    { yyval.Emptiness_type = FALSE; ;}
    break;

  case 8:

    { yyval.Emptiness_type = TRUE; ;}
    break;

  case 9:

    { yyval.LR_state_type = Create_Lalr_LR_state(make_post_src_info(yylsp[-4].first_line, yylsp[0].last_line), yyvsp[-3].Intsym_type, yyvsp[-2].MORE_Item_type, yyvsp[0].OPTMORE_Transition_type);
  ;}
    break;

  case 10:

    { yyval.Item_type = Create_Lalr_Item(make_post_src_info(yylsp[-5].first_line, yylsp[0].last_line), yyvsp[-5].Identsym_type, yyvsp[-3].OPTMORE_LR_Symbol_type, yyvsp[-1].LR_Symbols_type, yyvsp[0].OPT_followerscolonsym_TermSet_type);
  ;}
    break;

  case 11:

    {
    yyval.TermSet_type = yyvsp[0].MORE_Identsym_spacesym_type;
  ;}
    break;

  case 12:

    { yyval.Transition_type = Create_Lalr_Transition(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-3].LR_Symbol_type, yyvsp[0].Intsym_type);
  ;}
    break;

  case 13:

    {
    yyval.OPTMORE_Production_type = NULL;
  ;}
    break;

  case 14:

    {
    yyval.OPTMORE_Production_type = Create_List_Lalr_Production(yyvsp[-1].Production_type, yyvsp[0].OPTMORE_Production_type);
  ;}
    break;

  case 15:

    {
    yyval.OPTMORE_LR_state_type = NULL;
  ;}
    break;

  case 16:

    {
    yyval.OPTMORE_LR_state_type = Create_List_Lalr_LR_state(yyvsp[-1].LR_state_type, yyvsp[0].OPTMORE_LR_state_type);
  ;}
    break;

  case 17:

    {
    yyval.OPT_LR_Symbols_type = NULL;
  ;}
    break;

  case 18:

    {
    yyval.OPT_LR_Symbols_type = yyvsp[0].LR_Symbols_type;
  ;}
    break;

  case 19:

    {
    yyval.OPT_questionmarksym_type = FALSE;
  ;}
    break;

  case 20:

    {
    yyval.OPT_questionmarksym_type = TRUE;
  ;}
    break;

  case 21:

    {
    yyval.MORE_Item_type = Create_List_Lalr_Item(yyvsp[0].Item_type, NULL);
  ;}
    break;

  case 22:

    {
    yyval.MORE_Item_type = Create_List_Lalr_Item(yyvsp[-1].Item_type, yyvsp[0].MORE_Item_type);
  ;}
    break;

  case 23:

    {
    yyval.OPTMORE_Transition_type = NULL;
  ;}
    break;

  case 24:

    {
    yyval.OPTMORE_Transition_type = Create_List_Lalr_Transition(yyvsp[-1].Transition_type, yyvsp[0].OPTMORE_Transition_type);
  ;}
    break;

  case 25:

    {
    yyval.OPTMORE_LR_Symbol_type = NULL;
  ;}
    break;

  case 26:

    {
    yyval.OPTMORE_LR_Symbol_type = Create_List_Lalr_LR_Symbol(yyvsp[-1].LR_Symbol_type, yyvsp[0].OPTMORE_LR_Symbol_type);
  ;}
    break;

  case 27:

    {
    yyval.OPT_followerscolonsym_TermSet_type = NULL;
  ;}
    break;

  case 28:

    {
    yyval.OPT_followerscolonsym_TermSet_type = yyvsp[0].TermSet_type;
  ;}
    break;

  case 29:

    {
    yyval.MORE_Identsym_spacesym_type = Create_List_Ident(yyvsp[-1].Identsym_type, NULL);
  ;}
    break;

  case 30:

    {
    yyval.MORE_Identsym_spacesym_type = Create_List_Ident(yyvsp[-2].Identsym_type, yyvsp[0].MORE_Identsym_spacesym_type);
  ;}
    break;

  case 31:

    { yyval.Lalr_type = (Lalr_Lalr)Get_sub_tree (); ;}
    break;

  case 32:

    { Lalr_multi_action ((void*)yyvsp[0].Lalr_type); YYACCEPT; ;}
    break;

  case 33:

    { yyval.Production_type = (Lalr_Production)Get_sub_tree (); ;}
    break;

  case 34:

    { Lalr_multi_action ((void*)yyvsp[0].Production_type); YYACCEPT; ;}
    break;

  case 35:

    { yyval.ProdRhs_type = (Lalr_LR_Symbols)Get_sub_tree (); ;}
    break;

  case 36:

    { Lalr_multi_action ((void*)yyvsp[0].ProdRhs_type); YYACCEPT; ;}
    break;

  case 37:

    { yyval.LR_Symbol_type = (Lalr_LR_Symbol)Get_sub_tree (); ;}
    break;

  case 38:

    { Lalr_multi_action ((void*)yyvsp[0].LR_Symbol_type); YYACCEPT; ;}
    break;

  case 39:

    { yyval.LR_Symbols_type = (Lalr_LR_Symbols)Get_sub_tree (); ;}
    break;

  case 40:

    { Lalr_multi_action ((void*)yyvsp[0].LR_Symbols_type); YYACCEPT; ;}
    break;

  case 41:

    { yyval.Emptiness_type = (Lalr_Emptiness)Get_sub_tree (); ;}
    break;

  case 42:

    { Lalr_multi_action ((void*)yyvsp[0].Emptiness_type); YYACCEPT; ;}
    break;

  case 43:

    { yyval.LR_state_type = (Lalr_LR_state)Get_sub_tree (); ;}
    break;

  case 44:

    { Lalr_multi_action ((void*)yyvsp[0].LR_state_type); YYACCEPT; ;}
    break;

  case 45:

    { yyval.Item_type = (Lalr_Item)Get_sub_tree (); ;}
    break;

  case 46:

    { Lalr_multi_action ((void*)yyvsp[0].Item_type); YYACCEPT; ;}
    break;

  case 47:

    { yyval.TermSet_type = (List_Ident)Get_sub_tree (); ;}
    break;

  case 48:

    { Lalr_multi_action ((void*)yyvsp[0].TermSet_type); YYACCEPT; ;}
    break;

  case 49:

    { yyval.Transition_type = (Lalr_Transition)Get_sub_tree (); ;}
    break;

  case 50:

    { Lalr_multi_action ((void*)yyvsp[0].Transition_type); YYACCEPT; ;}
    break;

  case 51:

    { yyval.OPTMORE_Production_type = (List_Lalr_Production)Get_sub_tree (); ;}
    break;

  case 52:

    { Lalr_multi_action ((void*)yyvsp[0].OPTMORE_Production_type); YYACCEPT; ;}
    break;

  case 53:

    { yyval.OPTMORE_LR_state_type = (List_Lalr_LR_state)Get_sub_tree (); ;}
    break;

  case 54:

    { Lalr_multi_action ((void*)yyvsp[0].OPTMORE_LR_state_type); YYACCEPT; ;}
    break;

  case 55:

    { yyval.OPT_LR_Symbols_type = (Lalr_LR_Symbols)Get_sub_tree (); ;}
    break;

  case 56:

    { Lalr_multi_action ((void*)yyvsp[0].OPT_LR_Symbols_type); YYACCEPT; ;}
    break;

  case 57:

    { yyval.OPT_questionmarksym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 58:

    { Lalr_multi_action ((void*)yyvsp[0].OPT_questionmarksym_type); YYACCEPT; ;}
    break;

  case 59:

    { yyval.MORE_Item_type = (List_Lalr_Item)Get_sub_tree (); ;}
    break;

  case 60:

    { Lalr_multi_action ((void*)yyvsp[0].MORE_Item_type); YYACCEPT; ;}
    break;

  case 61:

    { yyval.OPTMORE_Transition_type = (List_Lalr_Transition)Get_sub_tree (); ;}
    break;

  case 62:

    { Lalr_multi_action ((void*)yyvsp[0].OPTMORE_Transition_type); YYACCEPT; ;}
    break;

  case 63:

    { yyval.OPTMORE_LR_Symbol_type = (List_Lalr_LR_Symbol)Get_sub_tree (); ;}
    break;

  case 64:

    { Lalr_multi_action ((void*)yyvsp[0].OPTMORE_LR_Symbol_type); YYACCEPT; ;}
    break;

  case 65:

    { yyval.OPT_followerscolonsym_TermSet_type = (List_Ident)Get_sub_tree (); ;}
    break;

  case 66:

    { Lalr_multi_action ((void*)yyvsp[0].OPT_followerscolonsym_TermSet_type); YYACCEPT; ;}
    break;

  case 67:

    { yyval.MORE_Identsym_spacesym_type = (List_Ident)Get_sub_tree (); ;}
    break;

  case 68:

    { Lalr_multi_action ((void*)yyvsp[0].MORE_Identsym_spacesym_type); YYACCEPT; ;}
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



