%{
#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "doggy.h"

extern int input_line_nr;

struct yy_buffer_state *doggy_dummy_state (void);
struct yy_buffer_state *doggy_scanner_state (void);
%}

%token NONSENSE
%token TYPESsym
%token ATTRIBUTESsym
%token openchainsym
%token OPRsym
%token commasym
%token closechainsym
%token MACHINEsym
%token DESCRIPTIONsym
%token openparsym
%token closeparsym
%token starsym
%token openbrksym
%token minussym
%token dotdotsym
%token STEPsym
%token closebrksym
%token verticalbarsym
%token colonsym
%token COMMUTATIVEsym
%token SUPPORTSsym
%token EXTERNALsym
%token externsym
%token semicolonsym
%token FUNCTIONSsym
%token equalssym
%token ANYsym
%token NULLsym
%token _sym
%token candsym
%token corsym
%token hatsym
%token eqsym
%token neqsym
%token lesym
%token gesym
%token lessthansym
%token greaterthansym
%token shlsym
%token shrsym
%token slashsym
%token percentsym
%token ampersandsym
%token plussym
%token openquotesym
%token CONSsym
%token IFsym
%token THENsym
%token ELSIFsym
%token ELSEsym
%token FIsym
%token exclaimsym
%token tildasym
%token arrowsym
%token WHEREsym
%token RULESsym
%token comment1sym
%token comment2sym
%token Boolsym
%token Identsym
%token Intsym
%token Stringsym

%union {
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
}

