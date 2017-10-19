#include "Pictures_lalr.h"

#include "Pictures_y.h"

typedef enum {
  Pictures_NONSENSE,
  Lsym_value,
  Rsym_value,
  Usym_value,
  Dsym_value,
  Csym_value,
  Floatsym_value,
  rectanglesym_value,
  circlesym_value,
  arcsym_value,
  arctopopsym_value,
  Boolsym_value,
  linesym_value,
  trianglesym_value,
  eofillsym_value,
  openparsym_value,
  Stringsym_value,
  closeparsym_value,
  Identsym_value,
  ALTspacesym_value,
  ENDALTsym_value,
  ORspacesym_value,
  ENDORsym_value,
  ANDspacesym_value,
  ENDANDsym_value,
  hole_OPTMORE_Picture_value,
  hole_Pictures_value,
  hole_Direction_value,
  hole_Picture_value,
  hole_MORE_Picture_value,
  Pictures_EOF_value,
  OPTMORE_Picture_value,
  Pictures_value,
  Direction_value,
  Picture_value,
  ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL_value,
  ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL_value,
  MORE_Picture_value,
  Pictures_ERROR
} PicturesSymbol;

static PicturesSymbol _Pictures_token;

static PicturesSymbol _Pictures_symbol;

#define NUM_TERMINALS 31

#define WORDS_IN_SET ((NUM_TERMINALS+BITSPERWORD-1)/BITSPERWORD)

static String Pictures_symbol_names[] = {
  "Pictures_NONSENSE",
  "Lsym",
  "Rsym",
  "Usym",
  "Dsym",
  "Csym",
  "Floatsym",
  "rectanglesym",
  "circlesym",
  "arcsym",
  "arctopopsym",
  "Boolsym",
  "linesym",
  "trianglesym",
  "eofillsym",
  "openparsym",
  "Stringsym",
  "closeparsym",
  "Identsym",
  "ALTspacesym",
  "ENDALTsym",
  "ORspacesym",
  "ENDORsym",
  "ANDspacesym",
  "ENDANDsym",
  "hole_OPTMORE_Picture",
  "hole_Pictures",
  "hole_Direction",
  "hole_Picture",
  "hole_MORE_Picture",
  "Pictures_EOF",
  "OPTMORE_Picture",
  "Pictures",
  "Direction",
  "Picture",
  "ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL",
  "ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL",
  "MORE_Picture",
  "Pictures_ERROR"
};

static PicturesSymbol Pictures_terminal_map[2*Pictures_ERROR];

static void fill_terminal_map (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;
  Pictures_terminal_map[0] = Pictures_NONSENSE;
  Pictures_terminal_map[Lsym-NONSENSE] = Lsym_value;
  Pictures_terminal_map[Rsym-NONSENSE] = Rsym_value;
  Pictures_terminal_map[Usym-NONSENSE] = Usym_value;
  Pictures_terminal_map[Dsym-NONSENSE] = Dsym_value;
  Pictures_terminal_map[Csym-NONSENSE] = Csym_value;
  Pictures_terminal_map[Floatsym-NONSENSE] = Floatsym_value;
  Pictures_terminal_map[rectanglesym-NONSENSE] = rectanglesym_value;
  Pictures_terminal_map[circlesym-NONSENSE] = circlesym_value;
  Pictures_terminal_map[arcsym-NONSENSE] = arcsym_value;
  Pictures_terminal_map[arctopopsym-NONSENSE] = arctopopsym_value;
  Pictures_terminal_map[Boolsym-NONSENSE] = Boolsym_value;
  Pictures_terminal_map[linesym-NONSENSE] = linesym_value;
  Pictures_terminal_map[trianglesym-NONSENSE] = trianglesym_value;
  Pictures_terminal_map[eofillsym-NONSENSE] = eofillsym_value;
  Pictures_terminal_map[openparsym-NONSENSE] = openparsym_value;
  Pictures_terminal_map[Stringsym-NONSENSE] = Stringsym_value;
  Pictures_terminal_map[closeparsym-NONSENSE] = closeparsym_value;
  Pictures_terminal_map[Identsym-NONSENSE] = Identsym_value;
  Pictures_terminal_map[ALTspacesym-NONSENSE] = ALTspacesym_value;
  Pictures_terminal_map[ENDALTsym-NONSENSE] = ENDALTsym_value;
  Pictures_terminal_map[ORspacesym-NONSENSE] = ORspacesym_value;
  Pictures_terminal_map[ENDORsym-NONSENSE] = ENDORsym_value;
  Pictures_terminal_map[ANDspacesym-NONSENSE] = ANDspacesym_value;
  Pictures_terminal_map[ENDANDsym-NONSENSE] = ENDANDsym_value;
  Pictures_terminal_map[hole_OPTMORE_Picture-NONSENSE] = hole_OPTMORE_Picture_value;
  Pictures_terminal_map[hole_Pictures-NONSENSE] = hole_Pictures_value;
  Pictures_terminal_map[hole_Direction-NONSENSE] = hole_Direction_value;
  Pictures_terminal_map[hole_Picture-NONSENSE] = hole_Picture_value;
  Pictures_terminal_map[hole_MORE_Picture-NONSENSE] = hole_MORE_Picture_value;
}

