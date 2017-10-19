#include "doggy_lalr.h"

#include "doggy_y.h"

typedef enum {
  doggy_NONSENSE,
  TYPESsym_value,
  Identsym_value,
  EXTERNALsym_value,
  externsym_value,
  semicolonsym_value,
  MACHINEsym_value,
  DESCRIPTIONsym_value,
  openparsym_value,
  closeparsym_value,
  OPRsym_value,
  Intsym_value,
  RULESsym_value,
  colonsym_value,
  FUNCTIONSsym_value,
  equalssym_value,
  openchainsym_value,
  closechainsym_value,
  NULLsym_value,
  _sym_value,
  verticalbarsym_value,
  arrowsym_value,
  WHEREsym_value,
  ANYsym_value,
  openbrksym_value,
  closebrksym_value,
  CONSsym_value,
  IFsym_value,
  THENsym_value,
  ELSEsym_value,
  FIsym_value,
  Boolsym_value,
  Stringsym_value,
  candsym_value,
  corsym_value,
  hatsym_value,
  eqsym_value,
  neqsym_value,
  lesym_value,
  gesym_value,
  lessthansym_value,
  greaterthansym_value,
  shlsym_value,
  shrsym_value,
  slashsym_value,
  percentsym_value,
  starsym_value,
  ampersandsym_value,
  plussym_value,
  minussym_value,
  openquotesym_value,
  exclaimsym_value,
  tildasym_value,
  dotdotsym_value,
  COMMUTATIVEsym_value,
  ATTRIBUTESsym_value,
  SUPPORTSsym_value,
  commasym_value,
  ELSIFsym_value,
  STEPsym_value,
  doggy_EOF_value,
  OPT_Typedefs_value,
  machine_description_value,
  OPT_machine_description_value,
  OPT_externals_value,
  OPTMORE_Section_value,
  doggy_value,
  OPTMORE_Typedef_value,
  Typedefs_value,
  OPT_Stringsym_Stringsym_Stringsym_value,
  OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_value,
  Typedef_value,
  OPTMORE_FunctionDef_value,
  externals_value,
  Type_value,
  ArgTypes_value,
  FunctionDef_value,
  OPTMORE_Operation_def_value,
  OPT_SUPPORTSsym_OPTMORE_Applied_formal_value,
  OPT_Types_value,
  OPT_colonsym_Type_value,
  OPTMORE_Property_value,
  Operation_def_value,
  OPT_Attrs_OPT_commasym_Attributes_value,
  Attributes_value,
  MORE_Attribute_value,
  Attrs_value,
  Attribute_value,
  Funcs_value,
  Section_value,
  Rules_value,
  OPT_colonsym_Identsym_value,
  OPTMORE_Rule_value,
  Lhs_value,
  Rhs_value,
  Rule_value,
  UnTypedPattern_value,
  OPTMORE_Func_value,
  OPT_externsym_value,
  FuncRules_value,
  Func_value,
  ALT_FuncRule_SEP_commasym_value,
  OPT_Arguments_value,
  FuncRule_value,
  ALT_Argument_SEP_commasym_value,
  Arguments_value,
  ArgPat2_value,
  Argument_value,
  Pattern_value,
  ArgPat_value,
  PatArg1_value,
  ParArg_value,
  SetArg_value,
  OPT_equalssym_UnTypedPattern_value,
  ParPattern_value,
  OpSet_value,
  BasicType_value,
  SimplePattern_value,
  ConsPattern_value,
  cons_value,
  IdentPattern_value,
  SingleDefPattern_value,
  DefPattern_value,
  IdParPattern_value,
  BinPattern_value,
  IdentPatterns_value,
  ALT_IdentPattern_SEP_commasym_value,
  BasicPattern_value,
  OPT_IdOp_SimplePattern_value,
  Applied_operation_value,
  OPT_Patterns_value,
  OPT_equalssym_SimpleExpr_value,
  MORE_Guard_value,
  OPT_Wherepart_value,
  Condition_value,
  Guard_value,
  OPT_verticalbarsym_Condition_value,
  ExprSeq_value,
  Expr_value,
  Exprs_value,
  OPTMORE_Definition_value,
  Wherepart_value,
  Applied_formal_value,
  Applied_formals_value,
  ALT_Applied_formal_SEP_commasym_value,
  ALT_SimpleExpr_SEP_Operator_value,
  IdOpExpr_value,
  ConsExpr_value,
  SimpleExpr_value,
  IdOp_value,
  OPTMORE_ELSIFsym_Condition_THENsym_Expr_value,
  Constant_value,
  OPT_Exprs_value,
  MonOp_value,
  Definition_value,
  Operator_value,
  ALT_BasicType_SEP_verticalbarsym_value,
  OPT_ArgTypes_value,
  Num_value,
  OPT_STEPsym_Num_value,
  Property_value,
  ALT_Pattern_SEP_commasym_value,
  Patterns_value,
  ALT_Expr_SEP_commasym_value,
  ALT_Type_SEP_commasym_value,
  Types_value,
  OPT_minussym_value,
  OPTMORE_Applied_formal_value,
  OPT_commasym_Attributes_value,
  doggy_ERROR
} doggySymbol;

static doggySymbol _doggy_token;

static doggySymbol _doggy_symbol;

#define NUM_TERMINALS 61

#define WORDS_IN_SET ((NUM_TERMINALS+BITSPERWORD-1)/BITSPERWORD)

static String doggy_symbol_names[] = {
  "doggy_NONSENSE",
  "TYPESsym",
  "Identsym",
  "EXTERNALsym",
  "externsym",
  "semicolonsym",
  "MACHINEsym",
  "DESCRIPTIONsym",
  "openparsym",
  "closeparsym",
  "OPRsym",
  "Intsym",
  "RULESsym",
  "colonsym",
  "FUNCTIONSsym",
  "equalssym",
  "openchainsym",
  "closechainsym",
  "NULLsym",
  "_sym",
  "verticalbarsym",
  "arrowsym",
  "WHEREsym",
  "ANYsym",
  "openbrksym",
  "closebrksym",
  "CONSsym",
  "IFsym",
  "THENsym",
  "ELSEsym",
  "FIsym",
  "Boolsym",
  "Stringsym",
  "candsym",
  "corsym",
  "hatsym",
  "eqsym",
  "neqsym",
  "lesym",
  "gesym",
  "lessthansym",
  "greaterthansym",
  "shlsym",
  "shrsym",
  "slashsym",
  "percentsym",
  "starsym",
  "ampersandsym",
  "plussym",
  "minussym",
  "openquotesym",
  "exclaimsym",
  "tildasym",
  "dotdotsym",
  "COMMUTATIVEsym",
  "ATTRIBUTESsym",
  "SUPPORTSsym",
  "commasym",
  "ELSIFsym",
  "STEPsym",
  "doggy_EOF",
  "OPT_Typedefs",
  "machine_description",
  "OPT_machine_description",
  "OPT_externals",
  "OPTMORE_Section",
  "doggy",
  "OPTMORE_Typedef",
  "Typedefs",
  "OPT_Stringsym_Stringsym_Stringsym",
  "OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym",
  "Typedef",
  "OPTMORE_FunctionDef",
  "externals",
  "Type",
  "ArgTypes",
  "FunctionDef",
  "OPTMORE_Operation_def",
  "OPT_SUPPORTSsym_OPTMORE_Applied_formal",
  "OPT_Types",
  "OPT_colonsym_Type",
  "OPTMORE_Property",
  "Operation_def",
  "OPT_Attrs_OPT_commasym_Attributes",
  "Attributes",
  "MORE_Attribute",
  "Attrs",
  "Attribute",
  "Funcs",
  "Section",
  "Rules",
  "OPT_colonsym_Identsym",
  "OPTMORE_Rule",
  "Lhs",
  "Rhs",
  "Rule",
  "UnTypedPattern",
  "OPTMORE_Func",
  "OPT_externsym",
  "FuncRules",
  "Func",
  "ALT_FuncRule_SEP_commasym",
  "OPT_Arguments",
  "FuncRule",
  "ALT_Argument_SEP_commasym",
  "Arguments",
  "ArgPat2",
  "Argument",
  "Pattern",
  "ArgPat",
  "PatArg1",
  "ParArg",
  "SetArg",
  "OPT_equalssym_UnTypedPattern",
  "ParPattern",
  "OpSet",
  "BasicType",
  "SimplePattern",
  "ConsPattern",
  "cons",
  "IdentPattern",
  "SingleDefPattern",
  "DefPattern",
  "IdParPattern",
  "BinPattern",
  "IdentPatterns",
  "ALT_IdentPattern_SEP_commasym",
  "BasicPattern",
  "OPT_IdOp_SimplePattern",
  "Applied_operation",
  "OPT_Patterns",
  "OPT_equalssym_SimpleExpr",
  "MORE_Guard",
  "OPT_Wherepart",
  "Condition",
  "Guard",
  "OPT_verticalbarsym_Condition",
  "ExprSeq",
  "Expr",
  "Exprs",
  "OPTMORE_Definition",
  "Wherepart",
  "Applied_formal",
  "Applied_formals",
  "ALT_Applied_formal_SEP_commasym",
  "ALT_SimpleExpr_SEP_Operator",
  "IdOpExpr",
  "ConsExpr",
  "SimpleExpr",
  "IdOp",
  "OPTMORE_ELSIFsym_Condition_THENsym_Expr",
  "Constant",
  "OPT_Exprs",
  "MonOp",
  "Definition",
  "Operator",
  "ALT_BasicType_SEP_verticalbarsym",
  "OPT_ArgTypes",
  "Num",
  "OPT_STEPsym_Num",
  "Property",
  "ALT_Pattern_SEP_commasym",
  "Patterns",
  "ALT_Expr_SEP_commasym",
  "ALT_Type_SEP_commasym",
  "Types",
  "OPT_minussym",
  "OPTMORE_Applied_formal",
  "OPT_commasym_Attributes",
  "doggy_ERROR"
};

static doggySymbol doggy_terminal_map[2*doggy_ERROR];

static void fill_terminal_map (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;
  doggy_terminal_map[0] = doggy_NONSENSE;
  doggy_terminal_map[TYPESsym-NONSENSE] = TYPESsym_value;
  doggy_terminal_map[Identsym-NONSENSE] = Identsym_value;
  doggy_terminal_map[EXTERNALsym-NONSENSE] = EXTERNALsym_value;
  doggy_terminal_map[externsym-NONSENSE] = externsym_value;
  doggy_terminal_map[semicolonsym-NONSENSE] = semicolonsym_value;
  doggy_terminal_map[MACHINEsym-NONSENSE] = MACHINEsym_value;
  doggy_terminal_map[DESCRIPTIONsym-NONSENSE] = DESCRIPTIONsym_value;
  doggy_terminal_map[openparsym-NONSENSE] = openparsym_value;
  doggy_terminal_map[closeparsym-NONSENSE] = closeparsym_value;
  doggy_terminal_map[OPRsym-NONSENSE] = OPRsym_value;
  doggy_terminal_map[Intsym-NONSENSE] = Intsym_value;
  doggy_terminal_map[RULESsym-NONSENSE] = RULESsym_value;
  doggy_terminal_map[colonsym-NONSENSE] = colonsym_value;
  doggy_terminal_map[FUNCTIONSsym-NONSENSE] = FUNCTIONSsym_value;
  doggy_terminal_map[equalssym-NONSENSE] = equalssym_value;
  doggy_terminal_map[openchainsym-NONSENSE] = openchainsym_value;
  doggy_terminal_map[closechainsym-NONSENSE] = closechainsym_value;
  doggy_terminal_map[NULLsym-NONSENSE] = NULLsym_value;
  doggy_terminal_map[_sym-NONSENSE] = _sym_value;
  doggy_terminal_map[verticalbarsym-NONSENSE] = verticalbarsym_value;
  doggy_terminal_map[arrowsym-NONSENSE] = arrowsym_value;
  doggy_terminal_map[WHEREsym-NONSENSE] = WHEREsym_value;
  doggy_terminal_map[ANYsym-NONSENSE] = ANYsym_value;
  doggy_terminal_map[openbrksym-NONSENSE] = openbrksym_value;
  doggy_terminal_map[closebrksym-NONSENSE] = closebrksym_value;
  doggy_terminal_map[CONSsym-NONSENSE] = CONSsym_value;
  doggy_terminal_map[IFsym-NONSENSE] = IFsym_value;
  doggy_terminal_map[THENsym-NONSENSE] = THENsym_value;
  doggy_terminal_map[ELSEsym-NONSENSE] = ELSEsym_value;
  doggy_terminal_map[FIsym-NONSENSE] = FIsym_value;
  doggy_terminal_map[Boolsym-NONSENSE] = Boolsym_value;
  doggy_terminal_map[Stringsym-NONSENSE] = Stringsym_value;
  doggy_terminal_map[candsym-NONSENSE] = candsym_value;
  doggy_terminal_map[corsym-NONSENSE] = corsym_value;
  doggy_terminal_map[hatsym-NONSENSE] = hatsym_value;
  doggy_terminal_map[eqsym-NONSENSE] = eqsym_value;
  doggy_terminal_map[neqsym-NONSENSE] = neqsym_value;
  doggy_terminal_map[lesym-NONSENSE] = lesym_value;
  doggy_terminal_map[gesym-NONSENSE] = gesym_value;
  doggy_terminal_map[lessthansym-NONSENSE] = lessthansym_value;
  doggy_terminal_map[greaterthansym-NONSENSE] = greaterthansym_value;
  doggy_terminal_map[shlsym-NONSENSE] = shlsym_value;
  doggy_terminal_map[shrsym-NONSENSE] = shrsym_value;
  doggy_terminal_map[slashsym-NONSENSE] = slashsym_value;
  doggy_terminal_map[percentsym-NONSENSE] = percentsym_value;
  doggy_terminal_map[starsym-NONSENSE] = starsym_value;
  doggy_terminal_map[ampersandsym-NONSENSE] = ampersandsym_value;
  doggy_terminal_map[plussym-NONSENSE] = plussym_value;
  doggy_terminal_map[minussym-NONSENSE] = minussym_value;
  doggy_terminal_map[openquotesym-NONSENSE] = openquotesym_value;
  doggy_terminal_map[exclaimsym-NONSENSE] = exclaimsym_value;
  doggy_terminal_map[tildasym-NONSENSE] = tildasym_value;
  doggy_terminal_map[dotdotsym-NONSENSE] = dotdotsym_value;
  doggy_terminal_map[COMMUTATIVEsym-NONSENSE] = COMMUTATIVEsym_value;
  doggy_terminal_map[ATTRIBUTESsym-NONSENSE] = ATTRIBUTESsym_value;
  doggy_terminal_map[SUPPORTSsym-NONSENSE] = SUPPORTSsym_value;
  doggy_terminal_map[commasym-NONSENSE] = commasym_value;
  doggy_terminal_map[ELSIFsym-NONSENSE] = ELSIFsym_value;
  doggy_terminal_map[STEPsym-NONSENSE] = STEPsym_value;
}

extern int doggy_lex(void);
#define SHIFT() { _doggy_token = doggy_lex(); if (_doggy_token==0) _doggy_token = doggy_EOF_value; else _doggy_token = doggy_terminal_map[_doggy_token-NONSENSE]; }
#define HOLE_ACTION(term,s) PUSH_PARSEVALUE(Pointer,Get_sub_tree(),hole); SHIFT()
#ifdef TRACE_doggy_PARSE
#define REPORT(n) \
    printf ("State %d,	symbol %s,	token %s\n", n, doggy_symbol_names[_doggy_symbol], doggy_symbol_names[_doggy_token]);
#else
#define REPORT(n)
#endif
#if !defined(__GNUC__)
# define __inline__
#endif
doggy_doggy Parse_state_doggy_doggy (void);	/* state 0 */
static int Parse_state_1 (SymbolSet followers);	/* state 1 */
static int Parse_state_2 (SymbolSet followers);	/* state 2 */
static int Parse_state_3 (SymbolSet followers);	/* state 3 */
static int Parse_state_4 (SymbolSet followers);	/* state 4 */

static __inline__ int Parse_state_5 (void)	/* state 5 */
{ int n;
      n = 3; _doggy_symbol = OPT_Stringsym_Stringsym_Stringsym_value;
      { /* opt action */
        String  value = POP_PARSEVALUE (String, String);
        String  short_hand = POP_PARSEVALUE (String, String);
        String  name = POP_PARSEVALUE (String, String);
        PUSH_PARSEVALUE(Pointer,name,String);
        PUSH_PARSEVALUE(Pointer,short_hand,String);
        PUSH_PARSEVALUE(Pointer,value,String);
      }
  return n-1;
}

static int Parse_state_6 (SymbolSet followers);	/* state 6 */
static int Parse_state_7 (SymbolSet followers);	/* state 7 */
static int Parse_state_8 (SymbolSet followers);	/* state 8 */

static __inline__ int Parse_state_9 (void)	/* state 9 */
{ int n;
      n = 1; _doggy_symbol = Attribute_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Attribute");
        me->sub.PointerValue = Create_doggy_IdAttr(src_info, id);
      }
  return n-1;
}


static __inline__ int Parse_state_10 (void)	/* state 10 */
{ int n;
      n = 1; _doggy_symbol = Attribute_value;
      { ParseValue me;
        SrcInfo src_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);
        me = PushParseValue("doggy_Attribute");
        me->sub.PointerValue = Create_doggy_OpAttr(src_info);
      }
  return n-1;
}


static __inline__ int Parse_state_11 (void)	/* state 11 */
{ int n;
      n = 1; _doggy_symbol = Attribute_value;
      { ParseValue me;
        Int  i = POP_PARSEVALUE (Int, Int);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Attribute");
        me->sub.PointerValue = Create_doggy_IntAttr(src_info, i);
      }
  return n-1;
}

static int Parse_state_12 (SymbolSet followers);	/* state 12 */

static __inline__ int Parse_state_13 (void)	/* state 13 */
{ int n;
      n = 2; _doggy_symbol = MORE_Attribute_value;
      { /* more action */
        List_doggy_Attribute  ids_l = POP_PARSEVALUE (Pointer, List_doggy_Attribute);
        doggy_Attribute  ids = POP_PARSEVALUE (Pointer, doggy_Attribute);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Attribute(ids,ids_l),List_doggy_Attribute);
      }
  return n-1;
}


static __inline__ int Parse_state_14 (void)	/* state 14 */
{ int n;
      n = 1; _doggy_symbol = Attrs_value;
  return n-1;
}

static int Parse_state_15 (SymbolSet followers);	/* state 15 */
static int Parse_state_16 (SymbolSet followers);	/* state 16 */

static __inline__ int Parse_state_17 (void)	/* state 17 */
{ int n;
      n = 1; _doggy_symbol = Attributes_value;
      { ParseValue me;
        doggy_Attributes  tail = POP_PARSEVALUE (Pointer, doggy_Attributes);
        List_doggy_Attribute  ids = POP_PARSEVALUE (Pointer, List_doggy_Attribute);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Attributes");
        me->sub.PointerValue = Create_doggy_Attributes(src_info, ids, tail);
      }
  return n-1;
}


static __inline__ int Parse_state_18 (void)	/* state 18 */
{ int n;
      n = 2; _doggy_symbol = OPT_commasym_Attributes_value;
      { /* opt action */
        doggy_Attributes  tail = POP_PARSEVALUE (Pointer, doggy_Attributes);
        PUSH_PARSEVALUE(Pointer,tail,doggy_Attributes);
      }
  return n-1;
}


static __inline__ int Parse_state_19 (void)	/* state 19 */
{ int n;
      n = 2; _doggy_symbol = OPT_Attrs_OPT_commasym_Attributes_value;
      { /* opt action */
        doggy_Attributes  tail = POP_PARSEVALUE (Pointer, doggy_Attributes);
        List_doggy_Attribute  ids = POP_PARSEVALUE (Pointer, List_doggy_Attribute);
        PUSH_PARSEVALUE(Pointer,ids,List_doggy_Attribute);
        PUSH_PARSEVALUE(Pointer,tail,doggy_Attributes);
      }
  return n-1;
}

static int Parse_state_20 (void);	/* state 20 */

static __inline__ int Parse_state_21 (void)	/* state 21 */
{ int n;
      n = 4; _doggy_symbol = OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_value;
      { /* opt action */
        doggy_Attributes  attrs = POP_PARSEVALUE (Pointer, doggy_Attributes);
        PUSH_PARSEVALUE(Pointer,attrs,doggy_Attributes);
      }
  return n-1;
}


static __inline__ int Parse_state_22 (void)	/* state 22 */
{ int n;
      n = 3; _doggy_symbol = Typedef_value;
      { ParseValue me;
        doggy_Attributes  attrs = POP_PARSEVALUE (Pointer, doggy_Attributes);
        String  value = POP_PARSEVALUE (String, String);
        String  short_hand = POP_PARSEVALUE (String, String);
        String  name = POP_PARSEVALUE (String, String);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Typedef");
        me->sub.PointerValue = Create_doggy_Typedef(src_info, id, name, short_hand, value, attrs);
      }
  return n-1;
}

static int Parse_state_23 (SymbolSet followers);	/* state 23 */

static __inline__ int Parse_state_24 (void)	/* state 24 */
{ int n;
      n = 2; _doggy_symbol = OPTMORE_Typedef_value;
      { /* optmore action */
        List_doggy_Typedef  types_l = POP_PARSEVALUE (Pointer, List_doggy_Typedef);
        doggy_Typedef  types = POP_PARSEVALUE (Pointer, doggy_Typedef);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Typedef(types,types_l),List_doggy_Typedef);
      }
  return n-1;
}


static __inline__ int Parse_state_25 (void)	/* state 25 */
{ int n;
      n = 2; _doggy_symbol = Typedefs_value;
  return n-1;
}


static __inline__ int Parse_state_26 (void)	/* state 26 */
{ int n;
      n = 1; _doggy_symbol = OPT_Typedefs_value;
      { /* opt action */
        List_doggy_Typedef  types = POP_PARSEVALUE (Pointer, List_doggy_Typedef);
        PUSH_PARSEVALUE(Pointer,types,List_doggy_Typedef);
      }
  return n-1;
}

