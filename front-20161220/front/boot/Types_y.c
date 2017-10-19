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
#define yyparse Types_parse
#define yylex   Types_lex
#define yyerror Types_error
#define yylval  Types_lval
#define yychar  Types_char
#define yydebug Types_debug
#define yynerrs Types_nerrs
#define yylloc Types_lloc

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NONSENSE = 258,
     hashincludespacelessthanstdargdothgreaterthansym = 259,
     hashincludespacelessthanstddefdothgreaterthansym = 260,
     hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym = 261,
     typedefsym = 262,
     enumsym = 263,
     openchainsym = 264,
     commasym = 265,
     closechainsym = 266,
     semicolonsym = 267,
     externspacecharspacestarsym = 268,
     underscorenamesopenbrkclosebrksemicolonsym = 269,
     hashdefinespaceNUMunderscoresym = 270,
     hashifndefspaceDEFunderscoreTYPEunderscoresym = 271,
     hashdefinespaceDEFunderscoreTYPEunderscoresym = 272,
     typedefspacestructspacesunderscoresym = 273,
     starsym = 274,
     typedefspacesym = 275,
     hashendifsym = 276,
     hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym = 277,
     hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym = 278,
     hashincludespacelessthanfrontslashSymTabdothgreaterthansym = 279,
     hashincludespacebackslashdoublequotesym = 280,
     underscoreparsedothbackslashdoublequotesym = 281,
     underscoredefsdothbackslashdoublequotesym = 282,
     dothbackslashdoublequotesym = 283,
     typedefspaceBindspaceBindunderscoresym = 284,
     typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym = 285,
     hashdefinespaceListunderscoreBindunderscoresym = 286,
     underscoredataopenparxcloseparsym = 287,
     openparBindunderscoresym = 288,
     closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym = 289,
     underscorenextopenparxcloseparsym = 290,
     openparListunderscoreBindunderscoresym = 291,
     closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym = 292,
     hashdefinespaceBindunderscoresym = 293,
     _kindsym = 294,
     externsym = 295,
     underscorerootsemicolonsym = 296,
     hashifndefspaceDEFunderscoreSTRUCTunderscoresym = 297,
     hashdefinespaceDEFunderscoreSTRUCTunderscoresym = 298,
     structsym = 299,
     s_sym = 300,
     _USER_FIELDSsym = 301,
     _sym = 302,
     unionspaceopenchainsym = 303,
     closechainspacesubsemicolonsym = 304,
     hashdefinesym = 305,
     openparunderscorepcloseparsym = 306,
     openparsym = 307,
     openparstarunderscorepcloseparsym = 308,
     underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym = 309,
     dotsubdotsym = 310,
     dotsym = 311,
     closeparsym = 312,
     CREATEsym = 313,
     hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym = 314,
     spacestarslashsym = 315,
     Intsym = 316,
     Identsym = 317,
     hole_Types = 318,
     start_Types = 319,
     hole_includes2 = 320,
     start_includes2 = 321,
     hole_EnumType = 322,
     start_EnumType = 323,
     hole_Enums = 324,
     start_Enums = 325,
     hole_BindType = 326,
     start_BindType = 327,
     hole_PointerType = 328,
     start_PointerType = 329,
     hole_subtypedef = 330,
     start_subtypedef = 331,
     hole_StructType = 332,
     start_StructType = 333,
     hole_struct_type = 334,
     start_struct_type = 335,
     hole_sub_union = 336,
     start_sub_union = 337,
     hole_macro = 338,
     start_macro = 339,
     hole_field = 340,
     start_field = 341,
     hole_TypeName = 342,
     start_TypeName = 343,
     hole_CreateFunction = 344,
     start_CreateFunction = 345,
     hole_TypeNames = 346,
     start_TypeNames = 347,
     hole_OPTMORE_EnumType = 348,
     start_OPTMORE_EnumType = 349,
     hole_OPTMORE_PointerType = 350,
     start_OPTMORE_PointerType = 351,
     hole_OPTMORE_subtypedef = 352,
     start_OPTMORE_subtypedef = 353,
     hole_OPTMORE_BindType = 354,
     start_OPTMORE_BindType = 355,
     hole_OPTMORE_StructType = 356,
     start_OPTMORE_StructType = 357,
     hole_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym = 358,
     start_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym = 359,
     hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym = 360,
     start_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym = 361,
     hole_ALT_TypeName_SEP_commasym_NL = 362,
     start_ALT_TypeName_SEP_commasym_NL = 363,
     hole_OPTMORE_macro = 364,
     start_OPTMORE_macro = 365,
     hole_OPTMORE_CreateFunction = 366,
     start_OPTMORE_CreateFunction = 367,
     hole_OPT_Identsym__USER_FIELDSsym = 368,
     start_OPT_Identsym__USER_FIELDSsym = 369,
     hole_OPTMORE_field = 370,
     start_OPTMORE_field = 371,
     hole_OPT_sub_union = 372,
     start_OPT_sub_union = 373,
     hole_OPT_Identsym = 374,
     start_OPT_Identsym = 375,
     hole_OPTMORE_struct_type = 376,
     start_OPTMORE_struct_type = 377,
     hole_OPTMORE_dotsubdotsym_Identsym = 378,
     start_OPTMORE_dotsubdotsym_Identsym = 379,
     hole_ALT_TypeName_SEP__sym = 380,
     start_ALT_TypeName_SEP__sym = 381
   };
