%{
#include <string.h>
#include "front/scan_support.h"
#include "front/parse_support.h"
#include "Pictures.h"

extern int input_line_nr;

struct yy_buffer_state *Pictures_dummy_state (void);
struct yy_buffer_state *Pictures_scanner_state (void);
%}

%token NONSENSE
%token rectanglesym
%token circlesym
%token arcsym
%token arctopopsym
%token linesym
%token trianglesym
%token eofillsym
%token Lsym
%token Rsym
%token Usym
%token Dsym
%token Csym
%token openparsym
%token closeparsym
%token ORspacesym
%token ENDORsym
%token ANDspacesym
%token ENDANDsym
%token ALTspacesym
%token ENDALTsym
%token Boolsym
%token Floatsym
%token Stringsym
%token Identsym
%token hole_Pictures
%token start_Pictures
%token hole_Direction
%token start_Direction
%token hole_Picture
%token start_Picture
%token hole_OPTMORE_Picture
%token start_OPTMORE_Picture
%token hole_MORE_Picture
%token start_MORE_Picture

%union {
Bool Boolsym_type;
Float Floatsym_type;
String Stringsym_type;
Ident Identsym_type;
Pictures_Pictures Pictures_type;
Pictures_Direction Direction_type;
Pictures_Picture Picture_type;
List_Pictures_Picture OPTMORE_Picture_type;
struct {
  List_Pictures_Picture f1;
  List_Pictures_Direction f2;
} ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL_type;
struct {
  List_Pictures_Picture f1;
  List_Pictures_Direction f2;
} ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL_type;
List_Pictures_Picture MORE_Picture_type;
}

%type <rectanglesym_type>	rectanglesym
%type <circlesym_type>	circlesym
%type <arcsym_type>	arcsym
%type <arctopopsym_type>	arctopopsym
%type <linesym_type>	linesym
%type <trianglesym_type>	trianglesym
%type <eofillsym_type>	eofillsym
%type <Lsym_type>	Lsym
%type <Rsym_type>	Rsym
%type <Usym_type>	Usym
%type <Dsym_type>	Dsym
%type <Csym_type>	Csym
%type <openparsym_type>	openparsym
%type <closeparsym_type>	closeparsym
%type <ORspacesym_type>	ORspacesym
%type <ENDORsym_type>	ENDORsym
%type <ANDspacesym_type>	ANDspacesym
%type <ENDANDsym_type>	ENDANDsym
%type <ALTspacesym_type>	ALTspacesym
%type <ENDALTsym_type>	ENDALTsym
%type <Boolsym_type>	Boolsym
%type <Floatsym_type>	Floatsym
%type <Stringsym_type>	Stringsym
%type <Identsym_type>	Identsym
%type <Pictures_type>	Pictures
%type <Direction_type>	Direction
%type <Picture_type>	Picture
%type <OPTMORE_Picture_type>	OPTMORE_Picture
%type <ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL_type>	ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL
%type <ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL_type>	ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL
%type <MORE_Picture_type>	MORE_Picture

%start Pictures

%%

Pictures :
  OPTMORE_Picture
  { $$ = Create_Pictures_Pictures(make_post_src_info(@1.first_line, @1.last_line), $1);
    Decorate_Pictures($$);
  }
;

Direction :
  Lsym
  /* Enum type */
  { $$ = Pictures_Left; }
;

Direction :
  Rsym
  /* Enum type */
  { $$ = Pictures_Right; }
;

Direction :
  Usym
  /* Enum type */
  { $$ = Pictures_Up; }
;

Direction :
  Dsym
  /* Enum type */
  { $$ = Pictures_Down; }
;

