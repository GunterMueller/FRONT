%pointer
%{
#include "Diagrams.h"
#include "support.h"
#include "scan_support.h"
#include "parse_support.h"
#include "Diagrams_y.h"
#undef YYLMAX
#define YYLMAX		(8*1024-1)
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

%%

"%Diagrams"	{
  return hole_Diagrams;
}

"%_Diagrams"	{
  return start_Diagrams;
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
  Diagrams_lval.Boolsym_type = (Bool)Get_sub_tree();
  return Boolsym;
}

"%Intsym"	{
  Diagrams_lval.Intsym_type = (Int)Get_sub_tree();
  return Intsym;
}

"%Stringsym"	{
  Diagrams_lval.Stringsym_type = (String)Get_sub_tree();
  return Stringsym;
}

"%Identsym"	{
  Diagrams_lval.Identsym_type = (Ident)Get_sub_tree();
  return Identsym;
}

"rectangle" {
  record_length (Diagrams_leng); return rectanglesym;
}

"arctopop" {
  record_length (Diagrams_leng); return arctopopsym;
}

"line" {
  record_length (Diagrams_leng); return linesym;
}

"triangle" {
  record_length (Diagrams_leng); return trianglesym;
}

"eofill" {
  record_length (Diagrams_leng); return eofillsym;
}

"L" {
  record_length (Diagrams_leng); return Lsym;
}

"R" {
  record_length (Diagrams_leng); return Rsym;
}

"U" {
  record_length (Diagrams_leng); return Usym;
}

"D" {
  record_length (Diagrams_leng); return Dsym;
}

"C" {
  record_length (Diagrams_leng); return Csym;
}

"(" {
  record_length (Diagrams_leng); return openparsym;
}

")" {
  record_length (Diagrams_leng); return closeparsym;
}

"OR " {
  record_length (Diagrams_leng); return ORspacesym;
}

"ENDOR" {
  record_length (Diagrams_leng); return ENDORsym;
}

"AND " {
  record_length (Diagrams_leng); return ANDspacesym;
}

"ENDAND" {
  record_length (Diagrams_leng); return ENDANDsym;
}

"ALT " {
  record_length (Diagrams_leng); return ALTspacesym;
}

"ENDALT" {
  record_length (Diagrams_leng); return ENDALTsym;
}

"FALSE"|"TRUE" {
  Diagrams_lval.Boolsym_type = Encode_Bool(Diagrams_text);
  record_length (Diagrams_leng); return Boolsym;
}

{Digit}+ {
  Diagrams_lval.Intsym_type = Encode_Int(Diagrams_text);
  record_length (Diagrams_leng); return Intsym;
}

{Double_quote}({NOT_DQ_BS_CR}|{Bs}{Esc})*{Double_quote} {
  Diagrams_lval.Stringsym_type = Encode_String(Diagrams_text);
  record_length (Diagrams_leng); return Stringsym;
}

{Non_digit}{Alphanum}* {
  Diagrams_lval.Identsym_type = Encode_Ident(Diagrams_text);
  record_length (Diagrams_leng); return Identsym;
}

^#line.*	{
  record_length (Diagrams_leng);
  record_symbol (Diagrams_leng,Diagrams_text);
  update_line_and_fname(Diagrams_text);
}

^#{White}.*	{
  record_length (Diagrams_leng);
  record_symbol (Diagrams_leng,Diagrams_text);
  update_line_and_fname(Diagrams_text);
}

{CReturn}?{Newline}	{
  record_length (Diagrams_leng);
  record_symbol (Diagrams_leng,Diagrams_text);
  new_input_line();
}

{White}+	{
  record_length (Diagrams_leng);
  record_symbol (Diagrams_leng,Diagrams_text);
}

.	{ return NONSENSE; }

%%

int Diagrams_wrap()
{ return 1; }

EXTERN void Diagrams_error(char *s)
{ InputError (SCAN_POSITION, TRUE, "%s", s);
  exit (1);
}
