#include "Lalr_lalr.h"

#include "Lalr_y.h"

typedef enum {
  Lalr_NONSENSE,
  GRAMMARsym_value,
  STATESsym_value,
  Identsym_value,
  minusgreaterthansym_value,
  semicolonsym_value,
  emptycolonsym_value,
  firstcolonsym_value,
  NON_EMPTYsym_value,
  EMPTYsym_value,
  statesym_value,
  Intsym_value,
  transitionssym_value,
  dotsym_value,
  equalsgreaterthansym_value,
  questionmarksym_value,
  followerscolonsym_value,
  spacesym_value,
  hole_OPTMORE_Production_value,
  hole_OPTMORE_LR_state_value,
  hole_Lalr_value,
  hole_ProdRhs_value,
  hole_Emptiness_value,
  hole_TermSet_value,
  hole_Production_value,
  hole_LR_Symbol_value,
  hole_LR_Symbols_value,
  hole_MORE_Item_value,
  hole_OPTMORE_Transition_value,
  hole_LR_state_value,
  hole_OPTMORE_LR_Symbol_value,
  hole_Item_value,
  hole_MORE_Identsym_spacesym_value,
  hole_Transition_value,
  Lalr_EOF_value,
  OPTMORE_Production_value,
  OPTMORE_LR_state_value,
  Lalr_value,
  ProdRhs_value,
  Emptiness_value,
  TermSet_value,
  Production_value,
  OPT_LR_Symbols_value,
  OPT_questionmarksym_value,
  LR_Symbol_value,
  LR_Symbols_value,
  MORE_Item_value,
  OPTMORE_Transition_value,
  LR_state_value,
  OPTMORE_LR_Symbol_value,
  OPT_followerscolonsym_TermSet_value,
  Item_value,
  MORE_Identsym_spacesym_value,
  Transition_value,
  Lalr_ERROR
} LalrSymbol;

static LalrSymbol _Lalr_token;

static LalrSymbol _Lalr_symbol;

#define NUM_TERMINALS 35

#define WORDS_IN_SET ((NUM_TERMINALS+BITSPERWORD-1)/BITSPERWORD)

static String Lalr_symbol_names[] = {
  "Lalr_NONSENSE",
  "GRAMMARsym",
  "STATESsym",
  "Identsym",
  "minusgreaterthansym",
  "semicolonsym",
  "emptycolonsym",
  "firstcolonsym",
  "NON_EMPTYsym",
  "EMPTYsym",
  "statesym",
  "Intsym",
  "transitionssym",
  "dotsym",
  "equalsgreaterthansym",
  "questionmarksym",
  "followerscolonsym",
  "spacesym",
  "hole_OPTMORE_Production",
  "hole_OPTMORE_LR_state",
  "hole_Lalr",
  "hole_ProdRhs",
  "hole_Emptiness",
  "hole_TermSet",
  "hole_Production",
  "hole_LR_Symbol",
  "hole_LR_Symbols",
  "hole_MORE_Item",
  "hole_OPTMORE_Transition",
  "hole_LR_state",
  "hole_OPTMORE_LR_Symbol",
  "hole_Item",
  "hole_MORE_Identsym_spacesym",
  "hole_Transition",
  "Lalr_EOF",
  "OPTMORE_Production",
  "OPTMORE_LR_state",
  "Lalr",
  "ProdRhs",
  "Emptiness",
  "TermSet",
  "Production",
  "OPT_LR_Symbols",
  "OPT_questionmarksym",
  "LR_Symbol",
  "LR_Symbols",
  "MORE_Item",
  "OPTMORE_Transition",
  "LR_state",
  "OPTMORE_LR_Symbol",
  "OPT_followerscolonsym_TermSet",
  "Item",
  "MORE_Identsym_spacesym",
  "Transition",
  "Lalr_ERROR"
};

static LalrSymbol Lalr_terminal_map[2*Lalr_ERROR];

static void fill_terminal_map (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;
  Lalr_terminal_map[0] = Lalr_NONSENSE;
  Lalr_terminal_map[GRAMMARsym-NONSENSE] = GRAMMARsym_value;
  Lalr_terminal_map[STATESsym-NONSENSE] = STATESsym_value;
  Lalr_terminal_map[Identsym-NONSENSE] = Identsym_value;
  Lalr_terminal_map[minusgreaterthansym-NONSENSE] = minusgreaterthansym_value;
  Lalr_terminal_map[semicolonsym-NONSENSE] = semicolonsym_value;
  Lalr_terminal_map[emptycolonsym-NONSENSE] = emptycolonsym_value;
  Lalr_terminal_map[firstcolonsym-NONSENSE] = firstcolonsym_value;
  Lalr_terminal_map[NON_EMPTYsym-NONSENSE] = NON_EMPTYsym_value;
  Lalr_terminal_map[EMPTYsym-NONSENSE] = EMPTYsym_value;
  Lalr_terminal_map[statesym-NONSENSE] = statesym_value;
  Lalr_terminal_map[Intsym-NONSENSE] = Intsym_value;
  Lalr_terminal_map[transitionssym-NONSENSE] = transitionssym_value;
  Lalr_terminal_map[dotsym-NONSENSE] = dotsym_value;
  Lalr_terminal_map[equalsgreaterthansym-NONSENSE] = equalsgreaterthansym_value;
  Lalr_terminal_map[questionmarksym-NONSENSE] = questionmarksym_value;
  Lalr_terminal_map[followerscolonsym-NONSENSE] = followerscolonsym_value;
  Lalr_terminal_map[spacesym-NONSENSE] = spacesym_value;
  Lalr_terminal_map[hole_OPTMORE_Production-NONSENSE] = hole_OPTMORE_Production_value;
  Lalr_terminal_map[hole_OPTMORE_LR_state-NONSENSE] = hole_OPTMORE_LR_state_value;
  Lalr_terminal_map[hole_Lalr-NONSENSE] = hole_Lalr_value;
  Lalr_terminal_map[hole_ProdRhs-NONSENSE] = hole_ProdRhs_value;
  Lalr_terminal_map[hole_Emptiness-NONSENSE] = hole_Emptiness_value;
  Lalr_terminal_map[hole_TermSet-NONSENSE] = hole_TermSet_value;
  Lalr_terminal_map[hole_Production-NONSENSE] = hole_Production_value;
  Lalr_terminal_map[hole_LR_Symbol-NONSENSE] = hole_LR_Symbol_value;
  Lalr_terminal_map[hole_LR_Symbols-NONSENSE] = hole_LR_Symbols_value;
  Lalr_terminal_map[hole_MORE_Item-NONSENSE] = hole_MORE_Item_value;
  Lalr_terminal_map[hole_OPTMORE_Transition-NONSENSE] = hole_OPTMORE_Transition_value;
  Lalr_terminal_map[hole_LR_state-NONSENSE] = hole_LR_state_value;
  Lalr_terminal_map[hole_OPTMORE_LR_Symbol-NONSENSE] = hole_OPTMORE_LR_Symbol_value;
  Lalr_terminal_map[hole_Item-NONSENSE] = hole_Item_value;
  Lalr_terminal_map[hole_MORE_Identsym_spacesym-NONSENSE] = hole_MORE_Identsym_spacesym_value;
  Lalr_terminal_map[hole_Transition-NONSENSE] = hole_Transition_value;
}

