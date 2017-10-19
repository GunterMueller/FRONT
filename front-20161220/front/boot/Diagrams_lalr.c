#include "Diagrams_lalr.h"

#include "Diagrams_y.h"

typedef enum {
  Diagrams_NONSENSE,
  Lsym_value,
  Rsym_value,
  Usym_value,
  Dsym_value,
  Csym_value,
  Intsym_value,
  rectanglesym_value,
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
  hole_Diagrams_value,
  hole_Direction_value,
  hole_Picture_value,
  hole_MORE_Picture_value,
  Diagrams_EOF_value,
  OPTMORE_Picture_value,
  Diagrams_value,
  Direction_value,
  Picture_value,
  ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_value,
  ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_value,
  MORE_Picture_value,
  Diagrams_ERROR
} DiagramsSymbol;

static DiagramsSymbol _Diagrams_token;

static DiagramsSymbol _Diagrams_symbol;

#define NUM_TERMINALS 29

#define WORDS_IN_SET ((NUM_TERMINALS+BITSPERWORD-1)/BITSPERWORD)

static String Diagrams_symbol_names[] = {
  "Diagrams_NONSENSE",
  "Lsym",
  "Rsym",
  "Usym",
  "Dsym",
  "Csym",
  "Intsym",
  "rectanglesym",
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
  "hole_Diagrams",
  "hole_Direction",
  "hole_Picture",
  "hole_MORE_Picture",
  "Diagrams_EOF",
  "OPTMORE_Picture",
  "Diagrams",
  "Direction",
  "Picture",
  "ALT_ORspacesym_Picture_SEP_Direction_ENDORsym",
  "ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym",
  "MORE_Picture",
  "Diagrams_ERROR"
};

static DiagramsSymbol Diagrams_terminal_map[2*Diagrams_ERROR];

static void fill_terminal_map (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;
  Diagrams_terminal_map[0] = Diagrams_NONSENSE;
  Diagrams_terminal_map[Lsym-NONSENSE] = Lsym_value;
  Diagrams_terminal_map[Rsym-NONSENSE] = Rsym_value;
  Diagrams_terminal_map[Usym-NONSENSE] = Usym_value;
  Diagrams_terminal_map[Dsym-NONSENSE] = Dsym_value;
  Diagrams_terminal_map[Csym-NONSENSE] = Csym_value;
  Diagrams_terminal_map[Intsym-NONSENSE] = Intsym_value;
  Diagrams_terminal_map[rectanglesym-NONSENSE] = rectanglesym_value;
  Diagrams_terminal_map[arctopopsym-NONSENSE] = arctopopsym_value;
  Diagrams_terminal_map[Boolsym-NONSENSE] = Boolsym_value;
  Diagrams_terminal_map[linesym-NONSENSE] = linesym_value;
  Diagrams_terminal_map[trianglesym-NONSENSE] = trianglesym_value;
  Diagrams_terminal_map[eofillsym-NONSENSE] = eofillsym_value;
  Diagrams_terminal_map[openparsym-NONSENSE] = openparsym_value;
  Diagrams_terminal_map[Stringsym-NONSENSE] = Stringsym_value;
  Diagrams_terminal_map[closeparsym-NONSENSE] = closeparsym_value;
  Diagrams_terminal_map[Identsym-NONSENSE] = Identsym_value;
  Diagrams_terminal_map[ALTspacesym-NONSENSE] = ALTspacesym_value;
  Diagrams_terminal_map[ENDALTsym-NONSENSE] = ENDALTsym_value;
  Diagrams_terminal_map[ORspacesym-NONSENSE] = ORspacesym_value;
  Diagrams_terminal_map[ENDORsym-NONSENSE] = ENDORsym_value;
  Diagrams_terminal_map[ANDspacesym-NONSENSE] = ANDspacesym_value;
  Diagrams_terminal_map[ENDANDsym-NONSENSE] = ENDANDsym_value;
  Diagrams_terminal_map[hole_OPTMORE_Picture-NONSENSE] = hole_OPTMORE_Picture_value;
  Diagrams_terminal_map[hole_Diagrams-NONSENSE] = hole_Diagrams_value;
  Diagrams_terminal_map[hole_Direction-NONSENSE] = hole_Direction_value;
  Diagrams_terminal_map[hole_Picture-NONSENSE] = hole_Picture_value;
  Diagrams_terminal_map[hole_MORE_Picture-NONSENSE] = hole_MORE_Picture_value;
}

