#include "grammar_lalr.h"

#include "grammar_y.h"

typedef enum {
  grammar_NONSENSE,
  openchainsym_value,
  closechainsym_value,
  questionmarksym_value,
  plussym_value,
  starsym_value,
  Stringsym_value,
  hatsym_value,
  dollarsym_value,
  Identsym_value,
  openparsym_value,
  closeparsym_value,
  dotsym_value,
  nonterminalsym_value,
  importsym_value,
  extrasym_value,
  semicolonsym_value,
  verticalbarsym_value,
  hole_Scanner_value,
  hole_Parser_value,
  hole_grammar_value,
  hole_OPTMORE_Token_value,
  hole_RegExpr_value,
  hole_OPTMORE_ScanAction_semicolonsym_value,
  hole_Token_value,
  hole_ChoiceRE_value,
  hole_SeqRE_value,
  hole_PostRE_value,
  hole_BasicRE_value,
  hole_ScanAction_value,
  hole_OPTMORE_ProdRule_value,
  hole_ProdRule_value,
  grammar_EOF_value,
  Scanner_value,
  Parser_value,
  grammar_value,
  OPTMORE_Token_value,
  RegExpr_value,
  OPTMORE_ScanAction_semicolonsym_value,
  Token_value,
  ChoiceRE_value,
  SeqRE_value,
  OPT_verticalbarsym_RegExpr_value,
  PostRE_value,
  OPT_SeqRE_value,
  BasicRE_value,
  ScanAction_value,
  OPTMORE_ProdRule_value,
  ProdRule_value,
  grammar_ERROR
} grammarSymbol;

static grammarSymbol _grammar_token;

static grammarSymbol _grammar_symbol;

#define NUM_TERMINALS 33

#define WORDS_IN_SET ((NUM_TERMINALS+BITSPERWORD-1)/BITSPERWORD)

static String grammar_symbol_names[] = {
  "grammar_NONSENSE",
  "openchainsym",
  "closechainsym",
  "questionmarksym",
  "plussym",
  "starsym",
  "Stringsym",
  "hatsym",
  "dollarsym",
  "Identsym",
  "openparsym",
  "closeparsym",
  "dotsym",
  "nonterminalsym",
  "importsym",
  "extrasym",
  "semicolonsym",
  "verticalbarsym",
  "hole_Scanner",
  "hole_Parser",
  "hole_grammar",
  "hole_OPTMORE_Token",
  "hole_RegExpr",
  "hole_OPTMORE_ScanAction_semicolonsym",
  "hole_Token",
  "hole_ChoiceRE",
  "hole_SeqRE",
  "hole_PostRE",
  "hole_BasicRE",
  "hole_ScanAction",
  "hole_OPTMORE_ProdRule",
  "hole_ProdRule",
  "grammar_EOF",
  "Scanner",
  "Parser",
  "grammar",
  "OPTMORE_Token",
  "RegExpr",
  "OPTMORE_ScanAction_semicolonsym",
  "Token",
  "ChoiceRE",
  "SeqRE",
  "OPT_verticalbarsym_RegExpr",
  "PostRE",
  "OPT_SeqRE",
  "BasicRE",
  "ScanAction",
  "OPTMORE_ProdRule",
  "ProdRule",
  "grammar_ERROR"
};

static grammarSymbol grammar_terminal_map[2*grammar_ERROR];

static void fill_terminal_map (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;
  grammar_terminal_map[0] = grammar_NONSENSE;
  grammar_terminal_map[openchainsym-NONSENSE] = openchainsym_value;
  grammar_terminal_map[closechainsym-NONSENSE] = closechainsym_value;
  grammar_terminal_map[questionmarksym-NONSENSE] = questionmarksym_value;
  grammar_terminal_map[plussym-NONSENSE] = plussym_value;
  grammar_terminal_map[starsym-NONSENSE] = starsym_value;
  grammar_terminal_map[Stringsym-NONSENSE] = Stringsym_value;
  grammar_terminal_map[hatsym-NONSENSE] = hatsym_value;
  grammar_terminal_map[dollarsym-NONSENSE] = dollarsym_value;
  grammar_terminal_map[Identsym-NONSENSE] = Identsym_value;
  grammar_terminal_map[openparsym-NONSENSE] = openparsym_value;
  grammar_terminal_map[closeparsym-NONSENSE] = closeparsym_value;
  grammar_terminal_map[dotsym-NONSENSE] = dotsym_value;
  grammar_terminal_map[nonterminalsym-NONSENSE] = nonterminalsym_value;
  grammar_terminal_map[importsym-NONSENSE] = importsym_value;
  grammar_terminal_map[extrasym-NONSENSE] = extrasym_value;
  grammar_terminal_map[semicolonsym-NONSENSE] = semicolonsym_value;
  grammar_terminal_map[verticalbarsym-NONSENSE] = verticalbarsym_value;
  grammar_terminal_map[hole_Scanner-NONSENSE] = hole_Scanner_value;
  grammar_terminal_map[hole_Parser-NONSENSE] = hole_Parser_value;
  grammar_terminal_map[hole_grammar-NONSENSE] = hole_grammar_value;
  grammar_terminal_map[hole_OPTMORE_Token-NONSENSE] = hole_OPTMORE_Token_value;
  grammar_terminal_map[hole_RegExpr-NONSENSE] = hole_RegExpr_value;
  grammar_terminal_map[hole_OPTMORE_ScanAction_semicolonsym-NONSENSE] = hole_OPTMORE_ScanAction_semicolonsym_value;
  grammar_terminal_map[hole_Token-NONSENSE] = hole_Token_value;
  grammar_terminal_map[hole_ChoiceRE-NONSENSE] = hole_ChoiceRE_value;
  grammar_terminal_map[hole_SeqRE-NONSENSE] = hole_SeqRE_value;
  grammar_terminal_map[hole_PostRE-NONSENSE] = hole_PostRE_value;
  grammar_terminal_map[hole_BasicRE-NONSENSE] = hole_BasicRE_value;
  grammar_terminal_map[hole_ScanAction-NONSENSE] = hole_ScanAction_value;
  grammar_terminal_map[hole_OPTMORE_ProdRule-NONSENSE] = hole_OPTMORE_ProdRule_value;
  grammar_terminal_map[hole_ProdRule-NONSENSE] = hole_ProdRule_value;
}

