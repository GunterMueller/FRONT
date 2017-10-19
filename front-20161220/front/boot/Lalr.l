%pointer
%{
#define fe_parser_input Lalr_in
#include "Lalr.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "Lalr_y.h"
#undef YYLMAX
#define YYLMAX		(8*1024-1)

int Lalr_state_stack_depth=0;

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

"%Lalr"	{
  return hole_Lalr;
}

"%_Lalr"	{
  return start_Lalr;
}

"%Production"	{
  return hole_Production;
}

"%_Production"	{
  return start_Production;
}

"%ProdRhs"	{
  return hole_ProdRhs;
}

"%_ProdRhs"	{
  return start_ProdRhs;
}

"%LR_Symbol"	{
  return hole_LR_Symbol;
}

"%_LR_Symbol"	{
  return start_LR_Symbol;
}

"%LR_Symbols"	{
  return hole_LR_Symbols;
}

"%_LR_Symbols"	{
  return start_LR_Symbols;
}

"%Emptiness"	{
  return hole_Emptiness;
}

"%_Emptiness"	{
  return start_Emptiness;
}

"%LR_state"	{
  return hole_LR_state;
}

"%_LR_state"	{
  return start_LR_state;
}

"%Item"	{
  return hole_Item;
}

"%_Item"	{
  return start_Item;
}

"%TermSet"	{
  return hole_TermSet;
}

"%_TermSet"	{
  return start_TermSet;
}

"%Transition"	{
  return hole_Transition;
}

"%_Transition"	{
  return start_Transition;
}

"%OPTMORE_Production"	{
  return hole_OPTMORE_Production;
}

"%_OPTMORE_Production"	{
  return start_OPTMORE_Production;
}

"%OPTMORE_LR_state"	{
  return hole_OPTMORE_LR_state;
}

"%_OPTMORE_LR_state"	{
  return start_OPTMORE_LR_state;
}

"%OPT_LR_Symbols"	{
  return hole_OPT_LR_Symbols;
}

"%_OPT_LR_Symbols"	{
  return start_OPT_LR_Symbols;
}

"%OPT_questionmarksym"	{
  return hole_OPT_questionmarksym;
}

"%_OPT_questionmarksym"	{
  return start_OPT_questionmarksym;
}

"%MORE_Item"	{
  return hole_MORE_Item;
}

"%_MORE_Item"	{
  return start_MORE_Item;
}

"%OPTMORE_Transition"	{
  return hole_OPTMORE_Transition;
}

"%_OPTMORE_Transition"	{
  return start_OPTMORE_Transition;
}

"%OPTMORE_LR_Symbol"	{
  return hole_OPTMORE_LR_Symbol;
}

"%_OPTMORE_LR_Symbol"	{
  return start_OPTMORE_LR_Symbol;
}

"%OPT_followerscolonsym_TermSet"	{
  return hole_OPT_followerscolonsym_TermSet;
}

"%_OPT_followerscolonsym_TermSet"	{
  return start_OPT_followerscolonsym_TermSet;
}

"%MORE_Identsym_spacesym"	{
  return hole_MORE_Identsym_spacesym;
}

"%_MORE_Identsym_spacesym"	{
  return start_MORE_Identsym_spacesym;
}

"%Intsym"	{
  Lalr_lval.Intsym_type = (Int)Get_sub_tree();
  return Intsym;
}

"%Identsym"	{
  Lalr_lval.Identsym_type = (Ident)Get_sub_tree();
  return Identsym;
}

"GRAMMAR" {
  record_length (Lalr_leng); return GRAMMARsym;
}

"->" {
  record_length (Lalr_leng); return minusgreaterthansym;
}

"?" {
  record_length (Lalr_leng); return questionmarksym;
}

";" {
  record_length (Lalr_leng); return semicolonsym;
}

"empty:" {
  record_length (Lalr_leng); return emptycolonsym;
}

"NON_EMPTY" {
  record_length (Lalr_leng); return NON_EMPTYsym;
}

"EMPTY" {
  record_length (Lalr_leng); return EMPTYsym;
}

"first:" {
  record_length (Lalr_leng); return firstcolonsym;
}

" " {
  record_length (Lalr_leng); return spacesym;
}

"STATES" {
  record_length (Lalr_leng); return STATESsym;
}

"state" {
  record_length (Lalr_leng); return statesym;
}

"." {
  record_length (Lalr_leng); return dotsym;
}

"followers:" {
  record_length (Lalr_leng); return followerscolonsym;
}

"transitions" {
  record_length (Lalr_leng); return transitionssym;
}

"=>" {
  record_length (Lalr_leng); return equalsgreaterthansym;
}

{Digit}+ {
  Lalr_lval.Intsym_type = Encode_Int(Lalr_text);
  record_length (Lalr_leng); return Intsym;
}

{Non_digit}{Alphanum}* {
  Lalr_lval.Identsym_type = Encode_Ident(Lalr_text);
  record_length (Lalr_leng); return Identsym;
}

^[ \t]*#line.*	{
  record_length (Lalr_leng);
  record_symbol (Lalr_leng,Lalr_text);
  update_line_and_fname(Lalr_text);
}

^[ \t]*#{White}.*	{
  record_length (Lalr_leng);
  record_symbol (Lalr_leng,Lalr_text);
  update_line_and_fname(Lalr_text);
}

{CReturn}?{Newline}	{
  record_length (Lalr_leng);
  record_symbol (Lalr_leng,Lalr_text);
  new_input_line();
}

{White}+	{
  record_length (Lalr_leng);
  record_symbol (Lalr_leng,Lalr_text);
}

.	{ return NONSENSE; }

%%

int Lalr_wrap()
{ return 1; }

void Lalr_error(char *s)
{ if (Front_Parse_Error) Front_Parse_Error (s, Lalr_text);
}
