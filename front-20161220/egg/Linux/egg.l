%pointer
%{
#define fe_parser_input egg_in
#include "egg.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "egg_y.h"
#undef YYLMAX
#define YYLMAX		(8*1024-1)

int egg_state_stack_depth=0;

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

"%egg"	{
  return hole_egg;
}

"%_egg"	{
  return start_egg;
}

"%Uses"	{
  return hole_Uses;
}

"%_Uses"	{
  return start_Uses;
}

"%Strings"	{
  return hole_Strings;
}

"%_Strings"	{
  return start_Strings;
}

"%Declarations"	{
  return hole_Declarations;
}

"%_Declarations"	{
  return start_Declarations;
}

"%Declaration"	{
  return hole_Declaration;
}

"%_Declaration"	{
  return start_Declaration;
}

"%Expression"	{
  return hole_Expression;
}

"%_Expression"	{
  return start_Expression;
}

"%Params"	{
  return hole_Params;
}

"%_Params"	{
  return start_Params;
}

"%Statements"	{
  return hole_Statements;
}

"%_Statements"	{
  return start_Statements;
}

"%Statement"	{
  return hole_Statement;
}

"%_Statement"	{
  return start_Statement;
}

"%MessageKind"	{
  return hole_MessageKind;
}

"%_MessageKind"	{
  return start_MessageKind;
}

"%Message"	{
  return hole_Message;
}

"%_Message"	{
  return start_Message;
}

"%SubMessages"	{
  return hole_SubMessages;
}

"%_SubMessages"	{
  return start_SubMessages;
}

"%SubMessage"	{
  return hole_SubMessage;
}

"%_SubMessage"	{
  return start_SubMessage;
}

"%Group"	{
  return hole_Group;
}

"%_Group"	{
  return start_Group;
}

"%OPTMORE_Group"	{
  return hole_OPTMORE_Group;
}

"%_OPTMORE_Group"	{
  return start_OPTMORE_Group;
}

"%ALT_Stringsym_SEP_commasym"	{
  return hole_ALT_Stringsym_SEP_commasym;
}

"%_ALT_Stringsym_SEP_commasym"	{
  return start_ALT_Stringsym_SEP_commasym;
}

"%OPTMORE_Declaration"	{
  return hole_OPTMORE_Declaration;
}

"%_OPTMORE_Declaration"	{
  return start_OPTMORE_Declaration;
}

"%MORE_Expression"	{
  return hole_MORE_Expression;
}

"%_MORE_Expression"	{
  return start_MORE_Expression;
}

"%ALT_Expression_SEP_commasym"	{
  return hole_ALT_Expression_SEP_commasym;
}

"%_ALT_Expression_SEP_commasym"	{
  return start_ALT_Expression_SEP_commasym;
}

"%OPTMORE_Statement"	{
  return hole_OPTMORE_Statement;
}

"%_OPTMORE_Statement"	{
  return start_OPTMORE_Statement;
}

"%OPT_fatalsym"	{
  return hole_OPT_fatalsym;
}

"%_OPT_fatalsym"	{
  return start_OPT_fatalsym;
}

"%ALT_SubMessage_SEP_commasym"	{
  return hole_ALT_SubMessage_SEP_commasym;
}

"%_ALT_SubMessage_SEP_commasym"	{
  return start_ALT_SubMessage_SEP_commasym;
}

"%OPT_openparsym_Identsym_closeparsym"	{
  return hole_OPT_openparsym_Identsym_closeparsym;
}

"%_OPT_openparsym_Identsym_closeparsym"	{
  return start_OPT_openparsym_Identsym_closeparsym;
}

"%OPT_groupsym"	{
  return hole_OPT_groupsym;
}

"%_OPT_groupsym"	{
  return start_OPT_groupsym;
}

"%Stringsym"	{
  egg_lval.Stringsym_type = (String)Get_sub_tree();
  return Stringsym;
}

"%Identsym"	{
  egg_lval.Identsym_type = (Ident)Get_sub_tree();
  return Identsym;
}

"uses" {
  record_length (egg_leng); return usessym;
}

"," {
  record_length (egg_leng); return commasym;
}

";" {
  record_length (egg_leng); return semicolonsym;
}

"fatal" {
  record_length (egg_leng); return fatalsym;
}

"error" {
  record_length (egg_leng); return errorsym;
}

"warning" {
  record_length (egg_leng); return warningsym;
}

"disabled" {
  record_length (egg_leng); return disabledsym;
}

"key" {
  record_length (egg_leng); return keysym;
}

"post" {
  record_length (egg_leng); return postsym;
}

"(" {
  record_length (egg_leng); return openparsym;
}

")" {
  record_length (egg_leng); return closeparsym;
}

"group" {
  record_length (egg_leng); return groupsym;
}

"{" {
  record_length (egg_leng); return openchainsym;
}

"=" {
  record_length (egg_leng); return equalssym;
}

"}" {
  record_length (egg_leng); return closechainsym;
}

"/""*" {
  record_symbol (egg_leng,egg_text);  skip_comment ("*/");
}

{Double_quote}({NOT_DQ_BS_LF}|{Bs}{Esc})*{Double_quote} {
  egg_lval.Stringsym_type = Encode_String(egg_text);
  record_length (egg_leng); return Stringsym;
}

{Non_digit}{Alphanum}* {
  egg_lval.Identsym_type = Encode_Ident(egg_text);
  record_length (egg_leng); return Identsym;
}

^[ \t]*#line.*	{
  record_length (egg_leng);
  record_symbol (egg_leng,egg_text);
  update_line_and_fname(egg_text);
}

^[ \t]*#{White}.*	{
  record_length (egg_leng);
  record_symbol (egg_leng,egg_text);
  update_line_and_fname(egg_text);
}

{CReturn}?{Newline}	{
  record_length (egg_leng);
  record_symbol (egg_leng,egg_text);
  new_input_line();
}

{White}+	{
  record_length (egg_leng);
  record_symbol (egg_leng,egg_text);
}

.	{ return NONSENSE; }

%%

int egg_wrap()
{ return 1; }

void egg_error(char *s)
{ if (Front_Parse_Error) Front_Parse_Error (s, egg_text);
}
