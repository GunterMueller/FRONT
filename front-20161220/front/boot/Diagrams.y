%{
#include "scan_support.h"
#include "parse_support.h"
#include "Diagrams.h"
extern int input_line_nr;
%}

%token NONSENSE
%token rectanglesym
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
%token Intsym
%token Stringsym
%token Identsym
%token hole_Diagrams
%token start_Diagrams
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
Int Intsym_type;
String Stringsym_type;
Ident Identsym_type;
Diagrams_Diagrams Diagrams_type;
Diagrams_Direction Direction_type;
Diagrams_Picture Picture_type;
List_Diagrams_Picture OPTMORE_Picture_type;
struct {
  List_Diagrams_Picture f1;
  List_Diagrams_Direction f2;
} ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_type;
struct {
  List_Diagrams_Picture f1;
  List_Diagrams_Direction f2;
} ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_type;
List_Diagrams_Picture MORE_Picture_type;
}

%type <rectanglesym_type>	rectanglesym
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
%type <Intsym_type>	Intsym
%type <Stringsym_type>	Stringsym
%type <Identsym_type>	Identsym
%type <Diagrams_type>	Diagrams
%type <Direction_type>	Direction
%type <Picture_type>	Picture
%type <OPTMORE_Picture_type>	OPTMORE_Picture
%type <ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_type>	ALT_ORspacesym_Picture_SEP_Direction_ENDORsym
%type <ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_type>	ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym
%type <MORE_Picture_type>	MORE_Picture

%%

Diagrams :
  OPTMORE_Picture
  { $$ = Create_Diagrams_Diagrams(make_post_src_info(@1.first_line, @1.last_line), $1);
    Decorate_Diagrams($$);
  }
;

Direction :
  Lsym
  /* Enum type */
  { $$ = Diagrams_Left; }
;

Direction :
  Rsym
  /* Enum type */
  { $$ = Diagrams_Right; }
;

Direction :
  Usym
  /* Enum type */
  { $$ = Diagrams_Up; }
;

Direction :
  Dsym
  /* Enum type */
  { $$ = Diagrams_Down; }
;

Direction :
  Csym
  /* Enum type */
  { $$ = Diagrams_Center; }
;

Picture :
  Intsym
  Intsym
  Intsym
  Intsym
  { $$ = Create_Diagrams_Empty(make_post_src_info(@1.first_line, @4.last_line), $1, $2, $3, $4);
  }
;

Picture :
  Intsym
  Intsym
  Intsym
  Intsym
  rectanglesym
  { $$ = Create_Diagrams_Box(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4);
  }
;

Picture :
  Intsym
  Intsym
  Intsym
  Intsym
  arctopopsym
  Boolsym
  Boolsym
  { $$ = Create_Diagrams_Curve(make_post_src_info(@1.first_line, @7.last_line), $1, $2, $3, $4, $6, $7);
  }
;

Picture :
  Intsym
  Intsym
  Intsym
  Intsym
  linesym
  { $$ = Create_Diagrams_Line(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4);
  }
;

Picture :
  Intsym
  Intsym
  Intsym
  Intsym
  trianglesym
  eofillsym
  Direction
  { $$ = Create_Diagrams_Arrow(make_post_src_info(@1.first_line, @7.last_line), $1, $2, $3, $4, $7);
  }
;

Picture :
  Intsym
  Intsym
  Intsym
  Intsym
  openparsym
  Stringsym
  closeparsym
  Identsym
  { $$ = Create_Diagrams_Text(make_post_src_info(@1.first_line, @8.last_line), $1, $2, $3, $4, $6, $8);
  }
;

Picture :
  Intsym
  Intsym
  Intsym
  Intsym
  ALT_ORspacesym_Picture_SEP_Direction_ENDORsym
  { $$ = Create_Diagrams_OrBlock(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4, $5.f1, $5.f2);
  }
;

Picture :
  Intsym
  Intsym
  Intsym
  Intsym
  ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym
  { $$ = Create_Diagrams_AndBlock(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4, $5.f1, $5.f2);
  }
;

Picture :
  Intsym
  Intsym
  Intsym
  Intsym
  ALTspacesym
  Picture
  Picture
  Boolsym
  ENDALTsym
  { $$ = Create_Diagrams_AltBlock(make_post_src_info(@1.first_line, @9.last_line), $1, $2, $3, $4, $6, $7, $8);
  }
;

Picture :
  Intsym
  Intsym
  Intsym
  Intsym
  MORE_Picture
  { $$ = Create_Diagrams_Compound(make_post_src_info(@1.first_line, @5.last_line), $1, $2, $3, $4, $5);
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
    $$ = Create_List_Diagrams_Picture($1, $2);
  }
;

ALT_ORspacesym_Picture_SEP_Direction_ENDORsym :
  ORspacesym
  Picture
  {
    $$.f1 = Create_List_Diagrams_Picture($2, NULL);
    $$.f2 = NULL;
  }
;

ALT_ORspacesym_Picture_SEP_Direction_ENDORsym :
  ORspacesym
  Picture
  Direction
  ENDORsym
  ALT_ORspacesym_Picture_SEP_Direction_ENDORsym
  {
    $$.f1 = Create_List_Diagrams_Picture($2, $5.f1);
    $$.f2 = Create_List_Diagrams_Direction($3, $5.f2);
  }
;

ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym :
  ANDspacesym
  Picture
  {
    $$.f1 = Create_List_Diagrams_Picture($2, NULL);
    $$.f2 = NULL;
  }
;

ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym :
  ANDspacesym
  Picture
  Direction
  ENDANDsym
  ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym
  {
    $$.f1 = Create_List_Diagrams_Picture($2, $5.f1);
    $$.f2 = Create_List_Diagrams_Direction($3, $5.f2);
  }
;

MORE_Picture :
  Picture
  {
    $$ = Create_List_Diagrams_Picture($1, NULL);
  }
;

MORE_Picture :
  Picture
  MORE_Picture
  {
    $$ = Create_List_Diagrams_Picture($1, $2);
  }
;

Diagrams :
  hole_Diagrams
  { $$ = (Diagrams_Diagrams)Get_sub_tree (); }
;

Diagrams :
  start_Diagrams
  Diagrams
  { Diagrams_multi_action ((void*)$2); }
;

Direction :
  hole_Direction
  { $$ = (Diagrams_Direction)Get_sub_tree (); }
;

Diagrams :
  start_Direction
  Direction
  { Diagrams_multi_action ((void*)$2); }
;

Picture :
  hole_Picture
  { $$ = (Diagrams_Picture)Get_sub_tree (); }
;

Diagrams :
  start_Picture
  Picture
  { Diagrams_multi_action ((void*)$2); }
;

OPTMORE_Picture :
  hole_OPTMORE_Picture
  { $$ = (List_Diagrams_Picture)Get_sub_tree (); }
;

Diagrams :
  start_OPTMORE_Picture
  OPTMORE_Picture
  { Diagrams_multi_action ((void*)$2); }
;

MORE_Picture :
  hole_MORE_Picture
  { $$ = (List_Diagrams_Picture)Get_sub_tree (); }
;

Diagrams :
  start_MORE_Picture
  MORE_Picture
  { Diagrams_multi_action ((void*)$2); }
;