extern int grammar_lex(void);
#define SHIFT() { _grammar_token = grammar_lex(); if (_grammar_token==0) _grammar_token = grammar_EOF_value; else _grammar_token = grammar_terminal_map[_grammar_token-NONSENSE]; }
#define HOLE_ACTION(term,s) PUSH_PARSEVALUE(Pointer,Get_sub_tree(),hole); SHIFT()
#ifdef TRACE_grammar_PARSE
#define REPORT(n) \
    printf ("State %d,	symbol %s,	token %s\n", n, grammar_symbol_names[_grammar_symbol], grammar_symbol_names[_grammar_token]);
#else
#define REPORT(n)
#endif
#if !defined(__GNUC__)
# define __inline__
#endif
grammar_Scanner Parse_state_grammar_Scanner (void);	/* state 0 */

static __inline__ int Parse_state_1 (void)	/* state 1 */
{ int n;
      n = 1; _grammar_symbol = BasicRE_value;
      { ParseValue me;
        String  s = POP_PARSEVALUE (String, String);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_StringRE(src_info, s);
      }
  return n-1;
}


static __inline__ int Parse_state_2 (void)	/* state 2 */
{ int n;
      n = 1; _grammar_symbol = BasicRE_value;
      { ParseValue me;
        SrcInfo src_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_SOLRE(src_info);
      }
  return n-1;
}


static __inline__ int Parse_state_3 (void)	/* state 3 */
{ int n;
      n = 1; _grammar_symbol = BasicRE_value;
      { ParseValue me;
        SrcInfo src_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_EOLRE(src_info);
      }
  return n-1;
}

static int Parse_state_4 (SymbolSet followers);	/* state 4 */
static int Parse_state_5 (void);	/* state 5 */

static __inline__ int Parse_state_6 (void)	/* state 6 */
{ int n;
      n = 3; _grammar_symbol = BasicRE_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_IdRE(src_info, id);
      }
  return n-1;
}

static int Parse_state_7 (SymbolSet followers);	/* state 7 */

static __inline__ int Parse_state_8 (void)	/* state 8 */
{ int n;
      n = 1; _grammar_symbol = BasicRE_value;
      { ParseValue me;
        SrcInfo src_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_AnyRE(src_info);
      }
  return n-1;
}

static int Parse_state_9 (SymbolSet followers);	/* state 9 */

static __inline__ int Parse_state_10 (void)	/* state 10 */
{ int n;
      n = 2; _grammar_symbol = PostRE_value;
      { ParseValue me;
        grammar_RegExpr  re = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_OptRE(src_info, re);
      }
  return n-1;
}


static __inline__ int Parse_state_11 (void)	/* state 11 */
{ int n;
      n = 2; _grammar_symbol = PostRE_value;
      { ParseValue me;
        grammar_RegExpr  re = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_PlusRE(src_info, re);
      }
  return n-1;
}


static __inline__ int Parse_state_12 (void)	/* state 12 */
{ int n;
      n = 2; _grammar_symbol = PostRE_value;
      { ParseValue me;
        grammar_RegExpr  re = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_TimesRE(src_info, re);
      }
  return n-1;
}

static int Parse_state_13 (SymbolSet followers);	/* state 13 */

static __inline__ int Parse_state_14 (void)	/* state 14 */
{ int n;
      n = 1; _grammar_symbol = OPT_SeqRE_value;
      { /* opt action */
        grammar_RegExpr  tail = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        PUSH_PARSEVALUE(Pointer,tail,grammar_RegExpr);
      }
  return n-1;
}


static __inline__ int Parse_state_15 (void)	/* state 15 */
{ int n;
      n = 2; _grammar_symbol = SeqRE_value;
      { ParseValue me;
        grammar_RegExpr  tail = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        grammar_RegExpr  head = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_SeqRE(src_info, head, tail);
      }
  return n-1;
}

static int Parse_state_16 (SymbolSet followers);	/* state 16 */
static int Parse_state_17 (SymbolSet followers);	/* state 17 */

static __inline__ int Parse_state_18 (void)	/* state 18 */
{ int n;
      n = 1; _grammar_symbol = RegExpr_value;
  return n-1;
}


static __inline__ int Parse_state_19 (void)	/* state 19 */
{ int n;
      n = 2; _grammar_symbol = OPT_verticalbarsym_RegExpr_value;
      { /* opt action */
        grammar_RegExpr  tail = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        PUSH_PARSEVALUE(Pointer,tail,grammar_RegExpr);
      }
  return n-1;
}


static __inline__ int Parse_state_20 (void)	/* state 20 */
{ int n;
      n = 2; _grammar_symbol = ChoiceRE_value;
      { ParseValue me;
        grammar_RegExpr  tail = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        grammar_RegExpr  head = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_ChoiceRE(src_info, head, tail);
      }
  return n-1;
}

static int Parse_state_21 (void);	/* state 21 */

