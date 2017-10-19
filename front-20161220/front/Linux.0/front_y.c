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
#define yyparse front_parse
#define yylex   front_lex
#define yyerror front_error
#define yylval  front_lval
#define yychar  front_char
#define yydebug front_debug
#define yynerrs front_nerrs
#define yylloc front_lloc

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NONSENSE = 258,
     USEsym = 259,
     commasym = 260,
     NAMESPACEsym = 261,
     FROMsym = 262,
     colonsym = 263,
     ROOTsym = 264,
     SCANsym = 265,
     TYPEsym = 266,
     openparsym = 267,
     closeparsym = 268,
     COMMENTsym = 269,
     lessthansym = 270,
     MEMOsym = 271,
     ENUMsym = 272,
     SKIPsym = 273,
     definessym = 274,
     equalssym = 275,
     SCOPEsym = 276,
     OPENSCOPEsym = 277,
     CLOSESCOPEsym = 278,
     FORWARDsym = 279,
     DEFININGsym = 280,
     REDEFININGsym = 281,
     OVERLOADINGsym = 282,
     tildasym = 283,
     exclaimsym = 284,
     equalsequalssym = 285,
     exclaimequalssym = 286,
     lessthanequalssym = 287,
     greaterthanequalssym = 288,
     ampersandsym = 289,
     ampersandampersandsym = 290,
     verticalbarverticalbarsym = 291,
     hatsym = 292,
     plussym = 293,
     minussym = 294,
     starsym = 295,
     slashsym = 296,
     percentsym = 297,
     lessthanlessthansym = 298,
     greaterthangreaterthansym = 299,
     dotsym = 300,
     NULLsym = 301,
     APPLIEDsym = 302,
     NAMEsym = 303,
     FIELDsym = 304,
     WARNINGsym = 305,
     open2symsym = 306,
     verticalbarsym = 307,
     LeftOrsym = 308,
     RightOrsym = 309,
     Xorsym = 310,
     openbrksym = 311,
     closebrksym = 312,
     openchainsym = 313,
     closechainsym = 314,
     EMPTYsym = 315,
     backslashbackslashsym = 316,
     LAYOUTsym = 317,
     COMPAREsym = 318,
     CREATEsym = 319,
     CHECKSsym = 320,
     TRAVERSEsym = 321,
     CLEARsym = 322,
     DONT_CLEARsym = 323,
     Newlinesym = 324,
     LeftAndsym = 325,
     RightAndsym = 326,
     alternate_leftsym = 327,
     alternate_rightsym = 328,
     greaterthansym = 329,
     IFsym = 330,
     THENsym = 331,
     semicolonsym = 332,
     comment1sym = 333,
     comment2sym = 334,
     comment3sym = 335,
     Boolsym = 336,
     Identsym = 337,
     Intsym = 338,
     Keywordsym = 339,
     Charsym = 340,
     Stringsym = 341,
     hole_front = 342,
     start_front = 343,
     hole_Import = 344,
     start_Import = 345,
     hole_ImportedNonTerminals = 346,
     start_ImportedNonTerminals = 347,
     hole_ImportedNonTerminal = 348,
     start_ImportedNonTerminal = 349,
     hole_NonTerminals = 350,
     start_NonTerminals = 351,
     hole_NonTerminal = 352,
     start_NonTerminal = 353,
     hole_Super = 354,
     start_Super = 355,
     hole_Rhs = 356,
     start_Rhs = 357,
     hole_Scoping = 358,
     start_Scoping = 359,
     hole_Alternative = 360,
     start_Alternative = 361,
     hole_Symbol = 362,
     start_Symbol = 363,
     hole_Symbol1 = 364,
     start_Symbol1 = 365,
     hole_AltSymbol = 366,
     start_AltSymbol = 367,
     hole_SymbolSeq = 368,
     start_SymbolSeq = 369,
     hole_And = 370,
     start_And = 371,
     hole_Or = 372,
     start_Or = 373,
     hole_Symbol2 = 374,
     start_Symbol2 = 375,
     hole_SimpleSymbol = 376,
     start_SimpleSymbol = 377,
     hole_IdSym = 378,
     start_IdSym = 379,
     hole_OptType = 380,
     start_OptType = 381,
     hole_DefiningSym = 382,
     start_DefiningSym = 383,
     hole_ScopeExpr = 384,
     start_ScopeExpr = 385,
     hole_Defining_id = 386,
     start_Defining_id = 387,
     hole_Define = 388,
     start_Define = 389,
     hole_Field = 390,
     start_Field = 391,
     hole_FieldInits = 392,
     start_FieldInits = 393,
     hole_FieldInit = 394,
     start_FieldInit = 395,
     hole_Type = 396,
     start_Type = 397,
     hole_Expr = 398,
     start_Expr = 399,
     hole_MonExpr1 = 400,
     start_MonExpr1 = 401,
     hole_SimpleExpr = 402,
     start_SimpleExpr = 403,
     hole_StringOrKeyword = 404,
     start_StringOrKeyword = 405,
     hole_Check = 406,
     start_Check = 407,
     hole_NameSpaceList = 408,
     start_NameSpaceList = 409,
     hole_ExprList = 410,
     start_ExprList = 411,
     hole_IdentList = 412,
     start_IdentList = 413,
     hole_TypeList = 414,
     start_TypeList = 415,
     hole_Alternator = 416,
     start_Alternator = 417,
     hole_ScanInfo = 418,
     start_ScanInfo = 419,
     hole_Defines = 420,
     start_Defines = 421,
     hole_NameSpace = 422,
     start_NameSpace = 423,
     hole_Oper = 424,
     start_Oper = 425,
     hole_NameOrField = 426,
     start_NameOrField = 427,
     hole_OPT_USEsym_IdentList = 428,
     start_OPT_USEsym_IdentList = 429,
     hole_OPT_NAMESPACEsym_NameSpaceList = 430,
     start_OPT_NAMESPACEsym_NameSpaceList = 431,
     hole_OPTMORE_Import = 432,
     start_OPTMORE_Import = 433,
     hole_OPT_NonTerminals = 434,
     start_OPT_NonTerminals = 435,
     hole_ALT_ImportedNonTerminal_SEP_commasym = 436,
     start_ALT_ImportedNonTerminal_SEP_commasym = 437,
     hole_OPT_colonsym_Identsym = 438,
     start_OPT_colonsym_Identsym = 439,
     hole_MORE_NonTerminal = 440,
     start_MORE_NonTerminal = 441,
     hole_OPT_ROOTsym = 442,
     start_OPT_ROOTsym = 443,
     hole_OPT_ScanInfo = 444,
     start_OPT_ScanInfo = 445,
     hole_OPT_Super = 446,
     start_OPT_Super = 447,
     hole_OPT_MEMOsym = 448,
     start_OPT_MEMOsym = 449,
     hole_OPT_ENUMsym = 450,
     start_OPT_ENUMsym = 451,
     hole_OPT_SKIPsym = 452,
     start_OPT_SKIPsym = 453,
     hole_OPTMORE_Scoping = 454,
     start_OPTMORE_Scoping = 455,
     hole_OPT_CHECKSsym_OPTMORE_Check = 456,
     start_OPT_CHECKSsym_OPTMORE_Check = 457,
     hole_OPTMORE_Check = 458,
     start_OPTMORE_Check = 459,
     hole_MORE_Symbol = 460,
     start_MORE_Symbol = 461,
     hole_OPT_ScopeExpr = 462,
     start_OPT_ScopeExpr = 463,
     hole_OPT_WARNINGsym = 464,
     start_OPT_WARNINGsym = 465,
     hole_OPT_NAMEsym_Identsym = 466,
     start_OPT_NAMEsym_Identsym = 467,
     hole_OPT_exclaimsym = 468,
     start_OPT_exclaimsym = 469,
     hole_OPT_TYPEsym_Type = 470,
     start_OPT_TYPEsym_Type = 471,
     hole_OPT_FORWARDsym = 472,
     start_OPT_FORWARDsym = 473,
     hole_OPT_NAMESPACEsym_Identsym = 474,
     start_OPT_NAMESPACEsym_Identsym = 475,
     hole_OPT_TRAVERSEsym = 476,
     start_OPT_TRAVERSEsym = 477,
     hole_OPT_CLEARsym = 478,
     start_OPT_CLEARsym = 479,
     hole_OPT_DONT_CLEARsym = 480,
     start_OPT_DONT_CLEARsym = 481,
     hole_ALT_FieldInit_SEP_commasym = 482,
     start_ALT_FieldInit_SEP_commasym = 483,
     hole_OPT_CREATEsym = 484,
     start_OPT_CREATEsym = 485,
     hole_OPT_openparsym_TypeList_closeparsym = 486,
     start_OPT_openparsym_TypeList_closeparsym = 487,
     hole_OPTMORE_Oper = 488,
     start_OPTMORE_Oper = 489,
     hole_OPT_ExprList = 490,
     start_OPT_ExprList = 491,
     hole_MORE_MonExpr1 = 492,
     start_MORE_MonExpr1 = 493,
     hole_ALT_NameSpace_SEP_commasym_SP = 494,
     start_ALT_NameSpace_SEP_commasym_SP = 495,
     hole_ALT_Expr_SEP_commasym_SP = 496,
     start_ALT_Expr_SEP_commasym_SP = 497,
     hole_ALT_Identsym_SEP_commasym_SP = 498,
     start_ALT_Identsym_SEP_commasym_SP = 499,
     hole_ALT_Type_SEP_commasym_SP = 500,
     start_ALT_Type_SEP_commasym_SP = 501,
     hole_OPT_COMMENTsym = 502,
     start_OPT_COMMENTsym = 503
   };
#endif
#define NONSENSE 258
#define USEsym 259
#define commasym 260
#define NAMESPACEsym 261
#define FROMsym 262
#define colonsym 263
#define ROOTsym 264
#define SCANsym 265
#define TYPEsym 266
#define openparsym 267
#define closeparsym 268
#define COMMENTsym 269
#define lessthansym 270
#define MEMOsym 271
#define ENUMsym 272
#define SKIPsym 273
#define definessym 274
#define equalssym 275
#define SCOPEsym 276
#define OPENSCOPEsym 277
#define CLOSESCOPEsym 278
#define FORWARDsym 279
#define DEFININGsym 280
#define REDEFININGsym 281
#define OVERLOADINGsym 282
#define tildasym 283
#define exclaimsym 284
#define equalsequalssym 285
#define exclaimequalssym 286
#define lessthanequalssym 287
#define greaterthanequalssym 288
#define ampersandsym 289
#define ampersandampersandsym 290
#define verticalbarverticalbarsym 291
#define hatsym 292
#define plussym 293
#define minussym 294
#define starsym 295
#define slashsym 296
#define percentsym 297
#define lessthanlessthansym 298
#define greaterthangreaterthansym 299
#define dotsym 300
#define NULLsym 301
#define APPLIEDsym 302
#define NAMEsym 303
#define FIELDsym 304
#define WARNINGsym 305
#define open2symsym 306
#define verticalbarsym 307
#define LeftOrsym 308
#define RightOrsym 309
#define Xorsym 310
#define openbrksym 311
#define closebrksym 312
#define openchainsym 313
#define closechainsym 314
#define EMPTYsym 315
#define backslashbackslashsym 316
#define LAYOUTsym 317
#define COMPAREsym 318
#define CREATEsym 319
#define CHECKSsym 320
#define TRAVERSEsym 321
#define CLEARsym 322
#define DONT_CLEARsym 323
#define Newlinesym 324
#define LeftAndsym 325
#define RightAndsym 326
#define alternate_leftsym 327
#define alternate_rightsym 328
#define greaterthansym 329
#define IFsym 330
#define THENsym 331
#define semicolonsym 332
#define comment1sym 333
#define comment2sym 334
#define comment3sym 335
#define Boolsym 336
#define Identsym 337
#define Intsym 338
#define Keywordsym 339
#define Charsym 340
#define Stringsym 341
#define hole_front 342
#define start_front 343
#define hole_Import 344
#define start_Import 345
#define hole_ImportedNonTerminals 346
#define start_ImportedNonTerminals 347
#define hole_ImportedNonTerminal 348
#define start_ImportedNonTerminal 349
#define hole_NonTerminals 350
#define start_NonTerminals 351
#define hole_NonTerminal 352
#define start_NonTerminal 353
#define hole_Super 354
#define start_Super 355
#define hole_Rhs 356
#define start_Rhs 357
#define hole_Scoping 358
#define start_Scoping 359
#define hole_Alternative 360
#define start_Alternative 361
#define hole_Symbol 362
#define start_Symbol 363
#define hole_Symbol1 364
#define start_Symbol1 365
#define hole_AltSymbol 366
#define start_AltSymbol 367
#define hole_SymbolSeq 368
#define start_SymbolSeq 369
#define hole_And 370
#define start_And 371
#define hole_Or 372
#define start_Or 373
#define hole_Symbol2 374
#define start_Symbol2 375
#define hole_SimpleSymbol 376
#define start_SimpleSymbol 377
#define hole_IdSym 378
#define start_IdSym 379
#define hole_OptType 380
#define start_OptType 381
#define hole_DefiningSym 382
#define start_DefiningSym 383
#define hole_ScopeExpr 384
#define start_ScopeExpr 385
#define hole_Defining_id 386
#define start_Defining_id 387
#define hole_Define 388
#define start_Define 389
#define hole_Field 390
#define start_Field 391
#define hole_FieldInits 392
#define start_FieldInits 393
#define hole_FieldInit 394
#define start_FieldInit 395
#define hole_Type 396
#define start_Type 397
#define hole_Expr 398
#define start_Expr 399
#define hole_MonExpr1 400
#define start_MonExpr1 401
#define hole_SimpleExpr 402
#define start_SimpleExpr 403
#define hole_StringOrKeyword 404
#define start_StringOrKeyword 405
#define hole_Check 406
#define start_Check 407
#define hole_NameSpaceList 408
#define start_NameSpaceList 409
#define hole_ExprList 410
#define start_ExprList 411
#define hole_IdentList 412
#define start_IdentList 413
#define hole_TypeList 414
#define start_TypeList 415
#define hole_Alternator 416
#define start_Alternator 417
#define hole_ScanInfo 418
#define start_ScanInfo 419
#define hole_Defines 420
#define start_Defines 421
#define hole_NameSpace 422
#define start_NameSpace 423
#define hole_Oper 424
#define start_Oper 425
#define hole_NameOrField 426
#define start_NameOrField 427
#define hole_OPT_USEsym_IdentList 428
#define start_OPT_USEsym_IdentList 429
#define hole_OPT_NAMESPACEsym_NameSpaceList 430
#define start_OPT_NAMESPACEsym_NameSpaceList 431
#define hole_OPTMORE_Import 432
#define start_OPTMORE_Import 433
#define hole_OPT_NonTerminals 434
#define start_OPT_NonTerminals 435
#define hole_ALT_ImportedNonTerminal_SEP_commasym 436
#define start_ALT_ImportedNonTerminal_SEP_commasym 437
#define hole_OPT_colonsym_Identsym 438
#define start_OPT_colonsym_Identsym 439
#define hole_MORE_NonTerminal 440
#define start_MORE_NonTerminal 441
#define hole_OPT_ROOTsym 442
#define start_OPT_ROOTsym 443
#define hole_OPT_ScanInfo 444
#define start_OPT_ScanInfo 445
#define hole_OPT_Super 446
#define start_OPT_Super 447
#define hole_OPT_MEMOsym 448
#define start_OPT_MEMOsym 449
#define hole_OPT_ENUMsym 450
#define start_OPT_ENUMsym 451
#define hole_OPT_SKIPsym 452
#define start_OPT_SKIPsym 453
#define hole_OPTMORE_Scoping 454
#define start_OPTMORE_Scoping 455
#define hole_OPT_CHECKSsym_OPTMORE_Check 456
#define start_OPT_CHECKSsym_OPTMORE_Check 457
#define hole_OPTMORE_Check 458
#define start_OPTMORE_Check 459
#define hole_MORE_Symbol 460
#define start_MORE_Symbol 461
#define hole_OPT_ScopeExpr 462
#define start_OPT_ScopeExpr 463
#define hole_OPT_WARNINGsym 464
#define start_OPT_WARNINGsym 465
#define hole_OPT_NAMEsym_Identsym 466
#define start_OPT_NAMEsym_Identsym 467
#define hole_OPT_exclaimsym 468
#define start_OPT_exclaimsym 469
#define hole_OPT_TYPEsym_Type 470
#define start_OPT_TYPEsym_Type 471
#define hole_OPT_FORWARDsym 472
#define start_OPT_FORWARDsym 473
#define hole_OPT_NAMESPACEsym_Identsym 474
#define start_OPT_NAMESPACEsym_Identsym 475
#define hole_OPT_TRAVERSEsym 476
#define start_OPT_TRAVERSEsym 477
#define hole_OPT_CLEARsym 478
#define start_OPT_CLEARsym 479
#define hole_OPT_DONT_CLEARsym 480
#define start_OPT_DONT_CLEARsym 481
#define hole_ALT_FieldInit_SEP_commasym 482
#define start_ALT_FieldInit_SEP_commasym 483
#define hole_OPT_CREATEsym 484
#define start_OPT_CREATEsym 485
#define hole_OPT_openparsym_TypeList_closeparsym 486
#define start_OPT_openparsym_TypeList_closeparsym 487
#define hole_OPTMORE_Oper 488
#define start_OPTMORE_Oper 489
#define hole_OPT_ExprList 490
#define start_OPT_ExprList 491
#define hole_MORE_MonExpr1 492
#define start_MORE_MonExpr1 493
#define hole_ALT_NameSpace_SEP_commasym_SP 494
#define start_ALT_NameSpace_SEP_commasym_SP 495
#define hole_ALT_Expr_SEP_commasym_SP 496
#define start_ALT_Expr_SEP_commasym_SP 497
#define hole_ALT_Identsym_SEP_commasym_SP 498
#define start_ALT_Identsym_SEP_commasym_SP 499
#define hole_ALT_Type_SEP_commasym_SP 500
#define start_ALT_Type_SEP_commasym_SP 501
#define hole_OPT_COMMENTsym 502
#define start_OPT_COMMENTsym 503