extern int Pictures_lex(void);
#define SHIFT() { _Pictures_token = Pictures_lex(); if (_Pictures_token==0) _Pictures_token = Pictures_EOF_value; else _Pictures_token = Pictures_terminal_map[_Pictures_token-NONSENSE]; }
#define HOLE_ACTION(term,s) PUSH_PARSEVALUE(Pointer,Get_sub_tree(),hole); SHIFT()
#ifdef TRACE_Pictures_PARSE
#define REPORT(n) \
    printf ("State %d,	symbol %s,	token %s\n", n, Pictures_symbol_names[_Pictures_symbol], Pictures_symbol_names[_Pictures_token]);
#else
#define REPORT(n)
#endif
#if !defined(__GNUC__)
# define __inline__
#endif
List_Pictures_Picture Parse_state_Pictures_OPTMORE_Picture (void);	/* state 0 */
static int Parse_state_1 (SymbolSet followers);	/* state 1 */
static int Parse_state_2 (SymbolSet followers);	/* state 2 */
static int Parse_state_3 (SymbolSet followers);	/* state 3 */
static int Parse_state_4 (SymbolSet followers);	/* state 4 */
static int Parse_state_5 (SymbolSet followers);	/* state 5 */
static int Parse_state_6 (SymbolSet followers);	/* state 6 */

static __inline__ int Parse_state_7 (void)	/* state 7 */
{ int n;
      n = 1; _Pictures_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Pictures_Left,Pictures_Direction);
  return n-1;
}


static __inline__ int Parse_state_8 (void)	/* state 8 */
{ int n;
      n = 1; _Pictures_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Pictures_Right,Pictures_Direction);
  return n-1;
}


static __inline__ int Parse_state_9 (void)	/* state 9 */
{ int n;
      n = 1; _Pictures_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Pictures_Up,Pictures_Direction);
  return n-1;
}


static __inline__ int Parse_state_10 (void)	/* state 10 */
{ int n;
      n = 1; _Pictures_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Pictures_Down,Pictures_Direction);
  return n-1;
}


static __inline__ int Parse_state_11 (void)	/* state 11 */
{ int n;
      n = 1; _Pictures_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Pictures_Center,Pictures_Direction);
  return n-1;
}

static int Parse_state_12 (SymbolSet followers);	/* state 12 */
static int Parse_state_13 (SymbolSet followers);	/* state 13 */

static __inline__ int Parse_state_14 (void)	/* state 14 */
{ int n;
      n = 5; _Pictures_symbol = ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL_value;
      { /* alt action */
        List_Pictures_Direction  dirs_l = POP_PARSEVALUE (Pointer, List_Pictures_Direction);
        List_Pictures_Picture  sub_l = POP_PARSEVALUE (Pointer, List_Pictures_Picture);
        Pictures_Direction  dirs = POP_PARSEVALUE (Int, Pictures_Direction);
        Pictures_Picture  sub = POP_PARSEVALUE (Pointer, Pictures_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Pictures_Picture(sub,sub_l),List_Pictures_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Pictures_Direction(dirs,dirs_l),List_Pictures_Direction);
      }
  return n-1;
}