static int Parse_state_27 (SymbolSet followers);	/* state 27 */
static int Parse_state_28 (SymbolSet followers);	/* state 28 */
static int Parse_state_29 (SymbolSet followers);	/* state 29 */
static int Parse_state_30 (SymbolSet followers);	/* state 30 */
static int Parse_state_31 (SymbolSet followers);	/* state 31 */
static int Parse_state_32 (SymbolSet followers);	/* state 32 */

static __inline__ int Parse_state_33 (void)	/* state 33 */
{ int n;
      n = 1; _doggy_symbol = BasicType_value;
      { ParseValue me;
        Ident  type_id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_IdentType(src_info, type_id);
      }
  return n-1;
}

static int Parse_state_34 (SymbolSet followers);	/* state 34 */
static int Parse_state_35 (SymbolSet followers);	/* state 35 */
static int Parse_state_36 (SymbolSet followers);	/* state 36 */

static __inline__ int Parse_state_37 (void)	/* state 37 */
{ int n;
      n = 2; _doggy_symbol = BasicType_value;
      { ParseValue me;
        doggy_Type  base = POP_PARSEVALUE (Pointer, doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_PointerType(src_info, base);
      }
  return n-1;
}

static int Parse_state_38 (SymbolSet followers);	/* state 38 */
static int Parse_state_39 (SymbolSet followers);	/* state 39 */

static __inline__ int Parse_state_40 (void)	/* state 40 */
{ int n;
      n = 1; _doggy_symbol = OPT_minussym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_41 (SymbolSet followers);	/* state 41 */

static __inline__ int Parse_state_42 (void)	/* state 42 */
{ int n;
      n = 2; _doggy_symbol = Num_value;
      { ParseValue me;
        Int  i = POP_PARSEVALUE (Int, Int);
        Bool  neg = POP_PARSEVALUE (Bool, Bool);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Num");
        me->sub.PointerValue = Create_doggy_Num(src_info, neg, i);
      }
  return n-1;
}

static int Parse_state_43 (SymbolSet followers);	/* state 43 */
static int Parse_state_44 (SymbolSet followers);	/* state 44 */
static int Parse_state_45 (SymbolSet followers);	/* state 45 */
static int Parse_state_46 (SymbolSet followers);	/* state 46 */

static __inline__ int Parse_state_47 (void)	/* state 47 */
{ int n;
      n = 2; _doggy_symbol = OPT_STEPsym_Num_value;
      { /* opt action */
        doggy_Num  step = POP_PARSEVALUE (Pointer, doggy_Num);
        PUSH_PARSEVALUE(Pointer,step,doggy_Num);
      }
  return n-1;
}

static int Parse_state_48 (void);	/* state 48 */

static __inline__ int Parse_state_49 (void)	/* state 49 */
{ int n;
      n = 6; _doggy_symbol = BasicType_value;
      { ParseValue me;
        doggy_Num  step = POP_PARSEVALUE (Pointer, doggy_Num);
        doggy_Num  hi = POP_PARSEVALUE (Pointer, doggy_Num);
        doggy_Num  lo = POP_PARSEVALUE (Pointer, doggy_Num);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_RangeType(src_info, lo, hi, step);
      }
  return n-1;
}

static int Parse_state_50 (void);	/* state 50 */
static int Parse_state_51 (void);	/* state 51 */
static int Parse_state_52 (void);	/* state 52 */

static __inline__ int Parse_state_53 (void)	/* state 53 */
{ int n;
      n = 5; _doggy_symbol = BasicType_value;
      { ParseValue me;
        Ident  f = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_FRangeType(src_info, f);
      }
  return n-1;
}


static __inline__ int Parse_state_54 (void)	/* state 54 */
{ int n;
      n = 3; _doggy_symbol = ALT_BasicType_SEP_verticalbarsym_value;
      { /* alt action */
        List_doggy_Type  types_l = POP_PARSEVALUE (Pointer, List_doggy_Type);
        doggy_Type  types = POP_PARSEVALUE (Pointer, doggy_Type);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Type(types,types_l),List_doggy_Type);
      }
  return n-1;
}


static __inline__ int Parse_state_55 (void)	/* state 55 */
{ int n;
      n = 1; _doggy_symbol = Type_value;
      { ParseValue me;
        List_doggy_Type  types = POP_PARSEVALUE (Pointer, List_doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_EdgeType(src_info, types);
      }
  return n-1;
}

static int Parse_state_56 (SymbolSet followers);	/* state 56 */
static int Parse_state_57 (SymbolSet followers);	/* state 57 */
static int Parse_state_58 (SymbolSet followers);	/* state 58 */

static __inline__ int Parse_state_59 (void)	/* state 59 */
{ int n;
      n = 3; _doggy_symbol = ALT_Type_SEP_commasym_value;
      { /* alt action */
        List_doggy_Type  t_l = POP_PARSEVALUE (Pointer, List_doggy_Type);
        doggy_Type  t = POP_PARSEVALUE (Pointer, doggy_Type);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Type(t,t_l),List_doggy_Type);
      }
  return n-1;
}


static __inline__ int Parse_state_60 (void)	/* state 60 */
{ int n;
      n = 1; _doggy_symbol = Types_value;
  return n-1;
}


static __inline__ int Parse_state_61 (void)	/* state 61 */
{ int n;
      n = 1; _doggy_symbol = OPT_Types_value;
      { /* opt action */
        List_doggy_Type  t = POP_PARSEVALUE (Pointer, List_doggy_Type);
        PUSH_PARSEVALUE(Pointer,t,List_doggy_Type);
      }
  return n-1;
}

static int Parse_state_62 (void);	/* state 62 */

static __inline__ int Parse_state_63 (void)	/* state 63 */
{ int n;
      n = 3; _doggy_symbol = Type_value;
      { ParseValue me;
        List_doggy_Type  t = POP_PARSEVALUE (Pointer, List_doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_TupleType(src_info, t);
      }
  return n-1;
}

static int Parse_state_64 (void);	/* state 64 */

static __inline__ int Parse_state_65 (void)	/* state 65 */
{ int n;
      n = 3; _doggy_symbol = ArgTypes_value;
  return n-1;
}


static __inline__ int Parse_state_66 (void)	/* state 66 */
{ int n;
      n = 1; _doggy_symbol = OPT_ArgTypes_value;
      { /* opt action */
        List_doggy_Type  args = POP_PARSEVALUE (Pointer, List_doggy_Type);
        PUSH_PARSEVALUE(Pointer,args,List_doggy_Type);
      }
  return n-1;
}


static __inline__ int Parse_state_67 (void)	/* state 67 */
{ int n;
      n = 2; _doggy_symbol = BasicType_value;
      { ParseValue me;
        List_doggy_Type  args = POP_PARSEVALUE (Pointer, List_doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_OprType(src_info, args);
      }
  return n-1;
}

static int Parse_state_68 (SymbolSet followers);	/* state 68 */
static int Parse_state_69 (SymbolSet followers);	/* state 69 */
static int Parse_state_70 (SymbolSet followers);	/* state 70 */

static __inline__ int Parse_state_71 (void)	/* state 71 */
{ int n;
      n = 2; _doggy_symbol = OPT_colonsym_Type_value;
      { /* opt action */
        doggy_Type  result = POP_PARSEVALUE (Pointer, doggy_Type);
        PUSH_PARSEVALUE(Pointer,result,doggy_Type);
      }
  return n-1;
}

static int Parse_state_72 (SymbolSet followers);	/* state 72 */
static int Parse_state_73 (SymbolSet followers);	/* state 73 */
static int Parse_state_74 (SymbolSet followers);	/* state 74 */

static __inline__ int Parse_state_75 (void)	/* state 75 */
{ int n;
      n = 1; _doggy_symbol = Property_value;
      PUSH_PARSEVALUE(Int,FALSE,doggy_Property);
  return n-1;
}

static int Parse_state_76 (SymbolSet followers);	/* state 76 */

static __inline__ int Parse_state_77 (void)	/* state 77 */
{ int n;
      n = 2; _doggy_symbol = OPTMORE_Property_value;
      { /* optmore action */
        List_doggy_Property  props_l = POP_PARSEVALUE (Pointer, List_doggy_Property);
        doggy_Property  props = POP_PARSEVALUE (Int, doggy_Property);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Property(props,props_l),List_doggy_Property);
      }
  return n-1;
}


static __inline__ int Parse_state_78 (void)	/* state 78 */
{ int n;
      n = 8; _doggy_symbol = Operation_def_value;
      { ParseValue me;
        List_doggy_Property  props = POP_PARSEVALUE (Pointer, List_doggy_Property);
        doggy_Attributes  descr = POP_PARSEVALUE (Pointer, doggy_Attributes);
        Ident  actual_id = POP_PARSEVALUE (Ident, Ident);
        doggy_Type  result = POP_PARSEVALUE (Pointer, doggy_Type);
        List_doggy_Type  t = POP_PARSEVALUE (Pointer, List_doggy_Type);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Operation_def");
        me->sub.PointerValue = Create_doggy_Operation_def(src_info, id, t, result, actual_id, descr, props);
      }
  return n-1;
}

static int Parse_state_79 (SymbolSet followers);	/* state 79 */

static __inline__ int Parse_state_80 (void)	/* state 80 */
{ int n;
      n = 2; _doggy_symbol = OPTMORE_Operation_def_value;
      { /* optmore action */
        List_doggy_Operation_def  defs_l = POP_PARSEVALUE (Pointer, List_doggy_Operation_def);
        doggy_Operation_def  defs = POP_PARSEVALUE (Pointer, doggy_Operation_def);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Operation_def(defs,defs_l),List_doggy_Operation_def);
      }
  return n-1;
}

static int Parse_state_81 (SymbolSet followers);	/* state 81 */
static int Parse_state_82 (SymbolSet followers);	/* state 82 */

static __inline__ int Parse_state_83 (void)	/* state 83 */
{ int n;
      n = 1; _doggy_symbol = Applied_formal_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Applied_formal");
        me->sub.PointerValue = Create_doggy_Applied_formal(src_info, id);
      }
  return n-1;
}

static int Parse_state_84 (SymbolSet followers);	/* state 84 */

static __inline__ int Parse_state_85 (void)	/* state 85 */
{ int n;
      n = 2; _doggy_symbol = OPTMORE_Applied_formal_value;
      { /* optmore action */
        List_doggy_Applied_formal  supports_l = POP_PARSEVALUE (Pointer, List_doggy_Applied_formal);
        doggy_Applied_formal  supports = POP_PARSEVALUE (Pointer, doggy_Applied_formal);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Applied_formal(supports,supports_l),List_doggy_Applied_formal);
      }
  return n-1;
}


static __inline__ int Parse_state_86 (void)	/* state 86 */
{ int n;
      n = 2; _doggy_symbol = OPT_SUPPORTSsym_OPTMORE_Applied_formal_value;
      { /* opt action */
        List_doggy_Applied_formal  supports = POP_PARSEVALUE (Pointer, List_doggy_Applied_formal);
        PUSH_PARSEVALUE(Pointer,supports,List_doggy_Applied_formal);
      }
  return n-1;
}


static __inline__ int Parse_state_87 (void)	/* state 87 */
{ int n;
      n = 5; _doggy_symbol = machine_description_value;
      { ParseValue me;
        List_doggy_Applied_formal  supports = POP_PARSEVALUE (Pointer, List_doggy_Applied_formal);
        List_doggy_Operation_def  defs = POP_PARSEVALUE (Pointer, List_doggy_Operation_def);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_machine_description");
        me->sub.PointerValue = Create_doggy_machine_description(src_info, id, defs, supports);
      }
  return n-1;
}

static int Parse_state_88 (SymbolSet followers);	/* state 88 */

static __inline__ int Parse_state_89 (void)	/* state 89 */
{ int n;
      n = 1; _doggy_symbol = OPT_machine_description_value;
      { /* opt action */
        doggy_machine_description  target = POP_PARSEVALUE (Pointer, doggy_machine_description);
        PUSH_PARSEVALUE(Pointer,target,doggy_machine_description);
      }
  return n-1;
}

static int Parse_state_90 (SymbolSet followers);	/* state 90 */
static int Parse_state_91 (SymbolSet followers);	/* state 91 */
static int Parse_state_92 (SymbolSet followers);	/* state 92 */
static int Parse_state_93 (SymbolSet followers);	/* state 93 */
static int Parse_state_94 (SymbolSet followers);	/* state 94 */
static int Parse_state_95 (void);	/* state 95 */

static __inline__ int Parse_state_96 (void)	/* state 96 */
{ int n;
      n = 5; _doggy_symbol = FunctionDef_value;
      { ParseValue me;
        List_doggy_Type  args = POP_PARSEVALUE (Pointer, List_doggy_Type);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        doggy_Type  result = POP_PARSEVALUE (Pointer, doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_FunctionDef");
        me->sub.PointerValue = Create_doggy_ExtFunc(src_info, result, id, args);
      }
  return n-1;
}


static __inline__ int Parse_state_97 (void)	/* state 97 */
{ int n;
      n = 4; _doggy_symbol = FunctionDef_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        doggy_Type  result = POP_PARSEVALUE (Pointer, doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_FunctionDef");
        me->sub.PointerValue = Create_doggy_ExtVar(src_info, result, id);
      }
  return n-1;
}

static int Parse_state_98 (SymbolSet followers);	/* state 98 */

static __inline__ int Parse_state_99 (void)	/* state 99 */
{ int n;
      n = 2; _doggy_symbol = OPTMORE_FunctionDef_value;
      { /* optmore action */
        List_doggy_FunctionDef  funcs_l = POP_PARSEVALUE (Pointer, List_doggy_FunctionDef);
        doggy_FunctionDef  funcs = POP_PARSEVALUE (Pointer, doggy_FunctionDef);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_FunctionDef(funcs,funcs_l),List_doggy_FunctionDef);
      }
  return n-1;
}


static __inline__ int Parse_state_100 (void)	/* state 100 */
{ int n;
      n = 2; _doggy_symbol = externals_value;
  return n-1;
}


static __inline__ int Parse_state_101 (void)	/* state 101 */
{ int n;
      n = 1; _doggy_symbol = OPT_externals_value;
      { /* opt action */
        List_doggy_FunctionDef  funcs = POP_PARSEVALUE (Pointer, List_doggy_FunctionDef);
        PUSH_PARSEVALUE(Pointer,funcs,List_doggy_FunctionDef);
      }
  return n-1;
}

static int Parse_state_102 (SymbolSet followers);	/* state 102 */
static int Parse_state_103 (SymbolSet followers);	/* state 103 */

static __inline__ int Parse_state_104 (void)	/* state 104 */
{ int n;
      n = 1; _doggy_symbol = OPT_externsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,TRUE,Bool);
      }
  return n-1;
}

static int Parse_state_105 (SymbolSet followers);	/* state 105 */
static int Parse_state_106 (SymbolSet followers);	/* state 106 */
static int Parse_state_107 (SymbolSet followers);	/* state 107 */
static int Parse_state_108 (SymbolSet followers);	/* state 108 */
static int Parse_state_109 (SymbolSet followers);	/* state 109 */
static int Parse_state_110 (SymbolSet followers);	/* state 110 */
static int Parse_state_111 (SymbolSet followers);	/* state 111 */
static int Parse_state_112 (SymbolSet followers);	/* state 112 */
static int Parse_state_113 (SymbolSet followers);	/* state 113 */
static int Parse_state_114 (SymbolSet followers);	/* state 114 */
static int Parse_state_115 (SymbolSet followers);	/* state 115 */

static __inline__ int Parse_state_116 (void)	/* state 116 */
{ int n;
      n = 3; _doggy_symbol = ALT_Applied_formal_SEP_commasym_value;
      { /* alt action */
        List_doggy_Applied_formal  ops_l = POP_PARSEVALUE (Pointer, List_doggy_Applied_formal);
        doggy_Applied_formal  ops = POP_PARSEVALUE (Pointer, doggy_Applied_formal);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Applied_formal(ops,ops_l),List_doggy_Applied_formal);
      }
  return n-1;
}


static __inline__ int Parse_state_117 (void)	/* state 117 */
{ int n;
      n = 1; _doggy_symbol = Applied_formals_value;
  return n-1;
}

static int Parse_state_118 (void);	/* state 118 */

static __inline__ int Parse_state_119 (void)	/* state 119 */
{ int n;
      n = 3; _doggy_symbol = OpSet_value;
      { ParseValue me;
        List_doggy_Applied_formal  ops = POP_PARSEVALUE (Pointer, List_doggy_Applied_formal);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Applied_operation");
        me->sub.PointerValue = Create_doggy_OpSet(src_info, ops);
      }
  return n-1;
}


static __inline__ int Parse_state_120 (void)	/* state 120 */
{ int n;
      n = 1; _doggy_symbol = Applied_operation_value;
      { ParseValue me;
        SrcInfo src_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);
        me = PushParseValue("doggy_Applied_operation");
        me->sub.PointerValue = Create_doggy_AnyOp(src_info);
      }
  return n-1;
}


static __inline__ int Parse_state_121 (void)	/* state 121 */
{ int n;
      n = 1; _doggy_symbol = Applied_operation_value;
  return n-1;
}


static __inline__ int Parse_state_122 (void)	/* state 122 */
{ int n;
      n = 1; _doggy_symbol = Applied_operation_value;
      { ParseValue me;
        doggy_Applied_formal  op = POP_PARSEVALUE (Pointer, doggy_Applied_formal);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Applied_operation");
        me->sub.PointerValue = Create_doggy_AppliedOp(src_info, op);
      }
  return n-1;
}

static int Parse_state_123 (SymbolSet followers);	/* state 123 */
static int Parse_state_124 (SymbolSet followers);	/* state 124 */
static int Parse_state_125 (SymbolSet followers);	/* state 125 */
static int Parse_state_126 (SymbolSet followers);	/* state 126 */
static int Parse_state_127 (SymbolSet followers);	/* state 127 */

static __inline__ int Parse_state_128 (void)	/* state 128 */
{ int n;
      n = 2; _doggy_symbol = IdParPattern_value;
      { ParseValue me;
        doggy_Pattern  _id_0 = POP_PARSEVALUE (Pointer, doggy_Pattern);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = IdParPattern(make_post_src_info(SCAN_POSITION, SCAN_END_POSITION), id, _id_0);
      }
  return n-1;
}


static __inline__ int Parse_state_129 (void)	/* state 129 */
{ int n;
      n = 1; _doggy_symbol = BasicPattern_value;
      { ParseValue me;
        Int  cnst = POP_PARSEVALUE (Int, Int);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_ConstPattern(src_info, cnst);
      }
  return n-1;
}


static __inline__ int Parse_state_130 (void)	/* state 130 */
{ int n;
      n = 1; _doggy_symbol = BasicPattern_value;
      { ParseValue me;
        SrcInfo src_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_NullPattern(src_info);
      }
  return n-1;
}

static int Parse_state_131 (SymbolSet followers);	/* state 131 */
static int Parse_state_132 (SymbolSet followers);	/* state 132 */

static __inline__ int Parse_state_133 (void)	/* state 133 */
{ int n;
      n = 1; _doggy_symbol = Constant_value;
      { ParseValue me;
        Int  i = POP_PARSEVALUE (Int, Int);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Constant");
        me->sub.PointerValue = Create_doggy_IntConst(src_info, i);
      }
  return n-1;
}


static __inline__ int Parse_state_134 (void)	/* state 134 */
{ int n;
      n = 1; _doggy_symbol = Constant_value;
      { ParseValue me;
        Bool  b = POP_PARSEVALUE (Bool, Bool);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Constant");
        me->sub.PointerValue = Create_doggy_BoolConst(src_info, b);
      }
  return n-1;
}


static __inline__ int Parse_state_135 (void)	/* state 135 */
{ int n;
      n = 1; _doggy_symbol = Constant_value;
      { ParseValue me;
        String  s = POP_PARSEVALUE (String, String);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Constant");
        me->sub.PointerValue = Create_doggy_StringConst(src_info, s);
      }
  return n-1;
}


static __inline__ int Parse_state_136 (void)	/* state 136 */
{ int n;
      n = 1; _doggy_symbol = Constant_value;
      { ParseValue me;
        SrcInfo src_info = make_post_src_info(SCAN_POSITION, SCAN_END_POSITION);
        me = PushParseValue("doggy_Constant");
        me->sub.PointerValue = Create_doggy_NullConst(src_info);
      }
  return n-1;
}


static __inline__ int Parse_state_137 (void)	/* state 137 */
{ int n;
      n = 1; _doggy_symbol = MonOp_value;
      PUSH_PARSEVALUE(Int,doggy_NotOp,doggy_MonOp);
  return n-1;
}


static __inline__ int Parse_state_138 (void)	/* state 138 */
{ int n;
      n = 1; _doggy_symbol = MonOp_value;
      PUSH_PARSEVALUE(Int,doggy_NegOp,doggy_MonOp);
  return n-1;
}


static __inline__ int Parse_state_139 (void)	/* state 139 */
{ int n;
      n = 1; _doggy_symbol = MonOp_value;
      PUSH_PARSEVALUE(Int,doggy_AddrOp,doggy_MonOp);
  return n-1;
}


static __inline__ int Parse_state_140 (void)	/* state 140 */
{ int n;
      n = 1; _doggy_symbol = MonOp_value;
      PUSH_PARSEVALUE(Int,doggy_DerefOp,doggy_MonOp);
  return n-1;
}


static __inline__ int Parse_state_141 (void)	/* state 141 */
{ int n;
      n = 1; _doggy_symbol = MonOp_value;
      PUSH_PARSEVALUE(Int,doggy_PlusOp,doggy_MonOp);
  return n-1;
}


static __inline__ int Parse_state_142 (void)	/* state 142 */
{ int n;
      n = 1; _doggy_symbol = MonOp_value;
      PUSH_PARSEVALUE(Int,doggy_MinOp,doggy_MonOp);
  return n-1;
}

static int Parse_state_143 (SymbolSet followers);	/* state 143 */
static int Parse_state_144 (SymbolSet followers);	/* state 144 */
static int Parse_state_145 (SymbolSet followers);	/* state 145 */

static __inline__ int Parse_state_146 (void)	/* state 146 */
{ int n;
      n = 1; _doggy_symbol = SimpleExpr_value;
      { ParseValue me;
        doggy_Constant  cnst = POP_PARSEVALUE (Pointer, doggy_Constant);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = Create_doggy_ConstExpr(src_info, cnst);
      }
  return n-1;
}