#endif
#define NONSENSE 258
#define hashincludespacelessthanstdargdothgreaterthansym 259
#define hashincludespacelessthanstddefdothgreaterthansym 260
#define hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym 261
#define typedefsym 262
#define enumsym 263
#define openchainsym 264
#define commasym 265
#define closechainsym 266
#define semicolonsym 267
#define externspacecharspacestarsym 268
#define underscorenamesopenbrkclosebrksemicolonsym 269
#define hashdefinespaceNUMunderscoresym 270
#define hashifndefspaceDEFunderscoreTYPEunderscoresym 271
#define hashdefinespaceDEFunderscoreTYPEunderscoresym 272
#define typedefspacestructspacesunderscoresym 273
#define starsym 274
#define typedefspacesym 275
#define hashendifsym 276
#define hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym 277
#define hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym 278
#define hashincludespacelessthanfrontslashSymTabdothgreaterthansym 279
#define hashincludespacebackslashdoublequotesym 280
#define underscoreparsedothbackslashdoublequotesym 281
#define underscoredefsdothbackslashdoublequotesym 282
#define dothbackslashdoublequotesym 283
#define typedefspaceBindspaceBindunderscoresym 284
#define typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym 285
#define hashdefinespaceListunderscoreBindunderscoresym 286
#define underscoredataopenparxcloseparsym 287
#define openparBindunderscoresym 288
#define closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym 289
#define underscorenextopenparxcloseparsym 290
#define openparListunderscoreBindunderscoresym 291
#define closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym 292
#define hashdefinespaceBindunderscoresym 293
#define _kindsym 294
#define externsym 295
#define underscorerootsemicolonsym 296
#define hashifndefspaceDEFunderscoreSTRUCTunderscoresym 297
#define hashdefinespaceDEFunderscoreSTRUCTunderscoresym 298
#define structsym 299
#define s_sym 300
#define _USER_FIELDSsym 301
#define _sym 302
#define unionspaceopenchainsym 303
#define closechainspacesubsemicolonsym 304
#define hashdefinesym 305
#define openparunderscorepcloseparsym 306
#define openparsym 307
#define openparstarunderscorepcloseparsym 308
#define underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym 309
#define dotsubdotsym 310
#define dotsym 311
#define closeparsym 312
#define CREATEsym 313
#define hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym 314
#define spacestarslashsym 315
#define Intsym 316
#define Identsym 317
#define hole_Types 318
#define start_Types 319
#define hole_includes2 320
#define start_includes2 321
#define hole_EnumType 322
#define start_EnumType 323
#define hole_Enums 324
#define start_Enums 325
#define hole_BindType 326
#define start_BindType 327
#define hole_PointerType 328
#define start_PointerType 329
#define hole_subtypedef 330
#define start_subtypedef 331
#define hole_StructType 332
#define start_StructType 333
#define hole_struct_type 334
#define start_struct_type 335
#define hole_sub_union 336
#define start_sub_union 337
#define hole_macro 338
#define start_macro 339
#define hole_field 340
#define start_field 341
#define hole_TypeName 342
#define start_TypeName 343
#define hole_CreateFunction 344
#define start_CreateFunction 345
#define hole_TypeNames 346
#define start_TypeNames 347
#define hole_OPTMORE_EnumType 348
#define start_OPTMORE_EnumType 349
#define hole_OPTMORE_PointerType 350
#define start_OPTMORE_PointerType 351
#define hole_OPTMORE_subtypedef 352
#define start_OPTMORE_subtypedef 353
#define hole_OPTMORE_BindType 354
#define start_OPTMORE_BindType 355
#define hole_OPTMORE_StructType 356
#define start_OPTMORE_StructType 357
#define hole_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym 358
#define start_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym 359
#define hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym 360
#define start_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym 361
#define hole_ALT_TypeName_SEP_commasym_NL 362
#define start_ALT_TypeName_SEP_commasym_NL 363
#define hole_OPTMORE_macro 364
#define start_OPTMORE_macro 365
#define hole_OPTMORE_CreateFunction 366
#define start_OPTMORE_CreateFunction 367
#define hole_OPT_Identsym__USER_FIELDSsym 368
#define start_OPT_Identsym__USER_FIELDSsym 369
#define hole_OPTMORE_field 370
#define start_OPTMORE_field 371
#define hole_OPT_sub_union 372
#define start_OPT_sub_union 373
#define hole_OPT_Identsym 374
#define start_OPT_Identsym 375
#define hole_OPTMORE_struct_type 376
#define start_OPTMORE_struct_type 377
#define hole_OPTMORE_dotsubdotsym_Identsym 378
#define start_OPTMORE_dotsubdotsym_Identsym 379
#define hole_ALT_TypeName_SEP__sym 380
#define start_ALT_TypeName_SEP__sym 381




/* Copy the first part of user declarations.  */


#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "Types.h"

extern int input_line_nr;

