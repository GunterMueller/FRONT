#include "front_lalr.h"

#include "front_y.h"

typedef enum {
  front_NONSENSE,
  FROMsym_value,
  Identsym_value,
  colonsym_value,
  semicolonsym_value,
  lessthansym_value,
  SCOPEsym_value,
  OPENSCOPEsym_value,
  CLOSESCOPEsym_value,
  greaterthansym_value,
  definessym_value,
  Newlinesym_value,
  LeftAndsym_value,
  RightAndsym_value,
  verticalbarsym_value,
  LeftOrsym_value,
  RightOrsym_value,
  Xorsym_value,
  COMPAREsym_value,
  APPLIEDsym_value,
  Stringsym_value,
  Charsym_value,
  Keywordsym_value,
  open2symsym_value,
  closeparsym_value,
  openbrksym_value,
  closebrksym_value,
  openchainsym_value,
  closechainsym_value,
  plussym_value,
  EMPTYsym_value,
  backslashbackslashsym_value,
  LAYOUTsym_value,
  openparsym_value,
  DEFININGsym_value,
  REDEFININGsym_value,
  OVERLOADINGsym_value,
  equalssym_value,
  CHECKSsym_value,
  dotsym_value,
  Intsym_value,
  Boolsym_value,
  NULLsym_value,
  IFsym_value,
  THENsym_value,
  alternate_leftsym_value,
  alternate_rightsym_value,
  SCANsym_value,
  tildasym_value,
  exclaimsym_value,
  equalsequalssym_value,
  exclaimequalssym_value,
  lessthanequalssym_value,
  greaterthanequalssym_value,
  ampersandsym_value,
  ampersandampersandsym_value,
  verticalbarverticalbarsym_value,
  hatsym_value,
  minussym_value,
  starsym_value,
  slashsym_value,
  percentsym_value,
  lessthanlessthansym_value,
  greaterthangreaterthansym_value,
  NAMEsym_value,
  FIELDsym_value,
  USEsym_value,
  NAMESPACEsym_value,
  commasym_value,
  ROOTsym_value,
  MEMOsym_value,
  ENUMsym_value,
  SKIPsym_value,
  WARNINGsym_value,
  TYPEsym_value,
  FORWARDsym_value,
  TRAVERSEsym_value,
  CLEARsym_value,
  DONT_CLEARsym_value,
  CREATEsym_value,
  COMMENTsym_value,
  hole_OPTMORE_Import_value,
  hole_front_value,
  hole_ImportedNonTerminals_value,
  hole_Import_value,
  hole_ALT_ImportedNonTerminal_SEP_commasym_value,
  hole_ImportedNonTerminal_value,
  hole_MORE_NonTerminal_value,
  hole_NonTerminals_value,
  hole_Defines_value,
  hole_Rhs_value,
  hole_NonTerminal_value,
  hole_Super_value,
  hole_OPTMORE_Scoping_value,
  hole_Symbol1_value,
  hole_Scoping_value,
  hole_Alternative_value,
  hole_Symbol2_value,
  hole_Symbol_value,
  hole_AltSymbol_value,
  hole_SymbolSeq_value,
  hole_Alternator_value,
  hole_MORE_Symbol_value,
  hole_And_value,
  hole_Or_value,
  hole_SimpleSymbol_value,
  hole_DefiningSym_value,
  hole_IdSym_value,
  hole_NameOrField_value,
  hole_OptType_value,
  hole_StringOrKeyword_value,
  hole_Expr_value,
  hole_Define_value,
  hole_Defining_id_value,
  hole_ScopeExpr_value,
  hole_Type_value,
  hole_FieldInits_value,
  hole_Field_value,
  hole_ALT_FieldInit_SEP_commasym_value,
  hole_FieldInit_value,
  hole_OPTMORE_Oper_value,
  hole_SimpleExpr_value,
  hole_MonExpr1_value,
  hole_MORE_MonExpr1_value,
  hole_Check_value,
  hole_ALT_NameSpace_SEP_commasym_SP_value,
  hole_NameSpaceList_value,
  hole_ALT_Expr_SEP_commasym_SP_value,
  hole_ExprList_value,
  hole_ALT_Identsym_SEP_commasym_SP_value,
  hole_IdentList_value,
  hole_ALT_Type_SEP_commasym_SP_value,
  hole_TypeList_value,
  hole_ScanInfo_value,
  hole_NameSpace_value,
  hole_Oper_value,
  hole_OPTMORE_Check_value,
  front_EOF_value,
  OPT_USEsym_IdentList_value,
  OPT_NAMESPACEsym_NameSpaceList_value,
  OPTMORE_Import_value,
  OPT_NonTerminals_value,
  front_value,
  ImportedNonTerminals_value,
  Import_value,
  ALT_ImportedNonTerminal_SEP_commasym_value,
  OPT_colonsym_Identsym_value,
  ImportedNonTerminal_value,
  MORE_NonTerminal_value,
  NonTerminals_value,
  OPT_ROOTsym_value,
  OPT_ScanInfo_value,
  OPT_Super_value,
  OPT_MEMOsym_value,
  OPT_ENUMsym_value,
  OPT_SKIPsym_value,
  Defines_value,
  Rhs_value,
  NonTerminal_value,
  Super_value,
  OPTMORE_Scoping_value,
  Symbol1_value,
  OPT_Choices_value,
  OPT_CHECKSsym_OPTMORE_Check_value,
  Scoping_value,
  ChoiceList_value,
  Choices_value,
  ALT_Alternative_SEP_Or_value,
  Alternative_value,
  Symbol2_value,
  Symbol_value,
  AltSymbol_value,
  SymbolSeq_value,
  Alternator_value,
  MORE_Symbol_value,
  OPT_ALT_ONCE_SymbolORField_SEP_And_value,
  And_value,
  Or_value,
  SimpleSymbol_value,
  DefiningSym_value,
  IdSym_value,
  NameOrField_value,
  OPT_ScopeExpr_value,
  OPT_WARNINGsym_value,
  OPT_NAMEsym_Identsym_value,
  OptType_value,
  Alternatives_value,
  OPT_exclaimsym_value,
  StringOrKeyword_value,
  Expr_value,
  ALT_Symbol1_SEP_Or_SP_value,
  OPT_TYPEsym_Type_value,
  OPT_FORWARDsym_value,
  Define_value,
  Defining_id_value,
  OPT_NAMESPACEsym_Identsym_value,
  ScopeExpr_value,
  Type_value,
  FieldInits_value,
  OPT_TRAVERSEsym_value,
  OPT_CLEARsym_value,
  OPT_DONT_CLEARsym_value,
  Field_value,
  ALT_FieldInit_SEP_commasym_value,
  OPT_CREATEsym_value,
  FieldInit_value,
  OPT_openparsym_TypeList_closeparsym_value,
  ALT_MonExpr1_SEP_SP_Oper_value,
  OPTMORE_Oper_value,
  SimpleExpr_value,
  MonExpr1_value,
  OPT_ExprList_value,
  MORE_MonExpr1_value,
  Check_value,
  ALT_NameSpace_SEP_commasym_SP_value,
  NameSpaceList_value,
  ALT_Expr_SEP_commasym_SP_value,
  ExprList_value,
  ALT_Identsym_SEP_commasym_SP_value,
  IdentList_value,
  ALT_Type_SEP_commasym_SP_value,
  TypeList_value,
  OPT_COMMENTsym_value,
  ScanInfo_value,
  NameSpace_value,
  Oper_value,
  OPTMORE_Check_value,
  ALT_ONCE_SymbolORField_SEP_And_value,
  ONCE_SymbolORField_value,
  front_ERROR
} frontSymbol;

static frontSymbol _front_token;

static frontSymbol _front_symbol;

#define NUM_TERMINALS 138

#define WORDS_IN_SET ((NUM_TERMINALS+BITSPERWORD-1)/BITSPERWORD)

static String front_symbol_names[] = {
  "front_NONSENSE",
  "FROMsym",
  "Identsym",
  "colonsym",
  "semicolonsym",
  "lessthansym",
  "SCOPEsym",
  "OPENSCOPEsym",
  "CLOSESCOPEsym",
  "greaterthansym",
  "definessym",
  "Newlinesym",
  "LeftAndsym",
  "RightAndsym",
  "verticalbarsym",
  "LeftOrsym",
  "RightOrsym",
  "Xorsym",
  "COMPAREsym",
  "APPLIEDsym",
  "Stringsym",
  "Charsym",
  "Keywordsym",
  "open2symsym",
  "closeparsym",
  "openbrksym",
  "closebrksym",
  "openchainsym",
  "closechainsym",
  "plussym",
  "EMPTYsym",
  "backslashbackslashsym",
  "LAYOUTsym",
  "openparsym",
  "DEFININGsym",
  "REDEFININGsym",
  "OVERLOADINGsym",
  "equalssym",
  "CHECKSsym",
  "dotsym",
  "Intsym",
  "Boolsym",
  "NULLsym",
  "IFsym",
  "THENsym",
  "alternate_leftsym",
  "alternate_rightsym",
  "SCANsym",
  "tildasym",
  "exclaimsym",
  "equalsequalssym",
  "exclaimequalssym",
  "lessthanequalssym",
  "greaterthanequalssym",
  "ampersandsym",
  "ampersandampersandsym",
  "verticalbarverticalbarsym",
  "hatsym",
  "minussym",
  "starsym",
  "slashsym",
  "percentsym",
  "lessthanlessthansym",
  "greaterthangreaterthansym",
  "NAMEsym",
  "FIELDsym",
  "USEsym",
  "NAMESPACEsym",
  "commasym",
  "ROOTsym",
  "MEMOsym",
  "ENUMsym",
  "SKIPsym",
  "WARNINGsym",
  "TYPEsym",
  "FORWARDsym",
  "TRAVERSEsym",
  "CLEARsym",
  "DONT_CLEARsym",
  "CREATEsym",
  "COMMENTsym",
  "hole_OPTMORE_Import",
  "hole_front",
  "hole_ImportedNonTerminals",
  "hole_Import",
  "hole_ALT_ImportedNonTerminal_SEP_commasym",
  "hole_ImportedNonTerminal",
  "hole_MORE_NonTerminal",
  "hole_NonTerminals",
  "hole_Defines",
  "hole_Rhs",
  "hole_NonTerminal",
  "hole_Super",
  "hole_OPTMORE_Scoping",
  "hole_Symbol1",
  "hole_Scoping",
  "hole_Alternative",
  "hole_Symbol2",
  "hole_Symbol",
  "hole_AltSymbol",
  "hole_SymbolSeq",
  "hole_Alternator",
  "hole_MORE_Symbol",
  "hole_And",
  "hole_Or",
  "hole_SimpleSymbol",
  "hole_DefiningSym",
  "hole_IdSym",
  "hole_NameOrField",
  "hole_OptType",
  "hole_StringOrKeyword",
  "hole_Expr",
  "hole_Define",
  "hole_Defining_id",
  "hole_ScopeExpr",
  "hole_Type",
  "hole_FieldInits",
  "hole_Field",
  "hole_ALT_FieldInit_SEP_commasym",
  "hole_FieldInit",
  "hole_OPTMORE_Oper",
  "hole_SimpleExpr",
  "hole_MonExpr1",
  "hole_MORE_MonExpr1",
  "hole_Check",
  "hole_ALT_NameSpace_SEP_commasym_SP",
  "hole_NameSpaceList",
  "hole_ALT_Expr_SEP_commasym_SP",
  "hole_ExprList",
  "hole_ALT_Identsym_SEP_commasym_SP",
  "hole_IdentList",
  "hole_ALT_Type_SEP_commasym_SP",
  "hole_TypeList",
  "hole_ScanInfo",
  "hole_NameSpace",
  "hole_Oper",
  "hole_OPTMORE_Check",
  "front_EOF",
  "OPT_USEsym_IdentList",
  "OPT_NAMESPACEsym_NameSpaceList",
  "OPTMORE_Import",
  "OPT_NonTerminals",
  "front",
  "ImportedNonTerminals",
  "Import",
  "ALT_ImportedNonTerminal_SEP_commasym",
  "OPT_colonsym_Identsym",
  "ImportedNonTerminal",
  "MORE_NonTerminal",
  "NonTerminals",
  "OPT_ROOTsym",
  "OPT_ScanInfo",
  "OPT_Super",
  "OPT_MEMOsym",
  "OPT_ENUMsym",
  "OPT_SKIPsym",
  "Defines",
  "Rhs",
  "NonTerminal",
  "Super",
  "OPTMORE_Scoping",
  "Symbol1",
  "OPT_Choices",
  "OPT_CHECKSsym_OPTMORE_Check",
  "Scoping",
  "ChoiceList",
  "Choices",
  "ALT_Alternative_SEP_Or",
  "Alternative",
  "Symbol2",
  "Symbol",
  "AltSymbol",
  "SymbolSeq",
  "Alternator",
  "MORE_Symbol",
  "OPT_ALT_ONCE_SymbolORField_SEP_And",
  "And",
  "Or",
  "SimpleSymbol",
  "DefiningSym",
  "IdSym",
  "NameOrField",
  "OPT_ScopeExpr",
  "OPT_WARNINGsym",
  "OPT_NAMEsym_Identsym",
  "OptType",
  "Alternatives",
  "OPT_exclaimsym",
  "StringOrKeyword",
  "Expr",
  "ALT_Symbol1_SEP_Or_SP",
  "OPT_TYPEsym_Type",
  "OPT_FORWARDsym",
  "Define",
  "Defining_id",
  "OPT_NAMESPACEsym_Identsym",
  "ScopeExpr",
  "Type",
  "FieldInits",
  "OPT_TRAVERSEsym",
  "OPT_CLEARsym",
  "OPT_DONT_CLEARsym",
  "Field",
  "ALT_FieldInit_SEP_commasym",
  "OPT_CREATEsym",
  "FieldInit",
  "OPT_openparsym_TypeList_closeparsym",
  "ALT_MonExpr1_SEP_SP_Oper",
  "OPTMORE_Oper",
  "SimpleExpr",
  "MonExpr1",
  "OPT_ExprList",
  "MORE_MonExpr1",
  "Check",
  "ALT_NameSpace_SEP_commasym_SP",
  "NameSpaceList",
  "ALT_Expr_SEP_commasym_SP",
  "ExprList",
  "ALT_Identsym_SEP_commasym_SP",
  "IdentList",
  "ALT_Type_SEP_commasym_SP",
  "TypeList",
  "OPT_COMMENTsym",
  "ScanInfo",
  "NameSpace",
  "Oper",
  "OPTMORE_Check",
  "ALT_ONCE_SymbolORField_SEP_And",
  "ONCE_SymbolORField",
  "front_ERROR"
};

static frontSymbol front_terminal_map[2*front_ERROR];

static void fill_terminal_map (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;
  front_terminal_map[0] = front_NONSENSE;
  front_terminal_map[FROMsym-NONSENSE] = FROMsym_value;
  front_terminal_map[Identsym-NONSENSE] = Identsym_value;
  front_terminal_map[colonsym-NONSENSE] = colonsym_value;
  front_terminal_map[semicolonsym-NONSENSE] = semicolonsym_value;
  front_terminal_map[lessthansym-NONSENSE] = lessthansym_value;
  front_terminal_map[SCOPEsym-NONSENSE] = SCOPEsym_value;
  front_terminal_map[OPENSCOPEsym-NONSENSE] = OPENSCOPEsym_value;
  front_terminal_map[CLOSESCOPEsym-NONSENSE] = CLOSESCOPEsym_value;
  front_terminal_map[greaterthansym-NONSENSE] = greaterthansym_value;
  front_terminal_map[definessym-NONSENSE] = definessym_value;
  front_terminal_map[Newlinesym-NONSENSE] = Newlinesym_value;
  front_terminal_map[LeftAndsym-NONSENSE] = LeftAndsym_value;
  front_terminal_map[RightAndsym-NONSENSE] = RightAndsym_value;
  front_terminal_map[verticalbarsym-NONSENSE] = verticalbarsym_value;
  front_terminal_map[LeftOrsym-NONSENSE] = LeftOrsym_value;
  front_terminal_map[RightOrsym-NONSENSE] = RightOrsym_value;
  front_terminal_map[Xorsym-NONSENSE] = Xorsym_value;
  front_terminal_map[COMPAREsym-NONSENSE] = COMPAREsym_value;
  front_terminal_map[APPLIEDsym-NONSENSE] = APPLIEDsym_value;
  front_terminal_map[Stringsym-NONSENSE] = Stringsym_value;
  front_terminal_map[Charsym-NONSENSE] = Charsym_value;
  front_terminal_map[Keywordsym-NONSENSE] = Keywordsym_value;
  front_terminal_map[open2symsym-NONSENSE] = open2symsym_value;
  front_terminal_map[closeparsym-NONSENSE] = closeparsym_value;
  front_terminal_map[openbrksym-NONSENSE] = openbrksym_value;
  front_terminal_map[closebrksym-NONSENSE] = closebrksym_value;
  front_terminal_map[openchainsym-NONSENSE] = openchainsym_value;
  front_terminal_map[closechainsym-NONSENSE] = closechainsym_value;
  front_terminal_map[plussym-NONSENSE] = plussym_value;
  front_terminal_map[EMPTYsym-NONSENSE] = EMPTYsym_value;
  front_terminal_map[backslashbackslashsym-NONSENSE] = backslashbackslashsym_value;
  front_terminal_map[LAYOUTsym-NONSENSE] = LAYOUTsym_value;
  front_terminal_map[openparsym-NONSENSE] = openparsym_value;
  front_terminal_map[DEFININGsym-NONSENSE] = DEFININGsym_value;
  front_terminal_map[REDEFININGsym-NONSENSE] = REDEFININGsym_value;
  front_terminal_map[OVERLOADINGsym-NONSENSE] = OVERLOADINGsym_value;
  front_terminal_map[equalssym-NONSENSE] = equalssym_value;
  front_terminal_map[CHECKSsym-NONSENSE] = CHECKSsym_value;
  front_terminal_map[dotsym-NONSENSE] = dotsym_value;
  front_terminal_map[Intsym-NONSENSE] = Intsym_value;
  front_terminal_map[Boolsym-NONSENSE] = Boolsym_value;
  front_terminal_map[NULLsym-NONSENSE] = NULLsym_value;
  front_terminal_map[IFsym-NONSENSE] = IFsym_value;
  front_terminal_map[THENsym-NONSENSE] = THENsym_value;
  front_terminal_map[alternate_leftsym-NONSENSE] = alternate_leftsym_value;
  front_terminal_map[alternate_rightsym-NONSENSE] = alternate_rightsym_value;
  front_terminal_map[SCANsym-NONSENSE] = SCANsym_value;
  front_terminal_map[tildasym-NONSENSE] = tildasym_value;
  front_terminal_map[exclaimsym-NONSENSE] = exclaimsym_value;
  front_terminal_map[equalsequalssym-NONSENSE] = equalsequalssym_value;
  front_terminal_map[exclaimequalssym-NONSENSE] = exclaimequalssym_value;
  front_terminal_map[lessthanequalssym-NONSENSE] = lessthanequalssym_value;
  front_terminal_map[greaterthanequalssym-NONSENSE] = greaterthanequalssym_value;
  front_terminal_map[ampersandsym-NONSENSE] = ampersandsym_value;
  front_terminal_map[ampersandampersandsym-NONSENSE] = ampersandampersandsym_value;
  front_terminal_map[verticalbarverticalbarsym-NONSENSE] = verticalbarverticalbarsym_value;
  front_terminal_map[hatsym-NONSENSE] = hatsym_value;
  front_terminal_map[minussym-NONSENSE] = minussym_value;
  front_terminal_map[starsym-NONSENSE] = starsym_value;
  front_terminal_map[slashsym-NONSENSE] = slashsym_value;
  front_terminal_map[percentsym-NONSENSE] = percentsym_value;
  front_terminal_map[lessthanlessthansym-NONSENSE] = lessthanlessthansym_value;
  front_terminal_map[greaterthangreaterthansym-NONSENSE] = greaterthangreaterthansym_value;
  front_terminal_map[NAMEsym-NONSENSE] = NAMEsym_value;
  front_terminal_map[FIELDsym-NONSENSE] = FIELDsym_value;
  front_terminal_map[USEsym-NONSENSE] = USEsym_value;
  front_terminal_map[NAMESPACEsym-NONSENSE] = NAMESPACEsym_value;
  front_terminal_map[commasym-NONSENSE] = commasym_value;
  front_terminal_map[ROOTsym-NONSENSE] = ROOTsym_value;
  front_terminal_map[MEMOsym-NONSENSE] = MEMOsym_value;
  front_terminal_map[ENUMsym-NONSENSE] = ENUMsym_value;
  front_terminal_map[SKIPsym-NONSENSE] = SKIPsym_value;
  front_terminal_map[WARNINGsym-NONSENSE] = WARNINGsym_value;
  front_terminal_map[TYPEsym-NONSENSE] = TYPEsym_value;
  front_terminal_map[FORWARDsym-NONSENSE] = FORWARDsym_value;
  front_terminal_map[TRAVERSEsym-NONSENSE] = TRAVERSEsym_value;
  front_terminal_map[CLEARsym-NONSENSE] = CLEARsym_value;
  front_terminal_map[DONT_CLEARsym-NONSENSE] = DONT_CLEARsym_value;
  front_terminal_map[CREATEsym-NONSENSE] = CREATEsym_value;
  front_terminal_map[COMMENTsym-NONSENSE] = COMMENTsym_value;
  front_terminal_map[hole_OPTMORE_Import-NONSENSE] = hole_OPTMORE_Import_value;
  front_terminal_map[hole_front-NONSENSE] = hole_front_value;
  front_terminal_map[hole_ImportedNonTerminals-NONSENSE] = hole_ImportedNonTerminals_value;
  front_terminal_map[hole_Import-NONSENSE] = hole_Import_value;
  front_terminal_map[hole_ALT_ImportedNonTerminal_SEP_commasym-NONSENSE] = hole_ALT_ImportedNonTerminal_SEP_commasym_value;
  front_terminal_map[hole_ImportedNonTerminal-NONSENSE] = hole_ImportedNonTerminal_value;
  front_terminal_map[hole_MORE_NonTerminal-NONSENSE] = hole_MORE_NonTerminal_value;
  front_terminal_map[hole_NonTerminals-NONSENSE] = hole_NonTerminals_value;
  front_terminal_map[hole_Defines-NONSENSE] = hole_Defines_value;
  front_terminal_map[hole_Rhs-NONSENSE] = hole_Rhs_value;
  front_terminal_map[hole_NonTerminal-NONSENSE] = hole_NonTerminal_value;
  front_terminal_map[hole_Super-NONSENSE] = hole_Super_value;
  front_terminal_map[hole_OPTMORE_Scoping-NONSENSE] = hole_OPTMORE_Scoping_value;
  front_terminal_map[hole_Symbol1-NONSENSE] = hole_Symbol1_value;
  front_terminal_map[hole_Scoping-NONSENSE] = hole_Scoping_value;
  front_terminal_map[hole_Alternative-NONSENSE] = hole_Alternative_value;
  front_terminal_map[hole_Symbol2-NONSENSE] = hole_Symbol2_value;
  front_terminal_map[hole_Symbol-NONSENSE] = hole_Symbol_value;
  front_terminal_map[hole_AltSymbol-NONSENSE] = hole_AltSymbol_value;
  front_terminal_map[hole_SymbolSeq-NONSENSE] = hole_SymbolSeq_value;
  front_terminal_map[hole_Alternator-NONSENSE] = hole_Alternator_value;
  front_terminal_map[hole_MORE_Symbol-NONSENSE] = hole_MORE_Symbol_value;
  front_terminal_map[hole_And-NONSENSE] = hole_And_value;
  front_terminal_map[hole_Or-NONSENSE] = hole_Or_value;
  front_terminal_map[hole_SimpleSymbol-NONSENSE] = hole_SimpleSymbol_value;
  front_terminal_map[hole_DefiningSym-NONSENSE] = hole_DefiningSym_value;
  front_terminal_map[hole_IdSym-NONSENSE] = hole_IdSym_value;
  front_terminal_map[hole_NameOrField-NONSENSE] = hole_NameOrField_value;
  front_terminal_map[hole_OptType-NONSENSE] = hole_OptType_value;
  front_terminal_map[hole_StringOrKeyword-NONSENSE] = hole_StringOrKeyword_value;
  front_terminal_map[hole_Expr-NONSENSE] = hole_Expr_value;
  front_terminal_map[hole_Define-NONSENSE] = hole_Define_value;
  front_terminal_map[hole_Defining_id-NONSENSE] = hole_Defining_id_value;
  front_terminal_map[hole_ScopeExpr-NONSENSE] = hole_ScopeExpr_value;
  front_terminal_map[hole_Type-NONSENSE] = hole_Type_value;
  front_terminal_map[hole_FieldInits-NONSENSE] = hole_FieldInits_value;
  front_terminal_map[hole_Field-NONSENSE] = hole_Field_value;
  front_terminal_map[hole_ALT_FieldInit_SEP_commasym-NONSENSE] = hole_ALT_FieldInit_SEP_commasym_value;
  front_terminal_map[hole_FieldInit-NONSENSE] = hole_FieldInit_value;
  front_terminal_map[hole_OPTMORE_Oper-NONSENSE] = hole_OPTMORE_Oper_value;
  front_terminal_map[hole_SimpleExpr-NONSENSE] = hole_SimpleExpr_value;
  front_terminal_map[hole_MonExpr1-NONSENSE] = hole_MonExpr1_value;
  front_terminal_map[hole_MORE_MonExpr1-NONSENSE] = hole_MORE_MonExpr1_value;
  front_terminal_map[hole_Check-NONSENSE] = hole_Check_value;
  front_terminal_map[hole_ALT_NameSpace_SEP_commasym_SP-NONSENSE] = hole_ALT_NameSpace_SEP_commasym_SP_value;
  front_terminal_map[hole_NameSpaceList-NONSENSE] = hole_NameSpaceList_value;
  front_terminal_map[hole_ALT_Expr_SEP_commasym_SP-NONSENSE] = hole_ALT_Expr_SEP_commasym_SP_value;
  front_terminal_map[hole_ExprList-NONSENSE] = hole_ExprList_value;
  front_terminal_map[hole_ALT_Identsym_SEP_commasym_SP-NONSENSE] = hole_ALT_Identsym_SEP_commasym_SP_value;
  front_terminal_map[hole_IdentList-NONSENSE] = hole_IdentList_value;
  front_terminal_map[hole_ALT_Type_SEP_commasym_SP-NONSENSE] = hole_ALT_Type_SEP_commasym_SP_value;
  front_terminal_map[hole_TypeList-NONSENSE] = hole_TypeList_value;
  front_terminal_map[hole_ScanInfo-NONSENSE] = hole_ScanInfo_value;
  front_terminal_map[hole_NameSpace-NONSENSE] = hole_NameSpace_value;
  front_terminal_map[hole_Oper-NONSENSE] = hole_Oper_value;
  front_terminal_map[hole_OPTMORE_Check-NONSENSE] = hole_OPTMORE_Check_value;
}

extern int front_lex(void);
#define SHIFT() { _front_token = front_lex(); if (_front_token==0) _front_token = front_EOF_value; else _front_token = front_terminal_map[_front_token-NONSENSE]; }
#define HOLE_ACTION(term,s) PUSH_PARSEVALUE(Pointer,Get_sub_tree(),hole); SHIFT()
#ifdef TRACE_front_PARSE
#define REPORT(n) \
    printf ("State %d,	symbol %s,	token %s\n", n, front_symbol_names[_front_symbol], front_symbol_names[_front_token]);
#else
#define REPORT(n)
#endif
#if !defined(__GNUC__)
# define __inline__
#endif
List_front_Import Parse_state_front_OPTMORE_Import (void);	/* state 0 */
static int Parse_state_1 (SymbolSet followers);	/* state 1 */
static int Parse_state_2 (SymbolSet followers);	/* state 2 */
static int Parse_state_3 (SymbolSet followers);	/* state 3 */
static int Parse_state_4 (SymbolSet followers);	/* state 4 */
static int Parse_state_5 (SymbolSet followers);	/* state 5 */

static __inline__ int Parse_state_6 (void)	/* state 6 */
{ int n;
      n = 2; _front_symbol = OPT_colonsym_Identsym_value;
      { /* opt action */
        Ident  type = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,type,Ident);
      }
  return n-1;
}


static __inline__ int Parse_state_7 (void)	/* state 7 */
{ int n;
      n = 2; _front_symbol = ImportedNonTerminal_value;
      { ParseValue me;
        Ident  type = POP_PARSEVALUE (Ident, Ident);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_ImportedNonTerminal");
        me->sub.PointerValue = Create_front_ImportedNonTerminal(src_info, id, type);
      }
  return n-1;
}

static int Parse_state_8 (SymbolSet followers);	/* state 8 */
static int Parse_state_9 (SymbolSet followers);	/* state 9 */