static int Parse_state_147 (SymbolSet followers);	/* state 147 */
static int Parse_state_148 (SymbolSet followers);	/* state 148 */

static __inline__ int Parse_state_149 (void)	/* state 149 */
{ int n;
      n = 2; _doggy_symbol = SimpleExpr_value;
      { ParseValue me;
        doggy_Expr  arg = POP_PARSEVALUE (Pointer, doggy_Expr);
        doggy_MonOp  op = POP_PARSEVALUE (Int, doggy_MonOp);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = Create_doggy_MonExpr(src_info, op, arg);
      }
  return n-1;
}

static int Parse_state_150 (SymbolSet followers);	/* state 150 */

static __inline__ int Parse_state_151 (void)	/* state 151 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_CandOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_152 (void)	/* state 152 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_CorOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_153 (void)	/* state 153 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_XorOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_154 (void)	/* state 154 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_EqOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_155 (void)	/* state 155 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_NeqOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_156 (void)	/* state 156 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_LEOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_157 (void)	/* state 157 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_GEOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_158 (void)	/* state 158 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_LTOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_159 (void)	/* state 159 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_GTOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_160 (void)	/* state 160 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_SLOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_161 (void)	/* state 161 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_SROp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_162 (void)	/* state 162 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_DivOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_163 (void)	/* state 163 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_ModOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_164 (void)	/* state 164 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_MulOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_165 (void)	/* state 165 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_AndOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_166 (void)	/* state 166 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_AddOp,doggy_Operator);
  return n-1;
}


static __inline__ int Parse_state_167 (void)	/* state 167 */
{ int n;
      n = 1; _doggy_symbol = Operator_value;
      PUSH_PARSEVALUE(Int,doggy_SubOp,doggy_Operator);
  return n-1;
}

static int Parse_state_168 (SymbolSet followers);	/* state 168 */

static __inline__ int Parse_state_169 (void)	/* state 169 */
{ int n;
      n = 2; _doggy_symbol = IdOp_value;
  return n-1;
}


static __inline__ int Parse_state_170 (void)	/* state 170 */
{ int n;
      n = 1; _doggy_symbol = cons_value;
  return n-1;
}

static int Parse_state_171 (SymbolSet followers);	/* state 171 */
static int Parse_state_172 (SymbolSet followers);	/* state 172 */

static __inline__ int Parse_state_173 (void)	/* state 173 */
{ int n;
      n = 3; _doggy_symbol = ALT_SimpleExpr_SEP_Operator_value;
      { /* alt action */
        List_doggy_Operator  ops_l = POP_PARSEVALUE (Pointer, List_doggy_Operator);
        List_doggy_Expr  args_l = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        doggy_Operator  ops = POP_PARSEVALUE (Int, doggy_Operator);
        doggy_Expr  args = POP_PARSEVALUE (Pointer, doggy_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Expr(args,args_l),List_doggy_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Operator(ops,ops_l),List_doggy_Operator);
      }
  return n-1;
}

static int Parse_state_174 (SymbolSet followers);	/* state 174 */

static __inline__ int Parse_state_175 (void)	/* state 175 */
{ int n;
      n = 1; _doggy_symbol = Expr_value;
      { ParseValue me;
        List_doggy_Operator  ops = POP_PARSEVALUE (Pointer, List_doggy_Operator);
        List_doggy_Expr  args = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = Create_doggy_BinExpr(src_info, args, ops);
      }
  return n-1;
}


static __inline__ int Parse_state_176 (void)	/* state 176 */
{ int n;
      n = 1; _doggy_symbol = Expr_value;
  return n-1;
}


static __inline__ int Parse_state_177 (void)	/* state 177 */
{ int n;
      n = 1; _doggy_symbol = Expr_value;
  return n-1;
}


static __inline__ int Parse_state_178 (void)	/* state 178 */
{ int n;
      n = 3; _doggy_symbol = IdOpExpr_value;
      { ParseValue me;
        doggy_Expr  rhs = POP_PARSEVALUE (Pointer, doggy_Expr);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        doggy_Expr  lhs = POP_PARSEVALUE (Pointer, doggy_Expr);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = IdOpExpr(make_post_src_info(SCAN_POSITION, SCAN_END_POSITION), lhs, id, rhs);
      }
  return n-1;
}

static int Parse_state_179 (SymbolSet followers);	/* state 179 */

static __inline__ int Parse_state_180 (void)	/* state 180 */
{ int n;
      n = 3; _doggy_symbol = ConsExpr_value;
      { ParseValue me;
        doggy_Expr  rhs = POP_PARSEVALUE (Pointer, doggy_Expr);
        doggy_Expr  lhs = POP_PARSEVALUE (Pointer, doggy_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = Create_doggy_ConsExpr(src_info, lhs, rhs);
      }
  return n-1;
}

static int Parse_state_181 (void);	/* state 181 */

static __inline__ int Parse_state_182 (void)	/* state 182 */
{ int n;
      n = 3; _doggy_symbol = SimpleExpr_value;
      { ParseValue me;
        doggy_Expr  expr = POP_PARSEVALUE (Pointer, doggy_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = Create_doggy_ParExpr(src_info, expr);
      }
  return n-1;
}


static __inline__ int Parse_state_183 (void)	/* state 183 */
{ int n;
      n = 1; _doggy_symbol = Condition_value;
  return n-1;
}

static int Parse_state_184 (SymbolSet followers);	/* state 184 */
static int Parse_state_185 (SymbolSet followers);	/* state 185 */
static int Parse_state_186 (SymbolSet followers);	/* state 186 */
static int Parse_state_187 (SymbolSet followers);	/* state 187 */
static int Parse_state_188 (SymbolSet followers);	/* state 188 */
static int Parse_state_189 (SymbolSet followers);	/* state 189 */
static int Parse_state_190 (SymbolSet followers);	/* state 190 */

static __inline__ int Parse_state_191 (void)	/* state 191 */
{ int n;
      n = 5; _doggy_symbol = OPTMORE_ELSIFsym_Condition_THENsym_Expr_value;
      { /* optmore action */
        List_doggy_Expr  thens_l = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        List_doggy_Expr  _id_0_l = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        doggy_Expr  thens = POP_PARSEVALUE (Pointer, doggy_Expr);
        doggy_Expr  _id_0 = POP_PARSEVALUE (Pointer, doggy_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Expr(_id_0,_id_0_l),List_doggy_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Expr(thens,thens_l),List_doggy_Expr);
      }
  return n-1;
}

static int Parse_state_192 (SymbolSet followers);	/* state 192 */
static int Parse_state_193 (SymbolSet followers);	/* state 193 */
static int Parse_state_194 (void);	/* state 194 */

static __inline__ int Parse_state_195 (void)	/* state 195 */
{ int n;
      n = 8; _doggy_symbol = SimpleExpr_value;
      { ParseValue me;
        doggy_Expr  els = POP_PARSEVALUE (Pointer, doggy_Expr);
        List_doggy_Expr  thens = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        List_doggy_Expr  conds = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        doggy_Expr  thn = POP_PARSEVALUE (Pointer, doggy_Expr);
        doggy_Expr  _id_0 = POP_PARSEVALUE (Pointer, doggy_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = Create_doggy_IfExpr(src_info, _id_0, thn, conds, thens, els);
      }
  return n-1;
}

static int Parse_state_196 (SymbolSet followers);	/* state 196 */
static int Parse_state_197 (SymbolSet followers);	/* state 197 */

static __inline__ int Parse_state_198 (void)	/* state 198 */
{ int n;
      n = 3; _doggy_symbol = ALT_Expr_SEP_commasym_value;
      { /* alt action */
        List_doggy_Expr  e_l = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        doggy_Expr  e = POP_PARSEVALUE (Pointer, doggy_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Expr(e,e_l),List_doggy_Expr);
      }
  return n-1;
}


static __inline__ int Parse_state_199 (void)	/* state 199 */
{ int n;
      n = 1; _doggy_symbol = Exprs_value;
  return n-1;
}


static __inline__ int Parse_state_200 (void)	/* state 200 */
{ int n;
      n = 1; _doggy_symbol = OPT_Exprs_value;
      { /* opt action */
        List_doggy_Expr  e = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        PUSH_PARSEVALUE(Pointer,e,List_doggy_Expr);
      }
  return n-1;
}

static int Parse_state_201 (void);	/* state 201 */

static __inline__ int Parse_state_202 (void)	/* state 202 */
{ int n;
      n = 4; _doggy_symbol = SimpleExpr_value;
      { ParseValue me;
        List_doggy_Expr  e = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = Create_doggy_Operation(src_info, id, e);
      }
  return n-1;
}


static __inline__ int Parse_state_203 (void)	/* state 203 */
{ int n;
      n = 2; _doggy_symbol = OPT_equalssym_SimpleExpr_value;
      { /* opt action */
        doggy_Expr  expr = POP_PARSEVALUE (Pointer, doggy_Expr);
        PUSH_PARSEVALUE(Pointer,expr,doggy_Expr);
      }
  return n-1;
}


static __inline__ int Parse_state_204 (void)	/* state 204 */
{ int n;
      n = 2; _doggy_symbol = BasicPattern_value;
      { ParseValue me;
        doggy_Expr  expr = POP_PARSEVALUE (Pointer, doggy_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_DontCarePattern(src_info, expr);
      }
  return n-1;
}

static int Parse_state_205 (SymbolSet followers);	/* state 205 */

static __inline__ int Parse_state_206 (void)	/* state 206 */
{ int n;
      n = 1; _doggy_symbol = IdentPattern_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_IdentPattern(src_info, id);
      }
  return n-1;
}

static int Parse_state_207 (SymbolSet followers);	/* state 207 */
static int Parse_state_208 (SymbolSet followers);	/* state 208 */

static __inline__ int Parse_state_209 (void)	/* state 209 */
{ int n;
      n = 3; _doggy_symbol = ALT_IdentPattern_SEP_commasym_value;
      { /* alt action */
        List_doggy_Pattern  ids_l = POP_PARSEVALUE (Pointer, List_doggy_Pattern);
        doggy_Pattern  ids = POP_PARSEVALUE (Pointer, doggy_Pattern);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Pattern(ids,ids_l),List_doggy_Pattern);
      }
  return n-1;
}


static __inline__ int Parse_state_210 (void)	/* state 210 */
{ int n;
      n = 1; _doggy_symbol = IdentPatterns_value;
  return n-1;
}

static int Parse_state_211 (SymbolSet followers);	/* state 211 */
static int Parse_state_212 (SymbolSet followers);	/* state 212 */
static int Parse_state_213 (SymbolSet followers);	/* state 213 */
static int Parse_state_214 (SymbolSet followers);	/* state 214 */
static int Parse_state_215 (SymbolSet followers);	/* state 215 */

static __inline__ int Parse_state_216 (void)	/* state 216 */
{ int n;
      n = 1; _doggy_symbol = SimplePattern_value;
  return n-1;
}


static __inline__ int Parse_state_217 (void)	/* state 217 */
{ int n;
      n = 1; _doggy_symbol = SimplePattern_value;
  return n-1;
}


static __inline__ int Parse_state_218 (void)	/* state 218 */
{ int n;
      n = 1; _doggy_symbol = SimplePattern_value;
  return n-1;
}


static __inline__ int Parse_state_219 (void)	/* state 219 */
{ int n;
      n = 1; _doggy_symbol = SimplePattern_value;
  return n-1;
}


static __inline__ int Parse_state_220 (void)	/* state 220 */
{ int n;
      n = 1; _doggy_symbol = SimplePattern_value;
  return n-1;
}


static __inline__ int Parse_state_221 (void)	/* state 221 */
{ int n;
      n = 2; _doggy_symbol = OPT_IdOp_SimplePattern_value;
      { /* opt action */
        doggy_Pattern  rhs = POP_PARSEVALUE (Pointer, doggy_Pattern);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,id,Ident);
        PUSH_PARSEVALUE(Pointer,rhs,doggy_Pattern);
      }
  return n-1;
}


static __inline__ int Parse_state_222 (void)	/* state 222 */
{ int n;
      n = 2; _doggy_symbol = BinPattern_value;
      { ParseValue me;
        doggy_Pattern  rhs = POP_PARSEVALUE (Pointer, doggy_Pattern);
        Ident  op = POP_PARSEVALUE (Ident, Ident);
        doggy_Pattern  lhs = POP_PARSEVALUE (Pointer, doggy_Pattern);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = BinPattern(make_post_src_info(SCAN_POSITION, SCAN_END_POSITION), lhs, op, rhs);
      }
  return n-1;
}


static __inline__ int Parse_state_223 (void)	/* state 223 */
{ int n;
      n = 5; _doggy_symbol = DefPattern_value;
      { ParseValue me;
        doggy_Pattern  arg = POP_PARSEVALUE (Pointer, doggy_Pattern);
        List_doggy_Pattern  ids = POP_PARSEVALUE (Pointer, List_doggy_Pattern);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_DefPattern(src_info, ids, arg);
      }
  return n-1;
}

static int Parse_state_224 (SymbolSet followers);	/* state 224 */
static int Parse_state_225 (SymbolSet followers);	/* state 225 */

static __inline__ int Parse_state_226 (void)	/* state 226 */
{ int n;
      n = 1; _doggy_symbol = UnTypedPattern_value;
  return n-1;
}


static __inline__ int Parse_state_227 (void)	/* state 227 */
{ int n;
      n = 3; _doggy_symbol = ConsPattern_value;
      { ParseValue me;
        doggy_Pattern  rhs = POP_PARSEVALUE (Pointer, doggy_Pattern);
        doggy_Pattern  lhs = POP_PARSEVALUE (Pointer, doggy_Pattern);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_ConsPattern(src_info, lhs, rhs);
      }
  return n-1;
}

static int Parse_state_228 (SymbolSet followers);	/* state 228 */

static __inline__ int Parse_state_229 (void)	/* state 229 */
{ int n;
      n = 2; _doggy_symbol = Pattern_value;
      { ParseValue me;
        doggy_Pattern  pat = POP_PARSEVALUE (Pointer, doggy_Pattern);
        doggy_Type  btype = POP_PARSEVALUE (Pointer, doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_TypedPattern(src_info, btype, pat);
      }
  return n-1;
}


static __inline__ int Parse_state_230 (void)	/* state 230 */
{ int n;
      n = 1; _doggy_symbol = Pattern_value;
  return n-1;
}

static int Parse_state_231 (SymbolSet followers);	/* state 231 */
static int Parse_state_232 (SymbolSet followers);	/* state 232 */

static __inline__ int Parse_state_233 (void)	/* state 233 */
{ int n;
      n = 3; _doggy_symbol = ALT_Pattern_SEP_commasym_value;
      { /* alt action */
        List_doggy_Pattern  args_l = POP_PARSEVALUE (Pointer, List_doggy_Pattern);
        doggy_Pattern  args = POP_PARSEVALUE (Pointer, doggy_Pattern);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Pattern(args,args_l),List_doggy_Pattern);
      }
  return n-1;
}


static __inline__ int Parse_state_234 (void)	/* state 234 */
{ int n;
      n = 1; _doggy_symbol = Patterns_value;
  return n-1;
}


static __inline__ int Parse_state_235 (void)	/* state 235 */
{ int n;
      n = 1; _doggy_symbol = OPT_Patterns_value;
      { /* opt action */
        List_doggy_Pattern  args = POP_PARSEVALUE (Pointer, List_doggy_Pattern);
        PUSH_PARSEVALUE(Pointer,args,List_doggy_Pattern);
      }
  return n-1;
}

static int Parse_state_236 (void);	/* state 236 */

static __inline__ int Parse_state_237 (void)	/* state 237 */
{ int n;
      n = 4; _doggy_symbol = BasicPattern_value;
      { ParseValue me;
        List_doggy_Pattern  args = POP_PARSEVALUE (Pointer, List_doggy_Pattern);
        doggy_Applied_operation  op = POP_PARSEVALUE (Pointer, doggy_Applied_operation);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_OpPattern(src_info, op, args);
      }
  return n-1;
}

static int Parse_state_238 (SymbolSet followers);	/* state 238 */
static int Parse_state_239 (void);	/* state 239 */

static __inline__ int Parse_state_240 (void)	/* state 240 */
{ int n;
      n = 4; _doggy_symbol = ParPattern_value;
      { ParseValue me;
        doggy_Pattern  _id_0 = POP_PARSEVALUE (Pointer, doggy_Pattern);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = ParPattern(make_post_src_info(SCAN_POSITION, SCAN_END_POSITION), _id_0);
      }
  return n-1;
}


static __inline__ int Parse_state_241 (void)	/* state 241 */
{ int n;
      n = 3; _doggy_symbol = SingleDefPattern_value;
      { ParseValue me;
        doggy_Pattern  arg = POP_PARSEVALUE (Pointer, doggy_Pattern);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = SingleDefPattern(make_post_src_info(SCAN_POSITION, SCAN_END_POSITION), id, arg);
      }
  return n-1;
}


static __inline__ int Parse_state_242 (void)	/* state 242 */
{ int n;
  _doggy_symbol = _doggy_token;
  do {
    REPORT(242);
    switch (_doggy_symbol) {
    case openparsym_value:
      n = 1; _doggy_symbol = Applied_operation_value;
      break;
    default:
    /* default item:SetArg  ->  equalssym OpSet .   followers: commasym closeparsym  */
      n = 2; _doggy_symbol = SetArg_value;
      { ParseValue me;
        doggy_Applied_operation  set = POP_PARSEVALUE (Pointer, doggy_Applied_operation);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_ArgPat");
        me->sub.PointerValue = Create_doggy_SetArg(src_info, set);
      }
      break;
    }
  } while (n==0);
  return n-1;
}


static __inline__ int Parse_state_243 (void)	/* state 243 */
{ int n;
      n = 2; _doggy_symbol = OPT_equalssym_UnTypedPattern_value;
      { /* opt action */
        doggy_Pattern  pat = POP_PARSEVALUE (Pointer, doggy_Pattern);
        PUSH_PARSEVALUE(Pointer,pat,doggy_Pattern);
      }
  return n-1;
}


static __inline__ int Parse_state_244 (void)	/* state 244 */
{ int n;
      n = 1; _doggy_symbol = PatArg1_value;
      { ParseValue me;
        doggy_Pattern  pat = POP_PARSEVALUE (Pointer, doggy_Pattern);
        me = PushParseValue("doggy_ArgPat");
        me->sub.PointerValue = PatArg1(make_post_src_info(SCAN_POSITION, SCAN_END_POSITION), pat);
      }
  return n-1;
}


static __inline__ int Parse_state_245 (void)	/* state 245 */
{ int n;
      n = 1; _doggy_symbol = ParArg_value;
      { ParseValue me;
        doggy_Pattern  _id_0 = POP_PARSEVALUE (Pointer, doggy_Pattern);
        me = PushParseValue("doggy_ArgPat");
        me->sub.PointerValue = ParArg(make_post_src_info(SCAN_POSITION, SCAN_END_POSITION), _id_0);
      }
  return n-1;
}


static __inline__ int Parse_state_246 (void)	/* state 246 */
{ int n;
      n = 1; _doggy_symbol = ArgPat2_value;
  return n-1;
}


static __inline__ int Parse_state_247 (void)	/* state 247 */
{ int n;
      n = 1; _doggy_symbol = ArgPat2_value;
  return n-1;
}


static __inline__ int Parse_state_248 (void)	/* state 248 */
{ int n;
      n = 1; _doggy_symbol = ArgPat2_value;
  return n-1;
}


static __inline__ int Parse_state_249 (void)	/* state 249 */
{ int n;
      n = 2; _doggy_symbol = Argument_value;
      { ParseValue me;
        doggy_ArgPat  pat = POP_PARSEVALUE (Pointer, doggy_ArgPat);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Argument");
        me->sub.PointerValue = Create_doggy_UnTypedArg(src_info, id, pat);
      }
  return n-1;
}

static int Parse_state_250 (SymbolSet followers);	/* state 250 */
static int Parse_state_251 (SymbolSet followers);	/* state 251 */

static __inline__ int Parse_state_252 (void)	/* state 252 */
{ int n;
      n = 3; _doggy_symbol = Argument_value;
      { ParseValue me;
        doggy_ArgPat  pat = POP_PARSEVALUE (Pointer, doggy_ArgPat);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        doggy_Type  type = POP_PARSEVALUE (Pointer, doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Argument");
        me->sub.PointerValue = Create_doggy_TypedArg(src_info, type, id, pat);
      }
  return n-1;
}

static int Parse_state_253 (SymbolSet followers);	/* state 253 */
static int Parse_state_254 (SymbolSet followers);	/* state 254 */

static __inline__ int Parse_state_255 (void)	/* state 255 */
{ int n;
      n = 3; _doggy_symbol = ALT_Argument_SEP_commasym_value;
      { /* alt action */
        List_doggy_Argument  _id_0_l = POP_PARSEVALUE (Pointer, List_doggy_Argument);
        doggy_Argument  _id_0 = POP_PARSEVALUE (Pointer, doggy_Argument);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Argument(_id_0,_id_0_l),List_doggy_Argument);
      }
  return n-1;
}


static __inline__ int Parse_state_256 (void)	/* state 256 */
{ int n;
      n = 1; _doggy_symbol = Arguments_value;
  return n-1;
}


static __inline__ int Parse_state_257 (void)	/* state 257 */
{ int n;
      n = 1; _doggy_symbol = OPT_Arguments_value;
      { /* opt action */
        List_doggy_Argument  _id_0 = POP_PARSEVALUE (Pointer, List_doggy_Argument);
        PUSH_PARSEVALUE(Pointer,_id_0,List_doggy_Argument);
      }
  return n-1;
}

static int Parse_state_258 (SymbolSet followers);	/* state 258 */
static int Parse_state_259 (SymbolSet followers);	/* state 259 */
static int Parse_state_260 (SymbolSet followers);	/* state 260 */
static int Parse_state_261 (SymbolSet followers);	/* state 261 */
static int Parse_state_262 (SymbolSet followers);	/* state 262 */
static int Parse_state_263 (SymbolSet followers);	/* state 263 */
static int Parse_state_264 (SymbolSet followers);	/* state 264 */

static __inline__ int Parse_state_265 (void)	/* state 265 */
{ int n;
      n = 1; _doggy_symbol = ExprSeq_value;
      { ParseValue me;
        doggy_Expr  expr = POP_PARSEVALUE (Pointer, doggy_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_ExprSeq");
        me->sub.PointerValue = Create_doggy_OneExpr(src_info, expr);
      }
  return n-1;
}

static int Parse_state_266 (SymbolSet followers);	/* state 266 */
static int Parse_state_267 (void);	/* state 267 */

static __inline__ int Parse_state_268 (void)	/* state 268 */
{ int n;
      n = 3; _doggy_symbol = ExprSeq_value;
      { ParseValue me;
        List_doggy_Expr  e = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_ExprSeq");
        me->sub.PointerValue = Create_doggy_MoreExprs(src_info, e);
      }
  return n-1;
}

static int Parse_state_269 (SymbolSet followers);	/* state 269 */
static int Parse_state_270 (SymbolSet followers);	/* state 270 */
static int Parse_state_271 (SymbolSet followers);	/* state 271 */
static int Parse_state_272 (SymbolSet followers);	/* state 272 */
static int Parse_state_273 (SymbolSet followers);	/* state 273 */

static __inline__ int Parse_state_274 (void)	/* state 274 */
{ int n;
      n = 4; _doggy_symbol = Definition_value;
      { ParseValue me;
        doggy_Expr  expr = POP_PARSEVALUE (Pointer, doggy_Expr);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        doggy_Type  type = POP_PARSEVALUE (Pointer, doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Definition");
        me->sub.PointerValue = Create_doggy_Definition(src_info, type, id, expr);
      }
  return n-1;
}

static int Parse_state_275 (SymbolSet followers);	/* state 275 */

static __inline__ int Parse_state_276 (void)	/* state 276 */
{ int n;
      n = 2; _doggy_symbol = OPTMORE_Definition_value;
      { /* optmore action */
        List_doggy_Definition  defs_l = POP_PARSEVALUE (Pointer, List_doggy_Definition);
        doggy_Definition  defs = POP_PARSEVALUE (Pointer, doggy_Definition);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Definition(defs,defs_l),List_doggy_Definition);
      }
  return n-1;
}


static __inline__ int Parse_state_277 (void)	/* state 277 */
{ int n;
      n = 2; _doggy_symbol = Wherepart_value;
      { ParseValue me;
        List_doggy_Definition  defs = POP_PARSEVALUE (Pointer, List_doggy_Definition);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Wherepart");
        me->sub.PointerValue = Create_doggy_Wherepart(src_info, defs);
      }
  return n-1;
}


static __inline__ int Parse_state_278 (void)	/* state 278 */
{ int n;
      n = 1; _doggy_symbol = OPT_Wherepart_value;
      { /* opt action */
        doggy_Wherepart  where = POP_PARSEVALUE (Pointer, doggy_Wherepart);
        PUSH_PARSEVALUE(Pointer,where,doggy_Wherepart);
      }
  return n-1;
}


static __inline__ int Parse_state_279 (void)	/* state 279 */
{ int n;
      n = 4; _doggy_symbol = Guard_value;
      { ParseValue me;
        doggy_Wherepart  where = POP_PARSEVALUE (Pointer, doggy_Wherepart);
        doggy_ExprSeq  exprs = POP_PARSEVALUE (Pointer, doggy_ExprSeq);
        doggy_Expr  conds = POP_PARSEVALUE (Pointer, doggy_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Guard");
        me->sub.PointerValue = Create_doggy_ExprGuard(src_info, conds, exprs, where);
      }
  return n-1;
}

static int Parse_state_280 (SymbolSet followers);	/* state 280 */

static __inline__ int Parse_state_281 (void)	/* state 281 */
{ int n;
      n = 2; _doggy_symbol = MORE_Guard_value;
      { /* more action */
        List_doggy_Guard  guards_l = POP_PARSEVALUE (Pointer, List_doggy_Guard);
        doggy_Guard  guards = POP_PARSEVALUE (Pointer, doggy_Guard);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Guard(guards,guards_l),List_doggy_Guard);
      }
  return n-1;
}


static __inline__ int Parse_state_282 (void)	/* state 282 */
{ int n;
      n = 1; _doggy_symbol = Rhs_value;
      { ParseValue me;
        List_doggy_Guard  guards = POP_PARSEVALUE (Pointer, List_doggy_Guard);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Rhs");
        me->sub.PointerValue = Create_doggy_PlainRhs(src_info, guards);
      }
  return n-1;
}

static int Parse_state_283 (SymbolSet followers);	/* state 283 */
static int Parse_state_284 (SymbolSet followers);	/* state 284 */
static int Parse_state_285 (SymbolSet followers);	/* state 285 */

static __inline__ int Parse_state_286 (void)	/* state 286 */
{ int n;
      n = 4; _doggy_symbol = Rhs_value;
      { ParseValue me;
        doggy_Wherepart  where = POP_PARSEVALUE (Pointer, doggy_Wherepart);
        doggy_Rhs  rhs = POP_PARSEVALUE (Pointer, doggy_Rhs);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Rhs");
        me->sub.PointerValue = Create_doggy_BlockRhs(src_info, rhs, where);
      }
  return n-1;
}

static int Parse_state_287 (SymbolSet followers);	/* state 287 */
static int Parse_state_288 (SymbolSet followers);	/* state 288 */

static __inline__ int Parse_state_289 (void)	/* state 289 */
{ int n;
      n = 6; _doggy_symbol = Guard_value;
      { ParseValue me;
        doggy_Wherepart  where = POP_PARSEVALUE (Pointer, doggy_Wherepart);
        doggy_Rhs  rhs = POP_PARSEVALUE (Pointer, doggy_Rhs);
        doggy_Expr  _id_0 = POP_PARSEVALUE (Pointer, doggy_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Guard");
        me->sub.PointerValue = Create_doggy_RhsGuard(src_info, _id_0, rhs, where);
      }
  return n-1;
}


static __inline__ int Parse_state_290 (void)	/* state 290 */
{ int n;
      n = 4; _doggy_symbol = FuncRule_value;
      { ParseValue me;
        doggy_Rhs  rhs = POP_PARSEVALUE (Pointer, doggy_Rhs);
        List_doggy_Argument  _id_0 = POP_PARSEVALUE (Pointer, List_doggy_Argument);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_FuncRule");
        me->sub.PointerValue = Create_doggy_FuncRule(src_info, _id_0, rhs);
      }
  return n-1;
}

static int Parse_state_291 (SymbolSet followers);	/* state 291 */
static int Parse_state_292 (SymbolSet followers);	/* state 292 */

static __inline__ int Parse_state_293 (void)	/* state 293 */
{ int n;
      n = 3; _doggy_symbol = ALT_FuncRule_SEP_commasym_value;
      { /* alt action */
        List_doggy_FuncRule  _id_0_l = POP_PARSEVALUE (Pointer, List_doggy_FuncRule);
        doggy_FuncRule  _id_0 = POP_PARSEVALUE (Pointer, doggy_FuncRule);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_FuncRule(_id_0,_id_0_l),List_doggy_FuncRule);
      }
  return n-1;
}


static __inline__ int Parse_state_294 (void)	/* state 294 */
{ int n;
      n = 1; _doggy_symbol = FuncRules_value;
  return n-1;
}

static int Parse_state_295 (void);	/* state 295 */

static __inline__ int Parse_state_296 (void)	/* state 296 */
{ int n;
      n = 5; _doggy_symbol = Func_value;
      { ParseValue me;
        List_doggy_FuncRule  _id_0 = POP_PARSEVALUE (Pointer, List_doggy_FuncRule);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        doggy_Type  type = POP_PARSEVALUE (Pointer, doggy_Type);
        Bool  ext = POP_PARSEVALUE (Bool, Bool);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Func");
        me->sub.PointerValue = Create_doggy_Func(src_info, ext, type, id, _id_0);
      }
  return n-1;
}

static int Parse_state_297 (SymbolSet followers);	/* state 297 */

static __inline__ int Parse_state_298 (void)	/* state 298 */
{ int n;
      n = 2; _doggy_symbol = OPTMORE_Func_value;
      { /* optmore action */
        List_doggy_Func  funcs_l = POP_PARSEVALUE (Pointer, List_doggy_Func);
        doggy_Func  funcs = POP_PARSEVALUE (Pointer, doggy_Func);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Func(funcs,funcs_l),List_doggy_Func);
      }
  return n-1;
}


static __inline__ int Parse_state_299 (void)	/* state 299 */
{ int n;
      n = 2; _doggy_symbol = Funcs_value;
  return n-1;
}

static int Parse_state_300 (SymbolSet followers);	/* state 300 */
static int Parse_state_301 (SymbolSet followers);	/* state 301 */

static __inline__ int Parse_state_302 (void)	/* state 302 */
{ int n;
      n = 2; _doggy_symbol = OPT_colonsym_Identsym_value;
      { /* opt action */
        Ident  rules_id = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,rules_id,Ident);
      }
  return n-1;
}