/* Copy the first part of user declarations.  */


#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "front.h"

extern int input_line_nr;

struct yy_buffer_state *front_dummy_state (void);
struct yy_buffer_state *front_scanner_state (void);


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
Ident lessthansym_type;
Ident definessym_type;
Ident equalssym_type;
Ident tildasym_type;
Ident exclaimsym_type;
Ident equalsequalssym_type;
Ident exclaimequalssym_type;
Ident lessthanequalssym_type;
Ident greaterthanequalssym_type;
Ident ampersandsym_type;
Ident ampersandampersandsym_type;
Ident verticalbarverticalbarsym_type;
Ident hatsym_type;
Ident plussym_type;
Ident minussym_type;
Ident starsym_type;
Ident slashsym_type;
Ident percentsym_type;
Ident lessthanlessthansym_type;
Ident greaterthangreaterthansym_type;
Ident greaterthansym_type;
Bool Boolsym_type;
Ident Identsym_type;
Int Intsym_type;
String Keywordsym_type;
String Charsym_type;
String Stringsym_type;
front_front front_type;
front_Import Import_type;
List_front_ImportedNonTerminal ImportedNonTerminals_type;
front_ImportedNonTerminal ImportedNonTerminal_type;
List_front_NonTerminal NonTerminals_type;
front_NonTerminal NonTerminal_type;
front_Super Super_type;
front_Rhs Rhs_type;
front_Scoping Scoping_type;
struct {
  Ident f1;
  List_front_Alternative f2;
  List_front_Or f3;
  Ident f4;
  front_Symbol f5;
} Choices_type;
struct {
  List_front_Alternative f1;
  List_front_Or f2;
} ChoiceList_type;
front_Alternative Alternative_type;
front_Symbol Symbol_type;
Symbol Symbol1_type;
front_AltSymbol AltSymbol_type;
front_SymbolSeq SymbolSeq_type;
front_And And_type;
front_Or Or_type;
front_Symbol2 Symbol2_type;
front_SimpleSymbol SimpleSymbol_type;
front_IdSym IdSym_type;
struct {
  List_front_Symbol f1;
  List_front_Or f2;
} Alternatives_type;
front_Type OptType_type;
front_DefiningSym DefiningSym_type;
front_Expr ScopeExpr_type;
front_Defining_id Defining_id_type;
front_Define Define_type;
front_Field Field_type;
List_front_FieldInit FieldInits_type;
front_FieldInit FieldInit_type;
front_Type Type_type;
front_Expr Expr_type;
front_MonExpr1 MonExpr1_type;
front_SimpleExpr SimpleExpr_type;
String StringOrKeyword_type;
front_Check Check_type;
List_front_NameSpace NameSpaceList_type;
List_front_Expr ExprList_type;
List_Ident IdentList_type;
List_front_Type TypeList_type;
front_Alternator Alternator_type;
front_ScanInfo ScanInfo_type;
front_Defines Defines_type;
front_NameSpace NameSpace_type;
Ident Oper_type;
front_NameOrField NameOrField_type;
List_Ident OPT_USEsym_IdentList_type;
List_front_NameSpace OPT_NAMESPACEsym_NameSpaceList_type;
List_front_Import OPTMORE_Import_type;
List_front_NonTerminal OPT_NonTerminals_type;
List_front_ImportedNonTerminal ALT_ImportedNonTerminal_SEP_commasym_type;
Ident OPT_colonsym_Identsym_type;
List_front_NonTerminal MORE_NonTerminal_type;
Bool OPT_ROOTsym_type;
front_ScanInfo OPT_ScanInfo_type;
front_Super OPT_Super_type;
Bool OPT_MEMOsym_type;
Bool OPT_ENUMsym_type;
Bool OPT_SKIPsym_type;
List_front_Scoping OPTMORE_Scoping_type;
struct {
  Ident f1;
  List_front_Alternative f2;
  List_front_Or f3;
  Ident f4;
  front_Symbol f5;
} OPT_Choices_type;
List_front_Check OPT_CHECKSsym_OPTMORE_Check_type;
List_front_Check OPTMORE_Check_type;
struct {
  List_front_Alternative f1;
  List_front_Or f2;
} ALT_Alternative_SEP_Or_type;
List_front_Symbol MORE_Symbol_type;
struct {
  List_front_Symbol f1;
  List_front_Field f2;
  List_front_And f3;
} OPT_ALT_ONCE_SymbolORField_SEP_And_type;
struct {
  List_front_Symbol f1;
  List_front_Field f2;
  List_front_And f3;
} ALT_ONCE_SymbolORField_SEP_And_type;
struct {
  front_Symbol f1;
  front_Field f2;
} ONCE_SymbolORField_type;
front_Expr OPT_ScopeExpr_type;
Bool OPT_WARNINGsym_type;
Ident OPT_NAMEsym_Identsym_type;
Bool OPT_exclaimsym_type;
struct {
  List_front_Symbol f1;
  List_front_Or f2;
} ALT_Symbol1_SEP_Or_SP_type;
front_Type OPT_TYPEsym_Type_type;
Bool OPT_FORWARDsym_type;
Ident OPT_NAMESPACEsym_Identsym_type;
Bool OPT_TRAVERSEsym_type;
Bool OPT_CLEARsym_type;
Bool OPT_DONT_CLEARsym_type;
List_front_FieldInit ALT_FieldInit_SEP_commasym_type;
Bool OPT_CREATEsym_type;
List_front_Type OPT_openparsym_TypeList_closeparsym_type;
struct {
  List_front_Expr f1;
  List_Ident f2;
} ALT_MonExpr1_SEP_SP_Oper_type;
List_Ident OPTMORE_Oper_type;
List_front_Expr OPT_ExprList_type;
List_front_Expr MORE_MonExpr1_type;
List_front_NameSpace ALT_NameSpace_SEP_commasym_SP_type;
List_front_Expr ALT_Expr_SEP_commasym_SP_type;
List_Ident ALT_Identsym_SEP_commasym_SP_type;
List_front_Type ALT_Type_SEP_commasym_SP_type;
Bool OPT_COMMENTsym_type;
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
#define YYFINAL  387
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1397

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  249
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  92
/* YYNRULES -- Number of rules. */
#define YYNRULES  358
/* YYNRULES -- Number of states. */
#define YYNSTATES  518

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   503

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
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     8,    13,    15,    18,    20,    31,    34,
      37,    42,    44,    46,    48,    53,    55,    61,    63,    67,
      69,    71,    73,    77,    79,    81,    83,    85,    86,    88,
      90,    92,    94,    98,   100,   102,   104,   111,   115,   118,
     121,   126,   131,   135,   140,   142,   145,   148,   151,   153,
     155,   161,   164,   166,   170,   172,   174,   176,   185,   187,
     190,   193,   196,   199,   202,   205,   207,   210,   212,   216,
     218,   220,   222,   224,   229,   231,   233,   235,   241,   243,
     245,   247,   249,   251,   253,   257,   259,   261,   263,   265,
     267,   269,   271,   273,   275,   277,   279,   281,   283,   285,
     287,   289,   291,   293,   295,   297,   299,   301,   302,   305,
     306,   309,   310,   313,   314,   316,   318,   322,   323,   326,
     328,   331,   332,   334,   335,   337,   338,   340,   341,   343,
     344,   346,   347,   349,   350,   353,   354,   356,   357,   360,
     361,   364,   366,   370,   372,   375,   376,   378,   380,   384,
     386,   388,   389,   391,   392,   394,   395,   398,   399,   401,
     403,   407,   408,   411,   412,   414,   415,   418,   419,   421,
     422,   424,   425,   427,   429,   433,   434,   436,   437,   441,
     443,   447,   448,   451,   452,   454,   456,   459,   461,   465,
     467,   471,   473,   477,   479,   483,   484,   486,   488,   491,
     493,   496,   498,   501,   503,   506,   508,   511,   513,   516,
     518,   521,   523,   526,   528,   531,   533,   536,   538,   541,
     543,   546,   548,   551,   553,   556,   558,   561,   563,   566,
     568,   571,   573,   576,   578,   581,   583,   586,   588,   591,
     593,   596,   598,   601,   603,   606,   608,   611,   613,   616,
     618,   621,   623,   626,   628,   631,   633,   636,   638,   641,
     643,   646,   648,   651,   653,   656,   658,   661,   663,   666,
     668,   671,   673,   676,   678,   681,   683,   686,   688,   691,
     693,   696,   698,   701,   703,   706,   708,   711,   713,   716,
     718,   721,   723,   726,   728,   731,   733,   736,   738,   741,
     743,   746,   748,   751,   753,   756,   758,   761,   763,   766,
     768,   771,   773,   776,   778,   781,   783,   786,   788,   791,
     793,   796,   798,   801,   803,   806,   808,   811,   813,   816,
     818,   821,   823,   826,   828,   831,   833,   836,   838,   841,
     843,   846,   848,   851,   853,   856,   858,   861,   863,   866,
     868,   871,   873,   876,   878,   881,   883,   886,   888
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     250,     0,    -1,   296,   297,   298,   299,    -1,     7,    82,
       8,   252,    -1,   300,    -1,    82,   301,    -1,   302,    -1,
     303,   304,    82,   305,   306,   307,   308,   292,   257,    77,
      -1,    15,    82,    -1,     8,    82,    -1,   309,   263,   310,
     311,    -1,    21,    -1,    22,    -1,    23,    -1,    15,   260,
      74,   263,    -1,   313,    -1,    82,   306,   308,    19,   257,
      -1,   263,    -1,    82,     8,   268,    -1,   268,    -1,   264,
      -1,   265,    -1,   265,   290,   314,    -1,   315,    -1,    69,
      -1,    70,    -1,    71,    -1,    -1,    52,    -1,    53,    -1,
      54,    -1,    55,    -1,   269,    63,    82,    -1,   269,    -1,
     273,    -1,   270,    -1,    47,    82,   295,    82,   318,   319,
      -1,    86,   320,   272,    -1,    85,   272,    -1,    84,   272,
      -1,    51,   271,    13,    13,    -1,    56,   271,    57,   321,
      -1,    58,   271,    59,    -1,    58,   271,    59,    38,    -1,
      60,    -1,    61,   284,    -1,    62,   281,    -1,    82,   272,
      -1,   322,    -1,   323,    -1,   324,   276,   275,   325,   318,
      -1,    21,   281,    -1,   270,    -1,    12,   281,    13,    -1,
      25,    -1,    26,    -1,    27,    -1,    82,     8,   280,    20,
     278,   326,   327,   328,    -1,   329,    -1,   330,   281,    -1,
      21,   281,    -1,    25,   281,    -1,    47,   281,    -1,    65,
     281,    -1,    82,   331,    -1,   332,    -1,   333,   283,    -1,
      82,    -1,   283,    45,    82,    -1,    83,    -1,    81,    -1,
     284,    -1,    46,    -1,   283,    12,   334,    13,    -1,    86,
      -1,    84,    -1,    85,    -1,    75,   281,    76,   319,   335,
      -1,   336,    -1,   337,    -1,   338,    -1,   339,    -1,    72,
      -1,    73,    -1,    10,   272,   340,    -1,    19,    -1,    20,
      -1,    82,    -1,    28,    -1,    29,    -1,    30,    -1,    31,
      -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,    36,
      -1,    37,    -1,    38,    -1,    39,    -1,    40,    -1,    41,
      -1,    42,    -1,    43,    -1,    44,    -1,    48,    -1,    49,
      -1,    -1,     4,   288,    -1,    -1,     6,   286,    -1,    -1,
     251,   298,    -1,    -1,   254,    -1,   253,    -1,   253,     5,
     300,    -1,    -1,     8,    82,    -1,   255,    -1,   255,   302,
      -1,    -1,     9,    -1,    -1,   291,    -1,    -1,   256,    -1,
      -1,    16,    -1,    -1,    17,    -1,    -1,    18,    -1,    -1,
     258,   309,    -1,    -1,   259,    -1,    -1,    65,   312,    -1,
      -1,   285,   312,    -1,   261,    -1,   261,   267,   313,    -1,
     262,    -1,   262,   314,    -1,    -1,   316,    -1,   317,    -1,
     317,   266,   316,    -1,   262,    -1,   277,    -1,    -1,   274,
      -1,    -1,    50,    -1,    -1,    48,    82,    -1,    -1,    29,
      -1,   263,    -1,   263,   267,   322,    -1,    -1,    11,   280,
      -1,    -1,    24,    -1,    -1,     6,    82,    -1,    -1,    66,
      -1,    -1,    67,    -1,    -1,    68,    -1,   279,    -1,   279,
       5,   329,    -1,    -1,    64,    -1,    -1,    12,   289,    13,
      -1,   282,    -1,   282,   294,   332,    -1,    -1,   294,   333,
      -1,    -1,   287,    -1,   282,    -1,   282,   335,    -1,   293,
      -1,   293,     5,   336,    -1,   281,    -1,   281,     5,   337,
      -1,    82,    -1,    82,     5,   338,    -1,   280,    -1,   280,
       5,   339,    -1,    -1,    14,    -1,    87,    -1,    88,   250,
      -1,    89,    -1,    90,   251,    -1,    91,    -1,    92,   252,
      -1,    93,    -1,    94,   253,    -1,    95,    -1,    96,   254,
      -1,    97,    -1,    98,   255,    -1,    99,    -1,   100,   256,
      -1,   101,    -1,   102,   257,    -1,   103,    -1,   104,   258,
      -1,   105,    -1,   106,   261,    -1,   107,    -1,   108,   262,
      -1,   109,    -1,   110,   263,    -1,   111,    -1,   112,   264,
      -1,   113,    -1,   114,   265,    -1,   115,    -1,   116,   266,
      -1,   117,    -1,   118,   267,    -1,   119,    -1,   120,   268,
      -1,   121,    -1,   122,   269,    -1,   123,    -1,   124,   270,
      -1,   125,    -1,   126,   272,    -1,   127,    -1,   128,   273,
      -1,   129,    -1,   130,   274,    -1,   131,    -1,   132,   275,
      -1,   133,    -1,   134,   276,    -1,   135,    -1,   136,   277,
      -1,   137,    -1,   138,   278,    -1,   139,    -1,   140,   279,
      -1,   141,    -1,   142,   280,    -1,   143,    -1,   144,   281,
      -1,   145,    -1,   146,   282,    -1,   147,    -1,   148,   283,
      -1,   149,    -1,   150,   284,    -1,   151,    -1,   152,   285,
      -1,   153,    -1,   154,   286,    -1,   155,    -1,   156,   287,
      -1,   157,    -1,   158,   288,    -1,   159,    -1,   160,   289,
      -1,   161,    -1,   162,   290,    -1,   163,    -1,   164,   291,
      -1,   165,    -1,   166,   292,    -1,   167,    -1,   168,   293,
      -1,   169,    -1,   170,   294,    -1,   171,    -1,   172,   295,
      -1,   173,    -1,   174,   296,    -1,   175,    -1,   176,   297,
      -1,   177,    -1,   178,   298,    -1,   179,    -1,   180,   299,
      -1,   181,    -1,   182,   300,    -1,   183,    -1,   184,   301,
      -1,   185,    -1,   186,   302,    -1,   187,    -1,   188,   303,
      -1,   189,    -1,   190,   304,    -1,   191,    -1,   192,   305,
      -1,   193,    -1,   194,   306,    -1,   195,    -1,   196,   307,
      -1,   197,    -1,   198,   308,    -1,   199,    -1,   200,   309,
      -1,   201,    -1,   202,   311,    -1,   203,    -1,   204,   312,
      -1,   205,    -1,   206,   314,    -1,   207,    -1,   208,   318,
      -1,   209,    -1,   210,   319,    -1,   211,    -1,   212,   320,
      -1,   213,    -1,   214,   321,    -1,   215,    -1,   216,   323,
      -1,   217,    -1,   218,   324,    -1,   219,    -1,   220,   325,
      -1,   221,    -1,   222,   326,    -1,   223,    -1,   224,   327,
      -1,   225,    -1,   226,   328,    -1,   227,    -1,   228,   329,
      -1,   229,    -1,   230,   330,    -1,   231,    -1,   232,   331,
      -1,   233,    -1,   234,   333,    -1,   235,    -1,   236,   334,
      -1,   237,    -1,   238,   335,    -1,   239,    -1,   240,   336,
      -1,   241,    -1,   242,   337,    -1,   243,    -1,   244,   338,
      -1,   245,    -1,   246,   339,    -1,   247,    -1,   248,   340,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   599,   599,   609,   618,   626,   633,   641,   656,   663,
     670,   679,   685,   691,   697,   712,   721,   731,   737,   745,
     752,   759,   766,   774,   780,   786,   792,   799,   803,   809,
     815,   821,   827,   835,   842,   849,   856,   867,   875,   882,
     889,   898,   907,   915,   924,   930,   937,   944,   951,   960,
     968,   978,   987,   993,  1001,  1007,  1013,  1019,  1032,  1040,
    1047,  1054,  1061,  1068,  1075,  1082,  1088,  1095,  1101,  1109,
    1115,  1121,  1127,  1133,  1142,  1149,  1156,  1163,  1173,  1181,
    1189,  1197,  1205,  1211,  1217,  1225,  1231,  1237,  1243,  1250,
    1257,  1264,  1271,  1278,  1285,  1292,  1299,  1306,  1313,  1320,
    1327,  1334,  1341,  1348,  1355,  1362,  1368,  1376,  1382,  1390,
    1396,  1404,  1410,  1418,  1424,  1431,  1438,  1447,  1453,  1461,
    1468,  1476,  1482,  1489,  1495,  1502,  1508,  1515,  1521,  1528,
    1534,  1541,  1547,  1554,  1560,  1568,  1578,  1589,  1595,  1603,
    1609,  1617,  1625,  1635,  1642,  1650,  1658,  1667,  1676,  1687,
    1695,  1703,  1709,  1716,  1722,  1729,  1735,  1743,  1749,  1756,
    1764,  1774,  1780,  1788,  1794,  1801,  1807,  1815,  1821,  1828,
    1834,  1841,  1847,  1854,  1861,  1870,  1876,  1883,  1889,  1898,
    1906,  1916,  1922,  1930,  1936,  1943,  1950,  1958,  1965,  1974,
    1981,  1990,  1997,  2006,  2013,  2022,  2028,  2035,  2040,  2046,
    2051,  2057,  2062,  2068,  2073,  2079,  2084,  2090,  2095,  2101,
    2106,  2112,  2117,  2123,  2128,  2134,  2139,  2145,  2150,  2156,
    2161,  2167,  2172,  2178,  2183,  2189,  2194,  2200,  2205,  2211,
    2216,  2222,  2227,  2233,  2238,  2244,  2249,  2255,  2260,  2266,
    2271,  2277,  2282,  2288,  2293,  2299,  2304,  2310,  2315,  2321,
    2326,  2332,  2337,  2343,  2348,  2354,  2359,  2365,  2370,  2376,
    2381,  2387,  2392,  2398,  2403,  2409,  2414,  2420,  2425,  2431,
    2436,  2442,  2447,  2453,  2458,  2464,  2469,  2475,  2480,  2486,
    2491,  2497,  2502,  2508,  2513,  2519,  2524,  2530,  2535,  2541,
    2546,  2552,  2557,  2563,  2568,  2574,  2579,  2585,  2590,  2596,
    2601,  2607,  2612,  2618,  2623,  2629,  2634,  2640,  2645,  2651,
    2656,  2662,  2667,  2673,  2678,  2684,  2689,  2695,  2700,  2706,
    2711,  2717,  2722,  2728,  2733,  2739,  2744,  2750,  2755,  2761,
    2766,  2772,  2777,  2783,  2788,  2794,  2799,  2805,  2810,  2816,
    2821,  2827,  2832,  2838,  2843,  2849,  2854,  2860,  2865,  2871,
    2876,  2882,  2887,  2893,  2898,  2904,  2909,  2915,  2920
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NONSENSE", "USEsym", "commasym",
  "NAMESPACEsym", "FROMsym", "colonsym", "ROOTsym", "SCANsym", "TYPEsym",
  "openparsym", "closeparsym", "COMMENTsym", "lessthansym", "MEMOsym",
  "ENUMsym", "SKIPsym", "definessym", "equalssym", "SCOPEsym",
  "OPENSCOPEsym", "CLOSESCOPEsym", "FORWARDsym", "DEFININGsym",
  "REDEFININGsym", "OVERLOADINGsym", "tildasym", "exclaimsym",
  "equalsequalssym", "exclaimequalssym", "lessthanequalssym",
  "greaterthanequalssym", "ampersandsym", "ampersandampersandsym",
  "verticalbarverticalbarsym", "hatsym", "plussym", "minussym", "starsym",
  "slashsym", "percentsym", "lessthanlessthansym",
  "greaterthangreaterthansym", "dotsym", "NULLsym", "APPLIEDsym",
  "NAMEsym", "FIELDsym", "WARNINGsym", "open2symsym", "verticalbarsym",
  "LeftOrsym", "RightOrsym", "Xorsym", "openbrksym", "closebrksym",
  "openchainsym", "closechainsym", "EMPTYsym", "backslashbackslashsym",
  "LAYOUTsym", "COMPAREsym", "CREATEsym", "CHECKSsym", "TRAVERSEsym",
  "CLEARsym", "DONT_CLEARsym", "Newlinesym", "LeftAndsym", "RightAndsym",
  "alternate_leftsym", "alternate_rightsym", "greaterthansym", "IFsym",
  "THENsym", "semicolonsym", "comment1sym", "comment2sym", "comment3sym",
  "Boolsym", "Identsym", "Intsym", "Keywordsym", "Charsym", "Stringsym",
  "hole_front", "start_front", "hole_Import", "start_Import",
  "hole_ImportedNonTerminals", "start_ImportedNonTerminals",
  "hole_ImportedNonTerminal", "start_ImportedNonTerminal",
  "hole_NonTerminals", "start_NonTerminals", "hole_NonTerminal",
  "start_NonTerminal", "hole_Super", "start_Super", "hole_Rhs",
  "start_Rhs", "hole_Scoping", "start_Scoping", "hole_Alternative",
  "start_Alternative", "hole_Symbol", "start_Symbol", "hole_Symbol1",
  "start_Symbol1", "hole_AltSymbol", "start_AltSymbol", "hole_SymbolSeq",
  "start_SymbolSeq", "hole_And", "start_And", "hole_Or", "start_Or",
  "hole_Symbol2", "start_Symbol2", "hole_SimpleSymbol",
  "start_SimpleSymbol", "hole_IdSym", "start_IdSym", "hole_OptType",
  "start_OptType", "hole_DefiningSym", "start_DefiningSym",
  "hole_ScopeExpr", "start_ScopeExpr", "hole_Defining_id",
  "start_Defining_id", "hole_Define", "start_Define", "hole_Field",
  "start_Field", "hole_FieldInits", "start_FieldInits", "hole_FieldInit",
  "start_FieldInit", "hole_Type", "start_Type", "hole_Expr", "start_Expr",
  "hole_MonExpr1", "start_MonExpr1", "hole_SimpleExpr", "start_SimpleExpr",
  "hole_StringOrKeyword", "start_StringOrKeyword", "hole_Check",
  "start_Check", "hole_NameSpaceList", "start_NameSpaceList",
  "hole_ExprList", "start_ExprList", "hole_IdentList", "start_IdentList",
  "hole_TypeList", "start_TypeList", "hole_Alternator", "start_Alternator",
  "hole_ScanInfo", "start_ScanInfo", "hole_Defines", "start_Defines",
  "hole_NameSpace", "start_NameSpace", "hole_Oper", "start_Oper",
  "hole_NameOrField", "start_NameOrField", "hole_OPT_USEsym_IdentList",
  "start_OPT_USEsym_IdentList", "hole_OPT_NAMESPACEsym_NameSpaceList",
  "start_OPT_NAMESPACEsym_NameSpaceList", "hole_OPTMORE_Import",
  "start_OPTMORE_Import", "hole_OPT_NonTerminals",
  "start_OPT_NonTerminals", "hole_ALT_ImportedNonTerminal_SEP_commasym",
  "start_ALT_ImportedNonTerminal_SEP_commasym",
  "hole_OPT_colonsym_Identsym", "start_OPT_colonsym_Identsym",
  "hole_MORE_NonTerminal", "start_MORE_NonTerminal", "hole_OPT_ROOTsym",
  "start_OPT_ROOTsym", "hole_OPT_ScanInfo", "start_OPT_ScanInfo",
  "hole_OPT_Super", "start_OPT_Super", "hole_OPT_MEMOsym",
  "start_OPT_MEMOsym", "hole_OPT_ENUMsym", "start_OPT_ENUMsym",
  "hole_OPT_SKIPsym", "start_OPT_SKIPsym", "hole_OPTMORE_Scoping",
  "start_OPTMORE_Scoping", "hole_OPT_CHECKSsym_OPTMORE_Check",
  "start_OPT_CHECKSsym_OPTMORE_Check", "hole_OPTMORE_Check",
  "start_OPTMORE_Check", "hole_MORE_Symbol", "start_MORE_Symbol",
  "hole_OPT_ScopeExpr", "start_OPT_ScopeExpr", "hole_OPT_WARNINGsym",
  "start_OPT_WARNINGsym", "hole_OPT_NAMEsym_Identsym",
  "start_OPT_NAMEsym_Identsym", "hole_OPT_exclaimsym",
  "start_OPT_exclaimsym", "hole_OPT_TYPEsym_Type",
  "start_OPT_TYPEsym_Type", "hole_OPT_FORWARDsym", "start_OPT_FORWARDsym",
  "hole_OPT_NAMESPACEsym_Identsym", "start_OPT_NAMESPACEsym_Identsym",
  "hole_OPT_TRAVERSEsym", "start_OPT_TRAVERSEsym", "hole_OPT_CLEARsym",
  "start_OPT_CLEARsym", "hole_OPT_DONT_CLEARsym",
  "start_OPT_DONT_CLEARsym", "hole_ALT_FieldInit_SEP_commasym",
  "start_ALT_FieldInit_SEP_commasym", "hole_OPT_CREATEsym",
  "start_OPT_CREATEsym", "hole_OPT_openparsym_TypeList_closeparsym",
  "start_OPT_openparsym_TypeList_closeparsym", "hole_OPTMORE_Oper",
  "start_OPTMORE_Oper", "hole_OPT_ExprList", "start_OPT_ExprList",
  "hole_MORE_MonExpr1", "start_MORE_MonExpr1",
  "hole_ALT_NameSpace_SEP_commasym_SP",
  "start_ALT_NameSpace_SEP_commasym_SP", "hole_ALT_Expr_SEP_commasym_SP",
  "start_ALT_Expr_SEP_commasym_SP", "hole_ALT_Identsym_SEP_commasym_SP",
  "start_ALT_Identsym_SEP_commasym_SP", "hole_ALT_Type_SEP_commasym_SP",
  "start_ALT_Type_SEP_commasym_SP", "hole_OPT_COMMENTsym",
  "start_OPT_COMMENTsym", "$accept", "front", "Import",
  "ImportedNonTerminals", "ImportedNonTerminal", "NonTerminals",
  "NonTerminal", "Super", "Rhs", "Scoping", "Choices", "ChoiceList",
  "Alternative", "Symbol", "Symbol1", "AltSymbol", "SymbolSeq", "And",
  "Or", "Symbol2", "SimpleSymbol", "IdSym", "Alternatives", "OptType",
  "DefiningSym", "ScopeExpr", "Defining_id", "Define", "Field",
  "FieldInits", "FieldInit", "Type", "Expr", "MonExpr1", "SimpleExpr",
  "StringOrKeyword", "Check", "NameSpaceList", "ExprList", "IdentList",
  "TypeList", "Alternator", "ScanInfo", "Defines", "NameSpace", "Oper",
  "NameOrField", "OPT_USEsym_IdentList", "OPT_NAMESPACEsym_NameSpaceList",
  "OPTMORE_Import", "OPT_NonTerminals",
  "ALT_ImportedNonTerminal_SEP_commasym", "OPT_colonsym_Identsym",
  "MORE_NonTerminal", "OPT_ROOTsym", "OPT_ScanInfo", "OPT_Super",
  "OPT_MEMOsym", "OPT_ENUMsym", "OPT_SKIPsym", "OPTMORE_Scoping",
  "OPT_Choices", "OPT_CHECKSsym_OPTMORE_Check", "OPTMORE_Check",
  "ALT_Alternative_SEP_Or", "MORE_Symbol",
  "OPT_ALT_ONCE_SymbolORField_SEP_And", "ALT_ONCE_SymbolORField_SEP_And",
  "ONCE_SymbolORField", "OPT_ScopeExpr", "OPT_WARNINGsym",
  "OPT_NAMEsym_Identsym", "OPT_exclaimsym", "ALT_Symbol1_SEP_Or_SP",
  "OPT_TYPEsym_Type", "OPT_FORWARDsym", "OPT_NAMESPACEsym_Identsym",
  "OPT_TRAVERSEsym", "OPT_CLEARsym", "OPT_DONT_CLEARsym",
  "ALT_FieldInit_SEP_commasym", "OPT_CREATEsym",
  "OPT_openparsym_TypeList_closeparsym", "ALT_MonExpr1_SEP_SP_Oper",
  "OPTMORE_Oper", "OPT_ExprList", "MORE_MonExpr1",
  "ALT_NameSpace_SEP_commasym_SP", "ALT_Expr_SEP_commasym_SP",
  "ALT_Identsym_SEP_commasym_SP", "ALT_Type_SEP_commasym_SP",
  "OPT_COMMENTsym", 0
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   249,   250,   251,   252,   253,   254,   255,   256,   256,
     257,   258,   258,   258,   259,   260,   261,   261,   262,   262,
     263,   263,   264,   265,   266,   266,   266,   266,   267,   267,
     267,   267,   268,   268,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   270,   271,   272,
     273,   274,   275,   275,   276,   276,   276,   277,   278,   279,
     279,   279,   279,   279,   280,   281,   282,   283,   283,   283,
     283,   283,   283,   283,   284,   284,   284,   285,   286,   287,
     288,   289,   290,   290,   291,   292,   292,   293,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   295,   295,   296,   296,   297,
     297,   298,   298,   299,   299,   300,   300,   301,   301,   302,
     302,   303,   303,   304,   304,   305,   305,   306,   306,   307,
     307,   308,   308,   309,   309,   310,   310,   311,   311,   312,
     312,   313,   313,   314,   314,   315,   315,   316,   316,   317,
     317,   318,   318,   319,   319,   320,   320,   321,   321,   322,
     322,   323,   323,   324,   324,   325,   325,   326,   326,   327,
     327,   328,   328,   329,   329,   330,   330,   331,   331,   332,
     332,   333,   333,   334,   334,   335,   335,   336,   336,   337,
     337,   338,   338,   339,   339,   340,   340,   250,   250,   251,
     250,   252,   250,   253,   250,   254,   250,   255,   250,   256,
     250,   257,   250,   258,   250,   261,   250,   262,   250,   263,
     250,   264,   250,   265,   250,   266,   250,   267,   250,   268,
     250,   269,   250,   270,   250,   272,   250,   273,   250,   274,
     250,   275,   250,   276,   250,   277,   250,   278,   250,   279,
     250,   280,   250,   281,   250,   282,   250,   283,   250,   284,
     250,   285,   250,   286,   250,   287,   250,   288,   250,   289,
     250,   290,   250,   291,   250,   292,   250,   293,   250,   294,
     250,   295,   250,   296,   250,   297,   250,   298,   250,   299,
     250,   300,   250,   301,   250,   302,   250,   303,   250,   304,
     250,   305,   250,   306,   250,   307,   250,   308,   250,   309,
     250,   311,   250,   312,   250,   314,   250,   318,   250,   319,
     250,   320,   250,   321,   250,   323,   250,   324,   250,   325,
     250,   326,   250,   327,   250,   328,   250,   329,   250,   330,
     250,   331,   250,   333,   250,   334,   250,   335,   250,   336,
     250,   337,   250,   338,   250,   339,   250,   340,   250
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     4,     4,     1,     2,     1,    10,     2,     2,
       4,     1,     1,     1,     4,     1,     5,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     3,     1,     1,     1,     6,     3,     2,     2,
       4,     4,     3,     4,     1,     2,     2,     2,     1,     1,
       5,     2,     1,     3,     1,     1,     1,     8,     1,     2,
       2,     2,     2,     2,     2,     1,     2,     1,     3,     1,
       1,     1,     1,     4,     1,     1,     1,     5,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     0,
       2,     0,     2,     0,     1,     1,     3,     0,     2,     1,
       2,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     2,     0,     1,     0,     2,     0,
       2,     1,     3,     1,     2,     0,     1,     1,     3,     1,
       1,     0,     1,     0,     1,     0,     2,     0,     1,     1,
       3,     0,     2,     0,     1,     0,     2,     0,     1,     0,
       1,     0,     1,     1,     3,     0,     1,     0,     3,     1,
       3,     0,     2,     0,     1,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     0,     1,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     107,     0,   197,   107,     0,     0,     0,   121,   121,     0,
     133,     0,   145,   163,   145,   163,   163,    27,     0,   163,
     163,     0,   161,   163,     0,     0,     0,     0,   175,   175,
       0,   181,   181,     0,     0,     0,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,   283,   107,   109,   111,
     121,     0,   117,   121,   121,   123,   125,   127,   129,   131,
     133,   137,   139,   163,   151,   153,   155,   157,   161,   163,
     165,   167,   169,   171,   175,   175,   177,   181,   181,   181,
       0,   181,     0,     0,   195,     0,   109,   191,   267,   353,
     108,    80,   198,     0,   199,   200,   117,   201,   203,   291,
     202,   115,     4,   204,   122,   205,   207,   295,   297,   206,
     121,     6,   123,   208,     0,     0,   209,   210,    11,    12,
      13,   211,   213,   309,   212,   133,   145,   214,   164,     0,
     145,   145,   145,    44,     0,   181,   161,   161,   161,   155,
     215,   217,   219,   221,   223,   229,   231,   233,   237,   245,
     327,   216,   149,    17,    20,    21,    19,    33,    35,    34,
     150,    23,   146,    27,     0,   161,   218,   161,   220,   222,
       0,   224,    24,    25,    26,   225,   226,    28,    29,    30,
      31,   227,   228,   161,   230,   232,   234,     0,   235,   325,
     236,    49,   238,   181,   239,   240,   181,   241,    52,   242,
      54,    55,    56,   243,   244,     0,   246,   181,   181,   181,
     176,   181,   247,   249,   337,   339,   248,   173,    58,   181,
     250,   177,   251,   252,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   253,   255,   279,   343,   254,   179,   181,    65,     0,
     256,    72,    70,    67,    69,    75,    76,    74,   257,   259,
     258,    71,   260,   181,   261,   262,    87,   263,   277,   349,
     264,   187,    78,   265,   351,   189,   266,    79,   268,   269,
     355,   193,   270,    81,    82,    83,   271,   272,   161,   273,
     274,    85,    86,   275,   276,   278,   280,   105,   106,   281,
     282,   284,     0,   285,   286,   287,   111,   288,   289,   114,
     290,   292,     0,   293,   294,   296,   298,   299,   124,   300,
     301,   126,   302,   128,   303,   304,   130,   305,   306,   132,
     307,   308,   310,   139,   311,   312,   313,   139,   314,   315,
     143,   316,   317,   152,   318,   154,   319,   320,     0,   321,
     322,   158,   323,   324,   326,   328,     0,   329,   330,   168,
     331,   332,   170,   333,   334,   172,   335,   336,   338,   340,
       0,   341,   342,   344,   345,   184,   346,   347,   185,   348,
     350,   352,   354,   356,   196,   357,   358,     1,   111,     0,
       0,     5,     0,   120,     0,     9,     8,   134,   135,     0,
     159,     0,    48,     0,     0,    45,    46,   163,    47,   131,
      39,    38,   161,   163,     0,   163,     0,   163,   162,    51,
       0,     0,    60,    61,    62,    63,   175,    59,    64,   181,
     182,    66,   181,     0,     0,     0,   181,     0,   195,   110,
     112,   118,   138,   140,   144,   156,   166,     0,   186,   121,
     192,     0,   116,   125,   145,   136,   137,     0,   145,     0,
     157,    42,   161,    18,     0,     0,    37,    22,    32,   148,
     165,    53,   174,   180,     0,    68,   153,   188,   190,   194,
      84,   178,     2,     3,   127,     0,   141,    15,    10,   151,
     160,    40,    41,    43,   175,   133,   151,    73,   181,   129,
     145,   145,   153,   167,    16,    50,    77,   131,    14,   142,
      36,   169,     0,   171,   133,    57,     0,     7
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    85,   306,   100,   101,   309,   110,   321,   124,   125,
     455,   485,   486,   152,   400,   154,   155,   176,   182,   156,
     157,   158,   401,   408,   159,   343,   199,   204,   160,   216,
     217,   281,   275,   246,   260,   261,   337,   270,   375,    90,
     282,   413,   318,   294,   271,   247,   300,    86,   304,   307,
     310,   102,   314,   111,   112,   319,   322,   325,   328,   331,
     126,   456,   335,   338,   487,   341,   161,   162,   163,   344,
     347,   350,   353,   402,   191,   164,   358,   361,   364,   367,
     218,   219,   428,   248,   249,   376,   379,   272,   277,    91,
     283,   386
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -412
static const short yypact[] =
{
      77,   244,  -412,    77,   307,   530,   300,   269,   342,    30,
     347,   553,   694,  1026,   799,   816,   328,   591,   561,  1111,
    1127,   -39,     7,    -7,   215,   528,   522,   298,    61,   488,
     236,   529,   562,   651,   430,   -40,   455,   387,   244,   299,
     284,   302,   352,   -50,  1228,   286,  -412,   129,   154,    99,
     349,   350,   127,   277,   109,    23,   107,   115,   142,    57,
     117,   -35,   257,   901,     1,   111,    35,    21,    17,    55,
      19,   110,   -43,    39,   486,    41,    11,   604,    27,   462,
     271,   113,   -51,   263,     5,    40,   154,   104,  -412,  -412,
    -412,  -412,  -412,    45,  -412,  -412,   127,  -412,  -412,  -412,
    -412,   116,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
     119,  -412,    23,  -412,    86,   102,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,   117,   799,  -412,  -412,   254,
     799,   799,   799,  -412,   430,   529,    33,     7,     7,    35,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,   284,  -412,   278,  -412,  -412,
    -412,  -412,  -412,   611,   522,    65,  -412,    69,  -412,  -412,
     284,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,     7,  -412,  -412,  -412,   236,  -412,  -412,
    -412,  -412,  -412,   529,  -412,  -412,   529,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,   340,  -412,   529,   529,   529,
    -412,   529,  -412,  -412,  -412,  -412,  -412,   356,  -412,   529,
    -412,    11,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  1228,   604,  -412,   651,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
     331,  -412,  -412,   529,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,   368,  -412,  -412,  -412,   373,  -412,  -412,  -412,  -412,
    -412,   380,  -412,  -412,  -412,  -412,  -412,  -412,     7,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,   455,  -412,  -412,  -412,    99,  -412,  -412,  -412,
    -412,  -412,   309,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,   257,  -412,  -412,  -412,   257,  -412,  -412,
     920,  -412,  -412,  -412,  -412,  -412,  -412,  -412,   313,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,   317,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
     299,  -412,  -412,  -412,  -412,  -412,  -412,  -412,   440,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,    99,   -51,
     397,  -412,   350,  -412,   325,  -412,  -412,  -412,   394,   286,
     561,   398,  -412,   377,   400,  -412,  -412,  1038,  -412,    57,
    -412,  -412,     7,   901,   379,   974,   528,  1111,  -412,  -412,
     453,   236,  -412,  -412,  -412,  -412,   486,  -412,  -412,   562,
    -412,   331,    59,   403,   436,   271,   113,   263,     5,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,   505,  -412,   349,
    -412,   530,  -412,   107,   694,  -412,   -35,   437,   799,   507,
      21,   489,     9,  -412,   518,   520,  -412,  -412,  -412,  -412,
      19,  -412,  -412,  -412,   541,  -412,   111,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,   115,   467,   561,  -412,  -412,     1,
    -412,  -412,  -412,  -412,    61,   347,     1,  -412,   462,   142,
     799,   694,   111,   110,  -412,  -412,  -412,    57,  -412,  -412,
    -412,   -43,   352,    39,   347,  -412,   466,  -412
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -412,   552,   573,   130,   572,   575,   576,   571,  -108,   577,
    -412,  -412,   574,   -10,   -12,   568,   421,   454,  -374,   -15,
     598,   -16,   321,   -14,   596,   605,   214,   485,   623,   158,
     624,   -24,   131,   -31,   405,     2,   622,   365,   621,   631,
     301,   635,   638,   174,   644,   -28,   290,   643,   606,  -272,
     242,   -37,   597,    -6,   642,   588,   248,  -124,   203,  -370,
      53,  -412,   247,  -291,   204,  -303,  -412,   289,  -412,  -411,
    -143,   569,   249,   252,   646,   647,   253,   209,   211,   212,
     -63,   649,   653,   310,    -3,   295,  -324,   -73,   -71,   -67,
     -70,   292
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -184
static const short yytable[] =
{
     153,   250,   168,   166,   184,   186,   223,   380,   190,   198,
     381,   368,   409,   383,   311,   382,   296,   128,   187,   384,
     187,   370,   193,   370,   362,   356,   458,  -183,   187,  -177,
     333,    87,   266,   288,   440,   263,   262,   444,   114,   465,
     387,   407,   442,   183,   187,   115,   443,   315,   378,   323,
     351,  -127,  -127,   340,   448,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,  -183,   417,   373,   329,   187,   407,   502,   128,
     187,     1,   207,   348,   147,   505,   208,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   393,   210,    93,   365,   209,   389,
     467,   264,   501,   332,   398,   114,   449,   268,   104,  -119,
     148,   392,   115,   410,   411,   210,   211,   390,   104,   116,
     194,   323,   188,     1,   188,   312,   405,   512,   118,   119,
     120,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   188,   326,
     302,   345,   245,   418,     2,     3,   334,     4,   395,     5,
     241,     6,   242,     7,   506,     8,   359,     9,   397,    10,
     363,    11,   273,    12,   396,    13,   289,    14,    94,    15,
     188,    16,    89,    17,   188,    18,   243,    19,   212,    20,
     213,    21,   241,    22,   242,    23,   116,    24,   342,    25,
     150,    26,   317,    27,   273,    28,   106,    29,   429,    30,
     122,    31,   189,    32,   189,    33,   324,    34,   243,    35,
    -127,    36,   189,    37,   352,    38,   193,    39,   357,    40,
     371,    41,   371,    42,   430,    43,   349,    44,   189,    45,
      46,    47,   385,    48,   330,    49,   241,    50,   242,    51,
     244,    52,   374,    53,   366,    54,   406,    55,   274,    56,
     215,    57,   150,    58,   438,    59,   305,    60,   104,    61,
     189,    62,   243,    63,   189,    64,   104,    65,   214,    66,
     215,    67,   244,    68,   374,    69,   108,    70,   320,    71,
     274,    72,    46,    73,   107,    74,   108,    75,   324,    76,
     313,    77,   288,    78,    93,    79,   123,    80,   221,    81,
     346,    82,   450,    83,   419,    84,    87,   420,  -145,   303,
     340,   360,   263,   498,   297,   298,   399,   327,   422,   423,
     424,   414,   425,   432,   194,   221,   244,   378,   421,  -113,
     427,   104,   128,   266,   274,   452,   284,   285,   104,   510,
     499,   426,   477,   472,   105,   478,   106,   479,   118,   119,
     120,   291,   292,   435,   106,   129,   433,   222,   436,   130,
     205,   221,    96,   464,   131,   437,   132,   504,   133,   134,
     135,   441,   463,    98,   434,   445,    94,   464,   466,   446,
     198,    88,   463,   340,   222,   451,   516,   453,   264,   454,
     167,   459,   137,   138,   139,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    96,   149,   460,   141,   170,   171,   268,   106,
     222,   144,   153,    98,   105,   286,   106,   145,   121,   146,
     122,   147,   403,   404,   107,   148,   108,   299,   279,   461,
     336,   468,   107,   149,   108,   289,   471,   378,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   475,  -181,    89,   508,   153,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   207,   280,   207,
     269,   208,   476,   208,   255,   256,   257,   293,   481,   489,
     491,  -181,  -181,  -181,  -181,  -181,  -181,   493,   308,   108,
     241,    99,   242,   209,   107,   209,   108,   266,   494,   495,
     196,   500,   273,   517,   280,   150,   123,   200,   201,   202,
     210,   211,   210,   211,   497,    92,   243,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   118,   119,   120,    95,   103,   259,
     117,   483,   109,   169,   113,   242,   151,  -181,   127,  -181,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   242,   267,   243,
     183,  -147,    96,   177,   178,   179,   180,   415,   185,   192,
     244,    97,   268,    98,  -147,   213,  -147,   213,   274,   195,
     470,   243,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   416,
     206,   147,   503,   220,   431,   203,   122,   265,   276,   197,
     172,   173,   174,  -147,  -147,  -147,  -147,   439,  -147,   278,
    -147,   447,   241,   244,   242,   287,  -147,   377,   181,   290,
     172,   173,   174,  -147,  -147,  -147,   514,   295,  -147,   457,
     301,   482,   388,   391,   269,   244,   316,   251,   243,   377,
     394,   484,   507,   488,   469,   509,   175,   242,   412,   492,
     490,    99,   511,   214,   354,   215,   355,   215,   128,  -163,
    -163,  -163,   513,   496,   369,   515,   175,   474,  -147,   372,
     480,   243,   252,   253,   254,   255,   256,   257,     0,   473,
       0,   129,     0,     0,     0,   130,     0,     0,     0,     0,
     131,     0,   132,     0,   133,   134,   135,     0,     0,     0,
       0,     0,   244,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -147,   243,     0,     0,   136,     0,   137,   138,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,     0,   258,   140,
     259,   141,     0,   142,     0,   143,     0,   144,     0,     0,
       0,     0,  -147,   145,     0,   146,     0,   147,     0,     0,
       0,   148,     0,   128,  -163,  -163,  -163,  -163,     0,   149,
       0,     0,     0,     0,     0,     0,     0,   244,     0,     0,
     128,     0,     0,     0,     0,     0,   129,     0,     0,     0,
     130,     0,     0,     0,     0,   131,     0,   132,     0,   133,
     134,   135,     0,   129,     0,     0,     0,   130,     0,     0,
       0,     0,   131,     0,   132,     0,   133,   134,   135,     0,
       0,   167,     0,   137,   138,   139,     0,     0,  -145,  -145,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
     137,   138,   139,     0,     0,     0,   141,     0,   142,     0,
     143,   150,   144,     0,     0,     0,     0,     0,   145,     0,
     146,     0,   147,   141,     0,   128,   148,   143,     0,   144,
       0,     0,  -163,     0,   149,   145,     0,   146,     0,   147,
       0,     0,     0,   148,   128,  -163,  -163,  -163,   129,     0,
       0,   149,   130,     0,     0,     0,     0,   131,     0,   132,
       0,   133,   134,   135,     0,     0,     0,   129,     0,     0,
       0,   130,     0,     0,     0,     0,   131,  -145,   132,     0,
     133,   134,   135,   165,     0,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,     0,
       0,     0,   165,     0,   137,   138,   139,     0,   141,     0,
       0,     0,     0,     0,     0,     0,   150,     0,     0,     0,
     145,   129,   146,     0,   147,   130,     0,   141,   148,     0,
     131,     0,   132,   150,   133,   134,   135,     0,     0,   145,
       0,   146,     0,   147,     0,     0,     0,   148,     0,     0,
     128,     0,     0,  -163,     0,     0,   167,     0,   137,   138,
     139,     0,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,     0,   130,     0,     0,
       0,   141,   131,     0,   132,   129,   133,   134,   135,   130,
       0,     0,     0,   145,   131,   146,   132,   147,   133,   134,
     135,   148,     0,     0,     0,     0,   339,     0,   165,   149,
     137,   138,   139,     0,     0,     0,     0,     0,   150,     0,
     462,     0,   137,   138,   139,   339,     0,     0,     0,     0,
       0,     0,     0,   141,     0,   128,     0,   150,     0,     0,
       0,     0,     0,     0,     0,   145,     0,   146,     0,   147,
       0,   128,     0,   148,     0,     0,     0,   145,   129,   146,
       0,   147,   130,     0,     0,   148,     0,   131,     0,   132,
       0,   133,   134,   135,   129,     0,     0,     0,   130,   222,
       0,     0,     0,   131,     0,   132,     0,   133,   134,   135,
       0,   150,     0,   183,     0,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
       0,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     0,   146,     0,   147,     0,     0,     0,   148,     0,
       0,     0,     0,   150,     0,     0,     0,     0,   146,     0,
     147,     0,     0,     0,   148,   150,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243
};

static const short yycheck[] =
{
      12,    32,    14,    13,    19,    21,    30,    80,    22,    25,
      81,    74,   136,    83,    51,    82,    44,    24,    11,    14,
      11,    12,    21,    12,    67,     6,   400,     0,    11,    20,
      65,    82,    82,    10,   306,    75,    34,   340,     8,   409,
       0,     8,   333,    82,    11,    15,   337,    53,    79,    16,
      29,    18,    19,    63,   378,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    13,     8,    77,    18,    11,     8,   489,    24,
      11,     4,    21,    48,   123,   496,    25,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,   110,    64,     7,    68,    47,     5,
     413,   151,   486,    60,   126,     8,   388,   167,     9,     0,
     127,     5,    15,   137,   138,    64,    65,    82,     9,    99,
     129,    16,   125,     4,   125,     8,   134,   507,    21,    22,
      23,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,   125,    17,
       6,    50,    31,   187,    87,    88,   201,    90,    82,    92,
     143,    94,   145,    96,   498,    98,    66,   100,   125,   102,
     223,   104,   155,   106,    82,   108,   163,   110,    89,   112,
     125,   114,   243,   116,   125,   118,   169,   120,   137,   122,
     139,   124,   143,   126,   145,   128,    99,   130,   207,   132,
     217,   134,   189,   136,   155,   138,    97,   140,   246,   142,
     103,   144,   215,   146,   215,   148,   193,   150,   169,   152,
     197,   154,   215,   156,   213,   158,    21,   160,   219,   162,
     231,   164,   231,   166,   247,   168,   211,   170,   215,   172,
     173,   174,   247,   176,   197,   178,   143,   180,   145,   182,
     233,   184,   235,   186,   225,   188,   135,   190,   241,   192,
     229,   194,   217,   196,   288,   198,   177,   200,     9,   202,
     215,   204,   169,   206,   215,   208,     9,   210,   227,   212,
     229,   214,   233,   216,   235,   218,   187,   220,   191,   222,
     241,   224,   173,   226,   185,   228,   187,   230,   193,   232,
     183,   234,    10,   236,     7,   238,   199,   240,    82,   242,
     209,   244,   389,   246,   193,   248,    82,   196,     0,   175,
     340,   221,    75,   476,    48,    49,    82,   195,   207,   208,
     209,    63,   211,    12,   129,    82,   233,   378,     8,     0,
     219,     9,    24,    82,   241,   392,    72,    73,     9,   502,
     484,     5,   435,   426,    95,   436,    97,   437,    21,    22,
      23,    19,    20,     5,    97,    47,    45,   141,     5,    51,
      82,    82,    82,   407,    56,     5,    58,   495,    60,    61,
      62,    82,   407,    93,   263,    82,    89,   421,   412,    82,
     416,   157,   417,   413,   141,     8,   514,    82,   151,    15,
      82,    13,    84,    85,    86,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    82,   135,    57,   107,    15,    16,   167,    97,
     141,   113,   454,    93,    95,   161,    97,   119,   101,   121,
     103,   123,   131,   132,   185,   127,   187,   171,   159,    59,
     203,    82,   185,   135,   187,   163,    13,   498,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    82,    46,   243,   500,   501,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    21,   245,    21,
     239,    25,    76,    25,    84,    85,    86,   165,    13,    82,
      13,    81,    82,    83,    84,    85,    86,    38,   179,   187,
     143,   181,   145,    47,   185,    47,   187,    82,    20,    19,
      12,    74,   155,    77,   245,   217,   199,    25,    26,    27,
      64,    65,    64,    65,    13,     3,   169,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    21,    22,    23,     4,     6,   149,
       9,   451,     7,    15,     8,   145,    12,   147,    11,   149,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   145,   153,   169,
      82,     0,    82,    52,    53,    54,    55,   163,    20,    23,
     233,    91,   167,    93,    13,   139,    15,   139,   241,    24,
     416,   169,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,   164,
      27,   123,   494,    29,   249,   133,   103,    35,    37,   131,
      69,    70,    71,    52,    53,    54,    55,   302,    57,    38,
      59,   370,   143,   233,   145,    40,    65,   237,   117,    41,
      69,    70,    71,    72,    73,    74,   512,    43,    77,   399,
      47,   449,    86,    96,   239,   233,    54,    46,   169,   237,
     112,   453,   499,   456,   415,   501,   115,   145,   139,   460,
     458,   181,   503,   227,    68,   229,    69,   229,    24,    25,
      26,    27,   511,   470,    75,   513,   115,   432,   117,    76,
     438,   169,    81,    82,    83,    84,    85,    86,    -1,   429,
      -1,    47,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      56,    -1,    58,    -1,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   169,    -1,    -1,    82,    -1,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,   147,   105,
     149,   107,    -1,   109,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,   201,   119,    -1,   121,    -1,   123,    -1,    -1,
      -1,   127,    -1,    24,    25,    26,    27,   133,    -1,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    -1,    60,
      61,    62,    -1,    47,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    -1,    60,    61,    62,    -1,
      -1,    82,    -1,    84,    85,    86,    -1,    -1,    72,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      84,    85,    86,    -1,    -1,    -1,   107,    -1,   109,    -1,
     111,   217,   113,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,   123,   107,    -1,    24,   127,   111,    -1,   113,
      -1,    -1,   133,    -1,   135,   119,    -1,   121,    -1,   123,
      -1,    -1,    -1,   127,    24,    25,    26,    27,    47,    -1,
      -1,   135,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,
      -1,    60,    61,    62,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    56,   161,    58,    -1,
      60,    61,    62,    82,    -1,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    82,    -1,    84,    85,    86,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
     119,    47,   121,    -1,   123,    51,    -1,   107,   127,    -1,
      56,    -1,    58,   217,    60,    61,    62,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,   127,    -1,    -1,
      24,    -1,    -1,   133,    -1,    -1,    82,    -1,    84,    85,
      86,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    -1,    -1,
      -1,   107,    56,    -1,    58,    47,    60,    61,    62,    51,
      -1,    -1,    -1,   119,    56,   121,    58,   123,    60,    61,
      62,   127,    -1,    -1,    -1,    -1,   205,    -1,    82,   135,
      84,    85,    86,    -1,    -1,    -1,    -1,    -1,   217,    -1,
      82,    -1,    84,    85,    86,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,    24,    -1,   217,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,
      -1,    24,    -1,   127,    -1,    -1,    -1,   119,    47,   121,
      -1,   123,    51,    -1,    -1,   127,    -1,    56,    -1,    58,
      -1,    60,    61,    62,    47,    -1,    -1,    -1,    51,   141,
      -1,    -1,    -1,    56,    -1,    58,    -1,    60,    61,    62,
      -1,   217,    -1,    82,    -1,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,   121,    -1,
     123,    -1,    -1,    -1,   127,   217,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     4,    87,    88,    90,    92,    94,    96,    98,   100,
     102,   104,   106,   108,   110,   112,   114,   116,   118,   120,
     122,   124,   126,   128,   130,   132,   134,   136,   138,   140,
     142,   144,   146,   148,   150,   152,   154,   156,   158,   160,
     162,   164,   166,   168,   170,   172,   173,   174,   176,   178,
     180,   182,   184,   186,   188,   190,   192,   194,   196,   198,
     200,   202,   204,   206,   208,   210,   212,   214,   216,   218,
     220,   222,   224,   226,   228,   230,   232,   234,   236,   238,
     240,   242,   244,   246,   248,   250,   296,    82,   157,   243,
     288,   338,   250,     7,    89,   251,    82,    91,    93,   181,
     252,   253,   300,   253,     9,    95,    97,   185,   187,   254,
     255,   302,   303,   255,     8,    15,    99,   256,    21,    22,
      23,   101,   103,   199,   257,   258,   309,   258,    24,    47,
      51,    56,    58,    60,    61,    62,    82,    84,    85,    86,
     105,   107,   109,   111,   113,   119,   121,   123,   127,   135,
     217,   261,   262,   263,   264,   265,   268,   269,   270,   273,
     277,   315,   316,   317,   324,    82,   262,    82,   263,   264,
     265,   265,    69,    70,    71,   115,   266,    52,    53,    54,
      55,   117,   267,    82,   268,   269,   270,    11,   125,   215,
     272,   323,   273,    21,   129,   274,    12,   131,   270,   275,
      25,    26,    27,   133,   276,    82,   277,    21,    25,    47,
      64,    65,   137,   139,   227,   229,   278,   279,   329,   330,
     279,    82,   141,   280,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,   143,   145,   169,   233,   281,   282,   294,   332,   333,
     282,    46,    81,    82,    83,    84,    85,    86,   147,   149,
     283,   284,   284,    75,   151,   285,    82,   153,   167,   239,
     286,   293,   336,   155,   241,   281,   287,   337,   288,   159,
     245,   280,   289,   339,    72,    73,   161,   290,    10,   163,
     291,    19,    20,   165,   292,   293,   294,    48,    49,   171,
     295,   296,     6,   175,   297,   177,   251,   298,   179,   254,
     299,   300,     8,   183,   301,   302,   303,   189,   291,   304,
     191,   256,   305,    16,   193,   306,    17,   195,   307,    18,
     197,   308,   309,    65,   201,   311,   203,   285,   312,   205,
     262,   314,   207,   274,   318,    50,   209,   319,    48,   211,
     320,    29,   213,   321,   323,   324,     6,   219,   325,    66,
     221,   326,    67,   223,   327,    68,   225,   328,   329,   330,
      12,   231,   331,   333,   235,   287,   334,   237,   282,   335,
     336,   337,   338,   339,    14,   247,   340,     0,   297,     5,
      82,   301,     5,   302,   304,    82,    82,   309,   263,    82,
     263,   271,   322,   271,   271,   284,   281,     8,   272,   306,
     272,   272,   320,   290,    63,   266,   276,     8,   280,   281,
     281,     8,   281,   281,   281,   281,     5,   281,   331,   294,
     333,   283,    12,    45,   281,     5,     5,     5,   272,   286,
     298,    82,   312,   312,   314,    82,    82,   289,   335,   298,
     338,     8,   300,    82,    15,   259,   310,   295,   267,    13,
      57,    59,    82,   268,   280,   308,   272,   314,    82,   316,
     275,    13,   329,   332,   334,    82,    76,   336,   337,   339,
     340,    13,   299,   252,   305,   260,   261,   313,   311,    82,
     322,    13,   321,    38,    20,    19,   325,    13,   319,   306,
      74,   267,   318,   278,   257,   318,   335,   307,   263,   313,
     319,   326,   308,   327,   292,   328,   257,    77
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

    { yyval.front_type = Create_front_front(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-3].OPT_USEsym_IdentList_type, yyvsp[-2].OPT_NAMESPACEsym_NameSpaceList_type, yyvsp[-1].OPTMORE_Import_type, yyvsp[0].OPT_NonTerminals_type);
    Decorate_front(yyval.front_type);
  ;}
    break;

  case 3:

    { yyval.Import_type = Create_front_Import(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-2].Identsym_type, yyvsp[0].ImportedNonTerminals_type);
  ;}
    break;

  case 4:

    {
    yyval.ImportedNonTerminals_type = yyvsp[0].ALT_ImportedNonTerminal_SEP_commasym_type;
  ;}
    break;

  case 5:

    { yyval.ImportedNonTerminal_type = Create_front_ImportedNonTerminal(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].Identsym_type, yyvsp[0].OPT_colonsym_Identsym_type);
  ;}
    break;

  case 6:

    {
    yyval.NonTerminals_type = yyvsp[0].MORE_NonTerminal_type;
  ;}
    break;

  case 7:

    { yyval.NonTerminal_type = Create_front_NonTerminal(make_post_src_info(yylsp[-9].first_line, yylsp[0].last_line), yyvsp[-9].OPT_ROOTsym_type, yyvsp[-8].OPT_ScanInfo_type, yyvsp[-7].Identsym_type, yyvsp[-6].OPT_Super_type, yyvsp[-5].OPT_MEMOsym_type, yyvsp[-4].OPT_ENUMsym_type, yyvsp[-3].OPT_SKIPsym_type, yyvsp[-2].Defines_type, yyvsp[-1].Rhs_type);
  ;}
    break;

  case 8:

    { yyval.Super_type = Create_front_SubType(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].lessthansym_type, yyvsp[0].Identsym_type);
  ;}
    break;

  case 9:

    { yyval.Super_type = Create_front_NoType(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[0].Identsym_type);
  ;}
    break;

  case 10:

    { yyval.Rhs_type = Create_front_Rhs(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-3].OPTMORE_Scoping_type, yyvsp[-2].Symbol1_type, yyvsp[-1].OPT_Choices_type.f1, yyvsp[-1].OPT_Choices_type.f2, yyvsp[-1].OPT_Choices_type.f3, yyvsp[-1].OPT_Choices_type.f4, yyvsp[-1].OPT_Choices_type.f5, yyvsp[0].OPT_CHECKSsym_OPTMORE_Check_type);
  ;}
    break;

  case 11:

    { yyval.Scoping_type = front_NewScope; ;}
    break;

  case 12:

    { yyval.Scoping_type = front_OpenScope; ;}
    break;

  case 13:

    { yyval.Scoping_type = front_CloseScope; ;}
    break;

  case 14:

    {
    yyval.Choices_type.f1 = yyvsp[-3].lessthansym_type;
    yyval.Choices_type.f2 = yyvsp[-2].ChoiceList_type.f1;
    yyval.Choices_type.f3 = yyvsp[-2].ChoiceList_type.f2;
    yyval.Choices_type.f4 = yyvsp[-1].greaterthansym_type;
    yyval.Choices_type.f5 = yyvsp[0].Symbol1_type;
  ;}
    break;

  case 15:

    {
    yyval.ChoiceList_type.f1 = yyvsp[0].ALT_Alternative_SEP_Or_type.f1;
    yyval.ChoiceList_type.f2 = yyvsp[0].ALT_Alternative_SEP_Or_type.f2;
  ;}
    break;

  case 16:

    { yyval.Alternative_type = Create_front_LabeledAlt(make_post_src_info(yylsp[-4].first_line, yylsp[0].last_line), yyvsp[-4].Identsym_type, yyvsp[-3].OPT_MEMOsym_type, yyvsp[-2].OPT_SKIPsym_type, yyvsp[-1].definessym_type, yyvsp[0].Rhs_type);
  ;}
    break;

  case 17:

    { yyval.Alternative_type = Create_front_UnLabeledAlt(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].Symbol1_type);
  ;}
    break;

  case 18:

    { yyval.Symbol_type = Create_front_LabeledSym(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-2].Identsym_type, yyvsp[0].Symbol2_type);
  ;}
    break;

  case 19:

    {
    yyval.Symbol_type = yyvsp[0].Symbol2_type;
  ;}
    break;

  case 20:

    {
    yyval.Symbol1_type = yyvsp[0].AltSymbol_type;
  ;}
    break;

  case 21:

    {
    yyval.Symbol1_type = yyvsp[0].SymbolSeq_type;
  ;}
    break;

  case 22:

    { yyval.AltSymbol_type = Create_front_AltSymbol(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-2].SymbolSeq_type, yyvsp[-1].Alternator_type, yyvsp[0].MORE_Symbol_type);
  ;}
    break;

  case 23:

    { yyval.SymbolSeq_type = Create_front_SymbolSeq(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].OPT_ALT_ONCE_SymbolORField_SEP_And_type.f1, yyvsp[0].OPT_ALT_ONCE_SymbolORField_SEP_And_type.f2, yyvsp[0].OPT_ALT_ONCE_SymbolORField_SEP_And_type.f3);
  ;}
    break;

  case 24:

    { yyval.And_type = front_AndTranspose; ;}
    break;

  case 25:

    { yyval.And_type = front_AndLeft; ;}
    break;

  case 26:

    { yyval.And_type = front_AndRight; ;}
    break;

  case 27:

    { yyval.And_type = front_AndCenter; ;}
    break;

  case 28:

    { yyval.Or_type = front_OrCenter; ;}
    break;

  case 29:

    { yyval.Or_type = front_OrLeft; ;}
    break;

  case 30:

    { yyval.Or_type = front_OrRight; ;}
    break;

  case 31:

    { yyval.Or_type = front_OrTranspose; ;}
    break;

  case 32:

    { yyval.Symbol2_type = Create_front_CompareSym(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-2].SimpleSymbol_type, yyvsp[0].Identsym_type);
  ;}
    break;

  case 33:

    {
    yyval.Symbol2_type = yyvsp[0].SimpleSymbol_type;
  ;}
    break;

  case 34:

    {
    yyval.SimpleSymbol_type = yyvsp[0].DefiningSym_type;
  ;}
    break;

  case 35:

    {
    yyval.SimpleSymbol_type = yyvsp[0].IdSym_type;
  ;}
    break;

  case 36:

    { yyval.SimpleSymbol_type = Create_front_AppliedSym(make_post_src_info(yylsp[-5].first_line, yylsp[0].last_line), yyvsp[-4].Identsym_type, yyvsp[-3].NameOrField_type, yyvsp[-2].Identsym_type, yyvsp[-1].OPT_ScopeExpr_type, yyvsp[0].OPT_WARNINGsym_type);
  ;}
    break;

  case 37:

    { yyval.SimpleSymbol_type = Create_front_StringSymbol(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-2].Stringsym_type, yyvsp[-1].OPT_NAMEsym_Identsym_type, yyvsp[0].OptType_type);
  ;}
    break;

  case 38:

    { yyval.SimpleSymbol_type = Create_front_CharSymbol(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].Charsym_type, yyvsp[0].OptType_type);
  ;}
    break;

  case 39:

    { yyval.SimpleSymbol_type = Create_front_KeywordSymbol(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].Keywordsym_type, yyvsp[0].OptType_type);
  ;}
    break;

  case 40:

    { yyval.SimpleSymbol_type = Create_front_OnceSymbol(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-2].Alternatives_type.f1, yyvsp[-2].Alternatives_type.f2);
  ;}
    break;

  case 41:

    { yyval.SimpleSymbol_type = Create_front_OptSymbol(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-2].Alternatives_type.f1, yyvsp[-2].Alternatives_type.f2, yyvsp[0].OPT_exclaimsym_type);
  ;}
    break;

  case 42:

    { yyval.SimpleSymbol_type = Create_front_OptMoreSymbol(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-1].Alternatives_type.f1, yyvsp[-1].Alternatives_type.f2);
  ;}
    break;

  case 43:

    { yyval.SimpleSymbol_type = Create_front_MoreSymbol(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-2].Alternatives_type.f1, yyvsp[-2].Alternatives_type.f2, yyvsp[0].plussym_type);
  ;}
    break;

  case 44:

    { yyval.SimpleSymbol_type = Create_front_EmptySym(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line));
  ;}
    break;

  case 45:

    { yyval.SimpleSymbol_type = Create_front_LayoutString(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[0].StringOrKeyword_type);
  ;}
    break;

  case 46:

    { yyval.SimpleSymbol_type = Create_front_LayoutAction(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[0].Expr_type);
  ;}
    break;

  case 47:

    { yyval.IdSym_type = Create_front_IdSym(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].Identsym_type, yyvsp[0].OptType_type);
  ;}
    break;

  case 48:

    {
    yyval.Alternatives_type.f1 = yyvsp[0].ALT_Symbol1_SEP_Or_SP_type.f1;
    yyval.Alternatives_type.f2 = yyvsp[0].ALT_Symbol1_SEP_Or_SP_type.f2;
  ;}
    break;

  case 49:

    {
    yyval.OptType_type = yyvsp[0].OPT_TYPEsym_Type_type;
  ;}
    break;

  case 50:

    { yyval.DefiningSym_type = Create_front_DefiningSym(make_post_src_info(yylsp[-4].first_line, yylsp[0].last_line), yyvsp[-4].OPT_FORWARDsym_type, yyvsp[-3].Define_type, yyvsp[-2].Defining_id_type, yyvsp[-1].OPT_NAMESPACEsym_Identsym_type, yyvsp[0].OPT_ScopeExpr_type);
  ;}
    break;

  case 51:

    {
    yyval.ScopeExpr_type = yyvsp[0].Expr_type;
  ;}
    break;

  case 52:

    { yyval.Defining_id_type = Create_front_DefId(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].IdSym_type);
  ;}
    break;

  case 53:

    { yyval.Defining_id_type = Create_front_DefExpr(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-1].Expr_type);
  ;}
    break;

  case 54:

    { yyval.Define_type = front_Defining; ;}
    break;

  case 55:

    { yyval.Define_type = front_Redefining; ;}
    break;

  case 56:

    { yyval.Define_type = front_Overloading; ;}
    break;

  case 57:

    { yyval.Field_type = Create_front_Field(make_post_src_info(yylsp[-7].first_line, yylsp[0].last_line), yyvsp[-7].Identsym_type, yyvsp[-5].Type_type, yyvsp[-4].equalssym_type, yyvsp[-3].FieldInits_type, yyvsp[-2].OPT_TRAVERSEsym_type, yyvsp[-1].OPT_CLEARsym_type, yyvsp[0].OPT_DONT_CLEARsym_type);
  ;}
    break;

  case 58:

    {
    yyval.FieldInits_type = yyvsp[0].ALT_FieldInit_SEP_commasym_type;
  ;}
    break;

  case 59:

    { yyval.FieldInit_type = Create_front_WhenCreate(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].OPT_CREATEsym_type, yyvsp[0].Expr_type);
  ;}
    break;

  case 60:

    { yyval.FieldInit_type = Create_front_WhenScope(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[0].Expr_type);
  ;}
    break;

  case 61:

    { yyval.FieldInit_type = Create_front_WhenDefining(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[0].Expr_type);
  ;}
    break;

  case 62:

    { yyval.FieldInit_type = Create_front_WhenApplied(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[0].Expr_type);
  ;}
    break;

  case 63:

    { yyval.FieldInit_type = Create_front_WhenChecks(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[0].Expr_type);
  ;}
    break;

  case 64:

    { yyval.Type_type = Create_front_Type(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].Identsym_type, yyvsp[0].OPT_openparsym_TypeList_closeparsym_type);
  ;}
    break;

  case 65:

    { yyval.Expr_type = Create_front_BinExpr(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].ALT_MonExpr1_SEP_SP_Oper_type.f1, yyvsp[0].ALT_MonExpr1_SEP_SP_Oper_type.f2);
  ;}
    break;

  case 66:

    { yyval.MonExpr1_type = Create_front_MonExpr(make_post_src_info(yylsp[-1].first_line, yylsp[0].last_line), yyvsp[-1].OPTMORE_Oper_type, yyvsp[0].SimpleExpr_type);
  ;}
    break;

  case 67:

    { yyval.SimpleExpr_type = Create_front_IdentExpr(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].Identsym_type);
  ;}
    break;

  case 68:

    { yyval.SimpleExpr_type = Create_front_QualExpr(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-2].SimpleExpr_type, yyvsp[0].Identsym_type);
  ;}
    break;

  case 69:

    { yyval.SimpleExpr_type = Create_front_IntExpr(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].Intsym_type);
  ;}
    break;

  case 70:

    { yyval.SimpleExpr_type = Create_front_BoolExpr(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].Boolsym_type);
  ;}
    break;

  case 71:

    { yyval.SimpleExpr_type = Create_front_StringExpr(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].StringOrKeyword_type);
  ;}
    break;

  case 72:

    { yyval.SimpleExpr_type = Create_front_NilExpr(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line));
  ;}
    break;

  case 73:

    { yyval.SimpleExpr_type = Create_front_CallExpr(make_post_src_info(yylsp[-3].first_line, yylsp[0].last_line), yyvsp[-3].SimpleExpr_type, yyvsp[-1].OPT_ExprList_type);
  ;}
    break;

  case 74:

    {
    yyval.StringOrKeyword_type = yyvsp[0].Stringsym_type;
  ;}
    break;

  case 75:

    {
    yyval.StringOrKeyword_type = yyvsp[0].Keywordsym_type;
  ;}
    break;

  case 76:

    {
    yyval.StringOrKeyword_type = yyvsp[0].Charsym_type;
  ;}
    break;

  case 77:

    { yyval.Check_type = Create_front_Check(make_post_src_info(yylsp[-4].first_line, yylsp[0].last_line), yyvsp[-3].Expr_type, yyvsp[-1].OPT_WARNINGsym_type, yyvsp[0].MORE_MonExpr1_type);
  ;}
    break;

  case 78:

    {
    yyval.NameSpaceList_type = yyvsp[0].ALT_NameSpace_SEP_commasym_SP_type;
  ;}
    break;

  case 79:

    {
    yyval.ExprList_type = yyvsp[0].ALT_Expr_SEP_commasym_SP_type;
  ;}
    break;

  case 80:

    {
    yyval.IdentList_type = yyvsp[0].ALT_Identsym_SEP_commasym_SP_type;
  ;}
    break;

  case 81:

    {
    yyval.TypeList_type = yyvsp[0].ALT_Type_SEP_commasym_SP_type;
  ;}
    break;

  case 82:

    { yyval.Alternator_type = FALSE; ;}
    break;

  case 83:

    { yyval.Alternator_type = TRUE; ;}
    break;

  case 84:

    { yyval.ScanInfo_type = Create_front_ScanInfo(make_post_src_info(yylsp[-2].first_line, yylsp[0].last_line), yyvsp[-1].OptType_type, yyvsp[0].OPT_COMMENTsym_type);
  ;}
    break;

  case 85:

    { yyval.Defines_type = Create_front_PlainDef(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].definessym_type);
  ;}
    break;

  case 86:

    { yyval.Defines_type = Create_front_MacroDef(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].equalssym_type);
  ;}
    break;

  case 87:

    { yyval.NameSpace_type = Create_front_NameSpace(make_post_src_info(yylsp[0].first_line, yylsp[0].last_line), yyvsp[0].Identsym_type);
  ;}
    break;

  case 88:

    {
    yyval.Oper_type = yyvsp[0].tildasym_type;
  ;}
    break;

  case 89:

    {
    yyval.Oper_type = yyvsp[0].exclaimsym_type;
  ;}
    break;

  case 90:

    {
    yyval.Oper_type = yyvsp[0].equalsequalssym_type;
  ;}
    break;

  case 91:

    {
    yyval.Oper_type = yyvsp[0].exclaimequalssym_type;
  ;}
    break;

  case 92:

    {
    yyval.Oper_type = yyvsp[0].lessthanequalssym_type;
  ;}
    break;

  case 93:

    {
    yyval.Oper_type = yyvsp[0].greaterthanequalssym_type;
  ;}
    break;

  case 94:

    {
    yyval.Oper_type = yyvsp[0].ampersandsym_type;
  ;}
    break;

  case 95:

    {
    yyval.Oper_type = yyvsp[0].ampersandampersandsym_type;
  ;}
    break;

  case 96:

    {
    yyval.Oper_type = yyvsp[0].verticalbarverticalbarsym_type;
  ;}
    break;

  case 97:

    {
    yyval.Oper_type = yyvsp[0].hatsym_type;
  ;}
    break;

  case 98:

    {
    yyval.Oper_type = yyvsp[0].plussym_type;
  ;}
    break;

  case 99:

    {
    yyval.Oper_type = yyvsp[0].minussym_type;
  ;}
    break;

  case 100:

    {
    yyval.Oper_type = yyvsp[0].starsym_type;
  ;}
    break;

  case 101:

    {
    yyval.Oper_type = yyvsp[0].slashsym_type;
  ;}
    break;

  case 102:

    {
    yyval.Oper_type = yyvsp[0].percentsym_type;
  ;}
    break;

  case 103:

    {
    yyval.Oper_type = yyvsp[0].lessthanlessthansym_type;
  ;}
    break;

  case 104:

    {
    yyval.Oper_type = yyvsp[0].greaterthangreaterthansym_type;
  ;}
    break;

  case 105:

    { yyval.NameOrField_type = front_AppliedName; ;}
    break;

  case 106:

    { yyval.NameOrField_type = front_AppliedField; ;}
    break;

  case 107:

    {
    yyval.OPT_USEsym_IdentList_type = NULL;
  ;}
    break;

  case 108:

    {
    yyval.OPT_USEsym_IdentList_type = yyvsp[0].IdentList_type;
  ;}
    break;

  case 109:

    {
    yyval.OPT_NAMESPACEsym_NameSpaceList_type = NULL;
  ;}
    break;

  case 110:

    {
    yyval.OPT_NAMESPACEsym_NameSpaceList_type = yyvsp[0].NameSpaceList_type;
  ;}
    break;

  case 111:

    {
    yyval.OPTMORE_Import_type = NULL;
  ;}
    break;

  case 112:

    {
    yyval.OPTMORE_Import_type = Create_List_front_Import(yyvsp[-1].Import_type, yyvsp[0].OPTMORE_Import_type);
  ;}
    break;

  case 113:

    {
    yyval.OPT_NonTerminals_type = NULL;
  ;}
    break;

  case 114:

    {
    yyval.OPT_NonTerminals_type = yyvsp[0].NonTerminals_type;
  ;}
    break;

  case 115:

    {
    yyval.ALT_ImportedNonTerminal_SEP_commasym_type = Create_List_front_ImportedNonTerminal(yyvsp[0].ImportedNonTerminal_type, NULL);
  ;}
    break;

  case 116:

    {
    yyval.ALT_ImportedNonTerminal_SEP_commasym_type = Create_List_front_ImportedNonTerminal(yyvsp[-2].ImportedNonTerminal_type, yyvsp[0].ALT_ImportedNonTerminal_SEP_commasym_type);
  ;}
    break;

  case 117:

    {
    yyval.OPT_colonsym_Identsym_type = NULL;
  ;}
    break;

  case 118:

    {
    yyval.OPT_colonsym_Identsym_type = yyvsp[0].Identsym_type;
  ;}
    break;

  case 119:

    {
    yyval.MORE_NonTerminal_type = Create_List_front_NonTerminal(yyvsp[0].NonTerminal_type, NULL);
  ;}
    break;

  case 120:

    {
    yyval.MORE_NonTerminal_type = Create_List_front_NonTerminal(yyvsp[-1].NonTerminal_type, yyvsp[0].MORE_NonTerminal_type);
  ;}
    break;

  case 121:

    {
    yyval.OPT_ROOTsym_type = FALSE;
  ;}
    break;

  case 122:

    {
    yyval.OPT_ROOTsym_type = TRUE;
  ;}
    break;

  case 123:

    {
    yyval.OPT_ScanInfo_type = NULL;
  ;}
    break;

  case 124:

    {
    yyval.OPT_ScanInfo_type = yyvsp[0].ScanInfo_type;
  ;}
    break;

  case 125:

    {
    yyval.OPT_Super_type = NULL;
  ;}
    break;

  case 126:

    {
    yyval.OPT_Super_type = yyvsp[0].Super_type;
  ;}
    break;

  case 127:

    {
    yyval.OPT_MEMOsym_type = FALSE;
  ;}
    break;

  case 128:

    {
    yyval.OPT_MEMOsym_type = TRUE;
  ;}
    break;

  case 129:

    {
    yyval.OPT_ENUMsym_type = FALSE;
  ;}
    break;

  case 130:

    {
    yyval.OPT_ENUMsym_type = TRUE;
  ;}
    break;

  case 131:

    {
    yyval.OPT_SKIPsym_type = FALSE;
  ;}
    break;

  case 132:

    {
    yyval.OPT_SKIPsym_type = TRUE;
  ;}
    break;

  case 133:

    {
    yyval.OPTMORE_Scoping_type = NULL;
  ;}
    break;

  case 134:

    {
    yyval.OPTMORE_Scoping_type = Create_List_front_Scoping(yyvsp[-1].Scoping_type, yyvsp[0].OPTMORE_Scoping_type);
  ;}
    break;

  case 135:

    {
    yyval.OPT_Choices_type.f1 = NULL;
    yyval.OPT_Choices_type.f2 = NULL;
    yyval.OPT_Choices_type.f3 = NULL;
    yyval.OPT_Choices_type.f4 = NULL;
    yyval.OPT_Choices_type.f5 = NULL;
  ;}
    break;

  case 136:

    {
    yyval.OPT_Choices_type.f1 = yyvsp[0].Choices_type.f1;
    yyval.OPT_Choices_type.f2 = yyvsp[0].Choices_type.f2;
    yyval.OPT_Choices_type.f3 = yyvsp[0].Choices_type.f3;
    yyval.OPT_Choices_type.f4 = yyvsp[0].Choices_type.f4;
    yyval.OPT_Choices_type.f5 = yyvsp[0].Choices_type.f5;
  ;}
    break;

  case 137:

    {
    yyval.OPT_CHECKSsym_OPTMORE_Check_type = NULL;
  ;}
    break;

  case 138:

    {
    yyval.OPT_CHECKSsym_OPTMORE_Check_type = yyvsp[0].OPTMORE_Check_type;
  ;}
    break;

  case 139:

    {
    yyval.OPTMORE_Check_type = NULL;
  ;}
    break;

  case 140:

    {
    yyval.OPTMORE_Check_type = Create_List_front_Check(yyvsp[-1].Check_type, yyvsp[0].OPTMORE_Check_type);
  ;}
    break;

  case 141:

    {
    yyval.ALT_Alternative_SEP_Or_type.f1 = Create_List_front_Alternative(yyvsp[0].Alternative_type, NULL);
    yyval.ALT_Alternative_SEP_Or_type.f2 = NULL;
  ;}
    break;

  case 142:

    {
    yyval.ALT_Alternative_SEP_Or_type.f1 = Create_List_front_Alternative(yyvsp[-2].Alternative_type, yyvsp[0].ALT_Alternative_SEP_Or_type.f1);
    yyval.ALT_Alternative_SEP_Or_type.f2 = Create_List_front_Or(yyvsp[-1].Or_type, yyvsp[0].ALT_Alternative_SEP_Or_type.f2);
  ;}
    break;

  case 143:

    {
    yyval.MORE_Symbol_type = Create_List_front_Symbol(yyvsp[0].Symbol_type, NULL);
  ;}
    break;

  case 144:

    {
    yyval.MORE_Symbol_type = Create_List_front_Symbol(yyvsp[-1].Symbol_type, yyvsp[0].MORE_Symbol_type);
  ;}
    break;

  case 145:

    {
    yyval.OPT_ALT_ONCE_SymbolORField_SEP_And_type.f1 = NULL;
    yyval.OPT_ALT_ONCE_SymbolORField_SEP_And_type.f2 = NULL;
    yyval.OPT_ALT_ONCE_SymbolORField_SEP_And_type.f3 = NULL;
  ;}
    break;

  case 146:

    {
    yyval.OPT_ALT_ONCE_SymbolORField_SEP_And_type.f1 = yyvsp[0].ALT_ONCE_SymbolORField_SEP_And_type.f1;
    yyval.OPT_ALT_ONCE_SymbolORField_SEP_And_type.f2 = yyvsp[0].ALT_ONCE_SymbolORField_SEP_And_type.f2;
    yyval.OPT_ALT_ONCE_SymbolORField_SEP_And_type.f3 = yyvsp[0].ALT_ONCE_SymbolORField_SEP_And_type.f3;
  ;}
    break;

  case 147:

    {
    yyval.ALT_ONCE_SymbolORField_SEP_And_type.f1 = Create_List_front_Symbol(yyvsp[0].ONCE_SymbolORField_type.f1, NULL);
    yyval.ALT_ONCE_SymbolORField_SEP_And_type.f2 = Create_List_front_Field(yyvsp[0].ONCE_SymbolORField_type.f2, NULL);
    yyval.ALT_ONCE_SymbolORField_SEP_And_type.f3 = NULL;
  ;}
    break;

  case 148:

    {
    yyval.ALT_ONCE_SymbolORField_SEP_And_type.f1 = Create_List_front_Symbol(yyvsp[-2].ONCE_SymbolORField_type.f1, yyvsp[0].ALT_ONCE_SymbolORField_SEP_And_type.f1);
    yyval.ALT_ONCE_SymbolORField_SEP_And_type.f2 = Create_List_front_Field(yyvsp[-2].ONCE_SymbolORField_type.f2, yyvsp[0].ALT_ONCE_SymbolORField_SEP_And_type.f2);
    yyval.ALT_ONCE_SymbolORField_SEP_And_type.f3 = Create_List_front_And(yyvsp[-1].And_type, yyvsp[0].ALT_ONCE_SymbolORField_SEP_And_type.f3);
  ;}
    break;

  case 149:

    {
    yyval.ONCE_SymbolORField_type.f1 = yyvsp[0].Symbol_type;
    yyval.ONCE_SymbolORField_type.f2 = NULL;
  ;}
    break;

  case 150:

    {
    yyval.ONCE_SymbolORField_type.f1 = NULL;
    yyval.ONCE_SymbolORField_type.f2 = yyvsp[0].Field_type;
  ;}
    break;

  case 151:

    {
    yyval.OPT_ScopeExpr_type = NULL;
  ;}
    break;

  case 152:

    {
    yyval.OPT_ScopeExpr_type = yyvsp[0].ScopeExpr_type;
  ;}
    break;

  case 153:

    {
    yyval.OPT_WARNINGsym_type = FALSE;
  ;}
    break;

  case 154:

    {
    yyval.OPT_WARNINGsym_type = TRUE;
  ;}
    break;

  case 155:

    {
    yyval.OPT_NAMEsym_Identsym_type = NULL;
  ;}
    break;

  case 156:

    {
    yyval.OPT_NAMEsym_Identsym_type = yyvsp[0].Identsym_type;
  ;}
    break;

  case 157:

    {
    yyval.OPT_exclaimsym_type = FALSE;
  ;}
    break;

  case 158:

    {
    yyval.OPT_exclaimsym_type = TRUE;
  ;}
    break;

  case 159:

    {
    yyval.ALT_Symbol1_SEP_Or_SP_type.f1 = Create_List_front_Symbol(yyvsp[0].Symbol1_type, NULL);
    yyval.ALT_Symbol1_SEP_Or_SP_type.f2 = NULL;
  ;}
    break;

  case 160:

    {
    yyval.ALT_Symbol1_SEP_Or_SP_type.f1 = Create_List_front_Symbol(yyvsp[-2].Symbol1_type, yyvsp[0].ALT_Symbol1_SEP_Or_SP_type.f1);
    yyval.ALT_Symbol1_SEP_Or_SP_type.f2 = Create_List_front_Or(yyvsp[-1].Or_type, yyvsp[0].ALT_Symbol1_SEP_Or_SP_type.f2);
  ;}
    break;

  case 161:

    {
    yyval.OPT_TYPEsym_Type_type = NULL;
  ;}
    break;

  case 162:

    {
    yyval.OPT_TYPEsym_Type_type = yyvsp[0].Type_type;
  ;}
    break;

  case 163:

    {
    yyval.OPT_FORWARDsym_type = FALSE;
  ;}
    break;

  case 164:

    {
    yyval.OPT_FORWARDsym_type = TRUE;
  ;}
    break;

  case 165:

    {
    yyval.OPT_NAMESPACEsym_Identsym_type = NULL;
  ;}
    break;

  case 166:

    {
    yyval.OPT_NAMESPACEsym_Identsym_type = yyvsp[0].Identsym_type;
  ;}
    break;

  case 167:

    {
    yyval.OPT_TRAVERSEsym_type = FALSE;
  ;}
    break;

  case 168:

    {
    yyval.OPT_TRAVERSEsym_type = TRUE;
  ;}
    break;

  case 169:

    {
    yyval.OPT_CLEARsym_type = FALSE;
  ;}
    break;

  case 170:

    {
    yyval.OPT_CLEARsym_type = TRUE;
  ;}
    break;

  case 171:

    {
    yyval.OPT_DONT_CLEARsym_type = FALSE;
  ;}
    break;

  case 172:

    {
    yyval.OPT_DONT_CLEARsym_type = TRUE;
  ;}
    break;

  case 173:

    {
    yyval.ALT_FieldInit_SEP_commasym_type = Create_List_front_FieldInit(yyvsp[0].FieldInit_type, NULL);
  ;}
    break;

  case 174:

    {
    yyval.ALT_FieldInit_SEP_commasym_type = Create_List_front_FieldInit(yyvsp[-2].FieldInit_type, yyvsp[0].ALT_FieldInit_SEP_commasym_type);
  ;}
    break;

  case 175:

    {
    yyval.OPT_CREATEsym_type = FALSE;
  ;}
    break;

  case 176:

    {
    yyval.OPT_CREATEsym_type = TRUE;
  ;}
    break;

  case 177:

    {
    yyval.OPT_openparsym_TypeList_closeparsym_type = NULL;
  ;}
    break;

  case 178:

    {
    yyval.OPT_openparsym_TypeList_closeparsym_type = yyvsp[-1].TypeList_type;
  ;}
    break;

  case 179:

    {
    yyval.ALT_MonExpr1_SEP_SP_Oper_type.f1 = Create_List_front_Expr(yyvsp[0].MonExpr1_type, NULL);
    yyval.ALT_MonExpr1_SEP_SP_Oper_type.f2 = NULL;
  ;}
    break;

  case 180:

    {
    yyval.ALT_MonExpr1_SEP_SP_Oper_type.f1 = Create_List_front_Expr(yyvsp[-2].MonExpr1_type, yyvsp[0].ALT_MonExpr1_SEP_SP_Oper_type.f1);
    yyval.ALT_MonExpr1_SEP_SP_Oper_type.f2 = Create_List_Ident(yyvsp[-1].Oper_type, yyvsp[0].ALT_MonExpr1_SEP_SP_Oper_type.f2);
  ;}
    break;

  case 181:

    {
    yyval.OPTMORE_Oper_type = NULL;
  ;}
    break;

  case 182:

    {
    yyval.OPTMORE_Oper_type = Create_List_Ident(yyvsp[-1].Oper_type, yyvsp[0].OPTMORE_Oper_type);
  ;}
    break;

  case 183:

    {
    yyval.OPT_ExprList_type = NULL;
  ;}
    break;

  case 184:

    {
    yyval.OPT_ExprList_type = yyvsp[0].ExprList_type;
  ;}
    break;

  case 185:

    {
    yyval.MORE_MonExpr1_type = Create_List_front_Expr(yyvsp[0].MonExpr1_type, NULL);
  ;}
    break;

  case 186:

    {
    yyval.MORE_MonExpr1_type = Create_List_front_Expr(yyvsp[-1].MonExpr1_type, yyvsp[0].MORE_MonExpr1_type);
  ;}
    break;

  case 187:

    {
    yyval.ALT_NameSpace_SEP_commasym_SP_type = Create_List_front_NameSpace(yyvsp[0].NameSpace_type, NULL);
  ;}
    break;

  case 188:

    {
    yyval.ALT_NameSpace_SEP_commasym_SP_type = Create_List_front_NameSpace(yyvsp[-2].NameSpace_type, yyvsp[0].ALT_NameSpace_SEP_commasym_SP_type);
  ;}
    break;

  case 189:

    {
    yyval.ALT_Expr_SEP_commasym_SP_type = Create_List_front_Expr(yyvsp[0].Expr_type, NULL);
  ;}
    break;

  case 190:

    {
    yyval.ALT_Expr_SEP_commasym_SP_type = Create_List_front_Expr(yyvsp[-2].Expr_type, yyvsp[0].ALT_Expr_SEP_commasym_SP_type);
  ;}
    break;

  case 191:

    {
    yyval.ALT_Identsym_SEP_commasym_SP_type = Create_List_Ident(yyvsp[0].Identsym_type, NULL);
  ;}
    break;

  case 192:

    {
    yyval.ALT_Identsym_SEP_commasym_SP_type = Create_List_Ident(yyvsp[-2].Identsym_type, yyvsp[0].ALT_Identsym_SEP_commasym_SP_type);
  ;}
    break;

  case 193:

    {
    yyval.ALT_Type_SEP_commasym_SP_type = Create_List_front_Type(yyvsp[0].Type_type, NULL);
  ;}
    break;

  case 194:

    {
    yyval.ALT_Type_SEP_commasym_SP_type = Create_List_front_Type(yyvsp[-2].Type_type, yyvsp[0].ALT_Type_SEP_commasym_SP_type);
  ;}
    break;

  case 195:

    {
    yyval.OPT_COMMENTsym_type = FALSE;
  ;}
    break;

  case 196:

    {
    yyval.OPT_COMMENTsym_type = TRUE;
  ;}
    break;

  case 197:

    { yyval.front_type = (front_front)Get_sub_tree (); ;}
    break;

  case 198:

    { front_multi_action ((void*)yyvsp[0].front_type); YYACCEPT; ;}
    break;

  case 199:

    { yyval.Import_type = (front_Import)Get_sub_tree (); ;}
    break;

  case 200:

    { front_multi_action ((void*)yyvsp[0].Import_type); YYACCEPT; ;}
    break;

  case 201:

    { yyval.ImportedNonTerminals_type = (List_front_ImportedNonTerminal)Get_sub_tree (); ;}
    break;

  case 202:

    { front_multi_action ((void*)yyvsp[0].ImportedNonTerminals_type); YYACCEPT; ;}
    break;

  case 203:

    { yyval.ImportedNonTerminal_type = (front_ImportedNonTerminal)Get_sub_tree (); ;}
    break;

  case 204:

    { front_multi_action ((void*)yyvsp[0].ImportedNonTerminal_type); YYACCEPT; ;}
    break;

  case 205:

    { yyval.NonTerminals_type = (List_front_NonTerminal)Get_sub_tree (); ;}
    break;

  case 206:

    { front_multi_action ((void*)yyvsp[0].NonTerminals_type); YYACCEPT; ;}
    break;

  case 207:

    { yyval.NonTerminal_type = (front_NonTerminal)Get_sub_tree (); ;}
    break;

  case 208:

    { front_multi_action ((void*)yyvsp[0].NonTerminal_type); YYACCEPT; ;}
    break;

  case 209:

    { yyval.Super_type = (front_Super)Get_sub_tree (); ;}
    break;

  case 210:

    { front_multi_action ((void*)yyvsp[0].Super_type); YYACCEPT; ;}
    break;

  case 211:

    { yyval.Rhs_type = (front_Rhs)Get_sub_tree (); ;}
    break;

  case 212:

    { front_multi_action ((void*)yyvsp[0].Rhs_type); YYACCEPT; ;}
    break;

  case 213:

    { yyval.Scoping_type = (front_Scoping)Get_sub_tree (); ;}
    break;

  case 214:

    { front_multi_action ((void*)yyvsp[0].Scoping_type); YYACCEPT; ;}
    break;

  case 215:

    { yyval.Alternative_type = (front_Alternative)Get_sub_tree (); ;}
    break;

  case 216:

    { front_multi_action ((void*)yyvsp[0].Alternative_type); YYACCEPT; ;}
    break;

  case 217:

    { yyval.Symbol_type = (front_Symbol)Get_sub_tree (); ;}
    break;

  case 218:

    { front_multi_action ((void*)yyvsp[0].Symbol_type); YYACCEPT; ;}
    break;

  case 219:

    { yyval.Symbol1_type = (front_Symbol)Get_sub_tree (); ;}
    break;

  case 220:

    { front_multi_action ((void*)yyvsp[0].Symbol1_type); YYACCEPT; ;}
    break;

  case 221:

    { yyval.AltSymbol_type = (front_Symbol)Get_sub_tree (); ;}
    break;

  case 222:

    { front_multi_action ((void*)yyvsp[0].AltSymbol_type); YYACCEPT; ;}
    break;

  case 223:

    { yyval.SymbolSeq_type = (front_Symbol)Get_sub_tree (); ;}
    break;

  case 224:

    { front_multi_action ((void*)yyvsp[0].SymbolSeq_type); YYACCEPT; ;}
    break;

  case 225:

    { yyval.And_type = (front_And)Get_sub_tree (); ;}
    break;

  case 226:

    { front_multi_action ((void*)yyvsp[0].And_type); YYACCEPT; ;}
    break;

  case 227:

    { yyval.Or_type = (front_Or)Get_sub_tree (); ;}
    break;

  case 228:

    { front_multi_action ((void*)yyvsp[0].Or_type); YYACCEPT; ;}
    break;

  case 229:

    { yyval.Symbol2_type = (front_Symbol)Get_sub_tree (); ;}
    break;

  case 230:

    { front_multi_action ((void*)yyvsp[0].Symbol2_type); YYACCEPT; ;}
    break;

  case 231:

    { yyval.SimpleSymbol_type = (front_Symbol)Get_sub_tree (); ;}
    break;

  case 232:

    { front_multi_action ((void*)yyvsp[0].SimpleSymbol_type); YYACCEPT; ;}
    break;

  case 233:

    { yyval.IdSym_type = (front_Symbol)Get_sub_tree (); ;}
    break;

  case 234:

    { front_multi_action ((void*)yyvsp[0].IdSym_type); YYACCEPT; ;}
    break;

  case 235:

    { yyval.OptType_type = (front_Type)Get_sub_tree (); ;}
    break;

  case 236:

    { front_multi_action ((void*)yyvsp[0].OptType_type); YYACCEPT; ;}
    break;

  case 237:

    { yyval.DefiningSym_type = (front_Symbol)Get_sub_tree (); ;}
    break;

  case 238:

    { front_multi_action ((void*)yyvsp[0].DefiningSym_type); YYACCEPT; ;}
    break;

  case 239:

    { yyval.ScopeExpr_type = (front_Expr)Get_sub_tree (); ;}
    break;

  case 240:

    { front_multi_action ((void*)yyvsp[0].ScopeExpr_type); YYACCEPT; ;}
    break;

  case 241:

    { yyval.Defining_id_type = (front_Defining_id)Get_sub_tree (); ;}
    break;

  case 242:

    { front_multi_action ((void*)yyvsp[0].Defining_id_type); YYACCEPT; ;}
    break;

  case 243:

    { yyval.Define_type = (front_Define)Get_sub_tree (); ;}
    break;

  case 244:

    { front_multi_action ((void*)yyvsp[0].Define_type); YYACCEPT; ;}
    break;

  case 245:

    { yyval.Field_type = (front_Field)Get_sub_tree (); ;}
    break;

  case 246:

    { front_multi_action ((void*)yyvsp[0].Field_type); YYACCEPT; ;}
    break;

  case 247:

    { yyval.FieldInits_type = (List_front_FieldInit)Get_sub_tree (); ;}
    break;

  case 248:

    { front_multi_action ((void*)yyvsp[0].FieldInits_type); YYACCEPT; ;}
    break;

  case 249:

    { yyval.FieldInit_type = (front_FieldInit)Get_sub_tree (); ;}
    break;

  case 250:

    { front_multi_action ((void*)yyvsp[0].FieldInit_type); YYACCEPT; ;}
    break;

  case 251:

    { yyval.Type_type = (front_Type)Get_sub_tree (); ;}
    break;

  case 252:

    { front_multi_action ((void*)yyvsp[0].Type_type); YYACCEPT; ;}
    break;

  case 253:

    { yyval.Expr_type = (front_Expr)Get_sub_tree (); ;}
    break;

  case 254:

    { front_multi_action ((void*)yyvsp[0].Expr_type); YYACCEPT; ;}
    break;

  case 255:

    { yyval.MonExpr1_type = (front_Expr)Get_sub_tree (); ;}
    break;

  case 256:

    { front_multi_action ((void*)yyvsp[0].MonExpr1_type); YYACCEPT; ;}
    break;

  case 257:

    { yyval.SimpleExpr_type = (front_Expr)Get_sub_tree (); ;}
    break;

  case 258:

    { front_multi_action ((void*)yyvsp[0].SimpleExpr_type); YYACCEPT; ;}
    break;

  case 259:

    { yyval.StringOrKeyword_type = (String)Get_sub_tree (); ;}
    break;

  case 260:

    { front_multi_action ((void*)yyvsp[0].StringOrKeyword_type); YYACCEPT; ;}
    break;

  case 261:

    { yyval.Check_type = (front_Check)Get_sub_tree (); ;}
    break;

  case 262:

    { front_multi_action ((void*)yyvsp[0].Check_type); YYACCEPT; ;}
    break;

  case 263:

    { yyval.NameSpaceList_type = (List_front_NameSpace)Get_sub_tree (); ;}
    break;

  case 264:

    { front_multi_action ((void*)yyvsp[0].NameSpaceList_type); YYACCEPT; ;}
    break;

  case 265:

    { yyval.ExprList_type = (List_front_Expr)Get_sub_tree (); ;}
    break;

  case 266:

    { front_multi_action ((void*)yyvsp[0].ExprList_type); YYACCEPT; ;}
    break;

  case 267:

    { yyval.IdentList_type = (List_Ident)Get_sub_tree (); ;}
    break;

  case 268:

    { front_multi_action ((void*)yyvsp[0].IdentList_type); YYACCEPT; ;}
    break;

  case 269:

    { yyval.TypeList_type = (List_front_Type)Get_sub_tree (); ;}
    break;

  case 270:

    { front_multi_action ((void*)yyvsp[0].TypeList_type); YYACCEPT; ;}
    break;

  case 271:

    { yyval.Alternator_type = (front_Alternator)Get_sub_tree (); ;}
    break;

  case 272:

    { front_multi_action ((void*)yyvsp[0].Alternator_type); YYACCEPT; ;}
    break;

  case 273:

    { yyval.ScanInfo_type = (front_ScanInfo)Get_sub_tree (); ;}
    break;

  case 274:

    { front_multi_action ((void*)yyvsp[0].ScanInfo_type); YYACCEPT; ;}
    break;

  case 275:

    { yyval.Defines_type = (front_Defines)Get_sub_tree (); ;}
    break;

  case 276:

    { front_multi_action ((void*)yyvsp[0].Defines_type); YYACCEPT; ;}
    break;

  case 277:

    { yyval.NameSpace_type = (front_NameSpace)Get_sub_tree (); ;}
    break;

  case 278:

    { front_multi_action ((void*)yyvsp[0].NameSpace_type); YYACCEPT; ;}
    break;

  case 279:

    { yyval.Oper_type = (Ident)Get_sub_tree (); ;}
    break;

  case 280:

    { front_multi_action ((void*)yyvsp[0].Oper_type); YYACCEPT; ;}
    break;

  case 281:

    { yyval.NameOrField_type = (front_NameOrField)Get_sub_tree (); ;}
    break;

  case 282:

    { front_multi_action ((void*)yyvsp[0].NameOrField_type); YYACCEPT; ;}
    break;

  case 283:

    { yyval.OPT_USEsym_IdentList_type = (List_Ident)Get_sub_tree (); ;}
    break;

  case 284:

    { front_multi_action ((void*)yyvsp[0].OPT_USEsym_IdentList_type); YYACCEPT; ;}
    break;

  case 285:

    { yyval.OPT_NAMESPACEsym_NameSpaceList_type = (List_front_NameSpace)Get_sub_tree (); ;}
    break;

  case 286:

    { front_multi_action ((void*)yyvsp[0].OPT_NAMESPACEsym_NameSpaceList_type); YYACCEPT; ;}
    break;

  case 287:

    { yyval.OPTMORE_Import_type = (List_front_Import)Get_sub_tree (); ;}
    break;

  case 288:

    { front_multi_action ((void*)yyvsp[0].OPTMORE_Import_type); YYACCEPT; ;}
    break;

  case 289:

    { yyval.OPT_NonTerminals_type = (List_front_NonTerminal)Get_sub_tree (); ;}
    break;

  case 290:

    { front_multi_action ((void*)yyvsp[0].OPT_NonTerminals_type); YYACCEPT; ;}
    break;

  case 291:

    { yyval.ALT_ImportedNonTerminal_SEP_commasym_type = (List_front_ImportedNonTerminal)Get_sub_tree (); ;}
    break;

  case 292:

    { front_multi_action ((void*)yyvsp[0].ALT_ImportedNonTerminal_SEP_commasym_type); YYACCEPT; ;}
    break;

  case 293:

    { yyval.OPT_colonsym_Identsym_type = (Ident)Get_sub_tree (); ;}
    break;

  case 294:

    { front_multi_action ((void*)yyvsp[0].OPT_colonsym_Identsym_type); YYACCEPT; ;}
    break;

  case 295:

    { yyval.MORE_NonTerminal_type = (List_front_NonTerminal)Get_sub_tree (); ;}
    break;

  case 296:

    { front_multi_action ((void*)yyvsp[0].MORE_NonTerminal_type); YYACCEPT; ;}
    break;

  case 297:

    { yyval.OPT_ROOTsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 298:

    { front_multi_action ((void*)yyvsp[0].OPT_ROOTsym_type); YYACCEPT; ;}
    break;

  case 299:

    { yyval.OPT_ScanInfo_type = (front_ScanInfo)Get_sub_tree (); ;}
    break;

  case 300:

    { front_multi_action ((void*)yyvsp[0].OPT_ScanInfo_type); YYACCEPT; ;}
    break;

  case 301:

    { yyval.OPT_Super_type = (front_Super)Get_sub_tree (); ;}
    break;

  case 302:

    { front_multi_action ((void*)yyvsp[0].OPT_Super_type); YYACCEPT; ;}
    break;

  case 303:

    { yyval.OPT_MEMOsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 304:

    { front_multi_action ((void*)yyvsp[0].OPT_MEMOsym_type); YYACCEPT; ;}
    break;

  case 305:

    { yyval.OPT_ENUMsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 306:

    { front_multi_action ((void*)yyvsp[0].OPT_ENUMsym_type); YYACCEPT; ;}
    break;

  case 307:

    { yyval.OPT_SKIPsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 308:

    { front_multi_action ((void*)yyvsp[0].OPT_SKIPsym_type); YYACCEPT; ;}
    break;

  case 309:

    { yyval.OPTMORE_Scoping_type = (List_front_Scoping)Get_sub_tree (); ;}
    break;

  case 310:

    { front_multi_action ((void*)yyvsp[0].OPTMORE_Scoping_type); YYACCEPT; ;}
    break;

  case 311:

    { yyval.OPT_CHECKSsym_OPTMORE_Check_type = (List_front_Check)Get_sub_tree (); ;}
    break;

  case 312:

    { front_multi_action ((void*)yyvsp[0].OPT_CHECKSsym_OPTMORE_Check_type); YYACCEPT; ;}
    break;

  case 313:

    { yyval.OPTMORE_Check_type = (List_front_Check)Get_sub_tree (); ;}
    break;

  case 314:

    { front_multi_action ((void*)yyvsp[0].OPTMORE_Check_type); YYACCEPT; ;}
    break;

  case 315:

    { yyval.MORE_Symbol_type = (List_front_Symbol)Get_sub_tree (); ;}
    break;

  case 316:

    { front_multi_action ((void*)yyvsp[0].MORE_Symbol_type); YYACCEPT; ;}
    break;

  case 317:

    { yyval.OPT_ScopeExpr_type = (front_Expr)Get_sub_tree (); ;}
    break;

  case 318:

    { front_multi_action ((void*)yyvsp[0].OPT_ScopeExpr_type); YYACCEPT; ;}
    break;

  case 319:

    { yyval.OPT_WARNINGsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 320:

    { front_multi_action ((void*)yyvsp[0].OPT_WARNINGsym_type); YYACCEPT; ;}
    break;

  case 321:

    { yyval.OPT_NAMEsym_Identsym_type = (Ident)Get_sub_tree (); ;}
    break;

  case 322:

    { front_multi_action ((void*)yyvsp[0].OPT_NAMEsym_Identsym_type); YYACCEPT; ;}
    break;

  case 323:

    { yyval.OPT_exclaimsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 324:

    { front_multi_action ((void*)yyvsp[0].OPT_exclaimsym_type); YYACCEPT; ;}
    break;

  case 325:

    { yyval.OPT_TYPEsym_Type_type = (front_Type)Get_sub_tree (); ;}
    break;

  case 326:

    { front_multi_action ((void*)yyvsp[0].OPT_TYPEsym_Type_type); YYACCEPT; ;}
    break;

  case 327:

    { yyval.OPT_FORWARDsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 328:

    { front_multi_action ((void*)yyvsp[0].OPT_FORWARDsym_type); YYACCEPT; ;}
    break;

  case 329:

    { yyval.OPT_NAMESPACEsym_Identsym_type = (Ident)Get_sub_tree (); ;}
    break;

  case 330:

    { front_multi_action ((void*)yyvsp[0].OPT_NAMESPACEsym_Identsym_type); YYACCEPT; ;}
    break;

  case 331:

    { yyval.OPT_TRAVERSEsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 332:

    { front_multi_action ((void*)yyvsp[0].OPT_TRAVERSEsym_type); YYACCEPT; ;}
    break;

  case 333:

    { yyval.OPT_CLEARsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 334:

    { front_multi_action ((void*)yyvsp[0].OPT_CLEARsym_type); YYACCEPT; ;}
    break;

  case 335:

    { yyval.OPT_DONT_CLEARsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 336:

    { front_multi_action ((void*)yyvsp[0].OPT_DONT_CLEARsym_type); YYACCEPT; ;}
    break;

  case 337:

    { yyval.ALT_FieldInit_SEP_commasym_type = (List_front_FieldInit)Get_sub_tree (); ;}
    break;

  case 338:

    { front_multi_action ((void*)yyvsp[0].ALT_FieldInit_SEP_commasym_type); YYACCEPT; ;}
    break;

  case 339:

    { yyval.OPT_CREATEsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 340:

    { front_multi_action ((void*)yyvsp[0].OPT_CREATEsym_type); YYACCEPT; ;}
    break;

  case 341:

    { yyval.OPT_openparsym_TypeList_closeparsym_type = (List_front_Type)Get_sub_tree (); ;}
    break;

  case 342:

    { front_multi_action ((void*)yyvsp[0].OPT_openparsym_TypeList_closeparsym_type); YYACCEPT; ;}
    break;

  case 343:

    { yyval.OPTMORE_Oper_type = (List_Ident)Get_sub_tree (); ;}
    break;

  case 344:

    { front_multi_action ((void*)yyvsp[0].OPTMORE_Oper_type); YYACCEPT; ;}
    break;

  case 345:

    { yyval.OPT_ExprList_type = (List_front_Expr)Get_sub_tree (); ;}
    break;

  case 346:

    { front_multi_action ((void*)yyvsp[0].OPT_ExprList_type); YYACCEPT; ;}
    break;

  case 347:

    { yyval.MORE_MonExpr1_type = (List_front_Expr)Get_sub_tree (); ;}
    break;

  case 348:

    { front_multi_action ((void*)yyvsp[0].MORE_MonExpr1_type); YYACCEPT; ;}
    break;

  case 349:

    { yyval.ALT_NameSpace_SEP_commasym_SP_type = (List_front_NameSpace)Get_sub_tree (); ;}
    break;

  case 350:

    { front_multi_action ((void*)yyvsp[0].ALT_NameSpace_SEP_commasym_SP_type); YYACCEPT; ;}
    break;

  case 351:

    { yyval.ALT_Expr_SEP_commasym_SP_type = (List_front_Expr)Get_sub_tree (); ;}
    break;

  case 352:

    { front_multi_action ((void*)yyvsp[0].ALT_Expr_SEP_commasym_SP_type); YYACCEPT; ;}
    break;

  case 353:

    { yyval.ALT_Identsym_SEP_commasym_SP_type = (List_Ident)Get_sub_tree (); ;}
    break;

  case 354:

    { front_multi_action ((void*)yyvsp[0].ALT_Identsym_SEP_commasym_SP_type); YYACCEPT; ;}
    break;

  case 355:

    { yyval.ALT_Type_SEP_commasym_SP_type = (List_front_Type)Get_sub_tree (); ;}
    break;

  case 356:

    { front_multi_action ((void*)yyvsp[0].ALT_Type_SEP_commasym_SP_type); YYACCEPT; ;}
    break;

  case 357:

    { yyval.OPT_COMMENTsym_type = (Bool)Get_sub_tree (); ;}
    break;

  case 358:

    { front_multi_action ((void*)yyvsp[0].OPT_COMMENTsym_type); YYACCEPT; ;}
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