extern int Lalr_lex(void);
#define SHIFT() { _Lalr_token = Lalr_lex(); if (_Lalr_token==0) _Lalr_token = Lalr_EOF_value; else _Lalr_token = Lalr_terminal_map[_Lalr_token-NONSENSE]; }
#define HOLE_ACTION(term,s) PUSH_PARSEVALUE(Pointer,Get_sub_tree(),hole); SHIFT()
#ifdef TRACE_Lalr_PARSE
#define REPORT(n) \
    printf ("State %d,	symbol %s,	token %s\n", n, Lalr_symbol_names[_Lalr_symbol], Lalr_symbol_names[_Lalr_token]);
#else
#define REPORT(n)
#endif
#if !defined(__GNUC__)
# define __inline__
#endif
List_Lalr_Production Parse_state_Lalr_OPTMORE_Production (void);	/* state 0 */
static int Parse_state_1 (SymbolSet followers);	/* state 1 */
static int Parse_state_2 (SymbolSet followers);	/* state 2 */
static int Parse_state_3 (SymbolSet followers);	/* state 3 */

static __inline__ int Parse_state_4 (void)	/* state 4 */
{ int n;
      n = 1; _Lalr_symbol = OPT_questionmarksym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}


static __inline__ int Parse_state_5 (void)	/* state 5 */
{ int n;
      n = 2; _Lalr_symbol = LR_Symbol_value;
      { ParseValue me;
        Bool  make_empty = POP_PARSEVALUE (Bool, Bool);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Lalr_LR_Symbol");
        me->sub.PointerValue = Create_Lalr_LR_Symbol(src_info, id, make_empty);
      }
  return n-1;
}

static int Parse_state_6 (SymbolSet followers);	/* state 6 */

static __inline__ int Parse_state_7 (void)	/* state 7 */
{ int n;
      n = 2; _Lalr_symbol = LR_Symbols_value;
      { ParseValue me;
        Lalr_LR_Symbols  next = POP_PARSEVALUE (Pointer, Lalr_LR_Symbols);
        Lalr_LR_Symbol  data = POP_PARSEVALUE (Pointer, Lalr_LR_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Lalr_LR_Symbols");
        me->sub.PointerValue = Create_Lalr_LR_Symbols(src_info, data, next);
      }
  return n-1;
}


static __inline__ int Parse_state_8 (void)	/* state 8 */
{ int n;
      n = 1; _Lalr_symbol = OPT_LR_Symbols_value;
      { /* opt action */
        Lalr_LR_Symbols  syms = POP_PARSEVALUE (Pointer, Lalr_LR_Symbols);
        PUSH_PARSEVALUE(Pointer,syms,Lalr_LR_Symbols);
      }
  return n-1;
}


static __inline__ int Parse_state_9 (void)	/* state 9 */
{ int n;
      n = 1; _Lalr_symbol = ProdRhs_value;
  return n-1;
}

static int Parse_state_10 (SymbolSet followers);	/* state 10 */
static int Parse_state_11 (SymbolSet followers);	/* state 11 */
static int Parse_state_12 (SymbolSet followers);	/* state 12 */

static __inline__ int Parse_state_13 (void)	/* state 13 */
{ int n;
      n = 1; _Lalr_symbol = Emptiness_value;
      PUSH_PARSEVALUE(Int,FALSE,Lalr_Emptiness);
  return n-1;
}


static __inline__ int Parse_state_14 (void)	/* state 14 */
{ int n;
      n = 1; _Lalr_symbol = Emptiness_value;
      PUSH_PARSEVALUE(Int,TRUE,Lalr_Emptiness);
  return n-1;
}

static int Parse_state_15 (SymbolSet followers);	/* state 15 */
static int Parse_state_16 (SymbolSet followers);	/* state 16 */
static int Parse_state_17 (SymbolSet followers);	/* state 17 */
static int Parse_state_18 (SymbolSet followers);	/* state 18 */

static __inline__ int Parse_state_19 (void)	/* state 19 */
{ int n;
      n = 3; _Lalr_symbol = MORE_Identsym_spacesym_value;
      { /* more action */
        List_Ident  _id_0_l = POP_PARSEVALUE (Pointer, List_Ident);
        Ident  _id_0 = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,Create_List_Ident(_id_0,_id_0_l),List_Ident);
      }
  return n-1;
}


static __inline__ int Parse_state_20 (void)	/* state 20 */
{ int n;
      n = 1; _Lalr_symbol = TermSet_value;
  return n-1;
}


static __inline__ int Parse_state_21 (void)	/* state 21 */
{ int n;
      n = 8; _Lalr_symbol = Production_value;
      { ParseValue me;
        List_Ident  _id_0 = POP_PARSEVALUE (Pointer, List_Ident);
        Lalr_Emptiness  empty = POP_PARSEVALUE (Int, Lalr_Emptiness);
        Lalr_LR_Symbols  syms = POP_PARSEVALUE (Pointer, Lalr_LR_Symbols);
        Ident  lhs = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Lalr_Production");
        me->sub.PointerValue = Create_Lalr_Production(src_info, lhs, syms, empty, _id_0);
      }
  return n-1;
}

static int Parse_state_22 (SymbolSet followers);	/* state 22 */

static __inline__ int Parse_state_23 (void)	/* state 23 */
{ int n;
      n = 2; _Lalr_symbol = OPTMORE_Production_value;
      { /* optmore action */
        List_Lalr_Production  grammar_l = POP_PARSEVALUE (Pointer, List_Lalr_Production);
        Lalr_Production  grammar = POP_PARSEVALUE (Pointer, Lalr_Production);
        PUSH_PARSEVALUE(Pointer,Create_List_Lalr_Production(grammar,grammar_l),List_Lalr_Production);
      }
  return n-1;
}