extern int Diagrams_lex(void);
#define SHIFT() { _Diagrams_token = Diagrams_lex(); if (_Diagrams_token==0) _Diagrams_token = Diagrams_EOF_value; else _Diagrams_token = Diagrams_terminal_map[_Diagrams_token-NONSENSE]; }
#define HOLE_ACTION(term,s)
#ifdef TRACE_Diagrams_PARSE
#define REPORT(n) \
    printf ("State %d,	symbol %s,	token %s\n", n, Diagrams_symbol_names[_Diagrams_symbol], Diagrams_symbol_names[_Diagrams_token]);
#else
#define REPORT(n)
#endif
List_Diagrams_Picture Parse_state_Diagrams_OPTMORE_Picture (void);	/* state 0 */
static int Parse_state_1 (SymbolSet followers);	/* state 1 */
static int Parse_state_2 (SymbolSet followers);	/* state 2 */
static int Parse_state_3 (SymbolSet followers);	/* state 3 */
static int Parse_state_4 (SymbolSet followers);	/* state 4 */
static int Parse_state_5 (SymbolSet followers);	/* state 5 */
static int Parse_state_6 (SymbolSet followers);	/* state 6 */

static inline int Parse_state_7 (void)	/* state 7 */
{ int n;
      n = 1; _Diagrams_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Diagrams_Left,Diagrams_Direction);
  return n-1;
}


static inline int Parse_state_8 (void)	/* state 8 */
{ int n;
      n = 1; _Diagrams_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Diagrams_Right,Diagrams_Direction);
  return n-1;
}


static inline int Parse_state_9 (void)	/* state 9 */
{ int n;
      n = 1; _Diagrams_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Diagrams_Up,Diagrams_Direction);
  return n-1;
}


static inline int Parse_state_10 (void)	/* state 10 */
{ int n;
      n = 1; _Diagrams_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Diagrams_Down,Diagrams_Direction);
  return n-1;
}


static inline int Parse_state_11 (void)	/* state 11 */
{ int n;
      n = 1; _Diagrams_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Diagrams_Center,Diagrams_Direction);
  return n-1;
}

static int Parse_state_12 (SymbolSet followers);	/* state 12 */
static int Parse_state_13 (SymbolSet followers);	/* state 13 */

static inline int Parse_state_14 (void)	/* state 14 */
{ int n;
      n = 5; _Diagrams_symbol = ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_value;
      { /* alt action */
        List_Diagrams_Direction  dirs_l = POP_PARSEVALUE (Pointer, List_Diagrams_Direction);
        List_Diagrams_Picture  sub_l = POP_PARSEVALUE (Pointer, List_Diagrams_Picture);
        Diagrams_Direction  dirs = POP_PARSEVALUE (Int, Diagrams_Direction);
        Diagrams_Picture  sub = POP_PARSEVALUE (Pointer, Diagrams_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Diagrams_Picture(sub,sub_l),List_Diagrams_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Diagrams_Direction(dirs,dirs_l),List_Diagrams_Direction);
      }
  return n-1;
}

static int Parse_state_15 (SymbolSet followers);	/* state 15 */
static int Parse_state_16 (SymbolSet followers);	/* state 16 */
static int Parse_state_17 (SymbolSet followers);	/* state 17 */
static int Parse_state_18 (SymbolSet followers);	/* state 18 */

static inline int Parse_state_19 (void)	/* state 19 */
{ int n;
      n = 5; _Diagrams_symbol = ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_value;
      { /* alt action */
        List_Diagrams_Direction  dirs_l = POP_PARSEVALUE (Pointer, List_Diagrams_Direction);
        List_Diagrams_Picture  sub_l = POP_PARSEVALUE (Pointer, List_Diagrams_Picture);
        Diagrams_Direction  dirs = POP_PARSEVALUE (Int, Diagrams_Direction);
        Diagrams_Picture  sub = POP_PARSEVALUE (Pointer, Diagrams_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Diagrams_Picture(sub,sub_l),List_Diagrams_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Diagrams_Direction(dirs,dirs_l),List_Diagrams_Direction);
      }
  return n-1;
}

