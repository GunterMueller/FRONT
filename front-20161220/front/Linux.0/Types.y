%{
#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "Types.h"

extern int input_line_nr;

struct yy_buffer_state *Types_dummy_state (void);
struct yy_buffer_state *Types_scanner_state (void);
%}

%token NONSENSE
%token hashincludespacelessthanstdargdothgreaterthansym
%token hashincludespacelessthanstddefdothgreaterthansym
%token hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym
%token typedefsym
%token enumsym
%token openchainsym
%token commasym
%token closechainsym
%token semicolonsym
%token externspacecharspacestarsym
%token underscorenamesopenbrkclosebrksemicolonsym
%token hashdefinespaceNUMunderscoresym
%token hashifndefspaceDEFunderscoreTYPEunderscoresym
%token hashdefinespaceDEFunderscoreTYPEunderscoresym
%token typedefspacestructspacesunderscoresym
%token starsym
%token typedefspacesym
%token hashendifsym
%token hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym
%token hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym
%token hashincludespacelessthanfrontslashSymTabdothgreaterthansym
%token hashincludespacebackslashdoublequotesym
%token underscoreparsedothbackslashdoublequotesym
%token underscoredefsdothbackslashdoublequotesym
%token dothbackslashdoublequotesym
%token typedefspaceBindspaceBindunderscoresym
%token typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym
%token hashdefinespaceListunderscoreBindunderscoresym
%token underscoredataopenparxcloseparsym
%token openparBindunderscoresym
%token closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym
%token underscorenextopenparxcloseparsym
%token openparListunderscoreBindunderscoresym
%token closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym
%token hashdefinespaceBindunderscoresym
%token _kindsym
%token externsym
%token underscorerootsemicolonsym
%token hashifndefspaceDEFunderscoreSTRUCTunderscoresym
%token hashdefinespaceDEFunderscoreSTRUCTunderscoresym
%token structsym
%token s_sym
%token _USER_FIELDSsym
%token _sym
%token unionspaceopenchainsym
%token closechainspacesubsemicolonsym
%token hashdefinesym
%token openparunderscorepcloseparsym
%token openparsym
%token openparstarunderscorepcloseparsym
%token underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym
%token dotsubdotsym
%token dotsym
%token closeparsym
%token CREATEsym
%token hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym
%token spacestarslashsym
%token Intsym
%token Identsym
%token hole_Types
%token start_Types
%token hole_includes2
%token start_includes2
%token hole_EnumType
%token start_EnumType
%token hole_Enums
%token start_Enums
%token hole_BindType
%token start_BindType
%token hole_PointerType
%token start_PointerType
%token hole_subtypedef
%token start_subtypedef
%token hole_StructType
%token start_StructType
%token hole_struct_type
%token start_struct_type
%token hole_sub_union
%token start_sub_union
%token hole_macro
%token start_macro
%token hole_field
%token start_field
%token hole_TypeName
%token start_TypeName
%token hole_CreateFunction
%token start_CreateFunction
%token hole_TypeNames
%token start_TypeNames
%token hole_OPTMORE_EnumType
%token start_OPTMORE_EnumType
%token hole_OPTMORE_PointerType
%token start_OPTMORE_PointerType
%token hole_OPTMORE_subtypedef
%token start_OPTMORE_subtypedef
%token hole_OPTMORE_BindType
%token start_OPTMORE_BindType
%token hole_OPTMORE_StructType
%token start_OPTMORE_StructType
%token hole_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym
%token start_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym
%token hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym
%token start_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym
%token hole_ALT_TypeName_SEP_commasym_NL
%token start_ALT_TypeName_SEP_commasym_NL
%token hole_OPTMORE_macro
%token start_OPTMORE_macro
%token hole_OPTMORE_CreateFunction
%token start_OPTMORE_CreateFunction
%token hole_OPT_Identsym__USER_FIELDSsym
%token start_OPT_Identsym__USER_FIELDSsym
%token hole_OPTMORE_field
%token start_OPTMORE_field
%token hole_OPT_sub_union
%token start_OPT_sub_union
%token hole_OPT_Identsym
%token start_OPT_Identsym
%token hole_OPTMORE_struct_type
%token start_OPTMORE_struct_type
%token hole_OPTMORE_dotsubdotsym_Identsym
%token start_OPTMORE_dotsubdotsym_Identsym
%token hole_ALT_TypeName_SEP__sym
%token start_ALT_TypeName_SEP__sym

%union {
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
}