List_Lalr_LR_state Parse_state_Lalr_OPTMORE_LR_state (void);	/* state 24 */
static int Parse_state_25 (SymbolSet followers);	/* state 25 */
static int Parse_state_26 (SymbolSet followers);	/* state 26 */
static int Parse_state_27 (SymbolSet followers);	/* state 27 */
static int Parse_state_28 (SymbolSet followers);	/* state 28 */
static int Parse_state_29 (SymbolSet followers);	/* state 29 */

static __inline__ int Parse_state_30 (void)	/* state 30 */
{ int n;
      n = 2; _Lalr_symbol = OPTMORE_LR_Symbol_value;
      { /* optmore action */
        List_Lalr_LR_Symbol  rhs1_l = POP_PARSEVALUE (Pointer, List_Lalr_LR_Symbol);
        Lalr_LR_Symbol  rhs1 = POP_PARSEVALUE (Pointer, Lalr_LR_Symbol);
        PUSH_PARSEVALUE(Pointer,Create_List_Lalr_LR_Symbol(rhs1,rhs1_l),List_Lalr_LR_Symbol);
      }
  return n-1;
}

static int Parse_state_31 (SymbolSet followers);	/* state 31 */
static int Parse_state_32 (SymbolSet followers);	/* state 32 */
static int Parse_state_33 (SymbolSet followers);	/* state 33 */
static int Parse_state_34 (SymbolSet followers);	/* state 34 */

static __inline__ int Parse_state_35 (void)	/* state 35 */
{ int n;
      n = 2; _Lalr_symbol = OPT_followerscolonsym_TermSet_value;
      { /* opt action */
        List_Ident  _id_0 = POP_PARSEVALUE (Pointer, List_Ident);
        PUSH_PARSEVALUE(Pointer,_id_0,List_Ident);
      }
  return n-1;
}


static __inline__ int Parse_state_36 (void)	/* state 36 */
{ int n;
      n = 6; _Lalr_symbol = Item_value;
      { ParseValue me;
        List_Ident  _id_0 = POP_PARSEVALUE (Pointer, List_Ident);
        Lalr_LR_Symbols  rhs2 = POP_PARSEVALUE (Pointer, Lalr_LR_Symbols);
        List_Lalr_LR_Symbol  rhs1 = POP_PARSEVALUE (Pointer, List_Lalr_LR_Symbol);
        Ident  lhs = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Lalr_Item");
        me->sub.PointerValue = Create_Lalr_Item(src_info, lhs, rhs1, rhs2, _id_0);
      }
  return n-1;
}

static int Parse_state_37 (SymbolSet followers);	/* state 37 */

static __inline__ int Parse_state_38 (void)	/* state 38 */
{ int n;
      n = 2; _Lalr_symbol = MORE_Item_value;
      { /* more action */
        List_Lalr_Item  items_l = POP_PARSEVALUE (Pointer, List_Lalr_Item);
        Lalr_Item  items = POP_PARSEVALUE (Pointer, Lalr_Item);
        PUSH_PARSEVALUE(Pointer,Create_List_Lalr_Item(items,items_l),List_Lalr_Item);
      }
  return n-1;
}

static int Parse_state_39 (SymbolSet followers);	/* state 39 */
static int Parse_state_40 (SymbolSet followers);	/* state 40 */
static int Parse_state_41 (SymbolSet followers);	/* state 41 */
static int Parse_state_42 (SymbolSet followers);	/* state 42 */
static int Parse_state_43 (SymbolSet followers);	/* state 43 */

static __inline__ int Parse_state_44 (void)	/* state 44 */
{ int n;
      n = 4; _Lalr_symbol = Transition_value;
      { ParseValue me;
        Int  num = POP_PARSEVALUE (Int, Int);
        Lalr_LR_Symbol  symbol = POP_PARSEVALUE (Pointer, Lalr_LR_Symbol);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Lalr_Transition");
        me->sub.PointerValue = Create_Lalr_Transition(src_info, symbol, num);
      }
  return n-1;
}

static int Parse_state_45 (SymbolSet followers);	/* state 45 */

static __inline__ int Parse_state_46 (void)	/* state 46 */
{ int n;
      n = 2; _Lalr_symbol = OPTMORE_Transition_value;
      { /* optmore action */
        List_Lalr_Transition  transitions_l = POP_PARSEVALUE (Pointer, List_Lalr_Transition);
        Lalr_Transition  transitions = POP_PARSEVALUE (Pointer, Lalr_Transition);
        PUSH_PARSEVALUE(Pointer,Create_List_Lalr_Transition(transitions,transitions_l),List_Lalr_Transition);
      }
  return n-1;
}


static __inline__ int Parse_state_47 (void)	/* state 47 */
{ int n;
      n = 5; _Lalr_symbol = LR_state_value;
      { ParseValue me;
        List_Lalr_Transition  transitions = POP_PARSEVALUE (Pointer, List_Lalr_Transition);
        List_Lalr_Item  items = POP_PARSEVALUE (Pointer, List_Lalr_Item);
        Int  num = POP_PARSEVALUE (Int, Int);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Lalr_LR_state");
        me->sub.PointerValue = Create_Lalr_LR_state(src_info, num, items, transitions);
      }
  return n-1;
}

static int Parse_state_48 (SymbolSet followers);	/* state 48 */

static __inline__ int Parse_state_49 (void)	/* state 49 */
{ int n;
      n = 2; _Lalr_symbol = OPTMORE_LR_state_value;
      { /* optmore action */
        List_Lalr_LR_state  states_l = POP_PARSEVALUE (Pointer, List_Lalr_LR_state);
        Lalr_LR_state  states = POP_PARSEVALUE (Pointer, Lalr_LR_state);
        PUSH_PARSEVALUE(Pointer,Create_List_Lalr_LR_state(states,states_l),List_Lalr_LR_state);
      }
  return n-1;
}

Lalr_Lalr Parse_state_Lalr_Lalr (void);	/* state 50 */
static int Parse_state_51 (SymbolSet followers);	/* state 51 */
static int Parse_state_52 (SymbolSet followers);	/* state 52 */
static int Parse_state_53 (SymbolSet followers);	/* state 53 */

static __inline__ int Parse_state_54 (void)	/* state 54 */
{ int n;
      n = 4; _Lalr_symbol = Lalr_value;
      { ParseValue me;
        List_Lalr_LR_state  states = POP_PARSEVALUE (Pointer, List_Lalr_LR_state);
        List_Lalr_Production  grammar = POP_PARSEVALUE (Pointer, List_Lalr_Production);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Lalr_Lalr");
        me->sub.PointerValue = Create_Lalr_Lalr(src_info, grammar, states);
        Decorate_Lalr(me->sub.PointerValue);
      }
  return n-1;
}