static int Parse_state_15 (SymbolSet followers);	/* state 15 */
static int Parse_state_16 (SymbolSet followers);	/* state 16 */
static int Parse_state_17 (SymbolSet followers);	/* state 17 */
static int Parse_state_18 (SymbolSet followers);	/* state 18 */

static __inline__ int Parse_state_19 (void)	/* state 19 */
{ int n;
      n = 5; _Pictures_symbol = ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL_value;
      { /* alt action */
        List_Pictures_Direction  dirs_l = POP_PARSEVALUE (Pointer, List_Pictures_Direction);
        List_Pictures_Picture  sub_l = POP_PARSEVALUE (Pointer, List_Pictures_Picture);
        Pictures_Direction  dirs = POP_PARSEVALUE (Int, Pictures_Direction);
        Pictures_Picture  sub = POP_PARSEVALUE (Pointer, Pictures_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Pictures_Picture(sub,sub_l),List_Pictures_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Pictures_Direction(dirs,dirs_l),List_Pictures_Direction);
      }
  return n-1;
}

static int Parse_state_20 (SymbolSet followers);	/* state 20 */

static __inline__ int Parse_state_21 (void)	/* state 21 */
{ int n;
      n = 2; _Pictures_symbol = MORE_Picture_value;
      { /* more action */
        List_Pictures_Picture  sub_l = POP_PARSEVALUE (Pointer, List_Pictures_Picture);
        Pictures_Picture  sub = POP_PARSEVALUE (Pointer, Pictures_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Pictures_Picture(sub,sub_l),List_Pictures_Picture);
      }
  return n-1;
}


static __inline__ int Parse_state_22 (void)	/* state 22 */
{ int n;
      n = 5; _Pictures_symbol = Picture_value;
      { ParseValue me;
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_Box(src_info, x, y, w, h);
      }
  return n-1;
}


static __inline__ int Parse_state_23 (void)	/* state 23 */
{ int n;
      n = 5; _Pictures_symbol = Picture_value;
      { ParseValue me;
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_Circle(src_info, x, y, w, h);
      }
  return n-1;
}

static int Parse_state_24 (SymbolSet followers);	/* state 24 */
static int Parse_state_25 (SymbolSet followers);	/* state 25 */

static __inline__ int Parse_state_26 (void)	/* state 26 */
{ int n;
      n = 7; _Pictures_symbol = Picture_value;
      { ParseValue me;
        Float  phi_2 = POP_PARSEVALUE (Float, Float);
        Float  phi_1 = POP_PARSEVALUE (Float, Float);
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_Arc(src_info, x, y, w, h, phi_1, phi_2);
      }
  return n-1;
}

static int Parse_state_27 (SymbolSet followers);	/* state 27 */
static int Parse_state_28 (SymbolSet followers);	/* state 28 */

static __inline__ int Parse_state_29 (void)	/* state 29 */
{ int n;
      n = 7; _Pictures_symbol = Picture_value;
      { ParseValue me;
        Bool  d2 = POP_PARSEVALUE (Bool, Bool);
        Bool  d1 = POP_PARSEVALUE (Bool, Bool);
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_Curve(src_info, x, y, w, h, d1, d2);
      }
  return n-1;
}


static __inline__ int Parse_state_30 (void)	/* state 30 */
{ int n;
      n = 5; _Pictures_symbol = Picture_value;
      { ParseValue me;
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_Line(src_info, x, y, w, h);
      }
  return n-1;
}

static int Parse_state_31 (SymbolSet followers);	/* state 31 */
static int Parse_state_32 (SymbolSet followers);	/* state 32 */

static __inline__ int Parse_state_33 (void)	/* state 33 */
{ int n;
      n = 7; _Pictures_symbol = Picture_value;
      { ParseValue me;
        Pictures_Direction  dir = POP_PARSEVALUE (Int, Pictures_Direction);
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_Arrow(src_info, x, y, w, h, dir);
      }
  return n-1;
}