Direction :
  Csym
  /* Enum type */
  { $$ = Pictures_Center; }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  { $$ = Create_Pictures_Empty(make_post_src_info(@1.first_line, @4.last_line), $1, $2, $3, $4);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  rectanglesym
  { $$ = Create_Pictures_Box(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  circlesym
  { $$ = Create_Pictures_Circle(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  arcsym
  Floatsym
  Floatsym
  { $$ = Create_Pictures_Arc(make_post_src_info(@1.first_line, @7.last_line), $1, $2, $3, $4, $6, $7);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  arctopopsym
  Boolsym
  Boolsym
  { $$ = Create_Pictures_Curve(make_post_src_info(@1.first_line, @7.last_line), $1, $2, $3, $4, $6, $7);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  linesym
  { $$ = Create_Pictures_Line(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  trianglesym
  eofillsym
  Direction
  { $$ = Create_Pictures_Arrow(make_post_src_info(@1.first_line, @7.last_line), $1, $2, $3, $4, $7);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  openparsym
  Stringsym
  closeparsym
  Identsym
  { $$ = Create_Pictures_Text(make_post_src_info(@1.first_line, @8.last_line), $1, $2, $3, $4, $6, $8);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL
  { $$ = Create_Pictures_OrBlock(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4, $5.f1, $5.f2);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL
  { $$ = Create_Pictures_AndBlock(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4, $5.f1, $5.f2);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  ALTspacesym
  Picture
  Picture
  Boolsym
  ENDALTsym
  { $$ = Create_Pictures_AltBlock(make_post_src_info(@1.first_line, @9.last_line), $1, $2, $3, $4, $6, $7, $8);
  }
;

Picture :
  Floatsym
  Floatsym
  Floatsym
  Floatsym
  MORE_Picture
  { $$ = Create_Pictures_Compound(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4, $5);
  }
;

/**** Extra rules ****/

OPTMORE_Picture :
  {
    $$ = NULL;
  }
;

OPTMORE_Picture :
  Picture
  OPTMORE_Picture
  {
    $$ = Create_List_Pictures_Picture($1, $2);
  }
;

ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL :
  ORspacesym
  Picture
  {
    $$.f1 = Create_List_Pictures_Picture($2, NULL);
    $$.f2 = NULL;
  }
;

ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL :
  ORspacesym
  Picture
  Direction
  ENDORsym
  ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL
  {
    $$.f1 = Create_List_Pictures_Picture($2, $5.f1);
    $$.f2 = Create_List_Pictures_Direction($3, $5.f2);
  }
;

ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL :
  ANDspacesym
  Picture
  {
    $$.f1 = Create_List_Pictures_Picture($2, NULL);
    $$.f2 = NULL;
  }
;

ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL :
  ANDspacesym
  Picture
  Direction
  ENDANDsym
  ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL
  {
    $$.f1 = Create_List_Pictures_Picture($2, $5.f1);
    $$.f2 = Create_List_Pictures_Direction($3, $5.f2);
  }
;

MORE_Picture :
  Picture
  {
    $$ = Create_List_Pictures_Picture($1, NULL);
  }
;

MORE_Picture :
  Picture
  MORE_Picture
  {
    $$ = Create_List_Pictures_Picture($1, $2);
  }
;

Pictures :
  hole_Pictures
  { $$ = (Pictures_Pictures)Get_sub_tree (); }
;

Pictures :
  start_Pictures
  Pictures
  { Pictures_multi_action ((void*)$2); YYACCEPT; }
;

Direction :
  hole_Direction
  { $$ = (Pictures_Direction)Get_sub_tree (); }
;

Pictures :
  start_Direction
  Direction
  { Pictures_multi_action ((void*)$2); YYACCEPT; }
;

Picture :
  hole_Picture
  { $$ = (Pictures_Picture)Get_sub_tree (); }
;

Pictures :
  start_Picture
  Picture
  { Pictures_multi_action ((void*)$2); YYACCEPT; }
;

OPTMORE_Picture :
  hole_OPTMORE_Picture
  { $$ = (List_Pictures_Picture)Get_sub_tree (); }
;

Pictures :
  start_OPTMORE_Picture
  OPTMORE_Picture
  { Pictures_multi_action ((void*)$2); YYACCEPT; }
;

MORE_Picture :
  hole_MORE_Picture
  { $$ = (List_Pictures_Picture)Get_sub_tree (); }
;

Pictures :
  start_MORE_Picture
  MORE_Picture
  { Pictures_multi_action ((void*)$2); YYACCEPT; }
;

