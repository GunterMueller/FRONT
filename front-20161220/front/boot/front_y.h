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
/* Line 1268 of yacc.c.  */

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE front_lval;

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

extern YYLTYPE front_lloc;


