#include "egg_lalr.h"

#include "egg_y.h"

typedef enum {
  egg_NONSENSE,
  usessym_value,
  semicolonsym_value,
  equalssym_value,
  Stringsym_value,
  Identsym_value,
  openparsym_value,
  closeparsym_value,
  errorsym_value,
  warningsym_value,
  disabledsym_value,
  keysym_value,
  postsym_value,
  openchainsym_value,
  closechainsym_value,
  commasym_value,
  fatalsym_value,
  groupsym_value,
  hole_Uses_value,
  hole_OPTMORE_Group_value,
  hole_egg_value,
  hole_Strings_value,
  hole_ALT_Stringsym_SEP_commasym_value,
  hole_OPTMORE_Declaration_value,
  hole_Declarations_value,
  hole_MessageKind_value,
  hole_MORE_Expression_value,
  hole_Declaration_value,
  hole_Expression_value,
  hole_Params_value,
  hole_ALT_Expression_SEP_commasym_value,
  hole_OPTMORE_Statement_value,
  hole_Statements_value,
  hole_Message_value,
  hole_Statement_value,
  hole_Group_value,
  hole_SubMessages_value,
  hole_ALT_SubMessage_SEP_commasym_value,
  hole_SubMessage_value,
  egg_EOF_value,
  Uses_value,
  OPTMORE_Group_value,
  egg_value,
  Strings_value,
  ALT_Stringsym_SEP_commasym_value,
  OPTMORE_Declaration_value,
  Declarations_value,
  MessageKind_value,
  MORE_Expression_value,
  Declaration_value,
  Expression_value,
  Params_value,
  ALT_Expression_SEP_commasym_value,
  OPTMORE_Statement_value,
  Statements_value,
  Message_value,
  Statement_value,
  Group_value,
  OPT_fatalsym_value,
  SubMessages_value,
  ALT_SubMessage_SEP_commasym_value,
  SubMessage_value,
  OPT_openparsym_Identsym_closeparsym_value,
  OPT_groupsym_value,
  egg_ERROR
} eggSymbol;

static eggSymbol _egg_token;

static eggSymbol _egg_symbol;

#define NUM_TERMINALS 40

#define WORDS_IN_SET ((NUM_TERMINALS+BITSPERWORD-1)/BITSPERWORD)

static String egg_symbol_names[] = {
  "egg_NONSENSE",
  "usessym",
  "semicolonsym",
  "equalssym",
  "Stringsym",
  "Identsym",
  "openparsym",
  "closeparsym",
  "errorsym",
  "warningsym",
  "disabledsym",
  "keysym",
  "postsym",
  "openchainsym",
  "closechainsym",
  "commasym",
  "fatalsym",
  "groupsym",
  "hole_Uses",
  "hole_OPTMORE_Group",
  "hole_egg",
  "hole_Strings",
  "hole_ALT_Stringsym_SEP_commasym",
  "hole_OPTMORE_Declaration",
  "hole_Declarations",
  "hole_MessageKind",
  "hole_MORE_Expression",
  "hole_Declaration",
  "hole_Expression",
  "hole_Params",
  "hole_ALT_Expression_SEP_commasym",
  "hole_OPTMORE_Statement",
  "hole_Statements",
  "hole_Message",
  "hole_Statement",
  "hole_Group",
  "hole_SubMessages",
  "hole_ALT_SubMessage_SEP_commasym",
  "hole_SubMessage",
  "egg_EOF",
  "Uses",
  "OPTMORE_Group",
  "egg",
  "Strings",
  "ALT_Stringsym_SEP_commasym",
  "OPTMORE_Declaration",
  "Declarations",
  "MessageKind",
  "MORE_Expression",
  "Declaration",
  "Expression",
  "Params",
  "ALT_Expression_SEP_commasym",
  "OPTMORE_Statement",
  "Statements",
  "Message",
  "Statement",
  "Group",
  "OPT_fatalsym",
  "SubMessages",
  "ALT_SubMessage_SEP_commasym",
  "SubMessage",
  "OPT_openparsym_Identsym_closeparsym",
  "OPT_groupsym",
  "egg_ERROR"
};

static eggSymbol egg_terminal_map[2*egg_ERROR];

static void fill_terminal_map (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;
  egg_terminal_map[0] = egg_NONSENSE;
  egg_terminal_map[usessym-NONSENSE] = usessym_value;
  egg_terminal_map[semicolonsym-NONSENSE] = semicolonsym_value;
  egg_terminal_map[equalssym-NONSENSE] = equalssym_value;
  egg_terminal_map[Stringsym-NONSENSE] = Stringsym_value;
  egg_terminal_map[Identsym-NONSENSE] = Identsym_value;
  egg_terminal_map[openparsym-NONSENSE] = openparsym_value;
  egg_terminal_map[closeparsym-NONSENSE] = closeparsym_value;
  egg_terminal_map[errorsym-NONSENSE] = errorsym_value;
  egg_terminal_map[warningsym-NONSENSE] = warningsym_value;
  egg_terminal_map[disabledsym-NONSENSE] = disabledsym_value;
  egg_terminal_map[keysym-NONSENSE] = keysym_value;
  egg_terminal_map[postsym-NONSENSE] = postsym_value;
  egg_terminal_map[openchainsym-NONSENSE] = openchainsym_value;
  egg_terminal_map[closechainsym-NONSENSE] = closechainsym_value;
  egg_terminal_map[commasym-NONSENSE] = commasym_value;
  egg_terminal_map[fatalsym-NONSENSE] = fatalsym_value;
  egg_terminal_map[groupsym-NONSENSE] = groupsym_value;
  egg_terminal_map[hole_Uses-NONSENSE] = hole_Uses_value;
  egg_terminal_map[hole_OPTMORE_Group-NONSENSE] = hole_OPTMORE_Group_value;
  egg_terminal_map[hole_egg-NONSENSE] = hole_egg_value;
  egg_terminal_map[hole_Strings-NONSENSE] = hole_Strings_value;
  egg_terminal_map[hole_ALT_Stringsym_SEP_commasym-NONSENSE] = hole_ALT_Stringsym_SEP_commasym_value;
  egg_terminal_map[hole_OPTMORE_Declaration-NONSENSE] = hole_OPTMORE_Declaration_value;
  egg_terminal_map[hole_Declarations-NONSENSE] = hole_Declarations_value;
  egg_terminal_map[hole_MessageKind-NONSENSE] = hole_MessageKind_value;
  egg_terminal_map[hole_MORE_Expression-NONSENSE] = hole_MORE_Expression_value;
  egg_terminal_map[hole_Declaration-NONSENSE] = hole_Declaration_value;
  egg_terminal_map[hole_Expression-NONSENSE] = hole_Expression_value;
  egg_terminal_map[hole_Params-NONSENSE] = hole_Params_value;
  egg_terminal_map[hole_ALT_Expression_SEP_commasym-NONSENSE] = hole_ALT_Expression_SEP_commasym_value;
  egg_terminal_map[hole_OPTMORE_Statement-NONSENSE] = hole_OPTMORE_Statement_value;
  egg_terminal_map[hole_Statements-NONSENSE] = hole_Statements_value;
  egg_terminal_map[hole_Message-NONSENSE] = hole_Message_value;
  egg_terminal_map[hole_Statement-NONSENSE] = hole_Statement_value;
  egg_terminal_map[hole_Group-NONSENSE] = hole_Group_value;
  egg_terminal_map[hole_SubMessages-NONSENSE] = hole_SubMessages_value;
  egg_terminal_map[hole_ALT_SubMessage_SEP_commasym-NONSENSE] = hole_ALT_SubMessage_SEP_commasym_value;
  egg_terminal_map[hole_SubMessage-NONSENSE] = hole_SubMessage_value;
}

extern int egg_lex(void);
#define SHIFT() { _egg_token = egg_lex(); if (_egg_token==0) _egg_token = egg_EOF_value; else _egg_token = egg_terminal_map[_egg_token-NONSENSE]; }
#define HOLE_ACTION(term,s) PUSH_PARSEVALUE(Pointer,Get_sub_tree(),hole); SHIFT()
#ifdef TRACE_egg_PARSE
#define REPORT(n) \
    printf ("State %d,	symbol %s,	token %s\n", n, egg_symbol_names[_egg_symbol], egg_symbol_names[_egg_token]);