static int Parse_state_20 (SymbolSet followers);	/* state 20 */

static inline int Parse_state_21 (void)	/* state 21 */
{ int n;
      n = 2; _Diagrams_symbol = MORE_Picture_value;
      { /* more action */
        List_Diagrams_Picture  sub_l = POP_PARSEVALUE (Pointer, List_Diagrams_Picture);
        Diagrams_Picture  sub = POP_PARSEVALUE (Pointer, Diagrams_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Diagrams_Picture(sub,sub_l),List_Diagrams_Picture);
      }
  return n-1;
}


static inline int Parse_state_22 (void)	/* state 22 */
{ int n;
      n = 5; _Diagrams_symbol = Picture_value;
      { ParseValue me;
        Int  h = POP_PARSEVALUE (Int, Int);
        Int  w = POP_PARSEVALUE (Int, Int);
        Int  y = POP_PARSEVALUE (Int, Int);
        Int  x = POP_PARSEVALUE (Int, Int);
        SrcInfo  src_info;
        src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Diagrams_Picture");
        me->sub.PointerValue = Create_Diagrams_Box(src_info, x, y, w, h);
      }
  return n-1;
}

static int Parse_state_23 (SymbolSet followers);	/* state 23 */
static int Parse_state_24 (SymbolSet followers);	/* state 24 */

static inline int Parse_state_25 (void)	/* state 25 */
{ int n;
      n = 7; _Diagrams_symbol = Picture_value;
      { ParseValue me;
        Bool  d2 = POP_PARSEVALUE (Bool, Bool);
        Bool  d1 = POP_PARSEVALUE (Bool, Bool);
        Int  h = POP_PARSEVALUE (Int, Int);
        Int  w = POP_PARSEVALUE (Int, Int);
        Int  y = POP_PARSEVALUE (Int, Int);
        Int  x = POP_PARSEVALUE (Int, Int);
        SrcInfo  src_info;
        src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Diagrams_Picture");
        me->sub.PointerValue = Create_Diagrams_Curve(src_info, x, y, w, h, d1, d2);
      }
  return n-1;
}


static inline int Parse_state_26 (void)	/* state 26 */
{ int n;
      n = 5; _Diagrams_symbol = Picture_value;
      { ParseValue me;
        Int  h = POP_PARSEVALUE (Int, Int);
        Int  w = POP_PARSEVALUE (Int, Int);
        Int  y = POP_PARSEVALUE (Int, Int);
        Int  x = POP_PARSEVALUE (Int, Int);
        SrcInfo  src_info;
        src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Diagrams_Picture");
        me->sub.PointerValue = Create_Diagrams_Line(src_info, x, y, w, h);
      }
  return n-1;
}

static int Parse_state_27 (SymbolSet followers);	/* state 27 */
static int Parse_state_28 (SymbolSet followers);	/* state 28 */

static inline int Parse_state_29 (void)	/* state 29 */
{ int n;
      n = 7; _Diagrams_symbol = Picture_value;
      { ParseValue me;
        Diagrams_Direction  dir = POP_PARSEVALUE (Int, Diagrams_Direction);
        Int  h = POP_PARSEVALUE (Int, Int);
        Int  w = POP_PARSEVALUE (Int, Int);
        Int  y = POP_PARSEVALUE (Int, Int);
        Int  x = POP_PARSEVALUE (Int, Int);
        SrcInfo  src_info;
        src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Diagrams_Picture");
        me->sub.PointerValue = Create_Diagrams_Arrow(src_info, x, y, w, h, dir);
      }
  return n-1;
}

static int Parse_state_30 (SymbolSet followers);	/* state 30 */
static int Parse_state_31 (SymbolSet followers);	/* state 31 */
static int Parse_state_32 (SymbolSet followers);	/* state 32 */

static inline int Parse_state_33 (void)	/* state 33 */
{ int n;
      n = 8; _Diagrams_symbol = Picture_value;
      { ParseValue me;
        Ident  font = POP_PARSEVALUE (Ident, Ident);
        String  text = POP_PARSEVALUE (String, String);
        Int  h = POP_PARSEVALUE (Int, Int);
        Int  w = POP_PARSEVALUE (Int, Int);
        Int  y = POP_PARSEVALUE (Int, Int);
        Int  x = POP_PARSEVALUE (Int, Int);
        SrcInfo  src_info;
        src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Diagrams_Picture");
        me->sub.PointerValue = Create_Diagrams_Text(src_info, x, y, w, h, text, font);
      }
  return n-1;
}