struct yy_buffer_state *Types_dummy_state (void);
struct yy_buffer_state *Types_scanner_state (void);


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
Types_Types Types_type;
Types_includes2 includes2_type;
Types_EnumType EnumType_type;
List_Types_TypeName Enums_type;
Types_BindType BindType_type;
Types_PointerType PointerType_type;
Types_subtypedef subtypedef_type;
struct {
  Ident f1;
  Ident f2;
} RootDecl_type;
Types_StructType StructType_type;
Types_struct_type struct_type_type;
List_Types_struct_type sub_union_type;
Types_macro macro_type;
Types_field field_type;
Types_TypeName TypeName_type;
Types_CreateFunction CreateFunction_type;
List_Types_TypeName TypeNames_type;
List_Types_EnumType OPTMORE_EnumType_type;
List_Types_PointerType OPTMORE_PointerType_type;
List_Types_subtypedef OPTMORE_subtypedef_type;
List_Types_BindType OPTMORE_BindType_type;
List_Types_StructType OPTMORE_StructType_type;
Ident OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_type;
List_Ident OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_type;
List_Types_TypeName ALT_TypeName_SEP_commasym_NL_type;
List_Types_macro OPTMORE_macro_type;
List_Types_CreateFunction OPTMORE_CreateFunction_type;
Ident OPT_Identsym__USER_FIELDSsym_type;
List_Types_field OPTMORE_field_type;
List_Types_struct_type OPT_sub_union_type;
Ident OPT_Identsym_type;
List_Types_struct_type OPTMORE_struct_type_type;
List_Ident OPTMORE_dotsubdotsym_Identsym_type;
List_Types_TypeName ALT_TypeName_SEP__sym_type;
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
#define YYFINAL  132
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   266

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  35
/* YYNRULES -- Number of rules. */
#define YYNRULES  117
/* YYNRULES -- Number of states. */
#define YYNSTATES  260

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   381

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,    13,    17,    26,    40,    42,    65,    77,
      82,    87,    98,   110,   114,   126,   139,   143,   145,   148,
     150,   151,   154,   155,   158,   159,   162,   163,   166,   167,
     170,   171,   175,   176,   181,   183,   187,   188,   191,   192,
     195,   196,   199,   200,   203,   204,   206,   207,   209,   210,
     213,   214,   218,   220,   224,   226,   229,   231,   234,   236,
     239,   241,   244,   246,   249,   251,   254,   256,   259,   261,
     264,   266,   269,   271,   274,   276,   279,   281,   284,   286,
     289,   291,   294,   296,   299,   301,   304,   306,   309,   311,
     314,   316,   319,   321,   324,   326,   329,   331,   334,   336,
     339,   341,   344,   346,   349,   351,   354,   356,   359,   361,
     364,   366,   369,   371,   374,   376,   379,   381
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     128,     0,    -1,   129,   145,   146,   147,   130,   147,   148,
     136,   149,    -1,     4,     5,     6,    -1,    22,    23,    24,
     150,    25,    62,    27,   151,    -1,     7,     8,     9,   132,
      11,    62,    12,    13,    62,    14,    15,    62,    61,    -1,
     152,    -1,    29,    62,    12,    30,    62,    12,    31,    62,
      32,    33,    62,    34,    31,    62,    35,    36,    62,    37,
      38,    62,    39,    61,    -1,    16,    62,    17,    62,    18,
      62,    19,    62,    12,   147,    21,    -1,    20,    62,    62,
      12,    -1,    40,    62,    62,    41,    -1,    42,    62,    43,
      62,   138,   153,   154,    59,    62,    60,    -1,    44,    45,
      62,     9,   155,   156,   157,   156,    11,   158,    12,    -1,
      48,   159,    49,    -1,    50,    62,    47,    62,    51,    52,
      53,   160,    56,    62,    57,    -1,    50,    62,    47,    62,
      51,    52,    62,    54,   160,    56,    62,    57,    -1,   144,
      62,    12,    -1,    62,    -1,    58,   156,    -1,   161,    -1,
      -1,   131,   145,    -1,    -1,   134,   146,    -1,    -1,   135,
     147,    -1,    -1,   133,   148,    -1,    -1,   137,   149,    -1,
      -1,    25,    62,    26,    -1,    -1,    25,    62,    28,   151,
      -1,   142,    -1,   142,    10,   152,    -1,    -1,   140,   153,
      -1,    -1,   143,   154,    -1,    -1,    62,    46,    -1,    -1,
     141,   156,    -1,    -1,   139,    -1,    -1,    62,    -1,    -1,
     138,   159,    -1,    -1,    55,    62,   160,    -1,   142,    -1,
     142,    47,   161,    -1,    63,    -1,    64,   128,    -1,    65,
      -1,    66,   130,    -1,    67,    -1,    68,   131,    -1,    69,
      -1,    70,   132,    -1,    71,    -1,    72,   133,    -1,    73,
      -1,    74,   134,    -1,    75,    -1,    76,   135,    -1,    77,
      -1,    78,   137,    -1,    79,    -1,    80,   138,    -1,    81,
      -1,    82,   139,    -1,    83,    -1,    84,   140,    -1,    85,
      -1,    86,   141,    -1,    87,    -1,    88,   142,    -1,    89,
      -1,    90,   143,    -1,    91,    -1,    92,   144,    -1,    93,
      -1,    94,   145,    -1,    95,    -1,    96,   146,    -1,    97,
      -1,    98,   147,    -1,    99,    -1,   100,   148,    -1,   101,
      -1,   102,   149,    -1,   103,    -1,   104,   150,    -1,   105,
      -1,   106,   151,    -1,   107,    -1,   108,   152,    -1,   109,
      -1,   110,   153,    -1,   111,    -1,   112,   154,    -1,   113,
      -1,   114,   155,    -1,   115,    -1,   116,   156,    -1,   117,
      -1,   118,   157,    -1,   119,    -1,   120,   158,    -1,   121,
      -1,   122,   159,    -1,   123,    -1,   124,   160,    -1,   125,
      -1,   126,   161,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   278,   278,   293,   302,   315,   333,   341,   368,   384,
     393,   405,   420,   436,   446,   462,   479,   487,   493,   500,
     510,   516,   524,   530,   538,   544,   552,   558,   566,   572,
     580,   586,   595,   601,   611,   618,   627,   633,   641,   647,
     655,   661,   669,   675,   683,   689,   696,   702,   709,   715,
     723,   729,   738,   745,   754,   759,   765,   770,   776,   781,
     787,   792,   798,   803,   809,   814,   820,   825,   831,   836,
     842,   847,   853,   858,   864,   869,   875,   880,   886,   891,
     897,   902,   908,   913,   919,   924,   930,   935,   941,   946,
     952,   957,   963,   968,   974,   979,   985,   990,   996,  1001,
    1007,  1012,  1018,  1023,  1029,  1034,  1040,  1045,  1051,  1056,
    1062,  1067,  1073,  1078,  1084,  1089,  1095,  1100
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NONSENSE",
  "hashincludespacelessthanstdargdothgreaterthansym",
  "hashincludespacelessthanstddefdothgreaterthansym",
  "hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym",
  "typedefsym", "enumsym", "openchainsym", "commasym", "closechainsym",
  "semicolonsym", "externspacecharspacestarsym",
  "underscorenamesopenbrkclosebrksemicolonsym",
  "hashdefinespaceNUMunderscoresym",
  "hashifndefspaceDEFunderscoreTYPEunderscoresym",
  "hashdefinespaceDEFunderscoreTYPEunderscoresym",
  "typedefspacestructspacesunderscoresym", "starsym", "typedefspacesym",
  "hashendifsym",
  "hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym",
  "hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym",
  "hashincludespacelessthanfrontslashSymTabdothgreaterthansym",
  "hashincludespacebackslashdoublequotesym",
  "underscoreparsedothbackslashdoublequotesym",
  "underscoredefsdothbackslashdoublequotesym",
  "dothbackslashdoublequotesym", "typedefspaceBindspaceBindunderscoresym",
  "typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym",
  "hashdefinespaceListunderscoreBindunderscoresym",
  "underscoredataopenparxcloseparsym", "openparBindunderscoresym",
  "closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym",
  "underscorenextopenparxcloseparsym",
  "openparListunderscoreBindunderscoresym",
  "closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym",
  "hashdefinespaceBindunderscoresym", "_kindsym", "externsym",
  "underscorerootsemicolonsym",
  "hashifndefspaceDEFunderscoreSTRUCTunderscoresym",
  "hashdefinespaceDEFunderscoreSTRUCTunderscoresym", "structsym", "s_sym",
  "_USER_FIELDSsym", "_sym", "unionspaceopenchainsym",
  "closechainspacesubsemicolonsym", "hashdefinesym",
  "openparunderscorepcloseparsym", "openparsym",
  "openparstarunderscorepcloseparsym",
  "underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym",
  "dotsubdotsym", "dotsym", "closeparsym", "CREATEsym",
  "hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym",
  "spacestarslashsym", "Intsym", "Identsym", "hole_Types", "start_Types",
  "hole_includes2", "start_includes2", "hole_EnumType", "start_EnumType",
  "hole_Enums", "start_Enums", "hole_BindType", "start_BindType",
  "hole_PointerType", "start_PointerType", "hole_subtypedef",
  "start_subtypedef", "hole_StructType", "start_StructType",
  "hole_struct_type", "start_struct_type", "hole_sub_union",
  "start_sub_union", "hole_macro", "start_macro", "hole_field",
  "start_field", "hole_TypeName", "start_TypeName", "hole_CreateFunction",
  "start_CreateFunction", "hole_TypeNames", "start_TypeNames",
  "hole_OPTMORE_EnumType", "start_OPTMORE_EnumType",
  "hole_OPTMORE_PointerType", "start_OPTMORE_PointerType",
  "hole_OPTMORE_subtypedef", "start_OPTMORE_subtypedef",
  "hole_OPTMORE_BindType", "start_OPTMORE_BindType",
  "hole_OPTMORE_StructType", "start_OPTMORE_StructType",
  "hole_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym",
  "start_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym",
  "hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym",
  "start_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym",
  "hole_ALT_TypeName_SEP_commasym_NL",
  "start_ALT_TypeName_SEP_commasym_NL", "hole_OPTMORE_macro",
  "start_OPTMORE_macro", "hole_OPTMORE_CreateFunction",
  "start_OPTMORE_CreateFunction", "hole_OPT_Identsym__USER_FIELDSsym",
  "start_OPT_Identsym__USER_FIELDSsym", "hole_OPTMORE_field",
  "start_OPTMORE_field", "hole_OPT_sub_union", "start_OPT_sub_union",
  "hole_OPT_Identsym", "start_OPT_Identsym", "hole_OPTMORE_struct_type",
  "start_OPTMORE_struct_type", "hole_OPTMORE_dotsubdotsym_Identsym",
  "start_OPTMORE_dotsubdotsym_Identsym", "hole_ALT_TypeName_SEP__sym",
  "start_ALT_TypeName_SEP__sym", "$accept", "Types", "includes1",
  "includes2", "EnumType", "Enums", "BindType", "PointerType",
  "subtypedef", "RootDecl", "StructType", "struct_type", "sub_union",
  "macro", "field", "TypeName", "CreateFunction", "TypeNames",
  "OPTMORE_EnumType", "OPTMORE_PointerType", "OPTMORE_subtypedef",
  "OPTMORE_BindType", "OPTMORE_StructType",
  "OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym",
  "OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym",
  "ALT_TypeName_SEP_commasym_NL", "OPTMORE_macro",
  "OPTMORE_CreateFunction", "OPT_Identsym__USER_FIELDSsym",
  "OPTMORE_field", "OPT_sub_union", "OPT_Identsym", "OPTMORE_struct_type",
  "OPTMORE_dotsubdotsym_Identsym", "ALT_TypeName_SEP__sym", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   140,   141,   142,   143,   144,
     145,   145,   146,   146,   147,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   155,   156,   156,   157,   157,   158,   158,   159,   159,
     160,   160,   161,   161,   128,   128,   130,   128,   131,   128,
     132,   128,   133,   128,   134,   128,   135,   128,   137,   128,
     138,   128,   139,   128,   140,   128,   141,   128,   142,   128,
     143,   128,   144,   128,   145,   128,   146,   128,   147,   128,
     148,   128,   149,   128,   150,   128,   151,   128,   152,   128,
     153,   128,   154,   128,   155,   128,   156,   128,   157,   128,
     158,   128,   159,   128,   160,   128,   161,   128
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     9,     3,     8,    13,     1,    22,    11,     4,
       4,    10,    11,     3,    11,    12,     3,     1,     2,     1,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     3,     0,     4,     1,     3,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     1,     0,     1,     0,     2,
       0,     3,     1,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    22,
      24,    26,    28,    30,    32,     0,    36,    38,    40,    42,
      44,    46,    48,    50,     0,     0,    20,     0,    55,     0,
      56,    57,     0,    58,    59,    17,    60,    78,    98,    61,
      34,     6,     0,    62,    63,     0,    64,    65,     0,    66,
      67,     0,    68,    69,     0,    70,    71,    48,    72,    73,
       0,    74,    75,    76,    82,   116,    77,    52,     0,    19,
      79,    42,    80,    81,    83,    84,    20,    85,    86,    22,
      87,    88,    24,    89,    90,    26,    91,    92,    28,    93,
       0,    94,    95,     0,    96,    97,    99,   100,    36,   101,
     102,    38,   103,     0,   104,   105,   106,    42,   107,   108,
      45,   109,    47,   110,   111,   112,    48,   113,     0,   114,
     115,   117,     1,    22,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    21,    23,
      25,    27,    29,     0,     0,    37,    39,    41,    43,    49,
      50,    24,     0,     0,    35,     0,     0,     0,     0,     0,
      13,     0,    53,    16,    31,    32,    51,     0,     0,     0,
       0,     0,     9,     0,    40,     0,    33,    24,     0,     0,
       0,     0,    36,    42,     0,    26,     0,     0,     0,     0,
      38,    44,     0,     0,    32,     0,     0,     0,     0,    42,
      50,     0,     0,    28,     4,     0,     0,     0,     0,     0,
       0,    50,     0,     2,     0,     0,    24,     0,    46,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,    10,
       0,     0,     8,    12,    14,     0,     0,     0,    15,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    35,    36,    41,    86,    49,    95,    89,    92,   213,
      98,   126,   120,   108,   117,    77,   111,    78,    87,    90,
      93,    96,    99,   102,   105,    51,   109,   112,   115,   118,
     121,   124,   127,   130,    79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -144