%type <hashincludespacelessthanstdargdothgreaterthansym_type>	hashincludespacelessthanstdargdothgreaterthansym
%type <hashincludespacelessthanstddefdothgreaterthansym_type>	hashincludespacelessthanstddefdothgreaterthansym
%type <hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym_type>	hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym
%type <typedefsym_type>	typedefsym
%type <enumsym_type>	enumsym
%type <openchainsym_type>	openchainsym
%type <commasym_type>	commasym
%type <closechainsym_type>	closechainsym
%type <semicolonsym_type>	semicolonsym
%type <externspacecharspacestarsym_type>	externspacecharspacestarsym
%type <underscorenamesopenbrkclosebrksemicolonsym_type>	underscorenamesopenbrkclosebrksemicolonsym
%type <hashdefinespaceNUMunderscoresym_type>	hashdefinespaceNUMunderscoresym
%type <hashifndefspaceDEFunderscoreTYPEunderscoresym_type>	hashifndefspaceDEFunderscoreTYPEunderscoresym
%type <hashdefinespaceDEFunderscoreTYPEunderscoresym_type>	hashdefinespaceDEFunderscoreTYPEunderscoresym
%type <typedefspacestructspacesunderscoresym_type>	typedefspacestructspacesunderscoresym
%type <starsym_type>	starsym
%type <typedefspacesym_type>	typedefspacesym
%type <hashendifsym_type>	hashendifsym
%type <hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym_type>	hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym
%type <hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym_type>	hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym
%type <hashincludespacelessthanfrontslashSymTabdothgreaterthansym_type>	hashincludespacelessthanfrontslashSymTabdothgreaterthansym
%type <hashincludespacebackslashdoublequotesym_type>	hashincludespacebackslashdoublequotesym
%type <underscoreparsedothbackslashdoublequotesym_type>	underscoreparsedothbackslashdoublequotesym
%type <underscoredefsdothbackslashdoublequotesym_type>	underscoredefsdothbackslashdoublequotesym
%type <dothbackslashdoublequotesym_type>	dothbackslashdoublequotesym
%type <typedefspaceBindspaceBindunderscoresym_type>	typedefspaceBindspaceBindunderscoresym
%type <typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym_type>	typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym
%type <hashdefinespaceListunderscoreBindunderscoresym_type>	hashdefinespaceListunderscoreBindunderscoresym
%type <underscoredataopenparxcloseparsym_type>	underscoredataopenparxcloseparsym
%type <openparBindunderscoresym_type>	openparBindunderscoresym
%type <closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym_type>	closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym
%type <underscorenextopenparxcloseparsym_type>	underscorenextopenparxcloseparsym
%type <openparListunderscoreBindunderscoresym_type>	openparListunderscoreBindunderscoresym
%type <closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym_type>	closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym
%type <hashdefinespaceBindunderscoresym_type>	hashdefinespaceBindunderscoresym
%type <_kindsym_type>	_kindsym
%type <externsym_type>	externsym
%type <underscorerootsemicolonsym_type>	underscorerootsemicolonsym
%type <hashifndefspaceDEFunderscoreSTRUCTunderscoresym_type>	hashifndefspaceDEFunderscoreSTRUCTunderscoresym
%type <hashdefinespaceDEFunderscoreSTRUCTunderscoresym_type>	hashdefinespaceDEFunderscoreSTRUCTunderscoresym
%type <structsym_type>	structsym
%type <s_sym_type>	s_sym
%type <_USER_FIELDSsym_type>	_USER_FIELDSsym
%type <_sym_type>	_sym
%type <unionspaceopenchainsym_type>	unionspaceopenchainsym
%type <closechainspacesubsemicolonsym_type>	closechainspacesubsemicolonsym
%type <hashdefinesym_type>	hashdefinesym
%type <openparunderscorepcloseparsym_type>	openparunderscorepcloseparsym
%type <openparsym_type>	openparsym
%type <openparstarunderscorepcloseparsym_type>	openparstarunderscorepcloseparsym
%type <underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym_type>	underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym
%type <dotsubdotsym_type>	dotsubdotsym
%type <dotsym_type>	dotsym
%type <closeparsym_type>	closeparsym
%type <CREATEsym_type>	CREATEsym
%type <hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym_type>	hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym
%type <spacestarslashsym_type>	spacestarslashsym
%type <Intsym_type>	Intsym
%type <Identsym_type>	Identsym
%type <Types_type>	Types
%type <includes1_type>	includes1
%type <includes2_type>	includes2
%type <EnumType_type>	EnumType
%type <Enums_type>	Enums
%type <BindType_type>	BindType
%type <PointerType_type>	PointerType
%type <subtypedef_type>	subtypedef
%type <RootDecl_type>	RootDecl
%type <StructType_type>	StructType
%type <struct_type_type>	struct_type
%type <sub_union_type>	sub_union
%type <macro_type>	macro
%type <field_type>	field
%type <TypeName_type>	TypeName
%type <CreateFunction_type>	CreateFunction
%type <TypeNames_type>	TypeNames
%type <OPTMORE_EnumType_type>	OPTMORE_EnumType
%type <OPTMORE_PointerType_type>	OPTMORE_PointerType
%type <OPTMORE_subtypedef_type>	OPTMORE_subtypedef
%type <OPTMORE_BindType_type>	OPTMORE_BindType
%type <OPTMORE_StructType_type>	OPTMORE_StructType
%type <OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_type>	OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym
%type <OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_type>	OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym
%type <ALT_TypeName_SEP_commasym_NL_type>	ALT_TypeName_SEP_commasym_NL
%type <OPTMORE_macro_type>	OPTMORE_macro
%type <OPTMORE_CreateFunction_type>	OPTMORE_CreateFunction
%type <OPT_Identsym__USER_FIELDSsym_type>	OPT_Identsym__USER_FIELDSsym
%type <OPTMORE_field_type>	OPTMORE_field
%type <OPT_sub_union_type>	OPT_sub_union
%type <OPT_Identsym_type>	OPT_Identsym
%type <OPTMORE_struct_type_type>	OPTMORE_struct_type
%type <OPTMORE_dotsubdotsym_Identsym_type>	OPTMORE_dotsubdotsym_Identsym
%type <ALT_TypeName_SEP__sym_type>	ALT_TypeName_SEP__sym