static inline int Parse_state_34 (void)	/* state 34 */
{ int n;
      n = 5; _Diagrams_symbol = Picture_value;
      { ParseValue me;
        List_Diagrams_Direction  dirs = POP_PARSEVALUE (Pointer, List_Diagrams_Direction);
        List_Diagrams_Picture  sub = POP_PARSEVALUE (Pointer, List_Diagrams_Picture);
        Int  h = POP_PARSEVALUE (Int, Int);
        Int  w = POP_PARSEVALUE (Int, Int);
        Int  y = POP_PARSEVALUE (Int, Int);
        Int  x = POP_PARSEVALUE (Int, Int);
        SrcInfo  src_info;
        src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Diagrams_Picture");
        me->sub.PointerValue = Create_Diagrams_OrBlock(src_info, x, y, w, h, sub, dirs);
      }
  return n-1;
}


static inline int Parse_state_35 (void)	/* state 35 */
{ int n;
      n = 5; _Diagrams_symbol = Picture_value;
      { ParseValue me;
        List_Diagrams_Direction  dirs = POP_PARSEVALUE (Pointer, List_Diagrams_Direction);
        List_Diagrams_Picture  sub = POP_PARSEVALUE (Pointer, List_Diagrams_Picture);
        Int  h = POP_PARSEVALUE (Int, Int);
        Int  w = POP_PARSEVALUE (Int, Int);
        Int  y = POP_PARSEVALUE (Int, Int);
        Int  x = POP_PARSEVALUE (Int, Int);
        SrcInfo  src_info;
        src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Diagrams_Picture");
        me->sub.PointerValue = Create_Diagrams_AndBlock(src_info, x, y, w, h, sub, dirs);
      }
  return n-1;
}

static int Parse_state_36 (SymbolSet followers);	/* state 36 */
static int Parse_state_37 (SymbolSet followers);	/* state 37 */
static int Parse_state_38 (SymbolSet followers);	/* state 38 */
static int Parse_state_39 (void);	/* state 39 */

static inline int Parse_state_40 (void)	/* state 40 */
{ int n;
      n = 9; _Diagrams_symbol = Picture_value;
      { ParseValue me;
        Bool  turn_left = POP_PARSEVALUE (Bool, Bool);
        Diagrams_Picture  b = POP_PARSEVALUE (Pointer, Diagrams_Picture);
        Diagrams_Picture  a = POP_PARSEVALUE (Pointer, Diagrams_Picture);
        Int  h = POP_PARSEVALUE (Int, Int);
        Int  w = POP_PARSEVALUE (Int, Int);
        Int  y = POP_PARSEVALUE (Int, Int);
        Int  x = POP_PARSEVALUE (Int, Int);
        SrcInfo  src_info;
        src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Diagrams_Picture");
        me->sub.PointerValue = Create_Diagrams_AltBlock(src_info, x, y, w, h, a, b, turn_left);
      }
  return n-1;
}


static inline int Parse_state_41 (void)	/* state 41 */
{ int n;
      n = 5; _Diagrams_symbol = Picture_value;
      { ParseValue me;
        List_Diagrams_Picture  sub = POP_PARSEVALUE (Pointer, List_Diagrams_Picture);
        Int  h = POP_PARSEVALUE (Int, Int);
        Int  w = POP_PARSEVALUE (Int, Int);
        Int  y = POP_PARSEVALUE (Int, Int);
        Int  x = POP_PARSEVALUE (Int, Int);
        SrcInfo  src_info;
        src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Diagrams_Picture");
        me->sub.PointerValue = Create_Diagrams_Compound(src_info, x, y, w, h, sub);
      }
  return n-1;
}

static int Parse_state_42 (SymbolSet followers);	/* state 42 */

static inline int Parse_state_43 (void)	/* state 43 */
{ int n;
      n = 2; _Diagrams_symbol = OPTMORE_Picture_value;
      { /* optmore action */
        List_Diagrams_Picture  pics_l = POP_PARSEVALUE (Pointer, List_Diagrams_Picture);
        Diagrams_Picture  pics = POP_PARSEVALUE (Pointer, Diagrams_Picture);
        PUSH_PARSEVALUE(Pointer,Create_List_Diagrams_Picture(pics,pics_l),List_Diagrams_Picture);
      }
  return n-1;
}

