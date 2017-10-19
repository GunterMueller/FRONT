%pointer
%{
#define fe_parser_input Pictures_in
#include "Pictures.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "Pictures_y.h"
#undef YYLMAX
#define YYLMAX		(8*1024-1)

int Pictures_state_stack_depth=0;

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

"%Pictures"	{
  return hole_Pictures;
}

"%_Pictures"	{
  return start_Pictures;
}

"%Direction"	{
  return hole_Direction;
}

"%_Direction"	{
  return start_Direction;
}

"%Picture"	{
  return hole_Picture;
}

"%_Picture"	{
  return start_Picture;
}

"%OPTMORE_Picture"	{
  return hole_OPTMORE_Picture;
}

"%_OPTMORE_Picture"	{
  return start_OPTMORE_Picture;
}

"%MORE_Picture"	{
  return hole_MORE_Picture;
}

"%_MORE_Picture"	{
  return start_MORE_Picture;
}

"%Boolsym"	{
  Pictures_lval.Boolsym_type = (Bool)Get_sub_tree();
  return Boolsym;
}

"%Stringsym"	{
  Pictures_lval.Stringsym_type = (String)Get_sub_tree();
  return Stringsym;
}

"%Identsym"	{
  Pictures_lval.Identsym_type = (Ident)Get_sub_tree();
  return Identsym;
}

"rectangle" {
  record_length (Pictures_leng); return rectanglesym;
}

"circle" {
  record_length (Pictures_leng); return circlesym;
}

"arc" {
  record_length (Pictures_leng); return arcsym;
}

"arctopop" {
  record_length (Pictures_leng); return arctopopsym;
}

"line" {
  record_length (Pictures_leng); return linesym;
}

"triangle" {
  record_length (Pictures_leng); return trianglesym;
}

"eofill" {
  record_length (Pictures_leng); return eofillsym;
}

"L" {
  record_length (Pictures_leng); return Lsym;
}

"R" {
  record_length (Pictures_leng); return Rsym;
}

"U" {
  record_length (Pictures_leng); return Usym;
}

"D" {
  record_length (Pictures_leng); return Dsym;
}

"C" {
  record_length (Pictures_leng); return Csym;
}

"(" {
  record_length (Pictures_leng); return openparsym;
}

")" {
  record_length (Pictures_leng); return closeparsym;
}

"OR " {
  record_length (Pictures_leng); return ORspacesym;
}

"ENDOR" {
  record_length (Pictures_leng); return ENDORsym;
}

"AND " {
  record_length (Pictures_leng); return ANDspacesym;
}

"ENDAND" {
  record_length (Pictures_leng); return ENDANDsym;
}

"ALT " {
  record_length (Pictures_leng); return ALTspacesym;
}

"ENDALT" {
  record_length (Pictures_leng); return ENDALTsym;
}

"FALSE"|"TRUE" {
  Pictures_lval.Boolsym_type = Encode_Bool(Pictures_text);
  record_length (Pictures_leng); return Boolsym;
}

{Digit}+"\."{Digit}* {
  Pictures_lval.Floatsym_type = Encode_Float(Pictures_text);
  record_length (Pictures_leng); return Floatsym;
}

{Double_quote}({NOT_DQ_BS_LF}|{Bs}{Esc})*{Double_quote} {
  Pictures_lval.Stringsym_type = Encode_String(Pictures_text);
  record_length (Pictures_leng); return Stringsym;
}

{Non_digit}{Alphanum}* {
  Pictures_lval.Identsym_type = Encode_Ident(Pictures_text);
  record_length (Pictures_leng); return Identsym;
}

^[ \t]*#line.*	{
  record_length (Pictures_leng);
  record_symbol (Pictures_leng,Pictures_text);
  update_line_and_fname(Pictures_text);
}

^[ \t]*#{White}.*	{
  record_length (Pictures_leng);
  record_symbol (Pictures_leng,Pictures_text);
  update_line_and_fname(Pictures_text);
}

{CReturn}?{Newline}	{
  record_length (Pictures_leng);
  record_symbol (Pictures_leng,Pictures_text);
  new_input_line();
}

{White}+	{
  record_length (Pictures_leng);
  record_symbol (Pictures_leng,Pictures_text);
}

.	{ return NONSENSE; }

%%

int Pictures_wrap()
{ return 1; }

void Pictures_error(char *s)
{ if (Front_Parse_Error) Front_Parse_Error (s, Pictures_text);
}
