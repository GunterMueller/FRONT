%pointer
%{
#define fe_parser_input doggy_in
#include "doggy.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "doggy_y.h"
#undef YYLMAX
#define YYLMAX		(8*1024-1)

int doggy_state_stack_depth=0;

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

"TYPES" {
  record_length (doggy_leng); return TYPESsym;
}

"ATTRIBUTES" {
  record_length (doggy_leng); return ATTRIBUTESsym;
}

"{" {
  record_length (doggy_leng); return openchainsym;
}

"OPR" {
  record_length (doggy_leng); return OPRsym;
}

"," {
  record_length (doggy_leng); return commasym;
}

"}" {
  record_length (doggy_leng); return closechainsym;
}

"MACHINE" {
  record_length (doggy_leng); return MACHINEsym;
}

"DESCRIPTION" {
  record_length (doggy_leng); return DESCRIPTIONsym;
}

"(" {
  record_length (doggy_leng); return openparsym;
}

")" {
  record_length (doggy_leng); return closeparsym;
}

"*" {
  record_length (doggy_leng); return starsym;
}

"[" {
  record_length (doggy_leng); return openbrksym;
}

"-" {
  record_length (doggy_leng); return minussym;
}

".." {
  record_length (doggy_leng); return dotdotsym;
}

"STEP" {
  record_length (doggy_leng); return STEPsym;
}

"]" {
  record_length (doggy_leng); return closebrksym;
}

"|" {
  record_length (doggy_leng); return verticalbarsym;
}

":" {
  record_length (doggy_leng); return colonsym;
}

"COMMUTATIVE" {
  record_length (doggy_leng); return COMMUTATIVEsym;
}

"SUPPORTS" {
  record_length (doggy_leng); return SUPPORTSsym;
}

"EXTERNAL" {
  record_length (doggy_leng); return EXTERNALsym;
}

"extern" {
  record_length (doggy_leng); return externsym;
}

";" {
  record_length (doggy_leng); return semicolonsym;
}

"FUNCTIONS" {
  record_length (doggy_leng); return FUNCTIONSsym;
}

"=" {
  record_length (doggy_leng); return equalssym;
}

"ANY" {
  record_length (doggy_leng); return ANYsym;
}

"NULL" {
  record_length (doggy_leng); return NULLsym;
}

"_" {
  record_length (doggy_leng); return _sym;
}

"&&" {
  record_length (doggy_leng); return candsym;
}

"||" {
  record_length (doggy_leng); return corsym;
}

"^" {
  record_length (doggy_leng); return hatsym;
}

"==" {
  record_length (doggy_leng); return eqsym;
}

"!=" {
  record_length (doggy_leng); return neqsym;
}

"<=" {
  record_length (doggy_leng); return lesym;
}

">=" {
  record_length (doggy_leng); return gesym;
}

"<" {
  record_length (doggy_leng); return lessthansym;
}

">" {
  record_length (doggy_leng); return greaterthansym;
}

"<<" {
  record_length (doggy_leng); return shlsym;
}

">>" {
  record_length (doggy_leng); return shrsym;
}

"/" {
  record_length (doggy_leng); return slashsym;
}

"%" {
  record_length (doggy_leng); return percentsym;
}

"&" {
  record_length (doggy_leng); return ampersandsym;
}

"+" {
  record_length (doggy_leng); return plussym;
}

"`" {
  record_length (doggy_leng); return openquotesym;
}

"::" {
  record_length (doggy_leng); return CONSsym;
}

"IF" {
  record_length (doggy_leng); return IFsym;
}

"THEN" {
  record_length (doggy_leng); return THENsym;
}

"ELSIF" {
  record_length (doggy_leng); return ELSIFsym;
}

"ELSE" {
  record_length (doggy_leng); return ELSEsym;
}

"FI" {
  record_length (doggy_leng); return FIsym;
}

"!" {
  record_length (doggy_leng); return exclaimsym;
}

"~" {
  record_length (doggy_leng); return tildasym;
}

"->" {
  record_length (doggy_leng); return arrowsym;
}

"WHERE" {
  record_length (doggy_leng); return WHEREsym;
}

"RULES" {
  record_length (doggy_leng); return RULESsym;
}

"/""*" {
  record_symbol (doggy_leng,doggy_text);  skip_comment ("*/");
}

"/""/" {
  record_symbol (doggy_leng,doggy_text);  skip_comment ("\n");
}

("TRUE"|"FALSE") {
  doggy_lval.Boolsym_type = Encode_Bool(doggy_text);
  record_length (doggy_leng); return Boolsym;
}

({Alphanum})*{Non_digit}({Alphanum})* {
  doggy_lval.Identsym_type = Encode_Ident(doggy_text);
  record_length (doggy_leng); return Identsym;
}

{Digit}+ {
  doggy_lval.Intsym_type = Encode_Int(doggy_text);
  record_length (doggy_leng); return Intsym;
}

{Double_quote}({NOT_DQ_BS_LF}|{Bs}{Esc})*{Double_quote} {
  doggy_lval.Stringsym_type = Encode_String(doggy_text);
  record_length (doggy_leng); return Stringsym;
}

^[ \t]*#line.*	{
  record_length (doggy_leng);
  record_symbol (doggy_leng,doggy_text);
  update_line_and_fname(doggy_text);
}

^[ \t]*#{White}.*	{
  record_length (doggy_leng);
  record_symbol (doggy_leng,doggy_text);
  update_line_and_fname(doggy_text);
}

{CReturn}?{Newline}	{
  record_length (doggy_leng);
  record_symbol (doggy_leng,doggy_text);
  new_input_line();
}

{White}+	{
  record_length (doggy_leng);
  record_symbol (doggy_leng,doggy_text);
}

.	{ return NONSENSE; }

%%

int doggy_wrap()
{ return 1; }

void doggy_error(char *s)
{ if (Front_Parse_Error) Front_Parse_Error (s, doggy_text);
}