static int Parse_state_34 (SymbolSet followers);	/* state 34 */
static int Parse_state_35 (SymbolSet followers);	/* state 35 */
static int Parse_state_36 (SymbolSet followers);	/* state 36 */

static __inline__ int Parse_state_37 (void)	/* state 37 */
{ int n;
      n = 8; _Pictures_symbol = Picture_value;
      { ParseValue me;
        Ident  font = POP_PARSEVALUE (Ident, Ident);
        String  text = POP_PARSEVALUE (String, String);
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_Text(src_info, x, y, w, h, text, font);
      }
  return n-1;
}


static __inline__ int Parse_state_38 (void)	/* state 38 */
{ int n;
      n = 5; _Pictures_symbol = Picture_value;
      { ParseValue me;
        List_Pictures_Direction  dirs = POP_PARSEVALUE (Pointer, List_Pictures_Direction);
        List_Pictures_Picture  sub = POP_PARSEVALUE (Pointer, List_Pictures_Picture);
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_OrBlock(src_info, x, y, w, h, sub, dirs);
      }
  return n-1;
}


static __inline__ int Parse_state_39 (void)	/* state 39 */
{ int n;
      n = 5; _Pictures_symbol = Picture_value;
      { ParseValue me;
        List_Pictures_Direction  dirs = POP_PARSEVALUE (Pointer, List_Pictures_Direction);
        List_Pictures_Picture  sub = POP_PARSEVALUE (Pointer, List_Pictures_Picture);
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_AndBlock(src_info, x, y, w, h, sub, dirs);
      }
  return n-1;
}

static int Parse_state_40 (SymbolSet followers);	/* state 40 */
static int Parse_state_41 (SymbolSet followers);	/* state 41 */
static int Parse_state_42 (SymbolSet followers);	/* state 42 */
static int Parse_state_43 (void);	/* state 43 */

static __inline__ int Parse_state_44 (void)	/* state 44 */
{ int n;
      n = 9; _Pictures_symbol = Picture_value;
      { ParseValue me;
        Bool  turn_left = POP_PARSEVALUE (Bool, Bool);
        Pictures_Picture  b = POP_PARSEVALUE (Pointer, Pictures_Picture);
        Pictures_Picture  a = POP_PARSEVALUE (Pointer, Pictures_Picture);
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_AltBlock(src_info, x, y, w, h, a, b, turn_left);
      }
  return n-1;
}


static __inline__ int Parse_state_45 (void)	/* state 45 */
{ int n;
      n = 5; _Pictures_symbol = Picture_value;
      { ParseValue me;
        List_Pictures_Picture  sub = POP_PARSEVALUE (Pointer, List_Pictures_Picture);
        Float  h = POP_PARSEVALUE (Float, Float);
        Float  w = POP_PARSEVALUE (Float, Float);
        Float  y = POP_PARSEVALUE (Float, Float);
        Float  x = POP_PARSEVALUE (Float, Float);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Picture");
        me->sub.PointerValue = Create_Pictures_Compound(src_info, x, y, w, h, sub);
      }
  return n-1;
}

static int Parse_state_46 (SymbolSet followers);	/* state 46 */

static __inline__ int Parse_state_47 (void)	/* state 47 */
{ int n;
      n = 2; _Pictures_symbol = OPTMORE_Picture_value;
      { /* optmore action */
        List_Pictures_Picture  pics_l = POP_PARSEVALUE (Pointer, List_Pictures_Picture);
        Pictures_Picture  pics = POP_PARSEVALUE (Pointer, Pictures_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Pictures_Picture(pics,pics_l),List_Pictures_Picture);
      }
  return n-1;
}

Pictures_Pictures Parse_state_Pictures_Pictures (void);	/* state 48 */

static __inline__ int Parse_state_49 (void)	/* state 49 */
{ int n;
      n = 1; _Pictures_symbol = Pictures_value;
      { ParseValue me;
        List_Pictures_Picture  pics = POP_PARSEVALUE (Pointer, List_Pictures_Picture);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Pictures_Pictures");
        me->sub.PointerValue = Create_Pictures_Pictures(src_info, pics);
        Decorate_Pictures(me->sub.PointerValue);
      }
  return n-1;
}