#else
#define REPORT(n)
#endif
#if !defined(__GNUC__)
# define __inline__
#endif
egg_Uses Parse_state_egg_Uses (void);	/* state 0 */
static int Parse_state_1 (SymbolSet followers);	/* state 1 */
static int Parse_state_2 (SymbolSet followers);	/* state 2 */
static int Parse_state_3 (SymbolSet followers);	/* state 3 */

static __inline__ int Parse_state_4 (void)	/* state 4 */
{ int n;
      n = 3; _egg_symbol = ALT_Stringsym_SEP_commasym_value;
      { /* alt action */
        List_String  _id_0_l = POP_PARSEVALUE (Pointer, List_String);
        String  _id_0 = POP_PARSEVALUE (String, String);
        PUSH_PARSEVALUE(Pointer,Create_List_String(_id_0,_id_0_l),List_String);
      }
  return n-1;
}


static __inline__ int Parse_state_5 (void)	/* state 5 */
{ int n;
      n = 1; _egg_symbol = Strings_value;
  return n-1;
}

static int Parse_state_6 (void);	/* state 6 */

static __inline__ int Parse_state_7 (void)	/* state 7 */
{ int n;
      n = 3; _egg_symbol = Uses_value;
      { ParseValue me;
        List_String  _id_0 = POP_PARSEVALUE (Pointer, List_String);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_Uses");
        me->sub.PointerValue = Create_egg_Uses(src_info, _id_0);
      }
  return n-1;
}

List_egg_Statement Parse_state_egg_OPTMORE_Group (void);	/* state 8 */

static __inline__ int Parse_state_9 (void)	/* state 9 */
{ int n;
      n = 1; _egg_symbol = OPT_fatalsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_10 (SymbolSet followers);	/* state 10 */
static int Parse_state_11 (SymbolSet followers);	/* state 11 */
static int Parse_state_12 (SymbolSet followers);	/* state 12 */
static int Parse_state_13 (void);	/* state 13 */

static __inline__ int Parse_state_14 (void)	/* state 14 */
{ int n;
      n = 3; _egg_symbol = OPT_openparsym_Identsym_closeparsym_value;
      { /* opt action */
        Ident  type = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,type,Ident);
      }
  return n-1;
}

static int Parse_state_15 (SymbolSet followers);	/* state 15 */