static int Parse_state_303 (SymbolSet followers);	/* state 303 */
static int Parse_state_304 (SymbolSet followers);	/* state 304 */
static int Parse_state_305 (SymbolSet followers);	/* state 305 */

static __inline__ int Parse_state_306 (void)	/* state 306 */
{ int n;
      n = 3; _doggy_symbol = Lhs_value;
      { ParseValue me;
        doggy_Pattern  pat = POP_PARSEVALUE (Pointer, doggy_Pattern);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Lhs");
        me->sub.PointerValue = Create_doggy_LabeledLhs(src_info, id, pat);
      }
  return n-1;
}


static __inline__ int Parse_state_307 (void)	/* state 307 */
{ int n;
      n = 1; _doggy_symbol = Lhs_value;
      { ParseValue me;
        doggy_Pattern  pat = POP_PARSEVALUE (Pointer, doggy_Pattern);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Lhs");
        me->sub.PointerValue = Create_doggy_UnLabeledLhs(src_info, pat);
      }
  return n-1;
}

static int Parse_state_308 (SymbolSet followers);	/* state 308 */
static int Parse_state_309 (void);	/* state 309 */

static __inline__ int Parse_state_310 (void)	/* state 310 */
{ int n;
      n = 3; _doggy_symbol = Rule_value;
      { ParseValue me;
        doggy_Rhs  rhs = POP_PARSEVALUE (Pointer, doggy_Rhs);
        doggy_Lhs  lhs = POP_PARSEVALUE (Pointer, doggy_Lhs);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Rule");
        me->sub.PointerValue = Create_doggy_Rule(src_info, lhs, rhs);
      }
  return n-1;
}

static int Parse_state_311 (SymbolSet followers);	/* state 311 */

static __inline__ int Parse_state_312 (void)	/* state 312 */
{ int n;
      n = 2; _doggy_symbol = OPTMORE_Rule_value;
      { /* optmore action */
        List_doggy_Rule  rules_l = POP_PARSEVALUE (Pointer, List_doggy_Rule);
        doggy_Rule  rules = POP_PARSEVALUE (Pointer, doggy_Rule);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Rule(rules,rules_l),List_doggy_Rule);
      }
  return n-1;
}


static __inline__ int Parse_state_313 (void)	/* state 313 */
{ int n;
      n = 3; _doggy_symbol = Rules_value;
  return n-1;
}


static __inline__ int Parse_state_314 (void)	/* state 314 */
{ int n;
      n = 1; _doggy_symbol = Section_value;
      { ParseValue me;
        List_doggy_Func  funcs = POP_PARSEVALUE (Pointer, List_doggy_Func);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Section");
        me->sub.PointerValue = Create_doggy_FuncSection(src_info, funcs);
      }
  return n-1;
}


static __inline__ int Parse_state_315 (void)	/* state 315 */
{ int n;
      n = 1; _doggy_symbol = Section_value;
      { ParseValue me;
        List_doggy_Rule  rules = POP_PARSEVALUE (Pointer, List_doggy_Rule);
        Ident  rules_id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Section");
        me->sub.PointerValue = Create_doggy_RuleSection(src_info, rules_id, rules);
      }
  return n-1;
}

static int Parse_state_316 (SymbolSet followers);	/* state 316 */

static __inline__ int Parse_state_317 (void)	/* state 317 */
{ int n;
      n = 2; _doggy_symbol = OPTMORE_Section_value;
      { /* optmore action */
        List_doggy_Section  sections_l = POP_PARSEVALUE (Pointer, List_doggy_Section);
        doggy_Section  sections = POP_PARSEVALUE (Pointer, doggy_Section);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Section(sections,sections_l),List_doggy_Section);
      }
  return n-1;
}


static __inline__ int Parse_state_318 (void)	/* state 318 */
{ int n;
      n = 5; _doggy_symbol = doggy_value;
      { ParseValue me;
        List_doggy_Section  sections = POP_PARSEVALUE (Pointer, List_doggy_Section);
        List_doggy_FunctionDef  funcs = POP_PARSEVALUE (Pointer, List_doggy_FunctionDef);
        doggy_machine_description  target = POP_PARSEVALUE (Pointer, doggy_machine_description);
        doggy_machine_description  source = POP_PARSEVALUE (Pointer, doggy_machine_description);
        List_doggy_Typedef  types = POP_PARSEVALUE (Pointer, List_doggy_Typedef);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_doggy");
        me->sub.PointerValue = Create_doggy_doggy(src_info, types, source, target, funcs, sections);
        Decorate_doggy(me->sub.PointerValue);
      }
  return n-1;
}


/* directors of state 0
   TYPESsym MACHINEsym 
 */
