%pointer
%{
#define fe_parser_input Types_in
#include "Types.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "Types_y.h"
#undef YYLMAX
#define YYLMAX		(8*1024-1)

int Types_state_stack_depth=0;

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

"%Types"	{
  return hole_Types;
}

"%_Types"	{
  return start_Types;
}

"%includes2"	{
  return hole_includes2;
}

"%_includes2"	{
  return start_includes2;
}

"%EnumType"	{
  return hole_EnumType;
}

"%_EnumType"	{
  return start_EnumType;
}

"%Enums"	{
  return hole_Enums;
}

"%_Enums"	{
  return start_Enums;
}

"%BindType"	{
  return hole_BindType;
}

"%_BindType"	{
  return start_BindType;
}

"%PointerType"	{
  return hole_PointerType;
}

"%_PointerType"	{
  return start_PointerType;
}

"%subtypedef"	{
  return hole_subtypedef;
}

"%_subtypedef"	{
  return start_subtypedef;
}

"%StructType"	{
  return hole_StructType;
}

"%_StructType"	{
  return start_StructType;
}

"%struct_type"	{
  return hole_struct_type;
}

"%_struct_type"	{
  return start_struct_type;
}

"%sub_union"	{
  return hole_sub_union;
}

"%_sub_union"	{
  return start_sub_union;
}

"%macro"	{
  return hole_macro;
}

"%_macro"	{
  return start_macro;
}

"%field"	{
  return hole_field;
}

"%_field"	{
  return start_field;
}

"%TypeName"	{
  return hole_TypeName;
}

"%_TypeName"	{
  return start_TypeName;
}

"%CreateFunction"	{
  return hole_CreateFunction;
}

"%_CreateFunction"	{
  return start_CreateFunction;
}

"%TypeNames"	{
  return hole_TypeNames;
}

"%_TypeNames"	{
  return start_TypeNames;
}

"%OPTMORE_EnumType"	{
  return hole_OPTMORE_EnumType;
}

"%_OPTMORE_EnumType"	{
  return start_OPTMORE_EnumType;
}

"%OPTMORE_PointerType"	{
  return hole_OPTMORE_PointerType;
}

"%_OPTMORE_PointerType"	{
  return start_OPTMORE_PointerType;
}

"%OPTMORE_subtypedef"	{
  return hole_OPTMORE_subtypedef;
}

"%_OPTMORE_subtypedef"	{
  return start_OPTMORE_subtypedef;
}

"%OPTMORE_BindType"	{
  return hole_OPTMORE_BindType;
}

"%_OPTMORE_BindType"	{
  return start_OPTMORE_BindType;
}

"%OPTMORE_StructType"	{
  return hole_OPTMORE_StructType;
}

"%_OPTMORE_StructType"	{
  return start_OPTMORE_StructType;
}

"%OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym"	{
  return hole_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym;
}

"%_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym"	{
  return start_OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym;
}

"%OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym"	{
  return hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym;
}

"%_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym"	{
  return start_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym;
}

"%ALT_TypeName_SEP_commasym_NL"	{
  return hole_ALT_TypeName_SEP_commasym_NL;
}

"%_ALT_TypeName_SEP_commasym_NL"	{
  return start_ALT_TypeName_SEP_commasym_NL;
}

"%OPTMORE_macro"	{
  return hole_OPTMORE_macro;
}

"%_OPTMORE_macro"	{
  return start_OPTMORE_macro;
}

"%OPTMORE_CreateFunction"	{
  return hole_OPTMORE_CreateFunction;
}

"%_OPTMORE_CreateFunction"	{
  return start_OPTMORE_CreateFunction;
}

"%OPT_Identsym__USER_FIELDSsym"	{
  return hole_OPT_Identsym__USER_FIELDSsym;
}

"%_OPT_Identsym__USER_FIELDSsym"	{
  return start_OPT_Identsym__USER_FIELDSsym;
}

"%OPTMORE_field"	{
  return hole_OPTMORE_field;
}

"%_OPTMORE_field"	{
  return start_OPTMORE_field;
}

"%OPT_sub_union"	{
  return hole_OPT_sub_union;
}

"%_OPT_sub_union"	{
  return start_OPT_sub_union;
}

"%OPT_Identsym"	{
  return hole_OPT_Identsym;
}

"%_OPT_Identsym"	{
  return start_OPT_Identsym;
}

"%OPTMORE_struct_type"	{
  return hole_OPTMORE_struct_type;
}

"%_OPTMORE_struct_type"	{
  return start_OPTMORE_struct_type;
}

"%OPTMORE_dotsubdotsym_Identsym"	{
  return hole_OPTMORE_dotsubdotsym_Identsym;
}

"%_OPTMORE_dotsubdotsym_Identsym"	{
  return start_OPTMORE_dotsubdotsym_Identsym;
}

"%ALT_TypeName_SEP__sym"	{
  return hole_ALT_TypeName_SEP__sym;
}

"%_ALT_TypeName_SEP__sym"	{
  return start_ALT_TypeName_SEP__sym;
}

"%Intsym"	{
  Types_lval.Intsym_type = (Int)Get_sub_tree();
  return Intsym;
}

"%Identsym"	{
  Types_lval.Identsym_type = (Ident)Get_sub_tree();
  return Identsym;
}

"#include <stdarg.h>" {
  record_length (Types_leng); return hashincludespacelessthanstdargdothgreaterthansym;
}

"#include <stddef.h>" {
  record_length (Types_leng); return hashincludespacelessthanstddefdothgreaterthansym;
}

"#include <front/basic_types.h>" {
  record_length (Types_leng); return hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym;
}

"typedef" {
  record_length (Types_leng); return typedefsym;
}

"enum" {
  record_length (Types_leng); return enumsym;
}

"{" {
  record_length (Types_leng); return openchainsym;
}

"," {
  record_length (Types_leng); return commasym;
}

"}" {
  record_length (Types_leng); return closechainsym;
}

";" {
  record_length (Types_leng); return semicolonsym;
}

"extern char *" {
  record_length (Types_leng); return externspacecharspacestarsym;
}

"_names[];" {
  record_length (Types_leng); return underscorenamesopenbrkclosebrksemicolonsym;
}

"#define NUM_" {
  record_length (Types_leng); return hashdefinespaceNUMunderscoresym;
}

"#ifndef DEF_TYPE_" {
  record_length (Types_leng); return hashifndefspaceDEFunderscoreTYPEunderscoresym;
}

"#define DEF_TYPE_" {
  record_length (Types_leng); return hashdefinespaceDEFunderscoreTYPEunderscoresym;
}

"typedef struct s_" {
  record_length (Types_leng); return typedefspacestructspacesunderscoresym;
}

"*" {
  record_length (Types_leng); return starsym;
}

"typedef " {
  record_length (Types_leng); return typedefspacesym;
}

"#endif" {
  record_length (Types_leng); return hashendifsym;
}

"#include <front/scan_support.h>" {
  record_length (Types_leng); return hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym;
}

"#include <front/print_support.h>" {
  record_length (Types_leng); return hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym;
}

"#include <front/SymTab.h>" {
  record_length (Types_leng); return hashincludespacelessthanfrontslashSymTabdothgreaterthansym;
}

"#include \"" {
  record_length (Types_leng); return hashincludespacebackslashdoublequotesym;
}

"_parse.h\"" {
  record_length (Types_leng); return underscoreparsedothbackslashdoublequotesym;
}

"_defs.h\"" {
  record_length (Types_leng); return underscoredefsdothbackslashdoublequotesym;
}

".h\"" {
  record_length (Types_leng); return dothbackslashdoublequotesym;
}

"typedef Bind Bind_" {
  record_length (Types_leng); return typedefspaceBindspaceBindunderscoresym;
}

"typedef List_Bind List_Bind_" {
  record_length (Types_leng); return typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym;
}

"#define List_Bind_" {
  record_length (Types_leng); return hashdefinespaceListunderscoreBindunderscoresym;
}

"_data(x)" {
  record_length (Types_leng); return underscoredataopenparxcloseparsym;
}

"(Bind_" {
  record_length (Types_leng); return openparBindunderscoresym;
}

")Front_List_data((Front_List)(x))" {
  record_length (Types_leng); return closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym;
}

"_next(x)" {
  record_length (Types_leng); return underscorenextopenparxcloseparsym;
}

"(List_Bind_" {
  record_length (Types_leng); return openparListunderscoreBindunderscoresym;
}

")Front_List_next((Front_List)(x))" {
  record_length (Types_leng); return closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym;
}

"#define Bind_" {
  record_length (Types_leng); return hashdefinespaceBindunderscoresym;
}

"_kind" {
  record_length (Types_leng); return _kindsym;
}

"extern" {
  record_length (Types_leng); return externsym;
}

"_root;" {
  record_length (Types_leng); return underscorerootsemicolonsym;
}

"#ifndef DEF_STRUCT_" {
  record_length (Types_leng); return hashifndefspaceDEFunderscoreSTRUCTunderscoresym;
}

"#define DEF_STRUCT_" {
  record_length (Types_leng); return hashdefinespaceDEFunderscoreSTRUCTunderscoresym;
}

"struct" {
  record_length (Types_leng); return structsym;
}

"s_" {
  record_length (Types_leng); return s_sym;
}

"_USER_FIELDS" {
  record_length (Types_leng); return _USER_FIELDSsym;
}

"_" {
  record_length (Types_leng); return _sym;
}

"union {" {
  record_length (Types_leng); return unionspaceopenchainsym;
}

"} sub;" {
  record_length (Types_leng); return closechainspacesubsemicolonsym;
}

"#define" {
  record_length (Types_leng); return hashdefinesym;
}

"(_p)" {
  record_length (Types_leng); return openparunderscorepcloseparsym;
}

"(" {
  record_length (Types_leng); return openparsym;
}

"(*_p)" {
  record_length (Types_leng); return openparstarunderscorepcloseparsym;
}

"_USER_ACCESS(_p)" {
  record_length (Types_leng); return underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym;
}

".sub." {
  record_length (Types_leng); return dotsubdotsym;
}

"." {
  record_length (Types_leng); return dotsym;
}

")" {
  record_length (Types_leng); return closeparsym;
}

"CREATE" {
  record_length (Types_leng); return CREATEsym;
}

"#endif /* DEF_STRUCT_" {
  record_length (Types_leng); return hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym;
}

" */" {
  record_length (Types_leng); return spacestarslashsym;
}

{Digit}+ {
  Types_lval.Intsym_type = Encode_Int(Types_text);
  record_length (Types_leng); return Intsym;
}

{Non_digit}{Alphanum}* {
  Types_lval.Identsym_type = Encode_Ident(Types_text);
  record_length (Types_leng); return Identsym;
}

^[ \t]*#line.*	{
  record_length (Types_leng);
  record_symbol (Types_leng,Types_text);
  update_line_and_fname(Types_text);
}

^[ \t]*#{White}.*	{
  record_length (Types_leng);
  record_symbol (Types_leng,Types_text);
  update_line_and_fname(Types_text);
}

{CReturn}?{Newline}	{
  record_length (Types_leng);
  record_symbol (Types_leng,Types_text);
  new_input_line();
}

{White}+	{
  record_length (Types_leng);
  record_symbol (Types_leng,Types_text);
}

.	{ return NONSENSE; }

%%

int Types_wrap()
{ return 1; }

void Types_error(char *s)
{ if (Front_Parse_Error) Front_Parse_Error (s, Types_text);
}