static __inline__ int Parse_state_22 (void)	/* state 22 */
{ int n;
      n = 3; _grammar_symbol = BasicRE_value;
      { ParseValue me;
        grammar_RegExpr  re = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_ParRE(src_info, re);
      }
  return n-1;
}

static int Parse_state_23 (SymbolSet followers);	/* state 23 */
static int Parse_state_24 (SymbolSet followers);	/* state 24 */

static __inline__ int Parse_state_25 (void)	/* state 25 */
{ int n;
      n = 1; _grammar_symbol = ScanAction_value;
  return n-1;
}

static int Parse_state_26 (SymbolSet followers);	/* state 26 */
static int Parse_state_27 (SymbolSet followers);	/* state 27 */

static __inline__ int Parse_state_28 (void)	/* state 28 */
{ int n;
      n = 3; _grammar_symbol = OPTMORE_ScanAction_semicolonsym_value;
      { /* optmore action */
        List_String  action_l = POP_PARSEVALUE (Pointer, List_String);
        String  action = POP_PARSEVALUE (String, String);
        PUSH_PARSEVALUE(Pointer,Create_List_String(action,action_l),List_String);
      }
  return n-1;
}

static int Parse_state_29 (void);	/* state 29 */

static __inline__ int Parse_state_30 (void)	/* state 30 */
{ int n;
      n = 4; _grammar_symbol = Token_value;
      { ParseValue me;
        List_String  action = POP_PARSEVALUE (Pointer, List_String);
        grammar_RegExpr  re = POP_PARSEVALUE (Pointer, grammar_RegExpr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_Token");
        me->sub.PointerValue = Create_grammar_Token(src_info, re, action);
      }
  return n-1;
}

static int Parse_state_31 (SymbolSet followers);	/* state 31 */

static __inline__ int Parse_state_32 (void)	/* state 32 */
{ int n;
      n = 2; _grammar_symbol = OPTMORE_Token_value;
      { /* optmore action */
        List_grammar_Token  tokens_l = POP_PARSEVALUE (Pointer, List_grammar_Token);
        grammar_Token  tokens = POP_PARSEVALUE (Pointer, grammar_Token);
        PUSH_PARSEVALUE(Pointer,Create_List_grammar_Token(tokens,tokens_l),List_grammar_Token);
      }
  return n-1;
}


static __inline__ int Parse_state_33 (void)	/* state 33 */
{ int n;
      n = 1; _grammar_symbol = Scanner_value;
      { ParseValue me;
        List_grammar_Token  tokens = POP_PARSEVALUE (Pointer, List_grammar_Token);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_Scanner");
        me->sub.PointerValue = Create_grammar_Scanner(src_info, tokens);
      }
  return n-1;
}

grammar_Parser Parse_state_grammar_Parser (void);	/* state 34 */
static int Parse_state_35 (SymbolSet followers);	/* state 35 */

static __inline__ int Parse_state_36 (void)	/* state 36 */
{ int n;
      n = 2; _grammar_symbol = ProdRule_value;
      { ParseValue me;
        Ident  lhs = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_ProdRule");
        me->sub.PointerValue = Create_grammar_NT_Rule(src_info, lhs);
      }
  return n-1;
}


static __inline__ int Parse_state_37 (void)	/* state 37 */
{ int n;
      n = 2; _grammar_symbol = ProdRule_value;
      { ParseValue me;
        Ident  lhs = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_ProdRule");
        me->sub.PointerValue = Create_grammar_Import_Rule(src_info, lhs);
      }
  return n-1;
}


static __inline__ int Parse_state_38 (void)	/* state 38 */
{ int n;
      n = 2; _grammar_symbol = ProdRule_value;
      { ParseValue me;
        Ident  lhs = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_ProdRule");
        me->sub.PointerValue = Create_grammar_Extra_Rule(src_info, lhs);
      }
  return n-1;
}

static int Parse_state_39 (SymbolSet followers);	/* state 39 */

static __inline__ int Parse_state_40 (void)	/* state 40 */
{ int n;
      n = 2; _grammar_symbol = OPTMORE_ProdRule_value;
      { /* optmore action */
        List_grammar_ProdRule  rules_l = POP_PARSEVALUE (Pointer, List_grammar_ProdRule);
        grammar_ProdRule  rules = POP_PARSEVALUE (Pointer, grammar_ProdRule);
        PUSH_PARSEVALUE(Pointer,Create_List_grammar_ProdRule(rules,rules_l),List_grammar_ProdRule);
      }
  return n-1;
}


static __inline__ int Parse_state_41 (void)	/* state 41 */
{ int n;
      n = 1; _grammar_symbol = Parser_value;
      { ParseValue me;
        List_grammar_ProdRule  rules = POP_PARSEVALUE (Pointer, List_grammar_ProdRule);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_Parser");
        me->sub.PointerValue = Create_grammar_Parser(src_info, rules);
      }
  return n-1;
}

grammar_grammar Parse_state_grammar_grammar (void);	/* state 42 */
static int Parse_state_43 (SymbolSet followers);	/* state 43 */

static __inline__ int Parse_state_44 (void)	/* state 44 */
{ int n;
      n = 2; _grammar_symbol = grammar_value;
      { ParseValue me;
        grammar_Parser  parser = POP_PARSEVALUE (Pointer, grammar_Parser);
        grammar_Scanner  scanner = POP_PARSEVALUE (Pointer, grammar_Scanner);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("grammar_grammar");
        me->sub.PointerValue = Create_grammar_grammar(src_info, scanner, parser);
        Decorate_grammar(me->sub.PointerValue);
      }
  return n-1;
}

List_grammar_Token Parse_state_grammar_OPTMORE_Token (void);	/* state 45 */
grammar_RegExpr Parse_state_grammar_RegExpr (void);	/* state 46 */
List_String Parse_state_grammar_OPTMORE_ScanAction_semicolonsym (void);	/* state 47 */
grammar_Token Parse_state_grammar_Token (void);	/* state 48 */
grammar_RegExpr Parse_state_grammar_ChoiceRE (void);	/* state 49 */
grammar_RegExpr Parse_state_grammar_SeqRE (void);	/* state 50 */
grammar_RegExpr Parse_state_grammar_PostRE (void);	/* state 51 */
grammar_RegExpr Parse_state_grammar_BasicRE (void);	/* state 52 */
String Parse_state_grammar_ScanAction (void);	/* state 53 */
List_grammar_ProdRule Parse_state_grammar_OPTMORE_ProdRule (void);	/* state 54 */
grammar_ProdRule Parse_state_grammar_ProdRule (void);	/* state 55 */

/* directors of state 0
   hole_OPTMORE_Token hole_Token hole_RegExpr hole_ChoiceRE hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
grammar_Scanner Parse_state_grammar_Scanner (void)	/* state 0 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1f6015c2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(0);
    switch (_grammar_symbol) {
    case Scanner_value:
      n = 1; break; /* accept Scanner  ->  . OPTMORE_Token    followers: grammar_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0x1f6215c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        static Int my_followers[] = { 0x1f6215c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_13(_followers);
        break;
      }
    case hole_SeqRE_value: HOLE_ACTION (0, "SeqRE");
    case SeqRE_value:
      {
        static Int my_followers[] = { 0x1f6015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_16(_followers);
        break;
      }
    case hole_ChoiceRE_value: HOLE_ACTION (0, "ChoiceRE");
    case ChoiceRE_value:
      {
        static Int my_followers[] = { 0x1f6015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_18();
        break;
      }
    case hole_RegExpr_value: HOLE_ACTION (0, "RegExpr");
    case RegExpr_value:
      {
        static Int my_followers[] = { 0x1f6015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23(_followers);
        break;
      }
    case hole_Token_value: HOLE_ACTION (0, "Token");
    case Token_value:
      {
        n = Parse_state_31(followers);
        break;
      }
    case hole_OPTMORE_Token_value: HOLE_ACTION (0, "List_Token");
    case OPTMORE_Token_value:
      {
        n = Parse_state_33();
        break;
      }
    default:
    /* default item:Scanner  ->  . OPTMORE_Token     followers: grammar_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_grammar_Token);
      _grammar_symbol = OPTMORE_Token_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("grammar_Scanner")->sub.PointerValue;
}

/* directors of state 4
   Identsym 
 */
static int Parse_state_4 (SymbolSet followers)	/* state 4 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,grammar_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_5();
      }
  return n-1;
}

static int Parse_state_5 (void)	/* state 5 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_6();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 7
   hole_RegExpr hole_ChoiceRE hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
static int Parse_state_7 (SymbolSet followers)	/* state 7 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1e4015c2, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(7);
    switch (_grammar_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x1c021dfa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x1c021dfa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x1c021dfa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1c021dfa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x1c021dfa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x1c021dfa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0x1c021dc2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        static Int my_followers[] = { 0x20800, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_13(_followers);
        break;
      }
    case hole_SeqRE_value: HOLE_ACTION (0, "SeqRE");
    case SeqRE_value:
      {
        static Int my_followers[] = { 0x800, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_16(_followers);
        break;
      }
    case hole_ChoiceRE_value: HOLE_ACTION (0, "ChoiceRE");
    case ChoiceRE_value:
      {
        static Int my_followers[] = { 0x800, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_18();
        break;
      }
    case hole_RegExpr_value: HOLE_ACTION (0, "RegExpr");
    case RegExpr_value:
      {
        n = Parse_state_21();
        break;
      }
    default:
    /* default item:BasicRE  ->  openparsym . RegExpr closeparsym   followers: closeparsym hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym verticalbarsym grammar_EOF starsym plussym questionmarksym  */
/* nt = 0x821cb38 */
      n = 0; _grammar_symbol = RegExpr_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 9
   starsym plussym questionmarksym 
 */
static int Parse_state_9 (SymbolSet followers)	/* state 9 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x38, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(9);
    switch (_grammar_symbol) {
    case questionmarksym_value:
      {
        n = Parse_state_10();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        n = Parse_state_11();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        n = Parse_state_12();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
    /* default item:PostRE  ->  BasicRE .   followers: closeparsym hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym verticalbarsym grammar_EOF  */
      n = 1; _grammar_symbol = PostRE_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 13
   hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
static int Parse_state_13 (SymbolSet followers)	/* state 13 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1c0015c2, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(13);
    switch (_grammar_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0x1c0015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        n = Parse_state_13(followers);
        break;
      }
    case hole_SeqRE_value: HOLE_ACTION (0, "SeqRE");
    case SeqRE_value:
      {
        n = Parse_state_14();
        break;
      }
    case OPT_SeqRE_value:
      {
        n = Parse_state_15();
        break;
      }
    default:
    /* default item:SeqRE  ->  PostRE . OPT_SeqRE   followers: closeparsym openchainsym verticalbarsym grammar_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,grammar_RegExpr);
      _grammar_symbol = OPT_SeqRE_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 16
   verticalbarsym 
 */
static int Parse_state_16 (SymbolSet followers)	/* state 16 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x20000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(16);
    switch (_grammar_symbol) {
    case verticalbarsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
        break;
      }
    case OPT_verticalbarsym_RegExpr_value:
      {
        n = Parse_state_20();
        break;
      }
    default:
    /* default item:ChoiceRE  ->  SeqRE . OPT_verticalbarsym_RegExpr        followers: closeparsym openchainsym grammar_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,grammar_RegExpr);
      _grammar_symbol = OPT_verticalbarsym_RegExpr_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 17
   hole_RegExpr hole_ChoiceRE hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
static int Parse_state_17 (SymbolSet followers)	/* state 17 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1e4015c2, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(17);
    switch (_grammar_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0x1c0215c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_13(_followers);
        break;
      }
    case hole_SeqRE_value: HOLE_ACTION (0, "SeqRE");
    case SeqRE_value:
      {
        n = Parse_state_16(followers);
        break;
      }
    case hole_ChoiceRE_value: HOLE_ACTION (0, "ChoiceRE");
    case ChoiceRE_value:
      {
        n = Parse_state_18();
        break;
      }
    case hole_RegExpr_value: HOLE_ACTION (0, "RegExpr");
    case RegExpr_value:
      {
        n = Parse_state_19();
        break;
      }
    default:
    /* default item:OPT_verticalbarsym_RegExpr  ->  verticalbarsym . RegExpr        followers: closeparsym openchainsym grammar_EOF  */
/* nt = 0x821cb38 */
      n = 0; _grammar_symbol = RegExpr_value;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_21 (void)	/* state 21 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 23
   openchainsym 
 */
static int Parse_state_23 (SymbolSet followers)	/* state 23 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_24(followers);
      }
  return n-1;
}

/* directors of state 24
   hole_OPTMORE_ScanAction_semicolonsym hole_ScanAction Stringsym closechainsym 
 */
static int Parse_state_24 (SymbolSet followers)	/* state 24 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x20800044, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(24);
    switch (_grammar_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x10004, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25();
        break;
      }
    case hole_ScanAction_value: HOLE_ACTION (0, "String");
    case ScanAction_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_26(_followers);
        break;
      }
    case hole_OPTMORE_ScanAction_semicolonsym_value: HOLE_ACTION (0, "List_String");
    case OPTMORE_ScanAction_semicolonsym_value:
      {
        n = Parse_state_29();
        break;
      }
    default:
    /* default item:Token  ->  RegExpr openchainsym . OPTMORE_ScanAction_semicolonsym closechainsym followers: hole_OPTMORE_Token hole_Token hole_RegExpr hole_ChoiceRE hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym hole_Parser hole_OPTMORE_ProdRule hole_ProdRule Identsym grammar_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_String);
      _grammar_symbol = OPTMORE_ScanAction_semicolonsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 26
   semicolonsym 
 */
static int Parse_state_26 (SymbolSet followers)	/* state 26 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(followers);
      }
  return n-1;
}

/* directors of state 27
   hole_OPTMORE_ScanAction_semicolonsym hole_ScanAction Stringsym 
 */
static int Parse_state_27 (SymbolSet followers)	/* state 27 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x20800040, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(27);
    switch (_grammar_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25();
        break;
      }
    case hole_ScanAction_value: HOLE_ACTION (0, "String");
    case ScanAction_value:
      {
        n = Parse_state_26(followers);
        break;
      }
    case hole_OPTMORE_ScanAction_semicolonsym_value: HOLE_ACTION (0, "List_String");
    case OPTMORE_ScanAction_semicolonsym_value:
      {
        n = Parse_state_28();
        break;
      }
    default:
    /* default item:OPTMORE_ScanAction_semicolonsym  ->  ScanAction semicolonsym . OPTMORE_ScanAction_semicolonsym  followers: closechainsym grammar_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_String);
      _grammar_symbol = OPTMORE_ScanAction_semicolonsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_29 (void)	/* state 29 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_30();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 31
   hole_OPTMORE_Token hole_Token hole_RegExpr hole_ChoiceRE hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
static int Parse_state_31 (SymbolSet followers)	/* state 31 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1f6015c2, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(31);
    switch (_grammar_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0x1f6215c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        static Int my_followers[] = { 0x1f6215c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_13(_followers);
        break;
      }
    case hole_SeqRE_value: HOLE_ACTION (0, "SeqRE");
    case SeqRE_value:
      {
        static Int my_followers[] = { 0x1f6015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_16(_followers);
        break;
      }
    case hole_ChoiceRE_value: HOLE_ACTION (0, "ChoiceRE");
    case ChoiceRE_value:
      {
        static Int my_followers[] = { 0x1f6015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_18();
        break;
      }
    case hole_RegExpr_value: HOLE_ACTION (0, "RegExpr");
    case RegExpr_value:
      {
        static Int my_followers[] = { 0x1f6015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23(_followers);
        break;
      }
    case hole_Token_value: HOLE_ACTION (0, "Token");
    case Token_value:
      {
        n = Parse_state_31(followers);
        break;
      }
    case hole_OPTMORE_Token_value: HOLE_ACTION (0, "List_Token");
    case OPTMORE_Token_value:
      {
        n = Parse_state_32();
        break;
      }
    default:
    /* default item:OPTMORE_Token  ->  Token . OPTMORE_Token        followers: hole_Parser hole_OPTMORE_ProdRule hole_ProdRule Identsym grammar_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_grammar_Token);
      _grammar_symbol = OPTMORE_Token_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 34
   hole_OPTMORE_ProdRule hole_ProdRule Identsym 
 */
grammar_Parser Parse_state_grammar_Parser (void)	/* state 34 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xc0000200, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(34);
    switch (_grammar_symbol) {
    case Parser_value:
      n = 1; break; /* accept Parser  ->  . OPTMORE_ProdRule  followers: grammar_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0xc0000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,grammar_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(_followers);
        break;
      }
    case hole_ProdRule_value: HOLE_ACTION (0, "ProdRule");
    case ProdRule_value:
      {
        n = Parse_state_39(followers);
        break;
      }
    case hole_OPTMORE_ProdRule_value: HOLE_ACTION (0, "List_ProdRule");
    case OPTMORE_ProdRule_value:
      {
        n = Parse_state_41();
        break;
      }
    default:
    /* default item:Parser  ->  . OPTMORE_ProdRule   followers: grammar_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_grammar_ProdRule);
      _grammar_symbol = OPTMORE_ProdRule_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("grammar_Parser")->sub.PointerValue;
}

/* directors of state 35
   extrasym importsym nonterminalsym 
 */
static int Parse_state_35 (SymbolSet followers)	/* state 35 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xe000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(35);
    switch (_grammar_symbol) {
    case nonterminalsym_value:
      {
        n = Parse_state_36();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case importsym_value:
      {
        n = Parse_state_37();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case extrasym_value:
      {
        n = Parse_state_38();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ProdRule  ->  Identsym . extrasym       followers: hole_OPTMORE_ProdRule hole_ProdRule Identsym grammar_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "extrasym expected");
      dont_shift = TRUE; _grammar_symbol = extrasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 39
   hole_OPTMORE_ProdRule hole_ProdRule Identsym 
 */
static int Parse_state_39 (SymbolSet followers)	/* state 39 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xc0000200, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(39);
    switch (_grammar_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0xc0000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,grammar_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(_followers);
        break;
      }
    case hole_ProdRule_value: HOLE_ACTION (0, "ProdRule");
    case ProdRule_value:
      {
        n = Parse_state_39(followers);
        break;
      }
    case hole_OPTMORE_ProdRule_value: HOLE_ACTION (0, "List_ProdRule");
    case OPTMORE_ProdRule_value:
      {
        n = Parse_state_40();
        break;
      }
    default:
    /* default item:OPTMORE_ProdRule  ->  ProdRule . OPTMORE_ProdRule       followers: grammar_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_grammar_ProdRule);
      _grammar_symbol = OPTMORE_ProdRule_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 42
   hole_Scanner hole_OPTMORE_Token hole_Token hole_RegExpr hole_ChoiceRE hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym hole_Parser hole_OPTMORE_ProdRule hole_ProdRule Identsym 
 */
grammar_grammar Parse_state_grammar_grammar (void)	/* state 42 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xdf6c17c2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(42);
    switch (_grammar_symbol) {
    case grammar_value:
      n = 1; break; /* accept grammar  ->  . Scanner Parser   followers: grammar_EOF  */
    case hole_Parser_value:
    case hole_OPTMORE_ProdRule_value:
    case hole_ProdRule_value:
    case Identsym_value:
    case grammar_EOF_value:
      n = 0; _grammar_symbol = OPTMORE_Token_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_grammar_Token);
      }
      break;
    case Stringsym_value:
      {
        static Int my_followers[] = { 0xdf6a17fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0xdf6a17fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0xdf6a17fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0xdf6a17fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0xdf6a17fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0xdf6a17fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0xdf6a17c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        static Int my_followers[] = { 0xdf6a17c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_13(_followers);
        break;
      }
    case hole_SeqRE_value: HOLE_ACTION (0, "SeqRE");
    case SeqRE_value:
      {
        static Int my_followers[] = { 0xdf6817c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_16(_followers);
        break;
      }
    case hole_ChoiceRE_value: HOLE_ACTION (0, "ChoiceRE");
    case ChoiceRE_value:
      {
        static Int my_followers[] = { 0xdf6817c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_18();
        break;
      }
    case hole_RegExpr_value: HOLE_ACTION (0, "RegExpr");
    case RegExpr_value:
      {
        static Int my_followers[] = { 0xdf6817c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23(_followers);
        break;
      }
    case hole_Token_value: HOLE_ACTION (0, "Token");
    case Token_value:
      {
        static Int my_followers[] = { 0xc0080200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_31(_followers);
        break;
      }
    case hole_OPTMORE_Token_value: HOLE_ACTION (0, "List_Token");
    case OPTMORE_Token_value:
      {
        static Int my_followers[] = { 0xc0080200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_33();
        break;
      }
    case hole_Scanner_value: HOLE_ACTION (0, "Scanner");
    case Scanner_value:
      {
        n = Parse_state_43(followers);
        break;
      }
    default:
    /* default item:grammar  ->  . Scanner Parser    followers: grammar_EOF  */
/* nt = 0x821b620 */
      PUSH_PARSEVALUE(Pointer,0,grammar_Scanner);
      _grammar_symbol = Scanner_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("grammar_grammar")->sub.PointerValue;
}

/* directors of state 43
   hole_Parser hole_OPTMORE_ProdRule hole_ProdRule Identsym 
 */
static int Parse_state_43 (SymbolSet followers)	/* state 43 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xc0080200, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(43);
    switch (_grammar_symbol) {
    case grammar_EOF_value:
      n = 0; _grammar_symbol = OPTMORE_ProdRule_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_grammar_ProdRule);
      }
      break;
    case Identsym_value:
      {
        static Int my_followers[] = { 0xc0000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,grammar_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(_followers);
        break;
      }
    case hole_ProdRule_value: HOLE_ACTION (0, "ProdRule");
    case ProdRule_value:
      {
        n = Parse_state_39(followers);
        break;
      }
    case hole_OPTMORE_ProdRule_value: HOLE_ACTION (0, "List_ProdRule");
    case OPTMORE_ProdRule_value:
      {
        n = Parse_state_41();
        break;
      }
    case hole_Parser_value: HOLE_ACTION (0, "Parser");
    case Parser_value:
      {
        n = Parse_state_44();
        break;
      }
    default:
    /* default item:grammar  ->  Scanner . Parser   followers: grammar_EOF  */
/* nt = 0x82207f0 */
      PUSH_PARSEVALUE(Pointer,0,grammar_Parser);
      _grammar_symbol = Parser_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 45
   hole_Token hole_RegExpr hole_ChoiceRE hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
List_grammar_Token Parse_state_grammar_OPTMORE_Token (void)	/* state 45 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1f4015c2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(45);
    switch (_grammar_symbol) {
    case OPTMORE_Token_value:
      n = 1; break; /* accept OPTMORE_Token  ->  . Token OPTMORE_Token        followers: grammar_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x1f6215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0x1f6215c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        static Int my_followers[] = { 0x1f6215c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_13(_followers);
        break;
      }
    case hole_SeqRE_value: HOLE_ACTION (0, "SeqRE");
    case SeqRE_value:
      {
        static Int my_followers[] = { 0x1f6015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_16(_followers);
        break;
      }
    case hole_ChoiceRE_value: HOLE_ACTION (0, "ChoiceRE");
    case ChoiceRE_value:
      {
        static Int my_followers[] = { 0x1f6015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_18();
        break;
      }
    case hole_RegExpr_value: HOLE_ACTION (0, "RegExpr");
    case RegExpr_value:
      {
        static Int my_followers[] = { 0x1f6015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23(_followers);
        break;
      }
    case hole_Token_value: HOLE_ACTION (0, "Token");
    case Token_value:
      {
        n = Parse_state_31(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Token  ->  .     followers: grammar_EOF  */
      n = 0; _grammar_symbol = OPTMORE_Token_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_grammar_Token);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_grammar_Token")->sub.PointerValue;
}

/* directors of state 46
   hole_ChoiceRE hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
grammar_RegExpr Parse_state_grammar_RegExpr (void)	/* state 46 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1e0015c2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(46);
    switch (_grammar_symbol) {
    case RegExpr_value:
      n = 1; break; /* accept RegExpr  ->  . ChoiceRE followers: grammar_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0x1c0215c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_13(_followers);
        break;
      }
    case hole_SeqRE_value: HOLE_ACTION (0, "SeqRE");
    case SeqRE_value:
      {
        n = Parse_state_16(followers);
        break;
      }
    case hole_ChoiceRE_value: HOLE_ACTION (0, "ChoiceRE");
    case ChoiceRE_value:
      {
        n = Parse_state_18();
        break;
      }
    default:
    /* default item:RegExpr  ->  . ChoiceRE  followers: grammar_EOF  */
/* nt = 0x821d228 */
      InputError (SCAN_POSITION, TRUE, "ChoiceRE expected");
      PUSH_PARSEVALUE(Pointer,0,grammar_ChoiceRE);
      _grammar_symbol = ChoiceRE_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("grammar_RegExpr")->sub.PointerValue;
}

/* directors of state 47
   hole_ScanAction Stringsym 
 */
List_String Parse_state_grammar_OPTMORE_ScanAction_semicolonsym (void)	/* state 47 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x20000040, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(47);
    switch (_grammar_symbol) {
    case OPTMORE_ScanAction_semicolonsym_value:
      n = 1; break; /* accept OPTMORE_ScanAction_semicolonsym  ->  . ScanAction semicolonsym OPTMORE_ScanAction_semicolonsym  followers: grammar_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25();
        break;
      }
    case hole_ScanAction_value: HOLE_ACTION (0, "String");
    case ScanAction_value:
      {
        n = Parse_state_26(followers);
        break;
      }
    default:
    /* default item:OPTMORE_ScanAction_semicolonsym  ->  .   followers: grammar_EOF  */
      n = 0; _grammar_symbol = OPTMORE_ScanAction_semicolonsym_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_String);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_String")->sub.PointerValue;
}

/* directors of state 48
   hole_RegExpr hole_ChoiceRE hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
grammar_Token Parse_state_grammar_Token (void)	/* state 48 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1e4015c2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(48);
    switch (_grammar_symbol) {
    case Token_value:
      n = 1; break; /* accept Token  ->  . RegExpr openchainsym OPTMORE_ScanAction_semicolonsym closechainsym followers: grammar_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0x1c0215c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        static Int my_followers[] = { 0x20002, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_13(_followers);
        break;
      }
    case hole_SeqRE_value: HOLE_ACTION (0, "SeqRE");
    case SeqRE_value:
      {
        static Int my_followers[] = { 0x2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_16(_followers);
        break;
      }
    case hole_ChoiceRE_value: HOLE_ACTION (0, "ChoiceRE");
    case ChoiceRE_value:
      {
        static Int my_followers[] = { 0x2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_18();
        break;
      }
    case hole_RegExpr_value: HOLE_ACTION (0, "RegExpr");
    case RegExpr_value:
      {
        n = Parse_state_23(followers);
        break;
      }
    default:
    /* default item:Token  ->  . RegExpr openchainsym OPTMORE_ScanAction_semicolonsym closechainsym  followers: grammar_EOF  */
/* nt = 0x821cb38 */
      n = 0; _grammar_symbol = RegExpr_value;
      break;
    }
  } while (n==0);
  return PopParseValue("grammar_Token")->sub.PointerValue;
}