Pictures_Direction Parse_state_Pictures_Direction (void);	/* state 50 */
Pictures_Picture Parse_state_Pictures_Picture (void);	/* state 51 */
List_Pictures_Picture Parse_state_Pictures_MORE_Picture (void);	/* state 52 */

/* directors of state 0
   hole_Picture Floatsym 
 */
List_Pictures_Picture Parse_state_Pictures_OPTMORE_Picture (void)	/* state 0 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x10000040 };
  Int _followers[1];
  Int followers[1] = { 0x40000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(0);
    switch (_Pictures_symbol) {
    case OPTMORE_Picture_value:
      n = 1; break; /* accept OPTMORE_Picture  ->  . Picture OPTMORE_Picture  followers: Pictures_EOF  */
    case Floatsym_value:
      {
        static Int my_followers[] = { 0x12000040 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_46(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Picture  ->  .  followers: Pictures_EOF  */
      n = 0; _Pictures_symbol = OPTMORE_Picture_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Pictures_Picture);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Pictures_Picture")->sub.PointerValue;
}

/* directors of state 1
   Floatsym 
 */
static int Parse_state_1 (SymbolSet followers)	/* state 1 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_2(followers);
      }
  return n-1;
}

/* directors of state 2
   Floatsym 
 */
static int Parse_state_2 (SymbolSet followers)	/* state 2 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(followers);
      }
  return n-1;
}

/* directors of state 3
   Floatsym 
 */
static int Parse_state_3 (SymbolSet followers)	/* state 3 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(followers);
      }
  return n-1;
}

/* directors of state 4
   hole_MORE_Picture hole_Picture Floatsym ALTspacesym ANDspacesym ORspacesym openparsym trianglesym linesym arctopopsym arcsym circlesym rectanglesym 
 */
static int Parse_state_4 (SymbolSet followers)	/* state 4 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x30a8b7c0 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(4);
    switch (_Pictures_symbol) {
    case Floatsym_value:
      {
        static Int my_followers[] = { 0x30000040 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case ORspacesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_5(followers);
        break;
      }
    case ANDspacesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_15(followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_20(followers);
        break;
      }
    case rectanglesym_value:
      {
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case circlesym_value:
      {
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case arcsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_24(followers);
        break;
      }
    case arctopopsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(followers);
        break;
      }
    case linesym_value:
      {
        n = Parse_state_30();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case trianglesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_31(followers);
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(followers);
        break;
      }
    case ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL_value:
      {
        n = Parse_state_38();
        break;
      }
    case ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL_value:
      {
        n = Parse_state_39();
        break;
      }
    case ALTspacesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_40(followers);
        break;
      }
    case hole_MORE_Picture_value: HOLE_ACTION (0, "List_Picture");
    case MORE_Picture_value:
      {
        n = Parse_state_45();
        break;
      }
    default:
    /* default item:Picture  ->  Floatsym Floatsym Floatsym Floatsym .      followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 5
   hole_Picture Floatsym 
 */
static int Parse_state_5 (SymbolSet followers)	/* state 5 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x10000040 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(5);
    switch (_Pictures_symbol) {
    case Floatsym_value:
      {
        static Int my_followers[] = { 0x800003e };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_6(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL  ->  ORspacesym . Picture      followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = 0x99a5ba0 */
      InputError (SCAN_POSITION, TRUE, "Picture expected");
      PUSH_PARSEVALUE(Pointer,0,Pictures_Picture);
      _Pictures_symbol = Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 6
   hole_Direction Csym Dsym Usym Rsym Lsym 
 */
static int Parse_state_6 (SymbolSet followers)	/* state 6 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x800003e };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(6);
    switch (_Pictures_symbol) {
    case Lsym_value:
      {
        static Int my_followers[] = { 0x400000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_7();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Rsym_value:
      {
        static Int my_followers[] = { 0x400000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Usym_value:
      {
        static Int my_followers[] = { 0x400000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Dsym_value:
      {
        static Int my_followers[] = { 0x400000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_10();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Csym_value:
      {
        static Int my_followers[] = { 0x400000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_11();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Direction_value: HOLE_ACTION (0, "Direction");
    case Direction_value:
      {
        n = Parse_state_12(followers);
        break;
      }
    default:
    /* default item:ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL  ->  ORspacesym Picture .      followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 12
   ENDORsym 
 */
static int Parse_state_12 (SymbolSet followers)	/* state 12 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_13(followers);
      }
  return n-1;
}

/* directors of state 13
   ORspacesym 
 */
static int Parse_state_13 (SymbolSet followers)	/* state 13 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x200000 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(13);
    switch (_Pictures_symbol) {
    case ORspacesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_5(followers);
        break;
      }
    case ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL_value:
      {
        n = Parse_state_14();
        break;
      }
    default:
    /* default item:ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL  ->  ORspacesym Picture Direction ENDORsym . ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL  followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL expected");
      PUSH_PARSEVALUE(Pointer,0,List_Pictures_Picture);
      PUSH_PARSEVALUE(Pointer,0,List_Pictures_Direction);
      _Pictures_symbol = ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_NL_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 15
   hole_Picture Floatsym 
 */
static int Parse_state_15 (SymbolSet followers)	/* state 15 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x10000040 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(15);
    switch (_Pictures_symbol) {
    case Floatsym_value:
      {
        static Int my_followers[] = { 0x800003e };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_16(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL  ->  ANDspacesym . Picture   followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = 0x99a5ba0 */
      InputError (SCAN_POSITION, TRUE, "Picture expected");
      PUSH_PARSEVALUE(Pointer,0,Pictures_Picture);
      _Pictures_symbol = Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 16
   hole_Direction Csym Dsym Usym Rsym Lsym 
 */
static int Parse_state_16 (SymbolSet followers)	/* state 16 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x800003e };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(16);
    switch (_Pictures_symbol) {
    case Lsym_value:
      {
        static Int my_followers[] = { 0x1000000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_7();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Rsym_value:
      {
        static Int my_followers[] = { 0x1000000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Usym_value:
      {
        static Int my_followers[] = { 0x1000000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Dsym_value:
      {
        static Int my_followers[] = { 0x1000000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_10();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Csym_value:
      {
        static Int my_followers[] = { 0x1000000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_11();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Direction_value: HOLE_ACTION (0, "Direction");
    case Direction_value:
      {
        n = Parse_state_17(followers);
        break;
      }
    default:
    /* default item:ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL  ->  ANDspacesym Picture .   followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 17
   ENDANDsym 
 */
static int Parse_state_17 (SymbolSet followers)	/* state 17 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_18(followers);
      }
  return n-1;
}

/* directors of state 18
   ANDspacesym 
 */
static int Parse_state_18 (SymbolSet followers)	/* state 18 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x800000 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(18);
    switch (_Pictures_symbol) {
    case ANDspacesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_15(followers);
        break;
      }
    case ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL_value:
      {
        n = Parse_state_19();
        break;
      }
    default:
    /* default item:ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL  ->  ANDspacesym Picture Direction ENDANDsym . ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL    followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL expected");
      PUSH_PARSEVALUE(Pointer,0,List_Pictures_Picture);
      PUSH_PARSEVALUE(Pointer,0,List_Pictures_Direction);
      _Pictures_symbol = ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_NL_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 20
   hole_MORE_Picture hole_Picture Floatsym 
 */
static int Parse_state_20 (SymbolSet followers)	/* state 20 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x30000040 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(20);
    switch (_Pictures_symbol) {
    case Floatsym_value:
      {
        static Int my_followers[] = { 0x30000040 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_20(followers);
        break;
      }
    case hole_MORE_Picture_value: HOLE_ACTION (0, "List_Picture");
    case MORE_Picture_value:
      {
        n = Parse_state_21();
        break;
      }
    default:
    /* default item:MORE_Picture  ->  Picture .     followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 24
   Floatsym 
 */
static int Parse_state_24 (SymbolSet followers)	/* state 24 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25(followers);
      }
  return n-1;
}

/* directors of state 25
   Floatsym 
 */
static int Parse_state_25 (SymbolSet followers)	/* state 25 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26();
      }
  return n-1;
}

/* directors of state 27
   Boolsym 
 */
static int Parse_state_27 (SymbolSet followers)	/* state 27 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,Pictures_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_28(followers);
      }
  return n-1;
}

/* directors of state 28
   Boolsym 
 */
static int Parse_state_28 (SymbolSet followers)	/* state 28 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,Pictures_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_29();
      }
  return n-1;
}

/* directors of state 31
   eofillsym 
 */
static int Parse_state_31 (SymbolSet followers)	/* state 31 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_32(followers);
      }
  return n-1;
}

/* directors of state 32
   hole_Direction Csym Dsym Usym Rsym Lsym 
 */
static int Parse_state_32 (SymbolSet followers)	/* state 32 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x800003e };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(32);
    switch (_Pictures_symbol) {
    case Lsym_value:
      {
        n = Parse_state_7();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Rsym_value:
      {
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Usym_value:
      {
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Dsym_value:
      {
        n = Parse_state_10();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Csym_value:
      {
        n = Parse_state_11();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Direction_value: HOLE_ACTION (0, "Direction");
    case Direction_value:
      {
        n = Parse_state_33();
        break;
      }
    default:
    /* default item:Picture  ->  Floatsym Floatsym Floatsym Floatsym trianglesym eofillsym . Direction      followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = 0x99a04f0 */
      n = 0; _Pictures_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Pictures_Center,Pictures_Direction);
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 34
   Stringsym 
 */