%type <TYPESsym_type>	TYPESsym
%type <ATTRIBUTESsym_type>	ATTRIBUTESsym
%type <openchainsym_type>	openchainsym
%type <OPRsym_type>	OPRsym
%type <commasym_type>	commasym
%type <closechainsym_type>	closechainsym
%type <MACHINEsym_type>	MACHINEsym
%type <DESCRIPTIONsym_type>	DESCRIPTIONsym
%type <openparsym_type>	openparsym
%type <closeparsym_type>	closeparsym
%type <starsym_type>	starsym
%type <openbrksym_type>	openbrksym
%type <minussym_type>	minussym
%type <dotdotsym_type>	dotdotsym
%type <STEPsym_type>	STEPsym
%type <closebrksym_type>	closebrksym
%type <verticalbarsym_type>	verticalbarsym
%type <colonsym_type>	colonsym
%type <COMMUTATIVEsym_type>	COMMUTATIVEsym
%type <SUPPORTSsym_type>	SUPPORTSsym
%type <EXTERNALsym_type>	EXTERNALsym
%type <externsym_type>	externsym
%type <semicolonsym_type>	semicolonsym
%type <FUNCTIONSsym_type>	FUNCTIONSsym
%type <equalssym_type>	equalssym
%type <ANYsym_type>	ANYsym
%type <NULLsym_type>	NULLsym
%type <_sym_type>	_sym
%type <candsym_type>	candsym
%type <corsym_type>	corsym
%type <hatsym_type>	hatsym
%type <eqsym_type>	eqsym
%type <neqsym_type>	neqsym
%type <lesym_type>	lesym
%type <gesym_type>	gesym
%type <lessthansym_type>	lessthansym
%type <greaterthansym_type>	greaterthansym
%type <shlsym_type>	shlsym
%type <shrsym_type>	shrsym
%type <slashsym_type>	slashsym
%type <percentsym_type>	percentsym
%type <ampersandsym_type>	ampersandsym
%type <plussym_type>	plussym
%type <openquotesym_type>	openquotesym
%type <CONSsym_type>	CONSsym
%type <IFsym_type>	IFsym
%type <THENsym_type>	THENsym
%type <ELSIFsym_type>	ELSIFsym
%type <ELSEsym_type>	ELSEsym
%type <FIsym_type>	FIsym
%type <exclaimsym_type>	exclaimsym
%type <tildasym_type>	tildasym
%type <arrowsym_type>	arrowsym
%type <WHEREsym_type>	WHEREsym
%type <RULESsym_type>	RULESsym
%type <comment1sym_type>	comment1sym
%type <comment2sym_type>	comment2sym
%type <Boolsym_type>	Boolsym
%type <Identsym_type>	Identsym
%type <Intsym_type>	Intsym
%type <Stringsym_type>	Stringsym
%type <doggy_type>	doggy
%type <Typedefs_type>	Typedefs
%type <Typedef_type>	Typedef
%type <externals_type>	externals
%type <FunctionDef_type>	FunctionDef
%type <machine_description_type>	machine_description
%type <Operation_def_type>	Operation_def
%type <Attributes_type>	Attributes
%type <Attrs_type>	Attrs
%type <Attribute_type>	Attribute
%type <Section_type>	Section
%type <Rules_type>	Rules
%type <Rule_type>	Rule
%type <Lhs_type>	Lhs
%type <Funcs_type>	Funcs
%type <Func_type>	Func
%type <FuncRules_type>	FuncRules
%type <FuncRule_type>	FuncRule
%type <Arguments_type>	Arguments
%type <Argument_type>	Argument
%type <ArgPat_type>	ArgPat
%type <ArgPat2_type>	ArgPat2
%type <PatArg1_type>	PatArg1
%type <ParArg_type>	ParArg
%type <SetArg_type>	SetArg
%type <Pattern_type>	Pattern
%type <UnTypedPattern_type>	UnTypedPattern
%type <ConsPattern_type>	ConsPattern
%type <SimplePattern_type>	SimplePattern
%type <DefPattern_type>	DefPattern
%type <IdentPattern_type>	IdentPattern
%type <IdentPatterns_type>	IdentPatterns
%type <SingleDefPattern_type>	SingleDefPattern
%type <IdParPattern_type>	IdParPattern
%type <BinPattern_type>	BinPattern
%type <BasicPattern_type>	BasicPattern
%type <ParPattern_type>	ParPattern
%type <Rhs_type>	Rhs
%type <Guard_type>	Guard
%type <ExprSeq_type>	ExprSeq
%type <Wherepart_type>	Wherepart
%type <Applied_operation_type>	Applied_operation
%type <OpSet_type>	OpSet
%type <Applied_formals_type>	Applied_formals
%type <Applied_formal_type>	Applied_formal
%type <Expr_type>	Expr
%type <IdOpExpr_type>	IdOpExpr
%type <ConsExpr_type>	ConsExpr
%type <cons_type>	cons
%type <SimpleExpr_type>	SimpleExpr
%type <Condition_type>	Condition
%type <Constant_type>	Constant
%type <Definition_type>	Definition
%type <Operator_type>	Operator
%type <IdOp_type>	IdOp
%type <MonOp_type>	MonOp
%type <Type_type>	Type
%type <BasicType_type>	BasicType
%type <Property_type>	Property
%type <ArgTypes_type>	ArgTypes
%type <Patterns_type>	Patterns
%type <Exprs_type>	Exprs
%type <Types_type>	Types
%type <Num_type>	Num
%type <OPT_Typedefs_type>	OPT_Typedefs
%type <OPT_machine_description_type>	OPT_machine_description
%type <OPT_externals_type>	OPT_externals
%type <OPTMORE_Section_type>	OPTMORE_Section
%type <OPTMORE_Typedef_type>	OPTMORE_Typedef
%type <OPT_Stringsym_Stringsym_Stringsym_type>	OPT_Stringsym_Stringsym_Stringsym
%type <OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_type>	OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym
%type <OPTMORE_FunctionDef_type>	OPTMORE_FunctionDef
%type <OPTMORE_Operation_def_type>	OPTMORE_Operation_def
%type <OPT_SUPPORTSsym_OPTMORE_Applied_formal_type>	OPT_SUPPORTSsym_OPTMORE_Applied_formal
%type <OPTMORE_Applied_formal_type>	OPTMORE_Applied_formal
%type <OPT_Types_type>	OPT_Types
%type <OPT_colonsym_Type_type>	OPT_colonsym_Type
%type <OPTMORE_Property_type>	OPTMORE_Property
%type <OPT_Attrs_OPT_commasym_Attributes_type>	OPT_Attrs_OPT_commasym_Attributes
%type <OPT_commasym_Attributes_type>	OPT_commasym_Attributes
%type <MORE_Attribute_type>	MORE_Attribute
%type <OPT_colonsym_Identsym_type>	OPT_colonsym_Identsym
%type <OPTMORE_Rule_type>	OPTMORE_Rule
%type <OPTMORE_Func_type>	OPTMORE_Func
%type <OPT_externsym_type>	OPT_externsym
%type <ALT_FuncRule_SEP_commasym_type>	ALT_FuncRule_SEP_commasym
%type <OPT_Arguments_type>	OPT_Arguments
%type <ALT_Argument_SEP_commasym_type>	ALT_Argument_SEP_commasym
%type <OPT_equalssym_UnTypedPattern_type>	OPT_equalssym_UnTypedPattern
%type <ALT_IdentPattern_SEP_commasym_type>	ALT_IdentPattern_SEP_commasym
%type <OPT_IdOp_SimplePattern_type>	OPT_IdOp_SimplePattern
%type <OPT_Patterns_type>	OPT_Patterns
%type <OPT_equalssym_SimpleExpr_type>	OPT_equalssym_SimpleExpr
%type <MORE_Guard_type>	MORE_Guard
%type <OPT_Wherepart_type>	OPT_Wherepart
%type <OPT_verticalbarsym_Condition_type>	OPT_verticalbarsym_Condition
%type <OPTMORE_Definition_type>	OPTMORE_Definition
%type <ALT_Applied_formal_SEP_commasym_type>	ALT_Applied_formal_SEP_commasym
%type <ALT_SimpleExpr_SEP_Operator_type>	ALT_SimpleExpr_SEP_Operator
%type <OPTMORE_ELSIFsym_Condition_THENsym_Expr_type>	OPTMORE_ELSIFsym_Condition_THENsym_Expr
%type <OPT_Exprs_type>	OPT_Exprs
%type <ALT_BasicType_SEP_verticalbarsym_type>	ALT_BasicType_SEP_verticalbarsym
%type <OPT_ArgTypes_type>	OPT_ArgTypes
%type <OPT_STEPsym_Num_type>	OPT_STEPsym_Num
%type <ALT_Pattern_SEP_commasym_type>	ALT_Pattern_SEP_commasym
%type <ALT_Expr_SEP_commasym_type>	ALT_Expr_SEP_commasym
%type <ALT_Type_SEP_commasym_type>	ALT_Type_SEP_commasym
%type <OPT_minussym_type>	OPT_minussym