/* directors of state 49
   hole_SeqRE hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
grammar_RegExpr Parse_state_grammar_ChoiceRE (void)	/* state 49 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1c0015c2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(49);
    switch (_grammar_symbol) {
    case ChoiceRE_value:
      n = 1; break; /* accept ChoiceRE  ->  . SeqRE OPT_verticalbarsym_RegExpr        followers: grammar_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x1c0215fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0x1c0215c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_13(_followers);
        break;
      }
    case hole_SeqRE_value: HOLE_ACTION (0, "SeqRE");
    case SeqRE_value:
      {
        n = Parse_state_16(followers);
        break;
      }
    default:
    /* default item:ChoiceRE  ->  . SeqRE OPT_verticalbarsym_RegExpr followers: grammar_EOF  */
/* nt = 0x821d818 */
      InputError (SCAN_POSITION, TRUE, "SeqRE expected");
      PUSH_PARSEVALUE(Pointer,0,grammar_SeqRE);
      _grammar_symbol = SeqRE_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("grammar_RegExpr")->sub.PointerValue;
}

/* directors of state 50
   hole_PostRE hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
grammar_RegExpr Parse_state_grammar_SeqRE (void)	/* state 50 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x180015c2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(50);
    switch (_grammar_symbol) {
    case SeqRE_value:
      n = 1; break; /* accept SeqRE  ->  . PostRE OPT_SeqRE   followers: grammar_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x1c0015fa, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        static Int my_followers[] = { 0x1c0015c2, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9(_followers);
        break;
      }
    case hole_PostRE_value: HOLE_ACTION (0, "PostRE");
    case PostRE_value:
      {
        n = Parse_state_13(followers);
        break;
      }
    default:
    /* default item:SeqRE  ->  . PostRE OPT_SeqRE    followers: grammar_EOF  */
