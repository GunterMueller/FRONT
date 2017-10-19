%{
#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "egg.h"

extern int input_line_nr;

struct yy_buffer_state *egg_dummy_state (void);
struct yy_buffer_state *egg_scanner_state (void);
%}

%token NONSENSE
%token usessym
%token commasym
%token semicolonsym
%token fatalsym
%token errorsym
%token warningsym
%token disabledsym
%token keysym
%token postsym
%token openparsym
%token closeparsym
%token groupsym
%token openchainsym
%token equalssym
%token closechainsym
%token commentsym
%token Stringsym
%token Identsym
%token hole_egg
%token start_egg
%token hole_Uses
%token start_Uses
%token hole_Strings
%token start_Strings
%token hole_Declarations
%token start_Declarations
%token hole_Declaration
%token start_Declaration
%token hole_Expression
%token start_Expression
%token hole_Params
%token start_Params
%token hole_Statements
%token start_Statements
%token hole_Statement
%token start_Statement
%token hole_MessageKind
%token start_MessageKind
%token hole_Message
%token start_Message
%token hole_SubMessages
%token start_SubMessages
%token hole_SubMessage
%token start_SubMessage
%token hole_Group
%token start_Group
%token hole_OPTMORE_Group
%token start_OPTMORE_Group
%token hole_ALT_Stringsym_SEP_commasym
%token start_ALT_Stringsym_SEP_commasym
%token hole_OPTMORE_Declaration
%token start_OPTMORE_Declaration
%token hole_MORE_Expression
%token start_MORE_Expression
%token hole_ALT_Expression_SEP_commasym
%token start_ALT_Expression_SEP_commasym
%token hole_OPTMORE_Statement
%token start_OPTMORE_Statement
%token hole_OPT_fatalsym
%token start_OPT_fatalsym
%token hole_ALT_SubMessage_SEP_commasym
%token start_ALT_SubMessage_SEP_commasym
%token hole_OPT_openparsym_Identsym_closeparsym
%token start_OPT_openparsym_Identsym_closeparsym
%token hole_OPT_groupsym
%token start_OPT_groupsym

%union {
String Stringsym_type;
Ident Identsym_type;
egg_egg egg_type;
egg_Uses Uses_type;
List_String Strings_type;
List_egg_Declaration Declarations_type;
egg_Declaration Declaration_type;
egg_Expression Expression_type;
List_egg_Expression Params_type;
List_egg_Statement Statements_type;
egg_Statement Statement_type;
egg_MessageKind MessageKind_type;
egg_Message Message_type;
List_egg_SubMessage SubMessages_type;
egg_SubMessage SubMessage_type;
egg_Group Group_type;
List_egg_Statement OPTMORE_Group_type;
List_String ALT_Stringsym_SEP_commasym_type;
List_egg_Declaration OPTMORE_Declaration_type;
List_egg_Expression MORE_Expression_type;
List_egg_Expression ALT_Expression_SEP_commasym_type;
List_egg_Statement OPTMORE_Statement_type;
Bool OPT_fatalsym_type;
List_egg_SubMessage ALT_SubMessage_SEP_commasym_type;
Ident OPT_openparsym_Identsym_closeparsym_type;
Bool OPT_groupsym_type;
}

%type <usessym_type>	usessym
%type <commasym_type>	commasym
%type <semicolonsym_type>	semicolonsym
%type <fatalsym_type>	fatalsym
%type <errorsym_type>	errorsym
%type <warningsym_type>	warningsym
%type <disabledsym_type>	disabledsym
%type <keysym_type>	keysym
%type <postsym_type>	postsym
%type <openparsym_type>	openparsym
%type <closeparsym_type>	closeparsym
%type <groupsym_type>	groupsym
%type <openchainsym_type>	openchainsym
%type <equalssym_type>	equalssym
%type <closechainsym_type>	closechainsym
%type <commentsym_type>	commentsym
%type <Stringsym_type>	Stringsym
%type <Identsym_type>	Identsym
%type <egg_type>	egg
%type <Uses_type>	Uses
%type <Strings_type>	Strings
%type <Declarations_type>	Declarations
%type <Declaration_type>	Declaration
%type <Expression_type>	Expression
%type <Params_type>	Params
%type <Statements_type>	Statements
%type <Statement_type>	Statement
%type <MessageKind_type>	MessageKind
%type <Message_type>	Message
%type <SubMessages_type>	SubMessages
%type <SubMessage_type>	SubMessage
%type <Group_type>	Group
%type <OPTMORE_Group_type>	OPTMORE_Group
%type <ALT_Stringsym_SEP_commasym_type>	ALT_Stringsym_SEP_commasym
%type <OPTMORE_Declaration_type>	OPTMORE_Declaration
%type <MORE_Expression_type>	MORE_Expression
%type <ALT_Expression_SEP_commasym_type>	ALT_Expression_SEP_commasym
%type <OPTMORE_Statement_type>	OPTMORE_Statement
%type <OPT_fatalsym_type>	OPT_fatalsym
%type <ALT_SubMessage_SEP_commasym_type>	ALT_SubMessage_SEP_commasym
%type <OPT_openparsym_Identsym_closeparsym_type>	OPT_openparsym_Identsym_closeparsym
%type <OPT_groupsym_type>	OPT_groupsym

