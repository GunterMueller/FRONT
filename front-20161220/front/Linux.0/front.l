%pointer
%{
#define fe_parser_input front_in
#include "front.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "front_y.h"
#undef YYLMAX
#define YYLMAX		(8*1024-1)

int front_state_stack_depth=0;

%}

SOL          ^
EOL          $
Non_digit    [a-zA-Z_]
Alphanum     [a-zA-Z_0-9]
Digit        [0-9]
OctDigit     [0-7]
HexDigit     [0-9a-fA-F]
Sign         [+-]
Quote        [\']
Double_quote [\"]
Bs           [\\]
NOT_DQ_BS_CR [\000-\014\016-!#-\[\]-\177]
NOT_Q_BS_CR  [\000-\014\016-&(-\[\]-\177]
NOT_DQ_BS_LF [\000-\011\013-!#-\[\]-\177]
NOT_Q_BS_LF  [\000-\011\013-&(-\[\]-\177]
Newline      [\n]
CReturn      [\r]
Feed         [\012]
NoFeed       [\000-\011\013-\177]
FormFeed     [\f]
Space        [\t ]
OctNumber    {OctDigit}{OctDigit}?{OctDigit}?
HexNumber    {HexDigit}+
Esc          ([abfnrtv\"\'?\\\n]|{OctNumber}|[xX]{HexNumber})
ReChar       [\.\*\^\$\[\]\+\?\{\}]
White        [\t\f ]
Any          [\000-\177]
HTMLChar     [^<]

%%

"%front"	{
  return hole_front;
}

"%_front"	{
  return start_front;
}

"%Import"	{
  return hole_Import;
}

"%_Import"	{
  return start_Import;
}

"%ImportedNonTerminals"	{
  return hole_ImportedNonTerminals;
}

"%_ImportedNonTerminals"	{
  return start_ImportedNonTerminals;
}

"%ImportedNonTerminal"	{
  return hole_ImportedNonTerminal;
}

"%_ImportedNonTerminal"	{
  return start_ImportedNonTerminal;
}

"%NonTerminals"	{
  return hole_NonTerminals;
}

"%_NonTerminals"	{
  return start_NonTerminals;
}

"%NonTerminal"	{
  return hole_NonTerminal;
}

"%_NonTerminal"	{
  return start_NonTerminal;
}

"%Super"	{
  return hole_Super;
}

"%_Super"	{
  return start_Super;
}

"%Rhs"	{
  return hole_Rhs;
}

"%_Rhs"	{
  return start_Rhs;
}

"%Scoping"	{
  return hole_Scoping;
}

"%_Scoping"	{
  return start_Scoping;
}

"%Alternative"	{
  return hole_Alternative;
}

"%_Alternative"	{
  return start_Alternative;
}

"%Symbol"	{
  return hole_Symbol;
}

"%_Symbol"	{
  return start_Symbol;
}

"%Symbol1"	{
  return hole_Symbol1;
}

"%_Symbol1"	{
  return start_Symbol1;
}

"%AltSymbol"	{
  return hole_AltSymbol;
}

"%_AltSymbol"	{
  return start_AltSymbol;
}

"%SymbolSeq"	{
  return hole_SymbolSeq;
}

"%_SymbolSeq"	{
  return start_SymbolSeq;
}

"%And"	{
  return hole_And;
}

"%_And"	{
  return start_And;
}

"%Or"	{
  return hole_Or;
}

"%_Or"	{
  return start_Or;
}

"%Symbol2"	{
  return hole_Symbol2;
}

"%_Symbol2"	{
  return start_Symbol2;
}

"%SimpleSymbol"	{
  return hole_SimpleSymbol;
}

"%_SimpleSymbol"	{
  return start_SimpleSymbol;
}

"%IdSym"	{
  return hole_IdSym;
}

"%_IdSym"	{
  return start_IdSym;
}

"%OptType"	{
  return hole_OptType;
}

"%_OptType"	{
  return start_OptType;
}

"%DefiningSym"	{
  return hole_DefiningSym;
}

"%_DefiningSym"	{
  return start_DefiningSym;
}

"%ScopeExpr"	{
  return hole_ScopeExpr;
}

"%_ScopeExpr"	{
  return start_ScopeExpr;
}

"%Defining_id"	{
  return hole_Defining_id;
}

"%_Defining_id"	{
  return start_Defining_id;
}

"%Define"	{
  return hole_Define;
}

"%_Define"	{
  return start_Define;
}

"%Field"	{
  return hole_Field;
}

"%_Field"	{
  return start_Field;
}

"%FieldInits"	{
  return hole_FieldInits;
}

"%_FieldInits"	{
  return start_FieldInits;
}

"%FieldInit"	{
  return hole_FieldInit;
}

"%_FieldInit"	{
  return start_FieldInit;
}

"%Type"	{
  return hole_Type;
}

"%_Type"	{
  return start_Type;
}

"%Expr"	{
  return hole_Expr;
}

"%_Expr"	{
  return start_Expr;
}

"%MonExpr1"	{
  return hole_MonExpr1;
}

"%_MonExpr1"	{
  return start_MonExpr1;
}

"%SimpleExpr"	{
  return hole_SimpleExpr;
}

"%_SimpleExpr"	{
  return start_SimpleExpr;
}

"%StringOrKeyword"	{
  return hole_StringOrKeyword;
}

"%_StringOrKeyword"	{
  return start_StringOrKeyword;
}

"%Check"	{
  return hole_Check;
}

"%_Check"	{
  return start_Check;
}

"%NameSpaceList"	{
  return hole_NameSpaceList;
}

"%_NameSpaceList"	{
  return start_NameSpaceList;
}

"%ExprList"	{
  return hole_ExprList;
}

"%_ExprList"	{
  return start_ExprList;
}

"%IdentList"	{
  return hole_IdentList;
}

"%_IdentList"	{
  return start_IdentList;
}

"%TypeList"	{
  return hole_TypeList;
}

"%_TypeList"	{
  return start_TypeList;
}

"%Alternator"	{
  return hole_Alternator;
}

"%_Alternator"	{
  return start_Alternator;
}

"%ScanInfo"	{
  return hole_ScanInfo;
}

"%_ScanInfo"	{
  return start_ScanInfo;
}

"%Defines"	{
  return hole_Defines;
}

"%_Defines"	{
  return start_Defines;
}

"%NameSpace"	{
  return hole_NameSpace;
}

"%_NameSpace"	{
  return start_NameSpace;
}

"%Oper"	{
  return hole_Oper;
}

"%_Oper"	{
  return start_Oper;
}

"%NameOrField"	{
  return hole_NameOrField;
}

"%_NameOrField"	{
  return start_NameOrField;
}

"%OPT_USEsym_IdentList"	{
  return hole_OPT_USEsym_IdentList;
}

"%_OPT_USEsym_IdentList"	{
  return start_OPT_USEsym_IdentList;
}

"%OPT_NAMESPACEsym_NameSpaceList"	{
  return hole_OPT_NAMESPACEsym_NameSpaceList;
}

"%_OPT_NAMESPACEsym_NameSpaceList"	{
  return start_OPT_NAMESPACEsym_NameSpaceList;
}

"%OPTMORE_Import"	{
  return hole_OPTMORE_Import;
}

"%_OPTMORE_Import"	{
  return start_OPTMORE_Import;
}

"%OPT_NonTerminals"	{
  return hole_OPT_NonTerminals;
}

"%_OPT_NonTerminals"	{
  return start_OPT_NonTerminals;
}

"%ALT_ImportedNonTerminal_SEP_commasym"	{
  return hole_ALT_ImportedNonTerminal_SEP_commasym;
}

"%_ALT_ImportedNonTerminal_SEP_commasym"	{
  return start_ALT_ImportedNonTerminal_SEP_commasym;
}

"%OPT_colonsym_Identsym"	{
  return hole_OPT_colonsym_Identsym;
}

"%_OPT_colonsym_Identsym"	{
  return start_OPT_colonsym_Identsym;
}

"%MORE_NonTerminal"	{
  return hole_MORE_NonTerminal;
}

"%_MORE_NonTerminal"	{
  return start_MORE_NonTerminal;
}

"%OPT_ROOTsym"	{
  return hole_OPT_ROOTsym;
}

"%_OPT_ROOTsym"	{
  return start_OPT_ROOTsym;
}

"%OPT_ScanInfo"	{
  return hole_OPT_ScanInfo;
}

"%_OPT_ScanInfo"	{
  return start_OPT_ScanInfo;
}

"%OPT_Super"	{
  return hole_OPT_Super;
}

"%_OPT_Super"	{
  return start_OPT_Super;
}

"%OPT_MEMOsym"	{
  return hole_OPT_MEMOsym;
}

"%_OPT_MEMOsym"	{
  return start_OPT_MEMOsym;
}

"%OPT_ENUMsym"	{
  return hole_OPT_ENUMsym;
}

"%_OPT_ENUMsym"	{
  return start_OPT_ENUMsym;
}

"%OPT_SKIPsym"	{
  return hole_OPT_SKIPsym;
}

"%_OPT_SKIPsym"	{
  return start_OPT_SKIPsym;
}

"%OPTMORE_Scoping"	{
  return hole_OPTMORE_Scoping;
}

"%_OPTMORE_Scoping"	{
  return start_OPTMORE_Scoping;
}

"%OPT_CHECKSsym_OPTMORE_Check"	{
  return hole_OPT_CHECKSsym_OPTMORE_Check;
}

"%_OPT_CHECKSsym_OPTMORE_Check"	{
  return start_OPT_CHECKSsym_OPTMORE_Check;
}

"%OPTMORE_Check"	{
  return hole_OPTMORE_Check;
}

"%_OPTMORE_Check"	{
  return start_OPTMORE_Check;
}

"%MORE_Symbol"	{
  return hole_MORE_Symbol;
}

"%_MORE_Symbol"	{
  return start_MORE_Symbol;
}

"%OPT_ScopeExpr"	{
  return hole_OPT_ScopeExpr;
}

"%_OPT_ScopeExpr"	{
  return start_OPT_ScopeExpr;
}

"%OPT_WARNINGsym"	{
  return hole_OPT_WARNINGsym;
}

"%_OPT_WARNINGsym"	{
  return start_OPT_WARNINGsym;
}

"%OPT_NAMEsym_Identsym"	{
  return hole_OPT_NAMEsym_Identsym;
}

"%_OPT_NAMEsym_Identsym"	{
  return start_OPT_NAMEsym_Identsym;
}

"%OPT_exclaimsym"	{
  return hole_OPT_exclaimsym;
}

"%_OPT_exclaimsym"	{
  return start_OPT_exclaimsym;
}

"%OPT_TYPEsym_Type"	{
  return hole_OPT_TYPEsym_Type;
}

"%_OPT_TYPEsym_Type"	{
  return start_OPT_TYPEsym_Type;
}

"%OPT_FORWARDsym"	{
  return hole_OPT_FORWARDsym;
}

"%_OPT_FORWARDsym"	{
  return start_OPT_FORWARDsym;
}

"%OPT_NAMESPACEsym_Identsym"	{
  return hole_OPT_NAMESPACEsym_Identsym;
}

"%_OPT_NAMESPACEsym_Identsym"	{
  return start_OPT_NAMESPACEsym_Identsym;
}

"%OPT_TRAVERSEsym"	{
  return hole_OPT_TRAVERSEsym;
}

"%_OPT_TRAVERSEsym"	{
  return start_OPT_TRAVERSEsym;
}

"%OPT_CLEARsym"	{
  return hole_OPT_CLEARsym;
}

"%_OPT_CLEARsym"	{
  return start_OPT_CLEARsym;
}

"%OPT_DONT_CLEARsym"	{
  return hole_OPT_DONT_CLEARsym;
}

"%_OPT_DONT_CLEARsym"	{
  return start_OPT_DONT_CLEARsym;
}

"%ALT_FieldInit_SEP_commasym"	{
  return hole_ALT_FieldInit_SEP_commasym;
}

"%_ALT_FieldInit_SEP_commasym"	{
  return start_ALT_FieldInit_SEP_commasym;
}

"%OPT_CREATEsym"	{
  return hole_OPT_CREATEsym;
}

"%_OPT_CREATEsym"	{
  return start_OPT_CREATEsym;
}

"%OPT_openparsym_TypeList_closeparsym"	{
  return hole_OPT_openparsym_TypeList_closeparsym;
}

"%_OPT_openparsym_TypeList_closeparsym"	{
  return start_OPT_openparsym_TypeList_closeparsym;
}

"%OPTMORE_Oper"	{
  return hole_OPTMORE_Oper;
}

"%_OPTMORE_Oper"	{
  return start_OPTMORE_Oper;
}

"%OPT_ExprList"	{
  return hole_OPT_ExprList;
}

"%_OPT_ExprList"	{
  return start_OPT_ExprList;
}

"%MORE_MonExpr1"	{
  return hole_MORE_MonExpr1;
}

"%_MORE_MonExpr1"	{
  return start_MORE_MonExpr1;
}

"%ALT_NameSpace_SEP_commasym_SP"	{
  return hole_ALT_NameSpace_SEP_commasym_SP;
}

"%_ALT_NameSpace_SEP_commasym_SP"	{
  return start_ALT_NameSpace_SEP_commasym_SP;
}

"%ALT_Expr_SEP_commasym_SP"	{
  return hole_ALT_Expr_SEP_commasym_SP;
}

"%_ALT_Expr_SEP_commasym_SP"	{
  return start_ALT_Expr_SEP_commasym_SP;
}

"%ALT_Identsym_SEP_commasym_SP"	{
  return hole_ALT_Identsym_SEP_commasym_SP;
}

"%_ALT_Identsym_SEP_commasym_SP"	{
  return start_ALT_Identsym_SEP_commasym_SP;
}

"%ALT_Type_SEP_commasym_SP"	{
  return hole_ALT_Type_SEP_commasym_SP;
}

"%_ALT_Type_SEP_commasym_SP"	{
  return start_ALT_Type_SEP_commasym_SP;
}

"%OPT_COMMENTsym"	{
  return hole_OPT_COMMENTsym;
}

"%_OPT_COMMENTsym"	{
  return start_OPT_COMMENTsym;
}

"%Boolsym"	{
  front_lval.Boolsym_type = (Bool)Get_sub_tree();
  return Boolsym;
}

"%Identsym"	{
  front_lval.Identsym_type = (Ident)Get_sub_tree();
  return Identsym;
}

"%Intsym"	{
  front_lval.Intsym_type = (Int)Get_sub_tree();
  return Intsym;
}

"%Keywordsym"	{
  front_lval.Keywordsym_type = (String)Get_sub_tree();
  return Keywordsym;
}

"%Charsym"	{
  front_lval.Charsym_type = (String)Get_sub_tree();
  return Charsym;
}

"%Stringsym"	{
  front_lval.Stringsym_type = (String)Get_sub_tree();
  return Stringsym;
}

"USE" {
  record_length (front_leng); return USEsym;
}

"," {
  record_length (front_leng); return commasym;
}

"NAMESPACE" {
  record_length (front_leng); return NAMESPACEsym;
}

"FROM" {
  record_length (front_leng); return FROMsym;
}

":" {
  record_length (front_leng); return colonsym;
}

"ROOT" {
  record_length (front_leng); return ROOTsym;
}

"SCAN" {
  record_length (front_leng); return SCANsym;
}

"TYPE" {
  record_length (front_leng); return TYPEsym;
}

"(" {
  record_length (front_leng); return openparsym;
}

")" {
  record_length (front_leng); return closeparsym;
}

"COMMENT" {
  record_length (front_leng); return COMMENTsym;
}

"<" {
  front_lval.lessthansym_type = Encode_Ident(front_text);
  record_length (front_leng); return lessthansym;
}

"MEMO" {
  record_length (front_leng); return MEMOsym;
}

"ENUM" {
  record_length (front_leng); return ENUMsym;
}

"SKIP" {
  record_length (front_leng); return SKIPsym;
}

"::=" {
  front_lval.definessym_type = Encode_Ident(front_text);
  record_length (front_leng); return definessym;
}

"=" {
  front_lval.equalssym_type = Encode_Ident(front_text);
  record_length (front_leng); return equalssym;
}

"SCOPE" {
  record_length (front_leng); return SCOPEsym;
}

"OPENSCOPE" {
  record_length (front_leng); return OPENSCOPEsym;
}

"CLOSESCOPE" {
  record_length (front_leng); return CLOSESCOPEsym;
}

"FORWARD" {
  record_length (front_leng); return FORWARDsym;
}

"DEFINING" {
  record_length (front_leng); return DEFININGsym;
}

"REDEFINING" {
  record_length (front_leng); return REDEFININGsym;
}

"OVERLOADING" {
  record_length (front_leng); return OVERLOADINGsym;
}

"~" {
  front_lval.tildasym_type = Encode_Ident(front_text);
  record_length (front_leng); return tildasym;
}

"!" {
  front_lval.exclaimsym_type = Encode_Ident(front_text);
  record_length (front_leng); return exclaimsym;
}

"==" {
  front_lval.equalsequalssym_type = Encode_Ident(front_text);
  record_length (front_leng); return equalsequalssym;
}

"!=" {
  front_lval.exclaimequalssym_type = Encode_Ident(front_text);
  record_length (front_leng); return exclaimequalssym;
}

"<=" {
  front_lval.lessthanequalssym_type = Encode_Ident(front_text);
  record_length (front_leng); return lessthanequalssym;
}

">=" {
  front_lval.greaterthanequalssym_type = Encode_Ident(front_text);
  record_length (front_leng); return greaterthanequalssym;
}

"&" {
  front_lval.ampersandsym_type = Encode_Ident(front_text);
  record_length (front_leng); return ampersandsym;
}

"&&" {
  front_lval.ampersandampersandsym_type = Encode_Ident(front_text);
  record_length (front_leng); return ampersandampersandsym;
}

"||" {
  front_lval.verticalbarverticalbarsym_type = Encode_Ident(front_text);
  record_length (front_leng); return verticalbarverticalbarsym;
}

"^" {
  front_lval.hatsym_type = Encode_Ident(front_text);
  record_length (front_leng); return hatsym;
}

"+" {
  front_lval.plussym_type = Encode_Ident(front_text);
  record_length (front_leng); return plussym;
}

"-" {
  front_lval.minussym_type = Encode_Ident(front_text);
  record_length (front_leng); return minussym;
}

"*" {
  front_lval.starsym_type = Encode_Ident(front_text);
  record_length (front_leng); return starsym;
}

"/" {
  front_lval.slashsym_type = Encode_Ident(front_text);
  record_length (front_leng); return slashsym;
}

"%" {
  front_lval.percentsym_type = Encode_Ident(front_text);
  record_length (front_leng); return percentsym;
}

"<<" {
  front_lval.lessthanlessthansym_type = Encode_Ident(front_text);
  record_length (front_leng); return lessthanlessthansym;
}

">>" {
  front_lval.greaterthangreaterthansym_type = Encode_Ident(front_text);
  record_length (front_leng); return greaterthangreaterthansym;
}

"." {
  record_length (front_leng); return dotsym;
}

"NULL" {
  record_length (front_leng); return NULLsym;
}

"APPLIED" {
  record_length (front_leng); return APPLIEDsym;
}

"NAME" {
  record_length (front_leng); return NAMEsym;
}

"FIELD" {
  record_length (front_leng); return FIELDsym;
}

"WARNING" {
  record_length (front_leng); return WARNINGsym;
}

"((" {
  record_length (front_leng); return open2symsym;
}

"|" {
  record_length (front_leng); return verticalbarsym;
}

"|<" {
  record_length (front_leng); return LeftOrsym;
}

"|>" {
  record_length (front_leng); return RightOrsym;
}

"\\|" {
  record_length (front_leng); return Xorsym;
}

"[" {
  record_length (front_leng); return openbrksym;
}

"]" {
  record_length (front_leng); return closebrksym;
}

"{" {
  record_length (front_leng); return openchainsym;
}

"}" {
  record_length (front_leng); return closechainsym;
}

"EMPTY" {
  record_length (front_leng); return EMPTYsym;
}

"\\" {
  record_length (front_leng); return backslashbackslashsym;
}

"LAYOUT" {
  record_length (front_leng); return LAYOUTsym;
}

"COMPARE" {
  record_length (front_leng); return COMPAREsym;
}

"CREATE" {
  record_length (front_leng); return CREATEsym;
}

"CHECKS" {
  record_length (front_leng); return CHECKSsym;
}

"TRAVERSE" {
  record_length (front_leng); return TRAVERSEsym;
}

"CLEAR" {
  record_length (front_leng); return CLEARsym;
}

"DONT_CLEAR" {
  record_length (front_leng); return DONT_CLEARsym;
}

"\\ " {
  record_length (front_leng); return Newlinesym;
}

"\\<" {
  record_length (front_leng); return LeftAndsym;
}

"\\>" {
  record_length (front_leng); return RightAndsym;
}

"\\\\" {
  record_length (front_leng); return alternate_leftsym;
}

"//" {
  record_length (front_leng); return alternate_rightsym;
}

">" {
  front_lval.greaterthansym_type = Encode_Ident(front_text);
  record_length (front_leng); return greaterthansym;
}

"IF" {
  record_length (front_leng); return IFsym;
}

"THEN" {
  record_length (front_leng); return THENsym;
}

";" {
  record_length (front_leng); return semicolonsym;
}

"/""*" {
  record_symbol (front_leng,front_text);  skip_comment ("*/");
}

"(""*" {
  record_symbol (front_leng,front_text);  skip_comment ("*)");
}

"%""%" {
  record_symbol (front_leng,front_text);  skip_comment ("\n");
}

("FALSE"|"TRUE") {
  front_lval.Boolsym_type = Encode_Bool(front_text);
  record_length (front_leng); return Boolsym;
}

({Non_digit}|"$")({Alphanum})* {
  front_lval.Identsym_type = Encode_Ident(front_text);
  record_length (front_leng); return Identsym;
}

({Digit})+ {
  front_lval.Intsym_type = Encode_Int(front_text);
  record_length (front_leng); return Intsym;
}

({Double_quote}{Non_digit}({Alphanum})*{Double_quote}|{Quote}{Non_digit}({Alphanum})*{Quote}) {
  front_lval.Keywordsym_type = Encode_String(front_text);
  record_length (front_leng); return Keywordsym;
}

("\'"{Any}"\'"|"\""{Any}"\"") {
  front_lval.Charsym_type = Encode_String(front_text);
  record_length (front_leng); return Charsym;
}

"\""({NOT_DQ_BS_CR}|{Bs}{Esc}|{Bs}{ReChar})*"\"" {
  front_lval.Stringsym_type = Encode_String(front_text);
  record_length (front_leng); return Stringsym;
}

^[ \t]*#line.*	{
  record_length (front_leng);
  record_symbol (front_leng,front_text);
  update_line_and_fname(front_text);
}

^[ \t]*#{White}.*	{
  record_length (front_leng);
  record_symbol (front_leng,front_text);
  update_line_and_fname(front_text);
}

{CReturn}?{Newline}	{
  record_length (front_leng);
  record_symbol (front_leng,front_text);
  new_input_line();
}

{White}+	{
  record_length (front_leng);
  record_symbol (front_leng,front_text);
}

.	{ return NONSENSE; }

%%

int front_wrap()
{ return 1; }

void front_error(char *s)
{ if (Front_Parse_Error) Front_Parse_Error (s, front_text);
}