doggy_doggy Parse_state_doggy_doggy (void)	/* state 0 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x42, 0x0 };
  Int _followers[2];
  Int followers[2] = { 0x0, 0x10000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(0);
    switch (_doggy_symbol) {
    case doggy_value:
      n = 1; break; /* accept doggy  ->  . OPT_Typedefs machine_description OPT_machine_description OPT_externals OPTMORE_Section     followers: doggy_EOF  */
    case TYPESsym_value:
      {
        static Int my_followers[] = { 0x40, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case Typedefs_value:
      {
        static Int my_followers[] = { 0x40, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_26();
        break;
      }
    case OPT_Typedefs_value:
      {
        n = Parse_state_27(followers);
        break;
      }
    default:
    /* default item:doggy  ->  . OPT_Typedefs machine_description OPT_machine_description OPT_externals OPTMORE_Section        followers: doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Typedef);
      _doggy_symbol = OPT_Typedefs_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("doggy_doggy")->sub.PointerValue;
}

/* directors of state 1
   Identsym 
 */
static int Parse_state_1 (SymbolSet followers)	/* state 1 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(1);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_2(_followers);
        break;
      }
    case Typedef_value:
      {
        n = Parse_state_23(followers);
        break;
      }
    case OPTMORE_Typedef_value:
      {
        n = Parse_state_25();
        break;
      }
    default:
    /* default item:Typedefs  ->  TYPESsym . OPTMORE_Typedef        followers: MACHINEsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Typedef);
      _doggy_symbol = OPTMORE_Typedef_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 2
   Stringsym ATTRIBUTESsym 
 */
static int Parse_state_2 (SymbolSet followers)	/* state 2 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x800001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(2);
    switch (_doggy_symbol) {
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x0, 0x800000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(_followers);
        break;
      }
    case OPT_Stringsym_Stringsym_Stringsym_value:
      {
        n = Parse_state_6(followers);
        break;
      }
    default:
    /* default item:Typedef  ->  Identsym . OPT_Stringsym_Stringsym_Stringsym OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym       followers: Identsym MACHINEsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(String,0,String);
      PUSH_PARSEVALUE(String,0,String);
      PUSH_PARSEVALUE(String,0,String);
      _doggy_symbol = OPT_Stringsym_Stringsym_Stringsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 3
   Stringsym 
 */
static int Parse_state_3 (SymbolSet followers)	/* state 3 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4(followers);
      }
  return n-1;
}

/* directors of state 4
   Stringsym 
 */
static int Parse_state_4 (SymbolSet followers)	/* state 4 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_5();
      }
  return n-1;
}

/* directors of state 6
   ATTRIBUTESsym 
 */
static int Parse_state_6 (SymbolSet followers)	/* state 6 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x800000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(6);
    switch (_doggy_symbol) {
    case ATTRIBUTESsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(followers);
        break;
      }
    case OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_value:
      {
        n = Parse_state_22();
        break;
      }
    default:
    /* default item:Typedef  ->  Identsym OPT_Stringsym_Stringsym_Stringsym . OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym       followers: Identsym MACHINEsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,doggy_Attributes);
      _doggy_symbol = OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 7
   openchainsym 
 */
static int Parse_state_7 (SymbolSet followers)	/* state 7 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_8(followers);
      }
  return n-1;
}

/* directors of state 8
   Intsym OPRsym Identsym closechainsym 
 */
static int Parse_state_8 (SymbolSet followers)	/* state 8 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x20c04, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(8);
    switch (_doggy_symbol) {
    case closechainsym_value:
      n = 0; _doggy_symbol = OPT_Attrs_OPT_commasym_Attributes_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_doggy_Attribute);
        PUSH_PARSEVALUE(Pointer,NULL,doggy_Attributes);
      }
      break;
    case Identsym_value:
      {
        static Int my_followers[] = { 0x20c04, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_9();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x20c04, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_10();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x20c04, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_11();
        break;
      }
    case Attribute_value:
      {
        static Int my_followers[] = { 0x20000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_12(_followers);
        break;
      }
    case MORE_Attribute_value:
      {
        static Int my_followers[] = { 0x20000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_14();
        break;
      }
    case Attrs_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_15(_followers);
        break;
      }
    case OPT_Attrs_OPT_commasym_Attributes_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_17();
        break;
      }
    case Attributes_value:
      {
        n = Parse_state_20();
        break;
      }
    default:
    /* default item:OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym  ->  ATTRIBUTESsym openchainsym . Attributes closechainsym      followers: COMMUTATIVEsym Identsym SUPPORTSsym MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = 0x96a0838 */
      PUSH_PARSEVALUE(Pointer,0,doggy_Attributes);
      _doggy_symbol = Attributes_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 12
   Intsym OPRsym Identsym 
 */
static int Parse_state_12 (SymbolSet followers)	/* state 12 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xc04, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(12);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0xc04, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_9();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0xc04, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_10();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0xc04, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_11();
        break;
      }
    case Attribute_value:
      {
        n = Parse_state_12(followers);
        break;
      }
    case MORE_Attribute_value:
      {
        n = Parse_state_13();
        break;
      }
    default:
    /* default item:MORE_Attribute  ->  Attribute . followers: commasym closechainsym  */
      n = 1; _doggy_symbol = MORE_Attribute_value;
      { /* more action */
        doggy_Attribute  ids = POP_PARSEVALUE (Pointer, doggy_Attribute);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Attribute(ids,NULL),List_doggy_Attribute);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 15
   commasym 
 */
static int Parse_state_15 (SymbolSet followers)	/* state 15 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x2000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(15);
    switch (_doggy_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_16(followers);
        break;
      }
    case OPT_commasym_Attributes_value:
      {
        n = Parse_state_19();
        break;
      }
    default:
    /* default item:OPT_Attrs_OPT_commasym_Attributes  ->  Attrs . OPT_commasym_Attributes  followers: closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,doggy_Attributes);
      _doggy_symbol = OPT_commasym_Attributes_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 16
   Intsym OPRsym Identsym 
 */
static int Parse_state_16 (SymbolSet followers)	/* state 16 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xc04, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(16);
    switch (_doggy_symbol) {
    case closechainsym_value:
      n = 0; _doggy_symbol = OPT_Attrs_OPT_commasym_Attributes_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,List_doggy_Attribute);
        PUSH_PARSEVALUE(Pointer,NULL,doggy_Attributes);
      }
      break;
    case Identsym_value:
      {
        static Int my_followers[] = { 0xc04, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_9();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0xc04, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_10();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0xc04, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_11();
        break;
      }
    case Attribute_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_12(_followers);
        break;
      }
    case MORE_Attribute_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_14();
        break;
      }
    case Attrs_value:
      {
        n = Parse_state_15(followers);
        break;
      }
    case OPT_Attrs_OPT_commasym_Attributes_value:
      {
        n = Parse_state_17();
        break;
      }
    case Attributes_value:
      {
        n = Parse_state_18();
        break;
      }
    default:
    /* default item:OPT_commasym_Attributes  ->  commasym . Attributes      followers: closechainsym  */
/* nt = 0x96a0838 */
      PUSH_PARSEVALUE(Pointer,0,doggy_Attributes);
      _doggy_symbol = Attributes_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_20 (void)	/* state 20 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_21();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 23
   Identsym 
 */
static int Parse_state_23 (SymbolSet followers)	/* state 23 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(23);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_2(_followers);
        break;
      }
    case Typedef_value:
      {
        n = Parse_state_23(followers);
        break;
      }
    case OPTMORE_Typedef_value:
      {
        n = Parse_state_24();
        break;
      }
    default:
    /* default item:OPTMORE_Typedef  ->  Typedef . OPTMORE_Typedef  followers: MACHINEsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Typedef);
      _doggy_symbol = OPTMORE_Typedef_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 27
   MACHINEsym 
 */
static int Parse_state_27 (SymbolSet followers)	/* state 27 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x40, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(27);
    switch (_doggy_symbol) {
    case MACHINEsym_value:
      {
        static Int my_followers[] = { 0x5048, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_28(_followers);
        break;
      }
    case machine_description_value:
      {
        n = Parse_state_88(followers);
        break;
      }
    default:
    /* default item:doggy  ->  OPT_Typedefs . machine_description OPT_machine_description OPT_externals OPTMORE_Section     followers: doggy_EOF  */
/* nt = 0x969ca08 */
      InputError (SCAN_POSITION, TRUE, "machine_description expected");
      PUSH_PARSEVALUE(Pointer,0,doggy_machine_description);
      _doggy_symbol = machine_description_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 28
   DESCRIPTIONsym 
 */
static int Parse_state_28 (SymbolSet followers)	/* state 28 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_29(followers);
      }
  return n-1;
}

/* directors of state 29
   Identsym 
 */
static int Parse_state_29 (SymbolSet followers)	/* state 29 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_30(followers);
      }
  return n-1;
}

/* directors of state 30
   Identsym SUPPORTSsym 
 */
static int Parse_state_30 (SymbolSet followers)	/* state 30 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4, 0x1000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(30);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4, 0x1000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_31(_followers);
        break;
      }
    case Operation_def_value:
      {
        static Int my_followers[] = { 0x0, 0x1000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_79(_followers);
        break;
      }
    case OPTMORE_Operation_def_value:
      {
        n = Parse_state_81(followers);
        break;
      }
    default:
    /* default item:machine_description  ->  MACHINEsym DESCRIPTIONsym Identsym . OPTMORE_Operation_def OPT_SUPPORTSsym_OPTMORE_Applied_formal      followers: MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Operation_def);
      _doggy_symbol = OPTMORE_Operation_def_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 31
   openparsym 
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
   openchainsym openbrksym OPRsym Identsym closeparsym 
 */
static int Parse_state_32 (SymbolSet followers)	/* state 32 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010604, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(32);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100200, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x100200, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_36(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100200, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(_followers);
        break;
      }
    case Type_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_57(_followers);
        break;
      }
    case ALT_Type_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_60();
        break;
      }
    case Types_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_61();
        break;
      }
    case OPT_Types_value:
      {
        n = Parse_state_68(followers);
        break;
      }
    default:
    /* default item:Operation_def  ->  Identsym openparsym . OPT_Types closeparsym OPT_colonsym_Type Identsym OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym OPTMORE_Property      followers: Identsym SUPPORTSsym MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Type);
      _doggy_symbol = OPT_Types_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 34
   openparsym 
 */
static int Parse_state_34 (SymbolSet followers)	/* state 34 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x100, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(34);
    switch (_doggy_symbol) {
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(followers);
        break;
      }
    case ArgTypes_value:
      {
        n = Parse_state_66();
        break;
      }
    case OPT_ArgTypes_value:
      {
        n = Parse_state_67();
        break;
      }
    default:
    /* default item:BasicType  ->  OPRsym . OPT_ArgTypes    followers: closeparsym _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym verticalbarsym starsym commasym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Type);
      _doggy_symbol = OPT_ArgTypes_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 35
   openchainsym openbrksym OPRsym Identsym closeparsym 
 */
static int Parse_state_35 (SymbolSet followers)	/* state 35 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010604, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(35);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100200, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x100200, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_36(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100200, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(_followers);
        break;
      }
    case Type_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_57(_followers);
        break;
      }
    case ALT_Type_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_60();
        break;
      }
    case Types_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_61();
        break;
      }
    case OPT_Types_value:
      {
        n = Parse_state_64();
        break;
      }
    default:
    /* default item:ArgTypes  ->  openparsym . OPT_Types closeparsym        followers: semicolonsym closeparsym _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym verticalbarsym starsym commasym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Type);
      _doggy_symbol = OPT_Types_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 36
   verticalbarsym starsym 
 */
static int Parse_state_36 (SymbolSet followers)	/* state 36 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x100000, 0x4000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(36);
    switch (_doggy_symbol) {
    case starsym_value:
      {
        n = Parse_state_37();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case verticalbarsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_38(followers);
        break;
      }
    default:
    /* default item:ALT_BasicType_SEP_verticalbarsym  ->  BasicType .       followers: closeparsym Identsym commasym closechainsym  */
      n = 1; _doggy_symbol = ALT_BasicType_SEP_verticalbarsym_value;
      { /* alt action */
        doggy_Type  types = POP_PARSEVALUE (Pointer, doggy_Type);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Type(types,NULL),List_doggy_Type);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 38
   openbrksym OPRsym Identsym 
 */
static int Parse_state_38 (SymbolSet followers)	/* state 38 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1000404, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(38);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100000, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x100000, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        n = Parse_state_36(followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100000, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        n = Parse_state_54();
        break;
      }
    default:
    /* default item:ALT_BasicType_SEP_verticalbarsym  ->  BasicType verticalbarsym . ALT_BasicType_SEP_verticalbarsym       followers: closeparsym Identsym commasym closechainsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_BasicType_SEP_verticalbarsym expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Type);
      _doggy_symbol = ALT_BasicType_SEP_verticalbarsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 39
   Identsym minussym Intsym 
 */
static int Parse_state_39 (SymbolSet followers)	/* state 39 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x804, 0x20000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(39);
    switch (_doggy_symbol) {
    case Intsym_value:
      n = 0; _doggy_symbol = OPT_minussym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case minussym_value:
      {
        static Int my_followers[] = { 0x800, 0x200000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_40();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_minussym_value:
      {
        static Int my_followers[] = { 0x0, 0x200000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_41(_followers);
        break;
      }
    case Num_value:
      {
        n = Parse_state_43(followers);
        break;
      }
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_50();
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:BasicType  ->  openbrksym . Identsym openparsym closeparsym closebrksym followers: verticalbarsym starsym closeparsym Identsym commasym closechainsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _doggy_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 41
   Intsym 
 */
static int Parse_state_41 (SymbolSet followers)	/* state 41 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_42();
      }
  return n-1;
}

/* directors of state 43
   dotdotsym 
 */
static int Parse_state_43 (SymbolSet followers)	/* state 43 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_44(followers);
      }
  return n-1;
}

/* directors of state 44
   minussym Intsym 
 */
static int Parse_state_44 (SymbolSet followers)	/* state 44 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x800, 0x20000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(44);
    switch (_doggy_symbol) {
    case Intsym_value:
      n = 0; _doggy_symbol = OPT_minussym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case minussym_value:
      {
        static Int my_followers[] = { 0x2000800, 0x8000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_40();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_minussym_value:
      {
        static Int my_followers[] = { 0x2000000, 0x8000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_41(_followers);
        break;
      }
    case Num_value:
      {
        n = Parse_state_45(followers);
        break;
      }
    default:
    /* default item:BasicType  ->  openbrksym Num dotdotsym . Num OPT_STEPsym_Num closebrksym       followers: verticalbarsym closeparsym commasym closechainsym _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym starsym  */
/* nt = 0x96d3da8 */
      InputError (SCAN_POSITION, TRUE, "Num expected");
      PUSH_PARSEVALUE(Pointer,0,doggy_Num);
      _doggy_symbol = Num_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 45
   STEPsym closebrksym 
 */
static int Parse_state_45 (SymbolSet followers)	/* state 45 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2000000, 0x8000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(45);
    switch (_doggy_symbol) {
    case STEPsym_value:
      {
        static Int my_followers[] = { 0x2000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_46(_followers);
        break;
      }
    case OPT_STEPsym_Num_value:
      {
        n = Parse_state_48();
        break;
      }
    default:
    /* default item:BasicType  ->  openbrksym Num dotdotsym Num . OPT_STEPsym_Num closebrksym       followers: verticalbarsym closeparsym commasym closechainsym _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym starsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,doggy_Num);
      _doggy_symbol = OPT_STEPsym_Num_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 46
   minussym Intsym 
 */
static int Parse_state_46 (SymbolSet followers)	/* state 46 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x800, 0x20000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(46);
    switch (_doggy_symbol) {
    case Intsym_value:
      n = 0; _doggy_symbol = OPT_minussym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case minussym_value:
      {
        static Int my_followers[] = { 0x800, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_40();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_minussym_value:
      {
        n = Parse_state_41(followers);
        break;
      }
    case Num_value:
      {
        n = Parse_state_47();
        break;
      }
    default:
    /* default item:OPT_STEPsym_Num  ->  STEPsym . Num      followers: closebrksym  */
/* nt = 0x96d3da8 */
      InputError (SCAN_POSITION, TRUE, "Num expected");
      PUSH_PARSEVALUE(Pointer,0,doggy_Num);
      _doggy_symbol = Num_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_48 (void)	/* state 48 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_49();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

static int Parse_state_50 (void)	/* state 50 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_51();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
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

static int Parse_state_52 (void)	/* state 52 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_53();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 56
   openchainsym openbrksym OPRsym Identsym closechainsym 
 */
static int Parse_state_56 (SymbolSet followers)	/* state 56 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1030404, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(56);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x120000, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x120000, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x20000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_36(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x120000, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        static Int my_followers[] = { 0x20000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x20000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(_followers);
        break;
      }
    case Type_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_57(_followers);
        break;
      }
    case ALT_Type_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_60();
        break;
      }
    case Types_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_61();
        break;
      }
    case OPT_Types_value:
      {
        n = Parse_state_62();
        break;
      }
    default:
    /* default item:Type  ->  openchainsym . OPT_Types closechainsym        followers: closeparsym commasym closechainsym Identsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Type);
      _doggy_symbol = OPT_Types_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 57
   commasym 
 */
static int Parse_state_57 (SymbolSet followers)	/* state 57 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x2000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(57);
    switch (_doggy_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_58(followers);
        break;
      }
    default:
    /* default item:ALT_Type_SEP_commasym  ->  Type .       followers: closechainsym closeparsym  */
      n = 1; _doggy_symbol = ALT_Type_SEP_commasym_value;
      { /* alt action */
        doggy_Type  t = POP_PARSEVALUE (Pointer, doggy_Type);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Type(t,NULL),List_doggy_Type);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 58
   openchainsym openbrksym OPRsym Identsym 
 */
static int Parse_state_58 (SymbolSet followers)	/* state 58 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010404, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(58);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100000, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x100000, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_36(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100000, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(_followers);
        break;
      }
    case Type_value:
      {
        n = Parse_state_57(followers);
        break;
      }
    case ALT_Type_SEP_commasym_value:
      {
        n = Parse_state_59();
        break;
      }
    default:
    /* default item:ALT_Type_SEP_commasym  ->  Type commasym . ALT_Type_SEP_commasym        followers: closechainsym closeparsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Type_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Type);
      _doggy_symbol = ALT_Type_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_62 (void)	/* state 62 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_63();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

static int Parse_state_64 (void)	/* state 64 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_65();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 68
   closeparsym 
 */
static int Parse_state_68 (SymbolSet followers)	/* state 68 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_69(followers);
      }
  return n-1;
}

/* directors of state 69
   colonsym Identsym 
 */
static int Parse_state_69 (SymbolSet followers)	/* state 69 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x2004, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(69);
    switch (_doggy_symbol) {
    case colonsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_70(_followers);
        break;
      }
    case OPT_colonsym_Type_value:
      {
        n = Parse_state_72(followers);
        break;
      }
    default:
    /* default item:Operation_def  ->  Identsym openparsym OPT_Types closeparsym . OPT_colonsym_Type Identsym OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym OPTMORE_Property      followers: Identsym SUPPORTSsym MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,doggy_Type);
      _doggy_symbol = OPT_colonsym_Type_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 70
   openchainsym openbrksym OPRsym Identsym 
 */
static int Parse_state_70 (SymbolSet followers)	/* state 70 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010404, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(70);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100000, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x100000, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        n = Parse_state_36(followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100000, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(followers);
        break;
      }
    case Type_value:
      {
        n = Parse_state_71();
        break;
      }
    default:
    /* default item:OPT_colonsym_Type  ->  colonsym . Type  followers: Identsym  */
/* nt = 0x96ce0d0 */
      n = 0; _doggy_symbol = Type_value;
      { ParseValue me;
        List_doggy_Type  t = POP_PARSEVALUE (Pointer, List_doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_TupleType(src_info, t);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 72
   Identsym 
 */
static int Parse_state_72 (SymbolSet followers)	/* state 72 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_73(followers);
      }
  return n-1;
}

/* directors of state 73
   ATTRIBUTESsym COMMUTATIVEsym 
 */
static int Parse_state_73 (SymbolSet followers)	/* state 73 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0xc00000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(73);
    switch (_doggy_symbol) {
    case ATTRIBUTESsym_value:
      {
        static Int my_followers[] = { 0x0, 0x400000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_7(_followers);
        break;
      }
    case OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_value:
      {
        n = Parse_state_74(followers);
        break;
      }
    default:
    /* default item:Operation_def  ->  Identsym openparsym OPT_Types closeparsym OPT_colonsym_Type Identsym . OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym OPTMORE_Property      followers: Identsym SUPPORTSsym MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,doggy_Attributes);
      _doggy_symbol = OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 74
   COMMUTATIVEsym 
 */
static int Parse_state_74 (SymbolSet followers)	/* state 74 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x400000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(74);
    switch (_doggy_symbol) {
    case COMMUTATIVEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x400000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_75();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Property_value:
      {
        n = Parse_state_76(followers);
        break;
      }
    case OPTMORE_Property_value:
      {
        n = Parse_state_78();
        break;
      }
    default:
    /* default item:Operation_def  ->  Identsym openparsym OPT_Types closeparsym OPT_colonsym_Type Identsym OPT_ATTRIBUTESsym_openchainsym_Attributes_closechainsym . OPTMORE_Property      followers: Identsym SUPPORTSsym MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Property);
      _doggy_symbol = OPTMORE_Property_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 76
   COMMUTATIVEsym 
 */
static int Parse_state_76 (SymbolSet followers)	/* state 76 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x400000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(76);
    switch (_doggy_symbol) {
    case COMMUTATIVEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x400000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_75();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Property_value:
      {
        n = Parse_state_76(followers);
        break;
      }
    case OPTMORE_Property_value:
      {
        n = Parse_state_77();
        break;
      }
    default:
    /* default item:OPTMORE_Property  ->  Property . OPTMORE_Property       followers: Identsym SUPPORTSsym MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Property);
      _doggy_symbol = OPTMORE_Property_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 79
   Identsym 
 */
static int Parse_state_79 (SymbolSet followers)	/* state 79 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(79);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_31(_followers);
        break;
      }
    case Operation_def_value:
      {
        n = Parse_state_79(followers);
        break;
      }
    case OPTMORE_Operation_def_value:
      {
        n = Parse_state_80();
        break;
      }
    default:
    /* default item:OPTMORE_Operation_def  ->  Operation_def . OPTMORE_Operation_def        followers: SUPPORTSsym MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Operation_def);
      _doggy_symbol = OPTMORE_Operation_def_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 81
   SUPPORTSsym 
 */
static int Parse_state_81 (SymbolSet followers)	/* state 81 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x1000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(81);
    switch (_doggy_symbol) {
    case SUPPORTSsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_82(followers);
        break;
      }
    case OPT_SUPPORTSsym_OPTMORE_Applied_formal_value:
      {
        n = Parse_state_87();
        break;
      }
    default:
    /* default item:machine_description  ->  MACHINEsym DESCRIPTIONsym Identsym OPTMORE_Operation_def . OPT_SUPPORTSsym_OPTMORE_Applied_formal      followers: MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Applied_formal);
      _doggy_symbol = OPT_SUPPORTSsym_OPTMORE_Applied_formal_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 82
   Identsym 
 */
static int Parse_state_82 (SymbolSet followers)	/* state 82 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(82);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_83();
        break;
      }
    case Applied_formal_value:
      {
        n = Parse_state_84(followers);
        break;
      }
    case OPTMORE_Applied_formal_value:
      {
        n = Parse_state_86();
        break;
      }
    default:
    /* default item:OPT_SUPPORTSsym_OPTMORE_Applied_formal  ->  SUPPORTSsym . OPTMORE_Applied_formal        followers: MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Applied_formal);
      _doggy_symbol = OPTMORE_Applied_formal_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 84
   Identsym 
 */
static int Parse_state_84 (SymbolSet followers)	/* state 84 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(84);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_83();
        break;
      }
    case Applied_formal_value:
      {
        n = Parse_state_84(followers);
        break;
      }
    case OPTMORE_Applied_formal_value:
      {
        n = Parse_state_85();
        break;
      }
    default:
    /* default item:OPTMORE_Applied_formal  ->  Applied_formal . OPTMORE_Applied_formal     followers: MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Applied_formal);
      _doggy_symbol = OPTMORE_Applied_formal_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 88
   MACHINEsym EXTERNALsym RULESsym FUNCTIONSsym 
 */
static int Parse_state_88 (SymbolSet followers)	/* state 88 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x5048, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(88);
    switch (_doggy_symbol) {
    case MACHINEsym_value:
      {
        static Int my_followers[] = { 0x5008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_28(_followers);
        break;
      }
    case machine_description_value:
      {
        static Int my_followers[] = { 0x5008, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_89();
        break;
      }
    case OPT_machine_description_value:
      {
        n = Parse_state_90(followers);
        break;
      }
    default:
    /* default item:doggy  ->  OPT_Typedefs machine_description . OPT_machine_description OPT_externals OPTMORE_Section     followers: doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,doggy_machine_description);
      _doggy_symbol = OPT_machine_description_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 90
   EXTERNALsym RULESsym FUNCTIONSsym 
 */
static int Parse_state_90 (SymbolSet followers)	/* state 90 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x5008, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(90);
    switch (_doggy_symbol) {
    case EXTERNALsym_value:
      {
        static Int my_followers[] = { 0x5000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91(_followers);
        break;
      }
    case externals_value:
      {
        static Int my_followers[] = { 0x5000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_101();
        break;
      }
    case OPT_externals_value:
      {
        n = Parse_state_102(followers);
        break;
      }
    default:
    /* default item:doggy  ->  OPT_Typedefs machine_description OPT_machine_description . OPT_externals OPTMORE_Section     followers: doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_FunctionDef);
      _doggy_symbol = OPT_externals_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 91
   externsym 
 */
static int Parse_state_91 (SymbolSet followers)	/* state 91 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(91);
    switch (_doggy_symbol) {
    case externsym_value:
      {
        static Int my_followers[] = { 0x10, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92(_followers);
        break;
      }
    case FunctionDef_value:
      {
        n = Parse_state_98(followers);
        break;
      }
    case OPTMORE_FunctionDef_value:
      {
        n = Parse_state_100();
        break;
      }
    default:
    /* default item:externals  ->  EXTERNALsym . OPTMORE_FunctionDef        followers: RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_FunctionDef);
      _doggy_symbol = OPTMORE_FunctionDef_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 92
   openchainsym openbrksym OPRsym Identsym 
 */
static int Parse_state_92 (SymbolSet followers)	/* state 92 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010404, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(92);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100004, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x100004, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_36(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100004, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(_followers);
        break;
      }
    case Type_value:
      {
        n = Parse_state_93(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:FunctionDef  ->  externsym . Type Identsym semicolonsym followers: externsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = 0x96ce0d0 */
      n = 0; _doggy_symbol = Type_value;
      { ParseValue me;
        List_doggy_Type  t = POP_PARSEVALUE (Pointer, List_doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_TupleType(src_info, t);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 93
   Identsym 
 */
static int Parse_state_93 (SymbolSet followers)	/* state 93 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_94(followers);
      }
  return n-1;
}

/* directors of state 94
   semicolonsym openparsym 
 */
static int Parse_state_94 (SymbolSet followers)	/* state 94 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x120, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(94);
    switch (_doggy_symbol) {
    case openparsym_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_35(_followers);
        break;
      }
    case ArgTypes_value:
      {
        n = Parse_state_95();
        break;
      }
    case semicolonsym_value:
      {
        n = Parse_state_97();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:FunctionDef  ->  externsym Type Identsym . semicolonsym followers: externsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "semicolonsym expected");
      dont_shift = TRUE; _doggy_symbol = semicolonsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_95 (void)	/* state 95 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_96();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 98
   externsym 
 */
static int Parse_state_98 (SymbolSet followers)	/* state 98 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(98);
    switch (_doggy_symbol) {
    case externsym_value:
      {
        static Int my_followers[] = { 0x10, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92(_followers);
        break;
      }
    case FunctionDef_value:
      {
        n = Parse_state_98(followers);
        break;
      }
    case OPTMORE_FunctionDef_value:
      {
        n = Parse_state_99();
        break;
      }
    default:
    /* default item:OPTMORE_FunctionDef  ->  FunctionDef . OPTMORE_FunctionDef      followers: RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_FunctionDef);
      _doggy_symbol = OPTMORE_FunctionDef_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 102
   RULESsym FUNCTIONSsym 
 */
static int Parse_state_102 (SymbolSet followers)	/* state 102 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x5000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(102);
    switch (_doggy_symbol) {
    case FUNCTIONSsym_value:
      {
        static Int my_followers[] = { 0x5000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_103(_followers);
        break;
      }
    case RULESsym_value:
      {
        static Int my_followers[] = { 0x5000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_300(_followers);
        break;
      }
    case Funcs_value:
      {
        static Int my_followers[] = { 0x5000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_314();
        break;
      }
    case Rules_value:
      {
        static Int my_followers[] = { 0x5000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_315();
        break;
      }
    case Section_value:
      {
        n = Parse_state_316(followers);
        break;
      }
    case OPTMORE_Section_value:
      {
        n = Parse_state_318();
        break;
      }
    default:
    /* default item:doggy  ->  OPT_Typedefs machine_description OPT_machine_description OPT_externals . OPTMORE_Section     followers: doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Section);
      _doggy_symbol = OPTMORE_Section_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 103
   externsym openchainsym openbrksym OPRsym Identsym 
 */
static int Parse_state_103 (SymbolSet followers)	/* state 103 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010414, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(103);
    switch (_doggy_symbol) {
    case openchainsym_value:
    case openbrksym_value:
    case OPRsym_value:
    case Identsym_value:
      n = 0; _doggy_symbol = OPT_externsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case externsym_value:
      {
        static Int my_followers[] = { 0x1010414, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_104();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_externsym_value:
      {
        static Int my_followers[] = { 0x1010414, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_105(_followers);
        break;
      }
    case Func_value:
      {
        n = Parse_state_297(followers);
        break;
      }
    case OPTMORE_Func_value:
      {
        n = Parse_state_299();
        break;
      }
    default:
    /* default item:Funcs  ->  FUNCTIONSsym . OPTMORE_Func  followers: RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Func);
      _doggy_symbol = OPTMORE_Func_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 105
   openchainsym openbrksym OPRsym Identsym 
 */
static int Parse_state_105 (SymbolSet followers)	/* state 105 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010404, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(105);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100004, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x100004, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_36(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100004, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(_followers);
        break;
      }
    case Type_value:
      {
        n = Parse_state_106(followers);
        break;
      }
    default:
    /* default item:Func  ->  OPT_externsym . Type Identsym FuncRules semicolonsym  followers: externsym openchainsym openbrksym OPRsym Identsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = 0x96ce0d0 */
      n = 0; _doggy_symbol = Type_value;
      { ParseValue me;
        List_doggy_Type  t = POP_PARSEVALUE (Pointer, List_doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_TupleType(src_info, t);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 106
   Identsym 
 */
static int Parse_state_106 (SymbolSet followers)	/* state 106 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_107(followers);
      }
  return n-1;
}

/* directors of state 107
   openparsym 
 */
static int Parse_state_107 (SymbolSet followers)	/* state 107 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x100, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(107);
    switch (_doggy_symbol) {
    case openparsym_value:
      {
        static Int my_followers[] = { 0x20, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_108(_followers);
        break;
      }
    case FuncRule_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_291(_followers);
        break;
      }
    case ALT_FuncRule_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_294();
        break;
      }
    case FuncRules_value:
      {
        n = Parse_state_295();
        break;
      }
    default:
    /* default item:Func  ->  OPT_externsym Type Identsym . FuncRules semicolonsym  followers: externsym openchainsym openbrksym OPRsym Identsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = 0x96a6c78 */
      InputError (SCAN_POSITION, TRUE, "FuncRules expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_FuncRule);
      _doggy_symbol = FuncRules_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 108
   Identsym openchainsym openbrksym OPRsym closeparsym 
 */
static int Parse_state_108 (SymbolSet followers)	/* state 108 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010604, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(108);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100204, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_109(_followers);
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x100204, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x204, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_36(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100204, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        static Int my_followers[] = { 0x204, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x204, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(_followers);
        break;
      }
    case Type_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_250(_followers);
        break;
      }
    case Argument_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_253(_followers);
        break;
      }
    case ALT_Argument_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_256();
        break;
      }
    case Arguments_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_257();
        break;
      }
    case OPT_Arguments_value:
      {
        n = Parse_state_258(followers);
        break;
      }
    default:
    /* default item:FuncRule  ->  openparsym . OPT_Arguments closeparsym Rhs        followers: commasym semicolonsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Argument);
      _doggy_symbol = OPT_Arguments_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 109
   equalssym 
 */
static int Parse_state_109 (SymbolSet followers)	/* state 109 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(109);
    switch (_doggy_symbol) {
    case commasym_value:
    case closeparsym_value:
      n = 0; _doggy_symbol = OPT_equalssym_UnTypedPattern_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,doggy_Pattern);
      }
      break;
    case equalssym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_110(followers);
        break;
      }
    case OPT_equalssym_UnTypedPattern_value:
      {
        n = Parse_state_244();
        break;
      }
    case ParPattern_value:
      {
        n = Parse_state_245();
        break;
      }
    case PatArg1_value:
      {
        n = Parse_state_246();
        break;
      }
    case ParArg_value:
      {
        n = Parse_state_247();
        break;
      }
    case SetArg_value:
      {
        n = Parse_state_248();
        break;
      }
    case ArgPat2_value:
      {
        n = Parse_state_249();
        break;
      }
    default:
    /* default item:BasicType  ->  Identsym .       followers: verticalbarsym Identsym starsym  */
      n = 1; _doggy_symbol = BasicType_value;
      { ParseValue me;
        Ident  type_id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_IdentType(src_info, type_id);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 110
   openbrksym openparsym _sym NULLsym Intsym Identsym ANYsym openchainsym 
 */
static int Parse_state_110 (SymbolSet followers)	/* state 110 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d0904, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(110);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_111(_followers);
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_242();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(_followers);
        break;
      }
    case BasicPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_214(_followers);
        break;
      }
    case IdentPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_216();
        break;
      }
    case SingleDefPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_217();
        break;
      }
    case DefPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_218();
        break;
      }
    case IdParPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_219();
        break;
      }
    case BinPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_220();
        break;
      }
    case SimplePattern_value:
      {
        n = Parse_state_224(followers);
        break;
      }
    case ConsPattern_value:
      {
        n = Parse_state_226();
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_113(_followers);
        break;
      }
    case UnTypedPattern_value:
      {
        n = Parse_state_243();
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_238(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:SetArg  ->  equalssym . OpSet   followers: commasym closeparsym  */
/* nt = 0x96babd0 */
      InputError (SCAN_POSITION, TRUE, "OpSet expected");
      PUSH_PARSEVALUE(Pointer,0,doggy_Applied_operation);
      _doggy_symbol = OpSet_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 111
   equalssym 
 */
static int Parse_state_111 (SymbolSet followers)	/* state 111 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(111);
    switch (_doggy_symbol) {
    case openparsym_value:
      n = 1; _doggy_symbol = Applied_formal_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Applied_formal");
        me->sub.PointerValue = Create_doggy_Applied_formal(src_info, id);
      }
      break;
    case equalssym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_112(followers);
        break;
      }
    case ParPattern_value:
      {
        n = Parse_state_128();
        break;
      }
    default:
    /* default item:IdentPattern  ->  Identsym .     followers: CONSsym commasym closeparsym openchainsym verticalbarsym arrowsym  */
      n = 1; _doggy_symbol = IdentPattern_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_IdentPattern(src_info, id);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 112
   _sym NULLsym Intsym Identsym openbrksym ANYsym openparsym 
 */
static int Parse_state_112 (SymbolSet followers)	/* state 112 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18c0904, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(112);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_113(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_83();
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case BasicPattern_value:
      {
        n = Parse_state_214(followers);
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_238(followers);
        break;
      }
    case BinPattern_value:
      {
        n = Parse_state_241();
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:SingleDefPattern  ->  Identsym equalssym . BinPattern   followers: CONSsym commasym closeparsym openchainsym verticalbarsym arrowsym  */
/* nt = 0x96b0b70 */
      InputError (SCAN_POSITION, TRUE, "BinPattern expected");
      PUSH_PARSEVALUE(Pointer,0,doggy_Pattern);
      _doggy_symbol = BinPattern_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 113
   Identsym 
 */
static int Parse_state_113 (SymbolSet followers)	/* state 113 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(113);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x2000000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_83();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x2000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_114(_followers);
        break;
      }
    case ALT_Applied_formal_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x2000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_117();
        break;
      }
    case Applied_formals_value:
      {
        n = Parse_state_118();
        break;
      }
    default:
    /* default item:OpSet  ->  openbrksym . Applied_formals closebrksym     followers: openparsym commasym closeparsym  */
/* nt = 0x96bb1d0 */
      InputError (SCAN_POSITION, TRUE, "Applied_formals expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Applied_formal);
      _doggy_symbol = Applied_formals_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 114
   commasym 
 */
static int Parse_state_114 (SymbolSet followers)	/* state 114 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x2000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(114);
    switch (_doggy_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_115(followers);
        break;
      }
    default:
    /* default item:ALT_Applied_formal_SEP_commasym  ->  Applied_formal .   followers: closebrksym  */
      n = 1; _doggy_symbol = ALT_Applied_formal_SEP_commasym_value;
      { /* alt action */
        doggy_Applied_formal  ops = POP_PARSEVALUE (Pointer, doggy_Applied_formal);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Applied_formal(ops,NULL),List_doggy_Applied_formal);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 115
   Identsym 
 */
static int Parse_state_115 (SymbolSet followers)	/* state 115 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(115);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_83();
        break;
      }
    case Applied_formal_value:
      {
        n = Parse_state_114(followers);
        break;
      }
    case ALT_Applied_formal_SEP_commasym_value:
      {
        n = Parse_state_116();
        break;
      }
    default:
    /* default item:ALT_Applied_formal_SEP_commasym  ->  Applied_formal commasym . ALT_Applied_formal_SEP_commasym  followers: closebrksym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Applied_formal_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Applied_formal);
      _doggy_symbol = ALT_Applied_formal_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_118 (void)	/* state 118 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_119();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 123
   openparsym 
 */
static int Parse_state_123 (SymbolSet followers)	/* state 123 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_124(followers);
      }
  return n-1;
}

/* directors of state 124
   openbrksym OPRsym Identsym _sym NULLsym Intsym ANYsym openchainsym closeparsym 
 */
static int Parse_state_124 (SymbolSet followers)	/* state 124 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d0e04, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(124);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x58d0b04, 0x2044000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_125(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x58d0b04, 0x2044000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_127(_followers);
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x4000300, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x4000300, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x4000300, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(_followers);
        break;
      }
    case BasicPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_214(_followers);
        break;
      }
    case IdentPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_216();
        break;
      }
    case SingleDefPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_217();
        break;
      }
    case DefPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_218();
        break;
      }
    case IdParPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_219();
        break;
      }
    case BinPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_220();
        break;
      }
    case SimplePattern_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_224(_followers);
        break;
      }
    case ConsPattern_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_226();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x18d0a04, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_228(_followers);
        break;
      }
    case UnTypedPattern_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_230();
        break;
      }
    case Pattern_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_231(_followers);
        break;
      }
    case ALT_Pattern_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_234();
        break;
      }
    case Patterns_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_235();
        break;
      }
    case OPT_Patterns_value:
      {
        n = Parse_state_236();
        break;
      }
    default:
    /* default item:BasicPattern  ->  Applied_operation openparsym . OPT_Patterns closeparsym       followers: CONSsym commasym closeparsym openquotesym openchainsym verticalbarsym arrowsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Pattern);
      _doggy_symbol = OPT_Patterns_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 125
   Identsym minussym Intsym 
 */
static int Parse_state_125 (SymbolSet followers)	/* state 125 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x804, 0x20000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(125);
    switch (_doggy_symbol) {
    case Intsym_value:
      n = 0; _doggy_symbol = OPT_minussym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case Identsym_value:
      {
        static Int my_followers[] = { 0x2000000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_126(_followers);
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x2000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_114(_followers);
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x800, 0x200000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_40();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ALT_Applied_formal_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x2000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_117();
        break;
      }
    case OPT_minussym_value:
      {
        static Int my_followers[] = { 0x0, 0x200000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_41(_followers);
        break;
      }
    case Applied_formals_value:
      {
        n = Parse_state_118();
        break;
      }
    case Num_value:
      {
        n = Parse_state_43(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:OpSet  ->  openbrksym . Applied_formals closebrksym     followers: openparsym  */
/* nt = 0x96bb1d0 */
      InputError (SCAN_POSITION, TRUE, "Applied_formals expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Applied_formal);
      _doggy_symbol = Applied_formals_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 126
   openparsym 
 */
static int Parse_state_126 (SymbolSet followers)	/* state 126 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x100, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(126);
    switch (_doggy_symbol) {
    case openparsym_value:
      {
        n = Parse_state_51();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    default:
    /* default item:Applied_formal  ->  Identsym .  followers: commasym closebrksym  */
      n = 1; _doggy_symbol = Applied_formal_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Applied_formal");
        me->sub.PointerValue = Create_doggy_Applied_formal(src_info, id);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 127
   equalssym 
 */
static int Parse_state_127 (SymbolSet followers)	/* state 127 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(127);
    switch (_doggy_symbol) {
    case CONSsym_value:
    case commasym_value:
    case closeparsym_value:
      n = 1; _doggy_symbol = IdentPattern_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_IdentPattern(src_info, id);
      }
      break;
    case openparsym_value:
      n = 1; _doggy_symbol = Applied_formal_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Applied_formal");
        me->sub.PointerValue = Create_doggy_Applied_formal(src_info, id);
      }
      break;
    case equalssym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_112(followers);
        break;
      }
    case ParPattern_value:
      {
        n = Parse_state_128();
        break;
      }
    default:
    /* default item:BasicType  ->  Identsym . followers: _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym starsym  */
      n = 1; _doggy_symbol = BasicType_value;
      { ParseValue me;
        Ident  type_id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Type");
        me->sub.PointerValue = Create_doggy_IdentType(src_info, type_id);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 131
   equalssym 
 */
static int Parse_state_131 (SymbolSet followers)	/* state 131 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(131);
    switch (_doggy_symbol) {
    case equalssym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_132(followers);
        break;
      }
    case OPT_equalssym_SimpleExpr_value:
      {
        n = Parse_state_204();
        break;
      }
    default:
    /* default item:BasicPattern  ->  _sym . OPT_equalssym_SimpleExpr       followers: CONSsym commasym closeparsym openquotesym openchainsym verticalbarsym arrowsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,doggy_Expr);
      _doggy_symbol = OPT_equalssym_SimpleExpr_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 132
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_132 (SymbolSet followers)	/* state 132 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(132);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(followers);
        break;
      }
    case IFsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(followers);
        break;
      }
    case Constant_value:
      {
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(followers);
        break;
      }
    case MonOp_value:
      {
        n = Parse_state_148(followers);
        break;
      }
    case SimpleExpr_value:
      {
        n = Parse_state_203();
        break;
      }
    default:
    /* default item:OPT_equalssym_SimpleExpr  ->  equalssym . SimpleExpr    followers: CONSsym commasym closeparsym openquotesym openchainsym verticalbarsym arrowsym  */
/* nt = 0x96c64c0 */
      n = 0; _doggy_symbol = SimpleExpr_value;
      { ParseValue me;
        doggy_Expr  arg = POP_PARSEVALUE (Pointer, doggy_Expr);
        doggy_MonOp  op = POP_PARSEVALUE (Int, doggy_MonOp);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = Create_doggy_MonExpr(src_info, op, arg);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 143
   openparsym 
 */
static int Parse_state_143 (SymbolSet followers)	/* state 143 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x100, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(143);
    switch (_doggy_symbol) {
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_144(followers);
        break;
      }
    default:
    /* default item:SimpleExpr  ->  Identsym .      followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym CONSsym openquotesym minussym plussym ampersandsym starsym percentsym slashsym shrsym shlsym greaterthansym lessthansym gesym lesym neqsym eqsym hatsym corsym candsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
      n = 1; _doggy_symbol = SimpleExpr_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = Create_doggy_IdentExpr(src_info, id);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 144
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym closeparsym 
 */
static int Parse_state_144 (SymbolSet followers)	/* state 144 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040b04, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(144);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x4000200, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x4000200, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x200, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_196(_followers);
        break;
      }
    case ALT_Expr_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_199();
        break;
      }
    case Exprs_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_200();
        break;
      }
    case OPT_Exprs_value:
      {
        n = Parse_state_201();
        break;
      }
    default:
    /* default item:SimpleExpr  ->  Identsym openparsym . OPT_Exprs closeparsym     followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym CONSsym openquotesym minussym plussym ampersandsym starsym percentsym slashsym shrsym shlsym greaterthansym lessthansym gesym lesym neqsym eqsym hatsym corsym candsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Expr);
      _doggy_symbol = OPT_Exprs_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 145
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_145 (SymbolSet followers)	/* state 145 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(145);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_183();
        break;
      }
    case Condition_value:
      {
        n = Parse_state_184(followers);
        break;
      }
    default:
    /* default item:SimpleExpr  ->  IFsym . Condition THENsym Expr OPTMORE_ELSIFsym_Condition_THENsym_Expr ELSEsym Expr FIsym       followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym CONSsym openquotesym minussym plussym ampersandsym starsym percentsym slashsym shrsym shlsym greaterthansym lessthansym gesym lesym neqsym eqsym hatsym corsym candsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = 0x96c6750 */
      InputError (SCAN_POSITION, TRUE, "Condition expected");
      PUSH_PARSEVALUE(Pointer,0,doggy_Expr);
      _doggy_symbol = Condition_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 147
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_147 (SymbolSet followers)	/* state 147 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(147);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x8c040b04, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x4000200, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x4000200, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        n = Parse_state_181();
        break;
      }
    default:
    /* default item:SimpleExpr  ->  openparsym . Expr closeparsym   followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym CONSsym openquotesym minussym plussym ampersandsym starsym percentsym slashsym shrsym shlsym greaterthansym lessthansym gesym lesym neqsym eqsym hatsym corsym candsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = 0x96bd958 */
      n = 0; _doggy_symbol = Expr_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 148
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_148 (SymbolSet followers)	/* state 148 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(148);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(followers);
        break;
      }
    case IFsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(followers);
        break;
      }
    case Constant_value:
      {
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(followers);
        break;
      }
    case MonOp_value:
      {
        n = Parse_state_148(followers);
        break;
      }
    case SimpleExpr_value:
      {
        n = Parse_state_149();
        break;
      }
    default:
    /* default item:SimpleExpr  ->  MonOp . SimpleExpr      followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym CONSsym openquotesym minussym plussym ampersandsym starsym percentsym slashsym shrsym shlsym greaterthansym lessthansym gesym lesym neqsym eqsym hatsym corsym candsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = 0x96c64c0 */
      n = 0; _doggy_symbol = SimpleExpr_value;
      { ParseValue me;
        doggy_Expr  arg = POP_PARSEVALUE (Pointer, doggy_Expr);
        doggy_MonOp  op = POP_PARSEVALUE (Int, doggy_MonOp);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Expr");
        me->sub.PointerValue = Create_doggy_MonExpr(src_info, op, arg);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 150
   CONSsym openquotesym minussym plussym ampersandsym starsym percentsym slashsym shrsym shlsym greaterthansym lessthansym gesym lesym neqsym eqsym hatsym corsym candsym 
 */
static int Parse_state_150 (SymbolSet followers)	/* state 150 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4000000, 0x7fffe };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(150);
    switch (_doggy_symbol) {
    case candsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_151();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case corsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_152();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_153();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case eqsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_154();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case neqsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_155();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case lesym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_156();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case gesym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_157();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case lessthansym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_158();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case greaterthansym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_159();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case shlsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_160();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case shrsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_161();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_162();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_164();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_165();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_166();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_167();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case openquotesym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_168(_followers);
        break;
      }
    case CONSsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_170();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Operator_value:
      {
        n = Parse_state_171(followers);
        break;
      }
    case IdOp_value:
      {
        n = Parse_state_174(followers);
        break;
      }
    case cons_value:
      {
        n = Parse_state_179(followers);
        break;
      }
    default:
    /* default item:ALT_SimpleExpr_SEP_Operator  ->  SimpleExpr .   followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
      n = 1; _doggy_symbol = ALT_SimpleExpr_SEP_Operator_value;
      { /* alt action */
        doggy_Expr  args = POP_PARSEVALUE (Pointer, doggy_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Expr(args,NULL),List_doggy_Expr);
        PUSH_PARSEVALUE(Pointer,NULL,List_doggy_Operator);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 168
   Identsym 
 */
static int Parse_state_168 (SymbolSet followers)	/* state 168 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_169();
      }
  return n-1;
}

/* directors of state 171
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_171 (SymbolSet followers)	/* state 171 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(171);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x0, 0x3fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x0, 0x3fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x0, 0x3fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x0, 0x3fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x3fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x0, 0x3fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x0, 0x3fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x0, 0x3fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x0, 0x3fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        n = Parse_state_172(followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        n = Parse_state_173();
        break;
      }
    default:
    /* default item:ALT_SimpleExpr_SEP_Operator  ->  SimpleExpr Operator . ALT_SimpleExpr_SEP_Operator      followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_SimpleExpr_SEP_Operator expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Expr);
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Operator);
      _doggy_symbol = ALT_SimpleExpr_SEP_Operator_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 172
   minussym plussym ampersandsym starsym percentsym slashsym shrsym shlsym greaterthansym lessthansym gesym lesym neqsym eqsym hatsym corsym candsym 
 */
static int Parse_state_172 (SymbolSet followers)	/* state 172 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x3fffe };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(172);
    switch (_doggy_symbol) {
    case candsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_151();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case corsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_152();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case hatsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_153();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case eqsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_154();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case neqsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_155();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case lesym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_156();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case gesym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_157();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case lessthansym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_158();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case greaterthansym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_159();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case shlsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_160();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case shrsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_161();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case slashsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_162();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case percentsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_163();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_164();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_165();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_166();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x88040904, 0x1bc001 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_167();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Operator_value:
      {
        n = Parse_state_171(followers);
        break;
      }
    default:
    /* default item:ALT_SimpleExpr_SEP_Operator  ->  SimpleExpr .   followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
      n = 1; _doggy_symbol = ALT_SimpleExpr_SEP_Operator_value;
      { /* alt action */
        doggy_Expr  args = POP_PARSEVALUE (Pointer, doggy_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Expr(args,NULL),List_doggy_Expr);
        PUSH_PARSEVALUE(Pointer,NULL,List_doggy_Operator);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 174
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_174 (SymbolSet followers)	/* state 174 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(174);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        n = Parse_state_150(followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        n = Parse_state_178();
        break;
      }
    default:
    /* default item:IdOpExpr  ->  SimpleExpr IdOp . Expr    followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = 0x96bd958 */
      n = 0; _doggy_symbol = Expr_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 179
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_179 (SymbolSet followers)	/* state 179 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(179);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        n = Parse_state_150(followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        n = Parse_state_180();
        break;
      }
    default:
    /* default item:ConsExpr  ->  SimpleExpr cons . Expr    followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = 0x96bd958 */
      n = 0; _doggy_symbol = Expr_value;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_181 (void)	/* state 181 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_182();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 184
   THENsym 
 */
static int Parse_state_184 (SymbolSet followers)	/* state 184 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_185(followers);
      }
  return n-1;
}

/* directors of state 185
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_185 (SymbolSet followers)	/* state 185 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(185);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x24000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x24000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x24000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x24000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0xac040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0xac040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0xac040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0xac040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0xac040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0xac040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x24000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x24000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x24000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x24000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x24000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x20000000, 0x4000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x20000000, 0x4000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x20000000, 0x4000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x20000000, 0x4000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        n = Parse_state_186(followers);
        break;
      }
    default:
    /* default item:SimpleExpr  ->  IFsym Condition THENsym . Expr OPTMORE_ELSIFsym_Condition_THENsym_Expr ELSEsym Expr FIsym       followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym CONSsym openquotesym minussym plussym ampersandsym starsym percentsym slashsym shrsym shlsym greaterthansym lessthansym gesym lesym neqsym eqsym hatsym corsym candsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = 0x96bd958 */
      n = 0; _doggy_symbol = Expr_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 186
   ELSIFsym ELSEsym 
 */
static int Parse_state_186 (SymbolSet followers)	/* state 186 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x20000000, 0x4000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(186);
    switch (_doggy_symbol) {
    case ELSIFsym_value:
      {
        static Int my_followers[] = { 0x20000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_187(_followers);
        break;
      }
    case OPTMORE_ELSIFsym_Condition_THENsym_Expr_value:
      {
        n = Parse_state_192(followers);
        break;
      }
    default:
    /* default item:SimpleExpr  ->  IFsym Condition THENsym Expr . OPTMORE_ELSIFsym_Condition_THENsym_Expr ELSEsym Expr FIsym       followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym CONSsym openquotesym minussym plussym ampersandsym starsym percentsym slashsym shrsym shlsym greaterthansym lessthansym gesym lesym neqsym eqsym hatsym corsym candsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Expr);
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Expr);
      _doggy_symbol = OPTMORE_ELSIFsym_Condition_THENsym_Expr_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 187
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_187 (SymbolSet followers)	/* state 187 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(187);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x9c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x14000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        static Int my_followers[] = { 0x10000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_183();
        break;
      }
    case Condition_value:
      {
        n = Parse_state_188(followers);
        break;
      }
    default:
    /* default item:OPTMORE_ELSIFsym_Condition_THENsym_Expr  ->  ELSIFsym . Condition THENsym Expr OPTMORE_ELSIFsym_Condition_THENsym_Expr  followers: ELSEsym  */
/* nt = 0x96c6750 */
      InputError (SCAN_POSITION, TRUE, "Condition expected");
      PUSH_PARSEVALUE(Pointer,0,doggy_Expr);
      _doggy_symbol = Condition_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 188
   THENsym 
 */
static int Parse_state_188 (SymbolSet followers)	/* state 188 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_189(followers);
      }
  return n-1;
}

/* directors of state 189
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_189 (SymbolSet followers)	/* state 189 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(189);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x41fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x4000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x4000000, 0x407fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x0, 0x4000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x0, 0x4000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x0, 0x4000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x0, 0x4000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        n = Parse_state_190(followers);
        break;
      }
    default:
    /* default item:OPTMORE_ELSIFsym_Condition_THENsym_Expr  ->  ELSIFsym Condition THENsym . Expr OPTMORE_ELSIFsym_Condition_THENsym_Expr  followers: ELSEsym  */
/* nt = 0x96bd958 */
      n = 0; _doggy_symbol = Expr_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 190
   ELSIFsym 
 */
static int Parse_state_190 (SymbolSet followers)	/* state 190 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x4000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(190);
    switch (_doggy_symbol) {
    case ELSIFsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_187(followers);
        break;
      }
    case OPTMORE_ELSIFsym_Condition_THENsym_Expr_value:
      {
        n = Parse_state_191();
        break;
      }
    default:
    /* default item:OPTMORE_ELSIFsym_Condition_THENsym_Expr  ->  ELSIFsym Condition THENsym Expr . OPTMORE_ELSIFsym_Condition_THENsym_Expr  followers: ELSEsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Expr);
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Expr);
      _doggy_symbol = OPTMORE_ELSIFsym_Condition_THENsym_Expr_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 192
   ELSEsym 
 */
static int Parse_state_192 (SymbolSet followers)	/* state 192 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_193(followers);
      }
  return n-1;
}

/* directors of state 193
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_193 (SymbolSet followers)	/* state 193 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(193);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x44000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x44000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x44000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x44000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0xcc040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0xcc040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0xcc040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0xcc040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0xcc040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0xcc040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x44000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x44000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x44000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x44000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x44000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x40000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x40000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x40000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x40000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        n = Parse_state_194();
        break;
      }
    default:
    /* default item:SimpleExpr  ->  IFsym Condition THENsym Expr OPTMORE_ELSIFsym_Condition_THENsym_Expr ELSEsym . Expr FIsym       followers: THENsym ELSIFsym ELSEsym FIsym closeparsym WHEREsym CONSsym openquotesym minussym plussym ampersandsym starsym percentsym slashsym shrsym shlsym greaterthansym lessthansym gesym lesym neqsym eqsym hatsym corsym candsym openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = 0x96bd958 */
      n = 0; _doggy_symbol = Expr_value;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_194 (void)	/* state 194 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_195();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 196
   commasym 
 */
static int Parse_state_196 (SymbolSet followers)	/* state 196 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x2000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(196);
    switch (_doggy_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_197(followers);
        break;
      }
    default:
    /* default item:ALT_Expr_SEP_commasym  ->  Expr .       followers: closeparsym closechainsym  */
      n = 1; _doggy_symbol = ALT_Expr_SEP_commasym_value;
      { /* alt action */
        doggy_Expr  e = POP_PARSEVALUE (Pointer, doggy_Expr);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Expr(e,NULL),List_doggy_Expr);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 197
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_197 (SymbolSet followers)	/* state 197 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(197);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x4000000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x4000000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        n = Parse_state_196(followers);
        break;
      }
    case ALT_Expr_SEP_commasym_value:
      {
        n = Parse_state_198();
        break;
      }
    default:
    /* default item:ALT_Expr_SEP_commasym  ->  Expr commasym . ALT_Expr_SEP_commasym        followers: closeparsym closechainsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Expr_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Expr);
      _doggy_symbol = ALT_Expr_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_201 (void)	/* state 201 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_202();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 205
   Identsym 
 */
static int Parse_state_205 (SymbolSet followers)	/* state 205 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(205);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x20000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_206();
        break;
      }
    case IdentPattern_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_207(_followers);
        break;
      }
    case ALT_IdentPattern_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_210();
        break;
      }
    case IdentPatterns_value:
      {
        n = Parse_state_211(followers);
        break;
      }
    default:
    /* default item:DefPattern  ->  openchainsym . IdentPatterns closechainsym equalssym BinPattern followers: CONSsym commasym closeparsym openchainsym verticalbarsym arrowsym  */
/* nt = 0x96af9c0 */
      InputError (SCAN_POSITION, TRUE, "IdentPatterns expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Pattern);
      _doggy_symbol = IdentPatterns_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 207
   commasym 
 */
static int Parse_state_207 (SymbolSet followers)	/* state 207 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x2000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(207);
    switch (_doggy_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_208(followers);
        break;
      }
    default:
    /* default item:ALT_IdentPattern_SEP_commasym  ->  IdentPattern .       followers: closechainsym  */
      n = 1; _doggy_symbol = ALT_IdentPattern_SEP_commasym_value;
      { /* alt action */
        doggy_Pattern  ids = POP_PARSEVALUE (Pointer, doggy_Pattern);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Pattern(ids,NULL),List_doggy_Pattern);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 208
   Identsym 
 */
static int Parse_state_208 (SymbolSet followers)	/* state 208 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(208);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_206();
        break;
      }
    case IdentPattern_value:
      {
        n = Parse_state_207(followers);
        break;
      }
    case ALT_IdentPattern_SEP_commasym_value:
      {
        n = Parse_state_209();
        break;
      }
    default:
    /* default item:ALT_IdentPattern_SEP_commasym  ->  IdentPattern commasym . ALT_IdentPattern_SEP_commasym        followers: closechainsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_IdentPattern_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Pattern);
      _doggy_symbol = ALT_IdentPattern_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 211
   closechainsym 
 */
static int Parse_state_211 (SymbolSet followers)	/* state 211 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_212(followers);
      }
  return n-1;
}

/* directors of state 212
   equalssym 
 */
static int Parse_state_212 (SymbolSet followers)	/* state 212 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_213(followers);
      }
  return n-1;
}

/* directors of state 213
   _sym NULLsym Intsym Identsym openbrksym ANYsym 
 */
static int Parse_state_213 (SymbolSet followers)	/* state 213 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18c0804, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(213);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_113(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_83();
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case BasicPattern_value:
      {
        n = Parse_state_214(followers);
        break;
      }
    case BinPattern_value:
      {
        n = Parse_state_223();
        break;
      }
    default:
    /* default item:DefPattern  ->  openchainsym IdentPatterns closechainsym equalssym . BinPattern followers: CONSsym commasym closeparsym openchainsym verticalbarsym arrowsym  */
/* nt = 0x96b0b70 */
      InputError (SCAN_POSITION, TRUE, "BinPattern expected");
      PUSH_PARSEVALUE(Pointer,0,doggy_Pattern);
      _doggy_symbol = BinPattern_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 214
   openquotesym 
 */
static int Parse_state_214 (SymbolSet followers)	/* state 214 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x40000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(214);
    switch (_doggy_symbol) {
    case openquotesym_value:
      {
        static Int my_followers[] = { 0x18d0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_168(_followers);
        break;
      }
    case IdOp_value:
      {
        n = Parse_state_215(followers);
        break;
      }
    case OPT_IdOp_SimplePattern_value:
      {
        n = Parse_state_222();
        break;
      }
    default:
    /* default item:BinPattern  ->  BasicPattern . OPT_IdOp_SimplePattern   followers: CONSsym commasym closeparsym openchainsym verticalbarsym arrowsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      PUSH_PARSEVALUE(Pointer,0,doggy_Pattern);
      _doggy_symbol = OPT_IdOp_SimplePattern_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 215
   _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym 
 */
static int Parse_state_215 (SymbolSet followers)	/* state 215 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d0804, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(215);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_113(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_111(_followers);
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case openchainsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(followers);
        break;
      }
    case BasicPattern_value:
      {
        n = Parse_state_214(followers);
        break;
      }
    case IdentPattern_value:
      {
        n = Parse_state_216();
        break;
      }
    case SingleDefPattern_value:
      {
        n = Parse_state_217();
        break;
      }
    case DefPattern_value:
      {
        n = Parse_state_218();
        break;
      }
    case IdParPattern_value:
      {
        n = Parse_state_219();
        break;
      }
    case BinPattern_value:
      {
        n = Parse_state_220();
        break;
      }
    case SimplePattern_value:
      {
        n = Parse_state_221();
        break;
      }
    default:
    /* default item:OPT_IdOp_SimplePattern  ->  IdOp . SimplePattern        followers: CONSsym commasym closeparsym openchainsym verticalbarsym arrowsym  */
/* nt = 0x96ade10 */
      n = 0; _doggy_symbol = SimplePattern_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 224
   CONSsym 
 */
static int Parse_state_224 (SymbolSet followers)	/* state 224 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x4000000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(224);
    switch (_doggy_symbol) {
    case CONSsym_value:
      {
        static Int my_followers[] = { 0x18d0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_170();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case cons_value:
      {
        n = Parse_state_225(followers);
        break;
      }
    default:
    /* default item:UnTypedPattern  ->  SimplePattern .     followers: commasym closeparsym openchainsym verticalbarsym arrowsym  */
      n = 1; _doggy_symbol = UnTypedPattern_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 225
   _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym 
 */
static int Parse_state_225 (SymbolSet followers)	/* state 225 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d0804, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(225);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_113(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_111(_followers);
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(_followers);
        break;
      }
    case BasicPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_214(_followers);
        break;
      }
    case IdentPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_216();
        break;
      }
    case SingleDefPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_217();
        break;
      }
    case DefPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_218();
        break;
      }
    case IdParPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_219();
        break;
      }
    case BinPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_220();
        break;
      }
    case SimplePattern_value:
      {
        n = Parse_state_224(followers);
        break;
      }
    case ConsPattern_value:
      {
        n = Parse_state_226();
        break;
      }
    case UnTypedPattern_value:
      {
        n = Parse_state_227();
        break;
      }
    default:
    /* default item:ConsPattern  ->  SimplePattern cons . UnTypedPattern    followers: commasym closeparsym openchainsym verticalbarsym arrowsym  */
/* nt = 0x96acbf0 */
      n = 0; _doggy_symbol = UnTypedPattern_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 228
   _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym starsym 
 */
static int Parse_state_228 (SymbolSet followers)	/* state 228 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d0804, 0x4000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(228);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_113(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_111(_followers);
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(_followers);
        break;
      }
    case BasicPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_214(_followers);
        break;
      }
    case IdentPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_216();
        break;
      }
    case SingleDefPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_217();
        break;
      }
    case DefPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_218();
        break;
      }
    case IdParPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_219();
        break;
      }
    case BinPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_220();
        break;
      }
    case SimplePattern_value:
      {
        n = Parse_state_224(followers);
        break;
      }
    case ConsPattern_value:
      {
        n = Parse_state_226();
        break;
      }
    case starsym_value:
      {
        n = Parse_state_37();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case UnTypedPattern_value:
      {
        n = Parse_state_229();
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:Pattern  ->  BasicType . UnTypedPattern followers: commasym closeparsym  */
/* nt = 0x96acbf0 */
      n = 0; _doggy_symbol = UnTypedPattern_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 231
   commasym 
 */
static int Parse_state_231 (SymbolSet followers)	/* state 231 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x2000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(231);
    switch (_doggy_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_232(followers);
        break;
      }
    default:
    /* default item:ALT_Pattern_SEP_commasym  ->  Pattern . followers: closeparsym  */
      n = 1; _doggy_symbol = ALT_Pattern_SEP_commasym_value;
      { /* alt action */
        doggy_Pattern  args = POP_PARSEVALUE (Pointer, doggy_Pattern);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Pattern(args,NULL),List_doggy_Pattern);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 232
   openbrksym OPRsym Identsym _sym NULLsym Intsym ANYsym openchainsym 
 */
static int Parse_state_232 (SymbolSet followers)	/* state 232 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d0c04, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(232);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x58d0904, 0x2044000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_125(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x58d0904, 0x2044000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_127(_followers);
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x4000100, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x4000100, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2040000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(_followers);
        break;
      }
    case BasicPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_214(_followers);
        break;
      }
    case IdentPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_216();
        break;
      }
    case SingleDefPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_217();
        break;
      }
    case DefPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_218();
        break;
      }
    case IdParPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_219();
        break;
      }
    case BinPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_220();
        break;
      }
    case SimplePattern_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_224(_followers);
        break;
      }
    case ConsPattern_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_226();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x18d0804, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_228(_followers);
        break;
      }
    case UnTypedPattern_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_230();
        break;
      }
    case Pattern_value:
      {
        n = Parse_state_231(followers);
        break;
      }
    case ALT_Pattern_SEP_commasym_value:
      {
        n = Parse_state_233();
        break;
      }
    default:
    /* default item:ALT_Pattern_SEP_commasym  ->  Pattern commasym . ALT_Pattern_SEP_commasym       followers: closeparsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Pattern_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Pattern);
      _doggy_symbol = ALT_Pattern_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_236 (void)	/* state 236 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_237();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 238
   openbrksym OPRsym Identsym _sym NULLsym Intsym ANYsym openchainsym 
 */
static int Parse_state_238 (SymbolSet followers)	/* state 238 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d0c04, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(238);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x58d0b04, 0x44000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_125(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x58d0b04, 0x44000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_127(_followers);
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x4000300, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x4000300, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x4000300, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x4000200, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x4000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(_followers);
        break;
      }
    case BasicPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_214(_followers);
        break;
      }
    case IdentPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_216();
        break;
      }
    case SingleDefPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_217();
        break;
      }
    case DefPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_218();
        break;
      }
    case IdParPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_219();
        break;
      }
    case BinPattern_value:
      {
        static Int my_followers[] = { 0x4000200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_220();
        break;
      }
    case SimplePattern_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_224(_followers);
        break;
      }
    case ConsPattern_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_226();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x18d0a04, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_228(_followers);
        break;
      }
    case UnTypedPattern_value:
      {
        static Int my_followers[] = { 0x200, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_230();
        break;
      }
    case Pattern_value:
      {
        n = Parse_state_239();
        break;
      }
    default:
    /* default item:ParPattern  ->  equalssym openparsym . Pattern closeparsym      followers: CONSsym commasym closeparsym openchainsym verticalbarsym arrowsym  */
/* nt = 0x96ac538 */
      n = 0; _doggy_symbol = Pattern_value;
      { ParseValue me;
        doggy_Pattern  pat = POP_PARSEVALUE (Pointer, doggy_Pattern);
        doggy_Type  btype = POP_PARSEVALUE (Pointer, doggy_Type);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_TypedPattern(src_info, btype, pat);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_239 (void)	/* state 239 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_240();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 250
   Identsym 
 */
static int Parse_state_250 (SymbolSet followers)	/* state 250 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_251(followers);
      }
  return n-1;
}

/* directors of state 251
   equalssym 
 */
static int Parse_state_251 (SymbolSet followers)	/* state 251 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x8000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(251);
    switch (_doggy_symbol) {
    case commasym_value:
    case closeparsym_value:
      n = 0; _doggy_symbol = OPT_equalssym_UnTypedPattern_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,doggy_Pattern);
      }
      break;
    case equalssym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_110(followers);
        break;
      }
    case OPT_equalssym_UnTypedPattern_value:
      {
        n = Parse_state_244();
        break;
      }
    case ParPattern_value:
      {
        n = Parse_state_245();
        break;
      }
    case PatArg1_value:
      {
        n = Parse_state_246();
        break;
      }
    case ParArg_value:
      {
        n = Parse_state_247();
        break;
      }
    case SetArg_value:
      {
        n = Parse_state_248();
        break;
      }
    case ArgPat2_value:
      {
        n = Parse_state_252();
        break;
      }
    default:
    /* default item:Argument  ->  Type Identsym . ArgPat2   followers: commasym closeparsym  */
/* nt = 0x96a9be0 */
      n = 0; _doggy_symbol = ArgPat2_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 253
   commasym 
 */
static int Parse_state_253 (SymbolSet followers)	/* state 253 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x2000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(253);
    switch (_doggy_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_254(followers);
        break;
      }
    default:
    /* default item:ALT_Argument_SEP_commasym  ->  Argument .       followers: closeparsym  */
      n = 1; _doggy_symbol = ALT_Argument_SEP_commasym_value;
      { /* alt action */
        doggy_Argument  _id_0 = POP_PARSEVALUE (Pointer, doggy_Argument);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Argument(_id_0,NULL),List_doggy_Argument);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 254
   Identsym openchainsym openbrksym OPRsym 
 */
static int Parse_state_254 (SymbolSet followers)	/* state 254 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010404, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(254);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100004, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_109(_followers);
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x100004, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x4, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_36(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x100004, 0x2004000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        static Int my_followers[] = { 0x4, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x4, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(_followers);
        break;
      }
    case Type_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_250(_followers);
        break;
      }
    case Argument_value:
      {
        n = Parse_state_253(followers);
        break;
      }
    case ALT_Argument_SEP_commasym_value:
      {
        n = Parse_state_255();
        break;
      }
    default:
    /* default item:ALT_Argument_SEP_commasym  ->  Argument commasym . ALT_Argument_SEP_commasym    followers: closeparsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_Argument_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Argument);
      _doggy_symbol = ALT_Argument_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 258
   closeparsym 
 */
static int Parse_state_258 (SymbolSet followers)	/* state 258 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_259(followers);
      }
  return n-1;
}

/* directors of state 259
   openchainsym verticalbarsym arrowsym 
 */
static int Parse_state_259 (SymbolSet followers)	/* state 259 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x310000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(259);
    switch (_doggy_symbol) {
    case arrowsym_value:
      n = 0; _doggy_symbol = OPT_verticalbarsym_Condition_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,doggy_Expr);
      }
      break;
    case verticalbarsym_value:
      {
        static Int my_followers[] = { 0x300000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_260(_followers);
        break;
      }
    case OPT_verticalbarsym_Condition_value:
      {
        static Int my_followers[] = { 0x300000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_263(_followers);
        break;
      }
    case Guard_value:
      {
        n = Parse_state_280(followers);
        break;
      }
    case MORE_Guard_value:
      {
        n = Parse_state_282();
        break;
      }
    case openchainsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_283(followers);
        break;
      }
    case Rhs_value:
      {
        n = Parse_state_290();
        break;
      }
    default:
    /* default item:FuncRule  ->  openparsym OPT_Arguments closeparsym . Rhs        followers: commasym semicolonsym  */
/* nt = 0x96b38f8 */
      n = 0; _doggy_symbol = Rhs_value;
      { ParseValue me;
        doggy_Wherepart  where = POP_PARSEVALUE (Pointer, doggy_Wherepart);
        doggy_Rhs  rhs = POP_PARSEVALUE (Pointer, doggy_Rhs);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Rhs");
        me->sub.PointerValue = Create_doggy_BlockRhs(src_info, rhs, where);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 260
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_260 (SymbolSet followers)	/* state 260 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(260);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4010000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x4010000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4010000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4010000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x8c050904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x8c050904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x8c050904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x8c050904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x8c050904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x8c050904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4010000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x4010000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x4010000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x4010000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x4010000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        static Int my_followers[] = { 0x10000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_183();
        break;
      }
    case Condition_value:
      {
        n = Parse_state_261(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:OPT_verticalbarsym_Condition  ->  verticalbarsym . Condition    followers: arrowsym  */
/* nt = 0x96c6750 */
      InputError (SCAN_POSITION, TRUE, "Condition expected");
      PUSH_PARSEVALUE(Pointer,0,doggy_Expr);
      _doggy_symbol = Condition_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 261
   openchainsym 
 */
static int Parse_state_261 (SymbolSet followers)	/* state 261 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x10000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(261);
    switch (_doggy_symbol) {
    case openchainsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_262(followers);
        break;
      }
    default:
    /* default item:OPT_verticalbarsym_Condition  ->  verticalbarsym Condition .    followers: arrowsym  */
      n = 2; _doggy_symbol = OPT_verticalbarsym_Condition_value;
      { /* opt action */
        doggy_Expr  _id_0 = POP_PARSEVALUE (Pointer, doggy_Expr);
        PUSH_PARSEVALUE(Pointer,_id_0,doggy_Expr);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 262
   openchainsym verticalbarsym arrowsym 
 */
static int Parse_state_262 (SymbolSet followers)	/* state 262 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x310000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(262);
    switch (_doggy_symbol) {
    case arrowsym_value:
      n = 0; _doggy_symbol = OPT_verticalbarsym_Condition_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,doggy_Expr);
      }
      break;
    case verticalbarsym_value:
      {
        static Int my_followers[] = { 0x320000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_260(_followers);
        break;
      }
    case OPT_verticalbarsym_Condition_value:
      {
        static Int my_followers[] = { 0x320000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_263(_followers);
        break;
      }
    case Guard_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_280(_followers);
        break;
      }
    case MORE_Guard_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_282();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_283(_followers);
        break;
      }
    case Rhs_value:
      {
        n = Parse_state_287(followers);
        break;
      }
    default:
    /* default item:Guard  ->  verticalbarsym Condition openchainsym . Rhs closechainsym OPT_Wherepart      followers: commasym semicolonsym verticalbarsym arrowsym closechainsym  */
/* nt = 0x96b38f8 */
      n = 0; _doggy_symbol = Rhs_value;
      { ParseValue me;
        doggy_Wherepart  where = POP_PARSEVALUE (Pointer, doggy_Wherepart);
        doggy_Rhs  rhs = POP_PARSEVALUE (Pointer, doggy_Rhs);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Rhs");
        me->sub.PointerValue = Create_doggy_BlockRhs(src_info, rhs, where);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 263
   arrowsym 
 */
static int Parse_state_263 (SymbolSet followers)	/* state 263 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_264(followers);
      }
  return n-1;
}

/* directors of state 264
   openchainsym minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_264 (SymbolSet followers)	/* state 264 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88050904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(264);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4400000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x4400000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4400000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4400000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x8c440904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x8c440904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x8c440904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x8c440904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x8c440904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x8c440904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4400000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x4400000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x4400000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x4400000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x4400000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x400000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x400000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x400000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x400000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        static Int my_followers[] = { 0x400000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_265();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x400000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_266(_followers);
        break;
      }
    case ExprSeq_value:
      {
        n = Parse_state_269(followers);
        break;
      }
    default:
    /* default item:Guard  ->  OPT_verticalbarsym_Condition arrowsym . ExprSeq OPT_Wherepart        followers: closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = 0x96b9330 */
      n = 0; _doggy_symbol = ExprSeq_value;
      { ParseValue me;
        List_doggy_Expr  e = POP_PARSEVALUE (Pointer, List_doggy_Expr);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_ExprSeq");
        me->sub.PointerValue = Create_doggy_MoreExprs(src_info, e);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 266
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_266 (SymbolSet followers)	/* state 266 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(266);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4020000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x4020000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4020000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4020000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x8c060904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x8c060904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x8c060904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x8c060904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x8c060904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x8c060904, 0x21fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4020000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x4020000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x4020000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x4020000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x4020000, 0x207fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        static Int my_followers[] = { 0x20000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_150(_followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        static Int my_followers[] = { 0x20000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        static Int my_followers[] = { 0x20000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        static Int my_followers[] = { 0x20000, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_196(_followers);
        break;
      }
    case ALT_Expr_SEP_commasym_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_199();
        break;
      }
    case Exprs_value:
      {
        n = Parse_state_267();
        break;
      }
    default:
    /* default item:ExprSeq  ->  openchainsym . Exprs closechainsym followers: WHEREsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = 0x96d2840 */
      InputError (SCAN_POSITION, TRUE, "Exprs expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Expr);
      _doggy_symbol = Exprs_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_267 (void)	/* state 267 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_268();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 269
   WHEREsym 
 */
static int Parse_state_269 (SymbolSet followers)	/* state 269 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x400000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(269);
    switch (_doggy_symbol) {
    case WHEREsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_270(followers);
        break;
      }
    case Wherepart_value:
      {
        n = Parse_state_278();
        break;
      }
    case OPT_Wherepart_value:
      {
        n = Parse_state_279();
        break;
      }
    default:
    /* default item:Guard  ->  OPT_verticalbarsym_Condition arrowsym ExprSeq . OPT_Wherepart        followers: closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,doggy_Wherepart);
      _doggy_symbol = OPT_Wherepart_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 270
   openchainsym openbrksym OPRsym Identsym 
 */
static int Parse_state_270 (SymbolSet followers)	/* state 270 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010404, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(270);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x1110404, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x1110404, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x1010404, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_36(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x1110404, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        static Int my_followers[] = { 0x1010404, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1010404, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(_followers);
        break;
      }
    case Type_value:
      {
        static Int my_followers[] = { 0x1010404, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_271(_followers);
        break;
      }
    case Definition_value:
      {
        n = Parse_state_275(followers);
        break;
      }
    case OPTMORE_Definition_value:
      {
        n = Parse_state_277();
        break;
      }
    default:
    /* default item:Wherepart  ->  WHEREsym . OPTMORE_Definition    followers: closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Definition);
      _doggy_symbol = OPTMORE_Definition_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 271
   Identsym 
 */
static int Parse_state_271 (SymbolSet followers)	/* state 271 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_272(followers);
      }
  return n-1;
}

/* directors of state 272
   equalssym 
 */
static int Parse_state_272 (SymbolSet followers)	/* state 272 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_273(followers);
      }
  return n-1;
}

/* directors of state 273
   minussym plussym starsym ampersandsym tildasym exclaimsym openparsym Identsym NULLsym Stringsym Boolsym Intsym IFsym 
 */
static int Parse_state_273 (SymbolSet followers)	/* state 273 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x88040904, 0x1bc001 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(273);
    switch (_doggy_symbol) {
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133();
        break;
      }
    case Boolsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Bool,doggy_lval.Boolsym_type,Bool);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_134();
        break;
      }
    case Stringsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(String,doggy_lval.Stringsym_type,String);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_136();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case exclaimsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case tildasym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_138();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case ampersandsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_139();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case starsym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_140();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case plussym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_141();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case minussym_value:
      {
        static Int my_followers[] = { 0x8c040904, 0x1fffff };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_142();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_143(_followers);
        break;
      }
    case IFsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_145(_followers);
        break;
      }
    case Constant_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_146();
        break;
      }
    case openparsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147(_followers);
        break;
      }
    case MonOp_value:
      {
        static Int my_followers[] = { 0x4000000, 0x7fffe };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_148(_followers);
        break;
      }
    case SimpleExpr_value:
      {
        n = Parse_state_150(followers);
        break;
      }
    case ALT_SimpleExpr_SEP_Operator_value:
      {
        n = Parse_state_175();
        break;
      }
    case IdOpExpr_value:
      {
        n = Parse_state_176();
        break;
      }
    case ConsExpr_value:
      {
        n = Parse_state_177();
        break;
      }
    case Expr_value:
      {
        n = Parse_state_274();
        break;
      }
    default:
    /* default item:Definition  ->  Type Identsym equalssym . Expr  followers: openchainsym openbrksym OPRsym Identsym closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = 0x96bd958 */
      n = 0; _doggy_symbol = Expr_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 275
   openchainsym openbrksym OPRsym Identsym 
 */
static int Parse_state_275 (SymbolSet followers)	/* state 275 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010404, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(275);
    switch (_doggy_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x1110404, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
        break;
      }
    case OPRsym_value:
      {
        static Int my_followers[] = { 0x1110404, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_34(_followers);
        break;
      }
    case BasicType_value:
      {
        static Int my_followers[] = { 0x1010404, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_36(_followers);
        break;
      }
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x1110404, 0x4000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_39(_followers);
        break;
      }
    case ALT_BasicType_SEP_verticalbarsym_value:
      {
        static Int my_followers[] = { 0x1010404, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_55();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x1010404, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_56(_followers);
        break;
      }
    case Type_value:
      {
        static Int my_followers[] = { 0x1010404, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_271(_followers);
        break;
      }
    case Definition_value:
      {
        n = Parse_state_275(followers);
        break;
      }
    case OPTMORE_Definition_value:
      {
        n = Parse_state_276();
        break;
      }
    default:
    /* default item:OPTMORE_Definition  ->  Definition . OPTMORE_Definition followers: closechainsym verticalbarsym arrowsym commasym semicolonsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Definition);
      _doggy_symbol = OPTMORE_Definition_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 280
   verticalbarsym arrowsym 
 */
static int Parse_state_280 (SymbolSet followers)	/* state 280 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x300000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(280);
    switch (_doggy_symbol) {
    case arrowsym_value:
      n = 0; _doggy_symbol = OPT_verticalbarsym_Condition_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,doggy_Expr);
      }
      break;
    case verticalbarsym_value:
      {
        static Int my_followers[] = { 0x300000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_260(_followers);
        break;
      }
    case OPT_verticalbarsym_Condition_value:
      {
        static Int my_followers[] = { 0x300000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_263(_followers);
        break;
      }
    case Guard_value:
      {
        n = Parse_state_280(followers);
        break;
      }
    case MORE_Guard_value:
      {
        n = Parse_state_281();
        break;
      }
    default:
    /* default item:MORE_Guard  ->  Guard . followers: closechainsym commasym semicolonsym  */
      n = 1; _doggy_symbol = MORE_Guard_value;
      { /* more action */
        doggy_Guard  guards = POP_PARSEVALUE (Pointer, doggy_Guard);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_Guard(guards,NULL),List_doggy_Guard);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 283
   openchainsym verticalbarsym arrowsym 
 */
static int Parse_state_283 (SymbolSet followers)	/* state 283 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x310000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(283);
    switch (_doggy_symbol) {
    case arrowsym_value:
      n = 0; _doggy_symbol = OPT_verticalbarsym_Condition_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,doggy_Expr);
      }
      break;
    case verticalbarsym_value:
      {
        static Int my_followers[] = { 0x320000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_260(_followers);
        break;
      }
    case OPT_verticalbarsym_Condition_value:
      {
        static Int my_followers[] = { 0x320000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_263(_followers);
        break;
      }
    case Guard_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_280(_followers);
        break;
      }
    case MORE_Guard_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_282();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x20000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_283(_followers);
        break;
      }
    case Rhs_value:
      {
        n = Parse_state_284(followers);
        break;
      }
    default:
    /* default item:Rhs  ->  openchainsym . Rhs closechainsym OPT_Wherepart followers: closechainsym commasym semicolonsym  */
/* nt = 0x96b38f8 */
      n = 0; _doggy_symbol = Rhs_value;
      { ParseValue me;
        doggy_Wherepart  where = POP_PARSEVALUE (Pointer, doggy_Wherepart);
        doggy_Rhs  rhs = POP_PARSEVALUE (Pointer, doggy_Rhs);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Rhs");
        me->sub.PointerValue = Create_doggy_BlockRhs(src_info, rhs, where);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 284
   closechainsym 
 */
static int Parse_state_284 (SymbolSet followers)	/* state 284 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_285(followers);
      }
  return n-1;
}

/* directors of state 285
   WHEREsym 
 */
static int Parse_state_285 (SymbolSet followers)	/* state 285 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x400000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(285);
    switch (_doggy_symbol) {
    case WHEREsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_270(followers);
        break;
      }
    case Wherepart_value:
      {
        n = Parse_state_278();
        break;
      }
    case OPT_Wherepart_value:
      {
        n = Parse_state_286();
        break;
      }
    default:
    /* default item:Rhs  ->  openchainsym Rhs closechainsym . OPT_Wherepart followers: closechainsym commasym semicolonsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,doggy_Wherepart);
      _doggy_symbol = OPT_Wherepart_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 287
   closechainsym 
 */
static int Parse_state_287 (SymbolSet followers)	/* state 287 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_288(followers);
      }
  return n-1;
}

/* directors of state 288
   WHEREsym 
 */
static int Parse_state_288 (SymbolSet followers)	/* state 288 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x400000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(288);
    switch (_doggy_symbol) {
    case WHEREsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_270(followers);
        break;
      }
    case Wherepart_value:
      {
        n = Parse_state_278();
        break;
      }
    case OPT_Wherepart_value:
      {
        n = Parse_state_289();
        break;
      }
    default:
    /* default item:Guard  ->  verticalbarsym Condition openchainsym Rhs closechainsym . OPT_Wherepart      followers: commasym semicolonsym verticalbarsym arrowsym closechainsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,doggy_Wherepart);
      _doggy_symbol = OPT_Wherepart_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 291
   commasym 
 */
static int Parse_state_291 (SymbolSet followers)	/* state 291 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x0, 0x2000000 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(291);
    switch (_doggy_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_292(followers);
        break;
      }
    default:
    /* default item:ALT_FuncRule_SEP_commasym  ->  FuncRule .       followers: semicolonsym  */
      n = 1; _doggy_symbol = ALT_FuncRule_SEP_commasym_value;
      { /* alt action */
        doggy_FuncRule  _id_0 = POP_PARSEVALUE (Pointer, doggy_FuncRule);
        PUSH_PARSEVALUE(Pointer,Create_List_doggy_FuncRule(_id_0,NULL),List_doggy_FuncRule);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 292
   openparsym 
 */
static int Parse_state_292 (SymbolSet followers)	/* state 292 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x100, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(292);
    switch (_doggy_symbol) {
    case openparsym_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_108(_followers);
        break;
      }
    case FuncRule_value:
      {
        n = Parse_state_291(followers);
        break;
      }
    case ALT_FuncRule_SEP_commasym_value:
      {
        n = Parse_state_293();
        break;
      }
    default:
    /* default item:ALT_FuncRule_SEP_commasym  ->  FuncRule commasym . ALT_FuncRule_SEP_commasym    followers: semicolonsym  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_FuncRule_SEP_commasym expected");
      PUSH_PARSEVALUE(Pointer,0,List_doggy_FuncRule);
      _doggy_symbol = ALT_FuncRule_SEP_commasym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_295 (void)	/* state 295 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_296();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 297
   externsym openchainsym openbrksym OPRsym Identsym 
 */
static int Parse_state_297 (SymbolSet followers)	/* state 297 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x1010414, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(297);
    switch (_doggy_symbol) {
    case openchainsym_value:
    case openbrksym_value:
    case OPRsym_value:
    case Identsym_value:
      n = 0; _doggy_symbol = OPT_externsym_value;
      { /* opt action */
        PUSH_PARSEVALUE(Bool,FALSE,Bool);
      }
      break;
    case externsym_value:
      {
        static Int my_followers[] = { 0x1010414, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_104();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OPT_externsym_value:
      {
        static Int my_followers[] = { 0x1010414, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_105(_followers);
        break;
      }
    case Func_value:
      {
        n = Parse_state_297(followers);
        break;
      }
    case OPTMORE_Func_value:
      {
        n = Parse_state_298();
        break;
      }
    default:
    /* default item:OPTMORE_Func  ->  Func . OPTMORE_Func   followers: RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Func);
      _doggy_symbol = OPTMORE_Func_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 300
   colonsym _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym 
 */
static int Parse_state_300 (SymbolSet followers)	/* state 300 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d2804, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(300);
    switch (_doggy_symbol) {
    case colonsym_value:
      {
        static Int my_followers[] = { 0x18d0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_301(_followers);
        break;
      }
    case OPT_colonsym_Identsym_value:
      {
        n = Parse_state_303(followers);
        break;
      }
    default:
    /* default item:Rules  ->  RULESsym . OPT_colonsym_Identsym OPTMORE_Rule        followers: RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      _doggy_symbol = OPT_colonsym_Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 301
   Identsym 
 */
static int Parse_state_301 (SymbolSet followers)	/* state 301 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_302();
      }
  return n-1;
}

/* directors of state 303
   _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym 
 */
static int Parse_state_303 (SymbolSet followers)	/* state 303 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d0804, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(303);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x5bd0904, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_113(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x5bd0904, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_304(_followers);
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x5bd0904, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x5bd0904, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x5bd0904, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(_followers);
        break;
      }
    case BasicPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_214(_followers);
        break;
      }
    case IdentPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_216();
        break;
      }
    case SingleDefPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_217();
        break;
      }
    case DefPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_218();
        break;
      }
    case IdParPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_219();
        break;
      }
    case BinPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_220();
        break;
      }
    case SimplePattern_value:
      {
        static Int my_followers[] = { 0x1bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_224(_followers);
        break;
      }
    case ConsPattern_value:
      {
        static Int my_followers[] = { 0x1bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_226();
        break;
      }
    case UnTypedPattern_value:
      {
        static Int my_followers[] = { 0x1bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_307();
        break;
      }
    case Lhs_value:
      {
        static Int my_followers[] = { 0x18d0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_308(_followers);
        break;
      }
    case Rule_value:
      {
        n = Parse_state_311(followers);
        break;
      }
    case OPTMORE_Rule_value:
      {
        n = Parse_state_313();
        break;
      }
    default:
    /* default item:Rules  ->  RULESsym OPT_colonsym_Identsym . OPTMORE_Rule        followers: RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Rule);
      _doggy_symbol = OPTMORE_Rule_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 304
   colonsym equalssym 
 */
static int Parse_state_304 (SymbolSet followers)	/* state 304 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0xa000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(304);
    switch (_doggy_symbol) {
    case openparsym_value:
      n = 1; _doggy_symbol = Applied_formal_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Applied_formal");
        me->sub.PointerValue = Create_doggy_Applied_formal(src_info, id);
      }
      break;
    case equalssym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_112(followers);
        break;
      }
    case ParPattern_value:
      {
        n = Parse_state_128();
        break;
      }
    case colonsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_305(followers);
        break;
      }
    default:
    /* default item:IdentPattern  ->  Identsym .     followers: openchainsym verticalbarsym arrowsym CONSsym  */
      n = 1; _doggy_symbol = IdentPattern_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Pattern");
        me->sub.PointerValue = Create_doggy_IdentPattern(src_info, id);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 305
   _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym 
 */
static int Parse_state_305 (SymbolSet followers)	/* state 305 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d0804, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(305);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_113(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_111(_followers);
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x4000100, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(_followers);
        break;
      }
    case BasicPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_214(_followers);
        break;
      }
    case IdentPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_216();
        break;
      }
    case SingleDefPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_217();
        break;
      }
    case DefPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_218();
        break;
      }
    case IdParPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_219();
        break;
      }
    case BinPattern_value:
      {
        static Int my_followers[] = { 0x4000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_220();
        break;
      }
    case SimplePattern_value:
      {
        n = Parse_state_224(followers);
        break;
      }
    case ConsPattern_value:
      {
        n = Parse_state_226();
        break;
      }
    case UnTypedPattern_value:
      {
        n = Parse_state_306();
        break;
      }
    default:
    /* default item:Lhs  ->  Identsym colonsym . UnTypedPattern     followers: openchainsym verticalbarsym arrowsym  */
/* nt = 0x96acbf0 */
      n = 0; _doggy_symbol = UnTypedPattern_value;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 308
   openchainsym verticalbarsym arrowsym 
 */
static int Parse_state_308 (SymbolSet followers)	/* state 308 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x310000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(308);
    switch (_doggy_symbol) {
    case arrowsym_value:
      n = 0; _doggy_symbol = OPT_verticalbarsym_Condition_value;
      { /* opt action */
        PUSH_PARSEVALUE(Pointer,NULL,doggy_Expr);
      }
      break;
    case verticalbarsym_value:
      {
        static Int my_followers[] = { 0x300020, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_260(_followers);
        break;
      }
    case OPT_verticalbarsym_Condition_value:
      {
        static Int my_followers[] = { 0x300020, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_263(_followers);
        break;
      }
    case Guard_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_280(_followers);
        break;
      }
    case MORE_Guard_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_282();
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x20, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_283(_followers);
        break;
      }
    case Rhs_value:
      {
        n = Parse_state_309();
        break;
      }
    default:
    /* default item:Rule  ->  Lhs . Rhs semicolonsym        followers: _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = 0x96b38f8 */
      n = 0; _doggy_symbol = Rhs_value;
      { ParseValue me;
        doggy_Wherepart  where = POP_PARSEVALUE (Pointer, doggy_Wherepart);
        doggy_Rhs  rhs = POP_PARSEVALUE (Pointer, doggy_Rhs);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("doggy_Rhs");
        me->sub.PointerValue = Create_doggy_BlockRhs(src_info, rhs, where);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_309 (void)	/* state 309 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_310();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 311
   _sym NULLsym Intsym Identsym openbrksym ANYsym openchainsym 
 */
static int Parse_state_311 (SymbolSet followers)	/* state 311 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x18d0804, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(311);
    switch (_doggy_symbol) {
    case openbrksym_value:
      {
        static Int my_followers[] = { 0x5bd0904, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_113(_followers);
        break;
      }
    case Identsym_value:
      {
        static Int my_followers[] = { 0x5bd0904, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,doggy_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_304(_followers);
        break;
      }
    case ANYsym_value:
      {
        static Int my_followers[] = { 0x5bd0904, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_120();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case OpSet_value:
      {
        static Int my_followers[] = { 0x5bd0904, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_121();
        break;
      }
    case Applied_formal_value:
      {
        static Int my_followers[] = { 0x5bd0904, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_122();
        break;
      }
    case Applied_operation_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_123(_followers);
        break;
      }
    case Intsym_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift)      PUSH_PARSEVALUE(Int,doggy_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129();
        break;
      }
    case NULLsym_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_130();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case _sym_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x40000 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_131(_followers);
        break;
      }
    case openchainsym_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_205(_followers);
        break;
      }
    case BasicPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_214(_followers);
        break;
      }
    case IdentPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_216();
        break;
      }
    case SingleDefPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_217();
        break;
      }
    case DefPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_218();
        break;
      }
    case IdParPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_219();
        break;
      }
    case BinPattern_value:
      {
        static Int my_followers[] = { 0x5bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_220();
        break;
      }
    case SimplePattern_value:
      {
        static Int my_followers[] = { 0x1bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_224(_followers);
        break;
      }
    case ConsPattern_value:
      {
        static Int my_followers[] = { 0x1bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_226();
        break;
      }
    case UnTypedPattern_value:
      {
        static Int my_followers[] = { 0x1bd0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_307();
        break;
      }
    case Lhs_value:
      {
        static Int my_followers[] = { 0x18d0804, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_308(_followers);
        break;
      }
    case Rule_value:
      {
        n = Parse_state_311(followers);
        break;
      }
    case OPTMORE_Rule_value:
      {
        n = Parse_state_312();
        break;
      }
    default:
    /* default item:OPTMORE_Rule  ->  Rule . OPTMORE_Rule   followers: RULESsym FUNCTIONSsym doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Rule);
      _doggy_symbol = OPTMORE_Rule_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 316
   RULESsym FUNCTIONSsym 
 */
static int Parse_state_316 (SymbolSet followers)	/* state 316 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[2] = { 0x5000, 0x0 };
  Int _followers[2];
  unite_symbol_sets (_followers, followers, directors, 2);
  DELETE_UNTIL (_followers, doggy);
  _doggy_symbol = _doggy_token;
  do {
    REPORT(316);
    switch (_doggy_symbol) {
    case FUNCTIONSsym_value:
      {
        static Int my_followers[] = { 0x5000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_103(_followers);
        break;
      }
    case RULESsym_value:
      {
        static Int my_followers[] = { 0x5000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_300(_followers);
        break;
      }
    case Funcs_value:
      {
        static Int my_followers[] = { 0x5000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_314();
        break;
      }
    case Rules_value:
      {
        static Int my_followers[] = { 0x5000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 2);
        n = Parse_state_315();
        break;
      }
    case Section_value:
      {
        n = Parse_state_316(followers);
        break;
      }
    case OPTMORE_Section_value:
      {
        n = Parse_state_317();
        break;
      }
    default:
    /* default item:OPTMORE_Section  ->  Section . OPTMORE_Section  followers: doggy_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_doggy_Section);
      _doggy_symbol = OPTMORE_Section_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