Lalr_LR_Symbols Parse_state_Lalr_ProdRhs (void);	/* state 55 */
Lalr_Emptiness Parse_state_Lalr_Emptiness (void);	/* state 56 */
List_Ident Parse_state_Lalr_TermSet (void);	/* state 57 */
Lalr_Production Parse_state_Lalr_Production (void);	/* state 58 */
Lalr_LR_Symbol Parse_state_Lalr_LR_Symbol (void);	/* state 59 */
Lalr_LR_Symbols Parse_state_Lalr_LR_Symbols (void);	/* state 60 */
List_Lalr_Item Parse_state_Lalr_MORE_Item (void);	/* state 61 */
List_Lalr_Transition Parse_state_Lalr_OPTMORE_Transition (void);	/* state 62 */
Lalr_LR_state Parse_state_Lalr_LR_state (void);	/* state 63 */
List_Lalr_LR_Symbol Parse_state_Lalr_OPTMORE_LR_Symbol (void);	/* state 64 */
Lalr_Item Parse_state_Lalr_Item (void);	/* state 65 */
List_Ident Parse_state_Lalr_MORE_Identsym_spacesym (void);	/* state 66 */
Lalr_Transition Parse_state_Lalr_Transition (void);	/* state 67 */

/* directors of state 0
   hole_Production Identsym 
 */
List_Lalr_Production Parse_state_Lalr_OPTMORE_Production (void)	/* state 0 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1000008, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(0);
    switch (_Lalr_symbol) {
    case OPTMORE_Production_value:
      n = 1; break; /* accept OPTMORE_Production  ->  . Production OPTMORE_Production followers: Lalr_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x1040008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Production_value: HOLE_ACTION (0, "Production");
    case Production_value:
      {
        n = Parse_state_22(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Production  ->  .   followers: Lalr_EOF  */
      n = 0; _Lalr_symbol = OPTMORE_Production_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Lalr_Production);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Lalr_Production")->sub.PointerValue;
}

/* directors of state 1
   minusgreaterthansym 
 */
static int Parse_state_1 (SymbolSet followers)	/* state 1 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_2(followers);
      }
  return n-1;
}

/* directors of state 2
   hole_ProdRhs hole_LR_Symbols hole_LR_Symbol Identsym semicolonsym 
 */
static int Parse_state_2 (SymbolSet followers)	/* state 2 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x6200028, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(2);
    switch (_Lalr_symbol) {
    case semicolonsym_value:
      n = 0; _Lalr_symbol = OPT_LR_Symbols_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,Lalr_LR_Symbols);
      }
      break;
    case Identsym_value:
      {
        static Int my_followers[] = { 0x6000028, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_6(_followers);
        break;
      }
    case hole_LR_Symbols_value: HOLE_ACTION (0, "LR_Symbols");
    case LR_Symbols_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        break;
      }
    case OPT_LR_Symbols_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        break;
      }
    case hole_ProdRhs_value: HOLE_ACTION (0, "LR_Symbols");
    case ProdRhs_value:
      {
        n = Parse_state_10(followers);
        break;
      }
    default:
    /* default item:Production  ->  Identsym minusgreaterthansym . ProdRhs semicolonsym emptycolonsym Emptiness firstcolonsym TermSet       followers: Lalr_EOF hole_OPTMORE_Production hole_Production Identsym STATESsym  */
/* nt = 0x821bbe8 */
      PUSH_PARSEVALUE(Pointer,0,Lalr_LR_Symbols);
      _Lalr_symbol = ProdRhs_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 3
   questionmarksym 
 */
static int Parse_state_3 (SymbolSet followers)	/* state 3 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(3);
    switch (_Lalr_symbol) {
    case questionmarksym_value:
      {
        n = Parse_state_4();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_questionmarksym_value:
      {
        n = Parse_state_5();
        break;
      }
    default:
    /* default item:LR_Symbol  ->  Identsym . OPT_questionmarksym   followers: hole_LR_Symbols hole_OPTMORE_LR_Symbol hole_LR_Symbol Identsym dotsym equalsgreaterthansym Lalr_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _Lalr_symbol = OPT_questionmarksym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 6
   hole_LR_Symbols hole_LR_Symbol Identsym 
 */
static int Parse_state_6 (SymbolSet followers)	/* state 6 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x6000008, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(6);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x6000008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        n = Parse_state_6(followers);
        break;
      }
    case hole_LR_Symbols_value: HOLE_ACTION (0, "LR_Symbols");
    case LR_Symbols_value:
      {
        n = Parse_state_7();
        break;
      }
    default:
    /* default item:LR_Symbols  ->  LR_Symbol . LR_Symbols  followers: semicolonsym followerscolonsym transitionssym hole_MORE_Item hole_Item Identsym Lalr_EOF  */
/* nt = 0x821e428 */
      InputError (SCAN_POSITION, TRUE, "LR_Symbols expected");
      PUSH_PARSEVALUE(Pointer,0,Lalr_LR_Symbols);
      _Lalr_symbol = LR_Symbols_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 10
   semicolonsym 
 */
static int Parse_state_10 (SymbolSet followers)	/* state 10 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_11(followers);
      }
  return n-1;
}

/* directors of state 11
   emptycolonsym 
 */
static int Parse_state_11 (SymbolSet followers)	/* state 11 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_12(followers);
      }
  return n-1;
}

/* directors of state 12
   hole_Emptiness EMPTYsym NON_EMPTYsym 
 */
static int Parse_state_12 (SymbolSet followers)	/* state 12 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x400300, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(12);
    switch (_Lalr_symbol) {
    case NON_EMPTYsym_value:
      {
        static Int my_followers[] = { 0x80, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_13();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case EMPTYsym_value:
      {
        static Int my_followers[] = { 0x80, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_14();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_Emptiness_value: HOLE_ACTION (0, "Emptiness");
    case Emptiness_value:
      {
        n = Parse_state_15(followers);
        break;
      }
    default:
    /* default item:Production  ->  Identsym minusgreaterthansym ProdRhs semicolonsym emptycolonsym . Emptiness firstcolonsym TermSet       followers: Lalr_EOF hole_OPTMORE_Production hole_Production Identsym STATESsym  */
/* nt = 0x821ea38 */
      n = 0; _Lalr_symbol = Emptiness_value;
      PUSH_PARSEVALUE(Int,TRUE,Lalr_Emptiness);
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 15
   firstcolonsym 
 */