%start Types

%%

Types :
  includes1
  OPTMORE_EnumType
  OPTMORE_PointerType
  OPTMORE_subtypedef
  includes2
  OPTMORE_subtypedef
  OPTMORE_BindType
  RootDecl
  OPTMORE_StructType
  { $$ = Create_Types_Types(make_post_src_info(@1.first_line, @9.last_line), $2, $3, $4, $5, $6, $7, $8.f1, $8.f2, $9);
    Decorate_Types($$);
  }
;

includes1 :
  hashincludespacelessthanstdargdothgreaterthansym
  hashincludespacelessthanstddefdothgreaterthansym
  hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym
  /* No type */
  {
  }
;

includes2 :
  hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym
  hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym
  hashincludespacelessthanfrontslashSymTabdothgreaterthansym
  OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym
  hashincludespacebackslashdoublequotesym
  Identsym
  underscoredefsdothbackslashdoublequotesym
  OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym
  { $$ = Create_Types_includes2(make_post_src_info(@1.first_line, @8.last_line), $4, $6, $8);
  }
;

EnumType :
  typedefsym
  enumsym
  openchainsym
  Enums
  closechainsym
  Identsym
  semicolonsym
  externspacecharspacestarsym
  Identsym
  underscorenamesopenbrkclosebrksemicolonsym
  hashdefinespaceNUMunderscoresym
  Identsym
  Intsym
  { $$ = Create_Types_EnumType(make_post_src_info(@1.first_line, @13.last_line), $4, $6, $9, $12, $13);
  }
;

Enums :
  ALT_TypeName_SEP_commasym_NL
  /* No type */
  {
    $$ = $1;
  }
;

BindType :
  typedefspaceBindspaceBindunderscoresym
  Identsym
  semicolonsym
  typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym
  Identsym
  semicolonsym
  hashdefinespaceListunderscoreBindunderscoresym
  Identsym
  underscoredataopenparxcloseparsym
  openparBindunderscoresym
  Identsym
  closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym
  hashdefinespaceListunderscoreBindunderscoresym
  Identsym
  underscorenextopenparxcloseparsym
  openparListunderscoreBindunderscoresym
  Identsym
  closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym
  hashdefinespaceBindunderscoresym
  Identsym
  _kindsym
  Intsym
  { $$ = Create_Types_BindType(make_post_src_info(@1.first_line, @22.last_line), $2, $5, $8, $11, $14, $17, $20, $22);
  }
;