/* nt = 0x821e7d0 */
      n = 0; _grammar_symbol = PostRE_value;
      break;
    }
  } while (n==0);
  return PopParseValue("grammar_RegExpr")->sub.PointerValue;
}

/* directors of state 51
   hole_BasicRE dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
grammar_RegExpr Parse_state_grammar_PostRE (void)	/* state 51 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x100015c2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(51);
    switch (_grammar_symbol) {
    case PostRE_value:
      n = 1; break; /* accept PostRE  ->  . BasicRE   followers: grammar_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x38, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x38, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        static Int my_followers[] = { 0x38, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x38, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(_followers);
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x38, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case dotsym_value:
      {
        static Int my_followers[] = { 0x38, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_BasicRE_value: HOLE_ACTION (0, "BasicRE");
    case BasicRE_value:
      {
        n = Parse_state_9(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:PostRE  ->  . BasicRE    followers: grammar_EOF  */
/* nt = 0x821fdf0 */
      n = 0; _grammar_symbol = BasicRE_value;
      { ParseValue me;
        SrcInfo src_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);
        me = PushParseValue("grammar_RegExpr");
        me->sub.PointerValue = Create_grammar_AnyRE(src_info);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("grammar_RegExpr")->sub.PointerValue;
}

/* directors of state 52
   dotsym openparsym openchainsym dollarsym hatsym Stringsym 
 */
