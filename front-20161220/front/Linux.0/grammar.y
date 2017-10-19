%{
#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "grammar.h"

extern int input_line_nr;

struct yy_buffer_state *grammar_dummy_state (void);
struct yy_buffer_state *grammar_scanner_state (void);
%}

%token NONSENSE
%token hatsym
%token dollarsym
%token openchainsym
%token closechainsym
%token openparsym
%token closeparsym
%token dotsym
%token questionmarksym
%token plussym
%token starsym
%token verticalbarsym
%token semicolonsym
%token nonterminalsym
%token importsym
%token extrasym
%token Stringsym
%token Identsym
%token hole_grammar
%token start_grammar
%token hole_Scanner
%token start_Scanner
%token hole_Token
%token start_Token
%token hole_RegExpr
%token start_RegExpr
%token hole_ChoiceRE
%token start_ChoiceRE
%token hole_SeqRE
%token start_SeqRE
%token hole_PostRE
%token start_PostRE
%token hole_BasicRE
%token start_BasicRE
%token hole_ScanAction
%token start_ScanAction
%token hole_Parser
%token start_Parser
%token hole_ProdRule
%token start_ProdRule
%token hole_OPTMORE_Token
%token start_OPTMORE_Token
%token hole_OPTMORE_ScanAction_semicolonsym
%token start_OPTMORE_ScanAction_semicolonsym
%token hole_OPT_verticalbarsym_RegExpr
%token start_OPT_verticalbarsym_RegExpr
%token hole_OPT_SeqRE
%token start_OPT_SeqRE
%token hole_OPTMORE_ProdRule
%token start_OPTMORE_ProdRule

%union {
String Stringsym_type;
Ident Identsym_type;
grammar_grammar grammar_type;
grammar_Scanner Scanner_type;
grammar_Token Token_type;
grammar_RegExpr RegExpr_type;
grammar_ChoiceRE ChoiceRE_type;
grammar_SeqRE SeqRE_type;
grammar_PostRE PostRE_type;
grammar_BasicRE BasicRE_type;
String ScanAction_type;
grammar_Parser Parser_type;
grammar_ProdRule ProdRule_type;
List_grammar_Token OPTMORE_Token_type;
List_String OPTMORE_ScanAction_semicolonsym_type;
grammar_RegExpr OPT_verticalbarsym_RegExpr_type;
grammar_RegExpr OPT_SeqRE_type;
List_grammar_ProdRule OPTMORE_ProdRule_type;
}

%type <hatsym_type>	hatsym
%type <dollarsym_type>	dollarsym
%type <openchainsym_type>	openchainsym
%type <closechainsym_type>	closechainsym
%type <openparsym_type>	openparsym
%type <closeparsym_type>	closeparsym
%type <dotsym_type>	dotsym
%type <questionmarksym_type>	questionmarksym
%type <plussym_type>	plussym
%type <starsym_type>	starsym
%type <verticalbarsym_type>	verticalbarsym
%type <semicolonsym_type>	semicolonsym
%type <nonterminalsym_type>	nonterminalsym
%type <importsym_type>	importsym
%type <extrasym_type>	extrasym
%type <Stringsym_type>	Stringsym
%type <Identsym_type>	Identsym
%type <grammar_type>	grammar
%type <Scanner_type>	Scanner
%type <Token_type>	Token
%type <RegExpr_type>	RegExpr
%type <ChoiceRE_type>	ChoiceRE
%type <SeqRE_type>	SeqRE
%type <PostRE_type>	PostRE
%type <BasicRE_type>	BasicRE
%type <ScanAction_type>	ScanAction
%type <Parser_type>	Parser
%type <ProdRule_type>	ProdRule
%type <OPTMORE_Token_type>	OPTMORE_Token
%type <OPTMORE_ScanAction_semicolonsym_type>	OPTMORE_ScanAction_semicolonsym
%type <OPT_verticalbarsym_RegExpr_type>	OPT_verticalbarsym_RegExpr
%type <OPT_SeqRE_type>	OPT_SeqRE
%type <OPTMORE_ProdRule_type>	OPTMORE_ProdRule

%start grammar

%%

