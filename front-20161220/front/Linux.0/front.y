%{
#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "front.h"

extern int input_line_nr;

struct yy_buffer_state *front_dummy_state (void);
struct yy_buffer_state *front_scanner_state (void);
%}

%token NONSENSE
%token USEsym
%token commasym
%token NAMESPACEsym
%token FROMsym
%token colonsym
%token ROOTsym
%token SCANsym
%token TYPEsym
%token openparsym
%token closeparsym
%token COMMENTsym
%token lessthansym
%token MEMOsym
%token ENUMsym
%token SKIPsym
%token definessym
%token equalssym
%token SCOPEsym
%token OPENSCOPEsym
%token CLOSESCOPEsym
%token FORWARDsym
%token DEFININGsym
%token REDEFININGsym
%token OVERLOADINGsym
%token tildasym
%token exclaimsym
%token equalsequalssym
%token exclaimequalssym
%token lessthanequalssym
%token greaterthanequalssym
%token ampersandsym
%token ampersandampersandsym
%token verticalbarverticalbarsym
%token hatsym
%token plussym
%token minussym
%token starsym
%token slashsym
%token percentsym
%token lessthanlessthansym
%token greaterthangreaterthansym
%token dotsym
%token NULLsym
%token APPLIEDsym
%token NAMEsym
%token FIELDsym
%token WARNINGsym
%token open2symsym
%token verticalbarsym
%token LeftOrsym
%token RightOrsym
%token Xorsym
%token openbrksym
%token closebrksym
%token openchainsym
%token closechainsym
%token EMPTYsym
%token backslashbackslashsym
%token LAYOUTsym
%token COMPAREsym
%token CREATEsym
%token CHECKSsym
%token TRAVERSEsym
%token CLEARsym
%token DONT_CLEARsym
%token Newlinesym
%token LeftAndsym
%token RightAndsym
%token alternate_leftsym
%token alternate_rightsym
%token greaterthansym
%token IFsym
%token THENsym
%token semicolonsym
%token comment1sym
%token comment2sym
%token comment3sym
%token Boolsym
%token Identsym
%token Intsym
%token Keywordsym
%token Charsym
%token Stringsym
%token hole_front
%token start_front
%token hole_Import
%token start_Import
%token hole_ImportedNonTerminals
%token start_ImportedNonTerminals
%token hole_ImportedNonTerminal
%token start_ImportedNonTerminal
%token hole_NonTerminals
%token start_NonTerminals
%token hole_NonTerminal
%token start_NonTerminal
%token hole_Super
%token start_Super
%token hole_Rhs
%token start_Rhs
%token hole_Scoping
%token start_Scoping
%token hole_Alternative
%token start_Alternative
%token hole_Symbol
%token start_Symbol
%token hole_Symbol1
%token start_Symbol1
%token hole_AltSymbol
%token start_AltSymbol
%token hole_SymbolSeq
%token start_SymbolSeq
%token hole_And
%token start_And
%token hole_Or
%token start_Or
%token hole_Symbol2
%token start_Symbol2
%token hole_SimpleSymbol
%token start_SimpleSymbol
%token hole_IdSym
%token start_IdSym
%token hole_OptType
%token start_OptType
%token hole_DefiningSym
%token start_DefiningSym
%token hole_ScopeExpr
%token start_ScopeExpr
%token hole_Defining_id
%token start_Defining_id
%token hole_Define
%token start_Define
%token hole_Field
%token start_Field
%token hole_FieldInits
%token start_FieldInits
%token hole_FieldInit
%token start_FieldInit
%token hole_Type
%token start_Type
%token hole_Expr
%token start_Expr
%token hole_MonExpr1
%token start_MonExpr1
%token hole_SimpleExpr
%token start_SimpleExpr
%token hole_StringOrKeyword
%token start_StringOrKeyword
%token hole_Check
%token start_Check
%token hole_NameSpaceList
%token start_NameSpaceList
%token hole_ExprList
%token start_ExprList
%token hole_IdentList
%token start_IdentList
%token hole_TypeList
%token start_TypeList
%token hole_Alternator
%token start_Alternator
%token hole_ScanInfo
%token start_ScanInfo
%token hole_Defines
%token start_Defines
%token hole_NameSpace
%token start_NameSpace
%token hole_Oper
%token start_Oper
%token hole_NameOrField
%token start_NameOrField
%token hole_OPT_USEsym_IdentList
%token start_OPT_USEsym_IdentList
%token hole_OPT_NAMESPACEsym_NameSpaceList
%token start_OPT_NAMESPACEsym_NameSpaceList
%token hole_OPTMORE_Import
%token start_OPTMORE_Import
%token hole_OPT_NonTerminals
%token start_OPT_NonTerminals
%token hole_ALT_ImportedNonTerminal_SEP_commasym
%token start_ALT_ImportedNonTerminal_SEP_commasym
%token hole_OPT_colonsym_Identsym
%token start_OPT_colonsym_Identsym
%token hole_MORE_NonTerminal
%token start_MORE_NonTerminal
%token hole_OPT_ROOTsym
%token start_OPT_ROOTsym
%token hole_OPT_ScanInfo
%token start_OPT_ScanInfo
%token hole_OPT_Super
%token start_OPT_Super
%token hole_OPT_MEMOsym
%token start_OPT_MEMOsym
%token hole_OPT_ENUMsym
%token start_OPT_ENUMsym
%token hole_OPT_SKIPsym
%token start_OPT_SKIPsym
%token hole_OPTMORE_Scoping
%token start_OPTMORE_Scoping
%token hole_OPT_CHECKSsym_OPTMORE_Check
%token start_OPT_CHECKSsym_OPTMORE_Check
%token hole_OPTMORE_Check
%token start_OPTMORE_Check
%token hole_MORE_Symbol
%token start_MORE_Symbol
%token hole_OPT_ScopeExpr
%token start_OPT_ScopeExpr
%token hole_OPT_WARNINGsym
%token start_OPT_WARNINGsym
%token hole_OPT_NAMEsym_Identsym
%token start_OPT_NAMEsym_Identsym
%token hole_OPT_exclaimsym
%token start_OPT_exclaimsym
%token hole_OPT_TYPEsym_Type
%token start_OPT_TYPEsym_Type
%token hole_OPT_FORWARDsym
%token start_OPT_FORWARDsym
%token hole_OPT_NAMESPACEsym_Identsym
%token start_OPT_NAMESPACEsym_Identsym
%token hole_OPT_TRAVERSEsym
%token start_OPT_TRAVERSEsym
%token hole_OPT_CLEARsym
%token start_OPT_CLEARsym
%token hole_OPT_DONT_CLEARsym
%token start_OPT_DONT_CLEARsym
%token hole_ALT_FieldInit_SEP_commasym
%token start_ALT_FieldInit_SEP_commasym
%token hole_OPT_CREATEsym
%token start_OPT_CREATEsym
%token hole_OPT_openparsym_TypeList_closeparsym
%token start_OPT_openparsym_TypeList_closeparsym
%token hole_OPTMORE_Oper
%token start_OPTMORE_Oper
%token hole_OPT_ExprList
%token start_OPT_ExprList
%token hole_MORE_MonExpr1
%token start_MORE_MonExpr1
%token hole_ALT_NameSpace_SEP_commasym_SP
%token start_ALT_NameSpace_SEP_commasym_SP
%token hole_ALT_Expr_SEP_commasym_SP
%token start_ALT_Expr_SEP_commasym_SP
%token hole_ALT_Identsym_SEP_commasym_SP
%token start_ALT_Identsym_SEP_commasym_SP
%token hole_ALT_Type_SEP_commasym_SP
%token start_ALT_Type_SEP_commasym_SP
%token hole_OPT_COMMENTsym
%token start_OPT_COMMENTsym