static int Parse_state_34 (SymbolSet followers)	/* state 34 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,Pictures_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
      }
  return n-1;
}

/* directors of state 35
   closeparsym 
 */
static int Parse_state_35 (SymbolSet followers)	/* state 35 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_36(followers);
      }
  return n-1;
}

/* directors of state 36
   Identsym 
 */
static int Parse_state_36 (SymbolSet followers)	/* state 36 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Pictures_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_37();
      }
  return n-1;
}

/* directors of state 40
   hole_Picture Floatsym 
 */
static int Parse_state_40 (SymbolSet followers)	/* state 40 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x10000040 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(40);
    switch (_Pictures_symbol) {
    case Floatsym_value:
      {
        static Int my_followers[] = { 0x10000040 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_41(followers);
        break;
      }
    default:
    /* default item:Picture  ->  Floatsym Floatsym Floatsym Floatsym ALTspacesym . Picture Picture Boolsym ENDALTsym        followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = 0x99a5ba0 */
      InputError (SCAN_POSITION, TRUE, "Picture expected");
      PUSH_PARSEVALUE(Pointer,0,Pictures_Picture);
      _Pictures_symbol = Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 41
   hole_Picture Floatsym 
 */
static int Parse_state_41 (SymbolSet followers)	/* state 41 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x10000040 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(41);
    switch (_Pictures_symbol) {
    case Floatsym_value:
      {
        static Int my_followers[] = { 0x800 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_42(followers);
        break;
      }
    default:
    /* default item:Picture  ->  Floatsym Floatsym Floatsym Floatsym ALTspacesym Picture . Picture Boolsym ENDALTsym        followers: hole_OPTMORE_Picture Pictures_EOF hole_MORE_Picture hole_Picture Floatsym hole_Direction Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = 0x99a5ba0 */
      InputError (SCAN_POSITION, TRUE, "Picture expected");
      PUSH_PARSEVALUE(Pointer,0,Pictures_Picture);
      _Pictures_symbol = Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 42
   Boolsym 
 */