Diagrams_Diagrams Parse_state_Diagrams_Diagrams (void);	/* state 44 */

static inline int Parse_state_45 (void)	/* state 45 */
{ int n;
      n = 1; _Diagrams_symbol = Diagrams_value;
      { ParseValue me;
        List_Diagrams_Picture  pics = POP_PARSEVALUE (Pointer, List_Diagrams_Picture);
        SrcInfo  src_info;
        src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Diagrams_Diagrams");
        me->sub.PointerValue = Create_Diagrams_Diagrams(src_info, pics);
        Decorate_Diagrams(me->sub.PointerValue);
      }
  return n-1;
}

Diagrams_Direction Parse_state_Diagrams_Direction (void);	/* state 46 */
Diagrams_Picture Parse_state_Diagrams_Picture (void);	/* state 47 */
List_Diagrams_Picture Parse_state_Diagrams_MORE_Picture (void);	/* state 48 */

List_Diagrams_Picture Parse_state_Diagrams_OPTMORE_Picture (void)	/* state 0 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  Int followers[1] = { 0x10000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(0);
    switch (_Diagrams_symbol) {
    case OPTMORE_Picture_value:
      n = 1; break; /* accept OPTMORE_Picture  ->  . Picture OPTMORE_Picture      followers: Diagrams_EOF  */
    case Intsym_value:
      {
        static Int my_followers[] = { 0x40 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
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
    /* default item:OPTMORE_Picture  ->  .  followers: Diagrams_EOF  */
      n = 0; _Diagrams_symbol = OPTMORE_Picture_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Diagrams_Picture);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Diagrams_Picture")->sub.PointerValue;
}