%start doggy

%%

doggy :
  OPT_Typedefs
  machine_description
  OPT_machine_description
  OPT_externals
  OPTMORE_Section
  { $$ = Create_doggy_doggy(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4, $5);
    Decorate_doggy($$);
  }
;

Typedefs :
  TYPESsym
  OPTMORE_Typedef
  /* No type */
  {
    $$ = $2;
  }
;

Typedef :
  Identsym
  OPT_Stringsym_Stringsym_Stringsym
  OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym
  { $$ = Create_doggy_Typedef(make_post_src_info(@1.first_line, @3.last_line), $1, $2.f1, $2.f2, $2.f3, $3);
  }
;

externals :
  EXTERNALsym
  OPTMORE_FunctionDef
  /* No type */
  {
    $$ = $2;
  }
;

FunctionDef :
  externsym
  Type
  Identsym
  ArgTypes
  semicolonsym
  { $$ = Create_doggy_ExtFunc(make_post_src_info(@1.first_line, @5.last_line), $2, $3, $4);
  }
;

FunctionDef :
  externsym
  Type
  Identsym
  semicolonsym
  { $$ = Create_doggy_ExtVar(make_post_src_info(@1.first_line, @4.last_line), $2, $3);
  }
;

machine_description :
  MACHINEsym
  DESCRIPTIONsym
  Identsym
  OPTMORE_Operation_def
  OPT_SUPPORTSsym_OPTMORE_Applied_formal
  { $$ = Create_doggy_machine_description(make_post_src_info(@1.first_line, @5.last_line), $3, $4, $5);
  }
;

Operation_def :
  Identsym
  openparsym
  OPT_Types
  closeparsym
  OPT_colonsym_Type
  Identsym
  OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym
  OPTMORE_Property
  { $$ = Create_doggy_Operation_def(make_post_src_info(@1.first_line, @8.last_line), $1, $3, $5, $6, $7, $8);
  }
;

Attributes :
  OPT_Attrs_OPT_commasym_Attributes
  { $$ = Create_doggy_Attributes(make_post_src_info(@1.first_line, @1.last_line), $1.f1, $1.f2);
  }
;

Attrs :
  MORE_Attribute
  /* No type */
  {
    $$ = $1;
  }
;