grammar_RegExpr Parse_state_grammar_BasicRE (void)	/* state 52 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x15c2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(52);
    switch (_grammar_symbol) {
    case BasicRE_value:
      n = 1; break; /* accept BasicRE  ->  . dotsym   followers: grammar_EOF  */
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1();
        break;
      }
    case hatsym_value:
      {
        n = Parse_state_2();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case dollarsym_value:
      {
        n = Parse_state_3();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openchainsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(followers);
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(followers);
        break;
      }
    case dotsym_value:
      {
        n = Parse_state_8();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:BasicRE  ->  . dotsym    followers: grammar_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "dotsym expected");
      dont_shift = TRUE; _grammar_symbol = dotsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("grammar_RegExpr")->sub.PointerValue;
}

/* directors of state 53
   Stringsym 
 */
String Parse_state_grammar_ScanAction (void)	/* state 53 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x40, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(53);
    switch (_grammar_symbol) {
    case ScanAction_value:
      n = 1; break; /* accept ScanAction  ->  . Stringsym     followers: grammar_EOF  */
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,grammar_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25();
        break;
      }
    default:
    /* default item:ScanAction  ->  . Stringsym      followers: grammar_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Stringsym expected");
      PUSH_PARSEVALUE(String,0,String);
      dont_shift = TRUE; _grammar_symbol = Stringsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("String")->sub.PointerValue;
}

/* directors of state 54
   hole_ProdRule Identsym 
 */