static int Parse_state_1 (SymbolSet followers)	/* state 1 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_2(followers);
      }
  return n-1;
}

static int Parse_state_2 (SymbolSet followers)	/* state 2 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(followers);
      }
  return n-1;
}

static int Parse_state_3 (SymbolSet followers)	/* state 3 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(followers);
      }
  return n-1;
}

static int Parse_state_4 (SymbolSet followers)	/* state 4 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x2a2dc0 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(4);
    switch (_Diagrams_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x40 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
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
    case arctopopsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_23(followers);
        break;
      }
    case linesym_value:
      {
        n = Parse_state_26();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case trianglesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(followers);
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_30(followers);
        break;
      }
    case ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_value:
      {
        n = Parse_state_34();
        break;
      }
    case ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_value:
      {
        n = Parse_state_35();
        break;
      }
    case ALTspacesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_36(followers);
        break;
      }
    case hole_MORE_Picture_value: HOLE_ACTION (0, "List_Picture");
    case MORE_Picture_value:
      {
        n = Parse_state_41();
        break;
      }
    default:
    /* default item:Picture  ->  Intsym Intsym Intsym Intsym .      followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_5 (SymbolSet followers)	/* state 5 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(5);
    switch (_Diagrams_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x3e };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
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
    /* default item:ALT_ORspacesym_Picture_SEP_Direction_ENDORsym  ->  ORspacesym . Picture followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = 0x8168070 */
      InputError (SCAN_POSITION, TRUE, "Picture expected");
      PUSH_PARSEVALUE(Pointer,0,Diagrams_Picture);
      _Diagrams_symbol = Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_6 (SymbolSet followers)	/* state 6 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x3e };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(6);
    switch (_Diagrams_symbol) {
    case Lsym_value:
      {
        static Int my_followers[] = { 0x100000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_7();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Rsym_value:
      {
        static Int my_followers[] = { 0x100000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Usym_value:
      {
        static Int my_followers[] = { 0x100000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Dsym_value:
      {
        static Int my_followers[] = { 0x100000 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        n = Parse_state_10();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Csym_value:
      {
        static Int my_followers[] = { 0x100000 };
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
    /* default item:ALT_ORspacesym_Picture_SEP_Direction_ENDORsym  ->  ORspacesym Picture . followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
      break;
    }
  } while (n==0);
  return n-1;
}

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

static int Parse_state_13 (SymbolSet followers)	/* state 13 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x80000 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(13);
    switch (_Diagrams_symbol) {
    case ORspacesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_5(followers);
        break;
      }
    case ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_value:
      {
        n = Parse_state_14();
        break;
      }
    default:
    /* default item:ALT_ORspacesym_Picture_SEP_Direction_ENDORsym  ->  ORspacesym Picture Direction ENDORsym . ALT_ORspacesym_Picture_SEP_Direction_ENDORsym        followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_ORspacesym_Picture_SEP_Direction_ENDORsym expected");
      PUSH_PARSEVALUE(Pointer,0,List_Diagrams_Picture);
      PUSH_PARSEVALUE(Pointer,0,List_Diagrams_Direction);
      _Diagrams_symbol = ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_15 (SymbolSet followers)	/* state 15 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(15);
    switch (_Diagrams_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x3e };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
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
    /* default item:ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym  ->  ANDspacesym . Picture      followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = 0x8168070 */
      InputError (SCAN_POSITION, TRUE, "Picture expected");
      PUSH_PARSEVALUE(Pointer,0,Diagrams_Picture);
      _Diagrams_symbol = Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_16 (SymbolSet followers)	/* state 16 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x3e };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(16);
    switch (_Diagrams_symbol) {
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
        n = Parse_state_17(followers);
        break;
      }
    default:
    /* default item:ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym  ->  ANDspacesym Picture .      followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
      break;
    }
  } while (n==0);
  return n-1;
}

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

static int Parse_state_18 (SymbolSet followers)	/* state 18 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x200000 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(18);
    switch (_Diagrams_symbol) {
    case ANDspacesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_15(followers);
        break;
      }
    case ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_value:
      {
        n = Parse_state_19();
        break;
      }
    default:
    /* default item:ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym  ->  ANDspacesym Picture Direction ENDANDsym . ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym  followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym expected");
      PUSH_PARSEVALUE(Pointer,0,List_Diagrams_Picture);
      PUSH_PARSEVALUE(Pointer,0,List_Diagrams_Direction);
      _Diagrams_symbol = ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_20 (SymbolSet followers)	/* state 20 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(20);
    switch (_Diagrams_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x40 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
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
    /* default item:MORE_Picture  ->  Picture .     followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_23 (SymbolSet followers)	/* state 23 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,Diagrams_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_24(followers);
      }
  return n-1;
}

static int Parse_state_24 (SymbolSet followers)	/* state 24 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,Diagrams_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25();
      }
  return n-1;
}

static int Parse_state_27 (SymbolSet followers)	/* state 27 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_28(followers);
      }
  return n-1;
}

static int Parse_state_28 (SymbolSet followers)	/* state 28 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x3e };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(28);
    switch (_Diagrams_symbol) {
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
        n = Parse_state_29();
        break;
      }
    default:
    /* default item:Picture  ->  Intsym Intsym Intsym Intsym trianglesym eofillsym . Direction      followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = 0x8162af8 */
      n = 0; _Diagrams_symbol = Direction_value;
      PUSH_PARSEVALUE(Int,Diagrams_Center,Diagrams_Direction);
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_30 (SymbolSet followers)	/* state 30 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,Diagrams_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_31(followers);
      }
  return n-1;
}

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

static int Parse_state_32 (SymbolSet followers)	/* state 32 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Diagrams_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
      }
  return n-1;
}

static int Parse_state_36 (SymbolSet followers)	/* state 36 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(36);
    switch (_Diagrams_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x40 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_37(followers);
        break;
      }
    default:
    /* default item:Picture  ->  Intsym Intsym Intsym Intsym ALTspacesym . Picture Picture Boolsym ENDALTsym        followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = 0x8168070 */
      InputError (SCAN_POSITION, TRUE, "Picture expected");
      PUSH_PARSEVALUE(Pointer,0,Diagrams_Picture);
      _Diagrams_symbol = Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_37 (SymbolSet followers)	/* state 37 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(37);
    switch (_Diagrams_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x200 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Picture_value: HOLE_ACTION (0, "Picture");
    case Picture_value:
      {
        n = Parse_state_38(followers);
        break;
      }
    default:
    /* default item:Picture  ->  Intsym Intsym Intsym Intsym ALTspacesym Picture . Picture Boolsym ENDALTsym        followers: Intsym Diagrams_EOF Csym Dsym Usym Rsym Lsym Boolsym  */