grammar :
  Scanner
  Parser
  { $$ = Create_grammar_grammar(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
    Decorate_grammar($$);
  }
;

Scanner :
  OPTMORE_Token
  { $$ = Create_grammar_Scanner(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Token :
  RegExpr
  openchainsym
  OPTMORE_ScanAction_semicolonsym
  closechainsym
  { $$ = Create_grammar_Token(make_post_src_info(@1.first_line, @4.last_line), $1, $3);
  }
;

RegExpr :
  ChoiceRE
  {
    $$ = $1;
  }
;

ChoiceRE :
  SeqRE
  OPT_verticalbarsym_RegExpr
  { $$ = Create_grammar_ChoiceRE(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

SeqRE :
  PostRE
  OPT_SeqRE
  { $$ = Create_grammar_SeqRE(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

PostRE :
  BasicRE
  questionmarksym
  { $$ = Create_grammar_OptRE(make_post_src_info(@1.first_line, @2.last_line), $1);
  }
;

PostRE :
  BasicRE
  plussym
  { $$ = Create_grammar_PlusRE(make_post_src_info(@1.first_line, @2.last_line), $1);
  }
;

PostRE :
  BasicRE
  starsym
  { $$ = Create_grammar_TimesRE(make_post_src_info(@1.first_line, @2.last_line), $1);
  }
;

PostRE :
  BasicRE
  {
    $$ = $1;
  }
;

BasicRE :
  Stringsym
  { $$ = Create_grammar_StringRE(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

BasicRE :
  hatsym
  { $$ = Create_grammar_SOLRE(make_post_src_info(@1.first_line, @1.last_line));
  }
;

BasicRE :
  dollarsym
  { $$ = Create_grammar_EOLRE(make_post_src_info(@1.first_line, @1.last_line));
  }
;

BasicRE :
  openchainsym
  Identsym
  closechainsym
  { $$ = Create_grammar_IdRE(make_post_src_info(@1.first_line, @3.last_line), $2);
  }
;

BasicRE :
  openparsym
  RegExpr
  closeparsym
  { $$ = Create_grammar_ParRE(make_post_src_info(@1.first_line, @3.last_line), $2);
  }
;

BasicRE :
  dotsym
  { $$ = Create_grammar_AnyRE(make_post_src_info(@1.first_line, @1.last_line));
  }
;

ScanAction :
  Stringsym
  /* No type */
  {
    $$ = $1;
  }
;

Parser :
  OPTMORE_ProdRule
  { $$ = Create_grammar_Parser(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

ProdRule :
  Identsym
  nonterminalsym
  { $$ = Create_grammar_NT_Rule(make_post_src_info(@1.first_line, @2.last_line), $1);
  }
;

ProdRule :
  Identsym
  importsym
  { $$ = Create_grammar_Import_Rule(make_post_src_info(@1.first_line, @2.last_line), $1);
  }
;

ProdRule :
  Identsym
  extrasym
  { $$ = Create_grammar_Extra_Rule(make_post_src_info(@1.first_line, @2.last_line), $1);
  }
;

/**** Extra rules ****/

OPTMORE_Token :
  {
    $$ = NULL;
  }
;

OPTMORE_Token :
  Token
  OPTMORE_Token
  {
    $$ = Create_List_grammar_Token($1, $2);
  }
;

OPTMORE_ScanAction_semicolonsym :
  {
    $$ = NULL;
  }
;

OPTMORE_ScanAction_semicolonsym :
  ScanAction
  semicolonsym
  OPTMORE_ScanAction_semicolonsym
  {
    $$ = Create_List_String($1, $3);
  }
;

OPT_verticalbarsym_RegExpr :
  {
    $$ = NULL;
  }
;

OPT_verticalbarsym_RegExpr :
  verticalbarsym
  RegExpr
  {
    $$ = $2;
  }
;

OPT_SeqRE :
  {
    $$ = NULL;
  }
;

OPT_SeqRE :
  SeqRE
  {
    $$ = $1;
  }
;

OPTMORE_ProdRule :
  {
    $$ = NULL;
  }
;

OPTMORE_ProdRule :
  ProdRule
  OPTMORE_ProdRule
  {
    $$ = Create_List_grammar_ProdRule($1, $2);
  }
;

grammar :
  hole_grammar
  { $$ = (grammar_grammar)Get_sub_tree (); }
;

grammar :
  start_grammar
  grammar
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

Scanner :
  hole_Scanner
  { $$ = (grammar_Scanner)Get_sub_tree (); }
;

grammar :
  start_Scanner
  Scanner
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

Token :
  hole_Token
  { $$ = (grammar_Token)Get_sub_tree (); }
;

grammar :
  start_Token
  Token
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

RegExpr :
  hole_RegExpr
  { $$ = (grammar_RegExpr)Get_sub_tree (); }
;

grammar :
  start_RegExpr
  RegExpr
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

ChoiceRE :
  hole_ChoiceRE
  { $$ = (grammar_RegExpr)Get_sub_tree (); }
;

grammar :
  start_ChoiceRE
  ChoiceRE
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

SeqRE :
  hole_SeqRE
  { $$ = (grammar_RegExpr)Get_sub_tree (); }
;

grammar :
  start_SeqRE
  SeqRE
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

PostRE :
  hole_PostRE
  { $$ = (grammar_RegExpr)Get_sub_tree (); }
;

grammar :
  start_PostRE
  PostRE
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

BasicRE :
  hole_BasicRE
  { $$ = (grammar_RegExpr)Get_sub_tree (); }
;

grammar :
  start_BasicRE
  BasicRE
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

ScanAction :
  hole_ScanAction
  { $$ = (String)Get_sub_tree (); }
;

grammar :
  start_ScanAction
  ScanAction
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

Parser :
  hole_Parser
  { $$ = (grammar_Parser)Get_sub_tree (); }
;

grammar :
  start_Parser
  Parser
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

ProdRule :
  hole_ProdRule
  { $$ = (grammar_ProdRule)Get_sub_tree (); }
;

grammar :
  start_ProdRule
  ProdRule
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Token :
  hole_OPTMORE_Token
  { $$ = (List_grammar_Token)Get_sub_tree (); }
;

grammar :
  start_OPTMORE_Token
  OPTMORE_Token
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_ScanAction_semicolonsym :
  hole_OPTMORE_ScanAction_semicolonsym
  { $$ = (List_String)Get_sub_tree (); }
;

grammar :
  start_OPTMORE_ScanAction_semicolonsym
  OPTMORE_ScanAction_semicolonsym
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

OPT_verticalbarsym_RegExpr :
  hole_OPT_verticalbarsym_RegExpr
  { $$ = (grammar_RegExpr)Get_sub_tree (); }
;

grammar :
  start_OPT_verticalbarsym_RegExpr
  OPT_verticalbarsym_RegExpr
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

OPT_SeqRE :
  hole_OPT_SeqRE
  { $$ = (grammar_RegExpr)Get_sub_tree (); }
;

grammar :
  start_OPT_SeqRE
  OPT_SeqRE
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_ProdRule :
  hole_OPTMORE_ProdRule
  { $$ = (List_grammar_ProdRule)Get_sub_tree (); }
;

grammar :
  start_OPTMORE_ProdRule
  OPTMORE_ProdRule
  { grammar_multi_action ((void*)$2); YYACCEPT; }
;