PointerType :
  hashifndefspaceDEFunderscoreTYPEunderscoresym
  Identsym
  hashdefinespaceDEFunderscoreTYPEunderscoresym
  Identsym
  typedefspacestructspacesunderscoresym
  Identsym
  starsym
  Identsym
  semicolonsym
  OPTMORE_subtypedef
  hashendifsym
  { $$ = Create_Types_PointerType(make_post_src_info(@1.first_line, @11.last_line), $2, $4, $6, $8, $10);
  }
;

subtypedef :
  typedefspacesym
  Identsym
  Identsym
  semicolonsym
  { $$ = Create_Types_subtypedef(make_post_src_info(@1.first_line, @4.last_line), $2, $3);
  }
;

RootDecl :
  externsym
  Identsym
  Identsym
  underscorerootsemicolonsym
  /* No type */
  {
    $$.f1 = $2;
    $$.f2 = $3;
  }
;

StructType :
  hashifndefspaceDEFunderscoreSTRUCTunderscoresym
  Identsym
  hashdefinespaceDEFunderscoreSTRUCTunderscoresym
  Identsym
  struct_type
  OPTMORE_macro
  OPTMORE_CreateFunction
  hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym
  Identsym
  spacestarslashsym
  { $$ = Create_Types_StructType(make_post_src_info(@1.first_line, @10.last_line), $2, $4, $5, $6, $7, $9);
  }
;

struct_type :
  structsym
  s_sym
  Identsym
  openchainsym
  OPT_Identsym__USER_FIELDSsym
  OPTMORE_field
  OPT_sub_union
  OPTMORE_field
  closechainsym
  OPT_Identsym
  semicolonsym
  { $$ = Create_Types_struct_type(make_post_src_info(@1.first_line, @11.last_line), $3, $5, $6, $7, $8, $10);
  }
;

sub_union :
  unionspaceopenchainsym
  OPTMORE_struct_type
  closechainspacesubsemicolonsym
  /* No type */
  {
    $$ = $2;
  }
;

macro :
  hashdefinesym
  Identsym
  _sym
  Identsym
  openparunderscorepcloseparsym
  openparsym
  openparstarunderscorepcloseparsym
  OPTMORE_dotsubdotsym_Identsym
  dotsym
  Identsym
  closeparsym
  { $$ = Create_Types_plain_macro(make_post_src_info(@1.first_line, @11.last_line), $2, $4, $8, $10);
  }
;

macro :
  hashdefinesym
  Identsym
  _sym
  Identsym
  openparunderscorepcloseparsym
  openparsym
  Identsym
  underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym
  OPTMORE_dotsubdotsym_Identsym
  dotsym
  Identsym
  closeparsym
  { $$ = Create_Types_access_macro(make_post_src_info(@1.first_line, @12.last_line), $2, $4, $7, $9, $11);
  }
;

field :
  TypeNames
  Identsym
  semicolonsym
  { $$ = Create_Types_field(make_post_src_info(@1.first_line, @3.last_line), $1, $2);
  }
;