static __inline__ int Parse_state_10 (void)	/* state 10 */
{ int n;
      n = 3; _front_symbol = ALT_ImportedNonTerminal_SEP_commasym_value;
      { /* alt action */
        List_front_ImportedNonTerminal  _id_0_l = POP_PARSEVALUE (Pointer, List_front_ImportedNonTerminal);
        front_ImportedNonTerminal  _id_0 = POP_PARSEVALUE (Pointer, front_ImportedNonTerminal);
        PUSH_PARSEVALUE(Pointer,Create_List_front_ImportedNonTerminal(_id_0,_id_0_l),List_front_ImportedNonTerminal);
      }
  return n-1;
}


static __inline__ int Parse_state_11 (void)	/* state 11 */
{ int n;
      n = 1; _front_symbol = ImportedNonTerminals_value;
  return n-1;
}


static __inline__ int Parse_state_12 (void)	/* state 12 */
{ int n;
      n = 4; _front_symbol = Import_value;
      { ParseValue me;
        List_front_ImportedNonTerminal  _id_0 = POP_PARSEVALUE (Pointer, List_front_ImportedNonTerminal);
        Ident  grammar = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Import");
        me->sub.PointerValue = Create_front_Import(src_info, grammar, _id_0);
      }
  return n-1;
}

static int Parse_state_13 (SymbolSet followers);	/* state 13 */

static __inline__ int Parse_state_14 (void)	/* state 14 */
{ int n;
      n = 2; _front_symbol = OPTMORE_Import_value;
      { /* optmore action */
        List_front_Import  imports_l = POP_PARSEVALUE (Pointer, List_front_Import);
        front_Import  imports = POP_PARSEVALUE (Pointer, front_Import);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Import(imports,imports_l),List_front_Import);
      }
  return n-1;
}

front_front Parse_state_front_front (void);	/* state 15 */
static int Parse_state_16 (SymbolSet followers);	/* state 16 */
static int Parse_state_17 (SymbolSet followers);	/* state 17 */
static int Parse_state_18 (SymbolSet followers);	/* state 18 */

static __inline__ int Parse_state_19 (void)	/* state 19 */
{ int n;
      n = 3; _front_symbol = ALT_Identsym_SEP_commasym_SP_value;
      { /* alt action */
        List_Ident  ids_l = POP_PARSEVALUE (Pointer, List_Ident);
        Ident  ids = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,Create_List_Ident(ids,ids_l),List_Ident);
      }
  return n-1;
}


static __inline__ int Parse_state_20 (void)	/* state 20 */
{ int n;
      n = 1; _front_symbol = IdentList_value;
  return n-1;
}


static __inline__ int Parse_state_21 (void)	/* state 21 */
{ int n;
      n = 2; _front_symbol = OPT_USEsym_IdentList_value;
      { /* opt action */
        List_Ident  ids = POP_PARSEVALUE (Pointer, List_Ident);
        PUSH_PARSEVALUE(Pointer,ids,List_Ident);
      }
  return n-1;
}

static int Parse_state_22 (SymbolSet followers);	/* state 22 */
static int Parse_state_23 (SymbolSet followers);	/* state 23 */

static __inline__ int Parse_state_24 (void)	/* state 24 */
{ int n;
      n = 1; _front_symbol = NameSpace_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_NameSpace");
        me->sub.PointerValue = Create_front_NameSpace(src_info, id);
      }
  return n-1;
}

static int Parse_state_25 (SymbolSet followers);	/* state 25 */
static int Parse_state_26 (SymbolSet followers);	/* state 26 */

static __inline__ int Parse_state_27 (void)	/* state 27 */
{ int n;
      n = 3; _front_symbol = ALT_NameSpace_SEP_commasym_SP_value;
      { /* alt action */
        List_front_NameSpace  namespace_l = POP_PARSEVALUE (Pointer, List_front_NameSpace);
        front_NameSpace  namespace = POP_PARSEVALUE (Pointer, front_NameSpace);
        PUSH_PARSEVALUE(Pointer,Create_List_front_NameSpace(namespace,namespace_l),List_front_NameSpace);
      }
  return n-1;
}


static __inline__ int Parse_state_28 (void)	/* state 28 */
{ int n;
      n = 1; _front_symbol = NameSpaceList_value;
  return n-1;
}


static __inline__ int Parse_state_29 (void)	/* state 29 */
{ int n;
      n = 2; _front_symbol = OPT_NAMESPACEsym_NameSpaceList_value;
      { /* opt action */
        List_front_NameSpace  namespace = POP_PARSEVALUE (Pointer, List_front_NameSpace);
        PUSH_PARSEVALUE(Pointer,namespace,List_front_NameSpace);
      }
  return n-1;
}

static int Parse_state_30 (SymbolSet followers);	/* state 30 */
static int Parse_state_31 (SymbolSet followers);	/* state 31 */

static __inline__ int Parse_state_32 (void)	/* state 32 */
{ int n;
      n = 1; _front_symbol = OPT_ROOTsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_33 (SymbolSet followers);	/* state 33 */
static int Parse_state_34 (SymbolSet followers);	/* state 34 */
static int Parse_state_35 (SymbolSet followers);	/* state 35 */
static int Parse_state_36 (SymbolSet followers);	/* state 36 */
static int Parse_state_37 (SymbolSet followers);	/* state 37 */
static int Parse_state_38 (SymbolSet followers);	/* state 38 */
static int Parse_state_39 (SymbolSet followers);	/* state 39 */

static __inline__ int Parse_state_40 (void)	/* state 40 */
{ int n;
      n = 3; _front_symbol = ALT_Type_SEP_commasym_SP_value;
      { /* alt action */
        List_front_Type  types_l = POP_PARSEVALUE (Pointer, List_front_Type);
        front_Type  types = POP_PARSEVALUE (Pointer, front_Type);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Type(types,types_l),List_front_Type);
      }
  return n-1;
}


static __inline__ int Parse_state_41 (void)	/* state 41 */
{ int n;
      n = 1; _front_symbol = TypeList_value;
  return n-1;
}

static int Parse_state_42 (void);	/* state 42 */

static __inline__ int Parse_state_43 (void)	/* state 43 */
{ int n;
      n = 3; _front_symbol = OPT_openparsym_TypeList_closeparsym_value;
      { /* opt action */
        List_front_Type  types = POP_PARSEVALUE (Pointer, List_front_Type);
        PUSH_PARSEVALUE(Pointer,types,List_front_Type);
      }
  return n-1;
}


static __inline__ int Parse_state_44 (void)	/* state 44 */
{ int n;
      n = 2; _front_symbol = Type_value;
      { ParseValue me;
        List_front_Type  types = POP_PARSEVALUE (Pointer, List_front_Type);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Type");
        me->sub.PointerValue = Create_front_Type(src_info, id, types);
      }
  return n-1;
}


static __inline__ int Parse_state_45 (void)	/* state 45 */
{ int n;
      n = 2; _front_symbol = OPT_TYPEsym_Type_value;
      { /* opt action */
        front_Type  type = POP_PARSEVALUE (Pointer, front_Type);
        PUSH_PARSEVALUE(Pointer,type,front_Type);
      }
  return n-1;
}


static __inline__ int Parse_state_46 (void)	/* state 46 */
{ int n;
      n = 1; _front_symbol = OptType_value;
  return n-1;
}

static int Parse_state_47 (SymbolSet followers);	/* state 47 */

static __inline__ int Parse_state_48 (void)	/* state 48 */
{ int n;
      n = 1; _front_symbol = OPT_COMMENTsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}


static __inline__ int Parse_state_49 (void)	/* state 49 */
{ int n;
      n = 3; _front_symbol = ScanInfo_value;
      { ParseValue me;
        Bool  comment = POP_PARSEVALUE (Bool, Bool);
        front_Type  type = POP_PARSEVALUE (Pointer, front_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_ScanInfo");
        me->sub.PointerValue = Create_front_ScanInfo(src_info, type, comment);
      }
  return n-1;
}


static __inline__ int Parse_state_50 (void)	/* state 50 */
{ int n;
      n = 1; _front_symbol = OPT_ScanInfo_value;
      { /* opt action */
        front_ScanInfo  scan = POP_PARSEVALUE (Pointer, front_ScanInfo);
        PUSH_PARSEVALUE(Pointer,scan,front_ScanInfo);
      }
  return n-1;
}

static int Parse_state_51 (SymbolSet followers);	/* state 51 */
static int Parse_state_52 (SymbolSet followers);	/* state 52 */
static int Parse_state_53 (SymbolSet followers);	/* state 53 */

static __inline__ int Parse_state_54 (void)	/* state 54 */
{ int n;
      n = 2; _front_symbol = Super_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        Ident  x = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Super");
        me->sub.PointerValue = Create_front_SubType(src_info, x, id);
      }
  return n-1;
}

static int Parse_state_55 (SymbolSet followers);	/* state 55 */

static __inline__ int Parse_state_56 (void)	/* state 56 */
{ int n;
      n = 2; _front_symbol = Super_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Super");
        me->sub.PointerValue = Create_front_NoType(src_info, id);
      }
  return n-1;
}


static __inline__ int Parse_state_57 (void)	/* state 57 */
{ int n;
      n = 1; _front_symbol = OPT_Super_value;
      { /* opt action */
        front_Super  super = POP_PARSEVALUE (Pointer, front_Super);
        PUSH_PARSEVALUE(Pointer,super,front_Super);
      }
  return n-1;
}

static int Parse_state_58 (SymbolSet followers);	/* state 58 */

static __inline__ int Parse_state_59 (void)	/* state 59 */
{ int n;
      n = 1; _front_symbol = OPT_MEMOsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_60 (SymbolSet followers);	/* state 60 */

static __inline__ int Parse_state_61 (void)	/* state 61 */
{ int n;
      n = 1; _front_symbol = OPT_ENUMsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_62 (SymbolSet followers);	/* state 62 */

static __inline__ int Parse_state_63 (void)	/* state 63 */
{ int n;
      n = 1; _front_symbol = OPT_SKIPsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_64 (SymbolSet followers);	/* state 64 */

static __inline__ int Parse_state_65 (void)	/* state 65 */
{ int n;
      n = 1; _front_symbol = Defines_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Defines");
        me->sub.PointerValue = Create_front_PlainDef(src_info, id);
      }
  return n-1;
}


static __inline__ int Parse_state_66 (void)	/* state 66 */
{ int n;
      n = 1; _front_symbol = Defines_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Defines");
        me->sub.PointerValue = Create_front_MacroDef(src_info, id);
      }
  return n-1;
}

static int Parse_state_67 (SymbolSet followers);	/* state 67 */

static __inline__ int Parse_state_68 (void)	/* state 68 */
{ int n;
      n = 1; _front_symbol = Scoping_value;
      PUSH_PARSEVALUE(Int,front_NewScope,front_Scoping);
  return n-1;
}


static __inline__ int Parse_state_69 (void)	/* state 69 */
{ int n;
      n = 1; _front_symbol = Scoping_value;
      PUSH_PARSEVALUE(Int,front_OpenScope,front_Scoping);
  return n-1;
}


static __inline__ int Parse_state_70 (void)	/* state 70 */
{ int n;
      n = 1; _front_symbol = Scoping_value;
      PUSH_PARSEVALUE(Int,front_CloseScope,front_Scoping);
  return n-1;
}

static int Parse_state_71 (SymbolSet followers);	/* state 71 */

static __inline__ int Parse_state_72 (void)	/* state 72 */
{ int n;
      n = 2; _front_symbol = OPTMORE_Scoping_value;
      { /* optmore action */
        List_front_Scoping  sc_l = POP_PARSEVALUE (Pointer, List_front_Scoping);
        front_Scoping  sc = POP_PARSEVALUE (Int, front_Scoping);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Scoping(sc,sc_l),List_front_Scoping);
      }
  return n-1;
}

static int Parse_state_73 (SymbolSet followers);	/* state 73 */

static __inline__ int Parse_state_74 (void)	/* state 74 */
{ int n;
      n = 1; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_75 (SymbolSet followers);	/* state 75 */

static __inline__ int Parse_state_76 (void)	/* state 76 */
{ int n;
      n = 1; _front_symbol = Define_value;
      PUSH_PARSEVALUE(Int,front_Defining,front_Define);
  return n-1;
}


static __inline__ int Parse_state_77 (void)	/* state 77 */
{ int n;
      n = 1; _front_symbol = Define_value;
      PUSH_PARSEVALUE(Int,front_Redefining,front_Define);
  return n-1;
}


static __inline__ int Parse_state_78 (void)	/* state 78 */
{ int n;
      n = 1; _front_symbol = Define_value;
      PUSH_PARSEVALUE(Int,front_Overloading,front_Define);
  return n-1;
}

static int Parse_state_79 (SymbolSet followers);	/* state 79 */
static int Parse_state_80 (SymbolSet followers);	/* state 80 */

static __inline__ int Parse_state_81 (void)	/* state 81 */
{ int n;
      n = 2; _front_symbol = IdSym_value;
      { ParseValue me;
        front_Type  type = POP_PARSEVALUE (Pointer, front_Type);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_IdSym(src_info, id, type);
      }
  return n-1;
}


static __inline__ int Parse_state_82 (void)	/* state 82 */
{ int n;
      n = 1; _front_symbol = Defining_id_value;
      { ParseValue me;
        front_Symbol  id = POP_PARSEVALUE (Pointer, front_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Defining_id");
        me->sub.PointerValue = Create_front_DefId(src_info, id);
      }
  return n-1;
}

static int Parse_state_83 (SymbolSet followers);	/* state 83 */

static __inline__ int Parse_state_84 (void)	/* state 84 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_85 (void)	/* state 85 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_86 (void)	/* state 86 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_87 (void)	/* state 87 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_88 (void)	/* state 88 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_89 (void)	/* state 89 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_90 (void)	/* state 90 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_91 (void)	/* state 91 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_92 (void)	/* state 92 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_93 (void)	/* state 93 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_94 (void)	/* state 94 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_95 (void)	/* state 95 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_96 (void)	/* state 96 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_97 (void)	/* state 97 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_98 (void)	/* state 98 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_99 (void)	/* state 99 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}


static __inline__ int Parse_state_100 (void)	/* state 100 */
{ int n;
      n = 1; _front_symbol = Oper_value;
  return n-1;
}

static int Parse_state_101 (SymbolSet followers);	/* state 101 */

static __inline__ int Parse_state_102 (void)	/* state 102 */
{ int n;
      n = 2; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        List_Ident  op_l = POP_PARSEVALUE (Pointer, List_Ident);
        Ident  op = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,Create_List_Ident(op,op_l),List_Ident);
      }
  return n-1;
}

static int Parse_state_103 (SymbolSet followers);	/* state 103 */

static __inline__ int Parse_state_104 (void)	/* state 104 */
{ int n;
      n = 1; _front_symbol = StringOrKeyword_value;
  return n-1;
}


static __inline__ int Parse_state_105 (void)	/* state 105 */
{ int n;
      n = 1; _front_symbol = StringOrKeyword_value;
  return n-1;
}


static __inline__ int Parse_state_106 (void)	/* state 106 */
{ int n;
      n = 1; _front_symbol = StringOrKeyword_value;
  return n-1;
}


static __inline__ int Parse_state_107 (void)	/* state 107 */
{ int n;
      n = 1; _front_symbol = SimpleExpr_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_IdentExpr(src_info, id);
      }
  return n-1;
}

static int Parse_state_108 (SymbolSet followers);	/* state 108 */
static int Parse_state_109 (SymbolSet followers);	/* state 109 */

static __inline__ int Parse_state_110 (void)	/* state 110 */
{ int n;
      n = 3; _front_symbol = SimpleExpr_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        front_Expr  prefix = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_QualExpr(src_info, prefix, id);
      }
  return n-1;
}

static int Parse_state_111 (SymbolSet followers);	/* state 111 */
static int Parse_state_112 (SymbolSet followers);	/* state 112 */
static int Parse_state_113 (SymbolSet followers);	/* state 113 */

static __inline__ int Parse_state_114 (void)	/* state 114 */
{ int n;
      n = 3; _front_symbol = ALT_MonExpr1_SEP_SP_Oper_value;
      { /* alt action */
        List_Ident  op_l = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args_l = POP_PARSEVALUE (Pointer, List_front_Expr);
        Ident  op = POP_PARSEVALUE (Ident, Ident);
        front_Expr  args = POP_PARSEVALUE (Pointer, front_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Expr(args,args_l),List_front_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_Ident(op,op_l),List_Ident);
      }
  return n-1;
}


static __inline__ int Parse_state_115 (void)	/* state 115 */
{ int n;
      n = 1; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
  return n-1;
}

static int Parse_state_116 (SymbolSet followers);	/* state 116 */
static int Parse_state_117 (SymbolSet followers);	/* state 117 */

static __inline__ int Parse_state_118 (void)	/* state 118 */
{ int n;
      n = 3; _front_symbol = ALT_Expr_SEP_commasym_SP_value;
      { /* alt action */
        List_front_Expr  exprs_l = POP_PARSEVALUE (Pointer, List_front_Expr);
        front_Expr  exprs = POP_PARSEVALUE (Pointer, front_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Expr(exprs,exprs_l),List_front_Expr);
      }
  return n-1;
}


static __inline__ int Parse_state_119 (void)	/* state 119 */
{ int n;
      n = 1; _front_symbol = ExprList_value;
  return n-1;
}


static __inline__ int Parse_state_120 (void)	/* state 120 */
{ int n;
      n = 1; _front_symbol = OPT_ExprList_value;
      { /* opt action */
        List_front_Expr  exprs = POP_PARSEVALUE (Pointer, List_front_Expr);
        PUSH_PARSEVALUE(Pointer,exprs,List_front_Expr);
      }
  return n-1;
}

static int Parse_state_121 (void);	/* state 121 */

static __inline__ int Parse_state_122 (void)	/* state 122 */
{ int n;
      n = 4; _front_symbol = SimpleExpr_value;
      { ParseValue me;
        List_front_Expr  exprs = POP_PARSEVALUE (Pointer, List_front_Expr);
        front_Expr  func = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_CallExpr(src_info, func, exprs);
      }
  return n-1;
}


static __inline__ int Parse_state_123 (void)	/* state 123 */
{ int n;
      n = 1; _front_symbol = SimpleExpr_value;
      { ParseValue me;
        Int  i = POP_PARSEVALUE (Int, Int);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_IntExpr(src_info, i);
      }
  return n-1;
}


static __inline__ int Parse_state_124 (void)	/* state 124 */
{ int n;
      n = 1; _front_symbol = SimpleExpr_value;
      { ParseValue me;
        Bool  b = POP_PARSEVALUE (Bool, Bool);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BoolExpr(src_info, b);
      }
  return n-1;
}


static __inline__ int Parse_state_125 (void)	/* state 125 */
{ int n;
      n = 1; _front_symbol = SimpleExpr_value;
      { ParseValue me;
        String  s = POP_PARSEVALUE (String, String);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_StringExpr(src_info, s);
      }
  return n-1;
}


static __inline__ int Parse_state_126 (void)	/* state 126 */
{ int n;
      n = 1; _front_symbol = SimpleExpr_value;
      { ParseValue me;
        SrcInfo src_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_NilExpr(src_info);
      }
  return n-1;
}

static int Parse_state_127 (void);	/* state 127 */

static __inline__ int Parse_state_128 (void)	/* state 128 */
{ int n;
      n = 3; _front_symbol = Defining_id_value;
      { ParseValue me;
        front_Expr  e = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Defining_id");
        me->sub.PointerValue = Create_front_DefExpr(src_info, e);
      }
  return n-1;
}

static int Parse_state_129 (SymbolSet followers);	/* state 129 */
static int Parse_state_130 (SymbolSet followers);	/* state 130 */

static __inline__ int Parse_state_131 (void)	/* state 131 */
{ int n;
      n = 2; _front_symbol = OPT_NAMESPACEsym_Identsym_value;
      { /* opt action */
        Ident  ns_id = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,ns_id,Ident);
      }
  return n-1;
}

static int Parse_state_132 (SymbolSet followers);	/* state 132 */
static int Parse_state_133 (SymbolSet followers);	/* state 133 */

static __inline__ int Parse_state_134 (void)	/* state 134 */
{ int n;
      n = 2; _front_symbol = ScopeExpr_value;
  return n-1;
}


static __inline__ int Parse_state_135 (void)	/* state 135 */
{ int n;
      n = 1; _front_symbol = OPT_ScopeExpr_value;
      { /* opt action */
        front_Expr  sc = POP_PARSEVALUE (Pointer, front_Expr);
        PUSH_PARSEVALUE(Pointer,sc,front_Expr);
      }
  return n-1;
}


static __inline__ int Parse_state_136 (void)	/* state 136 */
{ int n;
      n = 5; _front_symbol = DefiningSym_value;
      { ParseValue me;
        front_Expr  sc = POP_PARSEVALUE (Pointer, front_Expr);
        Ident  ns_id = POP_PARSEVALUE (Ident, Ident);
        front_Defining_id  id = POP_PARSEVALUE (Pointer, front_Defining_id);
        front_Define  def = POP_PARSEVALUE (Int, front_Define);
        Bool  forward = POP_PARSEVALUE (Bool, Bool);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_DefiningSym(src_info, forward, def, id, ns_id, sc);
      }
  return n-1;
}

static int Parse_state_137 (SymbolSet followers);	/* state 137 */
static int Parse_state_138 (SymbolSet followers);	/* state 138 */
static int Parse_state_139 (SymbolSet followers);	/* state 139 */

static __inline__ int Parse_state_140 (void)	/* state 140 */
{ int n;
      n = 1; _front_symbol = SimpleSymbol_value;
  return n-1;
}


static __inline__ int Parse_state_141 (void)	/* state 141 */
{ int n;
      n = 1; _front_symbol = SimpleSymbol_value;
  return n-1;
}

static int Parse_state_142 (SymbolSet followers);	/* state 142 */
static int Parse_state_143 (SymbolSet followers);	/* state 143 */

static __inline__ int Parse_state_144 (void)	/* state 144 */
{ int n;
      n = 1; _front_symbol = NameOrField_value;
      PUSH_PARSEVALUE(Int,front_AppliedName,front_NameOrField);
  return n-1;
}


static __inline__ int Parse_state_145 (void)	/* state 145 */
{ int n;
      n = 1; _front_symbol = NameOrField_value;
      PUSH_PARSEVALUE(Int,front_AppliedField,front_NameOrField);
  return n-1;
}

static int Parse_state_146 (SymbolSet followers);	/* state 146 */
static int Parse_state_147 (SymbolSet followers);	/* state 147 */
static int Parse_state_148 (SymbolSet followers);	/* state 148 */

static __inline__ int Parse_state_149 (void)	/* state 149 */
{ int n;
      n = 1; _front_symbol = OPT_WARNINGsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}


static __inline__ int Parse_state_150 (void)	/* state 150 */
{ int n;
      n = 6; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        Bool  warn = POP_PARSEVALUE (Bool, Bool);
        front_Expr  sc = POP_PARSEVALUE (Pointer, front_Expr);
        Ident  name = POP_PARSEVALUE (Ident, Ident);
        front_NameOrField  field = POP_PARSEVALUE (Int, front_NameOrField);
        Ident  nt_id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_AppliedSym(src_info, nt_id, field, name, sc, warn);
      }
  return n-1;
}

static int Parse_state_151 (SymbolSet followers);	/* state 151 */
static int Parse_state_152 (SymbolSet followers);	/* state 152 */

static __inline__ int Parse_state_153 (void)	/* state 153 */
{ int n;
      n = 2; _front_symbol = OPT_NAMEsym_Identsym_value;
      { /* opt action */
        Ident  n = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,n,Ident);
      }
  return n-1;
}

static int Parse_state_154 (SymbolSet followers);	/* state 154 */

static __inline__ int Parse_state_155 (void)	/* state 155 */
{ int n;
      n = 3; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        front_Type  type = POP_PARSEVALUE (Pointer, front_Type);
        Ident  n = POP_PARSEVALUE (Ident, Ident);
        String  string = POP_PARSEVALUE (String, String);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_StringSymbol(src_info, string, n, type);
      }
  return n-1;
}

static int Parse_state_156 (SymbolSet followers);	/* state 156 */

static __inline__ int Parse_state_157 (void)	/* state 157 */
{ int n;
      n = 2; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        front_Type  type = POP_PARSEVALUE (Pointer, front_Type);
        String  chr = POP_PARSEVALUE (String, String);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_CharSymbol(src_info, chr, type);
      }
  return n-1;
}

static int Parse_state_158 (SymbolSet followers);	/* state 158 */

static __inline__ int Parse_state_159 (void)	/* state 159 */
{ int n;
      n = 2; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        front_Type  type = POP_PARSEVALUE (Pointer, front_Type);
        String  keyword = POP_PARSEVALUE (String, String);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_KeywordSymbol(src_info, keyword, type);
      }
  return n-1;
}

static int Parse_state_160 (SymbolSet followers);	/* state 160 */
static int Parse_state_161 (SymbolSet followers);	/* state 161 */
static int Parse_state_162 (SymbolSet followers);	/* state 162 */

static __inline__ int Parse_state_163 (void)	/* state 163 */
{ int n;
      n = 1; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        SrcInfo src_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_EmptySym(src_info);
      }
  return n-1;
}

static int Parse_state_164 (SymbolSet followers);	/* state 164 */

static __inline__ int Parse_state_165 (void)	/* state 165 */
{ int n;
      n = 2; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        String  s = POP_PARSEVALUE (String, String);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_LayoutString(src_info, s);
      }
  return n-1;
}

static int Parse_state_166 (SymbolSet followers);	/* state 166 */

static __inline__ int Parse_state_167 (void)	/* state 167 */
{ int n;
      n = 2; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        front_Expr  layout = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_LayoutAction(src_info, layout);
      }
  return n-1;
}

static int Parse_state_168 (SymbolSet followers);	/* state 168 */
static int Parse_state_169 (SymbolSet followers);	/* state 169 */

static __inline__ int Parse_state_170 (void)	/* state 170 */
{ int n;
      n = 3; _front_symbol = Symbol2_value;
      { ParseValue me;
        Ident  comp = POP_PARSEVALUE (Ident, Ident);
        front_Symbol  sym = POP_PARSEVALUE (Pointer, front_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_CompareSym(src_info, sym, comp);
      }
  return n-1;
}


static __inline__ int Parse_state_171 (void)	/* state 171 */
{ int n;
      n = 1; _front_symbol = Symbol_value;
  return n-1;
}


static __inline__ int Parse_state_172 (void)	/* state 172 */
{ int n;
      n = 1; _front_symbol = ONCE_SymbolORField_value;
      { /* once action */
        front_Symbol  symbols = POP_PARSEVALUE (Pointer, front_Symbol);
        PUSH_PARSEVALUE(Pointer,symbols,front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,front_Field);
      }
  return n-1;
}


static __inline__ int Parse_state_173 (void)	/* state 173 */
{ int n;
      n = 1; _front_symbol = ONCE_SymbolORField_value;
      { /* once action */
        front_Field  my_fields = POP_PARSEVALUE (Pointer, front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,front_Symbol);
        PUSH_PARSEVALUE(Pointer,my_fields,front_Field);
      }
  return n-1;
}

static int Parse_state_174 (SymbolSet followers);	/* state 174 */

static __inline__ int Parse_state_175 (void)	/* state 175 */
{ int n;
      n = 1; _front_symbol = And_value;
      PUSH_PARSEVALUE(Int,front_AndTranspose,front_And);
  return n-1;
}


static __inline__ int Parse_state_176 (void)	/* state 176 */
{ int n;
      n = 1; _front_symbol = And_value;
      PUSH_PARSEVALUE(Int,front_AndLeft,front_And);
  return n-1;
}


static __inline__ int Parse_state_177 (void)	/* state 177 */
{ int n;
      n = 1; _front_symbol = And_value;
      PUSH_PARSEVALUE(Int,front_AndRight,front_And);
  return n-1;
}

static int Parse_state_178 (SymbolSet followers);	/* state 178 */

static __inline__ int Parse_state_179 (void)	/* state 179 */
{ int n;
      n = 3; _front_symbol = ALT_ONCE_SymbolORField_SEP_And_value;
      { /* alt action */
        List_front_And  ands_l = POP_PARSEVALUE (Pointer, List_front_And);
        List_front_Field  my_fields_l = POP_PARSEVALUE (Pointer, List_front_Field);
        List_front_Symbol  symbols_l = POP_PARSEVALUE (Pointer, List_front_Symbol);
        front_And  ands = POP_PARSEVALUE (Int, front_And);
        front_Field  my_fields = POP_PARSEVALUE (Pointer, front_Field);
        front_Symbol  symbols = POP_PARSEVALUE (Pointer, front_Symbol);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Symbol(symbols,symbols_l),List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Field(my_fields,my_fields_l),List_front_Field);
        PUSH_PARSEVALUE(Pointer,Create_List_front_And(ands,ands_l),List_front_And);
      }
  return n-1;
}


