%pointer
%{
#define fe_parser_input grammar_in
#include "grammar.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "grammar_y.h"
#undef YYLMAX
#define YYLMAX		(8*1024-1)

int grammar_state_stack_depth=0;

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

"%grammar"	{
  return hole_grammar;
}

"%_grammar"	{
  return start_grammar;
}

"%Scanner"	{
  return hole_Scanner;
}

"%_Scanner"	{
  return start_Scanner;
}

"%Token"	{
  return hole_Token;
}

"%_Token"	{
  return start_Token;
}

"%RegExpr"	{
  return hole_RegExpr;
}

"%_RegExpr"	{
  return start_RegExpr;
}

"%ChoiceRE"	{
  return hole_ChoiceRE;
}

"%_ChoiceRE"	{
  return start_ChoiceRE;
}

"%SeqRE"	{
  return hole_SeqRE;
}

"%_SeqRE"	{
  return start_SeqRE;
}

"%PostRE"	{
  return hole_PostRE;
}

"%_PostRE"	{
  return start_PostRE;
}

"%BasicRE"	{
  return hole_BasicRE;
}

"%_BasicRE"	{
  return start_BasicRE;
}

"%ScanAction"	{
  return hole_ScanAction;
}

"%_ScanAction"	{
  return start_ScanAction;
}

"%Parser"	{
  return hole_Parser;
}

"%_Parser"	{
  return start_Parser;
}

"%ProdRule"	{
  return hole_ProdRule;
}

"%_ProdRule"	{
  return start_ProdRule;
}

"%OPTMORE_Token"	{
  return hole_OPTMORE_Token;
}

"%_OPTMORE_Token"	{
  return start_OPTMORE_Token;
}

"%OPTMORE_ScanAction_semicolonsym"	{
  return hole_OPTMORE_ScanAction_semicolonsym;
}

"%_OPTMORE_ScanAction_semicolonsym"	{
  return start_OPTMORE_ScanAction_semicolonsym;
}

"%OPT_verticalbarsym_RegExpr"	{
  return hole_OPT_verticalbarsym_RegExpr;
}

"%_OPT_verticalbarsym_RegExpr"	{
  return start_OPT_verticalbarsym_RegExpr;
}

"%OPT_SeqRE"	{
  return hole_OPT_SeqRE;
}

"%_OPT_SeqRE"	{
  return start_OPT_SeqRE;
}

"%OPTMORE_ProdRule"	{
  return hole_OPTMORE_ProdRule;
}

"%_OPTMORE_ProdRule"	{
  return start_OPTMORE_ProdRule;
}

"%Stringsym"	{
  grammar_lval.Stringsym_type = (String)Get_sub_tree();
  return Stringsym;
}

"%Identsym"	{
  grammar_lval.Identsym_type = (Ident)Get_sub_tree();
  return Identsym;
}

"^" {
  record_length (grammar_leng); return hatsym;
}

"$" {
  record_length (grammar_leng); return dollarsym;
}

"{" {
  record_length (grammar_leng); return openchainsym;
}

"}" {
  record_length (grammar_leng); return closechainsym;
}

"(" {
  record_length (grammar_leng); return openparsym;
}

")" {
  record_length (grammar_leng); return closeparsym;
}

"." {
  record_length (grammar_leng); return dotsym;
}

"?" {
  record_length (grammar_leng); return questionmarksym;
}

"+" {
  record_length (grammar_leng); return plussym;
}

"*" {
  record_length (grammar_leng); return starsym;
}

"|" {
  record_length (grammar_leng); return verticalbarsym;
}

";" {
  record_length (grammar_leng); return semicolonsym;
}

"nonterminal" {
  record_length (grammar_leng); return nonterminalsym;
}

"import" {
  record_length (grammar_leng); return importsym;
}

"extra" {
  record_length (grammar_leng); return extrasym;
}

"\""({NOT_DQ_BS_CR}|{Bs}{Esc}|{Bs}{ReChar})*"\"" {
  grammar_lval.Stringsym_type = Encode_String(grammar_text);
  record_length (grammar_leng); return Stringsym;
}

{Non_digit}{Alphanum}* {
  grammar_lval.Identsym_type = Encode_Ident(grammar_text);
  record_length (grammar_leng); return Identsym;
}

^[ \t]*#line.*	{
  record_length (grammar_leng);
  record_symbol (grammar_leng,grammar_text);
  update_line_and_fname(grammar_text);
}

^[ \t]*#{White}.*	{
  record_length (grammar_leng);
  record_symbol (grammar_leng,grammar_text);
  update_line_and_fname(grammar_text);
}

{CReturn}?{Newline}	{
  record_length (grammar_leng);
  record_symbol (grammar_leng,grammar_text);
  new_input_line();
}

{White}+	{
  record_length (grammar_leng);
  record_symbol (grammar_leng,grammar_text);
}

.	{ return NONSENSE; }

%%

int grammar_wrap()
{ return 1; }

void grammar_error(char *s)
{ if (Front_Parse_Error) Front_Parse_Error (s, grammar_text);
}