/* nt = 0x8168070 */
      InputError (SCAN_POSITION, TRUE, "Picture expected");
      PUSH_PARSEVALUE(Pointer,0,Diagrams_Picture);
      _Diagrams_symbol = Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_38 (SymbolSet followers)	/* state 38 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,Diagrams_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39();
      }
  return n-1;
}

static int Parse_state_39 (void)	/* state 39 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_40();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

static int Parse_state_42 (SymbolSet followers)	/* state 42 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(42);
    switch (_Diagrams_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x40 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
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
    case hole_OPTMORE_Picture_value: HOLE_ACTION (0, "List_Picture");
    case OPTMORE_Picture_value:
      {
        n = Parse_state_43();
        break;
      }
    default:
    /* default item:OPTMORE_Picture  ->  Picture . OPTMORE_Picture  followers: Diagrams_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Diagrams_Picture);
      _Diagrams_symbol = OPTMORE_Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

Diagrams_Diagrams Parse_state_Diagrams_Diagrams (void)	/* state 44 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  Int followers[1] = { 0x10000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(44);
    switch (_Diagrams_symbol) {
    case Diagrams_value:
      n = 1; break; /* accept Diagrams  ->  . OPTMORE_Picture followers: Diagrams_EOF  */
    case Intsym_value:
      {
        static Int my_followers[] = { 0x40 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
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
    case hole_OPTMORE_Picture_value: HOLE_ACTION (0, "List_Picture");
    case OPTMORE_Picture_value:
      {
        n = Parse_state_45();
        break;
      }
    default:
    /* default item:Diagrams  ->  . OPTMORE_Picture followers: Diagrams_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Diagrams_Picture);
      _Diagrams_symbol = OPTMORE_Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Diagrams_Diagrams")->sub.PointerValue;
}

Diagrams_Direction Parse_state_Diagrams_Direction (void)	/* state 46 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x3e };
  Int _followers[1];
  Int followers[1] = { 0x10000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(46);
    switch (_Diagrams_symbol) {
    case Direction_value:
      n = 1; break; /* accept Direction  ->  . Csym   followers: Diagrams_EOF  */
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
    /* default item:Direction  ->  . Csym   followers: Diagrams_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Csym expected");
      dont_shift = TRUE; _Diagrams_symbol = Csym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Diagrams_Direction")->sub.IntValue;
}

Diagrams_Picture Parse_state_Diagrams_Picture (void)	/* state 47 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  Int followers[1] = { 0x10000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(47);
    switch (_Diagrams_symbol) {
    case Picture_value:
      n = 1; break; /* accept Picture  ->  . Intsym Intsym Intsym Intsym MORE_Picture followers: Diagrams_EOF  */
    case Intsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Picture  ->  . Intsym Intsym Intsym Intsym      followers: Diagrams_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Intsym expected");
      PUSH_PARSEVALUE(Int,0,Int);
      dont_shift = TRUE; _Diagrams_symbol = Intsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Diagrams_Picture")->sub.PointerValue;
}

List_Diagrams_Picture Parse_state_Diagrams_MORE_Picture (void)	/* state 48 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[1] = { 0x40 };
  Int _followers[1];
  Int followers[1] = { 0x10000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 1);
  DELETE_UNTIL (_followers, Diagrams);
  _Diagrams_symbol = _Diagrams_token;
  do {
    REPORT(48);
    switch (_Diagrams_symbol) {
    case MORE_Picture_value:
      n = 1; break; /* accept MORE_Picture  ->  . Picture MORE_Picture        followers: Diagrams_EOF  */
    case Intsym_value:
      {
        static Int my_followers[] = { 0x40 };
        unite_symbol_sets (_followers, my_followers, followers, 1);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Diagrams_lval.Intsym_type,Int);
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
    /* default item:MORE_Picture  ->  . Picture     followers: Diagrams_EOF  */
/* nt = 0x8168070 */
      InputError (SCAN_POSITION, TRUE, "Picture expected");
      PUSH_PARSEVALUE(Pointer,0,Diagrams_Picture);
      _Diagrams_symbol = Picture_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Diagrams_Picture")->sub.PointerValue;
}