static const short yypact[] =
{
       0,    24,  -144,     0,    -3,    20,    82,   112,   111,   119,
     -19,   -22,    99,   -24,    43,   -34,   -33,    63,     2,     8,
      14,   -16,    96,     6,   -14,    83,   -36,    85,    80,    61,
      -4,   -44,   -28,   -38,    73,    30,     2,    27,  -144,    12,
    -144,  -144,    29,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
      28,  -144,   -21,  -144,  -144,   -13,  -144,  -144,   -12,  -144,
    -144,   -10,  -144,  -144,    -2,  -144,  -144,   -28,  -144,  -144,
      -8,  -144,  -144,  -144,  -144,  -144,  -144,    -7,     5,  -144,
    -144,    61,  -144,  -144,  -144,  -144,     2,  -144,  -144,     8,
    -144,  -144,    14,  -144,  -144,   -16,  -144,  -144,    96,  -144,
      87,  -144,  -144,    91,  -144,  -144,  -144,  -144,   -36,  -144,
    -144,    85,  -144,   109,  -144,  -144,  -144,    61,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,   -28,  -144,    94,  -144,
    -144,  -144,  -144,     8,  -144,    18,    37,    83,    36,   140,
      97,    17,   100,   114,   117,    73,   149,  -144,  -144,  -144,
    -144,  -144,  -144,   139,   138,  -144,  -144,  -144,  -144,  -144,
     -38,    14,     6,    82,  -144,   137,   113,   159,   115,   169,
    -144,   120,  -144,  -144,  -144,   -14,  -144,    -3,   154,   170,
     123,   173,  -144,   -22,    80,   144,  -144,    14,   141,   142,
     187,   143,   -36,    61,   148,   -16,   174,   190,   175,   188,
      85,    -4,   -17,   168,   -14,   196,   150,   151,   152,    61,
     -38,   156,   153,    96,  -144,   155,   182,   204,   157,   207,
     164,   -38,   160,  -144,   209,   191,    14,   161,   -44,   163,
     171,   185,   213,   167,   210,  -144,   218,   176,   172,  -144,
     177,   198,  -144,  -144,  -144,   178,   179,   205,  -144,  -144,
     180,   202,   208,   181,   201,   203,   183,   211,   186,  -144
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -144,   243,  -144,    71,   244,    88,   245,   246,   247,  -144,
     248,   -11,   241,   242,   249,    -5,   250,   240,   101,   -68,
     -90,   -88,   -92,    98,  -143,   -20,   -93,   -99,    75,   -78,
      60,    34,    66,   -81,   -26
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
      66,    50,   150,   147,     1,   106,   152,   151,   131,    42,
      80,   103,   156,    52,    70,   155,    64,   128,   122,    39,
      50,   149,    64,    61,    55,    81,    70,    42,    45,    37,
     132,   100,   186,   134,    58,   135,   210,   136,   137,   158,
     145,   138,   162,   142,    67,   211,   163,    71,   165,   139,
     140,    65,   141,    47,   144,    53,    82,    65,    62,    71,
     168,   214,    40,     2,     3,   161,     4,   146,     5,    43,
       6,   177,     7,   107,     8,   123,     9,    68,    10,   176,
      11,    56,    12,    94,    13,   129,    14,    43,    15,    59,
      16,   104,    17,   125,    18,    85,    19,   195,    20,   200,
      21,   208,    22,    88,    23,    45,    24,   203,    25,   101,
      26,    91,    27,   119,    28,   201,    29,   164,    30,   172,
      31,   223,    32,    45,    33,    45,    34,    55,    73,   220,
      47,   219,    50,   143,    74,    45,   234,   133,    61,    58,
     230,    52,   113,    81,    45,    45,    73,    67,    47,   153,
      47,    46,    74,   154,    74,   157,   160,   166,    50,   167,
      47,   173,   169,   170,   171,   174,   175,   180,    75,    47,
      47,   182,   192,    62,    82,   181,   116,   183,   184,   188,
      68,   189,   185,    53,    56,   190,    75,   148,    75,    48,
      48,   191,   159,   114,    59,   194,   110,    97,    75,   198,
     202,   204,   205,   196,   197,   199,   206,   207,   212,   215,
     221,   218,   216,   217,   225,   222,   226,   224,   228,   227,
     229,   235,   231,   232,   233,   237,   239,   238,   240,   241,
     243,   242,   247,   244,   245,   248,   250,   252,   255,   246,
     249,   256,   251,   254,   253,   257,    38,   259,   187,    44,
     258,   179,    54,    69,    57,    72,    60,    84,    63,   193,
     178,   209,   236,    76,     0,     0,    83
};