static int Parse_state_15 (SymbolSet followers)	/* state 15 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_16(followers);
      }
  return n-1;
}

/* directors of state 16
   hole_TermSet hole_MORE_Identsym_spacesym Identsym 
 */
static int Parse_state_16 (SymbolSet followers)	/* state 16 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x800008, 0x1 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(16);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
        break;
      }
    case hole_MORE_Identsym_spacesym_value: HOLE_ACTION (0, "List_Ident");
    case MORE_Identsym_spacesym_value:
      {
        n = Parse_state_20();
        break;
      }
    case hole_TermSet_value: HOLE_ACTION (0, "List_Ident");
    case TermSet_value:
      {
        n = Parse_state_21();
        break;
      }
    default:
    /* default item:Production  ->  Identsym minusgreaterthansym ProdRhs semicolonsym emptycolonsym Emptiness firstcolonsym . TermSet       followers: Lalr_EOF hole_OPTMORE_Production hole_Production Identsym STATESsym  */
/* nt = 0x8221e10 */
      InputError (SCAN_POSITION, TRUE, "TermSet expected");
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _Lalr_symbol = TermSet_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 17
   spacesym 
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
   hole_MORE_Identsym_spacesym Identsym 
 */
static int Parse_state_18 (SymbolSet followers)	/* state 18 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8, 0x1 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(18);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
        break;
      }
    case hole_MORE_Identsym_spacesym_value: HOLE_ACTION (0, "List_Ident");
    case MORE_Identsym_spacesym_value:
      {
        n = Parse_state_19();
        break;
      }
    default:
    /* default item:MORE_Identsym_spacesym  ->  Identsym spacesym . followers: hole_OPTMORE_Production hole_Production STATESsym transitionssym hole_MORE_Item hole_Item Identsym Lalr_EOF  */
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 22
   hole_OPTMORE_Production hole_Production Identsym 
 */
static int Parse_state_22 (SymbolSet followers)	/* state 22 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1040008, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(22);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x1040008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Production_value: HOLE_ACTION (0, "Production");
    case Production_value:
      {
        n = Parse_state_22(followers);
        break;
      }
    case hole_OPTMORE_Production_value: HOLE_ACTION (0, "List_Production");
    case OPTMORE_Production_value:
      {
        n = Parse_state_23();
        break;
      }
    default:
    /* default item:OPTMORE_Production  ->  Production . OPTMORE_Production followers: Lalr_EOF STATESsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Lalr_Production);
      _Lalr_symbol = OPTMORE_Production_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 24
   hole_LR_state statesym 
 */
List_Lalr_LR_state Parse_state_Lalr_OPTMORE_LR_state (void)	/* state 24 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x20000400, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(24);
    switch (_Lalr_symbol) {
    case OPTMORE_LR_state_value:
      n = 1; break; /* accept OPTMORE_LR_state  ->  . LR_state OPTMORE_LR_state       followers: Lalr_EOF  */
    case statesym_value:
      {
        static Int my_followers[] = { 0x20080400, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25(_followers);
        break;
      }
    case hole_LR_state_value: HOLE_ACTION (0, "LR_state");
    case LR_state_value:
      {
        n = Parse_state_48(followers);
        break;
      }
    default:
    /* default item:OPTMORE_LR_state  ->  .     followers: Lalr_EOF  */
      n = 0; _Lalr_symbol = OPTMORE_LR_state_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Lalr_LR_state);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Lalr_LR_state")->sub.PointerValue;
}

/* directors of state 25
   Intsym 
 */
static int Parse_state_25 (SymbolSet followers)	/* state 25 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Lalr_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26(followers);
      }
  return n-1;
}

/* directors of state 26
   hole_MORE_Item hole_Item Identsym 
 */
static int Parse_state_26 (SymbolSet followers)	/* state 26 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88000008, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(26);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x88001008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(_followers);
        break;
      }
    case hole_Item_value: HOLE_ACTION (0, "Item");
    case Item_value:
      {
        static Int my_followers[] = { 0x1000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_37(_followers);
        break;
      }
    case hole_MORE_Item_value: HOLE_ACTION (0, "List_Item");
    case MORE_Item_value:
      {
        n = Parse_state_39(followers);
        break;
      }
    default:
    /* default item:LR_state  ->  statesym Intsym . MORE_Item transitionssym OPTMORE_Transition     followers: hole_OPTMORE_LR_state hole_LR_state statesym Lalr_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "MORE_Item expected");
      PUSH_PARSEVALUE(Pointer,0,List_Lalr_Item);
      _Lalr_symbol = MORE_Item_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 27
   minusgreaterthansym 
 */
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

/* directors of state 28
   hole_OPTMORE_LR_Symbol hole_LR_Symbol Identsym dotsym 
 */
static int Parse_state_28 (SymbolSet followers)	/* state 28 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x42002008, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(28);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x42002008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        static Int my_followers[] = { 0x2000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_29(_followers);
        break;
      }
    case hole_OPTMORE_LR_Symbol_value: HOLE_ACTION (0, "List_LR_Symbol");
    case OPTMORE_LR_Symbol_value:
      {
        n = Parse_state_31(followers);
        break;
      }
    default:
    /* default item:Item  ->  Identsym minusgreaterthansym . OPTMORE_LR_Symbol dotsym LR_Symbols OPT_followerscolonsym_TermSet      followers: transitionssym hole_MORE_Item hole_Item Identsym Lalr_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Lalr_LR_Symbol);
      _Lalr_symbol = OPTMORE_LR_Symbol_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 29
   hole_OPTMORE_LR_Symbol hole_LR_Symbol Identsym 
 */
static int Parse_state_29 (SymbolSet followers)	/* state 29 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x42000008, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(29);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x42000008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        n = Parse_state_29(followers);
        break;
      }
    case hole_OPTMORE_LR_Symbol_value: HOLE_ACTION (0, "List_LR_Symbol");
    case OPTMORE_LR_Symbol_value:
      {
        n = Parse_state_30();
        break;
      }
    default:
    /* default item:OPTMORE_LR_Symbol  ->  LR_Symbol . OPTMORE_LR_Symbol    followers: dotsym Lalr_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Lalr_LR_Symbol);
      _Lalr_symbol = OPTMORE_LR_Symbol_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 31
   dotsym 
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
   hole_LR_Symbols hole_LR_Symbol Identsym 
 */
