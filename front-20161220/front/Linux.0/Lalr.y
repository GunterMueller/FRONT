%{
#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "Lalr.h"

extern int input_line_nr;

struct yy_buffer_state *Lalr_dummy_state (void);
struct yy_buffer_state *Lalr_scanner_state (void);
%}

%token NONSENSE
%token GRAMMARsym
%token minusgreaterthansym
%token questionmarksym
%token semicolonsym
%token emptycolonsym
%token NON_EMPTYsym
%token EMPTYsym
%token firstcolonsym
%token spacesym
%token STATESsym
%token statesym
%token dotsym
%token followerscolonsym
%token transitionssym
%token equalsgreaterthansym
%token Intsym
%token Identsym
%token hole_Lalr
%token start_Lalr
%token hole_Production
%token start_Production
%token hole_ProdRhs
%token start_ProdRhs
%token hole_LR_Symbol
%token start_LR_Symbol
%token hole_LR_Symbols
%token start_LR_Symbols
%token hole_Emptiness
%token start_Emptiness
%token hole_LR_state
%token start_LR_state
%token hole_Item
%token start_Item
%token hole_TermSet
%token start_TermSet
%token hole_Transition
%token start_Transition
%token hole_OPTMORE_Production
%token start_OPTMORE_Production
%token hole_OPTMORE_LR_state
%token start_OPTMORE_LR_state
%token hole_OPT_LR_Symbols
%token start_OPT_LR_Symbols
%token hole_OPT_questionmarksym
%token start_OPT_questionmarksym
%token hole_MORE_Item
%token start_MORE_Item
%token hole_OPTMORE_Transition
%token start_OPTMORE_Transition
%token hole_OPTMORE_LR_Symbol
%token start_OPTMORE_LR_Symbol
%token hole_OPT_followerscolonsym_TermSet
%token start_OPT_followerscolonsym_TermSet
%token hole_MORE_Identsym_spacesym
%token start_MORE_Identsym_spacesym

%union {
Int Intsym_type;
Ident Identsym_type;
Lalr_Lalr Lalr_type;
Lalr_Production Production_type;
Lalr_LR_Symbols ProdRhs_type;
Lalr_LR_Symbol LR_Symbol_type;
Lalr_LR_Symbols LR_Symbols_type;
Lalr_Emptiness Emptiness_type;
Lalr_LR_state LR_state_type;
Lalr_Item Item_type;
List_Ident TermSet_type;
Lalr_Transition Transition_type;
List_Lalr_Production OPTMORE_Production_type;
List_Lalr_LR_state OPTMORE_LR_state_type;
Lalr_LR_Symbols OPT_LR_Symbols_type;
Bool OPT_questionmarksym_type;
List_Lalr_Item MORE_Item_type;
List_Lalr_Transition OPTMORE_Transition_type;
List_Lalr_LR_Symbol OPTMORE_LR_Symbol_type;
List_Ident OPT_followerscolonsym_TermSet_type;
List_Ident MORE_Identsym_spacesym_type;
}

%type <GRAMMARsym_type>	GRAMMARsym
%type <minusgreaterthansym_type>	minusgreaterthansym
%type <questionmarksym_type>	questionmarksym
%type <semicolonsym_type>	semicolonsym
%type <emptycolonsym_type>	emptycolonsym
%type <NON_EMPTYsym_type>	NON_EMPTYsym
%type <EMPTYsym_type>	EMPTYsym
%type <firstcolonsym_type>	firstcolonsym
%type <spacesym_type>	spacesym
%type <STATESsym_type>	STATESsym
%type <statesym_type>	statesym
%type <dotsym_type>	dotsym
%type <followerscolonsym_type>	followerscolonsym
%type <transitionssym_type>	transitionssym
%type <equalsgreaterthansym_type>	equalsgreaterthansym
%type <Intsym_type>	Intsym
%type <Identsym_type>	Identsym
%type <Lalr_type>	Lalr
%type <Production_type>	Production
%type <ProdRhs_type>	ProdRhs
%type <LR_Symbol_type>	LR_Symbol
%type <LR_Symbols_type>	LR_Symbols
%type <Emptiness_type>	Emptiness
%type <LR_state_type>	LR_state
%type <Item_type>	Item
%type <TermSet_type>	TermSet
%type <Transition_type>	Transition
%type <OPTMORE_Production_type>	OPTMORE_Production
%type <OPTMORE_LR_state_type>	OPTMORE_LR_state
%type <OPT_LR_Symbols_type>	OPT_LR_Symbols
%type <OPT_questionmarksym_type>	OPT_questionmarksym
%type <MORE_Item_type>	MORE_Item
%type <OPTMORE_Transition_type>	OPTMORE_Transition
%type <OPTMORE_LR_Symbol_type>	OPTMORE_LR_Symbol
%type <OPT_followerscolonsym_TermSet_type>	OPT_followerscolonsym_TermSet
%type <MORE_Identsym_spacesym_type>	MORE_Identsym_spacesym