List_grammar_ProdRule Parse_state_grammar_OPTMORE_ProdRule (void)	/* state 54 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x80000200, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(54);
    switch (_grammar_symbol) {
    case OPTMORE_ProdRule_value:
      n = 1; break; /* accept OPTMORE_ProdRule  ->  . ProdRule OPTMORE_ProdRule       followers: grammar_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0xc0000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,grammar_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(_followers);
        break;
      }
    case hole_ProdRule_value: HOLE_ACTION (0, "ProdRule");
    case ProdRule_value:
      {
        n = Parse_state_39(followers);
        break;
      }
    default:
    /* default item:OPTMORE_ProdRule  ->  .  followers: grammar_EOF  */
      n = 0; _grammar_symbol = OPTMORE_ProdRule_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_grammar_ProdRule);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_grammar_ProdRule")->sub.PointerValue;
}

/* directors of state 55
   Identsym 
 */
grammar_ProdRule Parse_state_grammar_ProdRule (void)	/* state 55 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x200, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x1 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, grammar);
  _grammar_symbol = _grammar_token;
  do {
    REPORT(55);
    switch (_grammar_symbol) {
    case ProdRule_value:
      n = 1; break; /* accept ProdRule  ->  . Identsym extrasym       followers: grammar_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,grammar_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ProdRule  ->  . Identsym extrasym        followers: grammar_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _grammar_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("grammar_ProdRule")->sub.PointerValue;
}