static __inline__ int Parse_state_180 (void)	/* state 180 */
{ int n;
      n = 1; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        List_front_And  ands = POP_PARSEVALUE (Pointer, List_front_And);
        List_front_Field  my_fields = POP_PARSEVALUE (Pointer, List_front_Field);
        List_front_Symbol  symbols = POP_PARSEVALUE (Pointer, List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,symbols,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,my_fields,List_front_Field);
        PUSH_PARSEVALUE(Pointer,ands,List_front_And);
      }
  return n-1;
}


static __inline__ int Parse_state_181 (void)	/* state 181 */
{ int n;
      n = 1; _front_symbol = SymbolSeq_value;
      { ParseValue me;
        List_front_And  ands = POP_PARSEVALUE (Pointer, List_front_And);
        List_front_Field  my_fields = POP_PARSEVALUE (Pointer, List_front_Field);
        List_front_Symbol  symbols = POP_PARSEVALUE (Pointer, List_front_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_SymbolSeq(src_info, symbols, my_fields, ands);
      }
  return n-1;
}

static int Parse_state_182 (SymbolSet followers);	/* state 182 */

static __inline__ int Parse_state_183 (void)	/* state 183 */
{ int n;
      n = 1; _front_symbol = Alternator_value;
      PUSH_PARSEVALUE(Int,FALSE,front_Alternator);
  return n-1;
}


static __inline__ int Parse_state_184 (void)	/* state 184 */
{ int n;
      n = 1; _front_symbol = Alternator_value;
      PUSH_PARSEVALUE(Int,TRUE,front_Alternator);
  return n-1;
}

static int Parse_state_185 (SymbolSet followers);	/* state 185 */
static int Parse_state_186 (SymbolSet followers);	/* state 186 */
static int Parse_state_187 (SymbolSet followers);	/* state 187 */

static __inline__ int Parse_state_188 (void)	/* state 188 */
{ int n;
      n = 3; _front_symbol = Symbol_value;
      { ParseValue me;
        front_Symbol  sym = POP_PARSEVALUE (Pointer, front_Symbol);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_LabeledSym(src_info, id, sym);
      }
  return n-1;
}

static int Parse_state_189 (SymbolSet followers);	/* state 189 */

static __inline__ int Parse_state_190 (void)	/* state 190 */
{ int n;
      n = 2; _front_symbol = MORE_Symbol_value;
      { /* more action */
        List_front_Symbol  syms_l = POP_PARSEVALUE (Pointer, List_front_Symbol);
        front_Symbol  syms = POP_PARSEVALUE (Pointer, front_Symbol);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Symbol(syms,syms_l),List_front_Symbol);
      }
  return n-1;
}


static __inline__ int Parse_state_191 (void)	/* state 191 */
{ int n;
      n = 3; _front_symbol = AltSymbol_value;
      { ParseValue me;
        List_front_Symbol  syms = POP_PARSEVALUE (Pointer, List_front_Symbol);
        front_Alternator  alt = POP_PARSEVALUE (Int, front_Alternator);
        front_Symbol  syms1 = POP_PARSEVALUE (Pointer, front_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_AltSymbol(src_info, syms1, alt, syms);
      }
  return n-1;
}


static __inline__ int Parse_state_192 (void)	/* state 192 */
{ int n;
      n = 1; _front_symbol = Symbol1_value;
  return n-1;
}

static int Parse_state_193 (SymbolSet followers);	/* state 193 */

static __inline__ int Parse_state_194 (void)	/* state 194 */
{ int n;
      n = 1; _front_symbol = Or_value;
      PUSH_PARSEVALUE(Int,front_OrCenter,front_Or);
  return n-1;
}


static __inline__ int Parse_state_195 (void)	/* state 195 */
{ int n;
      n = 1; _front_symbol = Or_value;
      PUSH_PARSEVALUE(Int,front_OrLeft,front_Or);
  return n-1;
}


static __inline__ int Parse_state_196 (void)	/* state 196 */
{ int n;
      n = 1; _front_symbol = Or_value;
      PUSH_PARSEVALUE(Int,front_OrRight,front_Or);
  return n-1;
}


static __inline__ int Parse_state_197 (void)	/* state 197 */
{ int n;
      n = 1; _front_symbol = Or_value;
      PUSH_PARSEVALUE(Int,front_OrTranspose,front_Or);
  return n-1;
}

static int Parse_state_198 (SymbolSet followers);	/* state 198 */

static __inline__ int Parse_state_199 (void)	/* state 199 */
{ int n;
      n = 3; _front_symbol = ALT_Symbol1_SEP_Or_SP_value;
      { /* alt action */
        List_front_Or  ops_l = POP_PARSEVALUE (Pointer, List_front_Or);
        List_front_Symbol  sym_l = POP_PARSEVALUE (Pointer, List_front_Symbol);
        front_Or  ops = POP_PARSEVALUE (Int, front_Or);
        front_Symbol  sym = POP_PARSEVALUE (Pointer, front_Symbol);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Symbol(sym,sym_l),List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Or(ops,ops_l),List_front_Or);
      }
  return n-1;
}


static __inline__ int Parse_state_200 (void)	/* state 200 */
{ int n;
      n = 1; _front_symbol = Alternatives_value;
  return n-1;
}

static int Parse_state_201 (SymbolSet followers);	/* state 201 */
static int Parse_state_202 (SymbolSet followers);	/* state 202 */

static __inline__ int Parse_state_203 (void)	/* state 203 */
{ int n;
      n = 4; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        Ident  more = POP_PARSEVALUE (Ident, Ident);
        List_front_Or  ops = POP_PARSEVALUE (Pointer, List_front_Or);
        List_front_Symbol  sym = POP_PARSEVALUE (Pointer, List_front_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_MoreSymbol(src_info, sym, ops, more);
      }
  return n-1;
}

static int Parse_state_204 (SymbolSet followers);	/* state 204 */
static int Parse_state_205 (SymbolSet followers);	/* state 205 */

static __inline__ int Parse_state_206 (void)	/* state 206 */
{ int n;
      n = 1; _front_symbol = OPT_exclaimsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}


static __inline__ int Parse_state_207 (void)	/* state 207 */
{ int n;
      n = 4; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        Bool  in_line = POP_PARSEVALUE (Bool, Bool);
        List_front_Or  ops = POP_PARSEVALUE (Pointer, List_front_Or);
        List_front_Symbol  sym = POP_PARSEVALUE (Pointer, List_front_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_OptSymbol(src_info, sym, ops, in_line);
      }
  return n-1;
}

static int Parse_state_208 (void);	/* state 208 */
static int Parse_state_209 (void);	/* state 209 */

static __inline__ int Parse_state_210 (void)	/* state 210 */
{ int n;
      n = 4; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        List_front_Or  ops = POP_PARSEVALUE (Pointer, List_front_Or);
        List_front_Symbol  sym = POP_PARSEVALUE (Pointer, List_front_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_OnceSymbol(src_info, sym, ops);
      }
  return n-1;
}

static int Parse_state_211 (SymbolSet followers);	/* state 211 */
static int Parse_state_212 (SymbolSet followers);	/* state 212 */

static __inline__ int Parse_state_213 (void)	/* state 213 */
{ int n;
      n = 1; _front_symbol = OPT_CREATEsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_214 (SymbolSet followers);	/* state 214 */

static __inline__ int Parse_state_215 (void)	/* state 215 */
{ int n;
      n = 2; _front_symbol = FieldInit_value;
      { ParseValue me;
        front_Expr  expr = POP_PARSEVALUE (Pointer, front_Expr);
        Bool  c = POP_PARSEVALUE (Bool, Bool);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_FieldInit");
        me->sub.PointerValue = Create_front_WhenCreate(src_info, c, expr);
      }
  return n-1;
}

static int Parse_state_216 (SymbolSet followers);	/* state 216 */

static __inline__ int Parse_state_217 (void)	/* state 217 */
{ int n;
      n = 2; _front_symbol = FieldInit_value;
      { ParseValue me;
        front_Expr  expr = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_FieldInit");
        me->sub.PointerValue = Create_front_WhenScope(src_info, expr);
      }
  return n-1;
}

static int Parse_state_218 (SymbolSet followers);	/* state 218 */

static __inline__ int Parse_state_219 (void)	/* state 219 */
{ int n;
      n = 2; _front_symbol = FieldInit_value;
      { ParseValue me;
        front_Expr  expr = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_FieldInit");
        me->sub.PointerValue = Create_front_WhenDefining(src_info, expr);
      }
  return n-1;
}

static int Parse_state_220 (SymbolSet followers);	/* state 220 */

static __inline__ int Parse_state_221 (void)	/* state 221 */
{ int n;
      n = 2; _front_symbol = FieldInit_value;
      { ParseValue me;
        front_Expr  expr = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_FieldInit");
        me->sub.PointerValue = Create_front_WhenApplied(src_info, expr);
      }
  return n-1;
}

static int Parse_state_222 (SymbolSet followers);	/* state 222 */

static __inline__ int Parse_state_223 (void)	/* state 223 */
{ int n;
      n = 2; _front_symbol = FieldInit_value;
      { ParseValue me;
        front_Expr  expr = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_FieldInit");
        me->sub.PointerValue = Create_front_WhenChecks(src_info, expr);
      }
  return n-1;
}

static int Parse_state_224 (SymbolSet followers);	/* state 224 */
static int Parse_state_225 (SymbolSet followers);	/* state 225 */

static __inline__ int Parse_state_226 (void)	/* state 226 */
{ int n;
      n = 3; _front_symbol = ALT_FieldInit_SEP_commasym_value;
      { /* alt action */
        List_front_FieldInit  _id_0_l = POP_PARSEVALUE (Pointer, List_front_FieldInit);
        front_FieldInit  _id_0 = POP_PARSEVALUE (Pointer, front_FieldInit);
        PUSH_PARSEVALUE(Pointer,Create_List_front_FieldInit(_id_0,_id_0_l),List_front_FieldInit);
      }
  return n-1;
}


static __inline__ int Parse_state_227 (void)	/* state 227 */
{ int n;
      n = 1; _front_symbol = FieldInits_value;
  return n-1;
}

static int Parse_state_228 (SymbolSet followers);	/* state 228 */

static __inline__ int Parse_state_229 (void)	/* state 229 */
{ int n;
      n = 1; _front_symbol = OPT_TRAVERSEsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_230 (SymbolSet followers);	/* state 230 */

static __inline__ int Parse_state_231 (void)	/* state 231 */
{ int n;
      n = 1; _front_symbol = OPT_CLEARsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_232 (SymbolSet followers);	/* state 232 */

static __inline__ int Parse_state_233 (void)	/* state 233 */
{ int n;
      n = 1; _front_symbol = OPT_DONT_CLEARsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}


static __inline__ int Parse_state_234 (void)	/* state 234 */
{ int n;
      n = 8; _front_symbol = Field_value;
      { ParseValue me;
        Bool  dont_clear = POP_PARSEVALUE (Bool, Bool);
        Bool  clear = POP_PARSEVALUE (Bool, Bool);
        Bool  traverse = POP_PARSEVALUE (Bool, Bool);
        List_front_FieldInit  _id_0 = POP_PARSEVALUE (Pointer, List_front_FieldInit);
        Ident  assign = POP_PARSEVALUE (Ident, Ident);
        front_Type  type = POP_PARSEVALUE (Pointer, front_Type);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Field");
        me->sub.PointerValue = Create_front_Field(src_info, id, type, assign, _id_0, traverse, clear, dont_clear);
      }
  return n-1;
}

static int Parse_state_235 (SymbolSet followers);	/* state 235 */
static int Parse_state_236 (SymbolSet followers);	/* state 236 */
static int Parse_state_237 (SymbolSet followers);	/* state 237 */
static int Parse_state_238 (SymbolSet followers);	/* state 238 */
static int Parse_state_239 (SymbolSet followers);	/* state 239 */
static int Parse_state_240 (SymbolSet followers);	/* state 240 */

static __inline__ int Parse_state_241 (void)	/* state 241 */
{ int n;
      n = 5; _front_symbol = Alternative_value;
      { ParseValue me;
        front_Rhs  rhs = POP_PARSEVALUE (Pointer, front_Rhs);
        Ident  def = POP_PARSEVALUE (Ident, Ident);
        Bool  skip = POP_PARSEVALUE (Bool, Bool);
        Bool  meemo = POP_PARSEVALUE (Bool, Bool);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Alternative");
        me->sub.PointerValue = Create_front_LabeledAlt(src_info, id, meemo, skip, def, rhs);
      }
  return n-1;
}


static __inline__ int Parse_state_242 (void)	/* state 242 */
{ int n;
      n = 1; _front_symbol = Alternative_value;
      { ParseValue me;
        front_Symbol  syms = POP_PARSEVALUE (Pointer, front_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Alternative");
        me->sub.PointerValue = Create_front_UnLabeledAlt(src_info, syms);
      }
  return n-1;
}

static int Parse_state_243 (SymbolSet followers);	/* state 243 */
static int Parse_state_244 (SymbolSet followers);	/* state 244 */

static __inline__ int Parse_state_245 (void)	/* state 245 */
{ int n;
      n = 3; _front_symbol = ALT_Alternative_SEP_Or_value;
      { /* alt action */
        List_front_Or  ops_l = POP_PARSEVALUE (Pointer, List_front_Or);
        List_front_Alternative  alts_l = POP_PARSEVALUE (Pointer, List_front_Alternative);
        front_Or  ops = POP_PARSEVALUE (Int, front_Or);
        front_Alternative  alts = POP_PARSEVALUE (Pointer, front_Alternative);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Alternative(alts,alts_l),List_front_Alternative);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Or(ops,ops_l),List_front_Or);
      }
  return n-1;
}


static __inline__ int Parse_state_246 (void)	/* state 246 */
{ int n;
      n = 1; _front_symbol = ChoiceList_value;
  return n-1;
}

static int Parse_state_247 (SymbolSet followers);	/* state 247 */
static int Parse_state_248 (SymbolSet followers);	/* state 248 */

static __inline__ int Parse_state_249 (void)	/* state 249 */
{ int n;
      n = 4; _front_symbol = Choices_value;
  return n-1;
}


static __inline__ int Parse_state_250 (void)	/* state 250 */
{ int n;
      n = 1; _front_symbol = OPT_Choices_value;
      { /* opt action */
        front_Symbol  syms2 = POP_PARSEVALUE (Pointer, front_Symbol);
        Ident  y = POP_PARSEVALUE (Ident, Ident);
        List_front_Or  ops = POP_PARSEVALUE (Pointer, List_front_Or);
        List_front_Alternative  alts = POP_PARSEVALUE (Pointer, List_front_Alternative);
        Ident  x = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,x,Ident);
        PUSH_PARSEVALUE(Pointer,alts,List_front_Alternative);
        PUSH_PARSEVALUE(Pointer,ops,List_front_Or);
        PUSH_PARSEVALUE(Pointer,y,Ident);
        PUSH_PARSEVALUE(Pointer,syms2,front_Symbol);
      }
  return n-1;
}

static int Parse_state_251 (SymbolSet followers);	/* state 251 */
static int Parse_state_252 (SymbolSet followers);	/* state 252 */
static int Parse_state_253 (SymbolSet followers);	/* state 253 */
static int Parse_state_254 (SymbolSet followers);	/* state 254 */
static int Parse_state_255 (SymbolSet followers);	/* state 255 */
static int Parse_state_256 (SymbolSet followers);	/* state 256 */
static int Parse_state_257 (SymbolSet followers);	/* state 257 */

static __inline__ int Parse_state_258 (void)	/* state 258 */
{ int n;
      n = 2; _front_symbol = MORE_MonExpr1_value;
      { /* more action */
        List_front_Expr  message_l = POP_PARSEVALUE (Pointer, List_front_Expr);
        front_Expr  message = POP_PARSEVALUE (Pointer, front_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Expr(message,message_l),List_front_Expr);
      }
  return n-1;
}


static __inline__ int Parse_state_259 (void)	/* state 259 */
{ int n;
      n = 5; _front_symbol = Check_value;
      { ParseValue me;
        List_front_Expr  message = POP_PARSEVALUE (Pointer, List_front_Expr);
        Bool  warn = POP_PARSEVALUE (Bool, Bool);
        front_Expr  cond = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Check");
        me->sub.PointerValue = Create_front_Check(src_info, cond, warn, message);
      }
  return n-1;
}

static int Parse_state_260 (SymbolSet followers);	/* state 260 */

static __inline__ int Parse_state_261 (void)	/* state 261 */
{ int n;
      n = 2; _front_symbol = OPTMORE_Check_value;
      { /* optmore action */
        List_front_Check  checklist_l = POP_PARSEVALUE (Pointer, List_front_Check);
        front_Check  checklist = POP_PARSEVALUE (Pointer, front_Check);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Check(checklist,checklist_l),List_front_Check);
      }
  return n-1;
}


static __inline__ int Parse_state_262 (void)	/* state 262 */
{ int n;
      n = 2; _front_symbol = OPT_CHECKSsym_OPTMORE_Check_value;
      { /* opt action */
        List_front_Check  checklist = POP_PARSEVALUE (Pointer, List_front_Check);
        PUSH_PARSEVALUE(Pointer,checklist,List_front_Check);
      }
  return n-1;
}


static __inline__ int Parse_state_263 (void)	/* state 263 */
{ int n;
      n = 4; _front_symbol = Rhs_value;
      { ParseValue me;
        List_front_Check  checklist = POP_PARSEVALUE (Pointer, List_front_Check);
        front_Symbol  syms2 = POP_PARSEVALUE (Pointer, front_Symbol);
        Ident  y = POP_PARSEVALUE (Ident, Ident);
        List_front_Or  ops = POP_PARSEVALUE (Pointer, List_front_Or);
        List_front_Alternative  alts = POP_PARSEVALUE (Pointer, List_front_Alternative);
        Ident  x = POP_PARSEVALUE (Ident, Ident);
        front_Symbol  syms1 = POP_PARSEVALUE (Pointer, front_Symbol);
        List_front_Scoping  sc = POP_PARSEVALUE (Pointer, List_front_Scoping);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Rhs");
        me->sub.PointerValue = Create_front_Rhs(src_info, sc, syms1, x, alts, ops, y, syms2, checklist);
      }
  return n-1;
}

static int Parse_state_264 (void);	/* state 264 */

static __inline__ int Parse_state_265 (void)	/* state 265 */
{ int n;
      n = 10; _front_symbol = NonTerminal_value;
      { ParseValue me;
        front_Rhs  rhs = POP_PARSEVALUE (Pointer, front_Rhs);
        front_Defines  alias = POP_PARSEVALUE (Pointer, front_Defines);
        Bool  skip = POP_PARSEVALUE (Bool, Bool);
        Bool  enumerate = POP_PARSEVALUE (Bool, Bool);
        Bool  meemo = POP_PARSEVALUE (Bool, Bool);
        front_Super  super = POP_PARSEVALUE (Pointer, front_Super);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        front_ScanInfo  scan = POP_PARSEVALUE (Pointer, front_ScanInfo);
        Bool  is_root = POP_PARSEVALUE (Bool, Bool);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_NonTerminal");
        me->sub.PointerValue = Create_front_NonTerminal(src_info, is_root, scan, id, super, meemo, enumerate, skip, alias, rhs);
      }
  return n-1;
}

static int Parse_state_266 (SymbolSet followers);	/* state 266 */

static __inline__ int Parse_state_267 (void)	/* state 267 */
{ int n;
      n = 2; _front_symbol = MORE_NonTerminal_value;
      { /* more action */
        List_front_NonTerminal  rules_l = POP_PARSEVALUE (Pointer, List_front_NonTerminal);
        front_NonTerminal  rules = POP_PARSEVALUE (Pointer, front_NonTerminal);
        PUSH_PARSEVALUE(Pointer,Create_List_front_NonTerminal(rules,rules_l),List_front_NonTerminal);
      }
  return n-1;
}


static __inline__ int Parse_state_268 (void)	/* state 268 */
{ int n;
      n = 1; _front_symbol = NonTerminals_value;
  return n-1;
}


static __inline__ int Parse_state_269 (void)	/* state 269 */
{ int n;
      n = 1; _front_symbol = OPT_NonTerminals_value;
      { /* opt action */
        List_front_NonTerminal  rules = POP_PARSEVALUE (Pointer, List_front_NonTerminal);
        PUSH_PARSEVALUE(Pointer,rules,List_front_NonTerminal);
      }
  return n-1;
}