static int Parse_state_32 (SymbolSet followers)	/* state 32 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x6000008, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(32);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x6010008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        static Int my_followers[] = { 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_6(_followers);
        break;
      }
    case hole_LR_Symbols_value: HOLE_ACTION (0, "LR_Symbols");
    case LR_Symbols_value:
      {
        n = Parse_state_33(followers);
        break;
      }
    default:
    /* default item:Item  ->  Identsym minusgreaterthansym OPTMORE_LR_Symbol dotsym . LR_Symbols OPT_followerscolonsym_TermSet      followers: transitionssym hole_MORE_Item hole_Item Identsym Lalr_EOF  */
/* nt = 0x821e428 */
      InputError (SCAN_POSITION, TRUE, "LR_Symbols expected");
      PUSH_PARSEVALUE(Pointer,0,Lalr_LR_Symbols);
      _Lalr_symbol = LR_Symbols_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 33
   followerscolonsym 
 */
static int Parse_state_33 (SymbolSet followers)	/* state 33 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(33);
    switch (_Lalr_symbol) {
    case followerscolonsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(followers);
        break;
      }
    case OPT_followerscolonsym_TermSet_value:
      {
        n = Parse_state_36();
        break;
      }
    default:
    /* default item:Item  ->  Identsym minusgreaterthansym OPTMORE_LR_Symbol dotsym LR_Symbols . OPT_followerscolonsym_TermSet      followers: transitionssym hole_MORE_Item hole_Item Identsym Lalr_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _Lalr_symbol = OPT_followerscolonsym_TermSet_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 34
   hole_TermSet hole_MORE_Identsym_spacesym Identsym 
 */
static int Parse_state_34 (SymbolSet followers)	/* state 34 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x800008, 0x1 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(34);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
        break;
      }
    case hole_MORE_Identsym_spacesym_value: HOLE_ACTION (0, "List_Ident");
    case MORE_Identsym_spacesym_value:
      {
        n = Parse_state_20();
        break;
      }
    case hole_TermSet_value: HOLE_ACTION (0, "List_Ident");
    case TermSet_value:
      {
        n = Parse_state_35();
        break;
      }
    default:
    /* default item:OPT_followerscolonsym_TermSet  ->  followerscolonsym . TermSet  followers: transitionssym hole_MORE_Item hole_Item Identsym Lalr_EOF  */
/* nt = 0x8221e10 */
      InputError (SCAN_POSITION, TRUE, "TermSet expected");
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _Lalr_symbol = TermSet_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 37
   hole_MORE_Item hole_Item Identsym 
 */
static int Parse_state_37 (SymbolSet followers)	/* state 37 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88000008, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(37);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x88000008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(_followers);
        break;
      }
    case hole_Item_value: HOLE_ACTION (0, "Item");
    case Item_value:
      {
        n = Parse_state_37(followers);
        break;
      }
    case hole_MORE_Item_value: HOLE_ACTION (0, "List_Item");
    case MORE_Item_value:
      {
        n = Parse_state_38();
        break;
      }
    default:
    /* default item:MORE_Item  ->  Item .   followers: transitionssym Lalr_EOF  */
      n = 1; _Lalr_symbol = MORE_Item_value;
      { /* more action */
        Lalr_Item  items = POP_PARSEVALUE (Pointer, Lalr_Item);
        PUSH_PARSEVALUE(Pointer,Create_List_Lalr_Item(items,NULL),List_Lalr_Item);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 39
   transitionssym 
 */
static int Parse_state_39 (SymbolSet followers)	/* state 39 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_40(followers);
      }
  return n-1;
}

/* directors of state 40
   hole_OPTMORE_Transition hole_Transition hole_LR_Symbol Identsym 
 */
static int Parse_state_40 (SymbolSet followers)	/* state 40 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x12000008, 0x2 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(40);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x12004008, 0x2 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        static Int my_followers[] = { 0x12000008, 0x2 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_41(_followers);
        break;
      }
    case hole_Transition_value: HOLE_ACTION (0, "Transition");
    case Transition_value:
      {
        n = Parse_state_45(followers);
        break;
      }
    case hole_OPTMORE_Transition_value: HOLE_ACTION (0, "List_Transition");
    case OPTMORE_Transition_value:
      {
        n = Parse_state_47();
        break;
      }
    default:
    /* default item:LR_state  ->  statesym Intsym MORE_Item transitionssym . OPTMORE_Transition     followers: hole_OPTMORE_LR_state hole_LR_state statesym Lalr_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Lalr_Transition);
      _Lalr_symbol = OPTMORE_Transition_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 41
   equalsgreaterthansym 
 */
static int Parse_state_41 (SymbolSet followers)	/* state 41 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_42(followers);
      }
  return n-1;
}

/* directors of state 42
   statesym 
 */
static int Parse_state_42 (SymbolSet followers)	/* state 42 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_43(followers);
      }
  return n-1;
}

/* directors of state 43
   Intsym 
 */
static int Parse_state_43 (SymbolSet followers)	/* state 43 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Lalr_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_44();
      }
  return n-1;
}

/* directors of state 45
   hole_OPTMORE_Transition hole_Transition hole_LR_Symbol Identsym 
 */
static int Parse_state_45 (SymbolSet followers)	/* state 45 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x12000008, 0x2 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(45);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x12004008, 0x2 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        static Int my_followers[] = { 0x12000008, 0x2 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_41(_followers);
        break;
      }
    case hole_Transition_value: HOLE_ACTION (0, "Transition");
    case Transition_value:
      {
        n = Parse_state_45(followers);
        break;
      }
    case hole_OPTMORE_Transition_value: HOLE_ACTION (0, "List_Transition");
    case OPTMORE_Transition_value:
      {
        n = Parse_state_46();
        break;
      }
    default:
    /* default item:OPTMORE_Transition  ->  Transition . OPTMORE_Transition followers: hole_OPTMORE_LR_state hole_LR_state statesym Lalr_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Lalr_Transition);
      _Lalr_symbol = OPTMORE_Transition_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 48
   hole_OPTMORE_LR_state hole_LR_state statesym 
 */
static int Parse_state_48 (SymbolSet followers)	/* state 48 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x20080400, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(48);
    switch (_Lalr_symbol) {
    case statesym_value:
      {
        static Int my_followers[] = { 0x20080400, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25(_followers);
        break;
      }
    case hole_LR_state_value: HOLE_ACTION (0, "LR_state");
    case LR_state_value:
      {
        n = Parse_state_48(followers);
        break;
      }
    case hole_OPTMORE_LR_state_value: HOLE_ACTION (0, "List_LR_state");
    case OPTMORE_LR_state_value:
      {
        n = Parse_state_49();
        break;
      }
    default:
    /* default item:OPTMORE_LR_state  ->  LR_state . OPTMORE_LR_state       followers: Lalr_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Lalr_LR_state);
      _Lalr_symbol = OPTMORE_LR_state_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 50
   GRAMMARsym 
 */
Lalr_Lalr Parse_state_Lalr_Lalr (void)	/* state 50 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(50);
    switch (_Lalr_symbol) {
    case Lalr_value:
      n = 1; break; /* accept Lalr  ->  . GRAMMARsym OPTMORE_Production STATESsym OPTMORE_LR_state    followers: Lalr_EOF  */
    case GRAMMARsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_51(followers);
        break;
      }
    default:
    /* default item:Lalr  ->  . GRAMMARsym OPTMORE_Production STATESsym OPTMORE_LR_state        followers: Lalr_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "GRAMMARsym expected");
      dont_shift = TRUE; _Lalr_symbol = GRAMMARsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Lalr_Lalr")->sub.PointerValue;
}

/* directors of state 51
   hole_OPTMORE_Production hole_Production Identsym STATESsym 
 */