static __inline__ int Parse_state_16 (void)	/* state 16 */
{ int n;
      n = 1; _egg_symbol = OPT_groupsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_17 (SymbolSet followers);	/* state 17 */
static int Parse_state_18 (SymbolSet followers);	/* state 18 */

static __inline__ int Parse_state_19 (void)	/* state 19 */
{ int n;
      n = 1; _egg_symbol = MessageKind_value;
      PUSH_PARSEVALUE(Int,egg_ErrorMsg,egg_MessageKind);
  return n-1;
}


static __inline__ int Parse_state_20 (void)	/* state 20 */
{ int n;
      n = 1; _egg_symbol = MessageKind_value;
      PUSH_PARSEVALUE(Int,egg_WarningMsg,egg_MessageKind);
  return n-1;
}


static __inline__ int Parse_state_21 (void)	/* state 21 */
{ int n;
      n = 1; _egg_symbol = MessageKind_value;
      PUSH_PARSEVALUE(Int,egg_DisabledMsg,egg_MessageKind);
  return n-1;
}


static __inline__ int Parse_state_22 (void)	/* state 22 */
{ int n;
      n = 1; _egg_symbol = MessageKind_value;
      PUSH_PARSEVALUE(Int,egg_KeyMsg,egg_MessageKind);
  return n-1;
}


static __inline__ int Parse_state_23 (void)	/* state 23 */
{ int n;
      n = 1; _egg_symbol = MessageKind_value;
      PUSH_PARSEVALUE(Int,egg_PostMsg,egg_MessageKind);
  return n-1;
}

static int Parse_state_24 (SymbolSet followers);	/* state 24 */
static int Parse_state_25 (SymbolSet followers);	/* state 25 */

static __inline__ int Parse_state_26 (void)	/* state 26 */
{ int n;
      n = 1; _egg_symbol = Expression_value;
      { ParseValue me;
        String  s = POP_PARSEVALUE (String, String);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_Expression");
        me->sub.PointerValue = Create_egg_StringExpr(src_info, s);
      }
  return n-1;
}

static int Parse_state_27 (SymbolSet followers);	/* state 27 */
static int Parse_state_28 (SymbolSet followers);	/* state 28 */
static int Parse_state_29 (SymbolSet followers);	/* state 29 */
static int Parse_state_30 (SymbolSet followers);	/* state 30 */

static __inline__ int Parse_state_31 (void)	/* state 31 */
{ int n;
      n = 3; _egg_symbol = ALT_Expression_SEP_commasym_value;
      { /* alt action */
        List_egg_Expression  _id_0_l = POP_PARSEVALUE (Pointer, List_egg_Expression);
        egg_Expression  _id_0 = POP_PARSEVALUE (Pointer, egg_Expression);
        PUSH_PARSEVALUE(Pointer,Create_List_egg_Expression(_id_0,_id_0_l),List_egg_Expression);
      }
  return n-1;
}


static __inline__ int Parse_state_32 (void)	/* state 32 */
{ int n;
      n = 1; _egg_symbol = Params_value;
  return n-1;
}

static int Parse_state_33 (void);	/* state 33 */

static __inline__ int Parse_state_34 (void)	/* state 34 */
{ int n;
      n = 4; _egg_symbol = Expression_value;
      { ParseValue me;
        List_egg_Expression  _id_0 = POP_PARSEVALUE (Pointer, List_egg_Expression);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_Expression");
        me->sub.PointerValue = Create_egg_CallExpr(src_info, id, _id_0);
      }
  return n-1;
}

static int Parse_state_35 (SymbolSet followers);	/* state 35 */

static __inline__ int Parse_state_36 (void)	/* state 36 */
{ int n;
      n = 2; _egg_symbol = MORE_Expression_value;
      { /* more action */
        List_egg_Expression  exprs_l = POP_PARSEVALUE (Pointer, List_egg_Expression);
        egg_Expression  exprs = POP_PARSEVALUE (Pointer, egg_Expression);
        PUSH_PARSEVALUE(Pointer,Create_List_egg_Expression(exprs,exprs_l),List_egg_Expression);
      }
  return n-1;
}

static int Parse_state_37 (void);	/* state 37 */

static __inline__ int Parse_state_38 (void)	/* state 38 */
{ int n;
      n = 4; _egg_symbol = Declaration_value;
      { ParseValue me;
        List_egg_Expression  exprs = POP_PARSEVALUE (Pointer, List_egg_Expression);
        egg_MessageKind  kind = POP_PARSEVALUE (Int, egg_MessageKind);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_Declaration");
        me->sub.PointerValue = Create_egg_Declaration(src_info, kind, exprs);
      }
  return n-1;
}

static int Parse_state_39 (SymbolSet followers);	/* state 39 */

static __inline__ int Parse_state_40 (void)	/* state 40 */
{ int n;
      n = 2; _egg_symbol = OPTMORE_Declaration_value;
      { /* optmore action */
        List_egg_Declaration  decls_l = POP_PARSEVALUE (Pointer, List_egg_Declaration);
        egg_Declaration  decls = POP_PARSEVALUE (Pointer, egg_Declaration);
        PUSH_PARSEVALUE(Pointer,Create_List_egg_Declaration(decls,decls_l),List_egg_Declaration);
      }
  return n-1;
}


static __inline__ int Parse_state_41 (void)	/* state 41 */
{ int n;
      n = 1; _egg_symbol = Declarations_value;
  return n-1;
}

static int Parse_state_42 (SymbolSet followers);	/* state 42 */
static int Parse_state_43 (SymbolSet followers);	/* state 43 */
static int Parse_state_44 (SymbolSet followers);	/* state 44 */
static int Parse_state_45 (SymbolSet followers);	/* state 45 */

static __inline__ int Parse_state_46 (void)	/* state 46 */
{ int n;
      n = 2; _egg_symbol = SubMessage_value;
      { ParseValue me;
        String  msg = POP_PARSEVALUE (String, String);
        egg_MessageKind  kind = POP_PARSEVALUE (Int, egg_MessageKind);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_SubMessage");
        me->sub.PointerValue = Create_egg_SubMessage(src_info, kind, msg);
      }
  return n-1;
}

static int Parse_state_47 (SymbolSet followers);	/* state 47 */
static int Parse_state_48 (SymbolSet followers);	/* state 48 */

static __inline__ int Parse_state_49 (void)	/* state 49 */
{ int n;
      n = 3; _egg_symbol = ALT_SubMessage_SEP_commasym_value;
      { /* alt action */
        List_egg_SubMessage  _id_0_l = POP_PARSEVALUE (Pointer, List_egg_SubMessage);
        egg_SubMessage  _id_0 = POP_PARSEVALUE (Pointer, egg_SubMessage);
        PUSH_PARSEVALUE(Pointer,Create_List_egg_SubMessage(_id_0,_id_0_l),List_egg_SubMessage);
      }
  return n-1;
}


static __inline__ int Parse_state_50 (void)	/* state 50 */
{ int n;
      n = 1; _egg_symbol = SubMessages_value;
  return n-1;
}

static int Parse_state_51 (void);	/* state 51 */

static __inline__ int Parse_state_52 (void)	/* state 52 */
{ int n;
      n = 4; _egg_symbol = Message_value;
      { ParseValue me;
        List_egg_SubMessage  _id_0 = POP_PARSEVALUE (Pointer, List_egg_SubMessage);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        Bool  fatal = POP_PARSEVALUE (Bool, Bool);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_Statement");
        me->sub.PointerValue = Create_egg_Message(src_info, fatal, id, _id_0);
      }
  return n-1;
}


static __inline__ int Parse_state_53 (void)	/* state 53 */
{ int n;
      n = 1; _egg_symbol = Statement_value;
  return n-1;
}


static __inline__ int Parse_state_54 (void)	/* state 54 */
{ int n;
      n = 1; _egg_symbol = Statement_value;
  return n-1;
}

static int Parse_state_55 (SymbolSet followers);	/* state 55 */

static __inline__ int Parse_state_56 (void)	/* state 56 */
{ int n;
      n = 2; _egg_symbol = OPTMORE_Statement_value;
      { /* optmore action */
        List_egg_Statement  stats_l = POP_PARSEVALUE (Pointer, List_egg_Statement);
        egg_Statement  stats = POP_PARSEVALUE (Pointer, egg_Statement);
        PUSH_PARSEVALUE(Pointer,Create_List_egg_Statement(stats,stats_l),List_egg_Statement);
      }
  return n-1;
}


static __inline__ int Parse_state_57 (void)	/* state 57 */
{ int n;
      n = 1; _egg_symbol = Statements_value;
  return n-1;
}

static int Parse_state_58 (void);	/* state 58 */

static __inline__ int Parse_state_59 (void)	/* state 59 */
{ int n;
      n = 8; _egg_symbol = Group_value;
      { ParseValue me;
        List_egg_Statement  stats = POP_PARSEVALUE (Pointer, List_egg_Statement);
        List_egg_Declaration  decls = POP_PARSEVALUE (Pointer, List_egg_Declaration);
        Bool  group = POP_PARSEVALUE (Bool, Bool);
        Ident  type = POP_PARSEVALUE (Ident, Ident);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        Bool  fatal = POP_PARSEVALUE (Bool, Bool);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_Statement");
        me->sub.PointerValue = Create_egg_Group(src_info, fatal, id, type, group, decls, stats);
      }
  return n-1;
}

static int Parse_state_60 (SymbolSet followers);	/* state 60 */

static __inline__ int Parse_state_61 (void)	/* state 61 */
{ int n;
      n = 2; _egg_symbol = OPTMORE_Group_value;
      { /* optmore action */
        List_egg_Statement  groups_l = POP_PARSEVALUE (Pointer, List_egg_Statement);
        egg_Statement  groups = POP_PARSEVALUE (Pointer, egg_Statement);
        PUSH_PARSEVALUE(Pointer,Create_List_egg_Statement(groups,groups_l),List_egg_Statement);
      }
  return n-1;
}

egg_egg Parse_state_egg_egg (void);	/* state 62 */
static int Parse_state_63 (SymbolSet followers);	/* state 63 */

static __inline__ int Parse_state_64 (void)	/* state 64 */
{ int n;
      n = 2; _egg_symbol = egg_value;
      { ParseValue me;
        List_egg_Statement  groups = POP_PARSEVALUE (Pointer, List_egg_Statement);
        egg_Uses  uses = POP_PARSEVALUE (Pointer, egg_Uses);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_egg");
        me->sub.PointerValue = Create_egg_egg(src_info, uses, groups);
        Decorate_egg(me->sub.PointerValue);
      }
  return n-1;
}

List_String Parse_state_egg_Strings (void);	/* state 65 */
List_String Parse_state_egg_ALT_Stringsym_SEP_commasym (void);	/* state 66 */
List_egg_Declaration Parse_state_egg_OPTMORE_Declaration (void);	/* state 67 */
List_egg_Declaration Parse_state_egg_Declarations (void);	/* state 68 */
egg_MessageKind Parse_state_egg_MessageKind (void);	/* state 69 */
List_egg_Expression Parse_state_egg_MORE_Expression (void);	/* state 70 */
egg_Declaration Parse_state_egg_Declaration (void);	/* state 71 */
egg_Expression Parse_state_egg_Expression (void);	/* state 72 */
List_egg_Expression Parse_state_egg_Params (void);	/* state 73 */
List_egg_Expression Parse_state_egg_ALT_Expression_SEP_commasym (void);	/* state 74 */
List_egg_Statement Parse_state_egg_OPTMORE_Statement (void);	/* state 75 */
List_egg_Statement Parse_state_egg_Statements (void);	/* state 76 */
egg_Statement Parse_state_egg_Message (void);	/* state 77 */
static int Parse_state_78 (SymbolSet followers);	/* state 78 */
static int Parse_state_79 (SymbolSet followers);	/* state 79 */
egg_Statement Parse_state_egg_Statement (void);	/* state 80 */
egg_Statement Parse_state_egg_Group (void);	/* state 81 */
List_egg_SubMessage Parse_state_egg_SubMessages (void);	/* state 82 */
List_egg_SubMessage Parse_state_egg_ALT_SubMessage_SEP_commasym (void);	/* state 83 */
egg_SubMessage Parse_state_egg_SubMessage (void);	/* state 84 */

/* directors of state 0
   usessym 
 */
egg_Uses Parse_state_egg_Uses (void)	/* state 0 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(0);
    switch (_egg_symbol) {
    case Uses_value:
      n = 1; break; /* accept Uses  ->  . usessym Strings semicolonsym        followers: egg_EOF  */
    case usessym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(followers);
        break;
      }
    default:
    /* default item:Uses  ->  . usessym Strings semicolonsym     followers: egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "usessym expected");
      dont_shift = TRUE; _egg_symbol = usessym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("egg_Uses")->sub.PointerValue;
}

/* directors of state 1
   hole_Strings hole_ALT_Stringsym_SEP_commasym Stringsym 
 */
static int Parse_state_1 (SymbolSet followers)	/* state 1 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x600010, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(1);
    switch (_egg_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_2(_followers);
        break;
      }
    case hole_ALT_Stringsym_SEP_commasym_value: HOLE_ACTION (0, "List_String");
    case ALT_Stringsym_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_5();
        break;
      }
    case hole_Strings_value: HOLE_ACTION (0, "List_String");
    case Strings_value:
      {
        n = Parse_state_6();
        break;
      }
    default:
    /* default item:Uses  ->  usessym . Strings semicolonsym        followers: hole_OPTMORE_Group hole_Group fatalsym Identsym egg_EOF  */
/* nt = 0x83ada60 */
      InputError (SCAN_POSITION, TRUE, "Strings expected");
      PUSH_PARSEVALUE(Pointer,0,List_String);
      _egg_symbol = Strings_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 2
   commasym 
 */
