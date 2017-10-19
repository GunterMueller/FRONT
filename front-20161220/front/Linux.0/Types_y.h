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
/* Line 1268 of yacc.c.  */

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE Types_lval;

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

extern YYLTYPE Types_lloc;