static int Parse_state_42 (SymbolSet followers)	/* state 42 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,Pictures_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_43();
      }
  return n-1;
}

static int Parse_state_43 (void)	/* state 43 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_44();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 46
   hole_OPTMORE_Picture hole_Picture Floatsym 
 */
static int Parse_state_46 (SymbolSet followers)	/* state 46 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x12000040 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(46);
    switch (_Pictures_symbol) {
    case Floatsym_value:
      {
        static Int my_followers[] = { 0x12000040 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_46(followers);
        break;
      }
    case hole_OPTMORE_Picture_value: HOLE_ACTION (0, "List_Picture");
    case OPTMORE_Picture_value:
      {
        n = Parse_state_47();
        break;
      }
    default:
    /* default item:OPTMORE_Picture  ->  Picture . OPTMORE_Picture  followers: Pictures_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Pictures_Picture);
      _Pictures_symbol = OPTMORE_Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 48
   hole_OPTMORE_Picture hole_Picture Floatsym 
 */
Pictures_Pictures Parse_state_Pictures_Pictures (void)	/* state 48 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x12000040 };
  Int _followers[1];
  Int followers[1] = { 0x40000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(48);
    switch (_Pictures_symbol) {
    case Pictures_value:
      n = 1; break; /* accept Pictures  ->  . OPTMORE_Picture followers: Pictures_EOF  */
    case Floatsym_value:
      {
        static Int my_followers[] = { 0x12000040 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_46(followers);
        break;
      }
    case hole_OPTMORE_Picture_value: HOLE_ACTION (0, "List_Picture");
    case OPTMORE_Picture_value:
      {
        n = Parse_state_49();
        break;
      }
    default:
    /* default item:Pictures  ->  . OPTMORE_Picture followers: Pictures_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Pictures_Picture);
      _Pictures_symbol = OPTMORE_Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Pictures_Pictures")->sub.PointerValue;
}

/* directors of state 50
   Csym Dsym Usym Rsym Lsym 
 */
Pictures_Direction Parse_state_Pictures_Direction (void)	/* state 50 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x3e };
  Int _followers[1];
  Int followers[1] = { 0x40000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(50);
    switch (_Pictures_symbol) {
    case Direction_value:
      n = 1; break; /* accept Direction  ->  . Csym   followers: Pictures_EOF  */
    case Lsym_value:
      {
        n = Parse_state_7();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Rsym_value:
      {
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Usym_value:
      {
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Dsym_value:
      {
        n = Parse_state_10();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Csym_value:
      {
        n = Parse_state_11();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Direction  ->  . Csym   followers: Pictures_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Csym expected");
      dont_shift = TRUE; _Pictures_symbol = Csym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Pictures_Direction")->sub.IntValue;
}

/* directors of state 51
   Floatsym 
 */
Pictures_Picture Parse_state_Pictures_Picture (void)	/* state 51 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  Int followers[1] = { 0x40000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(51);
    switch (_Pictures_symbol) {
    case Picture_value:
      n = 1; break; /* accept Picture  ->  . Floatsym Floatsym Floatsym Floatsym MORE_Picture followers: Pictures_EOF  */
    case Floatsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Picture  ->  . Floatsym Floatsym Floatsym Floatsym      followers: Pictures_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Floatsym expected");
      PUSH_PARSEVALUE(Float,0,Float);
      dont_shift = TRUE; _Pictures_symbol = Floatsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Pictures_Picture")->sub.PointerValue;
}

/* directors of state 52
   hole_Picture Floatsym 
 */
List_Pictures_Picture Parse_state_Pictures_MORE_Picture (void)	/* state 52 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x10000040 };
  Int _followers[1];
  Int followers[1] = { 0x40000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Pictures);
  _Pictures_symbol = _Pictures_token;
  do {
    REPORT(52);
    switch (_Pictures_symbol) {
    case MORE_Picture_value:
      n = 1; break; /* accept MORE_Picture  ->  . Picture MORE_Picture        followers: Pictures_EOF  */
    case Floatsym_value:
      {
        static Int my_followers[] = { 0x30000040 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Float,Pictures_lval.Floatsym_type,Float);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_20(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:MORE_Picture  ->  . Picture     followers: Pictures_EOF  */
/* nt = 0x99a5ba0 */
      InputError (SCAN_POSITION, TRUE, "Picture expected");
      PUSH_PARSEVALUE(Pointer,0,Pictures_Picture);
      _Pictures_symbol = Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Pictures_Picture")->sub.PointerValue;
}