%start egg

%%

egg :
  Uses
  OPTMORE_Group
  { $$ = Create_egg_egg(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
    Decorate_egg($$);
  }
;

Uses :
  usessym
  Strings
  semicolonsym
  { $$ = Create_egg_Uses(make_post_src_info(@1.first_line, @3.last_line), $2);
  }
;

Strings :
  ALT_Stringsym_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

Declarations :
  OPTMORE_Declaration
  /* No type */
  {
    $$ = $1;
  }
;

Declaration :
  MessageKind
  equalssym
  MORE_Expression
  semicolonsym
  { $$ = Create_egg_Declaration(make_post_src_info(@1.first_line, @4.last_line), $1, $3);
  }
;

Expression :
  Stringsym
  { $$ = Create_egg_StringExpr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Expression :
  Identsym
  openparsym
  Params
  closeparsym
  { $$ = Create_egg_CallExpr(make_post_src_info(@1.first_line, @4.last_line), $1, $3);
  }
;

Expression :
  Identsym
  { $$ = Create_egg_IdExpr(make_post_src_info(@1.first_line, @1.last_line), $1);
  }
;

Params :
  ALT_Expression_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

Statements :
  OPTMORE_Statement
  /* No type */
  {
    $$ = $1;
  }
;

Statement :
  Message
  {
    $$ = $1;
  }
;

Statement :
  Group
  {
    $$ = $1;
  }
;

MessageKind :
  errorsym
  /* Enum type */
  { $$ = egg_ErrorMsg; }
;

MessageKind :
  warningsym
  /* Enum type */
  { $$ = egg_WarningMsg; }
;

MessageKind :
  disabledsym
  /* Enum type */
  { $$ = egg_DisabledMsg; }
;

MessageKind :
  keysym
  /* Enum type */
  { $$ = egg_KeyMsg; }
;

MessageKind :
  postsym
  /* Enum type */
  { $$ = egg_PostMsg; }
;

Message :
  OPT_fatalsym
  Identsym
  SubMessages
  semicolonsym
  { $$ = Create_egg_Message(make_post_src_info(@1.first_line, @4.last_line), $1, $2, $3);
  }
;

SubMessages :
  ALT_SubMessage_SEP_commasym
  /* No type */
  {
    $$ = $1;
  }
;

SubMessage :
  MessageKind
  Stringsym
  { $$ = Create_egg_SubMessage(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

Group :
  OPT_fatalsym
  Identsym
  OPT_openparsym_Identsym_closeparsym
  OPT_groupsym
  openchainsym
  Declarations
  Statements
  closechainsym
  { $$ = Create_egg_Group(make_post_src_info(@1.first_line, @8.last_line), $1, $2, $3, $4, $6, $7);
  }
;

/**** Extra rules ****/

OPTMORE_Group :
  {
    $$ = NULL;
  }
;

OPTMORE_Group :
  Group
  OPTMORE_Group
  {
    $$ = Create_List_egg_Statement($1, $2);
  }
;

ALT_Stringsym_SEP_commasym :
  Stringsym
  {
    $$ = Create_List_String($1, NULL);
  }
;

ALT_Stringsym_SEP_commasym :
  Stringsym
  commasym
  ALT_Stringsym_SEP_commasym
  {
    $$ = Create_List_String($1, $3);
  }
;

OPTMORE_Declaration :
  {
    $$ = NULL;
  }
;

OPTMORE_Declaration :
  Declaration
  OPTMORE_Declaration
  {
    $$ = Create_List_egg_Declaration($1, $2);
  }
;

MORE_Expression :
  Expression
  {
    $$ = Create_List_egg_Expression($1, NULL);
  }
;

MORE_Expression :
  Expression
  MORE_Expression
  {
    $$ = Create_List_egg_Expression($1, $2);
  }
;

ALT_Expression_SEP_commasym :
  Expression
  {
    $$ = Create_List_egg_Expression($1, NULL);
  }
;

ALT_Expression_SEP_commasym :
  Expression
  commasym
  ALT_Expression_SEP_commasym
  {
    $$ = Create_List_egg_Expression($1, $3);
  }
;

OPTMORE_Statement :
  {
    $$ = NULL;
  }
;

OPTMORE_Statement :
  Statement
  OPTMORE_Statement
  {
    $$ = Create_List_egg_Statement($1, $2);
  }
;

OPT_fatalsym :
  {
    $$ = FALSE;
  }
;

OPT_fatalsym :
  fatalsym
  {
    $$ = TRUE;
  }
;

ALT_SubMessage_SEP_commasym :
  SubMessage
  {
    $$ = Create_List_egg_SubMessage($1, NULL);
  }
;

ALT_SubMessage_SEP_commasym :
  SubMessage
  commasym
  ALT_SubMessage_SEP_commasym
  {
    $$ = Create_List_egg_SubMessage($1, $3);
  }
;

OPT_openparsym_Identsym_closeparsym :
  {
    $$ = NULL;
  }
;

OPT_openparsym_Identsym_closeparsym :
  openparsym
  Identsym
  closeparsym
  {
    $$ = $2;
  }
;

OPT_groupsym :
  {
    $$ = FALSE;
  }
;

OPT_groupsym :
  groupsym
  {
    $$ = TRUE;
  }
;

egg :
  hole_egg
  { $$ = (egg_egg)Get_sub_tree (); }
;

egg :
  start_egg
  egg
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

Uses :
  hole_Uses
  { $$ = (egg_Uses)Get_sub_tree (); }
;

egg :
  start_Uses
  Uses
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

Strings :
  hole_Strings
  { $$ = (List_String)Get_sub_tree (); }
;

egg :
  start_Strings
  Strings
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

Declarations :
  hole_Declarations
  { $$ = (List_egg_Declaration)Get_sub_tree (); }
;

egg :
  start_Declarations
  Declarations
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

Declaration :
  hole_Declaration
  { $$ = (egg_Declaration)Get_sub_tree (); }
;

egg :
  start_Declaration
  Declaration
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

Expression :
  hole_Expression
  { $$ = (egg_Expression)Get_sub_tree (); }
;

egg :
  start_Expression
  Expression
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

Params :
  hole_Params
  { $$ = (List_egg_Expression)Get_sub_tree (); }
;

egg :
  start_Params
  Params
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

Statements :
  hole_Statements
  { $$ = (List_egg_Statement)Get_sub_tree (); }
;

egg :
  start_Statements
  Statements
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

Statement :
  hole_Statement
  { $$ = (egg_Statement)Get_sub_tree (); }
;

egg :
  start_Statement
  Statement
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

MessageKind :
  hole_MessageKind
  { $$ = (egg_MessageKind)Get_sub_tree (); }
;

egg :
  start_MessageKind
  MessageKind
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

Message :
  hole_Message
  { $$ = (egg_Statement)Get_sub_tree (); }
;

egg :
  start_Message
  Message
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

SubMessages :
  hole_SubMessages
  { $$ = (List_egg_SubMessage)Get_sub_tree (); }
;

egg :
  start_SubMessages
  SubMessages
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

SubMessage :
  hole_SubMessage
  { $$ = (egg_SubMessage)Get_sub_tree (); }
;

egg :
  start_SubMessage
  SubMessage
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

Group :
  hole_Group
  { $$ = (egg_Statement)Get_sub_tree (); }
;

egg :
  start_Group
  Group
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Group :
  hole_OPTMORE_Group
  { $$ = (List_egg_Statement)Get_sub_tree (); }
;

egg :
  start_OPTMORE_Group
  OPTMORE_Group
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

ALT_Stringsym_SEP_commasym :
  hole_ALT_Stringsym_SEP_commasym
  { $$ = (List_String)Get_sub_tree (); }
;

egg :
  start_ALT_Stringsym_SEP_commasym
  ALT_Stringsym_SEP_commasym
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Declaration :
  hole_OPTMORE_Declaration
  { $$ = (List_egg_Declaration)Get_sub_tree (); }
;

egg :
  start_OPTMORE_Declaration
  OPTMORE_Declaration
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

MORE_Expression :
  hole_MORE_Expression
  { $$ = (List_egg_Expression)Get_sub_tree (); }
;

egg :
  start_MORE_Expression
  MORE_Expression
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

ALT_Expression_SEP_commasym :
  hole_ALT_Expression_SEP_commasym
  { $$ = (List_egg_Expression)Get_sub_tree (); }
;

egg :
  start_ALT_Expression_SEP_commasym
  ALT_Expression_SEP_commasym
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Statement :
  hole_OPTMORE_Statement
  { $$ = (List_egg_Statement)Get_sub_tree (); }
;

egg :
  start_OPTMORE_Statement
  OPTMORE_Statement
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

OPT_fatalsym :
  hole_OPT_fatalsym
  { $$ = (Bool)Get_sub_tree (); }
;

egg :
  start_OPT_fatalsym
  OPT_fatalsym
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

ALT_SubMessage_SEP_commasym :
  hole_ALT_SubMessage_SEP_commasym
  { $$ = (List_egg_SubMessage)Get_sub_tree (); }
;

egg :
  start_ALT_SubMessage_SEP_commasym
  ALT_SubMessage_SEP_commasym
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

OPT_openparsym_Identsym_closeparsym :
  hole_OPT_openparsym_Identsym_closeparsym
  { $$ = (Ident)Get_sub_tree (); }
;

egg :
  start_OPT_openparsym_Identsym_closeparsym
  OPT_openparsym_Identsym_closeparsym
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

OPT_groupsym :
  hole_OPT_groupsym
  { $$ = (Bool)Get_sub_tree (); }
;

egg :
  start_OPT_groupsym
  OPT_groupsym
  { egg_multi_action ((void*)$2); YYACCEPT; }
;