TypeName :
  Identsym
  { $$ = Create_Types_TypeName(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

CreateFunction :
  CREATEsym
  OPTMORE_field
  { $$ = Create_Types_CreateFunction(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

TypeNames :
  ALT_TypeName_SEP__sym
  /* No type */
  {
    $$ = $1;
  }
;

/**** Extra rules ****/

OPTMORE_EnumType :
  {
    $$ = NULL;
  }
;

OPTMORE_EnumType :
  EnumType
  OPTMORE_EnumType
  {
    $$ = Create_List_Types_EnumType($1, $2);
  }
;

OPTMORE_PointerType :
  {
    $$ = NULL;
  }
;

OPTMORE_PointerType :
  PointerType
  OPTMORE_PointerType
  {
    $$ = Create_List_Types_PointerType($1, $2);
  }
;

OPTMORE_subtypedef :
  {
    $$ = NULL;
  }
;

OPTMORE_subtypedef :
  subtypedef
  OPTMORE_subtypedef
  {
    $$ = Create_List_Types_subtypedef($1, $2);
  }
;

OPTMORE_BindType :
  {
    $$ = NULL;
  }
;

OPTMORE_BindType :
  BindType
  OPTMORE_BindType
  {
    $$ = Create_List_Types_BindType($1, $2);
  }
;

OPTMORE_StructType :
  {
    $$ = NULL;
  }
;

OPTMORE_StructType :
  StructType
  OPTMORE_StructType
  {
    $$ = Create_List_Types_StructType($1, $2);
  }
;

OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym :
  {
    $$ = NULL;
  }
;

OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym :
  hashincludespacebackslashdoublequotesym
  Identsym
  underscoreparsedothbackslashdoublequotesym
  {
    $$ = $2;
  }
;

OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym :
  {
    $$ = NULL;
  }
;

OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym :
  hashincludespacebackslashdoublequotesym
  Identsym
  dothbackslashdoublequotesym
  OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym
  {
    $$ = Create_List_Ident($2, $4);
  }
;

ALT_TypeName_SEP_commasym_NL :
  TypeName
  {
    $$ = Create_List_Types_TypeName($1, NULL);
  }
;

ALT_TypeName_SEP_commasym_NL :
  TypeName
  commasym
  ALT_TypeName_SEP_commasym_NL
  {
    $$ = Create_List_Types_TypeName($1, $3);
  }
;

OPTMORE_macro :
  {
    $$ = NULL;
  }
;

OPTMORE_macro :
  macro
  OPTMORE_macro
  {
    $$ = Create_List_Types_macro($1, $2);
  }
;

OPTMORE_CreateFunction :
  {
    $$ = NULL;
  }
;

OPTMORE_CreateFunction :
  CreateFunction
  OPTMORE_CreateFunction
  {
    $$ = Create_List_Types_CreateFunction($1, $2);
  }
;

OPT_Identsym__USER_FIELDSsym :
  {
    $$ = NULL;
  }
;

OPT_Identsym__USER_FIELDSsym :
  Identsym
  _USER_FIELDSsym
  {
    $$ = $1;
  }
;

OPTMORE_field :
  {
    $$ = NULL;
  }
;

OPTMORE_field :
  field
  OPTMORE_field
  {
    $$ = Create_List_Types_field($1, $2);
  }
;

OPT_sub_union :
  {
    $$ = NULL;
  }
;

OPT_sub_union :
  sub_union
  {
    $$ = $1;
  }
;

OPT_Identsym :
  {
    $$ = NULL;
  }
;

OPT_Identsym :
  Identsym
  {
    $$ = $1;
  }
;

OPTMORE_struct_type :
  {
    $$ = NULL;
  }
;

OPTMORE_struct_type :
  struct_type
  OPTMORE_struct_type
  {
    $$ = Create_List_Types_struct_type($1, $2);
  }
;

OPTMORE_dotsubdotsym_Identsym :
  {
    $$ = NULL;
  }
;

OPTMORE_dotsubdotsym_Identsym :
  dotsubdotsym
  Identsym
  OPTMORE_dotsubdotsym_Identsym
  {
    $$ = Create_List_Ident($2, $3);
  }
;

ALT_TypeName_SEP__sym :
  TypeName
  {
    $$ = Create_List_Types_TypeName($1, NULL);
  }
;

ALT_TypeName_SEP__sym :
  TypeName
  _sym
  ALT_TypeName_SEP__sym
  {
    $$ = Create_List_Types_TypeName($1, $3);
  }
;

Types :
  hole_Types
  { $$ = (Types_Types)Get_sub_tree (); }
;

Types :
  start_Types
  Types
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

includes2 :
  hole_includes2
  { $$ = (Types_includes2)Get_sub_tree (); }
;

Types :
  start_includes2
  includes2
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

EnumType :
  hole_EnumType
  { $$ = (Types_EnumType)Get_sub_tree (); }
;

Types :
  start_EnumType
  EnumType
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

Enums :
  hole_Enums
  { $$ = (List_Types_TypeName)Get_sub_tree (); }
;

Types :
  start_Enums
  Enums
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

BindType :
  hole_BindType
  { $$ = (Types_BindType)Get_sub_tree (); }
;

Types :
  start_BindType
  BindType
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

PointerType :
  hole_PointerType
  { $$ = (Types_PointerType)Get_sub_tree (); }
;

Types :
  start_PointerType
  PointerType
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

subtypedef :
  hole_subtypedef
  { $$ = (Types_subtypedef)Get_sub_tree (); }
;

Types :
  start_subtypedef
  subtypedef
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

StructType :
  hole_StructType
  { $$ = (Types_StructType)Get_sub_tree (); }
;

Types :
  start_StructType
  StructType
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

struct_type :
  hole_struct_type
  { $$ = (Types_struct_type)Get_sub_tree (); }
;

Types :
  start_struct_type
  struct_type
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

sub_union :
  hole_sub_union
  { $$ = (List_Types_struct_type)Get_sub_tree (); }
;

Types :
  start_sub_union
  sub_union
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

macro :
  hole_macro
  { $$ = (Types_macro)Get_sub_tree (); }
;

Types :
  start_macro
  macro
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

field :
  hole_field
  { $$ = (Types_field)Get_sub_tree (); }
;

Types :
  start_field
  field
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

TypeName :
  hole_TypeName
  { $$ = (Types_TypeName)Get_sub_tree (); }
;

Types :
  start_TypeName
  TypeName
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

CreateFunction :
  hole_CreateFunction
  { $$ = (Types_CreateFunction)Get_sub_tree (); }
;

Types :
  start_CreateFunction
  CreateFunction
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

TypeNames :
  hole_TypeNames
  { $$ = (List_Types_TypeName)Get_sub_tree (); }
;

Types :
  start_TypeNames
  TypeNames
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_EnumType :
  hole_OPTMORE_EnumType
  { $$ = (List_Types_EnumType)Get_sub_tree (); }
;

Types :
  start_OPTMORE_EnumType
  OPTMORE_EnumType
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_PointerType :
  hole_OPTMORE_PointerType
  { $$ = (List_Types_PointerType)Get_sub_tree (); }
;

Types :
  start_OPTMORE_PointerType
  OPTMORE_PointerType
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_subtypedef :
  hole_OPTMORE_subtypedef
  { $$ = (List_Types_subtypedef)Get_sub_tree (); }
;

Types :
  start_OPTMORE_subtypedef
  OPTMORE_subtypedef
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_BindType :
  hole_OPTMORE_BindType
  { $$ = (List_Types_BindType)Get_sub_tree (); }
;

Types :
  start_OPTMORE_BindType
  OPTMORE_BindType
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_StructType :
  hole_OPTMORE_StructType
  { $$ = (List_Types_StructType)Get_sub_tree (); }
;

Types :
  start_OPTMORE_StructType
  OPTMORE_StructType
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym :
  hole_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym
  { $$ = (Ident)Get_sub_tree (); }
;

Types :
  start_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym
  OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym :
  hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym
  { $$ = (List_Ident)Get_sub_tree (); }
;

Types :
  start_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym
  OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

ALT_TypeName_SEP_commasym_NL :
  hole_ALT_TypeName_SEP_commasym_NL
  { $$ = (List_Types_TypeName)Get_sub_tree (); }
;

Types :
  start_ALT_TypeName_SEP_commasym_NL
  ALT_TypeName_SEP_commasym_NL
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_macro :
  hole_OPTMORE_macro
  { $$ = (List_Types_macro)Get_sub_tree (); }
;

Types :
  start_OPTMORE_macro
  OPTMORE_macro
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_CreateFunction :
  hole_OPTMORE_CreateFunction
  { $$ = (List_Types_CreateFunction)Get_sub_tree (); }
;

Types :
  start_OPTMORE_CreateFunction
  OPTMORE_CreateFunction
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPT_Identsym__USER_FIELDSsym :
  hole_OPT_Identsym__USER_FIELDSsym
  { $$ = (Ident)Get_sub_tree (); }
;

Types :
  start_OPT_Identsym__USER_FIELDSsym
  OPT_Identsym__USER_FIELDSsym
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_field :
  hole_OPTMORE_field
  { $$ = (List_Types_field)Get_sub_tree (); }
;

Types :
  start_OPTMORE_field
  OPTMORE_field
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPT_sub_union :
  hole_OPT_sub_union
  { $$ = (List_Types_struct_type)Get_sub_tree (); }
;

Types :
  start_OPT_sub_union
  OPT_sub_union
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPT_Identsym :
  hole_OPT_Identsym
  { $$ = (Ident)Get_sub_tree (); }
;

Types :
  start_OPT_Identsym
  OPT_Identsym
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_struct_type :
  hole_OPTMORE_struct_type
  { $$ = (List_Types_struct_type)Get_sub_tree (); }
;

Types :
  start_OPTMORE_struct_type
  OPTMORE_struct_type
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_dotsubdotsym_Identsym :
  hole_OPTMORE_dotsubdotsym_Identsym
  { $$ = (List_Ident)Get_sub_tree (); }
;

Types :
  start_OPTMORE_dotsubdotsym_Identsym
  OPTMORE_dotsubdotsym_Identsym
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

ALT_TypeName_SEP__sym :
  hole_ALT_TypeName_SEP__sym
  { $$ = (List_Types_TypeName)Get_sub_tree (); }
;

Types :
  start_ALT_TypeName_SEP__sym
  ALT_TypeName_SEP__sym
  { Types_multi_action ((void*)$2); YYACCEPT; }
;