static int Parse_state_51 (SymbolSet followers)	/* state 51 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x104000c, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(51);
    switch (_Lalr_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x104000c, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Production_value: HOLE_ACTION (0, "Production");
    case Production_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22(_followers);
        break;
      }
    case hole_OPTMORE_Production_value: HOLE_ACTION (0, "List_Production");
    case OPTMORE_Production_value:
      {
        n = Parse_state_52(followers);
        break;
      }
    default:
    /* default item:Lalr  ->  GRAMMARsym . OPTMORE_Production STATESsym OPTMORE_LR_state    followers: Lalr_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Lalr_Production);
      _Lalr_symbol = OPTMORE_Production_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 52
   STATESsym 
 */
static int Parse_state_52 (SymbolSet followers)	/* state 52 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_53(followers);
      }
  return n-1;
}

/* directors of state 53
   hole_OPTMORE_LR_state hole_LR_state statesym 
 */
static int Parse_state_53 (SymbolSet followers)	/* state 53 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x20080400, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(53);
    switch (_Lalr_symbol) {
    case statesym_value:
      {
        static Int my_followers[] = { 0x20080400, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25(_followers);
        break;
      }
    case hole_LR_state_value: HOLE_ACTION (0, "LR_state");
    case LR_state_value:
      {
        n = Parse_state_48(followers);
        break;
      }
    case hole_OPTMORE_LR_state_value: HOLE_ACTION (0, "List_LR_state");
    case OPTMORE_LR_state_value:
      {
        n = Parse_state_54();
        break;
      }
    default:
    /* default item:Lalr  ->  GRAMMARsym OPTMORE_Production STATESsym . OPTMORE_LR_state    followers: Lalr_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Lalr_LR_state);
      _Lalr_symbol = OPTMORE_LR_state_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 55
   hole_LR_Symbols hole_LR_Symbol Identsym 
 */
Lalr_LR_Symbols Parse_state_Lalr_ProdRhs (void)	/* state 55 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x6000008, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(55);
    switch (_Lalr_symbol) {
    case ProdRhs_value:
      n = 1; break; /* accept ProdRhs  ->  . OPT_LR_Symbols   followers: Lalr_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x6000008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        n = Parse_state_6(followers);
        break;
      }
    case hole_LR_Symbols_value: HOLE_ACTION (0, "LR_Symbols");
    case LR_Symbols_value:
      {
        n = Parse_state_8();
        break;
      }
    case OPT_LR_Symbols_value:
      {
        n = Parse_state_9();
        break;
      }
    default:
    /* default item:ProdRhs  ->  . OPT_LR_Symbols       followers: Lalr_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,Lalr_LR_Symbols);
      _Lalr_symbol = OPT_LR_Symbols_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Lalr_LR_Symbols")->sub.PointerValue;
}

/* directors of state 56
   EMPTYsym NON_EMPTYsym 
 */
Lalr_Emptiness Parse_state_Lalr_Emptiness (void)	/* state 56 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x300, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(56);
    switch (_Lalr_symbol) {
    case Emptiness_value:
      n = 1; break; /* accept Emptiness  ->  . EMPTYsym       followers: Lalr_EOF  */
    case NON_EMPTYsym_value:
      {
        n = Parse_state_13();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case EMPTYsym_value:
      {
        n = Parse_state_14();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Emptiness  ->  . EMPTYsym   followers: Lalr_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "EMPTYsym expected");
      dont_shift = TRUE; _Lalr_symbol = EMPTYsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Lalr_Emptiness")->sub.IntValue;
}

/* directors of state 57
   hole_MORE_Identsym_spacesym Identsym 
 */
List_Ident Parse_state_Lalr_TermSet (void)	/* state 57 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8, 0x1 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(57);
    switch (_Lalr_symbol) {
    case TermSet_value:
      n = 1; break; /* accept TermSet  ->  . MORE_Identsym_spacesym   followers: Lalr_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
        break;
      }
    case hole_MORE_Identsym_spacesym_value: HOLE_ACTION (0, "List_Ident");
    case MORE_Identsym_spacesym_value:
      {
        n = Parse_state_20();
        break;
      }
    default:
    /* default item:TermSet  ->  . MORE_Identsym_spacesym       followers: Lalr_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "MORE_Identsym_spacesym expected");
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _Lalr_symbol = MORE_Identsym_spacesym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Ident")->sub.PointerValue;
}

/* directors of state 58
   Identsym 
 */
Lalr_Production Parse_state_Lalr_Production (void)	/* state 58 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(58);
    switch (_Lalr_symbol) {
    case Production_value:
      n = 1; break; /* accept Production  ->  . Identsym minusgreaterthansym ProdRhs semicolonsym emptycolonsym Emptiness firstcolonsym TermSet       followers: Lalr_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(followers);
        break;
      }
    default:
    /* default item:Production  ->  . Identsym minusgreaterthansym ProdRhs semicolonsym emptycolonsym Emptiness firstcolonsym TermSet   followers: Lalr_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _Lalr_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Lalr_Production")->sub.PointerValue;
}

/* directors of state 59
   Identsym 
 */
Lalr_LR_Symbol Parse_state_Lalr_LR_Symbol (void)	/* state 59 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(59);
    switch (_Lalr_symbol) {
    case LR_Symbol_value:
      n = 1; break; /* accept LR_Symbol  ->  . Identsym OPT_questionmarksym   followers: Lalr_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(followers);
        break;
      }
    default:
    /* default item:LR_Symbol  ->  . Identsym OPT_questionmarksym       followers: Lalr_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _Lalr_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Lalr_LR_Symbol")->sub.PointerValue;
}

/* directors of state 60
   hole_LR_Symbol Identsym 
 */