%start Lalr

%%

Lalr :
  GRAMMARsym
  OPTMORE_Production
  STATESsym
  OPTMORE_LR_state
  { $$ = Create_Lalr_Lalr(make_post_src_info(@1.first_line, @4.last_line), $2, $4);
    Decorate_Lalr($$);
  }
;

Production :
  Identsym
  minusgreaterthansym
  ProdRhs
  semicolonsym
  emptycolonsym
  Emptiness
  firstcolonsym
  TermSet
  { $$ = Create_Lalr_Production(make_post_src_info(@1.first_line, @8.last_line), $1, $3, $6, $8);
  }
;

ProdRhs :
  OPT_LR_Symbols
  /* No type */
  {
    $$ = $1;
  }
;

LR_Symbol :
  Identsym
  OPT_questionmarksym
  { $$ = Create_Lalr_LR_Symbol(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

LR_Symbols :
  LR_Symbol
  LR_Symbols
  { $$ = Create_Lalr_LR_Symbols(make_post_src_info(@1.first_line, @2.last_line), $1, $2);
  }
;

Emptiness :
  NON_EMPTYsym
  /* Enum type */
  { $$ = FALSE; }
;

Emptiness :
  EMPTYsym
  /* Enum type */
  { $$ = TRUE; }
;

LR_state :
  statesym
  Intsym
  MORE_Item
  transitionssym
  OPTMORE_Transition
  { $$ = Create_Lalr_LR_state(make_post_src_info(@1.first_line, @5.last_line), $2, $3, $5);
  }
;

Item :
  Identsym
  minusgreaterthansym
  OPTMORE_LR_Symbol
  dotsym
  LR_Symbols
  OPT_followerscolonsym_TermSet
  { $$ = Create_Lalr_Item(make_post_src_info(@1.first_line, @6.last_line), $1, $3, $5, $6);
  }
;

TermSet :
  MORE_Identsym_spacesym
  /* No type */
  {
    $$ = $1;
  }
;

Transition :
  LR_Symbol
  equalsgreaterthansym
  statesym
  Intsym
  { $$ = Create_Lalr_Transition(make_post_src_info(@1.first_line, @4.last_line), $1, $4);
  }
;

/**** Extra rules ****/

OPTMORE_Production :
  {
    $$ = NULL;
  }
;

OPTMORE_Production :
  Production
  OPTMORE_Production
  {
    $$ = Create_List_Lalr_Production($1, $2);
  }
;

OPTMORE_LR_state :
  {
    $$ = NULL;
  }
;

OPTMORE_LR_state :
  LR_state
  OPTMORE_LR_state
  {
    $$ = Create_List_Lalr_LR_state($1, $2);
  }
;

OPT_LR_Symbols :
  {
    $$ = NULL;
  }
;

OPT_LR_Symbols :
  LR_Symbols
  {
    $$ = $1;
  }
;

OPT_questionmarksym :
  {
    $$ = FALSE;
  }
;

OPT_questionmarksym :
  questionmarksym
  {
    $$ = TRUE;
  }
;

MORE_Item :
  Item
  {
    $$ = Create_List_Lalr_Item($1, NULL);
  }
;

MORE_Item :
  Item
  MORE_Item
  {
    $$ = Create_List_Lalr_Item($1, $2);
  }
;

OPTMORE_Transition :
  {
    $$ = NULL;
  }
;

OPTMORE_Transition :
  Transition
  OPTMORE_Transition
  {
    $$ = Create_List_Lalr_Transition($1, $2);
  }
;

OPTMORE_LR_Symbol :
  {
    $$ = NULL;
  }
;

OPTMORE_LR_Symbol :
  LR_Symbol
  OPTMORE_LR_Symbol
  {
    $$ = Create_List_Lalr_LR_Symbol($1, $2);
  }
;

OPT_followerscolonsym_TermSet :
  {
    $$ = NULL;
  }
;

OPT_followerscolonsym_TermSet :
  followerscolonsym
  TermSet
  {
    $$ = $2;
  }
;

MORE_Identsym_spacesym :
  Identsym
  spacesym
  {
    $$ = Create_List_Ident($1, NULL);
  }
;

MORE_Identsym_spacesym :
  Identsym
  spacesym
  MORE_Identsym_spacesym
  {
    $$ = Create_List_Ident($1, $3);
  }
;

Lalr :
  hole_Lalr
  { $$ = (Lalr_Lalr)Get_sub_tree (); }
;

Lalr :
  start_Lalr
  Lalr
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

Production :
  hole_Production
  { $$ = (Lalr_Production)Get_sub_tree (); }
;

Lalr :
  start_Production
  Production
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

ProdRhs :
  hole_ProdRhs
  { $$ = (Lalr_LR_Symbols)Get_sub_tree (); }
;

Lalr :
  start_ProdRhs
  ProdRhs
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

LR_Symbol :
  hole_LR_Symbol
  { $$ = (Lalr_LR_Symbol)Get_sub_tree (); }
;

Lalr :
  start_LR_Symbol
  LR_Symbol
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

LR_Symbols :
  hole_LR_Symbols
  { $$ = (Lalr_LR_Symbols)Get_sub_tree (); }
;

Lalr :
  start_LR_Symbols
  LR_Symbols
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

Emptiness :
  hole_Emptiness
  { $$ = (Lalr_Emptiness)Get_sub_tree (); }
;

Lalr :
  start_Emptiness
  Emptiness
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

LR_state :
  hole_LR_state
  { $$ = (Lalr_LR_state)Get_sub_tree (); }
;

Lalr :
  start_LR_state
  LR_state
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

Item :
  hole_Item
  { $$ = (Lalr_Item)Get_sub_tree (); }
;

Lalr :
  start_Item
  Item
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

TermSet :
  hole_TermSet
  { $$ = (List_Ident)Get_sub_tree (); }
;

Lalr :
  start_TermSet
  TermSet
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

Transition :
  hole_Transition
  { $$ = (Lalr_Transition)Get_sub_tree (); }
;

Lalr :
  start_Transition
  Transition
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Production :
  hole_OPTMORE_Production
  { $$ = (List_Lalr_Production)Get_sub_tree (); }
;

Lalr :
  start_OPTMORE_Production
  OPTMORE_Production
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_LR_state :
  hole_OPTMORE_LR_state
  { $$ = (List_Lalr_LR_state)Get_sub_tree (); }
;

Lalr :
  start_OPTMORE_LR_state
  OPTMORE_LR_state
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

OPT_LR_Symbols :
  hole_OPT_LR_Symbols
  { $$ = (Lalr_LR_Symbols)Get_sub_tree (); }
;

Lalr :
  start_OPT_LR_Symbols
  OPT_LR_Symbols
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

OPT_questionmarksym :
  hole_OPT_questionmarksym
  { $$ = (Bool)Get_sub_tree (); }
;

Lalr :
  start_OPT_questionmarksym
  OPT_questionmarksym
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

MORE_Item :
  hole_MORE_Item
  { $$ = (List_Lalr_Item)Get_sub_tree (); }
;

Lalr :
  start_MORE_Item
  MORE_Item
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Transition :
  hole_OPTMORE_Transition
  { $$ = (List_Lalr_Transition)Get_sub_tree (); }
;

Lalr :
  start_OPTMORE_Transition
  OPTMORE_Transition
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_LR_Symbol :
  hole_OPTMORE_LR_Symbol
  { $$ = (List_Lalr_LR_Symbol)Get_sub_tree (); }
;

Lalr :
  start_OPTMORE_LR_Symbol
  OPTMORE_LR_Symbol
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

OPT_followerscolonsym_TermSet :
  hole_OPT_followerscolonsym_TermSet
  { $$ = (List_Ident)Get_sub_tree (); }
;

Lalr :
  start_OPT_followerscolonsym_TermSet
  OPT_followerscolonsym_TermSet
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

MORE_Identsym_spacesym :
  hole_MORE_Identsym_spacesym
  { $$ = (List_Ident)Get_sub_tree (); }
;

Lalr :
  start_MORE_Identsym_spacesym
  MORE_Identsym_spacesym
  { Lalr_multi_action ((void*)$2); YYACCEPT; }
;