static __inline__ int Parse_state_270 (void)	/* state 270 */
{ int n;
      n = 4; _front_symbol = front_value;
      { ParseValue me;
        List_front_NonTerminal  rules = POP_PARSEVALUE (Pointer, List_front_NonTerminal);
        List_front_Import  imports = POP_PARSEVALUE (Pointer, List_front_Import);
        List_front_NameSpace  namespace = POP_PARSEVALUE (Pointer, List_front_NameSpace);
        List_Ident  ids = POP_PARSEVALUE (Pointer, List_Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_front");
        me->sub.PointerValue = Create_front_front(src_info, ids, namespace, imports, rules);
        Decorate_front(me->sub.PointerValue);
      }
  return n-1;
}

List_front_ImportedNonTerminal Parse_state_front_ImportedNonTerminals (void);	/* state 271 */
front_Import Parse_state_front_Import (void);	/* state 272 */
List_front_ImportedNonTerminal Parse_state_front_ALT_ImportedNonTerminal_SEP_commasym (void);	/* state 273 */
front_ImportedNonTerminal Parse_state_front_ImportedNonTerminal (void);	/* state 274 */
List_front_NonTerminal Parse_state_front_MORE_NonTerminal (void);	/* state 275 */
List_front_NonTerminal Parse_state_front_NonTerminals (void);	/* state 276 */
front_Defines Parse_state_front_Defines (void);	/* state 277 */
front_Rhs Parse_state_front_Rhs (void);	/* state 278 */
front_NonTerminal Parse_state_front_NonTerminal (void);	/* state 279 */
front_Super Parse_state_front_Super (void);	/* state 280 */
List_front_Scoping Parse_state_front_OPTMORE_Scoping (void);	/* state 281 */
front_Symbol Parse_state_front_Symbol1 (void);	/* state 282 */
front_Scoping Parse_state_front_Scoping (void);	/* state 283 */
front_Alternative Parse_state_front_Alternative (void);	/* state 284 */
front_Symbol Parse_state_front_Symbol2 (void);	/* state 285 */
front_Symbol Parse_state_front_Symbol (void);	/* state 286 */
front_Symbol Parse_state_front_AltSymbol (void);	/* state 287 */
static int Parse_state_288 (SymbolSet followers);	/* state 288 */
front_Symbol Parse_state_front_SymbolSeq (void);	/* state 289 */
front_Alternator Parse_state_front_Alternator (void);	/* state 290 */
List_front_Symbol Parse_state_front_MORE_Symbol (void);	/* state 291 */
front_And Parse_state_front_And (void);	/* state 292 */
front_Or Parse_state_front_Or (void);	/* state 293 */
front_Symbol Parse_state_front_SimpleSymbol (void);	/* state 294 */
front_Symbol Parse_state_front_DefiningSym (void);	/* state 295 */
front_Symbol Parse_state_front_IdSym (void);	/* state 296 */
front_NameOrField Parse_state_front_NameOrField (void);	/* state 297 */
front_Type Parse_state_front_OptType (void);	/* state 298 */
String Parse_state_front_StringOrKeyword (void);	/* state 299 */
front_Expr Parse_state_front_Expr (void);	/* state 300 */
front_Define Parse_state_front_Define (void);	/* state 301 */
front_Defining_id Parse_state_front_Defining_id (void);	/* state 302 */
front_Expr Parse_state_front_ScopeExpr (void);	/* state 303 */
front_Type Parse_state_front_Type (void);	/* state 304 */
List_front_FieldInit Parse_state_front_FieldInits (void);	/* state 305 */
front_Field Parse_state_front_Field (void);	/* state 306 */
static int Parse_state_307 (SymbolSet followers);	/* state 307 */
static int Parse_state_308 (SymbolSet followers);	/* state 308 */
List_front_FieldInit Parse_state_front_ALT_FieldInit_SEP_commasym (void);	/* state 309 */
front_FieldInit Parse_state_front_FieldInit (void);	/* state 310 */
List_Ident Parse_state_front_OPTMORE_Oper (void);	/* state 311 */
front_Expr Parse_state_front_SimpleExpr (void);	/* state 312 */
static int Parse_state_313 (SymbolSet followers);	/* state 313 */
front_Expr Parse_state_front_MonExpr1 (void);	/* state 314 */
List_front_Expr Parse_state_front_MORE_MonExpr1 (void);	/* state 315 */
front_Check Parse_state_front_Check (void);	/* state 316 */
List_front_NameSpace Parse_state_front_ALT_NameSpace_SEP_commasym_SP (void);	/* state 317 */
List_front_NameSpace Parse_state_front_NameSpaceList (void);	/* state 318 */
List_front_Expr Parse_state_front_ALT_Expr_SEP_commasym_SP (void);	/* state 319 */
List_front_Expr Parse_state_front_ExprList (void);	/* state 320 */
List_Ident Parse_state_front_ALT_Identsym_SEP_commasym_SP (void);	/* state 321 */
List_Ident Parse_state_front_IdentList (void);	/* state 322 */
List_front_Type Parse_state_front_ALT_Type_SEP_commasym_SP (void);	/* state 323 */
List_front_Type Parse_state_front_TypeList (void);	/* state 324 */
front_ScanInfo Parse_state_front_ScanInfo (void);	/* state 325 */
front_NameSpace Parse_state_front_NameSpace (void);	/* state 326 */
Ident Parse_state_front_Oper (void);	/* state 327 */
List_front_Check Parse_state_front_OPTMORE_Check (void);	/* state 328 */

/* directors of state 0
   hole_Import FROMsym 
 */
List_front_Import Parse_state_front_OPTMORE_Import (void)	/* state 0 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x2, 0x0, 0x100000, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(0);
    switch (_front_symbol) {
    case OPTMORE_Import_value:
      n = 1; break; /* accept OPTMORE_Import  ->  . Import OPTMORE_Import     followers: front_EOF  */
    case FROMsym_value:
      {
        static Int my_followers[] = { 0x2, 0x0, 0x120000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Import_value: HOLE_ACTION (0, "Import");
    case Import_value:
      {
        n = Parse_state_13(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Import  ->  .      followers: front_EOF  */
      n = 0; _front_symbol = OPTMORE_Import_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Import);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_Import")->sub.PointerValue;
}

/* directors of state 1
   Identsym 
 */
static int Parse_state_1 (SymbolSet followers)	/* state 1 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_2(followers);
      }
  return n-1;
}

/* directors of state 2
   colonsym 
 */
static int Parse_state_2 (SymbolSet followers)	/* state 2 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(followers);
      }
  return n-1;
}

/* directors of state 3
   hole_ImportedNonTerminals hole_ALT_ImportedNonTerminal_SEP_commasym hole_ImportedNonTerminal Identsym 
 */
static int Parse_state_3 (SymbolSet followers)	/* state 3 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x680000, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(3);
    switch (_front_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case hole_ImportedNonTerminal_value: HOLE_ACTION (0, "ImportedNonTerminal");
    case ImportedNonTerminal_value:
      {
        n = Parse_state_8(followers);
        break;
      }
    case hole_ALT_ImportedNonTerminal_SEP_commasym_value: HOLE_ACTION (0, "List_ImportedNonTerminal");
    case ALT_ImportedNonTerminal_SEP_commasym_value:
      {
        n = Parse_state_11();
        break;
      }
    case hole_ImportedNonTerminals_value: HOLE_ACTION (0, "List_ImportedNonTerminal");
    case ImportedNonTerminals_value:
      {
        n = Parse_state_12();
        break;
      }
    default:
    /* default item:Import  ->  FROMsym Identsym colonsym . ImportedNonTerminals    followers: front_EOF hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym  */
/* nt = 0x82496f0 */
      InputError (SCAN_POSITION, TRUE, "ImportedNonTerminals expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_ImportedNonTerminal);
      _front_symbol = ImportedNonTerminals_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 4
   colonsym 
 */
static int Parse_state_4 (SymbolSet followers)	/* state 4 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x8, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(4);
    switch (_front_symbol) {
    case colonsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_5(followers);
        break;
      }
    case OPT_colonsym_Identsym_value:
      {
        n = Parse_state_7();
        break;
      }
    default:
    /* default item:ImportedNonTerminal  ->  Identsym . OPT_colonsym_Identsym       followers: commasym front_EOF hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      _front_symbol = OPT_colonsym_Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 5
   Identsym 
 */
static int Parse_state_5 (SymbolSet followers)	/* state 5 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_6();
      }
  return n-1;
}

/* directors of state 8
   commasym 
 */
static int Parse_state_8 (SymbolSet followers)	/* state 8 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(8);
    switch (_front_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_9(followers);
        break;
      }
    default:
    /* default item:ALT_ImportedNonTerminal_SEP_commasym  ->  ImportedNonTerminal . followers: front_EOF hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym  */
      n = 1; _front_symbol = ALT_ImportedNonTerminal_SEP_commasym_value;
      { /* alt action */
        front_ImportedNonTerminal  _id_0 = POP_PARSEVALUE (Pointer, front_ImportedNonTerminal);
        PUSH_PARSEVALUE(Pointer,Create_List_front_ImportedNonTerminal(_id_0,NULL),List_front_ImportedNonTerminal);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 9
   hole_ALT_ImportedNonTerminal_SEP_commasym hole_ImportedNonTerminal Identsym 
 */
static int Parse_state_9 (SymbolSet followers)	/* state 9 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x600000, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(9);
    switch (_front_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case hole_ImportedNonTerminal_value: HOLE_ACTION (0, "ImportedNonTerminal");
    case ImportedNonTerminal_value:
      {
        n = Parse_state_8(followers);
        break;
      }
    case hole_ALT_ImportedNonTerminal_SEP_commasym_value: HOLE_ACTION (0, "List_ImportedNonTerminal");
    case ALT_ImportedNonTerminal_SEP_commasym_value:
      {
        n = Parse_state_10();
        break;
      }
    default:
    /* default item:ALT_ImportedNonTerminal_SEP_commasym  ->  ImportedNonTerminal commasym . ALT_ImportedNonTerminal_SEP_commasym   followers: front_EOF hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_ImportedNonTerminal_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_ImportedNonTerminal);
      _front_symbol = ALT_ImportedNonTerminal_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 13
   hole_OPTMORE_Import hole_Import FROMsym 
 */
static int Parse_state_13 (SymbolSet followers)	/* state 13 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x2, 0x0, 0x120000, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(13);
    switch (_front_symbol) {
    case FROMsym_value:
      {
        static Int my_followers[] = { 0x2, 0x0, 0x120000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Import_value: HOLE_ACTION (0, "Import");
    case Import_value:
      {
        n = Parse_state_13(followers);
        break;
      }
    case hole_OPTMORE_Import_value: HOLE_ACTION (0, "List_Import");
    case OPTMORE_Import_value:
      {
        n = Parse_state_14();
        break;
      }
    default:
    /* default item:OPTMORE_Import  ->  Import . OPTMORE_Import     followers: front_EOF hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Import);
      _front_symbol = OPTMORE_Import_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 15
   USEsym NAMESPACEsym hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym 
 */
front_front Parse_state_front_front (void)	/* state 15 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x6, 0x8000, 0x992002c, 0x0, 0x20 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(15);
    switch (_front_symbol) {
    case front_value:
      n = 1; break; /* accept front  ->  . OPT_USEsym_IdentList OPT_NAMESPACEsym_NameSpaceList OPTMORE_Import OPT_NonTerminals        followers: front_EOF  */
    case USEsym_value:
      {
        static Int my_followers[] = { 0x6, 0x8000, 0x9920028, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_16(_followers);
        break;
      }
    case OPT_USEsym_IdentList_value:
      {
        n = Parse_state_22(followers);
        break;
      }
    default:
    /* default item:front  ->  . OPT_USEsym_IdentList OPT_NAMESPACEsym_NameSpaceList OPTMORE_Import OPT_NonTerminals   followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _front_symbol = OPT_USEsym_IdentList_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_front")->sub.PointerValue;
}

/* directors of state 16
   hole_IdentList hole_ALT_Identsym_SEP_commasym_SP Identsym 
 */
static int Parse_state_16 (SymbolSet followers)	/* state 16 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x0, 0x6 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(16);
    switch (_front_symbol) {
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
        break;
      }
    case hole_ALT_Identsym_SEP_commasym_SP_value: HOLE_ACTION (0, "List_Ident");
    case ALT_Identsym_SEP_commasym_SP_value:
      {
        n = Parse_state_20();
        break;
      }
    case hole_IdentList_value: HOLE_ACTION (0, "List_Ident");
    case IdentList_value:
      {
        n = Parse_state_21();
        break;
      }
    default:
    /* default item:OPT_USEsym_IdentList  ->  USEsym . IdentList    followers: NAMESPACEsym hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = 0x826c438 */
      InputError (SCAN_POSITION, TRUE, "IdentList expected");
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _front_symbol = IdentList_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 17
   commasym 
 */
static int Parse_state_17 (SymbolSet followers)	/* state 17 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(17);
    switch (_front_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_18(followers);
        break;
      }
    default:
    /* default item:ALT_Identsym_SEP_commasym_SP  ->  Identsym .    followers: NAMESPACEsym hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
      n = 1; _front_symbol = ALT_Identsym_SEP_commasym_SP_value;
      { /* alt action */
        Ident  ids = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,Create_List_Ident(ids,NULL),List_Ident);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 18
   hole_ALT_Identsym_SEP_commasym_SP Identsym 
 */
static int Parse_state_18 (SymbolSet followers)	/* state 18 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x0, 0x2 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(18);
    switch (_front_symbol) {
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
        break;
      }
    case hole_ALT_Identsym_SEP_commasym_SP_value: HOLE_ACTION (0, "List_Ident");
    case ALT_Identsym_SEP_commasym_SP_value:
      {
        n = Parse_state_19();
        break;
      }
    default:
    /* default item:ALT_Identsym_SEP_commasym_SP  ->  Identsym commasym . ALT_Identsym_SEP_commasym_SP      followers: NAMESPACEsym hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Identsym_SEP_commasym_SP expected");
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _front_symbol = ALT_Identsym_SEP_commasym_SP_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 22
   NAMESPACEsym hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym 
 */
static int Parse_state_22 (SymbolSet followers)	/* state 22 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x6, 0x8000, 0x9920028, 0x0, 0x20 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(22);
    switch (_front_symbol) {
    case NAMESPACEsym_value:
      {
        static Int my_followers[] = { 0x6, 0x8000, 0x9920020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_23(_followers);
        break;
      }
    case OPT_NAMESPACEsym_NameSpaceList_value:
      {
        n = Parse_state_30(followers);
        break;
      }
    default:
    /* default item:front  ->  OPT_USEsym_IdentList . OPT_NAMESPACEsym_NameSpaceList OPTMORE_Import OPT_NonTerminals        followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_NameSpace);
      _front_symbol = OPT_NAMESPACEsym_NameSpaceList_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 23
   hole_NameSpaceList hole_ALT_NameSpace_SEP_commasym_SP hole_NameSpace Identsym 
 */
static int Parse_state_23 (SymbolSet followers)	/* state 23 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x60000000, 0x40 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(23);
    switch (_front_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_24();
        break;
      }
    case hole_NameSpace_value: HOLE_ACTION (0, "NameSpace");
    case NameSpace_value:
      {
        n = Parse_state_25(followers);
        break;
      }
    case hole_ALT_NameSpace_SEP_commasym_SP_value: HOLE_ACTION (0, "List_NameSpace");
    case ALT_NameSpace_SEP_commasym_SP_value:
      {
        n = Parse_state_28();
        break;
      }
    case hole_NameSpaceList_value: HOLE_ACTION (0, "List_NameSpace");
    case NameSpaceList_value:
      {
        n = Parse_state_29();
        break;
      }
    default:
    /* default item:OPT_NAMESPACEsym_NameSpaceList  ->  NAMESPACEsym . NameSpaceList        followers: hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = 0x826ba78 */
      InputError (SCAN_POSITION, TRUE, "NameSpaceList expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_NameSpace);
      _front_symbol = NameSpaceList_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 25
   commasym 
 */
static int Parse_state_25 (SymbolSet followers)	/* state 25 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(25);
    switch (_front_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26(followers);
        break;
      }
    default:
    /* default item:ALT_NameSpace_SEP_commasym_SP  ->  NameSpace .  followers: hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
      n = 1; _front_symbol = ALT_NameSpace_SEP_commasym_SP_value;
      { /* alt action */
        front_NameSpace  namespace = POP_PARSEVALUE (Pointer, front_NameSpace);
        PUSH_PARSEVALUE(Pointer,Create_List_front_NameSpace(namespace,NULL),List_front_NameSpace);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 26
   hole_ALT_NameSpace_SEP_commasym_SP hole_NameSpace Identsym 
 */
static int Parse_state_26 (SymbolSet followers)	/* state 26 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x20000000, 0x40 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(26);
    switch (_front_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_24();
        break;
      }
    case hole_NameSpace_value: HOLE_ACTION (0, "NameSpace");
    case NameSpace_value:
      {
        n = Parse_state_25(followers);
        break;
      }
    case hole_ALT_NameSpace_SEP_commasym_SP_value: HOLE_ACTION (0, "List_NameSpace");
    case ALT_NameSpace_SEP_commasym_SP_value:
      {
        n = Parse_state_27();
        break;
      }
    default:
    /* default item:ALT_NameSpace_SEP_commasym_SP  ->  NameSpace commasym . ALT_NameSpace_SEP_commasym_SP   followers: hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_NameSpace_SEP_commasym_SP expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_NameSpace);
      _front_symbol = ALT_NameSpace_SEP_commasym_SP_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 30
   hole_OPTMORE_Import hole_Import FROMsym hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym 
 */
static int Parse_state_30 (SymbolSet followers)	/* state 30 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x6, 0x8000, 0x9920020, 0x0, 0x20 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(30);
    switch (_front_symbol) {
    case FROMsym_value:
      {
        static Int my_followers[] = { 0x6, 0x8000, 0x9920020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Import_value: HOLE_ACTION (0, "Import");
    case Import_value:
      {
        static Int my_followers[] = { 0x4, 0x8000, 0x9800020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_13(_followers);
        break;
      }
    case hole_OPTMORE_Import_value: HOLE_ACTION (0, "List_Import");
    case OPTMORE_Import_value:
      {
        n = Parse_state_31(followers);
        break;
      }
    default:
    /* default item:front  ->  OPT_USEsym_IdentList OPT_NAMESPACEsym_NameSpaceList . OPTMORE_Import OPT_NonTerminals        followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Import);
      _front_symbol = OPTMORE_Import_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 31
   hole_NonTerminals hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym 
 */
static int Parse_state_31 (SymbolSet followers)	/* state 31 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x8000, 0x9800020, 0x0, 0x20 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(31);
    switch (_front_symbol) {
    case hole_ScanInfo_value:
    case SCANsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPT_ROOTsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case ROOTsym_value:
      {
        static Int my_followers[] = { 0x4, 0x8000, 0x8800020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_32();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_ROOTsym_value:
      {
        static Int my_followers[] = { 0x4, 0x8000, 0x8800020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_33(_followers);
        break;
      }
    case hole_NonTerminal_value: HOLE_ACTION (0, "NonTerminal");
    case NonTerminal_value:
      {
        n = Parse_state_266(followers);
        break;
      }
    case hole_MORE_NonTerminal_value: HOLE_ACTION (0, "List_NonTerminal");
    case MORE_NonTerminal_value:
      {
        n = Parse_state_268();
        break;
      }
    case hole_NonTerminals_value: HOLE_ACTION (0, "List_NonTerminal");
    case NonTerminals_value:
      {
        n = Parse_state_269();
        break;
      }
    case OPT_NonTerminals_value:
      {
        n = Parse_state_270();
        break;
      }
    default:
    /* default item:front  ->  OPT_USEsym_IdentList OPT_NAMESPACEsym_NameSpaceList OPTMORE_Import . OPT_NonTerminals        followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_NonTerminal);
      _front_symbol = OPT_NonTerminals_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 33
   hole_ScanInfo SCANsym Identsym 
 */
static int Parse_state_33 (SymbolSet followers)	/* state 33 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x8000, 0x0, 0x0, 0x20 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(33);
    switch (_front_symbol) {
    case SCANsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case hole_ScanInfo_value: HOLE_ACTION (0, "ScanInfo");
    case ScanInfo_value:
      {
        static Int my_followers[] = { 0x4, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_50();
        break;
      }
    case OPT_ScanInfo_value:
      {
        n = Parse_state_51(followers);
        break;
      }
    default:
    /* default item:NonTerminal  ->  OPT_ROOTsym . OPT_ScanInfo Identsym OPT_Super OPT_MEMOsym OPT_ENUMsym OPT_SKIPsym Defines Rhs semicolonsym     followers: hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,front_ScanInfo);
      _front_symbol = OPT_ScanInfo_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 34
   hole_OptType TYPEsym COMMENTsym 
 */
static int Parse_state_34 (SymbolSet followers)	/* state 34 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x10400, 0x2000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(34);
    switch (_front_symbol) {
    case COMMENTsym_value:
    case Identsym_value:
    case front_EOF_value:
      n = 0; _front_symbol = OPT_TYPEsym_Type_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,front_Type);
      }
      break;
    case TYPEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(_followers);
        break;
      }
    case OPT_TYPEsym_Type_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_46();
        break;
      }
    case hole_OptType_value: HOLE_ACTION (0, "Type");
    case OptType_value:
      {
        n = Parse_state_47(followers);
        break;
      }
    default:
    /* default item:ScanInfo  ->  SCANsym . OptType OPT_COMMENTsym  followers: Identsym front_EOF  */
/* nt = 0x825f888 */
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = OptType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 35
   hole_Type Identsym 
 */
static int Parse_state_35 (SymbolSet followers)	/* state 35 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x80000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(35);
    switch (_front_symbol) {
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_36(followers);
        break;
      }
    case hole_Type_value: HOLE_ACTION (0, "Type");
    case Type_value:
      {
        n = Parse_state_45();
        break;
      }
    default:
    /* default item:OPT_TYPEsym_Type  ->  TYPEsym . Type    followers: COMMENTsym NAMESPACEsym hole_ScopeExpr SCOPEsym hole_MORE_Symbol closechainsym closebrksym closeparsym lessthansym CHECKSsym semicolonsym front_EOF COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym  */
/* nt = 0x8265dd0 */
      InputError (SCAN_POSITION, TRUE, "Type expected");
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = Type_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 36
   openparsym 
 */
static int Parse_state_36 (SymbolSet followers)	/* state 36 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x2, 0x0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(36);
    switch (_front_symbol) {
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_37(followers);
        break;
      }
    case OPT_openparsym_TypeList_closeparsym_value:
      {
        n = Parse_state_44();
        break;
      }
    default:
    /* default item:Type  ->  Identsym . OPT_openparsym_TypeList_closeparsym        followers: commasym equalssym COMMENTsym NAMESPACEsym hole_ScopeExpr SCOPEsym hole_MORE_Symbol closechainsym closebrksym closeparsym lessthansym CHECKSsym semicolonsym front_EOF COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Type);
      _front_symbol = OPT_openparsym_TypeList_closeparsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 37
   hole_TypeList hole_ALT_Type_SEP_commasym_SP hole_Type Identsym 
 */
static int Parse_state_37 (SymbolSet followers)	/* state 37 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x80000, 0x18 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(37);
    switch (_front_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_36(_followers);
        break;
      }
    case hole_Type_value: HOLE_ACTION (0, "Type");
    case Type_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_38(_followers);
        break;
      }
    case hole_ALT_Type_SEP_commasym_SP_value: HOLE_ACTION (0, "List_Type");
    case ALT_Type_SEP_commasym_SP_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_41();
        break;
      }
    case hole_TypeList_value: HOLE_ACTION (0, "List_Type");
    case TypeList_value:
      {
        n = Parse_state_42();
        break;
      }
    default:
    /* default item:OPT_openparsym_TypeList_closeparsym  ->  openparsym . TypeList closeparsym      followers: commasym equalssym COMMENTsym NAMESPACEsym hole_ScopeExpr SCOPEsym hole_MORE_Symbol closechainsym closebrksym closeparsym lessthansym CHECKSsym semicolonsym front_EOF COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym  */
/* nt = 0x826c918 */
      InputError (SCAN_POSITION, TRUE, "TypeList expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_Type);
      _front_symbol = TypeList_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 38
   commasym 
 */
static int Parse_state_38 (SymbolSet followers)	/* state 38 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(38);
    switch (_front_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(followers);
        break;
      }
    default:
    /* default item:ALT_Type_SEP_commasym_SP  ->  Type .    followers: closeparsym front_EOF  */
      n = 1; _front_symbol = ALT_Type_SEP_commasym_SP_value;
      { /* alt action */
        front_Type  types = POP_PARSEVALUE (Pointer, front_Type);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Type(types,NULL),List_front_Type);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 39
   hole_ALT_Type_SEP_commasym_SP hole_Type Identsym 
 */
static int Parse_state_39 (SymbolSet followers)	/* state 39 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x80000, 0x8 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(39);
    switch (_front_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_36(_followers);
        break;
      }
    case hole_Type_value: HOLE_ACTION (0, "Type");
    case Type_value:
      {
        n = Parse_state_38(followers);
        break;
      }
    case hole_ALT_Type_SEP_commasym_SP_value: HOLE_ACTION (0, "List_Type");
    case ALT_Type_SEP_commasym_SP_value:
      {
        n = Parse_state_40();
        break;
      }
    default:
    /* default item:ALT_Type_SEP_commasym_SP  ->  Type commasym . ALT_Type_SEP_commasym_SP  followers: closeparsym front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Type_SEP_commasym_SP expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_Type);
      _front_symbol = ALT_Type_SEP_commasym_SP_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_42 (void)	/* state 42 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_43();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 47
   COMMENTsym 
 */
static int Parse_state_47 (SymbolSet followers)	/* state 47 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x10000, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(47);
    switch (_front_symbol) {
    case COMMENTsym_value:
      {
        n = Parse_state_48();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_COMMENTsym_value:
      {
        n = Parse_state_49();
        break;
      }
    default:
    /* default item:ScanInfo  ->  SCANsym OptType . OPT_COMMENTsym  followers: Identsym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_COMMENTsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 51
   Identsym 
 */
static int Parse_state_51 (SymbolSet followers)	/* state 51 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_52(followers);
      }
  return n-1;
}

/* directors of state 52
   hole_Super colonsym lessthansym MEMOsym ENUMsym SKIPsym hole_Defines equalssym definessym 
 */
static int Parse_state_52 (SymbolSet followers)	/* state 52 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x428, 0x20, 0x120001c0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(52);
    switch (_front_symbol) {
    case lessthansym_value:
      {
        static Int my_followers[] = { 0x400, 0x20, 0x20001c0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_53(_followers);
        break;
      }
    case colonsym_value:
      {
        static Int my_followers[] = { 0x400, 0x20, 0x20001c0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_55(_followers);
        break;
      }
    case hole_Super_value: HOLE_ACTION (0, "Super");
    case Super_value:
      {
        static Int my_followers[] = { 0x400, 0x20, 0x20001c0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_57();
        break;
      }
    case OPT_Super_value:
      {
        n = Parse_state_58(followers);
        break;
      }
    default:
    /* default item:NonTerminal  ->  OPT_ROOTsym OPT_ScanInfo Identsym . OPT_Super OPT_MEMOsym OPT_ENUMsym OPT_SKIPsym Defines Rhs semicolonsym     followers: hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,front_Super);
      _front_symbol = OPT_Super_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 53
   Identsym 
 */
static int Parse_state_53 (SymbolSet followers)	/* state 53 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_54();
      }
  return n-1;
}

/* directors of state 55
   Identsym 
 */
static int Parse_state_55 (SymbolSet followers)	/* state 55 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56();
      }
  return n-1;
}

/* directors of state 58
   MEMOsym ENUMsym SKIPsym hole_Defines equalssym definessym 
 */
static int Parse_state_58 (SymbolSet followers)	/* state 58 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x400, 0x20, 0x20001c0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(58);
    switch (_front_symbol) {
    case MEMOsym_value:
      {
        static Int my_followers[] = { 0x400, 0x20, 0x2000180, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_59();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_MEMOsym_value:
      {
        n = Parse_state_60(followers);
        break;
      }
    default:
    /* default item:NonTerminal  ->  OPT_ROOTsym OPT_ScanInfo Identsym OPT_Super . OPT_MEMOsym OPT_ENUMsym OPT_SKIPsym Defines Rhs semicolonsym     followers: hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_MEMOsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 60
   ENUMsym SKIPsym hole_Defines equalssym definessym 
 */
static int Parse_state_60 (SymbolSet followers)	/* state 60 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x400, 0x20, 0x2000180, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(60);
    switch (_front_symbol) {
    case ENUMsym_value:
      {
        static Int my_followers[] = { 0x400, 0x20, 0x2000100, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_61();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_ENUMsym_value:
      {
        n = Parse_state_62(followers);
        break;
      }
    default:
    /* default item:NonTerminal  ->  OPT_ROOTsym OPT_ScanInfo Identsym OPT_Super OPT_MEMOsym . OPT_ENUMsym OPT_SKIPsym Defines Rhs semicolonsym     followers: hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_ENUMsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 62
   SKIPsym hole_Defines equalssym definessym 
 */
static int Parse_state_62 (SymbolSet followers)	/* state 62 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x400, 0x20, 0x2000100, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(62);
    switch (_front_symbol) {
    case SKIPsym_value:
      {
        static Int my_followers[] = { 0x400, 0x20, 0x2000000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_63();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_SKIPsym_value:
      {
        n = Parse_state_64(followers);
        break;
      }
    default:
    /* default item:NonTerminal  ->  OPT_ROOTsym OPT_ScanInfo Identsym OPT_Super OPT_MEMOsym OPT_ENUMsym . OPT_SKIPsym Defines Rhs semicolonsym     followers: hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_SKIPsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 64
   hole_Defines equalssym definessym 
 */
static int Parse_state_64 (SymbolSet followers)	/* state 64 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x400, 0x20, 0x2000000, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(64);
    switch (_front_symbol) {
    case definessym_value:
      {
        static Int my_followers[] = { 0xcaf801f4, 0x605d, 0xe4000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.definessym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_65();
        break;
      }
    case equalssym_value:
      {
        static Int my_followers[] = { 0xcaf801f4, 0x605d, 0xe4000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_66();
        break;
      }
    case hole_Defines_value: HOLE_ACTION (0, "Defines");
    case Defines_value:
      {
        n = Parse_state_67(followers);
        break;
      }
    default:
    /* default item:NonTerminal  ->  OPT_ROOTsym OPT_ScanInfo Identsym OPT_Super OPT_MEMOsym OPT_ENUMsym OPT_SKIPsym . Defines Rhs semicolonsym     followers: hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = 0x826e330 */
      n = 0; _front_symbol = Defines_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Defines");
        me->sub.PointerValue = Create_front_MacroDef(src_info, id);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 67
   hole_Rhs hole_OPTMORE_Scoping hole_Scoping CLOSESCOPEsym OPENSCOPEsym SCOPEsym hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym lessthansym CHECKSsym semicolonsym 
 */
static int Parse_state_67 (SymbolSet followers)	/* state 67 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf801f4, 0x605d, 0xe4000800, 0x210e3e, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(67);
    switch (_front_symbol) {
    case hole_Symbol1_value:
    case hole_SymbolSeq_value:
    case hole_Field_value:
    case Identsym_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
    case hole_AltSymbol_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case lessthansym_value:
    case CHECKSsym_value:
    case semicolonsym_value:
      n = 0; _front_symbol = OPTMORE_Scoping_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Scoping);
      }
      break;
    case SCOPEsym_value:
      {
        static Int my_followers[] = { 0xcaf801f4, 0x605d, 0xe0000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_68();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPENSCOPEsym_value:
      {
        static Int my_followers[] = { 0xcaf801f4, 0x605d, 0xe0000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_69();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case CLOSESCOPEsym_value:
      {
        static Int my_followers[] = { 0xcaf801f4, 0x605d, 0xe0000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_70();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Scoping_value: HOLE_ACTION (0, "Scoping");
    case Scoping_value:
      {
        static Int my_followers[] = { 0xcaf80034, 0x605d, 0x40000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_71(_followers);
        break;
      }
    case hole_OPTMORE_Scoping_value: HOLE_ACTION (0, "List_Scoping");
    case OPTMORE_Scoping_value:
      {
        static Int my_followers[] = { 0x10, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_73(_followers);
        break;
      }
    case hole_Rhs_value: HOLE_ACTION (0, "Rhs");
    case Rhs_value:
      {
        n = Parse_state_264();
        break;
      }
    default:
    /* default item:NonTerminal  ->  OPT_ROOTsym OPT_ScanInfo Identsym OPT_Super OPT_MEMOsym OPT_ENUMsym OPT_SKIPsym Defines . Rhs semicolonsym     followers: hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym front_EOF  */
/* nt = 0x824fca0 */
      PUSH_PARSEVALUE(Pointer,0,front_Rhs);
      _front_symbol = Rhs_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 71
   hole_OPTMORE_Scoping hole_Scoping CLOSESCOPEsym OPENSCOPEsym SCOPEsym 
 */
static int Parse_state_71 (SymbolSet followers)	/* state 71 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x1c0, 0x0, 0xa0000000, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(71);
    switch (_front_symbol) {
    case SCOPEsym_value:
      {
        static Int my_followers[] = { 0x1c0, 0x0, 0xa0000000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_68();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPENSCOPEsym_value:
      {
        static Int my_followers[] = { 0x1c0, 0x0, 0xa0000000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_69();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case CLOSESCOPEsym_value:
      {
        static Int my_followers[] = { 0x1c0, 0x0, 0xa0000000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_70();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Scoping_value: HOLE_ACTION (0, "Scoping");
    case Scoping_value:
      {
        n = Parse_state_71(followers);
        break;
      }
    case hole_OPTMORE_Scoping_value: HOLE_ACTION (0, "List_Scoping");
    case OPTMORE_Scoping_value:
      {
        n = Parse_state_72();
        break;
      }
    default:
    /* default item:OPTMORE_Scoping  ->  Scoping . OPTMORE_Scoping  followers: semicolonsym hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym lessthansym CHECKSsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Scoping);
      _front_symbol = OPTMORE_Scoping_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 73
   hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym lessthansym CHECKSsym 
 */
static int Parse_state_73 (SymbolSet followers)	/* state 73 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80024, 0x605d, 0x40000800, 0x210e3e, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(73);
    switch (_front_symbol) {
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case lessthansym_value:
    case CHECKSsym_value:
    case semicolonsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case greaterthansym_value:
    case front_EOF_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_137(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafc3824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcaf83824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcaf83824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcaf83824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcaf83824, 0x605d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x20, 0x6040, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x20, 0x6040, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x20, 0x6040, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        static Int my_followers[] = { 0x20, 0x40, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_182(_followers);
        break;
      }
    case hole_AltSymbol_value: HOLE_ACTION (0, "AltSymbol");
    case AltSymbol_value:
      {
        static Int my_followers[] = { 0x20, 0x40, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_192();
        break;
      }
    case hole_Symbol1_value: HOLE_ACTION (0, "Symbol1");
    case Symbol1_value:
      {
        n = Parse_state_235(followers);
        break;
      }
    default:
    /* default item:Rhs  ->  OPTMORE_Scoping . Symbol1 OPT_Choices OPT_CHECKSsym_OPTMORE_Check      followers: semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = 0x8254c48 */
      n = 0; _front_symbol = Symbol1_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 75
   hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
static int Parse_state_75 (SymbolSet followers)	/* state 75 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x1c, 0x0, 0x10000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(75);
    switch (_front_symbol) {
    case DEFININGsym_value:
      {
        static Int my_followers[] = { 0x4, 0x2, 0x0, 0x20800, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_76();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case REDEFININGsym_value:
      {
        static Int my_followers[] = { 0x4, 0x2, 0x0, 0x20800, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_77();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OVERLOADINGsym_value:
      {
        static Int my_followers[] = { 0x4, 0x2, 0x0, 0x20800, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_78();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Define_value: HOLE_ACTION (0, "Define");
    case Define_value:
      {
        n = Parse_state_79(followers);
        break;
      }
    default:
    /* default item:DefiningSym  ->  OPT_FORWARDsym . Define Defining_id OPT_NAMESPACEsym_Identsym OPT_ScopeExpr    followers: hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8262428 */
      n = 0; _front_symbol = Define_value;
      PUSH_PARSEVALUE(Int,front_Overloading,front_Define);
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 79
   hole_Defining_id openparsym hole_IdSym Identsym 
 */
static int Parse_state_79 (SymbolSet followers)	/* state 79 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x2, 0x0, 0x20800, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(79);
    switch (_front_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x40, 0x0, 0x8, 0x40000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_80(_followers);
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0x40, 0x0, 0x8, 0x40000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_82();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x40, 0x0, 0x8, 0x40000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_83(_followers);
        break;
      }
    case hole_Defining_id_value: HOLE_ACTION (0, "Defining_id");
    case Defining_id_value:
      {
        n = Parse_state_129(followers);
        break;
      }
    default:
    /* default item:DefiningSym  ->  OPT_FORWARDsym Define . Defining_id OPT_NAMESPACEsym_Identsym OPT_ScopeExpr    followers: hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8261858 */
      n = 0; _front_symbol = Defining_id_value;
      { ParseValue me;
        front_Expr  e = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Defining_id");
        me->sub.PointerValue = Create_front_DefExpr(src_info, e);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 80
   hole_OptType TYPEsym 
 */
static int Parse_state_80 (SymbolSet followers)	/* state 80 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x400, 0x2000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(80);
    switch (_front_symbol) {
    case NAMESPACEsym_value:
    case hole_ScopeExpr_value:
    case SCOPEsym_value:
    case hole_MORE_Symbol_value:
    case lessthansym_value:
    case CHECKSsym_value:
    case semicolonsym_value:
    case greaterthansym_value:
    case front_EOF_value:
    case closeparsym_value:
    case closebrksym_value:
    case COMPAREsym_value:
    case hole_And_value:
    case RightAndsym_value:
    case LeftAndsym_value:
    case Newlinesym_value:
    case hole_Field_value:
    case Identsym_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case closechainsym_value:
      n = 0; _front_symbol = OPT_TYPEsym_Type_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,front_Type);
      }
      break;
    case TYPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    case OPT_TYPEsym_Type_value:
      {
        n = Parse_state_46();
        break;
      }
    case hole_OptType_value: HOLE_ACTION (0, "Type");
    case OptType_value:
      {
        n = Parse_state_81();
        break;
      }
    default:
    /* default item:IdSym  ->  Identsym . OptType   followers: NAMESPACEsym hole_ScopeExpr SCOPEsym hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x825f888 */
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = OptType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 83
   hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_83 (SymbolSet followers)	/* state 83 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(83);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x21000000, 0xffff0000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_112(_followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_127();
        break;
      }
    default:
    /* default item:Defining_id  ->  openparsym . Expr closeparsym  followers: NAMESPACEsym hole_ScopeExpr SCOPEsym hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8266530 */
      n = 0; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 101
   hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym 
 */
static int Parse_state_101 (SymbolSet followers)	/* state 101 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(101);
    switch (_front_symbol) {
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        n = Parse_state_101(followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        n = Parse_state_102();
        break;
      }
    default:
    /* default item:OPTMORE_Oper  ->  Oper . OPTMORE_Oper   followers: hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _front_symbol = OPTMORE_Oper_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 103
   hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_103 (SymbolSet followers)	/* state 103 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x700004, 0x700, 0x0, 0x2004000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(103);
    switch (_front_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x0, 0x82, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_104();
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0x0, 0x82, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_105();
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0x0, 0x82, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_106();
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x82, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_107();
        break;
      }
    case hole_SimpleExpr_value: HOLE_ACTION (0, "SimpleExpr");
    case SimpleExpr_value:
      {
        n = Parse_state_108(followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x0, 0x82, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,front_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_123();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x0, 0x82, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,front_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_124();
        break;
      }
    case hole_StringOrKeyword_value: HOLE_ACTION (0, "String");
    case StringOrKeyword_value:
      {
        static Int my_followers[] = { 0x0, 0x82, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_125();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x0, 0x82, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_126();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
    /* default item:MonExpr1  ->  OPTMORE_Oper . SimpleExpr followers: THENsym commasym TRAVERSEsym CLEARsym DONT_CLEARsym hole_MORE_MonExpr1 hole_MonExpr1 hole_OPTMORE_Oper hole_SimpleExpr NULLsym hole_StringOrKeyword Boolsym Intsym hole_OPTMORE_Check hole_Check IFsym hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym WARNINGsym hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8269b60 */
      n = 0; _front_symbol = SimpleExpr_value;
      { ParseValue me;
        List_front_Expr  exprs = POP_PARSEVALUE (Pointer, List_front_Expr);
        front_Expr  func = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_CallExpr(src_info, func, exprs);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 108
   openparsym dotsym 
 */
static int Parse_state_108 (SymbolSet followers)	/* state 108 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x82, 0x0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(108);
    switch (_front_symbol) {
    case dotsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_109(followers);
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_111(followers);
        break;
      }
    default:
    /* default item:MonExpr1  ->  OPTMORE_Oper SimpleExpr . followers: THENsym commasym TRAVERSEsym CLEARsym DONT_CLEARsym hole_MORE_MonExpr1 hole_MonExpr1 hole_OPTMORE_Oper hole_SimpleExpr NULLsym hole_StringOrKeyword Boolsym Intsym hole_OPTMORE_Check hole_Check IFsym hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym WARNINGsym hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
      n = 2; _front_symbol = MonExpr1_value;
      { ParseValue me;
        front_Expr  arg = POP_PARSEVALUE (Pointer, front_Expr);
        List_Ident  op = POP_PARSEVALUE (Pointer, List_Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_MonExpr(src_info, op, arg);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 109
   Identsym 
 */
static int Parse_state_109 (SymbolSet followers)	/* state 109 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_110();
      }
  return n-1;
}

/* directors of state 111
   hole_ExprList hole_ALT_Expr_SEP_commasym_SP hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym closeparsym 
 */
static int Parse_state_111 (SymbolSet followers)	/* state 111 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x21700004, 0xffff0700, 0x0, 0x8700c000, 0x81 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(111);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x21700004, 0xffff0700, 0x10, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x21000000, 0xffff0000, 0x10, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_112(_followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_116(_followers);
        break;
      }
    case hole_ALT_Expr_SEP_commasym_SP_value: HOLE_ACTION (0, "List_Expr");
    case ALT_Expr_SEP_commasym_SP_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_119();
        break;
      }
    case hole_ExprList_value: HOLE_ACTION (0, "List_Expr");
    case ExprList_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_120();
        break;
      }
    case OPT_ExprList_value:
      {
        n = Parse_state_121();
        break;
      }
    default:
    /* default item:SimpleExpr  ->  SimpleExpr openparsym . OPT_ExprList closeparsym        followers: openparsym dotsym THENsym commasym TRAVERSEsym CLEARsym DONT_CLEARsym hole_MORE_MonExpr1 hole_MonExpr1 hole_OPTMORE_Oper hole_SimpleExpr NULLsym hole_StringOrKeyword Boolsym Intsym hole_OPTMORE_Check hole_Check IFsym hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym WARNINGsym hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Expr);
      _front_symbol = OPT_ExprList_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 112
   hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym 
 */
static int Parse_state_112 (SymbolSet followers)	/* state 112 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(112);
    switch (_front_symbol) {
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        n = Parse_state_113(followers);
        break;
      }
    default:
    /* default item:ALT_MonExpr1_SEP_SP_Oper  ->  MonExpr1 .        followers: THENsym commasym TRAVERSEsym CLEARsym DONT_CLEARsym WARNINGsym hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
      n = 1; _front_symbol = ALT_MonExpr1_SEP_SP_Oper_value;
      { /* alt action */
        front_Expr  args = POP_PARSEVALUE (Pointer, front_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Expr(args,NULL),List_front_Expr);
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 113
   hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_113 (SymbolSet followers)	/* state 113 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(113);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_112(followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        n = Parse_state_114();
        break;
      }
    default:
    /* default item:ALT_MonExpr1_SEP_SP_Oper  ->  MonExpr1 Oper . ALT_MonExpr1_SEP_SP_Oper  followers: THENsym commasym TRAVERSEsym CLEARsym DONT_CLEARsym WARNINGsym hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_MonExpr1_SEP_SP_Oper expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_Expr);
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _front_symbol = ALT_MonExpr1_SEP_SP_Oper_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 116
   commasym 
 */
static int Parse_state_116 (SymbolSet followers)	/* state 116 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(116);
    switch (_front_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_117(followers);
        break;
      }
    default:
    /* default item:ALT_Expr_SEP_commasym_SP  ->  Expr .    followers: closeparsym front_EOF  */
      n = 1; _front_symbol = ALT_Expr_SEP_commasym_SP_value;
      { /* alt action */
        front_Expr  exprs = POP_PARSEVALUE (Pointer, front_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Expr(exprs,NULL),List_front_Expr);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 117
   hole_ALT_Expr_SEP_commasym_SP hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_117 (SymbolSet followers)	/* state 117 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x8700c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(117);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x10, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_112(_followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_116(followers);
        break;
      }
    case hole_ALT_Expr_SEP_commasym_SP_value: HOLE_ACTION (0, "List_Expr");
    case ALT_Expr_SEP_commasym_SP_value:
      {
        n = Parse_state_118();
        break;
      }
    default:
    /* default item:ALT_Expr_SEP_commasym_SP  ->  Expr commasym . ALT_Expr_SEP_commasym_SP  followers: closeparsym front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Expr_SEP_commasym_SP expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_Expr);
      _front_symbol = ALT_Expr_SEP_commasym_SP_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_121 (void)	/* state 121 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_122();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

static int Parse_state_127 (void)	/* state 127 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_128();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 129
   NAMESPACEsym hole_ScopeExpr SCOPEsym 
 */
static int Parse_state_129 (SymbolSet followers)	/* state 129 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x40, 0x0, 0x8, 0x40000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(129);
    switch (_front_symbol) {
    case NAMESPACEsym_value:
      {
        static Int my_followers[] = { 0x40, 0x0, 0x0, 0x40000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_130(_followers);
        break;
      }
    case OPT_NAMESPACEsym_Identsym_value:
      {
        n = Parse_state_132(followers);
        break;
      }
    default:
    /* default item:DefiningSym  ->  OPT_FORWARDsym Define Defining_id . OPT_NAMESPACEsym_Identsym OPT_ScopeExpr    followers: hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      _front_symbol = OPT_NAMESPACEsym_Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 130
   Identsym 
 */
static int Parse_state_130 (SymbolSet followers)	/* state 130 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131();
      }
  return n-1;
}

/* directors of state 132
   hole_ScopeExpr SCOPEsym 
 */
static int Parse_state_132 (SymbolSet followers)	/* state 132 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x40, 0x0, 0x0, 0x40000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(132);
    switch (_front_symbol) {
    case SCOPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133(followers);
        break;
      }
    case hole_ScopeExpr_value: HOLE_ACTION (0, "Expr");
    case ScopeExpr_value:
      {
        n = Parse_state_135();
        break;
      }
    case OPT_ScopeExpr_value:
      {
        n = Parse_state_136();
        break;
      }
    default:
    /* default item:DefiningSym  ->  OPT_FORWARDsym Define Defining_id OPT_NAMESPACEsym_Identsym . OPT_ScopeExpr    followers: hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,front_Expr);
      _front_symbol = OPT_ScopeExpr_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 133
   hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_133 (SymbolSet followers)	/* state 133 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(133);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_112(followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_134();
        break;
      }
    default:
    /* default item:ScopeExpr  ->  SCOPEsym . Expr  followers: WARNINGsym hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8266530 */
      n = 0; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 137
   colonsym hole_OptType TYPEsym 
 */
static int Parse_state_137 (SymbolSet followers)	/* state 137 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x8, 0x0, 0x400, 0x2000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(137);
    switch (_front_symbol) {
    case lessthansym_value:
    case CHECKSsym_value:
    case semicolonsym_value:
    case greaterthansym_value:
    case front_EOF_value:
    case closeparsym_value:
    case closebrksym_value:
    case COMPAREsym_value:
    case hole_And_value:
    case RightAndsym_value:
    case LeftAndsym_value:
    case Newlinesym_value:
    case hole_Field_value:
    case Identsym_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case closechainsym_value:
      n = 0; _front_symbol = OPT_TYPEsym_Type_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,front_Type);
      }
      break;
    case TYPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    case OPT_TYPEsym_Type_value:
      {
        n = Parse_state_46();
        break;
      }
    case hole_OptType_value: HOLE_ACTION (0, "Type");
    case OptType_value:
      {
        n = Parse_state_81();
        break;
      }
    case colonsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_138(followers);
        break;
      }
    default:
    /* default item:IdSym  ->  Identsym . OptType   followers: lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x825f888 */
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = OptType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 138
   hole_Type Identsym hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
static int Parse_state_138 (SymbolSet followers)	/* state 138 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x1d, 0x800, 0x90e02, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(138);
    switch (_front_symbol) {
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x1c, 0x0, 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x20, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_139(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        n = Parse_state_168(followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        n = Parse_state_188();
        break;
      }
    case hole_Type_value: HOLE_ACTION (0, "Type");
    case Type_value:
      {
        n = Parse_state_211(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Symbol  ->  Identsym colonsym . Symbol2 followers: lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x82583d8 */
      n = 0; _front_symbol = Symbol2_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 139
   openparsym hole_OptType TYPEsym 
 */
static int Parse_state_139 (SymbolSet followers)	/* state 139 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x2, 0x400, 0x2000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(139);
    switch (_front_symbol) {
    case COMPAREsym_value:
    case lessthansym_value:
    case CHECKSsym_value:
    case semicolonsym_value:
    case greaterthansym_value:
    case front_EOF_value:
    case closeparsym_value:
    case closebrksym_value:
    case hole_And_value:
    case RightAndsym_value:
    case LeftAndsym_value:
    case Newlinesym_value:
    case hole_Field_value:
    case Identsym_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case closechainsym_value:
      n = 0; _front_symbol = OPT_TYPEsym_Type_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,front_Type);
      }
      break;
    case TYPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    case OPT_TYPEsym_Type_value:
      {
        n = Parse_state_46();
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_37(followers);
        break;
      }
    case hole_OptType_value: HOLE_ACTION (0, "Type");
    case OptType_value:
      {
        n = Parse_state_81();
        break;
      }
    case OPT_openparsym_TypeList_closeparsym_value:
      {
        n = Parse_state_44();
        break;
      }
    default:
    /* default item:Type  ->  Identsym . OPT_openparsym_TypeList_closeparsym        followers: equalssym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Type);
      _front_symbol = OPT_openparsym_TypeList_closeparsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 142
   Identsym 
 */
static int Parse_state_142 (SymbolSet followers)	/* state 142 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(followers);
      }
  return n-1;
}

/* directors of state 143
   hole_NameOrField FIELDsym NAMEsym 
 */
static int Parse_state_143 (SymbolSet followers)	/* state 143 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x3, 0x1000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(143);
    switch (_front_symbol) {
    case NAMEsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_144();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case FIELDsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_145();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_NameOrField_value: HOLE_ACTION (0, "NameOrField");
    case NameOrField_value:
      {
        n = Parse_state_146(followers);
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  APPLIEDsym Identsym . NameOrField Identsym OPT_ScopeExpr OPT_WARNINGsym       followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8272ca8 */
      n = 0; _front_symbol = NameOrField_value;
      PUSH_PARSEVALUE(Int,front_AppliedField,front_NameOrField);
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 146
   Identsym 
 */
static int Parse_state_146 (SymbolSet followers)	/* state 146 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(followers);
      }
  return n-1;
}

/* directors of state 147
   hole_ScopeExpr SCOPEsym WARNINGsym 
 */
static int Parse_state_147 (SymbolSet followers)	/* state 147 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x40, 0x0, 0x200, 0x40000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(147);
    switch (_front_symbol) {
    case SCOPEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x200, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133(_followers);
        break;
      }
    case hole_ScopeExpr_value: HOLE_ACTION (0, "Expr");
    case ScopeExpr_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x200, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_135();
        break;
      }
    case OPT_ScopeExpr_value:
      {
        n = Parse_state_148(followers);
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  APPLIEDsym Identsym NameOrField Identsym . OPT_ScopeExpr OPT_WARNINGsym       followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,front_Expr);
      _front_symbol = OPT_ScopeExpr_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 148
   WARNINGsym 
 */
static int Parse_state_148 (SymbolSet followers)	/* state 148 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x200, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(148);
    switch (_front_symbol) {
    case WARNINGsym_value:
      {
        n = Parse_state_149();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_WARNINGsym_value:
      {
        n = Parse_state_150();
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  APPLIEDsym Identsym NameOrField Identsym OPT_ScopeExpr . OPT_WARNINGsym       followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_WARNINGsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 151
   NAMEsym hole_OptType TYPEsym 
 */
static int Parse_state_151 (SymbolSet followers)	/* state 151 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x401, 0x2000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(151);
    switch (_front_symbol) {
    case NAMEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x400, 0x2000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_152(_followers);
        break;
      }
    case OPT_NAMEsym_Identsym_value:
      {
        n = Parse_state_154(followers);
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  Stringsym . OPT_NAMEsym_Identsym OptType      followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      _front_symbol = OPT_NAMEsym_Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 152
   Identsym 
 */
static int Parse_state_152 (SymbolSet followers)	/* state 152 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_153();
      }
  return n-1;
}

/* directors of state 154
   hole_OptType TYPEsym 
 */
static int Parse_state_154 (SymbolSet followers)	/* state 154 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x400, 0x2000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(154);
    switch (_front_symbol) {
    case hole_MORE_Symbol_value:
    case COMPAREsym_value:
    case lessthansym_value:
    case CHECKSsym_value:
    case semicolonsym_value:
    case greaterthansym_value:
    case front_EOF_value:
    case closeparsym_value:
    case closebrksym_value:
    case hole_And_value:
    case RightAndsym_value:
    case LeftAndsym_value:
    case Newlinesym_value:
    case hole_Field_value:
    case Identsym_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case closechainsym_value:
      n = 0; _front_symbol = OPT_TYPEsym_Type_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,front_Type);
      }
      break;
    case TYPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    case OPT_TYPEsym_Type_value:
      {
        n = Parse_state_46();
        break;
      }
    case hole_OptType_value: HOLE_ACTION (0, "Type");
    case OptType_value:
      {
        n = Parse_state_155();
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  Stringsym OPT_NAMEsym_Identsym . OptType      followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x825f888 */
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = OptType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 156
   hole_OptType TYPEsym 
 */
static int Parse_state_156 (SymbolSet followers)	/* state 156 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x400, 0x2000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(156);
    switch (_front_symbol) {
    case hole_MORE_Symbol_value:
    case COMPAREsym_value:
    case lessthansym_value:
    case CHECKSsym_value:
    case semicolonsym_value:
    case greaterthansym_value:
    case front_EOF_value:
    case closeparsym_value:
    case closebrksym_value:
    case hole_And_value:
    case RightAndsym_value:
    case LeftAndsym_value:
    case Newlinesym_value:
    case hole_Field_value:
    case Identsym_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case closechainsym_value:
      n = 0; _front_symbol = OPT_TYPEsym_Type_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,front_Type);
      }
      break;
    case TYPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    case OPT_TYPEsym_Type_value:
      {
        n = Parse_state_46();
        break;
      }
    case hole_OptType_value: HOLE_ACTION (0, "Type");
    case OptType_value:
      {
        n = Parse_state_157();
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  Charsym . OptType     followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x825f888 */
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = OptType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 158
   hole_OptType TYPEsym 
 */
static int Parse_state_158 (SymbolSet followers)	/* state 158 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x400, 0x2000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(158);
    switch (_front_symbol) {
    case hole_MORE_Symbol_value:
    case COMPAREsym_value:
    case lessthansym_value:
    case CHECKSsym_value:
    case semicolonsym_value:
    case greaterthansym_value:
    case front_EOF_value:
    case closeparsym_value:
    case closebrksym_value:
    case hole_And_value:
    case RightAndsym_value:
    case LeftAndsym_value:
    case Newlinesym_value:
    case hole_Field_value:
    case Identsym_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case closechainsym_value:
      n = 0; _front_symbol = OPT_TYPEsym_Type_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,front_Type);
      }
      break;
    case TYPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    case OPT_TYPEsym_Type_value:
      {
        n = Parse_state_46();
        break;
      }
    case hole_OptType_value: HOLE_ACTION (0, "Type");
    case OptType_value:
      {
        n = Parse_state_159();
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  Keywordsym . OptType  followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x825f888 */
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = OptType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 160
   hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closeparsym 
 */
static int Parse_state_160 (SymbolSet followers)	/* state 160 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcbfbc004, 0x601d, 0x40000800, 0x210f3e, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(160);
    switch (_front_symbol) {
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case closeparsym_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_137(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcbfff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcbfbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcbfbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcbfbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcbfbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x103c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x103c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x103c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        static Int my_followers[] = { 0x103c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_182(_followers);
        break;
      }
    case hole_AltSymbol_value: HOLE_ACTION (0, "AltSymbol");
    case AltSymbol_value:
      {
        static Int my_followers[] = { 0x103c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_192();
        break;
      }
    case hole_Symbol1_value: HOLE_ACTION (0, "Symbol1");
    case Symbol1_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_193(_followers);
        break;
      }
    case ALT_Symbol1_SEP_Or_SP_value:
      {
        static Int my_followers[] = { 0x1000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_200();
        break;
      }
    case Alternatives_value:
      {
        n = Parse_state_208();
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  open2symsym . Alternatives closeparsym closeparsym    followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x825f140 */
      PUSH_PARSEVALUE(Pointer,0,List_front_Symbol);
      PUSH_PARSEVALUE(Pointer,0,List_front_Or);
      _front_symbol = Alternatives_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 161
   hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closebrksym 
 */
static int Parse_state_161 (SymbolSet followers)	/* state 161 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcefbc004, 0x601d, 0x40000800, 0x210f3e, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(161);
    switch (_front_symbol) {
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case closebrksym_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_137(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcefff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcefbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcefbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcefbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcefbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x403c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x403c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x403c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        static Int my_followers[] = { 0x403c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_182(_followers);
        break;
      }
    case hole_AltSymbol_value: HOLE_ACTION (0, "AltSymbol");
    case AltSymbol_value:
      {
        static Int my_followers[] = { 0x403c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_192();
        break;
      }
    case hole_Symbol1_value: HOLE_ACTION (0, "Symbol1");
    case Symbol1_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_193(_followers);
        break;
      }
    case ALT_Symbol1_SEP_Or_SP_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_200();
        break;
      }
    case Alternatives_value:
      {
        n = Parse_state_204(followers);
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  openbrksym . Alternatives closebrksym OPT_exclaimsym  followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x825f140 */
      PUSH_PARSEVALUE(Pointer,0,List_front_Symbol);
      PUSH_PARSEVALUE(Pointer,0,List_front_Or);
      _front_symbol = Alternatives_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 162
   hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym 
 */
static int Parse_state_162 (SymbolSet followers)	/* state 162 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xdafbc004, 0x601d, 0x40000800, 0x210f3e, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(162);
    switch (_front_symbol) {
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case closechainsym_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_137(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xdafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xdafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xdafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xdafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xdafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x1003c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x1003c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x1003c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        static Int my_followers[] = { 0x1003c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_182(_followers);
        break;
      }
    case hole_AltSymbol_value: HOLE_ACTION (0, "AltSymbol");
    case AltSymbol_value:
      {
        static Int my_followers[] = { 0x1003c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_192();
        break;
      }
    case hole_Symbol1_value: HOLE_ACTION (0, "Symbol1");
    case Symbol1_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_193(_followers);
        break;
      }
    case ALT_Symbol1_SEP_Or_SP_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_200();
        break;
      }
    case Alternatives_value:
      {
        n = Parse_state_201(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:SimpleSymbol  ->  openchainsym . Alternatives closechainsym     followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x825f140 */
      PUSH_PARSEVALUE(Pointer,0,List_front_Symbol);
      PUSH_PARSEVALUE(Pointer,0,List_front_Or);
      _front_symbol = Alternatives_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 164
   hole_StringOrKeyword Charsym Keywordsym Stringsym 
 */
static int Parse_state_164 (SymbolSet followers)	/* state 164 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x700000, 0x0, 0x0, 0x4000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(164);
    switch (_front_symbol) {
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_104();
        break;
      }
    case Keywordsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_105();
        break;
      }
    case Charsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_106();
        break;
      }
    case hole_StringOrKeyword_value: HOLE_ACTION (0, "String");
    case StringOrKeyword_value:
      {
        n = Parse_state_165();
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  backslashbackslashsym . StringOrKeyword       followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x826a678 */
      n = 0; _front_symbol = StringOrKeyword_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 166
   hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_166 (SymbolSet followers)	/* state 166 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(166);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_112(followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_167();
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  LAYOUTsym . Expr      followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8266530 */
      n = 0; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 168
   COMPAREsym 
 */
static int Parse_state_168 (SymbolSet followers)	/* state 168 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(168);
    switch (_front_symbol) {
    case COMPAREsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_169(followers);
        break;
      }
    default:
    /* default item:Symbol2  ->  SimpleSymbol .     followers: hole_MORE_Symbol lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
      n = 1; _front_symbol = Symbol2_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 169
   Identsym 
 */
static int Parse_state_169 (SymbolSet followers)	/* state 169 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_170();
      }
  return n-1;
}

/* directors of state 174
   hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
static int Parse_state_174 (SymbolSet followers)	/* state 174 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf83804, 0x1d, 0x800, 0x210e86, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(174);
    switch (_front_symbol) {
    case hole_Field_value:
    case Identsym_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = And_value;
      PUSH_PARSEVALUE(Int,front_AndCenter,front_And);
      break;
    case Newlinesym_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x210e06, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_175();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case LeftAndsym_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x210e06, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_176();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case RightAndsym_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x210e06, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_177();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_And_value: HOLE_ACTION (0, "And");
    case And_value:
      {
        n = Parse_state_178(followers);
        break;
      }
    default:
    /* default item:ALT_ONCE_SymbolORField_SEP_And  ->  ONCE_SymbolORField .        followers: closechainsym closebrksym closeparsym hole_Alternator alternate_rightsym alternate_leftsym lessthansym CHECKSsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
      n = 1; _front_symbol = ALT_ONCE_SymbolORField_SEP_And_value;
      { /* alt action */
        front_Field  my_fields = POP_PARSEVALUE (Pointer, front_Field);
        front_Symbol  symbols = POP_PARSEVALUE (Pointer, front_Symbol);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Symbol(symbols,NULL),List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Field(my_fields,NULL),List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 178
   hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
static int Parse_state_178 (SymbolSet followers)	/* state 178 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x1d, 0x800, 0x210e06, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(178);
    switch (_front_symbol) {
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_137(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        n = Parse_state_174(followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        n = Parse_state_179();
        break;
      }
    default:
    /* default item:ALT_ONCE_SymbolORField_SEP_And  ->  ONCE_SymbolORField And . ALT_ONCE_SymbolORField_SEP_And     followers: closechainsym closebrksym closeparsym hole_Alternator alternate_rightsym alternate_leftsym lessthansym CHECKSsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_ONCE_SymbolORField_SEP_And expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_Symbol);
      PUSH_PARSEVALUE(Pointer,0,List_front_Field);
      PUSH_PARSEVALUE(Pointer,0,List_front_And);
      _front_symbol = ALT_ONCE_SymbolORField_SEP_And_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 182
   hole_Alternator alternate_rightsym alternate_leftsym 
 */
static int Parse_state_182 (SymbolSet followers)	/* state 182 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(182);
    switch (_front_symbol) {
    case alternate_leftsym_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_183();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case alternate_rightsym_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_184();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Alternator_value: HOLE_ACTION (0, "Alternator");
    case Alternator_value:
      {
        n = Parse_state_185(followers);
        break;
      }
    default:
    /* default item:Symbol1  ->  SymbolSeq .        followers: closechainsym closebrksym closeparsym lessthansym CHECKSsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
      n = 1; _front_symbol = Symbol1_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 185
   hole_MORE_Symbol hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym Identsym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
static int Parse_state_185 (SymbolSet followers)	/* state 185 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(185);
    switch (_front_symbol) {
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_186(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        n = Parse_state_189(followers);
        break;
      }
    case hole_MORE_Symbol_value: HOLE_ACTION (0, "List_Symbol");
    case MORE_Symbol_value:
      {
        n = Parse_state_191();
        break;
      }
    default:
    /* default item:AltSymbol  ->  SymbolSeq Alternator . MORE_Symbol       followers: closechainsym closebrksym closeparsym lessthansym CHECKSsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "MORE_Symbol expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_Symbol);
      _front_symbol = MORE_Symbol_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 186
   colonsym hole_OptType TYPEsym 
 */
static int Parse_state_186 (SymbolSet followers)	/* state 186 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x8, 0x0, 0x400, 0x2000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(186);
    switch (_front_symbol) {
    case COMPAREsym_value:
    case hole_MORE_Symbol_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case Identsym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
    case closechainsym_value:
    case closebrksym_value:
    case closeparsym_value:
    case lessthansym_value:
    case CHECKSsym_value:
    case semicolonsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case greaterthansym_value:
    case front_EOF_value:
      n = 0; _front_symbol = OPT_TYPEsym_Type_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,front_Type);
      }
      break;
    case TYPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    case OPT_TYPEsym_Type_value:
      {
        n = Parse_state_46();
        break;
      }
    case hole_OptType_value: HOLE_ACTION (0, "Type");
    case OptType_value:
      {
        n = Parse_state_81();
        break;
      }
    case colonsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_187(followers);
        break;
      }
    default:
    /* default item:IdSym  ->  Identsym . OptType   followers: COMPAREsym hole_MORE_Symbol hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym Identsym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym closechainsym closebrksym closeparsym lessthansym CHECKSsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = 0x825f888 */
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = OptType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 187
   hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym Identsym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
static int Parse_state_187 (SymbolSet followers)	/* state 187 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x1d, 0x800, 0x10e02, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(187);
    switch (_front_symbol) {
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x1c, 0x0, 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_80(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        n = Parse_state_168(followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        n = Parse_state_188();
        break;
      }
    default:
    /* default item:Symbol  ->  Identsym colonsym . Symbol2 followers: hole_MORE_Symbol hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym Identsym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym closechainsym closebrksym closeparsym lessthansym CHECKSsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = 0x82583d8 */
      n = 0; _front_symbol = Symbol2_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 189
   hole_MORE_Symbol hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym Identsym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
static int Parse_state_189 (SymbolSet followers)	/* state 189 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(189);
    switch (_front_symbol) {
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_186(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        n = Parse_state_189(followers);
        break;
      }
    case hole_MORE_Symbol_value: HOLE_ACTION (0, "List_Symbol");
    case MORE_Symbol_value:
      {
        n = Parse_state_190();
        break;
      }
    default:
    /* default item:MORE_Symbol  ->  Symbol .       followers: closechainsym closebrksym closeparsym lessthansym CHECKSsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
      n = 1; _front_symbol = MORE_Symbol_value;
      { /* more action */
        front_Symbol  syms = POP_PARSEVALUE (Pointer, front_Symbol);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Symbol(syms,NULL),List_front_Symbol);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 193
   hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym 
 */
static int Parse_state_193 (SymbolSet followers)	/* state 193 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x3c000, 0x0, 0x0, 0x100, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(193);
    switch (_front_symbol) {
    case verticalbarsym_value:
      {
        static Int my_followers[] = { 0xcafbc004, 0x601d, 0x40000800, 0x210f3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_194();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case LeftOrsym_value:
      {
        static Int my_followers[] = { 0xcafbc004, 0x601d, 0x40000800, 0x210f3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_195();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case RightOrsym_value:
      {
        static Int my_followers[] = { 0xcafbc004, 0x601d, 0x40000800, 0x210f3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_196();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Xorsym_value:
      {
        static Int my_followers[] = { 0xcafbc004, 0x601d, 0x40000800, 0x210f3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_197();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Or_value: HOLE_ACTION (0, "Or");
    case Or_value:
      {
        n = Parse_state_198(followers);
        break;
      }
    default:
    /* default item:ALT_Symbol1_SEP_Or_SP  ->  Symbol1 .    followers: closechainsym closebrksym closeparsym  */
      n = 1; _front_symbol = ALT_Symbol1_SEP_Or_SP_value;
      { /* alt action */
        front_Symbol  sym = POP_PARSEVALUE (Pointer, front_Symbol);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Symbol(sym,NULL),List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Or);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 198
   hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym 
 */
static int Parse_state_198 (SymbolSet followers)	/* state 198 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcafbc004, 0x601d, 0x40000800, 0x210f3e, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(198);
    switch (_front_symbol) {
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case closechainsym_value:
    case closebrksym_value:
    case closeparsym_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_137(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x3c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x3c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x3c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        static Int my_followers[] = { 0x3c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_182(_followers);
        break;
      }
    case hole_AltSymbol_value: HOLE_ACTION (0, "AltSymbol");
    case AltSymbol_value:
      {
        static Int my_followers[] = { 0x3c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_192();
        break;
      }
    case hole_Symbol1_value: HOLE_ACTION (0, "Symbol1");
    case Symbol1_value:
      {
        n = Parse_state_193(followers);
        break;
      }
    case ALT_Symbol1_SEP_Or_SP_value:
      {
        n = Parse_state_199();
        break;
      }
    default:
    /* default item:ALT_Symbol1_SEP_Or_SP  ->  Symbol1 Or . ALT_Symbol1_SEP_Or_SP   followers: closechainsym closebrksym closeparsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Symbol);
      PUSH_PARSEVALUE(Pointer,0,List_front_Or);
      _front_symbol = ALT_Symbol1_SEP_Or_SP_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 201
   closechainsym 
 */
static int Parse_state_201 (SymbolSet followers)	/* state 201 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_202(followers);
      }
  return n-1;
}

/* directors of state 202
   plussym 
 */
static int Parse_state_202 (SymbolSet followers)	/* state 202 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20000000, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(202);
    switch (_front_symbol) {
    case plussym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_203();
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  openchainsym Alternatives closechainsym .     followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
      n = 3; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        List_front_Or  ops = POP_PARSEVALUE (Pointer, List_front_Or);
        List_front_Symbol  sym = POP_PARSEVALUE (Pointer, List_front_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_OptMoreSymbol(src_info, sym, ops);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 204
   closebrksym 
 */
static int Parse_state_204 (SymbolSet followers)	/* state 204 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(followers);
      }
  return n-1;
}

/* directors of state 205
   exclaimsym 
 */
static int Parse_state_205 (SymbolSet followers)	/* state 205 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x20000, 0x0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(205);
    switch (_front_symbol) {
    case exclaimsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_206();
        break;
      }
    case OPT_exclaimsym_value:
      {
        n = Parse_state_207();
        break;
      }
    default:
    /* default item:SimpleSymbol  ->  openbrksym Alternatives closebrksym . OPT_exclaimsym  followers: hole_MORE_Symbol COMPAREsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_exclaimsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_208 (void)	/* state 208 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_209();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

static int Parse_state_209 (void)	/* state 209 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_210();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 211
   equalssym 
 */
static int Parse_state_211 (SymbolSet followers)	/* state 211 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_212(followers);
      }
  return n-1;
}

/* directors of state 212
   hole_FieldInits hole_ALT_FieldInit_SEP_commasym hole_FieldInit CHECKSsym APPLIEDsym DEFININGsym SCOPEsym CREATEsym hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_212 (SymbolSet followers)	/* state 212 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20780044, 0xffff0744, 0x8000, 0x7d0c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(212);
    switch (_front_symbol) {
    case hole_Expr_value:
    case hole_MonExpr1_value:
    case hole_OPTMORE_Oper_value:
    case hole_Oper_value:
    case greaterthangreaterthansym_value:
    case lessthanlessthansym_value:
    case percentsym_value:
    case slashsym_value:
    case starsym_value:
    case minussym_value:
    case plussym_value:
    case hatsym_value:
    case verticalbarverticalbarsym_value:
    case ampersandampersandsym_value:
    case ampersandsym_value:
    case greaterthanequalssym_value:
    case lessthanequalssym_value:
    case exclaimequalssym_value:
    case equalsequalssym_value:
    case exclaimsym_value:
    case tildasym_value:
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPT_CREATEsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case CREATEsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x7010, 0x700c000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_213();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_CREATEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x7010, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_214(_followers);
        break;
      }
    case SCOPEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x7010, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_216(_followers);
        break;
      }
    case DEFININGsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x7010, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_218(_followers);
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x7010, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_220(_followers);
        break;
      }
    case CHECKSsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x7010, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_222(_followers);
        break;
      }
    case hole_FieldInit_value: HOLE_ACTION (0, "FieldInit");
    case FieldInit_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x7000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_224(_followers);
        break;
      }
    case hole_ALT_FieldInit_SEP_commasym_value: HOLE_ACTION (0, "List_FieldInit");
    case ALT_FieldInit_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x7000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_227();
        break;
      }
    case hole_FieldInits_value: HOLE_ACTION (0, "List_FieldInit");
    case FieldInits_value:
      {
        n = Parse_state_228(followers);
        break;
      }
    default:
    /* default item:Field  ->  Identsym colonsym Type equalssym . FieldInits OPT_TRAVERSEsym OPT_CLEARsym OPT_DONT_CLEARsym followers: lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8263ee0 */
      InputError (SCAN_POSITION, TRUE, "FieldInits expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_FieldInit);
      _front_symbol = FieldInits_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 214
   hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_214 (SymbolSet followers)	/* state 214 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(214);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_112(followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_215();
        break;
      }
    default:
    /* default item:FieldInit  ->  OPT_CREATEsym . Expr     followers: commasym TRAVERSEsym CLEARsym DONT_CLEARsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8266530 */
      n = 0; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 216
   hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_216 (SymbolSet followers)	/* state 216 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(216);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_112(followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_217();
        break;
      }
    default:
    /* default item:FieldInit  ->  SCOPEsym . Expr  followers: commasym TRAVERSEsym CLEARsym DONT_CLEARsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8266530 */
      n = 0; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 218
   hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_218 (SymbolSet followers)	/* state 218 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(218);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_112(followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_219();
        break;
      }
    default:
    /* default item:FieldInit  ->  DEFININGsym . Expr       followers: commasym TRAVERSEsym CLEARsym DONT_CLEARsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8266530 */
      n = 0; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 220
   hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_220 (SymbolSet followers)	/* state 220 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(220);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_112(followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_221();
        break;
      }
    default:
    /* default item:FieldInit  ->  APPLIEDsym . Expr        followers: commasym TRAVERSEsym CLEARsym DONT_CLEARsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8266530 */
      n = 0; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 222
   hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_222 (SymbolSet followers)	/* state 222 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(222);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_112(followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_223();
        break;
      }
    default:
    /* default item:FieldInit  ->  CHECKSsym . Expr followers: commasym TRAVERSEsym CLEARsym DONT_CLEARsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = 0x8266530 */
      n = 0; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 224
   commasym 
 */
static int Parse_state_224 (SymbolSet followers)	/* state 224 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(224);
    switch (_front_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_225(followers);
        break;
      }
    default:
    /* default item:ALT_FieldInit_SEP_commasym  ->  FieldInit .     followers: TRAVERSEsym CLEARsym DONT_CLEARsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
      n = 1; _front_symbol = ALT_FieldInit_SEP_commasym_value;
      { /* alt action */
        front_FieldInit  _id_0 = POP_PARSEVALUE (Pointer, front_FieldInit);
        PUSH_PARSEVALUE(Pointer,Create_List_front_FieldInit(_id_0,NULL),List_front_FieldInit);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 225
   hole_ALT_FieldInit_SEP_commasym hole_FieldInit CHECKSsym APPLIEDsym DEFININGsym SCOPEsym CREATEsym hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_225 (SymbolSet followers)	/* state 225 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20780044, 0xffff0744, 0x8000, 0x7c0c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(225);
    switch (_front_symbol) {
    case hole_Expr_value:
    case hole_MonExpr1_value:
    case hole_OPTMORE_Oper_value:
    case hole_Oper_value:
    case greaterthangreaterthansym_value:
    case lessthanlessthansym_value:
    case percentsym_value:
    case slashsym_value:
    case starsym_value:
    case minussym_value:
    case plussym_value:
    case hatsym_value:
    case verticalbarverticalbarsym_value:
    case ampersandampersandsym_value:
    case ampersandsym_value:
    case greaterthanequalssym_value:
    case lessthanequalssym_value:
    case exclaimequalssym_value:
    case equalsequalssym_value:
    case exclaimsym_value:
    case tildasym_value:
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPT_CREATEsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case CREATEsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x700c000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_213();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_CREATEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_214(_followers);
        break;
      }
    case SCOPEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_216(_followers);
        break;
      }
    case DEFININGsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_218(_followers);
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_220(_followers);
        break;
      }
    case CHECKSsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_222(_followers);
        break;
      }
    case hole_FieldInit_value: HOLE_ACTION (0, "FieldInit");
    case FieldInit_value:
      {
        n = Parse_state_224(followers);
        break;
      }
    case hole_ALT_FieldInit_SEP_commasym_value: HOLE_ACTION (0, "List_FieldInit");
    case ALT_FieldInit_SEP_commasym_value:
      {
        n = Parse_state_226();
        break;
      }
    default:
    /* default item:ALT_FieldInit_SEP_commasym  ->  FieldInit commasym . ALT_FieldInit_SEP_commasym followers: TRAVERSEsym CLEARsym DONT_CLEARsym lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_FieldInit_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_FieldInit);
      _front_symbol = ALT_FieldInit_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 228
   TRAVERSEsym CLEARsym DONT_CLEARsym 
 */
static int Parse_state_228 (SymbolSet followers)	/* state 228 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x7000, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(228);
    switch (_front_symbol) {
    case TRAVERSEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x6000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_229();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_TRAVERSEsym_value:
      {
        n = Parse_state_230(followers);
        break;
      }
    default:
    /* default item:Field  ->  Identsym colonsym Type equalssym FieldInits . OPT_TRAVERSEsym OPT_CLEARsym OPT_DONT_CLEARsym followers: lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_TRAVERSEsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 230
   CLEARsym DONT_CLEARsym 
 */
static int Parse_state_230 (SymbolSet followers)	/* state 230 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x6000, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(230);
    switch (_front_symbol) {
    case CLEARsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x4000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_231();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_CLEARsym_value:
      {
        n = Parse_state_232(followers);
        break;
      }
    default:
    /* default item:Field  ->  Identsym colonsym Type equalssym FieldInits OPT_TRAVERSEsym . OPT_CLEARsym OPT_DONT_CLEARsym followers: lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_CLEARsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 232
   DONT_CLEARsym 
 */
static int Parse_state_232 (SymbolSet followers)	/* state 232 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x4000, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(232);
    switch (_front_symbol) {
    case DONT_CLEARsym_value:
      {
        n = Parse_state_233();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_DONT_CLEARsym_value:
      {
        n = Parse_state_234();
        break;
      }
    default:
    /* default item:Field  ->  Identsym colonsym Type equalssym FieldInits OPT_TRAVERSEsym OPT_CLEARsym . OPT_DONT_CLEARsym followers: lessthansym CHECKSsym semicolonsym greaterthansym front_EOF closeparsym closebrksym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_DONT_CLEARsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 235
   lessthansym CHECKSsym 
 */
static int Parse_state_235 (SymbolSet followers)	/* state 235 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20, 0x40, 0x0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(235);
    switch (_front_symbol) {
    case lessthansym_value:
      {
        static Int my_followers[] = { 0x0, 0x40, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_236(_followers);
        break;
      }
    case Choices_value:
      {
        static Int my_followers[] = { 0x0, 0x40, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_250();
        break;
      }
    case OPT_Choices_value:
      {
        n = Parse_state_251(followers);
        break;
      }
    default:
    /* default item:Rhs  ->  OPTMORE_Scoping Symbol1 . OPT_Choices OPT_CHECKSsym_OPTMORE_Check      followers: semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      PUSH_PARSEVALUE(Pointer,0,List_front_Alternative);
      PUSH_PARSEVALUE(Pointer,0,List_front_Or);
      PUSH_PARSEVALUE(Ident,0,Ident);
      PUSH_PARSEVALUE(Pointer,0,front_Symbol);
      _front_symbol = OPT_Choices_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 236
   hole_Alternative hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym 
 */
static int Parse_state_236 (SymbolSet followers)	/* state 236 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcafbc204, 0x601d, 0x40000800, 0x210f3f, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(236);
    switch (_front_symbol) {
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case greaterthansym_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_237(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafffa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcafbfa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcafbfa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcafbfa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcafbfa04, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x3c200, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x3c200, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x3c200, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        static Int my_followers[] = { 0x3c200, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_182(_followers);
        break;
      }
    case hole_AltSymbol_value: HOLE_ACTION (0, "AltSymbol");
    case AltSymbol_value:
      {
        static Int my_followers[] = { 0x3c200, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_192();
        break;
      }
    case hole_Symbol1_value: HOLE_ACTION (0, "Symbol1");
    case Symbol1_value:
      {
        static Int my_followers[] = { 0x3c200, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_242();
        break;
      }
    case hole_Alternative_value: HOLE_ACTION (0, "Alternative");
    case Alternative_value:
      {
        static Int my_followers[] = { 0x200, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_243(_followers);
        break;
      }
    case ALT_Alternative_SEP_Or_value:
      {
        static Int my_followers[] = { 0x200, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_246();
        break;
      }
    case ChoiceList_value:
      {
        n = Parse_state_247(followers);
        break;
      }
    default:
    /* default item:Choices  ->  lessthansym . ChoiceList greaterthansym Symbol1    followers: CHECKSsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = 0x8251438 */
      PUSH_PARSEVALUE(Pointer,0,List_front_Alternative);
      PUSH_PARSEVALUE(Pointer,0,List_front_Or);
      _front_symbol = ChoiceList_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 237
   MEMOsym SKIPsym definessym colonsym hole_OptType TYPEsym 
 */
static int Parse_state_237 (SymbolSet followers)	/* state 237 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x408, 0x0, 0x540, 0x2000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(237);
    switch (_front_symbol) {
    case SKIPsym_value:
    case definessym_value:
      n = 0; _front_symbol = OPT_MEMOsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case greaterthansym_value:
    case COMPAREsym_value:
    case hole_And_value:
    case RightAndsym_value:
    case LeftAndsym_value:
    case Newlinesym_value:
    case hole_Field_value:
    case Identsym_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
    case front_EOF_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
      n = 0; _front_symbol = OPT_TYPEsym_Type_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,front_Type);
      }
      break;
    case TYPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    case OPT_TYPEsym_Type_value:
      {
        n = Parse_state_46();
        break;
      }
    case MEMOsym_value:
      {
        static Int my_followers[] = { 0x400, 0x0, 0x100, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_59();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_OptType_value: HOLE_ACTION (0, "Type");
    case OptType_value:
      {
        n = Parse_state_81();
        break;
      }
    case colonsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_138(followers);
        break;
      }
    case OPT_MEMOsym_value:
      {
        n = Parse_state_238(followers);
        break;
      }
    default:
    /* default item:IdSym  ->  Identsym . OptType   followers: hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym COMPAREsym hole_And RightAndsym LeftAndsym Newlinesym hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym front_EOF hole_Alternator alternate_rightsym alternate_leftsym  */
/* nt = 0x825f888 */
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = OptType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 238
   SKIPsym definessym 
 */
static int Parse_state_238 (SymbolSet followers)	/* state 238 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x400, 0x0, 0x100, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(238);
    switch (_front_symbol) {
    case SKIPsym_value:
      {
        static Int my_followers[] = { 0x400, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_63();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_SKIPsym_value:
      {
        n = Parse_state_239(followers);
        break;
      }
    default:
    /* default item:Alternative  ->  Identsym OPT_MEMOsym . OPT_SKIPsym definessym Rhs      followers: hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_SKIPsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 239
   definessym 
 */
static int Parse_state_239 (SymbolSet followers)	/* state 239 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.definessym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_240(followers);
      }
  return n-1;
}

/* directors of state 240
   hole_Rhs hole_OPTMORE_Scoping hole_Scoping CLOSESCOPEsym OPENSCOPEsym SCOPEsym hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym lessthansym CHECKSsym 
 */
static int Parse_state_240 (SymbolSet followers)	/* state 240 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf801e4, 0x605d, 0xe4000800, 0x210e3e, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(240);
    switch (_front_symbol) {
    case hole_Symbol1_value:
    case hole_SymbolSeq_value:
    case hole_Field_value:
    case Identsym_value:
    case hole_Symbol_value:
    case hole_Symbol2_value:
    case hole_SimpleSymbol_value:
    case LAYOUTsym_value:
    case backslashbackslashsym_value:
    case EMPTYsym_value:
    case openchainsym_value:
    case openbrksym_value:
    case open2symsym_value:
    case Keywordsym_value:
    case Charsym_value:
    case Stringsym_value:
    case APPLIEDsym_value:
    case hole_IdSym_value:
    case hole_DefiningSym_value:
    case FORWARDsym_value:
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
    case hole_AltSymbol_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case lessthansym_value:
    case CHECKSsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case greaterthansym_value:
    case front_EOF_value:
      n = 0; _front_symbol = OPTMORE_Scoping_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Scoping);
      }
      break;
    case SCOPEsym_value:
      {
        static Int my_followers[] = { 0xcaf801e4, 0x605d, 0xe0000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_68();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPENSCOPEsym_value:
      {
        static Int my_followers[] = { 0xcaf801e4, 0x605d, 0xe0000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_69();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case CLOSESCOPEsym_value:
      {
        static Int my_followers[] = { 0xcaf801e4, 0x605d, 0xe0000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_70();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Scoping_value: HOLE_ACTION (0, "Scoping");
    case Scoping_value:
      {
        static Int my_followers[] = { 0xcaf80024, 0x605d, 0x40000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_71(_followers);
        break;
      }
    case hole_OPTMORE_Scoping_value: HOLE_ACTION (0, "List_Scoping");
    case OPTMORE_Scoping_value:
      {
        n = Parse_state_73(followers);
        break;
      }
    case hole_Rhs_value: HOLE_ACTION (0, "Rhs");
    case Rhs_value:
      {
        n = Parse_state_241();
        break;
      }
    default:
    /* default item:Alternative  ->  Identsym OPT_MEMOsym OPT_SKIPsym definessym . Rhs      followers: hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = 0x824fca0 */
      PUSH_PARSEVALUE(Pointer,0,front_Rhs);
      _front_symbol = Rhs_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 243
   hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym 
 */
static int Parse_state_243 (SymbolSet followers)	/* state 243 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x3c000, 0x0, 0x0, 0x100, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(243);
    switch (_front_symbol) {
    case verticalbarsym_value:
      {
        static Int my_followers[] = { 0xcafbc004, 0x601d, 0x40000800, 0x210f3f, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_194();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case LeftOrsym_value:
      {
        static Int my_followers[] = { 0xcafbc004, 0x601d, 0x40000800, 0x210f3f, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_195();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case RightOrsym_value:
      {
        static Int my_followers[] = { 0xcafbc004, 0x601d, 0x40000800, 0x210f3f, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_196();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Xorsym_value:
      {
        static Int my_followers[] = { 0xcafbc004, 0x601d, 0x40000800, 0x210f3f, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_197();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Or_value: HOLE_ACTION (0, "Or");
    case Or_value:
      {
        n = Parse_state_244(followers);
        break;
      }
    default:
    /* default item:ALT_Alternative_SEP_Or  ->  Alternative .       followers: greaterthansym  */
      n = 1; _front_symbol = ALT_Alternative_SEP_Or_value;
      { /* alt action */
        front_Alternative  alts = POP_PARSEVALUE (Pointer, front_Alternative);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Alternative(alts,NULL),List_front_Alternative);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Or);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 244
   hole_Alternative hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym 
 */
static int Parse_state_244 (SymbolSet followers)	/* state 244 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcafbc004, 0x601d, 0x40000800, 0x210f3f, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(244);
    switch (_front_symbol) {
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case greaterthansym_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_237(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafff804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcafbf804, 0x601d, 0x800, 0x210fa6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x3c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x3c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x3c000, 0x6000, 0x0, 0x120, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        static Int my_followers[] = { 0x3c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_182(_followers);
        break;
      }
    case hole_AltSymbol_value: HOLE_ACTION (0, "AltSymbol");
    case AltSymbol_value:
      {
        static Int my_followers[] = { 0x3c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_192();
        break;
      }
    case hole_Symbol1_value: HOLE_ACTION (0, "Symbol1");
    case Symbol1_value:
      {
        static Int my_followers[] = { 0x3c000, 0x0, 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_242();
        break;
      }
    case hole_Alternative_value: HOLE_ACTION (0, "Alternative");
    case Alternative_value:
      {
        n = Parse_state_243(followers);
        break;
      }
    case ALT_Alternative_SEP_Or_value:
      {
        n = Parse_state_245();
        break;
      }
    default:
    /* default item:ALT_Alternative_SEP_Or  ->  Alternative Or . ALT_Alternative_SEP_Or     followers: greaterthansym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Alternative);
      PUSH_PARSEVALUE(Pointer,0,List_front_Or);
      _front_symbol = ALT_Alternative_SEP_Or_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 247
   greaterthansym 
 */
static int Parse_state_247 (SymbolSet followers)	/* state 247 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_248(followers);
      }
  return n-1;
}

/* directors of state 248
   hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym 
 */
static int Parse_state_248 (SymbolSet followers)	/* state 248 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x601d, 0x40000800, 0x210e3e, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(248);
    switch (_front_symbol) {
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
    case CHECKSsym_value:
    case semicolonsym_value:
    case hole_Or_value:
    case Xorsym_value:
    case RightOrsym_value:
    case LeftOrsym_value:
    case verticalbarsym_value:
    case greaterthansym_value:
    case front_EOF_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_137(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        n = Parse_state_182(followers);
        break;
      }
    case hole_AltSymbol_value: HOLE_ACTION (0, "AltSymbol");
    case AltSymbol_value:
      {
        n = Parse_state_192();
        break;
      }
    case hole_Symbol1_value: HOLE_ACTION (0, "Symbol1");
    case Symbol1_value:
      {
        n = Parse_state_249();
        break;
      }
    default:
    /* default item:Choices  ->  lessthansym ChoiceList greaterthansym . Symbol1    followers: CHECKSsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = 0x8254c48 */
      n = 0; _front_symbol = Symbol1_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 251
   CHECKSsym 
 */
static int Parse_state_251 (SymbolSet followers)	/* state 251 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x40, 0x0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(251);
    switch (_front_symbol) {
    case CHECKSsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_252(followers);
        break;
      }
    case OPT_CHECKSsym_OPTMORE_Check_value:
      {
        n = Parse_state_263();
        break;
      }
    default:
    /* default item:Rhs  ->  OPTMORE_Scoping Symbol1 OPT_Choices . OPT_CHECKSsym_OPTMORE_Check      followers: semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Check);
      _front_symbol = OPT_CHECKSsym_OPTMORE_Check_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 252
   hole_OPTMORE_Check hole_Check IFsym 
 */
static int Parse_state_252 (SymbolSet followers)	/* state 252 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x800, 0x0, 0x10000000, 0x100 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(252);
    switch (_front_symbol) {
    case IFsym_value:
      {
        static Int my_followers[] = { 0x0, 0x800, 0x0, 0x10000000, 0x100 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_253(_followers);
        break;
      }
    case hole_Check_value: HOLE_ACTION (0, "Check");
    case Check_value:
      {
        n = Parse_state_260(followers);
        break;
      }
    case hole_OPTMORE_Check_value: HOLE_ACTION (0, "List_Check");
    case OPTMORE_Check_value:
      {
        n = Parse_state_262();
        break;
      }
    default:
    /* default item:OPT_CHECKSsym_OPTMORE_Check  ->  CHECKSsym . OPTMORE_Check      followers: semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Check);
      _front_symbol = OPTMORE_Check_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 253
   hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_253 (SymbolSet followers)	/* state 253 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(253);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff1700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff1000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        static Int my_followers[] = { 0x0, 0x1000, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_112(_followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        static Int my_followers[] = { 0x0, 0x1000, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_254(followers);
        break;
      }
    default:
    /* default item:Check  ->  IFsym . Expr THENsym OPT_WARNINGsym MORE_MonExpr1    followers: hole_OPTMORE_Check hole_Check IFsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = 0x8266530 */
      n = 0; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 254
   THENsym 
 */
static int Parse_state_254 (SymbolSet followers)	/* state 254 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_255(followers);
      }
  return n-1;
}

/* directors of state 255
   WARNINGsym hole_MORE_MonExpr1 hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_255 (SymbolSet followers)	/* state 255 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x200, 0xf004000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(255);
    switch (_front_symbol) {
    case WARNINGsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_149();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_WARNINGsym_value:
      {
        n = Parse_state_256(followers);
        break;
      }
    default:
    /* default item:Check  ->  IFsym Expr THENsym . OPT_WARNINGsym MORE_MonExpr1    followers: hole_OPTMORE_Check hole_Check IFsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_WARNINGsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 256
   hole_MORE_MonExpr1 hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_256 (SymbolSet followers)	/* state 256 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(256);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_257(followers);
        break;
      }
    case hole_MORE_MonExpr1_value: HOLE_ACTION (0, "List_Expr");
    case MORE_MonExpr1_value:
      {
        n = Parse_state_259();
        break;
      }
    default:
    /* default item:Check  ->  IFsym Expr THENsym OPT_WARNINGsym . MORE_MonExpr1    followers: hole_OPTMORE_Check hole_Check IFsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "MORE_MonExpr1 expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_Expr);
      _front_symbol = MORE_MonExpr1_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 257
   hole_MORE_MonExpr1 hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
static int Parse_state_257 (SymbolSet followers)	/* state 257 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(257);
    switch (_front_symbol) {
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_257(followers);
        break;
      }
    case hole_MORE_MonExpr1_value: HOLE_ACTION (0, "List_Expr");
    case MORE_MonExpr1_value:
      {
        n = Parse_state_258();
        break;
      }
    default:
    /* default item:MORE_MonExpr1  ->  MonExpr1 .   followers: hole_OPTMORE_Check hole_Check IFsym semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
      n = 1; _front_symbol = MORE_MonExpr1_value;
      { /* more action */
        front_Expr  message = POP_PARSEVALUE (Pointer, front_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_front_Expr(message,NULL),List_front_Expr);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 260
   hole_OPTMORE_Check hole_Check IFsym 
 */
static int Parse_state_260 (SymbolSet followers)	/* state 260 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x800, 0x0, 0x10000000, 0x100 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(260);
    switch (_front_symbol) {
    case IFsym_value:
      {
        static Int my_followers[] = { 0x0, 0x800, 0x0, 0x10000000, 0x100 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_253(_followers);
        break;
      }
    case hole_Check_value: HOLE_ACTION (0, "Check");
    case Check_value:
      {
        n = Parse_state_260(followers);
        break;
      }
    case hole_OPTMORE_Check_value: HOLE_ACTION (0, "List_Check");
    case OPTMORE_Check_value:
      {
        n = Parse_state_261();
        break;
      }
    default:
    /* default item:OPTMORE_Check  ->  Check . OPTMORE_Check        followers: semicolonsym hole_Or Xorsym RightOrsym LeftOrsym verticalbarsym greaterthansym front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Check);
      _front_symbol = OPTMORE_Check_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_264 (void)	/* state 264 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_265();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 266
   hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym 
 */
static int Parse_state_266 (SymbolSet followers)	/* state 266 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x8000, 0x8800020, 0x0, 0x20 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(266);
    switch (_front_symbol) {
    case hole_ScanInfo_value:
    case SCANsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPT_ROOTsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case ROOTsym_value:
      {
        static Int my_followers[] = { 0x4, 0x8000, 0x8800020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_32();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_ROOTsym_value:
      {
        static Int my_followers[] = { 0x4, 0x8000, 0x8800020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_33(_followers);
        break;
      }
    case hole_NonTerminal_value: HOLE_ACTION (0, "NonTerminal");
    case NonTerminal_value:
      {
        n = Parse_state_266(followers);
        break;
      }
    case hole_MORE_NonTerminal_value: HOLE_ACTION (0, "List_NonTerminal");
    case MORE_NonTerminal_value:
      {
        n = Parse_state_267();
        break;
      }
    default:
    /* default item:MORE_NonTerminal  ->  NonTerminal .     followers: front_EOF  */
      n = 1; _front_symbol = MORE_NonTerminal_value;
      { /* more action */
        front_NonTerminal  rules = POP_PARSEVALUE (Pointer, front_NonTerminal);
        PUSH_PARSEVALUE(Pointer,Create_List_front_NonTerminal(rules,NULL),List_front_NonTerminal);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 271
   hole_ALT_ImportedNonTerminal_SEP_commasym hole_ImportedNonTerminal Identsym 
 */
List_front_ImportedNonTerminal Parse_state_front_ImportedNonTerminals (void)	/* state 271 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x600000, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(271);
    switch (_front_symbol) {
    case ImportedNonTerminals_value:
      n = 1; break; /* accept ImportedNonTerminals  ->  . ALT_ImportedNonTerminal_SEP_commasym        followers: front_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case hole_ImportedNonTerminal_value: HOLE_ACTION (0, "ImportedNonTerminal");
    case ImportedNonTerminal_value:
      {
        n = Parse_state_8(followers);
        break;
      }
    case hole_ALT_ImportedNonTerminal_SEP_commasym_value: HOLE_ACTION (0, "List_ImportedNonTerminal");
    case ALT_ImportedNonTerminal_SEP_commasym_value:
      {
        n = Parse_state_11();
        break;
      }
    default:
    /* default item:ImportedNonTerminals  ->  . ALT_ImportedNonTerminal_SEP_commasym   followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_ImportedNonTerminal_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_ImportedNonTerminal);
      _front_symbol = ALT_ImportedNonTerminal_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_ImportedNonTerminal")->sub.PointerValue;
}

/* directors of state 272
   FROMsym 
 */
front_Import Parse_state_front_Import (void)	/* state 272 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x2, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(272);
    switch (_front_symbol) {
    case Import_value:
      n = 1; break; /* accept Import  ->  . FROMsym Identsym colonsym ImportedNonTerminals    followers: front_EOF  */
    case FROMsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(followers);
        break;
      }
    default:
    /* default item:Import  ->  . FROMsym Identsym colonsym ImportedNonTerminals       followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "FROMsym expected");
      dont_shift = TRUE; _front_symbol = FROMsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Import")->sub.PointerValue;
}

/* directors of state 273
   hole_ImportedNonTerminal Identsym 
 */
List_front_ImportedNonTerminal Parse_state_front_ALT_ImportedNonTerminal_SEP_commasym (void)	/* state 273 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x400000, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(273);
    switch (_front_symbol) {
    case ALT_ImportedNonTerminal_SEP_commasym_value:
      n = 1; break; /* accept ALT_ImportedNonTerminal_SEP_commasym  ->  . ImportedNonTerminal commasym ALT_ImportedNonTerminal_SEP_commasym   followers: front_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case hole_ImportedNonTerminal_value: HOLE_ACTION (0, "ImportedNonTerminal");
    case ImportedNonTerminal_value:
      {
        n = Parse_state_8(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_ImportedNonTerminal_SEP_commasym  ->  . ImportedNonTerminal    followers: front_EOF  */
/* nt = 0x8249fd8 */
      InputError (SCAN_POSITION, TRUE, "ImportedNonTerminal expected");
      PUSH_PARSEVALUE(Pointer,0,front_ImportedNonTerminal);
      _front_symbol = ImportedNonTerminal_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_ImportedNonTerminal")->sub.PointerValue;
}

/* directors of state 274
   Identsym 
 */
front_ImportedNonTerminal Parse_state_front_ImportedNonTerminal (void)	/* state 274 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(274);
    switch (_front_symbol) {
    case ImportedNonTerminal_value:
      n = 1; break; /* accept ImportedNonTerminal  ->  . Identsym OPT_colonsym_Identsym       followers: front_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(followers);
        break;
      }
    default:
    /* default item:ImportedNonTerminal  ->  . Identsym OPT_colonsym_Identsym  followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _front_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_ImportedNonTerminal")->sub.PointerValue;
}

/* directors of state 275
   hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym 
 */
List_front_NonTerminal Parse_state_front_MORE_NonTerminal (void)	/* state 275 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x8000, 0x8000020, 0x0, 0x20 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(275);
    switch (_front_symbol) {
    case MORE_NonTerminal_value:
      n = 1; break; /* accept MORE_NonTerminal  ->  . NonTerminal MORE_NonTerminal    followers: front_EOF  */
    case hole_ScanInfo_value:
    case SCANsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPT_ROOTsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case ROOTsym_value:
      {
        static Int my_followers[] = { 0x4, 0x8000, 0x8800020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_32();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_ROOTsym_value:
      {
        static Int my_followers[] = { 0x4, 0x8000, 0x8800020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_33(_followers);
        break;
      }
    case hole_NonTerminal_value: HOLE_ACTION (0, "NonTerminal");
    case NonTerminal_value:
      {
        n = Parse_state_266(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:MORE_NonTerminal  ->  . NonTerminal        followers: front_EOF  */
/* nt = 0x824d718 */
      InputError (SCAN_POSITION, TRUE, "NonTerminal expected");
      PUSH_PARSEVALUE(Pointer,0,front_NonTerminal);
      _front_symbol = NonTerminal_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_NonTerminal")->sub.PointerValue;
}

/* directors of state 276
   hole_MORE_NonTerminal hole_NonTerminal ROOTsym hole_ScanInfo SCANsym Identsym 
 */
List_front_NonTerminal Parse_state_front_NonTerminals (void)	/* state 276 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x8000, 0x8800020, 0x0, 0x20 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(276);
    switch (_front_symbol) {
    case NonTerminals_value:
      n = 1; break; /* accept NonTerminals  ->  . MORE_NonTerminal    followers: front_EOF  */
    case hole_ScanInfo_value:
    case SCANsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPT_ROOTsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case ROOTsym_value:
      {
        static Int my_followers[] = { 0x4, 0x8000, 0x8800020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_32();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_ROOTsym_value:
      {
        static Int my_followers[] = { 0x4, 0x8000, 0x8800020, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_33(_followers);
        break;
      }
    case hole_NonTerminal_value: HOLE_ACTION (0, "NonTerminal");
    case NonTerminal_value:
      {
        n = Parse_state_266(followers);
        break;
      }
    case hole_MORE_NonTerminal_value: HOLE_ACTION (0, "List_NonTerminal");
    case MORE_NonTerminal_value:
      {
        n = Parse_state_268();
        break;
      }
    default:
    /* default item:NonTerminals  ->  . MORE_NonTerminal       followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "MORE_NonTerminal expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_NonTerminal);
      _front_symbol = MORE_NonTerminal_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_NonTerminal")->sub.PointerValue;
}

/* directors of state 277
   equalssym definessym 
 */
front_Defines Parse_state_front_Defines (void)	/* state 277 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x400, 0x20, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(277);
    switch (_front_symbol) {
    case Defines_value:
      n = 1; break; /* accept Defines  ->  . equalssym        followers: front_EOF  */
    case definessym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.definessym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_65();
        break;
      }
    case equalssym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_66();
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Defines  ->  . equalssym   followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "equalssym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _front_symbol = equalssym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Defines")->sub.PointerValue;
}

/* directors of state 278
   hole_OPTMORE_Scoping hole_Scoping CLOSESCOPEsym OPENSCOPEsym SCOPEsym hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym lessthansym CHECKSsym 
 */
front_Rhs Parse_state_front_Rhs (void)	/* state 278 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf801e4, 0x605d, 0xe0000800, 0x210e3e, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(278);
    switch (_front_symbol) {
    case Rhs_value:
      n = 1; break; /* accept Rhs  ->  . OPTMORE_Scoping Symbol1 OPT_Choices OPT_CHECKSsym_OPTMORE_Check      followers: front_EOF  */
    case SCOPEsym_value:
      {
        static Int my_followers[] = { 0xcaf801e4, 0x605d, 0xe0000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_68();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPENSCOPEsym_value:
      {
        static Int my_followers[] = { 0xcaf801e4, 0x605d, 0xe0000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_69();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case CLOSESCOPEsym_value:
      {
        static Int my_followers[] = { 0xcaf801e4, 0x605d, 0xe0000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_70();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Scoping_value: HOLE_ACTION (0, "Scoping");
    case Scoping_value:
      {
        static Int my_followers[] = { 0xcaf80024, 0x605d, 0x40000800, 0x210e3e, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_71(_followers);
        break;
      }
    case hole_OPTMORE_Scoping_value: HOLE_ACTION (0, "List_Scoping");
    case OPTMORE_Scoping_value:
      {
        n = Parse_state_73(followers);
        break;
      }
    default:
    /* default item:Rhs  ->  . OPTMORE_Scoping Symbol1 OPT_Choices OPT_CHECKSsym_OPTMORE_Check followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Scoping);
      _front_symbol = OPTMORE_Scoping_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Rhs")->sub.PointerValue;
}

/* directors of state 279
   ROOTsym hole_ScanInfo SCANsym Identsym 
 */
front_NonTerminal Parse_state_front_NonTerminal (void)	/* state 279 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x8000, 0x20, 0x0, 0x20 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(279);
    switch (_front_symbol) {
    case NonTerminal_value:
      n = 1; break; /* accept NonTerminal  ->  . OPT_ROOTsym OPT_ScanInfo Identsym OPT_Super OPT_MEMOsym OPT_ENUMsym OPT_SKIPsym Defines Rhs semicolonsym     followers: front_EOF  */
    case ROOTsym_value:
      {
        static Int my_followers[] = { 0x4, 0x8000, 0x0, 0x0, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_32();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_ROOTsym_value:
      {
        n = Parse_state_33(followers);
        break;
      }
    default:
    /* default item:NonTerminal  ->  . OPT_ROOTsym OPT_ScanInfo Identsym OPT_Super OPT_MEMOsym OPT_ENUMsym OPT_SKIPsym Defines Rhs semicolonsym        followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_ROOTsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_NonTerminal")->sub.PointerValue;
}

/* directors of state 280
   colonsym lessthansym 
 */
front_Super Parse_state_front_Super (void)	/* state 280 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x28, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(280);
    switch (_front_symbol) {
    case Super_value:
      n = 1; break; /* accept Super  ->  . colonsym Identsym  followers: front_EOF  */
    case lessthansym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_53(followers);
        break;
      }
    case colonsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_55(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Super  ->  . colonsym Identsym     followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "colonsym expected");
      dont_shift = TRUE; _front_symbol = colonsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Super")->sub.PointerValue;
}

/* directors of state 281
   hole_Scoping CLOSESCOPEsym OPENSCOPEsym SCOPEsym 
 */
List_front_Scoping Parse_state_front_OPTMORE_Scoping (void)	/* state 281 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x1c0, 0x0, 0x80000000, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(281);
    switch (_front_symbol) {
    case OPTMORE_Scoping_value:
      n = 1; break; /* accept OPTMORE_Scoping  ->  . Scoping OPTMORE_Scoping  followers: front_EOF  */
    case SCOPEsym_value:
      {
        static Int my_followers[] = { 0x1c0, 0x0, 0xa0000000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_68();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPENSCOPEsym_value:
      {
        static Int my_followers[] = { 0x1c0, 0x0, 0xa0000000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_69();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case CLOSESCOPEsym_value:
      {
        static Int my_followers[] = { 0x1c0, 0x0, 0xa0000000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_70();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Scoping_value: HOLE_ACTION (0, "Scoping");
    case Scoping_value:
      {
        n = Parse_state_71(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Scoping  ->  .     followers: front_EOF  */
      n = 0; _front_symbol = OPTMORE_Scoping_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Scoping);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_Scoping")->sub.PointerValue;
}

/* directors of state 282
   hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym 
 */
front_Symbol Parse_state_front_Symbol1 (void)	/* state 282 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x601d, 0x800, 0x210e3e, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(282);
    switch (_front_symbol) {
    case Symbol1_value:
      n = 1; break; /* accept Symbol1  ->  . SymbolSeq        followers: front_EOF  */
    case front_EOF_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_137(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        n = Parse_state_182(followers);
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_AltSymbol_value: HOLE_ACTION (0, "AltSymbol");
    case AltSymbol_value:
      {
        n = Parse_state_192();
        break;
      }
    default:
    /* default item:Symbol1  ->  . SymbolSeq   followers: front_EOF  */
/* nt = 0x8255e48 */
      PUSH_PARSEVALUE(Pointer,0,front_SymbolSeq);
      _front_symbol = SymbolSeq_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Symbol")->sub.PointerValue;
}

/* directors of state 283
   CLOSESCOPEsym OPENSCOPEsym SCOPEsym 
 */
front_Scoping Parse_state_front_Scoping (void)	/* state 283 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x1c0, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(283);
    switch (_front_symbol) {
    case Scoping_value:
      n = 1; break; /* accept Scoping  ->  . CLOSESCOPEsym    followers: front_EOF  */
    case SCOPEsym_value:
      {
        n = Parse_state_68();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPENSCOPEsym_value:
      {
        n = Parse_state_69();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case CLOSESCOPEsym_value:
      {
        n = Parse_state_70();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Scoping  ->  . CLOSESCOPEsym       followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "CLOSESCOPEsym expected");
      dont_shift = TRUE; _front_symbol = CLOSESCOPEsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Scoping")->sub.IntValue;
}

/* directors of state 284
   hole_Symbol1 hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_AltSymbol hole_Alternator alternate_rightsym alternate_leftsym 
 */
front_Alternative Parse_state_front_Alternative (void)	/* state 284 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x601d, 0x40000800, 0x210e3e, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(284);
    switch (_front_symbol) {
    case Alternative_value:
      n = 1; break; /* accept Alternative  ->  . Symbol1      followers: front_EOF  */
    case front_EOF_value:
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_237(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        n = Parse_state_182(followers);
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_AltSymbol_value: HOLE_ACTION (0, "AltSymbol");
    case AltSymbol_value:
      {
        n = Parse_state_192();
        break;
      }
    case hole_Symbol1_value: HOLE_ACTION (0, "Symbol1");
    case Symbol1_value:
      {
        n = Parse_state_242();
        break;
      }
    default:
    /* default item:Alternative  ->  . Symbol1 followers: front_EOF  */
/* nt = 0x8254c48 */
      n = 0; _front_symbol = Symbol1_value;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Alternative")->sub.PointerValue;
}

/* directors of state 285
   hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym Identsym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
front_Symbol Parse_state_front_Symbol2 (void)	/* state 285 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x1d, 0x800, 0x10e00, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(285);
    switch (_front_symbol) {
    case Symbol2_value:
      n = 1; break; /* accept Symbol2  ->  . SimpleSymbol     followers: front_EOF  */
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x1c, 0x0, 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_80(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        n = Parse_state_168(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Symbol2  ->  . SimpleSymbol        followers: front_EOF  */
/* nt = 0x825e1e0 */
      n = 0; _front_symbol = SimpleSymbol_value;
      { ParseValue me;
        front_Expr  layout = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Symbol");
        me->sub.PointerValue = Create_front_LayoutAction(src_info, layout);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("front_Symbol")->sub.PointerValue;
}

/* directors of state 286
   hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym Identsym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
front_Symbol Parse_state_front_Symbol (void)	/* state 286 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x1d, 0x800, 0x10e02, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(286);
    switch (_front_symbol) {
    case Symbol_value:
      n = 1; break; /* accept Symbol  ->  . Symbol2   followers: front_EOF  */
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x1c, 0x0, 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_186(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0x40000, 0x0, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        n = Parse_state_168(followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        n = Parse_state_171();
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Symbol  ->  . Symbol2      followers: front_EOF  */
/* nt = 0x82583d8 */
      n = 0; _front_symbol = Symbol2_value;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Symbol")->sub.PointerValue;
}

/* directors of state 287
   hole_SymbolSeq hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym hole_Alternator alternate_rightsym alternate_leftsym 
 */
front_Symbol Parse_state_front_AltSymbol (void)	/* state 287 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x601d, 0x800, 0x210e36, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(287);
    switch (_front_symbol) {
    case AltSymbol_value:
      n = 1; break; /* accept AltSymbol  ->  . SymbolSeq Alternator MORE_Symbol       followers: front_EOF  */
    case hole_Alternator_value:
    case alternate_rightsym_value:
    case alternate_leftsym_value:
      n = 0; _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Symbol);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Field);
        PUSH_PARSEVALUE(Pointer,NULL,List_front_And);
      }
      break;
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_137(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x601d, 0x800, 0x210ea6, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_174(_followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_180();
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        static Int my_followers[] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_181();
        break;
      }
    case hole_SymbolSeq_value: HOLE_ACTION (0, "SymbolSeq");
    case SymbolSeq_value:
      {
        n = Parse_state_288(followers);
        break;
      }
    default:
    /* default item:AltSymbol  ->  . SymbolSeq Alternator MORE_Symbol  followers: front_EOF  */
/* nt = 0x8255e48 */
      PUSH_PARSEVALUE(Pointer,0,front_SymbolSeq);
      _front_symbol = SymbolSeq_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Symbol")->sub.PointerValue;
}

/* directors of state 288
   hole_Alternator alternate_rightsym alternate_leftsym 
 */
static int Parse_state_288 (SymbolSet followers)	/* state 288 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x6000, 0x0, 0x20, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(288);
    switch (_front_symbol) {
    case alternate_leftsym_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_183();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case alternate_rightsym_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_184();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Alternator_value: HOLE_ACTION (0, "Alternator");
    case Alternator_value:
      {
        n = Parse_state_185(followers);
        break;
      }
    default:
    /* default item:AltSymbol  ->  SymbolSeq . Alternator MORE_Symbol       followers: front_EOF  */
/* nt = 0x826cfa8 */
      n = 0; _front_symbol = Alternator_value;
      PUSH_PARSEVALUE(Int,TRUE,front_Alternator);
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 289
   hole_Field Identsym hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
front_Symbol Parse_state_front_SymbolSeq (void)	/* state 289 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x1d, 0x800, 0x210e06, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(289);
    switch (_front_symbol) {
    case SymbolSeq_value:
      n = 1; break; /* accept SymbolSeq  ->  . OPT_ALT_ONCE_SymbolORField_SEP_And     followers: front_EOF  */
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_137(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafc3804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_172();
        break;
      }
    case hole_Field_value: HOLE_ACTION (0, "Field");
    case Field_value:
      {
        static Int my_followers[] = { 0xcaf83804, 0x1d, 0x800, 0x210e86, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_173();
        break;
      }
    case ONCE_SymbolORField_value:
      {
        n = Parse_state_174(followers);
        break;
      }
    case ALT_ONCE_SymbolORField_SEP_And_value:
      {
        n = Parse_state_180();
        break;
      }
    case OPT_ALT_ONCE_SymbolORField_SEP_And_value:
      {
        n = Parse_state_181();
        break;
      }
    default:
    /* default item:SymbolSeq  ->  . OPT_ALT_ONCE_SymbolORField_SEP_And        followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_front_Symbol);
      PUSH_PARSEVALUE(Pointer,0,List_front_Field);
      PUSH_PARSEVALUE(Pointer,0,List_front_And);
      _front_symbol = OPT_ALT_ONCE_SymbolORField_SEP_And_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Symbol")->sub.PointerValue;
}

/* directors of state 290
   alternate_rightsym alternate_leftsym 
 */
front_Alternator Parse_state_front_Alternator (void)	/* state 290 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x6000, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(290);
    switch (_front_symbol) {
    case Alternator_value:
      n = 1; break; /* accept Alternator  ->  . alternate_rightsym    followers: front_EOF  */
    case alternate_leftsym_value:
      {
        n = Parse_state_183();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case alternate_rightsym_value:
      {
        n = Parse_state_184();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Alternator  ->  . alternate_rightsym       followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "alternate_rightsym expected");
      dont_shift = TRUE; _front_symbol = alternate_rightsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Alternator")->sub.IntValue;
}

/* directors of state 291
   hole_Symbol hole_Symbol2 hole_SimpleSymbol LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym Identsym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
List_front_Symbol Parse_state_front_MORE_Symbol (void)	/* state 291 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x1d, 0x800, 0x10e06, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(291);
    switch (_front_symbol) {
    case MORE_Symbol_value:
      n = 1; break; /* accept MORE_Symbol  ->  . Symbol MORE_Symbol   followers: front_EOF  */
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_75(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_186(_followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(_followers);
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(_followers);
        break;
      }
    case Charsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(_followers);
        break;
      }
    case Keywordsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(_followers);
        break;
      }
    case open2symsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(_followers);
        break;
      }
    case LAYOUTsym_value:
      {
        static Int my_followers[] = { 0xcafc0004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(_followers);
        break;
      }
    case hole_SimpleSymbol_value: HOLE_ACTION (0, "SimpleSymbol");
    case SimpleSymbol_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_168(_followers);
        break;
      }
    case hole_Symbol2_value: HOLE_ACTION (0, "Symbol2");
    case Symbol2_value:
      {
        static Int my_followers[] = { 0xcaf80004, 0x1d, 0x800, 0x10e46, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_171();
        break;
      }
    case hole_Symbol_value: HOLE_ACTION (0, "Symbol");
    case Symbol_value:
      {
        n = Parse_state_189(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:MORE_Symbol  ->  . Symbol  followers: front_EOF  */
/* nt = 0x82545d8 */
      n = 0; _front_symbol = Symbol_value;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_Symbol")->sub.PointerValue;
}

/* directors of state 292
   RightAndsym LeftAndsym Newlinesym 
 */
front_And Parse_state_front_And (void)	/* state 292 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x3800, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(292);
    switch (_front_symbol) {
    case And_value:
      n = 1; break; /* accept And  ->  .      followers: front_EOF  */
    case Newlinesym_value:
      {
        n = Parse_state_175();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case LeftAndsym_value:
      {
        n = Parse_state_176();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case RightAndsym_value:
      {
        n = Parse_state_177();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
    /* default item:And  ->  . followers: front_EOF  */
      n = 0; _front_symbol = And_value;
      PUSH_PARSEVALUE(Int,front_AndCenter,front_And);
      break;
    }
  } while (n==0);
  return PopParseValue("front_And")->sub.IntValue;
}

/* directors of state 293
   Xorsym RightOrsym LeftOrsym verticalbarsym 
 */
front_Or Parse_state_front_Or (void)	/* state 293 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x3c000, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(293);
    switch (_front_symbol) {
    case Or_value:
      n = 1; break; /* accept Or  ->  . Xorsym        followers: front_EOF  */
    case verticalbarsym_value:
      {
        n = Parse_state_194();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case LeftOrsym_value:
      {
        n = Parse_state_195();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case RightOrsym_value:
      {
        n = Parse_state_196();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Xorsym_value:
      {
        n = Parse_state_197();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Or  ->  . Xorsym   followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Xorsym expected");
      dont_shift = TRUE; _front_symbol = Xorsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Or")->sub.IntValue;
}

/* directors of state 294
   LAYOUTsym backslashbackslashsym EMPTYsym openchainsym openbrksym open2symsym Keywordsym Charsym Stringsym APPLIEDsym hole_IdSym Identsym hole_DefiningSym FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
front_Symbol Parse_state_front_SimpleSymbol (void)	/* state 294 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0xcaf80004, 0x1d, 0x800, 0x10c00, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(294);
    switch (_front_symbol) {
    case SimpleSymbol_value:
      n = 1; break; /* accept SimpleSymbol  ->  . LAYOUTsym Expr      followers: front_EOF  */
    case hole_Define_value:
    case OVERLOADINGsym_value:
    case REDEFININGsym_value:
    case DEFININGsym_value:
      n = 0; _front_symbol = OPT_FORWARDsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0x0, 0x1c, 0x0, 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        n = Parse_state_75(followers);
        break;
      }
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_80(followers);
        break;
      }
    case hole_DefiningSym_value: HOLE_ACTION (0, "DefiningSym");
    case DefiningSym_value:
      {
        n = Parse_state_140();
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        n = Parse_state_141();
        break;
      }
    case APPLIEDsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_142(followers);
        break;
      }
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_151(followers);
        break;
      }
    case Charsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_156(followers);
        break;
      }
    case Keywordsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_158(followers);
        break;
      }
    case open2symsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_160(followers);
        break;
      }
    case openbrksym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_161(followers);
        break;
      }
    case openchainsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(followers);
        break;
      }
    case EMPTYsym_value:
      {
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case backslashbackslashsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164(followers);
        break;
      }
    case LAYOUTsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_166(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:SimpleSymbol  ->  . EMPTYsym       followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "EMPTYsym expected");
      dont_shift = TRUE; _front_symbol = EMPTYsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Symbol")->sub.PointerValue;
}

/* directors of state 295
   FORWARDsym hole_Define OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
front_Symbol Parse_state_front_DefiningSym (void)	/* state 295 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x1c, 0x800, 0x10000, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(295);
    switch (_front_symbol) {
    case DefiningSym_value:
      n = 1; break; /* accept DefiningSym  ->  . OPT_FORWARDsym Define Defining_id OPT_NAMESPACEsym_Identsym OPT_ScopeExpr    followers: front_EOF  */
    case FORWARDsym_value:
      {
        static Int my_followers[] = { 0x0, 0x1c, 0x0, 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_74();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_FORWARDsym_value:
      {
        n = Parse_state_75(followers);
        break;
      }
    default:
    /* default item:DefiningSym  ->  . OPT_FORWARDsym Define Defining_id OPT_NAMESPACEsym_Identsym OPT_ScopeExpr       followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_FORWARDsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Symbol")->sub.PointerValue;
}

/* directors of state 296
   Identsym 
 */
front_Symbol Parse_state_front_IdSym (void)	/* state 296 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(296);
    switch (_front_symbol) {
    case IdSym_value:
      n = 1; break; /* accept IdSym  ->  . Identsym OptType   followers: front_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_80(followers);
        break;
      }
    default:
    /* default item:IdSym  ->  . Identsym OptType      followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _front_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Symbol")->sub.PointerValue;
}

/* directors of state 297
   FIELDsym NAMEsym 
 */
front_NameOrField Parse_state_front_NameOrField (void)	/* state 297 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x3, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(297);
    switch (_front_symbol) {
    case NameOrField_value:
      n = 1; break; /* accept NameOrField  ->  . FIELDsym     followers: front_EOF  */
    case NAMEsym_value:
      {
        n = Parse_state_144();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case FIELDsym_value:
      {
        n = Parse_state_145();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:NameOrField  ->  . FIELDsym        followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "FIELDsym expected");
      dont_shift = TRUE; _front_symbol = FIELDsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_NameOrField")->sub.IntValue;
}

/* directors of state 298
   TYPEsym 
 */
front_Type Parse_state_front_OptType (void)	/* state 298 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x0, 0x400, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(298);
    switch (_front_symbol) {
    case OptType_value:
      n = 1; break; /* accept OptType  ->  . OPT_TYPEsym_Type followers: front_EOF  */
    case TYPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    case OPT_TYPEsym_Type_value:
      {
        n = Parse_state_46();
        break;
      }
    default:
    /* default item:OptType  ->  . OPT_TYPEsym_Type    followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = OPT_TYPEsym_Type_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Type")->sub.PointerValue;
}

/* directors of state 299
   Charsym Keywordsym Stringsym 
 */
String Parse_state_front_StringOrKeyword (void)	/* state 299 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x700000, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(299);
    switch (_front_symbol) {
    case StringOrKeyword_value:
      n = 1; break; /* accept StringOrKeyword  ->  . Charsym  followers: front_EOF  */
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_104();
        break;
      }
    case Keywordsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_105();
        break;
      }
    case Charsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_106();
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:StringOrKeyword  ->  . Charsym     followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Charsym expected");
      PUSH_PARSEVALUE(String,0,String);
      dont_shift = TRUE; _front_symbol = Charsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("String")->sub.PointerValue;
}

/* directors of state 300
   hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
front_Expr Parse_state_front_Expr (void)	/* state 300 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(300);
    switch (_front_symbol) {
    case Expr_value:
      n = 1; break; /* accept Expr  ->  . ALT_MonExpr1_SEP_SP_Oper    followers: front_EOF  */
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_112(followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        n = Parse_state_115();
        break;
      }
    default:
    /* default item:Expr  ->  . ALT_MonExpr1_SEP_SP_Oper       followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_MonExpr1_SEP_SP_Oper expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_Expr);
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _front_symbol = ALT_MonExpr1_SEP_SP_Oper_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Expr")->sub.PointerValue;
}

/* directors of state 301
   OVERLOADINGsym REDEFININGsym DEFININGsym 
 */
front_Define Parse_state_front_Define (void)	/* state 301 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x1c, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(301);
    switch (_front_symbol) {
    case Define_value:
      n = 1; break; /* accept Define  ->  . OVERLOADINGsym    followers: front_EOF  */
    case DEFININGsym_value:
      {
        n = Parse_state_76();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case REDEFININGsym_value:
      {
        n = Parse_state_77();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OVERLOADINGsym_value:
      {
        n = Parse_state_78();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Define  ->  . OVERLOADINGsym       followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "OVERLOADINGsym expected");
      dont_shift = TRUE; _front_symbol = OVERLOADINGsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Define")->sub.IntValue;
}

/* directors of state 302
   openparsym hole_IdSym Identsym 
 */
front_Defining_id Parse_state_front_Defining_id (void)	/* state 302 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x2, 0x0, 0x800, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(302);
    switch (_front_symbol) {
    case Defining_id_value:
      n = 1; break; /* accept Defining_id  ->  . openparsym Expr closeparsym  followers: front_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_80(followers);
        break;
      }
    case hole_IdSym_value: HOLE_ACTION (0, "IdSym");
    case IdSym_value:
      {
        n = Parse_state_82();
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_83(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Defining_id  ->  . IdSym   followers: front_EOF  */
/* nt = 0x825ebd0 */
      InputError (SCAN_POSITION, TRUE, "IdSym expected");
      PUSH_PARSEVALUE(Pointer,0,front_IdSym);
      _front_symbol = IdSym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Defining_id")->sub.PointerValue;
}

/* directors of state 303
   SCOPEsym 
 */
front_Expr Parse_state_front_ScopeExpr (void)	/* state 303 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x40, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(303);
    switch (_front_symbol) {
    case ScopeExpr_value:
      n = 1; break; /* accept ScopeExpr  ->  . SCOPEsym Expr  followers: front_EOF  */
    case SCOPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133(followers);
        break;
      }
    default:
    /* default item:ScopeExpr  ->  . SCOPEsym Expr     followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "SCOPEsym expected");
      dont_shift = TRUE; _front_symbol = SCOPEsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Expr")->sub.PointerValue;
}

/* directors of state 304
   Identsym 
 */
front_Type Parse_state_front_Type (void)	/* state 304 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(304);
    switch (_front_symbol) {
    case Type_value:
      n = 1; break; /* accept Type  ->  . Identsym OPT_openparsym_TypeList_closeparsym        followers: front_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_36(followers);
        break;
      }
    default:
    /* default item:Type  ->  . Identsym OPT_openparsym_TypeList_closeparsym   followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _front_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Type")->sub.PointerValue;
}

/* directors of state 305
   hole_ALT_FieldInit_SEP_commasym hole_FieldInit CHECKSsym APPLIEDsym DEFININGsym SCOPEsym CREATEsym hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
List_front_FieldInit Parse_state_front_FieldInits (void)	/* state 305 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20780044, 0xffff0744, 0x8000, 0x7c0c000, 0x80 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(305);
    switch (_front_symbol) {
    case FieldInits_value:
      n = 1; break; /* accept FieldInits  ->  . ALT_FieldInit_SEP_commasym    followers: front_EOF  */
    case hole_Expr_value:
    case hole_MonExpr1_value:
    case hole_OPTMORE_Oper_value:
    case hole_Oper_value:
    case greaterthangreaterthansym_value:
    case lessthanlessthansym_value:
    case percentsym_value:
    case slashsym_value:
    case starsym_value:
    case minussym_value:
    case plussym_value:
    case hatsym_value:
    case verticalbarverticalbarsym_value:
    case ampersandampersandsym_value:
    case ampersandsym_value:
    case greaterthanequalssym_value:
    case lessthanequalssym_value:
    case exclaimequalssym_value:
    case equalsequalssym_value:
    case exclaimsym_value:
    case tildasym_value:
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPT_CREATEsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case CREATEsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x700c000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_213();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_CREATEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_214(_followers);
        break;
      }
    case SCOPEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_216(_followers);
        break;
      }
    case DEFININGsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_218(_followers);
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_220(_followers);
        break;
      }
    case CHECKSsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_222(_followers);
        break;
      }
    case hole_FieldInit_value: HOLE_ACTION (0, "FieldInit");
    case FieldInit_value:
      {
        n = Parse_state_224(followers);
        break;
      }
    case hole_ALT_FieldInit_SEP_commasym_value: HOLE_ACTION (0, "List_FieldInit");
    case ALT_FieldInit_SEP_commasym_value:
      {
        n = Parse_state_227();
        break;
      }
    default:
    /* default item:FieldInits  ->  . ALT_FieldInit_SEP_commasym       followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_FieldInit_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_FieldInit);
      _front_symbol = ALT_FieldInit_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_FieldInit")->sub.PointerValue;
}

/* directors of state 306
   Identsym 
 */
front_Field Parse_state_front_Field (void)	/* state 306 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(306);
    switch (_front_symbol) {
    case Field_value:
      n = 1; break; /* accept Field  ->  . Identsym colonsym Type equalssym FieldInits OPT_TRAVERSEsym OPT_CLEARsym OPT_DONT_CLEARsym followers: front_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_307(followers);
        break;
      }
    default:
    /* default item:Field  ->  . Identsym colonsym Type equalssym FieldInits OPT_TRAVERSEsym OPT_CLEARsym OPT_DONT_CLEARsym    followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _front_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Field")->sub.PointerValue;
}

/* directors of state 307
   colonsym 
 */
static int Parse_state_307 (SymbolSet followers)	/* state 307 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_308(followers);
      }
  return n-1;
}

/* directors of state 308
   hole_Type Identsym 
 */
static int Parse_state_308 (SymbolSet followers)	/* state 308 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x80000, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(308);
    switch (_front_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x20, 0x0, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_36(_followers);
        break;
      }
    case hole_Type_value: HOLE_ACTION (0, "Type");
    case Type_value:
      {
        n = Parse_state_211(followers);
        break;
      }
    default:
    /* default item:Field  ->  Identsym colonsym . Type equalssym FieldInits OPT_TRAVERSEsym OPT_CLEARsym OPT_DONT_CLEARsym followers: front_EOF  */
/* nt = 0x8265dd0 */
      InputError (SCAN_POSITION, TRUE, "Type expected");
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = Type_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 309
   hole_FieldInit CHECKSsym APPLIEDsym DEFININGsym SCOPEsym CREATEsym hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
List_front_FieldInit Parse_state_front_ALT_FieldInit_SEP_commasym (void)	/* state 309 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20780044, 0xffff0744, 0x8000, 0x780c000, 0x80 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(309);
    switch (_front_symbol) {
    case ALT_FieldInit_SEP_commasym_value:
      n = 1; break; /* accept ALT_FieldInit_SEP_commasym  ->  . FieldInit commasym ALT_FieldInit_SEP_commasym followers: front_EOF  */
    case hole_Expr_value:
    case hole_MonExpr1_value:
    case hole_OPTMORE_Oper_value:
    case hole_Oper_value:
    case greaterthangreaterthansym_value:
    case lessthanlessthansym_value:
    case percentsym_value:
    case slashsym_value:
    case starsym_value:
    case minussym_value:
    case plussym_value:
    case hatsym_value:
    case verticalbarverticalbarsym_value:
    case ampersandampersandsym_value:
    case ampersandsym_value:
    case greaterthanequalssym_value:
    case lessthanequalssym_value:
    case exclaimequalssym_value:
    case equalsequalssym_value:
    case exclaimsym_value:
    case tildasym_value:
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPT_CREATEsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case CREATEsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x700c000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_213();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_CREATEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_214(_followers);
        break;
      }
    case SCOPEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_216(_followers);
        break;
      }
    case DEFININGsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_218(_followers);
        break;
      }
    case APPLIEDsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_220(_followers);
        break;
      }
    case CHECKSsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_222(_followers);
        break;
      }
    case hole_FieldInit_value: HOLE_ACTION (0, "FieldInit");
    case FieldInit_value:
      {
        n = Parse_state_224(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_FieldInit_SEP_commasym  ->  . FieldInit        followers: front_EOF  */
/* nt = 0x8265110 */
      n = 0; _front_symbol = FieldInit_value;
      { ParseValue me;
        front_Expr  expr = POP_PARSEVALUE (Pointer, front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_FieldInit");
        me->sub.PointerValue = Create_front_WhenChecks(src_info, expr);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_FieldInit")->sub.PointerValue;
}

/* directors of state 310
   CHECKSsym APPLIEDsym DEFININGsym SCOPEsym CREATEsym hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
front_FieldInit Parse_state_front_FieldInit (void)	/* state 310 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20780044, 0xffff0744, 0x8000, 0x700c000, 0x80 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(310);
    switch (_front_symbol) {
    case FieldInit_value:
      n = 1; break; /* accept FieldInit  ->  . CHECKSsym Expr followers: front_EOF  */
    case hole_Expr_value:
    case hole_MonExpr1_value:
    case hole_OPTMORE_Oper_value:
    case hole_Oper_value:
    case greaterthangreaterthansym_value:
    case lessthanlessthansym_value:
    case percentsym_value:
    case slashsym_value:
    case starsym_value:
    case minussym_value:
    case plussym_value:
    case hatsym_value:
    case verticalbarverticalbarsym_value:
    case ampersandampersandsym_value:
    case ampersandsym_value:
    case greaterthanequalssym_value:
    case lessthanequalssym_value:
    case exclaimequalssym_value:
    case equalsequalssym_value:
    case exclaimsym_value:
    case tildasym_value:
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPT_CREATEsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case CREATEsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_213();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_CREATEsym_value:
      {
        n = Parse_state_214(followers);
        break;
      }
    case SCOPEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_216(followers);
        break;
      }
    case DEFININGsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_218(followers);
        break;
      }
    case APPLIEDsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_220(followers);
        break;
      }
    case CHECKSsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_222(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:FieldInit  ->  . OPT_CREATEsym Expr        followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _front_symbol = OPT_CREATEsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_FieldInit")->sub.PointerValue;
}

/* directors of state 311
   hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym 
 */
List_Ident Parse_state_front_OPTMORE_Oper (void)	/* state 311 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x80 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(311);
    switch (_front_symbol) {
    case OPTMORE_Oper_value:
      n = 1; break; /* accept OPTMORE_Oper  ->  . Oper OPTMORE_Oper   followers: front_EOF  */
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x0, 0x1000000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        n = Parse_state_101(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Oper  ->  .        followers: front_EOF  */
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Ident")->sub.PointerValue;
}

/* directors of state 312
   hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
front_Expr Parse_state_front_SimpleExpr (void)	/* state 312 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x700004, 0x700, 0x0, 0x2004000, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(312);
    switch (_front_symbol) {
    case SimpleExpr_value:
      n = 1; break; /* accept SimpleExpr  ->  . SimpleExpr openparsym OPT_ExprList closeparsym        followers: front_EOF openparsym dotsym  */
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_104();
        break;
      }
    case Keywordsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Keywordsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_105();
        break;
      }
    case Charsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,front_lval.Charsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_106();
        break;
      }
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_107();
        break;
      }
    /*
      {
        n = Parse_state_313(followers);
        break;
      }
    */
    case Intsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,front_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_123();
        break;
      }
    case Boolsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,front_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_124();
        break;
      }
    case hole_StringOrKeyword_value: HOLE_ACTION (0, "String");
    case StringOrKeyword_value:
      {
        n = Parse_state_125();
        break;
      }
    case NULLsym_value:
      {
        n = Parse_state_126();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:SimpleExpr  ->  . NULLsym        followers: front_EOF openparsym dotsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "NULLsym expected");
      dont_shift = TRUE; _front_symbol = NULLsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Expr")->sub.PointerValue;
}

/* directors of state 313
   openparsym dotsym 
 */
static int Parse_state_313 (SymbolSet followers)	/* state 313 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x82, 0x0, 0x0, 0x0 };
  Int _followers[5];
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(313);
    switch (_front_symbol) {
    case dotsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_109(followers);
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_111(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:SimpleExpr  ->  SimpleExpr . openparsym OPT_ExprList closeparsym        followers: front_EOF openparsym dotsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "openparsym expected");
      dont_shift = TRUE; _front_symbol = openparsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 314
   hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
front_Expr Parse_state_front_MonExpr1 (void)	/* state 314 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(314);
    switch (_front_symbol) {
    case MonExpr1_value:
      n = 1; break; /* accept MonExpr1  ->  . OPTMORE_Oper SimpleExpr followers: front_EOF  */
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x700004, 0x700, 0x0, 0x2004000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        n = Parse_state_103(followers);
        break;
      }
    default:
    /* default item:MonExpr1  ->  . OPTMORE_Oper SimpleExpr    followers: front_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _front_symbol = OPTMORE_Oper_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Expr")->sub.PointerValue;
}

/* directors of state 315
   hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
List_front_Expr Parse_state_front_MORE_MonExpr1 (void)	/* state 315 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x7004000, 0x80 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(315);
    switch (_front_symbol) {
    case MORE_MonExpr1_value:
      n = 1; break; /* accept MORE_MonExpr1  ->  . MonExpr1 MORE_MonExpr1     followers: front_EOF  */
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x0, 0xf004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        n = Parse_state_257(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:MORE_MonExpr1  ->  . MonExpr1      followers: front_EOF  */
/* nt = 0x8266d50 */
      n = 0; _front_symbol = MonExpr1_value;
      { ParseValue me;
        front_Expr  arg = POP_PARSEVALUE (Pointer, front_Expr);
        List_Ident  op = POP_PARSEVALUE (Pointer, List_Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_MonExpr(src_info, op, arg);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_Expr")->sub.PointerValue;
}

/* directors of state 316
   IFsym 
 */
front_Check Parse_state_front_Check (void)	/* state 316 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x800, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(316);
    switch (_front_symbol) {
    case Check_value:
      n = 1; break; /* accept Check  ->  . IFsym Expr THENsym OPT_WARNINGsym MORE_MonExpr1    followers: front_EOF  */
    case IFsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_253(followers);
        break;
      }
    default:
    /* default item:Check  ->  . IFsym Expr THENsym OPT_WARNINGsym MORE_MonExpr1       followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "IFsym expected");
      dont_shift = TRUE; _front_symbol = IFsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_Check")->sub.PointerValue;
}

/* directors of state 317
   hole_NameSpace Identsym 
 */
List_front_NameSpace Parse_state_front_ALT_NameSpace_SEP_commasym_SP (void)	/* state 317 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x0, 0x40 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(317);
    switch (_front_symbol) {
    case ALT_NameSpace_SEP_commasym_SP_value:
      n = 1; break; /* accept ALT_NameSpace_SEP_commasym_SP  ->  . NameSpace commasym ALT_NameSpace_SEP_commasym_SP   followers: front_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_24();
        break;
      }
    case hole_NameSpace_value: HOLE_ACTION (0, "NameSpace");
    case NameSpace_value:
      {
        n = Parse_state_25(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_NameSpace_SEP_commasym_SP  ->  . NameSpace     followers: front_EOF  */
/* nt = 0x826e708 */
      InputError (SCAN_POSITION, TRUE, "NameSpace expected");
      PUSH_PARSEVALUE(Pointer,0,front_NameSpace);
      _front_symbol = NameSpace_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_NameSpace")->sub.PointerValue;
}

/* directors of state 318
   hole_ALT_NameSpace_SEP_commasym_SP hole_NameSpace Identsym 
 */
List_front_NameSpace Parse_state_front_NameSpaceList (void)	/* state 318 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x20000000, 0x40 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(318);
    switch (_front_symbol) {
    case NameSpaceList_value:
      n = 1; break; /* accept NameSpaceList  ->  . ALT_NameSpace_SEP_commasym_SP      followers: front_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_24();
        break;
      }
    case hole_NameSpace_value: HOLE_ACTION (0, "NameSpace");
    case NameSpace_value:
      {
        n = Parse_state_25(followers);
        break;
      }
    case hole_ALT_NameSpace_SEP_commasym_SP_value: HOLE_ACTION (0, "List_NameSpace");
    case ALT_NameSpace_SEP_commasym_SP_value:
      {
        n = Parse_state_28();
        break;
      }
    default:
    /* default item:NameSpaceList  ->  . ALT_NameSpace_SEP_commasym_SP followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_NameSpace_SEP_commasym_SP expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_NameSpace);
      _front_symbol = ALT_NameSpace_SEP_commasym_SP_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_NameSpace")->sub.PointerValue;
}

/* directors of state 319
   hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
List_front_Expr Parse_state_front_ALT_Expr_SEP_commasym_SP (void)	/* state 319 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x700c000, 0x80 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(319);
    switch (_front_symbol) {
    case ALT_Expr_SEP_commasym_SP_value:
      n = 1; break; /* accept ALT_Expr_SEP_commasym_SP  ->  . Expr commasym ALT_Expr_SEP_commasym_SP  followers: front_EOF  */
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x10, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_112(_followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_116(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_Expr_SEP_commasym_SP  ->  . Expr       followers: front_EOF  */
/* nt = 0x8266530 */
      n = 0; _front_symbol = Expr_value;
      { ParseValue me;
        List_Ident  ops = POP_PARSEVALUE (Pointer, List_Ident);
        List_front_Expr  args = POP_PARSEVALUE (Pointer, List_front_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("front_Expr");
        me->sub.PointerValue = Create_front_BinExpr(src_info, args, ops);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_Expr")->sub.PointerValue;
}

/* directors of state 320
   hole_ALT_Expr_SEP_commasym_SP hole_Expr hole_MonExpr1 hole_OPTMORE_Oper hole_Oper greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym hole_SimpleExpr NULLsym hole_StringOrKeyword Charsym Keywordsym Stringsym Boolsym Intsym Identsym 
 */
List_front_Expr Parse_state_front_ExprList (void)	/* state 320 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20700004, 0xffff0700, 0x0, 0x8700c000, 0x80 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(320);
    switch (_front_symbol) {
    case ExprList_value:
      n = 1; break; /* accept ExprList  ->  . ALT_Expr_SEP_commasym_SP        followers: front_EOF  */
    case hole_SimpleExpr_value:
    case NULLsym_value:
    case hole_StringOrKeyword_value:
    case Charsym_value:
    case Keywordsym_value:
    case Stringsym_value:
    case Boolsym_value:
    case Intsym_value:
    case Identsym_value:
      n = 0; _front_symbol = OPTMORE_Oper_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    case tildasym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x3004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    case hole_Oper_value: HOLE_ACTION (0, "Ident");
    case Oper_value:
      {
        static Int my_followers[] = { 0x20700004, 0xffff0700, 0x10, 0x2004000, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_101(_followers);
        break;
      }
    case hole_OPTMORE_Oper_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_Oper_value:
      {
        static Int my_followers[] = { 0x20000000, 0xffff0000, 0x10, 0x0, 0x80 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_103(_followers);
        break;
      }
    case hole_MonExpr1_value: HOLE_ACTION (0, "MonExpr1");
    case MonExpr1_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_112(_followers);
        break;
      }
    case ALT_MonExpr1_SEP_SP_Oper_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        n = Parse_state_115();
        break;
      }
    case hole_Expr_value: HOLE_ACTION (0, "Expr");
    case Expr_value:
      {
        n = Parse_state_116(followers);
        break;
      }
    case hole_ALT_Expr_SEP_commasym_SP_value: HOLE_ACTION (0, "List_Expr");
    case ALT_Expr_SEP_commasym_SP_value:
      {
        n = Parse_state_119();
        break;
      }
    default:
    /* default item:ExprList  ->  . ALT_Expr_SEP_commasym_SP   followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Expr_SEP_commasym_SP expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_Expr);
      _front_symbol = ALT_Expr_SEP_commasym_SP_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_Expr")->sub.PointerValue;
}

/* directors of state 321
   Identsym 
 */
List_Ident Parse_state_front_ALT_Identsym_SEP_commasym_SP (void)	/* state 321 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(321);
    switch (_front_symbol) {
    case ALT_Identsym_SEP_commasym_SP_value:
      n = 1; break; /* accept ALT_Identsym_SEP_commasym_SP  ->  . Identsym commasym ALT_Identsym_SEP_commasym_SP      followers: front_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_Identsym_SEP_commasym_SP  ->  . Identsym       followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _front_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Ident")->sub.PointerValue;
}

/* directors of state 322
   hole_ALT_Identsym_SEP_commasym_SP Identsym 
 */
List_Ident Parse_state_front_IdentList (void)	/* state 322 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x0, 0x2 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(322);
    switch (_front_symbol) {
    case IdentList_value:
      n = 1; break; /* accept IdentList  ->  . ALT_Identsym_SEP_commasym_SP   followers: front_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
        break;
      }
    case hole_ALT_Identsym_SEP_commasym_SP_value: HOLE_ACTION (0, "List_Ident");
    case ALT_Identsym_SEP_commasym_SP_value:
      {
        n = Parse_state_20();
        break;
      }
    default:
    /* default item:IdentList  ->  . ALT_Identsym_SEP_commasym_SP      followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Identsym_SEP_commasym_SP expected");
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _front_symbol = ALT_Identsym_SEP_commasym_SP_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Ident")->sub.PointerValue;
}

/* directors of state 323
   hole_Type Identsym 
 */
List_front_Type Parse_state_front_ALT_Type_SEP_commasym_SP (void)	/* state 323 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x80000, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(323);
    switch (_front_symbol) {
    case ALT_Type_SEP_commasym_SP_value:
      n = 1; break; /* accept ALT_Type_SEP_commasym_SP  ->  . Type commasym ALT_Type_SEP_commasym_SP  followers: front_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_36(_followers);
        break;
      }
    case hole_Type_value: HOLE_ACTION (0, "Type");
    case Type_value:
      {
        n = Parse_state_38(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_Type_SEP_commasym_SP  ->  . Type       followers: front_EOF  */
/* nt = 0x8265dd0 */
      InputError (SCAN_POSITION, TRUE, "Type expected");
      PUSH_PARSEVALUE(Pointer,0,front_Type);
      _front_symbol = Type_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_Type")->sub.PointerValue;
}

/* directors of state 324
   hole_ALT_Type_SEP_commasym_SP hole_Type Identsym 
 */
List_front_Type Parse_state_front_TypeList (void)	/* state 324 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x80000, 0x8 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(324);
    switch (_front_symbol) {
    case TypeList_value:
      n = 1; break; /* accept TypeList  ->  . ALT_Type_SEP_commasym_SP        followers: front_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x0, 0x10, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_36(_followers);
        break;
      }
    case hole_Type_value: HOLE_ACTION (0, "Type");
    case Type_value:
      {
        n = Parse_state_38(followers);
        break;
      }
    case hole_ALT_Type_SEP_commasym_SP_value: HOLE_ACTION (0, "List_Type");
    case ALT_Type_SEP_commasym_SP_value:
      {
        n = Parse_state_41();
        break;
      }
    default:
    /* default item:TypeList  ->  . ALT_Type_SEP_commasym_SP   followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Type_SEP_commasym_SP expected");
      PUSH_PARSEVALUE(Pointer,0,List_front_Type);
      _front_symbol = ALT_Type_SEP_commasym_SP_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_Type")->sub.PointerValue;
}

/* directors of state 325
   SCANsym 
 */
front_ScanInfo Parse_state_front_ScanInfo (void)	/* state 325 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x8000, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(325);
    switch (_front_symbol) {
    case ScanInfo_value:
      n = 1; break; /* accept ScanInfo  ->  . SCANsym OptType OPT_COMMENTsym  followers: front_EOF  */
    case SCANsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(followers);
        break;
      }
    default:
    /* default item:ScanInfo  ->  . SCANsym OptType OPT_COMMENTsym     followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "SCANsym expected");
      dont_shift = TRUE; _front_symbol = SCANsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_ScanInfo")->sub.PointerValue;
}

/* directors of state 326
   Identsym 
 */
front_NameSpace Parse_state_front_NameSpace (void)	/* state 326 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x4, 0x0, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(326);
    switch (_front_symbol) {
    case NameSpace_value:
      n = 1; break; /* accept NameSpace  ->  . Identsym       followers: front_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_24();
        break;
      }
    default:
    /* default item:NameSpace  ->  . Identsym  followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _front_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("front_NameSpace")->sub.PointerValue;
}

/* directors of state 327
   greaterthangreaterthansym lessthanlessthansym percentsym slashsym starsym minussym plussym hatsym verticalbarverticalbarsym ampersandampersandsym ampersandsym greaterthanequalssym lessthanequalssym exclaimequalssym equalsequalssym exclaimsym tildasym 
 */
Ident Parse_state_front_Oper (void)	/* state 327 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x20000000, 0xffff0000, 0x0, 0x0, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(327);
    switch (_front_symbol) {
    case Oper_value:
      n = 1; break; /* accept Oper  ->  . greaterthangreaterthansym   followers: front_EOF  */
    case tildasym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.tildasym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84();
        break;
      }
    case exclaimsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85();
        break;
      }
    case equalsequalssym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.equalsequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86();
        break;
      }
    case exclaimequalssym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.exclaimequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87();
        break;
      }
    case lessthanequalssym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88();
        break;
      }
    case greaterthanequalssym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthanequalssym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89();
        break;
      }
    case ampersandsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90();
        break;
      }
    case ampersandampersandsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.ampersandampersandsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91();
        break;
      }
    case verticalbarverticalbarsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.verticalbarverticalbarsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case hatsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.hatsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_93();
        break;
      }
    case plussym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.plussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94();
        break;
      }
    case minussym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.minussym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_95();
        break;
      }
    case starsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.starsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96();
        break;
      }
    case slashsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.slashsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_97();
        break;
      }
    case percentsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.percentsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_98();
        break;
      }
    case lessthanlessthansym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.lessthanlessthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_99();
        break;
      }
    case greaterthangreaterthansym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,front_lval.greaterthangreaterthansym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Oper  ->  . greaterthangreaterthansym      followers: front_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "greaterthangreaterthansym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _front_symbol = greaterthangreaterthansym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Ident")->sub.PointerValue;
}

/* directors of state 328
   hole_Check IFsym 
 */
List_front_Check Parse_state_front_OPTMORE_Check (void)	/* state 328 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[5] = { 0x0, 0x800, 0x0, 0x10000000, 0x0 };
  Int _followers[5];
  Int followers[5] = { 0x0, 0x0, 0x0, 0x0, 0x200 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 5);
  DELETE_UNTIL (_followers, front);
  _front_symbol = _front_token;
  do {
    REPORT(328);
    switch (_front_symbol) {
    case OPTMORE_Check_value:
      n = 1; break; /* accept OPTMORE_Check  ->  . Check OPTMORE_Check        followers: front_EOF  */
    case IFsym_value:
      {
        static Int my_followers[] = { 0x0, 0x800, 0x0, 0x10000000, 0x100 };
        unite_symbol_sets (_followers, my_followers, followers, 5);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_253(_followers);
        break;
      }
    case hole_Check_value: HOLE_ACTION (0, "Check");
    case Check_value:
      {
        n = Parse_state_260(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Check  ->  .       followers: front_EOF  */
      n = 0; _front_symbol = OPTMORE_Check_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_front_Check);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_front_Check")->sub.PointerValue;
}