Lalr_LR_Symbols Parse_state_Lalr_LR_Symbols (void)	/* state 60 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2000008, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(60);
    switch (_Lalr_symbol) {
    case LR_Symbols_value:
      n = 1; break; /* accept LR_Symbols  ->  . LR_Symbol LR_Symbols  followers: Lalr_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x6000008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        n = Parse_state_6(followers);
        break;
      }
    default:
    /* default item:LR_Symbols  ->  . LR_Symbol LR_Symbols      followers: Lalr_EOF  */
/* nt = 0x821dc38 */
      InputError (SCAN_POSITION, TRUE, "LR_Symbol expected");
      PUSH_PARSEVALUE(Pointer,0,Lalr_LR_Symbol);
      _Lalr_symbol = LR_Symbol_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Lalr_LR_Symbols")->sub.PointerValue;
}

/* directors of state 61
   hole_Item Identsym 
 */
List_Lalr_Item Parse_state_Lalr_MORE_Item (void)	/* state 61 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x80000008, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(61);
    switch (_Lalr_symbol) {
    case MORE_Item_value:
      n = 1; break; /* accept MORE_Item  ->  . Item MORE_Item followers: Lalr_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x88000008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(_followers);
        break;
      }
    case hole_Item_value: HOLE_ACTION (0, "Item");
    case Item_value:
      {
        n = Parse_state_37(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:MORE_Item  ->  . Item       followers: Lalr_EOF  */
/* nt = 0x8221990 */
      InputError (SCAN_POSITION, TRUE, "Item expected");
      PUSH_PARSEVALUE(Pointer,0,Lalr_Item);
      _Lalr_symbol = Item_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Lalr_Item")->sub.PointerValue;
}

/* directors of state 62
   hole_Transition hole_LR_Symbol Identsym 
 */
List_Lalr_Transition Parse_state_Lalr_OPTMORE_Transition (void)	/* state 62 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2000008, 0x2 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(62);
    switch (_Lalr_symbol) {
    case OPTMORE_Transition_value:
      n = 1; break; /* accept OPTMORE_Transition  ->  . Transition OPTMORE_Transition followers: Lalr_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x12004008, 0x2 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        static Int my_followers[] = { 0x12000008, 0x2 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_41(_followers);
        break;
      }
    case hole_Transition_value: HOLE_ACTION (0, "Transition");
    case Transition_value:
      {
        n = Parse_state_45(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Transition  ->  .   followers: Lalr_EOF  */
      n = 0; _Lalr_symbol = OPTMORE_Transition_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Lalr_Transition);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Lalr_Transition")->sub.PointerValue;
}

/* directors of state 63
   statesym 
 */
Lalr_LR_state Parse_state_Lalr_LR_state (void)	/* state 63 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x400, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(63);
    switch (_Lalr_symbol) {
    case LR_state_value:
      n = 1; break; /* accept LR_state  ->  . statesym Intsym MORE_Item transitionssym OPTMORE_Transition     followers: Lalr_EOF  */
    case statesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25(followers);
        break;
      }
    default:
    /* default item:LR_state  ->  . statesym Intsym MORE_Item transitionssym OPTMORE_Transition followers: Lalr_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "statesym expected");
      dont_shift = TRUE; _Lalr_symbol = statesym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Lalr_LR_state")->sub.PointerValue;
}

/* directors of state 64
   hole_LR_Symbol Identsym 
 */
List_Lalr_LR_Symbol Parse_state_Lalr_OPTMORE_LR_Symbol (void)	/* state 64 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2000008, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(64);
    switch (_Lalr_symbol) {
    case OPTMORE_LR_Symbol_value:
      n = 1; break; /* accept OPTMORE_LR_Symbol  ->  . LR_Symbol OPTMORE_LR_Symbol    followers: Lalr_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x42000008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        n = Parse_state_29(followers);
        break;
      }
    default:
    /* default item:OPTMORE_LR_Symbol  ->  .    followers: Lalr_EOF  */
      n = 0; _Lalr_symbol = OPTMORE_LR_Symbol_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Lalr_LR_Symbol);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Lalr_LR_Symbol")->sub.PointerValue;
}

/* directors of state 65
   Identsym 
 */
Lalr_Item Parse_state_Lalr_Item (void)	/* state 65 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(65);
    switch (_Lalr_symbol) {
    case Item_value:
      n = 1; break; /* accept Item  ->  . Identsym minusgreaterthansym OPTMORE_LR_Symbol dotsym LR_Symbols OPT_followerscolonsym_TermSet      followers: Lalr_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(followers);
        break;
      }
    default:
    /* default item:Item  ->  . Identsym minusgreaterthansym OPTMORE_LR_Symbol dotsym LR_Symbols OPT_followerscolonsym_TermSet  followers: Lalr_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _Lalr_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Lalr_Item")->sub.PointerValue;
}

/* directors of state 66
   Identsym 
 */
List_Ident Parse_state_Lalr_MORE_Identsym_spacesym (void)	/* state 66 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(66);
    switch (_Lalr_symbol) {
    case MORE_Identsym_spacesym_value:
      n = 1; break; /* accept MORE_Identsym_spacesym  ->  . Identsym spacesym MORE_Identsym_spacesym  followers: Lalr_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:MORE_Identsym_spacesym  ->  . Identsym spacesym     followers: Lalr_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _Lalr_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Ident")->sub.PointerValue;
}

/* directors of state 67
   hole_LR_Symbol Identsym 
 */
Lalr_Transition Parse_state_Lalr_Transition (void)	/* state 67 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2000008, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x4 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, Lalr);
  _Lalr_symbol = _Lalr_token;
  do {
    REPORT(67);
    switch (_Lalr_symbol) {
    case Transition_value:
      n = 1; break; /* accept Transition  ->  . LR_Symbol equalsgreaterthansym statesym Intsym        followers: Lalr_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Lalr_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case hole_LR_Symbol_value: HOLE_ACTION (0, "LR_Symbol");
    case LR_Symbol_value:
      {
        n = Parse_state_41(followers);
        break;
      }
    default:
    /* default item:Transition  ->  . LR_Symbol equalsgreaterthansym statesym Intsym    followers: Lalr_EOF  */
/* nt = 0x821dc38 */
      InputError (SCAN_POSITION, TRUE, "LR_Symbol expected");
      PUSH_PARSEVALUE(Pointer,0,Lalr_LR_Symbol);
      _Lalr_symbol = LR_Symbol_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Lalr_Transition")->sub.PointerValue;
}