%union {
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
}

%type <USEsym_type>	USEsym
%type <commasym_type>	commasym
%type <NAMESPACEsym_type>	NAMESPACEsym
%type <FROMsym_type>	FROMsym
%type <colonsym_type>	colonsym
%type <ROOTsym_type>	ROOTsym
%type <SCANsym_type>	SCANsym
%type <TYPEsym_type>	TYPEsym
%type <openparsym_type>	openparsym
%type <closeparsym_type>	closeparsym
%type <COMMENTsym_type>	COMMENTsym
%type <lessthansym_type>	lessthansym
%type <MEMOsym_type>	MEMOsym
%type <ENUMsym_type>	ENUMsym
%type <SKIPsym_type>	SKIPsym
%type <definessym_type>	definessym
%type <equalssym_type>	equalssym
%type <SCOPEsym_type>	SCOPEsym
%type <OPENSCOPEsym_type>	OPENSCOPEsym
%type <CLOSESCOPEsym_type>	CLOSESCOPEsym
%type <FORWARDsym_type>	FORWARDsym
%type <DEFININGsym_type>	DEFININGsym
%type <REDEFININGsym_type>	REDEFININGsym
%type <OVERLOADINGsym_type>	OVERLOADINGsym
%type <tildasym_type>	tildasym
%type <exclaimsym_type>	exclaimsym
%type <equalsequalssym_type>	equalsequalssym
%type <exclaimequalssym_type>	exclaimequalssym
%type <lessthanequalssym_type>	lessthanequalssym
%type <greaterthanequalssym_type>	greaterthanequalssym
%type <ampersandsym_type>	ampersandsym
%type <ampersandampersandsym_type>	ampersandampersandsym
%type <verticalbarverticalbarsym_type>	verticalbarverticalbarsym
%type <hatsym_type>	hatsym
%type <plussym_type>	plussym
%type <minussym_type>	minussym
%type <starsym_type>	starsym
%type <slashsym_type>	slashsym
%type <percentsym_type>	percentsym
%type <lessthanlessthansym_type>	lessthanlessthansym
%type <greaterthangreaterthansym_type>	greaterthangreaterthansym
%type <dotsym_type>	dotsym
%type <NULLsym_type>	NULLsym
%type <APPLIEDsym_type>	APPLIEDsym
%type <NAMEsym_type>	NAMEsym
%type <FIELDsym_type>	FIELDsym
%type <WARNINGsym_type>	WARNINGsym
%type <open2symsym_type>	open2symsym
%type <verticalbarsym_type>	verticalbarsym
%type <LeftOrsym_type>	LeftOrsym
%type <RightOrsym_type>	RightOrsym
%type <Xorsym_type>	Xorsym
%type <openbrksym_type>	openbrksym
%type <closebrksym_type>	closebrksym
%type <openchainsym_type>	openchainsym
%type <closechainsym_type>	closechainsym
%type <EMPTYsym_type>	EMPTYsym
%type <backslashbackslashsym_type>	backslashbackslashsym
%type <LAYOUTsym_type>	LAYOUTsym
%type <COMPAREsym_type>	COMPAREsym
%type <CREATEsym_type>	CREATEsym
%type <CHECKSsym_type>	CHECKSsym
%type <TRAVERSEsym_type>	TRAVERSEsym
%type <CLEARsym_type>	CLEARsym
%type <DONT_CLEARsym_type>	DONT_CLEARsym
%type <Newlinesym_type>	Newlinesym
%type <LeftAndsym_type>	LeftAndsym
%type <RightAndsym_type>	RightAndsym
%type <alternate_leftsym_type>	alternate_leftsym
%type <alternate_rightsym_type>	alternate_rightsym
%type <greaterthansym_type>	greaterthansym
%type <IFsym_type>	IFsym
%type <THENsym_type>	THENsym
%type <semicolonsym_type>	semicolonsym
%type <comment1sym_type>	comment1sym
%type <comment2sym_type>	comment2sym
%type <comment3sym_type>	comment3sym
%type <Boolsym_type>	Boolsym
%type <Identsym_type>	Identsym
%type <Intsym_type>	Intsym
%type <Keywordsym_type>	Keywordsym
%type <Charsym_type>	Charsym
%type <Stringsym_type>	Stringsym
%type <front_type>	front
%type <Import_type>	Import
%type <ImportedNonTerminals_type>	ImportedNonTerminals
%type <ImportedNonTerminal_type>	ImportedNonTerminal
%type <NonTerminals_type>	NonTerminals
%type <NonTerminal_type>	NonTerminal
%type <Super_type>	Super
%type <Rhs_type>	Rhs
%type <Scoping_type>	Scoping
%type <Choices_type>	Choices
%type <ChoiceList_type>	ChoiceList
%type <Alternative_type>	Alternative
%type <Symbol_type>	Symbol
%type <Symbol1_type>	Symbol1
%type <AltSymbol_type>	AltSymbol
%type <SymbolSeq_type>	SymbolSeq
%type <And_type>	And
%type <Or_type>	Or
%type <Symbol2_type>	Symbol2
%type <SimpleSymbol_type>	SimpleSymbol
%type <IdSym_type>	IdSym
%type <Alternatives_type>	Alternatives
%type <OptType_type>	OptType
%type <DefiningSym_type>	DefiningSym
%type <ScopeExpr_type>	ScopeExpr
%type <Defining_id_type>	Defining_id
%type <Define_type>	Define
%type <Field_type>	Field
%type <FieldInits_type>	FieldInits
%type <FieldInit_type>	FieldInit
%type <Type_type>	Type
%type <Expr_type>	Expr
%type <MonExpr1_type>	MonExpr1
%type <SimpleExpr_type>	SimpleExpr
%type <StringOrKeyword_type>	StringOrKeyword
%type <Check_type>	Check
%type <NameSpaceList_type>	NameSpaceList
%type <ExprList_type>	ExprList
%type <IdentList_type>	IdentList
%type <TypeList_type>	TypeList
%type <Alternator_type>	Alternator
%type <ScanInfo_type>	ScanInfo
%type <Defines_type>	Defines
%type <NameSpace_type>	NameSpace
%type <Oper_type>	Oper
%type <NameOrField_type>	NameOrField
%type <OPT_USEsym_IdentList_type>	OPT_USEsym_IdentList
%type <OPT_NAMESPACEsym_NameSpaceList_type>	OPT_NAMESPACEsym_NameSpaceList
%type <OPTMORE_Import_type>	OPTMORE_Import
%type <OPT_NonTerminals_type>	OPT_NonTerminals
%type <ALT_ImportedNonTerminal_SEP_commasym_type>	ALT_ImportedNonTerminal_SEP_commasym
%type <OPT_colonsym_Identsym_type>	OPT_colonsym_Identsym
%type <MORE_NonTerminal_type>	MORE_NonTerminal
%type <OPT_ROOTsym_type>	OPT_ROOTsym
%type <OPT_ScanInfo_type>	OPT_ScanInfo
%type <OPT_Super_type>	OPT_Super
%type <OPT_MEMOsym_type>	OPT_MEMOsym
%type <OPT_ENUMsym_type>	OPT_ENUMsym
%type <OPT_SKIPsym_type>	OPT_SKIPsym
%type <OPTMORE_Scoping_type>	OPTMORE_Scoping
%type <OPT_Choices_type>	OPT_Choices
%type <OPT_CHECKSsym_OPTMORE_Check_type>	OPT_CHECKSsym_OPTMORE_Check
%type <OPTMORE_Check_type>	OPTMORE_Check
%type <ALT_Alternative_SEP_Or_type>	ALT_Alternative_SEP_Or
%type <MORE_Symbol_type>	MORE_Symbol
%type <OPT_ALT_ONCE_SymbolORField_SEP_And_type>	OPT_ALT_ONCE_SymbolORField_SEP_And
%type <ALT_ONCE_SymbolORField_SEP_And_type>	ALT_ONCE_SymbolORField_SEP_And
%type <ONCE_SymbolORField_type>	ONCE_SymbolORField
%type <OPT_ScopeExpr_type>	OPT_ScopeExpr
%type <OPT_WARNINGsym_type>	OPT_WARNINGsym
%type <OPT_NAMEsym_Identsym_type>	OPT_NAMEsym_Identsym
%type <OPT_exclaimsym_type>	OPT_exclaimsym
%type <ALT_Symbol1_SEP_Or_SP_type>	ALT_Symbol1_SEP_Or_SP
%type <OPT_TYPEsym_Type_type>	OPT_TYPEsym_Type
%type <OPT_FORWARDsym_type>	OPT_FORWARDsym
%type <OPT_NAMESPACEsym_Identsym_type>	OPT_NAMESPACEsym_Identsym
%type <OPT_TRAVERSEsym_type>	OPT_TRAVERSEsym
%type <OPT_CLEARsym_type>	OPT_CLEARsym
%type <OPT_DONT_CLEARsym_type>	OPT_DONT_CLEARsym
%type <ALT_FieldInit_SEP_commasym_type>	ALT_FieldInit_SEP_commasym
%type <OPT_CREATEsym_type>	OPT_CREATEsym
%type <OPT_openparsym_TypeList_closeparsym_type>	OPT_openparsym_TypeList_closeparsym
%type <ALT_MonExpr1_SEP_SP_Oper_type>	ALT_MonExpr1_SEP_SP_Oper
%type <OPTMORE_Oper_type>	OPTMORE_Oper
%type <OPT_ExprList_type>	OPT_ExprList
%type <MORE_MonExpr1_type>	MORE_MonExpr1
%type <ALT_NameSpace_SEP_commasym_SP_type>	ALT_NameSpace_SEP_commasym_SP
%type <ALT_Expr_SEP_commasym_SP_type>	ALT_Expr_SEP_commasym_SP
%type <ALT_Identsym_SEP_commasym_SP_type>	ALT_Identsym_SEP_commasym_SP
%type <ALT_Type_SEP_commasym_SP_type>	ALT_Type_SEP_commasym_SP
%type <OPT_COMMENTsym_type>	OPT_COMMENTsym