static int Parse_state_2 (SymbolSet followers)	/* state 2 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(2);
    switch (_egg_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(followers);
        break;
      }
    default:
    /* default item:ALT_Stringsym_SEP_commasym  ->  Stringsym .     followers: semicolonsym egg_EOF  */
      n = 1; _egg_symbol = ALT_Stringsym_SEP_commasym_value;
      { /* alt action */
        String  _id_0 = POP_PARSEVALUE (String, String);
        PUSH_PARSEVALUE(Pointer,Create_List_String(_id_0,NULL),List_String);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 3
   hole_ALT_Stringsym_SEP_commasym Stringsym 
 */
static int Parse_state_3 (SymbolSet followers)	/* state 3 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x400010, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(3);
    switch (_egg_symbol) {
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_2(followers);
        break;
      }
    case hole_ALT_Stringsym_SEP_commasym_value: HOLE_ACTION (0, "List_String");
    case ALT_Stringsym_SEP_commasym_value:
      {
        n = Parse_state_4();
        break;
      }
    default:
    /* default item:ALT_Stringsym_SEP_commasym  ->  Stringsym commasym . ALT_Stringsym_SEP_commasym followers: semicolonsym egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Stringsym_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_String);
      _egg_symbol = ALT_Stringsym_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_6 (void)	/* state 6 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_7();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 8
   hole_Group fatalsym Identsym 
 */
List_egg_Statement Parse_state_egg_OPTMORE_Group (void)	/* state 8 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10020, 0x8 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(8);
    switch (_egg_symbol) {
    case OPTMORE_Group_value:
      n = 1; break; /* accept OPTMORE_Group  ->  . Group OPTMORE_Group        followers: egg_EOF  */
    case Identsym_value:
      n = 0; _egg_symbol = OPT_fatalsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case fatalsym_value:
      {
        static Int my_followers[] = { 0x90020, 0x8 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_fatalsym_value:
      {
        static Int my_followers[] = { 0x90020, 0x8 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_10(_followers);
        break;
      }
    case hole_Group_value: HOLE_ACTION (0, "Group");
    case Group_value:
      {
        n = Parse_state_60(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Group  ->  . followers: egg_EOF  */
      n = 0; _egg_symbol = OPTMORE_Group_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_egg_Statement);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_egg_Statement")->sub.PointerValue;
}

/* directors of state 10
   Identsym 
 */
static int Parse_state_10 (SymbolSet followers)	/* state 10 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_11(followers);
      }
  return n-1;
}

/* directors of state 11
   openparsym groupsym openchainsym 
 */
static int Parse_state_11 (SymbolSet followers)	/* state 11 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x22040, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(11);
    switch (_egg_symbol) {
    case openparsym_value:
      {
        static Int my_followers[] = { 0x22000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_12(_followers);
        break;
      }
    case OPT_openparsym_Identsym_closeparsym_value:
      {
        n = Parse_state_15(followers);
        break;
      }
    default:
    /* default item:Group  ->  OPT_fatalsym Identsym . OPT_openparsym_Identsym_closeparsym OPT_groupsym openchainsym Declarations Statements closechainsym  followers: hole_OPTMORE_Group hole_Group fatalsym Identsym egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      _egg_symbol = OPT_openparsym_Identsym_closeparsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 12
   Identsym 
 */
static int Parse_state_12 (SymbolSet followers)	/* state 12 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_13();
      }
  return n-1;
}

static int Parse_state_13 (void)	/* state 13 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_14();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 15
   groupsym openchainsym 
 */
static int Parse_state_15 (SymbolSet followers)	/* state 15 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x22000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(15);
    switch (_egg_symbol) {
    case groupsym_value:
      {
        static Int my_followers[] = { 0x2000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_16();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_groupsym_value:
      {
        n = Parse_state_17(followers);
        break;
      }
    default:
    /* default item:Group  ->  OPT_fatalsym Identsym OPT_openparsym_Identsym_closeparsym . OPT_groupsym openchainsym Declarations Statements closechainsym  followers: hole_OPTMORE_Group closechainsym hole_OPTMORE_Statement hole_Statement hole_Group fatalsym Identsym hole_Message egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _egg_symbol = OPT_groupsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 17
   openchainsym 
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
   hole_Declarations hole_OPTMORE_Declaration hole_Declaration hole_MessageKind postsym keysym disabledsym warningsym errorsym hole_Statements hole_OPTMORE_Statement hole_Statement hole_Group fatalsym Identsym hole_Message closechainsym 
 */
static int Parse_state_18 (SymbolSet followers)	/* state 18 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8b815f20, 0xf };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(18);
    switch (_egg_symbol) {
    case hole_Statements_value:
    case hole_OPTMORE_Statement_value:
    case hole_Statement_value:
    case hole_Group_value:
    case fatalsym_value:
    case Identsym_value:
    case hole_Message_value:
    case closechainsym_value:
      n = 0; _egg_symbol = OPTMORE_Declaration_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_egg_Declaration);
      }
      break;
    case errorsym_value:
      {
        static Int my_followers[] = { 0x8a815f28, 0xf };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0x8a815f28, 0xf };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0x8a815f28, 0xf };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0x8a815f28, 0xf };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0x8a815f28, 0xf };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        static Int my_followers[] = { 0x8a815f20, 0xf };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_24(_followers);
        break;
      }
    case hole_Declaration_value: HOLE_ACTION (0, "Declaration");
    case Declaration_value:
      {
        static Int my_followers[] = { 0x80014020, 0xf };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_39(_followers);
        break;
      }
    case hole_OPTMORE_Declaration_value: HOLE_ACTION (0, "List_Declaration");
    case OPTMORE_Declaration_value:
      {
        static Int my_followers[] = { 0x80014020, 0xf };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_41();
        break;
      }
    case hole_Declarations_value: HOLE_ACTION (0, "List_Declaration");
    case Declarations_value:
      {
        n = Parse_state_42(followers);
        break;
      }
    default:
    /* default item:Group  ->  OPT_fatalsym Identsym OPT_openparsym_Identsym_closeparsym OPT_groupsym openchainsym . Declarations Statements closechainsym  followers: hole_OPTMORE_Group closechainsym hole_OPTMORE_Statement hole_Statement hole_Group fatalsym Identsym hole_Message egg_EOF  */
/* nt = 0x83adea0 */
      PUSH_PARSEVALUE(Pointer,0,List_egg_Declaration);
      _egg_symbol = Declarations_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 24
   equalssym 
 */
static int Parse_state_24 (SymbolSet followers)	/* state 24 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25(followers);
      }
  return n-1;
}

/* directors of state 25
   hole_MORE_Expression hole_Expression Identsym Stringsym 
 */
static int Parse_state_25 (SymbolSet followers)	/* state 25 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x14000030, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(25);
    switch (_egg_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x14000034, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26();
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x14000034, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(_followers);
        break;
      }
    case hole_Expression_value: HOLE_ACTION (0, "Expression");
    case Expression_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_35(_followers);
        break;
      }
    case hole_MORE_Expression_value: HOLE_ACTION (0, "List_Expression");
    case MORE_Expression_value:
      {
        n = Parse_state_37();
        break;
      }
    default:
    /* default item:Declaration  ->  MessageKind equalssym . MORE_Expression semicolonsym   followers: hole_Statements hole_OPTMORE_Statement hole_Statement hole_Group fatalsym Identsym hole_Message closechainsym hole_OPTMORE_Declaration hole_Declaration hole_MessageKind postsym keysym disabledsym warningsym errorsym egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "MORE_Expression expected");
      PUSH_PARSEVALUE(Pointer,0,List_egg_Expression);
      _egg_symbol = MORE_Expression_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 27
   openparsym 
 */
static int Parse_state_27 (SymbolSet followers)	/* state 27 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x40, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(27);
    switch (_egg_symbol) {
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_28(followers);
        break;
      }
    default:
    /* default item:Expression  ->  Identsym .      followers: semicolonsym commasym closeparsym hole_MORE_Expression hole_Expression Identsym Stringsym egg_EOF  */
      n = 1; _egg_symbol = Expression_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_Expression");
        me->sub.PointerValue = Create_egg_IdExpr(src_info, id);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 28
   hole_Params hole_ALT_Expression_SEP_commasym hole_Expression Identsym Stringsym 
 */
static int Parse_state_28 (SymbolSet followers)	/* state 28 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x70000030, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(28);
    switch (_egg_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x8080, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26();
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x8080, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(_followers);
        break;
      }
    case hole_Expression_value: HOLE_ACTION (0, "Expression");
    case Expression_value:
      {
        static Int my_followers[] = { 0x80, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_29(_followers);
        break;
      }
    case hole_ALT_Expression_SEP_commasym_value: HOLE_ACTION (0, "List_Expression");
    case ALT_Expression_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x80, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_32();
        break;
      }
    case hole_Params_value: HOLE_ACTION (0, "List_Expression");
    case Params_value:
      {
        n = Parse_state_33();
        break;
      }
    default:
    /* default item:Expression  ->  Identsym openparsym . Params closeparsym        followers: semicolonsym commasym closeparsym hole_MORE_Expression hole_Expression Identsym Stringsym egg_EOF  */
/* nt = 0x83afba0 */
      InputError (SCAN_POSITION, TRUE, "Params expected");
      PUSH_PARSEVALUE(Pointer,0,List_egg_Expression);
      _egg_symbol = Params_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 29
   commasym 
 */
static int Parse_state_29 (SymbolSet followers)	/* state 29 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(29);
    switch (_egg_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_30(followers);
        break;
      }
    default:
    /* default item:ALT_Expression_SEP_commasym  ->  Expression .   followers: closeparsym egg_EOF  */
      n = 1; _egg_symbol = ALT_Expression_SEP_commasym_value;
      { /* alt action */
        egg_Expression  _id_0 = POP_PARSEVALUE (Pointer, egg_Expression);
        PUSH_PARSEVALUE(Pointer,Create_List_egg_Expression(_id_0,NULL),List_egg_Expression);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 30
   hole_ALT_Expression_SEP_commasym hole_Expression Identsym Stringsym 
 */
static int Parse_state_30 (SymbolSet followers)	/* state 30 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x50000030, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(30);
    switch (_egg_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26();
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(_followers);
        break;
      }
    case hole_Expression_value: HOLE_ACTION (0, "Expression");
    case Expression_value:
      {
        n = Parse_state_29(followers);
        break;
      }
    case hole_ALT_Expression_SEP_commasym_value: HOLE_ACTION (0, "List_Expression");
    case ALT_Expression_SEP_commasym_value:
      {
        n = Parse_state_31();
        break;
      }
    default:
    /* default item:ALT_Expression_SEP_commasym  ->  Expression commasym . ALT_Expression_SEP_commasym      followers: closeparsym egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Expression_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_egg_Expression);
      _egg_symbol = ALT_Expression_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_33 (void)	/* state 33 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_34();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 35
   hole_MORE_Expression hole_Expression Identsym Stringsym 
 */
static int Parse_state_35 (SymbolSet followers)	/* state 35 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x14000030, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(35);
    switch (_egg_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x14000030, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26();
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x14000030, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(_followers);
        break;
      }
    case hole_Expression_value: HOLE_ACTION (0, "Expression");
    case Expression_value:
      {
        n = Parse_state_35(followers);
        break;
      }
    case hole_MORE_Expression_value: HOLE_ACTION (0, "List_Expression");
    case MORE_Expression_value:
      {
        n = Parse_state_36();
        break;
      }
    default:
    /* default item:MORE_Expression  ->  Expression .       followers: semicolonsym egg_EOF  */
      n = 1; _egg_symbol = MORE_Expression_value;
      { /* more action */
        egg_Expression  exprs = POP_PARSEVALUE (Pointer, egg_Expression);
        PUSH_PARSEVALUE(Pointer,Create_List_egg_Expression(exprs,NULL),List_egg_Expression);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_37 (void)	/* state 37 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_38();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 39
   hole_OPTMORE_Declaration hole_Declaration hole_MessageKind postsym keysym disabledsym warningsym errorsym 
 */
static int Parse_state_39 (SymbolSet followers)	/* state 39 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xa801f00, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(39);
    switch (_egg_symbol) {
    case errorsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        static Int my_followers[] = { 0xa801f00, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_24(_followers);
        break;
      }
    case hole_Declaration_value: HOLE_ACTION (0, "Declaration");
    case Declaration_value:
      {
        n = Parse_state_39(followers);
        break;
      }
    case hole_OPTMORE_Declaration_value: HOLE_ACTION (0, "List_Declaration");
    case OPTMORE_Declaration_value:
      {
        n = Parse_state_40();
        break;
      }
    default:
    /* default item:OPTMORE_Declaration  ->  Declaration . OPTMORE_Declaration      followers: hole_Statements hole_OPTMORE_Statement hole_Statement hole_Group fatalsym Identsym hole_Message closechainsym egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_egg_Declaration);
      _egg_symbol = OPTMORE_Declaration_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 42
   hole_Statements hole_OPTMORE_Statement hole_Statement hole_Group fatalsym Identsym hole_Message closechainsym 
 */
static int Parse_state_42 (SymbolSet followers)	/* state 42 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x80014020, 0xf };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(42);
    switch (_egg_symbol) {
    case closechainsym_value:
      n = 0; _egg_symbol = OPTMORE_Statement_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_egg_Statement);
      }
      break;
    case Identsym_value:
      n = 0; _egg_symbol = OPT_fatalsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case fatalsym_value:
      {
        static Int my_followers[] = { 0x80014020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_fatalsym_value:
      {
        static Int my_followers[] = { 0x80014020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_43(_followers);
        break;
      }
    case hole_Message_value: HOLE_ACTION (0, "Message");
    case Message_value:
      {
        static Int my_followers[] = { 0x80014020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_53();
        break;
      }
    case hole_Group_value: HOLE_ACTION (0, "Group");
    case Group_value:
      {
        static Int my_followers[] = { 0x80014020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_54();
        break;
      }
    case hole_Statement_value: HOLE_ACTION (0, "Statement");
    case Statement_value:
      {
        static Int my_followers[] = { 0x4000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55(_followers);
        break;
      }
    case hole_OPTMORE_Statement_value: HOLE_ACTION (0, "List_Statement");
    case OPTMORE_Statement_value:
      {
        static Int my_followers[] = { 0x4000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_57();
        break;
      }
    case hole_Statements_value: HOLE_ACTION (0, "List_Statement");
    case Statements_value:
      {
        n = Parse_state_58();
        break;
      }
    default:
    /* default item:Group  ->  OPT_fatalsym Identsym OPT_openparsym_Identsym_closeparsym OPT_groupsym openchainsym Declarations . Statements closechainsym  followers: hole_OPTMORE_Group closechainsym hole_OPTMORE_Statement hole_Statement hole_Group fatalsym Identsym hole_Message egg_EOF  */
/* nt = 0x83affc0 */
      PUSH_PARSEVALUE(Pointer,0,List_egg_Statement);
      _egg_symbol = Statements_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 43
   Identsym 
 */
static int Parse_state_43 (SymbolSet followers)	/* state 43 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_44(followers);
      }
  return n-1;
}

/* directors of state 44
   openparsym groupsym openchainsym hole_SubMessages hole_ALT_SubMessage_SEP_commasym hole_SubMessage hole_MessageKind postsym keysym disabledsym warningsym errorsym 
 */
static int Parse_state_44 (SymbolSet followers)	/* state 44 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2023f40, 0x70 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(44);
    switch (_egg_symbol) {
    case groupsym_value:
    case openchainsym_value:
      n = 0; _egg_symbol = OPT_openparsym_Identsym_closeparsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,Ident);
      }
      break;
    case errorsym_value:
      {
        static Int my_followers[] = { 0x8014, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0x8014, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0x8014, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0x8014, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0x8014, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        static Int my_followers[] = { 0x8004, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_45(_followers);
        break;
      }
    case hole_SubMessage_value: HOLE_ACTION (0, "SubMessage");
    case SubMessage_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_47(_followers);
        break;
      }
    case hole_ALT_SubMessage_SEP_commasym_value: HOLE_ACTION (0, "List_SubMessage");
    case ALT_SubMessage_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_50();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x22000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_12(_followers);
        break;
      }
    case hole_SubMessages_value: HOLE_ACTION (0, "List_SubMessage");
    case SubMessages_value:
      {
        n = Parse_state_51();
        break;
      }
    case OPT_openparsym_Identsym_closeparsym_value:
      {
        n = Parse_state_15(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Group  ->  OPT_fatalsym Identsym . OPT_openparsym_Identsym_closeparsym OPT_groupsym openchainsym Declarations Statements closechainsym  followers: closechainsym hole_OPTMORE_Statement hole_Statement hole_Group fatalsym Identsym hole_Message egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      _egg_symbol = OPT_openparsym_Identsym_closeparsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 45
   Stringsym 
 */
static int Parse_state_45 (SymbolSet followers)	/* state 45 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_46();
      }
  return n-1;
}

/* directors of state 47
   commasym 
 */
static int Parse_state_47 (SymbolSet followers)	/* state 47 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(47);
    switch (_egg_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_48(followers);
        break;
      }
    default:
    /* default item:ALT_SubMessage_SEP_commasym  ->  SubMessage .   followers: semicolonsym egg_EOF  */
      n = 1; _egg_symbol = ALT_SubMessage_SEP_commasym_value;
      { /* alt action */
        egg_SubMessage  _id_0 = POP_PARSEVALUE (Pointer, egg_SubMessage);
        PUSH_PARSEVALUE(Pointer,Create_List_egg_SubMessage(_id_0,NULL),List_egg_SubMessage);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 48
   hole_ALT_SubMessage_SEP_commasym hole_SubMessage hole_MessageKind postsym keysym disabledsym warningsym errorsym 
 */
static int Parse_state_48 (SymbolSet followers)	/* state 48 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2001f00, 0x60 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(48);
    switch (_egg_symbol) {
    case errorsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        static Int my_followers[] = { 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_45(_followers);
        break;
      }
    case hole_SubMessage_value: HOLE_ACTION (0, "SubMessage");
    case SubMessage_value:
      {
        n = Parse_state_47(followers);
        break;
      }
    case hole_ALT_SubMessage_SEP_commasym_value: HOLE_ACTION (0, "List_SubMessage");
    case ALT_SubMessage_SEP_commasym_value:
      {
        n = Parse_state_49();
        break;
      }
    default:
    /* default item:ALT_SubMessage_SEP_commasym  ->  SubMessage commasym . ALT_SubMessage_SEP_commasym      followers: semicolonsym egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_SubMessage_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_egg_SubMessage);
      _egg_symbol = ALT_SubMessage_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_51 (void)	/* state 51 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_52();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 55
   hole_OPTMORE_Statement hole_Statement hole_Group fatalsym Identsym hole_Message 
 */
static int Parse_state_55 (SymbolSet followers)	/* state 55 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x80010020, 0xe };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(55);
    switch (_egg_symbol) {
    case Identsym_value:
      n = 0; _egg_symbol = OPT_fatalsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case fatalsym_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_fatalsym_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_43(_followers);
        break;
      }
    case hole_Message_value: HOLE_ACTION (0, "Message");
    case Message_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_53();
        break;
      }
    case hole_Group_value: HOLE_ACTION (0, "Group");
    case Group_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_54();
        break;
      }
    case hole_Statement_value: HOLE_ACTION (0, "Statement");
    case Statement_value:
      {
        n = Parse_state_55(followers);
        break;
      }
    case hole_OPTMORE_Statement_value: HOLE_ACTION (0, "List_Statement");
    case OPTMORE_Statement_value:
      {
        n = Parse_state_56();
        break;
      }
    default:
    /* default item:OPTMORE_Statement  ->  Statement . OPTMORE_Statement    followers: closechainsym egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_egg_Statement);
      _egg_symbol = OPTMORE_Statement_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_58 (void)	/* state 58 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_59();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 60
   hole_OPTMORE_Group hole_Group fatalsym Identsym 
 */
static int Parse_state_60 (SymbolSet followers)	/* state 60 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x90020, 0x8 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(60);
    switch (_egg_symbol) {
    case Identsym_value:
      n = 0; _egg_symbol = OPT_fatalsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case fatalsym_value:
      {
        static Int my_followers[] = { 0x90020, 0x8 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_fatalsym_value:
      {
        static Int my_followers[] = { 0x90020, 0x8 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_10(_followers);
        break;
      }
    case hole_Group_value: HOLE_ACTION (0, "Group");
    case Group_value:
      {
        n = Parse_state_60(followers);
        break;
      }
    case hole_OPTMORE_Group_value: HOLE_ACTION (0, "List_Statement");
    case OPTMORE_Group_value:
      {
        n = Parse_state_61();
        break;
      }
    default:
    /* default item:OPTMORE_Group  ->  Group . OPTMORE_Group        followers: egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_egg_Statement);
      _egg_symbol = OPTMORE_Group_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 62
   hole_Uses usessym 
 */
egg_egg Parse_state_egg_egg (void)	/* state 62 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x40002, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(62);
    switch (_egg_symbol) {
    case egg_value:
      n = 1; break; /* accept egg  ->  . Uses OPTMORE_Group   followers: egg_EOF  */
    case usessym_value:
      {
        static Int my_followers[] = { 0x90020, 0x8 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_Uses_value: HOLE_ACTION (0, "Uses");
    case Uses_value:
      {
        n = Parse_state_63(followers);
        break;
      }
    default:
    /* default item:egg  ->  . Uses OPTMORE_Group        followers: egg_EOF  */
/* nt = 0x83ad730 */
      InputError (SCAN_POSITION, TRUE, "Uses expected");
      PUSH_PARSEVALUE(Pointer,0,egg_Uses);
      _egg_symbol = Uses_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("egg_egg")->sub.PointerValue;
}

/* directors of state 63
   hole_OPTMORE_Group hole_Group fatalsym Identsym 
 */
static int Parse_state_63 (SymbolSet followers)	/* state 63 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x90020, 0x8 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(63);
    switch (_egg_symbol) {
    case Identsym_value:
      n = 0; _egg_symbol = OPT_fatalsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case fatalsym_value:
      {
        static Int my_followers[] = { 0x90020, 0x8 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_fatalsym_value:
      {
        static Int my_followers[] = { 0x90020, 0x8 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_10(_followers);
        break;
      }
    case hole_Group_value: HOLE_ACTION (0, "Group");
    case Group_value:
      {
        n = Parse_state_60(followers);
        break;
      }
    case hole_OPTMORE_Group_value: HOLE_ACTION (0, "List_Statement");
    case OPTMORE_Group_value:
      {
        n = Parse_state_64();
        break;
      }
    default:
    /* default item:egg  ->  Uses . OPTMORE_Group   followers: egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_egg_Statement);
      _egg_symbol = OPTMORE_Group_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 65
   hole_ALT_Stringsym_SEP_commasym Stringsym 
 */
List_String Parse_state_egg_Strings (void)	/* state 65 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x400010, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(65);
    switch (_egg_symbol) {
    case Strings_value:
      n = 1; break; /* accept Strings  ->  . ALT_Stringsym_SEP_commasym       followers: egg_EOF  */
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_2(followers);
        break;
      }
    case hole_ALT_Stringsym_SEP_commasym_value: HOLE_ACTION (0, "List_String");
    case ALT_Stringsym_SEP_commasym_value:
      {
        n = Parse_state_5();
        break;
      }
    default:
    /* default item:Strings  ->  . ALT_Stringsym_SEP_commasym    followers: egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Stringsym_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_String);
      _egg_symbol = ALT_Stringsym_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_String")->sub.PointerValue;
}

/* directors of state 66
   Stringsym 
 */
List_String Parse_state_egg_ALT_Stringsym_SEP_commasym (void)	/* state 66 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(66);
    switch (_egg_symbol) {
    case ALT_Stringsym_SEP_commasym_value:
      n = 1; break; /* accept ALT_Stringsym_SEP_commasym  ->  . Stringsym commasym ALT_Stringsym_SEP_commasym followers: egg_EOF  */
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_2(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_Stringsym_SEP_commasym  ->  . Stringsym  followers: egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Stringsym expected");
      PUSH_PARSEVALUE(String,0,String);
      dont_shift = TRUE; _egg_symbol = Stringsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_String")->sub.PointerValue;
}

/* directors of state 67
   hole_Declaration hole_MessageKind postsym keysym disabledsym warningsym errorsym 
 */
List_egg_Declaration Parse_state_egg_OPTMORE_Declaration (void)	/* state 67 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xa001f00, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(67);
    switch (_egg_symbol) {
    case OPTMORE_Declaration_value:
      n = 1; break; /* accept OPTMORE_Declaration  ->  . Declaration OPTMORE_Declaration      followers: egg_EOF  */
    case errorsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        static Int my_followers[] = { 0xa801f00, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_24(_followers);
        break;
      }
    case hole_Declaration_value: HOLE_ACTION (0, "Declaration");
    case Declaration_value:
      {
        n = Parse_state_39(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Declaration  ->  .   followers: egg_EOF  */
      n = 0; _egg_symbol = OPTMORE_Declaration_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_egg_Declaration);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_egg_Declaration")->sub.PointerValue;
}

/* directors of state 68
   hole_OPTMORE_Declaration hole_Declaration hole_MessageKind postsym keysym disabledsym warningsym errorsym 
 */
List_egg_Declaration Parse_state_egg_Declarations (void)	/* state 68 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xa801f00, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(68);
    switch (_egg_symbol) {
    case Declarations_value:
      n = 1; break; /* accept Declarations  ->  . OPTMORE_Declaration followers: egg_EOF  */
    case errorsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0xa801f08, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        static Int my_followers[] = { 0xa801f00, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_24(_followers);
        break;
      }
    case hole_Declaration_value: HOLE_ACTION (0, "Declaration");
    case Declaration_value:
      {
        n = Parse_state_39(followers);
        break;
      }
    case hole_OPTMORE_Declaration_value: HOLE_ACTION (0, "List_Declaration");
    case OPTMORE_Declaration_value:
      {
        n = Parse_state_41();
        break;
      }
    default:
    /* default item:Declarations  ->  . OPTMORE_Declaration      followers: egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_egg_Declaration);
      _egg_symbol = OPTMORE_Declaration_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_egg_Declaration")->sub.PointerValue;
}

/* directors of state 69
   postsym keysym disabledsym warningsym errorsym 
 */
egg_MessageKind Parse_state_egg_MessageKind (void)	/* state 69 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1f00, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(69);
    switch (_egg_symbol) {
    case MessageKind_value:
      n = 1; break; /* accept MessageKind  ->  . postsym      followers: egg_EOF  */
    case errorsym_value:
      {
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:MessageKind  ->  . postsym   followers: egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "postsym expected");
      dont_shift = TRUE; _egg_symbol = postsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("egg_MessageKind")->sub.IntValue;
}

/* directors of state 70
   hole_Expression Identsym Stringsym 
 */
List_egg_Expression Parse_state_egg_MORE_Expression (void)	/* state 70 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10000030, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(70);
    switch (_egg_symbol) {
    case MORE_Expression_value:
      n = 1; break; /* accept MORE_Expression  ->  . Expression MORE_Expression       followers: egg_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x14000030, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26();
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x14000030, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(_followers);
        break;
      }
    case hole_Expression_value: HOLE_ACTION (0, "Expression");
    case Expression_value:
      {
        n = Parse_state_35(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:MORE_Expression  ->  . Expression    followers: egg_EOF  */
/* nt = 0x83af830 */
      n = 0; _egg_symbol = Expression_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_Expression");
        me->sub.PointerValue = Create_egg_IdExpr(src_info, id);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_egg_Expression")->sub.PointerValue;
}

/* directors of state 71
   hole_MessageKind postsym keysym disabledsym warningsym errorsym 
 */
egg_Declaration Parse_state_egg_Declaration (void)	/* state 71 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2001f00, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(71);
    switch (_egg_symbol) {
    case Declaration_value:
      n = 1; break; /* accept Declaration  ->  . MessageKind equalssym MORE_Expression semicolonsym   followers: egg_EOF  */
    case errorsym_value:
      {
        static Int my_followers[] = { 0x8, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0x8, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0x8, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0x8, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0x8, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        n = Parse_state_24(followers);
        break;
      }
    default:
    /* default item:Declaration  ->  . MessageKind equalssym MORE_Expression semicolonsym        followers: egg_EOF  */
/* nt = 0x83b16c0 */
      n = 0; _egg_symbol = MessageKind_value;
      PUSH_PARSEVALUE(Int,egg_PostMsg,egg_MessageKind);
      break;
    }
  } while (n==0);
  return PopParseValue("egg_Declaration")->sub.PointerValue;
}

/* directors of state 72
   Identsym Stringsym 
 */
egg_Expression Parse_state_egg_Expression (void)	/* state 72 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x30, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(72);
    switch (_egg_symbol) {
    case Expression_value:
      n = 1; break; /* accept Expression  ->  . Identsym      followers: egg_EOF  */
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26();
        break;
      }
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Expression  ->  . Identsym   followers: egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _egg_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("egg_Expression")->sub.PointerValue;
}

/* directors of state 73
   hole_ALT_Expression_SEP_commasym hole_Expression Identsym Stringsym 
 */
List_egg_Expression Parse_state_egg_Params (void)	/* state 73 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x50000030, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(73);
    switch (_egg_symbol) {
    case Params_value:
      n = 1; break; /* accept Params  ->  . ALT_Expression_SEP_commasym       followers: egg_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26();
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(_followers);
        break;
      }
    case hole_Expression_value: HOLE_ACTION (0, "Expression");
    case Expression_value:
      {
        n = Parse_state_29(followers);
        break;
      }
    case hole_ALT_Expression_SEP_commasym_value: HOLE_ACTION (0, "List_Expression");
    case ALT_Expression_SEP_commasym_value:
      {
        n = Parse_state_32();
        break;
      }
    default:
    /* default item:Params  ->  . ALT_Expression_SEP_commasym    followers: egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Expression_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_egg_Expression);
      _egg_symbol = ALT_Expression_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_egg_Expression")->sub.PointerValue;
}

/* directors of state 74
   hole_Expression Identsym Stringsym 
 */
List_egg_Expression Parse_state_egg_ALT_Expression_SEP_commasym (void)	/* state 74 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10000030, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(74);
    switch (_egg_symbol) {
    case ALT_Expression_SEP_commasym_value:
      n = 1; break; /* accept ALT_Expression_SEP_commasym  ->  . Expression commasym ALT_Expression_SEP_commasym      followers: egg_EOF  */
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,egg_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26();
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(_followers);
        break;
      }
    case hole_Expression_value: HOLE_ACTION (0, "Expression");
    case Expression_value:
      {
        n = Parse_state_29(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_Expression_SEP_commasym  ->  . Expression        followers: egg_EOF  */
/* nt = 0x83af830 */
      n = 0; _egg_symbol = Expression_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("egg_Expression");
        me->sub.PointerValue = Create_egg_IdExpr(src_info, id);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_egg_Expression")->sub.PointerValue;
}

/* directors of state 75
   hole_Statement hole_Group fatalsym Identsym hole_Message 
 */
List_egg_Statement Parse_state_egg_OPTMORE_Statement (void)	/* state 75 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10020, 0xe };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(75);
    switch (_egg_symbol) {
    case OPTMORE_Statement_value:
      n = 1; break; /* accept OPTMORE_Statement  ->  . Statement OPTMORE_Statement    followers: egg_EOF  */
    case Identsym_value:
      n = 0; _egg_symbol = OPT_fatalsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case fatalsym_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_fatalsym_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_43(_followers);
        break;
      }
    case hole_Message_value: HOLE_ACTION (0, "Message");
    case Message_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_53();
        break;
      }
    case hole_Group_value: HOLE_ACTION (0, "Group");
    case Group_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_54();
        break;
      }
    case hole_Statement_value: HOLE_ACTION (0, "Statement");
    case Statement_value:
      {
        n = Parse_state_55(followers);
        break;
      }
    default:
    /* default item:OPTMORE_Statement  ->  .     followers: egg_EOF  */
      n = 0; _egg_symbol = OPTMORE_Statement_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_egg_Statement);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_egg_Statement")->sub.PointerValue;
}