static const short yycheck[] =
{
      11,     6,    92,    81,     4,    25,    98,    95,    34,     7,
      15,    25,   111,    29,    50,   108,    44,    55,    62,    22,
      25,    89,    44,    42,    16,    58,    50,     7,    62,     5,
       0,    25,   175,     6,    20,    23,    53,     8,    10,   117,
      47,    62,    24,    45,    48,    62,     9,    83,    12,    62,
      62,    79,    62,    87,    62,    71,    89,    79,    77,    83,
      43,   204,    65,    63,    64,   133,    66,    62,    68,    67,
      70,   161,    72,   109,    74,   119,    76,    81,    78,   160,
      80,    73,    82,    99,    84,   123,    86,    67,    88,    75,
      90,   105,    92,   121,    94,    93,    96,   187,    98,   192,
     100,   200,   102,    95,   104,    62,   106,   195,   108,   103,
     110,    97,   112,   117,   114,   193,   116,   137,   118,   145,
     120,   213,   122,    62,   124,    62,   126,    16,    85,   210,
      87,   209,   137,    67,    91,    62,   226,    36,    42,    20,
     221,    29,    62,    58,    62,    62,    85,    48,    87,    62,
      87,    69,    91,    62,    91,    46,    62,    17,   163,    62,
      87,    12,    62,    49,    47,    26,    28,    30,   125,    87,
      87,    12,   183,    77,    89,    62,   115,    62,     9,    25,
      81,    11,    62,    71,    73,    62,   125,    86,   125,   107,
     107,    18,   126,   113,    75,    51,   111,   101,   125,    12,
      52,    27,    12,    62,    62,    62,    31,    19,    40,    13,
      54,    59,    62,    62,    32,    62,    12,    62,    11,    62,
      56,    60,    62,    14,    33,    62,    41,    56,    15,    62,
      12,    21,    34,    57,    62,    57,    31,    35,    37,    62,
      61,    38,    62,    62,    36,    62,     3,    61,   177,     5,
      39,   163,     7,    12,     8,    13,     9,    17,    10,   184,
     162,   201,   228,    14,    -1,    -1,    16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     4,    63,    64,    66,    68,    70,    72,    74,    76,
      78,    80,    82,    84,    86,    88,    90,    92,    94,    96,
      98,   100,   102,   104,   106,   108,   110,   112,   114,   116,
     118,   120,   122,   124,   126,   128,   129,     5,   128,    22,
      65,   130,     7,    67,   131,    62,    69,    87,   107,   132,
     142,   152,    29,    71,   133,    16,    73,   134,    20,    75,
     135,    42,    77,   137,    44,    79,   138,    48,    81,   139,
      50,    83,   140,    85,    91,   125,   141,   142,   144,   161,
     142,    58,    89,   143,   144,    93,   131,   145,    95,   134,
     146,    97,   135,   147,    99,   133,   148,   101,   137,   149,
      25,   103,   150,    25,   105,   151,   152,   109,   140,   153,
     111,   143,   154,    62,   113,   155,   115,   141,   156,   117,
     139,   157,    62,   119,   158,   121,   138,   159,    55,   123,
     160,   161,     0,   145,     6,    23,     8,    10,    62,    62,
      62,    62,    45,   159,    62,    47,    62,   156,   145,   146,
     147,   148,   149,    62,    62,   153,   154,    46,   156,   159,
      62,   146,    24,     9,   152,    12,    17,    62,    43,    62,
      49,    47,   161,    12,    26,    28,   160,   147,   150,   132,
      30,    62,    12,    62,     9,    62,   151,   130,    25,    11,
      62,    18,   138,   155,    51,   147,    62,    62,    12,    62,
     153,   156,    52,   148,    27,    12,    31,    19,   154,   157,
      53,    62,    40,   136,   151,    13,    62,    62,    59,   156,
     160,    54,    62,   149,    62,    32,    12,    62,    11,    56,
     160,    62,    14,    33,   147,    60,   158,    62,    56,    41,
      15,    62,    21,    12,    57,    62,    62,    34,    57,    61,
      31,    62,    35,    36,    62,    37,    38,    62,    39,    61
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

    { yyval.Types_type = Create_Types_Types(make_post_src_info(yylsp[-8].first_line, yylsp[0].last_line), yyvsp[-7].OPTMORE_EnumType_type, yyvsp[-6].OPTMORE_PointerType_type, yyvsp[-5].OPTMORE_subtypedef_type, yyvsp[-4].includes2_type, yyvsp[-3].OPTMORE_subtypedef_type, yyvsp[-2].OPTMORE_BindType_type, yyvsp[-1].RootDecl_type.f1, yyvsp[-1].RootDecl_type.f2, yyvsp[0].OPTMORE_StructType_type);
    Decorate_Types(yyval.Types_type);
  ;}
    break;

  case 3:

    {
  ;}
    break;

  case 4:

    { yyval.includes2_type = Create_Types_includes2(make_post_src_info(yylsp[-7].first_line, yylsp[0].last_line), yyvsp[-4].OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_type, yyvsp[-2].Identsym_type, yyvsp[0].OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_type);
  ;}
    break;

  case 5:

    { yyval.EnumType_type = Create_Types_EnumType(make_post_src_info(yylsp[-12].first_line, yylsp[0].last_line), yyvsp[-9].Enums_type, yyvsp[-7].Identsym_type, yyvsp[-4].Identsym_type, yyvsp[-1].Identsym_type, yyvsp[0].Intsym_type);
  ;}
    break;

  case 6:

    {
    yyval.Enums_type = yyvsp[0].ALT_TypeName_SEP_commasym_NL_type;
  ;}
    break;

  case 7:

    { yyval.BindType_type = Create_Types_BindType(make_post_src_info(yylsp[-21].first_line, yylsp[0].last_line), yyvsp[-20].Identsym_type, yyvsp[-17].Identsym_type, yyvsp[-14].Identsym_type, yyvsp[-11].Identsym_type, yyvsp[-8].Identsym_type, yyvsp[-5].Identsym_type, yyvsp[-2].Identsym_type, yyvsp[0].Intsym_type);
  ;}
    break;

  case 8:

    { yyval.PointerType_type = Create_Types_PointerType(make_post_src_info(yylsp[-10].first_line, yylsp[0].last_line), yyvsp[-9].Identsym_type, yyvsp[-7].Identsym_type, yyvsp[-5].Identsym_type, yyvsp[-3].Identsym_type, yyvsp[-1].OPTMORE_subtypedef_type);
  ;}
    break;

  case 9:

    { yyval.subtypedef_type = Create_Types_subtypedef(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-2].Identsym_type, yyvsp[-1].Identsym_type);
  ;}
    break;

  case 10:

    {
    yyval.RootDecl_type.f1 = yyvsp[-2].Identsym_type;
    yyval.RootDecl_type.f2 = yyvsp[-1].Identsym_type;
  ;}
    break;

  case 11:

    { yyval.StructType_type = Create_Types_StructType(make_post_src_info(yylsp[-9].first_line, yylsp[0].last_line), yyvsp[-8].Identsym_type, yyvsp[-6].Identsym_type, yyvsp[-5].struct_type_type, yyvsp[-4].OPTMORE_macro_type, yyvsp[-3].OPTMORE_CreateFunction_type, yyvsp[-1].Identsym_type);
  ;}
    break;

  case 12:

    { yyval.struct_type_type = Create_Types_struct_type(make_post_src_info(yylsp[-10].first_line, yylsp[0].last_line), yyvsp[-8].Identsym_type, yyvsp[-6].OPT_Identsym__USER_FIELDSsym_type, yyvsp[-5].OPTMORE_field_type, yyvsp[-4].OPT_sub_union_type, yyvsp[-3].OPTMORE_field_type, yyvsp[-1].OPT_Identsym_type);
  ;}
    break;

  case 13:

    {
    yyval.sub_union_type = yyvsp[-1].OPTMORE_struct_type_type;
  ;}
    break;

  case 14:

    { yyval.macro_type = Create_Types_plain_macro(make_post_src_info(yylsp[-10].first_line, yylsp[0].last_line), yyvsp[-9].Identsym_type, yyvsp[-7].Identsym_type, yyvsp[-3].OPTMORE_dotsubdotsym_Identsym_type, yyvsp[-1].Identsym_type);
  ;}
    break;

  case 15:

    { yyval.macro_type = Create_Types_access_macro(make_post_src_info(yylsp[-11].first_line, yylsp[0].last_line), yyvsp[-10].Identsym_type, yyvsp[-8].Identsym_type, yyvsp[-5].Identsym_type, yyvsp[-3].OPTMORE_dotsubdotsym_Identsym_type, yyvsp[-1].Identsym_type);
  ;}
    break;

  case 16:

    { yyval.field_type = Create_Types_field(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-2].TypeNames_type, yyvsp[-1].Identsym_type);
  ;}
    break;

  case 17:

    { yyval.TypeName_type = Create_Types_TypeName(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].Identsym_type);
  ;}
    break;

  case 18:

    { yyval.CreateFunction_type = Create_Types_CreateFunction(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[0].OPTMORE_field_type);
  ;}
    break;

  case 19:

    {
    yyval.TypeNames_type = yyvsp[0].ALT_TypeName_SEP__sym_type;
  ;}
    break;

  case 20:

    {
    yyval.OPTMORE_EnumType_type = NULL;
  ;}
    break;

  case 21:

    {
    yyval.OPTMORE_EnumType_type = Create_List_Types_EnumType(yyvsp[-1].EnumType_type, yyvsp[0].OPTMORE_EnumType_type);
  ;}
    break;

  case 22:

    {
    yyval.OPTMORE_PointerType_type = NULL;
  ;}
    break;

  case 23:

    {
    yyval.OPTMORE_PointerType_type = Create_List_Types_PointerType(yyvsp[-1].PointerType_type, yyvsp[0].OPTMORE_PointerType_type);
  ;}
    break;

  case 24:

    {
    yyval.OPTMORE_subtypedef_type = NULL;
  ;}
    break;

  case 25:

    {
    yyval.OPTMORE_subtypedef_type = Create_List_Types_subtypedef(yyvsp[-1].subtypedef_type, yyvsp[0].OPTMORE_subtypedef_type);
  ;}
    break;

  case 26:

    {
    yyval.OPTMORE_BindType_type = NULL;
  ;}
    break;

  case 27:

    {
    yyval.OPTMORE_BindType_type = Create_List_Types_BindType(yyvsp[-1].BindType_type, yyvsp[0].OPTMORE_BindType_type);
  ;}
    break;

  case 28:

    {
    yyval.OPTMORE_StructType_type = NULL;
  ;}
    break;

  case 29:

    {
    yyval.OPTMORE_StructType_type = Create_List_Types_StructType(yyvsp[-1].StructType_type, yyvsp[0].OPTMORE_StructType_type);
  ;}
    break;

  case 30:

    {
    yyval.OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_type = NULL;
  ;}
    break;

  case 31:

    {
    yyval.OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_type = yyvsp[-1].Identsym_type;
  ;}
    break;

  case 32:

    {
    yyval.OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_type = NULL;
  ;}
    break;

  case 33:

    {
    yyval.OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_type = Create_List_Ident(yyvsp[-2].Identsym_type, yyvsp[0].OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_type);
  ;}
    break;

  case 34:

    {
    yyval.ALT_TypeName_SEP_commasym_NL_type = Create_List_Types_TypeName(yyvsp[0].TypeName_type, NULL);
  ;}
    break;

  case 35:

    {
    yyval.ALT_TypeName_SEP_commasym_NL_type = Create_List_Types_TypeName(yyvsp[-2].TypeName_type, yyvsp[0].ALT_TypeName_SEP_commasym_NL_type);
  ;}
    break;

  case 36:

    {
    yyval.OPTMORE_macro_type = NULL;
  ;}
    break;

  case 37:

    {
    yyval.OPTMORE_macro_type = Create_List_Types_macro(yyvsp[-1].macro_type, yyvsp[0].OPTMORE_macro_type);
  ;}
    break;

  case 38:

    {
    yyval.OPTMORE_CreateFunction_type = NULL;
  ;}
    break;

  case 39:

    {
    yyval.OPTMORE_CreateFunction_type = Create_List_Types_CreateFunction(yyvsp[-1].CreateFunction_type, yyvsp[0].OPTMORE_CreateFunction_type);
  ;}
    break;

  case 40:

    {
    yyval.OPT_Identsym__USER_FIELDSsym_type = NULL;
  ;}
    break;

  case 41:

    {
    yyval.OPT_Identsym__USER_FIELDSsym_type = yyvsp[-1].Identsym_type;
  ;}
    break;

  case 42:

    {
    yyval.OPTMORE_field_type = NULL;
  ;}
    break;

  case 43:

    {
    yyval.OPTMORE_field_type = Create_List_Types_field(yyvsp[-1].field_type, yyvsp[0].OPTMORE_field_type);
  ;}
    break;

  case 44:

    {
    yyval.OPT_sub_union_type = NULL;
  ;}
    break;

  case 45:

    {
    yyval.OPT_sub_union_type = yyvsp[0].sub_union_type;
  ;}
    break;

  case 46:

    {
    yyval.OPT_Identsym_type = NULL;
  ;}
    break;

  case 47:

    {
    yyval.OPT_Identsym_type = yyvsp[0].Identsym_type;
  ;}
    break;

  case 48:

    {
    yyval.OPTMORE_struct_type_type = NULL;
  ;}
    break;

  case 49:

    {
    yyval.OPTMORE_struct_type_type = Create_List_Types_struct_type(yyvsp[-1].struct_type_type, yyvsp[0].OPTMORE_struct_type_type);
  ;}
    break;

  case 50:

    {
    yyval.OPTMORE_dotsubdotsym_Identsym_type = NULL;
  ;}
    break;

  case 51:

    {
    yyval.OPTMORE_dotsubdotsym_Identsym_type = Create_List_Ident(yyvsp[-1].Identsym_type, yyvsp[0].OPTMORE_dotsubdotsym_Identsym_type);
  ;}
    break;

  case 52:

    {
    yyval.ALT_TypeName_SEP__sym_type = Create_List_Types_TypeName(yyvsp[0].TypeName_type, NULL);
  ;}
    break;

  case 53:

    {
    yyval.ALT_TypeName_SEP__sym_type = Create_List_Types_TypeName(yyvsp[-2].TypeName_type, yyvsp[0].ALT_TypeName_SEP__sym_type);
  ;}
    break;

  case 54:

    { yyval.Types_type = (Types_Types)Get_sub_tree (); ;}
    break;

  case 55:

    { Types_multi_action ((void*)yyvsp[0].Types_type); YYACCEPT; ;}
    break;

  case 56:

    { yyval.includes2_type = (Types_includes2)Get_sub_tree (); ;}
    break;

  case 57:

    { Types_multi_action ((void*)yyvsp[0].includes2_type); YYACCEPT; ;}
    break;

  case 58:

    { yyval.EnumType_type = (Types_EnumType)Get_sub_tree (); ;}
    break;

  case 59:

    { Types_multi_action ((void*)yyvsp[0].EnumType_type); YYACCEPT; ;}
    break;

  case 60:

    { yyval.Enums_type = (List_Types_TypeName)Get_sub_tree (); ;}
    break;

  case 61:

    { Types_multi_action ((void*)yyvsp[0].Enums_type); YYACCEPT; ;}
    break;

  case 62:

    { yyval.BindType_type = (Types_BindType)Get_sub_tree (); ;}
    break;

  case 63:

    { Types_multi_action ((void*)yyvsp[0].BindType_type); YYACCEPT; ;}
    break;

  case 64:

    { yyval.PointerType_type = (Types_PointerType)Get_sub_tree (); ;}
    break;

  case 65:

    { Types_multi_action ((void*)yyvsp[0].PointerType_type); YYACCEPT; ;}
    break;

  case 66:

    { yyval.subtypedef_type = (Types_subtypedef)Get_sub_tree (); ;}
    break;

  case 67:

    { Types_multi_action ((void*)yyvsp[0].subtypedef_type); YYACCEPT; ;}
    break;

  case 68:

    { yyval.StructType_type = (Types_StructType)Get_sub_tree (); ;}
    break;

  case 69:

    { Types_multi_action ((void*)yyvsp[0].StructType_type); YYACCEPT; ;}
    break;

  case 70:

    { yyval.struct_type_type = (Types_struct_type)Get_sub_tree (); ;}
    break;

  case 71:

    { Types_multi_action ((void*)yyvsp[0].struct_type_type); YYACCEPT; ;}
    break;

  case 72:

    { yyval.sub_union_type = (List_Types_struct_type)Get_sub_tree (); ;}
    break;

  case 73:

    { Types_multi_action ((void*)yyvsp[0].sub_union_type); YYACCEPT; ;}
    break;

  case 74:

    { yyval.macro_type = (Types_macro)Get_sub_tree (); ;}
    break;

  case 75:

    { Types_multi_action ((void*)yyvsp[0].macro_type); YYACCEPT; ;}
    break;

  case 76:

    { yyval.field_type = (Types_field)Get_sub_tree (); ;}
    break;

  case 77:

    { Types_multi_action ((void*)yyvsp[0].field_type); YYACCEPT; ;}
    break;

  case 78:

    { yyval.TypeName_type = (Types_TypeName)Get_sub_tree (); ;}
    break;

  case 79:

    { Types_multi_action ((void*)yyvsp[0].TypeName_type); YYACCEPT; ;}
    break;

  case 80:

    { yyval.CreateFunction_type = (Types_CreateFunction)Get_sub_tree (); ;}
    break;

  case 81:

    { Types_multi_action ((void*)yyvsp[0].CreateFunction_type); YYACCEPT; ;}
    break;

  case 82:

    { yyval.TypeNames_type = (List_Types_TypeName)Get_sub_tree (); ;}
    break;

  case 83:

    { Types_multi_action ((void*)yyvsp[0].TypeNames_type); YYACCEPT; ;}
    break;

  case 84:

    { yyval.OPTMORE_EnumType_type = (List_Types_EnumType)Get_sub_tree (); ;}
    break;

  case 85:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_EnumType_type); YYACCEPT; ;}
    break;

  case 86:

    { yyval.OPTMORE_PointerType_type = (List_Types_PointerType)Get_sub_tree (); ;}
    break;

  case 87:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_PointerType_type); YYACCEPT; ;}
    break;

  case 88:

    { yyval.OPTMORE_subtypedef_type = (List_Types_subtypedef)Get_sub_tree (); ;}
    break;

  case 89:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_subtypedef_type); YYACCEPT; ;}
    break;

  case 90:

    { yyval.OPTMORE_BindType_type = (List_Types_BindType)Get_sub_tree (); ;}
    break;

  case 91:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_BindType_type); YYACCEPT; ;}
    break;

  case 92:

    { yyval.OPTMORE_StructType_type = (List_Types_StructType)Get_sub_tree (); ;}
    break;

  case 93:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_StructType_type); YYACCEPT; ;}
    break;

  case 94:

    { yyval.OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_type = (Ident)Get_sub_tree (); ;}
    break;

  case 95:

    { Types_multi_action ((void*)yyvsp[0].OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_type); YYACCEPT; ;}
    break;

  case 96:

    { yyval.OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_type = (List_Ident)Get_sub_tree (); ;}
    break;

  case 97:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_type); YYACCEPT; ;}
    break;

  case 98:

    { yyval.ALT_TypeName_SEP_commasym_NL_type = (List_Types_TypeName)Get_sub_tree (); ;}
    break;

  case 99:

    { Types_multi_action ((void*)yyvsp[0].ALT_TypeName_SEP_commasym_NL_type); YYACCEPT; ;}
    break;

  case 100:

    { yyval.OPTMORE_macro_type = (List_Types_macro)Get_sub_tree (); ;}
    break;

  case 101:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_macro_type); YYACCEPT; ;}
    break;

  case 102:

    { yyval.OPTMORE_CreateFunction_type = (List_Types_CreateFunction)Get_sub_tree (); ;}
    break;

  case 103:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_CreateFunction_type); YYACCEPT; ;}
    break;

  case 104:

    { yyval.OPT_Identsym__USER_FIELDSsym_type = (Ident)Get_sub_tree (); ;}
    break;

  case 105:

    { Types_multi_action ((void*)yyvsp[0].OPT_Identsym__USER_FIELDSsym_type); YYACCEPT; ;}
    break;

  case 106:

    { yyval.OPTMORE_field_type = (List_Types_field)Get_sub_tree (); ;}
    break;

  case 107:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_field_type); YYACCEPT; ;}
    break;

  case 108:

    { yyval.OPT_sub_union_type = (List_Types_struct_type)Get_sub_tree (); ;}
    break;

  case 109:

    { Types_multi_action ((void*)yyvsp[0].OPT_sub_union_type); YYACCEPT; ;}
    break;

  case 110:

    { yyval.OPT_Identsym_type = (Ident)Get_sub_tree (); ;}
    break;

  case 111:

    { Types_multi_action ((void*)yyvsp[0].OPT_Identsym_type); YYACCEPT; ;}
    break;

  case 112:

    { yyval.OPTMORE_struct_type_type = (List_Types_struct_type)Get_sub_tree (); ;}
    break;

  case 113:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_struct_type_type); YYACCEPT; ;}
    break;

  case 114:

    { yyval.OPTMORE_dotsubdotsym_Identsym_type = (List_Ident)Get_sub_tree (); ;}
    break;

  case 115:

    { Types_multi_action ((void*)yyvsp[0].OPTMORE_dotsubdotsym_Identsym_type); YYACCEPT; ;}
    break;

  case 116:

    { yyval.ALT_TypeName_SEP__sym_type = (List_Types_TypeName)Get_sub_tree (); ;}
    break;

  case 117:

    { Types_multi_action ((void*)yyvsp[0].ALT_TypeName_SEP__sym_type); YYACCEPT; ;}
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