%start front

%%

front :
  OPT_USEsym_IdentList
  OPT_NAMESPACEsym_NameSpaceList
  OPTMORE_Import
  OPT_NonTerminals
  { $$ = Create_front_front(make_post_src_info(@1.first_line, @4.last_line), $1, $2, $3, $4);
    Decorate_front($$);
  }
;

Import :
  FROMsym
  Identsym
  colonsym
  ImportedNonTerminals
  { $$ = Create_front_Import(make_post_src_info(@1.first_line, @4.last_line), $2, $4);
  }
;

ImportedNonTerminals :
  ALT_ImportedNonTerminal_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

ImportedNonTerminal :
  Identsym
  OPT_colonsym_Identsym
  { $$ = Create_front_ImportedNonTerminal(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

NonTerminals :
  MORE_NonTerminal
  /* No type */
  {
    $$ = $1;
  }
;

NonTerminal :
  OPT_ROOTsym
  OPT_ScanInfo
  Identsym
  OPT_Super
  OPT_MEMOsym
  OPT_ENUMsym
  OPT_SKIPsym
  Defines
  Rhs
  semicolonsym
  { $$ = Create_front_NonTerminal(make_post_src_info(@1.first_line, @10.last_line), $1, $2, $3, $4, $5, $6, $7, $8, $9);
  }
;

Super :
  lessthansym
  Identsym
  { $$ = Create_front_SubType(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

Super :
  colonsym
  Identsym
  { $$ = Create_front_NoType(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

Rhs :
  OPTMORE_Scoping
  Symbol1
  OPT_Choices
  OPT_CHECKSsym_OPTMORE_Check
  { $$ = Create_front_Rhs(make_post_src_info(@1.first_line, @4.last_line), $1, $2, $3.f1, $3.f2, $3.f3, $3.f4, $3.f5, $4);
  }
;

Scoping :
  SCOPEsym
  /* Enum type */
  { $$ = front_NewScope; }
;

Scoping :
  OPENSCOPEsym
  /* Enum type */
  { $$ = front_OpenScope; }
;

Scoping :
  CLOSESCOPEsym
  /* Enum type */
  { $$ = front_CloseScope; }
;

Choices :
  lessthansym
  ChoiceList
  greaterthansym
  Symbol1
  /* No type */
  {
    $$.f1 = $1;
    $$.f2 = $2.f1;
    $$.f3 = $2.f2;
    $$.f4 = $3;
    $$.f5 = $4;
  }
;

ChoiceList :
  ALT_Alternative_SEP_Or
  /* No type */
  {
    $$.f1 = $1.f1;
    $$.f2 = $1.f2;
  }
;

Alternative :
  Identsym
  OPT_MEMOsym
  OPT_SKIPsym
  definessym
  Rhs
  { $$ = Create_front_LabeledAlt(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4, $5);
  }
;

Alternative :
  Symbol1
  { $$ = Create_front_UnLabeledAlt(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Symbol :
  Identsym
  colonsym
  Symbol2
  { $$ = Create_front_LabeledSym(make_post_src_info(@1.first_line, @3.last_line), $1, $3);
  }
;

Symbol :
  Symbol2
  {
    $$ = $1;
  }
;

Symbol1 :
  AltSymbol
  {
    $$ = $1;
  }
;

Symbol1 :
  SymbolSeq
  {
    $$ = $1;
  }
;

AltSymbol :
  SymbolSeq
  Alternator
  MORE_Symbol
  { $$ = Create_front_AltSymbol(make_post_src_info(@1.first_line, @3.last_line), $1, $2, $3);
  }
;

SymbolSeq :
  OPT_ALT_ONCE_SymbolORField_SEP_And
  { $$ = Create_front_SymbolSeq(make_post_src_info(@1.first_line, @1.last_line), $1.f1, $1.f2, $1.f3);
  }
;

And :
  Newlinesym
  /* Enum type */
  { $$ = front_AndTranspose; }
;

And :
  LeftAndsym
  /* Enum type */
  { $$ = front_AndLeft; }
;

And :
  RightAndsym
  /* Enum type */
  { $$ = front_AndRight; }
;

And :
  /* Enum type */
  { $$ = front_AndCenter; }
;

Or :
  verticalbarsym
  /* Enum type */
  { $$ = front_OrCenter; }
;

Or :
  LeftOrsym
  /* Enum type */
  { $$ = front_OrLeft; }
;

Or :
  RightOrsym
  /* Enum type */
  { $$ = front_OrRight; }
;

Or :
  Xorsym
  /* Enum type */
  { $$ = front_OrTranspose; }
;

Symbol2 :
  SimpleSymbol
  COMPAREsym
  Identsym
  { $$ = Create_front_CompareSym(make_post_src_info(@1.first_line, @3.last_line), $1, $3);
  }
;

Symbol2 :
  SimpleSymbol
  {
    $$ = $1;
  }
;

SimpleSymbol :
  DefiningSym
  {
    $$ = $1;
  }
;

SimpleSymbol :
  IdSym
  {
    $$ = $1;
  }
;

SimpleSymbol :
  APPLIEDsym
  Identsym
  NameOrField
  Identsym
  OPT_ScopeExpr
  OPT_WARNINGsym
  { $$ = Create_front_AppliedSym(make_post_src_info(@1.first_line, @6.last_line), $2, $3, $4, $5, $6);
  }
;

SimpleSymbol :
  Stringsym
  OPT_NAMEsym_Identsym
  OptType
  { $$ = Create_front_StringSymbol(make_post_src_info(@1.first_line, @3.last_line), $1, $2, $3);
  }
;

SimpleSymbol :
  Charsym
  OptType
  { $$ = Create_front_CharSymbol(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

SimpleSymbol :
  Keywordsym
  OptType
  { $$ = Create_front_KeywordSymbol(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

SimpleSymbol :
  open2symsym
  Alternatives
  closeparsym
  closeparsym
  { $$ = Create_front_OnceSymbol(make_post_src_info(@1.first_line, @4.last_line), $2.f1, $2.f2);
  }
;

SimpleSymbol :
  openbrksym
  Alternatives
  closebrksym
  OPT_exclaimsym
  { $$ = Create_front_OptSymbol(make_post_src_info(@1.first_line, @4.last_line), $2.f1, $2.f2, $4);
  }
;

SimpleSymbol :
  openchainsym
  Alternatives
  closechainsym
  { $$ = Create_front_OptMoreSymbol(make_post_src_info(@1.first_line, @3.last_line), $2.f1, $2.f2);
  }
;

SimpleSymbol :
  openchainsym
  Alternatives
  closechainsym
  plussym
  { $$ = Create_front_MoreSymbol(make_post_src_info(@1.first_line, @4.last_line), $2.f1, $2.f2, $4);
  }
;

SimpleSymbol :
  EMPTYsym
  { $$ = Create_front_EmptySym(make_post_src_info(@1.first_line, @1.last_line));
  }
;

SimpleSymbol :
  backslashbackslashsym
  StringOrKeyword
  { $$ = Create_front_LayoutString(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

SimpleSymbol :
  LAYOUTsym
  Expr
  { $$ = Create_front_LayoutAction(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

IdSym :
  Identsym
  OptType
  { $$ = Create_front_IdSym(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

Alternatives :
  ALT_Symbol1_SEP_Or_SP
  /* No type */
  {
    $$.f1 = $1.f1;
    $$.f2 = $1.f2;
  }
;

OptType :
  OPT_TYPEsym_Type
  /* No type */
  {
    $$ = $1;
  }
;

DefiningSym :
  OPT_FORWARDsym
  Define
  Defining_id
  OPT_NAMESPACEsym_Identsym
  OPT_ScopeExpr
  { $$ = Create_front_DefiningSym(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4, $5);
  }
;

ScopeExpr :
  SCOPEsym
  Expr
  /* No type */
  {
    $$ = $2;
  }
;

Defining_id :
  IdSym
  { $$ = Create_front_DefId(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Defining_id :
  openparsym
  Expr
  closeparsym
  { $$ = Create_front_DefExpr(make_post_src_info(@1.first_line, @3.last_line), $2);
  }
;

Define :
  DEFININGsym
  /* Enum type */
  { $$ = front_Defining; }
;

Define :
  REDEFININGsym
  /* Enum type */
  { $$ = front_Redefining; }
;

Define :
  OVERLOADINGsym
  /* Enum type */
  { $$ = front_Overloading; }
;

Field :
  Identsym
  colonsym
  Type
  equalssym
  FieldInits
  OPT_TRAVERSEsym
  OPT_CLEARsym
  OPT_DONT_CLEARsym
  { $$ = Create_front_Field(make_post_src_info(@1.first_line, @8.last_line), $1, $3, $4, $5, $6, $7, $8);
  }
;

FieldInits :
  ALT_FieldInit_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

FieldInit :
  OPT_CREATEsym
  Expr
  { $$ = Create_front_WhenCreate(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

FieldInit :
  SCOPEsym
  Expr
  { $$ = Create_front_WhenScope(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

FieldInit :
  DEFININGsym
  Expr
  { $$ = Create_front_WhenDefining(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

FieldInit :
  APPLIEDsym
  Expr
  { $$ = Create_front_WhenApplied(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

FieldInit :
  CHECKSsym
  Expr
  { $$ = Create_front_WhenChecks(make_post_src_info(@1.first_line, @2.last_line), $2);
  }
;

Type :
  Identsym
  OPT_openparsym_TypeList_closeparsym
  { $$ = Create_front_Type(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

Expr :
  ALT_MonExpr1_SEP_SP_Oper
  { $$ = Create_front_BinExpr(make_post_src_info(@1.first_line, @1.last_line), $1.f1, $1.f2);
  }
;

MonExpr1 :
  OPTMORE_Oper
  SimpleExpr
  { $$ = Create_front_MonExpr(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

SimpleExpr :
  Identsym
  { $$ = Create_front_IdentExpr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

SimpleExpr :
  SimpleExpr
  dotsym
  Identsym
  { $$ = Create_front_QualExpr(make_post_src_info(@1.first_line, @3.last_line), $1, $3);
  }
;

SimpleExpr :
  Intsym
  { $$ = Create_front_IntExpr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

SimpleExpr :
  Boolsym
  { $$ = Create_front_BoolExpr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

SimpleExpr :
  StringOrKeyword
  { $$ = Create_front_StringExpr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

SimpleExpr :
  NULLsym
  { $$ = Create_front_NilExpr(make_post_src_info(@1.first_line, @1.last_line));
  }
;

SimpleExpr :
  SimpleExpr
  openparsym
  OPT_ExprList
  closeparsym
  { $$ = Create_front_CallExpr(make_post_src_info(@1.first_line, @4.last_line), $1, $3);
  }
;

StringOrKeyword :
  Stringsym
  {
    $$ = $1;
  }
;

StringOrKeyword :
  Keywordsym
  {
    $$ = $1;
  }
;

StringOrKeyword :
  Charsym
  {
    $$ = $1;
  }
;

Check :
  IFsym
  Expr
  THENsym
  OPT_WARNINGsym
  MORE_MonExpr1
  { $$ = Create_front_Check(make_post_src_info(@1.first_line, @5.last_line), $2, $4, $5);
  }
;

NameSpaceList :
  ALT_NameSpace_SEP_commasym_SP
  /* No type */
  {
    $$ = $1;
  }
;

ExprList :
  ALT_Expr_SEP_commasym_SP
  /* No type */
  {
    $$ = $1;
  }
;

IdentList :
  ALT_Identsym_SEP_commasym_SP
  /* No type */
  {
    $$ = $1;
  }
;

TypeList :
  ALT_Type_SEP_commasym_SP
  /* No type */
  {
    $$ = $1;
  }
;

Alternator :
  alternate_leftsym
  /* Enum type */
  { $$ = FALSE; }
;

Alternator :
  alternate_rightsym
  /* Enum type */
  { $$ = TRUE; }
;

ScanInfo :
  SCANsym
  OptType
  OPT_COMMENTsym
  { $$ = Create_front_ScanInfo(make_post_src_info(@1.first_line, @3.last_line), $2, $3);
  }
;

Defines :
  definessym
  { $$ = Create_front_PlainDef(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Defines :
  equalssym
  { $$ = Create_front_MacroDef(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

NameSpace :
  Identsym
  { $$ = Create_front_NameSpace(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Oper :
  tildasym
  {
    $$ = $1;
  }
;

Oper :
  exclaimsym
  {
    $$ = $1;
  }
;

Oper :
  equalsequalssym
  {
    $$ = $1;
  }
;

Oper :
  exclaimequalssym
  {
    $$ = $1;
  }
;

Oper :
  lessthanequalssym
  {
    $$ = $1;
  }
;

Oper :
  greaterthanequalssym
  {
    $$ = $1;
  }
;

Oper :
  ampersandsym
  {
    $$ = $1;
  }
;

Oper :
  ampersandampersandsym
  {
    $$ = $1;
  }
;

Oper :
  verticalbarverticalbarsym
  {
    $$ = $1;
  }
;

Oper :
  hatsym
  {
    $$ = $1;
  }
;

Oper :
  plussym
  {
    $$ = $1;
  }
;

Oper :
  minussym
  {
    $$ = $1;
  }
;

Oper :
  starsym
  {
    $$ = $1;
  }
;

Oper :
  slashsym
  {
    $$ = $1;
  }
;

Oper :
  percentsym
  {
    $$ = $1;
  }
;

Oper :
  lessthanlessthansym
  {
    $$ = $1;
  }
;

Oper :
  greaterthangreaterthansym
  {
    $$ = $1;
  }
;

NameOrField :
  NAMEsym
  /* Enum type */
  { $$ = front_AppliedName; }
;

NameOrField :
  FIELDsym
  /* Enum type */
  { $$ = front_AppliedField; }
;

/**** Extra rules ****/

OPT_USEsym_IdentList :
  {
    $$ = NULL;
  }
;

OPT_USEsym_IdentList :
  USEsym
  IdentList
  {
    $$ = $2;
  }
;

OPT_NAMESPACEsym_NameSpaceList :
  {
    $$ = NULL;
  }
;

OPT_NAMESPACEsym_NameSpaceList :
  NAMESPACEsym
  NameSpaceList
  {
    $$ = $2;
  }
;

OPTMORE_Import :
  {
    $$ = NULL;
  }
;

OPTMORE_Import :
  Import
  OPTMORE_Import
  {
    $$ = Create_List_front_Import($1, $2);
  }
;

OPT_NonTerminals :
  {
    $$ = NULL;
  }
;

OPT_NonTerminals :
  NonTerminals
  {
    $$ = $1;
  }
;

ALT_ImportedNonTerminal_SEP_commasym :
  ImportedNonTerminal
  {
    $$ = Create_List_front_ImportedNonTerminal($1, NULL);
  }
;

ALT_ImportedNonTerminal_SEP_commasym :
  ImportedNonTerminal
  commasym
  ALT_ImportedNonTerminal_SEP_commasym
  {
    $$ = Create_List_front_ImportedNonTerminal($1, $3);
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

MORE_NonTerminal :
  NonTerminal
  {
    $$ = Create_List_front_NonTerminal($1, NULL);
  }
;

MORE_NonTerminal :
  NonTerminal
  MORE_NonTerminal
  {
    $$ = Create_List_front_NonTerminal($1, $2);
  }
;

OPT_ROOTsym :
  {
    $$ = FALSE;
  }
;

OPT_ROOTsym :
  ROOTsym
  {
    $$ = TRUE;
  }
;

OPT_ScanInfo :
  {
    $$ = NULL;
  }
;

OPT_ScanInfo :
  ScanInfo
  {
    $$ = $1;
  }
;

OPT_Super :
  {
    $$ = NULL;
  }
;

OPT_Super :
  Super
  {
    $$ = $1;
  }
;

OPT_MEMOsym :
  {
    $$ = FALSE;
  }
;

OPT_MEMOsym :
  MEMOsym
  {
    $$ = TRUE;
  }
;

OPT_ENUMsym :
  {
    $$ = FALSE;
  }
;

OPT_ENUMsym :
  ENUMsym
  {
    $$ = TRUE;
  }
;

OPT_SKIPsym :
  {
    $$ = FALSE;
  }
;

OPT_SKIPsym :
  SKIPsym
  {
    $$ = TRUE;
  }
;

OPTMORE_Scoping :
  {
    $$ = NULL;
  }
;

OPTMORE_Scoping :
  Scoping
  OPTMORE_Scoping
  {
    $$ = Create_List_front_Scoping($1, $2);
  }
;

OPT_Choices :
  {
    $$.f1 = NULL;
    $$.f2 = NULL;
    $$.f3 = NULL;
    $$.f4 = NULL;
    $$.f5 = NULL;
  }
;

OPT_Choices :
  Choices
  {
    $$.f1 = $1.f1;
    $$.f2 = $1.f2;
    $$.f3 = $1.f3;
    $$.f4 = $1.f4;
    $$.f5 = $1.f5;
  }
;

OPT_CHECKSsym_OPTMORE_Check :
  {
    $$ = NULL;
  }
;

OPT_CHECKSsym_OPTMORE_Check :
  CHECKSsym
  OPTMORE_Check
  {
    $$ = $2;
  }
;

OPTMORE_Check :
  {
    $$ = NULL;
  }
;

OPTMORE_Check :
  Check
  OPTMORE_Check
  {
    $$ = Create_List_front_Check($1, $2);
  }
;

ALT_Alternative_SEP_Or :
  Alternative
  {
    $$.f1 = Create_List_front_Alternative($1, NULL);
    $$.f2 = NULL;
  }
;

ALT_Alternative_SEP_Or :
  Alternative
  Or
  ALT_Alternative_SEP_Or
  {
    $$.f1 = Create_List_front_Alternative($1, $3.f1);
    $$.f2 = Create_List_front_Or($2, $3.f2);
  }
;

MORE_Symbol :
  Symbol
  {
    $$ = Create_List_front_Symbol($1, NULL);
  }
;

MORE_Symbol :
  Symbol
  MORE_Symbol
  {
    $$ = Create_List_front_Symbol($1, $2);
  }
;

OPT_ALT_ONCE_SymbolORField_SEP_And :
  {
    $$.f1 = NULL;
    $$.f2 = NULL;
    $$.f3 = NULL;
  }
;

OPT_ALT_ONCE_SymbolORField_SEP_And :
  ALT_ONCE_SymbolORField_SEP_And
  {
    $$.f1 = $1.f1;
    $$.f2 = $1.f2;
    $$.f3 = $1.f3;
  }
;

ALT_ONCE_SymbolORField_SEP_And :
  ONCE_SymbolORField
  {
    $$.f1 = Create_List_front_Symbol($1.f1, NULL);
    $$.f2 = Create_List_front_Field($1.f2, NULL);
    $$.f3 = NULL;
  }
;

ALT_ONCE_SymbolORField_SEP_And :
  ONCE_SymbolORField
  And
  ALT_ONCE_SymbolORField_SEP_And
  {
    $$.f1 = Create_List_front_Symbol($1.f1, $3.f1);
    $$.f2 = Create_List_front_Field($1.f2, $3.f2);
    $$.f3 = Create_List_front_And($2, $3.f3);
  }
;

ONCE_SymbolORField :
  Symbol
  {
    $$.f1 = $1;
    $$.f2 = NULL;
  }
;

ONCE_SymbolORField :
  Field
  {
    $$.f1 = NULL;
    $$.f2 = $1;
  }
;

OPT_ScopeExpr :
  {
    $$ = NULL;
  }
;

OPT_ScopeExpr :
  ScopeExpr
  {
    $$ = $1;
  }
;

OPT_WARNINGsym :
  {
    $$ = FALSE;
  }
;

OPT_WARNINGsym :
  WARNINGsym
  {
    $$ = TRUE;
  }
;

OPT_NAMEsym_Identsym :
  {
    $$ = NULL;
  }
;

OPT_NAMEsym_Identsym :
  NAMEsym
  Identsym
  {
    $$ = $2;
  }
;

OPT_exclaimsym :
  {
    $$ = FALSE;
  }
;

OPT_exclaimsym :
  exclaimsym
  {
    $$ = TRUE;
  }
;

ALT_Symbol1_SEP_Or_SP :
  Symbol1
  {
    $$.f1 = Create_List_front_Symbol($1, NULL);
    $$.f2 = NULL;
  }
;

ALT_Symbol1_SEP_Or_SP :
  Symbol1
  Or
  ALT_Symbol1_SEP_Or_SP
  {
    $$.f1 = Create_List_front_Symbol($1, $3.f1);
    $$.f2 = Create_List_front_Or($2, $3.f2);
  }
;

OPT_TYPEsym_Type :
  {
    $$ = NULL;
  }
;

OPT_TYPEsym_Type :
  TYPEsym
  Type
  {
    $$ = $2;
  }
;

OPT_FORWARDsym :
  {
    $$ = FALSE;
  }
;

OPT_FORWARDsym :
  FORWARDsym
  {
    $$ = TRUE;
  }
;

OPT_NAMESPACEsym_Identsym :
  {
    $$ = NULL;
  }
;

OPT_NAMESPACEsym_Identsym :
  NAMESPACEsym
  Identsym
  {
    $$ = $2;
  }
;

OPT_TRAVERSEsym :
  {
    $$ = FALSE;
  }
;

OPT_TRAVERSEsym :
  TRAVERSEsym
  {
    $$ = TRUE;
  }
;

OPT_CLEARsym :
  {
    $$ = FALSE;
  }
;

OPT_CLEARsym :
  CLEARsym
  {
    $$ = TRUE;
  }
;

OPT_DONT_CLEARsym :
  {
    $$ = FALSE;
  }
;

OPT_DONT_CLEARsym :
  DONT_CLEARsym
  {
    $$ = TRUE;
  }
;

ALT_FieldInit_SEP_commasym :
  FieldInit
  {
    $$ = Create_List_front_FieldInit($1, NULL);
  }
;

ALT_FieldInit_SEP_commasym :
  FieldInit
  commasym
  ALT_FieldInit_SEP_commasym
  {
    $$ = Create_List_front_FieldInit($1, $3);
  }
;

OPT_CREATEsym :
  {
    $$ = FALSE;
  }
;

OPT_CREATEsym :
  CREATEsym
  {
    $$ = TRUE;
  }
;

OPT_openparsym_TypeList_closeparsym :
  {
    $$ = NULL;
  }
;

OPT_openparsym_TypeList_closeparsym :
  openparsym
  TypeList
  closeparsym
  {
    $$ = $2;
  }
;

ALT_MonExpr1_SEP_SP_Oper :
  MonExpr1
  {
    $$.f1 = Create_List_front_Expr($1, NULL);
    $$.f2 = NULL;
  }
;

ALT_MonExpr1_SEP_SP_Oper :
  MonExpr1
  Oper
  ALT_MonExpr1_SEP_SP_Oper
  {
    $$.f1 = Create_List_front_Expr($1, $3.f1);
    $$.f2 = Create_List_Ident($2, $3.f2);
  }
;

OPTMORE_Oper :
  {
    $$ = NULL;
  }
;

OPTMORE_Oper :
  Oper
  OPTMORE_Oper
  {
    $$ = Create_List_Ident($1, $2);
  }
;

OPT_ExprList :
  {
    $$ = NULL;
  }
;

OPT_ExprList :
  ExprList
  {
    $$ = $1;
  }
;

MORE_MonExpr1 :
  MonExpr1
  {
    $$ = Create_List_front_Expr($1, NULL);
  }
;

MORE_MonExpr1 :
  MonExpr1
  MORE_MonExpr1
  {
    $$ = Create_List_front_Expr($1, $2);
  }
;

ALT_NameSpace_SEP_commasym_SP :
  NameSpace
  {
    $$ = Create_List_front_NameSpace($1, NULL);
  }
;

ALT_NameSpace_SEP_commasym_SP :
  NameSpace
  commasym
  ALT_NameSpace_SEP_commasym_SP
  {
    $$ = Create_List_front_NameSpace($1, $3);
  }
;

ALT_Expr_SEP_commasym_SP :
  Expr
  {
    $$ = Create_List_front_Expr($1, NULL);
  }
;

ALT_Expr_SEP_commasym_SP :
  Expr
  commasym
  ALT_Expr_SEP_commasym_SP
  {
    $$ = Create_List_front_Expr($1, $3);
  }
;

ALT_Identsym_SEP_commasym_SP :
  Identsym
  {
    $$ = Create_List_Ident($1, NULL);
  }
;

ALT_Identsym_SEP_commasym_SP :
  Identsym
  commasym
  ALT_Identsym_SEP_commasym_SP
  {
    $$ = Create_List_Ident($1, $3);
  }
;

ALT_Type_SEP_commasym_SP :
  Type
  {
    $$ = Create_List_front_Type($1, NULL);
  }
;

ALT_Type_SEP_commasym_SP :
  Type
  commasym
  ALT_Type_SEP_commasym_SP
  {
    $$ = Create_List_front_Type($1, $3);
  }
;

OPT_COMMENTsym :
  {
    $$ = FALSE;
  }
;

OPT_COMMENTsym :
  COMMENTsym
  {
    $$ = TRUE;
  }
;

front :
  hole_front
  { $$ = (front_front)Get_sub_tree (); }
;

front :
  start_front
  front
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Import :
  hole_Import
  { $$ = (front_Import)Get_sub_tree (); }
;

front :
  start_Import
  Import
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ImportedNonTerminals :
  hole_ImportedNonTerminals
  { $$ = (List_front_ImportedNonTerminal)Get_sub_tree (); }
;

front :
  start_ImportedNonTerminals
  ImportedNonTerminals
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ImportedNonTerminal :
  hole_ImportedNonTerminal
  { $$ = (front_ImportedNonTerminal)Get_sub_tree (); }
;

front :
  start_ImportedNonTerminal
  ImportedNonTerminal
  { front_multi_action ((void*)$2); YYACCEPT; }
;

NonTerminals :
  hole_NonTerminals
  { $$ = (List_front_NonTerminal)Get_sub_tree (); }
;

front :
  start_NonTerminals
  NonTerminals
  { front_multi_action ((void*)$2); YYACCEPT; }
;

NonTerminal :
  hole_NonTerminal
  { $$ = (front_NonTerminal)Get_sub_tree (); }
;

front :
  start_NonTerminal
  NonTerminal
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Super :
  hole_Super
  { $$ = (front_Super)Get_sub_tree (); }
;

front :
  start_Super
  Super
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Rhs :
  hole_Rhs
  { $$ = (front_Rhs)Get_sub_tree (); }
;

front :
  start_Rhs
  Rhs
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Scoping :
  hole_Scoping
  { $$ = (front_Scoping)Get_sub_tree (); }
;

front :
  start_Scoping
  Scoping
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Alternative :
  hole_Alternative
  { $$ = (front_Alternative)Get_sub_tree (); }
;

front :
  start_Alternative
  Alternative
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Symbol :
  hole_Symbol
  { $$ = (front_Symbol)Get_sub_tree (); }
;

front :
  start_Symbol
  Symbol
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Symbol1 :
  hole_Symbol1
  { $$ = (front_Symbol)Get_sub_tree (); }
;

front :
  start_Symbol1
  Symbol1
  { front_multi_action ((void*)$2); YYACCEPT; }
;

AltSymbol :
  hole_AltSymbol
  { $$ = (front_Symbol)Get_sub_tree (); }
;

front :
  start_AltSymbol
  AltSymbol
  { front_multi_action ((void*)$2); YYACCEPT; }
;

SymbolSeq :
  hole_SymbolSeq
  { $$ = (front_Symbol)Get_sub_tree (); }
;

front :
  start_SymbolSeq
  SymbolSeq
  { front_multi_action ((void*)$2); YYACCEPT; }
;

And :
  hole_And
  { $$ = (front_And)Get_sub_tree (); }
;

front :
  start_And
  And
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Or :
  hole_Or
  { $$ = (front_Or)Get_sub_tree (); }
;

front :
  start_Or
  Or
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Symbol2 :
  hole_Symbol2
  { $$ = (front_Symbol)Get_sub_tree (); }
;

front :
  start_Symbol2
  Symbol2
  { front_multi_action ((void*)$2); YYACCEPT; }
;

SimpleSymbol :
  hole_SimpleSymbol
  { $$ = (front_Symbol)Get_sub_tree (); }
;

front :
  start_SimpleSymbol
  SimpleSymbol
  { front_multi_action ((void*)$2); YYACCEPT; }
;

IdSym :
  hole_IdSym
  { $$ = (front_Symbol)Get_sub_tree (); }
;

front :
  start_IdSym
  IdSym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OptType :
  hole_OptType
  { $$ = (front_Type)Get_sub_tree (); }
;

front :
  start_OptType
  OptType
  { front_multi_action ((void*)$2); YYACCEPT; }
;

DefiningSym :
  hole_DefiningSym
  { $$ = (front_Symbol)Get_sub_tree (); }
;

front :
  start_DefiningSym
  DefiningSym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ScopeExpr :
  hole_ScopeExpr
  { $$ = (front_Expr)Get_sub_tree (); }
;

front :
  start_ScopeExpr
  ScopeExpr
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Defining_id :
  hole_Defining_id
  { $$ = (front_Defining_id)Get_sub_tree (); }
;

front :
  start_Defining_id
  Defining_id
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Define :
  hole_Define
  { $$ = (front_Define)Get_sub_tree (); }
;

front :
  start_Define
  Define
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Field :
  hole_Field
  { $$ = (front_Field)Get_sub_tree (); }
;

front :
  start_Field
  Field
  { front_multi_action ((void*)$2); YYACCEPT; }
;

FieldInits :
  hole_FieldInits
  { $$ = (List_front_FieldInit)Get_sub_tree (); }
;

front :
  start_FieldInits
  FieldInits
  { front_multi_action ((void*)$2); YYACCEPT; }
;

FieldInit :
  hole_FieldInit
  { $$ = (front_FieldInit)Get_sub_tree (); }
;

front :
  start_FieldInit
  FieldInit
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Type :
  hole_Type
  { $$ = (front_Type)Get_sub_tree (); }
;

front :
  start_Type
  Type
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Expr :
  hole_Expr
  { $$ = (front_Expr)Get_sub_tree (); }
;

front :
  start_Expr
  Expr
  { front_multi_action ((void*)$2); YYACCEPT; }
;

MonExpr1 :
  hole_MonExpr1
  { $$ = (front_Expr)Get_sub_tree (); }
;

front :
  start_MonExpr1
  MonExpr1
  { front_multi_action ((void*)$2); YYACCEPT; }
;

SimpleExpr :
  hole_SimpleExpr
  { $$ = (front_Expr)Get_sub_tree (); }
;

front :
  start_SimpleExpr
  SimpleExpr
  { front_multi_action ((void*)$2); YYACCEPT; }
;

StringOrKeyword :
  hole_StringOrKeyword
  { $$ = (String)Get_sub_tree (); }
;

front :
  start_StringOrKeyword
  StringOrKeyword
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Check :
  hole_Check
  { $$ = (front_Check)Get_sub_tree (); }
;

front :
  start_Check
  Check
  { front_multi_action ((void*)$2); YYACCEPT; }
;

NameSpaceList :
  hole_NameSpaceList
  { $$ = (List_front_NameSpace)Get_sub_tree (); }
;

front :
  start_NameSpaceList
  NameSpaceList
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ExprList :
  hole_ExprList
  { $$ = (List_front_Expr)Get_sub_tree (); }
;

front :
  start_ExprList
  ExprList
  { front_multi_action ((void*)$2); YYACCEPT; }
;

IdentList :
  hole_IdentList
  { $$ = (List_Ident)Get_sub_tree (); }
;

front :
  start_IdentList
  IdentList
  { front_multi_action ((void*)$2); YYACCEPT; }
;

TypeList :
  hole_TypeList
  { $$ = (List_front_Type)Get_sub_tree (); }
;

front :
  start_TypeList
  TypeList
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Alternator :
  hole_Alternator
  { $$ = (front_Alternator)Get_sub_tree (); }
;

front :
  start_Alternator
  Alternator
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ScanInfo :
  hole_ScanInfo
  { $$ = (front_ScanInfo)Get_sub_tree (); }
;

front :
  start_ScanInfo
  ScanInfo
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Defines :
  hole_Defines
  { $$ = (front_Defines)Get_sub_tree (); }
;

front :
  start_Defines
  Defines
  { front_multi_action ((void*)$2); YYACCEPT; }
;

NameSpace :
  hole_NameSpace
  { $$ = (front_NameSpace)Get_sub_tree (); }
;

front :
  start_NameSpace
  NameSpace
  { front_multi_action ((void*)$2); YYACCEPT; }
;

Oper :
  hole_Oper
  { $$ = (Ident)Get_sub_tree (); }
;

front :
  start_Oper
  Oper
  { front_multi_action ((void*)$2); YYACCEPT; }
;

NameOrField :
  hole_NameOrField
  { $$ = (front_NameOrField)Get_sub_tree (); }
;

front :
  start_NameOrField
  NameOrField
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_USEsym_IdentList :
  hole_OPT_USEsym_IdentList
  { $$ = (List_Ident)Get_sub_tree (); }
;

front :
  start_OPT_USEsym_IdentList
  OPT_USEsym_IdentList
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_NAMESPACEsym_NameSpaceList :
  hole_OPT_NAMESPACEsym_NameSpaceList
  { $$ = (List_front_NameSpace)Get_sub_tree (); }
;

front :
  start_OPT_NAMESPACEsym_NameSpaceList
  OPT_NAMESPACEsym_NameSpaceList
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Import :
  hole_OPTMORE_Import
  { $$ = (List_front_Import)Get_sub_tree (); }
;

front :
  start_OPTMORE_Import
  OPTMORE_Import
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_NonTerminals :
  hole_OPT_NonTerminals
  { $$ = (List_front_NonTerminal)Get_sub_tree (); }
;

front :
  start_OPT_NonTerminals
  OPT_NonTerminals
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ALT_ImportedNonTerminal_SEP_commasym :
  hole_ALT_ImportedNonTerminal_SEP_commasym
  { $$ = (List_front_ImportedNonTerminal)Get_sub_tree (); }
;

front :
  start_ALT_ImportedNonTerminal_SEP_commasym
  ALT_ImportedNonTerminal_SEP_commasym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_colonsym_Identsym :
  hole_OPT_colonsym_Identsym
  { $$ = (Ident)Get_sub_tree (); }
;

front :
  start_OPT_colonsym_Identsym
  OPT_colonsym_Identsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

MORE_NonTerminal :
  hole_MORE_NonTerminal
  { $$ = (List_front_NonTerminal)Get_sub_tree (); }
;

front :
  start_MORE_NonTerminal
  MORE_NonTerminal
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_ROOTsym :
  hole_OPT_ROOTsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_ROOTsym
  OPT_ROOTsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_ScanInfo :
  hole_OPT_ScanInfo
  { $$ = (front_ScanInfo)Get_sub_tree (); }
;

front :
  start_OPT_ScanInfo
  OPT_ScanInfo
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_Super :
  hole_OPT_Super
  { $$ = (front_Super)Get_sub_tree (); }
;

front :
  start_OPT_Super
  OPT_Super
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_MEMOsym :
  hole_OPT_MEMOsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_MEMOsym
  OPT_MEMOsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_ENUMsym :
  hole_OPT_ENUMsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_ENUMsym
  OPT_ENUMsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_SKIPsym :
  hole_OPT_SKIPsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_SKIPsym
  OPT_SKIPsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Scoping :
  hole_OPTMORE_Scoping
  { $$ = (List_front_Scoping)Get_sub_tree (); }
;

front :
  start_OPTMORE_Scoping
  OPTMORE_Scoping
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_CHECKSsym_OPTMORE_Check :
  hole_OPT_CHECKSsym_OPTMORE_Check
  { $$ = (List_front_Check)Get_sub_tree (); }
;

front :
  start_OPT_CHECKSsym_OPTMORE_Check
  OPT_CHECKSsym_OPTMORE_Check
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Check :
  hole_OPTMORE_Check
  { $$ = (List_front_Check)Get_sub_tree (); }
;

front :
  start_OPTMORE_Check
  OPTMORE_Check
  { front_multi_action ((void*)$2); YYACCEPT; }
;

MORE_Symbol :
  hole_MORE_Symbol
  { $$ = (List_front_Symbol)Get_sub_tree (); }
;

front :
  start_MORE_Symbol
  MORE_Symbol
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_ScopeExpr :
  hole_OPT_ScopeExpr
  { $$ = (front_Expr)Get_sub_tree (); }
;

front :
  start_OPT_ScopeExpr
  OPT_ScopeExpr
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_WARNINGsym :
  hole_OPT_WARNINGsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_WARNINGsym
  OPT_WARNINGsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_NAMEsym_Identsym :
  hole_OPT_NAMEsym_Identsym
  { $$ = (Ident)Get_sub_tree (); }
;

front :
  start_OPT_NAMEsym_Identsym
  OPT_NAMEsym_Identsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_exclaimsym :
  hole_OPT_exclaimsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_exclaimsym
  OPT_exclaimsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_TYPEsym_Type :
  hole_OPT_TYPEsym_Type
  { $$ = (front_Type)Get_sub_tree (); }
;

front :
  start_OPT_TYPEsym_Type
  OPT_TYPEsym_Type
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_FORWARDsym :
  hole_OPT_FORWARDsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_FORWARDsym
  OPT_FORWARDsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_NAMESPACEsym_Identsym :
  hole_OPT_NAMESPACEsym_Identsym
  { $$ = (Ident)Get_sub_tree (); }
;

front :
  start_OPT_NAMESPACEsym_Identsym
  OPT_NAMESPACEsym_Identsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_TRAVERSEsym :
  hole_OPT_TRAVERSEsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_TRAVERSEsym
  OPT_TRAVERSEsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_CLEARsym :
  hole_OPT_CLEARsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_CLEARsym
  OPT_CLEARsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_DONT_CLEARsym :
  hole_OPT_DONT_CLEARsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_DONT_CLEARsym
  OPT_DONT_CLEARsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ALT_FieldInit_SEP_commasym :
  hole_ALT_FieldInit_SEP_commasym
  { $$ = (List_front_FieldInit)Get_sub_tree (); }
;

front :
  start_ALT_FieldInit_SEP_commasym
  ALT_FieldInit_SEP_commasym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_CREATEsym :
  hole_OPT_CREATEsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_CREATEsym
  OPT_CREATEsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_openparsym_TypeList_closeparsym :
  hole_OPT_openparsym_TypeList_closeparsym
  { $$ = (List_front_Type)Get_sub_tree (); }
;

front :
  start_OPT_openparsym_TypeList_closeparsym
  OPT_openparsym_TypeList_closeparsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Oper :
  hole_OPTMORE_Oper
  { $$ = (List_Ident)Get_sub_tree (); }
;

front :
  start_OPTMORE_Oper
  OPTMORE_Oper
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_ExprList :
  hole_OPT_ExprList
  { $$ = (List_front_Expr)Get_sub_tree (); }
;

front :
  start_OPT_ExprList
  OPT_ExprList
  { front_multi_action ((void*)$2); YYACCEPT; }
;

MORE_MonExpr1 :
  hole_MORE_MonExpr1
  { $$ = (List_front_Expr)Get_sub_tree (); }
;

front :
  start_MORE_MonExpr1
  MORE_MonExpr1
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ALT_NameSpace_SEP_commasym_SP :
  hole_ALT_NameSpace_SEP_commasym_SP
  { $$ = (List_front_NameSpace)Get_sub_tree (); }
;

front :
  start_ALT_NameSpace_SEP_commasym_SP
  ALT_NameSpace_SEP_commasym_SP
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ALT_Expr_SEP_commasym_SP :
  hole_ALT_Expr_SEP_commasym_SP
  { $$ = (List_front_Expr)Get_sub_tree (); }
;

front :
  start_ALT_Expr_SEP_commasym_SP
  ALT_Expr_SEP_commasym_SP
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ALT_Identsym_SEP_commasym_SP :
  hole_ALT_Identsym_SEP_commasym_SP
  { $$ = (List_Ident)Get_sub_tree (); }
;

front :
  start_ALT_Identsym_SEP_commasym_SP
  ALT_Identsym_SEP_commasym_SP
  { front_multi_action ((void*)$2); YYACCEPT; }
;

ALT_Type_SEP_commasym_SP :
  hole_ALT_Type_SEP_commasym_SP
  { $$ = (List_front_Type)Get_sub_tree (); }
;

front :
  start_ALT_Type_SEP_commasym_SP
  ALT_Type_SEP_commasym_SP
  { front_multi_action ((void*)$2); YYACCEPT; }
;

OPT_COMMENTsym :
  hole_OPT_COMMENTsym
  { $$ = (Bool)Get_sub_tree (); }
;

front :
  start_OPT_COMMENTsym
  OPT_COMMENTsym
  { front_multi_action ((void*)$2); YYACCEPT; }
;