/* directors of state 76
   hole_OPTMORE_Statement hole_Statement hole_Group fatalsym Identsym hole_Message 
 */
List_egg_Statement Parse_state_egg_Statements (void)	/* state 76 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x80010020, 0xe };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(76);
    switch (_egg_symbol) {
    case Statements_value:
      n = 1; break; /* accept Statements  ->  . OPTMORE_Statement     followers: egg_EOF  */
    case Identsym_value:
      n = 0; _egg_symbol = OPT_fatalsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case fatalsym_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_fatalsym_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_43(_followers);
        break;
      }
    case hole_Message_value: HOLE_ACTION (0, "Message");
    case Message_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_53();
        break;
      }
    case hole_Group_value: HOLE_ACTION (0, "Group");
    case Group_value:
      {
        static Int my_followers[] = { 0x80010020, 0xe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_54();
        break;
      }
    case hole_Statement_value: HOLE_ACTION (0, "Statement");
    case Statement_value:
      {
        n = Parse_state_55(followers);
        break;
      }
    case hole_OPTMORE_Statement_value: HOLE_ACTION (0, "List_Statement");
    case OPTMORE_Statement_value:
      {
        n = Parse_state_57();
        break;
      }
    default:
    /* default item:Statements  ->  . OPTMORE_Statement  followers: egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_egg_Statement);
      _egg_symbol = OPTMORE_Statement_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_egg_Statement")->sub.PointerValue;
}

/* directors of state 77
   fatalsym Identsym 
 */
egg_Statement Parse_state_egg_Message (void)	/* state 77 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10020, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(77);
    switch (_egg_symbol) {
    case Message_value:
      n = 1; break; /* accept Message  ->  . OPT_fatalsym Identsym SubMessages semicolonsym   followers: egg_EOF  */
    case fatalsym_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_fatalsym_value:
      {
        n = Parse_state_78(followers);
        break;
      }
    default:
    /* default item:Message  ->  . OPT_fatalsym Identsym SubMessages semicolonsym        followers: egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _egg_symbol = OPT_fatalsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("egg_Statement")->sub.PointerValue;
}

/* directors of state 78
   Identsym 
 */
static int Parse_state_78 (SymbolSet followers)	/* state 78 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,egg_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_79(followers);
      }
  return n-1;
}

/* directors of state 79
   hole_SubMessages hole_ALT_SubMessage_SEP_commasym hole_SubMessage hole_MessageKind postsym keysym disabledsym warningsym errorsym 
 */
static int Parse_state_79 (SymbolSet followers)	/* state 79 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2001f00, 0x70 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(79);
    switch (_egg_symbol) {
    case errorsym_value:
      {
        static Int my_followers[] = { 0x8014, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0x8014, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0x8014, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0x8014, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0x8014, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        static Int my_followers[] = { 0x8004, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_45(_followers);
        break;
      }
    case hole_SubMessage_value: HOLE_ACTION (0, "SubMessage");
    case SubMessage_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_47(_followers);
        break;
      }
    case hole_ALT_SubMessage_SEP_commasym_value: HOLE_ACTION (0, "List_SubMessage");
    case ALT_SubMessage_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_50();
        break;
      }
    case hole_SubMessages_value: HOLE_ACTION (0, "List_SubMessage");
    case SubMessages_value:
      {
        n = Parse_state_51();
        break;
      }
    default:
    /* default item:Message  ->  OPT_fatalsym Identsym . SubMessages semicolonsym   followers: egg_EOF  */
/* nt = 0x83b23e0 */
      InputError (SCAN_POSITION, TRUE, "SubMessages expected");
      PUSH_PARSEVALUE(Pointer,0,List_egg_SubMessage);
      _egg_symbol = SubMessages_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 80
   hole_Group fatalsym Identsym hole_Message 
 */
egg_Statement Parse_state_egg_Statement (void)	/* state 80 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10020, 0xa };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(80);
    switch (_egg_symbol) {
    case Statement_value:
      n = 1; break; /* accept Statement  ->  . Group  followers: egg_EOF  */
    case Identsym_value:
      n = 0; _egg_symbol = OPT_fatalsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case fatalsym_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_fatalsym_value:
      {
        n = Parse_state_43(followers);
        break;
      }
    case hole_Message_value: HOLE_ACTION (0, "Message");
    case Message_value:
      {
        n = Parse_state_53();
        break;
      }
    case hole_Group_value: HOLE_ACTION (0, "Group");
    case Group_value:
      {
        n = Parse_state_54();
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Statement  ->  . Group       followers: egg_EOF  */
/* nt = 0x83b3f70 */
      InputError (SCAN_POSITION, TRUE, "Group expected");
      PUSH_PARSEVALUE(Pointer,0,egg_Group);
      _egg_symbol = Group_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("egg_Statement")->sub.PointerValue;
}

/* directors of state 81
   fatalsym Identsym 
 */
egg_Statement Parse_state_egg_Group (void)	/* state 81 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10020, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(81);
    switch (_egg_symbol) {
    case Group_value:
      n = 1; break; /* accept Group  ->  . OPT_fatalsym Identsym OPT_openparsym_Identsym_closeparsym OPT_groupsym openchainsym Declarations Statements closechainsym  followers: egg_EOF  */
    case fatalsym_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_9();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_fatalsym_value:
      {
        n = Parse_state_10(followers);
        break;
      }
    default:
    /* default item:Group  ->  . OPT_fatalsym Identsym OPT_openparsym_Identsym_closeparsym OPT_groupsym openchainsym Declarations Statements closechainsym       followers: egg_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Bool,0,Bool);
      _egg_symbol = OPT_fatalsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("egg_Statement")->sub.PointerValue;
}

/* directors of state 82
   hole_ALT_SubMessage_SEP_commasym hole_SubMessage hole_MessageKind postsym keysym disabledsym warningsym errorsym 
 */
List_egg_SubMessage Parse_state_egg_SubMessages (void)	/* state 82 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2001f00, 0x60 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(82);
    switch (_egg_symbol) {
    case SubMessages_value:
      n = 1; break; /* accept SubMessages  ->  . ALT_SubMessage_SEP_commasym  followers: egg_EOF  */
    case errorsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        static Int my_followers[] = { 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_45(_followers);
        break;
      }
    case hole_SubMessage_value: HOLE_ACTION (0, "SubMessage");
    case SubMessage_value:
      {
        n = Parse_state_47(followers);
        break;
      }
    case hole_ALT_SubMessage_SEP_commasym_value: HOLE_ACTION (0, "List_SubMessage");
    case ALT_SubMessage_SEP_commasym_value:
      {
        n = Parse_state_50();
        break;
      }
    default:
    /* default item:SubMessages  ->  . ALT_SubMessage_SEP_commasym       followers: egg_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_SubMessage_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_egg_SubMessage);
      _egg_symbol = ALT_SubMessage_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_egg_SubMessage")->sub.PointerValue;
}

/* directors of state 83
   hole_SubMessage hole_MessageKind postsym keysym disabledsym warningsym errorsym 
 */
List_egg_SubMessage Parse_state_egg_ALT_SubMessage_SEP_commasym (void)	/* state 83 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2001f00, 0x40 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(83);
    switch (_egg_symbol) {
    case ALT_SubMessage_SEP_commasym_value:
      n = 1; break; /* accept ALT_SubMessage_SEP_commasym  ->  . SubMessage commasym ALT_SubMessage_SEP_commasym      followers: egg_EOF  */
    case errorsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0x8010, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        static Int my_followers[] = { 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_45(_followers);
        break;
      }
    case hole_SubMessage_value: HOLE_ACTION (0, "SubMessage");
    case SubMessage_value:
      {
        n = Parse_state_47(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_SubMessage_SEP_commasym  ->  . SubMessage        followers: egg_EOF  */
/* nt = 0x83b28d0 */
      InputError (SCAN_POSITION, TRUE, "SubMessage expected");
      PUSH_PARSEVALUE(Pointer,0,egg_SubMessage);
      _egg_symbol = SubMessage_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_egg_SubMessage")->sub.PointerValue;
}

/* directors of state 84
   hole_MessageKind postsym keysym disabledsym warningsym errorsym 
 */
egg_SubMessage Parse_state_egg_SubMessage (void)	/* state 84 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2001f00, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x80 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, egg);
  _egg_symbol = _egg_token;
  do {
    REPORT(84);
    switch (_egg_symbol) {
    case SubMessage_value:
      n = 1; break; /* accept SubMessage  ->  . MessageKind Stringsym followers: egg_EOF  */
    case errorsym_value:
      {
        static Int my_followers[] = { 0x10, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_19();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case warningsym_value:
      {
        static Int my_followers[] = { 0x10, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_20();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case disabledsym_value:
      {
        static Int my_followers[] = { 0x10, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case keysym_value:
      {
        static Int my_followers[] = { 0x10, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_22();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case postsym_value:
      {
        static Int my_followers[] = { 0x10, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_23();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hole_MessageKind_value: HOLE_ACTION (0, "MessageKind");
    case MessageKind_value:
      {
        n = Parse_state_45(followers);
        break;
      }
    default:
    /* default item:SubMessage  ->  . MessageKind Stringsym      followers: egg_EOF  */
/* nt = 0x83b16c0 */
      n = 0; _egg_symbol = MessageKind_value;
      PUSH_PARSEVALUE(Int,egg_PostMsg,egg_MessageKind);
      break;
    }
  } while (n==0);
  return PopParseValue("egg_SubMessage")->sub.PointerValue;
}