Attribute :
  Identsym
  { $$ = Create_doggy_IdAttr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Attribute :
  OPRsym
  { $$ = Create_doggy_OpAttr(make_post_src_info(@1.first_line, @1.last_line));
  }
;

Attribute :
  Intsym
  { $$ = Create_doggy_IntAttr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Section :
  Funcs
  { $$ = Create_doggy_FuncSection(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Section :
  Rules
  { $$ = Create_doggy_RuleSection(make_post_src_info(@1.first_line, @1.last_line), $1.f1, $1.f2);
  }
;

Rules :
  RULESsym
  OPT_colonsym_Identsym
  OPTMORE_Rule
  /* No type */
  {
    $$.f1 = $2;
    $$.f2 = $3;
  }
;

Rule :
  Lhs
  Rhs
  semicolonsym
  { $$ = Create_doggy_Rule(make_post_src_info(@1.first_line, @3.last_line), $1, $2);
  }
;

Lhs :
  Identsym
  colonsym
  UnTypedPattern
  { $$ = Create_doggy_LabeledLhs(make_post_src_info(@1.first_line, @3.last_line), $1, $3);
  }
;

Lhs :
  UnTypedPattern
  { $$ = Create_doggy_UnLabeledLhs(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Funcs :
  FUNCTIONSsym
  OPTMORE_Func
  /* No type */
  {
    $$ = $2;
  }
;

Func :
  OPT_externsym
  Type
  Identsym
  FuncRules
  semicolonsym
  { $$ = Create_doggy_Func(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4);
  }
;

FuncRules :
  ALT_FuncRule_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

FuncRule :
  openparsym
  OPT_Arguments
  closeparsym
  Rhs
  { $$ = Create_doggy_FuncRule(make_post_src_info(@1.first_line, @4.last_line), $2, $4);
  }
;

Arguments :
  ALT_Argument_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

Argument :
  Type
  Identsym
  ArgPat2
  { $$ = Create_doggy_TypedArg(make_post_src_info(@1.first_line, @3.last_line), $1, $2, $3);
  }
;

Argument :
  Identsym
  ArgPat2
  { $$ = Create_doggy_UnTypedArg(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

ArgPat :
  Pattern
  { $$ = Create_doggy_PatArg(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

ArgPat2 :
  PatArg1
  {
    $$ = $1;
  }
;

ArgPat2 :
  ParArg
  {
    $$ = $1;
  }
;

ArgPat2 :
  SetArg
  {
    $$ = $1;
  }
;

PatArg1 :
  OPT_equalssym_UnTypedPattern
  /* No type */
  { $$ = PatArg1(make_post_src_info(@1.first_line, @1.last_line), $1); }
;

ParArg :
  ParPattern
  /* No type */
  { $$ = ParArg(make_post_src_info(@1.first_line, @1.last_line), $1); }
;

SetArg :
  equalssym
  OpSet
  { $$ = Create_doggy_SetArg(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

Pattern :
  UnTypedPattern
  {
    $$ = $1;
  }
;

Pattern :
  BasicType
  UnTypedPattern
  { $$ = Create_doggy_TypedPattern(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

UnTypedPattern :
  SimplePattern
  {
    $$ = $1;
  }
;

UnTypedPattern :
  ConsPattern
  {
    $$ = $1;
  }
;

ConsPattern :
  SimplePattern
  cons
  UnTypedPattern
  { $$ = Create_doggy_ConsPattern(make_post_src_info(@1.first_line, @3.last_line), $1, $3);
  }
;

SimplePattern :
  IdentPattern
  {
    $$ = $1;
  }
;

SimplePattern :
  SingleDefPattern
  {
    $$ = $1;
  }
;

SimplePattern :
  DefPattern
  {
    $$ = $1;
  }
;

SimplePattern :
  IdParPattern
  {
    $$ = $1;
  }
;

SimplePattern :
  BinPattern
  {
    $$ = $1;
  }
;

DefPattern :
  openchainsym
  IdentPatterns
  closechainsym
  equalssym
  BinPattern
  { $$ = Create_doggy_DefPattern(make_post_src_info(@1.first_line, @5.last_line), $2, $5);
  }
;

IdentPattern :
  Identsym
  { $$ = Create_doggy_IdentPattern(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

IdentPatterns :
  ALT_IdentPattern_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

SingleDefPattern :
  Identsym
  equalssym
  BinPattern
  /* No type */
  { $$ = SingleDefPattern(make_post_src_info(@1.first_line, @3.last_line), $1, $3); }
;

IdParPattern :
  Identsym
  ParPattern
  /* No type */
  { $$ = IdParPattern(make_post_src_info(@1.first_line, @2.last_line), $1, $2); }
;

BinPattern :
  BasicPattern
  OPT_IdOp_SimplePattern
  /* No type */
  { $$ = BinPattern(make_post_src_info(@1.first_line, @2.last_line), $1, $2.f1, $2.f2); }
;

BasicPattern :
  Applied_operation
  openparsym
  OPT_Patterns
  closeparsym
  { $$ = Create_doggy_OpPattern(make_post_src_info(@1.first_line, @4.last_line), $1, $3);
  }
;

BasicPattern :
  Intsym
  { $$ = Create_doggy_ConstPattern(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

BasicPattern :
  NULLsym
  { $$ = Create_doggy_NullPattern(make_post_src_info(@1.first_line, @1.last_line));
  }
;

BasicPattern :
  _sym
  OPT_equalssym_SimpleExpr
  { $$ = Create_doggy_DontCarePattern(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

ParPattern :
  equalssym
  openparsym
  Pattern
  closeparsym
  /* No type */
  { $$ = ParPattern(make_post_src_info(@1.first_line, @4.last_line), $3); }
;

Rhs :
  MORE_Guard
  { $$ = Create_doggy_PlainRhs(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Rhs :
  openchainsym
  Rhs
  closechainsym
  OPT_Wherepart
  { $$ = Create_doggy_BlockRhs(make_post_src_info(@1.first_line, @4.last_line), $2, $4);
  }
;

Guard :
  verticalbarsym
  Condition
  openchainsym
  Rhs
  closechainsym
  OPT_Wherepart
  { $$ = Create_doggy_RhsGuard(make_post_src_info(@1.first_line, @6.last_line), $2, $4, $6);
  }
;

Guard :
  OPT_verticalbarsym_Condition
  arrowsym
  ExprSeq
  OPT_Wherepart
  { $$ = Create_doggy_ExprGuard(make_post_src_info(@1.first_line, @4.last_line), $1, $3, $4);
  }
;

ExprSeq :
  Expr
  { $$ = Create_doggy_OneExpr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

ExprSeq :
  openchainsym
  Exprs
  closechainsym
  { $$ = Create_doggy_MoreExprs(make_post_src_info(@1.first_line, @3.last_line), $2);
  }
;

Wherepart :
  WHEREsym
  OPTMORE_Definition
  { $$ = Create_doggy_Wherepart(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

Applied_operation :
  ANYsym
  { $$ = Create_doggy_AnyOp(make_post_src_info(@1.first_line, @1.last_line));
  }
;

Applied_operation :
  OpSet
  {
    $$ = $1;
  }
;

Applied_operation :
  Applied_formal
  { $$ = Create_doggy_AppliedOp(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

OpSet :
  openbrksym
  Applied_formals
  closebrksym
  { $$ = Create_doggy_OpSet(make_post_src_info(@1.first_line, @3.last_line), $2);
  }
;

Applied_formals :
  ALT_Applied_formal_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

Applied_formal :
  Identsym
  { $$ = Create_doggy_Applied_formal(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Expr :
  ALT_SimpleExpr_SEP_Operator
  { $$ = Create_doggy_BinExpr(make_post_src_info(@1.first_line, @1.last_line), $1.f1, $1.f2);
  }
;

Expr :
  IdOpExpr
  {
    $$ = $1;
  }
;

Expr :
  ConsExpr
  {
    $$ = $1;
  }
;

IdOpExpr :
  SimpleExpr
  IdOp
  Expr
  /* No type */
  { $$ = IdOpExpr(make_post_src_info(@1.first_line, @3.last_line), $1, $2, $3); }
;

ConsExpr :
  SimpleExpr
  cons
  Expr
  { $$ = Create_doggy_ConsExpr(make_post_src_info(@1.first_line, @3.last_line), $1, $3);
  }
;

cons :
  CONSsym
  /* No type */
  {
  }
;

SimpleExpr :
  Identsym
  { $$ = Create_doggy_IdentExpr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

SimpleExpr :
  IFsym
  Condition
  THENsym
  Expr
  OPTMORE_ELSIFsym_Condition_THENsym_Expr
  ELSEsym
  Expr
  FIsym
  { $$ = Create_doggy_IfExpr(make_post_src_info(@1.first_line, @8.last_line), $2, $4, $5.f1, $5.f2, $7);
  }
;

SimpleExpr :
  Constant
  { $$ = Create_doggy_ConstExpr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

SimpleExpr :
  Identsym
  openparsym
  OPT_Exprs
  closeparsym
  { $$ = Create_doggy_Operation(make_post_src_info(@1.first_line, @4.last_line), $1, $3);
  }
;

SimpleExpr :
  openparsym
  Expr
  closeparsym
  { $$ = Create_doggy_ParExpr(make_post_src_info(@1.first_line, @3.last_line), $2);
  }
;

SimpleExpr :
  MonOp
  SimpleExpr
  { $$ = Create_doggy_MonExpr(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

Condition :
  Expr
  /* No type */
  {
    $$ = $1;
  }
;

Constant :
  Intsym
  { $$ = Create_doggy_IntConst(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Constant :
  Boolsym
  { $$ = Create_doggy_BoolConst(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Constant :
  Stringsym
  { $$ = Create_doggy_StringConst(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Constant :
  NULLsym
  { $$ = Create_doggy_NullConst(make_post_src_info(@1.first_line, @1.last_line));
  }
;

Definition :
  Type
  Identsym
  equalssym
  Expr
  { $$ = Create_doggy_Definition(make_post_src_info(@1.first_line, @4.last_line), $1, $2, $4);
  }
;

Operator :
  candsym
  /* Enum type */
  { $$ = doggy_CandOp; }
;

Operator :
  corsym
  /* Enum type */
  { $$ = doggy_CorOp; }
;

Operator :
  hatsym
  /* Enum type */
  { $$ = doggy_XorOp; }
;

Operator :
  eqsym
  /* Enum type */
  { $$ = doggy_EqOp; }
;

Operator :
  neqsym
  /* Enum type */
  { $$ = doggy_NeqOp; }
;

Operator :
  lesym
  /* Enum type */
  { $$ = doggy_LEOp; }
;

Operator :
  gesym
  /* Enum type */
  { $$ = doggy_GEOp; }
;

Operator :
  lessthansym
  /* Enum type */
  { $$ = doggy_LTOp; }
;

Operator :
  greaterthansym
  /* Enum type */
  { $$ = doggy_GTOp; }
;

Operator :
  shlsym
  /* Enum type */
  { $$ = doggy_SLOp; }
;

Operator :
  shrsym
  /* Enum type */
  { $$ = doggy_SROp; }
;

Operator :
  slashsym
  /* Enum type */
  { $$ = doggy_DivOp; }
;

Operator :
  percentsym
  /* Enum type */
  { $$ = doggy_ModOp; }
;

Operator :
  starsym
  /* Enum type */
  { $$ = doggy_MulOp; }
;

Operator :
  ampersandsym
  /* Enum type */
  { $$ = doggy_AndOp; }
;

Operator :
  plussym
  /* Enum type */
  { $$ = doggy_AddOp; }
;

Operator :
  minussym
  /* Enum type */
  { $$ = doggy_SubOp; }
;

IdOp :
  openquotesym
  Identsym
  /* No type */
  {
    $$ = $2;
  }
;

MonOp :
  exclaimsym
  /* Enum type */
  { $$ = doggy_NotOp; }
;

MonOp :
  tildasym
  /* Enum type */
  { $$ = doggy_NegOp; }
;

MonOp :
  ampersandsym
  /* Enum type */
  { $$ = doggy_AddrOp; }
;

MonOp :
  starsym
  /* Enum type */
  { $$ = doggy_DerefOp; }
;

MonOp :
  plussym
  /* Enum type */
  { $$ = doggy_PlusOp; }
;

MonOp :
  minussym
  /* Enum type */
  { $$ = doggy_MinOp; }
;

Type :
  ALT_BasicType_SEP_verticalbarsym
  { $$ = Create_doggy_EdgeType(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Type :
  openchainsym
  OPT_Types
  closechainsym
  { $$ = Create_doggy_TupleType(make_post_src_info(@1.first_line, @3.last_line), $2);
  }
;

BasicType :
  Identsym
  { $$ = Create_doggy_IdentType(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

BasicType :
  OPRsym
  OPT_ArgTypes
  { $$ = Create_doggy_OprType(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

BasicType :
  BasicType
  starsym
  { $$ = Create_doggy_PointerType(make_post_src_info(@1.first_line, @2.last_line), $1);
  }
;

BasicType :
  openbrksym
  Num
  dotdotsym
  Num
  OPT_STEPsym_Num
  closebrksym
  { $$ = Create_doggy_RangeType(make_post_src_info(@1.first_line, @6.last_line), $2, $4, $5);
  }
;

BasicType :
  openbrksym
  Identsym
  openparsym
  closeparsym
  closebrksym
  { $$ = Create_doggy_FRangeType(make_post_src_info(@1.first_line, @5.last_line), $2);
  }
;

Property :
  COMMUTATIVEsym
  /* Enum type */
  { $$ = FALSE; }
;

ArgTypes :
  openparsym
  OPT_Types
  closeparsym
  /* No type */
  {
    $$ = $2;
  }
;

Patterns :
  ALT_Pattern_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

Exprs :
  ALT_Expr_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

Types :
  ALT_Type_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

Num :
  OPT_minussym
  Intsym
  { $$ = Create_doggy_Num(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

/**** Extra rules ****/

OPT_Typedefs :
  {
    $$ = NULL;
  }
;

OPT_Typedefs :
  Typedefs
  {
    $$ = $1;
  }
;

OPT_machine_description :
  {
    $$ = NULL;
  }
;

OPT_machine_description :
  machine_description
  {
    $$ = $1;
  }
;

OPT_externals :
  {
    $$ = NULL;
  }
;

OPT_externals :
  externals
  {
    $$ = $1;
  }
;

OPTMORE_Section :
  {
    $$ = NULL;
  }
;

OPTMORE_Section :
  Section
  OPTMORE_Section
  {
    $$ = Create_List_doggy_Section($1, $2);
  }
;

OPTMORE_Typedef :
  {
    $$ = NULL;
  }
;

OPTMORE_Typedef :
  Typedef
  OPTMORE_Typedef
  {
    $$ = Create_List_doggy_Typedef($1, $2);
  }
;

OPT_Stringsym_Stringsym_Stringsym :
  {
    $$.f1 = NULL;
    $$.f2 = NULL;
    $$.f3 = NULL;
  }
;

OPT_Stringsym_Stringsym_Stringsym :
  Stringsym
  Stringsym
  Stringsym
  {
    $$.f1 = $1;
    $$.f2 = $2;
    $$.f3 = $3;
  }
;

OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym :
  {
    $$ = NULL;
  }
;

OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym :
  ATTRIBUTESsym
  openchainsym
  Attributes
  closechainsym
  {
    $$ = $3;
  }
;

OPTMORE_FunctionDef :
  {
    $$ = NULL;
  }
;

OPTMORE_FunctionDef :
  FunctionDef
  OPTMORE_FunctionDef
  {
    $$ = Create_List_doggy_FunctionDef($1, $2);
  }
;

OPTMORE_Operation_def :
  {
    $$ = NULL;
  }
;

OPTMORE_Operation_def :
  Operation_def
  OPTMORE_Operation_def
  {
    $$ = Create_List_doggy_Operation_def($1, $2);
  }
;

OPT_SUPPORTSsym_OPTMORE_Applied_formal :
  {
    $$ = NULL;
  }
;

OPT_SUPPORTSsym_OPTMORE_Applied_formal :
  SUPPORTSsym
  OPTMORE_Applied_formal
  {
    $$ = $2;
  }
;

OPTMORE_Applied_formal :
  {
    $$ = NULL;
  }
;

OPTMORE_Applied_formal :
  Applied_formal
  OPTMORE_Applied_formal
  {
    $$ = Create_List_doggy_Applied_formal($1, $2);
  }
;

OPT_Types :
  {
    $$ = NULL;
  }
;

OPT_Types :
  Types
  {
    $$ = $1;
  }
;

OPT_colonsym_Type :
  {
    $$ = NULL;
  }
;

OPT_colonsym_Type :
  colonsym
  Type
  {
    $$ = $2;
  }
;

OPTMORE_Property :
  {
    $$ = NULL;
  }
;

OPTMORE_Property :
  Property
  OPTMORE_Property
  {
    $$ = Create_List_doggy_Property($1, $2);
  }
;

OPT_Attrs_OPT_commasym_Attributes :
  {
    $$.f1 = NULL;
    $$.f2 = NULL;
  }
;

OPT_Attrs_OPT_commasym_Attributes :
  Attrs
  OPT_commasym_Attributes
  {
    $$.f1 = $1;
    $$.f2 = $2;
  }
;

OPT_commasym_Attributes :
  {
    $$ = NULL;
  }
;

OPT_commasym_Attributes :
  commasym
  Attributes
  {
    $$ = $2;
  }
;

MORE_Attribute :
  Attribute
  {
    $$ = Create_List_doggy_Attribute($1, NULL);
  }
;

MORE_Attribute :
  Attribute
  MORE_Attribute
  {
    $$ = Create_List_doggy_Attribute($1, $2);
  }
;

OPT_colonsym_Identsym :
  {
    $$ = NULL;
  }
;

OPT_colonsym_Identsym :
  colonsym
  Identsym
  {
    $$ = $2;
  }
;

OPTMORE_Rule :
  {
    $$ = NULL;
  }
;

OPTMORE_Rule :
  Rule
  OPTMORE_Rule
  {
    $$ = Create_List_doggy_Rule($1, $2);
  }
;

OPTMORE_Func :
  {
    $$ = NULL;
  }
;

OPTMORE_Func :
  Func
  OPTMORE_Func
  {
    $$ = Create_List_doggy_Func($1, $2);
  }
;

OPT_externsym :
  {
    $$ = FALSE;
  }
;

OPT_externsym :
  externsym
  {
    $$ = TRUE;
  }
;

ALT_FuncRule_SEP_commasym :
  FuncRule
  {
    $$ = Create_List_doggy_FuncRule($1, NULL);
  }
;

ALT_FuncRule_SEP_commasym :
  FuncRule
  commasym
  ALT_FuncRule_SEP_commasym
  {
    $$ = Create_List_doggy_FuncRule($1, $3);
  }
;

OPT_Arguments :
  {
    $$ = NULL;
  }
;

OPT_Arguments :
  Arguments
  {
    $$ = $1;
  }
;

ALT_Argument_SEP_commasym :
  Argument
  {
    $$ = Create_List_doggy_Argument($1, NULL);
  }
;

ALT_Argument_SEP_commasym :
  Argument
  commasym
  ALT_Argument_SEP_commasym
  {
    $$ = Create_List_doggy_Argument($1, $3);
  }
;

OPT_equalssym_UnTypedPattern :
  {
    $$ = NULL;
  }
;

OPT_equalssym_UnTypedPattern :
  equalssym
  UnTypedPattern
  {
    $$ = $2;
  }
;

ALT_IdentPattern_SEP_commasym :
  IdentPattern
  {
    $$ = Create_List_doggy_Pattern($1, NULL);
  }
;

ALT_IdentPattern_SEP_commasym :
  IdentPattern
  commasym
  ALT_IdentPattern_SEP_commasym
  {
    $$ = Create_List_doggy_Pattern($1, $3);
  }
;

OPT_IdOp_SimplePattern :
  {
    $$.f1 = NULL;
    $$.f2 = NULL;
  }
;

OPT_IdOp_SimplePattern :
  IdOp
  SimplePattern
  {
    $$.f1 = $1;
    $$.f2 = $2;
  }
;

OPT_Patterns :
  {
    $$ = NULL;
  }
;

OPT_Patterns :
  Patterns
  {
    $$ = $1;
  }
;

OPT_equalssym_SimpleExpr :
  {
    $$ = NULL;
  }
;

OPT_equalssym_SimpleExpr :
  equalssym
  SimpleExpr
  {
    $$ = $2;
  }
;

MORE_Guard :
  Guard
  {
    $$ = Create_List_doggy_Guard($1, NULL);
  }
;

MORE_Guard :
  Guard
  MORE_Guard
  {
    $$ = Create_List_doggy_Guard($1, $2);
  }
;

OPT_Wherepart :
  {
    $$ = NULL;
  }
;

OPT_Wherepart :
  Wherepart
  {
    $$ = $1;
  }
;

OPT_verticalbarsym_Condition :
  {
    $$ = NULL;
  }
;

OPT_verticalbarsym_Condition :
  verticalbarsym
  Condition
  {
    $$ = $2;
  }
;

OPTMORE_Definition :
  {
    $$ = NULL;
  }
;

OPTMORE_Definition :
  Definition
  OPTMORE_Definition
  {
    $$ = Create_List_doggy_Definition($1, $2);
  }
;

ALT_Applied_formal_SEP_commasym :
  Applied_formal
  {
    $$ = Create_List_doggy_Applied_formal($1, NULL);
  }
;

ALT_Applied_formal_SEP_commasym :
  Applied_formal
  commasym
  ALT_Applied_formal_SEP_commasym
  {
    $$ = Create_List_doggy_Applied_formal($1, $3);
  }
;

ALT_SimpleExpr_SEP_Operator :
  SimpleExpr
  {
    $$.f1 = Create_List_doggy_Expr($1, NULL);
    $$.f2 = NULL;
  }
;

ALT_SimpleExpr_SEP_Operator :
  SimpleExpr
  Operator
  ALT_SimpleExpr_SEP_Operator
  {
    $$.f1 = Create_List_doggy_Expr($1, $3.f1);
    $$.f2 = Create_List_doggy_Operator($2, $3.f2);
  }
;

OPTMORE_ELSIFsym_Condition_THENsym_Expr :
  {
    $$.f1 = NULL;
    $$.f2 = NULL;
  }
;

OPTMORE_ELSIFsym_Condition_THENsym_Expr :
  ELSIFsym
  Condition
  THENsym
  Expr
  OPTMORE_ELSIFsym_Condition_THENsym_Expr
  {
    $$.f1 = Create_List_doggy_Expr($2, $5.f1);
    $$.f2 = Create_List_doggy_Expr($4, $5.f2);
  }
;

OPT_Exprs :
  {
    $$ = NULL;
  }
;

OPT_Exprs :
  Exprs
  {
    $$ = $1;
  }
;

ALT_BasicType_SEP_verticalbarsym :
  BasicType
  {
    $$ = Create_List_doggy_Type($1, NULL);
  }
;

ALT_BasicType_SEP_verticalbarsym :
  BasicType
  verticalbarsym
  ALT_BasicType_SEP_verticalbarsym
  {
    $$ = Create_List_doggy_Type($1, $3);
  }
;

OPT_ArgTypes :
  {
    $$ = NULL;
  }
;

OPT_ArgTypes :
  ArgTypes
  {
    $$ = $1;
  }
;

OPT_STEPsym_Num :
  {
    $$ = NULL;
  }
;

OPT_STEPsym_Num :
  STEPsym
  Num
  {
    $$ = $2;
  }
;

ALT_Pattern_SEP_commasym :
  Pattern
  {
    $$ = Create_List_doggy_Pattern($1, NULL);
  }
;

ALT_Pattern_SEP_commasym :
  Pattern
  commasym
  ALT_Pattern_SEP_commasym
  {
    $$ = Create_List_doggy_Pattern($1, $3);
  }
;

ALT_Expr_SEP_commasym :
  Expr
  {
    $$ = Create_List_doggy_Expr($1, NULL);
  }
;

ALT_Expr_SEP_commasym :
  Expr
  commasym
  ALT_Expr_SEP_commasym
  {
    $$ = Create_List_doggy_Expr($1, $3);
  }
;

ALT_Type_SEP_commasym :
  Type
  {
    $$ = Create_List_doggy_Type($1, NULL);
  }
;

ALT_Type_SEP_commasym :
  Type
  commasym
  ALT_Type_SEP_commasym
  {
    $$ = Create_List_doggy_Type($1, $3);
  }
;

OPT_minussym :
  {
    $$ = FALSE;
  }
;

OPT_minussym :
  minussym
  {
    $$ = TRUE;
  }
;

